static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
unsigned int V_6 ;
V_5 = F_2 ( V_2 -> V_7 , V_3 , & V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
return V_5 ;
}
* V_4 = ( T_1 ) V_6 ;
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_5 ( V_2 -> V_7 , V_3 , V_4 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_9 , T_1 V_4 )
{
return F_7 ( V_2 -> V_7 , V_3 , V_9 , V_4 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
enum V_12 V_13 = F_9 ( V_11 ) ;
switch ( V_13 ) {
case V_14 ... V_15 :
return V_13 ;
case V_16 ... V_17 :
return V_13 - V_18 ;
default:
return - V_19 ;
}
}
static int F_10 ( struct V_1 * V_2 )
{
enum V_20 V_21 = V_2 -> V_22 ;
T_1 V_6 , V_9 , V_23 ;
int * V_24 , V_25 , V_5 ;
int V_26 [] = { 25 , 50 } ;
int V_27 [] = { 32 , 64 , 128 , 256 } ;
switch ( V_21 ) {
case V_28 :
V_9 = V_29 ;
V_23 = V_30 ;
V_24 = & V_26 [ 0 ] ;
V_25 = F_11 ( V_26 ) ;
break;
case V_31 :
V_9 = V_32 ;
V_23 = V_33 ;
V_24 = & V_27 [ 0 ] ;
V_25 = F_11 ( V_27 ) ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_34 , & V_6 ) ;
if ( V_5 )
return - V_19 ;
V_6 = ( V_6 & V_9 ) >> V_23 ;
if ( V_6 >= V_25 )
return - V_19 ;
return * ( V_24 + V_6 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_35 = F_9 ( V_11 ) ;
int V_36 = F_10 ( V_2 ) ;
int V_5 , V_37 ;
T_1 V_3 , V_6 ;
if ( V_36 < 0 )
return - V_19 ;
switch ( V_35 ) {
case V_14 ... V_38 :
case V_16 ... V_39 :
V_37 = F_8 ( V_11 ) ;
if ( V_37 < 0 )
return - V_19 ;
V_3 = V_40 + V_37 ;
break;
case V_15 :
V_3 = V_41 ;
break;
case V_42 :
V_3 = V_43 ;
break;
case V_17 :
V_3 = V_44 ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_45 ) >> V_46 ;
return V_6 > V_47 ? 0 : V_6 * V_36 ;
}
static void F_14 ( struct V_1 * V_2 , int V_48 )
{
enum V_49 V_50 = V_2 -> V_51 -> V_52 -> V_53 ;
enum V_54 V_55 ;
V_55 = V_50 == V_56 ? V_57 : V_58 ;
F_15 ( V_48 , V_55 ) ;
V_2 -> V_59 = V_55 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
enum V_12 V_60 )
{
T_1 V_6 , V_3 ;
if ( F_1 ( V_2 , V_34 , & V_6 ) )
return 0 ;
switch ( V_60 ) {
case V_15 :
if ( V_6 & V_61 ) {
V_3 = ( V_2 -> V_59 == V_57 ) ?
V_41 : V_62 ;
} else {
if ( F_1 ( V_2 , V_63 , & V_6 ) )
return 0 ;
V_3 = V_6 & V_64 ?
V_41 : V_62 ;
}
break;
case V_42 :
if ( V_6 & V_65 )
V_3 = V_43 ;
else
V_3 = ( V_2 -> V_59 == V_57 ) ?
V_43 : V_66 ;
break;
case V_17 :
V_3 = V_6 & V_67 ?
V_44 : V_68 ;
break;
default:
return 0 ;
}
return V_3 ;
}
static bool F_17 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_41 :
case V_62 :
case V_43 :
case V_66 :
case V_44 :
case V_68 :
return true ;
default:
return false ;
}
}
static int F_18 ( struct V_10 * V_11 ,
unsigned V_69 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 = V_70 ;
struct V_71 * V_52 = V_2 -> V_51 -> V_52 ;
if ( V_52 && F_19 ( V_52 -> V_48 ) )
F_14 ( V_2 , V_52 -> V_48 ) ;
V_3 = F_16 ( V_2 , V_60 ) ;
if ( ! F_17 ( V_3 ) )
return - V_19 ;
return F_6 ( V_2 , V_3 , V_9 , V_69 ) ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
V_3 = F_16 ( V_2 , V_60 ) ;
if ( ! F_17 ( V_3 ) )
return - V_19 ;
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_70 ;
}
static int F_21 ( struct V_10 * V_11 ,
int V_72 , int V_73 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
int V_74 , V_75 = F_11 ( V_76 ) ;
T_1 V_3 , V_6 ;
switch ( V_60 ) {
case V_42 :
V_3 = V_66 ;
break;
case V_17 :
V_3 = V_68 ;
break;
default:
return - V_19 ;
}
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
if ( V_76 [ V_74 ] >= V_72 &&
V_76 [ V_74 ] <= V_73 )
break;
if ( V_74 == V_75 )
return - V_19 ;
V_6 = V_74 << V_77 ;
return F_6 ( V_2 , V_3 , V_78 , V_6 ) ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
switch ( V_60 ) {
case V_42 :
V_3 = V_66 ;
break;
case V_17 :
V_3 = V_68 ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_78 ) >> V_77 ;
return ( V_6 < F_11 ( V_76 ) ) ?
V_76 [ V_6 ] : - V_19 ;
}
static int F_23 ( struct V_10 * V_11 , unsigned int V_79 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 , V_23 , V_6 ;
switch ( V_60 ) {
case V_15 :
V_3 = V_62 ;
V_9 = V_80 ;
V_23 = V_81 ;
break;
case V_42 :
V_3 = V_82 ;
V_9 = V_83 ;
V_23 = V_84 ;
break;
case V_17 :
V_3 = V_82 ;
V_9 = V_85 ;
V_23 = V_86 ;
break;
default:
return - V_19 ;
}
if ( V_79 == V_87 )
V_6 = V_88 << V_23 ;
else if ( V_79 == V_89 )
V_6 = V_90 << V_23 ;
else
return - V_19 ;
return F_6 ( V_2 , V_3 , V_9 , V_6 ) ;
}
static unsigned int F_24 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_60 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 , V_6 ;
int V_5 ;
switch ( V_60 ) {
case V_15 :
V_3 = V_62 ;
V_9 = V_80 ;
break;
case V_42 :
V_3 = V_82 ;
V_9 = V_83 ;
break;
case V_17 :
V_3 = V_82 ;
V_9 = V_85 ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_9 ? V_87 : V_89 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_71 * V_52 = V_2 -> V_51 -> V_52 ;
T_1 V_6 = 0 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_34 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_5 = 0 ;
if ( V_2 -> V_22 == V_28 ) {
if ( V_6 & V_61 )
V_5 = V_52 ? 0 : - V_19 ;
} else {
if ( ( V_6 & V_65 ) == V_91 )
V_5 = V_52 ? 0 : - V_19 ;
}
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 , V_48 ;
struct V_71 * V_52 = V_2 -> V_51 -> V_52 ;
enum V_54 V_92 ;
V_5 = F_25 ( V_2 ) ;
if ( V_5 ) {
F_27 ( V_2 -> V_8 , L_2 , V_5 ) ;
return V_5 ;
}
V_48 = V_52 -> V_48 ;
if ( ! F_19 ( V_48 ) ) {
F_3 ( V_2 -> V_8 , L_3 , V_48 ) ;
return - V_19 ;
}
V_92 = V_52 -> V_93 ;
V_5 = F_28 ( V_2 -> V_8 , V_48 , V_92 , L_4 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 , L_5 , V_5 ) ;
return V_5 ;
}
V_2 -> V_59 = V_92 ;
V_2 -> V_94 = V_48 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_95 * V_51 = V_2 -> V_51 ;
int V_5 ;
if ( ! V_51 -> V_96 )
return 0 ;
V_5 = F_4 ( V_2 , V_34 , V_51 -> V_97 ) ;
if ( V_5 )
return V_5 ;
return F_26 ( V_2 ) ;
}
static struct V_98
* F_30 ( int V_13 , struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_99 ; V_74 ++ ) {
if ( V_2 -> V_51 -> V_100 [ V_74 ] . V_13 == V_13 )
return V_2 -> V_51 -> V_100 [ V_74 ] . V_101 ;
}
return NULL ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
struct V_104 V_105 = { } ;
struct V_10 * V_11 ;
int V_74 , V_5 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_99 ; V_74 ++ ) {
V_103 = ( V_2 -> V_22 == V_28 ) ? & V_106 [ V_74 ] :
& V_107 [ V_74 ] ;
V_105 . V_8 = V_2 -> V_8 ;
V_105 . V_101 = F_30 ( V_103 -> V_13 , V_2 ) ;
V_105 . V_108 = V_2 ;
V_105 . V_7 = V_2 -> V_7 ;
V_11 = F_32 ( V_103 , & V_105 ) ;
if ( F_33 ( V_11 ) ) {
F_3 ( V_2 -> V_8 , L_6 ) ;
V_5 = F_34 ( V_11 ) ;
goto V_109;
}
* ( V_2 -> V_110 + V_74 ) = V_11 ;
}
return 0 ;
V_109:
while ( -- V_74 >= 0 ) {
V_11 = * ( V_2 -> V_110 + V_74 ) ;
F_35 ( V_11 ) ;
}
return V_5 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_99 ; V_74 ++ ) {
V_11 = * ( V_2 -> V_110 + V_74 ) ;
F_35 ( V_11 ) ;
}
}
static int F_37 ( struct V_111 * V_112 , const struct V_113 * V_13 )
{
struct V_1 * V_2 ;
struct V_95 * V_51 = V_112 -> V_8 . V_114 ;
int V_5 , V_25 , V_99 ;
const int V_115 [] = {
[ V_28 ] = V_116 ,
[ V_31 ] = V_117 ,
} ;
if ( ! V_51 ) {
F_3 ( & V_112 -> V_8 , L_7 ) ;
return - V_19 ;
}
V_2 = F_38 ( & V_112 -> V_8 , sizeof( struct V_1 ) , V_118 ) ;
if ( ! V_2 )
goto V_119;
V_99 = V_115 [ V_13 -> V_108 ] ;
V_25 = sizeof( struct V_10 * ) * V_99 ;
V_2 -> V_110 = F_38 ( & V_112 -> V_8 , V_25 , V_118 ) ;
if ( ! V_2 -> V_110 )
goto V_119;
V_2 -> V_7 = F_39 ( V_112 , & V_120 ) ;
if ( F_33 ( V_2 -> V_7 ) ) {
V_5 = F_34 ( V_2 -> V_7 ) ;
F_3 ( & V_112 -> V_8 , L_8 , V_5 ) ;
goto V_121;
}
V_2 -> V_8 = & V_112 -> V_8 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_22 = V_13 -> V_108 ;
V_2 -> V_99 = V_99 ;
F_40 ( V_112 , V_2 ) ;
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
goto V_121;
return F_31 ( V_2 ) ;
V_119:
return - V_122 ;
V_121:
return V_5 ;
}
static int T_2 F_41 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_42 ( V_112 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
