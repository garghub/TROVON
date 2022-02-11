int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , 1 , & V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , bool V_6 , T_2 V_7 )
{
T_1 V_4 , V_8 ;
int V_9 ;
if ( V_10 == V_7 ) {
V_9 = F_4 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_11 , 1 , & V_8 ) ;
if ( V_9 != 1 )
return V_9 ;
V_8 &= ~ V_12 ;
}
if ( ( V_10 == V_7 ) && ( ! V_6 ) ) {
V_8 |= V_13 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_11 , V_8 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_4 ( V_2 -> V_5 ,
V_2 -> V_3 -> V_14 , 1 , & V_4 ) ;
if ( V_9 != 1 )
return V_9 ;
if ( V_6 )
V_4 &= ~ V_7 ;
else
V_4 |= V_7 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_14 , V_4 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 ) {
F_5 ( V_15 ) ;
if ( V_10 == V_7 ) {
V_8 |= V_16 ;
V_9 = F_1 ( V_2 ,
V_2 -> V_3 -> V_11 , V_8 ) ;
if ( V_9 )
return V_9 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , bool V_17 )
{
int V_9 ;
if ( V_17 )
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_11 , 0 ) ;
else
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_11 ,
V_18 ) ;
if ( V_9 )
return V_9 ;
if ( V_17 )
F_5 ( V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_20 * V_21 )
{
int V_9 ;
T_1 V_4 ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
V_9 = F_6 ( V_2 , true ) ;
if ( V_9 )
return V_9 ;
V_4 = ( V_22 << V_23 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_24 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 = V_25 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_26 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 = V_27 / V_28 - 1 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_29 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_4 = ( V_30 << V_31 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_32 , V_4 ) ;
if ( V_9 )
return V_9 ;
memcpy ( & V_2 -> V_33 , V_34 [ V_2 -> V_35 ] . V_36 ,
sizeof( struct V_37 ) ) ;
V_9 = F_6 ( V_2 , false ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 ,
int V_38 , int * V_39 )
{
int V_40 , V_9 ;
T_3 V_4 ;
V_40 = ( V_38 - V_41 ) * 2 ;
V_9 = F_4 ( V_2 -> V_5 , V_3 + V_40 , 2 ,
( T_1 * ) & V_4 ) ;
if ( V_9 != 2 )
return - V_42 ;
* V_39 = ( short ) F_10 ( & V_4 ) ;
return V_43 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_44 const * V_45 ,
int * V_39 ,
int * V_46 ,
long V_7 ) {
struct V_1 * V_2 = F_8 ( V_21 ) ;
switch ( V_7 ) {
case V_47 :
{
int V_48 , V_9 ;
V_48 = V_43 ;
V_9 = 0 ;
F_12 ( & V_21 -> V_49 ) ;
if ( ! V_2 -> V_33 . V_50 ) {
V_9 = F_6 ( V_2 , true ) ;
if ( V_9 )
goto V_51;
}
switch ( V_45 -> type ) {
case V_52 :
if ( ! V_2 -> V_33 . V_53 ||
! V_2 -> V_33 . V_50 ) {
V_9 = F_3 ( V_2 , true ,
V_10 ) ;
if ( V_9 )
goto V_51;
}
V_48 = F_9 ( V_2 , V_2 -> V_3 -> V_54 ,
V_45 -> V_55 , V_39 ) ;
if ( ! V_2 -> V_33 . V_53 ||
! V_2 -> V_33 . V_50 ) {
V_9 = F_3 ( V_2 , false ,
V_10 ) ;
if ( V_9 )
goto V_51;
}
break;
case V_56 :
if ( ! V_2 -> V_33 . V_57 ||
! V_2 -> V_33 . V_50 ) {
V_9 = F_3 ( V_2 , true ,
V_58 ) ;
if ( V_9 )
goto V_51;
}
V_48 = F_9 ( V_2 , V_2 -> V_3 -> V_59 ,
V_45 -> V_55 , V_39 ) ;
if ( ! V_2 -> V_33 . V_57 ||
! V_2 -> V_33 . V_50 ) {
V_9 = F_3 ( V_2 , false ,
V_58 ) ;
if ( V_9 )
goto V_51;
}
break;
case V_60 :
F_5 ( V_61 ) ;
F_9 ( V_2 , V_2 -> V_3 -> V_62 ,
V_41 , V_39 ) ;
break;
default:
V_48 = - V_42 ;
break;
}
V_51:
if ( ! V_2 -> V_33 . V_50 )
V_9 |= F_6 ( V_2 , false ) ;
F_13 ( & V_21 -> V_49 ) ;
if ( V_9 )
return V_9 ;
return V_48 ;
}
case V_63 :
switch ( V_45 -> type ) {
case V_52 :
* V_39 = 0 ;
* V_46 = V_64 [ V_2 -> V_33 . V_65 ] ;
return V_66 ;
case V_56 :
* V_39 = 0 ;
* V_46 = V_67 [ V_2 -> V_33 . V_68 ] ;
return V_69 ;
case V_60 :
* V_39 = 0 ;
* V_46 = V_70 ;
return V_69 ;
default:
return - V_42 ;
}
case V_71 :
switch ( V_45 -> type ) {
case V_60 :
* V_39 = V_72 ;
return V_43 ;
default:
return - V_42 ;
}
default:
return - V_42 ;
}
}
static int F_14 ( struct V_1 * V_2 , int V_65 )
{
int V_9 ;
T_1 V_4 ;
if ( V_65 < 0 || V_65 > V_73 )
return - V_42 ;
if ( V_65 == V_2 -> V_33 . V_65 )
return 0 ;
V_4 = ( V_65 << V_23 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_24 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_33 . V_65 = V_65 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_74 )
{
int V_9 ;
T_1 V_4 ;
if ( V_74 < 0 || V_74 > V_75 )
return - V_42 ;
if ( V_74 == V_2 -> V_33 . V_68 )
return 0 ;
V_4 = ( V_74 << V_31 ) ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_32 , V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_33 . V_68 = V_74 ;
return 0 ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_44 const * V_45 ,
int V_39 ,
int V_46 ,
long V_7 ) {
struct V_1 * V_2 = F_8 ( V_21 ) ;
int V_9 ;
F_12 ( & V_21 -> V_49 ) ;
if ( V_2 -> V_33 . V_50 ) {
V_9 = - V_76 ;
goto V_77;
}
V_9 = F_6 ( V_2 , true ) ;
if ( V_9 )
goto V_77;
switch ( V_7 ) {
case V_63 :
switch ( V_45 -> type ) {
case V_52 :
V_9 = F_14 ( V_2 , V_39 ) ;
break;
case V_56 :
V_9 = F_15 ( V_2 , V_39 ) ;
break;
default:
V_9 = - V_42 ;
break;
}
break;
default:
V_9 = - V_42 ;
break;
}
V_77:
V_9 |= F_6 ( V_2 , false ) ;
F_13 ( & V_21 -> V_49 ) ;
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 , int V_78 )
{
const int V_79 [] = { 188 , 98 , 42 , 20 , 10 , 5 } ;
const int V_4 [] = { V_80 , V_81 ,
V_82 , V_25 ,
V_83 , V_84 } ;
int V_85 , V_86 , V_9 ;
T_1 V_87 ;
V_86 = ( V_78 >> 1 ) ;
V_85 = 0 ;
while ( ( V_86 < V_79 [ V_85 ] ) && ( V_85 < F_18 ( V_4 ) - 1 ) )
V_85 ++ ;
V_87 = V_4 [ V_85 ] ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_26 , V_87 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_33 . V_26 = V_87 ;
return 0 ;
}
static T_4 F_19 ( struct V_88 * V_89 ,
struct V_90 * V_91 , const char * V_92 , T_5 V_93 )
{
T_6 V_94 ;
T_1 V_4 ;
int V_9 ;
struct V_20 * V_21 = F_20 ( V_89 ) ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
if ( F_21 ( V_92 , 10 , & V_94 ) )
return - V_42 ;
if ( V_94 < V_95 ||
V_94 > V_96 )
return - V_42 ;
if ( V_94 == V_2 -> V_33 . V_94 )
return V_93 ;
F_12 ( & V_21 -> V_49 ) ;
if ( V_2 -> V_33 . V_50 ) {
V_9 = - V_76 ;
goto V_97;
}
V_9 = F_6 ( V_2 , true ) ;
if ( V_9 )
goto V_97;
V_4 = V_27 / V_94 - 1 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_29 , V_4 ) ;
if ( V_9 )
goto V_97;
V_2 -> V_33 . V_94 = V_94 ;
V_9 = F_17 ( V_2 , V_94 ) ;
if ( V_9 )
goto V_97;
V_97:
V_9 |= F_6 ( V_2 , false ) ;
F_13 ( & V_21 -> V_49 ) ;
if ( V_9 )
return V_9 ;
return V_93 ;
}
static T_4 F_22 ( struct V_88 * V_89 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_1 * V_2 = F_8 ( F_20 ( V_89 ) ) ;
return sprintf ( V_92 , L_1 , V_2 -> V_33 . V_94 ) ;
}
static T_4 F_23 ( struct V_88 * V_89 ,
struct V_90 * V_91 , char * V_92 )
{
struct V_1 * V_2 = F_8 ( F_20 ( V_89 ) ) ;
struct V_98 * V_99 = F_24 ( V_91 ) ;
T_7 * V_100 ;
switch ( V_99 -> V_101 ) {
case V_102 :
case V_103 :
V_100 = V_2 -> V_104 . V_105 ;
return sprintf ( V_92 , L_2 ,
V_100 [ 0 ] , V_100 [ 1 ] , V_100 [ 2 ] , V_100 [ 3 ] , V_100 [ 4 ] , V_100 [ 5 ] , V_100 [ 6 ] , V_100 [ 7 ] , V_100 [ 8 ] ) ;
default:
return - V_42 ;
}
}
static int F_25 ( struct V_20 * V_21 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
if ( V_2 -> V_107 != V_107 )
return - V_42 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_108 * V_109 )
{
int V_9 ;
V_2 -> V_35 = V_110 ;
V_2 -> V_111 = & V_34 [ V_2 -> V_35 ] ;
V_2 -> V_3 = V_34 [ V_2 -> V_35 ] . V_3 ;
V_9 = F_1 ( V_2 , V_2 -> V_3 -> V_11 ,
V_112 ) ;
if ( V_9 )
return V_9 ;
F_5 ( V_113 ) ;
V_9 = F_6 ( V_2 , false ) ;
if ( V_9 )
return V_9 ;
V_9 = F_6 ( V_2 , true ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_2 , false ,
V_58 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_3 ( V_2 , false ,
V_10 ) ;
if ( V_9 )
return V_9 ;
return 0 ;
}
static int F_27 ( struct V_114 * V_5 ,
const struct V_108 * V_109 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_115 * V_116 ;
int V_9 ;
if ( ! F_28 ( V_5 -> V_117 ,
V_118 ) )
return - V_119 ;
V_21 = F_29 ( & V_5 -> V_89 , sizeof( * V_2 ) ) ;
if ( ! V_21 )
return - V_120 ;
V_2 = F_8 ( V_21 ) ;
V_2 -> V_5 = V_5 ;
V_116 = (struct V_115
* ) F_30 ( & V_5 -> V_89 ) ;
if ( V_116 )
V_2 -> V_104 = * V_116 ;
V_9 = F_26 ( V_2 , V_109 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_7 ( V_21 ) ;
if ( V_9 ) {
F_31 ( & V_5 -> V_89 ,
L_3 ) ;
return V_9 ;
}
F_32 ( V_5 , V_21 ) ;
V_21 -> V_89 . V_121 = & V_5 -> V_89 ;
V_21 -> V_122 = V_109 -> V_122 ;
V_21 -> V_123 = V_124 ;
V_21 -> V_125 = F_18 ( V_124 ) ;
V_21 -> V_126 = & V_127 ;
V_21 -> V_128 = V_129 ;
V_9 = F_33 ( V_21 ,
V_130 ,
V_131 ,
NULL ) ;
if ( V_9 ) {
F_31 ( & V_2 -> V_5 -> V_89 , L_4 ,
V_9 ) ;
return V_9 ;
}
V_9 = F_34 ( V_21 ) ;
if ( V_9 ) {
F_31 ( & V_2 -> V_5 -> V_89 , L_5 , V_9 ) ;
goto V_132;
}
F_35 ( V_2 -> V_133 ) ;
F_36 ( & V_2 -> V_134 ) ;
V_9 = F_37 ( V_21 ) ;
if ( V_9 ) {
F_31 ( & V_2 -> V_5 -> V_89 , L_6 , V_9 ) ;
goto V_135;
}
return 0 ;
V_135:
F_38 ( V_2 ) ;
V_132:
F_39 ( V_21 ) ;
return V_9 ;
}
static int F_40 ( struct V_114 * V_5 )
{
struct V_20 * V_21 = F_41 ( V_5 ) ;
struct V_1 * V_2 = F_8 ( V_21 ) ;
F_42 ( V_21 ) ;
F_38 ( V_2 ) ;
F_39 ( V_21 ) ;
return 0 ;
}
static int F_43 ( struct V_88 * V_89 )
{
return F_6 (
F_8 ( F_41 ( F_44 ( V_89 ) ) ) , true ) ;
}
static int F_45 ( struct V_88 * V_89 )
{
return F_6 (
F_8 ( F_41 ( F_44 ( V_89 ) ) ) , false ) ;
}
