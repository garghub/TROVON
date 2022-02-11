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
static void F_14 ( struct V_1 * V_2 , enum V_48 V_49 ,
int V_50 )
{
enum V_51 V_52 ;
V_52 = V_49 == V_53 ? V_54 : V_55 ;
F_15 ( V_50 , V_52 ) ;
V_2 -> V_56 = V_52 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
enum V_12 V_57 )
{
T_1 V_6 , V_3 ;
if ( F_1 ( V_2 , V_34 , & V_6 ) )
return 0 ;
switch ( V_57 ) {
case V_15 :
if ( V_6 & V_58 ) {
V_3 = ( V_2 -> V_56 == V_54 ) ?
V_41 : V_59 ;
} else {
if ( F_1 ( V_2 , V_60 , & V_6 ) )
return 0 ;
V_3 = V_6 & V_61 ?
V_41 : V_59 ;
}
break;
case V_42 :
if ( V_6 & V_62 )
V_3 = V_43 ;
else
V_3 = ( V_2 -> V_56 == V_54 ) ?
V_43 : V_63 ;
break;
case V_17 :
V_3 = V_6 & V_64 ?
V_44 : V_65 ;
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
case V_59 :
case V_43 :
case V_63 :
case V_44 :
case V_65 :
return true ;
default:
return false ;
}
}
static int F_18 ( struct V_10 * V_11 ,
unsigned V_66 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 = V_67 ;
struct V_68 * V_69 = V_2 -> V_70 ? V_2 -> V_70 -> V_69 : NULL ;
if ( V_69 && F_19 ( V_69 -> V_50 ) )
F_14 ( V_2 , V_69 -> V_71 , V_69 -> V_50 ) ;
V_3 = F_16 ( V_2 , V_57 ) ;
if ( ! F_17 ( V_3 ) )
return - V_19 ;
return F_6 ( V_2 , V_3 , V_9 , V_66 ) ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
V_3 = F_16 ( V_2 , V_57 ) ;
if ( ! F_17 ( V_3 ) )
return - V_19 ;
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_67 ;
}
static int F_21 ( struct V_10 * V_11 ,
int V_72 , int V_73 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
int V_74 ;
T_1 V_3 ;
switch ( V_57 ) {
case V_42 :
V_3 = V_63 ;
break;
case V_17 :
V_3 = V_65 ;
break;
default:
return - V_19 ;
}
for ( V_74 = F_11 ( V_75 ) - 1 ; V_74 >= 0 ; V_74 -- ) {
if ( V_75 [ V_74 ] >= V_72 &&
V_75 [ V_74 ] <= V_73 )
return F_6 ( V_2 , V_3 ,
V_76 ,
V_74 << V_77 ) ;
}
return - V_19 ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
switch ( V_57 ) {
case V_42 :
V_3 = V_63 ;
break;
case V_17 :
V_3 = V_65 ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_76 ) >> V_77 ;
return ( V_6 < F_11 ( V_75 ) ) ?
V_75 [ V_6 ] : - V_19 ;
}
static int F_23 ( struct V_10 * V_11 , unsigned int V_78 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 , V_23 , V_6 ;
switch ( V_57 ) {
case V_15 :
V_3 = V_59 ;
V_9 = V_79 ;
V_23 = V_80 ;
break;
case V_42 :
V_3 = V_81 ;
V_9 = V_82 ;
V_23 = V_83 ;
break;
case V_17 :
V_3 = V_81 ;
V_9 = V_84 ;
V_23 = V_85 ;
break;
default:
return - V_19 ;
}
if ( V_78 == V_86 )
V_6 = V_87 << V_23 ;
else if ( V_78 == V_88 )
V_6 = V_89 << V_23 ;
else
return - V_19 ;
return F_6 ( V_2 , V_3 , V_9 , V_6 ) ;
}
static unsigned int F_24 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
enum V_12 V_57 = F_9 ( V_11 ) ;
T_1 V_3 , V_9 , V_6 ;
int V_5 ;
switch ( V_57 ) {
case V_15 :
V_3 = V_59 ;
V_9 = V_79 ;
break;
case V_42 :
V_3 = V_81 ;
V_9 = V_82 ;
break;
case V_17 :
V_3 = V_81 ;
V_9 = V_84 ;
break;
default:
return - V_19 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_9 ? V_86 : V_88 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 , V_50 ;
struct V_68 * V_69 = V_2 -> V_70 ? V_2 -> V_70 -> V_69 : NULL ;
enum V_51 V_90 ;
T_1 V_9 [] = { V_58 , V_62 | V_64 } ;
T_1 V_91 [] = { V_92 , V_93 } ;
if ( ! V_69 )
goto V_94;
V_50 = V_69 -> V_50 ;
if ( ! F_19 ( V_50 ) ) {
F_3 ( V_2 -> V_8 , L_2 , V_50 ) ;
return - V_19 ;
}
V_90 = V_69 -> V_95 ;
V_5 = F_26 ( V_2 -> V_8 , V_50 , V_90 , L_3 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 , L_4 , V_5 ) ;
return V_5 ;
}
V_2 -> V_56 = V_90 ;
V_2 -> V_96 = V_50 ;
return 0 ;
V_94:
return F_6 ( V_2 , V_34 , V_9 [ V_2 -> V_22 ] ,
V_91 [ V_2 -> V_22 ] ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_97 * V_70 = V_2 -> V_70 ;
int V_5 ;
if ( ! V_70 || ! V_70 -> V_98 )
goto V_99;
V_5 = F_4 ( V_2 , V_34 , V_70 -> V_100 ) ;
if ( V_5 )
return V_5 ;
V_99:
return F_25 ( V_2 ) ;
}
static struct V_101
* F_28 ( int V_13 , struct V_1 * V_2 )
{
struct V_97 * V_70 = V_2 -> V_70 ;
int V_74 ;
if ( ! V_70 )
return NULL ;
for ( V_74 = 0 ; V_74 < V_2 -> V_102 ; V_74 ++ ) {
if ( V_70 -> V_103 [ V_74 ] . V_13 == V_13 )
return V_70 -> V_103 [ V_74 ] . V_104 ;
}
return NULL ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_107 V_108 = { } ;
struct V_10 * V_11 ;
int V_74 , V_5 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_102 ; V_74 ++ ) {
V_106 = ( V_2 -> V_22 == V_28 ) ? & V_109 [ V_74 ] :
& V_110 [ V_74 ] ;
V_108 . V_8 = V_2 -> V_8 ;
V_108 . V_104 = F_28 ( V_106 -> V_13 , V_2 ) ;
V_108 . V_111 = V_2 ;
V_108 . V_7 = V_2 -> V_7 ;
V_11 = F_30 ( V_106 , & V_108 ) ;
if ( F_31 ( V_11 ) ) {
F_3 ( V_2 -> V_8 , L_5 ) ;
V_5 = F_32 ( V_11 ) ;
goto V_112;
}
* ( V_2 -> V_113 + V_74 ) = V_11 ;
}
return 0 ;
V_112:
while ( -- V_74 >= 0 ) {
V_11 = * ( V_2 -> V_113 + V_74 ) ;
F_33 ( V_11 ) ;
}
return V_5 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_102 ; V_74 ++ ) {
V_11 = * ( V_2 -> V_113 + V_74 ) ;
F_33 ( V_11 ) ;
}
}
static int F_35 ( struct V_114 * V_115 , const struct V_116 * V_13 )
{
struct V_1 * V_2 ;
int V_5 , V_25 , V_102 ;
const int V_117 [] = {
[ V_28 ] = V_118 ,
[ V_31 ] = V_119 ,
} ;
V_2 = F_36 ( & V_115 -> V_8 , sizeof( struct V_1 ) , V_120 ) ;
if ( ! V_2 )
goto V_121;
V_102 = V_117 [ V_13 -> V_111 ] ;
V_25 = sizeof( struct V_10 * ) * V_102 ;
V_2 -> V_113 = F_36 ( & V_115 -> V_8 , V_25 , V_120 ) ;
if ( ! V_2 -> V_113 )
goto V_121;
V_2 -> V_7 = F_37 ( V_115 , & V_122 ) ;
if ( F_31 ( V_2 -> V_7 ) ) {
V_5 = F_32 ( V_2 -> V_7 ) ;
F_3 ( & V_115 -> V_8 , L_6 , V_5 ) ;
goto V_123;
}
V_2 -> V_8 = & V_115 -> V_8 ;
V_2 -> V_70 = V_115 -> V_8 . V_124 ;
V_2 -> V_22 = V_13 -> V_111 ;
V_2 -> V_102 = V_102 ;
F_38 ( V_115 , V_2 ) ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
goto V_123;
return F_29 ( V_2 ) ;
V_121:
return - V_125 ;
V_123:
return V_5 ;
}
static int F_39 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = F_40 ( V_115 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
