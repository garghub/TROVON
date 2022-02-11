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
return - V_24 ;
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
return - V_24 ;
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
if ( ! F_18 ( V_44 ) ) {
F_25 ( V_2 -> V_8 , L_2 , V_44 ) ;
goto V_90;
}
V_86 = V_65 -> V_91 ;
V_5 = F_26 ( V_2 -> V_8 , V_44 , V_86 , L_3 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_8 , L_4 , V_5 ) ;
return V_5 ;
}
V_2 -> V_50 = V_86 ;
V_2 -> V_92 = V_44 ;
return 0 ;
V_90:
return F_6 ( V_2 , V_25 , V_9 [ V_2 -> V_12 ] ,
V_87 [ V_2 -> V_12 ] ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_93 * V_66 = V_2 -> V_66 ;
int V_5 ;
if ( ! V_66 || ! V_66 -> V_94 )
goto V_95;
V_5 = F_4 ( V_2 , V_25 , V_66 -> V_96 ) ;
if ( V_5 )
return V_5 ;
V_95:
return F_24 ( V_2 ) ;
}
static struct V_97
* F_28 ( int V_98 , struct V_1 * V_2 )
{
struct V_93 * V_66 = V_2 -> V_66 ;
int V_70 ;
if ( ! V_66 )
return NULL ;
for ( V_70 = 0 ; V_70 < V_2 -> V_99 ; V_70 ++ ) {
if ( V_66 -> V_100 [ V_70 ] . V_98 == V_98 )
return V_66 -> V_100 [ V_70 ] . V_101 ;
}
return NULL ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
struct V_104 V_105 = { } ;
struct V_26 * V_27 ;
int V_70 , V_5 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_99 ; V_70 ++ ) {
V_103 = ( V_2 -> V_12 == V_18 ) ? & V_106 [ V_70 ] :
& V_107 [ V_70 ] ;
V_105 . V_8 = V_2 -> V_8 ;
V_105 . V_101 = F_28 ( V_103 -> V_98 , V_2 ) ;
V_105 . V_108 = V_2 ;
V_105 . V_7 = V_2 -> V_7 ;
V_27 = F_30 ( V_103 , & V_105 ) ;
if ( F_31 ( V_27 ) ) {
F_3 ( V_2 -> V_8 , L_5 ) ;
V_5 = F_32 ( V_27 ) ;
goto V_109;
}
* ( V_2 -> V_110 + V_70 ) = V_27 ;
}
return 0 ;
V_109:
while ( -- V_70 >= 0 ) {
V_27 = * ( V_2 -> V_110 + V_70 ) ;
F_33 ( V_27 ) ;
}
return V_5 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_99 ; V_70 ++ ) {
V_27 = * ( V_2 -> V_110 + V_70 ) ;
F_33 ( V_27 ) ;
}
}
static struct V_93
* F_35 ( struct V_111 * V_8 , enum V_10 V_112 )
{
struct V_113 * V_114 = V_8 -> V_115 ;
struct V_93 * V_66 ;
struct V_116 * V_117 ;
struct V_97 * V_118 ;
int V_119 ;
int V_120 ;
int V_70 ;
T_1 V_121 ;
V_66 = F_36 ( V_8 , sizeof( * V_66 ) , V_122 ) ;
if ( ! V_66 )
goto V_123;
F_37 ( V_114 , L_6 , & V_66 -> V_96 ) ;
if ( F_38 ( V_114 , L_7 , NULL ) )
V_66 -> V_94 = true ;
V_66 -> V_65 = F_36 ( V_8 , sizeof( struct V_64 ) , V_122 ) ;
if ( ! V_66 -> V_65 )
goto V_123;
V_66 -> V_65 -> V_44 = F_39 ( V_114 , L_8 , 0 ) ;
F_37 ( V_114 , L_9 , ( T_1 * ) & V_66 -> V_65 -> V_67 ) ;
F_37 ( V_114 , L_10 , & V_121 ) ;
V_66 -> V_65 -> V_91 = V_121 ? V_48 : V_49 ;
if ( F_40 ( V_114 ) == 0 )
goto V_123;
switch ( V_112 ) {
case V_18 :
V_117 = V_124 ;
V_119 = F_9 ( V_124 ) ;
break;
case V_21 :
V_117 = V_125 ;
V_119 = F_9 ( V_125 ) ;
break;
default:
goto V_123;
}
V_120 = V_116 ( V_8 , V_114 , V_117 , V_119 ) ;
if ( V_120 <= 0 )
goto V_123;
for ( V_70 = 0 ; V_70 < V_119 ; V_70 ++ ) {
V_66 -> V_100 [ V_70 ] . V_98 = ( int ) V_117 [ V_70 ] . V_108 ;
V_66 -> V_100 [ V_70 ] . V_101 = V_117 [ V_70 ] . V_101 ;
if ( strncmp ( V_117 [ V_70 ] . V_126 , L_11 , 4 ) )
continue;
V_118 = V_66 -> V_100 [ V_70 ] . V_101 ;
V_118 -> V_127 . V_128 |= V_129 ;
V_118 -> V_127 . V_130 |= V_131 ;
}
V_123:
return V_66 ;
}
static struct V_93
* F_35 ( struct V_111 * V_8 , enum V_10 V_112 )
{
return NULL ;
}
static int F_41 ( struct V_132 * V_133 , const struct V_134 * V_98 )
{
struct V_1 * V_2 ;
int V_5 , V_15 , V_99 ;
const int V_135 [] = {
[ V_18 ] = V_136 ,
[ V_21 ] = V_137 ,
} ;
if ( V_133 -> V_8 . V_115 )
V_133 -> V_8 . V_138 = F_35 ( & V_133 -> V_8 ,
(enum V_10 ) V_98 -> V_108 ) ;
V_2 = F_36 ( & V_133 -> V_8 , sizeof( struct V_1 ) , V_122 ) ;
if ( ! V_2 )
goto V_139;
V_99 = V_135 [ V_98 -> V_108 ] ;
V_15 = sizeof( struct V_26 * ) * V_99 ;
V_2 -> V_110 = F_36 ( & V_133 -> V_8 , V_15 , V_122 ) ;
if ( ! V_2 -> V_110 )
goto V_139;
V_2 -> V_7 = F_42 ( V_133 , & V_140 ) ;
if ( F_31 ( V_2 -> V_7 ) ) {
V_5 = F_32 ( V_2 -> V_7 ) ;
F_3 ( & V_133 -> V_8 , L_12 , V_5 ) ;
goto V_141;
}
V_2 -> V_8 = & V_133 -> V_8 ;
V_2 -> V_66 = V_133 -> V_8 . V_138 ;
V_2 -> V_12 = V_98 -> V_108 ;
V_2 -> V_99 = V_99 ;
F_43 ( V_133 , V_2 ) ;
V_5 = F_27 ( V_2 ) ;
if ( V_5 )
goto V_141;
return F_29 ( V_2 ) ;
V_139:
return - V_142 ;
V_141:
return V_5 ;
}
static int F_44 ( struct V_132 * V_133 )
{
struct V_1 * V_2 = F_45 ( V_133 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
