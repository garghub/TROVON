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
T_2 V_25 ;
int V_26 , V_5 ;
V_5 = F_11 ( V_2 , V_27 , & V_25 ) ;
if ( V_5 < 0 )
return V_5 ;
V_26 = ( V_25 & V_28 ) ? 53 : 1638 ;
V_26 /= ( V_25 & V_29 ) + 1 ;
return V_26 ;
}
static T_3 F_15 ( struct V_30 * V_23 ,
struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
int V_5 , V_19 = 0 ;
V_5 = F_14 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_19 = sprintf ( V_33 , L_2 , V_5 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_2 , int V_26 , int V_4 )
{
int V_34 , V_5 ;
T_2 V_35 ;
for ( V_34 = F_18 ( V_36 ) - 1 ; V_34 >= 0 ; V_34 -- )
if ( V_26 / V_36 [ V_34 ] > V_4 )
break;
if ( V_34 == - 1 )
V_5 = - V_37 ;
else {
V_5 = F_11 ( V_2 ,
V_38 ,
& V_35 ) ;
if ( V_5 < 0 )
goto V_24;
V_5 = F_7 ( V_2 ,
V_38 ,
( V_35 & ~ 0x03 ) | V_34 ) ;
}
V_24:
return V_5 ;
}
static T_3 F_19 ( struct V_30 * V_23 ,
struct V_31 * V_32 ,
const char * V_33 ,
T_4 V_19 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
long V_4 ;
int V_5 ;
T_1 V_25 ;
V_5 = F_20 ( V_33 , 10 , & V_4 ) ;
if ( V_5 )
return V_5 ;
F_3 ( & V_2 -> V_39 ) ;
V_25 = ( 1638 / V_4 ) ;
if ( V_25 > 0 )
V_25 -- ;
V_25 &= V_29 ;
if ( ( V_25 & V_29 ) >= 0x0A )
V_7 -> V_10 -> V_40 = V_41 ;
else
V_7 -> V_10 -> V_40 = V_42 ;
V_5 = F_1 ( V_2 ,
V_27 ,
V_25 ) ;
F_6 ( & V_2 -> V_39 ) ;
return V_5 ? V_5 : V_19 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ,
V_43 ,
V_44 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 , L_3 ) ;
return V_5 ;
}
static T_3 F_22 ( struct V_30 * V_23 ,
struct V_31 * V_32 ,
const char * V_33 , T_4 V_19 )
{
bool V_4 ;
int V_5 ;
V_5 = F_23 ( V_33 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_4 ) {
V_5 = F_21 ( F_16 ( V_23 ) ) ;
if ( V_5 < 0 )
return V_5 ;
}
return V_19 ;
}
int F_24 ( struct V_1 * V_2 , bool V_45 )
{
int V_5 ;
T_2 V_46 ;
V_5 = F_11 ( V_2 , V_47 , & V_46 ) ;
if ( V_5 )
goto V_24;
V_46 |= V_48 ;
if ( V_45 )
V_46 |= V_49 ;
else
V_46 &= ~ V_49 ;
V_5 = F_7 ( V_2 , V_47 , V_46 ) ;
if ( V_5 )
goto V_24;
V_24:
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_4 = V_50 ;
V_5 = F_7 ( V_2 , V_51 , V_4 ) ;
if ( V_5 )
F_13 ( & V_2 -> V_23 ,
L_4 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_2 V_52 ;
int V_5 ;
struct V_30 * V_23 = & V_2 -> V_23 ;
V_5 = F_11 ( V_2 ,
V_53 , & V_52 ) ;
if ( V_5 < 0 ) {
F_13 ( V_23 , L_5 ) ;
goto V_24;
}
V_5 = V_52 ;
if ( V_52 & V_54 )
F_13 ( V_23 , L_6 ) ;
if ( V_52 & V_55 )
F_13 ( V_23 , L_7 ) ;
if ( V_52 & V_56 )
F_13 ( V_23 , L_8 ) ;
if ( V_52 & V_57 )
F_13 ( V_23 , L_9 ) ;
if ( V_52 & V_58 )
F_13 ( V_23 , L_10 ) ;
if ( V_52 & V_59 )
F_13 ( V_23 , L_11 ) ;
if ( V_52 & V_60 )
F_13 ( V_23 , L_12 ) ;
if ( V_52 & V_61 )
F_13 ( V_23 , L_13 ) ;
if ( V_52 & V_62 )
F_13 ( V_23 , L_14 ) ;
if ( V_52 & V_63 )
F_13 ( V_23 , L_15 ) ;
if ( V_52 & V_64 )
F_13 ( V_23 , L_16 ) ;
if ( V_52 & V_65 )
F_13 ( V_23 , L_17 ) ;
if ( V_52 & V_66 )
F_13 ( V_23 , L_18 ) ;
if ( V_52 & V_67 )
F_13 ( V_23 , L_19 ) ;
if ( V_52 & V_68 )
F_13 ( V_23 , L_20 ) ;
V_24:
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_7 ( V_2 ,
V_47 ,
V_69 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_21 ) ;
goto V_70;
}
F_28 ( V_71 ) ;
F_26 ( V_2 ) ;
V_70:
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_72 , V_73 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_10 -> V_40 = V_41 ;
V_7 -> V_10 -> V_74 = V_75 ;
F_30 ( V_7 -> V_10 ) ;
V_5 = F_24 ( V_2 , false ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_22 ) ;
goto V_70;
}
V_5 = F_27 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_23 ) ;
goto V_70;
}
V_5 = F_26 ( V_2 ) ;
if ( V_5 ) {
F_21 ( V_2 ) ;
F_13 ( & V_2 -> V_23 , L_24 ) ;
F_28 ( V_76 ) ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 ) {
F_13 ( & V_2 -> V_23 , L_25 ) ;
goto V_70;
}
}
if ( V_7 -> V_77 -> V_78 & V_79 ) {
V_5 = F_11 ( V_2 ,
V_80 , & V_72 ) ;
if ( V_5 )
goto V_70;
if ( ( V_72 & 0xF000 ) != V_7 -> V_77 -> V_81 )
F_31 ( & V_2 -> V_23 , L_26 ) ;
F_32 ( & V_2 -> V_23 , L_27 ,
V_2 -> V_82 , V_72 ,
V_7 -> V_10 -> V_83 , V_7 -> V_10 -> V_84 ) ;
}
V_5 = F_11 ( V_2 ,
V_27 , & V_73 ) ;
if ( ! V_5 && ( V_73 & V_29 ) < 0x0A ) {
V_7 -> V_10 -> V_40 = V_41 ;
F_30 ( V_7 -> V_10 ) ;
}
V_70:
return V_5 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_85 const * V_86 ,
int V_4 ,
int V_87 ,
long V_88 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_26 ;
switch ( V_88 ) {
case V_89 :
F_3 ( & V_2 -> V_39 ) ;
V_5 = F_7 ( V_2 ,
V_90 [ V_86 -> V_91 ] [ 1 ] ,
V_4 ) ;
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
case V_92 :
F_3 ( & V_2 -> V_39 ) ;
V_7 -> V_93 = V_4 ;
V_26 = F_14 ( V_2 ) ;
if ( V_26 < 0 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_26 ;
}
V_5 = F_17 ( V_2 , V_26 , V_4 ) ;
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
default:
return - V_37 ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_85 const * V_86 ,
int * V_4 ,
int * V_87 ,
long V_88 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_5 , V_94 ;
T_5 V_35 ;
switch ( V_88 ) {
case 0 :
F_3 ( & V_2 -> V_39 ) ;
V_5 = F_11 ( V_2 ,
V_90 [ V_86 -> V_91 ] [ 0 ] ,
& V_35 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
V_35 &= ( 1 << V_86 -> V_95 . V_96 ) - 1 ;
if ( V_86 -> V_95 . V_97 == 's' ) {
V_94 = 16 - V_86 -> V_95 . V_96 ;
V_35 = ( T_5 ) ( V_35 << V_94 ) >> V_94 ;
}
* V_4 = V_35 ;
F_6 ( & V_2 -> V_39 ) ;
return V_98 ;
case V_99 :
switch ( V_86 -> type ) {
case V_100 :
* V_4 = 0 ;
* V_87 = V_7 -> V_77 -> V_101 ;
return V_102 ;
case V_103 :
* V_4 = 0 ;
if ( V_86 -> V_104 == 0 )
* V_87 = 2418 ;
else
* V_87 = 806 ;
return V_102 ;
case V_105 :
* V_4 = 0 ;
* V_87 = V_7 -> V_77 -> V_106 ;
return V_102 ;
case V_107 :
* V_4 = 0 ;
* V_87 = 500 ;
return V_102 ;
case V_108 :
* V_4 = 0 ;
* V_87 = 140000 ;
return V_102 ;
default:
return - V_37 ;
}
case V_89 :
F_3 ( & V_2 -> V_39 ) ;
V_5 = F_11 ( V_2 ,
V_90 [ V_86 -> V_91 ] [ 1 ] ,
& V_35 ) ;
F_6 ( & V_2 -> V_39 ) ;
if ( V_5 )
return V_5 ;
V_35 = ( ( V_35 & 0xFFF ) << 4 ) >> 4 ;
* V_4 = V_35 ;
return V_98 ;
case V_109 :
* V_4 = 198 ;
* V_87 = 160000 ;
return V_102 ;
case V_92 :
F_3 ( & V_2 -> V_39 ) ;
V_5 = F_11 ( V_2 ,
V_38 ,
& V_35 ) ;
if ( V_5 < 0 ) {
F_6 ( & V_2 -> V_39 ) ;
return V_5 ;
}
V_5 = F_14 ( V_2 ) ;
if ( V_5 > 0 )
* V_4 = V_5 / V_36 [ V_35 & 0x03 ] ;
* V_87 = 0 ;
F_6 ( & V_2 -> V_39 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_102 ;
default:
return - V_37 ;
}
}
static int T_6 F_35 ( struct V_110 * V_111 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_1 * V_2 = F_36 ( sizeof( * V_7 ) ) ;
if ( V_2 == NULL ) {
V_5 = - V_112 ;
goto V_24;
}
V_7 = F_2 ( V_2 ) ;
F_37 ( V_111 , V_2 ) ;
V_7 -> V_10 = V_111 ;
F_38 ( & V_7 -> V_8 ) ;
V_7 -> V_77 = & V_113 [ F_39 ( V_111 ) -> V_114 ] ;
V_2 -> V_23 . V_115 = & V_111 -> V_23 ;
V_2 -> V_82 = F_39 ( V_111 ) -> V_82 ;
V_2 -> V_116 = V_7 -> V_77 -> V_116 ;
V_2 -> V_117 = V_7 -> V_77 -> V_117 ;
V_2 -> V_118 = & V_119 ;
V_2 -> V_120 = V_121 ;
V_5 = F_40 ( V_2 ) ;
if ( V_5 )
goto V_122;
V_5 = F_41 ( V_2 ,
V_7 -> V_77 -> V_116 ,
V_7 -> V_77 -> V_117 ) ;
if ( V_5 ) {
F_13 ( & V_111 -> V_23 , L_28 ) ;
goto V_123;
}
if ( V_111 -> V_84 ) {
V_5 = F_42 ( V_2 ) ;
if ( V_5 )
goto V_124;
}
V_5 = F_29 ( V_2 ) ;
if ( V_5 )
goto V_125;
V_5 = F_43 ( V_2 ) ;
if ( V_5 )
goto V_125;
return 0 ;
V_125:
if ( V_2 -> V_120 & V_126 )
F_44 ( V_2 ) ;
V_124:
F_45 ( V_2 ) ;
V_123:
F_46 ( V_2 ) ;
V_122:
F_47 ( V_2 ) ;
V_24:
return V_5 ;
}
static int F_48 ( struct V_110 * V_111 )
{
int V_5 ;
struct V_1 * V_2 = F_49 ( V_111 ) ;
F_50 ( V_2 ) ;
V_5 = F_25 ( V_2 ) ;
if ( V_5 )
goto V_70;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
V_70:
return V_5 ;
}
