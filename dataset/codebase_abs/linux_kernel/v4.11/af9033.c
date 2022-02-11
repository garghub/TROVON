static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
#define F_2 212
int V_8 , V_9 , V_10 ;
T_1 V_11 [ 1 + F_2 ] ;
F_3 ( & V_7 -> V_2 , L_1 , V_5 ) ;
if ( V_5 > sizeof( V_11 ) ) {
F_4 ( & V_7 -> V_2 , L_2 , V_5 ) ;
return - V_12 ;
}
for ( V_9 = 0 , V_10 = 0 ; V_9 < V_5 ; V_9 ++ ) {
V_11 [ V_10 ] = V_4 [ V_9 ] . V_13 ;
if ( V_9 == V_5 - 1 || V_4 [ V_9 ] . V_14 != V_4 [ V_9 + 1 ] . V_14 - 1 ) {
V_8 = F_5 ( V_2 -> V_15 , V_4 [ V_9 ] . V_14 - V_10 ,
V_11 , V_10 + 1 ) ;
if ( V_8 )
goto V_16;
V_10 = 0 ;
} else {
V_10 ++ ;
}
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_20 * V_21 = & V_18 -> V_22 ;
int V_8 , V_9 , V_23 ;
unsigned int V_24 ;
const struct V_3 * V_25 ;
T_1 V_11 [ 4 ] ;
struct V_26 V_4 [] = {
{ 0x80fb24 , 0x00 , 0x08 } ,
{ 0x80004c , 0x00 , 0xff } ,
{ 0x00f641 , V_2 -> V_27 . V_28 , 0xff } ,
{ 0x80f5ca , 0x01 , 0x01 } ,
{ 0x80f715 , 0x01 , 0x01 } ,
{ 0x00f41f , 0x04 , 0x04 } ,
{ 0x00f41a , 0x01 , 0x01 } ,
{ 0x80f731 , 0x00 , 0x01 } ,
{ 0x00d91e , 0x00 , 0x01 } ,
{ 0x00d919 , 0x00 , 0x01 } ,
{ 0x80f732 , 0x00 , 0x01 } ,
{ 0x00d91f , 0x00 , 0x01 } ,
{ 0x00d91a , 0x00 , 0x01 } ,
{ 0x80f730 , 0x00 , 0x01 } ,
{ 0x80f778 , 0x00 , 0xff } ,
{ 0x80f73c , 0x01 , 0x01 } ,
{ 0x80f776 , 0x00 , 0x01 } ,
{ 0x00d8fd , 0x01 , 0xff } ,
{ 0x00d830 , 0x01 , 0xff } ,
{ 0x00d831 , 0x00 , 0xff } ,
{ 0x00d832 , 0x00 , 0xff } ,
{ 0x80f985 , V_2 -> V_29 , 0x01 } ,
{ 0x80f986 , V_2 -> V_30 , 0x01 } ,
{ 0x00d827 , 0x00 , 0xff } ,
{ 0x00d829 , 0x00 , 0xff } ,
{ 0x800045 , V_2 -> V_27 . V_31 , 0xff } ,
} ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
V_24 = F_7 ( ( V_32 ) V_2 -> V_27 . clock * 0x80000 , 1000000 ) ;
V_11 [ 0 ] = ( V_24 >> 0 ) & 0xff ;
V_11 [ 1 ] = ( V_24 >> 8 ) & 0xff ;
V_11 [ 2 ] = ( V_24 >> 16 ) & 0xff ;
V_11 [ 3 ] = ( V_24 >> 24 ) & 0xff ;
V_8 = F_5 ( V_2 -> V_15 , 0x800025 , V_11 , 4 ) ;
if ( V_8 )
goto V_16;
F_3 ( & V_7 -> V_2 , L_5 , V_2 -> V_27 . clock , V_24 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_33 ) ; V_9 ++ ) {
if ( V_33 [ V_9 ] . clock == V_2 -> V_27 . clock )
break;
}
if ( V_9 == F_8 ( V_33 ) ) {
F_9 ( & V_7 -> V_2 , L_6 ,
V_2 -> V_27 . clock ) ;
goto V_16;
}
V_24 = F_7 ( ( V_32 ) V_33 [ V_9 ] . V_34 * 0x80000 , 1000000 ) ;
V_11 [ 0 ] = ( V_24 >> 0 ) & 0xff ;
V_11 [ 1 ] = ( V_24 >> 8 ) & 0xff ;
V_11 [ 2 ] = ( V_24 >> 16 ) & 0xff ;
V_8 = F_5 ( V_2 -> V_15 , 0x80f1cd , V_11 , 3 ) ;
if ( V_8 )
goto V_16;
F_3 ( & V_7 -> V_2 , L_7 ,
V_33 [ V_9 ] . V_34 , V_24 ) ;
for ( V_9 = 0 ; V_9 < F_8 ( V_4 ) ; V_9 ++ ) {
V_8 = F_10 ( V_2 -> V_15 , V_4 [ V_9 ] . V_14 , V_4 [ V_9 ] . V_35 ,
V_4 [ V_9 ] . V_13 ) ;
if ( V_8 )
goto V_16;
}
if ( V_2 -> V_27 . V_36 ) {
V_8 = F_11 ( V_2 -> V_15 , 0x80fba8 , 0x00 ) ;
if ( V_8 )
goto V_16;
}
if ( V_2 -> V_27 . V_37 == V_38 ) {
V_8 = F_10 ( V_2 -> V_15 , 0x80f9a5 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x80f9b5 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_16;
} else {
V_8 = F_10 ( V_2 -> V_15 , 0x80f990 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x80f9b5 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
}
F_3 ( & V_7 -> V_2 , L_8 ) ;
switch ( V_2 -> V_27 . V_28 ) {
case V_39 :
case V_40 :
case V_41 :
V_23 = F_8 ( V_42 ) ;
V_25 = V_42 ;
break;
case V_43 :
case V_44 :
case V_45 :
V_23 = F_8 ( V_46 ) ;
V_25 = V_46 ;
break;
default:
V_23 = F_8 ( V_47 ) ;
V_25 = V_47 ;
break;
}
V_8 = F_1 ( V_2 , V_25 , V_23 ) ;
if ( V_8 )
goto V_16;
F_3 ( & V_7 -> V_2 , L_9 ) ;
switch ( V_2 -> V_27 . V_28 ) {
case V_48 :
V_23 = F_8 ( V_49 ) ;
V_25 = V_49 ;
break;
case V_50 :
V_23 = F_8 ( V_51 ) ;
V_25 = V_51 ;
break;
case V_52 :
V_23 = F_8 ( V_53 ) ;
V_25 = V_53 ;
break;
case V_54 :
V_23 = F_8 ( V_55 ) ;
V_25 = V_55 ;
break;
case V_56 :
V_23 = F_8 ( V_57 ) ;
V_25 = V_57 ;
break;
case V_58 :
V_23 = F_8 ( V_59 ) ;
V_25 = V_59 ;
break;
case V_39 :
V_23 = F_8 ( V_60 ) ;
V_25 = V_60 ;
break;
case V_40 :
V_23 = F_8 ( V_61 ) ;
V_25 = V_61 ;
break;
case V_41 :
V_23 = F_8 ( V_62 ) ;
V_25 = V_62 ;
break;
case V_43 :
V_23 = F_8 ( V_63 ) ;
V_25 = V_63 ;
break;
case V_44 :
V_23 = F_8 ( V_64 ) ;
V_25 = V_64 ;
break;
case V_45 :
V_23 = F_8 ( V_65 ) ;
V_25 = V_65 ;
break;
default:
F_3 ( & V_7 -> V_2 , L_10 ,
V_2 -> V_27 . V_28 ) ;
V_8 = - V_66 ;
goto V_16;
}
V_8 = F_1 ( V_2 , V_25 , V_23 ) ;
if ( V_8 )
goto V_16;
if ( V_2 -> V_27 . V_37 == V_67 ) {
V_8 = F_10 ( V_2 -> V_15 , 0x00d91c , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x00d917 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x00d916 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
}
switch ( V_2 -> V_27 . V_28 ) {
case V_43 :
case V_44 :
case V_45 :
V_8 = F_11 ( V_2 -> V_15 , 0x800000 , 0x01 ) ;
if ( V_8 )
goto V_16;
}
V_2 -> V_68 = 0 ;
V_21 -> V_69 . V_23 = 1 ;
V_21 -> V_69 . V_70 [ 0 ] . V_71 = V_72 ;
V_21 -> V_73 . V_23 = 1 ;
V_21 -> V_73 . V_70 [ 0 ] . V_71 = V_72 ;
V_21 -> V_74 . V_23 = 1 ;
V_21 -> V_74 . V_70 [ 0 ] . V_71 = V_72 ;
V_21 -> V_75 . V_23 = 1 ;
V_21 -> V_75 . V_70 [ 0 ] . V_71 = V_72 ;
V_21 -> V_76 . V_23 = 1 ;
V_21 -> V_76 . V_70 [ 0 ] . V_71 = V_72 ;
V_21 -> V_77 . V_23 = 1 ;
V_21 -> V_77 . V_70 [ 0 ] . V_71 = V_72 ;
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
unsigned int V_24 ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
V_8 = F_11 ( V_2 -> V_15 , 0x80004c , 0x01 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x800000 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_13 ( V_2 -> V_15 , 0x80004c , V_24 , V_24 == 0 ,
5000 , 1000000 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x80fb24 , 0x08 , 0x08 ) ;
if ( V_8 )
goto V_16;
if ( V_2 -> V_27 . V_37 == V_67 ) {
V_8 = F_10 ( V_2 -> V_15 , 0x00d917 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x00d916 , 0x01 , 0x01 ) ;
if ( V_8 )
goto V_16;
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_17 * V_18 ,
struct V_78 * V_79 )
{
V_79 -> V_80 = 2000 ;
V_79 -> V_81 = 0 ;
V_79 -> V_82 = 0 ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_20 * V_21 = & V_18 -> V_22 ;
int V_8 , V_9 ;
unsigned int V_24 , V_83 ;
T_1 V_84 , V_11 [ 3 ] , V_85 ;
T_2 V_86 ;
F_3 ( & V_7 -> V_2 , L_11 ,
V_21 -> V_87 , V_21 -> V_68 ) ;
switch ( V_21 -> V_68 ) {
case 6000000 :
V_85 = 0x00 ;
break;
case 7000000 :
V_85 = 0x01 ;
break;
case 8000000 :
V_85 = 0x02 ;
break;
default:
F_3 ( & V_7 -> V_2 , L_12 ) ;
V_8 = - V_12 ;
goto V_16;
}
if ( V_18 -> V_88 . V_89 . V_90 )
V_18 -> V_88 . V_89 . V_90 ( V_18 ) ;
if ( V_21 -> V_68 != V_2 -> V_68 ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_91 ) ; V_9 ++ ) {
if ( V_91 [ V_9 ] . clock == V_2 -> V_27 . clock &&
V_91 [ V_9 ] . V_68 == V_21 -> V_68 ) {
break;
}
}
if ( V_9 == F_8 ( V_91 ) ) {
F_9 ( & V_7 -> V_2 ,
L_13 ,
V_2 -> V_27 . clock ) ;
V_8 = - V_12 ;
goto V_16;
}
V_8 = F_5 ( V_2 -> V_15 , 0x800001 , V_91 [ V_9 ] . V_13 ,
sizeof( V_91 [ V_9 ] . V_13 ) ) ;
if ( V_8 )
goto V_16;
}
if ( V_21 -> V_68 != V_2 -> V_68 ) {
for ( V_9 = 0 ; V_9 < F_8 ( V_33 ) ; V_9 ++ ) {
if ( V_33 [ V_9 ] . clock == V_2 -> V_27 . clock )
break;
}
if ( V_9 == F_8 ( V_33 ) ) {
F_9 ( & V_7 -> V_2 ,
L_14 ,
V_2 -> V_27 . clock ) ;
V_8 = - V_12 ;
goto V_16;
}
V_83 = V_33 [ V_9 ] . V_34 ;
if ( V_2 -> V_27 . V_31 == V_92 )
V_83 = 2 * V_83 ;
if ( V_18 -> V_88 . V_89 . V_93 )
V_18 -> V_88 . V_89 . V_93 ( V_18 , & V_86 ) ;
else
V_86 = 0 ;
V_24 = F_16 ( ( V_32 ) V_86 * 0x800000 ,
V_83 ) ;
if ( ! V_2 -> V_27 . V_94 && V_86 )
V_24 = 0x800000 - V_24 ;
V_11 [ 0 ] = ( V_24 >> 0 ) & 0xff ;
V_11 [ 1 ] = ( V_24 >> 8 ) & 0xff ;
V_11 [ 2 ] = ( V_24 >> 16 ) & 0xff ;
V_8 = F_5 ( V_2 -> V_15 , 0x800029 , V_11 , 3 ) ;
if ( V_8 )
goto V_16;
F_3 ( & V_7 -> V_2 , L_15 , V_24 ) ;
V_2 -> V_68 = V_21 -> V_68 ;
}
V_8 = F_10 ( V_2 -> V_15 , 0x80f904 , 0x03 ,
V_85 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x800040 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x800047 , 0x00 ) ;
if ( V_8 )
goto V_16;
V_8 = F_10 ( V_2 -> V_15 , 0x80f999 , 0x01 , 0x00 ) ;
if ( V_8 )
goto V_16;
if ( V_21 -> V_87 <= 230000000 )
V_84 = 0x00 ;
else
V_84 = 0x01 ;
V_8 = F_11 ( V_2 -> V_15 , 0x80004b , V_84 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x800000 , 0x00 ) ;
if ( V_8 )
goto V_16;
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
T_1 V_11 [ 8 ] ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
V_8 = F_18 ( V_2 -> V_15 , 0x80f900 , V_11 , 8 ) ;
if ( V_8 )
goto V_16;
switch ( ( V_11 [ 0 ] >> 0 ) & 3 ) {
case 0 :
V_21 -> V_95 = V_96 ;
break;
case 1 :
V_21 -> V_95 = V_97 ;
break;
}
switch ( ( V_11 [ 1 ] >> 0 ) & 3 ) {
case 0 :
V_21 -> V_98 = V_99 ;
break;
case 1 :
V_21 -> V_98 = V_100 ;
break;
case 2 :
V_21 -> V_98 = V_101 ;
break;
case 3 :
V_21 -> V_98 = V_102 ;
break;
}
switch ( ( V_11 [ 2 ] >> 0 ) & 7 ) {
case 0 :
V_21 -> V_103 = V_104 ;
break;
case 1 :
V_21 -> V_103 = V_105 ;
break;
case 2 :
V_21 -> V_103 = V_106 ;
break;
case 3 :
V_21 -> V_103 = V_107 ;
break;
}
switch ( ( V_11 [ 3 ] >> 0 ) & 3 ) {
case 0 :
V_21 -> V_108 = V_109 ;
break;
case 1 :
V_21 -> V_108 = V_110 ;
break;
case 2 :
V_21 -> V_108 = V_111 ;
break;
}
switch ( ( V_11 [ 4 ] >> 0 ) & 3 ) {
case 0 :
V_21 -> V_68 = 6000000 ;
break;
case 1 :
V_21 -> V_68 = 7000000 ;
break;
case 2 :
V_21 -> V_68 = 8000000 ;
break;
}
switch ( ( V_11 [ 6 ] >> 0 ) & 7 ) {
case 0 :
V_21 -> V_112 = V_113 ;
break;
case 1 :
V_21 -> V_112 = V_114 ;
break;
case 2 :
V_21 -> V_112 = V_115 ;
break;
case 3 :
V_21 -> V_112 = V_116 ;
break;
case 4 :
V_21 -> V_112 = V_117 ;
break;
case 5 :
V_21 -> V_112 = V_118 ;
break;
}
switch ( ( V_11 [ 7 ] >> 0 ) & 7 ) {
case 0 :
V_21 -> V_119 = V_113 ;
break;
case 1 :
V_21 -> V_119 = V_114 ;
break;
case 2 :
V_21 -> V_119 = V_115 ;
break;
case 3 :
V_21 -> V_119 = V_116 ;
break;
case 4 :
V_21 -> V_119 = V_117 ;
break;
case 5 :
V_21 -> V_119 = V_118 ;
break;
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_19 ( struct V_17 * V_18 , enum V_120 * V_121 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_20 * V_21 = & V_18 -> V_22 ;
int V_8 , V_84 = 0 ;
T_1 V_11 [ 7 ] ;
unsigned int V_24 , V_122 ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
* V_121 = 0 ;
V_8 = F_20 ( V_2 -> V_15 , 0x800047 , & V_24 ) ;
if ( V_8 )
goto V_16;
if ( V_24 == 0x01 )
* V_121 |= V_123 ;
if ( V_24 != 0x02 ) {
V_8 = F_20 ( V_2 -> V_15 , 0x80f5a9 , & V_24 ) ;
if ( V_8 )
goto V_16;
if ( ( V_24 >> 0 ) & 0x01 )
* V_121 |= V_123 | V_124 |
V_125 ;
V_8 = F_20 ( V_2 -> V_15 , 0x80f999 , & V_24 ) ;
if ( V_8 )
goto V_16;
if ( ( V_24 >> 0 ) & 0x01 )
* V_121 |= V_123 | V_124 |
V_125 | V_126 |
V_127 ;
}
V_2 -> V_120 = * V_121 ;
if ( V_2 -> V_120 & V_123 ) {
if ( V_2 -> V_128 ) {
V_8 = F_20 ( V_2 -> V_15 , 0x80004a , & V_24 ) ;
if ( V_8 )
goto V_16;
V_84 = - V_24 * 1000 ;
} else {
V_8 = F_20 ( V_2 -> V_15 , 0x8000f7 , & V_24 ) ;
if ( V_8 )
goto V_16;
V_84 = ( V_24 - 100 ) * 1000 ;
}
V_21 -> V_69 . V_23 = 1 ;
V_21 -> V_69 . V_70 [ 0 ] . V_71 = V_129 ;
V_21 -> V_69 . V_70 [ 0 ] . V_130 = V_84 ;
} else {
V_21 -> V_69 . V_23 = 1 ;
V_21 -> V_69 . V_70 [ 0 ] . V_71 = V_72 ;
}
if ( V_2 -> V_120 & V_125 ) {
V_8 = F_18 ( V_2 -> V_15 , 0x80002c , V_11 , 3 ) ;
if ( V_8 )
goto V_16;
V_122 = V_11 [ 2 ] << 16 | V_11 [ 1 ] << 8 | V_11 [ 0 ] << 0 ;
V_8 = F_20 ( V_2 -> V_15 , 0x80f78b , & V_24 ) ;
if ( V_8 )
goto V_16;
if ( V_24 )
V_122 /= V_24 ;
V_8 = F_20 ( V_2 -> V_15 , 0x80f900 , & V_24 ) ;
if ( V_8 )
goto V_16;
switch ( ( V_24 >> 0 ) & 3 ) {
case 0 :
V_122 *= 4 ;
break;
case 1 :
V_122 *= 1 ;
break;
case 2 :
V_122 *= 2 ;
break;
default:
V_122 *= 0 ;
break;
}
V_8 = F_20 ( V_2 -> V_15 , 0x80f903 , & V_24 ) ;
if ( V_8 )
goto V_16;
switch ( ( V_24 >> 0 ) & 3 ) {
case 0 :
V_122 = F_21 ( V_122 , 653799U , 1689999U ) ;
V_122 = ( ( V_32 ) ( F_22 ( V_122 )
- F_22 ( 1690000 - V_122 )
+ 3355443 ) * 13 * 1000 ) >> 24 ;
break;
case 1 :
V_122 = F_21 ( V_122 , 371105U , 827999U ) ;
V_122 = ( ( V_32 ) ( F_22 ( V_122 - 370000 )
- F_22 ( 828000 - V_122 )
+ 43900382 ) * 6 * 1000 ) >> 24 ;
break;
case 2 :
V_122 = F_21 ( V_122 , 193246U , 424999U ) ;
V_122 = ( ( V_32 ) ( F_22 ( V_122 - 193000 )
- F_22 ( 425000 - V_122 )
+ 49912218 ) * 8 * 1000 ) >> 24 ;
break;
default:
V_122 = 0 ;
break;
}
F_3 ( & V_7 -> V_2 , L_16 , V_122 ) ;
V_21 -> V_73 . V_70 [ 0 ] . V_71 = V_129 ;
V_21 -> V_73 . V_70 [ 0 ] . V_130 = V_122 ;
} else {
V_21 -> V_73 . V_70 [ 0 ] . V_71 = V_72 ;
}
if ( V_2 -> V_120 & V_127 ) {
T_3 V_131 , V_132 ;
T_2 V_133 ;
V_8 = F_18 ( V_2 -> V_15 , 0x800032 , V_11 , 7 ) ;
if ( V_8 )
goto V_16;
V_131 = ( V_11 [ 1 ] << 8 ) | ( V_11 [ 0 ] << 0 ) ;
V_133 = ( V_11 [ 4 ] << 16 ) | ( V_11 [ 3 ] << 8 ) | V_11 [ 2 ] ;
V_132 = ( V_11 [ 6 ] << 8 ) | ( V_11 [ 5 ] << 0 ) ;
V_2 -> V_134 += V_131 ;
V_2 -> V_135 += V_132 ;
V_2 -> V_77 += V_133 ;
V_2 -> V_76 += V_132 * 204 * 8 ;
V_21 -> V_74 . V_23 = 1 ;
V_21 -> V_74 . V_70 [ 0 ] . V_71 = V_136 ;
V_21 -> V_74 . V_70 [ 0 ] . V_137 = V_2 -> V_135 ;
V_21 -> V_75 . V_23 = 1 ;
V_21 -> V_75 . V_70 [ 0 ] . V_71 = V_136 ;
V_21 -> V_75 . V_70 [ 0 ] . V_137 = V_2 -> V_134 ;
V_21 -> V_76 . V_23 = 1 ;
V_21 -> V_76 . V_70 [ 0 ] . V_71 = V_136 ;
V_21 -> V_76 . V_70 [ 0 ] . V_137 = V_2 -> V_76 ;
V_21 -> V_77 . V_23 = 1 ;
V_21 -> V_77 . V_70 [ 0 ] . V_71 = V_136 ;
V_21 -> V_77 . V_70 [ 0 ] . V_137 = V_2 -> V_77 ;
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_23 ( struct V_17 * V_18 , T_3 * V_138 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_20 * V_21 = & V_2 -> V_18 . V_22 ;
int V_8 ;
unsigned int V_24 ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
if ( V_21 -> V_73 . V_70 [ 0 ] . V_71 == V_129 ) {
if ( V_2 -> V_128 ) {
* V_138 = F_24 ( V_21 -> V_73 . V_70 [ 0 ] . V_130 , 100 ) ;
} else {
* V_138 = F_24 ( V_21 -> V_73 . V_70 [ 0 ] . V_130 , 1000 ) ;
V_8 = F_20 ( V_2 -> V_15 , 0x80f903 , & V_24 ) ;
if ( V_8 )
goto V_16;
switch ( ( V_24 >> 0 ) & 3 ) {
case 0 :
* V_138 = * V_138 * 0xffff / 23 ;
break;
case 1 :
* V_138 = * V_138 * 0xffff / 26 ;
break;
case 2 :
* V_138 = * V_138 * 0xffff / 32 ;
break;
default:
goto V_16;
}
}
} else {
* V_138 = 0 ;
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_25 ( struct V_17 * V_18 , T_3 * V_69 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_20 * V_21 = & V_2 -> V_18 . V_22 ;
int V_8 , V_84 , V_139 ;
unsigned int V_24 ;
T_1 V_140 , V_11 [ 7 ] ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
if ( V_2 -> V_128 ) {
V_8 = F_20 ( V_2 -> V_15 , 0x800048 , & V_24 ) ;
if ( V_8 )
goto V_16;
* V_69 = V_24 * 0xffff / 100 ;
} else {
V_8 = F_20 ( V_2 -> V_15 , 0x8000f7 , & V_24 ) ;
if ( V_8 )
goto V_16;
V_8 = F_18 ( V_2 -> V_15 , 0x80f900 , V_11 , 7 ) ;
if ( V_8 )
goto V_16;
if ( V_21 -> V_87 <= 300000000 )
V_140 = 7 ;
else
V_140 = 4 ;
V_139 = ( V_24 - 100 - V_140 ) -
V_141 [ ( ( V_11 [ 3 ] >> 0 ) & 3 ) ] [ ( ( V_11 [ 6 ] >> 0 ) & 7 ) ] ;
if ( V_139 < - 15 )
V_84 = 0 ;
else if ( ( V_139 >= - 15 ) && ( V_139 < 0 ) )
V_84 = ( 2 * ( V_139 + 15 ) ) / 3 ;
else if ( ( V_139 >= 0 ) && ( V_139 < 20 ) )
V_84 = 4 * V_139 + 10 ;
else if ( ( V_139 >= 20 ) && ( V_139 < 35 ) )
V_84 = ( 2 * ( V_139 - 20 ) ) / 3 + 90 ;
else
V_84 = 100 ;
* V_69 = V_84 * 0xffff / 100 ;
}
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_26 ( struct V_17 * V_18 , T_2 * V_142 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
* V_142 = ( V_2 -> V_77 - V_2 -> V_143 ) ;
V_2 -> V_143 = V_2 -> V_77 ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 , T_2 * V_144 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
* V_144 = V_2 -> V_134 ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 , int V_145 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_3 ( & V_7 -> V_2 , L_17 , V_145 ) ;
V_8 = F_10 ( V_2 -> V_15 , 0x00fa04 , 0x01 , V_145 ) ;
if ( V_8 )
goto V_16;
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_29 ( struct V_17 * V_18 , int V_146 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
F_3 ( & V_7 -> V_2 , L_18 , V_146 ) ;
V_8 = F_10 ( V_2 -> V_15 , 0x80f993 , 0x01 , V_146 ) ;
if ( V_8 )
goto V_16;
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_30 ( struct V_17 * V_18 , int V_147 , T_3 V_148 ,
int V_146 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 ;
T_1 V_149 [ 2 ] = { ( V_148 >> 0 ) & 0xff , ( V_148 >> 8 ) & 0xff } ;
F_3 ( & V_7 -> V_2 , L_19 ,
V_147 , V_148 , V_146 ) ;
if ( V_148 > 0x1fff )
return 0 ;
V_8 = F_5 ( V_2 -> V_15 , 0x80f996 , V_149 , 2 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x80f994 , V_146 ) ;
if ( V_8 )
goto V_16;
V_8 = F_11 ( V_2 -> V_15 , 0x80f995 , V_147 ) ;
if ( V_8 )
goto V_16;
return 0 ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_31 ( struct V_6 * V_7 ,
const struct V_150 * V_151 )
{
struct V_152 * V_27 = V_7 -> V_2 . V_153 ;
struct V_1 * V_2 ;
int V_8 ;
T_1 V_11 [ 8 ] ;
T_2 V_14 ;
static const struct V_154 V_154 = {
. V_155 = 24 ,
. V_156 = 8 ,
} ;
V_2 = F_32 ( sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 ) {
V_8 = - V_158 ;
goto V_16;
}
V_2 -> V_7 = V_7 ;
memcpy ( & V_2 -> V_27 , V_27 , sizeof( V_2 -> V_27 ) ) ;
switch ( V_2 -> V_27 . V_37 ) {
case V_159 :
V_2 -> V_30 = true ;
break;
case V_67 :
V_2 -> V_29 = true ;
break;
case V_38 :
default:
break;
}
if ( V_2 -> V_27 . clock != 12000000 ) {
V_8 = - V_66 ;
F_9 ( & V_7 -> V_2 ,
L_20 ,
V_2 -> V_27 . clock ) ;
goto V_160;
}
V_2 -> V_15 = F_33 ( V_7 , & V_154 ) ;
if ( F_34 ( V_2 -> V_15 ) ) {
V_8 = F_35 ( V_2 -> V_15 ) ;
goto V_160;
}
switch ( V_2 -> V_27 . V_28 ) {
case V_39 :
case V_40 :
case V_41 :
case V_43 :
case V_44 :
case V_45 :
V_2 -> V_161 = true ;
V_14 = 0x004bfc ;
break;
default:
V_2 -> V_128 = true ;
V_14 = 0x0083e9 ;
break;
}
V_8 = F_18 ( V_2 -> V_15 , V_14 , & V_11 [ 0 ] , 4 ) ;
if ( V_8 )
goto V_162;
V_8 = F_18 ( V_2 -> V_15 , 0x804191 , & V_11 [ 4 ] , 4 ) ;
if ( V_8 )
goto V_162;
F_36 ( & V_7 -> V_2 ,
L_21 ,
V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] ,
V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
switch ( V_2 -> V_27 . V_28 ) {
case V_39 :
case V_40 :
case V_41 :
case V_43 :
case V_44 :
case V_45 :
break;
default:
V_8 = F_11 ( V_2 -> V_15 , 0x80004c , 0x01 ) ;
if ( V_8 )
goto V_162;
V_8 = F_11 ( V_2 -> V_15 , 0x800000 , 0x00 ) ;
if ( V_8 )
goto V_162;
}
memcpy ( & V_2 -> V_18 . V_88 , & V_163 , sizeof( V_2 -> V_18 . V_88 ) ) ;
V_2 -> V_18 . V_19 = V_2 ;
* V_27 -> V_18 = & V_2 -> V_18 ;
if ( V_27 -> V_88 ) {
V_27 -> V_88 -> V_164 = F_30 ;
V_27 -> V_88 -> V_165 = F_29 ;
}
V_27 -> V_15 = V_2 -> V_15 ;
F_37 ( V_7 , V_2 ) ;
F_36 ( & V_7 -> V_2 , L_22 ) ;
return 0 ;
V_162:
F_38 ( V_2 -> V_15 ) ;
V_160:
F_39 ( V_2 ) ;
V_16:
F_3 ( & V_7 -> V_2 , L_3 , V_8 ) ;
return V_8 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_41 ( V_7 ) ;
F_3 ( & V_7 -> V_2 , L_4 ) ;
F_38 ( V_2 -> V_15 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
