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
T_2 V_18 )
{
T_1 V_19 = F_6 ( V_2 , 0x0e ) ;
T_1 V_20 = F_6 ( V_2 , 0x10 ) ;
switch ( V_18 ) {
case V_21 :
F_7 ( L_4 ) ;
F_8 ( V_2 , 0x0e , V_19 & ~ 0x80 ) ;
F_8 ( V_2 , 0x10 , V_20 | 0x80 ) ;
break;
case V_22 :
F_7 ( L_5 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x80 ) ;
F_8 ( V_2 , 0x10 , V_20 | 0x80 ) ;
break;
case V_23 :
F_7 ( L_6 ) ;
F_8 ( V_2 , 0x10 , V_20 & ~ 0x80 ) ;
break;
default:
return - V_24 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 * V_18 )
{
T_1 V_25 ;
V_25 = F_6 ( V_2 , 0x1b ) >> 7 ;
if ( V_25 == 0 ) {
F_7 ( L_7 ) ;
* V_18 = V_21 ;
} else {
F_7 ( L_8 ) ;
* V_18 = V_22 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_3 V_26 )
{
T_1 V_19 = F_6 ( V_2 , 0x0e ) & ~ 0x07 ;
if ( ( V_26 < V_27 ) || ( V_26 > V_28 ) )
V_26 = V_28 ;
if ( V_26 == V_29 )
F_8 ( V_2 , 0x43 ,
F_6 ( V_2 , 0x43 ) | 0x01 ) ;
else
F_8 ( V_2 , 0x43 ,
F_6 ( V_2 , 0x43 ) & ~ 0x01 ) ;
switch ( V_26 ) {
case V_29 :
F_7 ( L_9 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x01 ) ;
F_8 ( V_2 , 0x0f , 0x02 ) ;
break;
case V_30 :
F_7 ( L_10 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x02 ) ;
F_8 ( V_2 , 0x0f , 0x04 ) ;
break;
case V_31 :
F_7 ( L_11 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x03 ) ;
F_8 ( V_2 , 0x0f , 0x08 ) ;
break;
case V_32 :
F_7 ( L_12 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x04 ) ;
F_8 ( V_2 , 0x0f , 0x10 ) ;
break;
case V_33 :
F_7 ( L_13 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x05 ) ;
F_8 ( V_2 , 0x0f , 0x20 ) ;
break;
case V_34 :
F_7 ( L_14 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x06 ) ;
F_8 ( V_2 , 0x0f , 0x40 ) ;
break;
case V_35 :
F_7 ( L_15 ) ;
F_8 ( V_2 , 0x0e , V_19 | 0x07 ) ;
F_8 ( V_2 , 0x0f , 0x80 ) ;
break;
case V_28 :
F_7 ( L_16 ) ;
F_8 ( V_2 , 0x0f , 0xfe ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_3 * V_26 )
{
int V_15 ;
V_15 = F_6 ( V_2 , 0x1b ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_15 & 0x07 ;
switch ( V_15 ) {
case 1 :
* V_26 = V_29 ;
break;
case 2 :
* V_26 = V_30 ;
break;
case 3 :
* V_26 = V_31 ;
break;
case 4 :
* V_26 = V_32 ;
break;
case 5 :
* V_26 = V_33 ;
break;
case 6 :
* V_26 = V_34 ;
break;
case 7 :
* V_26 = V_35 ;
break;
default:
* V_26 = V_27 ;
}
return 0 ;
}
static T_4 F_12 ( T_4 V_37 , T_4 V_16 )
{
T_4 exp , V_38 = 0 ;
T_4 div = V_37 / V_16 ;
if ( V_37 % V_16 >= V_16 / 2 )
++ div ;
if ( div < ( 1 << 31 ) ) {
for ( exp = 1 ; div > exp ; V_38 ++ )
exp += exp ;
}
return V_38 ;
}
static int F_13 ( struct V_1 * V_2 , T_4 V_39 )
{
T_4 V_40 , V_41 , V_42 , V_43 ;
T_1 V_44 ;
if ( ( V_39 > V_2 -> V_45 . V_46 . V_47 . V_48 ) ||
( V_39 < V_2 -> V_45 . V_46 . V_47 . V_49 ) )
return - V_36 ;
if ( V_39 < ( V_50 * 2 ) / 2 )
V_44 = 2 ;
else if ( V_39 < ( V_50 * 3 ) / 2 )
V_44 = 3 ;
else if ( V_39 < ( V_50 * 4 ) / 2 )
V_44 = 4 ;
else if ( V_39 < ( V_50 * 5 ) / 2 )
V_44 = 5 ;
else if ( V_39 < ( V_50 * 6 ) / 2 )
V_44 = 6 ;
else if ( V_39 < ( V_50 * 7 ) / 2 )
V_44 = 7 ;
else if ( V_39 < ( V_50 * 8 ) / 2 )
V_44 = 8 ;
else
V_44 = 9 ;
V_41 = V_44 * V_50 ;
V_40 = V_39 << 6 ;
V_42 = V_40 / V_41 ;
V_40 = ( V_40 % V_41 ) << 6 ;
V_42 = ( V_42 << 6 ) + ( V_40 / V_41 ) ;
V_40 = ( V_40 % V_41 ) << 6 ;
V_42 = ( V_42 << 6 ) + ( V_40 / V_41 ) ;
V_40 = ( V_40 % V_41 ) << 5 ;
V_42 = ( V_42 << 5 ) + ( V_40 / V_41 ) ;
F_8 ( V_2 , 0x01 , V_44 * 6 ) ;
F_8 ( V_2 , 0x08 , ( V_42 >> 16 ) & 0x3f ) ;
F_8 ( V_2 , 0x09 , ( V_42 >> 8 ) & 0xff ) ;
F_8 ( V_2 , 0x0a , V_42 & 0xff ) ;
V_43 = F_12 ( V_41 , V_39 ) ;
V_40 = F_6 ( V_2 , 0x0c ) & ~ 0xe0 ;
F_8 ( V_2 , 0x0c , V_40 | V_43 << 5 ) ;
F_7 ( L_17 ,
V_39 , V_42 , V_41 , V_43 ) ;
return 0 ;
}
static int F_14 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_52 -> V_55 ;
struct V_1 * V_2 = V_52 -> V_56 ;
T_4 V_57 = 0 , V_58 = 0 , V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 2 ;
int V_62 = 0 ;
int V_63 = F_15 ( V_64 ) ;
struct V_65 * V_66 = NULL ;
struct V_67 * V_68 = NULL ;
V_2 -> V_69 = V_70 [ 0 ] . V_71 ;
V_2 -> V_72 = V_70 [ 0 ] . V_73 ;
V_2 -> V_74 = V_64 [ 0 ] . V_75 ;
V_59 = V_64 [ 0 ] . V_76 ;
for ( V_60 = 0 ; V_60 < F_15 ( V_70 ) ; V_60 ++ ) {
V_68 = & V_70 [ V_60 ] ;
if ( ( V_68 -> V_77 <= V_54 -> V_78 ) &&
( V_68 -> V_79 >= V_54 -> V_78 ) ) {
V_2 -> V_69 = V_68 -> V_71 ;
V_2 -> V_72 = V_68 -> V_73 ;
V_2 -> V_80 = V_68 -> V_80 ;
}
}
if ( V_81 < 1 || V_81 > V_63 ) {
for ( V_60 = 0 ; V_60 < V_63 ; V_60 ++ ) {
V_66 = & V_64 [ V_60 ] ;
if ( ( V_66 -> V_82 <= V_54 -> V_83 ) &&
( V_66 -> V_84 >= V_54 -> V_83 ) )
V_62 = V_60 ;
}
} else
V_62 = V_81 - 1 ;
V_2 -> V_74 = V_64 [ V_62 ] . V_75 ;
V_59 = V_64 [ V_62 ] . V_76 ;
if ( V_54 -> V_83 < ( V_64 [ V_62 ] . V_82 +
V_64 [ V_62 ] . V_84 ) / 2 )
V_61 = 0x01 ;
else
V_61 = 0x02 ;
V_57 = ( ( ( V_54 -> V_83 * V_59 * 10 ) /
( 2 * V_50 / 1000 ) ) / 32 ) & 0x1ff ;
V_58 = ( ( ( V_54 -> V_83 * V_59 * 10 ) /
( 2 * V_50 / 1000 ) ) % 32 ) & 0x1f ;
if ( V_58 == 0 && V_57 > 0 )
V_57 -- ;
V_2 -> V_85 = ( 3 << 19 ) | ( 3 << 17 ) | ( 1 << 16 ) |
( V_61 << 14 ) | ( V_57 << 5 ) | V_58 ;
return 0 ;
}
static int F_16 ( struct V_51 * V_52 , T_4 V_5 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
unsigned long V_86 ;
F_7 ( L_18 , V_5 ) ;
V_5 = V_5 << 3 ;
F_8 ( V_2 , 0x21 , 0x15 ) ;
V_86 = V_87 + F_17 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 >> 16 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x40 ) == 0 ) {
if ( F_18 ( V_87 , V_86 ) ) {
V_12 ( L_19\
L_20 , V_14 ) ;
return - V_88 ;
}
F_19 ( 10 ) ;
}
V_86 = V_87 + F_17 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 >> 8 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x40 ) == 0 ) {
if ( F_18 ( V_87 , V_86 ) ) {
V_12 ( L_19\
L_20 , V_14 ) ;
return - V_88 ;
}
F_19 ( 10 ) ;
}
V_86 = V_87 + F_17 ( 40 ) ;
F_8 ( V_2 , 0x22 , ( V_5 ) & 0xff ) ;
while ( ( F_6 ( V_2 , 0x20 ) & 0x80 ) ) {
if ( F_18 ( V_87 , V_86 ) ) {
V_12 ( L_21 \
L_20 , V_14 ) ;
return - V_88 ;
}
F_19 ( 10 ) ;
}
F_8 ( V_2 , 0x20 , F_6 ( V_2 , 0x20 ) | 2 ) ;
F_8 ( V_2 , 0x20 , F_6 ( V_2 , 0x20 ) & 0xfd ) ;
return 0 ;
}
static int F_20 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_52 -> V_55 ;
struct V_1 * V_2 = V_52 -> V_56 ;
T_1 V_25 ;
F_7 ( L_22 , V_54 -> V_83 ) ;
if ( F_14 ( V_52 ) != 0 ) {
V_12 ( L_23 , V_14 ) ;
return - V_24 ;
}
F_16 ( V_52 , V_2 -> V_69 ) ;
F_16 ( V_52 , V_2 -> V_72 ) ;
F_16 ( V_52 , V_2 -> V_74 ) ;
F_16 ( V_52 , V_2 -> V_85 ) ;
V_25 = F_6 ( V_2 , 0x28 ) & ~ 0x3 ;
F_8 ( V_2 , 0x27 , V_2 -> V_80 >> 2 ) ;
F_8 ( V_2 , 0x28 , V_25 | ( V_2 -> V_80 & 0x3 ) ) ;
F_7 ( L_24 , V_2 -> V_69 ,
V_2 -> V_74 , V_2 -> V_85 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_89 , T_1 V_90 )
{
T_1 V_91 = F_6 ( V_2 , 0x23 ) & 0x1e ;
if ( V_89 )
V_91 |= ( 1 << 6 ) | ( V_90 << 5 ) ;
else
V_91 |= ( 1 << 7 ) | ( V_90 ) ;
return F_8 ( V_2 , 0x23 , V_91 ) ;
}
static int F_22 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
int V_60 ;
F_7 ( L_25 ) ;
for ( V_60 = 0 ; V_60 < F_15 ( V_92 ) ; V_60 ++ )
F_8 ( V_2 , V_92 [ V_60 ] . V_4 ,
V_92 [ V_60 ] . V_5 ) ;
if ( V_2 -> V_93 -> V_94 )
F_8 ( V_2 , 0x32 ,
F_6 ( V_2 , 0x32 ) | 0x02 ) ;
if ( V_2 -> V_93 -> V_95 )
F_21 ( V_2 , 1 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_51 * V_52 ,
T_5 V_96 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
T_1 V_25 ;
V_25 = F_6 ( V_2 , 0x29 ) & ~ 0x40 ;
switch ( V_96 ) {
case V_97 :
F_7 ( L_26 ) ;
return F_8 ( V_2 , 0x29 , V_25 & 0x7f ) ;
case V_98 :
F_7 ( L_27 ) ;
return F_8 ( V_2 , 0x29 , V_25 | 0x80 ) ;
case V_99 :
return 0 ;
default:
return - V_24 ;
} ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_86 = V_87 + F_17 ( 200 ) ;
while ( ! ( F_6 ( V_2 , 0x29 ) & 0x40 ) ) {
if ( F_18 ( V_87 , V_86 ) ) {
V_12 ( L_28 \
L_29 , V_14 ) ;
break;
}
F_19 ( 10 ) ;
}
}
static int F_25 ( struct V_51 * V_52 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
int V_60 , V_25 , V_102 ;
F_7 ( L_30 ) ;
V_102 = F_6 ( V_2 , 0x29 ) ;
if ( V_102 & 0x10 )
F_8 ( V_2 , 0x29 , V_102 & ~ 0x50 ) ;
F_24 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) & 0xfb ) ;
for ( V_60 = 0 ; V_60 < V_101 -> V_103 ; V_60 ++ )
F_8 ( V_2 , 0x2C + V_60 , V_101 -> V_8 [ V_60 ] ) ;
V_25 = F_6 ( V_2 , 0x29 ) ;
F_8 ( V_2 , 0x29 , ( ( V_25 & 0x90 ) | 0x40 ) |
( ( V_101 -> V_103 - 3 ) & 3 ) ) ;
F_24 ( V_2 ) ;
if ( V_102 & 0x10 )
F_8 ( V_2 , 0x29 , V_102 & ~ 0x40 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_52 ,
T_6 V_104 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
int V_25 , V_102 ;
F_7 ( L_30 ) ;
V_102 = F_6 ( V_2 , 0x29 ) ;
if ( V_102 & 0x10 )
F_8 ( V_2 , 0x29 , V_102 & ~ 0x50 ) ;
F_24 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) | 0x4 ) ;
F_19 ( 30 ) ;
V_25 = F_6 ( V_2 , 0x29 ) ;
if ( V_104 == V_105 )
F_8 ( V_2 , 0x29 , ( ( V_25 & 0x90 ) | 0x40 | 0x00 ) ) ;
else if ( V_104 == V_106 )
F_8 ( V_2 , 0x29 , ( ( V_25 & 0x90 ) | 0x40 | 0x08 ) ) ;
else
return - V_24 ;
F_24 ( V_2 ) ;
F_8 ( V_2 , 0x2a , F_6 ( V_2 , 0x2a ) & 0xfb ) ;
if ( V_102 & 0x10 )
F_8 ( V_2 , 0x29 , V_102 & ~ 0x40 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_52 , T_7 * V_107 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
int V_108 = F_6 ( V_2 , 0x14 ) ;
* V_107 = 0 ;
if ( V_2 -> V_93 -> V_95 ) {
T_4 V_109 = 0 ;
if ( V_52 -> V_46 . V_110 . V_111 )
V_52 -> V_46 . V_110 . V_111 ( V_52 , & V_109 ) ;
if ( V_109 & V_112 )
* V_107 |= V_113 ;
} else {
int V_114 = F_6 ( V_2 , 0x20 ) ;
if ( V_114 & 0x01 )
* V_107 |= V_113 ;
}
if ( V_108 & 0x02 )
* V_107 |= V_115 ;
if ( V_108 & 0x04 )
* V_107 |= V_116 ;
if ( V_108 & 0x08 )
* V_107 |= V_117 ;
if ( V_108 & 0x80 )
* V_107 |= V_118 ;
return 0 ;
}
static int F_28 ( struct V_51 * V_52 , T_4 * V_119 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
* V_119 = ( ( F_6 ( V_2 , 0x1c ) & 0x3f ) << 16 ) |
( F_6 ( V_2 , 0x1d ) << 8 |
F_6 ( V_2 , 0x1e ) ) ;
F_7 ( L_31 , * V_119 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_52 ,
T_8 * V_120 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
* V_120 = F_6 ( V_2 , 0x3b ) << 8 ;
F_7 ( L_32 , * V_120 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 , T_8 * V_121 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
* V_121 = 65535 - ( ( ( T_8 ) F_6 ( V_2 , 0x18 ) << 8 ) |
( T_8 ) F_6 ( V_2 , 0x19 ) ) ;
F_7 ( L_33 , * V_121 ) ;
return 0 ;
}
static int F_31 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
struct V_53 * V_54 = & V_52 -> V_55 ;
F_7 ( L_30 ) ;
if ( V_2 -> V_93 -> V_122 )
V_2 -> V_93 -> V_122 ( V_52 , 0 ) ;
V_2 -> V_123 = V_54 -> V_83 ;
V_2 -> V_124 = V_54 -> V_78 ;
F_5 ( V_2 , V_54 -> V_18 ) ;
F_10 ( V_2 , V_54 -> V_125 ) ;
F_13 ( V_2 , V_54 -> V_78 ) ;
if ( ! V_2 -> V_93 -> V_95 )
F_20 ( V_52 ) ;
else if ( V_52 -> V_46 . V_110 . V_126 )
V_52 -> V_46 . V_110 . V_126 ( V_52 ) ;
else
V_12 ( L_34 ) ;
F_8 ( V_2 , 0x03 , ( F_6 ( V_2 , 0x03 ) | 0x07 ) ) ;
F_8 ( V_2 , 0x00 , 0x10 ) ;
F_8 ( V_2 , 0x00 , 0 ) ;
if ( V_2 -> V_93 -> V_127 )
V_2 -> V_93 -> V_127 ( V_52 ) ;
return 0 ;
}
static int F_32 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_52 -> V_55 ;
struct V_1 * V_2 = V_52 -> V_56 ;
F_7 ( L_30 ) ;
if ( F_9 ( V_2 , & V_54 -> V_18 ) != 0 ) {
V_12 ( L_35 , V_14 ) ;
return - V_88 ;
}
if ( F_11 ( V_2 , & V_54 -> V_125 ) != 0 ) {
V_12 ( L_36 , V_14 ) ;
return - V_88 ;
}
V_54 -> V_83 = V_2 -> V_123 ;
V_54 -> V_78 = V_2 -> V_124 ;
return 0 ;
}
static int F_33 ( struct V_51 * V_52 , T_9 V_102 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
T_1 V_25 ;
F_24 ( V_2 ) ;
V_25 = F_6 ( V_2 , 0x29 ) & ~ 0x40 ;
switch ( V_102 ) {
case V_128 :
F_7 ( L_37 ) ;
return F_8 ( V_2 , 0x29 , V_25 | 0x10 ) ;
case V_129 :
F_7 ( L_38 ) ;
return F_8 ( V_2 , 0x29 , V_25 & 0xef ) ;
default:
V_12 ( L_39 , V_102 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_34 ( struct V_51 * V_52 ,
bool V_130 ,
unsigned int V_131 ,
unsigned int * V_132 ,
T_7 * V_107 )
{
int V_133 = 0 ;
if ( V_130 )
V_133 = F_31 ( V_52 ) ;
if ( ! ( V_131 & V_134 ) )
F_27 ( V_52 , V_107 ) ;
* V_132 = V_135 / 10 ;
return V_133 ;
}
static int F_35 ( struct V_51 * V_52 )
{
return 1 ;
}
static void F_36 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
F_7 ( L_30 ) ;
F_37 ( & V_2 -> V_136 ) ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_137 * V_138 ,
struct V_7 V_8 [] , int V_139 )
{
struct V_1 * V_2 = F_40 ( V_138 ) ;
F_21 ( V_2 , 1 , 1 ) ;
return F_2 ( V_2 -> V_13 , V_8 , V_139 ) ;
}
static T_4 F_41 ( struct V_137 * V_140 )
{
return V_141 ;
}
struct V_137 *
F_42 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_56 ;
return & V_2 -> V_136 ;
}
struct V_51 * F_43 ( const struct V_142 * V_93 ,
struct V_137 * V_13 )
{
struct V_1 * V_2 =
F_44 ( sizeof( struct V_1 ) , V_143 ) ;
F_7 ( L_30 ) ;
if ( V_2 == NULL ) {
V_12 ( L_40 ) ;
goto error;
}
V_2 -> V_93 = V_93 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_144 = F_6 ( V_2 , 0x00 ) ;
switch ( V_2 -> V_144 ) {
case 0xe1 :
V_47 ( L_41 ) ;
break;
case 0xd1 :
V_47 ( L_42 ) ;
break;
default:
V_12 ( L_43 , V_2 -> V_144 ) ;
goto error;
}
memcpy ( & V_2 -> V_45 . V_46 , & V_145 ,
sizeof( struct V_146 ) ) ;
V_2 -> V_45 . V_56 = V_2 ;
if ( V_93 -> V_95 )
F_21 ( V_2 , 1 , 0 ) ;
F_45 ( V_2 -> V_136 . V_147 , L_44 ,
sizeof( V_2 -> V_136 . V_147 ) ) ;
V_2 -> V_136 . V_148 = & V_149 ;
V_2 -> V_136 . V_150 = NULL ;
F_46 ( & V_2 -> V_136 , V_2 ) ;
if ( F_47 ( & V_2 -> V_136 ) < 0 ) {
V_12 ( L_45 ) ;
goto error;
}
return & V_2 -> V_45 ;
error:
F_38 ( V_2 ) ;
return NULL ;
}
