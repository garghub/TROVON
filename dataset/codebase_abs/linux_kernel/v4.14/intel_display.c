int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 [] = { 800 , 1600 , 2000 , 2400 } ;
F_2 ( & V_2 -> V_5 ) ;
V_3 = F_3 ( V_2 , V_6 ) &
V_7 ;
F_4 ( & V_2 -> V_5 ) ;
return V_4 [ V_3 ] * 1000 ;
}
int F_5 ( struct V_1 * V_2 ,
const char * V_8 , T_1 V_9 , int V_10 )
{
T_1 V_11 ;
int V_12 ;
F_2 ( & V_2 -> V_5 ) ;
V_11 = F_3 ( V_2 , V_9 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_12 = V_11 & V_13 ;
F_6 ( ( V_11 & V_14 ) !=
( V_12 << V_15 ) ,
L_1 , V_8 ) ;
return F_7 ( V_10 << 1 , V_12 + 1 ) ;
}
int F_8 ( struct V_1 * V_2 ,
const char * V_8 , T_1 V_9 )
{
if ( V_2 -> V_3 == 0 )
V_2 -> V_3 = F_1 ( V_2 ) ;
return F_5 ( V_2 , V_8 , V_9 ,
V_2 -> V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! ( F_10 ( V_2 ) || F_11 ( V_2 ) ) )
return;
V_2 -> V_16 = F_8 ( V_2 , L_2 ,
V_17 ) ;
F_12 ( L_3 , V_2 -> V_16 ) ;
}
static inline T_1
F_13 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
if ( F_14 ( V_2 ) )
return V_19 -> V_20 ;
else if ( F_15 ( V_2 ) )
return ( ( F_16 ( V_21 ) & V_22 ) + 2 ) * 10000 ;
else
return 270000 ;
}
static bool
F_17 ( struct V_23 * V_24 )
{
return F_18 ( V_24 ) ;
}
static int F_19 ( int V_25 , struct V_26 * clock )
{
clock -> V_27 = clock -> V_28 + 2 ;
clock -> V_29 = clock -> V_30 * clock -> V_31 ;
if ( F_20 ( clock -> V_32 == 0 || clock -> V_29 == 0 ) )
return 0 ;
clock -> V_33 = F_7 ( V_25 * clock -> V_27 , clock -> V_32 ) ;
clock -> V_34 = F_7 ( clock -> V_33 , clock -> V_29 ) ;
return clock -> V_34 ;
}
static T_2 F_21 ( struct V_26 * V_26 )
{
return 5 * ( V_26 -> V_35 + 2 ) + ( V_26 -> V_28 + 2 ) ;
}
static int F_22 ( int V_25 , struct V_26 * clock )
{
clock -> V_27 = F_21 ( clock ) ;
clock -> V_29 = clock -> V_30 * clock -> V_31 ;
if ( F_20 ( clock -> V_32 + 2 == 0 || clock -> V_29 == 0 ) )
return 0 ;
clock -> V_33 = F_7 ( V_25 * clock -> V_27 , clock -> V_32 + 2 ) ;
clock -> V_34 = F_7 ( clock -> V_33 , clock -> V_29 ) ;
return clock -> V_34 ;
}
static int F_23 ( int V_25 , struct V_26 * clock )
{
clock -> V_27 = clock -> V_35 * clock -> V_28 ;
clock -> V_29 = clock -> V_30 * clock -> V_31 ;
if ( F_20 ( clock -> V_32 == 0 || clock -> V_29 == 0 ) )
return 0 ;
clock -> V_33 = F_7 ( V_25 * clock -> V_27 , clock -> V_32 ) ;
clock -> V_34 = F_7 ( clock -> V_33 , clock -> V_29 ) ;
return clock -> V_34 / 5 ;
}
int F_24 ( int V_25 , struct V_26 * clock )
{
clock -> V_27 = clock -> V_35 * clock -> V_28 ;
clock -> V_29 = clock -> V_30 * clock -> V_31 ;
if ( F_20 ( clock -> V_32 == 0 || clock -> V_29 == 0 ) )
return 0 ;
clock -> V_33 = F_25 ( ( V_36 ) V_25 * clock -> V_27 ,
clock -> V_32 << 22 ) ;
clock -> V_34 = F_7 ( clock -> V_33 , clock -> V_29 ) ;
return clock -> V_34 / 5 ;
}
static bool F_26 ( struct V_1 * V_2 ,
const struct V_37 * V_38 ,
const struct V_26 * clock )
{
if ( clock -> V_32 < V_38 -> V_32 . V_39 || V_38 -> V_32 . V_40 < clock -> V_32 )
F_27 ( L_4 ) ;
if ( clock -> V_30 < V_38 -> V_30 . V_39 || V_38 -> V_30 . V_40 < clock -> V_30 )
F_27 ( L_5 ) ;
if ( clock -> V_28 < V_38 -> V_28 . V_39 || V_38 -> V_28 . V_40 < clock -> V_28 )
F_27 ( L_6 ) ;
if ( clock -> V_35 < V_38 -> V_35 . V_39 || V_38 -> V_35 . V_40 < clock -> V_35 )
F_27 ( L_7 ) ;
if ( ! F_28 ( V_2 ) && ! F_10 ( V_2 ) &&
! F_11 ( V_2 ) && ! F_29 ( V_2 ) )
if ( clock -> V_35 <= clock -> V_28 )
F_27 ( L_8 ) ;
if ( ! F_10 ( V_2 ) && ! F_11 ( V_2 ) &&
! F_29 ( V_2 ) ) {
if ( clock -> V_29 < V_38 -> V_29 . V_39 || V_38 -> V_29 . V_40 < clock -> V_29 )
F_27 ( L_9 ) ;
if ( clock -> V_27 < V_38 -> V_27 . V_39 || V_38 -> V_27 . V_40 < clock -> V_27 )
F_27 ( L_10 ) ;
}
if ( clock -> V_33 < V_38 -> V_33 . V_39 || V_38 -> V_33 . V_40 < clock -> V_33 )
F_27 ( L_11 ) ;
if ( clock -> V_34 < V_38 -> V_34 . V_39 || V_38 -> V_34 . V_40 < clock -> V_34 )
F_27 ( L_12 ) ;
return true ;
}
static int
F_30 ( const struct V_37 * V_38 ,
const struct V_18 * V_41 ,
int V_42 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_46 -> V_44 ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_32 ( V_44 ) )
return V_38 -> V_31 . V_48 ;
else
return V_38 -> V_31 . V_49 ;
} else {
if ( V_42 < V_38 -> V_31 . V_50 )
return V_38 -> V_31 . V_49 ;
else
return V_38 -> V_31 . V_48 ;
}
}
static bool
F_33 ( const struct V_37 * V_38 ,
struct V_18 * V_41 ,
int V_42 , int V_25 , struct V_26 * V_51 ,
struct V_26 * V_52 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_46 -> V_44 ;
struct V_26 clock ;
int V_53 = V_42 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
clock . V_31 = F_30 ( V_38 , V_41 , V_42 ) ;
for ( clock . V_35 = V_38 -> V_35 . V_39 ; clock . V_35 <= V_38 -> V_35 . V_40 ;
clock . V_35 ++ ) {
for ( clock . V_28 = V_38 -> V_28 . V_39 ;
clock . V_28 <= V_38 -> V_28 . V_40 ; clock . V_28 ++ ) {
if ( clock . V_28 >= clock . V_35 )
break;
for ( clock . V_32 = V_38 -> V_32 . V_39 ;
clock . V_32 <= V_38 -> V_32 . V_40 ; clock . V_32 ++ ) {
for ( clock . V_30 = V_38 -> V_30 . V_39 ;
clock . V_30 <= V_38 -> V_30 . V_40 ; clock . V_30 ++ ) {
int V_54 ;
F_22 ( V_25 , & clock ) ;
if ( ! F_26 ( F_34 ( V_44 ) ,
V_38 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_29 != V_51 -> V_29 )
continue;
V_54 = abs ( clock . V_34 - V_42 ) ;
if ( V_54 < V_53 ) {
* V_52 = clock ;
V_53 = V_54 ;
}
}
}
}
}
return ( V_53 != V_42 ) ;
}
static bool
F_35 ( const struct V_37 * V_38 ,
struct V_18 * V_41 ,
int V_42 , int V_25 , struct V_26 * V_51 ,
struct V_26 * V_52 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_46 -> V_44 ;
struct V_26 clock ;
int V_53 = V_42 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
clock . V_31 = F_30 ( V_38 , V_41 , V_42 ) ;
for ( clock . V_35 = V_38 -> V_35 . V_39 ; clock . V_35 <= V_38 -> V_35 . V_40 ;
clock . V_35 ++ ) {
for ( clock . V_28 = V_38 -> V_28 . V_39 ;
clock . V_28 <= V_38 -> V_28 . V_40 ; clock . V_28 ++ ) {
for ( clock . V_32 = V_38 -> V_32 . V_39 ;
clock . V_32 <= V_38 -> V_32 . V_40 ; clock . V_32 ++ ) {
for ( clock . V_30 = V_38 -> V_30 . V_39 ;
clock . V_30 <= V_38 -> V_30 . V_40 ; clock . V_30 ++ ) {
int V_54 ;
F_19 ( V_25 , & clock ) ;
if ( ! F_26 ( F_34 ( V_44 ) ,
V_38 ,
& clock ) )
continue;
if ( V_51 &&
clock . V_29 != V_51 -> V_29 )
continue;
V_54 = abs ( clock . V_34 - V_42 ) ;
if ( V_54 < V_53 ) {
* V_52 = clock ;
V_53 = V_54 ;
}
}
}
}
}
return ( V_53 != V_42 ) ;
}
static bool
F_36 ( const struct V_37 * V_38 ,
struct V_18 * V_41 ,
int V_42 , int V_25 , struct V_26 * V_51 ,
struct V_26 * V_52 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_46 -> V_44 ;
struct V_26 clock ;
int V_55 ;
bool V_56 = false ;
int V_57 = ( V_42 >> 8 ) + ( V_42 >> 9 ) ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
clock . V_31 = F_30 ( V_38 , V_41 , V_42 ) ;
V_55 = V_38 -> V_32 . V_40 ;
for ( clock . V_32 = V_38 -> V_32 . V_39 ; clock . V_32 <= V_55 ; clock . V_32 ++ ) {
for ( clock . V_35 = V_38 -> V_35 . V_40 ;
clock . V_35 >= V_38 -> V_35 . V_39 ; clock . V_35 -- ) {
for ( clock . V_28 = V_38 -> V_28 . V_40 ;
clock . V_28 >= V_38 -> V_28 . V_39 ; clock . V_28 -- ) {
for ( clock . V_30 = V_38 -> V_30 . V_40 ;
clock . V_30 >= V_38 -> V_30 . V_39 ; clock . V_30 -- ) {
int V_54 ;
F_22 ( V_25 , & clock ) ;
if ( ! F_26 ( F_34 ( V_44 ) ,
V_38 ,
& clock ) )
continue;
V_54 = abs ( clock . V_34 - V_42 ) ;
if ( V_54 < V_57 ) {
* V_52 = clock ;
V_57 = V_54 ;
V_55 = clock . V_32 ;
V_56 = true ;
}
}
}
}
}
return V_56 ;
}
static bool F_37 ( struct V_43 * V_44 , int V_58 ,
const struct V_26 * V_59 ,
const struct V_26 * V_52 ,
unsigned int V_60 ,
unsigned int * V_61 )
{
if ( F_11 ( F_34 ( V_44 ) ) ) {
* V_61 = 0 ;
return V_59 -> V_29 > V_52 -> V_29 ;
}
if ( F_38 ( ! V_58 ) )
return false ;
* V_61 = F_39 ( 1000000ULL *
abs ( V_58 - V_59 -> V_34 ) ,
V_58 ) ;
if ( * V_61 < 100 && V_59 -> V_29 > V_52 -> V_29 ) {
* V_61 = 0 ;
return true ;
}
return * V_61 + 10 < V_60 ;
}
static bool
F_40 ( const struct V_37 * V_38 ,
struct V_18 * V_41 ,
int V_42 , int V_25 , struct V_26 * V_51 ,
struct V_26 * V_52 )
{
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_26 clock ;
unsigned int V_63 = 1000000 ;
int V_55 = V_39 ( V_38 -> V_32 . V_40 , V_25 / 19200 ) ;
bool V_56 = false ;
V_42 *= 5 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
for ( clock . V_32 = V_38 -> V_32 . V_39 ; clock . V_32 <= V_55 ; clock . V_32 ++ ) {
for ( clock . V_30 = V_38 -> V_30 . V_40 ; clock . V_30 >= V_38 -> V_30 . V_39 ; clock . V_30 -- ) {
for ( clock . V_31 = V_38 -> V_31 . V_48 ; clock . V_31 >= V_38 -> V_31 . V_49 ;
clock . V_31 -= clock . V_31 > 10 ? 2 : 1 ) {
clock . V_29 = clock . V_30 * clock . V_31 ;
for ( clock . V_35 = V_38 -> V_35 . V_39 ; clock . V_35 <= V_38 -> V_35 . V_40 ; clock . V_35 ++ ) {
unsigned int V_64 ;
clock . V_28 = F_7 ( V_42 * clock . V_29 * clock . V_32 ,
V_25 * clock . V_35 ) ;
F_23 ( V_25 , & clock ) ;
if ( ! F_26 ( F_34 ( V_44 ) ,
V_38 ,
& clock ) )
continue;
if ( ! F_37 ( V_44 , V_42 ,
& clock ,
V_52 ,
V_63 , & V_64 ) )
continue;
* V_52 = clock ;
V_63 = V_64 ;
V_56 = true ;
}
}
}
}
return V_56 ;
}
static bool
F_42 ( const struct V_37 * V_38 ,
struct V_18 * V_41 ,
int V_42 , int V_25 , struct V_26 * V_51 ,
struct V_26 * V_52 )
{
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
unsigned int V_60 ;
struct V_26 clock ;
V_36 V_28 ;
int V_56 = false ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_60 = 1000000 ;
clock . V_32 = 1 , clock . V_35 = 2 ;
V_42 *= 5 ;
for ( clock . V_30 = V_38 -> V_30 . V_40 ; clock . V_30 >= V_38 -> V_30 . V_39 ; clock . V_30 -- ) {
for ( clock . V_31 = V_38 -> V_31 . V_48 ;
clock . V_31 >= V_38 -> V_31 . V_49 ;
clock . V_31 -= clock . V_31 > 10 ? 2 : 1 ) {
unsigned int V_61 ;
clock . V_29 = clock . V_30 * clock . V_31 ;
V_28 = F_25 ( ( ( V_36 ) V_42 * clock . V_29 *
clock . V_32 ) << 22 , V_25 * clock . V_35 ) ;
if ( V_28 > V_65 / clock . V_35 )
continue;
clock . V_28 = V_28 ;
F_24 ( V_25 , & clock ) ;
if ( ! F_26 ( F_34 ( V_44 ) , V_38 , & clock ) )
continue;
if ( ! F_37 ( V_44 , V_42 , & clock , V_52 ,
V_60 , & V_61 ) )
continue;
* V_52 = clock ;
V_60 = V_61 ;
V_56 = true ;
}
}
return V_56 ;
}
bool F_43 ( struct V_18 * V_41 , int V_66 ,
struct V_26 * V_52 )
{
int V_25 = 100000 ;
const struct V_37 * V_38 = & V_67 ;
return F_42 ( V_38 , V_41 ,
V_66 , V_25 , NULL , V_52 ) ;
}
bool F_44 ( struct V_62 * V_46 )
{
return V_46 -> V_68 && V_46 -> V_45 . V_69 -> V_24 -> V_70 &&
V_46 -> V_71 -> V_45 . V_72 . V_73 ;
}
enum V_74 F_45 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
struct V_62 * V_46 = F_46 ( V_2 , V_75 ) ;
return V_46 -> V_71 -> V_76 ;
}
static bool F_47 ( struct V_1 * V_2 , enum V_75 V_75 )
{
T_3 V_9 = F_48 ( V_75 ) ;
T_1 V_77 , V_78 ;
T_1 V_79 ;
if ( F_49 ( V_2 ) )
V_79 = V_80 ;
else
V_79 = V_81 ;
V_77 = F_16 ( V_9 ) & V_79 ;
F_50 ( 5 ) ;
V_78 = F_16 ( V_9 ) & V_79 ;
return V_77 == V_78 ;
}
static void F_51 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_74 V_76 = V_46 -> V_71 -> V_76 ;
enum V_75 V_75 = V_46 -> V_75 ;
if ( F_52 ( V_2 ) >= 4 ) {
T_3 V_9 = F_53 ( V_76 ) ;
if ( F_54 ( V_2 ,
V_9 , V_82 , 0 ,
100 ) )
F_6 ( 1 , L_13 ) ;
} else {
if ( F_55 ( F_47 ( V_2 , V_75 ) , 100 ) )
F_6 ( 1 , L_13 ) ;
}
}
void F_56 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
T_1 V_11 ;
bool V_83 ;
V_11 = F_16 ( F_57 ( V_75 ) ) ;
V_83 = ! ! ( V_11 & V_84 ) ;
F_58 ( V_83 != V_24 ,
L_14 ,
F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
void F_60 ( struct V_1 * V_2 , bool V_24 )
{
T_1 V_11 ;
bool V_83 ;
F_2 ( & V_2 -> V_5 ) ;
V_11 = F_3 ( V_2 , V_85 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_83 = V_11 & V_86 ;
F_58 ( V_83 != V_24 ,
L_15 ,
F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
static void F_61 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
bool V_83 ;
enum V_74 V_76 = F_45 ( V_2 ,
V_75 ) ;
if ( F_14 ( V_2 ) ) {
T_1 V_11 = F_16 ( F_62 ( V_76 ) ) ;
V_83 = ! ! ( V_11 & V_87 ) ;
} else {
T_1 V_11 = F_16 ( F_63 ( V_75 ) ) ;
V_83 = ! ! ( V_11 & V_88 ) ;
}
F_58 ( V_83 != V_24 ,
L_16 ,
F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
static void F_64 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
T_1 V_11 ;
bool V_83 ;
V_11 = F_16 ( F_65 ( V_75 ) ) ;
V_83 = ! ! ( V_11 & V_89 ) ;
F_58 ( V_83 != V_24 ,
L_17 ,
F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
static void F_66 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
T_1 V_11 ;
if ( F_15 ( V_2 ) )
return;
if ( F_14 ( V_2 ) )
return;
V_11 = F_16 ( F_63 ( V_75 ) ) ;
F_58 ( ! ( V_11 & V_90 ) , L_18 ) ;
}
void F_67 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
T_1 V_11 ;
bool V_83 ;
V_11 = F_16 ( F_65 ( V_75 ) ) ;
V_83 = ! ! ( V_11 & V_91 ) ;
F_58 ( V_83 != V_24 ,
L_19 ,
F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
void F_68 ( struct V_1 * V_2 , enum V_75 V_75 )
{
T_3 V_92 ;
T_1 V_11 ;
enum V_75 V_93 = V_94 ;
bool V_95 = true ;
if ( F_20 ( F_14 ( V_2 ) ) )
return;
if ( F_69 ( V_2 ) ) {
T_1 V_96 ;
V_92 = F_70 ( 0 ) ;
V_96 = F_16 ( F_71 ( 0 ) ) & V_97 ;
if ( V_96 == V_98 &&
F_16 ( V_99 ) & V_100 )
V_93 = V_101 ;
} else if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
V_92 = F_70 ( V_75 ) ;
V_93 = V_75 ;
} else {
V_92 = F_70 ( 0 ) ;
if ( F_16 ( V_102 ) & V_100 )
V_93 = V_101 ;
}
V_11 = F_16 ( V_92 ) ;
if ( ! ( V_11 & V_103 ) ||
( ( V_11 & V_104 ) == V_105 ) )
V_95 = false ;
F_58 ( V_93 == V_75 && V_95 ,
L_20 ,
F_72 ( V_75 ) ) ;
}
static void F_73 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
bool V_83 ;
if ( F_74 ( V_2 ) || F_75 ( V_2 ) )
V_83 = F_16 ( F_76 ( V_94 ) ) & V_106 ;
else
V_83 = F_16 ( F_76 ( V_75 ) ) & V_107 ;
F_58 ( V_83 != V_24 ,
L_21 ,
F_72 ( V_75 ) , F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
void F_77 ( struct V_1 * V_2 ,
enum V_75 V_75 , bool V_24 )
{
bool V_83 ;
enum V_74 V_76 = F_45 ( V_2 ,
V_75 ) ;
enum V_108 V_109 ;
if ( F_78 ( V_2 ) )
V_24 = true ;
V_109 = F_79 ( V_76 ) ;
if ( F_80 ( V_2 , V_109 ) ) {
T_1 V_11 = F_16 ( F_53 ( V_76 ) ) ;
V_83 = ! ! ( V_11 & V_110 ) ;
F_81 ( V_2 , V_109 ) ;
} else {
V_83 = false ;
}
F_58 ( V_83 != V_24 ,
L_22 ,
F_72 ( V_75 ) , F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
static void F_82 ( struct V_1 * V_2 ,
enum V_111 V_111 , bool V_24 )
{
T_1 V_11 ;
bool V_83 ;
V_11 = F_16 ( F_83 ( V_111 ) ) ;
V_83 = ! ! ( V_11 & V_112 ) ;
F_58 ( V_83 != V_24 ,
L_23 ,
F_84 ( V_111 ) , F_59 ( V_24 ) , F_59 ( V_83 ) ) ;
}
static void F_85 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
int V_113 ;
if ( F_52 ( V_2 ) >= 4 ) {
T_1 V_11 = F_16 ( F_83 ( V_75 ) ) ;
F_58 ( V_11 & V_112 ,
L_24 ,
F_84 ( V_75 ) ) ;
return;
}
F_86 (dev_priv, i) {
T_1 V_11 = F_16 ( F_83 ( V_113 ) ) ;
enum V_75 V_114 = ( V_11 & V_115 ) >>
V_116 ;
F_58 ( ( V_11 & V_112 ) && V_75 == V_114 ,
L_25 ,
F_84 ( V_113 ) , F_72 ( V_75 ) ) ;
}
}
static void F_87 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
int V_117 ;
if ( F_52 ( V_2 ) >= 9 ) {
F_88 (dev_priv, pipe, sprite) {
T_1 V_11 = F_16 ( F_89 ( V_75 , V_117 ) ) ;
F_58 ( V_11 & V_118 ,
L_26 ,
V_117 , F_72 ( V_75 ) ) ;
}
} else if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
F_88 (dev_priv, pipe, sprite) {
T_1 V_11 = F_16 ( F_90 ( V_75 , V_119 + V_117 ) ) ;
F_58 ( V_11 & V_120 ,
L_27 ,
F_91 ( V_75 , V_117 ) , F_72 ( V_75 ) ) ;
}
} else if ( F_52 ( V_2 ) >= 7 ) {
T_1 V_11 = F_16 ( F_92 ( V_75 ) ) ;
F_58 ( V_11 & V_121 ,
L_27 ,
F_84 ( V_75 ) , F_72 ( V_75 ) ) ;
} else if ( F_52 ( V_2 ) >= 5 || F_93 ( V_2 ) ) {
T_1 V_11 = F_16 ( F_94 ( V_75 ) ) ;
F_58 ( V_11 & V_122 ,
L_27 ,
F_84 ( V_75 ) , F_72 ( V_75 ) ) ;
}
}
static void F_95 ( struct V_123 * V_46 )
{
if ( F_96 ( F_97 ( V_46 ) == 0 ) )
F_98 ( V_46 ) ;
}
void F_99 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
T_1 V_11 ;
bool V_124 ;
V_11 = F_16 ( F_100 ( V_75 ) ) ;
V_124 = ! ! ( V_11 & V_125 ) ;
F_58 ( V_124 ,
L_28 ,
F_72 ( V_75 ) ) ;
}
static bool F_101 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_1 V_96 , T_1 V_11 )
{
if ( ( V_11 & V_126 ) == 0 )
return false ;
if ( F_102 ( V_2 ) ) {
T_1 V_127 = F_16 ( F_103 ( V_75 ) ) ;
if ( ( V_127 & V_128 ) != V_96 )
return false ;
} else if ( F_11 ( V_2 ) ) {
if ( ( V_11 & V_129 ) != F_104 ( V_75 ) )
return false ;
} else {
if ( ( V_11 & V_130 ) != ( V_75 << 30 ) )
return false ;
}
return true ;
}
static bool F_105 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_1 V_11 )
{
if ( ( V_11 & V_131 ) == 0 )
return false ;
if ( F_102 ( V_2 ) ) {
if ( ( V_11 & V_132 ) != F_106 ( V_75 ) )
return false ;
} else if ( F_11 ( V_2 ) ) {
if ( ( V_11 & V_133 ) != F_107 ( V_75 ) )
return false ;
} else {
if ( ( V_11 & V_134 ) != F_108 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_109 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_1 V_11 )
{
if ( ( V_11 & V_135 ) == 0 )
return false ;
if ( F_102 ( V_2 ) ) {
if ( ( V_11 & V_136 ) != F_110 ( V_75 ) )
return false ;
} else {
if ( ( V_11 & V_137 ) != F_111 ( V_75 ) )
return false ;
}
return true ;
}
static bool F_112 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_1 V_11 )
{
if ( ( V_11 & V_138 ) == 0 )
return false ;
if ( F_102 ( V_2 ) ) {
if ( ( V_11 & V_136 ) != F_110 ( V_75 ) )
return false ;
} else {
if ( ( V_11 & V_139 ) != F_113 ( V_75 ) )
return false ;
}
return true ;
}
static void F_114 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_3 V_9 ,
T_1 V_96 )
{
T_1 V_11 = F_16 ( V_9 ) ;
F_58 ( F_101 ( V_2 , V_75 , V_96 , V_11 ) ,
L_29 ,
F_115 ( V_9 ) , F_72 ( V_75 ) ) ;
F_58 ( F_116 ( V_2 ) && ( V_11 & V_126 ) == 0
&& ( V_11 & V_140 ) ,
L_30 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
enum V_75 V_75 , T_3 V_9 )
{
T_1 V_11 = F_16 ( V_9 ) ;
F_58 ( F_105 ( V_2 , V_75 , V_11 ) ,
L_31 ,
F_115 ( V_9 ) , F_72 ( V_75 ) ) ;
F_58 ( F_116 ( V_2 ) && ( V_11 & V_131 ) == 0
&& ( V_11 & V_141 ) ,
L_32 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
T_1 V_11 ;
F_114 ( V_2 , V_75 , V_142 , V_143 ) ;
F_114 ( V_2 , V_75 , V_144 , V_145 ) ;
F_114 ( V_2 , V_75 , V_146 , V_147 ) ;
V_11 = F_16 ( V_148 ) ;
F_58 ( F_112 ( V_2 , V_75 , V_11 ) ,
L_33 ,
F_72 ( V_75 ) ) ;
V_11 = F_16 ( V_99 ) ;
F_58 ( F_109 ( V_2 , V_75 , V_11 ) ,
L_34 ,
F_72 ( V_75 ) ) ;
F_117 ( V_2 , V_75 , V_149 ) ;
F_117 ( V_2 , V_75 , V_150 ) ;
F_117 ( V_2 , V_75 , V_151 ) ;
}
static void F_119 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
F_120 ( F_57 ( V_75 ) , V_19 -> V_152 . V_26 ) ;
F_121 ( F_57 ( V_75 ) ) ;
F_122 ( 150 ) ;
if ( F_54 ( V_2 ,
F_57 ( V_75 ) ,
V_153 ,
V_153 ,
1 ) )
F_123 ( L_35 , V_75 ) ;
}
static void F_124 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
F_125 ( V_2 , V_75 ) ;
F_68 ( V_2 , V_75 ) ;
if ( V_19 -> V_152 . V_26 & V_84 )
F_119 ( V_46 , V_19 ) ;
F_120 ( F_126 ( V_75 ) , V_19 -> V_152 . V_154 ) ;
F_121 ( F_126 ( V_75 ) ) ;
}
static void F_127 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
enum V_155 V_156 = F_128 ( V_75 ) ;
T_1 V_157 ;
F_2 ( & V_2 -> V_5 ) ;
V_157 = F_129 ( V_2 , V_75 , F_130 ( V_156 ) ) ;
V_157 |= V_158 ;
F_131 ( V_2 , V_75 , F_130 ( V_156 ) , V_157 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_122 ( 1 ) ;
F_120 ( F_57 ( V_75 ) , V_19 -> V_152 . V_26 ) ;
if ( F_54 ( V_2 ,
F_57 ( V_75 ) , V_153 , V_153 ,
1 ) )
F_123 ( L_36 , V_75 ) ;
}
static void F_132 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
F_125 ( V_2 , V_75 ) ;
F_68 ( V_2 , V_75 ) ;
if ( V_19 -> V_152 . V_26 & V_84 )
F_127 ( V_46 , V_19 ) ;
if ( V_75 != V_94 ) {
F_120 ( V_159 , V_75 == V_101 ? V_160 : V_161 ) ;
F_120 ( F_126 ( V_101 ) , V_19 -> V_152 . V_154 ) ;
F_120 ( V_159 , 0 ) ;
V_2 -> V_162 [ V_75 ] = V_19 -> V_152 . V_154 ;
F_20 ( ( F_16 ( F_57 ( V_101 ) ) & V_163 ) == 0 ) ;
} else {
F_120 ( F_126 ( V_75 ) , V_19 -> V_152 . V_154 ) ;
F_121 ( F_126 ( V_75 ) ) ;
}
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_62 * V_46 ;
int V_164 = 0 ;
F_134 (&dev_priv->drm, crtc) {
V_164 += V_46 -> V_45 . V_24 -> V_68 &&
F_31 ( V_46 -> V_71 , V_165 ) ;
}
return V_164 ;
}
static void F_135 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
T_3 V_9 = F_57 ( V_46 -> V_75 ) ;
T_1 V_26 = V_46 -> V_71 -> V_152 . V_26 ;
int V_113 ;
F_125 ( V_2 , V_46 -> V_75 ) ;
if ( F_136 ( V_2 ) && ! F_78 ( V_2 ) )
F_68 ( V_2 , V_46 -> V_75 ) ;
if ( F_78 ( V_2 ) && F_133 ( V_2 ) > 0 ) {
V_26 |= V_166 ;
F_120 ( F_57 ( ! V_46 -> V_75 ) ,
F_16 ( F_57 ( ! V_46 -> V_75 ) ) | V_166 ) ;
}
F_120 ( V_9 , 0 ) ;
F_120 ( V_9 , V_26 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
if ( F_52 ( V_2 ) >= 4 ) {
F_120 ( F_126 ( V_46 -> V_75 ) ,
V_46 -> V_71 -> V_152 . V_154 ) ;
} else {
F_120 ( V_9 , V_26 ) ;
}
for ( V_113 = 0 ; V_113 < 3 ; V_113 ++ ) {
F_120 ( V_9 , V_26 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
}
}
static void F_137 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
if ( F_78 ( V_2 ) &&
F_31 ( V_46 -> V_71 , V_165 ) &&
! F_133 ( V_2 ) ) {
F_120 ( F_57 ( V_101 ) ,
F_16 ( F_57 ( V_101 ) ) & ~ V_166 ) ;
F_120 ( F_57 ( V_94 ) ,
F_16 ( F_57 ( V_94 ) ) & ~ V_166 ) ;
}
if ( F_78 ( V_2 ) )
return;
F_125 ( V_2 , V_75 ) ;
F_120 ( F_57 ( V_75 ) , V_163 ) ;
F_121 ( F_57 ( V_75 ) ) ;
}
static void F_138 ( struct V_1 * V_2 , enum V_75 V_75 )
{
T_1 V_11 ;
F_125 ( V_2 , V_75 ) ;
V_11 = V_167 |
V_168 | V_163 ;
if ( V_75 != V_94 )
V_11 |= V_169 ;
F_120 ( F_57 ( V_75 ) , V_11 ) ;
F_121 ( F_57 ( V_75 ) ) ;
}
static void F_139 ( struct V_1 * V_2 , enum V_75 V_75 )
{
enum V_155 V_156 = F_128 ( V_75 ) ;
T_1 V_11 ;
F_125 ( V_2 , V_75 ) ;
V_11 = V_170 |
V_168 | V_163 ;
if ( V_75 != V_94 )
V_11 |= V_169 ;
F_120 ( F_57 ( V_75 ) , V_11 ) ;
F_121 ( F_57 ( V_75 ) ) ;
F_2 ( & V_2 -> V_5 ) ;
V_11 = F_129 ( V_2 , V_75 , F_130 ( V_156 ) ) ;
V_11 &= ~ V_158 ;
F_131 ( V_2 , V_75 , F_130 ( V_156 ) , V_11 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_140 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
unsigned int V_173 )
{
T_1 V_174 ;
T_3 V_175 ;
switch ( V_172 -> V_156 ) {
case V_176 :
V_174 = V_177 ;
V_175 = F_57 ( 0 ) ;
break;
case V_178 :
V_174 = V_179 ;
V_175 = F_57 ( 0 ) ;
V_173 <<= 4 ;
break;
case V_180 :
V_174 = V_181 ;
V_175 = V_182 ;
break;
default:
F_141 () ;
}
if ( F_54 ( V_2 ,
V_175 , V_174 , V_173 ,
1000 ) )
F_6 ( 1 , L_37 ,
F_142 ( V_172 -> V_156 ) , F_16 ( V_175 ) & V_174 , V_173 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
struct V_62 * V_62 = F_46 ( V_2 ,
V_75 ) ;
T_3 V_9 ;
T_2 V_11 , V_183 ;
F_144 ( V_2 , V_62 -> V_71 -> V_184 ) ;
F_145 ( V_2 , V_75 ) ;
F_146 ( V_2 , V_75 ) ;
if ( F_102 ( V_2 ) ) {
V_9 = F_147 ( V_75 ) ;
V_11 = F_16 ( V_9 ) ;
V_11 |= V_185 ;
F_120 ( V_9 , V_11 ) ;
}
V_9 = F_100 ( V_75 ) ;
V_11 = F_16 ( V_9 ) ;
V_183 = F_16 ( F_53 ( V_75 ) ) ;
if ( F_116 ( V_2 ) ) {
V_11 &= ~ V_186 ;
if ( F_31 ( V_62 -> V_71 , V_187 ) )
V_11 |= V_188 ;
else
V_11 |= V_183 & V_186 ;
}
V_11 &= ~ V_189 ;
if ( ( V_183 & V_190 ) == V_191 )
if ( F_116 ( V_2 ) &&
F_31 ( V_62 -> V_71 , V_192 ) )
V_11 |= V_193 ;
else
V_11 |= V_194 ;
else
V_11 |= V_195 ;
F_120 ( V_9 , V_11 | V_125 ) ;
if ( F_54 ( V_2 ,
V_9 , V_196 , V_196 ,
100 ) )
F_123 ( L_38 , F_72 ( V_75 ) ) ;
}
static void F_148 ( struct V_1 * V_2 ,
enum V_74 V_76 )
{
T_1 V_11 , V_183 ;
F_145 ( V_2 , (enum V_75 ) V_76 ) ;
F_146 ( V_2 , V_94 ) ;
V_11 = F_16 ( F_147 ( V_94 ) ) ;
V_11 |= V_185 ;
F_120 ( F_147 ( V_94 ) , V_11 ) ;
V_11 = V_125 ;
V_183 = F_16 ( F_53 ( V_76 ) ) ;
if ( ( V_183 & V_197 ) ==
V_191 )
V_11 |= V_194 ;
else
V_11 |= V_195 ;
F_120 ( V_198 , V_11 ) ;
if ( F_54 ( V_2 ,
V_198 ,
V_196 ,
V_196 ,
100 ) )
F_123 ( L_39 ) ;
}
static void F_149 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
T_3 V_9 ;
T_2 V_11 ;
F_150 ( V_2 , V_75 ) ;
F_151 ( V_2 , V_75 ) ;
F_118 ( V_2 , V_75 ) ;
V_9 = F_100 ( V_75 ) ;
V_11 = F_16 ( V_9 ) ;
V_11 &= ~ V_125 ;
F_120 ( V_9 , V_11 ) ;
if ( F_54 ( V_2 ,
V_9 , V_196 , 0 ,
50 ) )
F_123 ( L_40 , F_72 ( V_75 ) ) ;
if ( F_102 ( V_2 ) ) {
V_9 = F_147 ( V_75 ) ;
V_11 = F_16 ( V_9 ) ;
V_11 &= ~ V_185 ;
F_120 ( V_9 , V_11 ) ;
}
}
void F_152 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_16 ( V_198 ) ;
V_11 &= ~ V_125 ;
F_120 ( V_198 , V_11 ) ;
if ( F_54 ( V_2 ,
V_198 , V_196 , 0 ,
50 ) )
F_123 ( L_41 ) ;
V_11 = F_16 ( F_147 ( V_94 ) ) ;
V_11 &= ~ V_185 ;
F_120 ( F_147 ( V_94 ) , V_11 ) ;
}
enum V_75 F_153 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
F_20 ( ! V_46 -> V_71 -> V_199 ) ;
if ( F_154 ( V_2 ) )
return V_94 ;
else
return V_46 -> V_75 ;
}
static void F_155 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
enum V_74 V_76 = V_46 -> V_71 -> V_76 ;
T_3 V_9 ;
T_1 V_11 ;
F_156 ( L_42 , F_72 ( V_75 ) ) ;
F_85 ( V_2 , V_75 ) ;
F_157 ( V_2 , V_75 ) ;
F_87 ( V_2 , V_75 ) ;
if ( F_158 ( V_2 ) ) {
if ( F_31 ( V_46 -> V_71 , V_200 ) )
F_159 ( V_2 ) ;
else
F_160 ( V_2 , V_75 ) ;
} else {
if ( V_46 -> V_71 -> V_199 ) {
F_161 ( V_2 ,
F_153 ( V_46 ) ) ;
F_66 ( V_2 ,
(enum V_75 ) V_76 ) ;
}
}
V_9 = F_53 ( V_76 ) ;
V_11 = F_16 ( V_9 ) ;
if ( V_11 & V_110 ) {
F_20 ( ! F_78 ( V_2 ) ) ;
return;
}
F_120 ( V_9 , V_11 | V_110 ) ;
F_121 ( V_9 ) ;
if ( V_44 -> V_201 == 0 &&
F_55 ( F_162 ( V_46 ) != V_46 -> V_202 , 50 ) )
F_123 ( L_43 , F_72 ( V_75 ) ) ;
}
static void F_163 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_74 V_76 = V_46 -> V_71 -> V_76 ;
enum V_75 V_75 = V_46 -> V_75 ;
T_3 V_9 ;
T_1 V_11 ;
F_156 ( L_44 , F_72 ( V_75 ) ) ;
F_85 ( V_2 , V_75 ) ;
F_157 ( V_2 , V_75 ) ;
F_87 ( V_2 , V_75 ) ;
V_9 = F_53 ( V_76 ) ;
V_11 = F_16 ( V_9 ) ;
if ( ( V_11 & V_110 ) == 0 )
return;
if ( V_46 -> V_71 -> V_203 )
V_11 &= ~ V_204 ;
if ( ! F_78 ( V_2 ) )
V_11 &= ~ V_110 ;
F_120 ( V_9 , V_11 ) ;
if ( ( V_11 & V_110 ) == 0 )
F_51 ( V_46 ) ;
}
static unsigned int F_164 ( const struct V_1 * V_2 )
{
return F_49 ( V_2 ) ? 2048 : 4096 ;
}
static unsigned int
F_165 ( const struct V_205 * V_70 , int V_111 )
{
struct V_1 * V_2 = F_34 ( V_70 -> V_44 ) ;
unsigned int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
switch ( V_70 -> V_208 ) {
case V_209 :
return V_206 ;
case V_210 :
if ( F_49 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_211 :
if ( V_111 == 1 )
return 128 ;
case V_212 :
if ( F_49 ( V_2 ) || F_166 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_213 :
if ( V_111 == 1 )
return 128 ;
case V_214 :
switch ( V_206 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_167 ( V_206 ) ;
return V_206 ;
}
break;
default:
F_167 ( V_70 -> V_208 ) ;
return V_206 ;
}
}
static unsigned int
F_168 ( const struct V_205 * V_70 , int V_111 )
{
if ( V_70 -> V_208 == V_209 )
return 1 ;
else
return F_164 ( F_34 ( V_70 -> V_44 ) ) /
F_165 ( V_70 , V_111 ) ;
}
static void F_169 ( const struct V_205 * V_70 , int V_111 ,
unsigned int * V_215 ,
unsigned int * V_216 )
{
unsigned int V_217 = F_165 ( V_70 , V_111 ) ;
unsigned int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
* V_215 = V_217 / V_206 ;
* V_216 = F_164 ( F_34 ( V_70 -> V_44 ) ) / V_217 ;
}
unsigned int
F_170 ( const struct V_205 * V_70 ,
int V_111 , unsigned int V_218 )
{
unsigned int V_216 = F_168 ( V_70 , V_111 ) ;
return F_171 ( V_218 , V_216 ) ;
}
unsigned int F_172 ( const struct V_219 * V_220 )
{
unsigned int V_221 = 0 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < F_173 ( V_220 -> V_111 ) ; V_113 ++ )
V_221 += V_220 -> V_111 [ V_113 ] . V_222 * V_220 -> V_111 [ V_113 ] . V_218 ;
return V_221 ;
}
static void
F_174 ( struct V_223 * V_224 ,
const struct V_205 * V_70 ,
unsigned int V_225 )
{
V_224 -> type = V_226 ;
if ( F_175 ( V_225 ) ) {
V_224 -> type = V_227 ;
V_224 -> V_228 = F_176 ( V_70 ) -> V_220 ;
}
}
static unsigned int F_177 ( const struct V_1 * V_2 )
{
if ( F_78 ( V_2 ) )
return 16 * 1024 ;
else if ( F_178 ( V_2 ) )
return 256 ;
else if ( F_74 ( V_2 ) || F_75 ( V_2 ) )
return 32 ;
else
return 4 * 1024 ;
}
static unsigned int F_179 ( const struct V_1 * V_2 )
{
if ( F_180 ( V_2 ) -> V_229 >= 9 )
return 256 * 1024 ;
else if ( F_181 ( V_2 ) || F_182 ( V_2 ) ||
F_10 ( V_2 ) || F_11 ( V_2 ) )
return 128 * 1024 ;
else if ( F_180 ( V_2 ) -> V_229 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_183 ( const struct V_205 * V_70 ,
int V_111 )
{
struct V_1 * V_2 = F_34 ( V_70 -> V_44 ) ;
if ( V_111 == 1 )
return 4096 ;
switch ( V_70 -> V_208 ) {
case V_209 :
return F_179 ( V_2 ) ;
case V_210 :
if ( F_52 ( V_2 ) >= 9 )
return 256 * 1024 ;
return 0 ;
case V_211 :
case V_213 :
case V_212 :
case V_214 :
return 1 * 1024 * 1024 ;
default:
F_167 ( V_70 -> V_208 ) ;
return 0 ;
}
}
struct V_230 *
F_184 ( struct V_205 * V_70 , unsigned int V_225 )
{
struct V_43 * V_44 = V_70 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_231 * V_232 = F_185 ( V_70 ) ;
struct V_223 V_224 ;
struct V_230 * V_233 ;
T_1 V_234 ;
F_20 ( ! F_186 ( & V_44 -> V_235 ) ) ;
V_234 = F_183 ( V_70 , 0 ) ;
F_174 ( & V_224 , V_70 , V_225 ) ;
if ( F_187 ( V_2 ) && V_234 < 256 * 1024 )
V_234 = 256 * 1024 ;
F_188 ( V_2 ) ;
F_189 ( & V_2 -> V_236 . V_237 ) ;
V_233 = F_190 ( V_232 , V_234 , & V_224 ) ;
if ( F_191 ( V_233 ) )
goto V_53;
if ( F_192 ( V_233 ) ) {
if ( F_193 ( V_233 ) == 0 )
F_194 ( V_233 ) ;
}
F_195 ( V_233 ) ;
V_53:
F_196 ( & V_2 -> V_236 . V_237 ) ;
F_197 ( V_2 ) ;
return V_233 ;
}
void F_198 ( struct V_230 * V_233 )
{
F_199 ( & V_233 -> V_238 -> V_239 -> V_240 . V_235 ) ;
F_200 ( V_233 ) ;
F_201 ( V_233 ) ;
F_202 ( V_233 ) ;
}
static int F_203 ( const struct V_205 * V_70 , int V_111 ,
unsigned int V_225 )
{
if ( F_175 ( V_225 ) )
return F_176 ( V_70 ) -> V_228 [ V_111 ] . V_241 ;
else
return V_70 -> V_242 [ V_111 ] ;
}
T_1 F_204 ( int V_243 , int V_244 ,
const struct V_245 * V_24 ,
int V_111 )
{
const struct V_205 * V_70 = V_24 -> V_45 . V_70 ;
unsigned int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
unsigned int V_241 = V_70 -> V_242 [ V_111 ] ;
return V_244 * V_241 + V_243 * V_206 ;
}
void F_205 ( int * V_243 , int * V_244 ,
const struct V_245 * V_24 ,
int V_111 )
{
const struct V_246 * V_247 = F_176 ( V_24 -> V_45 . V_70 ) ;
unsigned int V_225 = V_24 -> V_45 . V_225 ;
if ( F_175 ( V_225 ) ) {
* V_243 += V_247 -> V_228 [ V_111 ] . V_243 ;
* V_244 += V_247 -> V_228 [ V_111 ] . V_244 ;
} else {
* V_243 += V_247 -> V_248 [ V_111 ] . V_243 ;
* V_244 += V_247 -> V_248 [ V_111 ] . V_244 ;
}
}
static T_1 F_206 ( int * V_243 , int * V_244 ,
unsigned int V_215 ,
unsigned int V_216 ,
unsigned int V_249 ,
unsigned int V_250 ,
T_1 V_251 ,
T_1 V_252 )
{
unsigned int V_253 = V_250 * V_215 ;
unsigned int V_254 ;
F_20 ( V_251 & ( V_249 - 1 ) ) ;
F_20 ( V_252 & ( V_249 - 1 ) ) ;
F_20 ( V_252 > V_251 ) ;
V_254 = ( V_251 - V_252 ) / V_249 ;
* V_244 += V_254 / V_250 * V_216 ;
* V_243 += V_254 % V_250 * V_215 ;
* V_244 += * V_243 / V_253 * V_216 ;
* V_243 %= V_253 ;
return V_252 ;
}
static T_1 F_207 ( int * V_243 , int * V_244 ,
const struct V_205 * V_70 , int V_111 ,
unsigned int V_225 ,
T_1 V_251 , T_1 V_252 )
{
const struct V_1 * V_2 = F_34 ( V_70 -> V_44 ) ;
unsigned int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
unsigned int V_241 = F_203 ( V_70 , V_111 , V_225 ) ;
F_20 ( V_252 > V_251 ) ;
if ( V_70 -> V_208 != V_209 ) {
unsigned int V_249 , V_215 , V_216 ;
unsigned int V_250 ;
V_249 = F_164 ( V_2 ) ;
F_169 ( V_70 , V_111 , & V_215 , & V_216 ) ;
if ( F_175 ( V_225 ) ) {
V_250 = V_241 / V_216 ;
F_208 ( V_215 , V_216 ) ;
} else {
V_250 = V_241 / ( V_215 * V_206 ) ;
}
F_206 ( V_243 , V_244 , V_215 , V_216 ,
V_249 , V_250 ,
V_251 , V_252 ) ;
} else {
V_251 += * V_244 * V_241 + * V_243 * V_206 ;
* V_244 = ( V_251 - V_252 ) / V_241 ;
* V_243 = ( ( V_251 - V_252 ) - * V_244 * V_241 ) / V_206 ;
}
return V_252 ;
}
static T_1 F_209 ( int * V_243 , int * V_244 ,
const struct V_245 * V_24 , int V_111 ,
T_1 V_251 , T_1 V_252 )
{
return F_207 ( V_243 , V_244 , V_24 -> V_45 . V_70 , V_111 ,
V_24 -> V_45 . V_225 ,
V_251 , V_252 ) ;
}
static T_1 F_210 ( const struct V_1 * V_2 ,
int * V_243 , int * V_244 ,
const struct V_205 * V_70 , int V_111 ,
unsigned int V_241 ,
unsigned int V_225 ,
T_1 V_234 )
{
V_36 V_255 = V_70 -> V_208 ;
unsigned int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
T_1 V_256 , V_257 ;
if ( V_234 )
V_234 -- ;
if ( V_255 != V_209 ) {
unsigned int V_249 , V_215 , V_216 ;
unsigned int V_258 , V_254 , V_250 ;
V_249 = F_164 ( V_2 ) ;
F_169 ( V_70 , V_111 , & V_215 , & V_216 ) ;
if ( F_175 ( V_225 ) ) {
V_250 = V_241 / V_216 ;
F_208 ( V_215 , V_216 ) ;
} else {
V_250 = V_241 / ( V_215 * V_206 ) ;
}
V_258 = * V_244 / V_216 ;
* V_244 %= V_216 ;
V_254 = * V_243 / V_215 ;
* V_243 %= V_215 ;
V_256 = ( V_258 * V_250 + V_254 ) * V_249 ;
V_257 = V_256 & ~ V_234 ;
F_206 ( V_243 , V_244 , V_215 , V_216 ,
V_249 , V_250 ,
V_256 , V_257 ) ;
} else {
V_256 = * V_244 * V_241 + * V_243 * V_206 ;
V_257 = V_256 & ~ V_234 ;
* V_244 = ( V_256 & V_234 ) / V_241 ;
* V_243 = ( ( V_256 & V_234 ) - * V_244 * V_241 ) / V_206 ;
}
return V_257 ;
}
T_1 F_211 ( int * V_243 , int * V_244 ,
const struct V_245 * V_24 ,
int V_111 )
{
struct V_259 * V_259 = F_212 ( V_24 -> V_45 . V_111 ) ;
struct V_1 * V_2 = F_34 ( V_259 -> V_45 . V_44 ) ;
const struct V_205 * V_70 = V_24 -> V_45 . V_70 ;
unsigned int V_225 = V_24 -> V_45 . V_225 ;
int V_241 = F_203 ( V_70 , V_111 , V_225 ) ;
T_1 V_234 ;
if ( V_259 -> V_260 == V_261 )
V_234 = F_177 ( V_2 ) ;
else
V_234 = F_183 ( V_70 , V_111 ) ;
return F_210 ( V_2 , V_243 , V_244 , V_70 , V_111 , V_241 ,
V_225 , V_234 ) ;
}
static int F_213 ( int * V_243 , int * V_244 ,
const struct V_205 * V_70 , int V_111 )
{
struct V_1 * V_2 = F_34 ( V_70 -> V_44 ) ;
if ( V_70 -> V_208 != V_209 &&
V_70 -> V_262 [ V_111 ] % F_164 ( V_2 ) )
return - V_263 ;
* V_243 = 0 ;
* V_244 = 0 ;
F_207 ( V_243 , V_244 ,
V_70 , V_111 , V_264 ,
V_70 -> V_262 [ V_111 ] , 0 ) ;
return 0 ;
}
static unsigned int F_214 ( V_36 V_255 )
{
switch ( V_255 ) {
case V_210 :
return V_265 ;
case V_212 :
case V_211 :
return V_266 ;
default:
return V_267 ;
}
}
static const struct V_268 *
F_215 ( const struct V_268 V_269 [] ,
int V_270 , T_1 V_207 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_270 ; V_113 ++ ) {
if ( V_269 [ V_113 ] . V_207 == V_207 )
return & V_269 [ V_113 ] ;
}
return NULL ;
}
static const struct V_268 *
F_216 ( const struct V_271 * V_272 )
{
switch ( V_272 -> V_208 [ 0 ] ) {
case V_211 :
case V_213 :
return F_215 ( V_273 ,
F_173 ( V_273 ) ,
V_272 -> V_274 ) ;
default:
return NULL ;
}
}
static int
F_217 ( struct V_1 * V_2 ,
struct V_205 * V_70 )
{
struct V_246 * V_247 = F_176 ( V_70 ) ;
struct V_219 * V_220 = & V_247 -> V_220 ;
T_1 V_275 = 0 ;
unsigned int V_276 = 0 ;
int V_113 , V_277 = V_70 -> V_207 -> V_277 ;
unsigned int V_249 = F_164 ( V_2 ) ;
for ( V_113 = 0 ; V_113 < V_277 ; V_113 ++ ) {
unsigned int V_222 , V_218 ;
unsigned int V_206 , V_221 ;
T_1 V_256 ;
int V_243 , V_244 ;
int V_278 ;
V_206 = V_70 -> V_207 -> V_206 [ V_113 ] ;
V_222 = F_218 ( V_70 -> V_222 , V_70 , V_113 ) ;
V_218 = F_219 ( V_70 -> V_218 , V_70 , V_113 ) ;
V_278 = F_213 ( & V_243 , & V_244 , V_70 , V_113 ) ;
if ( V_278 ) {
F_156 ( L_45 ,
V_113 , V_70 -> V_262 [ V_113 ] ) ;
return V_278 ;
}
if ( ( V_70 -> V_208 == V_211 ||
V_70 -> V_208 == V_213 ) && V_113 == 1 ) {
int V_279 = V_70 -> V_207 -> V_279 ;
int V_280 = V_70 -> V_207 -> V_280 ;
int V_215 , V_216 ;
int V_281 , V_282 ;
int V_283 , V_284 ;
F_169 ( V_70 , V_113 , & V_215 , & V_216 ) ;
V_215 *= V_279 ;
V_216 *= V_280 ;
V_283 = ( V_243 * V_279 ) % V_215 ;
V_284 = ( V_244 * V_280 ) % V_216 ;
V_281 = V_247 -> V_248 [ 0 ] . V_243 % V_215 ;
V_282 = V_247 -> V_248 [ 0 ] . V_244 % V_216 ;
if ( V_281 != V_283 || V_282 != V_284 ) {
F_156 ( L_46 ,
V_281 , V_282 ,
V_283 , V_284 ,
V_247 -> V_248 [ 0 ] . V_243 ,
V_247 -> V_248 [ 0 ] . V_244 ,
V_243 , V_244 ) ;
return - V_263 ;
}
}
if ( V_113 == 0 && F_220 ( V_247 -> V_232 ) &&
( V_243 + V_222 ) * V_206 > V_70 -> V_242 [ V_113 ] ) {
F_156 ( L_45 ,
V_113 , V_70 -> V_262 [ V_113 ] ) ;
return - V_263 ;
}
V_247 -> V_248 [ V_113 ] . V_243 = V_243 ;
V_247 -> V_248 [ V_113 ] . V_244 = V_244 ;
V_256 = F_210 ( V_2 , & V_243 , & V_244 ,
V_70 , V_113 , V_70 -> V_242 [ V_113 ] ,
V_264 , V_249 ) ;
V_256 /= V_249 ;
if ( V_70 -> V_208 != V_209 ) {
unsigned int V_215 , V_216 ;
unsigned int V_250 ;
struct V_285 V_286 ;
F_169 ( V_70 , V_113 , & V_215 , & V_216 ) ;
V_220 -> V_111 [ V_113 ] . V_256 = V_256 ;
V_220 -> V_111 [ V_113 ] . V_287 = F_221 ( V_70 -> V_242 [ V_113 ] , V_215 * V_206 ) ;
V_220 -> V_111 [ V_113 ] . V_222 = F_221 ( V_243 + V_222 , V_215 ) ;
V_220 -> V_111 [ V_113 ] . V_218 = F_221 ( V_244 + V_218 , V_216 ) ;
V_247 -> V_228 [ V_113 ] . V_241 =
V_220 -> V_111 [ V_113 ] . V_218 * V_216 ;
V_221 = V_220 -> V_111 [ V_113 ] . V_287 * V_220 -> V_111 [ V_113 ] . V_218 ;
if ( V_243 != 0 )
V_221 ++ ;
V_286 . V_288 = V_243 ;
V_286 . y1 = V_244 ;
V_286 . V_289 = V_243 + V_222 ;
V_286 . V_290 = V_244 + V_218 ;
F_222 ( & V_286 ,
V_220 -> V_111 [ V_113 ] . V_222 * V_215 ,
V_220 -> V_111 [ V_113 ] . V_218 * V_216 ,
V_291 ) ;
V_243 = V_286 . V_288 ;
V_244 = V_286 . y1 ;
V_250 = V_247 -> V_228 [ V_113 ] . V_241 / V_216 ;
F_208 ( V_215 , V_216 ) ;
F_206 ( & V_243 , & V_244 ,
V_215 , V_216 ,
V_249 , V_250 ,
V_275 * V_249 , 0 ) ;
V_275 += V_220 -> V_111 [ V_113 ] . V_222 * V_220 -> V_111 [ V_113 ] . V_218 ;
V_247 -> V_228 [ V_113 ] . V_243 = V_243 ;
V_247 -> V_228 [ V_113 ] . V_244 = V_244 ;
} else {
V_221 = F_221 ( ( V_244 + V_218 ) * V_70 -> V_242 [ V_113 ] +
V_243 * V_206 , V_249 ) ;
}
V_276 = V_40 ( V_276 , V_256 + V_221 ) ;
}
if ( V_276 * V_249 > V_247 -> V_232 -> V_45 . V_221 ) {
F_156 ( L_47 ,
V_276 * V_249 , V_247 -> V_232 -> V_45 . V_221 ) ;
return - V_263 ;
}
return 0 ;
}
static int F_223 ( int V_207 )
{
switch ( V_207 ) {
case V_292 :
return V_293 ;
case V_294 :
return V_295 ;
case V_296 :
return V_297 ;
default:
case V_298 :
return V_299 ;
case V_300 :
return V_301 ;
case V_302 :
return V_303 ;
case V_304 :
return V_305 ;
}
}
static int F_224 ( int V_207 , bool V_306 , bool V_307 )
{
switch ( V_207 ) {
case V_308 :
return V_297 ;
default:
case V_309 :
if ( V_306 ) {
if ( V_307 )
return V_310 ;
else
return V_301 ;
} else {
if ( V_307 )
return V_311 ;
else
return V_299 ;
}
case V_312 :
if ( V_306 )
return V_305 ;
else
return V_303 ;
}
}
static bool
F_225 ( struct V_62 * V_46 ,
struct V_313 * V_314 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_315 * V_316 = & V_2 -> V_316 ;
struct V_231 * V_232 = NULL ;
struct V_271 V_317 = { 0 } ;
struct V_205 * V_70 = & V_314 -> V_70 -> V_45 ;
T_1 V_318 = F_226 ( V_314 -> V_45 , V_319 ) ;
T_1 V_320 = F_227 ( V_314 -> V_45 + V_314 -> V_221 ,
V_319 ) ;
V_320 -= V_318 ;
if ( V_314 -> V_221 == 0 )
return false ;
if ( V_320 * 2 > V_316 -> V_321 )
return false ;
F_2 ( & V_44 -> V_235 ) ;
V_232 = F_228 ( V_2 ,
V_318 ,
V_318 ,
V_320 ) ;
F_4 ( & V_44 -> V_235 ) ;
if ( ! V_232 )
return false ;
if ( V_314 -> V_322 == V_265 )
V_232 -> V_323 = V_70 -> V_242 [ 0 ] | V_265 ;
V_317 . V_274 = V_70 -> V_207 -> V_207 ;
V_317 . V_222 = V_70 -> V_222 ;
V_317 . V_218 = V_70 -> V_218 ;
V_317 . V_242 [ 0 ] = V_70 -> V_242 [ 0 ] ;
V_317 . V_208 [ 0 ] = V_70 -> V_208 ;
V_317 . V_324 = V_325 ;
if ( F_229 ( F_176 ( V_70 ) , V_232 , & V_317 ) ) {
F_156 ( L_48 ) ;
goto V_326;
}
F_156 ( L_49 , V_232 ) ;
return true ;
V_326:
F_230 ( V_232 ) ;
return false ;
}
static void
F_231 ( struct V_18 * V_41 ,
struct V_245 * V_327 ,
bool V_328 )
{
struct V_259 * V_111 = F_212 ( V_327 -> V_45 . V_111 ) ;
V_327 -> V_45 . V_328 = V_328 ;
if ( V_328 ) {
V_41 -> V_45 . V_329 |= F_232 ( F_233 ( & V_111 -> V_45 ) ) ;
V_41 -> V_330 |= F_232 ( V_111 -> V_260 ) ;
} else {
V_41 -> V_45 . V_329 &= ~ F_232 ( F_233 ( & V_111 -> V_45 ) ) ;
V_41 -> V_330 &= ~ F_232 ( V_111 -> V_260 ) ;
}
F_156 ( L_50 ,
V_41 -> V_45 . V_46 -> V_8 ,
V_41 -> V_330 ) ;
}
static void
F_234 ( struct V_62 * V_62 ,
struct V_313 * V_314 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_123 * V_331 ;
struct V_231 * V_232 ;
struct V_332 * V_69 = V_62 -> V_45 . V_69 ;
struct V_333 * V_327 = V_69 -> V_24 ;
struct V_23 * V_41 = V_62 -> V_45 . V_24 ;
struct V_259 * V_259 = F_212 ( V_69 ) ;
struct V_245 * V_334 =
F_235 ( V_327 ) ;
struct V_205 * V_70 ;
if ( ! V_314 -> V_70 )
return;
if ( F_225 ( V_62 , V_314 ) ) {
V_70 = & V_314 -> V_70 -> V_45 ;
goto V_335;
}
F_236 ( V_314 -> V_70 ) ;
F_237 (dev, c) {
struct V_245 * V_24 ;
if ( V_331 == & V_62 -> V_45 )
continue;
if ( ! F_41 ( V_331 ) -> V_68 )
continue;
V_24 = F_235 ( V_331 -> V_69 -> V_24 ) ;
if ( ! V_24 -> V_233 )
continue;
if ( F_238 ( V_24 ) == V_314 -> V_45 ) {
V_70 = V_331 -> V_69 -> V_70 ;
F_239 ( V_70 ) ;
goto V_335;
}
}
F_231 ( F_240 ( V_41 ) ,
F_235 ( V_327 ) ,
false ) ;
F_241 ( & V_62 -> V_45 ) ;
F_242 ( V_69 , V_62 ) ;
V_259 -> V_336 ( V_259 , V_62 ) ;
return;
V_335:
F_2 ( & V_44 -> V_235 ) ;
V_334 -> V_233 =
F_184 ( V_70 , V_69 -> V_24 -> V_225 ) ;
F_4 ( & V_44 -> V_235 ) ;
if ( F_191 ( V_334 -> V_233 ) ) {
F_123 ( L_51 ,
V_62 -> V_75 , F_243 ( V_334 -> V_233 ) ) ;
V_334 -> V_233 = NULL ;
F_244 ( V_70 ) ;
return;
}
V_327 -> V_337 = 0 ;
V_327 -> V_338 = 0 ;
V_327 -> V_339 = V_70 -> V_222 << 16 ;
V_327 -> V_340 = V_70 -> V_218 << 16 ;
V_327 -> V_341 = 0 ;
V_327 -> V_342 = 0 ;
V_327 -> V_343 = V_70 -> V_222 ;
V_327 -> V_344 = V_70 -> V_218 ;
V_334 -> V_45 . V_345 = F_245 ( V_327 ) ;
V_334 -> V_45 . V_346 = F_246 ( V_327 ) ;
V_232 = F_185 ( V_70 ) ;
if ( F_220 ( V_232 ) )
V_2 -> V_347 = true ;
F_239 ( V_70 ) ;
V_69 -> V_70 = V_69 -> V_24 -> V_70 = V_70 ;
V_69 -> V_46 = V_69 -> V_24 -> V_46 = & V_62 -> V_45 ;
F_231 ( F_240 ( V_41 ) ,
F_235 ( V_327 ) ,
true ) ;
F_247 ( F_212 ( V_69 ) -> V_348 ,
& V_232 -> V_349 ) ;
}
static int F_248 ( const struct V_205 * V_70 , int V_111 ,
unsigned int V_225 )
{
int V_206 = V_70 -> V_207 -> V_206 [ V_111 ] ;
switch ( V_70 -> V_208 ) {
case V_209 :
case V_210 :
switch ( V_206 ) {
case 8 :
return 4096 ;
case 4 :
case 2 :
case 1 :
return 8192 ;
default:
F_167 ( V_206 ) ;
break;
}
break;
case V_211 :
case V_213 :
case V_212 :
case V_214 :
switch ( V_206 ) {
case 8 :
return 2048 ;
case 4 :
return 4096 ;
case 2 :
case 1 :
return 8192 ;
default:
F_167 ( V_206 ) ;
break;
}
break;
default:
F_167 ( V_70 -> V_208 ) ;
}
return 2048 ;
}
static bool F_249 ( struct V_245 * V_327 ,
int V_281 , int V_282 , T_1 V_350 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
int V_279 = V_70 -> V_207 -> V_279 ;
int V_280 = V_70 -> V_207 -> V_280 ;
int V_351 = V_327 -> V_352 . V_243 ;
int V_353 = V_327 -> V_352 . V_244 ;
T_1 V_354 = V_327 -> V_352 . V_256 ;
T_1 V_234 = F_183 ( V_70 , 1 ) ;
while ( V_354 >= V_350 && V_353 <= V_282 ) {
int V_243 , V_244 ;
if ( V_351 == V_281 && V_353 == V_282 )
break;
if ( V_354 == 0 )
break;
V_243 = V_351 / V_279 ;
V_244 = V_353 / V_280 ;
V_354 = F_209 ( & V_243 , & V_244 , V_327 , 1 ,
V_354 , V_354 - V_234 ) ;
V_351 = V_243 * V_279 + V_351 % V_279 ;
V_353 = V_244 * V_280 + V_353 % V_280 ;
}
if ( V_351 != V_281 || V_353 != V_282 )
return false ;
V_327 -> V_352 . V_256 = V_354 ;
V_327 -> V_352 . V_243 = V_351 ;
V_327 -> V_352 . V_244 = V_353 ;
return true ;
}
static int F_250 ( struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
int V_243 = V_327 -> V_45 . V_345 . V_288 >> 16 ;
int V_244 = V_327 -> V_45 . V_345 . y1 >> 16 ;
int V_355 = F_251 ( & V_327 -> V_45 . V_345 ) >> 16 ;
int V_356 = F_252 ( & V_327 -> V_45 . V_345 ) >> 16 ;
int V_357 = F_248 ( V_70 , 0 , V_225 ) ;
int V_358 = 4096 ;
T_1 V_234 , V_256 , V_354 = V_327 -> V_352 . V_256 ;
if ( V_355 > V_357 || V_356 > V_358 ) {
F_156 ( L_52 ,
V_355 , V_356 , V_357 , V_358 ) ;
return - V_263 ;
}
F_205 ( & V_243 , & V_244 , V_327 , 0 ) ;
V_256 = F_211 ( & V_243 , & V_244 , V_327 , 0 ) ;
V_234 = F_183 ( V_70 , 0 ) ;
if ( V_256 > V_354 )
V_256 = F_209 ( & V_243 , & V_244 , V_327 , 0 ,
V_256 , V_354 & ~ ( V_234 - 1 ) ) ;
if ( V_70 -> V_208 == V_210 ) {
int V_206 = V_70 -> V_207 -> V_206 [ 0 ] ;
while ( ( V_243 + V_355 ) * V_206 > V_70 -> V_242 [ 0 ] ) {
if ( V_256 == 0 ) {
F_156 ( L_53 ) ;
return - V_263 ;
}
V_256 = F_209 ( & V_243 , & V_244 , V_327 , 0 ,
V_256 , V_256 - V_234 ) ;
}
}
if ( V_70 -> V_208 == V_211 ||
V_70 -> V_208 == V_213 ) {
while ( ! F_249 ( V_327 , V_243 , V_244 , V_256 ) ) {
if ( V_256 == 0 )
break;
V_256 = F_209 ( & V_243 , & V_244 , V_327 , 0 ,
V_256 , V_256 - V_234 ) ;
}
if ( V_243 != V_327 -> V_352 . V_243 || V_244 != V_327 -> V_352 . V_244 ) {
F_156 ( L_54 ) ;
return - V_263 ;
}
}
V_327 -> main. V_256 = V_256 ;
V_327 -> main. V_243 = V_243 ;
V_327 -> main. V_244 = V_244 ;
return 0 ;
}
static int F_253 ( struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
int V_357 = F_248 ( V_70 , 1 , V_225 ) ;
int V_358 = 4096 ;
int V_243 = V_327 -> V_45 . V_345 . V_288 >> 17 ;
int V_244 = V_327 -> V_45 . V_345 . y1 >> 17 ;
int V_355 = F_251 ( & V_327 -> V_45 . V_345 ) >> 17 ;
int V_356 = F_252 ( & V_327 -> V_45 . V_345 ) >> 17 ;
T_1 V_256 ;
F_205 ( & V_243 , & V_244 , V_327 , 1 ) ;
V_256 = F_211 ( & V_243 , & V_244 , V_327 , 1 ) ;
if ( V_355 > V_357 || V_356 > V_358 ) {
F_156 ( L_55 ,
V_355 , V_356 , V_357 , V_358 ) ;
return - V_263 ;
}
V_327 -> V_352 . V_256 = V_256 ;
V_327 -> V_352 . V_243 = V_243 ;
V_327 -> V_352 . V_244 = V_244 ;
return 0 ;
}
static int F_254 ( struct V_245 * V_327 )
{
struct V_259 * V_111 = F_212 ( V_327 -> V_45 . V_111 ) ;
struct V_62 * V_46 = F_41 ( V_327 -> V_45 . V_46 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
int V_337 = V_327 -> V_45 . V_345 . V_288 >> 16 ;
int V_338 = V_327 -> V_45 . V_345 . y1 >> 16 ;
int V_279 = V_70 -> V_207 -> V_279 ;
int V_280 = V_70 -> V_207 -> V_280 ;
int V_243 = V_337 / V_279 ;
int V_244 = V_338 / V_280 ;
T_1 V_256 ;
switch ( V_111 -> V_260 ) {
case V_359 :
case V_119 :
break;
default:
F_156 ( L_56 ) ;
return - V_263 ;
}
if ( V_46 -> V_75 == V_360 ) {
F_156 ( L_57 ) ;
return - V_263 ;
}
if ( V_327 -> V_45 . V_225 & ~ ( V_264 | V_361 ) ) {
F_156 ( L_58 ,
V_327 -> V_45 . V_225 ) ;
return - V_263 ;
}
F_205 ( & V_243 , & V_244 , V_327 , 1 ) ;
V_256 = F_211 ( & V_243 , & V_244 , V_327 , 1 ) ;
V_327 -> V_352 . V_256 = V_256 ;
V_327 -> V_352 . V_243 = V_243 * V_279 + V_337 % V_279 ;
V_327 -> V_352 . V_244 = V_244 * V_280 + V_338 % V_280 ;
return 0 ;
}
int F_255 ( struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
int V_278 ;
if ( ! V_327 -> V_45 . V_328 )
return 0 ;
if ( F_175 ( V_225 ) )
F_222 ( & V_327 -> V_45 . V_345 ,
V_70 -> V_222 << 16 , V_70 -> V_218 << 16 ,
V_291 ) ;
if ( V_70 -> V_207 -> V_207 == V_362 ) {
V_278 = F_253 ( V_327 ) ;
if ( V_278 )
return V_278 ;
} else if ( V_70 -> V_208 == V_211 ||
V_70 -> V_208 == V_213 ) {
V_278 = F_254 ( V_327 ) ;
if ( V_278 )
return V_278 ;
} else {
V_327 -> V_352 . V_256 = ~ 0xfff ;
V_327 -> V_352 . V_243 = 0 ;
V_327 -> V_352 . V_244 = 0 ;
}
V_278 = F_250 ( V_327 ) ;
if ( V_278 )
return V_278 ;
return 0 ;
}
static T_1 F_256 ( const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
T_1 V_363 ;
V_363 = V_112 | V_364 ;
if ( F_93 ( V_2 ) || F_15 ( V_2 ) ||
F_257 ( V_2 ) || F_258 ( V_2 ) )
V_363 |= V_365 ;
if ( F_259 ( V_2 ) || F_260 ( V_2 ) )
V_363 |= V_366 ;
if ( F_52 ( V_2 ) < 4 )
V_363 |= F_261 ( V_46 -> V_75 ) ;
switch ( V_70 -> V_207 -> V_207 ) {
case V_293 :
V_363 |= V_292 ;
break;
case V_295 :
V_363 |= V_294 ;
break;
case V_297 :
V_363 |= V_296 ;
break;
case V_299 :
V_363 |= V_298 ;
break;
case V_301 :
V_363 |= V_300 ;
break;
case V_303 :
V_363 |= V_302 ;
break;
case V_305 :
V_363 |= V_304 ;
break;
default:
F_167 ( V_70 -> V_207 -> V_207 ) ;
return 0 ;
}
if ( F_52 ( V_2 ) >= 4 &&
V_70 -> V_208 == V_210 )
V_363 |= V_367 ;
if ( V_225 & V_361 )
V_363 |= V_368 ;
if ( V_225 & V_369 )
V_363 |= V_370 ;
return V_363 ;
}
int F_262 ( struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
int V_337 = V_327 -> V_45 . V_345 . V_288 >> 16 ;
int V_338 = V_327 -> V_45 . V_345 . y1 >> 16 ;
T_1 V_256 ;
F_205 ( & V_337 , & V_338 , V_327 , 0 ) ;
if ( F_52 ( V_2 ) >= 4 )
V_256 = F_211 ( & V_337 , & V_338 ,
V_327 , 0 ) ;
else
V_256 = 0 ;
if ( ! F_259 ( V_2 ) && ! F_260 ( V_2 ) ) {
unsigned int V_225 = V_327 -> V_45 . V_225 ;
int V_339 = F_251 ( & V_327 -> V_45 . V_345 ) >> 16 ;
int V_340 = F_252 ( & V_327 -> V_45 . V_345 ) >> 16 ;
if ( V_225 & V_361 ) {
V_337 += V_339 - 1 ;
V_338 += V_340 - 1 ;
} else if ( V_225 & V_369 ) {
V_337 += V_339 - 1 ;
}
}
V_327 -> main. V_256 = V_256 ;
V_327 -> main. V_243 = V_337 ;
V_327 -> main. V_244 = V_338 ;
return 0 ;
}
static void F_263 ( struct V_259 * V_69 ,
const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 = F_34 ( V_69 -> V_45 . V_44 ) ;
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
enum V_111 V_111 = V_69 -> V_111 ;
T_1 V_371 ;
T_1 V_363 = V_327 -> V_372 ;
T_3 V_9 = F_83 ( V_111 ) ;
int V_243 = V_327 -> main. V_243 ;
int V_244 = V_327 -> main. V_244 ;
unsigned long V_373 ;
V_371 = F_204 ( V_243 , V_244 , V_327 , 0 ) ;
if ( F_52 ( V_2 ) >= 4 )
V_46 -> V_374 = V_327 -> main. V_256 ;
else
V_46 -> V_374 = V_371 ;
V_46 -> V_375 = V_243 ;
V_46 -> V_376 = V_244 ;
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
if ( F_52 ( V_2 ) < 4 ) {
F_265 ( F_266 ( V_111 ) ,
( ( V_41 -> V_379 - 1 ) << 16 ) |
( V_41 -> V_380 - 1 ) ) ;
F_265 ( F_267 ( V_111 ) , 0 ) ;
} else if ( F_11 ( V_2 ) && V_111 == V_381 ) {
F_265 ( F_268 ( V_111 ) ,
( ( V_41 -> V_379 - 1 ) << 16 ) |
( V_41 -> V_380 - 1 ) ) ;
F_265 ( F_269 ( V_111 ) , 0 ) ;
F_265 ( F_270 ( V_111 ) , 0 ) ;
}
F_265 ( V_9 , V_363 ) ;
F_265 ( F_271 ( V_111 ) , V_70 -> V_242 [ 0 ] ) ;
if ( F_259 ( V_2 ) || F_260 ( V_2 ) ) {
F_265 ( F_272 ( V_111 ) ,
F_238 ( V_327 ) +
V_46 -> V_374 ) ;
F_265 ( F_273 ( V_111 ) , ( V_244 << 16 ) | V_243 ) ;
} else if ( F_52 ( V_2 ) >= 4 ) {
F_265 ( F_272 ( V_111 ) ,
F_238 ( V_327 ) +
V_46 -> V_374 ) ;
F_265 ( F_274 ( V_111 ) , ( V_244 << 16 ) | V_243 ) ;
F_265 ( F_275 ( V_111 ) , V_371 ) ;
} else {
F_265 ( F_276 ( V_111 ) ,
F_238 ( V_327 ) +
V_46 -> V_374 ) ;
}
F_277 ( V_9 ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static void F_279 ( struct V_259 * V_69 ,
struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_69 -> V_45 . V_44 ) ;
enum V_111 V_111 = V_69 -> V_111 ;
unsigned long V_373 ;
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
F_265 ( F_83 ( V_111 ) , 0 ) ;
if ( F_180 ( V_2 ) -> V_229 >= 4 )
F_265 ( F_272 ( V_111 ) , 0 ) ;
else
F_265 ( F_276 ( V_111 ) , 0 ) ;
F_277 ( F_83 ( V_111 ) ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static T_1
F_280 ( const struct V_205 * V_70 , int V_111 )
{
if ( V_70 -> V_208 == V_209 )
return 64 ;
else
return F_165 ( V_70 , V_111 ) ;
}
static void F_281 ( struct V_62 * V_62 , int V_260 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_120 ( F_282 ( V_62 -> V_75 , V_260 ) , 0 ) ;
F_120 ( F_283 ( V_62 -> V_75 , V_260 ) , 0 ) ;
F_120 ( F_284 ( V_62 -> V_75 , V_260 ) , 0 ) ;
}
static void F_285 ( struct V_62 * V_62 )
{
struct V_382 * V_383 ;
int V_113 ;
V_383 = & V_62 -> V_71 -> V_383 ;
for ( V_113 = 0 ; V_113 < V_62 -> V_384 ; V_113 ++ ) {
if ( ! V_383 -> V_385 [ V_113 ] . V_386 )
F_281 ( V_62 , V_113 ) ;
}
}
T_1 F_286 ( const struct V_205 * V_70 , int V_111 ,
unsigned int V_225 )
{
T_1 V_287 ;
if ( V_111 >= V_70 -> V_207 -> V_277 )
return 0 ;
V_287 = F_203 ( V_70 , V_111 , V_225 ) ;
if ( F_175 ( V_225 ) )
V_287 /= F_168 ( V_70 , V_111 ) ;
else
V_287 /= F_280 ( V_70 , V_111 ) ;
return V_287 ;
}
static T_1 F_287 ( T_2 V_274 )
{
switch ( V_274 ) {
case V_293 :
return V_387 ;
case V_297 :
return V_308 ;
case V_301 :
return V_309 | V_388 ;
case V_299 :
return V_309 ;
case V_310 :
return V_309 | V_388 |
V_389 ;
case V_311 :
return V_309 |
V_389 ;
case V_303 :
return V_312 ;
case V_305 :
return V_388 | V_312 ;
case V_390 :
return V_391 | V_392 ;
case V_393 :
return V_391 | V_394 ;
case V_395 :
return V_391 | V_396 ;
case V_397 :
return V_391 | V_398 ;
default:
F_167 ( V_274 ) ;
}
return 0 ;
}
static T_1 F_288 ( V_36 V_255 )
{
switch ( V_255 ) {
case V_209 :
break;
case V_210 :
return V_399 ;
case V_212 :
return V_400 ;
case V_211 :
return V_400 | V_401 ;
case V_214 :
return V_402 ;
case V_213 :
return V_402 | V_401 ;
default:
F_167 ( V_255 ) ;
}
return 0 ;
}
static T_1 F_289 ( unsigned int V_225 )
{
switch ( V_225 ) {
case V_264 :
break;
case V_403 :
return V_404 ;
case V_361 :
return V_405 ;
case V_291 :
return V_406 ;
default:
F_167 ( V_225 ) ;
}
return 0 ;
}
T_1 F_290 ( const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
const struct V_407 * V_408 = & V_327 -> V_409 ;
T_1 V_410 ;
V_410 = V_118 ;
if ( ! F_291 ( V_2 ) && ! F_292 ( V_2 ) ) {
V_410 |=
V_411 |
V_412 |
V_413 ;
}
V_410 |= F_287 ( V_70 -> V_207 -> V_207 ) ;
V_410 |= F_288 ( V_70 -> V_208 ) ;
V_410 |= F_289 ( V_225 ) ;
if ( V_408 -> V_324 & V_414 )
V_410 |= V_415 ;
else if ( V_408 -> V_324 & V_416 )
V_410 |= V_417 ;
return V_410 ;
}
static void F_293 ( struct V_259 * V_111 ,
const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
enum V_418 V_418 = V_111 -> V_260 ;
enum V_75 V_75 = V_111 -> V_75 ;
T_1 V_410 = V_327 -> V_372 ;
unsigned int V_225 = V_327 -> V_45 . V_225 ;
T_1 V_287 = F_286 ( V_70 , 0 , V_225 ) ;
T_1 V_419 = F_286 ( V_70 , 1 , V_225 ) ;
T_1 V_420 = V_327 -> main. V_256 ;
int V_421 = V_327 -> V_421 ;
int V_337 = V_327 -> main. V_243 ;
int V_338 = V_327 -> main. V_244 ;
int V_339 = F_251 ( & V_327 -> V_45 . V_345 ) >> 16 ;
int V_340 = F_252 ( & V_327 -> V_45 . V_345 ) >> 16 ;
int V_422 = V_327 -> V_45 . V_346 . V_288 ;
int V_423 = V_327 -> V_45 . V_346 . y1 ;
int V_424 = F_251 ( & V_327 -> V_45 . V_346 ) ;
int V_425 = F_252 ( & V_327 -> V_45 . V_346 ) ;
unsigned long V_373 ;
V_339 -- ;
V_340 -- ;
V_424 -- ;
V_425 -- ;
V_46 -> V_374 = V_420 ;
V_46 -> V_375 = V_337 ;
V_46 -> V_376 = V_338 ;
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
if ( F_291 ( V_2 ) || F_292 ( V_2 ) ) {
F_265 ( F_294 ( V_75 , V_418 ) ,
V_426 |
V_427 |
V_428 ) ;
}
F_265 ( F_89 ( V_75 , V_418 ) , V_410 ) ;
F_265 ( F_295 ( V_75 , V_418 ) , ( V_338 << 16 ) | V_337 ) ;
F_265 ( F_296 ( V_75 , V_418 ) , V_287 ) ;
F_265 ( F_297 ( V_75 , V_418 ) , ( V_340 << 16 ) | V_339 ) ;
F_265 ( F_298 ( V_75 , V_418 ) ,
( V_327 -> V_352 . V_256 - V_420 ) | V_419 ) ;
F_265 ( F_299 ( V_75 , V_418 ) ,
( V_327 -> V_352 . V_244 << 16 ) | V_327 -> V_352 . V_243 ) ;
if ( V_421 >= 0 ) {
T_2 V_429 = 0 ;
F_20 ( ! V_424 || ! V_425 ) ;
V_429 = V_430 | F_300 ( V_418 ) |
V_41 -> V_383 . V_385 [ V_421 ] . V_431 ;
F_265 ( F_282 ( V_75 , V_421 ) , V_429 ) ;
F_265 ( F_301 ( V_75 , V_421 ) , 0 ) ;
F_265 ( F_283 ( V_75 , V_421 ) , ( V_422 << 16 ) | V_423 ) ;
F_265 ( F_284 ( V_75 , V_421 ) , ( V_424 << 16 ) | V_425 ) ;
F_265 ( F_302 ( V_75 , V_418 ) , 0 ) ;
} else {
F_265 ( F_302 ( V_75 , V_418 ) , ( V_423 << 16 ) | V_422 ) ;
}
F_265 ( F_303 ( V_75 , V_418 ) ,
F_238 ( V_327 ) + V_420 ) ;
F_277 ( F_303 ( V_75 , V_418 ) ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static void F_304 ( struct V_259 * V_69 ,
struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_69 -> V_45 . V_44 ) ;
enum V_418 V_418 = V_69 -> V_260 ;
enum V_75 V_75 = V_69 -> V_75 ;
unsigned long V_373 ;
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
F_265 ( F_89 ( V_75 , V_418 ) , 0 ) ;
F_265 ( F_303 ( V_75 , V_418 ) , 0 ) ;
F_277 ( F_303 ( V_75 , V_418 ) ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static int
F_305 ( struct V_43 * V_44 ,
struct V_432 * V_24 ,
struct V_433 * V_434 )
{
struct V_23 * V_41 ;
struct V_123 * V_46 ;
int V_113 , V_278 ;
F_306 ( V_44 , V_434 ) ;
F_307 ( F_34 ( V_44 ) ) ;
if ( ! V_24 )
return 0 ;
F_308 (state, crtc, crtc_state, i) {
V_41 -> V_435 = true ;
}
if ( ! F_158 ( F_34 ( V_44 ) ) )
F_309 ( V_24 ) -> V_436 = true ;
V_278 = F_310 ( V_24 , V_434 ) ;
F_20 ( V_278 == - V_437 ) ;
return V_278 ;
}
static bool F_311 ( struct V_1 * V_2 )
{
return F_312 ( V_2 ) &&
F_52 ( V_2 ) < 5 && ! F_93 ( V_2 ) ;
}
void F_313 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_240 ;
struct V_433 * V_434 = & V_2 -> V_438 ;
struct V_432 * V_24 ;
int V_278 ;
if ( ! V_239 . V_439 &&
! F_311 ( V_2 ) )
return;
F_314 ( V_440 , & V_2 -> V_236 . V_324 ) ;
F_315 ( & V_2 -> V_236 . V_441 ) ;
if ( F_316 ( & V_2 -> V_236 . V_237 ) ) {
F_156 ( L_59 ) ;
F_317 ( V_2 ) ;
}
F_2 ( & V_44 -> V_442 . V_443 ) ;
F_318 ( V_434 , 0 ) ;
while ( 1 ) {
V_278 = F_319 ( V_44 , V_434 ) ;
if ( V_278 != - V_437 )
break;
F_320 ( V_434 ) ;
}
V_24 = F_321 ( V_44 , V_434 ) ;
if ( F_191 ( V_24 ) ) {
V_278 = F_243 ( V_24 ) ;
F_123 ( L_60 , V_278 ) ;
return;
}
V_278 = F_322 ( V_44 , V_434 ) ;
if ( V_278 ) {
F_123 ( L_61 , V_278 ) ;
F_323 ( V_24 ) ;
return;
}
V_2 -> V_444 = V_24 ;
V_24 -> V_445 = V_434 ;
}
void F_324 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_240 ;
struct V_433 * V_434 = & V_2 -> V_438 ;
struct V_432 * V_24 = V_2 -> V_444 ;
int V_278 ;
if ( ! V_239 . V_439 &&
! F_311 ( V_2 ) )
return;
if ( ! V_24 )
goto V_446;
V_2 -> V_444 = NULL ;
if ( ! F_311 ( V_2 ) ) {
V_278 = F_305 ( V_44 , V_24 , V_434 ) ;
if ( V_278 )
F_123 ( L_62 , V_278 ) ;
} else {
F_325 ( V_2 ) ;
F_326 ( V_2 ) ;
F_327 ( V_2 ) ;
F_328 ( V_44 ) ;
F_329 ( & V_2 -> V_447 ) ;
if ( V_2 -> V_448 . V_449 )
V_2 -> V_448 . V_449 ( V_2 ) ;
F_330 ( & V_2 -> V_447 ) ;
V_278 = F_305 ( V_44 , V_24 , V_434 ) ;
if ( V_278 )
F_123 ( L_62 , V_278 ) ;
F_331 ( V_2 ) ;
}
F_323 ( V_24 ) ;
V_446:
F_332 ( V_434 ) ;
F_333 ( V_434 ) ;
F_4 ( & V_44 -> V_442 . V_443 ) ;
F_334 ( V_440 , & V_2 -> V_236 . V_324 ) ;
}
static void F_335 ( struct V_62 * V_46 ,
struct V_18 * V_450 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
struct V_18 * V_19 =
F_240 ( V_46 -> V_45 . V_24 ) ;
V_46 -> V_45 . V_431 = V_46 -> V_45 . V_24 -> V_431 ;
F_120 ( F_336 ( V_46 -> V_75 ) ,
( ( V_19 -> V_380 - 1 ) << 16 ) |
( V_19 -> V_379 - 1 ) ) ;
if ( F_52 ( V_2 ) >= 9 ) {
F_285 ( V_46 ) ;
if ( V_19 -> V_451 . V_124 )
F_337 ( V_46 ) ;
} else if ( F_69 ( V_2 ) ) {
if ( V_19 -> V_451 . V_124 )
F_338 ( V_46 ) ;
else if ( V_450 -> V_451 . V_124 )
F_339 ( V_46 , true ) ;
}
}
static void F_340 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
T_3 V_9 ;
T_1 V_452 ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( F_258 ( V_2 ) ) {
V_452 &= ~ V_453 ;
V_452 |= V_453 | V_454 ;
} else {
V_452 &= ~ V_455 ;
V_452 |= V_455 | V_454 ;
}
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( F_102 ( V_2 ) ) {
V_452 &= ~ V_456 ;
V_452 |= V_457 ;
} else {
V_452 &= ~ V_455 ;
V_452 |= V_455 ;
}
F_120 ( V_9 , V_452 | V_458 ) ;
F_121 ( V_9 ) ;
F_122 ( 1000 ) ;
if ( F_258 ( V_2 ) )
F_120 ( V_9 , F_16 ( V_9 ) | V_459 |
V_460 ) ;
}
static void F_341 ( struct V_62 * V_46 ,
const struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
T_3 V_9 ;
T_1 V_452 , V_461 ;
F_342 ( V_2 , V_75 ) ;
V_9 = F_343 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_462 ;
V_452 &= ~ V_463 ;
F_120 ( V_9 , V_452 ) ;
F_16 ( V_9 ) ;
F_122 ( 150 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_464 ;
V_452 |= F_344 ( V_41 -> V_465 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
F_120 ( V_9 , V_452 | V_88 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
F_120 ( V_9 , V_452 | V_89 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
F_120 ( F_345 ( V_75 ) , V_467 ) ;
F_120 ( F_345 ( V_75 ) , V_467 |
V_468 ) ;
V_9 = F_346 ( V_75 ) ;
for ( V_461 = 0 ; V_461 < 5 ; V_461 ++ ) {
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( ( V_452 & V_463 ) ) {
F_156 ( L_64 ) ;
F_120 ( V_9 , V_452 | V_463 ) ;
break;
}
}
if ( V_461 == 5 )
F_123 ( L_65 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_469 ;
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_469 ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
V_9 = F_346 ( V_75 ) ;
for ( V_461 = 0 ; V_461 < 5 ; V_461 ++ ) {
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( V_452 & V_462 ) {
F_120 ( V_9 , V_452 | V_462 ) ;
F_156 ( L_66 ) ;
break;
}
}
if ( V_461 == 5 )
F_123 ( L_67 ) ;
F_156 ( L_68 ) ;
}
static void F_347 ( struct V_62 * V_46 ,
const struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
T_3 V_9 ;
T_1 V_452 , V_113 , V_470 ;
V_9 = F_343 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_462 ;
V_452 &= ~ V_463 ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_464 ;
V_452 |= F_344 ( V_41 -> V_465 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
V_452 &= ~ V_471 ;
V_452 |= V_472 ;
F_120 ( V_9 , V_452 | V_88 ) ;
F_120 ( F_348 ( V_75 ) ,
V_473 | V_474 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( F_102 ( V_2 ) ) {
V_452 &= ~ V_456 ;
V_452 |= V_475 ;
} else {
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
}
F_120 ( V_9 , V_452 | V_89 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
for ( V_113 = 0 ; V_113 < 4 ; V_113 ++ ) {
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_471 ;
V_452 |= V_476 [ V_113 ] ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 500 ) ;
for ( V_470 = 0 ; V_470 < 5 ; V_470 ++ ) {
V_9 = F_346 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( V_452 & V_463 ) {
F_120 ( V_9 , V_452 | V_463 ) ;
F_156 ( L_64 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_470 < 5 )
break;
}
if ( V_113 == 4 )
F_123 ( L_65 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_469 ;
if ( F_257 ( V_2 ) ) {
V_452 &= ~ V_471 ;
V_452 |= V_472 ;
}
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( F_102 ( V_2 ) ) {
V_452 &= ~ V_456 ;
V_452 |= V_477 ;
} else {
V_452 &= ~ V_455 ;
V_452 |= V_469 ;
}
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
for ( V_113 = 0 ; V_113 < 4 ; V_113 ++ ) {
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_471 ;
V_452 |= V_476 [ V_113 ] ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 500 ) ;
for ( V_470 = 0 ; V_470 < 5 ; V_470 ++ ) {
V_9 = F_346 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( V_452 & V_462 ) {
F_120 ( V_9 , V_452 | V_462 ) ;
F_156 ( L_66 ) ;
break;
}
F_122 ( 50 ) ;
}
if ( V_470 < 5 )
break;
}
if ( V_113 == 4 )
F_123 ( L_67 ) ;
F_156 ( L_69 ) ;
}
static void F_349 ( struct V_62 * V_46 ,
const struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
T_3 V_9 ;
T_1 V_452 , V_113 , V_478 ;
V_9 = F_343 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_462 ;
V_452 &= ~ V_463 ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 150 ) ;
F_156 ( L_70 ,
F_16 ( F_346 ( V_75 ) ) ) ;
for ( V_478 = 0 ; V_478 < F_173 ( V_476 ) * 2 ; V_478 ++ ) {
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ ( V_479 | V_453 ) ;
V_452 &= ~ V_88 ;
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_479 ;
V_452 &= ~ V_456 ;
V_452 &= ~ V_89 ;
F_120 ( V_9 , V_452 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_464 ;
V_452 |= F_344 ( V_41 -> V_465 ) ;
V_452 |= V_480 ;
V_452 &= ~ V_471 ;
V_452 |= V_476 [ V_478 / 2 ] ;
V_452 |= V_481 ;
F_120 ( V_9 , V_452 | V_88 ) ;
F_120 ( F_348 ( V_75 ) ,
V_473 | V_474 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 |= V_475 ;
V_452 |= V_481 ;
F_120 ( V_9 , V_452 | V_89 ) ;
F_121 ( V_9 ) ;
F_122 ( 1 ) ;
for ( V_113 = 0 ; V_113 < 4 ; V_113 ++ ) {
V_9 = F_346 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( V_452 & V_463 ||
( F_16 ( V_9 ) & V_463 ) ) {
F_120 ( V_9 , V_452 | V_463 ) ;
F_156 ( L_71 ,
V_113 ) ;
break;
}
F_122 ( 1 ) ;
}
if ( V_113 == 4 ) {
F_156 ( L_72 , V_478 / 2 ) ;
continue;
}
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_453 ;
V_452 |= V_482 ;
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_456 ;
V_452 |= V_477 ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 2 ) ;
for ( V_113 = 0 ; V_113 < 4 ; V_113 ++ ) {
V_9 = F_346 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_156 ( L_63 , V_452 ) ;
if ( V_452 & V_462 ||
( F_16 ( V_9 ) & V_462 ) ) {
F_120 ( V_9 , V_452 | V_462 ) ;
F_156 ( L_73 ,
V_113 ) ;
goto V_483;
}
F_122 ( 2 ) ;
}
if ( V_113 == 4 )
F_156 ( L_74 , V_478 / 2 ) ;
}
V_483:
F_156 ( L_69 ) ;
}
static void F_350 ( struct V_62 * V_62 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_62 -> V_75 ;
T_3 V_9 ;
T_1 V_452 ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ ( V_464 | ( 0x7 << 16 ) ) ;
V_452 |= F_344 ( V_62 -> V_71 -> V_465 ) ;
V_452 |= ( F_16 ( F_53 ( V_75 ) ) & V_186 ) << 11 ;
F_120 ( V_9 , V_452 | V_91 ) ;
F_121 ( V_9 ) ;
F_122 ( 200 ) ;
V_452 = F_16 ( V_9 ) ;
F_120 ( V_9 , V_452 | V_484 ) ;
F_121 ( V_9 ) ;
F_122 ( 200 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( ( V_452 & V_90 ) == 0 ) {
F_120 ( V_9 , V_452 | V_90 ) ;
F_121 ( V_9 ) ;
F_122 ( 100 ) ;
}
}
static void F_351 ( struct V_62 * V_62 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_62 -> V_75 ;
T_3 V_9 ;
T_1 V_452 ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_120 ( V_9 , V_452 & ~ V_484 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_120 ( V_9 , V_452 & ~ V_90 ) ;
F_121 ( V_9 ) ;
F_122 ( 100 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_120 ( V_9 , V_452 & ~ V_91 ) ;
F_121 ( V_9 ) ;
F_122 ( 100 ) ;
}
static void F_352 ( struct V_123 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
T_3 V_9 ;
T_1 V_452 ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
F_120 ( V_9 , V_452 & ~ V_88 ) ;
F_121 ( V_9 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ ( 0x7 << 16 ) ;
V_452 |= ( F_16 ( F_53 ( V_75 ) ) & V_186 ) << 11 ;
F_120 ( V_9 , V_452 & ~ V_89 ) ;
F_121 ( V_9 ) ;
F_122 ( 100 ) ;
if ( F_116 ( V_2 ) )
F_120 ( F_345 ( V_75 ) , V_467 ) ;
V_9 = F_63 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
F_120 ( V_9 , V_452 ) ;
V_9 = F_65 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
if ( F_102 ( V_2 ) ) {
V_452 &= ~ V_456 ;
V_452 |= V_475 ;
} else {
V_452 &= ~ V_455 ;
V_452 |= V_466 ;
}
V_452 &= ~ ( 0x07 << 16 ) ;
V_452 |= ( F_16 ( F_53 ( V_75 ) ) & V_186 ) << 11 ;
F_120 ( V_9 , V_452 ) ;
F_121 ( V_9 ) ;
F_122 ( 100 ) ;
}
bool F_353 ( struct V_1 * V_2 )
{
struct V_123 * V_46 ;
bool V_485 ;
F_354 (crtc, &dev_priv->drm) {
struct V_486 * V_487 ;
F_355 ( & V_46 -> V_488 ) ;
V_487 = F_356 ( & V_46 -> V_489 ,
struct V_486 , V_490 ) ;
V_485 = V_487 ?
F_357 ( & V_487 -> V_485 ) : true ;
F_358 ( & V_46 -> V_488 ) ;
if ( V_485 )
continue;
F_359 ( V_46 ) ;
return true ;
}
return false ;
}
void F_360 ( struct V_1 * V_2 )
{
T_1 V_452 ;
F_120 ( V_491 , V_492 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_452 = F_361 ( V_2 , V_493 , V_494 ) ;
V_452 |= V_495 ;
F_362 ( V_2 , V_493 , V_452 , V_494 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_363 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
int clock = V_46 -> V_71 -> V_45 . V_72 . V_73 ;
T_1 V_496 , V_497 , V_498 , V_499 = 0 ;
T_1 V_452 ;
F_360 ( V_2 ) ;
for ( V_498 = 0 ; V_498 < 2 ; V_498 ++ ) {
T_1 V_500 = 172800 * 1000 ;
T_1 V_501 = 64 ;
T_1 V_502 ;
V_502 = F_7 ( V_500 ,
clock << V_498 ) ;
V_496 = ( V_502 / V_501 ) - 2 ;
V_497 = V_502 % V_501 ;
if ( V_496 <= 0x7f )
break;
}
F_20 ( F_364 ( V_496 ) &
~ V_503 ) ;
F_20 ( F_365 ( V_499 ) &
~ V_504 ) ;
F_156 ( L_75 ,
clock ,
V_498 ,
V_496 ,
V_499 ,
V_497 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_452 = F_361 ( V_2 , V_505 , V_494 ) ;
V_452 &= ~ V_503 ;
V_452 |= F_364 ( V_496 ) ;
V_452 &= ~ V_504 ;
V_452 |= F_366 ( V_497 ) ;
V_452 |= F_365 ( V_499 ) ;
V_452 |= V_506 ;
F_362 ( V_2 , V_505 , V_452 , V_494 ) ;
V_452 = F_361 ( V_2 , V_507 , V_494 ) ;
V_452 &= ~ F_367 ( 1 ) ;
V_452 |= F_367 ( V_498 ) ;
F_362 ( V_2 , V_507 , V_452 , V_494 ) ;
V_452 = F_361 ( V_2 , V_493 , V_494 ) ;
V_452 &= ~ V_495 ;
F_362 ( V_2 , V_493 , V_452 , V_494 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_122 ( 24 ) ;
F_120 ( V_491 , V_508 ) ;
}
int F_368 ( struct V_1 * V_2 )
{
T_1 V_496 , V_497 , V_498 ;
T_1 V_500 = 172800 * 1000 ;
T_1 V_501 = 64 ;
T_1 V_502 ;
T_1 V_452 ;
if ( ( F_16 ( V_491 ) & V_508 ) == 0 )
return 0 ;
F_2 ( & V_2 -> V_5 ) ;
V_452 = F_361 ( V_2 , V_493 , V_494 ) ;
if ( V_452 & V_495 ) {
F_4 ( & V_2 -> V_5 ) ;
return 0 ;
}
V_452 = F_361 ( V_2 , V_505 , V_494 ) ;
V_496 = ( V_452 & V_503 ) >>
V_509 ;
V_497 = ( V_452 & V_504 ) >>
V_510 ;
V_452 = F_361 ( V_2 , V_507 , V_494 ) ;
V_498 = ( V_452 & V_511 ) >>
V_512 ;
F_4 ( & V_2 -> V_5 ) ;
V_502 = ( V_496 + 2 ) * V_501 + V_497 ;
return F_7 ( V_500 ,
V_502 << V_498 ) ;
}
static void F_369 ( struct V_62 * V_46 ,
enum V_75 V_513 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_74 V_76 = V_46 -> V_71 -> V_76 ;
F_120 ( F_370 ( V_513 ) ,
F_16 ( F_371 ( V_76 ) ) ) ;
F_120 ( F_372 ( V_513 ) ,
F_16 ( F_373 ( V_76 ) ) ) ;
F_120 ( F_374 ( V_513 ) ,
F_16 ( F_375 ( V_76 ) ) ) ;
F_120 ( F_376 ( V_513 ) ,
F_16 ( F_377 ( V_76 ) ) ) ;
F_120 ( F_378 ( V_513 ) ,
F_16 ( F_379 ( V_76 ) ) ) ;
F_120 ( F_380 ( V_513 ) ,
F_16 ( F_381 ( V_76 ) ) ) ;
F_120 ( F_382 ( V_513 ) ,
F_16 ( F_383 ( V_76 ) ) ) ;
}
static void F_384 ( struct V_43 * V_44 , bool V_514 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_2 V_452 ;
V_452 = F_16 ( V_515 ) ;
if ( ! ! ( V_452 & V_516 ) == V_514 )
return;
F_20 ( F_16 ( F_65 ( V_101 ) ) & V_89 ) ;
F_20 ( F_16 ( F_65 ( V_360 ) ) & V_89 ) ;
V_452 &= ~ V_516 ;
if ( V_514 )
V_452 |= V_516 ;
F_156 ( L_76 , V_514 ? L_77 : L_78 ) ;
F_120 ( V_515 , V_452 ) ;
F_121 ( V_515 ) ;
}
static void F_385 ( struct V_62 * V_62 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
switch ( V_62 -> V_75 ) {
case V_94 :
break;
case V_101 :
if ( V_62 -> V_71 -> V_465 > 2 )
F_384 ( V_44 , false ) ;
else
F_384 ( V_44 , true ) ;
break;
case V_360 :
F_384 ( V_44 , true ) ;
break;
default:
F_141 () ;
}
}
static enum V_156
F_386 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_517 * V_518 ;
F_387 (dev, &crtc->base, encoder) {
if ( V_518 -> type == V_519 ||
V_518 -> type == V_520 )
return F_388 ( & V_518 -> V_45 ) -> V_156 ;
}
return - 1 ;
}
static void F_389 ( const struct V_18 * V_41 )
{
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
T_1 V_452 ;
F_99 ( V_2 , V_75 ) ;
if ( F_258 ( V_2 ) )
F_385 ( V_46 ) ;
F_120 ( F_390 ( V_75 ) ,
F_16 ( F_391 ( V_75 ) ) & V_521 ) ;
V_2 -> V_448 . V_522 ( V_46 , V_41 ) ;
if ( F_102 ( V_2 ) ) {
T_1 V_523 ;
V_452 = F_16 ( V_524 ) ;
V_452 |= F_392 ( V_75 ) ;
V_523 = F_393 ( V_75 ) ;
if ( V_41 -> V_184 ==
F_394 ( V_2 , V_525 ) )
V_452 |= V_523 ;
else
V_452 &= ~ V_523 ;
F_120 ( V_524 , V_452 ) ;
}
F_395 ( V_46 ) ;
F_68 ( V_2 , V_75 ) ;
F_369 ( V_46 , V_75 ) ;
F_340 ( V_46 ) ;
if ( F_102 ( V_2 ) &&
F_396 ( V_41 ) ) {
const struct V_526 * V_72 =
& V_41 -> V_45 . V_72 ;
T_1 V_527 = ( F_16 ( F_53 ( V_75 ) ) & V_186 ) >> 5 ;
T_3 V_9 = F_103 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ ( V_128 |
V_528 |
V_529 ) ;
V_452 |= V_530 ;
V_452 |= V_527 << 9 ;
if ( V_72 -> V_324 & V_531 )
V_452 |= V_532 ;
if ( V_72 -> V_324 & V_533 )
V_452 |= V_534 ;
switch ( F_386 ( V_46 ) ) {
case V_176 :
V_452 |= V_143 ;
break;
case V_178 :
V_452 |= V_145 ;
break;
case V_180 :
V_452 |= V_147 ;
break;
default:
F_141 () ;
}
F_120 ( V_9 , V_452 ) ;
}
F_143 ( V_2 , V_75 ) ;
}
static void F_397 ( const struct V_18 * V_41 )
{
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_74 V_76 = V_41 -> V_76 ;
F_99 ( V_2 , V_94 ) ;
F_363 ( V_46 ) ;
F_369 ( V_46 , V_94 ) ;
F_148 ( V_2 , V_76 ) ;
}
static void F_398 ( struct V_43 * V_44 , int V_75 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_3 V_535 = F_48 ( V_75 ) ;
T_1 V_452 ;
V_452 = F_16 ( V_535 ) ;
F_122 ( 500 ) ;
if ( F_55 ( F_16 ( V_535 ) != V_452 , 5 ) ) {
if ( F_55 ( F_16 ( V_535 ) != V_452 , 5 ) )
F_123 ( L_79 , F_72 ( V_75 ) ) ;
}
}
static int
F_399 ( struct V_18 * V_41 , bool V_536 ,
unsigned int V_537 , int * V_421 ,
int V_339 , int V_340 , int V_424 , int V_425 )
{
struct V_382 * V_383 =
& V_41 -> V_383 ;
struct V_62 * V_62 =
F_41 ( V_41 -> V_45 . V_46 ) ;
struct V_1 * V_2 = F_34 ( V_62 -> V_45 . V_44 ) ;
const struct V_526 * V_72 =
& V_41 -> V_45 . V_72 ;
int V_538 ;
V_538 = V_339 != V_424 || V_340 != V_425 ;
if ( V_41 -> V_539 && V_537 == V_540 )
V_538 = true ;
if ( F_52 ( V_2 ) >= 9 && V_41 -> V_45 . V_514 &&
V_538 && V_72 -> V_324 & V_541 ) {
F_156 ( L_80 ) ;
return - V_263 ;
}
if ( V_536 || ! V_538 ) {
if ( * V_421 >= 0 ) {
V_383 -> V_542 &= ~ ( 1 << V_537 ) ;
V_383 -> V_385 [ * V_421 ] . V_386 = 0 ;
F_156 ( L_81
L_82 ,
V_62 -> V_75 , V_537 , * V_421 ,
V_383 -> V_542 ) ;
* V_421 = - 1 ;
}
return 0 ;
}
if ( V_339 < V_543 || V_340 < V_544 ||
V_424 < V_545 || V_425 < V_546 ||
V_339 > V_547 || V_340 > V_548 ||
V_424 > V_549 || V_425 > V_550 ) {
F_156 ( L_83
L_84 ,
V_62 -> V_75 , V_537 , V_339 , V_340 , V_424 , V_425 ) ;
return - V_263 ;
}
V_383 -> V_542 |= ( 1 << V_537 ) ;
F_156 ( L_81
L_85 ,
V_62 -> V_75 , V_537 , V_339 , V_340 , V_424 , V_425 ,
V_383 -> V_542 ) ;
return 0 ;
}
int F_400 ( struct V_18 * V_24 )
{
const struct V_526 * V_72 = & V_24 -> V_45 . V_72 ;
return F_399 ( V_24 , ! V_24 -> V_45 . V_68 , V_540 ,
& V_24 -> V_383 . V_421 ,
V_24 -> V_380 , V_24 -> V_379 ,
V_72 -> V_551 , V_72 -> V_552 ) ;
}
static int F_401 ( struct V_18 * V_41 ,
struct V_245 * V_327 )
{
struct V_259 * V_259 =
F_212 ( V_327 -> V_45 . V_111 ) ;
struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
int V_278 ;
bool V_536 = ! V_70 || ! V_327 -> V_45 . V_328 ;
V_278 = F_399 ( V_41 , V_536 ,
F_233 ( & V_259 -> V_45 ) ,
& V_327 -> V_421 ,
F_251 ( & V_327 -> V_45 . V_345 ) >> 16 ,
F_252 ( & V_327 -> V_45 . V_345 ) >> 16 ,
F_251 ( & V_327 -> V_45 . V_346 ) ,
F_252 ( & V_327 -> V_45 . V_346 ) ) ;
if ( V_278 || V_327 -> V_421 < 0 )
return V_278 ;
if ( V_327 -> V_409 . V_324 != V_553 ) {
F_156 ( L_86 ,
V_259 -> V_45 . V_45 . V_260 ,
V_259 -> V_45 . V_8 ) ;
return - V_263 ;
}
switch ( V_70 -> V_207 -> V_207 ) {
case V_297 :
case V_301 :
case V_299 :
case V_310 :
case V_311 :
case V_303 :
case V_305 :
case V_390 :
case V_393 :
case V_395 :
case V_397 :
break;
default:
F_156 ( L_87 ,
V_259 -> V_45 . V_45 . V_260 , V_259 -> V_45 . V_8 ,
V_70 -> V_45 . V_260 , V_70 -> V_207 -> V_207 ) ;
return - V_263 ;
}
return 0 ;
}
static void F_402 ( struct V_62 * V_46 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_46 -> V_384 ; V_113 ++ )
F_281 ( V_46 , V_113 ) ;
}
static void F_337 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
struct V_382 * V_383 =
& V_46 -> V_71 -> V_383 ;
if ( V_46 -> V_71 -> V_451 . V_124 ) {
int V_260 ;
if ( F_20 ( V_46 -> V_71 -> V_383 . V_421 < 0 ) )
return;
V_260 = V_383 -> V_421 ;
F_120 ( F_282 ( V_75 , V_260 ) , V_430 |
V_554 | V_383 -> V_385 [ V_260 ] . V_431 ) ;
F_120 ( F_283 ( V_75 , V_260 ) , V_46 -> V_71 -> V_451 . V_555 ) ;
F_120 ( F_284 ( V_75 , V_260 ) , V_46 -> V_71 -> V_451 . V_221 ) ;
}
}
static void F_338 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
if ( V_46 -> V_71 -> V_451 . V_124 ) {
if ( F_258 ( V_2 ) || F_259 ( V_2 ) )
F_120 ( F_403 ( V_75 ) , V_556 | V_557 |
F_404 ( V_75 ) ) ;
else
F_120 ( F_403 ( V_75 ) , V_556 | V_557 ) ;
F_120 ( F_405 ( V_75 ) , V_46 -> V_71 -> V_451 . V_555 ) ;
F_120 ( F_406 ( V_75 ) , V_46 -> V_71 -> V_451 . V_221 ) ;
}
}
void F_407 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
if ( ! V_46 -> V_71 -> V_558 )
return;
F_408 ( V_2 , V_46 -> V_111 ) ;
if ( F_260 ( V_2 ) ) {
F_2 ( & V_2 -> V_559 . V_560 ) ;
F_20 ( F_409 ( V_2 , V_561 , 0xc0000000 ) ) ;
F_4 ( & V_2 -> V_559 . V_560 ) ;
} else {
F_120 ( V_562 , V_563 ) ;
if ( F_54 ( V_2 ,
V_562 , V_563 , V_563 ,
50 ) )
F_123 ( L_88 ) ;
}
}
void F_410 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
if ( ! V_46 -> V_71 -> V_558 )
return;
F_408 ( V_2 , V_46 -> V_111 ) ;
if ( F_260 ( V_2 ) ) {
F_2 ( & V_2 -> V_559 . V_560 ) ;
F_20 ( F_409 ( V_2 , V_561 , 0 ) ) ;
F_4 ( & V_2 -> V_559 . V_560 ) ;
if ( F_54 ( V_2 ,
V_562 , V_563 , 0 ,
42 ) )
F_123 ( L_89 ) ;
} else {
F_120 ( V_562 , 0 ) ;
F_121 ( V_562 ) ;
}
F_411 ( V_2 , V_46 -> V_75 ) ;
}
static void F_412 ( struct V_62 * V_62 )
{
if ( V_62 -> V_564 ) {
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
F_2 ( & V_44 -> V_235 ) ;
( void ) F_413 ( V_62 -> V_564 ) ;
F_4 ( & V_44 -> V_235 ) ;
}
}
static void
F_414 ( struct V_123 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
F_407 ( V_62 ) ;
if ( F_49 ( V_2 ) )
F_415 ( V_2 , V_75 , true ) ;
F_416 ( V_2 ) ;
F_417 ( V_2 ) ;
}
static void
F_418 ( struct V_123 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
if ( F_49 ( V_2 ) )
F_415 ( V_2 , V_75 , false ) ;
F_410 ( V_62 ) ;
}
static void
F_241 ( struct V_123 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
F_418 ( V_46 ) ;
if ( F_158 ( V_2 ) &&
F_419 ( V_2 , false ) )
F_411 ( V_2 , V_75 ) ;
}
static void F_420 ( struct V_18 * V_450 )
{
struct V_62 * V_46 = F_41 ( V_450 -> V_45 . V_46 ) ;
struct V_432 * V_565 = V_450 -> V_45 . V_24 ;
struct V_18 * V_19 =
F_240 ( V_46 -> V_45 . V_24 ) ;
struct V_332 * V_69 = V_46 -> V_45 . V_69 ;
struct V_333 * V_566 =
F_421 ( V_565 , V_69 ) ;
F_422 ( F_34 ( V_46 -> V_45 . V_44 ) , V_19 -> V_567 ) ;
if ( V_19 -> V_568 && V_19 -> V_45 . V_68 )
F_423 ( V_46 ) ;
if ( V_566 ) {
struct V_245 * V_569 =
F_235 ( V_69 -> V_24 ) ;
struct V_245 * V_570 =
F_235 ( V_566 ) ;
F_424 ( V_46 ) ;
if ( V_569 -> V_45 . V_328 &&
( F_17 ( & V_19 -> V_45 ) ||
! V_570 -> V_45 . V_328 ) )
F_414 ( & V_46 -> V_45 ) ;
}
}
static void F_425 ( struct V_18 * V_450 ,
struct V_18 * V_19 )
{
struct V_62 * V_46 = F_41 ( V_450 -> V_45 . V_46 ) ;
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_432 * V_565 = V_450 -> V_45 . V_24 ;
struct V_332 * V_69 = V_46 -> V_45 . V_69 ;
struct V_333 * V_566 =
F_421 ( V_565 , V_69 ) ;
bool V_571 = F_17 ( & V_19 -> V_45 ) ;
struct V_572 * V_573 =
F_309 ( V_565 ) ;
if ( V_566 ) {
struct V_245 * V_569 =
F_235 ( V_69 -> V_24 ) ;
struct V_245 * V_570 =
F_235 ( V_566 ) ;
F_426 ( V_46 , V_19 , V_569 ) ;
if ( V_570 -> V_45 . V_328 &&
( V_571 || ! V_569 -> V_45 . V_328 ) )
F_418 ( & V_46 -> V_45 ) ;
}
if ( F_158 ( V_2 ) && V_450 -> V_45 . V_68 &&
V_19 -> V_574 && F_419 ( V_2 , false ) )
F_411 ( V_2 , V_46 -> V_75 ) ;
if ( V_19 -> V_575 && F_427 ( V_44 ) )
F_411 ( V_2 , V_46 -> V_75 ) ;
if ( F_17 ( & V_19 -> V_45 ) )
return;
if ( V_2 -> V_448 . V_576 != NULL )
V_2 -> V_448 . V_576 ( V_573 ,
V_19 ) ;
else if ( V_19 -> V_577 )
F_423 ( V_46 ) ;
}
static void F_428 ( struct V_123 * V_46 , unsigned V_329 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_332 * V_29 ;
int V_75 = V_62 -> V_75 ;
F_412 ( V_62 ) ;
F_429 (p, dev, plane_mask)
F_212 ( V_29 ) -> V_336 ( F_212 ( V_29 ) , V_62 ) ;
F_422 ( F_34 ( V_44 ) , F_430 ( V_75 ) ) ;
}
static void F_431 ( struct V_123 * V_46 ,
struct V_18 * V_41 ,
struct V_432 * V_565 )
{
struct V_578 * V_579 ;
struct V_580 * V_581 ;
int V_113 ;
F_432 (old_state, conn, conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_579 -> V_582 ) ;
if ( V_579 -> V_46 != V_46 )
continue;
if ( V_518 -> V_583 )
V_518 -> V_583 ( V_518 , V_41 , V_579 ) ;
}
}
static void F_434 ( struct V_123 * V_46 ,
struct V_18 * V_41 ,
struct V_432 * V_565 )
{
struct V_578 * V_579 ;
struct V_580 * V_581 ;
int V_113 ;
F_432 (old_state, conn, conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_579 -> V_582 ) ;
if ( V_579 -> V_46 != V_46 )
continue;
if ( V_518 -> V_584 )
V_518 -> V_584 ( V_518 , V_41 , V_579 ) ;
}
}
static void F_435 ( struct V_123 * V_46 ,
struct V_18 * V_41 ,
struct V_432 * V_565 )
{
struct V_578 * V_579 ;
struct V_580 * V_581 ;
int V_113 ;
F_432 (old_state, conn, conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_579 -> V_582 ) ;
if ( V_579 -> V_46 != V_46 )
continue;
V_518 -> V_514 ( V_518 , V_41 , V_579 ) ;
F_436 ( V_518 , true ) ;
}
}
static void F_437 ( struct V_123 * V_46 ,
struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_578 * V_585 ;
struct V_580 * V_581 ;
int V_113 ;
F_438 (old_state, conn, old_conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_585 -> V_582 ) ;
if ( V_585 -> V_46 != V_46 )
continue;
F_436 ( V_518 , false ) ;
V_518 -> V_586 ( V_518 , V_450 , V_585 ) ;
}
}
static void F_439 ( struct V_123 * V_46 ,
struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_578 * V_585 ;
struct V_580 * V_581 ;
int V_113 ;
F_438 (old_state, conn, old_conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_585 -> V_582 ) ;
if ( V_585 -> V_46 != V_46 )
continue;
if ( V_518 -> V_587 )
V_518 -> V_587 ( V_518 , V_450 , V_585 ) ;
}
}
static void F_440 ( struct V_123 * V_46 ,
struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_578 * V_585 ;
struct V_580 * V_581 ;
int V_113 ;
F_438 (old_state, conn, old_conn_state, i) {
struct V_517 * V_518 =
F_433 ( V_585 -> V_582 ) ;
if ( V_585 -> V_46 != V_46 )
continue;
if ( V_518 -> V_588 )
V_518 -> V_588 ( V_518 , V_450 , V_585 ) ;
}
}
static void F_441 ( struct V_18 * V_19 ,
struct V_432 * V_565 )
{
struct V_123 * V_46 = V_19 -> V_45 . V_46 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
struct V_572 * V_573 =
F_309 ( V_565 ) ;
if ( F_20 ( V_62 -> V_68 ) )
return;
if ( V_62 -> V_71 -> V_199 || F_15 ( V_2 ) )
F_415 ( V_2 , V_75 , false ) ;
if ( V_62 -> V_71 -> V_199 )
F_442 ( V_2 , V_75 , false ) ;
if ( V_62 -> V_71 -> V_199 )
F_443 ( V_62 ) ;
if ( F_396 ( V_62 -> V_71 ) )
F_444 ( V_62 , V_589 ) ;
F_445 ( V_62 ) ;
F_446 ( V_62 ) ;
if ( V_62 -> V_71 -> V_199 ) {
F_447 ( V_62 ,
& V_62 -> V_71 -> V_590 , NULL ) ;
}
F_448 ( V_46 ) ;
V_62 -> V_68 = true ;
F_434 ( V_46 , V_19 , V_565 ) ;
if ( V_62 -> V_71 -> V_199 ) {
F_350 ( V_62 ) ;
} else {
F_150 ( V_2 , V_75 ) ;
F_151 ( V_2 , V_75 ) ;
}
F_338 ( V_62 ) ;
F_449 ( & V_19 -> V_45 ) ;
if ( V_2 -> V_448 . V_576 != NULL )
V_2 -> V_448 . V_576 ( V_573 , V_62 -> V_71 ) ;
F_155 ( V_62 ) ;
if ( V_62 -> V_71 -> V_199 )
F_389 ( V_19 ) ;
F_95 ( V_46 ) ;
F_450 ( V_46 ) ;
F_435 ( V_46 , V_19 , V_565 ) ;
if ( F_102 ( V_2 ) )
F_398 ( V_44 , V_62 -> V_75 ) ;
if ( V_62 -> V_71 -> V_199 )
F_411 ( V_2 , V_75 ) ;
F_415 ( V_2 , V_75 , true ) ;
F_442 ( V_2 , V_75 , true ) ;
}
static bool F_451 ( struct V_62 * V_46 )
{
return F_452 ( F_34 ( V_46 -> V_45 . V_44 ) ) && V_46 -> V_75 == V_94 ;
}
static void F_453 ( struct V_18 * V_19 ,
struct V_432 * V_565 )
{
struct V_123 * V_46 = V_19 -> V_45 . V_46 ;
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 , V_591 ;
enum V_74 V_76 = V_62 -> V_71 -> V_76 ;
struct V_572 * V_573 =
F_309 ( V_565 ) ;
if ( F_20 ( V_62 -> V_68 ) )
return;
if ( V_62 -> V_71 -> V_199 )
F_442 ( V_2 , V_94 , false ) ;
F_431 ( V_46 , V_19 , V_565 ) ;
if ( V_62 -> V_71 -> V_184 )
F_395 ( V_62 ) ;
if ( F_396 ( V_62 -> V_71 ) )
F_444 ( V_62 , V_589 ) ;
if ( ! F_454 ( V_76 ) )
F_445 ( V_62 ) ;
F_446 ( V_62 ) ;
if ( V_76 != V_592 &&
! F_454 ( V_76 ) ) {
F_120 ( F_455 ( V_76 ) ,
V_62 -> V_71 -> V_593 - 1 ) ;
}
if ( V_62 -> V_71 -> V_199 ) {
F_447 ( V_62 ,
& V_62 -> V_71 -> V_590 , NULL ) ;
}
if ( ! F_454 ( V_76 ) )
F_456 ( V_46 ) ;
F_457 ( V_46 ) ;
F_458 ( & V_19 -> V_45 ) ;
V_62 -> V_68 = true ;
if ( V_62 -> V_71 -> V_199 )
F_415 ( V_2 , V_75 , false ) ;
else
F_415 ( V_2 , V_75 , true ) ;
F_434 ( V_46 , V_19 , V_565 ) ;
if ( V_62 -> V_71 -> V_199 )
V_2 -> V_448 . V_522 ( V_62 , V_19 ) ;
if ( ! F_454 ( V_76 ) )
F_459 ( V_19 ) ;
if ( F_52 ( V_2 ) >= 9 )
F_337 ( V_62 ) ;
else
F_338 ( V_62 ) ;
F_449 ( & V_19 -> V_45 ) ;
F_460 ( V_19 ) ;
if ( ! F_454 ( V_76 ) )
F_461 ( V_19 ) ;
if ( V_2 -> V_448 . V_576 != NULL )
V_2 -> V_448 . V_576 ( V_573 , V_19 ) ;
if ( ! F_454 ( V_76 ) )
F_155 ( V_62 ) ;
if ( V_62 -> V_71 -> V_199 )
F_397 ( V_19 ) ;
if ( F_31 ( V_62 -> V_71 , V_594 ) )
F_462 ( V_19 , true ) ;
F_95 ( V_46 ) ;
F_450 ( V_46 ) ;
F_435 ( V_46 , V_19 , V_565 ) ;
if ( V_62 -> V_71 -> V_199 ) {
F_411 ( V_2 , V_75 ) ;
F_411 ( V_2 , V_75 ) ;
F_415 ( V_2 , V_75 , true ) ;
F_442 ( V_2 , V_94 , true ) ;
}
V_591 = V_19 -> V_591 ;
if ( F_259 ( V_2 ) && V_591 != V_595 ) {
F_411 ( V_2 , V_591 ) ;
F_411 ( V_2 , V_591 ) ;
}
}
static void F_339 ( struct V_62 * V_46 , bool V_596 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
if ( V_596 || V_46 -> V_71 -> V_451 . V_124 ) {
F_120 ( F_403 ( V_75 ) , 0 ) ;
F_120 ( F_405 ( V_75 ) , 0 ) ;
F_120 ( F_406 ( V_75 ) , 0 ) ;
}
}
static void F_463 ( struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_123 * V_46 = V_450 -> V_45 . V_46 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
if ( V_62 -> V_71 -> V_199 ) {
F_415 ( V_2 , V_75 , false ) ;
F_442 ( V_2 , V_75 , false ) ;
}
F_437 ( V_46 , V_450 , V_565 ) ;
F_464 ( V_46 ) ;
F_95 ( V_46 ) ;
F_163 ( V_62 ) ;
F_339 ( V_62 , false ) ;
if ( V_62 -> V_71 -> V_199 )
F_352 ( V_46 ) ;
F_439 ( V_46 , V_450 , V_565 ) ;
if ( V_62 -> V_71 -> V_199 ) {
F_149 ( V_2 , V_75 ) ;
if ( F_102 ( V_2 ) ) {
T_3 V_9 ;
T_1 V_452 ;
V_9 = F_103 ( V_75 ) ;
V_452 = F_16 ( V_9 ) ;
V_452 &= ~ ( V_530 |
V_128 ) ;
V_452 |= V_597 ;
F_120 ( V_9 , V_452 ) ;
V_452 = F_16 ( V_524 ) ;
V_452 &= ~ ( F_392 ( V_75 ) | F_393 ( V_75 ) ) ;
F_120 ( V_524 , V_452 ) ;
}
F_351 ( V_62 ) ;
}
F_415 ( V_2 , V_75 , true ) ;
F_442 ( V_2 , V_75 , true ) ;
}
static void F_465 ( struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_123 * V_46 = V_450 -> V_45 . V_46 ;
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_74 V_76 = V_62 -> V_71 -> V_76 ;
if ( V_62 -> V_71 -> V_199 )
F_442 ( V_2 , V_94 , false ) ;
F_437 ( V_46 , V_450 , V_565 ) ;
F_464 ( V_46 ) ;
F_95 ( V_46 ) ;
if ( ! F_454 ( V_76 ) )
F_163 ( V_62 ) ;
if ( F_31 ( V_62 -> V_71 , V_594 ) )
F_462 ( V_62 -> V_71 , false ) ;
if ( ! F_454 ( V_76 ) )
F_466 ( V_2 , V_76 ) ;
if ( F_52 ( V_2 ) >= 9 )
F_402 ( V_62 ) ;
else
F_339 ( V_62 , false ) ;
if ( ! F_454 ( V_76 ) )
F_467 ( V_62 -> V_71 ) ;
F_439 ( V_46 , V_450 , V_565 ) ;
if ( V_450 -> V_199 )
F_442 ( V_2 , V_94 , true ) ;
}
static void F_468 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_18 * V_19 = V_46 -> V_71 ;
if ( ! V_19 -> V_598 . V_599 )
return;
F_20 ( F_16 ( V_600 ) & V_601 ) ;
F_125 ( V_2 , V_46 -> V_75 ) ;
F_120 ( V_602 , V_19 -> V_598 . V_603 ) ;
F_120 ( V_600 , V_19 -> V_598 . V_599 ) ;
F_120 ( F_469 ( V_46 -> V_75 ) , 0 ) ;
}
enum V_108 F_470 ( enum V_156 V_156 )
{
switch ( V_156 ) {
case V_604 :
return V_605 ;
case V_176 :
return V_606 ;
case V_178 :
return V_607 ;
case V_180 :
return V_608 ;
case V_609 :
return V_610 ;
default:
F_167 ( V_156 ) ;
return V_611 ;
}
}
static T_4 F_471 ( struct V_123 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_612 * V_518 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_75 V_75 = V_62 -> V_75 ;
T_4 V_613 ;
enum V_74 V_74 = V_41 -> V_76 ;
if ( ! V_41 -> V_45 . V_68 )
return 0 ;
V_613 = F_232 ( F_472 ( V_75 ) ) ;
V_613 |= F_232 ( F_79 ( V_74 ) ) ;
if ( V_41 -> V_451 . V_124 ||
V_41 -> V_451 . V_614 )
V_613 |= F_473 ( F_474 ( V_75 ) ) ;
F_475 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_517 * V_517 = F_433 ( V_518 ) ;
V_613 |= F_473 ( V_517 -> V_109 ) ;
}
if ( F_14 ( V_2 ) && V_41 -> V_615 )
V_613 |= F_232 ( V_616 ) ;
if ( V_41 -> V_184 )
V_613 |= F_473 ( V_617 ) ;
return V_613 ;
}
static T_4
F_476 ( struct V_123 * V_46 ,
struct V_18 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_108 V_618 ;
T_4 V_619 , V_620 , V_621 ;
V_621 = V_62 -> V_622 ;
V_62 -> V_622 = V_620 =
F_471 ( V_46 , V_41 ) ;
V_619 = V_620 & ~ V_621 ;
F_477 (domain, domains)
F_478 ( V_2 , V_618 ) ;
return V_621 & ~ V_620 ;
}
static void F_479 ( struct V_1 * V_2 ,
T_4 V_619 )
{
enum V_108 V_618 ;
F_477 (domain, domains)
F_81 ( V_2 , V_618 ) ;
}
static void F_480 ( struct V_18 * V_19 ,
struct V_432 * V_565 )
{
struct V_572 * V_573 =
F_309 ( V_565 ) ;
struct V_123 * V_46 = V_19 -> V_45 . V_46 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
if ( F_20 ( V_62 -> V_68 ) )
return;
if ( F_396 ( V_62 -> V_71 ) )
F_444 ( V_62 , V_589 ) ;
F_445 ( V_62 ) ;
F_446 ( V_62 ) ;
if ( F_11 ( V_2 ) && V_75 == V_101 ) {
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_120 ( F_481 ( V_75 ) , V_623 ) ;
F_120 ( F_482 ( V_75 ) , 0 ) ;
}
F_483 ( V_62 ) ;
V_62 -> V_68 = true ;
F_415 ( V_2 , V_75 , true ) ;
F_431 ( V_46 , V_19 , V_565 ) ;
if ( F_11 ( V_2 ) ) {
F_484 ( V_62 , V_62 -> V_71 ) ;
F_132 ( V_62 , V_62 -> V_71 ) ;
} else {
F_485 ( V_62 , V_62 -> V_71 ) ;
F_124 ( V_62 , V_62 -> V_71 ) ;
}
F_434 ( V_46 , V_19 , V_565 ) ;
F_468 ( V_62 ) ;
F_449 ( & V_19 -> V_45 ) ;
V_2 -> V_448 . V_576 ( V_573 ,
V_19 ) ;
F_155 ( V_62 ) ;
F_95 ( V_46 ) ;
F_450 ( V_46 ) ;
F_435 ( V_46 , V_19 , V_565 ) ;
}
static void F_486 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_120 ( F_487 ( V_46 -> V_75 ) , V_46 -> V_71 -> V_152 . V_624 ) ;
F_120 ( F_488 ( V_46 -> V_75 ) , V_46 -> V_71 -> V_152 . V_625 ) ;
}
static void F_489 ( struct V_18 * V_19 ,
struct V_432 * V_565 )
{
struct V_572 * V_573 =
F_309 ( V_565 ) ;
struct V_123 * V_46 = V_19 -> V_45 . V_46 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_75 V_75 = V_62 -> V_75 ;
if ( F_20 ( V_62 -> V_68 ) )
return;
F_486 ( V_62 ) ;
if ( F_396 ( V_62 -> V_71 ) )
F_444 ( V_62 , V_589 ) ;
F_445 ( V_62 ) ;
F_446 ( V_62 ) ;
F_483 ( V_62 ) ;
V_62 -> V_68 = true ;
if ( ! F_49 ( V_2 ) )
F_415 ( V_2 , V_75 , true ) ;
F_434 ( V_46 , V_19 , V_565 ) ;
F_135 ( V_62 ) ;
F_468 ( V_62 ) ;
F_449 ( & V_19 -> V_45 ) ;
if ( V_2 -> V_448 . V_576 != NULL )
V_2 -> V_448 . V_576 ( V_573 ,
V_62 -> V_71 ) ;
else
F_423 ( V_62 ) ;
F_155 ( V_62 ) ;
F_95 ( V_46 ) ;
F_450 ( V_46 ) ;
F_435 ( V_46 , V_19 , V_565 ) ;
}
static void F_490 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
if ( ! V_46 -> V_71 -> V_598 . V_599 )
return;
F_125 ( V_2 , V_46 -> V_75 ) ;
F_12 ( L_90 ,
F_16 ( V_600 ) ) ;
F_120 ( V_600 , 0 ) ;
}
static void F_491 ( struct V_18 * V_450 ,
struct V_432 * V_565 )
{
struct V_123 * V_46 = V_450 -> V_45 . V_46 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
if ( F_49 ( V_2 ) )
F_411 ( V_2 , V_75 ) ;
F_437 ( V_46 , V_450 , V_565 ) ;
F_464 ( V_46 ) ;
F_95 ( V_46 ) ;
F_163 ( V_62 ) ;
F_490 ( V_62 ) ;
F_439 ( V_46 , V_450 , V_565 ) ;
if ( ! F_31 ( V_62 -> V_71 , V_200 ) ) {
if ( F_11 ( V_2 ) )
F_139 ( V_2 , V_75 ) ;
else if ( F_10 ( V_2 ) )
F_138 ( V_2 , V_75 ) ;
else
F_137 ( V_62 ) ;
}
F_440 ( V_46 , V_450 , V_565 ) ;
if ( ! F_49 ( V_2 ) )
F_415 ( V_2 , V_75 , false ) ;
if ( ! V_2 -> V_448 . V_576 )
F_423 ( V_62 ) ;
if ( F_78 ( V_2 ) )
F_492 ( V_2 , V_75 ) ;
}
static void F_493 ( struct V_123 * V_46 ,
struct V_433 * V_434 )
{
struct V_517 * V_518 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
enum V_108 V_618 ;
T_4 V_619 ;
struct V_432 * V_24 ;
struct V_18 * V_41 ;
int V_278 ;
if ( ! V_62 -> V_68 )
return;
if ( V_46 -> V_69 -> V_24 -> V_328 ) {
F_241 ( V_46 ) ;
F_428 ( V_46 , 1 << F_233 ( V_46 -> V_69 ) ) ;
V_46 -> V_69 -> V_24 -> V_328 = false ;
}
V_24 = F_494 ( V_46 -> V_44 ) ;
if ( ! V_24 ) {
F_156 ( L_91 ,
V_46 -> V_45 . V_260 , V_46 -> V_8 ) ;
return;
}
V_24 -> V_445 = V_434 ;
V_41 = F_495 ( V_24 , V_62 ) ;
V_278 = F_496 ( V_24 , V_46 ) ;
F_20 ( F_191 ( V_41 ) || V_278 ) ;
V_2 -> V_448 . V_626 ( V_41 , V_24 ) ;
F_323 ( V_24 ) ;
F_156 ( L_92 ,
V_46 -> V_45 . V_260 , V_46 -> V_8 ) ;
F_20 ( F_497 ( V_46 -> V_24 , NULL ) < 0 ) ;
V_46 -> V_24 -> V_68 = false ;
V_62 -> V_68 = false ;
V_46 -> V_124 = false ;
V_46 -> V_24 -> V_627 = 0 ;
V_46 -> V_24 -> V_628 = 0 ;
F_387 (crtc->dev, crtc, encoder)
V_518 -> V_45 . V_46 = NULL ;
F_498 ( V_62 ) ;
F_423 ( V_62 ) ;
F_499 ( V_62 ) ;
V_619 = V_62 -> V_622 ;
F_477 (domain, domains)
F_81 ( V_2 , V_618 ) ;
V_62 -> V_622 = 0 ;
V_2 -> V_629 &= ~ ( 1 << V_62 -> V_75 ) ;
V_2 -> V_630 [ V_62 -> V_75 ] = 0 ;
}
int F_500 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_432 * V_24 ;
int V_278 ;
V_24 = F_501 ( V_44 ) ;
V_278 = F_502 ( V_24 ) ;
if ( V_278 )
F_123 ( L_61 , V_278 ) ;
else
V_2 -> V_444 = V_24 ;
return V_278 ;
}
void F_503 ( struct V_612 * V_518 )
{
struct V_517 * V_517 = F_433 ( V_518 ) ;
F_504 ( V_518 ) ;
F_236 ( V_517 ) ;
}
static void F_505 ( struct V_23 * V_41 ,
struct V_578 * V_579 )
{
struct V_631 * V_632 = F_506 ( V_579 -> V_632 ) ;
F_156 ( L_93 ,
V_632 -> V_45 . V_45 . V_260 ,
V_632 -> V_45 . V_8 ) ;
if ( V_632 -> V_633 ( V_632 ) ) {
struct V_517 * V_518 = V_632 -> V_518 ;
F_58 ( ! V_41 ,
L_94 ) ;
if ( ! V_41 )
return;
F_58 ( ! V_41 -> V_68 ,
L_95 ) ;
if ( ! V_518 || V_518 -> type == V_594 )
return;
F_58 ( V_579 -> V_582 != & V_518 -> V_45 ,
L_96 ) ;
F_58 ( V_579 -> V_46 != V_518 -> V_45 . V_46 ,
L_97 ) ;
} else {
F_58 ( V_41 && V_41 -> V_68 ,
L_98 ) ;
F_58 ( ! V_41 && V_579 -> V_582 ,
L_99 ) ;
}
}
int F_507 ( struct V_631 * V_632 )
{
struct V_634 * V_579 ;
V_579 = F_508 ( sizeof( * V_579 ) , V_635 ) ;
if ( ! V_579 )
return - V_636 ;
F_509 ( & V_632 -> V_45 ,
& V_579 -> V_45 ) ;
return 0 ;
}
struct V_631 * F_510 ( void )
{
struct V_631 * V_632 ;
V_632 = F_508 ( sizeof *V_632 , V_635 ) ;
if ( ! V_632 )
return NULL ;
if ( F_507 ( V_632 ) < 0 ) {
F_236 ( V_632 ) ;
return NULL ;
}
return V_632 ;
}
bool F_511 ( struct V_631 * V_632 )
{
enum V_75 V_75 = 0 ;
struct V_517 * V_518 = V_632 -> V_518 ;
return V_518 -> V_633 ( V_518 , & V_75 ) ;
}
static int F_512 ( struct V_18 * V_41 )
{
if ( V_41 -> V_45 . V_514 && V_41 -> V_199 )
return V_41 -> V_465 ;
return 0 ;
}
static int F_513 ( struct V_43 * V_44 , enum V_75 V_75 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_432 * V_24 = V_19 -> V_45 . V_24 ;
struct V_62 * V_637 ;
struct V_18 * V_638 ;
F_156 ( L_100 ,
F_72 ( V_75 ) , V_19 -> V_465 ) ;
if ( V_19 -> V_465 > 4 ) {
F_156 ( L_101 ,
F_72 ( V_75 ) , V_19 -> V_465 ) ;
return - V_263 ;
}
if ( F_259 ( V_2 ) || F_260 ( V_2 ) ) {
if ( V_19 -> V_465 > 2 ) {
F_156 ( L_102 ,
V_19 -> V_465 ) ;
return - V_263 ;
} else {
return 0 ;
}
}
if ( F_180 ( V_2 ) -> V_639 == 2 )
return 0 ;
switch ( V_75 ) {
case V_94 :
return 0 ;
case V_101 :
if ( V_19 -> V_465 <= 2 )
return 0 ;
V_637 = F_46 ( V_2 , V_360 ) ;
V_638 =
F_495 ( V_24 , V_637 ) ;
if ( F_191 ( V_638 ) )
return F_243 ( V_638 ) ;
if ( F_512 ( V_638 ) > 0 ) {
F_156 ( L_103 ,
F_72 ( V_75 ) , V_19 -> V_465 ) ;
return - V_263 ;
}
return 0 ;
case V_360 :
if ( V_19 -> V_465 > 2 ) {
F_156 ( L_104 ,
F_72 ( V_75 ) , V_19 -> V_465 ) ;
return - V_263 ;
}
V_637 = F_46 ( V_2 , V_101 ) ;
V_638 =
F_495 ( V_24 , V_637 ) ;
if ( F_191 ( V_638 ) )
return F_243 ( V_638 ) ;
if ( F_512 ( V_638 ) > 2 ) {
F_156 ( L_105 ) ;
return - V_263 ;
}
return 0 ;
default:
F_141 () ;
}
}
static int F_514 ( struct V_62 * V_62 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
const struct V_526 * V_72 = & V_19 -> V_45 . V_72 ;
int V_640 , V_641 , V_642 , V_278 ;
bool V_643 = false ;
V_470:
V_641 = F_13 ( F_34 ( V_44 ) , V_19 ) ;
V_642 = V_72 -> V_73 ;
V_640 = F_515 ( V_642 , V_641 ,
V_19 -> V_644 ) ;
V_19 -> V_465 = V_640 ;
F_516 ( V_19 -> V_644 , V_640 , V_642 ,
V_641 , & V_19 -> V_590 , false ) ;
V_278 = F_513 ( V_44 , V_62 -> V_75 , V_19 ) ;
if ( V_278 == - V_263 && V_19 -> V_644 > 6 * 3 ) {
V_19 -> V_644 -= 2 * 3 ;
F_156 ( L_106 ,
V_19 -> V_644 ) ;
V_643 = true ;
V_19 -> V_645 = true ;
goto V_470;
}
if ( V_643 )
return V_646 ;
return V_278 ;
}
static bool F_517 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_644 > 24 )
return false ;
if ( F_259 ( V_2 ) )
return true ;
return V_19 -> V_647 <=
V_2 -> V_648 * 95 / 100 ;
}
static void F_518 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
V_19 -> V_558 = V_239 . V_649 &&
F_451 ( V_46 ) &&
F_517 ( V_2 , V_19 ) ;
}
static bool F_519 ( const struct V_62 * V_46 )
{
const struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
return F_180 ( V_2 ) -> V_229 < 4 &&
( V_46 -> V_75 == V_94 || F_520 ( V_2 ) ) ;
}
static T_2 F_521 ( const struct V_18 * V_19 )
{
T_2 V_647 ;
V_647 = V_19 -> V_45 . V_72 . V_73 ;
if ( V_19 -> V_451 . V_124 ) {
V_36 V_650 , V_651 , V_652 , V_653 ;
T_2 V_654 = V_19 -> V_451 . V_221 ;
V_650 = V_19 -> V_380 ;
V_651 = V_19 -> V_379 ;
V_652 = ( V_654 >> 16 ) & 0xFFFF ;
V_653 = V_654 & 0xFFFF ;
if ( V_650 < V_652 )
V_650 = V_652 ;
if ( V_651 < V_653 )
V_651 = V_653 ;
if ( F_20 ( ! V_652 || ! V_653 ) )
return V_647 ;
V_647 = F_39 ( ( V_36 ) V_647 * V_650 * V_651 ,
V_652 * V_653 ) ;
}
return V_647 ;
}
static void F_522 ( struct V_18 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 -> V_45 . V_46 -> V_44 ) ;
if ( F_158 ( V_2 ) )
V_41 -> V_647 =
V_41 -> V_45 . V_72 . V_73 ;
else
V_41 -> V_647 =
F_521 ( V_41 ) ;
}
static int F_523 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_526 * V_72 = & V_19 -> V_45 . V_72 ;
int V_655 = V_2 -> V_656 ;
if ( F_52 ( V_2 ) < 4 ) {
V_655 = V_2 -> V_648 * 9 / 10 ;
if ( F_519 ( V_46 ) &&
V_72 -> V_73 > V_655 ) {
V_655 = V_2 -> V_656 ;
V_19 -> V_203 = true ;
}
}
if ( V_72 -> V_73 > V_655 ) {
F_156 ( L_107 ,
V_72 -> V_73 , V_655 ,
F_524 ( V_19 -> V_203 ) ) ;
return - V_263 ;
}
if ( V_19 -> V_539 && V_19 -> V_45 . V_657 ) {
F_156 ( L_108 ) ;
return - V_263 ;
}
if ( ( F_31 ( V_19 , V_47 ) &&
F_32 ( V_44 ) ) || V_19 -> V_203 )
V_19 -> V_380 &= ~ 1 ;
if ( ( F_52 ( V_2 ) > 4 || F_93 ( V_2 ) ) &&
V_72 -> V_658 == V_72 -> V_551 )
return - V_263 ;
F_522 ( V_19 ) ;
if ( F_452 ( V_2 ) )
F_518 ( V_46 , V_19 ) ;
if ( V_19 -> V_199 )
return F_514 ( V_46 , V_19 ) ;
return 0 ;
}
static void
F_525 ( T_2 * V_659 , T_2 * V_660 )
{
while ( * V_659 > V_661 ||
* V_660 > V_661 ) {
* V_659 >>= 1 ;
* V_660 >>= 1 ;
}
}
static void F_526 ( unsigned int V_27 , unsigned int V_32 ,
T_2 * V_662 , T_2 * V_663 ,
bool V_664 )
{
if ( V_664 ) {
while ( ( V_27 & 1 ) == 0 && ( V_32 & 1 ) == 0 ) {
V_27 >>= 1 ;
V_32 >>= 1 ;
}
}
* V_663 = F_527 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_662 = F_39 ( ( V_36 ) V_27 * * V_663 , V_32 ) ;
F_525 ( V_662 , V_663 ) ;
}
void
F_516 ( int V_665 , int V_666 ,
int V_667 , int V_668 ,
struct V_669 * V_670 ,
bool V_664 )
{
V_670 -> V_671 = 64 ;
F_526 ( V_665 * V_667 ,
V_668 * V_666 * 8 ,
& V_670 -> V_672 , & V_670 -> V_673 ,
V_664 ) ;
F_526 ( V_667 , V_668 ,
& V_670 -> V_674 , & V_670 -> V_675 ,
V_664 ) ;
}
static inline bool F_528 ( struct V_1 * V_2 )
{
if ( V_239 . V_676 >= 0 )
return V_239 . V_676 != 0 ;
return V_2 -> V_677 . V_678
&& ! ( V_2 -> V_679 & V_680 ) ;
}
static T_2 F_529 ( struct V_26 * V_26 )
{
return ( 1 << V_26 -> V_32 ) << 16 | V_26 -> V_28 ;
}
static T_2 F_530 ( struct V_26 * V_26 )
{
return V_26 -> V_32 << 16 | V_26 -> V_35 << 8 | V_26 -> V_28 ;
}
static void F_531 ( struct V_62 * V_46 ,
struct V_18 * V_41 ,
struct V_26 * V_681 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
T_1 V_682 , V_683 = 0 ;
if ( F_28 ( V_2 ) ) {
V_682 = F_529 ( & V_41 -> V_26 ) ;
if ( V_681 )
V_683 = F_529 ( V_681 ) ;
} else {
V_682 = F_530 ( & V_41 -> V_26 ) ;
if ( V_681 )
V_683 = F_530 ( V_681 ) ;
}
V_41 -> V_152 . V_624 = V_682 ;
V_46 -> V_684 = false ;
if ( F_31 ( V_41 , V_47 ) &&
V_681 ) {
V_41 -> V_152 . V_625 = V_683 ;
V_46 -> V_684 = true ;
} else {
V_41 -> V_152 . V_625 = V_682 ;
}
}
static void F_532 ( struct V_1 * V_2 , enum V_75
V_75 )
{
T_1 V_685 ;
V_685 = F_129 ( V_2 , V_75 , F_533 ( 1 ) ) ;
V_685 &= 0xffffff00 ;
V_685 |= 0x00000030 ;
F_131 ( V_2 , V_75 , F_533 ( 1 ) , V_685 ) ;
V_685 = F_129 ( V_2 , V_75 , V_686 ) ;
V_685 &= 0x00ffffff ;
V_685 |= 0x8c000000 ;
F_131 ( V_2 , V_75 , V_686 , V_685 ) ;
V_685 = F_129 ( V_2 , V_75 , F_533 ( 1 ) ) ;
V_685 &= 0xffffff00 ;
F_131 ( V_2 , V_75 , F_533 ( 1 ) , V_685 ) ;
V_685 = F_129 ( V_2 , V_75 , V_686 ) ;
V_685 &= 0x00ffffff ;
V_685 |= 0xb0000000 ;
F_131 ( V_2 , V_75 , V_686 , V_685 ) ;
}
static void F_534 ( struct V_62 * V_46 ,
struct V_669 * V_670 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_46 -> V_75 ;
F_120 ( F_535 ( V_75 ) , F_536 ( V_670 -> V_671 ) | V_670 -> V_672 ) ;
F_120 ( F_537 ( V_75 ) , V_670 -> V_673 ) ;
F_120 ( F_538 ( V_75 ) , V_670 -> V_674 ) ;
F_120 ( F_539 ( V_75 ) , V_670 -> V_675 ) ;
}
static void F_447 ( struct V_62 * V_46 ,
struct V_669 * V_670 ,
struct V_669 * V_687 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
int V_75 = V_46 -> V_75 ;
enum V_74 V_74 = V_46 -> V_71 -> V_76 ;
if ( F_52 ( V_2 ) >= 5 ) {
F_120 ( F_391 ( V_74 ) , F_536 ( V_670 -> V_671 ) | V_670 -> V_672 ) ;
F_120 ( F_540 ( V_74 ) , V_670 -> V_673 ) ;
F_120 ( F_541 ( V_74 ) , V_670 -> V_674 ) ;
F_120 ( F_542 ( V_74 ) , V_670 -> V_675 ) ;
if ( V_687 && ( F_11 ( V_2 ) ||
F_52 ( V_2 ) < 8 ) && V_46 -> V_71 -> V_688 ) {
F_120 ( F_543 ( V_74 ) ,
F_536 ( V_687 -> V_671 ) | V_687 -> V_672 ) ;
F_120 ( F_544 ( V_74 ) , V_687 -> V_673 ) ;
F_120 ( F_545 ( V_74 ) , V_687 -> V_674 ) ;
F_120 ( F_546 ( V_74 ) , V_687 -> V_675 ) ;
}
} else {
F_120 ( F_547 ( V_75 ) , F_536 ( V_670 -> V_671 ) | V_670 -> V_672 ) ;
F_120 ( F_548 ( V_75 ) , V_670 -> V_673 ) ;
F_120 ( F_549 ( V_75 ) , V_670 -> V_674 ) ;
F_120 ( F_550 ( V_75 ) , V_670 -> V_675 ) ;
}
}
void F_444 ( struct V_62 * V_46 , enum V_689 V_670 )
{
struct V_669 * V_690 , * V_691 = NULL ;
if ( V_670 == V_589 ) {
V_690 = & V_46 -> V_71 -> V_690 ;
V_691 = & V_46 -> V_71 -> V_691 ;
} else if ( V_670 == V_692 ) {
V_690 = & V_46 -> V_71 -> V_691 ;
} else {
F_123 ( L_109 ) ;
return;
}
if ( V_46 -> V_71 -> V_199 )
F_534 ( V_46 , & V_46 -> V_71 -> V_690 ) ;
else
F_447 ( V_46 , V_690 , V_691 ) ;
}
static void F_551 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
V_19 -> V_152 . V_26 = V_167 |
V_168 | V_163 ;
if ( V_46 -> V_75 != V_94 )
V_19 -> V_152 . V_26 |= V_169 ;
if ( ! F_31 ( V_19 , V_200 ) )
V_19 -> V_152 . V_26 |= V_84 |
V_693 ;
V_19 -> V_152 . V_154 =
( V_19 -> V_593 - 1 ) << V_694 ;
}
static void F_552 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
V_19 -> V_152 . V_26 = V_170 |
V_168 | V_163 ;
if ( V_46 -> V_75 != V_94 )
V_19 -> V_152 . V_26 |= V_169 ;
if ( ! F_31 ( V_19 , V_200 ) )
V_19 -> V_152 . V_26 |= V_84 ;
V_19 -> V_152 . V_154 =
( V_19 -> V_593 - 1 ) << V_694 ;
}
static void F_485 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
T_1 V_695 ;
T_1 V_696 , V_697 , V_698 , V_699 , V_700 ;
T_1 V_701 , V_685 ;
F_120 ( F_57 ( V_75 ) ,
V_19 -> V_152 . V_26 &
~ ( V_84 | V_693 ) ) ;
if ( ( V_19 -> V_152 . V_26 & V_84 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_696 = V_19 -> V_26 . V_32 ;
V_697 = V_19 -> V_26 . V_35 ;
V_698 = V_19 -> V_26 . V_28 ;
V_699 = V_19 -> V_26 . V_30 ;
V_700 = V_19 -> V_26 . V_31 ;
if ( V_75 == V_101 )
F_532 ( V_2 , V_75 ) ;
F_131 ( V_2 , V_75 , V_702 , 0x0100000f ) ;
V_685 = F_129 ( V_2 , V_75 , F_553 ( V_75 ) ) ;
V_685 &= 0x00ffffff ;
F_131 ( V_2 , V_75 , F_553 ( V_75 ) , V_685 ) ;
F_131 ( V_2 , V_75 , V_703 , 0x610 ) ;
V_695 = ( ( V_697 << V_704 ) | ( V_698 & V_705 ) ) ;
V_695 |= ( ( V_699 << V_706 ) | ( V_700 << V_707 ) ) ;
V_695 |= ( ( V_696 << V_708 ) ) ;
V_695 |= ( 1 << V_709 ) ;
V_695 |= ( V_710 << V_711 ) ;
F_131 ( V_2 , V_75 , F_554 ( V_75 ) , V_695 ) ;
V_695 |= V_712 ;
F_131 ( V_2 , V_75 , F_554 ( V_75 ) , V_695 ) ;
if ( V_19 -> V_20 == 162000 ||
F_31 ( V_46 -> V_71 , V_713 ) ||
F_31 ( V_46 -> V_71 , V_187 ) )
F_131 ( V_2 , V_75 , F_555 ( V_75 ) ,
0x009f0003 ) ;
else
F_131 ( V_2 , V_75 , F_555 ( V_75 ) ,
0x00d0000f ) ;
if ( F_396 ( V_19 ) ) {
if ( V_75 == V_94 )
F_131 ( V_2 , V_75 , F_556 ( V_75 ) ,
0x0df40000 ) ;
else
F_131 ( V_2 , V_75 , F_556 ( V_75 ) ,
0x0df70000 ) ;
} else {
if ( V_75 == V_94 )
F_131 ( V_2 , V_75 , F_556 ( V_75 ) ,
0x0df70000 ) ;
else
F_131 ( V_2 , V_75 , F_556 ( V_75 ) ,
0x0df40000 ) ;
}
V_701 = F_129 ( V_2 , V_75 , F_557 ( V_75 ) ) ;
V_701 = ( V_701 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_396 ( V_46 -> V_71 ) )
V_701 |= 0x01000000 ;
F_131 ( V_2 , V_75 , F_557 ( V_75 ) , V_701 ) ;
F_131 ( V_2 , V_75 , F_558 ( V_75 ) , 0x87871000 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_484 ( struct V_62 * V_46 ,
const struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
enum V_155 V_156 = F_128 ( V_75 ) ;
T_1 V_714 , V_715 ;
T_1 V_696 , V_697 , V_698 , V_699 , V_700 , V_716 ;
T_1 V_717 ;
int V_33 ;
F_120 ( F_57 ( V_75 ) ,
V_19 -> V_152 . V_26 & ~ V_84 ) ;
if ( ( V_19 -> V_152 . V_26 & V_84 ) == 0 )
return;
V_696 = V_19 -> V_26 . V_32 ;
V_716 = V_19 -> V_26 . V_28 & 0x3fffff ;
V_697 = V_19 -> V_26 . V_35 ;
V_698 = V_19 -> V_26 . V_28 >> 22 ;
V_699 = V_19 -> V_26 . V_30 ;
V_700 = V_19 -> V_26 . V_31 ;
V_33 = V_19 -> V_26 . V_33 ;
V_717 = 0 ;
V_714 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
F_131 ( V_2 , V_75 , F_559 ( V_156 ) ,
5 << V_718 |
V_699 << V_719 |
V_700 << V_720 |
1 << V_721 ) ;
F_131 ( V_2 , V_75 , F_560 ( V_156 ) , V_698 ) ;
F_131 ( V_2 , V_75 , F_561 ( V_156 ) ,
V_722 |
1 << V_723 ) ;
F_131 ( V_2 , V_75 , F_562 ( V_156 ) , V_716 ) ;
V_717 = F_129 ( V_2 , V_75 , F_563 ( V_156 ) ) ;
V_717 &= ~ ( V_724 | V_725 ) ;
V_717 |= ( 2 << V_726 ) ;
if ( V_716 )
V_717 |= V_725 ;
F_131 ( V_2 , V_75 , F_563 ( V_156 ) , V_717 ) ;
V_717 = F_129 ( V_2 , V_75 , F_564 ( V_156 ) ) ;
V_717 &= ~ ( V_727 |
V_728 ) ;
V_717 |= ( 0x5 << V_729 ) ;
if ( ! V_716 )
V_717 |= V_728 ;
F_131 ( V_2 , V_75 , F_564 ( V_156 ) , V_717 ) ;
if ( V_33 == 5400000 ) {
V_714 |= ( 0x3 << V_730 ) ;
V_714 |= ( 0x8 << V_731 ) ;
V_714 |= ( 0x1 << V_732 ) ;
V_715 = 0x9 ;
} else if ( V_33 <= 6200000 ) {
V_714 |= ( 0x5 << V_730 ) ;
V_714 |= ( 0xB << V_731 ) ;
V_714 |= ( 0x3 << V_732 ) ;
V_715 = 0x9 ;
} else if ( V_33 <= 6480000 ) {
V_714 |= ( 0x4 << V_730 ) ;
V_714 |= ( 0x9 << V_731 ) ;
V_714 |= ( 0x3 << V_732 ) ;
V_715 = 0x8 ;
} else {
V_714 |= ( 0x4 << V_730 ) ;
V_714 |= ( 0x9 << V_731 ) ;
V_714 |= ( 0x3 << V_732 ) ;
V_715 = 0 ;
}
F_131 ( V_2 , V_75 , F_565 ( V_156 ) , V_714 ) ;
V_717 = F_129 ( V_2 , V_75 , F_566 ( V_156 ) ) ;
V_717 &= ~ V_733 ;
V_717 |= ( V_715 << V_734 ) ;
F_131 ( V_2 , V_75 , F_566 ( V_156 ) , V_717 ) ;
F_131 ( V_2 , V_75 , F_130 ( V_156 ) ,
F_129 ( V_2 , V_75 , F_130 ( V_156 ) ) |
V_735 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
int F_567 ( struct V_1 * V_2 , enum V_75 V_75 ,
const struct V_26 * V_26 )
{
struct V_62 * V_46 = F_46 ( V_2 , V_75 ) ;
struct V_18 * V_19 ;
V_19 = F_508 ( sizeof( * V_19 ) , V_635 ) ;
if ( ! V_19 )
return - V_636 ;
V_19 -> V_45 . V_46 = & V_46 -> V_45 ;
V_19 -> V_593 = 1 ;
V_19 -> V_26 = * V_26 ;
if ( F_11 ( V_2 ) ) {
F_552 ( V_46 , V_19 ) ;
F_484 ( V_46 , V_19 ) ;
F_132 ( V_46 , V_19 ) ;
} else {
F_551 ( V_46 , V_19 ) ;
F_485 ( V_46 , V_19 ) ;
F_124 ( V_46 , V_19 ) ;
}
F_236 ( V_19 ) ;
return 0 ;
}
void F_568 ( struct V_1 * V_2 , enum V_75 V_75 )
{
if ( F_11 ( V_2 ) )
F_139 ( V_2 , V_75 ) ;
else
F_138 ( V_2 , V_75 ) ;
}
static void F_569 ( struct V_62 * V_46 ,
struct V_18 * V_41 ,
struct V_26 * V_681 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
T_1 V_26 ;
struct V_26 * clock = & V_41 -> V_26 ;
F_531 ( V_46 , V_41 , V_681 ) ;
V_26 = V_163 ;
if ( F_31 ( V_41 , V_47 ) )
V_26 |= V_736 ;
else
V_26 |= V_737 ;
if ( F_570 ( V_2 ) || F_571 ( V_2 ) ||
F_572 ( V_2 ) || F_28 ( V_2 ) ) {
V_26 |= ( V_41 -> V_593 - 1 )
<< V_738 ;
}
if ( F_31 ( V_41 , V_192 ) ||
F_31 ( V_41 , V_187 ) )
V_26 |= V_739 ;
if ( F_396 ( V_41 ) )
V_26 |= V_739 ;
if ( F_28 ( V_2 ) )
V_26 |= ( 1 << ( clock -> V_30 - 1 ) ) << V_740 ;
else {
V_26 |= ( 1 << ( clock -> V_30 - 1 ) ) << V_741 ;
if ( F_93 ( V_2 ) && V_681 )
V_26 |= ( 1 << ( V_681 -> V_30 - 1 ) ) << V_742 ;
}
switch ( clock -> V_31 ) {
case 5 :
V_26 |= V_743 ;
break;
case 7 :
V_26 |= V_744 ;
break;
case 10 :
V_26 |= V_745 ;
break;
case 14 :
V_26 |= V_746 ;
break;
}
if ( F_52 ( V_2 ) >= 4 )
V_26 |= ( 6 << V_747 ) ;
if ( V_41 -> V_748 )
V_26 |= V_749 ;
else if ( F_31 ( V_41 , V_47 ) &&
F_528 ( V_2 ) )
V_26 |= V_750 ;
else
V_26 |= V_751 ;
V_26 |= V_84 ;
V_41 -> V_152 . V_26 = V_26 ;
if ( F_52 ( V_2 ) >= 4 ) {
T_1 V_154 = ( V_41 -> V_593 - 1 )
<< V_694 ;
V_41 -> V_152 . V_154 = V_154 ;
}
}
static void F_573 ( struct V_62 * V_46 ,
struct V_18 * V_41 ,
struct V_26 * V_681 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_26 ;
struct V_26 * clock = & V_41 -> V_26 ;
F_531 ( V_46 , V_41 , V_681 ) ;
V_26 = V_163 ;
if ( F_31 ( V_41 , V_47 ) ) {
V_26 |= ( 1 << ( clock -> V_30 - 1 ) ) << V_741 ;
} else {
if ( clock -> V_30 == 2 )
V_26 |= V_752 ;
else
V_26 |= ( clock -> V_30 - 2 ) << V_741 ;
if ( clock -> V_31 == 4 )
V_26 |= V_753 ;
}
if ( ! F_78 ( V_2 ) &&
F_31 ( V_41 , V_165 ) )
V_26 |= V_166 ;
if ( F_31 ( V_41 , V_47 ) &&
F_528 ( V_2 ) )
V_26 |= V_750 ;
else
V_26 |= V_751 ;
V_26 |= V_84 ;
V_41 -> V_152 . V_26 = V_26 ;
}
static void F_445 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_34 ( V_62 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_62 -> V_75 ;
enum V_74 V_76 = V_62 -> V_71 -> V_76 ;
const struct V_526 * V_72 = & V_62 -> V_71 -> V_45 . V_72 ;
T_2 V_754 , V_755 ;
int V_756 = 0 ;
V_754 = V_72 -> V_754 ;
V_755 = V_72 -> V_755 ;
if ( V_72 -> V_324 & V_541 ) {
V_754 -= 1 ;
V_755 -= 1 ;
if ( F_31 ( V_62 -> V_71 , V_192 ) )
V_756 = ( V_72 -> V_757 - 1 ) / 2 ;
else
V_756 = V_72 -> V_658 -
V_72 -> V_757 / 2 ;
if ( V_756 < 0 )
V_756 += V_72 -> V_757 ;
}
if ( F_52 ( V_2 ) > 3 )
F_120 ( F_383 ( V_76 ) , V_756 ) ;
F_120 ( F_371 ( V_76 ) ,
( V_72 -> V_551 - 1 ) |
( ( V_72 -> V_757 - 1 ) << 16 ) ) ;
F_120 ( F_373 ( V_76 ) ,
( V_72 -> V_758 - 1 ) |
( ( V_72 -> V_759 - 1 ) << 16 ) ) ;
F_120 ( F_375 ( V_76 ) ,
( V_72 -> V_658 - 1 ) |
( ( V_72 -> V_760 - 1 ) << 16 ) ) ;
F_120 ( F_377 ( V_76 ) ,
( V_72 -> V_552 - 1 ) |
( ( V_754 - 1 ) << 16 ) ) ;
F_120 ( F_379 ( V_76 ) ,
( V_72 -> V_761 - 1 ) |
( ( V_755 - 1 ) << 16 ) ) ;
F_120 ( F_381 ( V_76 ) ,
( V_72 -> V_762 - 1 ) |
( ( V_72 -> V_763 - 1 ) << 16 ) ) ;
if ( F_259 ( V_2 ) && V_76 == V_592 &&
( V_75 == V_101 || V_75 == V_360 ) )
F_120 ( F_377 ( V_75 ) , F_16 ( F_377 ( V_76 ) ) ) ;
}
static void F_446 ( struct V_62 * V_62 )
{
struct V_43 * V_44 = V_62 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 = V_62 -> V_75 ;
F_120 ( F_336 ( V_75 ) ,
( ( V_62 -> V_71 -> V_380 - 1 ) << 16 ) |
( V_62 -> V_71 -> V_379 - 1 ) ) ;
}
static void F_574 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_74 V_76 = V_19 -> V_76 ;
T_2 V_157 ;
V_157 = F_16 ( F_371 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_551 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_757 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_157 = F_16 ( F_373 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_758 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_759 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_157 = F_16 ( F_375 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_658 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_760 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_157 = F_16 ( F_377 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_552 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_754 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_157 = F_16 ( F_379 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_761 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_755 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_157 = F_16 ( F_381 ( V_76 ) ) ;
V_19 -> V_45 . V_72 . V_762 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_45 . V_72 . V_763 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
if ( F_16 ( F_53 ( V_76 ) ) & V_190 ) {
V_19 -> V_45 . V_72 . V_324 |= V_541 ;
V_19 -> V_45 . V_72 . V_754 += 1 ;
V_19 -> V_45 . V_72 . V_755 += 1 ;
}
}
static void F_575 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_157 ;
V_157 = F_16 ( F_336 ( V_46 -> V_75 ) ) ;
V_19 -> V_379 = ( V_157 & 0xffff ) + 1 ;
V_19 -> V_380 = ( ( V_157 >> 16 ) & 0xffff ) + 1 ;
V_19 -> V_45 . V_431 . V_764 = V_19 -> V_379 ;
V_19 -> V_45 . V_431 . V_765 = V_19 -> V_380 ;
}
void F_576 ( struct V_526 * V_431 ,
struct V_18 * V_19 )
{
V_431 -> V_765 = V_19 -> V_45 . V_72 . V_551 ;
V_431 -> V_766 = V_19 -> V_45 . V_72 . V_757 ;
V_431 -> V_767 = V_19 -> V_45 . V_72 . V_658 ;
V_431 -> V_768 = V_19 -> V_45 . V_72 . V_760 ;
V_431 -> V_764 = V_19 -> V_45 . V_72 . V_552 ;
V_431 -> V_769 = V_19 -> V_45 . V_72 . V_754 ;
V_431 -> V_770 = V_19 -> V_45 . V_72 . V_762 ;
V_431 -> V_771 = V_19 -> V_45 . V_72 . V_763 ;
V_431 -> V_324 = V_19 -> V_45 . V_72 . V_324 ;
V_431 -> type = V_772 ;
V_431 -> clock = V_19 -> V_45 . V_72 . V_73 ;
V_431 -> V_773 = F_577 ( V_431 ) ;
V_431 -> V_774 = F_578 ( V_431 ) ;
F_579 ( V_431 ) ;
}
static void F_483 ( struct V_62 * V_62 )
{
struct V_1 * V_2 = F_34 ( V_62 -> V_45 . V_44 ) ;
T_2 V_775 ;
V_775 = 0 ;
if ( F_78 ( V_2 ) )
V_775 |= F_16 ( F_53 ( V_62 -> V_75 ) ) & V_110 ;
if ( V_62 -> V_71 -> V_203 )
V_775 |= V_204 ;
if ( F_93 ( V_2 ) || F_10 ( V_2 ) ||
F_11 ( V_2 ) ) {
if ( V_62 -> V_71 -> V_776 && V_62 -> V_71 -> V_644 != 30 )
V_775 |= V_777 |
V_778 ;
switch ( V_62 -> V_71 -> V_644 ) {
case 18 :
V_775 |= V_779 ;
break;
case 24 :
V_775 |= V_188 ;
break;
case 30 :
V_775 |= V_780 ;
break;
default:
F_141 () ;
}
}
if ( F_580 ( V_2 ) ) {
if ( V_62 -> V_684 ) {
F_156 ( L_110 ) ;
V_775 |= V_781 ;
} else {
F_156 ( L_111 ) ;
}
}
if ( V_62 -> V_71 -> V_45 . V_72 . V_324 & V_541 ) {
if ( F_52 ( V_2 ) < 4 ||
F_31 ( V_62 -> V_71 , V_192 ) )
V_775 |= V_782 ;
else
V_775 |= V_783 ;
} else
V_775 |= V_784 ;
if ( ( F_10 ( V_2 ) || F_11 ( V_2 ) ) &&
V_62 -> V_71 -> V_785 )
V_775 |= V_786 ;
F_120 ( F_53 ( V_62 -> V_75 ) , V_775 ) ;
F_121 ( F_53 ( V_62 -> V_75 ) ) ;
}
static int F_581 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_37 * V_38 ;
int V_25 = 48000 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_528 ( V_2 ) ) {
V_25 = V_2 -> V_677 . V_787 ;
F_156 ( L_112 , V_25 ) ;
}
V_38 = & V_788 ;
} else if ( F_31 ( V_41 , V_165 ) ) {
V_38 = & V_789 ;
} else {
V_38 = & V_790 ;
}
if ( ! V_41 -> V_791 &&
! F_33 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_573 ( V_46 , V_41 , NULL ) ;
return 0 ;
}
static int F_582 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_37 * V_38 ;
int V_25 = 96000 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_528 ( V_2 ) ) {
V_25 = V_2 -> V_677 . V_787 ;
F_156 ( L_112 , V_25 ) ;
}
if ( F_32 ( V_44 ) )
V_38 = & V_792 ;
else
V_38 = & V_793 ;
} else if ( F_31 ( V_41 , V_187 ) ||
F_31 ( V_41 , V_713 ) ) {
V_38 = & V_794 ;
} else if ( F_31 ( V_41 , V_192 ) ) {
V_38 = & V_795 ;
} else {
V_38 = & V_796 ;
}
if ( ! V_41 -> V_791 &&
! F_36 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_569 ( V_46 , V_41 , NULL ) ;
return 0 ;
}
static int F_583 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_37 * V_38 ;
int V_25 = 96000 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_528 ( V_2 ) ) {
V_25 = V_2 -> V_677 . V_787 ;
F_156 ( L_112 , V_25 ) ;
}
V_38 = & V_797 ;
} else {
V_38 = & V_798 ;
}
if ( ! V_41 -> V_791 &&
! F_35 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_569 ( V_46 , V_41 , NULL ) ;
return 0 ;
}
static int F_584 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_37 * V_38 ;
int V_25 = 96000 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_528 ( V_2 ) ) {
V_25 = V_2 -> V_677 . V_787 ;
F_156 ( L_112 , V_25 ) ;
}
V_38 = & V_799 ;
} else {
V_38 = & V_796 ;
}
if ( ! V_41 -> V_791 &&
! F_33 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_569 ( V_46 , V_41 , NULL ) ;
return 0 ;
}
static int F_585 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
int V_25 = 100000 ;
const struct V_37 * V_38 = & V_800 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( ! V_41 -> V_791 &&
! F_42 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_552 ( V_46 , V_41 ) ;
return 0 ;
}
static int F_586 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
int V_25 = 100000 ;
const struct V_37 * V_38 = & V_801 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
if ( ! V_41 -> V_791 &&
! F_40 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_551 ( V_46 , V_41 ) ;
return 0 ;
}
static void F_587 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
T_2 V_157 ;
if ( F_52 ( V_2 ) <= 3 &&
( F_78 ( V_2 ) || ! F_136 ( V_2 ) ) )
return;
V_157 = F_16 ( V_600 ) ;
if ( ! ( V_157 & V_601 ) )
return;
if ( F_52 ( V_2 ) < 4 ) {
if ( V_46 -> V_75 != V_101 )
return;
} else {
if ( ( V_157 & V_802 ) != ( V_46 -> V_75 << V_803 ) )
return;
}
V_19 -> V_598 . V_599 = V_157 ;
V_19 -> V_598 . V_603 = F_16 ( V_602 ) ;
}
static void F_588 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_19 -> V_76 ;
struct V_26 clock ;
T_1 V_695 ;
int V_25 = 100000 ;
if ( ( V_19 -> V_152 . V_26 & V_84 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_695 = F_129 ( V_2 , V_75 , F_554 ( V_75 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_35 = ( V_695 >> V_704 ) & 7 ;
clock . V_28 = V_695 & V_705 ;
clock . V_32 = ( V_695 >> V_708 ) & 0xf ;
clock . V_30 = ( V_695 >> V_706 ) & 7 ;
clock . V_31 = ( V_695 >> V_707 ) & 0x1f ;
V_19 -> V_20 = F_23 ( V_25 , & clock ) ;
}
static void
F_589 ( struct V_62 * V_46 ,
struct V_313 * V_314 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_11 , V_45 , V_256 ;
int V_75 = V_46 -> V_75 , V_111 = V_46 -> V_111 ;
int V_804 , V_274 ;
unsigned int V_805 ;
struct V_205 * V_70 ;
struct V_246 * V_247 ;
V_11 = F_16 ( F_83 ( V_111 ) ) ;
if ( ! ( V_11 & V_112 ) )
return;
V_247 = F_508 ( sizeof( * V_247 ) , V_635 ) ;
if ( ! V_247 ) {
F_156 ( L_114 ) ;
return;
}
V_70 = & V_247 -> V_45 ;
V_70 -> V_44 = V_44 ;
if ( F_52 ( V_2 ) >= 4 ) {
if ( V_11 & V_367 ) {
V_314 -> V_322 = V_265 ;
V_70 -> V_208 = V_210 ;
}
}
V_274 = V_11 & V_806 ;
V_804 = F_223 ( V_274 ) ;
V_70 -> V_207 = V_268 ( V_804 ) ;
if ( F_52 ( V_2 ) >= 4 ) {
if ( V_314 -> V_322 )
V_256 = F_16 ( F_274 ( V_111 ) ) ;
else
V_256 = F_16 ( F_275 ( V_111 ) ) ;
V_45 = F_16 ( F_272 ( V_111 ) ) & 0xfffff000 ;
} else {
V_45 = F_16 ( F_276 ( V_111 ) ) ;
}
V_314 -> V_45 = V_45 ;
V_11 = F_16 ( F_336 ( V_75 ) ) ;
V_70 -> V_222 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_70 -> V_218 = ( ( V_11 >> 0 ) & 0xfff ) + 1 ;
V_11 = F_16 ( F_271 ( V_75 ) ) ;
V_70 -> V_242 [ 0 ] = V_11 & 0xffffffc0 ;
V_805 = F_170 ( V_70 , 0 , V_70 -> V_218 ) ;
V_314 -> V_221 = V_70 -> V_242 [ 0 ] * V_805 ;
F_156 ( L_115 ,
F_72 ( V_75 ) , V_111 , V_70 -> V_222 , V_70 -> V_218 ,
V_70 -> V_207 -> V_206 [ 0 ] * 8 , V_45 , V_70 -> V_242 [ 0 ] ,
V_314 -> V_221 ) ;
V_314 -> V_70 = V_247 ;
}
static void F_590 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_19 -> V_76 ;
enum V_155 V_156 = F_128 ( V_75 ) ;
struct V_26 clock ;
T_1 V_807 , V_808 , V_809 , V_810 , V_811 ;
int V_25 = 100000 ;
if ( ( V_19 -> V_152 . V_26 & V_84 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_807 = F_129 ( V_2 , V_75 , F_559 ( V_156 ) ) ;
V_808 = F_129 ( V_2 , V_75 , F_560 ( V_156 ) ) ;
V_809 = F_129 ( V_2 , V_75 , F_561 ( V_156 ) ) ;
V_810 = F_129 ( V_2 , V_75 , F_562 ( V_156 ) ) ;
V_811 = F_129 ( V_2 , V_75 , F_563 ( V_156 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_35 = ( V_809 & 0x7 ) == V_722 ? 2 : 0 ;
clock . V_28 = ( V_808 & 0xff ) << 22 ;
if ( V_811 & V_725 )
clock . V_28 |= V_810 & 0x3fffff ;
clock . V_32 = ( V_809 >> V_723 ) & 0xf ;
clock . V_30 = ( V_807 >> V_719 ) & 0x7 ;
clock . V_31 = ( V_807 >> V_720 ) & 0x1f ;
V_19 -> V_20 = F_24 ( V_25 , & clock ) ;
}
static bool F_591 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_108 V_109 ;
T_2 V_157 ;
bool V_278 ;
V_109 = F_472 ( V_46 -> V_75 ) ;
if ( ! F_80 ( V_2 , V_109 ) )
return false ;
V_19 -> V_76 = (enum V_74 ) V_46 -> V_75 ;
V_19 -> V_184 = NULL ;
V_278 = false ;
V_157 = F_16 ( F_53 ( V_46 -> V_75 ) ) ;
if ( ! ( V_157 & V_110 ) )
goto V_812;
if ( F_93 ( V_2 ) || F_10 ( V_2 ) ||
F_11 ( V_2 ) ) {
switch ( V_157 & V_186 ) {
case V_779 :
V_19 -> V_644 = 18 ;
break;
case V_188 :
V_19 -> V_644 = 24 ;
break;
case V_780 :
V_19 -> V_644 = 30 ;
break;
default:
break;
}
}
if ( ( F_10 ( V_2 ) || F_11 ( V_2 ) ) &&
( V_157 & V_786 ) )
V_19 -> V_785 = true ;
if ( F_52 ( V_2 ) < 4 )
V_19 -> V_203 = V_157 & V_204 ;
F_574 ( V_46 , V_19 ) ;
F_575 ( V_46 , V_19 ) ;
F_587 ( V_46 , V_19 ) ;
if ( F_52 ( V_2 ) >= 4 ) {
if ( F_11 ( V_2 ) && V_46 -> V_75 != V_94 )
V_157 = V_2 -> V_162 [ V_46 -> V_75 ] ;
else
V_157 = F_16 ( F_126 ( V_46 -> V_75 ) ) ;
V_19 -> V_593 =
( ( V_157 & V_813 )
>> V_694 ) + 1 ;
V_19 -> V_152 . V_154 = V_157 ;
} else if ( F_570 ( V_2 ) || F_571 ( V_2 ) ||
F_572 ( V_2 ) || F_28 ( V_2 ) ) {
V_157 = F_16 ( F_57 ( V_46 -> V_75 ) ) ;
V_19 -> V_593 =
( ( V_157 & V_814 )
>> V_738 ) + 1 ;
} else {
V_19 -> V_593 = 1 ;
}
V_19 -> V_152 . V_26 = F_16 ( F_57 ( V_46 -> V_75 ) ) ;
if ( ! F_10 ( V_2 ) && ! F_11 ( V_2 ) ) {
if ( F_78 ( V_2 ) )
V_19 -> V_152 . V_26 &= ~ V_166 ;
V_19 -> V_152 . V_624 = F_16 ( F_487 ( V_46 -> V_75 ) ) ;
V_19 -> V_152 . V_625 = F_16 ( F_488 ( V_46 -> V_75 ) ) ;
} else {
V_19 -> V_152 . V_26 &= ~ ( V_153 |
V_179 |
V_177 ) ;
}
if ( F_11 ( V_2 ) )
F_590 ( V_46 , V_19 ) ;
else if ( F_10 ( V_2 ) )
F_588 ( V_46 , V_19 ) ;
else
F_592 ( V_46 , V_19 ) ;
V_19 -> V_45 . V_72 . V_73 =
V_19 -> V_20 / V_19 -> V_593 ;
V_278 = true ;
V_812:
F_81 ( V_2 , V_109 ) ;
return V_278 ;
}
static void F_593 ( struct V_1 * V_2 )
{
struct V_517 * V_518 ;
int V_113 ;
T_1 V_11 , V_815 ;
bool V_816 = false ;
bool V_817 = false ;
bool V_818 = false ;
bool V_819 = false ;
bool V_820 = false ;
bool V_821 = false ;
F_594 (&dev_priv->drm, encoder) {
switch ( V_518 -> type ) {
case V_47 :
V_818 = true ;
V_816 = true ;
break;
case V_520 :
V_818 = true ;
if ( F_388 ( & V_518 -> V_45 ) -> V_156 == V_604 )
V_817 = true ;
break;
default:
break;
}
}
if ( F_116 ( V_2 ) ) {
V_819 = V_2 -> V_677 . V_822 ;
V_820 = V_819 ;
} else {
V_819 = false ;
V_820 = true ;
}
for ( V_113 = 0 ; V_113 < V_2 -> V_823 ; V_113 ++ ) {
T_1 V_452 = F_16 ( F_595 ( V_113 ) ) ;
if ( ! ( V_452 & V_84 ) )
continue;
if ( ( V_452 & V_824 ) ==
V_750 ) {
V_821 = true ;
break;
}
}
F_156 ( L_116 ,
V_818 , V_816 , V_819 , V_821 ) ;
V_11 = F_16 ( V_825 ) ;
V_815 = V_11 ;
V_815 &= ~ V_826 ;
if ( V_819 )
V_815 |= V_827 ;
else
V_815 |= V_828 ;
V_815 &= ~ V_829 ;
V_815 &= ~ V_830 ;
V_815 &= ~ V_831 ;
if ( V_818 ) {
V_815 |= V_832 ;
if ( F_528 ( V_2 ) && V_820 )
V_815 |= V_831 ;
if ( V_817 ) {
if ( F_528 ( V_2 ) && V_820 )
V_815 |= V_833 ;
else
V_815 |= V_834 ;
} else
V_815 |= V_835 ;
} else if ( V_821 ) {
V_815 |= V_832 ;
V_815 |= V_831 ;
}
if ( V_815 == V_11 )
return;
V_11 &= ~ V_826 ;
if ( V_819 )
V_11 |= V_827 ;
else
V_11 |= V_828 ;
if ( V_818 ) {
V_11 &= ~ V_829 ;
V_11 |= V_832 ;
if ( F_528 ( V_2 ) && V_820 ) {
F_156 ( L_117 ) ;
V_11 |= V_831 ;
} else
V_11 &= ~ V_831 ;
F_120 ( V_825 , V_11 ) ;
F_121 ( V_825 ) ;
F_122 ( 200 ) ;
V_11 &= ~ V_830 ;
if ( V_817 ) {
if ( F_528 ( V_2 ) && V_820 ) {
F_156 ( L_118 ) ;
V_11 |= V_833 ;
} else
V_11 |= V_834 ;
} else
V_11 |= V_835 ;
F_120 ( V_825 , V_11 ) ;
F_121 ( V_825 ) ;
F_122 ( 200 ) ;
} else {
F_156 ( L_119 ) ;
V_11 &= ~ V_830 ;
V_11 |= V_835 ;
F_120 ( V_825 , V_11 ) ;
F_121 ( V_825 ) ;
F_122 ( 200 ) ;
if ( ! V_821 ) {
F_156 ( L_120 ) ;
V_11 &= ~ V_829 ;
V_11 |= V_836 ;
V_11 &= ~ V_831 ;
F_120 ( V_825 , V_11 ) ;
F_121 ( V_825 ) ;
F_122 ( 200 ) ;
}
}
F_596 ( V_11 != V_815 ) ;
}
static void F_597 ( struct V_1 * V_2 )
{
T_2 V_157 ;
V_157 = F_16 ( V_837 ) ;
V_157 |= V_838 ;
F_120 ( V_837 , V_157 ) ;
if ( F_598 ( F_16 ( V_837 ) &
V_839 , 100 ) )
F_123 ( L_121 ) ;
V_157 = F_16 ( V_837 ) ;
V_157 &= ~ V_838 ;
F_120 ( V_837 , V_157 ) ;
if ( F_598 ( ( F_16 ( V_837 ) &
V_839 ) == 0 , 100 ) )
F_123 ( L_122 ) ;
}
static void F_599 ( struct V_1 * V_2 )
{
T_2 V_157 ;
V_157 = F_361 ( V_2 , 0x8008 , V_840 ) ;
V_157 &= ~ ( 0xFF << 24 ) ;
V_157 |= ( 0x12 << 24 ) ;
F_362 ( V_2 , 0x8008 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2008 , V_840 ) ;
V_157 |= ( 1 << 11 ) ;
F_362 ( V_2 , 0x2008 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2108 , V_840 ) ;
V_157 |= ( 1 << 11 ) ;
F_362 ( V_2 , 0x2108 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x206C , V_840 ) ;
V_157 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_362 ( V_2 , 0x206C , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x216C , V_840 ) ;
V_157 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_362 ( V_2 , 0x216C , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2080 , V_840 ) ;
V_157 &= ~ ( 7 << 13 ) ;
V_157 |= ( 5 << 13 ) ;
F_362 ( V_2 , 0x2080 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2180 , V_840 ) ;
V_157 &= ~ ( 7 << 13 ) ;
V_157 |= ( 5 << 13 ) ;
F_362 ( V_2 , 0x2180 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x208C , V_840 ) ;
V_157 &= ~ 0xFF ;
V_157 |= 0x1C ;
F_362 ( V_2 , 0x208C , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x218C , V_840 ) ;
V_157 &= ~ 0xFF ;
V_157 |= 0x1C ;
F_362 ( V_2 , 0x218C , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2098 , V_840 ) ;
V_157 &= ~ ( 0xFF << 16 ) ;
V_157 |= ( 0x1C << 16 ) ;
F_362 ( V_2 , 0x2098 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x2198 , V_840 ) ;
V_157 &= ~ ( 0xFF << 16 ) ;
V_157 |= ( 0x1C << 16 ) ;
F_362 ( V_2 , 0x2198 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x20C4 , V_840 ) ;
V_157 |= ( 1 << 27 ) ;
F_362 ( V_2 , 0x20C4 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x21C4 , V_840 ) ;
V_157 |= ( 1 << 27 ) ;
F_362 ( V_2 , 0x21C4 , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x20EC , V_840 ) ;
V_157 &= ~ ( 0xF << 28 ) ;
V_157 |= ( 4 << 28 ) ;
F_362 ( V_2 , 0x20EC , V_157 , V_840 ) ;
V_157 = F_361 ( V_2 , 0x21EC , V_840 ) ;
V_157 &= ~ ( 0xF << 28 ) ;
V_157 |= ( 4 << 28 ) ;
F_362 ( V_2 , 0x21EC , V_157 , V_840 ) ;
}
static void F_600 ( struct V_1 * V_2 ,
bool V_841 , bool V_842 )
{
T_2 V_9 , V_157 ;
if ( F_6 ( V_842 && ! V_841 , L_123 ) )
V_841 = true ;
if ( F_6 ( F_601 ( V_2 ) &&
V_842 , L_124 ) )
V_842 = false ;
F_2 ( & V_2 -> V_5 ) ;
V_157 = F_361 ( V_2 , V_843 , V_494 ) ;
V_157 &= ~ V_495 ;
V_157 |= V_844 ;
F_362 ( V_2 , V_843 , V_157 , V_494 ) ;
F_122 ( 24 ) ;
if ( V_841 ) {
V_157 = F_361 ( V_2 , V_843 , V_494 ) ;
V_157 &= ~ V_844 ;
F_362 ( V_2 , V_843 , V_157 , V_494 ) ;
if ( V_842 ) {
F_597 ( V_2 ) ;
F_599 ( V_2 ) ;
}
}
V_9 = F_601 ( V_2 ) ? V_845 : V_846 ;
V_157 = F_361 ( V_2 , V_9 , V_494 ) ;
V_157 |= V_847 ;
F_362 ( V_2 , V_9 , V_157 , V_494 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_602 ( struct V_1 * V_2 )
{
T_2 V_9 , V_157 ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_601 ( V_2 ) ? V_845 : V_846 ;
V_157 = F_361 ( V_2 , V_9 , V_494 ) ;
V_157 &= ~ V_847 ;
F_362 ( V_2 , V_9 , V_157 , V_494 ) ;
V_157 = F_361 ( V_2 , V_843 , V_494 ) ;
if ( ! ( V_157 & V_495 ) ) {
if ( ! ( V_157 & V_844 ) ) {
V_157 |= V_844 ;
F_362 ( V_2 , V_843 , V_157 , V_494 ) ;
F_122 ( 32 ) ;
}
V_157 |= V_495 ;
F_362 ( V_2 , V_843 , V_157 , V_494 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_603 ( struct V_1 * V_2 , int V_848 )
{
T_2 V_157 ;
int V_849 = F_604 ( V_848 ) ;
if ( F_20 ( V_848 % 5 != 0 ) )
return;
if ( F_20 ( V_849 >= F_173 ( V_850 ) ) )
return;
F_2 ( & V_2 -> V_5 ) ;
if ( V_848 % 10 != 0 )
V_157 = 0xAAAAAAAB ;
else
V_157 = 0x00000000 ;
F_362 ( V_2 , V_851 , V_157 , V_494 ) ;
V_157 = F_361 ( V_2 , V_852 , V_494 ) ;
V_157 &= 0xffff0000 ;
V_157 |= V_850 [ V_849 ] ;
F_362 ( V_2 , V_852 , V_157 , V_494 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_605 ( struct V_1 * V_2 )
{
struct V_517 * V_518 ;
bool V_853 = false ;
F_594 (&dev_priv->drm, encoder) {
switch ( V_518 -> type ) {
case V_713 :
V_853 = true ;
break;
default:
break;
}
}
if ( V_853 ) {
F_603 ( V_2 , 0 ) ;
F_600 ( V_2 , true , true ) ;
} else {
F_602 ( V_2 ) ;
}
}
void F_606 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 ) || F_102 ( V_2 ) )
F_593 ( V_2 ) ;
else if ( F_154 ( V_2 ) )
F_605 ( V_2 ) ;
}
static void F_448 ( struct V_123 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
int V_75 = V_62 -> V_75 ;
T_2 V_11 ;
V_11 = 0 ;
switch ( V_62 -> V_71 -> V_644 ) {
case 18 :
V_11 |= V_779 ;
break;
case 24 :
V_11 |= V_188 ;
break;
case 30 :
V_11 |= V_780 ;
break;
case 36 :
V_11 |= V_854 ;
break;
default:
F_141 () ;
}
if ( V_62 -> V_71 -> V_776 )
V_11 |= ( V_777 | V_778 ) ;
if ( V_62 -> V_71 -> V_45 . V_72 . V_324 & V_541 )
V_11 |= V_191 ;
else
V_11 |= V_784 ;
if ( V_62 -> V_71 -> V_785 )
V_11 |= V_786 ;
F_120 ( F_53 ( V_75 ) , V_11 ) ;
F_121 ( F_53 ( V_75 ) ) ;
}
static void F_456 ( struct V_123 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_74 V_76 = V_62 -> V_71 -> V_76 ;
T_1 V_11 = 0 ;
if ( F_259 ( V_2 ) && V_62 -> V_71 -> V_776 )
V_11 |= ( V_777 | V_778 ) ;
if ( V_62 -> V_71 -> V_45 . V_72 . V_324 & V_541 )
V_11 |= V_191 ;
else
V_11 |= V_784 ;
F_120 ( F_53 ( V_76 ) , V_11 ) ;
F_121 ( F_53 ( V_76 ) ) ;
}
static void F_457 ( struct V_123 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_18 * V_71 = V_62 -> V_71 ;
if ( F_260 ( V_2 ) || F_180 ( V_2 ) -> V_229 >= 9 ) {
T_1 V_11 = 0 ;
switch ( V_62 -> V_71 -> V_644 ) {
case 18 :
V_11 |= V_855 ;
break;
case 24 :
V_11 |= V_856 ;
break;
case 30 :
V_11 |= V_857 ;
break;
case 36 :
V_11 |= V_858 ;
break;
default:
F_141 () ;
}
if ( V_62 -> V_71 -> V_776 )
V_11 |= V_859 | V_860 ;
if ( V_71 -> V_539 ) {
V_11 |= V_861 |
V_862 |
V_863 ;
}
F_120 ( F_607 ( V_62 -> V_75 ) , V_11 ) ;
}
}
int F_515 ( int V_66 , int V_641 , int V_864 )
{
T_1 V_865 = V_66 * V_864 * 21 / 20 ;
return F_221 ( V_865 , V_641 * 8 ) ;
}
static bool F_608 ( struct V_26 * V_26 , int V_866 )
{
return F_21 ( V_26 ) < V_866 * V_26 -> V_32 ;
}
static void F_609 ( struct V_62 * V_62 ,
struct V_18 * V_41 ,
struct V_26 * V_681 )
{
struct V_123 * V_46 = & V_62 -> V_45 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_26 , V_682 , V_683 ;
int V_866 ;
V_866 = 21 ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( ( F_528 ( V_2 ) &&
V_2 -> V_677 . V_787 == 100000 ) ||
( F_116 ( V_2 ) && F_32 ( V_44 ) ) )
V_866 = 25 ;
} else if ( V_41 -> V_748 )
V_866 = 20 ;
V_682 = F_530 ( & V_41 -> V_26 ) ;
if ( F_608 ( & V_41 -> V_26 , V_866 ) )
V_682 |= V_867 ;
if ( V_681 ) {
V_683 = F_530 ( V_681 ) ;
if ( V_681 -> V_27 < V_866 * V_681 -> V_32 )
V_683 |= V_867 ;
} else {
V_683 = V_682 ;
}
V_26 = 0 ;
if ( F_31 ( V_41 , V_47 ) )
V_26 |= V_736 ;
else
V_26 |= V_737 ;
V_26 |= ( V_41 -> V_593 - 1 )
<< V_868 ;
if ( F_31 ( V_41 , V_192 ) ||
F_31 ( V_41 , V_187 ) )
V_26 |= V_739 ;
if ( F_396 ( V_41 ) )
V_26 |= V_739 ;
if ( F_180 ( V_2 ) -> V_639 == 3 &&
F_31 ( V_41 , V_713 ) )
V_26 |= V_739 ;
V_26 |= ( 1 << ( V_41 -> V_26 . V_30 - 1 ) ) << V_741 ;
V_26 |= ( 1 << ( V_41 -> V_26 . V_30 - 1 ) ) << V_742 ;
switch ( V_41 -> V_26 . V_31 ) {
case 5 :
V_26 |= V_743 ;
break;
case 7 :
V_26 |= V_744 ;
break;
case 10 :
V_26 |= V_745 ;
break;
case 14 :
V_26 |= V_746 ;
break;
}
if ( F_31 ( V_41 , V_47 ) &&
F_528 ( V_2 ) )
V_26 |= V_750 ;
else
V_26 |= V_751 ;
V_26 |= V_84 ;
V_41 -> V_152 . V_26 = V_26 ;
V_41 -> V_152 . V_624 = V_682 ;
V_41 -> V_152 . V_625 = V_683 ;
}
static int F_610 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
const struct V_37 * V_38 ;
int V_25 = 120000 ;
memset ( & V_41 -> V_152 , 0 ,
sizeof( V_41 -> V_152 ) ) ;
V_46 -> V_684 = false ;
if ( ! V_41 -> V_199 )
return 0 ;
if ( F_31 ( V_41 , V_47 ) ) {
if ( F_528 ( V_2 ) ) {
F_156 ( L_112 ,
V_2 -> V_677 . V_787 ) ;
V_25 = V_2 -> V_677 . V_787 ;
}
if ( F_32 ( V_44 ) ) {
if ( V_25 == 100000 )
V_38 = & V_869 ;
else
V_38 = & V_870 ;
} else {
if ( V_25 == 100000 )
V_38 = & V_871 ;
else
V_38 = & V_872 ;
}
} else {
V_38 = & V_873 ;
}
if ( ! V_41 -> V_791 &&
! F_36 ( V_38 , V_41 , V_41 -> V_20 ,
V_25 , NULL , & V_41 -> V_26 ) ) {
F_123 ( L_113 ) ;
return - V_263 ;
}
F_609 ( V_46 , V_41 , NULL ) ;
if ( ! F_611 ( V_46 , V_41 , NULL ) ) {
F_12 ( L_125 ,
F_72 ( V_46 -> V_75 ) ) ;
return - V_263 ;
}
return 0 ;
}
static void F_612 ( struct V_62 * V_46 ,
struct V_669 * V_670 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
V_670 -> V_674 = F_16 ( F_538 ( V_75 ) ) ;
V_670 -> V_675 = F_16 ( F_539 ( V_75 ) ) ;
V_670 -> V_672 = F_16 ( F_535 ( V_75 ) )
& ~ V_521 ;
V_670 -> V_673 = F_16 ( F_537 ( V_75 ) ) ;
V_670 -> V_671 = ( ( F_16 ( F_535 ( V_75 ) )
& V_521 ) >> V_874 ) + 1 ;
}
static void F_613 ( struct V_62 * V_46 ,
enum V_74 V_74 ,
struct V_669 * V_670 ,
struct V_669 * V_687 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_46 -> V_75 ;
if ( F_52 ( V_2 ) >= 5 ) {
V_670 -> V_674 = F_16 ( F_541 ( V_74 ) ) ;
V_670 -> V_675 = F_16 ( F_542 ( V_74 ) ) ;
V_670 -> V_672 = F_16 ( F_391 ( V_74 ) )
& ~ V_521 ;
V_670 -> V_673 = F_16 ( F_540 ( V_74 ) ) ;
V_670 -> V_671 = ( ( F_16 ( F_391 ( V_74 ) )
& V_521 ) >> V_874 ) + 1 ;
if ( V_687 && F_52 ( V_2 ) < 8 &&
V_46 -> V_71 -> V_688 ) {
V_687 -> V_674 = F_16 ( F_545 ( V_74 ) ) ;
V_687 -> V_675 = F_16 ( F_546 ( V_74 ) ) ;
V_687 -> V_672 = F_16 ( F_543 ( V_74 ) )
& ~ V_521 ;
V_687 -> V_673 = F_16 ( F_544 ( V_74 ) ) ;
V_687 -> V_671 = ( ( F_16 ( F_543 ( V_74 ) )
& V_521 ) >> V_874 ) + 1 ;
}
} else {
V_670 -> V_674 = F_16 ( F_549 ( V_75 ) ) ;
V_670 -> V_675 = F_16 ( F_550 ( V_75 ) ) ;
V_670 -> V_672 = F_16 ( F_547 ( V_75 ) )
& ~ V_521 ;
V_670 -> V_673 = F_16 ( F_548 ( V_75 ) ) ;
V_670 -> V_671 = ( ( F_16 ( F_547 ( V_75 ) )
& V_521 ) >> V_874 ) + 1 ;
}
}
void F_614 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_199 )
F_612 ( V_46 , & V_19 -> V_690 ) ;
else
F_613 ( V_46 , V_19 -> V_76 ,
& V_19 -> V_690 ,
& V_19 -> V_691 ) ;
}
static void F_615 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
F_613 ( V_46 , V_19 -> V_76 ,
& V_19 -> V_590 , NULL ) ;
}
static void F_616 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_382 * V_383 = & V_19 -> V_383 ;
T_2 V_429 = 0 ;
int V_260 = - 1 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_46 -> V_384 ; V_113 ++ ) {
V_429 = F_16 ( F_282 ( V_46 -> V_75 , V_113 ) ) ;
if ( V_429 & V_430 && ! ( V_429 & V_875 ) ) {
V_260 = V_113 ;
V_19 -> V_451 . V_124 = true ;
V_19 -> V_451 . V_555 = F_16 ( F_283 ( V_46 -> V_75 , V_113 ) ) ;
V_19 -> V_451 . V_221 = F_16 ( F_284 ( V_46 -> V_75 , V_113 ) ) ;
break;
}
}
V_383 -> V_421 = V_260 ;
if ( V_260 >= 0 ) {
V_383 -> V_542 |= ( 1 << V_540 ) ;
} else {
V_383 -> V_542 &= ~ ( 1 << V_540 ) ;
}
}
static void
F_617 ( struct V_62 * V_46 ,
struct V_313 * V_314 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_11 , V_45 , V_256 , V_876 , V_322 ;
int V_75 = V_46 -> V_75 ;
int V_804 , V_274 ;
unsigned int V_805 ;
struct V_205 * V_70 ;
struct V_246 * V_247 ;
V_247 = F_508 ( sizeof( * V_247 ) , V_635 ) ;
if ( ! V_247 ) {
F_156 ( L_114 ) ;
return;
}
V_70 = & V_247 -> V_45 ;
V_70 -> V_44 = V_44 ;
V_11 = F_16 ( F_89 ( V_75 , 0 ) ) ;
if ( ! ( V_11 & V_118 ) )
goto error;
V_274 = V_11 & V_877 ;
V_804 = F_224 ( V_274 ,
V_11 & V_388 ,
V_11 & V_878 ) ;
V_70 -> V_207 = V_268 ( V_804 ) ;
V_322 = V_11 & V_879 ;
switch ( V_322 ) {
case V_880 :
V_70 -> V_208 = V_209 ;
break;
case V_399 :
V_314 -> V_322 = V_265 ;
V_70 -> V_208 = V_210 ;
break;
case V_400 :
if ( V_11 & V_401 )
V_70 -> V_208 = V_211 ;
else
V_70 -> V_208 = V_212 ;
break;
case V_402 :
if ( V_11 & V_401 )
V_70 -> V_208 = V_213 ;
else
V_70 -> V_208 = V_214 ;
break;
default:
F_167 ( V_322 ) ;
goto error;
}
V_45 = F_16 ( F_303 ( V_75 , 0 ) ) & 0xfffff000 ;
V_314 -> V_45 = V_45 ;
V_256 = F_16 ( F_295 ( V_75 , 0 ) ) ;
V_11 = F_16 ( F_297 ( V_75 , 0 ) ) ;
V_70 -> V_218 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_70 -> V_222 = ( ( V_11 >> 0 ) & 0x1fff ) + 1 ;
V_11 = F_16 ( F_296 ( V_75 , 0 ) ) ;
V_876 = F_280 ( V_70 , 0 ) ;
V_70 -> V_242 [ 0 ] = ( V_11 & 0x3ff ) * V_876 ;
V_805 = F_170 ( V_70 , 0 , V_70 -> V_218 ) ;
V_314 -> V_221 = V_70 -> V_242 [ 0 ] * V_805 ;
F_156 ( L_126 ,
F_72 ( V_75 ) , V_70 -> V_222 , V_70 -> V_218 ,
V_70 -> V_207 -> V_206 [ 0 ] * 8 , V_45 , V_70 -> V_242 [ 0 ] ,
V_314 -> V_221 ) ;
V_314 -> V_70 = V_247 ;
return;
error:
F_236 ( V_247 ) ;
}
static void F_618 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_2 V_157 ;
V_157 = F_16 ( F_403 ( V_46 -> V_75 ) ) ;
if ( V_157 & V_556 ) {
V_19 -> V_451 . V_124 = true ;
V_19 -> V_451 . V_555 = F_16 ( F_405 ( V_46 -> V_75 ) ) ;
V_19 -> V_451 . V_221 = F_16 ( F_406 ( V_46 -> V_75 ) ) ;
if ( F_619 ( V_2 ) ) {
F_20 ( ( V_157 & V_881 ) !=
F_404 ( V_46 -> V_75 ) ) ;
}
}
}
static void
F_620 ( struct V_62 * V_46 ,
struct V_313 * V_314 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_11 , V_45 , V_256 ;
int V_75 = V_46 -> V_75 ;
int V_804 , V_274 ;
unsigned int V_805 ;
struct V_205 * V_70 ;
struct V_246 * V_247 ;
V_11 = F_16 ( F_83 ( V_75 ) ) ;
if ( ! ( V_11 & V_112 ) )
return;
V_247 = F_508 ( sizeof( * V_247 ) , V_635 ) ;
if ( ! V_247 ) {
F_156 ( L_114 ) ;
return;
}
V_70 = & V_247 -> V_45 ;
V_70 -> V_44 = V_44 ;
if ( F_52 ( V_2 ) >= 4 ) {
if ( V_11 & V_367 ) {
V_314 -> V_322 = V_265 ;
V_70 -> V_208 = V_210 ;
}
}
V_274 = V_11 & V_806 ;
V_804 = F_223 ( V_274 ) ;
V_70 -> V_207 = V_268 ( V_804 ) ;
V_45 = F_16 ( F_272 ( V_75 ) ) & 0xfffff000 ;
if ( F_259 ( V_2 ) || F_260 ( V_2 ) ) {
V_256 = F_16 ( F_273 ( V_75 ) ) ;
} else {
if ( V_314 -> V_322 )
V_256 = F_16 ( F_274 ( V_75 ) ) ;
else
V_256 = F_16 ( F_275 ( V_75 ) ) ;
}
V_314 -> V_45 = V_45 ;
V_11 = F_16 ( F_336 ( V_75 ) ) ;
V_70 -> V_222 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_70 -> V_218 = ( ( V_11 >> 0 ) & 0xfff ) + 1 ;
V_11 = F_16 ( F_271 ( V_75 ) ) ;
V_70 -> V_242 [ 0 ] = V_11 & 0xffffffc0 ;
V_805 = F_170 ( V_70 , 0 , V_70 -> V_218 ) ;
V_314 -> V_221 = V_70 -> V_242 [ 0 ] * V_805 ;
F_156 ( L_126 ,
F_72 ( V_75 ) , V_70 -> V_222 , V_70 -> V_218 ,
V_70 -> V_207 -> V_206 [ 0 ] * 8 , V_45 , V_70 -> V_242 [ 0 ] ,
V_314 -> V_221 ) ;
V_314 -> V_70 = V_247 ;
}
static bool F_621 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_108 V_109 ;
T_2 V_157 ;
bool V_278 ;
V_109 = F_472 ( V_46 -> V_75 ) ;
if ( ! F_80 ( V_2 , V_109 ) )
return false ;
V_19 -> V_76 = (enum V_74 ) V_46 -> V_75 ;
V_19 -> V_184 = NULL ;
V_278 = false ;
V_157 = F_16 ( F_53 ( V_46 -> V_75 ) ) ;
if ( ! ( V_157 & V_110 ) )
goto V_812;
switch ( V_157 & V_186 ) {
case V_779 :
V_19 -> V_644 = 18 ;
break;
case V_188 :
V_19 -> V_644 = 24 ;
break;
case V_780 :
V_19 -> V_644 = 30 ;
break;
case V_854 :
V_19 -> V_644 = 36 ;
break;
default:
break;
}
if ( V_157 & V_786 )
V_19 -> V_785 = true ;
if ( F_16 ( F_100 ( V_46 -> V_75 ) ) & V_125 ) {
struct V_882 * V_883 ;
enum V_884 V_885 ;
V_19 -> V_199 = true ;
V_157 = F_16 ( F_65 ( V_46 -> V_75 ) ) ;
V_19 -> V_465 = ( ( V_464 & V_157 ) >>
V_886 ) + 1 ;
F_615 ( V_46 , V_19 ) ;
if ( F_116 ( V_2 ) ) {
V_885 = (enum V_884 ) V_46 -> V_75 ;
} else {
V_157 = F_16 ( V_524 ) ;
if ( V_157 & F_393 ( V_46 -> V_75 ) )
V_885 = V_525 ;
else
V_885 = V_887 ;
}
V_19 -> V_184 =
F_394 ( V_2 , V_885 ) ;
V_883 = V_19 -> V_184 ;
F_20 ( ! V_883 -> V_888 . V_633 ( V_2 , V_883 ,
& V_19 -> V_152 ) ) ;
V_157 = V_19 -> V_152 . V_26 ;
V_19 -> V_593 =
( ( V_157 & V_889 )
>> V_868 ) + 1 ;
F_622 ( V_46 , V_19 ) ;
} else {
V_19 -> V_593 = 1 ;
}
F_574 ( V_46 , V_19 ) ;
F_575 ( V_46 , V_19 ) ;
F_618 ( V_46 , V_19 ) ;
V_278 = true ;
V_812:
F_81 ( V_2 , V_109 ) ;
return V_278 ;
}
static void F_623 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_240 ;
struct V_62 * V_46 ;
F_134 (dev, crtc)
F_58 ( V_46 -> V_68 , L_127 ,
F_72 ( V_46 -> V_75 ) ) ;
F_58 ( F_16 ( F_624 ( V_890 ) ) ,
L_128 ) ;
F_58 ( F_16 ( V_891 ) & V_892 , L_129 ) ;
F_58 ( F_16 ( F_625 ( 0 ) ) & V_893 , L_130 ) ;
F_58 ( F_16 ( F_625 ( 1 ) ) & V_893 , L_131 ) ;
F_58 ( F_16 ( F_626 ( 0 ) ) & V_894 , L_132 ) ;
F_58 ( F_16 ( V_895 ) & V_896 ,
L_133 ) ;
if ( F_259 ( V_2 ) )
F_58 ( F_16 ( V_897 ) & V_896 ,
L_134 ) ;
F_58 ( F_16 ( V_898 ) & V_899 ,
L_135 ) ;
F_58 ( F_16 ( V_900 ) & V_901 ,
L_136 ) ;
F_58 ( F_16 ( V_902 ) & V_903 , L_137 ) ;
F_58 ( F_627 ( V_2 ) , L_138 ) ;
}
static T_2 F_628 ( struct V_1 * V_2 )
{
if ( F_259 ( V_2 ) )
return F_16 ( V_904 ) ;
else
return F_16 ( V_905 ) ;
}
static void F_629 ( struct V_1 * V_2 , T_2 V_11 )
{
if ( F_259 ( V_2 ) ) {
F_2 ( & V_2 -> V_559 . V_560 ) ;
if ( F_409 ( V_2 , V_906 ,
V_11 ) )
F_156 ( L_139 ) ;
F_4 ( & V_2 -> V_559 . V_560 ) ;
} else {
F_120 ( V_905 , V_11 ) ;
F_121 ( V_905 ) ;
}
}
static void F_630 ( struct V_1 * V_2 ,
bool V_907 , bool V_908 )
{
T_2 V_11 ;
F_623 ( V_2 ) ;
V_11 = F_16 ( V_909 ) ;
if ( V_907 ) {
V_11 |= V_910 ;
F_120 ( V_909 , V_11 ) ;
if ( F_598 ( F_16 ( V_909 ) &
V_911 , 1 ) )
F_123 ( L_140 ) ;
V_11 = F_16 ( V_909 ) ;
}
V_11 |= V_912 ;
F_120 ( V_909 , V_11 ) ;
F_121 ( V_909 ) ;
if ( F_54 ( V_2 , V_909 , V_913 , 0 , 1 ) )
F_123 ( L_141 ) ;
V_11 = F_628 ( V_2 ) ;
V_11 |= V_914 ;
F_629 ( V_2 , V_11 ) ;
F_631 ( 100 ) ;
if ( F_55 ( ( F_628 ( V_2 ) & V_915 ) == 0 ,
1 ) )
F_123 ( L_142 ) ;
if ( V_908 ) {
V_11 = F_16 ( V_909 ) ;
V_11 |= V_916 ;
F_120 ( V_909 , V_11 ) ;
F_121 ( V_909 ) ;
}
}
static void F_632 ( struct V_1 * V_2 )
{
T_2 V_11 ;
V_11 = F_16 ( V_909 ) ;
if ( ( V_11 & ( V_913 | V_912 | V_910 |
V_916 ) ) == V_913 )
return;
F_633 ( V_2 , V_917 ) ;
if ( V_11 & V_916 ) {
V_11 &= ~ V_916 ;
F_120 ( V_909 , V_11 ) ;
F_121 ( V_909 ) ;
}
V_11 = F_628 ( V_2 ) ;
V_11 |= V_918 ;
V_11 &= ~ V_914 ;
F_629 ( V_2 , V_11 ) ;
V_11 = F_16 ( V_909 ) ;
V_11 &= ~ V_912 ;
F_120 ( V_909 , V_11 ) ;
if ( F_54 ( V_2 ,
V_909 , V_913 , V_913 ,
5 ) )
F_123 ( L_143 ) ;
if ( V_11 & V_910 ) {
V_11 = F_16 ( V_909 ) ;
V_11 &= ~ V_910 ;
F_120 ( V_909 , V_11 ) ;
if ( F_598 ( ( F_16 ( V_909 ) &
V_911 ) == 0 , 1 ) )
F_123 ( L_144 ) ;
}
F_634 ( V_2 , V_917 ) ;
F_635 ( V_2 ) ;
}
void F_636 ( struct V_1 * V_2 )
{
T_2 V_11 ;
F_156 ( L_145 ) ;
if ( F_601 ( V_2 ) ) {
V_11 = F_16 ( V_919 ) ;
V_11 &= ~ V_920 ;
F_120 ( V_919 , V_11 ) ;
}
F_602 ( V_2 ) ;
F_630 ( V_2 , true , true ) ;
}
void F_637 ( struct V_1 * V_2 )
{
T_2 V_11 ;
F_156 ( L_146 ) ;
F_632 ( V_2 ) ;
F_605 ( V_2 ) ;
if ( F_601 ( V_2 ) ) {
V_11 = F_16 ( V_919 ) ;
V_11 |= V_920 ;
F_120 ( V_919 , V_11 ) ;
}
}
static int F_638 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
if ( ! F_31 ( V_41 , V_200 ) ) {
struct V_517 * V_518 =
F_639 ( V_41 ) ;
if ( ! F_611 ( V_46 , V_41 , V_518 ) ) {
F_12 ( L_125 ,
F_72 ( V_46 -> V_75 ) ) ;
return - V_263 ;
}
}
V_46 -> V_684 = false ;
return 0 ;
}
static void F_640 ( struct V_1 * V_2 ,
enum V_156 V_156 ,
struct V_18 * V_19 )
{
enum V_884 V_260 ;
T_1 V_452 ;
V_452 = F_16 ( V_921 ) & F_641 ( V_156 ) ;
V_260 = V_452 >> ( V_156 * 2 ) ;
if ( F_20 ( V_260 < V_922 || V_260 > V_923 ) )
return;
V_19 -> V_184 = F_394 ( V_2 , V_260 ) ;
}
static void F_642 ( struct V_1 * V_2 ,
enum V_156 V_156 ,
struct V_18 * V_19 )
{
enum V_884 V_260 ;
switch ( V_156 ) {
case V_604 :
V_260 = V_924 ;
break;
case V_176 :
V_260 = V_925 ;
break;
case V_178 :
V_260 = V_926 ;
break;
default:
F_123 ( L_147 ) ;
return;
}
V_19 -> V_184 = F_394 ( V_2 , V_260 ) ;
}
static void F_643 ( struct V_1 * V_2 ,
enum V_156 V_156 ,
struct V_18 * V_19 )
{
enum V_884 V_260 ;
T_1 V_452 ;
V_452 = F_16 ( V_927 ) & F_644 ( V_156 ) ;
V_260 = V_452 >> ( V_156 * 3 + 1 ) ;
if ( F_20 ( V_260 < V_922 || V_260 > V_928 ) )
return;
V_19 -> V_184 = F_394 ( V_2 , V_260 ) ;
}
static void F_645 ( struct V_1 * V_2 ,
enum V_156 V_156 ,
struct V_18 * V_19 )
{
enum V_884 V_260 ;
T_2 V_929 = F_16 ( F_646 ( V_156 ) ) ;
switch ( V_929 ) {
case V_930 :
V_260 = V_931 ;
break;
case V_932 :
V_260 = V_933 ;
break;
case V_934 :
V_260 = V_935 ;
break;
case V_936 :
V_260 = V_937 ;
break;
case V_938 :
V_260 = V_939 ;
break;
case V_940 :
V_260 = V_941 ;
break;
default:
F_167 ( V_929 ) ;
case V_942 :
return;
}
V_19 -> V_184 = F_394 ( V_2 , V_260 ) ;
}
static bool F_647 ( struct V_62 * V_46 ,
struct V_18 * V_19 ,
T_4 * V_943 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_108 V_109 ;
T_1 V_157 ;
V_19 -> V_76 = (enum V_74 ) V_46 -> V_75 ;
V_157 = F_16 ( F_62 ( V_592 ) ) ;
if ( V_157 & V_87 ) {
enum V_75 V_944 ;
switch ( V_157 & V_945 ) {
default:
F_6 ( 1 , L_148 ) ;
case V_946 :
case V_947 :
V_944 = V_94 ;
break;
case V_948 :
V_944 = V_101 ;
break;
case V_949 :
V_944 = V_360 ;
break;
}
if ( V_944 == V_46 -> V_75 )
V_19 -> V_76 = V_592 ;
}
V_109 = F_79 ( V_19 -> V_76 ) ;
if ( ! F_80 ( V_2 , V_109 ) )
return false ;
* V_943 |= F_473 ( V_109 ) ;
V_157 = F_16 ( F_53 ( V_19 -> V_76 ) ) ;
return V_157 & V_110 ;
}
static bool F_648 ( struct V_62 * V_46 ,
struct V_18 * V_19 ,
T_4 * V_943 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_108 V_109 ;
enum V_156 V_156 ;
enum V_74 V_76 ;
T_1 V_157 ;
F_649 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_156 == V_604 )
V_76 = V_950 ;
else
V_76 = V_951 ;
V_109 = F_79 ( V_76 ) ;
if ( ! F_80 ( V_2 , V_109 ) )
continue;
* V_943 |= F_473 ( V_109 ) ;
if ( ! F_650 ( V_2 ) )
break;
V_157 = F_16 ( F_651 ( V_156 ) ) ;
if ( ! ( V_157 & V_952 ) )
continue;
V_157 = F_16 ( F_652 ( V_156 ) ) ;
if ( ( V_157 & V_953 ) != F_653 ( V_46 -> V_75 ) )
continue;
V_19 -> V_76 = V_76 ;
break;
}
return F_454 ( V_19 -> V_76 ) ;
}
static void F_654 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
struct V_882 * V_883 ;
enum V_156 V_156 ;
T_2 V_157 ;
V_157 = F_16 ( F_62 ( V_19 -> V_76 ) ) ;
V_156 = ( V_157 & V_954 ) >> V_955 ;
if ( F_292 ( V_2 ) )
F_640 ( V_2 , V_156 , V_19 ) ;
else if ( F_655 ( V_2 ) )
F_643 ( V_2 , V_156 , V_19 ) ;
else if ( F_29 ( V_2 ) )
F_642 ( V_2 , V_156 , V_19 ) ;
else
F_645 ( V_2 , V_156 , V_19 ) ;
V_883 = V_19 -> V_184 ;
if ( V_883 ) {
F_20 ( ! V_883 -> V_888 . V_633 ( V_2 , V_883 ,
& V_19 -> V_152 ) ) ;
}
if ( F_52 ( V_2 ) < 9 &&
( V_156 == V_609 ) && F_16 ( V_198 ) & V_125 ) {
V_19 -> V_199 = true ;
V_157 = F_16 ( F_65 ( V_94 ) ) ;
V_19 -> V_465 = ( ( V_464 & V_157 ) >>
V_886 ) + 1 ;
F_615 ( V_46 , V_19 ) ;
}
}
static bool F_656 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
enum V_108 V_109 ;
T_4 V_943 ;
bool V_68 ;
F_657 ( V_46 , V_19 ) ;
V_109 = F_472 ( V_46 -> V_75 ) ;
if ( ! F_80 ( V_2 , V_109 ) )
return false ;
V_943 = F_473 ( V_109 ) ;
V_19 -> V_184 = NULL ;
V_68 = F_647 ( V_46 , V_19 , & V_943 ) ;
if ( F_29 ( V_2 ) &&
F_648 ( V_46 , V_19 , & V_943 ) ) {
F_20 ( V_68 ) ;
V_68 = true ;
}
if ( ! V_68 )
goto V_812;
if ( ! F_454 ( V_19 -> V_76 ) ) {
F_654 ( V_46 , V_19 ) ;
F_574 ( V_46 , V_19 ) ;
}
F_575 ( V_46 , V_19 ) ;
V_19 -> V_956 =
F_16 ( F_658 ( V_46 -> V_75 ) ) & V_957 ;
if ( F_260 ( V_2 ) || V_2 -> V_958 . V_229 >= 9 ) {
T_1 V_157 = F_16 ( F_607 ( V_46 -> V_75 ) ) ;
bool V_959 = V_157 & V_861 ;
if ( F_291 ( V_2 ) || V_2 -> V_958 . V_229 >= 10 ) {
bool V_960 = V_157 &
V_863 ;
V_19 -> V_539 = V_157 & V_862 ;
if ( V_19 -> V_539 != V_959 ||
V_19 -> V_539 != V_960 )
F_156 ( L_149 , V_157 ) ;
} else if ( V_959 ) {
F_156 ( L_150 ) ;
}
}
V_109 = F_474 ( V_46 -> V_75 ) ;
if ( F_80 ( V_2 , V_109 ) ) {
V_943 |= F_473 ( V_109 ) ;
if ( F_52 ( V_2 ) >= 9 )
F_616 ( V_46 , V_19 ) ;
else
F_618 ( V_46 , V_19 ) ;
}
if ( F_259 ( V_2 ) )
V_19 -> V_558 = F_451 ( V_46 ) &&
( F_16 ( V_562 ) & V_563 ) ;
if ( V_19 -> V_76 != V_592 &&
! F_454 ( V_19 -> V_76 ) ) {
V_19 -> V_593 =
F_16 ( F_455 ( V_19 -> V_76 ) ) + 1 ;
} else {
V_19 -> V_593 = 1 ;
}
V_812:
F_477 (power_domain, power_domain_mask)
F_81 ( V_2 , V_109 ) ;
return V_68 ;
}
static T_1 F_659 ( const struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
const struct V_231 * V_232 = F_185 ( V_70 ) ;
T_1 V_45 ;
if ( F_180 ( V_2 ) -> V_961 )
V_45 = V_232 -> V_962 -> V_963 ;
else
V_45 = F_238 ( V_327 ) ;
V_45 += V_327 -> main. V_256 ;
if ( F_158 ( V_2 ) &&
V_327 -> V_45 . V_225 & V_361 )
V_45 += ( V_327 -> V_45 . V_344 *
V_327 -> V_45 . V_343 - 1 ) * V_70 -> V_207 -> V_206 [ 0 ] ;
return V_45 ;
}
static T_1 F_660 ( const struct V_245 * V_327 )
{
int V_243 = V_327 -> V_45 . V_341 ;
int V_244 = V_327 -> V_45 . V_342 ;
T_1 V_555 = 0 ;
if ( V_243 < 0 ) {
V_555 |= V_964 << V_965 ;
V_243 = - V_243 ;
}
V_555 |= V_243 << V_965 ;
if ( V_244 < 0 ) {
V_555 |= V_964 << V_966 ;
V_244 = - V_244 ;
}
V_555 |= V_244 << V_966 ;
return V_555 ;
}
static bool F_661 ( const struct V_245 * V_327 )
{
const struct V_967 * V_71 =
& V_327 -> V_45 . V_111 -> V_44 -> V_442 ;
int V_222 = V_327 -> V_45 . V_343 ;
int V_218 = V_327 -> V_45 . V_344 ;
return V_222 > 0 && V_222 <= V_71 -> V_968 &&
V_218 > 0 && V_218 <= V_71 -> V_969 ;
}
static int F_662 ( struct V_18 * V_41 ,
struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
int V_337 , V_338 ;
T_1 V_256 ;
int V_278 ;
V_278 = F_663 ( & V_327 -> V_45 ,
& V_327 -> V_970 ,
V_971 ,
V_971 ,
true , true ) ;
if ( V_278 )
return V_278 ;
if ( ! V_70 )
return 0 ;
if ( V_70 -> V_208 != V_209 ) {
F_156 ( L_151 ) ;
return - V_263 ;
}
V_337 = V_327 -> V_45 . V_337 >> 16 ;
V_338 = V_327 -> V_45 . V_338 >> 16 ;
F_205 ( & V_337 , & V_338 , V_327 , 0 ) ;
V_256 = F_211 ( & V_337 , & V_338 , V_327 , 0 ) ;
if ( V_337 != 0 || V_338 != 0 ) {
F_156 ( L_152 ) ;
return - V_263 ;
}
V_327 -> main. V_256 = V_256 ;
return 0 ;
}
static T_1 F_664 ( const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
return V_106 |
V_972 |
V_973 |
F_665 ( V_70 -> V_242 [ 0 ] ) ;
}
static bool F_666 ( const struct V_245 * V_327 )
{
int V_222 = V_327 -> V_45 . V_343 ;
return F_661 ( V_327 ) && F_667 ( V_222 , 64 ) ;
}
static int F_668 ( struct V_259 * V_111 ,
struct V_18 * V_41 ,
struct V_245 * V_327 )
{
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
int V_278 ;
V_278 = F_662 ( V_41 , V_327 ) ;
if ( V_278 )
return V_278 ;
if ( ! V_70 )
return 0 ;
if ( ! F_666 ( V_327 ) ) {
F_669 ( L_153 ,
V_327 -> V_45 . V_343 ,
V_327 -> V_45 . V_344 ) ;
return - V_263 ;
}
switch ( V_70 -> V_242 [ 0 ] ) {
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
default:
F_156 ( L_154 ,
V_70 -> V_242 [ 0 ] ) ;
return - V_263 ;
}
V_327 -> V_372 = F_664 ( V_41 , V_327 ) ;
return 0 ;
}
static void F_670 ( struct V_259 * V_111 ,
const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
T_1 V_974 = 0 , V_45 = 0 , V_555 = 0 , V_221 = 0 ;
unsigned long V_373 ;
if ( V_327 && V_327 -> V_45 . V_328 ) {
unsigned int V_222 = V_327 -> V_45 . V_343 ;
unsigned int V_218 = V_327 -> V_45 . V_344 ;
V_974 = V_327 -> V_372 ;
V_221 = ( V_218 << 12 ) | V_222 ;
V_45 = F_659 ( V_327 ) ;
V_555 = F_660 ( V_327 ) ;
}
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
if ( V_111 -> V_975 . V_45 != V_45 ||
V_111 -> V_975 . V_221 != V_221 ||
V_111 -> V_975 . V_974 != V_974 ) {
F_265 ( F_76 ( V_94 ) , 0 ) ;
F_265 ( F_671 ( V_94 ) , V_45 ) ;
F_265 ( V_976 , V_221 ) ;
F_265 ( F_672 ( V_94 ) , V_555 ) ;
F_265 ( F_76 ( V_94 ) , V_974 ) ;
V_111 -> V_975 . V_45 = V_45 ;
V_111 -> V_975 . V_221 = V_221 ;
V_111 -> V_975 . V_974 = V_974 ;
} else {
F_265 ( F_672 ( V_94 ) , V_555 ) ;
}
F_277 ( F_76 ( V_94 ) ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static void F_673 ( struct V_259 * V_111 ,
struct V_62 * V_46 )
{
F_670 ( V_111 , NULL , NULL ) ;
}
static T_1 F_674 ( const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
struct V_62 * V_46 = F_41 ( V_41 -> V_45 . V_46 ) ;
T_1 V_974 ;
V_974 = V_977 ;
if ( F_14 ( V_2 ) )
V_974 |= V_978 ;
V_974 |= F_675 ( V_46 -> V_75 ) ;
switch ( V_327 -> V_45 . V_343 ) {
case 64 :
V_974 |= V_979 ;
break;
case 128 :
V_974 |= V_980 ;
break;
case 256 :
V_974 |= V_981 ;
break;
default:
F_167 ( V_327 -> V_45 . V_343 ) ;
return 0 ;
}
if ( V_327 -> V_45 . V_225 & V_361 )
V_974 |= V_982 ;
return V_974 ;
}
static bool F_676 ( const struct V_245 * V_327 )
{
struct V_1 * V_2 =
F_34 ( V_327 -> V_45 . V_111 -> V_44 ) ;
int V_222 = V_327 -> V_45 . V_343 ;
int V_218 = V_327 -> V_45 . V_344 ;
if ( ! F_661 ( V_327 ) )
return false ;
switch ( V_222 ) {
case 256 :
case 128 :
case 64 :
break;
default:
return false ;
}
if ( F_677 ( V_2 ) &&
V_327 -> V_45 . V_225 & V_264 ) {
if ( V_218 < 8 || V_218 > V_222 )
return false ;
} else {
if ( V_218 != V_222 )
return false ;
}
return true ;
}
static int F_678 ( struct V_259 * V_111 ,
struct V_18 * V_41 ,
struct V_245 * V_327 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
const struct V_205 * V_70 = V_327 -> V_45 . V_70 ;
enum V_75 V_75 = V_111 -> V_75 ;
int V_278 ;
V_278 = F_662 ( V_41 , V_327 ) ;
if ( V_278 )
return V_278 ;
if ( ! V_70 )
return 0 ;
if ( ! F_676 ( V_327 ) ) {
F_669 ( L_153 ,
V_327 -> V_45 . V_343 ,
V_327 -> V_45 . V_344 ) ;
return - V_263 ;
}
if ( V_70 -> V_242 [ 0 ] != V_327 -> V_45 . V_343 * V_70 -> V_207 -> V_206 [ 0 ] ) {
F_156 ( L_155 ,
V_70 -> V_242 [ 0 ] , V_327 -> V_45 . V_343 ) ;
return - V_263 ;
}
if ( F_11 ( V_2 ) && V_75 == V_360 &&
V_327 -> V_45 . V_328 && V_327 -> V_45 . V_341 < 0 ) {
F_156 ( L_156 ) ;
return - V_263 ;
}
V_327 -> V_372 = F_674 ( V_41 , V_327 ) ;
return 0 ;
}
static void F_679 ( struct V_259 * V_111 ,
const struct V_18 * V_41 ,
const struct V_245 * V_327 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
enum V_75 V_75 = V_111 -> V_75 ;
T_1 V_974 = 0 , V_45 = 0 , V_555 = 0 , V_983 = 0 ;
unsigned long V_373 ;
if ( V_327 && V_327 -> V_45 . V_328 ) {
V_974 = V_327 -> V_372 ;
if ( V_327 -> V_45 . V_344 != V_327 -> V_45 . V_343 )
V_983 = V_984 | ( V_327 -> V_45 . V_344 - 1 ) ;
V_45 = F_659 ( V_327 ) ;
V_555 = F_660 ( V_327 ) ;
}
F_264 ( & V_2 -> V_377 . V_378 , V_373 ) ;
if ( V_111 -> V_975 . V_45 != V_45 ||
V_111 -> V_975 . V_221 != V_983 ||
V_111 -> V_975 . V_974 != V_974 ) {
F_265 ( F_76 ( V_75 ) , V_974 ) ;
if ( F_677 ( V_2 ) )
F_265 ( F_680 ( V_75 ) , V_983 ) ;
F_265 ( F_672 ( V_75 ) , V_555 ) ;
F_265 ( F_671 ( V_75 ) , V_45 ) ;
V_111 -> V_975 . V_45 = V_45 ;
V_111 -> V_975 . V_221 = V_983 ;
V_111 -> V_975 . V_974 = V_974 ;
} else {
F_265 ( F_672 ( V_75 ) , V_555 ) ;
F_265 ( F_671 ( V_75 ) , V_45 ) ;
}
F_277 ( F_671 ( V_75 ) ) ;
F_278 ( & V_2 -> V_377 . V_378 , V_373 ) ;
}
static void F_681 ( struct V_259 * V_111 ,
struct V_62 * V_46 )
{
F_679 ( V_111 , NULL , NULL ) ;
}
struct V_205 *
F_682 ( struct V_231 * V_232 ,
struct V_271 * V_317 )
{
struct V_246 * V_247 ;
int V_278 ;
V_247 = F_508 ( sizeof( * V_247 ) , V_635 ) ;
if ( ! V_247 )
return F_683 ( - V_636 ) ;
V_278 = F_229 ( V_247 , V_232 , V_317 ) ;
if ( V_278 )
goto V_53;
return & V_247 -> V_45 ;
V_53:
F_236 ( V_247 ) ;
return F_683 ( V_278 ) ;
}
static T_1
F_684 ( int V_222 , int V_864 )
{
T_1 V_241 = F_221 ( V_222 * V_864 , 8 ) ;
return F_171 ( V_241 , 64 ) ;
}
static T_1
F_685 ( struct V_526 * V_431 , int V_864 )
{
T_1 V_241 = F_684 ( V_431 -> V_765 , V_864 ) ;
return F_686 ( V_241 * V_431 -> V_764 ) ;
}
static struct V_205 *
F_687 ( struct V_43 * V_44 ,
struct V_526 * V_431 ,
int V_985 , int V_864 )
{
struct V_205 * V_70 ;
struct V_231 * V_232 ;
struct V_271 V_317 = { 0 } ;
V_232 = F_688 ( F_34 ( V_44 ) ,
F_685 ( V_431 , V_864 ) ) ;
if ( F_191 ( V_232 ) )
return F_689 ( V_232 ) ;
V_317 . V_222 = V_431 -> V_765 ;
V_317 . V_218 = V_431 -> V_764 ;
V_317 . V_242 [ 0 ] = F_684 ( V_317 . V_222 ,
V_864 ) ;
V_317 . V_274 = F_690 ( V_864 , V_985 ) ;
V_70 = F_682 ( V_232 , & V_317 ) ;
if ( F_191 ( V_70 ) )
F_230 ( V_232 ) ;
return V_70 ;
}
static struct V_205 *
F_691 ( struct V_43 * V_44 ,
struct V_526 * V_431 )
{
#ifdef F_692
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_231 * V_232 ;
struct V_205 * V_70 ;
if ( ! V_2 -> V_986 )
return NULL ;
if ( ! V_2 -> V_986 -> V_70 )
return NULL ;
V_232 = V_2 -> V_986 -> V_70 -> V_232 ;
F_596 ( ! V_232 ) ;
V_70 = & V_2 -> V_986 -> V_70 -> V_45 ;
if ( V_70 -> V_242 [ 0 ] < F_684 ( V_431 -> V_765 ,
V_70 -> V_207 -> V_206 [ 0 ] * 8 ) )
return NULL ;
if ( V_232 -> V_45 . V_221 < V_431 -> V_764 * V_70 -> V_242 [ 0 ] )
return NULL ;
F_239 ( V_70 ) ;
return V_70 ;
#else
return NULL ;
#endif
}
static int F_693 ( struct V_432 * V_24 ,
struct V_123 * V_46 ,
struct V_526 * V_431 ,
struct V_205 * V_70 ,
int V_243 , int V_244 )
{
struct V_333 * V_327 ;
int V_765 , V_764 ;
int V_278 ;
V_327 = F_694 ( V_24 , V_46 -> V_69 ) ;
if ( F_191 ( V_327 ) )
return F_243 ( V_327 ) ;
if ( V_431 )
F_695 ( V_431 , & V_765 , & V_764 ) ;
else
V_765 = V_764 = 0 ;
V_278 = F_696 ( V_327 , V_70 ? V_46 : NULL ) ;
if ( V_278 )
return V_278 ;
F_697 ( V_327 , V_70 ) ;
V_327 -> V_341 = 0 ;
V_327 -> V_342 = 0 ;
V_327 -> V_343 = V_765 ;
V_327 -> V_344 = V_764 ;
V_327 -> V_337 = V_243 << 16 ;
V_327 -> V_338 = V_244 << 16 ;
V_327 -> V_339 = V_765 << 16 ;
V_327 -> V_340 = V_764 << 16 ;
return 0 ;
}
int F_698 ( struct V_580 * V_632 ,
struct V_526 * V_431 ,
struct V_987 * V_988 ,
struct V_433 * V_434 )
{
struct V_62 * V_62 ;
struct V_517 * V_517 =
F_699 ( V_632 ) ;
struct V_123 * V_989 ;
struct V_612 * V_518 = & V_517 -> V_45 ;
struct V_123 * V_46 = NULL ;
struct V_43 * V_44 = V_518 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_205 * V_70 ;
struct V_967 * V_71 = & V_44 -> V_442 ;
struct V_432 * V_24 = NULL , * V_990 = NULL ;
struct V_578 * V_991 ;
struct V_18 * V_41 ;
int V_278 , V_113 = - 1 ;
F_156 ( L_157 ,
V_632 -> V_45 . V_260 , V_632 -> V_8 ,
V_518 -> V_45 . V_260 , V_518 -> V_8 ) ;
V_988 -> V_990 = NULL ;
F_20 ( ! F_700 ( & V_71 -> V_992 ) ) ;
if ( V_632 -> V_24 -> V_46 ) {
V_46 = V_632 -> V_24 -> V_46 ;
V_278 = F_701 ( & V_46 -> V_443 , V_434 ) ;
if ( V_278 )
goto V_993;
goto V_56;
}
F_237 (dev, possible_crtc) {
V_113 ++ ;
if ( ! ( V_518 -> V_994 & ( 1 << V_113 ) ) )
continue;
V_278 = F_701 ( & V_989 -> V_443 , V_434 ) ;
if ( V_278 )
goto V_993;
if ( V_989 -> V_24 -> V_514 ) {
F_702 ( & V_989 -> V_443 ) ;
continue;
}
V_46 = V_989 ;
break;
}
if ( ! V_46 ) {
F_156 ( L_158 ) ;
V_278 = - V_995 ;
goto V_993;
}
V_56:
V_62 = F_41 ( V_46 ) ;
V_278 = F_701 ( & V_46 -> V_69 -> V_443 , V_434 ) ;
if ( V_278 )
goto V_993;
V_24 = F_494 ( V_44 ) ;
V_990 = F_494 ( V_44 ) ;
if ( ! V_24 || ! V_990 ) {
V_278 = - V_636 ;
goto V_993;
}
V_24 -> V_445 = V_434 ;
V_990 -> V_445 = V_434 ;
V_991 = F_703 ( V_24 , V_632 ) ;
if ( F_191 ( V_991 ) ) {
V_278 = F_243 ( V_991 ) ;
goto V_993;
}
V_278 = F_704 ( V_991 , V_46 ) ;
if ( V_278 )
goto V_993;
V_41 = F_495 ( V_24 , V_62 ) ;
if ( F_191 ( V_41 ) ) {
V_278 = F_243 ( V_41 ) ;
goto V_993;
}
V_41 -> V_45 . V_68 = V_41 -> V_45 . V_514 = true ;
if ( ! V_431 )
V_431 = & V_996 ;
V_70 = F_691 ( V_44 , V_431 ) ;
if ( V_70 == NULL ) {
F_156 ( L_159 ) ;
V_70 = F_687 ( V_44 , V_431 , 24 , 32 ) ;
} else
F_156 ( L_160 ) ;
if ( F_191 ( V_70 ) ) {
F_156 ( L_161 ) ;
V_278 = F_243 ( V_70 ) ;
goto V_993;
}
V_278 = F_693 ( V_24 , V_46 , V_431 , V_70 , 0 , 0 ) ;
if ( V_278 )
goto V_993;
F_244 ( V_70 ) ;
V_278 = F_497 ( & V_41 -> V_45 , V_431 ) ;
if ( V_278 )
goto V_993;
V_278 = F_502 ( F_703 ( V_990 , V_632 ) ) ;
if ( ! V_278 )
V_278 = F_502 ( F_705 ( V_990 , V_46 ) ) ;
if ( ! V_278 )
V_278 = F_502 ( F_694 ( V_990 , V_46 -> V_69 ) ) ;
if ( V_278 ) {
F_156 ( L_162 , V_278 ) ;
goto V_993;
}
V_278 = F_706 ( V_24 ) ;
if ( V_278 ) {
F_156 ( L_163 ) ;
goto V_993;
}
V_988 -> V_990 = V_990 ;
F_323 ( V_24 ) ;
F_411 ( V_2 , V_62 -> V_75 ) ;
return true ;
V_993:
if ( V_24 ) {
F_323 ( V_24 ) ;
V_24 = NULL ;
}
if ( V_990 ) {
F_323 ( V_990 ) ;
V_990 = NULL ;
}
if ( V_278 == - V_437 )
return V_278 ;
return false ;
}
void F_707 ( struct V_580 * V_632 ,
struct V_987 * V_988 ,
struct V_433 * V_434 )
{
struct V_517 * V_517 =
F_699 ( V_632 ) ;
struct V_612 * V_518 = & V_517 -> V_45 ;
struct V_432 * V_24 = V_988 -> V_990 ;
int V_278 ;
F_156 ( L_157 ,
V_632 -> V_45 . V_260 , V_632 -> V_8 ,
V_518 -> V_45 . V_260 , V_518 -> V_8 ) ;
if ( ! V_24 )
return;
V_278 = F_310 ( V_24 , V_434 ) ;
if ( V_278 )
F_156 ( L_164 , V_278 ) ;
F_323 ( V_24 ) ;
}
static int F_708 ( struct V_43 * V_44 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
T_1 V_26 = V_19 -> V_152 . V_26 ;
if ( ( V_26 & V_824 ) == V_750 )
return V_2 -> V_677 . V_787 ;
else if ( F_69 ( V_2 ) )
return 120000 ;
else if ( ! F_49 ( V_2 ) )
return 96000 ;
else
return 48000 ;
}
static void F_592 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_75 = V_19 -> V_76 ;
T_1 V_26 = V_19 -> V_152 . V_26 ;
T_1 V_682 ;
struct V_26 clock ;
int V_20 ;
int V_25 = F_708 ( V_44 , V_19 ) ;
if ( ( V_26 & V_997 ) == 0 )
V_682 = V_19 -> V_152 . V_624 ;
else
V_682 = V_19 -> V_152 . V_625 ;
clock . V_35 = ( V_682 & V_998 ) >> V_999 ;
if ( F_28 ( V_2 ) ) {
clock . V_32 = F_709 ( ( V_682 & V_1000 ) >> V_1001 ) - 1 ;
clock . V_28 = ( V_682 & V_1002 ) >> V_1003 ;
} else {
clock . V_32 = ( V_682 & V_1004 ) >> V_1001 ;
clock . V_28 = ( V_682 & V_1005 ) >> V_1003 ;
}
if ( ! F_49 ( V_2 ) ) {
if ( F_28 ( V_2 ) )
clock . V_30 = F_709 ( ( V_26 & V_1006 ) >>
V_740 ) ;
else
clock . V_30 = F_709 ( ( V_26 & V_1007 ) >>
V_741 ) ;
switch ( V_26 & V_1008 ) {
case V_737 :
clock . V_31 = V_26 & V_743 ?
5 : 10 ;
break;
case V_736 :
clock . V_31 = V_26 & V_744 ?
7 : 14 ;
break;
default:
F_156 ( L_165
L_166 , ( int ) ( V_26 & V_1008 ) ) ;
return;
}
if ( F_28 ( V_2 ) )
V_20 = F_19 ( V_25 , & clock ) ;
else
V_20 = F_22 ( V_25 , & clock ) ;
} else {
T_1 V_1009 = F_78 ( V_2 ) ? 0 : F_16 ( V_102 ) ;
bool V_1010 = ( V_75 == 1 ) && ( V_1009 & V_135 ) ;
if ( V_1010 ) {
clock . V_30 = F_709 ( ( V_26 & V_1011 ) >>
V_741 ) ;
if ( V_1009 & V_1012 )
clock . V_31 = 7 ;
else
clock . V_31 = 14 ;
} else {
if ( V_26 & V_752 )
clock . V_30 = 2 ;
else {
clock . V_30 = ( ( V_26 & V_1013 ) >>
V_741 ) + 2 ;
}
if ( V_26 & V_753 )
clock . V_31 = 4 ;
else
clock . V_31 = 2 ;
}
V_20 = F_22 ( V_25 , & clock ) ;
}
V_19 -> V_20 = V_20 ;
}
int F_710 ( int V_1014 ,
const struct V_669 * V_670 )
{
if ( ! V_670 -> V_675 )
return 0 ;
return F_39 ( ( T_4 ) V_670 -> V_674 * V_1014 , V_670 -> V_675 ) ;
}
static void F_622 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
F_592 ( V_46 , V_19 ) ;
V_19 -> V_45 . V_72 . V_73 =
F_710 ( F_13 ( V_2 , V_19 ) ,
& V_19 -> V_590 ) ;
}
struct V_526 * F_711 ( struct V_43 * V_44 ,
struct V_123 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
enum V_74 V_76 ;
struct V_526 * V_431 ;
struct V_18 * V_19 ;
T_1 V_1015 , V_773 , V_1016 , V_1017 ;
enum V_75 V_75 = V_62 -> V_75 ;
V_431 = F_508 ( sizeof( * V_431 ) , V_635 ) ;
if ( ! V_431 )
return NULL ;
V_19 = F_508 ( sizeof( * V_19 ) , V_635 ) ;
if ( ! V_19 ) {
F_236 ( V_431 ) ;
return NULL ;
}
V_19 -> V_76 = (enum V_74 ) V_75 ;
V_19 -> V_593 = 1 ;
V_19 -> V_152 . V_26 = F_16 ( F_57 ( V_75 ) ) ;
V_19 -> V_152 . V_624 = F_16 ( F_487 ( V_75 ) ) ;
V_19 -> V_152 . V_625 = F_16 ( F_488 ( V_75 ) ) ;
F_592 ( V_62 , V_19 ) ;
V_431 -> clock = V_19 -> V_20 / V_19 -> V_593 ;
V_76 = V_19 -> V_76 ;
V_1015 = F_16 ( F_371 ( V_76 ) ) ;
V_773 = F_16 ( F_375 ( V_76 ) ) ;
V_1016 = F_16 ( F_377 ( V_76 ) ) ;
V_1017 = F_16 ( F_381 ( V_76 ) ) ;
V_431 -> V_765 = ( V_1015 & 0xffff ) + 1 ;
V_431 -> V_766 = ( ( V_1015 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_767 = ( V_773 & 0xffff ) + 1 ;
V_431 -> V_768 = ( ( V_773 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_764 = ( V_1016 & 0xffff ) + 1 ;
V_431 -> V_769 = ( ( V_1016 & 0xffff0000 ) >> 16 ) + 1 ;
V_431 -> V_770 = ( V_1017 & 0xffff ) + 1 ;
V_431 -> V_771 = ( ( V_1017 & 0xffff0000 ) >> 16 ) + 1 ;
F_579 ( V_431 ) ;
F_236 ( V_19 ) ;
return V_431 ;
}
static void F_712 ( struct V_123 * V_46 )
{
struct V_62 * V_62 = F_41 ( V_46 ) ;
F_713 ( V_46 ) ;
F_236 ( V_62 ) ;
}
static bool F_714 ( struct V_332 * V_111 ,
struct V_333 * V_24 )
{
struct V_245 * V_1018 = F_235 ( V_24 ) ;
struct V_245 * V_1019 = F_235 ( V_111 -> V_24 ) ;
if ( V_1018 -> V_45 . V_328 != V_1019 -> V_45 . V_328 )
return true ;
if ( ! V_1019 -> V_45 . V_70 || ! V_1018 -> V_45 . V_70 )
return false ;
if ( V_1019 -> V_45 . V_70 -> V_208 != V_1018 -> V_45 . V_70 -> V_208 ||
V_1019 -> V_45 . V_225 != V_1018 -> V_45 . V_225 ||
F_251 ( & V_1018 -> V_45 . V_345 ) != F_251 ( & V_1019 -> V_45 . V_345 ) ||
F_252 ( & V_1018 -> V_45 . V_345 ) != F_252 ( & V_1019 -> V_45 . V_345 ) ||
F_251 ( & V_1018 -> V_45 . V_346 ) != F_251 ( & V_1019 -> V_45 . V_346 ) ||
F_252 ( & V_1018 -> V_45 . V_346 ) != F_252 ( & V_1019 -> V_45 . V_346 ) )
return true ;
return false ;
}
static bool F_715 ( struct V_245 * V_24 )
{
int V_339 = F_251 ( & V_24 -> V_45 . V_345 ) >> 16 ;
int V_340 = F_252 ( & V_24 -> V_45 . V_345 ) >> 16 ;
int V_424 = F_251 ( & V_24 -> V_45 . V_346 ) ;
int V_425 = F_252 ( & V_24 -> V_45 . V_346 ) ;
return ( V_339 != V_424 || V_340 != V_425 ) ;
}
int F_716 ( struct V_23 * V_41 ,
struct V_333 * V_327 )
{
struct V_18 * V_19 = F_240 ( V_41 ) ;
struct V_123 * V_46 = V_41 -> V_46 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_259 * V_111 = F_212 ( V_327 -> V_111 ) ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_245 * V_1020 =
F_235 ( V_111 -> V_45 . V_24 ) ;
bool V_435 = F_17 ( V_41 ) ;
bool V_1021 = V_46 -> V_24 -> V_68 ;
bool V_1022 = V_41 -> V_68 ;
bool V_1023 , V_1024 , V_328 , V_1025 ;
struct V_205 * V_70 = V_327 -> V_70 ;
int V_278 ;
if ( F_52 ( V_2 ) >= 9 && V_111 -> V_260 != V_261 ) {
V_278 = F_401 (
F_240 ( V_41 ) ,
F_235 ( V_327 ) ) ;
if ( V_278 )
return V_278 ;
}
V_1025 = V_1020 -> V_45 . V_328 ;
V_328 = V_327 -> V_328 ;
if ( ! V_1021 && F_20 ( V_1025 ) )
V_1025 = false ;
if ( ! V_1022 ) {
V_327 -> V_328 = V_328 = false ;
F_240 ( V_41 ) -> V_330 &= ~ F_232 ( V_111 -> V_260 ) ;
}
if ( ! V_1025 && ! V_328 )
return 0 ;
if ( V_70 != V_1020 -> V_45 . V_70 )
V_19 -> V_1026 = true ;
V_1023 = V_1025 && ( ! V_328 || V_435 ) ;
V_1024 = V_328 && ( ! V_1025 || V_435 ) ;
F_717 ( L_167 ,
V_62 -> V_45 . V_45 . V_260 , V_62 -> V_45 . V_8 ,
V_111 -> V_45 . V_45 . V_260 , V_111 -> V_45 . V_8 ,
V_70 ? V_70 -> V_45 . V_260 : - 1 ) ;
F_717 ( L_168 ,
V_111 -> V_45 . V_45 . V_260 , V_111 -> V_45 . V_8 ,
V_1025 , V_328 ,
V_1023 , V_1024 , V_435 ) ;
if ( V_1024 ) {
if ( F_52 ( V_2 ) < 5 && ! F_93 ( V_2 ) )
V_19 -> V_577 = true ;
if ( V_111 -> V_260 != V_261 )
V_19 -> V_574 = true ;
} else if ( V_1023 ) {
if ( F_52 ( V_2 ) < 5 && ! F_93 ( V_2 ) )
V_19 -> V_568 = true ;
if ( V_111 -> V_260 != V_261 )
V_19 -> V_574 = true ;
} else if ( F_714 ( & V_111 -> V_45 , V_327 ) ) {
if ( F_52 ( V_2 ) < 5 && ! F_93 ( V_2 ) ) {
V_19 -> V_577 = true ;
V_19 -> V_568 = true ;
}
}
if ( V_328 || V_1025 )
V_19 -> V_567 |= V_111 -> V_348 ;
if ( V_111 -> V_260 == V_119 && F_258 ( V_2 ) &&
F_715 ( F_235 ( V_327 ) ) &&
! F_715 ( V_1020 ) )
V_19 -> V_575 = true ;
return 0 ;
}
static bool F_718 ( const struct V_517 * V_1027 ,
const struct V_517 * V_1028 )
{
return V_1027 == V_1028 || ( V_1027 -> V_1029 & ( 1 << V_1028 -> type ) &&
V_1028 -> V_1029 & ( 1 << V_1027 -> type ) ) ;
}
static bool F_719 ( struct V_432 * V_24 ,
struct V_62 * V_46 ,
struct V_517 * V_518 )
{
struct V_517 * V_1030 ;
struct V_580 * V_632 ;
struct V_578 * V_991 ;
int V_113 ;
F_432 (state, connector, connector_state, i) {
if ( V_991 -> V_46 != & V_46 -> V_45 )
continue;
V_1030 =
F_433 ( V_991 -> V_582 ) ;
if ( ! F_718 ( V_518 , V_1030 ) )
return false ;
}
return true ;
}
static int F_720 ( struct V_123 * V_46 ,
struct V_23 * V_41 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_18 * V_19 =
F_240 ( V_41 ) ;
struct V_432 * V_24 = V_41 -> V_24 ;
int V_278 ;
bool V_435 = F_17 ( V_41 ) ;
if ( V_435 && ! V_41 -> V_68 )
V_19 -> V_568 = true ;
if ( V_435 && V_41 -> V_514 &&
V_2 -> V_448 . V_1031 &&
! F_20 ( V_19 -> V_184 ) ) {
V_278 = V_2 -> V_448 . V_1031 ( V_62 ,
V_19 ) ;
if ( V_278 )
return V_278 ;
}
if ( V_41 -> V_1032 ) {
V_278 = F_721 ( V_46 , V_41 ) ;
if ( V_278 )
return V_278 ;
V_41 -> V_1033 = true ;
}
V_278 = 0 ;
if ( V_2 -> V_448 . V_1034 ) {
V_278 = V_2 -> V_448 . V_1034 ( V_19 ) ;
if ( V_278 ) {
F_156 ( L_169 ) ;
return V_278 ;
}
}
if ( V_2 -> V_448 . V_1035 &&
! F_309 ( V_24 ) -> V_436 ) {
if ( F_20 ( ! V_2 -> V_448 . V_1034 ) )
return 0 ;
V_278 = V_2 -> V_448 . V_1035 ( V_44 ,
V_62 ,
V_19 ) ;
if ( V_278 ) {
F_156 ( L_170 ) ;
return V_278 ;
}
} else if ( V_2 -> V_448 . V_1035 ) {
if ( F_69 ( V_2 ) && F_52 ( V_2 ) < 9 )
V_19 -> V_1036 . V_1037 . V_1038 = V_19 -> V_1036 . V_1037 . V_1039 ;
}
if ( F_52 ( V_2 ) >= 9 ) {
if ( V_435 )
V_278 = F_400 ( V_19 ) ;
if ( ! V_278 )
V_278 = F_722 ( V_62 ,
V_19 ) ;
if ( ! V_278 )
V_278 = F_723 ( V_2 , V_62 ,
V_19 ) ;
}
return V_278 ;
}
static void F_724 ( struct V_43 * V_44 )
{
struct V_631 * V_632 ;
struct V_1040 V_1041 ;
F_725 ( V_44 , & V_1041 ) ;
F_726 (connector, &conn_iter) {
if ( V_632 -> V_45 . V_24 -> V_46 )
F_727 ( & V_632 -> V_45 ) ;
if ( V_632 -> V_45 . V_518 ) {
V_632 -> V_45 . V_24 -> V_582 =
V_632 -> V_45 . V_518 ;
V_632 -> V_45 . V_24 -> V_46 =
V_632 -> V_45 . V_518 -> V_46 ;
F_728 ( & V_632 -> V_45 ) ;
} else {
V_632 -> V_45 . V_24 -> V_582 = NULL ;
V_632 -> V_45 . V_24 -> V_46 = NULL ;
}
}
F_729 ( & V_1041 ) ;
}
static void
F_730 ( struct V_631 * V_632 ,
struct V_18 * V_19 )
{
const struct V_1042 * V_958 = & V_632 -> V_45 . V_1043 ;
int V_864 = V_19 -> V_644 ;
F_156 ( L_171 ,
V_632 -> V_45 . V_45 . V_260 ,
V_632 -> V_45 . V_8 ) ;
if ( V_958 -> V_527 != 0 && V_958 -> V_527 * 3 < V_864 ) {
F_156 ( L_172 ,
V_864 , V_958 -> V_527 * 3 ) ;
V_19 -> V_644 = V_958 -> V_527 * 3 ;
}
if ( V_958 -> V_527 == 0 && V_864 > 24 ) {
F_156 ( L_173 ,
V_864 ) ;
V_19 -> V_644 = 24 ;
}
}
static int
F_731 ( struct V_62 * V_46 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
struct V_432 * V_24 ;
struct V_580 * V_632 ;
struct V_578 * V_991 ;
int V_864 , V_113 ;
if ( ( F_93 ( V_2 ) || F_10 ( V_2 ) ||
F_11 ( V_2 ) ) )
V_864 = 10 * 3 ;
else if ( F_52 ( V_2 ) >= 5 )
V_864 = 12 * 3 ;
else
V_864 = 8 * 3 ;
V_19 -> V_644 = V_864 ;
V_24 = V_19 -> V_45 . V_24 ;
F_432 (state, connector, connector_state, i) {
if ( V_991 -> V_46 != & V_46 -> V_45 )
continue;
F_730 ( F_506 ( V_632 ) ,
V_19 ) ;
}
return V_864 ;
}
static void F_732 ( const struct V_526 * V_431 )
{
F_156 ( L_174
L_175 ,
V_431 -> V_73 ,
V_431 -> V_551 , V_431 -> V_658 ,
V_431 -> V_760 , V_431 -> V_757 ,
V_431 -> V_552 , V_431 -> V_762 ,
V_431 -> V_763 , V_431 -> V_754 , V_431 -> type , V_431 -> V_324 ) ;
}
static inline void
F_733 ( struct V_18 * V_19 , char * V_260 ,
unsigned int V_1044 , struct V_669 * V_670 )
{
F_156 ( L_176 ,
V_260 , V_1044 ,
V_670 -> V_672 , V_670 -> V_673 ,
V_670 -> V_674 , V_670 -> V_675 , V_670 -> V_671 ) ;
}
static void F_734 ( struct V_62 * V_46 ,
struct V_18 * V_19 ,
const char * V_1045 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_332 * V_111 ;
struct V_259 * V_259 ;
struct V_245 * V_24 ;
struct V_205 * V_70 ;
F_156 ( L_177 ,
V_46 -> V_45 . V_45 . V_260 , V_46 -> V_45 . V_8 , V_1045 ) ;
F_156 ( L_178 ,
F_735 ( V_19 -> V_76 ) ,
V_19 -> V_644 , V_19 -> V_776 ) ;
if ( V_19 -> V_199 )
F_733 ( V_19 , L_179 ,
V_19 -> V_465 ,
& V_19 -> V_590 ) ;
if ( V_19 -> V_539 )
F_156 ( L_180 ) ;
if ( F_396 ( V_19 ) ) {
F_733 ( V_19 , L_181 ,
V_19 -> V_1044 , & V_19 -> V_690 ) ;
if ( V_19 -> V_688 )
F_733 ( V_19 , L_182 ,
V_19 -> V_1044 ,
& V_19 -> V_691 ) ;
}
F_156 ( L_183 ,
V_19 -> V_615 , V_19 -> V_1046 ) ;
F_156 ( L_184 ) ;
F_736 ( & V_19 -> V_45 . V_431 ) ;
F_156 ( L_185 ) ;
F_736 ( & V_19 -> V_45 . V_72 ) ;
F_732 ( & V_19 -> V_45 . V_72 ) ;
F_156 ( L_186 ,
V_19 -> V_20 ,
V_19 -> V_380 , V_19 -> V_379 ,
V_19 -> V_647 ) ;
if ( F_52 ( V_2 ) >= 9 )
F_156 ( L_187 ,
V_46 -> V_384 ,
V_19 -> V_383 . V_542 ,
V_19 -> V_383 . V_421 ) ;
if ( F_158 ( V_2 ) )
F_156 ( L_188 ,
V_19 -> V_598 . V_599 ,
V_19 -> V_598 . V_603 ,
V_19 -> V_598 . V_1047 ) ;
else
F_156 ( L_189 ,
V_19 -> V_451 . V_555 ,
V_19 -> V_451 . V_221 ,
F_737 ( V_19 -> V_451 . V_124 ) ) ;
F_156 ( L_190 ,
V_19 -> V_558 , V_19 -> V_203 ) ;
F_738 ( V_2 , & V_19 -> V_152 ) ;
F_156 ( L_191 ) ;
F_739 (plane, &dev->mode_config.plane_list, head) {
struct V_1048 V_1049 ;
V_259 = F_212 ( V_111 ) ;
if ( V_259 -> V_75 != V_46 -> V_75 )
continue;
V_24 = F_235 ( V_111 -> V_24 ) ;
V_70 = V_24 -> V_45 . V_70 ;
if ( ! V_70 ) {
F_156 ( L_192 ,
V_111 -> V_45 . V_260 , V_111 -> V_8 , V_24 -> V_421 ) ;
continue;
}
F_156 ( L_193 ,
V_111 -> V_45 . V_260 , V_111 -> V_8 ,
V_70 -> V_45 . V_260 , V_70 -> V_222 , V_70 -> V_218 ,
F_740 ( V_70 -> V_207 -> V_207 , & V_1049 ) ) ;
if ( F_52 ( V_2 ) >= 9 )
F_156 ( L_194 ,
V_24 -> V_421 ,
V_24 -> V_45 . V_345 . V_288 >> 16 ,
V_24 -> V_45 . V_345 . y1 >> 16 ,
F_251 ( & V_24 -> V_45 . V_345 ) >> 16 ,
F_252 ( & V_24 -> V_45 . V_345 ) >> 16 ,
V_24 -> V_45 . V_346 . V_288 , V_24 -> V_45 . V_346 . y1 ,
F_251 ( & V_24 -> V_45 . V_346 ) ,
F_252 ( & V_24 -> V_45 . V_346 ) ) ;
}
}
static bool F_741 ( struct V_432 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
struct V_580 * V_632 ;
struct V_1040 V_1041 ;
unsigned int V_1050 = 0 ;
unsigned int V_1051 = 0 ;
F_725 ( V_44 , & V_1041 ) ;
F_742 (connector, &conn_iter) {
struct V_578 * V_991 ;
struct V_517 * V_518 ;
V_991 = F_743 ( V_24 , V_632 ) ;
if ( ! V_991 )
V_991 = V_632 -> V_24 ;
if ( ! V_991 -> V_582 )
continue;
V_518 = F_433 ( V_991 -> V_582 ) ;
F_20 ( ! V_991 -> V_46 ) ;
switch ( V_518 -> type ) {
unsigned int V_174 ;
case V_1052 :
if ( F_20 ( ! F_14 ( F_34 ( V_44 ) ) ) )
break;
case V_519 :
case V_187 :
case V_520 :
V_174 = 1 << F_388 ( & V_518 -> V_45 ) -> V_156 ;
if ( V_1050 & V_174 )
return false ;
V_1050 |= V_174 ;
break;
case V_594 :
V_1051 |=
1 << F_744 ( & V_518 -> V_45 ) -> V_69 -> V_156 ;
break;
default:
break;
}
}
F_729 ( & V_1041 ) ;
if ( V_1050 & V_1051 )
return false ;
return true ;
}
static void
F_745 ( struct V_18 * V_41 )
{
struct V_1 * V_2 =
F_34 ( V_41 -> V_45 . V_46 -> V_44 ) ;
struct V_382 V_383 ;
struct V_1053 V_152 ;
struct V_882 * V_184 ;
struct V_1054 V_1055 ;
bool V_614 ;
V_383 = V_41 -> V_383 ;
V_184 = V_41 -> V_184 ;
V_152 = V_41 -> V_152 ;
V_614 = V_41 -> V_451 . V_614 ;
if ( F_93 ( V_2 ) ||
F_10 ( V_2 ) || F_11 ( V_2 ) )
V_1055 = V_41 -> V_1036 ;
F_746 ( F_747 ( struct V_18 , V_45 ) ) ;
memset ( & V_41 -> V_45 + 1 , 0 ,
sizeof( * V_41 ) - sizeof( V_41 -> V_45 ) ) ;
V_41 -> V_383 = V_383 ;
V_41 -> V_184 = V_184 ;
V_41 -> V_152 = V_152 ;
V_41 -> V_451 . V_614 = V_614 ;
if ( F_93 ( V_2 ) ||
F_10 ( V_2 ) || F_11 ( V_2 ) )
V_41 -> V_1036 = V_1055 ;
}
static int
F_748 ( struct V_123 * V_46 ,
struct V_18 * V_19 )
{
struct V_432 * V_24 = V_19 -> V_45 . V_24 ;
struct V_517 * V_518 ;
struct V_580 * V_632 ;
struct V_578 * V_991 ;
int V_1056 , V_278 = - V_263 ;
int V_113 ;
bool V_470 = true ;
F_745 ( V_19 ) ;
V_19 -> V_76 =
(enum V_74 ) F_41 ( V_46 ) -> V_75 ;
if ( ! ( V_19 -> V_45 . V_72 . V_324 &
( V_531 | V_1057 ) ) )
V_19 -> V_45 . V_72 . V_324 |= V_1057 ;
if ( ! ( V_19 -> V_45 . V_72 . V_324 &
( V_533 | V_1058 ) ) )
V_19 -> V_45 . V_72 . V_324 |= V_1058 ;
V_1056 = F_731 ( F_41 ( V_46 ) ,
V_19 ) ;
if ( V_1056 < 0 )
goto V_993;
F_695 ( & V_19 -> V_45 . V_431 ,
& V_19 -> V_380 ,
& V_19 -> V_379 ) ;
F_432 (state, connector, connector_state, i) {
if ( V_991 -> V_46 != V_46 )
continue;
V_518 = F_433 ( V_991 -> V_582 ) ;
if ( ! F_719 ( V_24 , F_41 ( V_46 ) , V_518 ) ) {
F_156 ( L_195 ) ;
goto V_993;
}
V_19 -> V_1059 |= 1 << V_518 -> type ;
}
V_1060:
V_19 -> V_20 = 0 ;
V_19 -> V_593 = 1 ;
F_749 ( & V_19 -> V_45 . V_72 ,
V_1061 ) ;
F_432 (state, connector, connector_state, i) {
if ( V_991 -> V_46 != V_46 )
continue;
V_518 = F_433 ( V_991 -> V_582 ) ;
if ( ! ( V_518 -> V_1062 ( V_518 , V_19 , V_991 ) ) ) {
F_156 ( L_196 ) ;
goto V_993;
}
}
if ( ! V_19 -> V_20 )
V_19 -> V_20 = V_19 -> V_45 . V_72 . V_73
* V_19 -> V_593 ;
V_278 = F_523 ( F_41 ( V_46 ) , V_19 ) ;
if ( V_278 < 0 ) {
F_156 ( L_197 ) ;
goto V_993;
}
if ( V_278 == V_646 ) {
if ( F_6 ( ! V_470 , L_198 ) ) {
V_278 = - V_263 ;
goto V_993;
}
F_156 ( L_199 ) ;
V_470 = false ;
goto V_1060;
}
V_19 -> V_776 = ( V_19 -> V_644 == 6 * 3 ) &&
! V_19 -> V_1063 ;
F_156 ( L_200 ,
V_1056 , V_19 -> V_644 , V_19 -> V_776 ) ;
V_993:
return V_278 ;
}
static void
F_750 ( struct V_432 * V_24 )
{
struct V_123 * V_46 ;
struct V_23 * V_1064 ;
int V_113 ;
F_308 (state, crtc, new_crtc_state, i) {
F_41 ( V_46 ) -> V_71 = F_240 ( V_1064 ) ;
if ( F_421 ( V_24 , V_46 -> V_69 ) ) {
struct V_333 * V_327 = V_46 -> V_69 -> V_24 ;
V_46 -> V_69 -> V_70 = V_327 -> V_70 ;
V_46 -> V_243 = V_327 -> V_337 >> 16 ;
V_46 -> V_244 = V_327 -> V_338 >> 16 ;
}
}
}
static bool F_751 ( int V_1065 , int V_1066 )
{
int V_1067 ;
if ( V_1065 == V_1066 )
return true ;
if ( ! V_1065 || ! V_1066 )
return false ;
V_1067 = abs ( V_1065 - V_1066 ) ;
if ( ( ( ( ( V_1067 + V_1065 + V_1066 ) * 100 ) ) / ( V_1065 + V_1066 ) ) < 105 )
return true ;
return false ;
}
static bool
F_752 ( unsigned int V_27 , unsigned int V_32 ,
unsigned int V_28 , unsigned int V_1068 ,
bool V_1069 )
{
if ( V_27 == V_28 && V_32 == V_1068 )
return true ;
if ( V_1069 || ! V_27 || ! V_32 || ! V_28 || ! V_1068 )
return false ;
F_746 ( V_661 > V_65 ) ;
if ( V_32 > V_1068 ) {
while ( V_32 > V_1068 ) {
V_28 <<= 1 ;
V_1068 <<= 1 ;
}
} else if ( V_32 < V_1068 ) {
while ( V_32 < V_1068 ) {
V_27 <<= 1 ;
V_32 <<= 1 ;
}
}
if ( V_32 != V_1068 )
return false ;
return F_751 ( V_27 , V_28 ) ;
}
static bool
F_753 ( const struct V_669 * V_670 ,
struct V_669 * V_687 ,
bool V_1070 )
{
if ( V_670 -> V_671 == V_687 -> V_671 &&
F_752 ( V_670 -> V_672 , V_670 -> V_673 ,
V_687 -> V_672 , V_687 -> V_673 , ! V_1070 ) &&
F_752 ( V_670 -> V_674 , V_670 -> V_675 ,
V_687 -> V_674 , V_687 -> V_675 , ! V_1070 ) ) {
if ( V_1070 )
* V_687 = * V_670 ;
return true ;
}
return false ;
}
static bool
F_754 ( struct V_1 * V_2 ,
struct V_18 * V_1071 ,
struct V_18 * V_19 ,
bool V_1070 )
{
bool V_278 = true ;
#define F_755 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_756 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_757 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_758 ( V_8 ) \
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
#define F_759 ( V_8 , T_5 ) \
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
#define F_760 ( V_8 , V_613 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
pipe_config_err(adjust, __stringify(name), \
"(%x) (expected %i, found %i)\n", \
(mask), \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_761 ( V_8 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
pipe_config_err(adjust, __stringify(name), \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_762 ( T_6 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_756 ( V_76 ) ;
F_756 ( V_199 ) ;
F_756 ( V_465 ) ;
F_758 ( V_590 ) ;
F_756 ( V_1044 ) ;
F_755 ( V_1072 ) ;
if ( F_52 ( V_2 ) < 8 ) {
F_758 ( V_690 ) ;
if ( V_1071 -> V_688 )
F_758 ( V_691 ) ;
} else
F_759 ( V_690 , V_691 ) ;
F_755 ( V_1059 ) ;
F_756 ( V_45 . V_72 . V_551 ) ;
F_756 ( V_45 . V_72 . V_757 ) ;
F_756 ( V_45 . V_72 . V_758 ) ;
F_756 ( V_45 . V_72 . V_759 ) ;
F_756 ( V_45 . V_72 . V_658 ) ;
F_756 ( V_45 . V_72 . V_760 ) ;
F_756 ( V_45 . V_72 . V_552 ) ;
F_756 ( V_45 . V_72 . V_754 ) ;
F_756 ( V_45 . V_72 . V_761 ) ;
F_756 ( V_45 . V_72 . V_755 ) ;
F_756 ( V_45 . V_72 . V_762 ) ;
F_756 ( V_45 . V_72 . V_763 ) ;
F_756 ( V_593 ) ;
F_756 ( V_1073 ) ;
if ( ( F_52 ( V_2 ) < 8 && ! F_259 ( V_2 ) ) ||
F_10 ( V_2 ) || F_11 ( V_2 ) )
F_756 ( V_785 ) ;
F_756 ( V_1074 ) ;
F_756 ( V_1075 ) ;
F_756 ( V_1046 ) ;
F_756 ( V_539 ) ;
F_756 ( V_615 ) ;
F_760 ( V_45 . V_72 . V_324 ,
V_541 ) ;
if ( ! F_762 ( V_1076 ) ) {
F_760 ( V_45 . V_72 . V_324 ,
V_531 ) ;
F_760 ( V_45 . V_72 . V_324 ,
V_1057 ) ;
F_760 ( V_45 . V_72 . V_324 ,
V_533 ) ;
F_760 ( V_45 . V_72 . V_324 ,
V_1058 ) ;
}
F_755 ( V_598 . V_599 ) ;
if ( F_52 ( V_2 ) < 4 )
F_755 ( V_598 . V_603 ) ;
F_755 ( V_598 . V_1047 ) ;
if ( ! V_1070 ) {
F_756 ( V_380 ) ;
F_756 ( V_379 ) ;
F_756 ( V_451 . V_124 ) ;
if ( V_1071 -> V_451 . V_124 ) {
F_755 ( V_451 . V_555 ) ;
F_755 ( V_451 . V_221 ) ;
}
F_756 ( V_383 . V_421 ) ;
F_761 ( V_647 ) ;
}
if ( F_259 ( V_2 ) )
F_756 ( V_558 ) ;
F_756 ( V_203 ) ;
F_757 ( V_184 ) ;
F_755 ( V_152 . V_26 ) ;
F_755 ( V_152 . V_154 ) ;
F_755 ( V_152 . V_624 ) ;
F_755 ( V_152 . V_625 ) ;
F_755 ( V_152 . V_1077 ) ;
F_755 ( V_152 . V_1078 ) ;
F_755 ( V_152 . V_1079 ) ;
F_755 ( V_152 . V_1080 ) ;
F_755 ( V_152 . V_1081 ) ;
F_755 ( V_1082 . V_1083 ) ;
F_755 ( V_1082 . div ) ;
if ( F_93 ( V_2 ) || F_52 ( V_2 ) >= 5 )
F_756 ( V_644 ) ;
F_761 ( V_45 . V_72 . V_73 ) ;
F_761 ( V_20 ) ;
#undef F_755
#undef F_756
#undef F_757
#undef F_760
#undef F_761
#undef F_762
return V_278 ;
}
static void F_763 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
if ( V_19 -> V_199 ) {
int V_642 = F_710 ( F_13 ( V_2 , V_19 ) ,
& V_19 -> V_590 ) ;
int V_1084 = V_19 -> V_45 . V_72 . V_73 ;
F_6 ( ! F_751 ( V_642 , V_1084 ) ,
L_201 ,
V_642 , V_1084 ) ;
}
}
static void F_764 ( struct V_123 * V_46 ,
struct V_23 * V_1085 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
struct V_1086 V_1087 , * V_1088 ;
struct V_1089 V_1090 , * V_1091 ;
struct V_1092 * V_1093 , * V_1094 ;
struct V_1095 * V_1096 , * V_1097 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
const enum V_75 V_75 = V_62 -> V_75 ;
int V_111 , V_1098 , V_1099 = F_765 ( V_2 ) ;
if ( F_52 ( V_2 ) < 9 || ! V_1085 -> V_68 )
return;
F_766 ( V_46 , & V_1090 ) ;
V_1091 = & F_240 ( V_1085 ) -> V_1036 . V_1100 . V_1039 ;
F_767 ( V_2 , & V_1087 ) ;
V_1088 = & V_2 -> V_1036 . V_1101 . V_1102 ;
F_768 (dev_priv, pipe, plane) {
V_1093 = & V_1090 . V_1103 [ V_111 ] ;
V_1094 = & V_1091 -> V_1103 [ V_111 ] ;
for ( V_1098 = 0 ; V_1098 <= V_1099 ; V_1098 ++ ) {
if ( F_769 ( & V_1093 -> V_1036 [ V_1098 ] ,
& V_1094 -> V_1036 [ V_1098 ] ) )
continue;
F_123 ( L_202 ,
F_72 ( V_75 ) , V_111 + 1 , V_1098 ,
V_1094 -> V_1036 [ V_1098 ] . V_1104 ,
V_1094 -> V_1036 [ V_1098 ] . V_1105 ,
V_1094 -> V_1036 [ V_1098 ] . V_1106 ,
V_1093 -> V_1036 [ V_1098 ] . V_1104 ,
V_1093 -> V_1036 [ V_1098 ] . V_1105 ,
V_1093 -> V_1036 [ V_1098 ] . V_1106 ) ;
}
if ( ! F_769 ( & V_1093 -> V_1107 ,
& V_1094 -> V_1107 ) ) {
F_123 ( L_203 ,
F_72 ( V_75 ) , V_111 + 1 ,
V_1094 -> V_1107 . V_1104 ,
V_1094 -> V_1107 . V_1105 ,
V_1094 -> V_1107 . V_1106 ,
V_1093 -> V_1107 . V_1104 ,
V_1093 -> V_1107 . V_1105 ,
V_1093 -> V_1107 . V_1106 ) ;
}
V_1096 = & V_1087 . V_111 [ V_75 ] [ V_111 ] ;
V_1097 = & V_1088 -> V_111 [ V_75 ] [ V_111 ] ;
if ( ! F_770 ( V_1096 , V_1097 ) ) {
F_123 ( L_204 ,
F_72 ( V_75 ) , V_111 + 1 ,
V_1097 -> V_1108 , V_1097 -> V_1109 ,
V_1096 -> V_1108 , V_1096 -> V_1109 ) ;
}
}
if ( 1 ) {
V_1093 = & V_1090 . V_1103 [ V_261 ] ;
V_1094 = & V_1091 -> V_1103 [ V_261 ] ;
for ( V_1098 = 0 ; V_1098 <= V_1099 ; V_1098 ++ ) {
if ( F_769 ( & V_1093 -> V_1036 [ V_1098 ] ,
& V_1094 -> V_1036 [ V_1098 ] ) )
continue;
F_123 ( L_205 ,
F_72 ( V_75 ) , V_1098 ,
V_1094 -> V_1036 [ V_1098 ] . V_1104 ,
V_1094 -> V_1036 [ V_1098 ] . V_1105 ,
V_1094 -> V_1036 [ V_1098 ] . V_1106 ,
V_1093 -> V_1036 [ V_1098 ] . V_1104 ,
V_1093 -> V_1036 [ V_1098 ] . V_1105 ,
V_1093 -> V_1036 [ V_1098 ] . V_1106 ) ;
}
if ( ! F_769 ( & V_1093 -> V_1107 ,
& V_1094 -> V_1107 ) ) {
F_123 ( L_206 ,
F_72 ( V_75 ) ,
V_1094 -> V_1107 . V_1104 ,
V_1094 -> V_1107 . V_1105 ,
V_1094 -> V_1107 . V_1106 ,
V_1093 -> V_1107 . V_1104 ,
V_1093 -> V_1107 . V_1105 ,
V_1093 -> V_1107 . V_1106 ) ;
}
V_1096 = & V_1087 . V_111 [ V_75 ] [ V_261 ] ;
V_1097 = & V_1088 -> V_111 [ V_75 ] [ V_261 ] ;
if ( ! F_770 ( V_1096 , V_1097 ) ) {
F_123 ( L_207 ,
F_72 ( V_75 ) ,
V_1097 -> V_1108 , V_1097 -> V_1109 ,
V_1096 -> V_1108 , V_1096 -> V_1109 ) ;
}
}
}
static void
F_771 ( struct V_43 * V_44 ,
struct V_432 * V_24 ,
struct V_123 * V_46 )
{
struct V_580 * V_632 ;
struct V_578 * V_1110 ;
int V_113 ;
F_432 (state, connector, new_conn_state, i) {
struct V_612 * V_518 = V_632 -> V_518 ;
struct V_23 * V_41 = NULL ;
if ( V_1110 -> V_46 != V_46 )
continue;
if ( V_46 )
V_41 = F_772 ( V_24 , V_1110 -> V_46 ) ;
F_505 ( V_41 , V_1110 ) ;
F_58 ( V_1110 -> V_582 != V_518 ,
L_208 ) ;
}
}
static void
F_773 ( struct V_43 * V_44 , struct V_432 * V_24 )
{
struct V_517 * V_518 ;
struct V_580 * V_632 ;
struct V_578 * V_585 , * V_1110 ;
int V_113 ;
F_594 (dev, encoder) {
bool V_124 = false , V_56 = false ;
enum V_75 V_75 ;
F_156 ( L_209 ,
V_518 -> V_45 . V_45 . V_260 ,
V_518 -> V_45 . V_8 ) ;
F_774 (state, connector, old_conn_state,
new_conn_state, i) {
if ( V_585 -> V_582 == & V_518 -> V_45 )
V_56 = true ;
if ( V_1110 -> V_582 != & V_518 -> V_45 )
continue;
V_56 = V_124 = true ;
F_58 ( V_1110 -> V_46 !=
V_518 -> V_45 . V_46 ,
L_210 ) ;
}
if ( ! V_56 )
continue;
F_58 ( ! ! V_518 -> V_45 . V_46 != V_124 ,
L_211
L_212 ,
! ! V_518 -> V_45 . V_46 , V_124 ) ;
if ( ! V_518 -> V_45 . V_46 ) {
bool V_68 ;
V_68 = V_518 -> V_633 ( V_518 , & V_75 ) ;
F_58 ( V_68 ,
L_213 ,
F_72 ( V_75 ) ) ;
}
}
}
static void
F_775 ( struct V_123 * V_46 ,
struct V_23 * V_450 ,
struct V_23 * V_1064 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_517 * V_518 ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_18 * V_19 , * V_1111 ;
struct V_432 * V_565 ;
bool V_68 ;
V_565 = V_450 -> V_24 ;
F_776 ( V_450 ) ;
V_19 = F_240 ( V_450 ) ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_45 . V_46 = V_46 ;
V_19 -> V_45 . V_24 = V_565 ;
F_156 ( L_214 , V_46 -> V_45 . V_260 , V_46 -> V_8 ) ;
V_68 = V_2 -> V_448 . V_1112 ( V_62 , V_19 ) ;
if ( F_78 ( V_2 ) )
V_68 = V_1064 -> V_68 ;
F_58 ( V_1064 -> V_68 != V_68 ,
L_215
L_212 , V_1064 -> V_68 , V_68 ) ;
F_58 ( V_62 -> V_68 != V_1064 -> V_68 ,
L_216
L_212 , V_1064 -> V_68 , V_62 -> V_68 ) ;
F_387 (dev, crtc, encoder) {
enum V_75 V_75 ;
V_68 = V_518 -> V_633 ( V_518 , & V_75 ) ;
F_58 ( V_68 != V_1064 -> V_68 ,
L_217 ,
V_518 -> V_45 . V_45 . V_260 , V_68 , V_1064 -> V_68 ) ;
F_58 ( V_68 && V_62 -> V_75 != V_75 ,
L_218 ,
F_72 ( V_75 ) ) ;
if ( V_68 ) {
V_19 -> V_1059 |= 1 << V_518 -> type ;
V_518 -> V_1113 ( V_518 , V_19 ) ;
}
}
F_522 ( V_19 ) ;
if ( ! V_1064 -> V_68 )
return;
F_763 ( V_2 , V_19 ) ;
V_1111 = F_240 ( V_1064 ) ;
if ( ! F_754 ( V_2 , V_1111 ,
V_19 , false ) ) {
F_58 ( 1 , L_219 ) ;
F_734 ( V_62 , V_19 ,
L_220 ) ;
F_734 ( V_62 , V_1111 ,
L_221 ) ;
}
}
static void
F_777 ( struct V_1 * V_2 ,
struct V_882 * V_883 ,
struct V_123 * V_46 ,
struct V_23 * V_1085 )
{
struct V_1053 V_152 ;
unsigned V_1114 ;
bool V_68 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
F_156 ( L_222 , V_883 -> V_8 ) ;
V_68 = V_883 -> V_888 . V_633 ( V_2 , V_883 , & V_152 ) ;
if ( ! ( V_883 -> V_324 & V_1115 ) ) {
F_58 ( ! V_883 -> V_1116 && V_883 -> V_1117 ,
L_223 ) ;
F_58 ( V_883 -> V_1116 && ! V_883 -> V_1117 ,
L_224 ) ;
F_58 ( V_883 -> V_1116 != V_68 ,
L_225 ,
V_883 -> V_1116 , V_68 ) ;
}
if ( ! V_46 ) {
F_58 ( V_883 -> V_1117 & ~ V_883 -> V_24 . V_1114 ,
L_226 ,
V_883 -> V_1117 , V_883 -> V_24 . V_1114 ) ;
return;
}
V_1114 = 1 << F_778 ( V_46 ) ;
if ( V_1085 -> V_68 )
F_58 ( ! ( V_883 -> V_1117 & V_1114 ) ,
L_227 ,
F_72 ( F_778 ( V_46 ) ) , V_883 -> V_1117 ) ;
else
F_58 ( V_883 -> V_1117 & V_1114 ,
L_228 ,
F_72 ( F_778 ( V_46 ) ) , V_883 -> V_1117 ) ;
F_58 ( ! ( V_883 -> V_24 . V_1114 & V_1114 ) ,
L_229 ,
V_1114 , V_883 -> V_24 . V_1114 ) ;
F_58 ( V_883 -> V_1116 && memcmp ( & V_883 -> V_24 . V_1118 ,
& V_152 ,
sizeof( V_152 ) ) ,
L_230 ) ;
}
static void
F_779 ( struct V_43 * V_44 , struct V_123 * V_46 ,
struct V_23 * V_450 ,
struct V_23 * V_1064 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_18 * V_565 = F_240 ( V_450 ) ;
struct V_18 * V_1085 = F_240 ( V_1064 ) ;
if ( V_1085 -> V_184 )
F_777 ( V_2 , V_1085 -> V_184 , V_46 , V_1064 ) ;
if ( V_565 -> V_184 &&
V_565 -> V_184 != V_1085 -> V_184 ) {
unsigned V_1114 = 1 << F_778 ( V_46 ) ;
struct V_882 * V_883 = V_565 -> V_184 ;
F_58 ( V_883 -> V_1117 & V_1114 ,
L_231 ,
F_72 ( F_778 ( V_46 ) ) ) ;
F_58 ( V_883 -> V_24 . V_1114 & V_1114 ,
L_232 ,
F_72 ( F_778 ( V_46 ) ) ) ;
}
}
static void
F_780 ( struct V_123 * V_46 ,
struct V_432 * V_24 ,
struct V_23 * V_565 ,
struct V_23 * V_1085 )
{
if ( ! F_17 ( V_1085 ) &&
! F_240 ( V_1085 ) -> V_1119 )
return;
F_764 ( V_46 , V_1085 ) ;
F_771 ( V_46 -> V_44 , V_24 , V_46 ) ;
F_775 ( V_46 , V_565 , V_1085 ) ;
F_779 ( V_46 -> V_44 , V_46 , V_565 , V_1085 ) ;
}
static void
F_781 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_823 ; V_113 ++ )
F_777 ( V_2 , & V_2 -> V_1120 [ V_113 ] , NULL , NULL ) ;
}
static void
F_782 ( struct V_43 * V_44 ,
struct V_432 * V_24 )
{
F_773 ( V_44 , V_24 ) ;
F_771 ( V_44 , V_24 , NULL ) ;
F_781 ( V_44 ) ;
}
static void F_783 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
if ( F_49 ( V_2 ) ) {
const struct V_526 * V_72 = & V_46 -> V_71 -> V_45 . V_72 ;
int V_769 ;
V_769 = V_72 -> V_754 ;
if ( V_72 -> V_324 & V_541 )
V_769 /= 2 ;
V_46 -> V_202 = V_769 - 1 ;
} else if ( F_14 ( V_2 ) &&
F_31 ( V_46 -> V_71 , V_187 ) ) {
V_46 -> V_202 = 2 ;
} else
V_46 -> V_202 = 1 ;
}
static void F_784 ( struct V_432 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_123 * V_46 ;
struct V_23 * V_450 , * V_1064 ;
int V_113 ;
if ( ! V_2 -> V_448 . V_1031 )
return;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_882 * V_1121 =
F_240 ( V_450 ) -> V_184 ;
if ( ! F_17 ( V_1064 ) )
continue;
F_240 ( V_1064 ) -> V_184 = NULL ;
if ( ! V_1121 )
continue;
F_786 ( V_1121 , V_62 , V_24 ) ;
}
}
static int F_787 ( struct V_432 * V_24 )
{
struct V_23 * V_41 ;
struct V_62 * V_62 ;
struct V_123 * V_46 ;
struct V_18 * V_1122 = NULL ;
struct V_18 * V_638 = NULL ;
enum V_75 V_1123 = V_595 , V_1124 = V_595 ;
int V_113 ;
F_308 (state, crtc, crtc_state, i) {
V_62 = F_41 ( V_46 ) ;
if ( ! V_41 -> V_68 || ! F_17 ( V_41 ) )
continue;
if ( V_1122 ) {
V_638 = F_240 ( V_41 ) ;
break;
} else {
V_1122 = F_240 ( V_41 ) ;
V_1123 = V_62 -> V_75 ;
}
}
if ( ! V_1122 )
return 0 ;
F_134 (state->dev, intel_crtc) {
struct V_18 * V_19 ;
V_19 = F_495 ( V_24 , V_62 ) ;
if ( F_191 ( V_19 ) )
return F_243 ( V_19 ) ;
V_19 -> V_591 = V_595 ;
if ( ! V_19 -> V_45 . V_68 ||
F_17 ( & V_19 -> V_45 ) )
continue;
if ( V_1124 != V_595 )
return 0 ;
V_1124 = V_62 -> V_75 ;
}
if ( V_1124 != V_595 )
V_1122 -> V_591 = V_1124 ;
else if ( V_638 )
V_638 -> V_591 = V_1123 ;
return 0 ;
}
static int F_788 ( struct V_432 * V_24 )
{
struct V_123 * V_46 ;
F_237 (state->dev, crtc) {
struct V_23 * V_41 ;
V_41 = F_705 ( V_24 , V_46 ) ;
if ( F_191 ( V_41 ) )
return F_243 ( V_41 ) ;
}
return 0 ;
}
static int F_789 ( struct V_432 * V_24 )
{
struct V_123 * V_46 ;
F_237 (state->dev, crtc) {
struct V_23 * V_41 ;
int V_278 ;
V_41 = F_705 ( V_24 , V_46 ) ;
if ( F_191 ( V_41 ) )
return F_243 ( V_41 ) ;
if ( ! V_41 -> V_68 || F_17 ( V_41 ) )
continue;
V_41 -> V_435 = true ;
V_278 = F_496 ( V_24 , V_46 ) ;
if ( V_278 )
return V_278 ;
V_278 = F_790 ( V_24 , V_46 ) ;
if ( V_278 )
return V_278 ;
}
return 0 ;
}
static int F_791 ( struct V_432 * V_24 )
{
struct V_572 * V_334 = F_309 ( V_24 ) ;
struct V_1 * V_2 = F_34 ( V_24 -> V_44 ) ;
struct V_123 * V_46 ;
struct V_23 * V_450 , * V_1064 ;
int V_278 = 0 , V_113 ;
if ( ! F_741 ( V_24 ) ) {
F_156 ( L_233 ) ;
return - V_263 ;
}
V_334 -> V_571 = true ;
V_334 -> V_629 = V_2 -> V_629 ;
V_334 -> V_1125 . V_1126 = V_2 -> V_1125 . V_1126 ;
V_334 -> V_1125 . V_1127 = V_2 -> V_1125 . V_1127 ;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( V_1064 -> V_68 )
V_334 -> V_629 |= 1 << V_113 ;
else
V_334 -> V_629 &= ~ ( 1 << V_113 ) ;
if ( V_450 -> V_68 != V_1064 -> V_68 )
V_334 -> V_1128 |= F_792 ( V_46 ) ;
}
if ( V_2 -> V_448 . V_1129 ) {
V_278 = V_2 -> V_448 . V_1129 ( V_24 ) ;
if ( V_278 < 0 )
return V_278 ;
if ( ! F_793 ( & V_2 -> V_1125 . V_1126 ,
& V_334 -> V_1125 . V_1126 ) ) {
V_278 = F_788 ( V_24 ) ;
if ( V_278 < 0 )
return V_278 ;
}
if ( ! F_793 ( & V_2 -> V_1125 . V_1127 ,
& V_334 -> V_1125 . V_1127 ) ) {
V_278 = F_789 ( V_24 ) ;
if ( V_278 < 0 )
return V_278 ;
}
F_156 ( L_234 ,
V_334 -> V_1125 . V_1126 . V_1125 ,
V_334 -> V_1125 . V_1127 . V_1125 ) ;
} else {
F_309 ( V_24 ) -> V_1125 . V_1126 = V_2 -> V_1125 . V_1126 ;
}
F_784 ( V_24 ) ;
if ( F_259 ( V_2 ) )
return F_787 ( V_24 ) ;
return 0 ;
}
static int F_794 ( struct V_432 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
if ( V_2 -> V_448 . V_1130 )
return V_2 -> V_448 . V_1130 ( V_24 ) ;
return 0 ;
}
static int F_795 ( struct V_43 * V_44 ,
struct V_432 * V_24 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_572 * V_334 = F_309 ( V_24 ) ;
struct V_123 * V_46 ;
struct V_23 * V_450 , * V_41 ;
int V_278 , V_113 ;
bool V_1131 = false ;
V_278 = F_796 ( V_44 , V_24 ) ;
if ( V_278 )
return V_278 ;
F_785 (state, crtc, old_crtc_state, crtc_state, i) {
struct V_18 * V_19 =
F_240 ( V_41 ) ;
if ( V_41 -> V_431 . V_1132 != V_450 -> V_431 . V_1132 )
V_41 -> V_435 = true ;
if ( ! F_17 ( V_41 ) )
continue;
if ( ! V_41 -> V_514 ) {
V_1131 = true ;
continue;
}
V_278 = F_496 ( V_24 , V_46 ) ;
if ( V_278 )
return V_278 ;
V_278 = F_748 ( V_46 , V_19 ) ;
if ( V_278 ) {
F_734 ( F_41 ( V_46 ) ,
V_19 , L_235 ) ;
return V_278 ;
}
if ( V_239 . V_1133 &&
F_754 ( V_2 ,
F_240 ( V_450 ) ,
V_19 , true ) ) {
V_41 -> V_435 = false ;
V_19 -> V_1119 = true ;
}
if ( F_17 ( V_41 ) )
V_1131 = true ;
V_278 = F_790 ( V_24 , V_46 ) ;
if ( V_278 )
return V_278 ;
F_734 ( F_41 ( V_46 ) , V_19 ,
F_17 ( V_41 ) ?
L_236 : L_237 ) ;
}
if ( V_1131 ) {
V_278 = F_791 ( V_24 ) ;
if ( V_278 )
return V_278 ;
} else {
V_334 -> V_1125 . V_1126 = V_2 -> V_1125 . V_1126 ;
}
V_278 = F_797 ( V_44 , V_24 ) ;
if ( V_278 )
return V_278 ;
F_798 ( V_2 , V_24 ) ;
return F_794 ( V_24 ) ;
}
static int F_799 ( struct V_43 * V_44 ,
struct V_432 * V_24 )
{
return F_800 ( V_44 , V_24 ) ;
}
T_1 F_801 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
if ( ! V_44 -> V_201 )
return F_802 ( & V_46 -> V_45 ) ;
return V_44 -> V_1134 -> V_1135 ( V_44 , V_46 -> V_75 ) ;
}
static void F_803 ( struct V_43 * V_44 ,
struct V_1 * V_2 ,
unsigned V_1114 )
{
unsigned V_1136 [ V_1137 ] ;
enum V_75 V_75 ;
int V_278 ;
if ( ! V_1114 )
return;
F_86 (dev_priv, pipe) {
struct V_62 * V_46 = F_46 ( V_2 ,
V_75 ) ;
if ( ! ( ( 1 << V_75 ) & V_1114 ) )
continue;
V_278 = F_97 ( & V_46 -> V_45 ) ;
if ( F_20 ( V_278 != 0 ) ) {
V_1114 &= ~ ( 1 << V_75 ) ;
continue;
}
V_1136 [ V_75 ] = F_804 ( & V_46 -> V_45 ) ;
}
F_86 (dev_priv, pipe) {
struct V_62 * V_46 = F_46 ( V_2 ,
V_75 ) ;
long V_1138 ;
if ( ! ( ( 1 << V_75 ) & V_1114 ) )
continue;
V_1138 = F_805 ( V_44 -> V_1139 [ V_75 ] . V_1140 ,
V_1136 [ V_75 ] !=
F_804 ( & V_46 -> V_45 ) ,
F_806 ( 50 ) ) ;
F_6 ( ! V_1138 , L_238 , F_72 ( V_75 ) ) ;
F_98 ( & V_46 -> V_45 ) ;
}
}
static bool F_807 ( struct V_18 * V_41 )
{
if ( V_41 -> V_1026 )
return true ;
if ( V_41 -> V_568 )
return true ;
if ( V_41 -> V_1036 . V_1141 )
return true ;
return false ;
}
static void F_808 ( struct V_123 * V_46 ,
struct V_432 * V_24 ,
struct V_23 * V_450 ,
struct V_23 * V_1064 ,
unsigned int * V_1142 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_18 * V_19 = F_240 ( V_1064 ) ;
bool V_571 = F_17 ( V_1064 ) ;
if ( V_571 ) {
F_783 ( V_62 ) ;
V_2 -> V_448 . V_1143 ( V_19 , V_24 ) ;
} else {
F_425 ( F_240 ( V_450 ) ,
V_19 ) ;
}
if ( F_421 ( V_24 , V_46 -> V_69 ) ) {
F_809 (
V_62 , V_19 ,
F_235 ( V_46 -> V_69 -> V_24 ) ) ;
}
F_810 ( V_450 ) ;
if ( F_807 ( V_19 ) )
* V_1142 |= F_792 ( V_46 ) ;
}
static void F_811 ( struct V_432 * V_24 ,
unsigned int * V_1142 )
{
struct V_123 * V_46 ;
struct V_23 * V_450 , * V_1064 ;
int V_113 ;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( ! V_1064 -> V_68 )
continue;
F_808 ( V_46 , V_24 , V_450 ,
V_1064 , V_1142 ) ;
}
}
static void F_812 ( struct V_432 * V_24 ,
unsigned int * V_1142 )
{
struct V_1 * V_2 = F_34 ( V_24 -> V_44 ) ;
struct V_572 * V_334 = F_309 ( V_24 ) ;
struct V_123 * V_46 ;
struct V_62 * V_62 ;
struct V_23 * V_450 , * V_1064 ;
struct V_18 * V_1144 ;
unsigned int V_1145 = 0 ;
bool V_1146 ;
enum V_75 V_75 ;
int V_113 ;
const struct V_1095 * V_1147 [ V_1137 ] = {} ;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i)
if ( V_1064 -> V_68 )
V_1147 [ V_113 ] = & F_240 ( V_450 ) -> V_1036 . V_1100 . V_1102 ;
do {
V_1146 = false ;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
bool V_1148 = false ;
unsigned int V_1149 = F_792 ( V_46 ) ;
V_62 = F_41 ( V_46 ) ;
V_1144 = F_240 ( V_46 -> V_24 ) ;
V_75 = V_62 -> V_75 ;
if ( V_1145 & V_1149 || ! V_1144 -> V_45 . V_68 )
continue;
if ( F_813 ( V_1147 , & V_1144 -> V_1036 . V_1100 . V_1102 , V_113 ) )
continue;
V_1145 |= V_1149 ;
V_1147 [ V_113 ] = & V_1144 -> V_1036 . V_1100 . V_1102 ;
if ( ! F_770 ( & V_1144 -> V_1036 . V_1100 . V_1102 ,
& F_240 ( V_450 ) -> V_1036 . V_1100 . V_1102 ) &&
! V_1064 -> V_1150 &&
V_334 -> V_1151 . V_1152 != V_1145 )
V_1148 = true ;
F_808 ( V_46 , V_24 , V_450 ,
V_1064 , V_1142 ) ;
if ( V_1148 )
F_411 ( V_2 , V_75 ) ;
V_1146 = true ;
}
} while ( V_1146 );
}
static void F_814 ( struct V_1 * V_2 )
{
struct V_572 * V_24 , * V_1153 ;
struct V_1154 * V_1155 ;
V_1155 = F_815 ( & V_2 -> V_1156 . V_1157 ) ;
F_816 (state, next, freed, freed)
F_323 ( & V_24 -> V_45 ) ;
}
static void F_817 ( struct V_1158 * V_1159 )
{
struct V_1 * V_2 =
F_818 ( V_1159 , F_819 ( * V_2 ) , V_1156 . V_1160 ) ;
F_814 ( V_2 ) ;
}
static void F_820 ( struct V_572 * V_334 )
{
struct V_1161 V_1162 , V_1163 ;
struct V_1 * V_2 = F_34 ( V_334 -> V_45 . V_44 ) ;
F_821 ( & V_1162 , 0 ) ;
F_821 ( & V_1163 , 0 ) ;
for (; ; ) {
F_822 ( & V_334 -> V_1164 . V_1165 ,
& V_1162 , V_1166 ) ;
F_822 ( & V_2 -> V_236 . V_441 ,
& V_1163 , V_1166 ) ;
if ( F_823 ( & V_334 -> V_1164 )
|| F_824 ( V_440 , & V_2 -> V_236 . V_324 ) )
break;
F_825 () ;
}
F_826 ( & V_334 -> V_1164 . V_1165 , & V_1162 ) ;
F_826 ( & V_2 -> V_236 . V_441 , & V_1163 ) ;
}
static void F_827 ( struct V_432 * V_24 )
{
struct V_43 * V_44 = V_24 -> V_44 ;
struct V_572 * V_334 = F_309 ( V_24 ) ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_23 * V_450 , * V_1064 ;
struct V_123 * V_46 ;
struct V_18 * V_1167 ;
T_4 V_1168 [ V_1137 ] = {} ;
unsigned V_1142 = 0 ;
int V_113 ;
F_820 ( V_334 ) ;
F_828 ( V_24 ) ;
if ( V_334 -> V_571 )
F_478 ( V_2 , V_1169 ) ;
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
struct V_62 * V_62 = F_41 ( V_46 ) ;
if ( F_17 ( V_1064 ) ||
F_240 ( V_1064 ) -> V_1119 ) {
V_1168 [ F_41 ( V_46 ) -> V_75 ] =
F_476 ( V_46 ,
F_240 ( V_1064 ) ) ;
}
if ( ! F_17 ( V_1064 ) )
continue;
F_425 ( F_240 ( V_450 ) ,
F_240 ( V_1064 ) ) ;
if ( V_450 -> V_68 ) {
F_428 ( V_46 , V_450 -> V_329 ) ;
V_2 -> V_448 . V_626 ( F_240 ( V_450 ) , V_24 ) ;
V_62 -> V_68 = false ;
F_498 ( V_62 ) ;
F_499 ( V_62 ) ;
F_416 ( V_2 ) ;
F_417 ( V_2 ) ;
if ( ! V_46 -> V_24 -> V_68 ) {
if ( F_52 ( V_2 ) >= 9 )
V_2 -> V_448 . V_576 ( V_334 ,
F_240 ( V_46 -> V_24 ) ) ;
}
}
}
F_750 ( V_24 ) ;
if ( V_334 -> V_571 ) {
F_829 ( V_24 -> V_44 , V_24 ) ;
F_830 ( V_2 , & V_2 -> V_1125 . V_1127 ) ;
if ( ! F_831 ( V_24 ) )
F_832 ( V_2 ) ;
F_782 ( V_44 , V_24 ) ;
}
F_308 (state, crtc, new_crtc_state, i) {
bool V_571 = F_17 ( V_1064 ) ;
if ( V_571 && ! V_1064 -> V_68 && V_1064 -> V_1170 ) {
F_329 ( & V_44 -> V_1171 ) ;
F_833 ( V_46 , V_1064 -> V_1170 ) ;
F_330 ( & V_44 -> V_1171 ) ;
V_1064 -> V_1170 = NULL ;
}
}
V_2 -> V_448 . V_1172 ( V_24 , & V_1142 ) ;
if ( ! V_24 -> V_1173 )
F_803 ( V_44 , V_2 , V_1142 ) ;
F_308 (state, crtc, new_crtc_state, i) {
V_1167 = F_240 ( V_1064 ) ;
if ( V_2 -> V_448 . V_1174 )
V_2 -> V_448 . V_1174 ( V_334 ,
V_1167 ) ;
}
F_785 (state, crtc, old_crtc_state, new_crtc_state, i) {
F_420 ( F_240 ( V_450 ) ) ;
if ( V_1168 [ V_113 ] )
F_479 ( V_2 , V_1168 [ V_113 ] ) ;
F_780 ( V_46 , V_24 , V_450 , V_1064 ) ;
}
if ( V_334 -> V_571 && F_831 ( V_24 ) )
F_834 ( V_2 ) ;
F_835 ( V_24 ) ;
if ( V_334 -> V_571 ) {
F_836 ( V_2 ) ;
F_81 ( V_2 , V_1169 ) ;
}
F_837 ( V_44 , V_24 ) ;
F_838 ( V_24 ) ;
F_323 ( V_24 ) ;
F_814 ( V_2 ) ;
}
static void F_839 ( struct V_1158 * V_1159 )
{
struct V_432 * V_24 =
F_818 ( V_1159 , struct V_432 , V_1175 ) ;
F_827 ( V_24 ) ;
}
static int T_7
F_840 ( struct V_1176 * V_1177 ,
enum V_1178 V_1179 )
{
struct V_572 * V_24 =
F_818 ( V_1177 , struct V_572 , V_1164 ) ;
switch ( V_1179 ) {
case V_1180 :
break;
case V_1181 :
{
struct V_1182 * V_1183 =
& F_34 ( V_24 -> V_45 . V_44 ) -> V_1156 ;
if ( F_841 ( & V_24 -> V_1155 , & V_1183 -> V_1157 ) )
F_842 ( & V_1183 -> V_1160 ) ;
break;
}
}
return V_1184 ;
}
static void F_843 ( struct V_432 * V_24 )
{
struct V_333 * V_1020 , * V_1185 ;
struct V_332 * V_111 ;
int V_113 ;
F_844 (state, plane, old_plane_state, new_plane_state, i)
F_845 ( F_185 ( V_1020 -> V_70 ) ,
F_185 ( V_1185 -> V_70 ) ,
F_212 ( V_111 ) -> V_348 ) ;
}
static int F_846 ( struct V_43 * V_44 ,
struct V_432 * V_24 ,
bool V_1186 )
{
struct V_572 * V_334 = F_309 ( V_24 ) ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
int V_278 = 0 ;
V_278 = F_847 ( V_24 , V_1186 ) ;
if ( V_278 )
return V_278 ;
F_848 ( V_24 ) ;
F_849 ( & V_334 -> V_1164 ,
F_840 ) ;
V_278 = F_799 ( V_44 , V_24 ) ;
if ( V_278 ) {
F_717 ( L_239 , V_278 ) ;
F_850 ( & V_334 -> V_1164 ) ;
return V_278 ;
}
if ( F_52 ( V_2 ) < 9 )
V_24 -> V_1173 = false ;
V_278 = F_851 ( V_24 , true ) ;
if ( V_278 ) {
F_850 ( & V_334 -> V_1164 ) ;
F_837 ( V_44 , V_24 ) ;
return V_278 ;
}
V_2 -> V_1036 . V_1187 = false ;
F_852 ( V_24 ) ;
F_843 ( V_24 ) ;
if ( V_334 -> V_571 ) {
memcpy ( V_2 -> V_630 , V_334 -> V_630 ,
sizeof( V_334 -> V_630 ) ) ;
V_2 -> V_629 = V_334 -> V_629 ;
V_2 -> V_1125 . V_1126 = V_334 -> V_1125 . V_1126 ;
V_2 -> V_1125 . V_1127 = V_334 -> V_1125 . V_1127 ;
}
F_848 ( V_24 ) ;
F_853 ( & V_24 -> V_1175 , F_839 ) ;
F_850 ( & V_334 -> V_1164 ) ;
if ( V_1186 )
F_854 ( V_1188 , & V_24 -> V_1175 ) ;
else
F_827 ( V_24 ) ;
return 0 ;
}
int
F_855 ( struct V_332 * V_111 ,
struct V_333 * V_1085 )
{
struct V_572 * V_334 =
F_309 ( V_1085 -> V_24 ) ;
struct V_1 * V_2 = F_34 ( V_111 -> V_44 ) ;
struct V_205 * V_70 = V_1085 -> V_70 ;
struct V_231 * V_232 = F_185 ( V_70 ) ;
struct V_231 * V_1189 = F_185 ( V_111 -> V_24 -> V_70 ) ;
int V_278 ;
if ( V_1189 ) {
struct V_23 * V_41 =
F_856 ( V_1085 -> V_24 ,
V_111 -> V_24 -> V_46 ) ;
if ( F_17 ( V_41 ) ) {
V_278 = F_857 ( & V_334 -> V_1164 ,
V_1189 -> V_1190 , NULL ,
false , 0 ,
V_635 ) ;
if ( V_278 < 0 )
return V_278 ;
}
}
if ( V_1085 -> V_1177 ) {
V_278 = F_858 ( & V_334 -> V_1164 ,
V_1085 -> V_1177 ,
V_1191 ,
V_635 ) ;
if ( V_278 < 0 )
return V_278 ;
}
if ( ! V_232 )
return 0 ;
V_278 = F_859 ( V_232 ) ;
if ( V_278 )
return V_278 ;
V_278 = F_860 ( & V_2 -> V_240 . V_235 ) ;
if ( V_278 ) {
F_861 ( V_232 ) ;
return V_278 ;
}
if ( V_111 -> type == V_1192 &&
F_180 ( V_2 ) -> V_961 ) {
const int V_1193 = F_177 ( V_2 ) ;
V_278 = F_862 ( V_232 , V_1193 ) ;
} else {
struct V_230 * V_233 ;
V_233 = F_184 ( V_70 , V_1085 -> V_225 ) ;
if ( ! F_191 ( V_233 ) )
F_235 ( V_1085 ) -> V_233 = V_233 ;
else
V_278 = F_243 ( V_233 ) ;
}
F_863 ( V_232 , 0 , V_1194 ) ;
F_4 ( & V_2 -> V_240 . V_235 ) ;
F_861 ( V_232 ) ;
if ( V_278 )
return V_278 ;
if ( ! V_1085 -> V_1177 ) {
V_278 = F_857 ( & V_334 -> V_1164 ,
V_232 -> V_1190 , NULL ,
false , V_1191 ,
V_635 ) ;
if ( V_278 < 0 )
return V_278 ;
}
return 0 ;
}
void
F_864 ( struct V_332 * V_111 ,
struct V_333 * V_565 )
{
struct V_230 * V_233 ;
V_233 = F_865 ( & F_235 ( V_565 ) -> V_233 ) ;
if ( V_233 ) {
F_2 ( & V_111 -> V_44 -> V_235 ) ;
F_198 ( V_233 ) ;
F_4 ( & V_111 -> V_44 -> V_235 ) ;
}
}
int
F_866 ( struct V_62 * V_62 , struct V_18 * V_41 )
{
struct V_1 * V_2 ;
int V_1195 ;
int V_73 , V_1196 ;
if ( ! V_62 || ! V_41 -> V_45 . V_514 )
return V_971 ;
V_2 = F_34 ( V_62 -> V_45 . V_44 ) ;
V_73 = V_41 -> V_45 . V_72 . V_73 ;
V_1196 = F_309 ( V_41 -> V_45 . V_24 ) -> V_1125 . V_1126 . V_1125 ;
if ( F_291 ( V_2 ) )
V_1196 *= 2 ;
if ( F_38 ( ! V_73 || V_1196 < V_73 ) )
return V_971 ;
V_1195 = V_39 ( ( 1 << 16 ) * 3 - 1 ,
( 1 << 8 ) * ( ( V_1196 << 8 ) / V_73 ) ) ;
return V_1195 ;
}
static int
F_867 ( struct V_259 * V_111 ,
struct V_18 * V_41 ,
struct V_245 * V_24 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
struct V_123 * V_46 = V_24 -> V_45 . V_46 ;
int V_1197 = V_971 ;
int V_1195 = V_971 ;
bool V_1198 = false ;
int V_278 ;
if ( F_52 ( V_2 ) >= 9 ) {
if ( V_24 -> V_409 . V_324 == V_553 ) {
V_1197 = 1 ;
V_1195 = F_866 ( F_41 ( V_46 ) , V_41 ) ;
}
V_1198 = true ;
}
V_278 = F_663 ( & V_24 -> V_45 ,
& V_24 -> V_970 ,
V_1197 , V_1195 ,
V_1198 , true ) ;
if ( V_278 )
return V_278 ;
if ( ! V_24 -> V_45 . V_70 )
return 0 ;
if ( F_52 ( V_2 ) >= 9 ) {
V_278 = F_255 ( V_24 ) ;
if ( V_278 )
return V_278 ;
V_24 -> V_372 = F_290 ( V_41 , V_24 ) ;
} else {
V_278 = F_262 ( V_24 ) ;
if ( V_278 )
return V_278 ;
V_24 -> V_372 = F_256 ( V_41 , V_24 ) ;
}
return 0 ;
}
static void F_868 ( struct V_123 * V_46 ,
struct V_23 * V_450 )
{
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_62 * V_62 = F_41 ( V_46 ) ;
struct V_18 * V_1167 =
F_240 ( V_46 -> V_24 ) ;
struct V_18 * V_1199 =
F_240 ( V_450 ) ;
struct V_572 * V_573 =
F_309 ( V_450 -> V_24 ) ;
bool V_571 = F_17 ( V_46 -> V_24 ) ;
if ( ! V_571 &&
( V_1167 -> V_45 . V_1032 ||
V_1167 -> V_1119 ) ) {
F_458 ( V_46 -> V_24 ) ;
F_449 ( V_46 -> V_24 ) ;
}
F_869 ( V_62 ) ;
if ( V_571 )
goto V_812;
if ( V_1167 -> V_1119 )
F_335 ( V_62 , V_1199 ) ;
else if ( F_52 ( V_2 ) >= 9 )
F_285 ( V_62 ) ;
V_812:
if ( V_2 -> V_448 . V_1200 )
V_2 -> V_448 . V_1200 ( V_573 ,
V_1167 ) ;
}
static void F_870 ( struct V_123 * V_46 ,
struct V_23 * V_450 )
{
struct V_62 * V_62 = F_41 ( V_46 ) ;
F_871 ( V_62 ) ;
}
void F_872 ( struct V_332 * V_111 )
{
F_873 ( V_111 ) ;
F_236 ( F_212 ( V_111 ) ) ;
}
static bool F_874 ( T_2 V_207 , V_36 V_208 )
{
switch ( V_207 ) {
case V_293 :
case V_297 :
case V_295 :
case V_299 :
return V_208 == V_209 ||
V_208 == V_210 ;
default:
return false ;
}
}
static bool F_875 ( T_2 V_207 , V_36 V_208 )
{
switch ( V_207 ) {
case V_293 :
case V_297 :
case V_299 :
case V_301 :
case V_303 :
case V_305 :
return V_208 == V_209 ||
V_208 == V_210 ;
default:
return false ;
}
}
static bool F_876 ( T_2 V_207 , V_36 V_208 )
{
switch ( V_207 ) {
case V_299 :
case V_301 :
case V_311 :
case V_310 :
if ( V_208 == V_213 ||
V_208 == V_211 )
return true ;
case V_297 :
case V_303 :
case V_305 :
case V_390 :
case V_393 :
case V_395 :
case V_397 :
if ( V_208 == V_214 )
return true ;
case V_293 :
if ( V_208 == V_209 ||
V_208 == V_210 ||
V_208 == V_212 )
return true ;
default:
return false ;
}
}
static bool F_877 ( struct V_332 * V_111 ,
T_2 V_207 ,
V_36 V_208 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_44 ) ;
if ( F_20 ( V_208 == V_1201 ) )
return false ;
if ( ( V_208 >> 56 ) != V_1202 &&
V_208 != V_209 )
return false ;
if ( F_52 ( V_2 ) >= 9 )
return F_876 ( V_207 , V_208 ) ;
else if ( F_52 ( V_2 ) >= 4 )
return F_875 ( V_207 , V_208 ) ;
else
return F_874 ( V_207 , V_208 ) ;
F_878 () ;
}
static bool F_879 ( struct V_332 * V_111 ,
T_2 V_207 ,
V_36 V_208 )
{
if ( F_20 ( V_208 == V_1201 ) )
return false ;
return V_208 == V_209 && V_207 == V_311 ;
}
static int
F_880 ( struct V_332 * V_111 ,
struct V_123 * V_46 ,
struct V_205 * V_70 ,
int V_341 , int V_342 ,
unsigned int V_343 , unsigned int V_344 ,
T_2 V_337 , T_2 V_338 ,
T_2 V_339 , T_2 V_340 ,
struct V_433 * V_434 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_44 ) ;
int V_278 ;
struct V_333 * V_1020 , * V_1185 ;
struct V_259 * V_259 = F_212 ( V_111 ) ;
struct V_205 * V_1203 ;
struct V_23 * V_41 = V_46 -> V_24 ;
struct V_230 * V_1204 , * V_233 ;
if ( ! V_41 -> V_68 || F_17 ( V_41 ) ||
F_240 ( V_41 ) -> V_1119 )
goto V_1205;
V_1020 = V_111 -> V_24 ;
if ( V_1020 -> V_46 != V_46 ||
V_1020 -> V_339 != V_339 ||
V_1020 -> V_340 != V_340 ||
V_1020 -> V_343 != V_343 ||
V_1020 -> V_344 != V_344 ||
! V_1020 -> V_70 != ! V_70 )
goto V_1205;
V_1185 = F_881 ( V_111 ) ;
if ( ! V_1185 )
return - V_636 ;
F_697 ( V_1185 , V_70 ) ;
V_1185 -> V_337 = V_337 ;
V_1185 -> V_338 = V_338 ;
V_1185 -> V_339 = V_339 ;
V_1185 -> V_340 = V_340 ;
V_1185 -> V_341 = V_341 ;
V_1185 -> V_342 = V_342 ;
V_1185 -> V_343 = V_343 ;
V_1185 -> V_344 = V_344 ;
V_278 = F_882 ( F_240 ( V_46 -> V_24 ) ,
F_235 ( V_1185 ) ) ;
if ( V_278 )
goto V_1206;
V_278 = F_860 ( & V_2 -> V_240 . V_235 ) ;
if ( V_278 )
goto V_1206;
if ( F_180 ( V_2 ) -> V_961 ) {
int V_1193 = F_177 ( V_2 ) ;
V_278 = F_862 ( F_185 ( V_70 ) , V_1193 ) ;
if ( V_278 ) {
F_156 ( L_240 ) ;
goto V_1207;
}
} else {
V_233 = F_184 ( V_70 , V_1185 -> V_225 ) ;
if ( F_191 ( V_233 ) ) {
F_156 ( L_241 ) ;
V_278 = F_243 ( V_233 ) ;
goto V_1207;
}
F_235 ( V_1185 ) -> V_233 = V_233 ;
}
V_1203 = V_1020 -> V_70 ;
V_1204 = F_235 ( V_1020 ) -> V_233 ;
F_845 ( F_185 ( V_1203 ) , F_185 ( V_70 ) ,
V_259 -> V_348 ) ;
V_1185 -> V_1177 = V_1020 -> V_1177 ;
* F_235 ( V_1020 ) = * F_235 ( V_1185 ) ;
V_1185 -> V_1177 = NULL ;
V_1185 -> V_70 = V_1203 ;
F_235 ( V_1185 ) -> V_233 = NULL ;
if ( V_111 -> V_24 -> V_328 ) {
F_883 ( V_111 , F_41 ( V_46 ) ) ;
V_259 -> V_1208 ( V_259 ,
F_240 ( V_46 -> V_24 ) ,
F_235 ( V_111 -> V_24 ) ) ;
} else {
F_242 ( V_111 , F_41 ( V_46 ) ) ;
V_259 -> V_336 ( V_259 , F_41 ( V_46 ) ) ;
}
if ( V_1204 )
F_198 ( V_1204 ) ;
V_1207:
F_4 ( & V_2 -> V_240 . V_235 ) ;
V_1206:
F_884 ( V_111 , V_1185 ) ;
return V_278 ;
V_1205:
return F_885 ( V_111 , V_46 , V_70 ,
V_341 , V_342 , V_343 , V_344 ,
V_337 , V_338 , V_339 , V_340 , V_434 ) ;
}
static struct V_259 *
F_886 ( struct V_1 * V_2 , enum V_75 V_75 )
{
struct V_259 * V_69 = NULL ;
struct V_245 * V_24 = NULL ;
const T_2 * V_1209 ;
unsigned int V_1210 ;
unsigned int V_270 ;
const V_36 * V_1211 ;
int V_278 ;
V_69 = F_508 ( sizeof( * V_69 ) , V_635 ) ;
if ( ! V_69 ) {
V_278 = - V_636 ;
goto V_993;
}
V_24 = F_887 ( & V_69 -> V_45 ) ;
if ( ! V_24 ) {
V_278 = - V_636 ;
goto V_993;
}
V_69 -> V_45 . V_24 = & V_24 -> V_45 ;
V_69 -> V_1212 = false ;
V_69 -> V_1213 = 1 ;
if ( F_52 ( V_2 ) >= 9 ) {
V_69 -> V_1212 = true ;
V_24 -> V_421 = - 1 ;
}
V_69 -> V_75 = V_75 ;
if ( F_888 ( V_2 ) && F_52 ( V_2 ) < 4 )
V_69 -> V_111 = (enum V_111 ) ! V_75 ;
else
V_69 -> V_111 = (enum V_111 ) V_75 ;
V_69 -> V_260 = V_359 ;
V_69 -> V_348 = F_889 ( V_75 ) ;
V_69 -> V_1214 = F_867 ;
if ( F_52 ( V_2 ) >= 10 || F_291 ( V_2 ) ) {
V_1209 = V_1215 ;
V_270 = F_173 ( V_1215 ) ;
V_1211 = V_1216 ;
V_69 -> V_1208 = F_293 ;
V_69 -> V_336 = F_304 ;
} else if ( F_52 ( V_2 ) >= 9 ) {
V_1209 = V_1215 ;
V_270 = F_173 ( V_1215 ) ;
if ( V_75 < V_360 )
V_1211 = V_1216 ;
else
V_1211 = V_1217 ;
V_69 -> V_1208 = F_293 ;
V_69 -> V_336 = F_304 ;
} else if ( F_52 ( V_2 ) >= 4 ) {
V_1209 = V_1218 ;
V_270 = F_173 ( V_1218 ) ;
V_1211 = V_1219 ;
V_69 -> V_1208 = F_263 ;
V_69 -> V_336 = F_279 ;
} else {
V_1209 = V_1220 ;
V_270 = F_173 ( V_1220 ) ;
V_1211 = V_1219 ;
V_69 -> V_1208 = F_263 ;
V_69 -> V_336 = F_279 ;
}
if ( F_52 ( V_2 ) >= 9 )
V_278 = F_890 ( & V_2 -> V_240 , & V_69 -> V_45 ,
0 , & V_1221 ,
V_1209 , V_270 ,
V_1211 ,
V_1222 ,
L_242 , F_72 ( V_75 ) ) ;
else if ( F_52 ( V_2 ) >= 5 || F_93 ( V_2 ) )
V_278 = F_890 ( & V_2 -> V_240 , & V_69 -> V_45 ,
0 , & V_1221 ,
V_1209 , V_270 ,
V_1211 ,
V_1222 ,
L_243 , F_72 ( V_75 ) ) ;
else
V_278 = F_890 ( & V_2 -> V_240 , & V_69 -> V_45 ,
0 , & V_1221 ,
V_1209 , V_270 ,
V_1211 ,
V_1222 ,
L_244 , F_84 ( V_69 -> V_111 ) ) ;
if ( V_278 )
goto V_993;
if ( F_52 ( V_2 ) >= 9 ) {
V_1210 =
V_264 | V_403 |
V_361 | V_291 ;
} else if ( F_11 ( V_2 ) && V_75 == V_101 ) {
V_1210 =
V_264 | V_361 |
V_369 ;
} else if ( F_52 ( V_2 ) >= 4 ) {
V_1210 =
V_264 | V_361 ;
} else {
V_1210 = V_264 ;
}
if ( F_52 ( V_2 ) >= 4 )
F_891 ( & V_69 -> V_45 ,
V_264 ,
V_1210 ) ;
F_892 ( & V_69 -> V_45 , & V_1223 ) ;
return V_69 ;
V_993:
F_236 ( V_24 ) ;
F_236 ( V_69 ) ;
return F_683 ( V_278 ) ;
}
static struct V_259 *
F_893 ( struct V_1 * V_2 ,
enum V_75 V_75 )
{
struct V_259 * V_975 = NULL ;
struct V_245 * V_24 = NULL ;
int V_278 ;
V_975 = F_508 ( sizeof( * V_975 ) , V_635 ) ;
if ( ! V_975 ) {
V_278 = - V_636 ;
goto V_993;
}
V_24 = F_887 ( & V_975 -> V_45 ) ;
if ( ! V_24 ) {
V_278 = - V_636 ;
goto V_993;
}
V_975 -> V_45 . V_24 = & V_24 -> V_45 ;
V_975 -> V_1212 = false ;
V_975 -> V_1213 = 1 ;
V_975 -> V_75 = V_75 ;
V_975 -> V_111 = V_75 ;
V_975 -> V_260 = V_261 ;
V_975 -> V_348 = F_894 ( V_75 ) ;
if ( F_74 ( V_2 ) || F_75 ( V_2 ) ) {
V_975 -> V_1208 = F_670 ;
V_975 -> V_336 = F_673 ;
V_975 -> V_1214 = F_668 ;
} else {
V_975 -> V_1208 = F_679 ;
V_975 -> V_336 = F_681 ;
V_975 -> V_1214 = F_678 ;
}
V_975 -> V_975 . V_45 = ~ 0 ;
V_975 -> V_975 . V_974 = ~ 0 ;
if ( F_74 ( V_2 ) || F_75 ( V_2 ) || F_677 ( V_2 ) )
V_975 -> V_975 . V_221 = ~ 0 ;
V_278 = F_890 ( & V_2 -> V_240 , & V_975 -> V_45 ,
0 , & V_1224 ,
V_1225 ,
F_173 ( V_1225 ) ,
V_1226 ,
V_1192 ,
L_245 , F_72 ( V_75 ) ) ;
if ( V_278 )
goto V_993;
if ( F_52 ( V_2 ) >= 4 )
F_891 ( & V_975 -> V_45 ,
V_264 ,
V_264 |
V_361 ) ;
if ( F_52 ( V_2 ) >= 9 )
V_24 -> V_421 = - 1 ;
F_892 ( & V_975 -> V_45 , & V_1223 ) ;
return V_975 ;
V_993:
F_236 ( V_24 ) ;
F_236 ( V_975 ) ;
return F_683 ( V_278 ) ;
}
static void F_657 ( struct V_62 * V_46 ,
struct V_18 * V_41 )
{
struct V_382 * V_383 =
& V_41 -> V_383 ;
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
int V_113 ;
V_46 -> V_384 = V_2 -> V_958 . V_384 [ V_46 -> V_75 ] ;
if ( ! V_46 -> V_384 )
return;
for ( V_113 = 0 ; V_113 < V_46 -> V_384 ; V_113 ++ ) {
struct V_1227 * V_1228 = & V_383 -> V_385 [ V_113 ] ;
V_1228 -> V_386 = 0 ;
V_1228 -> V_431 = V_1229 ;
}
V_383 -> V_421 = - 1 ;
}
static int F_895 ( struct V_1 * V_2 , enum V_75 V_75 )
{
struct V_62 * V_62 ;
struct V_18 * V_41 = NULL ;
struct V_259 * V_69 = NULL ;
struct V_259 * V_975 = NULL ;
int V_117 , V_278 ;
V_62 = F_508 ( sizeof( * V_62 ) , V_635 ) ;
if ( ! V_62 )
return - V_636 ;
V_41 = F_508 ( sizeof( * V_41 ) , V_635 ) ;
if ( ! V_41 ) {
V_278 = - V_636 ;
goto V_993;
}
V_62 -> V_71 = V_41 ;
V_62 -> V_45 . V_24 = & V_41 -> V_45 ;
V_41 -> V_45 . V_46 = & V_62 -> V_45 ;
V_69 = F_886 ( V_2 , V_75 ) ;
if ( F_191 ( V_69 ) ) {
V_278 = F_243 ( V_69 ) ;
goto V_993;
}
V_62 -> V_1230 |= F_232 ( V_69 -> V_260 ) ;
F_88 (dev_priv, pipe, sprite) {
struct V_259 * V_111 ;
V_111 = F_896 ( V_2 , V_75 , V_117 ) ;
if ( F_191 ( V_111 ) ) {
V_278 = F_243 ( V_111 ) ;
goto V_993;
}
V_62 -> V_1230 |= F_232 ( V_111 -> V_260 ) ;
}
V_975 = F_893 ( V_2 , V_75 ) ;
if ( F_191 ( V_975 ) ) {
V_278 = F_243 ( V_975 ) ;
goto V_993;
}
V_62 -> V_1230 |= F_232 ( V_975 -> V_260 ) ;
V_278 = F_897 ( & V_2 -> V_240 , & V_62 -> V_45 ,
& V_69 -> V_45 , & V_975 -> V_45 ,
& V_1231 ,
L_246 , F_72 ( V_75 ) ) ;
if ( V_278 )
goto V_993;
V_62 -> V_75 = V_75 ;
V_62 -> V_111 = V_69 -> V_111 ;
F_657 ( V_62 , V_41 ) ;
F_596 ( V_75 >= F_173 ( V_2 -> V_1232 ) ||
V_2 -> V_1232 [ V_62 -> V_111 ] != NULL ) ;
V_2 -> V_1232 [ V_62 -> V_111 ] = V_62 ;
V_2 -> V_1233 [ V_62 -> V_75 ] = V_62 ;
F_898 ( & V_62 -> V_45 , & V_1234 ) ;
F_899 ( & V_62 -> V_45 ) ;
F_20 ( F_778 ( & V_62 -> V_45 ) != V_62 -> V_75 ) ;
return 0 ;
V_993:
F_236 ( V_41 ) ;
F_236 ( V_62 ) ;
return V_278 ;
}
enum V_75 F_900 ( struct V_631 * V_632 )
{
struct V_43 * V_44 = V_632 -> V_45 . V_44 ;
F_20 ( ! F_700 ( & V_44 -> V_442 . V_992 ) ) ;
if ( ! V_632 -> V_45 . V_24 -> V_46 )
return V_595 ;
return F_41 ( V_632 -> V_45 . V_24 -> V_46 ) -> V_75 ;
}
int F_901 ( struct V_43 * V_44 , void * V_1235 ,
struct V_1236 * V_1237 )
{
struct V_1238 * V_1239 = V_1235 ;
struct V_123 * V_1240 ;
struct V_62 * V_46 ;
V_1240 = F_902 ( V_44 , V_1239 -> V_1241 ) ;
if ( ! V_1240 )
return - V_1242 ;
V_46 = F_41 ( V_1240 ) ;
V_1239 -> V_75 = V_46 -> V_75 ;
return 0 ;
}
static int F_903 ( struct V_517 * V_518 )
{
struct V_43 * V_44 = V_518 -> V_45 . V_44 ;
struct V_517 * V_1030 ;
int V_1243 = 0 ;
int V_1244 = 0 ;
F_594 (dev, source_encoder) {
if ( F_718 ( V_518 , V_1030 ) )
V_1243 |= ( 1 << V_1244 ) ;
V_1244 ++ ;
}
return V_1243 ;
}
static bool F_904 ( struct V_1 * V_2 )
{
if ( ! F_136 ( V_2 ) )
return false ;
if ( ( F_16 ( V_1245 ) & V_1246 ) == 0 )
return false ;
if ( F_15 ( V_2 ) && ( F_16 ( V_1247 ) & V_1248 ) )
return false ;
return true ;
}
static bool F_905 ( struct V_1 * V_2 )
{
if ( F_52 ( V_2 ) >= 9 )
return false ;
if ( F_906 ( V_2 ) || F_907 ( V_2 ) )
return false ;
if ( F_11 ( V_2 ) )
return false ;
if ( F_908 ( V_2 ) &&
F_16 ( V_1249 ) & V_1250 )
return false ;
if ( F_14 ( V_2 ) && F_16 ( F_909 ( V_604 ) ) & V_1251 )
return false ;
if ( ! V_2 -> V_677 . V_1252 )
return false ;
return true ;
}
void F_327 ( struct V_1 * V_2 )
{
int V_1253 ;
int V_1254 ;
if ( F_14 ( V_2 ) )
return;
if ( F_10 ( V_2 ) || F_11 ( V_2 ) )
V_1253 = 2 ;
else
V_1253 = 1 ;
for ( V_1254 = 0 ; V_1254 < V_1253 ; V_1254 ++ ) {
T_1 V_11 = F_16 ( F_70 ( V_1254 ) ) ;
V_11 = ( V_11 & ~ V_104 ) | V_105 ;
F_120 ( F_70 ( V_1254 ) , V_11 ) ;
}
}
static void F_910 ( struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) || F_29 ( V_2 ) )
V_2 -> V_1255 = V_1256 ;
else if ( F_10 ( V_2 ) || F_11 ( V_2 ) )
V_2 -> V_1255 = V_1257 ;
else
V_2 -> V_1255 = V_1258 ;
F_327 ( V_2 ) ;
}
static void F_911 ( struct V_1 * V_2 )
{
struct V_517 * V_518 ;
bool V_1259 = false ;
F_910 ( V_2 ) ;
F_912 ( V_2 ) ;
if ( F_905 ( V_2 ) )
F_913 ( V_2 ) ;
if ( F_29 ( V_2 ) ) {
F_914 ( V_2 , V_604 ) ;
F_914 ( V_2 , V_176 ) ;
F_914 ( V_2 , V_178 ) ;
F_915 ( V_2 ) ;
} else if ( F_14 ( V_2 ) ) {
int V_56 ;
V_56 = F_16 ( F_909 ( V_604 ) ) & V_1260 ;
if ( V_56 || F_655 ( V_2 ) )
F_914 ( V_2 , V_604 ) ;
V_56 = F_16 ( V_1249 ) ;
if ( V_56 & V_1261 )
F_914 ( V_2 , V_176 ) ;
if ( V_56 & V_1262 )
F_914 ( V_2 , V_178 ) ;
if ( V_56 & V_1263 )
F_914 ( V_2 , V_180 ) ;
if ( F_655 ( V_2 ) &&
( V_2 -> V_677 . V_1264 [ V_609 ] . V_1265 ||
V_2 -> V_677 . V_1264 [ V_609 ] . V_1266 ||
V_2 -> V_677 . V_1264 [ V_609 ] . V_1267 ) )
F_914 ( V_2 , V_609 ) ;
} else if ( F_69 ( V_2 ) ) {
int V_56 ;
V_1259 = F_916 ( V_2 , V_180 ) ;
if ( F_904 ( V_2 ) )
F_917 ( V_2 , V_1245 , V_604 ) ;
if ( F_16 ( V_149 ) & V_1268 ) {
V_56 = F_918 ( V_2 , V_1269 , V_176 ) ;
if ( ! V_56 )
F_919 ( V_2 , V_149 , V_176 ) ;
if ( ! V_56 && ( F_16 ( V_142 ) & V_1246 ) )
F_917 ( V_2 , V_142 , V_176 ) ;
}
if ( F_16 ( V_150 ) & V_1268 )
F_919 ( V_2 , V_150 , V_178 ) ;
if ( ! V_1259 && F_16 ( V_151 ) & V_1268 )
F_919 ( V_2 , V_151 , V_180 ) ;
if ( F_16 ( V_144 ) & V_1246 )
F_917 ( V_2 , V_144 , V_178 ) ;
if ( F_16 ( V_146 ) & V_1246 )
F_917 ( V_2 , V_146 , V_180 ) ;
} else if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
bool V_1270 , V_1271 ;
V_1270 = F_916 ( V_2 , V_176 ) ;
V_1271 = F_920 ( V_2 , V_176 ) ;
if ( F_16 ( V_1272 ) & V_1246 || V_1271 )
V_1270 &= F_917 ( V_2 , V_1272 , V_176 ) ;
if ( ( F_16 ( V_1273 ) & V_1268 || V_1271 ) && ! V_1270 )
F_919 ( V_2 , V_1273 , V_176 ) ;
V_1270 = F_916 ( V_2 , V_178 ) ;
V_1271 = F_920 ( V_2 , V_178 ) ;
if ( F_16 ( V_1274 ) & V_1246 || V_1271 )
V_1270 &= F_917 ( V_2 , V_1274 , V_178 ) ;
if ( ( F_16 ( V_1275 ) & V_1268 || V_1271 ) && ! V_1270 )
F_919 ( V_2 , V_1275 , V_178 ) ;
if ( F_11 ( V_2 ) ) {
V_1271 = F_920 ( V_2 , V_180 ) ;
if ( F_16 ( V_1276 ) & V_1246 || V_1271 )
F_917 ( V_2 , V_1276 , V_180 ) ;
if ( F_16 ( V_1277 ) & V_1268 || V_1271 )
F_919 ( V_2 , V_1277 , V_180 ) ;
}
F_915 ( V_2 ) ;
} else if ( ! F_49 ( V_2 ) && ! F_28 ( V_2 ) ) {
bool V_56 = false ;
if ( F_16 ( V_1278 ) & V_1268 ) {
F_156 ( L_247 ) ;
V_56 = F_918 ( V_2 , V_1278 , V_176 ) ;
if ( ! V_56 && F_93 ( V_2 ) ) {
F_156 ( L_248 ) ;
F_919 ( V_2 , V_1279 , V_176 ) ;
}
if ( ! V_56 && F_93 ( V_2 ) )
F_917 ( V_2 , V_1280 , V_176 ) ;
}
if ( F_16 ( V_1278 ) & V_1268 ) {
F_156 ( L_249 ) ;
V_56 = F_918 ( V_2 , V_1281 , V_178 ) ;
}
if ( ! V_56 && ( F_16 ( V_1281 ) & V_1268 ) ) {
if ( F_93 ( V_2 ) ) {
F_156 ( L_250 ) ;
F_919 ( V_2 , V_1282 , V_178 ) ;
}
if ( F_93 ( V_2 ) )
F_917 ( V_2 , V_1283 , V_178 ) ;
}
if ( F_93 ( V_2 ) && ( F_16 ( V_1284 ) & V_1246 ) )
F_917 ( V_2 , V_1284 , V_180 ) ;
} else if ( F_49 ( V_2 ) )
F_921 ( V_2 ) ;
if ( F_922 ( V_2 ) )
F_923 ( V_2 ) ;
F_924 ( V_2 ) ;
F_594 (&dev_priv->drm, encoder) {
V_518 -> V_45 . V_994 = V_518 -> V_1114 ;
V_518 -> V_45 . V_1285 =
F_903 ( V_518 ) ;
}
F_606 ( V_2 ) ;
F_925 ( & V_2 -> V_240 ) ;
}
static void F_926 ( struct V_205 * V_70 )
{
struct V_246 * V_247 = F_176 ( V_70 ) ;
F_927 ( V_70 ) ;
F_928 ( V_247 -> V_232 ) ;
F_20 ( ! V_247 -> V_232 -> V_1286 -- ) ;
F_929 ( V_247 -> V_232 ) ;
F_230 ( V_247 -> V_232 ) ;
F_236 ( V_247 ) ;
}
static int F_930 ( struct V_205 * V_70 ,
struct V_1236 * V_1237 ,
unsigned int * V_1287 )
{
struct V_246 * V_247 = F_176 ( V_70 ) ;
struct V_231 * V_232 = V_247 -> V_232 ;
if ( V_232 -> V_1288 . V_1289 ) {
F_669 ( L_251 ) ;
return - V_263 ;
}
return F_931 ( V_1237 , & V_232 -> V_45 , V_1287 ) ;
}
static int F_932 ( struct V_205 * V_70 ,
struct V_1236 * V_1237 ,
unsigned V_324 , unsigned V_1290 ,
struct V_1291 * V_1292 ,
unsigned V_1293 )
{
struct V_231 * V_232 = F_185 ( V_70 ) ;
F_933 ( V_232 ) ;
F_934 ( V_232 , V_1294 ) ;
return 0 ;
}
static
T_1 F_935 ( struct V_1 * V_2 ,
V_36 V_255 , T_2 V_274 )
{
T_1 V_229 = F_52 ( V_2 ) ;
if ( V_229 >= 9 ) {
int V_206 = F_936 ( V_274 , 0 ) ;
return V_39 ( 8192 * V_206 , 32768 ) ;
} else if ( V_229 >= 5 && ! F_158 ( V_2 ) ) {
return 32 * 1024 ;
} else if ( V_229 >= 4 ) {
if ( V_255 == V_210 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_229 >= 3 ) {
if ( V_255 == V_210 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_229 ( struct V_246 * V_247 ,
struct V_231 * V_232 ,
struct V_271 * V_317 )
{
struct V_1 * V_2 = F_34 ( V_232 -> V_45 . V_44 ) ;
struct V_205 * V_70 = & V_247 -> V_45 ;
struct V_1048 V_1049 ;
T_1 V_1295 ;
unsigned int V_322 , V_287 ;
int V_278 = - V_263 ;
int V_113 ;
F_928 ( V_232 ) ;
V_232 -> V_1286 ++ ;
V_322 = F_937 ( V_232 ) ;
V_287 = F_938 ( V_232 ) ;
F_929 ( V_232 ) ;
if ( V_317 -> V_324 & V_325 ) {
if ( V_322 != V_267 &&
V_322 != F_214 ( V_317 -> V_208 [ 0 ] ) ) {
F_156 ( L_252 ) ;
goto V_53;
}
} else {
if ( V_322 == V_265 ) {
V_317 -> V_208 [ 0 ] = V_210 ;
} else if ( V_322 == V_266 ) {
F_156 ( L_253 ) ;
goto V_53;
}
}
switch ( V_317 -> V_208 [ 0 ] ) {
case V_211 :
case V_213 :
switch ( V_317 -> V_274 ) {
case V_301 :
case V_310 :
case V_299 :
case V_311 :
break;
default:
F_156 ( L_254 ) ;
goto V_53;
}
case V_212 :
case V_214 :
if ( F_52 ( V_2 ) < 9 ) {
F_156 ( L_255 ,
V_317 -> V_208 [ 0 ] ) ;
goto V_53;
}
case V_209 :
case V_210 :
break;
default:
F_156 ( L_256 ,
V_317 -> V_208 [ 0 ] ) ;
goto V_53;
}
if ( F_180 ( V_2 ) -> V_229 < 4 &&
V_322 != F_214 ( V_317 -> V_208 [ 0 ] ) ) {
F_156 ( L_257 ) ;
goto V_53;
}
V_1295 = F_935 ( V_2 , V_317 -> V_208 [ 0 ] ,
V_317 -> V_274 ) ;
if ( V_317 -> V_242 [ 0 ] > V_1295 ) {
F_156 ( L_258 ,
V_317 -> V_208 [ 0 ] != V_209 ?
L_259 : L_260 ,
V_317 -> V_242 [ 0 ] , V_1295 ) ;
goto V_53;
}
if ( V_322 != V_267 && V_317 -> V_242 [ 0 ] != V_287 ) {
F_156 ( L_261 ,
V_317 -> V_242 [ 0 ] , V_287 ) ;
goto V_53;
}
switch ( V_317 -> V_274 ) {
case V_293 :
case V_297 :
case V_299 :
case V_311 :
break;
case V_295 :
if ( F_52 ( V_2 ) > 3 ) {
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
break;
case V_310 :
if ( ! F_10 ( V_2 ) && ! F_11 ( V_2 ) &&
F_52 ( V_2 ) < 9 ) {
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
break;
case V_301 :
case V_303 :
case V_305 :
if ( F_52 ( V_2 ) < 4 ) {
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
break;
case V_1296 :
if ( ! F_10 ( V_2 ) && ! F_11 ( V_2 ) ) {
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
break;
case V_390 :
case V_395 :
case V_393 :
case V_397 :
if ( F_52 ( V_2 ) < 5 && ! F_93 ( V_2 ) ) {
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
break;
default:
F_156 ( L_262 ,
F_740 ( V_317 -> V_274 , & V_1049 ) ) ;
goto V_53;
}
if ( V_317 -> V_262 [ 0 ] != 0 )
goto V_53;
F_939 ( & V_2 -> V_240 , V_70 , V_317 ) ;
for ( V_113 = 0 ; V_113 < V_70 -> V_207 -> V_277 ; V_113 ++ ) {
T_1 V_1297 ;
if ( V_317 -> V_1298 [ V_113 ] != V_317 -> V_1298 [ 0 ] ) {
F_156 ( L_263 , V_113 ) ;
goto V_53;
}
V_1297 = F_280 ( V_70 , V_113 ) ;
if ( F_940 ( V_2 ) && V_113 == 0 && V_70 -> V_222 > 3840 &&
( V_70 -> V_208 == V_211 ||
V_70 -> V_208 == V_213 ) )
V_1297 *= 4 ;
if ( V_70 -> V_242 [ V_113 ] & ( V_1297 - 1 ) ) {
F_156 ( L_264 ,
V_113 , V_70 -> V_242 [ V_113 ] , V_1297 ) ;
goto V_53;
}
}
V_247 -> V_232 = V_232 ;
V_278 = F_217 ( V_2 , V_70 ) ;
if ( V_278 )
goto V_53;
V_278 = F_941 ( & V_2 -> V_240 , V_70 , & V_1299 ) ;
if ( V_278 ) {
F_123 ( L_265 , V_278 ) ;
goto V_53;
}
return 0 ;
V_53:
F_928 ( V_232 ) ;
V_232 -> V_1286 -- ;
F_929 ( V_232 ) ;
return V_278 ;
}
static struct V_205 *
F_942 ( struct V_43 * V_44 ,
struct V_1236 * V_1300 ,
const struct V_271 * V_1301 )
{
struct V_205 * V_70 ;
struct V_231 * V_232 ;
struct V_271 V_317 = * V_1301 ;
V_232 = F_943 ( V_1300 , V_317 . V_1298 [ 0 ] ) ;
if ( ! V_232 )
return F_683 ( - V_1242 ) ;
V_70 = F_682 ( V_232 , & V_317 ) ;
if ( F_191 ( V_70 ) )
F_230 ( V_232 ) ;
return V_70 ;
}
static void F_944 ( struct V_432 * V_24 )
{
struct V_572 * V_334 = F_309 ( V_24 ) ;
F_945 ( V_24 ) ;
F_946 ( & V_334 -> V_1164 ) ;
F_236 ( V_24 ) ;
}
void F_947 ( struct V_1 * V_2 )
{
F_948 ( V_2 ) ;
if ( F_180 ( V_2 ) -> V_229 >= 9 ) {
V_2 -> V_448 . V_1112 = F_656 ;
V_2 -> V_448 . V_1302 =
F_617 ;
V_2 -> V_448 . V_1031 =
F_638 ;
V_2 -> V_448 . V_1143 = F_453 ;
V_2 -> V_448 . V_626 = F_465 ;
} else if ( F_14 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_656 ;
V_2 -> V_448 . V_1302 =
F_620 ;
V_2 -> V_448 . V_1031 =
F_638 ;
V_2 -> V_448 . V_1143 = F_453 ;
V_2 -> V_448 . V_626 = F_465 ;
} else if ( F_69 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_621 ;
V_2 -> V_448 . V_1302 =
F_620 ;
V_2 -> V_448 . V_1031 =
F_610 ;
V_2 -> V_448 . V_1143 = F_441 ;
V_2 -> V_448 . V_626 = F_463 ;
} else if ( F_11 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_585 ;
V_2 -> V_448 . V_1143 = F_480 ;
V_2 -> V_448 . V_626 = F_491 ;
} else if ( F_10 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_586 ;
V_2 -> V_448 . V_1143 = F_480 ;
V_2 -> V_448 . V_626 = F_491 ;
} else if ( F_93 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_582 ;
V_2 -> V_448 . V_1143 = F_489 ;
V_2 -> V_448 . V_626 = F_491 ;
} else if ( F_28 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_583 ;
V_2 -> V_448 . V_1143 = F_489 ;
V_2 -> V_448 . V_626 = F_491 ;
} else if ( ! F_49 ( V_2 ) ) {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_584 ;
V_2 -> V_448 . V_1143 = F_489 ;
V_2 -> V_448 . V_626 = F_491 ;
} else {
V_2 -> V_448 . V_1112 = F_591 ;
V_2 -> V_448 . V_1302 =
F_589 ;
V_2 -> V_448 . V_1031 = F_581 ;
V_2 -> V_448 . V_1143 = F_489 ;
V_2 -> V_448 . V_626 = F_491 ;
}
if ( F_15 ( V_2 ) ) {
V_2 -> V_448 . V_522 = F_341 ;
} else if ( F_257 ( V_2 ) ) {
V_2 -> V_448 . V_522 = F_347 ;
} else if ( F_258 ( V_2 ) ) {
V_2 -> V_448 . V_522 = F_349 ;
} else if ( F_259 ( V_2 ) || F_260 ( V_2 ) ) {
V_2 -> V_448 . V_522 = V_1303 ;
}
if ( V_2 -> V_958 . V_229 >= 9 )
V_2 -> V_448 . V_1172 = F_812 ;
else
V_2 -> V_448 . V_1172 = F_811 ;
}
static void F_949 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
V_2 -> V_679 |= V_680 ;
F_950 ( L_266 ) ;
}
static void F_951 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
V_2 -> V_679 |= V_1304 ;
F_950 ( L_267 ) ;
}
static void F_952 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
V_2 -> V_679 |= V_1305 ;
F_950 ( L_268 ) ;
}
static void F_953 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
V_2 -> V_679 |= V_1306 ;
F_950 ( L_269 ) ;
}
static int F_954 ( const struct V_1307 * V_260 )
{
F_950 ( L_270 , V_260 -> V_1308 ) ;
return 1 ;
}
static void F_955 ( struct V_43 * V_44 )
{
struct V_1309 * V_1310 = V_44 -> V_1311 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < F_173 ( V_1312 ) ; V_113 ++ ) {
struct V_1313 * V_1314 = & V_1312 [ V_113 ] ;
if ( V_1310 -> V_1315 == V_1314 -> V_1315 &&
( V_1310 -> V_1316 == V_1314 -> V_1316 ||
V_1314 -> V_1316 == V_1317 ) &&
( V_1310 -> V_1318 == V_1314 -> V_1318 ||
V_1314 -> V_1318 == V_1317 ) )
V_1314 -> V_1319 ( V_44 ) ;
}
for ( V_113 = 0 ; V_113 < F_173 ( V_1320 ) ; V_113 ++ ) {
if ( F_956 ( * V_1320 [ V_113 ] . V_1321 ) != 0 )
V_1320 [ V_113 ] . V_1319 ( V_44 ) ;
}
}
static void F_957 ( struct V_1 * V_2 )
{
struct V_1309 * V_1311 = V_2 -> V_240 . V_1311 ;
T_8 V_1322 ;
T_3 V_1323 = F_958 ( V_2 ) ;
F_959 ( V_1311 , V_1324 ) ;
F_960 ( V_1325 , V_1326 ) ;
V_1322 = F_961 ( V_1327 ) ;
F_960 ( V_1322 | 1 << 5 , V_1327 ) ;
F_962 ( V_1311 , V_1324 ) ;
F_122 ( 300 ) ;
F_120 ( V_1323 , V_1328 ) ;
F_121 ( V_1323 ) ;
}
void F_328 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_635 ( V_2 ) ;
V_2 -> V_1125 . V_1126 = V_2 -> V_1125 . V_1127 = V_2 -> V_1125 . V_1329 ;
F_963 ( V_2 ) ;
}
static void F_964 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_432 * V_24 ;
struct V_572 * V_334 ;
struct V_123 * V_46 ;
struct V_23 * V_1144 ;
struct V_433 V_434 ;
int V_278 ;
int V_113 ;
if ( ! V_2 -> V_448 . V_1174 )
return;
F_318 ( & V_434 , 0 ) ;
V_470:
V_278 = F_319 ( V_44 , & V_434 ) ;
if ( V_278 == - V_437 ) {
F_320 ( & V_434 ) ;
goto V_470;
} else if ( F_20 ( V_278 ) ) {
goto V_993;
}
V_24 = F_321 ( V_44 , & V_434 ) ;
if ( F_20 ( F_191 ( V_24 ) ) )
goto V_993;
V_334 = F_309 ( V_24 ) ;
if ( ! F_158 ( V_2 ) )
V_334 -> V_436 = true ;
V_278 = F_795 ( V_44 , V_24 ) ;
if ( V_278 ) {
F_6 ( true , L_271 ) ;
goto V_1330;
}
F_308 (state, crtc, cstate, i) {
struct V_18 * V_1331 = F_240 ( V_1144 ) ;
V_1331 -> V_1036 . V_1141 = true ;
V_2 -> V_448 . V_1174 ( V_334 , V_1331 ) ;
}
V_1330:
F_323 ( V_24 ) ;
V_993:
F_332 ( & V_434 ) ;
F_333 ( & V_434 ) ;
}
int F_965 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_315 * V_316 = & V_2 -> V_316 ;
enum V_75 V_75 ;
struct V_62 * V_46 ;
F_966 ( V_44 ) ;
V_44 -> V_442 . V_1332 = 0 ;
V_44 -> V_442 . V_1333 = 0 ;
V_44 -> V_442 . V_1334 = 24 ;
V_44 -> V_442 . V_1335 = 1 ;
V_44 -> V_442 . V_1336 = true ;
V_44 -> V_442 . V_888 = & V_1337 ;
F_967 ( & V_2 -> V_1156 . V_1157 ) ;
F_853 ( & V_2 -> V_1156 . V_1160 ,
F_817 ) ;
F_955 ( V_44 ) ;
F_968 ( V_2 ) ;
if ( F_180 ( V_2 ) -> V_639 == 0 )
return 0 ;
if ( F_116 ( V_2 ) || F_102 ( V_2 ) ) {
bool V_1338 = ! ! ( F_16 ( V_825 ) &
V_831 ) ;
if ( V_2 -> V_677 . V_678 != V_1338 ) {
F_156 ( L_272 ,
V_1338 ? L_77 : L_78 ,
V_2 -> V_677 . V_678 ? L_77 : L_78 ) ;
V_2 -> V_677 . V_678 = V_1338 ;
}
}
if ( F_49 ( V_2 ) ) {
V_44 -> V_442 . V_357 = 2048 ;
V_44 -> V_442 . V_358 = 2048 ;
} else if ( F_969 ( V_2 ) ) {
V_44 -> V_442 . V_357 = 4096 ;
V_44 -> V_442 . V_358 = 4096 ;
} else {
V_44 -> V_442 . V_357 = 8192 ;
V_44 -> V_442 . V_358 = 8192 ;
}
if ( F_74 ( V_2 ) || F_75 ( V_2 ) ) {
V_44 -> V_442 . V_968 = F_74 ( V_2 ) ? 64 : 512 ;
V_44 -> V_442 . V_969 = 1023 ;
} else if ( F_49 ( V_2 ) ) {
V_44 -> V_442 . V_968 = V_1339 ;
V_44 -> V_442 . V_969 = V_1340 ;
} else {
V_44 -> V_442 . V_968 = V_1341 ;
V_44 -> V_442 . V_969 = V_1342 ;
}
V_44 -> V_442 . V_1343 = V_316 -> V_1344 ;
F_156 ( L_273 ,
F_180 ( V_2 ) -> V_639 ,
F_180 ( V_2 ) -> V_639 > 1 ? L_274 : L_275 ) ;
F_86 (dev_priv, pipe) {
int V_278 ;
V_278 = F_895 ( V_2 , V_75 ) ;
if ( V_278 ) {
F_970 ( V_44 ) ;
return V_278 ;
}
}
F_971 ( V_44 ) ;
F_9 ( V_2 ) ;
F_328 ( V_44 ) ;
if ( V_2 -> V_648 == 0 )
F_972 ( V_2 ) ;
F_957 ( V_2 ) ;
F_911 ( V_2 ) ;
F_973 ( V_44 ) ;
F_306 ( V_44 , V_44 -> V_442 . V_445 ) ;
F_974 ( V_44 ) ;
F_134 (dev, crtc) {
struct V_313 V_314 = {} ;
if ( ! V_46 -> V_68 )
continue;
V_2 -> V_448 . V_1302 ( V_46 ,
& V_314 ) ;
F_234 ( V_46 , & V_314 ) ;
}
if ( ! F_158 ( V_2 ) )
F_964 ( V_44 ) ;
return 0 ;
}
void F_492 ( struct V_1 * V_2 , enum V_75 V_75 )
{
struct V_26 clock = {
. V_35 = 18 ,
. V_28 = 7 ,
. V_30 = 13 ,
. V_31 = 4 ,
. V_32 = 2 ,
} ;
T_1 V_26 , V_682 ;
int V_113 ;
F_20 ( F_22 ( 48000 , & clock ) != 25154 ) ;
F_156 ( L_276 ,
F_72 ( V_75 ) , clock . V_33 , clock . V_34 ) ;
V_682 = F_530 ( & clock ) ;
V_26 = ( F_16 ( F_57 ( V_75 ) ) & V_166 ) |
V_163 |
( ( clock . V_30 - 2 ) << V_741 ) |
V_753 |
V_751 |
V_84 ;
F_120 ( F_487 ( V_75 ) , V_682 ) ;
F_120 ( F_488 ( V_75 ) , V_682 ) ;
F_120 ( F_371 ( V_75 ) , ( 640 - 1 ) | ( ( 800 - 1 ) << 16 ) ) ;
F_120 ( F_373 ( V_75 ) , ( 640 - 1 ) | ( ( 800 - 1 ) << 16 ) ) ;
F_120 ( F_375 ( V_75 ) , ( 656 - 1 ) | ( ( 752 - 1 ) << 16 ) ) ;
F_120 ( F_377 ( V_75 ) , ( 480 - 1 ) | ( ( 525 - 1 ) << 16 ) ) ;
F_120 ( F_379 ( V_75 ) , ( 480 - 1 ) | ( ( 525 - 1 ) << 16 ) ) ;
F_120 ( F_381 ( V_75 ) , ( 490 - 1 ) | ( ( 492 - 1 ) << 16 ) ) ;
F_120 ( F_336 ( V_75 ) , ( ( 640 - 1 ) << 16 ) | ( 480 - 1 ) ) ;
F_120 ( F_57 ( V_75 ) , V_26 & ~ V_163 ) ;
F_120 ( F_57 ( V_75 ) , V_26 ) ;
F_121 ( F_57 ( V_75 ) ) ;
F_122 ( 150 ) ;
F_120 ( F_57 ( V_75 ) , V_26 ) ;
for ( V_113 = 0 ; V_113 < 3 ; V_113 ++ ) {
F_120 ( F_57 ( V_75 ) , V_26 ) ;
F_121 ( F_57 ( V_75 ) ) ;
F_122 ( 150 ) ;
}
F_120 ( F_53 ( V_75 ) , V_110 | V_784 ) ;
F_121 ( F_53 ( V_75 ) ) ;
}
void F_975 ( struct V_1 * V_2 , enum V_75 V_75 )
{
F_156 ( L_277 ,
F_72 ( V_75 ) ) ;
F_976 ( V_2 , V_1345 ) ;
F_976 ( V_2 , V_381 ) ;
F_120 ( F_53 ( V_75 ) , 0 ) ;
F_121 ( F_53 ( V_75 ) ) ;
if ( F_55 ( F_47 ( V_2 , V_75 ) , 100 ) )
F_123 ( L_278 , F_72 ( V_75 ) ) ;
F_120 ( F_57 ( V_75 ) , V_163 ) ;
F_121 ( F_57 ( V_75 ) ) ;
}
static bool
F_977 ( struct V_62 * V_46 )
{
struct V_1 * V_2 = F_34 ( V_46 -> V_45 . V_44 ) ;
T_1 V_11 ;
if ( F_180 ( V_2 ) -> V_639 == 1 )
return true ;
V_11 = F_16 ( F_83 ( ! V_46 -> V_111 ) ) ;
if ( ( V_11 & V_112 ) &&
( ! ! ( V_11 & V_115 ) == V_46 -> V_75 ) )
return false ;
return true ;
}
static bool F_978 ( struct V_62 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_517 * V_518 ;
F_387 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static struct V_631 * F_979 ( struct V_517 * V_518 )
{
struct V_43 * V_44 = V_518 -> V_45 . V_44 ;
struct V_631 * V_632 ;
F_980 (dev, &encoder->base, connector)
return V_632 ;
return NULL ;
}
static bool F_981 ( struct V_1 * V_2 ,
enum V_74 V_513 )
{
return F_116 ( V_2 ) || F_102 ( V_2 ) ||
( F_908 ( V_2 ) && V_513 == V_1346 ) ;
}
static void F_982 ( struct V_62 * V_46 ,
struct V_433 * V_434 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_74 V_76 = V_46 -> V_71 -> V_76 ;
if ( ! F_454 ( V_76 ) ) {
T_3 V_9 = F_53 ( V_76 ) ;
F_120 ( V_9 ,
F_16 ( V_9 ) & ~ V_1347 ) ;
}
F_983 ( & V_46 -> V_45 ) ;
if ( V_46 -> V_68 ) {
struct V_259 * V_111 ;
F_450 ( & V_46 -> V_45 ) ;
F_984 (dev, crtc, plane) {
if ( V_111 -> V_45 . type == V_1222 )
continue;
F_242 ( & V_111 -> V_45 , V_46 ) ;
V_111 -> V_336 ( V_111 , V_46 ) ;
}
}
if ( F_52 ( V_2 ) < 4 && ! F_977 ( V_46 ) ) {
bool V_111 ;
F_156 ( L_279 ,
V_46 -> V_45 . V_45 . V_260 , V_46 -> V_45 . V_8 ) ;
V_111 = V_46 -> V_111 ;
V_46 -> V_45 . V_69 -> V_24 -> V_328 = true ;
V_46 -> V_111 = ! V_111 ;
F_493 ( & V_46 -> V_45 , V_434 ) ;
V_46 -> V_111 = V_111 ;
}
if ( V_46 -> V_68 && ! F_978 ( V_46 ) )
F_493 ( & V_46 -> V_45 , V_434 ) ;
if ( V_46 -> V_68 || F_158 ( V_2 ) ) {
V_46 -> V_1348 = true ;
if ( F_981 ( V_2 , (enum V_74 ) V_46 -> V_75 ) )
V_46 -> V_1349 = true ;
}
}
static void F_985 ( struct V_517 * V_518 )
{
struct V_631 * V_632 ;
bool V_1350 = V_518 -> V_45 . V_46 &&
F_41 ( V_518 -> V_45 . V_46 ) -> V_68 ;
V_632 = F_979 ( V_518 ) ;
if ( V_632 && ! V_1350 ) {
F_156 ( L_280 ,
V_518 -> V_45 . V_45 . V_260 ,
V_518 -> V_45 . V_8 ) ;
if ( V_518 -> V_45 . V_46 ) {
struct V_23 * V_41 = V_518 -> V_45 . V_46 -> V_24 ;
F_156 ( L_281 ,
V_518 -> V_45 . V_45 . V_260 ,
V_518 -> V_45 . V_8 ) ;
V_518 -> V_586 ( V_518 , F_240 ( V_41 ) , V_632 -> V_45 . V_24 ) ;
if ( V_518 -> V_587 )
V_518 -> V_587 ( V_518 , F_240 ( V_41 ) , V_632 -> V_45 . V_24 ) ;
}
V_518 -> V_45 . V_46 = NULL ;
V_632 -> V_45 . V_1351 = V_1352 ;
V_632 -> V_45 . V_518 = NULL ;
}
}
void F_986 ( struct V_1 * V_2 )
{
T_3 V_1323 = F_958 ( V_2 ) ;
if ( ! ( F_16 ( V_1323 ) & V_1328 ) ) {
F_156 ( L_282 ) ;
F_957 ( V_2 ) ;
}
}
void F_307 ( struct V_1 * V_2 )
{
if ( ! F_80 ( V_2 , V_1353 ) )
return;
F_986 ( V_2 ) ;
F_81 ( V_2 , V_1353 ) ;
}
static bool F_987 ( struct V_259 * V_111 )
{
struct V_1 * V_2 = F_34 ( V_111 -> V_45 . V_44 ) ;
return F_16 ( F_83 ( V_111 -> V_111 ) ) & V_112 ;
}
static void F_988 ( struct V_62 * V_46 )
{
struct V_259 * V_69 = F_212 ( V_46 -> V_45 . V_69 ) ;
bool V_328 ;
V_328 = V_46 -> V_68 && F_987 ( V_69 ) ;
F_231 ( F_240 ( V_46 -> V_45 . V_24 ) ,
F_235 ( V_69 -> V_45 . V_24 ) ,
V_328 ) ;
}
static void F_989 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 ;
struct V_62 * V_46 ;
struct V_517 * V_518 ;
struct V_631 * V_632 ;
struct V_1040 V_1041 ;
int V_113 ;
V_2 -> V_629 = 0 ;
F_134 (dev, crtc) {
struct V_18 * V_41 =
F_240 ( V_46 -> V_45 . V_24 ) ;
F_776 ( & V_41 -> V_45 ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_45 . V_46 = & V_46 -> V_45 ;
V_41 -> V_45 . V_68 = V_41 -> V_45 . V_514 =
V_2 -> V_448 . V_1112 ( V_46 , V_41 ) ;
V_46 -> V_45 . V_124 = V_41 -> V_45 . V_514 ;
V_46 -> V_68 = V_41 -> V_45 . V_68 ;
if ( V_41 -> V_45 . V_68 )
V_2 -> V_629 |= 1 << V_46 -> V_75 ;
F_988 ( V_46 ) ;
F_156 ( L_283 ,
V_46 -> V_45 . V_45 . V_260 , V_46 -> V_45 . V_8 ,
F_737 ( V_41 -> V_45 . V_68 ) ) ;
}
for ( V_113 = 0 ; V_113 < V_2 -> V_823 ; V_113 ++ ) {
struct V_882 * V_883 = & V_2 -> V_1120 [ V_113 ] ;
V_883 -> V_1116 = V_883 -> V_888 . V_633 ( V_2 , V_883 ,
& V_883 -> V_24 . V_1118 ) ;
V_883 -> V_24 . V_1114 = 0 ;
F_134 (dev, crtc) {
struct V_18 * V_41 =
F_240 ( V_46 -> V_45 . V_24 ) ;
if ( V_41 -> V_45 . V_68 &&
V_41 -> V_184 == V_883 )
V_883 -> V_24 . V_1114 |= 1 << V_46 -> V_75 ;
}
V_883 -> V_1117 = V_883 -> V_24 . V_1114 ;
F_156 ( L_284 ,
V_883 -> V_8 , V_883 -> V_24 . V_1114 , V_883 -> V_1116 ) ;
}
F_594 (dev, encoder) {
V_75 = 0 ;
if ( V_518 -> V_633 ( V_518 , & V_75 ) ) {
struct V_18 * V_41 ;
V_46 = F_46 ( V_2 , V_75 ) ;
V_41 = F_240 ( V_46 -> V_45 . V_24 ) ;
V_518 -> V_45 . V_46 = & V_46 -> V_45 ;
V_41 -> V_1059 |= 1 << V_518 -> type ;
V_518 -> V_1113 ( V_518 , V_41 ) ;
} else {
V_518 -> V_45 . V_46 = NULL ;
}
F_156 ( L_285 ,
V_518 -> V_45 . V_45 . V_260 , V_518 -> V_45 . V_8 ,
F_737 ( V_518 -> V_45 . V_46 ) ,
F_72 ( V_75 ) ) ;
}
F_725 ( V_44 , & V_1041 ) ;
F_726 (connector, &conn_iter) {
if ( V_632 -> V_633 ( V_632 ) ) {
V_632 -> V_45 . V_1351 = V_1354 ;
V_518 = V_632 -> V_518 ;
V_632 -> V_45 . V_518 = & V_518 -> V_45 ;
if ( V_518 -> V_45 . V_46 &&
V_518 -> V_45 . V_46 -> V_24 -> V_68 ) {
V_518 -> V_45 . V_46 -> V_24 -> V_627 |=
1 << F_990 ( & V_632 -> V_45 ) ;
V_518 -> V_45 . V_46 -> V_24 -> V_628 |=
1 << F_991 ( & V_518 -> V_45 ) ;
}
} else {
V_632 -> V_45 . V_1351 = V_1352 ;
V_632 -> V_45 . V_518 = NULL ;
}
F_156 ( L_286 ,
V_632 -> V_45 . V_45 . V_260 , V_632 -> V_45 . V_8 ,
F_737 ( V_632 -> V_45 . V_518 ) ) ;
}
F_729 ( & V_1041 ) ;
F_134 (dev, crtc) {
struct V_18 * V_41 =
F_240 ( V_46 -> V_45 . V_24 ) ;
int V_1355 = 0 ;
memset ( & V_46 -> V_45 . V_431 , 0 , sizeof( V_46 -> V_45 . V_431 ) ) ;
if ( V_41 -> V_45 . V_68 ) {
F_576 ( & V_46 -> V_45 . V_431 , V_41 ) ;
F_576 ( & V_41 -> V_45 . V_72 , V_41 ) ;
F_20 ( F_497 ( V_46 -> V_45 . V_24 , & V_46 -> V_45 . V_431 ) ) ;
V_41 -> V_45 . V_431 . V_1132 = V_1356 ;
F_522 ( V_41 ) ;
if ( F_52 ( V_2 ) >= 9 || F_260 ( V_2 ) ||
F_10 ( V_2 ) || F_11 ( V_2 ) )
V_1355 = V_41 -> V_647 ;
else
F_20 ( V_2 -> V_448 . V_1129 ) ;
if ( F_260 ( V_2 ) && V_41 -> V_558 )
V_1355 = F_221 ( V_1355 * 100 , 95 ) ;
F_992 ( & V_46 -> V_45 ,
& V_41 -> V_45 . V_72 ) ;
F_783 ( V_46 ) ;
}
V_2 -> V_630 [ V_46 -> V_75 ] = V_1355 ;
F_763 ( V_2 , V_41 ) ;
}
}
static void
F_993 ( struct V_1 * V_2 )
{
struct V_517 * V_518 ;
F_594 (&dev_priv->drm, encoder) {
T_4 V_1357 ;
enum V_108 V_618 ;
if ( ! V_518 -> V_1358 )
continue;
V_1357 = V_518 -> V_1358 ( V_518 ) ;
F_477 (domain, get_domains)
F_478 ( V_2 , V_618 ) ;
}
}
static void
F_306 ( struct V_43 * V_44 ,
struct V_433 * V_434 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
enum V_75 V_75 ;
struct V_62 * V_46 ;
struct V_517 * V_518 ;
int V_113 ;
F_989 ( V_44 ) ;
F_993 ( V_2 ) ;
F_594 (dev, encoder) {
F_985 ( V_518 ) ;
}
F_86 (dev_priv, pipe) {
V_46 = F_46 ( V_2 , V_75 ) ;
F_982 ( V_46 , V_434 ) ;
F_734 ( V_46 , V_46 -> V_71 ,
L_287 ) ;
}
F_724 ( V_44 ) ;
for ( V_113 = 0 ; V_113 < V_2 -> V_823 ; V_113 ++ ) {
struct V_882 * V_883 = & V_2 -> V_1120 [ V_113 ] ;
if ( ! V_883 -> V_1116 || V_883 -> V_1117 )
continue;
F_156 ( L_288 , V_883 -> V_8 ) ;
V_883 -> V_888 . V_586 ( V_2 , V_883 ) ;
V_883 -> V_1116 = false ;
}
if ( F_93 ( V_2 ) ) {
F_994 ( V_44 ) ;
F_995 ( V_2 ) ;
} else if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
F_996 ( V_44 ) ;
F_997 ( V_2 ) ;
} else if ( F_52 ( V_2 ) >= 9 ) {
F_998 ( V_44 ) ;
} else if ( F_69 ( V_2 ) ) {
F_999 ( V_44 ) ;
}
F_134 (dev, crtc) {
T_4 V_1168 ;
V_1168 = F_476 ( & V_46 -> V_45 , V_46 -> V_71 ) ;
if ( F_20 ( V_1168 ) )
F_479 ( V_2 , V_1168 ) ;
}
F_1000 ( V_2 , false ) ;
F_1001 ( V_2 ) ;
F_1002 ( V_2 ) ;
}
void F_1003 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
struct V_432 * V_24 = V_2 -> V_444 ;
struct V_433 V_434 ;
int V_278 ;
V_2 -> V_444 = NULL ;
if ( V_24 )
V_24 -> V_445 = & V_434 ;
F_318 ( & V_434 , 0 ) ;
while ( 1 ) {
V_278 = F_319 ( V_44 , & V_434 ) ;
if ( V_278 != - V_437 )
break;
F_320 ( & V_434 ) ;
}
if ( ! V_278 )
V_278 = F_305 ( V_44 , V_24 , & V_434 ) ;
F_332 ( & V_434 ) ;
F_333 ( & V_434 ) ;
if ( V_278 )
F_123 ( L_62 , V_278 ) ;
if ( V_24 )
F_323 ( V_24 ) ;
}
void F_1004 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_1005 ( V_2 ) ;
F_1006 ( V_2 ) ;
}
int F_1007 ( struct V_580 * V_632 )
{
struct V_631 * V_631 = F_506 ( V_632 ) ;
int V_278 ;
V_278 = F_1008 ( V_631 ) ;
if ( V_278 )
goto V_53;
return 0 ;
V_53:
return V_278 ;
}
void F_1009 ( struct V_580 * V_632 )
{
struct V_631 * V_631 = F_506 ( V_632 ) ;
F_1010 ( V_631 ) ;
F_1011 ( V_632 ) ;
}
static void F_1012 ( struct V_43 * V_44 )
{
struct V_631 * V_632 ;
struct V_1040 V_1041 ;
F_1013 ( V_44 ) ;
F_725 ( V_44 , & V_1041 ) ;
F_726 (connector, &conn_iter) {
if ( V_632 -> V_1359 . V_1360 )
F_1014 ( & V_632 -> V_1359 ) ;
}
F_729 ( & V_1041 ) ;
}
void F_1015 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_34 ( V_44 ) ;
F_1016 ( & V_2 -> V_1156 . V_1160 ) ;
F_20 ( ! F_1017 ( & V_2 -> V_1156 . V_1157 ) ) ;
F_1018 ( V_2 ) ;
F_1019 ( V_2 ) ;
F_1012 ( V_44 ) ;
F_1020 ( V_2 ) ;
F_1021 () ;
F_1022 ( V_2 ) ;
F_1023 () ;
F_970 ( V_44 ) ;
F_1024 ( V_2 ) ;
F_1025 ( V_2 ) ;
F_1026 ( V_2 ) ;
}
void F_1027 ( struct V_631 * V_632 ,
struct V_517 * V_518 )
{
V_632 -> V_518 = V_518 ;
F_1028 ( & V_632 -> V_45 ,
& V_518 -> V_45 ) ;
}
int F_1029 ( struct V_1 * V_2 , bool V_24 )
{
unsigned V_9 = F_52 ( V_2 ) >= 6 ? V_1361 : V_1362 ;
T_9 V_1363 ;
if ( F_1030 ( V_2 -> V_1364 , V_9 , & V_1363 ) ) {
F_123 ( L_289 ) ;
return - V_1365 ;
}
if ( ! ! ( V_1363 & V_1366 ) == ! V_24 )
return 0 ;
if ( V_24 )
V_1363 &= ~ V_1366 ;
else
V_1363 |= V_1366 ;
if ( F_1031 ( V_2 -> V_1364 , V_9 , V_1363 ) ) {
F_123 ( L_290 ) ;
return - V_1365 ;
}
return 0 ;
}
struct V_1367 *
F_1032 ( struct V_1 * V_2 )
{
struct V_1367 * error ;
int V_1368 [] = {
V_1346 ,
V_1369 ,
V_1370 ,
V_592 ,
} ;
int V_113 ;
if ( F_180 ( V_2 ) -> V_639 == 0 )
return NULL ;
error = F_508 ( sizeof( * error ) , V_1371 ) ;
if ( error == NULL )
return NULL ;
if ( F_259 ( V_2 ) || F_260 ( V_2 ) )
error -> V_1372 =
F_16 ( F_624 ( V_890 ) ) ;
F_86 (dev_priv, i) {
error -> V_75 [ V_113 ] . V_1373 =
F_1033 ( V_2 ,
F_472 ( V_113 ) ) ;
if ( ! error -> V_75 [ V_113 ] . V_1373 )
continue;
error -> V_975 [ V_113 ] . V_599 = F_16 ( F_76 ( V_113 ) ) ;
error -> V_975 [ V_113 ] . V_1374 = F_16 ( F_672 ( V_113 ) ) ;
error -> V_975 [ V_113 ] . V_45 = F_16 ( F_671 ( V_113 ) ) ;
error -> V_111 [ V_113 ] . V_599 = F_16 ( F_83 ( V_113 ) ) ;
error -> V_111 [ V_113 ] . V_287 = F_16 ( F_271 ( V_113 ) ) ;
if ( F_52 ( V_2 ) <= 3 ) {
error -> V_111 [ V_113 ] . V_221 = F_16 ( F_266 ( V_113 ) ) ;
error -> V_111 [ V_113 ] . V_555 = F_16 ( F_267 ( V_113 ) ) ;
}
if ( F_52 ( V_2 ) <= 7 && ! F_259 ( V_2 ) )
error -> V_111 [ V_113 ] . V_1375 = F_16 ( F_276 ( V_113 ) ) ;
if ( F_52 ( V_2 ) >= 4 ) {
error -> V_111 [ V_113 ] . V_1376 = F_16 ( F_272 ( V_113 ) ) ;
error -> V_111 [ V_113 ] . V_1377 = F_16 ( F_274 ( V_113 ) ) ;
}
error -> V_75 [ V_113 ] . V_1378 = F_16 ( F_336 ( V_113 ) ) ;
if ( F_158 ( V_2 ) )
error -> V_75 [ V_113 ] . V_1379 = F_16 ( F_1034 ( V_113 ) ) ;
}
error -> V_1380 = F_180 ( V_2 ) -> V_639 ;
if ( F_14 ( V_2 ) )
error -> V_1380 ++ ;
for ( V_113 = 0 ; V_113 < error -> V_1380 ; V_113 ++ ) {
enum V_74 V_76 = V_1368 [ V_113 ] ;
error -> V_74 [ V_113 ] . V_1373 =
F_1033 ( V_2 ,
F_79 ( V_76 ) ) ;
if ( ! error -> V_74 [ V_113 ] . V_1373 )
continue;
error -> V_74 [ V_113 ] . V_76 = V_76 ;
error -> V_74 [ V_113 ] . V_1381 = F_16 ( F_53 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_766 = F_16 ( F_371 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_1382 = F_16 ( F_373 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_773 = F_16 ( F_375 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_769 = F_16 ( F_377 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_1139 = F_16 ( F_379 ( V_76 ) ) ;
error -> V_74 [ V_113 ] . V_1017 = F_16 ( F_381 ( V_76 ) ) ;
}
return error ;
}
void
F_1035 ( struct V_1383 * V_27 ,
struct V_1367 * error )
{
struct V_1 * V_2 = V_27 -> V_239 ;
int V_113 ;
if ( ! error )
return;
F_1036 ( V_27 , L_291 , F_180 ( V_2 ) -> V_639 ) ;
if ( F_259 ( V_2 ) || F_260 ( V_2 ) )
F_1036 ( V_27 , L_292 ,
error -> V_1372 ) ;
F_86 (dev_priv, i) {
F_1036 ( V_27 , L_293 , V_113 ) ;
F_1036 ( V_27 , L_294 ,
F_59 ( error -> V_75 [ V_113 ] . V_1373 ) ) ;
F_1036 ( V_27 , L_295 , error -> V_75 [ V_113 ] . V_1378 ) ;
F_1036 ( V_27 , L_296 , error -> V_75 [ V_113 ] . V_1379 ) ;
F_1036 ( V_27 , L_297 , V_113 ) ;
F_1036 ( V_27 , L_298 , error -> V_111 [ V_113 ] . V_599 ) ;
F_1036 ( V_27 , L_299 , error -> V_111 [ V_113 ] . V_287 ) ;
if ( F_52 ( V_2 ) <= 3 ) {
F_1036 ( V_27 , L_300 , error -> V_111 [ V_113 ] . V_221 ) ;
F_1036 ( V_27 , L_301 , error -> V_111 [ V_113 ] . V_555 ) ;
}
if ( F_52 ( V_2 ) <= 7 && ! F_259 ( V_2 ) )
F_1036 ( V_27 , L_302 , error -> V_111 [ V_113 ] . V_1375 ) ;
if ( F_52 ( V_2 ) >= 4 ) {
F_1036 ( V_27 , L_303 , error -> V_111 [ V_113 ] . V_1376 ) ;
F_1036 ( V_27 , L_304 , error -> V_111 [ V_113 ] . V_1377 ) ;
}
F_1036 ( V_27 , L_305 , V_113 ) ;
F_1036 ( V_27 , L_298 , error -> V_975 [ V_113 ] . V_599 ) ;
F_1036 ( V_27 , L_301 , error -> V_975 [ V_113 ] . V_1374 ) ;
F_1036 ( V_27 , L_306 , error -> V_975 [ V_113 ] . V_45 ) ;
}
for ( V_113 = 0 ; V_113 < error -> V_1380 ; V_113 ++ ) {
F_1036 ( V_27 , L_307 ,
F_735 ( error -> V_74 [ V_113 ] . V_76 ) ) ;
F_1036 ( V_27 , L_294 ,
F_59 ( error -> V_74 [ V_113 ] . V_1373 ) ) ;
F_1036 ( V_27 , L_308 , error -> V_74 [ V_113 ] . V_1381 ) ;
F_1036 ( V_27 , L_309 , error -> V_74 [ V_113 ] . V_766 ) ;
F_1036 ( V_27 , L_310 , error -> V_74 [ V_113 ] . V_1382 ) ;
F_1036 ( V_27 , L_311 , error -> V_74 [ V_113 ] . V_773 ) ;
F_1036 ( V_27 , L_312 , error -> V_74 [ V_113 ] . V_769 ) ;
F_1036 ( V_27 , L_313 , error -> V_74 [ V_113 ] . V_1139 ) ;
F_1036 ( V_27 , L_314 , error -> V_74 [ V_113 ] . V_1017 ) ;
}
}
