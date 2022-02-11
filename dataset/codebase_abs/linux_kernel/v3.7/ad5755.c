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
struct V_15 V_16 ;
int V_12 ;
struct V_17 V_18 [] = {
{
. V_19 = & V_6 -> V_7 [ 0 ] . V_10 [ 1 ] ,
. V_20 = 3 ,
. V_21 = 1 ,
} , {
. V_19 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_22 = & V_6 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_20 = 3 ,
} ,
} ;
F_12 ( & V_16 ) ;
F_13 ( & V_18 [ 0 ] , & V_16 ) ;
F_13 ( & V_18 [ 1 ] , & V_16 ) ;
F_8 ( & V_2 -> V_13 ) ;
V_6 -> V_7 [ 0 ] . V_8 = F_3 ( V_23 | ( V_14 << 16 ) ) ;
V_6 -> V_7 [ 1 ] . V_8 = F_3 ( V_24 ) ;
V_12 = F_14 ( V_6 -> V_9 , & V_16 ) ;
if ( V_12 >= 0 )
V_12 = F_15 ( V_6 -> V_7 [ 1 ] . V_8 ) & 0xffff ;
F_9 ( & V_2 -> V_13 ) ;
return V_12 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned int V_11 , unsigned int V_25 , unsigned int V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
V_6 -> V_27 [ V_11 ] |= V_25 ;
V_6 -> V_27 [ V_11 ] &= ~ V_26 ;
V_12 = F_5 ( V_2 , V_11 ,
V_28 , V_6 -> V_27 [ V_11 ] ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_11 , bool V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_30 = F_18 ( V_11 ) ;
F_8 ( & V_2 -> V_13 ) ;
if ( ( bool ) ( V_6 -> V_29 & V_30 ) == V_29 )
goto V_31;
if ( ! V_29 ) {
V_6 -> V_29 &= ~ V_30 ;
F_16 ( V_2 , V_11 ,
V_32 | V_33 , 0 ) ;
F_19 ( 200 ) ;
F_16 ( V_2 , V_11 ,
V_34 , 0 ) ;
} else {
V_6 -> V_29 |= V_30 ;
F_16 ( V_2 , V_11 ,
0 , V_32 | V_34 |
V_33 ) ;
}
V_31:
F_9 ( & V_2 -> V_13 ) ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_35 const * V_36 , int * V_37 , int * V_38 )
{
enum V_39 V_40 = V_6 -> V_27 [ V_36 -> V_11 ] & 7 ;
* V_37 = V_41 [ V_40 ] [ 0 ] ;
* V_38 = V_41 [ V_40 ] [ 1 ] ;
}
static inline int F_21 ( struct V_5 * V_6 ,
struct V_35 const * V_36 )
{
int V_37 , V_38 ;
F_20 ( V_6 , V_36 , & V_37 , & V_38 ) ;
return ( V_37 * ( 1 << V_36 -> V_42 . V_43 ) ) / ( V_38 - V_37 ) ;
}
static inline int F_22 ( struct V_5 * V_6 ,
struct V_35 const * V_36 )
{
int V_37 , V_38 ;
F_20 ( V_6 , V_36 , & V_37 , & V_38 ) ;
return ( ( V_38 - V_37 ) * 1000000000ULL ) >> V_36 -> V_42 . V_43 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_35 const * V_36 , long V_44 , bool V_45 ,
unsigned int * V_3 , unsigned int * V_46 , unsigned int * V_47 )
{
switch ( V_44 ) {
case V_48 :
if ( V_45 )
* V_3 = F_24 ( V_36 -> V_49 ) ;
else
* V_3 = F_25 ( V_36 -> V_49 ) ;
* V_46 = V_36 -> V_42 . V_46 ;
* V_47 = 0 ;
break;
case V_50 :
if ( V_45 )
* V_3 = F_26 ( V_36 -> V_49 ) ;
else
* V_3 = F_27 ( V_36 -> V_49 ) ;
* V_46 = V_6 -> V_51 -> V_52 ;
* V_47 = 32768 ;
break;
case V_53 :
if ( V_45 )
* V_3 = F_28 ( V_36 -> V_49 ) ;
else
* V_3 = F_29 ( V_36 -> V_49 ) ;
* V_46 = V_6 -> V_51 -> V_52 ;
* V_47 = 0 ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int * V_4 , int * V_55 , long V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_3 , V_46 , V_47 ;
int V_12 ;
switch ( V_44 ) {
case V_56 :
* V_4 = 0 ;
* V_55 = F_22 ( V_6 , V_36 ) ;
return V_57 ;
case V_58 :
* V_4 = F_21 ( V_6 , V_36 ) ;
return V_59 ;
default:
V_12 = F_23 ( V_6 , V_36 , V_44 , false ,
& V_3 , & V_46 , & V_47 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = ( V_12 - V_47 ) >> V_46 ;
return V_59 ;
}
return - V_54 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_4 , int V_55 , long V_44 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_46 , V_3 , V_47 ;
int V_12 ;
V_12 = F_23 ( V_6 , V_36 , V_44 , true ,
& V_3 , & V_46 , & V_47 ) ;
if ( V_12 )
return V_12 ;
V_4 <<= V_46 ;
V_4 += V_47 ;
if ( V_4 < 0 || V_4 > 0xffff )
return - V_54 ;
return F_7 ( V_2 , V_3 , V_4 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 , T_2 V_60 ,
const struct V_35 * V_36 , char * V_61 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_61 , L_1 ,
( bool ) ( V_6 -> V_29 & ( 1 << V_36 -> V_11 ) ) ) ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_2 V_60 ,
struct V_35 const * V_36 , const char * V_61 , T_3 V_20 )
{
bool V_29 ;
int V_12 ;
V_12 = F_34 ( V_61 , & V_29 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_17 ( V_2 , V_36 -> V_11 , V_29 ) ;
return V_12 ? V_12 : V_20 ;
}
static bool F_35 ( struct V_5 * V_6 , enum V_39 V_40 )
{
switch ( V_40 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
return V_6 -> V_51 -> V_66 ;
case V_67 :
case V_68 :
case V_69 :
return true ;
default:
return false ;
}
}
static int T_4 F_36 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_4 ;
unsigned int V_72 ;
int V_12 ;
if ( V_71 -> V_73 > V_74 ||
V_71 -> V_75 > V_76 ||
V_71 -> V_77 > V_78 )
return - V_54 ;
V_4 = V_71 -> V_77 << V_79 ;
V_4 |= V_71 -> V_75 << V_80 ;
V_4 |= V_71 -> V_73 << V_81 ;
if ( V_71 -> V_82 )
V_4 |= V_83 ;
V_12 = F_10 ( V_2 , 0 , V_84 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
for ( V_72 = 0 ; V_72 < F_37 ( V_71 -> V_85 ) ; ++ V_72 ) {
V_4 = V_71 -> V_85 [ V_72 ] . V_86 . V_87 <<
V_88 ;
V_4 |= V_71 -> V_85 [ V_72 ] . V_86 . V_89 <<
V_90 ;
if ( V_71 -> V_85 [ V_72 ] . V_86 . V_91 )
V_4 |= V_92 ;
V_12 = F_10 ( V_2 , V_72 ,
V_93 , V_4 ) ;
if ( V_12 < 0 )
return V_12 ;
}
for ( V_72 = 0 ; V_72 < F_37 ( V_71 -> V_85 ) ; ++ V_72 ) {
if ( ! F_35 ( V_6 , V_71 -> V_85 [ V_72 ] . V_40 ) )
return - V_54 ;
V_4 = 0 ;
if ( ! V_71 -> V_85 [ V_72 ] . V_94 )
V_4 |= V_95 ;
if ( V_71 -> V_85 [ V_72 ] . V_96 )
V_4 |= V_97 ;
V_4 |= V_71 -> V_85 [ V_72 ] . V_40 ;
V_12 = F_16 ( V_2 , V_72 , V_4 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
}
return 0 ;
}
static bool T_4 F_38 ( enum V_39 V_40 )
{
switch ( V_40 ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
return true ;
default:
return false ;
}
}
static int T_4 F_39 ( struct V_1 * V_2 ,
const struct V_70 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_98 = V_6 -> V_98 ;
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < V_99 ; ++ V_72 ) {
V_98 [ V_72 ] = V_6 -> V_51 -> V_100 ;
V_98 [ V_72 ] . V_11 = V_72 ;
V_98 [ V_72 ] . V_49 = V_72 ;
if ( V_71 && F_38 ( V_71 -> V_85 [ V_72 ] . V_40 ) )
V_98 [ V_72 ] . type = V_101 ;
else
V_98 [ V_72 ] . type = V_102 ;
}
V_2 -> V_98 = V_98 ;
return 0 ;
}
static int T_4 F_40 ( struct V_103 * V_9 )
{
enum V_104 type = F_41 ( V_9 ) -> V_105 ;
const struct V_70 * V_71 = F_42 ( & V_9 -> V_106 ) ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_12 ;
V_2 = F_43 ( sizeof( * V_6 ) ) ;
if ( V_2 == NULL ) {
F_44 ( & V_9 -> V_106 , L_2 ) ;
return - V_107 ;
}
V_6 = F_2 ( V_2 ) ;
F_45 ( V_9 , V_2 ) ;
V_6 -> V_51 = & V_108 [ type ] ;
V_6 -> V_9 = V_9 ;
V_6 -> V_29 = 0xf ;
V_2 -> V_106 . V_109 = & V_9 -> V_106 ;
V_2 -> V_110 = F_41 ( V_9 ) -> V_110 ;
V_2 -> V_44 = & V_111 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = V_99 ;
if ( ! V_71 )
V_71 = & V_115 ;
V_12 = F_39 ( V_2 , V_71 ) ;
if ( V_12 )
goto V_116;
V_12 = F_36 ( V_2 , V_71 ) ;
if ( V_12 )
goto V_116;
V_12 = F_46 ( V_2 ) ;
if ( V_12 ) {
F_44 ( & V_9 -> V_106 , L_3 , V_12 ) ;
goto V_116;
}
return 0 ;
V_116:
F_47 ( V_2 ) ;
return V_12 ;
}
static int T_5 F_48 ( struct V_103 * V_9 )
{
struct V_1 * V_2 = F_49 ( V_9 ) ;
F_50 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
