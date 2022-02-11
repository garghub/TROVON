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
case V_26 :
V_24 = 0x55B7 ;
break;
case V_27 :
V_24 = 0x6400 ;
break;
case V_28 :
V_24 = 0x7249 ;
break;
default:
return - V_29 ;
}
if ( ( V_25 = F_1 ( V_2 , V_30 , V_24 & 0xFF ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_31 , ( V_24 >> 8 ) & 0xFF ) ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_32 )
{
switch ( V_32 ) {
case V_33 :
return F_1 ( V_2 , V_34 , 0x00 | ( F_4 ( V_2 , V_34 ) & ~ 0x03 ) ) ;
case V_35 :
return F_1 ( V_2 , V_34 , 0x01 | ( F_4 ( V_2 , V_34 ) & ~ 0x03 ) ) ;
case V_36 :
case V_37 :
return F_1 ( V_2 , V_34 , 0x02 | ( F_4 ( V_2 , V_34 ) & ~ 0x03 ) ) ;
case V_38 :
return F_1 ( V_2 , V_34 , 0x03 | ( F_4 ( V_2 , V_34 ) & ~ 0x03 ) ) ;
default:
return - V_29 ;
}
}
static int F_8 ( struct V_1 * V_2 , T_5 V_39 )
{
switch ( V_39 ) {
case V_40 :
return F_1 ( V_2 , V_41 , 0x00 ) ;
case V_42 :
return F_1 ( V_2 , V_41 , V_43 ) ;
default:
return - V_29 ;
}
}
static int F_9 ( struct V_1 * V_2 , T_6 V_44 )
{
int V_25 ;
switch ( V_44 ) {
case V_45 :
if ( ( V_25 = F_1 ( V_2 , V_46 , 0x00 | ( F_4 ( V_2 , V_46 ) & ~ 0x03 ) ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_34 , ( 0x00 << 2 ) | ( F_4 ( V_2 , V_34 ) & ~ 0x04 ) ) ;
case V_47 :
case V_48 :
if ( ( V_25 = F_1 ( V_2 , V_46 , 0x02 | ( F_4 ( V_2 , V_46 ) & ~ 0x03 ) ) ) < 0 )
return V_25 ;
return F_1 ( V_2 , V_34 , ( 0x01 << 2 ) | ( F_4 ( V_2 , V_34 ) & ~ 0x04 ) ) ;
default:
return - V_29 ;
}
}
static void F_10 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
F_1 ( V_2 , V_52 , V_53 ) ;
F_1 ( V_2 , V_54 , ( 0x01 << 1 ) | 0x01 ) ;
F_1 ( V_2 , V_55 , 0x00 ) ;
F_1 ( V_2 , V_56 , 0x02 ) ;
F_1 ( V_2 , V_57 , 0x00 ) ;
F_1 ( V_2 , V_58 , 0x98 ) ;
F_1 ( V_2 , V_59 , 0x82 ) ;
F_1 ( V_2 , V_59 , V_60 | 0x02 ) ;
F_1 ( V_2 , V_21 , ( 0x01 << 5 ) | ( F_4 ( V_2 , V_21 ) & 0x0F ) ) ;
F_1 ( V_2 , V_34 , V_61 | 0x02 ) ;
F_1 ( V_2 , V_62 , V_63 | V_64 ) ;
F_1 ( V_2 , V_65 , 0x06 ) ;
F_1 ( V_2 , V_66 , 0x31 ) ;
F_1 ( V_2 , V_67 , ( 0x01 << 7 ) | ( 0x02 << 3 ) | 0x04 ) ;
F_1 ( V_2 , V_68 , 0xBB ) ;
F_1 ( V_2 , V_69 , 1 << 2 ) ;
F_1 ( V_2 , V_70 , V_71 ) ;
F_1 ( V_2 , V_30 , 0x49 ) ;
F_1 ( V_2 , V_31 , 0x72 ) ;
F_1 ( V_2 , V_72 , 1 << 5 ) ;
F_1 ( V_2 , V_46 , ( 1 << 7 ) | ( 3 << 4 ) | 2 ) ;
F_1 ( V_2 , V_73 , V_74 ) ;
if ( V_2 -> V_9 -> V_75 )
F_1 ( V_2 , V_76 , V_77 ) ;
else
F_1 ( V_2 , V_76 , 0 ) ;
F_1 ( V_2 , V_78 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_20 ;
F_12 ( L_3 ) ;
V_20 = F_4 ( V_2 , V_79 ) ;
F_12 ( L_4 , V_20 & 0x01 ) ;
F_12 ( L_5 , ( V_20 >> 1 ) & 0x01 ) ;
V_20 = F_4 ( V_2 , V_80 ) ;
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
V_20 = F_4 ( V_2 , V_81 ) ;
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
V_20 = F_4 ( V_2 , V_82 ) ;
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
V_20 = F_4 ( V_2 , V_83 ) ;
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
V_20 = F_4 ( V_2 , V_84 ) ;
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
F_4 ( V_2 , V_85 ) ;
V_20 = F_4 ( V_2 , V_86 ) ;
V_20 = F_4 ( V_2 , V_86 ) ;
F_12 ( L_49 , ( V_20 >> 4 ) & 0x01 ) ;
F_12 ( L_50 ) ;
}
static int F_13 ( struct V_49 * V_50 , T_7 * V_87 )
{
T_1 V_88 ;
struct V_1 * V_2 = V_50 -> V_51 ;
* V_87 = 0 ;
V_88 = F_4 ( V_2 , V_81 ) ;
if ( V_88 & V_89 )
* V_87 |= V_90 ;
if ( F_4 ( V_2 , V_82 ) & V_91 )
* V_87 |= V_92 ;
if ( F_4 ( V_2 , V_80 ) & V_93 )
* V_87 |= V_94 ;
if ( F_4 ( V_2 , V_79 ) & V_95 )
* V_87 |= V_96 ;
if ( ( V_88 & V_97 ) && ( * V_87 == ( V_90 | V_92 | V_94 | V_96 ) ) )
* V_87 |= V_98 ;
if ( V_99 )
F_11 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
F_5 ( V_2 ) ;
F_10 ( V_50 ) ;
return 0 ;
}
static int F_15 ( struct V_49 * V_50 , struct V_100 * V_101 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
int V_25 ;
if ( V_50 -> V_102 . V_103 . V_104 ) {
V_50 -> V_102 . V_103 . V_104 ( V_50 , V_101 ) ;
if ( V_50 -> V_102 . V_105 ) V_50 -> V_102 . V_105 ( V_50 , 0 ) ;
}
if ( ( V_25 = F_6 ( V_2 , V_101 -> V_106 . V_107 . V_23 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_7 ( V_2 , V_101 -> V_106 . V_107 . V_32 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_9 ( V_2 , V_101 -> V_106 . V_107 . V_44 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_8 ( V_2 , V_101 -> V_39 ) ) < 0 )
return V_25 ;
F_16 ( 500 ) ;
return 0 ;
}
static void F_17 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_49 * V_50 , T_3 * V_108 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
* V_108 = F_4 ( V_2 , V_109 ) / 8 ;
return 0 ;
}
static int F_20 ( struct V_49 * V_50 , T_8 * V_110 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
F_1 ( V_2 , V_111 , 0x18 ) ;
* V_110 = ( F_4 ( V_2 , V_112 ) << 8 ) |
F_4 ( V_2 , V_113 ) ;
F_1 ( V_2 , V_111 , 0x18 ) ;
return 0 ;
}
static int F_21 ( struct V_49 * V_50 , T_3 * V_114 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
* V_114 = ( short ) ( 511 -
( F_4 ( V_2 , V_115 ) +
( ( F_4 ( V_2 , V_116 ) & 0x03 ) << 8 ) ) ) ;
return 0 ;
}
static int F_22 ( struct V_49 * V_50 , struct V_117 * V_118 )
{
V_118 -> V_119 = 500 ;
return 0 ;
}
static int F_23 ( struct V_49 * V_50 , int V_120 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
if ( V_120 ) {
return F_1 ( V_2 , V_121 , 0x01 ) ;
} else {
return F_1 ( V_2 , V_121 , 0x00 ) ;
}
}
struct V_49 * F_24 ( const struct V_122 * V_9 ,
struct V_123 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_124 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
if ( F_4 ( V_2 , V_125 ) != V_126 ) goto error;
memcpy ( & V_2 -> V_127 . V_102 , & V_128 , sizeof( struct V_129 ) ) ;
V_2 -> V_127 . V_51 = V_2 ;
return & V_2 -> V_127 ;
error:
F_18 ( V_2 ) ;
return NULL ;
}
