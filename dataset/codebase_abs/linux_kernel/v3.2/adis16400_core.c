static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_3 ) ;
V_7 -> V_9 [ 1 ] = V_4 ;
V_5 = F_5 ( V_7 -> V_10 , V_7 -> V_9 , 2 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 V_12 )
{
int V_5 ;
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
} , {
. V_17 = V_7 -> V_9 + 2 ,
. V_18 = 8 ,
. V_19 = 2 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_4 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = V_12 & 0xFF ;
V_7 -> V_9 [ 2 ] = F_4 ( V_11 + 1 ) ;
V_7 -> V_9 [ 3 ] = ( V_12 >> 8 ) & 0xFF ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_11 ,
T_2 * V_4 )
{
struct V_13 V_14 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 ;
struct V_15 V_16 [] = {
{
. V_17 = V_7 -> V_9 ,
. V_18 = 8 ,
. V_19 = 2 ,
. V_20 = 1 ,
} , {
. V_21 = V_7 -> V_22 ,
. V_18 = 8 ,
. V_19 = 2 ,
} ,
} ;
F_3 ( & V_7 -> V_8 ) ;
V_7 -> V_9 [ 0 ] = F_12 ( V_11 ) ;
V_7 -> V_9 [ 1 ] = 0 ;
F_8 ( & V_14 ) ;
F_9 ( & V_16 [ 0 ] , & V_14 ) ;
F_9 ( & V_16 [ 1 ] , & V_14 ) ;
V_5 = F_10 ( V_7 -> V_10 , & V_14 ) ;
if ( V_5 ) {
F_13 ( & V_7 -> V_10 -> V_23 ,
L_1 ,
V_11 ) ;
goto V_24;
}
* V_4 = ( V_7 -> V_22 [ 0 ] << 8 ) | V_7 -> V_22 [ 1 ] ;
V_24:
F_6 ( & V_7 -> V_8 ) ;
return V_5 ;
}
static T_3 F_14 ( struct V_25 * V_23 ,
struct V_26 * V_27 ,
char * V_28 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
int V_5 , V_19 = 0 ;
T_2 V_29 ;
int V_30 ;
V_5 = F_11 ( V_2 ,
V_31 ,
& V_29 ) ;
if ( V_5 )
return V_5 ;
V_30 = ( V_29 & V_32 ) ? 53 : 1638 ;
V_30 /= ( V_29 & V_33 ) + 1 ;
V_19 = sprintf ( V_28 , L_2 , V_30 ) ;
return V_19 ;
}
static T_3 F_16 ( struct V_25 * V_23 ,
struct V_26 * V_27 ,
const char * V_28 ,
T_4 V_19 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
long V_4 ;
int V_5 ;
T_1 V_29 ;
V_5 = F_17 ( V_28 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_2 -> V_34 ) ;
V_29 = ( 1638 / V_4 ) ;
if ( V_29 > 0 )
V_29 -- ;
V_29 &= V_33 ;
if ( ( V_29 & V_33 ) >= 0x0A )
V_7 -> V_10 -> V_35 = V_36 ;
else
V_7 -> V_10 -> V_35 = V_37 ;
V_5 = F_1 ( V_2 ,
V_31 ,
V_29 ) ;
F_6 ( & V_2 -> V_34 ) ;
return V_5 ? V_5 : V_19 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_38 ,
V_39 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 , L_3 ) ;
return V_5 ;
}
static T_3 F_19 ( struct V_25 * V_23 ,
struct V_26 * V_27 ,
const char * V_28 , T_4 V_19 )
{
bool V_4 ;
int V_5 ;
V_5 = F_20 ( V_28 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_4 ) {
V_5 = F_18 ( F_15 ( V_23 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
return V_19 ;
}
int F_21 ( struct V_1 * V_2 , bool V_40 )
{
int V_5 ;
T_2 V_41 ;
V_5 = F_11 ( V_2 , V_42 , & V_41 ) ;
if ( V_5 )
goto V_24;
V_41 |= V_43 ;
if ( V_40 )
V_41 |= V_44 ;
else
V_41 &= ~ V_44 ;
V_5 = F_7 ( V_2 , V_42 , V_41 ) ;
if ( V_5 )
goto V_24;
V_24:
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 = V_45 ;
V_5 = F_7 ( V_2 , V_46 , V_4 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 ,
L_4 ) ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_2 V_47 ;
int V_5 ;
struct V_25 * V_23 = & V_2 -> V_23 ;
V_5 = F_11 ( V_2 ,
V_48 , & V_47 ) ;
if ( V_5 < 0 ) {
F_13 ( V_23 , L_5 ) ;
goto V_24;
}
V_5 = V_47 ;
if ( V_47 & V_49 )
F_13 ( V_23 , L_6 ) ;
if ( V_47 & V_50 )
F_13 ( V_23 , L_7 ) ;
if ( V_47 & V_51 )
F_13 ( V_23 , L_8 ) ;
if ( V_47 & V_52 )
F_13 ( V_23 , L_9 ) ;
if ( V_47 & V_53 )
F_13 ( V_23 , L_10 ) ;
if ( V_47 & V_54 )
F_13 ( V_23 , L_11 ) ;
if ( V_47 & V_55 )
F_13 ( V_23 , L_12 ) ;
if ( V_47 & V_56 )
F_13 ( V_23 , L_13 ) ;
if ( V_47 & V_57 )
F_13 ( V_23 , L_14 ) ;
if ( V_47 & V_58 )
F_13 ( V_23 , L_15 ) ;
if ( V_47 & V_59 )
F_13 ( V_23 , L_16 ) ;
if ( V_47 & V_60 )
F_13 ( V_23 , L_17 ) ;
if ( V_47 & V_61 )
F_13 ( V_23 , L_18 ) ;
if ( V_47 & V_62 )
F_13 ( V_23 , L_19 ) ;
if ( V_47 & V_63 )
F_13 ( V_23 , L_20 ) ;
V_24:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_42 ,
V_64 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_21 ) ;
goto V_65;
}
F_25 ( V_66 ) ;
F_23 ( V_2 ) ;
V_65:
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_67 , V_68 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_10 -> V_35 = V_36 ;
V_7 -> V_10 -> V_69 = V_70 ;
F_27 ( V_7 -> V_10 ) ;
V_5 = F_21 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_22 ) ;
goto V_65;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_23 ) ;
goto V_65;
}
V_5 = F_23 ( V_2 ) ;
if ( V_5 ) {
F_18 ( V_2 ) ;
F_13 ( & V_2 -> V_23 , L_24 ) ;
F_25 ( V_71 ) ;
V_5 = F_23 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_25 ) ;
goto V_65;
}
}
if ( V_7 -> V_72 -> V_73 & V_74 ) {
V_5 = F_11 ( V_2 ,
V_75 , & V_67 ) ;
if ( V_5 )
goto V_65;
if ( ( V_67 & 0xF000 ) != V_7 -> V_72 -> V_76 )
F_28 ( & V_2 -> V_23 , L_26 ) ;
F_29 ( & V_2 -> V_23 , L_27 ,
V_2 -> V_77 , V_67 ,
V_7 -> V_10 -> V_78 , V_7 -> V_10 -> V_79 ) ;
}
V_5 = F_11 ( V_2 ,
V_31 , & V_68 ) ;
if ( ! V_5 && ( V_68 & V_33 ) < 0x0A ) {
V_7 -> V_10 -> V_35 = V_36 ;
F_27 ( V_7 -> V_10 ) ;
}
V_65:
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_80 const * V_81 ,
int V_4 ,
int V_82 ,
long V_83 )
{
int V_5 ;
switch ( V_83 ) {
case ( 1 << V_84 ) :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_7 ( V_2 ,
V_85 [ V_81 -> V_86 ] [ 1 ] ,
V_4 ) ;
F_6 ( & V_2 -> V_34 ) ;
return V_5 ;
default:
return - V_87 ;
}
}
static int F_31 ( struct V_1 * V_2 ,
struct V_80 const * V_81 ,
int * V_4 ,
int * V_82 ,
long V_83 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_88 ;
T_5 V_89 ;
switch ( V_83 ) {
case 0 :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_11 ( V_2 ,
V_85 [ V_81 -> V_86 ] [ 0 ] ,
& V_89 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_34 ) ;
return V_5 ;
}
V_89 &= ( 1 << V_81 -> V_90 . V_91 ) - 1 ;
if ( V_81 -> V_90 . V_92 == 's' ) {
V_88 = 16 - V_81 -> V_90 . V_91 ;
V_89 = ( T_5 ) ( V_89 << V_88 ) >> V_88 ;
}
* V_4 = V_89 ;
F_6 ( & V_2 -> V_34 ) ;
return V_93 ;
case ( 1 << V_94 ) :
case ( 1 << V_95 ) :
switch ( V_81 -> type ) {
case V_96 :
* V_4 = 0 ;
* V_82 = V_7 -> V_72 -> V_97 ;
return V_98 ;
case V_99 :
* V_4 = 0 ;
if ( V_81 -> V_100 == 0 )
* V_82 = 2418 ;
else
* V_82 = 806 ;
return V_98 ;
case V_101 :
* V_4 = 0 ;
* V_82 = V_7 -> V_72 -> V_102 ;
return V_98 ;
case V_103 :
* V_4 = 0 ;
* V_82 = 500 ;
return V_98 ;
case V_104 :
* V_4 = 0 ;
* V_82 = 140000 ;
return V_98 ;
default:
return - V_87 ;
}
case ( 1 << V_84 ) :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_11 ( V_2 ,
V_85 [ V_81 -> V_86 ] [ 1 ] ,
& V_89 ) ;
F_6 ( & V_2 -> V_34 ) ;
if ( V_5 )
return V_5 ;
V_89 = ( ( V_89 & 0xFFF ) << 4 ) >> 4 ;
* V_4 = V_89 ;
return V_93 ;
case ( 1 << V_105 ) :
* V_4 = 198 ;
* V_82 = 160000 ;
return V_98 ;
default:
return - V_87 ;
}
}
static int T_6 F_32 ( struct V_106 * V_107 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 = F_33 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_108 ;
goto V_24;
}
V_7 = F_2 ( V_2 ) ;
F_34 ( V_107 , V_2 ) ;
V_7 -> V_10 = V_107 ;
F_35 ( & V_7 -> V_8 ) ;
V_7 -> V_72 = & V_109 [ F_36 ( V_107 ) -> V_110 ] ;
V_2 -> V_23 . V_111 = & V_107 -> V_23 ;
V_2 -> V_77 = F_36 ( V_107 ) -> V_77 ;
V_2 -> V_112 = V_7 -> V_72 -> V_112 ;
V_2 -> V_113 = V_7 -> V_72 -> V_113 ;
V_2 -> V_114 = & V_115 ;
V_2 -> V_116 = V_117 ;
V_5 = F_37 ( V_2 ) ;
if ( V_5 )
goto V_118;
V_5 = F_38 ( V_2 ,
V_7 -> V_72 -> V_112 ,
V_7 -> V_72 -> V_113 ) ;
if ( V_5 ) {
F_13 ( & V_107 -> V_23 , L_28 ) ;
goto V_119;
}
if ( V_107 -> V_79 ) {
V_5 = F_39 ( V_2 ) ;
if ( V_5 )
goto V_120;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
goto V_121;
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
goto V_121;
return 0 ;
V_121:
if ( V_2 -> V_116 & V_122 )
F_41 ( V_2 ) ;
V_120:
F_42 ( V_2 ) ;
V_119:
F_43 ( V_2 ) ;
V_118:
F_44 ( V_2 ) ;
V_24:
return V_5 ;
}
static int F_45 ( struct V_106 * V_107 )
{
int V_5 ;
struct V_1 * V_2 = F_46 ( V_107 ) ;
F_47 ( V_2 ) ;
V_5 = F_22 ( V_2 ) ;
if ( V_5 )
goto V_65;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
return 0 ;
V_65:
return V_5 ;
}
static T_7 int F_48 ( void )
{
return F_49 ( & V_123 ) ;
}
static T_8 void F_50 ( void )
{
F_51 ( & V_123 ) ;
}
