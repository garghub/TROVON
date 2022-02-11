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
V_7 -> V_9 [ 2 ] = 0 ;
V_7 -> V_9 [ 3 ] = 0 ;
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
struct V_1 * V_2 = F_15 ( V_23 ) ;
if ( V_19 < 1 )
return - 1 ;
switch ( V_28 [ 0 ] ) {
case '1' :
case 'y' :
case 'Y' :
return F_18 ( V_2 ) ;
}
return - 1 ;
}
int F_20 ( struct V_1 * V_2 , bool V_40 )
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
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 = V_45 ;
V_5 = F_7 ( V_2 , V_46 , V_4 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 ,
L_4 ) ;
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_42 ,
V_47 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_5 ) ;
goto V_48;
}
F_23 ( V_49 ) ;
F_24 ( V_2 ) ;
V_48:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_50 ;
int V_5 ;
struct V_25 * V_23 = & V_2 -> V_23 ;
V_5 = F_11 ( V_2 ,
V_51 , & V_50 ) ;
if ( V_5 < 0 ) {
F_13 ( V_23 , L_6 ) ;
goto V_24;
}
V_5 = V_50 ;
if ( V_50 & V_52 )
F_13 ( V_23 , L_7 ) ;
if ( V_50 & V_53 )
F_13 ( V_23 , L_8 ) ;
if ( V_50 & V_54 )
F_13 ( V_23 , L_9 ) ;
if ( V_50 & V_55 )
F_13 ( V_23 , L_10 ) ;
if ( V_50 & V_56 )
F_13 ( V_23 , L_11 ) ;
if ( V_50 & V_57 )
F_13 ( V_23 , L_12 ) ;
if ( V_50 & V_58 )
F_13 ( V_23 , L_13 ) ;
if ( V_50 & V_59 )
F_13 ( V_23 , L_14 ) ;
if ( V_50 & V_60 )
F_13 ( V_23 , L_15 ) ;
if ( V_50 & V_61 )
F_13 ( V_23 , L_16 ) ;
if ( V_50 & V_62 )
F_13 ( V_23 , L_17 ) ;
if ( V_50 & V_63 )
F_13 ( V_23 , L_18 ) ;
if ( V_50 & V_64 )
F_13 ( V_23 , L_19 ) ;
if ( V_50 & V_65 )
F_13 ( V_23 , L_20 ) ;
if ( V_50 & V_66 )
F_13 ( V_23 , L_21 ) ;
V_24:
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_67 , V_68 ;
struct V_25 * V_23 = & V_2 -> V_23 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_10 -> V_35 = V_36 ;
V_7 -> V_10 -> V_69 = V_70 ;
F_26 ( V_7 -> V_10 ) ;
V_5 = F_20 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( V_23 , L_22 ) ;
goto V_48;
}
V_5 = F_22 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_23 , L_23 ) ;
goto V_48;
}
V_5 = F_24 ( V_2 ) ;
if ( V_5 ) {
F_18 ( V_2 ) ;
F_13 ( V_23 , L_24 ) ;
F_23 ( V_71 ) ;
V_5 = F_24 ( V_2 ) ;
if ( V_5 ) {
F_13 ( V_23 , L_25 ) ;
goto V_48;
}
}
if ( V_7 -> V_72 -> V_73 & V_74 ) {
V_5 = F_11 ( V_2 ,
V_75 , & V_67 ) ;
if ( V_5 )
goto V_48;
if ( ( V_67 & 0xF000 ) != V_7 -> V_72 -> V_76 )
F_27 ( V_23 , L_26 ) ;
F_28 (KERN_INFO DRIVER_NAME L_27 ,
prod_id, st->us->chip_select, st->us->irq) ;
}
V_5 = F_11 ( V_2 ,
V_31 , & V_68 ) ;
if ( ! V_5 && ( V_68 & V_33 ) < 0x0A ) {
V_7 -> V_10 -> V_35 = V_36 ;
F_26 ( V_7 -> V_10 ) ;
}
V_48:
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_77 const * V_78 ,
int V_4 ,
int V_79 ,
long V_80 )
{
int V_5 ;
switch ( V_80 ) {
case ( 1 << V_81 ) :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_7 ( V_2 ,
V_82 [ V_78 -> V_83 ] [ 1 ] ,
V_4 ) ;
F_6 ( & V_2 -> V_34 ) ;
return V_5 ;
default:
return - V_84 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
struct V_77 const * V_78 ,
int * V_4 ,
int * V_79 ,
long V_80 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 ;
T_5 V_85 ;
int V_86 ;
switch ( V_80 ) {
case 0 :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_11 ( V_2 ,
V_82 [ V_78 -> V_83 ] [ 0 ] ,
& V_85 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_34 ) ;
return V_5 ;
}
V_85 &= ( 1 << V_78 -> V_87 . V_88 ) - 1 ;
if ( V_78 -> V_87 . V_89 == 's' ) {
V_86 = 16 - V_78 -> V_87 . V_88 ;
V_85 = ( T_5 ) ( V_85 << V_86 ) >> V_86 ;
}
* V_4 = V_85 ;
F_6 ( & V_2 -> V_34 ) ;
return V_90 ;
case ( 1 << V_91 ) :
case ( 1 << V_92 ) :
switch ( V_78 -> type ) {
case V_93 :
* V_4 = 0 ;
* V_79 = V_7 -> V_72 -> V_94 ;
return V_95 ;
case V_96 :
* V_4 = 0 ;
if ( V_78 -> V_97 == 0 )
* V_79 = 2418 ;
else
* V_79 = 806 ;
return V_95 ;
case V_98 :
* V_4 = 0 ;
* V_79 = V_7 -> V_72 -> V_99 ;
return V_95 ;
case V_100 :
* V_4 = 0 ;
* V_79 = 500 ;
return V_95 ;
case V_101 :
* V_4 = 0 ;
* V_79 = 140000 ;
return V_95 ;
default:
return - V_84 ;
}
case ( 1 << V_81 ) :
F_3 ( & V_2 -> V_34 ) ;
V_5 = F_11 ( V_2 ,
V_82 [ V_78 -> V_83 ] [ 1 ] ,
& V_85 ) ;
F_6 ( & V_2 -> V_34 ) ;
if ( V_5 )
return V_5 ;
V_85 = ( ( V_85 & 0xFFF ) << 4 ) >> 4 ;
* V_4 = V_85 ;
return V_90 ;
case ( 1 << V_102 ) :
* V_4 = 198 ;
* V_79 = 160000 ;
return V_95 ;
default:
return - V_84 ;
}
}
static int T_6 F_31 ( struct V_103 * V_104 )
{
int V_5 , V_105 = 0 ;
struct V_6 * V_7 ;
struct V_1 * V_2 = F_32 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_106 ;
goto V_24;
}
V_7 = F_2 ( V_2 ) ;
F_33 ( V_104 , V_2 ) ;
V_7 -> V_10 = V_104 ;
F_34 ( & V_7 -> V_8 ) ;
V_7 -> V_72 = & V_107 [ F_35 ( V_104 ) -> V_108 ] ;
V_2 -> V_23 . V_109 = & V_104 -> V_23 ;
V_2 -> V_110 = F_35 ( V_104 ) -> V_110 ;
V_2 -> V_111 = V_7 -> V_72 -> V_111 ;
V_2 -> V_112 = V_7 -> V_72 -> V_112 ;
V_2 -> V_113 = & V_114 ;
V_2 -> V_115 = V_116 ;
V_5 = F_36 ( V_2 ) ;
if ( V_5 )
goto V_117;
V_5 = F_37 ( V_2 ) ;
if ( V_5 )
goto V_118;
V_105 = 1 ;
V_5 = F_38 ( V_2 -> V_119 , 0 ,
V_7 -> V_72 -> V_111 ,
V_7 -> V_72 -> V_112 ) ;
if ( V_5 ) {
F_13 ( & V_104 -> V_23 , L_28 ) ;
goto V_118;
}
if ( V_104 -> V_120 && F_39 ( F_40 ( V_104 -> V_120 ) ) > 0 ) {
V_5 = F_41 ( V_2 ) ;
if ( V_5 )
goto V_121;
}
V_5 = F_25 ( V_2 ) ;
if ( V_5 )
goto V_122;
return 0 ;
V_122:
if ( V_2 -> V_115 & V_123 )
F_42 ( V_2 ) ;
V_121:
F_43 ( V_2 -> V_119 ) ;
V_118:
F_44 ( V_2 ) ;
V_117:
if ( V_105 )
F_45 ( V_2 ) ;
else
F_46 ( V_2 ) ;
V_24:
return V_5 ;
}
static int F_47 ( struct V_103 * V_104 )
{
int V_5 ;
struct V_1 * V_2 = F_48 ( V_104 ) ;
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
goto V_48;
F_42 ( V_2 ) ;
F_43 ( V_2 -> V_119 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
return 0 ;
V_48:
return V_5 ;
}
static T_7 int F_49 ( void )
{
return F_50 ( & V_124 ) ;
}
static T_8 void F_51 ( void )
{
F_52 ( & V_124 ) ;
}
