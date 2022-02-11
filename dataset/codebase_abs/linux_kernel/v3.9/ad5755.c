static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( ( V_3 << 16 ) | V_4 ) ;
return F_4 ( V_6 -> V_9 , & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] , 3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_11 , unsigned int V_3 , unsigned int V_4 )
{
return F_1 ( V_2 ,
F_6 ( V_11 ) , ( V_3 << 13 ) | V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
int V_12 ;
F_8 ( & V_2 -> V_13 ) ;
V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_11 ,
unsigned int V_3 , unsigned int V_4 )
{
int V_12 ;
F_8 ( & V_2 -> V_13 ) ;
V_12 = F_5 ( V_2 , V_11 , V_3 , V_4 ) ;
F_9 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
struct V_15 V_16 [] = {
{
. V_17 = & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] ,
. V_18 = 3 ,
. V_19 = 1 ,
} , {
. V_17 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_20 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_18 = 3 ,
} ,
} ;
F_8 ( & V_2 -> V_13 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( V_21 | ( V_14 << 16 ) ) ;
V_6 -> V_7 [ 1 ] . V_8 = F_3 ( V_22 ) ;
V_12 = F_12 ( V_6 -> V_9 , V_16 , F_13 ( V_16 ) ) ;
if ( V_12 >= 0 )
V_12 = F_14 ( V_6 -> V_7 [ 1 ] . V_8 ) & 0xffff ;
F_9 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_11 , unsigned int V_23 , unsigned int V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
V_6 -> V_25 [ V_11 ] |= V_23 ;
V_6 -> V_25 [ V_11 ] &= ~ V_24 ;
V_12 = F_5 ( V_2 , V_11 ,
V_26 , V_6 -> V_25 [ V_11 ] ) ;
return V_12 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_11 , bool V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_28 = F_17 ( V_11 ) ;
F_8 ( & V_2 -> V_13 ) ;
if ( ( bool ) ( V_6 -> V_27 & V_28 ) == V_27 )
goto V_29;
if ( ! V_27 ) {
V_6 -> V_27 &= ~ V_28 ;
F_15 ( V_2 , V_11 ,
V_30 | V_31 , 0 ) ;
F_18 ( 200 ) ;
F_15 ( V_2 , V_11 ,
V_32 , 0 ) ;
} else {
V_6 -> V_27 |= V_28 ;
F_15 ( V_2 , V_11 ,
0 , V_30 | V_32 |
V_31 ) ;
}
V_29:
F_9 ( & V_2 -> V_13 ) ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_33 const * V_34 , int * V_35 , int * V_36 )
{
enum V_37 V_38 = V_6 -> V_25 [ V_34 -> V_11 ] & 7 ;
* V_35 = V_39 [ V_38 ] [ 0 ] ;
* V_36 = V_39 [ V_38 ] [ 1 ] ;
}
static inline int F_20 ( struct V_5 * V_6 ,
struct V_33 const * V_34 )
{
int V_35 , V_36 ;
F_19 ( V_6 , V_34 , & V_35 , & V_36 ) ;
return ( V_35 * ( 1 << V_34 -> V_40 . V_41 ) ) / ( V_36 - V_35 ) ;
}
static inline int F_21 ( struct V_5 * V_6 ,
struct V_33 const * V_34 )
{
int V_35 , V_36 ;
F_19 ( V_6 , V_34 , & V_35 , & V_36 ) ;
return ( ( V_36 - V_35 ) * 1000000000ULL ) >> V_34 -> V_40 . V_41 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_33 const * V_34 , long V_42 , bool V_43 ,
unsigned int * V_3 , unsigned int * V_44 , unsigned int * V_45 )
{
switch ( V_42 ) {
case V_46 :
if ( V_43 )
* V_3 = F_23 ( V_34 -> V_47 ) ;
else
* V_3 = F_24 ( V_34 -> V_47 ) ;
* V_44 = V_34 -> V_40 . V_44 ;
* V_45 = 0 ;
break;
case V_48 :
if ( V_43 )
* V_3 = F_25 ( V_34 -> V_47 ) ;
else
* V_3 = F_26 ( V_34 -> V_47 ) ;
* V_44 = V_6 -> V_49 -> V_50 ;
* V_45 = 32768 ;
break;
case V_51 :
if ( V_43 )
* V_3 = F_27 ( V_34 -> V_47 ) ;
else
* V_3 = F_28 ( V_34 -> V_47 ) ;
* V_44 = V_6 -> V_49 -> V_50 ;
* V_45 = 0 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_33 * V_34 , int * V_4 , int * V_53 , long V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_3 , V_44 , V_45 ;
int V_12 ;
switch ( V_42 ) {
case V_54 :
* V_4 = 0 ;
* V_53 = F_21 ( V_6 , V_34 ) ;
return V_55 ;
case V_56 :
* V_4 = F_20 ( V_6 , V_34 ) ;
return V_57 ;
default:
V_12 = F_22 ( V_6 , V_34 , V_42 , false ,
& V_3 , & V_44 , & V_45 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = ( V_12 - V_45 ) >> V_44 ;
return V_57 ;
}
return - V_52 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_33 * V_34 , int V_4 , int V_53 , long V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_44 , V_3 , V_45 ;
int V_12 ;
V_12 = F_22 ( V_6 , V_34 , V_42 , true ,
& V_3 , & V_44 , & V_45 ) ;
if ( V_12 )
return V_12 ;
V_4 <<= V_44 ;
V_4 += V_45 ;
if ( V_4 < 0 || V_4 > 0xffff )
return - V_52 ;
return F_7 ( V_2 , V_3 , V_4 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_2 V_58 ,
const struct V_33 * V_34 , char * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_59 , L_1 ,
( bool ) ( V_6 -> V_27 & ( 1 << V_34 -> V_11 ) ) ) ;
}
static T_1 F_32 ( struct V_1 * V_2 , T_2 V_58 ,
struct V_33 const * V_34 , const char * V_59 , T_3 V_18 )
{
bool V_27 ;
int V_12 ;
V_12 = F_33 ( V_59 , & V_27 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_16 ( V_2 , V_34 -> V_11 , V_27 ) ;
return V_12 ? V_12 : V_18 ;
}
static bool F_34 ( struct V_5 * V_6 , enum V_37 V_38 )
{
switch ( V_38 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return V_6 -> V_49 -> V_64 ;
case V_65 :
case V_66 :
case V_67 :
return true ;
default:
return false ;
}
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_4 ;
unsigned int V_70 ;
int V_12 ;
if ( V_69 -> V_71 > V_72 ||
V_69 -> V_73 > V_74 ||
V_69 -> V_75 > V_76 )
return - V_52 ;
V_4 = V_69 -> V_75 << V_77 ;
V_4 |= V_69 -> V_73 << V_78 ;
V_4 |= V_69 -> V_71 << V_79 ;
if ( V_69 -> V_80 )
V_4 |= V_81 ;
V_12 = F_10 ( V_2 , 0 , V_82 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
for ( V_70 = 0 ; V_70 < F_13 ( V_69 -> V_83 ) ; ++ V_70 ) {
V_4 = V_69 -> V_83 [ V_70 ] . V_84 . V_85 <<
V_86 ;
V_4 |= V_69 -> V_83 [ V_70 ] . V_84 . V_87 <<
V_88 ;
if ( V_69 -> V_83 [ V_70 ] . V_84 . V_89 )
V_4 |= V_90 ;
V_12 = F_10 ( V_2 , V_70 ,
V_91 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_70 = 0 ; V_70 < F_13 ( V_69 -> V_83 ) ; ++ V_70 ) {
if ( ! F_34 ( V_6 , V_69 -> V_83 [ V_70 ] . V_38 ) )
return - V_52 ;
V_4 = 0 ;
if ( ! V_69 -> V_83 [ V_70 ] . V_92 )
V_4 |= V_93 ;
if ( V_69 -> V_83 [ V_70 ] . V_94 )
V_4 |= V_95 ;
V_4 |= V_69 -> V_83 [ V_70 ] . V_38 ;
V_12 = F_15 ( V_2 , V_70 , V_4 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static bool F_36 ( enum V_37 V_38 )
{
switch ( V_38 ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return true ;
default:
return false ;
}
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_33 * V_96 = V_6 -> V_96 ;
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_97 ; ++ V_70 ) {
V_96 [ V_70 ] = V_6 -> V_49 -> V_98 ;
V_96 [ V_70 ] . V_11 = V_70 ;
V_96 [ V_70 ] . V_47 = V_70 ;
if ( V_69 && F_36 ( V_69 -> V_83 [ V_70 ] . V_38 ) )
V_96 [ V_70 ] . type = V_99 ;
else
V_96 [ V_70 ] . type = V_100 ;
}
V_2 -> V_96 = V_96 ;
return 0 ;
}
static int F_38 ( struct V_101 * V_9 )
{
enum V_102 type = F_39 ( V_9 ) -> V_103 ;
const struct V_68 * V_69 = F_40 ( & V_9 -> V_104 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_12 ;
V_2 = F_41 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_42 ( & V_9 -> V_104 , L_2 ) ;
return - V_105 ;
}
V_6 = F_2 ( V_2 ) ;
F_43 ( V_9 , V_2 ) ;
V_6 -> V_49 = & V_106 [ type ] ;
V_6 -> V_9 = V_9 ;
V_6 -> V_27 = 0xf ;
V_2 -> V_104 . V_107 = & V_9 -> V_104 ;
V_2 -> V_108 = F_39 ( V_9 ) -> V_108 ;
V_2 -> V_42 = & V_109 ;
V_2 -> V_110 = V_111 ;
V_2 -> V_112 = V_97 ;
if ( ! V_69 )
V_69 = & V_113 ;
V_12 = F_37 ( V_2 , V_69 ) ;
if ( V_12 )
goto V_114;
V_12 = F_35 ( V_2 , V_69 ) ;
if ( V_12 )
goto V_114;
V_12 = F_44 ( V_2 ) ;
if ( V_12 ) {
F_42 ( & V_9 -> V_104 , L_3 , V_12 ) ;
goto V_114;
}
return 0 ;
V_114:
F_45 ( V_2 ) ;
return V_12 ;
}
static int F_46 ( struct V_101 * V_9 )
{
struct V_1 * V_2 = F_47 ( V_9 ) ;
F_48 ( V_2 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
