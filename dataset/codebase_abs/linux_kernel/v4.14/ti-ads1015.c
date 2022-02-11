static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 != V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 , int V_5 ,
int V_6 )
{
F_3 ( F_1 ( V_2 ) ) ;
V_2 -> V_3 = V_5 ;
V_2 -> V_6 = V_6 ;
}
static void F_4 ( struct V_1 * V_2 , int V_5 )
{
V_2 -> V_3 = V_4 ;
}
static bool F_5 ( struct V_7 * V_8 , unsigned int V_9 )
{
switch ( V_9 ) {
case V_10 :
case V_11 :
case V_12 :
return true ;
default:
return false ;
}
}
static int F_6 ( struct V_1 * V_2 , bool V_13 )
{
int V_14 ;
struct V_7 * V_8 = F_7 ( V_2 -> V_15 ) ;
if ( V_13 ) {
V_14 = F_8 ( V_8 ) ;
if ( V_14 < 0 )
F_9 ( V_8 ) ;
} else {
F_10 ( V_8 ) ;
V_14 = F_11 ( V_8 ) ;
}
return V_14 < 0 ? V_14 : 0 ;
}
static
int F_12 ( struct V_1 * V_2 , int V_5 , int * V_16 )
{
int V_14 , V_17 , V_18 , V_19 ;
unsigned int V_20 , V_21 , V_22 ;
if ( V_5 < 0 || V_5 >= V_4 )
return - V_23 ;
V_14 = F_13 ( V_2 -> V_15 , V_10 , & V_20 ) ;
if ( V_14 )
return V_14 ;
V_17 = V_2 -> V_24 [ V_5 ] . V_17 ;
V_18 = V_2 -> V_24 [ V_5 ] . V_25 ;
V_21 = V_26 | V_27 |
V_28 ;
V_22 = V_5 << V_29 | V_17 << V_30 |
V_18 << V_31 ;
if ( F_1 ( V_2 ) ) {
V_21 |= V_32 | V_33 ;
V_22 |= V_2 -> V_34 [ V_5 ] . V_35 <<
V_36 |
V_2 -> V_6 <<
V_37 ;
}
V_22 = ( V_20 & ~ V_21 ) | ( V_22 & V_21 ) ;
V_14 = F_14 ( V_2 -> V_15 , V_10 , V_22 ) ;
if ( V_14 )
return V_14 ;
if ( V_20 != V_22 || V_2 -> V_38 ) {
int V_39 = ( V_20 & V_28 ) >>
V_31 ;
V_19 = F_15 ( V_40 , V_2 -> V_25 [ V_39 ] ) ;
V_19 += F_15 ( V_40 , V_2 -> V_25 [ V_18 ] ) ;
F_16 ( V_19 , V_19 + 1 ) ;
V_2 -> V_38 = false ;
}
return F_13 ( V_2 -> V_15 , V_41 , V_16 ) ;
}
static T_1 F_17 ( int V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_46 * V_47 = V_45 -> V_47 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
T_2 V_48 [ 8 ] ;
int V_5 , V_14 , V_49 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
F_19 ( & V_2 -> V_50 ) ;
V_5 = F_20 ( V_47 -> V_51 ,
V_47 -> V_52 ) ;
V_14 = F_12 ( V_2 , V_5 , & V_49 ) ;
if ( V_14 < 0 ) {
F_21 ( & V_2 -> V_50 ) ;
goto V_53;
}
V_48 [ 0 ] = V_49 ;
F_21 ( & V_2 -> V_50 ) ;
F_22 ( V_47 , V_48 ,
F_23 ( V_47 ) ) ;
V_53:
F_24 ( V_47 -> V_54 ) ;
return V_55 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_56 const * V_5 ,
int V_57 , int V_58 )
{
int V_59 ;
int V_60 = F_26 ( ( V_57 * 1000000LL + V_58 ) <<
( V_5 -> V_61 . V_62 - 1 ) , 1000000 ) ;
for ( V_59 = 0 ; V_59 < F_27 ( V_63 ) ; V_59 ++ ) {
if ( V_63 [ V_59 ] == V_60 ) {
V_2 -> V_24 [ V_5 -> V_64 ] . V_17 = V_59 ;
return 0 ;
}
}
return - V_23 ;
}
static int F_28 ( struct V_1 * V_2 , int V_5 , int V_65 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < F_27 ( V_66 ) ; V_59 ++ ) {
if ( V_2 -> V_25 [ V_59 ] == V_65 ) {
V_2 -> V_24 [ V_5 ] . V_25 = V_59 ;
return 0 ;
}
}
return - V_23 ;
}
static int F_29 ( struct V_46 * V_47 ,
struct V_56 const * V_5 , int * V_16 ,
int * V_67 , long V_21 )
{
int V_14 , V_68 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
F_19 ( & V_2 -> V_50 ) ;
switch ( V_21 ) {
case V_69 : {
int V_70 = V_5 -> V_61 . V_70 ;
V_14 = F_30 ( V_47 ) ;
if ( V_14 )
break;
if ( F_1 ( V_2 ) &&
V_2 -> V_3 != V_5 -> V_64 ) {
V_14 = - V_71 ;
goto V_72;
}
V_14 = F_6 ( V_2 , true ) ;
if ( V_14 < 0 )
goto V_72;
V_14 = F_12 ( V_2 , V_5 -> V_64 , V_16 ) ;
if ( V_14 < 0 ) {
F_6 ( V_2 , false ) ;
goto V_72;
}
* V_16 = F_31 ( * V_16 >> V_70 , 15 - V_70 ) ;
V_14 = F_6 ( V_2 , false ) ;
if ( V_14 < 0 )
goto V_72;
V_14 = V_73 ;
V_72:
F_32 ( V_47 ) ;
break;
}
case V_74 :
V_68 = V_2 -> V_24 [ V_5 -> V_64 ] . V_17 ;
* V_16 = V_63 [ V_68 ] ;
* V_67 = V_5 -> V_61 . V_62 - 1 ;
V_14 = V_75 ;
break;
case V_76 :
V_68 = V_2 -> V_24 [ V_5 -> V_64 ] . V_25 ;
* V_16 = V_2 -> V_25 [ V_68 ] ;
V_14 = V_73 ;
break;
default:
V_14 = - V_23 ;
break;
}
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static int F_33 ( struct V_46 * V_47 ,
struct V_56 const * V_5 , int V_16 ,
int V_67 , long V_21 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 ;
F_19 ( & V_2 -> V_50 ) ;
switch ( V_21 ) {
case V_74 :
V_14 = F_25 ( V_2 , V_5 , V_16 , V_67 ) ;
break;
case V_76 :
V_14 = F_28 ( V_2 , V_5 -> V_64 , V_16 ) ;
break;
default:
V_14 = - V_23 ;
break;
}
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static int F_34 ( struct V_46 * V_47 ,
const struct V_56 * V_5 , enum V_77 type ,
enum V_78 V_79 , enum V_80 V_81 , int * V_16 ,
int * V_67 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 ;
unsigned int V_35 ;
int V_82 ;
int V_18 ;
F_19 ( & V_2 -> V_50 ) ;
switch ( V_81 ) {
case V_83 :
* V_16 = ( V_79 == V_84 ) ?
V_2 -> V_34 [ V_5 -> V_64 ] . V_85 :
V_2 -> V_34 [ V_5 -> V_64 ] . V_86 ;
V_14 = V_73 ;
break;
case V_87 :
V_18 = V_2 -> V_24 [ V_5 -> V_64 ] . V_25 ;
V_35 = V_2 -> V_34 [ V_5 -> V_64 ] . V_35 ;
V_82 = V_88 [ V_35 ] *
V_40 / V_2 -> V_25 [ V_18 ] ;
* V_16 = V_82 / V_40 ;
* V_67 = V_82 % V_40 ;
V_14 = V_89 ;
break;
default:
V_14 = - V_23 ;
break;
}
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static int F_35 ( struct V_46 * V_47 ,
const struct V_56 * V_5 , enum V_77 type ,
enum V_78 V_79 , enum V_80 V_81 , int V_16 ,
int V_67 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_62 = V_5 -> V_61 . V_62 ;
int V_14 = 0 ;
long long V_82 ;
int V_59 ;
int V_18 ;
F_19 ( & V_2 -> V_50 ) ;
switch ( V_81 ) {
case V_83 :
if ( V_16 >= 1 << ( V_62 - 1 ) || V_16 < - 1 << ( V_62 - 1 ) ) {
V_14 = - V_23 ;
break;
}
if ( V_79 == V_84 )
V_2 -> V_34 [ V_5 -> V_64 ] . V_85 = V_16 ;
else
V_2 -> V_34 [ V_5 -> V_64 ] . V_86 = V_16 ;
break;
case V_87 :
V_18 = V_2 -> V_24 [ V_5 -> V_64 ] . V_25 ;
V_82 = V_16 * V_40 + V_67 ;
for ( V_59 = 0 ; V_59 < F_27 ( V_88 ) - 1 ; V_59 ++ ) {
if ( V_82 <= V_88 [ V_59 ] *
V_40 / V_2 -> V_25 [ V_18 ] )
break;
}
V_2 -> V_34 [ V_5 -> V_64 ] . V_35 = V_59 ;
break;
default:
V_14 = - V_23 ;
break;
}
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static int F_36 ( struct V_46 * V_47 ,
const struct V_56 * V_5 , enum V_77 type ,
enum V_78 V_79 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 = 0 ;
F_19 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_3 == V_5 -> V_64 ) {
switch ( V_79 ) {
case V_84 :
V_14 = 1 ;
break;
case V_90 :
V_14 = ( V_2 -> V_6 == V_91 ) ;
break;
default:
V_14 = - V_23 ;
break;
}
}
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_56 * V_5 , int V_6 )
{
int V_86 = V_2 -> V_34 [ V_5 -> V_64 ] . V_86 ;
int V_85 = V_2 -> V_34 [ V_5 -> V_64 ] . V_85 ;
int V_14 ;
unsigned int V_16 ;
if ( F_1 ( V_2 ) ) {
if ( V_2 -> V_3 != V_5 -> V_64 ||
( V_2 -> V_6 == V_92 &&
V_6 == V_91 ) )
return - V_71 ;
return 0 ;
}
if ( V_6 == V_92 ) {
V_86 = F_38 ( - 1 << ( V_5 -> V_61 . V_62 - 1 ) ,
V_85 - 1 ) ;
}
V_14 = F_14 ( V_2 -> V_15 , V_11 ,
V_86 << V_5 -> V_61 . V_70 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_14 ( V_2 -> V_15 , V_12 ,
V_85 << V_5 -> V_61 . V_70 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_6 ( V_2 , true ) ;
if ( V_14 < 0 )
return V_14 ;
F_2 ( V_2 , V_5 -> V_64 , V_6 ) ;
V_14 = F_12 ( V_2 , V_5 -> V_64 , & V_16 ) ;
if ( V_14 ) {
F_4 ( V_2 , V_5 -> V_64 ) ;
F_6 ( V_2 , false ) ;
}
return V_14 ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_56 * V_5 , int V_6 )
{
int V_14 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_3 != V_5 -> V_64 )
return 0 ;
if ( V_2 -> V_6 == V_92 &&
V_6 == V_91 )
return 0 ;
V_14 = F_40 ( V_2 -> V_15 , V_10 ,
V_32 ,
V_93 <<
V_36 ) ;
if ( V_14 )
return V_14 ;
F_4 ( V_2 , V_5 -> V_64 ) ;
return F_6 ( V_2 , false ) ;
}
static int F_41 ( struct V_46 * V_47 ,
const struct V_56 * V_5 , enum V_77 type ,
enum V_78 V_79 , int V_94 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 ;
int V_6 = ( V_79 == V_90 ) ?
V_91 : V_92 ;
F_19 ( & V_2 -> V_50 ) ;
V_14 = F_30 ( V_47 ) ;
if ( V_14 ) {
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
if ( V_94 )
V_14 = F_37 ( V_2 , V_5 , V_6 ) ;
else
V_14 = F_39 ( V_2 , V_5 , V_6 ) ;
F_32 ( V_47 ) ;
F_21 ( & V_2 -> V_50 ) ;
return V_14 ;
}
static T_1 F_42 ( int V_42 , void * V_95 )
{
struct V_46 * V_47 = V_95 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_16 ;
int V_14 ;
V_14 = F_13 ( V_2 -> V_15 , V_41 , & V_16 ) ;
if ( V_14 )
return V_55 ;
if ( F_1 ( V_2 ) ) {
enum V_78 V_79 ;
T_3 V_96 ;
V_79 = V_2 -> V_6 == V_92 ?
V_84 : V_90 ;
V_96 = F_43 ( V_97 , V_2 -> V_3 ,
V_98 , V_79 ) ;
F_44 ( V_47 , V_96 , F_23 ( V_47 ) ) ;
}
return V_55 ;
}
static int F_45 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
if ( F_1 ( V_2 ) )
return - V_71 ;
return F_6 ( F_18 ( V_47 ) , true ) ;
}
static int F_46 ( struct V_46 * V_47 )
{
return F_6 ( F_18 ( V_47 ) , false ) ;
}
static int F_47 ( struct V_99 * V_100 )
{
struct V_46 * V_47 = F_48 ( V_100 ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_101 * V_102 ;
if ( ! V_100 -> V_8 . V_103 ||
! F_49 ( V_100 -> V_8 . V_103 , NULL ) )
return - V_23 ;
F_50 (client->dev.of_node, node) {
T_4 V_104 ;
unsigned int V_105 ;
unsigned int V_17 = V_106 ;
unsigned int V_25 = V_107 ;
if ( F_51 ( V_102 , L_1 , & V_104 ) ) {
F_52 ( & V_100 -> V_8 , L_2 ,
V_102 ) ;
continue;
}
V_105 = V_104 ;
if ( V_105 >= V_4 ) {
F_52 ( & V_100 -> V_8 ,
L_3 ,
V_105 , V_102 ) ;
continue;
}
if ( ! F_51 ( V_102 , L_4 , & V_104 ) ) {
V_17 = V_104 ;
if ( V_17 > 6 ) {
F_52 ( & V_100 -> V_8 , L_5 ,
V_102 ) ;
F_53 ( V_102 ) ;
return - V_23 ;
}
}
if ( ! F_51 ( V_102 , L_6 , & V_104 ) ) {
V_25 = V_104 ;
if ( V_25 > 7 ) {
F_52 ( & V_100 -> V_8 ,
L_7 ,
V_102 ) ;
F_53 ( V_102 ) ;
return - V_23 ;
}
}
V_2 -> V_24 [ V_105 ] . V_17 = V_17 ;
V_2 -> V_24 [ V_105 ] . V_25 = V_25 ;
}
return 0 ;
}
static void F_54 ( struct V_99 * V_100 )
{
unsigned int V_108 ;
struct V_46 * V_47 = F_48 ( V_100 ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_109 * V_110 = F_55 ( & V_100 -> V_8 ) ;
if ( V_110 ) {
memcpy ( V_2 -> V_24 , V_110 -> V_24 ,
sizeof( V_2 -> V_24 ) ) ;
return;
}
#ifdef F_56
if ( ! F_47 ( V_100 ) )
return;
#endif
for ( V_108 = 0 ; V_108 < V_4 ; ++ V_108 ) {
V_2 -> V_24 [ V_108 ] . V_17 = V_106 ;
V_2 -> V_24 [ V_108 ] . V_25 = V_107 ;
}
}
static int F_57 ( struct V_1 * V_2 , int V_111 )
{
return F_40 ( V_2 -> V_15 , V_10 ,
V_112 ,
V_111 << V_113 ) ;
}
static int F_58 ( struct V_99 * V_100 ,
const struct V_114 * V_115 )
{
struct V_46 * V_47 ;
struct V_1 * V_2 ;
int V_14 ;
enum V_116 V_117 ;
int V_59 ;
V_47 = F_59 ( & V_100 -> V_8 , sizeof( * V_2 ) ) ;
if ( ! V_47 )
return - V_118 ;
V_2 = F_18 ( V_47 ) ;
F_60 ( V_100 , V_47 ) ;
F_61 ( & V_2 -> V_50 ) ;
V_47 -> V_8 . V_119 = & V_100 -> V_8 ;
V_47 -> V_8 . V_103 = V_100 -> V_8 . V_103 ;
V_47 -> V_120 = V_121 ;
V_47 -> V_122 = V_123 ;
if ( V_100 -> V_8 . V_103 )
V_117 = (enum V_116 ) F_62 ( & V_100 -> V_8 ) ;
else
V_117 = V_115 -> V_124 ;
switch ( V_117 ) {
case V_125 :
V_47 -> V_126 = V_127 ;
V_47 -> V_128 = F_27 ( V_127 ) ;
V_47 -> V_81 = & V_129 ;
V_2 -> V_25 = ( unsigned int * ) & V_66 ;
break;
case V_130 :
V_47 -> V_126 = V_131 ;
V_47 -> V_128 = F_27 ( V_131 ) ;
V_47 -> V_81 = & V_132 ;
V_2 -> V_25 = ( unsigned int * ) & V_133 ;
break;
}
V_2 -> V_3 = V_4 ;
for ( V_59 = 0 ; V_59 < V_4 ; V_59 ++ ) {
int V_62 = V_47 -> V_126 [ V_59 ] . V_61 . V_62 ;
V_2 -> V_34 [ V_59 ] . V_86 = - 1 << ( V_62 - 1 ) ;
V_2 -> V_34 [ V_59 ] . V_85 = ( 1 << ( V_62 - 1 ) ) - 1 ;
}
F_54 ( V_100 ) ;
V_2 -> V_15 = F_63 ( V_100 , & V_134 ) ;
if ( F_64 ( V_2 -> V_15 ) ) {
F_52 ( & V_100 -> V_8 , L_8 ) ;
return F_65 ( V_2 -> V_15 ) ;
}
V_14 = F_66 ( & V_100 -> V_8 , V_47 , NULL ,
F_17 ,
& V_135 ) ;
if ( V_14 < 0 ) {
F_52 ( & V_100 -> V_8 , L_9 ) ;
return V_14 ;
}
if ( V_100 -> V_42 ) {
unsigned long V_136 =
F_67 ( F_68 ( V_100 -> V_42 ) ) ;
unsigned int V_137 = V_32 |
V_138 | V_139 ;
unsigned int V_140 =
V_93 << V_36 |
1 << V_141 ;
switch ( V_136 ) {
case V_142 :
V_140 |= V_143 <<
V_144 ;
break;
case V_145 :
V_140 |= V_146 <<
V_144 ;
break;
default:
return - V_23 ;
}
V_14 = F_40 ( V_2 -> V_15 , V_10 ,
V_137 , V_140 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( & V_100 -> V_8 , V_100 -> V_42 ,
NULL , F_42 ,
V_136 | V_147 ,
V_100 -> V_120 , V_47 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_57 ( V_2 , V_148 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_38 = true ;
V_14 = F_70 ( & V_100 -> V_8 ) ;
if ( V_14 )
return V_14 ;
F_71 ( & V_100 -> V_8 , V_149 ) ;
F_72 ( & V_100 -> V_8 ) ;
F_73 ( & V_100 -> V_8 ) ;
V_14 = F_74 ( V_47 ) ;
if ( V_14 < 0 ) {
F_52 ( & V_100 -> V_8 , L_10 ) ;
return V_14 ;
}
return 0 ;
}
static int F_75 ( struct V_99 * V_100 )
{
struct V_46 * V_47 = F_48 ( V_100 ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
F_76 ( V_47 ) ;
F_77 ( & V_100 -> V_8 ) ;
F_78 ( & V_100 -> V_8 ) ;
F_9 ( & V_100 -> V_8 ) ;
return F_57 ( V_2 , V_150 ) ;
}
static int F_79 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = F_48 ( F_80 ( V_8 ) ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
return F_57 ( V_2 , V_150 ) ;
}
static int F_81 ( struct V_7 * V_8 )
{
struct V_46 * V_47 = F_48 ( F_80 ( V_8 ) ) ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_14 ;
V_14 = F_57 ( V_2 , V_148 ) ;
if ( ! V_14 )
V_2 -> V_38 = true ;
return V_14 ;
}
