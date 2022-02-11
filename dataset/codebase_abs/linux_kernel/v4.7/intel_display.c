static int F_1 ( struct V_1 * V_2 )
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
static int F_8 ( struct V_1 * V_2 ,
const char * V_8 , T_1 V_9 )
{
if ( V_2 -> V_3 == 0 )
V_2 -> V_3 = F_1 ( V_2 ) ;
return F_5 ( V_2 , V_8 , V_9 ,
V_2 -> V_3 ) ;
}
static int
F_9 ( struct V_1 * V_2 )
{
return ( F_10 ( V_16 ) & V_17 ) * 1000 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , L_2 ,
V_18 ) ;
}
static int
F_12 ( struct V_1 * V_2 )
{
T_2 V_19 ;
V_19 = F_10 ( V_20 ) ;
switch ( V_19 & V_21 ) {
case V_22 :
return 100000 ;
case V_23 :
return 133333 ;
case V_24 :
return 166667 ;
case V_25 :
return 200000 ;
case V_26 :
return 266667 ;
case V_27 :
return 333333 ;
case V_28 :
case V_29 :
return 400000 ;
default:
return 133333 ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 ) )
V_2 -> V_30 = F_9 ( V_2 ) ;
else if ( F_15 ( V_2 ) || F_16 ( V_2 ) )
V_2 -> V_30 = F_11 ( V_2 ) ;
else if ( F_17 ( V_2 ) || F_18 ( V_2 ) )
V_2 -> V_30 = F_12 ( V_2 ) ;
else
return;
F_19 ( L_3 , V_2 -> V_30 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! ( F_15 ( V_2 ) || F_16 ( V_2 ) ) )
return;
V_2 -> V_31 = F_8 ( V_2 , L_4 ,
V_32 ) ;
F_19 ( L_5 , V_2 -> V_31 ) ;
}
static inline T_1
F_21 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
if ( F_22 ( V_2 ) )
return V_34 -> V_35 ;
else if ( F_23 ( V_2 ) )
return ( ( F_10 ( V_36 ) & V_37 ) + 2 ) * 10000 ;
else
return 270000 ;
}
static bool
F_24 ( struct V_38 * V_39 )
{
return F_25 ( V_39 ) ;
}
bool F_26 ( struct V_40 * V_41 , enum V_42 type )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_46 * V_47 ;
F_27 (dev, &crtc->base, encoder)
if ( V_47 -> type == type )
return true ;
return false ;
}
static bool F_28 ( const struct V_33 * V_48 ,
int type )
{
struct V_49 * V_39 = V_48 -> V_45 . V_39 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_46 * V_47 ;
int V_54 , V_55 = 0 ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != V_48 -> V_45 . V_41 )
continue;
V_55 ++ ;
V_47 = F_30 ( V_53 -> V_56 ) ;
if ( V_47 -> type == type )
return true ;
}
F_31 ( V_55 == 0 ) ;
return false ;
}
static int F_32 ( int V_57 , T_3 * clock )
{
clock -> V_58 = clock -> V_59 + 2 ;
clock -> V_60 = clock -> V_61 * clock -> V_62 ;
if ( F_31 ( clock -> V_63 == 0 || clock -> V_60 == 0 ) )
return 0 ;
clock -> V_64 = F_7 ( V_57 * clock -> V_58 , clock -> V_63 ) ;
clock -> V_65 = F_7 ( clock -> V_64 , clock -> V_60 ) ;
return clock -> V_65 ;
}
static T_2 F_33 ( struct V_66 * V_66 )
{
return 5 * ( V_66 -> V_67 + 2 ) + ( V_66 -> V_59 + 2 ) ;
}
static int F_34 ( int V_57 , T_3 * clock )
{
clock -> V_58 = F_33 ( clock ) ;
clock -> V_60 = clock -> V_61 * clock -> V_62 ;
if ( F_31 ( clock -> V_63 + 2 == 0 || clock -> V_60 == 0 ) )
return 0 ;
clock -> V_64 = F_7 ( V_57 * clock -> V_58 , clock -> V_63 + 2 ) ;
clock -> V_65 = F_7 ( clock -> V_64 , clock -> V_60 ) ;
return clock -> V_65 ;
}
static int F_35 ( int V_57 , T_3 * clock )
{
clock -> V_58 = clock -> V_67 * clock -> V_59 ;
clock -> V_60 = clock -> V_61 * clock -> V_62 ;
if ( F_31 ( clock -> V_63 == 0 || clock -> V_60 == 0 ) )
return 0 ;
clock -> V_64 = F_7 ( V_57 * clock -> V_58 , clock -> V_63 ) ;
clock -> V_65 = F_7 ( clock -> V_64 , clock -> V_60 ) ;
return clock -> V_65 / 5 ;
}
int F_36 ( int V_57 , T_3 * clock )
{
clock -> V_58 = clock -> V_67 * clock -> V_59 ;
clock -> V_60 = clock -> V_61 * clock -> V_62 ;
if ( F_31 ( clock -> V_63 == 0 || clock -> V_60 == 0 ) )
return 0 ;
clock -> V_64 = F_37 ( ( V_68 ) V_57 * clock -> V_58 ,
clock -> V_63 << 22 ) ;
clock -> V_65 = F_7 ( clock -> V_64 , clock -> V_60 ) ;
return clock -> V_65 / 5 ;
}
static bool F_38 ( struct V_43 * V_44 ,
const T_4 * V_69 ,
const T_3 * clock )
{
if ( clock -> V_63 < V_69 -> V_63 . V_70 || V_69 -> V_63 . V_71 < clock -> V_63 )
F_39 ( L_6 ) ;
if ( clock -> V_61 < V_69 -> V_61 . V_70 || V_69 -> V_61 . V_71 < clock -> V_61 )
F_39 ( L_7 ) ;
if ( clock -> V_59 < V_69 -> V_59 . V_70 || V_69 -> V_59 . V_71 < clock -> V_59 )
F_39 ( L_8 ) ;
if ( clock -> V_67 < V_69 -> V_67 . V_70 || V_69 -> V_67 . V_71 < clock -> V_67 )
F_39 ( L_9 ) ;
if ( ! F_18 ( V_44 ) && ! F_15 ( V_44 ) &&
! F_16 ( V_44 ) && ! F_40 ( V_44 ) )
if ( clock -> V_67 <= clock -> V_59 )
F_39 ( L_10 ) ;
if ( ! F_15 ( V_44 ) && ! F_16 ( V_44 ) && ! F_40 ( V_44 ) ) {
if ( clock -> V_60 < V_69 -> V_60 . V_70 || V_69 -> V_60 . V_71 < clock -> V_60 )
F_39 ( L_11 ) ;
if ( clock -> V_58 < V_69 -> V_58 . V_70 || V_69 -> V_58 . V_71 < clock -> V_58 )
F_39 ( L_12 ) ;
}
if ( clock -> V_64 < V_69 -> V_64 . V_70 || V_69 -> V_64 . V_71 < clock -> V_64 )
F_39 ( L_13 ) ;
if ( clock -> V_65 < V_69 -> V_65 . V_70 || V_69 -> V_65 . V_71 < clock -> V_65 )
F_39 ( L_14 ) ;
return true ;
}
static int
F_41 ( const T_4 * V_69 ,
const struct V_33 * V_48 ,
int V_72 )
{
struct V_43 * V_44 = V_48 -> V_45 . V_41 -> V_44 ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_42 ( V_44 ) )
return V_69 -> V_62 . V_74 ;
else
return V_69 -> V_62 . V_75 ;
} else {
if ( V_72 < V_69 -> V_62 . V_76 )
return V_69 -> V_62 . V_75 ;
else
return V_69 -> V_62 . V_74 ;
}
}
static bool
F_43 ( const T_4 * V_69 ,
struct V_33 * V_48 ,
int V_72 , int V_57 , T_3 * V_77 ,
T_3 * V_78 )
{
struct V_43 * V_44 = V_48 -> V_45 . V_41 -> V_44 ;
T_3 clock ;
int V_79 = V_72 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
clock . V_62 = F_41 ( V_69 , V_48 , V_72 ) ;
for ( clock . V_67 = V_69 -> V_67 . V_70 ; clock . V_67 <= V_69 -> V_67 . V_71 ;
clock . V_67 ++ ) {
for ( clock . V_59 = V_69 -> V_59 . V_70 ;
clock . V_59 <= V_69 -> V_59 . V_71 ; clock . V_59 ++ ) {
if ( clock . V_59 >= clock . V_67 )
break;
for ( clock . V_63 = V_69 -> V_63 . V_70 ;
clock . V_63 <= V_69 -> V_63 . V_71 ; clock . V_63 ++ ) {
for ( clock . V_61 = V_69 -> V_61 . V_70 ;
clock . V_61 <= V_69 -> V_61 . V_71 ; clock . V_61 ++ ) {
int V_80 ;
F_34 ( V_57 , & clock ) ;
if ( ! F_38 ( V_44 , V_69 ,
& clock ) )
continue;
if ( V_77 &&
clock . V_60 != V_77 -> V_60 )
continue;
V_80 = abs ( clock . V_65 - V_72 ) ;
if ( V_80 < V_79 ) {
* V_78 = clock ;
V_79 = V_80 ;
}
}
}
}
}
return ( V_79 != V_72 ) ;
}
static bool
F_44 ( const T_4 * V_69 ,
struct V_33 * V_48 ,
int V_72 , int V_57 , T_3 * V_77 ,
T_3 * V_78 )
{
struct V_43 * V_44 = V_48 -> V_45 . V_41 -> V_44 ;
T_3 clock ;
int V_79 = V_72 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
clock . V_62 = F_41 ( V_69 , V_48 , V_72 ) ;
for ( clock . V_67 = V_69 -> V_67 . V_70 ; clock . V_67 <= V_69 -> V_67 . V_71 ;
clock . V_67 ++ ) {
for ( clock . V_59 = V_69 -> V_59 . V_70 ;
clock . V_59 <= V_69 -> V_59 . V_71 ; clock . V_59 ++ ) {
for ( clock . V_63 = V_69 -> V_63 . V_70 ;
clock . V_63 <= V_69 -> V_63 . V_71 ; clock . V_63 ++ ) {
for ( clock . V_61 = V_69 -> V_61 . V_70 ;
clock . V_61 <= V_69 -> V_61 . V_71 ; clock . V_61 ++ ) {
int V_80 ;
F_32 ( V_57 , & clock ) ;
if ( ! F_38 ( V_44 , V_69 ,
& clock ) )
continue;
if ( V_77 &&
clock . V_60 != V_77 -> V_60 )
continue;
V_80 = abs ( clock . V_65 - V_72 ) ;
if ( V_80 < V_79 ) {
* V_78 = clock ;
V_79 = V_80 ;
}
}
}
}
}
return ( V_79 != V_72 ) ;
}
static bool
F_45 ( const T_4 * V_69 ,
struct V_33 * V_48 ,
int V_72 , int V_57 , T_3 * V_77 ,
T_3 * V_78 )
{
struct V_43 * V_44 = V_48 -> V_45 . V_41 -> V_44 ;
T_3 clock ;
int V_81 ;
bool V_82 = false ;
int V_83 = ( V_72 >> 8 ) + ( V_72 >> 9 ) ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
clock . V_62 = F_41 ( V_69 , V_48 , V_72 ) ;
V_81 = V_69 -> V_63 . V_71 ;
for ( clock . V_63 = V_69 -> V_63 . V_70 ; clock . V_63 <= V_81 ; clock . V_63 ++ ) {
for ( clock . V_67 = V_69 -> V_67 . V_71 ;
clock . V_67 >= V_69 -> V_67 . V_70 ; clock . V_67 -- ) {
for ( clock . V_59 = V_69 -> V_59 . V_71 ;
clock . V_59 >= V_69 -> V_59 . V_70 ; clock . V_59 -- ) {
for ( clock . V_61 = V_69 -> V_61 . V_71 ;
clock . V_61 >= V_69 -> V_61 . V_70 ; clock . V_61 -- ) {
int V_80 ;
F_34 ( V_57 , & clock ) ;
if ( ! F_38 ( V_44 , V_69 ,
& clock ) )
continue;
V_80 = abs ( clock . V_65 - V_72 ) ;
if ( V_80 < V_83 ) {
* V_78 = clock ;
V_83 = V_80 ;
V_81 = clock . V_63 ;
V_82 = true ;
}
}
}
}
}
return V_82 ;
}
static bool F_46 ( struct V_43 * V_44 , int V_84 ,
const T_3 * V_85 ,
const T_3 * V_78 ,
unsigned int V_86 ,
unsigned int * V_87 )
{
if ( F_16 ( V_44 ) ) {
* V_87 = 0 ;
return V_85 -> V_60 > V_78 -> V_60 ;
}
if ( F_47 ( ! V_84 ) )
return false ;
* V_87 = F_48 ( 1000000ULL *
abs ( V_84 - V_85 -> V_65 ) ,
V_84 ) ;
if ( * V_87 < 100 && V_85 -> V_60 > V_78 -> V_60 ) {
* V_87 = 0 ;
return true ;
}
return * V_87 + 10 < V_86 ;
}
static bool
F_49 ( const T_4 * V_69 ,
struct V_33 * V_48 ,
int V_72 , int V_57 , T_3 * V_77 ,
T_3 * V_78 )
{
struct V_40 * V_41 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
T_3 clock ;
unsigned int V_88 = 1000000 ;
int V_81 = V_70 ( V_69 -> V_63 . V_71 , V_57 / 19200 ) ;
bool V_82 = false ;
V_72 *= 5 ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
for ( clock . V_63 = V_69 -> V_63 . V_70 ; clock . V_63 <= V_81 ; clock . V_63 ++ ) {
for ( clock . V_61 = V_69 -> V_61 . V_71 ; clock . V_61 >= V_69 -> V_61 . V_70 ; clock . V_61 -- ) {
for ( clock . V_62 = V_69 -> V_62 . V_74 ; clock . V_62 >= V_69 -> V_62 . V_75 ;
clock . V_62 -= clock . V_62 > 10 ? 2 : 1 ) {
clock . V_60 = clock . V_61 * clock . V_62 ;
for ( clock . V_67 = V_69 -> V_67 . V_70 ; clock . V_67 <= V_69 -> V_67 . V_71 ; clock . V_67 ++ ) {
unsigned int V_89 ;
clock . V_59 = F_7 ( V_72 * clock . V_60 * clock . V_63 ,
V_57 * clock . V_67 ) ;
F_35 ( V_57 , & clock ) ;
if ( ! F_38 ( V_44 , V_69 ,
& clock ) )
continue;
if ( ! F_46 ( V_44 , V_72 ,
& clock ,
V_78 ,
V_88 , & V_89 ) )
continue;
* V_78 = clock ;
V_88 = V_89 ;
V_82 = true ;
}
}
}
}
return V_82 ;
}
static bool
F_51 ( const T_4 * V_69 ,
struct V_33 * V_48 ,
int V_72 , int V_57 , T_3 * V_77 ,
T_3 * V_78 )
{
struct V_40 * V_41 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
unsigned int V_86 ;
T_3 clock ;
V_68 V_59 ;
int V_82 = false ;
memset ( V_78 , 0 , sizeof( * V_78 ) ) ;
V_86 = 1000000 ;
clock . V_63 = 1 , clock . V_67 = 2 ;
V_72 *= 5 ;
for ( clock . V_61 = V_69 -> V_61 . V_71 ; clock . V_61 >= V_69 -> V_61 . V_70 ; clock . V_61 -- ) {
for ( clock . V_62 = V_69 -> V_62 . V_74 ;
clock . V_62 >= V_69 -> V_62 . V_75 ;
clock . V_62 -= clock . V_62 > 10 ? 2 : 1 ) {
unsigned int V_87 ;
clock . V_60 = clock . V_61 * clock . V_62 ;
V_59 = F_37 ( ( ( V_68 ) V_72 * clock . V_60 *
clock . V_63 ) << 22 , V_57 * clock . V_67 ) ;
if ( V_59 > V_90 / clock . V_67 )
continue;
clock . V_59 = V_59 ;
F_36 ( V_57 , & clock ) ;
if ( ! F_38 ( V_44 , V_69 , & clock ) )
continue;
if ( ! F_46 ( V_44 , V_72 , & clock , V_78 ,
V_86 , & V_87 ) )
continue;
* V_78 = clock ;
V_86 = V_87 ;
V_82 = true ;
}
}
return V_82 ;
}
bool F_52 ( struct V_33 * V_48 , int V_91 ,
T_3 * V_78 )
{
int V_57 = 100000 ;
const T_4 * V_69 = & V_92 ;
return F_51 ( V_69 , V_48 ,
V_91 , V_57 , NULL , V_78 ) ;
}
bool F_53 ( struct V_93 * V_41 )
{
struct V_40 * V_40 = F_50 ( V_41 ) ;
return V_40 -> V_94 && V_41 -> V_95 -> V_39 -> V_96 &&
V_40 -> V_97 -> V_45 . V_98 . V_99 ;
}
enum V_100 F_54 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
return V_40 -> V_97 -> V_103 ;
}
static bool F_55 ( struct V_43 * V_44 , enum V_101 V_101 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_5 V_9 = F_56 ( V_101 ) ;
T_1 V_105 , V_106 ;
T_1 V_107 ;
if ( F_57 ( V_44 ) )
V_107 = V_108 ;
else
V_107 = V_109 ;
V_105 = F_10 ( V_9 ) & V_107 ;
F_58 ( 5 ) ;
V_106 = F_10 ( V_9 ) & V_107 ;
return V_105 == V_106 ;
}
static void F_59 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_100 V_103 = V_41 -> V_97 -> V_103 ;
enum V_101 V_101 = V_41 -> V_101 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
T_5 V_9 = F_61 ( V_103 ) ;
if ( F_62 ( ( F_10 ( V_9 ) & V_111 ) == 0 ,
100 ) )
F_6 ( 1 , L_15 ) ;
} else {
if ( F_62 ( F_55 ( V_44 , V_101 ) , 100 ) )
F_6 ( 1 , L_15 ) ;
}
}
void F_63 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
T_1 V_11 ;
bool V_112 ;
V_11 = F_10 ( F_64 ( V_101 ) ) ;
V_112 = ! ! ( V_11 & V_113 ) ;
F_65 ( V_112 != V_39 ,
L_16 ,
F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
void F_67 ( struct V_1 * V_2 , bool V_39 )
{
T_1 V_11 ;
bool V_112 ;
F_2 ( & V_2 -> V_5 ) ;
V_11 = F_3 ( V_2 , V_114 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_112 = V_11 & V_115 ;
F_65 ( V_112 != V_39 ,
L_17 ,
F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
static void F_68 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
bool V_112 ;
enum V_100 V_103 = F_54 ( V_2 ,
V_101 ) ;
if ( F_22 ( V_2 ) ) {
T_1 V_11 = F_10 ( F_69 ( V_103 ) ) ;
V_112 = ! ! ( V_11 & V_116 ) ;
} else {
T_1 V_11 = F_10 ( F_70 ( V_101 ) ) ;
V_112 = ! ! ( V_11 & V_117 ) ;
}
F_65 ( V_112 != V_39 ,
L_18 ,
F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
static void F_71 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
T_1 V_11 ;
bool V_112 ;
V_11 = F_10 ( F_72 ( V_101 ) ) ;
V_112 = ! ! ( V_11 & V_118 ) ;
F_65 ( V_112 != V_39 ,
L_19 ,
F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
static void F_73 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
T_1 V_11 ;
if ( F_60 ( V_2 ) -> V_110 == 5 )
return;
if ( F_22 ( V_2 ) )
return;
V_11 = F_10 ( F_70 ( V_101 ) ) ;
F_65 ( ! ( V_11 & V_119 ) , L_20 ) ;
}
void F_74 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
T_1 V_11 ;
bool V_112 ;
V_11 = F_10 ( F_72 ( V_101 ) ) ;
V_112 = ! ! ( V_11 & V_120 ) ;
F_65 ( V_112 != V_39 ,
L_21 ,
F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
void F_75 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
T_5 V_121 ;
T_1 V_11 ;
enum V_101 V_122 = V_123 ;
bool V_124 = true ;
if ( F_31 ( F_22 ( V_44 ) ) )
return;
if ( F_14 ( V_44 ) ) {
T_1 V_125 ;
V_121 = V_126 ;
V_125 = F_10 ( V_127 ) & V_128 ;
if ( V_125 == V_129 &&
F_10 ( V_130 ) & V_131 )
V_122 = V_132 ;
} else if ( F_15 ( V_44 ) || F_16 ( V_44 ) ) {
V_121 = F_76 ( V_101 ) ;
V_122 = V_101 ;
} else {
V_121 = V_133 ;
if ( F_10 ( V_134 ) & V_131 )
V_122 = V_132 ;
}
V_11 = F_10 ( V_121 ) ;
if ( ! ( V_11 & V_135 ) ||
( ( V_11 & V_136 ) == V_137 ) )
V_124 = false ;
F_65 ( V_122 == V_101 && V_124 ,
L_22 ,
F_77 ( V_101 ) ) ;
}
static void F_78 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
bool V_112 ;
if ( F_79 ( V_44 ) || F_80 ( V_44 ) )
V_112 = F_10 ( F_81 ( V_123 ) ) & V_138 ;
else
V_112 = F_10 ( F_81 ( V_101 ) ) & V_139 ;
F_65 ( V_112 != V_39 ,
L_23 ,
F_77 ( V_101 ) , F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
void F_82 ( struct V_1 * V_2 ,
enum V_101 V_101 , bool V_39 )
{
bool V_112 ;
enum V_100 V_103 = F_54 ( V_2 ,
V_101 ) ;
enum V_140 V_141 ;
if ( ( V_101 == V_123 && V_2 -> V_142 & V_143 ) ||
( V_101 == V_132 && V_2 -> V_142 & V_144 ) )
V_39 = true ;
V_141 = F_83 ( V_103 ) ;
if ( F_84 ( V_2 , V_141 ) ) {
T_1 V_11 = F_10 ( F_61 ( V_103 ) ) ;
V_112 = ! ! ( V_11 & V_145 ) ;
F_85 ( V_2 , V_141 ) ;
} else {
V_112 = false ;
}
F_65 ( V_112 != V_39 ,
L_24 ,
F_77 ( V_101 ) , F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
static void F_86 ( struct V_1 * V_2 ,
enum V_146 V_146 , bool V_39 )
{
T_1 V_11 ;
bool V_112 ;
V_11 = F_10 ( F_87 ( V_146 ) ) ;
V_112 = ! ! ( V_11 & V_147 ) ;
F_65 ( V_112 != V_39 ,
L_25 ,
F_88 ( V_146 ) , F_66 ( V_39 ) , F_66 ( V_112 ) ) ;
}
static void F_89 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
int V_54 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
T_1 V_11 = F_10 ( F_87 ( V_101 ) ) ;
F_65 ( V_11 & V_147 ,
L_26 ,
F_88 ( V_101 ) ) ;
return;
}
F_90 (dev_priv, i) {
T_1 V_11 = F_10 ( F_87 ( V_54 ) ) ;
enum V_101 V_148 = ( V_11 & V_149 ) >>
V_150 ;
F_65 ( ( V_11 & V_147 ) && V_101 == V_148 ,
L_27 ,
F_88 ( V_54 ) , F_77 ( V_101 ) ) ;
}
}
static void F_91 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
int V_151 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
F_92 (dev_priv, pipe, sprite) {
T_1 V_11 = F_10 ( F_93 ( V_101 , V_151 ) ) ;
F_65 ( V_11 & V_152 ,
L_28 ,
V_151 , F_77 ( V_101 ) ) ;
}
} else if ( F_15 ( V_44 ) || F_16 ( V_44 ) ) {
F_92 (dev_priv, pipe, sprite) {
T_1 V_11 = F_10 ( F_94 ( V_101 , V_151 ) ) ;
F_65 ( V_11 & V_153 ,
L_29 ,
F_95 ( V_101 , V_151 ) , F_77 ( V_101 ) ) ;
}
} else if ( F_60 ( V_44 ) -> V_110 >= 7 ) {
T_1 V_11 = F_10 ( F_96 ( V_101 ) ) ;
F_65 ( V_11 & V_154 ,
L_29 ,
F_88 ( V_101 ) , F_77 ( V_101 ) ) ;
} else if ( F_60 ( V_44 ) -> V_110 >= 5 ) {
T_1 V_11 = F_10 ( F_97 ( V_101 ) ) ;
F_65 ( V_11 & V_155 ,
L_29 ,
F_88 ( V_101 ) , F_77 ( V_101 ) ) ;
}
}
static void F_98 ( struct V_93 * V_41 )
{
if ( F_99 ( F_100 ( V_41 ) == 0 ) )
F_101 ( V_41 ) ;
}
void F_102 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
T_1 V_11 ;
bool V_156 ;
V_11 = F_10 ( F_103 ( V_101 ) ) ;
V_156 = ! ! ( V_11 & V_157 ) ;
F_65 ( V_156 ,
L_30 ,
F_77 ( V_101 ) ) ;
}
static bool F_104 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_1 V_125 , T_1 V_11 )
{
if ( ( V_11 & V_158 ) == 0 )
return false ;
if ( F_105 ( V_2 ) ) {
T_1 V_159 = F_10 ( F_106 ( V_101 ) ) ;
if ( ( V_159 & V_160 ) != V_125 )
return false ;
} else if ( F_16 ( V_2 ) ) {
if ( ( V_11 & V_161 ) != F_107 ( V_101 ) )
return false ;
} else {
if ( ( V_11 & V_162 ) != ( V_101 << 30 ) )
return false ;
}
return true ;
}
static bool F_108 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_1 V_11 )
{
if ( ( V_11 & V_163 ) == 0 )
return false ;
if ( F_105 ( V_2 ) ) {
if ( ( V_11 & V_164 ) != F_109 ( V_101 ) )
return false ;
} else if ( F_16 ( V_2 ) ) {
if ( ( V_11 & V_165 ) != F_110 ( V_101 ) )
return false ;
} else {
if ( ( V_11 & V_166 ) != F_111 ( V_101 ) )
return false ;
}
return true ;
}
static bool F_112 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_1 V_11 )
{
if ( ( V_11 & V_167 ) == 0 )
return false ;
if ( F_105 ( V_2 ) ) {
if ( ( V_11 & V_168 ) != F_113 ( V_101 ) )
return false ;
} else {
if ( ( V_11 & V_169 ) != F_114 ( V_101 ) )
return false ;
}
return true ;
}
static bool F_115 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_1 V_11 )
{
if ( ( V_11 & V_170 ) == 0 )
return false ;
if ( F_105 ( V_2 ) ) {
if ( ( V_11 & V_168 ) != F_113 ( V_101 ) )
return false ;
} else {
if ( ( V_11 & V_171 ) != F_116 ( V_101 ) )
return false ;
}
return true ;
}
static void F_117 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_5 V_9 ,
T_1 V_125 )
{
T_1 V_11 = F_10 ( V_9 ) ;
F_65 ( F_104 ( V_2 , V_101 , V_125 , V_11 ) ,
L_31 ,
F_118 ( V_9 ) , F_77 ( V_101 ) ) ;
F_65 ( F_119 ( V_2 ) && ( V_11 & V_158 ) == 0
&& ( V_11 & V_172 ) ,
L_32 ) ;
}
static void F_120 ( struct V_1 * V_2 ,
enum V_101 V_101 , T_5 V_9 )
{
T_1 V_11 = F_10 ( V_9 ) ;
F_65 ( F_108 ( V_2 , V_101 , V_11 ) ,
L_33 ,
F_118 ( V_9 ) , F_77 ( V_101 ) ) ;
F_65 ( F_119 ( V_2 ) && ( V_11 & V_163 ) == 0
&& ( V_11 & V_173 ) ,
L_34 ) ;
}
static void F_121 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
T_1 V_11 ;
F_117 ( V_2 , V_101 , V_174 , V_175 ) ;
F_117 ( V_2 , V_101 , V_176 , V_177 ) ;
F_117 ( V_2 , V_101 , V_178 , V_179 ) ;
V_11 = F_10 ( V_180 ) ;
F_65 ( F_115 ( V_2 , V_101 , V_11 ) ,
L_35 ,
F_77 ( V_101 ) ) ;
V_11 = F_10 ( V_130 ) ;
F_65 ( F_112 ( V_2 , V_101 , V_11 ) ,
L_36 ,
F_77 ( V_101 ) ) ;
F_120 ( V_2 , V_101 , V_181 ) ;
F_120 ( V_2 , V_101 , V_182 ) ;
F_120 ( V_2 , V_101 , V_183 ) ;
}
static void F_122 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
enum V_101 V_101 = V_41 -> V_101 ;
F_124 ( F_64 ( V_101 ) , V_34 -> V_184 . V_66 ) ;
F_125 ( F_64 ( V_101 ) ) ;
F_126 ( 150 ) ;
if ( F_62 ( ( ( F_10 ( F_64 ( V_101 ) ) & V_185 ) == V_185 ) , 1 ) )
F_127 ( L_37 , V_101 ) ;
}
static void F_128 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
enum V_101 V_101 = V_41 -> V_101 ;
F_129 ( V_2 , V_101 ) ;
F_75 ( V_2 , V_101 ) ;
if ( V_34 -> V_184 . V_66 & V_113 )
F_122 ( V_41 , V_34 ) ;
F_124 ( F_130 ( V_101 ) , V_34 -> V_184 . V_186 ) ;
F_125 ( F_130 ( V_101 ) ) ;
}
static void F_131 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
enum V_101 V_101 = V_41 -> V_101 ;
enum V_187 V_188 = F_132 ( V_101 ) ;
T_1 V_189 ;
F_2 ( & V_2 -> V_5 ) ;
V_189 = F_133 ( V_2 , V_101 , F_134 ( V_188 ) ) ;
V_189 |= V_190 ;
F_135 ( V_2 , V_101 , F_134 ( V_188 ) , V_189 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_126 ( 1 ) ;
F_124 ( F_64 ( V_101 ) , V_34 -> V_184 . V_66 ) ;
if ( F_62 ( ( ( F_10 ( F_64 ( V_101 ) ) & V_185 ) == V_185 ) , 1 ) )
F_127 ( L_38 , V_101 ) ;
}
static void F_136 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
enum V_101 V_101 = V_41 -> V_101 ;
F_129 ( V_2 , V_101 ) ;
F_75 ( V_2 , V_101 ) ;
if ( V_34 -> V_184 . V_66 & V_113 )
F_131 ( V_41 , V_34 ) ;
if ( V_101 != V_123 ) {
F_124 ( V_191 , V_101 == V_132 ? V_192 : V_193 ) ;
F_124 ( F_130 ( V_132 ) , V_34 -> V_184 . V_186 ) ;
F_124 ( V_191 , 0 ) ;
V_2 -> V_194 [ V_101 ] = V_34 -> V_184 . V_186 ;
F_31 ( ( F_10 ( F_64 ( V_132 ) ) & V_195 ) == 0 ) ;
} else {
F_124 ( F_130 ( V_101 ) , V_34 -> V_184 . V_186 ) ;
F_125 ( F_130 ( V_101 ) ) ;
}
}
static int F_137 ( struct V_43 * V_44 )
{
struct V_40 * V_41 ;
int V_196 = 0 ;
F_138 (dev, crtc)
V_196 += V_41 -> V_45 . V_39 -> V_94 &&
F_26 ( V_41 , V_197 ) ;
return V_196 ;
}
static void F_139 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_5 V_9 = F_64 ( V_41 -> V_101 ) ;
T_1 V_66 = V_41 -> V_97 -> V_184 . V_66 ;
F_129 ( V_2 , V_41 -> V_101 ) ;
if ( F_140 ( V_44 ) && ! F_141 ( V_44 ) )
F_75 ( V_2 , V_41 -> V_101 ) ;
if ( F_141 ( V_44 ) && F_137 ( V_44 ) > 0 ) {
V_66 |= V_198 ;
F_124 ( F_64 ( ! V_41 -> V_101 ) ,
F_10 ( F_64 ( ! V_41 -> V_101 ) ) | V_198 ) ;
}
F_124 ( V_9 , 0 ) ;
F_124 ( V_9 , V_66 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
F_124 ( F_130 ( V_41 -> V_101 ) ,
V_41 -> V_97 -> V_184 . V_186 ) ;
} else {
F_124 ( V_9 , V_66 ) ;
}
F_124 ( V_9 , V_66 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
F_124 ( V_9 , V_66 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
F_124 ( V_9 , V_66 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
}
static void F_142 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
if ( F_141 ( V_44 ) &&
F_26 ( V_41 , V_197 ) &&
! F_137 ( V_44 ) ) {
F_124 ( F_64 ( V_132 ) ,
F_10 ( F_64 ( V_132 ) ) & ~ V_198 ) ;
F_124 ( F_64 ( V_123 ) ,
F_10 ( F_64 ( V_123 ) ) & ~ V_198 ) ;
}
if ( ( V_101 == V_123 && V_2 -> V_142 & V_143 ) ||
( V_101 == V_132 && V_2 -> V_142 & V_144 ) )
return;
F_129 ( V_2 , V_101 ) ;
F_124 ( F_64 ( V_101 ) , V_195 ) ;
F_125 ( F_64 ( V_101 ) ) ;
}
static void F_143 ( struct V_1 * V_2 , enum V_101 V_101 )
{
T_1 V_11 ;
F_129 ( V_2 , V_101 ) ;
V_11 = V_199 |
V_200 | V_195 ;
if ( V_101 != V_123 )
V_11 |= V_201 ;
F_124 ( F_64 ( V_101 ) , V_11 ) ;
F_125 ( F_64 ( V_101 ) ) ;
}
static void F_144 ( struct V_1 * V_2 , enum V_101 V_101 )
{
enum V_187 V_188 = F_132 ( V_101 ) ;
T_1 V_11 ;
F_129 ( V_2 , V_101 ) ;
V_11 = V_202 |
V_200 | V_195 ;
if ( V_101 != V_123 )
V_11 |= V_201 ;
F_124 ( F_64 ( V_101 ) , V_11 ) ;
F_125 ( F_64 ( V_101 ) ) ;
F_2 ( & V_2 -> V_5 ) ;
V_11 = F_133 ( V_2 , V_101 , F_134 ( V_188 ) ) ;
V_11 &= ~ V_190 ;
F_135 ( V_2 , V_101 , F_134 ( V_188 ) , V_11 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
void F_145 ( struct V_1 * V_2 ,
struct V_203 * V_204 ,
unsigned int V_205 )
{
T_1 V_206 ;
T_5 V_207 ;
switch ( V_204 -> V_188 ) {
case V_208 :
V_206 = V_209 ;
V_207 = F_64 ( 0 ) ;
break;
case V_210 :
V_206 = V_211 ;
V_207 = F_64 ( 0 ) ;
V_205 <<= 4 ;
break;
case V_212 :
V_206 = V_213 ;
V_207 = V_214 ;
break;
default:
F_146 () ;
}
if ( F_62 ( ( F_10 ( V_207 ) & V_206 ) == V_205 , 1000 ) )
F_6 ( 1 , L_39 ,
F_147 ( V_204 -> V_188 ) , F_10 ( V_207 ) & V_206 , V_205 ) ;
}
static void F_148 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_5 V_9 ;
T_2 V_11 , V_215 ;
F_149 ( V_2 , V_40 -> V_97 -> V_216 ) ;
F_150 ( V_2 , V_101 ) ;
F_151 ( V_2 , V_101 ) ;
if ( F_105 ( V_44 ) ) {
V_9 = F_152 ( V_101 ) ;
V_11 = F_10 ( V_9 ) ;
V_11 |= V_217 ;
F_124 ( V_9 , V_11 ) ;
}
V_9 = F_103 ( V_101 ) ;
V_11 = F_10 ( V_9 ) ;
V_215 = F_10 ( F_61 ( V_101 ) ) ;
if ( F_119 ( V_2 ) ) {
V_11 &= ~ V_218 ;
if ( F_26 ( V_40 , V_219 ) )
V_11 |= V_220 ;
else
V_11 |= V_215 & V_218 ;
}
V_11 &= ~ V_221 ;
if ( ( V_215 & V_222 ) == V_223 )
if ( F_119 ( V_2 ) &&
F_26 ( V_40 , V_224 ) )
V_11 |= V_225 ;
else
V_11 |= V_226 ;
else
V_11 |= V_227 ;
F_124 ( V_9 , V_11 | V_157 ) ;
if ( F_62 ( F_10 ( V_9 ) & V_228 , 100 ) )
F_127 ( L_40 , F_77 ( V_101 ) ) ;
}
static void F_153 ( struct V_1 * V_2 ,
enum V_100 V_103 )
{
T_1 V_11 , V_215 ;
F_150 ( V_2 , (enum V_101 ) V_103 ) ;
F_151 ( V_2 , V_229 ) ;
V_11 = F_10 ( F_152 ( V_123 ) ) ;
V_11 |= V_217 ;
F_124 ( F_152 ( V_123 ) , V_11 ) ;
V_11 = V_157 ;
V_215 = F_10 ( F_61 ( V_103 ) ) ;
if ( ( V_215 & V_230 ) ==
V_223 )
V_11 |= V_226 ;
else
V_11 |= V_227 ;
F_124 ( V_231 , V_11 ) ;
if ( F_62 ( F_10 ( V_231 ) & V_228 , 100 ) )
F_127 ( L_41 ) ;
}
static void F_154 ( struct V_1 * V_2 ,
enum V_101 V_101 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
T_5 V_9 ;
T_2 V_11 ;
F_155 ( V_2 , V_101 ) ;
F_156 ( V_2 , V_101 ) ;
F_121 ( V_2 , V_101 ) ;
V_9 = F_103 ( V_101 ) ;
V_11 = F_10 ( V_9 ) ;
V_11 &= ~ V_157 ;
F_124 ( V_9 , V_11 ) ;
if ( F_62 ( ( F_10 ( V_9 ) & V_228 ) == 0 , 50 ) )
F_127 ( L_42 , F_77 ( V_101 ) ) ;
if ( F_105 ( V_44 ) ) {
V_9 = F_152 ( V_101 ) ;
V_11 = F_10 ( V_9 ) ;
V_11 &= ~ V_217 ;
F_124 ( V_9 , V_11 ) ;
}
}
static void F_157 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_10 ( V_231 ) ;
V_11 &= ~ V_157 ;
F_124 ( V_231 , V_11 ) ;
if ( F_62 ( ( F_10 ( V_231 ) & V_228 ) == 0 , 50 ) )
F_127 ( L_43 ) ;
V_11 = F_10 ( F_152 ( V_123 ) ) ;
V_11 &= ~ V_217 ;
F_124 ( F_152 ( V_123 ) , V_11 ) ;
}
static void F_158 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
enum V_100 V_103 = V_41 -> V_97 -> V_103 ;
enum V_101 V_232 ;
T_5 V_9 ;
T_1 V_11 ;
F_159 ( L_44 , F_77 ( V_101 ) ) ;
F_89 ( V_2 , V_101 ) ;
F_160 ( V_2 , V_101 ) ;
F_91 ( V_2 , V_101 ) ;
if ( F_161 ( V_2 ) )
V_232 = V_229 ;
else
V_232 = V_101 ;
if ( F_162 ( V_2 ) )
if ( V_41 -> V_97 -> V_233 )
F_163 ( V_2 ) ;
else
F_164 ( V_2 , V_101 ) ;
else {
if ( V_41 -> V_97 -> V_234 ) {
F_165 ( V_2 , V_232 ) ;
F_73 ( V_2 ,
(enum V_101 ) V_103 ) ;
}
}
V_9 = F_61 ( V_103 ) ;
V_11 = F_10 ( V_9 ) ;
if ( V_11 & V_145 ) {
F_31 ( ! ( ( V_101 == V_123 && V_2 -> V_142 & V_143 ) ||
( V_101 == V_132 && V_2 -> V_142 & V_144 ) ) ) ;
return;
}
F_124 ( V_9 , V_11 | V_145 ) ;
F_125 ( V_9 ) ;
if ( V_44 -> V_235 == 0 &&
F_62 ( F_166 ( V_41 ) != V_41 -> V_236 , 50 ) )
F_127 ( L_45 , F_77 ( V_101 ) ) ;
}
static void F_167 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_45 . V_44 -> V_104 ;
enum V_100 V_103 = V_41 -> V_97 -> V_103 ;
enum V_101 V_101 = V_41 -> V_101 ;
T_5 V_9 ;
T_1 V_11 ;
F_159 ( L_46 , F_77 ( V_101 ) ) ;
F_89 ( V_2 , V_101 ) ;
F_160 ( V_2 , V_101 ) ;
F_91 ( V_2 , V_101 ) ;
V_9 = F_61 ( V_103 ) ;
V_11 = F_10 ( V_9 ) ;
if ( ( V_11 & V_145 ) == 0 )
return;
if ( V_41 -> V_97 -> V_237 )
V_11 &= ~ V_238 ;
if ( ! ( V_101 == V_123 && V_2 -> V_142 & V_143 ) &&
! ( V_101 == V_132 && V_2 -> V_142 & V_144 ) )
V_11 &= ~ V_145 ;
F_124 ( V_9 , V_11 ) ;
if ( ( V_11 & V_145 ) == 0 )
F_59 ( V_41 ) ;
}
static bool F_168 ( struct V_43 * V_44 )
{
#ifdef F_169
if ( F_60 ( V_44 ) -> V_110 >= 6 && V_239 )
return true ;
#endif
return false ;
}
static unsigned int F_170 ( const struct V_1 * V_2 )
{
return F_57 ( V_2 ) ? 2048 : 4096 ;
}
static unsigned int F_171 ( const struct V_1 * V_2 ,
V_68 V_240 , unsigned int V_241 )
{
switch ( V_240 ) {
case V_242 :
return V_241 ;
case V_243 :
if ( F_57 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_244 :
if ( F_57 ( V_2 ) || F_172 ( V_2 ) )
return 128 ;
else
return 512 ;
case V_245 :
switch ( V_241 ) {
case 1 :
return 64 ;
case 2 :
case 4 :
return 128 ;
case 8 :
case 16 :
return 256 ;
default:
F_173 ( V_241 ) ;
return V_241 ;
}
break;
default:
F_173 ( V_240 ) ;
return V_241 ;
}
}
unsigned int F_174 ( const struct V_1 * V_2 ,
V_68 V_240 , unsigned int V_241 )
{
if ( V_240 == V_242 )
return 1 ;
else
return F_170 ( V_2 ) /
F_171 ( V_2 , V_240 , V_241 ) ;
}
static void F_175 ( const struct V_1 * V_2 ,
unsigned int * V_246 ,
unsigned int * V_247 ,
V_68 V_240 ,
unsigned int V_241 )
{
unsigned int V_248 =
F_171 ( V_2 , V_240 , V_241 ) ;
* V_246 = V_248 / V_241 ;
* V_247 = F_170 ( V_2 ) / V_248 ;
}
unsigned int
F_176 ( struct V_43 * V_44 , unsigned int V_249 ,
T_2 V_250 , V_68 V_240 )
{
unsigned int V_241 = F_177 ( V_250 , 0 ) ;
unsigned int V_247 = F_174 ( F_123 ( V_44 ) , V_240 , V_241 ) ;
return F_178 ( V_249 , V_247 ) ;
}
unsigned int F_179 ( const struct V_251 * V_252 )
{
unsigned int V_253 = 0 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_180 ( V_252 -> V_146 ) ; V_54 ++ )
V_253 += V_252 -> V_146 [ V_54 ] . V_254 * V_252 -> V_146 [ V_54 ] . V_249 ;
return V_253 ;
}
static void
F_181 ( struct V_255 * V_256 ,
const struct V_257 * V_96 ,
unsigned int V_258 )
{
if ( F_182 ( V_258 ) ) {
* V_256 = V_259 ;
V_256 -> V_260 . V_261 = F_183 ( V_96 ) -> V_252 ;
} else {
* V_256 = V_262 ;
}
}
static void
F_184 ( struct V_1 * V_2 ,
struct V_257 * V_96 )
{
struct V_251 * V_263 = & F_183 ( V_96 ) -> V_252 ;
unsigned int V_264 , V_246 , V_247 , V_241 ;
V_264 = F_170 ( V_2 ) ;
V_241 = F_177 ( V_96 -> V_250 , 0 ) ;
F_175 ( V_2 , & V_246 , & V_247 ,
V_96 -> V_265 [ 0 ] , V_241 ) ;
V_263 -> V_146 [ 0 ] . V_254 = F_185 ( V_96 -> V_266 [ 0 ] , V_246 * V_241 ) ;
V_263 -> V_146 [ 0 ] . V_249 = F_185 ( V_96 -> V_249 , V_247 ) ;
if ( V_263 -> V_250 == V_267 ) {
V_241 = F_177 ( V_96 -> V_250 , 1 ) ;
F_175 ( V_2 , & V_246 , & V_247 ,
V_96 -> V_265 [ 1 ] , V_241 ) ;
V_263 -> V_268 = V_96 -> V_269 [ 1 ] ;
V_263 -> V_146 [ 1 ] . V_254 = F_185 ( V_96 -> V_266 [ 1 ] , V_246 * V_241 ) ;
V_263 -> V_146 [ 1 ] . V_249 = F_185 ( V_96 -> V_249 / 2 , V_247 ) ;
}
}
static unsigned int F_186 ( const struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) -> V_110 >= 9 )
return 256 * 1024 ;
else if ( F_187 ( V_2 ) || F_188 ( V_2 ) ||
F_15 ( V_2 ) || F_16 ( V_2 ) )
return 128 * 1024 ;
else if ( F_60 ( V_2 ) -> V_110 >= 4 )
return 4 * 1024 ;
else
return 0 ;
}
static unsigned int F_189 ( const struct V_1 * V_2 ,
V_68 V_240 )
{
switch ( V_240 ) {
case V_242 :
return F_186 ( V_2 ) ;
case V_243 :
if ( F_60 ( V_2 ) -> V_110 >= 9 )
return 256 * 1024 ;
return 0 ;
case V_244 :
case V_245 :
return 1 * 1024 * 1024 ;
default:
F_173 ( V_240 ) ;
return 0 ;
}
}
int
F_190 ( struct V_257 * V_96 ,
unsigned int V_258 )
{
struct V_43 * V_44 = V_96 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
struct V_255 V_256 ;
T_1 V_272 ;
int V_273 ;
F_31 ( ! F_192 ( & V_44 -> V_274 ) ) ;
V_272 = F_189 ( V_2 , V_96 -> V_265 [ 0 ] ) ;
F_181 ( & V_256 , V_96 , V_258 ) ;
if ( F_168 ( V_44 ) && V_272 < 256 * 1024 )
V_272 = 256 * 1024 ;
F_193 ( V_2 ) ;
V_273 = F_194 ( V_271 , V_272 ,
& V_256 ) ;
if ( V_273 )
goto V_275;
if ( V_256 . type == V_276 ) {
V_273 = F_195 ( V_271 ) ;
if ( V_273 == - V_277 ) {
V_273 = - V_278 ;
goto V_279;
} else if ( V_273 )
goto V_279;
F_196 ( V_271 ) ;
}
F_197 ( V_2 ) ;
return 0 ;
V_279:
F_198 ( V_271 , & V_256 ) ;
V_275:
F_197 ( V_2 ) ;
return V_273 ;
}
static void F_199 ( struct V_257 * V_96 , unsigned int V_258 )
{
struct V_270 * V_271 = F_191 ( V_96 ) ;
struct V_255 V_256 ;
F_31 ( ! F_192 ( & V_271 -> V_45 . V_44 -> V_274 ) ) ;
F_181 ( & V_256 , V_96 , V_258 ) ;
if ( V_256 . type == V_276 )
F_200 ( V_271 ) ;
F_198 ( V_271 , & V_256 ) ;
}
static T_1 F_201 ( int * V_280 , int * V_281 ,
unsigned int V_246 ,
unsigned int V_247 ,
unsigned int V_264 ,
unsigned int V_282 ,
T_1 V_283 ,
T_1 V_284 )
{
unsigned int V_285 ;
F_31 ( V_283 & ( V_264 - 1 ) ) ;
F_31 ( V_284 & ( V_264 - 1 ) ) ;
F_31 ( V_284 > V_283 ) ;
V_285 = ( V_283 - V_284 ) / V_264 ;
* V_281 += V_285 / V_282 * V_247 ;
* V_280 += V_285 % V_282 * V_246 ;
return V_284 ;
}
T_1 F_202 ( int * V_280 , int * V_281 ,
const struct V_257 * V_96 , int V_146 ,
unsigned int V_286 ,
unsigned int V_258 )
{
const struct V_1 * V_2 = F_123 ( V_96 -> V_44 ) ;
V_68 V_240 = V_96 -> V_265 [ V_146 ] ;
unsigned int V_241 = F_177 ( V_96 -> V_250 , V_146 ) ;
T_1 V_287 , V_288 , V_272 ;
V_272 = F_189 ( V_2 , V_240 ) ;
if ( V_272 )
V_272 -- ;
if ( V_240 != V_242 ) {
unsigned int V_264 , V_246 , V_247 ;
unsigned int V_289 , V_285 , V_282 ;
V_264 = F_170 ( V_2 ) ;
F_175 ( V_2 , & V_246 , & V_247 ,
V_240 , V_241 ) ;
if ( F_182 ( V_258 ) ) {
V_282 = V_286 / V_247 ;
F_203 ( V_246 , V_247 ) ;
} else {
V_282 = V_286 / ( V_246 * V_241 ) ;
}
V_289 = * V_281 / V_247 ;
* V_281 %= V_247 ;
V_285 = * V_280 / V_246 ;
* V_280 %= V_246 ;
V_287 = ( V_289 * V_282 + V_285 ) * V_264 ;
V_288 = V_287 & ~ V_272 ;
F_201 ( V_280 , V_281 , V_246 , V_247 ,
V_264 , V_282 ,
V_287 , V_288 ) ;
} else {
V_287 = * V_281 * V_286 + * V_280 * V_241 ;
V_288 = V_287 & ~ V_272 ;
* V_281 = ( V_287 & V_272 ) / V_286 ;
* V_280 = ( ( V_287 & V_272 ) - * V_281 * V_286 ) / V_241 ;
}
return V_288 ;
}
static int F_204 ( int V_290 )
{
switch ( V_290 ) {
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
case V_295 :
return V_296 ;
default:
case V_297 :
return V_298 ;
case V_299 :
return V_300 ;
case V_301 :
return V_302 ;
case V_303 :
return V_304 ;
}
}
static int F_205 ( int V_290 , bool V_305 , bool V_306 )
{
switch ( V_290 ) {
case V_307 :
return V_296 ;
default:
case V_308 :
if ( V_305 ) {
if ( V_306 )
return V_309 ;
else
return V_300 ;
} else {
if ( V_306 )
return V_310 ;
else
return V_298 ;
}
case V_311 :
if ( V_305 )
return V_304 ;
else
return V_302 ;
}
}
static bool
F_206 ( struct V_40 * V_41 ,
struct V_312 * V_313 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_314 * V_315 = & V_2 -> V_315 ;
struct V_270 * V_271 = NULL ;
struct V_316 V_317 = { 0 } ;
struct V_257 * V_96 = & V_313 -> V_96 -> V_45 ;
T_1 V_318 = F_207 ( V_313 -> V_45 , V_319 ) ;
T_1 V_320 = F_208 ( V_313 -> V_45 + V_313 -> V_253 ,
V_319 ) ;
V_320 -= V_318 ;
if ( V_313 -> V_253 == 0 )
return false ;
if ( V_320 * 2 > V_315 -> V_321 )
return false ;
F_2 ( & V_44 -> V_274 ) ;
V_271 = F_209 ( V_44 ,
V_318 ,
V_318 ,
V_320 ) ;
if ( ! V_271 ) {
F_4 ( & V_44 -> V_274 ) ;
return false ;
}
V_271 -> V_322 = V_313 -> V_323 ;
if ( V_271 -> V_322 == V_324 )
V_271 -> V_325 = V_96 -> V_266 [ 0 ] ;
V_317 . V_250 = V_96 -> V_250 ;
V_317 . V_254 = V_96 -> V_254 ;
V_317 . V_249 = V_96 -> V_249 ;
V_317 . V_266 [ 0 ] = V_96 -> V_266 [ 0 ] ;
V_317 . V_265 [ 0 ] = V_96 -> V_265 [ 0 ] ;
V_317 . V_326 = V_327 ;
if ( F_210 ( V_44 , F_183 ( V_96 ) ,
& V_317 , V_271 ) ) {
F_159 ( L_47 ) ;
goto V_328;
}
F_4 ( & V_44 -> V_274 ) ;
F_159 ( L_48 , V_271 ) ;
return true ;
V_328:
F_211 ( & V_271 -> V_45 ) ;
F_4 ( & V_44 -> V_274 ) ;
return false ;
}
static void
F_212 ( struct V_329 * V_146 )
{
if ( V_146 -> V_96 == V_146 -> V_39 -> V_96 )
return;
if ( V_146 -> V_39 -> V_96 )
F_213 ( V_146 -> V_39 -> V_96 ) ;
V_146 -> V_39 -> V_96 = V_146 -> V_96 ;
if ( V_146 -> V_39 -> V_96 )
F_214 ( V_146 -> V_39 -> V_96 ) ;
}
static void
F_215 ( struct V_40 * V_40 ,
struct V_312 * V_313 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_93 * V_330 ;
struct V_40 * V_54 ;
struct V_270 * V_271 ;
struct V_329 * V_95 = V_40 -> V_45 . V_95 ;
struct V_331 * V_332 = V_95 -> V_39 ;
struct V_38 * V_48 = V_40 -> V_45 . V_39 ;
struct V_333 * V_333 = F_216 ( V_95 ) ;
struct V_334 * V_335 =
F_217 ( V_332 ) ;
struct V_257 * V_96 ;
if ( ! V_313 -> V_96 )
return;
if ( F_206 ( V_40 , V_313 ) ) {
V_96 = & V_313 -> V_96 -> V_45 ;
goto V_336;
}
F_218 ( V_313 -> V_96 ) ;
F_219 (dev, c) {
V_54 = F_50 ( V_330 ) ;
if ( V_330 == & V_40 -> V_45 )
continue;
if ( ! V_54 -> V_94 )
continue;
V_96 = V_330 -> V_95 -> V_96 ;
if ( ! V_96 )
continue;
V_271 = F_191 ( V_96 ) ;
if ( F_220 ( V_271 ) == V_313 -> V_45 ) {
F_214 ( V_96 ) ;
goto V_336;
}
}
F_217 ( V_332 ) -> V_337 = false ;
V_48 -> V_338 &= ~ ( 1 << F_221 ( V_95 ) ) ;
F_222 ( & V_40 -> V_45 ) ;
V_333 -> V_339 ( V_95 , & V_40 -> V_45 ) ;
return;
V_336:
V_332 -> V_340 = 0 ;
V_332 -> V_341 = 0 ;
V_332 -> V_342 = V_96 -> V_254 << 16 ;
V_332 -> V_343 = V_96 -> V_249 << 16 ;
V_332 -> V_344 = 0 ;
V_332 -> V_345 = 0 ;
V_332 -> V_346 = V_96 -> V_254 ;
V_332 -> V_347 = V_96 -> V_249 ;
V_335 -> V_348 . V_349 = V_332 -> V_340 ;
V_335 -> V_348 . y1 = V_332 -> V_341 ;
V_335 -> V_348 . V_350 = V_332 -> V_340 + V_332 -> V_342 ;
V_335 -> V_348 . V_351 = V_332 -> V_341 + V_332 -> V_343 ;
V_335 -> V_352 . V_349 = V_332 -> V_344 ;
V_335 -> V_352 . y1 = V_332 -> V_345 ;
V_335 -> V_352 . V_350 = V_332 -> V_344 + V_332 -> V_346 ;
V_335 -> V_352 . V_351 = V_332 -> V_345 + V_332 -> V_347 ;
V_271 = F_191 ( V_96 ) ;
if ( V_271 -> V_322 != V_353 )
V_2 -> V_354 = true ;
F_214 ( V_96 ) ;
V_95 -> V_96 = V_95 -> V_39 -> V_96 = V_96 ;
V_95 -> V_41 = V_95 -> V_39 -> V_41 = & V_40 -> V_45 ;
V_40 -> V_45 . V_39 -> V_338 |= ( 1 << F_221 ( V_95 ) ) ;
V_271 -> V_355 |= F_216 ( V_95 ) -> V_356 ;
}
static void F_223 ( struct V_329 * V_95 ,
const struct V_33 * V_48 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_95 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_257 * V_96 = V_332 -> V_45 . V_96 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
int V_146 = V_40 -> V_146 ;
T_1 V_357 ;
T_1 V_358 ;
T_5 V_9 = F_87 ( V_146 ) ;
unsigned int V_258 = V_332 -> V_45 . V_258 ;
int V_241 = F_177 ( V_96 -> V_250 , 0 ) ;
int V_280 = V_332 -> V_348 . V_349 >> 16 ;
int V_281 = V_332 -> V_348 . y1 >> 16 ;
V_358 = V_359 ;
V_358 |= V_147 ;
if ( F_60 ( V_44 ) -> V_110 < 4 ) {
if ( V_40 -> V_101 == V_132 )
V_358 |= V_360 ;
F_124 ( F_224 ( V_146 ) ,
( ( V_48 -> V_361 - 1 ) << 16 ) |
( V_48 -> V_362 - 1 ) ) ;
F_124 ( F_225 ( V_146 ) , 0 ) ;
} else if ( F_16 ( V_44 ) && V_146 == V_363 ) {
F_124 ( F_226 ( V_146 ) ,
( ( V_48 -> V_361 - 1 ) << 16 ) |
( V_48 -> V_362 - 1 ) ) ;
F_124 ( F_227 ( V_146 ) , 0 ) ;
F_124 ( F_228 ( V_146 ) , 0 ) ;
}
switch ( V_96 -> V_250 ) {
case V_292 :
V_358 |= V_291 ;
break;
case V_294 :
V_358 |= V_293 ;
break;
case V_296 :
V_358 |= V_295 ;
break;
case V_298 :
V_358 |= V_297 ;
break;
case V_300 :
V_358 |= V_299 ;
break;
case V_302 :
V_358 |= V_301 ;
break;
case V_304 :
V_358 |= V_303 ;
break;
default:
F_146 () ;
}
if ( F_60 ( V_44 ) -> V_110 >= 4 &&
V_271 -> V_322 != V_353 )
V_358 |= V_364 ;
if ( F_17 ( V_44 ) )
V_358 |= V_365 ;
V_357 = V_281 * V_96 -> V_266 [ 0 ] + V_280 * V_241 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
V_40 -> V_366 =
F_202 ( & V_280 , & V_281 , V_96 , 0 ,
V_96 -> V_266 [ 0 ] , V_258 ) ;
V_357 -= V_40 -> V_366 ;
} else {
V_40 -> V_366 = V_357 ;
}
if ( V_258 == F_229 ( V_367 ) ) {
V_358 |= V_368 ;
V_280 += ( V_48 -> V_362 - 1 ) ;
V_281 += ( V_48 -> V_361 - 1 ) ;
V_357 +=
( V_48 -> V_361 - 1 ) * V_96 -> V_266 [ 0 ] +
( V_48 -> V_362 - 1 ) * V_241 ;
}
V_40 -> V_369 = V_280 ;
V_40 -> V_370 = V_281 ;
F_124 ( V_9 , V_358 ) ;
F_124 ( F_230 ( V_146 ) , V_96 -> V_266 [ 0 ] ) ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
F_124 ( F_231 ( V_146 ) ,
F_220 ( V_271 ) + V_40 -> V_366 ) ;
F_124 ( F_232 ( V_146 ) , ( V_281 << 16 ) | V_280 ) ;
F_124 ( F_233 ( V_146 ) , V_357 ) ;
} else
F_124 ( F_234 ( V_146 ) , F_220 ( V_271 ) + V_357 ) ;
F_125 ( V_9 ) ;
}
static void F_235 ( struct V_329 * V_95 ,
struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_146 = V_40 -> V_146 ;
F_124 ( F_87 ( V_146 ) , 0 ) ;
if ( F_60 ( V_2 ) -> V_110 >= 4 )
F_124 ( F_231 ( V_146 ) , 0 ) ;
else
F_124 ( F_234 ( V_146 ) , 0 ) ;
F_125 ( F_87 ( V_146 ) ) ;
}
static void F_236 ( struct V_329 * V_95 ,
const struct V_33 * V_48 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_95 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_257 * V_96 = V_332 -> V_45 . V_96 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
int V_146 = V_40 -> V_146 ;
T_1 V_357 ;
T_1 V_358 ;
T_5 V_9 = F_87 ( V_146 ) ;
unsigned int V_258 = V_332 -> V_45 . V_258 ;
int V_241 = F_177 ( V_96 -> V_250 , 0 ) ;
int V_280 = V_332 -> V_348 . V_349 >> 16 ;
int V_281 = V_332 -> V_348 . y1 >> 16 ;
V_358 = V_359 ;
V_358 |= V_147 ;
if ( F_237 ( V_44 ) || F_238 ( V_44 ) )
V_358 |= V_371 ;
switch ( V_96 -> V_250 ) {
case V_292 :
V_358 |= V_291 ;
break;
case V_296 :
V_358 |= V_295 ;
break;
case V_298 :
V_358 |= V_297 ;
break;
case V_300 :
V_358 |= V_299 ;
break;
case V_302 :
V_358 |= V_301 ;
break;
case V_304 :
V_358 |= V_303 ;
break;
default:
F_146 () ;
}
if ( V_271 -> V_322 != V_353 )
V_358 |= V_364 ;
if ( ! F_237 ( V_44 ) && ! F_238 ( V_44 ) )
V_358 |= V_365 ;
V_357 = V_281 * V_96 -> V_266 [ 0 ] + V_280 * V_241 ;
V_40 -> V_366 =
F_202 ( & V_280 , & V_281 , V_96 , 0 ,
V_96 -> V_266 [ 0 ] , V_258 ) ;
V_357 -= V_40 -> V_366 ;
if ( V_258 == F_229 ( V_367 ) ) {
V_358 |= V_368 ;
if ( ! F_237 ( V_44 ) && ! F_238 ( V_44 ) ) {
V_280 += ( V_48 -> V_362 - 1 ) ;
V_281 += ( V_48 -> V_361 - 1 ) ;
V_357 +=
( V_48 -> V_361 - 1 ) * V_96 -> V_266 [ 0 ] +
( V_48 -> V_362 - 1 ) * V_241 ;
}
}
V_40 -> V_369 = V_280 ;
V_40 -> V_370 = V_281 ;
F_124 ( V_9 , V_358 ) ;
F_124 ( F_230 ( V_146 ) , V_96 -> V_266 [ 0 ] ) ;
F_124 ( F_231 ( V_146 ) ,
F_220 ( V_271 ) + V_40 -> V_366 ) ;
if ( F_237 ( V_44 ) || F_238 ( V_44 ) ) {
F_124 ( F_239 ( V_146 ) , ( V_281 << 16 ) | V_280 ) ;
} else {
F_124 ( F_232 ( V_146 ) , ( V_281 << 16 ) | V_280 ) ;
F_124 ( F_233 ( V_146 ) , V_357 ) ;
}
F_125 ( V_9 ) ;
}
T_1 F_240 ( const struct V_1 * V_2 ,
V_68 V_240 , T_2 V_250 )
{
if ( V_240 == V_242 ) {
return 64 ;
} else {
int V_241 = F_177 ( V_250 , 0 ) ;
return F_171 ( V_2 , V_240 , V_241 ) ;
}
}
T_1 F_241 ( struct V_333 * V_333 ,
struct V_270 * V_271 ,
unsigned int V_146 )
{
struct V_255 V_256 ;
struct V_372 * V_373 ;
T_6 V_287 ;
F_181 ( & V_256 , V_333 -> V_45 . V_39 -> V_96 ,
V_333 -> V_45 . V_39 -> V_258 ) ;
V_373 = F_242 ( V_271 , & V_256 ) ;
if ( F_6 ( ! V_373 , L_49 ,
V_256 . type ) )
return - 1 ;
V_287 = V_373 -> V_374 . V_375 ;
if ( V_146 == 1 ) {
V_287 += V_373 -> V_376 . V_260 . V_261 . V_377 *
V_319 ;
}
F_31 ( F_243 ( V_287 ) ) ;
return F_244 ( V_287 ) ;
}
static void F_245 ( struct V_40 * V_40 , int V_378 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
F_124 ( F_246 ( V_40 -> V_101 , V_378 ) , 0 ) ;
F_124 ( F_247 ( V_40 -> V_101 , V_378 ) , 0 ) ;
F_124 ( F_248 ( V_40 -> V_101 , V_378 ) , 0 ) ;
}
static void F_249 ( struct V_40 * V_40 )
{
struct V_379 * V_380 ;
int V_54 ;
V_380 = & V_40 -> V_97 -> V_380 ;
for ( V_54 = 0 ; V_54 < V_40 -> V_381 ; V_54 ++ ) {
if ( ! V_380 -> V_382 [ V_54 ] . V_383 )
F_245 ( V_40 , V_54 ) ;
}
}
T_1 F_250 ( T_2 V_250 )
{
switch ( V_250 ) {
case V_292 :
return V_384 ;
case V_296 :
return V_307 ;
case V_300 :
return V_308 | V_385 ;
case V_298 :
return V_308 ;
case V_309 :
return V_308 | V_385 |
V_386 ;
case V_310 :
return V_308 |
V_386 ;
case V_302 :
return V_311 ;
case V_304 :
return V_385 | V_311 ;
case V_387 :
return V_388 | V_389 ;
case V_390 :
return V_388 | V_391 ;
case V_392 :
return V_388 | V_393 ;
case V_394 :
return V_388 | V_395 ;
default:
F_173 ( V_250 ) ;
}
return 0 ;
}
T_1 F_251 ( V_68 V_240 )
{
switch ( V_240 ) {
case V_242 :
break;
case V_243 :
return V_396 ;
case V_244 :
return V_397 ;
case V_245 :
return V_398 ;
default:
F_173 ( V_240 ) ;
}
return 0 ;
}
T_1 F_252 ( unsigned int V_258 )
{
switch ( V_258 ) {
case F_229 ( V_399 ) :
break;
case F_229 ( V_400 ) :
return V_401 ;
case F_229 ( V_367 ) :
return V_402 ;
case F_229 ( V_403 ) :
return V_404 ;
default:
F_173 ( V_258 ) ;
}
return 0 ;
}
static void F_253 ( struct V_329 * V_146 ,
const struct V_33 * V_48 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_146 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_257 * V_96 = V_332 -> V_45 . V_96 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
int V_101 = V_40 -> V_101 ;
T_1 V_405 , V_406 , V_325 ;
T_1 V_247 , V_407 , V_408 ;
unsigned int V_258 = V_332 -> V_45 . V_258 ;
int V_409 , V_410 ;
T_1 V_411 ;
int V_412 = V_332 -> V_412 ;
int V_340 = V_332 -> V_348 . V_349 >> 16 ;
int V_341 = V_332 -> V_348 . y1 >> 16 ;
int V_342 = F_254 ( & V_332 -> V_348 ) >> 16 ;
int V_343 = F_255 ( & V_332 -> V_348 ) >> 16 ;
int V_413 = V_332 -> V_352 . V_349 ;
int V_414 = V_332 -> V_352 . y1 ;
int V_415 = F_254 ( & V_332 -> V_352 ) ;
int V_416 = F_255 ( & V_332 -> V_352 ) ;
V_405 = V_152 |
V_417 |
V_418 ;
V_405 |= F_250 ( V_96 -> V_250 ) ;
V_405 |= F_251 ( V_96 -> V_265 [ 0 ] ) ;
V_405 |= V_419 ;
V_405 |= F_252 ( V_258 ) ;
V_406 = F_240 ( V_2 , V_96 -> V_265 [ 0 ] ,
V_96 -> V_250 ) ;
V_411 = F_241 ( F_216 ( V_146 ) , V_271 , 0 ) ;
F_31 ( F_254 ( & V_332 -> V_348 ) == 0 ) ;
if ( F_182 ( V_258 ) ) {
int V_241 = F_177 ( V_96 -> V_250 , 0 ) ;
V_247 = F_174 ( V_2 , V_96 -> V_265 [ 0 ] , V_241 ) ;
V_325 = F_185 ( V_96 -> V_249 , V_247 ) ;
V_409 = V_325 * V_247 - V_341 - V_343 ;
V_410 = V_340 ;
V_408 = ( V_342 - 1 ) << 16 | ( V_343 - 1 ) ;
} else {
V_325 = V_96 -> V_266 [ 0 ] / V_406 ;
V_409 = V_340 ;
V_410 = V_341 ;
V_408 = ( V_343 - 1 ) << 16 | ( V_342 - 1 ) ;
}
V_407 = V_410 << 16 | V_409 ;
V_40 -> V_369 = V_409 ;
V_40 -> V_370 = V_410 ;
F_124 ( F_93 ( V_101 , 0 ) , V_405 ) ;
F_124 ( F_256 ( V_101 , 0 ) , V_407 ) ;
F_124 ( F_257 ( V_101 , 0 ) , V_408 ) ;
F_124 ( F_258 ( V_101 , 0 ) , V_325 ) ;
if ( V_412 >= 0 ) {
T_2 V_420 = 0 ;
F_31 ( ! V_415 || ! V_416 ) ;
V_420 = V_421 | F_259 ( 0 ) |
V_48 -> V_380 . V_382 [ V_412 ] . V_422 ;
F_124 ( F_246 ( V_101 , V_412 ) , V_420 ) ;
F_124 ( F_260 ( V_101 , V_412 ) , 0 ) ;
F_124 ( F_247 ( V_101 , V_412 ) , ( V_413 << 16 ) | V_414 ) ;
F_124 ( F_248 ( V_101 , V_412 ) , ( V_415 << 16 ) | V_416 ) ;
F_124 ( F_261 ( V_101 , 0 ) , 0 ) ;
} else {
F_124 ( F_261 ( V_101 , 0 ) , ( V_414 << 16 ) | V_413 ) ;
}
F_124 ( F_262 ( V_101 , 0 ) , V_411 ) ;
F_125 ( F_262 ( V_101 , 0 ) ) ;
}
static void F_263 ( struct V_329 * V_95 ,
struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = F_50 ( V_41 ) -> V_101 ;
F_124 ( F_93 ( V_101 , 0 ) , 0 ) ;
F_124 ( F_262 ( V_101 , 0 ) , 0 ) ;
F_125 ( F_262 ( V_101 , 0 ) ) ;
}
static int
F_264 ( struct V_93 * V_41 , struct V_257 * V_96 ,
int V_280 , int V_281 , enum V_423 V_39 )
{
F_127 ( L_50 ) ;
return - V_424 ;
}
static void F_265 ( struct V_43 * V_44 )
{
struct V_93 * V_41 ;
F_219 (dev, crtc) {
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_146 V_146 = V_40 -> V_146 ;
F_266 ( V_44 , V_146 ) ;
F_267 ( V_44 , V_146 ) ;
}
}
static void F_268 ( struct V_43 * V_44 )
{
struct V_93 * V_41 ;
F_219 (dev, crtc) {
struct V_333 * V_146 = F_216 ( V_41 -> V_95 ) ;
struct V_334 * V_332 ;
F_269 ( V_41 , & V_146 -> V_45 ) ;
V_332 = F_217 ( V_146 -> V_45 . V_39 ) ;
if ( V_332 -> V_337 )
V_146 -> V_425 ( & V_146 -> V_45 ,
F_270 ( V_41 -> V_39 ) ,
V_332 ) ;
F_271 ( V_41 ) ;
}
}
void F_272 ( struct V_43 * V_44 )
{
if ( F_57 ( V_44 ) )
return;
if ( F_60 ( V_44 ) -> V_110 >= 5 || F_17 ( V_44 ) )
return;
F_273 ( V_44 ) ;
F_274 ( V_44 ) ;
}
void F_275 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
F_265 ( V_44 ) ;
if ( F_57 ( V_44 ) )
return;
if ( F_60 ( V_44 ) -> V_110 >= 5 || F_17 ( V_44 ) ) {
F_268 ( V_44 ) ;
return;
}
F_276 ( V_2 ) ;
F_277 ( V_2 ) ;
F_278 ( V_44 ) ;
F_279 ( & V_2 -> V_426 ) ;
if ( V_2 -> V_427 . V_428 )
V_2 -> V_427 . V_428 ( V_44 ) ;
F_280 ( & V_2 -> V_426 ) ;
F_281 ( V_44 ) ;
F_282 ( V_2 ) ;
F_283 ( V_44 ) ;
}
static bool F_284 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
unsigned V_429 ;
bool V_430 ;
V_429 = F_285 ( & F_123 ( V_44 ) -> V_431 ) ;
if ( V_40 -> V_429 != V_429 )
return false ;
F_279 ( & V_44 -> V_432 ) ;
V_430 = F_50 ( V_41 ) -> V_433 != NULL ;
F_280 ( & V_44 -> V_432 ) ;
return V_430 ;
}
static void F_286 ( struct V_40 * V_41 ,
struct V_33 * V_434 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_45 . V_39 ) ;
V_41 -> V_45 . V_422 = V_41 -> V_45 . V_39 -> V_422 ;
F_159 ( L_51 ,
V_434 -> V_362 , V_434 -> V_361 ,
V_34 -> V_362 , V_34 -> V_361 ) ;
F_124 ( F_287 ( V_41 -> V_101 ) ,
( ( V_34 -> V_362 - 1 ) << 16 ) |
( V_34 -> V_361 - 1 ) ) ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
F_249 ( V_41 ) ;
if ( V_34 -> V_435 . V_156 )
F_288 ( V_41 ) ;
} else if ( F_14 ( V_44 ) ) {
if ( V_34 -> V_435 . V_156 )
F_289 ( V_41 ) ;
else if ( V_434 -> V_435 . V_156 )
F_290 ( V_41 , true ) ;
}
}
static void F_291 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( F_292 ( V_44 ) ) {
V_436 &= ~ V_437 ;
V_436 |= V_437 | V_438 ;
} else {
V_436 &= ~ V_439 ;
V_436 |= V_439 | V_438 ;
}
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( F_105 ( V_44 ) ) {
V_436 &= ~ V_440 ;
V_436 |= V_441 ;
} else {
V_436 &= ~ V_439 ;
V_436 |= V_439 ;
}
F_124 ( V_9 , V_436 | V_442 ) ;
F_125 ( V_9 ) ;
F_126 ( 1000 ) ;
if ( F_292 ( V_44 ) )
F_124 ( V_9 , F_10 ( V_9 ) | V_443 |
V_444 ) ;
}
static void F_293 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 , V_445 ;
F_294 ( V_2 , V_101 ) ;
V_9 = F_295 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_446 ;
V_436 &= ~ V_447 ;
F_124 ( V_9 , V_436 ) ;
F_10 ( V_9 ) ;
F_126 ( 150 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_448 ;
V_436 |= F_296 ( V_40 -> V_97 -> V_449 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
F_124 ( V_9 , V_436 | V_117 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
F_124 ( V_9 , V_436 | V_118 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
F_124 ( F_297 ( V_101 ) , V_451 ) ;
F_124 ( F_297 ( V_101 ) , V_451 |
V_452 ) ;
V_9 = F_298 ( V_101 ) ;
for ( V_445 = 0 ; V_445 < 5 ; V_445 ++ ) {
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( ( V_436 & V_447 ) ) {
F_159 ( L_53 ) ;
F_124 ( V_9 , V_436 | V_447 ) ;
break;
}
}
if ( V_445 == 5 )
F_127 ( L_54 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_453 ;
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_453 ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
V_9 = F_298 ( V_101 ) ;
for ( V_445 = 0 ; V_445 < 5 ; V_445 ++ ) {
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( V_436 & V_446 ) {
F_124 ( V_9 , V_436 | V_446 ) ;
F_159 ( L_55 ) ;
break;
}
}
if ( V_445 == 5 )
F_127 ( L_56 ) ;
F_159 ( L_57 ) ;
}
static void F_299 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 , V_54 , V_454 ;
V_9 = F_295 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_446 ;
V_436 &= ~ V_447 ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_448 ;
V_436 |= F_296 ( V_40 -> V_97 -> V_449 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
V_436 &= ~ V_455 ;
V_436 |= V_456 ;
F_124 ( V_9 , V_436 | V_117 ) ;
F_124 ( F_300 ( V_101 ) ,
V_457 | V_458 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( F_105 ( V_44 ) ) {
V_436 &= ~ V_440 ;
V_436 |= V_459 ;
} else {
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
}
F_124 ( V_9 , V_436 | V_118 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_455 ;
V_436 |= V_460 [ V_54 ] ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 500 ) ;
for ( V_454 = 0 ; V_454 < 5 ; V_454 ++ ) {
V_9 = F_298 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( V_436 & V_447 ) {
F_124 ( V_9 , V_436 | V_447 ) ;
F_159 ( L_53 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_454 < 5 )
break;
}
if ( V_54 == 4 )
F_127 ( L_54 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_453 ;
if ( F_301 ( V_44 ) ) {
V_436 &= ~ V_455 ;
V_436 |= V_456 ;
}
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( F_105 ( V_44 ) ) {
V_436 &= ~ V_440 ;
V_436 |= V_461 ;
} else {
V_436 &= ~ V_439 ;
V_436 |= V_453 ;
}
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_455 ;
V_436 |= V_460 [ V_54 ] ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 500 ) ;
for ( V_454 = 0 ; V_454 < 5 ; V_454 ++ ) {
V_9 = F_298 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( V_436 & V_446 ) {
F_124 ( V_9 , V_436 | V_446 ) ;
F_159 ( L_55 ) ;
break;
}
F_126 ( 50 ) ;
}
if ( V_454 < 5 )
break;
}
if ( V_54 == 4 )
F_127 ( L_56 ) ;
F_159 ( L_58 ) ;
}
static void F_302 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 , V_54 , V_462 ;
V_9 = F_295 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_446 ;
V_436 &= ~ V_447 ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 150 ) ;
F_159 ( L_59 ,
F_10 ( F_298 ( V_101 ) ) ) ;
for ( V_462 = 0 ; V_462 < F_180 ( V_460 ) * 2 ; V_462 ++ ) {
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ ( V_463 | V_437 ) ;
V_436 &= ~ V_117 ;
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_463 ;
V_436 &= ~ V_440 ;
V_436 &= ~ V_118 ;
F_124 ( V_9 , V_436 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_448 ;
V_436 |= F_296 ( V_40 -> V_97 -> V_449 ) ;
V_436 |= V_464 ;
V_436 &= ~ V_455 ;
V_436 |= V_460 [ V_462 / 2 ] ;
V_436 |= V_465 ;
F_124 ( V_9 , V_436 | V_117 ) ;
F_124 ( F_300 ( V_101 ) ,
V_457 | V_458 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 |= V_459 ;
V_436 |= V_465 ;
F_124 ( V_9 , V_436 | V_118 ) ;
F_125 ( V_9 ) ;
F_126 ( 1 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_9 = F_298 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( V_436 & V_447 ||
( F_10 ( V_9 ) & V_447 ) ) {
F_124 ( V_9 , V_436 | V_447 ) ;
F_159 ( L_60 ,
V_54 ) ;
break;
}
F_126 ( 1 ) ;
}
if ( V_54 == 4 ) {
F_159 ( L_61 , V_462 / 2 ) ;
continue;
}
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_437 ;
V_436 |= V_466 ;
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_440 ;
V_436 |= V_461 ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 2 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
V_9 = F_298 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_159 ( L_52 , V_436 ) ;
if ( V_436 & V_446 ||
( F_10 ( V_9 ) & V_446 ) ) {
F_124 ( V_9 , V_436 | V_446 ) ;
F_159 ( L_62 ,
V_54 ) ;
goto V_467;
}
F_126 ( 2 ) ;
}
if ( V_54 == 4 )
F_159 ( L_63 , V_462 / 2 ) ;
}
V_467:
F_159 ( L_58 ) ;
}
static void F_303 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ ( V_448 | ( 0x7 << 16 ) ) ;
V_436 |= F_296 ( V_40 -> V_97 -> V_449 ) ;
V_436 |= ( F_10 ( F_61 ( V_101 ) ) & V_218 ) << 11 ;
F_124 ( V_9 , V_436 | V_120 ) ;
F_125 ( V_9 ) ;
F_126 ( 200 ) ;
V_436 = F_10 ( V_9 ) ;
F_124 ( V_9 , V_436 | V_468 ) ;
F_125 ( V_9 ) ;
F_126 ( 200 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( ( V_436 & V_119 ) == 0 ) {
F_124 ( V_9 , V_436 | V_119 ) ;
F_125 ( V_9 ) ;
F_126 ( 100 ) ;
}
}
static void F_304 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_124 ( V_9 , V_436 & ~ V_468 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_124 ( V_9 , V_436 & ~ V_119 ) ;
F_125 ( V_9 ) ;
F_126 ( 100 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_124 ( V_9 , V_436 & ~ V_120 ) ;
F_125 ( V_9 ) ;
F_126 ( 100 ) ;
}
static void F_305 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_5 V_9 ;
T_1 V_436 ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
F_124 ( V_9 , V_436 & ~ V_117 ) ;
F_125 ( V_9 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ ( 0x7 << 16 ) ;
V_436 |= ( F_10 ( F_61 ( V_101 ) ) & V_218 ) << 11 ;
F_124 ( V_9 , V_436 & ~ V_118 ) ;
F_125 ( V_9 ) ;
F_126 ( 100 ) ;
if ( F_119 ( V_44 ) )
F_124 ( F_297 ( V_101 ) , V_451 ) ;
V_9 = F_70 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
F_124 ( V_9 , V_436 ) ;
V_9 = F_72 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
if ( F_105 ( V_44 ) ) {
V_436 &= ~ V_440 ;
V_436 |= V_459 ;
} else {
V_436 &= ~ V_439 ;
V_436 |= V_450 ;
}
V_436 &= ~ ( 0x07 << 16 ) ;
V_436 |= ( F_10 ( F_61 ( V_101 ) ) & V_218 ) << 11 ;
F_124 ( V_9 , V_436 ) ;
F_125 ( V_9 ) ;
F_126 ( 100 ) ;
}
bool F_306 ( struct V_43 * V_44 )
{
struct V_40 * V_41 ;
F_138 (dev, crtc) {
if ( F_307 ( & V_41 -> V_469 ) == 0 )
continue;
if ( V_41 -> V_433 )
F_308 ( V_44 , V_41 -> V_101 ) ;
return true ;
}
return false ;
}
static void F_309 ( struct V_40 * V_40 )
{
struct V_1 * V_2 = F_123 ( V_40 -> V_45 . V_44 ) ;
struct V_470 * V_471 = V_40 -> V_433 ;
F_310 () ;
V_40 -> V_433 = NULL ;
if ( V_471 -> V_472 )
F_311 ( & V_40 -> V_45 , V_471 -> V_472 ) ;
F_101 ( & V_40 -> V_45 ) ;
F_312 ( & V_2 -> V_473 ) ;
F_313 ( V_2 -> V_474 , & V_471 -> V_471 ) ;
F_314 ( V_40 -> V_146 ,
V_471 -> V_475 ) ;
}
static int F_315 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
long V_273 ;
F_31 ( F_316 ( & V_2 -> V_473 ) ) ;
V_273 = F_317 (
V_2 -> V_473 ,
! F_284 ( V_41 ) ,
60 * V_476 ) ;
if ( V_273 < 0 )
return V_273 ;
if ( V_273 == 0 ) {
struct V_40 * V_40 = F_50 ( V_41 ) ;
F_279 ( & V_44 -> V_432 ) ;
if ( V_40 -> V_433 ) {
F_318 ( 1 , L_64 ) ;
F_309 ( V_40 ) ;
}
F_280 ( & V_44 -> V_432 ) ;
}
return 0 ;
}
static void F_319 ( struct V_1 * V_2 )
{
T_1 V_436 ;
F_124 ( V_477 , V_478 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_436 = F_320 ( V_2 , V_479 , V_480 ) ;
V_436 |= V_481 ;
F_321 ( V_2 , V_479 , V_436 , V_480 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_322 ( struct V_93 * V_41 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_44 ) ;
int clock = F_50 ( V_41 ) -> V_97 -> V_45 . V_98 . V_99 ;
T_1 V_482 , V_483 , V_484 , V_485 = 0 ;
T_1 V_436 ;
F_319 ( V_2 ) ;
for ( V_484 = 0 ; V_484 < 2 ; V_484 ++ ) {
T_1 V_486 = 172800 * 1000 ;
T_1 V_487 = 64 ;
T_1 V_488 ;
V_488 = F_7 ( V_486 ,
clock << V_484 ) ;
V_482 = ( V_488 / V_487 ) - 2 ;
V_483 = V_488 % V_487 ;
if ( V_482 <= 0x7f )
break;
}
F_31 ( F_323 ( V_482 ) &
~ V_489 ) ;
F_31 ( F_324 ( V_485 ) &
~ V_490 ) ;
F_159 ( L_65 ,
clock ,
V_484 ,
V_482 ,
V_485 ,
V_483 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_436 = F_320 ( V_2 , V_491 , V_480 ) ;
V_436 &= ~ V_489 ;
V_436 |= F_323 ( V_482 ) ;
V_436 &= ~ V_490 ;
V_436 |= F_325 ( V_483 ) ;
V_436 |= F_324 ( V_485 ) ;
V_436 |= V_492 ;
F_321 ( V_2 , V_491 , V_436 , V_480 ) ;
V_436 = F_320 ( V_2 , V_493 , V_480 ) ;
V_436 &= ~ F_326 ( 1 ) ;
V_436 |= F_326 ( V_484 ) ;
F_321 ( V_2 , V_493 , V_436 , V_480 ) ;
V_436 = F_320 ( V_2 , V_479 , V_480 ) ;
V_436 &= ~ V_481 ;
F_321 ( V_2 , V_479 , V_436 , V_480 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_126 ( 24 ) ;
F_124 ( V_477 , V_494 ) ;
}
int F_327 ( struct V_1 * V_2 )
{
T_1 V_482 , V_483 , V_484 ;
T_1 V_486 = 172800 * 1000 ;
T_1 V_487 = 64 ;
T_1 V_488 ;
T_1 V_436 ;
if ( ( F_10 ( V_477 ) & V_494 ) == 0 )
return 0 ;
F_2 ( & V_2 -> V_5 ) ;
V_436 = F_320 ( V_2 , V_479 , V_480 ) ;
if ( V_436 & V_481 ) {
F_4 ( & V_2 -> V_5 ) ;
return 0 ;
}
V_436 = F_320 ( V_2 , V_491 , V_480 ) ;
V_482 = ( V_436 & V_489 ) >>
V_495 ;
V_483 = ( V_436 & V_490 ) >>
V_496 ;
V_436 = F_320 ( V_2 , V_493 , V_480 ) ;
V_484 = ( V_436 & V_497 ) >>
V_498 ;
F_4 ( & V_2 -> V_5 ) ;
V_488 = ( V_482 + 2 ) * V_487 + V_483 ;
return F_7 ( V_486 ,
V_488 << V_484 ) ;
}
static void F_328 ( struct V_40 * V_41 ,
enum V_101 V_232 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_100 V_103 = V_41 -> V_97 -> V_103 ;
F_124 ( F_329 ( V_232 ) ,
F_10 ( F_330 ( V_103 ) ) ) ;
F_124 ( F_331 ( V_232 ) ,
F_10 ( F_332 ( V_103 ) ) ) ;
F_124 ( F_333 ( V_232 ) ,
F_10 ( F_334 ( V_103 ) ) ) ;
F_124 ( F_335 ( V_232 ) ,
F_10 ( F_336 ( V_103 ) ) ) ;
F_124 ( F_337 ( V_232 ) ,
F_10 ( F_338 ( V_103 ) ) ) ;
F_124 ( F_339 ( V_232 ) ,
F_10 ( F_340 ( V_103 ) ) ) ;
F_124 ( F_341 ( V_232 ) ,
F_10 ( F_342 ( V_103 ) ) ) ;
}
static void F_343 ( struct V_43 * V_44 , bool V_499 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_436 ;
V_436 = F_10 ( V_500 ) ;
if ( ! ! ( V_436 & V_501 ) == V_499 )
return;
F_31 ( F_10 ( F_72 ( V_132 ) ) & V_118 ) ;
F_31 ( F_10 ( F_72 ( V_502 ) ) & V_118 ) ;
V_436 &= ~ V_501 ;
if ( V_499 )
V_436 |= V_501 ;
F_159 ( L_66 , V_499 ? L_67 : L_68 ) ;
F_124 ( V_500 , V_436 ) ;
F_125 ( V_500 ) ;
}
static void F_344 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
switch ( V_40 -> V_101 ) {
case V_123 :
break;
case V_132 :
if ( V_40 -> V_97 -> V_449 > 2 )
F_343 ( V_44 , false ) ;
else
F_343 ( V_44 , true ) ;
break;
case V_502 :
F_343 ( V_44 , true ) ;
break;
default:
F_146 () ;
}
}
static enum V_188
F_345 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_46 * V_47 ;
F_27 (dev, crtc, encoder) {
if ( V_47 -> type == V_503 ||
V_47 -> type == V_504 )
return F_346 ( & V_47 -> V_45 ) -> V_188 ;
}
return - 1 ;
}
static void F_347 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_1 V_436 ;
F_102 ( V_2 , V_101 ) ;
if ( F_292 ( V_44 ) )
F_344 ( V_40 ) ;
F_124 ( F_348 ( V_101 ) ,
F_10 ( F_349 ( V_101 ) ) & V_505 ) ;
V_2 -> V_427 . V_506 ( V_41 ) ;
if ( F_105 ( V_44 ) ) {
T_1 V_507 ;
V_436 = F_10 ( V_508 ) ;
V_436 |= F_350 ( V_101 ) ;
V_507 = F_351 ( V_101 ) ;
if ( V_40 -> V_97 -> V_216 ==
F_352 ( V_2 , V_509 ) )
V_436 |= V_507 ;
else
V_436 &= ~ V_507 ;
F_124 ( V_508 , V_436 ) ;
}
F_353 ( V_40 ) ;
F_75 ( V_2 , V_101 ) ;
F_328 ( V_40 , V_101 ) ;
F_291 ( V_41 ) ;
if ( F_105 ( V_44 ) && V_40 -> V_97 -> V_510 ) {
const struct V_511 * V_98 =
& V_40 -> V_97 -> V_45 . V_98 ;
T_1 V_512 = ( F_10 ( F_61 ( V_101 ) ) & V_218 ) >> 5 ;
T_5 V_9 = F_106 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ ( V_160 |
V_513 |
V_514 ) ;
V_436 |= V_515 ;
V_436 |= V_512 << 9 ;
if ( V_98 -> V_326 & V_516 )
V_436 |= V_517 ;
if ( V_98 -> V_326 & V_518 )
V_436 |= V_519 ;
switch ( F_345 ( V_41 ) ) {
case V_208 :
V_436 |= V_175 ;
break;
case V_210 :
V_436 |= V_177 ;
break;
case V_212 :
V_436 |= V_179 ;
break;
default:
F_146 () ;
}
F_124 ( V_9 , V_436 ) ;
}
F_148 ( V_2 , V_101 ) ;
}
static void F_354 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
F_102 ( V_2 , V_229 ) ;
F_322 ( V_41 ) ;
F_328 ( V_40 , V_123 ) ;
F_153 ( V_2 , V_103 ) ;
}
static void F_355 ( struct V_43 * V_44 , int V_101 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_5 V_520 = F_56 ( V_101 ) ;
T_1 V_436 ;
V_436 = F_10 ( V_520 ) ;
F_126 ( 500 ) ;
if ( F_62 ( F_10 ( V_520 ) != V_436 , 5 ) ) {
if ( F_62 ( F_10 ( V_520 ) != V_436 , 5 ) )
F_127 ( L_69 , F_77 ( V_101 ) ) ;
}
}
static int
F_356 ( struct V_33 * V_48 , bool V_521 ,
unsigned V_522 , int * V_412 , unsigned int V_258 ,
int V_342 , int V_343 , int V_415 , int V_416 )
{
struct V_379 * V_380 =
& V_48 -> V_380 ;
struct V_40 * V_40 =
F_50 ( V_48 -> V_45 . V_41 ) ;
int V_523 ;
V_523 = F_182 ( V_258 ) ?
( V_343 != V_415 || V_342 != V_416 ) :
( V_342 != V_415 || V_343 != V_416 ) ;
if ( V_521 || ! V_523 ) {
if ( * V_412 >= 0 ) {
V_380 -> V_524 &= ~ ( 1 << V_522 ) ;
V_380 -> V_382 [ * V_412 ] . V_383 = 0 ;
F_159 ( L_70
L_71 ,
V_40 -> V_101 , V_522 , * V_412 ,
V_380 -> V_524 ) ;
* V_412 = - 1 ;
}
return 0 ;
}
if ( V_342 < V_525 || V_343 < V_526 ||
V_415 < V_527 || V_416 < V_528 ||
V_342 > V_529 || V_343 > V_530 ||
V_415 > V_531 || V_416 > V_532 ) {
F_159 ( L_72
L_73 ,
V_40 -> V_101 , V_522 , V_342 , V_343 , V_415 , V_416 ) ;
return - V_533 ;
}
V_380 -> V_524 |= ( 1 << V_522 ) ;
F_159 ( L_70
L_74 ,
V_40 -> V_101 , V_522 , V_342 , V_343 , V_415 , V_416 ,
V_380 -> V_524 ) ;
return 0 ;
}
int F_357 ( struct V_33 * V_39 )
{
struct V_40 * V_40 = F_50 ( V_39 -> V_45 . V_41 ) ;
const struct V_511 * V_98 = & V_39 -> V_45 . V_98 ;
F_159 ( L_75 ,
V_40 -> V_45 . V_45 . V_378 , V_40 -> V_101 , V_534 ) ;
return F_356 ( V_39 , ! V_39 -> V_45 . V_94 , V_534 ,
& V_39 -> V_380 . V_412 , F_229 ( V_399 ) ,
V_39 -> V_362 , V_39 -> V_361 ,
V_98 -> V_535 , V_98 -> V_536 ) ;
}
static int F_358 ( struct V_33 * V_48 ,
struct V_334 * V_332 )
{
struct V_40 * V_40 = F_50 ( V_48 -> V_45 . V_41 ) ;
struct V_333 * V_333 =
F_216 ( V_332 -> V_45 . V_146 ) ;
struct V_257 * V_96 = V_332 -> V_45 . V_96 ;
int V_273 ;
bool V_521 = ! V_96 || ! V_332 -> V_337 ;
F_159 ( L_76 ,
V_333 -> V_45 . V_45 . V_378 , V_40 -> V_101 ,
F_221 ( & V_333 -> V_45 ) ) ;
V_273 = F_356 ( V_48 , V_521 ,
F_221 ( & V_333 -> V_45 ) ,
& V_332 -> V_412 ,
V_332 -> V_45 . V_258 ,
F_254 ( & V_332 -> V_348 ) >> 16 ,
F_255 ( & V_332 -> V_348 ) >> 16 ,
F_254 ( & V_332 -> V_352 ) ,
F_255 ( & V_332 -> V_352 ) ) ;
if ( V_273 || V_332 -> V_412 < 0 )
return V_273 ;
if ( V_332 -> V_537 . V_326 != V_538 ) {
F_159 ( L_77 ,
V_333 -> V_45 . V_45 . V_378 ) ;
return - V_533 ;
}
switch ( V_96 -> V_250 ) {
case V_296 :
case V_300 :
case V_298 :
case V_309 :
case V_310 :
case V_302 :
case V_304 :
case V_387 :
case V_390 :
case V_392 :
case V_394 :
break;
default:
F_159 ( L_78 ,
V_333 -> V_45 . V_45 . V_378 , V_96 -> V_45 . V_378 , V_96 -> V_250 ) ;
return - V_533 ;
}
return 0 ;
}
static void F_359 ( struct V_40 * V_41 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_41 -> V_381 ; V_54 ++ )
F_245 ( V_41 , V_54 ) ;
}
static void F_288 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_41 -> V_101 ;
struct V_379 * V_380 =
& V_41 -> V_97 -> V_380 ;
F_159 ( L_79 , V_41 -> V_97 ) ;
if ( V_41 -> V_97 -> V_435 . V_156 ) {
int V_378 ;
if ( F_31 ( V_41 -> V_97 -> V_380 . V_412 < 0 ) ) {
F_127 ( L_80 ) ;
return;
}
V_378 = V_380 -> V_412 ;
F_124 ( F_246 ( V_101 , V_378 ) , V_421 |
V_539 | V_380 -> V_382 [ V_378 ] . V_422 ) ;
F_124 ( F_247 ( V_101 , V_378 ) , V_41 -> V_97 -> V_435 . V_540 ) ;
F_124 ( F_248 ( V_101 , V_378 ) , V_41 -> V_97 -> V_435 . V_253 ) ;
F_159 ( L_81 , V_41 -> V_97 , V_378 ) ;
}
}
static void F_289 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_41 -> V_101 ;
if ( V_41 -> V_97 -> V_435 . V_156 ) {
if ( F_292 ( V_44 ) || F_237 ( V_44 ) )
F_124 ( F_360 ( V_101 ) , V_541 | V_542 |
F_361 ( V_101 ) ) ;
else
F_124 ( F_360 ( V_101 ) , V_541 | V_542 ) ;
F_124 ( F_362 ( V_101 ) , V_41 -> V_97 -> V_435 . V_540 ) ;
F_124 ( F_363 ( V_101 ) , V_41 -> V_97 -> V_435 . V_253 ) ;
}
}
void F_364 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! V_41 -> V_97 -> V_543 )
return;
F_365 ( V_2 , V_41 -> V_146 ) ;
if ( F_238 ( V_44 ) ) {
F_2 ( & V_2 -> V_544 . V_545 ) ;
F_31 ( F_366 ( V_2 , V_546 , 0xc0000000 ) ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
} else {
F_124 ( V_547 , V_548 ) ;
if ( F_62 ( F_367 ( V_547 ) & V_548 , 50 ) )
F_127 ( L_82 ) ;
}
}
void F_368 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! V_41 -> V_97 -> V_543 )
return;
F_365 ( V_2 , V_41 -> V_146 ) ;
if ( F_238 ( V_44 ) ) {
F_2 ( & V_2 -> V_544 . V_545 ) ;
F_31 ( F_366 ( V_2 , V_546 , 0 ) ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
if ( F_62 ( ( F_10 ( V_547 ) & V_548 ) == 0 , 42 ) )
F_127 ( L_83 ) ;
} else {
F_124 ( V_547 , 0 ) ;
F_125 ( V_547 ) ;
}
F_308 ( V_44 , V_41 -> V_101 ) ;
}
static void F_369 ( struct V_40 * V_40 )
{
if ( V_40 -> V_549 ) {
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
F_2 ( & V_44 -> V_274 ) ;
V_2 -> V_550 . V_551 = false ;
( void ) F_370 ( V_40 -> V_549 ) ;
V_2 -> V_550 . V_551 = true ;
F_4 ( & V_44 -> V_274 ) ;
}
}
static void
F_371 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
F_364 ( V_40 ) ;
if ( F_57 ( V_44 ) )
F_372 ( V_2 , V_101 , true ) ;
F_373 ( V_2 ) ;
F_374 ( V_2 ) ;
}
static void
F_375 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
if ( F_57 ( V_44 ) )
F_372 ( V_2 , V_101 , false ) ;
F_368 ( V_40 ) ;
}
static void
F_222 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
F_375 ( V_41 ) ;
if ( F_162 ( V_44 ) ) {
F_376 ( V_2 , false ) ;
V_2 -> V_552 . V_553 . V_554 = false ;
F_308 ( V_44 , V_101 ) ;
}
}
static void F_377 ( struct V_33 * V_434 )
{
struct V_40 * V_41 = F_50 ( V_434 -> V_45 . V_41 ) ;
struct V_49 * V_555 = V_434 -> V_45 . V_39 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_45 . V_39 ) ;
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_329 * V_95 = V_41 -> V_45 . V_95 ;
struct V_331 * V_556 =
F_378 ( V_555 , V_95 ) ;
F_379 ( V_44 , V_34 -> V_557 ) ;
V_41 -> V_552 . V_558 = true ;
if ( V_34 -> V_559 && V_34 -> V_45 . V_94 )
F_380 ( & V_41 -> V_45 ) ;
if ( V_556 ) {
struct V_334 * V_560 =
F_217 ( V_95 -> V_39 ) ;
struct V_334 * V_561 =
F_217 ( V_556 ) ;
F_381 ( V_41 ) ;
if ( V_560 -> V_337 &&
( F_24 ( & V_34 -> V_45 ) ||
! V_561 -> V_337 ) )
F_371 ( & V_41 -> V_45 ) ;
}
}
static void F_382 ( struct V_33 * V_434 )
{
struct V_40 * V_41 = F_50 ( V_434 -> V_45 . V_41 ) ;
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_45 . V_39 ) ;
struct V_49 * V_555 = V_434 -> V_45 . V_39 ;
struct V_329 * V_95 = V_41 -> V_45 . V_95 ;
struct V_331 * V_556 =
F_378 ( V_555 , V_95 ) ;
bool V_562 = F_24 ( & V_34 -> V_45 ) ;
if ( V_556 ) {
struct V_334 * V_560 =
F_217 ( V_95 -> V_39 ) ;
struct V_334 * V_561 =
F_217 ( V_556 ) ;
F_383 ( V_41 ) ;
if ( V_561 -> V_337 &&
( V_562 || ! V_560 -> V_337 ) )
F_375 ( & V_41 -> V_45 ) ;
}
if ( V_34 -> V_563 ) {
V_41 -> V_552 . V_558 = false ;
if ( V_434 -> V_45 . V_94 ) {
F_376 ( V_2 , false ) ;
V_2 -> V_552 . V_553 . V_554 = false ;
F_308 ( V_44 , V_41 -> V_101 ) ;
}
}
if ( V_34 -> V_564 ) {
F_384 ( V_44 ) ;
F_308 ( V_44 , V_41 -> V_101 ) ;
}
if ( F_24 ( & V_34 -> V_45 ) )
return;
if ( V_2 -> V_427 . V_565 != NULL )
V_2 -> V_427 . V_565 ( V_34 ) ;
else if ( V_34 -> V_566 )
F_380 ( & V_41 -> V_45 ) ;
}
static void F_385 ( struct V_93 * V_41 , unsigned V_338 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_329 * V_60 ;
int V_101 = V_40 -> V_101 ;
F_369 ( V_40 ) ;
F_386 (p, dev, plane_mask)
F_216 ( V_60 ) -> V_339 ( V_60 , V_41 ) ;
F_379 ( V_44 , F_387 ( V_101 ) ) ;
}
static void F_388 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
int V_101 = V_40 -> V_101 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_39 ) ;
if ( F_31 ( V_40 -> V_94 ) )
return;
if ( V_40 -> V_97 -> V_234 || F_23 ( V_2 ) )
F_372 ( V_2 , V_101 , false ) ;
if ( V_40 -> V_97 -> V_234 )
F_389 ( V_2 , V_101 , false ) ;
if ( V_40 -> V_97 -> V_234 )
F_390 ( V_40 ) ;
if ( V_40 -> V_97 -> V_510 )
F_391 ( V_40 , V_567 ) ;
F_392 ( V_40 ) ;
F_393 ( V_40 ) ;
if ( V_40 -> V_97 -> V_234 ) {
F_394 ( V_40 ,
& V_40 -> V_97 -> V_568 , NULL ) ;
}
F_395 ( V_41 ) ;
V_40 -> V_94 = true ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_569 )
V_47 -> V_569 ( V_47 ) ;
if ( V_40 -> V_97 -> V_234 ) {
F_303 ( V_40 ) ;
} else {
F_155 ( V_2 , V_101 ) ;
F_156 ( V_2 , V_101 ) ;
}
F_289 ( V_40 ) ;
F_396 ( & V_34 -> V_45 ) ;
if ( V_2 -> V_427 . V_565 != NULL )
V_2 -> V_427 . V_565 ( V_40 -> V_97 ) ;
F_158 ( V_40 ) ;
if ( V_40 -> V_97 -> V_234 )
F_347 ( V_41 ) ;
F_98 ( V_41 ) ;
F_397 ( V_41 ) ;
F_27 (dev, crtc, encoder)
V_47 -> V_499 ( V_47 ) ;
if ( F_105 ( V_44 ) )
F_355 ( V_44 , V_40 -> V_101 ) ;
if ( V_40 -> V_97 -> V_234 )
F_308 ( V_44 , V_101 ) ;
F_372 ( V_2 , V_101 , true ) ;
F_389 ( V_2 , V_101 , true ) ;
}
static bool F_398 ( struct V_40 * V_41 )
{
return F_399 ( V_41 -> V_45 . V_44 ) && V_41 -> V_101 == V_123 ;
}
static void F_400 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
int V_101 = V_40 -> V_101 , V_570 ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_39 ) ;
if ( F_31 ( V_40 -> V_94 ) )
return;
if ( V_40 -> V_97 -> V_234 )
F_389 ( V_2 , V_229 ,
false ) ;
if ( V_40 -> V_97 -> V_216 )
F_353 ( V_40 ) ;
if ( V_40 -> V_97 -> V_510 )
F_391 ( V_40 , V_567 ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_392 ( V_40 ) ;
F_393 ( V_40 ) ;
if ( V_103 != V_571 &&
! F_401 ( V_103 ) ) {
F_124 ( F_402 ( V_103 ) ,
V_40 -> V_97 -> V_572 - 1 ) ;
}
if ( V_40 -> V_97 -> V_234 ) {
F_394 ( V_40 ,
& V_40 -> V_97 -> V_568 , NULL ) ;
}
if ( ! V_40 -> V_97 -> V_233 )
F_403 ( V_41 ) ;
F_404 ( V_41 ) ;
F_405 ( & V_34 -> V_45 ) ;
V_40 -> V_94 = true ;
if ( V_40 -> V_97 -> V_234 )
F_372 ( V_2 , V_101 , false ) ;
else
F_372 ( V_2 , V_101 , true ) ;
F_27 (dev, crtc, encoder) {
if ( V_47 -> V_569 )
V_47 -> V_569 ( V_47 ) ;
}
if ( V_40 -> V_97 -> V_234 )
V_2 -> V_427 . V_506 ( V_41 ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_406 ( V_40 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 9 )
F_288 ( V_40 ) ;
else
F_289 ( V_40 ) ;
F_396 ( & V_34 -> V_45 ) ;
F_407 ( V_41 ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_408 ( V_41 ) ;
if ( V_2 -> V_427 . V_565 != NULL )
V_2 -> V_427 . V_565 ( V_34 ) ;
else
F_380 ( V_41 ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_158 ( V_40 ) ;
if ( V_40 -> V_97 -> V_234 )
F_354 ( V_41 ) ;
if ( V_40 -> V_97 -> V_573 )
F_409 ( V_41 , true ) ;
F_98 ( V_41 ) ;
F_397 ( V_41 ) ;
F_27 (dev, crtc, encoder) {
V_47 -> V_499 ( V_47 ) ;
F_410 ( V_47 , true ) ;
}
if ( V_40 -> V_97 -> V_234 ) {
F_308 ( V_44 , V_101 ) ;
F_308 ( V_44 , V_101 ) ;
F_372 ( V_2 , V_101 , true ) ;
F_389 ( V_2 , V_229 ,
true ) ;
}
V_570 = V_34 -> V_570 ;
if ( F_237 ( V_44 ) && V_570 != V_574 ) {
F_308 ( V_44 , V_570 ) ;
F_308 ( V_44 , V_570 ) ;
}
}
static void F_290 ( struct V_40 * V_41 , bool V_575 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_41 -> V_101 ;
if ( V_575 || V_41 -> V_97 -> V_435 . V_156 ) {
F_124 ( F_360 ( V_101 ) , 0 ) ;
F_124 ( F_362 ( V_101 ) , 0 ) ;
F_124 ( F_363 ( V_101 ) , 0 ) ;
}
}
static void F_411 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
int V_101 = V_40 -> V_101 ;
if ( V_40 -> V_97 -> V_234 ) {
F_372 ( V_2 , V_101 , false ) ;
F_389 ( V_2 , V_101 , false ) ;
}
F_27 (dev, crtc, encoder)
V_47 -> V_576 ( V_47 ) ;
F_412 ( V_41 ) ;
F_98 ( V_41 ) ;
F_167 ( V_40 ) ;
F_290 ( V_40 , false ) ;
if ( V_40 -> V_97 -> V_234 )
F_305 ( V_41 ) ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_577 )
V_47 -> V_577 ( V_47 ) ;
if ( V_40 -> V_97 -> V_234 ) {
F_154 ( V_2 , V_101 ) ;
if ( F_105 ( V_44 ) ) {
T_5 V_9 ;
T_1 V_436 ;
V_9 = F_106 ( V_101 ) ;
V_436 = F_10 ( V_9 ) ;
V_436 &= ~ ( V_515 |
V_160 ) ;
V_436 |= V_578 ;
F_124 ( V_9 , V_436 ) ;
V_436 = F_10 ( V_508 ) ;
V_436 &= ~ ( F_350 ( V_101 ) | F_351 ( V_101 ) ) ;
F_124 ( V_508 , V_436 ) ;
}
F_304 ( V_40 ) ;
}
F_372 ( V_2 , V_101 , true ) ;
F_389 ( V_2 , V_101 , true ) ;
}
static void F_413 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
if ( V_40 -> V_97 -> V_234 )
F_389 ( V_2 , V_229 ,
false ) ;
F_27 (dev, crtc, encoder) {
F_410 ( V_47 , false ) ;
V_47 -> V_576 ( V_47 ) ;
}
F_412 ( V_41 ) ;
F_98 ( V_41 ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_167 ( V_40 ) ;
if ( V_40 -> V_97 -> V_573 )
F_409 ( V_41 , false ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_414 ( V_2 , V_103 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 9 )
F_359 ( V_40 ) ;
else
F_290 ( V_40 , false ) ;
if ( ! V_40 -> V_97 -> V_233 )
F_415 ( V_40 ) ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_577 )
V_47 -> V_577 ( V_47 ) ;
if ( V_40 -> V_97 -> V_234 ) {
F_157 ( V_2 ) ;
F_319 ( V_2 ) ;
F_416 ( V_41 ) ;
F_389 ( V_2 , V_229 ,
true ) ;
}
}
static void F_417 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_33 * V_34 = V_41 -> V_97 ;
if ( ! V_34 -> V_579 . V_580 )
return;
F_31 ( F_10 ( V_581 ) & V_582 ) ;
F_129 ( V_2 , V_41 -> V_101 ) ;
F_124 ( V_583 , V_34 -> V_579 . V_584 ) ;
F_124 ( V_581 , V_34 -> V_579 . V_580 ) ;
F_124 ( F_418 ( V_41 -> V_101 ) , 0 ) ;
}
static enum V_140 F_419 ( enum V_188 V_188 )
{
switch ( V_188 ) {
case V_585 :
return V_586 ;
case V_208 :
return V_587 ;
case V_210 :
return V_588 ;
case V_212 :
return V_589 ;
case V_590 :
return V_591 ;
default:
F_173 ( V_188 ) ;
return V_592 ;
}
}
static enum V_140 F_420 ( enum V_188 V_188 )
{
switch ( V_188 ) {
case V_585 :
return V_593 ;
case V_208 :
return V_594 ;
case V_210 :
return V_595 ;
case V_212 :
return V_596 ;
case V_590 :
return V_596 ;
default:
F_173 ( V_188 ) ;
return V_593 ;
}
}
enum V_140
F_421 ( struct V_46 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_203 * V_597 ;
switch ( V_46 -> type ) {
case V_598 :
F_47 ( ! F_22 ( V_44 ) ) ;
case V_503 :
case V_219 :
case V_504 :
V_597 = F_346 ( & V_46 -> V_45 ) ;
return F_419 ( V_597 -> V_188 ) ;
case V_599 :
V_597 = F_422 ( & V_46 -> V_45 ) -> V_95 ;
return F_419 ( V_597 -> V_188 ) ;
case V_600 :
return V_601 ;
case V_602 :
return V_603 ;
default:
return V_592 ;
}
}
enum V_140
F_423 ( struct V_46 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_45 . V_44 ;
struct V_203 * V_597 ;
switch ( V_46 -> type ) {
case V_598 :
case V_219 :
F_47 ( ! F_22 ( V_44 ) ) ;
case V_503 :
case V_504 :
V_597 = F_346 ( & V_46 -> V_45 ) ;
return F_420 ( V_597 -> V_188 ) ;
case V_599 :
V_597 = F_422 ( & V_46 -> V_45 ) -> V_95 ;
return F_420 ( V_597 -> V_188 ) ;
default:
F_173 ( V_46 -> type ) ;
return V_593 ;
}
}
static unsigned long F_424 ( struct V_93 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_604 * V_47 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_101 V_101 = V_40 -> V_101 ;
unsigned long V_605 ;
enum V_100 V_100 = V_48 -> V_103 ;
if ( ! V_48 -> V_45 . V_94 )
return 0 ;
V_605 = F_229 ( F_425 ( V_101 ) ) ;
V_605 |= F_229 ( F_83 ( V_100 ) ) ;
if ( V_48 -> V_435 . V_156 ||
V_48 -> V_435 . V_606 )
V_605 |= F_229 ( F_426 ( V_101 ) ) ;
F_427 (encoder, dev, crtc_state->base.encoder_mask) {
struct V_46 * V_46 = F_30 ( V_47 ) ;
V_605 |= F_229 ( F_421 ( V_46 ) ) ;
}
if ( V_48 -> V_216 )
V_605 |= F_229 ( V_607 ) ;
return V_605 ;
}
static unsigned long
F_428 ( struct V_93 * V_41 ,
struct V_33 * V_48 )
{
struct V_1 * V_2 = V_41 -> V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_140 V_608 ;
unsigned long V_609 , V_610 , V_611 ;
V_611 = V_40 -> V_612 ;
V_40 -> V_612 = V_610 =
F_424 ( V_41 , V_48 ) ;
V_609 = V_610 & ~ V_611 ;
F_429 (domain, domains)
F_430 ( V_2 , V_608 ) ;
return V_611 & ~ V_610 ;
}
static void F_431 ( struct V_1 * V_2 ,
unsigned long V_609 )
{
enum V_140 V_608 ;
F_429 (domain, domains)
F_85 ( V_2 , V_608 ) ;
}
static int F_432 ( struct V_1 * V_2 )
{
int V_613 = V_2 -> V_613 ;
if ( F_60 ( V_2 ) -> V_110 >= 9 ||
F_237 ( V_2 ) || F_238 ( V_2 ) )
return V_613 ;
else if ( F_16 ( V_2 ) )
return V_613 * 95 / 100 ;
else if ( F_60 ( V_2 ) -> V_110 < 4 )
return 2 * V_613 * 90 / 100 ;
else
return V_613 * 90 / 100 ;
}
static void F_433 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( F_434 ( V_44 ) || F_435 ( V_44 ) ) {
T_1 V_69 = F_10 ( V_614 ) & V_615 ;
if ( V_69 == V_616 )
V_2 -> V_613 = 675000 ;
else if ( V_69 == V_617 )
V_2 -> V_613 = 540000 ;
else if ( V_69 == V_618 )
V_2 -> V_613 = 450000 ;
else
V_2 -> V_613 = 337500 ;
} else if ( F_40 ( V_44 ) ) {
V_2 -> V_613 = 624000 ;
} else if ( F_238 ( V_44 ) ) {
if ( F_10 ( V_619 ) & V_620 )
V_2 -> V_613 = 450000 ;
else if ( F_436 ( V_44 ) )
V_2 -> V_613 = 450000 ;
else if ( F_437 ( V_44 ) )
V_2 -> V_613 = 540000 ;
else
V_2 -> V_613 = 675000 ;
} else if ( F_16 ( V_44 ) ) {
V_2 -> V_613 = 320000 ;
} else if ( F_15 ( V_44 ) ) {
V_2 -> V_613 = 400000 ;
} else {
V_2 -> V_613 = V_2 -> V_621 ;
}
V_2 -> V_622 = F_432 ( V_2 ) ;
F_19 ( L_84 ,
V_2 -> V_613 ) ;
F_19 ( L_85 ,
V_2 -> V_622 ) ;
}
static void F_438 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_621 = V_2 -> V_427 . V_623 ( V_44 ) ;
F_19 ( L_86 ,
V_2 -> V_621 ) ;
if ( F_15 ( V_44 ) || F_16 ( V_44 ) ) {
F_124 ( V_624 , F_185 ( V_2 -> V_621 , 1000 ) ) ;
}
if ( V_2 -> V_613 == 0 )
F_433 ( V_44 ) ;
}
static void F_439 ( struct V_1 * V_2 , int V_625 )
{
T_2 V_12 ;
T_2 V_626 ;
T_2 V_627 ;
int V_273 ;
switch ( V_625 ) {
case 144000 :
V_12 = V_628 ;
V_626 = F_440 ( 60 ) ;
break;
case 288000 :
V_12 = V_629 ;
V_626 = F_440 ( 60 ) ;
break;
case 384000 :
V_12 = V_630 ;
V_626 = F_440 ( 60 ) ;
break;
case 576000 :
V_12 = V_631 ;
V_626 = F_440 ( 60 ) ;
break;
case 624000 :
V_12 = V_631 ;
V_626 = F_440 ( 65 ) ;
break;
case 19200 :
V_626 = 0 ;
V_12 = 0 ;
break;
default:
F_127 ( L_87 , V_625 ) ;
return;
}
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_273 = F_366 ( V_2 , V_632 ,
0x80000000 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
if ( V_273 ) {
F_127 ( L_88 ,
V_273 , V_625 ) ;
return;
}
V_627 = F_10 ( V_633 ) & V_634 ;
V_627 = V_627 * 500 + 1000 ;
if ( V_625 == 19200 || V_625 == 624000 ||
V_627 == 624000 ) {
F_124 ( V_635 , ~ V_636 ) ;
if ( F_62 ( ! ( F_10 ( V_635 ) & V_637 ) ,
1 ) )
F_127 ( L_89 ) ;
}
if ( V_625 != 19200 ) {
T_2 V_11 ;
V_11 = F_10 ( V_638 ) ;
V_11 &= ~ V_639 ;
V_11 |= V_626 ;
F_124 ( V_638 , V_11 ) ;
F_124 ( V_635 , V_636 ) ;
if ( F_62 ( F_10 ( V_635 ) & V_637 , 1 ) )
F_127 ( L_90 ) ;
V_11 = F_10 ( V_633 ) ;
V_11 &= ~ V_640 ;
V_11 |= V_12 ;
V_11 &= ~ V_641 ;
if ( V_625 >= 500000 )
V_11 |= V_641 ;
V_11 &= ~ V_634 ;
V_11 |= ( V_625 - 1000 ) / 500 ;
F_124 ( V_633 , V_11 ) ;
}
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_273 = F_366 ( V_2 , V_632 ,
F_185 ( V_625 , 25000 ) ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
if ( V_273 ) {
F_127 ( L_91 ,
V_273 , V_625 ) ;
return;
}
F_438 ( V_2 -> V_44 ) ;
}
static bool F_441 ( struct V_1 * V_2 )
{
if ( ! ( F_10 ( V_635 ) & V_636 ) )
return false ;
if ( ! ( F_10 ( V_642 ) & V_643 ) ) {
F_19 ( L_92 ) ;
return false ;
}
if ( ! ( F_10 ( V_642 ) & V_644 ) ) {
F_19 ( L_93 ) ;
return false ;
}
return true ;
}
bool F_442 ( struct V_1 * V_2 )
{
return F_441 ( V_2 ) ;
}
void F_443 ( struct V_1 * V_2 )
{
if ( F_441 ( V_2 ) ) {
F_159 ( L_94 ) ;
return;
}
F_159 ( L_95 ) ;
F_439 ( V_2 , 624000 ) ;
F_124 ( V_642 , F_10 ( V_642 ) | V_643 ) ;
F_125 ( V_642 ) ;
F_126 ( 10 ) ;
if ( ! ( F_10 ( V_642 ) & V_644 ) )
F_127 ( L_96 ) ;
}
void F_444 ( struct V_1 * V_2 )
{
F_124 ( V_642 , F_10 ( V_642 ) & ~ V_643 ) ;
F_125 ( V_642 ) ;
F_126 ( 10 ) ;
if ( F_10 ( V_642 ) & V_644 )
F_127 ( L_97 ) ;
F_439 ( V_2 , 19200 ) ;
}
static unsigned int F_445 ( unsigned int V_645 )
{
return ( V_645 - 1000 ) / 500 ;
}
static unsigned int F_446 ( unsigned int V_645 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < F_180 ( V_646 ) ; V_54 ++ ) {
const struct V_647 * V_648 = & V_646 [ V_54 ] ;
if ( V_648 -> V_645 == V_645 )
return V_648 -> V_64 ;
}
return 8100 ;
}
static void
F_447 ( struct V_1 * V_2 , unsigned int V_649 )
{
unsigned int V_650 ;
T_1 V_11 ;
V_11 = F_10 ( V_633 ) ;
V_11 &= ~ V_651 | ~ V_634 ;
V_11 |= V_652 ;
if ( V_649 == 8640 )
V_650 = 308570 ;
else
V_650 = 337500 ;
V_11 = V_652 | F_445 ( V_650 ) ;
F_124 ( V_633 , V_11 ) ;
F_125 ( V_633 ) ;
V_11 = F_10 ( V_653 ) ;
V_11 &= ~ ( F_448 ( V_654 ) | F_449 ( V_654 ) |
F_450 ( V_654 ) ) ;
V_11 |= F_451 ( V_654 ) ;
if ( V_649 == 8640 )
V_11 |= F_452 ( V_655 ,
V_654 ) ;
else
V_11 |= F_452 ( V_656 ,
V_654 ) ;
F_124 ( V_653 , V_11 ) ;
F_125 ( V_653 ) ;
F_124 ( V_657 , F_10 ( V_657 ) | V_658 ) ;
if ( F_62 ( F_10 ( V_657 ) & V_659 , 5 ) )
F_127 ( L_98 ) ;
}
static bool F_453 ( struct V_1 * V_2 )
{
int V_273 ;
T_1 V_11 ;
V_11 = V_660 ;
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_273 = F_454 ( V_2 , V_661 , & V_11 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
return V_273 == 0 && ( V_11 & V_662 ) ;
}
static bool F_455 ( struct V_1 * V_2 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < 15 ; V_54 ++ ) {
if ( F_453 ( V_2 ) )
return true ;
F_126 ( 10 ) ;
}
return false ;
}
static void F_456 ( struct V_1 * V_2 , unsigned int V_645 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
T_1 V_663 , V_664 ;
F_19 ( L_99 , V_645 ) ;
if ( ! F_455 ( V_2 ) ) {
F_127 ( L_100 ) ;
return;
}
switch( V_645 ) {
case 450000 :
case 432000 :
V_663 = V_665 ;
V_664 = 1 ;
break;
case 540000 :
V_663 = V_666 ;
V_664 = 2 ;
break;
case 308570 :
case 337500 :
default:
V_663 = V_652 ;
V_664 = 0 ;
break;
case 617140 :
case 675000 :
V_663 = V_667 ;
V_664 = 3 ;
break;
}
F_124 ( V_633 , V_663 | F_445 ( V_645 ) ) ;
F_125 ( V_633 ) ;
F_2 ( & V_2 -> V_544 . V_545 ) ;
F_366 ( V_2 , V_661 , V_664 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
F_438 ( V_44 ) ;
}
void F_457 ( struct V_1 * V_2 )
{
F_124 ( V_642 , F_10 ( V_642 ) & ~ V_643 ) ;
F_125 ( V_642 ) ;
F_126 ( 10 ) ;
if ( F_10 ( V_642 ) & V_644 )
F_127 ( L_101 ) ;
F_124 ( V_657 , F_10 ( V_657 ) & ~ V_658 ) ;
if ( F_62 ( ! ( F_10 ( V_657 ) & V_659 ) , 1 ) )
F_127 ( L_102 ) ;
}
void F_458 ( struct V_1 * V_2 )
{
unsigned int V_649 ;
if ( ! ( F_10 ( V_657 ) & V_658 ) ) {
V_649 = F_446 ( V_2 -> V_668 ) ;
F_447 ( V_2 , V_649 ) ;
}
F_456 ( V_2 , V_2 -> V_668 ) ;
F_124 ( V_642 , F_10 ( V_642 ) | V_643 ) ;
F_125 ( V_642 ) ;
F_126 ( 10 ) ;
if ( ! ( F_10 ( V_642 ) & V_644 ) )
F_127 ( L_103 ) ;
}
int F_459 ( struct V_1 * V_2 )
{
T_2 V_669 = F_10 ( V_657 ) ;
T_2 V_670 = F_10 ( V_633 ) ;
int V_645 = V_2 -> V_668 ;
if ( ( F_10 ( F_460 ( 0x18 ) ) & 0x00FFFFFF ) == 0 )
goto V_671;
if ( ! ( ( V_669 & V_658 ) && ( V_669 & V_659 ) ) )
goto V_671;
if ( V_670 == ( ( V_670 & V_651 ) | F_445 ( V_645 ) ) )
return false ;
V_671:
V_2 -> V_668 = V_2 -> V_613 ;
F_458 ( V_2 ) ;
return true ;
}
static void F_461 ( struct V_43 * V_44 , int V_672 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 , V_673 ;
F_31 ( V_2 -> V_427 . V_623 ( V_44 )
!= V_2 -> V_621 ) ;
if ( V_672 >= 320000 )
V_673 = 2 ;
else if ( V_672 == 266667 )
V_673 = 1 ;
else
V_673 = 0 ;
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_11 = F_462 ( V_2 , V_674 ) ;
V_11 &= ~ V_675 ;
V_11 |= ( V_673 << V_676 ) ;
F_463 ( V_2 , V_674 , V_11 ) ;
if ( F_62 ( ( F_462 ( V_2 , V_674 ) &
V_677 ) == ( V_673 << V_678 ) ,
50 ) ) {
F_127 ( L_104 ) ;
}
F_4 ( & V_2 -> V_544 . V_545 ) ;
F_2 ( & V_2 -> V_5 ) ;
if ( V_672 == 400000 ) {
T_1 V_12 ;
V_12 = F_7 ( V_2 -> V_3 << 1 , V_672 ) - 1 ;
V_11 = F_3 ( V_2 , V_679 ) ;
V_11 &= ~ V_13 ;
V_11 |= V_12 ;
F_464 ( V_2 , V_679 , V_11 ) ;
if ( F_62 ( ( F_3 ( V_2 , V_679 ) &
V_14 ) == ( V_12 << V_15 ) ,
50 ) )
F_127 ( L_104 ) ;
}
V_11 = F_465 ( V_2 , V_680 ) ;
V_11 &= ~ 0x7f ;
if ( V_672 == 400000 )
V_11 |= 4500 / 250 ;
else
V_11 |= 3000 / 250 ;
F_466 ( V_2 , V_680 , V_11 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_438 ( V_44 ) ;
}
static void F_467 ( struct V_43 * V_44 , int V_672 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 , V_673 ;
F_31 ( V_2 -> V_427 . V_623 ( V_44 )
!= V_2 -> V_621 ) ;
switch ( V_672 ) {
case 333333 :
case 320000 :
case 266667 :
case 200000 :
break;
default:
F_173 ( V_672 ) ;
return;
}
V_673 = F_7 ( V_2 -> V_3 << 1 , V_672 ) - 1 ;
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_11 = F_462 ( V_2 , V_674 ) ;
V_11 &= ~ V_681 ;
V_11 |= ( V_673 << V_682 ) ;
F_463 ( V_2 , V_674 , V_11 ) ;
if ( F_62 ( ( F_462 ( V_2 , V_674 ) &
V_683 ) == ( V_673 << V_684 ) ,
50 ) ) {
F_127 ( L_104 ) ;
}
F_4 ( & V_2 -> V_544 . V_545 ) ;
F_438 ( V_44 ) ;
}
static int F_468 ( struct V_1 * V_2 ,
int V_685 )
{
int V_686 = ( V_2 -> V_3 << 1 ) % 320000 != 0 ? 333333 : 320000 ;
int V_69 = F_16 ( V_2 ) ? 95 : 90 ;
if ( ! F_16 ( V_2 ) &&
V_685 > V_686 * V_69 / 100 )
return 400000 ;
else if ( V_685 > 266667 * V_69 / 100 )
return V_686 ;
else if ( V_685 > 0 )
return 266667 ;
else
return 200000 ;
}
static int F_469 ( struct V_1 * V_2 ,
int V_685 )
{
if ( V_685 > 576000 * 9 / 10 )
return 624000 ;
else if ( V_685 > 384000 * 9 / 10 )
return 576000 ;
else if ( V_685 > 288000 * 9 / 10 )
return 384000 ;
else if ( V_685 > 144000 * 9 / 10 )
return 288000 ;
else
return 144000 ;
}
static int F_470 ( struct V_43 * V_44 ,
struct V_49 * V_39 )
{
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_93 * V_41 ;
struct V_38 * V_48 ;
unsigned V_685 = 0 , V_54 ;
enum V_101 V_101 ;
memcpy ( V_335 -> V_688 , V_2 -> V_688 ,
sizeof( V_335 -> V_688 ) ) ;
F_472 (state, crtc, crtc_state, i) {
int V_689 = 0 ;
if ( V_48 -> V_499 )
V_689 = V_48 -> V_98 . V_99 ;
V_335 -> V_688 [ V_54 ] = V_689 ;
}
F_90 (dev_priv, pipe)
V_685 = V_71 ( V_335 -> V_688 [ V_101 ] , V_685 ) ;
return V_685 ;
}
static int F_473 ( struct V_49 * V_39 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_685 = F_470 ( V_44 , V_39 ) ;
struct V_687 * V_335 =
F_471 ( V_39 ) ;
if ( V_685 < 0 )
return V_685 ;
V_335 -> V_672 = V_335 -> V_690 =
F_468 ( V_2 , V_685 ) ;
if ( ! V_335 -> V_691 )
V_335 -> V_690 = F_468 ( V_2 , 0 ) ;
return 0 ;
}
static int F_474 ( struct V_49 * V_39 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_685 = F_470 ( V_44 , V_39 ) ;
struct V_687 * V_335 =
F_471 ( V_39 ) ;
if ( V_685 < 0 )
return V_685 ;
V_335 -> V_672 = V_335 -> V_690 =
F_469 ( V_2 , V_685 ) ;
if ( ! V_335 -> V_691 )
V_335 -> V_690 = F_469 ( V_2 , 0 ) ;
return 0 ;
}
static void F_475 ( struct V_1 * V_2 )
{
unsigned int V_692 , V_693 ;
if ( F_16 ( V_2 ) )
V_693 = F_476 ( 12 ) ;
else
V_693 = F_476 ( 8 ) ;
if ( V_2 -> V_621 >= V_2 -> V_31 ) {
if ( F_16 ( V_2 ) )
V_692 = V_694 ;
else
V_692 = F_476 ( 15 ) ;
} else {
V_692 = V_693 ;
}
F_124 ( V_695 , V_696 |
V_693 ) ;
F_124 ( V_695 , V_696 |
V_692 | V_697 ) ;
F_31 ( F_10 ( V_695 ) & V_697 ) ;
}
static void F_477 ( struct V_49 * V_555 )
{
struct V_43 * V_44 = V_555 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_687 * V_698 =
F_471 ( V_555 ) ;
unsigned V_699 = V_698 -> V_690 ;
F_430 ( V_2 , V_700 ) ;
if ( F_16 ( V_44 ) )
F_467 ( V_44 , V_699 ) ;
else
F_461 ( V_44 , V_699 ) ;
F_475 ( V_2 ) ;
F_85 ( V_2 , V_700 ) ;
}
static void F_478 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_39 ) ;
int V_101 = V_40 -> V_101 ;
if ( F_31 ( V_40 -> V_94 ) )
return;
if ( V_40 -> V_97 -> V_510 )
F_391 ( V_40 , V_567 ) ;
F_392 ( V_40 ) ;
F_393 ( V_40 ) ;
if ( F_16 ( V_44 ) && V_101 == V_132 ) {
struct V_1 * V_2 = V_44 -> V_104 ;
F_124 ( F_479 ( V_101 ) , V_701 ) ;
F_124 ( F_480 ( V_101 ) , 0 ) ;
}
F_481 ( V_40 ) ;
V_40 -> V_94 = true ;
F_372 ( V_2 , V_101 , true ) ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_702 )
V_47 -> V_702 ( V_47 ) ;
if ( F_16 ( V_44 ) ) {
F_482 ( V_40 , V_40 -> V_97 ) ;
F_136 ( V_40 , V_40 -> V_97 ) ;
} else {
F_483 ( V_40 , V_40 -> V_97 ) ;
F_128 ( V_40 , V_40 -> V_97 ) ;
}
F_27 (dev, crtc, encoder)
if ( V_47 -> V_569 )
V_47 -> V_569 ( V_47 ) ;
F_417 ( V_40 ) ;
F_396 ( & V_34 -> V_45 ) ;
F_380 ( V_41 ) ;
F_158 ( V_40 ) ;
F_98 ( V_41 ) ;
F_397 ( V_41 ) ;
F_27 (dev, crtc, encoder)
V_47 -> V_499 ( V_47 ) ;
}
static void F_484 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
F_124 ( F_485 ( V_41 -> V_101 ) , V_41 -> V_97 -> V_184 . V_703 ) ;
F_124 ( F_486 ( V_41 -> V_101 ) , V_41 -> V_97 -> V_184 . V_704 ) ;
}
static void F_487 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_39 ) ;
enum V_101 V_101 = V_40 -> V_101 ;
if ( F_31 ( V_40 -> V_94 ) )
return;
F_484 ( V_40 ) ;
if ( V_40 -> V_97 -> V_510 )
F_391 ( V_40 , V_567 ) ;
F_392 ( V_40 ) ;
F_393 ( V_40 ) ;
F_481 ( V_40 ) ;
V_40 -> V_94 = true ;
if ( ! F_57 ( V_44 ) )
F_372 ( V_2 , V_101 , true ) ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_569 )
V_47 -> V_569 ( V_47 ) ;
F_139 ( V_40 ) ;
F_417 ( V_40 ) ;
F_396 ( & V_34 -> V_45 ) ;
F_380 ( V_41 ) ;
F_158 ( V_40 ) ;
F_98 ( V_41 ) ;
F_397 ( V_41 ) ;
F_27 (dev, crtc, encoder)
V_47 -> V_499 ( V_47 ) ;
}
static void F_488 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! V_41 -> V_97 -> V_579 . V_580 )
return;
F_129 ( V_2 , V_41 -> V_101 ) ;
F_19 ( L_105 ,
F_10 ( V_581 ) ) ;
F_124 ( V_581 , 0 ) ;
}
static void F_489 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_46 * V_47 ;
int V_101 = V_40 -> V_101 ;
if ( F_57 ( V_44 ) )
F_308 ( V_44 , V_101 ) ;
F_27 (dev, crtc, encoder)
V_47 -> V_576 ( V_47 ) ;
F_412 ( V_41 ) ;
F_98 ( V_41 ) ;
F_167 ( V_40 ) ;
F_488 ( V_40 ) ;
F_27 (dev, crtc, encoder)
if ( V_47 -> V_577 )
V_47 -> V_577 ( V_47 ) ;
if ( ! V_40 -> V_97 -> V_233 ) {
if ( F_16 ( V_44 ) )
F_144 ( V_2 , V_101 ) ;
else if ( F_15 ( V_44 ) )
F_143 ( V_2 , V_101 ) ;
else
F_142 ( V_40 ) ;
}
F_27 (dev, crtc, encoder)
if ( V_47 -> V_705 )
V_47 -> V_705 ( V_47 ) ;
if ( ! F_57 ( V_44 ) )
F_372 ( V_2 , V_101 , false ) ;
}
static void F_490 ( struct V_93 * V_41 )
{
struct V_46 * V_47 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_1 * V_2 = F_123 ( V_41 -> V_44 ) ;
enum V_140 V_608 ;
unsigned long V_609 ;
if ( ! V_40 -> V_94 )
return;
if ( F_217 ( V_41 -> V_95 -> V_39 ) -> V_337 ) {
F_31 ( V_40 -> V_433 ) ;
F_222 ( V_41 ) ;
F_385 ( V_41 , 1 << F_221 ( V_41 -> V_95 ) ) ;
F_217 ( V_41 -> V_95 -> V_39 ) -> V_337 = false ;
}
V_2 -> V_427 . V_706 ( V_41 ) ;
F_159 ( L_106 ,
V_41 -> V_45 . V_378 ) ;
F_31 ( F_491 ( V_41 -> V_39 , NULL ) < 0 ) ;
V_41 -> V_39 -> V_94 = false ;
V_40 -> V_94 = false ;
V_41 -> V_156 = false ;
V_41 -> V_39 -> V_707 = 0 ;
V_41 -> V_39 -> V_708 = 0 ;
F_27 (crtc->dev, crtc, encoder)
V_47 -> V_45 . V_41 = NULL ;
F_492 ( V_40 ) ;
F_380 ( V_41 ) ;
F_493 ( V_40 ) ;
V_609 = V_40 -> V_612 ;
F_429 (domain, domains)
F_85 ( V_2 , V_608 ) ;
V_40 -> V_612 = 0 ;
V_2 -> V_691 &= ~ ( 1 << V_40 -> V_101 ) ;
V_2 -> V_688 [ V_40 -> V_101 ] = 0 ;
}
int F_274 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_49 * V_39 ;
int V_273 ;
V_39 = F_494 ( V_44 ) ;
V_273 = F_495 ( V_39 ) ;
if ( V_273 )
F_127 ( L_107 , V_273 ) ;
else
V_2 -> V_709 = V_39 ;
return V_273 ;
}
void F_496 ( struct V_604 * V_47 )
{
struct V_46 * V_46 = F_30 ( V_47 ) ;
F_497 ( V_47 ) ;
F_218 ( V_46 ) ;
}
static void F_498 ( struct V_710 * V_51 )
{
struct V_93 * V_41 = V_51 -> V_45 . V_39 -> V_41 ;
F_159 ( L_108 ,
V_51 -> V_45 . V_45 . V_378 ,
V_51 -> V_45 . V_8 ) ;
if ( V_51 -> V_711 ( V_51 ) ) {
struct V_46 * V_47 = V_51 -> V_47 ;
struct V_52 * V_712 = V_51 -> V_45 . V_39 ;
F_65 ( ! V_41 ,
L_109 ) ;
if ( ! V_41 )
return;
F_65 ( ! V_41 -> V_39 -> V_94 ,
L_110 ) ;
if ( ! V_47 || V_47 -> type == V_599 )
return;
F_65 ( V_712 -> V_56 != & V_47 -> V_45 ,
L_111 ) ;
F_65 ( V_712 -> V_41 != V_47 -> V_45 . V_41 ,
L_112 ) ;
} else {
F_65 ( V_41 && V_41 -> V_39 -> V_94 ,
L_113 ) ;
F_65 ( ! V_41 && V_51 -> V_45 . V_39 -> V_56 ,
L_114 ) ;
}
}
int F_499 ( struct V_710 * V_51 )
{
F_500 ( & V_51 -> V_45 ) ;
if ( ! V_51 -> V_45 . V_39 )
return - V_713 ;
return 0 ;
}
struct V_710 * F_501 ( void )
{
struct V_710 * V_51 ;
V_51 = F_502 ( sizeof *V_51 , V_714 ) ;
if ( ! V_51 )
return NULL ;
if ( F_499 ( V_51 ) < 0 ) {
F_218 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
bool F_503 ( struct V_710 * V_51 )
{
enum V_101 V_101 = 0 ;
struct V_46 * V_47 = V_51 -> V_47 ;
return V_47 -> V_711 ( V_47 , & V_101 ) ;
}
static int F_504 ( struct V_33 * V_48 )
{
if ( V_48 -> V_45 . V_499 && V_48 -> V_234 )
return V_48 -> V_449 ;
return 0 ;
}
static int F_505 ( struct V_43 * V_44 , enum V_101 V_101 ,
struct V_33 * V_34 )
{
struct V_49 * V_39 = V_34 -> V_45 . V_39 ;
struct V_40 * V_715 ;
struct V_33 * V_716 ;
F_159 ( L_115 ,
F_77 ( V_101 ) , V_34 -> V_449 ) ;
if ( V_34 -> V_449 > 4 ) {
F_159 ( L_116 ,
F_77 ( V_101 ) , V_34 -> V_449 ) ;
return - V_533 ;
}
if ( F_237 ( V_44 ) || F_238 ( V_44 ) ) {
if ( V_34 -> V_449 > 2 ) {
F_159 ( L_117 ,
V_34 -> V_449 ) ;
return - V_533 ;
} else {
return 0 ;
}
}
if ( F_60 ( V_44 ) -> V_717 == 2 )
return 0 ;
switch ( V_101 ) {
case V_123 :
return 0 ;
case V_132 :
if ( V_34 -> V_449 <= 2 )
return 0 ;
V_715 = F_50 ( F_506 ( V_44 , V_502 ) ) ;
V_716 =
F_507 ( V_39 , V_715 ) ;
if ( F_508 ( V_716 ) )
return F_509 ( V_716 ) ;
if ( F_504 ( V_716 ) > 0 ) {
F_159 ( L_118 ,
F_77 ( V_101 ) , V_34 -> V_449 ) ;
return - V_533 ;
}
return 0 ;
case V_502 :
if ( V_34 -> V_449 > 2 ) {
F_159 ( L_119 ,
F_77 ( V_101 ) , V_34 -> V_449 ) ;
return - V_533 ;
}
V_715 = F_50 ( F_506 ( V_44 , V_132 ) ) ;
V_716 =
F_507 ( V_39 , V_715 ) ;
if ( F_508 ( V_716 ) )
return F_509 ( V_716 ) ;
if ( F_504 ( V_716 ) > 2 ) {
F_159 ( L_120 ) ;
return - V_533 ;
}
return 0 ;
default:
F_146 () ;
}
}
static int F_510 ( struct V_40 * V_40 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
const struct V_511 * V_98 = & V_34 -> V_45 . V_98 ;
int V_718 , V_719 , V_720 , V_273 ;
bool V_721 = false ;
V_454:
V_719 = F_21 ( F_123 ( V_44 ) , V_34 ) ;
V_720 = V_98 -> V_99 ;
V_718 = F_511 ( V_720 , V_719 ,
V_34 -> V_722 ) ;
V_34 -> V_449 = V_718 ;
F_512 ( V_34 -> V_722 , V_718 , V_720 ,
V_719 , & V_34 -> V_568 ) ;
V_273 = F_505 ( V_44 , V_40 -> V_101 , V_34 ) ;
if ( V_273 == - V_533 && V_34 -> V_722 > 6 * 3 ) {
V_34 -> V_722 -= 2 * 3 ;
F_159 ( L_121 ,
V_34 -> V_722 ) ;
V_721 = true ;
V_34 -> V_723 = true ;
goto V_454;
}
if ( V_721 )
return V_724 ;
return V_273 ;
}
static bool F_513 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_722 > 24 )
return false ;
if ( F_237 ( V_2 ) )
return true ;
return F_514 ( V_34 ) <=
V_2 -> V_613 * 95 / 100 ;
}
static void F_515 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
V_34 -> V_543 = V_725 . V_726 &&
F_398 ( V_41 ) &&
F_513 ( V_2 , V_34 ) ;
}
static bool F_516 ( const struct V_40 * V_41 )
{
const struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
return F_60 ( V_2 ) -> V_110 < 4 &&
( V_41 -> V_101 == V_123 || F_517 ( V_2 ) ) ;
}
static int F_518 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
const struct V_511 * V_98 = & V_34 -> V_45 . V_98 ;
if ( F_60 ( V_44 ) -> V_110 < 4 ) {
int V_727 = V_2 -> V_613 * 9 / 10 ;
if ( F_516 ( V_41 ) &&
V_98 -> V_99 > V_727 ) {
V_727 *= 2 ;
V_34 -> V_237 = true ;
}
if ( V_98 -> V_99 > V_727 ) {
F_159 ( L_122 ,
V_98 -> V_99 , V_727 ,
F_519 ( V_34 -> V_237 ) ) ;
return - V_533 ;
}
}
if ( ( F_28 ( V_34 , V_73 ) &&
F_42 ( V_44 ) ) || V_34 -> V_237 )
V_34 -> V_362 &= ~ 1 ;
if ( ( F_60 ( V_44 ) -> V_110 > 4 || F_17 ( V_44 ) ) &&
V_98 -> V_728 == V_98 -> V_535 )
return - V_533 ;
if ( F_399 ( V_44 ) )
F_515 ( V_41 , V_34 ) ;
if ( V_34 -> V_234 )
return F_510 ( V_41 , V_34 ) ;
return 0 ;
}
static int F_520 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
T_2 V_669 = F_10 ( V_657 ) ;
T_2 V_670 = F_10 ( V_633 ) ;
T_2 V_729 ;
if ( ! ( V_669 & V_658 ) )
return 24000 ;
if ( ( V_670 & V_651 ) == V_666 )
return 540000 ;
V_729 = ( F_10 ( V_653 ) &
F_450 ( V_654 ) ) >> 1 ;
if ( V_729 == V_730 ||
V_729 == V_655 ) {
switch ( V_670 & V_651 ) {
case V_665 :
return 432000 ;
case V_652 :
return 308570 ;
case V_667 :
return 617140 ;
default:
F_6 ( 1 , L_123 ) ;
}
} else {
switch ( V_670 & V_651 ) {
case V_665 :
return 450000 ;
case V_652 :
return 337500 ;
case V_667 :
return 675000 ;
default:
F_6 ( 1 , L_123 ) ;
}
}
return 24000 ;
}
static int F_521 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
T_2 V_670 = F_10 ( V_633 ) ;
T_2 V_731 = F_10 ( V_638 ) & V_639 ;
T_2 V_732 = F_10 ( V_635 ) ;
int V_672 ;
if ( ! ( V_732 & V_636 ) )
return 19200 ;
V_672 = 19200 * V_731 / 2 ;
switch ( V_670 & V_640 ) {
case V_631 :
return V_672 ;
case V_630 :
return V_672 * 2 / 3 ;
case V_629 :
return V_672 / 2 ;
case V_628 :
return V_672 / 4 ;
}
return 19200 ;
}
static int F_522 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_733 = F_10 ( V_734 ) ;
T_2 V_645 = V_733 & V_735 ;
if ( V_733 & V_736 )
return 800000 ;
else if ( F_10 ( V_619 ) & V_620 )
return 450000 ;
else if ( V_645 == V_737 )
return 450000 ;
else if ( V_645 == V_738 )
return 540000 ;
else if ( V_645 == V_739 )
return 337500 ;
else
return 675000 ;
}
static int F_523 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_733 = F_10 ( V_734 ) ;
T_2 V_645 = V_733 & V_735 ;
if ( V_733 & V_736 )
return 800000 ;
else if ( F_10 ( V_619 ) & V_620 )
return 450000 ;
else if ( V_645 == V_737 )
return 450000 ;
else if ( F_524 ( V_44 ) )
return 337500 ;
else
return 540000 ;
}
static int F_525 ( struct V_43 * V_44 )
{
return F_8 ( F_123 ( V_44 ) , L_124 ,
V_679 ) ;
}
static int F_526 ( struct V_43 * V_44 )
{
return 450000 ;
}
static int F_527 ( struct V_43 * V_44 )
{
return 400000 ;
}
static int F_528 ( struct V_43 * V_44 )
{
return 333333 ;
}
static int F_529 ( struct V_43 * V_44 )
{
return 200000 ;
}
static int F_530 ( struct V_43 * V_44 )
{
T_7 V_740 = 0 ;
F_531 ( V_44 -> V_741 , V_742 , & V_740 ) ;
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
F_127 ( L_125 , V_740 ) ;
case V_748 :
return 133333 ;
case V_749 :
return 166667 ;
}
}
static int F_532 ( struct V_43 * V_44 )
{
T_7 V_740 = 0 ;
F_531 ( V_44 -> V_741 , V_742 , & V_740 ) ;
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
static int F_533 ( struct V_43 * V_44 )
{
return 266667 ;
}
static int F_534 ( struct V_43 * V_44 )
{
T_7 V_753 = 0 ;
if ( V_44 -> V_741 -> V_754 == 0x1 )
return 133333 ;
F_535 ( V_44 -> V_741 -> V_755 ,
F_536 ( 0 , 3 ) , V_756 , & V_753 ) ;
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
static int F_537 ( struct V_43 * V_44 )
{
return 133333 ;
}
static unsigned int F_538 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
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
unsigned int V_64 ;
T_8 V_189 = 0 ;
if ( F_539 ( V_44 ) )
V_771 = V_770 ;
else if ( F_17 ( V_44 ) )
V_771 = V_769 ;
else if ( F_188 ( V_44 ) )
V_771 = V_768 ;
else if ( F_18 ( V_44 ) )
V_771 = V_767 ;
else if ( F_540 ( V_44 ) )
V_771 = V_766 ;
else
return 0 ;
V_189 = F_10 ( F_140 ( V_44 ) ? V_772 : V_773 ) ;
V_64 = V_771 [ V_189 & 0x7 ] ;
if ( V_64 == 0 )
F_127 ( L_126 , V_189 ) ;
else
F_159 ( L_127 , V_64 ) ;
return V_64 ;
}
static int F_541 ( struct V_43 * V_44 )
{
unsigned int V_774 , V_64 = F_538 ( V_44 ) ;
T_9 V_189 = 0 ;
F_531 ( V_44 -> V_741 , V_742 , & V_189 ) ;
V_774 = ( V_189 >> 12 ) & 0x1 ;
switch ( V_64 ) {
case 2666667 :
case 4000000 :
case 5333333 :
return V_774 ? 333333 : 222222 ;
case 3200000 :
return V_774 ? 320000 : 228571 ;
default:
F_127 ( L_128 , V_64 , V_189 ) ;
return 222222 ;
}
}
static int F_542 ( struct V_43 * V_44 )
{
static const T_8 V_775 [] = { 16 , 10 , 8 } ;
static const T_8 V_776 [] = { 20 , 12 , 10 } ;
static const T_8 V_777 [] = { 24 , 16 , 14 } ;
const T_8 * V_778 ;
unsigned int V_774 , V_64 = F_538 ( V_44 ) ;
T_9 V_189 = 0 ;
F_531 ( V_44 -> V_741 , V_742 , & V_189 ) ;
V_774 = ( ( V_189 >> 8 ) & 0x1f ) - 1 ;
if ( V_774 >= F_180 ( V_775 ) )
goto V_779;
switch ( V_64 ) {
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
return F_7 ( V_64 , V_778 [ V_774 ] ) ;
V_779:
F_127 ( L_129 , V_64 , V_189 ) ;
return 200000 ;
}
static int F_543 ( struct V_43 * V_44 )
{
static const T_8 V_775 [] = { 12 , 10 , 8 , 7 , 5 , 16 } ;
static const T_8 V_776 [] = { 14 , 12 , 10 , 8 , 6 , 20 } ;
static const T_8 V_780 [] = { 20 , 14 , 12 , 10 , 8 , 24 } ;
static const T_8 V_777 [] = { 20 , 16 , 12 , 12 , 8 , 28 } ;
const T_8 * V_778 ;
unsigned int V_774 , V_64 = F_538 ( V_44 ) ;
T_9 V_189 = 0 ;
F_531 ( V_44 -> V_741 , V_742 , & V_189 ) ;
V_774 = ( V_189 >> 4 ) & 0x7 ;
if ( V_774 >= F_180 ( V_775 ) )
goto V_779;
switch ( V_64 ) {
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
return F_7 ( V_64 , V_778 [ V_774 ] ) ;
V_779:
F_127 ( L_130 , V_64 , V_189 ) ;
return 190476 ;
}
static void
F_544 ( T_2 * V_781 , T_2 * V_782 )
{
while ( * V_781 > V_783 ||
* V_782 > V_783 ) {
* V_781 >>= 1 ;
* V_782 >>= 1 ;
}
}
static void F_545 ( unsigned int V_58 , unsigned int V_63 ,
T_2 * V_784 , T_2 * V_785 )
{
* V_785 = F_546 (unsigned int, roundup_pow_of_two(n), DATA_LINK_N_MAX) ;
* V_784 = F_48 ( ( V_68 ) V_58 * * V_785 , V_63 ) ;
F_544 ( V_784 , V_785 ) ;
}
void
F_512 ( int V_786 , int V_787 ,
int V_788 , int V_789 ,
struct V_790 * V_791 )
{
V_791 -> V_792 = 64 ;
F_545 ( V_786 * V_788 ,
V_789 * V_787 * 8 ,
& V_791 -> V_793 , & V_791 -> V_794 ) ;
F_545 ( V_788 , V_789 ,
& V_791 -> V_795 , & V_791 -> V_796 ) ;
}
static inline bool F_547 ( struct V_1 * V_2 )
{
if ( V_725 . V_797 >= 0 )
return V_725 . V_797 != 0 ;
return V_2 -> V_798 . V_799
&& ! ( V_2 -> V_142 & V_800 ) ;
}
static T_2 F_548 ( struct V_66 * V_66 )
{
return ( 1 << V_66 -> V_63 ) << 16 | V_66 -> V_59 ;
}
static T_2 F_549 ( struct V_66 * V_66 )
{
return V_66 -> V_63 << 16 | V_66 -> V_67 << 8 | V_66 -> V_59 ;
}
static void F_550 ( struct V_40 * V_41 ,
struct V_33 * V_48 ,
T_3 * V_801 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
T_1 V_802 , V_803 = 0 ;
if ( F_18 ( V_44 ) ) {
V_802 = F_548 ( & V_48 -> V_66 ) ;
if ( V_801 )
V_803 = F_548 ( V_801 ) ;
} else {
V_802 = F_549 ( & V_48 -> V_66 ) ;
if ( V_801 )
V_803 = F_549 ( V_801 ) ;
}
V_48 -> V_184 . V_703 = V_802 ;
V_41 -> V_804 = false ;
if ( F_28 ( V_48 , V_73 ) &&
V_801 ) {
V_48 -> V_184 . V_704 = V_803 ;
V_41 -> V_804 = true ;
} else {
V_48 -> V_184 . V_704 = V_802 ;
}
}
static void F_551 ( struct V_1 * V_2 , enum V_101
V_101 )
{
T_1 V_805 ;
V_805 = F_133 ( V_2 , V_101 , F_552 ( 1 ) ) ;
V_805 &= 0xffffff00 ;
V_805 |= 0x00000030 ;
F_135 ( V_2 , V_101 , F_552 ( 1 ) , V_805 ) ;
V_805 = F_133 ( V_2 , V_101 , V_806 ) ;
V_805 &= 0x8cffffff ;
V_805 = 0x8c000000 ;
F_135 ( V_2 , V_101 , V_806 , V_805 ) ;
V_805 = F_133 ( V_2 , V_101 , F_552 ( 1 ) ) ;
V_805 &= 0xffffff00 ;
F_135 ( V_2 , V_101 , F_552 ( 1 ) , V_805 ) ;
V_805 = F_133 ( V_2 , V_101 , V_806 ) ;
V_805 &= 0x00ffffff ;
V_805 |= 0xb0000000 ;
F_135 ( V_2 , V_101 , V_806 , V_805 ) ;
}
static void F_553 ( struct V_40 * V_41 ,
struct V_790 * V_791 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_41 -> V_101 ;
F_124 ( F_554 ( V_101 ) , F_555 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_124 ( F_556 ( V_101 ) , V_791 -> V_794 ) ;
F_124 ( F_557 ( V_101 ) , V_791 -> V_795 ) ;
F_124 ( F_558 ( V_101 ) , V_791 -> V_796 ) ;
}
static void F_394 ( struct V_40 * V_41 ,
struct V_790 * V_791 ,
struct V_790 * V_807 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_41 -> V_101 ;
enum V_100 V_100 = V_41 -> V_97 -> V_103 ;
if ( F_60 ( V_44 ) -> V_110 >= 5 ) {
F_124 ( F_349 ( V_100 ) , F_555 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_124 ( F_559 ( V_100 ) , V_791 -> V_794 ) ;
F_124 ( F_560 ( V_100 ) , V_791 -> V_795 ) ;
F_124 ( F_561 ( V_100 ) , V_791 -> V_796 ) ;
if ( V_807 && ( F_16 ( V_44 ) || F_60 ( V_44 ) -> V_110 < 8 ) &&
V_41 -> V_97 -> V_808 ) {
F_124 ( F_562 ( V_100 ) ,
F_555 ( V_807 -> V_792 ) | V_807 -> V_793 ) ;
F_124 ( F_563 ( V_100 ) , V_807 -> V_794 ) ;
F_124 ( F_564 ( V_100 ) , V_807 -> V_795 ) ;
F_124 ( F_565 ( V_100 ) , V_807 -> V_796 ) ;
}
} else {
F_124 ( F_566 ( V_101 ) , F_555 ( V_791 -> V_792 ) | V_791 -> V_793 ) ;
F_124 ( F_567 ( V_101 ) , V_791 -> V_794 ) ;
F_124 ( F_568 ( V_101 ) , V_791 -> V_795 ) ;
F_124 ( F_569 ( V_101 ) , V_791 -> V_796 ) ;
}
}
void F_391 ( struct V_40 * V_41 , enum V_809 V_791 )
{
struct V_790 * V_810 , * V_811 = NULL ;
if ( V_791 == V_567 ) {
V_810 = & V_41 -> V_97 -> V_810 ;
V_811 = & V_41 -> V_97 -> V_811 ;
} else if ( V_791 == V_812 ) {
V_810 = & V_41 -> V_97 -> V_811 ;
} else {
F_127 ( L_131 ) ;
return;
}
if ( V_41 -> V_97 -> V_234 )
F_553 ( V_41 , & V_41 -> V_97 -> V_810 ) ;
else
F_394 ( V_41 , V_810 , V_811 ) ;
}
static void F_570 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
V_34 -> V_184 . V_66 = V_199 |
V_200 | V_195 ;
if ( V_41 -> V_101 != V_123 )
V_34 -> V_184 . V_66 |= V_201 ;
if ( ! V_34 -> V_233 )
V_34 -> V_184 . V_66 |= V_113 |
V_813 ;
V_34 -> V_184 . V_186 =
( V_34 -> V_572 - 1 ) << V_814 ;
}
static void F_571 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
V_34 -> V_184 . V_66 = V_202 |
V_200 | V_195 ;
if ( V_41 -> V_101 != V_123 )
V_34 -> V_184 . V_66 |= V_201 ;
if ( ! V_34 -> V_233 )
V_34 -> V_184 . V_66 |= V_113 ;
V_34 -> V_184 . V_186 =
( V_34 -> V_572 - 1 ) << V_814 ;
}
static void F_483 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
T_1 V_815 ;
T_1 V_816 , V_817 , V_818 , V_819 , V_820 ;
T_1 V_821 , V_805 ;
F_124 ( F_64 ( V_101 ) ,
V_34 -> V_184 . V_66 &
~ ( V_113 | V_813 ) ) ;
if ( ( V_34 -> V_184 . V_66 & V_113 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_816 = V_34 -> V_66 . V_63 ;
V_817 = V_34 -> V_66 . V_67 ;
V_818 = V_34 -> V_66 . V_59 ;
V_819 = V_34 -> V_66 . V_61 ;
V_820 = V_34 -> V_66 . V_62 ;
if ( V_101 == V_132 )
F_551 ( V_2 , V_101 ) ;
F_135 ( V_2 , V_101 , V_822 , 0x0100000f ) ;
V_805 = F_133 ( V_2 , V_101 , F_572 ( V_101 ) ) ;
V_805 &= 0x00ffffff ;
F_135 ( V_2 , V_101 , F_572 ( V_101 ) , V_805 ) ;
F_135 ( V_2 , V_101 , V_823 , 0x610 ) ;
V_815 = ( ( V_817 << V_824 ) | ( V_818 & V_825 ) ) ;
V_815 |= ( ( V_819 << V_826 ) | ( V_820 << V_827 ) ) ;
V_815 |= ( ( V_816 << V_828 ) ) ;
V_815 |= ( 1 << V_829 ) ;
V_815 |= ( V_830 << V_831 ) ;
F_135 ( V_2 , V_101 , F_573 ( V_101 ) , V_815 ) ;
V_815 |= V_832 ;
F_135 ( V_2 , V_101 , F_573 ( V_101 ) , V_815 ) ;
if ( V_34 -> V_35 == 162000 ||
F_26 ( V_41 , V_600 ) ||
F_26 ( V_41 , V_219 ) )
F_135 ( V_2 , V_101 , F_574 ( V_101 ) ,
0x009f0003 ) ;
else
F_135 ( V_2 , V_101 , F_574 ( V_101 ) ,
0x00d0000f ) ;
if ( V_34 -> V_510 ) {
if ( V_101 == V_123 )
F_135 ( V_2 , V_101 , F_575 ( V_101 ) ,
0x0df40000 ) ;
else
F_135 ( V_2 , V_101 , F_575 ( V_101 ) ,
0x0df70000 ) ;
} else {
if ( V_101 == V_123 )
F_135 ( V_2 , V_101 , F_575 ( V_101 ) ,
0x0df70000 ) ;
else
F_135 ( V_2 , V_101 , F_575 ( V_101 ) ,
0x0df40000 ) ;
}
V_821 = F_133 ( V_2 , V_101 , F_576 ( V_101 ) ) ;
V_821 = ( V_821 & 0x0000ff00 ) | 0x01c00000 ;
if ( F_26 ( V_41 , V_503 ) ||
F_26 ( V_41 , V_504 ) )
V_821 |= 0x01000000 ;
F_135 ( V_2 , V_101 , F_576 ( V_101 ) , V_821 ) ;
F_135 ( V_2 , V_101 , F_577 ( V_101 ) , 0x87871000 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_482 ( struct V_40 * V_41 ,
const struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
enum V_187 V_188 = F_132 ( V_101 ) ;
T_1 V_833 , V_834 ;
T_1 V_816 , V_817 , V_818 , V_819 , V_820 , V_835 ;
T_1 V_836 ;
int V_64 ;
F_124 ( F_64 ( V_101 ) ,
V_34 -> V_184 . V_66 & ~ V_113 ) ;
if ( ( V_34 -> V_184 . V_66 & V_113 ) == 0 )
return;
V_816 = V_34 -> V_66 . V_63 ;
V_835 = V_34 -> V_66 . V_59 & 0x3fffff ;
V_817 = V_34 -> V_66 . V_67 ;
V_818 = V_34 -> V_66 . V_59 >> 22 ;
V_819 = V_34 -> V_66 . V_61 ;
V_820 = V_34 -> V_66 . V_62 ;
V_64 = V_34 -> V_66 . V_64 ;
V_836 = 0 ;
V_833 = 0 ;
F_2 ( & V_2 -> V_5 ) ;
F_135 ( V_2 , V_101 , F_578 ( V_188 ) ,
5 << V_837 |
V_819 << V_838 |
V_820 << V_839 |
1 << V_840 ) ;
F_135 ( V_2 , V_101 , F_579 ( V_188 ) , V_818 ) ;
F_135 ( V_2 , V_101 , F_580 ( V_188 ) ,
V_841 |
1 << V_842 ) ;
F_135 ( V_2 , V_101 , F_581 ( V_188 ) , V_835 ) ;
V_836 = F_133 ( V_2 , V_101 , F_582 ( V_188 ) ) ;
V_836 &= ~ ( V_843 | V_844 ) ;
V_836 |= ( 2 << V_845 ) ;
if ( V_835 )
V_836 |= V_844 ;
F_135 ( V_2 , V_101 , F_582 ( V_188 ) , V_836 ) ;
V_836 = F_133 ( V_2 , V_101 , F_583 ( V_188 ) ) ;
V_836 &= ~ ( V_846 |
V_847 ) ;
V_836 |= ( 0x5 << V_848 ) ;
if ( ! V_835 )
V_836 |= V_847 ;
F_135 ( V_2 , V_101 , F_583 ( V_188 ) , V_836 ) ;
if ( V_64 == 5400000 ) {
V_833 |= ( 0x3 << V_849 ) ;
V_833 |= ( 0x8 << V_850 ) ;
V_833 |= ( 0x1 << V_851 ) ;
V_834 = 0x9 ;
} else if ( V_64 <= 6200000 ) {
V_833 |= ( 0x5 << V_849 ) ;
V_833 |= ( 0xB << V_850 ) ;
V_833 |= ( 0x3 << V_851 ) ;
V_834 = 0x9 ;
} else if ( V_64 <= 6480000 ) {
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
F_135 ( V_2 , V_101 , F_584 ( V_188 ) , V_833 ) ;
V_836 = F_133 ( V_2 , V_101 , F_585 ( V_188 ) ) ;
V_836 &= ~ V_852 ;
V_836 |= ( V_834 << V_853 ) ;
F_135 ( V_2 , V_101 , F_585 ( V_188 ) , V_836 ) ;
F_135 ( V_2 , V_101 , F_134 ( V_188 ) ,
F_133 ( V_2 , V_101 , F_134 ( V_188 ) ) |
V_854 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
int F_586 ( struct V_43 * V_44 , enum V_101 V_101 ,
const struct V_66 * V_66 )
{
struct V_40 * V_41 =
F_50 ( F_506 ( V_44 , V_101 ) ) ;
struct V_33 * V_34 ;
V_34 = F_502 ( sizeof( * V_34 ) , V_714 ) ;
if ( ! V_34 )
return - V_713 ;
V_34 -> V_45 . V_41 = & V_41 -> V_45 ;
V_34 -> V_572 = 1 ;
V_34 -> V_66 = * V_66 ;
if ( F_16 ( V_44 ) ) {
F_571 ( V_41 , V_34 ) ;
F_482 ( V_41 , V_34 ) ;
F_136 ( V_41 , V_34 ) ;
} else {
F_570 ( V_41 , V_34 ) ;
F_483 ( V_41 , V_34 ) ;
F_128 ( V_41 , V_34 ) ;
}
F_218 ( V_34 ) ;
return 0 ;
}
void F_587 ( struct V_43 * V_44 , enum V_101 V_101 )
{
if ( F_16 ( V_44 ) )
F_144 ( F_123 ( V_44 ) , V_101 ) ;
else
F_143 ( F_123 ( V_44 ) , V_101 ) ;
}
static void F_588 ( struct V_40 * V_41 ,
struct V_33 * V_48 ,
T_3 * V_801 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_66 ;
bool V_855 ;
struct V_66 * clock = & V_48 -> V_66 ;
F_550 ( V_41 , V_48 , V_801 ) ;
V_855 = F_28 ( V_48 , V_224 ) ||
F_28 ( V_48 , V_219 ) ;
V_66 = V_195 ;
if ( F_28 ( V_48 , V_73 ) )
V_66 |= V_856 ;
else
V_66 |= V_857 ;
if ( F_589 ( V_44 ) || F_590 ( V_44 ) || F_540 ( V_44 ) ) {
V_66 |= ( V_48 -> V_572 - 1 )
<< V_858 ;
}
if ( V_855 )
V_66 |= V_859 ;
if ( V_48 -> V_510 )
V_66 |= V_859 ;
if ( F_18 ( V_44 ) )
V_66 |= ( 1 << ( clock -> V_61 - 1 ) ) << V_860 ;
else {
V_66 |= ( 1 << ( clock -> V_61 - 1 ) ) << V_861 ;
if ( F_17 ( V_44 ) && V_801 )
V_66 |= ( 1 << ( V_801 -> V_61 - 1 ) ) << V_862 ;
}
switch ( clock -> V_62 ) {
case 5 :
V_66 |= V_863 ;
break;
case 7 :
V_66 |= V_864 ;
break;
case 10 :
V_66 |= V_865 ;
break;
case 14 :
V_66 |= V_866 ;
break;
}
if ( F_60 ( V_44 ) -> V_110 >= 4 )
V_66 |= ( 6 << V_867 ) ;
if ( V_48 -> V_868 )
V_66 |= V_869 ;
else if ( F_28 ( V_48 , V_73 ) &&
F_547 ( V_2 ) )
V_66 |= V_870 ;
else
V_66 |= V_871 ;
V_66 |= V_113 ;
V_48 -> V_184 . V_66 = V_66 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
T_1 V_186 = ( V_48 -> V_572 - 1 )
<< V_814 ;
V_48 -> V_184 . V_186 = V_186 ;
}
}
static void F_591 ( struct V_40 * V_41 ,
struct V_33 * V_48 ,
T_3 * V_801 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_66 ;
struct V_66 * clock = & V_48 -> V_66 ;
F_550 ( V_41 , V_48 , V_801 ) ;
V_66 = V_195 ;
if ( F_28 ( V_48 , V_73 ) ) {
V_66 |= ( 1 << ( clock -> V_61 - 1 ) ) << V_861 ;
} else {
if ( clock -> V_61 == 2 )
V_66 |= V_872 ;
else
V_66 |= ( clock -> V_61 - 2 ) << V_861 ;
if ( clock -> V_62 == 4 )
V_66 |= V_873 ;
}
if ( ! F_141 ( V_44 ) && F_28 ( V_48 , V_197 ) )
V_66 |= V_198 ;
if ( F_28 ( V_48 , V_73 ) &&
F_547 ( V_2 ) )
V_66 |= V_870 ;
else
V_66 |= V_871 ;
V_66 |= V_113 ;
V_48 -> V_184 . V_66 = V_66 ;
}
static void F_392 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_40 -> V_101 ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
const struct V_511 * V_98 = & V_40 -> V_97 -> V_45 . V_98 ;
T_2 V_874 , V_875 ;
int V_876 = 0 ;
V_874 = V_98 -> V_874 ;
V_875 = V_98 -> V_875 ;
if ( V_98 -> V_326 & V_877 ) {
V_874 -= 1 ;
V_875 -= 1 ;
if ( F_26 ( V_40 , V_224 ) )
V_876 = ( V_98 -> V_878 - 1 ) / 2 ;
else
V_876 = V_98 -> V_728 -
V_98 -> V_878 / 2 ;
if ( V_876 < 0 )
V_876 += V_98 -> V_878 ;
}
if ( F_60 ( V_44 ) -> V_110 > 3 )
F_124 ( F_342 ( V_103 ) , V_876 ) ;
F_124 ( F_330 ( V_103 ) ,
( V_98 -> V_535 - 1 ) |
( ( V_98 -> V_878 - 1 ) << 16 ) ) ;
F_124 ( F_332 ( V_103 ) ,
( V_98 -> V_879 - 1 ) |
( ( V_98 -> V_880 - 1 ) << 16 ) ) ;
F_124 ( F_334 ( V_103 ) ,
( V_98 -> V_728 - 1 ) |
( ( V_98 -> V_881 - 1 ) << 16 ) ) ;
F_124 ( F_336 ( V_103 ) ,
( V_98 -> V_536 - 1 ) |
( ( V_874 - 1 ) << 16 ) ) ;
F_124 ( F_338 ( V_103 ) ,
( V_98 -> V_882 - 1 ) |
( ( V_875 - 1 ) << 16 ) ) ;
F_124 ( F_340 ( V_103 ) ,
( V_98 -> V_883 - 1 ) |
( ( V_98 -> V_884 - 1 ) << 16 ) ) ;
if ( F_237 ( V_44 ) && V_103 == V_571 &&
( V_101 == V_132 || V_101 == V_502 ) )
F_124 ( F_336 ( V_101 ) , F_10 ( F_336 ( V_103 ) ) ) ;
}
static void F_393 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_40 -> V_101 ;
F_124 ( F_287 ( V_101 ) ,
( ( V_40 -> V_97 -> V_362 - 1 ) << 16 ) |
( V_40 -> V_97 -> V_361 - 1 ) ) ;
}
static void F_592 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_100 V_103 = V_34 -> V_103 ;
T_2 V_189 ;
V_189 = F_10 ( F_330 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_535 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_878 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_189 = F_10 ( F_332 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_879 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_880 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_189 = F_10 ( F_334 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_728 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_881 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_189 = F_10 ( F_336 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_536 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_874 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_189 = F_10 ( F_338 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_882 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_875 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_189 = F_10 ( F_340 ( V_103 ) ) ;
V_34 -> V_45 . V_98 . V_883 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_45 . V_98 . V_884 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
if ( F_10 ( F_61 ( V_103 ) ) & V_222 ) {
V_34 -> V_45 . V_98 . V_326 |= V_877 ;
V_34 -> V_45 . V_98 . V_874 += 1 ;
V_34 -> V_45 . V_98 . V_875 += 1 ;
}
}
static void F_593 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_189 ;
V_189 = F_10 ( F_287 ( V_41 -> V_101 ) ) ;
V_34 -> V_361 = ( V_189 & 0xffff ) + 1 ;
V_34 -> V_362 = ( ( V_189 >> 16 ) & 0xffff ) + 1 ;
V_34 -> V_45 . V_422 . V_885 = V_34 -> V_361 ;
V_34 -> V_45 . V_422 . V_886 = V_34 -> V_362 ;
}
void F_594 ( struct V_511 * V_422 ,
struct V_33 * V_34 )
{
V_422 -> V_886 = V_34 -> V_45 . V_98 . V_535 ;
V_422 -> V_887 = V_34 -> V_45 . V_98 . V_878 ;
V_422 -> V_888 = V_34 -> V_45 . V_98 . V_728 ;
V_422 -> V_889 = V_34 -> V_45 . V_98 . V_881 ;
V_422 -> V_885 = V_34 -> V_45 . V_98 . V_536 ;
V_422 -> V_890 = V_34 -> V_45 . V_98 . V_874 ;
V_422 -> V_891 = V_34 -> V_45 . V_98 . V_883 ;
V_422 -> V_892 = V_34 -> V_45 . V_98 . V_884 ;
V_422 -> V_326 = V_34 -> V_45 . V_98 . V_326 ;
V_422 -> type = V_893 ;
V_422 -> clock = V_34 -> V_45 . V_98 . V_99 ;
V_422 -> V_326 |= V_34 -> V_45 . V_98 . V_326 ;
V_422 -> V_894 = F_595 ( V_422 ) ;
V_422 -> V_895 = F_596 ( V_422 ) ;
F_597 ( V_422 ) ;
}
static void F_481 ( struct V_40 * V_40 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_896 ;
V_896 = 0 ;
if ( ( V_40 -> V_101 == V_123 && V_2 -> V_142 & V_143 ) ||
( V_40 -> V_101 == V_132 && V_2 -> V_142 & V_144 ) )
V_896 |= F_10 ( F_61 ( V_40 -> V_101 ) ) & V_145 ;
if ( V_40 -> V_97 -> V_237 )
V_896 |= V_238 ;
if ( F_17 ( V_44 ) || F_15 ( V_44 ) || F_16 ( V_44 ) ) {
if ( V_40 -> V_97 -> V_897 && V_40 -> V_97 -> V_722 != 30 )
V_896 |= V_898 |
V_899 ;
switch ( V_40 -> V_97 -> V_722 ) {
case 18 :
V_896 |= V_900 ;
break;
case 24 :
V_896 |= V_220 ;
break;
case 30 :
V_896 |= V_901 ;
break;
default:
F_146 () ;
}
}
if ( F_598 ( V_44 ) ) {
if ( V_40 -> V_804 ) {
F_159 ( L_132 ) ;
V_896 |= V_902 ;
} else {
F_159 ( L_133 ) ;
}
}
if ( V_40 -> V_97 -> V_45 . V_98 . V_326 & V_877 ) {
if ( F_60 ( V_44 ) -> V_110 < 4 ||
F_26 ( V_40 , V_224 ) )
V_896 |= V_903 ;
else
V_896 |= V_904 ;
} else
V_896 |= V_905 ;
if ( ( F_15 ( V_44 ) || F_16 ( V_44 ) ) &&
V_40 -> V_97 -> V_906 )
V_896 |= V_907 ;
F_124 ( F_61 ( V_40 -> V_101 ) , V_896 ) ;
F_125 ( F_61 ( V_40 -> V_101 ) ) ;
}
static int F_599 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
const T_4 * V_69 ;
int V_57 = 48000 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_547 ( V_2 ) ) {
V_57 = V_2 -> V_798 . V_908 ;
F_159 ( L_134 , V_57 ) ;
}
V_69 = & V_909 ;
} else if ( F_28 ( V_48 , V_197 ) ) {
V_69 = & V_910 ;
} else {
V_69 = & V_911 ;
}
if ( ! V_48 -> V_912 &&
! F_43 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_591 ( V_41 , V_48 , NULL ) ;
return 0 ;
}
static int F_600 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
const T_4 * V_69 ;
int V_57 = 96000 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_547 ( V_2 ) ) {
V_57 = V_2 -> V_798 . V_908 ;
F_159 ( L_134 , V_57 ) ;
}
if ( F_42 ( V_44 ) )
V_69 = & V_913 ;
else
V_69 = & V_914 ;
} else if ( F_28 ( V_48 , V_219 ) ||
F_28 ( V_48 , V_600 ) ) {
V_69 = & V_915 ;
} else if ( F_28 ( V_48 , V_224 ) ) {
V_69 = & V_916 ;
} else {
V_69 = & V_917 ;
}
if ( ! V_48 -> V_912 &&
! F_45 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_588 ( V_41 , V_48 , NULL ) ;
return 0 ;
}
static int F_601 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
const T_4 * V_69 ;
int V_57 = 96000 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_547 ( V_2 ) ) {
V_57 = V_2 -> V_798 . V_908 ;
F_159 ( L_134 , V_57 ) ;
}
V_69 = & V_918 ;
} else {
V_69 = & V_919 ;
}
if ( ! V_48 -> V_912 &&
! F_44 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_588 ( V_41 , V_48 , NULL ) ;
return 0 ;
}
static int F_602 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
const T_4 * V_69 ;
int V_57 = 96000 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_547 ( V_2 ) ) {
V_57 = V_2 -> V_798 . V_908 ;
F_159 ( L_134 , V_57 ) ;
}
V_69 = & V_920 ;
} else {
V_69 = & V_917 ;
}
if ( ! V_48 -> V_912 &&
! F_43 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_588 ( V_41 , V_48 , NULL ) ;
return 0 ;
}
static int F_603 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
int V_57 = 100000 ;
const T_4 * V_69 = & V_921 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( ! V_48 -> V_912 &&
! F_51 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_571 ( V_41 , V_48 ) ;
return 0 ;
}
static int F_604 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
int V_57 = 100000 ;
const T_4 * V_69 = & V_922 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
if ( ! V_48 -> V_912 &&
! F_49 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_570 ( V_41 , V_48 ) ;
return 0 ;
}
static void F_605 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_189 ;
if ( F_60 ( V_44 ) -> V_110 <= 3 && ( F_141 ( V_44 ) || ! F_140 ( V_44 ) ) )
return;
V_189 = F_10 ( V_581 ) ;
if ( ! ( V_189 & V_582 ) )
return;
if ( F_60 ( V_44 ) -> V_110 < 4 ) {
if ( V_41 -> V_101 != V_132 )
return;
} else {
if ( ( V_189 & V_923 ) != ( V_41 -> V_101 << V_924 ) )
return;
}
V_34 -> V_579 . V_580 = V_189 ;
V_34 -> V_579 . V_584 = F_10 ( V_583 ) ;
}
static void F_606 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_34 -> V_103 ;
T_3 clock ;
T_1 V_815 ;
int V_57 = 100000 ;
if ( ( V_34 -> V_184 . V_66 & V_113 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_815 = F_133 ( V_2 , V_101 , F_573 ( V_101 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_67 = ( V_815 >> V_824 ) & 7 ;
clock . V_59 = V_815 & V_825 ;
clock . V_63 = ( V_815 >> V_828 ) & 0xf ;
clock . V_61 = ( V_815 >> V_826 ) & 7 ;
clock . V_62 = ( V_815 >> V_827 ) & 0x1f ;
V_34 -> V_35 = F_35 ( V_57 , & clock ) ;
}
static void
F_607 ( struct V_40 * V_41 ,
struct V_312 * V_313 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 , V_45 , V_287 ;
int V_101 = V_41 -> V_101 , V_146 = V_41 -> V_146 ;
int V_925 , V_250 ;
unsigned int V_926 ;
struct V_257 * V_96 ;
struct V_927 * V_928 ;
V_11 = F_10 ( F_87 ( V_146 ) ) ;
if ( ! ( V_11 & V_147 ) )
return;
V_928 = F_502 ( sizeof( * V_928 ) , V_714 ) ;
if ( ! V_928 ) {
F_159 ( L_136 ) ;
return;
}
V_96 = & V_928 -> V_45 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
if ( V_11 & V_364 ) {
V_313 -> V_323 = V_324 ;
V_96 -> V_265 [ 0 ] = V_243 ;
}
}
V_250 = V_11 & V_929 ;
V_925 = F_204 ( V_250 ) ;
V_96 -> V_250 = V_925 ;
V_96 -> V_786 = F_177 ( V_925 , 0 ) * 8 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
if ( V_313 -> V_323 )
V_287 = F_10 ( F_232 ( V_146 ) ) ;
else
V_287 = F_10 ( F_233 ( V_146 ) ) ;
V_45 = F_10 ( F_231 ( V_146 ) ) & 0xfffff000 ;
} else {
V_45 = F_10 ( F_234 ( V_146 ) ) ;
}
V_313 -> V_45 = V_45 ;
V_11 = F_10 ( F_287 ( V_101 ) ) ;
V_96 -> V_254 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_96 -> V_249 = ( ( V_11 >> 0 ) & 0xfff ) + 1 ;
V_11 = F_10 ( F_230 ( V_101 ) ) ;
V_96 -> V_266 [ 0 ] = V_11 & 0xffffffc0 ;
V_926 = F_176 ( V_44 , V_96 -> V_249 ,
V_96 -> V_250 ,
V_96 -> V_265 [ 0 ] ) ;
V_313 -> V_253 = V_96 -> V_266 [ 0 ] * V_926 ;
F_159 ( L_137 ,
F_77 ( V_101 ) , V_146 , V_96 -> V_254 , V_96 -> V_249 ,
V_96 -> V_786 , V_45 , V_96 -> V_266 [ 0 ] ,
V_313 -> V_253 ) ;
V_313 -> V_96 = V_928 ;
}
static void F_608 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_34 -> V_103 ;
enum V_187 V_188 = F_132 ( V_101 ) ;
T_3 clock ;
T_1 V_930 , V_931 , V_932 , V_933 , V_934 ;
int V_57 = 100000 ;
if ( ( V_34 -> V_184 . V_66 & V_113 ) == 0 )
return;
F_2 ( & V_2 -> V_5 ) ;
V_930 = F_133 ( V_2 , V_101 , F_578 ( V_188 ) ) ;
V_931 = F_133 ( V_2 , V_101 , F_579 ( V_188 ) ) ;
V_932 = F_133 ( V_2 , V_101 , F_580 ( V_188 ) ) ;
V_933 = F_133 ( V_2 , V_101 , F_581 ( V_188 ) ) ;
V_934 = F_133 ( V_2 , V_101 , F_582 ( V_188 ) ) ;
F_4 ( & V_2 -> V_5 ) ;
clock . V_67 = ( V_932 & 0x7 ) == V_841 ? 2 : 0 ;
clock . V_59 = ( V_931 & 0xff ) << 22 ;
if ( V_934 & V_844 )
clock . V_59 |= V_933 & 0x3fffff ;
clock . V_63 = ( V_932 >> V_842 ) & 0xf ;
clock . V_61 = ( V_930 >> V_838 ) & 0x7 ;
clock . V_62 = ( V_930 >> V_839 ) & 0x1f ;
V_34 -> V_35 = F_36 ( V_57 , & clock ) ;
}
static bool F_609 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_140 V_141 ;
T_2 V_189 ;
bool V_273 ;
V_141 = F_425 ( V_41 -> V_101 ) ;
if ( ! F_84 ( V_2 , V_141 ) )
return false ;
V_34 -> V_103 = (enum V_100 ) V_41 -> V_101 ;
V_34 -> V_216 = NULL ;
V_273 = false ;
V_189 = F_10 ( F_61 ( V_41 -> V_101 ) ) ;
if ( ! ( V_189 & V_145 ) )
goto V_935;
if ( F_17 ( V_44 ) || F_15 ( V_44 ) || F_16 ( V_44 ) ) {
switch ( V_189 & V_218 ) {
case V_900 :
V_34 -> V_722 = 18 ;
break;
case V_220 :
V_34 -> V_722 = 24 ;
break;
case V_901 :
V_34 -> V_722 = 30 ;
break;
default:
break;
}
}
if ( ( F_15 ( V_44 ) || F_16 ( V_44 ) ) &&
( V_189 & V_907 ) )
V_34 -> V_906 = true ;
if ( F_60 ( V_44 ) -> V_110 < 4 )
V_34 -> V_237 = V_189 & V_238 ;
F_592 ( V_41 , V_34 ) ;
F_593 ( V_41 , V_34 ) ;
F_605 ( V_41 , V_34 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
if ( F_16 ( V_44 ) && V_41 -> V_101 != V_123 )
V_189 = V_2 -> V_194 [ V_41 -> V_101 ] ;
else
V_189 = F_10 ( F_130 ( V_41 -> V_101 ) ) ;
V_34 -> V_572 =
( ( V_189 & V_936 )
>> V_814 ) + 1 ;
V_34 -> V_184 . V_186 = V_189 ;
} else if ( F_589 ( V_44 ) || F_590 ( V_44 ) || F_540 ( V_44 ) ) {
V_189 = F_10 ( F_64 ( V_41 -> V_101 ) ) ;
V_34 -> V_572 =
( ( V_189 & V_937 )
>> V_858 ) + 1 ;
} else {
V_34 -> V_572 = 1 ;
}
V_34 -> V_184 . V_66 = F_10 ( F_64 ( V_41 -> V_101 ) ) ;
if ( ! F_15 ( V_44 ) && ! F_16 ( V_44 ) ) {
if ( F_141 ( V_44 ) )
V_34 -> V_184 . V_66 &= ~ V_198 ;
V_34 -> V_184 . V_703 = F_10 ( F_485 ( V_41 -> V_101 ) ) ;
V_34 -> V_184 . V_704 = F_10 ( F_486 ( V_41 -> V_101 ) ) ;
} else {
V_34 -> V_184 . V_66 &= ~ ( V_185 |
V_211 |
V_209 ) ;
}
if ( F_16 ( V_44 ) )
F_608 ( V_41 , V_34 ) ;
else if ( F_15 ( V_44 ) )
F_606 ( V_41 , V_34 ) ;
else
F_610 ( V_41 , V_34 ) ;
V_34 -> V_45 . V_98 . V_99 =
V_34 -> V_35 / V_34 -> V_572 ;
V_273 = true ;
V_935:
F_85 ( V_2 , V_141 ) ;
return V_273 ;
}
static void F_611 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_46 * V_47 ;
int V_54 ;
T_1 V_11 , V_938 ;
bool V_939 = false ;
bool V_940 = false ;
bool V_941 = false ;
bool V_942 = false ;
bool V_943 = false ;
bool V_944 = false ;
F_612 (dev, encoder) {
switch ( V_47 -> type ) {
case V_73 :
V_941 = true ;
V_939 = true ;
break;
case V_504 :
V_941 = true ;
if ( F_346 ( & V_47 -> V_45 ) -> V_188 == V_585 )
V_940 = true ;
break;
default:
break;
}
}
if ( F_119 ( V_44 ) ) {
V_942 = V_2 -> V_798 . V_945 ;
V_943 = V_942 ;
} else {
V_942 = false ;
V_943 = true ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_946 ; V_54 ++ ) {
T_1 V_436 = F_10 ( F_613 ( V_54 ) ) ;
if ( ! ( V_436 & V_113 ) )
continue;
if ( ( V_436 & V_947 ) ==
V_870 ) {
V_944 = true ;
break;
}
}
F_159 ( L_138 ,
V_941 , V_939 , V_942 , V_944 ) ;
V_11 = F_10 ( V_948 ) ;
V_938 = V_11 ;
V_938 &= ~ V_949 ;
if ( V_942 )
V_938 |= V_950 ;
else
V_938 |= V_951 ;
V_938 &= ~ V_952 ;
V_938 &= ~ V_953 ;
V_938 &= ~ V_954 ;
if ( V_941 ) {
V_938 |= V_955 ;
if ( F_547 ( V_2 ) && V_943 )
V_938 |= V_954 ;
if ( V_940 ) {
if ( F_547 ( V_2 ) && V_943 )
V_938 |= V_956 ;
else
V_938 |= V_957 ;
} else
V_938 |= V_958 ;
} else if ( V_944 ) {
V_938 |= V_955 ;
V_938 |= V_954 ;
}
if ( V_938 == V_11 )
return;
V_11 &= ~ V_949 ;
if ( V_942 )
V_11 |= V_950 ;
else
V_11 |= V_951 ;
if ( V_941 ) {
V_11 &= ~ V_952 ;
V_11 |= V_955 ;
if ( F_547 ( V_2 ) && V_943 ) {
F_159 ( L_139 ) ;
V_11 |= V_954 ;
} else
V_11 &= ~ V_954 ;
F_124 ( V_948 , V_11 ) ;
F_125 ( V_948 ) ;
F_126 ( 200 ) ;
V_11 &= ~ V_953 ;
if ( V_940 ) {
if ( F_547 ( V_2 ) && V_943 ) {
F_159 ( L_140 ) ;
V_11 |= V_956 ;
} else
V_11 |= V_957 ;
} else
V_11 |= V_958 ;
F_124 ( V_948 , V_11 ) ;
F_125 ( V_948 ) ;
F_126 ( 200 ) ;
} else {
F_159 ( L_141 ) ;
V_11 &= ~ V_953 ;
V_11 |= V_958 ;
F_124 ( V_948 , V_11 ) ;
F_125 ( V_948 ) ;
F_126 ( 200 ) ;
if ( ! V_944 ) {
F_159 ( L_142 ) ;
V_11 &= ~ V_952 ;
V_11 |= V_959 ;
V_11 &= ~ V_954 ;
F_124 ( V_948 , V_11 ) ;
F_125 ( V_948 ) ;
F_126 ( 200 ) ;
}
}
F_614 ( V_11 != V_938 ) ;
}
static void F_615 ( struct V_1 * V_2 )
{
T_2 V_189 ;
V_189 = F_10 ( V_960 ) ;
V_189 |= V_961 ;
F_124 ( V_960 , V_189 ) ;
if ( F_616 ( F_10 ( V_960 ) &
V_962 , 100 ) )
F_127 ( L_143 ) ;
V_189 = F_10 ( V_960 ) ;
V_189 &= ~ V_961 ;
F_124 ( V_960 , V_189 ) ;
if ( F_616 ( ( F_10 ( V_960 ) &
V_962 ) == 0 , 100 ) )
F_127 ( L_144 ) ;
}
static void F_617 ( struct V_1 * V_2 )
{
T_2 V_189 ;
V_189 = F_320 ( V_2 , 0x8008 , V_963 ) ;
V_189 &= ~ ( 0xFF << 24 ) ;
V_189 |= ( 0x12 << 24 ) ;
F_321 ( V_2 , 0x8008 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2008 , V_963 ) ;
V_189 |= ( 1 << 11 ) ;
F_321 ( V_2 , 0x2008 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2108 , V_963 ) ;
V_189 |= ( 1 << 11 ) ;
F_321 ( V_2 , 0x2108 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x206C , V_963 ) ;
V_189 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_321 ( V_2 , 0x206C , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x216C , V_963 ) ;
V_189 |= ( 1 << 24 ) | ( 1 << 21 ) | ( 1 << 18 ) ;
F_321 ( V_2 , 0x216C , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2080 , V_963 ) ;
V_189 &= ~ ( 7 << 13 ) ;
V_189 |= ( 5 << 13 ) ;
F_321 ( V_2 , 0x2080 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2180 , V_963 ) ;
V_189 &= ~ ( 7 << 13 ) ;
V_189 |= ( 5 << 13 ) ;
F_321 ( V_2 , 0x2180 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x208C , V_963 ) ;
V_189 &= ~ 0xFF ;
V_189 |= 0x1C ;
F_321 ( V_2 , 0x208C , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x218C , V_963 ) ;
V_189 &= ~ 0xFF ;
V_189 |= 0x1C ;
F_321 ( V_2 , 0x218C , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2098 , V_963 ) ;
V_189 &= ~ ( 0xFF << 16 ) ;
V_189 |= ( 0x1C << 16 ) ;
F_321 ( V_2 , 0x2098 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x2198 , V_963 ) ;
V_189 &= ~ ( 0xFF << 16 ) ;
V_189 |= ( 0x1C << 16 ) ;
F_321 ( V_2 , 0x2198 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x20C4 , V_963 ) ;
V_189 |= ( 1 << 27 ) ;
F_321 ( V_2 , 0x20C4 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x21C4 , V_963 ) ;
V_189 |= ( 1 << 27 ) ;
F_321 ( V_2 , 0x21C4 , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x20EC , V_963 ) ;
V_189 &= ~ ( 0xF << 28 ) ;
V_189 |= ( 4 << 28 ) ;
F_321 ( V_2 , 0x20EC , V_189 , V_963 ) ;
V_189 = F_320 ( V_2 , 0x21EC , V_963 ) ;
V_189 &= ~ ( 0xF << 28 ) ;
V_189 |= ( 4 << 28 ) ;
F_321 ( V_2 , 0x21EC , V_189 , V_963 ) ;
}
static void F_618 ( struct V_43 * V_44 , bool V_964 ,
bool V_965 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_9 , V_189 ;
if ( F_6 ( V_965 && ! V_964 , L_145 ) )
V_964 = true ;
if ( F_6 ( F_619 ( V_44 ) && V_965 , L_146 ) )
V_965 = false ;
F_2 ( & V_2 -> V_5 ) ;
V_189 = F_320 ( V_2 , V_966 , V_480 ) ;
V_189 &= ~ V_481 ;
V_189 |= V_967 ;
F_321 ( V_2 , V_966 , V_189 , V_480 ) ;
F_126 ( 24 ) ;
if ( V_964 ) {
V_189 = F_320 ( V_2 , V_966 , V_480 ) ;
V_189 &= ~ V_967 ;
F_321 ( V_2 , V_966 , V_189 , V_480 ) ;
if ( V_965 ) {
F_615 ( V_2 ) ;
F_617 ( V_2 ) ;
}
}
V_9 = F_619 ( V_44 ) ? V_968 : V_969 ;
V_189 = F_320 ( V_2 , V_9 , V_480 ) ;
V_189 |= V_970 ;
F_321 ( V_2 , V_9 , V_189 , V_480 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_620 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_9 , V_189 ;
F_2 ( & V_2 -> V_5 ) ;
V_9 = F_619 ( V_44 ) ? V_968 : V_969 ;
V_189 = F_320 ( V_2 , V_9 , V_480 ) ;
V_189 &= ~ V_970 ;
F_321 ( V_2 , V_9 , V_189 , V_480 ) ;
V_189 = F_320 ( V_2 , V_966 , V_480 ) ;
if ( ! ( V_189 & V_481 ) ) {
if ( ! ( V_189 & V_967 ) ) {
V_189 |= V_967 ;
F_321 ( V_2 , V_966 , V_189 , V_480 ) ;
F_126 ( 32 ) ;
}
V_189 |= V_481 ;
F_321 ( V_2 , V_966 , V_189 , V_480 ) ;
}
F_4 ( & V_2 -> V_5 ) ;
}
static void F_621 ( struct V_1 * V_2 , int V_971 )
{
T_2 V_189 ;
int V_972 = F_622 ( V_971 ) ;
if ( F_31 ( V_971 % 5 != 0 ) )
return;
if ( F_31 ( V_972 >= F_180 ( V_973 ) ) )
return;
F_2 ( & V_2 -> V_5 ) ;
if ( V_971 % 10 != 0 )
V_189 = 0xAAAAAAAB ;
else
V_189 = 0x00000000 ;
F_321 ( V_2 , V_974 , V_189 , V_480 ) ;
V_189 = F_320 ( V_2 , V_975 , V_480 ) ;
V_189 &= 0xffff0000 ;
V_189 |= V_973 [ V_972 ] ;
F_321 ( V_2 , V_975 , V_189 , V_480 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static void F_623 ( struct V_43 * V_44 )
{
struct V_46 * V_47 ;
bool V_976 = false ;
F_612 (dev, encoder) {
switch ( V_47 -> type ) {
case V_600 :
V_976 = true ;
break;
default:
break;
}
}
if ( V_976 ) {
F_621 ( F_123 ( V_44 ) , 0 ) ;
F_618 ( V_44 , true , true ) ;
} else {
F_620 ( V_44 ) ;
}
}
void F_624 ( struct V_43 * V_44 )
{
if ( F_119 ( V_44 ) || F_105 ( V_44 ) )
F_611 ( V_44 ) ;
else if ( F_161 ( V_44 ) )
F_623 ( V_44 ) ;
}
static void F_395 ( struct V_93 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_2 V_11 ;
V_11 = 0 ;
switch ( V_40 -> V_97 -> V_722 ) {
case 18 :
V_11 |= V_900 ;
break;
case 24 :
V_11 |= V_220 ;
break;
case 30 :
V_11 |= V_901 ;
break;
case 36 :
V_11 |= V_977 ;
break;
default:
F_146 () ;
}
if ( V_40 -> V_97 -> V_897 )
V_11 |= ( V_898 | V_899 ) ;
if ( V_40 -> V_97 -> V_45 . V_98 . V_326 & V_877 )
V_11 |= V_223 ;
else
V_11 |= V_905 ;
if ( V_40 -> V_97 -> V_906 )
V_11 |= V_907 ;
F_124 ( F_61 ( V_101 ) , V_11 ) ;
F_125 ( F_61 ( V_101 ) ) ;
}
static void F_403 ( struct V_93 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
T_1 V_11 = 0 ;
if ( F_237 ( V_2 ) && V_40 -> V_97 -> V_897 )
V_11 |= ( V_898 | V_899 ) ;
if ( V_40 -> V_97 -> V_45 . V_98 . V_326 & V_877 )
V_11 |= V_223 ;
else
V_11 |= V_905 ;
F_124 ( F_61 ( V_103 ) , V_11 ) ;
F_125 ( F_61 ( V_103 ) ) ;
}
static void F_404 ( struct V_93 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
if ( F_238 ( V_2 ) || F_60 ( V_2 ) -> V_110 >= 9 ) {
T_1 V_11 = 0 ;
switch ( V_40 -> V_97 -> V_722 ) {
case 18 :
V_11 |= V_978 ;
break;
case 24 :
V_11 |= V_979 ;
break;
case 30 :
V_11 |= V_980 ;
break;
case 36 :
V_11 |= V_981 ;
break;
default:
F_146 () ;
}
if ( V_40 -> V_97 -> V_897 )
V_11 |= V_982 | V_983 ;
F_124 ( F_625 ( V_40 -> V_101 ) , V_11 ) ;
}
}
int F_511 ( int V_91 , int V_719 , int V_984 )
{
T_1 V_985 = V_91 * V_984 * 21 / 20 ;
return F_185 ( V_985 , V_719 * 8 ) ;
}
static bool F_626 ( struct V_66 * V_66 , int V_986 )
{
return F_33 ( V_66 ) < V_986 * V_66 -> V_63 ;
}
static void F_627 ( struct V_40 * V_40 ,
struct V_33 * V_48 ,
T_3 * V_801 )
{
struct V_93 * V_41 = & V_40 -> V_45 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_49 * V_39 = V_48 -> V_45 . V_39 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_46 * V_47 ;
T_1 V_66 , V_802 , V_803 ;
int V_986 , V_54 ;
bool V_987 = false , V_855 = false ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != V_48 -> V_45 . V_41 )
continue;
V_47 = F_30 ( V_53 -> V_56 ) ;
switch ( V_47 -> type ) {
case V_73 :
V_987 = true ;
break;
case V_224 :
case V_219 :
V_855 = true ;
break;
default:
break;
}
}
V_986 = 21 ;
if ( V_987 ) {
if ( ( F_547 ( V_2 ) &&
V_2 -> V_798 . V_908 == 100000 ) ||
( F_119 ( V_44 ) && F_42 ( V_44 ) ) )
V_986 = 25 ;
} else if ( V_48 -> V_868 )
V_986 = 20 ;
V_802 = F_549 ( & V_48 -> V_66 ) ;
if ( F_626 ( & V_48 -> V_66 , V_986 ) )
V_802 |= V_988 ;
if ( V_801 ) {
V_803 = F_549 ( V_801 ) ;
if ( V_801 -> V_58 < V_986 * V_801 -> V_63 )
V_803 |= V_988 ;
} else {
V_803 = V_802 ;
}
V_66 = 0 ;
if ( V_987 )
V_66 |= V_856 ;
else
V_66 |= V_857 ;
V_66 |= ( V_48 -> V_572 - 1 )
<< V_989 ;
if ( V_855 )
V_66 |= V_859 ;
if ( V_48 -> V_510 )
V_66 |= V_859 ;
V_66 |= ( 1 << ( V_48 -> V_66 . V_61 - 1 ) ) << V_861 ;
V_66 |= ( 1 << ( V_48 -> V_66 . V_61 - 1 ) ) << V_862 ;
switch ( V_48 -> V_66 . V_62 ) {
case 5 :
V_66 |= V_863 ;
break;
case 7 :
V_66 |= V_864 ;
break;
case 10 :
V_66 |= V_865 ;
break;
case 14 :
V_66 |= V_866 ;
break;
}
if ( V_987 && F_547 ( V_2 ) )
V_66 |= V_870 ;
else
V_66 |= V_871 ;
V_66 |= V_113 ;
V_48 -> V_184 . V_66 = V_66 ;
V_48 -> V_184 . V_703 = V_802 ;
V_48 -> V_184 . V_704 = V_803 ;
}
static int F_628 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_3 V_801 ;
bool V_990 = false ;
struct V_991 * V_992 ;
const T_4 * V_69 ;
int V_57 = 120000 ;
memset ( & V_48 -> V_184 , 0 ,
sizeof( V_48 -> V_184 ) ) ;
V_41 -> V_804 = false ;
if ( ! V_48 -> V_234 )
return 0 ;
if ( F_28 ( V_48 , V_73 ) ) {
if ( F_547 ( V_2 ) ) {
F_159 ( L_134 ,
V_2 -> V_798 . V_908 ) ;
V_57 = V_2 -> V_798 . V_908 ;
}
if ( F_42 ( V_44 ) ) {
if ( V_57 == 100000 )
V_69 = & V_993 ;
else
V_69 = & V_994 ;
} else {
if ( V_57 == 100000 )
V_69 = & V_995 ;
else
V_69 = & V_996 ;
}
} else {
V_69 = & V_997 ;
}
if ( ! V_48 -> V_912 &&
! F_45 ( V_69 , V_48 , V_48 -> V_35 ,
V_57 , NULL , & V_48 -> V_66 ) ) {
F_127 ( L_135 ) ;
return - V_533 ;
}
F_627 ( V_41 , V_48 ,
V_990 ? & V_801 : NULL ) ;
V_992 = F_629 ( V_41 , V_48 , NULL ) ;
if ( V_992 == NULL ) {
F_19 ( L_147 ,
F_77 ( V_41 -> V_101 ) ) ;
return - V_533 ;
}
if ( F_28 ( V_48 , V_73 ) &&
V_990 )
V_41 -> V_804 = true ;
return 0 ;
}
static void F_630 ( struct V_40 * V_41 ,
struct V_790 * V_791 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
V_791 -> V_795 = F_10 ( F_557 ( V_101 ) ) ;
V_791 -> V_796 = F_10 ( F_558 ( V_101 ) ) ;
V_791 -> V_793 = F_10 ( F_554 ( V_101 ) )
& ~ V_505 ;
V_791 -> V_794 = F_10 ( F_556 ( V_101 ) ) ;
V_791 -> V_792 = ( ( F_10 ( F_554 ( V_101 ) )
& V_505 ) >> V_998 ) + 1 ;
}
static void F_631 ( struct V_40 * V_41 ,
enum V_100 V_100 ,
struct V_790 * V_791 ,
struct V_790 * V_807 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 = V_41 -> V_101 ;
if ( F_60 ( V_44 ) -> V_110 >= 5 ) {
V_791 -> V_795 = F_10 ( F_560 ( V_100 ) ) ;
V_791 -> V_796 = F_10 ( F_561 ( V_100 ) ) ;
V_791 -> V_793 = F_10 ( F_349 ( V_100 ) )
& ~ V_505 ;
V_791 -> V_794 = F_10 ( F_559 ( V_100 ) ) ;
V_791 -> V_792 = ( ( F_10 ( F_349 ( V_100 ) )
& V_505 ) >> V_998 ) + 1 ;
if ( V_807 && F_60 ( V_44 ) -> V_110 < 8 &&
V_41 -> V_97 -> V_808 ) {
V_807 -> V_795 = F_10 ( F_564 ( V_100 ) ) ;
V_807 -> V_796 = F_10 ( F_565 ( V_100 ) ) ;
V_807 -> V_793 = F_10 ( F_562 ( V_100 ) )
& ~ V_505 ;
V_807 -> V_794 = F_10 ( F_563 ( V_100 ) ) ;
V_807 -> V_792 = ( ( F_10 ( F_562 ( V_100 ) )
& V_505 ) >> V_998 ) + 1 ;
}
} else {
V_791 -> V_795 = F_10 ( F_568 ( V_101 ) ) ;
V_791 -> V_796 = F_10 ( F_569 ( V_101 ) ) ;
V_791 -> V_793 = F_10 ( F_566 ( V_101 ) )
& ~ V_505 ;
V_791 -> V_794 = F_10 ( F_567 ( V_101 ) ) ;
V_791 -> V_792 = ( ( F_10 ( F_566 ( V_101 ) )
& V_505 ) >> V_998 ) + 1 ;
}
}
void F_632 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
if ( V_34 -> V_234 )
F_630 ( V_41 , & V_34 -> V_810 ) ;
else
F_631 ( V_41 , V_34 -> V_103 ,
& V_34 -> V_810 ,
& V_34 -> V_811 ) ;
}
static void F_633 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
F_631 ( V_41 , V_34 -> V_103 ,
& V_34 -> V_568 , NULL ) ;
}
static void F_634 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_379 * V_380 = & V_34 -> V_380 ;
T_2 V_420 = 0 ;
int V_378 = - 1 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_41 -> V_381 ; V_54 ++ ) {
V_420 = F_10 ( F_246 ( V_41 -> V_101 , V_54 ) ) ;
if ( V_420 & V_421 && ! ( V_420 & V_999 ) ) {
V_378 = V_54 ;
V_34 -> V_435 . V_156 = true ;
V_34 -> V_435 . V_540 = F_10 ( F_247 ( V_41 -> V_101 , V_54 ) ) ;
V_34 -> V_435 . V_253 = F_10 ( F_248 ( V_41 -> V_101 , V_54 ) ) ;
break;
}
}
V_380 -> V_412 = V_378 ;
if ( V_378 >= 0 ) {
V_380 -> V_524 |= ( 1 << V_534 ) ;
} else {
V_380 -> V_524 &= ~ ( 1 << V_534 ) ;
}
}
static void
F_635 ( struct V_40 * V_41 ,
struct V_312 * V_313 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 , V_45 , V_287 , V_1000 , V_323 ;
int V_101 = V_41 -> V_101 ;
int V_925 , V_250 ;
unsigned int V_926 ;
struct V_257 * V_96 ;
struct V_927 * V_928 ;
V_928 = F_502 ( sizeof( * V_928 ) , V_714 ) ;
if ( ! V_928 ) {
F_159 ( L_136 ) ;
return;
}
V_96 = & V_928 -> V_45 ;
V_11 = F_10 ( F_93 ( V_101 , 0 ) ) ;
if ( ! ( V_11 & V_152 ) )
goto error;
V_250 = V_11 & V_1001 ;
V_925 = F_205 ( V_250 ,
V_11 & V_385 ,
V_11 & V_1002 ) ;
V_96 -> V_250 = V_925 ;
V_96 -> V_786 = F_177 ( V_925 , 0 ) * 8 ;
V_323 = V_11 & V_1003 ;
switch ( V_323 ) {
case V_1004 :
V_96 -> V_265 [ 0 ] = V_242 ;
break;
case V_396 :
V_313 -> V_323 = V_324 ;
V_96 -> V_265 [ 0 ] = V_243 ;
break;
case V_397 :
V_96 -> V_265 [ 0 ] = V_244 ;
break;
case V_398 :
V_96 -> V_265 [ 0 ] = V_245 ;
break;
default:
F_173 ( V_323 ) ;
goto error;
}
V_45 = F_10 ( F_262 ( V_101 , 0 ) ) & 0xfffff000 ;
V_313 -> V_45 = V_45 ;
V_287 = F_10 ( F_256 ( V_101 , 0 ) ) ;
V_11 = F_10 ( F_257 ( V_101 , 0 ) ) ;
V_96 -> V_249 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_96 -> V_254 = ( ( V_11 >> 0 ) & 0x1fff ) + 1 ;
V_11 = F_10 ( F_258 ( V_101 , 0 ) ) ;
V_1000 = F_240 ( V_2 , V_96 -> V_265 [ 0 ] ,
V_96 -> V_250 ) ;
V_96 -> V_266 [ 0 ] = ( V_11 & 0x3ff ) * V_1000 ;
V_926 = F_176 ( V_44 , V_96 -> V_249 ,
V_96 -> V_250 ,
V_96 -> V_265 [ 0 ] ) ;
V_313 -> V_253 = V_96 -> V_266 [ 0 ] * V_926 ;
F_159 ( L_148 ,
F_77 ( V_101 ) , V_96 -> V_254 , V_96 -> V_249 ,
V_96 -> V_786 , V_45 , V_96 -> V_266 [ 0 ] ,
V_313 -> V_253 ) ;
V_313 -> V_96 = V_928 ;
return;
error:
F_218 ( V_96 ) ;
}
static void F_636 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_189 ;
V_189 = F_10 ( F_360 ( V_41 -> V_101 ) ) ;
if ( V_189 & V_541 ) {
V_34 -> V_435 . V_156 = true ;
V_34 -> V_435 . V_540 = F_10 ( F_362 ( V_41 -> V_101 ) ) ;
V_34 -> V_435 . V_253 = F_10 ( F_363 ( V_41 -> V_101 ) ) ;
if ( F_637 ( V_44 ) ) {
F_31 ( ( V_189 & V_1005 ) !=
F_361 ( V_41 -> V_101 ) ) ;
}
}
}
static void
F_638 ( struct V_40 * V_41 ,
struct V_312 * V_313 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 , V_45 , V_287 ;
int V_101 = V_41 -> V_101 ;
int V_925 , V_250 ;
unsigned int V_926 ;
struct V_257 * V_96 ;
struct V_927 * V_928 ;
V_11 = F_10 ( F_87 ( V_101 ) ) ;
if ( ! ( V_11 & V_147 ) )
return;
V_928 = F_502 ( sizeof( * V_928 ) , V_714 ) ;
if ( ! V_928 ) {
F_159 ( L_136 ) ;
return;
}
V_96 = & V_928 -> V_45 ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
if ( V_11 & V_364 ) {
V_313 -> V_323 = V_324 ;
V_96 -> V_265 [ 0 ] = V_243 ;
}
}
V_250 = V_11 & V_929 ;
V_925 = F_204 ( V_250 ) ;
V_96 -> V_250 = V_925 ;
V_96 -> V_786 = F_177 ( V_925 , 0 ) * 8 ;
V_45 = F_10 ( F_231 ( V_101 ) ) & 0xfffff000 ;
if ( F_237 ( V_44 ) || F_238 ( V_44 ) ) {
V_287 = F_10 ( F_239 ( V_101 ) ) ;
} else {
if ( V_313 -> V_323 )
V_287 = F_10 ( F_232 ( V_101 ) ) ;
else
V_287 = F_10 ( F_233 ( V_101 ) ) ;
}
V_313 -> V_45 = V_45 ;
V_11 = F_10 ( F_287 ( V_101 ) ) ;
V_96 -> V_254 = ( ( V_11 >> 16 ) & 0xfff ) + 1 ;
V_96 -> V_249 = ( ( V_11 >> 0 ) & 0xfff ) + 1 ;
V_11 = F_10 ( F_230 ( V_101 ) ) ;
V_96 -> V_266 [ 0 ] = V_11 & 0xffffffc0 ;
V_926 = F_176 ( V_44 , V_96 -> V_249 ,
V_96 -> V_250 ,
V_96 -> V_265 [ 0 ] ) ;
V_313 -> V_253 = V_96 -> V_266 [ 0 ] * V_926 ;
F_159 ( L_148 ,
F_77 ( V_101 ) , V_96 -> V_254 , V_96 -> V_249 ,
V_96 -> V_786 , V_45 , V_96 -> V_266 [ 0 ] ,
V_313 -> V_253 ) ;
V_313 -> V_96 = V_928 ;
}
static bool F_639 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_140 V_141 ;
T_2 V_189 ;
bool V_273 ;
V_141 = F_425 ( V_41 -> V_101 ) ;
if ( ! F_84 ( V_2 , V_141 ) )
return false ;
V_34 -> V_103 = (enum V_100 ) V_41 -> V_101 ;
V_34 -> V_216 = NULL ;
V_273 = false ;
V_189 = F_10 ( F_61 ( V_41 -> V_101 ) ) ;
if ( ! ( V_189 & V_145 ) )
goto V_935;
switch ( V_189 & V_218 ) {
case V_900 :
V_34 -> V_722 = 18 ;
break;
case V_220 :
V_34 -> V_722 = 24 ;
break;
case V_901 :
V_34 -> V_722 = 30 ;
break;
case V_977 :
V_34 -> V_722 = 36 ;
break;
default:
break;
}
if ( V_189 & V_907 )
V_34 -> V_906 = true ;
if ( F_10 ( F_103 ( V_41 -> V_101 ) ) & V_157 ) {
struct V_991 * V_992 ;
enum V_1006 V_1007 ;
V_34 -> V_234 = true ;
V_189 = F_10 ( F_72 ( V_41 -> V_101 ) ) ;
V_34 -> V_449 = ( ( V_448 & V_189 ) >>
V_1008 ) + 1 ;
F_633 ( V_41 , V_34 ) ;
if ( F_119 ( V_2 ) ) {
V_1007 = (enum V_1006 ) V_41 -> V_101 ;
} else {
V_189 = F_10 ( V_508 ) ;
if ( V_189 & F_351 ( V_41 -> V_101 ) )
V_1007 = V_509 ;
else
V_1007 = V_1009 ;
}
V_34 -> V_216 =
F_352 ( V_2 , V_1007 ) ;
V_992 = V_34 -> V_216 ;
F_31 ( ! V_992 -> V_1010 . V_711 ( V_2 , V_992 ,
& V_34 -> V_184 ) ) ;
V_189 = V_34 -> V_184 . V_66 ;
V_34 -> V_572 =
( ( V_189 & V_1011 )
>> V_989 ) + 1 ;
F_640 ( V_41 , V_34 ) ;
} else {
V_34 -> V_572 = 1 ;
}
F_592 ( V_41 , V_34 ) ;
F_593 ( V_41 , V_34 ) ;
F_636 ( V_41 , V_34 ) ;
V_273 = true ;
V_935:
F_85 ( V_2 , V_141 ) ;
return V_273 ;
}
static void F_641 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
struct V_40 * V_41 ;
F_138 (dev, crtc)
F_65 ( V_41 -> V_94 , L_149 ,
F_77 ( V_41 -> V_101 ) ) ;
F_65 ( F_10 ( V_1012 ) , L_150 ) ;
F_65 ( F_10 ( V_1013 ) & V_1014 , L_151 ) ;
F_65 ( F_10 ( F_642 ( 0 ) ) & V_1015 , L_152 ) ;
F_65 ( F_10 ( F_642 ( 1 ) ) & V_1015 , L_153 ) ;
F_65 ( F_10 ( V_1016 ) & V_1017 , L_154 ) ;
F_65 ( F_10 ( V_1018 ) & V_1019 ,
L_155 ) ;
if ( F_237 ( V_44 ) )
F_65 ( F_10 ( V_1020 ) & V_1019 ,
L_156 ) ;
F_65 ( F_10 ( V_1021 ) & V_1022 ,
L_157 ) ;
F_65 ( F_10 ( V_1023 ) & V_1024 ,
L_158 ) ;
F_65 ( F_10 ( V_1025 ) & V_1026 , L_159 ) ;
F_65 ( F_643 ( V_2 ) , L_160 ) ;
}
static T_2 F_644 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
if ( F_237 ( V_44 ) )
return F_10 ( V_1027 ) ;
else
return F_10 ( V_1028 ) ;
}
static void F_645 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
if ( F_237 ( V_44 ) ) {
F_2 ( & V_2 -> V_544 . V_545 ) ;
if ( F_366 ( V_2 , V_1029 ,
V_11 ) )
F_127 ( L_161 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
} else {
F_124 ( V_1028 , V_11 ) ;
F_125 ( V_1028 ) ;
}
}
static void F_646 ( struct V_1 * V_2 ,
bool V_1030 , bool V_1031 )
{
T_2 V_11 ;
F_641 ( V_2 ) ;
V_11 = F_10 ( V_734 ) ;
if ( V_1030 ) {
V_11 |= V_736 ;
F_124 ( V_734 , V_11 ) ;
if ( F_616 ( F_10 ( V_734 ) &
V_1032 , 1 ) )
F_127 ( L_162 ) ;
V_11 = F_10 ( V_734 ) ;
}
V_11 |= V_1033 ;
F_124 ( V_734 , V_11 ) ;
F_125 ( V_734 ) ;
if ( F_62 ( ( F_10 ( V_734 ) & V_659 ) == 0 , 1 ) )
F_127 ( L_163 ) ;
V_11 = F_644 ( V_2 ) ;
V_11 |= V_1034 ;
F_645 ( V_2 , V_11 ) ;
F_647 ( 100 ) ;
if ( F_62 ( ( F_644 ( V_2 ) & V_1035 ) == 0 ,
1 ) )
F_127 ( L_164 ) ;
if ( V_1031 ) {
V_11 = F_10 ( V_734 ) ;
V_11 |= V_1036 ;
F_124 ( V_734 , V_11 ) ;
F_125 ( V_734 ) ;
}
}
static void F_648 ( struct V_1 * V_2 )
{
T_2 V_11 ;
V_11 = F_10 ( V_734 ) ;
if ( ( V_11 & ( V_659 | V_1033 | V_736 |
V_1036 ) ) == V_659 )
return;
F_649 ( V_2 , V_1037 ) ;
if ( V_11 & V_1036 ) {
V_11 &= ~ V_1036 ;
F_124 ( V_734 , V_11 ) ;
F_125 ( V_734 ) ;
}
V_11 = F_644 ( V_2 ) ;
V_11 |= V_1038 ;
V_11 &= ~ V_1034 ;
F_645 ( V_2 , V_11 ) ;
V_11 = F_10 ( V_734 ) ;
V_11 &= ~ V_1033 ;
F_124 ( V_734 , V_11 ) ;
if ( F_62 ( F_10 ( V_734 ) & V_659 , 5 ) )
F_127 ( L_165 ) ;
if ( V_11 & V_736 ) {
V_11 = F_10 ( V_734 ) ;
V_11 &= ~ V_736 ;
F_124 ( V_734 , V_11 ) ;
if ( F_616 ( ( F_10 ( V_734 ) &
V_1032 ) == 0 , 1 ) )
F_127 ( L_166 ) ;
}
F_650 ( V_2 , V_1037 ) ;
F_438 ( V_2 -> V_44 ) ;
}
void F_651 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
T_2 V_11 ;
F_159 ( L_167 ) ;
if ( F_619 ( V_44 ) ) {
V_11 = F_10 ( V_1039 ) ;
V_11 &= ~ V_1040 ;
F_124 ( V_1039 , V_11 ) ;
}
F_620 ( V_44 ) ;
F_646 ( V_2 , true , true ) ;
}
void F_652 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
T_2 V_11 ;
F_159 ( L_168 ) ;
F_648 ( V_2 ) ;
F_623 ( V_44 ) ;
if ( F_619 ( V_44 ) ) {
V_11 = F_10 ( V_1039 ) ;
V_11 |= V_1040 ;
F_124 ( V_1039 , V_11 ) ;
}
}
static void F_653 ( struct V_49 * V_555 )
{
struct V_43 * V_44 = V_555 -> V_44 ;
struct V_687 * V_698 =
F_471 ( V_555 ) ;
unsigned int V_699 = V_698 -> V_690 ;
F_439 ( F_123 ( V_44 ) , V_699 ) ;
}
static int F_654 ( struct V_49 * V_39 )
{
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_1 * V_2 = V_39 -> V_44 -> V_104 ;
struct V_93 * V_41 ;
struct V_38 * V_1041 ;
struct V_33 * V_48 ;
unsigned V_1042 = 0 , V_54 ;
enum V_101 V_101 ;
memcpy ( V_335 -> V_688 , V_2 -> V_688 ,
sizeof( V_335 -> V_688 ) ) ;
F_472 (state, crtc, cstate, i) {
int V_1043 ;
V_48 = F_270 ( V_1041 ) ;
if ( ! V_48 -> V_45 . V_499 ) {
V_335 -> V_688 [ V_54 ] = 0 ;
continue;
}
V_1043 = F_514 ( V_48 ) ;
if ( F_238 ( V_2 ) && V_48 -> V_543 )
V_1043 = F_185 ( V_1043 * 100 , 95 ) ;
V_335 -> V_688 [ V_54 ] = V_1043 ;
}
F_90 (dev_priv, pipe)
V_1042 = V_71 ( V_335 -> V_688 [ V_101 ] , V_1042 ) ;
return V_1042 ;
}
static void F_655 ( struct V_43 * V_44 , int V_672 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_2 V_11 , V_1044 ;
int V_273 ;
if ( F_6 ( ( F_10 ( V_734 ) &
( V_1033 | V_659 |
V_1045 | V_1046 |
V_1047 | V_1036 |
V_736 ) ) != V_659 ,
L_169 ) )
return;
F_2 ( & V_2 -> V_544 . V_545 ) ;
V_273 = F_366 ( V_2 ,
V_1048 , 0x0 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
if ( V_273 ) {
F_127 ( L_170 ) ;
return;
}
V_11 = F_10 ( V_734 ) ;
V_11 |= V_736 ;
F_124 ( V_734 , V_11 ) ;
if ( F_616 ( F_10 ( V_734 ) &
V_1032 , 1 ) )
F_127 ( L_162 ) ;
V_11 = F_10 ( V_734 ) ;
V_11 &= ~ V_735 ;
switch ( V_672 ) {
case 450000 :
V_11 |= V_737 ;
V_1044 = 0 ;
break;
case 540000 :
V_11 |= V_738 ;
V_1044 = 1 ;
break;
case 337500 :
V_11 |= V_739 ;
V_1044 = 2 ;
break;
case 675000 :
V_11 |= V_1049 ;
V_1044 = 3 ;
break;
default:
F_6 ( 1 , L_171 ) ;
return;
}
F_124 ( V_734 , V_11 ) ;
V_11 = F_10 ( V_734 ) ;
V_11 &= ~ V_736 ;
F_124 ( V_734 , V_11 ) ;
if ( F_616 ( ( F_10 ( V_734 ) &
V_1032 ) == 0 , 1 ) )
F_127 ( L_166 ) ;
F_2 ( & V_2 -> V_544 . V_545 ) ;
F_366 ( V_2 , V_632 , V_1044 ) ;
F_4 ( & V_2 -> V_544 . V_545 ) ;
F_124 ( V_1050 , F_7 ( V_672 , 1000 ) - 1 ) ;
F_438 ( V_44 ) ;
F_6 ( V_672 != V_2 -> V_621 ,
L_172 ,
V_672 , V_2 -> V_621 ) ;
}
static int F_656 ( struct V_49 * V_39 )
{
struct V_1 * V_2 = F_123 ( V_39 -> V_44 ) ;
struct V_687 * V_335 = F_471 ( V_39 ) ;
int V_685 = F_654 ( V_39 ) ;
int V_672 ;
if ( V_685 > 540000 )
V_672 = 675000 ;
else if ( V_685 > 450000 )
V_672 = 540000 ;
else if ( V_685 > 337500 )
V_672 = 450000 ;
else
V_672 = 337500 ;
if ( V_672 > V_2 -> V_613 ) {
F_159 ( L_173 ,
V_672 , V_2 -> V_613 ) ;
return - V_533 ;
}
V_335 -> V_672 = V_335 -> V_690 = V_672 ;
if ( ! V_335 -> V_691 )
V_335 -> V_690 = 337500 ;
return 0 ;
}
static void F_657 ( struct V_49 * V_555 )
{
struct V_43 * V_44 = V_555 -> V_44 ;
struct V_687 * V_698 =
F_471 ( V_555 ) ;
unsigned V_699 = V_698 -> V_690 ;
F_655 ( V_44 , V_699 ) ;
}
static int F_658 ( struct V_40 * V_41 ,
struct V_33 * V_48 )
{
struct V_46 * V_46 =
F_659 ( V_48 ) ;
if ( V_46 -> type != V_602 ) {
if ( ! F_660 ( V_41 , V_48 ) )
return - V_533 ;
}
V_41 -> V_804 = false ;
return 0 ;
}
static void F_661 ( struct V_1 * V_2 ,
enum V_188 V_188 ,
struct V_33 * V_34 )
{
enum V_1006 V_378 ;
switch ( V_188 ) {
case V_585 :
V_34 -> V_1051 = V_654 ;
V_378 = V_1052 ;
break;
case V_208 :
V_34 -> V_1051 = V_1053 ;
V_378 = V_1054 ;
break;
case V_210 :
V_34 -> V_1051 = V_1055 ;
V_378 = V_1056 ;
break;
default:
F_127 ( L_174 ) ;
return;
}
V_34 -> V_216 = F_352 ( V_2 , V_378 ) ;
}
static void F_662 ( struct V_1 * V_2 ,
enum V_188 V_188 ,
struct V_33 * V_34 )
{
enum V_1006 V_378 ;
T_1 V_436 ;
V_436 = F_10 ( V_1057 ) & F_663 ( V_188 ) ;
V_34 -> V_1051 = V_436 >> ( V_188 * 3 + 1 ) ;
switch ( V_34 -> V_1051 ) {
case V_654 :
V_378 = V_1052 ;
break;
case V_1053 :
V_378 = V_1054 ;
break;
case V_1055 :
V_378 = V_1056 ;
break;
case V_1058 :
V_378 = V_1059 ;
break;
default:
F_173 ( V_34 -> V_1051 ) ;
return;
}
V_34 -> V_216 = F_352 ( V_2 , V_378 ) ;
}
static void F_664 ( struct V_1 * V_2 ,
enum V_188 V_188 ,
struct V_33 * V_34 )
{
enum V_1006 V_378 ;
V_34 -> V_1051 = F_10 ( F_665 ( V_188 ) ) ;
switch ( V_34 -> V_1051 ) {
case V_1060 :
V_378 = V_1061 ;
break;
case V_1062 :
V_378 = V_1063 ;
break;
case V_1064 :
V_378 = V_1065 ;
break;
case V_1066 :
V_378 = V_1067 ;
break;
case V_1068 :
V_378 = V_1069 ;
break;
case V_1070 :
V_378 = V_1071 ;
break;
default:
F_173 ( V_34 -> V_1051 ) ;
case V_1072 :
return;
}
V_34 -> V_216 = F_352 ( V_2 , V_378 ) ;
}
static bool F_666 ( struct V_40 * V_41 ,
struct V_33 * V_34 ,
unsigned long * V_1073 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_140 V_141 ;
T_1 V_189 ;
V_34 -> V_103 = (enum V_100 ) V_41 -> V_101 ;
V_189 = F_10 ( F_69 ( V_571 ) ) ;
if ( V_189 & V_116 ) {
enum V_101 V_1074 ;
switch ( V_189 & V_1075 ) {
default:
F_6 ( 1 , L_175 ) ;
case V_1076 :
case V_1077 :
V_1074 = V_123 ;
break;
case V_1078 :
V_1074 = V_132 ;
break;
case V_1079 :
V_1074 = V_502 ;
break;
}
if ( V_1074 == V_41 -> V_101 )
V_34 -> V_103 = V_571 ;
}
V_141 = F_83 ( V_34 -> V_103 ) ;
if ( ! F_84 ( V_2 , V_141 ) )
return false ;
* V_1073 |= F_229 ( V_141 ) ;
V_189 = F_10 ( F_61 ( V_34 -> V_103 ) ) ;
return V_189 & V_145 ;
}
static bool F_667 ( struct V_40 * V_41 ,
struct V_33 * V_34 ,
unsigned long * V_1073 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_140 V_141 ;
enum V_188 V_188 ;
enum V_100 V_103 ;
T_1 V_189 ;
V_34 -> V_233 = false ;
F_668 (port, BIT(PORT_A) | BIT(PORT_C)) {
if ( V_188 == V_585 )
V_103 = V_1080 ;
else
V_103 = V_1081 ;
V_141 = F_83 ( V_103 ) ;
if ( ! F_84 ( V_2 , V_141 ) )
continue;
* V_1073 |= F_229 ( V_141 ) ;
if ( ! F_669 ( V_2 ) )
break;
V_189 = F_10 ( F_670 ( V_188 ) ) ;
if ( ! ( V_189 & V_1082 ) )
continue;
V_189 = F_10 ( F_671 ( V_188 ) ) ;
if ( ( V_189 & V_1083 ) != F_672 ( V_41 -> V_101 ) )
continue;
V_34 -> V_103 = V_103 ;
V_34 -> V_233 = true ;
break;
}
return V_34 -> V_233 ;
}
static void F_673 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_991 * V_992 ;
enum V_188 V_188 ;
T_2 V_189 ;
V_189 = F_10 ( F_69 ( V_34 -> V_103 ) ) ;
V_188 = ( V_189 & V_1084 ) >> V_1085 ;
if ( F_434 ( V_44 ) || F_435 ( V_44 ) )
F_662 ( V_2 , V_188 , V_34 ) ;
else if ( F_40 ( V_44 ) )
F_661 ( V_2 , V_188 , V_34 ) ;
else
F_664 ( V_2 , V_188 , V_34 ) ;
V_992 = V_34 -> V_216 ;
if ( V_992 ) {
F_31 ( ! V_992 -> V_1010 . V_711 ( V_2 , V_992 ,
& V_34 -> V_184 ) ) ;
}
if ( F_60 ( V_44 ) -> V_110 < 9 &&
( V_188 == V_590 ) && F_10 ( V_231 ) & V_157 ) {
V_34 -> V_234 = true ;
V_189 = F_10 ( F_72 ( V_123 ) ) ;
V_34 -> V_449 = ( ( V_448 & V_189 ) >>
V_1008 ) + 1 ;
F_633 ( V_41 , V_34 ) ;
}
}
static bool F_674 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_140 V_141 ;
unsigned long V_1073 ;
bool V_94 ;
V_141 = F_425 ( V_41 -> V_101 ) ;
if ( ! F_84 ( V_2 , V_141 ) )
return false ;
V_1073 = F_229 ( V_141 ) ;
V_34 -> V_216 = NULL ;
V_94 = F_666 ( V_41 , V_34 , & V_1073 ) ;
if ( F_40 ( V_2 ) ) {
F_667 ( V_41 , V_34 ,
& V_1073 ) ;
F_31 ( V_94 && V_34 -> V_233 ) ;
if ( V_34 -> V_233 )
V_94 = true ;
}
if ( ! V_94 )
goto V_935;
if ( ! V_34 -> V_233 ) {
F_673 ( V_41 , V_34 ) ;
F_592 ( V_41 , V_34 ) ;
}
F_593 ( V_41 , V_34 ) ;
V_34 -> V_1086 =
F_10 ( F_675 ( V_41 -> V_101 ) ) & V_1087 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
F_676 ( V_44 , V_41 , V_34 ) ;
}
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
V_34 -> V_380 . V_412 = - 1 ;
V_34 -> V_380 . V_524 &= ~ ( 1 << V_534 ) ;
}
V_141 = F_426 ( V_41 -> V_101 ) ;
if ( F_84 ( V_2 , V_141 ) ) {
V_1073 |= F_229 ( V_141 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 9 )
F_634 ( V_41 , V_34 ) ;
else
F_636 ( V_41 , V_34 ) ;
}
if ( F_237 ( V_44 ) )
V_34 -> V_543 = F_398 ( V_41 ) &&
( F_10 ( V_547 ) & V_548 ) ;
if ( V_34 -> V_103 != V_571 &&
! F_401 ( V_34 -> V_103 ) ) {
V_34 -> V_572 =
F_10 ( F_402 ( V_34 -> V_103 ) ) + 1 ;
} else {
V_34 -> V_572 = 1 ;
}
V_935:
F_429 (power_domain, power_domain_mask)
F_85 ( V_2 , V_141 ) ;
return V_94 ;
}
static void F_677 ( struct V_93 * V_41 , T_1 V_45 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_2 V_1088 = 0 , V_253 = 0 ;
if ( V_332 && V_332 -> V_337 ) {
unsigned int V_254 = V_332 -> V_45 . V_346 ;
unsigned int V_249 = V_332 -> V_45 . V_347 ;
unsigned int V_325 = F_678 ( V_254 ) * 4 ;
switch ( V_325 ) {
default:
F_318 ( 1 , L_176 ,
V_254 , V_325 ) ;
V_325 = 256 ;
case 256 :
case 512 :
case 1024 :
case 2048 :
break;
}
V_1088 |= V_138 |
V_1089 |
V_1090 |
F_679 ( V_325 ) ;
V_253 = ( V_249 << 12 ) | V_254 ;
}
if ( V_40 -> V_1091 != 0 &&
( V_40 -> V_1092 != V_45 ||
V_40 -> V_1093 != V_253 ||
V_40 -> V_1091 != V_1088 ) ) {
F_124 ( F_81 ( V_123 ) , 0 ) ;
F_125 ( F_81 ( V_123 ) ) ;
V_40 -> V_1091 = 0 ;
}
if ( V_40 -> V_1092 != V_45 ) {
F_124 ( F_680 ( V_123 ) , V_45 ) ;
V_40 -> V_1092 = V_45 ;
}
if ( V_40 -> V_1093 != V_253 ) {
F_124 ( V_1094 , V_253 ) ;
V_40 -> V_1093 = V_253 ;
}
if ( V_40 -> V_1091 != V_1088 ) {
F_124 ( F_81 ( V_123 ) , V_1088 ) ;
F_125 ( F_81 ( V_123 ) ) ;
V_40 -> V_1091 = V_1088 ;
}
}
static void F_681 ( struct V_93 * V_41 , T_1 V_45 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_2 V_1088 = 0 ;
if ( V_332 && V_332 -> V_337 ) {
V_1088 = V_1095 ;
switch ( V_332 -> V_45 . V_346 ) {
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
F_173 ( V_332 -> V_45 . V_346 ) ;
return;
}
V_1088 |= V_101 << 28 ;
if ( F_22 ( V_44 ) )
V_1088 |= V_1099 ;
if ( V_332 -> V_45 . V_258 == F_229 ( V_367 ) )
V_1088 |= V_1100 ;
}
if ( V_40 -> V_1091 != V_1088 ) {
F_124 ( F_81 ( V_101 ) , V_1088 ) ;
F_125 ( F_81 ( V_101 ) ) ;
V_40 -> V_1091 = V_1088 ;
}
F_124 ( F_680 ( V_101 ) , V_45 ) ;
F_125 ( F_680 ( V_101 ) ) ;
V_40 -> V_1092 = V_45 ;
}
static void F_682 ( struct V_93 * V_41 ,
const struct V_334 * V_332 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
int V_101 = V_40 -> V_101 ;
T_1 V_45 = V_40 -> V_1101 ;
T_1 V_540 = 0 ;
if ( V_332 ) {
int V_280 = V_332 -> V_45 . V_344 ;
int V_281 = V_332 -> V_45 . V_345 ;
if ( V_280 < 0 ) {
V_540 |= V_1102 << V_1103 ;
V_280 = - V_280 ;
}
V_540 |= V_280 << V_1103 ;
if ( V_281 < 0 ) {
V_540 |= V_1102 << V_1104 ;
V_281 = - V_281 ;
}
V_540 |= V_281 << V_1104 ;
if ( F_162 ( V_44 ) &&
V_332 -> V_45 . V_258 == F_229 ( V_367 ) ) {
V_45 += ( V_332 -> V_45 . V_347 *
V_332 -> V_45 . V_346 - 1 ) * 4 ;
}
}
F_124 ( F_683 ( V_101 ) , V_540 ) ;
if ( F_79 ( V_44 ) || F_80 ( V_44 ) )
F_677 ( V_41 , V_45 , V_332 ) ;
else
F_681 ( V_41 , V_45 , V_332 ) ;
}
static bool F_684 ( struct V_43 * V_44 ,
T_2 V_254 , T_2 V_249 )
{
if ( V_254 == 0 || V_249 == 0 )
return false ;
if ( F_79 ( V_44 ) || F_80 ( V_44 ) ) {
if ( ( V_254 & 63 ) != 0 )
return false ;
if ( V_254 > ( F_79 ( V_44 ) ? 64 : 512 ) )
return false ;
if ( V_249 > 1023 )
return false ;
} else {
switch ( V_254 | V_249 ) {
case 256 :
case 128 :
if ( F_57 ( V_44 ) )
return false ;
case 64 :
break;
default:
return false ;
}
}
return true ;
}
struct V_257 *
F_685 ( struct V_43 * V_44 ,
struct V_316 * V_317 ,
struct V_270 * V_271 )
{
struct V_927 * V_928 ;
int V_273 ;
V_928 = F_502 ( sizeof( * V_928 ) , V_714 ) ;
if ( ! V_928 )
return F_686 ( - V_713 ) ;
V_273 = F_210 ( V_44 , V_928 , V_317 , V_271 ) ;
if ( V_273 )
goto V_79;
return & V_928 -> V_45 ;
V_79:
F_218 ( V_928 ) ;
return F_686 ( V_273 ) ;
}
static struct V_257 *
F_687 ( struct V_43 * V_44 ,
struct V_316 * V_317 ,
struct V_270 * V_271 )
{
struct V_257 * V_96 ;
int V_273 ;
V_273 = F_688 ( V_44 ) ;
if ( V_273 )
return F_686 ( V_273 ) ;
V_96 = F_685 ( V_44 , V_317 , V_271 ) ;
F_4 ( & V_44 -> V_274 ) ;
return V_96 ;
}
static T_1
F_689 ( int V_254 , int V_984 )
{
T_1 V_286 = F_185 ( V_254 * V_984 , 8 ) ;
return F_178 ( V_286 , 64 ) ;
}
static T_1
F_690 ( struct V_511 * V_422 , int V_984 )
{
T_1 V_286 = F_689 ( V_422 -> V_886 , V_984 ) ;
return F_691 ( V_286 * V_422 -> V_885 ) ;
}
static struct V_257 *
F_692 ( struct V_43 * V_44 ,
struct V_511 * V_422 ,
int V_1105 , int V_984 )
{
struct V_257 * V_96 ;
struct V_270 * V_271 ;
struct V_316 V_317 = { 0 } ;
V_271 = F_693 ( V_44 ,
F_690 ( V_422 , V_984 ) ) ;
if ( V_271 == NULL )
return F_686 ( - V_713 ) ;
V_317 . V_254 = V_422 -> V_886 ;
V_317 . V_249 = V_422 -> V_885 ;
V_317 . V_266 [ 0 ] = F_689 ( V_317 . V_254 ,
V_984 ) ;
V_317 . V_250 = F_694 ( V_984 , V_1105 ) ;
V_96 = F_687 ( V_44 , & V_317 , V_271 ) ;
if ( F_508 ( V_96 ) )
F_695 ( & V_271 -> V_45 ) ;
return V_96 ;
}
static struct V_257 *
F_696 ( struct V_43 * V_44 ,
struct V_511 * V_422 )
{
#ifdef F_697
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_270 * V_271 ;
struct V_257 * V_96 ;
if ( ! V_2 -> V_1106 )
return NULL ;
if ( ! V_2 -> V_1106 -> V_96 )
return NULL ;
V_271 = V_2 -> V_1106 -> V_96 -> V_271 ;
F_614 ( ! V_271 ) ;
V_96 = & V_2 -> V_1106 -> V_96 -> V_45 ;
if ( V_96 -> V_266 [ 0 ] < F_689 ( V_422 -> V_886 ,
V_96 -> V_786 ) )
return NULL ;
if ( V_271 -> V_45 . V_253 < V_422 -> V_885 * V_96 -> V_266 [ 0 ] )
return NULL ;
F_214 ( V_96 ) ;
return V_96 ;
#else
return NULL ;
#endif
}
static int F_698 ( struct V_49 * V_39 ,
struct V_93 * V_41 ,
struct V_511 * V_422 ,
struct V_257 * V_96 ,
int V_280 , int V_281 )
{
struct V_331 * V_332 ;
int V_886 , V_885 ;
int V_273 ;
V_332 = F_699 ( V_39 , V_41 -> V_95 ) ;
if ( F_508 ( V_332 ) )
return F_509 ( V_332 ) ;
if ( V_422 )
F_700 ( V_422 , & V_886 , & V_885 ) ;
else
V_886 = V_885 = 0 ;
V_273 = F_701 ( V_332 , V_96 ? V_41 : NULL ) ;
if ( V_273 )
return V_273 ;
F_702 ( V_332 , V_96 ) ;
V_332 -> V_344 = 0 ;
V_332 -> V_345 = 0 ;
V_332 -> V_346 = V_886 ;
V_332 -> V_347 = V_885 ;
V_332 -> V_340 = V_280 << 16 ;
V_332 -> V_341 = V_281 << 16 ;
V_332 -> V_342 = V_886 << 16 ;
V_332 -> V_343 = V_885 << 16 ;
return 0 ;
}
bool F_703 ( struct V_50 * V_51 ,
struct V_511 * V_422 ,
struct V_1107 * V_1108 ,
struct V_1109 * V_1110 )
{
struct V_40 * V_40 ;
struct V_46 * V_46 =
F_704 ( V_51 ) ;
struct V_93 * V_1111 ;
struct V_604 * V_47 = & V_46 -> V_45 ;
struct V_93 * V_41 = NULL ;
struct V_43 * V_44 = V_47 -> V_44 ;
struct V_257 * V_96 ;
struct V_1112 * V_97 = & V_44 -> V_1113 ;
struct V_49 * V_39 = NULL , * V_1114 = NULL ;
struct V_52 * V_53 ;
struct V_33 * V_48 ;
int V_273 , V_54 = - 1 ;
F_159 ( L_177 ,
V_51 -> V_45 . V_378 , V_51 -> V_8 ,
V_47 -> V_45 . V_378 , V_47 -> V_8 ) ;
V_1108 -> V_1114 = NULL ;
V_454:
V_273 = F_705 ( & V_97 -> V_1115 , V_1110 ) ;
if ( V_273 )
goto V_779;
if ( V_51 -> V_39 -> V_41 ) {
V_41 = V_51 -> V_39 -> V_41 ;
V_273 = F_705 ( & V_41 -> V_1116 , V_1110 ) ;
if ( V_273 )
goto V_779;
goto V_82;
}
F_219 (dev, possible_crtc) {
V_54 ++ ;
if ( ! ( V_47 -> V_1117 & ( 1 << V_54 ) ) )
continue;
V_273 = F_705 ( & V_1111 -> V_1116 , V_1110 ) ;
if ( V_273 )
goto V_779;
if ( V_1111 -> V_39 -> V_499 ) {
F_706 ( & V_1111 -> V_1116 ) ;
continue;
}
V_41 = V_1111 ;
break;
}
if ( ! V_41 ) {
F_159 ( L_178 ) ;
goto V_779;
}
V_82:
V_40 = F_50 ( V_41 ) ;
V_273 = F_705 ( & V_41 -> V_95 -> V_1116 , V_1110 ) ;
if ( V_273 )
goto V_779;
V_39 = F_707 ( V_44 ) ;
V_1114 = F_707 ( V_44 ) ;
if ( ! V_39 || ! V_1114 ) {
V_273 = - V_713 ;
goto V_779;
}
V_39 -> V_1118 = V_1110 ;
V_1114 -> V_1118 = V_1110 ;
V_53 = F_708 ( V_39 , V_51 ) ;
if ( F_508 ( V_53 ) ) {
V_273 = F_509 ( V_53 ) ;
goto V_779;
}
V_273 = F_709 ( V_53 , V_41 ) ;
if ( V_273 )
goto V_779;
V_48 = F_507 ( V_39 , V_40 ) ;
if ( F_508 ( V_48 ) ) {
V_273 = F_509 ( V_48 ) ;
goto V_779;
}
V_48 -> V_45 . V_94 = V_48 -> V_45 . V_499 = true ;
if ( ! V_422 )
V_422 = & V_1119 ;
V_96 = F_696 ( V_44 , V_422 ) ;
if ( V_96 == NULL ) {
F_159 ( L_179 ) ;
V_96 = F_692 ( V_44 , V_422 , 24 , 32 ) ;
} else
F_159 ( L_180 ) ;
if ( F_508 ( V_96 ) ) {
F_159 ( L_181 ) ;
goto V_779;
}
V_273 = F_698 ( V_39 , V_41 , V_422 , V_96 , 0 , 0 ) ;
if ( V_273 )
goto V_779;
F_213 ( V_96 ) ;
V_273 = F_491 ( & V_48 -> V_45 , V_422 ) ;
if ( V_273 )
goto V_779;
V_273 = F_495 ( F_708 ( V_1114 , V_51 ) ) ;
if ( ! V_273 )
V_273 = F_495 ( F_710 ( V_1114 , V_41 ) ) ;
if ( ! V_273 )
V_273 = F_495 ( F_699 ( V_1114 , V_41 -> V_95 ) ) ;
if ( V_273 ) {
F_159 ( L_182 , V_273 ) ;
goto V_779;
}
V_273 = F_711 ( V_39 ) ;
if ( V_273 ) {
F_159 ( L_183 ) ;
goto V_779;
}
V_1108 -> V_1114 = V_1114 ;
F_308 ( V_44 , V_40 -> V_101 ) ;
return true ;
V_779:
F_712 ( V_39 ) ;
F_712 ( V_1114 ) ;
V_1114 = V_39 = NULL ;
if ( V_273 == - V_277 ) {
F_713 ( V_1110 ) ;
goto V_454;
}
return false ;
}
void F_714 ( struct V_50 * V_51 ,
struct V_1107 * V_1108 ,
struct V_1109 * V_1110 )
{
struct V_46 * V_46 =
F_704 ( V_51 ) ;
struct V_604 * V_47 = & V_46 -> V_45 ;
struct V_49 * V_39 = V_1108 -> V_1114 ;
int V_273 ;
F_159 ( L_177 ,
V_51 -> V_45 . V_378 , V_51 -> V_8 ,
V_47 -> V_45 . V_378 , V_47 -> V_8 ) ;
if ( ! V_39 )
return;
V_273 = F_711 ( V_39 ) ;
if ( V_273 ) {
F_159 ( L_184 , V_273 ) ;
F_712 ( V_39 ) ;
}
}
static int F_715 ( struct V_43 * V_44 ,
const struct V_33 * V_34 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_66 = V_34 -> V_184 . V_66 ;
if ( ( V_66 & V_947 ) == V_870 )
return V_2 -> V_798 . V_908 ;
else if ( F_14 ( V_44 ) )
return 120000 ;
else if ( ! F_57 ( V_44 ) )
return 96000 ;
else
return 48000 ;
}
static void F_610 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
int V_101 = V_34 -> V_103 ;
T_1 V_66 = V_34 -> V_184 . V_66 ;
T_1 V_802 ;
T_3 clock ;
int V_35 ;
int V_57 = F_715 ( V_44 , V_34 ) ;
if ( ( V_66 & V_1120 ) == 0 )
V_802 = V_34 -> V_184 . V_703 ;
else
V_802 = V_34 -> V_184 . V_704 ;
clock . V_67 = ( V_802 & V_1121 ) >> V_1122 ;
if ( F_18 ( V_44 ) ) {
clock . V_63 = F_716 ( ( V_802 & V_1123 ) >> V_1124 ) - 1 ;
clock . V_59 = ( V_802 & V_1125 ) >> V_1126 ;
} else {
clock . V_63 = ( V_802 & V_1127 ) >> V_1124 ;
clock . V_59 = ( V_802 & V_1128 ) >> V_1126 ;
}
if ( ! F_57 ( V_44 ) ) {
if ( F_18 ( V_44 ) )
clock . V_61 = F_716 ( ( V_66 & V_1129 ) >>
V_860 ) ;
else
clock . V_61 = F_716 ( ( V_66 & V_1130 ) >>
V_861 ) ;
switch ( V_66 & V_1131 ) {
case V_857 :
clock . V_62 = V_66 & V_863 ?
5 : 10 ;
break;
case V_856 :
clock . V_62 = V_66 & V_864 ?
7 : 14 ;
break;
default:
F_159 ( L_185
L_186 , ( int ) ( V_66 & V_1131 ) ) ;
return;
}
if ( F_18 ( V_44 ) )
V_35 = F_32 ( V_57 , & clock ) ;
else
V_35 = F_34 ( V_57 , & clock ) ;
} else {
T_1 V_1132 = F_141 ( V_44 ) ? 0 : F_10 ( V_134 ) ;
bool V_987 = ( V_101 == 1 ) && ( V_1132 & V_167 ) ;
if ( V_987 ) {
clock . V_61 = F_716 ( ( V_66 & V_1133 ) >>
V_861 ) ;
if ( V_1132 & V_1134 )
clock . V_62 = 7 ;
else
clock . V_62 = 14 ;
} else {
if ( V_66 & V_872 )
clock . V_61 = 2 ;
else {
clock . V_61 = ( ( V_66 & V_1135 ) >>
V_861 ) + 2 ;
}
if ( V_66 & V_873 )
clock . V_62 = 4 ;
else
clock . V_62 = 2 ;
}
V_35 = F_34 ( V_57 , & clock ) ;
}
V_34 -> V_35 = V_35 ;
}
int F_717 ( int V_1136 ,
const struct V_790 * V_791 )
{
if ( ! V_791 -> V_796 )
return 0 ;
return F_48 ( ( T_6 ) V_791 -> V_795 * V_1136 , V_791 -> V_796 ) ;
}
static void F_640 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_1 * V_2 = F_123 ( V_41 -> V_45 . V_44 ) ;
F_610 ( V_41 , V_34 ) ;
V_34 -> V_45 . V_98 . V_99 =
F_717 ( F_21 ( V_2 , V_34 ) ,
& V_34 -> V_568 ) ;
}
struct V_511 * F_718 ( struct V_43 * V_44 ,
struct V_93 * V_41 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
enum V_100 V_103 = V_40 -> V_97 -> V_103 ;
struct V_511 * V_422 ;
struct V_33 * V_34 ;
int V_1137 = F_10 ( F_330 ( V_103 ) ) ;
int V_894 = F_10 ( F_334 ( V_103 ) ) ;
int V_1138 = F_10 ( F_336 ( V_103 ) ) ;
int V_1139 = F_10 ( F_340 ( V_103 ) ) ;
enum V_101 V_101 = V_40 -> V_101 ;
V_422 = F_502 ( sizeof( * V_422 ) , V_714 ) ;
if ( ! V_422 )
return NULL ;
V_34 = F_502 ( sizeof( * V_34 ) , V_714 ) ;
if ( ! V_34 ) {
F_218 ( V_422 ) ;
return NULL ;
}
V_34 -> V_103 = (enum V_100 ) V_101 ;
V_34 -> V_572 = 1 ;
V_34 -> V_184 . V_66 = F_10 ( F_64 ( V_101 ) ) ;
V_34 -> V_184 . V_703 = F_10 ( F_485 ( V_101 ) ) ;
V_34 -> V_184 . V_704 = F_10 ( F_486 ( V_101 ) ) ;
F_610 ( V_40 , V_34 ) ;
V_422 -> clock = V_34 -> V_35 / V_34 -> V_572 ;
V_422 -> V_886 = ( V_1137 & 0xffff ) + 1 ;
V_422 -> V_887 = ( ( V_1137 & 0xffff0000 ) >> 16 ) + 1 ;
V_422 -> V_888 = ( V_894 & 0xffff ) + 1 ;
V_422 -> V_889 = ( ( V_894 & 0xffff0000 ) >> 16 ) + 1 ;
V_422 -> V_885 = ( V_1138 & 0xffff ) + 1 ;
V_422 -> V_890 = ( ( V_1138 & 0xffff0000 ) >> 16 ) + 1 ;
V_422 -> V_891 = ( V_1139 & 0xffff ) + 1 ;
V_422 -> V_892 = ( ( V_1139 & 0xffff0000 ) >> 16 ) + 1 ;
F_597 ( V_422 ) ;
F_218 ( V_34 ) ;
return V_422 ;
}
void F_719 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( V_2 -> V_550 . V_1140 )
return;
F_193 ( V_2 ) ;
F_720 ( V_2 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 6 )
F_721 ( V_2 ) ;
V_2 -> V_550 . V_1140 = true ;
}
void F_722 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! V_2 -> V_550 . V_1140 )
return;
V_2 -> V_550 . V_1140 = false ;
if ( F_60 ( V_44 ) -> V_110 >= 6 )
F_723 ( V_44 -> V_104 ) ;
F_197 ( V_2 ) ;
}
static void F_724 ( struct V_93 * V_41 )
{
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_470 * V_471 ;
F_279 ( & V_44 -> V_432 ) ;
V_471 = V_40 -> V_433 ;
V_40 -> V_433 = NULL ;
F_280 ( & V_44 -> V_432 ) ;
if ( V_471 ) {
F_725 ( & V_471 -> V_471 ) ;
F_218 ( V_471 ) ;
}
F_726 ( V_41 ) ;
F_218 ( V_40 ) ;
}
static void F_727 ( struct V_1141 * V_1142 )
{
struct V_470 * V_471 =
F_728 ( V_1142 , struct V_470 , V_471 ) ;
struct V_40 * V_41 = F_50 ( V_471 -> V_41 ) ;
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_329 * V_95 = V_41 -> V_45 . V_95 ;
F_2 ( & V_44 -> V_274 ) ;
F_199 ( V_471 -> V_1143 , V_95 -> V_39 -> V_258 ) ;
F_211 ( & V_471 -> V_475 -> V_45 ) ;
if ( V_471 -> V_1144 )
F_729 ( & V_471 -> V_1144 , NULL ) ;
F_4 ( & V_44 -> V_274 ) ;
F_730 ( V_44 , F_216 ( V_95 ) -> V_356 ) ;
F_381 ( V_41 ) ;
F_213 ( V_471 -> V_1143 ) ;
F_614 ( F_307 ( & V_41 -> V_469 ) == 0 ) ;
F_731 ( & V_41 -> V_469 ) ;
F_218 ( V_471 ) ;
}
static void F_732 ( struct V_43 * V_44 ,
struct V_93 * V_41 )
{
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_470 * V_471 ;
unsigned long V_326 ;
if ( V_40 == NULL )
return;
F_733 ( & V_44 -> V_432 , V_326 ) ;
V_471 = V_40 -> V_433 ;
F_310 () ;
if ( V_471 == NULL || F_307 ( & V_471 -> V_430 ) < V_1145 ) {
F_734 ( & V_44 -> V_432 , V_326 ) ;
return;
}
F_309 ( V_40 ) ;
F_734 ( & V_44 -> V_432 , V_326 ) ;
}
void F_735 ( struct V_43 * V_44 , int V_101 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
F_732 ( V_44 , V_41 ) ;
}
void F_267 ( struct V_43 * V_44 , int V_146 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_93 * V_41 = V_2 -> V_1146 [ V_146 ] ;
F_732 ( V_44 , V_41 ) ;
}
static bool F_736 ( T_1 V_1147 , T_1 V_1148 )
{
return ! ( ( V_1147 - V_1148 ) & 0x80000000 ) ;
}
static bool F_737 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
unsigned V_429 ;
V_429 = F_285 ( & V_2 -> V_431 ) ;
if ( V_41 -> V_429 != V_429 )
return true ;
if ( F_60 ( V_44 ) -> V_110 < 5 && ! F_17 ( V_44 ) )
return true ;
return ( F_10 ( F_738 ( V_41 -> V_146 ) ) & ~ 0xfff ) ==
V_41 -> V_433 -> V_1149 &&
F_736 ( F_10 ( F_739 ( V_41 -> V_101 ) ) ,
V_41 -> V_433 -> V_1150 ) ;
}
void F_266 ( struct V_43 * V_44 , int V_146 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 =
F_50 ( V_2 -> V_1146 [ V_146 ] ) ;
unsigned long V_326 ;
F_733 ( & V_44 -> V_432 , V_326 ) ;
if ( V_40 -> V_433 && F_737 ( V_40 ) )
F_740 ( & V_40 -> V_433 -> V_430 ) ;
F_734 ( & V_44 -> V_432 , V_326 ) ;
}
static inline void F_741 ( struct V_470 * V_471 )
{
F_742 () ;
F_743 ( & V_471 -> V_430 , V_1151 ) ;
F_742 () ;
}
static int F_744 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
struct V_1154 * V_1155 = V_1153 -> V_1155 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_1 V_1156 ;
int V_273 ;
V_273 = F_745 ( V_1153 , 6 ) ;
if ( V_273 )
return V_273 ;
if ( V_40 -> V_146 )
V_1156 = V_1157 ;
else
V_1156 = V_1158 ;
F_746 ( V_1155 , V_1159 | V_1156 ) ;
F_746 ( V_1155 , V_1160 ) ;
F_746 ( V_1155 , V_1161 |
F_747 ( V_40 -> V_146 ) ) ;
F_746 ( V_1155 , V_96 -> V_266 [ 0 ] ) ;
F_746 ( V_1155 , V_40 -> V_433 -> V_1149 ) ;
F_746 ( V_1155 , 0 ) ;
F_741 ( V_40 -> V_433 ) ;
return 0 ;
}
static int F_748 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
struct V_1154 * V_1155 = V_1153 -> V_1155 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_1 V_1156 ;
int V_273 ;
V_273 = F_745 ( V_1153 , 6 ) ;
if ( V_273 )
return V_273 ;
if ( V_40 -> V_146 )
V_1156 = V_1157 ;
else
V_1156 = V_1158 ;
F_746 ( V_1155 , V_1159 | V_1156 ) ;
F_746 ( V_1155 , V_1160 ) ;
F_746 ( V_1155 , V_1162 |
F_747 ( V_40 -> V_146 ) ) ;
F_746 ( V_1155 , V_96 -> V_266 [ 0 ] ) ;
F_746 ( V_1155 , V_40 -> V_433 -> V_1149 ) ;
F_746 ( V_1155 , V_1160 ) ;
F_741 ( V_40 -> V_433 ) ;
return 0 ;
}
static int F_749 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
struct V_1154 * V_1155 = V_1153 -> V_1155 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_2 V_1163 , V_1164 ;
int V_273 ;
V_273 = F_745 ( V_1153 , 4 ) ;
if ( V_273 )
return V_273 ;
F_746 ( V_1155 , V_1161 |
F_747 ( V_40 -> V_146 ) ) ;
F_746 ( V_1155 , V_96 -> V_266 [ 0 ] ) ;
F_746 ( V_1155 , V_40 -> V_433 -> V_1149 |
V_271 -> V_322 ) ;
V_1163 = 0 ;
V_1164 = F_10 ( F_287 ( V_40 -> V_101 ) ) & 0x0fff0fff ;
F_746 ( V_1155 , V_1163 | V_1164 ) ;
F_741 ( V_40 -> V_433 ) ;
return 0 ;
}
static int F_750 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
struct V_1154 * V_1155 = V_1153 -> V_1155 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_2 V_1163 , V_1164 ;
int V_273 ;
V_273 = F_745 ( V_1153 , 4 ) ;
if ( V_273 )
return V_273 ;
F_746 ( V_1155 , V_1161 |
F_747 ( V_40 -> V_146 ) ) ;
F_746 ( V_1155 , V_96 -> V_266 [ 0 ] | V_271 -> V_322 ) ;
F_746 ( V_1155 , V_40 -> V_433 -> V_1149 ) ;
V_1163 = 0 ;
V_1164 = F_10 ( F_287 ( V_40 -> V_101 ) ) & 0x0fff0fff ;
F_746 ( V_1155 , V_1163 | V_1164 ) ;
F_741 ( V_40 -> V_433 ) ;
return 0 ;
}
static int F_751 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
struct V_1154 * V_1155 = V_1153 -> V_1155 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
T_2 V_1165 = 0 ;
int V_1166 , V_273 ;
switch ( V_40 -> V_146 ) {
case V_1167 :
V_1165 = V_1168 ;
break;
case V_363 :
V_1165 = V_1169 ;
break;
case V_1170 :
V_1165 = V_1171 ;
break;
default:
F_318 ( 1 , L_187 ) ;
return - V_424 ;
}
V_1166 = 4 ;
if ( V_1155 -> V_378 == V_1172 ) {
V_1166 += 6 ;
if ( F_752 ( V_44 ) )
V_1166 += 2 ;
}
V_273 = F_753 ( V_1153 ) ;
if ( V_273 )
return V_273 ;
V_273 = F_745 ( V_1153 , V_1166 ) ;
if ( V_273 )
return V_273 ;
if ( V_1155 -> V_378 == V_1172 ) {
F_746 ( V_1155 , F_754 ( 1 ) ) ;
F_755 ( V_1155 , V_1173 ) ;
F_746 ( V_1155 , ~ ( V_1174 |
V_1175 |
V_1176 ) ) ;
if ( F_752 ( V_44 ) )
F_746 ( V_1155 , V_1177 |
V_1178 ) ;
else
F_746 ( V_1155 , V_1179 |
V_1178 ) ;
F_755 ( V_1155 , V_1173 ) ;
F_746 ( V_1155 , V_1155 -> V_1180 . V_1149 + 256 ) ;
if ( F_752 ( V_44 ) ) {
F_746 ( V_1155 , 0 ) ;
F_746 ( V_1155 , V_1160 ) ;
}
}
F_746 ( V_1155 , V_1162 | V_1165 ) ;
F_746 ( V_1155 , ( V_96 -> V_266 [ 0 ] | V_271 -> V_322 ) ) ;
F_746 ( V_1155 , V_40 -> V_433 -> V_1149 ) ;
F_746 ( V_1155 , ( V_1160 ) ) ;
F_741 ( V_40 -> V_433 ) ;
return 0 ;
}
static bool F_756 ( struct V_1154 * V_1155 ,
struct V_270 * V_271 )
{
if ( V_1155 == NULL )
return true ;
if ( F_60 ( V_1155 -> V_44 ) -> V_110 < 5 )
return false ;
if ( V_725 . F_756 < 0 )
return false ;
else if ( V_725 . F_756 > 0 )
return true ;
else if ( V_725 . V_1181 )
return true ;
else if ( V_271 -> V_45 . V_1182 &&
! F_757 ( V_271 -> V_45 . V_1182 -> V_1183 ,
false ) )
return true ;
else
return V_1155 != F_758 ( V_271 -> V_1184 ) ;
}
static void F_759 ( struct V_40 * V_40 ,
unsigned int V_258 ,
struct V_470 * V_471 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_257 * V_96 = V_40 -> V_45 . V_95 -> V_96 ;
const enum V_101 V_101 = V_40 -> V_101 ;
T_1 V_1185 , V_325 , V_247 ;
V_1185 = F_10 ( F_93 ( V_101 , 0 ) ) ;
V_1185 &= ~ V_1003 ;
switch ( V_96 -> V_265 [ 0 ] ) {
case V_242 :
break;
case V_243 :
V_1185 |= V_396 ;
break;
case V_244 :
V_1185 |= V_397 ;
break;
case V_245 :
V_1185 |= V_398 ;
break;
default:
F_173 ( V_96 -> V_265 [ 0 ] ) ;
}
if ( F_182 ( V_258 ) ) {
V_247 = F_174 ( V_2 , V_96 -> V_265 [ 0 ] , 0 ) ;
V_325 = F_185 ( V_96 -> V_249 , V_247 ) ;
} else {
V_325 = V_96 -> V_266 [ 0 ] /
F_240 ( V_2 , V_96 -> V_265 [ 0 ] ,
V_96 -> V_250 ) ;
}
F_124 ( F_93 ( V_101 , 0 ) , V_1185 ) ;
F_124 ( F_258 ( V_101 , 0 ) , V_325 ) ;
F_124 ( F_262 ( V_101 , 0 ) , V_471 -> V_1149 ) ;
F_125 ( F_262 ( V_101 , 0 ) ) ;
}
static void F_760 ( struct V_40 * V_40 ,
struct V_470 * V_471 )
{
struct V_43 * V_44 = V_40 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_927 * V_928 =
F_183 ( V_40 -> V_45 . V_95 -> V_96 ) ;
struct V_270 * V_271 = V_928 -> V_271 ;
T_5 V_9 = F_87 ( V_40 -> V_146 ) ;
T_1 V_358 ;
V_358 = F_10 ( V_9 ) ;
if ( V_271 -> V_322 != V_353 )
V_358 |= V_364 ;
else
V_358 &= ~ V_364 ;
F_124 ( V_9 , V_358 ) ;
F_124 ( F_231 ( V_40 -> V_146 ) , V_471 -> V_1149 ) ;
F_125 ( F_231 ( V_40 -> V_146 ) ) ;
}
static void F_761 ( struct V_1186 * V_1187 )
{
struct V_40 * V_41 = V_1187 -> V_41 ;
struct V_470 * V_471 ;
F_279 ( & V_41 -> V_45 . V_44 -> V_432 ) ;
V_471 = V_41 -> V_433 ;
F_280 ( & V_41 -> V_45 . V_44 -> V_432 ) ;
if ( V_471 == NULL )
return;
F_741 ( V_471 ) ;
F_762 ( V_41 ) ;
if ( F_60 ( V_1187 -> V_725 ) -> V_110 >= 9 )
F_759 ( V_41 , V_1187 -> V_258 , V_471 ) ;
else
F_760 ( V_41 , V_471 ) ;
F_763 ( V_41 ) ;
}
static void F_764 ( struct V_1141 * V_471 )
{
struct V_1186 * V_1187 =
F_728 ( V_471 , struct V_1186 , V_471 ) ;
struct V_927 * V_928 =
F_183 ( V_1187 -> V_41 -> V_45 . V_95 -> V_96 ) ;
struct V_270 * V_271 = V_928 -> V_271 ;
if ( V_1187 -> V_1153 ) {
F_31 ( F_765 ( V_1187 -> V_1153 ,
false , NULL ,
& V_1187 -> V_725 -> V_544 . V_1188 ) ) ;
F_766 ( V_1187 -> V_1153 ) ;
}
if ( V_271 -> V_45 . V_1182 )
F_31 ( F_767 ( V_271 -> V_45 . V_1182 -> V_1183 ,
false , false ,
V_1189 ) < 0 ) ;
F_761 ( V_1187 ) ;
F_218 ( V_1187 ) ;
}
static int F_768 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_270 * V_271 )
{
struct V_1186 * V_1187 ;
V_1187 = F_769 ( sizeof( * V_1187 ) , V_714 ) ;
if ( V_1187 == NULL )
return - V_713 ;
V_1187 -> V_725 = F_123 ( V_44 ) ;
V_1187 -> V_1153 = F_770 ( V_271 -> V_1184 ) ;
V_1187 -> V_41 = F_50 ( V_41 ) ;
V_1187 -> V_258 = V_41 -> V_95 -> V_39 -> V_258 ;
F_771 ( & V_1187 -> V_471 , F_764 ) ;
F_772 ( & V_1187 -> V_471 ) ;
return 0 ;
}
static int F_773 ( struct V_43 * V_44 ,
struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_270 * V_271 ,
struct V_1152 * V_1153 ,
T_2 V_326 )
{
return - V_424 ;
}
static bool F_774 ( struct V_43 * V_44 ,
struct V_93 * V_41 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_470 * V_471 = V_40 -> V_433 ;
T_1 V_1190 ;
if ( F_307 ( & V_471 -> V_430 ) >= V_1145 )
return true ;
if ( F_307 ( & V_471 -> V_430 ) < V_1151 )
return false ;
if ( ! V_471 -> V_1191 )
return false ;
if ( V_471 -> V_1192 == 0 ) {
if ( V_471 -> V_1144 &&
! F_775 ( V_471 -> V_1144 , true ) )
return false ;
V_471 -> V_1192 = F_776 ( V_41 ) ;
}
if ( F_776 ( V_41 ) - V_471 -> V_1192 < 3 )
return false ;
if ( F_60 ( V_44 ) -> V_110 >= 4 )
V_1190 = F_777 ( F_10 ( F_231 ( V_40 -> V_146 ) ) ) ;
else
V_1190 = F_10 ( F_234 ( V_40 -> V_146 ) ) ;
return V_1190 == V_471 -> V_1149 ;
}
void F_778 ( struct V_43 * V_44 , int V_101 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_470 * V_471 ;
F_31 ( ! F_779 () ) ;
if ( V_41 == NULL )
return;
F_780 ( & V_44 -> V_432 ) ;
V_471 = V_40 -> V_433 ;
if ( V_471 != NULL && F_774 ( V_44 , V_41 ) ) {
F_318 ( 1 , L_188 ,
V_471 -> V_1193 , F_781 ( V_44 , V_101 ) ) ;
F_309 ( V_40 ) ;
V_471 = NULL ;
}
if ( V_471 != NULL &&
F_781 ( V_44 , V_101 ) - V_471 -> V_1193 > 1 )
F_782 ( V_44 , V_471 -> V_1144 ) ;
F_783 ( & V_44 -> V_432 ) ;
}
static int F_784 ( struct V_93 * V_41 ,
struct V_257 * V_96 ,
struct V_1194 * V_472 ,
T_2 V_1195 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_257 * V_1143 = V_41 -> V_95 -> V_96 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_329 * V_95 = V_41 -> V_95 ;
enum V_101 V_101 = V_40 -> V_101 ;
struct V_470 * V_471 ;
struct V_1154 * V_1155 ;
bool V_1187 ;
struct V_1152 * V_1196 = NULL ;
int V_273 ;
if ( F_31 ( F_191 ( V_1143 ) == NULL ) )
return - V_278 ;
if ( V_96 -> V_250 != V_41 -> V_95 -> V_96 -> V_250 )
return - V_533 ;
if ( F_60 ( V_44 ) -> V_110 > 3 &&
( V_96 -> V_269 [ 0 ] != V_41 -> V_95 -> V_96 -> V_269 [ 0 ] ||
V_96 -> V_266 [ 0 ] != V_41 -> V_95 -> V_96 -> V_266 [ 0 ] ) )
return - V_533 ;
if ( F_785 ( & V_2 -> V_431 ) )
goto V_1197;
V_471 = F_502 ( sizeof( * V_471 ) , V_714 ) ;
if ( V_471 == NULL )
return - V_713 ;
V_471 -> V_472 = V_472 ;
V_471 -> V_41 = V_41 ;
V_471 -> V_1143 = V_1143 ;
F_771 ( & V_471 -> V_471 , F_727 ) ;
V_273 = F_100 ( V_41 ) ;
if ( V_273 )
goto V_1198;
F_279 ( & V_44 -> V_432 ) ;
if ( V_40 -> V_433 ) {
if ( F_774 ( V_44 , V_41 ) ) {
F_19 ( L_189 ) ;
F_309 ( V_40 ) ;
} else {
F_19 ( L_190 ) ;
F_280 ( & V_44 -> V_432 ) ;
F_101 ( V_41 ) ;
F_218 ( V_471 ) ;
return - V_278 ;
}
}
V_40 -> V_433 = V_471 ;
F_280 ( & V_44 -> V_432 ) ;
if ( F_307 ( & V_40 -> V_469 ) >= 2 )
F_786 ( V_2 -> V_474 ) ;
F_214 ( V_471 -> V_1143 ) ;
F_787 ( & V_271 -> V_45 ) ;
V_41 -> V_95 -> V_96 = V_96 ;
F_212 ( V_41 -> V_95 ) ;
F_383 ( V_40 ) ;
V_471 -> V_475 = V_271 ;
V_273 = F_688 ( V_44 ) ;
if ( V_273 )
goto V_1199;
V_40 -> V_429 = F_285 ( & V_2 -> V_431 ) ;
if ( F_788 ( V_40 -> V_429 ) ) {
V_273 = - V_1200 ;
goto V_1199;
}
F_789 ( & V_40 -> V_469 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 5 || F_17 ( V_44 ) )
V_471 -> V_1150 = F_10 ( F_739 ( V_101 ) ) + 1 ;
if ( F_15 ( V_44 ) || F_16 ( V_44 ) ) {
V_1155 = & V_2 -> V_1155 [ V_1201 ] ;
if ( V_271 -> V_322 != F_191 ( V_471 -> V_1143 ) -> V_322 )
V_1155 = NULL ;
} else if ( F_292 ( V_44 ) || F_237 ( V_44 ) ) {
V_1155 = & V_2 -> V_1155 [ V_1201 ] ;
} else if ( F_60 ( V_44 ) -> V_110 >= 7 ) {
V_1155 = F_758 ( V_271 -> V_1184 ) ;
if ( V_1155 == NULL || V_1155 -> V_378 != V_1172 )
V_1155 = & V_2 -> V_1155 [ V_1201 ] ;
} else {
V_1155 = & V_2 -> V_1155 [ V_1172 ] ;
}
V_1187 = F_756 ( V_1155 , V_271 ) ;
if ( ! V_1187 ) {
V_273 = F_790 ( V_271 , V_1155 , & V_1196 ) ;
if ( V_273 )
goto V_1202;
}
V_273 = F_190 ( V_96 , V_95 -> V_39 -> V_258 ) ;
if ( V_273 )
goto V_1202;
V_471 -> V_1149 = F_241 ( F_216 ( V_95 ) ,
V_271 , 0 ) ;
V_471 -> V_1149 += V_40 -> V_366 ;
if ( V_1187 ) {
V_273 = F_768 ( V_44 , V_41 , V_271 ) ;
if ( V_273 )
goto V_1203;
F_729 ( & V_471 -> V_1144 ,
V_271 -> V_1184 ) ;
} else {
if ( ! V_1196 ) {
V_1196 = F_791 ( V_1155 , NULL ) ;
if ( F_508 ( V_1196 ) ) {
V_273 = F_509 ( V_1196 ) ;
goto V_1203;
}
}
V_273 = V_2 -> V_427 . V_1204 ( V_44 , V_41 , V_96 , V_271 , V_1196 ,
V_1195 ) ;
if ( V_273 )
goto V_1203;
F_729 ( & V_471 -> V_1144 , V_1196 ) ;
}
if ( V_1196 )
F_792 ( V_1196 ) ;
V_471 -> V_1193 = F_776 ( V_41 ) ;
V_471 -> V_1191 = true ;
F_793 ( F_191 ( V_471 -> V_1143 ) , V_271 ,
F_216 ( V_95 ) -> V_356 ) ;
F_4 ( & V_44 -> V_274 ) ;
F_794 ( V_44 ,
F_216 ( V_95 ) -> V_356 ) ;
F_795 ( V_40 -> V_146 , V_271 ) ;
return 0 ;
V_1203:
F_199 ( V_96 , V_41 -> V_95 -> V_39 -> V_258 ) ;
V_1202:
if ( ! F_796 ( V_1196 ) )
F_792 ( V_1196 ) ;
F_731 ( & V_40 -> V_469 ) ;
F_4 ( & V_44 -> V_274 ) ;
V_1199:
V_41 -> V_95 -> V_96 = V_1143 ;
F_212 ( V_41 -> V_95 ) ;
F_695 ( & V_271 -> V_45 ) ;
F_213 ( V_471 -> V_1143 ) ;
F_279 ( & V_44 -> V_432 ) ;
V_40 -> V_433 = NULL ;
F_280 ( & V_44 -> V_432 ) ;
F_101 ( V_41 ) ;
V_1198:
F_218 ( V_471 ) ;
if ( V_273 == - V_1200 ) {
struct V_49 * V_39 ;
struct V_331 * V_332 ;
V_1197:
V_39 = F_707 ( V_44 ) ;
if ( ! V_39 )
return - V_713 ;
V_39 -> V_1118 = F_797 ( V_41 ) ;
V_454:
V_332 = F_699 ( V_39 , V_95 ) ;
V_273 = F_495 ( V_332 ) ;
if ( ! V_273 ) {
F_702 ( V_332 , V_96 ) ;
V_273 = F_701 ( V_332 , V_41 ) ;
if ( ! V_273 )
V_273 = F_711 ( V_39 ) ;
}
if ( V_273 == - V_277 ) {
F_713 ( V_39 -> V_1118 ) ;
F_798 ( V_39 ) ;
goto V_454;
}
if ( V_273 )
F_712 ( V_39 ) ;
if ( V_273 == 0 && V_472 ) {
F_279 ( & V_44 -> V_432 ) ;
F_311 ( V_41 , V_472 ) ;
F_280 ( & V_44 -> V_432 ) ;
}
}
return V_273 ;
}
static bool F_799 ( struct V_329 * V_146 ,
struct V_331 * V_39 )
{
struct V_334 * V_1205 = F_217 ( V_39 ) ;
struct V_334 * V_1206 = F_217 ( V_146 -> V_39 ) ;
if ( V_1205 -> V_337 != V_1206 -> V_337 )
return true ;
if ( ! V_1206 -> V_45 . V_96 || ! V_1205 -> V_45 . V_96 )
return false ;
if ( V_1206 -> V_45 . V_96 -> V_265 [ 0 ] != V_1205 -> V_45 . V_96 -> V_265 [ 0 ] ||
V_1206 -> V_45 . V_258 != V_1205 -> V_45 . V_258 ||
F_254 ( & V_1205 -> V_348 ) != F_254 ( & V_1206 -> V_348 ) ||
F_255 ( & V_1205 -> V_348 ) != F_255 ( & V_1206 -> V_348 ) ||
F_254 ( & V_1205 -> V_352 ) != F_254 ( & V_1206 -> V_352 ) ||
F_255 ( & V_1205 -> V_352 ) != F_255 ( & V_1206 -> V_352 ) )
return true ;
return false ;
}
static bool F_800 ( struct V_334 * V_39 )
{
int V_342 = F_254 ( & V_39 -> V_348 ) >> 16 ;
int V_343 = F_255 ( & V_39 -> V_348 ) >> 16 ;
int V_415 = F_254 ( & V_39 -> V_352 ) ;
int V_416 = F_255 ( & V_39 -> V_352 ) ;
return ( V_342 != V_415 || V_343 != V_416 ) ;
}
int F_801 ( struct V_38 * V_48 ,
struct V_331 * V_332 )
{
struct V_33 * V_34 = F_270 ( V_48 ) ;
struct V_93 * V_41 = V_48 -> V_41 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_329 * V_146 = V_332 -> V_146 ;
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_334 * V_1207 =
F_217 ( V_146 -> V_39 ) ;
int V_972 = V_40 -> V_45 . V_45 . V_378 , V_273 ;
bool V_1208 = F_24 ( V_48 ) ;
bool V_1209 = V_41 -> V_39 -> V_94 ;
bool V_1210 = V_48 -> V_94 ;
bool V_1211 , V_1212 , V_337 , V_1213 ;
struct V_257 * V_96 = V_332 -> V_96 ;
if ( V_48 && F_60 ( V_44 ) -> V_110 >= 9 &&
V_146 -> type != V_1214 ) {
V_273 = F_358 (
F_270 ( V_48 ) ,
F_217 ( V_332 ) ) ;
if ( V_273 )
return V_273 ;
}
V_1213 = V_1207 -> V_337 ;
V_337 = F_217 ( V_332 ) -> V_337 ;
if ( ! V_1209 && F_31 ( V_1213 ) )
V_1213 = false ;
if ( ! V_1210 )
F_217 ( V_332 ) -> V_337 = V_337 = false ;
if ( ! V_1213 && ! V_337 )
return 0 ;
if ( V_96 != V_1207 -> V_45 . V_96 )
V_34 -> V_1215 = true ;
V_1211 = V_1213 && ( ! V_337 || V_1208 ) ;
V_1212 = V_337 && ( ! V_1213 || V_1208 ) ;
F_802 ( L_191 , V_972 ,
V_146 -> V_45 . V_378 , V_96 ? V_96 -> V_45 . V_378 : - 1 ) ;
F_802 ( L_192 ,
V_146 -> V_45 . V_378 , V_1213 , V_337 ,
V_1211 , V_1212 , V_1208 ) ;
if ( V_1212 ) {
V_34 -> V_566 = true ;
if ( V_146 -> type != V_1214 )
V_34 -> V_563 = true ;
} else if ( V_1211 ) {
V_34 -> V_559 = true ;
if ( V_146 -> type != V_1214 )
V_34 -> V_563 = true ;
} else if ( F_799 ( V_146 , V_332 ) ) {
V_34 -> V_566 = true ;
V_34 -> V_559 = true ;
}
if ( ( V_34 -> V_566 || V_34 -> V_559 ) &&
F_60 ( V_44 ) -> V_110 < 9 && V_2 -> V_427 . V_1216 )
F_270 ( V_48 ) -> V_552 . V_1217 = true ;
if ( V_337 || V_1213 )
V_34 -> V_557 |= F_216 ( V_146 ) -> V_356 ;
if ( V_146 -> type == V_1218 && F_292 ( V_44 ) &&
F_800 ( F_217 ( V_332 ) ) &&
! F_800 ( V_1207 ) )
V_34 -> V_564 = true ;
return 0 ;
}
static bool F_803 ( const struct V_46 * V_1147 ,
const struct V_46 * V_1148 )
{
return V_1147 == V_1148 || ( V_1147 -> V_1219 & ( 1 << V_1148 -> type ) &&
V_1148 -> V_1219 & ( 1 << V_1147 -> type ) ) ;
}
static bool F_804 ( struct V_49 * V_39 ,
struct V_40 * V_41 ,
struct V_46 * V_47 )
{
struct V_46 * V_1220 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_54 ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != & V_41 -> V_45 )
continue;
V_1220 =
F_30 ( V_53 -> V_56 ) ;
if ( ! F_803 ( V_47 , V_1220 ) )
return false ;
}
return true ;
}
static bool F_805 ( struct V_49 * V_39 ,
struct V_40 * V_41 )
{
struct V_46 * V_47 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_54 ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != & V_41 -> V_45 )
continue;
V_47 = F_30 ( V_53 -> V_56 ) ;
if ( ! F_804 ( V_39 , V_41 , V_47 ) )
return false ;
}
return true ;
}
static int F_806 ( struct V_93 * V_41 ,
struct V_38 * V_48 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_33 * V_34 =
F_270 ( V_48 ) ;
struct V_49 * V_39 = V_48 -> V_39 ;
int V_273 ;
bool V_1208 = F_24 ( V_48 ) ;
if ( V_1208 && ! F_805 ( V_39 , V_40 ) ) {
F_159 ( L_193 ) ;
return - V_533 ;
}
if ( V_1208 && ! V_48 -> V_94 )
V_34 -> V_559 = true ;
if ( V_1208 && V_48 -> V_499 &&
V_2 -> V_427 . V_1221 &&
! F_31 ( V_34 -> V_216 ) ) {
V_273 = V_2 -> V_427 . V_1221 ( V_40 ,
V_34 ) ;
if ( V_273 )
return V_273 ;
}
if ( V_48 -> V_1222 ) {
V_273 = F_807 ( V_41 , V_48 ) ;
if ( V_273 )
return V_273 ;
V_48 -> V_1223 = true ;
}
V_273 = 0 ;
if ( V_2 -> V_427 . V_1224 ) {
V_273 = V_2 -> V_427 . V_1224 ( V_34 ) ;
if ( V_273 ) {
F_159 ( L_194 ) ;
return V_273 ;
}
}
if ( V_2 -> V_427 . V_1225 &&
! F_471 ( V_39 ) -> V_1226 ) {
if ( F_31 ( ! V_2 -> V_427 . V_1224 ) )
return 0 ;
V_273 = V_2 -> V_427 . V_1225 ( V_41 -> V_44 ,
V_40 ,
V_34 ) ;
if ( V_273 ) {
F_159 ( L_195 ) ;
return V_273 ;
}
} else if ( V_2 -> V_427 . V_1225 ) {
if ( F_14 ( V_2 ) && F_808 ( V_2 ) < 9 )
V_34 -> V_552 . V_1227 = V_34 -> V_552 . V_1228 . V_1229 ;
}
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
if ( V_1208 )
V_273 = F_357 ( V_34 ) ;
if ( ! V_273 )
V_273 = F_809 ( V_44 , V_40 ,
V_34 ) ;
}
return V_273 ;
}
static void F_810 ( struct V_43 * V_44 )
{
struct V_710 * V_51 ;
F_811 (dev, connector) {
if ( V_51 -> V_45 . V_39 -> V_41 )
F_812 ( & V_51 -> V_45 ) ;
if ( V_51 -> V_45 . V_47 ) {
V_51 -> V_45 . V_39 -> V_56 =
V_51 -> V_45 . V_47 ;
V_51 -> V_45 . V_39 -> V_41 =
V_51 -> V_45 . V_47 -> V_41 ;
F_813 ( & V_51 -> V_45 ) ;
} else {
V_51 -> V_45 . V_39 -> V_56 = NULL ;
V_51 -> V_45 . V_39 -> V_41 = NULL ;
}
}
}
static void
F_814 ( struct V_710 * V_51 ,
struct V_33 * V_34 )
{
int V_984 = V_34 -> V_722 ;
F_159 ( L_196 ,
V_51 -> V_45 . V_45 . V_378 ,
V_51 -> V_45 . V_8 ) ;
if ( V_51 -> V_45 . V_1230 . V_512 &&
V_51 -> V_45 . V_1230 . V_512 * 3 < V_984 ) {
F_159 ( L_197 ,
V_984 , V_51 -> V_45 . V_1230 . V_512 * 3 ) ;
V_34 -> V_722 = V_51 -> V_45 . V_1230 . V_512 * 3 ;
}
if ( V_51 -> V_45 . V_1230 . V_512 == 0 ) {
int type = V_51 -> V_45 . V_1231 ;
int V_1232 = 24 ;
if ( type == V_1233 ||
type == V_1234 )
V_1232 = 18 ;
if ( V_984 > V_1232 ) {
F_159 ( L_198 ,
V_984 , V_1232 ) ;
V_34 -> V_722 = V_1232 ;
}
}
}
static int
F_815 ( struct V_40 * V_41 ,
struct V_33 * V_34 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_49 * V_39 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_984 , V_54 ;
if ( ( F_17 ( V_44 ) || F_15 ( V_44 ) || F_16 ( V_44 ) ) )
V_984 = 10 * 3 ;
else if ( F_60 ( V_44 ) -> V_110 >= 5 )
V_984 = 12 * 3 ;
else
V_984 = 8 * 3 ;
V_34 -> V_722 = V_984 ;
V_39 = V_34 -> V_45 . V_39 ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != & V_41 -> V_45 )
continue;
F_814 ( F_816 ( V_51 ) ,
V_34 ) ;
}
return V_984 ;
}
static void F_817 ( const struct V_511 * V_422 )
{
F_159 ( L_199
L_200 ,
V_422 -> V_99 ,
V_422 -> V_535 , V_422 -> V_728 ,
V_422 -> V_881 , V_422 -> V_878 ,
V_422 -> V_536 , V_422 -> V_883 ,
V_422 -> V_884 , V_422 -> V_874 , V_422 -> type , V_422 -> V_326 ) ;
}
static void F_818 ( struct V_40 * V_41 ,
struct V_33 * V_34 ,
const char * V_1235 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_329 * V_146 ;
struct V_333 * V_333 ;
struct V_334 * V_39 ;
struct V_257 * V_96 ;
F_159 ( L_201 , V_41 -> V_45 . V_45 . V_378 ,
V_1235 , V_34 , F_77 ( V_41 -> V_101 ) ) ;
F_159 ( L_202 , F_819 ( V_34 -> V_103 ) ) ;
F_159 ( L_203 ,
V_34 -> V_722 , V_34 -> V_897 ) ;
F_159 ( L_204 ,
V_34 -> V_234 ,
V_34 -> V_449 ,
V_34 -> V_568 . V_793 , V_34 -> V_568 . V_794 ,
V_34 -> V_568 . V_795 , V_34 -> V_568 . V_796 ,
V_34 -> V_568 . V_792 ) ;
F_159 ( L_205 ,
V_34 -> V_510 ,
V_34 -> V_1236 ,
V_34 -> V_810 . V_793 , V_34 -> V_810 . V_794 ,
V_34 -> V_810 . V_795 , V_34 -> V_810 . V_796 ,
V_34 -> V_810 . V_792 ) ;
F_159 ( L_206 ,
V_34 -> V_510 ,
V_34 -> V_1236 ,
V_34 -> V_811 . V_793 ,
V_34 -> V_811 . V_794 ,
V_34 -> V_811 . V_795 ,
V_34 -> V_811 . V_796 ,
V_34 -> V_811 . V_792 ) ;
F_159 ( L_207 ,
V_34 -> V_1237 ,
V_34 -> V_1238 ) ;
F_159 ( L_208 ) ;
F_820 ( & V_34 -> V_45 . V_422 ) ;
F_159 ( L_209 ) ;
F_820 ( & V_34 -> V_45 . V_98 ) ;
F_817 ( & V_34 -> V_45 . V_98 ) ;
F_159 ( L_210 , V_34 -> V_35 ) ;
F_159 ( L_211 ,
V_34 -> V_362 , V_34 -> V_361 ) ;
F_159 ( L_212 ,
V_41 -> V_381 ,
V_34 -> V_380 . V_524 ,
V_34 -> V_380 . V_412 ) ;
F_159 ( L_213 ,
V_34 -> V_579 . V_580 ,
V_34 -> V_579 . V_584 ,
V_34 -> V_579 . V_1239 ) ;
F_159 ( L_214 ,
V_34 -> V_435 . V_540 ,
V_34 -> V_435 . V_253 ,
V_34 -> V_435 . V_156 ? L_215 : L_216 ) ;
F_159 ( L_217 , V_34 -> V_543 ) ;
F_159 ( L_218 , V_34 -> V_237 ) ;
if ( F_40 ( V_44 ) ) {
F_159 ( L_219
L_220
L_221 ,
V_34 -> V_1051 ,
V_34 -> V_184 . V_1240 ,
V_34 -> V_184 . V_1241 ,
V_34 -> V_184 . V_1242 ,
V_34 -> V_184 . V_1243 ,
V_34 -> V_184 . V_1244 ,
V_34 -> V_184 . V_1245 ,
V_34 -> V_184 . V_1246 ,
V_34 -> V_184 . V_1247 ,
V_34 -> V_184 . V_1248 ,
V_34 -> V_184 . V_1249 ,
V_34 -> V_184 . V_1250 ) ;
} else if ( F_434 ( V_44 ) || F_435 ( V_44 ) ) {
F_159 ( L_222
L_223 ,
V_34 -> V_1051 ,
V_34 -> V_184 . V_1251 ,
V_34 -> V_184 . V_1252 ,
V_34 -> V_184 . V_1253 ) ;
} else if ( F_22 ( V_44 ) ) {
F_159 ( L_224 ,
V_34 -> V_1051 ,
V_34 -> V_184 . V_1254 ,
V_34 -> V_184 . V_1255 ) ;
} else {
F_159 ( L_225
L_226 ,
V_34 -> V_184 . V_66 ,
V_34 -> V_184 . V_186 ,
V_34 -> V_184 . V_703 ,
V_34 -> V_184 . V_704 ) ;
}
F_159 ( L_227 ) ;
F_821 (plane, &dev->mode_config.plane_list, head) {
V_333 = F_216 ( V_146 ) ;
if ( V_333 -> V_101 != V_41 -> V_101 )
continue;
V_39 = F_217 ( V_146 -> V_39 ) ;
V_96 = V_39 -> V_45 . V_96 ;
if ( ! V_96 ) {
F_159 ( L_228
L_229 ,
V_146 -> type == V_1214 ? L_230 : L_231 ,
V_146 -> V_45 . V_378 , V_333 -> V_101 ,
( V_41 -> V_45 . V_95 == V_146 ) ? 0 : V_333 -> V_146 + 1 ,
F_221 ( V_146 ) , V_39 -> V_412 ) ;
continue;
}
F_159 ( L_232 ,
V_146 -> type == V_1214 ? L_230 : L_231 ,
V_146 -> V_45 . V_378 , V_333 -> V_101 ,
V_41 -> V_45 . V_95 == V_146 ? 0 : V_333 -> V_146 + 1 ,
F_221 ( V_146 ) ) ;
F_159 ( L_233 ,
V_96 -> V_45 . V_378 , V_96 -> V_254 , V_96 -> V_249 , V_96 -> V_250 ) ;
F_159 ( L_234 ,
V_39 -> V_412 ,
V_39 -> V_348 . V_349 >> 16 , V_39 -> V_348 . y1 >> 16 ,
F_254 ( & V_39 -> V_348 ) >> 16 ,
F_255 ( & V_39 -> V_348 ) >> 16 ,
V_39 -> V_352 . V_349 , V_39 -> V_352 . y1 ,
F_254 ( & V_39 -> V_352 ) , F_255 ( & V_39 -> V_352 ) ) ;
}
}
static bool F_822 ( struct V_49 * V_39 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
struct V_50 * V_51 ;
unsigned int V_1256 = 0 ;
F_823 (connector, dev) {
struct V_52 * V_53 ;
struct V_46 * V_47 ;
V_53 = F_824 ( V_39 , V_51 ) ;
if ( ! V_53 )
V_53 = V_51 -> V_39 ;
if ( ! V_53 -> V_56 )
continue;
V_47 = F_30 ( V_53 -> V_56 ) ;
F_31 ( ! V_53 -> V_41 ) ;
switch ( V_47 -> type ) {
unsigned int V_206 ;
case V_598 :
if ( F_31 ( ! F_22 ( V_44 ) ) )
break;
case V_503 :
case V_219 :
case V_504 :
V_206 = 1 << F_346 ( & V_47 -> V_45 ) -> V_188 ;
if ( V_1256 & V_206 )
return false ;
V_1256 |= V_206 ;
default:
break;
}
}
return true ;
}
static void
F_825 ( struct V_33 * V_48 )
{
struct V_38 V_1257 ;
struct V_379 V_380 ;
struct V_1258 V_184 ;
struct V_991 * V_216 ;
T_2 V_1051 ;
bool V_606 ;
V_1257 = V_48 -> V_45 ;
V_380 = V_48 -> V_380 ;
V_216 = V_48 -> V_216 ;
V_184 = V_48 -> V_184 ;
V_1051 = V_48 -> V_1051 ;
V_606 = V_48 -> V_435 . V_606 ;
memset ( V_48 , 0 , sizeof *V_48 ) ;
V_48 -> V_45 = V_1257 ;
V_48 -> V_380 = V_380 ;
V_48 -> V_216 = V_216 ;
V_48 -> V_184 = V_184 ;
V_48 -> V_1051 = V_1051 ;
V_48 -> V_435 . V_606 = V_606 ;
}
static int
F_826 ( struct V_93 * V_41 ,
struct V_33 * V_34 )
{
struct V_49 * V_39 = V_34 -> V_45 . V_39 ;
struct V_46 * V_47 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_1259 , V_273 = - V_533 ;
int V_54 ;
bool V_454 = true ;
F_825 ( V_34 ) ;
V_34 -> V_103 =
(enum V_100 ) F_50 ( V_41 ) -> V_101 ;
if ( ! ( V_34 -> V_45 . V_98 . V_326 &
( V_516 | V_1260 ) ) )
V_34 -> V_45 . V_98 . V_326 |= V_1260 ;
if ( ! ( V_34 -> V_45 . V_98 . V_326 &
( V_518 | V_1261 ) ) )
V_34 -> V_45 . V_98 . V_326 |= V_1261 ;
V_1259 = F_815 ( F_50 ( V_41 ) ,
V_34 ) ;
if ( V_1259 < 0 )
goto V_779;
F_700 ( & V_34 -> V_45 . V_422 ,
& V_34 -> V_362 ,
& V_34 -> V_361 ) ;
V_1262:
V_34 -> V_35 = 0 ;
V_34 -> V_572 = 1 ;
F_827 ( & V_34 -> V_45 . V_98 ,
V_1263 ) ;
F_29 (state, connector, connector_state, i) {
if ( V_53 -> V_41 != V_41 )
continue;
V_47 = F_30 ( V_53 -> V_56 ) ;
if ( ! ( V_47 -> V_1264 ( V_47 , V_34 ) ) ) {
F_159 ( L_235 ) ;
goto V_779;
}
}
if ( ! V_34 -> V_35 )
V_34 -> V_35 = V_34 -> V_45 . V_98 . V_99
* V_34 -> V_572 ;
V_273 = F_518 ( F_50 ( V_41 ) , V_34 ) ;
if ( V_273 < 0 ) {
F_159 ( L_236 ) ;
goto V_779;
}
if ( V_273 == V_724 ) {
if ( F_6 ( ! V_454 , L_237 ) ) {
V_273 = - V_533 ;
goto V_779;
}
F_159 ( L_238 ) ;
V_454 = false ;
goto V_1262;
}
V_34 -> V_897 = V_34 -> V_722 == 6 * 3 ;
F_159 ( L_239 ,
V_1259 , V_34 -> V_722 , V_34 -> V_897 ) ;
V_779:
return V_273 ;
}
static void
F_828 ( struct V_49 * V_39 )
{
struct V_93 * V_41 ;
struct V_38 * V_48 ;
int V_54 ;
F_472 (state, crtc, crtc_state, i) {
F_50 ( V_41 ) -> V_97 = F_270 ( V_41 -> V_39 ) ;
if ( V_41 -> V_39 -> V_94 )
V_41 -> V_1265 = V_41 -> V_39 -> V_98 ;
else
V_41 -> V_1265 . V_99 = 0 ;
if ( F_378 ( V_39 , V_41 -> V_95 ) ) {
struct V_331 * V_332 = V_41 -> V_95 -> V_39 ;
V_41 -> V_95 -> V_96 = V_332 -> V_96 ;
V_41 -> V_280 = V_332 -> V_340 >> 16 ;
V_41 -> V_281 = V_332 -> V_341 >> 16 ;
}
}
}
static bool F_829 ( int V_1266 , int V_1267 )
{
int V_1268 ;
if ( V_1266 == V_1267 )
return true ;
if ( ! V_1266 || ! V_1267 )
return false ;
V_1268 = abs ( V_1266 - V_1267 ) ;
if ( ( ( ( ( V_1268 + V_1266 + V_1267 ) * 100 ) ) / ( V_1266 + V_1267 ) ) < 105 )
return true ;
return false ;
}
static bool
F_830 ( unsigned int V_58 , unsigned int V_63 ,
unsigned int V_59 , unsigned int V_1269 ,
bool V_1270 )
{
if ( V_58 == V_59 && V_63 == V_1269 )
return true ;
if ( V_1270 || ! V_58 || ! V_63 || ! V_59 || ! V_1269 )
return false ;
F_831 ( V_783 > V_90 ) ;
if ( V_63 > V_1269 ) {
while ( V_63 > V_1269 ) {
V_59 <<= 1 ;
V_1269 <<= 1 ;
}
} else if ( V_63 < V_1269 ) {
while ( V_63 < V_1269 ) {
V_58 <<= 1 ;
V_63 <<= 1 ;
}
}
if ( V_63 != V_1269 )
return false ;
return F_829 ( V_58 , V_59 ) ;
}
static bool
F_832 ( const struct V_790 * V_791 ,
struct V_790 * V_807 ,
bool V_1271 )
{
if ( V_791 -> V_792 == V_807 -> V_792 &&
F_830 ( V_791 -> V_793 , V_791 -> V_794 ,
V_807 -> V_793 , V_807 -> V_794 , ! V_1271 ) &&
F_830 ( V_791 -> V_795 , V_791 -> V_796 ,
V_807 -> V_795 , V_807 -> V_796 , ! V_1271 ) ) {
if ( V_1271 )
* V_807 = * V_791 ;
return true ;
}
return false ;
}
static bool
F_833 ( struct V_43 * V_44 ,
struct V_33 * V_1272 ,
struct V_33 * V_34 ,
bool V_1271 )
{
bool V_273 = true ;
#define F_834 ( T_10 , ... ) \
do { \
if (!adjust) \
DRM_ERROR(fmt, ##__VA_ARGS__); \
else \
DRM_DEBUG_KMS(fmt, ##__VA_ARGS__); \
} while (0)
#define F_835 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected 0x%08x, found 0x%08x)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_836 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_837 ( V_8 ) \
if (current_config->name != pipe_config->name) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %p, found %p)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_838 ( V_8 ) \
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
#define F_839 ( V_8 , T_11 ) \
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
#define F_840 ( V_8 , V_605 ) \
if ((current_config->name ^ pipe_config->name) & (mask)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name "(" #mask ") " \
"(expected %i, found %i)\n", \
current_config->name & (mask), \
pipe_config->name & (mask)); \
ret = false; \
}
#define F_841 ( V_8 ) \
if (!intel_fuzzy_clock_check(current_config->name, pipe_config->name)) { \
INTEL_ERR_OR_DBG_KMS("mismatch in " #name " " \
"(expected %i, found %i)\n", \
current_config->name, \
pipe_config->name); \
ret = false; \
}
#define F_842 ( T_12 ) \
((current_config->quirks | pipe_config->quirks) & (quirk))
F_836 ( V_103 ) ;
F_836 ( V_234 ) ;
F_836 ( V_449 ) ;
F_838 ( V_568 ) ;
F_836 ( V_510 ) ;
F_836 ( V_1236 ) ;
if ( F_60 ( V_44 ) -> V_110 < 8 ) {
F_838 ( V_810 ) ;
if ( V_1272 -> V_808 )
F_838 ( V_811 ) ;
} else
F_839 ( V_810 , V_811 ) ;
F_836 ( V_233 ) ;
F_836 ( V_45 . V_98 . V_535 ) ;
F_836 ( V_45 . V_98 . V_878 ) ;
F_836 ( V_45 . V_98 . V_879 ) ;
F_836 ( V_45 . V_98 . V_880 ) ;
F_836 ( V_45 . V_98 . V_728 ) ;
F_836 ( V_45 . V_98 . V_881 ) ;
F_836 ( V_45 . V_98 . V_536 ) ;
F_836 ( V_45 . V_98 . V_874 ) ;
F_836 ( V_45 . V_98 . V_882 ) ;
F_836 ( V_45 . V_98 . V_875 ) ;
F_836 ( V_45 . V_98 . V_883 ) ;
F_836 ( V_45 . V_98 . V_884 ) ;
F_836 ( V_572 ) ;
F_836 ( V_1273 ) ;
if ( ( F_60 ( V_44 ) -> V_110 < 8 && ! F_237 ( V_44 ) ) ||
F_15 ( V_44 ) || F_16 ( V_44 ) )
F_836 ( V_906 ) ;
F_836 ( V_1238 ) ;
F_836 ( V_1237 ) ;
F_840 ( V_45 . V_98 . V_326 ,
V_877 ) ;
if ( ! F_842 ( V_1274 ) ) {
F_840 ( V_45 . V_98 . V_326 ,
V_516 ) ;
F_840 ( V_45 . V_98 . V_326 ,
V_1260 ) ;
F_840 ( V_45 . V_98 . V_326 ,
V_518 ) ;
F_840 ( V_45 . V_98 . V_326 ,
V_1261 ) ;
}
F_835 ( V_579 . V_580 ) ;
if ( F_60 ( V_44 ) -> V_110 < 4 )
F_835 ( V_579 . V_584 ) ;
F_835 ( V_579 . V_1239 ) ;
if ( ! V_1271 ) {
F_836 ( V_362 ) ;
F_836 ( V_361 ) ;
F_836 ( V_435 . V_156 ) ;
if ( V_1272 -> V_435 . V_156 ) {
F_835 ( V_435 . V_540 ) ;
F_835 ( V_435 . V_253 ) ;
}
F_836 ( V_380 . V_412 ) ;
}
if ( F_237 ( V_44 ) )
F_836 ( V_543 ) ;
F_836 ( V_237 ) ;
F_835 ( V_1051 ) ;
F_837 ( V_216 ) ;
F_835 ( V_184 . V_66 ) ;
F_835 ( V_184 . V_186 ) ;
F_835 ( V_184 . V_703 ) ;
F_835 ( V_184 . V_704 ) ;
F_835 ( V_184 . V_1254 ) ;
F_835 ( V_184 . V_1255 ) ;
F_835 ( V_184 . V_1251 ) ;
F_835 ( V_184 . V_1252 ) ;
F_835 ( V_184 . V_1253 ) ;
F_835 ( V_1275 . V_1276 ) ;
F_835 ( V_1275 . div ) ;
if ( F_17 ( V_44 ) || F_60 ( V_44 ) -> V_110 >= 5 )
F_836 ( V_722 ) ;
F_841 ( V_45 . V_98 . V_99 ) ;
F_841 ( V_35 ) ;
#undef F_835
#undef F_836
#undef F_837
#undef F_840
#undef F_841
#undef F_842
#undef F_834
return V_273 ;
}
static void F_843 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
if ( V_34 -> V_234 ) {
int V_720 = F_717 ( F_21 ( V_2 , V_34 ) ,
& V_34 -> V_568 ) ;
int V_1277 = V_34 -> V_45 . V_98 . V_99 ;
F_6 ( ! F_829 ( V_720 , V_1277 ) ,
L_240 ,
V_720 , V_1277 ) ;
}
}
static void F_844 ( struct V_93 * V_41 ,
struct V_38 * V_1278 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_1279 V_1280 , * V_1281 ;
struct V_1282 * V_1283 , * V_1284 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
const enum V_101 V_101 = V_40 -> V_101 ;
int V_146 ;
if ( F_60 ( V_44 ) -> V_110 < 9 || ! V_1278 -> V_94 )
return;
F_845 ( V_2 , & V_1280 ) ;
V_1281 = & V_2 -> V_552 . V_1285 . V_1286 ;
F_846 (dev_priv, pipe, plane) {
V_1283 = & V_1280 . V_146 [ V_101 ] [ V_146 ] ;
V_1284 = & V_1281 -> V_146 [ V_101 ] [ V_146 ] ;
if ( F_847 ( V_1283 , V_1284 ) )
continue;
F_127 ( L_241
L_242 ,
F_77 ( V_101 ) , V_146 + 1 ,
V_1284 -> V_375 , V_1284 -> V_1287 ,
V_1283 -> V_375 , V_1283 -> V_1287 ) ;
}
V_1283 = & V_1280 . V_146 [ V_101 ] [ V_1288 ] ;
V_1284 = & V_1281 -> V_146 [ V_101 ] [ V_1288 ] ;
if ( ! F_847 ( V_1283 , V_1284 ) ) {
F_127 ( L_243
L_242 ,
F_77 ( V_101 ) ,
V_1284 -> V_375 , V_1284 -> V_1287 ,
V_1283 -> V_375 , V_1283 -> V_1287 ) ;
}
}
static void
F_848 ( struct V_43 * V_44 , struct V_93 * V_41 )
{
struct V_50 * V_51 ;
F_823 (connector, dev) {
struct V_604 * V_47 = V_51 -> V_47 ;
struct V_52 * V_39 = V_51 -> V_39 ;
if ( V_39 -> V_41 != V_41 )
continue;
F_498 ( F_816 ( V_51 ) ) ;
F_65 ( V_39 -> V_56 != V_47 ,
L_244 ) ;
}
}
static void
F_849 ( struct V_43 * V_44 )
{
struct V_46 * V_47 ;
struct V_710 * V_51 ;
F_612 (dev, encoder) {
bool V_156 = false ;
enum V_101 V_101 ;
F_159 ( L_245 ,
V_47 -> V_45 . V_45 . V_378 ,
V_47 -> V_45 . V_8 ) ;
F_811 (dev, connector) {
if ( V_51 -> V_45 . V_39 -> V_56 != & V_47 -> V_45 )
continue;
V_156 = true ;
F_65 ( V_51 -> V_45 . V_39 -> V_41 !=
V_47 -> V_45 . V_41 ,
L_246 ) ;
}
F_65 ( ! ! V_47 -> V_45 . V_41 != V_156 ,
L_247
L_248 ,
! ! V_47 -> V_45 . V_41 , V_156 ) ;
if ( ! V_47 -> V_45 . V_41 ) {
bool V_94 ;
V_94 = V_47 -> V_711 ( V_47 , & V_101 ) ;
F_65 ( V_94 ,
L_249 ,
F_77 ( V_101 ) ) ;
}
}
}
static void
F_850 ( struct V_93 * V_41 ,
struct V_38 * V_434 ,
struct V_38 * V_1289 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_46 * V_47 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_33 * V_34 , * V_1290 ;
struct V_49 * V_555 ;
bool V_94 ;
V_555 = V_434 -> V_39 ;
F_851 ( V_434 ) ;
V_34 = F_270 ( V_434 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_45 . V_41 = V_41 ;
V_34 -> V_45 . V_39 = V_555 ;
F_159 ( L_250 , V_41 -> V_45 . V_378 ) ;
V_94 = V_2 -> V_427 . V_1291 ( V_40 , V_34 ) ;
if ( ( V_40 -> V_101 == V_123 && V_2 -> V_142 & V_143 ) ||
( V_40 -> V_101 == V_132 && V_2 -> V_142 & V_144 ) )
V_94 = V_1289 -> V_94 ;
F_65 ( V_1289 -> V_94 != V_94 ,
L_251
L_248 , V_1289 -> V_94 , V_94 ) ;
F_65 ( V_40 -> V_94 != V_1289 -> V_94 ,
L_252
L_248 , V_1289 -> V_94 , V_40 -> V_94 ) ;
F_27 (dev, crtc, encoder) {
enum V_101 V_101 ;
V_94 = V_47 -> V_711 ( V_47 , & V_101 ) ;
F_65 ( V_94 != V_1289 -> V_94 ,
L_253 ,
V_47 -> V_45 . V_45 . V_378 , V_94 , V_1289 -> V_94 ) ;
F_65 ( V_94 && V_40 -> V_101 != V_101 ,
L_254 ,
F_77 ( V_101 ) ) ;
if ( V_94 )
V_47 -> V_1292 ( V_47 , V_34 ) ;
}
if ( ! V_1289 -> V_94 )
return;
F_843 ( V_2 , V_34 ) ;
V_1290 = F_270 ( V_41 -> V_39 ) ;
if ( ! F_833 ( V_44 , V_1290 ,
V_34 , false ) ) {
F_65 ( 1 , L_255 ) ;
F_818 ( V_40 , V_34 ,
L_256 ) ;
F_818 ( V_40 , V_1290 ,
L_257 ) ;
}
}
static void
F_852 ( struct V_1 * V_2 ,
struct V_991 * V_992 ,
struct V_93 * V_41 ,
struct V_38 * V_1278 )
{
struct V_1258 V_184 ;
unsigned V_1293 ;
bool V_94 ;
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
F_159 ( L_258 , V_992 -> V_8 ) ;
V_94 = V_992 -> V_1010 . V_711 ( V_2 , V_992 , & V_184 ) ;
if ( ! ( V_992 -> V_326 & V_1294 ) ) {
F_65 ( ! V_992 -> V_1295 && V_992 -> V_1296 ,
L_259 ) ;
F_65 ( V_992 -> V_1295 && ! V_992 -> V_1296 ,
L_260 ) ;
F_65 ( V_992 -> V_1295 != V_94 ,
L_261 ,
V_992 -> V_1295 , V_94 ) ;
}
if ( ! V_41 ) {
F_65 ( V_992 -> V_1296 & ~ V_992 -> V_97 . V_1293 ,
L_262 ,
V_992 -> V_1296 , V_992 -> V_97 . V_1293 ) ;
return;
}
V_1293 = 1 << F_853 ( V_41 ) ;
if ( V_1278 -> V_94 )
F_65 ( ! ( V_992 -> V_1296 & V_1293 ) ,
L_263 ,
F_77 ( F_853 ( V_41 ) ) , V_992 -> V_1296 ) ;
else
F_65 ( V_992 -> V_1296 & V_1293 ,
L_264 ,
F_77 ( F_853 ( V_41 ) ) , V_992 -> V_1296 ) ;
F_65 ( ! ( V_992 -> V_97 . V_1293 & V_1293 ) ,
L_265 ,
V_1293 , V_992 -> V_97 . V_1293 ) ;
F_65 ( V_992 -> V_1295 && memcmp ( & V_992 -> V_97 . V_1297 ,
& V_184 ,
sizeof( V_184 ) ) ,
L_266 ) ;
}
static void
F_854 ( struct V_43 * V_44 , struct V_93 * V_41 ,
struct V_38 * V_434 ,
struct V_38 * V_1289 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_33 * V_555 = F_270 ( V_434 ) ;
struct V_33 * V_1278 = F_270 ( V_1289 ) ;
if ( V_1278 -> V_216 )
F_852 ( V_2 , V_1278 -> V_216 , V_41 , V_1289 ) ;
if ( V_555 -> V_216 &&
V_555 -> V_216 != V_1278 -> V_216 ) {
unsigned V_1293 = 1 << F_853 ( V_41 ) ;
struct V_991 * V_992 = V_555 -> V_216 ;
F_65 ( V_992 -> V_1296 & V_1293 ,
L_267 ,
F_77 ( F_853 ( V_41 ) ) ) ;
F_65 ( V_992 -> V_97 . V_1293 & V_1293 ,
L_268 ,
F_77 ( F_853 ( V_41 ) ) ) ;
}
}
static void
F_855 ( struct V_93 * V_41 ,
struct V_38 * V_555 ,
struct V_38 * V_1278 )
{
if ( ! F_24 ( V_1278 ) &&
! F_270 ( V_1278 ) -> V_1298 )
return;
F_844 ( V_41 , V_1278 ) ;
F_848 ( V_41 -> V_44 , V_41 ) ;
F_850 ( V_41 , V_555 , V_1278 ) ;
F_854 ( V_41 -> V_44 , V_41 , V_555 , V_1278 ) ;
}
static void
F_856 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_946 ; V_54 ++ )
F_852 ( V_2 , & V_2 -> V_1299 [ V_54 ] , NULL , NULL ) ;
}
static void
F_857 ( struct V_43 * V_44 )
{
F_849 ( V_44 ) ;
F_848 ( V_44 , NULL ) ;
F_856 ( V_44 ) ;
}
static void F_858 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
if ( F_57 ( V_44 ) ) {
const struct V_511 * V_98 = & V_41 -> V_97 -> V_45 . V_98 ;
int V_890 ;
V_890 = V_98 -> V_874 ;
if ( V_98 -> V_326 & V_877 )
V_890 /= 2 ;
V_41 -> V_236 = V_890 - 1 ;
} else if ( F_22 ( V_44 ) &&
F_26 ( V_41 , V_219 ) ) {
V_41 -> V_236 = 2 ;
} else
V_41 -> V_236 = 1 ;
}
static void F_859 ( struct V_49 * V_39 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_1300 * V_216 = NULL ;
struct V_93 * V_41 ;
struct V_38 * V_48 ;
int V_54 ;
if ( ! V_2 -> V_427 . V_1221 )
return;
F_472 (state, crtc, crtc_state, i) {
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_991 * V_1301 =
F_270 ( V_41 -> V_39 ) -> V_216 ;
if ( ! F_24 ( V_48 ) )
continue;
F_270 ( V_48 ) -> V_216 = NULL ;
if ( ! V_1301 )
continue;
if ( ! V_216 )
V_216 = F_860 ( V_39 ) ;
F_861 ( V_216 , V_1301 , V_40 ) ;
}
}
static int F_862 ( struct V_49 * V_39 )
{
struct V_38 * V_48 ;
struct V_40 * V_40 ;
struct V_93 * V_41 ;
struct V_33 * V_1302 = NULL ;
struct V_33 * V_716 = NULL ;
enum V_101 V_1303 = V_574 , V_1304 = V_574 ;
int V_54 ;
F_472 (state, crtc, crtc_state, i) {
V_40 = F_50 ( V_41 ) ;
if ( ! V_48 -> V_94 || ! F_24 ( V_48 ) )
continue;
if ( V_1302 ) {
V_716 = F_270 ( V_48 ) ;
break;
} else {
V_1302 = F_270 ( V_48 ) ;
V_1303 = V_40 -> V_101 ;
}
}
if ( ! V_1302 )
return 0 ;
F_138 (state->dev, intel_crtc) {
struct V_33 * V_34 ;
V_34 = F_507 ( V_39 , V_40 ) ;
if ( F_508 ( V_34 ) )
return F_509 ( V_34 ) ;
V_34 -> V_570 = V_574 ;
if ( ! V_34 -> V_45 . V_94 ||
F_24 ( & V_34 -> V_45 ) )
continue;
if ( V_1304 != V_574 )
return 0 ;
V_1304 = V_40 -> V_101 ;
}
if ( V_1304 != V_574 )
V_1302 -> V_570 = V_1304 ;
else if ( V_716 )
V_716 -> V_570 = V_1303 ;
return 0 ;
}
static int F_863 ( struct V_49 * V_39 )
{
struct V_93 * V_41 ;
struct V_38 * V_48 ;
int V_273 = 0 ;
F_219 (state->dev, crtc) {
V_48 = F_710 ( V_39 , V_41 ) ;
if ( F_508 ( V_48 ) )
return F_509 ( V_48 ) ;
if ( ! V_48 -> V_94 || F_24 ( V_48 ) )
continue;
V_48 -> V_1208 = true ;
V_273 = F_864 ( V_39 , V_41 ) ;
if ( V_273 )
break;
V_273 = F_865 ( V_39 , V_41 ) ;
if ( V_273 )
break;
}
return V_273 ;
}
static int F_866 ( struct V_49 * V_39 )
{
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_1 * V_2 = V_39 -> V_44 -> V_104 ;
struct V_93 * V_41 ;
struct V_38 * V_48 ;
int V_273 = 0 , V_54 ;
if ( ! F_822 ( V_39 ) ) {
F_159 ( L_269 ) ;
return - V_533 ;
}
V_335 -> V_562 = true ;
V_335 -> V_691 = V_2 -> V_691 ;
F_472 (state, crtc, crtc_state, i) {
if ( V_48 -> V_94 )
V_335 -> V_691 |= 1 << V_54 ;
else
V_335 -> V_691 &= ~ ( 1 << V_54 ) ;
}
if ( V_2 -> V_427 . V_1305 ) {
V_273 = V_2 -> V_427 . V_1305 ( V_39 ) ;
if ( ! V_273 && V_335 -> V_690 != V_2 -> V_621 )
V_273 = F_863 ( V_39 ) ;
if ( V_273 < 0 )
return V_273 ;
F_159 ( L_270 ,
V_335 -> V_672 , V_335 -> V_690 ) ;
} else
F_471 ( V_39 ) -> V_672 = V_2 -> V_1306 ;
F_859 ( V_39 ) ;
if ( F_237 ( V_2 ) )
return F_862 ( V_39 ) ;
return 0 ;
}
static void F_867 ( struct V_49 * V_39 )
{
struct V_43 * V_44 = V_39 -> V_44 ;
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_93 * V_41 ;
struct V_38 * V_1041 ;
struct V_329 * V_146 ;
struct V_331 * V_1307 ;
F_868 (crtc, dev) {
V_1041 = F_869 ( V_39 , V_41 ) ? :
V_41 -> V_39 ;
if ( V_1041 -> V_94 )
V_335 -> V_1308 . V_1309 ++ ;
}
F_870 (plane, dev) {
V_1307 = F_378 ( V_39 , V_146 ) ? :
V_146 -> V_39 ;
if ( ! F_217 ( V_1307 ) -> V_337 )
continue;
V_335 -> V_1308 . V_1310 = true ;
if ( V_1307 -> V_346 != V_1307 -> V_342 >> 16 ||
V_1307 -> V_347 != V_1307 -> V_343 >> 16 )
V_335 -> V_1308 . V_1311 = true ;
}
}
static int F_871 ( struct V_43 * V_44 ,
struct V_49 * V_39 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_93 * V_41 ;
struct V_38 * V_48 ;
int V_273 , V_54 ;
bool V_1312 = false ;
V_273 = F_872 ( V_44 , V_39 ) ;
if ( V_273 )
return V_273 ;
F_472 (state, crtc, crtc_state, i) {
struct V_33 * V_34 =
F_270 ( V_48 ) ;
if ( V_48 -> V_422 . V_1313 != V_41 -> V_39 -> V_422 . V_1313 )
V_48 -> V_1208 = true ;
if ( ! V_48 -> V_499 ) {
if ( F_24 ( V_48 ) )
V_1312 = true ;
continue;
}
if ( ! F_24 ( V_48 ) )
continue;
V_273 = F_864 ( V_39 , V_41 ) ;
if ( V_273 )
return V_273 ;
V_273 = F_826 ( V_41 , V_34 ) ;
if ( V_273 )
return V_273 ;
if ( V_725 . V_1314 &&
F_833 ( V_44 ,
F_270 ( V_41 -> V_39 ) ,
V_34 , true ) ) {
V_48 -> V_1208 = false ;
F_270 ( V_48 ) -> V_1298 = true ;
}
if ( F_24 ( V_48 ) ) {
V_1312 = true ;
V_273 = F_865 ( V_39 , V_41 ) ;
if ( V_273 )
return V_273 ;
}
F_818 ( F_50 ( V_41 ) , V_34 ,
F_24 ( V_48 ) ?
L_271 : L_272 ) ;
}
if ( V_1312 ) {
V_273 = F_866 ( V_39 ) ;
if ( V_273 )
return V_273 ;
} else
V_335 -> V_672 = V_2 -> V_621 ;
V_273 = F_873 ( V_44 , V_39 ) ;
if ( V_273 )
return V_273 ;
F_874 ( V_2 , V_39 ) ;
F_867 ( V_39 ) ;
return 0 ;
}
static int F_875 ( struct V_43 * V_44 ,
struct V_49 * V_39 ,
bool V_1315 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_331 * V_332 ;
struct V_38 * V_48 ;
struct V_329 * V_146 ;
struct V_93 * V_41 ;
int V_54 , V_273 ;
if ( V_1315 ) {
F_159 ( L_273 ) ;
return - V_533 ;
}
F_472 (state, crtc, crtc_state, i) {
if ( V_39 -> V_1316 )
continue;
V_273 = F_315 ( V_41 ) ;
if ( V_273 )
return V_273 ;
if ( F_307 ( & F_50 ( V_41 ) -> V_469 ) >= 2 )
F_786 ( V_2 -> V_474 ) ;
}
V_273 = F_876 ( & V_44 -> V_274 ) ;
if ( V_273 )
return V_273 ;
V_273 = F_877 ( V_44 , V_39 ) ;
F_4 ( & V_44 -> V_274 ) ;
if ( ! V_273 && ! V_1315 ) {
F_878 (state, plane, plane_state, i) {
struct V_334 * V_334 =
F_217 ( V_332 ) ;
if ( ! V_334 -> V_1317 )
continue;
V_273 = F_765 ( V_334 -> V_1317 ,
true , NULL , NULL ) ;
if ( V_273 ) {
F_31 ( V_273 == - V_1200 ) ;
F_2 ( & V_44 -> V_274 ) ;
F_879 ( V_44 , V_39 ) ;
F_4 ( & V_44 -> V_274 ) ;
break;
}
}
}
return V_273 ;
}
static void F_880 ( struct V_43 * V_44 ,
struct V_1 * V_2 ,
unsigned V_1293 )
{
unsigned V_1318 [ V_1319 ] ;
enum V_101 V_101 ;
int V_273 ;
if ( ! V_1293 )
return;
F_90 (dev_priv, pipe) {
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
if ( ! ( ( 1 << V_101 ) & V_1293 ) )
continue;
V_273 = F_100 ( V_41 ) ;
if ( F_31 ( V_273 != 0 ) ) {
V_1293 &= ~ ( 1 << V_101 ) ;
continue;
}
V_1318 [ V_101 ] = F_776 ( V_41 ) ;
}
F_90 (dev_priv, pipe) {
struct V_93 * V_41 = V_2 -> V_102 [ V_101 ] ;
long V_1320 ;
if ( ! ( ( 1 << V_101 ) & V_1293 ) )
continue;
V_1320 = F_881 ( V_44 -> V_1321 [ V_101 ] . V_1322 ,
V_1318 [ V_101 ] !=
F_776 ( V_41 ) ,
F_882 ( 50 ) ) ;
F_6 ( ! V_1320 , L_274 , F_77 ( V_101 ) ) ;
F_101 ( V_41 ) ;
}
}
static bool F_883 ( struct V_33 * V_48 )
{
if ( V_48 -> V_1215 )
return true ;
if ( V_48 -> V_559 )
return true ;
if ( V_48 -> V_563 )
return true ;
return false ;
}
static int F_884 ( struct V_43 * V_44 ,
struct V_49 * V_39 ,
bool V_1315 )
{
struct V_687 * V_335 = F_471 ( V_39 ) ;
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_38 * V_434 ;
struct V_93 * V_41 ;
struct V_33 * V_1323 ;
int V_273 = 0 , V_54 ;
bool V_1324 = V_335 -> V_562 ;
unsigned long V_1325 [ V_1319 ] = {} ;
unsigned V_1326 = 0 ;
V_273 = F_875 ( V_44 , V_39 , V_1315 ) ;
if ( V_273 ) {
F_802 ( L_275 , V_273 ) ;
return V_273 ;
}
F_885 ( V_44 , V_39 ) ;
V_2 -> V_552 . V_97 = V_335 -> V_1308 ;
F_886 ( V_39 ) ;
if ( V_335 -> V_562 ) {
memcpy ( V_2 -> V_688 , V_335 -> V_688 ,
sizeof( V_335 -> V_688 ) ) ;
V_2 -> V_691 = V_335 -> V_691 ;
V_2 -> V_1306 = V_335 -> V_672 ;
F_430 ( V_2 , V_1327 ) ;
}
F_472 (state, crtc, old_crtc_state, i) {
struct V_40 * V_40 = F_50 ( V_41 ) ;
if ( F_24 ( V_41 -> V_39 ) ||
F_270 ( V_41 -> V_39 ) -> V_1298 ) {
V_1324 = true ;
V_1325 [ F_50 ( V_41 ) -> V_101 ] =
F_428 ( V_41 ,
F_270 ( V_41 -> V_39 ) ) ;
}
if ( ! F_24 ( V_41 -> V_39 ) )
continue;
F_382 ( F_270 ( V_434 ) ) ;
if ( V_434 -> V_94 ) {
F_385 ( V_41 , V_434 -> V_338 ) ;
V_2 -> V_427 . V_706 ( V_41 ) ;
V_40 -> V_94 = false ;
F_492 ( V_40 ) ;
F_493 ( V_40 ) ;
F_373 ( V_2 ) ;
F_374 ( V_2 ) ;
if ( ! V_41 -> V_39 -> V_94 )
F_380 ( V_41 ) ;
}
}
F_828 ( V_39 ) ;
if ( V_335 -> V_562 ) {
F_887 ( V_39 -> V_44 , V_39 ) ;
if ( V_2 -> V_427 . V_1328 &&
V_335 -> V_690 != V_2 -> V_621 )
V_2 -> V_427 . V_1328 ( V_39 ) ;
F_857 ( V_44 ) ;
}
F_472 (state, crtc, old_crtc_state, i) {
struct V_40 * V_40 = F_50 ( V_41 ) ;
bool V_562 = F_24 ( V_41 -> V_39 ) ;
struct V_33 * V_34 =
F_270 ( V_41 -> V_39 ) ;
bool V_1298 = ! V_562 && V_34 -> V_1298 ;
if ( V_562 && V_41 -> V_39 -> V_94 ) {
F_858 ( F_50 ( V_41 ) ) ;
V_2 -> V_427 . V_1329 ( V_41 ) ;
}
if ( ! V_562 )
F_382 ( F_270 ( V_434 ) ) ;
if ( V_41 -> V_39 -> V_94 &&
F_378 ( V_39 , V_41 -> V_95 ) )
F_888 ( V_40 ) ;
if ( V_41 -> V_39 -> V_94 &&
( V_41 -> V_39 -> V_1223 || V_1298 ) )
F_889 ( V_434 ) ;
if ( V_34 -> V_45 . V_94 && F_883 ( V_34 ) )
V_1326 |= 1 << V_54 ;
}
if ( ! V_39 -> V_1316 )
F_880 ( V_44 , V_2 , V_1326 ) ;
F_472 (state, crtc, old_crtc_state, i) {
V_1323 = F_270 ( V_41 -> V_39 ) ;
if ( V_2 -> V_427 . V_1216 )
V_2 -> V_427 . V_1216 ( V_1323 ) ;
}
F_472 (state, crtc, old_crtc_state, i) {
F_377 ( F_270 ( V_434 ) ) ;
if ( V_1325 [ V_54 ] )
F_431 ( V_2 , V_1325 [ V_54 ] ) ;
F_855 ( V_41 , V_434 , V_41 -> V_39 ) ;
}
if ( V_335 -> V_562 )
F_85 ( V_2 , V_1327 ) ;
F_2 ( & V_44 -> V_274 ) ;
F_879 ( V_44 , V_39 ) ;
F_4 ( & V_44 -> V_274 ) ;
F_712 ( V_39 ) ;
F_890 ( V_2 ) ;
return 0 ;
}
void F_891 ( struct V_93 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_49 * V_39 ;
struct V_38 * V_48 ;
int V_273 ;
V_39 = F_707 ( V_44 ) ;
if ( ! V_39 ) {
F_159 ( L_276 ,
V_41 -> V_45 . V_378 ) ;
return;
}
V_39 -> V_1118 = F_797 ( V_41 ) ;
V_454:
V_48 = F_710 ( V_39 , V_41 ) ;
V_273 = F_495 ( V_48 ) ;
if ( ! V_273 ) {
if ( ! V_48 -> V_94 )
goto V_935;
V_48 -> V_1208 = true ;
V_273 = F_711 ( V_39 ) ;
}
if ( V_273 == - V_277 ) {
F_798 ( V_39 ) ;
F_713 ( V_39 -> V_1118 ) ;
goto V_454;
}
if ( V_273 )
V_935:
F_712 ( V_39 ) ;
}
int
F_892 ( struct V_329 * V_146 ,
const struct V_331 * V_1278 )
{
struct V_43 * V_44 = V_146 -> V_44 ;
struct V_257 * V_96 = V_1278 -> V_96 ;
struct V_333 * V_333 = F_216 ( V_146 ) ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
struct V_270 * V_1330 = F_191 ( V_146 -> V_39 -> V_96 ) ;
int V_273 = 0 ;
if ( ! V_271 && ! V_1330 )
return 0 ;
if ( V_1330 ) {
struct V_38 * V_48 =
F_869 ( V_1278 -> V_39 , V_146 -> V_39 -> V_41 ) ;
if ( F_24 ( V_48 ) )
V_273 = F_893 ( V_1330 , true ) ;
if ( V_273 ) {
F_31 ( V_273 == - V_1200 ) ;
return V_273 ;
}
}
if ( V_271 && V_271 -> V_45 . V_1182 ) {
long V_1320 ;
V_1320 = F_767 ( V_271 -> V_45 . V_1182 -> V_1183 ,
false , true ,
V_1189 ) ;
if ( V_1320 == - V_1331 )
return V_1320 ;
F_6 ( V_1320 < 0 , L_277 , V_1320 ) ;
}
if ( ! V_271 ) {
V_273 = 0 ;
} else if ( V_146 -> type == V_1214 &&
F_60 ( V_44 ) -> V_1332 ) {
int V_1333 = F_141 ( V_44 ) ? 16 * 1024 : 256 ;
V_273 = F_894 ( V_271 , V_1333 ) ;
if ( V_273 )
F_159 ( L_278 ) ;
} else {
V_273 = F_190 ( V_96 , V_1278 -> V_258 ) ;
}
if ( V_273 == 0 ) {
if ( V_271 ) {
struct V_334 * V_332 =
F_217 ( V_1278 ) ;
F_729 ( & V_332 -> V_1317 ,
V_271 -> V_1184 ) ;
}
F_793 ( V_1330 , V_271 , V_333 -> V_356 ) ;
}
return V_273 ;
}
void
F_895 ( struct V_329 * V_146 ,
const struct V_331 * V_555 )
{
struct V_43 * V_44 = V_146 -> V_44 ;
struct V_333 * V_333 = F_216 ( V_146 ) ;
struct V_334 * V_698 ;
struct V_270 * V_1330 = F_191 ( V_555 -> V_96 ) ;
struct V_270 * V_271 = F_191 ( V_146 -> V_39 -> V_96 ) ;
V_698 = F_217 ( V_555 ) ;
if ( ! V_271 && ! V_1330 )
return;
if ( V_1330 && ( V_146 -> type != V_1214 ||
! F_60 ( V_44 ) -> V_1332 ) )
F_199 ( V_555 -> V_96 , V_555 -> V_258 ) ;
if ( ( V_1330 && ( V_1330 -> V_355 & V_333 -> V_356 ) ) ||
( V_271 && ! ( V_271 -> V_355 & V_333 -> V_356 ) ) )
F_793 ( V_1330 , V_271 , V_333 -> V_356 ) ;
F_729 ( & V_698 -> V_1317 , NULL ) ;
}
int
F_896 ( struct V_40 * V_40 , struct V_33 * V_48 )
{
int V_1334 ;
struct V_43 * V_44 ;
struct V_1 * V_2 ;
int V_99 , V_672 ;
if ( ! V_40 || ! V_48 -> V_45 . V_499 )
return V_1335 ;
V_44 = V_40 -> V_45 . V_44 ;
V_2 = V_44 -> V_104 ;
V_99 = V_48 -> V_45 . V_98 . V_99 ;
V_672 = F_471 ( V_48 -> V_45 . V_39 ) -> V_672 ;
if ( F_47 ( ! V_99 || V_672 < V_99 ) )
return V_1335 ;
V_1334 = V_70 ( ( 1 << 16 ) * 3 - 1 , ( 1 << 8 ) * ( ( V_672 << 8 ) / V_99 ) ) ;
return V_1334 ;
}
static int
F_897 ( struct V_329 * V_146 ,
struct V_33 * V_48 ,
struct V_334 * V_39 )
{
struct V_93 * V_41 = V_39 -> V_45 . V_41 ;
struct V_257 * V_96 = V_39 -> V_45 . V_96 ;
int V_1336 = V_1335 ;
int V_1334 = V_1335 ;
bool V_1337 = false ;
if ( F_60 ( V_146 -> V_44 ) -> V_110 >= 9 ) {
if ( V_39 -> V_537 . V_326 == V_538 ) {
V_1336 = 1 ;
V_1334 = F_896 ( F_50 ( V_41 ) , V_48 ) ;
}
V_1337 = true ;
}
return F_898 ( V_146 , V_41 , V_96 , & V_39 -> V_348 ,
& V_39 -> V_352 , & V_39 -> V_1338 ,
V_1336 , V_1334 ,
V_1337 , true ,
& V_39 -> V_337 ) ;
}
static void F_899 ( struct V_93 * V_41 ,
struct V_38 * V_434 )
{
struct V_43 * V_44 = V_41 -> V_44 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_33 * V_698 =
F_270 ( V_434 ) ;
bool V_562 = F_24 ( V_41 -> V_39 ) ;
F_762 ( V_40 ) ;
if ( V_562 )
return;
if ( V_41 -> V_39 -> V_1222 || F_270 ( V_41 -> V_39 ) -> V_1298 ) {
F_405 ( V_41 -> V_39 ) ;
F_396 ( V_41 -> V_39 ) ;
}
if ( F_270 ( V_41 -> V_39 ) -> V_1298 )
F_286 ( V_40 , V_698 ) ;
else if ( F_60 ( V_44 ) -> V_110 >= 9 )
F_249 ( V_40 ) ;
}
static void F_900 ( struct V_93 * V_41 ,
struct V_38 * V_434 )
{
struct V_40 * V_40 = F_50 ( V_41 ) ;
F_763 ( V_40 ) ;
}
void F_901 ( struct V_329 * V_146 )
{
struct V_333 * V_333 = F_216 ( V_146 ) ;
F_902 ( V_146 ) ;
F_218 ( V_333 ) ;
}
static struct V_329 * F_903 ( struct V_43 * V_44 ,
int V_101 )
{
struct V_333 * V_95 = NULL ;
struct V_334 * V_39 = NULL ;
const T_2 * V_1339 ;
unsigned int V_1340 ;
int V_273 ;
V_95 = F_502 ( sizeof( * V_95 ) , V_714 ) ;
if ( ! V_95 )
goto V_779;
V_39 = F_904 ( & V_95 -> V_45 ) ;
if ( ! V_39 )
goto V_779;
V_95 -> V_45 . V_39 = & V_39 -> V_45 ;
V_95 -> V_1341 = false ;
V_95 -> V_1342 = 1 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
V_95 -> V_1341 = true ;
V_39 -> V_412 = - 1 ;
}
V_95 -> V_101 = V_101 ;
V_95 -> V_146 = V_101 ;
V_95 -> V_356 = F_905 ( V_101 ) ;
V_95 -> V_1343 = F_897 ;
if ( F_906 ( V_44 ) && F_60 ( V_44 ) -> V_110 < 4 )
V_95 -> V_146 = ! V_101 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
V_1339 = V_1344 ;
V_1340 = F_180 ( V_1344 ) ;
V_95 -> V_425 = F_253 ;
V_95 -> V_339 = F_263 ;
} else if ( F_14 ( V_44 ) ) {
V_1339 = V_1345 ;
V_1340 = F_180 ( V_1345 ) ;
V_95 -> V_425 = F_236 ;
V_95 -> V_339 = F_235 ;
} else if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
V_1339 = V_1345 ;
V_1340 = F_180 ( V_1345 ) ;
V_95 -> V_425 = F_223 ;
V_95 -> V_339 = F_235 ;
} else {
V_1339 = V_1346 ;
V_1340 = F_180 ( V_1346 ) ;
V_95 -> V_425 = F_223 ;
V_95 -> V_339 = F_235 ;
}
V_273 = F_907 ( V_44 , & V_95 -> V_45 , 0 ,
& V_1347 ,
V_1339 , V_1340 ,
V_1348 , NULL ) ;
if ( V_273 )
goto V_779;
if ( F_60 ( V_44 ) -> V_110 >= 4 )
F_908 ( V_44 , V_95 ) ;
F_909 ( & V_95 -> V_45 , & V_1349 ) ;
return & V_95 -> V_45 ;
V_779:
F_218 ( V_39 ) ;
F_218 ( V_95 ) ;
return NULL ;
}
void F_908 ( struct V_43 * V_44 , struct V_333 * V_146 )
{
if ( ! V_44 -> V_1113 . V_1350 ) {
unsigned long V_326 = F_229 ( V_399 ) |
F_229 ( V_367 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 9 )
V_326 |= F_229 ( V_400 ) | F_229 ( V_403 ) ;
V_44 -> V_1113 . V_1350 =
F_910 ( V_44 , V_326 ) ;
}
if ( V_44 -> V_1113 . V_1350 )
F_911 ( & V_146 -> V_45 . V_45 ,
V_44 -> V_1113 . V_1350 ,
V_146 -> V_45 . V_39 -> V_258 ) ;
}
static int
F_912 ( struct V_329 * V_146 ,
struct V_33 * V_48 ,
struct V_334 * V_39 )
{
struct V_93 * V_41 = V_48 -> V_45 . V_41 ;
struct V_257 * V_96 = V_39 -> V_45 . V_96 ;
struct V_270 * V_271 = F_191 ( V_96 ) ;
enum V_101 V_101 = F_216 ( V_146 ) -> V_101 ;
unsigned V_325 ;
int V_273 ;
V_273 = F_898 ( V_146 , V_41 , V_96 , & V_39 -> V_348 ,
& V_39 -> V_352 , & V_39 -> V_1338 ,
V_1335 ,
V_1335 ,
true , true , & V_39 -> V_337 ) ;
if ( V_273 )
return V_273 ;
if ( ! V_271 )
return 0 ;
if ( ! F_684 ( V_146 -> V_44 , V_39 -> V_45 . V_346 , V_39 -> V_45 . V_347 ) ) {
F_913 ( L_279 ,
V_39 -> V_45 . V_346 , V_39 -> V_45 . V_347 ) ;
return - V_533 ;
}
V_325 = F_678 ( V_39 -> V_45 . V_346 ) * 4 ;
if ( V_271 -> V_45 . V_253 < V_325 * V_39 -> V_45 . V_347 ) {
F_159 ( L_280 ) ;
return - V_713 ;
}
if ( V_96 -> V_265 [ 0 ] != V_242 ) {
F_159 ( L_281 ) ;
return - V_533 ;
}
if ( F_16 ( V_146 -> V_44 ) && V_101 == V_502 &&
V_39 -> V_337 && V_39 -> V_45 . V_344 < 0 ) {
F_159 ( L_282 ) ;
return - V_533 ;
}
return 0 ;
}
static void
F_914 ( struct V_329 * V_146 ,
struct V_93 * V_41 )
{
struct V_40 * V_40 = F_50 ( V_41 ) ;
V_40 -> V_1101 = 0 ;
F_682 ( V_41 , NULL ) ;
}
static void
F_915 ( struct V_329 * V_146 ,
const struct V_33 * V_48 ,
const struct V_334 * V_39 )
{
struct V_93 * V_41 = V_48 -> V_45 . V_41 ;
struct V_40 * V_40 = F_50 ( V_41 ) ;
struct V_43 * V_44 = V_146 -> V_44 ;
struct V_270 * V_271 = F_191 ( V_39 -> V_45 . V_96 ) ;
T_2 V_1190 ;
if ( ! V_271 )
V_1190 = 0 ;
else if ( ! F_60 ( V_44 ) -> V_1332 )
V_1190 = F_220 ( V_271 ) ;
else
V_1190 = V_271 -> V_1351 -> V_1352 ;
V_40 -> V_1101 = V_1190 ;
F_682 ( V_41 , V_39 ) ;
}
static struct V_329 * F_916 ( struct V_43 * V_44 ,
int V_101 )
{
struct V_333 * V_1353 = NULL ;
struct V_334 * V_39 = NULL ;
int V_273 ;
V_1353 = F_502 ( sizeof( * V_1353 ) , V_714 ) ;
if ( ! V_1353 )
goto V_779;
V_39 = F_904 ( & V_1353 -> V_45 ) ;
if ( ! V_39 )
goto V_779;
V_1353 -> V_45 . V_39 = & V_39 -> V_45 ;
V_1353 -> V_1341 = false ;
V_1353 -> V_1342 = 1 ;
V_1353 -> V_101 = V_101 ;
V_1353 -> V_146 = V_101 ;
V_1353 -> V_356 = F_917 ( V_101 ) ;
V_1353 -> V_1343 = F_912 ;
V_1353 -> V_425 = F_915 ;
V_1353 -> V_339 = F_914 ;
V_273 = F_907 ( V_44 , & V_1353 -> V_45 , 0 ,
& V_1347 ,
V_1354 ,
F_180 ( V_1354 ) ,
V_1214 , NULL ) ;
if ( V_273 )
goto V_779;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
if ( ! V_44 -> V_1113 . V_1350 )
V_44 -> V_1113 . V_1350 =
F_910 ( V_44 ,
F_229 ( V_399 ) |
F_229 ( V_367 ) ) ;
if ( V_44 -> V_1113 . V_1350 )
F_911 ( & V_1353 -> V_45 . V_45 ,
V_44 -> V_1113 . V_1350 ,
V_39 -> V_45 . V_258 ) ;
}
if ( F_60 ( V_44 ) -> V_110 >= 9 )
V_39 -> V_412 = - 1 ;
F_909 ( & V_1353 -> V_45 , & V_1349 ) ;
return & V_1353 -> V_45 ;
V_779:
F_218 ( V_39 ) ;
F_218 ( V_1353 ) ;
return NULL ;
}
static void F_676 ( struct V_43 * V_44 , struct V_40 * V_40 ,
struct V_33 * V_48 )
{
int V_54 ;
struct V_1355 * V_1355 ;
struct V_379 * V_380 = & V_48 -> V_380 ;
for ( V_54 = 0 ; V_54 < V_40 -> V_381 ; V_54 ++ ) {
V_1355 = & V_380 -> V_382 [ V_54 ] ;
V_1355 -> V_383 = 0 ;
V_1355 -> V_422 = V_1356 ;
}
V_380 -> V_412 = - 1 ;
}
static void F_918 ( struct V_43 * V_44 , int V_101 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_40 * V_40 ;
struct V_33 * V_48 = NULL ;
struct V_329 * V_95 = NULL ;
struct V_329 * V_1353 = NULL ;
int V_273 ;
V_40 = F_502 ( sizeof( * V_40 ) , V_714 ) ;
if ( V_40 == NULL )
return;
V_48 = F_502 ( sizeof( * V_48 ) , V_714 ) ;
if ( ! V_48 )
goto V_779;
V_40 -> V_97 = V_48 ;
V_40 -> V_45 . V_39 = & V_48 -> V_45 ;
V_48 -> V_45 . V_41 = & V_40 -> V_45 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 ) {
if ( V_101 == V_502 )
V_40 -> V_381 = 1 ;
else
V_40 -> V_381 = V_1357 ;
F_676 ( V_44 , V_40 , V_48 ) ;
}
V_95 = F_903 ( V_44 , V_101 ) ;
if ( ! V_95 )
goto V_779;
V_1353 = F_916 ( V_44 , V_101 ) ;
if ( ! V_1353 )
goto V_779;
V_273 = F_919 ( V_44 , & V_40 -> V_45 , V_95 ,
V_1353 , & V_1358 , NULL ) ;
if ( V_273 )
goto V_779;
V_40 -> V_101 = V_101 ;
V_40 -> V_146 = V_101 ;
if ( F_906 ( V_44 ) && F_60 ( V_44 ) -> V_110 < 4 ) {
F_159 ( L_283 ) ;
V_40 -> V_146 = ! V_101 ;
}
V_40 -> V_1092 = ~ 0 ;
V_40 -> V_1091 = ~ 0 ;
V_40 -> V_1093 = ~ 0 ;
V_40 -> V_552 . V_558 = true ;
F_614 ( V_101 >= F_180 ( V_2 -> V_1146 ) ||
V_2 -> V_1146 [ V_40 -> V_146 ] != NULL ) ;
V_2 -> V_1146 [ V_40 -> V_146 ] = & V_40 -> V_45 ;
V_2 -> V_102 [ V_40 -> V_101 ] = & V_40 -> V_45 ;
F_920 ( & V_40 -> V_45 , & V_1359 ) ;
F_921 ( & V_40 -> V_45 ) ;
F_31 ( F_853 ( & V_40 -> V_45 ) != V_40 -> V_101 ) ;
return;
V_779:
if ( V_95 )
F_902 ( V_95 ) ;
if ( V_1353 )
F_902 ( V_1353 ) ;
F_218 ( V_48 ) ;
F_218 ( V_40 ) ;
}
enum V_101 F_922 ( struct V_710 * V_51 )
{
struct V_604 * V_47 = V_51 -> V_45 . V_47 ;
struct V_43 * V_44 = V_51 -> V_45 . V_44 ;
F_31 ( ! F_923 ( & V_44 -> V_1113 . V_1115 ) ) ;
if ( ! V_47 || F_31 ( ! V_47 -> V_41 ) )
return V_574 ;
return F_50 ( V_47 -> V_41 ) -> V_101 ;
}
int F_924 ( struct V_43 * V_44 , void * V_1044 ,
struct V_1360 * V_1361 )
{
struct V_1362 * V_1363 = V_1044 ;
struct V_93 * V_1364 ;
struct V_40 * V_41 ;
V_1364 = F_925 ( V_44 , V_1363 -> V_1365 ) ;
if ( ! V_1364 ) {
F_127 ( L_284 ) ;
return - V_1366 ;
}
V_41 = F_50 ( V_1364 ) ;
V_1363 -> V_101 = V_41 -> V_101 ;
return 0 ;
}
static int F_926 ( struct V_46 * V_47 )
{
struct V_43 * V_44 = V_47 -> V_45 . V_44 ;
struct V_46 * V_1220 ;
int V_1367 = 0 ;
int V_1368 = 0 ;
F_612 (dev, source_encoder) {
if ( F_803 ( V_47 , V_1220 ) )
V_1367 |= ( 1 << V_1368 ) ;
V_1368 ++ ;
}
return V_1367 ;
}
static bool F_927 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! F_140 ( V_44 ) )
return false ;
if ( ( F_10 ( V_1369 ) & V_1370 ) == 0 )
return false ;
if ( F_23 ( V_44 ) && ( F_10 ( V_619 ) & V_1371 ) )
return false ;
return true ;
}
static bool F_928 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( F_60 ( V_44 ) -> V_110 >= 9 )
return false ;
if ( F_524 ( V_44 ) || F_437 ( V_44 ) )
return false ;
if ( F_16 ( V_44 ) )
return false ;
if ( F_929 ( V_44 ) && F_10 ( V_1372 ) & V_1373 )
return false ;
if ( F_22 ( V_44 ) && F_10 ( F_930 ( V_585 ) ) & V_1374 )
return false ;
if ( ! V_2 -> V_798 . V_1375 )
return false ;
return true ;
}
static void F_931 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_46 * V_47 ;
bool V_1376 = false ;
F_932 ( V_44 ) ;
if ( F_928 ( V_44 ) )
F_933 ( V_44 ) ;
if ( F_40 ( V_44 ) ) {
F_934 ( V_44 , V_585 ) ;
F_934 ( V_44 , V_208 ) ;
F_934 ( V_44 , V_210 ) ;
F_935 ( V_44 ) ;
} else if ( F_22 ( V_44 ) ) {
int V_82 ;
V_82 = F_10 ( F_930 ( V_585 ) ) & V_1377 ;
if ( V_82 || F_434 ( V_44 ) || F_435 ( V_44 ) )
F_934 ( V_44 , V_585 ) ;
V_82 = F_10 ( V_1372 ) ;
if ( V_82 & V_1378 )
F_934 ( V_44 , V_208 ) ;
if ( V_82 & V_1379 )
F_934 ( V_44 , V_210 ) ;
if ( V_82 & V_1380 )
F_934 ( V_44 , V_212 ) ;
if ( ( F_434 ( V_44 ) || F_435 ( V_44 ) ) &&
( V_2 -> V_798 . V_1381 [ V_590 ] . V_1382 ||
V_2 -> V_798 . V_1381 [ V_590 ] . V_1383 ||
V_2 -> V_798 . V_1381 [ V_590 ] . V_1384 ) )
F_934 ( V_44 , V_590 ) ;
} else if ( F_14 ( V_44 ) ) {
int V_82 ;
V_1376 = F_936 ( V_44 , V_212 ) ;
if ( F_927 ( V_44 ) )
F_937 ( V_44 , V_1369 , V_585 ) ;
if ( F_10 ( V_181 ) & V_1385 ) {
V_82 = F_938 ( V_44 , V_1386 , V_208 ) ;
if ( ! V_82 )
F_939 ( V_44 , V_181 , V_208 ) ;
if ( ! V_82 && ( F_10 ( V_174 ) & V_1370 ) )
F_937 ( V_44 , V_174 , V_208 ) ;
}
if ( F_10 ( V_182 ) & V_1385 )
F_939 ( V_44 , V_182 , V_210 ) ;
if ( ! V_1376 && F_10 ( V_183 ) & V_1385 )
F_939 ( V_44 , V_183 , V_212 ) ;
if ( F_10 ( V_176 ) & V_1370 )
F_937 ( V_44 , V_176 , V_210 ) ;
if ( F_10 ( V_178 ) & V_1370 )
F_937 ( V_44 , V_178 , V_212 ) ;
} else if ( F_15 ( V_44 ) || F_16 ( V_44 ) ) {
bool V_1387 , V_1388 ;
V_1387 = F_936 ( V_44 , V_208 ) ;
V_1388 = F_940 ( V_2 , V_208 ) ;
if ( F_10 ( V_1389 ) & V_1370 || V_1388 )
V_1387 &= F_937 ( V_44 , V_1389 , V_208 ) ;
if ( ( F_10 ( V_1390 ) & V_1385 || V_1388 ) && ! V_1387 )
F_939 ( V_44 , V_1390 , V_208 ) ;
V_1387 = F_936 ( V_44 , V_210 ) ;
V_1388 = F_940 ( V_2 , V_210 ) ;
if ( F_10 ( V_1391 ) & V_1370 || V_1388 )
V_1387 &= F_937 ( V_44 , V_1391 , V_210 ) ;
if ( ( F_10 ( V_1392 ) & V_1385 || V_1388 ) && ! V_1387 )
F_939 ( V_44 , V_1392 , V_210 ) ;
if ( F_16 ( V_44 ) ) {
V_1388 = F_940 ( V_2 , V_212 ) ;
if ( F_10 ( V_1393 ) & V_1370 || V_1388 )
F_937 ( V_44 , V_1393 , V_212 ) ;
if ( F_10 ( V_1394 ) & V_1385 || V_1388 )
F_939 ( V_44 , V_1394 , V_212 ) ;
}
F_935 ( V_44 ) ;
} else if ( ! F_57 ( V_44 ) && ! F_18 ( V_44 ) ) {
bool V_82 = false ;
if ( F_10 ( V_1395 ) & V_1385 ) {
F_159 ( L_285 ) ;
V_82 = F_938 ( V_44 , V_1395 , V_208 ) ;
if ( ! V_82 && F_17 ( V_44 ) ) {
F_159 ( L_286 ) ;
F_939 ( V_44 , V_1396 , V_208 ) ;
}
if ( ! V_82 && F_17 ( V_44 ) )
F_937 ( V_44 , V_1397 , V_208 ) ;
}
if ( F_10 ( V_1395 ) & V_1385 ) {
F_159 ( L_287 ) ;
V_82 = F_938 ( V_44 , V_1398 , V_210 ) ;
}
if ( ! V_82 && ( F_10 ( V_1398 ) & V_1385 ) ) {
if ( F_17 ( V_44 ) ) {
F_159 ( L_288 ) ;
F_939 ( V_44 , V_1399 , V_210 ) ;
}
if ( F_17 ( V_44 ) )
F_937 ( V_44 , V_1400 , V_210 ) ;
}
if ( F_17 ( V_44 ) &&
( F_10 ( V_1401 ) & V_1370 ) )
F_937 ( V_44 , V_1401 , V_212 ) ;
} else if ( F_57 ( V_44 ) )
F_941 ( V_44 ) ;
if ( F_942 ( V_44 ) )
F_943 ( V_44 ) ;
F_944 ( V_44 ) ;
F_612 (dev, encoder) {
V_47 -> V_45 . V_1117 = V_47 -> V_1293 ;
V_47 -> V_45 . V_1402 =
F_926 ( V_47 ) ;
}
F_624 ( V_44 ) ;
F_945 ( V_44 ) ;
}
static void F_946 ( struct V_257 * V_96 )
{
struct V_43 * V_44 = V_96 -> V_44 ;
struct V_927 * V_928 = F_183 ( V_96 ) ;
F_947 ( V_96 ) ;
F_2 ( & V_44 -> V_274 ) ;
F_31 ( ! V_928 -> V_271 -> V_1403 -- ) ;
F_211 ( & V_928 -> V_271 -> V_45 ) ;
F_4 ( & V_44 -> V_274 ) ;
F_218 ( V_928 ) ;
}
static int F_948 ( struct V_257 * V_96 ,
struct V_1360 * V_1361 ,
unsigned int * V_1404 )
{
struct V_927 * V_928 = F_183 ( V_96 ) ;
struct V_270 * V_271 = V_928 -> V_271 ;
if ( V_271 -> V_1405 . V_550 ) {
F_913 ( L_289 ) ;
return - V_533 ;
}
return F_949 ( V_1361 , & V_271 -> V_45 , V_1404 ) ;
}
static int F_950 ( struct V_257 * V_96 ,
struct V_1360 * V_1361 ,
unsigned V_326 , unsigned V_1406 ,
struct V_1407 * V_1408 ,
unsigned V_1409 )
{
struct V_43 * V_44 = V_96 -> V_44 ;
struct V_927 * V_928 = F_183 ( V_96 ) ;
struct V_270 * V_271 = V_928 -> V_271 ;
F_2 ( & V_44 -> V_274 ) ;
F_951 ( V_271 , false , V_1410 ) ;
F_4 ( & V_44 -> V_274 ) ;
return 0 ;
}
static
T_1 F_952 ( struct V_43 * V_44 , V_68 V_240 ,
T_2 V_250 )
{
T_1 V_110 = F_60 ( V_44 ) -> V_110 ;
if ( V_110 >= 9 ) {
int V_241 = F_177 ( V_250 , 0 ) ;
return V_70 ( 8192 * V_241 , 32768 ) ;
} else if ( V_110 >= 5 && ! F_15 ( V_44 ) && ! F_16 ( V_44 ) ) {
return 32 * 1024 ;
} else if ( V_110 >= 4 ) {
if ( V_240 == V_243 )
return 16 * 1024 ;
else
return 32 * 1024 ;
} else if ( V_110 >= 3 ) {
if ( V_240 == V_243 )
return 8 * 1024 ;
else
return 16 * 1024 ;
} else {
return 8 * 1024 ;
}
}
static int F_210 ( struct V_43 * V_44 ,
struct V_927 * V_928 ,
struct V_316 * V_317 ,
struct V_270 * V_271 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
unsigned int V_926 ;
int V_273 ;
T_1 V_1411 , V_1412 ;
F_31 ( ! F_192 ( & V_44 -> V_274 ) ) ;
if ( V_317 -> V_326 & V_327 ) {
if ( ! ! ( V_271 -> V_322 == V_324 ) !=
! ! ( V_317 -> V_265 [ 0 ] == V_243 ) ) {
F_913 ( L_290 ) ;
return - V_533 ;
}
} else {
if ( V_271 -> V_322 == V_324 )
V_317 -> V_265 [ 0 ] = V_243 ;
else if ( V_271 -> V_322 == V_1413 ) {
F_913 ( L_291 ) ;
return - V_533 ;
}
}
switch ( V_317 -> V_265 [ 0 ] ) {
case V_244 :
case V_245 :
if ( F_60 ( V_44 ) -> V_110 < 9 ) {
F_913 ( L_292 ,
V_317 -> V_265 [ 0 ] ) ;
return - V_533 ;
}
case V_242 :
case V_243 :
break;
default:
F_913 ( L_293 ,
V_317 -> V_265 [ 0 ] ) ;
return - V_533 ;
}
V_1412 = F_240 ( V_2 ,
V_317 -> V_265 [ 0 ] ,
V_317 -> V_250 ) ;
if ( V_317 -> V_266 [ 0 ] & ( V_1412 - 1 ) ) {
F_913 ( L_294 ,
V_317 -> V_266 [ 0 ] , V_1412 ) ;
return - V_533 ;
}
V_1411 = F_952 ( V_44 , V_317 -> V_265 [ 0 ] ,
V_317 -> V_250 ) ;
if ( V_317 -> V_266 [ 0 ] > V_1411 ) {
F_913 ( L_295 ,
V_317 -> V_265 [ 0 ] != V_242 ?
L_296 : L_297 ,
V_317 -> V_266 [ 0 ] , V_1411 ) ;
return - V_533 ;
}
if ( V_317 -> V_265 [ 0 ] == V_243 &&
V_317 -> V_266 [ 0 ] != V_271 -> V_325 ) {
F_913 ( L_298 ,
V_317 -> V_266 [ 0 ] , V_271 -> V_325 ) ;
return - V_533 ;
}
switch ( V_317 -> V_250 ) {
case V_292 :
case V_296 :
case V_298 :
case V_310 :
break;
case V_294 :
if ( F_60 ( V_44 ) -> V_110 > 3 ) {
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
break;
case V_309 :
if ( ! F_15 ( V_44 ) && ! F_16 ( V_44 ) &&
F_60 ( V_44 ) -> V_110 < 9 ) {
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
break;
case V_300 :
case V_302 :
case V_304 :
if ( F_60 ( V_44 ) -> V_110 < 4 ) {
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
break;
case V_1414 :
if ( ! F_15 ( V_44 ) && ! F_16 ( V_44 ) ) {
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
break;
case V_387 :
case V_392 :
case V_390 :
case V_394 :
if ( F_60 ( V_44 ) -> V_110 < 5 ) {
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
break;
default:
F_913 ( L_299 ,
F_953 ( V_317 -> V_250 ) ) ;
return - V_533 ;
}
if ( V_317 -> V_269 [ 0 ] != 0 )
return - V_533 ;
V_926 = F_176 ( V_44 , V_317 -> V_249 ,
V_317 -> V_250 ,
V_317 -> V_265 [ 0 ] ) ;
if ( V_271 -> V_45 . V_253 < V_926 * V_317 -> V_266 [ 0 ] )
return - V_533 ;
F_954 ( & V_928 -> V_45 , V_317 ) ;
V_928 -> V_271 = V_271 ;
F_184 ( V_2 , & V_928 -> V_45 ) ;
V_273 = F_955 ( V_44 , & V_928 -> V_45 , & V_1415 ) ;
if ( V_273 ) {
F_127 ( L_300 , V_273 ) ;
return V_273 ;
}
V_928 -> V_271 -> V_1403 ++ ;
return 0 ;
}
static struct V_257 *
F_956 ( struct V_43 * V_44 ,
struct V_1360 * V_1416 ,
const struct V_316 * V_1417 )
{
struct V_257 * V_96 ;
struct V_270 * V_271 ;
struct V_316 V_317 = * V_1417 ;
V_271 = F_957 ( F_958 ( V_1416 , V_317 . V_1418 [ 0 ] ) ) ;
if ( & V_271 -> V_45 == NULL )
return F_686 ( - V_1366 ) ;
V_96 = F_687 ( V_44 , & V_317 , V_271 ) ;
if ( F_508 ( V_96 ) )
F_695 ( & V_271 -> V_45 ) ;
return V_96 ;
}
static inline void F_959 ( struct V_43 * V_44 )
{
}
void F_960 ( struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) -> V_110 >= 9 ) {
V_2 -> V_427 . V_1291 = F_674 ;
V_2 -> V_427 . V_1419 =
F_635 ;
V_2 -> V_427 . V_1221 =
F_658 ;
V_2 -> V_427 . V_1329 = F_400 ;
V_2 -> V_427 . V_706 = F_413 ;
} else if ( F_22 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_674 ;
V_2 -> V_427 . V_1419 =
F_638 ;
V_2 -> V_427 . V_1221 =
F_658 ;
V_2 -> V_427 . V_1329 = F_400 ;
V_2 -> V_427 . V_706 = F_413 ;
} else if ( F_14 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_639 ;
V_2 -> V_427 . V_1419 =
F_638 ;
V_2 -> V_427 . V_1221 =
F_628 ;
V_2 -> V_427 . V_1329 = F_388 ;
V_2 -> V_427 . V_706 = F_411 ;
} else if ( F_16 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_603 ;
V_2 -> V_427 . V_1329 = F_478 ;
V_2 -> V_427 . V_706 = F_489 ;
} else if ( F_15 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_604 ;
V_2 -> V_427 . V_1329 = F_478 ;
V_2 -> V_427 . V_706 = F_489 ;
} else if ( F_17 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_600 ;
V_2 -> V_427 . V_1329 = F_487 ;
V_2 -> V_427 . V_706 = F_489 ;
} else if ( F_18 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_601 ;
V_2 -> V_427 . V_1329 = F_487 ;
V_2 -> V_427 . V_706 = F_489 ;
} else if ( ! F_57 ( V_2 ) ) {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_602 ;
V_2 -> V_427 . V_1329 = F_487 ;
V_2 -> V_427 . V_706 = F_489 ;
} else {
V_2 -> V_427 . V_1291 = F_609 ;
V_2 -> V_427 . V_1419 =
F_607 ;
V_2 -> V_427 . V_1221 = F_599 ;
V_2 -> V_427 . V_1329 = F_487 ;
V_2 -> V_427 . V_706 = F_489 ;
}
if ( F_434 ( V_2 ) || F_435 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_520 ;
else if ( F_40 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_521 ;
else if ( F_238 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_522 ;
else if ( F_237 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_523 ;
else if ( F_15 ( V_2 ) || F_16 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_525 ;
else if ( F_23 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_526 ;
else if ( F_589 ( V_2 ) || F_187 ( V_2 ) ||
F_301 ( V_2 ) || F_292 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_527 ;
else if ( F_539 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_541 ;
else if ( F_188 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_542 ;
else if ( F_18 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_530 ;
else if ( F_540 ( V_2 ) || F_17 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_543 ;
else if ( F_517 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_528 ;
else if ( F_590 ( V_2 ) || F_79 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_529 ;
else if ( F_961 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_532 ;
else if ( F_80 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_533 ;
else if ( F_962 ( V_2 ) )
V_2 -> V_427 . V_623 =
F_534 ;
else {
F_6 ( ! F_141 ( V_2 ) , L_301 ) ;
V_2 -> V_427 . V_623 =
F_537 ;
}
if ( F_23 ( V_2 ) ) {
V_2 -> V_427 . V_506 = F_293 ;
} else if ( F_301 ( V_2 ) ) {
V_2 -> V_427 . V_506 = F_299 ;
} else if ( F_292 ( V_2 ) ) {
V_2 -> V_427 . V_506 = F_302 ;
} else if ( F_237 ( V_2 ) || F_238 ( V_2 ) ) {
V_2 -> V_427 . V_506 = V_1420 ;
if ( F_238 ( V_2 ) ) {
V_2 -> V_427 . V_1328 =
F_657 ;
V_2 -> V_427 . V_1305 =
F_656 ;
}
} else if ( F_15 ( V_2 ) || F_16 ( V_2 ) ) {
V_2 -> V_427 . V_1328 =
F_477 ;
V_2 -> V_427 . V_1305 =
F_473 ;
} else if ( F_40 ( V_2 ) ) {
V_2 -> V_427 . V_1328 =
F_653 ;
V_2 -> V_427 . V_1305 =
F_474 ;
}
switch ( F_60 ( V_2 ) -> V_110 ) {
case 2 :
V_2 -> V_427 . V_1204 = F_744 ;
break;
case 3 :
V_2 -> V_427 . V_1204 = F_748 ;
break;
case 4 :
case 5 :
V_2 -> V_427 . V_1204 = F_749 ;
break;
case 6 :
V_2 -> V_427 . V_1204 = F_750 ;
break;
case 7 :
case 8 :
V_2 -> V_427 . V_1204 = F_751 ;
break;
case 9 :
default:
V_2 -> V_427 . V_1204 = F_773 ;
}
}
static void F_963 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_142 |= V_143 ;
F_964 ( L_302 ) ;
}
static void F_965 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_142 |= V_144 ;
F_964 ( L_303 ) ;
}
static void F_966 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_142 |= V_800 ;
F_964 ( L_304 ) ;
}
static void F_967 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_142 |= V_1421 ;
F_964 ( L_305 ) ;
}
static void F_968 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
V_2 -> V_142 |= V_1422 ;
F_964 ( L_306 ) ;
}
static int F_969 ( const struct V_1423 * V_378 )
{
F_964 ( L_307 , V_378 -> V_1424 ) ;
return 1 ;
}
static void F_970 ( struct V_43 * V_44 )
{
struct V_1425 * V_1426 = V_44 -> V_741 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < F_180 ( V_1427 ) ; V_54 ++ ) {
struct V_1428 * V_1429 = & V_1427 [ V_54 ] ;
if ( V_1426 -> V_1430 == V_1429 -> V_1430 &&
( V_1426 -> V_1431 == V_1429 -> V_1431 ||
V_1429 -> V_1431 == V_1432 ) &&
( V_1426 -> V_1433 == V_1429 -> V_1433 ||
V_1429 -> V_1433 == V_1432 ) )
V_1429 -> V_1434 ( V_44 ) ;
}
for ( V_54 = 0 ; V_54 < F_180 ( V_1435 ) ; V_54 ++ ) {
if ( F_971 ( * V_1435 [ V_54 ] . V_1436 ) != 0 )
V_1435 [ V_54 ] . V_1434 ( V_44 ) ;
}
}
static void F_972 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_13 V_1437 ;
T_5 V_1438 = F_973 ( V_44 ) ;
F_974 ( V_44 -> V_741 , V_1439 ) ;
F_975 ( V_1440 , V_1441 ) ;
V_1437 = F_976 ( V_1442 ) ;
F_975 ( V_1437 | 1 << 5 , V_1442 ) ;
F_977 ( V_44 -> V_741 , V_1439 ) ;
F_126 ( 300 ) ;
F_124 ( V_1438 , V_1443 ) ;
F_125 ( V_1438 ) ;
}
void F_278 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
F_438 ( V_44 ) ;
V_2 -> V_1306 = V_2 -> V_621 ;
F_978 ( V_44 ) ;
F_979 ( V_44 ) ;
}
static void F_980 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_49 * V_39 ;
struct V_93 * V_41 ;
struct V_38 * V_1041 ;
struct V_1109 V_1110 ;
int V_273 ;
int V_54 ;
if ( ! V_2 -> V_427 . V_1216 )
return;
F_981 ( & V_1110 , 0 ) ;
V_454:
V_273 = F_982 ( V_44 , & V_1110 ) ;
if ( V_273 == - V_277 ) {
F_713 ( & V_1110 ) ;
goto V_454;
} else if ( F_31 ( V_273 ) ) {
goto V_779;
}
V_39 = F_983 ( V_44 , & V_1110 ) ;
if ( F_31 ( F_508 ( V_39 ) ) )
goto V_779;
F_471 ( V_39 ) -> V_1226 = true ;
V_273 = F_871 ( V_44 , V_39 ) ;
if ( V_273 ) {
F_6 ( true , L_308 ) ;
goto V_779;
}
F_123 ( V_44 ) -> V_552 . V_97 = F_471 ( V_39 ) -> V_1308 ;
F_472 (state, crtc, cstate, i) {
struct V_33 * V_1444 = F_270 ( V_1041 ) ;
V_1444 -> V_552 . V_1217 = true ;
V_2 -> V_427 . V_1216 ( V_1444 ) ;
}
F_712 ( V_39 ) ;
V_779:
F_984 ( & V_1110 ) ;
F_985 ( & V_1110 ) ;
}
void F_986 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_314 * V_315 = & V_2 -> V_315 ;
int V_151 , V_273 ;
enum V_101 V_101 ;
struct V_40 * V_41 ;
F_987 ( V_44 ) ;
V_44 -> V_1113 . V_1445 = 0 ;
V_44 -> V_1113 . V_1446 = 0 ;
V_44 -> V_1113 . V_1447 = 24 ;
V_44 -> V_1113 . V_1448 = 1 ;
V_44 -> V_1113 . V_1449 = true ;
V_44 -> V_1113 . V_1010 = & V_1450 ;
F_970 ( V_44 ) ;
F_988 ( V_44 ) ;
if ( F_60 ( V_44 ) -> V_717 == 0 )
return;
if ( F_119 ( V_44 ) || F_105 ( V_44 ) ) {
bool V_1451 = ! ! ( F_10 ( V_948 ) &
V_954 ) ;
if ( V_2 -> V_798 . V_799 != V_1451 ) {
F_159 ( L_309 ,
V_1451 ? L_67 : L_68 ,
V_2 -> V_798 . V_799 ? L_67 : L_68 ) ;
V_2 -> V_798 . V_799 = V_1451 ;
}
}
if ( F_57 ( V_44 ) ) {
V_44 -> V_1113 . V_1452 = 2048 ;
V_44 -> V_1113 . V_1453 = 2048 ;
} else if ( F_989 ( V_44 ) ) {
V_44 -> V_1113 . V_1452 = 4096 ;
V_44 -> V_1113 . V_1453 = 4096 ;
} else {
V_44 -> V_1113 . V_1452 = 8192 ;
V_44 -> V_1113 . V_1453 = 8192 ;
}
if ( F_79 ( V_44 ) || F_80 ( V_44 ) ) {
V_44 -> V_1113 . V_1454 = F_79 ( V_44 ) ? 64 : 512 ;
V_44 -> V_1113 . V_1455 = 1023 ;
} else if ( F_57 ( V_44 ) ) {
V_44 -> V_1113 . V_1454 = V_1456 ;
V_44 -> V_1113 . V_1455 = V_1457 ;
} else {
V_44 -> V_1113 . V_1454 = V_1458 ;
V_44 -> V_1113 . V_1455 = V_1459 ;
}
V_44 -> V_1113 . V_1460 = V_315 -> V_1461 ;
F_159 ( L_310 ,
F_60 ( V_44 ) -> V_717 ,
F_60 ( V_44 ) -> V_717 > 1 ? L_311 : L_312 ) ;
F_90 (dev_priv, pipe) {
F_918 ( V_44 , V_101 ) ;
F_92 (dev_priv, pipe, sprite) {
V_273 = F_990 ( V_44 , V_101 , V_151 ) ;
if ( V_273 )
F_159 ( L_313 ,
F_77 ( V_101 ) , F_95 ( V_101 , V_151 ) , V_273 ) ;
}
}
F_20 ( V_2 ) ;
F_13 ( V_2 ) ;
F_438 ( V_44 ) ;
F_991 ( V_44 ) ;
F_972 ( V_44 ) ;
F_931 ( V_44 ) ;
F_273 ( V_44 ) ;
F_992 ( V_44 ) ;
F_283 ( V_44 ) ;
F_138 (dev, crtc) {
struct V_312 V_313 = {} ;
if ( ! V_41 -> V_94 )
continue;
V_2 -> V_427 . V_1419 ( V_41 ,
& V_313 ) ;
F_215 ( V_41 , & V_313 ) ;
}
F_980 ( V_44 ) ;
}
static void F_993 ( struct V_43 * V_44 )
{
struct V_710 * V_51 ;
struct V_50 * V_1462 = NULL ;
struct V_1107 V_1463 ;
struct V_1109 * V_1110 = V_44 -> V_1113 . V_1118 ;
F_811 (dev, connector) {
if ( V_51 -> V_47 -> type == V_600 ) {
V_1462 = & V_51 -> V_45 ;
break;
}
}
if ( ! V_1462 )
return;
if ( F_703 ( V_1462 , NULL , & V_1463 , V_1110 ) )
F_714 ( V_1462 , & V_1463 , V_1110 ) ;
}
static bool
F_994 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
T_1 V_11 ;
if ( F_60 ( V_44 ) -> V_717 == 1 )
return true ;
V_11 = F_10 ( F_87 ( ! V_41 -> V_146 ) ) ;
if ( ( V_11 & V_147 ) &&
( ! ! ( V_11 & V_149 ) == V_41 -> V_101 ) )
return false ;
return true ;
}
static bool F_995 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_46 * V_47 ;
F_27 (dev, &crtc->base, encoder)
return true ;
return false ;
}
static bool F_996 ( struct V_46 * V_47 )
{
struct V_43 * V_44 = V_47 -> V_45 . V_44 ;
struct V_710 * V_51 ;
F_997 (dev, &encoder->base, connector)
return true ;
return false ;
}
static void F_998 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = V_41 -> V_45 . V_44 ;
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_100 V_103 = V_41 -> V_97 -> V_103 ;
if ( ! F_401 ( V_103 ) ) {
T_5 V_9 = F_61 ( V_103 ) ;
F_124 ( V_9 ,
F_10 ( V_9 ) & ~ V_1464 ) ;
}
F_999 ( & V_41 -> V_45 ) ;
if ( V_41 -> V_94 ) {
struct V_333 * V_146 ;
F_397 ( & V_41 -> V_45 ) ;
F_1000 (dev, crtc, plane) {
if ( V_146 -> V_45 . type == V_1348 )
continue;
V_146 -> V_339 ( & V_146 -> V_45 , & V_41 -> V_45 ) ;
}
}
if ( F_60 ( V_44 ) -> V_110 < 4 && ! F_994 ( V_41 ) ) {
bool V_146 ;
F_159 ( L_314 ,
V_41 -> V_45 . V_45 . V_378 ) ;
V_146 = V_41 -> V_146 ;
F_217 ( V_41 -> V_45 . V_95 -> V_39 ) -> V_337 = true ;
V_41 -> V_146 = ! V_146 ;
F_490 ( & V_41 -> V_45 ) ;
V_41 -> V_146 = V_146 ;
}
if ( V_2 -> V_142 & V_143 &&
V_41 -> V_101 == V_123 && ! V_41 -> V_94 ) {
F_993 ( V_44 ) ;
}
if ( V_41 -> V_94 && ! F_995 ( V_41 ) )
F_490 ( & V_41 -> V_45 ) ;
if ( V_41 -> V_94 || F_162 ( V_44 ) ) {
V_41 -> V_1465 = true ;
V_41 -> V_1466 = true ;
}
}
static void F_1001 ( struct V_46 * V_47 )
{
struct V_710 * V_51 ;
struct V_43 * V_44 = V_47 -> V_45 . V_44 ;
bool V_1467 = V_47 -> V_45 . V_41 &&
F_50 ( V_47 -> V_45 . V_41 ) -> V_94 ;
if ( F_996 ( V_47 ) && ! V_1467 ) {
F_159 ( L_315 ,
V_47 -> V_45 . V_45 . V_378 ,
V_47 -> V_45 . V_8 ) ;
if ( V_47 -> V_45 . V_41 ) {
F_159 ( L_316 ,
V_47 -> V_45 . V_45 . V_378 ,
V_47 -> V_45 . V_8 ) ;
V_47 -> V_576 ( V_47 ) ;
if ( V_47 -> V_577 )
V_47 -> V_577 ( V_47 ) ;
}
V_47 -> V_45 . V_41 = NULL ;
F_811 (dev, connector) {
if ( V_51 -> V_47 != V_47 )
continue;
V_51 -> V_45 . V_1468 = V_1469 ;
V_51 -> V_45 . V_47 = NULL ;
}
}
}
void F_1002 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
T_5 V_1438 = F_973 ( V_44 ) ;
if ( ! ( F_10 ( V_1438 ) & V_1443 ) ) {
F_159 ( L_317 ) ;
F_972 ( V_44 ) ;
}
}
void F_1003 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
if ( ! F_84 ( V_2 , V_1470 ) )
return;
F_1002 ( V_44 ) ;
F_85 ( V_2 , V_1470 ) ;
}
static bool F_1004 ( struct V_333 * V_146 )
{
struct V_1 * V_2 = F_123 ( V_146 -> V_45 . V_44 ) ;
return F_10 ( F_87 ( V_146 -> V_146 ) ) & V_147 ;
}
static void F_1005 ( struct V_40 * V_41 )
{
struct V_329 * V_95 = V_41 -> V_45 . V_95 ;
struct V_334 * V_332 =
F_217 ( V_95 -> V_39 ) ;
V_332 -> V_337 = V_41 -> V_94 &&
F_1004 ( F_216 ( V_95 ) ) ;
if ( V_332 -> V_337 )
V_41 -> V_45 . V_39 -> V_338 |= 1 << F_221 ( V_95 ) ;
}
static void F_1006 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
struct V_710 * V_51 ;
int V_54 ;
V_2 -> V_691 = 0 ;
F_138 (dev, crtc) {
struct V_33 * V_48 = V_41 -> V_97 ;
int V_689 = 0 ;
F_851 ( & V_48 -> V_45 ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_45 . V_41 = & V_41 -> V_45 ;
V_48 -> V_45 . V_94 = V_48 -> V_45 . V_499 =
V_2 -> V_427 . V_1291 ( V_41 , V_48 ) ;
V_41 -> V_45 . V_156 = V_48 -> V_45 . V_499 ;
V_41 -> V_94 = V_48 -> V_45 . V_94 ;
if ( V_48 -> V_45 . V_94 ) {
V_2 -> V_691 |= 1 << V_41 -> V_101 ;
if ( F_238 ( V_2 ) ) {
V_689 = F_514 ( V_48 ) ;
if ( V_48 -> V_543 )
V_689 = F_185 ( V_689 * 100 , 95 ) ;
} else if ( F_15 ( V_2 ) ||
F_16 ( V_2 ) ||
F_40 ( V_2 ) )
V_689 = V_48 -> V_45 . V_98 . V_99 ;
else
F_31 ( V_2 -> V_427 . V_1305 ) ;
}
V_2 -> V_688 [ V_41 -> V_101 ] = V_689 ;
F_1005 ( V_41 ) ;
F_159 ( L_318 ,
V_41 -> V_45 . V_45 . V_378 ,
V_41 -> V_94 ? L_215 : L_216 ) ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_946 ; V_54 ++ ) {
struct V_991 * V_992 = & V_2 -> V_1299 [ V_54 ] ;
V_992 -> V_1295 = V_992 -> V_1010 . V_711 ( V_2 , V_992 ,
& V_992 -> V_97 . V_1297 ) ;
V_992 -> V_97 . V_1293 = 0 ;
F_138 (dev, crtc) {
if ( V_41 -> V_94 && V_41 -> V_97 -> V_216 == V_992 )
V_992 -> V_97 . V_1293 |= 1 << V_41 -> V_101 ;
}
V_992 -> V_1296 = V_992 -> V_97 . V_1293 ;
F_159 ( L_319 ,
V_992 -> V_8 , V_992 -> V_97 . V_1293 , V_992 -> V_1295 ) ;
}
F_612 (dev, encoder) {
V_101 = 0 ;
if ( V_47 -> V_711 ( V_47 , & V_101 ) ) {
V_41 = F_50 ( V_2 -> V_102 [ V_101 ] ) ;
V_47 -> V_45 . V_41 = & V_41 -> V_45 ;
V_47 -> V_1292 ( V_47 , V_41 -> V_97 ) ;
} else {
V_47 -> V_45 . V_41 = NULL ;
}
F_159 ( L_320 ,
V_47 -> V_45 . V_45 . V_378 ,
V_47 -> V_45 . V_8 ,
V_47 -> V_45 . V_41 ? L_215 : L_216 ,
F_77 ( V_101 ) ) ;
}
F_811 (dev, connector) {
if ( V_51 -> V_711 ( V_51 ) ) {
V_51 -> V_45 . V_1468 = V_1471 ;
V_47 = V_51 -> V_47 ;
V_51 -> V_45 . V_47 = & V_47 -> V_45 ;
if ( V_47 -> V_45 . V_41 &&
V_47 -> V_45 . V_41 -> V_39 -> V_94 ) {
V_47 -> V_45 . V_41 -> V_39 -> V_707 |=
1 << F_1007 ( & V_51 -> V_45 ) ;
V_47 -> V_45 . V_41 -> V_39 -> V_708 |=
1 << F_1008 ( & V_47 -> V_45 ) ;
}
} else {
V_51 -> V_45 . V_1468 = V_1469 ;
V_51 -> V_45 . V_47 = NULL ;
}
F_159 ( L_321 ,
V_51 -> V_45 . V_45 . V_378 ,
V_51 -> V_45 . V_8 ,
V_51 -> V_45 . V_47 ? L_215 : L_216 ) ;
}
F_138 (dev, crtc) {
V_41 -> V_45 . V_1265 = V_41 -> V_97 -> V_45 . V_98 ;
memset ( & V_41 -> V_45 . V_422 , 0 , sizeof( V_41 -> V_45 . V_422 ) ) ;
if ( V_41 -> V_45 . V_39 -> V_94 ) {
F_594 ( & V_41 -> V_45 . V_422 , V_41 -> V_97 ) ;
F_594 ( & V_41 -> V_45 . V_39 -> V_98 , V_41 -> V_97 ) ;
F_31 ( F_491 ( V_41 -> V_45 . V_39 , & V_41 -> V_45 . V_422 ) ) ;
V_41 -> V_45 . V_39 -> V_422 . V_1313 = V_1472 ;
F_1009 ( & V_41 -> V_45 , & V_41 -> V_45 . V_1265 ) ;
F_858 ( V_41 ) ;
}
F_843 ( V_2 , V_41 -> V_97 ) ;
}
}
static void
F_992 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
enum V_101 V_101 ;
struct V_40 * V_41 ;
struct V_46 * V_47 ;
int V_54 ;
F_1006 ( V_44 ) ;
F_612 (dev, encoder) {
F_1001 ( V_47 ) ;
}
F_90 (dev_priv, pipe) {
V_41 = F_50 ( V_2 -> V_102 [ V_101 ] ) ;
F_998 ( V_41 ) ;
F_818 ( V_41 , V_41 -> V_97 ,
L_322 ) ;
}
F_810 ( V_44 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_946 ; V_54 ++ ) {
struct V_991 * V_992 = & V_2 -> V_1299 [ V_54 ] ;
if ( ! V_992 -> V_1295 || V_992 -> V_1296 )
continue;
F_159 ( L_323 , V_992 -> V_8 ) ;
V_992 -> V_1010 . V_576 ( V_2 , V_992 ) ;
V_992 -> V_1295 = false ;
}
if ( F_15 ( V_44 ) || F_16 ( V_44 ) )
F_1010 ( V_44 ) ;
else if ( F_1011 ( V_44 ) )
F_1012 ( V_44 ) ;
else if ( F_14 ( V_44 ) )
F_1013 ( V_44 ) ;
F_138 (dev, crtc) {
unsigned long V_1325 ;
V_1325 = F_428 ( & V_41 -> V_45 , V_41 -> V_97 ) ;
if ( F_31 ( V_1325 ) )
F_431 ( V_2 , V_1325 ) ;
}
F_1014 ( V_2 , false ) ;
F_1015 ( V_2 ) ;
}
void F_281 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_123 ( V_44 ) ;
struct V_49 * V_39 = V_2 -> V_709 ;
struct V_1109 V_1110 ;
int V_273 ;
bool V_1473 = false ;
V_2 -> V_709 = NULL ;
F_2 ( & V_44 -> V_1113 . V_1116 ) ;
F_981 ( & V_1110 , 0 ) ;
V_454:
V_273 = F_982 ( V_44 , & V_1110 ) ;
if ( V_273 == 0 && ! V_1473 ) {
V_1473 = true ;
F_992 ( V_44 ) ;
F_1003 ( V_44 ) ;
}
if ( V_273 == 0 && V_39 ) {
struct V_38 * V_48 ;
struct V_93 * V_41 ;
int V_54 ;
V_39 -> V_1118 = & V_1110 ;
F_471 ( V_39 ) -> V_1226 = true ;
F_472 (state, crtc, crtc_state, i) {
V_48 -> V_1208 = true ;
}
V_273 = F_711 ( V_39 ) ;
}
if ( V_273 == - V_277 ) {
F_713 ( & V_1110 ) ;
goto V_454;
}
F_984 ( & V_1110 ) ;
F_985 ( & V_1110 ) ;
F_4 ( & V_44 -> V_1113 . V_1116 ) ;
if ( V_273 ) {
F_127 ( L_324 , V_273 ) ;
F_712 ( V_39 ) ;
}
}
void F_1016 ( struct V_43 * V_44 )
{
struct V_93 * V_330 ;
struct V_270 * V_271 ;
int V_273 ;
F_1017 ( V_44 ) ;
F_278 ( V_44 ) ;
F_1018 ( V_44 ) ;
F_219 (dev, c) {
V_271 = F_191 ( V_330 -> V_95 -> V_96 ) ;
if ( V_271 == NULL )
continue;
F_2 ( & V_44 -> V_274 ) ;
V_273 = F_190 ( V_330 -> V_95 -> V_96 ,
V_330 -> V_95 -> V_39 -> V_258 ) ;
F_4 ( & V_44 -> V_274 ) ;
if ( V_273 ) {
F_127 ( L_325 ,
F_50 ( V_330 ) -> V_101 ) ;
F_213 ( V_330 -> V_95 -> V_96 ) ;
V_330 -> V_95 -> V_96 = NULL ;
V_330 -> V_95 -> V_41 = V_330 -> V_95 -> V_39 -> V_41 = NULL ;
F_212 ( V_330 -> V_95 ) ;
V_330 -> V_39 -> V_338 &= ~ ( 1 << F_221 ( V_330 -> V_95 ) ) ;
}
}
F_1019 ( V_44 ) ;
}
void F_1020 ( struct V_710 * V_710 )
{
struct V_50 * V_51 = & V_710 -> V_45 ;
F_1021 ( V_51 ) ;
F_1022 ( V_51 ) ;
}
void F_1023 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_710 * V_51 ;
F_1024 ( V_44 ) ;
F_1025 ( V_44 ) ;
F_1026 ( V_2 ) ;
F_1027 ( V_44 ) ;
F_1028 () ;
F_1029 ( V_2 ) ;
F_1030 () ;
F_811 (dev, connector)
V_51 -> V_1474 ( V_51 ) ;
F_1031 ( V_44 ) ;
F_1032 ( V_44 ) ;
F_1033 ( V_44 ) ;
F_1034 ( V_44 ) ;
}
struct V_604 * F_1035 ( struct V_50 * V_51 )
{
return & F_704 ( V_51 ) -> V_45 ;
}
void F_1036 ( struct V_710 * V_51 ,
struct V_46 * V_47 )
{
V_51 -> V_47 = V_47 ;
F_1037 ( & V_51 -> V_45 ,
& V_47 -> V_45 ) ;
}
int F_1038 ( struct V_43 * V_44 , bool V_39 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
unsigned V_9 = F_60 ( V_44 ) -> V_110 >= 6 ? V_1475 : V_1476 ;
T_7 V_1477 ;
if ( F_531 ( V_2 -> V_1478 , V_9 , & V_1477 ) ) {
F_127 ( L_326 ) ;
return - V_1200 ;
}
if ( ! ! ( V_1477 & V_1479 ) == ! V_39 )
return 0 ;
if ( V_39 )
V_1477 &= ~ V_1479 ;
else
V_1477 |= V_1479 ;
if ( F_1039 ( V_2 -> V_1478 , V_9 , V_1477 ) ) {
F_127 ( L_327 ) ;
return - V_1200 ;
}
return 0 ;
}
struct V_1480 *
F_1040 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_104 ;
struct V_1480 * error ;
int V_1481 [] = {
V_229 ,
V_1482 ,
V_1483 ,
V_571 ,
} ;
int V_54 ;
if ( F_60 ( V_44 ) -> V_717 == 0 )
return NULL ;
error = F_502 ( sizeof( * error ) , V_1484 ) ;
if ( error == NULL )
return NULL ;
if ( F_237 ( V_44 ) || F_238 ( V_44 ) )
error -> V_1485 = F_10 ( V_1012 ) ;
F_90 (dev_priv, i) {
error -> V_101 [ V_54 ] . V_1486 =
F_1041 ( V_2 ,
F_425 ( V_54 ) ) ;
if ( ! error -> V_101 [ V_54 ] . V_1486 )
continue;
error -> V_1353 [ V_54 ] . V_580 = F_10 ( F_81 ( V_54 ) ) ;
error -> V_1353 [ V_54 ] . V_1487 = F_10 ( F_683 ( V_54 ) ) ;
error -> V_1353 [ V_54 ] . V_45 = F_10 ( F_680 ( V_54 ) ) ;
error -> V_146 [ V_54 ] . V_580 = F_10 ( F_87 ( V_54 ) ) ;
error -> V_146 [ V_54 ] . V_325 = F_10 ( F_230 ( V_54 ) ) ;
if ( F_60 ( V_44 ) -> V_110 <= 3 ) {
error -> V_146 [ V_54 ] . V_253 = F_10 ( F_224 ( V_54 ) ) ;
error -> V_146 [ V_54 ] . V_540 = F_10 ( F_225 ( V_54 ) ) ;
}
if ( F_60 ( V_44 ) -> V_110 <= 7 && ! F_237 ( V_44 ) )
error -> V_146 [ V_54 ] . V_1190 = F_10 ( F_234 ( V_54 ) ) ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
error -> V_146 [ V_54 ] . V_1488 = F_10 ( F_231 ( V_54 ) ) ;
error -> V_146 [ V_54 ] . V_1489 = F_10 ( F_232 ( V_54 ) ) ;
}
error -> V_101 [ V_54 ] . V_1490 = F_10 ( F_287 ( V_54 ) ) ;
if ( F_162 ( V_44 ) )
error -> V_101 [ V_54 ] . V_1491 = F_10 ( F_1042 ( V_54 ) ) ;
}
error -> V_1492 = F_60 ( V_44 ) -> V_717 ;
if ( F_22 ( V_2 ) )
error -> V_1492 ++ ;
for ( V_54 = 0 ; V_54 < error -> V_1492 ; V_54 ++ ) {
enum V_100 V_103 = V_1481 [ V_54 ] ;
error -> V_100 [ V_54 ] . V_1486 =
F_1041 ( V_2 ,
F_83 ( V_103 ) ) ;
if ( ! error -> V_100 [ V_54 ] . V_1486 )
continue;
error -> V_100 [ V_54 ] . V_103 = V_103 ;
error -> V_100 [ V_54 ] . V_1493 = F_10 ( F_61 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_887 = F_10 ( F_330 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_1494 = F_10 ( F_332 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_894 = F_10 ( F_334 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_890 = F_10 ( F_336 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_1321 = F_10 ( F_338 ( V_103 ) ) ;
error -> V_100 [ V_54 ] . V_1139 = F_10 ( F_340 ( V_103 ) ) ;
}
return error ;
}
void
F_1043 ( struct V_1495 * V_58 ,
struct V_43 * V_44 ,
struct V_1480 * error )
{
struct V_1 * V_2 = V_44 -> V_104 ;
int V_54 ;
if ( ! error )
return;
F_1044 ( V_58 , L_328 , F_60 ( V_44 ) -> V_717 ) ;
if ( F_237 ( V_44 ) || F_238 ( V_44 ) )
F_1044 ( V_58 , L_329 ,
error -> V_1485 ) ;
F_90 (dev_priv, i) {
F_1044 ( V_58 , L_330 , V_54 ) ;
F_1044 ( V_58 , L_331 ,
F_66 ( error -> V_101 [ V_54 ] . V_1486 ) ) ;
F_1044 ( V_58 , L_332 , error -> V_101 [ V_54 ] . V_1490 ) ;
F_1044 ( V_58 , L_333 , error -> V_101 [ V_54 ] . V_1491 ) ;
F_1044 ( V_58 , L_334 , V_54 ) ;
F_1044 ( V_58 , L_335 , error -> V_146 [ V_54 ] . V_580 ) ;
F_1044 ( V_58 , L_336 , error -> V_146 [ V_54 ] . V_325 ) ;
if ( F_60 ( V_44 ) -> V_110 <= 3 ) {
F_1044 ( V_58 , L_337 , error -> V_146 [ V_54 ] . V_253 ) ;
F_1044 ( V_58 , L_338 , error -> V_146 [ V_54 ] . V_540 ) ;
}
if ( F_60 ( V_44 ) -> V_110 <= 7 && ! F_237 ( V_44 ) )
F_1044 ( V_58 , L_339 , error -> V_146 [ V_54 ] . V_1190 ) ;
if ( F_60 ( V_44 ) -> V_110 >= 4 ) {
F_1044 ( V_58 , L_340 , error -> V_146 [ V_54 ] . V_1488 ) ;
F_1044 ( V_58 , L_341 , error -> V_146 [ V_54 ] . V_1489 ) ;
}
F_1044 ( V_58 , L_342 , V_54 ) ;
F_1044 ( V_58 , L_335 , error -> V_1353 [ V_54 ] . V_580 ) ;
F_1044 ( V_58 , L_338 , error -> V_1353 [ V_54 ] . V_1487 ) ;
F_1044 ( V_58 , L_343 , error -> V_1353 [ V_54 ] . V_45 ) ;
}
for ( V_54 = 0 ; V_54 < error -> V_1492 ; V_54 ++ ) {
F_1044 ( V_58 , L_344 ,
F_819 ( error -> V_100 [ V_54 ] . V_103 ) ) ;
F_1044 ( V_58 , L_331 ,
F_66 ( error -> V_100 [ V_54 ] . V_1486 ) ) ;
F_1044 ( V_58 , L_345 , error -> V_100 [ V_54 ] . V_1493 ) ;
F_1044 ( V_58 , L_346 , error -> V_100 [ V_54 ] . V_887 ) ;
F_1044 ( V_58 , L_347 , error -> V_100 [ V_54 ] . V_1494 ) ;
F_1044 ( V_58 , L_348 , error -> V_100 [ V_54 ] . V_894 ) ;
F_1044 ( V_58 , L_349 , error -> V_100 [ V_54 ] . V_890 ) ;
F_1044 ( V_58 , L_350 , error -> V_100 [ V_54 ] . V_1321 ) ;
F_1044 ( V_58 , L_351 , error -> V_100 [ V_54 ] . V_1139 ) ;
}
}
