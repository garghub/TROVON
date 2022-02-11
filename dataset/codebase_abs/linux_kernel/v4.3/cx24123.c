static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 , int V_5 )
{
T_1 V_6 [] = { V_4 , V_5 } ;
struct V_7 V_8 = {
. V_9 = V_3 , . V_10 = 0 , . V_6 = V_6 , . V_11 = 2
} ;
int V_12 ;
V_12 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_12 != 1 ) {
F_3 ( L_1
L_2 , V_14 , V_12 , V_4 , V_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_15 ;
T_1 V_16 = 0 ;
struct V_7 V_8 [] = {
{ . V_9 = V_3 , . V_10 = 0 , . V_6 = & V_4 , . V_11 = 1 } ,
{ . V_9 = V_3 , . V_10 = V_17 , . V_6 = & V_16 , . V_11 = 1 }
} ;
V_15 = F_2 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_15 != 2 ) {
V_12 ( L_3 , V_14 , V_4 , V_15 ) ;
return V_15 ;
}
return V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_18 V_19 )
{
T_1 V_20 = F_6 ( V_2 , 0x0e ) ;
T_1 V_21 = F_6 ( V_2 , 0x10 ) ;
switch ( V_19 ) {
case V_22 :
F_7 ( L_4 ) ;
F_8 ( V_2 , 0x0e , V_20 & ~ 0x80 ) ;
F_8 ( V_2 , 0x10 , V_21 | 0x80 ) ;
break;
case V_23 :
F_7 ( L_5 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x80 ) ;
F_8 ( V_2 , 0x10 , V_21 | 0x80 ) ;
break;
case V_24 :
F_7 ( L_6 ) ;
F_8 ( V_2 , 0x10 , V_21 & ~ 0x80 ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_18 * V_19 )
{
T_1 V_26 ;
V_26 = F_6 ( V_2 , 0x1b ) >> 7 ;
if ( V_26 == 0 ) {
F_7 ( L_7 ) ;
* V_19 = V_22 ;
} else {
F_7 ( L_8 ) ;
* V_19 = V_23 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , enum V_27 V_28 )
{
T_1 V_20 = F_6 ( V_2 , 0x0e ) & ~ 0x07 ;
if ( ( ( int ) V_28 < V_29 ) || ( V_28 > V_30 ) )
V_28 = V_30 ;
if ( V_28 == V_31 )
F_8 ( V_2 , 0x43 ,
F_6 ( V_2 , 0x43 ) | 0x01 ) ;
else
F_8 ( V_2 , 0x43 ,
F_6 ( V_2 , 0x43 ) & ~ 0x01 ) ;
switch ( V_28 ) {
case V_31 :
F_7 ( L_9 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x01 ) ;
F_8 ( V_2 , 0x0f , 0x02 ) ;
break;
case V_32 :
F_7 ( L_10 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x02 ) ;
F_8 ( V_2 , 0x0f , 0x04 ) ;
break;
case V_33 :
F_7 ( L_11 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x03 ) ;
F_8 ( V_2 , 0x0f , 0x08 ) ;
break;
case V_34 :
F_7 ( L_12 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x04 ) ;
F_8 ( V_2 , 0x0f , 0x10 ) ;
break;
case V_35 :
F_7 ( L_13 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x05 ) ;
F_8 ( V_2 , 0x0f , 0x20 ) ;
break;
case V_36 :
F_7 ( L_14 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x06 ) ;
F_8 ( V_2 , 0x0f , 0x40 ) ;
break;
case V_37 :
F_7 ( L_15 ) ;
F_8 ( V_2 , 0x0e , V_20 | 0x07 ) ;
F_8 ( V_2 , 0x0f , 0x80 ) ;
break;
case V_30 :
F_7 ( L_16 ) ;
F_8 ( V_2 , 0x0f , 0xfe ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , enum V_27 * V_28 )
{
int V_15 ;
V_15 = F_6 ( V_2 , 0x1b ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_15 & 0x07 ;
switch ( V_15 ) {
case 1 :
* V_28 = V_31 ;
break;
case 2 :
* V_28 = V_32 ;
break;
case 3 :
* V_28 = V_33 ;
break;
case 4 :
* V_28 = V_34 ;
break;
case 5 :
* V_28 = V_35 ;
break;
case 6 :
* V_28 = V_36 ;
break;
case 7 :
* V_28 = V_37 ;
break;
default:
* V_28 = V_29 ;
}
return 0 ;
}
static T_2 F_12 ( T_2 V_39 , T_2 V_16 )
{
T_2 exp , V_40 = 0 ;
T_2 div = V_39 / V_16 ;
if ( V_39 % V_16 >= V_16 / 2 )
++ div ;
if ( div < ( 1 << 31 ) ) {
for ( exp = 1 ; div > exp ; V_40 ++ )
exp += exp ;
}
return V_40 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_41 )
{
T_3 V_42 ;
T_2 V_43 , V_44 , V_45 ;
T_1 V_46 ;
if ( ( V_41 > V_2 -> V_47 . V_48 . V_49 . V_50 ) ||
( V_41 < V_2 -> V_47 . V_48 . V_49 . V_51 ) )
return - V_38 ;
if ( V_41 < ( V_52 * 2 ) / 2 )
V_46 = 2 ;
else if ( V_41 < ( V_52 * 3 ) / 2 )
V_46 = 3 ;
else if ( V_41 < ( V_52 * 4 ) / 2 )
V_46 = 4 ;
else if ( V_41 < ( V_52 * 5 ) / 2 )
V_46 = 5 ;
else if ( V_41 < ( V_52 * 6 ) / 2 )
V_46 = 6 ;
else if ( V_41 < ( V_52 * 7 ) / 2 )
V_46 = 7 ;
else if ( V_41 < ( V_52 * 8 ) / 2 )
V_46 = 8 ;
else
V_46 = 9 ;
V_43 = V_46 * V_52 ;
V_42 = ( ( T_3 ) V_41 ) << 23 ;
F_14 ( V_42 , V_43 ) ;
V_44 = ( T_2 ) V_42 ;
F_8 ( V_2 , 0x01 , V_46 * 6 ) ;
F_8 ( V_2 , 0x08 , ( V_44 >> 16 ) & 0x3f ) ;
F_8 ( V_2 , 0x09 , ( V_44 >> 8 ) & 0xff ) ;
F_8 ( V_2 , 0x0a , V_44 & 0xff ) ;
V_45 = F_12 ( V_43 , V_41 ) ;
V_42 = F_6 ( V_2 , 0x0c ) & ~ 0xe0 ;
F_8 ( V_2 , 0x0c , V_42 | V_45 << 5 ) ;
F_7 ( L_17 ,
V_41 , V_44 , V_43 , V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_54 -> V_57 ;
struct V_1 * V_2 = V_54 -> V_58 ;
T_2 V_59 = 0 , V_60 = 0 , V_61 = 0 ;
int V_62 = 0 ;
int V_63 = 2 ;
int V_64 = 0 ;
int V_65 = F_16 ( V_66 ) ;
struct V_67 * V_68 = NULL ;
struct V_69 * V_70 = NULL ;
V_2 -> V_71 = V_72 [ 0 ] . V_73 ;
V_2 -> V_74 = V_72 [ 0 ] . V_75 ;
V_2 -> V_76 = V_66 [ 0 ] . V_77 ;
V_61 = V_66 [ 0 ] . V_78 ;
for ( V_62 = 0 ; V_62 < F_16 ( V_72 ) ; V_62 ++ ) {
V_70 = & V_72 [ V_62 ] ;
if ( ( V_70 -> V_79 <= V_56 -> V_80 ) &&
( V_70 -> V_81 >= V_56 -> V_80 ) ) {
V_2 -> V_71 = V_70 -> V_73 ;
V_2 -> V_74 = V_70 -> V_75 ;
V_2 -> V_82 = V_70 -> V_82 ;
}
}
if ( V_83 < 1 || V_83 > V_65 ) {
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
V_68 = & V_66 [ V_62 ] ;
if ( ( V_68 -> V_84 <= V_56 -> V_85 ) &&
( V_68 -> V_86 >= V_56 -> V_85 ) )
V_64 = V_62 ;
}
} else
V_64 = V_83 - 1 ;
V_2 -> V_76 = V_66 [ V_64 ] . V_77 ;
V_61 = V_66 [ V_64 ] . V_78 ;
if ( V_56 -> V_85 < ( V_66 [ V_64 ] . V_84 +
V_66 [ V_64 ] . V_86 ) / 2 )
V_63 = 0x01 ;
else
V_63 = 0x02 ;
V_59 = ( ( ( V_56 -> V_85 * V_61 * 10 ) /
( 2 * V_52 / 1000 ) ) / 32 ) & 0x1ff ;
V_60 = ( ( ( V_56 -> V_85 * V_61 * 10 ) /
( 2 * V_52 / 1000 ) ) % 32 ) & 0x1f ;
if ( V_60 == 0 && V_59 > 0 )
V_59 -- ;
V_2 -> V_87 = ( 3 << 19 ) | ( 3 << 17 ) | ( 1 << 16 ) |
( V_63 << 14 ) | ( V_59 << 5 ) | V_60 ;
return 0 ;
}
static int F_17 ( struct V_53 * V_54 , T_2 V_5 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
unsigned long V_88 ;
F_7 ( L_18 , V_5 ) ;
V_5 = V_5 << 3 ;
F_8 ( V_2 , 0x21 , 0x15 ) ;
V_88 = V_89 + F_18 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 >> 16 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x40 ) == 0 ) {
if ( F_19 ( V_89 , V_88 ) ) {
V_12 ( L_19\
L_20 , V_14 ) ;
return - V_90 ;
}
F_20 ( 10 ) ;
}
V_88 = V_89 + F_18 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 >> 8 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x40 ) == 0 ) {
if ( F_19 ( V_89 , V_88 ) ) {
V_12 ( L_19\
L_20 , V_14 ) ;
return - V_90 ;
}
F_20 ( 10 ) ;
}
V_88 = V_89 + F_18 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x80 ) ) {
if ( F_19 ( V_89 , V_88 ) ) {
V_12 ( L_21 \
L_20 , V_14 ) ;
return - V_90 ;
}
F_20 ( 10 ) ;
}
F_8 ( V_2 , 0x20 , F_6 ( V_2 , 0x20 ) | 2 ) ;
F_8 ( V_2 , 0x20 , F_6 ( V_2 , 0x20 ) & 0xfd ) ;
return 0 ;
}
static int F_21 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_54 -> V_57 ;
struct V_1 * V_2 = V_54 -> V_58 ;
T_1 V_26 ;
F_7 ( L_22 , V_56 -> V_85 ) ;
if ( F_15 ( V_54 ) != 0 ) {
V_12 ( L_23 , V_14 ) ;
return - V_25 ;
}
F_17 ( V_54 , V_2 -> V_71 ) ;
F_17 ( V_54 , V_2 -> V_74 ) ;
F_17 ( V_54 , V_2 -> V_76 ) ;
F_17 ( V_54 , V_2 -> V_87 ) ;
V_26 = F_6 ( V_2 , 0x28 ) & ~ 0x3 ;
F_8 ( V_2 , 0x27 , V_2 -> V_82 >> 2 ) ;
F_8 ( V_2 , 0x28 , V_26 | ( V_2 -> V_82 & 0x3 ) ) ;
F_7 ( L_24 , V_2 -> V_71 ,
V_2 -> V_76 , V_2 -> V_87 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_91 , T_1 V_92 )
{
T_1 V_93 = F_6 ( V_2 , 0x23 ) & 0x1e ;
if ( V_91 )
V_93 |= ( 1 << 6 ) | ( V_92 << 5 ) ;
else
V_93 |= ( 1 << 7 ) | ( V_92 ) ;
return F_8 ( V_2 , 0x23 , V_93 ) ;
}
static int F_23 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
int V_62 ;
F_7 ( L_25 ) ;
for ( V_62 = 0 ; V_62 < F_16 ( V_94 ) ; V_62 ++ )
F_8 ( V_2 , V_94 [ V_62 ] . V_4 ,
V_94 [ V_62 ] . V_5 ) ;
if ( V_2 -> V_95 -> V_96 )
F_8 ( V_2 , 0x32 ,
F_6 ( V_2 , 0x32 ) | 0x02 ) ;
if ( V_2 -> V_95 -> V_97 )
F_22 ( V_2 , 1 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_53 * V_54 ,
enum V_98 V_99 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
T_1 V_26 ;
V_26 = F_6 ( V_2 , 0x29 ) & ~ 0x40 ;
switch ( V_99 ) {
case V_100 :
F_7 ( L_26 ) ;
return F_8 ( V_2 , 0x29 , V_26 & 0x7f ) ;
case V_101 :
F_7 ( L_27 ) ;
return F_8 ( V_2 , 0x29 , V_26 | 0x80 ) ;
case V_102 :
return 0 ;
default:
return - V_25 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned long V_88 = V_89 + F_18 ( 200 ) ;
while ( ! ( F_6 ( V_2 , 0x29 ) & 0x40 ) ) {
if ( F_19 ( V_89 , V_88 ) ) {
V_12 ( L_28 \
L_29 , V_14 ) ;
break;
}
F_20 ( 10 ) ;
}
}
static int F_26 ( struct V_53 * V_54 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
int V_62 , V_26 , V_105 ;
F_7 ( L_30 ) ;
V_105 = F_6 ( V_2 , 0x29 ) ;
if ( V_105 & 0x10 )
F_8 ( V_2 , 0x29 , V_105 & ~ 0x50 ) ;
F_25 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) & 0xfb ) ;
for ( V_62 = 0 ; V_62 < V_104 -> V_106 ; V_62 ++ )
F_8 ( V_2 , 0x2C + V_62 , V_104 -> V_8 [ V_62 ] ) ;
V_26 = F_6 ( V_2 , 0x29 ) ;
F_8 ( V_2 , 0x29 , ( ( V_26 & 0x90 ) | 0x40 ) |
( ( V_104 -> V_106 - 3 ) & 3 ) ) ;
F_25 ( V_2 ) ;
if ( V_105 & 0x10 )
F_8 ( V_2 , 0x29 , V_105 & ~ 0x40 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_54 ,
enum V_107 V_108 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
int V_26 , V_105 ;
F_7 ( L_30 ) ;
V_105 = F_6 ( V_2 , 0x29 ) ;
if ( V_105 & 0x10 )
F_8 ( V_2 , 0x29 , V_105 & ~ 0x50 ) ;
F_25 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) | 0x4 ) ;
F_20 ( 30 ) ;
V_26 = F_6 ( V_2 , 0x29 ) ;
if ( V_108 == V_109 )
F_8 ( V_2 , 0x29 , ( ( V_26 & 0x90 ) | 0x40 | 0x00 ) ) ;
else if ( V_108 == V_110 )
F_8 ( V_2 , 0x29 , ( ( V_26 & 0x90 ) | 0x40 | 0x08 ) ) ;
else
return - V_25 ;
F_25 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) & 0xfb ) ;
if ( V_105 & 0x10 )
F_8 ( V_2 , 0x29 , V_105 & ~ 0x40 ) ;
return 0 ;
}
static int F_28 ( struct V_53 * V_54 , enum V_111 * V_112 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
int V_113 = F_6 ( V_2 , 0x14 ) ;
* V_112 = 0 ;
if ( V_2 -> V_95 -> V_97 ) {
T_2 V_114 = 0 ;
if ( V_54 -> V_48 . V_115 . V_116 )
V_54 -> V_48 . V_115 . V_116 ( V_54 , & V_114 ) ;
if ( V_114 & V_117 )
* V_112 |= V_118 ;
} else {
int V_119 = F_6 ( V_2 , 0x20 ) ;
if ( V_119 & 0x01 )
* V_112 |= V_118 ;
}
if ( V_113 & 0x02 )
* V_112 |= V_120 ;
if ( V_113 & 0x04 )
* V_112 |= V_121 ;
if ( V_113 & 0x08 )
* V_112 |= V_122 ;
if ( V_113 & 0x80 )
* V_112 |= V_123 ;
return 0 ;
}
static int F_29 ( struct V_53 * V_54 , T_2 * V_124 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
* V_124 = ( ( F_6 ( V_2 , 0x1c ) & 0x3f ) << 16 ) |
( F_6 ( V_2 , 0x1d ) << 8 |
F_6 ( V_2 , 0x1e ) ) ;
F_7 ( L_31 , * V_124 ) ;
return 0 ;
}
static int F_30 ( struct V_53 * V_54 ,
T_4 * V_125 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
* V_125 = F_6 ( V_2 , 0x3b ) << 8 ;
F_7 ( L_32 , * V_125 ) ;
return 0 ;
}
static int F_31 ( struct V_53 * V_54 , T_4 * V_126 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
* V_126 = 65535 - ( ( ( T_4 ) F_6 ( V_2 , 0x18 ) << 8 ) |
( T_4 ) F_6 ( V_2 , 0x19 ) ) ;
F_7 ( L_33 , * V_126 ) ;
return 0 ;
}
static int F_32 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
struct V_55 * V_56 = & V_54 -> V_57 ;
F_7 ( L_30 ) ;
if ( V_2 -> V_95 -> V_127 )
V_2 -> V_95 -> V_127 ( V_54 , 0 ) ;
V_2 -> V_128 = V_56 -> V_85 ;
V_2 -> V_129 = V_56 -> V_80 ;
F_5 ( V_2 , V_56 -> V_19 ) ;
F_10 ( V_2 , V_56 -> V_130 ) ;
F_13 ( V_2 , V_56 -> V_80 ) ;
if ( ! V_2 -> V_95 -> V_97 )
F_21 ( V_54 ) ;
else if ( V_54 -> V_48 . V_115 . V_131 )
V_54 -> V_48 . V_115 . V_131 ( V_54 ) ;
else
V_12 ( L_34 ) ;
F_8 ( V_2 , 0x03 , ( F_6 ( V_2 , 0x03 ) | 0x07 ) ) ;
F_8 ( V_2 , 0x00 , 0x10 ) ;
F_8 ( V_2 , 0x00 , 0 ) ;
if ( V_2 -> V_95 -> V_132 )
V_2 -> V_95 -> V_132 ( V_54 ) ;
return 0 ;
}
static int F_33 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_54 -> V_57 ;
struct V_1 * V_2 = V_54 -> V_58 ;
F_7 ( L_30 ) ;
if ( F_9 ( V_2 , & V_56 -> V_19 ) != 0 ) {
V_12 ( L_35 , V_14 ) ;
return - V_90 ;
}
if ( F_11 ( V_2 , & V_56 -> V_130 ) != 0 ) {
V_12 ( L_36 , V_14 ) ;
return - V_90 ;
}
V_56 -> V_85 = V_2 -> V_128 ;
V_56 -> V_80 = V_2 -> V_129 ;
return 0 ;
}
static int F_34 ( struct V_53 * V_54 , enum V_133 V_105 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
T_1 V_26 ;
F_25 ( V_2 ) ;
V_26 = F_6 ( V_2 , 0x29 ) & ~ 0x40 ;
switch ( V_105 ) {
case V_134 :
F_7 ( L_37 ) ;
return F_8 ( V_2 , 0x29 , V_26 | 0x10 ) ;
case V_135 :
F_7 ( L_38 ) ;
return F_8 ( V_2 , 0x29 , V_26 & 0xef ) ;
default:
V_12 ( L_39 , V_105 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_35 ( struct V_53 * V_54 ,
bool V_136 ,
unsigned int V_137 ,
unsigned int * V_138 ,
enum V_111 * V_112 )
{
int V_139 = 0 ;
if ( V_136 )
V_139 = F_32 ( V_54 ) ;
if ( ! ( V_137 & V_140 ) )
F_28 ( V_54 , V_112 ) ;
* V_138 = V_141 / 10 ;
return V_139 ;
}
static int F_36 ( struct V_53 * V_54 )
{
return V_142 ;
}
static void F_37 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
F_7 ( L_30 ) ;
F_38 ( & V_2 -> V_143 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_144 * V_145 ,
struct V_7 V_8 [] , int V_146 )
{
struct V_1 * V_2 = F_41 ( V_145 ) ;
F_22 ( V_2 , 1 , 1 ) ;
return F_2 ( V_2 -> V_13 , V_8 , V_146 ) ;
}
static T_2 F_42 ( struct V_144 * V_147 )
{
return V_148 ;
}
struct V_144 *
F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_58 ;
return & V_2 -> V_143 ;
}
struct V_53 * F_44 ( const struct V_149 * V_95 ,
struct V_144 * V_13 )
{
struct V_1 * V_2 =
F_45 ( sizeof( struct V_1 ) , V_150 ) ;
F_7 ( L_30 ) ;
if ( V_2 == NULL ) {
V_12 ( L_40 ) ;
goto error;
}
V_2 -> V_95 = V_95 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_151 = F_6 ( V_2 , 0x00 ) ;
switch ( V_2 -> V_151 ) {
case 0xe1 :
V_49 ( L_41 ) ;
break;
case 0xd1 :
V_49 ( L_42 ) ;
break;
default:
V_12 ( L_43 , V_2 -> V_151 ) ;
goto error;
}
memcpy ( & V_2 -> V_47 . V_48 , & V_152 ,
sizeof( struct V_153 ) ) ;
V_2 -> V_47 . V_58 = V_2 ;
if ( V_95 -> V_97 )
F_22 ( V_2 , 1 , 0 ) ;
F_46 ( V_2 -> V_143 . V_154 , L_44 ,
sizeof( V_2 -> V_143 . V_154 ) ) ;
V_2 -> V_143 . V_155 = & V_156 ;
V_2 -> V_143 . V_157 = NULL ;
V_2 -> V_143 . V_158 . V_159 = V_13 -> V_158 . V_159 ;
F_47 ( & V_2 -> V_143 , V_2 ) ;
if ( F_48 ( & V_2 -> V_143 ) < 0 ) {
V_12 ( L_45 ) ;
goto error;
}
return & V_2 -> V_47 ;
error:
F_39 ( V_2 ) ;
return NULL ;
}
