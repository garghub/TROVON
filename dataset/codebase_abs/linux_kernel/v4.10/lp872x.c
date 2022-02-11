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
static int F_8 ( struct V_1 * V_2 )
{
enum V_10 V_11 = V_2 -> V_12 ;
T_1 V_6 , V_9 , V_13 ;
int * V_14 , V_15 , V_5 ;
int V_16 [] = { 25 , 50 } ;
int V_17 [] = { 32 , 64 , 128 , 256 } ;
switch ( V_11 ) {
case V_18 :
V_9 = V_19 ;
V_13 = V_20 ;
V_14 = & V_16 [ 0 ] ;
V_15 = F_9 ( V_16 ) ;
break;
case V_21 :
V_9 = V_22 ;
V_13 = V_23 ;
V_14 = & V_17 [ 0 ] ;
V_15 = F_9 ( V_17 ) ;
break;
default:
return - V_24 ;
}
V_5 = F_1 ( V_2 , V_25 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_9 ) >> V_13 ;
if ( V_6 >= V_15 )
return - V_24 ;
return * ( V_14 + V_6 ) ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_29 = F_12 ( V_27 ) ;
int V_30 = F_8 ( V_2 ) ;
int V_5 ;
T_1 V_3 , V_6 ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_29 ) {
case V_31 ... V_32 :
V_3 = V_33 + V_29 ;
break;
case V_34 ... V_35 :
V_3 = V_33 + V_29 - V_36 ;
break;
case V_37 :
V_3 = V_38 ;
break;
default:
return - V_24 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_39 ) >> V_40 ;
return V_6 > V_41 ? 0 : V_6 * V_30 ;
}
static void F_13 ( struct V_1 * V_2 , enum V_42 V_43 ,
int V_44 )
{
enum V_45 V_46 ;
V_46 = V_43 == V_47 ? V_48 : V_49 ;
F_14 ( V_44 , V_46 ) ;
V_2 -> V_50 = V_46 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
enum V_28 V_51 )
{
T_1 V_6 , V_3 ;
if ( F_1 ( V_2 , V_25 , & V_6 ) )
return 0 ;
switch ( V_51 ) {
case V_32 :
if ( V_6 & V_52 ) {
V_3 = ( V_2 -> V_50 == V_48 ) ?
V_53 : V_54 ;
} else {
if ( F_1 ( V_2 , V_55 , & V_6 ) )
return 0 ;
V_3 = V_6 & V_56 ?
V_53 : V_54 ;
}
break;
case V_35 :
if ( V_6 & V_57 )
V_3 = V_58 ;
else
V_3 = ( V_2 -> V_50 == V_48 ) ?
V_58 : V_59 ;
break;
case V_37 :
V_3 = V_6 & V_60 ?
V_38 : V_61 ;
break;
default:
return 0 ;
}
return V_3 ;
}
static bool F_16 ( T_1 V_3 )
{
switch ( V_3 ) {
case V_53 :
case V_54 :
case V_58 :
case V_59 :
case V_38 :
case V_61 :
return true ;
default:
return false ;
}
}
static int F_17 ( struct V_26 * V_27 ,
unsigned V_62 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
T_1 V_3 , V_9 = V_63 ;
struct V_64 * V_65 = V_2 -> V_66 ? V_2 -> V_66 -> V_65 : NULL ;
if ( V_65 && F_18 ( V_65 -> V_44 ) )
F_13 ( V_2 , V_65 -> V_67 , V_65 -> V_44 ) ;
V_3 = F_15 ( V_2 , V_51 ) ;
if ( ! F_16 ( V_3 ) )
return - V_24 ;
return F_6 ( V_2 , V_3 , V_9 , V_62 ) ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
V_3 = F_15 ( V_2 , V_51 ) ;
if ( ! F_16 ( V_3 ) )
return - V_24 ;
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_63 ;
}
static int F_20 ( struct V_26 * V_27 ,
int V_68 , int V_69 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
int V_70 ;
T_1 V_3 ;
switch ( V_51 ) {
case V_35 :
V_3 = V_59 ;
break;
case V_37 :
V_3 = V_61 ;
break;
default:
return - V_24 ;
}
for ( V_70 = F_9 ( V_71 ) - 1 ; V_70 >= 0 ; V_70 -- ) {
if ( V_71 [ V_70 ] >= V_68 &&
V_71 [ V_70 ] <= V_69 )
return F_6 ( V_2 , V_3 ,
V_72 ,
V_70 << V_73 ) ;
}
return - V_24 ;
}
static int F_21 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
T_1 V_3 , V_6 ;
int V_5 ;
switch ( V_51 ) {
case V_35 :
V_3 = V_59 ;
break;
case V_37 :
V_3 = V_61 ;
break;
default:
return - V_24 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_6 = ( V_6 & V_72 ) >> V_73 ;
return ( V_6 < F_9 ( V_71 ) ) ?
V_71 [ V_6 ] : - V_24 ;
}
static int F_22 ( struct V_26 * V_27 , unsigned int V_74 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
T_1 V_3 , V_9 , V_13 , V_6 ;
switch ( V_51 ) {
case V_32 :
V_3 = V_54 ;
V_9 = V_75 ;
V_13 = V_76 ;
break;
case V_35 :
V_3 = V_77 ;
V_9 = V_78 ;
V_13 = V_79 ;
break;
case V_37 :
V_3 = V_77 ;
V_9 = V_80 ;
V_13 = V_81 ;
break;
default:
return - V_24 ;
}
if ( V_74 == V_82 )
V_6 = V_83 << V_13 ;
else if ( V_74 == V_84 )
V_6 = V_85 << V_13 ;
else
return - V_24 ;
return F_6 ( V_2 , V_3 , V_9 , V_6 ) ;
}
static unsigned int F_23 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_11 ( V_27 ) ;
enum V_28 V_51 = F_12 ( V_27 ) ;
T_1 V_3 , V_9 , V_6 ;
int V_5 ;
switch ( V_51 ) {
case V_32 :
V_3 = V_54 ;
V_9 = V_75 ;
break;
case V_35 :
V_3 = V_77 ;
V_9 = V_78 ;
break;
case V_37 :
V_3 = V_77 ;
V_9 = V_80 ;
break;
default:
return - V_24 ;
}
V_5 = F_1 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
return V_5 ;
return V_6 & V_9 ? V_82 : V_84 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_5 , V_44 ;
struct V_64 * V_65 = V_2 -> V_66 ? V_2 -> V_66 -> V_65 : NULL ;
enum V_45 V_86 ;
T_1 V_9 [] = { V_52 , V_57 | V_60 } ;
T_1 V_87 [] = { V_88 , V_89 } ;
if ( ! V_65 )
goto V_90;
V_44 = V_65 -> V_44 ;
if ( ! F_18 ( V_44 ) )
goto V_90;
V_86 = V_65 -> V_91 ;
V_5 = F_25 ( V_2 -> V_8 , V_44 , V_86 , L_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 , L_3 , V_5 ) ;
return V_5 ;
}
V_2 -> V_50 = V_86 ;
return 0 ;
V_90:
return F_6 ( V_2 , V_25 , V_9 [ V_2 -> V_12 ] ,
V_87 [ V_2 -> V_12 ] ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 , V_44 ;
if ( ! V_2 -> V_66 )
return - V_24 ;
V_44 = V_2 -> V_66 -> V_92 ;
if ( ! F_18 ( V_44 ) )
return 0 ;
V_5 = F_25 ( V_2 -> V_8 , V_44 , V_93 , L_4 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 , L_3 , V_5 ) ;
return V_5 ;
}
if ( V_2 -> V_12 == V_18 )
F_27 ( V_94 , 1.5 * V_94 ) ;
else
F_27 ( V_95 , 1.5 * V_95 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_96 * V_66 = V_2 -> V_66 ;
int V_5 ;
if ( ! V_66 || ! V_66 -> V_97 )
goto V_98;
V_5 = F_4 ( V_2 , V_25 , V_66 -> V_99 ) ;
if ( V_5 )
return V_5 ;
V_98:
return F_24 ( V_2 ) ;
}
static struct V_100
* F_29 ( int V_101 , struct V_1 * V_2 )
{
struct V_96 * V_66 = V_2 -> V_66 ;
int V_70 ;
if ( ! V_66 )
return NULL ;
for ( V_70 = 0 ; V_70 < V_2 -> V_102 ; V_70 ++ ) {
if ( V_66 -> V_103 [ V_70 ] . V_101 == V_101 )
return V_66 -> V_103 [ V_70 ] . V_104 ;
}
return NULL ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_105 * V_106 ;
struct V_107 V_108 = { } ;
struct V_26 * V_27 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_102 ; V_70 ++ ) {
V_106 = ( V_2 -> V_12 == V_18 ) ? & V_109 [ V_70 ] :
& V_110 [ V_70 ] ;
V_108 . V_8 = V_2 -> V_8 ;
V_108 . V_104 = F_29 ( V_106 -> V_101 , V_2 ) ;
V_108 . V_111 = V_2 ;
V_108 . V_7 = V_2 -> V_7 ;
V_27 = F_31 ( V_2 -> V_8 , V_106 , & V_108 ) ;
if ( F_32 ( V_27 ) ) {
F_3 ( V_2 -> V_8 , L_5 ) ;
return F_33 ( V_27 ) ;
}
}
return 0 ;
}
static struct V_96
* F_34 ( struct V_112 * V_8 , enum V_10 V_113 )
{
struct V_114 * V_115 = V_8 -> V_116 ;
struct V_96 * V_66 ;
struct V_117 * V_118 ;
int V_119 ;
int V_120 ;
int V_70 ;
T_1 V_121 ;
V_66 = F_35 ( V_8 , sizeof( * V_66 ) , V_122 ) ;
if ( ! V_66 )
return F_36 ( - V_123 ) ;
F_37 ( V_115 , L_6 , & V_66 -> V_99 ) ;
if ( F_38 ( V_115 , L_7 , NULL ) )
V_66 -> V_97 = true ;
V_66 -> V_65 = F_35 ( V_8 , sizeof( struct V_64 ) , V_122 ) ;
if ( ! V_66 -> V_65 )
return F_36 ( - V_123 ) ;
V_66 -> V_65 -> V_44 = F_39 ( V_115 , L_8 , 0 ) ;
F_37 ( V_115 , L_9 , ( T_1 * ) & V_66 -> V_65 -> V_67 ) ;
F_37 ( V_115 , L_10 , & V_121 ) ;
V_66 -> V_65 -> V_91 = V_121 ? V_48 : V_49 ;
V_66 -> V_92 = F_39 ( V_115 , L_11 , 0 ) ;
if ( F_40 ( V_115 ) == 0 )
goto V_124;
switch ( V_113 ) {
case V_18 :
V_118 = V_125 ;
V_119 = F_9 ( V_125 ) ;
break;
case V_21 :
V_118 = V_126 ;
V_119 = F_9 ( V_126 ) ;
break;
default:
goto V_124;
}
V_120 = V_117 ( V_8 , V_115 , V_118 , V_119 ) ;
if ( V_120 <= 0 )
goto V_124;
for ( V_70 = 0 ; V_70 < V_119 ; V_70 ++ ) {
V_66 -> V_103 [ V_70 ] . V_101 =
(enum V_28 ) V_118 [ V_70 ] . V_111 ;
V_66 -> V_103 [ V_70 ] . V_104 = V_118 [ V_70 ] . V_104 ;
}
V_124:
return V_66 ;
}
static struct V_96
* F_34 ( struct V_112 * V_8 , enum V_10 V_113 )
{
return NULL ;
}
static int F_41 ( struct V_127 * V_128 , const struct V_129 * V_101 )
{
struct V_1 * V_2 ;
struct V_96 * V_66 ;
int V_5 ;
const int V_130 [] = {
[ V_18 ] = V_131 ,
[ V_21 ] = V_132 ,
} ;
if ( V_128 -> V_8 . V_116 ) {
V_66 = F_34 ( & V_128 -> V_8 ,
(enum V_10 ) V_101 -> V_111 ) ;
if ( F_32 ( V_66 ) )
return F_33 ( V_66 ) ;
} else {
V_66 = F_42 ( & V_128 -> V_8 ) ;
}
V_2 = F_35 ( & V_128 -> V_8 , sizeof( struct V_1 ) , V_122 ) ;
if ( ! V_2 )
return - V_123 ;
V_2 -> V_102 = V_130 [ V_101 -> V_111 ] ;
V_2 -> V_7 = F_43 ( V_128 , & V_133 ) ;
if ( F_32 ( V_2 -> V_7 ) ) {
V_5 = F_33 ( V_2 -> V_7 ) ;
F_3 ( & V_128 -> V_8 , L_12 , V_5 ) ;
return V_5 ;
}
V_2 -> V_8 = & V_128 -> V_8 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_12 = V_101 -> V_111 ;
F_44 ( V_128 , V_2 ) ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_28 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return F_30 ( V_2 ) ;
}
