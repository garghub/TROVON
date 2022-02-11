static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 2 } ;
int V_13 ;
if ( ( V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ) != 1 )
F_3 ( L_1 , V_3 , V_4 , V_13 ) ;
return ( V_13 != 1 ) ? - V_15 : 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_13 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_6 V_18 [] = {
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_16 , . V_12 = 1 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_19 , . V_5 = V_17 , . V_12 = 1 }
} ;
V_13 = F_2 ( V_2 -> V_14 , V_18 , 2 ) ;
if ( V_13 != 2 )
F_3 ( L_2 , V_3 , V_13 ) ;
return V_17 [ 0 ] ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_20 ;
V_20 = F_4 ( V_2 , V_21 ) ;
F_1 ( V_2 , V_21 , V_20 & ~ V_22 ) ;
F_1 ( V_2 , V_21 , V_20 | V_22 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_23 )
{
T_3 V_24 ;
int V_25 ;
switch ( V_23 ) {
case 6000000 :
V_24 = 0x55B7 ;
break;
case 7000000 :
V_24 = 0x6400 ;
break;
case 8000000 :
V_24 = 0x7249 ;
break;
default:
return - V_26 ;
}
if ( ( V_25 = F_1 ( V_2 , V_27 , V_24 & 0xFF ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_28 , ( V_24 >> 8 ) & 0xFF ) ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_29 )
{
switch ( V_29 ) {
case V_30 :
return F_1 ( V_2 , V_31 , 0x00 | ( F_4 ( V_2 , V_31 ) & ~ 0x03 ) ) ;
case V_32 :
return F_1 ( V_2 , V_31 , 0x01 | ( F_4 ( V_2 , V_31 ) & ~ 0x03 ) ) ;
case V_33 :
case V_34 :
return F_1 ( V_2 , V_31 , 0x02 | ( F_4 ( V_2 , V_31 ) & ~ 0x03 ) ) ;
case V_35 :
return F_1 ( V_2 , V_31 , 0x03 | ( F_4 ( V_2 , V_31 ) & ~ 0x03 ) ) ;
default:
return - V_26 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_5 V_36 )
{
switch ( V_36 ) {
case V_37 :
return F_1 ( V_2 , V_38 , 0x00 ) ;
case V_39 :
return F_1 ( V_2 , V_38 , V_40 ) ;
default:
return - V_26 ;
}
}
static int F_9 ( struct V_1 * V_2 , T_6 V_41 )
{
int V_25 ;
switch ( V_41 ) {
case V_42 :
if ( ( V_25 = F_1 ( V_2 , V_43 , 0x00 | ( F_4 ( V_2 , V_43 ) & ~ 0x03 ) ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_31 , ( 0x00 << 2 ) | ( F_4 ( V_2 , V_31 ) & ~ 0x04 ) ) ;
case V_44 :
case V_45 :
if ( ( V_25 = F_1 ( V_2 , V_43 , 0x02 | ( F_4 ( V_2 , V_43 ) & ~ 0x03 ) ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_31 , ( 0x01 << 2 ) | ( F_4 ( V_2 , V_31 ) & ~ 0x04 ) ) ;
default:
return - V_26 ;
}
}
static void F_10 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_1 ( V_2 , V_49 , V_50 ) ;
F_1 ( V_2 , V_51 , ( 0x01 << 1 ) | 0x01 ) ;
F_1 ( V_2 , V_52 , 0x00 ) ;
F_1 ( V_2 , V_53 , 0x02 ) ;
F_1 ( V_2 , V_54 , 0x00 ) ;
F_1 ( V_2 , V_55 , 0x98 ) ;
F_1 ( V_2 , V_56 , 0x82 ) ;
F_1 ( V_2 , V_56 , V_57 | 0x02 ) ;
F_1 ( V_2 , V_21 , ( 0x01 << 5 ) | ( F_4 ( V_2 , V_21 ) & 0x0F ) ) ;
F_1 ( V_2 , V_31 , V_58 | 0x02 ) ;
F_1 ( V_2 , V_59 , V_60 | V_61 ) ;
F_1 ( V_2 , V_62 , 0x06 ) ;
F_1 ( V_2 , V_63 , 0x31 ) ;
F_1 ( V_2 , V_64 , ( 0x01 << 7 ) | ( 0x02 << 3 ) | 0x04 ) ;
F_1 ( V_2 , V_65 , 0xBB ) ;
F_1 ( V_2 , V_66 , 1 << 2 ) ;
F_1 ( V_2 , V_67 , V_68 ) ;
F_1 ( V_2 , V_27 , 0x49 ) ;
F_1 ( V_2 , V_28 , 0x72 ) ;
F_1 ( V_2 , V_69 , 1 << 5 ) ;
F_1 ( V_2 , V_43 , ( 1 << 7 ) | ( 3 << 4 ) | 2 ) ;
F_1 ( V_2 , V_70 , V_71 ) ;
if ( V_2 -> V_9 -> V_72 )
F_1 ( V_2 , V_73 , V_74 ) ;
else
F_1 ( V_2 , V_73 , 0 ) ;
F_1 ( V_2 , V_75 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_12 ( L_3 ) ;
V_20 = F_4 ( V_2 , V_76 ) ;
F_12 ( L_4 , V_20 & 0x01 ) ;
F_12 ( L_5 , ( V_20 >> 1 ) & 0x01 ) ;
V_20 = F_4 ( V_2 , V_77 ) ;
F_12 ( L_6 , ( V_20 >> 7 ) & 0x01 ) ;
switch ( ( V_20 >> 4 ) & 0x07 ) {
case 0x00 :
F_12 ( L_7 ) ;
break;
case 0x01 :
F_12 ( L_8 ) ;
break;
case 0x02 :
F_12 ( L_9 ) ;
break;
case 0x03 :
F_12 ( L_10 ) ;
break;
case 0x04 :
F_12 ( L_11 ) ;
break;
default:
F_12 ( L_12 ) ;
}
V_20 = F_4 ( V_2 , V_78 ) ;
F_12 ( L_13 , ( V_20 >> 7 ) & 0x01 ) ;
F_12 ( L_14 , ( V_20 >> 6 ) & 0x01 ) ;
F_12 ( L_15 , ( V_20 >> 5 ) & 0x01 ) ;
F_12 ( L_16 , ( V_20 >> 4 ) & 0x01 ) ;
switch ( V_20 & 0x0F ) {
case 0x00 :
F_12 ( L_17 ) ;
break;
case 0x02 :
F_12 ( L_18 ) ;
break;
case 0x03 :
F_12 ( L_19 ) ;
break;
case 0x04 :
F_12 ( L_20 ) ;
break;
case 0x01 :
F_12 ( L_21 ) ;
break;
case 0x05 :
F_12 ( L_22 ) ;
break;
case 0x06 :
F_12 ( L_23 ) ;
break;
default:
F_12 ( L_24 ) ;
}
V_20 = F_4 ( V_2 , V_79 ) ;
F_12 ( L_15 , ( V_20 >> 4 ) & 0x01 ) ;
F_12 ( L_25 , ( V_20 >> 2 ) & 0x01 ? L_26 : L_27 ) ;
switch ( ( V_20 >> 4 ) & 0x03 ) {
case 0x00 :
F_12 ( L_28 ) ;
break;
case 0x01 :
F_12 ( L_29 ) ;
break;
case 0x02 :
F_12 ( L_30 ) ;
break;
case 0x03 :
F_12 ( L_31 ) ;
break;
}
V_20 = F_4 ( V_2 , V_80 ) ;
switch ( ( V_20 >> 4 ) & 0x07 ) {
case 0x00 :
F_12 ( L_32 ) ;
break;
case 0x01 :
F_12 ( L_33 ) ;
break;
case 0x02 :
F_12 ( L_34 ) ;
break;
case 0x03 :
F_12 ( L_35 ) ;
break;
case 0x04 :
F_12 ( L_36 ) ;
break;
default:
F_12 ( L_37 ) ;
}
switch ( V_20 & 0x07 ) {
case 0x00 :
F_12 ( L_38 ) ;
break;
case 0x01 :
F_12 ( L_39 ) ;
break;
case 0x02 :
F_12 ( L_40 ) ;
break;
case 0x03 :
F_12 ( L_41 ) ;
break;
case 0x04 :
F_12 ( L_42 ) ;
break;
default:
F_12 ( L_43 ) ;
}
V_20 = F_4 ( V_2 , V_81 ) ;
F_12 ( L_44 , V_20 & 0x01 ? L_26 : L_27 ) ;
switch ( ( V_20 >> 4 ) & 0x03 ) {
case 0x00 :
F_12 ( L_45 ) ;
break;
case 0x01 :
F_12 ( L_46 ) ;
break;
case 0x02 :
F_12 ( L_47 ) ;
break;
case 0x03 :
F_12 ( L_48 ) ;
break;
}
F_4 ( V_2 , V_82 ) ;
V_20 = F_4 ( V_2 , V_83 ) ;
V_20 = F_4 ( V_2 , V_83 ) ;
F_12 ( L_49 , ( V_20 >> 4 ) & 0x01 ) ;
F_12 ( L_50 ) ;
}
static int F_13 ( struct V_46 * V_47 , T_7 * V_84 )
{
T_1 V_85 ;
struct V_1 * V_2 = V_47 -> V_48 ;
* V_84 = 0 ;
V_85 = F_4 ( V_2 , V_78 ) ;
if ( V_85 & V_86 )
* V_84 |= V_87 ;
if ( F_4 ( V_2 , V_79 ) & V_88 )
* V_84 |= V_89 ;
if ( F_4 ( V_2 , V_77 ) & V_90 )
* V_84 |= V_91 ;
if ( F_4 ( V_2 , V_76 ) & V_92 )
* V_84 |= V_93 ;
if ( ( V_85 & V_94 ) && ( * V_84 == ( V_87 | V_89 | V_91 | V_93 ) ) )
* V_84 |= V_95 ;
if ( V_96 )
F_11 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_5 ( V_2 ) ;
F_10 ( V_47 ) ;
return 0 ;
}
static int F_15 ( struct V_46 * V_47 )
{
struct V_97 * V_98 = & V_47 -> V_99 ;
struct V_1 * V_2 = V_47 -> V_48 ;
int V_25 ;
if ( V_47 -> V_100 . V_101 . V_102 ) {
V_47 -> V_100 . V_101 . V_102 ( V_47 ) ;
if ( V_47 -> V_100 . V_103 ) V_47 -> V_100 . V_103 ( V_47 , 0 ) ;
}
V_25 = F_6 ( V_2 , V_98 -> V_104 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_7 ( V_2 , V_98 -> V_29 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( V_2 , V_98 -> V_41 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_8 ( V_2 , V_98 -> V_36 ) ;
if ( V_25 < 0 )
return V_25 ;
F_16 ( 500 ) ;
return 0 ;
}
static void F_17 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_46 * V_47 , T_3 * V_105 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
* V_105 = F_4 ( V_2 , V_106 ) / 8 ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 , T_2 * V_107 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_1 ( V_2 , V_108 , 0x18 ) ;
* V_107 = ( F_4 ( V_2 , V_109 ) << 8 ) |
F_4 ( V_2 , V_110 ) ;
F_1 ( V_2 , V_108 , 0x18 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 , T_3 * V_111 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
* V_111 = ( short ) ( 511 -
( F_4 ( V_2 , V_112 ) +
( ( F_4 ( V_2 , V_113 ) & 0x03 ) << 8 ) ) ) ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 , struct V_114 * V_115 )
{
V_115 -> V_116 = 500 ;
return 0 ;
}
static int F_23 ( struct V_46 * V_47 , int V_117 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
if ( V_117 ) {
return F_1 ( V_2 , V_118 , 0x01 ) ;
} else {
return F_1 ( V_2 , V_118 , 0x00 ) ;
}
}
struct V_46 * F_24 ( const struct V_119 * V_9 ,
struct V_120 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_121 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
if ( F_4 ( V_2 , V_122 ) != V_123 ) goto error;
memcpy ( & V_2 -> V_124 . V_100 , & V_125 , sizeof( struct V_126 ) ) ;
V_2 -> V_124 . V_48 = V_2 ;
return & V_2 -> V_124 ;
error:
F_18 ( V_2 ) ;
return NULL ;
}
