static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 ;
}
int F_2 ( struct V_5 * V_6 )
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
int F_9 ( struct V_5 * V_6 ,
const char * V_12 , T_1 V_13 )
{
if ( V_6 -> V_7 == 0 )
V_6 -> V_7 = F_2 ( V_6 ) ;
return F_6 ( V_6 , V_12 , V_13 ,
V_6 -> V_7 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
if ( ! ( F_11 ( V_6 ) || F_12 ( V_6 ) ) )
return;
V_6 -> V_20 = F_9 ( V_6 , L_2 ,
V_21 ) ;
F_13 ( L_3 , V_6 -> V_20 ) ;
}
static inline T_1
F_14 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
if ( F_15 ( V_6 ) )
return V_23 -> V_24 ;
else if ( F_16 ( V_6 ) )
return ( ( F_17 ( V_25 ) & V_26 ) + 2 ) * 10000 ;
else
return 270000 ;
}
static bool
F_18 ( struct V_27 * V_28 )
{
return F_19 ( V_28 ) ;
}
static int F_20 ( int V_29 , struct V_30 * clock )
{
clock -> V_31 = clock -> V_32 + 2 ;
clock -> V_33 = clock -> V_34 * clock -> V_35 ;
if ( F_21 ( clock -> V_36 == 0 || clock -> V_33 == 0 ) )
return 0 ;
clock -> V_37 = F_8 ( V_29 * clock -> V_31 , clock -> V_36 ) ;
clock -> V_38 = F_8 ( clock -> V_37 , clock -> V_33 ) ;
return clock -> V_38 ;
}
static T_2 F_22 ( struct V_30 * V_30 )
{
return 5 * ( V_30 -> V_39 + 2 ) + ( V_30 -> V_32 + 2 ) ;
}
static int F_23 ( int V_29 , struct V_30 * clock )
{
clock -> V_31 = F_22 ( clock ) ;
clock -> V_33 = clock -> V_34 * clock -> V_35 ;
if ( F_21 ( clock -> V_36 + 2 == 0 || clock -> V_33 == 0 ) )
return 0 ;
clock -> V_37 = F_8 ( V_29 * clock -> V_31 , clock -> V_36 + 2 ) ;
clock -> V_38 = F_8 ( clock -> V_37 , clock -> V_33 ) ;
return clock -> V_38 ;
}
static int F_24 ( int V_29 , struct V_30 * clock )
{
clock -> V_31 = clock -> V_39 * clock -> V_32 ;
clock -> V_33 = clock -> V_34 * clock -> V_35 ;
if ( F_21 ( clock -> V_36 == 0 || clock -> V_33 == 0 ) )
return 0 ;
clock -> V_37 = F_8 ( V_29 * clock -> V_31 , clock -> V_36 ) ;
clock -> V_38 = F_8 ( clock -> V_37 , clock -> V_33 ) ;
return clock -> V_38 / 5 ;
}
int F_25 ( int V_29 , struct V_30 * clock )
{
clock -> V_31 = clock -> V_39 * clock -> V_32 ;
clock -> V_33 = clock -> V_34 * clock -> V_35 ;
if ( F_21 ( clock -> V_36 == 0 || clock -> V_33 == 0 ) )
return 0 ;
clock -> V_37 = F_26 ( ( V_40 ) V_29 * clock -> V_31 ,
clock -> V_36 << 22 ) ;
clock -> V_38 = F_8 ( clock -> V_37 , clock -> V_33 ) ;
return clock -> V_38 / 5 ;
}
static bool F_27 ( struct V_5 * V_6 ,
const struct V_41 * V_42 ,
const struct V_30 * clock )
{
if ( clock -> V_36 < V_42 -> V_36 . V_43 || V_42 -> V_36 . V_44 < clock -> V_36 )
F_28 ( L_4 ) ;
if ( clock -> V_34 < V_42 -> V_34 . V_43 || V_42 -> V_34 . V_44 < clock -> V_34 )
F_28 ( L_5 ) ;
if ( clock -> V_32 < V_42 -> V_32 . V_43 || V_42 -> V_32 . V_44 < clock -> V_32 )
F_28 ( L_6 ) ;
if ( clock -> V_39 < V_42 -> V_39 . V_43 || V_42 -> V_39 . V_44 < clock -> V_39 )
F_28 ( L_7 ) ;
if ( ! F_29 ( V_6 ) && ! F_11 ( V_6 ) &&
! F_12 ( V_6 ) && ! F_30 ( V_6 ) )
if ( clock -> V_39 <= clock -> V_32 )
F_28 ( L_8 ) ;
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) &&
! F_30 ( V_6 ) ) {
if ( clock -> V_33 < V_42 -> V_33 . V_43 || V_42 -> V_33 . V_44 < clock -> V_33 )
F_28 ( L_9 ) ;
if ( clock -> V_31 < V_42 -> V_31 . V_43 || V_42 -> V_31 . V_44 < clock -> V_31 )
F_28 ( L_10 ) ;
}
if ( clock -> V_37 < V_42 -> V_37 . V_43 || V_42 -> V_37 . V_44 < clock -> V_37 )
F_28 ( L_11 ) ;
if ( clock -> V_38 < V_42 -> V_38 . V_43 || V_42 -> V_38 . V_44 < clock -> V_38 )
F_28 ( L_12 ) ;
return true ;
}
static int
F_31 ( const struct V_41 * V_42 ,
const struct V_22 * V_45 ,
int V_46 )
{
struct V_47 * V_48 = V_45 -> V_49 . V_50 -> V_48 ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_33 ( V_48 ) )
return V_42 -> V_35 . V_52 ;
else
return V_42 -> V_35 . V_53 ;
} else {
if ( V_46 < V_42 -> V_35 . V_54 )
return V_42 -> V_35 . V_53 ;
else
return V_42 -> V_35 . V_52 ;
}
}
static bool
F_34 ( const struct V_41 * V_42 ,
struct V_22 * V_45 ,
int V_46 , int V_29 , struct V_30 * V_55 ,
struct V_30 * V_56 )
{
struct V_47 * V_48 = V_45 -> V_49 . V_50 -> V_48 ;
struct V_30 clock ;
int V_57 = V_46 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
clock . V_35 = F_31 ( V_42 , V_45 , V_46 ) ;
for ( clock . V_39 = V_42 -> V_39 . V_43 ; clock . V_39 <= V_42 -> V_39 . V_44 ;
clock . V_39 ++ ) {
for ( clock . V_32 = V_42 -> V_32 . V_43 ;
clock . V_32 <= V_42 -> V_32 . V_44 ; clock . V_32 ++ ) {
if ( clock . V_32 >= clock . V_39 )
break;
for ( clock . V_36 = V_42 -> V_36 . V_43 ;
clock . V_36 <= V_42 -> V_36 . V_44 ; clock . V_36 ++ ) {
for ( clock . V_34 = V_42 -> V_34 . V_43 ;
clock . V_34 <= V_42 -> V_34 . V_44 ; clock . V_34 ++ ) {
int V_58 ;
F_23 ( V_29 , & clock ) ;
if ( ! F_27 ( F_35 ( V_48 ) ,
V_42 ,
& clock ) )
continue;
if ( V_55 &&
clock . V_33 != V_55 -> V_33 )
continue;
V_58 = abs ( clock . V_38 - V_46 ) ;
if ( V_58 < V_57 ) {
* V_56 = clock ;
V_57 = V_58 ;
}
}
}
}
}
return ( V_57 != V_46 ) ;
}
static bool
F_36 ( const struct V_41 * V_42 ,
struct V_22 * V_45 ,
int V_46 , int V_29 , struct V_30 * V_55 ,
struct V_30 * V_56 )
{
struct V_47 * V_48 = V_45 -> V_49 . V_50 -> V_48 ;
struct V_30 clock ;
int V_57 = V_46 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
clock . V_35 = F_31 ( V_42 , V_45 , V_46 ) ;
for ( clock . V_39 = V_42 -> V_39 . V_43 ; clock . V_39 <= V_42 -> V_39 . V_44 ;
clock . V_39 ++ ) {
for ( clock . V_32 = V_42 -> V_32 . V_43 ;
clock . V_32 <= V_42 -> V_32 . V_44 ; clock . V_32 ++ ) {
for ( clock . V_36 = V_42 -> V_36 . V_43 ;
clock . V_36 <= V_42 -> V_36 . V_44 ; clock . V_36 ++ ) {
for ( clock . V_34 = V_42 -> V_34 . V_43 ;
clock . V_34 <= V_42 -> V_34 . V_44 ; clock . V_34 ++ ) {
int V_58 ;
F_20 ( V_29 , & clock ) ;
if ( ! F_27 ( F_35 ( V_48 ) ,
V_42 ,
& clock ) )
continue;
if ( V_55 &&
clock . V_33 != V_55 -> V_33 )
continue;
V_58 = abs ( clock . V_38 - V_46 ) ;
if ( V_58 < V_57 ) {
* V_56 = clock ;
V_57 = V_58 ;
}
}
}
}
}
return ( V_57 != V_46 ) ;
}
static bool
F_37 ( const struct V_41 * V_42 ,
struct V_22 * V_45 ,
int V_46 , int V_29 , struct V_30 * V_55 ,
struct V_30 * V_56 )
{
struct V_47 * V_48 = V_45 -> V_49 . V_50 -> V_48 ;
struct V_30 clock ;
int V_59 ;
bool V_60 = false ;
int V_61 = ( V_46 >> 8 ) + ( V_46 >> 9 ) ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
clock . V_35 = F_31 ( V_42 , V_45 , V_46 ) ;
V_59 = V_42 -> V_36 . V_44 ;
for ( clock . V_36 = V_42 -> V_36 . V_43 ; clock . V_36 <= V_59 ; clock . V_36 ++ ) {
for ( clock . V_39 = V_42 -> V_39 . V_44 ;
clock . V_39 >= V_42 -> V_39 . V_43 ; clock . V_39 -- ) {
for ( clock . V_32 = V_42 -> V_32 . V_44 ;
clock . V_32 >= V_42 -> V_32 . V_43 ; clock . V_32 -- ) {
for ( clock . V_34 = V_42 -> V_34 . V_44 ;
clock . V_34 >= V_42 -> V_34 . V_43 ; clock . V_34 -- ) {
int V_58 ;
F_23 ( V_29 , & clock ) ;
if ( ! F_27 ( F_35 ( V_48 ) ,
V_42 ,
& clock ) )
continue;
V_58 = abs ( clock . V_38 - V_46 ) ;
if ( V_58 < V_61 ) {
* V_56 = clock ;
V_61 = V_58 ;
V_59 = clock . V_36 ;
V_60 = true ;
}
}
}
}
}
return V_60 ;
}
static bool F_38 ( struct V_47 * V_48 , int V_62 ,
const struct V_30 * V_63 ,
const struct V_30 * V_56 ,
unsigned int V_64 ,
unsigned int * V_65 )
{
if ( F_12 ( F_35 ( V_48 ) ) ) {
* V_65 = 0 ;
return V_63 -> V_33 > V_56 -> V_33 ;
}
if ( F_39 ( ! V_62 ) )
return false ;
* V_65 = F_40 ( 1000000ULL *
abs ( V_62 - V_63 -> V_38 ) ,
V_62 ) ;
if ( * V_65 < 100 && V_63 -> V_33 > V_56 -> V_33 ) {
* V_65 = 0 ;
return true ;
}
return * V_65 + 10 < V_64 ;
}
static bool
F_41 ( const struct V_41 * V_42 ,
struct V_22 * V_45 ,
int V_46 , int V_29 , struct V_30 * V_55 ,
struct V_30 * V_56 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_30 clock ;
unsigned int V_67 = 1000000 ;
int V_59 = V_43 ( V_42 -> V_36 . V_44 , V_29 / 19200 ) ;
bool V_60 = false ;
V_46 *= 5 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
for ( clock . V_36 = V_42 -> V_36 . V_43 ; clock . V_36 <= V_59 ; clock . V_36 ++ ) {
for ( clock . V_34 = V_42 -> V_34 . V_44 ; clock . V_34 >= V_42 -> V_34 . V_43 ; clock . V_34 -- ) {
for ( clock . V_35 = V_42 -> V_35 . V_52 ; clock . V_35 >= V_42 -> V_35 . V_53 ;
clock . V_35 -= clock . V_35 > 10 ? 2 : 1 ) {
clock . V_33 = clock . V_34 * clock . V_35 ;
for ( clock . V_39 = V_42 -> V_39 . V_43 ; clock . V_39 <= V_42 -> V_39 . V_44 ; clock . V_39 ++ ) {
unsigned int V_68 ;
clock . V_32 = F_8 ( V_46 * clock . V_33 * clock . V_36 ,
V_29 * clock . V_39 ) ;
F_24 ( V_29 , & clock ) ;
if ( ! F_27 ( F_35 ( V_48 ) ,
V_42 ,
& clock ) )
continue;
if ( ! F_38 ( V_48 , V_46 ,
& clock ,
V_56 ,
V_67 , & V_68 ) )
continue;
* V_56 = clock ;
V_67 = V_68 ;
V_60 = true ;
}
}
}
}
return V_60 ;
}
static bool
F_43 ( const struct V_41 * V_42 ,
struct V_22 * V_45 ,
int V_46 , int V_29 , struct V_30 * V_55 ,
struct V_30 * V_56 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
unsigned int V_64 ;
struct V_30 clock ;
V_40 V_32 ;
int V_60 = false ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_64 = 1000000 ;
clock . V_36 = 1 , clock . V_39 = 2 ;
V_46 *= 5 ;
for ( clock . V_34 = V_42 -> V_34 . V_44 ; clock . V_34 >= V_42 -> V_34 . V_43 ; clock . V_34 -- ) {
for ( clock . V_35 = V_42 -> V_35 . V_52 ;
clock . V_35 >= V_42 -> V_35 . V_53 ;
clock . V_35 -= clock . V_35 > 10 ? 2 : 1 ) {
unsigned int V_65 ;
clock . V_33 = clock . V_34 * clock . V_35 ;
V_32 = F_26 ( ( ( V_40 ) V_46 * clock . V_33 *
clock . V_36 ) << 22 , V_29 * clock . V_39 ) ;
if ( V_32 > V_69 / clock . V_39 )
continue;
clock . V_32 = V_32 ;
F_25 ( V_29 , & clock ) ;
if ( ! F_27 ( F_35 ( V_48 ) , V_42 , & clock ) )
continue;
if ( ! F_38 ( V_48 , V_46 , & clock , V_56 ,
V_64 , & V_65 ) )
continue;
* V_56 = clock ;
V_64 = V_65 ;
V_60 = true ;
}
}
return V_60 ;
}
bool F_44 ( struct V_22 * V_45 , int V_70 ,
struct V_30 * V_56 )
{
int V_29 = 100000 ;
const struct V_41 * V_42 = & V_71 ;
return F_43 ( V_42 , V_45 ,
V_70 , V_29 , NULL , V_56 ) ;
}
bool F_45 ( struct V_66 * V_50 )
{
return V_50 -> V_72 && V_50 -> V_49 . V_73 -> V_28 -> V_74 &&
V_50 -> V_75 -> V_49 . V_76 . V_77 ;
}
enum V_78 F_46 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
return V_50 -> V_75 -> V_80 ;
}
static bool F_48 ( struct V_5 * V_6 , enum V_79 V_79 )
{
T_3 V_13 = F_49 ( V_79 ) ;
T_1 V_81 , V_82 ;
T_1 V_83 ;
if ( F_50 ( V_6 ) )
V_83 = V_84 ;
else
V_83 = V_85 ;
V_81 = F_17 ( V_13 ) & V_83 ;
F_51 ( 5 ) ;
V_82 = F_17 ( V_13 ) & V_83 ;
return V_81 == V_82 ;
}
static void F_52 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
enum V_79 V_79 = V_50 -> V_79 ;
if ( F_53 ( V_6 ) >= 4 ) {
T_3 V_13 = F_54 ( V_80 ) ;
if ( F_55 ( V_6 ,
V_13 , V_86 , 0 ,
100 ) )
F_7 ( 1 , L_13 ) ;
} else {
if ( F_56 ( F_48 ( V_6 , V_79 ) , 100 ) )
F_7 ( 1 , L_13 ) ;
}
}
void F_57 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
V_15 = F_17 ( F_58 ( V_79 ) ) ;
V_87 = ! ! ( V_15 & V_88 ) ;
F_59 ( V_87 != V_28 ,
L_14 ,
F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
void F_61 ( struct V_5 * V_6 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_4 ( V_6 , V_89 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_87 = V_15 & V_90 ;
F_59 ( V_87 != V_28 ,
L_15 ,
F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_62 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
bool V_87 ;
enum V_78 V_80 = F_46 ( V_6 ,
V_79 ) ;
if ( F_15 ( V_6 ) ) {
T_1 V_15 = F_17 ( F_63 ( V_80 ) ) ;
V_87 = ! ! ( V_15 & V_91 ) ;
} else {
T_1 V_15 = F_17 ( F_64 ( V_79 ) ) ;
V_87 = ! ! ( V_15 & V_92 ) ;
}
F_59 ( V_87 != V_28 ,
L_16 ,
F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_65 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
V_15 = F_17 ( F_66 ( V_79 ) ) ;
V_87 = ! ! ( V_15 & V_93 ) ;
F_59 ( V_87 != V_28 ,
L_17 ,
F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_67 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_1 V_15 ;
if ( F_16 ( V_6 ) )
return;
if ( F_15 ( V_6 ) )
return;
V_15 = F_17 ( F_64 ( V_79 ) ) ;
F_59 ( ! ( V_15 & V_94 ) , L_18 ) ;
}
void F_68 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
V_15 = F_17 ( F_66 ( V_79 ) ) ;
V_87 = ! ! ( V_15 & V_95 ) ;
F_59 ( V_87 != V_28 ,
L_19 ,
F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
void F_69 ( struct V_5 * V_6 , enum V_79 V_79 )
{
T_3 V_96 ;
T_1 V_15 ;
enum V_79 V_97 = V_98 ;
bool V_99 = true ;
if ( F_21 ( F_15 ( V_6 ) ) )
return;
if ( F_70 ( V_6 ) ) {
T_1 V_100 ;
V_96 = F_71 ( 0 ) ;
V_100 = F_17 ( F_72 ( 0 ) ) & V_101 ;
if ( V_100 == V_102 &&
F_17 ( V_103 ) & V_104 )
V_97 = V_105 ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
V_96 = F_71 ( V_79 ) ;
V_97 = V_79 ;
} else {
V_96 = F_71 ( 0 ) ;
if ( F_17 ( V_106 ) & V_104 )
V_97 = V_105 ;
}
V_15 = F_17 ( V_96 ) ;
if ( ! ( V_15 & V_107 ) ||
( ( V_15 & V_108 ) == V_109 ) )
V_99 = false ;
F_59 ( V_97 == V_79 && V_99 ,
L_20 ,
F_73 ( V_79 ) ) ;
}
static void F_74 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
bool V_87 ;
if ( F_75 ( V_6 ) || F_76 ( V_6 ) )
V_87 = F_17 ( F_77 ( V_98 ) ) & V_110 ;
else
V_87 = F_17 ( F_77 ( V_79 ) ) & V_111 ;
F_59 ( V_87 != V_28 ,
L_21 ,
F_73 ( V_79 ) , F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
void F_78 ( struct V_5 * V_6 ,
enum V_79 V_79 , bool V_28 )
{
bool V_87 ;
enum V_78 V_80 = F_46 ( V_6 ,
V_79 ) ;
enum V_112 V_113 ;
if ( ( V_79 == V_98 && V_6 -> V_114 & V_115 ) ||
( V_79 == V_105 && V_6 -> V_114 & V_116 ) )
V_28 = true ;
V_113 = F_79 ( V_80 ) ;
if ( F_80 ( V_6 , V_113 ) ) {
T_1 V_15 = F_17 ( F_54 ( V_80 ) ) ;
V_87 = ! ! ( V_15 & V_117 ) ;
F_81 ( V_6 , V_113 ) ;
} else {
V_87 = false ;
}
F_59 ( V_87 != V_28 ,
L_22 ,
F_73 ( V_79 ) , F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_82 ( struct V_5 * V_6 ,
enum V_118 V_118 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
V_15 = F_17 ( F_83 ( V_118 ) ) ;
V_87 = ! ! ( V_15 & V_119 ) ;
F_59 ( V_87 != V_28 ,
L_23 ,
F_84 ( V_118 ) , F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_85 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
int V_120 ;
if ( F_53 ( V_6 ) >= 4 ) {
T_1 V_15 = F_17 ( F_83 ( V_79 ) ) ;
F_59 ( V_15 & V_119 ,
L_24 ,
F_84 ( V_79 ) ) ;
return;
}
F_86 (dev_priv, i) {
T_1 V_15 = F_17 ( F_83 ( V_120 ) ) ;
enum V_79 V_121 = ( V_15 & V_122 ) >>
V_123 ;
F_59 ( ( V_15 & V_119 ) && V_79 == V_121 ,
L_25 ,
F_84 ( V_120 ) , F_73 ( V_79 ) ) ;
}
}
static void F_87 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
int V_124 ;
if ( F_53 ( V_6 ) >= 9 ) {
F_88 (dev_priv, pipe, sprite) {
T_1 V_15 = F_17 ( F_89 ( V_79 , V_124 ) ) ;
F_59 ( V_15 & V_125 ,
L_26 ,
V_124 , F_73 ( V_79 ) ) ;
}
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
F_88 (dev_priv, pipe, sprite) {
T_1 V_15 = F_17 ( F_90 ( V_79 , V_126 + V_124 ) ) ;
F_59 ( V_15 & V_127 ,
L_27 ,
F_91 ( V_79 , V_124 ) , F_73 ( V_79 ) ) ;
}
} else if ( F_53 ( V_6 ) >= 7 ) {
T_1 V_15 = F_17 ( F_92 ( V_79 ) ) ;
F_59 ( V_15 & V_128 ,
L_27 ,
F_84 ( V_79 ) , F_73 ( V_79 ) ) ;
} else if ( F_53 ( V_6 ) >= 5 ) {
T_1 V_15 = F_17 ( F_93 ( V_79 ) ) ;
F_59 ( V_15 & V_129 ,
L_27 ,
F_84 ( V_79 ) , F_73 ( V_79 ) ) ;
}
}
static void F_94 ( struct V_130 * V_50 )
{
if ( F_95 ( F_96 ( V_50 ) == 0 ) )
F_97 ( V_50 ) ;
}
void F_98 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_1 V_15 ;
bool V_131 ;
V_15 = F_17 ( F_99 ( V_79 ) ) ;
V_131 = ! ! ( V_15 & V_132 ) ;
F_59 ( V_131 ,
L_28 ,
F_73 ( V_79 ) ) ;
}
static bool F_100 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_100 , T_1 V_15 )
{
if ( ( V_15 & V_133 ) == 0 )
return false ;
if ( F_101 ( V_6 ) ) {
T_1 V_134 = F_17 ( F_102 ( V_79 ) ) ;
if ( ( V_134 & V_135 ) != V_100 )
return false ;
} else if ( F_12 ( V_6 ) ) {
if ( ( V_15 & V_136 ) != F_103 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_137 ) != ( V_79 << 30 ) )
return false ;
}
return true ;
}
static bool F_104 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_138 ) == 0 )
return false ;
if ( F_101 ( V_6 ) ) {
if ( ( V_15 & V_139 ) != F_105 ( V_79 ) )
return false ;
} else if ( F_12 ( V_6 ) ) {
if ( ( V_15 & V_140 ) != F_106 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_141 ) != F_107 ( V_79 ) )
return false ;
}
return true ;
}
static bool F_108 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_142 ) == 0 )
return false ;
if ( F_101 ( V_6 ) ) {
if ( ( V_15 & V_143 ) != F_109 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_144 ) != F_110 ( V_79 ) )
return false ;
}
return true ;
}
static bool F_111 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_145 ) == 0 )
return false ;
if ( F_101 ( V_6 ) ) {
if ( ( V_15 & V_143 ) != F_109 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_146 ) != F_112 ( V_79 ) )
return false ;
}
return true ;
}
static void F_113 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_3 V_13 ,
T_1 V_100 )
{
T_1 V_15 = F_17 ( V_13 ) ;
F_59 ( F_100 ( V_6 , V_79 , V_100 , V_15 ) ,
L_29 ,
F_114 ( V_13 ) , F_73 ( V_79 ) ) ;
F_59 ( F_115 ( V_6 ) && ( V_15 & V_133 ) == 0
&& ( V_15 & V_147 ) ,
L_30 ) ;
}
static void F_116 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_3 V_13 )
{
T_1 V_15 = F_17 ( V_13 ) ;
F_59 ( F_104 ( V_6 , V_79 , V_15 ) ,
L_31 ,
F_114 ( V_13 ) , F_73 ( V_79 ) ) ;
F_59 ( F_115 ( V_6 ) && ( V_15 & V_138 ) == 0
&& ( V_15 & V_148 ) ,
L_32 ) ;
}
static void F_117 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_1 V_15 ;
F_113 ( V_6 , V_79 , V_149 , V_150 ) ;
F_113 ( V_6 , V_79 , V_151 , V_152 ) ;
F_113 ( V_6 , V_79 , V_153 , V_154 ) ;
V_15 = F_17 ( V_155 ) ;
F_59 ( F_111 ( V_6 , V_79 , V_15 ) ,
L_33 ,
F_73 ( V_79 ) ) ;
V_15 = F_17 ( V_103 ) ;
F_59 ( F_108 ( V_6 , V_79 , V_15 ) ,
L_34 ,
F_73 ( V_79 ) ) ;
F_116 ( V_6 , V_79 , V_156 ) ;
F_116 ( V_6 , V_79 , V_157 ) ;
F_116 ( V_6 , V_79 , V_158 ) ;
}
static void F_118 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_119 ( F_58 ( V_79 ) , V_23 -> V_159 . V_30 ) ;
F_120 ( F_58 ( V_79 ) ) ;
F_121 ( 150 ) ;
if ( F_55 ( V_6 ,
F_58 ( V_79 ) ,
V_160 ,
V_160 ,
1 ) )
F_122 ( L_35 , V_79 ) ;
}
static void F_123 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_124 ( V_6 , V_79 ) ;
F_69 ( V_6 , V_79 ) ;
if ( V_23 -> V_159 . V_30 & V_88 )
F_118 ( V_50 , V_23 ) ;
F_119 ( F_125 ( V_79 ) , V_23 -> V_159 . V_161 ) ;
F_120 ( F_125 ( V_79 ) ) ;
}
static void F_126 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_162 V_163 = F_127 ( V_79 ) ;
T_1 V_164 ;
F_3 ( & V_6 -> V_9 ) ;
V_164 = F_128 ( V_6 , V_79 , F_129 ( V_163 ) ) ;
V_164 |= V_165 ;
F_130 ( V_6 , V_79 , F_129 ( V_163 ) , V_164 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_121 ( 1 ) ;
F_119 ( F_58 ( V_79 ) , V_23 -> V_159 . V_30 ) ;
if ( F_55 ( V_6 ,
F_58 ( V_79 ) , V_160 , V_160 ,
1 ) )
F_122 ( L_36 , V_79 ) ;
}
static void F_131 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_124 ( V_6 , V_79 ) ;
F_69 ( V_6 , V_79 ) ;
if ( V_23 -> V_159 . V_30 & V_88 )
F_126 ( V_50 , V_23 ) ;
if ( V_79 != V_98 ) {
F_119 ( V_166 , V_79 == V_105 ? V_167 : V_168 ) ;
F_119 ( F_125 ( V_105 ) , V_23 -> V_159 . V_161 ) ;
F_119 ( V_166 , 0 ) ;
V_6 -> V_169 [ V_79 ] = V_23 -> V_159 . V_161 ;
F_21 ( ( F_17 ( F_58 ( V_105 ) ) & V_170 ) == 0 ) ;
} else {
F_119 ( F_125 ( V_79 ) , V_23 -> V_159 . V_161 ) ;
F_120 ( F_125 ( V_79 ) ) ;
}
}
static int F_132 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
int V_171 = 0 ;
F_133 (&dev_priv->drm, crtc) {
V_171 += V_50 -> V_49 . V_28 -> V_72 &&
F_32 ( V_50 -> V_75 , V_172 ) ;
}
return V_171 ;
}
static void F_134 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_3 V_13 = F_58 ( V_50 -> V_79 ) ;
T_1 V_30 = V_50 -> V_75 -> V_159 . V_30 ;
F_124 ( V_6 , V_50 -> V_79 ) ;
if ( F_135 ( V_6 ) && ! F_136 ( V_6 ) )
F_69 ( V_6 , V_50 -> V_79 ) ;
if ( F_136 ( V_6 ) && F_132 ( V_6 ) > 0 ) {
V_30 |= V_173 ;
F_119 ( F_58 ( ! V_50 -> V_79 ) ,
F_17 ( F_58 ( ! V_50 -> V_79 ) ) | V_173 ) ;
}
F_119 ( V_13 , 0 ) ;
F_119 ( V_13 , V_30 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
F_119 ( F_125 ( V_50 -> V_79 ) ,
V_50 -> V_75 -> V_159 . V_161 ) ;
} else {
F_119 ( V_13 , V_30 ) ;
}
F_119 ( V_13 , V_30 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
F_119 ( V_13 , V_30 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
F_119 ( V_13 , V_30 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
}
static void F_137 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
if ( F_136 ( V_6 ) &&
F_32 ( V_50 -> V_75 , V_172 ) &&
! F_132 ( V_6 ) ) {
F_119 ( F_58 ( V_105 ) ,
F_17 ( F_58 ( V_105 ) ) & ~ V_173 ) ;
F_119 ( F_58 ( V_98 ) ,
F_17 ( F_58 ( V_98 ) ) & ~ V_173 ) ;
}
if ( ( V_79 == V_98 && V_6 -> V_114 & V_115 ) ||
( V_79 == V_105 && V_6 -> V_114 & V_116 ) )
return;
F_124 ( V_6 , V_79 ) ;
F_119 ( F_58 ( V_79 ) , V_170 ) ;
F_120 ( F_58 ( V_79 ) ) ;
}
static void F_138 ( struct V_5 * V_6 , enum V_79 V_79 )
{
T_1 V_15 ;
F_124 ( V_6 , V_79 ) ;
V_15 = V_174 |
V_175 | V_170 ;
if ( V_79 != V_98 )
V_15 |= V_176 ;
F_119 ( F_58 ( V_79 ) , V_15 ) ;
F_120 ( F_58 ( V_79 ) ) ;
}
static void F_139 ( struct V_5 * V_6 , enum V_79 V_79 )
{
enum V_162 V_163 = F_127 ( V_79 ) ;
T_1 V_15 ;
F_124 ( V_6 , V_79 ) ;
V_15 = V_177 |
V_175 | V_170 ;
if ( V_79 != V_98 )
V_15 |= V_176 ;
F_119 ( F_58 ( V_79 ) , V_15 ) ;
F_120 ( F_58 ( V_79 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_128 ( V_6 , V_79 , F_129 ( V_163 ) ) ;
V_15 &= ~ V_165 ;
F_130 ( V_6 , V_79 , F_129 ( V_163 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_140 ( struct V_5 * V_6 ,
struct V_178 * V_179 ,
unsigned int V_180 )
{
T_1 V_181 ;
T_3 V_182 ;
switch ( V_179 -> V_163 ) {
case V_183 :
V_181 = V_184 ;
V_182 = F_58 ( 0 ) ;
break;
case V_185 :
V_181 = V_186 ;
V_182 = F_58 ( 0 ) ;
V_180 <<= 4 ;
break;
case V_187 :
V_181 = V_188 ;
V_182 = V_189 ;
break;
default:
F_141 () ;
}
if ( F_55 ( V_6 ,
V_182 , V_181 , V_180 ,
1000 ) )
F_7 ( 1 , L_37 ,
F_142 ( V_179 -> V_163 ) , F_17 ( V_182 ) & V_181 , V_180 ) ;
}
static void F_143 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
struct V_66 * V_66 = F_47 ( V_6 ,
V_79 ) ;
T_3 V_13 ;
T_2 V_15 , V_190 ;
F_144 ( V_6 , V_66 -> V_75 -> V_191 ) ;
F_145 ( V_6 , V_79 ) ;
F_146 ( V_6 , V_79 ) ;
if ( F_101 ( V_6 ) ) {
V_13 = F_147 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 |= V_192 ;
F_119 ( V_13 , V_15 ) ;
}
V_13 = F_99 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_190 = F_17 ( F_54 ( V_79 ) ) ;
if ( F_115 ( V_6 ) ) {
V_15 &= ~ V_193 ;
if ( F_32 ( V_66 -> V_75 , V_194 ) )
V_15 |= V_195 ;
else
V_15 |= V_190 & V_193 ;
}
V_15 &= ~ V_196 ;
if ( ( V_190 & V_197 ) == V_198 )
if ( F_115 ( V_6 ) &&
F_32 ( V_66 -> V_75 , V_199 ) )
V_15 |= V_200 ;
else
V_15 |= V_201 ;
else
V_15 |= V_202 ;
F_119 ( V_13 , V_15 | V_132 ) ;
if ( F_55 ( V_6 ,
V_13 , V_203 , V_203 ,
100 ) )
F_122 ( L_38 , F_73 ( V_79 ) ) ;
}
static void F_148 ( struct V_5 * V_6 ,
enum V_78 V_80 )
{
T_1 V_15 , V_190 ;
F_145 ( V_6 , (enum V_79 ) V_80 ) ;
F_146 ( V_6 , V_204 ) ;
V_15 = F_17 ( F_147 ( V_98 ) ) ;
V_15 |= V_192 ;
F_119 ( F_147 ( V_98 ) , V_15 ) ;
V_15 = V_132 ;
V_190 = F_17 ( F_54 ( V_80 ) ) ;
if ( ( V_190 & V_205 ) ==
V_198 )
V_15 |= V_201 ;
else
V_15 |= V_202 ;
F_119 ( V_206 , V_15 ) ;
if ( F_55 ( V_6 ,
V_206 ,
V_203 ,
V_203 ,
100 ) )
F_122 ( L_39 ) ;
}
static void F_149 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_3 V_13 ;
T_2 V_15 ;
F_150 ( V_6 , V_79 ) ;
F_151 ( V_6 , V_79 ) ;
F_117 ( V_6 , V_79 ) ;
V_13 = F_99 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 &= ~ V_132 ;
F_119 ( V_13 , V_15 ) ;
if ( F_55 ( V_6 ,
V_13 , V_203 , 0 ,
50 ) )
F_122 ( L_40 , F_73 ( V_79 ) ) ;
if ( F_101 ( V_6 ) ) {
V_13 = F_147 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 &= ~ V_192 ;
F_119 ( V_13 , V_15 ) ;
}
}
void F_152 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_17 ( V_206 ) ;
V_15 &= ~ V_132 ;
F_119 ( V_206 , V_15 ) ;
if ( F_55 ( V_6 ,
V_206 , V_203 , 0 ,
50 ) )
F_122 ( L_41 ) ;
V_15 = F_17 ( F_147 ( V_98 ) ) ;
V_15 &= ~ V_192 ;
F_119 ( F_147 ( V_98 ) , V_15 ) ;
}
enum V_78 F_153 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
F_21 ( ! V_50 -> V_75 -> V_207 ) ;
if ( F_154 ( V_6 ) )
return V_204 ;
else
return (enum V_78 ) V_50 -> V_79 ;
}
static void F_155 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
T_3 V_13 ;
T_1 V_15 ;
F_156 ( L_42 , F_73 ( V_79 ) ) ;
F_85 ( V_6 , V_79 ) ;
F_157 ( V_6 , V_79 ) ;
F_87 ( V_6 , V_79 ) ;
if ( F_158 ( V_6 ) ) {
if ( F_32 ( V_50 -> V_75 , V_208 ) )
F_159 ( V_6 ) ;
else
F_160 ( V_6 , V_79 ) ;
} else {
if ( V_50 -> V_75 -> V_207 ) {
F_161 ( V_6 ,
(enum V_79 ) F_153 ( V_50 ) ) ;
F_67 ( V_6 ,
(enum V_79 ) V_80 ) ;
}
}
V_13 = F_54 ( V_80 ) ;
V_15 = F_17 ( V_13 ) ;
if ( V_15 & V_117 ) {
F_21 ( ! ( ( V_79 == V_98 && V_6 -> V_114 & V_115 ) ||
( V_79 == V_105 && V_6 -> V_114 & V_116 ) ) ) ;
return;
}
F_119 ( V_13 , V_15 | V_117 ) ;
F_120 ( V_13 ) ;
if ( V_48 -> V_209 == 0 &&
F_56 ( F_162 ( V_50 ) != V_50 -> V_210 , 50 ) )
F_122 ( L_43 , F_73 ( V_79 ) ) ;
}
static void F_163 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
enum V_79 V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_15 ;
F_156 ( L_44 , F_73 ( V_79 ) ) ;
F_85 ( V_6 , V_79 ) ;
F_157 ( V_6 , V_79 ) ;
F_87 ( V_6 , V_79 ) ;
V_13 = F_54 ( V_80 ) ;
V_15 = F_17 ( V_13 ) ;
if ( ( V_15 & V_117 ) == 0 )
return;
if ( V_50 -> V_75 -> V_211 )
V_15 &= ~ V_212 ;
if ( ! ( V_79 == V_98 && V_6 -> V_114 & V_115 ) &&
! ( V_79 == V_105 && V_6 -> V_114 & V_116 ) )
V_15 &= ~ V_117 ;
F_119 ( V_13 , V_15 ) ;
if ( ( V_15 & V_117 ) == 0 )
F_52 ( V_50 ) ;
}
static unsigned int F_164 ( const struct V_5 * V_6 )
{
return F_50 ( V_6 ) ? 2048 : 4096 ;
}
static unsigned int
F_165 ( const struct V_213 * V_74 , int V_118 )
{
struct V_5 * V_6 = F_35 ( V_74 -> V_48 ) ;
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
switch ( V_74 -> V_216 ) {
case V_217 :
return V_214 ;
case V_218 :
if ( F_50 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_219 :
if ( F_50 ( V_6 ) || F_166 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_220 :
switch ( V_214 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_167 ( V_214 ) ;
return V_214 ;
}
break;
default:
F_167 ( V_74 -> V_216 ) ;
return V_214 ;
}
}
static unsigned int
F_168 ( const struct V_213 * V_74 , int V_118 )
{
if ( V_74 -> V_216 == V_217 )
return 1 ;
else
return F_164 ( F_35 ( V_74 -> V_48 ) ) /
F_165 ( V_74 , V_118 ) ;
}
static void F_169 ( const struct V_213 * V_74 , int V_118 ,
unsigned int * V_221 ,
unsigned int * V_222 )
{
unsigned int V_223 = F_165 ( V_74 , V_118 ) ;
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
* V_221 = V_223 / V_214 ;
* V_222 = F_164 ( F_35 ( V_74 -> V_48 ) ) / V_223 ;
}
unsigned int
F_170 ( const struct V_213 * V_74 ,
int V_118 , unsigned int V_224 )
{
unsigned int V_222 = F_168 ( V_74 , V_118 ) ;
return F_171 ( V_224 , V_222 ) ;
}
unsigned int F_172 ( const struct V_225 * V_226 )
{
unsigned int V_227 = 0 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_173 ( V_226 -> V_118 ) ; V_120 ++ )
V_227 += V_226 -> V_118 [ V_120 ] . V_228 * V_226 -> V_118 [ V_120 ] . V_224 ;
return V_227 ;
}
static void
F_174 ( struct V_229 * V_230 ,
const struct V_213 * V_74 ,
unsigned int V_231 )
{
V_230 -> type = V_232 ;
if ( F_175 ( V_231 ) ) {
V_230 -> type = V_233 ;
V_230 -> V_234 = F_176 ( V_74 ) -> V_226 ;
}
}
static unsigned int F_177 ( const struct V_5 * V_6 )
{
if ( F_178 ( V_6 ) -> V_235 >= 9 )
return 256 * 1024 ;
else if ( F_179 ( V_6 ) || F_180 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
return 128 * 1024 ;
else if ( F_178 ( V_6 ) -> V_235 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_181 ( const struct V_213 * V_74 ,
int V_118 )
{
struct V_5 * V_6 = F_35 ( V_74 -> V_48 ) ;
if ( V_74 -> V_215 -> V_215 == V_236 && V_118 == 1 )
return 4096 ;
switch ( V_74 -> V_216 ) {
case V_217 :
return F_177 ( V_6 ) ;
case V_218 :
if ( F_53 ( V_6 ) >= 9 )
return 256 * 1024 ;
return 0 ;
case V_219 :
case V_220 :
return 1 * 1024 * 1024 ;
default:
F_167 ( V_74 -> V_216 ) ;
return 0 ;
}
}
struct V_237 *
F_182 ( struct V_213 * V_74 , unsigned int V_231 )
{
struct V_47 * V_48 = V_74 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_238 * V_239 = F_183 ( V_74 ) ;
struct V_229 V_230 ;
struct V_237 * V_240 ;
T_1 V_241 ;
F_21 ( ! F_184 ( & V_48 -> V_242 ) ) ;
V_241 = F_181 ( V_74 , 0 ) ;
F_174 ( & V_230 , V_74 , V_231 ) ;
if ( F_185 ( V_6 ) && V_241 < 256 * 1024 )
V_241 = 256 * 1024 ;
F_186 ( V_6 ) ;
V_240 = F_187 ( V_239 , V_241 , & V_230 ) ;
if ( F_188 ( V_240 ) )
goto V_57;
if ( F_189 ( V_240 ) ) {
if ( F_190 ( V_240 ) == 0 )
F_191 ( V_240 ) ;
}
F_192 ( V_240 ) ;
V_57:
F_193 ( V_6 ) ;
return V_240 ;
}
void F_194 ( struct V_237 * V_240 )
{
F_195 ( & V_240 -> V_243 -> V_244 -> V_245 . V_242 ) ;
F_196 ( V_240 ) ;
F_197 ( V_240 ) ;
F_198 ( V_240 ) ;
}
static int F_199 ( const struct V_213 * V_74 , int V_118 ,
unsigned int V_231 )
{
if ( F_175 ( V_231 ) )
return F_176 ( V_74 ) -> V_234 [ V_118 ] . V_246 ;
else
return V_74 -> V_247 [ V_118 ] ;
}
T_1 F_200 ( int V_248 , int V_249 ,
const struct V_250 * V_28 ,
int V_118 )
{
const struct V_213 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
unsigned int V_246 = V_74 -> V_247 [ V_118 ] ;
return V_249 * V_246 + V_248 * V_214 ;
}
void F_201 ( int * V_248 , int * V_249 ,
const struct V_250 * V_28 ,
int V_118 )
{
const struct V_251 * V_252 = F_176 ( V_28 -> V_49 . V_74 ) ;
unsigned int V_231 = V_28 -> V_49 . V_231 ;
if ( F_175 ( V_231 ) ) {
* V_248 += V_252 -> V_234 [ V_118 ] . V_248 ;
* V_249 += V_252 -> V_234 [ V_118 ] . V_249 ;
} else {
* V_248 += V_252 -> V_253 [ V_118 ] . V_248 ;
* V_249 += V_252 -> V_253 [ V_118 ] . V_249 ;
}
}
static T_1 F_202 ( int * V_248 , int * V_249 ,
unsigned int V_221 ,
unsigned int V_222 ,
unsigned int V_254 ,
unsigned int V_255 ,
T_1 V_256 ,
T_1 V_257 )
{
unsigned int V_258 = V_255 * V_221 ;
unsigned int V_259 ;
F_21 ( V_256 & ( V_254 - 1 ) ) ;
F_21 ( V_257 & ( V_254 - 1 ) ) ;
F_21 ( V_257 > V_256 ) ;
V_259 = ( V_256 - V_257 ) / V_254 ;
* V_249 += V_259 / V_255 * V_222 ;
* V_248 += V_259 % V_255 * V_221 ;
* V_249 += * V_248 / V_258 * V_222 ;
* V_248 %= V_258 ;
return V_257 ;
}
static T_1 F_203 ( int * V_248 , int * V_249 ,
const struct V_250 * V_28 , int V_118 ,
T_1 V_256 , T_1 V_257 )
{
const struct V_5 * V_6 = F_35 ( V_28 -> V_49 . V_118 -> V_48 ) ;
const struct V_213 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
unsigned int V_231 = V_28 -> V_49 . V_231 ;
unsigned int V_246 = F_199 ( V_74 , V_118 , V_231 ) ;
F_21 ( V_257 > V_256 ) ;
if ( V_74 -> V_216 != V_217 ) {
unsigned int V_254 , V_221 , V_222 ;
unsigned int V_255 ;
V_254 = F_164 ( V_6 ) ;
F_169 ( V_74 , V_118 , & V_221 , & V_222 ) ;
if ( F_175 ( V_231 ) ) {
V_255 = V_246 / V_222 ;
F_204 ( V_221 , V_222 ) ;
} else {
V_255 = V_246 / ( V_221 * V_214 ) ;
}
F_202 ( V_248 , V_249 , V_221 , V_222 ,
V_254 , V_255 ,
V_256 , V_257 ) ;
} else {
V_256 += * V_249 * V_246 + * V_248 * V_214 ;
* V_249 = ( V_256 - V_257 ) / V_246 ;
* V_248 = ( ( V_256 - V_257 ) - * V_249 * V_246 ) / V_214 ;
}
return V_257 ;
}
static T_1 F_205 ( const struct V_5 * V_6 ,
int * V_248 , int * V_249 ,
const struct V_213 * V_74 , int V_118 ,
unsigned int V_246 ,
unsigned int V_231 ,
T_1 V_241 )
{
V_40 V_260 = V_74 -> V_216 ;
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
T_1 V_261 , V_262 ;
if ( V_241 )
V_241 -- ;
if ( V_260 != V_217 ) {
unsigned int V_254 , V_221 , V_222 ;
unsigned int V_263 , V_259 , V_255 ;
V_254 = F_164 ( V_6 ) ;
F_169 ( V_74 , V_118 , & V_221 , & V_222 ) ;
if ( F_175 ( V_231 ) ) {
V_255 = V_246 / V_222 ;
F_204 ( V_221 , V_222 ) ;
} else {
V_255 = V_246 / ( V_221 * V_214 ) ;
}
V_263 = * V_249 / V_222 ;
* V_249 %= V_222 ;
V_259 = * V_248 / V_221 ;
* V_248 %= V_221 ;
V_261 = ( V_263 * V_255 + V_259 ) * V_254 ;
V_262 = V_261 & ~ V_241 ;
F_202 ( V_248 , V_249 , V_221 , V_222 ,
V_254 , V_255 ,
V_261 , V_262 ) ;
} else {
V_261 = * V_249 * V_246 + * V_248 * V_214 ;
V_262 = V_261 & ~ V_241 ;
* V_249 = ( V_261 & V_241 ) / V_246 ;
* V_248 = ( ( V_261 & V_241 ) - * V_249 * V_246 ) / V_214 ;
}
return V_262 ;
}
T_1 F_206 ( int * V_248 , int * V_249 ,
const struct V_250 * V_28 ,
int V_118 )
{
const struct V_5 * V_6 = F_35 ( V_28 -> V_49 . V_118 -> V_48 ) ;
const struct V_213 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_231 = V_28 -> V_49 . V_231 ;
int V_246 = F_199 ( V_74 , V_118 , V_231 ) ;
T_1 V_241 = F_181 ( V_74 , V_118 ) ;
return F_205 ( V_6 , V_248 , V_249 , V_74 , V_118 , V_246 ,
V_231 , V_241 ) ;
}
static void F_207 ( int * V_248 , int * V_249 ,
const struct V_213 * V_74 , int V_118 )
{
unsigned int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
unsigned int V_246 = V_74 -> V_247 [ V_118 ] ;
T_1 V_264 = V_74 -> V_265 [ V_118 ] ;
* V_249 = V_264 / V_246 ;
* V_248 = V_264 % V_246 / V_214 ;
}
static unsigned int F_208 ( V_40 V_260 )
{
switch ( V_260 ) {
case V_218 :
return V_266 ;
case V_219 :
return V_267 ;
default:
return V_268 ;
}
}
static int
F_209 ( struct V_5 * V_6 ,
struct V_213 * V_74 )
{
struct V_251 * V_252 = F_176 ( V_74 ) ;
struct V_225 * V_226 = & V_252 -> V_226 ;
T_1 V_269 = 0 ;
unsigned int V_270 = 0 ;
int V_120 , V_271 = V_74 -> V_215 -> V_271 ;
unsigned int V_254 = F_164 ( V_6 ) ;
for ( V_120 = 0 ; V_120 < V_271 ; V_120 ++ ) {
unsigned int V_228 , V_224 ;
unsigned int V_214 , V_227 ;
T_1 V_261 ;
int V_248 , V_249 ;
V_214 = V_74 -> V_215 -> V_214 [ V_120 ] ;
V_228 = F_210 ( V_74 -> V_228 , V_74 , V_120 ) ;
V_224 = F_211 ( V_74 -> V_224 , V_74 , V_120 ) ;
F_207 ( & V_248 , & V_249 , V_74 , V_120 ) ;
if ( F_212 ( V_252 -> V_239 ) &&
( V_248 + V_228 ) * V_214 > V_74 -> V_247 [ V_120 ] ) {
F_156 ( L_45 ,
V_120 , V_74 -> V_265 [ V_120 ] ) ;
return - V_272 ;
}
V_252 -> V_253 [ V_120 ] . V_248 = V_248 ;
V_252 -> V_253 [ V_120 ] . V_249 = V_249 ;
V_261 = F_205 ( V_6 , & V_248 , & V_249 ,
V_74 , V_120 , V_74 -> V_247 [ V_120 ] ,
V_273 , V_254 ) ;
V_261 /= V_254 ;
if ( V_74 -> V_216 != V_217 ) {
unsigned int V_221 , V_222 ;
unsigned int V_255 ;
struct V_274 V_275 ;
F_169 ( V_74 , V_120 , & V_221 , & V_222 ) ;
V_226 -> V_118 [ V_120 ] . V_261 = V_261 ;
V_226 -> V_118 [ V_120 ] . V_276 = F_213 ( V_74 -> V_247 [ V_120 ] , V_221 * V_214 ) ;
V_226 -> V_118 [ V_120 ] . V_228 = F_213 ( V_248 + V_228 , V_221 ) ;
V_226 -> V_118 [ V_120 ] . V_224 = F_213 ( V_249 + V_224 , V_222 ) ;
V_252 -> V_234 [ V_120 ] . V_246 =
V_226 -> V_118 [ V_120 ] . V_224 * V_222 ;
V_227 = V_226 -> V_118 [ V_120 ] . V_276 * V_226 -> V_118 [ V_120 ] . V_224 ;
if ( V_248 != 0 )
V_227 ++ ;
V_275 . V_277 = V_248 ;
V_275 . y1 = V_249 ;
V_275 . V_278 = V_248 + V_228 ;
V_275 . V_279 = V_249 + V_224 ;
F_214 ( & V_275 ,
V_226 -> V_118 [ V_120 ] . V_228 * V_221 ,
V_226 -> V_118 [ V_120 ] . V_224 * V_222 ,
V_280 ) ;
V_248 = V_275 . V_277 ;
V_249 = V_275 . y1 ;
V_255 = V_252 -> V_234 [ V_120 ] . V_246 / V_222 ;
F_204 ( V_221 , V_222 ) ;
F_202 ( & V_248 , & V_249 ,
V_221 , V_222 ,
V_254 , V_255 ,
V_269 * V_254 , 0 ) ;
V_269 += V_226 -> V_118 [ V_120 ] . V_228 * V_226 -> V_118 [ V_120 ] . V_224 ;
V_252 -> V_234 [ V_120 ] . V_248 = V_248 ;
V_252 -> V_234 [ V_120 ] . V_249 = V_249 ;
} else {
V_227 = F_213 ( ( V_249 + V_224 ) * V_74 -> V_247 [ V_120 ] +
V_248 * V_214 , V_254 ) ;
}
V_270 = V_44 ( V_270 , V_261 + V_227 ) ;
}
if ( V_270 * V_254 > V_252 -> V_239 -> V_49 . V_227 ) {
F_156 ( L_46 ,
V_270 * V_254 , V_252 -> V_239 -> V_49 . V_227 ) ;
return - V_272 ;
}
return 0 ;
}
static int F_215 ( int V_215 )
{
switch ( V_215 ) {
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
default:
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
}
}
static int F_216 ( int V_215 , bool V_295 , bool V_296 )
{
switch ( V_215 ) {
case V_297 :
return V_286 ;
default:
case V_298 :
if ( V_295 ) {
if ( V_296 )
return V_299 ;
else
return V_290 ;
} else {
if ( V_296 )
return V_300 ;
else
return V_288 ;
}
case V_301 :
if ( V_295 )
return V_294 ;
else
return V_292 ;
}
}
static bool
F_217 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_304 * V_305 = & V_6 -> V_305 ;
struct V_238 * V_239 = NULL ;
struct V_306 V_307 = { 0 } ;
struct V_213 * V_74 = & V_303 -> V_74 -> V_49 ;
T_1 V_308 = F_218 ( V_303 -> V_49 , V_309 ) ;
T_1 V_310 = F_219 ( V_303 -> V_49 + V_303 -> V_227 ,
V_309 ) ;
V_310 -= V_308 ;
if ( V_303 -> V_227 == 0 )
return false ;
if ( V_310 * 2 > V_305 -> V_311 )
return false ;
F_3 ( & V_48 -> V_242 ) ;
V_239 = F_220 ( V_6 ,
V_308 ,
V_308 ,
V_310 ) ;
F_5 ( & V_48 -> V_242 ) ;
if ( ! V_239 )
return false ;
if ( V_303 -> V_312 == V_266 )
V_239 -> V_313 = V_74 -> V_247 [ 0 ] | V_266 ;
V_307 . V_314 = V_74 -> V_215 -> V_215 ;
V_307 . V_228 = V_74 -> V_228 ;
V_307 . V_224 = V_74 -> V_224 ;
V_307 . V_247 [ 0 ] = V_74 -> V_247 [ 0 ] ;
V_307 . V_216 [ 0 ] = V_74 -> V_216 ;
V_307 . V_315 = V_316 ;
if ( F_221 ( F_176 ( V_74 ) , V_239 , & V_307 ) ) {
F_156 ( L_47 ) ;
goto V_317;
}
F_156 ( L_48 , V_239 ) ;
return true ;
V_317:
F_222 ( V_239 ) ;
return false ;
}
static void
F_223 ( struct V_318 * V_118 )
{
if ( V_118 -> V_74 == V_118 -> V_28 -> V_74 )
return;
if ( V_118 -> V_28 -> V_74 )
F_224 ( V_118 -> V_28 -> V_74 ) ;
V_118 -> V_28 -> V_74 = V_118 -> V_74 ;
if ( V_118 -> V_28 -> V_74 )
F_225 ( V_118 -> V_28 -> V_74 ) ;
}
static void
F_226 ( struct V_22 * V_45 ,
struct V_250 * V_319 ,
bool V_320 )
{
struct V_321 * V_118 = F_227 ( V_319 -> V_49 . V_118 ) ;
V_319 -> V_49 . V_320 = V_320 ;
if ( V_320 ) {
V_45 -> V_49 . V_322 |= F_228 ( F_229 ( & V_118 -> V_49 ) ) ;
V_45 -> V_323 |= F_228 ( V_118 -> V_324 ) ;
} else {
V_45 -> V_49 . V_322 &= ~ F_228 ( F_229 ( & V_118 -> V_49 ) ) ;
V_45 -> V_323 &= ~ F_228 ( V_118 -> V_324 ) ;
}
F_156 ( L_49 ,
V_45 -> V_49 . V_50 -> V_12 ,
V_45 -> V_323 ) ;
}
static void
F_230 ( struct V_66 * V_66 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_130 * V_325 ;
struct V_238 * V_239 ;
struct V_318 * V_73 = V_66 -> V_49 . V_73 ;
struct V_326 * V_319 = V_73 -> V_28 ;
struct V_27 * V_45 = V_66 -> V_49 . V_28 ;
struct V_321 * V_321 = F_227 ( V_73 ) ;
struct V_250 * V_327 =
F_231 ( V_319 ) ;
struct V_213 * V_74 ;
if ( ! V_303 -> V_74 )
return;
if ( F_217 ( V_66 , V_303 ) ) {
V_74 = & V_303 -> V_74 -> V_49 ;
goto V_328;
}
F_232 ( V_303 -> V_74 ) ;
F_233 (dev, c) {
struct V_250 * V_28 ;
if ( V_325 == & V_66 -> V_49 )
continue;
if ( ! F_42 ( V_325 ) -> V_72 )
continue;
V_28 = F_231 ( V_325 -> V_73 -> V_28 ) ;
if ( ! V_28 -> V_240 )
continue;
if ( F_234 ( V_28 ) == V_303 -> V_49 ) {
V_74 = V_325 -> V_73 -> V_74 ;
F_225 ( V_74 ) ;
goto V_328;
}
}
F_226 ( F_235 ( V_45 ) ,
F_231 ( V_319 ) ,
false ) ;
F_236 ( & V_66 -> V_49 ) ;
F_237 ( V_73 , V_66 ) ;
V_321 -> V_329 ( V_73 , & V_66 -> V_49 ) ;
return;
V_328:
F_3 ( & V_48 -> V_242 ) ;
V_327 -> V_240 =
F_182 ( V_74 , V_73 -> V_28 -> V_231 ) ;
F_5 ( & V_48 -> V_242 ) ;
if ( F_188 ( V_327 -> V_240 ) ) {
F_122 ( L_50 ,
V_66 -> V_79 , F_238 ( V_327 -> V_240 ) ) ;
V_327 -> V_240 = NULL ;
F_224 ( V_74 ) ;
return;
}
V_319 -> V_330 = 0 ;
V_319 -> V_331 = 0 ;
V_319 -> V_332 = V_74 -> V_228 << 16 ;
V_319 -> V_333 = V_74 -> V_224 << 16 ;
V_319 -> V_334 = 0 ;
V_319 -> V_335 = 0 ;
V_319 -> V_336 = V_74 -> V_228 ;
V_319 -> V_337 = V_74 -> V_224 ;
V_327 -> V_49 . V_338 = F_239 ( V_319 ) ;
V_327 -> V_49 . V_339 = F_240 ( V_319 ) ;
V_239 = F_183 ( V_74 ) ;
if ( F_212 ( V_239 ) )
V_6 -> V_340 = true ;
F_225 ( V_74 ) ;
V_73 -> V_74 = V_73 -> V_28 -> V_74 = V_74 ;
V_73 -> V_50 = V_73 -> V_28 -> V_50 = & V_66 -> V_49 ;
F_226 ( F_235 ( V_45 ) ,
F_231 ( V_319 ) ,
true ) ;
F_241 ( F_227 ( V_73 ) -> V_341 ,
& V_239 -> V_342 ) ;
}
static int F_242 ( const struct V_213 * V_74 , int V_118 ,
unsigned int V_231 )
{
int V_214 = V_74 -> V_215 -> V_214 [ V_118 ] ;
switch ( V_74 -> V_216 ) {
case V_217 :
case V_218 :
switch ( V_214 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_167 ( V_214 ) ;
break;
}
break;
case V_219 :
case V_220 :
switch ( V_214 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_167 ( V_214 ) ;
break;
}
break;
default:
F_167 ( V_74 -> V_216 ) ;
}
return 2048 ;
}
static int F_243 ( struct V_250 * V_319 )
{
const struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
int V_248 = V_319 -> V_49 . V_338 . V_277 >> 16 ;
int V_249 = V_319 -> V_49 . V_338 . y1 >> 16 ;
int V_343 = F_244 ( & V_319 -> V_49 . V_338 ) >> 16 ;
int V_344 = F_245 ( & V_319 -> V_49 . V_338 ) >> 16 ;
int V_345 = F_242 ( V_74 , 0 , V_231 ) ;
int V_346 = 4096 ;
T_1 V_241 , V_261 , V_347 = V_319 -> V_348 . V_261 ;
if ( V_343 > V_345 || V_344 > V_346 ) {
F_156 ( L_51 ,
V_343 , V_344 , V_345 , V_346 ) ;
return - V_272 ;
}
F_201 ( & V_248 , & V_249 , V_319 , 0 ) ;
V_261 = F_206 ( & V_248 , & V_249 , V_319 , 0 ) ;
V_241 = F_181 ( V_74 , 0 ) ;
if ( V_261 > V_347 )
V_261 = F_203 ( & V_248 , & V_249 , V_319 , 0 ,
V_261 , V_347 & ~ ( V_241 - 1 ) ) ;
if ( V_74 -> V_216 == V_218 ) {
int V_214 = V_74 -> V_215 -> V_214 [ 0 ] ;
while ( ( V_248 + V_343 ) * V_214 > V_74 -> V_247 [ 0 ] ) {
if ( V_261 == 0 ) {
F_156 ( L_52 ) ;
return - V_272 ;
}
V_261 = F_203 ( & V_248 , & V_249 , V_319 , 0 ,
V_261 , V_261 - V_241 ) ;
}
}
V_319 -> main. V_261 = V_261 ;
V_319 -> main. V_248 = V_248 ;
V_319 -> main. V_249 = V_249 ;
return 0 ;
}
static int F_246 ( struct V_250 * V_319 )
{
const struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
int V_345 = F_242 ( V_74 , 1 , V_231 ) ;
int V_346 = 4096 ;
int V_248 = V_319 -> V_49 . V_338 . V_277 >> 17 ;
int V_249 = V_319 -> V_49 . V_338 . y1 >> 17 ;
int V_343 = F_244 ( & V_319 -> V_49 . V_338 ) >> 17 ;
int V_344 = F_245 ( & V_319 -> V_49 . V_338 ) >> 17 ;
T_1 V_261 ;
F_201 ( & V_248 , & V_249 , V_319 , 1 ) ;
V_261 = F_206 ( & V_248 , & V_249 , V_319 , 1 ) ;
if ( V_343 > V_345 || V_344 > V_346 ) {
F_156 ( L_53 ,
V_343 , V_344 , V_345 , V_346 ) ;
return - V_272 ;
}
V_319 -> V_348 . V_261 = V_261 ;
V_319 -> V_348 . V_248 = V_248 ;
V_319 -> V_348 . V_249 = V_249 ;
return 0 ;
}
int F_247 ( struct V_250 * V_319 )
{
const struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
int V_349 ;
if ( ! V_319 -> V_49 . V_320 )
return 0 ;
if ( F_175 ( V_231 ) )
F_214 ( & V_319 -> V_49 . V_338 ,
V_74 -> V_228 << 16 , V_74 -> V_224 << 16 ,
V_280 ) ;
if ( V_74 -> V_215 -> V_215 == V_236 ) {
V_349 = F_246 ( V_319 ) ;
if ( V_349 )
return V_349 ;
} else {
V_319 -> V_348 . V_261 = ~ 0xfff ;
V_319 -> V_348 . V_248 = 0 ;
V_319 -> V_348 . V_249 = 0 ;
}
V_349 = F_243 ( V_319 ) ;
if ( V_349 )
return V_349 ;
return 0 ;
}
static T_1 F_248 ( const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_118 -> V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
const struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
T_1 V_350 ;
V_350 = V_119 | V_351 ;
if ( F_249 ( V_6 ) || F_16 ( V_6 ) ||
F_250 ( V_6 ) || F_251 ( V_6 ) )
V_350 |= V_352 ;
if ( F_252 ( V_6 ) || F_253 ( V_6 ) )
V_350 |= V_353 ;
if ( F_53 ( V_6 ) < 4 ) {
if ( V_50 -> V_79 == V_105 )
V_350 |= V_354 ;
}
switch ( V_74 -> V_215 -> V_215 ) {
case V_282 :
V_350 |= V_281 ;
break;
case V_284 :
V_350 |= V_283 ;
break;
case V_286 :
V_350 |= V_285 ;
break;
case V_288 :
V_350 |= V_287 ;
break;
case V_290 :
V_350 |= V_289 ;
break;
case V_292 :
V_350 |= V_291 ;
break;
case V_294 :
V_350 |= V_293 ;
break;
default:
F_167 ( V_74 -> V_215 -> V_215 ) ;
return 0 ;
}
if ( F_53 ( V_6 ) >= 4 &&
V_74 -> V_216 == V_218 )
V_350 |= V_355 ;
if ( V_231 & V_356 )
V_350 |= V_357 ;
if ( V_231 & V_358 )
V_350 |= V_359 ;
return V_350 ;
}
int F_254 ( struct V_250 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_118 -> V_48 ) ;
int V_330 = V_319 -> V_49 . V_338 . V_277 >> 16 ;
int V_331 = V_319 -> V_49 . V_338 . y1 >> 16 ;
T_1 V_261 ;
F_201 ( & V_330 , & V_331 , V_319 , 0 ) ;
if ( F_53 ( V_6 ) >= 4 )
V_261 = F_206 ( & V_330 , & V_331 ,
V_319 , 0 ) ;
else
V_261 = 0 ;
if ( ! F_252 ( V_6 ) && ! F_253 ( V_6 ) ) {
unsigned int V_231 = V_319 -> V_49 . V_231 ;
int V_332 = F_244 ( & V_319 -> V_49 . V_338 ) >> 16 ;
int V_333 = F_245 ( & V_319 -> V_49 . V_338 ) >> 16 ;
if ( V_231 & V_356 ) {
V_330 += V_332 - 1 ;
V_331 += V_333 - 1 ;
} else if ( V_231 & V_358 ) {
V_330 += V_332 - 1 ;
}
}
V_319 -> main. V_261 = V_261 ;
V_319 -> main. V_248 = V_330 ;
V_319 -> main. V_249 = V_331 ;
return 0 ;
}
static void F_255 ( struct V_318 * V_73 ,
const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_73 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
int V_118 = V_66 -> V_118 ;
T_1 V_264 ;
T_1 V_350 = V_319 -> V_360 ;
T_3 V_13 = F_83 ( V_118 ) ;
int V_248 = V_319 -> main. V_248 ;
int V_249 = V_319 -> main. V_249 ;
unsigned long V_361 ;
V_264 = F_200 ( V_248 , V_249 , V_319 , 0 ) ;
if ( F_53 ( V_6 ) >= 4 )
V_66 -> V_362 = V_319 -> main. V_261 ;
else
V_66 -> V_362 = V_264 ;
V_66 -> V_363 = V_248 ;
V_66 -> V_364 = V_249 ;
F_256 ( & V_6 -> V_365 . V_366 , V_361 ) ;
if ( F_53 ( V_6 ) < 4 ) {
F_257 ( F_258 ( V_118 ) ,
( ( V_45 -> V_367 - 1 ) << 16 ) |
( V_45 -> V_368 - 1 ) ) ;
F_257 ( F_259 ( V_118 ) , 0 ) ;
} else if ( F_12 ( V_6 ) && V_118 == V_369 ) {
F_257 ( F_260 ( V_118 ) ,
( ( V_45 -> V_367 - 1 ) << 16 ) |
( V_45 -> V_368 - 1 ) ) ;
F_257 ( F_261 ( V_118 ) , 0 ) ;
F_257 ( F_262 ( V_118 ) , 0 ) ;
}
F_257 ( V_13 , V_350 ) ;
F_257 ( F_263 ( V_118 ) , V_74 -> V_247 [ 0 ] ) ;
if ( F_252 ( V_6 ) || F_253 ( V_6 ) ) {
F_257 ( F_264 ( V_118 ) ,
F_234 ( V_319 ) +
V_66 -> V_362 ) ;
F_257 ( F_265 ( V_118 ) , ( V_249 << 16 ) | V_248 ) ;
} else if ( F_53 ( V_6 ) >= 4 ) {
F_257 ( F_264 ( V_118 ) ,
F_234 ( V_319 ) +
V_66 -> V_362 ) ;
F_257 ( F_266 ( V_118 ) , ( V_249 << 16 ) | V_248 ) ;
F_257 ( F_267 ( V_118 ) , V_264 ) ;
} else {
F_257 ( F_268 ( V_118 ) ,
F_234 ( V_319 ) +
V_66 -> V_362 ) ;
}
F_269 ( V_13 ) ;
F_270 ( & V_6 -> V_365 . V_366 , V_361 ) ;
}
static void F_271 ( struct V_318 * V_73 ,
struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_118 = V_66 -> V_118 ;
unsigned long V_361 ;
F_256 ( & V_6 -> V_365 . V_366 , V_361 ) ;
F_257 ( F_83 ( V_118 ) , 0 ) ;
if ( F_178 ( V_6 ) -> V_235 >= 4 )
F_257 ( F_264 ( V_118 ) , 0 ) ;
else
F_257 ( F_268 ( V_118 ) , 0 ) ;
F_269 ( F_83 ( V_118 ) ) ;
F_270 ( & V_6 -> V_365 . V_366 , V_361 ) ;
}
static T_1
F_272 ( const struct V_213 * V_74 , int V_118 )
{
if ( V_74 -> V_216 == V_217 )
return 64 ;
else
return F_165 ( V_74 , V_118 ) ;
}
static void F_273 ( struct V_66 * V_66 , int V_324 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_119 ( F_274 ( V_66 -> V_79 , V_324 ) , 0 ) ;
F_119 ( F_275 ( V_66 -> V_79 , V_324 ) , 0 ) ;
F_119 ( F_276 ( V_66 -> V_79 , V_324 ) , 0 ) ;
}
static void F_277 ( struct V_66 * V_66 )
{
struct V_370 * V_371 ;
int V_120 ;
V_371 = & V_66 -> V_75 -> V_371 ;
for ( V_120 = 0 ; V_120 < V_66 -> V_372 ; V_120 ++ ) {
if ( ! V_371 -> V_373 [ V_120 ] . V_374 )
F_273 ( V_66 , V_120 ) ;
}
}
T_1 F_278 ( const struct V_213 * V_74 , int V_118 ,
unsigned int V_231 )
{
T_1 V_276 ;
if ( V_118 >= V_74 -> V_215 -> V_271 )
return 0 ;
V_276 = F_199 ( V_74 , V_118 , V_231 ) ;
if ( F_175 ( V_231 ) )
V_276 /= F_168 ( V_74 , V_118 ) ;
else
V_276 /= F_272 ( V_74 , V_118 ) ;
return V_276 ;
}
static T_1 F_279 ( T_2 V_314 )
{
switch ( V_314 ) {
case V_282 :
return V_375 ;
case V_286 :
return V_297 ;
case V_290 :
return V_298 | V_376 ;
case V_288 :
return V_298 ;
case V_299 :
return V_298 | V_376 |
V_377 ;
case V_300 :
return V_298 |
V_377 ;
case V_292 :
return V_301 ;
case V_294 :
return V_376 | V_301 ;
case V_378 :
return V_379 | V_380 ;
case V_381 :
return V_379 | V_382 ;
case V_383 :
return V_379 | V_384 ;
case V_385 :
return V_379 | V_386 ;
default:
F_167 ( V_314 ) ;
}
return 0 ;
}
static T_1 F_280 ( V_40 V_260 )
{
switch ( V_260 ) {
case V_217 :
break;
case V_218 :
return V_387 ;
case V_219 :
return V_388 ;
case V_220 :
return V_389 ;
default:
F_167 ( V_260 ) ;
}
return 0 ;
}
static T_1 F_281 ( unsigned int V_231 )
{
switch ( V_231 ) {
case V_273 :
break;
case V_390 :
return V_391 ;
case V_356 :
return V_392 ;
case V_280 :
return V_393 ;
default:
F_167 ( V_231 ) ;
}
return 0 ;
}
T_1 F_282 ( const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_118 -> V_48 ) ;
const struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
const struct V_394 * V_395 = & V_319 -> V_396 ;
T_1 V_397 ;
V_397 = V_125 ;
if ( ! F_283 ( V_6 ) ) {
V_397 |=
V_398 |
V_399 |
V_400 ;
}
V_397 |= F_279 ( V_74 -> V_215 -> V_215 ) ;
V_397 |= F_280 ( V_74 -> V_216 ) ;
V_397 |= F_281 ( V_231 ) ;
if ( V_395 -> V_315 & V_401 )
V_397 |= V_402 ;
else if ( V_395 -> V_315 & V_403 )
V_397 |= V_404 ;
return V_397 ;
}
static void F_284 ( struct V_318 * V_118 ,
const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
struct V_47 * V_48 = V_118 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
enum V_405 V_405 = F_227 ( V_118 ) -> V_324 ;
enum V_79 V_79 = F_227 ( V_118 ) -> V_79 ;
T_1 V_397 = V_319 -> V_360 ;
unsigned int V_231 = V_319 -> V_49 . V_231 ;
T_1 V_276 = F_278 ( V_74 , 0 , V_231 ) ;
T_1 V_406 = V_319 -> main. V_261 ;
int V_407 = V_319 -> V_407 ;
int V_330 = V_319 -> main. V_248 ;
int V_331 = V_319 -> main. V_249 ;
int V_332 = F_244 ( & V_319 -> V_49 . V_338 ) >> 16 ;
int V_333 = F_245 ( & V_319 -> V_49 . V_338 ) >> 16 ;
int V_408 = V_319 -> V_49 . V_339 . V_277 ;
int V_409 = V_319 -> V_49 . V_339 . y1 ;
int V_410 = F_244 ( & V_319 -> V_49 . V_339 ) ;
int V_411 = F_245 ( & V_319 -> V_49 . V_339 ) ;
unsigned long V_361 ;
V_332 -- ;
V_333 -- ;
V_410 -- ;
V_411 -- ;
V_66 -> V_362 = V_406 ;
V_66 -> V_363 = V_330 ;
V_66 -> V_364 = V_331 ;
F_256 ( & V_6 -> V_365 . V_366 , V_361 ) ;
if ( F_283 ( V_6 ) ) {
F_257 ( F_285 ( V_79 , V_405 ) ,
V_412 |
V_413 |
V_414 ) ;
}
F_257 ( F_89 ( V_79 , V_405 ) , V_397 ) ;
F_257 ( F_286 ( V_79 , V_405 ) , ( V_331 << 16 ) | V_330 ) ;
F_257 ( F_287 ( V_79 , V_405 ) , V_276 ) ;
F_257 ( F_288 ( V_79 , V_405 ) , ( V_333 << 16 ) | V_332 ) ;
if ( V_407 >= 0 ) {
T_2 V_415 = 0 ;
F_21 ( ! V_410 || ! V_411 ) ;
V_415 = V_416 | F_289 ( V_405 ) |
V_45 -> V_371 . V_373 [ V_407 ] . V_417 ;
F_257 ( F_274 ( V_79 , V_407 ) , V_415 ) ;
F_257 ( F_290 ( V_79 , V_407 ) , 0 ) ;
F_257 ( F_275 ( V_79 , V_407 ) , ( V_408 << 16 ) | V_409 ) ;
F_257 ( F_276 ( V_79 , V_407 ) , ( V_410 << 16 ) | V_411 ) ;
F_257 ( F_291 ( V_79 , V_405 ) , 0 ) ;
} else {
F_257 ( F_291 ( V_79 , V_405 ) , ( V_409 << 16 ) | V_408 ) ;
}
F_257 ( F_292 ( V_79 , V_405 ) ,
F_234 ( V_319 ) + V_406 ) ;
F_269 ( F_292 ( V_79 , V_405 ) ) ;
F_270 ( & V_6 -> V_365 . V_366 , V_361 ) ;
}
static void F_293 ( struct V_318 * V_73 ,
struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_405 V_405 = F_227 ( V_73 ) -> V_324 ;
enum V_79 V_79 = F_227 ( V_73 ) -> V_79 ;
unsigned long V_361 ;
F_256 ( & V_6 -> V_365 . V_366 , V_361 ) ;
F_257 ( F_89 ( V_79 , V_405 ) , 0 ) ;
F_257 ( F_292 ( V_79 , V_405 ) , 0 ) ;
F_269 ( F_292 ( V_79 , V_405 ) ) ;
F_270 ( & V_6 -> V_365 . V_366 , V_361 ) ;
}
static void F_294 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
F_133 (&dev_priv->drm, crtc)
F_295 ( V_6 , V_50 -> V_79 ) ;
}
static void F_296 ( struct V_47 * V_48 )
{
struct V_130 * V_50 ;
F_233 (dev, crtc) {
struct V_321 * V_118 = F_227 ( V_50 -> V_73 ) ;
struct V_250 * V_319 =
F_231 ( V_118 -> V_49 . V_28 ) ;
if ( V_319 -> V_49 . V_320 ) {
F_297 ( & V_118 -> V_49 ,
F_42 ( V_50 ) ) ;
V_118 -> V_418 ( & V_118 -> V_49 ,
F_235 ( V_50 -> V_28 ) ,
V_319 ) ;
}
}
}
static int
F_298 ( struct V_47 * V_48 ,
struct V_419 * V_28 ,
struct V_420 * V_421 )
{
struct V_27 * V_45 ;
struct V_130 * V_50 ;
int V_120 , V_349 ;
F_299 ( V_48 , V_421 ) ;
F_300 ( F_35 ( V_48 ) ) ;
if ( ! V_28 )
return 0 ;
F_301 (state, crtc, crtc_state, i) {
V_45 -> V_422 = true ;
}
if ( ! F_158 ( F_35 ( V_48 ) ) )
F_302 ( V_28 ) -> V_423 = true ;
V_349 = F_303 ( V_28 , V_421 ) ;
F_21 ( V_349 == - V_424 ) ;
return V_349 ;
}
static bool F_304 ( struct V_5 * V_6 )
{
return F_305 ( V_6 ) &&
F_53 ( V_6 ) < 5 && ! F_249 ( V_6 ) ;
}
void F_306 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_420 * V_421 = & V_6 -> V_425 ;
struct V_419 * V_28 ;
int V_349 ;
F_3 ( & V_48 -> V_426 . V_427 ) ;
F_307 ( V_421 , 0 ) ;
while ( 1 ) {
V_349 = F_308 ( V_48 , V_421 ) ;
if ( V_349 != - V_424 )
break;
F_309 ( V_421 ) ;
}
if ( ! V_244 . V_428 &&
! F_304 ( V_6 ) )
return;
V_28 = F_310 ( V_48 , V_421 ) ;
if ( F_188 ( V_28 ) ) {
V_349 = F_238 ( V_28 ) ;
F_122 ( L_54 , V_349 ) ;
return;
}
V_349 = F_311 ( V_48 , V_421 ) ;
if ( V_349 ) {
F_122 ( L_55 , V_349 ) ;
F_312 ( V_28 ) ;
return;
}
V_6 -> V_429 = V_28 ;
V_28 -> V_430 = V_421 ;
}
void F_313 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_420 * V_421 = & V_6 -> V_425 ;
struct V_419 * V_28 = V_6 -> V_429 ;
int V_349 ;
F_294 ( V_6 ) ;
V_6 -> V_429 = NULL ;
if ( ! F_304 ( V_6 ) ) {
if ( ! V_28 ) {
F_296 ( V_48 ) ;
} else {
V_349 = F_298 ( V_48 , V_28 , V_421 ) ;
if ( V_349 )
F_122 ( L_56 , V_349 ) ;
}
} else {
F_314 ( V_6 ) ;
F_315 ( V_6 ) ;
F_316 ( V_6 ) ;
F_317 ( V_48 ) ;
F_318 ( & V_6 -> V_431 ) ;
if ( V_6 -> V_432 . V_433 )
V_6 -> V_432 . V_433 ( V_6 ) ;
F_319 ( & V_6 -> V_431 ) ;
V_349 = F_298 ( V_48 , V_28 , V_421 ) ;
if ( V_349 )
F_122 ( L_56 , V_349 ) ;
F_320 ( V_6 ) ;
}
if ( V_28 )
F_312 ( V_28 ) ;
F_321 ( V_421 ) ;
F_322 ( V_421 ) ;
F_5 ( & V_48 -> V_426 . V_427 ) ;
}
static bool F_323 ( struct V_66 * V_50 )
{
struct V_434 * error = & F_35 ( V_50 -> V_49 . V_48 ) -> V_435 ;
if ( F_324 ( error ) )
return true ;
if ( V_50 -> V_436 != F_325 ( error ) )
return true ;
return false ;
}
static bool F_326 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
bool V_437 ;
if ( F_323 ( V_66 ) )
return false ;
F_318 ( & V_48 -> V_438 ) ;
V_437 = F_42 ( V_50 ) -> V_439 != NULL ;
F_319 ( & V_48 -> V_438 ) ;
return V_437 ;
}
static void F_327 ( struct V_66 * V_50 ,
struct V_22 * V_440 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_22 * V_23 =
F_235 ( V_50 -> V_49 . V_28 ) ;
V_50 -> V_49 . V_417 = V_50 -> V_49 . V_28 -> V_417 ;
F_119 ( F_328 ( V_50 -> V_79 ) ,
( ( V_23 -> V_368 - 1 ) << 16 ) |
( V_23 -> V_367 - 1 ) ) ;
if ( F_53 ( V_6 ) >= 9 ) {
F_277 ( V_50 ) ;
if ( V_23 -> V_441 . V_131 )
F_329 ( V_50 ) ;
} else if ( F_70 ( V_6 ) ) {
if ( V_23 -> V_441 . V_131 )
F_330 ( V_50 ) ;
else if ( V_440 -> V_441 . V_131 )
F_331 ( V_50 , true ) ;
}
}
static void F_332 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_442 ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( F_251 ( V_6 ) ) {
V_442 &= ~ V_443 ;
V_442 |= V_443 | V_444 ;
} else {
V_442 &= ~ V_445 ;
V_442 |= V_445 | V_444 ;
}
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( F_101 ( V_6 ) ) {
V_442 &= ~ V_446 ;
V_442 |= V_447 ;
} else {
V_442 &= ~ V_445 ;
V_442 |= V_445 ;
}
F_119 ( V_13 , V_442 | V_448 ) ;
F_120 ( V_13 ) ;
F_121 ( 1000 ) ;
if ( F_251 ( V_6 ) )
F_119 ( V_13 , F_17 ( V_13 ) | V_449 |
V_450 ) ;
}
static void F_333 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_442 , V_451 ;
F_334 ( V_6 , V_79 ) ;
V_13 = F_335 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_452 ;
V_442 &= ~ V_453 ;
F_119 ( V_13 , V_442 ) ;
F_17 ( V_13 ) ;
F_121 ( 150 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_454 ;
V_442 |= F_336 ( V_45 -> V_455 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
F_119 ( V_13 , V_442 | V_92 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
F_119 ( V_13 , V_442 | V_93 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
F_119 ( F_337 ( V_79 ) , V_457 ) ;
F_119 ( F_337 ( V_79 ) , V_457 |
V_458 ) ;
V_13 = F_338 ( V_79 ) ;
for ( V_451 = 0 ; V_451 < 5 ; V_451 ++ ) {
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( ( V_442 & V_453 ) ) {
F_156 ( L_58 ) ;
F_119 ( V_13 , V_442 | V_453 ) ;
break;
}
}
if ( V_451 == 5 )
F_122 ( L_59 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_459 ;
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_459 ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
V_13 = F_338 ( V_79 ) ;
for ( V_451 = 0 ; V_451 < 5 ; V_451 ++ ) {
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( V_442 & V_452 ) {
F_119 ( V_13 , V_442 | V_452 ) ;
F_156 ( L_60 ) ;
break;
}
}
if ( V_451 == 5 )
F_122 ( L_61 ) ;
F_156 ( L_62 ) ;
}
static void F_339 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_442 , V_120 , V_460 ;
V_13 = F_335 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_452 ;
V_442 &= ~ V_453 ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_454 ;
V_442 |= F_336 ( V_45 -> V_455 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
V_442 &= ~ V_461 ;
V_442 |= V_462 ;
F_119 ( V_13 , V_442 | V_92 ) ;
F_119 ( F_340 ( V_79 ) ,
V_463 | V_464 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( F_101 ( V_6 ) ) {
V_442 &= ~ V_446 ;
V_442 |= V_465 ;
} else {
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
}
F_119 ( V_13 , V_442 | V_93 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_461 ;
V_442 |= V_466 [ V_120 ] ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 500 ) ;
for ( V_460 = 0 ; V_460 < 5 ; V_460 ++ ) {
V_13 = F_338 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( V_442 & V_453 ) {
F_119 ( V_13 , V_442 | V_453 ) ;
F_156 ( L_58 ) ;
break;
}
F_121 ( 50 ) ;
}
if ( V_460 < 5 )
break;
}
if ( V_120 == 4 )
F_122 ( L_59 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_459 ;
if ( F_250 ( V_6 ) ) {
V_442 &= ~ V_461 ;
V_442 |= V_462 ;
}
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( F_101 ( V_6 ) ) {
V_442 &= ~ V_446 ;
V_442 |= V_467 ;
} else {
V_442 &= ~ V_445 ;
V_442 |= V_459 ;
}
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_461 ;
V_442 |= V_466 [ V_120 ] ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 500 ) ;
for ( V_460 = 0 ; V_460 < 5 ; V_460 ++ ) {
V_13 = F_338 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( V_442 & V_452 ) {
F_119 ( V_13 , V_442 | V_452 ) ;
F_156 ( L_60 ) ;
break;
}
F_121 ( 50 ) ;
}
if ( V_460 < 5 )
break;
}
if ( V_120 == 4 )
F_122 ( L_61 ) ;
F_156 ( L_63 ) ;
}
static void F_341 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_442 , V_120 , V_468 ;
V_13 = F_335 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_452 ;
V_442 &= ~ V_453 ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 150 ) ;
F_156 ( L_64 ,
F_17 ( F_338 ( V_79 ) ) ) ;
for ( V_468 = 0 ; V_468 < F_173 ( V_466 ) * 2 ; V_468 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ ( V_469 | V_443 ) ;
V_442 &= ~ V_92 ;
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_469 ;
V_442 &= ~ V_446 ;
V_442 &= ~ V_93 ;
F_119 ( V_13 , V_442 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_454 ;
V_442 |= F_336 ( V_45 -> V_455 ) ;
V_442 |= V_470 ;
V_442 &= ~ V_461 ;
V_442 |= V_466 [ V_468 / 2 ] ;
V_442 |= V_471 ;
F_119 ( V_13 , V_442 | V_92 ) ;
F_119 ( F_340 ( V_79 ) ,
V_463 | V_464 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 |= V_465 ;
V_442 |= V_471 ;
F_119 ( V_13 , V_442 | V_93 ) ;
F_120 ( V_13 ) ;
F_121 ( 1 ) ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
V_13 = F_338 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( V_442 & V_453 ||
( F_17 ( V_13 ) & V_453 ) ) {
F_119 ( V_13 , V_442 | V_453 ) ;
F_156 ( L_65 ,
V_120 ) ;
break;
}
F_121 ( 1 ) ;
}
if ( V_120 == 4 ) {
F_156 ( L_66 , V_468 / 2 ) ;
continue;
}
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_443 ;
V_442 |= V_472 ;
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_446 ;
V_442 |= V_467 ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 2 ) ;
for ( V_120 = 0 ; V_120 < 4 ; V_120 ++ ) {
V_13 = F_338 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_156 ( L_57 , V_442 ) ;
if ( V_442 & V_452 ||
( F_17 ( V_13 ) & V_452 ) ) {
F_119 ( V_13 , V_442 | V_452 ) ;
F_156 ( L_67 ,
V_120 ) ;
goto V_473;
}
F_121 ( 2 ) ;
}
if ( V_120 == 4 )
F_156 ( L_68 , V_468 / 2 ) ;
}
V_473:
F_156 ( L_63 ) ;
}
static void F_342 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_442 ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ ( V_454 | ( 0x7 << 16 ) ) ;
V_442 |= F_336 ( V_66 -> V_75 -> V_455 ) ;
V_442 |= ( F_17 ( F_54 ( V_79 ) ) & V_193 ) << 11 ;
F_119 ( V_13 , V_442 | V_95 ) ;
F_120 ( V_13 ) ;
F_121 ( 200 ) ;
V_442 = F_17 ( V_13 ) ;
F_119 ( V_13 , V_442 | V_474 ) ;
F_120 ( V_13 ) ;
F_121 ( 200 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( ( V_442 & V_94 ) == 0 ) {
F_119 ( V_13 , V_442 | V_94 ) ;
F_120 ( V_13 ) ;
F_121 ( 100 ) ;
}
}
static void F_343 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_442 ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_119 ( V_13 , V_442 & ~ V_474 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_119 ( V_13 , V_442 & ~ V_94 ) ;
F_120 ( V_13 ) ;
F_121 ( 100 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_119 ( V_13 , V_442 & ~ V_95 ) ;
F_120 ( V_13 ) ;
F_121 ( 100 ) ;
}
static void F_344 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_442 ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
F_119 ( V_13 , V_442 & ~ V_92 ) ;
F_120 ( V_13 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ ( 0x7 << 16 ) ;
V_442 |= ( F_17 ( F_54 ( V_79 ) ) & V_193 ) << 11 ;
F_119 ( V_13 , V_442 & ~ V_93 ) ;
F_120 ( V_13 ) ;
F_121 ( 100 ) ;
if ( F_115 ( V_6 ) )
F_119 ( F_337 ( V_79 ) , V_457 ) ;
V_13 = F_64 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
F_119 ( V_13 , V_442 ) ;
V_13 = F_66 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
if ( F_101 ( V_6 ) ) {
V_442 &= ~ V_446 ;
V_442 |= V_465 ;
} else {
V_442 &= ~ V_445 ;
V_442 |= V_456 ;
}
V_442 &= ~ ( 0x07 << 16 ) ;
V_442 |= ( F_17 ( F_54 ( V_79 ) ) & V_193 ) << 11 ;
F_119 ( V_13 , V_442 ) ;
F_120 ( V_13 ) ;
F_121 ( 100 ) ;
}
bool F_345 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
F_133 (&dev_priv->drm, crtc) {
if ( F_346 ( & V_50 -> V_475 ) == 0 )
continue;
if ( V_50 -> V_439 )
F_347 ( V_6 , V_50 -> V_79 ) ;
return true ;
}
return false ;
}
static void F_348 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
struct V_1 * V_2 = V_66 -> V_439 ;
V_66 -> V_439 = NULL ;
if ( V_2 -> V_476 )
F_349 ( & V_66 -> V_49 , V_2 -> V_476 ) ;
F_97 ( & V_66 -> V_49 ) ;
F_350 ( & V_6 -> V_477 ) ;
F_351 ( V_66 -> V_118 ,
V_2 -> V_478 ) ;
F_352 ( V_6 -> V_479 , & V_2 -> V_480 ) ;
}
static int F_353 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
long V_349 ;
F_21 ( F_354 ( & V_6 -> V_477 ) ) ;
V_349 = F_355 (
V_6 -> V_477 ,
! F_326 ( V_50 ) ,
60 * V_481 ) ;
if ( V_349 < 0 )
return V_349 ;
if ( V_349 == 0 ) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_1 * V_2 ;
F_318 ( & V_48 -> V_438 ) ;
V_2 = V_66 -> V_439 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_356 ( 1 , L_69 ) ;
F_348 ( V_66 ) ;
}
F_319 ( & V_48 -> V_438 ) ;
}
return 0 ;
}
void F_357 ( struct V_5 * V_6 )
{
T_1 V_442 ;
F_119 ( V_482 , V_483 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_442 = F_358 ( V_6 , V_484 , V_485 ) ;
V_442 |= V_486 ;
F_359 ( V_6 , V_484 , V_442 , V_485 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_360 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int clock = V_50 -> V_75 -> V_49 . V_76 . V_77 ;
T_1 V_487 , V_488 , V_489 , V_490 = 0 ;
T_1 V_442 ;
F_357 ( V_6 ) ;
for ( V_489 = 0 ; V_489 < 2 ; V_489 ++ ) {
T_1 V_491 = 172800 * 1000 ;
T_1 V_492 = 64 ;
T_1 V_493 ;
V_493 = F_8 ( V_491 ,
clock << V_489 ) ;
V_487 = ( V_493 / V_492 ) - 2 ;
V_488 = V_493 % V_492 ;
if ( V_487 <= 0x7f )
break;
}
F_21 ( F_361 ( V_487 ) &
~ V_494 ) ;
F_21 ( F_362 ( V_490 ) &
~ V_495 ) ;
F_156 ( L_70 ,
clock ,
V_489 ,
V_487 ,
V_490 ,
V_488 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_442 = F_358 ( V_6 , V_496 , V_485 ) ;
V_442 &= ~ V_494 ;
V_442 |= F_361 ( V_487 ) ;
V_442 &= ~ V_495 ;
V_442 |= F_363 ( V_488 ) ;
V_442 |= F_362 ( V_490 ) ;
V_442 |= V_497 ;
F_359 ( V_6 , V_496 , V_442 , V_485 ) ;
V_442 = F_358 ( V_6 , V_498 , V_485 ) ;
V_442 &= ~ F_364 ( 1 ) ;
V_442 |= F_364 ( V_489 ) ;
F_359 ( V_6 , V_498 , V_442 , V_485 ) ;
V_442 = F_358 ( V_6 , V_484 , V_485 ) ;
V_442 &= ~ V_486 ;
F_359 ( V_6 , V_484 , V_442 , V_485 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_121 ( 24 ) ;
F_119 ( V_482 , V_499 ) ;
}
int F_365 ( struct V_5 * V_6 )
{
T_1 V_487 , V_488 , V_489 ;
T_1 V_491 = 172800 * 1000 ;
T_1 V_492 = 64 ;
T_1 V_493 ;
T_1 V_442 ;
if ( ( F_17 ( V_482 ) & V_499 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_442 = F_358 ( V_6 , V_484 , V_485 ) ;
if ( V_442 & V_486 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_442 = F_358 ( V_6 , V_496 , V_485 ) ;
V_487 = ( V_442 & V_494 ) >>
V_500 ;
V_488 = ( V_442 & V_495 ) >>
V_501 ;
V_442 = F_358 ( V_6 , V_498 , V_485 ) ;
V_489 = ( V_442 & V_502 ) >>
V_503 ;
F_5 ( & V_6 -> V_9 ) ;
V_493 = ( V_487 + 2 ) * V_492 + V_488 ;
return F_8 ( V_491 ,
V_493 << V_489 ) ;
}
static void F_366 ( struct V_66 * V_50 ,
enum V_79 V_504 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
F_119 ( F_367 ( V_504 ) ,
F_17 ( F_368 ( V_80 ) ) ) ;
F_119 ( F_369 ( V_504 ) ,
F_17 ( F_370 ( V_80 ) ) ) ;
F_119 ( F_371 ( V_504 ) ,
F_17 ( F_372 ( V_80 ) ) ) ;
F_119 ( F_373 ( V_504 ) ,
F_17 ( F_374 ( V_80 ) ) ) ;
F_119 ( F_375 ( V_504 ) ,
F_17 ( F_376 ( V_80 ) ) ) ;
F_119 ( F_377 ( V_504 ) ,
F_17 ( F_378 ( V_80 ) ) ) ;
F_119 ( F_379 ( V_504 ) ,
F_17 ( F_380 ( V_80 ) ) ) ;
}
static void F_381 ( struct V_47 * V_48 , bool V_505 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_2 V_442 ;
V_442 = F_17 ( V_506 ) ;
if ( ! ! ( V_442 & V_507 ) == V_505 )
return;
F_21 ( F_17 ( F_66 ( V_105 ) ) & V_93 ) ;
F_21 ( F_17 ( F_66 ( V_508 ) ) & V_93 ) ;
V_442 &= ~ V_507 ;
if ( V_505 )
V_442 |= V_507 ;
F_156 ( L_71 , V_505 ? L_72 : L_73 ) ;
F_119 ( V_506 , V_442 ) ;
F_120 ( V_506 ) ;
}
static void F_382 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
switch ( V_66 -> V_79 ) {
case V_98 :
break;
case V_105 :
if ( V_66 -> V_75 -> V_455 > 2 )
F_381 ( V_48 , false ) ;
else
F_381 ( V_48 , true ) ;
break;
case V_508 :
F_381 ( V_48 , true ) ;
break;
default:
F_141 () ;
}
}
static enum V_163
F_383 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_509 * V_510 ;
F_384 (dev, &crtc->base, encoder) {
if ( V_510 -> type == V_511 ||
V_510 -> type == V_512 )
return F_385 ( & V_510 -> V_49 ) -> V_163 ;
}
return - 1 ;
}
static void F_386 ( const struct V_22 * V_45 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_1 V_442 ;
F_98 ( V_6 , V_79 ) ;
if ( F_251 ( V_6 ) )
F_382 ( V_50 ) ;
F_119 ( F_387 ( V_79 ) ,
F_17 ( F_388 ( V_79 ) ) & V_513 ) ;
V_6 -> V_432 . V_514 ( V_50 , V_45 ) ;
if ( F_101 ( V_6 ) ) {
T_1 V_515 ;
V_442 = F_17 ( V_516 ) ;
V_442 |= F_389 ( V_79 ) ;
V_515 = F_390 ( V_79 ) ;
if ( V_45 -> V_191 ==
F_391 ( V_6 , V_517 ) )
V_442 |= V_515 ;
else
V_442 &= ~ V_515 ;
F_119 ( V_516 , V_442 ) ;
}
F_392 ( V_50 ) ;
F_69 ( V_6 , V_79 ) ;
F_366 ( V_50 , V_79 ) ;
F_332 ( V_50 ) ;
if ( F_101 ( V_6 ) &&
F_393 ( V_45 ) ) {
const struct V_518 * V_76 =
& V_45 -> V_49 . V_76 ;
T_1 V_519 = ( F_17 ( F_54 ( V_79 ) ) & V_193 ) >> 5 ;
T_3 V_13 = F_102 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ ( V_135 |
V_520 |
V_521 ) ;
V_442 |= V_522 ;
V_442 |= V_519 << 9 ;
if ( V_76 -> V_315 & V_523 )
V_442 |= V_524 ;
if ( V_76 -> V_315 & V_525 )
V_442 |= V_526 ;
switch ( F_383 ( V_50 ) ) {
case V_183 :
V_442 |= V_150 ;
break;
case V_185 :
V_442 |= V_152 ;
break;
case V_187 :
V_442 |= V_154 ;
break;
default:
F_141 () ;
}
F_119 ( V_13 , V_442 ) ;
}
F_143 ( V_6 , V_79 ) ;
}
static void F_394 ( const struct V_22 * V_45 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_78 V_80 = V_45 -> V_80 ;
F_98 ( V_6 , V_204 ) ;
F_360 ( V_50 ) ;
F_366 ( V_50 , V_98 ) ;
F_148 ( V_6 , V_80 ) ;
}
static void F_395 ( struct V_47 * V_48 , int V_79 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_3 V_527 = F_49 ( V_79 ) ;
T_1 V_442 ;
V_442 = F_17 ( V_527 ) ;
F_121 ( 500 ) ;
if ( F_56 ( F_17 ( V_527 ) != V_442 , 5 ) ) {
if ( F_56 ( F_17 ( V_527 ) != V_442 , 5 ) )
F_122 ( L_74 , F_73 ( V_79 ) ) ;
}
}
static int
F_396 ( struct V_22 * V_45 , bool V_528 ,
unsigned int V_529 , int * V_407 ,
int V_332 , int V_333 , int V_410 , int V_411 )
{
struct V_370 * V_371 =
& V_45 -> V_371 ;
struct V_66 * V_66 =
F_42 ( V_45 -> V_49 . V_50 ) ;
int V_530 ;
V_530 = V_332 != V_410 || V_333 != V_411 ;
if ( V_528 || ! V_530 ) {
if ( * V_407 >= 0 ) {
V_371 -> V_531 &= ~ ( 1 << V_529 ) ;
V_371 -> V_373 [ * V_407 ] . V_374 = 0 ;
F_156 ( L_75
L_76 ,
V_66 -> V_79 , V_529 , * V_407 ,
V_371 -> V_531 ) ;
* V_407 = - 1 ;
}
return 0 ;
}
if ( V_332 < V_532 || V_333 < V_533 ||
V_410 < V_534 || V_411 < V_535 ||
V_332 > V_536 || V_333 > V_537 ||
V_410 > V_538 || V_411 > V_539 ) {
F_156 ( L_77
L_78 ,
V_66 -> V_79 , V_529 , V_332 , V_333 , V_410 , V_411 ) ;
return - V_272 ;
}
V_371 -> V_531 |= ( 1 << V_529 ) ;
F_156 ( L_75
L_79 ,
V_66 -> V_79 , V_529 , V_332 , V_333 , V_410 , V_411 ,
V_371 -> V_531 ) ;
return 0 ;
}
int F_397 ( struct V_22 * V_28 )
{
const struct V_518 * V_76 = & V_28 -> V_49 . V_76 ;
return F_396 ( V_28 , ! V_28 -> V_49 . V_72 , V_540 ,
& V_28 -> V_371 . V_407 ,
V_28 -> V_368 , V_28 -> V_367 ,
V_76 -> V_541 , V_76 -> V_542 ) ;
}
static int F_398 ( struct V_22 * V_45 ,
struct V_250 * V_319 )
{
struct V_321 * V_321 =
F_227 ( V_319 -> V_49 . V_118 ) ;
struct V_213 * V_74 = V_319 -> V_49 . V_74 ;
int V_349 ;
bool V_528 = ! V_74 || ! V_319 -> V_49 . V_320 ;
V_349 = F_396 ( V_45 , V_528 ,
F_229 ( & V_321 -> V_49 ) ,
& V_319 -> V_407 ,
F_244 ( & V_319 -> V_49 . V_338 ) >> 16 ,
F_245 ( & V_319 -> V_49 . V_338 ) >> 16 ,
F_244 ( & V_319 -> V_49 . V_339 ) ,
F_245 ( & V_319 -> V_49 . V_339 ) ) ;
if ( V_349 || V_319 -> V_407 < 0 )
return V_349 ;
if ( V_319 -> V_396 . V_315 != V_543 ) {
F_156 ( L_80 ,
V_321 -> V_49 . V_49 . V_324 ,
V_321 -> V_49 . V_12 ) ;
return - V_272 ;
}
switch ( V_74 -> V_215 -> V_215 ) {
case V_286 :
case V_290 :
case V_288 :
case V_299 :
case V_300 :
case V_292 :
case V_294 :
case V_378 :
case V_381 :
case V_383 :
case V_385 :
break;
default:
F_156 ( L_81 ,
V_321 -> V_49 . V_49 . V_324 , V_321 -> V_49 . V_12 ,
V_74 -> V_49 . V_324 , V_74 -> V_215 -> V_215 ) ;
return - V_272 ;
}
return 0 ;
}
static void F_399 ( struct V_66 * V_50 )
{
int V_120 ;
for ( V_120 = 0 ; V_120 < V_50 -> V_372 ; V_120 ++ )
F_273 ( V_50 , V_120 ) ;
}
static void F_329 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
struct V_370 * V_371 =
& V_50 -> V_75 -> V_371 ;
if ( V_50 -> V_75 -> V_441 . V_131 ) {
int V_324 ;
if ( F_21 ( V_50 -> V_75 -> V_371 . V_407 < 0 ) )
return;
V_324 = V_371 -> V_407 ;
F_119 ( F_274 ( V_79 , V_324 ) , V_416 |
V_544 | V_371 -> V_373 [ V_324 ] . V_417 ) ;
F_119 ( F_275 ( V_79 , V_324 ) , V_50 -> V_75 -> V_441 . V_545 ) ;
F_119 ( F_276 ( V_79 , V_324 ) , V_50 -> V_75 -> V_441 . V_227 ) ;
}
}
static void F_330 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
if ( V_50 -> V_75 -> V_441 . V_131 ) {
if ( F_251 ( V_6 ) || F_252 ( V_6 ) )
F_119 ( F_400 ( V_79 ) , V_546 | V_547 |
F_401 ( V_79 ) ) ;
else
F_119 ( F_400 ( V_79 ) , V_546 | V_547 ) ;
F_119 ( F_402 ( V_79 ) , V_50 -> V_75 -> V_441 . V_545 ) ;
F_119 ( F_403 ( V_79 ) , V_50 -> V_75 -> V_441 . V_227 ) ;
}
}
void F_404 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_548 )
return;
F_405 ( V_6 , V_50 -> V_118 ) ;
if ( F_253 ( V_6 ) ) {
F_3 ( & V_6 -> V_549 . V_550 ) ;
F_21 ( F_406 ( V_6 , V_551 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_549 . V_550 ) ;
} else {
F_119 ( V_552 , V_553 ) ;
if ( F_55 ( V_6 ,
V_552 , V_553 , V_553 ,
50 ) )
F_122 ( L_82 ) ;
}
}
void F_407 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_548 )
return;
F_405 ( V_6 , V_50 -> V_118 ) ;
if ( F_253 ( V_6 ) ) {
F_3 ( & V_6 -> V_549 . V_550 ) ;
F_21 ( F_406 ( V_6 , V_551 , 0 ) ) ;
F_5 ( & V_6 -> V_549 . V_550 ) ;
if ( F_55 ( V_6 ,
V_552 , V_553 , 0 ,
42 ) )
F_122 ( L_83 ) ;
} else {
F_119 ( V_552 , 0 ) ;
F_120 ( V_552 ) ;
}
F_347 ( V_6 , V_50 -> V_79 ) ;
}
static void F_408 ( struct V_66 * V_66 )
{
if ( V_66 -> V_554 ) {
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_3 ( & V_48 -> V_242 ) ;
V_6 -> V_555 . V_556 = false ;
( void ) F_409 ( V_66 -> V_554 ) ;
V_6 -> V_555 . V_556 = true ;
F_5 ( & V_48 -> V_242 ) ;
}
}
static void
F_410 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
F_404 ( V_66 ) ;
if ( F_50 ( V_6 ) )
F_411 ( V_6 , V_79 , true ) ;
F_412 ( V_6 ) ;
F_413 ( V_6 ) ;
}
static void
F_414 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_50 ( V_6 ) )
F_411 ( V_6 , V_79 , false ) ;
F_407 ( V_66 ) ;
}
static void
F_236 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
F_414 ( V_50 ) ;
if ( F_158 ( V_6 ) &&
F_415 ( V_6 , false ) )
F_347 ( V_6 , V_79 ) ;
}
static void F_416 ( struct V_22 * V_440 )
{
struct V_66 * V_50 = F_42 ( V_440 -> V_49 . V_50 ) ;
struct V_419 * V_557 = V_440 -> V_49 . V_28 ;
struct V_22 * V_23 =
F_235 ( V_50 -> V_49 . V_28 ) ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
struct V_326 * V_558 =
F_417 ( V_557 , V_73 ) ;
F_418 ( F_35 ( V_50 -> V_49 . V_48 ) , V_23 -> V_559 ) ;
if ( V_23 -> V_560 && V_23 -> V_49 . V_72 )
F_419 ( V_50 ) ;
if ( V_558 ) {
struct V_250 * V_561 =
F_231 ( V_73 -> V_28 ) ;
struct V_250 * V_562 =
F_231 ( V_558 ) ;
F_420 ( V_50 ) ;
if ( V_561 -> V_49 . V_320 &&
( F_18 ( & V_23 -> V_49 ) ||
! V_562 -> V_49 . V_320 ) )
F_410 ( & V_50 -> V_49 ) ;
}
}
static void F_421 ( struct V_22 * V_440 ,
struct V_22 * V_23 )
{
struct V_66 * V_50 = F_42 ( V_440 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_419 * V_557 = V_440 -> V_49 . V_28 ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
struct V_326 * V_558 =
F_417 ( V_557 , V_73 ) ;
bool V_563 = F_18 ( & V_23 -> V_49 ) ;
struct V_564 * V_565 =
F_302 ( V_557 ) ;
if ( V_558 ) {
struct V_250 * V_561 =
F_231 ( V_73 -> V_28 ) ;
struct V_250 * V_562 =
F_231 ( V_558 ) ;
F_422 ( V_50 , V_23 , V_561 ) ;
if ( V_562 -> V_49 . V_320 &&
( V_563 || ! V_561 -> V_49 . V_320 ) )
F_414 ( & V_50 -> V_49 ) ;
}
if ( F_158 ( V_6 ) && V_440 -> V_49 . V_72 &&
V_23 -> V_566 && F_415 ( V_6 , false ) )
F_347 ( V_6 , V_50 -> V_79 ) ;
if ( V_23 -> V_567 && F_423 ( V_48 ) )
F_347 ( V_6 , V_50 -> V_79 ) ;
if ( F_18 ( & V_23 -> V_49 ) )
return;
if ( V_6 -> V_432 . V_568 != NULL )
V_6 -> V_432 . V_568 ( V_565 ,
V_23 ) ;
else if ( V_23 -> V_569 )
F_419 ( V_50 ) ;
}
static void F_424 ( struct V_130 * V_50 , unsigned V_322 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_318 * V_33 ;
int V_79 = V_66 -> V_79 ;
F_408 ( V_66 ) ;
F_425 (p, dev, plane_mask)
F_227 ( V_33 ) -> V_329 ( V_33 , V_50 ) ;
F_418 ( F_35 ( V_48 ) , F_426 ( V_79 ) ) ;
}
static void F_427 ( struct V_130 * V_50 ,
struct V_22 * V_45 ,
struct V_419 * V_557 )
{
struct V_570 * V_571 ;
struct V_572 * V_573 ;
int V_120 ;
F_428 (old_state, conn, conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_571 -> V_574 ) ;
if ( V_571 -> V_50 != V_50 )
continue;
if ( V_510 -> V_575 )
V_510 -> V_575 ( V_510 , V_45 , V_571 ) ;
}
}
static void F_430 ( struct V_130 * V_50 ,
struct V_22 * V_45 ,
struct V_419 * V_557 )
{
struct V_570 * V_571 ;
struct V_572 * V_573 ;
int V_120 ;
F_428 (old_state, conn, conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_571 -> V_574 ) ;
if ( V_571 -> V_50 != V_50 )
continue;
if ( V_510 -> V_576 )
V_510 -> V_576 ( V_510 , V_45 , V_571 ) ;
}
}
static void F_431 ( struct V_130 * V_50 ,
struct V_22 * V_45 ,
struct V_419 * V_557 )
{
struct V_570 * V_571 ;
struct V_572 * V_573 ;
int V_120 ;
F_428 (old_state, conn, conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_571 -> V_574 ) ;
if ( V_571 -> V_50 != V_50 )
continue;
V_510 -> V_505 ( V_510 , V_45 , V_571 ) ;
F_432 ( V_510 , true ) ;
}
}
static void F_433 ( struct V_130 * V_50 ,
struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_570 * V_577 ;
struct V_572 * V_573 ;
int V_120 ;
F_434 (old_state, conn, old_conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_577 -> V_574 ) ;
if ( V_577 -> V_50 != V_50 )
continue;
F_432 ( V_510 , false ) ;
V_510 -> V_578 ( V_510 , V_440 , V_577 ) ;
}
}
static void F_435 ( struct V_130 * V_50 ,
struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_570 * V_577 ;
struct V_572 * V_573 ;
int V_120 ;
F_434 (old_state, conn, old_conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_577 -> V_574 ) ;
if ( V_577 -> V_50 != V_50 )
continue;
if ( V_510 -> V_579 )
V_510 -> V_579 ( V_510 , V_440 , V_577 ) ;
}
}
static void F_436 ( struct V_130 * V_50 ,
struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_570 * V_577 ;
struct V_572 * V_573 ;
int V_120 ;
F_434 (old_state, conn, old_conn_state, i) {
struct V_509 * V_510 =
F_429 ( V_577 -> V_574 ) ;
if ( V_577 -> V_50 != V_50 )
continue;
if ( V_510 -> V_580 )
V_510 -> V_580 ( V_510 , V_440 , V_577 ) ;
}
}
static void F_437 ( struct V_22 * V_23 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
struct V_564 * V_565 =
F_302 ( V_557 ) ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( V_66 -> V_75 -> V_207 || F_16 ( V_6 ) )
F_411 ( V_6 , V_79 , false ) ;
if ( V_66 -> V_75 -> V_207 )
F_438 ( V_6 , V_79 , false ) ;
if ( V_66 -> V_75 -> V_207 )
F_439 ( V_66 ) ;
if ( F_393 ( V_66 -> V_75 ) )
F_440 ( V_66 , V_581 ) ;
F_441 ( V_66 ) ;
F_442 ( V_66 ) ;
if ( V_66 -> V_75 -> V_207 ) {
F_443 ( V_66 ,
& V_66 -> V_75 -> V_582 , NULL ) ;
}
F_444 ( V_50 ) ;
V_66 -> V_72 = true ;
F_430 ( V_50 , V_23 , V_557 ) ;
if ( V_66 -> V_75 -> V_207 ) {
F_342 ( V_66 ) ;
} else {
F_150 ( V_6 , V_79 ) ;
F_151 ( V_6 , V_79 ) ;
}
F_330 ( V_66 ) ;
F_445 ( & V_23 -> V_49 ) ;
if ( V_6 -> V_432 . V_568 != NULL )
V_6 -> V_432 . V_568 ( V_565 , V_66 -> V_75 ) ;
F_155 ( V_66 ) ;
if ( V_66 -> V_75 -> V_207 )
F_386 ( V_23 ) ;
F_94 ( V_50 ) ;
F_446 ( V_50 ) ;
F_431 ( V_50 , V_23 , V_557 ) ;
if ( F_101 ( V_6 ) )
F_395 ( V_48 , V_66 -> V_79 ) ;
if ( V_66 -> V_75 -> V_207 )
F_347 ( V_6 , V_79 ) ;
F_411 ( V_6 , V_79 , true ) ;
F_438 ( V_6 , V_79 , true ) ;
}
static bool F_447 ( struct V_66 * V_50 )
{
return F_448 ( F_35 ( V_50 -> V_49 . V_48 ) ) && V_50 -> V_79 == V_98 ;
}
static void F_449 ( struct V_22 * V_23 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_23 -> V_49 . V_50 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 , V_583 ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
struct V_564 * V_565 =
F_302 ( V_557 ) ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( V_66 -> V_75 -> V_207 )
F_438 ( V_6 , V_204 ,
false ) ;
F_427 ( V_50 , V_23 , V_557 ) ;
if ( V_66 -> V_75 -> V_191 )
F_392 ( V_66 ) ;
if ( F_393 ( V_66 -> V_75 ) )
F_440 ( V_66 , V_581 ) ;
if ( ! F_450 ( V_80 ) )
F_441 ( V_66 ) ;
F_442 ( V_66 ) ;
if ( V_80 != V_584 &&
! F_450 ( V_80 ) ) {
F_119 ( F_451 ( V_80 ) ,
V_66 -> V_75 -> V_585 - 1 ) ;
}
if ( V_66 -> V_75 -> V_207 ) {
F_443 ( V_66 ,
& V_66 -> V_75 -> V_582 , NULL ) ;
}
if ( ! F_450 ( V_80 ) )
F_452 ( V_50 ) ;
F_453 ( V_50 ) ;
F_454 ( & V_23 -> V_49 ) ;
V_66 -> V_72 = true ;
if ( V_66 -> V_75 -> V_207 )
F_411 ( V_6 , V_79 , false ) ;
else
F_411 ( V_6 , V_79 , true ) ;
F_430 ( V_50 , V_23 , V_557 ) ;
if ( V_66 -> V_75 -> V_207 )
V_6 -> V_432 . V_514 ( V_66 , V_23 ) ;
if ( ! F_450 ( V_80 ) )
F_455 ( V_23 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_329 ( V_66 ) ;
else
F_330 ( V_66 ) ;
F_445 ( & V_23 -> V_49 ) ;
F_456 ( V_23 ) ;
if ( ! F_450 ( V_80 ) )
F_457 ( V_23 ) ;
if ( V_6 -> V_432 . V_568 != NULL )
V_6 -> V_432 . V_568 ( V_565 , V_23 ) ;
if ( ! F_450 ( V_80 ) )
F_155 ( V_66 ) ;
if ( V_66 -> V_75 -> V_207 )
F_394 ( V_23 ) ;
if ( F_32 ( V_66 -> V_75 , V_586 ) )
F_458 ( V_23 , true ) ;
F_94 ( V_50 ) ;
F_446 ( V_50 ) ;
F_431 ( V_50 , V_23 , V_557 ) ;
if ( V_66 -> V_75 -> V_207 ) {
F_347 ( V_6 , V_79 ) ;
F_347 ( V_6 , V_79 ) ;
F_411 ( V_6 , V_79 , true ) ;
F_438 ( V_6 , V_204 ,
true ) ;
}
V_583 = V_23 -> V_583 ;
if ( F_252 ( V_6 ) && V_583 != V_587 ) {
F_347 ( V_6 , V_583 ) ;
F_347 ( V_6 , V_583 ) ;
}
}
static void F_331 ( struct V_66 * V_50 , bool V_588 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
if ( V_588 || V_50 -> V_75 -> V_441 . V_131 ) {
F_119 ( F_400 ( V_79 ) , 0 ) ;
F_119 ( F_402 ( V_79 ) , 0 ) ;
F_119 ( F_403 ( V_79 ) , 0 ) ;
}
}
static void F_459 ( struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_440 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( V_66 -> V_75 -> V_207 ) {
F_411 ( V_6 , V_79 , false ) ;
F_438 ( V_6 , V_79 , false ) ;
}
F_433 ( V_50 , V_440 , V_557 ) ;
F_460 ( V_50 ) ;
F_94 ( V_50 ) ;
F_163 ( V_66 ) ;
F_331 ( V_66 , false ) ;
if ( V_66 -> V_75 -> V_207 )
F_344 ( V_50 ) ;
F_435 ( V_50 , V_440 , V_557 ) ;
if ( V_66 -> V_75 -> V_207 ) {
F_149 ( V_6 , V_79 ) ;
if ( F_101 ( V_6 ) ) {
T_3 V_13 ;
T_1 V_442 ;
V_13 = F_102 ( V_79 ) ;
V_442 = F_17 ( V_13 ) ;
V_442 &= ~ ( V_522 |
V_135 ) ;
V_442 |= V_589 ;
F_119 ( V_13 , V_442 ) ;
V_442 = F_17 ( V_516 ) ;
V_442 &= ~ ( F_389 ( V_79 ) | F_390 ( V_79 ) ) ;
F_119 ( V_516 , V_442 ) ;
}
F_343 ( V_66 ) ;
}
F_411 ( V_6 , V_79 , true ) ;
F_438 ( V_6 , V_79 , true ) ;
}
static void F_461 ( struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_440 -> V_49 . V_50 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
if ( V_66 -> V_75 -> V_207 )
F_438 ( V_6 , V_204 ,
false ) ;
F_433 ( V_50 , V_440 , V_557 ) ;
F_460 ( V_50 ) ;
F_94 ( V_50 ) ;
if ( ! F_450 ( V_80 ) )
F_163 ( V_66 ) ;
if ( F_32 ( V_66 -> V_75 , V_586 ) )
F_458 ( V_66 -> V_75 , false ) ;
if ( ! F_450 ( V_80 ) )
F_462 ( V_6 , V_80 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_399 ( V_66 ) ;
else
F_331 ( V_66 , false ) ;
if ( ! F_450 ( V_80 ) )
F_463 ( V_66 -> V_75 ) ;
F_435 ( V_50 , V_440 , V_557 ) ;
if ( V_440 -> V_207 )
F_438 ( V_6 , V_204 ,
true ) ;
}
static void F_464 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_22 * V_23 = V_50 -> V_75 ;
if ( ! V_23 -> V_590 . V_591 )
return;
F_21 ( F_17 ( V_592 ) & V_593 ) ;
F_124 ( V_6 , V_50 -> V_79 ) ;
F_119 ( V_594 , V_23 -> V_590 . V_595 ) ;
F_119 ( V_592 , V_23 -> V_590 . V_591 ) ;
F_119 ( F_465 ( V_50 -> V_79 ) , 0 ) ;
}
enum V_112 F_466 ( enum V_163 V_163 )
{
switch ( V_163 ) {
case V_596 :
return V_597 ;
case V_183 :
return V_598 ;
case V_185 :
return V_599 ;
case V_187 :
return V_600 ;
case V_601 :
return V_602 ;
default:
F_167 ( V_163 ) ;
return V_603 ;
}
}
static T_4 F_467 ( struct V_130 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_604 * V_510 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
T_4 V_605 ;
enum V_78 V_78 = V_45 -> V_80 ;
if ( ! V_45 -> V_49 . V_72 )
return 0 ;
V_605 = F_228 ( F_468 ( V_79 ) ) ;
V_605 |= F_228 ( F_79 ( V_78 ) ) ;
if ( V_45 -> V_441 . V_131 ||
V_45 -> V_441 . V_606 )
V_605 |= F_469 ( F_470 ( V_79 ) ) ;
F_471 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_509 * V_509 = F_429 ( V_510 ) ;
V_605 |= F_469 ( V_509 -> V_113 ) ;
}
if ( F_15 ( V_6 ) && V_45 -> V_607 )
V_605 |= F_228 ( V_608 ) ;
if ( V_45 -> V_191 )
V_605 |= F_469 ( V_609 ) ;
return V_605 ;
}
static T_4
F_472 ( struct V_130 * V_50 ,
struct V_22 * V_45 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_112 V_610 ;
T_4 V_611 , V_612 , V_613 ;
V_613 = V_66 -> V_614 ;
V_66 -> V_614 = V_612 =
F_467 ( V_50 , V_45 ) ;
V_611 = V_612 & ~ V_613 ;
F_473 (domain, domains)
F_474 ( V_6 , V_610 ) ;
return V_613 & ~ V_612 ;
}
static void F_475 ( struct V_5 * V_6 ,
T_4 V_611 )
{
enum V_112 V_610 ;
F_473 (domain, domains)
F_81 ( V_6 , V_610 ) ;
}
static void F_476 ( struct V_22 * V_23 ,
struct V_419 * V_557 )
{
struct V_564 * V_565 =
F_302 ( V_557 ) ;
struct V_130 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( F_393 ( V_66 -> V_75 ) )
F_440 ( V_66 , V_581 ) ;
F_441 ( V_66 ) ;
F_442 ( V_66 ) ;
if ( F_12 ( V_6 ) && V_79 == V_105 ) {
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_119 ( F_477 ( V_79 ) , V_615 ) ;
F_119 ( F_478 ( V_79 ) , 0 ) ;
}
F_479 ( V_66 ) ;
V_66 -> V_72 = true ;
F_411 ( V_6 , V_79 , true ) ;
F_427 ( V_50 , V_23 , V_557 ) ;
if ( F_12 ( V_6 ) ) {
F_480 ( V_66 , V_66 -> V_75 ) ;
F_131 ( V_66 , V_66 -> V_75 ) ;
} else {
F_481 ( V_66 , V_66 -> V_75 ) ;
F_123 ( V_66 , V_66 -> V_75 ) ;
}
F_430 ( V_50 , V_23 , V_557 ) ;
F_464 ( V_66 ) ;
F_445 ( & V_23 -> V_49 ) ;
V_6 -> V_432 . V_568 ( V_565 ,
V_23 ) ;
F_155 ( V_66 ) ;
F_94 ( V_50 ) ;
F_446 ( V_50 ) ;
F_431 ( V_50 , V_23 , V_557 ) ;
}
static void F_482 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_119 ( F_483 ( V_50 -> V_79 ) , V_50 -> V_75 -> V_159 . V_616 ) ;
F_119 ( F_484 ( V_50 -> V_79 ) , V_50 -> V_75 -> V_159 . V_617 ) ;
}
static void F_485 ( struct V_22 * V_23 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
if ( F_21 ( V_66 -> V_72 ) )
return;
F_482 ( V_66 ) ;
if ( F_393 ( V_66 -> V_75 ) )
F_440 ( V_66 , V_581 ) ;
F_441 ( V_66 ) ;
F_442 ( V_66 ) ;
F_479 ( V_66 ) ;
V_66 -> V_72 = true ;
if ( ! F_50 ( V_6 ) )
F_411 ( V_6 , V_79 , true ) ;
F_430 ( V_50 , V_23 , V_557 ) ;
F_134 ( V_66 ) ;
F_464 ( V_66 ) ;
F_445 ( & V_23 -> V_49 ) ;
F_419 ( V_66 ) ;
F_155 ( V_66 ) ;
F_94 ( V_50 ) ;
F_446 ( V_50 ) ;
F_431 ( V_50 , V_23 , V_557 ) ;
}
static void F_486 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_590 . V_591 )
return;
F_124 ( V_6 , V_50 -> V_79 ) ;
F_13 ( L_84 ,
F_17 ( V_592 ) ) ;
F_119 ( V_592 , 0 ) ;
}
static void F_487 ( struct V_22 * V_440 ,
struct V_419 * V_557 )
{
struct V_130 * V_50 = V_440 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_50 ( V_6 ) )
F_347 ( V_6 , V_79 ) ;
F_433 ( V_50 , V_440 , V_557 ) ;
F_460 ( V_50 ) ;
F_94 ( V_50 ) ;
F_163 ( V_66 ) ;
F_486 ( V_66 ) ;
F_435 ( V_50 , V_440 , V_557 ) ;
if ( ! F_32 ( V_66 -> V_75 , V_208 ) ) {
if ( F_12 ( V_6 ) )
F_139 ( V_6 , V_79 ) ;
else if ( F_11 ( V_6 ) )
F_138 ( V_6 , V_79 ) ;
else
F_137 ( V_66 ) ;
}
F_436 ( V_50 , V_440 , V_557 ) ;
if ( ! F_50 ( V_6 ) )
F_411 ( V_6 , V_79 , false ) ;
if ( ! V_6 -> V_432 . V_568 )
F_419 ( V_66 ) ;
}
static void F_488 ( struct V_130 * V_50 ,
struct V_420 * V_421 )
{
struct V_509 * V_510 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
enum V_112 V_610 ;
T_4 V_611 ;
struct V_419 * V_28 ;
struct V_22 * V_45 ;
int V_349 ;
if ( ! V_66 -> V_72 )
return;
if ( V_50 -> V_73 -> V_28 -> V_320 ) {
F_21 ( V_66 -> V_439 ) ;
F_236 ( V_50 ) ;
F_424 ( V_50 , 1 << F_229 ( V_50 -> V_73 ) ) ;
V_50 -> V_73 -> V_28 -> V_320 = false ;
}
V_28 = F_489 ( V_50 -> V_48 ) ;
if ( ! V_28 ) {
F_156 ( L_85 ,
V_50 -> V_49 . V_324 , V_50 -> V_12 ) ;
return;
}
V_28 -> V_430 = V_421 ;
V_45 = F_490 ( V_28 , V_66 ) ;
V_349 = F_491 ( V_28 , V_50 ) ;
F_21 ( F_188 ( V_45 ) || V_349 ) ;
V_6 -> V_432 . V_618 ( V_45 , V_28 ) ;
F_312 ( V_28 ) ;
F_156 ( L_86 ,
V_50 -> V_49 . V_324 , V_50 -> V_12 ) ;
F_21 ( F_492 ( V_50 -> V_28 , NULL ) < 0 ) ;
V_50 -> V_28 -> V_72 = false ;
V_66 -> V_72 = false ;
V_50 -> V_131 = false ;
V_50 -> V_28 -> V_619 = 0 ;
V_50 -> V_28 -> V_620 = 0 ;
F_384 (crtc->dev, crtc, encoder)
V_510 -> V_49 . V_50 = NULL ;
F_493 ( V_66 ) ;
F_419 ( V_66 ) ;
F_494 ( V_66 ) ;
V_611 = V_66 -> V_614 ;
F_473 (domain, domains)
F_81 ( V_6 , V_610 ) ;
V_66 -> V_614 = 0 ;
V_6 -> V_621 &= ~ ( 1 << V_66 -> V_79 ) ;
V_6 -> V_622 [ V_66 -> V_79 ] = 0 ;
}
int F_495 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_419 * V_28 ;
int V_349 ;
V_28 = F_496 ( V_48 ) ;
V_349 = F_497 ( V_28 ) ;
if ( V_349 )
F_122 ( L_55 , V_349 ) ;
else
V_6 -> V_429 = V_28 ;
return V_349 ;
}
void F_498 ( struct V_604 * V_510 )
{
struct V_509 * V_509 = F_429 ( V_510 ) ;
F_499 ( V_510 ) ;
F_232 ( V_509 ) ;
}
static void F_500 ( struct V_623 * V_624 )
{
struct V_130 * V_50 = V_624 -> V_49 . V_28 -> V_50 ;
F_156 ( L_87 ,
V_624 -> V_49 . V_49 . V_324 ,
V_624 -> V_49 . V_12 ) ;
if ( V_624 -> V_625 ( V_624 ) ) {
struct V_509 * V_510 = V_624 -> V_510 ;
struct V_570 * V_571 = V_624 -> V_49 . V_28 ;
F_59 ( ! V_50 ,
L_88 ) ;
if ( ! V_50 )
return;
F_59 ( ! V_50 -> V_28 -> V_72 ,
L_89 ) ;
if ( ! V_510 || V_510 -> type == V_586 )
return;
F_59 ( V_571 -> V_574 != & V_510 -> V_49 ,
L_90 ) ;
F_59 ( V_571 -> V_50 != V_510 -> V_49 . V_50 ,
L_91 ) ;
} else {
F_59 ( V_50 && V_50 -> V_28 -> V_72 ,
L_92 ) ;
F_59 ( ! V_50 && V_624 -> V_49 . V_28 -> V_574 ,
L_93 ) ;
}
}
int F_501 ( struct V_623 * V_624 )
{
F_502 ( & V_624 -> V_49 ) ;
if ( ! V_624 -> V_49 . V_28 )
return - V_626 ;
return 0 ;
}
struct V_623 * F_503 ( void )
{
struct V_623 * V_624 ;
V_624 = F_504 ( sizeof *V_624 , V_627 ) ;
if ( ! V_624 )
return NULL ;
if ( F_501 ( V_624 ) < 0 ) {
F_232 ( V_624 ) ;
return NULL ;
}
return V_624 ;
}
bool F_505 ( struct V_623 * V_624 )
{
enum V_79 V_79 = 0 ;
struct V_509 * V_510 = V_624 -> V_510 ;
return V_510 -> V_625 ( V_510 , & V_79 ) ;
}
static int F_506 ( struct V_22 * V_45 )
{
if ( V_45 -> V_49 . V_505 && V_45 -> V_207 )
return V_45 -> V_455 ;
return 0 ;
}
static int F_507 ( struct V_47 * V_48 , enum V_79 V_79 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_419 * V_28 = V_23 -> V_49 . V_28 ;
struct V_66 * V_628 ;
struct V_22 * V_629 ;
F_156 ( L_94 ,
F_73 ( V_79 ) , V_23 -> V_455 ) ;
if ( V_23 -> V_455 > 4 ) {
F_156 ( L_95 ,
F_73 ( V_79 ) , V_23 -> V_455 ) ;
return - V_272 ;
}
if ( F_252 ( V_6 ) || F_253 ( V_6 ) ) {
if ( V_23 -> V_455 > 2 ) {
F_156 ( L_96 ,
V_23 -> V_455 ) ;
return - V_272 ;
} else {
return 0 ;
}
}
if ( F_178 ( V_6 ) -> V_630 == 2 )
return 0 ;
switch ( V_79 ) {
case V_98 :
return 0 ;
case V_105 :
if ( V_23 -> V_455 <= 2 )
return 0 ;
V_628 = F_47 ( V_6 , V_508 ) ;
V_629 =
F_490 ( V_28 , V_628 ) ;
if ( F_188 ( V_629 ) )
return F_238 ( V_629 ) ;
if ( F_506 ( V_629 ) > 0 ) {
F_156 ( L_97 ,
F_73 ( V_79 ) , V_23 -> V_455 ) ;
return - V_272 ;
}
return 0 ;
case V_508 :
if ( V_23 -> V_455 > 2 ) {
F_156 ( L_98 ,
F_73 ( V_79 ) , V_23 -> V_455 ) ;
return - V_272 ;
}
V_628 = F_47 ( V_6 , V_105 ) ;
V_629 =
F_490 ( V_28 , V_628 ) ;
if ( F_188 ( V_629 ) )
return F_238 ( V_629 ) ;
if ( F_506 ( V_629 ) > 2 ) {
F_156 ( L_99 ) ;
return - V_272 ;
}
return 0 ;
default:
F_141 () ;
}
}
static int F_508 ( struct V_66 * V_66 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
const struct V_518 * V_76 = & V_23 -> V_49 . V_76 ;
int V_631 , V_632 , V_633 , V_349 ;
bool V_634 = false ;
V_460:
V_632 = F_14 ( F_35 ( V_48 ) , V_23 ) ;
V_633 = V_76 -> V_77 ;
V_631 = F_509 ( V_633 , V_632 ,
V_23 -> V_635 ) ;
V_23 -> V_455 = V_631 ;
F_510 ( V_23 -> V_635 , V_631 , V_633 ,
V_632 , & V_23 -> V_582 , false ) ;
V_349 = F_507 ( V_48 , V_66 -> V_79 , V_23 ) ;
if ( V_349 == - V_272 && V_23 -> V_635 > 6 * 3 ) {
V_23 -> V_635 -= 2 * 3 ;
F_156 ( L_100 ,
V_23 -> V_635 ) ;
V_634 = true ;
V_23 -> V_636 = true ;
goto V_460;
}
if ( V_634 )
return V_637 ;
return V_349 ;
}
static bool F_511 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_635 > 24 )
return false ;
if ( F_252 ( V_6 ) )
return true ;
return V_23 -> V_638 <=
V_6 -> V_639 * 95 / 100 ;
}
static void F_512 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_23 -> V_548 = V_244 . V_640 &&
F_447 ( V_50 ) &&
F_511 ( V_6 , V_23 ) ;
}
static bool F_513 ( const struct V_66 * V_50 )
{
const struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
return F_178 ( V_6 ) -> V_235 < 4 &&
( V_50 -> V_79 == V_98 || F_514 ( V_6 ) ) ;
}
static T_2 F_515 ( const struct V_22 * V_23 )
{
T_2 V_638 ;
V_638 = V_23 -> V_49 . V_76 . V_77 ;
if ( V_23 -> V_441 . V_131 ) {
V_40 V_641 , V_642 , V_643 , V_644 ;
T_2 V_645 = V_23 -> V_441 . V_227 ;
V_641 = V_23 -> V_368 ;
V_642 = V_23 -> V_367 ;
V_643 = ( V_645 >> 16 ) & 0xFFFF ;
V_644 = V_645 & 0xFFFF ;
if ( V_641 < V_643 )
V_641 = V_643 ;
if ( V_642 < V_644 )
V_642 = V_644 ;
if ( F_21 ( ! V_643 || ! V_644 ) )
return V_638 ;
V_638 = F_40 ( ( V_40 ) V_638 * V_641 * V_642 ,
V_643 * V_644 ) ;
}
return V_638 ;
}
static void F_516 ( struct V_22 * V_45 )
{
struct V_5 * V_6 = F_35 ( V_45 -> V_49 . V_50 -> V_48 ) ;
if ( F_158 ( V_6 ) )
V_45 -> V_638 =
V_45 -> V_49 . V_76 . V_77 ;
else
V_45 -> V_638 =
F_515 ( V_45 ) ;
}
static int F_517 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_518 * V_76 = & V_23 -> V_49 . V_76 ;
int V_646 = V_6 -> V_647 ;
if ( F_53 ( V_6 ) < 4 ) {
V_646 = V_6 -> V_639 * 9 / 10 ;
if ( F_513 ( V_50 ) &&
V_76 -> V_77 > V_646 ) {
V_646 = V_6 -> V_647 ;
V_23 -> V_211 = true ;
}
}
if ( V_76 -> V_77 > V_646 ) {
F_156 ( L_101 ,
V_76 -> V_77 , V_646 ,
F_518 ( V_23 -> V_211 ) ) ;
return - V_272 ;
}
if ( ( F_32 ( V_23 , V_51 ) &&
F_33 ( V_48 ) ) || V_23 -> V_211 )
V_23 -> V_368 &= ~ 1 ;
if ( ( F_53 ( V_6 ) > 4 || F_249 ( V_6 ) ) &&
V_76 -> V_648 == V_76 -> V_541 )
return - V_272 ;
F_516 ( V_23 ) ;
if ( F_448 ( V_6 ) )
F_512 ( V_50 , V_23 ) ;
if ( V_23 -> V_207 )
return F_508 ( V_50 , V_23 ) ;
return 0 ;
}
static void
F_519 ( T_2 * V_649 , T_2 * V_650 )
{
while ( * V_649 > V_651 ||
* V_650 > V_651 ) {
* V_649 >>= 1 ;
* V_650 >>= 1 ;
}
}
static void F_520 ( unsigned int V_31 , unsigned int V_36 ,
T_2 * V_652 , T_2 * V_653 ,
bool V_654 )
{
if ( V_654 ) {
while ( ( V_31 & 1 ) == 0 && ( V_36 & 1 ) == 0 ) {
V_31 >>= 1 ;
V_36 >>= 1 ;
}
}
* V_653 = F_521 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_652 = F_40 ( ( V_40 ) V_31 * * V_653 , V_36 ) ;
F_519 ( V_652 , V_653 ) ;
}
void
F_510 ( int V_655 , int V_656 ,
int V_657 , int V_658 ,
struct V_659 * V_660 ,
bool V_654 )
{
V_660 -> V_661 = 64 ;
F_520 ( V_655 * V_657 ,
V_658 * V_656 * 8 ,
& V_660 -> V_662 , & V_660 -> V_663 ,
V_654 ) ;
F_520 ( V_657 , V_658 ,
& V_660 -> V_664 , & V_660 -> V_665 ,
V_654 ) ;
}
static inline bool F_522 ( struct V_5 * V_6 )
{
if ( V_244 . V_666 >= 0 )
return V_244 . V_666 != 0 ;
return V_6 -> V_667 . V_668
&& ! ( V_6 -> V_114 & V_669 ) ;
}
static T_2 F_523 ( struct V_30 * V_30 )
{
return ( 1 << V_30 -> V_36 ) << 16 | V_30 -> V_32 ;
}
static T_2 F_524 ( struct V_30 * V_30 )
{
return V_30 -> V_36 << 16 | V_30 -> V_39 << 8 | V_30 -> V_32 ;
}
static void F_525 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_670 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_671 , V_672 = 0 ;
if ( F_29 ( V_6 ) ) {
V_671 = F_523 ( & V_45 -> V_30 ) ;
if ( V_670 )
V_672 = F_523 ( V_670 ) ;
} else {
V_671 = F_524 ( & V_45 -> V_30 ) ;
if ( V_670 )
V_672 = F_524 ( V_670 ) ;
}
V_45 -> V_159 . V_616 = V_671 ;
V_50 -> V_673 = false ;
if ( F_32 ( V_45 , V_51 ) &&
V_670 ) {
V_45 -> V_159 . V_617 = V_672 ;
V_50 -> V_673 = true ;
} else {
V_45 -> V_159 . V_617 = V_671 ;
}
}
static void F_526 ( struct V_5 * V_6 , enum V_79
V_79 )
{
T_1 V_674 ;
V_674 = F_128 ( V_6 , V_79 , F_527 ( 1 ) ) ;
V_674 &= 0xffffff00 ;
V_674 |= 0x00000030 ;
F_130 ( V_6 , V_79 , F_527 ( 1 ) , V_674 ) ;
V_674 = F_128 ( V_6 , V_79 , V_675 ) ;
V_674 &= 0x8cffffff ;
V_674 = 0x8c000000 ;
F_130 ( V_6 , V_79 , V_675 , V_674 ) ;
V_674 = F_128 ( V_6 , V_79 , F_527 ( 1 ) ) ;
V_674 &= 0xffffff00 ;
F_130 ( V_6 , V_79 , F_527 ( 1 ) , V_674 ) ;
V_674 = F_128 ( V_6 , V_79 , V_675 ) ;
V_674 &= 0x00ffffff ;
V_674 |= 0xb0000000 ;
F_130 ( V_6 , V_79 , V_675 , V_674 ) ;
}
static void F_528 ( struct V_66 * V_50 ,
struct V_659 * V_660 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
F_119 ( F_529 ( V_79 ) , F_530 ( V_660 -> V_661 ) | V_660 -> V_662 ) ;
F_119 ( F_531 ( V_79 ) , V_660 -> V_663 ) ;
F_119 ( F_532 ( V_79 ) , V_660 -> V_664 ) ;
F_119 ( F_533 ( V_79 ) , V_660 -> V_665 ) ;
}
static void F_443 ( struct V_66 * V_50 ,
struct V_659 * V_660 ,
struct V_659 * V_676 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int V_79 = V_50 -> V_79 ;
enum V_78 V_78 = V_50 -> V_75 -> V_80 ;
if ( F_53 ( V_6 ) >= 5 ) {
F_119 ( F_388 ( V_78 ) , F_530 ( V_660 -> V_661 ) | V_660 -> V_662 ) ;
F_119 ( F_534 ( V_78 ) , V_660 -> V_663 ) ;
F_119 ( F_535 ( V_78 ) , V_660 -> V_664 ) ;
F_119 ( F_536 ( V_78 ) , V_660 -> V_665 ) ;
if ( V_676 && ( F_12 ( V_6 ) ||
F_53 ( V_6 ) < 8 ) && V_50 -> V_75 -> V_677 ) {
F_119 ( F_537 ( V_78 ) ,
F_530 ( V_676 -> V_661 ) | V_676 -> V_662 ) ;
F_119 ( F_538 ( V_78 ) , V_676 -> V_663 ) ;
F_119 ( F_539 ( V_78 ) , V_676 -> V_664 ) ;
F_119 ( F_540 ( V_78 ) , V_676 -> V_665 ) ;
}
} else {
F_119 ( F_541 ( V_79 ) , F_530 ( V_660 -> V_661 ) | V_660 -> V_662 ) ;
F_119 ( F_542 ( V_79 ) , V_660 -> V_663 ) ;
F_119 ( F_543 ( V_79 ) , V_660 -> V_664 ) ;
F_119 ( F_544 ( V_79 ) , V_660 -> V_665 ) ;
}
}
void F_440 ( struct V_66 * V_50 , enum V_678 V_660 )
{
struct V_659 * V_679 , * V_680 = NULL ;
if ( V_660 == V_581 ) {
V_679 = & V_50 -> V_75 -> V_679 ;
V_680 = & V_50 -> V_75 -> V_680 ;
} else if ( V_660 == V_681 ) {
V_679 = & V_50 -> V_75 -> V_680 ;
} else {
F_122 ( L_102 ) ;
return;
}
if ( V_50 -> V_75 -> V_207 )
F_528 ( V_50 , & V_50 -> V_75 -> V_679 ) ;
else
F_443 ( V_50 , V_679 , V_680 ) ;
}
static void F_545 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
V_23 -> V_159 . V_30 = V_174 |
V_175 | V_170 ;
if ( V_50 -> V_79 != V_98 )
V_23 -> V_159 . V_30 |= V_176 ;
if ( ! F_32 ( V_23 , V_208 ) )
V_23 -> V_159 . V_30 |= V_88 |
V_682 ;
V_23 -> V_159 . V_161 =
( V_23 -> V_585 - 1 ) << V_683 ;
}
static void F_546 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
V_23 -> V_159 . V_30 = V_177 |
V_175 | V_170 ;
if ( V_50 -> V_79 != V_98 )
V_23 -> V_159 . V_30 |= V_176 ;
if ( ! F_32 ( V_23 , V_208 ) )
V_23 -> V_159 . V_30 |= V_88 ;
V_23 -> V_159 . V_161 =
( V_23 -> V_585 - 1 ) << V_683 ;
}
static void F_481 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
T_1 V_684 ;
T_1 V_685 , V_686 , V_687 , V_688 , V_689 ;
T_1 V_690 , V_674 ;
F_119 ( F_58 ( V_79 ) ,
V_23 -> V_159 . V_30 &
~ ( V_88 | V_682 ) ) ;
if ( ( V_23 -> V_159 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_685 = V_23 -> V_30 . V_36 ;
V_686 = V_23 -> V_30 . V_39 ;
V_687 = V_23 -> V_30 . V_32 ;
V_688 = V_23 -> V_30 . V_34 ;
V_689 = V_23 -> V_30 . V_35 ;
if ( V_79 == V_105 )
F_526 ( V_6 , V_79 ) ;
F_130 ( V_6 , V_79 , V_691 , 0x0100000f ) ;
V_674 = F_128 ( V_6 , V_79 , F_547 ( V_79 ) ) ;
V_674 &= 0x00ffffff ;
F_130 ( V_6 , V_79 , F_547 ( V_79 ) , V_674 ) ;
F_130 ( V_6 , V_79 , V_692 , 0x610 ) ;
V_684 = ( ( V_686 << V_693 ) | ( V_687 & V_694 ) ) ;
V_684 |= ( ( V_688 << V_695 ) | ( V_689 << V_696 ) ) ;
V_684 |= ( ( V_685 << V_697 ) ) ;
V_684 |= ( 1 << V_698 ) ;
V_684 |= ( V_699 << V_700 ) ;
F_130 ( V_6 , V_79 , F_548 ( V_79 ) , V_684 ) ;
V_684 |= V_701 ;
F_130 ( V_6 , V_79 , F_548 ( V_79 ) , V_684 ) ;
if ( V_23 -> V_24 == 162000 ||
F_32 ( V_50 -> V_75 , V_702 ) ||
F_32 ( V_50 -> V_75 , V_194 ) )
F_130 ( V_6 , V_79 , F_549 ( V_79 ) ,
0x009f0003 ) ;
else
F_130 ( V_6 , V_79 , F_549 ( V_79 ) ,
0x00d0000f ) ;
if ( F_393 ( V_23 ) ) {
if ( V_79 == V_98 )
F_130 ( V_6 , V_79 , F_550 ( V_79 ) ,
0x0df40000 ) ;
else
F_130 ( V_6 , V_79 , F_550 ( V_79 ) ,
0x0df70000 ) ;
} else {
if ( V_79 == V_98 )
F_130 ( V_6 , V_79 , F_550 ( V_79 ) ,
0x0df70000 ) ;
else
F_130 ( V_6 , V_79 , F_550 ( V_79 ) ,
0x0df40000 ) ;
}
V_690 = F_128 ( V_6 , V_79 , F_551 ( V_79 ) ) ;
V_690 = ( V_690 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_393 ( V_50 -> V_75 ) )
V_690 |= 0x01000000 ;
F_130 ( V_6 , V_79 , F_551 ( V_79 ) , V_690 ) ;
F_130 ( V_6 , V_79 , F_552 ( V_79 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_480 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_162 V_163 = F_127 ( V_79 ) ;
T_1 V_703 , V_704 ;
T_1 V_685 , V_686 , V_687 , V_688 , V_689 , V_705 ;
T_1 V_706 ;
int V_37 ;
F_119 ( F_58 ( V_79 ) ,
V_23 -> V_159 . V_30 & ~ V_88 ) ;
if ( ( V_23 -> V_159 . V_30 & V_88 ) == 0 )
return;
V_685 = V_23 -> V_30 . V_36 ;
V_705 = V_23 -> V_30 . V_32 & 0x3fffff ;
V_686 = V_23 -> V_30 . V_39 ;
V_687 = V_23 -> V_30 . V_32 >> 22 ;
V_688 = V_23 -> V_30 . V_34 ;
V_689 = V_23 -> V_30 . V_35 ;
V_37 = V_23 -> V_30 . V_37 ;
V_706 = 0 ;
V_703 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_130 ( V_6 , V_79 , F_553 ( V_163 ) ,
5 << V_707 |
V_688 << V_708 |
V_689 << V_709 |
1 << V_710 ) ;
F_130 ( V_6 , V_79 , F_554 ( V_163 ) , V_687 ) ;
F_130 ( V_6 , V_79 , F_555 ( V_163 ) ,
V_711 |
1 << V_712 ) ;
F_130 ( V_6 , V_79 , F_556 ( V_163 ) , V_705 ) ;
V_706 = F_128 ( V_6 , V_79 , F_557 ( V_163 ) ) ;
V_706 &= ~ ( V_713 | V_714 ) ;
V_706 |= ( 2 << V_715 ) ;
if ( V_705 )
V_706 |= V_714 ;
F_130 ( V_6 , V_79 , F_557 ( V_163 ) , V_706 ) ;
V_706 = F_128 ( V_6 , V_79 , F_558 ( V_163 ) ) ;
V_706 &= ~ ( V_716 |
V_717 ) ;
V_706 |= ( 0x5 << V_718 ) ;
if ( ! V_705 )
V_706 |= V_717 ;
F_130 ( V_6 , V_79 , F_558 ( V_163 ) , V_706 ) ;
if ( V_37 == 5400000 ) {
V_703 |= ( 0x3 << V_719 ) ;
V_703 |= ( 0x8 << V_720 ) ;
V_703 |= ( 0x1 << V_721 ) ;
V_704 = 0x9 ;
} else if ( V_37 <= 6200000 ) {
V_703 |= ( 0x5 << V_719 ) ;
V_703 |= ( 0xB << V_720 ) ;
V_703 |= ( 0x3 << V_721 ) ;
V_704 = 0x9 ;
} else if ( V_37 <= 6480000 ) {
V_703 |= ( 0x4 << V_719 ) ;
V_703 |= ( 0x9 << V_720 ) ;
V_703 |= ( 0x3 << V_721 ) ;
V_704 = 0x8 ;
} else {
V_703 |= ( 0x4 << V_719 ) ;
V_703 |= ( 0x9 << V_720 ) ;
V_703 |= ( 0x3 << V_721 ) ;
V_704 = 0 ;
}
F_130 ( V_6 , V_79 , F_559 ( V_163 ) , V_703 ) ;
V_706 = F_128 ( V_6 , V_79 , F_560 ( V_163 ) ) ;
V_706 &= ~ V_722 ;
V_706 |= ( V_704 << V_723 ) ;
F_130 ( V_6 , V_79 , F_560 ( V_163 ) , V_706 ) ;
F_130 ( V_6 , V_79 , F_129 ( V_163 ) ,
F_128 ( V_6 , V_79 , F_129 ( V_163 ) ) |
V_724 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_561 ( struct V_5 * V_6 , enum V_79 V_79 ,
const struct V_30 * V_30 )
{
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_22 * V_23 ;
V_23 = F_504 ( sizeof( * V_23 ) , V_627 ) ;
if ( ! V_23 )
return - V_626 ;
V_23 -> V_49 . V_50 = & V_50 -> V_49 ;
V_23 -> V_585 = 1 ;
V_23 -> V_30 = * V_30 ;
if ( F_12 ( V_6 ) ) {
F_546 ( V_50 , V_23 ) ;
F_480 ( V_50 , V_23 ) ;
F_131 ( V_50 , V_23 ) ;
} else {
F_545 ( V_50 , V_23 ) ;
F_481 ( V_50 , V_23 ) ;
F_123 ( V_50 , V_23 ) ;
}
F_232 ( V_23 ) ;
return 0 ;
}
void F_562 ( struct V_5 * V_6 , enum V_79 V_79 )
{
if ( F_12 ( V_6 ) )
F_139 ( V_6 , V_79 ) ;
else
F_138 ( V_6 , V_79 ) ;
}
static void F_563 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_670 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_30 ;
struct V_30 * clock = & V_45 -> V_30 ;
F_525 ( V_50 , V_45 , V_670 ) ;
V_30 = V_170 ;
if ( F_32 ( V_45 , V_51 ) )
V_30 |= V_725 ;
else
V_30 |= V_726 ;
if ( F_564 ( V_6 ) || F_565 ( V_6 ) ||
F_566 ( V_6 ) || F_29 ( V_6 ) ) {
V_30 |= ( V_45 -> V_585 - 1 )
<< V_727 ;
}
if ( F_32 ( V_45 , V_199 ) ||
F_32 ( V_45 , V_194 ) )
V_30 |= V_728 ;
if ( F_393 ( V_45 ) )
V_30 |= V_728 ;
if ( F_29 ( V_6 ) )
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_729 ;
else {
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_730 ;
if ( F_249 ( V_6 ) && V_670 )
V_30 |= ( 1 << ( V_670 -> V_34 - 1 ) ) << V_731 ;
}
switch ( clock -> V_35 ) {
case 5 :
V_30 |= V_732 ;
break;
case 7 :
V_30 |= V_733 ;
break;
case 10 :
V_30 |= V_734 ;
break;
case 14 :
V_30 |= V_735 ;
break;
}
if ( F_53 ( V_6 ) >= 4 )
V_30 |= ( 6 << V_736 ) ;
if ( V_45 -> V_737 )
V_30 |= V_738 ;
else if ( F_32 ( V_45 , V_51 ) &&
F_522 ( V_6 ) )
V_30 |= V_739 ;
else
V_30 |= V_740 ;
V_30 |= V_88 ;
V_45 -> V_159 . V_30 = V_30 ;
if ( F_53 ( V_6 ) >= 4 ) {
T_1 V_161 = ( V_45 -> V_585 - 1 )
<< V_683 ;
V_45 -> V_159 . V_161 = V_161 ;
}
}
static void F_567 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_670 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 ;
struct V_30 * clock = & V_45 -> V_30 ;
F_525 ( V_50 , V_45 , V_670 ) ;
V_30 = V_170 ;
if ( F_32 ( V_45 , V_51 ) ) {
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_730 ;
} else {
if ( clock -> V_34 == 2 )
V_30 |= V_741 ;
else
V_30 |= ( clock -> V_34 - 2 ) << V_730 ;
if ( clock -> V_35 == 4 )
V_30 |= V_742 ;
}
if ( ! F_136 ( V_6 ) &&
F_32 ( V_45 , V_172 ) )
V_30 |= V_173 ;
if ( F_32 ( V_45 , V_51 ) &&
F_522 ( V_6 ) )
V_30 |= V_739 ;
else
V_30 |= V_740 ;
V_30 |= V_88 ;
V_45 -> V_159 . V_30 = V_30 ;
}
static void F_441 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
const struct V_518 * V_76 = & V_66 -> V_75 -> V_49 . V_76 ;
T_2 V_743 , V_744 ;
int V_745 = 0 ;
V_743 = V_76 -> V_743 ;
V_744 = V_76 -> V_744 ;
if ( V_76 -> V_315 & V_746 ) {
V_743 -= 1 ;
V_744 -= 1 ;
if ( F_32 ( V_66 -> V_75 , V_199 ) )
V_745 = ( V_76 -> V_747 - 1 ) / 2 ;
else
V_745 = V_76 -> V_648 -
V_76 -> V_747 / 2 ;
if ( V_745 < 0 )
V_745 += V_76 -> V_747 ;
}
if ( F_53 ( V_6 ) > 3 )
F_119 ( F_380 ( V_80 ) , V_745 ) ;
F_119 ( F_368 ( V_80 ) ,
( V_76 -> V_541 - 1 ) |
( ( V_76 -> V_747 - 1 ) << 16 ) ) ;
F_119 ( F_370 ( V_80 ) ,
( V_76 -> V_748 - 1 ) |
( ( V_76 -> V_749 - 1 ) << 16 ) ) ;
F_119 ( F_372 ( V_80 ) ,
( V_76 -> V_648 - 1 ) |
( ( V_76 -> V_750 - 1 ) << 16 ) ) ;
F_119 ( F_374 ( V_80 ) ,
( V_76 -> V_542 - 1 ) |
( ( V_743 - 1 ) << 16 ) ) ;
F_119 ( F_376 ( V_80 ) ,
( V_76 -> V_751 - 1 ) |
( ( V_744 - 1 ) << 16 ) ) ;
F_119 ( F_378 ( V_80 ) ,
( V_76 -> V_752 - 1 ) |
( ( V_76 -> V_753 - 1 ) << 16 ) ) ;
if ( F_252 ( V_6 ) && V_80 == V_584 &&
( V_79 == V_105 || V_79 == V_508 ) )
F_119 ( F_374 ( V_79 ) , F_17 ( F_374 ( V_80 ) ) ) ;
}
static void F_442 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
F_119 ( F_328 ( V_79 ) ,
( ( V_66 -> V_75 -> V_368 - 1 ) << 16 ) |
( V_66 -> V_75 -> V_367 - 1 ) ) ;
}
static void F_568 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_23 -> V_80 ;
T_2 V_164 ;
V_164 = F_17 ( F_368 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_541 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_747 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_164 = F_17 ( F_370 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_748 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_749 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_164 = F_17 ( F_372 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_648 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_750 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_164 = F_17 ( F_374 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_542 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_743 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_164 = F_17 ( F_376 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_751 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_744 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_164 = F_17 ( F_378 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_752 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_753 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
if ( F_17 ( F_54 ( V_80 ) ) & V_197 ) {
V_23 -> V_49 . V_76 . V_315 |= V_746 ;
V_23 -> V_49 . V_76 . V_743 += 1 ;
V_23 -> V_49 . V_76 . V_744 += 1 ;
}
}
static void F_569 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_164 ;
V_164 = F_17 ( F_328 ( V_50 -> V_79 ) ) ;
V_23 -> V_367 = ( V_164 & 0xffff ) + 1 ;
V_23 -> V_368 = ( ( V_164 >> 16 ) & 0xffff ) + 1 ;
V_23 -> V_49 . V_417 . V_754 = V_23 -> V_367 ;
V_23 -> V_49 . V_417 . V_755 = V_23 -> V_368 ;
}
void F_570 ( struct V_518 * V_417 ,
struct V_22 * V_23 )
{
V_417 -> V_755 = V_23 -> V_49 . V_76 . V_541 ;
V_417 -> V_756 = V_23 -> V_49 . V_76 . V_747 ;
V_417 -> V_757 = V_23 -> V_49 . V_76 . V_648 ;
V_417 -> V_758 = V_23 -> V_49 . V_76 . V_750 ;
V_417 -> V_754 = V_23 -> V_49 . V_76 . V_542 ;
V_417 -> V_759 = V_23 -> V_49 . V_76 . V_743 ;
V_417 -> V_760 = V_23 -> V_49 . V_76 . V_752 ;
V_417 -> V_761 = V_23 -> V_49 . V_76 . V_753 ;
V_417 -> V_315 = V_23 -> V_49 . V_76 . V_315 ;
V_417 -> type = V_762 ;
V_417 -> clock = V_23 -> V_49 . V_76 . V_77 ;
V_417 -> V_763 = F_571 ( V_417 ) ;
V_417 -> V_764 = F_572 ( V_417 ) ;
F_573 ( V_417 ) ;
}
static void F_479 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
T_2 V_765 ;
V_765 = 0 ;
if ( ( V_66 -> V_79 == V_98 && V_6 -> V_114 & V_115 ) ||
( V_66 -> V_79 == V_105 && V_6 -> V_114 & V_116 ) )
V_765 |= F_17 ( F_54 ( V_66 -> V_79 ) ) & V_117 ;
if ( V_66 -> V_75 -> V_211 )
V_765 |= V_212 ;
if ( F_249 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) {
if ( V_66 -> V_75 -> V_766 && V_66 -> V_75 -> V_635 != 30 )
V_765 |= V_767 |
V_768 ;
switch ( V_66 -> V_75 -> V_635 ) {
case 18 :
V_765 |= V_769 ;
break;
case 24 :
V_765 |= V_195 ;
break;
case 30 :
V_765 |= V_770 ;
break;
default:
F_141 () ;
}
}
if ( F_574 ( V_6 ) ) {
if ( V_66 -> V_673 ) {
F_156 ( L_103 ) ;
V_765 |= V_771 ;
} else {
F_156 ( L_104 ) ;
}
}
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_746 ) {
if ( F_53 ( V_6 ) < 4 ||
F_32 ( V_66 -> V_75 , V_199 ) )
V_765 |= V_772 ;
else
V_765 |= V_773 ;
} else
V_765 |= V_774 ;
if ( ( F_11 ( V_6 ) || F_12 ( V_6 ) ) &&
V_66 -> V_75 -> V_775 )
V_765 |= V_776 ;
F_119 ( F_54 ( V_66 -> V_79 ) , V_765 ) ;
F_120 ( F_54 ( V_66 -> V_79 ) ) ;
}
static int F_575 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 48000 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_522 ( V_6 ) ) {
V_29 = V_6 -> V_667 . V_777 ;
F_156 ( L_105 , V_29 ) ;
}
V_42 = & V_778 ;
} else if ( F_32 ( V_45 , V_172 ) ) {
V_42 = & V_779 ;
} else {
V_42 = & V_780 ;
}
if ( ! V_45 -> V_781 &&
! F_34 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_567 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_576 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_522 ( V_6 ) ) {
V_29 = V_6 -> V_667 . V_777 ;
F_156 ( L_105 , V_29 ) ;
}
if ( F_33 ( V_48 ) )
V_42 = & V_782 ;
else
V_42 = & V_783 ;
} else if ( F_32 ( V_45 , V_194 ) ||
F_32 ( V_45 , V_702 ) ) {
V_42 = & V_784 ;
} else if ( F_32 ( V_45 , V_199 ) ) {
V_42 = & V_785 ;
} else {
V_42 = & V_786 ;
}
if ( ! V_45 -> V_781 &&
! F_37 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_563 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_577 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_522 ( V_6 ) ) {
V_29 = V_6 -> V_667 . V_777 ;
F_156 ( L_105 , V_29 ) ;
}
V_42 = & V_787 ;
} else {
V_42 = & V_788 ;
}
if ( ! V_45 -> V_781 &&
! F_36 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_563 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_578 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_522 ( V_6 ) ) {
V_29 = V_6 -> V_667 . V_777 ;
F_156 ( L_105 , V_29 ) ;
}
V_42 = & V_789 ;
} else {
V_42 = & V_786 ;
}
if ( ! V_45 -> V_781 &&
! F_34 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_563 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_579 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
int V_29 = 100000 ;
const struct V_41 * V_42 = & V_790 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( ! V_45 -> V_781 &&
! F_43 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_546 ( V_50 , V_45 ) ;
return 0 ;
}
static int F_580 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
int V_29 = 100000 ;
const struct V_41 * V_42 = & V_791 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
if ( ! V_45 -> V_781 &&
! F_41 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_545 ( V_50 , V_45 ) ;
return 0 ;
}
static void F_581 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_2 V_164 ;
if ( F_53 ( V_6 ) <= 3 &&
( F_136 ( V_6 ) || ! F_135 ( V_6 ) ) )
return;
V_164 = F_17 ( V_592 ) ;
if ( ! ( V_164 & V_593 ) )
return;
if ( F_53 ( V_6 ) < 4 ) {
if ( V_50 -> V_79 != V_105 )
return;
} else {
if ( ( V_164 & V_792 ) != ( V_50 -> V_79 << V_793 ) )
return;
}
V_23 -> V_590 . V_591 = V_164 ;
V_23 -> V_590 . V_595 = F_17 ( V_594 ) ;
}
static void F_582 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
struct V_30 clock ;
T_1 V_684 ;
int V_29 = 100000 ;
if ( ( V_23 -> V_159 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_684 = F_128 ( V_6 , V_79 , F_548 ( V_79 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_39 = ( V_684 >> V_693 ) & 7 ;
clock . V_32 = V_684 & V_694 ;
clock . V_36 = ( V_684 >> V_697 ) & 0xf ;
clock . V_34 = ( V_684 >> V_695 ) & 7 ;
clock . V_35 = ( V_684 >> V_696 ) & 0x1f ;
V_23 -> V_24 = F_24 ( V_29 , & clock ) ;
}
static void
F_583 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_261 ;
int V_79 = V_50 -> V_79 , V_118 = V_50 -> V_118 ;
int V_794 , V_314 ;
unsigned int V_795 ;
struct V_213 * V_74 ;
struct V_251 * V_252 ;
V_15 = F_17 ( F_83 ( V_118 ) ) ;
if ( ! ( V_15 & V_119 ) )
return;
V_252 = F_504 ( sizeof( * V_252 ) , V_627 ) ;
if ( ! V_252 ) {
F_156 ( L_107 ) ;
return;
}
V_74 = & V_252 -> V_49 ;
V_74 -> V_48 = V_48 ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_15 & V_355 ) {
V_303 -> V_312 = V_266 ;
V_74 -> V_216 = V_218 ;
}
}
V_314 = V_15 & V_796 ;
V_794 = F_215 ( V_314 ) ;
V_74 -> V_215 = F_584 ( V_794 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_303 -> V_312 )
V_261 = F_17 ( F_266 ( V_118 ) ) ;
else
V_261 = F_17 ( F_267 ( V_118 ) ) ;
V_49 = F_17 ( F_264 ( V_118 ) ) & 0xfffff000 ;
} else {
V_49 = F_17 ( F_268 ( V_118 ) ) ;
}
V_303 -> V_49 = V_49 ;
V_15 = F_17 ( F_328 ( V_79 ) ) ;
V_74 -> V_228 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_224 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_17 ( F_263 ( V_79 ) ) ;
V_74 -> V_247 [ 0 ] = V_15 & 0xffffffc0 ;
V_795 = F_170 ( V_74 , 0 , V_74 -> V_224 ) ;
V_303 -> V_227 = V_74 -> V_247 [ 0 ] * V_795 ;
F_156 ( L_108 ,
F_73 ( V_79 ) , V_118 , V_74 -> V_228 , V_74 -> V_224 ,
V_74 -> V_215 -> V_214 [ 0 ] * 8 , V_49 , V_74 -> V_247 [ 0 ] ,
V_303 -> V_227 ) ;
V_303 -> V_74 = V_252 ;
}
static void F_585 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
enum V_162 V_163 = F_127 ( V_79 ) ;
struct V_30 clock ;
T_1 V_797 , V_798 , V_799 , V_800 , V_801 ;
int V_29 = 100000 ;
if ( ( V_23 -> V_159 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_797 = F_128 ( V_6 , V_79 , F_553 ( V_163 ) ) ;
V_798 = F_128 ( V_6 , V_79 , F_554 ( V_163 ) ) ;
V_799 = F_128 ( V_6 , V_79 , F_555 ( V_163 ) ) ;
V_800 = F_128 ( V_6 , V_79 , F_556 ( V_163 ) ) ;
V_801 = F_128 ( V_6 , V_79 , F_557 ( V_163 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_39 = ( V_799 & 0x7 ) == V_711 ? 2 : 0 ;
clock . V_32 = ( V_798 & 0xff ) << 22 ;
if ( V_801 & V_714 )
clock . V_32 |= V_800 & 0x3fffff ;
clock . V_36 = ( V_799 >> V_712 ) & 0xf ;
clock . V_34 = ( V_797 >> V_708 ) & 0x7 ;
clock . V_35 = ( V_797 >> V_709 ) & 0x1f ;
V_23 -> V_24 = F_25 ( V_29 , & clock ) ;
}
static bool F_586 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_112 V_113 ;
T_2 V_164 ;
bool V_349 ;
V_113 = F_468 ( V_50 -> V_79 ) ;
if ( ! F_80 ( V_6 , V_113 ) )
return false ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_23 -> V_191 = NULL ;
V_349 = false ;
V_164 = F_17 ( F_54 ( V_50 -> V_79 ) ) ;
if ( ! ( V_164 & V_117 ) )
goto V_802;
if ( F_249 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) {
switch ( V_164 & V_193 ) {
case V_769 :
V_23 -> V_635 = 18 ;
break;
case V_195 :
V_23 -> V_635 = 24 ;
break;
case V_770 :
V_23 -> V_635 = 30 ;
break;
default:
break;
}
}
if ( ( F_11 ( V_6 ) || F_12 ( V_6 ) ) &&
( V_164 & V_776 ) )
V_23 -> V_775 = true ;
if ( F_53 ( V_6 ) < 4 )
V_23 -> V_211 = V_164 & V_212 ;
F_568 ( V_50 , V_23 ) ;
F_569 ( V_50 , V_23 ) ;
F_581 ( V_50 , V_23 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( F_12 ( V_6 ) && V_50 -> V_79 != V_98 )
V_164 = V_6 -> V_169 [ V_50 -> V_79 ] ;
else
V_164 = F_17 ( F_125 ( V_50 -> V_79 ) ) ;
V_23 -> V_585 =
( ( V_164 & V_803 )
>> V_683 ) + 1 ;
V_23 -> V_159 . V_161 = V_164 ;
} else if ( F_564 ( V_6 ) || F_565 ( V_6 ) ||
F_566 ( V_6 ) || F_29 ( V_6 ) ) {
V_164 = F_17 ( F_58 ( V_50 -> V_79 ) ) ;
V_23 -> V_585 =
( ( V_164 & V_804 )
>> V_727 ) + 1 ;
} else {
V_23 -> V_585 = 1 ;
}
V_23 -> V_159 . V_30 = F_17 ( F_58 ( V_50 -> V_79 ) ) ;
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) ) {
if ( F_136 ( V_6 ) )
V_23 -> V_159 . V_30 &= ~ V_173 ;
V_23 -> V_159 . V_616 = F_17 ( F_483 ( V_50 -> V_79 ) ) ;
V_23 -> V_159 . V_617 = F_17 ( F_484 ( V_50 -> V_79 ) ) ;
} else {
V_23 -> V_159 . V_30 &= ~ ( V_160 |
V_186 |
V_184 ) ;
}
if ( F_12 ( V_6 ) )
F_585 ( V_50 , V_23 ) ;
else if ( F_11 ( V_6 ) )
F_582 ( V_50 , V_23 ) ;
else
F_587 ( V_50 , V_23 ) ;
V_23 -> V_49 . V_76 . V_77 =
V_23 -> V_24 / V_23 -> V_585 ;
V_349 = true ;
V_802:
F_81 ( V_6 , V_113 ) ;
return V_349 ;
}
static void F_588 ( struct V_5 * V_6 )
{
struct V_509 * V_510 ;
int V_120 ;
T_1 V_15 , V_805 ;
bool V_806 = false ;
bool V_807 = false ;
bool V_808 = false ;
bool V_809 = false ;
bool V_810 = false ;
bool V_811 = false ;
F_589 (&dev_priv->drm, encoder) {
switch ( V_510 -> type ) {
case V_51 :
V_808 = true ;
V_806 = true ;
break;
case V_512 :
V_808 = true ;
if ( F_385 ( & V_510 -> V_49 ) -> V_163 == V_596 )
V_807 = true ;
break;
default:
break;
}
}
if ( F_115 ( V_6 ) ) {
V_809 = V_6 -> V_667 . V_812 ;
V_810 = V_809 ;
} else {
V_809 = false ;
V_810 = true ;
}
for ( V_120 = 0 ; V_120 < V_6 -> V_813 ; V_120 ++ ) {
T_1 V_442 = F_17 ( F_590 ( V_120 ) ) ;
if ( ! ( V_442 & V_88 ) )
continue;
if ( ( V_442 & V_814 ) ==
V_739 ) {
V_811 = true ;
break;
}
}
F_156 ( L_109 ,
V_808 , V_806 , V_809 , V_811 ) ;
V_15 = F_17 ( V_815 ) ;
V_805 = V_15 ;
V_805 &= ~ V_816 ;
if ( V_809 )
V_805 |= V_817 ;
else
V_805 |= V_818 ;
V_805 &= ~ V_819 ;
V_805 &= ~ V_820 ;
V_805 &= ~ V_821 ;
if ( V_808 ) {
V_805 |= V_822 ;
if ( F_522 ( V_6 ) && V_810 )
V_805 |= V_821 ;
if ( V_807 ) {
if ( F_522 ( V_6 ) && V_810 )
V_805 |= V_823 ;
else
V_805 |= V_824 ;
} else
V_805 |= V_825 ;
} else if ( V_811 ) {
V_805 |= V_822 ;
V_805 |= V_821 ;
}
if ( V_805 == V_15 )
return;
V_15 &= ~ V_816 ;
if ( V_809 )
V_15 |= V_817 ;
else
V_15 |= V_818 ;
if ( V_808 ) {
V_15 &= ~ V_819 ;
V_15 |= V_822 ;
if ( F_522 ( V_6 ) && V_810 ) {
F_156 ( L_110 ) ;
V_15 |= V_821 ;
} else
V_15 &= ~ V_821 ;
F_119 ( V_815 , V_15 ) ;
F_120 ( V_815 ) ;
F_121 ( 200 ) ;
V_15 &= ~ V_820 ;
if ( V_807 ) {
if ( F_522 ( V_6 ) && V_810 ) {
F_156 ( L_111 ) ;
V_15 |= V_823 ;
} else
V_15 |= V_824 ;
} else
V_15 |= V_825 ;
F_119 ( V_815 , V_15 ) ;
F_120 ( V_815 ) ;
F_121 ( 200 ) ;
} else {
F_156 ( L_112 ) ;
V_15 &= ~ V_820 ;
V_15 |= V_825 ;
F_119 ( V_815 , V_15 ) ;
F_120 ( V_815 ) ;
F_121 ( 200 ) ;
if ( ! V_811 ) {
F_156 ( L_113 ) ;
V_15 &= ~ V_819 ;
V_15 |= V_826 ;
V_15 &= ~ V_821 ;
F_119 ( V_815 , V_15 ) ;
F_120 ( V_815 ) ;
F_121 ( 200 ) ;
}
}
F_591 ( V_15 != V_805 ) ;
}
static void F_592 ( struct V_5 * V_6 )
{
T_2 V_164 ;
V_164 = F_17 ( V_827 ) ;
V_164 |= V_828 ;
F_119 ( V_827 , V_164 ) ;
if ( F_593 ( F_17 ( V_827 ) &
V_829 , 100 ) )
F_122 ( L_114 ) ;
V_164 = F_17 ( V_827 ) ;
V_164 &= ~ V_828 ;
F_119 ( V_827 , V_164 ) ;
if ( F_593 ( ( F_17 ( V_827 ) &
V_829 ) == 0 , 100 ) )
F_122 ( L_115 ) ;
}
static void F_594 ( struct V_5 * V_6 )
{
T_2 V_164 ;
V_164 = F_358 ( V_6 , 0x8008 , V_830 ) ;
V_164 &= ~ ( 0xFF << 24 ) ;
V_164 |= ( 0x12 << 24 ) ;
F_359 ( V_6 , 0x8008 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2008 , V_830 ) ;
V_164 |= ( 1 << 11 ) ;
F_359 ( V_6 , 0x2008 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2108 , V_830 ) ;
V_164 |= ( 1 << 11 ) ;
F_359 ( V_6 , 0x2108 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x206C , V_830 ) ;
V_164 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_359 ( V_6 , 0x206C , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x216C , V_830 ) ;
V_164 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_359 ( V_6 , 0x216C , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2080 , V_830 ) ;
V_164 &= ~ ( 7 << 13 ) ;
V_164 |= ( 5 << 13 ) ;
F_359 ( V_6 , 0x2080 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2180 , V_830 ) ;
V_164 &= ~ ( 7 << 13 ) ;
V_164 |= ( 5 << 13 ) ;
F_359 ( V_6 , 0x2180 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x208C , V_830 ) ;
V_164 &= ~ 0xFF ;
V_164 |= 0x1C ;
F_359 ( V_6 , 0x208C , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x218C , V_830 ) ;
V_164 &= ~ 0xFF ;
V_164 |= 0x1C ;
F_359 ( V_6 , 0x218C , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2098 , V_830 ) ;
V_164 &= ~ ( 0xFF << 16 ) ;
V_164 |= ( 0x1C << 16 ) ;
F_359 ( V_6 , 0x2098 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x2198 , V_830 ) ;
V_164 &= ~ ( 0xFF << 16 ) ;
V_164 |= ( 0x1C << 16 ) ;
F_359 ( V_6 , 0x2198 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x20C4 , V_830 ) ;
V_164 |= ( 1 << 27 ) ;
F_359 ( V_6 , 0x20C4 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x21C4 , V_830 ) ;
V_164 |= ( 1 << 27 ) ;
F_359 ( V_6 , 0x21C4 , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x20EC , V_830 ) ;
V_164 &= ~ ( 0xF << 28 ) ;
V_164 |= ( 4 << 28 ) ;
F_359 ( V_6 , 0x20EC , V_164 , V_830 ) ;
V_164 = F_358 ( V_6 , 0x21EC , V_830 ) ;
V_164 &= ~ ( 0xF << 28 ) ;
V_164 |= ( 4 << 28 ) ;
F_359 ( V_6 , 0x21EC , V_164 , V_830 ) ;
}
static void F_595 ( struct V_5 * V_6 ,
bool V_831 , bool V_832 )
{
T_2 V_13 , V_164 ;
if ( F_7 ( V_832 && ! V_831 , L_116 ) )
V_831 = true ;
if ( F_7 ( F_596 ( V_6 ) &&
V_832 , L_117 ) )
V_832 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_164 = F_358 ( V_6 , V_833 , V_485 ) ;
V_164 &= ~ V_486 ;
V_164 |= V_834 ;
F_359 ( V_6 , V_833 , V_164 , V_485 ) ;
F_121 ( 24 ) ;
if ( V_831 ) {
V_164 = F_358 ( V_6 , V_833 , V_485 ) ;
V_164 &= ~ V_834 ;
F_359 ( V_6 , V_833 , V_164 , V_485 ) ;
if ( V_832 ) {
F_592 ( V_6 ) ;
F_594 ( V_6 ) ;
}
}
V_13 = F_596 ( V_6 ) ? V_835 : V_836 ;
V_164 = F_358 ( V_6 , V_13 , V_485 ) ;
V_164 |= V_837 ;
F_359 ( V_6 , V_13 , V_164 , V_485 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_597 ( struct V_5 * V_6 )
{
T_2 V_13 , V_164 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_596 ( V_6 ) ? V_835 : V_836 ;
V_164 = F_358 ( V_6 , V_13 , V_485 ) ;
V_164 &= ~ V_837 ;
F_359 ( V_6 , V_13 , V_164 , V_485 ) ;
V_164 = F_358 ( V_6 , V_833 , V_485 ) ;
if ( ! ( V_164 & V_486 ) ) {
if ( ! ( V_164 & V_834 ) ) {
V_164 |= V_834 ;
F_359 ( V_6 , V_833 , V_164 , V_485 ) ;
F_121 ( 32 ) ;
}
V_164 |= V_486 ;
F_359 ( V_6 , V_833 , V_164 , V_485 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_598 ( struct V_5 * V_6 , int V_838 )
{
T_2 V_164 ;
int V_839 = F_599 ( V_838 ) ;
if ( F_21 ( V_838 % 5 != 0 ) )
return;
if ( F_21 ( V_839 >= F_173 ( V_840 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_838 % 10 != 0 )
V_164 = 0xAAAAAAAB ;
else
V_164 = 0x00000000 ;
F_359 ( V_6 , V_841 , V_164 , V_485 ) ;
V_164 = F_358 ( V_6 , V_842 , V_485 ) ;
V_164 &= 0xffff0000 ;
V_164 |= V_840 [ V_839 ] ;
F_359 ( V_6 , V_842 , V_164 , V_485 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_600 ( struct V_5 * V_6 )
{
struct V_509 * V_510 ;
bool V_843 = false ;
F_589 (&dev_priv->drm, encoder) {
switch ( V_510 -> type ) {
case V_702 :
V_843 = true ;
break;
default:
break;
}
}
if ( V_843 ) {
F_598 ( V_6 , 0 ) ;
F_595 ( V_6 , true , true ) ;
} else {
F_597 ( V_6 ) ;
}
}
void F_601 ( struct V_5 * V_6 )
{
if ( F_115 ( V_6 ) || F_101 ( V_6 ) )
F_588 ( V_6 ) ;
else if ( F_154 ( V_6 ) )
F_600 ( V_6 ) ;
}
static void F_444 ( struct V_130 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_66 -> V_75 -> V_635 ) {
case 18 :
V_15 |= V_769 ;
break;
case 24 :
V_15 |= V_195 ;
break;
case 30 :
V_15 |= V_770 ;
break;
case 36 :
V_15 |= V_844 ;
break;
default:
F_141 () ;
}
if ( V_66 -> V_75 -> V_766 )
V_15 |= ( V_767 | V_768 ) ;
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_746 )
V_15 |= V_198 ;
else
V_15 |= V_774 ;
if ( V_66 -> V_75 -> V_775 )
V_15 |= V_776 ;
F_119 ( F_54 ( V_79 ) , V_15 ) ;
F_120 ( F_54 ( V_79 ) ) ;
}
static void F_452 ( struct V_130 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
T_1 V_15 = 0 ;
if ( F_252 ( V_6 ) && V_66 -> V_75 -> V_766 )
V_15 |= ( V_767 | V_768 ) ;
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_746 )
V_15 |= V_198 ;
else
V_15 |= V_774 ;
F_119 ( F_54 ( V_80 ) , V_15 ) ;
F_120 ( F_54 ( V_80 ) ) ;
}
static void F_453 ( struct V_130 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
if ( F_253 ( V_6 ) || F_178 ( V_6 ) -> V_235 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_66 -> V_75 -> V_635 ) {
case 18 :
V_15 |= V_845 ;
break;
case 24 :
V_15 |= V_846 ;
break;
case 30 :
V_15 |= V_847 ;
break;
case 36 :
V_15 |= V_848 ;
break;
default:
F_141 () ;
}
if ( V_66 -> V_75 -> V_766 )
V_15 |= V_849 | V_850 ;
F_119 ( F_602 ( V_66 -> V_79 ) , V_15 ) ;
}
}
int F_509 ( int V_70 , int V_632 , int V_851 )
{
T_1 V_852 = V_70 * V_851 * 21 / 20 ;
return F_213 ( V_852 , V_632 * 8 ) ;
}
static bool F_603 ( struct V_30 * V_30 , int V_853 )
{
return F_22 ( V_30 ) < V_853 * V_30 -> V_36 ;
}
static void F_604 ( struct V_66 * V_66 ,
struct V_22 * V_45 ,
struct V_30 * V_670 )
{
struct V_130 * V_50 = & V_66 -> V_49 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 , V_671 , V_672 ;
int V_853 ;
V_853 = 21 ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( ( F_522 ( V_6 ) &&
V_6 -> V_667 . V_777 == 100000 ) ||
( F_115 ( V_6 ) && F_33 ( V_48 ) ) )
V_853 = 25 ;
} else if ( V_45 -> V_737 )
V_853 = 20 ;
V_671 = F_524 ( & V_45 -> V_30 ) ;
if ( F_603 ( & V_45 -> V_30 , V_853 ) )
V_671 |= V_854 ;
if ( V_670 ) {
V_672 = F_524 ( V_670 ) ;
if ( V_670 -> V_31 < V_853 * V_670 -> V_36 )
V_672 |= V_854 ;
} else {
V_672 = V_671 ;
}
V_30 = 0 ;
if ( F_32 ( V_45 , V_51 ) )
V_30 |= V_725 ;
else
V_30 |= V_726 ;
V_30 |= ( V_45 -> V_585 - 1 )
<< V_855 ;
if ( F_32 ( V_45 , V_199 ) ||
F_32 ( V_45 , V_194 ) )
V_30 |= V_728 ;
if ( F_393 ( V_45 ) )
V_30 |= V_728 ;
if ( F_178 ( V_6 ) -> V_630 == 3 &&
F_32 ( V_45 , V_702 ) )
V_30 |= V_728 ;
V_30 |= ( 1 << ( V_45 -> V_30 . V_34 - 1 ) ) << V_730 ;
V_30 |= ( 1 << ( V_45 -> V_30 . V_34 - 1 ) ) << V_731 ;
switch ( V_45 -> V_30 . V_35 ) {
case 5 :
V_30 |= V_732 ;
break;
case 7 :
V_30 |= V_733 ;
break;
case 10 :
V_30 |= V_734 ;
break;
case 14 :
V_30 |= V_735 ;
break;
}
if ( F_32 ( V_45 , V_51 ) &&
F_522 ( V_6 ) )
V_30 |= V_739 ;
else
V_30 |= V_740 ;
V_30 |= V_88 ;
V_45 -> V_159 . V_30 = V_30 ;
V_45 -> V_159 . V_616 = V_671 ;
V_45 -> V_159 . V_617 = V_672 ;
}
static int F_605 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_30 V_670 ;
bool V_856 = false ;
struct V_857 * V_858 ;
const struct V_41 * V_42 ;
int V_29 = 120000 ;
memset ( & V_45 -> V_159 , 0 ,
sizeof( V_45 -> V_159 ) ) ;
V_50 -> V_673 = false ;
if ( ! V_45 -> V_207 )
return 0 ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_522 ( V_6 ) ) {
F_156 ( L_105 ,
V_6 -> V_667 . V_777 ) ;
V_29 = V_6 -> V_667 . V_777 ;
}
if ( F_33 ( V_48 ) ) {
if ( V_29 == 100000 )
V_42 = & V_859 ;
else
V_42 = & V_860 ;
} else {
if ( V_29 == 100000 )
V_42 = & V_861 ;
else
V_42 = & V_862 ;
}
} else {
V_42 = & V_863 ;
}
if ( ! V_45 -> V_781 &&
! F_37 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_122 ( L_106 ) ;
return - V_272 ;
}
F_604 ( V_50 , V_45 ,
V_856 ? & V_670 : NULL ) ;
V_858 = F_606 ( V_50 , V_45 , NULL ) ;
if ( V_858 == NULL ) {
F_13 ( L_118 ,
F_73 ( V_50 -> V_79 ) ) ;
return - V_272 ;
}
if ( F_32 ( V_45 , V_51 ) &&
V_856 )
V_50 -> V_673 = true ;
return 0 ;
}
static void F_607 ( struct V_66 * V_50 ,
struct V_659 * V_660 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
V_660 -> V_664 = F_17 ( F_532 ( V_79 ) ) ;
V_660 -> V_665 = F_17 ( F_533 ( V_79 ) ) ;
V_660 -> V_662 = F_17 ( F_529 ( V_79 ) )
& ~ V_513 ;
V_660 -> V_663 = F_17 ( F_531 ( V_79 ) ) ;
V_660 -> V_661 = ( ( F_17 ( F_529 ( V_79 ) )
& V_513 ) >> V_864 ) + 1 ;
}
static void F_608 ( struct V_66 * V_50 ,
enum V_78 V_78 ,
struct V_659 * V_660 ,
struct V_659 * V_676 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
if ( F_53 ( V_6 ) >= 5 ) {
V_660 -> V_664 = F_17 ( F_535 ( V_78 ) ) ;
V_660 -> V_665 = F_17 ( F_536 ( V_78 ) ) ;
V_660 -> V_662 = F_17 ( F_388 ( V_78 ) )
& ~ V_513 ;
V_660 -> V_663 = F_17 ( F_534 ( V_78 ) ) ;
V_660 -> V_661 = ( ( F_17 ( F_388 ( V_78 ) )
& V_513 ) >> V_864 ) + 1 ;
if ( V_676 && F_53 ( V_6 ) < 8 &&
V_50 -> V_75 -> V_677 ) {
V_676 -> V_664 = F_17 ( F_539 ( V_78 ) ) ;
V_676 -> V_665 = F_17 ( F_540 ( V_78 ) ) ;
V_676 -> V_662 = F_17 ( F_537 ( V_78 ) )
& ~ V_513 ;
V_676 -> V_663 = F_17 ( F_538 ( V_78 ) ) ;
V_676 -> V_661 = ( ( F_17 ( F_537 ( V_78 ) )
& V_513 ) >> V_864 ) + 1 ;
}
} else {
V_660 -> V_664 = F_17 ( F_543 ( V_79 ) ) ;
V_660 -> V_665 = F_17 ( F_544 ( V_79 ) ) ;
V_660 -> V_662 = F_17 ( F_541 ( V_79 ) )
& ~ V_513 ;
V_660 -> V_663 = F_17 ( F_542 ( V_79 ) ) ;
V_660 -> V_661 = ( ( F_17 ( F_541 ( V_79 ) )
& V_513 ) >> V_864 ) + 1 ;
}
}
void F_609 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_207 )
F_607 ( V_50 , & V_23 -> V_679 ) ;
else
F_608 ( V_50 , V_23 -> V_80 ,
& V_23 -> V_679 ,
& V_23 -> V_680 ) ;
}
static void F_610 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
F_608 ( V_50 , V_23 -> V_80 ,
& V_23 -> V_582 , NULL ) ;
}
static void F_611 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_370 * V_371 = & V_23 -> V_371 ;
T_2 V_415 = 0 ;
int V_324 = - 1 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_50 -> V_372 ; V_120 ++ ) {
V_415 = F_17 ( F_274 ( V_50 -> V_79 , V_120 ) ) ;
if ( V_415 & V_416 && ! ( V_415 & V_865 ) ) {
V_324 = V_120 ;
V_23 -> V_441 . V_131 = true ;
V_23 -> V_441 . V_545 = F_17 ( F_275 ( V_50 -> V_79 , V_120 ) ) ;
V_23 -> V_441 . V_227 = F_17 ( F_276 ( V_50 -> V_79 , V_120 ) ) ;
break;
}
}
V_371 -> V_407 = V_324 ;
if ( V_324 >= 0 ) {
V_371 -> V_531 |= ( 1 << V_540 ) ;
} else {
V_371 -> V_531 &= ~ ( 1 << V_540 ) ;
}
}
static void
F_612 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_261 , V_866 , V_312 ;
int V_79 = V_50 -> V_79 ;
int V_794 , V_314 ;
unsigned int V_795 ;
struct V_213 * V_74 ;
struct V_251 * V_252 ;
V_252 = F_504 ( sizeof( * V_252 ) , V_627 ) ;
if ( ! V_252 ) {
F_156 ( L_107 ) ;
return;
}
V_74 = & V_252 -> V_49 ;
V_74 -> V_48 = V_48 ;
V_15 = F_17 ( F_89 ( V_79 , 0 ) ) ;
if ( ! ( V_15 & V_125 ) )
goto error;
V_314 = V_15 & V_867 ;
V_794 = F_216 ( V_314 ,
V_15 & V_376 ,
V_15 & V_868 ) ;
V_74 -> V_215 = F_584 ( V_794 ) ;
V_312 = V_15 & V_869 ;
switch ( V_312 ) {
case V_870 :
V_74 -> V_216 = V_217 ;
break;
case V_387 :
V_303 -> V_312 = V_266 ;
V_74 -> V_216 = V_218 ;
break;
case V_388 :
V_74 -> V_216 = V_219 ;
break;
case V_389 :
V_74 -> V_216 = V_220 ;
break;
default:
F_167 ( V_312 ) ;
goto error;
}
V_49 = F_17 ( F_292 ( V_79 , 0 ) ) & 0xfffff000 ;
V_303 -> V_49 = V_49 ;
V_261 = F_17 ( F_286 ( V_79 , 0 ) ) ;
V_15 = F_17 ( F_288 ( V_79 , 0 ) ) ;
V_74 -> V_224 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_228 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_17 ( F_287 ( V_79 , 0 ) ) ;
V_866 = F_272 ( V_74 , 0 ) ;
V_74 -> V_247 [ 0 ] = ( V_15 & 0x3ff ) * V_866 ;
V_795 = F_170 ( V_74 , 0 , V_74 -> V_224 ) ;
V_303 -> V_227 = V_74 -> V_247 [ 0 ] * V_795 ;
F_156 ( L_119 ,
F_73 ( V_79 ) , V_74 -> V_228 , V_74 -> V_224 ,
V_74 -> V_215 -> V_214 [ 0 ] * 8 , V_49 , V_74 -> V_247 [ 0 ] ,
V_303 -> V_227 ) ;
V_303 -> V_74 = V_252 ;
return;
error:
F_232 ( V_252 ) ;
}
static void F_613 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_2 V_164 ;
V_164 = F_17 ( F_400 ( V_50 -> V_79 ) ) ;
if ( V_164 & V_546 ) {
V_23 -> V_441 . V_131 = true ;
V_23 -> V_441 . V_545 = F_17 ( F_402 ( V_50 -> V_79 ) ) ;
V_23 -> V_441 . V_227 = F_17 ( F_403 ( V_50 -> V_79 ) ) ;
if ( F_614 ( V_6 ) ) {
F_21 ( ( V_164 & V_871 ) !=
F_401 ( V_50 -> V_79 ) ) ;
}
}
}
static void
F_615 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_261 ;
int V_79 = V_50 -> V_79 ;
int V_794 , V_314 ;
unsigned int V_795 ;
struct V_213 * V_74 ;
struct V_251 * V_252 ;
V_15 = F_17 ( F_83 ( V_79 ) ) ;
if ( ! ( V_15 & V_119 ) )
return;
V_252 = F_504 ( sizeof( * V_252 ) , V_627 ) ;
if ( ! V_252 ) {
F_156 ( L_107 ) ;
return;
}
V_74 = & V_252 -> V_49 ;
V_74 -> V_48 = V_48 ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_15 & V_355 ) {
V_303 -> V_312 = V_266 ;
V_74 -> V_216 = V_218 ;
}
}
V_314 = V_15 & V_796 ;
V_794 = F_215 ( V_314 ) ;
V_74 -> V_215 = F_584 ( V_794 ) ;
V_49 = F_17 ( F_264 ( V_79 ) ) & 0xfffff000 ;
if ( F_252 ( V_6 ) || F_253 ( V_6 ) ) {
V_261 = F_17 ( F_265 ( V_79 ) ) ;
} else {
if ( V_303 -> V_312 )
V_261 = F_17 ( F_266 ( V_79 ) ) ;
else
V_261 = F_17 ( F_267 ( V_79 ) ) ;
}
V_303 -> V_49 = V_49 ;
V_15 = F_17 ( F_328 ( V_79 ) ) ;
V_74 -> V_228 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_224 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_17 ( F_263 ( V_79 ) ) ;
V_74 -> V_247 [ 0 ] = V_15 & 0xffffffc0 ;
V_795 = F_170 ( V_74 , 0 , V_74 -> V_224 ) ;
V_303 -> V_227 = V_74 -> V_247 [ 0 ] * V_795 ;
F_156 ( L_119 ,
F_73 ( V_79 ) , V_74 -> V_228 , V_74 -> V_224 ,
V_74 -> V_215 -> V_214 [ 0 ] * 8 , V_49 , V_74 -> V_247 [ 0 ] ,
V_303 -> V_227 ) ;
V_303 -> V_74 = V_252 ;
}
static bool F_616 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
T_2 V_164 ;
bool V_349 ;
V_113 = F_468 ( V_50 -> V_79 ) ;
if ( ! F_80 ( V_6 , V_113 ) )
return false ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_23 -> V_191 = NULL ;
V_349 = false ;
V_164 = F_17 ( F_54 ( V_50 -> V_79 ) ) ;
if ( ! ( V_164 & V_117 ) )
goto V_802;
switch ( V_164 & V_193 ) {
case V_769 :
V_23 -> V_635 = 18 ;
break;
case V_195 :
V_23 -> V_635 = 24 ;
break;
case V_770 :
V_23 -> V_635 = 30 ;
break;
case V_844 :
V_23 -> V_635 = 36 ;
break;
default:
break;
}
if ( V_164 & V_776 )
V_23 -> V_775 = true ;
if ( F_17 ( F_99 ( V_50 -> V_79 ) ) & V_132 ) {
struct V_857 * V_858 ;
enum V_872 V_873 ;
V_23 -> V_207 = true ;
V_164 = F_17 ( F_66 ( V_50 -> V_79 ) ) ;
V_23 -> V_455 = ( ( V_454 & V_164 ) >>
V_874 ) + 1 ;
F_610 ( V_50 , V_23 ) ;
if ( F_115 ( V_6 ) ) {
V_873 = (enum V_872 ) V_50 -> V_79 ;
} else {
V_164 = F_17 ( V_516 ) ;
if ( V_164 & F_390 ( V_50 -> V_79 ) )
V_873 = V_517 ;
else
V_873 = V_875 ;
}
V_23 -> V_191 =
F_391 ( V_6 , V_873 ) ;
V_858 = V_23 -> V_191 ;
F_21 ( ! V_858 -> V_876 . V_625 ( V_6 , V_858 ,
& V_23 -> V_159 ) ) ;
V_164 = V_23 -> V_159 . V_30 ;
V_23 -> V_585 =
( ( V_164 & V_877 )
>> V_855 ) + 1 ;
F_617 ( V_50 , V_23 ) ;
} else {
V_23 -> V_585 = 1 ;
}
F_568 ( V_50 , V_23 ) ;
F_569 ( V_50 , V_23 ) ;
F_613 ( V_50 , V_23 ) ;
V_349 = true ;
V_802:
F_81 ( V_6 , V_113 ) ;
return V_349 ;
}
static void F_618 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_66 * V_50 ;
F_133 (dev, crtc)
F_59 ( V_50 -> V_72 , L_120 ,
F_73 ( V_50 -> V_79 ) ) ;
F_59 ( F_17 ( V_878 ) , L_121 ) ;
F_59 ( F_17 ( V_879 ) & V_880 , L_122 ) ;
F_59 ( F_17 ( F_619 ( 0 ) ) & V_881 , L_123 ) ;
F_59 ( F_17 ( F_619 ( 1 ) ) & V_881 , L_124 ) ;
F_59 ( F_17 ( F_620 ( 0 ) ) & V_882 , L_125 ) ;
F_59 ( F_17 ( V_883 ) & V_884 ,
L_126 ) ;
if ( F_252 ( V_6 ) )
F_59 ( F_17 ( V_885 ) & V_884 ,
L_127 ) ;
F_59 ( F_17 ( V_886 ) & V_887 ,
L_128 ) ;
F_59 ( F_17 ( V_888 ) & V_889 ,
L_129 ) ;
F_59 ( F_17 ( V_890 ) & V_891 , L_130 ) ;
F_59 ( F_621 ( V_6 ) , L_131 ) ;
}
static T_2 F_622 ( struct V_5 * V_6 )
{
if ( F_252 ( V_6 ) )
return F_17 ( V_892 ) ;
else
return F_17 ( V_893 ) ;
}
static void F_623 ( struct V_5 * V_6 , T_2 V_15 )
{
if ( F_252 ( V_6 ) ) {
F_3 ( & V_6 -> V_549 . V_550 ) ;
if ( F_406 ( V_6 , V_894 ,
V_15 ) )
F_156 ( L_132 ) ;
F_5 ( & V_6 -> V_549 . V_550 ) ;
} else {
F_119 ( V_893 , V_15 ) ;
F_120 ( V_893 ) ;
}
}
static void F_624 ( struct V_5 * V_6 ,
bool V_895 , bool V_896 )
{
T_2 V_15 ;
F_618 ( V_6 ) ;
V_15 = F_17 ( V_897 ) ;
if ( V_895 ) {
V_15 |= V_898 ;
F_119 ( V_897 , V_15 ) ;
if ( F_593 ( F_17 ( V_897 ) &
V_899 , 1 ) )
F_122 ( L_133 ) ;
V_15 = F_17 ( V_897 ) ;
}
V_15 |= V_900 ;
F_119 ( V_897 , V_15 ) ;
F_120 ( V_897 ) ;
if ( F_55 ( V_6 , V_897 , V_901 , 0 , 1 ) )
F_122 ( L_134 ) ;
V_15 = F_622 ( V_6 ) ;
V_15 |= V_902 ;
F_623 ( V_6 , V_15 ) ;
F_625 ( 100 ) ;
if ( F_56 ( ( F_622 ( V_6 ) & V_903 ) == 0 ,
1 ) )
F_122 ( L_135 ) ;
if ( V_896 ) {
V_15 = F_17 ( V_897 ) ;
V_15 |= V_904 ;
F_119 ( V_897 , V_15 ) ;
F_120 ( V_897 ) ;
}
}
static void F_626 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_17 ( V_897 ) ;
if ( ( V_15 & ( V_901 | V_900 | V_898 |
V_904 ) ) == V_901 )
return;
F_627 ( V_6 , V_905 ) ;
if ( V_15 & V_904 ) {
V_15 &= ~ V_904 ;
F_119 ( V_897 , V_15 ) ;
F_120 ( V_897 ) ;
}
V_15 = F_622 ( V_6 ) ;
V_15 |= V_906 ;
V_15 &= ~ V_902 ;
F_623 ( V_6 , V_15 ) ;
V_15 = F_17 ( V_897 ) ;
V_15 &= ~ V_900 ;
F_119 ( V_897 , V_15 ) ;
if ( F_55 ( V_6 ,
V_897 , V_901 , V_901 ,
5 ) )
F_122 ( L_136 ) ;
if ( V_15 & V_898 ) {
V_15 = F_17 ( V_897 ) ;
V_15 &= ~ V_898 ;
F_119 ( V_897 , V_15 ) ;
if ( F_593 ( ( F_17 ( V_897 ) &
V_899 ) == 0 , 1 ) )
F_122 ( L_137 ) ;
}
F_628 ( V_6 , V_905 ) ;
F_629 ( V_6 ) ;
}
void F_630 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_156 ( L_138 ) ;
if ( F_596 ( V_6 ) ) {
V_15 = F_17 ( V_907 ) ;
V_15 &= ~ V_908 ;
F_119 ( V_907 , V_15 ) ;
}
F_597 ( V_6 ) ;
F_624 ( V_6 , true , true ) ;
}
void F_631 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_156 ( L_139 ) ;
F_626 ( V_6 ) ;
F_600 ( V_6 ) ;
if ( F_596 ( V_6 ) ) {
V_15 = F_17 ( V_907 ) ;
V_15 |= V_908 ;
F_119 ( V_907 , V_15 ) ;
}
}
static int F_632 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
if ( ! F_32 ( V_45 , V_208 ) ) {
struct V_509 * V_510 =
F_633 ( V_45 ) ;
if ( ! F_606 ( V_50 , V_45 , V_510 ) ) {
F_13 ( L_118 ,
F_73 ( V_50 -> V_79 ) ) ;
return - V_272 ;
}
}
V_50 -> V_673 = false ;
return 0 ;
}
static void F_634 ( struct V_5 * V_6 ,
enum V_163 V_163 ,
struct V_22 * V_23 )
{
enum V_872 V_324 ;
switch ( V_163 ) {
case V_596 :
V_324 = V_909 ;
break;
case V_183 :
V_324 = V_910 ;
break;
case V_185 :
V_324 = V_911 ;
break;
default:
F_122 ( L_140 ) ;
return;
}
V_23 -> V_191 = F_391 ( V_6 , V_324 ) ;
}
static void F_635 ( struct V_5 * V_6 ,
enum V_163 V_163 ,
struct V_22 * V_23 )
{
enum V_872 V_324 ;
T_1 V_442 ;
V_442 = F_17 ( V_912 ) & F_636 ( V_163 ) ;
V_324 = V_442 >> ( V_163 * 3 + 1 ) ;
if ( F_21 ( V_324 < V_913 || V_324 > V_914 ) )
return;
V_23 -> V_191 = F_391 ( V_6 , V_324 ) ;
}
static void F_637 ( struct V_5 * V_6 ,
enum V_163 V_163 ,
struct V_22 * V_23 )
{
enum V_872 V_324 ;
T_2 V_915 = F_17 ( F_638 ( V_163 ) ) ;
switch ( V_915 ) {
case V_916 :
V_324 = V_917 ;
break;
case V_918 :
V_324 = V_919 ;
break;
case V_920 :
V_324 = V_921 ;
break;
case V_922 :
V_324 = V_923 ;
break;
case V_924 :
V_324 = V_925 ;
break;
case V_926 :
V_324 = V_927 ;
break;
default:
F_167 ( V_915 ) ;
case V_928 :
return;
}
V_23 -> V_191 = F_391 ( V_6 , V_324 ) ;
}
static bool F_639 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
T_4 * V_929 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
T_1 V_164 ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_164 = F_17 ( F_63 ( V_584 ) ) ;
if ( V_164 & V_91 ) {
enum V_79 V_930 ;
switch ( V_164 & V_931 ) {
default:
F_7 ( 1 , L_141 ) ;
case V_932 :
case V_933 :
V_930 = V_98 ;
break;
case V_934 :
V_930 = V_105 ;
break;
case V_935 :
V_930 = V_508 ;
break;
}
if ( V_930 == V_50 -> V_79 )
V_23 -> V_80 = V_584 ;
}
V_113 = F_79 ( V_23 -> V_80 ) ;
if ( ! F_80 ( V_6 , V_113 ) )
return false ;
* V_929 |= F_469 ( V_113 ) ;
V_164 = F_17 ( F_54 ( V_23 -> V_80 ) ) ;
return V_164 & V_117 ;
}
static bool F_640 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
T_4 * V_929 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
enum V_163 V_163 ;
enum V_78 V_80 ;
T_1 V_164 ;
F_641 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_163 == V_596 )
V_80 = V_936 ;
else
V_80 = V_937 ;
V_113 = F_79 ( V_80 ) ;
if ( ! F_80 ( V_6 , V_113 ) )
continue;
* V_929 |= F_469 ( V_113 ) ;
if ( ! F_642 ( V_6 ) )
break;
V_164 = F_17 ( F_643 ( V_163 ) ) ;
if ( ! ( V_164 & V_938 ) )
continue;
V_164 = F_17 ( F_644 ( V_163 ) ) ;
if ( ( V_164 & V_939 ) != F_645 ( V_50 -> V_79 ) )
continue;
V_23 -> V_80 = V_80 ;
break;
}
return F_450 ( V_23 -> V_80 ) ;
}
static void F_646 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_857 * V_858 ;
enum V_163 V_163 ;
T_2 V_164 ;
V_164 = F_17 ( F_63 ( V_23 -> V_80 ) ) ;
V_163 = ( V_164 & V_940 ) >> V_941 ;
if ( F_647 ( V_6 ) )
F_635 ( V_6 , V_163 , V_23 ) ;
else if ( F_30 ( V_6 ) )
F_634 ( V_6 , V_163 , V_23 ) ;
else
F_637 ( V_6 , V_163 , V_23 ) ;
V_858 = V_23 -> V_191 ;
if ( V_858 ) {
F_21 ( ! V_858 -> V_876 . V_625 ( V_6 , V_858 ,
& V_23 -> V_159 ) ) ;
}
if ( F_53 ( V_6 ) < 9 &&
( V_163 == V_601 ) && F_17 ( V_206 ) & V_132 ) {
V_23 -> V_207 = true ;
V_164 = F_17 ( F_66 ( V_98 ) ) ;
V_23 -> V_455 = ( ( V_454 & V_164 ) >>
V_874 ) + 1 ;
F_610 ( V_50 , V_23 ) ;
}
}
static bool F_648 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_112 V_113 ;
T_4 V_929 ;
bool V_72 ;
V_113 = F_468 ( V_50 -> V_79 ) ;
if ( ! F_80 ( V_6 , V_113 ) )
return false ;
V_929 = F_469 ( V_113 ) ;
V_23 -> V_191 = NULL ;
V_72 = F_639 ( V_50 , V_23 , & V_929 ) ;
if ( F_30 ( V_6 ) &&
F_640 ( V_50 , V_23 , & V_929 ) ) {
F_21 ( V_72 ) ;
V_72 = true ;
}
if ( ! V_72 )
goto V_802;
if ( ! F_450 ( V_23 -> V_80 ) ) {
F_646 ( V_50 , V_23 ) ;
F_568 ( V_50 , V_23 ) ;
}
F_569 ( V_50 , V_23 ) ;
V_23 -> V_942 =
F_17 ( F_649 ( V_50 -> V_79 ) ) & V_943 ;
if ( F_53 ( V_6 ) >= 9 ) {
F_650 ( V_50 , V_23 ) ;
V_23 -> V_371 . V_407 = - 1 ;
V_23 -> V_371 . V_531 &= ~ ( 1 << V_540 ) ;
}
V_113 = F_470 ( V_50 -> V_79 ) ;
if ( F_80 ( V_6 , V_113 ) ) {
V_929 |= F_469 ( V_113 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_611 ( V_50 , V_23 ) ;
else
F_613 ( V_50 , V_23 ) ;
}
if ( F_252 ( V_6 ) )
V_23 -> V_548 = F_447 ( V_50 ) &&
( F_17 ( V_552 ) & V_553 ) ;
if ( V_23 -> V_80 != V_584 &&
! F_450 ( V_23 -> V_80 ) ) {
V_23 -> V_585 =
F_17 ( F_451 ( V_23 -> V_80 ) ) + 1 ;
} else {
V_23 -> V_585 = 1 ;
}
V_802:
F_473 (power_domain, power_domain_mask)
F_81 ( V_6 , V_113 ) ;
return V_72 ;
}
static T_1 F_651 ( const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
unsigned int V_228 = V_319 -> V_49 . V_336 ;
unsigned int V_276 = F_652 ( V_228 ) * 4 ;
switch ( V_276 ) {
default:
F_356 ( 1 , L_142 ,
V_228 , V_276 ) ;
V_276 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
return V_110 |
V_944 |
V_945 |
F_653 ( V_276 ) ;
}
static void F_654 ( struct V_130 * V_50 , T_1 V_49 ,
const struct V_250 * V_319 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_2 V_946 = 0 , V_227 = 0 ;
if ( V_319 && V_319 -> V_49 . V_320 ) {
unsigned int V_228 = V_319 -> V_49 . V_336 ;
unsigned int V_224 = V_319 -> V_49 . V_337 ;
V_946 = V_319 -> V_360 ;
V_227 = ( V_224 << 12 ) | V_228 ;
}
if ( V_66 -> V_947 != 0 &&
( V_66 -> V_948 != V_49 ||
V_66 -> V_949 != V_227 ||
V_66 -> V_947 != V_946 ) ) {
F_257 ( F_77 ( V_98 ) , 0 ) ;
F_269 ( F_77 ( V_98 ) ) ;
V_66 -> V_947 = 0 ;
}
if ( V_66 -> V_948 != V_49 ) {
F_257 ( F_655 ( V_98 ) , V_49 ) ;
V_66 -> V_948 = V_49 ;
}
if ( V_66 -> V_949 != V_227 ) {
F_257 ( V_950 , V_227 ) ;
V_66 -> V_949 = V_227 ;
}
if ( V_66 -> V_947 != V_946 ) {
F_257 ( F_77 ( V_98 ) , V_946 ) ;
F_269 ( F_77 ( V_98 ) ) ;
V_66 -> V_947 = V_946 ;
}
}
static T_1 F_656 ( const struct V_22 * V_45 ,
const struct V_250 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_118 -> V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
T_1 V_946 ;
V_946 = V_951 ;
if ( F_15 ( V_6 ) )
V_946 |= V_952 ;
V_946 |= V_79 << 28 ;
switch ( V_319 -> V_49 . V_336 ) {
case 64 :
V_946 |= V_953 ;
break;
case 128 :
V_946 |= V_954 ;
break;
case 256 :
V_946 |= V_955 ;
break;
default:
F_167 ( V_319 -> V_49 . V_336 ) ;
return 0 ;
}
if ( V_319 -> V_49 . V_231 & V_356 )
V_946 |= V_956 ;
return V_946 ;
}
static void F_657 ( struct V_130 * V_50 , T_1 V_49 ,
const struct V_250 * V_319 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_2 V_946 = 0 ;
if ( V_319 && V_319 -> V_49 . V_320 )
V_946 = V_319 -> V_360 ;
if ( V_66 -> V_947 != V_946 ) {
F_257 ( F_77 ( V_79 ) , V_946 ) ;
F_269 ( F_77 ( V_79 ) ) ;
V_66 -> V_947 = V_946 ;
}
F_257 ( F_655 ( V_79 ) , V_49 ) ;
F_269 ( F_655 ( V_79 ) ) ;
V_66 -> V_948 = V_49 ;
}
static void F_658 ( struct V_130 * V_50 ,
const struct V_250 * V_319 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_1 V_49 = V_66 -> V_957 ;
unsigned long V_361 ;
T_1 V_545 = 0 ;
if ( V_319 ) {
int V_248 = V_319 -> V_49 . V_334 ;
int V_249 = V_319 -> V_49 . V_335 ;
if ( V_248 < 0 ) {
V_545 |= V_958 << V_959 ;
V_248 = - V_248 ;
}
V_545 |= V_248 << V_959 ;
if ( V_249 < 0 ) {
V_545 |= V_958 << V_960 ;
V_249 = - V_249 ;
}
V_545 |= V_249 << V_960 ;
if ( F_158 ( V_6 ) &&
V_319 -> V_49 . V_231 & V_356 ) {
V_49 += ( V_319 -> V_49 . V_337 *
V_319 -> V_49 . V_336 - 1 ) * 4 ;
}
}
F_256 ( & V_6 -> V_365 . V_366 , V_361 ) ;
F_257 ( F_659 ( V_79 ) , V_545 ) ;
if ( F_75 ( V_6 ) || F_76 ( V_6 ) )
F_654 ( V_50 , V_49 , V_319 ) ;
else
F_657 ( V_50 , V_49 , V_319 ) ;
F_270 ( & V_6 -> V_365 . V_366 , V_361 ) ;
}
static bool F_660 ( struct V_5 * V_6 ,
T_2 V_228 , T_2 V_224 )
{
if ( V_228 == 0 || V_224 == 0 )
return false ;
if ( F_75 ( V_6 ) || F_76 ( V_6 ) ) {
if ( ( V_228 & 63 ) != 0 )
return false ;
if ( V_228 > ( F_75 ( V_6 ) ? 64 : 512 ) )
return false ;
if ( V_224 > 1023 )
return false ;
} else {
switch ( V_228 | V_224 ) {
case 256 :
case 128 :
if ( F_50 ( V_6 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
struct V_213 *
F_661 ( struct V_238 * V_239 ,
struct V_306 * V_307 )
{
struct V_251 * V_252 ;
int V_349 ;
V_252 = F_504 ( sizeof( * V_252 ) , V_627 ) ;
if ( ! V_252 )
return F_662 ( - V_626 ) ;
V_349 = F_221 ( V_252 , V_239 , V_307 ) ;
if ( V_349 )
goto V_57;
return & V_252 -> V_49 ;
V_57:
F_232 ( V_252 ) ;
return F_662 ( V_349 ) ;
}
static T_1
F_663 ( int V_228 , int V_851 )
{
T_1 V_246 = F_213 ( V_228 * V_851 , 8 ) ;
return F_171 ( V_246 , 64 ) ;
}
static T_1
F_664 ( struct V_518 * V_417 , int V_851 )
{
T_1 V_246 = F_663 ( V_417 -> V_755 , V_851 ) ;
return F_665 ( V_246 * V_417 -> V_754 ) ;
}
static struct V_213 *
F_666 ( struct V_47 * V_48 ,
struct V_518 * V_417 ,
int V_961 , int V_851 )
{
struct V_213 * V_74 ;
struct V_238 * V_239 ;
struct V_306 V_307 = { 0 } ;
V_239 = F_667 ( F_35 ( V_48 ) ,
F_664 ( V_417 , V_851 ) ) ;
if ( F_188 ( V_239 ) )
return F_668 ( V_239 ) ;
V_307 . V_228 = V_417 -> V_755 ;
V_307 . V_224 = V_417 -> V_754 ;
V_307 . V_247 [ 0 ] = F_663 ( V_307 . V_228 ,
V_851 ) ;
V_307 . V_314 = F_669 ( V_851 , V_961 ) ;
V_74 = F_661 ( V_239 , & V_307 ) ;
if ( F_188 ( V_74 ) )
F_222 ( V_239 ) ;
return V_74 ;
}
static struct V_213 *
F_670 ( struct V_47 * V_48 ,
struct V_518 * V_417 )
{
#ifdef F_671
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_238 * V_239 ;
struct V_213 * V_74 ;
if ( ! V_6 -> V_962 )
return NULL ;
if ( ! V_6 -> V_962 -> V_74 )
return NULL ;
V_239 = V_6 -> V_962 -> V_74 -> V_239 ;
F_591 ( ! V_239 ) ;
V_74 = & V_6 -> V_962 -> V_74 -> V_49 ;
if ( V_74 -> V_247 [ 0 ] < F_663 ( V_417 -> V_755 ,
V_74 -> V_215 -> V_214 [ 0 ] * 8 ) )
return NULL ;
if ( V_239 -> V_49 . V_227 < V_417 -> V_754 * V_74 -> V_247 [ 0 ] )
return NULL ;
F_225 ( V_74 ) ;
return V_74 ;
#else
return NULL ;
#endif
}
static int F_672 ( struct V_419 * V_28 ,
struct V_130 * V_50 ,
struct V_518 * V_417 ,
struct V_213 * V_74 ,
int V_248 , int V_249 )
{
struct V_326 * V_319 ;
int V_755 , V_754 ;
int V_349 ;
V_319 = F_673 ( V_28 , V_50 -> V_73 ) ;
if ( F_188 ( V_319 ) )
return F_238 ( V_319 ) ;
if ( V_417 )
F_674 ( V_417 , & V_755 , & V_754 ) ;
else
V_755 = V_754 = 0 ;
V_349 = F_675 ( V_319 , V_74 ? V_50 : NULL ) ;
if ( V_349 )
return V_349 ;
F_676 ( V_319 , V_74 ) ;
V_319 -> V_334 = 0 ;
V_319 -> V_335 = 0 ;
V_319 -> V_336 = V_755 ;
V_319 -> V_337 = V_754 ;
V_319 -> V_330 = V_248 << 16 ;
V_319 -> V_331 = V_249 << 16 ;
V_319 -> V_332 = V_755 << 16 ;
V_319 -> V_333 = V_754 << 16 ;
return 0 ;
}
int F_677 ( struct V_572 * V_624 ,
struct V_518 * V_417 ,
struct V_963 * V_964 ,
struct V_420 * V_421 )
{
struct V_66 * V_66 ;
struct V_509 * V_509 =
F_678 ( V_624 ) ;
struct V_130 * V_965 ;
struct V_604 * V_510 = & V_509 -> V_49 ;
struct V_130 * V_50 = NULL ;
struct V_47 * V_48 = V_510 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_213 * V_74 ;
struct V_966 * V_75 = & V_48 -> V_426 ;
struct V_419 * V_28 = NULL , * V_967 = NULL ;
struct V_570 * V_968 ;
struct V_22 * V_45 ;
int V_349 , V_120 = - 1 ;
F_156 ( L_143 ,
V_624 -> V_49 . V_324 , V_624 -> V_12 ,
V_510 -> V_49 . V_324 , V_510 -> V_12 ) ;
V_964 -> V_967 = NULL ;
F_21 ( ! F_679 ( & V_75 -> V_969 ) ) ;
if ( V_624 -> V_28 -> V_50 ) {
V_50 = V_624 -> V_28 -> V_50 ;
V_349 = F_680 ( & V_50 -> V_427 , V_421 ) ;
if ( V_349 )
goto V_970;
goto V_60;
}
F_233 (dev, possible_crtc) {
V_120 ++ ;
if ( ! ( V_510 -> V_971 & ( 1 << V_120 ) ) )
continue;
V_349 = F_680 ( & V_965 -> V_427 , V_421 ) ;
if ( V_349 )
goto V_970;
if ( V_965 -> V_28 -> V_505 ) {
F_681 ( & V_965 -> V_427 ) ;
continue;
}
V_50 = V_965 ;
break;
}
if ( ! V_50 ) {
F_156 ( L_144 ) ;
goto V_970;
}
V_60:
V_66 = F_42 ( V_50 ) ;
V_349 = F_680 ( & V_50 -> V_73 -> V_427 , V_421 ) ;
if ( V_349 )
goto V_970;
V_28 = F_489 ( V_48 ) ;
V_967 = F_489 ( V_48 ) ;
if ( ! V_28 || ! V_967 ) {
V_349 = - V_626 ;
goto V_970;
}
V_28 -> V_430 = V_421 ;
V_967 -> V_430 = V_421 ;
V_968 = F_682 ( V_28 , V_624 ) ;
if ( F_188 ( V_968 ) ) {
V_349 = F_238 ( V_968 ) ;
goto V_970;
}
V_349 = F_683 ( V_968 , V_50 ) ;
if ( V_349 )
goto V_970;
V_45 = F_490 ( V_28 , V_66 ) ;
if ( F_188 ( V_45 ) ) {
V_349 = F_238 ( V_45 ) ;
goto V_970;
}
V_45 -> V_49 . V_72 = V_45 -> V_49 . V_505 = true ;
if ( ! V_417 )
V_417 = & V_972 ;
V_74 = F_670 ( V_48 , V_417 ) ;
if ( V_74 == NULL ) {
F_156 ( L_145 ) ;
V_74 = F_666 ( V_48 , V_417 , 24 , 32 ) ;
} else
F_156 ( L_146 ) ;
if ( F_188 ( V_74 ) ) {
F_156 ( L_147 ) ;
goto V_970;
}
V_349 = F_672 ( V_28 , V_50 , V_417 , V_74 , 0 , 0 ) ;
if ( V_349 )
goto V_970;
F_224 ( V_74 ) ;
V_349 = F_492 ( & V_45 -> V_49 , V_417 ) ;
if ( V_349 )
goto V_970;
V_349 = F_497 ( F_682 ( V_967 , V_624 ) ) ;
if ( ! V_349 )
V_349 = F_497 ( F_684 ( V_967 , V_50 ) ) ;
if ( ! V_349 )
V_349 = F_497 ( F_673 ( V_967 , V_50 -> V_73 ) ) ;
if ( V_349 ) {
F_156 ( L_148 , V_349 ) ;
goto V_970;
}
V_349 = F_685 ( V_28 ) ;
if ( V_349 ) {
F_156 ( L_149 ) ;
goto V_970;
}
V_964 -> V_967 = V_967 ;
F_312 ( V_28 ) ;
F_347 ( V_6 , V_66 -> V_79 ) ;
return true ;
V_970:
if ( V_28 ) {
F_312 ( V_28 ) ;
V_28 = NULL ;
}
if ( V_967 ) {
F_312 ( V_967 ) ;
V_967 = NULL ;
}
if ( V_349 == - V_424 )
return V_349 ;
return false ;
}
void F_686 ( struct V_572 * V_624 ,
struct V_963 * V_964 ,
struct V_420 * V_421 )
{
struct V_509 * V_509 =
F_678 ( V_624 ) ;
struct V_604 * V_510 = & V_509 -> V_49 ;
struct V_419 * V_28 = V_964 -> V_967 ;
int V_349 ;
F_156 ( L_143 ,
V_624 -> V_49 . V_324 , V_624 -> V_12 ,
V_510 -> V_49 . V_324 , V_510 -> V_12 ) ;
if ( ! V_28 )
return;
V_349 = F_303 ( V_28 , V_421 ) ;
if ( V_349 )
F_156 ( L_150 , V_349 ) ;
F_312 ( V_28 ) ;
}
static int F_687 ( struct V_47 * V_48 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 = V_23 -> V_159 . V_30 ;
if ( ( V_30 & V_814 ) == V_739 )
return V_6 -> V_667 . V_777 ;
else if ( F_70 ( V_6 ) )
return 120000 ;
else if ( ! F_50 ( V_6 ) )
return 96000 ;
else
return 48000 ;
}
static void F_587 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
T_1 V_30 = V_23 -> V_159 . V_30 ;
T_1 V_671 ;
struct V_30 clock ;
int V_24 ;
int V_29 = F_687 ( V_48 , V_23 ) ;
if ( ( V_30 & V_973 ) == 0 )
V_671 = V_23 -> V_159 . V_616 ;
else
V_671 = V_23 -> V_159 . V_617 ;
clock . V_39 = ( V_671 & V_974 ) >> V_975 ;
if ( F_29 ( V_6 ) ) {
clock . V_36 = F_688 ( ( V_671 & V_976 ) >> V_977 ) - 1 ;
clock . V_32 = ( V_671 & V_978 ) >> V_979 ;
} else {
clock . V_36 = ( V_671 & V_980 ) >> V_977 ;
clock . V_32 = ( V_671 & V_981 ) >> V_979 ;
}
if ( ! F_50 ( V_6 ) ) {
if ( F_29 ( V_6 ) )
clock . V_34 = F_688 ( ( V_30 & V_982 ) >>
V_729 ) ;
else
clock . V_34 = F_688 ( ( V_30 & V_983 ) >>
V_730 ) ;
switch ( V_30 & V_984 ) {
case V_726 :
clock . V_35 = V_30 & V_732 ?
5 : 10 ;
break;
case V_725 :
clock . V_35 = V_30 & V_733 ?
7 : 14 ;
break;
default:
F_156 ( L_151
L_152 , ( int ) ( V_30 & V_984 ) ) ;
return;
}
if ( F_29 ( V_6 ) )
V_24 = F_20 ( V_29 , & clock ) ;
else
V_24 = F_23 ( V_29 , & clock ) ;
} else {
T_1 V_985 = F_136 ( V_6 ) ? 0 : F_17 ( V_106 ) ;
bool V_986 = ( V_79 == 1 ) && ( V_985 & V_142 ) ;
if ( V_986 ) {
clock . V_34 = F_688 ( ( V_30 & V_987 ) >>
V_730 ) ;
if ( V_985 & V_988 )
clock . V_35 = 7 ;
else
clock . V_35 = 14 ;
} else {
if ( V_30 & V_741 )
clock . V_34 = 2 ;
else {
clock . V_34 = ( ( V_30 & V_989 ) >>
V_730 ) + 2 ;
}
if ( V_30 & V_742 )
clock . V_35 = 4 ;
else
clock . V_35 = 2 ;
}
V_24 = F_23 ( V_29 , & clock ) ;
}
V_23 -> V_24 = V_24 ;
}
int F_689 ( int V_990 ,
const struct V_659 * V_660 )
{
if ( ! V_660 -> V_665 )
return 0 ;
return F_40 ( ( T_4 ) V_660 -> V_664 * V_990 , V_660 -> V_665 ) ;
}
static void F_617 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
F_587 ( V_50 , V_23 ) ;
V_23 -> V_49 . V_76 . V_77 =
F_689 ( F_14 ( V_6 , V_23 ) ,
& V_23 -> V_582 ) ;
}
struct V_518 * F_690 ( struct V_47 * V_48 ,
struct V_130 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
struct V_518 * V_417 ;
struct V_22 * V_23 ;
int V_991 = F_17 ( F_368 ( V_80 ) ) ;
int V_763 = F_17 ( F_372 ( V_80 ) ) ;
int V_992 = F_17 ( F_374 ( V_80 ) ) ;
int V_993 = F_17 ( F_378 ( V_80 ) ) ;
enum V_79 V_79 = V_66 -> V_79 ;
V_417 = F_504 ( sizeof( * V_417 ) , V_627 ) ;
if ( ! V_417 )
return NULL ;
V_23 = F_504 ( sizeof( * V_23 ) , V_627 ) ;
if ( ! V_23 ) {
F_232 ( V_417 ) ;
return NULL ;
}
V_23 -> V_80 = (enum V_78 ) V_79 ;
V_23 -> V_585 = 1 ;
V_23 -> V_159 . V_30 = F_17 ( F_58 ( V_79 ) ) ;
V_23 -> V_159 . V_616 = F_17 ( F_483 ( V_79 ) ) ;
V_23 -> V_159 . V_617 = F_17 ( F_484 ( V_79 ) ) ;
F_587 ( V_66 , V_23 ) ;
V_417 -> clock = V_23 -> V_24 / V_23 -> V_585 ;
V_417 -> V_755 = ( V_991 & 0xffff ) + 1 ;
V_417 -> V_756 = ( ( V_991 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_757 = ( V_763 & 0xffff ) + 1 ;
V_417 -> V_758 = ( ( V_763 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_754 = ( V_992 & 0xffff ) + 1 ;
V_417 -> V_759 = ( ( V_992 & 0xffff0000 ) >> 16 ) + 1 ;
V_417 -> V_760 = ( V_993 & 0xffff ) + 1 ;
V_417 -> V_761 = ( ( V_993 & 0xffff0000 ) >> 16 ) + 1 ;
F_573 ( V_417 ) ;
F_232 ( V_23 ) ;
return V_417 ;
}
static void F_691 ( struct V_130 * V_50 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_1 * V_2 ;
F_318 ( & V_48 -> V_438 ) ;
V_2 = V_66 -> V_439 ;
V_66 -> V_439 = NULL ;
F_319 ( & V_48 -> V_438 ) ;
if ( V_2 ) {
F_692 ( & V_2 -> V_3 ) ;
F_692 ( & V_2 -> V_480 ) ;
F_232 ( V_2 ) ;
}
F_693 ( V_50 ) ;
F_232 ( V_66 ) ;
}
static void F_694 ( struct V_994 * V_995 )
{
struct V_1 * V_2 =
F_695 ( V_995 , struct V_1 , V_480 ) ;
struct V_66 * V_50 = F_42 ( V_2 -> V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
if ( F_1 ( V_2 ) )
F_696 ( & V_2 -> V_3 ) ;
F_3 ( & V_48 -> V_242 ) ;
F_194 ( V_2 -> V_996 ) ;
F_222 ( V_2 -> V_478 ) ;
F_5 ( & V_48 -> V_242 ) ;
F_697 ( V_2 -> V_997 ) ;
F_698 ( F_35 ( V_48 ) ,
F_227 ( V_73 ) -> V_341 ) ;
F_420 ( V_50 ) ;
F_224 ( V_2 -> V_998 ) ;
F_591 ( F_346 ( & V_50 -> V_475 ) == 0 ) ;
F_699 ( & V_50 -> V_475 ) ;
F_232 ( V_2 ) ;
}
static bool F_700 ( T_1 V_999 , T_1 V_1000 )
{
return ! ( ( V_999 - V_1000 ) & 0x80000000 ) ;
}
static bool F_701 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( F_323 ( V_50 ) )
return true ;
if ( F_53 ( V_6 ) < 5 && ! F_249 ( V_6 ) )
return true ;
return ( F_17 ( F_702 ( V_50 -> V_118 ) ) & ~ 0xfff ) ==
V_50 -> V_439 -> V_1001 &&
F_700 ( F_17 ( F_703 ( V_50 -> V_79 ) ) ,
V_50 -> V_439 -> V_1002 ) ;
}
static bool
F_704 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
return F_705 ( V_50 ) != V_2 -> V_1003 ;
}
static bool F_706 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
if ( ! F_346 ( & V_2 -> V_437 ) )
return false ;
F_707 () ;
if ( F_1 ( V_2 ) )
return F_704 ( V_50 , V_2 ) ;
else
return F_701 ( V_50 , V_2 ) ;
}
void F_295 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
unsigned long V_315 ;
if ( ! V_50 )
return;
F_256 ( & V_48 -> V_438 , V_315 ) ;
V_2 = V_50 -> V_439 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_706 ( V_50 , V_2 ) )
F_348 ( V_50 ) ;
F_270 ( & V_48 -> V_438 , V_315 ) ;
}
void F_708 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
unsigned long V_315 ;
if ( ! V_50 )
return;
F_256 ( & V_48 -> V_438 , V_315 ) ;
V_2 = V_50 -> V_439 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_706 ( V_50 , V_2 ) )
F_348 ( V_50 ) ;
F_270 ( & V_48 -> V_438 , V_315 ) ;
}
static inline void F_709 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
V_2 -> V_1003 = F_705 ( V_50 ) ;
F_710 () ;
F_711 ( & V_2 -> V_437 , 1 ) ;
}
static int F_712 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1006 , * V_1007 ;
V_1007 = F_713 ( V_1005 , 6 ) ;
if ( F_188 ( V_1007 ) )
return F_238 ( V_1007 ) ;
if ( V_66 -> V_118 )
V_1006 = V_1008 ;
else
V_1006 = V_1009 ;
* V_1007 ++ = V_1010 | V_1006 ;
* V_1007 ++ = V_1011 ;
* V_1007 ++ = V_1012 | F_714 ( V_66 -> V_118 ) ;
* V_1007 ++ = V_74 -> V_247 [ 0 ] ;
* V_1007 ++ = V_66 -> V_439 -> V_1001 ;
* V_1007 ++ = 0 ;
return 0 ;
}
static int F_715 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1006 , * V_1007 ;
V_1007 = F_713 ( V_1005 , 6 ) ;
if ( F_188 ( V_1007 ) )
return F_238 ( V_1007 ) ;
if ( V_66 -> V_118 )
V_1006 = V_1008 ;
else
V_1006 = V_1009 ;
* V_1007 ++ = V_1010 | V_1006 ;
* V_1007 ++ = V_1011 ;
* V_1007 ++ = V_1013 | F_714 ( V_66 -> V_118 ) ;
* V_1007 ++ = V_74 -> V_247 [ 0 ] ;
* V_1007 ++ = V_66 -> V_439 -> V_1001 ;
* V_1007 ++ = V_1011 ;
return 0 ;
}
static int F_716 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1014 , V_1015 , * V_1007 ;
V_1007 = F_713 ( V_1005 , 4 ) ;
if ( F_188 ( V_1007 ) )
return F_238 ( V_1007 ) ;
* V_1007 ++ = V_1012 | F_714 ( V_66 -> V_118 ) ;
* V_1007 ++ = V_74 -> V_247 [ 0 ] ;
* V_1007 ++ = V_66 -> V_439 -> V_1001 |
F_208 ( V_74 -> V_216 ) ;
V_1014 = 0 ;
V_1015 = F_17 ( F_328 ( V_66 -> V_79 ) ) & 0x0fff0fff ;
* V_1007 ++ = V_1014 | V_1015 ;
return 0 ;
}
static int F_717 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1014 , V_1015 , * V_1007 ;
V_1007 = F_713 ( V_1005 , 4 ) ;
if ( F_188 ( V_1007 ) )
return F_238 ( V_1007 ) ;
* V_1007 ++ = V_1012 | F_714 ( V_66 -> V_118 ) ;
* V_1007 ++ = V_74 -> V_247 [ 0 ] | F_208 ( V_74 -> V_216 ) ;
* V_1007 ++ = V_66 -> V_439 -> V_1001 ;
V_1014 = 0 ;
V_1015 = F_17 ( F_328 ( V_66 -> V_79 ) ) & 0x0fff0fff ;
* V_1007 ++ = V_1014 | V_1015 ;
return 0 ;
}
static int F_718 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 * V_1007 , V_1016 = 0 ;
int V_1017 , V_349 ;
switch ( V_66 -> V_118 ) {
case V_1018 :
V_1016 = V_1019 ;
break;
case V_369 :
V_1016 = V_1020 ;
break;
case V_1021 :
V_1016 = V_1022 ;
break;
default:
F_356 ( 1 , L_153 ) ;
return - V_1023 ;
}
V_1017 = 4 ;
if ( V_1005 -> V_1024 -> V_324 == V_1025 ) {
V_1017 += 6 ;
if ( F_719 ( V_6 ) )
V_1017 += 2 ;
}
V_349 = F_720 ( V_1005 ) ;
if ( V_349 )
return V_349 ;
V_1007 = F_713 ( V_1005 , V_1017 ) ;
if ( F_188 ( V_1007 ) )
return F_238 ( V_1007 ) ;
if ( V_1005 -> V_1024 -> V_324 == V_1025 ) {
* V_1007 ++ = F_721 ( 1 ) ;
* V_1007 ++ = F_114 ( V_1026 ) ;
* V_1007 ++ = ~ ( V_1027 |
V_1028 |
V_1029 ) ;
if ( F_719 ( V_6 ) )
* V_1007 ++ = V_1030 |
V_1031 ;
else
* V_1007 ++ = V_1032 | V_1031 ;
* V_1007 ++ = F_114 ( V_1026 ) ;
* V_1007 ++ = F_722 ( V_1005 -> V_1024 -> V_1033 ) + 256 ;
if ( F_719 ( V_6 ) ) {
* V_1007 ++ = 0 ;
* V_1007 ++ = V_1011 ;
}
}
* V_1007 ++ = V_1013 | V_1016 ;
* V_1007 ++ = V_74 -> V_247 [ 0 ] | F_208 ( V_74 -> V_216 ) ;
* V_1007 ++ = V_66 -> V_439 -> V_1001 ;
* V_1007 ++ = V_1011 ;
return 0 ;
}
static bool F_723 ( struct V_1034 * V_1024 ,
struct V_238 * V_239 )
{
if ( V_1024 == NULL )
return true ;
if ( F_53 ( V_1024 -> V_244 ) < 5 )
return false ;
if ( V_244 . F_723 < 0 )
return false ;
else if ( V_244 . F_723 > 0 )
return true ;
else if ( V_244 . V_1035 )
return true ;
return V_1024 != F_724 ( V_239 ) ;
}
static void F_725 ( struct V_66 * V_66 ,
unsigned int V_231 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_213 * V_74 = V_66 -> V_49 . V_73 -> V_74 ;
const enum V_79 V_79 = V_66 -> V_79 ;
T_1 V_360 , V_276 = F_278 ( V_74 , 0 , V_231 ) ;
V_360 = F_17 ( F_89 ( V_79 , 0 ) ) ;
V_360 &= ~ V_869 ;
switch ( V_74 -> V_216 ) {
case V_217 :
break;
case V_218 :
V_360 |= V_387 ;
break;
case V_219 :
V_360 |= V_388 ;
break;
case V_220 :
V_360 |= V_389 ;
break;
default:
F_167 ( V_74 -> V_216 ) ;
}
F_119 ( F_89 ( V_79 , 0 ) , V_360 ) ;
F_119 ( F_287 ( V_79 , 0 ) , V_276 ) ;
F_119 ( F_292 ( V_79 , 0 ) , V_2 -> V_1001 ) ;
F_120 ( F_292 ( V_79 , 0 ) ) ;
}
static void F_726 ( struct V_66 * V_66 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_213 * V_74 = V_66 -> V_49 . V_73 -> V_74 ;
T_3 V_13 = F_83 ( V_66 -> V_118 ) ;
T_1 V_350 ;
V_350 = F_17 ( V_13 ) ;
if ( V_74 -> V_216 == V_218 )
V_350 |= V_355 ;
else
V_350 &= ~ V_355 ;
F_119 ( V_13 , V_350 ) ;
F_119 ( F_264 ( V_66 -> V_118 ) , V_2 -> V_1001 ) ;
F_120 ( F_264 ( V_66 -> V_118 ) ) ;
}
static void F_727 ( struct V_994 * V_343 )
{
struct V_1 * V_2 =
F_695 ( V_343 , struct V_1 , V_3 ) ;
struct V_66 * V_50 = F_42 ( V_2 -> V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_251 * V_252 =
F_176 ( V_50 -> V_49 . V_73 -> V_74 ) ;
struct V_238 * V_239 = V_252 -> V_239 ;
F_21 ( F_728 ( V_239 , 0 , V_1036 , NULL ) < 0 ) ;
F_729 ( V_50 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_725 ( V_50 , V_2 -> V_231 , V_2 ) ;
else
F_726 ( V_50 , V_2 ) ;
F_730 ( V_50 , V_2 ) ;
}
static int F_731 ( struct V_47 * V_48 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_238 * V_239 ,
struct V_1004 * V_1005 ,
T_2 V_315 )
{
return - V_1023 ;
}
static bool F_732 ( struct V_5 * V_6 ,
struct V_66 * V_66 ,
struct V_1 * V_2 )
{
T_1 V_1037 , V_1038 ;
if ( ! F_346 ( & V_2 -> V_437 ) )
return false ;
F_707 () ;
V_1038 = F_705 ( V_66 ) ;
if ( V_2 -> V_1039 == 0 ) {
if ( V_2 -> V_997 &&
! F_733 ( V_2 -> V_997 ) )
return false ;
V_2 -> V_1039 = V_1038 ;
}
if ( V_1038 - V_2 -> V_1039 < 3 )
return false ;
if ( F_53 ( V_6 ) >= 4 )
V_1037 = F_734 ( F_17 ( F_264 ( V_66 -> V_118 ) ) ) ;
else
V_1037 = F_17 ( F_268 ( V_66 -> V_118 ) ) ;
return V_1037 == V_2 -> V_1001 ;
}
void F_735 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_245 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
F_21 ( ! F_736 () ) ;
if ( V_50 == NULL )
return;
F_737 ( & V_48 -> V_438 ) ;
V_2 = V_50 -> V_439 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_732 ( V_6 , V_50 , V_2 ) ) {
F_356 ( 1 ,
L_154 ,
V_2 -> V_1003 , F_705 ( V_50 ) ) ;
F_348 ( V_50 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_705 ( V_50 ) - V_2 -> V_1003 > 1 )
F_738 ( V_2 -> V_997 ) ;
F_739 ( & V_48 -> V_438 ) ;
}
T_5
static int F_740 ( struct V_130 * V_50 ,
struct V_213 * V_74 ,
struct V_1040 * V_476 ,
T_2 V_1041 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_213 * V_998 = V_50 -> V_73 -> V_74 ;
struct V_238 * V_239 = F_183 ( V_74 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_318 * V_73 = V_50 -> V_73 ;
enum V_79 V_79 = V_66 -> V_79 ;
struct V_1 * V_2 ;
struct V_1034 * V_1024 ;
bool V_1042 ;
struct V_1004 * V_1043 ;
struct V_237 * V_240 ;
int V_349 ;
if ( F_21 ( F_183 ( V_998 ) == NULL ) )
return - V_1044 ;
if ( V_74 -> V_215 != V_50 -> V_73 -> V_74 -> V_215 )
return - V_272 ;
if ( F_53 ( V_6 ) > 3 &&
( V_74 -> V_265 [ 0 ] != V_50 -> V_73 -> V_74 -> V_265 [ 0 ] ||
V_74 -> V_247 [ 0 ] != V_50 -> V_73 -> V_74 -> V_247 [ 0 ] ) )
return - V_272 ;
if ( F_741 ( & V_6 -> V_435 ) )
goto V_1045;
V_2 = F_504 ( sizeof( * V_2 ) , V_627 ) ;
if ( V_2 == NULL )
return - V_626 ;
V_2 -> V_476 = V_476 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_998 = V_998 ;
F_742 ( & V_2 -> V_480 , F_694 ) ;
V_349 = F_96 ( V_50 ) ;
if ( V_349 )
goto V_1046;
F_318 ( & V_48 -> V_438 ) ;
if ( V_66 -> V_439 ) {
if ( F_706 ( V_66 , V_66 -> V_439 ) ) {
F_13 ( L_155 ) ;
F_348 ( V_66 ) ;
} else {
F_13 ( L_156 ) ;
F_319 ( & V_48 -> V_438 ) ;
F_97 ( V_50 ) ;
F_232 ( V_2 ) ;
return - V_1044 ;
}
}
V_66 -> V_439 = V_2 ;
F_319 ( & V_48 -> V_438 ) ;
if ( F_346 ( & V_66 -> V_475 ) >= 2 )
F_743 ( V_6 -> V_479 ) ;
F_225 ( V_2 -> V_998 ) ;
V_50 -> V_73 -> V_74 = V_74 ;
F_223 ( V_50 -> V_73 ) ;
V_2 -> V_478 = F_744 ( V_239 ) ;
V_349 = F_745 ( V_48 ) ;
if ( V_349 )
goto V_1047;
V_66 -> V_436 = F_325 ( & V_6 -> V_435 ) ;
if ( F_746 ( & V_6 -> V_435 ) ) {
V_349 = - V_1048 ;
goto V_1049;
}
F_747 ( & V_66 -> V_475 ) ;
if ( F_53 ( V_6 ) >= 5 || F_249 ( V_6 ) )
V_2 -> V_1002 = F_17 ( F_703 ( V_79 ) ) + 1 ;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
V_1024 = V_6 -> V_1024 [ V_1050 ] ;
if ( V_74 -> V_216 != V_998 -> V_216 )
V_1024 = NULL ;
} else if ( F_251 ( V_6 ) || F_252 ( V_6 ) ) {
V_1024 = V_6 -> V_1024 [ V_1050 ] ;
} else if ( F_53 ( V_6 ) >= 7 ) {
V_1024 = F_724 ( V_239 ) ;
if ( V_1024 == NULL || V_1024 -> V_324 != V_1025 )
V_1024 = V_6 -> V_1024 [ V_1050 ] ;
} else {
V_1024 = V_6 -> V_1024 [ V_1025 ] ;
}
V_1042 = F_723 ( V_1024 , V_239 ) ;
V_240 = F_182 ( V_74 , V_73 -> V_28 -> V_231 ) ;
if ( F_188 ( V_240 ) ) {
V_349 = F_238 ( V_240 ) ;
goto V_1051;
}
V_2 -> V_996 = F_231 ( V_73 -> V_28 ) -> V_240 ;
F_231 ( V_73 -> V_28 ) -> V_240 = V_240 ;
V_2 -> V_1001 = F_722 ( V_240 ) + V_66 -> V_362 ;
V_2 -> V_231 = V_50 -> V_73 -> V_28 -> V_231 ;
F_422 ( V_66 , V_66 -> V_75 ,
F_231 ( V_73 -> V_28 ) ) ;
if ( V_1042 ) {
F_742 ( & V_2 -> V_3 , F_727 ) ;
F_352 ( V_1052 , & V_2 -> V_3 ) ;
} else {
V_1043 = F_748 ( V_1024 ,
V_6 -> V_1053 ) ;
if ( F_188 ( V_1043 ) ) {
V_349 = F_238 ( V_1043 ) ;
goto V_1054;
}
V_349 = F_749 ( V_1043 , V_239 , false ) ;
if ( V_349 )
goto V_1055;
V_349 = V_6 -> V_432 . V_1056 ( V_48 , V_50 , V_74 , V_239 , V_1043 ,
V_1041 ) ;
if ( V_349 )
goto V_1055;
F_709 ( V_66 , V_2 ) ;
V_2 -> V_997 = F_750 ( V_1043 ) ;
F_751 ( V_1043 ) ;
}
F_752 ( V_239 , 0 , V_1057 ) ;
F_753 ( F_183 ( V_998 ) , V_239 ,
F_227 ( V_73 ) -> V_341 ) ;
F_5 ( & V_48 -> V_242 ) ;
F_754 ( F_35 ( V_48 ) ,
F_227 ( V_73 ) -> V_341 ) ;
F_755 ( V_66 -> V_118 , V_239 ) ;
return 0 ;
V_1055:
F_751 ( V_1043 ) ;
V_1054:
F_231 ( V_73 -> V_28 ) -> V_240 = V_2 -> V_996 ;
F_194 ( V_240 ) ;
V_1051:
F_699 ( & V_66 -> V_475 ) ;
V_1049:
F_5 ( & V_48 -> V_242 ) ;
V_1047:
V_50 -> V_73 -> V_74 = V_998 ;
F_223 ( V_50 -> V_73 ) ;
F_222 ( V_239 ) ;
F_224 ( V_2 -> V_998 ) ;
F_318 ( & V_48 -> V_438 ) ;
V_66 -> V_439 = NULL ;
F_319 ( & V_48 -> V_438 ) ;
F_97 ( V_50 ) ;
V_1046:
F_232 ( V_2 ) ;
if ( V_349 == - V_1048 ) {
struct V_419 * V_28 ;
struct V_326 * V_319 ;
V_1045:
V_28 = F_489 ( V_48 ) ;
if ( ! V_28 )
return - V_626 ;
V_28 -> V_430 = V_48 -> V_426 . V_430 ;
V_460:
V_319 = F_673 ( V_28 , V_73 ) ;
V_349 = F_497 ( V_319 ) ;
if ( ! V_349 ) {
F_676 ( V_319 , V_74 ) ;
V_349 = F_675 ( V_319 , V_50 ) ;
if ( ! V_349 )
V_349 = F_685 ( V_28 ) ;
}
if ( V_349 == - V_424 ) {
F_309 ( V_28 -> V_430 ) ;
F_756 ( V_28 ) ;
goto V_460;
}
F_312 ( V_28 ) ;
if ( V_349 == 0 && V_476 ) {
F_318 ( & V_48 -> V_438 ) ;
F_349 ( V_50 , V_476 ) ;
F_319 ( & V_48 -> V_438 ) ;
}
}
return V_349 ;
}
static bool F_757 ( struct V_318 * V_118 ,
struct V_326 * V_28 )
{
struct V_250 * V_1058 = F_231 ( V_28 ) ;
struct V_250 * V_1059 = F_231 ( V_118 -> V_28 ) ;
if ( V_1058 -> V_49 . V_320 != V_1059 -> V_49 . V_320 )
return true ;
if ( ! V_1059 -> V_49 . V_74 || ! V_1058 -> V_49 . V_74 )
return false ;
if ( V_1059 -> V_49 . V_74 -> V_216 != V_1058 -> V_49 . V_74 -> V_216 ||
V_1059 -> V_49 . V_231 != V_1058 -> V_49 . V_231 ||
F_244 ( & V_1058 -> V_49 . V_338 ) != F_244 ( & V_1059 -> V_49 . V_338 ) ||
F_245 ( & V_1058 -> V_49 . V_338 ) != F_245 ( & V_1059 -> V_49 . V_338 ) ||
F_244 ( & V_1058 -> V_49 . V_339 ) != F_244 ( & V_1059 -> V_49 . V_339 ) ||
F_245 ( & V_1058 -> V_49 . V_339 ) != F_245 ( & V_1059 -> V_49 . V_339 ) )
return true ;
return false ;
}
static bool F_758 ( struct V_250 * V_28 )
{
int V_332 = F_244 ( & V_28 -> V_49 . V_338 ) >> 16 ;
int V_333 = F_245 ( & V_28 -> V_49 . V_338 ) >> 16 ;
int V_410 = F_244 ( & V_28 -> V_49 . V_339 ) ;
int V_411 = F_245 ( & V_28 -> V_49 . V_339 ) ;
return ( V_332 != V_410 || V_333 != V_411 ) ;
}
int F_759 ( struct V_27 * V_45 ,
struct V_326 * V_319 )
{
struct V_22 * V_23 = F_235 ( V_45 ) ;
struct V_130 * V_50 = V_45 -> V_50 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_321 * V_118 = F_227 ( V_319 -> V_118 ) ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_250 * V_1060 =
F_231 ( V_118 -> V_49 . V_28 ) ;
bool V_422 = F_18 ( V_45 ) ;
bool V_1061 = V_50 -> V_28 -> V_72 ;
bool V_1062 = V_45 -> V_72 ;
bool V_1063 , V_1064 , V_320 , V_1065 ;
struct V_213 * V_74 = V_319 -> V_74 ;
int V_349 ;
if ( F_53 ( V_6 ) >= 9 && V_118 -> V_324 != V_1066 ) {
V_349 = F_398 (
F_235 ( V_45 ) ,
F_231 ( V_319 ) ) ;
if ( V_349 )
return V_349 ;
}
V_1065 = V_1060 -> V_49 . V_320 ;
V_320 = V_319 -> V_320 ;
if ( ! V_1061 && F_21 ( V_1065 ) )
V_1065 = false ;
if ( ! V_1062 ) {
V_319 -> V_320 = V_320 = false ;
F_235 ( V_45 ) -> V_323 &= ~ F_228 ( V_118 -> V_324 ) ;
}
if ( ! V_1065 && ! V_320 )
return 0 ;
if ( V_74 != V_1060 -> V_49 . V_74 )
V_23 -> V_1067 = true ;
V_1063 = V_1065 && ( ! V_320 || V_422 ) ;
V_1064 = V_320 && ( ! V_1065 || V_422 ) ;
F_760 ( L_157 ,
V_66 -> V_49 . V_49 . V_324 , V_66 -> V_49 . V_12 ,
V_118 -> V_49 . V_49 . V_324 , V_118 -> V_49 . V_12 ,
V_74 ? V_74 -> V_49 . V_324 : - 1 ) ;
F_760 ( L_158 ,
V_118 -> V_49 . V_49 . V_324 , V_118 -> V_49 . V_12 ,
V_1065 , V_320 ,
V_1063 , V_1064 , V_422 ) ;
if ( V_1064 ) {
if ( F_53 ( V_6 ) < 5 )
V_23 -> V_569 = true ;
if ( V_118 -> V_324 != V_1066 )
V_23 -> V_566 = true ;
} else if ( V_1063 ) {
if ( F_53 ( V_6 ) < 5 )
V_23 -> V_560 = true ;
if ( V_118 -> V_324 != V_1066 )
V_23 -> V_566 = true ;
} else if ( F_757 ( & V_118 -> V_49 , V_319 ) ) {
if ( F_53 ( V_6 ) < 5 ) {
V_23 -> V_569 = true ;
V_23 -> V_560 = true ;
}
}
if ( V_320 || V_1065 )
V_23 -> V_559 |= V_118 -> V_341 ;
if ( V_118 -> V_324 == V_126 && F_251 ( V_6 ) &&
F_758 ( F_231 ( V_319 ) ) &&
! F_758 ( V_1060 ) )
V_23 -> V_567 = true ;
return 0 ;
}
static bool F_761 ( const struct V_509 * V_999 ,
const struct V_509 * V_1000 )
{
return V_999 == V_1000 || ( V_999 -> V_1068 & ( 1 << V_1000 -> type ) &&
V_1000 -> V_1068 & ( 1 << V_999 -> type ) ) ;
}
static bool F_762 ( struct V_419 * V_28 ,
struct V_66 * V_50 ,
struct V_509 * V_510 )
{
struct V_509 * V_1069 ;
struct V_572 * V_624 ;
struct V_570 * V_968 ;
int V_120 ;
F_428 (state, connector, connector_state, i) {
if ( V_968 -> V_50 != & V_50 -> V_49 )
continue;
V_1069 =
F_429 ( V_968 -> V_574 ) ;
if ( ! F_761 ( V_510 , V_1069 ) )
return false ;
}
return true ;
}
static int F_763 ( struct V_130 * V_50 ,
struct V_27 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 =
F_235 ( V_45 ) ;
struct V_419 * V_28 = V_45 -> V_28 ;
int V_349 ;
bool V_422 = F_18 ( V_45 ) ;
if ( V_422 && ! V_45 -> V_72 )
V_23 -> V_560 = true ;
if ( V_422 && V_45 -> V_505 &&
V_6 -> V_432 . V_1070 &&
! F_21 ( V_23 -> V_191 ) ) {
V_349 = V_6 -> V_432 . V_1070 ( V_66 ,
V_23 ) ;
if ( V_349 )
return V_349 ;
}
if ( V_45 -> V_1071 ) {
V_349 = F_764 ( V_50 , V_45 ) ;
if ( V_349 )
return V_349 ;
V_45 -> V_1072 = true ;
}
V_349 = 0 ;
if ( V_6 -> V_432 . V_1073 ) {
V_349 = V_6 -> V_432 . V_1073 ( V_23 ) ;
if ( V_349 ) {
F_156 ( L_159 ) ;
return V_349 ;
}
}
if ( V_6 -> V_432 . V_1074 &&
! F_302 ( V_28 ) -> V_423 ) {
if ( F_21 ( ! V_6 -> V_432 . V_1073 ) )
return 0 ;
V_349 = V_6 -> V_432 . V_1074 ( V_48 ,
V_66 ,
V_23 ) ;
if ( V_349 ) {
F_156 ( L_160 ) ;
return V_349 ;
}
} else if ( V_6 -> V_432 . V_1074 ) {
if ( F_70 ( V_6 ) && F_53 ( V_6 ) < 9 )
V_23 -> V_1075 . V_1076 . V_1077 = V_23 -> V_1075 . V_1076 . V_1078 ;
}
if ( F_53 ( V_6 ) >= 9 ) {
if ( V_422 )
V_349 = F_397 ( V_23 ) ;
if ( ! V_349 )
V_349 = F_765 ( V_6 , V_66 ,
V_23 ) ;
}
return V_349 ;
}
static void F_766 ( struct V_47 * V_48 )
{
struct V_623 * V_624 ;
struct V_1079 V_1080 ;
F_767 ( V_48 , & V_1080 ) ;
F_768 (connector, &conn_iter) {
if ( V_624 -> V_49 . V_28 -> V_50 )
F_769 ( & V_624 -> V_49 ) ;
if ( V_624 -> V_49 . V_510 ) {
V_624 -> V_49 . V_28 -> V_574 =
V_624 -> V_49 . V_510 ;
V_624 -> V_49 . V_28 -> V_50 =
V_624 -> V_49 . V_510 -> V_50 ;
F_770 ( & V_624 -> V_49 ) ;
} else {
V_624 -> V_49 . V_28 -> V_574 = NULL ;
V_624 -> V_49 . V_28 -> V_50 = NULL ;
}
}
F_771 ( & V_1080 ) ;
}
static void
F_772 ( struct V_623 * V_624 ,
struct V_22 * V_23 )
{
const struct V_1081 * V_1082 = & V_624 -> V_49 . V_1083 ;
int V_851 = V_23 -> V_635 ;
F_156 ( L_161 ,
V_624 -> V_49 . V_49 . V_324 ,
V_624 -> V_49 . V_12 ) ;
if ( V_1082 -> V_519 != 0 && V_1082 -> V_519 * 3 < V_851 ) {
F_156 ( L_162 ,
V_851 , V_1082 -> V_519 * 3 ) ;
V_23 -> V_635 = V_1082 -> V_519 * 3 ;
}
if ( V_1082 -> V_519 == 0 && V_851 > 24 ) {
F_156 ( L_163 ,
V_851 ) ;
V_23 -> V_635 = 24 ;
}
}
static int
F_773 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_419 * V_28 ;
struct V_572 * V_624 ;
struct V_570 * V_968 ;
int V_851 , V_120 ;
if ( ( F_249 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) )
V_851 = 10 * 3 ;
else if ( F_53 ( V_6 ) >= 5 )
V_851 = 12 * 3 ;
else
V_851 = 8 * 3 ;
V_23 -> V_635 = V_851 ;
V_28 = V_23 -> V_49 . V_28 ;
F_428 (state, connector, connector_state, i) {
if ( V_968 -> V_50 != & V_50 -> V_49 )
continue;
F_772 ( F_774 ( V_624 ) ,
V_23 ) ;
}
return V_851 ;
}
static void F_775 ( const struct V_518 * V_417 )
{
F_156 ( L_164
L_165 ,
V_417 -> V_77 ,
V_417 -> V_541 , V_417 -> V_648 ,
V_417 -> V_750 , V_417 -> V_747 ,
V_417 -> V_542 , V_417 -> V_752 ,
V_417 -> V_753 , V_417 -> V_743 , V_417 -> type , V_417 -> V_315 ) ;
}
static inline void
F_776 ( struct V_22 * V_23 , char * V_324 ,
unsigned int V_1084 , struct V_659 * V_660 )
{
F_156 ( L_166 ,
V_324 , V_1084 ,
V_660 -> V_662 , V_660 -> V_663 ,
V_660 -> V_664 , V_660 -> V_665 , V_660 -> V_661 ) ;
}
static void F_777 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
const char * V_1085 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_318 * V_118 ;
struct V_321 * V_321 ;
struct V_250 * V_28 ;
struct V_213 * V_74 ;
F_156 ( L_167 ,
V_50 -> V_49 . V_49 . V_324 , V_50 -> V_49 . V_12 , V_1085 ) ;
F_156 ( L_168 ,
F_778 ( V_23 -> V_80 ) ,
V_23 -> V_635 , V_23 -> V_766 ) ;
if ( V_23 -> V_207 )
F_776 ( V_23 , L_169 ,
V_23 -> V_455 ,
& V_23 -> V_582 ) ;
if ( F_393 ( V_23 ) ) {
F_776 ( V_23 , L_170 ,
V_23 -> V_1084 , & V_23 -> V_679 ) ;
if ( V_23 -> V_677 )
F_776 ( V_23 , L_171 ,
V_23 -> V_1084 ,
& V_23 -> V_680 ) ;
}
F_156 ( L_172 ,
V_23 -> V_607 , V_23 -> V_1086 ) ;
F_156 ( L_173 ) ;
F_779 ( & V_23 -> V_49 . V_417 ) ;
F_156 ( L_174 ) ;
F_779 ( & V_23 -> V_49 . V_76 ) ;
F_775 ( & V_23 -> V_49 . V_76 ) ;
F_156 ( L_175 ,
V_23 -> V_24 ,
V_23 -> V_368 , V_23 -> V_367 ,
V_23 -> V_638 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_156 ( L_176 ,
V_50 -> V_372 ,
V_23 -> V_371 . V_531 ,
V_23 -> V_371 . V_407 ) ;
if ( F_158 ( V_6 ) )
F_156 ( L_177 ,
V_23 -> V_590 . V_591 ,
V_23 -> V_590 . V_595 ,
V_23 -> V_590 . V_1087 ) ;
else
F_156 ( L_178 ,
V_23 -> V_441 . V_545 ,
V_23 -> V_441 . V_227 ,
F_780 ( V_23 -> V_441 . V_131 ) ) ;
F_156 ( L_179 ,
V_23 -> V_548 , V_23 -> V_211 ) ;
F_781 ( V_6 , & V_23 -> V_159 ) ;
F_156 ( L_180 ) ;
F_782 (plane, &dev->mode_config.plane_list, head) {
struct V_1088 V_1089 ;
V_321 = F_227 ( V_118 ) ;
if ( V_321 -> V_79 != V_50 -> V_79 )
continue;
V_28 = F_231 ( V_118 -> V_28 ) ;
V_74 = V_28 -> V_49 . V_74 ;
if ( ! V_74 ) {
F_156 ( L_181 ,
V_118 -> V_49 . V_324 , V_118 -> V_12 , V_28 -> V_407 ) ;
continue;
}
F_156 ( L_182 ,
V_118 -> V_49 . V_324 , V_118 -> V_12 ,
V_74 -> V_49 . V_324 , V_74 -> V_228 , V_74 -> V_224 ,
F_783 ( V_74 -> V_215 -> V_215 , & V_1089 ) ) ;
if ( F_53 ( V_6 ) >= 9 )
F_156 ( L_183 ,
V_28 -> V_407 ,
V_28 -> V_49 . V_338 . V_277 >> 16 ,
V_28 -> V_49 . V_338 . y1 >> 16 ,
F_244 ( & V_28 -> V_49 . V_338 ) >> 16 ,
F_245 ( & V_28 -> V_49 . V_338 ) >> 16 ,
V_28 -> V_49 . V_339 . V_277 , V_28 -> V_49 . V_339 . y1 ,
F_244 ( & V_28 -> V_49 . V_339 ) ,
F_245 ( & V_28 -> V_49 . V_339 ) ) ;
}
}
static bool F_784 ( struct V_419 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_572 * V_624 ;
unsigned int V_1090 = 0 ;
unsigned int V_1091 = 0 ;
F_785 (connector, dev) {
struct V_570 * V_968 ;
struct V_509 * V_510 ;
V_968 = F_786 ( V_28 , V_624 ) ;
if ( ! V_968 )
V_968 = V_624 -> V_28 ;
if ( ! V_968 -> V_574 )
continue;
V_510 = F_429 ( V_968 -> V_574 ) ;
F_21 ( ! V_968 -> V_50 ) ;
switch ( V_510 -> type ) {
unsigned int V_181 ;
case V_1092 :
if ( F_21 ( ! F_15 ( F_35 ( V_48 ) ) ) )
break;
case V_511 :
case V_194 :
case V_512 :
V_181 = 1 << F_385 ( & V_510 -> V_49 ) -> V_163 ;
if ( V_1090 & V_181 )
return false ;
V_1090 |= V_181 ;
break;
case V_586 :
V_1091 |=
1 << F_787 ( & V_510 -> V_49 ) -> V_73 -> V_163 ;
break;
default:
break;
}
}
if ( V_1090 & V_1091 )
return false ;
return true ;
}
static void
F_788 ( struct V_22 * V_45 )
{
struct V_5 * V_6 =
F_35 ( V_45 -> V_49 . V_50 -> V_48 ) ;
struct V_370 V_371 ;
struct V_1093 V_159 ;
struct V_857 * V_191 ;
struct V_1094 V_1095 ;
bool V_606 ;
V_371 = V_45 -> V_371 ;
V_191 = V_45 -> V_191 ;
V_159 = V_45 -> V_159 ;
V_606 = V_45 -> V_441 . V_606 ;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1095 = V_45 -> V_1075 ;
F_789 ( F_790 ( struct V_22 , V_49 ) ) ;
memset ( & V_45 -> V_49 + 1 , 0 ,
sizeof( * V_45 ) - sizeof( V_45 -> V_49 ) ) ;
V_45 -> V_371 = V_371 ;
V_45 -> V_191 = V_191 ;
V_45 -> V_159 = V_159 ;
V_45 -> V_441 . V_606 = V_606 ;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_45 -> V_1075 = V_1095 ;
}
static int
F_791 ( struct V_130 * V_50 ,
struct V_22 * V_23 )
{
struct V_419 * V_28 = V_23 -> V_49 . V_28 ;
struct V_509 * V_510 ;
struct V_572 * V_624 ;
struct V_570 * V_968 ;
int V_1096 , V_349 = - V_272 ;
int V_120 ;
bool V_460 = true ;
F_788 ( V_23 ) ;
V_23 -> V_80 =
(enum V_78 ) F_42 ( V_50 ) -> V_79 ;
if ( ! ( V_23 -> V_49 . V_76 . V_315 &
( V_523 | V_1097 ) ) )
V_23 -> V_49 . V_76 . V_315 |= V_1097 ;
if ( ! ( V_23 -> V_49 . V_76 . V_315 &
( V_525 | V_1098 ) ) )
V_23 -> V_49 . V_76 . V_315 |= V_1098 ;
V_1096 = F_773 ( F_42 ( V_50 ) ,
V_23 ) ;
if ( V_1096 < 0 )
goto V_970;
F_674 ( & V_23 -> V_49 . V_417 ,
& V_23 -> V_368 ,
& V_23 -> V_367 ) ;
F_428 (state, connector, connector_state, i) {
if ( V_968 -> V_50 != V_50 )
continue;
V_510 = F_429 ( V_968 -> V_574 ) ;
if ( ! F_762 ( V_28 , F_42 ( V_50 ) , V_510 ) ) {
F_156 ( L_184 ) ;
goto V_970;
}
V_23 -> V_1099 |= 1 << V_510 -> type ;
}
V_1100:
V_23 -> V_24 = 0 ;
V_23 -> V_585 = 1 ;
F_792 ( & V_23 -> V_49 . V_76 ,
V_1101 ) ;
F_428 (state, connector, connector_state, i) {
if ( V_968 -> V_50 != V_50 )
continue;
V_510 = F_429 ( V_968 -> V_574 ) ;
if ( ! ( V_510 -> V_1102 ( V_510 , V_23 , V_968 ) ) ) {
F_156 ( L_185 ) ;
goto V_970;
}
}
if ( ! V_23 -> V_24 )
V_23 -> V_24 = V_23 -> V_49 . V_76 . V_77
* V_23 -> V_585 ;
V_349 = F_517 ( F_42 ( V_50 ) , V_23 ) ;
if ( V_349 < 0 ) {
F_156 ( L_186 ) ;
goto V_970;
}
if ( V_349 == V_637 ) {
if ( F_7 ( ! V_460 , L_187 ) ) {
V_349 = - V_272 ;
goto V_970;
}
F_156 ( L_188 ) ;
V_460 = false ;
goto V_1100;
}
V_23 -> V_766 = ( V_23 -> V_635 == 6 * 3 ) &&
! V_23 -> V_1103 ;
F_156 ( L_189 ,
V_1096 , V_23 -> V_635 , V_23 -> V_766 ) ;
V_970:
return V_349 ;
}
static void
F_793 ( struct V_419 * V_28 )
{
struct V_130 * V_50 ;
struct V_27 * V_1104 ;
int V_120 ;
F_301 (state, crtc, new_crtc_state, i) {
F_42 ( V_50 ) -> V_75 = F_235 ( V_1104 ) ;
if ( V_1104 -> V_72 )
V_50 -> V_1105 = V_1104 -> V_76 ;
else
V_50 -> V_1105 . V_77 = 0 ;
if ( F_417 ( V_28 , V_50 -> V_73 ) ) {
struct V_326 * V_319 = V_50 -> V_73 -> V_28 ;
V_50 -> V_73 -> V_74 = V_319 -> V_74 ;
V_50 -> V_248 = V_319 -> V_330 >> 16 ;
V_50 -> V_249 = V_319 -> V_331 >> 16 ;
}
}
}
static bool F_794 ( int V_1106 , int V_1107 )
{
int V_1108 ;
if ( V_1106 == V_1107 )
return true ;
if ( ! V_1106 || ! V_1107 )
return false ;
V_1108 = abs ( V_1106 - V_1107 ) ;
if ( ( ( ( ( V_1108 + V_1106 + V_1107 ) * 100 ) ) / ( V_1106 + V_1107 ) ) < 105 )
return true ;
return false ;
}
static bool
F_795 ( unsigned int V_31 , unsigned int V_36 ,
unsigned int V_32 , unsigned int V_1109 ,
bool V_1110 )
{
if ( V_31 == V_32 && V_36 == V_1109 )
return true ;
if ( V_1110 || ! V_31 || ! V_36 || ! V_32 || ! V_1109 )
return false ;
F_789 ( V_651 > V_69 ) ;
if ( V_36 > V_1109 ) {
while ( V_36 > V_1109 ) {
V_32 <<= 1 ;
V_1109 <<= 1 ;
}
} else if ( V_36 < V_1109 ) {
while ( V_36 < V_1109 ) {
V_31 <<= 1 ;
V_36 <<= 1 ;
}
}
if ( V_36 != V_1109 )
return false ;
return F_794 ( V_31 , V_32 ) ;
}
static bool
F_796 ( const struct V_659 * V_660 ,
struct V_659 * V_676 ,
bool V_1111 )
{
if ( V_660 -> V_661 == V_676 -> V_661 &&
F_795 ( V_660 -> V_662 , V_660 -> V_663 ,
V_676 -> V_662 , V_676 -> V_663 , ! V_1111 ) &&
F_795 ( V_660 -> V_664 , V_660 -> V_665 ,
V_676 -> V_664 , V_676 -> V_665 , ! V_1111 ) ) {
if ( V_1111 )
* V_676 = * V_660 ;
return true ;
}
return false ;
}
static bool
F_797 ( struct V_5 * V_6 ,
struct V_22 * V_1112 ,
struct V_22 * V_23 ,
bool V_1111 )
{
bool V_349 = true ;
#define F_798 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_799 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_800 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_801 ( V_12 ) \
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
#define F_802 ( V_12 , T_6 ) \
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
#define F_803 ( V_12 , V_605 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
pipe_config_err(adjust, __stringify(name), \
"(%x) (expected %i, found %i)\n", \
(mask), \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_804 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_805 ( T_7 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_799 ( V_80 ) ;
F_799 ( V_207 ) ;
F_799 ( V_455 ) ;
F_801 ( V_582 ) ;
F_799 ( V_1084 ) ;
F_798 ( V_1113 ) ;
if ( F_53 ( V_6 ) < 8 ) {
F_801 ( V_679 ) ;
if ( V_1112 -> V_677 )
F_801 ( V_680 ) ;
} else
F_802 ( V_679 , V_680 ) ;
F_798 ( V_1099 ) ;
F_799 ( V_49 . V_76 . V_541 ) ;
F_799 ( V_49 . V_76 . V_747 ) ;
F_799 ( V_49 . V_76 . V_748 ) ;
F_799 ( V_49 . V_76 . V_749 ) ;
F_799 ( V_49 . V_76 . V_648 ) ;
F_799 ( V_49 . V_76 . V_750 ) ;
F_799 ( V_49 . V_76 . V_542 ) ;
F_799 ( V_49 . V_76 . V_743 ) ;
F_799 ( V_49 . V_76 . V_751 ) ;
F_799 ( V_49 . V_76 . V_744 ) ;
F_799 ( V_49 . V_76 . V_752 ) ;
F_799 ( V_49 . V_76 . V_753 ) ;
F_799 ( V_585 ) ;
F_799 ( V_1114 ) ;
if ( ( F_53 ( V_6 ) < 8 && ! F_252 ( V_6 ) ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
F_799 ( V_775 ) ;
F_799 ( V_1115 ) ;
F_799 ( V_1116 ) ;
F_799 ( V_1086 ) ;
F_799 ( V_607 ) ;
F_803 ( V_49 . V_76 . V_315 ,
V_746 ) ;
if ( ! F_805 ( V_1117 ) ) {
F_803 ( V_49 . V_76 . V_315 ,
V_523 ) ;
F_803 ( V_49 . V_76 . V_315 ,
V_1097 ) ;
F_803 ( V_49 . V_76 . V_315 ,
V_525 ) ;
F_803 ( V_49 . V_76 . V_315 ,
V_1098 ) ;
}
F_798 ( V_590 . V_591 ) ;
if ( F_53 ( V_6 ) < 4 )
F_798 ( V_590 . V_595 ) ;
F_798 ( V_590 . V_1087 ) ;
if ( ! V_1111 ) {
F_799 ( V_368 ) ;
F_799 ( V_367 ) ;
F_799 ( V_441 . V_131 ) ;
if ( V_1112 -> V_441 . V_131 ) {
F_798 ( V_441 . V_545 ) ;
F_798 ( V_441 . V_227 ) ;
}
F_799 ( V_371 . V_407 ) ;
F_804 ( V_638 ) ;
}
if ( F_252 ( V_6 ) )
F_799 ( V_548 ) ;
F_799 ( V_211 ) ;
F_800 ( V_191 ) ;
F_798 ( V_159 . V_30 ) ;
F_798 ( V_159 . V_161 ) ;
F_798 ( V_159 . V_616 ) ;
F_798 ( V_159 . V_617 ) ;
F_798 ( V_159 . V_1118 ) ;
F_798 ( V_159 . V_1119 ) ;
F_798 ( V_159 . V_1120 ) ;
F_798 ( V_159 . V_1121 ) ;
F_798 ( V_159 . V_1122 ) ;
F_798 ( V_1123 . V_1124 ) ;
F_798 ( V_1123 . div ) ;
if ( F_249 ( V_6 ) || F_53 ( V_6 ) >= 5 )
F_799 ( V_635 ) ;
F_804 ( V_49 . V_76 . V_77 ) ;
F_804 ( V_24 ) ;
#undef F_798
#undef F_799
#undef F_800
#undef F_803
#undef F_804
#undef F_805
return V_349 ;
}
static void F_806 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
if ( V_23 -> V_207 ) {
int V_633 = F_689 ( F_14 ( V_6 , V_23 ) ,
& V_23 -> V_582 ) ;
int V_1125 = V_23 -> V_49 . V_76 . V_77 ;
F_7 ( ! F_794 ( V_633 , V_1125 ) ,
L_190 ,
V_633 , V_1125 ) ;
}
}
static void F_807 ( struct V_130 * V_50 ,
struct V_27 * V_1126 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_1127 V_1128 , * V_1129 ;
struct V_1130 V_1131 , * V_1132 ;
struct V_1133 * V_1134 , * V_1135 ;
struct V_1136 * V_1137 , * V_1138 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
const enum V_79 V_79 = V_66 -> V_79 ;
int V_118 , V_1139 , V_1140 = F_808 ( V_6 ) ;
if ( F_53 ( V_6 ) < 9 || ! V_1126 -> V_72 )
return;
F_809 ( V_50 , & V_1131 ) ;
V_1132 = & F_235 ( V_1126 ) -> V_1075 . V_1141 . V_1078 ;
F_810 ( V_6 , & V_1128 ) ;
V_1129 = & V_6 -> V_1075 . V_1142 . V_1143 ;
F_811 (dev_priv, pipe, plane) {
V_1134 = & V_1131 . V_1144 [ V_118 ] ;
V_1135 = & V_1132 -> V_1144 [ V_118 ] ;
for ( V_1139 = 0 ; V_1139 <= V_1140 ; V_1139 ++ ) {
if ( F_812 ( & V_1134 -> V_1075 [ V_1139 ] ,
& V_1135 -> V_1075 [ V_1139 ] ) )
continue;
F_122 ( L_191 ,
F_73 ( V_79 ) , V_118 + 1 , V_1139 ,
V_1135 -> V_1075 [ V_1139 ] . V_1145 ,
V_1135 -> V_1075 [ V_1139 ] . V_1146 ,
V_1135 -> V_1075 [ V_1139 ] . V_1147 ,
V_1134 -> V_1075 [ V_1139 ] . V_1145 ,
V_1134 -> V_1075 [ V_1139 ] . V_1146 ,
V_1134 -> V_1075 [ V_1139 ] . V_1147 ) ;
}
if ( ! F_812 ( & V_1134 -> V_1148 ,
& V_1135 -> V_1148 ) ) {
F_122 ( L_192 ,
F_73 ( V_79 ) , V_118 + 1 ,
V_1135 -> V_1148 . V_1145 ,
V_1135 -> V_1148 . V_1146 ,
V_1135 -> V_1148 . V_1147 ,
V_1134 -> V_1148 . V_1145 ,
V_1134 -> V_1148 . V_1146 ,
V_1134 -> V_1148 . V_1147 ) ;
}
V_1137 = & V_1128 . V_118 [ V_79 ] [ V_118 ] ;
V_1138 = & V_1129 -> V_118 [ V_79 ] [ V_118 ] ;
if ( ! F_813 ( V_1137 , V_1138 ) ) {
F_122 ( L_193 ,
F_73 ( V_79 ) , V_118 + 1 ,
V_1138 -> V_1149 , V_1138 -> V_1150 ,
V_1137 -> V_1149 , V_1137 -> V_1150 ) ;
}
}
if ( V_66 -> V_957 ) {
V_1134 = & V_1131 . V_1144 [ V_1066 ] ;
V_1135 = & V_1132 -> V_1144 [ V_1066 ] ;
for ( V_1139 = 0 ; V_1139 <= V_1140 ; V_1139 ++ ) {
if ( F_812 ( & V_1134 -> V_1075 [ V_1139 ] ,
& V_1135 -> V_1075 [ V_1139 ] ) )
continue;
F_122 ( L_194 ,
F_73 ( V_79 ) , V_1139 ,
V_1135 -> V_1075 [ V_1139 ] . V_1145 ,
V_1135 -> V_1075 [ V_1139 ] . V_1146 ,
V_1135 -> V_1075 [ V_1139 ] . V_1147 ,
V_1134 -> V_1075 [ V_1139 ] . V_1145 ,
V_1134 -> V_1075 [ V_1139 ] . V_1146 ,
V_1134 -> V_1075 [ V_1139 ] . V_1147 ) ;
}
if ( ! F_812 ( & V_1134 -> V_1148 ,
& V_1135 -> V_1148 ) ) {
F_122 ( L_195 ,
F_73 ( V_79 ) ,
V_1135 -> V_1148 . V_1145 ,
V_1135 -> V_1148 . V_1146 ,
V_1135 -> V_1148 . V_1147 ,
V_1134 -> V_1148 . V_1145 ,
V_1134 -> V_1148 . V_1146 ,
V_1134 -> V_1148 . V_1147 ) ;
}
V_1137 = & V_1128 . V_118 [ V_79 ] [ V_1066 ] ;
V_1138 = & V_1129 -> V_118 [ V_79 ] [ V_1066 ] ;
if ( ! F_813 ( V_1137 , V_1138 ) ) {
F_122 ( L_196 ,
F_73 ( V_79 ) ,
V_1138 -> V_1149 , V_1138 -> V_1150 ,
V_1137 -> V_1149 , V_1137 -> V_1150 ) ;
}
}
}
static void
F_814 ( struct V_47 * V_48 ,
struct V_419 * V_28 ,
struct V_130 * V_50 )
{
struct V_572 * V_624 ;
struct V_570 * V_1151 ;
int V_120 ;
F_428 (state, connector, new_conn_state, i) {
struct V_604 * V_510 = V_624 -> V_510 ;
if ( V_1151 -> V_50 != V_50 )
continue;
F_500 ( F_774 ( V_624 ) ) ;
F_59 ( V_1151 -> V_574 != V_510 ,
L_197 ) ;
}
}
static void
F_815 ( struct V_47 * V_48 , struct V_419 * V_28 )
{
struct V_509 * V_510 ;
struct V_572 * V_624 ;
struct V_570 * V_577 , * V_1151 ;
int V_120 ;
F_589 (dev, encoder) {
bool V_131 = false , V_60 = false ;
enum V_79 V_79 ;
F_156 ( L_198 ,
V_510 -> V_49 . V_49 . V_324 ,
V_510 -> V_49 . V_12 ) ;
F_816 (state, connector, old_conn_state,
new_conn_state, i) {
if ( V_577 -> V_574 == & V_510 -> V_49 )
V_60 = true ;
if ( V_1151 -> V_574 != & V_510 -> V_49 )
continue;
V_60 = V_131 = true ;
F_59 ( V_1151 -> V_50 !=
V_510 -> V_49 . V_50 ,
L_199 ) ;
}
if ( ! V_60 )
continue;
F_59 ( ! ! V_510 -> V_49 . V_50 != V_131 ,
L_200
L_201 ,
! ! V_510 -> V_49 . V_50 , V_131 ) ;
if ( ! V_510 -> V_49 . V_50 ) {
bool V_72 ;
V_72 = V_510 -> V_625 ( V_510 , & V_79 ) ;
F_59 ( V_72 ,
L_202 ,
F_73 ( V_79 ) ) ;
}
}
}
static void
F_817 ( struct V_130 * V_50 ,
struct V_27 * V_440 ,
struct V_27 * V_1104 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_509 * V_510 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 , * V_1152 ;
struct V_419 * V_557 ;
bool V_72 ;
V_557 = V_440 -> V_28 ;
F_818 ( V_440 ) ;
V_23 = F_235 ( V_440 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_49 . V_50 = V_50 ;
V_23 -> V_49 . V_28 = V_557 ;
F_156 ( L_203 , V_50 -> V_49 . V_324 , V_50 -> V_12 ) ;
V_72 = V_6 -> V_432 . V_1153 ( V_66 , V_23 ) ;
if ( ( V_66 -> V_79 == V_98 && V_6 -> V_114 & V_115 ) ||
( V_66 -> V_79 == V_105 && V_6 -> V_114 & V_116 ) )
V_72 = V_1104 -> V_72 ;
F_59 ( V_1104 -> V_72 != V_72 ,
L_204
L_201 , V_1104 -> V_72 , V_72 ) ;
F_59 ( V_66 -> V_72 != V_1104 -> V_72 ,
L_205
L_201 , V_1104 -> V_72 , V_66 -> V_72 ) ;
F_384 (dev, crtc, encoder) {
enum V_79 V_79 ;
V_72 = V_510 -> V_625 ( V_510 , & V_79 ) ;
F_59 ( V_72 != V_1104 -> V_72 ,
L_206 ,
V_510 -> V_49 . V_49 . V_324 , V_72 , V_1104 -> V_72 ) ;
F_59 ( V_72 && V_66 -> V_79 != V_79 ,
L_207 ,
F_73 ( V_79 ) ) ;
if ( V_72 ) {
V_23 -> V_1099 |= 1 << V_510 -> type ;
V_510 -> V_1154 ( V_510 , V_23 ) ;
}
}
F_516 ( V_23 ) ;
if ( ! V_1104 -> V_72 )
return;
F_806 ( V_6 , V_23 ) ;
V_1152 = F_235 ( V_50 -> V_28 ) ;
if ( ! F_797 ( V_6 , V_1152 ,
V_23 , false ) ) {
F_59 ( 1 , L_208 ) ;
F_777 ( V_66 , V_23 ,
L_209 ) ;
F_777 ( V_66 , V_1152 ,
L_210 ) ;
}
}
static void
F_819 ( struct V_5 * V_6 ,
struct V_857 * V_858 ,
struct V_130 * V_50 ,
struct V_27 * V_1126 )
{
struct V_1093 V_159 ;
unsigned V_1155 ;
bool V_72 ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
F_156 ( L_211 , V_858 -> V_12 ) ;
V_72 = V_858 -> V_876 . V_625 ( V_6 , V_858 , & V_159 ) ;
if ( ! ( V_858 -> V_315 & V_1156 ) ) {
F_59 ( ! V_858 -> V_1157 && V_858 -> V_1158 ,
L_212 ) ;
F_59 ( V_858 -> V_1157 && ! V_858 -> V_1158 ,
L_213 ) ;
F_59 ( V_858 -> V_1157 != V_72 ,
L_214 ,
V_858 -> V_1157 , V_72 ) ;
}
if ( ! V_50 ) {
F_59 ( V_858 -> V_1158 & ~ V_858 -> V_28 . V_1155 ,
L_215 ,
V_858 -> V_1158 , V_858 -> V_28 . V_1155 ) ;
return;
}
V_1155 = 1 << F_820 ( V_50 ) ;
if ( V_1126 -> V_72 )
F_59 ( ! ( V_858 -> V_1158 & V_1155 ) ,
L_216 ,
F_73 ( F_820 ( V_50 ) ) , V_858 -> V_1158 ) ;
else
F_59 ( V_858 -> V_1158 & V_1155 ,
L_217 ,
F_73 ( F_820 ( V_50 ) ) , V_858 -> V_1158 ) ;
F_59 ( ! ( V_858 -> V_28 . V_1155 & V_1155 ) ,
L_218 ,
V_1155 , V_858 -> V_28 . V_1155 ) ;
F_59 ( V_858 -> V_1157 && memcmp ( & V_858 -> V_28 . V_1159 ,
& V_159 ,
sizeof( V_159 ) ) ,
L_219 ) ;
}
static void
F_821 ( struct V_47 * V_48 , struct V_130 * V_50 ,
struct V_27 * V_440 ,
struct V_27 * V_1104 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_22 * V_557 = F_235 ( V_440 ) ;
struct V_22 * V_1126 = F_235 ( V_1104 ) ;
if ( V_1126 -> V_191 )
F_819 ( V_6 , V_1126 -> V_191 , V_50 , V_1104 ) ;
if ( V_557 -> V_191 &&
V_557 -> V_191 != V_1126 -> V_191 ) {
unsigned V_1155 = 1 << F_820 ( V_50 ) ;
struct V_857 * V_858 = V_557 -> V_191 ;
F_59 ( V_858 -> V_1158 & V_1155 ,
L_220 ,
F_73 ( F_820 ( V_50 ) ) ) ;
F_59 ( V_858 -> V_28 . V_1155 & V_1155 ,
L_221 ,
F_73 ( F_820 ( V_50 ) ) ) ;
}
}
static void
F_822 ( struct V_130 * V_50 ,
struct V_419 * V_28 ,
struct V_27 * V_557 ,
struct V_27 * V_1126 )
{
if ( ! F_18 ( V_1126 ) &&
! F_235 ( V_1126 ) -> V_1160 )
return;
F_807 ( V_50 , V_1126 ) ;
F_814 ( V_50 -> V_48 , V_28 , V_50 ) ;
F_817 ( V_50 , V_557 , V_1126 ) ;
F_821 ( V_50 -> V_48 , V_50 , V_557 , V_1126 ) ;
}
static void
F_823 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_6 -> V_813 ; V_120 ++ )
F_819 ( V_6 , & V_6 -> V_1161 [ V_120 ] , NULL , NULL ) ;
}
static void
F_824 ( struct V_47 * V_48 ,
struct V_419 * V_28 )
{
F_815 ( V_48 , V_28 ) ;
F_814 ( V_48 , V_28 , NULL ) ;
F_823 ( V_48 ) ;
}
static void F_825 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
if ( F_50 ( V_6 ) ) {
const struct V_518 * V_76 = & V_50 -> V_75 -> V_49 . V_76 ;
int V_759 ;
V_759 = V_76 -> V_743 ;
if ( V_76 -> V_315 & V_746 )
V_759 /= 2 ;
V_50 -> V_210 = V_759 - 1 ;
} else if ( F_15 ( V_6 ) &&
F_32 ( V_50 -> V_75 , V_194 ) ) {
V_50 -> V_210 = 2 ;
} else
V_50 -> V_210 = 1 ;
}
static void F_826 ( struct V_419 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_130 * V_50 ;
struct V_27 * V_440 , * V_1104 ;
int V_120 ;
if ( ! V_6 -> V_432 . V_1070 )
return;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_857 * V_1162 =
F_235 ( V_440 ) -> V_191 ;
if ( ! F_18 ( V_1104 ) )
continue;
F_235 ( V_1104 ) -> V_191 = NULL ;
if ( ! V_1162 )
continue;
F_828 ( V_1162 , V_66 , V_28 ) ;
}
}
static int F_829 ( struct V_419 * V_28 )
{
struct V_27 * V_45 ;
struct V_66 * V_66 ;
struct V_130 * V_50 ;
struct V_22 * V_1163 = NULL ;
struct V_22 * V_629 = NULL ;
enum V_79 V_1164 = V_587 , V_1165 = V_587 ;
int V_120 ;
F_301 (state, crtc, crtc_state, i) {
V_66 = F_42 ( V_50 ) ;
if ( ! V_45 -> V_72 || ! F_18 ( V_45 ) )
continue;
if ( V_1163 ) {
V_629 = F_235 ( V_45 ) ;
break;
} else {
V_1163 = F_235 ( V_45 ) ;
V_1164 = V_66 -> V_79 ;
}
}
if ( ! V_1163 )
return 0 ;
F_133 (state->dev, intel_crtc) {
struct V_22 * V_23 ;
V_23 = F_490 ( V_28 , V_66 ) ;
if ( F_188 ( V_23 ) )
return F_238 ( V_23 ) ;
V_23 -> V_583 = V_587 ;
if ( ! V_23 -> V_49 . V_72 ||
F_18 ( & V_23 -> V_49 ) )
continue;
if ( V_1165 != V_587 )
return 0 ;
V_1165 = V_66 -> V_79 ;
}
if ( V_1165 != V_587 )
V_1163 -> V_583 = V_1165 ;
else if ( V_629 )
V_629 -> V_583 = V_1164 ;
return 0 ;
}
static int F_830 ( struct V_419 * V_28 )
{
struct V_130 * V_50 ;
F_233 (state->dev, crtc) {
struct V_27 * V_45 ;
V_45 = F_684 ( V_28 , V_50 ) ;
if ( F_188 ( V_45 ) )
return F_238 ( V_45 ) ;
}
return 0 ;
}
static int F_831 ( struct V_419 * V_28 )
{
struct V_130 * V_50 ;
F_233 (state->dev, crtc) {
struct V_27 * V_45 ;
int V_349 ;
V_45 = F_684 ( V_28 , V_50 ) ;
if ( F_188 ( V_45 ) )
return F_238 ( V_45 ) ;
if ( ! V_45 -> V_72 || F_18 ( V_45 ) )
continue;
V_45 -> V_422 = true ;
V_349 = F_491 ( V_28 , V_50 ) ;
if ( V_349 )
return V_349 ;
V_349 = F_832 ( V_28 , V_50 ) ;
if ( V_349 )
return V_349 ;
}
return 0 ;
}
static int F_833 ( struct V_419 * V_28 )
{
struct V_564 * V_327 = F_302 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_28 -> V_48 ) ;
struct V_130 * V_50 ;
struct V_27 * V_440 , * V_1104 ;
int V_349 = 0 , V_120 ;
if ( ! F_784 ( V_28 ) ) {
F_156 ( L_222 ) ;
return - V_272 ;
}
V_327 -> V_563 = true ;
V_327 -> V_621 = V_6 -> V_621 ;
V_327 -> V_1166 . V_1167 = V_6 -> V_1166 . V_1167 ;
V_327 -> V_1166 . V_1168 = V_6 -> V_1166 . V_1168 ;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( V_1104 -> V_72 )
V_327 -> V_621 |= 1 << V_120 ;
else
V_327 -> V_621 &= ~ ( 1 << V_120 ) ;
if ( V_440 -> V_72 != V_1104 -> V_72 )
V_327 -> V_1169 |= F_834 ( V_50 ) ;
}
if ( V_6 -> V_432 . V_1170 ) {
V_349 = V_6 -> V_432 . V_1170 ( V_28 ) ;
if ( V_349 < 0 )
return V_349 ;
if ( ! F_835 ( & V_6 -> V_1166 . V_1167 ,
& V_327 -> V_1166 . V_1167 ) ) {
V_349 = F_830 ( V_28 ) ;
if ( V_349 < 0 )
return V_349 ;
}
if ( ! F_835 ( & V_6 -> V_1166 . V_1168 ,
& V_327 -> V_1166 . V_1168 ) ) {
V_349 = F_831 ( V_28 ) ;
if ( V_349 < 0 )
return V_349 ;
}
F_156 ( L_223 ,
V_327 -> V_1166 . V_1167 . V_1166 ,
V_327 -> V_1166 . V_1168 . V_1166 ) ;
} else {
F_302 ( V_28 ) -> V_1166 . V_1167 = V_6 -> V_1166 . V_1167 ;
}
F_826 ( V_28 ) ;
if ( F_252 ( V_6 ) )
return F_829 ( V_28 ) ;
return 0 ;
}
static int F_836 ( struct V_419 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( V_6 -> V_432 . V_1171 )
return V_6 -> V_432 . V_1171 ( V_28 ) ;
return 0 ;
}
static int F_837 ( struct V_47 * V_48 ,
struct V_419 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_564 * V_327 = F_302 ( V_28 ) ;
struct V_130 * V_50 ;
struct V_27 * V_440 , * V_45 ;
int V_349 , V_120 ;
bool V_1172 = false ;
V_349 = F_838 ( V_48 , V_28 ) ;
if ( V_349 )
return V_349 ;
F_827 (state, crtc, old_crtc_state, crtc_state, i) {
struct V_22 * V_23 =
F_235 ( V_45 ) ;
if ( V_45 -> V_417 . V_1173 != V_440 -> V_417 . V_1173 )
V_45 -> V_422 = true ;
if ( ! F_18 ( V_45 ) )
continue;
if ( ! V_45 -> V_505 ) {
V_1172 = true ;
continue;
}
V_349 = F_491 ( V_28 , V_50 ) ;
if ( V_349 )
return V_349 ;
V_349 = F_791 ( V_50 , V_23 ) ;
if ( V_349 ) {
F_777 ( F_42 ( V_50 ) ,
V_23 , L_224 ) ;
return V_349 ;
}
if ( V_244 . V_1174 &&
F_797 ( V_6 ,
F_235 ( V_440 ) ,
V_23 , true ) ) {
V_45 -> V_422 = false ;
V_23 -> V_1160 = true ;
}
if ( F_18 ( V_45 ) )
V_1172 = true ;
V_349 = F_832 ( V_28 , V_50 ) ;
if ( V_349 )
return V_349 ;
F_777 ( F_42 ( V_50 ) , V_23 ,
F_18 ( V_45 ) ?
L_225 : L_226 ) ;
}
if ( V_1172 ) {
V_349 = F_833 ( V_28 ) ;
if ( V_349 )
return V_349 ;
} else {
V_327 -> V_1166 . V_1167 = V_6 -> V_1166 . V_1167 ;
}
V_349 = F_839 ( V_48 , V_28 ) ;
if ( V_349 )
return V_349 ;
F_840 ( V_6 , V_28 ) ;
return F_836 ( V_28 ) ;
}
static int F_841 ( struct V_47 * V_48 ,
struct V_419 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_27 * V_45 ;
struct V_130 * V_50 ;
int V_120 , V_349 ;
F_301 (state, crtc, crtc_state, i) {
if ( V_28 -> V_1175 )
continue;
V_349 = F_353 ( V_50 ) ;
if ( V_349 )
return V_349 ;
if ( F_346 ( & F_42 ( V_50 ) -> V_475 ) >= 2 )
F_743 ( V_6 -> V_479 ) ;
}
V_349 = F_842 ( & V_48 -> V_242 ) ;
if ( V_349 )
return V_349 ;
V_349 = F_843 ( V_48 , V_28 ) ;
F_5 ( & V_48 -> V_242 ) ;
return V_349 ;
}
T_1 F_705 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
if ( ! V_48 -> V_209 )
return F_844 ( & V_50 -> V_49 ) ;
return V_48 -> V_1176 -> V_1177 ( V_48 , V_50 -> V_79 ) ;
}
static void F_845 ( struct V_47 * V_48 ,
struct V_5 * V_6 ,
unsigned V_1155 )
{
unsigned V_1178 [ V_1179 ] ;
enum V_79 V_79 ;
int V_349 ;
if ( ! V_1155 )
return;
F_86 (dev_priv, pipe) {
struct V_66 * V_50 = F_47 ( V_6 ,
V_79 ) ;
if ( ! ( ( 1 << V_79 ) & V_1155 ) )
continue;
V_349 = F_96 ( & V_50 -> V_49 ) ;
if ( F_21 ( V_349 != 0 ) ) {
V_1155 &= ~ ( 1 << V_79 ) ;
continue;
}
V_1178 [ V_79 ] = F_846 ( & V_50 -> V_49 ) ;
}
F_86 (dev_priv, pipe) {
struct V_66 * V_50 = F_47 ( V_6 ,
V_79 ) ;
long V_1180 ;
if ( ! ( ( 1 << V_79 ) & V_1155 ) )
continue;
V_1180 = F_847 ( V_48 -> V_1038 [ V_79 ] . V_1181 ,
V_1178 [ V_79 ] !=
F_846 ( & V_50 -> V_49 ) ,
F_848 ( 50 ) ) ;
F_7 ( ! V_1180 , L_227 , F_73 ( V_79 ) ) ;
F_97 ( & V_50 -> V_49 ) ;
}
}
static bool F_849 ( struct V_22 * V_45 )
{
if ( V_45 -> V_1067 )
return true ;
if ( V_45 -> V_560 )
return true ;
if ( V_45 -> V_1075 . V_1182 )
return true ;
return false ;
}
static void F_850 ( struct V_130 * V_50 ,
struct V_419 * V_28 ,
struct V_27 * V_440 ,
struct V_27 * V_1104 ,
unsigned int * V_1183 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 = F_235 ( V_1104 ) ;
bool V_563 = F_18 ( V_1104 ) ;
if ( V_563 ) {
F_825 ( V_66 ) ;
V_6 -> V_432 . V_1184 ( V_23 , V_28 ) ;
} else {
F_421 ( F_235 ( V_440 ) ,
V_23 ) ;
}
if ( F_417 ( V_28 , V_50 -> V_73 ) ) {
F_851 (
V_66 , V_23 ,
F_231 ( V_50 -> V_73 -> V_28 ) ) ;
}
F_852 ( V_440 ) ;
if ( F_849 ( V_23 ) )
* V_1183 |= F_834 ( V_50 ) ;
}
static void F_853 ( struct V_419 * V_28 ,
unsigned int * V_1183 )
{
struct V_130 * V_50 ;
struct V_27 * V_440 , * V_1104 ;
int V_120 ;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_1104 -> V_72 )
continue;
F_850 ( V_50 , V_28 , V_440 ,
V_1104 , V_1183 ) ;
}
}
static void F_854 ( struct V_419 * V_28 ,
unsigned int * V_1183 )
{
struct V_5 * V_6 = F_35 ( V_28 -> V_48 ) ;
struct V_564 * V_327 = F_302 ( V_28 ) ;
struct V_130 * V_50 ;
struct V_66 * V_66 ;
struct V_27 * V_440 , * V_1104 ;
struct V_22 * V_1185 ;
unsigned int V_1186 = 0 ;
bool V_1187 ;
enum V_79 V_79 ;
int V_120 ;
const struct V_1136 * V_1188 [ V_1179 ] = {} ;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i)
if ( V_1104 -> V_72 )
V_1188 [ V_120 ] = & F_235 ( V_440 ) -> V_1075 . V_1141 . V_1143 ;
do {
V_1187 = false ;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
bool V_1189 = false ;
unsigned int V_1190 = F_834 ( V_50 ) ;
V_66 = F_42 ( V_50 ) ;
V_1185 = F_235 ( V_50 -> V_28 ) ;
V_79 = V_66 -> V_79 ;
if ( V_1186 & V_1190 || ! V_1185 -> V_49 . V_72 )
continue;
if ( F_855 ( V_1188 , & V_1185 -> V_1075 . V_1141 . V_1143 , V_120 ) )
continue;
V_1186 |= V_1190 ;
V_1188 [ V_120 ] = & V_1185 -> V_1075 . V_1141 . V_1143 ;
if ( ! F_813 ( & V_1185 -> V_1075 . V_1141 . V_1143 ,
& F_235 ( V_440 ) -> V_1075 . V_1141 . V_1143 ) &&
! V_1104 -> V_1191 &&
V_327 -> V_1192 . V_1193 != V_1186 )
V_1189 = true ;
F_850 ( V_50 , V_28 , V_440 ,
V_1104 , V_1183 ) ;
if ( V_1189 )
F_347 ( V_6 , V_79 ) ;
V_1187 = true ;
}
} while ( V_1187 );
}
static void F_856 ( struct V_5 * V_6 )
{
struct V_564 * V_28 , * V_1194 ;
struct V_1195 * V_1196 ;
V_1196 = F_857 ( & V_6 -> V_1197 . V_1198 ) ;
F_858 (state, next, freed, freed)
F_312 ( & V_28 -> V_49 ) ;
}
static void F_859 ( struct V_994 * V_2 )
{
struct V_5 * V_6 =
F_695 ( V_2 , F_860 ( * V_6 ) , V_1197 . V_1046 ) ;
F_856 ( V_6 ) ;
}
static void F_861 ( struct V_419 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_564 * V_327 = F_302 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_27 * V_440 , * V_1104 ;
struct V_130 * V_50 ;
struct V_22 * V_1199 ;
bool V_1200 = V_327 -> V_563 ;
T_4 V_1201 [ V_1179 ] = {} ;
unsigned V_1183 = 0 ;
int V_120 ;
F_862 ( V_28 ) ;
if ( V_327 -> V_563 )
F_474 ( V_6 , V_1202 ) ;
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
if ( F_18 ( V_1104 ) ||
F_235 ( V_1104 ) -> V_1160 ) {
V_1200 = true ;
V_1201 [ F_42 ( V_50 ) -> V_79 ] =
F_472 ( V_50 ,
F_235 ( V_1104 ) ) ;
}
if ( ! F_18 ( V_1104 ) )
continue;
F_421 ( F_235 ( V_440 ) ,
F_235 ( V_1104 ) ) ;
if ( V_440 -> V_72 ) {
F_424 ( V_50 , V_440 -> V_322 ) ;
V_6 -> V_432 . V_618 ( F_235 ( V_440 ) , V_28 ) ;
V_66 -> V_72 = false ;
F_493 ( V_66 ) ;
F_494 ( V_66 ) ;
F_412 ( V_6 ) ;
F_413 ( V_6 ) ;
if ( ! V_50 -> V_28 -> V_72 ) {
if ( F_53 ( V_6 ) >= 9 )
V_6 -> V_432 . V_568 ( V_327 ,
F_235 ( V_50 -> V_28 ) ) ;
}
}
}
F_793 ( V_28 ) ;
if ( V_327 -> V_563 ) {
F_863 ( V_28 -> V_48 , V_28 ) ;
F_864 ( V_6 , & V_6 -> V_1166 . V_1168 ) ;
if ( ! F_865 ( V_28 ) )
F_866 ( V_6 ) ;
F_824 ( V_48 , V_28 ) ;
}
F_301 (state, crtc, new_crtc_state, i) {
bool V_563 = F_18 ( V_1104 ) ;
if ( V_563 && ! V_1104 -> V_72 && V_1104 -> V_476 ) {
F_318 ( & V_48 -> V_438 ) ;
F_349 ( V_50 , V_1104 -> V_476 ) ;
F_319 ( & V_48 -> V_438 ) ;
V_1104 -> V_476 = NULL ;
}
}
V_6 -> V_432 . V_1203 ( V_28 , & V_1183 ) ;
if ( ! V_28 -> V_1175 )
F_845 ( V_48 , V_6 , V_1183 ) ;
F_301 (state, crtc, new_crtc_state, i) {
V_1199 = F_235 ( V_1104 ) ;
if ( V_6 -> V_432 . V_1204 )
V_6 -> V_432 . V_1204 ( V_327 ,
V_1199 ) ;
}
F_827 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_416 ( F_235 ( V_440 ) ) ;
if ( V_1201 [ V_120 ] )
F_475 ( V_6 , V_1201 [ V_120 ] ) ;
F_822 ( V_50 , V_28 , V_440 , V_1104 ) ;
}
if ( V_327 -> V_563 && F_865 ( V_28 ) )
F_867 ( V_6 ) ;
F_868 ( V_28 ) ;
if ( V_327 -> V_563 )
F_81 ( V_6 , V_1202 ) ;
F_3 ( & V_48 -> V_242 ) ;
F_869 ( V_48 , V_28 ) ;
F_5 ( & V_48 -> V_242 ) ;
F_870 ( V_28 ) ;
F_312 ( V_28 ) ;
F_871 ( V_6 ) ;
F_856 ( V_6 ) ;
}
static void F_872 ( struct V_994 * V_2 )
{
struct V_419 * V_28 =
F_695 ( V_2 , struct V_419 , V_1205 ) ;
F_861 ( V_28 ) ;
}
static int T_8
F_873 ( struct V_1206 * V_1207 ,
enum V_1208 V_1209 )
{
struct V_564 * V_28 =
F_695 ( V_1207 , struct V_564 , V_1210 ) ;
switch ( V_1209 ) {
case V_1211 :
if ( V_28 -> V_49 . V_1205 . V_4 )
F_352 ( V_1052 , & V_28 -> V_49 . V_1205 ) ;
break;
case V_1212 :
{
struct V_1213 * V_1214 =
& F_35 ( V_28 -> V_49 . V_48 ) -> V_1197 ;
if ( F_874 ( & V_28 -> V_1196 , & V_1214 -> V_1198 ) )
F_875 ( & V_1214 -> V_1046 ) ;
break;
}
}
return V_1215 ;
}
static void F_876 ( struct V_419 * V_28 )
{
struct V_326 * V_1060 , * V_1216 ;
struct V_318 * V_118 ;
int V_120 ;
F_877 (state, plane, old_plane_state, new_plane_state, i)
F_753 ( F_183 ( V_1060 -> V_74 ) ,
F_183 ( V_1216 -> V_74 ) ,
F_227 ( V_118 ) -> V_341 ) ;
}
static int F_878 ( struct V_47 * V_48 ,
struct V_419 * V_28 ,
bool V_1217 )
{
struct V_564 * V_327 = F_302 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_349 = 0 ;
V_349 = F_879 ( V_28 , V_1217 ) ;
if ( V_349 )
return V_349 ;
F_880 ( V_28 ) ;
F_881 ( & V_327 -> V_1210 ,
F_873 ) ;
V_349 = F_841 ( V_48 , V_28 ) ;
if ( V_349 ) {
F_760 ( L_228 , V_349 ) ;
F_882 ( & V_327 -> V_1210 ) ;
return V_349 ;
}
if ( F_53 ( V_6 ) < 9 )
V_28 -> V_1175 = false ;
F_883 ( V_28 , true ) ;
V_6 -> V_1075 . V_1218 = false ;
F_884 ( V_28 ) ;
F_876 ( V_28 ) ;
if ( V_327 -> V_563 ) {
memcpy ( V_6 -> V_622 , V_327 -> V_622 ,
sizeof( V_327 -> V_622 ) ) ;
V_6 -> V_621 = V_327 -> V_621 ;
V_6 -> V_1166 . V_1167 = V_327 -> V_1166 . V_1167 ;
V_6 -> V_1166 . V_1168 = V_327 -> V_1166 . V_1168 ;
}
F_880 ( V_28 ) ;
F_742 ( & V_28 -> V_1205 ,
V_1217 ? F_872 : NULL ) ;
F_882 ( & V_327 -> V_1210 ) ;
if ( ! V_1217 ) {
F_885 ( & V_327 -> V_1210 ) ;
F_861 ( V_28 ) ;
}
return 0 ;
}
void F_886 ( struct V_130 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_419 * V_28 ;
struct V_27 * V_45 ;
int V_349 ;
V_28 = F_489 ( V_48 ) ;
if ( ! V_28 ) {
F_156 ( L_229 ,
V_50 -> V_49 . V_324 , V_50 -> V_12 ) ;
return;
}
V_28 -> V_430 = V_50 -> V_48 -> V_426 . V_430 ;
V_460:
V_45 = F_684 ( V_28 , V_50 ) ;
V_349 = F_497 ( V_45 ) ;
if ( ! V_349 ) {
if ( ! V_45 -> V_72 )
goto V_802;
V_45 -> V_422 = true ;
V_349 = F_685 ( V_28 ) ;
}
if ( V_349 == - V_424 ) {
F_756 ( V_28 ) ;
F_309 ( V_28 -> V_430 ) ;
goto V_460;
}
V_802:
F_312 ( V_28 ) ;
}
int
F_887 ( struct V_318 * V_118 ,
struct V_326 * V_1126 )
{
struct V_564 * V_327 =
F_302 ( V_1126 -> V_28 ) ;
struct V_5 * V_6 = F_35 ( V_118 -> V_48 ) ;
struct V_213 * V_74 = V_1126 -> V_74 ;
struct V_238 * V_239 = F_183 ( V_74 ) ;
struct V_238 * V_1219 = F_183 ( V_118 -> V_28 -> V_74 ) ;
int V_349 ;
if ( V_239 ) {
if ( V_118 -> type == V_1220 &&
F_178 ( V_6 ) -> V_1221 ) {
const int V_1222 = F_136 ( V_6 ) ? 16 * 1024 : 256 ;
V_349 = F_888 ( V_239 , V_1222 ) ;
if ( V_349 ) {
F_156 ( L_230 ) ;
return V_349 ;
}
} else {
struct V_237 * V_240 ;
V_240 = F_182 ( V_74 , V_1126 -> V_231 ) ;
if ( F_188 ( V_240 ) ) {
F_156 ( L_231 ) ;
return F_238 ( V_240 ) ;
}
F_231 ( V_1126 ) -> V_240 = V_240 ;
}
}
if ( ! V_239 && ! V_1219 )
return 0 ;
if ( V_1219 ) {
struct V_27 * V_45 =
F_889 ( V_1126 -> V_28 ,
V_118 -> V_28 -> V_50 ) ;
if ( F_18 ( V_45 ) ) {
V_349 = F_890 ( & V_327 -> V_1210 ,
V_1219 -> V_1223 , NULL ,
false , 0 ,
V_627 ) ;
if ( V_349 < 0 )
return V_349 ;
}
}
if ( V_1126 -> V_1207 ) {
V_349 = F_891 ( & V_327 -> V_1210 ,
V_1126 -> V_1207 ,
V_1224 ,
V_627 ) ;
if ( V_349 < 0 )
return V_349 ;
}
if ( ! V_239 )
return 0 ;
if ( ! V_1126 -> V_1207 ) {
V_349 = F_890 ( & V_327 -> V_1210 ,
V_239 -> V_1223 , NULL ,
false , V_1224 ,
V_627 ) ;
if ( V_349 < 0 )
return V_349 ;
F_752 ( V_239 , 0 , V_1057 ) ;
}
return 0 ;
}
void
F_892 ( struct V_318 * V_118 ,
struct V_326 * V_557 )
{
struct V_237 * V_240 ;
V_240 = F_893 ( & F_231 ( V_557 ) -> V_240 ) ;
if ( V_240 )
F_194 ( V_240 ) ;
}
int
F_894 ( struct V_66 * V_66 , struct V_22 * V_45 )
{
struct V_5 * V_6 ;
int V_1225 ;
int V_77 , V_1226 ;
if ( ! V_66 || ! V_45 -> V_49 . V_505 )
return V_1227 ;
V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
V_77 = V_45 -> V_49 . V_76 . V_77 ;
V_1226 = F_302 ( V_45 -> V_49 . V_28 ) -> V_1166 . V_1167 . V_1166 ;
if ( F_283 ( V_6 ) )
V_1226 *= 2 ;
if ( F_39 ( ! V_77 || V_1226 < V_77 ) )
return V_1227 ;
V_1225 = V_43 ( ( 1 << 16 ) * 3 - 1 ,
( 1 << 8 ) * ( ( V_1226 << 8 ) / V_77 ) ) ;
return V_1225 ;
}
static int
F_895 ( struct V_318 * V_118 ,
struct V_22 * V_45 ,
struct V_250 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_118 -> V_48 ) ;
struct V_130 * V_50 = V_28 -> V_49 . V_50 ;
int V_1228 = V_1227 ;
int V_1225 = V_1227 ;
bool V_1229 = false ;
int V_349 ;
if ( F_53 ( V_6 ) >= 9 ) {
if ( V_28 -> V_396 . V_315 == V_543 ) {
V_1228 = 1 ;
V_1225 = F_894 ( F_42 ( V_50 ) , V_45 ) ;
}
V_1229 = true ;
}
V_349 = F_896 ( & V_28 -> V_49 ,
& V_28 -> V_1230 ,
V_1228 , V_1225 ,
V_1229 , true ) ;
if ( V_349 )
return V_349 ;
if ( ! V_28 -> V_49 . V_74 )
return 0 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_349 = F_247 ( V_28 ) ;
if ( V_349 )
return V_349 ;
V_28 -> V_360 = F_282 ( V_45 , V_28 ) ;
} else {
V_349 = F_254 ( V_28 ) ;
if ( V_349 )
return V_349 ;
V_28 -> V_360 = F_248 ( V_45 , V_28 ) ;
}
return 0 ;
}
static void F_897 ( struct V_130 * V_50 ,
struct V_27 * V_440 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_1199 =
F_235 ( V_50 -> V_28 ) ;
struct V_22 * V_1231 =
F_235 ( V_440 ) ;
struct V_564 * V_565 =
F_302 ( V_440 -> V_28 ) ;
bool V_563 = F_18 ( V_50 -> V_28 ) ;
if ( ! V_563 &&
( V_1199 -> V_49 . V_1071 ||
V_1199 -> V_1160 ) ) {
F_454 ( V_50 -> V_28 ) ;
F_445 ( V_50 -> V_28 ) ;
}
F_729 ( V_66 ) ;
if ( V_563 )
goto V_802;
if ( V_1199 -> V_1160 )
F_327 ( V_66 , V_1231 ) ;
else if ( F_53 ( V_6 ) >= 9 )
F_277 ( V_66 ) ;
V_802:
if ( V_6 -> V_432 . V_1232 )
V_6 -> V_432 . V_1232 ( V_565 ,
V_1199 ) ;
}
static void F_898 ( struct V_130 * V_50 ,
struct V_27 * V_440 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
F_730 ( V_66 , NULL ) ;
}
void F_899 ( struct V_318 * V_118 )
{
F_900 ( V_118 ) ;
F_232 ( F_227 ( V_118 ) ) ;
}
static int
F_901 ( struct V_318 * V_118 ,
struct V_130 * V_50 ,
struct V_213 * V_74 ,
int V_334 , int V_335 ,
unsigned int V_336 , unsigned int V_337 ,
T_2 V_330 , T_2 V_331 ,
T_2 V_332 , T_2 V_333 ,
struct V_420 * V_421 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
int V_349 ;
struct V_326 * V_1060 , * V_1216 ;
struct V_321 * V_321 = F_227 ( V_118 ) ;
struct V_213 * V_998 ;
struct V_27 * V_45 = V_50 -> V_28 ;
struct V_237 * V_996 ;
if ( ! V_45 -> V_72 || F_18 ( V_45 ) ||
F_235 ( V_45 ) -> V_1160 )
goto V_1233;
V_1060 = V_118 -> V_28 ;
if ( V_1060 -> V_50 != V_50 ||
V_1060 -> V_332 != V_332 ||
V_1060 -> V_333 != V_333 ||
V_1060 -> V_336 != V_336 ||
V_1060 -> V_337 != V_337 ||
! V_1060 -> V_74 != ! V_74 )
goto V_1233;
V_1216 = F_902 ( V_118 ) ;
if ( ! V_1216 )
return - V_626 ;
F_676 ( V_1216 , V_74 ) ;
V_1216 -> V_330 = V_330 ;
V_1216 -> V_331 = V_331 ;
V_1216 -> V_332 = V_332 ;
V_1216 -> V_333 = V_333 ;
V_1216 -> V_334 = V_334 ;
V_1216 -> V_335 = V_335 ;
V_1216 -> V_336 = V_336 ;
V_1216 -> V_337 = V_337 ;
V_349 = F_903 ( F_235 ( V_50 -> V_28 ) ,
F_231 ( V_1216 ) ) ;
if ( V_349 )
goto V_1234;
V_349 = F_842 ( & V_6 -> V_245 . V_242 ) ;
if ( V_349 )
goto V_1234;
if ( F_178 ( V_6 ) -> V_1221 ) {
int V_1222 = F_136 ( V_6 ) ? 16 * 1024 : 256 ;
V_349 = F_888 ( F_183 ( V_74 ) , V_1222 ) ;
if ( V_349 ) {
F_156 ( L_230 ) ;
goto V_1235;
}
} else {
struct V_237 * V_240 ;
V_240 = F_182 ( V_74 , V_1216 -> V_231 ) ;
if ( F_188 ( V_240 ) ) {
F_156 ( L_231 ) ;
V_349 = F_238 ( V_240 ) ;
goto V_1235;
}
F_231 ( V_1216 ) -> V_240 = V_240 ;
}
V_998 = V_1060 -> V_74 ;
V_996 = F_231 ( V_1060 ) -> V_240 ;
F_753 ( F_183 ( V_998 ) , F_183 ( V_74 ) ,
V_321 -> V_341 ) ;
V_1216 -> V_1207 = V_1060 -> V_1207 ;
* F_231 ( V_1060 ) = * F_231 ( V_1216 ) ;
V_1216 -> V_1207 = NULL ;
V_1216 -> V_74 = V_998 ;
F_231 ( V_1216 ) -> V_240 = V_996 ;
if ( V_118 -> V_28 -> V_320 ) {
F_297 ( V_118 , F_42 ( V_50 ) ) ;
V_321 -> V_418 ( V_118 ,
F_235 ( V_50 -> V_28 ) ,
F_231 ( V_118 -> V_28 ) ) ;
} else {
F_237 ( V_118 , F_42 ( V_50 ) ) ;
V_321 -> V_329 ( V_118 , V_50 ) ;
}
F_892 ( V_118 , V_1216 ) ;
V_1235:
F_5 ( & V_6 -> V_245 . V_242 ) ;
V_1234:
F_904 ( V_118 , V_1216 ) ;
return V_349 ;
V_1233:
return F_905 ( V_118 , V_50 , V_74 ,
V_334 , V_335 , V_336 , V_337 ,
V_330 , V_331 , V_332 , V_333 , V_421 ) ;
}
static struct V_321 *
F_906 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_321 * V_73 = NULL ;
struct V_250 * V_28 = NULL ;
const T_2 * V_1236 ;
unsigned int V_1237 ;
unsigned int V_1238 ;
int V_349 ;
V_73 = F_504 ( sizeof( * V_73 ) , V_627 ) ;
if ( ! V_73 ) {
V_349 = - V_626 ;
goto V_970;
}
V_28 = F_907 ( & V_73 -> V_49 ) ;
if ( ! V_28 ) {
V_349 = - V_626 ;
goto V_970;
}
V_73 -> V_49 . V_28 = & V_28 -> V_49 ;
V_73 -> V_1239 = false ;
V_73 -> V_1240 = 1 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_73 -> V_1239 = true ;
V_28 -> V_407 = - 1 ;
}
V_73 -> V_79 = V_79 ;
if ( F_908 ( V_6 ) && F_53 ( V_6 ) < 4 )
V_73 -> V_118 = (enum V_118 ) ! V_79 ;
else
V_73 -> V_118 = (enum V_118 ) V_79 ;
V_73 -> V_324 = V_1241 ;
V_73 -> V_341 = F_909 ( V_79 ) ;
V_73 -> V_1242 = F_895 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_1236 = V_1243 ;
V_1238 = F_173 ( V_1243 ) ;
V_73 -> V_418 = F_284 ;
V_73 -> V_329 = F_293 ;
} else if ( F_53 ( V_6 ) >= 4 ) {
V_1236 = V_1244 ;
V_1238 = F_173 ( V_1244 ) ;
V_73 -> V_418 = F_255 ;
V_73 -> V_329 = F_271 ;
} else {
V_1236 = V_1245 ;
V_1238 = F_173 ( V_1245 ) ;
V_73 -> V_418 = F_255 ;
V_73 -> V_329 = F_271 ;
}
if ( F_53 ( V_6 ) >= 9 )
V_349 = F_910 ( & V_6 -> V_245 , & V_73 -> V_49 ,
0 , & V_1246 ,
V_1236 , V_1238 ,
V_1247 ,
L_232 , F_73 ( V_79 ) ) ;
else if ( F_53 ( V_6 ) >= 5 || F_249 ( V_6 ) )
V_349 = F_910 ( & V_6 -> V_245 , & V_73 -> V_49 ,
0 , & V_1246 ,
V_1236 , V_1238 ,
V_1247 ,
L_233 , F_73 ( V_79 ) ) ;
else
V_349 = F_910 ( & V_6 -> V_245 , & V_73 -> V_49 ,
0 , & V_1246 ,
V_1236 , V_1238 ,
V_1247 ,
L_234 , F_84 ( V_73 -> V_118 ) ) ;
if ( V_349 )
goto V_970;
if ( F_53 ( V_6 ) >= 9 ) {
V_1237 =
V_273 | V_390 |
V_356 | V_280 ;
} else if ( F_12 ( V_6 ) && V_79 == V_105 ) {
V_1237 =
V_273 | V_356 |
V_358 ;
} else if ( F_53 ( V_6 ) >= 4 ) {
V_1237 =
V_273 | V_356 ;
} else {
V_1237 = V_273 ;
}
if ( F_53 ( V_6 ) >= 4 )
F_911 ( & V_73 -> V_49 ,
V_273 ,
V_1237 ) ;
F_912 ( & V_73 -> V_49 , & V_1248 ) ;
return V_73 ;
V_970:
F_232 ( V_28 ) ;
F_232 ( V_73 ) ;
return F_662 ( V_349 ) ;
}
static int
F_913 ( struct V_318 * V_118 ,
struct V_22 * V_45 ,
struct V_250 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_118 -> V_48 ) ;
struct V_213 * V_74 = V_28 -> V_49 . V_74 ;
struct V_238 * V_239 = F_183 ( V_74 ) ;
enum V_79 V_79 = F_227 ( V_118 ) -> V_79 ;
unsigned V_276 ;
int V_349 ;
V_349 = F_896 ( & V_28 -> V_49 ,
& V_28 -> V_1230 ,
V_1227 ,
V_1227 ,
true , true ) ;
if ( V_349 )
return V_349 ;
if ( ! V_239 )
return 0 ;
if ( ! F_660 ( V_6 , V_28 -> V_49 . V_336 ,
V_28 -> V_49 . V_337 ) ) {
F_914 ( L_235 ,
V_28 -> V_49 . V_336 , V_28 -> V_49 . V_337 ) ;
return - V_272 ;
}
V_276 = F_652 ( V_28 -> V_49 . V_336 ) * 4 ;
if ( V_239 -> V_49 . V_227 < V_276 * V_28 -> V_49 . V_337 ) {
F_156 ( L_236 ) ;
return - V_626 ;
}
if ( V_74 -> V_216 != V_217 ) {
F_156 ( L_237 ) ;
return - V_272 ;
}
if ( F_12 ( V_6 ) && V_79 == V_508 &&
V_28 -> V_49 . V_320 && V_28 -> V_49 . V_334 < 0 ) {
F_156 ( L_238 ) ;
return - V_272 ;
}
if ( F_75 ( V_6 ) || F_76 ( V_6 ) )
V_28 -> V_360 = F_651 ( V_45 , V_28 ) ;
else
V_28 -> V_360 = F_656 ( V_45 , V_28 ) ;
return 0 ;
}
static void
F_915 ( struct V_318 * V_118 ,
struct V_130 * V_50 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
V_66 -> V_957 = 0 ;
F_658 ( V_50 , NULL ) ;
}
static void
F_916 ( struct V_318 * V_118 ,
const struct V_22 * V_45 ,
const struct V_250 * V_28 )
{
struct V_130 * V_50 = V_45 -> V_49 . V_50 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_5 * V_6 = F_35 ( V_118 -> V_48 ) ;
struct V_238 * V_239 = F_183 ( V_28 -> V_49 . V_74 ) ;
T_2 V_1037 ;
if ( ! V_239 )
V_1037 = 0 ;
else if ( ! F_178 ( V_6 ) -> V_1221 )
V_1037 = F_234 ( V_28 ) ;
else
V_1037 = V_239 -> V_1249 -> V_1250 ;
V_66 -> V_957 = V_1037 ;
F_658 ( V_50 , V_28 ) ;
}
static struct V_321 *
F_917 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_321 * V_1251 = NULL ;
struct V_250 * V_28 = NULL ;
int V_349 ;
V_1251 = F_504 ( sizeof( * V_1251 ) , V_627 ) ;
if ( ! V_1251 ) {
V_349 = - V_626 ;
goto V_970;
}
V_28 = F_907 ( & V_1251 -> V_49 ) ;
if ( ! V_28 ) {
V_349 = - V_626 ;
goto V_970;
}
V_1251 -> V_49 . V_28 = & V_28 -> V_49 ;
V_1251 -> V_1239 = false ;
V_1251 -> V_1240 = 1 ;
V_1251 -> V_79 = V_79 ;
V_1251 -> V_118 = V_79 ;
V_1251 -> V_324 = V_1066 ;
V_1251 -> V_341 = F_918 ( V_79 ) ;
V_1251 -> V_1242 = F_913 ;
V_1251 -> V_418 = F_916 ;
V_1251 -> V_329 = F_915 ;
V_349 = F_910 ( & V_6 -> V_245 , & V_1251 -> V_49 ,
0 , & V_1252 ,
V_1253 ,
F_173 ( V_1253 ) ,
V_1220 ,
L_239 , F_73 ( V_79 ) ) ;
if ( V_349 )
goto V_970;
if ( F_53 ( V_6 ) >= 4 )
F_911 ( & V_1251 -> V_49 ,
V_273 ,
V_273 |
V_356 ) ;
if ( F_53 ( V_6 ) >= 9 )
V_28 -> V_407 = - 1 ;
F_912 ( & V_1251 -> V_49 , & V_1248 ) ;
return V_1251 ;
V_970:
F_232 ( V_28 ) ;
F_232 ( V_1251 ) ;
return F_662 ( V_349 ) ;
}
static void F_650 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_370 * V_371 =
& V_45 -> V_371 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int V_120 ;
V_50 -> V_372 = V_6 -> V_1082 . V_372 [ V_50 -> V_79 ] ;
if ( ! V_50 -> V_372 )
return;
for ( V_120 = 0 ; V_120 < V_50 -> V_372 ; V_120 ++ ) {
struct V_1254 * V_1255 = & V_371 -> V_373 [ V_120 ] ;
V_1255 -> V_374 = 0 ;
V_1255 -> V_417 = V_1256 ;
}
V_371 -> V_407 = - 1 ;
}
static int F_919 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_66 * V_66 ;
struct V_22 * V_45 = NULL ;
struct V_321 * V_73 = NULL ;
struct V_321 * V_1251 = NULL ;
int V_124 , V_349 ;
V_66 = F_504 ( sizeof( * V_66 ) , V_627 ) ;
if ( ! V_66 )
return - V_626 ;
V_45 = F_504 ( sizeof( * V_45 ) , V_627 ) ;
if ( ! V_45 ) {
V_349 = - V_626 ;
goto V_970;
}
V_66 -> V_75 = V_45 ;
V_66 -> V_49 . V_28 = & V_45 -> V_49 ;
V_45 -> V_49 . V_50 = & V_66 -> V_49 ;
V_73 = F_906 ( V_6 , V_79 ) ;
if ( F_188 ( V_73 ) ) {
V_349 = F_238 ( V_73 ) ;
goto V_970;
}
V_66 -> V_1257 |= F_228 ( V_73 -> V_324 ) ;
F_88 (dev_priv, pipe, sprite) {
struct V_321 * V_118 ;
V_118 = F_920 ( V_6 , V_79 , V_124 ) ;
if ( F_188 ( V_118 ) ) {
V_349 = F_238 ( V_118 ) ;
goto V_970;
}
V_66 -> V_1257 |= F_228 ( V_118 -> V_324 ) ;
}
V_1251 = F_917 ( V_6 , V_79 ) ;
if ( F_188 ( V_1251 ) ) {
V_349 = F_238 ( V_1251 ) ;
goto V_970;
}
V_66 -> V_1257 |= F_228 ( V_1251 -> V_324 ) ;
V_349 = F_921 ( & V_6 -> V_245 , & V_66 -> V_49 ,
& V_73 -> V_49 , & V_1251 -> V_49 ,
& V_1258 ,
L_240 , F_73 ( V_79 ) ) ;
if ( V_349 )
goto V_970;
V_66 -> V_79 = V_79 ;
V_66 -> V_118 = V_73 -> V_118 ;
V_66 -> V_948 = ~ 0 ;
V_66 -> V_947 = ~ 0 ;
V_66 -> V_949 = ~ 0 ;
F_650 ( V_66 , V_45 ) ;
F_591 ( V_79 >= F_173 ( V_6 -> V_1259 ) ||
V_6 -> V_1259 [ V_66 -> V_118 ] != NULL ) ;
V_6 -> V_1259 [ V_66 -> V_118 ] = V_66 ;
V_6 -> V_1260 [ V_66 -> V_79 ] = V_66 ;
F_922 ( & V_66 -> V_49 , & V_1261 ) ;
F_923 ( & V_66 -> V_49 ) ;
F_21 ( F_820 ( & V_66 -> V_49 ) != V_66 -> V_79 ) ;
return 0 ;
V_970:
F_232 ( V_45 ) ;
F_232 ( V_66 ) ;
return V_349 ;
}
enum V_79 F_924 ( struct V_623 * V_624 )
{
struct V_47 * V_48 = V_624 -> V_49 . V_48 ;
F_21 ( ! F_679 ( & V_48 -> V_426 . V_969 ) ) ;
if ( ! V_624 -> V_49 . V_28 -> V_50 )
return V_587 ;
return F_42 ( V_624 -> V_49 . V_28 -> V_50 ) -> V_79 ;
}
int F_925 ( struct V_47 * V_48 , void * V_1262 ,
struct V_1263 * V_1264 )
{
struct V_1265 * V_1266 = V_1262 ;
struct V_130 * V_1267 ;
struct V_66 * V_50 ;
V_1267 = F_926 ( V_48 , V_1266 -> V_1268 ) ;
if ( ! V_1267 )
return - V_1269 ;
V_50 = F_42 ( V_1267 ) ;
V_1266 -> V_79 = V_50 -> V_79 ;
return 0 ;
}
static int F_927 ( struct V_509 * V_510 )
{
struct V_47 * V_48 = V_510 -> V_49 . V_48 ;
struct V_509 * V_1069 ;
int V_1270 = 0 ;
int V_1271 = 0 ;
F_589 (dev, source_encoder) {
if ( F_761 ( V_510 , V_1069 ) )
V_1270 |= ( 1 << V_1271 ) ;
V_1271 ++ ;
}
return V_1270 ;
}
static bool F_928 ( struct V_5 * V_6 )
{
if ( ! F_135 ( V_6 ) )
return false ;
if ( ( F_17 ( V_1272 ) & V_1273 ) == 0 )
return false ;
if ( F_16 ( V_6 ) && ( F_17 ( V_1274 ) & V_1275 ) )
return false ;
return true ;
}
static bool F_929 ( struct V_5 * V_6 )
{
if ( F_53 ( V_6 ) >= 9 )
return false ;
if ( F_930 ( V_6 ) || F_931 ( V_6 ) )
return false ;
if ( F_12 ( V_6 ) )
return false ;
if ( F_932 ( V_6 ) &&
F_17 ( V_1276 ) & V_1277 )
return false ;
if ( F_15 ( V_6 ) && F_17 ( F_933 ( V_596 ) ) & V_1278 )
return false ;
if ( ! V_6 -> V_667 . V_1279 )
return false ;
return true ;
}
void F_316 ( struct V_5 * V_6 )
{
int V_1280 ;
int V_1281 ;
if ( F_15 ( V_6 ) )
return;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1280 = 2 ;
else
V_1280 = 1 ;
for ( V_1281 = 0 ; V_1281 < V_1280 ; V_1281 ++ ) {
T_1 V_15 = F_17 ( F_71 ( V_1281 ) ) ;
V_15 = ( V_15 & ~ V_108 ) | V_109 ;
F_119 ( F_71 ( V_1281 ) , V_15 ) ;
}
}
static void F_934 ( struct V_5 * V_6 )
{
if ( F_70 ( V_6 ) || F_30 ( V_6 ) )
V_6 -> V_1282 = V_1283 ;
else if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_6 -> V_1282 = V_1284 ;
else
V_6 -> V_1282 = V_1285 ;
F_316 ( V_6 ) ;
}
static void F_935 ( struct V_5 * V_6 )
{
struct V_509 * V_510 ;
bool V_1286 = false ;
F_934 ( V_6 ) ;
F_936 ( V_6 ) ;
if ( F_929 ( V_6 ) )
F_937 ( V_6 ) ;
if ( F_30 ( V_6 ) ) {
F_938 ( V_6 , V_596 ) ;
F_938 ( V_6 , V_183 ) ;
F_938 ( V_6 , V_185 ) ;
F_939 ( V_6 ) ;
} else if ( F_15 ( V_6 ) ) {
int V_60 ;
V_60 = F_17 ( F_933 ( V_596 ) ) & V_1287 ;
if ( V_60 || F_647 ( V_6 ) )
F_938 ( V_6 , V_596 ) ;
V_60 = F_17 ( V_1276 ) ;
if ( V_60 & V_1288 )
F_938 ( V_6 , V_183 ) ;
if ( V_60 & V_1289 )
F_938 ( V_6 , V_185 ) ;
if ( V_60 & V_1290 )
F_938 ( V_6 , V_187 ) ;
if ( F_647 ( V_6 ) &&
( V_6 -> V_667 . V_1291 [ V_601 ] . V_1292 ||
V_6 -> V_667 . V_1291 [ V_601 ] . V_1293 ||
V_6 -> V_667 . V_1291 [ V_601 ] . V_1294 ) )
F_938 ( V_6 , V_601 ) ;
} else if ( F_70 ( V_6 ) ) {
int V_60 ;
V_1286 = F_940 ( V_6 , V_187 ) ;
if ( F_928 ( V_6 ) )
F_941 ( V_6 , V_1272 , V_596 ) ;
if ( F_17 ( V_156 ) & V_1295 ) {
V_60 = F_942 ( V_6 , V_1296 , V_183 ) ;
if ( ! V_60 )
F_943 ( V_6 , V_156 , V_183 ) ;
if ( ! V_60 && ( F_17 ( V_149 ) & V_1273 ) )
F_941 ( V_6 , V_149 , V_183 ) ;
}
if ( F_17 ( V_157 ) & V_1295 )
F_943 ( V_6 , V_157 , V_185 ) ;
if ( ! V_1286 && F_17 ( V_158 ) & V_1295 )
F_943 ( V_6 , V_158 , V_187 ) ;
if ( F_17 ( V_151 ) & V_1273 )
F_941 ( V_6 , V_151 , V_185 ) ;
if ( F_17 ( V_153 ) & V_1273 )
F_941 ( V_6 , V_153 , V_187 ) ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
bool V_1297 , V_1298 ;
V_1297 = F_940 ( V_6 , V_183 ) ;
V_1298 = F_944 ( V_6 , V_183 ) ;
if ( F_17 ( V_1299 ) & V_1273 || V_1298 )
V_1297 &= F_941 ( V_6 , V_1299 , V_183 ) ;
if ( ( F_17 ( V_1300 ) & V_1295 || V_1298 ) && ! V_1297 )
F_943 ( V_6 , V_1300 , V_183 ) ;
V_1297 = F_940 ( V_6 , V_185 ) ;
V_1298 = F_944 ( V_6 , V_185 ) ;
if ( F_17 ( V_1301 ) & V_1273 || V_1298 )
V_1297 &= F_941 ( V_6 , V_1301 , V_185 ) ;
if ( ( F_17 ( V_1302 ) & V_1295 || V_1298 ) && ! V_1297 )
F_943 ( V_6 , V_1302 , V_185 ) ;
if ( F_12 ( V_6 ) ) {
V_1298 = F_944 ( V_6 , V_187 ) ;
if ( F_17 ( V_1303 ) & V_1273 || V_1298 )
F_941 ( V_6 , V_1303 , V_187 ) ;
if ( F_17 ( V_1304 ) & V_1295 || V_1298 )
F_943 ( V_6 , V_1304 , V_187 ) ;
}
F_939 ( V_6 ) ;
} else if ( ! F_50 ( V_6 ) && ! F_29 ( V_6 ) ) {
bool V_60 = false ;
if ( F_17 ( V_1305 ) & V_1295 ) {
F_156 ( L_241 ) ;
V_60 = F_942 ( V_6 , V_1305 , V_183 ) ;
if ( ! V_60 && F_249 ( V_6 ) ) {
F_156 ( L_242 ) ;
F_943 ( V_6 , V_1306 , V_183 ) ;
}
if ( ! V_60 && F_249 ( V_6 ) )
F_941 ( V_6 , V_1307 , V_183 ) ;
}
if ( F_17 ( V_1305 ) & V_1295 ) {
F_156 ( L_243 ) ;
V_60 = F_942 ( V_6 , V_1308 , V_185 ) ;
}
if ( ! V_60 && ( F_17 ( V_1308 ) & V_1295 ) ) {
if ( F_249 ( V_6 ) ) {
F_156 ( L_244 ) ;
F_943 ( V_6 , V_1309 , V_185 ) ;
}
if ( F_249 ( V_6 ) )
F_941 ( V_6 , V_1310 , V_185 ) ;
}
if ( F_249 ( V_6 ) && ( F_17 ( V_1311 ) & V_1273 ) )
F_941 ( V_6 , V_1311 , V_187 ) ;
} else if ( F_50 ( V_6 ) )
F_945 ( V_6 ) ;
if ( F_946 ( V_6 ) )
F_947 ( V_6 ) ;
F_948 ( V_6 ) ;
F_589 (&dev_priv->drm, encoder) {
V_510 -> V_49 . V_971 = V_510 -> V_1155 ;
V_510 -> V_49 . V_1312 =
F_927 ( V_510 ) ;
}
F_601 ( V_6 ) ;
F_949 ( & V_6 -> V_245 ) ;
}
static void F_950 ( struct V_213 * V_74 )
{
struct V_251 * V_252 = F_176 ( V_74 ) ;
F_951 ( V_74 ) ;
F_952 ( V_252 -> V_239 ) ;
F_21 ( ! V_252 -> V_239 -> V_1313 -- ) ;
F_953 ( V_252 -> V_239 ) ;
F_222 ( V_252 -> V_239 ) ;
F_232 ( V_252 ) ;
}
static int F_954 ( struct V_213 * V_74 ,
struct V_1263 * V_1264 ,
unsigned int * V_1314 )
{
struct V_251 * V_252 = F_176 ( V_74 ) ;
struct V_238 * V_239 = V_252 -> V_239 ;
if ( V_239 -> V_1315 . V_555 ) {
F_914 ( L_245 ) ;
return - V_272 ;
}
return F_955 ( V_1264 , & V_239 -> V_49 , V_1314 ) ;
}
static int F_956 ( struct V_213 * V_74 ,
struct V_1263 * V_1264 ,
unsigned V_315 , unsigned V_1316 ,
struct V_1317 * V_1318 ,
unsigned V_1319 )
{
struct V_238 * V_239 = F_183 ( V_74 ) ;
F_957 ( V_239 ) ;
F_958 ( V_239 , V_1320 ) ;
return 0 ;
}
static
T_1 F_959 ( struct V_5 * V_6 ,
V_40 V_260 , T_2 V_314 )
{
T_1 V_235 = F_53 ( V_6 ) ;
if ( V_235 >= 9 ) {
int V_214 = F_960 ( V_314 , 0 ) ;
return V_43 ( 8192 * V_214 , 32768 ) ;
} else if ( V_235 >= 5 && ! F_158 ( V_6 ) ) {
return 32 * 1024 ;
} else if ( V_235 >= 4 ) {
if ( V_260 == V_218 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_235 >= 3 ) {
if ( V_260 == V_218 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_221 ( struct V_251 * V_252 ,
struct V_238 * V_239 ,
struct V_306 * V_307 )
{
struct V_5 * V_6 = F_35 ( V_239 -> V_49 . V_48 ) ;
struct V_1088 V_1089 ;
T_1 V_1321 , V_1322 ;
unsigned int V_312 , V_276 ;
int V_349 = - V_272 ;
F_952 ( V_239 ) ;
V_239 -> V_1313 ++ ;
V_312 = F_961 ( V_239 ) ;
V_276 = F_962 ( V_239 ) ;
F_953 ( V_239 ) ;
if ( V_307 -> V_315 & V_316 ) {
if ( V_312 != V_268 &&
V_312 != F_208 ( V_307 -> V_216 [ 0 ] ) ) {
F_156 ( L_246 ) ;
goto V_57;
}
} else {
if ( V_312 == V_266 ) {
V_307 -> V_216 [ 0 ] = V_218 ;
} else if ( V_312 == V_267 ) {
F_156 ( L_247 ) ;
goto V_57;
}
}
switch ( V_307 -> V_216 [ 0 ] ) {
case V_219 :
case V_220 :
if ( F_53 ( V_6 ) < 9 ) {
F_156 ( L_248 ,
V_307 -> V_216 [ 0 ] ) ;
goto V_57;
}
case V_217 :
case V_218 :
break;
default:
F_156 ( L_249 ,
V_307 -> V_216 [ 0 ] ) ;
goto V_57;
}
if ( F_178 ( V_6 ) -> V_235 < 4 &&
V_312 != F_208 ( V_307 -> V_216 [ 0 ] ) ) {
F_156 ( L_250 ) ;
goto V_57;
}
V_1321 = F_959 ( V_6 , V_307 -> V_216 [ 0 ] ,
V_307 -> V_314 ) ;
if ( V_307 -> V_247 [ 0 ] > V_1321 ) {
F_156 ( L_251 ,
V_307 -> V_216 [ 0 ] != V_217 ?
L_252 : L_253 ,
V_307 -> V_247 [ 0 ] , V_1321 ) ;
goto V_57;
}
if ( V_312 != V_268 && V_307 -> V_247 [ 0 ] != V_276 ) {
F_156 ( L_254 ,
V_307 -> V_247 [ 0 ] , V_276 ) ;
goto V_57;
}
switch ( V_307 -> V_314 ) {
case V_282 :
case V_286 :
case V_288 :
case V_300 :
break;
case V_284 :
if ( F_53 ( V_6 ) > 3 ) {
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
break;
case V_299 :
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) &&
F_53 ( V_6 ) < 9 ) {
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
break;
case V_290 :
case V_292 :
case V_294 :
if ( F_53 ( V_6 ) < 4 ) {
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
break;
case V_1323 :
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) ) {
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
break;
case V_378 :
case V_383 :
case V_381 :
case V_385 :
if ( F_53 ( V_6 ) < 5 ) {
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
break;
default:
F_156 ( L_255 ,
F_783 ( V_307 -> V_314 , & V_1089 ) ) ;
goto V_57;
}
if ( V_307 -> V_265 [ 0 ] != 0 )
goto V_57;
F_963 ( & V_6 -> V_245 ,
& V_252 -> V_49 , V_307 ) ;
V_1322 = F_272 ( & V_252 -> V_49 , 0 ) ;
if ( V_307 -> V_247 [ 0 ] & ( V_1322 - 1 ) ) {
F_156 ( L_256 ,
V_307 -> V_247 [ 0 ] , V_1322 ) ;
goto V_57;
}
V_252 -> V_239 = V_239 ;
V_349 = F_209 ( V_6 , & V_252 -> V_49 ) ;
if ( V_349 )
goto V_57;
V_349 = F_964 ( V_239 -> V_49 . V_48 ,
& V_252 -> V_49 ,
& V_1324 ) ;
if ( V_349 ) {
F_122 ( L_257 , V_349 ) ;
goto V_57;
}
return 0 ;
V_57:
F_952 ( V_239 ) ;
V_239 -> V_1313 -- ;
F_953 ( V_239 ) ;
return V_349 ;
}
static struct V_213 *
F_965 ( struct V_47 * V_48 ,
struct V_1263 * V_1325 ,
const struct V_306 * V_1326 )
{
struct V_213 * V_74 ;
struct V_238 * V_239 ;
struct V_306 V_307 = * V_1326 ;
V_239 = F_966 ( V_1325 , V_307 . V_1327 [ 0 ] ) ;
if ( ! V_239 )
return F_662 ( - V_1269 ) ;
V_74 = F_661 ( V_239 , & V_307 ) ;
if ( F_188 ( V_74 ) )
F_222 ( V_239 ) ;
return V_74 ;
}
static void F_967 ( struct V_419 * V_28 )
{
struct V_564 * V_327 = F_302 ( V_28 ) ;
F_968 ( V_28 ) ;
F_969 ( & V_327 -> V_1210 ) ;
F_232 ( V_28 ) ;
}
void F_970 ( struct V_5 * V_6 )
{
F_971 ( V_6 ) ;
if ( F_178 ( V_6 ) -> V_235 >= 9 ) {
V_6 -> V_432 . V_1153 = F_648 ;
V_6 -> V_432 . V_1328 =
F_612 ;
V_6 -> V_432 . V_1070 =
F_632 ;
V_6 -> V_432 . V_1184 = F_449 ;
V_6 -> V_432 . V_618 = F_461 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_648 ;
V_6 -> V_432 . V_1328 =
F_615 ;
V_6 -> V_432 . V_1070 =
F_632 ;
V_6 -> V_432 . V_1184 = F_449 ;
V_6 -> V_432 . V_618 = F_461 ;
} else if ( F_70 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_616 ;
V_6 -> V_432 . V_1328 =
F_615 ;
V_6 -> V_432 . V_1070 =
F_605 ;
V_6 -> V_432 . V_1184 = F_437 ;
V_6 -> V_432 . V_618 = F_459 ;
} else if ( F_12 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_579 ;
V_6 -> V_432 . V_1184 = F_476 ;
V_6 -> V_432 . V_618 = F_487 ;
} else if ( F_11 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_580 ;
V_6 -> V_432 . V_1184 = F_476 ;
V_6 -> V_432 . V_618 = F_487 ;
} else if ( F_249 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_576 ;
V_6 -> V_432 . V_1184 = F_485 ;
V_6 -> V_432 . V_618 = F_487 ;
} else if ( F_29 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_577 ;
V_6 -> V_432 . V_1184 = F_485 ;
V_6 -> V_432 . V_618 = F_487 ;
} else if ( ! F_50 ( V_6 ) ) {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_578 ;
V_6 -> V_432 . V_1184 = F_485 ;
V_6 -> V_432 . V_618 = F_487 ;
} else {
V_6 -> V_432 . V_1153 = F_586 ;
V_6 -> V_432 . V_1328 =
F_583 ;
V_6 -> V_432 . V_1070 = F_575 ;
V_6 -> V_432 . V_1184 = F_485 ;
V_6 -> V_432 . V_618 = F_487 ;
}
if ( F_16 ( V_6 ) ) {
V_6 -> V_432 . V_514 = F_333 ;
} else if ( F_250 ( V_6 ) ) {
V_6 -> V_432 . V_514 = F_339 ;
} else if ( F_251 ( V_6 ) ) {
V_6 -> V_432 . V_514 = F_341 ;
} else if ( F_252 ( V_6 ) || F_253 ( V_6 ) ) {
V_6 -> V_432 . V_514 = V_1329 ;
}
if ( V_6 -> V_1082 . V_235 >= 9 )
V_6 -> V_432 . V_1203 = F_854 ;
else
V_6 -> V_432 . V_1203 = F_853 ;
switch ( F_178 ( V_6 ) -> V_235 ) {
case 2 :
V_6 -> V_432 . V_1056 = F_712 ;
break;
case 3 :
V_6 -> V_432 . V_1056 = F_715 ;
break;
case 4 :
case 5 :
V_6 -> V_432 . V_1056 = F_716 ;
break;
case 6 :
V_6 -> V_432 . V_1056 = F_717 ;
break;
case 7 :
case 8 :
V_6 -> V_432 . V_1056 = F_718 ;
break;
case 9 :
default:
V_6 -> V_432 . V_1056 = F_731 ;
}
}
static void F_972 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_114 |= V_115 ;
F_973 ( L_258 ) ;
}
static void F_974 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_114 |= V_116 ;
F_973 ( L_259 ) ;
}
static void F_975 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_114 |= V_669 ;
F_973 ( L_260 ) ;
}
static void F_976 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_114 |= V_1330 ;
F_973 ( L_261 ) ;
}
static void F_977 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_114 |= V_1331 ;
F_973 ( L_262 ) ;
}
static int F_978 ( const struct V_1332 * V_324 )
{
F_973 ( L_263 , V_324 -> V_1333 ) ;
return 1 ;
}
static void F_979 ( struct V_47 * V_48 )
{
struct V_1334 * V_1335 = V_48 -> V_1336 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < F_173 ( V_1337 ) ; V_120 ++ ) {
struct V_1338 * V_1339 = & V_1337 [ V_120 ] ;
if ( V_1335 -> V_1340 == V_1339 -> V_1340 &&
( V_1335 -> V_1341 == V_1339 -> V_1341 ||
V_1339 -> V_1341 == V_1342 ) &&
( V_1335 -> V_1343 == V_1339 -> V_1343 ||
V_1339 -> V_1343 == V_1342 ) )
V_1339 -> V_1344 ( V_48 ) ;
}
for ( V_120 = 0 ; V_120 < F_173 ( V_1345 ) ; V_120 ++ ) {
if ( F_980 ( * V_1345 [ V_120 ] . V_1346 ) != 0 )
V_1345 [ V_120 ] . V_1344 ( V_48 ) ;
}
}
static void F_981 ( struct V_5 * V_6 )
{
struct V_1334 * V_1336 = V_6 -> V_245 . V_1336 ;
T_9 V_1347 ;
T_3 V_1348 = F_982 ( V_6 ) ;
F_983 ( V_1336 , V_1349 ) ;
F_984 ( V_1350 , V_1351 ) ;
V_1347 = F_985 ( V_1352 ) ;
F_984 ( V_1347 | 1 << 5 , V_1352 ) ;
F_986 ( V_1336 , V_1349 ) ;
F_121 ( 300 ) ;
F_119 ( V_1348 , V_1353 ) ;
F_120 ( V_1348 ) ;
}
void F_317 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_629 ( V_6 ) ;
V_6 -> V_1166 . V_1167 = V_6 -> V_1166 . V_1168 = V_6 -> V_1166 . V_1354 ;
F_987 ( V_6 ) ;
}
static void F_988 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_419 * V_28 ;
struct V_564 * V_327 ;
struct V_130 * V_50 ;
struct V_27 * V_1185 ;
struct V_420 V_421 ;
int V_349 ;
int V_120 ;
if ( ! V_6 -> V_432 . V_1204 )
return;
F_307 ( & V_421 , 0 ) ;
V_460:
V_349 = F_308 ( V_48 , & V_421 ) ;
if ( V_349 == - V_424 ) {
F_309 ( & V_421 ) ;
goto V_460;
} else if ( F_21 ( V_349 ) ) {
goto V_970;
}
V_28 = F_310 ( V_48 , & V_421 ) ;
if ( F_21 ( F_188 ( V_28 ) ) )
goto V_970;
V_327 = F_302 ( V_28 ) ;
if ( ! F_158 ( V_6 ) )
V_327 -> V_423 = true ;
V_349 = F_837 ( V_48 , V_28 ) ;
if ( V_349 ) {
F_7 ( true , L_264 ) ;
goto V_1355;
}
F_301 (state, crtc, cstate, i) {
struct V_22 * V_1007 = F_235 ( V_1185 ) ;
V_1007 -> V_1075 . V_1182 = true ;
V_6 -> V_432 . V_1204 ( V_327 , V_1007 ) ;
}
V_1355:
F_312 ( V_28 ) ;
V_970:
F_321 ( & V_421 ) ;
F_322 ( & V_421 ) ;
}
int F_989 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_304 * V_305 = & V_6 -> V_305 ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
F_990 ( V_48 ) ;
V_48 -> V_426 . V_1356 = 0 ;
V_48 -> V_426 . V_1357 = 0 ;
V_48 -> V_426 . V_1358 = 24 ;
V_48 -> V_426 . V_1359 = 1 ;
V_48 -> V_426 . V_1360 = true ;
V_48 -> V_426 . V_876 = & V_1361 ;
F_742 ( & V_6 -> V_1197 . V_1046 ,
F_859 ) ;
F_979 ( V_48 ) ;
F_991 ( V_6 ) ;
if ( F_178 ( V_6 ) -> V_630 == 0 )
return 0 ;
if ( F_115 ( V_6 ) || F_101 ( V_6 ) ) {
bool V_1362 = ! ! ( F_17 ( V_815 ) &
V_821 ) ;
if ( V_6 -> V_667 . V_668 != V_1362 ) {
F_156 ( L_265 ,
V_1362 ? L_72 : L_73 ,
V_6 -> V_667 . V_668 ? L_72 : L_73 ) ;
V_6 -> V_667 . V_668 = V_1362 ;
}
}
if ( F_50 ( V_6 ) ) {
V_48 -> V_426 . V_345 = 2048 ;
V_48 -> V_426 . V_346 = 2048 ;
} else if ( F_992 ( V_6 ) ) {
V_48 -> V_426 . V_345 = 4096 ;
V_48 -> V_426 . V_346 = 4096 ;
} else {
V_48 -> V_426 . V_345 = 8192 ;
V_48 -> V_426 . V_346 = 8192 ;
}
if ( F_75 ( V_6 ) || F_76 ( V_6 ) ) {
V_48 -> V_426 . V_1363 = F_75 ( V_6 ) ? 64 : 512 ;
V_48 -> V_426 . V_1364 = 1023 ;
} else if ( F_50 ( V_6 ) ) {
V_48 -> V_426 . V_1363 = V_1365 ;
V_48 -> V_426 . V_1364 = V_1366 ;
} else {
V_48 -> V_426 . V_1363 = V_1367 ;
V_48 -> V_426 . V_1364 = V_1368 ;
}
V_48 -> V_426 . V_1369 = V_305 -> V_1370 ;
F_156 ( L_266 ,
F_178 ( V_6 ) -> V_630 ,
F_178 ( V_6 ) -> V_630 > 1 ? L_267 : L_268 ) ;
F_86 (dev_priv, pipe) {
int V_349 ;
V_349 = F_919 ( V_6 , V_79 ) ;
if ( V_349 ) {
F_993 ( V_48 ) ;
return V_349 ;
}
}
F_994 ( V_48 ) ;
F_10 ( V_6 ) ;
F_317 ( V_48 ) ;
if ( V_6 -> V_639 == 0 )
F_995 ( V_6 ) ;
F_981 ( V_6 ) ;
F_935 ( V_6 ) ;
F_996 ( V_48 ) ;
F_299 ( V_48 , V_48 -> V_426 . V_430 ) ;
F_997 ( V_48 ) ;
F_133 (dev, crtc) {
struct V_302 V_303 = {} ;
if ( ! V_50 -> V_72 )
continue;
V_6 -> V_432 . V_1328 ( V_50 ,
& V_303 ) ;
F_230 ( V_50 , & V_303 ) ;
}
if ( ! F_158 ( V_6 ) )
F_988 ( V_48 ) ;
return 0 ;
}
static void F_998 ( struct V_47 * V_48 ,
struct V_420 * V_421 )
{
struct V_623 * V_624 ;
struct V_1079 V_1080 ;
struct V_572 * V_1371 = NULL ;
struct V_963 V_1372 ;
int V_349 ;
F_767 ( V_48 , & V_1080 ) ;
F_768 (connector, &conn_iter) {
if ( V_624 -> V_510 -> type == V_702 ) {
V_1371 = & V_624 -> V_49 ;
break;
}
}
F_771 ( & V_1080 ) ;
if ( ! V_1371 )
return;
V_349 = F_677 ( V_1371 , NULL , & V_1372 , V_421 ) ;
F_7 ( V_349 < 0 , L_269 ) ;
if ( V_349 > 0 )
F_686 ( V_1371 , & V_1372 , V_421 ) ;
}
static bool
F_999 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_15 ;
if ( F_178 ( V_6 ) -> V_630 == 1 )
return true ;
V_15 = F_17 ( F_83 ( ! V_50 -> V_118 ) ) ;
if ( ( V_15 & V_119 ) &&
( ! ! ( V_15 & V_122 ) == V_50 -> V_79 ) )
return false ;
return true ;
}
static bool F_1000 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_509 * V_510 ;
F_384 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_623 * F_1001 ( struct V_509 * V_510 )
{
struct V_47 * V_48 = V_510 -> V_49 . V_48 ;
struct V_623 * V_624 ;
F_1002 (dev, &encoder->base, connector)
return V_624 ;
return NULL ;
}
static bool F_1003 ( struct V_5 * V_6 ,
enum V_78 V_504 )
{
return F_115 ( V_6 ) || F_101 ( V_6 ) ||
( F_932 ( V_6 ) && V_504 == V_204 ) ;
}
static void F_1004 ( struct V_66 * V_50 ,
struct V_420 * V_421 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
if ( ! F_450 ( V_80 ) ) {
T_3 V_13 = F_54 ( V_80 ) ;
F_119 ( V_13 ,
F_17 ( V_13 ) & ~ V_1373 ) ;
}
F_1005 ( & V_50 -> V_49 ) ;
if ( V_50 -> V_72 ) {
struct V_321 * V_118 ;
F_446 ( & V_50 -> V_49 ) ;
F_1006 (dev, crtc, plane) {
if ( V_118 -> V_49 . type == V_1247 )
continue;
F_237 ( & V_118 -> V_49 , V_50 ) ;
V_118 -> V_329 ( & V_118 -> V_49 , & V_50 -> V_49 ) ;
}
}
if ( F_53 ( V_6 ) < 4 && ! F_999 ( V_50 ) ) {
bool V_118 ;
F_156 ( L_270 ,
V_50 -> V_49 . V_49 . V_324 , V_50 -> V_49 . V_12 ) ;
V_118 = V_50 -> V_118 ;
V_50 -> V_49 . V_73 -> V_28 -> V_320 = true ;
V_50 -> V_118 = ! V_118 ;
F_488 ( & V_50 -> V_49 , V_421 ) ;
V_50 -> V_118 = V_118 ;
}
if ( V_6 -> V_114 & V_115 &&
V_50 -> V_79 == V_98 && ! V_50 -> V_72 ) {
F_998 ( V_48 , V_421 ) ;
}
if ( V_50 -> V_72 && ! F_1000 ( V_50 ) )
F_488 ( & V_50 -> V_49 , V_421 ) ;
if ( V_50 -> V_72 || F_158 ( V_6 ) ) {
V_50 -> V_1374 = true ;
if ( F_1003 ( V_6 , (enum V_78 ) V_50 -> V_79 ) )
V_50 -> V_1375 = true ;
}
}
static void F_1007 ( struct V_509 * V_510 )
{
struct V_623 * V_624 ;
bool V_1376 = V_510 -> V_49 . V_50 &&
F_42 ( V_510 -> V_49 . V_50 ) -> V_72 ;
V_624 = F_1001 ( V_510 ) ;
if ( V_624 && ! V_1376 ) {
F_156 ( L_271 ,
V_510 -> V_49 . V_49 . V_324 ,
V_510 -> V_49 . V_12 ) ;
if ( V_510 -> V_49 . V_50 ) {
struct V_27 * V_45 = V_510 -> V_49 . V_50 -> V_28 ;
F_156 ( L_272 ,
V_510 -> V_49 . V_49 . V_324 ,
V_510 -> V_49 . V_12 ) ;
V_510 -> V_578 ( V_510 , F_235 ( V_45 ) , V_624 -> V_49 . V_28 ) ;
if ( V_510 -> V_579 )
V_510 -> V_579 ( V_510 , F_235 ( V_45 ) , V_624 -> V_49 . V_28 ) ;
}
V_510 -> V_49 . V_50 = NULL ;
V_624 -> V_49 . V_1377 = V_1378 ;
V_624 -> V_49 . V_510 = NULL ;
}
}
void F_1008 ( struct V_5 * V_6 )
{
T_3 V_1348 = F_982 ( V_6 ) ;
if ( ! ( F_17 ( V_1348 ) & V_1353 ) ) {
F_156 ( L_273 ) ;
F_981 ( V_6 ) ;
}
}
void F_300 ( struct V_5 * V_6 )
{
if ( ! F_80 ( V_6 , V_1379 ) )
return;
F_1008 ( V_6 ) ;
F_81 ( V_6 , V_1379 ) ;
}
static bool F_1009 ( struct V_321 * V_118 )
{
struct V_5 * V_6 = F_35 ( V_118 -> V_49 . V_48 ) ;
return F_17 ( F_83 ( V_118 -> V_118 ) ) & V_119 ;
}
static void F_1010 ( struct V_66 * V_50 )
{
struct V_321 * V_73 = F_227 ( V_50 -> V_49 . V_73 ) ;
bool V_320 ;
V_320 = V_50 -> V_72 && F_1009 ( V_73 ) ;
F_226 ( F_235 ( V_50 -> V_49 . V_28 ) ,
F_231 ( V_73 -> V_49 . V_28 ) ,
V_320 ) ;
}
static void F_1011 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
struct V_509 * V_510 ;
struct V_623 * V_624 ;
struct V_1079 V_1080 ;
int V_120 ;
V_6 -> V_621 = 0 ;
F_133 (dev, crtc) {
struct V_22 * V_45 =
F_235 ( V_50 -> V_49 . V_28 ) ;
F_818 ( & V_45 -> V_49 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_49 . V_50 = & V_50 -> V_49 ;
V_45 -> V_49 . V_72 = V_45 -> V_49 . V_505 =
V_6 -> V_432 . V_1153 ( V_50 , V_45 ) ;
V_50 -> V_49 . V_131 = V_45 -> V_49 . V_505 ;
V_50 -> V_72 = V_45 -> V_49 . V_72 ;
if ( V_45 -> V_49 . V_72 )
V_6 -> V_621 |= 1 << V_50 -> V_79 ;
F_1010 ( V_50 ) ;
F_156 ( L_274 ,
V_50 -> V_49 . V_49 . V_324 , V_50 -> V_49 . V_12 ,
F_780 ( V_45 -> V_49 . V_72 ) ) ;
}
for ( V_120 = 0 ; V_120 < V_6 -> V_813 ; V_120 ++ ) {
struct V_857 * V_858 = & V_6 -> V_1161 [ V_120 ] ;
V_858 -> V_1157 = V_858 -> V_876 . V_625 ( V_6 , V_858 ,
& V_858 -> V_28 . V_1159 ) ;
V_858 -> V_28 . V_1155 = 0 ;
F_133 (dev, crtc) {
struct V_22 * V_45 =
F_235 ( V_50 -> V_49 . V_28 ) ;
if ( V_45 -> V_49 . V_72 &&
V_45 -> V_191 == V_858 )
V_858 -> V_28 . V_1155 |= 1 << V_50 -> V_79 ;
}
V_858 -> V_1158 = V_858 -> V_28 . V_1155 ;
F_156 ( L_275 ,
V_858 -> V_12 , V_858 -> V_28 . V_1155 , V_858 -> V_1157 ) ;
}
F_589 (dev, encoder) {
V_79 = 0 ;
if ( V_510 -> V_625 ( V_510 , & V_79 ) ) {
struct V_22 * V_45 ;
V_50 = F_47 ( V_6 , V_79 ) ;
V_45 = F_235 ( V_50 -> V_49 . V_28 ) ;
V_510 -> V_49 . V_50 = & V_50 -> V_49 ;
V_45 -> V_1099 |= 1 << V_510 -> type ;
V_510 -> V_1154 ( V_510 , V_45 ) ;
} else {
V_510 -> V_49 . V_50 = NULL ;
}
F_156 ( L_276 ,
V_510 -> V_49 . V_49 . V_324 , V_510 -> V_49 . V_12 ,
F_780 ( V_510 -> V_49 . V_50 ) ,
F_73 ( V_79 ) ) ;
}
F_767 ( V_48 , & V_1080 ) ;
F_768 (connector, &conn_iter) {
if ( V_624 -> V_625 ( V_624 ) ) {
V_624 -> V_49 . V_1377 = V_1380 ;
V_510 = V_624 -> V_510 ;
V_624 -> V_49 . V_510 = & V_510 -> V_49 ;
if ( V_510 -> V_49 . V_50 &&
V_510 -> V_49 . V_50 -> V_28 -> V_72 ) {
V_510 -> V_49 . V_50 -> V_28 -> V_619 |=
1 << F_1012 ( & V_624 -> V_49 ) ;
V_510 -> V_49 . V_50 -> V_28 -> V_620 |=
1 << F_1013 ( & V_510 -> V_49 ) ;
}
} else {
V_624 -> V_49 . V_1377 = V_1378 ;
V_624 -> V_49 . V_510 = NULL ;
}
F_156 ( L_277 ,
V_624 -> V_49 . V_49 . V_324 , V_624 -> V_49 . V_12 ,
F_780 ( V_624 -> V_49 . V_510 ) ) ;
}
F_771 ( & V_1080 ) ;
F_133 (dev, crtc) {
struct V_22 * V_45 =
F_235 ( V_50 -> V_49 . V_28 ) ;
int V_1381 = 0 ;
V_50 -> V_49 . V_1105 = V_45 -> V_49 . V_76 ;
memset ( & V_50 -> V_49 . V_417 , 0 , sizeof( V_50 -> V_49 . V_417 ) ) ;
if ( V_45 -> V_49 . V_72 ) {
F_570 ( & V_50 -> V_49 . V_417 , V_45 ) ;
F_570 ( & V_45 -> V_49 . V_76 , V_45 ) ;
F_21 ( F_492 ( V_50 -> V_49 . V_28 , & V_50 -> V_49 . V_417 ) ) ;
V_45 -> V_49 . V_417 . V_1173 = V_1382 ;
F_516 ( V_45 ) ;
if ( F_53 ( V_6 ) >= 9 || F_253 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1381 = V_45 -> V_638 ;
else
F_21 ( V_6 -> V_432 . V_1170 ) ;
if ( F_253 ( V_6 ) && V_45 -> V_548 )
V_1381 = F_213 ( V_1381 * 100 , 95 ) ;
F_1014 ( & V_50 -> V_49 , & V_50 -> V_49 . V_1105 ) ;
F_825 ( V_50 ) ;
}
V_6 -> V_622 [ V_50 -> V_79 ] = V_1381 ;
F_806 ( V_6 , V_45 ) ;
}
}
static void
F_1015 ( struct V_5 * V_6 )
{
struct V_509 * V_510 ;
F_589 (&dev_priv->drm, encoder) {
T_4 V_1383 ;
enum V_112 V_610 ;
if ( ! V_510 -> V_1384 )
continue;
V_1383 = V_510 -> V_1384 ( V_510 ) ;
F_473 (domain, get_domains)
F_474 ( V_6 , V_610 ) ;
}
}
static void
F_299 ( struct V_47 * V_48 ,
struct V_420 * V_421 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
struct V_509 * V_510 ;
int V_120 ;
F_1011 ( V_48 ) ;
F_1015 ( V_6 ) ;
F_589 (dev, encoder) {
F_1007 ( V_510 ) ;
}
F_86 (dev_priv, pipe) {
V_50 = F_47 ( V_6 , V_79 ) ;
F_1004 ( V_50 , V_421 ) ;
F_777 ( V_50 , V_50 -> V_75 ,
L_278 ) ;
}
F_766 ( V_48 ) ;
for ( V_120 = 0 ; V_120 < V_6 -> V_813 ; V_120 ++ ) {
struct V_857 * V_858 = & V_6 -> V_1161 [ V_120 ] ;
if ( ! V_858 -> V_1157 || V_858 -> V_1158 )
continue;
F_156 ( L_279 , V_858 -> V_12 ) ;
V_858 -> V_876 . V_578 ( V_6 , V_858 ) ;
V_858 -> V_1157 = false ;
}
if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
F_1016 ( V_48 ) ;
F_1017 ( V_6 ) ;
} else if ( F_1018 ( V_6 ) ) {
F_1019 ( V_48 ) ;
} else if ( F_70 ( V_6 ) ) {
F_1020 ( V_48 ) ;
}
F_133 (dev, crtc) {
T_4 V_1201 ;
V_1201 = F_472 ( & V_50 -> V_49 , V_50 -> V_75 ) ;
if ( F_21 ( V_1201 ) )
F_475 ( V_6 , V_1201 ) ;
}
F_1021 ( V_6 , false ) ;
F_1022 ( V_6 ) ;
F_1023 ( V_6 ) ;
}
void F_1024 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_419 * V_28 = V_6 -> V_429 ;
struct V_420 V_421 ;
int V_349 ;
V_6 -> V_429 = NULL ;
if ( V_28 )
V_28 -> V_430 = & V_421 ;
F_3 ( & V_48 -> V_426 . V_427 ) ;
F_307 ( & V_421 , 0 ) ;
while ( 1 ) {
V_349 = F_308 ( V_48 , & V_421 ) ;
if ( V_349 != - V_424 )
break;
F_309 ( & V_421 ) ;
}
if ( ! V_349 )
V_349 = F_298 ( V_48 , V_28 , & V_421 ) ;
F_321 ( & V_421 ) ;
F_322 ( & V_421 ) ;
F_5 ( & V_48 -> V_426 . V_427 ) ;
if ( V_349 )
F_122 ( L_56 , V_349 ) ;
if ( V_28 )
F_312 ( V_28 ) ;
}
void F_1025 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_1026 ( V_6 ) ;
F_1027 ( V_6 ) ;
}
int F_1028 ( struct V_572 * V_624 )
{
struct V_623 * V_623 = F_774 ( V_624 ) ;
int V_349 ;
V_349 = F_1029 ( V_623 ) ;
if ( V_349 )
goto V_57;
return 0 ;
V_57:
return V_349 ;
}
void F_1030 ( struct V_572 * V_624 )
{
struct V_623 * V_623 = F_774 ( V_624 ) ;
F_1031 ( V_623 ) ;
F_1032 ( V_624 ) ;
}
void F_1033 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_696 ( & V_6 -> V_1197 . V_1046 ) ;
F_21 ( ! F_1034 ( & V_6 -> V_1197 . V_1198 ) ) ;
F_1035 ( V_6 ) ;
F_1036 ( V_6 ) ;
F_1037 ( V_48 ) ;
F_1038 () ;
F_1039 ( V_6 ) ;
F_1040 () ;
F_993 ( V_48 ) ;
F_1041 ( V_6 ) ;
F_1042 ( V_6 ) ;
F_1043 ( V_6 ) ;
}
void F_1044 ( struct V_623 * V_624 ,
struct V_509 * V_510 )
{
V_624 -> V_510 = V_510 ;
F_1045 ( & V_624 -> V_49 ,
& V_510 -> V_49 ) ;
}
int F_1046 ( struct V_5 * V_6 , bool V_28 )
{
unsigned V_13 = F_53 ( V_6 ) >= 6 ? V_1385 : V_1386 ;
T_10 V_1387 ;
if ( F_1047 ( V_6 -> V_1388 , V_13 , & V_1387 ) ) {
F_122 ( L_280 ) ;
return - V_1048 ;
}
if ( ! ! ( V_1387 & V_1389 ) == ! V_28 )
return 0 ;
if ( V_28 )
V_1387 &= ~ V_1389 ;
else
V_1387 |= V_1389 ;
if ( F_1048 ( V_6 -> V_1388 , V_13 , V_1387 ) ) {
F_122 ( L_281 ) ;
return - V_1048 ;
}
return 0 ;
}
struct V_1390 *
F_1049 ( struct V_5 * V_6 )
{
struct V_1390 * error ;
int V_1391 [] = {
V_204 ,
V_1392 ,
V_1393 ,
V_584 ,
} ;
int V_120 ;
if ( F_178 ( V_6 ) -> V_630 == 0 )
return NULL ;
error = F_504 ( sizeof( * error ) , V_1394 ) ;
if ( error == NULL )
return NULL ;
if ( F_252 ( V_6 ) || F_253 ( V_6 ) )
error -> V_1395 = F_17 ( V_878 ) ;
F_86 (dev_priv, i) {
error -> V_79 [ V_120 ] . V_1396 =
F_1050 ( V_6 ,
F_468 ( V_120 ) ) ;
if ( ! error -> V_79 [ V_120 ] . V_1396 )
continue;
error -> V_1251 [ V_120 ] . V_591 = F_17 ( F_77 ( V_120 ) ) ;
error -> V_1251 [ V_120 ] . V_1397 = F_17 ( F_659 ( V_120 ) ) ;
error -> V_1251 [ V_120 ] . V_49 = F_17 ( F_655 ( V_120 ) ) ;
error -> V_118 [ V_120 ] . V_591 = F_17 ( F_83 ( V_120 ) ) ;
error -> V_118 [ V_120 ] . V_276 = F_17 ( F_263 ( V_120 ) ) ;
if ( F_53 ( V_6 ) <= 3 ) {
error -> V_118 [ V_120 ] . V_227 = F_17 ( F_258 ( V_120 ) ) ;
error -> V_118 [ V_120 ] . V_545 = F_17 ( F_259 ( V_120 ) ) ;
}
if ( F_53 ( V_6 ) <= 7 && ! F_252 ( V_6 ) )
error -> V_118 [ V_120 ] . V_1037 = F_17 ( F_268 ( V_120 ) ) ;
if ( F_53 ( V_6 ) >= 4 ) {
error -> V_118 [ V_120 ] . V_1398 = F_17 ( F_264 ( V_120 ) ) ;
error -> V_118 [ V_120 ] . V_1399 = F_17 ( F_266 ( V_120 ) ) ;
}
error -> V_79 [ V_120 ] . V_1400 = F_17 ( F_328 ( V_120 ) ) ;
if ( F_158 ( V_6 ) )
error -> V_79 [ V_120 ] . V_1401 = F_17 ( F_1051 ( V_120 ) ) ;
}
error -> V_1402 = F_178 ( V_6 ) -> V_630 ;
if ( F_15 ( V_6 ) )
error -> V_1402 ++ ;
for ( V_120 = 0 ; V_120 < error -> V_1402 ; V_120 ++ ) {
enum V_78 V_80 = V_1391 [ V_120 ] ;
error -> V_78 [ V_120 ] . V_1396 =
F_1050 ( V_6 ,
F_79 ( V_80 ) ) ;
if ( ! error -> V_78 [ V_120 ] . V_1396 )
continue;
error -> V_78 [ V_120 ] . V_80 = V_80 ;
error -> V_78 [ V_120 ] . V_1403 = F_17 ( F_54 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_756 = F_17 ( F_368 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_1404 = F_17 ( F_370 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_763 = F_17 ( F_372 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_759 = F_17 ( F_374 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_1038 = F_17 ( F_376 ( V_80 ) ) ;
error -> V_78 [ V_120 ] . V_993 = F_17 ( F_378 ( V_80 ) ) ;
}
return error ;
}
void
F_1052 ( struct V_1405 * V_31 ,
struct V_1390 * error )
{
struct V_5 * V_6 = V_31 -> V_244 ;
int V_120 ;
if ( ! error )
return;
F_1053 ( V_31 , L_282 , F_178 ( V_6 ) -> V_630 ) ;
if ( F_252 ( V_6 ) || F_253 ( V_6 ) )
F_1053 ( V_31 , L_283 ,
error -> V_1395 ) ;
F_86 (dev_priv, i) {
F_1053 ( V_31 , L_284 , V_120 ) ;
F_1053 ( V_31 , L_285 ,
F_60 ( error -> V_79 [ V_120 ] . V_1396 ) ) ;
F_1053 ( V_31 , L_286 , error -> V_79 [ V_120 ] . V_1400 ) ;
F_1053 ( V_31 , L_287 , error -> V_79 [ V_120 ] . V_1401 ) ;
F_1053 ( V_31 , L_288 , V_120 ) ;
F_1053 ( V_31 , L_289 , error -> V_118 [ V_120 ] . V_591 ) ;
F_1053 ( V_31 , L_290 , error -> V_118 [ V_120 ] . V_276 ) ;
if ( F_53 ( V_6 ) <= 3 ) {
F_1053 ( V_31 , L_291 , error -> V_118 [ V_120 ] . V_227 ) ;
F_1053 ( V_31 , L_292 , error -> V_118 [ V_120 ] . V_545 ) ;
}
if ( F_53 ( V_6 ) <= 7 && ! F_252 ( V_6 ) )
F_1053 ( V_31 , L_293 , error -> V_118 [ V_120 ] . V_1037 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
F_1053 ( V_31 , L_294 , error -> V_118 [ V_120 ] . V_1398 ) ;
F_1053 ( V_31 , L_295 , error -> V_118 [ V_120 ] . V_1399 ) ;
}
F_1053 ( V_31 , L_296 , V_120 ) ;
F_1053 ( V_31 , L_289 , error -> V_1251 [ V_120 ] . V_591 ) ;
F_1053 ( V_31 , L_292 , error -> V_1251 [ V_120 ] . V_1397 ) ;
F_1053 ( V_31 , L_297 , error -> V_1251 [ V_120 ] . V_49 ) ;
}
for ( V_120 = 0 ; V_120 < error -> V_1402 ; V_120 ++ ) {
F_1053 ( V_31 , L_298 ,
F_778 ( error -> V_78 [ V_120 ] . V_80 ) ) ;
F_1053 ( V_31 , L_285 ,
F_60 ( error -> V_78 [ V_120 ] . V_1396 ) ) ;
F_1053 ( V_31 , L_299 , error -> V_78 [ V_120 ] . V_1403 ) ;
F_1053 ( V_31 , L_300 , error -> V_78 [ V_120 ] . V_756 ) ;
F_1053 ( V_31 , L_301 , error -> V_78 [ V_120 ] . V_1404 ) ;
F_1053 ( V_31 , L_302 , error -> V_78 [ V_120 ] . V_763 ) ;
F_1053 ( V_31 , L_303 , error -> V_78 [ V_120 ] . V_759 ) ;
F_1053 ( V_31 , L_304 , error -> V_78 [ V_120 ] . V_1038 ) ;
F_1053 ( V_31 , L_305 , error -> V_78 [ V_120 ] . V_993 ) ;
}
}
