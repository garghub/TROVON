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
V_115 = F_75 ( 0 ) ;
V_119 = F_11 ( F_76 ( 0 ) ) & V_120 ;
if ( V_119 == V_121 &&
F_11 ( V_122 ) & V_123 )
V_116 = V_124 ;
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
V_115 = F_75 ( V_95 ) ;
V_116 = V_95 ;
} else {
V_115 = F_75 ( 0 ) ;
if ( F_11 ( V_125 ) & V_123 )
V_116 = V_124 ;
}
V_15 = F_11 ( V_115 ) ;
if ( ! ( V_15 & V_126 ) ||
( ( V_15 & V_127 ) == V_128 ) )
V_118 = false ;
F_64 ( V_116 == V_95 && V_118 ,
L_22 ,
F_77 ( V_95 ) ) ;
}
static void F_78 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
bool V_105 ;
if ( F_79 ( V_57 ) || F_80 ( V_57 ) )
V_105 = F_11 ( F_81 ( V_117 ) ) & V_129 ;
else
V_105 = F_11 ( F_81 ( V_95 ) ) & V_130 ;
F_64 ( V_105 != V_43 ,
L_23 ,
F_77 ( V_95 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
void F_82 ( struct V_5 * V_6 ,
enum V_95 V_95 , bool V_43 )
{
bool V_105 ;
enum V_94 V_97 = F_51 ( V_6 ,
V_95 ) ;
enum V_131 V_132 ;
if ( ( V_95 == V_117 && V_6 -> V_133 & V_134 ) ||
( V_95 == V_124 && V_6 -> V_133 & V_135 ) )
V_43 = true ;
V_132 = F_83 ( V_97 ) ;
if ( F_84 ( V_6 , V_132 ) ) {
T_1 V_15 = F_11 ( F_59 ( V_97 ) ) ;
V_105 = ! ! ( V_15 & V_136 ) ;
F_85 ( V_6 , V_132 ) ;
} else {
V_105 = false ;
}
F_64 ( V_105 != V_43 ,
L_24 ,
F_77 ( V_95 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_86 ( struct V_5 * V_6 ,
enum V_137 V_137 , bool V_43 )
{
T_1 V_15 ;
bool V_105 ;
V_15 = F_11 ( F_87 ( V_137 ) ) ;
V_105 = ! ! ( V_15 & V_138 ) ;
F_64 ( V_105 != V_43 ,
L_25 ,
F_88 ( V_137 ) , F_65 ( V_43 ) , F_65 ( V_105 ) ) ;
}
static void F_89 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
int V_139 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
T_1 V_15 = F_11 ( F_87 ( V_95 ) ) ;
F_64 ( V_15 & V_138 ,
L_26 ,
F_88 ( V_95 ) ) ;
return;
}
F_90 (dev_priv, i) {
T_1 V_15 = F_11 ( F_87 ( V_139 ) ) ;
enum V_95 V_140 = ( V_15 & V_141 ) >>
V_142 ;
F_64 ( ( V_15 & V_138 ) && V_95 == V_140 ,
L_27 ,
F_88 ( V_139 ) , F_77 ( V_95 ) ) ;
}
}
static void F_91 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
int V_143 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_92 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_93 ( V_95 , V_143 ) ) ;
F_64 ( V_15 & V_144 ,
L_28 ,
V_143 , F_77 ( V_95 ) ) ;
}
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
F_92 (dev_priv, pipe, sprite) {
T_1 V_15 = F_11 ( F_94 ( V_95 , V_143 ) ) ;
F_64 ( V_15 & V_145 ,
L_29 ,
F_95 ( V_95 , V_143 ) , F_77 ( V_95 ) ) ;
}
} else if ( F_58 ( V_57 ) -> V_103 >= 7 ) {
T_1 V_15 = F_11 ( F_96 ( V_95 ) ) ;
F_64 ( V_15 & V_146 ,
L_29 ,
F_88 ( V_95 ) , F_77 ( V_95 ) ) ;
} else if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
T_1 V_15 = F_11 ( F_97 ( V_95 ) ) ;
F_64 ( V_15 & V_147 ,
L_29 ,
F_88 ( V_95 ) , F_77 ( V_95 ) ) ;
}
}
static void F_98 ( struct V_87 * V_65 )
{
if ( F_99 ( F_100 ( V_65 ) == 0 ) )
F_101 ( V_65 ) ;
}
void F_102 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
T_1 V_15 ;
bool V_148 ;
V_15 = F_11 ( F_103 ( V_95 ) ) ;
V_148 = ! ! ( V_15 & V_149 ) ;
F_64 ( V_148 ,
L_30 ,
F_77 ( V_95 ) ) ;
}
static bool F_104 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_119 , T_1 V_15 )
{
if ( ( V_15 & V_150 ) == 0 )
return false ;
if ( F_105 ( V_6 ) ) {
T_1 V_151 = F_11 ( F_106 ( V_95 ) ) ;
if ( ( V_151 & V_152 ) != V_119 )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_153 ) != F_107 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_154 ) != ( V_95 << 30 ) )
return false ;
}
return true ;
}
static bool F_108 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_155 ) == 0 )
return false ;
if ( F_105 ( V_6 ) ) {
if ( ( V_15 & V_156 ) != F_109 ( V_95 ) )
return false ;
} else if ( F_17 ( V_6 ) ) {
if ( ( V_15 & V_157 ) != F_110 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_158 ) != F_111 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_112 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_159 ) == 0 )
return false ;
if ( F_105 ( V_6 ) ) {
if ( ( V_15 & V_160 ) != F_113 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_161 ) != F_114 ( V_95 ) )
return false ;
}
return true ;
}
static bool F_115 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_1 V_15 )
{
if ( ( V_15 & V_162 ) == 0 )
return false ;
if ( F_105 ( V_6 ) ) {
if ( ( V_15 & V_160 ) != F_113 ( V_95 ) )
return false ;
} else {
if ( ( V_15 & V_163 ) != F_116 ( V_95 ) )
return false ;
}
return true ;
}
static void F_117 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_3 V_13 ,
T_1 V_119 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_64 ( F_104 ( V_6 , V_95 , V_119 , V_15 ) ,
L_31 ,
F_118 ( V_13 ) , F_77 ( V_95 ) ) ;
F_64 ( F_119 ( V_6 ) && ( V_15 & V_150 ) == 0
&& ( V_15 & V_164 ) ,
L_32 ) ;
}
static void F_120 ( struct V_5 * V_6 ,
enum V_95 V_95 , T_3 V_13 )
{
T_1 V_15 = F_11 ( V_13 ) ;
F_64 ( F_108 ( V_6 , V_95 , V_15 ) ,
L_33 ,
F_118 ( V_13 ) , F_77 ( V_95 ) ) ;
F_64 ( F_119 ( V_6 ) && ( V_15 & V_155 ) == 0
&& ( V_15 & V_165 ) ,
L_34 ) ;
}
static void F_121 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
T_1 V_15 ;
F_117 ( V_6 , V_95 , V_166 , V_167 ) ;
F_117 ( V_6 , V_95 , V_168 , V_169 ) ;
F_117 ( V_6 , V_95 , V_170 , V_171 ) ;
V_15 = F_11 ( V_172 ) ;
F_64 ( F_115 ( V_6 , V_95 , V_15 ) ,
L_35 ,
F_77 ( V_95 ) ) ;
V_15 = F_11 ( V_122 ) ;
F_64 ( F_112 ( V_6 , V_95 , V_15 ) ,
L_36 ,
F_77 ( V_95 ) ) ;
F_120 ( V_6 , V_95 , V_173 ) ;
F_120 ( V_6 , V_95 , V_174 ) ;
F_120 ( V_6 , V_95 , V_175 ) ;
}
static void F_122 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_123 ( F_63 ( V_95 ) , V_38 -> V_176 . V_45 ) ;
F_124 ( F_63 ( V_95 ) ) ;
F_125 ( 150 ) ;
if ( F_60 ( V_6 ,
F_63 ( V_95 ) ,
V_177 ,
V_177 ,
1 ) )
F_126 ( L_37 , V_95 ) ;
}
static void F_127 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_128 ( V_6 , V_95 ) ;
F_74 ( V_6 , V_95 ) ;
if ( V_38 -> V_176 . V_45 & V_106 )
F_122 ( V_65 , V_38 ) ;
F_123 ( F_129 ( V_95 ) , V_38 -> V_176 . V_178 ) ;
F_124 ( F_129 ( V_95 ) ) ;
}
static void F_130 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_179 V_180 = F_131 ( V_95 ) ;
T_1 V_181 ;
F_3 ( & V_6 -> V_9 ) ;
V_181 = F_132 ( V_6 , V_95 , F_133 ( V_180 ) ) ;
V_181 |= V_182 ;
F_134 ( V_6 , V_95 , F_133 ( V_180 ) , V_181 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_125 ( 1 ) ;
F_123 ( F_63 ( V_95 ) , V_38 -> V_176 . V_45 ) ;
if ( F_60 ( V_6 ,
F_63 ( V_95 ) , V_177 , V_177 ,
1 ) )
F_126 ( L_38 , V_95 ) ;
}
static void F_135 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
F_128 ( V_6 , V_95 ) ;
F_74 ( V_6 , V_95 ) ;
if ( V_38 -> V_176 . V_45 & V_106 )
F_130 ( V_65 , V_38 ) ;
if ( V_95 != V_117 ) {
F_123 ( V_183 , V_95 == V_124 ? V_184 : V_185 ) ;
F_123 ( F_129 ( V_124 ) , V_38 -> V_176 . V_178 ) ;
F_123 ( V_183 , 0 ) ;
V_6 -> V_186 [ V_95 ] = V_38 -> V_176 . V_178 ;
F_28 ( ( F_11 ( F_63 ( V_124 ) ) & V_187 ) == 0 ) ;
} else {
F_123 ( F_129 ( V_95 ) , V_38 -> V_176 . V_178 ) ;
F_124 ( F_129 ( V_95 ) ) ;
}
}
static int F_136 ( struct V_56 * V_57 )
{
struct V_81 * V_65 ;
int V_188 = 0 ;
F_137 (dev, crtc) {
V_188 += V_65 -> V_64 . V_43 -> V_88 &&
F_38 ( V_65 -> V_91 , V_189 ) ;
}
return V_188 ;
}
static void F_138 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_13 = F_63 ( V_65 -> V_95 ) ;
T_1 V_45 = V_65 -> V_91 -> V_176 . V_45 ;
F_128 ( V_6 , V_65 -> V_95 ) ;
if ( F_139 ( V_57 ) && ! F_140 ( V_57 ) )
F_74 ( V_6 , V_65 -> V_95 ) ;
if ( F_140 ( V_57 ) && F_136 ( V_57 ) > 0 ) {
V_45 |= V_190 ;
F_123 ( F_63 ( ! V_65 -> V_95 ) ,
F_11 ( F_63 ( ! V_65 -> V_95 ) ) | V_190 ) ;
}
F_123 ( V_13 , 0 ) ;
F_123 ( V_13 , V_45 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_123 ( F_129 ( V_65 -> V_95 ) ,
V_65 -> V_91 -> V_176 . V_178 ) ;
} else {
F_123 ( V_13 , V_45 ) ;
}
F_123 ( V_13 , V_45 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
F_123 ( V_13 , V_45 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
F_123 ( V_13 , V_45 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
}
static void F_141 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
if ( F_140 ( V_57 ) &&
F_38 ( V_65 -> V_91 , V_189 ) &&
! F_136 ( V_57 ) ) {
F_123 ( F_63 ( V_124 ) ,
F_11 ( F_63 ( V_124 ) ) & ~ V_190 ) ;
F_123 ( F_63 ( V_117 ) ,
F_11 ( F_63 ( V_117 ) ) & ~ V_190 ) ;
}
if ( ( V_95 == V_117 && V_6 -> V_133 & V_134 ) ||
( V_95 == V_124 && V_6 -> V_133 & V_135 ) )
return;
F_128 ( V_6 , V_95 ) ;
F_123 ( F_63 ( V_95 ) , V_187 ) ;
F_124 ( F_63 ( V_95 ) ) ;
}
static void F_142 ( struct V_5 * V_6 , enum V_95 V_95 )
{
T_1 V_15 ;
F_128 ( V_6 , V_95 ) ;
V_15 = V_191 |
V_192 | V_187 ;
if ( V_95 != V_117 )
V_15 |= V_193 ;
F_123 ( F_63 ( V_95 ) , V_15 ) ;
F_124 ( F_63 ( V_95 ) ) ;
}
static void F_143 ( struct V_5 * V_6 , enum V_95 V_95 )
{
enum V_179 V_180 = F_131 ( V_95 ) ;
T_1 V_15 ;
F_128 ( V_6 , V_95 ) ;
V_15 = V_194 |
V_192 | V_187 ;
if ( V_95 != V_117 )
V_15 |= V_193 ;
F_123 ( F_63 ( V_95 ) , V_15 ) ;
F_124 ( F_63 ( V_95 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_132 ( V_6 , V_95 , F_133 ( V_180 ) ) ;
V_15 &= ~ V_182 ;
F_134 ( V_6 , V_95 , F_133 ( V_180 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_144 ( struct V_5 * V_6 ,
struct V_195 * V_196 ,
unsigned int V_197 )
{
T_1 V_198 ;
T_3 V_199 ;
switch ( V_196 -> V_180 ) {
case V_200 :
V_198 = V_201 ;
V_199 = F_63 ( 0 ) ;
break;
case V_202 :
V_198 = V_203 ;
V_199 = F_63 ( 0 ) ;
V_197 <<= 4 ;
break;
case V_204 :
V_198 = V_205 ;
V_199 = V_206 ;
break;
default:
F_145 () ;
}
if ( F_60 ( V_6 ,
V_199 , V_198 , V_197 ,
1000 ) )
F_7 ( 1 , L_39 ,
F_146 ( V_196 -> V_180 ) , F_11 ( V_199 ) & V_198 , V_197 ) ;
}
static void F_147 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_3 V_13 ;
T_2 V_15 , V_207 ;
F_148 ( V_6 , V_81 -> V_91 -> V_208 ) ;
F_149 ( V_6 , V_95 ) ;
F_150 ( V_6 , V_95 ) ;
if ( F_105 ( V_57 ) ) {
V_13 = F_151 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 |= V_209 ;
F_123 ( V_13 , V_15 ) ;
}
V_13 = F_103 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_207 = F_11 ( F_59 ( V_95 ) ) ;
if ( F_119 ( V_6 ) ) {
V_15 &= ~ V_210 ;
if ( F_38 ( V_81 -> V_91 , V_211 ) )
V_15 |= V_212 ;
else
V_15 |= V_207 & V_210 ;
}
V_15 &= ~ V_213 ;
if ( ( V_207 & V_214 ) == V_215 )
if ( F_119 ( V_6 ) &&
F_38 ( V_81 -> V_91 , V_216 ) )
V_15 |= V_217 ;
else
V_15 |= V_218 ;
else
V_15 |= V_219 ;
F_123 ( V_13 , V_15 | V_149 ) ;
if ( F_60 ( V_6 ,
V_13 , V_220 , V_220 ,
100 ) )
F_126 ( L_40 , F_77 ( V_95 ) ) ;
}
static void F_152 ( struct V_5 * V_6 ,
enum V_94 V_97 )
{
T_1 V_15 , V_207 ;
F_149 ( V_6 , (enum V_95 ) V_97 ) ;
F_150 ( V_6 , V_221 ) ;
V_15 = F_11 ( F_151 ( V_117 ) ) ;
V_15 |= V_209 ;
F_123 ( F_151 ( V_117 ) , V_15 ) ;
V_15 = V_149 ;
V_207 = F_11 ( F_59 ( V_97 ) ) ;
if ( ( V_207 & V_222 ) ==
V_215 )
V_15 |= V_218 ;
else
V_15 |= V_219 ;
F_123 ( V_223 , V_15 ) ;
if ( F_60 ( V_6 ,
V_223 ,
V_220 ,
V_220 ,
100 ) )
F_126 ( L_41 ) ;
}
static void F_153 ( struct V_5 * V_6 ,
enum V_95 V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_3 V_13 ;
T_2 V_15 ;
F_154 ( V_6 , V_95 ) ;
F_155 ( V_6 , V_95 ) ;
F_121 ( V_6 , V_95 ) ;
V_13 = F_103 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_149 ;
F_123 ( V_13 , V_15 ) ;
if ( F_60 ( V_6 ,
V_13 , V_220 , 0 ,
50 ) )
F_126 ( L_42 , F_77 ( V_95 ) ) ;
if ( F_105 ( V_57 ) ) {
V_13 = F_151 ( V_95 ) ;
V_15 = F_11 ( V_13 ) ;
V_15 &= ~ V_209 ;
F_123 ( V_13 , V_15 ) ;
}
}
void F_156 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_11 ( V_223 ) ;
V_15 &= ~ V_149 ;
F_123 ( V_223 , V_15 ) ;
if ( F_60 ( V_6 ,
V_223 , V_220 , 0 ,
50 ) )
F_126 ( L_43 ) ;
V_15 = F_11 ( F_151 ( V_117 ) ) ;
V_15 &= ~ V_209 ;
F_123 ( F_151 ( V_117 ) , V_15 ) ;
}
static void F_157 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
enum V_95 V_224 ;
T_3 V_13 ;
T_1 V_15 ;
F_158 ( L_44 , F_77 ( V_95 ) ) ;
F_89 ( V_6 , V_95 ) ;
F_159 ( V_6 , V_95 ) ;
F_91 ( V_6 , V_95 ) ;
if ( F_160 ( V_6 ) )
V_224 = V_221 ;
else
V_224 = V_95 ;
if ( F_161 ( V_6 ) ) {
if ( F_38 ( V_65 -> V_91 , V_225 ) )
F_162 ( V_6 ) ;
else
F_163 ( V_6 , V_95 ) ;
} else {
if ( V_65 -> V_91 -> V_226 ) {
F_164 ( V_6 , V_224 ) ;
F_72 ( V_6 ,
(enum V_95 ) V_97 ) ;
}
}
V_13 = F_59 ( V_97 ) ;
V_15 = F_11 ( V_13 ) ;
if ( V_15 & V_136 ) {
F_28 ( ! ( ( V_95 == V_117 && V_6 -> V_133 & V_134 ) ||
( V_95 == V_124 && V_6 -> V_133 & V_135 ) ) ) ;
return;
}
F_123 ( V_13 , V_15 | V_136 ) ;
F_124 ( V_13 ) ;
if ( V_57 -> V_227 == 0 &&
F_61 ( F_165 ( V_65 ) != V_65 -> V_228 , 50 ) )
F_126 ( L_45 , F_77 ( V_95 ) ) ;
}
static void F_166 ( struct V_81 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
enum V_95 V_95 = V_65 -> V_95 ;
T_3 V_13 ;
T_1 V_15 ;
F_158 ( L_46 , F_77 ( V_95 ) ) ;
F_89 ( V_6 , V_95 ) ;
F_159 ( V_6 , V_95 ) ;
F_91 ( V_6 , V_95 ) ;
V_13 = F_59 ( V_97 ) ;
V_15 = F_11 ( V_13 ) ;
if ( ( V_15 & V_136 ) == 0 )
return;
if ( V_65 -> V_91 -> V_229 )
V_15 &= ~ V_230 ;
if ( ! ( V_95 == V_117 && V_6 -> V_133 & V_134 ) &&
! ( V_95 == V_124 && V_6 -> V_133 & V_135 ) )
V_15 &= ~ V_136 ;
F_123 ( V_13 , V_15 ) ;
if ( ( V_15 & V_136 ) == 0 )
F_57 ( V_65 ) ;
}
static unsigned int F_167 ( const struct V_5 * V_6 )
{
return F_55 ( V_6 ) ? 2048 : 4096 ;
}
static unsigned int F_168 ( const struct V_5 * V_6 ,
V_55 V_231 , unsigned int V_232 )
{
switch ( V_231 ) {
case V_233 :
return V_232 ;
case V_234 :
if ( F_55 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_235 :
if ( F_55 ( V_6 ) || F_169 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_236 :
switch ( V_232 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_170 ( V_232 ) ;
return V_232 ;
}
break;
default:
F_170 ( V_231 ) ;
return V_232 ;
}
}
unsigned int F_171 ( const struct V_5 * V_6 ,
V_55 V_231 , unsigned int V_232 )
{
if ( V_231 == V_233 )
return 1 ;
else
return F_167 ( V_6 ) /
F_168 ( V_6 , V_231 , V_232 ) ;
}
static void F_172 ( const struct V_5 * V_6 ,
unsigned int * V_237 ,
unsigned int * V_238 ,
V_55 V_231 ,
unsigned int V_232 )
{
unsigned int V_239 =
F_168 ( V_6 , V_231 , V_232 ) ;
* V_237 = V_239 / V_232 ;
* V_238 = F_167 ( V_6 ) / V_239 ;
}
unsigned int
F_173 ( struct V_56 * V_57 , unsigned int V_240 ,
T_2 V_241 , V_55 V_231 )
{
unsigned int V_232 = F_174 ( V_241 , 0 ) ;
unsigned int V_238 = F_171 ( F_53 ( V_57 ) , V_231 , V_232 ) ;
return F_175 ( V_240 , V_238 ) ;
}
unsigned int F_176 ( const struct V_242 * V_243 )
{
unsigned int V_244 = 0 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < F_177 ( V_243 -> V_137 ) ; V_139 ++ )
V_244 += V_243 -> V_137 [ V_139 ] . V_245 * V_243 -> V_137 [ V_139 ] . V_240 ;
return V_244 ;
}
static void
F_178 ( struct V_246 * V_247 ,
const struct V_248 * V_90 ,
unsigned int V_249 )
{
if ( F_179 ( V_249 ) ) {
* V_247 = V_250 ;
V_247 -> V_251 . V_252 = F_180 ( V_90 ) -> V_243 ;
} else {
* V_247 = V_253 ;
}
}
static unsigned int F_181 ( const struct V_5 * V_6 )
{
if ( F_58 ( V_6 ) -> V_103 >= 9 )
return 256 * 1024 ;
else if ( F_182 ( V_6 ) || F_183 ( V_6 ) ||
F_16 ( V_6 ) || F_17 ( V_6 ) )
return 128 * 1024 ;
else if ( F_58 ( V_6 ) -> V_103 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_184 ( const struct V_5 * V_6 ,
V_55 V_231 )
{
switch ( V_231 ) {
case V_233 :
return F_181 ( V_6 ) ;
case V_234 :
if ( F_58 ( V_6 ) -> V_103 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_235 :
case V_236 :
return 1 * 1024 * 1024 ;
default:
F_170 ( V_231 ) ;
return 0 ;
}
}
struct V_254 *
F_185 ( struct V_248 * V_90 , unsigned int V_249 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_255 * V_256 = F_186 ( V_90 ) ;
struct V_246 V_247 ;
struct V_254 * V_257 ;
T_1 V_258 ;
F_28 ( ! F_187 ( & V_57 -> V_259 ) ) ;
V_258 = F_184 ( V_6 , V_90 -> V_260 [ 0 ] ) ;
F_178 ( & V_247 , V_90 , V_249 ) ;
if ( F_188 ( V_6 ) && V_258 < 256 * 1024 )
V_258 = 256 * 1024 ;
F_189 ( V_6 ) ;
V_257 = F_190 ( V_256 , V_258 , & V_247 ) ;
if ( F_191 ( V_257 ) )
goto V_72;
if ( F_192 ( V_257 ) ) {
if ( F_193 ( V_257 ) == 0 )
F_194 ( V_257 ) ;
}
V_72:
F_195 ( V_6 ) ;
return V_257 ;
}
void F_196 ( struct V_248 * V_90 , unsigned int V_249 )
{
struct V_255 * V_256 = F_186 ( V_90 ) ;
struct V_246 V_247 ;
struct V_254 * V_257 ;
F_28 ( ! F_187 ( & V_256 -> V_64 . V_57 -> V_259 ) ) ;
F_178 ( & V_247 , V_90 , V_249 ) ;
V_257 = F_197 ( V_256 , & V_247 ) ;
F_198 ( V_257 ) ;
F_199 ( V_257 ) ;
}
static int F_200 ( const struct V_248 * V_90 , int V_137 ,
unsigned int V_249 )
{
if ( F_179 ( V_249 ) )
return F_180 ( V_90 ) -> V_252 [ V_137 ] . V_261 ;
else
return V_90 -> V_262 [ V_137 ] ;
}
T_1 F_201 ( int V_263 , int V_264 ,
const struct V_265 * V_43 ,
int V_137 )
{
const struct V_248 * V_90 = V_43 -> V_64 . V_90 ;
unsigned int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
unsigned int V_261 = V_90 -> V_262 [ V_137 ] ;
return V_264 * V_261 + V_263 * V_232 ;
}
void F_202 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 ,
int V_137 )
{
const struct V_266 * V_267 = F_180 ( V_43 -> V_64 . V_90 ) ;
unsigned int V_249 = V_43 -> V_64 . V_249 ;
if ( F_179 ( V_249 ) ) {
* V_263 += V_267 -> V_252 [ V_137 ] . V_263 ;
* V_264 += V_267 -> V_252 [ V_137 ] . V_264 ;
} else {
* V_263 += V_267 -> V_268 [ V_137 ] . V_263 ;
* V_264 += V_267 -> V_268 [ V_137 ] . V_264 ;
}
}
static T_1 F_203 ( int * V_263 , int * V_264 ,
unsigned int V_237 ,
unsigned int V_238 ,
unsigned int V_269 ,
unsigned int V_270 ,
T_1 V_271 ,
T_1 V_272 )
{
unsigned int V_273 = V_270 * V_237 ;
unsigned int V_274 ;
F_28 ( V_271 & ( V_269 - 1 ) ) ;
F_28 ( V_272 & ( V_269 - 1 ) ) ;
F_28 ( V_272 > V_271 ) ;
V_274 = ( V_271 - V_272 ) / V_269 ;
* V_264 += V_274 / V_270 * V_238 ;
* V_263 += V_274 % V_270 * V_237 ;
* V_264 += * V_263 / V_273 * V_238 ;
* V_263 %= V_273 ;
return V_272 ;
}
static T_1 F_204 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 , int V_137 ,
T_1 V_271 , T_1 V_272 )
{
const struct V_5 * V_6 = F_53 ( V_43 -> V_64 . V_137 -> V_57 ) ;
const struct V_248 * V_90 = V_43 -> V_64 . V_90 ;
unsigned int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
unsigned int V_249 = V_43 -> V_64 . V_249 ;
unsigned int V_261 = F_200 ( V_90 , V_137 , V_249 ) ;
F_28 ( V_272 > V_271 ) ;
if ( V_90 -> V_260 [ V_137 ] != V_233 ) {
unsigned int V_269 , V_237 , V_238 ;
unsigned int V_270 ;
V_269 = F_167 ( V_6 ) ;
F_172 ( V_6 , & V_237 , & V_238 ,
V_90 -> V_260 [ V_137 ] , V_232 ) ;
if ( F_179 ( V_249 ) ) {
V_270 = V_261 / V_238 ;
F_205 ( V_237 , V_238 ) ;
} else {
V_270 = V_261 / ( V_237 * V_232 ) ;
}
F_203 ( V_263 , V_264 , V_237 , V_238 ,
V_269 , V_270 ,
V_271 , V_272 ) ;
} else {
V_271 += * V_264 * V_261 + * V_263 * V_232 ;
* V_264 = ( V_271 - V_272 ) / V_261 ;
* V_263 = ( ( V_271 - V_272 ) - * V_264 * V_261 ) / V_232 ;
}
return V_272 ;
}
static T_1 F_206 ( const struct V_5 * V_6 ,
int * V_263 , int * V_264 ,
const struct V_248 * V_90 , int V_137 ,
unsigned int V_261 ,
unsigned int V_249 ,
T_1 V_258 )
{
V_55 V_231 = V_90 -> V_260 [ V_137 ] ;
unsigned int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
T_1 V_275 , V_276 ;
if ( V_258 )
V_258 -- ;
if ( V_231 != V_233 ) {
unsigned int V_269 , V_237 , V_238 ;
unsigned int V_277 , V_274 , V_270 ;
V_269 = F_167 ( V_6 ) ;
F_172 ( V_6 , & V_237 , & V_238 ,
V_231 , V_232 ) ;
if ( F_179 ( V_249 ) ) {
V_270 = V_261 / V_238 ;
F_205 ( V_237 , V_238 ) ;
} else {
V_270 = V_261 / ( V_237 * V_232 ) ;
}
V_277 = * V_264 / V_238 ;
* V_264 %= V_238 ;
V_274 = * V_263 / V_237 ;
* V_263 %= V_237 ;
V_275 = ( V_277 * V_270 + V_274 ) * V_269 ;
V_276 = V_275 & ~ V_258 ;
F_203 ( V_263 , V_264 , V_237 , V_238 ,
V_269 , V_270 ,
V_275 , V_276 ) ;
} else {
V_275 = * V_264 * V_261 + * V_263 * V_232 ;
V_276 = V_275 & ~ V_258 ;
* V_264 = ( V_275 & V_258 ) / V_261 ;
* V_263 = ( ( V_275 & V_258 ) - * V_264 * V_261 ) / V_232 ;
}
return V_276 ;
}
T_1 F_207 ( int * V_263 , int * V_264 ,
const struct V_265 * V_43 ,
int V_137 )
{
const struct V_5 * V_6 = F_53 ( V_43 -> V_64 . V_137 -> V_57 ) ;
const struct V_248 * V_90 = V_43 -> V_64 . V_90 ;
unsigned int V_249 = V_43 -> V_64 . V_249 ;
int V_261 = F_200 ( V_90 , V_137 , V_249 ) ;
T_1 V_258 ;
if ( V_90 -> V_241 == V_278 && V_137 == 1 )
V_258 = 4096 ;
else
V_258 = F_184 ( V_6 , V_90 -> V_260 [ V_137 ] ) ;
return F_206 ( V_6 , V_263 , V_264 , V_90 , V_137 , V_261 ,
V_249 , V_258 ) ;
}
static void F_208 ( int * V_263 , int * V_264 ,
const struct V_248 * V_90 , int V_137 )
{
unsigned int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
unsigned int V_261 = V_90 -> V_262 [ V_137 ] ;
T_1 V_279 = V_90 -> V_280 [ V_137 ] ;
* V_264 = V_279 / V_261 ;
* V_263 = V_279 % V_261 / V_232 ;
}
static unsigned int F_209 ( V_55 V_231 )
{
switch ( V_231 ) {
case V_234 :
return V_281 ;
case V_235 :
return V_282 ;
default:
return V_283 ;
}
}
static int
F_210 ( struct V_5 * V_6 ,
struct V_248 * V_90 )
{
struct V_266 * V_267 = F_180 ( V_90 ) ;
struct V_242 * V_243 = & V_267 -> V_243 ;
T_1 V_284 = 0 ;
unsigned int V_285 = 0 ;
T_2 V_286 = V_90 -> V_241 ;
int V_139 , V_287 = F_211 ( V_286 ) ;
unsigned int V_269 = F_167 ( V_6 ) ;
for ( V_139 = 0 ; V_139 < V_287 ; V_139 ++ ) {
unsigned int V_245 , V_240 ;
unsigned int V_232 , V_244 ;
T_1 V_275 ;
int V_263 , V_264 ;
V_232 = F_174 ( V_286 , V_139 ) ;
V_245 = F_212 ( V_90 -> V_245 , V_286 , V_139 ) ;
V_240 = F_213 ( V_90 -> V_240 , V_286 , V_139 ) ;
F_208 ( & V_263 , & V_264 , V_90 , V_139 ) ;
if ( F_214 ( V_267 -> V_256 ) &&
( V_263 + V_245 ) * V_232 > V_90 -> V_262 [ V_139 ] ) {
F_215 ( L_47 ,
V_139 , V_90 -> V_280 [ V_139 ] ) ;
return - V_288 ;
}
V_267 -> V_268 [ V_139 ] . V_263 = V_263 ;
V_267 -> V_268 [ V_139 ] . V_264 = V_264 ;
V_275 = F_206 ( V_6 , & V_263 , & V_264 ,
V_90 , 0 , V_90 -> V_262 [ V_139 ] ,
V_289 , V_269 ) ;
V_275 /= V_269 ;
if ( V_90 -> V_260 [ V_139 ] != V_233 ) {
unsigned int V_237 , V_238 ;
unsigned int V_270 ;
struct V_290 V_291 ;
F_172 ( V_6 , & V_237 , & V_238 ,
V_90 -> V_260 [ V_139 ] , V_232 ) ;
V_243 -> V_137 [ V_139 ] . V_275 = V_275 ;
V_243 -> V_137 [ V_139 ] . V_292 = F_216 ( V_90 -> V_262 [ V_139 ] , V_237 * V_232 ) ;
V_243 -> V_137 [ V_139 ] . V_245 = F_216 ( V_263 + V_245 , V_237 ) ;
V_243 -> V_137 [ V_139 ] . V_240 = F_216 ( V_264 + V_240 , V_238 ) ;
V_267 -> V_252 [ V_139 ] . V_261 =
V_243 -> V_137 [ V_139 ] . V_240 * V_238 ;
V_244 = V_243 -> V_137 [ V_139 ] . V_292 * V_243 -> V_137 [ V_139 ] . V_240 ;
if ( V_263 != 0 )
V_244 ++ ;
V_291 . V_293 = V_263 ;
V_291 . y1 = V_264 ;
V_291 . V_294 = V_263 + V_245 ;
V_291 . V_295 = V_264 + V_240 ;
F_217 ( & V_291 ,
V_243 -> V_137 [ V_139 ] . V_245 * V_237 ,
V_243 -> V_137 [ V_139 ] . V_240 * V_238 ,
V_296 ) ;
V_263 = V_291 . V_293 ;
V_264 = V_291 . y1 ;
V_270 = V_267 -> V_252 [ V_139 ] . V_261 / V_238 ;
F_205 ( V_237 , V_238 ) ;
F_203 ( & V_263 , & V_264 , V_269 ,
V_237 , V_238 , V_270 ,
V_284 * V_269 , 0 ) ;
V_284 += V_243 -> V_137 [ V_139 ] . V_245 * V_243 -> V_137 [ V_139 ] . V_240 ;
V_267 -> V_252 [ V_139 ] . V_263 = V_263 ;
V_267 -> V_252 [ V_139 ] . V_264 = V_264 ;
} else {
V_244 = F_216 ( ( V_264 + V_240 ) * V_90 -> V_262 [ V_139 ] +
V_263 * V_232 , V_269 ) ;
}
V_285 = V_61 ( V_285 , V_275 + V_244 ) ;
}
if ( V_285 * V_269 > F_180 ( V_90 ) -> V_256 -> V_64 . V_244 ) {
F_215 ( L_48 ,
V_285 * V_269 , F_180 ( V_90 ) -> V_256 -> V_64 . V_244 ) ;
return - V_288 ;
}
return 0 ;
}
static int F_218 ( int V_286 )
{
switch ( V_286 ) {
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
static int F_219 ( int V_286 , bool V_311 , bool V_312 )
{
switch ( V_286 ) {
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
F_220 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_320 * V_321 = & V_6 -> V_321 ;
struct V_255 * V_256 = NULL ;
struct V_322 V_323 = { 0 } ;
struct V_248 * V_90 = & V_319 -> V_90 -> V_64 ;
T_1 V_324 = F_221 ( V_319 -> V_64 , V_325 ) ;
T_1 V_326 = F_222 ( V_319 -> V_64 + V_319 -> V_244 ,
V_325 ) ;
V_326 -= V_324 ;
if ( V_319 -> V_244 == 0 )
return false ;
if ( V_326 * 2 > V_321 -> V_327 )
return false ;
F_3 ( & V_57 -> V_259 ) ;
V_256 = F_223 ( V_57 ,
V_324 ,
V_324 ,
V_326 ) ;
if ( ! V_256 ) {
F_5 ( & V_57 -> V_259 ) ;
return false ;
}
if ( V_319 -> V_328 == V_281 )
V_256 -> V_329 = V_90 -> V_262 [ 0 ] | V_281 ;
V_323 . V_241 = V_90 -> V_241 ;
V_323 . V_245 = V_90 -> V_245 ;
V_323 . V_240 = V_90 -> V_240 ;
V_323 . V_262 [ 0 ] = V_90 -> V_262 [ 0 ] ;
V_323 . V_260 [ 0 ] = V_90 -> V_260 [ 0 ] ;
V_323 . V_330 = V_331 ;
if ( F_224 ( V_57 , F_180 ( V_90 ) ,
& V_323 , V_256 ) ) {
F_158 ( L_49 ) ;
goto V_332;
}
F_5 ( & V_57 -> V_259 ) ;
F_158 ( L_50 , V_256 ) ;
return true ;
V_332:
F_225 ( V_256 ) ;
F_5 ( & V_57 -> V_259 ) ;
return false ;
}
static void
F_226 ( struct V_333 * V_137 )
{
if ( V_137 -> V_90 == V_137 -> V_43 -> V_90 )
return;
if ( V_137 -> V_43 -> V_90 )
F_227 ( V_137 -> V_43 -> V_90 ) ;
V_137 -> V_43 -> V_90 = V_137 -> V_90 ;
if ( V_137 -> V_43 -> V_90 )
F_228 ( V_137 -> V_43 -> V_90 ) ;
}
static void
F_229 ( struct V_81 * V_81 ,
struct V_318 * V_319 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_334 ;
struct V_81 * V_139 ;
struct V_255 * V_256 ;
struct V_333 * V_89 = V_81 -> V_64 . V_89 ;
struct V_335 * V_336 = V_89 -> V_43 ;
struct V_42 * V_62 = V_81 -> V_64 . V_43 ;
struct V_337 * V_337 = F_230 ( V_89 ) ;
struct V_265 * V_338 =
F_231 ( V_336 ) ;
struct V_248 * V_90 ;
if ( ! V_319 -> V_90 )
return;
if ( F_220 ( V_81 , V_319 ) ) {
V_90 = & V_319 -> V_90 -> V_64 ;
goto V_339;
}
F_232 ( V_319 -> V_90 ) ;
F_233 (dev, c) {
V_139 = F_47 ( V_334 ) ;
if ( V_334 == & V_81 -> V_64 )
continue;
if ( ! V_139 -> V_88 )
continue;
V_90 = V_334 -> V_89 -> V_90 ;
if ( ! V_90 )
continue;
V_256 = F_186 ( V_90 ) ;
if ( F_234 ( V_256 , NULL ) == V_319 -> V_64 ) {
F_228 ( V_90 ) ;
goto V_339;
}
}
F_231 ( V_336 ) -> V_64 . V_340 = false ;
V_62 -> V_341 &= ~ ( 1 << F_235 ( V_89 ) ) ;
F_236 ( & V_81 -> V_64 ) ;
V_337 -> V_342 ( V_89 , & V_81 -> V_64 ) ;
return;
V_339:
V_336 -> V_343 = 0 ;
V_336 -> V_344 = 0 ;
V_336 -> V_345 = V_90 -> V_245 << 16 ;
V_336 -> V_346 = V_90 -> V_240 << 16 ;
V_336 -> V_347 = 0 ;
V_336 -> V_348 = 0 ;
V_336 -> V_349 = V_90 -> V_245 ;
V_336 -> V_350 = V_90 -> V_240 ;
V_338 -> V_64 . V_351 . V_293 = V_336 -> V_343 ;
V_338 -> V_64 . V_351 . y1 = V_336 -> V_344 ;
V_338 -> V_64 . V_351 . V_294 = V_336 -> V_343 + V_336 -> V_345 ;
V_338 -> V_64 . V_351 . V_295 = V_336 -> V_344 + V_336 -> V_346 ;
V_338 -> V_64 . V_352 . V_293 = V_336 -> V_347 ;
V_338 -> V_64 . V_352 . y1 = V_336 -> V_348 ;
V_338 -> V_64 . V_352 . V_294 = V_336 -> V_347 + V_336 -> V_349 ;
V_338 -> V_64 . V_352 . V_295 = V_336 -> V_348 + V_336 -> V_350 ;
V_256 = F_186 ( V_90 ) ;
if ( F_214 ( V_256 ) )
V_6 -> V_353 = true ;
F_228 ( V_90 ) ;
V_89 -> V_90 = V_89 -> V_43 -> V_90 = V_90 ;
V_89 -> V_65 = V_89 -> V_43 -> V_65 = & V_81 -> V_64 ;
V_81 -> V_64 . V_43 -> V_341 |= ( 1 << F_235 ( V_89 ) ) ;
F_237 ( F_230 ( V_89 ) -> V_354 ,
& V_256 -> V_355 ) ;
}
static int F_238 ( const struct V_248 * V_90 , int V_137 ,
unsigned int V_249 )
{
int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
switch ( V_90 -> V_260 [ V_137 ] ) {
case V_233 :
case V_234 :
switch ( V_232 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_170 ( V_232 ) ;
break;
}
break;
case V_235 :
case V_236 :
switch ( V_232 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_170 ( V_232 ) ;
break;
}
break;
default:
F_170 ( V_90 -> V_260 [ V_137 ] ) ;
}
return 2048 ;
}
static int F_239 ( struct V_265 * V_336 )
{
const struct V_5 * V_6 = F_53 ( V_336 -> V_64 . V_137 -> V_57 ) ;
const struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
int V_356 = F_240 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_357 = F_241 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_358 = F_238 ( V_90 , 0 , V_249 ) ;
int V_359 = 4096 ;
T_1 V_258 , V_275 , V_360 = V_336 -> V_361 . V_275 ;
if ( V_356 > V_358 || V_357 > V_359 ) {
F_158 ( L_51 ,
V_356 , V_357 , V_358 , V_359 ) ;
return - V_288 ;
}
F_202 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_275 = F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_258 = F_184 ( V_6 , V_90 -> V_260 [ 0 ] ) ;
if ( V_275 > V_360 )
V_275 = F_204 ( & V_263 , & V_264 , V_336 , 0 ,
V_275 , V_360 & ~ ( V_258 - 1 ) ) ;
if ( V_90 -> V_260 [ 0 ] == V_234 ) {
int V_232 = F_174 ( V_90 -> V_241 , 0 ) ;
while ( ( V_263 + V_356 ) * V_232 > V_90 -> V_262 [ 0 ] ) {
if ( V_275 == 0 ) {
F_158 ( L_52 ) ;
return - V_288 ;
}
V_275 = F_204 ( & V_263 , & V_264 , V_336 , 0 ,
V_275 , V_275 - V_258 ) ;
}
}
V_336 -> main. V_275 = V_275 ;
V_336 -> main. V_263 = V_263 ;
V_336 -> main. V_264 = V_264 ;
return 0 ;
}
static int F_242 ( struct V_265 * V_336 )
{
const struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
int V_358 = F_238 ( V_90 , 1 , V_249 ) ;
int V_359 = 4096 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 17 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 17 ;
int V_356 = F_240 ( & V_336 -> V_64 . V_351 ) >> 17 ;
int V_357 = F_241 ( & V_336 -> V_64 . V_351 ) >> 17 ;
T_1 V_275 ;
F_202 ( & V_263 , & V_264 , V_336 , 1 ) ;
V_275 = F_207 ( & V_263 , & V_264 , V_336 , 1 ) ;
if ( V_356 > V_358 || V_357 > V_359 ) {
F_158 ( L_53 ,
V_356 , V_357 , V_358 , V_359 ) ;
return - V_288 ;
}
V_336 -> V_361 . V_275 = V_275 ;
V_336 -> V_361 . V_263 = V_263 ;
V_336 -> V_361 . V_264 = V_264 ;
return 0 ;
}
int F_243 ( struct V_265 * V_336 )
{
const struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
int V_362 ;
if ( F_179 ( V_249 ) )
F_217 ( & V_336 -> V_64 . V_351 ,
V_90 -> V_245 << 16 , V_90 -> V_240 << 16 ,
V_296 ) ;
if ( V_90 -> V_241 == V_278 ) {
V_362 = F_242 ( V_336 ) ;
if ( V_362 )
return V_362 ;
} else {
V_336 -> V_361 . V_275 = ~ 0xfff ;
V_336 -> V_361 . V_263 = 0 ;
V_336 -> V_361 . V_264 = 0 ;
}
V_362 = F_239 ( V_336 ) ;
if ( V_362 )
return V_362 ;
return 0 ;
}
static void F_244 ( struct V_333 * V_89 ,
const struct V_37 * V_62 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_89 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
struct V_255 * V_256 = F_186 ( V_90 ) ;
int V_137 = V_81 -> V_137 ;
T_1 V_279 ;
T_1 V_363 ;
T_3 V_13 = F_87 ( V_137 ) ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
V_363 = V_364 ;
V_363 |= V_138 ;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
if ( V_81 -> V_95 == V_124 )
V_363 |= V_365 ;
F_123 ( F_245 ( V_137 ) ,
( ( V_62 -> V_366 - 1 ) << 16 ) |
( V_62 -> V_367 - 1 ) ) ;
F_123 ( F_246 ( V_137 ) , 0 ) ;
} else if ( F_17 ( V_57 ) && V_137 == V_368 ) {
F_123 ( F_247 ( V_137 ) ,
( ( V_62 -> V_366 - 1 ) << 16 ) |
( V_62 -> V_367 - 1 ) ) ;
F_123 ( F_248 ( V_137 ) , 0 ) ;
F_123 ( F_249 ( V_137 ) , 0 ) ;
}
switch ( V_90 -> V_241 ) {
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
F_145 () ;
}
if ( F_250 ( V_6 ) >= 4 &&
V_90 -> V_260 [ 0 ] == V_234 )
V_363 |= V_369 ;
if ( F_18 ( V_57 ) )
V_363 |= V_370 ;
F_202 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 )
V_81 -> V_371 =
F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( V_249 == V_372 ) {
V_363 |= V_373 ;
V_263 += ( V_62 -> V_367 - 1 ) ;
V_264 += ( V_62 -> V_366 - 1 ) ;
}
V_279 = F_201 ( V_263 , V_264 , V_336 , 0 ) ;
if ( F_58 ( V_57 ) -> V_103 < 4 )
V_81 -> V_371 = V_279 ;
V_81 -> V_374 = V_263 ;
V_81 -> V_375 = V_264 ;
F_123 ( V_13 , V_363 ) ;
F_123 ( F_251 ( V_137 ) , V_90 -> V_262 [ 0 ] ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_123 ( F_252 ( V_137 ) ,
F_253 ( V_90 , V_249 ) +
V_81 -> V_371 ) ;
F_123 ( F_254 ( V_137 ) , ( V_264 << 16 ) | V_263 ) ;
F_123 ( F_255 ( V_137 ) , V_279 ) ;
} else
F_123 ( F_256 ( V_137 ) , F_234 ( V_256 , NULL ) + V_279 ) ;
F_124 ( V_13 ) ;
}
static void F_257 ( struct V_333 * V_89 ,
struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_137 = V_81 -> V_137 ;
F_123 ( F_87 ( V_137 ) , 0 ) ;
if ( F_58 ( V_6 ) -> V_103 >= 4 )
F_123 ( F_252 ( V_137 ) , 0 ) ;
else
F_123 ( F_256 ( V_137 ) , 0 ) ;
F_124 ( F_87 ( V_137 ) ) ;
}
static void F_258 ( struct V_333 * V_89 ,
const struct V_37 * V_62 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_89 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
int V_137 = V_81 -> V_137 ;
T_1 V_279 ;
T_1 V_363 ;
T_3 V_13 = F_87 ( V_137 ) ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
int V_263 = V_336 -> V_64 . V_351 . V_293 >> 16 ;
int V_264 = V_336 -> V_64 . V_351 . y1 >> 16 ;
V_363 = V_364 ;
V_363 |= V_138 ;
if ( F_259 ( V_57 ) || F_260 ( V_57 ) )
V_363 |= V_376 ;
switch ( V_90 -> V_241 ) {
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
F_145 () ;
}
if ( V_90 -> V_260 [ 0 ] == V_234 )
V_363 |= V_369 ;
if ( ! F_259 ( V_57 ) && ! F_260 ( V_57 ) )
V_363 |= V_370 ;
F_202 ( & V_263 , & V_264 , V_336 , 0 ) ;
V_81 -> V_371 =
F_207 ( & V_263 , & V_264 , V_336 , 0 ) ;
if ( V_249 == V_372 ) {
V_363 |= V_373 ;
if ( ! F_259 ( V_57 ) && ! F_260 ( V_57 ) ) {
V_263 += ( V_62 -> V_367 - 1 ) ;
V_264 += ( V_62 -> V_366 - 1 ) ;
}
}
V_279 = F_201 ( V_263 , V_264 , V_336 , 0 ) ;
V_81 -> V_374 = V_263 ;
V_81 -> V_375 = V_264 ;
F_123 ( V_13 , V_363 ) ;
F_123 ( F_251 ( V_137 ) , V_90 -> V_262 [ 0 ] ) ;
F_123 ( F_252 ( V_137 ) ,
F_253 ( V_90 , V_249 ) +
V_81 -> V_371 ) ;
if ( F_259 ( V_57 ) || F_260 ( V_57 ) ) {
F_123 ( F_261 ( V_137 ) , ( V_264 << 16 ) | V_263 ) ;
} else {
F_123 ( F_254 ( V_137 ) , ( V_264 << 16 ) | V_263 ) ;
F_123 ( F_255 ( V_137 ) , V_279 ) ;
}
F_124 ( V_13 ) ;
}
T_1 F_262 ( const struct V_5 * V_6 ,
V_55 V_231 , T_2 V_241 )
{
if ( V_231 == V_233 ) {
return 64 ;
} else {
int V_232 = F_174 ( V_241 , 0 ) ;
return F_168 ( V_6 , V_231 , V_232 ) ;
}
}
T_1 F_253 ( struct V_248 * V_90 ,
unsigned int V_249 )
{
struct V_255 * V_256 = F_186 ( V_90 ) ;
struct V_246 V_247 ;
struct V_254 * V_257 ;
F_178 ( & V_247 , V_90 , V_249 ) ;
V_257 = F_197 ( V_256 , & V_247 ) ;
if ( F_7 ( ! V_257 , L_54 ,
V_247 . type ) )
return - 1 ;
return F_263 ( V_257 ) ;
}
static void F_264 ( struct V_81 * V_81 , int V_377 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_123 ( F_265 ( V_81 -> V_95 , V_377 ) , 0 ) ;
F_123 ( F_266 ( V_81 -> V_95 , V_377 ) , 0 ) ;
F_123 ( F_267 ( V_81 -> V_95 , V_377 ) , 0 ) ;
}
static void F_268 ( struct V_81 * V_81 )
{
struct V_378 * V_379 ;
int V_139 ;
V_379 = & V_81 -> V_91 -> V_379 ;
for ( V_139 = 0 ; V_139 < V_81 -> V_380 ; V_139 ++ ) {
if ( ! V_379 -> V_381 [ V_139 ] . V_382 )
F_264 ( V_81 , V_139 ) ;
}
}
T_1 F_269 ( const struct V_248 * V_90 , int V_137 ,
unsigned int V_249 )
{
const struct V_5 * V_6 = F_53 ( V_90 -> V_57 ) ;
T_1 V_292 = F_200 ( V_90 , V_137 , V_249 ) ;
if ( F_179 ( V_249 ) ) {
int V_232 = F_174 ( V_90 -> V_241 , V_137 ) ;
V_292 /= F_171 ( V_6 , V_90 -> V_260 [ 0 ] , V_232 ) ;
} else {
V_292 /= F_262 ( V_6 , V_90 -> V_260 [ 0 ] ,
V_90 -> V_241 ) ;
}
return V_292 ;
}
T_1 F_270 ( T_2 V_241 )
{
switch ( V_241 ) {
case V_298 :
return V_383 ;
case V_302 :
return V_313 ;
case V_306 :
return V_314 | V_384 ;
case V_304 :
return V_314 ;
case V_315 :
return V_314 | V_384 |
V_385 ;
case V_316 :
return V_314 |
V_385 ;
case V_308 :
return V_317 ;
case V_310 :
return V_384 | V_317 ;
case V_386 :
return V_387 | V_388 ;
case V_389 :
return V_387 | V_390 ;
case V_391 :
return V_387 | V_392 ;
case V_393 :
return V_387 | V_394 ;
default:
F_170 ( V_241 ) ;
}
return 0 ;
}
T_1 F_271 ( V_55 V_231 )
{
switch ( V_231 ) {
case V_233 :
break;
case V_234 :
return V_395 ;
case V_235 :
return V_396 ;
case V_236 :
return V_397 ;
default:
F_170 ( V_231 ) ;
}
return 0 ;
}
T_1 F_272 ( unsigned int V_249 )
{
switch ( V_249 ) {
case V_289 :
break;
case V_398 :
return V_399 ;
case V_372 :
return V_400 ;
case V_296 :
return V_401 ;
default:
F_170 ( V_249 ) ;
}
return 0 ;
}
static void F_273 ( struct V_333 * V_137 ,
const struct V_37 * V_62 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
const struct V_402 * V_403 = & V_6 -> V_403 . V_404 ;
int V_95 = V_81 -> V_95 ;
T_1 V_405 ;
unsigned int V_249 = V_336 -> V_64 . V_249 ;
T_1 V_292 = F_269 ( V_90 , 0 , V_249 ) ;
T_1 V_406 = V_336 -> main. V_275 ;
int V_407 = V_336 -> V_407 ;
int V_343 = V_336 -> main. V_263 ;
int V_344 = V_336 -> main. V_264 ;
int V_345 = F_240 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_346 = F_241 ( & V_336 -> V_64 . V_351 ) >> 16 ;
int V_408 = V_336 -> V_64 . V_352 . V_293 ;
int V_409 = V_336 -> V_64 . V_352 . y1 ;
int V_410 = F_240 ( & V_336 -> V_64 . V_352 ) ;
int V_411 = F_241 ( & V_336 -> V_64 . V_352 ) ;
V_405 = V_144 |
V_412 |
V_413 ;
V_405 |= F_270 ( V_90 -> V_241 ) ;
V_405 |= F_271 ( V_90 -> V_260 [ 0 ] ) ;
V_405 |= V_414 ;
V_405 |= F_272 ( V_249 ) ;
V_345 -- ;
V_346 -- ;
V_410 -- ;
V_411 -- ;
V_81 -> V_371 = V_406 ;
V_81 -> V_374 = V_343 ;
V_81 -> V_375 = V_344 ;
if ( V_403 -> V_415 & F_274 ( & V_81 -> V_64 ) )
F_275 ( V_81 , V_403 , 0 ) ;
F_123 ( F_93 ( V_95 , 0 ) , V_405 ) ;
F_123 ( F_276 ( V_95 , 0 ) , ( V_344 << 16 ) | V_343 ) ;
F_123 ( F_277 ( V_95 , 0 ) , V_292 ) ;
F_123 ( F_278 ( V_95 , 0 ) , ( V_346 << 16 ) | V_345 ) ;
if ( V_407 >= 0 ) {
T_2 V_416 = 0 ;
F_28 ( ! V_410 || ! V_411 ) ;
V_416 = V_417 | F_279 ( 0 ) |
V_62 -> V_379 . V_381 [ V_407 ] . V_418 ;
F_123 ( F_265 ( V_95 , V_407 ) , V_416 ) ;
F_123 ( F_280 ( V_95 , V_407 ) , 0 ) ;
F_123 ( F_266 ( V_95 , V_407 ) , ( V_408 << 16 ) | V_409 ) ;
F_123 ( F_267 ( V_95 , V_407 ) , ( V_410 << 16 ) | V_411 ) ;
F_123 ( F_281 ( V_95 , 0 ) , 0 ) ;
} else {
F_123 ( F_281 ( V_95 , 0 ) , ( V_409 << 16 ) | V_408 ) ;
}
F_123 ( F_282 ( V_95 , 0 ) ,
F_253 ( V_90 , V_249 ) + V_406 ) ;
F_124 ( F_282 ( V_95 , 0 ) ) ;
}
static void F_283 ( struct V_333 * V_89 ,
struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( ! V_65 -> V_89 -> V_43 -> V_340 )
F_275 ( V_81 , & V_6 -> V_403 . V_404 , 0 ) ;
F_123 ( F_93 ( V_95 , 0 ) , 0 ) ;
F_123 ( F_282 ( V_95 , 0 ) , 0 ) ;
F_124 ( F_282 ( V_95 , 0 ) ) ;
}
static int
F_284 ( struct V_87 * V_65 , struct V_248 * V_90 ,
int V_263 , int V_264 , enum V_419 V_43 )
{
F_126 ( L_55 ) ;
return - V_420 ;
}
static void F_285 ( struct V_5 * V_6 )
{
struct V_81 * V_65 ;
F_137 (&dev_priv->drm, crtc)
F_286 ( V_6 , V_65 -> V_95 ) ;
}
static void F_287 ( struct V_56 * V_57 )
{
struct V_87 * V_65 ;
F_233 (dev, crtc) {
struct V_337 * V_137 = F_230 ( V_65 -> V_89 ) ;
struct V_265 * V_336 =
F_231 ( V_137 -> V_64 . V_43 ) ;
if ( V_336 -> V_64 . V_340 )
V_137 -> V_421 ( & V_137 -> V_64 ,
F_288 ( V_65 -> V_43 ) ,
V_336 ) ;
}
}
static int
F_289 ( struct V_56 * V_57 ,
struct V_422 * V_43 )
{
struct V_42 * V_62 ;
struct V_87 * V_65 ;
int V_139 , V_362 ;
F_290 ( V_57 ) ;
F_291 ( V_57 ) ;
if ( ! V_43 )
return 0 ;
F_292 (state, crtc, crtc_state, i) {
V_62 -> V_423 = true ;
}
F_293 ( V_43 ) -> V_424 = true ;
V_362 = F_294 ( V_43 ) ;
F_28 ( V_362 == - V_425 ) ;
return V_362 ;
}
static bool F_295 ( struct V_5 * V_6 )
{
return F_296 ( V_6 ) &&
F_250 ( V_6 ) < 5 && ! F_18 ( V_6 ) ;
}
void F_297 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_426 * V_427 = & V_6 -> V_428 ;
struct V_422 * V_43 ;
int V_362 ;
F_3 ( & V_57 -> V_429 . V_430 ) ;
F_298 ( V_427 , 0 ) ;
while ( 1 ) {
V_362 = F_299 ( V_57 , V_427 ) ;
if ( V_362 != - V_425 )
break;
F_300 ( V_427 ) ;
}
if ( ! V_431 . V_432 &&
! F_295 ( V_6 ) )
return;
V_43 = F_301 ( V_57 , V_427 ) ;
if ( F_191 ( V_43 ) ) {
V_362 = F_302 ( V_43 ) ;
V_43 = NULL ;
F_126 ( L_56 , V_362 ) ;
goto V_72;
}
V_362 = F_303 ( V_57 , V_427 ) ;
if ( V_362 ) {
F_126 ( L_57 , V_362 ) ;
goto V_72;
}
V_6 -> V_433 = V_43 ;
V_43 -> V_434 = V_427 ;
return;
V_72:
F_304 ( V_43 ) ;
}
void F_305 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_426 * V_427 = & V_6 -> V_428 ;
struct V_422 * V_43 = V_6 -> V_433 ;
int V_362 ;
F_285 ( V_6 ) ;
V_6 -> V_433 = NULL ;
V_6 -> V_433 = NULL ;
if ( ! F_295 ( V_6 ) ) {
if ( ! V_43 ) {
F_287 ( V_57 ) ;
} else {
V_362 = F_289 ( V_57 , V_43 ) ;
if ( V_362 )
F_126 ( L_58 , V_362 ) ;
}
} else {
F_306 ( V_6 ) ;
F_307 ( V_6 ) ;
F_308 ( V_6 ) ;
F_309 ( V_57 ) ;
F_310 ( & V_6 -> V_435 ) ;
if ( V_6 -> V_436 . V_437 )
V_6 -> V_436 . V_437 ( V_6 ) ;
F_311 ( & V_6 -> V_435 ) ;
V_362 = F_289 ( V_57 , V_43 ) ;
if ( V_362 )
F_126 ( L_58 , V_362 ) ;
F_312 ( V_6 ) ;
}
F_313 ( V_427 ) ;
F_314 ( V_427 ) ;
F_5 ( & V_57 -> V_429 . V_430 ) ;
}
static bool F_315 ( struct V_81 * V_65 )
{
struct V_438 * error = & F_53 ( V_65 -> V_64 . V_57 ) -> V_439 ;
if ( F_316 ( error ) )
return true ;
if ( V_65 -> V_440 != F_317 ( error ) )
return true ;
return false ;
}
static bool F_318 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
bool V_441 ;
if ( F_315 ( V_81 ) )
return false ;
F_310 ( & V_57 -> V_442 ) ;
V_441 = F_47 ( V_65 ) -> V_443 != NULL ;
F_311 ( & V_57 -> V_442 ) ;
return V_441 ;
}
static void F_319 ( struct V_81 * V_65 ,
struct V_37 * V_444 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 =
F_288 ( V_65 -> V_64 . V_43 ) ;
V_65 -> V_64 . V_418 = V_65 -> V_64 . V_43 -> V_418 ;
F_158 ( L_59 ,
V_444 -> V_367 , V_444 -> V_366 ,
V_38 -> V_367 , V_38 -> V_366 ) ;
F_123 ( F_320 ( V_65 -> V_95 ) ,
( ( V_38 -> V_367 - 1 ) << 16 ) |
( V_38 -> V_366 - 1 ) ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_268 ( V_65 ) ;
if ( V_38 -> V_445 . V_148 )
F_321 ( V_65 ) ;
} else if ( F_15 ( V_57 ) ) {
if ( V_38 -> V_445 . V_148 )
F_322 ( V_65 ) ;
else if ( V_444 -> V_445 . V_148 )
F_323 ( V_65 , true ) ;
}
}
static void F_324 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( F_325 ( V_57 ) ) {
V_446 &= ~ V_447 ;
V_446 |= V_447 | V_448 ;
} else {
V_446 &= ~ V_449 ;
V_446 |= V_449 | V_448 ;
}
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( F_105 ( V_57 ) ) {
V_446 &= ~ V_450 ;
V_446 |= V_451 ;
} else {
V_446 &= ~ V_449 ;
V_446 |= V_449 ;
}
F_123 ( V_13 , V_446 | V_452 ) ;
F_124 ( V_13 ) ;
F_125 ( 1000 ) ;
if ( F_325 ( V_57 ) )
F_123 ( V_13 , F_11 ( V_13 ) | V_453 |
V_454 ) ;
}
static void F_326 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 , V_455 ;
F_327 ( V_6 , V_95 ) ;
V_13 = F_328 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_456 ;
V_446 &= ~ V_457 ;
F_123 ( V_13 , V_446 ) ;
F_11 ( V_13 ) ;
F_125 ( 150 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_458 ;
V_446 |= F_329 ( V_81 -> V_91 -> V_459 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
F_123 ( V_13 , V_446 | V_110 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
F_123 ( V_13 , V_446 | V_111 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
F_123 ( F_330 ( V_95 ) , V_461 ) ;
F_123 ( F_330 ( V_95 ) , V_461 |
V_462 ) ;
V_13 = F_331 ( V_95 ) ;
for ( V_455 = 0 ; V_455 < 5 ; V_455 ++ ) {
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( ( V_446 & V_457 ) ) {
F_158 ( L_61 ) ;
F_123 ( V_13 , V_446 | V_457 ) ;
break;
}
}
if ( V_455 == 5 )
F_126 ( L_62 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_463 ;
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_463 ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
V_13 = F_331 ( V_95 ) ;
for ( V_455 = 0 ; V_455 < 5 ; V_455 ++ ) {
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( V_446 & V_456 ) {
F_123 ( V_13 , V_446 | V_456 ) ;
F_158 ( L_63 ) ;
break;
}
}
if ( V_455 == 5 )
F_126 ( L_64 ) ;
F_158 ( L_65 ) ;
}
static void F_332 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 , V_139 , V_464 ;
V_13 = F_328 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_456 ;
V_446 &= ~ V_457 ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_458 ;
V_446 |= F_329 ( V_81 -> V_91 -> V_459 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
V_446 &= ~ V_465 ;
V_446 |= V_466 ;
F_123 ( V_13 , V_446 | V_110 ) ;
F_123 ( F_333 ( V_95 ) ,
V_467 | V_468 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( F_105 ( V_57 ) ) {
V_446 &= ~ V_450 ;
V_446 |= V_469 ;
} else {
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
}
F_123 ( V_13 , V_446 | V_111 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_465 ;
V_446 |= V_470 [ V_139 ] ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 500 ) ;
for ( V_464 = 0 ; V_464 < 5 ; V_464 ++ ) {
V_13 = F_331 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( V_446 & V_457 ) {
F_123 ( V_13 , V_446 | V_457 ) ;
F_158 ( L_61 ) ;
break;
}
F_125 ( 50 ) ;
}
if ( V_464 < 5 )
break;
}
if ( V_139 == 4 )
F_126 ( L_62 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_463 ;
if ( F_334 ( V_57 ) ) {
V_446 &= ~ V_465 ;
V_446 |= V_466 ;
}
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( F_105 ( V_57 ) ) {
V_446 &= ~ V_450 ;
V_446 |= V_471 ;
} else {
V_446 &= ~ V_449 ;
V_446 |= V_463 ;
}
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_465 ;
V_446 |= V_470 [ V_139 ] ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 500 ) ;
for ( V_464 = 0 ; V_464 < 5 ; V_464 ++ ) {
V_13 = F_331 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( V_446 & V_456 ) {
F_123 ( V_13 , V_446 | V_456 ) ;
F_158 ( L_63 ) ;
break;
}
F_125 ( 50 ) ;
}
if ( V_464 < 5 )
break;
}
if ( V_139 == 4 )
F_126 ( L_64 ) ;
F_158 ( L_66 ) ;
}
static void F_335 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 , V_139 , V_472 ;
V_13 = F_328 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_456 ;
V_446 &= ~ V_457 ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 150 ) ;
F_158 ( L_67 ,
F_11 ( F_331 ( V_95 ) ) ) ;
for ( V_472 = 0 ; V_472 < F_177 ( V_470 ) * 2 ; V_472 ++ ) {
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ ( V_473 | V_447 ) ;
V_446 &= ~ V_110 ;
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_473 ;
V_446 &= ~ V_450 ;
V_446 &= ~ V_111 ;
F_123 ( V_13 , V_446 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_458 ;
V_446 |= F_329 ( V_81 -> V_91 -> V_459 ) ;
V_446 |= V_474 ;
V_446 &= ~ V_465 ;
V_446 |= V_470 [ V_472 / 2 ] ;
V_446 |= V_475 ;
F_123 ( V_13 , V_446 | V_110 ) ;
F_123 ( F_333 ( V_95 ) ,
V_467 | V_468 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 |= V_469 ;
V_446 |= V_475 ;
F_123 ( V_13 , V_446 | V_111 ) ;
F_124 ( V_13 ) ;
F_125 ( 1 ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
V_13 = F_331 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( V_446 & V_457 ||
( F_11 ( V_13 ) & V_457 ) ) {
F_123 ( V_13 , V_446 | V_457 ) ;
F_158 ( L_68 ,
V_139 ) ;
break;
}
F_125 ( 1 ) ;
}
if ( V_139 == 4 ) {
F_158 ( L_69 , V_472 / 2 ) ;
continue;
}
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_447 ;
V_446 |= V_476 ;
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_450 ;
V_446 |= V_471 ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 2 ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
V_13 = F_331 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_158 ( L_60 , V_446 ) ;
if ( V_446 & V_456 ||
( F_11 ( V_13 ) & V_456 ) ) {
F_123 ( V_13 , V_446 | V_456 ) ;
F_158 ( L_70 ,
V_139 ) ;
goto V_477;
}
F_125 ( 2 ) ;
}
if ( V_139 == 4 )
F_158 ( L_71 , V_472 / 2 ) ;
}
V_477:
F_158 ( L_66 ) ;
}
static void F_336 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ ( V_458 | ( 0x7 << 16 ) ) ;
V_446 |= F_329 ( V_81 -> V_91 -> V_459 ) ;
V_446 |= ( F_11 ( F_59 ( V_95 ) ) & V_210 ) << 11 ;
F_123 ( V_13 , V_446 | V_113 ) ;
F_124 ( V_13 ) ;
F_125 ( 200 ) ;
V_446 = F_11 ( V_13 ) ;
F_123 ( V_13 , V_446 | V_478 ) ;
F_124 ( V_13 ) ;
F_125 ( 200 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( ( V_446 & V_112 ) == 0 ) {
F_123 ( V_13 , V_446 | V_112 ) ;
F_124 ( V_13 ) ;
F_125 ( 100 ) ;
}
}
static void F_337 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_123 ( V_13 , V_446 & ~ V_478 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_123 ( V_13 , V_446 & ~ V_112 ) ;
F_124 ( V_13 ) ;
F_125 ( 100 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_123 ( V_13 , V_446 & ~ V_113 ) ;
F_124 ( V_13 ) ;
F_125 ( 100 ) ;
}
static void F_338 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_3 V_13 ;
T_1 V_446 ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
F_123 ( V_13 , V_446 & ~ V_110 ) ;
F_124 ( V_13 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ ( 0x7 << 16 ) ;
V_446 |= ( F_11 ( F_59 ( V_95 ) ) & V_210 ) << 11 ;
F_123 ( V_13 , V_446 & ~ V_111 ) ;
F_124 ( V_13 ) ;
F_125 ( 100 ) ;
if ( F_119 ( V_57 ) )
F_123 ( F_330 ( V_95 ) , V_461 ) ;
V_13 = F_69 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
F_123 ( V_13 , V_446 ) ;
V_13 = F_71 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
if ( F_105 ( V_57 ) ) {
V_446 &= ~ V_450 ;
V_446 |= V_469 ;
} else {
V_446 &= ~ V_449 ;
V_446 |= V_460 ;
}
V_446 &= ~ ( 0x07 << 16 ) ;
V_446 |= ( F_11 ( F_59 ( V_95 ) ) & V_210 ) << 11 ;
F_123 ( V_13 , V_446 ) ;
F_124 ( V_13 ) ;
F_125 ( 100 ) ;
}
bool F_339 ( struct V_56 * V_57 )
{
struct V_81 * V_65 ;
F_137 (dev, crtc) {
if ( F_340 ( & V_65 -> V_479 ) == 0 )
continue;
if ( V_65 -> V_443 )
F_341 ( V_57 , V_65 -> V_95 ) ;
return true ;
}
return false ;
}
static void F_342 ( struct V_81 * V_81 )
{
struct V_5 * V_6 = F_53 ( V_81 -> V_64 . V_57 ) ;
struct V_1 * V_2 = V_81 -> V_443 ;
V_81 -> V_443 = NULL ;
if ( V_2 -> V_480 )
F_343 ( & V_81 -> V_64 , V_2 -> V_480 ) ;
F_101 ( & V_81 -> V_64 ) ;
F_344 ( & V_6 -> V_481 ) ;
F_345 ( V_6 -> V_482 , & V_2 -> V_483 ) ;
F_346 ( V_81 -> V_137 ,
V_2 -> V_484 ) ;
}
static int F_347 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
long V_362 ;
F_28 ( F_348 ( & V_6 -> V_481 ) ) ;
V_362 = F_349 (
V_6 -> V_481 ,
! F_318 ( V_65 ) ,
60 * V_485 ) ;
if ( V_362 < 0 )
return V_362 ;
if ( V_362 == 0 ) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
F_310 ( & V_57 -> V_442 ) ;
V_2 = V_81 -> V_443 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_350 ( 1 , L_72 ) ;
F_342 ( V_81 ) ;
}
F_311 ( & V_57 -> V_442 ) ;
}
return 0 ;
}
void F_351 ( struct V_5 * V_6 )
{
T_1 V_446 ;
F_123 ( V_486 , V_487 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_446 = F_352 ( V_6 , V_488 , V_489 ) ;
V_446 |= V_490 ;
F_353 ( V_6 , V_488 , V_446 , V_489 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_354 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
int clock = F_47 ( V_65 ) -> V_91 -> V_64 . V_92 . V_93 ;
T_1 V_491 , V_492 , V_493 , V_494 = 0 ;
T_1 V_446 ;
F_351 ( V_6 ) ;
for ( V_493 = 0 ; V_493 < 2 ; V_493 ++ ) {
T_1 V_495 = 172800 * 1000 ;
T_1 V_496 = 64 ;
T_1 V_497 ;
V_497 = F_8 ( V_495 ,
clock << V_493 ) ;
V_491 = ( V_497 / V_496 ) - 2 ;
V_492 = V_497 % V_496 ;
if ( V_491 <= 0x7f )
break;
}
F_28 ( F_355 ( V_491 ) &
~ V_498 ) ;
F_28 ( F_356 ( V_494 ) &
~ V_499 ) ;
F_158 ( L_73 ,
clock ,
V_493 ,
V_491 ,
V_494 ,
V_492 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_446 = F_352 ( V_6 , V_500 , V_489 ) ;
V_446 &= ~ V_498 ;
V_446 |= F_355 ( V_491 ) ;
V_446 &= ~ V_499 ;
V_446 |= F_357 ( V_492 ) ;
V_446 |= F_356 ( V_494 ) ;
V_446 |= V_501 ;
F_353 ( V_6 , V_500 , V_446 , V_489 ) ;
V_446 = F_352 ( V_6 , V_502 , V_489 ) ;
V_446 &= ~ F_358 ( 1 ) ;
V_446 |= F_358 ( V_493 ) ;
F_353 ( V_6 , V_502 , V_446 , V_489 ) ;
V_446 = F_352 ( V_6 , V_488 , V_489 ) ;
V_446 &= ~ V_490 ;
F_353 ( V_6 , V_488 , V_446 , V_489 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_125 ( 24 ) ;
F_123 ( V_486 , V_503 ) ;
}
int F_359 ( struct V_5 * V_6 )
{
T_1 V_491 , V_492 , V_493 ;
T_1 V_495 = 172800 * 1000 ;
T_1 V_496 = 64 ;
T_1 V_497 ;
T_1 V_446 ;
if ( ( F_11 ( V_486 ) & V_503 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_446 = F_352 ( V_6 , V_488 , V_489 ) ;
if ( V_446 & V_490 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_446 = F_352 ( V_6 , V_500 , V_489 ) ;
V_491 = ( V_446 & V_498 ) >>
V_504 ;
V_492 = ( V_446 & V_499 ) >>
V_505 ;
V_446 = F_352 ( V_6 , V_502 , V_489 ) ;
V_493 = ( V_446 & V_506 ) >>
V_507 ;
F_5 ( & V_6 -> V_9 ) ;
V_497 = ( V_491 + 2 ) * V_496 + V_492 ;
return F_8 ( V_495 ,
V_497 << V_493 ) ;
}
static void F_360 ( struct V_81 * V_65 ,
enum V_95 V_224 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
F_123 ( F_361 ( V_224 ) ,
F_11 ( F_362 ( V_97 ) ) ) ;
F_123 ( F_363 ( V_224 ) ,
F_11 ( F_364 ( V_97 ) ) ) ;
F_123 ( F_365 ( V_224 ) ,
F_11 ( F_366 ( V_97 ) ) ) ;
F_123 ( F_367 ( V_224 ) ,
F_11 ( F_368 ( V_97 ) ) ) ;
F_123 ( F_369 ( V_224 ) ,
F_11 ( F_370 ( V_97 ) ) ) ;
F_123 ( F_371 ( V_224 ) ,
F_11 ( F_372 ( V_97 ) ) ) ;
F_123 ( F_373 ( V_224 ) ,
F_11 ( F_374 ( V_97 ) ) ) ;
}
static void F_375 ( struct V_56 * V_57 , bool V_508 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_446 ;
V_446 = F_11 ( V_509 ) ;
if ( ! ! ( V_446 & V_510 ) == V_508 )
return;
F_28 ( F_11 ( F_71 ( V_124 ) ) & V_111 ) ;
F_28 ( F_11 ( F_71 ( V_511 ) ) & V_111 ) ;
V_446 &= ~ V_510 ;
if ( V_508 )
V_446 |= V_510 ;
F_158 ( L_74 , V_508 ? L_75 : L_76 ) ;
F_123 ( V_509 , V_446 ) ;
F_124 ( V_509 ) ;
}
static void F_376 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
switch ( V_81 -> V_95 ) {
case V_117 :
break;
case V_124 :
if ( V_81 -> V_91 -> V_459 > 2 )
F_375 ( V_57 , false ) ;
else
F_375 ( V_57 , true ) ;
break;
case V_511 :
F_375 ( V_57 , true ) ;
break;
default:
F_145 () ;
}
}
static enum V_180
F_377 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_512 * V_513 ;
F_378 (dev, crtc, encoder) {
if ( V_513 -> type == V_514 ||
V_513 -> type == V_515 )
return F_379 ( & V_513 -> V_64 ) -> V_180 ;
}
return - 1 ;
}
static void F_380 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_1 V_446 ;
F_102 ( V_6 , V_95 ) ;
if ( F_325 ( V_57 ) )
F_376 ( V_81 ) ;
F_123 ( F_381 ( V_95 ) ,
F_11 ( F_382 ( V_95 ) ) & V_516 ) ;
V_6 -> V_436 . V_517 ( V_65 ) ;
if ( F_105 ( V_57 ) ) {
T_1 V_518 ;
V_446 = F_11 ( V_519 ) ;
V_446 |= F_383 ( V_95 ) ;
V_518 = F_384 ( V_95 ) ;
if ( V_81 -> V_91 -> V_208 ==
F_385 ( V_6 , V_520 ) )
V_446 |= V_518 ;
else
V_446 &= ~ V_518 ;
F_123 ( V_519 , V_446 ) ;
}
F_386 ( V_81 ) ;
F_74 ( V_6 , V_95 ) ;
F_360 ( V_81 , V_95 ) ;
F_324 ( V_65 ) ;
if ( F_105 ( V_57 ) && F_387 ( V_81 -> V_91 ) ) {
const struct V_521 * V_92 =
& V_81 -> V_91 -> V_64 . V_92 ;
T_1 V_522 = ( F_11 ( F_59 ( V_95 ) ) & V_210 ) >> 5 ;
T_3 V_13 = F_106 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ ( V_152 |
V_523 |
V_524 ) ;
V_446 |= V_525 ;
V_446 |= V_522 << 9 ;
if ( V_92 -> V_330 & V_526 )
V_446 |= V_527 ;
if ( V_92 -> V_330 & V_528 )
V_446 |= V_529 ;
switch ( F_377 ( V_65 ) ) {
case V_200 :
V_446 |= V_167 ;
break;
case V_202 :
V_446 |= V_169 ;
break;
case V_204 :
V_446 |= V_171 ;
break;
default:
F_145 () ;
}
F_123 ( V_13 , V_446 ) ;
}
F_147 ( V_6 , V_95 ) ;
}
static void F_388 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
F_102 ( V_6 , V_221 ) ;
F_354 ( V_65 ) ;
F_360 ( V_81 , V_117 ) ;
F_152 ( V_6 , V_97 ) ;
}
static void F_389 ( struct V_56 * V_57 , int V_95 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_530 = F_54 ( V_95 ) ;
T_1 V_446 ;
V_446 = F_11 ( V_530 ) ;
F_125 ( 500 ) ;
if ( F_61 ( F_11 ( V_530 ) != V_446 , 5 ) ) {
if ( F_61 ( F_11 ( V_530 ) != V_446 , 5 ) )
F_126 ( L_77 , F_77 ( V_95 ) ) ;
}
}
static int
F_390 ( struct V_37 * V_62 , bool V_531 ,
unsigned V_532 , int * V_407 , unsigned int V_249 ,
int V_345 , int V_346 , int V_410 , int V_411 )
{
struct V_378 * V_379 =
& V_62 -> V_379 ;
struct V_81 * V_81 =
F_47 ( V_62 -> V_64 . V_65 ) ;
int V_533 ;
V_533 = F_179 ( V_249 ) ?
( V_346 != V_410 || V_345 != V_411 ) :
( V_345 != V_410 || V_346 != V_411 ) ;
if ( V_531 || ! V_533 ) {
if ( * V_407 >= 0 ) {
V_379 -> V_534 &= ~ ( 1 << V_532 ) ;
V_379 -> V_381 [ * V_407 ] . V_382 = 0 ;
F_158 ( L_78
L_79 ,
V_81 -> V_95 , V_532 , * V_407 ,
V_379 -> V_534 ) ;
* V_407 = - 1 ;
}
return 0 ;
}
if ( V_345 < V_535 || V_346 < V_536 ||
V_410 < V_537 || V_411 < V_538 ||
V_345 > V_539 || V_346 > V_540 ||
V_410 > V_541 || V_411 > V_542 ) {
F_158 ( L_80
L_81 ,
V_81 -> V_95 , V_532 , V_345 , V_346 , V_410 , V_411 ) ;
return - V_288 ;
}
V_379 -> V_534 |= ( 1 << V_532 ) ;
F_158 ( L_78
L_82 ,
V_81 -> V_95 , V_532 , V_345 , V_346 , V_410 , V_411 ,
V_379 -> V_534 ) ;
return 0 ;
}
int F_391 ( struct V_37 * V_43 )
{
struct V_81 * V_81 = F_47 ( V_43 -> V_64 . V_65 ) ;
const struct V_521 * V_92 = & V_43 -> V_64 . V_92 ;
F_158 ( L_83 ,
V_81 -> V_64 . V_64 . V_377 , V_81 -> V_64 . V_12 ,
V_81 -> V_95 , V_543 ) ;
return F_390 ( V_43 , ! V_43 -> V_64 . V_88 , V_543 ,
& V_43 -> V_379 . V_407 , V_289 ,
V_43 -> V_367 , V_43 -> V_366 ,
V_92 -> V_544 , V_92 -> V_545 ) ;
}
static int F_392 ( struct V_37 * V_62 ,
struct V_265 * V_336 )
{
struct V_81 * V_81 = F_47 ( V_62 -> V_64 . V_65 ) ;
struct V_337 * V_337 =
F_230 ( V_336 -> V_64 . V_137 ) ;
struct V_248 * V_90 = V_336 -> V_64 . V_90 ;
int V_362 ;
bool V_531 = ! V_90 || ! V_336 -> V_64 . V_340 ;
F_158 ( L_84 ,
V_337 -> V_64 . V_64 . V_377 , V_337 -> V_64 . V_12 ,
V_81 -> V_95 , F_235 ( & V_337 -> V_64 ) ) ;
V_362 = F_390 ( V_62 , V_531 ,
F_235 ( & V_337 -> V_64 ) ,
& V_336 -> V_407 ,
V_336 -> V_64 . V_249 ,
F_240 ( & V_336 -> V_64 . V_351 ) >> 16 ,
F_241 ( & V_336 -> V_64 . V_351 ) >> 16 ,
F_240 ( & V_336 -> V_64 . V_352 ) ,
F_241 ( & V_336 -> V_64 . V_352 ) ) ;
if ( V_362 || V_336 -> V_407 < 0 )
return V_362 ;
if ( V_336 -> V_546 . V_330 != V_547 ) {
F_158 ( L_85 ,
V_337 -> V_64 . V_64 . V_377 ,
V_337 -> V_64 . V_12 ) ;
return - V_288 ;
}
switch ( V_90 -> V_241 ) {
case V_302 :
case V_306 :
case V_304 :
case V_315 :
case V_316 :
case V_308 :
case V_310 :
case V_386 :
case V_389 :
case V_391 :
case V_393 :
break;
default:
F_158 ( L_86 ,
V_337 -> V_64 . V_64 . V_377 , V_337 -> V_64 . V_12 ,
V_90 -> V_64 . V_377 , V_90 -> V_241 ) ;
return - V_288 ;
}
return 0 ;
}
static void F_393 ( struct V_81 * V_65 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_65 -> V_380 ; V_139 ++ )
F_264 ( V_65 , V_139 ) ;
}
static void F_321 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
struct V_378 * V_379 =
& V_65 -> V_91 -> V_379 ;
F_158 ( L_87 , V_65 -> V_91 ) ;
if ( V_65 -> V_91 -> V_445 . V_148 ) {
int V_377 ;
if ( F_28 ( V_65 -> V_91 -> V_379 . V_407 < 0 ) ) {
F_126 ( L_88 ) ;
return;
}
V_377 = V_379 -> V_407 ;
F_123 ( F_265 ( V_95 , V_377 ) , V_417 |
V_548 | V_379 -> V_381 [ V_377 ] . V_418 ) ;
F_123 ( F_266 ( V_95 , V_377 ) , V_65 -> V_91 -> V_445 . V_549 ) ;
F_123 ( F_267 ( V_95 , V_377 ) , V_65 -> V_91 -> V_445 . V_244 ) ;
F_158 ( L_89 , V_65 -> V_91 , V_377 ) ;
}
}
static void F_322 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
if ( V_65 -> V_91 -> V_445 . V_148 ) {
if ( F_325 ( V_57 ) || F_259 ( V_57 ) )
F_123 ( F_394 ( V_95 ) , V_550 | V_551 |
F_395 ( V_95 ) ) ;
else
F_123 ( F_394 ( V_95 ) , V_550 | V_551 ) ;
F_123 ( F_396 ( V_95 ) , V_65 -> V_91 -> V_445 . V_549 ) ;
F_123 ( F_397 ( V_95 ) , V_65 -> V_91 -> V_445 . V_244 ) ;
}
}
void F_398 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_552 )
return;
F_399 ( V_6 , V_65 -> V_137 ) ;
if ( F_260 ( V_57 ) ) {
F_3 ( & V_6 -> V_553 . V_554 ) ;
F_28 ( F_400 ( V_6 , V_555 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
} else {
F_123 ( V_556 , V_557 ) ;
if ( F_60 ( V_6 ,
V_556 , V_557 , V_557 ,
50 ) )
F_126 ( L_90 ) ;
}
}
void F_401 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_552 )
return;
F_399 ( V_6 , V_65 -> V_137 ) ;
if ( F_260 ( V_57 ) ) {
F_3 ( & V_6 -> V_553 . V_554 ) ;
F_28 ( F_400 ( V_6 , V_555 , 0 ) ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
if ( F_60 ( V_6 ,
V_556 , V_557 , 0 ,
42 ) )
F_126 ( L_91 ) ;
} else {
F_123 ( V_556 , 0 ) ;
F_124 ( V_556 ) ;
}
F_341 ( V_57 , V_65 -> V_95 ) ;
}
static void F_402 ( struct V_81 * V_81 )
{
if ( V_81 -> V_558 ) {
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_3 ( & V_57 -> V_259 ) ;
V_6 -> V_559 . V_560 = false ;
( void ) F_403 ( V_81 -> V_558 ) ;
V_6 -> V_559 . V_560 = true ;
F_5 ( & V_57 -> V_259 ) ;
}
}
static void
F_404 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
F_398 ( V_81 ) ;
if ( F_55 ( V_57 ) )
F_405 ( V_6 , V_95 , true ) ;
F_406 ( V_6 ) ;
F_407 ( V_6 ) ;
}
static void
F_408 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_55 ( V_57 ) )
F_405 ( V_6 , V_95 , false ) ;
F_401 ( V_81 ) ;
}
static void
F_236 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
F_408 ( V_65 ) ;
if ( F_161 ( V_57 ) ) {
F_409 ( V_6 , false ) ;
V_6 -> V_403 . V_561 . V_562 = false ;
F_341 ( V_57 , V_95 ) ;
}
}
static void F_410 ( struct V_37 * V_444 )
{
struct V_81 * V_65 = F_47 ( V_444 -> V_64 . V_65 ) ;
struct V_422 * V_563 = V_444 -> V_64 . V_43 ;
struct V_37 * V_38 =
F_288 ( V_65 -> V_64 . V_43 ) ;
struct V_333 * V_89 = V_65 -> V_64 . V_89 ;
struct V_335 * V_564 =
F_411 ( V_563 , V_89 ) ;
F_412 ( F_53 ( V_65 -> V_64 . V_57 ) , V_38 -> V_565 ) ;
V_65 -> V_403 . V_566 = true ;
if ( V_38 -> V_567 && V_38 -> V_64 . V_88 )
F_413 ( & V_65 -> V_64 ) ;
if ( V_564 ) {
struct V_265 * V_568 =
F_231 ( V_89 -> V_43 ) ;
struct V_265 * V_569 =
F_231 ( V_564 ) ;
F_414 ( V_65 ) ;
if ( V_568 -> V_64 . V_340 &&
( F_25 ( & V_38 -> V_64 ) ||
! V_569 -> V_64 . V_340 ) )
F_404 ( & V_65 -> V_64 ) ;
}
}
static void F_415 ( struct V_37 * V_444 )
{
struct V_81 * V_65 = F_47 ( V_444 -> V_64 . V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 =
F_288 ( V_65 -> V_64 . V_43 ) ;
struct V_422 * V_563 = V_444 -> V_64 . V_43 ;
struct V_333 * V_89 = V_65 -> V_64 . V_89 ;
struct V_335 * V_564 =
F_411 ( V_563 , V_89 ) ;
bool V_570 = F_25 ( & V_38 -> V_64 ) ;
if ( V_564 ) {
struct V_265 * V_568 =
F_231 ( V_89 -> V_43 ) ;
struct V_265 * V_569 =
F_231 ( V_564 ) ;
F_416 ( V_65 , V_38 , V_568 ) ;
if ( V_569 -> V_64 . V_340 &&
( V_570 || ! V_568 -> V_64 . V_340 ) )
F_408 ( & V_65 -> V_64 ) ;
}
if ( V_38 -> V_571 && F_161 ( V_57 ) ) {
V_65 -> V_403 . V_566 = false ;
if ( V_444 -> V_64 . V_88 ) {
F_409 ( V_6 , false ) ;
V_6 -> V_403 . V_561 . V_562 = false ;
F_341 ( V_57 , V_65 -> V_95 ) ;
}
}
if ( V_38 -> V_572 ) {
F_417 ( V_57 ) ;
F_341 ( V_57 , V_65 -> V_95 ) ;
}
if ( F_25 ( & V_38 -> V_64 ) )
return;
if ( V_6 -> V_436 . V_573 != NULL )
V_6 -> V_436 . V_573 ( V_38 ) ;
else if ( V_38 -> V_574 )
F_413 ( & V_65 -> V_64 ) ;
}
static void F_418 ( struct V_87 * V_65 , unsigned V_341 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_333 * V_48 ;
int V_95 = V_81 -> V_95 ;
F_402 ( V_81 ) ;
F_419 (p, dev, plane_mask)
F_230 ( V_48 ) -> V_342 ( V_48 , V_65 ) ;
F_412 ( F_53 ( V_57 ) , F_420 ( V_95 ) ) ;
}
static void F_421 ( struct V_87 * V_65 ,
struct V_37 * V_62 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_512 * V_513 =
F_423 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
if ( V_513 -> V_581 )
V_513 -> V_581 ( V_513 , V_62 , V_579 ) ;
}
}
static void F_424 ( struct V_87 * V_65 ,
struct V_37 * V_62 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_512 * V_513 =
F_423 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
if ( V_513 -> V_582 )
V_513 -> V_582 ( V_513 , V_62 , V_579 ) ;
}
}
static void F_425 ( struct V_87 * V_65 ,
struct V_37 * V_62 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_575 * V_579 = V_578 -> V_43 ;
struct V_512 * V_513 =
F_423 ( V_579 -> V_580 ) ;
if ( V_579 -> V_65 != V_65 )
continue;
V_513 -> V_508 ( V_513 , V_62 , V_579 ) ;
F_426 ( V_513 , true ) ;
}
}
static void F_427 ( struct V_87 * V_65 ,
struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_512 * V_513 =
F_423 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
F_426 ( V_513 , false ) ;
V_513 -> V_583 ( V_513 , V_444 , V_576 ) ;
}
}
static void F_428 ( struct V_87 * V_65 ,
struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_512 * V_513 =
F_423 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
if ( V_513 -> V_584 )
V_513 -> V_584 ( V_513 , V_444 , V_576 ) ;
}
}
static void F_429 ( struct V_87 * V_65 ,
struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_575 * V_576 ;
struct V_577 * V_578 ;
int V_139 ;
F_422 (old_state, conn, old_conn_state, i) {
struct V_512 * V_513 =
F_423 ( V_576 -> V_580 ) ;
if ( V_576 -> V_65 != V_65 )
continue;
if ( V_513 -> V_585 )
V_513 -> V_585 ( V_513 , V_444 , V_576 ) ;
}
}
static void F_430 ( struct V_37 * V_38 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_38 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( V_81 -> V_91 -> V_226 || F_24 ( V_6 ) )
F_405 ( V_6 , V_95 , false ) ;
if ( V_81 -> V_91 -> V_226 )
F_431 ( V_6 , V_95 , false ) ;
if ( V_81 -> V_91 -> V_226 )
F_432 ( V_81 ) ;
if ( F_387 ( V_81 -> V_91 ) )
F_433 ( V_81 , V_586 ) ;
F_434 ( V_81 ) ;
F_435 ( V_81 ) ;
if ( V_81 -> V_91 -> V_226 ) {
F_436 ( V_81 ,
& V_81 -> V_91 -> V_587 , NULL ) ;
}
F_437 ( V_65 ) ;
V_81 -> V_88 = true ;
F_424 ( V_65 , V_38 , V_563 ) ;
if ( V_81 -> V_91 -> V_226 ) {
F_336 ( V_81 ) ;
} else {
F_154 ( V_6 , V_95 ) ;
F_155 ( V_6 , V_95 ) ;
}
F_322 ( V_81 ) ;
F_438 ( & V_38 -> V_64 ) ;
if ( V_6 -> V_436 . V_573 != NULL )
V_6 -> V_436 . V_573 ( V_81 -> V_91 ) ;
F_157 ( V_81 ) ;
if ( V_81 -> V_91 -> V_226 )
F_380 ( V_65 ) ;
F_98 ( V_65 ) ;
F_439 ( V_65 ) ;
F_425 ( V_65 , V_38 , V_563 ) ;
if ( F_105 ( V_57 ) )
F_389 ( V_57 , V_81 -> V_95 ) ;
if ( V_81 -> V_91 -> V_226 )
F_341 ( V_57 , V_95 ) ;
F_405 ( V_6 , V_95 , true ) ;
F_431 ( V_6 , V_95 , true ) ;
}
static bool F_440 ( struct V_81 * V_65 )
{
return F_441 ( V_65 -> V_64 . V_57 ) && V_65 -> V_95 == V_117 ;
}
static void F_442 ( struct V_37 * V_38 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_38 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 , V_588 ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( V_81 -> V_91 -> V_226 )
F_431 ( V_6 , V_221 ,
false ) ;
F_421 ( V_65 , V_38 , V_563 ) ;
if ( V_81 -> V_91 -> V_208 )
F_386 ( V_81 ) ;
if ( F_387 ( V_81 -> V_91 ) )
F_433 ( V_81 , V_586 ) ;
if ( ! F_443 ( V_97 ) )
F_434 ( V_81 ) ;
F_435 ( V_81 ) ;
if ( V_97 != V_589 &&
! F_443 ( V_97 ) ) {
F_123 ( F_444 ( V_97 ) ,
V_81 -> V_91 -> V_590 - 1 ) ;
}
if ( V_81 -> V_91 -> V_226 ) {
F_436 ( V_81 ,
& V_81 -> V_91 -> V_587 , NULL ) ;
}
if ( ! F_443 ( V_97 ) )
F_445 ( V_65 ) ;
F_446 ( V_65 ) ;
F_447 ( & V_38 -> V_64 ) ;
V_81 -> V_88 = true ;
if ( V_81 -> V_91 -> V_226 )
F_405 ( V_6 , V_95 , false ) ;
else
F_405 ( V_6 , V_95 , true ) ;
F_424 ( V_65 , V_38 , V_563 ) ;
if ( V_81 -> V_91 -> V_226 )
V_6 -> V_436 . V_517 ( V_65 ) ;
if ( ! F_443 ( V_97 ) )
F_448 ( V_81 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_321 ( V_81 ) ;
else
F_322 ( V_81 ) ;
F_438 ( & V_38 -> V_64 ) ;
F_449 ( V_65 ) ;
if ( ! F_443 ( V_97 ) )
F_450 ( V_65 ) ;
if ( V_6 -> V_436 . V_573 != NULL )
V_6 -> V_436 . V_573 ( V_38 ) ;
else
F_413 ( V_65 ) ;
if ( ! F_443 ( V_97 ) )
F_157 ( V_81 ) ;
if ( V_81 -> V_91 -> V_226 )
F_388 ( V_65 ) ;
if ( V_81 -> V_91 -> V_591 )
F_451 ( V_65 , true ) ;
F_98 ( V_65 ) ;
F_439 ( V_65 ) ;
F_425 ( V_65 , V_38 , V_563 ) ;
if ( V_81 -> V_91 -> V_226 ) {
F_341 ( V_57 , V_95 ) ;
F_341 ( V_57 , V_95 ) ;
F_405 ( V_6 , V_95 , true ) ;
F_431 ( V_6 , V_221 ,
true ) ;
}
V_588 = V_38 -> V_588 ;
if ( F_259 ( V_57 ) && V_588 != V_592 ) {
F_341 ( V_57 , V_588 ) ;
F_341 ( V_57 , V_588 ) ;
}
}
static void F_323 ( struct V_81 * V_65 , bool V_593 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
if ( V_593 || V_65 -> V_91 -> V_445 . V_148 ) {
F_123 ( F_394 ( V_95 ) , 0 ) ;
F_123 ( F_396 ( V_95 ) , 0 ) ;
F_123 ( F_397 ( V_95 ) , 0 ) ;
}
}
static void F_452 ( struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_444 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( V_81 -> V_91 -> V_226 ) {
F_405 ( V_6 , V_95 , false ) ;
F_431 ( V_6 , V_95 , false ) ;
}
F_427 ( V_65 , V_444 , V_563 ) ;
F_453 ( V_65 ) ;
F_98 ( V_65 ) ;
F_166 ( V_81 ) ;
F_323 ( V_81 , false ) ;
if ( V_81 -> V_91 -> V_226 )
F_338 ( V_65 ) ;
F_428 ( V_65 , V_444 , V_563 ) ;
if ( V_81 -> V_91 -> V_226 ) {
F_153 ( V_6 , V_95 ) ;
if ( F_105 ( V_57 ) ) {
T_3 V_13 ;
T_1 V_446 ;
V_13 = F_106 ( V_95 ) ;
V_446 = F_11 ( V_13 ) ;
V_446 &= ~ ( V_525 |
V_152 ) ;
V_446 |= V_594 ;
F_123 ( V_13 , V_446 ) ;
V_446 = F_11 ( V_519 ) ;
V_446 &= ~ ( F_383 ( V_95 ) | F_384 ( V_95 ) ) ;
F_123 ( V_519 , V_446 ) ;
}
F_337 ( V_81 ) ;
}
F_405 ( V_6 , V_95 , true ) ;
F_431 ( V_6 , V_95 , true ) ;
}
static void F_454 ( struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_444 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
if ( V_81 -> V_91 -> V_226 )
F_431 ( V_6 , V_221 ,
false ) ;
F_427 ( V_65 , V_444 , V_563 ) ;
F_453 ( V_65 ) ;
F_98 ( V_65 ) ;
if ( ! F_443 ( V_97 ) )
F_166 ( V_81 ) ;
if ( V_81 -> V_91 -> V_591 )
F_451 ( V_65 , false ) ;
if ( ! F_443 ( V_97 ) )
F_455 ( V_6 , V_97 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_393 ( V_81 ) ;
else
F_323 ( V_81 , false ) ;
if ( ! F_443 ( V_97 ) )
F_456 ( V_81 ) ;
F_428 ( V_65 , V_444 , V_563 ) ;
if ( V_444 -> V_226 )
F_431 ( V_6 , V_221 ,
true ) ;
}
static void F_457 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_38 = V_65 -> V_91 ;
if ( ! V_38 -> V_595 . V_596 )
return;
F_28 ( F_11 ( V_597 ) & V_598 ) ;
F_128 ( V_6 , V_65 -> V_95 ) ;
F_123 ( V_599 , V_38 -> V_595 . V_600 ) ;
F_123 ( V_597 , V_38 -> V_595 . V_596 ) ;
F_123 ( F_458 ( V_65 -> V_95 ) , 0 ) ;
}
static enum V_131 F_459 ( enum V_180 V_180 )
{
switch ( V_180 ) {
case V_601 :
return V_602 ;
case V_200 :
return V_603 ;
case V_202 :
return V_604 ;
case V_204 :
return V_605 ;
case V_606 :
return V_607 ;
default:
F_170 ( V_180 ) ;
return V_608 ;
}
}
static enum V_131 F_460 ( enum V_180 V_180 )
{
switch ( V_180 ) {
case V_601 :
return V_609 ;
case V_200 :
return V_610 ;
case V_202 :
return V_611 ;
case V_204 :
return V_612 ;
case V_606 :
return V_612 ;
default:
F_170 ( V_180 ) ;
return V_609 ;
}
}
enum V_131
F_461 ( struct V_512 * V_512 )
{
struct V_56 * V_57 = V_512 -> V_64 . V_57 ;
struct V_195 * V_613 ;
switch ( V_512 -> type ) {
case V_614 :
F_44 ( ! F_23 ( V_57 ) ) ;
case V_514 :
case V_211 :
case V_515 :
V_613 = F_379 ( & V_512 -> V_64 ) ;
return F_459 ( V_613 -> V_180 ) ;
case V_615 :
V_613 = F_462 ( & V_512 -> V_64 ) -> V_89 ;
return F_459 ( V_613 -> V_180 ) ;
case V_616 :
return V_617 ;
case V_225 :
return V_618 ;
default:
return V_608 ;
}
}
enum V_131
F_463 ( struct V_512 * V_512 )
{
struct V_56 * V_57 = V_512 -> V_64 . V_57 ;
struct V_195 * V_613 ;
switch ( V_512 -> type ) {
case V_614 :
case V_211 :
F_44 ( ! F_23 ( V_57 ) ) ;
case V_514 :
case V_515 :
V_613 = F_379 ( & V_512 -> V_64 ) ;
return F_460 ( V_613 -> V_180 ) ;
case V_615 :
V_613 = F_462 ( & V_512 -> V_64 ) -> V_89 ;
return F_460 ( V_613 -> V_180 ) ;
default:
F_170 ( V_512 -> type ) ;
return V_609 ;
}
}
static unsigned long F_464 ( struct V_87 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_619 * V_513 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
unsigned long V_620 ;
enum V_94 V_94 = V_62 -> V_97 ;
if ( ! V_62 -> V_64 . V_88 )
return 0 ;
V_620 = F_465 ( F_466 ( V_95 ) ) ;
V_620 |= F_465 ( F_83 ( V_94 ) ) ;
if ( V_62 -> V_445 . V_148 ||
V_62 -> V_445 . V_621 )
V_620 |= F_465 ( F_467 ( V_95 ) ) ;
F_468 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_512 * V_512 = F_423 ( V_513 ) ;
V_620 |= F_465 ( F_461 ( V_512 ) ) ;
}
if ( V_62 -> V_208 )
V_620 |= F_465 ( V_622 ) ;
return V_620 ;
}
static unsigned long
F_469 ( struct V_87 * V_65 ,
struct V_37 * V_62 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_131 V_623 ;
unsigned long V_624 , V_625 , V_626 ;
V_626 = V_81 -> V_627 ;
V_81 -> V_627 = V_625 =
F_464 ( V_65 , V_62 ) ;
V_624 = V_625 & ~ V_626 ;
F_470 (domain, domains)
F_471 ( V_6 , V_623 ) ;
return V_626 & ~ V_625 ;
}
static void F_472 ( struct V_5 * V_6 ,
unsigned long V_624 )
{
enum V_131 V_623 ;
F_470 (domain, domains)
F_85 ( V_6 , V_623 ) ;
}
static int F_473 ( struct V_5 * V_6 )
{
int V_628 = V_6 -> V_628 ;
if ( F_58 ( V_6 ) -> V_103 >= 9 ||
F_259 ( V_6 ) || F_260 ( V_6 ) )
return V_628 ;
else if ( F_17 ( V_6 ) )
return V_628 * 95 / 100 ;
else if ( F_58 ( V_6 ) -> V_103 < 4 )
return 2 * V_628 * 90 / 100 ;
else
return V_628 * 90 / 100 ;
}
static void F_474 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( F_475 ( V_57 ) || F_476 ( V_57 ) ) {
T_1 V_59 = F_11 ( V_629 ) & V_630 ;
int V_631 , V_52 ;
V_52 = V_6 -> V_632 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
if ( V_59 == V_633 )
V_631 = 617143 ;
else if ( V_59 == V_634 )
V_631 = 540000 ;
else if ( V_59 == V_635 )
V_631 = 432000 ;
else
V_631 = 308571 ;
V_6 -> V_628 = F_477 ( V_631 , V_52 ) ;
} else if ( F_36 ( V_57 ) ) {
V_6 -> V_628 = 624000 ;
} else if ( F_260 ( V_57 ) ) {
if ( F_11 ( V_636 ) & V_637 )
V_6 -> V_628 = 450000 ;
else if ( F_478 ( V_57 ) )
V_6 -> V_628 = 450000 ;
else if ( F_479 ( V_57 ) )
V_6 -> V_628 = 540000 ;
else
V_6 -> V_628 = 675000 ;
} else if ( F_17 ( V_57 ) ) {
V_6 -> V_628 = 320000 ;
} else if ( F_16 ( V_57 ) ) {
V_6 -> V_628 = 400000 ;
} else {
V_6 -> V_628 = V_6 -> V_638 ;
}
V_6 -> V_639 = F_473 ( V_6 ) ;
F_20 ( L_92 ,
V_6 -> V_628 ) ;
F_20 ( L_93 ,
V_6 -> V_639 ) ;
}
static void F_480 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_638 = V_6 -> V_436 . V_640 ( V_57 ) ;
if ( F_250 ( V_6 ) >= 9 )
F_20 ( L_94 ,
V_6 -> V_638 , V_6 -> V_641 . V_52 ,
V_6 -> V_641 . V_642 ) ;
else
F_20 ( L_95 ,
V_6 -> V_638 ) ;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
F_123 ( V_643 , F_216 ( V_6 -> V_638 , 1000 ) ) ;
}
static int F_481 ( int V_644 )
{
return F_8 ( V_644 - 1000 , 500 ) ;
}
static int F_482 ( struct V_5 * V_6 , int V_644 )
{
int V_645 ;
if ( V_644 == V_6 -> V_641 . V_642 )
return 0 ;
switch ( V_644 ) {
default:
F_170 ( V_644 ) ;
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
static void F_483 ( struct V_5 * V_6 )
{
F_123 ( V_646 , 0 ) ;
if ( F_60 ( V_6 ,
V_646 , V_647 , 0 ,
1 ) )
F_126 ( L_96 ) ;
V_6 -> V_641 . V_52 = 0 ;
}
static void F_484 ( struct V_5 * V_6 , int V_52 )
{
int V_645 = F_8 ( V_52 , V_6 -> V_641 . V_642 ) ;
T_1 V_15 ;
V_15 = F_11 ( V_648 ) ;
V_15 &= ~ V_649 ;
V_15 |= F_485 ( V_645 ) ;
F_123 ( V_648 , V_15 ) ;
F_123 ( V_646 , V_650 ) ;
if ( F_60 ( V_6 ,
V_646 ,
V_647 ,
V_647 ,
1 ) )
F_126 ( L_97 ) ;
V_6 -> V_641 . V_52 = V_52 ;
}
static void F_486 ( struct V_5 * V_6 , int V_644 )
{
T_1 V_15 , V_16 ;
int V_52 , V_362 ;
V_52 = F_482 ( V_6 , V_644 ) ;
F_20 ( L_98 , V_644 , V_52 ) ;
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
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_362 = F_400 ( V_6 , V_655 ,
0x80000000 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
if ( V_362 ) {
F_126 ( L_99 ,
V_362 , V_644 ) ;
return;
}
if ( V_6 -> V_641 . V_52 != 0 &&
V_6 -> V_641 . V_52 != V_52 )
F_483 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 != V_52 )
F_484 ( V_6 , V_52 ) ;
V_15 = V_16 | F_481 ( V_644 ) ;
V_15 |= V_656 ;
if ( V_644 >= 500000 )
V_15 |= V_657 ;
F_123 ( V_658 , V_15 ) ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_362 = F_400 ( V_6 , V_655 ,
F_216 ( V_644 , 25000 ) ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
if ( V_362 ) {
F_126 ( L_100 ,
V_362 , V_644 ) ;
return;
}
F_480 ( & V_6 -> V_114 ) ;
}
static void F_487 ( struct V_5 * V_6 )
{
T_1 V_659 , V_660 ;
F_480 ( & V_6 -> V_114 ) ;
if ( V_6 -> V_641 . V_52 == 0 ||
V_6 -> V_638 == V_6 -> V_641 . V_642 )
goto V_661;
V_659 = F_11 ( V_658 ) ;
V_659 &= ~ V_656 ;
V_660 = ( V_659 & V_662 ) |
F_481 ( V_6 -> V_638 ) ;
if ( V_6 -> V_638 >= 500000 )
V_660 |= V_657 ;
if ( V_659 == V_660 )
return;
V_661:
F_158 ( L_101 ) ;
V_6 -> V_638 = 0 ;
V_6 -> V_641 . V_52 = - 1 ;
}
void F_488 ( struct V_5 * V_6 )
{
F_487 ( V_6 ) ;
if ( V_6 -> V_638 != 0 && V_6 -> V_641 . V_52 != 0 )
return;
F_486 ( V_6 , F_489 ( 0 ) ) ;
}
void F_490 ( struct V_5 * V_6 )
{
F_486 ( V_6 , V_6 -> V_641 . V_642 ) ;
}
static int F_477 ( int V_663 , int V_52 )
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
F_491 ( struct V_5 * V_6 )
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
if ( F_28 ( ( V_15 & ( F_492 ( V_668 ) |
F_493 ( V_668 ) |
F_494 ( V_668 ) ) ) !=
F_494 ( V_668 ) ) )
return;
switch ( V_15 & F_495 ( V_668 ) ) {
case F_496 ( V_669 , V_668 ) :
case F_496 ( V_670 , V_668 ) :
case F_496 ( V_671 , V_668 ) :
case F_496 ( V_672 , V_668 ) :
V_6 -> V_641 . V_52 = 8100000 ;
break;
case F_496 ( V_673 , V_668 ) :
case F_496 ( V_674 , V_668 ) :
V_6 -> V_641 . V_52 = 8640000 ;
break;
default:
F_170 ( V_15 & F_495 ( V_668 ) ) ;
break;
}
}
void F_497 ( struct V_5 * V_6 , int V_52 )
{
bool V_675 = V_6 -> V_632 != V_52 ;
V_6 -> V_632 = V_52 ;
if ( V_675 )
F_474 ( & V_6 -> V_114 ) ;
}
static void
F_498 ( struct V_5 * V_6 , int V_52 )
{
int V_676 = F_477 ( 0 , V_52 ) ;
T_1 V_15 ;
F_28 ( V_52 != 8100000 && V_52 != 8640000 ) ;
V_15 = V_677 | F_481 ( V_676 ) ;
F_123 ( V_658 , V_15 ) ;
F_124 ( V_658 ) ;
V_15 = F_11 ( V_667 ) ;
V_15 &= ~ ( F_492 ( V_668 ) | F_493 ( V_668 ) |
F_495 ( V_668 ) ) ;
V_15 |= F_494 ( V_668 ) ;
if ( V_52 == 8640000 )
V_15 |= F_496 ( V_673 ,
V_668 ) ;
else
V_15 |= F_496 ( V_669 ,
V_668 ) ;
F_123 ( V_667 , V_15 ) ;
F_124 ( V_667 ) ;
F_123 ( V_664 , F_11 ( V_664 ) | V_665 ) ;
if ( F_60 ( V_6 ,
V_664 , V_666 , V_666 ,
5 ) )
F_126 ( L_102 ) ;
V_6 -> V_641 . V_52 = V_52 ;
F_497 ( V_6 , V_52 ) ;
}
static void
F_499 ( struct V_5 * V_6 )
{
F_123 ( V_664 , F_11 ( V_664 ) & ~ V_665 ) ;
if ( F_60 ( V_6 ,
V_664 , V_666 , 0 ,
1 ) )
F_126 ( L_103 ) ;
V_6 -> V_641 . V_52 = 0 ;
}
static bool F_500 ( struct V_5 * V_6 )
{
int V_362 ;
T_1 V_15 ;
V_15 = V_678 ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_362 = F_501 ( V_6 , V_679 , & V_15 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
return V_362 == 0 && ( V_15 & V_680 ) ;
}
static bool F_502 ( struct V_5 * V_6 )
{
return F_503 ( F_500 ( V_6 ) , 3000 , 10 ) == 0 ;
}
static void F_504 ( struct V_5 * V_6 , int V_644 , int V_52 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_1 V_681 , V_682 ;
F_28 ( ( V_644 == 24000 ) != ( V_52 == 0 ) ) ;
F_20 ( L_98 , V_644 , V_52 ) ;
if ( ! F_502 ( V_6 ) ) {
F_126 ( L_104 ) ;
return;
}
switch ( V_644 ) {
case 450000 :
case 432000 :
V_681 = V_683 ;
V_682 = 1 ;
break;
case 540000 :
V_681 = V_684 ;
V_682 = 2 ;
break;
case 308571 :
case 337500 :
default:
V_681 = V_677 ;
V_682 = 0 ;
break;
case 617143 :
case 675000 :
V_681 = V_685 ;
V_682 = 3 ;
break;
}
if ( V_6 -> V_641 . V_52 != 0 &&
V_6 -> V_641 . V_52 != V_52 )
F_499 ( V_6 ) ;
if ( V_6 -> V_641 . V_52 != V_52 )
F_498 ( V_6 , V_52 ) ;
F_123 ( V_658 , V_681 | F_481 ( V_644 ) ) ;
F_124 ( V_658 ) ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
F_400 ( V_6 , V_679 , V_682 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
F_480 ( V_57 ) ;
}
void F_505 ( struct V_5 * V_6 )
{
F_504 ( V_6 , V_6 -> V_641 . V_642 , 0 ) ;
}
void F_506 ( struct V_5 * V_6 )
{
int V_644 , V_52 ;
F_507 ( V_6 ) ;
if ( V_6 -> V_638 != 0 && V_6 -> V_641 . V_52 != 0 ) {
if ( V_6 -> V_632 == 0 )
F_497 ( V_6 ,
V_6 -> V_641 . V_52 ) ;
return;
}
V_52 = V_6 -> V_632 ;
if ( V_52 == 0 )
V_52 = 8100000 ;
V_644 = F_477 ( 0 , V_52 ) ;
F_504 ( V_6 , V_644 , V_52 ) ;
}
static void F_507 ( struct V_5 * V_6 )
{
T_2 V_659 , V_660 ;
if ( ( F_11 ( F_508 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_661;
F_480 ( & V_6 -> V_114 ) ;
if ( V_6 -> V_641 . V_52 == 0 ||
V_6 -> V_638 == V_6 -> V_641 . V_642 )
goto V_661;
V_659 = F_11 ( V_658 ) ;
V_660 = ( V_659 & V_686 ) |
F_481 ( V_6 -> V_638 ) ;
if ( V_659 == V_660 )
return;
V_661:
F_158 ( L_101 ) ;
V_6 -> V_638 = 0 ;
V_6 -> V_641 . V_52 = - 1 ;
}
static void F_509 ( struct V_56 * V_57 , int V_644 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_687 ;
F_28 ( V_6 -> V_436 . V_640 ( V_57 )
!= V_6 -> V_638 ) ;
if ( V_644 >= 320000 )
V_687 = 2 ;
else if ( V_644 == 266667 )
V_687 = 1 ;
else
V_687 = 0 ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_15 = F_510 ( V_6 , V_688 ) ;
V_15 &= ~ V_689 ;
V_15 |= ( V_687 << V_690 ) ;
F_511 ( V_6 , V_688 , V_15 ) ;
if ( F_61 ( ( F_510 ( V_6 , V_688 ) &
V_691 ) == ( V_687 << V_692 ) ,
50 ) ) {
F_126 ( L_105 ) ;
}
F_5 ( & V_6 -> V_553 . V_554 ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( V_644 == 400000 ) {
T_1 V_16 ;
V_16 = F_8 ( V_6 -> V_7 << 1 , V_644 ) - 1 ;
V_15 = F_4 ( V_6 , V_693 ) ;
V_15 &= ~ V_17 ;
V_15 |= V_16 ;
F_512 ( V_6 , V_693 , V_15 ) ;
if ( F_61 ( ( F_4 ( V_6 , V_693 ) &
V_18 ) == ( V_16 << V_19 ) ,
50 ) )
F_126 ( L_105 ) ;
}
V_15 = F_513 ( V_6 , V_694 ) ;
V_15 &= ~ 0x7f ;
if ( V_644 == 400000 )
V_15 |= 4500 / 250 ;
else
V_15 |= 3000 / 250 ;
F_514 ( V_6 , V_694 , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_480 ( V_57 ) ;
}
static void F_515 ( struct V_56 * V_57 , int V_644 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_687 ;
F_28 ( V_6 -> V_436 . V_640 ( V_57 )
!= V_6 -> V_638 ) ;
switch ( V_644 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_170 ( V_644 ) ;
return;
}
V_687 = F_8 ( V_6 -> V_7 << 1 , V_644 ) - 1 ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_15 = F_510 ( V_6 , V_688 ) ;
V_15 &= ~ V_695 ;
V_15 |= ( V_687 << V_696 ) ;
F_511 ( V_6 , V_688 , V_15 ) ;
if ( F_61 ( ( F_510 ( V_6 , V_688 ) &
V_697 ) == ( V_687 << V_698 ) ,
50 ) ) {
F_126 ( L_105 ) ;
}
F_5 ( & V_6 -> V_553 . V_554 ) ;
F_480 ( V_57 ) ;
}
static int F_516 ( struct V_5 * V_6 ,
int V_663 )
{
int V_699 = ( V_6 -> V_7 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_59 = F_17 ( V_6 ) ? 95 : 90 ;
if ( ! F_17 ( V_6 ) &&
V_663 > V_699 * V_59 / 100 )
return 400000 ;
else if ( V_663 > 266667 * V_59 / 100 )
return V_699 ;
else if ( V_663 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_489 ( int V_663 )
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
static int F_517 ( struct V_56 * V_57 ,
struct V_422 * V_43 )
{
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
unsigned V_663 = 0 , V_139 ;
enum V_95 V_95 ;
memcpy ( V_338 -> V_701 , V_6 -> V_701 ,
sizeof( V_338 -> V_701 ) ) ;
F_292 (state, crtc, crtc_state, i) {
int V_702 = 0 ;
if ( V_62 -> V_508 )
V_702 = V_62 -> V_92 . V_93 ;
V_338 -> V_701 [ V_139 ] = V_702 ;
}
F_90 (dev_priv, pipe)
V_663 = V_61 ( V_338 -> V_701 [ V_95 ] , V_663 ) ;
return V_663 ;
}
static int F_518 ( struct V_422 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_663 = F_517 ( V_57 , V_43 ) ;
struct V_700 * V_338 =
F_293 ( V_43 ) ;
V_338 -> V_644 = V_338 -> V_703 =
F_516 ( V_6 , V_663 ) ;
if ( ! V_338 -> V_704 )
V_338 -> V_703 = F_516 ( V_6 , 0 ) ;
return 0 ;
}
static int F_519 ( struct V_422 * V_43 )
{
int V_663 = F_520 ( V_43 ) ;
struct V_700 * V_338 =
F_293 ( V_43 ) ;
V_338 -> V_644 = V_338 -> V_703 =
F_489 ( V_663 ) ;
if ( ! V_338 -> V_704 )
V_338 -> V_703 = F_489 ( 0 ) ;
return 0 ;
}
static void F_521 ( struct V_5 * V_6 )
{
unsigned int V_705 , V_706 ;
if ( F_17 ( V_6 ) )
V_706 = F_522 ( 12 ) ;
else
V_706 = F_522 ( 8 ) ;
if ( V_6 -> V_638 >= V_6 -> V_35 ) {
if ( F_17 ( V_6 ) )
V_705 = V_707 ;
else
V_705 = F_522 ( 15 ) ;
} else {
V_705 = V_706 ;
}
F_123 ( V_708 , V_709 |
V_706 ) ;
F_123 ( V_708 , V_709 |
V_705 | V_710 ) ;
F_28 ( F_11 ( V_708 ) & V_710 ) ;
}
static void F_523 ( struct V_422 * V_563 )
{
struct V_56 * V_57 = V_563 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_700 * V_711 =
F_293 ( V_563 ) ;
unsigned V_712 = V_711 -> V_703 ;
F_471 ( V_6 , V_713 ) ;
if ( F_17 ( V_57 ) )
F_515 ( V_57 , V_712 ) ;
else
F_509 ( V_57 , V_712 ) ;
F_521 ( V_6 ) ;
F_85 ( V_6 , V_713 ) ;
}
static void F_524 ( struct V_37 * V_38 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_38 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
if ( F_387 ( V_81 -> V_91 ) )
F_433 ( V_81 , V_586 ) ;
F_434 ( V_81 ) ;
F_435 ( V_81 ) ;
if ( F_17 ( V_57 ) && V_95 == V_124 ) {
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_123 ( F_525 ( V_95 ) , V_714 ) ;
F_123 ( F_526 ( V_95 ) , 0 ) ;
}
F_527 ( V_81 ) ;
V_81 -> V_88 = true ;
F_405 ( V_6 , V_95 , true ) ;
F_421 ( V_65 , V_38 , V_563 ) ;
if ( F_17 ( V_57 ) ) {
F_528 ( V_81 , V_81 -> V_91 ) ;
F_135 ( V_81 , V_81 -> V_91 ) ;
} else {
F_529 ( V_81 , V_81 -> V_91 ) ;
F_127 ( V_81 , V_81 -> V_91 ) ;
}
F_424 ( V_65 , V_38 , V_563 ) ;
F_457 ( V_81 ) ;
F_438 ( & V_38 -> V_64 ) ;
F_413 ( V_65 ) ;
F_157 ( V_81 ) ;
F_98 ( V_65 ) ;
F_439 ( V_65 ) ;
F_425 ( V_65 , V_38 , V_563 ) ;
}
static void F_530 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_123 ( F_531 ( V_65 -> V_95 ) , V_65 -> V_91 -> V_176 . V_715 ) ;
F_123 ( F_532 ( V_65 -> V_95 ) , V_65 -> V_91 -> V_176 . V_716 ) ;
}
static void F_533 ( struct V_37 * V_38 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_38 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
if ( F_28 ( V_81 -> V_88 ) )
return;
F_530 ( V_81 ) ;
if ( F_387 ( V_81 -> V_91 ) )
F_433 ( V_81 , V_586 ) ;
F_434 ( V_81 ) ;
F_435 ( V_81 ) ;
F_527 ( V_81 ) ;
V_81 -> V_88 = true ;
if ( ! F_55 ( V_57 ) )
F_405 ( V_6 , V_95 , true ) ;
F_424 ( V_65 , V_38 , V_563 ) ;
F_138 ( V_81 ) ;
F_457 ( V_81 ) ;
F_438 ( & V_38 -> V_64 ) ;
F_413 ( V_65 ) ;
F_157 ( V_81 ) ;
F_98 ( V_65 ) ;
F_439 ( V_65 ) ;
F_425 ( V_65 , V_38 , V_563 ) ;
}
static void F_534 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! V_65 -> V_91 -> V_595 . V_596 )
return;
F_128 ( V_6 , V_65 -> V_95 ) ;
F_20 ( L_106 ,
F_11 ( V_597 ) ) ;
F_123 ( V_597 , 0 ) ;
}
static void F_535 ( struct V_37 * V_444 ,
struct V_422 * V_563 )
{
struct V_87 * V_65 = V_444 -> V_64 . V_65 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
if ( F_55 ( V_57 ) )
F_341 ( V_57 , V_95 ) ;
F_427 ( V_65 , V_444 , V_563 ) ;
F_453 ( V_65 ) ;
F_98 ( V_65 ) ;
F_166 ( V_81 ) ;
F_534 ( V_81 ) ;
F_428 ( V_65 , V_444 , V_563 ) ;
if ( ! F_38 ( V_81 -> V_91 , V_225 ) ) {
if ( F_17 ( V_57 ) )
F_143 ( V_6 , V_95 ) ;
else if ( F_16 ( V_57 ) )
F_142 ( V_6 , V_95 ) ;
else
F_141 ( V_81 ) ;
}
F_429 ( V_65 , V_444 , V_563 ) ;
if ( ! F_55 ( V_57 ) )
F_405 ( V_6 , V_95 , false ) ;
}
static void F_536 ( struct V_87 * V_65 )
{
struct V_512 * V_513 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
enum V_131 V_623 ;
unsigned long V_624 ;
struct V_422 * V_43 ;
struct V_37 * V_62 ;
int V_362 ;
if ( ! V_81 -> V_88 )
return;
if ( F_231 ( V_65 -> V_89 -> V_43 ) -> V_64 . V_340 ) {
F_28 ( V_81 -> V_443 ) ;
F_236 ( V_65 ) ;
F_418 ( V_65 , 1 << F_235 ( V_65 -> V_89 ) ) ;
F_231 ( V_65 -> V_89 -> V_43 ) -> V_64 . V_340 = false ;
}
V_43 = F_537 ( V_65 -> V_57 ) ;
V_43 -> V_434 = V_65 -> V_57 -> V_429 . V_434 ;
V_62 = F_538 ( V_43 , V_81 ) ;
V_362 = F_539 ( V_43 , V_65 ) ;
F_28 ( F_191 ( V_62 ) || V_362 ) ;
V_6 -> V_436 . V_717 ( V_62 , V_43 ) ;
F_304 ( V_43 ) ;
F_158 ( L_107 ,
V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
F_28 ( F_540 ( V_65 -> V_43 , NULL ) < 0 ) ;
V_65 -> V_43 -> V_88 = false ;
V_81 -> V_88 = false ;
V_65 -> V_148 = false ;
V_65 -> V_43 -> V_718 = 0 ;
V_65 -> V_43 -> V_719 = 0 ;
F_378 (crtc->dev, crtc, encoder)
V_513 -> V_64 . V_65 = NULL ;
F_541 ( V_81 ) ;
F_413 ( V_65 ) ;
F_542 ( V_81 ) ;
V_624 = V_81 -> V_627 ;
F_470 (domain, domains)
F_85 ( V_6 , V_623 ) ;
V_81 -> V_627 = 0 ;
V_6 -> V_704 &= ~ ( 1 << V_81 -> V_95 ) ;
V_6 -> V_701 [ V_81 -> V_95 ] = 0 ;
}
int F_543 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_422 * V_43 ;
int V_362 ;
V_43 = F_544 ( V_57 ) ;
V_362 = F_545 ( V_43 ) ;
if ( V_362 )
F_126 ( L_57 , V_362 ) ;
else
V_6 -> V_433 = V_43 ;
return V_362 ;
}
void F_546 ( struct V_619 * V_513 )
{
struct V_512 * V_512 = F_423 ( V_513 ) ;
F_547 ( V_513 ) ;
F_232 ( V_512 ) ;
}
static void F_548 ( struct V_720 * V_721 )
{
struct V_87 * V_65 = V_721 -> V_64 . V_43 -> V_65 ;
F_158 ( L_108 ,
V_721 -> V_64 . V_64 . V_377 ,
V_721 -> V_64 . V_12 ) ;
if ( V_721 -> V_722 ( V_721 ) ) {
struct V_512 * V_513 = V_721 -> V_513 ;
struct V_575 * V_579 = V_721 -> V_64 . V_43 ;
F_64 ( ! V_65 ,
L_109 ) ;
if ( ! V_65 )
return;
F_64 ( ! V_65 -> V_43 -> V_88 ,
L_110 ) ;
if ( ! V_513 || V_513 -> type == V_615 )
return;
F_64 ( V_579 -> V_580 != & V_513 -> V_64 ,
L_111 ) ;
F_64 ( V_579 -> V_65 != V_513 -> V_64 . V_65 ,
L_112 ) ;
} else {
F_64 ( V_65 && V_65 -> V_43 -> V_88 ,
L_113 ) ;
F_64 ( ! V_65 && V_721 -> V_64 . V_43 -> V_580 ,
L_114 ) ;
}
}
int F_549 ( struct V_720 * V_721 )
{
F_550 ( & V_721 -> V_64 ) ;
if ( ! V_721 -> V_64 . V_43 )
return - V_723 ;
return 0 ;
}
struct V_720 * F_551 ( void )
{
struct V_720 * V_721 ;
V_721 = F_552 ( sizeof *V_721 , V_724 ) ;
if ( ! V_721 )
return NULL ;
if ( F_549 ( V_721 ) < 0 ) {
F_232 ( V_721 ) ;
return NULL ;
}
return V_721 ;
}
bool F_553 ( struct V_720 * V_721 )
{
enum V_95 V_95 = 0 ;
struct V_512 * V_513 = V_721 -> V_513 ;
return V_513 -> V_722 ( V_513 , & V_95 ) ;
}
static int F_554 ( struct V_37 * V_62 )
{
if ( V_62 -> V_64 . V_508 && V_62 -> V_226 )
return V_62 -> V_459 ;
return 0 ;
}
static int F_555 ( struct V_56 * V_57 , enum V_95 V_95 ,
struct V_37 * V_38 )
{
struct V_422 * V_43 = V_38 -> V_64 . V_43 ;
struct V_81 * V_725 ;
struct V_37 * V_726 ;
F_158 ( L_115 ,
F_77 ( V_95 ) , V_38 -> V_459 ) ;
if ( V_38 -> V_459 > 4 ) {
F_158 ( L_116 ,
F_77 ( V_95 ) , V_38 -> V_459 ) ;
return - V_288 ;
}
if ( F_259 ( V_57 ) || F_260 ( V_57 ) ) {
if ( V_38 -> V_459 > 2 ) {
F_158 ( L_117 ,
V_38 -> V_459 ) ;
return - V_288 ;
} else {
return 0 ;
}
}
if ( F_58 ( V_57 ) -> V_727 == 2 )
return 0 ;
switch ( V_95 ) {
case V_117 :
return 0 ;
case V_124 :
if ( V_38 -> V_459 <= 2 )
return 0 ;
V_725 = F_47 ( F_556 ( V_57 , V_511 ) ) ;
V_726 =
F_538 ( V_43 , V_725 ) ;
if ( F_191 ( V_726 ) )
return F_302 ( V_726 ) ;
if ( F_554 ( V_726 ) > 0 ) {
F_158 ( L_118 ,
F_77 ( V_95 ) , V_38 -> V_459 ) ;
return - V_288 ;
}
return 0 ;
case V_511 :
if ( V_38 -> V_459 > 2 ) {
F_158 ( L_119 ,
F_77 ( V_95 ) , V_38 -> V_459 ) ;
return - V_288 ;
}
V_725 = F_47 ( F_556 ( V_57 , V_124 ) ) ;
V_726 =
F_538 ( V_43 , V_725 ) ;
if ( F_191 ( V_726 ) )
return F_302 ( V_726 ) ;
if ( F_554 ( V_726 ) > 2 ) {
F_158 ( L_120 ) ;
return - V_288 ;
}
return 0 ;
default:
F_145 () ;
}
}
static int F_557 ( struct V_81 * V_81 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
const struct V_521 * V_92 = & V_38 -> V_64 . V_92 ;
int V_728 , V_729 , V_730 , V_362 ;
bool V_731 = false ;
V_464:
V_729 = F_22 ( F_53 ( V_57 ) , V_38 ) ;
V_730 = V_92 -> V_93 ;
V_728 = F_558 ( V_730 , V_729 ,
V_38 -> V_732 ) ;
V_38 -> V_459 = V_728 ;
F_559 ( V_38 -> V_732 , V_728 , V_730 ,
V_729 , & V_38 -> V_587 ) ;
V_362 = F_555 ( V_57 , V_81 -> V_95 , V_38 ) ;
if ( V_362 == - V_288 && V_38 -> V_732 > 6 * 3 ) {
V_38 -> V_732 -= 2 * 3 ;
F_158 ( L_121 ,
V_38 -> V_732 ) ;
V_731 = true ;
V_38 -> V_733 = true ;
goto V_464;
}
if ( V_731 )
return V_734 ;
return V_362 ;
}
static bool F_560 ( struct V_5 * V_6 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_732 > 24 )
return false ;
if ( F_259 ( V_6 ) )
return true ;
return F_561 ( V_38 ) <=
V_6 -> V_628 * 95 / 100 ;
}
static void F_562 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_38 -> V_552 = V_431 . V_735 &&
F_440 ( V_65 ) &&
F_560 ( V_6 , V_38 ) ;
}
static bool F_563 ( const struct V_81 * V_65 )
{
const struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
return F_58 ( V_6 ) -> V_103 < 4 &&
( V_65 -> V_95 == V_117 || F_564 ( V_6 ) ) ;
}
static int F_565 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_521 * V_92 = & V_38 -> V_64 . V_92 ;
int V_736 = V_6 -> V_639 ;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
V_736 = V_6 -> V_628 * 9 / 10 ;
if ( F_563 ( V_65 ) &&
V_92 -> V_93 > V_736 ) {
V_736 = V_6 -> V_639 ;
V_38 -> V_229 = true ;
}
}
if ( V_92 -> V_93 > V_736 ) {
F_158 ( L_122 ,
V_92 -> V_93 , V_736 ,
F_566 ( V_38 -> V_229 ) ) ;
return - V_288 ;
}
if ( ( F_38 ( V_38 , V_66 ) &&
F_39 ( V_57 ) ) || V_38 -> V_229 )
V_38 -> V_367 &= ~ 1 ;
if ( ( F_58 ( V_57 ) -> V_103 > 4 || F_18 ( V_57 ) ) &&
V_92 -> V_737 == V_92 -> V_544 )
return - V_288 ;
if ( F_441 ( V_57 ) )
F_562 ( V_65 , V_38 ) ;
if ( V_38 -> V_226 )
return F_557 ( V_65 , V_38 ) ;
return 0 ;
}
static int F_567 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_659 ;
F_491 ( V_6 ) ;
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
F_170 ( V_659 & V_686 ) ;
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
F_170 ( V_659 & V_686 ) ;
}
}
return V_6 -> V_641 . V_642 ;
}
static void F_568 ( struct V_5 * V_6 )
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
static int F_569 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_16 ;
int div , V_52 ;
F_568 ( V_6 ) ;
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
F_170 ( V_16 ) ;
return V_6 -> V_641 . V_642 ;
}
return F_8 ( V_52 , div ) ;
}
static int F_570 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_738 = F_11 ( V_739 ) ;
T_2 V_740 = V_738 & V_741 ;
if ( V_738 & V_742 )
return 800000 ;
else if ( F_11 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_740 == V_743 )
return 450000 ;
else if ( V_740 == V_744 )
return 540000 ;
else if ( V_740 == V_745 )
return 337500 ;
else
return 675000 ;
}
static int F_571 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_738 = F_11 ( V_739 ) ;
T_2 V_740 = V_738 & V_741 ;
if ( V_738 & V_742 )
return 800000 ;
else if ( F_11 ( V_636 ) & V_637 )
return 450000 ;
else if ( V_740 == V_743 )
return 450000 ;
else if ( F_572 ( V_57 ) )
return 337500 ;
else
return 540000 ;
}
static int F_573 ( struct V_56 * V_57 )
{
return F_9 ( F_53 ( V_57 ) , L_123 ,
V_693 ) ;
}
static int F_574 ( struct V_56 * V_57 )
{
return 450000 ;
}
static int F_575 ( struct V_56 * V_57 )
{
return 400000 ;
}
static int F_576 ( struct V_56 * V_57 )
{
return 333333 ;
}
static int F_577 ( struct V_56 * V_57 )
{
return 200000 ;
}
static int F_578 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
T_4 V_748 = 0 ;
F_579 ( V_747 , V_749 , & V_748 ) ;
switch ( V_748 & V_750 ) {
case V_751 :
return 266667 ;
case V_752 :
return 333333 ;
case V_753 :
return 444444 ;
case V_754 :
return 200000 ;
default:
F_126 ( L_124 , V_748 ) ;
case V_755 :
return 133333 ;
case V_756 :
return 166667 ;
}
}
static int F_580 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
T_4 V_748 = 0 ;
F_579 ( V_747 , V_749 , & V_748 ) ;
if ( V_748 & V_757 )
return 133333 ;
else {
switch ( V_748 & V_750 ) {
case V_758 :
return 333333 ;
default:
case V_759 :
return 190000 ;
}
}
}
static int F_581 ( struct V_56 * V_57 )
{
return 266667 ;
}
static int F_582 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
T_4 V_760 = 0 ;
if ( V_747 -> V_761 == 0x1 )
return 133333 ;
F_583 ( V_747 -> V_762 ,
F_584 ( 0 , 3 ) , V_763 , & V_760 ) ;
switch ( V_760 & V_764 ) {
case V_765 :
case V_766 :
case V_767 :
return 200000 ;
case V_768 :
return 250000 ;
case V_769 :
return 133333 ;
case V_770 :
case V_771 :
case V_772 :
return 266667 ;
}
return 0 ;
}
static int F_585 ( struct V_56 * V_57 )
{
return 133333 ;
}
static unsigned int F_586 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
static const unsigned int V_773 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 6400000 ,
} ;
static const unsigned int V_774 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
[ 4 ] = 2666667 ,
} ;
static const unsigned int V_775 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 3333333 ,
[ 5 ] = 3566667 ,
[ 6 ] = 4266667 ,
} ;
static const unsigned int V_776 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 4800000 ,
} ;
static const unsigned int V_777 [ 8 ] = {
[ 0 ] = 3200000 ,
[ 1 ] = 4000000 ,
[ 2 ] = 5333333 ,
[ 3 ] = 6400000 ,
[ 4 ] = 2666667 ,
[ 5 ] = 4266667 ,
} ;
const unsigned int * V_778 ;
unsigned int V_52 ;
T_5 V_181 = 0 ;
if ( F_587 ( V_57 ) )
V_778 = V_777 ;
else if ( F_18 ( V_57 ) )
V_778 = V_776 ;
else if ( F_183 ( V_57 ) )
V_778 = V_775 ;
else if ( F_19 ( V_57 ) )
V_778 = V_774 ;
else if ( F_588 ( V_57 ) )
V_778 = V_773 ;
else
return 0 ;
V_181 = F_11 ( F_139 ( V_57 ) ? V_779 : V_780 ) ;
V_52 = V_778 [ V_181 & 0x7 ] ;
if ( V_52 == 0 )
F_126 ( L_125 , V_181 ) ;
else
F_158 ( L_126 , V_52 ) ;
return V_52 ;
}
static int F_589 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
unsigned int V_781 , V_52 = F_586 ( V_57 ) ;
T_6 V_181 = 0 ;
F_579 ( V_747 , V_749 , & V_181 ) ;
V_781 = ( V_181 >> 12 ) & 0x1 ;
switch ( V_52 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_781 ? 333333 : 222222 ;
case 3200000 :
return V_781 ? 320000 : 228571 ;
default:
F_126 ( L_127 , V_52 , V_181 ) ;
return 222222 ;
}
}
static int F_590 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
static const T_5 V_782 [] = { 16 , 10 , 8 } ;
static const T_5 V_783 [] = { 20 , 12 , 10 } ;
static const T_5 V_784 [] = { 24 , 16 , 14 } ;
const T_5 * V_785 ;
unsigned int V_781 , V_52 = F_586 ( V_57 ) ;
T_6 V_181 = 0 ;
F_579 ( V_747 , V_749 , & V_181 ) ;
V_781 = ( ( V_181 >> 8 ) & 0x1f ) - 1 ;
if ( V_781 >= F_177 ( V_782 ) )
goto V_786;
switch ( V_52 ) {
case 3200000 :
V_785 = V_782 ;
break;
case 4000000 :
V_785 = V_783 ;
break;
case 5333333 :
V_785 = V_784 ;
break;
default:
goto V_786;
}
return F_8 ( V_52 , V_785 [ V_781 ] ) ;
V_786:
F_126 ( L_128 , V_52 , V_181 ) ;
return 200000 ;
}
static int F_591 ( struct V_56 * V_57 )
{
struct V_746 * V_747 = V_57 -> V_747 ;
static const T_5 V_782 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_5 V_783 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_5 V_787 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_5 V_784 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_5 * V_785 ;
unsigned int V_781 , V_52 = F_586 ( V_57 ) ;
T_6 V_181 = 0 ;
F_579 ( V_747 , V_749 , & V_181 ) ;
V_781 = ( V_181 >> 4 ) & 0x7 ;
if ( V_781 >= F_177 ( V_782 ) )
goto V_786;
switch ( V_52 ) {
case 3200000 :
V_785 = V_782 ;
break;
case 4000000 :
V_785 = V_783 ;
break;
case 4800000 :
V_785 = V_787 ;
break;
case 5333333 :
V_785 = V_784 ;
break;
default:
goto V_786;
}
return F_8 ( V_52 , V_785 [ V_781 ] ) ;
V_786:
F_126 ( L_129 , V_52 , V_181 ) ;
return 190476 ;
}
static void
F_592 ( T_2 * V_788 , T_2 * V_789 )
{
while ( * V_788 > V_790 ||
* V_789 > V_790 ) {
* V_788 >>= 1 ;
* V_789 >>= 1 ;
}
}
static void F_593 ( unsigned int V_46 , unsigned int V_51 ,
T_2 * V_791 , T_2 * V_792 )
{
* V_792 = F_594 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_791 = F_45 ( ( V_55 ) V_46 * * V_792 , V_51 ) ;
F_592 ( V_791 , V_792 ) ;
}
void
F_559 ( int V_793 , int V_794 ,
int V_795 , int V_796 ,
struct V_797 * V_798 )
{
V_798 -> V_799 = 64 ;
F_593 ( V_793 * V_795 ,
V_796 * V_794 * 8 ,
& V_798 -> V_800 , & V_798 -> V_801 ) ;
F_593 ( V_795 , V_796 ,
& V_798 -> V_802 , & V_798 -> V_803 ) ;
}
static inline bool F_595 ( struct V_5 * V_6 )
{
if ( V_431 . V_804 >= 0 )
return V_431 . V_804 != 0 ;
return V_6 -> V_805 . V_806
&& ! ( V_6 -> V_133 & V_807 ) ;
}
static T_2 F_596 ( struct V_45 * V_45 )
{
return ( 1 << V_45 -> V_51 ) << 16 | V_45 -> V_47 ;
}
static T_2 F_597 ( struct V_45 * V_45 )
{
return V_45 -> V_51 << 16 | V_45 -> V_54 << 8 | V_45 -> V_47 ;
}
static void F_598 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_808 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
T_1 V_809 , V_810 = 0 ;
if ( F_19 ( V_57 ) ) {
V_809 = F_596 ( & V_62 -> V_45 ) ;
if ( V_808 )
V_810 = F_596 ( V_808 ) ;
} else {
V_809 = F_597 ( & V_62 -> V_45 ) ;
if ( V_808 )
V_810 = F_597 ( V_808 ) ;
}
V_62 -> V_176 . V_715 = V_809 ;
V_65 -> V_811 = false ;
if ( F_38 ( V_62 , V_66 ) &&
V_808 ) {
V_62 -> V_176 . V_716 = V_810 ;
V_65 -> V_811 = true ;
} else {
V_62 -> V_176 . V_716 = V_809 ;
}
}
static void F_599 ( struct V_5 * V_6 , enum V_95
V_95 )
{
T_1 V_812 ;
V_812 = F_132 ( V_6 , V_95 , F_600 ( 1 ) ) ;
V_812 &= 0xffffff00 ;
V_812 |= 0x00000030 ;
F_134 ( V_6 , V_95 , F_600 ( 1 ) , V_812 ) ;
V_812 = F_132 ( V_6 , V_95 , V_813 ) ;
V_812 &= 0x8cffffff ;
V_812 = 0x8c000000 ;
F_134 ( V_6 , V_95 , V_813 , V_812 ) ;
V_812 = F_132 ( V_6 , V_95 , F_600 ( 1 ) ) ;
V_812 &= 0xffffff00 ;
F_134 ( V_6 , V_95 , F_600 ( 1 ) , V_812 ) ;
V_812 = F_132 ( V_6 , V_95 , V_813 ) ;
V_812 &= 0x00ffffff ;
V_812 |= 0xb0000000 ;
F_134 ( V_6 , V_95 , V_813 , V_812 ) ;
}
static void F_601 ( struct V_81 * V_65 ,
struct V_797 * V_798 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
F_123 ( F_602 ( V_95 ) , F_603 ( V_798 -> V_799 ) | V_798 -> V_800 ) ;
F_123 ( F_604 ( V_95 ) , V_798 -> V_801 ) ;
F_123 ( F_605 ( V_95 ) , V_798 -> V_802 ) ;
F_123 ( F_606 ( V_95 ) , V_798 -> V_803 ) ;
}
static void F_436 ( struct V_81 * V_65 ,
struct V_797 * V_798 ,
struct V_797 * V_814 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_65 -> V_95 ;
enum V_94 V_94 = V_65 -> V_91 -> V_97 ;
if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
F_123 ( F_382 ( V_94 ) , F_603 ( V_798 -> V_799 ) | V_798 -> V_800 ) ;
F_123 ( F_607 ( V_94 ) , V_798 -> V_801 ) ;
F_123 ( F_608 ( V_94 ) , V_798 -> V_802 ) ;
F_123 ( F_609 ( V_94 ) , V_798 -> V_803 ) ;
if ( V_814 && ( F_17 ( V_57 ) || F_58 ( V_57 ) -> V_103 < 8 ) &&
V_65 -> V_91 -> V_815 ) {
F_123 ( F_610 ( V_94 ) ,
F_603 ( V_814 -> V_799 ) | V_814 -> V_800 ) ;
F_123 ( F_611 ( V_94 ) , V_814 -> V_801 ) ;
F_123 ( F_612 ( V_94 ) , V_814 -> V_802 ) ;
F_123 ( F_613 ( V_94 ) , V_814 -> V_803 ) ;
}
} else {
F_123 ( F_614 ( V_95 ) , F_603 ( V_798 -> V_799 ) | V_798 -> V_800 ) ;
F_123 ( F_615 ( V_95 ) , V_798 -> V_801 ) ;
F_123 ( F_616 ( V_95 ) , V_798 -> V_802 ) ;
F_123 ( F_617 ( V_95 ) , V_798 -> V_803 ) ;
}
}
void F_433 ( struct V_81 * V_65 , enum V_816 V_798 )
{
struct V_797 * V_817 , * V_818 = NULL ;
if ( V_798 == V_586 ) {
V_817 = & V_65 -> V_91 -> V_817 ;
V_818 = & V_65 -> V_91 -> V_818 ;
} else if ( V_798 == V_819 ) {
V_817 = & V_65 -> V_91 -> V_818 ;
} else {
F_126 ( L_130 ) ;
return;
}
if ( V_65 -> V_91 -> V_226 )
F_601 ( V_65 , & V_65 -> V_91 -> V_817 ) ;
else
F_436 ( V_65 , V_817 , V_818 ) ;
}
static void F_618 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_176 . V_45 = V_191 |
V_192 | V_187 ;
if ( V_65 -> V_95 != V_117 )
V_38 -> V_176 . V_45 |= V_193 ;
if ( ! F_38 ( V_38 , V_225 ) )
V_38 -> V_176 . V_45 |= V_106 |
V_820 ;
V_38 -> V_176 . V_178 =
( V_38 -> V_590 - 1 ) << V_821 ;
}
static void F_619 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
V_38 -> V_176 . V_45 = V_194 |
V_192 | V_187 ;
if ( V_65 -> V_95 != V_117 )
V_38 -> V_176 . V_45 |= V_193 ;
if ( ! F_38 ( V_38 , V_225 ) )
V_38 -> V_176 . V_45 |= V_106 ;
V_38 -> V_176 . V_178 =
( V_38 -> V_590 - 1 ) << V_821 ;
}
static void F_529 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
T_1 V_822 ;
T_1 V_823 , V_824 , V_825 , V_826 , V_827 ;
T_1 V_828 , V_812 ;
F_123 ( F_63 ( V_95 ) ,
V_38 -> V_176 . V_45 &
~ ( V_106 | V_820 ) ) ;
if ( ( V_38 -> V_176 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_823 = V_38 -> V_45 . V_51 ;
V_824 = V_38 -> V_45 . V_54 ;
V_825 = V_38 -> V_45 . V_47 ;
V_826 = V_38 -> V_45 . V_49 ;
V_827 = V_38 -> V_45 . V_50 ;
if ( V_95 == V_124 )
F_599 ( V_6 , V_95 ) ;
F_134 ( V_6 , V_95 , V_829 , 0x0100000f ) ;
V_812 = F_132 ( V_6 , V_95 , F_620 ( V_95 ) ) ;
V_812 &= 0x00ffffff ;
F_134 ( V_6 , V_95 , F_620 ( V_95 ) , V_812 ) ;
F_134 ( V_6 , V_95 , V_830 , 0x610 ) ;
V_822 = ( ( V_824 << V_831 ) | ( V_825 & V_832 ) ) ;
V_822 |= ( ( V_826 << V_833 ) | ( V_827 << V_834 ) ) ;
V_822 |= ( ( V_823 << V_835 ) ) ;
V_822 |= ( 1 << V_836 ) ;
V_822 |= ( V_837 << V_838 ) ;
F_134 ( V_6 , V_95 , F_621 ( V_95 ) , V_822 ) ;
V_822 |= V_839 ;
F_134 ( V_6 , V_95 , F_621 ( V_95 ) , V_822 ) ;
if ( V_38 -> V_39 == 162000 ||
F_38 ( V_65 -> V_91 , V_616 ) ||
F_38 ( V_65 -> V_91 , V_211 ) )
F_134 ( V_6 , V_95 , F_622 ( V_95 ) ,
0x009f0003 ) ;
else
F_134 ( V_6 , V_95 , F_622 ( V_95 ) ,
0x00d0000f ) ;
if ( F_387 ( V_38 ) ) {
if ( V_95 == V_117 )
F_134 ( V_6 , V_95 , F_623 ( V_95 ) ,
0x0df40000 ) ;
else
F_134 ( V_6 , V_95 , F_623 ( V_95 ) ,
0x0df70000 ) ;
} else {
if ( V_95 == V_117 )
F_134 ( V_6 , V_95 , F_623 ( V_95 ) ,
0x0df70000 ) ;
else
F_134 ( V_6 , V_95 , F_623 ( V_95 ) ,
0x0df40000 ) ;
}
V_828 = F_132 ( V_6 , V_95 , F_624 ( V_95 ) ) ;
V_828 = ( V_828 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_387 ( V_65 -> V_91 ) )
V_828 |= 0x01000000 ;
F_134 ( V_6 , V_95 , F_624 ( V_95 ) , V_828 ) ;
F_134 ( V_6 , V_95 , F_625 ( V_95 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_528 ( struct V_81 * V_65 ,
const struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
enum V_179 V_180 = F_131 ( V_95 ) ;
T_1 V_840 , V_841 ;
T_1 V_823 , V_824 , V_825 , V_826 , V_827 , V_842 ;
T_1 V_843 ;
int V_52 ;
F_123 ( F_63 ( V_95 ) ,
V_38 -> V_176 . V_45 & ~ V_106 ) ;
if ( ( V_38 -> V_176 . V_45 & V_106 ) == 0 )
return;
V_823 = V_38 -> V_45 . V_51 ;
V_842 = V_38 -> V_45 . V_47 & 0x3fffff ;
V_824 = V_38 -> V_45 . V_54 ;
V_825 = V_38 -> V_45 . V_47 >> 22 ;
V_826 = V_38 -> V_45 . V_49 ;
V_827 = V_38 -> V_45 . V_50 ;
V_52 = V_38 -> V_45 . V_52 ;
V_843 = 0 ;
V_840 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_134 ( V_6 , V_95 , F_626 ( V_180 ) ,
5 << V_844 |
V_826 << V_845 |
V_827 << V_846 |
1 << V_847 ) ;
F_134 ( V_6 , V_95 , F_627 ( V_180 ) , V_825 ) ;
F_134 ( V_6 , V_95 , F_628 ( V_180 ) ,
V_848 |
1 << V_849 ) ;
F_134 ( V_6 , V_95 , F_629 ( V_180 ) , V_842 ) ;
V_843 = F_132 ( V_6 , V_95 , F_630 ( V_180 ) ) ;
V_843 &= ~ ( V_850 | V_851 ) ;
V_843 |= ( 2 << V_852 ) ;
if ( V_842 )
V_843 |= V_851 ;
F_134 ( V_6 , V_95 , F_630 ( V_180 ) , V_843 ) ;
V_843 = F_132 ( V_6 , V_95 , F_631 ( V_180 ) ) ;
V_843 &= ~ ( V_853 |
V_854 ) ;
V_843 |= ( 0x5 << V_855 ) ;
if ( ! V_842 )
V_843 |= V_854 ;
F_134 ( V_6 , V_95 , F_631 ( V_180 ) , V_843 ) ;
if ( V_52 == 5400000 ) {
V_840 |= ( 0x3 << V_856 ) ;
V_840 |= ( 0x8 << V_857 ) ;
V_840 |= ( 0x1 << V_858 ) ;
V_841 = 0x9 ;
} else if ( V_52 <= 6200000 ) {
V_840 |= ( 0x5 << V_856 ) ;
V_840 |= ( 0xB << V_857 ) ;
V_840 |= ( 0x3 << V_858 ) ;
V_841 = 0x9 ;
} else if ( V_52 <= 6480000 ) {
V_840 |= ( 0x4 << V_856 ) ;
V_840 |= ( 0x9 << V_857 ) ;
V_840 |= ( 0x3 << V_858 ) ;
V_841 = 0x8 ;
} else {
V_840 |= ( 0x4 << V_856 ) ;
V_840 |= ( 0x9 << V_857 ) ;
V_840 |= ( 0x3 << V_858 ) ;
V_841 = 0 ;
}
F_134 ( V_6 , V_95 , F_632 ( V_180 ) , V_840 ) ;
V_843 = F_132 ( V_6 , V_95 , F_633 ( V_180 ) ) ;
V_843 &= ~ V_859 ;
V_843 |= ( V_841 << V_860 ) ;
F_134 ( V_6 , V_95 , F_633 ( V_180 ) , V_843 ) ;
F_134 ( V_6 , V_95 , F_133 ( V_180 ) ,
F_132 ( V_6 , V_95 , F_133 ( V_180 ) ) |
V_861 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_634 ( struct V_56 * V_57 , enum V_95 V_95 ,
const struct V_45 * V_45 )
{
struct V_81 * V_65 =
F_47 ( F_556 ( V_57 , V_95 ) ) ;
struct V_37 * V_38 ;
V_38 = F_552 ( sizeof( * V_38 ) , V_724 ) ;
if ( ! V_38 )
return - V_723 ;
V_38 -> V_64 . V_65 = & V_65 -> V_64 ;
V_38 -> V_590 = 1 ;
V_38 -> V_45 = * V_45 ;
if ( F_17 ( V_57 ) ) {
F_619 ( V_65 , V_38 ) ;
F_528 ( V_65 , V_38 ) ;
F_135 ( V_65 , V_38 ) ;
} else {
F_618 ( V_65 , V_38 ) ;
F_529 ( V_65 , V_38 ) ;
F_127 ( V_65 , V_38 ) ;
}
F_232 ( V_38 ) ;
return 0 ;
}
void F_635 ( struct V_56 * V_57 , enum V_95 V_95 )
{
if ( F_17 ( V_57 ) )
F_143 ( F_53 ( V_57 ) , V_95 ) ;
else
F_142 ( F_53 ( V_57 ) , V_95 ) ;
}
static void F_636 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_808 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_62 -> V_45 ;
F_598 ( V_65 , V_62 , V_808 ) ;
V_45 = V_187 ;
if ( F_38 ( V_62 , V_66 ) )
V_45 |= V_862 ;
else
V_45 |= V_863 ;
if ( F_637 ( V_57 ) || F_638 ( V_57 ) || F_588 ( V_57 ) ) {
V_45 |= ( V_62 -> V_590 - 1 )
<< V_864 ;
}
if ( F_38 ( V_62 , V_216 ) ||
F_38 ( V_62 , V_211 ) )
V_45 |= V_865 ;
if ( F_387 ( V_62 ) )
V_45 |= V_865 ;
if ( F_19 ( V_57 ) )
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_866 ;
else {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_867 ;
if ( F_18 ( V_57 ) && V_808 )
V_45 |= ( 1 << ( V_808 -> V_49 - 1 ) ) << V_868 ;
}
switch ( clock -> V_50 ) {
case 5 :
V_45 |= V_869 ;
break;
case 7 :
V_45 |= V_870 ;
break;
case 10 :
V_45 |= V_871 ;
break;
case 14 :
V_45 |= V_872 ;
break;
}
if ( F_58 ( V_57 ) -> V_103 >= 4 )
V_45 |= ( 6 << V_873 ) ;
if ( V_62 -> V_874 )
V_45 |= V_875 ;
else if ( F_38 ( V_62 , V_66 ) &&
F_595 ( V_6 ) )
V_45 |= V_876 ;
else
V_45 |= V_877 ;
V_45 |= V_106 ;
V_62 -> V_176 . V_45 = V_45 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
T_1 V_178 = ( V_62 -> V_590 - 1 )
<< V_821 ;
V_62 -> V_176 . V_178 = V_178 ;
}
}
static void F_639 ( struct V_81 * V_65 ,
struct V_37 * V_62 ,
struct V_45 * V_808 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 ;
struct V_45 * clock = & V_62 -> V_45 ;
F_598 ( V_65 , V_62 , V_808 ) ;
V_45 = V_187 ;
if ( F_38 ( V_62 , V_66 ) ) {
V_45 |= ( 1 << ( clock -> V_49 - 1 ) ) << V_867 ;
} else {
if ( clock -> V_49 == 2 )
V_45 |= V_878 ;
else
V_45 |= ( clock -> V_49 - 2 ) << V_867 ;
if ( clock -> V_50 == 4 )
V_45 |= V_879 ;
}
if ( ! F_140 ( V_57 ) && F_38 ( V_62 , V_189 ) )
V_45 |= V_190 ;
if ( F_38 ( V_62 , V_66 ) &&
F_595 ( V_6 ) )
V_45 |= V_876 ;
else
V_45 |= V_877 ;
V_45 |= V_106 ;
V_62 -> V_176 . V_45 = V_45 ;
}
static void F_434 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
const struct V_521 * V_92 = & V_81 -> V_91 -> V_64 . V_92 ;
T_2 V_880 , V_881 ;
int V_882 = 0 ;
V_880 = V_92 -> V_880 ;
V_881 = V_92 -> V_881 ;
if ( V_92 -> V_330 & V_883 ) {
V_880 -= 1 ;
V_881 -= 1 ;
if ( F_38 ( V_81 -> V_91 , V_216 ) )
V_882 = ( V_92 -> V_884 - 1 ) / 2 ;
else
V_882 = V_92 -> V_737 -
V_92 -> V_884 / 2 ;
if ( V_882 < 0 )
V_882 += V_92 -> V_884 ;
}
if ( F_58 ( V_57 ) -> V_103 > 3 )
F_123 ( F_374 ( V_97 ) , V_882 ) ;
F_123 ( F_362 ( V_97 ) ,
( V_92 -> V_544 - 1 ) |
( ( V_92 -> V_884 - 1 ) << 16 ) ) ;
F_123 ( F_364 ( V_97 ) ,
( V_92 -> V_885 - 1 ) |
( ( V_92 -> V_886 - 1 ) << 16 ) ) ;
F_123 ( F_366 ( V_97 ) ,
( V_92 -> V_737 - 1 ) |
( ( V_92 -> V_887 - 1 ) << 16 ) ) ;
F_123 ( F_368 ( V_97 ) ,
( V_92 -> V_545 - 1 ) |
( ( V_880 - 1 ) << 16 ) ) ;
F_123 ( F_370 ( V_97 ) ,
( V_92 -> V_888 - 1 ) |
( ( V_881 - 1 ) << 16 ) ) ;
F_123 ( F_372 ( V_97 ) ,
( V_92 -> V_889 - 1 ) |
( ( V_92 -> V_890 - 1 ) << 16 ) ) ;
if ( F_259 ( V_57 ) && V_97 == V_589 &&
( V_95 == V_124 || V_95 == V_511 ) )
F_123 ( F_368 ( V_95 ) , F_11 ( F_368 ( V_97 ) ) ) ;
}
static void F_435 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
F_123 ( F_320 ( V_95 ) ,
( ( V_81 -> V_91 -> V_367 - 1 ) << 16 ) |
( V_81 -> V_91 -> V_366 - 1 ) ) ;
}
static void F_640 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_38 -> V_97 ;
T_2 V_181 ;
V_181 = F_11 ( F_362 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_544 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_884 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_181 = F_11 ( F_364 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_885 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_886 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_181 = F_11 ( F_366 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_737 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_887 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_181 = F_11 ( F_368 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_545 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_880 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_181 = F_11 ( F_370 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_888 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_881 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_181 = F_11 ( F_372 ( V_97 ) ) ;
V_38 -> V_64 . V_92 . V_889 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_64 . V_92 . V_890 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
if ( F_11 ( F_59 ( V_97 ) ) & V_214 ) {
V_38 -> V_64 . V_92 . V_330 |= V_883 ;
V_38 -> V_64 . V_92 . V_880 += 1 ;
V_38 -> V_64 . V_92 . V_881 += 1 ;
}
}
static void F_641 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_181 ;
V_181 = F_11 ( F_320 ( V_65 -> V_95 ) ) ;
V_38 -> V_366 = ( V_181 & 0xffff ) + 1 ;
V_38 -> V_367 = ( ( V_181 >> 16 ) & 0xffff ) + 1 ;
V_38 -> V_64 . V_418 . V_891 = V_38 -> V_366 ;
V_38 -> V_64 . V_418 . V_892 = V_38 -> V_367 ;
}
void F_642 ( struct V_521 * V_418 ,
struct V_37 * V_38 )
{
V_418 -> V_892 = V_38 -> V_64 . V_92 . V_544 ;
V_418 -> V_893 = V_38 -> V_64 . V_92 . V_884 ;
V_418 -> V_894 = V_38 -> V_64 . V_92 . V_737 ;
V_418 -> V_895 = V_38 -> V_64 . V_92 . V_887 ;
V_418 -> V_891 = V_38 -> V_64 . V_92 . V_545 ;
V_418 -> V_896 = V_38 -> V_64 . V_92 . V_880 ;
V_418 -> V_897 = V_38 -> V_64 . V_92 . V_889 ;
V_418 -> V_898 = V_38 -> V_64 . V_92 . V_890 ;
V_418 -> V_330 = V_38 -> V_64 . V_92 . V_330 ;
V_418 -> type = V_899 ;
V_418 -> clock = V_38 -> V_64 . V_92 . V_93 ;
V_418 -> V_330 |= V_38 -> V_64 . V_92 . V_330 ;
V_418 -> V_900 = F_643 ( V_418 ) ;
V_418 -> V_901 = F_644 ( V_418 ) ;
F_645 ( V_418 ) ;
}
static void F_527 ( struct V_81 * V_81 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_902 ;
V_902 = 0 ;
if ( ( V_81 -> V_95 == V_117 && V_6 -> V_133 & V_134 ) ||
( V_81 -> V_95 == V_124 && V_6 -> V_133 & V_135 ) )
V_902 |= F_11 ( F_59 ( V_81 -> V_95 ) ) & V_136 ;
if ( V_81 -> V_91 -> V_229 )
V_902 |= V_230 ;
if ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) {
if ( V_81 -> V_91 -> V_903 && V_81 -> V_91 -> V_732 != 30 )
V_902 |= V_904 |
V_905 ;
switch ( V_81 -> V_91 -> V_732 ) {
case 18 :
V_902 |= V_906 ;
break;
case 24 :
V_902 |= V_212 ;
break;
case 30 :
V_902 |= V_907 ;
break;
default:
F_145 () ;
}
}
if ( F_646 ( V_57 ) ) {
if ( V_81 -> V_811 ) {
F_158 ( L_131 ) ;
V_902 |= V_908 ;
} else {
F_158 ( L_132 ) ;
}
}
if ( V_81 -> V_91 -> V_64 . V_92 . V_330 & V_883 ) {
if ( F_58 ( V_57 ) -> V_103 < 4 ||
F_38 ( V_81 -> V_91 , V_216 ) )
V_902 |= V_909 ;
else
V_902 |= V_910 ;
} else
V_902 |= V_911 ;
if ( ( F_16 ( V_57 ) || F_17 ( V_57 ) ) &&
V_81 -> V_91 -> V_912 )
V_902 |= V_913 ;
F_123 ( F_59 ( V_81 -> V_95 ) , V_902 ) ;
F_124 ( F_59 ( V_81 -> V_95 ) ) ;
}
static int F_647 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 48000 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_595 ( V_6 ) ) {
V_44 = V_6 -> V_805 . V_914 ;
F_158 ( L_133 , V_44 ) ;
}
V_59 = & V_915 ;
} else if ( F_38 ( V_62 , V_189 ) ) {
V_59 = & V_916 ;
} else {
V_59 = & V_917 ;
}
if ( ! V_62 -> V_918 &&
! F_40 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_639 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_648 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_595 ( V_6 ) ) {
V_44 = V_6 -> V_805 . V_914 ;
F_158 ( L_133 , V_44 ) ;
}
if ( F_39 ( V_57 ) )
V_59 = & V_919 ;
else
V_59 = & V_920 ;
} else if ( F_38 ( V_62 , V_211 ) ||
F_38 ( V_62 , V_616 ) ) {
V_59 = & V_921 ;
} else if ( F_38 ( V_62 , V_216 ) ) {
V_59 = & V_922 ;
} else {
V_59 = & V_923 ;
}
if ( ! V_62 -> V_918 &&
! F_42 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_636 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_649 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_595 ( V_6 ) ) {
V_44 = V_6 -> V_805 . V_914 ;
F_158 ( L_133 , V_44 ) ;
}
V_59 = & V_924 ;
} else {
V_59 = & V_925 ;
}
if ( ! V_62 -> V_918 &&
! F_41 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_636 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_650 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
const struct V_58 * V_59 ;
int V_44 = 96000 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_595 ( V_6 ) ) {
V_44 = V_6 -> V_805 . V_914 ;
F_158 ( L_133 , V_44 ) ;
}
V_59 = & V_926 ;
} else {
V_59 = & V_923 ;
}
if ( ! V_62 -> V_918 &&
! F_40 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_636 ( V_65 , V_62 , NULL ) ;
return 0 ;
}
static int F_651 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
int V_44 = 100000 ;
const struct V_58 * V_59 = & V_927 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( ! V_62 -> V_918 &&
! F_48 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_619 ( V_65 , V_62 ) ;
return 0 ;
}
static int F_652 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
int V_44 = 100000 ;
const struct V_58 * V_59 = & V_928 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
if ( ! V_62 -> V_918 &&
! F_46 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_618 ( V_65 , V_62 ) ;
return 0 ;
}
static void F_653 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_181 ;
if ( F_58 ( V_57 ) -> V_103 <= 3 && ( F_140 ( V_57 ) || ! F_139 ( V_57 ) ) )
return;
V_181 = F_11 ( V_597 ) ;
if ( ! ( V_181 & V_598 ) )
return;
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
if ( V_65 -> V_95 != V_124 )
return;
} else {
if ( ( V_181 & V_929 ) != ( V_65 -> V_95 << V_930 ) )
return;
}
V_38 -> V_595 . V_596 = V_181 ;
V_38 -> V_595 . V_600 = F_11 ( V_599 ) ;
}
static void F_654 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
struct V_45 clock ;
T_1 V_822 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_176 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_822 = F_132 ( V_6 , V_95 , F_621 ( V_95 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_822 >> V_831 ) & 7 ;
clock . V_47 = V_822 & V_832 ;
clock . V_51 = ( V_822 >> V_835 ) & 0xf ;
clock . V_49 = ( V_822 >> V_833 ) & 7 ;
clock . V_50 = ( V_822 >> V_834 ) & 0x1f ;
V_38 -> V_39 = F_31 ( V_44 , & clock ) ;
}
static void
F_655 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_275 ;
int V_95 = V_65 -> V_95 , V_137 = V_65 -> V_137 ;
int V_931 , V_241 ;
unsigned int V_932 ;
struct V_248 * V_90 ;
struct V_266 * V_267 ;
V_15 = F_11 ( F_87 ( V_137 ) ) ;
if ( ! ( V_15 & V_138 ) )
return;
V_267 = F_552 ( sizeof( * V_267 ) , V_724 ) ;
if ( ! V_267 ) {
F_158 ( L_135 ) ;
return;
}
V_90 = & V_267 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_15 & V_369 ) {
V_319 -> V_328 = V_281 ;
V_90 -> V_260 [ 0 ] = V_234 ;
}
}
V_241 = V_15 & V_933 ;
V_931 = F_218 ( V_241 ) ;
V_90 -> V_241 = V_931 ;
V_90 -> V_793 = F_174 ( V_931 , 0 ) * 8 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_319 -> V_328 )
V_275 = F_11 ( F_254 ( V_137 ) ) ;
else
V_275 = F_11 ( F_255 ( V_137 ) ) ;
V_64 = F_11 ( F_252 ( V_137 ) ) & 0xfffff000 ;
} else {
V_64 = F_11 ( F_256 ( V_137 ) ) ;
}
V_319 -> V_64 = V_64 ;
V_15 = F_11 ( F_320 ( V_95 ) ) ;
V_90 -> V_245 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_240 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_251 ( V_95 ) ) ;
V_90 -> V_262 [ 0 ] = V_15 & 0xffffffc0 ;
V_932 = F_173 ( V_57 , V_90 -> V_240 ,
V_90 -> V_241 ,
V_90 -> V_260 [ 0 ] ) ;
V_319 -> V_244 = V_90 -> V_262 [ 0 ] * V_932 ;
F_158 ( L_136 ,
F_77 ( V_95 ) , V_137 , V_90 -> V_245 , V_90 -> V_240 ,
V_90 -> V_793 , V_64 , V_90 -> V_262 [ 0 ] ,
V_319 -> V_244 ) ;
V_319 -> V_90 = V_267 ;
}
static void F_656 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
enum V_179 V_180 = F_131 ( V_95 ) ;
struct V_45 clock ;
T_1 V_934 , V_935 , V_936 , V_937 , V_938 ;
int V_44 = 100000 ;
if ( ( V_38 -> V_176 . V_45 & V_106 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_934 = F_132 ( V_6 , V_95 , F_626 ( V_180 ) ) ;
V_935 = F_132 ( V_6 , V_95 , F_627 ( V_180 ) ) ;
V_936 = F_132 ( V_6 , V_95 , F_628 ( V_180 ) ) ;
V_937 = F_132 ( V_6 , V_95 , F_629 ( V_180 ) ) ;
V_938 = F_132 ( V_6 , V_95 , F_630 ( V_180 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_54 = ( V_936 & 0x7 ) == V_848 ? 2 : 0 ;
clock . V_47 = ( V_935 & 0xff ) << 22 ;
if ( V_938 & V_851 )
clock . V_47 |= V_937 & 0x3fffff ;
clock . V_51 = ( V_936 >> V_849 ) & 0xf ;
clock . V_49 = ( V_934 >> V_845 ) & 0x7 ;
clock . V_50 = ( V_934 >> V_846 ) & 0x1f ;
V_38 -> V_39 = F_32 ( V_44 , & clock ) ;
}
static bool F_657 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_131 V_132 ;
T_2 V_181 ;
bool V_362 ;
V_132 = F_466 ( V_65 -> V_95 ) ;
if ( ! F_84 ( V_6 , V_132 ) )
return false ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_38 -> V_208 = NULL ;
V_362 = false ;
V_181 = F_11 ( F_59 ( V_65 -> V_95 ) ) ;
if ( ! ( V_181 & V_136 ) )
goto V_939;
if ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) {
switch ( V_181 & V_210 ) {
case V_906 :
V_38 -> V_732 = 18 ;
break;
case V_212 :
V_38 -> V_732 = 24 ;
break;
case V_907 :
V_38 -> V_732 = 30 ;
break;
default:
break;
}
}
if ( ( F_16 ( V_57 ) || F_17 ( V_57 ) ) &&
( V_181 & V_913 ) )
V_38 -> V_912 = true ;
if ( F_58 ( V_57 ) -> V_103 < 4 )
V_38 -> V_229 = V_181 & V_230 ;
F_640 ( V_65 , V_38 ) ;
F_641 ( V_65 , V_38 ) ;
F_653 ( V_65 , V_38 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( F_17 ( V_57 ) && V_65 -> V_95 != V_117 )
V_181 = V_6 -> V_186 [ V_65 -> V_95 ] ;
else
V_181 = F_11 ( F_129 ( V_65 -> V_95 ) ) ;
V_38 -> V_590 =
( ( V_181 & V_940 )
>> V_821 ) + 1 ;
V_38 -> V_176 . V_178 = V_181 ;
} else if ( F_637 ( V_57 ) || F_638 ( V_57 ) || F_588 ( V_57 ) ) {
V_181 = F_11 ( F_63 ( V_65 -> V_95 ) ) ;
V_38 -> V_590 =
( ( V_181 & V_941 )
>> V_864 ) + 1 ;
} else {
V_38 -> V_590 = 1 ;
}
V_38 -> V_176 . V_45 = F_11 ( F_63 ( V_65 -> V_95 ) ) ;
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
if ( F_140 ( V_57 ) )
V_38 -> V_176 . V_45 &= ~ V_190 ;
V_38 -> V_176 . V_715 = F_11 ( F_531 ( V_65 -> V_95 ) ) ;
V_38 -> V_176 . V_716 = F_11 ( F_532 ( V_65 -> V_95 ) ) ;
} else {
V_38 -> V_176 . V_45 &= ~ ( V_177 |
V_203 |
V_201 ) ;
}
if ( F_17 ( V_57 ) )
F_656 ( V_65 , V_38 ) ;
else if ( F_16 ( V_57 ) )
F_654 ( V_65 , V_38 ) ;
else
F_658 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_92 . V_93 =
V_38 -> V_39 / V_38 -> V_590 ;
V_362 = true ;
V_939:
F_85 ( V_6 , V_132 ) ;
return V_362 ;
}
static void F_659 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_512 * V_513 ;
int V_139 ;
T_1 V_15 , V_942 ;
bool V_943 = false ;
bool V_944 = false ;
bool V_945 = false ;
bool V_946 = false ;
bool V_947 = false ;
bool V_948 = false ;
F_660 (dev, encoder) {
switch ( V_513 -> type ) {
case V_66 :
V_945 = true ;
V_943 = true ;
break;
case V_515 :
V_945 = true ;
if ( F_379 ( & V_513 -> V_64 ) -> V_180 == V_601 )
V_944 = true ;
break;
default:
break;
}
}
if ( F_119 ( V_57 ) ) {
V_946 = V_6 -> V_805 . V_949 ;
V_947 = V_946 ;
} else {
V_946 = false ;
V_947 = true ;
}
for ( V_139 = 0 ; V_139 < V_6 -> V_950 ; V_139 ++ ) {
T_1 V_446 = F_11 ( F_661 ( V_139 ) ) ;
if ( ! ( V_446 & V_106 ) )
continue;
if ( ( V_446 & V_951 ) ==
V_876 ) {
V_948 = true ;
break;
}
}
F_158 ( L_137 ,
V_945 , V_943 , V_946 , V_948 ) ;
V_15 = F_11 ( V_952 ) ;
V_942 = V_15 ;
V_942 &= ~ V_953 ;
if ( V_946 )
V_942 |= V_954 ;
else
V_942 |= V_955 ;
V_942 &= ~ V_956 ;
V_942 &= ~ V_957 ;
V_942 &= ~ V_958 ;
if ( V_945 ) {
V_942 |= V_959 ;
if ( F_595 ( V_6 ) && V_947 )
V_942 |= V_958 ;
if ( V_944 ) {
if ( F_595 ( V_6 ) && V_947 )
V_942 |= V_960 ;
else
V_942 |= V_961 ;
} else
V_942 |= V_962 ;
} else if ( V_948 ) {
V_942 |= V_959 ;
V_942 |= V_958 ;
}
if ( V_942 == V_15 )
return;
V_15 &= ~ V_953 ;
if ( V_946 )
V_15 |= V_954 ;
else
V_15 |= V_955 ;
if ( V_945 ) {
V_15 &= ~ V_956 ;
V_15 |= V_959 ;
if ( F_595 ( V_6 ) && V_947 ) {
F_158 ( L_138 ) ;
V_15 |= V_958 ;
} else
V_15 &= ~ V_958 ;
F_123 ( V_952 , V_15 ) ;
F_124 ( V_952 ) ;
F_125 ( 200 ) ;
V_15 &= ~ V_957 ;
if ( V_944 ) {
if ( F_595 ( V_6 ) && V_947 ) {
F_158 ( L_139 ) ;
V_15 |= V_960 ;
} else
V_15 |= V_961 ;
} else
V_15 |= V_962 ;
F_123 ( V_952 , V_15 ) ;
F_124 ( V_952 ) ;
F_125 ( 200 ) ;
} else {
F_158 ( L_140 ) ;
V_15 &= ~ V_957 ;
V_15 |= V_962 ;
F_123 ( V_952 , V_15 ) ;
F_124 ( V_952 ) ;
F_125 ( 200 ) ;
if ( ! V_948 ) {
F_158 ( L_141 ) ;
V_15 &= ~ V_956 ;
V_15 |= V_963 ;
V_15 &= ~ V_958 ;
F_123 ( V_952 , V_15 ) ;
F_124 ( V_952 ) ;
F_125 ( 200 ) ;
}
}
F_662 ( V_15 != V_942 ) ;
}
static void F_663 ( struct V_5 * V_6 )
{
T_2 V_181 ;
V_181 = F_11 ( V_964 ) ;
V_181 |= V_965 ;
F_123 ( V_964 , V_181 ) ;
if ( F_664 ( F_11 ( V_964 ) &
V_966 , 100 ) )
F_126 ( L_142 ) ;
V_181 = F_11 ( V_964 ) ;
V_181 &= ~ V_965 ;
F_123 ( V_964 , V_181 ) ;
if ( F_664 ( ( F_11 ( V_964 ) &
V_966 ) == 0 , 100 ) )
F_126 ( L_143 ) ;
}
static void F_665 ( struct V_5 * V_6 )
{
T_2 V_181 ;
V_181 = F_352 ( V_6 , 0x8008 , V_967 ) ;
V_181 &= ~ ( 0xFF << 24 ) ;
V_181 |= ( 0x12 << 24 ) ;
F_353 ( V_6 , 0x8008 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2008 , V_967 ) ;
V_181 |= ( 1 << 11 ) ;
F_353 ( V_6 , 0x2008 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2108 , V_967 ) ;
V_181 |= ( 1 << 11 ) ;
F_353 ( V_6 , 0x2108 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x206C , V_967 ) ;
V_181 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_353 ( V_6 , 0x206C , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x216C , V_967 ) ;
V_181 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_353 ( V_6 , 0x216C , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2080 , V_967 ) ;
V_181 &= ~ ( 7 << 13 ) ;
V_181 |= ( 5 << 13 ) ;
F_353 ( V_6 , 0x2080 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2180 , V_967 ) ;
V_181 &= ~ ( 7 << 13 ) ;
V_181 |= ( 5 << 13 ) ;
F_353 ( V_6 , 0x2180 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x208C , V_967 ) ;
V_181 &= ~ 0xFF ;
V_181 |= 0x1C ;
F_353 ( V_6 , 0x208C , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x218C , V_967 ) ;
V_181 &= ~ 0xFF ;
V_181 |= 0x1C ;
F_353 ( V_6 , 0x218C , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2098 , V_967 ) ;
V_181 &= ~ ( 0xFF << 16 ) ;
V_181 |= ( 0x1C << 16 ) ;
F_353 ( V_6 , 0x2098 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x2198 , V_967 ) ;
V_181 &= ~ ( 0xFF << 16 ) ;
V_181 |= ( 0x1C << 16 ) ;
F_353 ( V_6 , 0x2198 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x20C4 , V_967 ) ;
V_181 |= ( 1 << 27 ) ;
F_353 ( V_6 , 0x20C4 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x21C4 , V_967 ) ;
V_181 |= ( 1 << 27 ) ;
F_353 ( V_6 , 0x21C4 , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x20EC , V_967 ) ;
V_181 &= ~ ( 0xF << 28 ) ;
V_181 |= ( 4 << 28 ) ;
F_353 ( V_6 , 0x20EC , V_181 , V_967 ) ;
V_181 = F_352 ( V_6 , 0x21EC , V_967 ) ;
V_181 &= ~ ( 0xF << 28 ) ;
V_181 |= ( 4 << 28 ) ;
F_353 ( V_6 , 0x21EC , V_181 , V_967 ) ;
}
static void F_666 ( struct V_56 * V_57 , bool V_968 ,
bool V_969 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_13 , V_181 ;
if ( F_7 ( V_969 && ! V_968 , L_144 ) )
V_968 = true ;
if ( F_7 ( F_667 ( V_57 ) && V_969 , L_145 ) )
V_969 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_181 = F_352 ( V_6 , V_970 , V_489 ) ;
V_181 &= ~ V_490 ;
V_181 |= V_971 ;
F_353 ( V_6 , V_970 , V_181 , V_489 ) ;
F_125 ( 24 ) ;
if ( V_968 ) {
V_181 = F_352 ( V_6 , V_970 , V_489 ) ;
V_181 &= ~ V_971 ;
F_353 ( V_6 , V_970 , V_181 , V_489 ) ;
if ( V_969 ) {
F_663 ( V_6 ) ;
F_665 ( V_6 ) ;
}
}
V_13 = F_667 ( V_57 ) ? V_972 : V_973 ;
V_181 = F_352 ( V_6 , V_13 , V_489 ) ;
V_181 |= V_974 ;
F_353 ( V_6 , V_13 , V_181 , V_489 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_668 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_13 , V_181 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_667 ( V_57 ) ? V_972 : V_973 ;
V_181 = F_352 ( V_6 , V_13 , V_489 ) ;
V_181 &= ~ V_974 ;
F_353 ( V_6 , V_13 , V_181 , V_489 ) ;
V_181 = F_352 ( V_6 , V_970 , V_489 ) ;
if ( ! ( V_181 & V_490 ) ) {
if ( ! ( V_181 & V_971 ) ) {
V_181 |= V_971 ;
F_353 ( V_6 , V_970 , V_181 , V_489 ) ;
F_125 ( 32 ) ;
}
V_181 |= V_490 ;
F_353 ( V_6 , V_970 , V_181 , V_489 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_669 ( struct V_5 * V_6 , int V_975 )
{
T_2 V_181 ;
int V_976 = F_670 ( V_975 ) ;
if ( F_28 ( V_975 % 5 != 0 ) )
return;
if ( F_28 ( V_976 >= F_177 ( V_977 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_975 % 10 != 0 )
V_181 = 0xAAAAAAAB ;
else
V_181 = 0x00000000 ;
F_353 ( V_6 , V_978 , V_181 , V_489 ) ;
V_181 = F_352 ( V_6 , V_979 , V_489 ) ;
V_181 &= 0xffff0000 ;
V_181 |= V_977 [ V_976 ] ;
F_353 ( V_6 , V_979 , V_181 , V_489 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_671 ( struct V_56 * V_57 )
{
struct V_512 * V_513 ;
bool V_980 = false ;
F_660 (dev, encoder) {
switch ( V_513 -> type ) {
case V_616 :
V_980 = true ;
break;
default:
break;
}
}
if ( V_980 ) {
F_669 ( F_53 ( V_57 ) , 0 ) ;
F_666 ( V_57 , true , true ) ;
} else {
F_668 ( V_57 ) ;
}
}
void F_672 ( struct V_56 * V_57 )
{
if ( F_119 ( V_57 ) || F_105 ( V_57 ) )
F_659 ( V_57 ) ;
else if ( F_160 ( V_57 ) )
F_671 ( V_57 ) ;
}
static void F_437 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_81 -> V_91 -> V_732 ) {
case 18 :
V_15 |= V_906 ;
break;
case 24 :
V_15 |= V_212 ;
break;
case 30 :
V_15 |= V_907 ;
break;
case 36 :
V_15 |= V_981 ;
break;
default:
F_145 () ;
}
if ( V_81 -> V_91 -> V_903 )
V_15 |= ( V_904 | V_905 ) ;
if ( V_81 -> V_91 -> V_64 . V_92 . V_330 & V_883 )
V_15 |= V_215 ;
else
V_15 |= V_911 ;
if ( V_81 -> V_91 -> V_912 )
V_15 |= V_913 ;
F_123 ( F_59 ( V_95 ) , V_15 ) ;
F_124 ( F_59 ( V_95 ) ) ;
}
static void F_445 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
T_1 V_15 = 0 ;
if ( F_259 ( V_6 ) && V_81 -> V_91 -> V_903 )
V_15 |= ( V_904 | V_905 ) ;
if ( V_81 -> V_91 -> V_64 . V_92 . V_330 & V_883 )
V_15 |= V_215 ;
else
V_15 |= V_911 ;
F_123 ( F_59 ( V_97 ) , V_15 ) ;
F_124 ( F_59 ( V_97 ) ) ;
}
static void F_446 ( struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
if ( F_260 ( V_6 ) || F_58 ( V_6 ) -> V_103 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_81 -> V_91 -> V_732 ) {
case 18 :
V_15 |= V_982 ;
break;
case 24 :
V_15 |= V_983 ;
break;
case 30 :
V_15 |= V_984 ;
break;
case 36 :
V_15 |= V_985 ;
break;
default:
F_145 () ;
}
if ( V_81 -> V_91 -> V_903 )
V_15 |= V_986 | V_987 ;
F_123 ( F_673 ( V_81 -> V_95 ) , V_15 ) ;
}
}
int F_558 ( int V_85 , int V_729 , int V_988 )
{
T_1 V_989 = V_85 * V_988 * 21 / 20 ;
return F_216 ( V_989 , V_729 * 8 ) ;
}
static bool F_674 ( struct V_45 * V_45 , int V_990 )
{
return F_29 ( V_45 ) < V_990 * V_45 -> V_51 ;
}
static void F_675 ( struct V_81 * V_81 ,
struct V_37 * V_62 ,
struct V_45 * V_808 )
{
struct V_87 * V_65 = & V_81 -> V_64 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 , V_809 , V_810 ;
int V_990 ;
V_990 = 21 ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( ( F_595 ( V_6 ) &&
V_6 -> V_805 . V_914 == 100000 ) ||
( F_119 ( V_57 ) && F_39 ( V_57 ) ) )
V_990 = 25 ;
} else if ( V_62 -> V_874 )
V_990 = 20 ;
V_809 = F_597 ( & V_62 -> V_45 ) ;
if ( F_674 ( & V_62 -> V_45 , V_990 ) )
V_809 |= V_991 ;
if ( V_808 ) {
V_810 = F_597 ( V_808 ) ;
if ( V_808 -> V_46 < V_990 * V_808 -> V_51 )
V_810 |= V_991 ;
} else {
V_810 = V_809 ;
}
V_45 = 0 ;
if ( F_38 ( V_62 , V_66 ) )
V_45 |= V_862 ;
else
V_45 |= V_863 ;
V_45 |= ( V_62 -> V_590 - 1 )
<< V_992 ;
if ( F_38 ( V_62 , V_216 ) ||
F_38 ( V_62 , V_211 ) )
V_45 |= V_865 ;
if ( F_387 ( V_62 ) )
V_45 |= V_865 ;
if ( F_58 ( V_6 ) -> V_727 == 3 &&
F_38 ( V_62 , V_616 ) )
V_45 |= V_865 ;
V_45 |= ( 1 << ( V_62 -> V_45 . V_49 - 1 ) ) << V_867 ;
V_45 |= ( 1 << ( V_62 -> V_45 . V_49 - 1 ) ) << V_868 ;
switch ( V_62 -> V_45 . V_50 ) {
case 5 :
V_45 |= V_869 ;
break;
case 7 :
V_45 |= V_870 ;
break;
case 10 :
V_45 |= V_871 ;
break;
case 14 :
V_45 |= V_872 ;
break;
}
if ( F_38 ( V_62 , V_66 ) &&
F_595 ( V_6 ) )
V_45 |= V_876 ;
else
V_45 |= V_877 ;
V_45 |= V_106 ;
V_62 -> V_176 . V_45 = V_45 ;
V_62 -> V_176 . V_715 = V_809 ;
V_62 -> V_176 . V_716 = V_810 ;
}
static int F_676 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_45 V_808 ;
bool V_993 = false ;
struct V_994 * V_995 ;
const struct V_58 * V_59 ;
int V_44 = 120000 ;
memset ( & V_62 -> V_176 , 0 ,
sizeof( V_62 -> V_176 ) ) ;
V_65 -> V_811 = false ;
if ( ! V_62 -> V_226 )
return 0 ;
if ( F_38 ( V_62 , V_66 ) ) {
if ( F_595 ( V_6 ) ) {
F_158 ( L_133 ,
V_6 -> V_805 . V_914 ) ;
V_44 = V_6 -> V_805 . V_914 ;
}
if ( F_39 ( V_57 ) ) {
if ( V_44 == 100000 )
V_59 = & V_996 ;
else
V_59 = & V_997 ;
} else {
if ( V_44 == 100000 )
V_59 = & V_998 ;
else
V_59 = & V_999 ;
}
} else {
V_59 = & V_1000 ;
}
if ( ! V_62 -> V_918 &&
! F_42 ( V_59 , V_62 , V_62 -> V_39 ,
V_44 , NULL , & V_62 -> V_45 ) ) {
F_126 ( L_134 ) ;
return - V_288 ;
}
F_675 ( V_65 , V_62 ,
V_993 ? & V_808 : NULL ) ;
V_995 = F_677 ( V_65 , V_62 , NULL ) ;
if ( V_995 == NULL ) {
F_20 ( L_146 ,
F_77 ( V_65 -> V_95 ) ) ;
return - V_288 ;
}
if ( F_38 ( V_62 , V_66 ) &&
V_993 )
V_65 -> V_811 = true ;
return 0 ;
}
static void F_678 ( struct V_81 * V_65 ,
struct V_797 * V_798 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
V_798 -> V_802 = F_11 ( F_605 ( V_95 ) ) ;
V_798 -> V_803 = F_11 ( F_606 ( V_95 ) ) ;
V_798 -> V_800 = F_11 ( F_602 ( V_95 ) )
& ~ V_516 ;
V_798 -> V_801 = F_11 ( F_604 ( V_95 ) ) ;
V_798 -> V_799 = ( ( F_11 ( F_602 ( V_95 ) )
& V_516 ) >> V_1001 ) + 1 ;
}
static void F_679 ( struct V_81 * V_65 ,
enum V_94 V_94 ,
struct V_797 * V_798 ,
struct V_797 * V_814 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 = V_65 -> V_95 ;
if ( F_58 ( V_57 ) -> V_103 >= 5 ) {
V_798 -> V_802 = F_11 ( F_608 ( V_94 ) ) ;
V_798 -> V_803 = F_11 ( F_609 ( V_94 ) ) ;
V_798 -> V_800 = F_11 ( F_382 ( V_94 ) )
& ~ V_516 ;
V_798 -> V_801 = F_11 ( F_607 ( V_94 ) ) ;
V_798 -> V_799 = ( ( F_11 ( F_382 ( V_94 ) )
& V_516 ) >> V_1001 ) + 1 ;
if ( V_814 && F_58 ( V_57 ) -> V_103 < 8 &&
V_65 -> V_91 -> V_815 ) {
V_814 -> V_802 = F_11 ( F_612 ( V_94 ) ) ;
V_814 -> V_803 = F_11 ( F_613 ( V_94 ) ) ;
V_814 -> V_800 = F_11 ( F_610 ( V_94 ) )
& ~ V_516 ;
V_814 -> V_801 = F_11 ( F_611 ( V_94 ) ) ;
V_814 -> V_799 = ( ( F_11 ( F_610 ( V_94 ) )
& V_516 ) >> V_1001 ) + 1 ;
}
} else {
V_798 -> V_802 = F_11 ( F_616 ( V_95 ) ) ;
V_798 -> V_803 = F_11 ( F_617 ( V_95 ) ) ;
V_798 -> V_800 = F_11 ( F_614 ( V_95 ) )
& ~ V_516 ;
V_798 -> V_801 = F_11 ( F_615 ( V_95 ) ) ;
V_798 -> V_799 = ( ( F_11 ( F_614 ( V_95 ) )
& V_516 ) >> V_1001 ) + 1 ;
}
}
void F_680 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
if ( V_38 -> V_226 )
F_678 ( V_65 , & V_38 -> V_817 ) ;
else
F_679 ( V_65 , V_38 -> V_97 ,
& V_38 -> V_817 ,
& V_38 -> V_818 ) ;
}
static void F_681 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
F_679 ( V_65 , V_38 -> V_97 ,
& V_38 -> V_587 , NULL ) ;
}
static void F_682 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_378 * V_379 = & V_38 -> V_379 ;
T_2 V_416 = 0 ;
int V_377 = - 1 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_65 -> V_380 ; V_139 ++ ) {
V_416 = F_11 ( F_265 ( V_65 -> V_95 , V_139 ) ) ;
if ( V_416 & V_417 && ! ( V_416 & V_1002 ) ) {
V_377 = V_139 ;
V_38 -> V_445 . V_148 = true ;
V_38 -> V_445 . V_549 = F_11 ( F_266 ( V_65 -> V_95 , V_139 ) ) ;
V_38 -> V_445 . V_244 = F_11 ( F_267 ( V_65 -> V_95 , V_139 ) ) ;
break;
}
}
V_379 -> V_407 = V_377 ;
if ( V_377 >= 0 ) {
V_379 -> V_534 |= ( 1 << V_543 ) ;
} else {
V_379 -> V_534 &= ~ ( 1 << V_543 ) ;
}
}
static void
F_683 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_275 , V_1003 , V_328 ;
int V_95 = V_65 -> V_95 ;
int V_931 , V_241 ;
unsigned int V_932 ;
struct V_248 * V_90 ;
struct V_266 * V_267 ;
V_267 = F_552 ( sizeof( * V_267 ) , V_724 ) ;
if ( ! V_267 ) {
F_158 ( L_135 ) ;
return;
}
V_90 = & V_267 -> V_64 ;
V_15 = F_11 ( F_93 ( V_95 , 0 ) ) ;
if ( ! ( V_15 & V_144 ) )
goto error;
V_241 = V_15 & V_1004 ;
V_931 = F_219 ( V_241 ,
V_15 & V_384 ,
V_15 & V_1005 ) ;
V_90 -> V_241 = V_931 ;
V_90 -> V_793 = F_174 ( V_931 , 0 ) * 8 ;
V_328 = V_15 & V_1006 ;
switch ( V_328 ) {
case V_1007 :
V_90 -> V_260 [ 0 ] = V_233 ;
break;
case V_395 :
V_319 -> V_328 = V_281 ;
V_90 -> V_260 [ 0 ] = V_234 ;
break;
case V_396 :
V_90 -> V_260 [ 0 ] = V_235 ;
break;
case V_397 :
V_90 -> V_260 [ 0 ] = V_236 ;
break;
default:
F_170 ( V_328 ) ;
goto error;
}
V_64 = F_11 ( F_282 ( V_95 , 0 ) ) & 0xfffff000 ;
V_319 -> V_64 = V_64 ;
V_275 = F_11 ( F_276 ( V_95 , 0 ) ) ;
V_15 = F_11 ( F_278 ( V_95 , 0 ) ) ;
V_90 -> V_240 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_245 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_11 ( F_277 ( V_95 , 0 ) ) ;
V_1003 = F_262 ( V_6 , V_90 -> V_260 [ 0 ] ,
V_90 -> V_241 ) ;
V_90 -> V_262 [ 0 ] = ( V_15 & 0x3ff ) * V_1003 ;
V_932 = F_173 ( V_57 , V_90 -> V_240 ,
V_90 -> V_241 ,
V_90 -> V_260 [ 0 ] ) ;
V_319 -> V_244 = V_90 -> V_262 [ 0 ] * V_932 ;
F_158 ( L_147 ,
F_77 ( V_95 ) , V_90 -> V_245 , V_90 -> V_240 ,
V_90 -> V_793 , V_64 , V_90 -> V_262 [ 0 ] ,
V_319 -> V_244 ) ;
V_319 -> V_90 = V_267 ;
return;
error:
F_232 ( V_267 ) ;
}
static void F_684 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_181 ;
V_181 = F_11 ( F_394 ( V_65 -> V_95 ) ) ;
if ( V_181 & V_550 ) {
V_38 -> V_445 . V_148 = true ;
V_38 -> V_445 . V_549 = F_11 ( F_396 ( V_65 -> V_95 ) ) ;
V_38 -> V_445 . V_244 = F_11 ( F_397 ( V_65 -> V_95 ) ) ;
if ( F_685 ( V_57 ) ) {
F_28 ( ( V_181 & V_1008 ) !=
F_395 ( V_65 -> V_95 ) ) ;
}
}
}
static void
F_686 ( struct V_81 * V_65 ,
struct V_318 * V_319 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 , V_64 , V_275 ;
int V_95 = V_65 -> V_95 ;
int V_931 , V_241 ;
unsigned int V_932 ;
struct V_248 * V_90 ;
struct V_266 * V_267 ;
V_15 = F_11 ( F_87 ( V_95 ) ) ;
if ( ! ( V_15 & V_138 ) )
return;
V_267 = F_552 ( sizeof( * V_267 ) , V_724 ) ;
if ( ! V_267 ) {
F_158 ( L_135 ) ;
return;
}
V_90 = & V_267 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( V_15 & V_369 ) {
V_319 -> V_328 = V_281 ;
V_90 -> V_260 [ 0 ] = V_234 ;
}
}
V_241 = V_15 & V_933 ;
V_931 = F_218 ( V_241 ) ;
V_90 -> V_241 = V_931 ;
V_90 -> V_793 = F_174 ( V_931 , 0 ) * 8 ;
V_64 = F_11 ( F_252 ( V_95 ) ) & 0xfffff000 ;
if ( F_259 ( V_57 ) || F_260 ( V_57 ) ) {
V_275 = F_11 ( F_261 ( V_95 ) ) ;
} else {
if ( V_319 -> V_328 )
V_275 = F_11 ( F_254 ( V_95 ) ) ;
else
V_275 = F_11 ( F_255 ( V_95 ) ) ;
}
V_319 -> V_64 = V_64 ;
V_15 = F_11 ( F_320 ( V_95 ) ) ;
V_90 -> V_245 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_90 -> V_240 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_11 ( F_251 ( V_95 ) ) ;
V_90 -> V_262 [ 0 ] = V_15 & 0xffffffc0 ;
V_932 = F_173 ( V_57 , V_90 -> V_240 ,
V_90 -> V_241 ,
V_90 -> V_260 [ 0 ] ) ;
V_319 -> V_244 = V_90 -> V_262 [ 0 ] * V_932 ;
F_158 ( L_147 ,
F_77 ( V_95 ) , V_90 -> V_245 , V_90 -> V_240 ,
V_90 -> V_793 , V_64 , V_90 -> V_262 [ 0 ] ,
V_319 -> V_244 ) ;
V_319 -> V_90 = V_267 ;
}
static bool F_687 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_131 V_132 ;
T_2 V_181 ;
bool V_362 ;
V_132 = F_466 ( V_65 -> V_95 ) ;
if ( ! F_84 ( V_6 , V_132 ) )
return false ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_38 -> V_208 = NULL ;
V_362 = false ;
V_181 = F_11 ( F_59 ( V_65 -> V_95 ) ) ;
if ( ! ( V_181 & V_136 ) )
goto V_939;
switch ( V_181 & V_210 ) {
case V_906 :
V_38 -> V_732 = 18 ;
break;
case V_212 :
V_38 -> V_732 = 24 ;
break;
case V_907 :
V_38 -> V_732 = 30 ;
break;
case V_981 :
V_38 -> V_732 = 36 ;
break;
default:
break;
}
if ( V_181 & V_913 )
V_38 -> V_912 = true ;
if ( F_11 ( F_103 ( V_65 -> V_95 ) ) & V_149 ) {
struct V_994 * V_995 ;
enum V_1009 V_1010 ;
V_38 -> V_226 = true ;
V_181 = F_11 ( F_71 ( V_65 -> V_95 ) ) ;
V_38 -> V_459 = ( ( V_458 & V_181 ) >>
V_1011 ) + 1 ;
F_681 ( V_65 , V_38 ) ;
if ( F_119 ( V_6 ) ) {
V_1010 = (enum V_1009 ) V_65 -> V_95 ;
} else {
V_181 = F_11 ( V_519 ) ;
if ( V_181 & F_384 ( V_65 -> V_95 ) )
V_1010 = V_520 ;
else
V_1010 = V_1012 ;
}
V_38 -> V_208 =
F_385 ( V_6 , V_1010 ) ;
V_995 = V_38 -> V_208 ;
F_28 ( ! V_995 -> V_1013 . V_722 ( V_6 , V_995 ,
& V_38 -> V_176 ) ) ;
V_181 = V_38 -> V_176 . V_45 ;
V_38 -> V_590 =
( ( V_181 & V_1014 )
>> V_992 ) + 1 ;
F_688 ( V_65 , V_38 ) ;
} else {
V_38 -> V_590 = 1 ;
}
F_640 ( V_65 , V_38 ) ;
F_641 ( V_65 , V_38 ) ;
F_684 ( V_65 , V_38 ) ;
V_362 = true ;
V_939:
F_85 ( V_6 , V_132 ) ;
return V_362 ;
}
static void F_689 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_81 * V_65 ;
F_137 (dev, crtc)
F_64 ( V_65 -> V_88 , L_148 ,
F_77 ( V_65 -> V_95 ) ) ;
F_64 ( F_11 ( V_1015 ) , L_149 ) ;
F_64 ( F_11 ( V_1016 ) & V_1017 , L_150 ) ;
F_64 ( F_11 ( F_690 ( 0 ) ) & V_1018 , L_151 ) ;
F_64 ( F_11 ( F_690 ( 1 ) ) & V_1018 , L_152 ) ;
F_64 ( F_11 ( F_691 ( 0 ) ) & V_1019 , L_153 ) ;
F_64 ( F_11 ( V_1020 ) & V_1021 ,
L_154 ) ;
if ( F_259 ( V_57 ) )
F_64 ( F_11 ( V_1022 ) & V_1021 ,
L_155 ) ;
F_64 ( F_11 ( V_1023 ) & V_1024 ,
L_156 ) ;
F_64 ( F_11 ( V_1025 ) & V_1026 ,
L_157 ) ;
F_64 ( F_11 ( V_1027 ) & V_1028 , L_158 ) ;
F_64 ( F_692 ( V_6 ) , L_159 ) ;
}
static T_2 F_693 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
if ( F_259 ( V_57 ) )
return F_11 ( V_1029 ) ;
else
return F_11 ( V_1030 ) ;
}
static void F_694 ( struct V_5 * V_6 , T_2 V_15 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
if ( F_259 ( V_57 ) ) {
F_3 ( & V_6 -> V_553 . V_554 ) ;
if ( F_400 ( V_6 , V_1031 ,
V_15 ) )
F_158 ( L_160 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
} else {
F_123 ( V_1030 , V_15 ) ;
F_124 ( V_1030 ) ;
}
}
static void F_695 ( struct V_5 * V_6 ,
bool V_1032 , bool V_1033 )
{
T_2 V_15 ;
F_689 ( V_6 ) ;
V_15 = F_11 ( V_739 ) ;
if ( V_1032 ) {
V_15 |= V_742 ;
F_123 ( V_739 , V_15 ) ;
if ( F_664 ( F_11 ( V_739 ) &
V_1034 , 1 ) )
F_126 ( L_161 ) ;
V_15 = F_11 ( V_739 ) ;
}
V_15 |= V_1035 ;
F_123 ( V_739 , V_15 ) ;
F_124 ( V_739 ) ;
if ( F_60 ( V_6 , V_739 , V_666 , 0 , 1 ) )
F_126 ( L_162 ) ;
V_15 = F_693 ( V_6 ) ;
V_15 |= V_1036 ;
F_694 ( V_6 , V_15 ) ;
F_696 ( 100 ) ;
if ( F_61 ( ( F_693 ( V_6 ) & V_1037 ) == 0 ,
1 ) )
F_126 ( L_163 ) ;
if ( V_1033 ) {
V_15 = F_11 ( V_739 ) ;
V_15 |= V_1038 ;
F_123 ( V_739 , V_15 ) ;
F_124 ( V_739 ) ;
}
}
static void F_697 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_11 ( V_739 ) ;
if ( ( V_15 & ( V_666 | V_1035 | V_742 |
V_1038 ) ) == V_666 )
return;
F_698 ( V_6 , V_1039 ) ;
if ( V_15 & V_1038 ) {
V_15 &= ~ V_1038 ;
F_123 ( V_739 , V_15 ) ;
F_124 ( V_739 ) ;
}
V_15 = F_693 ( V_6 ) ;
V_15 |= V_1040 ;
V_15 &= ~ V_1036 ;
F_694 ( V_6 , V_15 ) ;
V_15 = F_11 ( V_739 ) ;
V_15 &= ~ V_1035 ;
F_123 ( V_739 , V_15 ) ;
if ( F_60 ( V_6 ,
V_739 , V_666 , V_666 ,
5 ) )
F_126 ( L_164 ) ;
if ( V_15 & V_742 ) {
V_15 = F_11 ( V_739 ) ;
V_15 &= ~ V_742 ;
F_123 ( V_739 , V_15 ) ;
if ( F_664 ( ( F_11 ( V_739 ) &
V_1034 ) == 0 , 1 ) )
F_126 ( L_165 ) ;
}
F_699 ( V_6 , V_1039 ) ;
F_480 ( & V_6 -> V_114 ) ;
}
void F_700 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_2 V_15 ;
F_158 ( L_166 ) ;
if ( F_667 ( V_57 ) ) {
V_15 = F_11 ( V_1041 ) ;
V_15 &= ~ V_1042 ;
F_123 ( V_1041 , V_15 ) ;
}
F_668 ( V_57 ) ;
F_695 ( V_6 , true , true ) ;
}
void F_701 ( struct V_5 * V_6 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
T_2 V_15 ;
F_158 ( L_167 ) ;
F_697 ( V_6 ) ;
F_671 ( V_57 ) ;
if ( F_667 ( V_57 ) ) {
V_15 = F_11 ( V_1041 ) ;
V_15 |= V_1042 ;
F_123 ( V_1041 , V_15 ) ;
}
}
static void F_702 ( struct V_422 * V_563 )
{
struct V_56 * V_57 = V_563 -> V_57 ;
struct V_700 * V_711 =
F_293 ( V_563 ) ;
unsigned int V_712 = V_711 -> V_703 ;
F_486 ( F_53 ( V_57 ) , V_712 ) ;
}
static int F_703 ( struct V_37 * V_62 ,
int V_1043 )
{
struct V_5 * V_6 = F_53 ( V_62 -> V_64 . V_65 -> V_57 ) ;
if ( F_260 ( V_6 ) && V_62 -> V_552 )
V_1043 = F_216 ( V_1043 * 100 , 95 ) ;
if ( F_387 ( V_62 ) &&
V_62 -> V_1044 &&
V_62 -> V_39 >= 540000 &&
V_62 -> V_1045 == 4 )
V_1043 = V_61 ( 432000 , V_1043 ) ;
return V_1043 ;
}
static int F_520 ( struct V_422 * V_43 )
{
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_1046 ;
struct V_37 * V_62 ;
unsigned V_1047 = 0 , V_139 ;
enum V_95 V_95 ;
memcpy ( V_338 -> V_701 , V_6 -> V_701 ,
sizeof( V_338 -> V_701 ) ) ;
F_292 (state, crtc, cstate, i) {
int V_1043 ;
V_62 = F_288 ( V_1046 ) ;
if ( ! V_62 -> V_64 . V_508 ) {
V_338 -> V_701 [ V_139 ] = 0 ;
continue;
}
V_1043 = F_561 ( V_62 ) ;
if ( F_260 ( V_6 ) || F_704 ( V_6 ) )
V_1043 = F_703 ( V_62 ,
V_1043 ) ;
V_338 -> V_701 [ V_139 ] = V_1043 ;
}
F_90 (dev_priv, pipe)
V_1047 = V_61 ( V_338 -> V_701 [ V_95 ] , V_1047 ) ;
return V_1047 ;
}
static void F_705 ( struct V_56 * V_57 , int V_644 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_2 V_15 , V_1048 ;
int V_362 ;
if ( F_7 ( ( F_11 ( V_739 ) &
( V_1035 | V_666 |
V_1049 | V_1050 |
V_1051 | V_1038 |
V_742 ) ) != V_666 ,
L_168 ) )
return;
F_3 ( & V_6 -> V_553 . V_554 ) ;
V_362 = F_400 ( V_6 ,
V_1052 , 0x0 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
if ( V_362 ) {
F_126 ( L_169 ) ;
return;
}
V_15 = F_11 ( V_739 ) ;
V_15 |= V_742 ;
F_123 ( V_739 , V_15 ) ;
if ( F_664 ( F_11 ( V_739 ) &
V_1034 , 1 ) )
F_126 ( L_161 ) ;
V_15 = F_11 ( V_739 ) ;
V_15 &= ~ V_741 ;
switch ( V_644 ) {
case 450000 :
V_15 |= V_743 ;
V_1048 = 0 ;
break;
case 540000 :
V_15 |= V_744 ;
V_1048 = 1 ;
break;
case 337500 :
V_15 |= V_745 ;
V_1048 = 2 ;
break;
case 675000 :
V_15 |= V_1053 ;
V_1048 = 3 ;
break;
default:
F_7 ( 1 , L_170 ) ;
return;
}
F_123 ( V_739 , V_15 ) ;
V_15 = F_11 ( V_739 ) ;
V_15 &= ~ V_742 ;
F_123 ( V_739 , V_15 ) ;
if ( F_664 ( ( F_11 ( V_739 ) &
V_1034 ) == 0 , 1 ) )
F_126 ( L_165 ) ;
F_3 ( & V_6 -> V_553 . V_554 ) ;
F_400 ( V_6 , V_655 , V_1048 ) ;
F_5 ( & V_6 -> V_553 . V_554 ) ;
F_123 ( V_1054 , F_8 ( V_644 , 1000 ) - 1 ) ;
F_480 ( V_57 ) ;
F_7 ( V_644 != V_6 -> V_638 ,
L_171 ,
V_644 , V_6 -> V_638 ) ;
}
static int F_706 ( int V_663 )
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
static int F_707 ( struct V_422 * V_43 )
{
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_700 * V_338 = F_293 ( V_43 ) ;
int V_663 = F_520 ( V_43 ) ;
int V_644 ;
V_644 = F_706 ( V_663 ) ;
if ( V_644 > V_6 -> V_628 ) {
F_158 ( L_172 ,
V_644 , V_6 -> V_628 ) ;
return - V_288 ;
}
V_338 -> V_644 = V_338 -> V_703 = V_644 ;
if ( ! V_338 -> V_704 )
V_338 -> V_703 = F_706 ( 0 ) ;
return 0 ;
}
static void F_708 ( struct V_422 * V_563 )
{
struct V_56 * V_57 = V_563 -> V_57 ;
struct V_700 * V_711 =
F_293 ( V_563 ) ;
unsigned V_712 = V_711 -> V_703 ;
F_705 ( V_57 , V_712 ) ;
}
static int F_709 ( struct V_422 * V_43 )
{
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
const int V_663 = F_520 ( V_43 ) ;
int V_52 = V_338 -> V_1055 ;
int V_644 ;
V_644 = F_477 ( V_663 , V_52 ) ;
if ( V_644 > V_6 -> V_628 ) {
F_126 ( L_172 ,
V_644 , V_6 -> V_628 ) ;
V_644 = V_6 -> V_628 ;
}
V_338 -> V_644 = V_338 -> V_703 = V_644 ;
if ( ! V_338 -> V_704 )
V_338 -> V_703 = F_477 ( 0 , V_52 ) ;
return 0 ;
}
static void F_710 ( struct V_422 * V_563 )
{
struct V_5 * V_6 = F_53 ( V_563 -> V_57 ) ;
struct V_700 * V_338 = F_293 ( V_563 ) ;
unsigned int V_712 = V_338 -> V_703 ;
unsigned int V_1056 = V_338 -> V_1055 ;
F_504 ( V_6 , V_712 , V_1056 ) ;
}
static int F_711 ( struct V_81 * V_65 ,
struct V_37 * V_62 )
{
if ( ! F_38 ( V_62 , V_225 ) ) {
if ( ! F_712 ( V_65 , V_62 ) )
return - V_288 ;
}
V_65 -> V_811 = false ;
return 0 ;
}
static void F_713 ( struct V_5 * V_6 ,
enum V_180 V_180 ,
struct V_37 * V_38 )
{
enum V_1009 V_377 ;
switch ( V_180 ) {
case V_601 :
V_377 = V_1057 ;
break;
case V_200 :
V_377 = V_1058 ;
break;
case V_202 :
V_377 = V_1059 ;
break;
default:
F_126 ( L_173 ) ;
return;
}
V_38 -> V_208 = F_385 ( V_6 , V_377 ) ;
}
static void F_714 ( struct V_5 * V_6 ,
enum V_180 V_180 ,
struct V_37 * V_38 )
{
enum V_1009 V_377 ;
T_1 V_446 ;
V_446 = F_11 ( V_1060 ) & F_715 ( V_180 ) ;
V_377 = V_446 >> ( V_180 * 3 + 1 ) ;
if ( F_28 ( V_377 < V_668 || V_377 > V_1061 ) )
return;
V_38 -> V_208 = F_385 ( V_6 , V_377 ) ;
}
static void F_716 ( struct V_5 * V_6 ,
enum V_180 V_180 ,
struct V_37 * V_38 )
{
enum V_1009 V_377 ;
T_2 V_1062 = F_11 ( F_717 ( V_180 ) ) ;
switch ( V_1062 ) {
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
case V_1073 :
V_377 = V_1074 ;
break;
default:
F_170 ( V_1062 ) ;
case V_1075 :
return;
}
V_38 -> V_208 = F_385 ( V_6 , V_377 ) ;
}
static bool F_718 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1076 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_131 V_132 ;
T_1 V_181 ;
V_38 -> V_97 = (enum V_94 ) V_65 -> V_95 ;
V_181 = F_11 ( F_68 ( V_589 ) ) ;
if ( V_181 & V_109 ) {
enum V_95 V_1077 ;
switch ( V_181 & V_1078 ) {
default:
F_7 ( 1 , L_174 ) ;
case V_1079 :
case V_1080 :
V_1077 = V_117 ;
break;
case V_1081 :
V_1077 = V_124 ;
break;
case V_1082 :
V_1077 = V_511 ;
break;
}
if ( V_1077 == V_65 -> V_95 )
V_38 -> V_97 = V_589 ;
}
V_132 = F_83 ( V_38 -> V_97 ) ;
if ( ! F_84 ( V_6 , V_132 ) )
return false ;
* V_1076 |= F_465 ( V_132 ) ;
V_181 = F_11 ( F_59 ( V_38 -> V_97 ) ) ;
return V_181 & V_136 ;
}
static bool F_719 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
unsigned long * V_1076 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_131 V_132 ;
enum V_180 V_180 ;
enum V_94 V_97 ;
T_1 V_181 ;
F_720 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_180 == V_601 )
V_97 = V_1083 ;
else
V_97 = V_1084 ;
V_132 = F_83 ( V_97 ) ;
if ( ! F_84 ( V_6 , V_132 ) )
continue;
* V_1076 |= F_465 ( V_132 ) ;
if ( ! F_721 ( V_6 ) )
break;
V_181 = F_11 ( F_722 ( V_180 ) ) ;
if ( ! ( V_181 & V_1085 ) )
continue;
V_181 = F_11 ( F_723 ( V_180 ) ) ;
if ( ( V_181 & V_1086 ) != F_724 ( V_65 -> V_95 ) )
continue;
V_38 -> V_97 = V_97 ;
break;
}
return F_443 ( V_38 -> V_97 ) ;
}
static void F_725 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_994 * V_995 ;
enum V_180 V_180 ;
T_2 V_181 ;
V_181 = F_11 ( F_68 ( V_38 -> V_97 ) ) ;
V_180 = ( V_181 & V_1087 ) >> V_1088 ;
if ( F_475 ( V_57 ) || F_476 ( V_57 ) )
F_714 ( V_6 , V_180 , V_38 ) ;
else if ( F_36 ( V_57 ) )
F_713 ( V_6 , V_180 , V_38 ) ;
else
F_716 ( V_6 , V_180 , V_38 ) ;
V_995 = V_38 -> V_208 ;
if ( V_995 ) {
F_28 ( ! V_995 -> V_1013 . V_722 ( V_6 , V_995 ,
& V_38 -> V_176 ) ) ;
}
if ( F_58 ( V_57 ) -> V_103 < 9 &&
( V_180 == V_606 ) && F_11 ( V_223 ) & V_149 ) {
V_38 -> V_226 = true ;
V_181 = F_11 ( F_71 ( V_117 ) ) ;
V_38 -> V_459 = ( ( V_458 & V_181 ) >>
V_1011 ) + 1 ;
F_681 ( V_65 , V_38 ) ;
}
}
static bool F_726 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_131 V_132 ;
unsigned long V_1076 ;
bool V_88 ;
V_132 = F_466 ( V_65 -> V_95 ) ;
if ( ! F_84 ( V_6 , V_132 ) )
return false ;
V_1076 = F_465 ( V_132 ) ;
V_38 -> V_208 = NULL ;
V_88 = F_718 ( V_65 , V_38 , & V_1076 ) ;
if ( F_36 ( V_6 ) &&
F_719 ( V_65 , V_38 , & V_1076 ) ) {
F_28 ( V_88 ) ;
V_88 = true ;
}
if ( ! V_88 )
goto V_939;
if ( ! F_443 ( V_38 -> V_97 ) ) {
F_725 ( V_65 , V_38 ) ;
F_640 ( V_65 , V_38 ) ;
}
F_641 ( V_65 , V_38 ) ;
V_38 -> V_1089 =
F_11 ( F_727 ( V_65 -> V_95 ) ) & V_1090 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
F_728 ( V_57 , V_65 , V_38 ) ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_38 -> V_379 . V_407 = - 1 ;
V_38 -> V_379 . V_534 &= ~ ( 1 << V_543 ) ;
}
V_132 = F_467 ( V_65 -> V_95 ) ;
if ( F_84 ( V_6 , V_132 ) ) {
V_1076 |= F_465 ( V_132 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
F_682 ( V_65 , V_38 ) ;
else
F_684 ( V_65 , V_38 ) ;
}
if ( F_259 ( V_57 ) )
V_38 -> V_552 = F_440 ( V_65 ) &&
( F_11 ( V_556 ) & V_557 ) ;
if ( V_38 -> V_97 != V_589 &&
! F_443 ( V_38 -> V_97 ) ) {
V_38 -> V_590 =
F_11 ( F_444 ( V_38 -> V_97 ) ) + 1 ;
} else {
V_38 -> V_590 = 1 ;
}
V_939:
F_470 (power_domain, power_domain_mask)
F_85 ( V_6 , V_132 ) ;
return V_88 ;
}
static void F_729 ( struct V_87 * V_65 , T_1 V_64 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1091 = 0 , V_244 = 0 ;
if ( V_336 && V_336 -> V_64 . V_340 ) {
unsigned int V_245 = V_336 -> V_64 . V_349 ;
unsigned int V_240 = V_336 -> V_64 . V_350 ;
unsigned int V_292 = F_730 ( V_245 ) * 4 ;
switch ( V_292 ) {
default:
F_350 ( 1 , L_175 ,
V_245 , V_292 ) ;
V_292 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1091 |= V_129 |
V_1092 |
V_1093 |
F_731 ( V_292 ) ;
V_244 = ( V_240 << 12 ) | V_245 ;
}
if ( V_81 -> V_1094 != 0 &&
( V_81 -> V_1095 != V_64 ||
V_81 -> V_1096 != V_244 ||
V_81 -> V_1094 != V_1091 ) ) {
F_123 ( F_81 ( V_117 ) , 0 ) ;
F_124 ( F_81 ( V_117 ) ) ;
V_81 -> V_1094 = 0 ;
}
if ( V_81 -> V_1095 != V_64 ) {
F_123 ( F_732 ( V_117 ) , V_64 ) ;
V_81 -> V_1095 = V_64 ;
}
if ( V_81 -> V_1096 != V_244 ) {
F_123 ( V_1097 , V_244 ) ;
V_81 -> V_1096 = V_244 ;
}
if ( V_81 -> V_1094 != V_1091 ) {
F_123 ( F_81 ( V_117 ) , V_1091 ) ;
F_124 ( F_81 ( V_117 ) ) ;
V_81 -> V_1094 = V_1091 ;
}
}
static void F_733 ( struct V_87 * V_65 , T_1 V_64 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
const struct V_402 * V_403 = & V_6 -> V_403 . V_404 ;
int V_95 = V_81 -> V_95 ;
T_2 V_1091 = 0 ;
if ( F_250 ( V_6 ) >= 9 && V_403 -> V_415 & F_274 ( V_65 ) )
F_734 ( V_81 , V_403 ) ;
if ( V_336 && V_336 -> V_64 . V_340 ) {
V_1091 = V_1098 ;
switch ( V_336 -> V_64 . V_349 ) {
case 64 :
V_1091 |= V_1099 ;
break;
case 128 :
V_1091 |= V_1100 ;
break;
case 256 :
V_1091 |= V_1101 ;
break;
default:
F_170 ( V_336 -> V_64 . V_349 ) ;
return;
}
V_1091 |= V_95 << 28 ;
if ( F_23 ( V_57 ) )
V_1091 |= V_1102 ;
if ( V_336 -> V_64 . V_249 == V_372 )
V_1091 |= V_1103 ;
}
if ( V_81 -> V_1094 != V_1091 ) {
F_123 ( F_81 ( V_95 ) , V_1091 ) ;
F_124 ( F_81 ( V_95 ) ) ;
V_81 -> V_1094 = V_1091 ;
}
F_123 ( F_732 ( V_95 ) , V_64 ) ;
F_124 ( F_732 ( V_95 ) ) ;
V_81 -> V_1095 = V_64 ;
}
static void F_735 ( struct V_87 * V_65 ,
const struct V_265 * V_336 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
int V_95 = V_81 -> V_95 ;
T_1 V_64 = V_81 -> V_1104 ;
T_1 V_549 = 0 ;
if ( V_336 ) {
int V_263 = V_336 -> V_64 . V_347 ;
int V_264 = V_336 -> V_64 . V_348 ;
if ( V_263 < 0 ) {
V_549 |= V_1105 << V_1106 ;
V_263 = - V_263 ;
}
V_549 |= V_263 << V_1106 ;
if ( V_264 < 0 ) {
V_549 |= V_1105 << V_1107 ;
V_264 = - V_264 ;
}
V_549 |= V_264 << V_1107 ;
if ( F_161 ( V_57 ) &&
V_336 -> V_64 . V_249 == V_372 ) {
V_64 += ( V_336 -> V_64 . V_350 *
V_336 -> V_64 . V_349 - 1 ) * 4 ;
}
}
F_123 ( F_736 ( V_95 ) , V_549 ) ;
if ( F_79 ( V_57 ) || F_80 ( V_57 ) )
F_729 ( V_65 , V_64 , V_336 ) ;
else
F_733 ( V_65 , V_64 , V_336 ) ;
}
static bool F_737 ( struct V_56 * V_57 ,
T_2 V_245 , T_2 V_240 )
{
if ( V_245 == 0 || V_240 == 0 )
return false ;
if ( F_79 ( V_57 ) || F_80 ( V_57 ) ) {
if ( ( V_245 & 63 ) != 0 )
return false ;
if ( V_245 > ( F_79 ( V_57 ) ? 64 : 512 ) )
return false ;
if ( V_240 > 1023 )
return false ;
} else {
switch ( V_245 | V_240 ) {
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
struct V_248 *
F_738 ( struct V_56 * V_57 ,
struct V_322 * V_323 ,
struct V_255 * V_256 )
{
struct V_266 * V_267 ;
int V_362 ;
V_267 = F_552 ( sizeof( * V_267 ) , V_724 ) ;
if ( ! V_267 )
return F_739 ( - V_723 ) ;
V_362 = F_224 ( V_57 , V_267 , V_323 , V_256 ) ;
if ( V_362 )
goto V_72;
return & V_267 -> V_64 ;
V_72:
F_232 ( V_267 ) ;
return F_739 ( V_362 ) ;
}
static struct V_248 *
F_740 ( struct V_56 * V_57 ,
struct V_322 * V_323 ,
struct V_255 * V_256 )
{
struct V_248 * V_90 ;
int V_362 ;
V_362 = F_741 ( V_57 ) ;
if ( V_362 )
return F_739 ( V_362 ) ;
V_90 = F_738 ( V_57 , V_323 , V_256 ) ;
F_5 ( & V_57 -> V_259 ) ;
return V_90 ;
}
static T_1
F_742 ( int V_245 , int V_988 )
{
T_1 V_261 = F_216 ( V_245 * V_988 , 8 ) ;
return F_175 ( V_261 , 64 ) ;
}
static T_1
F_743 ( struct V_521 * V_418 , int V_988 )
{
T_1 V_261 = F_742 ( V_418 -> V_892 , V_988 ) ;
return F_744 ( V_261 * V_418 -> V_891 ) ;
}
static struct V_248 *
F_745 ( struct V_56 * V_57 ,
struct V_521 * V_418 ,
int V_1108 , int V_988 )
{
struct V_248 * V_90 ;
struct V_255 * V_256 ;
struct V_322 V_323 = { 0 } ;
V_256 = F_746 ( V_57 ,
F_743 ( V_418 , V_988 ) ) ;
if ( F_191 ( V_256 ) )
return F_747 ( V_256 ) ;
V_323 . V_245 = V_418 -> V_892 ;
V_323 . V_240 = V_418 -> V_891 ;
V_323 . V_262 [ 0 ] = F_742 ( V_323 . V_245 ,
V_988 ) ;
V_323 . V_241 = F_748 ( V_988 , V_1108 ) ;
V_90 = F_740 ( V_57 , & V_323 , V_256 ) ;
if ( F_191 ( V_90 ) )
F_749 ( V_256 ) ;
return V_90 ;
}
static struct V_248 *
F_750 ( struct V_56 * V_57 ,
struct V_521 * V_418 )
{
#ifdef F_751
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_255 * V_256 ;
struct V_248 * V_90 ;
if ( ! V_6 -> V_1109 )
return NULL ;
if ( ! V_6 -> V_1109 -> V_90 )
return NULL ;
V_256 = V_6 -> V_1109 -> V_90 -> V_256 ;
F_662 ( ! V_256 ) ;
V_90 = & V_6 -> V_1109 -> V_90 -> V_64 ;
if ( V_90 -> V_262 [ 0 ] < F_742 ( V_418 -> V_892 ,
V_90 -> V_793 ) )
return NULL ;
if ( V_256 -> V_64 . V_244 < V_418 -> V_891 * V_90 -> V_262 [ 0 ] )
return NULL ;
F_228 ( V_90 ) ;
return V_90 ;
#else
return NULL ;
#endif
}
static int F_752 ( struct V_422 * V_43 ,
struct V_87 * V_65 ,
struct V_521 * V_418 ,
struct V_248 * V_90 ,
int V_263 , int V_264 )
{
struct V_335 * V_336 ;
int V_892 , V_891 ;
int V_362 ;
V_336 = F_753 ( V_43 , V_65 -> V_89 ) ;
if ( F_191 ( V_336 ) )
return F_302 ( V_336 ) ;
if ( V_418 )
F_754 ( V_418 , & V_892 , & V_891 ) ;
else
V_892 = V_891 = 0 ;
V_362 = F_755 ( V_336 , V_90 ? V_65 : NULL ) ;
if ( V_362 )
return V_362 ;
F_756 ( V_336 , V_90 ) ;
V_336 -> V_347 = 0 ;
V_336 -> V_348 = 0 ;
V_336 -> V_349 = V_892 ;
V_336 -> V_350 = V_891 ;
V_336 -> V_343 = V_263 << 16 ;
V_336 -> V_344 = V_264 << 16 ;
V_336 -> V_345 = V_892 << 16 ;
V_336 -> V_346 = V_891 << 16 ;
return 0 ;
}
bool F_757 ( struct V_577 * V_721 ,
struct V_521 * V_418 ,
struct V_1110 * V_1111 ,
struct V_426 * V_427 )
{
struct V_81 * V_81 ;
struct V_512 * V_512 =
F_758 ( V_721 ) ;
struct V_87 * V_1112 ;
struct V_619 * V_513 = & V_512 -> V_64 ;
struct V_87 * V_65 = NULL ;
struct V_56 * V_57 = V_513 -> V_57 ;
struct V_248 * V_90 ;
struct V_1113 * V_91 = & V_57 -> V_429 ;
struct V_422 * V_43 = NULL , * V_1114 = NULL ;
struct V_575 * V_1115 ;
struct V_37 * V_62 ;
int V_362 , V_139 = - 1 ;
F_158 ( L_176 ,
V_721 -> V_64 . V_377 , V_721 -> V_12 ,
V_513 -> V_64 . V_377 , V_513 -> V_12 ) ;
V_1111 -> V_1114 = NULL ;
V_464:
V_362 = F_759 ( & V_91 -> V_1116 , V_427 ) ;
if ( V_362 )
goto V_786;
if ( V_721 -> V_43 -> V_65 ) {
V_65 = V_721 -> V_43 -> V_65 ;
V_362 = F_759 ( & V_65 -> V_430 , V_427 ) ;
if ( V_362 )
goto V_786;
goto V_75;
}
F_233 (dev, possible_crtc) {
V_139 ++ ;
if ( ! ( V_513 -> V_1117 & ( 1 << V_139 ) ) )
continue;
V_362 = F_759 ( & V_1112 -> V_430 , V_427 ) ;
if ( V_362 )
goto V_786;
if ( V_1112 -> V_43 -> V_508 ) {
F_760 ( & V_1112 -> V_430 ) ;
continue;
}
V_65 = V_1112 ;
break;
}
if ( ! V_65 ) {
F_158 ( L_177 ) ;
goto V_786;
}
V_75:
V_81 = F_47 ( V_65 ) ;
V_362 = F_759 ( & V_65 -> V_89 -> V_430 , V_427 ) ;
if ( V_362 )
goto V_786;
V_43 = F_537 ( V_57 ) ;
V_1114 = F_537 ( V_57 ) ;
if ( ! V_43 || ! V_1114 ) {
V_362 = - V_723 ;
goto V_786;
}
V_43 -> V_434 = V_427 ;
V_1114 -> V_434 = V_427 ;
V_1115 = F_761 ( V_43 , V_721 ) ;
if ( F_191 ( V_1115 ) ) {
V_362 = F_302 ( V_1115 ) ;
goto V_786;
}
V_362 = F_762 ( V_1115 , V_65 ) ;
if ( V_362 )
goto V_786;
V_62 = F_538 ( V_43 , V_81 ) ;
if ( F_191 ( V_62 ) ) {
V_362 = F_302 ( V_62 ) ;
goto V_786;
}
V_62 -> V_64 . V_88 = V_62 -> V_64 . V_508 = true ;
if ( ! V_418 )
V_418 = & V_1118 ;
V_90 = F_750 ( V_57 , V_418 ) ;
if ( V_90 == NULL ) {
F_158 ( L_178 ) ;
V_90 = F_745 ( V_57 , V_418 , 24 , 32 ) ;
} else
F_158 ( L_179 ) ;
if ( F_191 ( V_90 ) ) {
F_158 ( L_180 ) ;
goto V_786;
}
V_362 = F_752 ( V_43 , V_65 , V_418 , V_90 , 0 , 0 ) ;
if ( V_362 )
goto V_786;
F_227 ( V_90 ) ;
V_362 = F_540 ( & V_62 -> V_64 , V_418 ) ;
if ( V_362 )
goto V_786;
V_362 = F_545 ( F_761 ( V_1114 , V_721 ) ) ;
if ( ! V_362 )
V_362 = F_545 ( F_763 ( V_1114 , V_65 ) ) ;
if ( ! V_362 )
V_362 = F_545 ( F_753 ( V_1114 , V_65 -> V_89 ) ) ;
if ( V_362 ) {
F_158 ( L_181 , V_362 ) ;
goto V_786;
}
V_362 = F_294 ( V_43 ) ;
if ( V_362 ) {
F_158 ( L_182 ) ;
goto V_786;
}
V_1111 -> V_1114 = V_1114 ;
F_341 ( V_57 , V_81 -> V_95 ) ;
return true ;
V_786:
F_304 ( V_43 ) ;
F_304 ( V_1114 ) ;
V_1114 = V_43 = NULL ;
if ( V_362 == - V_425 ) {
F_300 ( V_427 ) ;
goto V_464;
}
return false ;
}
void F_764 ( struct V_577 * V_721 ,
struct V_1110 * V_1111 ,
struct V_426 * V_427 )
{
struct V_512 * V_512 =
F_758 ( V_721 ) ;
struct V_619 * V_513 = & V_512 -> V_64 ;
struct V_422 * V_43 = V_1111 -> V_1114 ;
int V_362 ;
F_158 ( L_176 ,
V_721 -> V_64 . V_377 , V_721 -> V_12 ,
V_513 -> V_64 . V_377 , V_513 -> V_12 ) ;
if ( ! V_43 )
return;
V_362 = F_294 ( V_43 ) ;
if ( V_362 ) {
F_158 ( L_183 , V_362 ) ;
F_304 ( V_43 ) ;
}
}
static int F_765 ( struct V_56 * V_57 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_45 = V_38 -> V_176 . V_45 ;
if ( ( V_45 & V_951 ) == V_876 )
return V_6 -> V_805 . V_914 ;
else if ( F_15 ( V_57 ) )
return 120000 ;
else if ( ! F_55 ( V_57 ) )
return 96000 ;
else
return 48000 ;
}
static void F_658 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_95 = V_38 -> V_97 ;
T_1 V_45 = V_38 -> V_176 . V_45 ;
T_1 V_809 ;
struct V_45 clock ;
int V_39 ;
int V_44 = F_765 ( V_57 , V_38 ) ;
if ( ( V_45 & V_1119 ) == 0 )
V_809 = V_38 -> V_176 . V_715 ;
else
V_809 = V_38 -> V_176 . V_716 ;
clock . V_54 = ( V_809 & V_1120 ) >> V_1121 ;
if ( F_19 ( V_57 ) ) {
clock . V_51 = F_766 ( ( V_809 & V_1122 ) >> V_1123 ) - 1 ;
clock . V_47 = ( V_809 & V_1124 ) >> V_1125 ;
} else {
clock . V_51 = ( V_809 & V_1126 ) >> V_1123 ;
clock . V_47 = ( V_809 & V_1127 ) >> V_1125 ;
}
if ( ! F_55 ( V_57 ) ) {
if ( F_19 ( V_57 ) )
clock . V_49 = F_766 ( ( V_45 & V_1128 ) >>
V_866 ) ;
else
clock . V_49 = F_766 ( ( V_45 & V_1129 ) >>
V_867 ) ;
switch ( V_45 & V_1130 ) {
case V_863 :
clock . V_50 = V_45 & V_869 ?
5 : 10 ;
break;
case V_862 :
clock . V_50 = V_45 & V_870 ?
7 : 14 ;
break;
default:
F_158 ( L_184
L_185 , ( int ) ( V_45 & V_1130 ) ) ;
return;
}
if ( F_19 ( V_57 ) )
V_39 = F_27 ( V_44 , & clock ) ;
else
V_39 = F_30 ( V_44 , & clock ) ;
} else {
T_1 V_1131 = F_140 ( V_57 ) ? 0 : F_11 ( V_125 ) ;
bool V_1132 = ( V_95 == 1 ) && ( V_1131 & V_159 ) ;
if ( V_1132 ) {
clock . V_49 = F_766 ( ( V_45 & V_1133 ) >>
V_867 ) ;
if ( V_1131 & V_1134 )
clock . V_50 = 7 ;
else
clock . V_50 = 14 ;
} else {
if ( V_45 & V_878 )
clock . V_49 = 2 ;
else {
clock . V_49 = ( ( V_45 & V_1135 ) >>
V_867 ) + 2 ;
}
if ( V_45 & V_879 )
clock . V_50 = 4 ;
else
clock . V_50 = 2 ;
}
V_39 = F_30 ( V_44 , & clock ) ;
}
V_38 -> V_39 = V_39 ;
}
int F_767 ( int V_1136 ,
const struct V_797 * V_798 )
{
if ( ! V_798 -> V_803 )
return 0 ;
return F_45 ( ( V_1137 ) V_798 -> V_802 * V_1136 , V_798 -> V_803 ) ;
}
static void F_688 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
F_658 ( V_65 , V_38 ) ;
V_38 -> V_64 . V_92 . V_93 =
F_767 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_587 ) ;
}
struct V_521 * F_768 ( struct V_56 * V_57 ,
struct V_87 * V_65 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
enum V_94 V_97 = V_81 -> V_91 -> V_97 ;
struct V_521 * V_418 ;
struct V_37 * V_38 ;
int V_1138 = F_11 ( F_362 ( V_97 ) ) ;
int V_900 = F_11 ( F_366 ( V_97 ) ) ;
int V_1139 = F_11 ( F_368 ( V_97 ) ) ;
int V_1140 = F_11 ( F_372 ( V_97 ) ) ;
enum V_95 V_95 = V_81 -> V_95 ;
V_418 = F_552 ( sizeof( * V_418 ) , V_724 ) ;
if ( ! V_418 )
return NULL ;
V_38 = F_552 ( sizeof( * V_38 ) , V_724 ) ;
if ( ! V_38 ) {
F_232 ( V_418 ) ;
return NULL ;
}
V_38 -> V_97 = (enum V_94 ) V_95 ;
V_38 -> V_590 = 1 ;
V_38 -> V_176 . V_45 = F_11 ( F_63 ( V_95 ) ) ;
V_38 -> V_176 . V_715 = F_11 ( F_531 ( V_95 ) ) ;
V_38 -> V_176 . V_716 = F_11 ( F_532 ( V_95 ) ) ;
F_658 ( V_81 , V_38 ) ;
V_418 -> clock = V_38 -> V_39 / V_38 -> V_590 ;
V_418 -> V_892 = ( V_1138 & 0xffff ) + 1 ;
V_418 -> V_893 = ( ( V_1138 & 0xffff0000 ) >> 16 ) + 1 ;
V_418 -> V_894 = ( V_900 & 0xffff ) + 1 ;
V_418 -> V_895 = ( ( V_900 & 0xffff0000 ) >> 16 ) + 1 ;
V_418 -> V_891 = ( V_1139 & 0xffff ) + 1 ;
V_418 -> V_896 = ( ( V_1139 & 0xffff0000 ) >> 16 ) + 1 ;
V_418 -> V_897 = ( V_1140 & 0xffff ) + 1 ;
V_418 -> V_898 = ( ( V_1140 & 0xffff0000 ) >> 16 ) + 1 ;
F_645 ( V_418 ) ;
F_232 ( V_38 ) ;
return V_418 ;
}
static void F_769 ( struct V_87 * V_65 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_1 * V_2 ;
F_310 ( & V_57 -> V_442 ) ;
V_2 = V_81 -> V_443 ;
V_81 -> V_443 = NULL ;
F_311 ( & V_57 -> V_442 ) ;
if ( V_2 ) {
F_770 ( & V_2 -> V_3 ) ;
F_770 ( & V_2 -> V_483 ) ;
F_232 ( V_2 ) ;
}
F_771 ( V_65 ) ;
F_232 ( V_81 ) ;
}
static void F_772 ( struct V_1141 * V_1142 )
{
struct V_1 * V_2 =
F_773 ( V_1142 , struct V_1 , V_483 ) ;
struct V_81 * V_65 = F_47 ( V_2 -> V_65 ) ;
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_333 * V_89 = V_65 -> V_64 . V_89 ;
if ( F_1 ( V_2 ) )
F_774 ( & V_2 -> V_3 ) ;
F_3 ( & V_57 -> V_259 ) ;
F_196 ( V_2 -> V_1143 , V_89 -> V_43 -> V_249 ) ;
F_225 ( V_2 -> V_484 ) ;
F_5 ( & V_57 -> V_259 ) ;
F_775 ( V_2 -> V_1144 ) ;
F_776 ( F_53 ( V_57 ) ,
F_230 ( V_89 ) -> V_354 ) ;
F_414 ( V_65 ) ;
F_227 ( V_2 -> V_1143 ) ;
F_662 ( F_340 ( & V_65 -> V_479 ) == 0 ) ;
F_777 ( & V_65 -> V_479 ) ;
F_232 ( V_2 ) ;
}
static bool F_778 ( T_1 V_1145 , T_1 V_1146 )
{
return ! ( ( V_1145 - V_1146 ) & 0x80000000 ) ;
}
static bool F_779 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( F_315 ( V_65 ) )
return true ;
if ( F_58 ( V_57 ) -> V_103 < 5 && ! F_18 ( V_57 ) )
return true ;
return ( F_11 ( F_780 ( V_65 -> V_137 ) ) & ~ 0xfff ) ==
V_65 -> V_443 -> V_1147 &&
F_778 ( F_11 ( F_781 ( V_65 -> V_95 ) ) ,
V_65 -> V_443 -> V_1148 ) ;
}
static bool
F_782 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
return F_783 ( V_65 ) != V_2 -> V_1149 ;
}
static bool F_784 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
if ( ! F_340 ( & V_2 -> V_441 ) )
return false ;
F_785 () ;
if ( F_1 ( V_2 ) )
return F_782 ( V_65 , V_2 ) ;
else
return F_779 ( V_65 , V_2 ) ;
}
void F_286 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
unsigned long V_330 ;
if ( ! V_65 )
return;
F_786 ( & V_57 -> V_442 , V_330 ) ;
V_2 = V_81 -> V_443 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_784 ( V_81 , V_2 ) )
F_342 ( V_81 ) ;
F_787 ( & V_57 -> V_442 , V_330 ) ;
}
void F_788 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
unsigned long V_330 ;
if ( ! V_65 )
return;
F_786 ( & V_57 -> V_442 , V_330 ) ;
V_2 = V_81 -> V_443 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_784 ( V_81 , V_2 ) )
F_342 ( V_81 ) ;
F_787 ( & V_57 -> V_442 , V_330 ) ;
}
static inline void F_789 ( struct V_81 * V_65 ,
struct V_1 * V_2 )
{
V_2 -> V_1149 = F_783 ( V_65 ) ;
F_790 () ;
F_791 ( & V_2 -> V_441 , 1 ) ;
}
static int F_792 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
struct V_1152 * V_1153 = V_1151 -> V_1153 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_1 V_1154 ;
int V_362 ;
V_362 = F_793 ( V_1151 , 6 ) ;
if ( V_362 )
return V_362 ;
if ( V_81 -> V_137 )
V_1154 = V_1155 ;
else
V_1154 = V_1156 ;
F_794 ( V_1153 , V_1157 | V_1154 ) ;
F_794 ( V_1153 , V_1158 ) ;
F_794 ( V_1153 , V_1159 |
F_795 ( V_81 -> V_137 ) ) ;
F_794 ( V_1153 , V_90 -> V_262 [ 0 ] ) ;
F_794 ( V_1153 , V_81 -> V_443 -> V_1147 ) ;
F_794 ( V_1153 , 0 ) ;
return 0 ;
}
static int F_796 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
struct V_1152 * V_1153 = V_1151 -> V_1153 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_1 V_1154 ;
int V_362 ;
V_362 = F_793 ( V_1151 , 6 ) ;
if ( V_362 )
return V_362 ;
if ( V_81 -> V_137 )
V_1154 = V_1155 ;
else
V_1154 = V_1156 ;
F_794 ( V_1153 , V_1157 | V_1154 ) ;
F_794 ( V_1153 , V_1158 ) ;
F_794 ( V_1153 , V_1160 |
F_795 ( V_81 -> V_137 ) ) ;
F_794 ( V_1153 , V_90 -> V_262 [ 0 ] ) ;
F_794 ( V_1153 , V_81 -> V_443 -> V_1147 ) ;
F_794 ( V_1153 , V_1158 ) ;
return 0 ;
}
static int F_797 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
struct V_1152 * V_1153 = V_1151 -> V_1153 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1161 , V_1162 ;
int V_362 ;
V_362 = F_793 ( V_1151 , 4 ) ;
if ( V_362 )
return V_362 ;
F_794 ( V_1153 , V_1159 |
F_795 ( V_81 -> V_137 ) ) ;
F_794 ( V_1153 , V_90 -> V_262 [ 0 ] ) ;
F_794 ( V_1153 , V_81 -> V_443 -> V_1147 |
F_209 ( V_90 -> V_260 [ 0 ] ) ) ;
V_1161 = 0 ;
V_1162 = F_11 ( F_320 ( V_81 -> V_95 ) ) & 0x0fff0fff ;
F_794 ( V_1153 , V_1161 | V_1162 ) ;
return 0 ;
}
static int F_798 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
struct V_1152 * V_1153 = V_1151 -> V_1153 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1161 , V_1162 ;
int V_362 ;
V_362 = F_793 ( V_1151 , 4 ) ;
if ( V_362 )
return V_362 ;
F_794 ( V_1153 , V_1159 |
F_795 ( V_81 -> V_137 ) ) ;
F_794 ( V_1153 , V_90 -> V_262 [ 0 ] |
F_209 ( V_90 -> V_260 [ 0 ] ) ) ;
F_794 ( V_1153 , V_81 -> V_443 -> V_1147 ) ;
V_1161 = 0 ;
V_1162 = F_11 ( F_320 ( V_81 -> V_95 ) ) & 0x0fff0fff ;
F_794 ( V_1153 , V_1161 | V_1162 ) ;
return 0 ;
}
static int F_799 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
struct V_1152 * V_1153 = V_1151 -> V_1153 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
T_2 V_1163 = 0 ;
int V_1164 , V_362 ;
switch ( V_81 -> V_137 ) {
case V_1165 :
V_1163 = V_1166 ;
break;
case V_368 :
V_1163 = V_1167 ;
break;
case V_1168 :
V_1163 = V_1169 ;
break;
default:
F_350 ( 1 , L_186 ) ;
return - V_420 ;
}
V_1164 = 4 ;
if ( V_1151 -> V_1170 -> V_377 == V_1171 ) {
V_1164 += 6 ;
if ( F_800 ( V_57 ) )
V_1164 += 2 ;
}
V_362 = F_801 ( V_1151 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_793 ( V_1151 , V_1164 ) ;
if ( V_362 )
return V_362 ;
if ( V_1151 -> V_1170 -> V_377 == V_1171 ) {
F_794 ( V_1153 , F_802 ( 1 ) ) ;
F_803 ( V_1153 , V_1172 ) ;
F_794 ( V_1153 , ~ ( V_1173 |
V_1174 |
V_1175 ) ) ;
if ( F_800 ( V_57 ) )
F_794 ( V_1153 , V_1176 |
V_1177 ) ;
else
F_794 ( V_1153 , V_1178 |
V_1177 ) ;
F_803 ( V_1153 , V_1172 ) ;
F_794 ( V_1153 ,
F_263 ( V_1151 -> V_1170 -> V_1179 ) + 256 ) ;
if ( F_800 ( V_57 ) ) {
F_794 ( V_1153 , 0 ) ;
F_794 ( V_1153 , V_1158 ) ;
}
}
F_794 ( V_1153 , V_1160 | V_1163 ) ;
F_794 ( V_1153 , V_90 -> V_262 [ 0 ] |
F_209 ( V_90 -> V_260 [ 0 ] ) ) ;
F_794 ( V_1153 , V_81 -> V_443 -> V_1147 ) ;
F_794 ( V_1153 , ( V_1158 ) ) ;
return 0 ;
}
static bool F_804 ( struct V_1180 * V_1170 ,
struct V_255 * V_256 )
{
struct V_1181 * V_1182 ;
if ( V_1170 == NULL )
return true ;
if ( F_250 ( V_1170 -> V_431 ) < 5 )
return false ;
if ( V_431 . F_804 < 0 )
return false ;
else if ( V_431 . F_804 > 0 )
return true ;
else if ( V_431 . V_1183 )
return true ;
V_1182 = F_805 ( V_256 ) ;
if ( V_1182 && ! F_806 ( V_1182 , false ) )
return true ;
return V_1170 != F_807 ( & V_256 -> V_1184 ,
& V_256 -> V_64 . V_57 -> V_259 ) ;
}
static void F_808 ( struct V_81 * V_81 ,
unsigned int V_249 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_248 * V_90 = V_81 -> V_64 . V_89 -> V_90 ;
const enum V_95 V_95 = V_81 -> V_95 ;
T_1 V_1185 , V_292 = F_269 ( V_90 , 0 , V_249 ) ;
V_1185 = F_11 ( F_93 ( V_95 , 0 ) ) ;
V_1185 &= ~ V_1006 ;
switch ( V_90 -> V_260 [ 0 ] ) {
case V_233 :
break;
case V_234 :
V_1185 |= V_395 ;
break;
case V_235 :
V_1185 |= V_396 ;
break;
case V_236 :
V_1185 |= V_397 ;
break;
default:
F_170 ( V_90 -> V_260 [ 0 ] ) ;
}
F_123 ( F_93 ( V_95 , 0 ) , V_1185 ) ;
F_123 ( F_277 ( V_95 , 0 ) , V_292 ) ;
F_123 ( F_282 ( V_95 , 0 ) , V_2 -> V_1147 ) ;
F_124 ( F_282 ( V_95 , 0 ) ) ;
}
static void F_809 ( struct V_81 * V_81 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 = V_81 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_248 * V_90 = V_81 -> V_64 . V_89 -> V_90 ;
T_3 V_13 = F_87 ( V_81 -> V_137 ) ;
T_1 V_363 ;
V_363 = F_11 ( V_13 ) ;
if ( V_90 -> V_260 [ 0 ] == V_234 )
V_363 |= V_369 ;
else
V_363 &= ~ V_369 ;
F_123 ( V_13 , V_363 ) ;
F_123 ( F_252 ( V_81 -> V_137 ) , V_2 -> V_1147 ) ;
F_124 ( F_252 ( V_81 -> V_137 ) ) ;
}
static void F_810 ( struct V_1141 * V_356 )
{
struct V_1 * V_2 =
F_773 ( V_356 , struct V_1 , V_3 ) ;
struct V_81 * V_65 = F_47 ( V_2 -> V_65 ) ;
struct V_5 * V_6 = F_53 ( V_65 -> V_64 . V_57 ) ;
struct V_266 * V_267 =
F_180 ( V_65 -> V_64 . V_89 -> V_90 ) ;
struct V_255 * V_256 = V_267 -> V_256 ;
struct V_1181 * V_1182 ;
if ( V_2 -> V_1144 )
F_28 ( F_811 ( V_2 -> V_1144 ,
0 , NULL , V_1186 ) ) ;
V_1182 = F_805 ( V_256 ) ;
if ( V_1182 )
F_28 ( F_812 ( V_1182 , false , false ,
V_1187 ) < 0 ) ;
F_813 ( V_65 ) ;
if ( F_250 ( V_6 ) >= 9 )
F_808 ( V_65 , V_2 -> V_249 , V_2 ) ;
else
F_809 ( V_65 , V_2 ) ;
F_814 ( V_65 , V_2 ) ;
}
static int F_815 ( struct V_56 * V_57 ,
struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_255 * V_256 ,
struct V_1150 * V_1151 ,
T_2 V_330 )
{
return - V_420 ;
}
static bool F_816 ( struct V_5 * V_6 ,
struct V_81 * V_81 ,
struct V_1 * V_2 )
{
T_1 V_1188 , V_1189 ;
if ( ! F_340 ( & V_2 -> V_441 ) )
return false ;
F_785 () ;
V_1189 = F_783 ( V_81 ) ;
if ( V_2 -> V_1190 == 0 ) {
if ( V_2 -> V_1144 &&
! F_817 ( V_2 -> V_1144 ) )
return false ;
V_2 -> V_1190 = V_1189 ;
}
if ( V_1189 - V_2 -> V_1190 < 3 )
return false ;
if ( F_250 ( V_6 ) >= 4 )
V_1188 = F_818 ( F_11 ( F_252 ( V_81 -> V_137 ) ) ) ;
else
V_1188 = F_11 ( F_256 ( V_81 -> V_137 ) ) ;
return V_1188 == V_2 -> V_1147 ;
}
void F_819 ( struct V_5 * V_6 , int V_95 )
{
struct V_56 * V_57 = & V_6 -> V_114 ;
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_1 * V_2 ;
F_28 ( ! F_820 () ) ;
if ( V_65 == NULL )
return;
F_821 ( & V_57 -> V_442 ) ;
V_2 = V_81 -> V_443 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_816 ( V_6 , V_81 , V_2 ) ) {
F_350 ( 1 ,
L_187 ,
V_2 -> V_1149 , F_783 ( V_81 ) ) ;
F_342 ( V_81 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_783 ( V_81 ) - V_2 -> V_1149 > 1 )
F_822 ( V_2 -> V_1144 ) ;
F_823 ( & V_57 -> V_442 ) ;
}
static int F_824 ( struct V_87 * V_65 ,
struct V_248 * V_90 ,
struct V_1191 * V_480 ,
T_2 V_1192 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_248 * V_1143 = V_65 -> V_89 -> V_90 ;
struct V_255 * V_256 = F_186 ( V_90 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_333 * V_89 = V_65 -> V_89 ;
enum V_95 V_95 = V_81 -> V_95 ;
struct V_1 * V_2 ;
struct V_1180 * V_1170 ;
bool V_1193 ;
struct V_1150 * V_1194 ;
struct V_254 * V_257 ;
int V_362 ;
if ( F_28 ( F_186 ( V_1143 ) == NULL ) )
return - V_1195 ;
if ( V_90 -> V_241 != V_65 -> V_89 -> V_90 -> V_241 )
return - V_288 ;
if ( F_58 ( V_57 ) -> V_103 > 3 &&
( V_90 -> V_280 [ 0 ] != V_65 -> V_89 -> V_90 -> V_280 [ 0 ] ||
V_90 -> V_262 [ 0 ] != V_65 -> V_89 -> V_90 -> V_262 [ 0 ] ) )
return - V_288 ;
if ( F_825 ( & V_6 -> V_439 ) )
goto V_1196;
V_2 = F_552 ( sizeof( * V_2 ) , V_724 ) ;
if ( V_2 == NULL )
return - V_723 ;
V_2 -> V_480 = V_480 ;
V_2 -> V_65 = V_65 ;
V_2 -> V_1143 = V_1143 ;
F_826 ( & V_2 -> V_483 , F_772 ) ;
V_362 = F_100 ( V_65 ) ;
if ( V_362 )
goto V_1197;
F_310 ( & V_57 -> V_442 ) ;
if ( V_81 -> V_443 ) {
if ( F_784 ( V_81 , V_81 -> V_443 ) ) {
F_20 ( L_188 ) ;
F_342 ( V_81 ) ;
} else {
F_20 ( L_189 ) ;
F_311 ( & V_57 -> V_442 ) ;
F_101 ( V_65 ) ;
F_232 ( V_2 ) ;
return - V_1195 ;
}
}
V_81 -> V_443 = V_2 ;
F_311 ( & V_57 -> V_442 ) ;
if ( F_340 ( & V_81 -> V_479 ) >= 2 )
F_827 ( V_6 -> V_482 ) ;
F_228 ( V_2 -> V_1143 ) ;
V_65 -> V_89 -> V_90 = V_90 ;
F_226 ( V_65 -> V_89 ) ;
V_2 -> V_484 = F_828 ( V_256 ) ;
V_362 = F_741 ( V_57 ) ;
if ( V_362 )
goto V_1198;
V_81 -> V_440 = F_317 ( & V_6 -> V_439 ) ;
if ( F_829 ( & V_6 -> V_439 ) ) {
V_362 = - V_1199 ;
goto V_1200;
}
F_830 ( & V_81 -> V_479 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 5 || F_18 ( V_57 ) )
V_2 -> V_1148 = F_11 ( F_781 ( V_95 ) ) + 1 ;
if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
V_1170 = & V_6 -> V_1170 [ V_1201 ] ;
if ( V_90 -> V_260 [ 0 ] != V_1143 -> V_260 [ 0 ] )
V_1170 = NULL ;
} else if ( F_325 ( V_57 ) || F_259 ( V_57 ) ) {
V_1170 = & V_6 -> V_1170 [ V_1201 ] ;
} else if ( F_58 ( V_57 ) -> V_103 >= 7 ) {
V_1170 = F_807 ( & V_256 -> V_1184 ,
& V_256 -> V_64 . V_57 -> V_259 ) ;
if ( V_1170 == NULL || V_1170 -> V_377 != V_1171 )
V_1170 = & V_6 -> V_1170 [ V_1201 ] ;
} else {
V_1170 = & V_6 -> V_1170 [ V_1171 ] ;
}
V_1193 = F_804 ( V_1170 , V_256 ) ;
V_257 = F_185 ( V_90 , V_89 -> V_43 -> V_249 ) ;
if ( F_191 ( V_257 ) ) {
V_362 = F_302 ( V_257 ) ;
goto V_1202;
}
V_2 -> V_1147 = F_253 ( V_90 , V_89 -> V_43 -> V_249 ) ;
V_2 -> V_1147 += V_81 -> V_371 ;
V_2 -> V_249 = V_65 -> V_89 -> V_43 -> V_249 ;
F_416 ( V_81 , V_81 -> V_91 ,
F_231 ( V_89 -> V_43 ) ) ;
if ( V_1193 ) {
F_826 ( & V_2 -> V_3 , F_810 ) ;
V_2 -> V_1144 = F_831 ( & V_256 -> V_1184 ,
& V_256 -> V_64 . V_57 -> V_259 ) ;
F_832 ( & V_2 -> V_3 ) ;
} else {
V_1194 = F_833 ( V_1170 , V_1170 -> V_1203 ) ;
if ( F_191 ( V_1194 ) ) {
V_362 = F_302 ( V_1194 ) ;
goto V_1204;
}
V_362 = F_834 ( V_1194 , V_256 , false ) ;
if ( V_362 )
goto V_1205;
V_362 = V_6 -> V_436 . V_1206 ( V_57 , V_65 , V_90 , V_256 , V_1194 ,
V_1192 ) ;
if ( V_362 )
goto V_1205;
F_789 ( V_81 , V_2 ) ;
V_2 -> V_1144 = F_835 ( V_1194 ) ;
F_836 ( V_1194 ) ;
}
F_837 ( F_186 ( V_1143 ) , V_256 ,
F_230 ( V_89 ) -> V_354 ) ;
F_5 ( & V_57 -> V_259 ) ;
F_838 ( F_53 ( V_57 ) ,
F_230 ( V_89 ) -> V_354 ) ;
F_839 ( V_81 -> V_137 , V_256 ) ;
return 0 ;
V_1205:
F_836 ( V_1194 ) ;
V_1204:
F_196 ( V_90 , V_65 -> V_89 -> V_43 -> V_249 ) ;
V_1202:
F_777 ( & V_81 -> V_479 ) ;
V_1200:
F_5 ( & V_57 -> V_259 ) ;
V_1198:
V_65 -> V_89 -> V_90 = V_1143 ;
F_226 ( V_65 -> V_89 ) ;
F_749 ( V_256 ) ;
F_227 ( V_2 -> V_1143 ) ;
F_310 ( & V_57 -> V_442 ) ;
V_81 -> V_443 = NULL ;
F_311 ( & V_57 -> V_442 ) ;
F_101 ( V_65 ) ;
V_1197:
F_232 ( V_2 ) ;
if ( V_362 == - V_1199 ) {
struct V_422 * V_43 ;
struct V_335 * V_336 ;
V_1196:
V_43 = F_537 ( V_57 ) ;
if ( ! V_43 )
return - V_723 ;
V_43 -> V_434 = F_840 ( V_65 ) ;
V_464:
V_336 = F_753 ( V_43 , V_89 ) ;
V_362 = F_545 ( V_336 ) ;
if ( ! V_362 ) {
F_756 ( V_336 , V_90 ) ;
V_362 = F_755 ( V_336 , V_65 ) ;
if ( ! V_362 )
V_362 = F_294 ( V_43 ) ;
}
if ( V_362 == - V_425 ) {
F_300 ( V_43 -> V_434 ) ;
F_841 ( V_43 ) ;
goto V_464;
}
if ( V_362 )
F_304 ( V_43 ) ;
if ( V_362 == 0 && V_480 ) {
F_310 ( & V_57 -> V_442 ) ;
F_343 ( V_65 , V_480 ) ;
F_311 ( & V_57 -> V_442 ) ;
}
}
return V_362 ;
}
static bool F_842 ( struct V_333 * V_137 ,
struct V_335 * V_43 )
{
struct V_265 * V_1207 = F_231 ( V_43 ) ;
struct V_265 * V_1208 = F_231 ( V_137 -> V_43 ) ;
if ( V_1207 -> V_64 . V_340 != V_1208 -> V_64 . V_340 )
return true ;
if ( ! V_1208 -> V_64 . V_90 || ! V_1207 -> V_64 . V_90 )
return false ;
if ( V_1208 -> V_64 . V_90 -> V_260 [ 0 ] != V_1207 -> V_64 . V_90 -> V_260 [ 0 ] ||
V_1208 -> V_64 . V_249 != V_1207 -> V_64 . V_249 ||
F_240 ( & V_1207 -> V_64 . V_351 ) != F_240 ( & V_1208 -> V_64 . V_351 ) ||
F_241 ( & V_1207 -> V_64 . V_351 ) != F_241 ( & V_1208 -> V_64 . V_351 ) ||
F_240 ( & V_1207 -> V_64 . V_352 ) != F_240 ( & V_1208 -> V_64 . V_352 ) ||
F_241 ( & V_1207 -> V_64 . V_352 ) != F_241 ( & V_1208 -> V_64 . V_352 ) )
return true ;
return false ;
}
static bool F_843 ( struct V_265 * V_43 )
{
int V_345 = F_240 ( & V_43 -> V_64 . V_351 ) >> 16 ;
int V_346 = F_241 ( & V_43 -> V_64 . V_351 ) >> 16 ;
int V_410 = F_240 ( & V_43 -> V_64 . V_352 ) ;
int V_411 = F_241 ( & V_43 -> V_64 . V_352 ) ;
return ( V_345 != V_410 || V_346 != V_411 ) ;
}
int F_844 ( struct V_42 * V_62 ,
struct V_335 * V_336 )
{
struct V_37 * V_38 = F_288 ( V_62 ) ;
struct V_87 * V_65 = V_62 -> V_65 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_333 * V_137 = V_336 -> V_137 ;
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_265 * V_1209 =
F_231 ( V_137 -> V_43 ) ;
bool V_423 = F_25 ( V_62 ) ;
bool V_1210 = V_65 -> V_43 -> V_88 ;
bool V_1211 = V_62 -> V_88 ;
bool V_1212 , V_1213 , V_340 , V_1214 ;
struct V_248 * V_90 = V_336 -> V_90 ;
int V_362 ;
if ( F_250 ( V_57 ) >= 9 && V_137 -> type != V_1215 ) {
V_362 = F_392 (
F_288 ( V_62 ) ,
F_231 ( V_336 ) ) ;
if ( V_362 )
return V_362 ;
}
V_1214 = V_1209 -> V_64 . V_340 ;
V_340 = F_231 ( V_336 ) -> V_64 . V_340 ;
if ( ! V_1210 && F_28 ( V_1214 ) )
V_1214 = false ;
if ( ! V_1211 )
F_231 ( V_336 ) -> V_64 . V_340 = V_340 = false ;
if ( ! V_1214 && ! V_340 )
return 0 ;
if ( V_90 != V_1209 -> V_64 . V_90 )
V_38 -> V_1216 = true ;
V_1212 = V_1214 && ( ! V_340 || V_423 ) ;
V_1213 = V_340 && ( ! V_1214 || V_423 ) ;
F_845 ( L_190 ,
V_81 -> V_64 . V_64 . V_377 ,
V_81 -> V_64 . V_12 ,
V_137 -> V_64 . V_377 , V_137 -> V_12 ,
V_90 ? V_90 -> V_64 . V_377 : - 1 ) ;
F_845 ( L_191 ,
V_137 -> V_64 . V_377 , V_137 -> V_12 ,
V_1214 , V_340 ,
V_1212 , V_1213 , V_423 ) ;
if ( V_1213 ) {
V_38 -> V_574 = true ;
if ( V_137 -> type != V_1215 )
V_38 -> V_571 = true ;
} else if ( V_1212 ) {
V_38 -> V_567 = true ;
if ( V_137 -> type != V_1215 )
V_38 -> V_571 = true ;
} else if ( F_842 ( V_137 , V_336 ) ) {
V_38 -> V_574 = true ;
V_38 -> V_567 = true ;
}
if ( ( V_38 -> V_574 || V_38 -> V_567 ) &&
F_58 ( V_57 ) -> V_103 < 9 && V_6 -> V_436 . V_1217 )
F_288 ( V_62 ) -> V_403 . V_1218 = true ;
if ( V_340 || V_1214 )
V_38 -> V_565 |= F_230 ( V_137 ) -> V_354 ;
if ( V_137 -> type == V_1219 && F_325 ( V_57 ) &&
F_843 ( F_231 ( V_336 ) ) &&
! F_843 ( V_1209 ) )
V_38 -> V_572 = true ;
return 0 ;
}
static bool F_846 ( const struct V_512 * V_1145 ,
const struct V_512 * V_1146 )
{
return V_1145 == V_1146 || ( V_1145 -> V_1220 & ( 1 << V_1146 -> type ) &&
V_1146 -> V_1220 & ( 1 << V_1145 -> type ) ) ;
}
static bool F_847 ( struct V_422 * V_43 ,
struct V_81 * V_65 ,
struct V_512 * V_513 )
{
struct V_512 * V_1221 ;
struct V_577 * V_721 ;
struct V_575 * V_1115 ;
int V_139 ;
F_422 (state, connector, connector_state, i) {
if ( V_1115 -> V_65 != & V_65 -> V_64 )
continue;
V_1221 =
F_423 ( V_1115 -> V_580 ) ;
if ( ! F_846 ( V_513 , V_1221 ) )
return false ;
}
return true ;
}
static int F_848 ( struct V_87 * V_65 ,
struct V_42 * V_62 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_38 =
F_288 ( V_62 ) ;
struct V_422 * V_43 = V_62 -> V_43 ;
int V_362 ;
bool V_423 = F_25 ( V_62 ) ;
if ( V_423 && ! V_62 -> V_88 )
V_38 -> V_567 = true ;
if ( V_423 && V_62 -> V_508 &&
V_6 -> V_436 . V_1222 &&
! F_28 ( V_38 -> V_208 ) ) {
V_362 = V_6 -> V_436 . V_1222 ( V_81 ,
V_38 ) ;
if ( V_362 )
return V_362 ;
}
if ( V_62 -> V_1223 ) {
V_362 = F_849 ( V_65 , V_62 ) ;
if ( V_362 )
return V_362 ;
V_62 -> V_1224 = true ;
}
V_362 = 0 ;
if ( V_6 -> V_436 . V_1225 ) {
V_362 = V_6 -> V_436 . V_1225 ( V_38 ) ;
if ( V_362 ) {
F_158 ( L_192 ) ;
return V_362 ;
}
}
if ( V_6 -> V_436 . V_1226 &&
! F_293 ( V_43 ) -> V_424 ) {
if ( F_28 ( ! V_6 -> V_436 . V_1225 ) )
return 0 ;
V_362 = V_6 -> V_436 . V_1226 ( V_65 -> V_57 ,
V_81 ,
V_38 ) ;
if ( V_362 ) {
F_158 ( L_193 ) ;
return V_362 ;
}
} else if ( V_6 -> V_436 . V_1226 ) {
if ( F_15 ( V_6 ) && F_250 ( V_6 ) < 9 )
V_38 -> V_403 . V_1227 . V_1228 = V_38 -> V_403 . V_1227 . V_1229 ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
if ( V_423 )
V_362 = F_391 ( V_38 ) ;
if ( ! V_362 )
V_362 = F_850 ( V_57 , V_81 ,
V_38 ) ;
}
return V_362 ;
}
static void F_851 ( struct V_56 * V_57 )
{
struct V_720 * V_721 ;
F_852 (dev, connector) {
if ( V_721 -> V_64 . V_43 -> V_65 )
F_853 ( & V_721 -> V_64 ) ;
if ( V_721 -> V_64 . V_513 ) {
V_721 -> V_64 . V_43 -> V_580 =
V_721 -> V_64 . V_513 ;
V_721 -> V_64 . V_43 -> V_65 =
V_721 -> V_64 . V_513 -> V_65 ;
F_854 ( & V_721 -> V_64 ) ;
} else {
V_721 -> V_64 . V_43 -> V_580 = NULL ;
V_721 -> V_64 . V_43 -> V_65 = NULL ;
}
}
}
static void
F_855 ( struct V_720 * V_721 ,
struct V_37 * V_38 )
{
const struct V_1230 * V_1231 = & V_721 -> V_64 . V_1232 ;
int V_988 = V_38 -> V_732 ;
F_158 ( L_194 ,
V_721 -> V_64 . V_64 . V_377 ,
V_721 -> V_64 . V_12 ) ;
if ( V_1231 -> V_522 != 0 && V_1231 -> V_522 * 3 < V_988 ) {
F_158 ( L_195 ,
V_988 , V_1231 -> V_522 * 3 ) ;
V_38 -> V_732 = V_1231 -> V_522 * 3 ;
}
if ( V_1231 -> V_522 == 0 && V_988 > 24 ) {
F_158 ( L_196 ,
V_988 ) ;
V_38 -> V_732 = 24 ;
}
}
static int
F_856 ( struct V_81 * V_65 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_422 * V_43 ;
struct V_577 * V_721 ;
struct V_575 * V_1115 ;
int V_988 , V_139 ;
if ( ( F_18 ( V_57 ) || F_16 ( V_57 ) || F_17 ( V_57 ) ) )
V_988 = 10 * 3 ;
else if ( F_58 ( V_57 ) -> V_103 >= 5 )
V_988 = 12 * 3 ;
else
V_988 = 8 * 3 ;
V_38 -> V_732 = V_988 ;
V_43 = V_38 -> V_64 . V_43 ;
F_422 (state, connector, connector_state, i) {
if ( V_1115 -> V_65 != & V_65 -> V_64 )
continue;
F_855 ( F_857 ( V_721 ) ,
V_38 ) ;
}
return V_988 ;
}
static void F_858 ( const struct V_521 * V_418 )
{
F_158 ( L_197
L_198 ,
V_418 -> V_93 ,
V_418 -> V_544 , V_418 -> V_737 ,
V_418 -> V_887 , V_418 -> V_884 ,
V_418 -> V_545 , V_418 -> V_889 ,
V_418 -> V_890 , V_418 -> V_880 , V_418 -> type , V_418 -> V_330 ) ;
}
static void F_859 ( struct V_81 * V_65 ,
struct V_37 * V_38 ,
const char * V_1233 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_333 * V_137 ;
struct V_337 * V_337 ;
struct V_265 * V_43 ;
struct V_248 * V_90 ;
F_158 ( L_199 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 ,
V_1233 , V_38 , F_77 ( V_65 -> V_95 ) ) ;
F_158 ( L_200 , F_860 ( V_38 -> V_97 ) ) ;
F_158 ( L_201 ,
V_38 -> V_732 , V_38 -> V_903 ) ;
F_158 ( L_202 ,
V_38 -> V_226 ,
V_38 -> V_459 ,
V_38 -> V_587 . V_800 , V_38 -> V_587 . V_801 ,
V_38 -> V_587 . V_802 , V_38 -> V_587 . V_803 ,
V_38 -> V_587 . V_799 ) ;
F_158 ( L_203 ,
F_387 ( V_38 ) ,
V_38 -> V_1045 ,
V_38 -> V_817 . V_800 , V_38 -> V_817 . V_801 ,
V_38 -> V_817 . V_802 , V_38 -> V_817 . V_803 ,
V_38 -> V_817 . V_799 ) ;
F_158 ( L_204 ,
F_387 ( V_38 ) ,
V_38 -> V_1045 ,
V_38 -> V_818 . V_800 ,
V_38 -> V_818 . V_801 ,
V_38 -> V_818 . V_802 ,
V_38 -> V_818 . V_803 ,
V_38 -> V_818 . V_799 ) ;
F_158 ( L_205 ,
V_38 -> V_1044 ,
V_38 -> V_1234 ) ;
F_158 ( L_206 ) ;
F_861 ( & V_38 -> V_64 . V_418 ) ;
F_158 ( L_207 ) ;
F_861 ( & V_38 -> V_64 . V_92 ) ;
F_858 ( & V_38 -> V_64 . V_92 ) ;
F_158 ( L_208 , V_38 -> V_39 ) ;
F_158 ( L_209 ,
V_38 -> V_367 , V_38 -> V_366 ) ;
F_158 ( L_210 ,
V_65 -> V_380 ,
V_38 -> V_379 . V_534 ,
V_38 -> V_379 . V_407 ) ;
F_158 ( L_211 ,
V_38 -> V_595 . V_596 ,
V_38 -> V_595 . V_600 ,
V_38 -> V_595 . V_1235 ) ;
F_158 ( L_212 ,
V_38 -> V_445 . V_549 ,
V_38 -> V_445 . V_244 ,
V_38 -> V_445 . V_148 ? L_213 : L_214 ) ;
F_158 ( L_215 , V_38 -> V_552 ) ;
F_158 ( L_216 , V_38 -> V_229 ) ;
if ( F_36 ( V_57 ) ) {
F_158 ( L_217
L_218
L_219 ,
V_38 -> V_176 . V_1236 ,
V_38 -> V_176 . V_1237 ,
V_38 -> V_176 . V_1238 ,
V_38 -> V_176 . V_1239 ,
V_38 -> V_176 . V_1240 ,
V_38 -> V_176 . V_1241 ,
V_38 -> V_176 . V_1242 ,
V_38 -> V_176 . V_1243 ,
V_38 -> V_176 . V_1244 ,
V_38 -> V_176 . V_1245 ,
V_38 -> V_176 . V_1246 ) ;
} else if ( F_475 ( V_57 ) || F_476 ( V_57 ) ) {
F_158 ( L_220
L_221 ,
V_38 -> V_176 . V_1247 ,
V_38 -> V_176 . V_1248 ,
V_38 -> V_176 . V_1249 ) ;
} else if ( F_23 ( V_57 ) ) {
F_158 ( L_222 ,
V_38 -> V_176 . V_1250 ,
V_38 -> V_176 . V_1251 ) ;
} else {
F_158 ( L_223
L_224 ,
V_38 -> V_176 . V_45 ,
V_38 -> V_176 . V_178 ,
V_38 -> V_176 . V_715 ,
V_38 -> V_176 . V_716 ) ;
}
F_158 ( L_225 ) ;
F_862 (plane, &dev->mode_config.plane_list, head) {
char * V_1252 ;
V_337 = F_230 ( V_137 ) ;
if ( V_337 -> V_95 != V_65 -> V_95 )
continue;
V_43 = F_231 ( V_137 -> V_43 ) ;
V_90 = V_43 -> V_64 . V_90 ;
if ( ! V_90 ) {
F_158 ( L_226 ,
V_137 -> V_64 . V_377 , V_137 -> V_12 , V_43 -> V_407 ) ;
continue;
}
V_1252 = F_863 ( V_90 -> V_241 ) ;
F_158 ( L_227 ,
V_137 -> V_64 . V_377 , V_137 -> V_12 ) ;
F_158 ( L_228 ,
V_90 -> V_64 . V_377 , V_90 -> V_245 , V_90 -> V_240 , V_1252 ) ;
F_158 ( L_229 ,
V_43 -> V_407 ,
V_43 -> V_64 . V_351 . V_293 >> 16 ,
V_43 -> V_64 . V_351 . y1 >> 16 ,
F_240 ( & V_43 -> V_64 . V_351 ) >> 16 ,
F_241 ( & V_43 -> V_64 . V_351 ) >> 16 ,
V_43 -> V_64 . V_352 . V_293 , V_43 -> V_64 . V_352 . y1 ,
F_240 ( & V_43 -> V_64 . V_352 ) ,
F_241 ( & V_43 -> V_64 . V_352 ) ) ;
F_232 ( V_1252 ) ;
}
}
static bool F_864 ( struct V_422 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_577 * V_721 ;
unsigned int V_1253 = 0 ;
unsigned int V_1254 = 0 ;
F_865 (connector, dev) {
struct V_575 * V_1115 ;
struct V_512 * V_513 ;
V_1115 = F_866 ( V_43 , V_721 ) ;
if ( ! V_1115 )
V_1115 = V_721 -> V_43 ;
if ( ! V_1115 -> V_580 )
continue;
V_513 = F_423 ( V_1115 -> V_580 ) ;
F_28 ( ! V_1115 -> V_65 ) ;
switch ( V_513 -> type ) {
unsigned int V_198 ;
case V_614 :
if ( F_28 ( ! F_23 ( V_57 ) ) )
break;
case V_514 :
case V_211 :
case V_515 :
V_198 = 1 << F_379 ( & V_513 -> V_64 ) -> V_180 ;
if ( V_1253 & V_198 )
return false ;
V_1253 |= V_198 ;
break;
case V_615 :
V_1254 |=
1 << F_462 ( & V_513 -> V_64 ) -> V_89 -> V_180 ;
break;
default:
break;
}
}
if ( V_1253 & V_1254 )
return false ;
return true ;
}
static void
F_867 ( struct V_37 * V_62 )
{
struct V_42 V_1255 ;
struct V_378 V_379 ;
struct V_1256 V_176 ;
struct V_994 * V_208 ;
bool V_621 ;
V_1255 = V_62 -> V_64 ;
V_379 = V_62 -> V_379 ;
V_208 = V_62 -> V_208 ;
V_176 = V_62 -> V_176 ;
V_621 = V_62 -> V_445 . V_621 ;
memset ( V_62 , 0 , sizeof *V_62 ) ;
V_62 -> V_64 = V_1255 ;
V_62 -> V_379 = V_379 ;
V_62 -> V_208 = V_208 ;
V_62 -> V_176 = V_176 ;
V_62 -> V_445 . V_621 = V_621 ;
}
static int
F_868 ( struct V_87 * V_65 ,
struct V_37 * V_38 )
{
struct V_422 * V_43 = V_38 -> V_64 . V_43 ;
struct V_512 * V_513 ;
struct V_577 * V_721 ;
struct V_575 * V_1115 ;
int V_1257 , V_362 = - V_288 ;
int V_139 ;
bool V_464 = true ;
F_867 ( V_38 ) ;
V_38 -> V_97 =
(enum V_94 ) F_47 ( V_65 ) -> V_95 ;
if ( ! ( V_38 -> V_64 . V_92 . V_330 &
( V_526 | V_1258 ) ) )
V_38 -> V_64 . V_92 . V_330 |= V_1258 ;
if ( ! ( V_38 -> V_64 . V_92 . V_330 &
( V_528 | V_1259 ) ) )
V_38 -> V_64 . V_92 . V_330 |= V_1259 ;
V_1257 = F_856 ( F_47 ( V_65 ) ,
V_38 ) ;
if ( V_1257 < 0 )
goto V_786;
F_754 ( & V_38 -> V_64 . V_418 ,
& V_38 -> V_367 ,
& V_38 -> V_366 ) ;
F_422 (state, connector, connector_state, i) {
if ( V_1115 -> V_65 != V_65 )
continue;
V_513 = F_423 ( V_1115 -> V_580 ) ;
if ( ! F_847 ( V_43 , F_47 ( V_65 ) , V_513 ) ) {
F_158 ( L_230 ) ;
goto V_786;
}
V_38 -> V_1260 |= 1 << V_513 -> type ;
}
V_1261:
V_38 -> V_39 = 0 ;
V_38 -> V_590 = 1 ;
F_869 ( & V_38 -> V_64 . V_92 ,
V_1262 ) ;
F_422 (state, connector, connector_state, i) {
if ( V_1115 -> V_65 != V_65 )
continue;
V_513 = F_423 ( V_1115 -> V_580 ) ;
if ( ! ( V_513 -> V_1263 ( V_513 , V_38 , V_1115 ) ) ) {
F_158 ( L_231 ) ;
goto V_786;
}
}
if ( ! V_38 -> V_39 )
V_38 -> V_39 = V_38 -> V_64 . V_92 . V_93
* V_38 -> V_590 ;
V_362 = F_565 ( F_47 ( V_65 ) , V_38 ) ;
if ( V_362 < 0 ) {
F_158 ( L_232 ) ;
goto V_786;
}
if ( V_362 == V_734 ) {
if ( F_7 ( ! V_464 , L_233 ) ) {
V_362 = - V_288 ;
goto V_786;
}
F_158 ( L_234 ) ;
V_464 = false ;
goto V_1261;
}
V_38 -> V_903 = V_38 -> V_732 == 6 * 3 ;
F_158 ( L_235 ,
V_1257 , V_38 -> V_732 , V_38 -> V_903 ) ;
V_786:
return V_362 ;
}
static void
F_870 ( struct V_422 * V_43 )
{
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_139 ;
F_292 (state, crtc, crtc_state, i) {
F_47 ( V_65 ) -> V_91 = F_288 ( V_65 -> V_43 ) ;
if ( V_65 -> V_43 -> V_88 )
V_65 -> V_1264 = V_65 -> V_43 -> V_92 ;
else
V_65 -> V_1264 . V_93 = 0 ;
if ( F_411 ( V_43 , V_65 -> V_89 ) ) {
struct V_335 * V_336 = V_65 -> V_89 -> V_43 ;
V_65 -> V_89 -> V_90 = V_336 -> V_90 ;
V_65 -> V_263 = V_336 -> V_343 >> 16 ;
V_65 -> V_264 = V_336 -> V_344 >> 16 ;
}
}
}
static bool F_871 ( int V_1265 , int V_1266 )
{
int V_1267 ;
if ( V_1265 == V_1266 )
return true ;
if ( ! V_1265 || ! V_1266 )
return false ;
V_1267 = abs ( V_1265 - V_1266 ) ;
if ( ( ( ( ( V_1267 + V_1265 + V_1266 ) * 100 ) ) / ( V_1265 + V_1266 ) ) < 105 )
return true ;
return false ;
}
static bool
F_872 ( unsigned int V_46 , unsigned int V_51 ,
unsigned int V_47 , unsigned int V_1268 ,
bool V_1269 )
{
if ( V_46 == V_47 && V_51 == V_1268 )
return true ;
if ( V_1269 || ! V_46 || ! V_51 || ! V_47 || ! V_1268 )
return false ;
F_873 ( V_790 > V_84 ) ;
if ( V_51 > V_1268 ) {
while ( V_51 > V_1268 ) {
V_47 <<= 1 ;
V_1268 <<= 1 ;
}
} else if ( V_51 < V_1268 ) {
while ( V_51 < V_1268 ) {
V_46 <<= 1 ;
V_51 <<= 1 ;
}
}
if ( V_51 != V_1268 )
return false ;
return F_871 ( V_46 , V_47 ) ;
}
static bool
F_874 ( const struct V_797 * V_798 ,
struct V_797 * V_814 ,
bool V_1270 )
{
if ( V_798 -> V_799 == V_814 -> V_799 &&
F_872 ( V_798 -> V_800 , V_798 -> V_801 ,
V_814 -> V_800 , V_814 -> V_801 , ! V_1270 ) &&
F_872 ( V_798 -> V_802 , V_798 -> V_803 ,
V_814 -> V_802 , V_814 -> V_803 , ! V_1270 ) ) {
if ( V_1270 )
* V_814 = * V_798 ;
return true ;
}
return false ;
}
static bool
F_875 ( struct V_56 * V_57 ,
struct V_37 * V_1271 ,
struct V_37 * V_38 ,
bool V_1270 )
{
bool V_362 = true ;
#define F_876 ( T_7 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_877 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_878 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_879 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_880 ( V_12 ) \
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
#define F_881 ( V_12 , T_8 ) \
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
#define F_882 ( V_12 , V_620 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_883 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_884 ( T_9 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_878 ( V_97 ) ;
F_878 ( V_226 ) ;
F_878 ( V_459 ) ;
F_880 ( V_587 ) ;
F_878 ( V_1045 ) ;
F_877 ( V_1272 ) ;
if ( F_58 ( V_57 ) -> V_103 < 8 ) {
F_880 ( V_817 ) ;
if ( V_1271 -> V_815 )
F_880 ( V_818 ) ;
} else
F_881 ( V_817 , V_818 ) ;
F_877 ( V_1260 ) ;
F_878 ( V_64 . V_92 . V_544 ) ;
F_878 ( V_64 . V_92 . V_884 ) ;
F_878 ( V_64 . V_92 . V_885 ) ;
F_878 ( V_64 . V_92 . V_886 ) ;
F_878 ( V_64 . V_92 . V_737 ) ;
F_878 ( V_64 . V_92 . V_887 ) ;
F_878 ( V_64 . V_92 . V_545 ) ;
F_878 ( V_64 . V_92 . V_880 ) ;
F_878 ( V_64 . V_92 . V_888 ) ;
F_878 ( V_64 . V_92 . V_881 ) ;
F_878 ( V_64 . V_92 . V_889 ) ;
F_878 ( V_64 . V_92 . V_890 ) ;
F_878 ( V_590 ) ;
F_878 ( V_1273 ) ;
if ( ( F_58 ( V_57 ) -> V_103 < 8 && ! F_259 ( V_57 ) ) ||
F_16 ( V_57 ) || F_17 ( V_57 ) )
F_878 ( V_912 ) ;
F_878 ( V_1234 ) ;
F_878 ( V_1044 ) ;
F_882 ( V_64 . V_92 . V_330 ,
V_883 ) ;
if ( ! F_884 ( V_1274 ) ) {
F_882 ( V_64 . V_92 . V_330 ,
V_526 ) ;
F_882 ( V_64 . V_92 . V_330 ,
V_1258 ) ;
F_882 ( V_64 . V_92 . V_330 ,
V_528 ) ;
F_882 ( V_64 . V_92 . V_330 ,
V_1259 ) ;
}
F_877 ( V_595 . V_596 ) ;
if ( F_58 ( V_57 ) -> V_103 < 4 )
F_877 ( V_595 . V_600 ) ;
F_877 ( V_595 . V_1235 ) ;
if ( ! V_1270 ) {
F_878 ( V_367 ) ;
F_878 ( V_366 ) ;
F_878 ( V_445 . V_148 ) ;
if ( V_1271 -> V_445 . V_148 ) {
F_877 ( V_445 . V_549 ) ;
F_877 ( V_445 . V_244 ) ;
}
F_878 ( V_379 . V_407 ) ;
}
if ( F_259 ( V_57 ) )
F_878 ( V_552 ) ;
F_878 ( V_229 ) ;
F_879 ( V_208 ) ;
F_877 ( V_176 . V_45 ) ;
F_877 ( V_176 . V_178 ) ;
F_877 ( V_176 . V_715 ) ;
F_877 ( V_176 . V_716 ) ;
F_877 ( V_176 . V_1250 ) ;
F_877 ( V_176 . V_1251 ) ;
F_877 ( V_176 . V_1247 ) ;
F_877 ( V_176 . V_1248 ) ;
F_877 ( V_176 . V_1249 ) ;
F_877 ( V_1275 . V_1276 ) ;
F_877 ( V_1275 . div ) ;
if ( F_18 ( V_57 ) || F_58 ( V_57 ) -> V_103 >= 5 )
F_878 ( V_732 ) ;
F_883 ( V_64 . V_92 . V_93 ) ;
F_883 ( V_39 ) ;
#undef F_877
#undef F_878
#undef F_879
#undef F_882
#undef F_883
#undef F_884
#undef F_876
return V_362 ;
}
static void F_885 ( struct V_5 * V_6 ,
const struct V_37 * V_38 )
{
if ( V_38 -> V_226 ) {
int V_730 = F_767 ( F_22 ( V_6 , V_38 ) ,
& V_38 -> V_587 ) ;
int V_1277 = V_38 -> V_64 . V_92 . V_93 ;
F_7 ( ! F_871 ( V_730 , V_1277 ) ,
L_236 ,
V_730 , V_1277 ) ;
}
}
static void F_886 ( struct V_87 * V_65 ,
struct V_42 * V_1278 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_1279 V_1280 , * V_1281 ;
struct V_1282 * V_1283 , * V_1284 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
const enum V_95 V_95 = V_81 -> V_95 ;
int V_137 ;
if ( F_58 ( V_57 ) -> V_103 < 9 || ! V_1278 -> V_88 )
return;
F_887 ( V_6 , & V_1280 ) ;
V_1281 = & V_6 -> V_403 . V_1285 . V_1286 ;
F_888 (dev_priv, pipe, plane) {
V_1283 = & V_1280 . V_137 [ V_95 ] [ V_137 ] ;
V_1284 = & V_1281 -> V_137 [ V_95 ] [ V_137 ] ;
if ( F_889 ( V_1283 , V_1284 ) )
continue;
F_126 ( L_237
L_238 ,
F_77 ( V_95 ) , V_137 + 1 ,
V_1284 -> V_1287 , V_1284 -> V_1288 ,
V_1283 -> V_1287 , V_1283 -> V_1288 ) ;
}
if ( V_81 -> V_1104 ) {
V_1283 = & V_1280 . V_137 [ V_95 ] [ V_1289 ] ;
V_1284 = & V_1281 -> V_137 [ V_95 ] [ V_1289 ] ;
if ( ! F_889 ( V_1283 , V_1284 ) ) {
F_126 ( L_239
L_238 ,
F_77 ( V_95 ) ,
V_1284 -> V_1287 , V_1284 -> V_1288 ,
V_1283 -> V_1287 , V_1283 -> V_1288 ) ;
}
}
}
static void
F_890 ( struct V_56 * V_57 , struct V_87 * V_65 )
{
struct V_577 * V_721 ;
F_865 (connector, dev) {
struct V_619 * V_513 = V_721 -> V_513 ;
struct V_575 * V_43 = V_721 -> V_43 ;
if ( V_43 -> V_65 != V_65 )
continue;
F_548 ( F_857 ( V_721 ) ) ;
F_64 ( V_43 -> V_580 != V_513 ,
L_240 ) ;
}
}
static void
F_891 ( struct V_56 * V_57 )
{
struct V_512 * V_513 ;
struct V_720 * V_721 ;
F_660 (dev, encoder) {
bool V_148 = false ;
enum V_95 V_95 ;
F_158 ( L_241 ,
V_513 -> V_64 . V_64 . V_377 ,
V_513 -> V_64 . V_12 ) ;
F_852 (dev, connector) {
if ( V_721 -> V_64 . V_43 -> V_580 != & V_513 -> V_64 )
continue;
V_148 = true ;
F_64 ( V_721 -> V_64 . V_43 -> V_65 !=
V_513 -> V_64 . V_65 ,
L_242 ) ;
}
F_64 ( ! ! V_513 -> V_64 . V_65 != V_148 ,
L_243
L_244 ,
! ! V_513 -> V_64 . V_65 , V_148 ) ;
if ( ! V_513 -> V_64 . V_65 ) {
bool V_88 ;
V_88 = V_513 -> V_722 ( V_513 , & V_95 ) ;
F_64 ( V_88 ,
L_245 ,
F_77 ( V_95 ) ) ;
}
}
}
static void
F_892 ( struct V_87 * V_65 ,
struct V_42 * V_444 ,
struct V_42 * V_1290 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_512 * V_513 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_38 , * V_1291 ;
struct V_422 * V_563 ;
bool V_88 ;
V_563 = V_444 -> V_43 ;
F_893 ( V_444 ) ;
V_38 = F_288 ( V_444 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_64 . V_65 = V_65 ;
V_38 -> V_64 . V_43 = V_563 ;
F_158 ( L_246 , V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
V_88 = V_6 -> V_436 . V_1292 ( V_81 , V_38 ) ;
if ( ( V_81 -> V_95 == V_117 && V_6 -> V_133 & V_134 ) ||
( V_81 -> V_95 == V_124 && V_6 -> V_133 & V_135 ) )
V_88 = V_1290 -> V_88 ;
F_64 ( V_1290 -> V_88 != V_88 ,
L_247
L_244 , V_1290 -> V_88 , V_88 ) ;
F_64 ( V_81 -> V_88 != V_1290 -> V_88 ,
L_248
L_244 , V_1290 -> V_88 , V_81 -> V_88 ) ;
F_378 (dev, crtc, encoder) {
enum V_95 V_95 ;
V_88 = V_513 -> V_722 ( V_513 , & V_95 ) ;
F_64 ( V_88 != V_1290 -> V_88 ,
L_249 ,
V_513 -> V_64 . V_64 . V_377 , V_88 , V_1290 -> V_88 ) ;
F_64 ( V_88 && V_81 -> V_95 != V_95 ,
L_250 ,
F_77 ( V_95 ) ) ;
if ( V_88 ) {
V_38 -> V_1260 |= 1 << V_513 -> type ;
V_513 -> V_1293 ( V_513 , V_38 ) ;
}
}
if ( ! V_1290 -> V_88 )
return;
F_885 ( V_6 , V_38 ) ;
V_1291 = F_288 ( V_65 -> V_43 ) ;
if ( ! F_875 ( V_57 , V_1291 ,
V_38 , false ) ) {
F_64 ( 1 , L_251 ) ;
F_859 ( V_81 , V_38 ,
L_252 ) ;
F_859 ( V_81 , V_1291 ,
L_253 ) ;
}
}
static void
F_894 ( struct V_5 * V_6 ,
struct V_994 * V_995 ,
struct V_87 * V_65 ,
struct V_42 * V_1278 )
{
struct V_1256 V_176 ;
unsigned V_1294 ;
bool V_88 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
F_158 ( L_254 , V_995 -> V_12 ) ;
V_88 = V_995 -> V_1013 . V_722 ( V_6 , V_995 , & V_176 ) ;
if ( ! ( V_995 -> V_330 & V_1295 ) ) {
F_64 ( ! V_995 -> V_1296 && V_995 -> V_1297 ,
L_255 ) ;
F_64 ( V_995 -> V_1296 && ! V_995 -> V_1297 ,
L_256 ) ;
F_64 ( V_995 -> V_1296 != V_88 ,
L_257 ,
V_995 -> V_1296 , V_88 ) ;
}
if ( ! V_65 ) {
F_64 ( V_995 -> V_1297 & ~ V_995 -> V_91 . V_1294 ,
L_258 ,
V_995 -> V_1297 , V_995 -> V_91 . V_1294 ) ;
return;
}
V_1294 = 1 << F_895 ( V_65 ) ;
if ( V_1278 -> V_88 )
F_64 ( ! ( V_995 -> V_1297 & V_1294 ) ,
L_259 ,
F_77 ( F_895 ( V_65 ) ) , V_995 -> V_1297 ) ;
else
F_64 ( V_995 -> V_1297 & V_1294 ,
L_260 ,
F_77 ( F_895 ( V_65 ) ) , V_995 -> V_1297 ) ;
F_64 ( ! ( V_995 -> V_91 . V_1294 & V_1294 ) ,
L_261 ,
V_1294 , V_995 -> V_91 . V_1294 ) ;
F_64 ( V_995 -> V_1296 && memcmp ( & V_995 -> V_91 . V_1298 ,
& V_176 ,
sizeof( V_176 ) ) ,
L_262 ) ;
}
static void
F_896 ( struct V_56 * V_57 , struct V_87 * V_65 ,
struct V_42 * V_444 ,
struct V_42 * V_1290 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_37 * V_563 = F_288 ( V_444 ) ;
struct V_37 * V_1278 = F_288 ( V_1290 ) ;
if ( V_1278 -> V_208 )
F_894 ( V_6 , V_1278 -> V_208 , V_65 , V_1290 ) ;
if ( V_563 -> V_208 &&
V_563 -> V_208 != V_1278 -> V_208 ) {
unsigned V_1294 = 1 << F_895 ( V_65 ) ;
struct V_994 * V_995 = V_563 -> V_208 ;
F_64 ( V_995 -> V_1297 & V_1294 ,
L_263 ,
F_77 ( F_895 ( V_65 ) ) ) ;
F_64 ( V_995 -> V_91 . V_1294 & V_1294 ,
L_264 ,
F_77 ( F_895 ( V_65 ) ) ) ;
}
}
static void
F_897 ( struct V_87 * V_65 ,
struct V_42 * V_563 ,
struct V_42 * V_1278 )
{
if ( ! F_25 ( V_1278 ) &&
! F_288 ( V_1278 ) -> V_1299 )
return;
F_886 ( V_65 , V_1278 ) ;
F_890 ( V_65 -> V_57 , V_65 ) ;
F_892 ( V_65 , V_563 , V_1278 ) ;
F_896 ( V_65 -> V_57 , V_65 , V_563 , V_1278 ) ;
}
static void
F_898 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_6 -> V_950 ; V_139 ++ )
F_894 ( V_6 , & V_6 -> V_1300 [ V_139 ] , NULL , NULL ) ;
}
static void
F_899 ( struct V_56 * V_57 )
{
F_891 ( V_57 ) ;
F_890 ( V_57 , NULL ) ;
F_898 ( V_57 ) ;
}
static void F_900 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
if ( F_55 ( V_57 ) ) {
const struct V_521 * V_92 = & V_65 -> V_91 -> V_64 . V_92 ;
int V_896 ;
V_896 = V_92 -> V_880 ;
if ( V_92 -> V_330 & V_883 )
V_896 /= 2 ;
V_65 -> V_228 = V_896 - 1 ;
} else if ( F_23 ( V_57 ) &&
F_38 ( V_65 -> V_91 , V_211 ) ) {
V_65 -> V_228 = 2 ;
} else
V_65 -> V_228 = 1 ;
}
static void F_901 ( struct V_422 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_1301 * V_208 = NULL ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_139 ;
if ( ! V_6 -> V_436 . V_1222 )
return;
F_292 (state, crtc, crtc_state, i) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_994 * V_1302 =
F_288 ( V_65 -> V_43 ) -> V_208 ;
if ( ! F_25 ( V_62 ) )
continue;
F_288 ( V_62 ) -> V_208 = NULL ;
if ( ! V_1302 )
continue;
if ( ! V_208 )
V_208 = F_902 ( V_43 ) ;
F_903 ( V_208 , V_1302 , V_81 ) ;
}
}
static int F_904 ( struct V_422 * V_43 )
{
struct V_42 * V_62 ;
struct V_81 * V_81 ;
struct V_87 * V_65 ;
struct V_37 * V_1303 = NULL ;
struct V_37 * V_726 = NULL ;
enum V_95 V_1304 = V_592 , V_1305 = V_592 ;
int V_139 ;
F_292 (state, crtc, crtc_state, i) {
V_81 = F_47 ( V_65 ) ;
if ( ! V_62 -> V_88 || ! F_25 ( V_62 ) )
continue;
if ( V_1303 ) {
V_726 = F_288 ( V_62 ) ;
break;
} else {
V_1303 = F_288 ( V_62 ) ;
V_1304 = V_81 -> V_95 ;
}
}
if ( ! V_1303 )
return 0 ;
F_137 (state->dev, intel_crtc) {
struct V_37 * V_38 ;
V_38 = F_538 ( V_43 , V_81 ) ;
if ( F_191 ( V_38 ) )
return F_302 ( V_38 ) ;
V_38 -> V_588 = V_592 ;
if ( ! V_38 -> V_64 . V_88 ||
F_25 ( & V_38 -> V_64 ) )
continue;
if ( V_1305 != V_592 )
return 0 ;
V_1305 = V_81 -> V_95 ;
}
if ( V_1305 != V_592 )
V_1303 -> V_588 = V_1305 ;
else if ( V_726 )
V_726 -> V_588 = V_1304 ;
return 0 ;
}
static int F_905 ( struct V_422 * V_43 )
{
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_362 = 0 ;
F_233 (state->dev, crtc) {
V_62 = F_763 ( V_43 , V_65 ) ;
if ( F_191 ( V_62 ) )
return F_302 ( V_62 ) ;
if ( ! V_62 -> V_88 || F_25 ( V_62 ) )
continue;
V_62 -> V_423 = true ;
V_362 = F_539 ( V_43 , V_65 ) ;
if ( V_362 )
break;
V_362 = F_906 ( V_43 , V_65 ) ;
if ( V_362 )
break;
}
return V_362 ;
}
static int F_907 ( struct V_422 * V_43 )
{
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_43 -> V_57 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_362 = 0 , V_139 ;
if ( ! F_864 ( V_43 ) ) {
F_158 ( L_265 ) ;
return - V_288 ;
}
V_338 -> V_570 = true ;
V_338 -> V_704 = V_6 -> V_704 ;
F_292 (state, crtc, crtc_state, i) {
if ( V_62 -> V_88 )
V_338 -> V_704 |= 1 << V_139 ;
else
V_338 -> V_704 &= ~ ( 1 << V_139 ) ;
if ( V_62 -> V_88 != V_65 -> V_43 -> V_88 )
V_338 -> V_1306 |= F_274 ( V_65 ) ;
}
if ( V_6 -> V_436 . V_1307 ) {
if ( ! V_338 -> V_1055 )
V_338 -> V_1055 = V_6 -> V_641 . V_52 ;
if ( ! V_338 -> V_1055 )
V_338 -> V_1055 = V_6 -> V_632 ;
V_362 = V_6 -> V_436 . V_1307 ( V_43 ) ;
if ( V_362 < 0 )
return V_362 ;
if ( V_338 -> V_703 != V_6 -> V_638 ||
V_338 -> V_1055 != V_6 -> V_641 . V_52 )
V_362 = F_905 ( V_43 ) ;
if ( V_362 < 0 )
return V_362 ;
F_158 ( L_266 ,
V_338 -> V_644 , V_338 -> V_703 ) ;
} else
F_293 ( V_43 ) -> V_644 = V_6 -> V_1308 ;
F_901 ( V_43 ) ;
if ( F_259 ( V_6 ) )
return F_904 ( V_43 ) ;
return 0 ;
}
static int F_908 ( struct V_422 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( V_6 -> V_436 . V_1309 )
return V_6 -> V_436 . V_1309 ( V_43 ) ;
return 0 ;
}
static int F_909 ( struct V_56 * V_57 ,
struct V_422 * V_43 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_87 * V_65 ;
struct V_42 * V_62 ;
int V_362 , V_139 ;
bool V_1310 = false ;
V_362 = F_910 ( V_57 , V_43 ) ;
if ( V_362 )
return V_362 ;
F_292 (state, crtc, crtc_state, i) {
struct V_37 * V_38 =
F_288 ( V_62 ) ;
if ( V_62 -> V_418 . V_1311 != V_65 -> V_43 -> V_418 . V_1311 )
V_62 -> V_423 = true ;
if ( ! F_25 ( V_62 ) )
continue;
if ( ! V_62 -> V_508 ) {
V_1310 = true ;
continue;
}
V_362 = F_539 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_868 ( V_65 , V_38 ) ;
if ( V_362 ) {
F_859 ( F_47 ( V_65 ) ,
V_38 , L_267 ) ;
return V_362 ;
}
if ( V_431 . V_1312 &&
F_875 ( V_57 ,
F_288 ( V_65 -> V_43 ) ,
V_38 , true ) ) {
V_62 -> V_423 = false ;
F_288 ( V_62 ) -> V_1299 = true ;
}
if ( F_25 ( V_62 ) )
V_1310 = true ;
V_362 = F_906 ( V_43 , V_65 ) ;
if ( V_362 )
return V_362 ;
F_859 ( F_47 ( V_65 ) , V_38 ,
F_25 ( V_62 ) ?
L_268 : L_269 ) ;
}
if ( V_1310 ) {
V_362 = F_907 ( V_43 ) ;
if ( V_362 )
return V_362 ;
} else
V_338 -> V_644 = V_6 -> V_638 ;
V_362 = F_911 ( V_57 , V_43 ) ;
if ( V_362 )
return V_362 ;
F_912 ( V_6 , V_43 ) ;
return F_908 ( V_43 ) ;
}
static int F_913 ( struct V_56 * V_57 ,
struct V_422 * V_43 ,
bool V_1313 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_335 * V_336 ;
struct V_42 * V_62 ;
struct V_333 * V_137 ;
struct V_87 * V_65 ;
int V_139 , V_362 ;
F_292 (state, crtc, crtc_state, i) {
if ( V_43 -> V_1314 )
continue;
V_362 = F_347 ( V_65 ) ;
if ( V_362 )
return V_362 ;
if ( F_340 ( & F_47 ( V_65 ) -> V_479 ) >= 2 )
F_827 ( V_6 -> V_482 ) ;
}
V_362 = F_914 ( & V_57 -> V_259 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_915 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_259 ) ;
if ( ! V_362 && ! V_1313 ) {
F_916 (state, plane, plane_state, i) {
struct V_265 * V_265 =
F_231 ( V_336 ) ;
if ( ! V_265 -> V_1315 )
continue;
V_362 = F_811 ( V_265 -> V_1315 ,
V_1316 ,
NULL , NULL ) ;
if ( V_362 ) {
F_28 ( V_362 == - V_1199 ) ;
F_3 ( & V_57 -> V_259 ) ;
F_917 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_259 ) ;
break;
}
}
}
return V_362 ;
}
T_1 F_783 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
if ( ! V_57 -> V_227 )
return F_918 ( & V_65 -> V_64 ) ;
return V_57 -> V_1317 -> V_1318 ( V_57 , V_65 -> V_95 ) ;
}
static void F_919 ( struct V_56 * V_57 ,
struct V_5 * V_6 ,
unsigned V_1294 )
{
unsigned V_1319 [ V_1320 ] ;
enum V_95 V_95 ;
int V_362 ;
if ( ! V_1294 )
return;
F_90 (dev_priv, pipe) {
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
if ( ! ( ( 1 << V_95 ) & V_1294 ) )
continue;
V_362 = F_100 ( V_65 ) ;
if ( F_28 ( V_362 != 0 ) ) {
V_1294 &= ~ ( 1 << V_95 ) ;
continue;
}
V_1319 [ V_95 ] = F_920 ( V_65 ) ;
}
F_90 (dev_priv, pipe) {
struct V_87 * V_65 = V_6 -> V_96 [ V_95 ] ;
long V_1321 ;
if ( ! ( ( 1 << V_95 ) & V_1294 ) )
continue;
V_1321 = F_921 ( V_57 -> V_1189 [ V_95 ] . V_1322 ,
V_1319 [ V_95 ] !=
F_920 ( V_65 ) ,
F_922 ( 50 ) ) ;
F_7 ( ! V_1321 , L_270 , F_77 ( V_95 ) ) ;
F_101 ( V_65 ) ;
}
}
static bool F_923 ( struct V_37 * V_62 )
{
if ( V_62 -> V_1216 )
return true ;
if ( V_62 -> V_567 )
return true ;
if ( V_62 -> V_571 )
return true ;
return false ;
}
static void F_924 ( struct V_87 * V_65 ,
struct V_422 * V_43 ,
struct V_42 * V_444 ,
unsigned int * V_1323 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_38 = F_288 ( V_65 -> V_43 ) ;
bool V_570 = F_25 ( V_65 -> V_43 ) ;
if ( V_570 ) {
F_900 ( V_81 ) ;
V_6 -> V_436 . V_1324 ( V_38 , V_43 ) ;
} else {
F_415 ( F_288 ( V_444 ) ) ;
}
if ( F_411 ( V_43 , V_65 -> V_89 ) ) {
F_925 (
V_81 , V_38 ,
F_231 ( V_65 -> V_89 -> V_43 ) ) ;
}
F_926 ( V_444 ) ;
if ( F_923 ( V_38 ) )
* V_1323 |= F_274 ( V_65 ) ;
}
static void F_927 ( struct V_422 * V_43 ,
unsigned int * V_1323 )
{
struct V_87 * V_65 ;
struct V_42 * V_444 ;
int V_139 ;
F_292 (state, crtc, old_crtc_state, i) {
if ( ! V_65 -> V_43 -> V_88 )
continue;
F_924 ( V_65 , V_43 , V_444 ,
V_1323 ) ;
}
}
static void F_928 ( struct V_422 * V_43 ,
unsigned int * V_1323 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_87 * V_65 ;
struct V_42 * V_444 ;
struct V_1279 * V_1325 = & V_338 -> V_1326 . V_1286 ;
struct V_1279 * V_1327 = & V_6 -> V_403 . V_1285 . V_1286 ;
unsigned int V_1328 = 0 ;
bool V_1329 ;
enum V_95 V_95 ;
do {
int V_139 ;
V_1329 = false ;
F_292 (state, crtc, old_crtc_state, i) {
bool V_1330 = false ;
unsigned int V_1331 = F_274 ( V_65 ) ;
V_95 = F_47 ( V_65 ) -> V_95 ;
if ( V_1328 & V_1331 || ! V_65 -> V_43 -> V_88 )
continue;
if ( F_929 ( V_43 , V_1327 , V_1325 ,
V_95 ) )
continue;
V_1328 |= V_1331 ;
if ( ! F_930 ( V_1327 , V_1325 , V_95 ) &&
! V_65 -> V_43 -> V_1332 &&
V_338 -> V_1326 . V_415 != V_1328 )
V_1330 = true ;
F_924 ( V_65 , V_43 , V_444 ,
V_1323 ) ;
if ( V_1330 )
F_341 ( V_57 , V_95 ) ;
V_1329 = true ;
}
} while ( V_1329 );
}
static void F_931 ( struct V_422 * V_43 )
{
struct V_56 * V_57 = V_43 -> V_57 ;
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_42 * V_444 ;
struct V_87 * V_65 ;
struct V_37 * V_1333 ;
struct V_333 * V_137 ;
struct V_335 * V_336 ;
bool V_1334 = V_338 -> V_570 ;
unsigned long V_1335 [ V_1320 ] = {} ;
unsigned V_1323 = 0 ;
int V_139 , V_362 ;
F_916 (state, plane, plane_state, i) {
struct V_265 * V_265 =
F_231 ( V_137 -> V_43 ) ;
if ( ! V_265 -> V_1315 )
continue;
V_362 = F_811 ( V_265 -> V_1315 ,
0 , NULL , NULL ) ;
F_28 ( V_362 ) ;
}
F_932 ( V_43 ) ;
if ( V_338 -> V_570 ) {
memcpy ( V_6 -> V_701 , V_338 -> V_701 ,
sizeof( V_338 -> V_701 ) ) ;
V_6 -> V_704 = V_338 -> V_704 ;
V_6 -> V_1308 = V_338 -> V_644 ;
F_471 ( V_6 , V_1336 ) ;
}
F_292 (state, crtc, old_crtc_state, i) {
struct V_81 * V_81 = F_47 ( V_65 ) ;
if ( F_25 ( V_65 -> V_43 ) ||
F_288 ( V_65 -> V_43 ) -> V_1299 ) {
V_1334 = true ;
V_1335 [ F_47 ( V_65 ) -> V_95 ] =
F_469 ( V_65 ,
F_288 ( V_65 -> V_43 ) ) ;
}
if ( ! F_25 ( V_65 -> V_43 ) )
continue;
F_415 ( F_288 ( V_444 ) ) ;
if ( V_444 -> V_88 ) {
F_418 ( V_65 , V_444 -> V_341 ) ;
V_6 -> V_436 . V_717 ( F_288 ( V_444 ) , V_43 ) ;
V_81 -> V_88 = false ;
F_541 ( V_81 ) ;
F_542 ( V_81 ) ;
F_406 ( V_6 ) ;
F_407 ( V_6 ) ;
if ( ! V_65 -> V_43 -> V_88 )
F_413 ( V_65 ) ;
}
}
F_870 ( V_43 ) ;
if ( V_338 -> V_570 ) {
F_933 ( V_43 -> V_57 , V_43 ) ;
if ( V_6 -> V_436 . V_1337 &&
( V_338 -> V_703 != V_6 -> V_638 ||
V_338 -> V_1055 != V_6 -> V_641 . V_52 ) )
V_6 -> V_436 . V_1337 ( V_43 ) ;
if ( ! F_934 ( V_43 ) )
F_935 ( V_6 ) ;
F_899 ( V_57 ) ;
}
F_292 (state, crtc, old_crtc_state, i) {
bool V_570 = F_25 ( V_65 -> V_43 ) ;
if ( V_570 && ! V_65 -> V_43 -> V_88 && V_65 -> V_43 -> V_480 ) {
F_310 ( & V_57 -> V_442 ) ;
F_343 ( V_65 , V_65 -> V_43 -> V_480 ) ;
F_311 ( & V_57 -> V_442 ) ;
V_65 -> V_43 -> V_480 = NULL ;
}
}
V_6 -> V_436 . V_1338 ( V_43 , & V_1323 ) ;
if ( ! V_43 -> V_1314 )
F_919 ( V_57 , V_6 , V_1323 ) ;
F_292 (state, crtc, old_crtc_state, i) {
V_1333 = F_288 ( V_65 -> V_43 ) ;
if ( V_6 -> V_436 . V_1217 )
V_6 -> V_436 . V_1217 ( V_1333 ) ;
}
F_292 (state, crtc, old_crtc_state, i) {
F_410 ( F_288 ( V_444 ) ) ;
if ( V_1335 [ V_139 ] )
F_472 ( V_6 , V_1335 [ V_139 ] ) ;
F_897 ( V_65 , V_444 , V_65 -> V_43 ) ;
}
if ( V_338 -> V_570 && F_934 ( V_43 ) )
F_936 ( V_6 ) ;
F_937 ( V_43 ) ;
if ( V_338 -> V_570 )
F_85 ( V_6 , V_1336 ) ;
F_3 ( & V_57 -> V_259 ) ;
F_917 ( V_57 , V_43 ) ;
F_5 ( & V_57 -> V_259 ) ;
F_938 ( V_43 ) ;
F_304 ( V_43 ) ;
F_939 ( V_6 ) ;
}
static void F_940 ( struct V_1141 * V_2 )
{
struct V_422 * V_43 = F_773 ( V_2 ,
struct V_422 ,
V_1339 ) ;
F_931 ( V_43 ) ;
}
static void F_941 ( struct V_422 * V_43 )
{
struct V_335 * V_1209 ;
struct V_333 * V_137 ;
int V_139 ;
F_916 (state, plane, old_plane_state, i)
F_837 ( F_186 ( V_1209 -> V_90 ) ,
F_186 ( V_137 -> V_43 -> V_90 ) ,
F_230 ( V_137 ) -> V_354 ) ;
}
static int F_942 ( struct V_56 * V_57 ,
struct V_422 * V_43 ,
bool V_1313 )
{
struct V_700 * V_338 = F_293 ( V_43 ) ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_362 = 0 ;
if ( V_338 -> V_570 && V_1313 ) {
F_158 ( L_271 ) ;
return - V_288 ;
}
V_362 = F_943 ( V_43 , V_1313 ) ;
if ( V_362 )
return V_362 ;
F_826 ( & V_43 -> V_1339 , F_940 ) ;
V_362 = F_913 ( V_57 , V_43 , V_1313 ) ;
if ( V_362 ) {
F_845 ( L_272 , V_362 ) ;
return V_362 ;
}
F_944 ( V_43 , true ) ;
V_6 -> V_403 . V_1340 = false ;
V_6 -> V_403 . V_404 = V_338 -> V_1326 ;
F_945 ( V_43 ) ;
F_941 ( V_43 ) ;
if ( V_1313 )
F_345 ( V_1341 , & V_43 -> V_1339 ) ;
else
F_931 ( V_43 ) ;
return 0 ;
}
void F_946 ( struct V_87 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_422 * V_43 ;
struct V_42 * V_62 ;
int V_362 ;
V_43 = F_537 ( V_57 ) ;
if ( ! V_43 ) {
F_158 ( L_273 ,
V_65 -> V_64 . V_377 , V_65 -> V_12 ) ;
return;
}
V_43 -> V_434 = F_840 ( V_65 ) ;
V_464:
V_62 = F_763 ( V_43 , V_65 ) ;
V_362 = F_545 ( V_62 ) ;
if ( ! V_362 ) {
if ( ! V_62 -> V_88 )
goto V_939;
V_62 -> V_423 = true ;
V_362 = F_294 ( V_43 ) ;
}
if ( V_362 == - V_425 ) {
F_841 ( V_43 ) ;
F_300 ( V_43 -> V_434 ) ;
goto V_464;
}
if ( V_362 )
V_939:
F_304 ( V_43 ) ;
}
static int F_947 ( struct V_87 * V_65 ,
T_4 * V_1342 , T_4 * V_1343 , T_4 * V_1344 ,
T_2 V_244 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_1113 * V_91 = & V_57 -> V_429 ;
struct V_42 * V_43 ;
int V_362 ;
V_362 = F_948 ( V_65 , V_1342 , V_1343 , V_1344 , V_244 ) ;
if ( V_362 )
return V_362 ;
V_43 = V_65 -> V_43 ;
F_949 ( & V_65 -> V_64 ,
V_91 -> V_1345 ,
( V_43 -> V_1346 ) ?
V_43 -> V_1346 -> V_64 . V_377 : 0 ) ;
F_949 ( & V_65 -> V_64 ,
V_91 -> V_1347 ,
( V_43 -> V_1348 ) ?
V_43 -> V_1348 -> V_64 . V_377 : 0 ) ;
F_949 ( & V_65 -> V_64 ,
V_91 -> V_1349 ,
( V_43 -> V_1350 ) ?
V_43 -> V_1350 -> V_64 . V_377 : 0 ) ;
return 0 ;
}
int
F_950 ( struct V_333 * V_137 ,
struct V_335 * V_1278 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_248 * V_90 = V_1278 -> V_90 ;
struct V_255 * V_256 = F_186 ( V_90 ) ;
struct V_255 * V_1351 = F_186 ( V_137 -> V_43 -> V_90 ) ;
struct V_1181 * V_1182 ;
int V_362 = 0 ;
if ( ! V_256 && ! V_1351 )
return 0 ;
if ( V_1351 ) {
struct V_42 * V_62 =
F_951 ( V_1278 -> V_43 , V_137 -> V_43 -> V_65 ) ;
if ( F_25 ( V_62 ) )
V_362 = F_952 ( V_1351 , true ) ;
if ( V_362 ) {
F_28 ( V_362 == - V_1199 ) ;
return V_362 ;
}
}
if ( ! V_256 )
return 0 ;
V_1182 = F_805 ( V_256 ) ;
if ( V_1182 ) {
long V_1321 ;
V_1321 = F_812 ( V_1182 , false , true ,
V_1187 ) ;
if ( V_1321 == - V_1352 )
return V_1321 ;
F_7 ( V_1321 < 0 , L_274 , V_1321 ) ;
}
if ( V_137 -> type == V_1215 &&
F_58 ( V_57 ) -> V_1353 ) {
int V_1354 = F_140 ( V_57 ) ? 16 * 1024 : 256 ;
V_362 = F_953 ( V_256 , V_1354 ) ;
if ( V_362 )
F_158 ( L_275 ) ;
} else {
struct V_254 * V_257 ;
V_257 = F_185 ( V_90 , V_1278 -> V_249 ) ;
if ( F_191 ( V_257 ) )
V_362 = F_302 ( V_257 ) ;
}
if ( V_362 == 0 ) {
F_231 ( V_1278 ) -> V_1315 =
F_831 ( & V_256 -> V_1184 ,
& V_256 -> V_64 . V_57 -> V_259 ) ;
}
return V_362 ;
}
void
F_954 ( struct V_333 * V_137 ,
struct V_335 * V_563 )
{
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_265 * V_711 ;
struct V_265 * V_338 = F_231 ( V_137 -> V_43 ) ;
struct V_255 * V_1351 = F_186 ( V_563 -> V_90 ) ;
struct V_255 * V_256 = F_186 ( V_137 -> V_43 -> V_90 ) ;
V_711 = F_231 ( V_563 ) ;
if ( ! V_256 && ! V_1351 )
return;
if ( V_1351 && ( V_137 -> type != V_1215 ||
! F_58 ( V_57 ) -> V_1353 ) )
F_196 ( V_563 -> V_90 , V_563 -> V_249 ) ;
F_955 ( & V_338 -> V_1315 , NULL ) ;
F_955 ( & V_711 -> V_1315 , NULL ) ;
}
int
F_956 ( struct V_81 * V_81 , struct V_37 * V_62 )
{
int V_1355 ;
int V_93 , V_644 ;
if ( ! V_81 || ! V_62 -> V_64 . V_508 )
return V_1356 ;
V_93 = V_62 -> V_64 . V_92 . V_93 ;
V_644 = F_293 ( V_62 -> V_64 . V_43 ) -> V_644 ;
if ( F_44 ( ! V_93 || V_644 < V_93 ) )
return V_1356 ;
V_1355 = V_60 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_644 << 8 ) / V_93 ) ) ;
return V_1355 ;
}
static int
F_957 ( struct V_333 * V_137 ,
struct V_37 * V_62 ,
struct V_265 * V_43 )
{
struct V_5 * V_6 = F_53 ( V_137 -> V_57 ) ;
struct V_87 * V_65 = V_43 -> V_64 . V_65 ;
int V_1357 = V_1356 ;
int V_1355 = V_1356 ;
bool V_1358 = false ;
int V_362 ;
if ( F_250 ( V_6 ) >= 9 ) {
if ( V_43 -> V_546 . V_330 == V_547 ) {
V_1357 = 1 ;
V_1355 = F_956 ( F_47 ( V_65 ) , V_62 ) ;
}
V_1358 = true ;
}
V_362 = F_958 ( & V_43 -> V_64 ,
& V_43 -> V_1359 ,
V_1357 , V_1355 ,
V_1358 , true ) ;
if ( V_362 )
return V_362 ;
if ( ! V_43 -> V_64 . V_90 )
return 0 ;
if ( F_250 ( V_6 ) >= 9 ) {
V_362 = F_243 ( V_43 ) ;
if ( V_362 )
return V_362 ;
}
return 0 ;
}
static void F_959 ( struct V_87 * V_65 ,
struct V_42 * V_444 )
{
struct V_56 * V_57 = V_65 -> V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_37 * V_711 =
F_288 ( V_444 ) ;
bool V_570 = F_25 ( V_65 -> V_43 ) ;
enum V_95 V_95 = V_81 -> V_95 ;
F_813 ( V_81 ) ;
if ( V_570 )
return;
if ( V_65 -> V_43 -> V_1223 || F_288 ( V_65 -> V_43 ) -> V_1299 ) {
F_447 ( V_65 -> V_43 ) ;
F_438 ( V_65 -> V_43 ) ;
}
if ( F_288 ( V_65 -> V_43 ) -> V_1299 )
F_319 ( V_81 , V_711 ) ;
else if ( F_250 ( V_6 ) >= 9 ) {
F_268 ( V_81 ) ;
F_123 ( F_960 ( V_95 ) ,
V_6 -> V_403 . V_1285 . V_1360 [ V_95 ] ) ;
}
}
static void F_961 ( struct V_87 * V_65 ,
struct V_42 * V_444 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
F_814 ( V_81 , NULL ) ;
}
void F_962 ( struct V_333 * V_137 )
{
if ( ! V_137 )
return;
F_963 ( V_137 ) ;
F_232 ( F_230 ( V_137 ) ) ;
}
static struct V_333 * F_964 ( struct V_56 * V_57 ,
int V_95 )
{
struct V_337 * V_89 = NULL ;
struct V_265 * V_43 = NULL ;
const T_2 * V_1361 ;
unsigned int V_1362 ;
int V_362 ;
V_89 = F_552 ( sizeof( * V_89 ) , V_724 ) ;
if ( ! V_89 )
goto V_786;
V_43 = F_965 ( & V_89 -> V_64 ) ;
if ( ! V_43 )
goto V_786;
V_89 -> V_64 . V_43 = & V_43 -> V_64 ;
V_89 -> V_1363 = false ;
V_89 -> V_1364 = 1 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_89 -> V_1363 = true ;
V_43 -> V_407 = - 1 ;
}
V_89 -> V_95 = V_95 ;
V_89 -> V_137 = V_95 ;
V_89 -> V_354 = F_966 ( V_95 ) ;
V_89 -> V_1365 = F_957 ;
if ( F_967 ( V_57 ) && F_58 ( V_57 ) -> V_103 < 4 )
V_89 -> V_137 = ! V_95 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
V_1361 = V_1366 ;
V_1362 = F_177 ( V_1366 ) ;
V_89 -> V_421 = F_273 ;
V_89 -> V_342 = F_283 ;
} else if ( F_15 ( V_57 ) ) {
V_1361 = V_1367 ;
V_1362 = F_177 ( V_1367 ) ;
V_89 -> V_421 = F_258 ;
V_89 -> V_342 = F_257 ;
} else if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
V_1361 = V_1367 ;
V_1362 = F_177 ( V_1367 ) ;
V_89 -> V_421 = F_244 ;
V_89 -> V_342 = F_257 ;
} else {
V_1361 = V_1368 ;
V_1362 = F_177 ( V_1368 ) ;
V_89 -> V_421 = F_244 ;
V_89 -> V_342 = F_257 ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_362 = F_968 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1369 ,
V_1361 , V_1362 ,
V_1370 ,
L_276 , F_77 ( V_95 ) ) ;
else if ( F_58 ( V_57 ) -> V_103 >= 5 || F_18 ( V_57 ) )
V_362 = F_968 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1369 ,
V_1361 , V_1362 ,
V_1370 ,
L_277 , F_77 ( V_95 ) ) ;
else
V_362 = F_968 ( V_57 , & V_89 -> V_64 , 0 ,
& V_1369 ,
V_1361 , V_1362 ,
V_1370 ,
L_278 , F_88 ( V_89 -> V_137 ) ) ;
if ( V_362 )
goto V_786;
if ( F_58 ( V_57 ) -> V_103 >= 4 )
F_969 ( V_57 , V_89 ) ;
F_970 ( & V_89 -> V_64 , & V_1371 ) ;
return & V_89 -> V_64 ;
V_786:
F_232 ( V_43 ) ;
F_232 ( V_89 ) ;
return NULL ;
}
void F_969 ( struct V_56 * V_57 , struct V_337 * V_137 )
{
if ( ! V_57 -> V_429 . V_1372 ) {
unsigned long V_330 = V_289 |
V_372 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_330 |= V_398 | V_296 ;
V_57 -> V_429 . V_1372 =
F_971 ( V_57 , V_330 ) ;
}
if ( V_57 -> V_429 . V_1372 )
F_972 ( & V_137 -> V_64 . V_64 ,
V_57 -> V_429 . V_1372 ,
V_137 -> V_64 . V_43 -> V_249 ) ;
}
static int
F_973 ( struct V_333 * V_137 ,
struct V_37 * V_62 ,
struct V_265 * V_43 )
{
struct V_248 * V_90 = V_43 -> V_64 . V_90 ;
struct V_255 * V_256 = F_186 ( V_90 ) ;
enum V_95 V_95 = F_230 ( V_137 ) -> V_95 ;
unsigned V_292 ;
int V_362 ;
V_362 = F_958 ( & V_43 -> V_64 ,
& V_43 -> V_1359 ,
V_1356 ,
V_1356 ,
true , true ) ;
if ( V_362 )
return V_362 ;
if ( ! V_256 )
return 0 ;
if ( ! F_737 ( V_137 -> V_57 , V_43 -> V_64 . V_349 , V_43 -> V_64 . V_350 ) ) {
F_215 ( L_279 ,
V_43 -> V_64 . V_349 , V_43 -> V_64 . V_350 ) ;
return - V_288 ;
}
V_292 = F_730 ( V_43 -> V_64 . V_349 ) * 4 ;
if ( V_256 -> V_64 . V_244 < V_292 * V_43 -> V_64 . V_350 ) {
F_158 ( L_280 ) ;
return - V_723 ;
}
if ( V_90 -> V_260 [ 0 ] != V_233 ) {
F_158 ( L_281 ) ;
return - V_288 ;
}
if ( F_17 ( V_137 -> V_57 ) && V_95 == V_511 &&
V_43 -> V_64 . V_340 && V_43 -> V_64 . V_347 < 0 ) {
F_158 ( L_282 ) ;
return - V_288 ;
}
return 0 ;
}
static void
F_974 ( struct V_333 * V_137 ,
struct V_87 * V_65 )
{
struct V_81 * V_81 = F_47 ( V_65 ) ;
V_81 -> V_1104 = 0 ;
F_735 ( V_65 , NULL ) ;
}
static void
F_975 ( struct V_333 * V_137 ,
const struct V_37 * V_62 ,
const struct V_265 * V_43 )
{
struct V_87 * V_65 = V_62 -> V_64 . V_65 ;
struct V_81 * V_81 = F_47 ( V_65 ) ;
struct V_56 * V_57 = V_137 -> V_57 ;
struct V_255 * V_256 = F_186 ( V_43 -> V_64 . V_90 ) ;
T_2 V_1188 ;
if ( ! V_256 )
V_1188 = 0 ;
else if ( ! F_58 ( V_57 ) -> V_1353 )
V_1188 = F_234 ( V_256 , NULL ) ;
else
V_1188 = V_256 -> V_1373 -> V_1374 ;
V_81 -> V_1104 = V_1188 ;
F_735 ( V_65 , V_43 ) ;
}
static struct V_333 * F_976 ( struct V_56 * V_57 ,
int V_95 )
{
struct V_337 * V_1375 = NULL ;
struct V_265 * V_43 = NULL ;
int V_362 ;
V_1375 = F_552 ( sizeof( * V_1375 ) , V_724 ) ;
if ( ! V_1375 )
goto V_786;
V_43 = F_965 ( & V_1375 -> V_64 ) ;
if ( ! V_43 )
goto V_786;
V_1375 -> V_64 . V_43 = & V_43 -> V_64 ;
V_1375 -> V_1363 = false ;
V_1375 -> V_1364 = 1 ;
V_1375 -> V_95 = V_95 ;
V_1375 -> V_137 = V_95 ;
V_1375 -> V_354 = F_977 ( V_95 ) ;
V_1375 -> V_1365 = F_973 ;
V_1375 -> V_421 = F_975 ;
V_1375 -> V_342 = F_974 ;
V_362 = F_968 ( V_57 , & V_1375 -> V_64 , 0 ,
& V_1369 ,
V_1376 ,
F_177 ( V_1376 ) ,
V_1215 ,
L_283 , F_77 ( V_95 ) ) ;
if ( V_362 )
goto V_786;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
if ( ! V_57 -> V_429 . V_1372 )
V_57 -> V_429 . V_1372 =
F_971 ( V_57 ,
V_289 |
V_372 ) ;
if ( V_57 -> V_429 . V_1372 )
F_972 ( & V_1375 -> V_64 . V_64 ,
V_57 -> V_429 . V_1372 ,
V_43 -> V_64 . V_249 ) ;
}
if ( F_58 ( V_57 ) -> V_103 >= 9 )
V_43 -> V_407 = - 1 ;
F_970 ( & V_1375 -> V_64 , & V_1371 ) ;
return & V_1375 -> V_64 ;
V_786:
F_232 ( V_43 ) ;
F_232 ( V_1375 ) ;
return NULL ;
}
static void F_728 ( struct V_56 * V_57 , struct V_81 * V_81 ,
struct V_37 * V_62 )
{
int V_139 ;
struct V_1377 * V_1377 ;
struct V_378 * V_379 = & V_62 -> V_379 ;
for ( V_139 = 0 ; V_139 < V_81 -> V_380 ; V_139 ++ ) {
V_1377 = & V_379 -> V_381 [ V_139 ] ;
V_1377 -> V_382 = 0 ;
V_1377 -> V_418 = V_1378 ;
}
V_379 -> V_407 = - 1 ;
}
static void F_978 ( struct V_56 * V_57 , int V_95 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_81 * V_81 ;
struct V_37 * V_62 = NULL ;
struct V_333 * V_89 = NULL ;
struct V_333 * V_1375 = NULL ;
int V_362 ;
V_81 = F_552 ( sizeof( * V_81 ) , V_724 ) ;
if ( V_81 == NULL )
return;
V_62 = F_552 ( sizeof( * V_62 ) , V_724 ) ;
if ( ! V_62 )
goto V_786;
V_81 -> V_91 = V_62 ;
V_81 -> V_64 . V_43 = & V_62 -> V_64 ;
V_62 -> V_64 . V_65 = & V_81 -> V_64 ;
if ( F_58 ( V_57 ) -> V_103 >= 9 ) {
if ( V_95 == V_511 )
V_81 -> V_380 = 1 ;
else
V_81 -> V_380 = V_1379 ;
F_728 ( V_57 , V_81 , V_62 ) ;
}
V_89 = F_964 ( V_57 , V_95 ) ;
if ( ! V_89 )
goto V_786;
V_1375 = F_976 ( V_57 , V_95 ) ;
if ( ! V_1375 )
goto V_786;
V_362 = F_979 ( V_57 , & V_81 -> V_64 , V_89 ,
V_1375 , & V_1380 ,
L_284 , F_77 ( V_95 ) ) ;
if ( V_362 )
goto V_786;
V_81 -> V_95 = V_95 ;
V_81 -> V_137 = V_95 ;
if ( F_967 ( V_57 ) && F_58 ( V_57 ) -> V_103 < 4 ) {
F_158 ( L_285 ) ;
V_81 -> V_137 = ! V_95 ;
}
V_81 -> V_1095 = ~ 0 ;
V_81 -> V_1094 = ~ 0 ;
V_81 -> V_1096 = ~ 0 ;
V_81 -> V_403 . V_566 = true ;
F_662 ( V_95 >= F_177 ( V_6 -> V_1381 ) ||
V_6 -> V_1381 [ V_81 -> V_137 ] != NULL ) ;
V_6 -> V_1381 [ V_81 -> V_137 ] = & V_81 -> V_64 ;
V_6 -> V_96 [ V_81 -> V_95 ] = & V_81 -> V_64 ;
F_980 ( & V_81 -> V_64 , & V_1382 ) ;
F_981 ( & V_81 -> V_64 ) ;
F_28 ( F_895 ( & V_81 -> V_64 ) != V_81 -> V_95 ) ;
return;
V_786:
F_962 ( V_89 ) ;
F_962 ( V_1375 ) ;
F_232 ( V_62 ) ;
F_232 ( V_81 ) ;
}
enum V_95 F_982 ( struct V_720 * V_721 )
{
struct V_619 * V_513 = V_721 -> V_64 . V_513 ;
struct V_56 * V_57 = V_721 -> V_64 . V_57 ;
F_28 ( ! F_983 ( & V_57 -> V_429 . V_1116 ) ) ;
if ( ! V_513 || F_28 ( ! V_513 -> V_65 ) )
return V_592 ;
return F_47 ( V_513 -> V_65 ) -> V_95 ;
}
int F_984 ( struct V_56 * V_57 , void * V_1048 ,
struct V_1383 * V_1384 )
{
struct V_1385 * V_1386 = V_1048 ;
struct V_87 * V_1387 ;
struct V_81 * V_65 ;
V_1387 = F_985 ( V_57 , V_1386 -> V_1388 ) ;
if ( ! V_1387 )
return - V_1389 ;
V_65 = F_47 ( V_1387 ) ;
V_1386 -> V_95 = V_65 -> V_95 ;
return 0 ;
}
static int F_986 ( struct V_512 * V_513 )
{
struct V_56 * V_57 = V_513 -> V_64 . V_57 ;
struct V_512 * V_1221 ;
int V_1390 = 0 ;
int V_1391 = 0 ;
F_660 (dev, source_encoder) {
if ( F_846 ( V_513 , V_1221 ) )
V_1390 |= ( 1 << V_1391 ) ;
V_1391 ++ ;
}
return V_1390 ;
}
static bool F_987 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! F_139 ( V_57 ) )
return false ;
if ( ( F_11 ( V_1392 ) & V_1393 ) == 0 )
return false ;
if ( F_24 ( V_57 ) && ( F_11 ( V_636 ) & V_1394 ) )
return false ;
return true ;
}
static bool F_988 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 9 )
return false ;
if ( F_572 ( V_57 ) || F_479 ( V_57 ) )
return false ;
if ( F_17 ( V_57 ) )
return false ;
if ( F_989 ( V_57 ) && F_11 ( V_1395 ) & V_1396 )
return false ;
if ( F_23 ( V_57 ) && F_11 ( F_990 ( V_601 ) ) & V_1397 )
return false ;
if ( ! V_6 -> V_805 . V_1398 )
return false ;
return true ;
}
void F_308 ( struct V_5 * V_6 )
{
int V_1399 ;
int V_1400 ;
if ( F_23 ( V_6 ) )
return;
if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_1399 = 2 ;
else
V_1399 = 1 ;
for ( V_1400 = 0 ; V_1400 < V_1399 ; V_1400 ++ ) {
T_1 V_15 = F_11 ( F_75 ( V_1400 ) ) ;
V_15 = ( V_15 & ~ V_127 ) | V_128 ;
F_123 ( F_75 ( V_1400 ) , V_15 ) ;
}
}
static void F_991 ( struct V_5 * V_6 )
{
if ( F_15 ( V_6 ) || F_36 ( V_6 ) )
V_6 -> V_1401 = V_1402 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_1401 = V_1403 ;
else
V_6 -> V_1401 = V_1404 ;
F_308 ( V_6 ) ;
}
static void F_992 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_512 * V_513 ;
bool V_1405 = false ;
F_991 ( V_6 ) ;
F_993 ( V_57 ) ;
if ( F_988 ( V_57 ) )
F_994 ( V_57 ) ;
if ( F_36 ( V_57 ) ) {
F_995 ( V_57 , V_601 ) ;
F_995 ( V_57 , V_200 ) ;
F_995 ( V_57 , V_202 ) ;
F_996 ( V_57 ) ;
} else if ( F_23 ( V_57 ) ) {
int V_75 ;
V_75 = F_11 ( F_990 ( V_601 ) ) & V_1406 ;
if ( V_75 || F_475 ( V_57 ) || F_476 ( V_57 ) )
F_995 ( V_57 , V_601 ) ;
V_75 = F_11 ( V_1395 ) ;
if ( V_75 & V_1407 )
F_995 ( V_57 , V_200 ) ;
if ( V_75 & V_1408 )
F_995 ( V_57 , V_202 ) ;
if ( V_75 & V_1409 )
F_995 ( V_57 , V_204 ) ;
if ( ( F_475 ( V_57 ) || F_476 ( V_57 ) ) &&
( V_6 -> V_805 . V_1410 [ V_606 ] . V_1411 ||
V_6 -> V_805 . V_1410 [ V_606 ] . V_1412 ||
V_6 -> V_805 . V_1410 [ V_606 ] . V_1413 ) )
F_995 ( V_57 , V_606 ) ;
} else if ( F_15 ( V_57 ) ) {
int V_75 ;
V_1405 = F_997 ( V_57 , V_204 ) ;
if ( F_987 ( V_57 ) )
F_998 ( V_57 , V_1392 , V_601 ) ;
if ( F_11 ( V_173 ) & V_1414 ) {
V_75 = F_999 ( V_57 , V_1415 , V_200 ) ;
if ( ! V_75 )
F_1000 ( V_57 , V_173 , V_200 ) ;
if ( ! V_75 && ( F_11 ( V_166 ) & V_1393 ) )
F_998 ( V_57 , V_166 , V_200 ) ;
}
if ( F_11 ( V_174 ) & V_1414 )
F_1000 ( V_57 , V_174 , V_202 ) ;
if ( ! V_1405 && F_11 ( V_175 ) & V_1414 )
F_1000 ( V_57 , V_175 , V_204 ) ;
if ( F_11 ( V_168 ) & V_1393 )
F_998 ( V_57 , V_168 , V_202 ) ;
if ( F_11 ( V_170 ) & V_1393 )
F_998 ( V_57 , V_170 , V_204 ) ;
} else if ( F_16 ( V_57 ) || F_17 ( V_57 ) ) {
bool V_1416 , V_1417 ;
V_1416 = F_997 ( V_57 , V_200 ) ;
V_1417 = F_1001 ( V_6 , V_200 ) ;
if ( F_11 ( V_1418 ) & V_1393 || V_1417 )
V_1416 &= F_998 ( V_57 , V_1418 , V_200 ) ;
if ( ( F_11 ( V_1419 ) & V_1414 || V_1417 ) && ! V_1416 )
F_1000 ( V_57 , V_1419 , V_200 ) ;
V_1416 = F_997 ( V_57 , V_202 ) ;
V_1417 = F_1001 ( V_6 , V_202 ) ;
if ( F_11 ( V_1420 ) & V_1393 || V_1417 )
V_1416 &= F_998 ( V_57 , V_1420 , V_202 ) ;
if ( ( F_11 ( V_1421 ) & V_1414 || V_1417 ) && ! V_1416 )
F_1000 ( V_57 , V_1421 , V_202 ) ;
if ( F_17 ( V_57 ) ) {
V_1417 = F_1001 ( V_6 , V_204 ) ;
if ( F_11 ( V_1422 ) & V_1393 || V_1417 )
F_998 ( V_57 , V_1422 , V_204 ) ;
if ( F_11 ( V_1423 ) & V_1414 || V_1417 )
F_1000 ( V_57 , V_1423 , V_204 ) ;
}
F_996 ( V_57 ) ;
} else if ( ! F_55 ( V_57 ) && ! F_19 ( V_57 ) ) {
bool V_75 = false ;
if ( F_11 ( V_1424 ) & V_1414 ) {
F_158 ( L_286 ) ;
V_75 = F_999 ( V_57 , V_1424 , V_200 ) ;
if ( ! V_75 && F_18 ( V_57 ) ) {
F_158 ( L_287 ) ;
F_1000 ( V_57 , V_1425 , V_200 ) ;
}
if ( ! V_75 && F_18 ( V_57 ) )
F_998 ( V_57 , V_1426 , V_200 ) ;
}
if ( F_11 ( V_1424 ) & V_1414 ) {
F_158 ( L_288 ) ;
V_75 = F_999 ( V_57 , V_1427 , V_202 ) ;
}
if ( ! V_75 && ( F_11 ( V_1427 ) & V_1414 ) ) {
if ( F_18 ( V_57 ) ) {
F_158 ( L_289 ) ;
F_1000 ( V_57 , V_1428 , V_202 ) ;
}
if ( F_18 ( V_57 ) )
F_998 ( V_57 , V_1429 , V_202 ) ;
}
if ( F_18 ( V_57 ) &&
( F_11 ( V_1430 ) & V_1393 ) )
F_998 ( V_57 , V_1430 , V_204 ) ;
} else if ( F_55 ( V_57 ) )
F_1002 ( V_57 ) ;
if ( F_1003 ( V_57 ) )
F_1004 ( V_57 ) ;
F_1005 ( V_57 ) ;
F_660 (dev, encoder) {
V_513 -> V_64 . V_1117 = V_513 -> V_1294 ;
V_513 -> V_64 . V_1431 =
F_986 ( V_513 ) ;
}
F_672 ( V_57 ) ;
F_1006 ( V_57 ) ;
}
static void F_1007 ( struct V_248 * V_90 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_266 * V_267 = F_180 ( V_90 ) ;
F_1008 ( V_90 ) ;
F_3 ( & V_57 -> V_259 ) ;
F_28 ( ! V_267 -> V_256 -> V_1432 -- ) ;
F_225 ( V_267 -> V_256 ) ;
F_5 ( & V_57 -> V_259 ) ;
F_232 ( V_267 ) ;
}
static int F_1009 ( struct V_248 * V_90 ,
struct V_1383 * V_1384 ,
unsigned int * V_1433 )
{
struct V_266 * V_267 = F_180 ( V_90 ) ;
struct V_255 * V_256 = V_267 -> V_256 ;
if ( V_256 -> V_1434 . V_559 ) {
F_215 ( L_290 ) ;
return - V_288 ;
}
return F_1010 ( V_1384 , & V_256 -> V_64 , V_1433 ) ;
}
static int F_1011 ( struct V_248 * V_90 ,
struct V_1383 * V_1384 ,
unsigned V_330 , unsigned V_1435 ,
struct V_1436 * V_1437 ,
unsigned V_1438 )
{
struct V_56 * V_57 = V_90 -> V_57 ;
struct V_266 * V_267 = F_180 ( V_90 ) ;
struct V_255 * V_256 = V_267 -> V_256 ;
F_3 ( & V_57 -> V_259 ) ;
F_1012 ( V_256 , false , V_1439 ) ;
F_5 ( & V_57 -> V_259 ) ;
return 0 ;
}
static
T_1 F_1013 ( struct V_56 * V_57 , V_55 V_231 ,
T_2 V_241 )
{
T_1 V_103 = F_58 ( V_57 ) -> V_103 ;
if ( V_103 >= 9 ) {
int V_232 = F_174 ( V_241 , 0 ) ;
return V_60 ( 8192 * V_232 , 32768 ) ;
} else if ( V_103 >= 5 && ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
return 32 * 1024 ;
} else if ( V_103 >= 4 ) {
if ( V_231 == V_234 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_103 >= 3 ) {
if ( V_231 == V_234 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_224 ( struct V_56 * V_57 ,
struct V_266 * V_267 ,
struct V_322 * V_323 ,
struct V_255 * V_256 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
unsigned int V_328 = F_1014 ( V_256 ) ;
int V_362 ;
T_1 V_1440 , V_1441 ;
char * V_1252 ;
F_28 ( ! F_187 ( & V_57 -> V_259 ) ) ;
if ( V_323 -> V_330 & V_331 ) {
if ( V_328 != V_283 &&
V_328 != F_209 ( V_323 -> V_260 [ 0 ] ) ) {
F_215 ( L_291 ) ;
return - V_288 ;
}
} else {
if ( V_328 == V_281 ) {
V_323 -> V_260 [ 0 ] = V_234 ;
} else if ( V_328 == V_282 ) {
F_215 ( L_292 ) ;
return - V_288 ;
}
}
switch ( V_323 -> V_260 [ 0 ] ) {
case V_235 :
case V_236 :
if ( F_58 ( V_57 ) -> V_103 < 9 ) {
F_215 ( L_293 ,
V_323 -> V_260 [ 0 ] ) ;
return - V_288 ;
}
case V_233 :
case V_234 :
break;
default:
F_215 ( L_294 ,
V_323 -> V_260 [ 0 ] ) ;
return - V_288 ;
}
if ( F_58 ( V_6 ) -> V_103 < 4 &&
V_328 != F_209 ( V_323 -> V_260 [ 0 ] ) ) {
F_215 ( L_295 ) ;
return - V_288 ;
}
V_1441 = F_262 ( V_6 ,
V_323 -> V_260 [ 0 ] ,
V_323 -> V_241 ) ;
if ( V_323 -> V_262 [ 0 ] & ( V_1441 - 1 ) ) {
F_215 ( L_296 ,
V_323 -> V_262 [ 0 ] , V_1441 ) ;
return - V_288 ;
}
V_1440 = F_1013 ( V_57 , V_323 -> V_260 [ 0 ] ,
V_323 -> V_241 ) ;
if ( V_323 -> V_262 [ 0 ] > V_1440 ) {
F_215 ( L_297 ,
V_323 -> V_260 [ 0 ] != V_233 ?
L_298 : L_299 ,
V_323 -> V_262 [ 0 ] , V_1440 ) ;
return - V_288 ;
}
if ( V_328 != V_283 &&
V_323 -> V_262 [ 0 ] != F_1015 ( V_256 ) ) {
F_215 ( L_300 ,
V_323 -> V_262 [ 0 ] ,
F_1015 ( V_256 ) ) ;
return - V_288 ;
}
switch ( V_323 -> V_241 ) {
case V_298 :
case V_302 :
case V_304 :
case V_316 :
break;
case V_300 :
if ( F_58 ( V_57 ) -> V_103 > 3 ) {
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
break;
case V_315 :
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) &&
F_58 ( V_57 ) -> V_103 < 9 ) {
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
break;
case V_306 :
case V_308 :
case V_310 :
if ( F_58 ( V_57 ) -> V_103 < 4 ) {
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
break;
case V_1442 :
if ( ! F_16 ( V_57 ) && ! F_17 ( V_57 ) ) {
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
break;
case V_386 :
case V_391 :
case V_389 :
case V_393 :
if ( F_58 ( V_57 ) -> V_103 < 5 ) {
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
break;
default:
V_1252 = F_863 ( V_323 -> V_241 ) ;
F_215 ( L_301 , V_1252 ) ;
F_232 ( V_1252 ) ;
return - V_288 ;
}
if ( V_323 -> V_280 [ 0 ] != 0 )
return - V_288 ;
F_1016 ( & V_267 -> V_64 , V_323 ) ;
V_267 -> V_256 = V_256 ;
V_362 = F_210 ( V_6 , & V_267 -> V_64 ) ;
if ( V_362 )
return V_362 ;
V_362 = F_1017 ( V_57 , & V_267 -> V_64 , & V_1443 ) ;
if ( V_362 ) {
F_126 ( L_302 , V_362 ) ;
return V_362 ;
}
V_267 -> V_256 -> V_1432 ++ ;
return 0 ;
}
static struct V_248 *
F_1018 ( struct V_56 * V_57 ,
struct V_1383 * V_1444 ,
const struct V_322 * V_1445 )
{
struct V_248 * V_90 ;
struct V_255 * V_256 ;
struct V_322 V_323 = * V_1445 ;
V_256 = F_1019 ( V_1444 , V_323 . V_1446 [ 0 ] ) ;
if ( ! V_256 )
return F_739 ( - V_1389 ) ;
V_90 = F_740 ( V_57 , & V_323 , V_256 ) ;
if ( F_191 ( V_90 ) )
F_749 ( V_256 ) ;
return V_90 ;
}
static inline void F_1020 ( struct V_56 * V_57 )
{
}
void F_1021 ( struct V_5 * V_6 )
{
if ( F_58 ( V_6 ) -> V_103 >= 9 ) {
V_6 -> V_436 . V_1292 = F_726 ;
V_6 -> V_436 . V_1447 =
F_683 ;
V_6 -> V_436 . V_1222 =
F_711 ;
V_6 -> V_436 . V_1324 = F_442 ;
V_6 -> V_436 . V_717 = F_454 ;
} else if ( F_23 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_726 ;
V_6 -> V_436 . V_1447 =
F_686 ;
V_6 -> V_436 . V_1222 =
F_711 ;
V_6 -> V_436 . V_1324 = F_442 ;
V_6 -> V_436 . V_717 = F_454 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_687 ;
V_6 -> V_436 . V_1447 =
F_686 ;
V_6 -> V_436 . V_1222 =
F_676 ;
V_6 -> V_436 . V_1324 = F_430 ;
V_6 -> V_436 . V_717 = F_452 ;
} else if ( F_17 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_651 ;
V_6 -> V_436 . V_1324 = F_524 ;
V_6 -> V_436 . V_717 = F_535 ;
} else if ( F_16 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_652 ;
V_6 -> V_436 . V_1324 = F_524 ;
V_6 -> V_436 . V_717 = F_535 ;
} else if ( F_18 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_648 ;
V_6 -> V_436 . V_1324 = F_533 ;
V_6 -> V_436 . V_717 = F_535 ;
} else if ( F_19 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_649 ;
V_6 -> V_436 . V_1324 = F_533 ;
V_6 -> V_436 . V_717 = F_535 ;
} else if ( ! F_55 ( V_6 ) ) {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_650 ;
V_6 -> V_436 . V_1324 = F_533 ;
V_6 -> V_436 . V_717 = F_535 ;
} else {
V_6 -> V_436 . V_1292 = F_657 ;
V_6 -> V_436 . V_1447 =
F_655 ;
V_6 -> V_436 . V_1222 = F_647 ;
V_6 -> V_436 . V_1324 = F_533 ;
V_6 -> V_436 . V_717 = F_535 ;
}
if ( F_475 ( V_6 ) || F_476 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_567 ;
else if ( F_36 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_569 ;
else if ( F_260 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_570 ;
else if ( F_259 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_571 ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_573 ;
else if ( F_24 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_574 ;
else if ( F_637 ( V_6 ) || F_182 ( V_6 ) ||
F_334 ( V_6 ) || F_325 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_575 ;
else if ( F_587 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_589 ;
else if ( F_183 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_590 ;
else if ( F_19 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_578 ;
else if ( F_588 ( V_6 ) || F_18 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_591 ;
else if ( F_564 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_576 ;
else if ( F_638 ( V_6 ) || F_79 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_577 ;
else if ( F_1022 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_580 ;
else if ( F_80 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_581 ;
else if ( F_1023 ( V_6 ) )
V_6 -> V_436 . V_640 =
F_582 ;
else {
F_7 ( ! F_140 ( V_6 ) , L_303 ) ;
V_6 -> V_436 . V_640 =
F_585 ;
}
if ( F_24 ( V_6 ) ) {
V_6 -> V_436 . V_517 = F_326 ;
} else if ( F_334 ( V_6 ) ) {
V_6 -> V_436 . V_517 = F_332 ;
} else if ( F_325 ( V_6 ) ) {
V_6 -> V_436 . V_517 = F_335 ;
} else if ( F_259 ( V_6 ) || F_260 ( V_6 ) ) {
V_6 -> V_436 . V_517 = V_1448 ;
}
if ( F_260 ( V_6 ) ) {
V_6 -> V_436 . V_1337 =
F_708 ;
V_6 -> V_436 . V_1307 =
F_707 ;
} else if ( F_16 ( V_6 ) || F_17 ( V_6 ) ) {
V_6 -> V_436 . V_1337 =
F_523 ;
V_6 -> V_436 . V_1307 =
F_518 ;
} else if ( F_36 ( V_6 ) ) {
V_6 -> V_436 . V_1337 =
F_702 ;
V_6 -> V_436 . V_1307 =
F_519 ;
} else if ( F_475 ( V_6 ) || F_476 ( V_6 ) ) {
V_6 -> V_436 . V_1337 =
F_710 ;
V_6 -> V_436 . V_1307 =
F_709 ;
}
if ( V_6 -> V_1231 . V_103 >= 9 )
V_6 -> V_436 . V_1338 = F_928 ;
else
V_6 -> V_436 . V_1338 = F_927 ;
switch ( F_58 ( V_6 ) -> V_103 ) {
case 2 :
V_6 -> V_436 . V_1206 = F_792 ;
break;
case 3 :
V_6 -> V_436 . V_1206 = F_796 ;
break;
case 4 :
case 5 :
V_6 -> V_436 . V_1206 = F_797 ;
break;
case 6 :
V_6 -> V_436 . V_1206 = F_798 ;
break;
case 7 :
case 8 :
V_6 -> V_436 . V_1206 = F_799 ;
break;
case 9 :
default:
V_6 -> V_436 . V_1206 = F_815 ;
}
}
static void F_1024 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_133 |= V_134 ;
F_1025 ( L_304 ) ;
}
static void F_1026 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_133 |= V_135 ;
F_1025 ( L_305 ) ;
}
static void F_1027 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_133 |= V_807 ;
F_1025 ( L_306 ) ;
}
static void F_1028 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_133 |= V_1449 ;
F_1025 ( L_307 ) ;
}
static void F_1029 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
V_6 -> V_133 |= V_1450 ;
F_1025 ( L_308 ) ;
}
static int F_1030 ( const struct V_1451 * V_377 )
{
F_1025 ( L_309 , V_377 -> V_1452 ) ;
return 1 ;
}
static void F_1031 ( struct V_56 * V_57 )
{
struct V_746 * V_1453 = V_57 -> V_747 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < F_177 ( V_1454 ) ; V_139 ++ ) {
struct V_1455 * V_1456 = & V_1454 [ V_139 ] ;
if ( V_1453 -> V_1457 == V_1456 -> V_1457 &&
( V_1453 -> V_1458 == V_1456 -> V_1458 ||
V_1456 -> V_1458 == V_1459 ) &&
( V_1453 -> V_1460 == V_1456 -> V_1460 ||
V_1456 -> V_1460 == V_1459 ) )
V_1456 -> V_1461 ( V_57 ) ;
}
for ( V_139 = 0 ; V_139 < F_177 ( V_1462 ) ; V_139 ++ ) {
if ( F_1032 ( * V_1462 [ V_139 ] . V_1463 ) != 0 )
V_1462 [ V_139 ] . V_1461 ( V_57 ) ;
}
}
static void F_1033 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_746 * V_747 = V_6 -> V_114 . V_747 ;
T_10 V_1464 ;
T_3 V_1465 = F_1034 ( V_57 ) ;
F_1035 ( V_747 , V_1466 ) ;
F_1036 ( V_1467 , V_1468 ) ;
V_1464 = F_1037 ( V_1469 ) ;
F_1036 ( V_1464 | 1 << 5 , V_1469 ) ;
F_1038 ( V_747 , V_1466 ) ;
F_125 ( 300 ) ;
F_123 ( V_1465 , V_1470 ) ;
F_124 ( V_1465 ) ;
}
void F_309 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_480 ( V_57 ) ;
V_6 -> V_1308 = V_6 -> V_638 ;
F_1039 ( V_57 ) ;
}
static void F_1040 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_422 * V_43 ;
struct V_87 * V_65 ;
struct V_42 * V_1046 ;
struct V_426 V_427 ;
int V_362 ;
int V_139 ;
if ( ! V_6 -> V_436 . V_1217 )
return;
F_298 ( & V_427 , 0 ) ;
V_464:
V_362 = F_299 ( V_57 , & V_427 ) ;
if ( V_362 == - V_425 ) {
F_300 ( & V_427 ) ;
goto V_464;
} else if ( F_28 ( V_362 ) ) {
goto V_786;
}
V_43 = F_301 ( V_57 , & V_427 ) ;
if ( F_28 ( F_191 ( V_43 ) ) )
goto V_786;
F_293 ( V_43 ) -> V_424 = true ;
V_362 = F_909 ( V_57 , V_43 ) ;
if ( V_362 ) {
F_7 ( true , L_310 ) ;
goto V_786;
}
F_292 (state, crtc, cstate, i) {
struct V_37 * V_1471 = F_288 ( V_1046 ) ;
V_1471 -> V_403 . V_1218 = true ;
V_6 -> V_436 . V_1217 ( V_1471 ) ;
}
F_304 ( V_43 ) ;
V_786:
F_313 ( & V_427 ) ;
F_314 ( & V_427 ) ;
}
void F_1041 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_320 * V_321 = & V_6 -> V_321 ;
int V_143 , V_362 ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
F_1042 ( V_57 ) ;
V_57 -> V_429 . V_1472 = 0 ;
V_57 -> V_429 . V_1473 = 0 ;
V_57 -> V_429 . V_1474 = 24 ;
V_57 -> V_429 . V_1475 = 1 ;
V_57 -> V_429 . V_1476 = true ;
V_57 -> V_429 . V_1013 = & V_1477 ;
F_1031 ( V_57 ) ;
F_1043 ( V_57 ) ;
if ( F_58 ( V_57 ) -> V_727 == 0 )
return;
if ( F_119 ( V_57 ) || F_105 ( V_57 ) ) {
bool V_1478 = ! ! ( F_11 ( V_952 ) &
V_958 ) ;
if ( V_6 -> V_805 . V_806 != V_1478 ) {
F_158 ( L_311 ,
V_1478 ? L_75 : L_76 ,
V_6 -> V_805 . V_806 ? L_75 : L_76 ) ;
V_6 -> V_805 . V_806 = V_1478 ;
}
}
if ( F_55 ( V_57 ) ) {
V_57 -> V_429 . V_358 = 2048 ;
V_57 -> V_429 . V_359 = 2048 ;
} else if ( F_1044 ( V_57 ) ) {
V_57 -> V_429 . V_358 = 4096 ;
V_57 -> V_429 . V_359 = 4096 ;
} else {
V_57 -> V_429 . V_358 = 8192 ;
V_57 -> V_429 . V_359 = 8192 ;
}
if ( F_79 ( V_57 ) || F_80 ( V_57 ) ) {
V_57 -> V_429 . V_1479 = F_79 ( V_57 ) ? 64 : 512 ;
V_57 -> V_429 . V_1480 = 1023 ;
} else if ( F_55 ( V_57 ) ) {
V_57 -> V_429 . V_1479 = V_1481 ;
V_57 -> V_429 . V_1480 = V_1482 ;
} else {
V_57 -> V_429 . V_1479 = V_1483 ;
V_57 -> V_429 . V_1480 = V_1484 ;
}
V_57 -> V_429 . V_1485 = V_321 -> V_1486 ;
F_158 ( L_312 ,
F_58 ( V_57 ) -> V_727 ,
F_58 ( V_57 ) -> V_727 > 1 ? L_313 : L_314 ) ;
F_90 (dev_priv, pipe) {
F_978 ( V_57 , V_95 ) ;
F_92 (dev_priv, pipe, sprite) {
V_362 = F_1045 ( V_57 , V_95 , V_143 ) ;
if ( V_362 )
F_158 ( L_315 ,
F_77 ( V_95 ) , F_95 ( V_95 , V_143 ) , V_362 ) ;
}
}
F_21 ( V_6 ) ;
F_480 ( V_57 ) ;
F_1046 ( V_57 ) ;
if ( V_6 -> V_628 == 0 )
F_474 ( V_57 ) ;
F_1033 ( V_57 ) ;
F_992 ( V_57 ) ;
F_1047 ( V_57 ) ;
F_290 ( V_57 ) ;
F_1048 ( V_57 ) ;
F_137 (dev, crtc) {
struct V_318 V_319 = {} ;
if ( ! V_65 -> V_88 )
continue;
V_6 -> V_436 . V_1447 ( V_65 ,
& V_319 ) ;
F_229 ( V_65 , & V_319 ) ;
}
F_1040 ( V_57 ) ;
}
static void F_1049 ( struct V_56 * V_57 )
{
struct V_720 * V_721 ;
struct V_577 * V_1487 = NULL ;
struct V_1110 V_1488 ;
struct V_426 * V_427 = V_57 -> V_429 . V_434 ;
F_852 (dev, connector) {
if ( V_721 -> V_513 -> type == V_616 ) {
V_1487 = & V_721 -> V_64 ;
break;
}
}
if ( ! V_1487 )
return;
if ( F_757 ( V_1487 , NULL , & V_1488 , V_427 ) )
F_764 ( V_1487 , & V_1488 , V_427 ) ;
}
static bool
F_1050 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_1 V_15 ;
if ( F_58 ( V_57 ) -> V_727 == 1 )
return true ;
V_15 = F_11 ( F_87 ( ! V_65 -> V_137 ) ) ;
if ( ( V_15 & V_138 ) &&
( ! ! ( V_15 & V_141 ) == V_65 -> V_95 ) )
return false ;
return true ;
}
static bool F_1051 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_512 * V_513 ;
F_378 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_720 * F_1052 ( struct V_512 * V_513 )
{
struct V_56 * V_57 = V_513 -> V_64 . V_57 ;
struct V_720 * V_721 ;
F_1053 (dev, &encoder->base, connector)
return V_721 ;
return NULL ;
}
static bool F_1054 ( struct V_5 * V_6 ,
enum V_94 V_224 )
{
return F_119 ( V_6 ) || F_105 ( V_6 ) ||
( F_989 ( V_6 ) && V_224 == V_221 ) ;
}
static void F_1055 ( struct V_81 * V_65 )
{
struct V_56 * V_57 = V_65 -> V_64 . V_57 ;
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_94 V_97 = V_65 -> V_91 -> V_97 ;
if ( ! F_443 ( V_97 ) ) {
T_3 V_13 = F_59 ( V_97 ) ;
F_123 ( V_13 ,
F_11 ( V_13 ) & ~ V_1489 ) ;
}
F_1056 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_88 ) {
struct V_337 * V_137 ;
F_439 ( & V_65 -> V_64 ) ;
F_1057 (dev, crtc, plane) {
if ( V_137 -> V_64 . type == V_1370 )
continue;
V_137 -> V_342 ( & V_137 -> V_64 , & V_65 -> V_64 ) ;
}
}
if ( F_58 ( V_57 ) -> V_103 < 4 && ! F_1050 ( V_65 ) ) {
bool V_137 ;
F_158 ( L_316 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 ) ;
V_137 = V_65 -> V_137 ;
F_231 ( V_65 -> V_64 . V_89 -> V_43 ) -> V_64 . V_340 = true ;
V_65 -> V_137 = ! V_137 ;
F_536 ( & V_65 -> V_64 ) ;
V_65 -> V_137 = V_137 ;
}
if ( V_6 -> V_133 & V_134 &&
V_65 -> V_95 == V_117 && ! V_65 -> V_88 ) {
F_1049 ( V_57 ) ;
}
if ( V_65 -> V_88 && ! F_1051 ( V_65 ) )
F_536 ( & V_65 -> V_64 ) ;
if ( V_65 -> V_88 || F_161 ( V_57 ) ) {
V_65 -> V_1490 = true ;
if ( F_1054 ( V_6 , (enum V_94 ) V_65 -> V_95 ) )
V_65 -> V_1491 = true ;
}
}
static void F_1058 ( struct V_512 * V_513 )
{
struct V_720 * V_721 ;
bool V_1492 = V_513 -> V_64 . V_65 &&
F_47 ( V_513 -> V_64 . V_65 ) -> V_88 ;
V_721 = F_1052 ( V_513 ) ;
if ( V_721 && ! V_1492 ) {
F_158 ( L_317 ,
V_513 -> V_64 . V_64 . V_377 ,
V_513 -> V_64 . V_12 ) ;
if ( V_513 -> V_64 . V_65 ) {
struct V_42 * V_62 = V_513 -> V_64 . V_65 -> V_43 ;
F_158 ( L_318 ,
V_513 -> V_64 . V_64 . V_377 ,
V_513 -> V_64 . V_12 ) ;
V_513 -> V_583 ( V_513 , F_288 ( V_62 ) , V_721 -> V_64 . V_43 ) ;
if ( V_513 -> V_584 )
V_513 -> V_584 ( V_513 , F_288 ( V_62 ) , V_721 -> V_64 . V_43 ) ;
}
V_513 -> V_64 . V_65 = NULL ;
V_721 -> V_64 . V_1493 = V_1494 ;
V_721 -> V_64 . V_513 = NULL ;
}
}
void F_1059 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
T_3 V_1465 = F_1034 ( V_57 ) ;
if ( ! ( F_11 ( V_1465 ) & V_1470 ) ) {
F_158 ( L_319 ) ;
F_1033 ( V_57 ) ;
}
}
void F_291 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
if ( ! F_84 ( V_6 , V_1495 ) )
return;
F_1059 ( V_57 ) ;
F_85 ( V_6 , V_1495 ) ;
}
static bool F_1060 ( struct V_337 * V_137 )
{
struct V_5 * V_6 = F_53 ( V_137 -> V_64 . V_57 ) ;
return F_11 ( F_87 ( V_137 -> V_137 ) ) & V_138 ;
}
static void F_1061 ( struct V_81 * V_65 )
{
struct V_333 * V_89 = V_65 -> V_64 . V_89 ;
struct V_265 * V_336 =
F_231 ( V_89 -> V_43 ) ;
V_336 -> V_64 . V_340 = V_65 -> V_88 &&
F_1060 ( F_230 ( V_89 ) ) ;
if ( V_336 -> V_64 . V_340 )
V_65 -> V_64 . V_43 -> V_341 |= 1 << F_235 ( V_89 ) ;
}
static void F_1062 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
struct V_512 * V_513 ;
struct V_720 * V_721 ;
int V_139 ;
V_6 -> V_704 = 0 ;
F_137 (dev, crtc) {
struct V_37 * V_62 = V_65 -> V_91 ;
int V_702 = 0 ;
F_893 ( & V_62 -> V_64 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_64 . V_65 = & V_65 -> V_64 ;
V_62 -> V_64 . V_88 = V_62 -> V_64 . V_508 =
V_6 -> V_436 . V_1292 ( V_65 , V_62 ) ;
V_65 -> V_64 . V_148 = V_62 -> V_64 . V_508 ;
V_65 -> V_88 = V_62 -> V_64 . V_88 ;
if ( V_62 -> V_64 . V_88 ) {
V_6 -> V_704 |= 1 << V_65 -> V_95 ;
if ( F_250 ( V_6 ) >= 9 || F_260 ( V_6 ) )
V_702 = F_561 ( V_62 ) ;
else if ( F_16 ( V_6 ) || F_17 ( V_6 ) )
V_702 = V_62 -> V_64 . V_92 . V_93 ;
else
F_28 ( V_6 -> V_436 . V_1307 ) ;
if ( F_260 ( V_6 ) && V_62 -> V_552 )
V_702 = F_216 ( V_702 * 100 , 95 ) ;
}
V_6 -> V_701 [ V_65 -> V_95 ] = V_702 ;
F_1061 ( V_65 ) ;
F_158 ( L_320 ,
V_65 -> V_64 . V_64 . V_377 , V_65 -> V_64 . V_12 ,
V_65 -> V_88 ? L_213 : L_214 ) ;
}
for ( V_139 = 0 ; V_139 < V_6 -> V_950 ; V_139 ++ ) {
struct V_994 * V_995 = & V_6 -> V_1300 [ V_139 ] ;
V_995 -> V_1296 = V_995 -> V_1013 . V_722 ( V_6 , V_995 ,
& V_995 -> V_91 . V_1298 ) ;
V_995 -> V_91 . V_1294 = 0 ;
F_137 (dev, crtc) {
if ( V_65 -> V_88 && V_65 -> V_91 -> V_208 == V_995 )
V_995 -> V_91 . V_1294 |= 1 << V_65 -> V_95 ;
}
V_995 -> V_1297 = V_995 -> V_91 . V_1294 ;
F_158 ( L_321 ,
V_995 -> V_12 , V_995 -> V_91 . V_1294 , V_995 -> V_1296 ) ;
}
F_660 (dev, encoder) {
V_95 = 0 ;
if ( V_513 -> V_722 ( V_513 , & V_95 ) ) {
V_65 = F_47 ( V_6 -> V_96 [ V_95 ] ) ;
V_513 -> V_64 . V_65 = & V_65 -> V_64 ;
V_65 -> V_91 -> V_1260 |= 1 << V_513 -> type ;
V_513 -> V_1293 ( V_513 , V_65 -> V_91 ) ;
} else {
V_513 -> V_64 . V_65 = NULL ;
}
F_158 ( L_322 ,
V_513 -> V_64 . V_64 . V_377 ,
V_513 -> V_64 . V_12 ,
V_513 -> V_64 . V_65 ? L_213 : L_214 ,
F_77 ( V_95 ) ) ;
}
F_852 (dev, connector) {
if ( V_721 -> V_722 ( V_721 ) ) {
V_721 -> V_64 . V_1493 = V_1496 ;
V_513 = V_721 -> V_513 ;
V_721 -> V_64 . V_513 = & V_513 -> V_64 ;
if ( V_513 -> V_64 . V_65 &&
V_513 -> V_64 . V_65 -> V_43 -> V_88 ) {
V_513 -> V_64 . V_65 -> V_43 -> V_718 |=
1 << F_1063 ( & V_721 -> V_64 ) ;
V_513 -> V_64 . V_65 -> V_43 -> V_719 |=
1 << F_1064 ( & V_513 -> V_64 ) ;
}
} else {
V_721 -> V_64 . V_1493 = V_1494 ;
V_721 -> V_64 . V_513 = NULL ;
}
F_158 ( L_323 ,
V_721 -> V_64 . V_64 . V_377 ,
V_721 -> V_64 . V_12 ,
V_721 -> V_64 . V_513 ? L_213 : L_214 ) ;
}
F_137 (dev, crtc) {
V_65 -> V_64 . V_1264 = V_65 -> V_91 -> V_64 . V_92 ;
memset ( & V_65 -> V_64 . V_418 , 0 , sizeof( V_65 -> V_64 . V_418 ) ) ;
if ( V_65 -> V_64 . V_43 -> V_88 ) {
F_642 ( & V_65 -> V_64 . V_418 , V_65 -> V_91 ) ;
F_642 ( & V_65 -> V_64 . V_43 -> V_92 , V_65 -> V_91 ) ;
F_28 ( F_540 ( V_65 -> V_64 . V_43 , & V_65 -> V_64 . V_418 ) ) ;
V_65 -> V_64 . V_43 -> V_418 . V_1311 = V_1497 ;
F_1065 ( & V_65 -> V_64 , & V_65 -> V_64 . V_1264 ) ;
F_900 ( V_65 ) ;
}
F_885 ( V_6 , V_65 -> V_91 ) ;
}
}
static void
F_290 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
enum V_95 V_95 ;
struct V_81 * V_65 ;
struct V_512 * V_513 ;
int V_139 ;
F_1062 ( V_57 ) ;
F_660 (dev, encoder) {
F_1058 ( V_513 ) ;
}
F_90 (dev_priv, pipe) {
V_65 = F_47 ( V_6 -> V_96 [ V_95 ] ) ;
F_1055 ( V_65 ) ;
F_859 ( V_65 , V_65 -> V_91 ,
L_324 ) ;
}
F_851 ( V_57 ) ;
for ( V_139 = 0 ; V_139 < V_6 -> V_950 ; V_139 ++ ) {
struct V_994 * V_995 = & V_6 -> V_1300 [ V_139 ] ;
if ( ! V_995 -> V_1296 || V_995 -> V_1297 )
continue;
F_158 ( L_325 , V_995 -> V_12 ) ;
V_995 -> V_1013 . V_583 ( V_6 , V_995 ) ;
V_995 -> V_1296 = false ;
}
if ( F_16 ( V_57 ) || F_17 ( V_57 ) )
F_1066 ( V_57 ) ;
else if ( F_704 ( V_57 ) )
F_1067 ( V_57 ) ;
else if ( F_15 ( V_57 ) )
F_1068 ( V_57 ) ;
F_137 (dev, crtc) {
unsigned long V_1335 ;
V_1335 = F_469 ( & V_65 -> V_64 , V_65 -> V_91 ) ;
if ( F_28 ( V_1335 ) )
F_472 ( V_6 , V_1335 ) ;
}
F_1069 ( V_6 , false ) ;
F_1070 ( V_6 ) ;
}
void F_1071 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_422 * V_43 = V_6 -> V_433 ;
struct V_426 V_427 ;
int V_362 ;
V_6 -> V_433 = NULL ;
if ( V_43 )
V_43 -> V_434 = & V_427 ;
F_3 ( & V_57 -> V_429 . V_430 ) ;
F_298 ( & V_427 , 0 ) ;
while ( 1 ) {
V_362 = F_299 ( V_57 , & V_427 ) ;
if ( V_362 != - V_425 )
break;
F_300 ( & V_427 ) ;
}
if ( ! V_362 )
V_362 = F_289 ( V_57 , V_43 ) ;
F_313 ( & V_427 ) ;
F_314 ( & V_427 ) ;
F_5 ( & V_57 -> V_429 . V_430 ) ;
if ( V_362 ) {
F_126 ( L_58 , V_362 ) ;
F_304 ( V_43 ) ;
}
}
void F_1072 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
struct V_87 * V_334 ;
struct V_255 * V_256 ;
F_1073 ( V_6 ) ;
F_309 ( V_57 ) ;
F_1074 ( V_6 ) ;
F_233 (dev, c) {
struct V_254 * V_257 ;
V_256 = F_186 ( V_334 -> V_89 -> V_90 ) ;
if ( V_256 == NULL )
continue;
F_3 ( & V_57 -> V_259 ) ;
V_257 = F_185 ( V_334 -> V_89 -> V_90 ,
V_334 -> V_89 -> V_43 -> V_249 ) ;
F_5 ( & V_57 -> V_259 ) ;
if ( F_191 ( V_257 ) ) {
F_126 ( L_326 ,
F_47 ( V_334 ) -> V_95 ) ;
F_227 ( V_334 -> V_89 -> V_90 ) ;
V_334 -> V_89 -> V_90 = NULL ;
V_334 -> V_89 -> V_65 = V_334 -> V_89 -> V_43 -> V_65 = NULL ;
F_226 ( V_334 -> V_89 ) ;
V_334 -> V_43 -> V_341 &= ~ ( 1 << F_235 ( V_334 -> V_89 ) ) ;
}
}
}
int F_1075 ( struct V_577 * V_721 )
{
struct V_720 * V_720 = F_857 ( V_721 ) ;
int V_362 ;
V_362 = F_1076 ( V_720 ) ;
if ( V_362 )
goto V_72;
return 0 ;
V_72:
return V_362 ;
}
void F_1077 ( struct V_577 * V_721 )
{
struct V_720 * V_720 = F_857 ( V_721 ) ;
F_1078 ( V_720 ) ;
F_1079 ( V_721 ) ;
}
void F_1080 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
F_1081 ( V_6 ) ;
F_1082 ( V_6 ) ;
F_1083 ( V_57 ) ;
F_1084 () ;
F_1085 ( V_6 ) ;
F_1086 () ;
F_1087 ( V_57 ) ;
F_1088 ( V_6 ) ;
F_1089 ( V_6 ) ;
F_1090 ( V_57 ) ;
}
void F_1091 ( struct V_720 * V_721 ,
struct V_512 * V_513 )
{
V_721 -> V_513 = V_513 ;
F_1092 ( & V_721 -> V_64 ,
& V_513 -> V_64 ) ;
}
int F_1093 ( struct V_56 * V_57 , bool V_43 )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
unsigned V_13 = F_58 ( V_57 ) -> V_103 >= 6 ? V_1498 : V_1499 ;
T_4 V_1500 ;
if ( F_579 ( V_6 -> V_1501 , V_13 , & V_1500 ) ) {
F_126 ( L_327 ) ;
return - V_1199 ;
}
if ( ! ! ( V_1500 & V_1502 ) == ! V_43 )
return 0 ;
if ( V_43 )
V_1500 &= ~ V_1502 ;
else
V_1500 |= V_1502 ;
if ( F_1094 ( V_6 -> V_1501 , V_13 , V_1500 ) ) {
F_126 ( L_328 ) ;
return - V_1199 ;
}
return 0 ;
}
struct V_1503 *
F_1095 ( struct V_5 * V_6 )
{
struct V_1503 * error ;
int V_1504 [] = {
V_221 ,
V_1505 ,
V_1506 ,
V_589 ,
} ;
int V_139 ;
if ( F_58 ( V_6 ) -> V_727 == 0 )
return NULL ;
error = F_552 ( sizeof( * error ) , V_1507 ) ;
if ( error == NULL )
return NULL ;
if ( F_259 ( V_6 ) || F_260 ( V_6 ) )
error -> V_1508 = F_11 ( V_1015 ) ;
F_90 (dev_priv, i) {
error -> V_95 [ V_139 ] . V_1509 =
F_1096 ( V_6 ,
F_466 ( V_139 ) ) ;
if ( ! error -> V_95 [ V_139 ] . V_1509 )
continue;
error -> V_1375 [ V_139 ] . V_596 = F_11 ( F_81 ( V_139 ) ) ;
error -> V_1375 [ V_139 ] . V_1510 = F_11 ( F_736 ( V_139 ) ) ;
error -> V_1375 [ V_139 ] . V_64 = F_11 ( F_732 ( V_139 ) ) ;
error -> V_137 [ V_139 ] . V_596 = F_11 ( F_87 ( V_139 ) ) ;
error -> V_137 [ V_139 ] . V_292 = F_11 ( F_251 ( V_139 ) ) ;
if ( F_250 ( V_6 ) <= 3 ) {
error -> V_137 [ V_139 ] . V_244 = F_11 ( F_245 ( V_139 ) ) ;
error -> V_137 [ V_139 ] . V_549 = F_11 ( F_246 ( V_139 ) ) ;
}
if ( F_250 ( V_6 ) <= 7 && ! F_259 ( V_6 ) )
error -> V_137 [ V_139 ] . V_1188 = F_11 ( F_256 ( V_139 ) ) ;
if ( F_250 ( V_6 ) >= 4 ) {
error -> V_137 [ V_139 ] . V_1511 = F_11 ( F_252 ( V_139 ) ) ;
error -> V_137 [ V_139 ] . V_1512 = F_11 ( F_254 ( V_139 ) ) ;
}
error -> V_95 [ V_139 ] . V_1513 = F_11 ( F_320 ( V_139 ) ) ;
if ( F_161 ( V_6 ) )
error -> V_95 [ V_139 ] . V_1514 = F_11 ( F_1097 ( V_139 ) ) ;
}
error -> V_1515 = F_58 ( V_6 ) -> V_727 ;
if ( F_23 ( V_6 ) )
error -> V_1515 ++ ;
for ( V_139 = 0 ; V_139 < error -> V_1515 ; V_139 ++ ) {
enum V_94 V_97 = V_1504 [ V_139 ] ;
error -> V_94 [ V_139 ] . V_1509 =
F_1096 ( V_6 ,
F_83 ( V_97 ) ) ;
if ( ! error -> V_94 [ V_139 ] . V_1509 )
continue;
error -> V_94 [ V_139 ] . V_97 = V_97 ;
error -> V_94 [ V_139 ] . V_1516 = F_11 ( F_59 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_893 = F_11 ( F_362 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_1517 = F_11 ( F_364 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_900 = F_11 ( F_366 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_896 = F_11 ( F_368 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_1189 = F_11 ( F_370 ( V_97 ) ) ;
error -> V_94 [ V_139 ] . V_1140 = F_11 ( F_372 ( V_97 ) ) ;
}
return error ;
}
void
F_1098 ( struct V_1518 * V_46 ,
struct V_56 * V_57 ,
struct V_1503 * error )
{
struct V_5 * V_6 = F_53 ( V_57 ) ;
int V_139 ;
if ( ! error )
return;
F_1099 ( V_46 , L_329 , F_58 ( V_57 ) -> V_727 ) ;
if ( F_259 ( V_57 ) || F_260 ( V_57 ) )
F_1099 ( V_46 , L_330 ,
error -> V_1508 ) ;
F_90 (dev_priv, i) {
F_1099 ( V_46 , L_331 , V_139 ) ;
F_1099 ( V_46 , L_332 ,
F_65 ( error -> V_95 [ V_139 ] . V_1509 ) ) ;
F_1099 ( V_46 , L_333 , error -> V_95 [ V_139 ] . V_1513 ) ;
F_1099 ( V_46 , L_334 , error -> V_95 [ V_139 ] . V_1514 ) ;
F_1099 ( V_46 , L_335 , V_139 ) ;
F_1099 ( V_46 , L_336 , error -> V_137 [ V_139 ] . V_596 ) ;
F_1099 ( V_46 , L_337 , error -> V_137 [ V_139 ] . V_292 ) ;
if ( F_58 ( V_57 ) -> V_103 <= 3 ) {
F_1099 ( V_46 , L_338 , error -> V_137 [ V_139 ] . V_244 ) ;
F_1099 ( V_46 , L_339 , error -> V_137 [ V_139 ] . V_549 ) ;
}
if ( F_58 ( V_57 ) -> V_103 <= 7 && ! F_259 ( V_57 ) )
F_1099 ( V_46 , L_340 , error -> V_137 [ V_139 ] . V_1188 ) ;
if ( F_58 ( V_57 ) -> V_103 >= 4 ) {
F_1099 ( V_46 , L_341 , error -> V_137 [ V_139 ] . V_1511 ) ;
F_1099 ( V_46 , L_342 , error -> V_137 [ V_139 ] . V_1512 ) ;
}
F_1099 ( V_46 , L_343 , V_139 ) ;
F_1099 ( V_46 , L_336 , error -> V_1375 [ V_139 ] . V_596 ) ;
F_1099 ( V_46 , L_339 , error -> V_1375 [ V_139 ] . V_1510 ) ;
F_1099 ( V_46 , L_344 , error -> V_1375 [ V_139 ] . V_64 ) ;
}
for ( V_139 = 0 ; V_139 < error -> V_1515 ; V_139 ++ ) {
F_1099 ( V_46 , L_345 ,
F_860 ( error -> V_94 [ V_139 ] . V_97 ) ) ;
F_1099 ( V_46 , L_332 ,
F_65 ( error -> V_94 [ V_139 ] . V_1509 ) ) ;
F_1099 ( V_46 , L_346 , error -> V_94 [ V_139 ] . V_1516 ) ;
F_1099 ( V_46 , L_347 , error -> V_94 [ V_139 ] . V_893 ) ;
F_1099 ( V_46 , L_348 , error -> V_94 [ V_139 ] . V_1517 ) ;
F_1099 ( V_46 , L_349 , error -> V_94 [ V_139 ] . V_900 ) ;
F_1099 ( V_46 , L_350 , error -> V_94 [ V_139 ] . V_896 ) ;
F_1099 ( V_46 , L_351 , error -> V_94 [ V_139 ] . V_1189 ) ;
F_1099 ( V_46 , L_352 , error -> V_94 [ V_139 ] . V_1140 ) ;
}
}
