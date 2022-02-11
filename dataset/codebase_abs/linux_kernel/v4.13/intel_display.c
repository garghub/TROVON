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
if ( F_79 ( V_6 ) )
V_28 = true ;
V_113 = F_80 ( V_80 ) ;
if ( F_81 ( V_6 , V_113 ) ) {
T_1 V_15 = F_17 ( F_54 ( V_80 ) ) ;
V_87 = ! ! ( V_15 & V_114 ) ;
F_82 ( V_6 , V_113 ) ;
} else {
V_87 = false ;
}
F_59 ( V_87 != V_28 ,
L_22 ,
F_73 ( V_79 ) , F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_83 ( struct V_5 * V_6 ,
enum V_115 V_115 , bool V_28 )
{
T_1 V_15 ;
bool V_87 ;
V_15 = F_17 ( F_84 ( V_115 ) ) ;
V_87 = ! ! ( V_15 & V_116 ) ;
F_59 ( V_87 != V_28 ,
L_23 ,
F_85 ( V_115 ) , F_60 ( V_28 ) , F_60 ( V_87 ) ) ;
}
static void F_86 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
int V_117 ;
if ( F_53 ( V_6 ) >= 4 ) {
T_1 V_15 = F_17 ( F_84 ( V_79 ) ) ;
F_59 ( V_15 & V_116 ,
L_24 ,
F_85 ( V_79 ) ) ;
return;
}
F_87 (dev_priv, i) {
T_1 V_15 = F_17 ( F_84 ( V_117 ) ) ;
enum V_79 V_118 = ( V_15 & V_119 ) >>
V_120 ;
F_59 ( ( V_15 & V_116 ) && V_79 == V_118 ,
L_25 ,
F_85 ( V_117 ) , F_73 ( V_79 ) ) ;
}
}
static void F_88 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
int V_121 ;
if ( F_53 ( V_6 ) >= 9 ) {
F_89 (dev_priv, pipe, sprite) {
T_1 V_15 = F_17 ( F_90 ( V_79 , V_121 ) ) ;
F_59 ( V_15 & V_122 ,
L_26 ,
V_121 , F_73 ( V_79 ) ) ;
}
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
F_89 (dev_priv, pipe, sprite) {
T_1 V_15 = F_17 ( F_91 ( V_79 , V_123 + V_121 ) ) ;
F_59 ( V_15 & V_124 ,
L_27 ,
F_92 ( V_79 , V_121 ) , F_73 ( V_79 ) ) ;
}
} else if ( F_53 ( V_6 ) >= 7 ) {
T_1 V_15 = F_17 ( F_93 ( V_79 ) ) ;
F_59 ( V_15 & V_125 ,
L_27 ,
F_85 ( V_79 ) , F_73 ( V_79 ) ) ;
} else if ( F_53 ( V_6 ) >= 5 || F_94 ( V_6 ) ) {
T_1 V_15 = F_17 ( F_95 ( V_79 ) ) ;
F_59 ( V_15 & V_126 ,
L_27 ,
F_85 ( V_79 ) , F_73 ( V_79 ) ) ;
}
}
static void F_96 ( struct V_127 * V_50 )
{
if ( F_97 ( F_98 ( V_50 ) == 0 ) )
F_99 ( V_50 ) ;
}
void F_100 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_1 V_15 ;
bool V_128 ;
V_15 = F_17 ( F_101 ( V_79 ) ) ;
V_128 = ! ! ( V_15 & V_129 ) ;
F_59 ( V_128 ,
L_28 ,
F_73 ( V_79 ) ) ;
}
static bool F_102 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_100 , T_1 V_15 )
{
if ( ( V_15 & V_130 ) == 0 )
return false ;
if ( F_103 ( V_6 ) ) {
T_1 V_131 = F_17 ( F_104 ( V_79 ) ) ;
if ( ( V_131 & V_132 ) != V_100 )
return false ;
} else if ( F_12 ( V_6 ) ) {
if ( ( V_15 & V_133 ) != F_105 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_134 ) != ( V_79 << 30 ) )
return false ;
}
return true ;
}
static bool F_106 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_135 ) == 0 )
return false ;
if ( F_103 ( V_6 ) ) {
if ( ( V_15 & V_136 ) != F_107 ( V_79 ) )
return false ;
} else if ( F_12 ( V_6 ) ) {
if ( ( V_15 & V_137 ) != F_108 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_138 ) != F_109 ( V_79 ) )
return false ;
}
return true ;
}
static bool F_110 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_139 ) == 0 )
return false ;
if ( F_103 ( V_6 ) ) {
if ( ( V_15 & V_140 ) != F_111 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_141 ) != F_112 ( V_79 ) )
return false ;
}
return true ;
}
static bool F_113 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_1 V_15 )
{
if ( ( V_15 & V_142 ) == 0 )
return false ;
if ( F_103 ( V_6 ) ) {
if ( ( V_15 & V_140 ) != F_111 ( V_79 ) )
return false ;
} else {
if ( ( V_15 & V_143 ) != F_114 ( V_79 ) )
return false ;
}
return true ;
}
static void F_115 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_3 V_13 ,
T_1 V_100 )
{
T_1 V_15 = F_17 ( V_13 ) ;
F_59 ( F_102 ( V_6 , V_79 , V_100 , V_15 ) ,
L_29 ,
F_116 ( V_13 ) , F_73 ( V_79 ) ) ;
F_59 ( F_117 ( V_6 ) && ( V_15 & V_130 ) == 0
&& ( V_15 & V_144 ) ,
L_30 ) ;
}
static void F_118 ( struct V_5 * V_6 ,
enum V_79 V_79 , T_3 V_13 )
{
T_1 V_15 = F_17 ( V_13 ) ;
F_59 ( F_106 ( V_6 , V_79 , V_15 ) ,
L_31 ,
F_116 ( V_13 ) , F_73 ( V_79 ) ) ;
F_59 ( F_117 ( V_6 ) && ( V_15 & V_135 ) == 0
&& ( V_15 & V_145 ) ,
L_32 ) ;
}
static void F_119 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_1 V_15 ;
F_115 ( V_6 , V_79 , V_146 , V_147 ) ;
F_115 ( V_6 , V_79 , V_148 , V_149 ) ;
F_115 ( V_6 , V_79 , V_150 , V_151 ) ;
V_15 = F_17 ( V_152 ) ;
F_59 ( F_113 ( V_6 , V_79 , V_15 ) ,
L_33 ,
F_73 ( V_79 ) ) ;
V_15 = F_17 ( V_103 ) ;
F_59 ( F_110 ( V_6 , V_79 , V_15 ) ,
L_34 ,
F_73 ( V_79 ) ) ;
F_118 ( V_6 , V_79 , V_153 ) ;
F_118 ( V_6 , V_79 , V_154 ) ;
F_118 ( V_6 , V_79 , V_155 ) ;
}
static void F_120 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_121 ( F_58 ( V_79 ) , V_23 -> V_156 . V_30 ) ;
F_122 ( F_58 ( V_79 ) ) ;
F_123 ( 150 ) ;
if ( F_55 ( V_6 ,
F_58 ( V_79 ) ,
V_157 ,
V_157 ,
1 ) )
F_124 ( L_35 , V_79 ) ;
}
static void F_125 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_126 ( V_6 , V_79 ) ;
F_69 ( V_6 , V_79 ) ;
if ( V_23 -> V_156 . V_30 & V_88 )
F_120 ( V_50 , V_23 ) ;
F_121 ( F_127 ( V_79 ) , V_23 -> V_156 . V_158 ) ;
F_122 ( F_127 ( V_79 ) ) ;
}
static void F_128 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_159 V_160 = F_129 ( V_79 ) ;
T_1 V_161 ;
F_3 ( & V_6 -> V_9 ) ;
V_161 = F_130 ( V_6 , V_79 , F_131 ( V_160 ) ) ;
V_161 |= V_162 ;
F_132 ( V_6 , V_79 , F_131 ( V_160 ) , V_161 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_123 ( 1 ) ;
F_121 ( F_58 ( V_79 ) , V_23 -> V_156 . V_30 ) ;
if ( F_55 ( V_6 ,
F_58 ( V_79 ) , V_157 , V_157 ,
1 ) )
F_124 ( L_36 , V_79 ) ;
}
static void F_133 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
F_126 ( V_6 , V_79 ) ;
F_69 ( V_6 , V_79 ) ;
if ( V_23 -> V_156 . V_30 & V_88 )
F_128 ( V_50 , V_23 ) ;
if ( V_79 != V_98 ) {
F_121 ( V_163 , V_79 == V_105 ? V_164 : V_165 ) ;
F_121 ( F_127 ( V_105 ) , V_23 -> V_156 . V_158 ) ;
F_121 ( V_163 , 0 ) ;
V_6 -> V_166 [ V_79 ] = V_23 -> V_156 . V_158 ;
F_21 ( ( F_17 ( F_58 ( V_105 ) ) & V_167 ) == 0 ) ;
} else {
F_121 ( F_127 ( V_79 ) , V_23 -> V_156 . V_158 ) ;
F_122 ( F_127 ( V_79 ) ) ;
}
}
static int F_134 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
int V_168 = 0 ;
F_135 (&dev_priv->drm, crtc) {
V_168 += V_50 -> V_49 . V_28 -> V_72 &&
F_32 ( V_50 -> V_75 , V_169 ) ;
}
return V_168 ;
}
static void F_136 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_3 V_13 = F_58 ( V_50 -> V_79 ) ;
T_1 V_30 = V_50 -> V_75 -> V_156 . V_30 ;
int V_117 ;
F_126 ( V_6 , V_50 -> V_79 ) ;
if ( F_137 ( V_6 ) && ! F_79 ( V_6 ) )
F_69 ( V_6 , V_50 -> V_79 ) ;
if ( F_79 ( V_6 ) && F_134 ( V_6 ) > 0 ) {
V_30 |= V_170 ;
F_121 ( F_58 ( ! V_50 -> V_79 ) ,
F_17 ( F_58 ( ! V_50 -> V_79 ) ) | V_170 ) ;
}
F_121 ( V_13 , 0 ) ;
F_121 ( V_13 , V_30 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
F_121 ( F_127 ( V_50 -> V_79 ) ,
V_50 -> V_75 -> V_156 . V_158 ) ;
} else {
F_121 ( V_13 , V_30 ) ;
}
for ( V_117 = 0 ; V_117 < 3 ; V_117 ++ ) {
F_121 ( V_13 , V_30 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
}
}
static void F_138 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
if ( F_79 ( V_6 ) &&
F_32 ( V_50 -> V_75 , V_169 ) &&
! F_134 ( V_6 ) ) {
F_121 ( F_58 ( V_105 ) ,
F_17 ( F_58 ( V_105 ) ) & ~ V_170 ) ;
F_121 ( F_58 ( V_98 ) ,
F_17 ( F_58 ( V_98 ) ) & ~ V_170 ) ;
}
if ( F_79 ( V_6 ) )
return;
F_126 ( V_6 , V_79 ) ;
F_121 ( F_58 ( V_79 ) , V_167 ) ;
F_122 ( F_58 ( V_79 ) ) ;
}
static void F_139 ( struct V_5 * V_6 , enum V_79 V_79 )
{
T_1 V_15 ;
F_126 ( V_6 , V_79 ) ;
V_15 = V_171 |
V_172 | V_167 ;
if ( V_79 != V_98 )
V_15 |= V_173 ;
F_121 ( F_58 ( V_79 ) , V_15 ) ;
F_122 ( F_58 ( V_79 ) ) ;
}
static void F_140 ( struct V_5 * V_6 , enum V_79 V_79 )
{
enum V_159 V_160 = F_129 ( V_79 ) ;
T_1 V_15 ;
F_126 ( V_6 , V_79 ) ;
V_15 = V_174 |
V_172 | V_167 ;
if ( V_79 != V_98 )
V_15 |= V_173 ;
F_121 ( F_58 ( V_79 ) , V_15 ) ;
F_122 ( F_58 ( V_79 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
V_15 = F_130 ( V_6 , V_79 , F_131 ( V_160 ) ) ;
V_15 &= ~ V_162 ;
F_132 ( V_6 , V_79 , F_131 ( V_160 ) , V_15 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
void F_141 ( struct V_5 * V_6 ,
struct V_175 * V_176 ,
unsigned int V_177 )
{
T_1 V_178 ;
T_3 V_179 ;
switch ( V_176 -> V_160 ) {
case V_180 :
V_178 = V_181 ;
V_179 = F_58 ( 0 ) ;
break;
case V_182 :
V_178 = V_183 ;
V_179 = F_58 ( 0 ) ;
V_177 <<= 4 ;
break;
case V_184 :
V_178 = V_185 ;
V_179 = V_186 ;
break;
default:
F_142 () ;
}
if ( F_55 ( V_6 ,
V_179 , V_178 , V_177 ,
1000 ) )
F_7 ( 1 , L_37 ,
F_143 ( V_176 -> V_160 ) , F_17 ( V_179 ) & V_178 , V_177 ) ;
}
static void F_144 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
struct V_66 * V_66 = F_47 ( V_6 ,
V_79 ) ;
T_3 V_13 ;
T_2 V_15 , V_187 ;
F_145 ( V_6 , V_66 -> V_75 -> V_188 ) ;
F_146 ( V_6 , V_79 ) ;
F_147 ( V_6 , V_79 ) ;
if ( F_103 ( V_6 ) ) {
V_13 = F_148 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 |= V_189 ;
F_121 ( V_13 , V_15 ) ;
}
V_13 = F_101 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_187 = F_17 ( F_54 ( V_79 ) ) ;
if ( F_117 ( V_6 ) ) {
V_15 &= ~ V_190 ;
if ( F_32 ( V_66 -> V_75 , V_191 ) )
V_15 |= V_192 ;
else
V_15 |= V_187 & V_190 ;
}
V_15 &= ~ V_193 ;
if ( ( V_187 & V_194 ) == V_195 )
if ( F_117 ( V_6 ) &&
F_32 ( V_66 -> V_75 , V_196 ) )
V_15 |= V_197 ;
else
V_15 |= V_198 ;
else
V_15 |= V_199 ;
F_121 ( V_13 , V_15 | V_129 ) ;
if ( F_55 ( V_6 ,
V_13 , V_200 , V_200 ,
100 ) )
F_124 ( L_38 , F_73 ( V_79 ) ) ;
}
static void F_149 ( struct V_5 * V_6 ,
enum V_78 V_80 )
{
T_1 V_15 , V_187 ;
F_146 ( V_6 , (enum V_79 ) V_80 ) ;
F_147 ( V_6 , V_201 ) ;
V_15 = F_17 ( F_148 ( V_98 ) ) ;
V_15 |= V_189 ;
F_121 ( F_148 ( V_98 ) , V_15 ) ;
V_15 = V_129 ;
V_187 = F_17 ( F_54 ( V_80 ) ) ;
if ( ( V_187 & V_202 ) ==
V_195 )
V_15 |= V_198 ;
else
V_15 |= V_199 ;
F_121 ( V_203 , V_15 ) ;
if ( F_55 ( V_6 ,
V_203 ,
V_200 ,
V_200 ,
100 ) )
F_124 ( L_39 ) ;
}
static void F_150 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
T_3 V_13 ;
T_2 V_15 ;
F_151 ( V_6 , V_79 ) ;
F_152 ( V_6 , V_79 ) ;
F_119 ( V_6 , V_79 ) ;
V_13 = F_101 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 &= ~ V_129 ;
F_121 ( V_13 , V_15 ) ;
if ( F_55 ( V_6 ,
V_13 , V_200 , 0 ,
50 ) )
F_124 ( L_40 , F_73 ( V_79 ) ) ;
if ( F_103 ( V_6 ) ) {
V_13 = F_148 ( V_79 ) ;
V_15 = F_17 ( V_13 ) ;
V_15 &= ~ V_189 ;
F_121 ( V_13 , V_15 ) ;
}
}
void F_153 ( struct V_5 * V_6 )
{
T_1 V_15 ;
V_15 = F_17 ( V_203 ) ;
V_15 &= ~ V_129 ;
F_121 ( V_203 , V_15 ) ;
if ( F_55 ( V_6 ,
V_203 , V_200 , 0 ,
50 ) )
F_124 ( L_41 ) ;
V_15 = F_17 ( F_148 ( V_98 ) ) ;
V_15 &= ~ V_189 ;
F_121 ( F_148 ( V_98 ) , V_15 ) ;
}
enum V_78 F_154 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
F_21 ( ! V_50 -> V_75 -> V_204 ) ;
if ( F_155 ( V_6 ) )
return V_201 ;
else
return (enum V_78 ) V_50 -> V_79 ;
}
static void F_156 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
T_3 V_13 ;
T_1 V_15 ;
F_157 ( L_42 , F_73 ( V_79 ) ) ;
F_86 ( V_6 , V_79 ) ;
F_158 ( V_6 , V_79 ) ;
F_88 ( V_6 , V_79 ) ;
if ( F_159 ( V_6 ) ) {
if ( F_32 ( V_50 -> V_75 , V_205 ) )
F_160 ( V_6 ) ;
else
F_161 ( V_6 , V_79 ) ;
} else {
if ( V_50 -> V_75 -> V_204 ) {
F_162 ( V_6 ,
(enum V_79 ) F_154 ( V_50 ) ) ;
F_67 ( V_6 ,
(enum V_79 ) V_80 ) ;
}
}
V_13 = F_54 ( V_80 ) ;
V_15 = F_17 ( V_13 ) ;
if ( V_15 & V_114 ) {
F_21 ( ! F_79 ( V_6 ) ) ;
return;
}
F_121 ( V_13 , V_15 | V_114 ) ;
F_122 ( V_13 ) ;
if ( V_48 -> V_206 == 0 &&
F_56 ( F_163 ( V_50 ) != V_50 -> V_207 , 50 ) )
F_124 ( L_43 , F_73 ( V_79 ) ) ;
}
static void F_164 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
enum V_79 V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_15 ;
F_157 ( L_44 , F_73 ( V_79 ) ) ;
F_86 ( V_6 , V_79 ) ;
F_158 ( V_6 , V_79 ) ;
F_88 ( V_6 , V_79 ) ;
V_13 = F_54 ( V_80 ) ;
V_15 = F_17 ( V_13 ) ;
if ( ( V_15 & V_114 ) == 0 )
return;
if ( V_50 -> V_75 -> V_208 )
V_15 &= ~ V_209 ;
if ( ! F_79 ( V_6 ) )
V_15 &= ~ V_114 ;
F_121 ( V_13 , V_15 ) ;
if ( ( V_15 & V_114 ) == 0 )
F_52 ( V_50 ) ;
}
static unsigned int F_165 ( const struct V_5 * V_6 )
{
return F_50 ( V_6 ) ? 2048 : 4096 ;
}
static unsigned int
F_166 ( const struct V_210 * V_74 , int V_115 )
{
struct V_5 * V_6 = F_35 ( V_74 -> V_48 ) ;
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
switch ( V_74 -> V_213 ) {
case V_214 :
return V_211 ;
case V_215 :
if ( F_50 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_216 :
if ( F_50 ( V_6 ) || F_167 ( V_6 ) )
return 128 ;
else
return 512 ;
case V_217 :
switch ( V_211 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_168 ( V_211 ) ;
return V_211 ;
}
break;
default:
F_168 ( V_74 -> V_213 ) ;
return V_211 ;
}
}
static unsigned int
F_169 ( const struct V_210 * V_74 , int V_115 )
{
if ( V_74 -> V_213 == V_214 )
return 1 ;
else
return F_165 ( F_35 ( V_74 -> V_48 ) ) /
F_166 ( V_74 , V_115 ) ;
}
static void F_170 ( const struct V_210 * V_74 , int V_115 ,
unsigned int * V_218 ,
unsigned int * V_219 )
{
unsigned int V_220 = F_166 ( V_74 , V_115 ) ;
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
* V_218 = V_220 / V_211 ;
* V_219 = F_165 ( F_35 ( V_74 -> V_48 ) ) / V_220 ;
}
unsigned int
F_171 ( const struct V_210 * V_74 ,
int V_115 , unsigned int V_221 )
{
unsigned int V_219 = F_169 ( V_74 , V_115 ) ;
return F_172 ( V_221 , V_219 ) ;
}
unsigned int F_173 ( const struct V_222 * V_223 )
{
unsigned int V_224 = 0 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < F_174 ( V_223 -> V_115 ) ; V_117 ++ )
V_224 += V_223 -> V_115 [ V_117 ] . V_225 * V_223 -> V_115 [ V_117 ] . V_221 ;
return V_224 ;
}
static void
F_175 ( struct V_226 * V_227 ,
const struct V_210 * V_74 ,
unsigned int V_228 )
{
V_227 -> type = V_229 ;
if ( F_176 ( V_228 ) ) {
V_227 -> type = V_230 ;
V_227 -> V_231 = F_177 ( V_74 ) -> V_223 ;
}
}
static unsigned int F_178 ( const struct V_5 * V_6 )
{
if ( F_79 ( V_6 ) )
return 16 * 1024 ;
else if ( F_179 ( V_6 ) )
return 256 ;
else if ( F_75 ( V_6 ) || F_76 ( V_6 ) )
return 32 ;
else
return 4 * 1024 ;
}
static unsigned int F_180 ( const struct V_5 * V_6 )
{
if ( F_181 ( V_6 ) -> V_232 >= 9 )
return 256 * 1024 ;
else if ( F_182 ( V_6 ) || F_183 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
return 128 * 1024 ;
else if ( F_181 ( V_6 ) -> V_232 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_184 ( const struct V_210 * V_74 ,
int V_115 )
{
struct V_5 * V_6 = F_35 ( V_74 -> V_48 ) ;
if ( V_74 -> V_212 -> V_212 == V_233 && V_115 == 1 )
return 4096 ;
switch ( V_74 -> V_213 ) {
case V_214 :
return F_180 ( V_6 ) ;
case V_215 :
if ( F_53 ( V_6 ) >= 9 )
return 256 * 1024 ;
return 0 ;
case V_216 :
case V_217 :
return 1 * 1024 * 1024 ;
default:
F_168 ( V_74 -> V_213 ) ;
return 0 ;
}
}
struct V_234 *
F_185 ( struct V_210 * V_74 , unsigned int V_228 )
{
struct V_47 * V_48 = V_74 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_235 * V_236 = F_186 ( V_74 ) ;
struct V_226 V_227 ;
struct V_234 * V_237 ;
T_1 V_238 ;
F_21 ( ! F_187 ( & V_48 -> V_239 ) ) ;
V_238 = F_184 ( V_74 , 0 ) ;
F_175 ( & V_227 , V_74 , V_228 ) ;
if ( F_188 ( V_6 ) && V_238 < 256 * 1024 )
V_238 = 256 * 1024 ;
F_189 ( V_6 ) ;
V_237 = F_190 ( V_236 , V_238 , & V_227 ) ;
if ( F_191 ( V_237 ) )
goto V_57;
if ( F_192 ( V_237 ) ) {
if ( F_193 ( V_237 ) == 0 )
F_194 ( V_237 ) ;
}
F_195 ( V_237 ) ;
V_57:
F_196 ( V_6 ) ;
return V_237 ;
}
void F_197 ( struct V_234 * V_237 )
{
F_198 ( & V_237 -> V_240 -> V_241 -> V_242 . V_239 ) ;
F_199 ( V_237 ) ;
F_200 ( V_237 ) ;
F_201 ( V_237 ) ;
}
static int F_202 ( const struct V_210 * V_74 , int V_115 ,
unsigned int V_228 )
{
if ( F_176 ( V_228 ) )
return F_177 ( V_74 ) -> V_231 [ V_115 ] . V_243 ;
else
return V_74 -> V_244 [ V_115 ] ;
}
T_1 F_203 ( int V_245 , int V_246 ,
const struct V_247 * V_28 ,
int V_115 )
{
const struct V_210 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
unsigned int V_243 = V_74 -> V_244 [ V_115 ] ;
return V_246 * V_243 + V_245 * V_211 ;
}
void F_204 ( int * V_245 , int * V_246 ,
const struct V_247 * V_28 ,
int V_115 )
{
const struct V_248 * V_249 = F_177 ( V_28 -> V_49 . V_74 ) ;
unsigned int V_228 = V_28 -> V_49 . V_228 ;
if ( F_176 ( V_228 ) ) {
* V_245 += V_249 -> V_231 [ V_115 ] . V_245 ;
* V_246 += V_249 -> V_231 [ V_115 ] . V_246 ;
} else {
* V_245 += V_249 -> V_250 [ V_115 ] . V_245 ;
* V_246 += V_249 -> V_250 [ V_115 ] . V_246 ;
}
}
static T_1 F_205 ( int * V_245 , int * V_246 ,
unsigned int V_218 ,
unsigned int V_219 ,
unsigned int V_251 ,
unsigned int V_252 ,
T_1 V_253 ,
T_1 V_254 )
{
unsigned int V_255 = V_252 * V_218 ;
unsigned int V_256 ;
F_21 ( V_253 & ( V_251 - 1 ) ) ;
F_21 ( V_254 & ( V_251 - 1 ) ) ;
F_21 ( V_254 > V_253 ) ;
V_256 = ( V_253 - V_254 ) / V_251 ;
* V_246 += V_256 / V_252 * V_219 ;
* V_245 += V_256 % V_252 * V_218 ;
* V_246 += * V_245 / V_255 * V_219 ;
* V_245 %= V_255 ;
return V_254 ;
}
static T_1 F_206 ( int * V_245 , int * V_246 ,
const struct V_247 * V_28 , int V_115 ,
T_1 V_253 , T_1 V_254 )
{
const struct V_5 * V_6 = F_35 ( V_28 -> V_49 . V_115 -> V_48 ) ;
const struct V_210 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
unsigned int V_228 = V_28 -> V_49 . V_228 ;
unsigned int V_243 = F_202 ( V_74 , V_115 , V_228 ) ;
F_21 ( V_254 > V_253 ) ;
if ( V_74 -> V_213 != V_214 ) {
unsigned int V_251 , V_218 , V_219 ;
unsigned int V_252 ;
V_251 = F_165 ( V_6 ) ;
F_170 ( V_74 , V_115 , & V_218 , & V_219 ) ;
if ( F_176 ( V_228 ) ) {
V_252 = V_243 / V_219 ;
F_207 ( V_218 , V_219 ) ;
} else {
V_252 = V_243 / ( V_218 * V_211 ) ;
}
F_205 ( V_245 , V_246 , V_218 , V_219 ,
V_251 , V_252 ,
V_253 , V_254 ) ;
} else {
V_253 += * V_246 * V_243 + * V_245 * V_211 ;
* V_246 = ( V_253 - V_254 ) / V_243 ;
* V_245 = ( ( V_253 - V_254 ) - * V_246 * V_243 ) / V_211 ;
}
return V_254 ;
}
static T_1 F_208 ( const struct V_5 * V_6 ,
int * V_245 , int * V_246 ,
const struct V_210 * V_74 , int V_115 ,
unsigned int V_243 ,
unsigned int V_228 ,
T_1 V_238 )
{
V_40 V_257 = V_74 -> V_213 ;
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
T_1 V_258 , V_259 ;
if ( V_238 )
V_238 -- ;
if ( V_257 != V_214 ) {
unsigned int V_251 , V_218 , V_219 ;
unsigned int V_260 , V_256 , V_252 ;
V_251 = F_165 ( V_6 ) ;
F_170 ( V_74 , V_115 , & V_218 , & V_219 ) ;
if ( F_176 ( V_228 ) ) {
V_252 = V_243 / V_219 ;
F_207 ( V_218 , V_219 ) ;
} else {
V_252 = V_243 / ( V_218 * V_211 ) ;
}
V_260 = * V_246 / V_219 ;
* V_246 %= V_219 ;
V_256 = * V_245 / V_218 ;
* V_245 %= V_218 ;
V_258 = ( V_260 * V_252 + V_256 ) * V_251 ;
V_259 = V_258 & ~ V_238 ;
F_205 ( V_245 , V_246 , V_218 , V_219 ,
V_251 , V_252 ,
V_258 , V_259 ) ;
} else {
V_258 = * V_246 * V_243 + * V_245 * V_211 ;
V_259 = V_258 & ~ V_238 ;
* V_246 = ( V_258 & V_238 ) / V_243 ;
* V_245 = ( ( V_258 & V_238 ) - * V_246 * V_243 ) / V_211 ;
}
return V_259 ;
}
T_1 F_209 ( int * V_245 , int * V_246 ,
const struct V_247 * V_28 ,
int V_115 )
{
struct V_261 * V_261 = F_210 ( V_28 -> V_49 . V_115 ) ;
struct V_5 * V_6 = F_35 ( V_261 -> V_49 . V_48 ) ;
const struct V_210 * V_74 = V_28 -> V_49 . V_74 ;
unsigned int V_228 = V_28 -> V_49 . V_228 ;
int V_243 = F_202 ( V_74 , V_115 , V_228 ) ;
T_1 V_238 ;
if ( V_261 -> V_262 == V_263 )
V_238 = F_178 ( V_6 ) ;
else
V_238 = F_184 ( V_74 , V_115 ) ;
return F_208 ( V_6 , V_245 , V_246 , V_74 , V_115 , V_243 ,
V_228 , V_238 ) ;
}
static void F_211 ( int * V_245 , int * V_246 ,
const struct V_210 * V_74 , int V_115 )
{
unsigned int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
unsigned int V_243 = V_74 -> V_244 [ V_115 ] ;
T_1 V_264 = V_74 -> V_265 [ V_115 ] ;
* V_246 = V_264 / V_243 ;
* V_245 = V_264 % V_243 / V_211 ;
}
static unsigned int F_212 ( V_40 V_257 )
{
switch ( V_257 ) {
case V_215 :
return V_266 ;
case V_216 :
return V_267 ;
default:
return V_268 ;
}
}
static int
F_213 ( struct V_5 * V_6 ,
struct V_210 * V_74 )
{
struct V_248 * V_249 = F_177 ( V_74 ) ;
struct V_222 * V_223 = & V_249 -> V_223 ;
T_1 V_269 = 0 ;
unsigned int V_270 = 0 ;
int V_117 , V_271 = V_74 -> V_212 -> V_271 ;
unsigned int V_251 = F_165 ( V_6 ) ;
for ( V_117 = 0 ; V_117 < V_271 ; V_117 ++ ) {
unsigned int V_225 , V_221 ;
unsigned int V_211 , V_224 ;
T_1 V_258 ;
int V_245 , V_246 ;
V_211 = V_74 -> V_212 -> V_211 [ V_117 ] ;
V_225 = F_214 ( V_74 -> V_225 , V_74 , V_117 ) ;
V_221 = F_215 ( V_74 -> V_221 , V_74 , V_117 ) ;
F_211 ( & V_245 , & V_246 , V_74 , V_117 ) ;
if ( F_216 ( V_249 -> V_236 ) &&
( V_245 + V_225 ) * V_211 > V_74 -> V_244 [ V_117 ] ) {
F_157 ( L_45 ,
V_117 , V_74 -> V_265 [ V_117 ] ) ;
return - V_272 ;
}
V_249 -> V_250 [ V_117 ] . V_245 = V_245 ;
V_249 -> V_250 [ V_117 ] . V_246 = V_246 ;
V_258 = F_208 ( V_6 , & V_245 , & V_246 ,
V_74 , V_117 , V_74 -> V_244 [ V_117 ] ,
V_273 , V_251 ) ;
V_258 /= V_251 ;
if ( V_74 -> V_213 != V_214 ) {
unsigned int V_218 , V_219 ;
unsigned int V_252 ;
struct V_274 V_275 ;
F_170 ( V_74 , V_117 , & V_218 , & V_219 ) ;
V_223 -> V_115 [ V_117 ] . V_258 = V_258 ;
V_223 -> V_115 [ V_117 ] . V_276 = F_217 ( V_74 -> V_244 [ V_117 ] , V_218 * V_211 ) ;
V_223 -> V_115 [ V_117 ] . V_225 = F_217 ( V_245 + V_225 , V_218 ) ;
V_223 -> V_115 [ V_117 ] . V_221 = F_217 ( V_246 + V_221 , V_219 ) ;
V_249 -> V_231 [ V_117 ] . V_243 =
V_223 -> V_115 [ V_117 ] . V_221 * V_219 ;
V_224 = V_223 -> V_115 [ V_117 ] . V_276 * V_223 -> V_115 [ V_117 ] . V_221 ;
if ( V_245 != 0 )
V_224 ++ ;
V_275 . V_277 = V_245 ;
V_275 . y1 = V_246 ;
V_275 . V_278 = V_245 + V_225 ;
V_275 . V_279 = V_246 + V_221 ;
F_218 ( & V_275 ,
V_223 -> V_115 [ V_117 ] . V_225 * V_218 ,
V_223 -> V_115 [ V_117 ] . V_221 * V_219 ,
V_280 ) ;
V_245 = V_275 . V_277 ;
V_246 = V_275 . y1 ;
V_252 = V_249 -> V_231 [ V_117 ] . V_243 / V_219 ;
F_207 ( V_218 , V_219 ) ;
F_205 ( & V_245 , & V_246 ,
V_218 , V_219 ,
V_251 , V_252 ,
V_269 * V_251 , 0 ) ;
V_269 += V_223 -> V_115 [ V_117 ] . V_225 * V_223 -> V_115 [ V_117 ] . V_221 ;
V_249 -> V_231 [ V_117 ] . V_245 = V_245 ;
V_249 -> V_231 [ V_117 ] . V_246 = V_246 ;
} else {
V_224 = F_217 ( ( V_246 + V_221 ) * V_74 -> V_244 [ V_117 ] +
V_245 * V_211 , V_251 ) ;
}
V_270 = V_44 ( V_270 , V_258 + V_224 ) ;
}
if ( V_270 * V_251 > V_249 -> V_236 -> V_49 . V_224 ) {
F_157 ( L_46 ,
V_270 * V_251 , V_249 -> V_236 -> V_49 . V_224 ) ;
return - V_272 ;
}
return 0 ;
}
static int F_219 ( int V_212 )
{
switch ( V_212 ) {
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
static int F_220 ( int V_212 , bool V_295 , bool V_296 )
{
switch ( V_212 ) {
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
F_221 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_304 * V_305 = & V_6 -> V_305 ;
struct V_235 * V_236 = NULL ;
struct V_306 V_307 = { 0 } ;
struct V_210 * V_74 = & V_303 -> V_74 -> V_49 ;
T_1 V_308 = F_222 ( V_303 -> V_49 , V_309 ) ;
T_1 V_310 = F_223 ( V_303 -> V_49 + V_303 -> V_224 ,
V_309 ) ;
V_310 -= V_308 ;
if ( V_303 -> V_224 == 0 )
return false ;
if ( V_310 * 2 > V_305 -> V_311 )
return false ;
F_3 ( & V_48 -> V_239 ) ;
V_236 = F_224 ( V_6 ,
V_308 ,
V_308 ,
V_310 ) ;
F_5 ( & V_48 -> V_239 ) ;
if ( ! V_236 )
return false ;
if ( V_303 -> V_312 == V_266 )
V_236 -> V_313 = V_74 -> V_244 [ 0 ] | V_266 ;
V_307 . V_314 = V_74 -> V_212 -> V_212 ;
V_307 . V_225 = V_74 -> V_225 ;
V_307 . V_221 = V_74 -> V_221 ;
V_307 . V_244 [ 0 ] = V_74 -> V_244 [ 0 ] ;
V_307 . V_213 [ 0 ] = V_74 -> V_213 ;
V_307 . V_315 = V_316 ;
if ( F_225 ( F_177 ( V_74 ) , V_236 , & V_307 ) ) {
F_157 ( L_47 ) ;
goto V_317;
}
F_157 ( L_48 , V_236 ) ;
return true ;
V_317:
F_226 ( V_236 ) ;
return false ;
}
static void
F_227 ( struct V_318 * V_115 )
{
if ( V_115 -> V_74 == V_115 -> V_28 -> V_74 )
return;
if ( V_115 -> V_28 -> V_74 )
F_228 ( V_115 -> V_28 -> V_74 ) ;
V_115 -> V_28 -> V_74 = V_115 -> V_74 ;
if ( V_115 -> V_28 -> V_74 )
F_229 ( V_115 -> V_28 -> V_74 ) ;
}
static void
F_230 ( struct V_22 * V_45 ,
struct V_247 * V_319 ,
bool V_320 )
{
struct V_261 * V_115 = F_210 ( V_319 -> V_49 . V_115 ) ;
V_319 -> V_49 . V_320 = V_320 ;
if ( V_320 ) {
V_45 -> V_49 . V_321 |= F_231 ( F_232 ( & V_115 -> V_49 ) ) ;
V_45 -> V_322 |= F_231 ( V_115 -> V_262 ) ;
} else {
V_45 -> V_49 . V_321 &= ~ F_231 ( F_232 ( & V_115 -> V_49 ) ) ;
V_45 -> V_322 &= ~ F_231 ( V_115 -> V_262 ) ;
}
F_157 ( L_49 ,
V_45 -> V_49 . V_50 -> V_12 ,
V_45 -> V_322 ) ;
}
static void
F_233 ( struct V_66 * V_66 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_127 * V_323 ;
struct V_235 * V_236 ;
struct V_318 * V_73 = V_66 -> V_49 . V_73 ;
struct V_324 * V_319 = V_73 -> V_28 ;
struct V_27 * V_45 = V_66 -> V_49 . V_28 ;
struct V_261 * V_261 = F_210 ( V_73 ) ;
struct V_247 * V_325 =
F_234 ( V_319 ) ;
struct V_210 * V_74 ;
if ( ! V_303 -> V_74 )
return;
if ( F_221 ( V_66 , V_303 ) ) {
V_74 = & V_303 -> V_74 -> V_49 ;
goto V_326;
}
F_235 ( V_303 -> V_74 ) ;
F_236 (dev, c) {
struct V_247 * V_28 ;
if ( V_323 == & V_66 -> V_49 )
continue;
if ( ! F_42 ( V_323 ) -> V_72 )
continue;
V_28 = F_234 ( V_323 -> V_73 -> V_28 ) ;
if ( ! V_28 -> V_237 )
continue;
if ( F_237 ( V_28 ) == V_303 -> V_49 ) {
V_74 = V_323 -> V_73 -> V_74 ;
F_229 ( V_74 ) ;
goto V_326;
}
}
F_230 ( F_238 ( V_45 ) ,
F_234 ( V_319 ) ,
false ) ;
F_239 ( & V_66 -> V_49 ) ;
F_240 ( V_73 , V_66 ) ;
V_261 -> V_327 ( V_261 , V_66 ) ;
return;
V_326:
F_3 ( & V_48 -> V_239 ) ;
V_325 -> V_237 =
F_185 ( V_74 , V_73 -> V_28 -> V_228 ) ;
F_5 ( & V_48 -> V_239 ) ;
if ( F_191 ( V_325 -> V_237 ) ) {
F_124 ( L_50 ,
V_66 -> V_79 , F_241 ( V_325 -> V_237 ) ) ;
V_325 -> V_237 = NULL ;
F_228 ( V_74 ) ;
return;
}
V_319 -> V_328 = 0 ;
V_319 -> V_329 = 0 ;
V_319 -> V_330 = V_74 -> V_225 << 16 ;
V_319 -> V_331 = V_74 -> V_221 << 16 ;
V_319 -> V_332 = 0 ;
V_319 -> V_333 = 0 ;
V_319 -> V_334 = V_74 -> V_225 ;
V_319 -> V_335 = V_74 -> V_221 ;
V_325 -> V_49 . V_336 = F_242 ( V_319 ) ;
V_325 -> V_49 . V_337 = F_243 ( V_319 ) ;
V_236 = F_186 ( V_74 ) ;
if ( F_216 ( V_236 ) )
V_6 -> V_338 = true ;
F_229 ( V_74 ) ;
V_73 -> V_74 = V_73 -> V_28 -> V_74 = V_74 ;
V_73 -> V_50 = V_73 -> V_28 -> V_50 = & V_66 -> V_49 ;
F_230 ( F_238 ( V_45 ) ,
F_234 ( V_319 ) ,
true ) ;
F_244 ( F_210 ( V_73 ) -> V_339 ,
& V_236 -> V_340 ) ;
}
static int F_245 ( const struct V_210 * V_74 , int V_115 ,
unsigned int V_228 )
{
int V_211 = V_74 -> V_212 -> V_211 [ V_115 ] ;
switch ( V_74 -> V_213 ) {
case V_214 :
case V_215 :
switch ( V_211 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_168 ( V_211 ) ;
break;
}
break;
case V_216 :
case V_217 :
switch ( V_211 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_168 ( V_211 ) ;
break;
}
break;
default:
F_168 ( V_74 -> V_213 ) ;
}
return 2048 ;
}
static int F_246 ( struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
int V_245 = V_319 -> V_49 . V_336 . V_277 >> 16 ;
int V_246 = V_319 -> V_49 . V_336 . y1 >> 16 ;
int V_341 = F_247 ( & V_319 -> V_49 . V_336 ) >> 16 ;
int V_342 = F_248 ( & V_319 -> V_49 . V_336 ) >> 16 ;
int V_343 = F_245 ( V_74 , 0 , V_228 ) ;
int V_344 = 4096 ;
T_1 V_238 , V_258 , V_345 = V_319 -> V_346 . V_258 ;
if ( V_341 > V_343 || V_342 > V_344 ) {
F_157 ( L_51 ,
V_341 , V_342 , V_343 , V_344 ) ;
return - V_272 ;
}
F_204 ( & V_245 , & V_246 , V_319 , 0 ) ;
V_258 = F_209 ( & V_245 , & V_246 , V_319 , 0 ) ;
V_238 = F_184 ( V_74 , 0 ) ;
if ( V_258 > V_345 )
V_258 = F_206 ( & V_245 , & V_246 , V_319 , 0 ,
V_258 , V_345 & ~ ( V_238 - 1 ) ) ;
if ( V_74 -> V_213 == V_215 ) {
int V_211 = V_74 -> V_212 -> V_211 [ 0 ] ;
while ( ( V_245 + V_341 ) * V_211 > V_74 -> V_244 [ 0 ] ) {
if ( V_258 == 0 ) {
F_157 ( L_52 ) ;
return - V_272 ;
}
V_258 = F_206 ( & V_245 , & V_246 , V_319 , 0 ,
V_258 , V_258 - V_238 ) ;
}
}
V_319 -> main. V_258 = V_258 ;
V_319 -> main. V_245 = V_245 ;
V_319 -> main. V_246 = V_246 ;
return 0 ;
}
static int F_249 ( struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
int V_343 = F_245 ( V_74 , 1 , V_228 ) ;
int V_344 = 4096 ;
int V_245 = V_319 -> V_49 . V_336 . V_277 >> 17 ;
int V_246 = V_319 -> V_49 . V_336 . y1 >> 17 ;
int V_341 = F_247 ( & V_319 -> V_49 . V_336 ) >> 17 ;
int V_342 = F_248 ( & V_319 -> V_49 . V_336 ) >> 17 ;
T_1 V_258 ;
F_204 ( & V_245 , & V_246 , V_319 , 1 ) ;
V_258 = F_209 ( & V_245 , & V_246 , V_319 , 1 ) ;
if ( V_341 > V_343 || V_342 > V_344 ) {
F_157 ( L_53 ,
V_341 , V_342 , V_343 , V_344 ) ;
return - V_272 ;
}
V_319 -> V_346 . V_258 = V_258 ;
V_319 -> V_346 . V_245 = V_245 ;
V_319 -> V_346 . V_246 = V_246 ;
return 0 ;
}
int F_250 ( struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
int V_347 ;
if ( ! V_319 -> V_49 . V_320 )
return 0 ;
if ( F_176 ( V_228 ) )
F_218 ( & V_319 -> V_49 . V_336 ,
V_74 -> V_225 << 16 , V_74 -> V_221 << 16 ,
V_280 ) ;
if ( V_74 -> V_212 -> V_212 == V_233 ) {
V_347 = F_249 ( V_319 ) ;
if ( V_347 )
return V_347 ;
} else {
V_319 -> V_346 . V_258 = ~ 0xfff ;
V_319 -> V_346 . V_245 = 0 ;
V_319 -> V_346 . V_246 = 0 ;
}
V_347 = F_246 ( V_319 ) ;
if ( V_347 )
return V_347 ;
return 0 ;
}
static T_1 F_251 ( const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
T_1 V_348 ;
V_348 = V_116 | V_349 ;
if ( F_94 ( V_6 ) || F_16 ( V_6 ) ||
F_252 ( V_6 ) || F_253 ( V_6 ) )
V_348 |= V_350 ;
if ( F_254 ( V_6 ) || F_255 ( V_6 ) )
V_348 |= V_351 ;
if ( F_53 ( V_6 ) < 4 )
V_348 |= F_256 ( V_50 -> V_79 ) ;
switch ( V_74 -> V_212 -> V_212 ) {
case V_282 :
V_348 |= V_281 ;
break;
case V_284 :
V_348 |= V_283 ;
break;
case V_286 :
V_348 |= V_285 ;
break;
case V_288 :
V_348 |= V_287 ;
break;
case V_290 :
V_348 |= V_289 ;
break;
case V_292 :
V_348 |= V_291 ;
break;
case V_294 :
V_348 |= V_293 ;
break;
default:
F_168 ( V_74 -> V_212 -> V_212 ) ;
return 0 ;
}
if ( F_53 ( V_6 ) >= 4 &&
V_74 -> V_213 == V_215 )
V_348 |= V_352 ;
if ( V_228 & V_353 )
V_348 |= V_354 ;
if ( V_228 & V_355 )
V_348 |= V_356 ;
return V_348 ;
}
int F_257 ( struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
int V_328 = V_319 -> V_49 . V_336 . V_277 >> 16 ;
int V_329 = V_319 -> V_49 . V_336 . y1 >> 16 ;
T_1 V_258 ;
F_204 ( & V_328 , & V_329 , V_319 , 0 ) ;
if ( F_53 ( V_6 ) >= 4 )
V_258 = F_209 ( & V_328 , & V_329 ,
V_319 , 0 ) ;
else
V_258 = 0 ;
if ( ! F_254 ( V_6 ) && ! F_255 ( V_6 ) ) {
unsigned int V_228 = V_319 -> V_49 . V_228 ;
int V_330 = F_247 ( & V_319 -> V_49 . V_336 ) >> 16 ;
int V_331 = F_248 ( & V_319 -> V_49 . V_336 ) >> 16 ;
if ( V_228 & V_353 ) {
V_328 += V_330 - 1 ;
V_329 += V_331 - 1 ;
} else if ( V_228 & V_355 ) {
V_328 += V_330 - 1 ;
}
}
V_319 -> main. V_258 = V_258 ;
V_319 -> main. V_245 = V_328 ;
V_319 -> main. V_246 = V_329 ;
return 0 ;
}
static void F_258 ( struct V_261 * V_73 ,
const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_73 -> V_49 . V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
enum V_115 V_115 = V_73 -> V_115 ;
T_1 V_264 ;
T_1 V_348 = V_319 -> V_357 ;
T_3 V_13 = F_84 ( V_115 ) ;
int V_245 = V_319 -> main. V_245 ;
int V_246 = V_319 -> main. V_246 ;
unsigned long V_358 ;
V_264 = F_203 ( V_245 , V_246 , V_319 , 0 ) ;
if ( F_53 ( V_6 ) >= 4 )
V_50 -> V_359 = V_319 -> main. V_258 ;
else
V_50 -> V_359 = V_264 ;
V_50 -> V_360 = V_245 ;
V_50 -> V_361 = V_246 ;
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
if ( F_53 ( V_6 ) < 4 ) {
F_260 ( F_261 ( V_115 ) ,
( ( V_45 -> V_364 - 1 ) << 16 ) |
( V_45 -> V_365 - 1 ) ) ;
F_260 ( F_262 ( V_115 ) , 0 ) ;
} else if ( F_12 ( V_6 ) && V_115 == V_366 ) {
F_260 ( F_263 ( V_115 ) ,
( ( V_45 -> V_364 - 1 ) << 16 ) |
( V_45 -> V_365 - 1 ) ) ;
F_260 ( F_264 ( V_115 ) , 0 ) ;
F_260 ( F_265 ( V_115 ) , 0 ) ;
}
F_260 ( V_13 , V_348 ) ;
F_260 ( F_266 ( V_115 ) , V_74 -> V_244 [ 0 ] ) ;
if ( F_254 ( V_6 ) || F_255 ( V_6 ) ) {
F_260 ( F_267 ( V_115 ) ,
F_237 ( V_319 ) +
V_50 -> V_359 ) ;
F_260 ( F_268 ( V_115 ) , ( V_246 << 16 ) | V_245 ) ;
} else if ( F_53 ( V_6 ) >= 4 ) {
F_260 ( F_267 ( V_115 ) ,
F_237 ( V_319 ) +
V_50 -> V_359 ) ;
F_260 ( F_269 ( V_115 ) , ( V_246 << 16 ) | V_245 ) ;
F_260 ( F_270 ( V_115 ) , V_264 ) ;
} else {
F_260 ( F_271 ( V_115 ) ,
F_237 ( V_319 ) +
V_50 -> V_359 ) ;
}
F_272 ( V_13 ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static void F_274 ( struct V_261 * V_73 ,
struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_73 -> V_49 . V_48 ) ;
enum V_115 V_115 = V_73 -> V_115 ;
unsigned long V_358 ;
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
F_260 ( F_84 ( V_115 ) , 0 ) ;
if ( F_181 ( V_6 ) -> V_232 >= 4 )
F_260 ( F_267 ( V_115 ) , 0 ) ;
else
F_260 ( F_271 ( V_115 ) , 0 ) ;
F_272 ( F_84 ( V_115 ) ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static T_1
F_275 ( const struct V_210 * V_74 , int V_115 )
{
if ( V_74 -> V_213 == V_214 )
return 64 ;
else
return F_166 ( V_74 , V_115 ) ;
}
static void F_276 ( struct V_66 * V_66 , int V_262 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_121 ( F_277 ( V_66 -> V_79 , V_262 ) , 0 ) ;
F_121 ( F_278 ( V_66 -> V_79 , V_262 ) , 0 ) ;
F_121 ( F_279 ( V_66 -> V_79 , V_262 ) , 0 ) ;
}
static void F_280 ( struct V_66 * V_66 )
{
struct V_367 * V_368 ;
int V_117 ;
V_368 = & V_66 -> V_75 -> V_368 ;
for ( V_117 = 0 ; V_117 < V_66 -> V_369 ; V_117 ++ ) {
if ( ! V_368 -> V_370 [ V_117 ] . V_371 )
F_276 ( V_66 , V_117 ) ;
}
}
T_1 F_281 ( const struct V_210 * V_74 , int V_115 ,
unsigned int V_228 )
{
T_1 V_276 ;
if ( V_115 >= V_74 -> V_212 -> V_271 )
return 0 ;
V_276 = F_202 ( V_74 , V_115 , V_228 ) ;
if ( F_176 ( V_228 ) )
V_276 /= F_169 ( V_74 , V_115 ) ;
else
V_276 /= F_275 ( V_74 , V_115 ) ;
return V_276 ;
}
static T_1 F_282 ( T_2 V_314 )
{
switch ( V_314 ) {
case V_282 :
return V_372 ;
case V_286 :
return V_297 ;
case V_290 :
return V_298 | V_373 ;
case V_288 :
return V_298 ;
case V_299 :
return V_298 | V_373 |
V_374 ;
case V_300 :
return V_298 |
V_374 ;
case V_292 :
return V_301 ;
case V_294 :
return V_373 | V_301 ;
case V_375 :
return V_376 | V_377 ;
case V_378 :
return V_376 | V_379 ;
case V_380 :
return V_376 | V_381 ;
case V_382 :
return V_376 | V_383 ;
default:
F_168 ( V_314 ) ;
}
return 0 ;
}
static T_1 F_283 ( V_40 V_257 )
{
switch ( V_257 ) {
case V_214 :
break;
case V_215 :
return V_384 ;
case V_216 :
return V_385 ;
case V_217 :
return V_386 ;
default:
F_168 ( V_257 ) ;
}
return 0 ;
}
static T_1 F_284 ( unsigned int V_228 )
{
switch ( V_228 ) {
case V_273 :
break;
case V_387 :
return V_388 ;
case V_353 :
return V_389 ;
case V_280 :
return V_390 ;
default:
F_168 ( V_228 ) ;
}
return 0 ;
}
T_1 F_285 ( const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
const struct V_391 * V_392 = & V_319 -> V_393 ;
T_1 V_394 ;
V_394 = V_122 ;
if ( ! F_286 ( V_6 ) ) {
V_394 |=
V_395 |
V_396 |
V_397 ;
}
V_394 |= F_282 ( V_74 -> V_212 -> V_212 ) ;
V_394 |= F_283 ( V_74 -> V_213 ) ;
V_394 |= F_284 ( V_228 ) ;
if ( V_392 -> V_315 & V_398 )
V_394 |= V_399 ;
else if ( V_392 -> V_315 & V_400 )
V_394 |= V_401 ;
return V_394 ;
}
static void F_287 ( struct V_261 * V_115 ,
const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
enum V_402 V_402 = V_115 -> V_262 ;
enum V_79 V_79 = V_115 -> V_79 ;
T_1 V_394 = V_319 -> V_357 ;
unsigned int V_228 = V_319 -> V_49 . V_228 ;
T_1 V_276 = F_281 ( V_74 , 0 , V_228 ) ;
T_1 V_403 = V_319 -> main. V_258 ;
int V_404 = V_319 -> V_404 ;
int V_328 = V_319 -> main. V_245 ;
int V_329 = V_319 -> main. V_246 ;
int V_330 = F_247 ( & V_319 -> V_49 . V_336 ) >> 16 ;
int V_331 = F_248 ( & V_319 -> V_49 . V_336 ) >> 16 ;
int V_405 = V_319 -> V_49 . V_337 . V_277 ;
int V_406 = V_319 -> V_49 . V_337 . y1 ;
int V_407 = F_247 ( & V_319 -> V_49 . V_337 ) ;
int V_408 = F_248 ( & V_319 -> V_49 . V_337 ) ;
unsigned long V_358 ;
V_330 -- ;
V_331 -- ;
V_407 -- ;
V_408 -- ;
V_50 -> V_359 = V_403 ;
V_50 -> V_360 = V_328 ;
V_50 -> V_361 = V_329 ;
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
if ( F_286 ( V_6 ) ) {
F_260 ( F_288 ( V_79 , V_402 ) ,
V_409 |
V_410 |
V_411 ) ;
}
F_260 ( F_90 ( V_79 , V_402 ) , V_394 ) ;
F_260 ( F_289 ( V_79 , V_402 ) , ( V_329 << 16 ) | V_328 ) ;
F_260 ( F_290 ( V_79 , V_402 ) , V_276 ) ;
F_260 ( F_291 ( V_79 , V_402 ) , ( V_331 << 16 ) | V_330 ) ;
if ( V_404 >= 0 ) {
T_2 V_412 = 0 ;
F_21 ( ! V_407 || ! V_408 ) ;
V_412 = V_413 | F_292 ( V_402 ) |
V_45 -> V_368 . V_370 [ V_404 ] . V_414 ;
F_260 ( F_277 ( V_79 , V_404 ) , V_412 ) ;
F_260 ( F_293 ( V_79 , V_404 ) , 0 ) ;
F_260 ( F_278 ( V_79 , V_404 ) , ( V_405 << 16 ) | V_406 ) ;
F_260 ( F_279 ( V_79 , V_404 ) , ( V_407 << 16 ) | V_408 ) ;
F_260 ( F_294 ( V_79 , V_402 ) , 0 ) ;
} else {
F_260 ( F_294 ( V_79 , V_402 ) , ( V_406 << 16 ) | V_405 ) ;
}
F_260 ( F_295 ( V_79 , V_402 ) ,
F_237 ( V_319 ) + V_403 ) ;
F_272 ( F_295 ( V_79 , V_402 ) ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static void F_296 ( struct V_261 * V_73 ,
struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_73 -> V_49 . V_48 ) ;
enum V_402 V_402 = V_73 -> V_262 ;
enum V_79 V_79 = V_73 -> V_79 ;
unsigned long V_358 ;
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
F_260 ( F_90 ( V_79 , V_402 ) , 0 ) ;
F_260 ( F_295 ( V_79 , V_402 ) , 0 ) ;
F_272 ( F_295 ( V_79 , V_402 ) ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static void F_297 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
F_135 (&dev_priv->drm, crtc)
F_298 ( V_6 , V_50 -> V_79 ) ;
}
static int
F_299 ( struct V_47 * V_48 ,
struct V_415 * V_28 ,
struct V_416 * V_417 )
{
struct V_27 * V_45 ;
struct V_127 * V_50 ;
int V_117 , V_347 ;
F_300 ( V_48 , V_417 ) ;
F_301 ( F_35 ( V_48 ) ) ;
if ( ! V_28 )
return 0 ;
F_302 (state, crtc, crtc_state, i) {
V_45 -> V_418 = true ;
}
if ( ! F_159 ( F_35 ( V_48 ) ) )
F_303 ( V_28 ) -> V_419 = true ;
V_347 = F_304 ( V_28 , V_417 ) ;
F_21 ( V_347 == - V_420 ) ;
return V_347 ;
}
static bool F_305 ( struct V_5 * V_6 )
{
return F_306 ( V_6 ) &&
F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) ;
}
void F_307 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_416 * V_417 = & V_6 -> V_421 ;
struct V_415 * V_28 ;
int V_347 ;
if ( ! V_241 . V_422 &&
! F_305 ( V_6 ) )
return;
F_308 ( V_6 ) ;
F_13 ( L_54 ) ;
F_3 ( & V_48 -> V_423 . V_424 ) ;
F_309 ( V_417 , 0 ) ;
while ( 1 ) {
V_347 = F_310 ( V_48 , V_417 ) ;
if ( V_347 != - V_420 )
break;
F_311 ( V_417 ) ;
}
V_28 = F_312 ( V_48 , V_417 ) ;
if ( F_191 ( V_28 ) ) {
V_347 = F_241 ( V_28 ) ;
F_124 ( L_55 , V_347 ) ;
return;
}
V_347 = F_313 ( V_48 , V_417 ) ;
if ( V_347 ) {
F_124 ( L_56 , V_347 ) ;
F_314 ( V_28 ) ;
return;
}
V_6 -> V_425 = V_28 ;
V_28 -> V_426 = V_417 ;
}
void F_315 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_416 * V_417 = & V_6 -> V_421 ;
struct V_415 * V_28 = V_6 -> V_425 ;
int V_347 ;
if ( ! V_241 . V_422 &&
! F_305 ( V_6 ) )
return;
if ( ! V_28 )
goto V_427;
F_297 ( V_6 ) ;
V_6 -> V_425 = NULL ;
if ( ! F_305 ( V_6 ) ) {
V_347 = F_299 ( V_48 , V_28 , V_417 ) ;
if ( V_347 )
F_124 ( L_57 , V_347 ) ;
} else {
F_316 ( V_6 ) ;
F_317 ( V_6 ) ;
F_318 ( V_6 ) ;
F_319 ( V_48 ) ;
F_320 ( & V_6 -> V_428 ) ;
if ( V_6 -> V_429 . V_430 )
V_6 -> V_429 . V_430 ( V_6 ) ;
F_321 ( & V_6 -> V_428 ) ;
V_347 = F_299 ( V_48 , V_28 , V_417 ) ;
if ( V_347 )
F_124 ( L_57 , V_347 ) ;
F_322 ( V_6 ) ;
}
F_314 ( V_28 ) ;
V_427:
F_323 ( V_417 ) ;
F_324 ( V_417 ) ;
F_5 ( & V_48 -> V_423 . V_424 ) ;
}
static bool F_325 ( struct V_66 * V_50 )
{
struct V_431 * error = & F_35 ( V_50 -> V_49 . V_48 ) -> V_432 ;
if ( F_326 ( error ) )
return true ;
if ( V_50 -> V_433 != F_327 ( error ) )
return true ;
return false ;
}
static bool F_328 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
bool V_434 ;
if ( F_325 ( V_66 ) )
return false ;
F_320 ( & V_48 -> V_435 ) ;
V_434 = F_42 ( V_50 ) -> V_436 != NULL ;
F_321 ( & V_48 -> V_435 ) ;
return V_434 ;
}
static void F_329 ( struct V_66 * V_50 ,
struct V_22 * V_437 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_22 * V_23 =
F_238 ( V_50 -> V_49 . V_28 ) ;
V_50 -> V_49 . V_414 = V_50 -> V_49 . V_28 -> V_414 ;
F_121 ( F_330 ( V_50 -> V_79 ) ,
( ( V_23 -> V_365 - 1 ) << 16 ) |
( V_23 -> V_364 - 1 ) ) ;
if ( F_53 ( V_6 ) >= 9 ) {
F_280 ( V_50 ) ;
if ( V_23 -> V_438 . V_128 )
F_331 ( V_50 ) ;
} else if ( F_70 ( V_6 ) ) {
if ( V_23 -> V_438 . V_128 )
F_332 ( V_50 ) ;
else if ( V_437 -> V_438 . V_128 )
F_333 ( V_50 , true ) ;
}
}
static void F_334 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_439 ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( F_253 ( V_6 ) ) {
V_439 &= ~ V_440 ;
V_439 |= V_440 | V_441 ;
} else {
V_439 &= ~ V_442 ;
V_439 |= V_442 | V_441 ;
}
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( F_103 ( V_6 ) ) {
V_439 &= ~ V_443 ;
V_439 |= V_444 ;
} else {
V_439 &= ~ V_442 ;
V_439 |= V_442 ;
}
F_121 ( V_13 , V_439 | V_445 ) ;
F_122 ( V_13 ) ;
F_123 ( 1000 ) ;
if ( F_253 ( V_6 ) )
F_121 ( V_13 , F_17 ( V_13 ) | V_446 |
V_447 ) ;
}
static void F_335 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_439 , V_448 ;
F_336 ( V_6 , V_79 ) ;
V_13 = F_337 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_449 ;
V_439 &= ~ V_450 ;
F_121 ( V_13 , V_439 ) ;
F_17 ( V_13 ) ;
F_123 ( 150 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_451 ;
V_439 |= F_338 ( V_45 -> V_452 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
F_121 ( V_13 , V_439 | V_92 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
F_121 ( V_13 , V_439 | V_93 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
F_121 ( F_339 ( V_79 ) , V_454 ) ;
F_121 ( F_339 ( V_79 ) , V_454 |
V_455 ) ;
V_13 = F_340 ( V_79 ) ;
for ( V_448 = 0 ; V_448 < 5 ; V_448 ++ ) {
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( ( V_439 & V_450 ) ) {
F_157 ( L_59 ) ;
F_121 ( V_13 , V_439 | V_450 ) ;
break;
}
}
if ( V_448 == 5 )
F_124 ( L_60 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_456 ;
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_456 ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
V_13 = F_340 ( V_79 ) ;
for ( V_448 = 0 ; V_448 < 5 ; V_448 ++ ) {
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( V_439 & V_449 ) {
F_121 ( V_13 , V_439 | V_449 ) ;
F_157 ( L_61 ) ;
break;
}
}
if ( V_448 == 5 )
F_124 ( L_62 ) ;
F_157 ( L_63 ) ;
}
static void F_341 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_439 , V_117 , V_457 ;
V_13 = F_337 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_449 ;
V_439 &= ~ V_450 ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_451 ;
V_439 |= F_338 ( V_45 -> V_452 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
V_439 &= ~ V_458 ;
V_439 |= V_459 ;
F_121 ( V_13 , V_439 | V_92 ) ;
F_121 ( F_342 ( V_79 ) ,
V_460 | V_461 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( F_103 ( V_6 ) ) {
V_439 &= ~ V_443 ;
V_439 |= V_462 ;
} else {
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
}
F_121 ( V_13 , V_439 | V_93 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_458 ;
V_439 |= V_463 [ V_117 ] ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 500 ) ;
for ( V_457 = 0 ; V_457 < 5 ; V_457 ++ ) {
V_13 = F_340 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( V_439 & V_450 ) {
F_121 ( V_13 , V_439 | V_450 ) ;
F_157 ( L_59 ) ;
break;
}
F_123 ( 50 ) ;
}
if ( V_457 < 5 )
break;
}
if ( V_117 == 4 )
F_124 ( L_60 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_456 ;
if ( F_252 ( V_6 ) ) {
V_439 &= ~ V_458 ;
V_439 |= V_459 ;
}
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( F_103 ( V_6 ) ) {
V_439 &= ~ V_443 ;
V_439 |= V_464 ;
} else {
V_439 &= ~ V_442 ;
V_439 |= V_456 ;
}
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_458 ;
V_439 |= V_463 [ V_117 ] ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 500 ) ;
for ( V_457 = 0 ; V_457 < 5 ; V_457 ++ ) {
V_13 = F_340 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( V_439 & V_449 ) {
F_121 ( V_13 , V_439 | V_449 ) ;
F_157 ( L_61 ) ;
break;
}
F_123 ( 50 ) ;
}
if ( V_457 < 5 )
break;
}
if ( V_117 == 4 )
F_124 ( L_62 ) ;
F_157 ( L_64 ) ;
}
static void F_343 ( struct V_66 * V_50 ,
const struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_3 V_13 ;
T_1 V_439 , V_117 , V_465 ;
V_13 = F_337 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_449 ;
V_439 &= ~ V_450 ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 150 ) ;
F_157 ( L_65 ,
F_17 ( F_340 ( V_79 ) ) ) ;
for ( V_465 = 0 ; V_465 < F_174 ( V_463 ) * 2 ; V_465 ++ ) {
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ ( V_466 | V_440 ) ;
V_439 &= ~ V_92 ;
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_466 ;
V_439 &= ~ V_443 ;
V_439 &= ~ V_93 ;
F_121 ( V_13 , V_439 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_451 ;
V_439 |= F_338 ( V_45 -> V_452 ) ;
V_439 |= V_467 ;
V_439 &= ~ V_458 ;
V_439 |= V_463 [ V_465 / 2 ] ;
V_439 |= V_468 ;
F_121 ( V_13 , V_439 | V_92 ) ;
F_121 ( F_342 ( V_79 ) ,
V_460 | V_461 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 |= V_462 ;
V_439 |= V_468 ;
F_121 ( V_13 , V_439 | V_93 ) ;
F_122 ( V_13 ) ;
F_123 ( 1 ) ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
V_13 = F_340 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( V_439 & V_450 ||
( F_17 ( V_13 ) & V_450 ) ) {
F_121 ( V_13 , V_439 | V_450 ) ;
F_157 ( L_66 ,
V_117 ) ;
break;
}
F_123 ( 1 ) ;
}
if ( V_117 == 4 ) {
F_157 ( L_67 , V_465 / 2 ) ;
continue;
}
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_440 ;
V_439 |= V_469 ;
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_443 ;
V_439 |= V_464 ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 2 ) ;
for ( V_117 = 0 ; V_117 < 4 ; V_117 ++ ) {
V_13 = F_340 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_157 ( L_58 , V_439 ) ;
if ( V_439 & V_449 ||
( F_17 ( V_13 ) & V_449 ) ) {
F_121 ( V_13 , V_439 | V_449 ) ;
F_157 ( L_68 ,
V_117 ) ;
goto V_470;
}
F_123 ( 2 ) ;
}
if ( V_117 == 4 )
F_157 ( L_69 , V_465 / 2 ) ;
}
V_470:
F_157 ( L_64 ) ;
}
static void F_344 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_439 ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ ( V_451 | ( 0x7 << 16 ) ) ;
V_439 |= F_338 ( V_66 -> V_75 -> V_452 ) ;
V_439 |= ( F_17 ( F_54 ( V_79 ) ) & V_190 ) << 11 ;
F_121 ( V_13 , V_439 | V_95 ) ;
F_122 ( V_13 ) ;
F_123 ( 200 ) ;
V_439 = F_17 ( V_13 ) ;
F_121 ( V_13 , V_439 | V_471 ) ;
F_122 ( V_13 ) ;
F_123 ( 200 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( ( V_439 & V_94 ) == 0 ) {
F_121 ( V_13 , V_439 | V_94 ) ;
F_122 ( V_13 ) ;
F_123 ( 100 ) ;
}
}
static void F_345 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_439 ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_121 ( V_13 , V_439 & ~ V_471 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_121 ( V_13 , V_439 & ~ V_94 ) ;
F_122 ( V_13 ) ;
F_123 ( 100 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_121 ( V_13 , V_439 & ~ V_95 ) ;
F_122 ( V_13 ) ;
F_123 ( 100 ) ;
}
static void F_346 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_3 V_13 ;
T_1 V_439 ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
F_121 ( V_13 , V_439 & ~ V_92 ) ;
F_122 ( V_13 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ ( 0x7 << 16 ) ;
V_439 |= ( F_17 ( F_54 ( V_79 ) ) & V_190 ) << 11 ;
F_121 ( V_13 , V_439 & ~ V_93 ) ;
F_122 ( V_13 ) ;
F_123 ( 100 ) ;
if ( F_117 ( V_6 ) )
F_121 ( F_339 ( V_79 ) , V_454 ) ;
V_13 = F_64 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
F_121 ( V_13 , V_439 ) ;
V_13 = F_66 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
if ( F_103 ( V_6 ) ) {
V_439 &= ~ V_443 ;
V_439 |= V_462 ;
} else {
V_439 &= ~ V_442 ;
V_439 |= V_453 ;
}
V_439 &= ~ ( 0x07 << 16 ) ;
V_439 |= ( F_17 ( F_54 ( V_79 ) ) & V_190 ) << 11 ;
F_121 ( V_13 , V_439 ) ;
F_122 ( V_13 ) ;
F_123 ( 100 ) ;
}
bool F_347 ( struct V_5 * V_6 )
{
struct V_66 * V_50 ;
F_135 (&dev_priv->drm, crtc) {
if ( F_348 ( & V_50 -> V_472 ) == 0 )
continue;
if ( V_50 -> V_436 )
F_349 ( V_6 , V_50 -> V_79 ) ;
return true ;
}
return false ;
}
static void F_350 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
struct V_1 * V_2 = V_66 -> V_436 ;
V_66 -> V_436 = NULL ;
if ( V_2 -> V_473 )
F_351 ( & V_66 -> V_49 , V_2 -> V_473 ) ;
F_99 ( & V_66 -> V_49 ) ;
F_352 ( & V_6 -> V_474 ) ;
F_353 ( V_66 -> V_115 ,
V_2 -> V_475 ) ;
F_354 ( V_6 -> V_476 , & V_2 -> V_477 ) ;
}
static int F_355 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
long V_347 ;
F_21 ( F_356 ( & V_6 -> V_474 ) ) ;
V_347 = F_357 (
V_6 -> V_474 ,
! F_328 ( V_50 ) ,
60 * V_478 ) ;
if ( V_347 < 0 )
return V_347 ;
if ( V_347 == 0 ) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_1 * V_2 ;
F_320 ( & V_48 -> V_435 ) ;
V_2 = V_66 -> V_436 ;
if ( V_2 && ! F_1 ( V_2 ) ) {
F_358 ( 1 , L_70 ) ;
F_350 ( V_66 ) ;
}
F_321 ( & V_48 -> V_435 ) ;
}
return 0 ;
}
void F_359 ( struct V_5 * V_6 )
{
T_1 V_439 ;
F_121 ( V_479 , V_480 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_439 = F_360 ( V_6 , V_481 , V_482 ) ;
V_439 |= V_483 ;
F_361 ( V_6 , V_481 , V_439 , V_482 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_362 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int clock = V_50 -> V_75 -> V_49 . V_76 . V_77 ;
T_1 V_484 , V_485 , V_486 , V_487 = 0 ;
T_1 V_439 ;
F_359 ( V_6 ) ;
for ( V_486 = 0 ; V_486 < 2 ; V_486 ++ ) {
T_1 V_488 = 172800 * 1000 ;
T_1 V_489 = 64 ;
T_1 V_490 ;
V_490 = F_8 ( V_488 ,
clock << V_486 ) ;
V_484 = ( V_490 / V_489 ) - 2 ;
V_485 = V_490 % V_489 ;
if ( V_484 <= 0x7f )
break;
}
F_21 ( F_363 ( V_484 ) &
~ V_491 ) ;
F_21 ( F_364 ( V_487 ) &
~ V_492 ) ;
F_157 ( L_71 ,
clock ,
V_486 ,
V_484 ,
V_487 ,
V_485 ) ;
F_3 ( & V_6 -> V_9 ) ;
V_439 = F_360 ( V_6 , V_493 , V_482 ) ;
V_439 &= ~ V_491 ;
V_439 |= F_363 ( V_484 ) ;
V_439 &= ~ V_492 ;
V_439 |= F_365 ( V_485 ) ;
V_439 |= F_364 ( V_487 ) ;
V_439 |= V_494 ;
F_361 ( V_6 , V_493 , V_439 , V_482 ) ;
V_439 = F_360 ( V_6 , V_495 , V_482 ) ;
V_439 &= ~ F_366 ( 1 ) ;
V_439 |= F_366 ( V_486 ) ;
F_361 ( V_6 , V_495 , V_439 , V_482 ) ;
V_439 = F_360 ( V_6 , V_481 , V_482 ) ;
V_439 &= ~ V_483 ;
F_361 ( V_6 , V_481 , V_439 , V_482 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_123 ( 24 ) ;
F_121 ( V_479 , V_496 ) ;
}
int F_367 ( struct V_5 * V_6 )
{
T_1 V_484 , V_485 , V_486 ;
T_1 V_488 = 172800 * 1000 ;
T_1 V_489 = 64 ;
T_1 V_490 ;
T_1 V_439 ;
if ( ( F_17 ( V_479 ) & V_496 ) == 0 )
return 0 ;
F_3 ( & V_6 -> V_9 ) ;
V_439 = F_360 ( V_6 , V_481 , V_482 ) ;
if ( V_439 & V_483 ) {
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
V_439 = F_360 ( V_6 , V_493 , V_482 ) ;
V_484 = ( V_439 & V_491 ) >>
V_497 ;
V_485 = ( V_439 & V_492 ) >>
V_498 ;
V_439 = F_360 ( V_6 , V_495 , V_482 ) ;
V_486 = ( V_439 & V_499 ) >>
V_500 ;
F_5 ( & V_6 -> V_9 ) ;
V_490 = ( V_484 + 2 ) * V_489 + V_485 ;
return F_8 ( V_488 ,
V_490 << V_486 ) ;
}
static void F_368 ( struct V_66 * V_50 ,
enum V_79 V_501 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
F_121 ( F_369 ( V_501 ) ,
F_17 ( F_370 ( V_80 ) ) ) ;
F_121 ( F_371 ( V_501 ) ,
F_17 ( F_372 ( V_80 ) ) ) ;
F_121 ( F_373 ( V_501 ) ,
F_17 ( F_374 ( V_80 ) ) ) ;
F_121 ( F_375 ( V_501 ) ,
F_17 ( F_376 ( V_80 ) ) ) ;
F_121 ( F_377 ( V_501 ) ,
F_17 ( F_378 ( V_80 ) ) ) ;
F_121 ( F_379 ( V_501 ) ,
F_17 ( F_380 ( V_80 ) ) ) ;
F_121 ( F_381 ( V_501 ) ,
F_17 ( F_382 ( V_80 ) ) ) ;
}
static void F_383 ( struct V_47 * V_48 , bool V_502 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_2 V_439 ;
V_439 = F_17 ( V_503 ) ;
if ( ! ! ( V_439 & V_504 ) == V_502 )
return;
F_21 ( F_17 ( F_66 ( V_105 ) ) & V_93 ) ;
F_21 ( F_17 ( F_66 ( V_505 ) ) & V_93 ) ;
V_439 &= ~ V_504 ;
if ( V_502 )
V_439 |= V_504 ;
F_157 ( L_72 , V_502 ? L_73 : L_74 ) ;
F_121 ( V_503 , V_439 ) ;
F_122 ( V_503 ) ;
}
static void F_384 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
switch ( V_66 -> V_79 ) {
case V_98 :
break;
case V_105 :
if ( V_66 -> V_75 -> V_452 > 2 )
F_383 ( V_48 , false ) ;
else
F_383 ( V_48 , true ) ;
break;
case V_505 :
F_383 ( V_48 , true ) ;
break;
default:
F_142 () ;
}
}
static enum V_160
F_385 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_506 * V_507 ;
F_386 (dev, &crtc->base, encoder) {
if ( V_507 -> type == V_508 ||
V_507 -> type == V_509 )
return F_387 ( & V_507 -> V_49 ) -> V_160 ;
}
return - 1 ;
}
static void F_388 ( const struct V_22 * V_45 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
T_1 V_439 ;
F_100 ( V_6 , V_79 ) ;
if ( F_253 ( V_6 ) )
F_384 ( V_50 ) ;
F_121 ( F_389 ( V_79 ) ,
F_17 ( F_390 ( V_79 ) ) & V_510 ) ;
V_6 -> V_429 . V_511 ( V_50 , V_45 ) ;
if ( F_103 ( V_6 ) ) {
T_1 V_512 ;
V_439 = F_17 ( V_513 ) ;
V_439 |= F_391 ( V_79 ) ;
V_512 = F_392 ( V_79 ) ;
if ( V_45 -> V_188 ==
F_393 ( V_6 , V_514 ) )
V_439 |= V_512 ;
else
V_439 &= ~ V_512 ;
F_121 ( V_513 , V_439 ) ;
}
F_394 ( V_50 ) ;
F_69 ( V_6 , V_79 ) ;
F_368 ( V_50 , V_79 ) ;
F_334 ( V_50 ) ;
if ( F_103 ( V_6 ) &&
F_395 ( V_45 ) ) {
const struct V_515 * V_76 =
& V_45 -> V_49 . V_76 ;
T_1 V_516 = ( F_17 ( F_54 ( V_79 ) ) & V_190 ) >> 5 ;
T_3 V_13 = F_104 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ ( V_132 |
V_517 |
V_518 ) ;
V_439 |= V_519 ;
V_439 |= V_516 << 9 ;
if ( V_76 -> V_315 & V_520 )
V_439 |= V_521 ;
if ( V_76 -> V_315 & V_522 )
V_439 |= V_523 ;
switch ( F_385 ( V_50 ) ) {
case V_180 :
V_439 |= V_147 ;
break;
case V_182 :
V_439 |= V_149 ;
break;
case V_184 :
V_439 |= V_151 ;
break;
default:
F_142 () ;
}
F_121 ( V_13 , V_439 ) ;
}
F_144 ( V_6 , V_79 ) ;
}
static void F_396 ( const struct V_22 * V_45 )
{
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_78 V_80 = V_45 -> V_80 ;
F_100 ( V_6 , V_201 ) ;
F_362 ( V_50 ) ;
F_368 ( V_50 , V_98 ) ;
F_149 ( V_6 , V_80 ) ;
}
static void F_397 ( struct V_47 * V_48 , int V_79 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_3 V_524 = F_49 ( V_79 ) ;
T_1 V_439 ;
V_439 = F_17 ( V_524 ) ;
F_123 ( 500 ) ;
if ( F_56 ( F_17 ( V_524 ) != V_439 , 5 ) ) {
if ( F_56 ( F_17 ( V_524 ) != V_439 , 5 ) )
F_124 ( L_75 , F_73 ( V_79 ) ) ;
}
}
static int
F_398 ( struct V_22 * V_45 , bool V_525 ,
unsigned int V_526 , int * V_404 ,
int V_330 , int V_331 , int V_407 , int V_408 )
{
struct V_367 * V_368 =
& V_45 -> V_368 ;
struct V_66 * V_66 =
F_42 ( V_45 -> V_49 . V_50 ) ;
int V_527 ;
V_527 = V_330 != V_407 || V_331 != V_408 ;
if ( V_525 || ! V_527 ) {
if ( * V_404 >= 0 ) {
V_368 -> V_528 &= ~ ( 1 << V_526 ) ;
V_368 -> V_370 [ * V_404 ] . V_371 = 0 ;
F_157 ( L_76
L_77 ,
V_66 -> V_79 , V_526 , * V_404 ,
V_368 -> V_528 ) ;
* V_404 = - 1 ;
}
return 0 ;
}
if ( V_330 < V_529 || V_331 < V_530 ||
V_407 < V_531 || V_408 < V_532 ||
V_330 > V_533 || V_331 > V_534 ||
V_407 > V_535 || V_408 > V_536 ) {
F_157 ( L_78
L_79 ,
V_66 -> V_79 , V_526 , V_330 , V_331 , V_407 , V_408 ) ;
return - V_272 ;
}
V_368 -> V_528 |= ( 1 << V_526 ) ;
F_157 ( L_76
L_80 ,
V_66 -> V_79 , V_526 , V_330 , V_331 , V_407 , V_408 ,
V_368 -> V_528 ) ;
return 0 ;
}
int F_399 ( struct V_22 * V_28 )
{
const struct V_515 * V_76 = & V_28 -> V_49 . V_76 ;
return F_398 ( V_28 , ! V_28 -> V_49 . V_72 , V_537 ,
& V_28 -> V_368 . V_404 ,
V_28 -> V_365 , V_28 -> V_364 ,
V_76 -> V_538 , V_76 -> V_539 ) ;
}
static int F_400 ( struct V_22 * V_45 ,
struct V_247 * V_319 )
{
struct V_261 * V_261 =
F_210 ( V_319 -> V_49 . V_115 ) ;
struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
int V_347 ;
bool V_525 = ! V_74 || ! V_319 -> V_49 . V_320 ;
V_347 = F_398 ( V_45 , V_525 ,
F_232 ( & V_261 -> V_49 ) ,
& V_319 -> V_404 ,
F_247 ( & V_319 -> V_49 . V_336 ) >> 16 ,
F_248 ( & V_319 -> V_49 . V_336 ) >> 16 ,
F_247 ( & V_319 -> V_49 . V_337 ) ,
F_248 ( & V_319 -> V_49 . V_337 ) ) ;
if ( V_347 || V_319 -> V_404 < 0 )
return V_347 ;
if ( V_319 -> V_393 . V_315 != V_540 ) {
F_157 ( L_81 ,
V_261 -> V_49 . V_49 . V_262 ,
V_261 -> V_49 . V_12 ) ;
return - V_272 ;
}
switch ( V_74 -> V_212 -> V_212 ) {
case V_286 :
case V_290 :
case V_288 :
case V_299 :
case V_300 :
case V_292 :
case V_294 :
case V_375 :
case V_378 :
case V_380 :
case V_382 :
break;
default:
F_157 ( L_82 ,
V_261 -> V_49 . V_49 . V_262 , V_261 -> V_49 . V_12 ,
V_74 -> V_49 . V_262 , V_74 -> V_212 -> V_212 ) ;
return - V_272 ;
}
return 0 ;
}
static void F_401 ( struct V_66 * V_50 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_50 -> V_369 ; V_117 ++ )
F_276 ( V_50 , V_117 ) ;
}
static void F_331 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
struct V_367 * V_368 =
& V_50 -> V_75 -> V_368 ;
if ( V_50 -> V_75 -> V_438 . V_128 ) {
int V_262 ;
if ( F_21 ( V_50 -> V_75 -> V_368 . V_404 < 0 ) )
return;
V_262 = V_368 -> V_404 ;
F_121 ( F_277 ( V_79 , V_262 ) , V_413 |
V_541 | V_368 -> V_370 [ V_262 ] . V_414 ) ;
F_121 ( F_278 ( V_79 , V_262 ) , V_50 -> V_75 -> V_438 . V_542 ) ;
F_121 ( F_279 ( V_79 , V_262 ) , V_50 -> V_75 -> V_438 . V_224 ) ;
}
}
static void F_332 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
if ( V_50 -> V_75 -> V_438 . V_128 ) {
if ( F_253 ( V_6 ) || F_254 ( V_6 ) )
F_121 ( F_402 ( V_79 ) , V_543 | V_544 |
F_403 ( V_79 ) ) ;
else
F_121 ( F_402 ( V_79 ) , V_543 | V_544 ) ;
F_121 ( F_404 ( V_79 ) , V_50 -> V_75 -> V_438 . V_542 ) ;
F_121 ( F_405 ( V_79 ) , V_50 -> V_75 -> V_438 . V_224 ) ;
}
}
void F_406 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_545 )
return;
F_407 ( V_6 , V_50 -> V_115 ) ;
if ( F_255 ( V_6 ) ) {
F_3 ( & V_6 -> V_546 . V_547 ) ;
F_21 ( F_408 ( V_6 , V_548 , 0xc0000000 ) ) ;
F_5 ( & V_6 -> V_546 . V_547 ) ;
} else {
F_121 ( V_549 , V_550 ) ;
if ( F_55 ( V_6 ,
V_549 , V_550 , V_550 ,
50 ) )
F_124 ( L_83 ) ;
}
}
void F_409 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_545 )
return;
F_407 ( V_6 , V_50 -> V_115 ) ;
if ( F_255 ( V_6 ) ) {
F_3 ( & V_6 -> V_546 . V_547 ) ;
F_21 ( F_408 ( V_6 , V_548 , 0 ) ) ;
F_5 ( & V_6 -> V_546 . V_547 ) ;
if ( F_55 ( V_6 ,
V_549 , V_550 , 0 ,
42 ) )
F_124 ( L_84 ) ;
} else {
F_121 ( V_549 , 0 ) ;
F_122 ( V_549 ) ;
}
F_349 ( V_6 , V_50 -> V_79 ) ;
}
static void F_410 ( struct V_66 * V_66 )
{
if ( V_66 -> V_551 ) {
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
F_3 ( & V_48 -> V_239 ) ;
( void ) F_411 ( V_66 -> V_551 ) ;
F_5 ( & V_48 -> V_239 ) ;
}
}
static void
F_412 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
F_406 ( V_66 ) ;
if ( F_50 ( V_6 ) )
F_413 ( V_6 , V_79 , true ) ;
F_414 ( V_6 ) ;
F_415 ( V_6 ) ;
}
static void
F_416 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_50 ( V_6 ) )
F_413 ( V_6 , V_79 , false ) ;
F_409 ( V_66 ) ;
}
static void
F_239 ( struct V_127 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
F_416 ( V_50 ) ;
if ( F_159 ( V_6 ) &&
F_417 ( V_6 , false ) )
F_349 ( V_6 , V_79 ) ;
}
static void F_418 ( struct V_22 * V_437 )
{
struct V_66 * V_50 = F_42 ( V_437 -> V_49 . V_50 ) ;
struct V_415 * V_552 = V_437 -> V_49 . V_28 ;
struct V_22 * V_23 =
F_238 ( V_50 -> V_49 . V_28 ) ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
struct V_324 * V_553 =
F_419 ( V_552 , V_73 ) ;
F_420 ( F_35 ( V_50 -> V_49 . V_48 ) , V_23 -> V_554 ) ;
if ( V_23 -> V_555 && V_23 -> V_49 . V_72 )
F_421 ( V_50 ) ;
if ( V_553 ) {
struct V_247 * V_556 =
F_234 ( V_73 -> V_28 ) ;
struct V_247 * V_557 =
F_234 ( V_553 ) ;
F_422 ( V_50 ) ;
if ( V_556 -> V_49 . V_320 &&
( F_18 ( & V_23 -> V_49 ) ||
! V_557 -> V_49 . V_320 ) )
F_412 ( & V_50 -> V_49 ) ;
}
}
static void F_423 ( struct V_22 * V_437 ,
struct V_22 * V_23 )
{
struct V_66 * V_50 = F_42 ( V_437 -> V_49 . V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_415 * V_552 = V_437 -> V_49 . V_28 ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
struct V_324 * V_553 =
F_419 ( V_552 , V_73 ) ;
bool V_558 = F_18 ( & V_23 -> V_49 ) ;
struct V_559 * V_560 =
F_303 ( V_552 ) ;
if ( V_553 ) {
struct V_247 * V_556 =
F_234 ( V_73 -> V_28 ) ;
struct V_247 * V_557 =
F_234 ( V_553 ) ;
F_424 ( V_50 , V_23 , V_556 ) ;
if ( V_557 -> V_49 . V_320 &&
( V_558 || ! V_556 -> V_49 . V_320 ) )
F_416 ( & V_50 -> V_49 ) ;
}
if ( F_159 ( V_6 ) && V_437 -> V_49 . V_72 &&
V_23 -> V_561 && F_417 ( V_6 , false ) )
F_349 ( V_6 , V_50 -> V_79 ) ;
if ( V_23 -> V_562 && F_425 ( V_48 ) )
F_349 ( V_6 , V_50 -> V_79 ) ;
if ( F_18 ( & V_23 -> V_49 ) )
return;
if ( V_6 -> V_429 . V_563 != NULL )
V_6 -> V_429 . V_563 ( V_560 ,
V_23 ) ;
else if ( V_23 -> V_564 )
F_421 ( V_50 ) ;
}
static void F_426 ( struct V_127 * V_50 , unsigned V_321 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_318 * V_33 ;
int V_79 = V_66 -> V_79 ;
F_410 ( V_66 ) ;
F_427 (p, dev, plane_mask)
F_210 ( V_33 ) -> V_327 ( F_210 ( V_33 ) , V_66 ) ;
F_420 ( F_35 ( V_48 ) , F_428 ( V_79 ) ) ;
}
static void F_429 ( struct V_127 * V_50 ,
struct V_22 * V_45 ,
struct V_415 * V_552 )
{
struct V_565 * V_566 ;
struct V_567 * V_568 ;
int V_117 ;
F_430 (old_state, conn, conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_566 -> V_569 ) ;
if ( V_566 -> V_50 != V_50 )
continue;
if ( V_507 -> V_570 )
V_507 -> V_570 ( V_507 , V_45 , V_566 ) ;
}
}
static void F_432 ( struct V_127 * V_50 ,
struct V_22 * V_45 ,
struct V_415 * V_552 )
{
struct V_565 * V_566 ;
struct V_567 * V_568 ;
int V_117 ;
F_430 (old_state, conn, conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_566 -> V_569 ) ;
if ( V_566 -> V_50 != V_50 )
continue;
if ( V_507 -> V_571 )
V_507 -> V_571 ( V_507 , V_45 , V_566 ) ;
}
}
static void F_433 ( struct V_127 * V_50 ,
struct V_22 * V_45 ,
struct V_415 * V_552 )
{
struct V_565 * V_566 ;
struct V_567 * V_568 ;
int V_117 ;
F_430 (old_state, conn, conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_566 -> V_569 ) ;
if ( V_566 -> V_50 != V_50 )
continue;
V_507 -> V_502 ( V_507 , V_45 , V_566 ) ;
F_434 ( V_507 , true ) ;
}
}
static void F_435 ( struct V_127 * V_50 ,
struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_565 * V_572 ;
struct V_567 * V_568 ;
int V_117 ;
F_436 (old_state, conn, old_conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_572 -> V_569 ) ;
if ( V_572 -> V_50 != V_50 )
continue;
F_434 ( V_507 , false ) ;
V_507 -> V_573 ( V_507 , V_437 , V_572 ) ;
}
}
static void F_437 ( struct V_127 * V_50 ,
struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_565 * V_572 ;
struct V_567 * V_568 ;
int V_117 ;
F_436 (old_state, conn, old_conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_572 -> V_569 ) ;
if ( V_572 -> V_50 != V_50 )
continue;
if ( V_507 -> V_574 )
V_507 -> V_574 ( V_507 , V_437 , V_572 ) ;
}
}
static void F_438 ( struct V_127 * V_50 ,
struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_565 * V_572 ;
struct V_567 * V_568 ;
int V_117 ;
F_436 (old_state, conn, old_conn_state, i) {
struct V_506 * V_507 =
F_431 ( V_572 -> V_569 ) ;
if ( V_572 -> V_50 != V_50 )
continue;
if ( V_507 -> V_575 )
V_507 -> V_575 ( V_507 , V_437 , V_572 ) ;
}
}
static void F_439 ( struct V_22 * V_23 ,
struct V_415 * V_552 )
{
struct V_127 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
struct V_559 * V_560 =
F_303 ( V_552 ) ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( V_66 -> V_75 -> V_204 || F_16 ( V_6 ) )
F_413 ( V_6 , V_79 , false ) ;
if ( V_66 -> V_75 -> V_204 )
F_440 ( V_6 , V_79 , false ) ;
if ( V_66 -> V_75 -> V_204 )
F_441 ( V_66 ) ;
if ( F_395 ( V_66 -> V_75 ) )
F_442 ( V_66 , V_576 ) ;
F_443 ( V_66 ) ;
F_444 ( V_66 ) ;
if ( V_66 -> V_75 -> V_204 ) {
F_445 ( V_66 ,
& V_66 -> V_75 -> V_577 , NULL ) ;
}
F_446 ( V_50 ) ;
V_66 -> V_72 = true ;
F_432 ( V_50 , V_23 , V_552 ) ;
if ( V_66 -> V_75 -> V_204 ) {
F_344 ( V_66 ) ;
} else {
F_151 ( V_6 , V_79 ) ;
F_152 ( V_6 , V_79 ) ;
}
F_332 ( V_66 ) ;
F_447 ( & V_23 -> V_49 ) ;
if ( V_6 -> V_429 . V_563 != NULL )
V_6 -> V_429 . V_563 ( V_560 , V_66 -> V_75 ) ;
F_156 ( V_66 ) ;
if ( V_66 -> V_75 -> V_204 )
F_388 ( V_23 ) ;
F_96 ( V_50 ) ;
F_448 ( V_50 ) ;
F_433 ( V_50 , V_23 , V_552 ) ;
if ( F_103 ( V_6 ) )
F_397 ( V_48 , V_66 -> V_79 ) ;
if ( V_66 -> V_75 -> V_204 )
F_349 ( V_6 , V_79 ) ;
F_413 ( V_6 , V_79 , true ) ;
F_440 ( V_6 , V_79 , true ) ;
}
static bool F_449 ( struct V_66 * V_50 )
{
return F_450 ( F_35 ( V_50 -> V_49 . V_48 ) ) && V_50 -> V_79 == V_98 ;
}
static void F_451 ( struct V_22 * V_23 ,
struct V_415 * V_552 )
{
struct V_127 * V_50 = V_23 -> V_49 . V_50 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 , V_578 ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
struct V_559 * V_560 =
F_303 ( V_552 ) ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( V_66 -> V_75 -> V_204 )
F_440 ( V_6 , V_201 ,
false ) ;
F_429 ( V_50 , V_23 , V_552 ) ;
if ( V_66 -> V_75 -> V_188 )
F_394 ( V_66 ) ;
if ( F_395 ( V_66 -> V_75 ) )
F_442 ( V_66 , V_576 ) ;
if ( ! F_452 ( V_80 ) )
F_443 ( V_66 ) ;
F_444 ( V_66 ) ;
if ( V_80 != V_579 &&
! F_452 ( V_80 ) ) {
F_121 ( F_453 ( V_80 ) ,
V_66 -> V_75 -> V_580 - 1 ) ;
}
if ( V_66 -> V_75 -> V_204 ) {
F_445 ( V_66 ,
& V_66 -> V_75 -> V_577 , NULL ) ;
}
if ( ! F_452 ( V_80 ) )
F_454 ( V_50 ) ;
F_455 ( V_50 ) ;
F_456 ( & V_23 -> V_49 ) ;
V_66 -> V_72 = true ;
if ( V_66 -> V_75 -> V_204 )
F_413 ( V_6 , V_79 , false ) ;
else
F_413 ( V_6 , V_79 , true ) ;
F_432 ( V_50 , V_23 , V_552 ) ;
if ( V_66 -> V_75 -> V_204 )
V_6 -> V_429 . V_511 ( V_66 , V_23 ) ;
if ( ! F_452 ( V_80 ) )
F_457 ( V_23 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_331 ( V_66 ) ;
else
F_332 ( V_66 ) ;
F_447 ( & V_23 -> V_49 ) ;
F_458 ( V_23 ) ;
if ( ! F_452 ( V_80 ) )
F_459 ( V_23 ) ;
if ( V_6 -> V_429 . V_563 != NULL )
V_6 -> V_429 . V_563 ( V_560 , V_23 ) ;
if ( ! F_452 ( V_80 ) )
F_156 ( V_66 ) ;
if ( V_66 -> V_75 -> V_204 )
F_396 ( V_23 ) ;
if ( F_32 ( V_66 -> V_75 , V_581 ) )
F_460 ( V_23 , true ) ;
F_96 ( V_50 ) ;
F_448 ( V_50 ) ;
F_433 ( V_50 , V_23 , V_552 ) ;
if ( V_66 -> V_75 -> V_204 ) {
F_349 ( V_6 , V_79 ) ;
F_349 ( V_6 , V_79 ) ;
F_413 ( V_6 , V_79 , true ) ;
F_440 ( V_6 , V_201 ,
true ) ;
}
V_578 = V_23 -> V_578 ;
if ( F_254 ( V_6 ) && V_578 != V_582 ) {
F_349 ( V_6 , V_578 ) ;
F_349 ( V_6 , V_578 ) ;
}
}
static void F_333 ( struct V_66 * V_50 , bool V_583 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
if ( V_583 || V_50 -> V_75 -> V_438 . V_128 ) {
F_121 ( F_402 ( V_79 ) , 0 ) ;
F_121 ( F_404 ( V_79 ) , 0 ) ;
F_121 ( F_405 ( V_79 ) , 0 ) ;
}
}
static void F_461 ( struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_127 * V_50 = V_437 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( V_66 -> V_75 -> V_204 ) {
F_413 ( V_6 , V_79 , false ) ;
F_440 ( V_6 , V_79 , false ) ;
}
F_435 ( V_50 , V_437 , V_552 ) ;
F_462 ( V_50 ) ;
F_96 ( V_50 ) ;
F_164 ( V_66 ) ;
F_333 ( V_66 , false ) ;
if ( V_66 -> V_75 -> V_204 )
F_346 ( V_50 ) ;
F_437 ( V_50 , V_437 , V_552 ) ;
if ( V_66 -> V_75 -> V_204 ) {
F_150 ( V_6 , V_79 ) ;
if ( F_103 ( V_6 ) ) {
T_3 V_13 ;
T_1 V_439 ;
V_13 = F_104 ( V_79 ) ;
V_439 = F_17 ( V_13 ) ;
V_439 &= ~ ( V_519 |
V_132 ) ;
V_439 |= V_584 ;
F_121 ( V_13 , V_439 ) ;
V_439 = F_17 ( V_513 ) ;
V_439 &= ~ ( F_391 ( V_79 ) | F_392 ( V_79 ) ) ;
F_121 ( V_513 , V_439 ) ;
}
F_345 ( V_66 ) ;
}
F_413 ( V_6 , V_79 , true ) ;
F_440 ( V_6 , V_79 , true ) ;
}
static void F_463 ( struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_127 * V_50 = V_437 -> V_49 . V_50 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
if ( V_66 -> V_75 -> V_204 )
F_440 ( V_6 , V_201 ,
false ) ;
F_435 ( V_50 , V_437 , V_552 ) ;
F_462 ( V_50 ) ;
F_96 ( V_50 ) ;
if ( ! F_452 ( V_80 ) )
F_164 ( V_66 ) ;
if ( F_32 ( V_66 -> V_75 , V_581 ) )
F_460 ( V_66 -> V_75 , false ) ;
if ( ! F_452 ( V_80 ) )
F_464 ( V_6 , V_80 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_401 ( V_66 ) ;
else
F_333 ( V_66 , false ) ;
if ( ! F_452 ( V_80 ) )
F_465 ( V_66 -> V_75 ) ;
F_437 ( V_50 , V_437 , V_552 ) ;
if ( V_437 -> V_204 )
F_440 ( V_6 , V_201 ,
true ) ;
}
static void F_466 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_22 * V_23 = V_50 -> V_75 ;
if ( ! V_23 -> V_585 . V_586 )
return;
F_21 ( F_17 ( V_587 ) & V_588 ) ;
F_126 ( V_6 , V_50 -> V_79 ) ;
F_121 ( V_589 , V_23 -> V_585 . V_590 ) ;
F_121 ( V_587 , V_23 -> V_585 . V_586 ) ;
F_121 ( F_467 ( V_50 -> V_79 ) , 0 ) ;
}
enum V_112 F_468 ( enum V_160 V_160 )
{
switch ( V_160 ) {
case V_591 :
return V_592 ;
case V_180 :
return V_593 ;
case V_182 :
return V_594 ;
case V_184 :
return V_595 ;
case V_596 :
return V_597 ;
default:
F_168 ( V_160 ) ;
return V_598 ;
}
}
static T_4 F_469 ( struct V_127 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_599 * V_507 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
T_4 V_600 ;
enum V_78 V_78 = V_45 -> V_80 ;
if ( ! V_45 -> V_49 . V_72 )
return 0 ;
V_600 = F_231 ( F_470 ( V_79 ) ) ;
V_600 |= F_231 ( F_80 ( V_78 ) ) ;
if ( V_45 -> V_438 . V_128 ||
V_45 -> V_438 . V_601 )
V_600 |= F_471 ( F_472 ( V_79 ) ) ;
F_473 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_506 * V_506 = F_431 ( V_507 ) ;
V_600 |= F_471 ( V_506 -> V_113 ) ;
}
if ( F_15 ( V_6 ) && V_45 -> V_602 )
V_600 |= F_231 ( V_603 ) ;
if ( V_45 -> V_188 )
V_600 |= F_471 ( V_604 ) ;
return V_600 ;
}
static T_4
F_474 ( struct V_127 * V_50 ,
struct V_22 * V_45 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_112 V_605 ;
T_4 V_606 , V_607 , V_608 ;
V_608 = V_66 -> V_609 ;
V_66 -> V_609 = V_607 =
F_469 ( V_50 , V_45 ) ;
V_606 = V_607 & ~ V_608 ;
F_475 (domain, domains)
F_476 ( V_6 , V_605 ) ;
return V_608 & ~ V_607 ;
}
static void F_477 ( struct V_5 * V_6 ,
T_4 V_606 )
{
enum V_112 V_605 ;
F_475 (domain, domains)
F_82 ( V_6 , V_605 ) ;
}
static void F_478 ( struct V_22 * V_23 ,
struct V_415 * V_552 )
{
struct V_559 * V_560 =
F_303 ( V_552 ) ;
struct V_127 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_21 ( V_66 -> V_72 ) )
return;
if ( F_395 ( V_66 -> V_75 ) )
F_442 ( V_66 , V_576 ) ;
F_443 ( V_66 ) ;
F_444 ( V_66 ) ;
if ( F_12 ( V_6 ) && V_79 == V_105 ) {
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_121 ( F_479 ( V_79 ) , V_610 ) ;
F_121 ( F_480 ( V_79 ) , 0 ) ;
}
F_481 ( V_66 ) ;
V_66 -> V_72 = true ;
F_413 ( V_6 , V_79 , true ) ;
F_429 ( V_50 , V_23 , V_552 ) ;
if ( F_12 ( V_6 ) ) {
F_482 ( V_66 , V_66 -> V_75 ) ;
F_133 ( V_66 , V_66 -> V_75 ) ;
} else {
F_483 ( V_66 , V_66 -> V_75 ) ;
F_125 ( V_66 , V_66 -> V_75 ) ;
}
F_432 ( V_50 , V_23 , V_552 ) ;
F_466 ( V_66 ) ;
F_447 ( & V_23 -> V_49 ) ;
V_6 -> V_429 . V_563 ( V_560 ,
V_23 ) ;
F_156 ( V_66 ) ;
F_96 ( V_50 ) ;
F_448 ( V_50 ) ;
F_433 ( V_50 , V_23 , V_552 ) ;
}
static void F_484 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_121 ( F_485 ( V_50 -> V_79 ) , V_50 -> V_75 -> V_156 . V_611 ) ;
F_121 ( F_486 ( V_50 -> V_79 ) , V_50 -> V_75 -> V_156 . V_612 ) ;
}
static void F_487 ( struct V_22 * V_23 ,
struct V_415 * V_552 )
{
struct V_559 * V_560 =
F_303 ( V_552 ) ;
struct V_127 * V_50 = V_23 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
if ( F_21 ( V_66 -> V_72 ) )
return;
F_484 ( V_66 ) ;
if ( F_395 ( V_66 -> V_75 ) )
F_442 ( V_66 , V_576 ) ;
F_443 ( V_66 ) ;
F_444 ( V_66 ) ;
F_481 ( V_66 ) ;
V_66 -> V_72 = true ;
if ( ! F_50 ( V_6 ) )
F_413 ( V_6 , V_79 , true ) ;
F_432 ( V_50 , V_23 , V_552 ) ;
F_136 ( V_66 ) ;
F_466 ( V_66 ) ;
F_447 ( & V_23 -> V_49 ) ;
if ( V_6 -> V_429 . V_563 != NULL )
V_6 -> V_429 . V_563 ( V_560 ,
V_66 -> V_75 ) ;
else
F_421 ( V_66 ) ;
F_156 ( V_66 ) ;
F_96 ( V_50 ) ;
F_448 ( V_50 ) ;
F_433 ( V_50 , V_23 , V_552 ) ;
}
static void F_488 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( ! V_50 -> V_75 -> V_585 . V_586 )
return;
F_126 ( V_6 , V_50 -> V_79 ) ;
F_13 ( L_85 ,
F_17 ( V_587 ) ) ;
F_121 ( V_587 , 0 ) ;
}
static void F_489 ( struct V_22 * V_437 ,
struct V_415 * V_552 )
{
struct V_127 * V_50 = V_437 -> V_49 . V_50 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
if ( F_50 ( V_6 ) )
F_349 ( V_6 , V_79 ) ;
F_435 ( V_50 , V_437 , V_552 ) ;
F_462 ( V_50 ) ;
F_96 ( V_50 ) ;
F_164 ( V_66 ) ;
F_488 ( V_66 ) ;
F_437 ( V_50 , V_437 , V_552 ) ;
if ( ! F_32 ( V_66 -> V_75 , V_205 ) ) {
if ( F_12 ( V_6 ) )
F_140 ( V_6 , V_79 ) ;
else if ( F_11 ( V_6 ) )
F_139 ( V_6 , V_79 ) ;
else
F_138 ( V_66 ) ;
}
F_438 ( V_50 , V_437 , V_552 ) ;
if ( ! F_50 ( V_6 ) )
F_413 ( V_6 , V_79 , false ) ;
if ( ! V_6 -> V_429 . V_563 )
F_421 ( V_66 ) ;
if ( F_79 ( V_6 ) )
F_490 ( V_6 , V_79 ) ;
}
static void F_491 ( struct V_127 * V_50 ,
struct V_416 * V_417 )
{
struct V_506 * V_507 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
enum V_112 V_605 ;
T_4 V_606 ;
struct V_415 * V_28 ;
struct V_22 * V_45 ;
int V_347 ;
if ( ! V_66 -> V_72 )
return;
if ( V_50 -> V_73 -> V_28 -> V_320 ) {
F_21 ( V_66 -> V_436 ) ;
F_239 ( V_50 ) ;
F_426 ( V_50 , 1 << F_232 ( V_50 -> V_73 ) ) ;
V_50 -> V_73 -> V_28 -> V_320 = false ;
}
V_28 = F_492 ( V_50 -> V_48 ) ;
if ( ! V_28 ) {
F_157 ( L_86 ,
V_50 -> V_49 . V_262 , V_50 -> V_12 ) ;
return;
}
V_28 -> V_426 = V_417 ;
V_45 = F_493 ( V_28 , V_66 ) ;
V_347 = F_494 ( V_28 , V_50 ) ;
F_21 ( F_191 ( V_45 ) || V_347 ) ;
V_6 -> V_429 . V_613 ( V_45 , V_28 ) ;
F_314 ( V_28 ) ;
F_157 ( L_87 ,
V_50 -> V_49 . V_262 , V_50 -> V_12 ) ;
F_21 ( F_495 ( V_50 -> V_28 , NULL ) < 0 ) ;
V_50 -> V_28 -> V_72 = false ;
V_66 -> V_72 = false ;
V_50 -> V_128 = false ;
V_50 -> V_28 -> V_614 = 0 ;
V_50 -> V_28 -> V_615 = 0 ;
F_386 (crtc->dev, crtc, encoder)
V_507 -> V_49 . V_50 = NULL ;
F_496 ( V_66 ) ;
F_421 ( V_66 ) ;
F_497 ( V_66 ) ;
V_606 = V_66 -> V_609 ;
F_475 (domain, domains)
F_82 ( V_6 , V_605 ) ;
V_66 -> V_609 = 0 ;
V_6 -> V_616 &= ~ ( 1 << V_66 -> V_79 ) ;
V_6 -> V_617 [ V_66 -> V_79 ] = 0 ;
}
int F_498 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_415 * V_28 ;
int V_347 ;
V_28 = F_499 ( V_48 ) ;
V_347 = F_500 ( V_28 ) ;
if ( V_347 )
F_124 ( L_56 , V_347 ) ;
else
V_6 -> V_425 = V_28 ;
return V_347 ;
}
void F_501 ( struct V_599 * V_507 )
{
struct V_506 * V_506 = F_431 ( V_507 ) ;
F_502 ( V_507 ) ;
F_235 ( V_506 ) ;
}
static void F_503 ( struct V_27 * V_45 ,
struct V_565 * V_566 )
{
struct V_618 * V_619 = F_504 ( V_566 -> V_619 ) ;
F_157 ( L_88 ,
V_619 -> V_49 . V_49 . V_262 ,
V_619 -> V_49 . V_12 ) ;
if ( V_619 -> V_620 ( V_619 ) ) {
struct V_506 * V_507 = V_619 -> V_507 ;
F_59 ( ! V_45 ,
L_89 ) ;
if ( ! V_45 )
return;
F_59 ( ! V_45 -> V_72 ,
L_90 ) ;
if ( ! V_507 || V_507 -> type == V_581 )
return;
F_59 ( V_566 -> V_569 != & V_507 -> V_49 ,
L_91 ) ;
F_59 ( V_566 -> V_50 != V_507 -> V_49 . V_50 ,
L_92 ) ;
} else {
F_59 ( V_45 && V_45 -> V_72 ,
L_93 ) ;
F_59 ( ! V_45 && V_566 -> V_569 ,
L_94 ) ;
}
}
int F_505 ( struct V_618 * V_619 )
{
struct V_621 * V_566 ;
V_566 = F_506 ( sizeof( * V_566 ) , V_622 ) ;
if ( ! V_566 )
return - V_623 ;
F_507 ( & V_619 -> V_49 ,
& V_566 -> V_49 ) ;
return 0 ;
}
struct V_618 * F_508 ( void )
{
struct V_618 * V_619 ;
V_619 = F_506 ( sizeof *V_619 , V_622 ) ;
if ( ! V_619 )
return NULL ;
if ( F_505 ( V_619 ) < 0 ) {
F_235 ( V_619 ) ;
return NULL ;
}
return V_619 ;
}
bool F_509 ( struct V_618 * V_619 )
{
enum V_79 V_79 = 0 ;
struct V_506 * V_507 = V_619 -> V_507 ;
return V_507 -> V_620 ( V_507 , & V_79 ) ;
}
static int F_510 ( struct V_22 * V_45 )
{
if ( V_45 -> V_49 . V_502 && V_45 -> V_204 )
return V_45 -> V_452 ;
return 0 ;
}
static int F_511 ( struct V_47 * V_48 , enum V_79 V_79 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_415 * V_28 = V_23 -> V_49 . V_28 ;
struct V_66 * V_624 ;
struct V_22 * V_625 ;
F_157 ( L_95 ,
F_73 ( V_79 ) , V_23 -> V_452 ) ;
if ( V_23 -> V_452 > 4 ) {
F_157 ( L_96 ,
F_73 ( V_79 ) , V_23 -> V_452 ) ;
return - V_272 ;
}
if ( F_254 ( V_6 ) || F_255 ( V_6 ) ) {
if ( V_23 -> V_452 > 2 ) {
F_157 ( L_97 ,
V_23 -> V_452 ) ;
return - V_272 ;
} else {
return 0 ;
}
}
if ( F_181 ( V_6 ) -> V_626 == 2 )
return 0 ;
switch ( V_79 ) {
case V_98 :
return 0 ;
case V_105 :
if ( V_23 -> V_452 <= 2 )
return 0 ;
V_624 = F_47 ( V_6 , V_505 ) ;
V_625 =
F_493 ( V_28 , V_624 ) ;
if ( F_191 ( V_625 ) )
return F_241 ( V_625 ) ;
if ( F_510 ( V_625 ) > 0 ) {
F_157 ( L_98 ,
F_73 ( V_79 ) , V_23 -> V_452 ) ;
return - V_272 ;
}
return 0 ;
case V_505 :
if ( V_23 -> V_452 > 2 ) {
F_157 ( L_99 ,
F_73 ( V_79 ) , V_23 -> V_452 ) ;
return - V_272 ;
}
V_624 = F_47 ( V_6 , V_105 ) ;
V_625 =
F_493 ( V_28 , V_624 ) ;
if ( F_191 ( V_625 ) )
return F_241 ( V_625 ) ;
if ( F_510 ( V_625 ) > 2 ) {
F_157 ( L_100 ) ;
return - V_272 ;
}
return 0 ;
default:
F_142 () ;
}
}
static int F_512 ( struct V_66 * V_66 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
const struct V_515 * V_76 = & V_23 -> V_49 . V_76 ;
int V_627 , V_628 , V_629 , V_347 ;
bool V_630 = false ;
V_457:
V_628 = F_14 ( F_35 ( V_48 ) , V_23 ) ;
V_629 = V_76 -> V_77 ;
V_627 = F_513 ( V_629 , V_628 ,
V_23 -> V_631 ) ;
V_23 -> V_452 = V_627 ;
F_514 ( V_23 -> V_631 , V_627 , V_629 ,
V_628 , & V_23 -> V_577 , false ) ;
V_347 = F_511 ( V_48 , V_66 -> V_79 , V_23 ) ;
if ( V_347 == - V_272 && V_23 -> V_631 > 6 * 3 ) {
V_23 -> V_631 -= 2 * 3 ;
F_157 ( L_101 ,
V_23 -> V_631 ) ;
V_630 = true ;
V_23 -> V_632 = true ;
goto V_457;
}
if ( V_630 )
return V_633 ;
return V_347 ;
}
static bool F_515 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_631 > 24 )
return false ;
if ( F_254 ( V_6 ) )
return true ;
return V_23 -> V_634 <=
V_6 -> V_635 * 95 / 100 ;
}
static void F_516 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_23 -> V_545 = V_241 . V_636 &&
F_449 ( V_50 ) &&
F_515 ( V_6 , V_23 ) ;
}
static bool F_517 ( const struct V_66 * V_50 )
{
const struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
return F_181 ( V_6 ) -> V_232 < 4 &&
( V_50 -> V_79 == V_98 || F_518 ( V_6 ) ) ;
}
static T_2 F_519 ( const struct V_22 * V_23 )
{
T_2 V_634 ;
V_634 = V_23 -> V_49 . V_76 . V_77 ;
if ( V_23 -> V_438 . V_128 ) {
V_40 V_637 , V_638 , V_639 , V_640 ;
T_2 V_641 = V_23 -> V_438 . V_224 ;
V_637 = V_23 -> V_365 ;
V_638 = V_23 -> V_364 ;
V_639 = ( V_641 >> 16 ) & 0xFFFF ;
V_640 = V_641 & 0xFFFF ;
if ( V_637 < V_639 )
V_637 = V_639 ;
if ( V_638 < V_640 )
V_638 = V_640 ;
if ( F_21 ( ! V_639 || ! V_640 ) )
return V_634 ;
V_634 = F_40 ( ( V_40 ) V_634 * V_637 * V_638 ,
V_639 * V_640 ) ;
}
return V_634 ;
}
static void F_520 ( struct V_22 * V_45 )
{
struct V_5 * V_6 = F_35 ( V_45 -> V_49 . V_50 -> V_48 ) ;
if ( F_159 ( V_6 ) )
V_45 -> V_634 =
V_45 -> V_49 . V_76 . V_77 ;
else
V_45 -> V_634 =
F_519 ( V_45 ) ;
}
static int F_521 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_515 * V_76 = & V_23 -> V_49 . V_76 ;
int V_642 = V_6 -> V_643 ;
if ( F_53 ( V_6 ) < 4 ) {
V_642 = V_6 -> V_635 * 9 / 10 ;
if ( F_517 ( V_50 ) &&
V_76 -> V_77 > V_642 ) {
V_642 = V_6 -> V_643 ;
V_23 -> V_208 = true ;
}
}
if ( V_76 -> V_77 > V_642 ) {
F_157 ( L_102 ,
V_76 -> V_77 , V_642 ,
F_522 ( V_23 -> V_208 ) ) ;
return - V_272 ;
}
if ( ( F_32 ( V_23 , V_51 ) &&
F_33 ( V_48 ) ) || V_23 -> V_208 )
V_23 -> V_365 &= ~ 1 ;
if ( ( F_53 ( V_6 ) > 4 || F_94 ( V_6 ) ) &&
V_76 -> V_644 == V_76 -> V_538 )
return - V_272 ;
F_520 ( V_23 ) ;
if ( F_450 ( V_6 ) )
F_516 ( V_50 , V_23 ) ;
if ( V_23 -> V_204 )
return F_512 ( V_50 , V_23 ) ;
return 0 ;
}
static void
F_523 ( T_2 * V_645 , T_2 * V_646 )
{
while ( * V_645 > V_647 ||
* V_646 > V_647 ) {
* V_645 >>= 1 ;
* V_646 >>= 1 ;
}
}
static void F_524 ( unsigned int V_31 , unsigned int V_36 ,
T_2 * V_648 , T_2 * V_649 ,
bool V_650 )
{
if ( V_650 ) {
while ( ( V_31 & 1 ) == 0 && ( V_36 & 1 ) == 0 ) {
V_31 >>= 1 ;
V_36 >>= 1 ;
}
}
* V_649 = F_525 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_648 = F_40 ( ( V_40 ) V_31 * * V_649 , V_36 ) ;
F_523 ( V_648 , V_649 ) ;
}
void
F_514 ( int V_651 , int V_652 ,
int V_653 , int V_654 ,
struct V_655 * V_656 ,
bool V_650 )
{
V_656 -> V_657 = 64 ;
F_524 ( V_651 * V_653 ,
V_654 * V_652 * 8 ,
& V_656 -> V_658 , & V_656 -> V_659 ,
V_650 ) ;
F_524 ( V_653 , V_654 ,
& V_656 -> V_660 , & V_656 -> V_661 ,
V_650 ) ;
}
static inline bool F_526 ( struct V_5 * V_6 )
{
if ( V_241 . V_662 >= 0 )
return V_241 . V_662 != 0 ;
return V_6 -> V_663 . V_664
&& ! ( V_6 -> V_665 & V_666 ) ;
}
static T_2 F_527 ( struct V_30 * V_30 )
{
return ( 1 << V_30 -> V_36 ) << 16 | V_30 -> V_32 ;
}
static T_2 F_528 ( struct V_30 * V_30 )
{
return V_30 -> V_36 << 16 | V_30 -> V_39 << 8 | V_30 -> V_32 ;
}
static void F_529 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_667 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_668 , V_669 = 0 ;
if ( F_29 ( V_6 ) ) {
V_668 = F_527 ( & V_45 -> V_30 ) ;
if ( V_667 )
V_669 = F_527 ( V_667 ) ;
} else {
V_668 = F_528 ( & V_45 -> V_30 ) ;
if ( V_667 )
V_669 = F_528 ( V_667 ) ;
}
V_45 -> V_156 . V_611 = V_668 ;
V_50 -> V_670 = false ;
if ( F_32 ( V_45 , V_51 ) &&
V_667 ) {
V_45 -> V_156 . V_612 = V_669 ;
V_50 -> V_670 = true ;
} else {
V_45 -> V_156 . V_612 = V_668 ;
}
}
static void F_530 ( struct V_5 * V_6 , enum V_79
V_79 )
{
T_1 V_671 ;
V_671 = F_130 ( V_6 , V_79 , F_531 ( 1 ) ) ;
V_671 &= 0xffffff00 ;
V_671 |= 0x00000030 ;
F_132 ( V_6 , V_79 , F_531 ( 1 ) , V_671 ) ;
V_671 = F_130 ( V_6 , V_79 , V_672 ) ;
V_671 &= 0x00ffffff ;
V_671 |= 0x8c000000 ;
F_132 ( V_6 , V_79 , V_672 , V_671 ) ;
V_671 = F_130 ( V_6 , V_79 , F_531 ( 1 ) ) ;
V_671 &= 0xffffff00 ;
F_132 ( V_6 , V_79 , F_531 ( 1 ) , V_671 ) ;
V_671 = F_130 ( V_6 , V_79 , V_672 ) ;
V_671 &= 0x00ffffff ;
V_671 |= 0xb0000000 ;
F_132 ( V_6 , V_79 , V_672 , V_671 ) ;
}
static void F_532 ( struct V_66 * V_50 ,
struct V_655 * V_656 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_50 -> V_79 ;
F_121 ( F_533 ( V_79 ) , F_534 ( V_656 -> V_657 ) | V_656 -> V_658 ) ;
F_121 ( F_535 ( V_79 ) , V_656 -> V_659 ) ;
F_121 ( F_536 ( V_79 ) , V_656 -> V_660 ) ;
F_121 ( F_537 ( V_79 ) , V_656 -> V_661 ) ;
}
static void F_445 ( struct V_66 * V_50 ,
struct V_655 * V_656 ,
struct V_655 * V_673 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int V_79 = V_50 -> V_79 ;
enum V_78 V_78 = V_50 -> V_75 -> V_80 ;
if ( F_53 ( V_6 ) >= 5 ) {
F_121 ( F_390 ( V_78 ) , F_534 ( V_656 -> V_657 ) | V_656 -> V_658 ) ;
F_121 ( F_538 ( V_78 ) , V_656 -> V_659 ) ;
F_121 ( F_539 ( V_78 ) , V_656 -> V_660 ) ;
F_121 ( F_540 ( V_78 ) , V_656 -> V_661 ) ;
if ( V_673 && ( F_12 ( V_6 ) ||
F_53 ( V_6 ) < 8 ) && V_50 -> V_75 -> V_674 ) {
F_121 ( F_541 ( V_78 ) ,
F_534 ( V_673 -> V_657 ) | V_673 -> V_658 ) ;
F_121 ( F_542 ( V_78 ) , V_673 -> V_659 ) ;
F_121 ( F_543 ( V_78 ) , V_673 -> V_660 ) ;
F_121 ( F_544 ( V_78 ) , V_673 -> V_661 ) ;
}
} else {
F_121 ( F_545 ( V_79 ) , F_534 ( V_656 -> V_657 ) | V_656 -> V_658 ) ;
F_121 ( F_546 ( V_79 ) , V_656 -> V_659 ) ;
F_121 ( F_547 ( V_79 ) , V_656 -> V_660 ) ;
F_121 ( F_548 ( V_79 ) , V_656 -> V_661 ) ;
}
}
void F_442 ( struct V_66 * V_50 , enum V_675 V_656 )
{
struct V_655 * V_676 , * V_677 = NULL ;
if ( V_656 == V_576 ) {
V_676 = & V_50 -> V_75 -> V_676 ;
V_677 = & V_50 -> V_75 -> V_677 ;
} else if ( V_656 == V_678 ) {
V_676 = & V_50 -> V_75 -> V_677 ;
} else {
F_124 ( L_103 ) ;
return;
}
if ( V_50 -> V_75 -> V_204 )
F_532 ( V_50 , & V_50 -> V_75 -> V_676 ) ;
else
F_445 ( V_50 , V_676 , V_677 ) ;
}
static void F_549 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
V_23 -> V_156 . V_30 = V_171 |
V_172 | V_167 ;
if ( V_50 -> V_79 != V_98 )
V_23 -> V_156 . V_30 |= V_173 ;
if ( ! F_32 ( V_23 , V_205 ) )
V_23 -> V_156 . V_30 |= V_88 |
V_679 ;
V_23 -> V_156 . V_158 =
( V_23 -> V_580 - 1 ) << V_680 ;
}
static void F_550 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
V_23 -> V_156 . V_30 = V_174 |
V_172 | V_167 ;
if ( V_50 -> V_79 != V_98 )
V_23 -> V_156 . V_30 |= V_173 ;
if ( ! F_32 ( V_23 , V_205 ) )
V_23 -> V_156 . V_30 |= V_88 ;
V_23 -> V_156 . V_158 =
( V_23 -> V_580 - 1 ) << V_680 ;
}
static void F_483 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
T_1 V_681 ;
T_1 V_682 , V_683 , V_684 , V_685 , V_686 ;
T_1 V_687 , V_671 ;
F_121 ( F_58 ( V_79 ) ,
V_23 -> V_156 . V_30 &
~ ( V_88 | V_679 ) ) ;
if ( ( V_23 -> V_156 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_682 = V_23 -> V_30 . V_36 ;
V_683 = V_23 -> V_30 . V_39 ;
V_684 = V_23 -> V_30 . V_32 ;
V_685 = V_23 -> V_30 . V_34 ;
V_686 = V_23 -> V_30 . V_35 ;
if ( V_79 == V_105 )
F_530 ( V_6 , V_79 ) ;
F_132 ( V_6 , V_79 , V_688 , 0x0100000f ) ;
V_671 = F_130 ( V_6 , V_79 , F_551 ( V_79 ) ) ;
V_671 &= 0x00ffffff ;
F_132 ( V_6 , V_79 , F_551 ( V_79 ) , V_671 ) ;
F_132 ( V_6 , V_79 , V_689 , 0x610 ) ;
V_681 = ( ( V_683 << V_690 ) | ( V_684 & V_691 ) ) ;
V_681 |= ( ( V_685 << V_692 ) | ( V_686 << V_693 ) ) ;
V_681 |= ( ( V_682 << V_694 ) ) ;
V_681 |= ( 1 << V_695 ) ;
V_681 |= ( V_696 << V_697 ) ;
F_132 ( V_6 , V_79 , F_552 ( V_79 ) , V_681 ) ;
V_681 |= V_698 ;
F_132 ( V_6 , V_79 , F_552 ( V_79 ) , V_681 ) ;
if ( V_23 -> V_24 == 162000 ||
F_32 ( V_50 -> V_75 , V_699 ) ||
F_32 ( V_50 -> V_75 , V_191 ) )
F_132 ( V_6 , V_79 , F_553 ( V_79 ) ,
0x009f0003 ) ;
else
F_132 ( V_6 , V_79 , F_553 ( V_79 ) ,
0x00d0000f ) ;
if ( F_395 ( V_23 ) ) {
if ( V_79 == V_98 )
F_132 ( V_6 , V_79 , F_554 ( V_79 ) ,
0x0df40000 ) ;
else
F_132 ( V_6 , V_79 , F_554 ( V_79 ) ,
0x0df70000 ) ;
} else {
if ( V_79 == V_98 )
F_132 ( V_6 , V_79 , F_554 ( V_79 ) ,
0x0df70000 ) ;
else
F_132 ( V_6 , V_79 , F_554 ( V_79 ) ,
0x0df40000 ) ;
}
V_687 = F_130 ( V_6 , V_79 , F_555 ( V_79 ) ) ;
V_687 = ( V_687 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_395 ( V_50 -> V_75 ) )
V_687 |= 0x01000000 ;
F_132 ( V_6 , V_79 , F_555 ( V_79 ) , V_687 ) ;
F_132 ( V_6 , V_79 , F_556 ( V_79 ) , 0x87871000 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_482 ( struct V_66 * V_50 ,
const struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
enum V_159 V_160 = F_129 ( V_79 ) ;
T_1 V_700 , V_701 ;
T_1 V_682 , V_683 , V_684 , V_685 , V_686 , V_702 ;
T_1 V_703 ;
int V_37 ;
F_121 ( F_58 ( V_79 ) ,
V_23 -> V_156 . V_30 & ~ V_88 ) ;
if ( ( V_23 -> V_156 . V_30 & V_88 ) == 0 )
return;
V_682 = V_23 -> V_30 . V_36 ;
V_702 = V_23 -> V_30 . V_32 & 0x3fffff ;
V_683 = V_23 -> V_30 . V_39 ;
V_684 = V_23 -> V_30 . V_32 >> 22 ;
V_685 = V_23 -> V_30 . V_34 ;
V_686 = V_23 -> V_30 . V_35 ;
V_37 = V_23 -> V_30 . V_37 ;
V_703 = 0 ;
V_700 = 0 ;
F_3 ( & V_6 -> V_9 ) ;
F_132 ( V_6 , V_79 , F_557 ( V_160 ) ,
5 << V_704 |
V_685 << V_705 |
V_686 << V_706 |
1 << V_707 ) ;
F_132 ( V_6 , V_79 , F_558 ( V_160 ) , V_684 ) ;
F_132 ( V_6 , V_79 , F_559 ( V_160 ) ,
V_708 |
1 << V_709 ) ;
F_132 ( V_6 , V_79 , F_560 ( V_160 ) , V_702 ) ;
V_703 = F_130 ( V_6 , V_79 , F_561 ( V_160 ) ) ;
V_703 &= ~ ( V_710 | V_711 ) ;
V_703 |= ( 2 << V_712 ) ;
if ( V_702 )
V_703 |= V_711 ;
F_132 ( V_6 , V_79 , F_561 ( V_160 ) , V_703 ) ;
V_703 = F_130 ( V_6 , V_79 , F_562 ( V_160 ) ) ;
V_703 &= ~ ( V_713 |
V_714 ) ;
V_703 |= ( 0x5 << V_715 ) ;
if ( ! V_702 )
V_703 |= V_714 ;
F_132 ( V_6 , V_79 , F_562 ( V_160 ) , V_703 ) ;
if ( V_37 == 5400000 ) {
V_700 |= ( 0x3 << V_716 ) ;
V_700 |= ( 0x8 << V_717 ) ;
V_700 |= ( 0x1 << V_718 ) ;
V_701 = 0x9 ;
} else if ( V_37 <= 6200000 ) {
V_700 |= ( 0x5 << V_716 ) ;
V_700 |= ( 0xB << V_717 ) ;
V_700 |= ( 0x3 << V_718 ) ;
V_701 = 0x9 ;
} else if ( V_37 <= 6480000 ) {
V_700 |= ( 0x4 << V_716 ) ;
V_700 |= ( 0x9 << V_717 ) ;
V_700 |= ( 0x3 << V_718 ) ;
V_701 = 0x8 ;
} else {
V_700 |= ( 0x4 << V_716 ) ;
V_700 |= ( 0x9 << V_717 ) ;
V_700 |= ( 0x3 << V_718 ) ;
V_701 = 0 ;
}
F_132 ( V_6 , V_79 , F_563 ( V_160 ) , V_700 ) ;
V_703 = F_130 ( V_6 , V_79 , F_564 ( V_160 ) ) ;
V_703 &= ~ V_719 ;
V_703 |= ( V_701 << V_720 ) ;
F_132 ( V_6 , V_79 , F_564 ( V_160 ) , V_703 ) ;
F_132 ( V_6 , V_79 , F_131 ( V_160 ) ,
F_130 ( V_6 , V_79 , F_131 ( V_160 ) ) |
V_721 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
int F_565 ( struct V_5 * V_6 , enum V_79 V_79 ,
const struct V_30 * V_30 )
{
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_22 * V_23 ;
V_23 = F_506 ( sizeof( * V_23 ) , V_622 ) ;
if ( ! V_23 )
return - V_623 ;
V_23 -> V_49 . V_50 = & V_50 -> V_49 ;
V_23 -> V_580 = 1 ;
V_23 -> V_30 = * V_30 ;
if ( F_12 ( V_6 ) ) {
F_550 ( V_50 , V_23 ) ;
F_482 ( V_50 , V_23 ) ;
F_133 ( V_50 , V_23 ) ;
} else {
F_549 ( V_50 , V_23 ) ;
F_483 ( V_50 , V_23 ) ;
F_125 ( V_50 , V_23 ) ;
}
F_235 ( V_23 ) ;
return 0 ;
}
void F_566 ( struct V_5 * V_6 , enum V_79 V_79 )
{
if ( F_12 ( V_6 ) )
F_140 ( V_6 , V_79 ) ;
else
F_139 ( V_6 , V_79 ) ;
}
static void F_567 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_667 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_30 ;
struct V_30 * clock = & V_45 -> V_30 ;
F_529 ( V_50 , V_45 , V_667 ) ;
V_30 = V_167 ;
if ( F_32 ( V_45 , V_51 ) )
V_30 |= V_722 ;
else
V_30 |= V_723 ;
if ( F_568 ( V_6 ) || F_569 ( V_6 ) ||
F_570 ( V_6 ) || F_29 ( V_6 ) ) {
V_30 |= ( V_45 -> V_580 - 1 )
<< V_724 ;
}
if ( F_32 ( V_45 , V_196 ) ||
F_32 ( V_45 , V_191 ) )
V_30 |= V_725 ;
if ( F_395 ( V_45 ) )
V_30 |= V_725 ;
if ( F_29 ( V_6 ) )
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_726 ;
else {
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_727 ;
if ( F_94 ( V_6 ) && V_667 )
V_30 |= ( 1 << ( V_667 -> V_34 - 1 ) ) << V_728 ;
}
switch ( clock -> V_35 ) {
case 5 :
V_30 |= V_729 ;
break;
case 7 :
V_30 |= V_730 ;
break;
case 10 :
V_30 |= V_731 ;
break;
case 14 :
V_30 |= V_732 ;
break;
}
if ( F_53 ( V_6 ) >= 4 )
V_30 |= ( 6 << V_733 ) ;
if ( V_45 -> V_734 )
V_30 |= V_735 ;
else if ( F_32 ( V_45 , V_51 ) &&
F_526 ( V_6 ) )
V_30 |= V_736 ;
else
V_30 |= V_737 ;
V_30 |= V_88 ;
V_45 -> V_156 . V_30 = V_30 ;
if ( F_53 ( V_6 ) >= 4 ) {
T_1 V_158 = ( V_45 -> V_580 - 1 )
<< V_680 ;
V_45 -> V_156 . V_158 = V_158 ;
}
}
static void F_571 ( struct V_66 * V_50 ,
struct V_22 * V_45 ,
struct V_30 * V_667 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 ;
struct V_30 * clock = & V_45 -> V_30 ;
F_529 ( V_50 , V_45 , V_667 ) ;
V_30 = V_167 ;
if ( F_32 ( V_45 , V_51 ) ) {
V_30 |= ( 1 << ( clock -> V_34 - 1 ) ) << V_727 ;
} else {
if ( clock -> V_34 == 2 )
V_30 |= V_738 ;
else
V_30 |= ( clock -> V_34 - 2 ) << V_727 ;
if ( clock -> V_35 == 4 )
V_30 |= V_739 ;
}
if ( ! F_79 ( V_6 ) &&
F_32 ( V_45 , V_169 ) )
V_30 |= V_170 ;
if ( F_32 ( V_45 , V_51 ) &&
F_526 ( V_6 ) )
V_30 |= V_736 ;
else
V_30 |= V_737 ;
V_30 |= V_88 ;
V_45 -> V_156 . V_30 = V_30 ;
}
static void F_443 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
const struct V_515 * V_76 = & V_66 -> V_75 -> V_49 . V_76 ;
T_2 V_740 , V_741 ;
int V_742 = 0 ;
V_740 = V_76 -> V_740 ;
V_741 = V_76 -> V_741 ;
if ( V_76 -> V_315 & V_743 ) {
V_740 -= 1 ;
V_741 -= 1 ;
if ( F_32 ( V_66 -> V_75 , V_196 ) )
V_742 = ( V_76 -> V_744 - 1 ) / 2 ;
else
V_742 = V_76 -> V_644 -
V_76 -> V_744 / 2 ;
if ( V_742 < 0 )
V_742 += V_76 -> V_744 ;
}
if ( F_53 ( V_6 ) > 3 )
F_121 ( F_382 ( V_80 ) , V_742 ) ;
F_121 ( F_370 ( V_80 ) ,
( V_76 -> V_538 - 1 ) |
( ( V_76 -> V_744 - 1 ) << 16 ) ) ;
F_121 ( F_372 ( V_80 ) ,
( V_76 -> V_745 - 1 ) |
( ( V_76 -> V_746 - 1 ) << 16 ) ) ;
F_121 ( F_374 ( V_80 ) ,
( V_76 -> V_644 - 1 ) |
( ( V_76 -> V_747 - 1 ) << 16 ) ) ;
F_121 ( F_376 ( V_80 ) ,
( V_76 -> V_539 - 1 ) |
( ( V_740 - 1 ) << 16 ) ) ;
F_121 ( F_378 ( V_80 ) ,
( V_76 -> V_748 - 1 ) |
( ( V_741 - 1 ) << 16 ) ) ;
F_121 ( F_380 ( V_80 ) ,
( V_76 -> V_749 - 1 ) |
( ( V_76 -> V_750 - 1 ) << 16 ) ) ;
if ( F_254 ( V_6 ) && V_80 == V_579 &&
( V_79 == V_105 || V_79 == V_505 ) )
F_121 ( F_376 ( V_79 ) , F_17 ( F_376 ( V_80 ) ) ) ;
}
static void F_444 ( struct V_66 * V_66 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_66 -> V_79 ;
F_121 ( F_330 ( V_79 ) ,
( ( V_66 -> V_75 -> V_365 - 1 ) << 16 ) |
( V_66 -> V_75 -> V_364 - 1 ) ) ;
}
static void F_572 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_23 -> V_80 ;
T_2 V_161 ;
V_161 = F_17 ( F_370 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_538 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_744 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_161 = F_17 ( F_372 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_745 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_746 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_161 = F_17 ( F_374 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_644 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_747 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_161 = F_17 ( F_376 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_539 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_740 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_161 = F_17 ( F_378 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_748 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_741 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_161 = F_17 ( F_380 ( V_80 ) ) ;
V_23 -> V_49 . V_76 . V_749 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_49 . V_76 . V_750 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
if ( F_17 ( F_54 ( V_80 ) ) & V_194 ) {
V_23 -> V_49 . V_76 . V_315 |= V_743 ;
V_23 -> V_49 . V_76 . V_740 += 1 ;
V_23 -> V_49 . V_76 . V_741 += 1 ;
}
}
static void F_573 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_161 ;
V_161 = F_17 ( F_330 ( V_50 -> V_79 ) ) ;
V_23 -> V_364 = ( V_161 & 0xffff ) + 1 ;
V_23 -> V_365 = ( ( V_161 >> 16 ) & 0xffff ) + 1 ;
V_23 -> V_49 . V_414 . V_751 = V_23 -> V_364 ;
V_23 -> V_49 . V_414 . V_752 = V_23 -> V_365 ;
}
void F_574 ( struct V_515 * V_414 ,
struct V_22 * V_23 )
{
V_414 -> V_752 = V_23 -> V_49 . V_76 . V_538 ;
V_414 -> V_753 = V_23 -> V_49 . V_76 . V_744 ;
V_414 -> V_754 = V_23 -> V_49 . V_76 . V_644 ;
V_414 -> V_755 = V_23 -> V_49 . V_76 . V_747 ;
V_414 -> V_751 = V_23 -> V_49 . V_76 . V_539 ;
V_414 -> V_756 = V_23 -> V_49 . V_76 . V_740 ;
V_414 -> V_757 = V_23 -> V_49 . V_76 . V_749 ;
V_414 -> V_758 = V_23 -> V_49 . V_76 . V_750 ;
V_414 -> V_315 = V_23 -> V_49 . V_76 . V_315 ;
V_414 -> type = V_759 ;
V_414 -> clock = V_23 -> V_49 . V_76 . V_77 ;
V_414 -> V_760 = F_575 ( V_414 ) ;
V_414 -> V_761 = F_576 ( V_414 ) ;
F_577 ( V_414 ) ;
}
static void F_481 ( struct V_66 * V_66 )
{
struct V_5 * V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
T_2 V_762 ;
V_762 = 0 ;
if ( F_79 ( V_6 ) )
V_762 |= F_17 ( F_54 ( V_66 -> V_79 ) ) & V_114 ;
if ( V_66 -> V_75 -> V_208 )
V_762 |= V_209 ;
if ( F_94 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) {
if ( V_66 -> V_75 -> V_763 && V_66 -> V_75 -> V_631 != 30 )
V_762 |= V_764 |
V_765 ;
switch ( V_66 -> V_75 -> V_631 ) {
case 18 :
V_762 |= V_766 ;
break;
case 24 :
V_762 |= V_192 ;
break;
case 30 :
V_762 |= V_767 ;
break;
default:
F_142 () ;
}
}
if ( F_578 ( V_6 ) ) {
if ( V_66 -> V_670 ) {
F_157 ( L_104 ) ;
V_762 |= V_768 ;
} else {
F_157 ( L_105 ) ;
}
}
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_743 ) {
if ( F_53 ( V_6 ) < 4 ||
F_32 ( V_66 -> V_75 , V_196 ) )
V_762 |= V_769 ;
else
V_762 |= V_770 ;
} else
V_762 |= V_771 ;
if ( ( F_11 ( V_6 ) || F_12 ( V_6 ) ) &&
V_66 -> V_75 -> V_772 )
V_762 |= V_773 ;
F_121 ( F_54 ( V_66 -> V_79 ) , V_762 ) ;
F_122 ( F_54 ( V_66 -> V_79 ) ) ;
}
static int F_579 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 48000 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_526 ( V_6 ) ) {
V_29 = V_6 -> V_663 . V_774 ;
F_157 ( L_106 , V_29 ) ;
}
V_42 = & V_775 ;
} else if ( F_32 ( V_45 , V_169 ) ) {
V_42 = & V_776 ;
} else {
V_42 = & V_777 ;
}
if ( ! V_45 -> V_778 &&
! F_34 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_571 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_580 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_526 ( V_6 ) ) {
V_29 = V_6 -> V_663 . V_774 ;
F_157 ( L_106 , V_29 ) ;
}
if ( F_33 ( V_48 ) )
V_42 = & V_779 ;
else
V_42 = & V_780 ;
} else if ( F_32 ( V_45 , V_191 ) ||
F_32 ( V_45 , V_699 ) ) {
V_42 = & V_781 ;
} else if ( F_32 ( V_45 , V_196 ) ) {
V_42 = & V_782 ;
} else {
V_42 = & V_783 ;
}
if ( ! V_45 -> V_778 &&
! F_37 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_567 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_581 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_526 ( V_6 ) ) {
V_29 = V_6 -> V_663 . V_774 ;
F_157 ( L_106 , V_29 ) ;
}
V_42 = & V_784 ;
} else {
V_42 = & V_785 ;
}
if ( ! V_45 -> V_778 &&
! F_36 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_567 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_582 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 96000 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_526 ( V_6 ) ) {
V_29 = V_6 -> V_663 . V_774 ;
F_157 ( L_106 , V_29 ) ;
}
V_42 = & V_786 ;
} else {
V_42 = & V_783 ;
}
if ( ! V_45 -> V_778 &&
! F_34 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_567 ( V_50 , V_45 , NULL ) ;
return 0 ;
}
static int F_583 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
int V_29 = 100000 ;
const struct V_41 * V_42 = & V_787 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( ! V_45 -> V_778 &&
! F_43 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_550 ( V_50 , V_45 ) ;
return 0 ;
}
static int F_584 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
int V_29 = 100000 ;
const struct V_41 * V_42 = & V_788 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
if ( ! V_45 -> V_778 &&
! F_41 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_549 ( V_50 , V_45 ) ;
return 0 ;
}
static void F_585 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_2 V_161 ;
if ( F_53 ( V_6 ) <= 3 &&
( F_79 ( V_6 ) || ! F_137 ( V_6 ) ) )
return;
V_161 = F_17 ( V_587 ) ;
if ( ! ( V_161 & V_588 ) )
return;
if ( F_53 ( V_6 ) < 4 ) {
if ( V_50 -> V_79 != V_105 )
return;
} else {
if ( ( V_161 & V_789 ) != ( V_50 -> V_79 << V_790 ) )
return;
}
V_23 -> V_585 . V_586 = V_161 ;
V_23 -> V_585 . V_590 = F_17 ( V_589 ) ;
}
static void F_586 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
struct V_30 clock ;
T_1 V_681 ;
int V_29 = 100000 ;
if ( ( V_23 -> V_156 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_681 = F_130 ( V_6 , V_79 , F_552 ( V_79 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_39 = ( V_681 >> V_690 ) & 7 ;
clock . V_32 = V_681 & V_691 ;
clock . V_36 = ( V_681 >> V_694 ) & 0xf ;
clock . V_34 = ( V_681 >> V_692 ) & 7 ;
clock . V_35 = ( V_681 >> V_693 ) & 0x1f ;
V_23 -> V_24 = F_24 ( V_29 , & clock ) ;
}
static void
F_587 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_258 ;
int V_79 = V_50 -> V_79 , V_115 = V_50 -> V_115 ;
int V_791 , V_314 ;
unsigned int V_792 ;
struct V_210 * V_74 ;
struct V_248 * V_249 ;
V_15 = F_17 ( F_84 ( V_115 ) ) ;
if ( ! ( V_15 & V_116 ) )
return;
V_249 = F_506 ( sizeof( * V_249 ) , V_622 ) ;
if ( ! V_249 ) {
F_157 ( L_108 ) ;
return;
}
V_74 = & V_249 -> V_49 ;
V_74 -> V_48 = V_48 ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_15 & V_352 ) {
V_303 -> V_312 = V_266 ;
V_74 -> V_213 = V_215 ;
}
}
V_314 = V_15 & V_793 ;
V_791 = F_219 ( V_314 ) ;
V_74 -> V_212 = F_588 ( V_791 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_303 -> V_312 )
V_258 = F_17 ( F_269 ( V_115 ) ) ;
else
V_258 = F_17 ( F_270 ( V_115 ) ) ;
V_49 = F_17 ( F_267 ( V_115 ) ) & 0xfffff000 ;
} else {
V_49 = F_17 ( F_271 ( V_115 ) ) ;
}
V_303 -> V_49 = V_49 ;
V_15 = F_17 ( F_330 ( V_79 ) ) ;
V_74 -> V_225 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_221 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_17 ( F_266 ( V_79 ) ) ;
V_74 -> V_244 [ 0 ] = V_15 & 0xffffffc0 ;
V_792 = F_171 ( V_74 , 0 , V_74 -> V_221 ) ;
V_303 -> V_224 = V_74 -> V_244 [ 0 ] * V_792 ;
F_157 ( L_109 ,
F_73 ( V_79 ) , V_115 , V_74 -> V_225 , V_74 -> V_221 ,
V_74 -> V_212 -> V_211 [ 0 ] * 8 , V_49 , V_74 -> V_244 [ 0 ] ,
V_303 -> V_224 ) ;
V_303 -> V_74 = V_249 ;
}
static void F_589 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
enum V_159 V_160 = F_129 ( V_79 ) ;
struct V_30 clock ;
T_1 V_794 , V_795 , V_796 , V_797 , V_798 ;
int V_29 = 100000 ;
if ( ( V_23 -> V_156 . V_30 & V_88 ) == 0 )
return;
F_3 ( & V_6 -> V_9 ) ;
V_794 = F_130 ( V_6 , V_79 , F_557 ( V_160 ) ) ;
V_795 = F_130 ( V_6 , V_79 , F_558 ( V_160 ) ) ;
V_796 = F_130 ( V_6 , V_79 , F_559 ( V_160 ) ) ;
V_797 = F_130 ( V_6 , V_79 , F_560 ( V_160 ) ) ;
V_798 = F_130 ( V_6 , V_79 , F_561 ( V_160 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
clock . V_39 = ( V_796 & 0x7 ) == V_708 ? 2 : 0 ;
clock . V_32 = ( V_795 & 0xff ) << 22 ;
if ( V_798 & V_711 )
clock . V_32 |= V_797 & 0x3fffff ;
clock . V_36 = ( V_796 >> V_709 ) & 0xf ;
clock . V_34 = ( V_794 >> V_705 ) & 0x7 ;
clock . V_35 = ( V_794 >> V_706 ) & 0x1f ;
V_23 -> V_24 = F_25 ( V_29 , & clock ) ;
}
static bool F_590 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_112 V_113 ;
T_2 V_161 ;
bool V_347 ;
V_113 = F_470 ( V_50 -> V_79 ) ;
if ( ! F_81 ( V_6 , V_113 ) )
return false ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_23 -> V_188 = NULL ;
V_347 = false ;
V_161 = F_17 ( F_54 ( V_50 -> V_79 ) ) ;
if ( ! ( V_161 & V_114 ) )
goto V_799;
if ( F_94 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) {
switch ( V_161 & V_190 ) {
case V_766 :
V_23 -> V_631 = 18 ;
break;
case V_192 :
V_23 -> V_631 = 24 ;
break;
case V_767 :
V_23 -> V_631 = 30 ;
break;
default:
break;
}
}
if ( ( F_11 ( V_6 ) || F_12 ( V_6 ) ) &&
( V_161 & V_773 ) )
V_23 -> V_772 = true ;
if ( F_53 ( V_6 ) < 4 )
V_23 -> V_208 = V_161 & V_209 ;
F_572 ( V_50 , V_23 ) ;
F_573 ( V_50 , V_23 ) ;
F_585 ( V_50 , V_23 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( F_12 ( V_6 ) && V_50 -> V_79 != V_98 )
V_161 = V_6 -> V_166 [ V_50 -> V_79 ] ;
else
V_161 = F_17 ( F_127 ( V_50 -> V_79 ) ) ;
V_23 -> V_580 =
( ( V_161 & V_800 )
>> V_680 ) + 1 ;
V_23 -> V_156 . V_158 = V_161 ;
} else if ( F_568 ( V_6 ) || F_569 ( V_6 ) ||
F_570 ( V_6 ) || F_29 ( V_6 ) ) {
V_161 = F_17 ( F_58 ( V_50 -> V_79 ) ) ;
V_23 -> V_580 =
( ( V_161 & V_801 )
>> V_724 ) + 1 ;
} else {
V_23 -> V_580 = 1 ;
}
V_23 -> V_156 . V_30 = F_17 ( F_58 ( V_50 -> V_79 ) ) ;
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) ) {
if ( F_79 ( V_6 ) )
V_23 -> V_156 . V_30 &= ~ V_170 ;
V_23 -> V_156 . V_611 = F_17 ( F_485 ( V_50 -> V_79 ) ) ;
V_23 -> V_156 . V_612 = F_17 ( F_486 ( V_50 -> V_79 ) ) ;
} else {
V_23 -> V_156 . V_30 &= ~ ( V_157 |
V_183 |
V_181 ) ;
}
if ( F_12 ( V_6 ) )
F_589 ( V_50 , V_23 ) ;
else if ( F_11 ( V_6 ) )
F_586 ( V_50 , V_23 ) ;
else
F_591 ( V_50 , V_23 ) ;
V_23 -> V_49 . V_76 . V_77 =
V_23 -> V_24 / V_23 -> V_580 ;
V_347 = true ;
V_799:
F_82 ( V_6 , V_113 ) ;
return V_347 ;
}
static void F_592 ( struct V_5 * V_6 )
{
struct V_506 * V_507 ;
int V_117 ;
T_1 V_15 , V_802 ;
bool V_803 = false ;
bool V_804 = false ;
bool V_805 = false ;
bool V_806 = false ;
bool V_807 = false ;
bool V_808 = false ;
F_593 (&dev_priv->drm, encoder) {
switch ( V_507 -> type ) {
case V_51 :
V_805 = true ;
V_803 = true ;
break;
case V_509 :
V_805 = true ;
if ( F_387 ( & V_507 -> V_49 ) -> V_160 == V_591 )
V_804 = true ;
break;
default:
break;
}
}
if ( F_117 ( V_6 ) ) {
V_806 = V_6 -> V_663 . V_809 ;
V_807 = V_806 ;
} else {
V_806 = false ;
V_807 = true ;
}
for ( V_117 = 0 ; V_117 < V_6 -> V_810 ; V_117 ++ ) {
T_1 V_439 = F_17 ( F_594 ( V_117 ) ) ;
if ( ! ( V_439 & V_88 ) )
continue;
if ( ( V_439 & V_811 ) ==
V_736 ) {
V_808 = true ;
break;
}
}
F_157 ( L_110 ,
V_805 , V_803 , V_806 , V_808 ) ;
V_15 = F_17 ( V_812 ) ;
V_802 = V_15 ;
V_802 &= ~ V_813 ;
if ( V_806 )
V_802 |= V_814 ;
else
V_802 |= V_815 ;
V_802 &= ~ V_816 ;
V_802 &= ~ V_817 ;
V_802 &= ~ V_818 ;
if ( V_805 ) {
V_802 |= V_819 ;
if ( F_526 ( V_6 ) && V_807 )
V_802 |= V_818 ;
if ( V_804 ) {
if ( F_526 ( V_6 ) && V_807 )
V_802 |= V_820 ;
else
V_802 |= V_821 ;
} else
V_802 |= V_822 ;
} else if ( V_808 ) {
V_802 |= V_819 ;
V_802 |= V_818 ;
}
if ( V_802 == V_15 )
return;
V_15 &= ~ V_813 ;
if ( V_806 )
V_15 |= V_814 ;
else
V_15 |= V_815 ;
if ( V_805 ) {
V_15 &= ~ V_816 ;
V_15 |= V_819 ;
if ( F_526 ( V_6 ) && V_807 ) {
F_157 ( L_111 ) ;
V_15 |= V_818 ;
} else
V_15 &= ~ V_818 ;
F_121 ( V_812 , V_15 ) ;
F_122 ( V_812 ) ;
F_123 ( 200 ) ;
V_15 &= ~ V_817 ;
if ( V_804 ) {
if ( F_526 ( V_6 ) && V_807 ) {
F_157 ( L_112 ) ;
V_15 |= V_820 ;
} else
V_15 |= V_821 ;
} else
V_15 |= V_822 ;
F_121 ( V_812 , V_15 ) ;
F_122 ( V_812 ) ;
F_123 ( 200 ) ;
} else {
F_157 ( L_113 ) ;
V_15 &= ~ V_817 ;
V_15 |= V_822 ;
F_121 ( V_812 , V_15 ) ;
F_122 ( V_812 ) ;
F_123 ( 200 ) ;
if ( ! V_808 ) {
F_157 ( L_114 ) ;
V_15 &= ~ V_816 ;
V_15 |= V_823 ;
V_15 &= ~ V_818 ;
F_121 ( V_812 , V_15 ) ;
F_122 ( V_812 ) ;
F_123 ( 200 ) ;
}
}
F_595 ( V_15 != V_802 ) ;
}
static void F_596 ( struct V_5 * V_6 )
{
T_2 V_161 ;
V_161 = F_17 ( V_824 ) ;
V_161 |= V_825 ;
F_121 ( V_824 , V_161 ) ;
if ( F_597 ( F_17 ( V_824 ) &
V_826 , 100 ) )
F_124 ( L_115 ) ;
V_161 = F_17 ( V_824 ) ;
V_161 &= ~ V_825 ;
F_121 ( V_824 , V_161 ) ;
if ( F_597 ( ( F_17 ( V_824 ) &
V_826 ) == 0 , 100 ) )
F_124 ( L_116 ) ;
}
static void F_598 ( struct V_5 * V_6 )
{
T_2 V_161 ;
V_161 = F_360 ( V_6 , 0x8008 , V_827 ) ;
V_161 &= ~ ( 0xFF << 24 ) ;
V_161 |= ( 0x12 << 24 ) ;
F_361 ( V_6 , 0x8008 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2008 , V_827 ) ;
V_161 |= ( 1 << 11 ) ;
F_361 ( V_6 , 0x2008 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2108 , V_827 ) ;
V_161 |= ( 1 << 11 ) ;
F_361 ( V_6 , 0x2108 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x206C , V_827 ) ;
V_161 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_361 ( V_6 , 0x206C , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x216C , V_827 ) ;
V_161 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_361 ( V_6 , 0x216C , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2080 , V_827 ) ;
V_161 &= ~ ( 7 << 13 ) ;
V_161 |= ( 5 << 13 ) ;
F_361 ( V_6 , 0x2080 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2180 , V_827 ) ;
V_161 &= ~ ( 7 << 13 ) ;
V_161 |= ( 5 << 13 ) ;
F_361 ( V_6 , 0x2180 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x208C , V_827 ) ;
V_161 &= ~ 0xFF ;
V_161 |= 0x1C ;
F_361 ( V_6 , 0x208C , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x218C , V_827 ) ;
V_161 &= ~ 0xFF ;
V_161 |= 0x1C ;
F_361 ( V_6 , 0x218C , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2098 , V_827 ) ;
V_161 &= ~ ( 0xFF << 16 ) ;
V_161 |= ( 0x1C << 16 ) ;
F_361 ( V_6 , 0x2098 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x2198 , V_827 ) ;
V_161 &= ~ ( 0xFF << 16 ) ;
V_161 |= ( 0x1C << 16 ) ;
F_361 ( V_6 , 0x2198 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x20C4 , V_827 ) ;
V_161 |= ( 1 << 27 ) ;
F_361 ( V_6 , 0x20C4 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x21C4 , V_827 ) ;
V_161 |= ( 1 << 27 ) ;
F_361 ( V_6 , 0x21C4 , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x20EC , V_827 ) ;
V_161 &= ~ ( 0xF << 28 ) ;
V_161 |= ( 4 << 28 ) ;
F_361 ( V_6 , 0x20EC , V_161 , V_827 ) ;
V_161 = F_360 ( V_6 , 0x21EC , V_827 ) ;
V_161 &= ~ ( 0xF << 28 ) ;
V_161 |= ( 4 << 28 ) ;
F_361 ( V_6 , 0x21EC , V_161 , V_827 ) ;
}
static void F_599 ( struct V_5 * V_6 ,
bool V_828 , bool V_829 )
{
T_2 V_13 , V_161 ;
if ( F_7 ( V_829 && ! V_828 , L_117 ) )
V_828 = true ;
if ( F_7 ( F_600 ( V_6 ) &&
V_829 , L_118 ) )
V_829 = false ;
F_3 ( & V_6 -> V_9 ) ;
V_161 = F_360 ( V_6 , V_830 , V_482 ) ;
V_161 &= ~ V_483 ;
V_161 |= V_831 ;
F_361 ( V_6 , V_830 , V_161 , V_482 ) ;
F_123 ( 24 ) ;
if ( V_828 ) {
V_161 = F_360 ( V_6 , V_830 , V_482 ) ;
V_161 &= ~ V_831 ;
F_361 ( V_6 , V_830 , V_161 , V_482 ) ;
if ( V_829 ) {
F_596 ( V_6 ) ;
F_598 ( V_6 ) ;
}
}
V_13 = F_600 ( V_6 ) ? V_832 : V_833 ;
V_161 = F_360 ( V_6 , V_13 , V_482 ) ;
V_161 |= V_834 ;
F_361 ( V_6 , V_13 , V_161 , V_482 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_601 ( struct V_5 * V_6 )
{
T_2 V_13 , V_161 ;
F_3 ( & V_6 -> V_9 ) ;
V_13 = F_600 ( V_6 ) ? V_832 : V_833 ;
V_161 = F_360 ( V_6 , V_13 , V_482 ) ;
V_161 &= ~ V_834 ;
F_361 ( V_6 , V_13 , V_161 , V_482 ) ;
V_161 = F_360 ( V_6 , V_830 , V_482 ) ;
if ( ! ( V_161 & V_483 ) ) {
if ( ! ( V_161 & V_831 ) ) {
V_161 |= V_831 ;
F_361 ( V_6 , V_830 , V_161 , V_482 ) ;
F_123 ( 32 ) ;
}
V_161 |= V_483 ;
F_361 ( V_6 , V_830 , V_161 , V_482 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
}
static void F_602 ( struct V_5 * V_6 , int V_835 )
{
T_2 V_161 ;
int V_836 = F_603 ( V_835 ) ;
if ( F_21 ( V_835 % 5 != 0 ) )
return;
if ( F_21 ( V_836 >= F_174 ( V_837 ) ) )
return;
F_3 ( & V_6 -> V_9 ) ;
if ( V_835 % 10 != 0 )
V_161 = 0xAAAAAAAB ;
else
V_161 = 0x00000000 ;
F_361 ( V_6 , V_838 , V_161 , V_482 ) ;
V_161 = F_360 ( V_6 , V_839 , V_482 ) ;
V_161 &= 0xffff0000 ;
V_161 |= V_837 [ V_836 ] ;
F_361 ( V_6 , V_839 , V_161 , V_482 ) ;
F_5 ( & V_6 -> V_9 ) ;
}
static void F_604 ( struct V_5 * V_6 )
{
struct V_506 * V_507 ;
bool V_840 = false ;
F_593 (&dev_priv->drm, encoder) {
switch ( V_507 -> type ) {
case V_699 :
V_840 = true ;
break;
default:
break;
}
}
if ( V_840 ) {
F_602 ( V_6 , 0 ) ;
F_599 ( V_6 , true , true ) ;
} else {
F_601 ( V_6 ) ;
}
}
void F_605 ( struct V_5 * V_6 )
{
if ( F_117 ( V_6 ) || F_103 ( V_6 ) )
F_592 ( V_6 ) ;
else if ( F_155 ( V_6 ) )
F_604 ( V_6 ) ;
}
static void F_446 ( struct V_127 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
int V_79 = V_66 -> V_79 ;
T_2 V_15 ;
V_15 = 0 ;
switch ( V_66 -> V_75 -> V_631 ) {
case 18 :
V_15 |= V_766 ;
break;
case 24 :
V_15 |= V_192 ;
break;
case 30 :
V_15 |= V_767 ;
break;
case 36 :
V_15 |= V_841 ;
break;
default:
F_142 () ;
}
if ( V_66 -> V_75 -> V_763 )
V_15 |= ( V_764 | V_765 ) ;
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_743 )
V_15 |= V_195 ;
else
V_15 |= V_771 ;
if ( V_66 -> V_75 -> V_772 )
V_15 |= V_773 ;
F_121 ( F_54 ( V_79 ) , V_15 ) ;
F_122 ( F_54 ( V_79 ) ) ;
}
static void F_454 ( struct V_127 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
T_1 V_15 = 0 ;
if ( F_254 ( V_6 ) && V_66 -> V_75 -> V_763 )
V_15 |= ( V_764 | V_765 ) ;
if ( V_66 -> V_75 -> V_49 . V_76 . V_315 & V_743 )
V_15 |= V_195 ;
else
V_15 |= V_771 ;
F_121 ( F_54 ( V_80 ) , V_15 ) ;
F_122 ( F_54 ( V_80 ) ) ;
}
static void F_455 ( struct V_127 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
if ( F_255 ( V_6 ) || F_181 ( V_6 ) -> V_232 >= 9 ) {
T_1 V_15 = 0 ;
switch ( V_66 -> V_75 -> V_631 ) {
case 18 :
V_15 |= V_842 ;
break;
case 24 :
V_15 |= V_843 ;
break;
case 30 :
V_15 |= V_844 ;
break;
case 36 :
V_15 |= V_845 ;
break;
default:
F_142 () ;
}
if ( V_66 -> V_75 -> V_763 )
V_15 |= V_846 | V_847 ;
F_121 ( F_606 ( V_66 -> V_79 ) , V_15 ) ;
}
}
int F_513 ( int V_70 , int V_628 , int V_848 )
{
T_1 V_849 = V_70 * V_848 * 21 / 20 ;
return F_217 ( V_849 , V_628 * 8 ) ;
}
static bool F_607 ( struct V_30 * V_30 , int V_850 )
{
return F_22 ( V_30 ) < V_850 * V_30 -> V_36 ;
}
static void F_608 ( struct V_66 * V_66 ,
struct V_22 * V_45 ,
struct V_30 * V_667 )
{
struct V_127 * V_50 = & V_66 -> V_49 ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 , V_668 , V_669 ;
int V_850 ;
V_850 = 21 ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( ( F_526 ( V_6 ) &&
V_6 -> V_663 . V_774 == 100000 ) ||
( F_117 ( V_6 ) && F_33 ( V_48 ) ) )
V_850 = 25 ;
} else if ( V_45 -> V_734 )
V_850 = 20 ;
V_668 = F_528 ( & V_45 -> V_30 ) ;
if ( F_607 ( & V_45 -> V_30 , V_850 ) )
V_668 |= V_851 ;
if ( V_667 ) {
V_669 = F_528 ( V_667 ) ;
if ( V_667 -> V_31 < V_850 * V_667 -> V_36 )
V_669 |= V_851 ;
} else {
V_669 = V_668 ;
}
V_30 = 0 ;
if ( F_32 ( V_45 , V_51 ) )
V_30 |= V_722 ;
else
V_30 |= V_723 ;
V_30 |= ( V_45 -> V_580 - 1 )
<< V_852 ;
if ( F_32 ( V_45 , V_196 ) ||
F_32 ( V_45 , V_191 ) )
V_30 |= V_725 ;
if ( F_395 ( V_45 ) )
V_30 |= V_725 ;
if ( F_181 ( V_6 ) -> V_626 == 3 &&
F_32 ( V_45 , V_699 ) )
V_30 |= V_725 ;
V_30 |= ( 1 << ( V_45 -> V_30 . V_34 - 1 ) ) << V_727 ;
V_30 |= ( 1 << ( V_45 -> V_30 . V_34 - 1 ) ) << V_728 ;
switch ( V_45 -> V_30 . V_35 ) {
case 5 :
V_30 |= V_729 ;
break;
case 7 :
V_30 |= V_730 ;
break;
case 10 :
V_30 |= V_731 ;
break;
case 14 :
V_30 |= V_732 ;
break;
}
if ( F_32 ( V_45 , V_51 ) &&
F_526 ( V_6 ) )
V_30 |= V_736 ;
else
V_30 |= V_737 ;
V_30 |= V_88 ;
V_45 -> V_156 . V_30 = V_30 ;
V_45 -> V_156 . V_611 = V_668 ;
V_45 -> V_156 . V_612 = V_669 ;
}
static int F_609 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
const struct V_41 * V_42 ;
int V_29 = 120000 ;
memset ( & V_45 -> V_156 , 0 ,
sizeof( V_45 -> V_156 ) ) ;
V_50 -> V_670 = false ;
if ( ! V_45 -> V_204 )
return 0 ;
if ( F_32 ( V_45 , V_51 ) ) {
if ( F_526 ( V_6 ) ) {
F_157 ( L_106 ,
V_6 -> V_663 . V_774 ) ;
V_29 = V_6 -> V_663 . V_774 ;
}
if ( F_33 ( V_48 ) ) {
if ( V_29 == 100000 )
V_42 = & V_853 ;
else
V_42 = & V_854 ;
} else {
if ( V_29 == 100000 )
V_42 = & V_855 ;
else
V_42 = & V_856 ;
}
} else {
V_42 = & V_857 ;
}
if ( ! V_45 -> V_778 &&
! F_37 ( V_42 , V_45 , V_45 -> V_24 ,
V_29 , NULL , & V_45 -> V_30 ) ) {
F_124 ( L_107 ) ;
return - V_272 ;
}
F_608 ( V_50 , V_45 , NULL ) ;
if ( ! F_610 ( V_50 , V_45 , NULL ) ) {
F_13 ( L_119 ,
F_73 ( V_50 -> V_79 ) ) ;
return - V_272 ;
}
return 0 ;
}
static void F_611 ( struct V_66 * V_50 ,
struct V_655 * V_656 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
V_656 -> V_660 = F_17 ( F_536 ( V_79 ) ) ;
V_656 -> V_661 = F_17 ( F_537 ( V_79 ) ) ;
V_656 -> V_658 = F_17 ( F_533 ( V_79 ) )
& ~ V_510 ;
V_656 -> V_659 = F_17 ( F_535 ( V_79 ) ) ;
V_656 -> V_657 = ( ( F_17 ( F_533 ( V_79 ) )
& V_510 ) >> V_858 ) + 1 ;
}
static void F_612 ( struct V_66 * V_50 ,
enum V_78 V_78 ,
struct V_655 * V_656 ,
struct V_655 * V_673 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_50 -> V_79 ;
if ( F_53 ( V_6 ) >= 5 ) {
V_656 -> V_660 = F_17 ( F_539 ( V_78 ) ) ;
V_656 -> V_661 = F_17 ( F_540 ( V_78 ) ) ;
V_656 -> V_658 = F_17 ( F_390 ( V_78 ) )
& ~ V_510 ;
V_656 -> V_659 = F_17 ( F_538 ( V_78 ) ) ;
V_656 -> V_657 = ( ( F_17 ( F_390 ( V_78 ) )
& V_510 ) >> V_858 ) + 1 ;
if ( V_673 && F_53 ( V_6 ) < 8 &&
V_50 -> V_75 -> V_674 ) {
V_673 -> V_660 = F_17 ( F_543 ( V_78 ) ) ;
V_673 -> V_661 = F_17 ( F_544 ( V_78 ) ) ;
V_673 -> V_658 = F_17 ( F_541 ( V_78 ) )
& ~ V_510 ;
V_673 -> V_659 = F_17 ( F_542 ( V_78 ) ) ;
V_673 -> V_657 = ( ( F_17 ( F_541 ( V_78 ) )
& V_510 ) >> V_858 ) + 1 ;
}
} else {
V_656 -> V_660 = F_17 ( F_547 ( V_79 ) ) ;
V_656 -> V_661 = F_17 ( F_548 ( V_79 ) ) ;
V_656 -> V_658 = F_17 ( F_545 ( V_79 ) )
& ~ V_510 ;
V_656 -> V_659 = F_17 ( F_546 ( V_79 ) ) ;
V_656 -> V_657 = ( ( F_17 ( F_545 ( V_79 ) )
& V_510 ) >> V_858 ) + 1 ;
}
}
void F_613 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
if ( V_23 -> V_204 )
F_611 ( V_50 , & V_23 -> V_676 ) ;
else
F_612 ( V_50 , V_23 -> V_80 ,
& V_23 -> V_676 ,
& V_23 -> V_677 ) ;
}
static void F_614 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
F_612 ( V_50 , V_23 -> V_80 ,
& V_23 -> V_577 , NULL ) ;
}
static void F_615 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_367 * V_368 = & V_23 -> V_368 ;
T_2 V_412 = 0 ;
int V_262 = - 1 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_50 -> V_369 ; V_117 ++ ) {
V_412 = F_17 ( F_277 ( V_50 -> V_79 , V_117 ) ) ;
if ( V_412 & V_413 && ! ( V_412 & V_859 ) ) {
V_262 = V_117 ;
V_23 -> V_438 . V_128 = true ;
V_23 -> V_438 . V_542 = F_17 ( F_278 ( V_50 -> V_79 , V_117 ) ) ;
V_23 -> V_438 . V_224 = F_17 ( F_279 ( V_50 -> V_79 , V_117 ) ) ;
break;
}
}
V_368 -> V_404 = V_262 ;
if ( V_262 >= 0 ) {
V_368 -> V_528 |= ( 1 << V_537 ) ;
} else {
V_368 -> V_528 &= ~ ( 1 << V_537 ) ;
}
}
static void
F_616 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_258 , V_860 , V_312 ;
int V_79 = V_50 -> V_79 ;
int V_791 , V_314 ;
unsigned int V_792 ;
struct V_210 * V_74 ;
struct V_248 * V_249 ;
V_249 = F_506 ( sizeof( * V_249 ) , V_622 ) ;
if ( ! V_249 ) {
F_157 ( L_108 ) ;
return;
}
V_74 = & V_249 -> V_49 ;
V_74 -> V_48 = V_48 ;
V_15 = F_17 ( F_90 ( V_79 , 0 ) ) ;
if ( ! ( V_15 & V_122 ) )
goto error;
V_314 = V_15 & V_861 ;
V_791 = F_220 ( V_314 ,
V_15 & V_373 ,
V_15 & V_862 ) ;
V_74 -> V_212 = F_588 ( V_791 ) ;
V_312 = V_15 & V_863 ;
switch ( V_312 ) {
case V_864 :
V_74 -> V_213 = V_214 ;
break;
case V_384 :
V_303 -> V_312 = V_266 ;
V_74 -> V_213 = V_215 ;
break;
case V_385 :
V_74 -> V_213 = V_216 ;
break;
case V_386 :
V_74 -> V_213 = V_217 ;
break;
default:
F_168 ( V_312 ) ;
goto error;
}
V_49 = F_17 ( F_295 ( V_79 , 0 ) ) & 0xfffff000 ;
V_303 -> V_49 = V_49 ;
V_258 = F_17 ( F_289 ( V_79 , 0 ) ) ;
V_15 = F_17 ( F_291 ( V_79 , 0 ) ) ;
V_74 -> V_221 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_225 = ( ( V_15 >> 0 ) & 0x1fff ) + 1 ;
V_15 = F_17 ( F_290 ( V_79 , 0 ) ) ;
V_860 = F_275 ( V_74 , 0 ) ;
V_74 -> V_244 [ 0 ] = ( V_15 & 0x3ff ) * V_860 ;
V_792 = F_171 ( V_74 , 0 , V_74 -> V_221 ) ;
V_303 -> V_224 = V_74 -> V_244 [ 0 ] * V_792 ;
F_157 ( L_120 ,
F_73 ( V_79 ) , V_74 -> V_225 , V_74 -> V_221 ,
V_74 -> V_212 -> V_211 [ 0 ] * 8 , V_49 , V_74 -> V_244 [ 0 ] ,
V_303 -> V_224 ) ;
V_303 -> V_74 = V_249 ;
return;
error:
F_235 ( V_249 ) ;
}
static void F_617 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_2 V_161 ;
V_161 = F_17 ( F_402 ( V_50 -> V_79 ) ) ;
if ( V_161 & V_543 ) {
V_23 -> V_438 . V_128 = true ;
V_23 -> V_438 . V_542 = F_17 ( F_404 ( V_50 -> V_79 ) ) ;
V_23 -> V_438 . V_224 = F_17 ( F_405 ( V_50 -> V_79 ) ) ;
if ( F_618 ( V_6 ) ) {
F_21 ( ( V_161 & V_865 ) !=
F_403 ( V_50 -> V_79 ) ) ;
}
}
}
static void
F_619 ( struct V_66 * V_50 ,
struct V_302 * V_303 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_15 , V_49 , V_258 ;
int V_79 = V_50 -> V_79 ;
int V_791 , V_314 ;
unsigned int V_792 ;
struct V_210 * V_74 ;
struct V_248 * V_249 ;
V_15 = F_17 ( F_84 ( V_79 ) ) ;
if ( ! ( V_15 & V_116 ) )
return;
V_249 = F_506 ( sizeof( * V_249 ) , V_622 ) ;
if ( ! V_249 ) {
F_157 ( L_108 ) ;
return;
}
V_74 = & V_249 -> V_49 ;
V_74 -> V_48 = V_48 ;
if ( F_53 ( V_6 ) >= 4 ) {
if ( V_15 & V_352 ) {
V_303 -> V_312 = V_266 ;
V_74 -> V_213 = V_215 ;
}
}
V_314 = V_15 & V_793 ;
V_791 = F_219 ( V_314 ) ;
V_74 -> V_212 = F_588 ( V_791 ) ;
V_49 = F_17 ( F_267 ( V_79 ) ) & 0xfffff000 ;
if ( F_254 ( V_6 ) || F_255 ( V_6 ) ) {
V_258 = F_17 ( F_268 ( V_79 ) ) ;
} else {
if ( V_303 -> V_312 )
V_258 = F_17 ( F_269 ( V_79 ) ) ;
else
V_258 = F_17 ( F_270 ( V_79 ) ) ;
}
V_303 -> V_49 = V_49 ;
V_15 = F_17 ( F_330 ( V_79 ) ) ;
V_74 -> V_225 = ( ( V_15 >> 16 ) & 0xfff ) + 1 ;
V_74 -> V_221 = ( ( V_15 >> 0 ) & 0xfff ) + 1 ;
V_15 = F_17 ( F_266 ( V_79 ) ) ;
V_74 -> V_244 [ 0 ] = V_15 & 0xffffffc0 ;
V_792 = F_171 ( V_74 , 0 , V_74 -> V_221 ) ;
V_303 -> V_224 = V_74 -> V_244 [ 0 ] * V_792 ;
F_157 ( L_120 ,
F_73 ( V_79 ) , V_74 -> V_225 , V_74 -> V_221 ,
V_74 -> V_212 -> V_211 [ 0 ] * 8 , V_49 , V_74 -> V_244 [ 0 ] ,
V_303 -> V_224 ) ;
V_303 -> V_74 = V_249 ;
}
static bool F_620 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
T_2 V_161 ;
bool V_347 ;
V_113 = F_470 ( V_50 -> V_79 ) ;
if ( ! F_81 ( V_6 , V_113 ) )
return false ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_23 -> V_188 = NULL ;
V_347 = false ;
V_161 = F_17 ( F_54 ( V_50 -> V_79 ) ) ;
if ( ! ( V_161 & V_114 ) )
goto V_799;
switch ( V_161 & V_190 ) {
case V_766 :
V_23 -> V_631 = 18 ;
break;
case V_192 :
V_23 -> V_631 = 24 ;
break;
case V_767 :
V_23 -> V_631 = 30 ;
break;
case V_841 :
V_23 -> V_631 = 36 ;
break;
default:
break;
}
if ( V_161 & V_773 )
V_23 -> V_772 = true ;
if ( F_17 ( F_101 ( V_50 -> V_79 ) ) & V_129 ) {
struct V_866 * V_867 ;
enum V_868 V_869 ;
V_23 -> V_204 = true ;
V_161 = F_17 ( F_66 ( V_50 -> V_79 ) ) ;
V_23 -> V_452 = ( ( V_451 & V_161 ) >>
V_870 ) + 1 ;
F_614 ( V_50 , V_23 ) ;
if ( F_117 ( V_6 ) ) {
V_869 = (enum V_868 ) V_50 -> V_79 ;
} else {
V_161 = F_17 ( V_513 ) ;
if ( V_161 & F_392 ( V_50 -> V_79 ) )
V_869 = V_514 ;
else
V_869 = V_871 ;
}
V_23 -> V_188 =
F_393 ( V_6 , V_869 ) ;
V_867 = V_23 -> V_188 ;
F_21 ( ! V_867 -> V_872 . V_620 ( V_6 , V_867 ,
& V_23 -> V_156 ) ) ;
V_161 = V_23 -> V_156 . V_30 ;
V_23 -> V_580 =
( ( V_161 & V_873 )
>> V_852 ) + 1 ;
F_621 ( V_50 , V_23 ) ;
} else {
V_23 -> V_580 = 1 ;
}
F_572 ( V_50 , V_23 ) ;
F_573 ( V_50 , V_23 ) ;
F_617 ( V_50 , V_23 ) ;
V_347 = true ;
V_799:
F_82 ( V_6 , V_113 ) ;
return V_347 ;
}
static void F_622 ( struct V_5 * V_6 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_66 * V_50 ;
F_135 (dev, crtc)
F_59 ( V_50 -> V_72 , L_121 ,
F_73 ( V_50 -> V_79 ) ) ;
F_59 ( F_17 ( V_874 ) , L_122 ) ;
F_59 ( F_17 ( V_875 ) & V_876 , L_123 ) ;
F_59 ( F_17 ( F_623 ( 0 ) ) & V_877 , L_124 ) ;
F_59 ( F_17 ( F_623 ( 1 ) ) & V_877 , L_125 ) ;
F_59 ( F_17 ( F_624 ( 0 ) ) & V_878 , L_126 ) ;
F_59 ( F_17 ( V_879 ) & V_880 ,
L_127 ) ;
if ( F_254 ( V_6 ) )
F_59 ( F_17 ( V_881 ) & V_880 ,
L_128 ) ;
F_59 ( F_17 ( V_882 ) & V_883 ,
L_129 ) ;
F_59 ( F_17 ( V_884 ) & V_885 ,
L_130 ) ;
F_59 ( F_17 ( V_886 ) & V_887 , L_131 ) ;
F_59 ( F_625 ( V_6 ) , L_132 ) ;
}
static T_2 F_626 ( struct V_5 * V_6 )
{
if ( F_254 ( V_6 ) )
return F_17 ( V_888 ) ;
else
return F_17 ( V_889 ) ;
}
static void F_627 ( struct V_5 * V_6 , T_2 V_15 )
{
if ( F_254 ( V_6 ) ) {
F_3 ( & V_6 -> V_546 . V_547 ) ;
if ( F_408 ( V_6 , V_890 ,
V_15 ) )
F_157 ( L_133 ) ;
F_5 ( & V_6 -> V_546 . V_547 ) ;
} else {
F_121 ( V_889 , V_15 ) ;
F_122 ( V_889 ) ;
}
}
static void F_628 ( struct V_5 * V_6 ,
bool V_891 , bool V_892 )
{
T_2 V_15 ;
F_622 ( V_6 ) ;
V_15 = F_17 ( V_893 ) ;
if ( V_891 ) {
V_15 |= V_894 ;
F_121 ( V_893 , V_15 ) ;
if ( F_597 ( F_17 ( V_893 ) &
V_895 , 1 ) )
F_124 ( L_134 ) ;
V_15 = F_17 ( V_893 ) ;
}
V_15 |= V_896 ;
F_121 ( V_893 , V_15 ) ;
F_122 ( V_893 ) ;
if ( F_55 ( V_6 , V_893 , V_897 , 0 , 1 ) )
F_124 ( L_135 ) ;
V_15 = F_626 ( V_6 ) ;
V_15 |= V_898 ;
F_627 ( V_6 , V_15 ) ;
F_629 ( 100 ) ;
if ( F_56 ( ( F_626 ( V_6 ) & V_899 ) == 0 ,
1 ) )
F_124 ( L_136 ) ;
if ( V_892 ) {
V_15 = F_17 ( V_893 ) ;
V_15 |= V_900 ;
F_121 ( V_893 , V_15 ) ;
F_122 ( V_893 ) ;
}
}
static void F_630 ( struct V_5 * V_6 )
{
T_2 V_15 ;
V_15 = F_17 ( V_893 ) ;
if ( ( V_15 & ( V_897 | V_896 | V_894 |
V_900 ) ) == V_897 )
return;
F_631 ( V_6 , V_901 ) ;
if ( V_15 & V_900 ) {
V_15 &= ~ V_900 ;
F_121 ( V_893 , V_15 ) ;
F_122 ( V_893 ) ;
}
V_15 = F_626 ( V_6 ) ;
V_15 |= V_902 ;
V_15 &= ~ V_898 ;
F_627 ( V_6 , V_15 ) ;
V_15 = F_17 ( V_893 ) ;
V_15 &= ~ V_896 ;
F_121 ( V_893 , V_15 ) ;
if ( F_55 ( V_6 ,
V_893 , V_897 , V_897 ,
5 ) )
F_124 ( L_137 ) ;
if ( V_15 & V_894 ) {
V_15 = F_17 ( V_893 ) ;
V_15 &= ~ V_894 ;
F_121 ( V_893 , V_15 ) ;
if ( F_597 ( ( F_17 ( V_893 ) &
V_895 ) == 0 , 1 ) )
F_124 ( L_138 ) ;
}
F_632 ( V_6 , V_901 ) ;
F_633 ( V_6 ) ;
}
void F_634 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_157 ( L_139 ) ;
if ( F_600 ( V_6 ) ) {
V_15 = F_17 ( V_903 ) ;
V_15 &= ~ V_904 ;
F_121 ( V_903 , V_15 ) ;
}
F_601 ( V_6 ) ;
F_628 ( V_6 , true , true ) ;
}
void F_635 ( struct V_5 * V_6 )
{
T_2 V_15 ;
F_157 ( L_140 ) ;
F_630 ( V_6 ) ;
F_604 ( V_6 ) ;
if ( F_600 ( V_6 ) ) {
V_15 = F_17 ( V_903 ) ;
V_15 |= V_904 ;
F_121 ( V_903 , V_15 ) ;
}
}
static int F_636 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
if ( ! F_32 ( V_45 , V_205 ) ) {
struct V_506 * V_507 =
F_637 ( V_45 ) ;
if ( ! F_610 ( V_50 , V_45 , V_507 ) ) {
F_13 ( L_119 ,
F_73 ( V_50 -> V_79 ) ) ;
return - V_272 ;
}
}
V_50 -> V_670 = false ;
return 0 ;
}
static void F_638 ( struct V_5 * V_6 ,
enum V_160 V_160 ,
struct V_22 * V_23 )
{
enum V_868 V_262 ;
T_1 V_439 ;
V_439 = F_17 ( V_905 ) & F_639 ( V_160 ) ;
V_262 = V_439 >> ( V_160 * 2 ) ;
if ( F_21 ( V_262 < V_906 || V_262 > V_907 ) )
return;
V_23 -> V_188 = F_393 ( V_6 , V_262 ) ;
}
static void F_640 ( struct V_5 * V_6 ,
enum V_160 V_160 ,
struct V_22 * V_23 )
{
enum V_868 V_262 ;
switch ( V_160 ) {
case V_591 :
V_262 = V_908 ;
break;
case V_180 :
V_262 = V_909 ;
break;
case V_182 :
V_262 = V_910 ;
break;
default:
F_124 ( L_141 ) ;
return;
}
V_23 -> V_188 = F_393 ( V_6 , V_262 ) ;
}
static void F_641 ( struct V_5 * V_6 ,
enum V_160 V_160 ,
struct V_22 * V_23 )
{
enum V_868 V_262 ;
T_1 V_439 ;
V_439 = F_17 ( V_911 ) & F_642 ( V_160 ) ;
V_262 = V_439 >> ( V_160 * 3 + 1 ) ;
if ( F_21 ( V_262 < V_906 || V_262 > V_912 ) )
return;
V_23 -> V_188 = F_393 ( V_6 , V_262 ) ;
}
static void F_643 ( struct V_5 * V_6 ,
enum V_160 V_160 ,
struct V_22 * V_23 )
{
enum V_868 V_262 ;
T_2 V_913 = F_17 ( F_644 ( V_160 ) ) ;
switch ( V_913 ) {
case V_914 :
V_262 = V_915 ;
break;
case V_916 :
V_262 = V_917 ;
break;
case V_918 :
V_262 = V_919 ;
break;
case V_920 :
V_262 = V_921 ;
break;
case V_922 :
V_262 = V_923 ;
break;
case V_924 :
V_262 = V_925 ;
break;
default:
F_168 ( V_913 ) ;
case V_926 :
return;
}
V_23 -> V_188 = F_393 ( V_6 , V_262 ) ;
}
static bool F_645 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
T_4 * V_927 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
T_1 V_161 ;
V_23 -> V_80 = (enum V_78 ) V_50 -> V_79 ;
V_161 = F_17 ( F_63 ( V_579 ) ) ;
if ( V_161 & V_91 ) {
enum V_79 V_928 ;
switch ( V_161 & V_929 ) {
default:
F_7 ( 1 , L_142 ) ;
case V_930 :
case V_931 :
V_928 = V_98 ;
break;
case V_932 :
V_928 = V_105 ;
break;
case V_933 :
V_928 = V_505 ;
break;
}
if ( V_928 == V_50 -> V_79 )
V_23 -> V_80 = V_579 ;
}
V_113 = F_80 ( V_23 -> V_80 ) ;
if ( ! F_81 ( V_6 , V_113 ) )
return false ;
* V_927 |= F_471 ( V_113 ) ;
V_161 = F_17 ( F_54 ( V_23 -> V_80 ) ) ;
return V_161 & V_114 ;
}
static bool F_646 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
T_4 * V_927 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_112 V_113 ;
enum V_160 V_160 ;
enum V_78 V_80 ;
T_1 V_161 ;
F_647 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_160 == V_591 )
V_80 = V_934 ;
else
V_80 = V_935 ;
V_113 = F_80 ( V_80 ) ;
if ( ! F_81 ( V_6 , V_113 ) )
continue;
* V_927 |= F_471 ( V_113 ) ;
if ( ! F_648 ( V_6 ) )
break;
V_161 = F_17 ( F_649 ( V_160 ) ) ;
if ( ! ( V_161 & V_936 ) )
continue;
V_161 = F_17 ( F_650 ( V_160 ) ) ;
if ( ( V_161 & V_937 ) != F_651 ( V_50 -> V_79 ) )
continue;
V_23 -> V_80 = V_80 ;
break;
}
return F_452 ( V_23 -> V_80 ) ;
}
static void F_652 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_866 * V_867 ;
enum V_160 V_160 ;
T_2 V_161 ;
V_161 = F_17 ( F_63 ( V_23 -> V_80 ) ) ;
V_160 = ( V_161 & V_938 ) >> V_939 ;
if ( F_653 ( V_6 ) )
F_638 ( V_6 , V_160 , V_23 ) ;
else if ( F_654 ( V_6 ) )
F_641 ( V_6 , V_160 , V_23 ) ;
else if ( F_30 ( V_6 ) )
F_640 ( V_6 , V_160 , V_23 ) ;
else
F_643 ( V_6 , V_160 , V_23 ) ;
V_867 = V_23 -> V_188 ;
if ( V_867 ) {
F_21 ( ! V_867 -> V_872 . V_620 ( V_6 , V_867 ,
& V_23 -> V_156 ) ) ;
}
if ( F_53 ( V_6 ) < 9 &&
( V_160 == V_596 ) && F_17 ( V_203 ) & V_129 ) {
V_23 -> V_204 = true ;
V_161 = F_17 ( F_66 ( V_98 ) ) ;
V_23 -> V_452 = ( ( V_451 & V_161 ) >>
V_870 ) + 1 ;
F_614 ( V_50 , V_23 ) ;
}
}
static bool F_655 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
enum V_112 V_113 ;
T_4 V_927 ;
bool V_72 ;
if ( F_53 ( V_6 ) >= 9 ) {
F_656 ( V_50 , V_23 ) ;
V_23 -> V_368 . V_404 = - 1 ;
V_23 -> V_368 . V_528 &= ~ ( 1 << V_537 ) ;
}
V_113 = F_470 ( V_50 -> V_79 ) ;
if ( ! F_81 ( V_6 , V_113 ) )
return false ;
V_927 = F_471 ( V_113 ) ;
V_23 -> V_188 = NULL ;
V_72 = F_645 ( V_50 , V_23 , & V_927 ) ;
if ( F_30 ( V_6 ) &&
F_646 ( V_50 , V_23 , & V_927 ) ) {
F_21 ( V_72 ) ;
V_72 = true ;
}
if ( ! V_72 )
goto V_799;
if ( ! F_452 ( V_23 -> V_80 ) ) {
F_652 ( V_50 , V_23 ) ;
F_572 ( V_50 , V_23 ) ;
}
F_573 ( V_50 , V_23 ) ;
V_23 -> V_940 =
F_17 ( F_657 ( V_50 -> V_79 ) ) & V_941 ;
V_113 = F_472 ( V_50 -> V_79 ) ;
if ( F_81 ( V_6 , V_113 ) ) {
V_927 |= F_471 ( V_113 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_615 ( V_50 , V_23 ) ;
else
F_617 ( V_50 , V_23 ) ;
}
if ( F_254 ( V_6 ) )
V_23 -> V_545 = F_449 ( V_50 ) &&
( F_17 ( V_549 ) & V_550 ) ;
if ( V_23 -> V_80 != V_579 &&
! F_452 ( V_23 -> V_80 ) ) {
V_23 -> V_580 =
F_17 ( F_453 ( V_23 -> V_80 ) ) + 1 ;
} else {
V_23 -> V_580 = 1 ;
}
V_799:
F_475 (power_domain, power_domain_mask)
F_82 ( V_6 , V_113 ) ;
return V_72 ;
}
static T_1 F_658 ( const struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
const struct V_235 * V_236 = F_186 ( V_74 ) ;
T_1 V_49 ;
if ( F_181 ( V_6 ) -> V_942 )
V_49 = V_236 -> V_943 -> V_944 ;
else
V_49 = F_237 ( V_319 ) ;
V_49 += V_319 -> main. V_258 ;
if ( F_159 ( V_6 ) &&
V_319 -> V_49 . V_228 & V_353 )
V_49 += ( V_319 -> V_49 . V_335 *
V_319 -> V_49 . V_334 - 1 ) * V_74 -> V_212 -> V_211 [ 0 ] ;
return V_49 ;
}
static T_1 F_659 ( const struct V_247 * V_319 )
{
int V_245 = V_319 -> V_49 . V_332 ;
int V_246 = V_319 -> V_49 . V_333 ;
T_1 V_542 = 0 ;
if ( V_245 < 0 ) {
V_542 |= V_945 << V_946 ;
V_245 = - V_245 ;
}
V_542 |= V_245 << V_946 ;
if ( V_246 < 0 ) {
V_542 |= V_945 << V_947 ;
V_246 = - V_246 ;
}
V_542 |= V_246 << V_947 ;
return V_542 ;
}
static bool F_660 ( const struct V_247 * V_319 )
{
const struct V_948 * V_75 =
& V_319 -> V_49 . V_115 -> V_48 -> V_423 ;
int V_225 = V_319 -> V_49 . V_334 ;
int V_221 = V_319 -> V_49 . V_335 ;
return V_225 > 0 && V_225 <= V_75 -> V_949 &&
V_221 > 0 && V_221 <= V_75 -> V_950 ;
}
static int F_661 ( struct V_22 * V_45 ,
struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
int V_328 , V_329 ;
T_1 V_258 ;
int V_347 ;
V_347 = F_662 ( & V_319 -> V_49 ,
& V_319 -> V_951 ,
V_952 ,
V_952 ,
true , true ) ;
if ( V_347 )
return V_347 ;
if ( ! V_74 )
return 0 ;
if ( V_74 -> V_213 != V_214 ) {
F_157 ( L_143 ) ;
return - V_272 ;
}
V_328 = V_319 -> V_49 . V_328 >> 16 ;
V_329 = V_319 -> V_49 . V_329 >> 16 ;
F_204 ( & V_328 , & V_329 , V_319 , 0 ) ;
V_258 = F_209 ( & V_328 , & V_329 , V_319 , 0 ) ;
if ( V_328 != 0 || V_329 != 0 ) {
F_157 ( L_144 ) ;
return - V_272 ;
}
V_319 -> main. V_258 = V_258 ;
return 0 ;
}
static T_1 F_663 ( const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
return V_110 |
V_953 |
V_954 |
F_664 ( V_74 -> V_244 [ 0 ] ) ;
}
static bool F_665 ( const struct V_247 * V_319 )
{
int V_225 = V_319 -> V_49 . V_334 ;
return F_660 ( V_319 ) && F_666 ( V_225 , 64 ) ;
}
static int F_667 ( struct V_261 * V_115 ,
struct V_22 * V_45 ,
struct V_247 * V_319 )
{
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
int V_347 ;
V_347 = F_661 ( V_45 , V_319 ) ;
if ( V_347 )
return V_347 ;
if ( ! V_74 )
return 0 ;
if ( ! F_665 ( V_319 ) ) {
F_668 ( L_145 ,
V_319 -> V_49 . V_334 ,
V_319 -> V_49 . V_335 ) ;
return - V_272 ;
}
switch ( V_74 -> V_244 [ 0 ] ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_157 ( L_146 ,
V_74 -> V_244 [ 0 ] ) ;
return - V_272 ;
}
V_319 -> V_357 = F_663 ( V_45 , V_319 ) ;
return 0 ;
}
static void F_669 ( struct V_261 * V_115 ,
const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
T_1 V_955 = 0 , V_49 = 0 , V_542 = 0 , V_224 = 0 ;
unsigned long V_358 ;
if ( V_319 && V_319 -> V_49 . V_320 ) {
unsigned int V_225 = V_319 -> V_49 . V_334 ;
unsigned int V_221 = V_319 -> V_49 . V_335 ;
V_955 = V_319 -> V_357 ;
V_224 = ( V_221 << 12 ) | V_225 ;
V_49 = F_658 ( V_319 ) ;
V_542 = F_659 ( V_319 ) ;
}
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
if ( V_115 -> V_956 . V_49 != V_49 ||
V_115 -> V_956 . V_224 != V_224 ||
V_115 -> V_956 . V_955 != V_955 ) {
F_260 ( F_77 ( V_98 ) , 0 ) ;
F_260 ( F_670 ( V_98 ) , V_49 ) ;
F_260 ( V_957 , V_224 ) ;
F_260 ( F_671 ( V_98 ) , V_542 ) ;
F_260 ( F_77 ( V_98 ) , V_955 ) ;
V_115 -> V_956 . V_49 = V_49 ;
V_115 -> V_956 . V_224 = V_224 ;
V_115 -> V_956 . V_955 = V_955 ;
} else {
F_260 ( F_671 ( V_98 ) , V_542 ) ;
}
F_272 ( F_77 ( V_98 ) ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static void F_672 ( struct V_261 * V_115 ,
struct V_66 * V_50 )
{
F_669 ( V_115 , NULL , NULL ) ;
}
static T_1 F_673 ( const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
struct V_66 * V_50 = F_42 ( V_45 -> V_49 . V_50 ) ;
T_1 V_955 ;
V_955 = V_958 ;
if ( F_15 ( V_6 ) )
V_955 |= V_959 ;
V_955 |= F_674 ( V_50 -> V_79 ) ;
switch ( V_319 -> V_49 . V_334 ) {
case 64 :
V_955 |= V_960 ;
break;
case 128 :
V_955 |= V_961 ;
break;
case 256 :
V_955 |= V_962 ;
break;
default:
F_168 ( V_319 -> V_49 . V_334 ) ;
return 0 ;
}
if ( V_319 -> V_49 . V_228 & V_353 )
V_955 |= V_963 ;
return V_955 ;
}
static bool F_675 ( const struct V_247 * V_319 )
{
struct V_5 * V_6 =
F_35 ( V_319 -> V_49 . V_115 -> V_48 ) ;
int V_225 = V_319 -> V_49 . V_334 ;
int V_221 = V_319 -> V_49 . V_335 ;
if ( ! F_660 ( V_319 ) )
return false ;
switch ( V_225 ) {
case 256 :
case 128 :
case 64 :
break;
default:
return false ;
}
if ( F_676 ( V_6 ) &&
V_319 -> V_49 . V_228 & V_273 ) {
if ( V_221 < 8 || V_221 > V_225 )
return false ;
} else {
if ( V_221 != V_225 )
return false ;
}
return true ;
}
static int F_677 ( struct V_261 * V_115 ,
struct V_22 * V_45 ,
struct V_247 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
const struct V_210 * V_74 = V_319 -> V_49 . V_74 ;
enum V_79 V_79 = V_115 -> V_79 ;
int V_347 ;
V_347 = F_661 ( V_45 , V_319 ) ;
if ( V_347 )
return V_347 ;
if ( ! V_74 )
return 0 ;
if ( ! F_675 ( V_319 ) ) {
F_668 ( L_145 ,
V_319 -> V_49 . V_334 ,
V_319 -> V_49 . V_335 ) ;
return - V_272 ;
}
if ( V_74 -> V_244 [ 0 ] != V_319 -> V_49 . V_334 * V_74 -> V_212 -> V_211 [ 0 ] ) {
F_157 ( L_147 ,
V_74 -> V_244 [ 0 ] , V_319 -> V_49 . V_334 ) ;
return - V_272 ;
}
if ( F_12 ( V_6 ) && V_79 == V_505 &&
V_319 -> V_49 . V_320 && V_319 -> V_49 . V_332 < 0 ) {
F_157 ( L_148 ) ;
return - V_272 ;
}
V_319 -> V_357 = F_673 ( V_45 , V_319 ) ;
return 0 ;
}
static void F_678 ( struct V_261 * V_115 ,
const struct V_22 * V_45 ,
const struct V_247 * V_319 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
enum V_79 V_79 = V_115 -> V_79 ;
T_1 V_955 = 0 , V_49 = 0 , V_542 = 0 , V_964 = 0 ;
unsigned long V_358 ;
if ( V_319 && V_319 -> V_49 . V_320 ) {
V_955 = V_319 -> V_357 ;
if ( V_319 -> V_49 . V_335 != V_319 -> V_49 . V_334 )
V_964 = V_965 | ( V_319 -> V_49 . V_335 - 1 ) ;
V_49 = F_658 ( V_319 ) ;
V_542 = F_659 ( V_319 ) ;
}
F_259 ( & V_6 -> V_362 . V_363 , V_358 ) ;
if ( V_115 -> V_956 . V_49 != V_49 ||
V_115 -> V_956 . V_224 != V_964 ||
V_115 -> V_956 . V_955 != V_955 ) {
F_260 ( F_77 ( V_79 ) , V_955 ) ;
if ( F_676 ( V_6 ) )
F_260 ( F_679 ( V_79 ) , V_964 ) ;
F_260 ( F_671 ( V_79 ) , V_542 ) ;
F_260 ( F_670 ( V_79 ) , V_49 ) ;
V_115 -> V_956 . V_49 = V_49 ;
V_115 -> V_956 . V_224 = V_964 ;
V_115 -> V_956 . V_955 = V_955 ;
} else {
F_260 ( F_671 ( V_79 ) , V_542 ) ;
F_260 ( F_670 ( V_79 ) , V_49 ) ;
}
F_272 ( F_670 ( V_79 ) ) ;
F_273 ( & V_6 -> V_362 . V_363 , V_358 ) ;
}
static void F_680 ( struct V_261 * V_115 ,
struct V_66 * V_50 )
{
F_678 ( V_115 , NULL , NULL ) ;
}
struct V_210 *
F_681 ( struct V_235 * V_236 ,
struct V_306 * V_307 )
{
struct V_248 * V_249 ;
int V_347 ;
V_249 = F_506 ( sizeof( * V_249 ) , V_622 ) ;
if ( ! V_249 )
return F_682 ( - V_623 ) ;
V_347 = F_225 ( V_249 , V_236 , V_307 ) ;
if ( V_347 )
goto V_57;
return & V_249 -> V_49 ;
V_57:
F_235 ( V_249 ) ;
return F_682 ( V_347 ) ;
}
static T_1
F_683 ( int V_225 , int V_848 )
{
T_1 V_243 = F_217 ( V_225 * V_848 , 8 ) ;
return F_172 ( V_243 , 64 ) ;
}
static T_1
F_684 ( struct V_515 * V_414 , int V_848 )
{
T_1 V_243 = F_683 ( V_414 -> V_752 , V_848 ) ;
return F_685 ( V_243 * V_414 -> V_751 ) ;
}
static struct V_210 *
F_686 ( struct V_47 * V_48 ,
struct V_515 * V_414 ,
int V_966 , int V_848 )
{
struct V_210 * V_74 ;
struct V_235 * V_236 ;
struct V_306 V_307 = { 0 } ;
V_236 = F_687 ( F_35 ( V_48 ) ,
F_684 ( V_414 , V_848 ) ) ;
if ( F_191 ( V_236 ) )
return F_688 ( V_236 ) ;
V_307 . V_225 = V_414 -> V_752 ;
V_307 . V_221 = V_414 -> V_751 ;
V_307 . V_244 [ 0 ] = F_683 ( V_307 . V_225 ,
V_848 ) ;
V_307 . V_314 = F_689 ( V_848 , V_966 ) ;
V_74 = F_681 ( V_236 , & V_307 ) ;
if ( F_191 ( V_74 ) )
F_226 ( V_236 ) ;
return V_74 ;
}
static struct V_210 *
F_690 ( struct V_47 * V_48 ,
struct V_515 * V_414 )
{
#ifdef F_691
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_235 * V_236 ;
struct V_210 * V_74 ;
if ( ! V_6 -> V_967 )
return NULL ;
if ( ! V_6 -> V_967 -> V_74 )
return NULL ;
V_236 = V_6 -> V_967 -> V_74 -> V_236 ;
F_595 ( ! V_236 ) ;
V_74 = & V_6 -> V_967 -> V_74 -> V_49 ;
if ( V_74 -> V_244 [ 0 ] < F_683 ( V_414 -> V_752 ,
V_74 -> V_212 -> V_211 [ 0 ] * 8 ) )
return NULL ;
if ( V_236 -> V_49 . V_224 < V_414 -> V_751 * V_74 -> V_244 [ 0 ] )
return NULL ;
F_229 ( V_74 ) ;
return V_74 ;
#else
return NULL ;
#endif
}
static int F_692 ( struct V_415 * V_28 ,
struct V_127 * V_50 ,
struct V_515 * V_414 ,
struct V_210 * V_74 ,
int V_245 , int V_246 )
{
struct V_324 * V_319 ;
int V_752 , V_751 ;
int V_347 ;
V_319 = F_693 ( V_28 , V_50 -> V_73 ) ;
if ( F_191 ( V_319 ) )
return F_241 ( V_319 ) ;
if ( V_414 )
F_694 ( V_414 , & V_752 , & V_751 ) ;
else
V_752 = V_751 = 0 ;
V_347 = F_695 ( V_319 , V_74 ? V_50 : NULL ) ;
if ( V_347 )
return V_347 ;
F_696 ( V_319 , V_74 ) ;
V_319 -> V_332 = 0 ;
V_319 -> V_333 = 0 ;
V_319 -> V_334 = V_752 ;
V_319 -> V_335 = V_751 ;
V_319 -> V_328 = V_245 << 16 ;
V_319 -> V_329 = V_246 << 16 ;
V_319 -> V_330 = V_752 << 16 ;
V_319 -> V_331 = V_751 << 16 ;
return 0 ;
}
int F_697 ( struct V_567 * V_619 ,
struct V_515 * V_414 ,
struct V_968 * V_969 ,
struct V_416 * V_417 )
{
struct V_66 * V_66 ;
struct V_506 * V_506 =
F_698 ( V_619 ) ;
struct V_127 * V_970 ;
struct V_599 * V_507 = & V_506 -> V_49 ;
struct V_127 * V_50 = NULL ;
struct V_47 * V_48 = V_507 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_210 * V_74 ;
struct V_948 * V_75 = & V_48 -> V_423 ;
struct V_415 * V_28 = NULL , * V_971 = NULL ;
struct V_565 * V_972 ;
struct V_22 * V_45 ;
int V_347 , V_117 = - 1 ;
F_157 ( L_149 ,
V_619 -> V_49 . V_262 , V_619 -> V_12 ,
V_507 -> V_49 . V_262 , V_507 -> V_12 ) ;
V_969 -> V_971 = NULL ;
F_21 ( ! F_699 ( & V_75 -> V_973 ) ) ;
if ( V_619 -> V_28 -> V_50 ) {
V_50 = V_619 -> V_28 -> V_50 ;
V_347 = F_700 ( & V_50 -> V_424 , V_417 ) ;
if ( V_347 )
goto V_974;
goto V_60;
}
F_236 (dev, possible_crtc) {
V_117 ++ ;
if ( ! ( V_507 -> V_975 & ( 1 << V_117 ) ) )
continue;
V_347 = F_700 ( & V_970 -> V_424 , V_417 ) ;
if ( V_347 )
goto V_974;
if ( V_970 -> V_28 -> V_502 ) {
F_701 ( & V_970 -> V_424 ) ;
continue;
}
V_50 = V_970 ;
break;
}
if ( ! V_50 ) {
F_157 ( L_150 ) ;
V_347 = - V_976 ;
goto V_974;
}
V_60:
V_66 = F_42 ( V_50 ) ;
V_347 = F_700 ( & V_50 -> V_73 -> V_424 , V_417 ) ;
if ( V_347 )
goto V_974;
V_28 = F_492 ( V_48 ) ;
V_971 = F_492 ( V_48 ) ;
if ( ! V_28 || ! V_971 ) {
V_347 = - V_623 ;
goto V_974;
}
V_28 -> V_426 = V_417 ;
V_971 -> V_426 = V_417 ;
V_972 = F_702 ( V_28 , V_619 ) ;
if ( F_191 ( V_972 ) ) {
V_347 = F_241 ( V_972 ) ;
goto V_974;
}
V_347 = F_703 ( V_972 , V_50 ) ;
if ( V_347 )
goto V_974;
V_45 = F_493 ( V_28 , V_66 ) ;
if ( F_191 ( V_45 ) ) {
V_347 = F_241 ( V_45 ) ;
goto V_974;
}
V_45 -> V_49 . V_72 = V_45 -> V_49 . V_502 = true ;
if ( ! V_414 )
V_414 = & V_977 ;
V_74 = F_690 ( V_48 , V_414 ) ;
if ( V_74 == NULL ) {
F_157 ( L_151 ) ;
V_74 = F_686 ( V_48 , V_414 , 24 , 32 ) ;
} else
F_157 ( L_152 ) ;
if ( F_191 ( V_74 ) ) {
F_157 ( L_153 ) ;
V_347 = F_241 ( V_74 ) ;
goto V_974;
}
V_347 = F_692 ( V_28 , V_50 , V_414 , V_74 , 0 , 0 ) ;
if ( V_347 )
goto V_974;
F_228 ( V_74 ) ;
V_347 = F_495 ( & V_45 -> V_49 , V_414 ) ;
if ( V_347 )
goto V_974;
V_347 = F_500 ( F_702 ( V_971 , V_619 ) ) ;
if ( ! V_347 )
V_347 = F_500 ( F_704 ( V_971 , V_50 ) ) ;
if ( ! V_347 )
V_347 = F_500 ( F_693 ( V_971 , V_50 -> V_73 ) ) ;
if ( V_347 ) {
F_157 ( L_154 , V_347 ) ;
goto V_974;
}
V_347 = F_705 ( V_28 ) ;
if ( V_347 ) {
F_157 ( L_155 ) ;
goto V_974;
}
V_969 -> V_971 = V_971 ;
F_314 ( V_28 ) ;
F_349 ( V_6 , V_66 -> V_79 ) ;
return true ;
V_974:
if ( V_28 ) {
F_314 ( V_28 ) ;
V_28 = NULL ;
}
if ( V_971 ) {
F_314 ( V_971 ) ;
V_971 = NULL ;
}
if ( V_347 == - V_420 )
return V_347 ;
return false ;
}
void F_706 ( struct V_567 * V_619 ,
struct V_968 * V_969 ,
struct V_416 * V_417 )
{
struct V_506 * V_506 =
F_698 ( V_619 ) ;
struct V_599 * V_507 = & V_506 -> V_49 ;
struct V_415 * V_28 = V_969 -> V_971 ;
int V_347 ;
F_157 ( L_149 ,
V_619 -> V_49 . V_262 , V_619 -> V_12 ,
V_507 -> V_49 . V_262 , V_507 -> V_12 ) ;
if ( ! V_28 )
return;
V_347 = F_304 ( V_28 , V_417 ) ;
if ( V_347 )
F_157 ( L_156 , V_347 ) ;
F_314 ( V_28 ) ;
}
static int F_707 ( struct V_47 * V_48 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
T_1 V_30 = V_23 -> V_156 . V_30 ;
if ( ( V_30 & V_811 ) == V_736 )
return V_6 -> V_663 . V_774 ;
else if ( F_70 ( V_6 ) )
return 120000 ;
else if ( ! F_50 ( V_6 ) )
return 96000 ;
else
return 48000 ;
}
static void F_591 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_79 = V_23 -> V_80 ;
T_1 V_30 = V_23 -> V_156 . V_30 ;
T_1 V_668 ;
struct V_30 clock ;
int V_24 ;
int V_29 = F_707 ( V_48 , V_23 ) ;
if ( ( V_30 & V_978 ) == 0 )
V_668 = V_23 -> V_156 . V_611 ;
else
V_668 = V_23 -> V_156 . V_612 ;
clock . V_39 = ( V_668 & V_979 ) >> V_980 ;
if ( F_29 ( V_6 ) ) {
clock . V_36 = F_708 ( ( V_668 & V_981 ) >> V_982 ) - 1 ;
clock . V_32 = ( V_668 & V_983 ) >> V_984 ;
} else {
clock . V_36 = ( V_668 & V_985 ) >> V_982 ;
clock . V_32 = ( V_668 & V_986 ) >> V_984 ;
}
if ( ! F_50 ( V_6 ) ) {
if ( F_29 ( V_6 ) )
clock . V_34 = F_708 ( ( V_30 & V_987 ) >>
V_726 ) ;
else
clock . V_34 = F_708 ( ( V_30 & V_988 ) >>
V_727 ) ;
switch ( V_30 & V_989 ) {
case V_723 :
clock . V_35 = V_30 & V_729 ?
5 : 10 ;
break;
case V_722 :
clock . V_35 = V_30 & V_730 ?
7 : 14 ;
break;
default:
F_157 ( L_157
L_158 , ( int ) ( V_30 & V_989 ) ) ;
return;
}
if ( F_29 ( V_6 ) )
V_24 = F_20 ( V_29 , & clock ) ;
else
V_24 = F_23 ( V_29 , & clock ) ;
} else {
T_1 V_990 = F_79 ( V_6 ) ? 0 : F_17 ( V_106 ) ;
bool V_991 = ( V_79 == 1 ) && ( V_990 & V_139 ) ;
if ( V_991 ) {
clock . V_34 = F_708 ( ( V_30 & V_992 ) >>
V_727 ) ;
if ( V_990 & V_993 )
clock . V_35 = 7 ;
else
clock . V_35 = 14 ;
} else {
if ( V_30 & V_738 )
clock . V_34 = 2 ;
else {
clock . V_34 = ( ( V_30 & V_994 ) >>
V_727 ) + 2 ;
}
if ( V_30 & V_739 )
clock . V_35 = 4 ;
else
clock . V_35 = 2 ;
}
V_24 = F_23 ( V_29 , & clock ) ;
}
V_23 -> V_24 = V_24 ;
}
int F_709 ( int V_995 ,
const struct V_655 * V_656 )
{
if ( ! V_656 -> V_661 )
return 0 ;
return F_40 ( ( T_4 ) V_656 -> V_660 * V_995 , V_656 -> V_661 ) ;
}
static void F_621 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
F_591 ( V_50 , V_23 ) ;
V_23 -> V_49 . V_76 . V_77 =
F_709 ( F_14 ( V_6 , V_23 ) ,
& V_23 -> V_577 ) ;
}
struct V_515 * F_710 ( struct V_47 * V_48 ,
struct V_127 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
enum V_78 V_80 = V_66 -> V_75 -> V_80 ;
struct V_515 * V_414 ;
struct V_22 * V_23 ;
int V_996 = F_17 ( F_370 ( V_80 ) ) ;
int V_760 = F_17 ( F_374 ( V_80 ) ) ;
int V_997 = F_17 ( F_376 ( V_80 ) ) ;
int V_998 = F_17 ( F_380 ( V_80 ) ) ;
enum V_79 V_79 = V_66 -> V_79 ;
V_414 = F_506 ( sizeof( * V_414 ) , V_622 ) ;
if ( ! V_414 )
return NULL ;
V_23 = F_506 ( sizeof( * V_23 ) , V_622 ) ;
if ( ! V_23 ) {
F_235 ( V_414 ) ;
return NULL ;
}
V_23 -> V_80 = (enum V_78 ) V_79 ;
V_23 -> V_580 = 1 ;
V_23 -> V_156 . V_30 = F_17 ( F_58 ( V_79 ) ) ;
V_23 -> V_156 . V_611 = F_17 ( F_485 ( V_79 ) ) ;
V_23 -> V_156 . V_612 = F_17 ( F_486 ( V_79 ) ) ;
F_591 ( V_66 , V_23 ) ;
V_414 -> clock = V_23 -> V_24 / V_23 -> V_580 ;
V_414 -> V_752 = ( V_996 & 0xffff ) + 1 ;
V_414 -> V_753 = ( ( V_996 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_754 = ( V_760 & 0xffff ) + 1 ;
V_414 -> V_755 = ( ( V_760 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_751 = ( V_997 & 0xffff ) + 1 ;
V_414 -> V_756 = ( ( V_997 & 0xffff0000 ) >> 16 ) + 1 ;
V_414 -> V_757 = ( V_998 & 0xffff ) + 1 ;
V_414 -> V_758 = ( ( V_998 & 0xffff0000 ) >> 16 ) + 1 ;
F_577 ( V_414 ) ;
F_235 ( V_23 ) ;
return V_414 ;
}
static void F_711 ( struct V_127 * V_50 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_1 * V_2 ;
F_320 ( & V_48 -> V_435 ) ;
V_2 = V_66 -> V_436 ;
V_66 -> V_436 = NULL ;
F_321 ( & V_48 -> V_435 ) ;
if ( V_2 ) {
F_712 ( & V_2 -> V_3 ) ;
F_712 ( & V_2 -> V_477 ) ;
F_235 ( V_2 ) ;
}
F_713 ( V_50 ) ;
F_235 ( V_66 ) ;
}
static void F_714 ( struct V_999 * V_1000 )
{
struct V_1 * V_2 =
F_715 ( V_1000 , struct V_1 , V_477 ) ;
struct V_66 * V_50 = F_42 ( V_2 -> V_50 ) ;
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_318 * V_73 = V_50 -> V_49 . V_73 ;
if ( F_1 ( V_2 ) )
F_716 ( & V_2 -> V_3 ) ;
F_3 ( & V_48 -> V_239 ) ;
F_197 ( V_2 -> V_1001 ) ;
F_226 ( V_2 -> V_475 ) ;
F_5 ( & V_48 -> V_239 ) ;
F_717 ( V_2 -> V_1002 ) ;
F_718 ( F_35 ( V_48 ) ,
F_210 ( V_73 ) -> V_339 ) ;
F_422 ( V_50 ) ;
F_228 ( V_2 -> V_1003 ) ;
F_595 ( F_348 ( & V_50 -> V_472 ) == 0 ) ;
F_719 ( & V_50 -> V_472 ) ;
F_235 ( V_2 ) ;
}
static bool F_720 ( T_1 V_1004 , T_1 V_1005 )
{
return ! ( ( V_1004 - V_1005 ) & 0x80000000 ) ;
}
static bool F_721 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( F_325 ( V_50 ) )
return true ;
if ( F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) )
return true ;
return ( F_17 ( F_722 ( V_50 -> V_115 ) ) & ~ 0xfff ) ==
V_50 -> V_436 -> V_1006 &&
F_720 ( F_17 ( F_723 ( V_50 -> V_79 ) ) ,
V_50 -> V_436 -> V_1007 ) ;
}
static bool
F_724 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
return F_725 ( V_50 ) != V_2 -> V_1008 ;
}
static bool F_726 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
if ( ! F_348 ( & V_2 -> V_434 ) )
return false ;
F_727 () ;
if ( F_1 ( V_2 ) )
return F_724 ( V_50 , V_2 ) ;
else
return F_721 ( V_50 , V_2 ) ;
}
void F_298 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
unsigned long V_315 ;
if ( ! V_50 )
return;
F_259 ( & V_48 -> V_435 , V_315 ) ;
V_2 = V_50 -> V_436 ;
if ( V_2 != NULL &&
! F_1 ( V_2 ) &&
F_726 ( V_50 , V_2 ) )
F_350 ( V_50 ) ;
F_273 ( & V_48 -> V_435 , V_315 ) ;
}
void F_728 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
unsigned long V_315 ;
if ( ! V_50 )
return;
F_259 ( & V_48 -> V_435 , V_315 ) ;
V_2 = V_50 -> V_436 ;
if ( V_2 != NULL &&
F_1 ( V_2 ) &&
F_726 ( V_50 , V_2 ) )
F_350 ( V_50 ) ;
F_273 ( & V_48 -> V_435 , V_315 ) ;
}
static inline void F_729 ( struct V_66 * V_50 ,
struct V_1 * V_2 )
{
V_2 -> V_1008 = F_725 ( V_50 ) ;
F_730 () ;
F_731 ( & V_2 -> V_434 , 1 ) ;
}
static int F_732 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1011 , * V_1012 ;
V_1012 = F_733 ( V_1010 , 6 ) ;
if ( F_191 ( V_1012 ) )
return F_241 ( V_1012 ) ;
if ( V_66 -> V_115 )
V_1011 = V_1013 ;
else
V_1011 = V_1014 ;
* V_1012 ++ = V_1015 | V_1011 ;
* V_1012 ++ = V_1016 ;
* V_1012 ++ = V_1017 | F_734 ( V_66 -> V_115 ) ;
* V_1012 ++ = V_74 -> V_244 [ 0 ] ;
* V_1012 ++ = V_66 -> V_436 -> V_1006 ;
* V_1012 ++ = 0 ;
return 0 ;
}
static int F_735 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1011 , * V_1012 ;
V_1012 = F_733 ( V_1010 , 6 ) ;
if ( F_191 ( V_1012 ) )
return F_241 ( V_1012 ) ;
if ( V_66 -> V_115 )
V_1011 = V_1013 ;
else
V_1011 = V_1014 ;
* V_1012 ++ = V_1015 | V_1011 ;
* V_1012 ++ = V_1016 ;
* V_1012 ++ = V_1018 | F_734 ( V_66 -> V_115 ) ;
* V_1012 ++ = V_74 -> V_244 [ 0 ] ;
* V_1012 ++ = V_66 -> V_436 -> V_1006 ;
* V_1012 ++ = V_1016 ;
return 0 ;
}
static int F_736 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1019 , V_1020 , * V_1012 ;
V_1012 = F_733 ( V_1010 , 4 ) ;
if ( F_191 ( V_1012 ) )
return F_241 ( V_1012 ) ;
* V_1012 ++ = V_1017 | F_734 ( V_66 -> V_115 ) ;
* V_1012 ++ = V_74 -> V_244 [ 0 ] ;
* V_1012 ++ = V_66 -> V_436 -> V_1006 |
F_212 ( V_74 -> V_213 ) ;
V_1019 = 0 ;
V_1020 = F_17 ( F_330 ( V_66 -> V_79 ) ) & 0x0fff0fff ;
* V_1012 ++ = V_1019 | V_1020 ;
return 0 ;
}
static int F_737 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 V_1019 , V_1020 , * V_1012 ;
V_1012 = F_733 ( V_1010 , 4 ) ;
if ( F_191 ( V_1012 ) )
return F_241 ( V_1012 ) ;
* V_1012 ++ = V_1017 | F_734 ( V_66 -> V_115 ) ;
* V_1012 ++ = V_74 -> V_244 [ 0 ] | F_212 ( V_74 -> V_213 ) ;
* V_1012 ++ = V_66 -> V_436 -> V_1006 ;
V_1019 = 0 ;
V_1020 = F_17 ( F_330 ( V_66 -> V_79 ) ) & 0x0fff0fff ;
* V_1012 ++ = V_1019 | V_1020 ;
return 0 ;
}
static int F_738 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
T_1 * V_1012 , V_1021 = 0 ;
int V_1022 , V_347 ;
switch ( V_66 -> V_115 ) {
case V_1023 :
V_1021 = V_1024 ;
break;
case V_366 :
V_1021 = V_1025 ;
break;
case V_1026 :
V_1021 = V_1027 ;
break;
default:
F_358 ( 1 , L_159 ) ;
return - V_976 ;
}
V_1022 = 4 ;
if ( V_1010 -> V_1028 -> V_262 == V_1029 ) {
V_1022 += 6 ;
if ( F_739 ( V_6 ) )
V_1022 += 2 ;
}
V_347 = F_740 ( V_1010 ) ;
if ( V_347 )
return V_347 ;
V_1012 = F_733 ( V_1010 , V_1022 ) ;
if ( F_191 ( V_1012 ) )
return F_241 ( V_1012 ) ;
if ( V_1010 -> V_1028 -> V_262 == V_1029 ) {
* V_1012 ++ = F_741 ( 1 ) ;
* V_1012 ++ = F_116 ( V_1030 ) ;
* V_1012 ++ = ~ ( V_1031 |
V_1032 |
V_1033 ) ;
if ( F_739 ( V_6 ) )
* V_1012 ++ = V_1034 |
V_1035 ;
else
* V_1012 ++ = V_1036 | V_1035 ;
* V_1012 ++ = F_116 ( V_1030 ) ;
* V_1012 ++ = F_742 ( V_1010 -> V_1028 -> V_1037 ) + 256 ;
if ( F_739 ( V_6 ) ) {
* V_1012 ++ = 0 ;
* V_1012 ++ = V_1016 ;
}
}
* V_1012 ++ = V_1018 | V_1021 ;
* V_1012 ++ = V_74 -> V_244 [ 0 ] | F_212 ( V_74 -> V_213 ) ;
* V_1012 ++ = V_66 -> V_436 -> V_1006 ;
* V_1012 ++ = V_1016 ;
return 0 ;
}
static bool F_743 ( struct V_1038 * V_1028 ,
struct V_235 * V_236 )
{
if ( V_1028 == NULL )
return true ;
if ( F_53 ( V_1028 -> V_241 ) < 5 )
return false ;
if ( V_241 . F_743 < 0 )
return false ;
else if ( V_241 . F_743 > 0 )
return true ;
else if ( V_241 . V_1039 )
return true ;
return V_1028 != F_744 ( V_236 ) ;
}
static void F_745 ( struct V_66 * V_66 ,
unsigned int V_228 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_210 * V_74 = V_66 -> V_49 . V_73 -> V_74 ;
const enum V_79 V_79 = V_66 -> V_79 ;
T_1 V_357 , V_276 = F_281 ( V_74 , 0 , V_228 ) ;
V_357 = F_17 ( F_90 ( V_79 , 0 ) ) ;
V_357 &= ~ V_863 ;
switch ( V_74 -> V_213 ) {
case V_214 :
break;
case V_215 :
V_357 |= V_384 ;
break;
case V_216 :
V_357 |= V_385 ;
break;
case V_217 :
V_357 |= V_386 ;
break;
default:
F_168 ( V_74 -> V_213 ) ;
}
F_121 ( F_90 ( V_79 , 0 ) , V_357 ) ;
F_121 ( F_290 ( V_79 , 0 ) , V_276 ) ;
F_121 ( F_295 ( V_79 , 0 ) , V_2 -> V_1006 ) ;
F_122 ( F_295 ( V_79 , 0 ) ) ;
}
static void F_746 ( struct V_66 * V_66 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_66 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_210 * V_74 = V_66 -> V_49 . V_73 -> V_74 ;
T_3 V_13 = F_84 ( V_66 -> V_115 ) ;
T_1 V_348 ;
V_348 = F_17 ( V_13 ) ;
if ( V_74 -> V_213 == V_215 )
V_348 |= V_352 ;
else
V_348 &= ~ V_352 ;
F_121 ( V_13 , V_348 ) ;
F_121 ( F_267 ( V_66 -> V_115 ) , V_2 -> V_1006 ) ;
F_122 ( F_267 ( V_66 -> V_115 ) ) ;
}
static void F_747 ( struct V_999 * V_341 )
{
struct V_1 * V_2 =
F_715 ( V_341 , struct V_1 , V_3 ) ;
struct V_66 * V_50 = F_42 ( V_2 -> V_50 ) ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_248 * V_249 =
F_177 ( V_50 -> V_49 . V_73 -> V_74 ) ;
struct V_235 * V_236 = V_249 -> V_236 ;
F_21 ( F_748 ( V_236 , 0 , V_1040 , NULL ) < 0 ) ;
F_749 ( V_50 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_745 ( V_50 , V_2 -> V_228 , V_2 ) ;
else
F_746 ( V_50 , V_2 ) ;
F_750 ( V_50 , V_2 ) ;
}
static int F_751 ( struct V_47 * V_48 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_235 * V_236 ,
struct V_1009 * V_1010 ,
T_2 V_315 )
{
return - V_976 ;
}
static bool F_752 ( struct V_5 * V_6 ,
struct V_66 * V_66 ,
struct V_1 * V_2 )
{
T_1 V_1041 , V_1042 ;
if ( ! F_348 ( & V_2 -> V_434 ) )
return false ;
F_727 () ;
V_1042 = F_725 ( V_66 ) ;
if ( V_2 -> V_1043 == 0 ) {
if ( V_2 -> V_1002 &&
! F_753 ( V_2 -> V_1002 ) )
return false ;
V_2 -> V_1043 = V_1042 ;
}
if ( V_1042 - V_2 -> V_1043 < 3 )
return false ;
if ( F_53 ( V_6 ) >= 4 )
V_1041 = F_754 ( F_17 ( F_267 ( V_66 -> V_115 ) ) ) ;
else
V_1041 = F_17 ( F_271 ( V_66 -> V_115 ) ) ;
return V_1041 == V_2 -> V_1006 ;
}
void F_755 ( struct V_5 * V_6 , int V_79 )
{
struct V_47 * V_48 = & V_6 -> V_242 ;
struct V_66 * V_50 = F_47 ( V_6 , V_79 ) ;
struct V_1 * V_2 ;
F_21 ( ! F_756 () ) ;
if ( V_50 == NULL )
return;
F_757 ( & V_48 -> V_435 ) ;
V_2 = V_50 -> V_436 ;
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_752 ( V_6 , V_50 , V_2 ) ) {
F_358 ( 1 ,
L_160 ,
V_2 -> V_1008 , F_725 ( V_50 ) ) ;
F_350 ( V_50 ) ;
V_2 = NULL ;
}
if ( V_2 != NULL && ! F_1 ( V_2 ) &&
F_725 ( V_50 ) - V_2 -> V_1008 > 1 )
F_758 ( V_2 -> V_1002 ) ;
F_759 ( & V_48 -> V_435 ) ;
}
T_5
static int F_760 ( struct V_127 * V_50 ,
struct V_210 * V_74 ,
struct V_1044 * V_473 ,
T_2 V_1045 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_210 * V_1003 = V_50 -> V_73 -> V_74 ;
struct V_235 * V_236 = F_186 ( V_74 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_318 * V_73 = V_50 -> V_73 ;
enum V_79 V_79 = V_66 -> V_79 ;
struct V_1 * V_2 ;
struct V_1038 * V_1028 ;
bool V_1046 ;
struct V_1009 * V_1047 ;
struct V_234 * V_237 ;
int V_347 ;
if ( F_21 ( F_186 ( V_1003 ) == NULL ) )
return - V_1048 ;
if ( V_74 -> V_212 != V_50 -> V_73 -> V_74 -> V_212 )
return - V_272 ;
if ( F_53 ( V_6 ) > 3 &&
( V_74 -> V_265 [ 0 ] != V_50 -> V_73 -> V_74 -> V_265 [ 0 ] ||
V_74 -> V_244 [ 0 ] != V_50 -> V_73 -> V_74 -> V_244 [ 0 ] ) )
return - V_272 ;
if ( F_761 ( & V_6 -> V_432 ) )
goto V_1049;
V_2 = F_506 ( sizeof( * V_2 ) , V_622 ) ;
if ( V_2 == NULL )
return - V_623 ;
V_2 -> V_473 = V_473 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_1003 = V_1003 ;
F_762 ( & V_2 -> V_477 , F_714 ) ;
V_347 = F_98 ( V_50 ) ;
if ( V_347 )
goto V_1050;
F_320 ( & V_48 -> V_435 ) ;
if ( V_66 -> V_436 ) {
if ( F_726 ( V_66 , V_66 -> V_436 ) ) {
F_13 ( L_161 ) ;
F_350 ( V_66 ) ;
} else {
F_13 ( L_162 ) ;
F_321 ( & V_48 -> V_435 ) ;
F_99 ( V_50 ) ;
F_235 ( V_2 ) ;
return - V_1048 ;
}
}
V_66 -> V_436 = V_2 ;
F_321 ( & V_48 -> V_435 ) ;
if ( F_348 ( & V_66 -> V_472 ) >= 2 )
F_763 ( V_6 -> V_476 ) ;
F_229 ( V_2 -> V_1003 ) ;
V_50 -> V_73 -> V_74 = V_74 ;
F_227 ( V_50 -> V_73 ) ;
V_2 -> V_475 = F_764 ( V_236 ) ;
V_347 = F_765 ( V_48 ) ;
if ( V_347 )
goto V_1051;
V_66 -> V_433 = F_327 ( & V_6 -> V_432 ) ;
if ( F_766 ( & V_6 -> V_432 ) ) {
V_347 = - V_1052 ;
goto V_427;
}
F_767 ( & V_66 -> V_472 ) ;
if ( F_53 ( V_6 ) >= 5 || F_94 ( V_6 ) )
V_2 -> V_1007 = F_17 ( F_723 ( V_79 ) ) + 1 ;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
V_1028 = V_6 -> V_1028 [ V_1053 ] ;
if ( V_74 -> V_213 != V_1003 -> V_213 )
V_1028 = NULL ;
} else if ( F_253 ( V_6 ) || F_254 ( V_6 ) ) {
V_1028 = V_6 -> V_1028 [ V_1053 ] ;
} else if ( F_53 ( V_6 ) >= 7 ) {
V_1028 = F_744 ( V_236 ) ;
if ( V_1028 == NULL || V_1028 -> V_262 != V_1029 )
V_1028 = V_6 -> V_1028 [ V_1053 ] ;
} else {
V_1028 = V_6 -> V_1028 [ V_1029 ] ;
}
V_1046 = F_743 ( V_1028 , V_236 ) ;
V_237 = F_185 ( V_74 , V_73 -> V_28 -> V_228 ) ;
if ( F_191 ( V_237 ) ) {
V_347 = F_241 ( V_237 ) ;
goto V_1054;
}
V_2 -> V_1001 = F_234 ( V_73 -> V_28 ) -> V_237 ;
F_234 ( V_73 -> V_28 ) -> V_237 = V_237 ;
V_2 -> V_1006 = F_742 ( V_237 ) + V_66 -> V_359 ;
V_2 -> V_228 = V_50 -> V_73 -> V_28 -> V_228 ;
F_424 ( V_66 , V_66 -> V_75 ,
F_234 ( V_73 -> V_28 ) ) ;
if ( V_1046 ) {
F_762 ( & V_2 -> V_3 , F_747 ) ;
F_354 ( V_1055 , & V_2 -> V_3 ) ;
} else {
V_1047 = F_768 ( V_1028 ,
V_6 -> V_1056 ) ;
if ( F_191 ( V_1047 ) ) {
V_347 = F_241 ( V_1047 ) ;
goto V_1057;
}
V_347 = F_769 ( V_1047 , V_236 , false ) ;
if ( V_347 )
goto V_1058;
V_347 = V_6 -> V_429 . V_1059 ( V_48 , V_50 , V_74 , V_236 , V_1047 ,
V_1045 ) ;
if ( V_347 )
goto V_1058;
F_729 ( V_66 , V_2 ) ;
V_2 -> V_1002 = F_770 ( V_1047 ) ;
F_771 ( V_1047 ) ;
}
F_772 ( V_236 , 0 , V_1060 ) ;
F_773 ( F_186 ( V_1003 ) , V_236 ,
F_210 ( V_73 ) -> V_339 ) ;
F_5 ( & V_48 -> V_239 ) ;
F_774 ( F_35 ( V_48 ) ,
F_210 ( V_73 ) -> V_339 ) ;
F_775 ( V_66 -> V_115 , V_236 ) ;
return 0 ;
V_1058:
F_771 ( V_1047 ) ;
V_1057:
F_234 ( V_73 -> V_28 ) -> V_237 = V_2 -> V_1001 ;
F_197 ( V_237 ) ;
V_1054:
F_719 ( & V_66 -> V_472 ) ;
V_427:
F_5 ( & V_48 -> V_239 ) ;
V_1051:
V_50 -> V_73 -> V_74 = V_1003 ;
F_227 ( V_50 -> V_73 ) ;
F_226 ( V_236 ) ;
F_228 ( V_2 -> V_1003 ) ;
F_320 ( & V_48 -> V_435 ) ;
V_66 -> V_436 = NULL ;
F_321 ( & V_48 -> V_435 ) ;
F_99 ( V_50 ) ;
V_1050:
F_235 ( V_2 ) ;
if ( V_347 == - V_1052 ) {
struct V_415 * V_28 ;
struct V_324 * V_319 ;
V_1049:
V_28 = F_492 ( V_48 ) ;
if ( ! V_28 )
return - V_623 ;
V_28 -> V_426 = V_48 -> V_423 . V_426 ;
V_457:
V_319 = F_693 ( V_28 , V_73 ) ;
V_347 = F_500 ( V_319 ) ;
if ( ! V_347 ) {
F_696 ( V_319 , V_74 ) ;
V_347 = F_695 ( V_319 , V_50 ) ;
if ( ! V_347 )
V_347 = F_705 ( V_28 ) ;
}
if ( V_347 == - V_420 ) {
F_311 ( V_28 -> V_426 ) ;
F_776 ( V_28 ) ;
goto V_457;
}
F_314 ( V_28 ) ;
if ( V_347 == 0 && V_473 ) {
F_320 ( & V_48 -> V_435 ) ;
F_351 ( V_50 , V_473 ) ;
F_321 ( & V_48 -> V_435 ) ;
}
}
return V_347 ;
}
static bool F_777 ( struct V_318 * V_115 ,
struct V_324 * V_28 )
{
struct V_247 * V_1061 = F_234 ( V_28 ) ;
struct V_247 * V_1062 = F_234 ( V_115 -> V_28 ) ;
if ( V_1061 -> V_49 . V_320 != V_1062 -> V_49 . V_320 )
return true ;
if ( ! V_1062 -> V_49 . V_74 || ! V_1061 -> V_49 . V_74 )
return false ;
if ( V_1062 -> V_49 . V_74 -> V_213 != V_1061 -> V_49 . V_74 -> V_213 ||
V_1062 -> V_49 . V_228 != V_1061 -> V_49 . V_228 ||
F_247 ( & V_1061 -> V_49 . V_336 ) != F_247 ( & V_1062 -> V_49 . V_336 ) ||
F_248 ( & V_1061 -> V_49 . V_336 ) != F_248 ( & V_1062 -> V_49 . V_336 ) ||
F_247 ( & V_1061 -> V_49 . V_337 ) != F_247 ( & V_1062 -> V_49 . V_337 ) ||
F_248 ( & V_1061 -> V_49 . V_337 ) != F_248 ( & V_1062 -> V_49 . V_337 ) )
return true ;
return false ;
}
static bool F_778 ( struct V_247 * V_28 )
{
int V_330 = F_247 ( & V_28 -> V_49 . V_336 ) >> 16 ;
int V_331 = F_248 ( & V_28 -> V_49 . V_336 ) >> 16 ;
int V_407 = F_247 ( & V_28 -> V_49 . V_337 ) ;
int V_408 = F_248 ( & V_28 -> V_49 . V_337 ) ;
return ( V_330 != V_407 || V_331 != V_408 ) ;
}
int F_779 ( struct V_27 * V_45 ,
struct V_324 * V_319 )
{
struct V_22 * V_23 = F_238 ( V_45 ) ;
struct V_127 * V_50 = V_45 -> V_50 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_261 * V_115 = F_210 ( V_319 -> V_115 ) ;
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_247 * V_1063 =
F_234 ( V_115 -> V_49 . V_28 ) ;
bool V_418 = F_18 ( V_45 ) ;
bool V_1064 = V_50 -> V_28 -> V_72 ;
bool V_1065 = V_45 -> V_72 ;
bool V_1066 , V_1067 , V_320 , V_1068 ;
struct V_210 * V_74 = V_319 -> V_74 ;
int V_347 ;
if ( F_53 ( V_6 ) >= 9 && V_115 -> V_262 != V_263 ) {
V_347 = F_400 (
F_238 ( V_45 ) ,
F_234 ( V_319 ) ) ;
if ( V_347 )
return V_347 ;
}
V_1068 = V_1063 -> V_49 . V_320 ;
V_320 = V_319 -> V_320 ;
if ( ! V_1064 && F_21 ( V_1068 ) )
V_1068 = false ;
if ( ! V_1065 ) {
V_319 -> V_320 = V_320 = false ;
F_238 ( V_45 ) -> V_322 &= ~ F_231 ( V_115 -> V_262 ) ;
}
if ( ! V_1068 && ! V_320 )
return 0 ;
if ( V_74 != V_1063 -> V_49 . V_74 )
V_23 -> V_1069 = true ;
V_1066 = V_1068 && ( ! V_320 || V_418 ) ;
V_1067 = V_320 && ( ! V_1068 || V_418 ) ;
F_780 ( L_163 ,
V_66 -> V_49 . V_49 . V_262 , V_66 -> V_49 . V_12 ,
V_115 -> V_49 . V_49 . V_262 , V_115 -> V_49 . V_12 ,
V_74 ? V_74 -> V_49 . V_262 : - 1 ) ;
F_780 ( L_164 ,
V_115 -> V_49 . V_49 . V_262 , V_115 -> V_49 . V_12 ,
V_1068 , V_320 ,
V_1066 , V_1067 , V_418 ) ;
if ( V_1067 ) {
if ( F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) )
V_23 -> V_564 = true ;
if ( V_115 -> V_262 != V_263 )
V_23 -> V_561 = true ;
} else if ( V_1066 ) {
if ( F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) )
V_23 -> V_555 = true ;
if ( V_115 -> V_262 != V_263 )
V_23 -> V_561 = true ;
} else if ( F_777 ( & V_115 -> V_49 , V_319 ) ) {
if ( F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) ) {
V_23 -> V_564 = true ;
V_23 -> V_555 = true ;
}
}
if ( V_320 || V_1068 )
V_23 -> V_554 |= V_115 -> V_339 ;
if ( V_115 -> V_262 == V_123 && F_253 ( V_6 ) &&
F_778 ( F_234 ( V_319 ) ) &&
! F_778 ( V_1063 ) )
V_23 -> V_562 = true ;
return 0 ;
}
static bool F_781 ( const struct V_506 * V_1004 ,
const struct V_506 * V_1005 )
{
return V_1004 == V_1005 || ( V_1004 -> V_1070 & ( 1 << V_1005 -> type ) &&
V_1005 -> V_1070 & ( 1 << V_1004 -> type ) ) ;
}
static bool F_782 ( struct V_415 * V_28 ,
struct V_66 * V_50 ,
struct V_506 * V_507 )
{
struct V_506 * V_1071 ;
struct V_567 * V_619 ;
struct V_565 * V_972 ;
int V_117 ;
F_430 (state, connector, connector_state, i) {
if ( V_972 -> V_50 != & V_50 -> V_49 )
continue;
V_1071 =
F_431 ( V_972 -> V_569 ) ;
if ( ! F_781 ( V_507 , V_1071 ) )
return false ;
}
return true ;
}
static int F_783 ( struct V_127 * V_50 ,
struct V_27 * V_45 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 =
F_238 ( V_45 ) ;
struct V_415 * V_28 = V_45 -> V_28 ;
int V_347 ;
bool V_418 = F_18 ( V_45 ) ;
if ( V_418 && ! V_45 -> V_72 )
V_23 -> V_555 = true ;
if ( V_418 && V_45 -> V_502 &&
V_6 -> V_429 . V_1072 &&
! F_21 ( V_23 -> V_188 ) ) {
V_347 = V_6 -> V_429 . V_1072 ( V_66 ,
V_23 ) ;
if ( V_347 )
return V_347 ;
}
if ( V_45 -> V_1073 ) {
V_347 = F_784 ( V_50 , V_45 ) ;
if ( V_347 )
return V_347 ;
V_45 -> V_1074 = true ;
}
V_347 = 0 ;
if ( V_6 -> V_429 . V_1075 ) {
V_347 = V_6 -> V_429 . V_1075 ( V_23 ) ;
if ( V_347 ) {
F_157 ( L_165 ) ;
return V_347 ;
}
}
if ( V_6 -> V_429 . V_1076 &&
! F_303 ( V_28 ) -> V_419 ) {
if ( F_21 ( ! V_6 -> V_429 . V_1075 ) )
return 0 ;
V_347 = V_6 -> V_429 . V_1076 ( V_48 ,
V_66 ,
V_23 ) ;
if ( V_347 ) {
F_157 ( L_166 ) ;
return V_347 ;
}
} else if ( V_6 -> V_429 . V_1076 ) {
if ( F_70 ( V_6 ) && F_53 ( V_6 ) < 9 )
V_23 -> V_1077 . V_1078 . V_1079 = V_23 -> V_1077 . V_1078 . V_1080 ;
}
if ( F_53 ( V_6 ) >= 9 ) {
if ( V_418 )
V_347 = F_399 ( V_23 ) ;
if ( ! V_347 )
V_347 = F_785 ( V_66 ,
V_23 ) ;
if ( ! V_347 )
V_347 = F_786 ( V_6 , V_66 ,
V_23 ) ;
}
return V_347 ;
}
static void F_787 ( struct V_47 * V_48 )
{
struct V_618 * V_619 ;
struct V_1081 V_1082 ;
F_788 ( V_48 , & V_1082 ) ;
F_789 (connector, &conn_iter) {
if ( V_619 -> V_49 . V_28 -> V_50 )
F_790 ( & V_619 -> V_49 ) ;
if ( V_619 -> V_49 . V_507 ) {
V_619 -> V_49 . V_28 -> V_569 =
V_619 -> V_49 . V_507 ;
V_619 -> V_49 . V_28 -> V_50 =
V_619 -> V_49 . V_507 -> V_50 ;
F_791 ( & V_619 -> V_49 ) ;
} else {
V_619 -> V_49 . V_28 -> V_569 = NULL ;
V_619 -> V_49 . V_28 -> V_50 = NULL ;
}
}
F_792 ( & V_1082 ) ;
}
static void
F_793 ( struct V_618 * V_619 ,
struct V_22 * V_23 )
{
const struct V_1083 * V_1084 = & V_619 -> V_49 . V_1085 ;
int V_848 = V_23 -> V_631 ;
F_157 ( L_167 ,
V_619 -> V_49 . V_49 . V_262 ,
V_619 -> V_49 . V_12 ) ;
if ( V_1084 -> V_516 != 0 && V_1084 -> V_516 * 3 < V_848 ) {
F_157 ( L_168 ,
V_848 , V_1084 -> V_516 * 3 ) ;
V_23 -> V_631 = V_1084 -> V_516 * 3 ;
}
if ( V_1084 -> V_516 == 0 && V_848 > 24 ) {
F_157 ( L_169 ,
V_848 ) ;
V_23 -> V_631 = 24 ;
}
}
static int
F_794 ( struct V_66 * V_50 ,
struct V_22 * V_23 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
struct V_415 * V_28 ;
struct V_567 * V_619 ;
struct V_565 * V_972 ;
int V_848 , V_117 ;
if ( ( F_94 ( V_6 ) || F_11 ( V_6 ) ||
F_12 ( V_6 ) ) )
V_848 = 10 * 3 ;
else if ( F_53 ( V_6 ) >= 5 )
V_848 = 12 * 3 ;
else
V_848 = 8 * 3 ;
V_23 -> V_631 = V_848 ;
V_28 = V_23 -> V_49 . V_28 ;
F_430 (state, connector, connector_state, i) {
if ( V_972 -> V_50 != & V_50 -> V_49 )
continue;
F_793 ( F_504 ( V_619 ) ,
V_23 ) ;
}
return V_848 ;
}
static void F_795 ( const struct V_515 * V_414 )
{
F_157 ( L_170
L_171 ,
V_414 -> V_77 ,
V_414 -> V_538 , V_414 -> V_644 ,
V_414 -> V_747 , V_414 -> V_744 ,
V_414 -> V_539 , V_414 -> V_749 ,
V_414 -> V_750 , V_414 -> V_740 , V_414 -> type , V_414 -> V_315 ) ;
}
static inline void
F_796 ( struct V_22 * V_23 , char * V_262 ,
unsigned int V_1086 , struct V_655 * V_656 )
{
F_157 ( L_172 ,
V_262 , V_1086 ,
V_656 -> V_658 , V_656 -> V_659 ,
V_656 -> V_660 , V_656 -> V_661 , V_656 -> V_657 ) ;
}
static void F_797 ( struct V_66 * V_50 ,
struct V_22 * V_23 ,
const char * V_1087 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_318 * V_115 ;
struct V_261 * V_261 ;
struct V_247 * V_28 ;
struct V_210 * V_74 ;
F_157 ( L_173 ,
V_50 -> V_49 . V_49 . V_262 , V_50 -> V_49 . V_12 , V_1087 ) ;
F_157 ( L_174 ,
F_798 ( V_23 -> V_80 ) ,
V_23 -> V_631 , V_23 -> V_763 ) ;
if ( V_23 -> V_204 )
F_796 ( V_23 , L_175 ,
V_23 -> V_452 ,
& V_23 -> V_577 ) ;
if ( F_395 ( V_23 ) ) {
F_796 ( V_23 , L_176 ,
V_23 -> V_1086 , & V_23 -> V_676 ) ;
if ( V_23 -> V_674 )
F_796 ( V_23 , L_177 ,
V_23 -> V_1086 ,
& V_23 -> V_677 ) ;
}
F_157 ( L_178 ,
V_23 -> V_602 , V_23 -> V_1088 ) ;
F_157 ( L_179 ) ;
F_799 ( & V_23 -> V_49 . V_414 ) ;
F_157 ( L_180 ) ;
F_799 ( & V_23 -> V_49 . V_76 ) ;
F_795 ( & V_23 -> V_49 . V_76 ) ;
F_157 ( L_181 ,
V_23 -> V_24 ,
V_23 -> V_365 , V_23 -> V_364 ,
V_23 -> V_634 ) ;
if ( F_53 ( V_6 ) >= 9 )
F_157 ( L_182 ,
V_50 -> V_369 ,
V_23 -> V_368 . V_528 ,
V_23 -> V_368 . V_404 ) ;
if ( F_159 ( V_6 ) )
F_157 ( L_183 ,
V_23 -> V_585 . V_586 ,
V_23 -> V_585 . V_590 ,
V_23 -> V_585 . V_1089 ) ;
else
F_157 ( L_184 ,
V_23 -> V_438 . V_542 ,
V_23 -> V_438 . V_224 ,
F_800 ( V_23 -> V_438 . V_128 ) ) ;
F_157 ( L_185 ,
V_23 -> V_545 , V_23 -> V_208 ) ;
F_801 ( V_6 , & V_23 -> V_156 ) ;
F_157 ( L_186 ) ;
F_802 (plane, &dev->mode_config.plane_list, head) {
struct V_1090 V_1091 ;
V_261 = F_210 ( V_115 ) ;
if ( V_261 -> V_79 != V_50 -> V_79 )
continue;
V_28 = F_234 ( V_115 -> V_28 ) ;
V_74 = V_28 -> V_49 . V_74 ;
if ( ! V_74 ) {
F_157 ( L_187 ,
V_115 -> V_49 . V_262 , V_115 -> V_12 , V_28 -> V_404 ) ;
continue;
}
F_157 ( L_188 ,
V_115 -> V_49 . V_262 , V_115 -> V_12 ,
V_74 -> V_49 . V_262 , V_74 -> V_225 , V_74 -> V_221 ,
F_803 ( V_74 -> V_212 -> V_212 , & V_1091 ) ) ;
if ( F_53 ( V_6 ) >= 9 )
F_157 ( L_189 ,
V_28 -> V_404 ,
V_28 -> V_49 . V_336 . V_277 >> 16 ,
V_28 -> V_49 . V_336 . y1 >> 16 ,
F_247 ( & V_28 -> V_49 . V_336 ) >> 16 ,
F_248 ( & V_28 -> V_49 . V_336 ) >> 16 ,
V_28 -> V_49 . V_337 . V_277 , V_28 -> V_49 . V_337 . y1 ,
F_247 ( & V_28 -> V_49 . V_337 ) ,
F_248 ( & V_28 -> V_49 . V_337 ) ) ;
}
}
static bool F_804 ( struct V_415 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_567 * V_619 ;
struct V_1081 V_1082 ;
unsigned int V_1092 = 0 ;
unsigned int V_1093 = 0 ;
F_788 ( V_48 , & V_1082 ) ;
F_805 (connector, &conn_iter) {
struct V_565 * V_972 ;
struct V_506 * V_507 ;
V_972 = F_806 ( V_28 , V_619 ) ;
if ( ! V_972 )
V_972 = V_619 -> V_28 ;
if ( ! V_972 -> V_569 )
continue;
V_507 = F_431 ( V_972 -> V_569 ) ;
F_21 ( ! V_972 -> V_50 ) ;
switch ( V_507 -> type ) {
unsigned int V_178 ;
case V_1094 :
if ( F_21 ( ! F_15 ( F_35 ( V_48 ) ) ) )
break;
case V_508 :
case V_191 :
case V_509 :
V_178 = 1 << F_387 ( & V_507 -> V_49 ) -> V_160 ;
if ( V_1092 & V_178 )
return false ;
V_1092 |= V_178 ;
break;
case V_581 :
V_1093 |=
1 << F_807 ( & V_507 -> V_49 ) -> V_73 -> V_160 ;
break;
default:
break;
}
}
F_792 ( & V_1082 ) ;
if ( V_1092 & V_1093 )
return false ;
return true ;
}
static void
F_808 ( struct V_22 * V_45 )
{
struct V_5 * V_6 =
F_35 ( V_45 -> V_49 . V_50 -> V_48 ) ;
struct V_367 V_368 ;
struct V_1095 V_156 ;
struct V_866 * V_188 ;
struct V_1096 V_1097 ;
bool V_601 ;
V_368 = V_45 -> V_368 ;
V_188 = V_45 -> V_188 ;
V_156 = V_45 -> V_156 ;
V_601 = V_45 -> V_438 . V_601 ;
if ( F_94 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1097 = V_45 -> V_1077 ;
F_809 ( F_810 ( struct V_22 , V_49 ) ) ;
memset ( & V_45 -> V_49 + 1 , 0 ,
sizeof( * V_45 ) - sizeof( V_45 -> V_49 ) ) ;
V_45 -> V_368 = V_368 ;
V_45 -> V_188 = V_188 ;
V_45 -> V_156 = V_156 ;
V_45 -> V_438 . V_601 = V_601 ;
if ( F_94 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
V_45 -> V_1077 = V_1097 ;
}
static int
F_811 ( struct V_127 * V_50 ,
struct V_22 * V_23 )
{
struct V_415 * V_28 = V_23 -> V_49 . V_28 ;
struct V_506 * V_507 ;
struct V_567 * V_619 ;
struct V_565 * V_972 ;
int V_1098 , V_347 = - V_272 ;
int V_117 ;
bool V_457 = true ;
F_808 ( V_23 ) ;
V_23 -> V_80 =
(enum V_78 ) F_42 ( V_50 ) -> V_79 ;
if ( ! ( V_23 -> V_49 . V_76 . V_315 &
( V_520 | V_1099 ) ) )
V_23 -> V_49 . V_76 . V_315 |= V_1099 ;
if ( ! ( V_23 -> V_49 . V_76 . V_315 &
( V_522 | V_1100 ) ) )
V_23 -> V_49 . V_76 . V_315 |= V_1100 ;
V_1098 = F_794 ( F_42 ( V_50 ) ,
V_23 ) ;
if ( V_1098 < 0 )
goto V_974;
F_694 ( & V_23 -> V_49 . V_414 ,
& V_23 -> V_365 ,
& V_23 -> V_364 ) ;
F_430 (state, connector, connector_state, i) {
if ( V_972 -> V_50 != V_50 )
continue;
V_507 = F_431 ( V_972 -> V_569 ) ;
if ( ! F_782 ( V_28 , F_42 ( V_50 ) , V_507 ) ) {
F_157 ( L_190 ) ;
goto V_974;
}
V_23 -> V_1101 |= 1 << V_507 -> type ;
}
V_1102:
V_23 -> V_24 = 0 ;
V_23 -> V_580 = 1 ;
F_812 ( & V_23 -> V_49 . V_76 ,
V_1103 ) ;
F_430 (state, connector, connector_state, i) {
if ( V_972 -> V_50 != V_50 )
continue;
V_507 = F_431 ( V_972 -> V_569 ) ;
if ( ! ( V_507 -> V_1104 ( V_507 , V_23 , V_972 ) ) ) {
F_157 ( L_191 ) ;
goto V_974;
}
}
if ( ! V_23 -> V_24 )
V_23 -> V_24 = V_23 -> V_49 . V_76 . V_77
* V_23 -> V_580 ;
V_347 = F_521 ( F_42 ( V_50 ) , V_23 ) ;
if ( V_347 < 0 ) {
F_157 ( L_192 ) ;
goto V_974;
}
if ( V_347 == V_633 ) {
if ( F_7 ( ! V_457 , L_193 ) ) {
V_347 = - V_272 ;
goto V_974;
}
F_157 ( L_194 ) ;
V_457 = false ;
goto V_1102;
}
V_23 -> V_763 = ( V_23 -> V_631 == 6 * 3 ) &&
! V_23 -> V_1105 ;
F_157 ( L_195 ,
V_1098 , V_23 -> V_631 , V_23 -> V_763 ) ;
V_974:
return V_347 ;
}
static void
F_813 ( struct V_415 * V_28 )
{
struct V_127 * V_50 ;
struct V_27 * V_1106 ;
int V_117 ;
F_302 (state, crtc, new_crtc_state, i) {
F_42 ( V_50 ) -> V_75 = F_238 ( V_1106 ) ;
if ( F_419 ( V_28 , V_50 -> V_73 ) ) {
struct V_324 * V_319 = V_50 -> V_73 -> V_28 ;
V_50 -> V_73 -> V_74 = V_319 -> V_74 ;
V_50 -> V_245 = V_319 -> V_328 >> 16 ;
V_50 -> V_246 = V_319 -> V_329 >> 16 ;
}
}
}
static bool F_814 ( int V_1107 , int V_1108 )
{
int V_1109 ;
if ( V_1107 == V_1108 )
return true ;
if ( ! V_1107 || ! V_1108 )
return false ;
V_1109 = abs ( V_1107 - V_1108 ) ;
if ( ( ( ( ( V_1109 + V_1107 + V_1108 ) * 100 ) ) / ( V_1107 + V_1108 ) ) < 105 )
return true ;
return false ;
}
static bool
F_815 ( unsigned int V_31 , unsigned int V_36 ,
unsigned int V_32 , unsigned int V_1110 ,
bool V_1111 )
{
if ( V_31 == V_32 && V_36 == V_1110 )
return true ;
if ( V_1111 || ! V_31 || ! V_36 || ! V_32 || ! V_1110 )
return false ;
F_809 ( V_647 > V_69 ) ;
if ( V_36 > V_1110 ) {
while ( V_36 > V_1110 ) {
V_32 <<= 1 ;
V_1110 <<= 1 ;
}
} else if ( V_36 < V_1110 ) {
while ( V_36 < V_1110 ) {
V_31 <<= 1 ;
V_36 <<= 1 ;
}
}
if ( V_36 != V_1110 )
return false ;
return F_814 ( V_31 , V_32 ) ;
}
static bool
F_816 ( const struct V_655 * V_656 ,
struct V_655 * V_673 ,
bool V_1112 )
{
if ( V_656 -> V_657 == V_673 -> V_657 &&
F_815 ( V_656 -> V_658 , V_656 -> V_659 ,
V_673 -> V_658 , V_673 -> V_659 , ! V_1112 ) &&
F_815 ( V_656 -> V_660 , V_656 -> V_661 ,
V_673 -> V_660 , V_673 -> V_661 , ! V_1112 ) ) {
if ( V_1112 )
* V_673 = * V_656 ;
return true ;
}
return false ;
}
static bool
F_817 ( struct V_5 * V_6 ,
struct V_22 * V_1113 ,
struct V_22 * V_23 ,
bool V_1112 )
{
bool V_347 = true ;
#define F_818 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_819 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_820 ( V_12 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_821 ( V_12 ) \
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
#define F_822 ( V_12 , T_6 ) \
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
#define F_823 ( V_12 , V_600 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
pipe_config_err(adjust, __stringify(name), \
"(%x) (expected %i, found %i)\n", \
(mask), \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_824 ( V_12 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_825 ( T_7 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_819 ( V_80 ) ;
F_819 ( V_204 ) ;
F_819 ( V_452 ) ;
F_821 ( V_577 ) ;
F_819 ( V_1086 ) ;
F_818 ( V_1114 ) ;
if ( F_53 ( V_6 ) < 8 ) {
F_821 ( V_676 ) ;
if ( V_1113 -> V_674 )
F_821 ( V_677 ) ;
} else
F_822 ( V_676 , V_677 ) ;
F_818 ( V_1101 ) ;
F_819 ( V_49 . V_76 . V_538 ) ;
F_819 ( V_49 . V_76 . V_744 ) ;
F_819 ( V_49 . V_76 . V_745 ) ;
F_819 ( V_49 . V_76 . V_746 ) ;
F_819 ( V_49 . V_76 . V_644 ) ;
F_819 ( V_49 . V_76 . V_747 ) ;
F_819 ( V_49 . V_76 . V_539 ) ;
F_819 ( V_49 . V_76 . V_740 ) ;
F_819 ( V_49 . V_76 . V_748 ) ;
F_819 ( V_49 . V_76 . V_741 ) ;
F_819 ( V_49 . V_76 . V_749 ) ;
F_819 ( V_49 . V_76 . V_750 ) ;
F_819 ( V_580 ) ;
F_819 ( V_1115 ) ;
if ( ( F_53 ( V_6 ) < 8 && ! F_254 ( V_6 ) ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
F_819 ( V_772 ) ;
F_819 ( V_1116 ) ;
F_819 ( V_1117 ) ;
F_819 ( V_1088 ) ;
F_819 ( V_602 ) ;
F_823 ( V_49 . V_76 . V_315 ,
V_743 ) ;
if ( ! F_825 ( V_1118 ) ) {
F_823 ( V_49 . V_76 . V_315 ,
V_520 ) ;
F_823 ( V_49 . V_76 . V_315 ,
V_1099 ) ;
F_823 ( V_49 . V_76 . V_315 ,
V_522 ) ;
F_823 ( V_49 . V_76 . V_315 ,
V_1100 ) ;
}
F_818 ( V_585 . V_586 ) ;
if ( F_53 ( V_6 ) < 4 )
F_818 ( V_585 . V_590 ) ;
F_818 ( V_585 . V_1089 ) ;
if ( ! V_1112 ) {
F_819 ( V_365 ) ;
F_819 ( V_364 ) ;
F_819 ( V_438 . V_128 ) ;
if ( V_1113 -> V_438 . V_128 ) {
F_818 ( V_438 . V_542 ) ;
F_818 ( V_438 . V_224 ) ;
}
F_819 ( V_368 . V_404 ) ;
F_824 ( V_634 ) ;
}
if ( F_254 ( V_6 ) )
F_819 ( V_545 ) ;
F_819 ( V_208 ) ;
F_820 ( V_188 ) ;
F_818 ( V_156 . V_30 ) ;
F_818 ( V_156 . V_158 ) ;
F_818 ( V_156 . V_611 ) ;
F_818 ( V_156 . V_612 ) ;
F_818 ( V_156 . V_1119 ) ;
F_818 ( V_156 . V_1120 ) ;
F_818 ( V_156 . V_1121 ) ;
F_818 ( V_156 . V_1122 ) ;
F_818 ( V_156 . V_1123 ) ;
F_818 ( V_1124 . V_1125 ) ;
F_818 ( V_1124 . div ) ;
if ( F_94 ( V_6 ) || F_53 ( V_6 ) >= 5 )
F_819 ( V_631 ) ;
F_824 ( V_49 . V_76 . V_77 ) ;
F_824 ( V_24 ) ;
#undef F_818
#undef F_819
#undef F_820
#undef F_823
#undef F_824
#undef F_825
return V_347 ;
}
static void F_826 ( struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
if ( V_23 -> V_204 ) {
int V_629 = F_709 ( F_14 ( V_6 , V_23 ) ,
& V_23 -> V_577 ) ;
int V_1126 = V_23 -> V_49 . V_76 . V_77 ;
F_7 ( ! F_814 ( V_629 , V_1126 ) ,
L_196 ,
V_629 , V_1126 ) ;
}
}
static void F_827 ( struct V_127 * V_50 ,
struct V_27 * V_1127 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
struct V_1128 V_1129 , * V_1130 ;
struct V_1131 V_1132 , * V_1133 ;
struct V_1134 * V_1135 , * V_1136 ;
struct V_1137 * V_1138 , * V_1139 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
const enum V_79 V_79 = V_66 -> V_79 ;
int V_115 , V_1140 , V_1141 = F_828 ( V_6 ) ;
if ( F_53 ( V_6 ) < 9 || ! V_1127 -> V_72 )
return;
F_829 ( V_50 , & V_1132 ) ;
V_1133 = & F_238 ( V_1127 ) -> V_1077 . V_1142 . V_1080 ;
F_830 ( V_6 , & V_1129 ) ;
V_1130 = & V_6 -> V_1077 . V_1143 . V_1144 ;
F_831 (dev_priv, pipe, plane) {
V_1135 = & V_1132 . V_1145 [ V_115 ] ;
V_1136 = & V_1133 -> V_1145 [ V_115 ] ;
for ( V_1140 = 0 ; V_1140 <= V_1141 ; V_1140 ++ ) {
if ( F_832 ( & V_1135 -> V_1077 [ V_1140 ] ,
& V_1136 -> V_1077 [ V_1140 ] ) )
continue;
F_124 ( L_197 ,
F_73 ( V_79 ) , V_115 + 1 , V_1140 ,
V_1136 -> V_1077 [ V_1140 ] . V_1146 ,
V_1136 -> V_1077 [ V_1140 ] . V_1147 ,
V_1136 -> V_1077 [ V_1140 ] . V_1148 ,
V_1135 -> V_1077 [ V_1140 ] . V_1146 ,
V_1135 -> V_1077 [ V_1140 ] . V_1147 ,
V_1135 -> V_1077 [ V_1140 ] . V_1148 ) ;
}
if ( ! F_832 ( & V_1135 -> V_1149 ,
& V_1136 -> V_1149 ) ) {
F_124 ( L_198 ,
F_73 ( V_79 ) , V_115 + 1 ,
V_1136 -> V_1149 . V_1146 ,
V_1136 -> V_1149 . V_1147 ,
V_1136 -> V_1149 . V_1148 ,
V_1135 -> V_1149 . V_1146 ,
V_1135 -> V_1149 . V_1147 ,
V_1135 -> V_1149 . V_1148 ) ;
}
V_1138 = & V_1129 . V_115 [ V_79 ] [ V_115 ] ;
V_1139 = & V_1130 -> V_115 [ V_79 ] [ V_115 ] ;
if ( ! F_833 ( V_1138 , V_1139 ) ) {
F_124 ( L_199 ,
F_73 ( V_79 ) , V_115 + 1 ,
V_1139 -> V_1150 , V_1139 -> V_1151 ,
V_1138 -> V_1150 , V_1138 -> V_1151 ) ;
}
}
if ( 1 ) {
V_1135 = & V_1132 . V_1145 [ V_263 ] ;
V_1136 = & V_1133 -> V_1145 [ V_263 ] ;
for ( V_1140 = 0 ; V_1140 <= V_1141 ; V_1140 ++ ) {
if ( F_832 ( & V_1135 -> V_1077 [ V_1140 ] ,
& V_1136 -> V_1077 [ V_1140 ] ) )
continue;
F_124 ( L_200 ,
F_73 ( V_79 ) , V_1140 ,
V_1136 -> V_1077 [ V_1140 ] . V_1146 ,
V_1136 -> V_1077 [ V_1140 ] . V_1147 ,
V_1136 -> V_1077 [ V_1140 ] . V_1148 ,
V_1135 -> V_1077 [ V_1140 ] . V_1146 ,
V_1135 -> V_1077 [ V_1140 ] . V_1147 ,
V_1135 -> V_1077 [ V_1140 ] . V_1148 ) ;
}
if ( ! F_832 ( & V_1135 -> V_1149 ,
& V_1136 -> V_1149 ) ) {
F_124 ( L_201 ,
F_73 ( V_79 ) ,
V_1136 -> V_1149 . V_1146 ,
V_1136 -> V_1149 . V_1147 ,
V_1136 -> V_1149 . V_1148 ,
V_1135 -> V_1149 . V_1146 ,
V_1135 -> V_1149 . V_1147 ,
V_1135 -> V_1149 . V_1148 ) ;
}
V_1138 = & V_1129 . V_115 [ V_79 ] [ V_263 ] ;
V_1139 = & V_1130 -> V_115 [ V_79 ] [ V_263 ] ;
if ( ! F_833 ( V_1138 , V_1139 ) ) {
F_124 ( L_202 ,
F_73 ( V_79 ) ,
V_1139 -> V_1150 , V_1139 -> V_1151 ,
V_1138 -> V_1150 , V_1138 -> V_1151 ) ;
}
}
}
static void
F_834 ( struct V_47 * V_48 ,
struct V_415 * V_28 ,
struct V_127 * V_50 )
{
struct V_567 * V_619 ;
struct V_565 * V_1152 ;
int V_117 ;
F_430 (state, connector, new_conn_state, i) {
struct V_599 * V_507 = V_619 -> V_507 ;
struct V_27 * V_45 = NULL ;
if ( V_1152 -> V_50 != V_50 )
continue;
if ( V_50 )
V_45 = F_835 ( V_28 , V_1152 -> V_50 ) ;
F_503 ( V_45 , V_1152 ) ;
F_59 ( V_1152 -> V_569 != V_507 ,
L_203 ) ;
}
}
static void
F_836 ( struct V_47 * V_48 , struct V_415 * V_28 )
{
struct V_506 * V_507 ;
struct V_567 * V_619 ;
struct V_565 * V_572 , * V_1152 ;
int V_117 ;
F_593 (dev, encoder) {
bool V_128 = false , V_60 = false ;
enum V_79 V_79 ;
F_157 ( L_204 ,
V_507 -> V_49 . V_49 . V_262 ,
V_507 -> V_49 . V_12 ) ;
F_837 (state, connector, old_conn_state,
new_conn_state, i) {
if ( V_572 -> V_569 == & V_507 -> V_49 )
V_60 = true ;
if ( V_1152 -> V_569 != & V_507 -> V_49 )
continue;
V_60 = V_128 = true ;
F_59 ( V_1152 -> V_50 !=
V_507 -> V_49 . V_50 ,
L_205 ) ;
}
if ( ! V_60 )
continue;
F_59 ( ! ! V_507 -> V_49 . V_50 != V_128 ,
L_206
L_207 ,
! ! V_507 -> V_49 . V_50 , V_128 ) ;
if ( ! V_507 -> V_49 . V_50 ) {
bool V_72 ;
V_72 = V_507 -> V_620 ( V_507 , & V_79 ) ;
F_59 ( V_72 ,
L_208 ,
F_73 ( V_79 ) ) ;
}
}
}
static void
F_838 ( struct V_127 * V_50 ,
struct V_27 * V_437 ,
struct V_27 * V_1106 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_506 * V_507 ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 , * V_1153 ;
struct V_415 * V_552 ;
bool V_72 ;
V_552 = V_437 -> V_28 ;
F_839 ( V_437 ) ;
V_23 = F_238 ( V_437 ) ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_49 . V_50 = V_50 ;
V_23 -> V_49 . V_28 = V_552 ;
F_157 ( L_209 , V_50 -> V_49 . V_262 , V_50 -> V_12 ) ;
V_72 = V_6 -> V_429 . V_1154 ( V_66 , V_23 ) ;
if ( F_79 ( V_6 ) )
V_72 = V_1106 -> V_72 ;
F_59 ( V_1106 -> V_72 != V_72 ,
L_210
L_207 , V_1106 -> V_72 , V_72 ) ;
F_59 ( V_66 -> V_72 != V_1106 -> V_72 ,
L_211
L_207 , V_1106 -> V_72 , V_66 -> V_72 ) ;
F_386 (dev, crtc, encoder) {
enum V_79 V_79 ;
V_72 = V_507 -> V_620 ( V_507 , & V_79 ) ;
F_59 ( V_72 != V_1106 -> V_72 ,
L_212 ,
V_507 -> V_49 . V_49 . V_262 , V_72 , V_1106 -> V_72 ) ;
F_59 ( V_72 && V_66 -> V_79 != V_79 ,
L_213 ,
F_73 ( V_79 ) ) ;
if ( V_72 ) {
V_23 -> V_1101 |= 1 << V_507 -> type ;
V_507 -> V_1155 ( V_507 , V_23 ) ;
}
}
F_520 ( V_23 ) ;
if ( ! V_1106 -> V_72 )
return;
F_826 ( V_6 , V_23 ) ;
V_1153 = F_238 ( V_1106 ) ;
if ( ! F_817 ( V_6 , V_1153 ,
V_23 , false ) ) {
F_59 ( 1 , L_214 ) ;
F_797 ( V_66 , V_23 ,
L_215 ) ;
F_797 ( V_66 , V_1153 ,
L_216 ) ;
}
}
static void
F_840 ( struct V_5 * V_6 ,
struct V_866 * V_867 ,
struct V_127 * V_50 ,
struct V_27 * V_1127 )
{
struct V_1095 V_156 ;
unsigned V_1156 ;
bool V_72 ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
F_157 ( L_217 , V_867 -> V_12 ) ;
V_72 = V_867 -> V_872 . V_620 ( V_6 , V_867 , & V_156 ) ;
if ( ! ( V_867 -> V_315 & V_1157 ) ) {
F_59 ( ! V_867 -> V_1158 && V_867 -> V_1159 ,
L_218 ) ;
F_59 ( V_867 -> V_1158 && ! V_867 -> V_1159 ,
L_219 ) ;
F_59 ( V_867 -> V_1158 != V_72 ,
L_220 ,
V_867 -> V_1158 , V_72 ) ;
}
if ( ! V_50 ) {
F_59 ( V_867 -> V_1159 & ~ V_867 -> V_28 . V_1156 ,
L_221 ,
V_867 -> V_1159 , V_867 -> V_28 . V_1156 ) ;
return;
}
V_1156 = 1 << F_841 ( V_50 ) ;
if ( V_1127 -> V_72 )
F_59 ( ! ( V_867 -> V_1159 & V_1156 ) ,
L_222 ,
F_73 ( F_841 ( V_50 ) ) , V_867 -> V_1159 ) ;
else
F_59 ( V_867 -> V_1159 & V_1156 ,
L_223 ,
F_73 ( F_841 ( V_50 ) ) , V_867 -> V_1159 ) ;
F_59 ( ! ( V_867 -> V_28 . V_1156 & V_1156 ) ,
L_224 ,
V_1156 , V_867 -> V_28 . V_1156 ) ;
F_59 ( V_867 -> V_1158 && memcmp ( & V_867 -> V_28 . V_1160 ,
& V_156 ,
sizeof( V_156 ) ) ,
L_225 ) ;
}
static void
F_842 ( struct V_47 * V_48 , struct V_127 * V_50 ,
struct V_27 * V_437 ,
struct V_27 * V_1106 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_22 * V_552 = F_238 ( V_437 ) ;
struct V_22 * V_1127 = F_238 ( V_1106 ) ;
if ( V_1127 -> V_188 )
F_840 ( V_6 , V_1127 -> V_188 , V_50 , V_1106 ) ;
if ( V_552 -> V_188 &&
V_552 -> V_188 != V_1127 -> V_188 ) {
unsigned V_1156 = 1 << F_841 ( V_50 ) ;
struct V_866 * V_867 = V_552 -> V_188 ;
F_59 ( V_867 -> V_1159 & V_1156 ,
L_226 ,
F_73 ( F_841 ( V_50 ) ) ) ;
F_59 ( V_867 -> V_28 . V_1156 & V_1156 ,
L_227 ,
F_73 ( F_841 ( V_50 ) ) ) ;
}
}
static void
F_843 ( struct V_127 * V_50 ,
struct V_415 * V_28 ,
struct V_27 * V_552 ,
struct V_27 * V_1127 )
{
if ( ! F_18 ( V_1127 ) &&
! F_238 ( V_1127 ) -> V_1161 )
return;
F_827 ( V_50 , V_1127 ) ;
F_834 ( V_50 -> V_48 , V_28 , V_50 ) ;
F_838 ( V_50 , V_552 , V_1127 ) ;
F_842 ( V_50 -> V_48 , V_50 , V_552 , V_1127 ) ;
}
static void
F_844 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_6 -> V_810 ; V_117 ++ )
F_840 ( V_6 , & V_6 -> V_1162 [ V_117 ] , NULL , NULL ) ;
}
static void
F_845 ( struct V_47 * V_48 ,
struct V_415 * V_28 )
{
F_836 ( V_48 , V_28 ) ;
F_834 ( V_48 , V_28 , NULL ) ;
F_844 ( V_48 ) ;
}
static void F_846 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
if ( F_50 ( V_6 ) ) {
const struct V_515 * V_76 = & V_50 -> V_75 -> V_49 . V_76 ;
int V_756 ;
V_756 = V_76 -> V_740 ;
if ( V_76 -> V_315 & V_743 )
V_756 /= 2 ;
V_50 -> V_207 = V_756 - 1 ;
} else if ( F_15 ( V_6 ) &&
F_32 ( V_50 -> V_75 , V_191 ) ) {
V_50 -> V_207 = 2 ;
} else
V_50 -> V_207 = 1 ;
}
static void F_847 ( struct V_415 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_127 * V_50 ;
struct V_27 * V_437 , * V_1106 ;
int V_117 ;
if ( ! V_6 -> V_429 . V_1072 )
return;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_866 * V_1163 =
F_238 ( V_437 ) -> V_188 ;
if ( ! F_18 ( V_1106 ) )
continue;
F_238 ( V_1106 ) -> V_188 = NULL ;
if ( ! V_1163 )
continue;
F_849 ( V_1163 , V_66 , V_28 ) ;
}
}
static int F_850 ( struct V_415 * V_28 )
{
struct V_27 * V_45 ;
struct V_66 * V_66 ;
struct V_127 * V_50 ;
struct V_22 * V_1164 = NULL ;
struct V_22 * V_625 = NULL ;
enum V_79 V_1165 = V_582 , V_1166 = V_582 ;
int V_117 ;
F_302 (state, crtc, crtc_state, i) {
V_66 = F_42 ( V_50 ) ;
if ( ! V_45 -> V_72 || ! F_18 ( V_45 ) )
continue;
if ( V_1164 ) {
V_625 = F_238 ( V_45 ) ;
break;
} else {
V_1164 = F_238 ( V_45 ) ;
V_1165 = V_66 -> V_79 ;
}
}
if ( ! V_1164 )
return 0 ;
F_135 (state->dev, intel_crtc) {
struct V_22 * V_23 ;
V_23 = F_493 ( V_28 , V_66 ) ;
if ( F_191 ( V_23 ) )
return F_241 ( V_23 ) ;
V_23 -> V_578 = V_582 ;
if ( ! V_23 -> V_49 . V_72 ||
F_18 ( & V_23 -> V_49 ) )
continue;
if ( V_1166 != V_582 )
return 0 ;
V_1166 = V_66 -> V_79 ;
}
if ( V_1166 != V_582 )
V_1164 -> V_578 = V_1166 ;
else if ( V_625 )
V_625 -> V_578 = V_1165 ;
return 0 ;
}
static int F_851 ( struct V_415 * V_28 )
{
struct V_127 * V_50 ;
F_236 (state->dev, crtc) {
struct V_27 * V_45 ;
V_45 = F_704 ( V_28 , V_50 ) ;
if ( F_191 ( V_45 ) )
return F_241 ( V_45 ) ;
}
return 0 ;
}
static int F_852 ( struct V_415 * V_28 )
{
struct V_127 * V_50 ;
F_236 (state->dev, crtc) {
struct V_27 * V_45 ;
int V_347 ;
V_45 = F_704 ( V_28 , V_50 ) ;
if ( F_191 ( V_45 ) )
return F_241 ( V_45 ) ;
if ( ! V_45 -> V_72 || F_18 ( V_45 ) )
continue;
V_45 -> V_418 = true ;
V_347 = F_494 ( V_28 , V_50 ) ;
if ( V_347 )
return V_347 ;
V_347 = F_853 ( V_28 , V_50 ) ;
if ( V_347 )
return V_347 ;
}
return 0 ;
}
static int F_854 ( struct V_415 * V_28 )
{
struct V_559 * V_325 = F_303 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_28 -> V_48 ) ;
struct V_127 * V_50 ;
struct V_27 * V_437 , * V_1106 ;
int V_347 = 0 , V_117 ;
if ( ! F_804 ( V_28 ) ) {
F_157 ( L_228 ) ;
return - V_272 ;
}
V_325 -> V_558 = true ;
V_325 -> V_616 = V_6 -> V_616 ;
V_325 -> V_1167 . V_1168 = V_6 -> V_1167 . V_1168 ;
V_325 -> V_1167 . V_1169 = V_6 -> V_1167 . V_1169 ;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( V_1106 -> V_72 )
V_325 -> V_616 |= 1 << V_117 ;
else
V_325 -> V_616 &= ~ ( 1 << V_117 ) ;
if ( V_437 -> V_72 != V_1106 -> V_72 )
V_325 -> V_1170 |= F_855 ( V_50 ) ;
}
if ( V_6 -> V_429 . V_1171 ) {
V_347 = V_6 -> V_429 . V_1171 ( V_28 ) ;
if ( V_347 < 0 )
return V_347 ;
if ( ! F_856 ( & V_6 -> V_1167 . V_1168 ,
& V_325 -> V_1167 . V_1168 ) ) {
V_347 = F_851 ( V_28 ) ;
if ( V_347 < 0 )
return V_347 ;
}
if ( ! F_856 ( & V_6 -> V_1167 . V_1169 ,
& V_325 -> V_1167 . V_1169 ) ) {
V_347 = F_852 ( V_28 ) ;
if ( V_347 < 0 )
return V_347 ;
}
F_157 ( L_229 ,
V_325 -> V_1167 . V_1168 . V_1167 ,
V_325 -> V_1167 . V_1169 . V_1167 ) ;
} else {
F_303 ( V_28 ) -> V_1167 . V_1168 = V_6 -> V_1167 . V_1168 ;
}
F_847 ( V_28 ) ;
if ( F_254 ( V_6 ) )
return F_850 ( V_28 ) ;
return 0 ;
}
static int F_857 ( struct V_415 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
if ( V_6 -> V_429 . V_1172 )
return V_6 -> V_429 . V_1172 ( V_28 ) ;
return 0 ;
}
static int F_858 ( struct V_47 * V_48 ,
struct V_415 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_559 * V_325 = F_303 ( V_28 ) ;
struct V_127 * V_50 ;
struct V_27 * V_437 , * V_45 ;
int V_347 , V_117 ;
bool V_1173 = false ;
V_347 = F_859 ( V_48 , V_28 ) ;
if ( V_347 )
return V_347 ;
F_848 (state, crtc, old_crtc_state, crtc_state, i) {
struct V_22 * V_23 =
F_238 ( V_45 ) ;
if ( V_45 -> V_414 . V_1174 != V_437 -> V_414 . V_1174 )
V_45 -> V_418 = true ;
if ( ! F_18 ( V_45 ) )
continue;
if ( ! V_45 -> V_502 ) {
V_1173 = true ;
continue;
}
V_347 = F_494 ( V_28 , V_50 ) ;
if ( V_347 )
return V_347 ;
V_347 = F_811 ( V_50 , V_23 ) ;
if ( V_347 ) {
F_797 ( F_42 ( V_50 ) ,
V_23 , L_230 ) ;
return V_347 ;
}
if ( V_241 . V_1175 &&
F_817 ( V_6 ,
F_238 ( V_437 ) ,
V_23 , true ) ) {
V_45 -> V_418 = false ;
V_23 -> V_1161 = true ;
}
if ( F_18 ( V_45 ) )
V_1173 = true ;
V_347 = F_853 ( V_28 , V_50 ) ;
if ( V_347 )
return V_347 ;
F_797 ( F_42 ( V_50 ) , V_23 ,
F_18 ( V_45 ) ?
L_231 : L_232 ) ;
}
if ( V_1173 ) {
V_347 = F_854 ( V_28 ) ;
if ( V_347 )
return V_347 ;
} else {
V_325 -> V_1167 . V_1168 = V_6 -> V_1167 . V_1168 ;
}
V_347 = F_860 ( V_48 , V_28 ) ;
if ( V_347 )
return V_347 ;
F_861 ( V_6 , V_28 ) ;
return F_857 ( V_28 ) ;
}
static int F_862 ( struct V_47 * V_48 ,
struct V_415 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_27 * V_45 ;
struct V_127 * V_50 ;
int V_117 , V_347 ;
F_302 (state, crtc, crtc_state, i) {
if ( V_28 -> V_1176 )
continue;
V_347 = F_355 ( V_50 ) ;
if ( V_347 )
return V_347 ;
if ( F_348 ( & F_42 ( V_50 ) -> V_472 ) >= 2 )
F_763 ( V_6 -> V_476 ) ;
}
V_347 = F_863 ( & V_48 -> V_239 ) ;
if ( V_347 )
return V_347 ;
V_347 = F_864 ( V_48 , V_28 ) ;
F_5 ( & V_48 -> V_239 ) ;
return V_347 ;
}
T_1 F_725 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
if ( ! V_48 -> V_206 )
return F_865 ( & V_50 -> V_49 ) ;
return V_48 -> V_1177 -> V_1178 ( V_48 , V_50 -> V_79 ) ;
}
static void F_866 ( struct V_47 * V_48 ,
struct V_5 * V_6 ,
unsigned V_1156 )
{
unsigned V_1179 [ V_1180 ] ;
enum V_79 V_79 ;
int V_347 ;
if ( ! V_1156 )
return;
F_87 (dev_priv, pipe) {
struct V_66 * V_50 = F_47 ( V_6 ,
V_79 ) ;
if ( ! ( ( 1 << V_79 ) & V_1156 ) )
continue;
V_347 = F_98 ( & V_50 -> V_49 ) ;
if ( F_21 ( V_347 != 0 ) ) {
V_1156 &= ~ ( 1 << V_79 ) ;
continue;
}
V_1179 [ V_79 ] = F_867 ( & V_50 -> V_49 ) ;
}
F_87 (dev_priv, pipe) {
struct V_66 * V_50 = F_47 ( V_6 ,
V_79 ) ;
long V_1181 ;
if ( ! ( ( 1 << V_79 ) & V_1156 ) )
continue;
V_1181 = F_868 ( V_48 -> V_1042 [ V_79 ] . V_1182 ,
V_1179 [ V_79 ] !=
F_867 ( & V_50 -> V_49 ) ,
F_869 ( 50 ) ) ;
F_7 ( ! V_1181 , L_233 , F_73 ( V_79 ) ) ;
F_99 ( & V_50 -> V_49 ) ;
}
}
static bool F_870 ( struct V_22 * V_45 )
{
if ( V_45 -> V_1069 )
return true ;
if ( V_45 -> V_555 )
return true ;
if ( V_45 -> V_1077 . V_1183 )
return true ;
return false ;
}
static void F_871 ( struct V_127 * V_50 ,
struct V_415 * V_28 ,
struct V_27 * V_437 ,
struct V_27 * V_1106 ,
unsigned int * V_1184 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_23 = F_238 ( V_1106 ) ;
bool V_558 = F_18 ( V_1106 ) ;
if ( V_558 ) {
F_846 ( V_66 ) ;
V_6 -> V_429 . V_1185 ( V_23 , V_28 ) ;
} else {
F_423 ( F_238 ( V_437 ) ,
V_23 ) ;
}
if ( F_419 ( V_28 , V_50 -> V_73 ) ) {
F_872 (
V_66 , V_23 ,
F_234 ( V_50 -> V_73 -> V_28 ) ) ;
}
F_873 ( V_437 ) ;
if ( F_870 ( V_23 ) )
* V_1184 |= F_855 ( V_50 ) ;
}
static void F_874 ( struct V_415 * V_28 ,
unsigned int * V_1184 )
{
struct V_127 * V_50 ;
struct V_27 * V_437 , * V_1106 ;
int V_117 ;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_1106 -> V_72 )
continue;
F_871 ( V_50 , V_28 , V_437 ,
V_1106 , V_1184 ) ;
}
}
static void F_875 ( struct V_415 * V_28 ,
unsigned int * V_1184 )
{
struct V_5 * V_6 = F_35 ( V_28 -> V_48 ) ;
struct V_559 * V_325 = F_303 ( V_28 ) ;
struct V_127 * V_50 ;
struct V_66 * V_66 ;
struct V_27 * V_437 , * V_1106 ;
struct V_22 * V_1186 ;
unsigned int V_1187 = 0 ;
bool V_1188 ;
enum V_79 V_79 ;
int V_117 ;
const struct V_1137 * V_1189 [ V_1180 ] = {} ;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i)
if ( V_1106 -> V_72 )
V_1189 [ V_117 ] = & F_238 ( V_437 ) -> V_1077 . V_1142 . V_1144 ;
do {
V_1188 = false ;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
bool V_1190 = false ;
unsigned int V_1191 = F_855 ( V_50 ) ;
V_66 = F_42 ( V_50 ) ;
V_1186 = F_238 ( V_50 -> V_28 ) ;
V_79 = V_66 -> V_79 ;
if ( V_1187 & V_1191 || ! V_1186 -> V_49 . V_72 )
continue;
if ( F_876 ( V_1189 , & V_1186 -> V_1077 . V_1142 . V_1144 , V_117 ) )
continue;
V_1187 |= V_1191 ;
V_1189 [ V_117 ] = & V_1186 -> V_1077 . V_1142 . V_1144 ;
if ( ! F_833 ( & V_1186 -> V_1077 . V_1142 . V_1144 ,
& F_238 ( V_437 ) -> V_1077 . V_1142 . V_1144 ) &&
! V_1106 -> V_1192 &&
V_325 -> V_1193 . V_1194 != V_1187 )
V_1190 = true ;
F_871 ( V_50 , V_28 , V_437 ,
V_1106 , V_1184 ) ;
if ( V_1190 )
F_349 ( V_6 , V_79 ) ;
V_1188 = true ;
}
} while ( V_1188 );
}
static void F_877 ( struct V_5 * V_6 )
{
struct V_559 * V_28 , * V_1195 ;
struct V_1196 * V_1197 ;
V_1197 = F_878 ( & V_6 -> V_1198 . V_1199 ) ;
F_879 (state, next, freed, freed)
F_314 ( & V_28 -> V_49 ) ;
}
static void F_880 ( struct V_999 * V_2 )
{
struct V_5 * V_6 =
F_715 ( V_2 , F_881 ( * V_6 ) , V_1198 . V_1050 ) ;
F_877 ( V_6 ) ;
}
static void F_882 ( struct V_415 * V_28 )
{
struct V_47 * V_48 = V_28 -> V_48 ;
struct V_559 * V_325 = F_303 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_27 * V_437 , * V_1106 ;
struct V_127 * V_50 ;
struct V_22 * V_1200 ;
bool V_1201 = V_325 -> V_558 ;
T_4 V_1202 [ V_1180 ] = {} ;
unsigned V_1184 = 0 ;
int V_117 ;
F_883 ( V_28 ) ;
if ( V_325 -> V_558 )
F_476 ( V_6 , V_1203 ) ;
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_66 * V_66 = F_42 ( V_50 ) ;
if ( F_18 ( V_1106 ) ||
F_238 ( V_1106 ) -> V_1161 ) {
V_1201 = true ;
V_1202 [ F_42 ( V_50 ) -> V_79 ] =
F_474 ( V_50 ,
F_238 ( V_1106 ) ) ;
}
if ( ! F_18 ( V_1106 ) )
continue;
F_423 ( F_238 ( V_437 ) ,
F_238 ( V_1106 ) ) ;
if ( V_437 -> V_72 ) {
F_426 ( V_50 , V_437 -> V_321 ) ;
V_6 -> V_429 . V_613 ( F_238 ( V_437 ) , V_28 ) ;
V_66 -> V_72 = false ;
F_496 ( V_66 ) ;
F_497 ( V_66 ) ;
F_414 ( V_6 ) ;
F_415 ( V_6 ) ;
if ( ! V_50 -> V_28 -> V_72 ) {
if ( F_53 ( V_6 ) >= 9 )
V_6 -> V_429 . V_563 ( V_325 ,
F_238 ( V_50 -> V_28 ) ) ;
}
}
}
F_813 ( V_28 ) ;
if ( V_325 -> V_558 ) {
F_884 ( V_28 -> V_48 , V_28 ) ;
F_885 ( V_6 , & V_6 -> V_1167 . V_1169 ) ;
if ( ! F_886 ( V_28 ) )
F_887 ( V_6 ) ;
F_845 ( V_48 , V_28 ) ;
}
F_302 (state, crtc, new_crtc_state, i) {
bool V_558 = F_18 ( V_1106 ) ;
if ( V_558 && ! V_1106 -> V_72 && V_1106 -> V_473 ) {
F_320 ( & V_48 -> V_435 ) ;
F_351 ( V_50 , V_1106 -> V_473 ) ;
F_321 ( & V_48 -> V_435 ) ;
V_1106 -> V_473 = NULL ;
}
}
V_6 -> V_429 . V_1204 ( V_28 , & V_1184 ) ;
if ( ! V_28 -> V_1176 )
F_866 ( V_48 , V_6 , V_1184 ) ;
F_302 (state, crtc, new_crtc_state, i) {
V_1200 = F_238 ( V_1106 ) ;
if ( V_6 -> V_429 . V_1205 )
V_6 -> V_429 . V_1205 ( V_325 ,
V_1200 ) ;
}
F_848 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_418 ( F_238 ( V_437 ) ) ;
if ( V_1202 [ V_117 ] )
F_477 ( V_6 , V_1202 [ V_117 ] ) ;
F_843 ( V_50 , V_28 , V_437 , V_1106 ) ;
}
if ( V_325 -> V_558 && F_886 ( V_28 ) )
F_888 ( V_6 ) ;
F_889 ( V_28 ) ;
if ( V_325 -> V_558 ) {
F_890 ( V_6 ) ;
F_82 ( V_6 , V_1203 ) ;
}
F_3 ( & V_48 -> V_239 ) ;
F_891 ( V_48 , V_28 ) ;
F_5 ( & V_48 -> V_239 ) ;
F_892 ( V_28 ) ;
F_314 ( V_28 ) ;
F_877 ( V_6 ) ;
}
static void F_893 ( struct V_999 * V_2 )
{
struct V_415 * V_28 =
F_715 ( V_2 , struct V_415 , V_1206 ) ;
F_882 ( V_28 ) ;
}
static int T_8
F_894 ( struct V_1207 * V_1208 ,
enum V_1209 V_1210 )
{
struct V_559 * V_28 =
F_715 ( V_1208 , struct V_559 , V_1211 ) ;
switch ( V_1210 ) {
case V_1212 :
if ( V_28 -> V_49 . V_1206 . V_4 )
F_354 ( V_1055 , & V_28 -> V_49 . V_1206 ) ;
break;
case V_1213 :
{
struct V_1214 * V_1215 =
& F_35 ( V_28 -> V_49 . V_48 ) -> V_1198 ;
if ( F_895 ( & V_28 -> V_1197 , & V_1215 -> V_1199 ) )
F_896 ( & V_1215 -> V_1050 ) ;
break;
}
}
return V_1216 ;
}
static void F_897 ( struct V_415 * V_28 )
{
struct V_324 * V_1063 , * V_1217 ;
struct V_318 * V_115 ;
int V_117 ;
F_898 (state, plane, old_plane_state, new_plane_state, i)
F_773 ( F_186 ( V_1063 -> V_74 ) ,
F_186 ( V_1217 -> V_74 ) ,
F_210 ( V_115 ) -> V_339 ) ;
}
static int F_899 ( struct V_47 * V_48 ,
struct V_415 * V_28 ,
bool V_1218 )
{
struct V_559 * V_325 = F_303 ( V_28 ) ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
int V_347 = 0 ;
V_347 = F_900 ( V_28 , V_1218 ) ;
if ( V_347 )
return V_347 ;
F_901 ( V_28 ) ;
F_902 ( & V_325 -> V_1211 ,
F_894 ) ;
V_347 = F_862 ( V_48 , V_28 ) ;
if ( V_347 ) {
F_780 ( L_234 , V_347 ) ;
F_903 ( & V_325 -> V_1211 ) ;
return V_347 ;
}
if ( F_53 ( V_6 ) < 9 )
V_28 -> V_1176 = false ;
F_904 ( V_28 , true ) ;
V_6 -> V_1077 . V_1219 = false ;
F_905 ( V_28 ) ;
F_897 ( V_28 ) ;
if ( V_325 -> V_558 ) {
memcpy ( V_6 -> V_617 , V_325 -> V_617 ,
sizeof( V_325 -> V_617 ) ) ;
V_6 -> V_616 = V_325 -> V_616 ;
V_6 -> V_1167 . V_1168 = V_325 -> V_1167 . V_1168 ;
V_6 -> V_1167 . V_1169 = V_325 -> V_1167 . V_1169 ;
}
F_901 ( V_28 ) ;
F_762 ( & V_28 -> V_1206 ,
V_1218 ? F_893 : NULL ) ;
F_903 ( & V_325 -> V_1211 ) ;
if ( ! V_1218 ) {
F_906 ( & V_325 -> V_1211 ) ;
F_882 ( V_28 ) ;
}
return 0 ;
}
int
F_907 ( struct V_318 * V_115 ,
struct V_324 * V_1127 )
{
struct V_559 * V_325 =
F_303 ( V_1127 -> V_28 ) ;
struct V_5 * V_6 = F_35 ( V_115 -> V_48 ) ;
struct V_210 * V_74 = V_1127 -> V_74 ;
struct V_235 * V_236 = F_186 ( V_74 ) ;
struct V_235 * V_1220 = F_186 ( V_115 -> V_28 -> V_74 ) ;
int V_347 ;
if ( V_236 ) {
if ( V_115 -> type == V_1221 &&
F_181 ( V_6 ) -> V_942 ) {
const int V_1222 = F_178 ( V_6 ) ;
V_347 = F_908 ( V_236 , V_1222 ) ;
if ( V_347 ) {
F_157 ( L_235 ) ;
return V_347 ;
}
} else {
struct V_234 * V_237 ;
V_237 = F_185 ( V_74 , V_1127 -> V_228 ) ;
if ( F_191 ( V_237 ) ) {
F_157 ( L_236 ) ;
return F_241 ( V_237 ) ;
}
F_234 ( V_1127 ) -> V_237 = V_237 ;
}
}
if ( ! V_236 && ! V_1220 )
return 0 ;
if ( V_1220 ) {
struct V_27 * V_45 =
F_909 ( V_1127 -> V_28 ,
V_115 -> V_28 -> V_50 ) ;
if ( F_18 ( V_45 ) ) {
V_347 = F_910 ( & V_325 -> V_1211 ,
V_1220 -> V_1223 , NULL ,
false , 0 ,
V_622 ) ;
if ( V_347 < 0 )
return V_347 ;
}
}
if ( V_1127 -> V_1208 ) {
V_347 = F_911 ( & V_325 -> V_1211 ,
V_1127 -> V_1208 ,
V_1224 ,
V_622 ) ;
if ( V_347 < 0 )
return V_347 ;
}
if ( ! V_236 )
return 0 ;
if ( ! V_1127 -> V_1208 ) {
V_347 = F_910 ( & V_325 -> V_1211 ,
V_236 -> V_1223 , NULL ,
false , V_1224 ,
V_622 ) ;
if ( V_347 < 0 )
return V_347 ;
F_772 ( V_236 , 0 , V_1060 ) ;
}
return 0 ;
}
void
F_912 ( struct V_318 * V_115 ,
struct V_324 * V_552 )
{
struct V_234 * V_237 ;
V_237 = F_913 ( & F_234 ( V_552 ) -> V_237 ) ;
if ( V_237 )
F_197 ( V_237 ) ;
}
int
F_914 ( struct V_66 * V_66 , struct V_22 * V_45 )
{
struct V_5 * V_6 ;
int V_1225 ;
int V_77 , V_1226 ;
if ( ! V_66 || ! V_45 -> V_49 . V_502 )
return V_952 ;
V_6 = F_35 ( V_66 -> V_49 . V_48 ) ;
V_77 = V_45 -> V_49 . V_76 . V_77 ;
V_1226 = F_303 ( V_45 -> V_49 . V_28 ) -> V_1167 . V_1168 . V_1167 ;
if ( F_286 ( V_6 ) )
V_1226 *= 2 ;
if ( F_39 ( ! V_77 || V_1226 < V_77 ) )
return V_952 ;
V_1225 = V_43 ( ( 1 << 16 ) * 3 - 1 ,
( 1 << 8 ) * ( ( V_1226 << 8 ) / V_77 ) ) ;
return V_1225 ;
}
static int
F_915 ( struct V_261 * V_115 ,
struct V_22 * V_45 ,
struct V_247 * V_28 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
struct V_127 * V_50 = V_28 -> V_49 . V_50 ;
int V_1227 = V_952 ;
int V_1225 = V_952 ;
bool V_1228 = false ;
int V_347 ;
if ( F_53 ( V_6 ) >= 9 ) {
if ( V_28 -> V_393 . V_315 == V_540 ) {
V_1227 = 1 ;
V_1225 = F_914 ( F_42 ( V_50 ) , V_45 ) ;
}
V_1228 = true ;
}
V_347 = F_662 ( & V_28 -> V_49 ,
& V_28 -> V_951 ,
V_1227 , V_1225 ,
V_1228 , true ) ;
if ( V_347 )
return V_347 ;
if ( ! V_28 -> V_49 . V_74 )
return 0 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_347 = F_250 ( V_28 ) ;
if ( V_347 )
return V_347 ;
V_28 -> V_357 = F_285 ( V_45 , V_28 ) ;
} else {
V_347 = F_257 ( V_28 ) ;
if ( V_347 )
return V_347 ;
V_28 -> V_357 = F_251 ( V_45 , V_28 ) ;
}
return 0 ;
}
static void F_916 ( struct V_127 * V_50 ,
struct V_27 * V_437 )
{
struct V_47 * V_48 = V_50 -> V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_66 * V_66 = F_42 ( V_50 ) ;
struct V_22 * V_1200 =
F_238 ( V_50 -> V_28 ) ;
struct V_22 * V_1229 =
F_238 ( V_437 ) ;
struct V_559 * V_560 =
F_303 ( V_437 -> V_28 ) ;
bool V_558 = F_18 ( V_50 -> V_28 ) ;
if ( ! V_558 &&
( V_1200 -> V_49 . V_1073 ||
V_1200 -> V_1161 ) ) {
F_456 ( V_50 -> V_28 ) ;
F_447 ( V_50 -> V_28 ) ;
}
F_749 ( V_66 ) ;
if ( V_558 )
goto V_799;
if ( V_1200 -> V_1161 )
F_329 ( V_66 , V_1229 ) ;
else if ( F_53 ( V_6 ) >= 9 )
F_280 ( V_66 ) ;
V_799:
if ( V_6 -> V_429 . V_1230 )
V_6 -> V_429 . V_1230 ( V_560 ,
V_1200 ) ;
}
static void F_917 ( struct V_127 * V_50 ,
struct V_27 * V_437 )
{
struct V_66 * V_66 = F_42 ( V_50 ) ;
F_750 ( V_66 , NULL ) ;
}
void F_918 ( struct V_318 * V_115 )
{
F_919 ( V_115 ) ;
F_235 ( F_210 ( V_115 ) ) ;
}
static int
F_920 ( struct V_318 * V_115 ,
struct V_127 * V_50 ,
struct V_210 * V_74 ,
int V_332 , int V_333 ,
unsigned int V_334 , unsigned int V_335 ,
T_2 V_328 , T_2 V_329 ,
T_2 V_330 , T_2 V_331 ,
struct V_416 * V_417 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_48 ) ;
int V_347 ;
struct V_324 * V_1063 , * V_1217 ;
struct V_261 * V_261 = F_210 ( V_115 ) ;
struct V_210 * V_1003 ;
struct V_27 * V_45 = V_50 -> V_28 ;
struct V_234 * V_1001 ;
if ( ! V_45 -> V_72 || F_18 ( V_45 ) ||
F_238 ( V_45 ) -> V_1161 )
goto V_1231;
V_1063 = V_115 -> V_28 ;
if ( V_1063 -> V_50 != V_50 ||
V_1063 -> V_330 != V_330 ||
V_1063 -> V_331 != V_331 ||
V_1063 -> V_334 != V_334 ||
V_1063 -> V_335 != V_335 ||
! V_1063 -> V_74 != ! V_74 )
goto V_1231;
V_1217 = F_921 ( V_115 ) ;
if ( ! V_1217 )
return - V_623 ;
F_696 ( V_1217 , V_74 ) ;
V_1217 -> V_328 = V_328 ;
V_1217 -> V_329 = V_329 ;
V_1217 -> V_330 = V_330 ;
V_1217 -> V_331 = V_331 ;
V_1217 -> V_332 = V_332 ;
V_1217 -> V_333 = V_333 ;
V_1217 -> V_334 = V_334 ;
V_1217 -> V_335 = V_335 ;
V_347 = F_922 ( F_238 ( V_50 -> V_28 ) ,
F_234 ( V_1217 ) ) ;
if ( V_347 )
goto V_1232;
V_347 = F_863 ( & V_6 -> V_242 . V_239 ) ;
if ( V_347 )
goto V_1232;
if ( F_181 ( V_6 ) -> V_942 ) {
int V_1222 = F_178 ( V_6 ) ;
V_347 = F_908 ( F_186 ( V_74 ) , V_1222 ) ;
if ( V_347 ) {
F_157 ( L_235 ) ;
goto V_1233;
}
} else {
struct V_234 * V_237 ;
V_237 = F_185 ( V_74 , V_1217 -> V_228 ) ;
if ( F_191 ( V_237 ) ) {
F_157 ( L_236 ) ;
V_347 = F_241 ( V_237 ) ;
goto V_1233;
}
F_234 ( V_1217 ) -> V_237 = V_237 ;
}
V_1003 = V_1063 -> V_74 ;
V_1001 = F_234 ( V_1063 ) -> V_237 ;
F_773 ( F_186 ( V_1003 ) , F_186 ( V_74 ) ,
V_261 -> V_339 ) ;
V_1217 -> V_1208 = V_1063 -> V_1208 ;
* F_234 ( V_1063 ) = * F_234 ( V_1217 ) ;
V_1217 -> V_1208 = NULL ;
V_1217 -> V_74 = V_1003 ;
F_234 ( V_1217 ) -> V_237 = V_1001 ;
if ( V_115 -> V_28 -> V_320 ) {
F_923 ( V_115 , F_42 ( V_50 ) ) ;
V_261 -> V_1234 ( V_261 ,
F_238 ( V_50 -> V_28 ) ,
F_234 ( V_115 -> V_28 ) ) ;
} else {
F_240 ( V_115 , F_42 ( V_50 ) ) ;
V_261 -> V_327 ( V_261 , F_42 ( V_50 ) ) ;
}
F_912 ( V_115 , V_1217 ) ;
V_1233:
F_5 ( & V_6 -> V_242 . V_239 ) ;
V_1232:
F_924 ( V_115 , V_1217 ) ;
return V_347 ;
V_1231:
return F_925 ( V_115 , V_50 , V_74 ,
V_332 , V_333 , V_334 , V_335 ,
V_328 , V_329 , V_330 , V_331 , V_417 ) ;
}
static struct V_261 *
F_926 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_261 * V_73 = NULL ;
struct V_247 * V_28 = NULL ;
const T_2 * V_1235 ;
unsigned int V_1236 ;
unsigned int V_1237 ;
int V_347 ;
V_73 = F_506 ( sizeof( * V_73 ) , V_622 ) ;
if ( ! V_73 ) {
V_347 = - V_623 ;
goto V_974;
}
V_28 = F_927 ( & V_73 -> V_49 ) ;
if ( ! V_28 ) {
V_347 = - V_623 ;
goto V_974;
}
V_73 -> V_49 . V_28 = & V_28 -> V_49 ;
V_73 -> V_1238 = false ;
V_73 -> V_1239 = 1 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_73 -> V_1238 = true ;
V_28 -> V_404 = - 1 ;
}
V_73 -> V_79 = V_79 ;
if ( F_928 ( V_6 ) && F_53 ( V_6 ) < 4 )
V_73 -> V_115 = (enum V_115 ) ! V_79 ;
else
V_73 -> V_115 = (enum V_115 ) V_79 ;
V_73 -> V_262 = V_1240 ;
V_73 -> V_339 = F_929 ( V_79 ) ;
V_73 -> V_1241 = F_915 ;
if ( F_53 ( V_6 ) >= 9 ) {
V_1235 = V_1242 ;
V_1237 = F_174 ( V_1242 ) ;
V_73 -> V_1234 = F_287 ;
V_73 -> V_327 = F_296 ;
} else if ( F_53 ( V_6 ) >= 4 ) {
V_1235 = V_1243 ;
V_1237 = F_174 ( V_1243 ) ;
V_73 -> V_1234 = F_258 ;
V_73 -> V_327 = F_274 ;
} else {
V_1235 = V_1244 ;
V_1237 = F_174 ( V_1244 ) ;
V_73 -> V_1234 = F_258 ;
V_73 -> V_327 = F_274 ;
}
if ( F_53 ( V_6 ) >= 9 )
V_347 = F_930 ( & V_6 -> V_242 , & V_73 -> V_49 ,
0 , & V_1245 ,
V_1235 , V_1237 ,
V_1246 ,
L_237 , F_73 ( V_79 ) ) ;
else if ( F_53 ( V_6 ) >= 5 || F_94 ( V_6 ) )
V_347 = F_930 ( & V_6 -> V_242 , & V_73 -> V_49 ,
0 , & V_1245 ,
V_1235 , V_1237 ,
V_1246 ,
L_238 , F_73 ( V_79 ) ) ;
else
V_347 = F_930 ( & V_6 -> V_242 , & V_73 -> V_49 ,
0 , & V_1245 ,
V_1235 , V_1237 ,
V_1246 ,
L_239 , F_85 ( V_73 -> V_115 ) ) ;
if ( V_347 )
goto V_974;
if ( F_53 ( V_6 ) >= 9 ) {
V_1236 =
V_273 | V_387 |
V_353 | V_280 ;
} else if ( F_12 ( V_6 ) && V_79 == V_105 ) {
V_1236 =
V_273 | V_353 |
V_355 ;
} else if ( F_53 ( V_6 ) >= 4 ) {
V_1236 =
V_273 | V_353 ;
} else {
V_1236 = V_273 ;
}
if ( F_53 ( V_6 ) >= 4 )
F_931 ( & V_73 -> V_49 ,
V_273 ,
V_1236 ) ;
F_932 ( & V_73 -> V_49 , & V_1247 ) ;
return V_73 ;
V_974:
F_235 ( V_28 ) ;
F_235 ( V_73 ) ;
return F_682 ( V_347 ) ;
}
static struct V_261 *
F_933 ( struct V_5 * V_6 ,
enum V_79 V_79 )
{
struct V_261 * V_956 = NULL ;
struct V_247 * V_28 = NULL ;
int V_347 ;
V_956 = F_506 ( sizeof( * V_956 ) , V_622 ) ;
if ( ! V_956 ) {
V_347 = - V_623 ;
goto V_974;
}
V_28 = F_927 ( & V_956 -> V_49 ) ;
if ( ! V_28 ) {
V_347 = - V_623 ;
goto V_974;
}
V_956 -> V_49 . V_28 = & V_28 -> V_49 ;
V_956 -> V_1238 = false ;
V_956 -> V_1239 = 1 ;
V_956 -> V_79 = V_79 ;
V_956 -> V_115 = V_79 ;
V_956 -> V_262 = V_263 ;
V_956 -> V_339 = F_934 ( V_79 ) ;
if ( F_75 ( V_6 ) || F_76 ( V_6 ) ) {
V_956 -> V_1234 = F_669 ;
V_956 -> V_327 = F_672 ;
V_956 -> V_1241 = F_667 ;
} else {
V_956 -> V_1234 = F_678 ;
V_956 -> V_327 = F_680 ;
V_956 -> V_1241 = F_677 ;
}
V_956 -> V_956 . V_49 = ~ 0 ;
V_956 -> V_956 . V_955 = ~ 0 ;
if ( F_75 ( V_6 ) || F_76 ( V_6 ) || F_676 ( V_6 ) )
V_956 -> V_956 . V_224 = ~ 0 ;
V_347 = F_930 ( & V_6 -> V_242 , & V_956 -> V_49 ,
0 , & V_1248 ,
V_1249 ,
F_174 ( V_1249 ) ,
V_1221 ,
L_240 , F_73 ( V_79 ) ) ;
if ( V_347 )
goto V_974;
if ( F_53 ( V_6 ) >= 4 )
F_931 ( & V_956 -> V_49 ,
V_273 ,
V_273 |
V_353 ) ;
if ( F_53 ( V_6 ) >= 9 )
V_28 -> V_404 = - 1 ;
F_932 ( & V_956 -> V_49 , & V_1247 ) ;
return V_956 ;
V_974:
F_235 ( V_28 ) ;
F_235 ( V_956 ) ;
return F_682 ( V_347 ) ;
}
static void F_656 ( struct V_66 * V_50 ,
struct V_22 * V_45 )
{
struct V_367 * V_368 =
& V_45 -> V_368 ;
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
int V_117 ;
V_50 -> V_369 = V_6 -> V_1084 . V_369 [ V_50 -> V_79 ] ;
if ( ! V_50 -> V_369 )
return;
for ( V_117 = 0 ; V_117 < V_50 -> V_369 ; V_117 ++ ) {
struct V_1250 * V_1251 = & V_368 -> V_370 [ V_117 ] ;
V_1251 -> V_371 = 0 ;
V_1251 -> V_414 = V_1252 ;
}
V_368 -> V_404 = - 1 ;
}
static int F_935 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_66 * V_66 ;
struct V_22 * V_45 = NULL ;
struct V_261 * V_73 = NULL ;
struct V_261 * V_956 = NULL ;
int V_121 , V_347 ;
V_66 = F_506 ( sizeof( * V_66 ) , V_622 ) ;
if ( ! V_66 )
return - V_623 ;
V_45 = F_506 ( sizeof( * V_45 ) , V_622 ) ;
if ( ! V_45 ) {
V_347 = - V_623 ;
goto V_974;
}
V_66 -> V_75 = V_45 ;
V_66 -> V_49 . V_28 = & V_45 -> V_49 ;
V_45 -> V_49 . V_50 = & V_66 -> V_49 ;
V_73 = F_926 ( V_6 , V_79 ) ;
if ( F_191 ( V_73 ) ) {
V_347 = F_241 ( V_73 ) ;
goto V_974;
}
V_66 -> V_1253 |= F_231 ( V_73 -> V_262 ) ;
F_89 (dev_priv, pipe, sprite) {
struct V_261 * V_115 ;
V_115 = F_936 ( V_6 , V_79 , V_121 ) ;
if ( F_191 ( V_115 ) ) {
V_347 = F_241 ( V_115 ) ;
goto V_974;
}
V_66 -> V_1253 |= F_231 ( V_115 -> V_262 ) ;
}
V_956 = F_933 ( V_6 , V_79 ) ;
if ( F_191 ( V_956 ) ) {
V_347 = F_241 ( V_956 ) ;
goto V_974;
}
V_66 -> V_1253 |= F_231 ( V_956 -> V_262 ) ;
V_347 = F_937 ( & V_6 -> V_242 , & V_66 -> V_49 ,
& V_73 -> V_49 , & V_956 -> V_49 ,
& V_1254 ,
L_241 , F_73 ( V_79 ) ) ;
if ( V_347 )
goto V_974;
V_66 -> V_79 = V_79 ;
V_66 -> V_115 = V_73 -> V_115 ;
F_656 ( V_66 , V_45 ) ;
F_595 ( V_79 >= F_174 ( V_6 -> V_1255 ) ||
V_6 -> V_1255 [ V_66 -> V_115 ] != NULL ) ;
V_6 -> V_1255 [ V_66 -> V_115 ] = V_66 ;
V_6 -> V_1256 [ V_66 -> V_79 ] = V_66 ;
F_938 ( & V_66 -> V_49 , & V_1257 ) ;
F_939 ( & V_66 -> V_49 ) ;
F_21 ( F_841 ( & V_66 -> V_49 ) != V_66 -> V_79 ) ;
return 0 ;
V_974:
F_235 ( V_45 ) ;
F_235 ( V_66 ) ;
return V_347 ;
}
enum V_79 F_940 ( struct V_618 * V_619 )
{
struct V_47 * V_48 = V_619 -> V_49 . V_48 ;
F_21 ( ! F_699 ( & V_48 -> V_423 . V_973 ) ) ;
if ( ! V_619 -> V_49 . V_28 -> V_50 )
return V_582 ;
return F_42 ( V_619 -> V_49 . V_28 -> V_50 ) -> V_79 ;
}
int F_941 ( struct V_47 * V_48 , void * V_1258 ,
struct V_1259 * V_1260 )
{
struct V_1261 * V_1262 = V_1258 ;
struct V_127 * V_1263 ;
struct V_66 * V_50 ;
V_1263 = F_942 ( V_48 , V_1262 -> V_1264 ) ;
if ( ! V_1263 )
return - V_1265 ;
V_50 = F_42 ( V_1263 ) ;
V_1262 -> V_79 = V_50 -> V_79 ;
return 0 ;
}
static int F_943 ( struct V_506 * V_507 )
{
struct V_47 * V_48 = V_507 -> V_49 . V_48 ;
struct V_506 * V_1071 ;
int V_1266 = 0 ;
int V_1267 = 0 ;
F_593 (dev, source_encoder) {
if ( F_781 ( V_507 , V_1071 ) )
V_1266 |= ( 1 << V_1267 ) ;
V_1267 ++ ;
}
return V_1266 ;
}
static bool F_944 ( struct V_5 * V_6 )
{
if ( ! F_137 ( V_6 ) )
return false ;
if ( ( F_17 ( V_1268 ) & V_1269 ) == 0 )
return false ;
if ( F_16 ( V_6 ) && ( F_17 ( V_1270 ) & V_1271 ) )
return false ;
return true ;
}
static bool F_945 ( struct V_5 * V_6 )
{
if ( F_53 ( V_6 ) >= 9 )
return false ;
if ( F_946 ( V_6 ) || F_947 ( V_6 ) )
return false ;
if ( F_12 ( V_6 ) )
return false ;
if ( F_948 ( V_6 ) &&
F_17 ( V_1272 ) & V_1273 )
return false ;
if ( F_15 ( V_6 ) && F_17 ( F_949 ( V_591 ) ) & V_1274 )
return false ;
if ( ! V_6 -> V_663 . V_1275 )
return false ;
return true ;
}
void F_318 ( struct V_5 * V_6 )
{
int V_1276 ;
int V_1277 ;
if ( F_15 ( V_6 ) )
return;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1276 = 2 ;
else
V_1276 = 1 ;
for ( V_1277 = 0 ; V_1277 < V_1276 ; V_1277 ++ ) {
T_1 V_15 = F_17 ( F_71 ( V_1277 ) ) ;
V_15 = ( V_15 & ~ V_108 ) | V_109 ;
F_121 ( F_71 ( V_1277 ) , V_15 ) ;
}
}
static void F_950 ( struct V_5 * V_6 )
{
if ( F_70 ( V_6 ) || F_30 ( V_6 ) )
V_6 -> V_1278 = V_1279 ;
else if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
V_6 -> V_1278 = V_1280 ;
else
V_6 -> V_1278 = V_1281 ;
F_318 ( V_6 ) ;
}
static void F_951 ( struct V_5 * V_6 )
{
struct V_506 * V_507 ;
bool V_1282 = false ;
F_950 ( V_6 ) ;
F_952 ( V_6 ) ;
if ( F_945 ( V_6 ) )
F_953 ( V_6 ) ;
if ( F_30 ( V_6 ) ) {
F_954 ( V_6 , V_591 ) ;
F_954 ( V_6 , V_180 ) ;
F_954 ( V_6 , V_182 ) ;
F_955 ( V_6 ) ;
} else if ( F_15 ( V_6 ) ) {
int V_60 ;
V_60 = F_17 ( F_949 ( V_591 ) ) & V_1283 ;
if ( V_60 || F_654 ( V_6 ) )
F_954 ( V_6 , V_591 ) ;
V_60 = F_17 ( V_1272 ) ;
if ( V_60 & V_1284 )
F_954 ( V_6 , V_180 ) ;
if ( V_60 & V_1285 )
F_954 ( V_6 , V_182 ) ;
if ( V_60 & V_1286 )
F_954 ( V_6 , V_184 ) ;
if ( F_654 ( V_6 ) &&
( V_6 -> V_663 . V_1287 [ V_596 ] . V_1288 ||
V_6 -> V_663 . V_1287 [ V_596 ] . V_1289 ||
V_6 -> V_663 . V_1287 [ V_596 ] . V_1290 ) )
F_954 ( V_6 , V_596 ) ;
} else if ( F_70 ( V_6 ) ) {
int V_60 ;
V_1282 = F_956 ( V_6 , V_184 ) ;
if ( F_944 ( V_6 ) )
F_957 ( V_6 , V_1268 , V_591 ) ;
if ( F_17 ( V_153 ) & V_1291 ) {
V_60 = F_958 ( V_6 , V_1292 , V_180 ) ;
if ( ! V_60 )
F_959 ( V_6 , V_153 , V_180 ) ;
if ( ! V_60 && ( F_17 ( V_146 ) & V_1269 ) )
F_957 ( V_6 , V_146 , V_180 ) ;
}
if ( F_17 ( V_154 ) & V_1291 )
F_959 ( V_6 , V_154 , V_182 ) ;
if ( ! V_1282 && F_17 ( V_155 ) & V_1291 )
F_959 ( V_6 , V_155 , V_184 ) ;
if ( F_17 ( V_148 ) & V_1269 )
F_957 ( V_6 , V_148 , V_182 ) ;
if ( F_17 ( V_150 ) & V_1269 )
F_957 ( V_6 , V_150 , V_184 ) ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
bool V_1293 , V_1294 ;
V_1293 = F_956 ( V_6 , V_180 ) ;
V_1294 = F_960 ( V_6 , V_180 ) ;
if ( F_17 ( V_1295 ) & V_1269 || V_1294 )
V_1293 &= F_957 ( V_6 , V_1295 , V_180 ) ;
if ( ( F_17 ( V_1296 ) & V_1291 || V_1294 ) && ! V_1293 )
F_959 ( V_6 , V_1296 , V_180 ) ;
V_1293 = F_956 ( V_6 , V_182 ) ;
V_1294 = F_960 ( V_6 , V_182 ) ;
if ( F_17 ( V_1297 ) & V_1269 || V_1294 )
V_1293 &= F_957 ( V_6 , V_1297 , V_182 ) ;
if ( ( F_17 ( V_1298 ) & V_1291 || V_1294 ) && ! V_1293 )
F_959 ( V_6 , V_1298 , V_182 ) ;
if ( F_12 ( V_6 ) ) {
V_1294 = F_960 ( V_6 , V_184 ) ;
if ( F_17 ( V_1299 ) & V_1269 || V_1294 )
F_957 ( V_6 , V_1299 , V_184 ) ;
if ( F_17 ( V_1300 ) & V_1291 || V_1294 )
F_959 ( V_6 , V_1300 , V_184 ) ;
}
F_955 ( V_6 ) ;
} else if ( ! F_50 ( V_6 ) && ! F_29 ( V_6 ) ) {
bool V_60 = false ;
if ( F_17 ( V_1301 ) & V_1291 ) {
F_157 ( L_242 ) ;
V_60 = F_958 ( V_6 , V_1301 , V_180 ) ;
if ( ! V_60 && F_94 ( V_6 ) ) {
F_157 ( L_243 ) ;
F_959 ( V_6 , V_1302 , V_180 ) ;
}
if ( ! V_60 && F_94 ( V_6 ) )
F_957 ( V_6 , V_1303 , V_180 ) ;
}
if ( F_17 ( V_1301 ) & V_1291 ) {
F_157 ( L_244 ) ;
V_60 = F_958 ( V_6 , V_1304 , V_182 ) ;
}
if ( ! V_60 && ( F_17 ( V_1304 ) & V_1291 ) ) {
if ( F_94 ( V_6 ) ) {
F_157 ( L_245 ) ;
F_959 ( V_6 , V_1305 , V_182 ) ;
}
if ( F_94 ( V_6 ) )
F_957 ( V_6 , V_1306 , V_182 ) ;
}
if ( F_94 ( V_6 ) && ( F_17 ( V_1307 ) & V_1269 ) )
F_957 ( V_6 , V_1307 , V_184 ) ;
} else if ( F_50 ( V_6 ) )
F_961 ( V_6 ) ;
if ( F_962 ( V_6 ) )
F_963 ( V_6 ) ;
F_964 ( V_6 ) ;
F_593 (&dev_priv->drm, encoder) {
V_507 -> V_49 . V_975 = V_507 -> V_1156 ;
V_507 -> V_49 . V_1308 =
F_943 ( V_507 ) ;
}
F_605 ( V_6 ) ;
F_965 ( & V_6 -> V_242 ) ;
}
static void F_966 ( struct V_210 * V_74 )
{
struct V_248 * V_249 = F_177 ( V_74 ) ;
F_967 ( V_74 ) ;
F_968 ( V_249 -> V_236 ) ;
F_21 ( ! V_249 -> V_236 -> V_1309 -- ) ;
F_969 ( V_249 -> V_236 ) ;
F_226 ( V_249 -> V_236 ) ;
F_235 ( V_249 ) ;
}
static int F_970 ( struct V_210 * V_74 ,
struct V_1259 * V_1260 ,
unsigned int * V_1310 )
{
struct V_248 * V_249 = F_177 ( V_74 ) ;
struct V_235 * V_236 = V_249 -> V_236 ;
if ( V_236 -> V_1311 . V_1312 ) {
F_668 ( L_246 ) ;
return - V_272 ;
}
return F_971 ( V_1260 , & V_236 -> V_49 , V_1310 ) ;
}
static int F_972 ( struct V_210 * V_74 ,
struct V_1259 * V_1260 ,
unsigned V_315 , unsigned V_1313 ,
struct V_1314 * V_1315 ,
unsigned V_1316 )
{
struct V_235 * V_236 = F_186 ( V_74 ) ;
F_973 ( V_236 ) ;
F_974 ( V_236 , V_1317 ) ;
return 0 ;
}
static
T_1 F_975 ( struct V_5 * V_6 ,
V_40 V_257 , T_2 V_314 )
{
T_1 V_232 = F_53 ( V_6 ) ;
if ( V_232 >= 9 ) {
int V_211 = F_976 ( V_314 , 0 ) ;
return V_43 ( 8192 * V_211 , 32768 ) ;
} else if ( V_232 >= 5 && ! F_159 ( V_6 ) ) {
return 32 * 1024 ;
} else if ( V_232 >= 4 ) {
if ( V_257 == V_215 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_232 >= 3 ) {
if ( V_257 == V_215 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_225 ( struct V_248 * V_249 ,
struct V_235 * V_236 ,
struct V_306 * V_307 )
{
struct V_5 * V_6 = F_35 ( V_236 -> V_49 . V_48 ) ;
struct V_1090 V_1091 ;
T_1 V_1318 , V_1319 ;
unsigned int V_312 , V_276 ;
int V_347 = - V_272 ;
F_968 ( V_236 ) ;
V_236 -> V_1309 ++ ;
V_312 = F_977 ( V_236 ) ;
V_276 = F_978 ( V_236 ) ;
F_969 ( V_236 ) ;
if ( V_307 -> V_315 & V_316 ) {
if ( V_312 != V_268 &&
V_312 != F_212 ( V_307 -> V_213 [ 0 ] ) ) {
F_157 ( L_247 ) ;
goto V_57;
}
} else {
if ( V_312 == V_266 ) {
V_307 -> V_213 [ 0 ] = V_215 ;
} else if ( V_312 == V_267 ) {
F_157 ( L_248 ) ;
goto V_57;
}
}
switch ( V_307 -> V_213 [ 0 ] ) {
case V_216 :
case V_217 :
if ( F_53 ( V_6 ) < 9 ) {
F_157 ( L_249 ,
V_307 -> V_213 [ 0 ] ) ;
goto V_57;
}
case V_214 :
case V_215 :
break;
default:
F_157 ( L_250 ,
V_307 -> V_213 [ 0 ] ) ;
goto V_57;
}
if ( F_181 ( V_6 ) -> V_232 < 4 &&
V_312 != F_212 ( V_307 -> V_213 [ 0 ] ) ) {
F_157 ( L_251 ) ;
goto V_57;
}
V_1318 = F_975 ( V_6 , V_307 -> V_213 [ 0 ] ,
V_307 -> V_314 ) ;
if ( V_307 -> V_244 [ 0 ] > V_1318 ) {
F_157 ( L_252 ,
V_307 -> V_213 [ 0 ] != V_214 ?
L_253 : L_254 ,
V_307 -> V_244 [ 0 ] , V_1318 ) ;
goto V_57;
}
if ( V_312 != V_268 && V_307 -> V_244 [ 0 ] != V_276 ) {
F_157 ( L_255 ,
V_307 -> V_244 [ 0 ] , V_276 ) ;
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
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
break;
case V_299 :
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) &&
F_53 ( V_6 ) < 9 ) {
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
break;
case V_290 :
case V_292 :
case V_294 :
if ( F_53 ( V_6 ) < 4 ) {
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
break;
case V_1320 :
if ( ! F_11 ( V_6 ) && ! F_12 ( V_6 ) ) {
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
break;
case V_375 :
case V_380 :
case V_378 :
case V_382 :
if ( F_53 ( V_6 ) < 5 && ! F_94 ( V_6 ) ) {
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
break;
default:
F_157 ( L_256 ,
F_803 ( V_307 -> V_314 , & V_1091 ) ) ;
goto V_57;
}
if ( V_307 -> V_265 [ 0 ] != 0 )
goto V_57;
F_979 ( & V_6 -> V_242 ,
& V_249 -> V_49 , V_307 ) ;
V_1319 = F_275 ( & V_249 -> V_49 , 0 ) ;
if ( V_307 -> V_244 [ 0 ] & ( V_1319 - 1 ) ) {
F_157 ( L_257 ,
V_307 -> V_244 [ 0 ] , V_1319 ) ;
goto V_57;
}
V_249 -> V_236 = V_236 ;
V_347 = F_213 ( V_6 , & V_249 -> V_49 ) ;
if ( V_347 )
goto V_57;
V_347 = F_980 ( V_236 -> V_49 . V_48 ,
& V_249 -> V_49 ,
& V_1321 ) ;
if ( V_347 ) {
F_124 ( L_258 , V_347 ) ;
goto V_57;
}
return 0 ;
V_57:
F_968 ( V_236 ) ;
V_236 -> V_1309 -- ;
F_969 ( V_236 ) ;
return V_347 ;
}
static struct V_210 *
F_981 ( struct V_47 * V_48 ,
struct V_1259 * V_1322 ,
const struct V_306 * V_1323 )
{
struct V_210 * V_74 ;
struct V_235 * V_236 ;
struct V_306 V_307 = * V_1323 ;
V_236 = F_982 ( V_1322 , V_307 . V_1324 [ 0 ] ) ;
if ( ! V_236 )
return F_682 ( - V_1265 ) ;
V_74 = F_681 ( V_236 , & V_307 ) ;
if ( F_191 ( V_74 ) )
F_226 ( V_236 ) ;
return V_74 ;
}
static void F_983 ( struct V_415 * V_28 )
{
struct V_559 * V_325 = F_303 ( V_28 ) ;
F_984 ( V_28 ) ;
F_985 ( & V_325 -> V_1211 ) ;
F_235 ( V_28 ) ;
}
void F_986 ( struct V_5 * V_6 )
{
F_987 ( V_6 ) ;
if ( F_181 ( V_6 ) -> V_232 >= 9 ) {
V_6 -> V_429 . V_1154 = F_655 ;
V_6 -> V_429 . V_1325 =
F_616 ;
V_6 -> V_429 . V_1072 =
F_636 ;
V_6 -> V_429 . V_1185 = F_451 ;
V_6 -> V_429 . V_613 = F_463 ;
} else if ( F_15 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_655 ;
V_6 -> V_429 . V_1325 =
F_619 ;
V_6 -> V_429 . V_1072 =
F_636 ;
V_6 -> V_429 . V_1185 = F_451 ;
V_6 -> V_429 . V_613 = F_463 ;
} else if ( F_70 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_620 ;
V_6 -> V_429 . V_1325 =
F_619 ;
V_6 -> V_429 . V_1072 =
F_609 ;
V_6 -> V_429 . V_1185 = F_439 ;
V_6 -> V_429 . V_613 = F_461 ;
} else if ( F_12 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_583 ;
V_6 -> V_429 . V_1185 = F_478 ;
V_6 -> V_429 . V_613 = F_489 ;
} else if ( F_11 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_584 ;
V_6 -> V_429 . V_1185 = F_478 ;
V_6 -> V_429 . V_613 = F_489 ;
} else if ( F_94 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_580 ;
V_6 -> V_429 . V_1185 = F_487 ;
V_6 -> V_429 . V_613 = F_489 ;
} else if ( F_29 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_581 ;
V_6 -> V_429 . V_1185 = F_487 ;
V_6 -> V_429 . V_613 = F_489 ;
} else if ( ! F_50 ( V_6 ) ) {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_582 ;
V_6 -> V_429 . V_1185 = F_487 ;
V_6 -> V_429 . V_613 = F_489 ;
} else {
V_6 -> V_429 . V_1154 = F_590 ;
V_6 -> V_429 . V_1325 =
F_587 ;
V_6 -> V_429 . V_1072 = F_579 ;
V_6 -> V_429 . V_1185 = F_487 ;
V_6 -> V_429 . V_613 = F_489 ;
}
if ( F_16 ( V_6 ) ) {
V_6 -> V_429 . V_511 = F_335 ;
} else if ( F_252 ( V_6 ) ) {
V_6 -> V_429 . V_511 = F_341 ;
} else if ( F_253 ( V_6 ) ) {
V_6 -> V_429 . V_511 = F_343 ;
} else if ( F_254 ( V_6 ) || F_255 ( V_6 ) ) {
V_6 -> V_429 . V_511 = V_1326 ;
}
if ( V_6 -> V_1084 . V_232 >= 9 )
V_6 -> V_429 . V_1204 = F_875 ;
else
V_6 -> V_429 . V_1204 = F_874 ;
switch ( F_181 ( V_6 ) -> V_232 ) {
case 2 :
V_6 -> V_429 . V_1059 = F_732 ;
break;
case 3 :
V_6 -> V_429 . V_1059 = F_735 ;
break;
case 4 :
case 5 :
V_6 -> V_429 . V_1059 = F_736 ;
break;
case 6 :
V_6 -> V_429 . V_1059 = F_737 ;
break;
case 7 :
case 8 :
V_6 -> V_429 . V_1059 = F_738 ;
break;
case 9 :
default:
V_6 -> V_429 . V_1059 = F_751 ;
}
}
static void F_988 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_665 |= V_666 ;
F_989 ( L_259 ) ;
}
static void F_990 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_665 |= V_1327 ;
F_989 ( L_260 ) ;
}
static void F_991 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
V_6 -> V_665 |= V_1328 ;
F_989 ( L_261 ) ;
}
static int F_992 ( const struct V_1329 * V_262 )
{
F_989 ( L_262 , V_262 -> V_1330 ) ;
return 1 ;
}
static void F_993 ( struct V_47 * V_48 )
{
struct V_1331 * V_1332 = V_48 -> V_1333 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < F_174 ( V_1334 ) ; V_117 ++ ) {
struct V_1335 * V_1336 = & V_1334 [ V_117 ] ;
if ( V_1332 -> V_1337 == V_1336 -> V_1337 &&
( V_1332 -> V_1338 == V_1336 -> V_1338 ||
V_1336 -> V_1338 == V_1339 ) &&
( V_1332 -> V_1340 == V_1336 -> V_1340 ||
V_1336 -> V_1340 == V_1339 ) )
V_1336 -> V_1341 ( V_48 ) ;
}
for ( V_117 = 0 ; V_117 < F_174 ( V_1342 ) ; V_117 ++ ) {
if ( F_994 ( * V_1342 [ V_117 ] . V_1343 ) != 0 )
V_1342 [ V_117 ] . V_1341 ( V_48 ) ;
}
}
static void F_995 ( struct V_5 * V_6 )
{
struct V_1331 * V_1333 = V_6 -> V_242 . V_1333 ;
T_9 V_1344 ;
T_3 V_1345 = F_996 ( V_6 ) ;
F_997 ( V_1333 , V_1346 ) ;
F_998 ( V_1347 , V_1348 ) ;
V_1344 = F_999 ( V_1349 ) ;
F_998 ( V_1344 | 1 << 5 , V_1349 ) ;
F_1000 ( V_1333 , V_1346 ) ;
F_123 ( 300 ) ;
F_121 ( V_1345 , V_1350 ) ;
F_122 ( V_1345 ) ;
}
void F_319 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_633 ( V_6 ) ;
V_6 -> V_1167 . V_1168 = V_6 -> V_1167 . V_1169 = V_6 -> V_1167 . V_1351 ;
F_1001 ( V_6 ) ;
}
static void F_1002 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_415 * V_28 ;
struct V_559 * V_325 ;
struct V_127 * V_50 ;
struct V_27 * V_1186 ;
struct V_416 V_417 ;
int V_347 ;
int V_117 ;
if ( ! V_6 -> V_429 . V_1205 )
return;
F_309 ( & V_417 , 0 ) ;
V_457:
V_347 = F_310 ( V_48 , & V_417 ) ;
if ( V_347 == - V_420 ) {
F_311 ( & V_417 ) ;
goto V_457;
} else if ( F_21 ( V_347 ) ) {
goto V_974;
}
V_28 = F_312 ( V_48 , & V_417 ) ;
if ( F_21 ( F_191 ( V_28 ) ) )
goto V_974;
V_325 = F_303 ( V_28 ) ;
if ( ! F_159 ( V_6 ) )
V_325 -> V_419 = true ;
V_347 = F_858 ( V_48 , V_28 ) ;
if ( V_347 ) {
F_7 ( true , L_263 ) ;
goto V_1352;
}
F_302 (state, crtc, cstate, i) {
struct V_22 * V_1012 = F_238 ( V_1186 ) ;
V_1012 -> V_1077 . V_1183 = true ;
V_6 -> V_429 . V_1205 ( V_325 , V_1012 ) ;
}
V_1352:
F_314 ( V_28 ) ;
V_974:
F_323 ( & V_417 ) ;
F_324 ( & V_417 ) ;
}
int F_1003 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_304 * V_305 = & V_6 -> V_305 ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
F_1004 ( V_48 ) ;
V_48 -> V_423 . V_1353 = 0 ;
V_48 -> V_423 . V_1354 = 0 ;
V_48 -> V_423 . V_1355 = 24 ;
V_48 -> V_423 . V_1356 = 1 ;
V_48 -> V_423 . V_1357 = true ;
V_48 -> V_423 . V_872 = & V_1358 ;
F_1005 ( & V_6 -> V_1198 . V_1199 ) ;
F_762 ( & V_6 -> V_1198 . V_1050 ,
F_880 ) ;
F_993 ( V_48 ) ;
F_1006 ( V_6 ) ;
if ( F_181 ( V_6 ) -> V_626 == 0 )
return 0 ;
if ( F_117 ( V_6 ) || F_103 ( V_6 ) ) {
bool V_1359 = ! ! ( F_17 ( V_812 ) &
V_818 ) ;
if ( V_6 -> V_663 . V_664 != V_1359 ) {
F_157 ( L_264 ,
V_1359 ? L_73 : L_74 ,
V_6 -> V_663 . V_664 ? L_73 : L_74 ) ;
V_6 -> V_663 . V_664 = V_1359 ;
}
}
if ( F_50 ( V_6 ) ) {
V_48 -> V_423 . V_343 = 2048 ;
V_48 -> V_423 . V_344 = 2048 ;
} else if ( F_1007 ( V_6 ) ) {
V_48 -> V_423 . V_343 = 4096 ;
V_48 -> V_423 . V_344 = 4096 ;
} else {
V_48 -> V_423 . V_343 = 8192 ;
V_48 -> V_423 . V_344 = 8192 ;
}
if ( F_75 ( V_6 ) || F_76 ( V_6 ) ) {
V_48 -> V_423 . V_949 = F_75 ( V_6 ) ? 64 : 512 ;
V_48 -> V_423 . V_950 = 1023 ;
} else if ( F_50 ( V_6 ) ) {
V_48 -> V_423 . V_949 = V_1360 ;
V_48 -> V_423 . V_950 = V_1361 ;
} else {
V_48 -> V_423 . V_949 = V_1362 ;
V_48 -> V_423 . V_950 = V_1363 ;
}
V_48 -> V_423 . V_1364 = V_305 -> V_1365 ;
F_157 ( L_265 ,
F_181 ( V_6 ) -> V_626 ,
F_181 ( V_6 ) -> V_626 > 1 ? L_266 : L_267 ) ;
F_87 (dev_priv, pipe) {
int V_347 ;
V_347 = F_935 ( V_6 , V_79 ) ;
if ( V_347 ) {
F_1008 ( V_48 ) ;
return V_347 ;
}
}
F_1009 ( V_48 ) ;
F_10 ( V_6 ) ;
F_319 ( V_48 ) ;
if ( V_6 -> V_635 == 0 )
F_1010 ( V_6 ) ;
F_995 ( V_6 ) ;
F_951 ( V_6 ) ;
F_1011 ( V_48 ) ;
F_300 ( V_48 , V_48 -> V_423 . V_426 ) ;
F_1012 ( V_48 ) ;
F_135 (dev, crtc) {
struct V_302 V_303 = {} ;
if ( ! V_50 -> V_72 )
continue;
V_6 -> V_429 . V_1325 ( V_50 ,
& V_303 ) ;
F_233 ( V_50 , & V_303 ) ;
}
if ( ! F_159 ( V_6 ) )
F_1002 ( V_48 ) ;
return 0 ;
}
void F_490 ( struct V_5 * V_6 , enum V_79 V_79 )
{
struct V_30 clock = {
. V_39 = 18 ,
. V_32 = 7 ,
. V_34 = 13 ,
. V_35 = 4 ,
. V_36 = 2 ,
} ;
T_1 V_30 , V_668 ;
int V_117 ;
F_21 ( F_23 ( 48000 , & clock ) != 25154 ) ;
F_157 ( L_268 ,
F_73 ( V_79 ) , clock . V_37 , clock . V_38 ) ;
V_668 = F_528 ( & clock ) ;
V_30 = ( F_17 ( F_58 ( V_79 ) ) & V_170 ) |
V_167 |
( ( clock . V_34 - 2 ) << V_727 ) |
V_739 |
V_737 |
V_88 ;
F_121 ( F_485 ( V_79 ) , V_668 ) ;
F_121 ( F_486 ( V_79 ) , V_668 ) ;
F_121 ( F_370 ( V_79 ) , ( 640 - 1 ) | ( ( 800 - 1 ) << 16 ) ) ;
F_121 ( F_372 ( V_79 ) , ( 640 - 1 ) | ( ( 800 - 1 ) << 16 ) ) ;
F_121 ( F_374 ( V_79 ) , ( 656 - 1 ) | ( ( 752 - 1 ) << 16 ) ) ;
F_121 ( F_376 ( V_79 ) , ( 480 - 1 ) | ( ( 525 - 1 ) << 16 ) ) ;
F_121 ( F_378 ( V_79 ) , ( 480 - 1 ) | ( ( 525 - 1 ) << 16 ) ) ;
F_121 ( F_380 ( V_79 ) , ( 490 - 1 ) | ( ( 492 - 1 ) << 16 ) ) ;
F_121 ( F_330 ( V_79 ) , ( ( 640 - 1 ) << 16 ) | ( 480 - 1 ) ) ;
F_121 ( F_58 ( V_79 ) , V_30 & ~ V_167 ) ;
F_121 ( F_58 ( V_79 ) , V_30 ) ;
F_122 ( F_58 ( V_79 ) ) ;
F_123 ( 150 ) ;
F_121 ( F_58 ( V_79 ) , V_30 ) ;
for ( V_117 = 0 ; V_117 < 3 ; V_117 ++ ) {
F_121 ( F_58 ( V_79 ) , V_30 ) ;
F_122 ( F_58 ( V_79 ) ) ;
F_123 ( 150 ) ;
}
F_121 ( F_54 ( V_79 ) , V_114 | V_771 ) ;
F_122 ( F_54 ( V_79 ) ) ;
}
void F_1013 ( struct V_5 * V_6 , enum V_79 V_79 )
{
F_157 ( L_269 ,
F_73 ( V_79 ) ) ;
F_1014 ( V_6 , V_1023 ) ;
F_1014 ( V_6 , V_366 ) ;
F_121 ( F_54 ( V_79 ) , 0 ) ;
F_122 ( F_54 ( V_79 ) ) ;
if ( F_56 ( F_48 ( V_6 , V_79 ) , 100 ) )
F_124 ( L_270 , F_73 ( V_79 ) ) ;
F_121 ( F_58 ( V_79 ) , V_167 ) ;
F_122 ( F_58 ( V_79 ) ) ;
}
static bool
F_1015 ( struct V_66 * V_50 )
{
struct V_5 * V_6 = F_35 ( V_50 -> V_49 . V_48 ) ;
T_1 V_15 ;
if ( F_181 ( V_6 ) -> V_626 == 1 )
return true ;
V_15 = F_17 ( F_84 ( ! V_50 -> V_115 ) ) ;
if ( ( V_15 & V_116 ) &&
( ! ! ( V_15 & V_119 ) == V_50 -> V_79 ) )
return false ;
return true ;
}
static bool F_1016 ( struct V_66 * V_50 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_506 * V_507 ;
F_386 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_618 * F_1017 ( struct V_506 * V_507 )
{
struct V_47 * V_48 = V_507 -> V_49 . V_48 ;
struct V_618 * V_619 ;
F_1018 (dev, &encoder->base, connector)
return V_619 ;
return NULL ;
}
static bool F_1019 ( struct V_5 * V_6 ,
enum V_78 V_501 )
{
return F_117 ( V_6 ) || F_103 ( V_6 ) ||
( F_948 ( V_6 ) && V_501 == V_201 ) ;
}
static void F_1020 ( struct V_66 * V_50 ,
struct V_416 * V_417 )
{
struct V_47 * V_48 = V_50 -> V_49 . V_48 ;
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_78 V_80 = V_50 -> V_75 -> V_80 ;
if ( ! F_452 ( V_80 ) ) {
T_3 V_13 = F_54 ( V_80 ) ;
F_121 ( V_13 ,
F_17 ( V_13 ) & ~ V_1366 ) ;
}
F_1021 ( & V_50 -> V_49 ) ;
if ( V_50 -> V_72 ) {
struct V_261 * V_115 ;
F_448 ( & V_50 -> V_49 ) ;
F_1022 (dev, crtc, plane) {
if ( V_115 -> V_49 . type == V_1246 )
continue;
F_240 ( & V_115 -> V_49 , V_50 ) ;
V_115 -> V_327 ( V_115 , V_50 ) ;
}
}
if ( F_53 ( V_6 ) < 4 && ! F_1015 ( V_50 ) ) {
bool V_115 ;
F_157 ( L_271 ,
V_50 -> V_49 . V_49 . V_262 , V_50 -> V_49 . V_12 ) ;
V_115 = V_50 -> V_115 ;
V_50 -> V_49 . V_73 -> V_28 -> V_320 = true ;
V_50 -> V_115 = ! V_115 ;
F_491 ( & V_50 -> V_49 , V_417 ) ;
V_50 -> V_115 = V_115 ;
}
if ( V_50 -> V_72 && ! F_1016 ( V_50 ) )
F_491 ( & V_50 -> V_49 , V_417 ) ;
if ( V_50 -> V_72 || F_159 ( V_6 ) ) {
V_50 -> V_1367 = true ;
if ( F_1019 ( V_6 , (enum V_78 ) V_50 -> V_79 ) )
V_50 -> V_1368 = true ;
}
}
static void F_1023 ( struct V_506 * V_507 )
{
struct V_618 * V_619 ;
bool V_1369 = V_507 -> V_49 . V_50 &&
F_42 ( V_507 -> V_49 . V_50 ) -> V_72 ;
V_619 = F_1017 ( V_507 ) ;
if ( V_619 && ! V_1369 ) {
F_157 ( L_272 ,
V_507 -> V_49 . V_49 . V_262 ,
V_507 -> V_49 . V_12 ) ;
if ( V_507 -> V_49 . V_50 ) {
struct V_27 * V_45 = V_507 -> V_49 . V_50 -> V_28 ;
F_157 ( L_273 ,
V_507 -> V_49 . V_49 . V_262 ,
V_507 -> V_49 . V_12 ) ;
V_507 -> V_573 ( V_507 , F_238 ( V_45 ) , V_619 -> V_49 . V_28 ) ;
if ( V_507 -> V_574 )
V_507 -> V_574 ( V_507 , F_238 ( V_45 ) , V_619 -> V_49 . V_28 ) ;
}
V_507 -> V_49 . V_50 = NULL ;
V_619 -> V_49 . V_1370 = V_1371 ;
V_619 -> V_49 . V_507 = NULL ;
}
}
void F_1024 ( struct V_5 * V_6 )
{
T_3 V_1345 = F_996 ( V_6 ) ;
if ( ! ( F_17 ( V_1345 ) & V_1350 ) ) {
F_157 ( L_274 ) ;
F_995 ( V_6 ) ;
}
}
void F_301 ( struct V_5 * V_6 )
{
if ( ! F_81 ( V_6 , V_1372 ) )
return;
F_1024 ( V_6 ) ;
F_82 ( V_6 , V_1372 ) ;
}
static bool F_1025 ( struct V_261 * V_115 )
{
struct V_5 * V_6 = F_35 ( V_115 -> V_49 . V_48 ) ;
return F_17 ( F_84 ( V_115 -> V_115 ) ) & V_116 ;
}
static void F_1026 ( struct V_66 * V_50 )
{
struct V_261 * V_73 = F_210 ( V_50 -> V_49 . V_73 ) ;
bool V_320 ;
V_320 = V_50 -> V_72 && F_1025 ( V_73 ) ;
F_230 ( F_238 ( V_50 -> V_49 . V_28 ) ,
F_234 ( V_73 -> V_49 . V_28 ) ,
V_320 ) ;
}
static void F_1027 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
struct V_506 * V_507 ;
struct V_618 * V_619 ;
struct V_1081 V_1082 ;
int V_117 ;
V_6 -> V_616 = 0 ;
F_135 (dev, crtc) {
struct V_22 * V_45 =
F_238 ( V_50 -> V_49 . V_28 ) ;
F_839 ( & V_45 -> V_49 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_49 . V_50 = & V_50 -> V_49 ;
V_45 -> V_49 . V_72 = V_45 -> V_49 . V_502 =
V_6 -> V_429 . V_1154 ( V_50 , V_45 ) ;
V_50 -> V_49 . V_128 = V_45 -> V_49 . V_502 ;
V_50 -> V_72 = V_45 -> V_49 . V_72 ;
if ( V_45 -> V_49 . V_72 )
V_6 -> V_616 |= 1 << V_50 -> V_79 ;
F_1026 ( V_50 ) ;
F_157 ( L_275 ,
V_50 -> V_49 . V_49 . V_262 , V_50 -> V_49 . V_12 ,
F_800 ( V_45 -> V_49 . V_72 ) ) ;
}
for ( V_117 = 0 ; V_117 < V_6 -> V_810 ; V_117 ++ ) {
struct V_866 * V_867 = & V_6 -> V_1162 [ V_117 ] ;
V_867 -> V_1158 = V_867 -> V_872 . V_620 ( V_6 , V_867 ,
& V_867 -> V_28 . V_1160 ) ;
V_867 -> V_28 . V_1156 = 0 ;
F_135 (dev, crtc) {
struct V_22 * V_45 =
F_238 ( V_50 -> V_49 . V_28 ) ;
if ( V_45 -> V_49 . V_72 &&
V_45 -> V_188 == V_867 )
V_867 -> V_28 . V_1156 |= 1 << V_50 -> V_79 ;
}
V_867 -> V_1159 = V_867 -> V_28 . V_1156 ;
F_157 ( L_276 ,
V_867 -> V_12 , V_867 -> V_28 . V_1156 , V_867 -> V_1158 ) ;
}
F_593 (dev, encoder) {
V_79 = 0 ;
if ( V_507 -> V_620 ( V_507 , & V_79 ) ) {
struct V_22 * V_45 ;
V_50 = F_47 ( V_6 , V_79 ) ;
V_45 = F_238 ( V_50 -> V_49 . V_28 ) ;
V_507 -> V_49 . V_50 = & V_50 -> V_49 ;
V_45 -> V_1101 |= 1 << V_507 -> type ;
V_507 -> V_1155 ( V_507 , V_45 ) ;
} else {
V_507 -> V_49 . V_50 = NULL ;
}
F_157 ( L_277 ,
V_507 -> V_49 . V_49 . V_262 , V_507 -> V_49 . V_12 ,
F_800 ( V_507 -> V_49 . V_50 ) ,
F_73 ( V_79 ) ) ;
}
F_788 ( V_48 , & V_1082 ) ;
F_789 (connector, &conn_iter) {
if ( V_619 -> V_620 ( V_619 ) ) {
V_619 -> V_49 . V_1370 = V_1373 ;
V_507 = V_619 -> V_507 ;
V_619 -> V_49 . V_507 = & V_507 -> V_49 ;
if ( V_507 -> V_49 . V_50 &&
V_507 -> V_49 . V_50 -> V_28 -> V_72 ) {
V_507 -> V_49 . V_50 -> V_28 -> V_614 |=
1 << F_1028 ( & V_619 -> V_49 ) ;
V_507 -> V_49 . V_50 -> V_28 -> V_615 |=
1 << F_1029 ( & V_507 -> V_49 ) ;
}
} else {
V_619 -> V_49 . V_1370 = V_1371 ;
V_619 -> V_49 . V_507 = NULL ;
}
F_157 ( L_278 ,
V_619 -> V_49 . V_49 . V_262 , V_619 -> V_49 . V_12 ,
F_800 ( V_619 -> V_49 . V_507 ) ) ;
}
F_792 ( & V_1082 ) ;
F_135 (dev, crtc) {
struct V_22 * V_45 =
F_238 ( V_50 -> V_49 . V_28 ) ;
int V_1374 = 0 ;
memset ( & V_50 -> V_49 . V_414 , 0 , sizeof( V_50 -> V_49 . V_414 ) ) ;
if ( V_45 -> V_49 . V_72 ) {
F_574 ( & V_50 -> V_49 . V_414 , V_45 ) ;
F_574 ( & V_45 -> V_49 . V_76 , V_45 ) ;
F_21 ( F_495 ( V_50 -> V_49 . V_28 , & V_50 -> V_49 . V_414 ) ) ;
V_45 -> V_49 . V_414 . V_1174 = V_1375 ;
F_520 ( V_45 ) ;
if ( F_53 ( V_6 ) >= 9 || F_255 ( V_6 ) ||
F_11 ( V_6 ) || F_12 ( V_6 ) )
V_1374 = V_45 -> V_634 ;
else
F_21 ( V_6 -> V_429 . V_1171 ) ;
if ( F_255 ( V_6 ) && V_45 -> V_545 )
V_1374 = F_217 ( V_1374 * 100 , 95 ) ;
F_1030 ( & V_50 -> V_49 ,
& V_45 -> V_49 . V_76 ) ;
F_846 ( V_50 ) ;
}
V_6 -> V_617 [ V_50 -> V_79 ] = V_1374 ;
F_826 ( V_6 , V_45 ) ;
}
}
static void
F_1031 ( struct V_5 * V_6 )
{
struct V_506 * V_507 ;
F_593 (&dev_priv->drm, encoder) {
T_4 V_1376 ;
enum V_112 V_605 ;
if ( ! V_507 -> V_1377 )
continue;
V_1376 = V_507 -> V_1377 ( V_507 ) ;
F_475 (domain, get_domains)
F_476 ( V_6 , V_605 ) ;
}
}
static void
F_300 ( struct V_47 * V_48 ,
struct V_416 * V_417 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
enum V_79 V_79 ;
struct V_66 * V_50 ;
struct V_506 * V_507 ;
int V_117 ;
F_1027 ( V_48 ) ;
F_1031 ( V_6 ) ;
F_593 (dev, encoder) {
F_1023 ( V_507 ) ;
}
F_87 (dev_priv, pipe) {
V_50 = F_47 ( V_6 , V_79 ) ;
F_1020 ( V_50 , V_417 ) ;
F_797 ( V_50 , V_50 -> V_75 ,
L_279 ) ;
}
F_787 ( V_48 ) ;
for ( V_117 = 0 ; V_117 < V_6 -> V_810 ; V_117 ++ ) {
struct V_866 * V_867 = & V_6 -> V_1162 [ V_117 ] ;
if ( ! V_867 -> V_1158 || V_867 -> V_1159 )
continue;
F_157 ( L_280 , V_867 -> V_12 ) ;
V_867 -> V_872 . V_573 ( V_6 , V_867 ) ;
V_867 -> V_1158 = false ;
}
if ( F_94 ( V_6 ) ) {
F_1032 ( V_48 ) ;
F_1033 ( V_6 ) ;
} else if ( F_11 ( V_6 ) || F_12 ( V_6 ) ) {
F_1034 ( V_48 ) ;
F_1035 ( V_6 ) ;
} else if ( F_1036 ( V_6 ) ) {
F_1037 ( V_48 ) ;
} else if ( F_70 ( V_6 ) ) {
F_1038 ( V_48 ) ;
}
F_135 (dev, crtc) {
T_4 V_1202 ;
V_1202 = F_474 ( & V_50 -> V_49 , V_50 -> V_75 ) ;
if ( F_21 ( V_1202 ) )
F_477 ( V_6 , V_1202 ) ;
}
F_1039 ( V_6 , false ) ;
F_1040 ( V_6 ) ;
F_1041 ( V_6 ) ;
}
void F_1042 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
struct V_415 * V_28 = V_6 -> V_425 ;
struct V_416 V_417 ;
int V_347 ;
V_6 -> V_425 = NULL ;
if ( V_28 )
V_28 -> V_426 = & V_417 ;
F_309 ( & V_417 , 0 ) ;
while ( 1 ) {
V_347 = F_310 ( V_48 , & V_417 ) ;
if ( V_347 != - V_420 )
break;
F_311 ( & V_417 ) ;
}
if ( ! V_347 )
V_347 = F_299 ( V_48 , V_28 , & V_417 ) ;
F_323 ( & V_417 ) ;
F_324 ( & V_417 ) ;
if ( V_347 )
F_124 ( L_57 , V_347 ) ;
if ( V_28 )
F_314 ( V_28 ) ;
}
void F_1043 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_1044 ( V_6 ) ;
F_1045 ( V_6 ) ;
}
int F_1046 ( struct V_567 * V_619 )
{
struct V_618 * V_618 = F_504 ( V_619 ) ;
int V_347 ;
V_347 = F_1047 ( V_618 ) ;
if ( V_347 )
goto V_57;
return 0 ;
V_57:
return V_347 ;
}
void F_1048 ( struct V_567 * V_619 )
{
struct V_618 * V_618 = F_504 ( V_619 ) ;
F_1049 ( V_618 ) ;
F_1050 ( V_619 ) ;
}
void F_1051 ( struct V_47 * V_48 )
{
struct V_5 * V_6 = F_35 ( V_48 ) ;
F_716 ( & V_6 -> V_1198 . V_1050 ) ;
F_21 ( ! F_1052 ( & V_6 -> V_1198 . V_1199 ) ) ;
F_1053 ( V_6 ) ;
F_1054 ( V_6 ) ;
F_1055 ( V_48 ) ;
F_1056 () ;
F_1057 ( V_6 ) ;
F_1058 () ;
F_1008 ( V_48 ) ;
F_1059 ( V_6 ) ;
F_1060 ( V_6 ) ;
F_1061 ( V_6 ) ;
}
void F_1062 ( struct V_618 * V_619 ,
struct V_506 * V_507 )
{
V_619 -> V_507 = V_507 ;
F_1063 ( & V_619 -> V_49 ,
& V_507 -> V_49 ) ;
}
int F_1064 ( struct V_5 * V_6 , bool V_28 )
{
unsigned V_13 = F_53 ( V_6 ) >= 6 ? V_1378 : V_1379 ;
T_10 V_1380 ;
if ( F_1065 ( V_6 -> V_1381 , V_13 , & V_1380 ) ) {
F_124 ( L_281 ) ;
return - V_1052 ;
}
if ( ! ! ( V_1380 & V_1382 ) == ! V_28 )
return 0 ;
if ( V_28 )
V_1380 &= ~ V_1382 ;
else
V_1380 |= V_1382 ;
if ( F_1066 ( V_6 -> V_1381 , V_13 , V_1380 ) ) {
F_124 ( L_282 ) ;
return - V_1052 ;
}
return 0 ;
}
struct V_1383 *
F_1067 ( struct V_5 * V_6 )
{
struct V_1383 * error ;
int V_1384 [] = {
V_201 ,
V_1385 ,
V_1386 ,
V_579 ,
} ;
int V_117 ;
if ( F_181 ( V_6 ) -> V_626 == 0 )
return NULL ;
error = F_506 ( sizeof( * error ) , V_1387 ) ;
if ( error == NULL )
return NULL ;
if ( F_254 ( V_6 ) || F_255 ( V_6 ) )
error -> V_1388 = F_17 ( V_874 ) ;
F_87 (dev_priv, i) {
error -> V_79 [ V_117 ] . V_1389 =
F_1068 ( V_6 ,
F_470 ( V_117 ) ) ;
if ( ! error -> V_79 [ V_117 ] . V_1389 )
continue;
error -> V_956 [ V_117 ] . V_586 = F_17 ( F_77 ( V_117 ) ) ;
error -> V_956 [ V_117 ] . V_1390 = F_17 ( F_671 ( V_117 ) ) ;
error -> V_956 [ V_117 ] . V_49 = F_17 ( F_670 ( V_117 ) ) ;
error -> V_115 [ V_117 ] . V_586 = F_17 ( F_84 ( V_117 ) ) ;
error -> V_115 [ V_117 ] . V_276 = F_17 ( F_266 ( V_117 ) ) ;
if ( F_53 ( V_6 ) <= 3 ) {
error -> V_115 [ V_117 ] . V_224 = F_17 ( F_261 ( V_117 ) ) ;
error -> V_115 [ V_117 ] . V_542 = F_17 ( F_262 ( V_117 ) ) ;
}
if ( F_53 ( V_6 ) <= 7 && ! F_254 ( V_6 ) )
error -> V_115 [ V_117 ] . V_1041 = F_17 ( F_271 ( V_117 ) ) ;
if ( F_53 ( V_6 ) >= 4 ) {
error -> V_115 [ V_117 ] . V_1391 = F_17 ( F_267 ( V_117 ) ) ;
error -> V_115 [ V_117 ] . V_1392 = F_17 ( F_269 ( V_117 ) ) ;
}
error -> V_79 [ V_117 ] . V_1393 = F_17 ( F_330 ( V_117 ) ) ;
if ( F_159 ( V_6 ) )
error -> V_79 [ V_117 ] . V_1394 = F_17 ( F_1069 ( V_117 ) ) ;
}
error -> V_1395 = F_181 ( V_6 ) -> V_626 ;
if ( F_15 ( V_6 ) )
error -> V_1395 ++ ;
for ( V_117 = 0 ; V_117 < error -> V_1395 ; V_117 ++ ) {
enum V_78 V_80 = V_1384 [ V_117 ] ;
error -> V_78 [ V_117 ] . V_1389 =
F_1068 ( V_6 ,
F_80 ( V_80 ) ) ;
if ( ! error -> V_78 [ V_117 ] . V_1389 )
continue;
error -> V_78 [ V_117 ] . V_80 = V_80 ;
error -> V_78 [ V_117 ] . V_1396 = F_17 ( F_54 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_753 = F_17 ( F_370 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_1397 = F_17 ( F_372 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_760 = F_17 ( F_374 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_756 = F_17 ( F_376 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_1042 = F_17 ( F_378 ( V_80 ) ) ;
error -> V_78 [ V_117 ] . V_998 = F_17 ( F_380 ( V_80 ) ) ;
}
return error ;
}
void
F_1070 ( struct V_1398 * V_31 ,
struct V_1383 * error )
{
struct V_5 * V_6 = V_31 -> V_241 ;
int V_117 ;
if ( ! error )
return;
F_1071 ( V_31 , L_283 , F_181 ( V_6 ) -> V_626 ) ;
if ( F_254 ( V_6 ) || F_255 ( V_6 ) )
F_1071 ( V_31 , L_284 ,
error -> V_1388 ) ;
F_87 (dev_priv, i) {
F_1071 ( V_31 , L_285 , V_117 ) ;
F_1071 ( V_31 , L_286 ,
F_60 ( error -> V_79 [ V_117 ] . V_1389 ) ) ;
F_1071 ( V_31 , L_287 , error -> V_79 [ V_117 ] . V_1393 ) ;
F_1071 ( V_31 , L_288 , error -> V_79 [ V_117 ] . V_1394 ) ;
F_1071 ( V_31 , L_289 , V_117 ) ;
F_1071 ( V_31 , L_290 , error -> V_115 [ V_117 ] . V_586 ) ;
F_1071 ( V_31 , L_291 , error -> V_115 [ V_117 ] . V_276 ) ;
if ( F_53 ( V_6 ) <= 3 ) {
F_1071 ( V_31 , L_292 , error -> V_115 [ V_117 ] . V_224 ) ;
F_1071 ( V_31 , L_293 , error -> V_115 [ V_117 ] . V_542 ) ;
}
if ( F_53 ( V_6 ) <= 7 && ! F_254 ( V_6 ) )
F_1071 ( V_31 , L_294 , error -> V_115 [ V_117 ] . V_1041 ) ;
if ( F_53 ( V_6 ) >= 4 ) {
F_1071 ( V_31 , L_295 , error -> V_115 [ V_117 ] . V_1391 ) ;
F_1071 ( V_31 , L_296 , error -> V_115 [ V_117 ] . V_1392 ) ;
}
F_1071 ( V_31 , L_297 , V_117 ) ;
F_1071 ( V_31 , L_290 , error -> V_956 [ V_117 ] . V_586 ) ;
F_1071 ( V_31 , L_293 , error -> V_956 [ V_117 ] . V_1390 ) ;
F_1071 ( V_31 , L_298 , error -> V_956 [ V_117 ] . V_49 ) ;
}
for ( V_117 = 0 ; V_117 < error -> V_1395 ; V_117 ++ ) {
F_1071 ( V_31 , L_299 ,
F_798 ( error -> V_78 [ V_117 ] . V_80 ) ) ;
F_1071 ( V_31 , L_286 ,
F_60 ( error -> V_78 [ V_117 ] . V_1389 ) ) ;
F_1071 ( V_31 , L_300 , error -> V_78 [ V_117 ] . V_1396 ) ;
F_1071 ( V_31 , L_301 , error -> V_78 [ V_117 ] . V_753 ) ;
F_1071 ( V_31 , L_302 , error -> V_78 [ V_117 ] . V_1397 ) ;
F_1071 ( V_31 , L_303 , error -> V_78 [ V_117 ] . V_760 ) ;
F_1071 ( V_31 , L_304 , error -> V_78 [ V_117 ] . V_756 ) ;
F_1071 ( V_31 , L_305 , error -> V_78 [ V_117 ] . V_1042 ) ;
F_1071 ( V_31 , L_306 , error -> V_78 [ V_117 ] . V_998 ) ;
}
}
