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
static int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_25 ;
V_5 = F_11 ( V_2 , V_26 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_25 >>= V_27 ;
return ( 8192 >> V_25 ) / 10 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_28 )
{
unsigned int V_25 ;
V_25 = F_16 ( 8192 / ( V_28 * 10 ) ) ;
if ( V_25 > 0x31 )
V_25 = 0x31 ;
V_25 <<= V_27 ;
V_25 |= V_29 ;
return F_7 ( V_2 , V_26 , V_25 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_30 , V_5 ;
T_2 V_25 ;
V_5 = F_11 ( V_2 , V_26 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_30 = ( V_25 & V_31 ) ? 53 : 1638 ;
V_30 /= ( V_25 & V_32 ) + 1 ;
return V_30 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_28 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_25 ;
V_25 = 1638 / V_28 ;
if ( V_25 > 0 )
V_25 -- ;
V_25 &= V_32 ;
if ( ( V_25 & V_32 ) >= 0x0A )
V_7 -> V_10 -> V_33 = V_34 ;
else
V_7 -> V_10 -> V_33 = V_35 ;
return F_1 ( V_2 ,
V_26 , V_25 ) ;
}
static T_3 F_19 ( struct V_36 * V_23 ,
struct V_37 * V_38 ,
char * V_39 )
{
struct V_1 * V_2 = F_20 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_19 = 0 ;
V_5 = V_7 -> V_40 -> V_41 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_19 = sprintf ( V_39 , L_2 , V_5 ) ;
return V_19 ;
}
static int F_21 ( struct V_1 * V_2 , int V_30 , int V_4 )
{
int V_42 , V_5 ;
T_2 V_43 ;
for ( V_42 = F_22 ( V_44 ) - 1 ; V_42 >= 0 ; V_42 -- )
if ( V_30 / V_44 [ V_42 ] > V_4 )
break;
if ( V_42 == - 1 )
V_5 = - V_45 ;
else {
V_5 = F_11 ( V_2 ,
V_46 ,
& V_43 ) ;
if ( V_5 < 0 )
goto V_24;
V_5 = F_7 ( V_2 ,
V_46 ,
( V_43 & ~ 0x03 ) | V_42 ) ;
}
V_24:
return V_5 ;
}
static T_3 F_23 ( struct V_36 * V_23 ,
struct V_37 * V_38 ,
const char * V_39 ,
T_4 V_19 )
{
struct V_1 * V_2 = F_20 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
long V_4 ;
int V_5 ;
V_5 = F_24 ( V_39 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( V_4 == 0 )
return - V_45 ;
F_3 ( & V_2 -> V_47 ) ;
V_7 -> V_40 -> V_48 ( V_2 , V_4 ) ;
F_6 ( & V_2 -> V_47 ) ;
return V_5 ? V_5 : V_19 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_49 ,
V_50 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 , L_3 ) ;
return V_5 ;
}
int F_26 ( struct V_1 * V_2 , bool V_51 )
{
int V_5 ;
T_2 V_52 ;
V_5 = F_11 ( V_2 , V_53 , & V_52 ) ;
if ( V_5 )
goto V_24;
V_52 |= V_54 ;
if ( V_51 )
V_52 |= V_55 ;
else
V_52 &= ~ V_55 ;
V_5 = F_7 ( V_2 , V_53 , V_52 ) ;
if ( V_5 )
goto V_24;
V_24:
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 = V_56 ;
V_5 = F_7 ( V_2 , V_57 , V_4 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 ,
L_4 ) ;
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_2 V_58 ;
int V_5 ;
struct V_36 * V_23 = & V_2 -> V_23 ;
V_5 = F_11 ( V_2 ,
V_59 , & V_58 ) ;
if ( V_5 < 0 ) {
F_13 ( V_23 , L_5 ) ;
goto V_24;
}
V_5 = V_58 ;
if ( V_58 & V_60 )
F_13 ( V_23 , L_6 ) ;
if ( V_58 & V_61 )
F_13 ( V_23 , L_7 ) ;
if ( V_58 & V_62 )
F_13 ( V_23 , L_8 ) ;
if ( V_58 & V_63 )
F_13 ( V_23 , L_9 ) ;
if ( V_58 & V_64 )
F_13 ( V_23 , L_10 ) ;
if ( V_58 & V_65 )
F_13 ( V_23 , L_11 ) ;
if ( V_58 & V_66 )
F_13 ( V_23 , L_12 ) ;
if ( V_58 & V_67 )
F_13 ( V_23 , L_13 ) ;
if ( V_58 & V_68 )
F_13 ( V_23 , L_14 ) ;
if ( V_58 & V_69 )
F_13 ( V_23 , L_15 ) ;
if ( V_58 & V_70 )
F_13 ( V_23 , L_16 ) ;
if ( V_58 & V_71 )
F_13 ( V_23 , L_17 ) ;
if ( V_58 & V_72 )
F_13 ( V_23 , L_18 ) ;
if ( V_58 & V_73 )
F_13 ( V_23 , L_19 ) ;
if ( V_58 & V_74 )
F_13 ( V_23 , L_20 ) ;
V_24:
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_53 ,
V_75 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_21 ) ;
goto V_76;
}
F_30 ( V_77 ) ;
F_28 ( V_2 ) ;
V_76:
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_78 , V_79 ;
unsigned int V_80 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( V_7 -> V_40 -> V_81 & V_82 )
V_7 -> V_10 -> V_33 = V_34 ;
else
V_7 -> V_10 -> V_33 = V_35 ;
V_7 -> V_10 -> V_83 = V_84 ;
F_32 ( V_7 -> V_10 ) ;
V_5 = F_26 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_22 ) ;
goto V_76;
}
V_5 = F_29 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_23 ) ;
goto V_76;
}
V_5 = F_28 ( V_2 ) ;
if ( V_5 ) {
F_25 ( V_2 ) ;
F_13 ( & V_2 -> V_23 , L_24 ) ;
F_30 ( V_85 ) ;
V_5 = F_28 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_25 ) ;
goto V_76;
}
}
if ( V_7 -> V_40 -> V_81 & V_86 ) {
V_5 = F_11 ( V_2 ,
V_87 , & V_78 ) ;
if ( V_5 )
goto V_76;
sscanf ( V_2 -> V_88 , L_26 , & V_80 ) ;
if ( V_78 != V_80 )
F_33 ( & V_2 -> V_23 , L_27 ,
V_80 , V_78 ) ;
F_34 ( & V_2 -> V_23 , L_28 ,
V_2 -> V_88 , V_78 ,
V_7 -> V_10 -> V_89 , V_7 -> V_10 -> V_90 ) ;
}
if ( V_7 -> V_40 -> V_81 & V_82 ) {
V_5 = F_11 ( V_2 ,
V_26 , & V_79 ) ;
if ( V_5 )
goto V_76;
if ( ( V_79 & V_32 ) < 0x0A ) {
V_7 -> V_10 -> V_33 = V_35 ;
F_32 ( V_7 -> V_10 ) ;
}
}
V_76:
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_91 const * V_92 ,
int V_4 ,
int V_93 ,
long V_94 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_30 ;
switch ( V_94 ) {
case V_95 :
F_3 ( & V_2 -> V_47 ) ;
V_5 = F_7 ( V_2 ,
V_96 [ V_92 -> V_97 ] [ 1 ] ,
V_4 ) ;
F_6 ( & V_2 -> V_47 ) ;
return V_5 ;
case V_98 :
F_3 ( & V_2 -> V_47 ) ;
V_7 -> V_99 = V_4 ;
V_30 = V_7 -> V_40 -> V_41 ( V_2 ) ;
if ( V_30 < 0 ) {
F_6 ( & V_2 -> V_47 ) ;
return V_30 ;
}
V_5 = F_21 ( V_2 , V_30 , V_4 ) ;
F_6 ( & V_2 -> V_47 ) ;
return V_5 ;
default:
return - V_45 ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_91 const * V_92 ,
int * V_4 ,
int * V_93 ,
long V_94 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_100 ;
T_5 V_43 ;
switch ( V_94 ) {
case V_101 :
F_3 ( & V_2 -> V_47 ) ;
V_5 = F_11 ( V_2 ,
V_96 [ V_92 -> V_97 ] [ 0 ] ,
& V_43 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_47 ) ;
return V_5 ;
}
V_43 &= ( 1 << V_92 -> V_102 . V_103 ) - 1 ;
if ( V_92 -> V_102 . V_104 == 's' ) {
V_100 = 16 - V_92 -> V_102 . V_103 ;
V_43 = ( T_5 ) ( V_43 << V_100 ) >> V_100 ;
}
* V_4 = V_43 ;
F_6 ( & V_2 -> V_47 ) ;
return V_105 ;
case V_106 :
switch ( V_92 -> type ) {
case V_107 :
* V_4 = 0 ;
* V_93 = V_7 -> V_40 -> V_108 ;
return V_109 ;
case V_110 :
* V_4 = 0 ;
if ( V_92 -> V_111 == 0 ) {
* V_4 = 2 ;
* V_93 = 418000 ;
} else {
* V_4 = 0 ;
* V_93 = 805800 ;
}
return V_109 ;
case V_112 :
* V_4 = 0 ;
* V_93 = V_7 -> V_40 -> V_113 ;
return V_109 ;
case V_114 :
* V_4 = 0 ;
* V_93 = 500 ;
return V_109 ;
case V_115 :
* V_4 = V_7 -> V_40 -> V_116 / 1000000 ;
* V_93 = ( V_7 -> V_40 -> V_116 % 1000000 ) ;
return V_109 ;
default:
return - V_45 ;
}
case V_95 :
F_3 ( & V_2 -> V_47 ) ;
V_5 = F_11 ( V_2 ,
V_96 [ V_92 -> V_97 ] [ 1 ] ,
& V_43 ) ;
F_6 ( & V_2 -> V_47 ) ;
if ( V_5 )
return V_5 ;
V_43 = ( ( V_43 & 0xFFF ) << 4 ) >> 4 ;
* V_4 = V_43 ;
return V_105 ;
case V_117 :
* V_4 = V_7 -> V_40 -> V_118 ;
return V_105 ;
case V_98 :
F_3 ( & V_2 -> V_47 ) ;
V_5 = F_11 ( V_2 ,
V_46 ,
& V_43 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_2 -> V_47 ) ;
return V_5 ;
}
V_43 = V_7 -> V_40 -> V_41 ( V_2 ) ;
if ( V_5 > 0 )
* V_4 = V_5 / V_44 [ V_43 & 0x03 ] ;
* V_93 = 0 ;
F_6 ( & V_2 -> V_47 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_109 ;
default:
return - V_45 ;
}
}
static int F_37 ( struct V_119 * V_120 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 = F_38 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_121 ;
goto V_24;
}
V_7 = F_2 ( V_2 ) ;
F_39 ( V_120 , V_2 ) ;
V_7 -> V_10 = V_120 ;
F_40 ( & V_7 -> V_8 ) ;
V_7 -> V_40 = & V_122 [ F_41 ( V_120 ) -> V_123 ] ;
V_2 -> V_23 . V_124 = & V_120 -> V_23 ;
V_2 -> V_88 = F_41 ( V_120 ) -> V_88 ;
V_2 -> V_125 = V_7 -> V_40 -> V_125 ;
V_2 -> V_126 = V_7 -> V_40 -> V_126 ;
V_2 -> V_127 = & V_128 ;
V_2 -> V_129 = V_130 ;
V_5 = F_42 ( V_2 ) ;
if ( V_5 )
goto V_131;
V_5 = F_43 ( V_2 ,
V_7 -> V_40 -> V_125 ,
V_7 -> V_40 -> V_126 ) ;
if ( V_5 ) {
F_13 ( & V_120 -> V_23 , L_29 ) ;
goto V_132;
}
if ( V_120 -> V_90 ) {
V_5 = F_44 ( V_2 ) ;
if ( V_5 )
goto V_133;
}
V_5 = F_31 ( V_2 ) ;
if ( V_5 )
goto V_134;
V_5 = F_45 ( V_2 ) ;
if ( V_5 )
goto V_134;
return 0 ;
V_134:
if ( V_120 -> V_90 )
F_46 ( V_2 ) ;
V_133:
F_47 ( V_2 ) ;
V_132:
F_48 ( V_2 ) ;
V_131:
F_49 ( V_2 ) ;
V_24:
return V_5 ;
}
static int F_50 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = F_51 ( V_120 ) ;
F_52 ( V_2 ) ;
F_27 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
