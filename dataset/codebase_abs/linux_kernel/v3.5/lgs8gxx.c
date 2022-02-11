static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = 0 , . V_6 = V_6 , . V_10 = 2 } ;
V_8 . V_11 = V_2 -> V_12 -> V_13 ;
if ( V_2 -> V_12 -> V_14 != V_15 && V_3 >= 0xC0 )
V_8 . V_11 += 0x02 ;
if ( V_16 >= 2 )
F_2 ( L_1 , V_17 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_18 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_2 ( L_2 ,
V_17 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_19 )
{
int V_5 ;
T_1 V_20 ;
T_1 V_21 [] = { V_3 } ;
T_1 V_22 [] = { 0 } ;
struct V_7 V_8 [] = {
{ . V_9 = 0 , . V_6 = V_21 , . V_10 = 1 } ,
{ . V_9 = V_23 , . V_6 = V_22 , . V_10 = 1 } ,
} ;
V_20 = V_2 -> V_12 -> V_13 ;
if ( V_2 -> V_12 -> V_14 != V_15 && V_3 >= 0xC0 )
V_20 += 0x02 ;
V_8 [ 1 ] . V_11 = V_8 [ 0 ] . V_11 = V_20 ;
V_5 = F_3 ( V_2 -> V_18 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_2 ( L_3 , V_17 , V_3 , V_5 ) ;
return - 1 ;
}
* V_19 = V_22 [ 0 ] ;
if ( V_16 >= 2 )
F_2 ( L_1 , V_17 , V_3 , V_22 [ 0 ] ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x02 , 0x00 ) ;
F_6 ( 1 ) ;
F_1 ( V_2 , 0x02 , 0x01 ) ;
F_6 ( 100 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_24 ,
T_1 V_25 , T_1 V_26 , T_1 V_27 )
{
T_1 V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_27 ; V_29 ++ ) {
F_4 ( V_2 , V_3 , & V_28 ) ;
if ( ( V_28 & V_24 ) == V_25 )
return 0 ;
F_6 ( V_26 ) ;
}
return 1 ;
}
static int F_8 ( struct V_1 * V_2 )
{
const struct V_30 * V_12 = V_2 -> V_12 ;
T_1 V_31 ;
V_31 = 0x10 ;
V_31 |=
( ( V_12 -> V_32 ) ? 0x80 : 0x00 ) |
( ( V_12 -> V_33 ) ? 0x04 : 0x00 ) |
( ( V_12 -> V_34 == 0 ) ? 0x08 : 0x00 ) |
( ( V_12 -> V_35 ) ? 0x02 : 0x00 ) |
( ( V_12 -> V_36 ) ? 0x01 : 0x00 ) ;
if ( V_12 -> V_32 &&
( V_12 -> V_14 == V_37 ) ) {
F_1 ( V_2 , 0xBA , 0x40 ) ;
}
F_1 ( V_2 , 0x07 , V_31 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_38 )
{
T_3 V_25 ;
T_2 V_39 ;
T_2 V_40 ;
V_40 = V_2 -> V_12 -> V_41 ;
V_25 = V_38 ;
if ( V_38 != 0 ) {
V_25 <<= 32 ;
if ( V_40 != 0 )
F_10 ( V_25 , V_40 ) ;
V_39 = V_25 & 0xFFFFFFFF ;
F_2 ( L_4 , V_38 ) ;
} else {
V_39 = 0 ;
F_2 ( L_5 ) ;
}
F_2 ( L_6 , V_39 ) ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
F_1 ( V_2 , 0x08 , 0xFF & ( V_39 ) ) ;
F_1 ( V_2 , 0x09 , 0xFF & ( V_39 >> 8 ) ) ;
F_1 ( V_2 , 0x0A , 0xFF & ( V_39 >> 16 ) ) ;
F_1 ( V_2 , 0x0B , 0xFF & ( V_39 >> 24 ) ) ;
} else {
F_1 ( V_2 , 0x09 , 0xFF & ( V_39 ) ) ;
F_1 ( V_2 , 0x0A , 0xFF & ( V_39 >> 8 ) ) ;
F_1 ( V_2 , 0x0B , 0xFF & ( V_39 >> 16 ) ) ;
F_1 ( V_2 , 0x0C , 0xFF & ( V_39 >> 24 ) ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_3 V_25 ;
T_2 V_39 = 0 ;
T_1 V_42 , V_28 ;
int V_29 ;
if ( V_2 -> V_12 -> V_14 == V_15 )
V_42 = 0x23 ;
else
V_42 = 0x48 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
F_4 ( V_2 , V_42 , & V_28 ) ;
V_39 <<= 8 ;
V_39 |= V_28 ;
V_42 -- ;
}
V_25 = V_39 ;
V_25 *= V_2 -> V_12 -> V_41 ;
V_25 >>= 32 ;
F_2 ( L_7 , ( T_2 ) V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_28 ;
T_1 V_14 = V_2 -> V_12 -> V_14 ;
if ( V_14 == V_43 )
F_1 ( V_2 , 0xC6 , 0x01 ) ;
if ( V_14 == V_15 ) {
F_4 ( V_2 , 0x0C , & V_28 ) ;
V_28 &= ( ~ 0x04 ) ;
F_1 ( V_2 , 0x0C , V_28 | 0x80 ) ;
F_1 ( V_2 , 0x39 , 0x00 ) ;
F_1 ( V_2 , 0x3D , 0x04 ) ;
} else if ( V_14 == V_43 ||
V_14 == V_44 ||
V_14 == V_45 ||
V_14 == V_37 ||
V_14 == V_46 ) {
F_4 ( V_2 , 0x7E , & V_28 ) ;
F_1 ( V_2 , 0x7E , V_28 | 0x01 ) ;
F_4 ( V_2 , 0xC5 , & V_28 ) ;
F_1 ( V_2 , 0xC5 , V_28 & 0xE0 ) ;
}
if ( V_14 == V_43 ) {
F_1 ( V_2 , 0xC1 , 0x03 ) ;
F_4 ( V_2 , 0x7C , & V_28 ) ;
V_28 = ( V_28 & 0x8C ) | 0x03 ;
F_1 ( V_2 , 0x7C , V_28 ) ;
F_4 ( V_2 , 0xC3 , & V_28 ) ;
V_28 = ( V_28 & 0xEF ) | 0x10 ;
F_1 ( V_2 , 0xC3 , V_28 ) ;
}
if ( V_2 -> V_12 -> V_14 == V_37 )
F_1 ( V_2 , 0xD9 , 0x40 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_28 ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
T_1 V_47 ;
F_4 ( V_2 , 0x0C , & V_28 ) ;
V_28 &= ( ~ 0x80 ) ;
F_1 ( V_2 , 0x0C , V_28 ) ;
F_4 ( V_2 , 0x0C , & V_28 ) ;
F_4 ( V_2 , 0x19 , & V_47 ) ;
if ( ( ( V_28 & 0x03 ) == 0x01 ) && ( V_47 & 0x01 ) ) {
F_1 ( V_2 , 0x6E , 0x05 ) ;
F_1 ( V_2 , 0x39 , 0x02 ) ;
F_1 ( V_2 , 0x39 , 0x03 ) ;
F_1 ( V_2 , 0x3D , 0x05 ) ;
F_1 ( V_2 , 0x3E , 0x28 ) ;
F_1 ( V_2 , 0x53 , 0x80 ) ;
} else {
F_1 ( V_2 , 0x6E , 0x3F ) ;
F_1 ( V_2 , 0x39 , 0x00 ) ;
F_1 ( V_2 , 0x3D , 0x04 ) ;
}
F_5 ( V_2 ) ;
return 0 ;
}
F_1 ( V_2 , 0x7E , 0 ) ;
if ( V_2 -> V_12 -> V_14 == V_43 )
F_1 ( V_2 , 0xC1 , 0 ) ;
F_4 ( V_2 , 0xC5 , & V_28 ) ;
V_28 = ( V_28 & 0xE0 ) | 0x06 ;
F_1 ( V_2 , 0xC5 , V_28 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_48 )
{
int V_5 = 0 ;
T_1 V_28 ;
if ( V_2 -> V_12 -> V_14 == V_15 )
V_5 = F_4 ( V_2 , 0x13 , & V_28 ) ;
else
V_5 = F_4 ( V_2 , 0x4B , & V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
if ( V_2 -> V_12 -> V_14 == V_15 )
* V_48 = ( ( V_28 & 0x80 ) == 0x80 ) ? 1 : 0 ;
else
* V_48 = ( ( V_28 & 0xC0 ) == 0xC0 ) ? 1 : 0 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_48 )
{
int V_5 = 0 ;
T_1 V_3 , V_24 , V_25 ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
V_3 = 0x13 ;
V_24 = 0x80 ;
V_25 = 0x80 ;
} else {
V_3 = 0x4B ;
V_24 = 0xC0 ;
V_25 = 0xC0 ;
}
V_5 = F_7 ( V_2 , V_3 , V_24 , V_25 , 50 , 40 ) ;
* V_48 = ( V_5 == 0 ) ? 1 : 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 * V_49 )
{
int V_5 = 0 ;
T_1 V_3 , V_24 , V_25 ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
V_3 = 0x1f ;
V_24 = 0xC0 ;
V_25 = 0x80 ;
} else {
V_3 = 0xA4 ;
V_24 = 0x03 ;
V_25 = 0x01 ;
}
V_5 = F_7 ( V_2 , V_3 , V_24 , V_25 , 10 , 20 ) ;
* V_49 = ( V_5 == 0 ) ? 1 : 0 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_50 , T_1 V_51 ,
T_1 * V_48 )
{
int V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 , V_47 ;
if ( V_50 == V_55 )
F_2 ( L_8 ) ;
else if ( V_50 == V_56 )
F_2 ( L_9 ) ;
else if ( V_50 == V_57 )
F_2 ( L_10 ) ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
F_4 ( V_2 , 0x0C , & V_54 ) ;
F_4 ( V_2 , 0x18 , & V_47 ) ;
V_54 &= ~ ( V_58 ) ;
V_54 |= V_50 ;
V_47 &= 0xFE ;
V_47 |= V_51 ? 0x01 : 0x00 ;
F_1 ( V_2 , 0x0C , V_54 ) ;
F_1 ( V_2 , 0x18 , V_47 ) ;
} else {
F_1 ( V_2 , 0x04 , V_50 ) ;
}
F_5 ( V_2 ) ;
V_52 = F_15 ( V_2 , V_48 ) ;
if ( V_52 || ! ( * V_48 ) )
return V_52 ;
V_52 = F_16 ( V_2 , & V_53 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_53 ) {
F_2 ( L_11 ) ;
} else
* V_48 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 * V_59 , T_1 * V_50 )
{
int V_29 , V_60 ;
int V_52 = 0 ;
T_1 V_48 = 0 , V_61 ;
F_2 ( L_12 , V_17 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
F_1 ( V_2 , 0x67 , 0xAA ) ;
F_1 ( V_2 , 0x6E , 0x3F ) ;
} else {
F_1 ( V_2 , 0x03 , 00 ) ;
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
V_61 = V_55 ;
V_52 = F_17 ( V_2 , V_55 , V_60 , & V_48 ) ;
if ( V_52 )
goto V_62;
if ( V_48 )
goto V_48;
}
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
V_61 = V_57 ;
V_52 = F_17 ( V_2 , V_57 , V_60 , & V_48 ) ;
if ( V_52 )
goto V_62;
if ( V_48 )
goto V_48;
}
V_61 = V_56 ;
V_52 = F_17 ( V_2 , V_56 , 1 , & V_48 ) ;
if ( V_52 )
goto V_62;
if ( V_48 )
goto V_48;
}
V_48:
if ( ( V_52 == 0 ) && ( V_48 == 1 ) ) {
T_1 V_28 ;
if ( V_2 -> V_12 -> V_14 != V_15 ) {
F_4 ( V_2 , 0xA2 , & V_28 ) ;
* V_59 = V_28 ;
} else {
F_4 ( V_2 , 0x1F , & V_28 ) ;
* V_59 = V_28 & 0x3F ;
}
if ( V_61 == V_55 )
F_2 ( L_13 ) ;
else if ( V_61 == V_56 )
F_2 ( L_14 ) ;
else if ( V_61 == V_57 )
F_2 ( L_15 ) ;
* V_50 = V_61 ;
}
if ( ! V_48 )
V_52 = - 1 ;
V_62:
return V_52 ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_4 V_52 ;
T_1 V_50 = 0x2 ;
T_1 V_59 = 0 ;
V_52 = F_18 ( V_2 , & V_59 , & V_50 ) ;
if ( V_52 != 0 ) {
F_2 ( L_16 ) ;
} else
F_2 ( L_17 , V_59 ) ;
if ( V_2 -> V_12 -> V_14 == V_43 ) {
T_1 V_63 = V_59 & V_64 ;
V_63 = ( V_63 == V_65 ) ? 0x60 : 0x40 ;
V_59 &= V_66 | V_67 | V_68 ;
V_59 |= V_63 ;
}
if ( V_2 -> V_12 -> V_14 == V_15 ) {
T_1 V_28 ;
F_4 ( V_2 , 0x19 , & V_28 ) ;
V_28 &= 0x81 ;
V_28 |= V_59 << 1 ;
F_1 ( V_2 , 0x19 , V_28 ) ;
} else {
F_1 ( V_2 , 0x7D , V_59 ) ;
if ( V_2 -> V_12 -> V_14 == V_43 )
F_1 ( V_2 , 0xC0 , V_59 ) ;
}
F_13 ( V_2 ) ;
switch ( V_50 ) {
case V_55 :
V_2 -> V_69 = 945 ; break;
case V_56 :
V_2 -> V_69 = 595 ; break;
case V_57 :
V_2 -> V_69 = 420 ; break;
default:
V_2 -> V_69 = 945 ; break;
}
}
static int F_20 ( struct V_1 * V_2 ,
T_1 V_70 , T_1 V_71 , T_1 V_72 )
{
int V_5 = 0 ;
T_1 V_28 , V_42 ;
V_42 = ( V_2 -> V_12 -> V_14 == V_15 ) ? 0x30 : 0xC2 ;
V_5 = F_4 ( V_2 , V_42 , & V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
V_28 &= 0xF8 ;
V_28 |= V_70 ? V_73 : V_74 ;
V_28 |= V_71 ? V_75 : V_76 ;
V_28 |= V_72 ? V_77 : V_78 ;
V_5 = F_1 ( V_2 , V_42 , V_28 ) ;
if ( V_5 != 0 )
return V_5 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_79 )
{
T_1 V_80 = 0x73 , V_81 = 0x90 ;
if ( V_2 -> V_12 -> V_14 != V_15 )
return 0 ;
V_80 |= ( V_79 & 0x01 ) << 7 ;
V_81 |= ( V_79 & 0x02 ) >> 1 ;
F_1 ( V_2 , 0x26 , V_80 ) ;
F_1 ( V_2 , 0x27 , V_81 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_1 V_28 ;
F_1 ( V_2 , 0xc1 , 0x3 ) ;
F_4 ( V_2 , 0x7c , & V_28 ) ;
F_1 ( V_2 , 0x7c , ( V_28 & 0x8c ) | 0x3 ) ;
F_4 ( V_2 , 0xc3 , & V_28 ) ;
F_1 ( V_2 , 0xc3 , V_28 & 0x10 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
const struct V_82 * V_83 ;
int V_84 ;
int V_29 ;
V_84 = F_24 ( & V_83 , L_18 , & V_2 -> V_18 -> V_85 ) ;
if ( V_84 )
return V_84 ;
F_1 ( V_2 , 0xC6 , 0x40 ) ;
F_1 ( V_2 , 0x3D , 0x04 ) ;
F_1 ( V_2 , 0x39 , 0x00 ) ;
F_1 ( V_2 , 0x3A , 0x00 ) ;
F_1 ( V_2 , 0x38 , 0x00 ) ;
F_1 ( V_2 , 0x3B , 0x00 ) ;
F_1 ( V_2 , 0x38 , 0x00 ) ;
for ( V_29 = 0 ; V_29 < V_83 -> V_86 ; V_29 ++ ) {
F_1 ( V_2 , 0x38 , 0x00 ) ;
F_1 ( V_2 , 0x3A , ( T_1 ) ( V_29 & 0xff ) ) ;
F_1 ( V_2 , 0x3B , ( T_1 ) ( V_29 >> 8 ) ) ;
F_1 ( V_2 , 0x3C , V_83 -> V_4 [ V_29 ] ) ;
}
F_1 ( V_2 , 0x38 , 0x00 ) ;
F_25 ( V_83 ) ;
return 0 ;
}
static int F_26 ( struct V_87 * V_88 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_88 -> V_89 ;
const struct V_30 * V_12 = V_2 -> V_12 ;
T_1 V_4 = 0 ;
T_4 V_52 ;
F_2 ( L_12 , V_17 ) ;
F_4 ( V_2 , 0 , & V_4 ) ;
F_2 ( L_19 , V_4 ) ;
if ( V_12 -> V_14 == V_15 )
F_21 ( V_2 , V_12 -> V_90 ) ;
V_52 = F_20 ( V_2 , V_12 -> V_91 ,
V_12 -> V_92 ,
V_12 -> V_93 ) ;
if ( V_52 != 0 )
return - V_94 ;
if ( V_12 -> V_14 == V_43 )
F_22 ( V_2 ) ;
F_9 ( V_2 , V_2 -> V_12 -> V_34 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_87 * V_88 )
{
struct V_1 * V_95 = V_88 -> V_89 ;
F_2 ( L_12 , V_17 ) ;
F_28 ( V_95 ) ;
}
static int F_29 ( struct V_87 * V_88 , const T_1 V_6 [] , int V_10 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
if ( V_10 != 2 )
return - V_96 ;
return F_1 ( V_2 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
}
static int F_30 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
F_2 ( L_12 , V_17 ) ;
if ( V_88 -> V_97 . V_98 . V_99 ) {
V_88 -> V_97 . V_98 . V_99 ( V_88 ) ;
if ( V_88 -> V_97 . V_100 )
V_88 -> V_97 . V_100 ( V_88 , 0 ) ;
}
F_19 ( V_2 ) ;
F_6 ( 10 ) ;
return 0 ;
}
static int F_31 ( struct V_87 * V_88 )
{
struct V_101 * V_102 = & V_88 -> V_103 ;
F_2 ( L_12 , V_17 ) ;
V_102 -> V_104 = V_105 ;
V_102 -> V_106 = 8000000 ;
V_102 -> V_107 = V_108 ;
V_102 -> V_109 = V_108 ;
V_102 -> V_110 = V_111 ;
V_102 -> V_112 = V_113 ;
V_102 -> V_114 = V_115 ;
V_102 -> V_116 = V_117 ;
return 0 ;
}
static
int F_32 ( struct V_87 * V_88 ,
struct V_118 * V_119 )
{
V_119 -> V_120 = 800 ;
V_119 -> V_121 = 0 ;
V_119 -> V_122 = 0 ;
return 0 ;
}
static int F_33 ( struct V_87 * V_88 , T_5 * V_123 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
T_4 V_5 ;
T_1 V_28 , V_48 = 0 ;
F_2 ( L_12 , V_17 ) ;
* V_123 = 0 ;
F_11 ( V_2 ) ;
F_14 ( V_2 , & V_48 ) ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
if ( V_48 )
* V_123 |= V_124 | V_125 |
V_126 | V_127 | V_128 ;
return 0 ;
}
V_5 = F_4 ( V_2 , 0x4B , & V_28 ) ;
if ( V_5 != 0 )
return - V_94 ;
F_2 ( L_20 , V_28 ) ;
* V_123 = 0 ;
if ( V_2 -> V_12 -> V_14 == V_43 ) {
if ( ( V_28 & 0x40 ) == 0x40 )
* V_123 |= V_124 | V_125 ;
if ( ( V_28 & 0x80 ) == 0x80 )
* V_123 |= V_126 | V_127 |
V_128 ;
} else {
if ( ( V_28 & 0x80 ) == 0x80 )
* V_123 |= V_124 | V_125 |
V_126 | V_127 | V_128 ;
}
F_2 ( L_21 , V_17 , * V_123 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_6 * signal )
{
T_6 V_129 ;
T_1 V_130 [ 2 ] , V_131 ;
F_2 ( L_22 , V_17 ) ;
F_4 ( V_2 , 0x3F , & V_130 [ 0 ] ) ;
F_4 ( V_2 , 0x3E , & V_130 [ 1 ] ) ;
V_129 = V_130 [ 0 ] ;
V_129 <<= 8 ;
V_129 |= V_130 [ 1 ] ;
F_2 ( L_23 , V_129 ) ;
if ( V_129 < 0x100 )
V_131 = 0 ;
else if ( V_129 < 0x190 )
V_131 = 5 ;
else if ( V_129 < 0x2A8 )
V_131 = 4 ;
else if ( V_129 < 0x381 )
V_131 = 3 ;
else if ( V_129 < 0x400 )
V_131 = 2 ;
else if ( V_129 == 0x400 )
V_131 = 1 ;
else
V_131 = 0 ;
* signal = V_131 * 65535 / 5 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_6 * signal )
{
T_1 V_28 ; T_4 V_5 ;
T_7 V_132 = 0 ;
T_1 V_133 ;
T_6 V_29 , V_50 = V_2 -> V_69 ;
F_2 ( L_12 , V_17 ) ;
V_5 = F_4 ( V_2 , 0x4B , & V_28 ) ;
if ( V_5 != 0 )
return - V_94 ;
if ( V_134 ) {
if ( ( V_28 & 0xC0 ) == 0xC0 ) {
F_2 ( L_24 ) ;
* signal = 0x7FFF ;
} else
* signal = 0 ;
return 0 ;
}
F_2 ( L_25 , V_50 ) ;
for ( V_29 = 0 ; V_29 < V_50 ; V_29 ++ ) {
if ( ( V_29 & 0xFF ) == 0 )
F_1 ( V_2 , 0x84 , 0x03 & ( V_29 >> 8 ) ) ;
F_1 ( V_2 , 0x83 , V_29 & 0xFF ) ;
F_4 ( V_2 , 0x94 , & V_133 ) ;
if ( V_132 < V_133 )
V_132 = V_133 ;
}
* signal = V_132 ;
F_2 ( L_26 , V_17 , * signal ) ;
F_4 ( V_2 , 0x95 , & V_28 ) ;
F_2 ( L_27 , V_17 , V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , T_6 * signal )
{
T_1 V_28 ;
T_7 V_129 = 0 ;
F_2 ( L_12 , V_17 ) ;
F_4 ( V_2 , 0xB1 , & V_28 ) ;
V_129 |= V_28 ;
V_129 <<= 8 ;
F_4 ( V_2 , 0xB0 , & V_28 ) ;
V_129 |= V_28 ;
* signal = V_129 ;
F_2 ( L_26 , V_17 , * signal ) ;
return 0 ;
}
static int F_37 ( struct V_87 * V_88 , T_6 * signal )
{
struct V_1 * V_2 = V_88 -> V_89 ;
if ( V_2 -> V_12 -> V_14 == V_43 )
return F_35 ( V_2 , signal ) ;
else if ( V_2 -> V_12 -> V_14 == V_15 )
return F_36 ( V_2 , signal ) ;
else
return F_34 ( V_2 , signal ) ;
}
static int F_38 ( struct V_87 * V_88 , T_6 * V_135 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
T_1 V_28 ;
* V_135 = 0 ;
if ( V_2 -> V_12 -> V_14 == V_15 )
F_4 ( V_2 , 0x34 , & V_28 ) ;
else
F_4 ( V_2 , 0x95 , & V_28 ) ;
F_2 ( L_28 , V_28 ) ;
* V_135 = 256 - V_28 ;
* V_135 <<= 8 ;
F_2 ( L_29 , * V_135 ) ;
return 0 ;
}
static int F_39 ( struct V_87 * V_88 , T_2 * V_136 )
{
* V_136 = 0 ;
F_2 ( L_30 , V_17 , * V_136 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_137 , V_28 ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
F_4 ( V_2 , 0x30 , & V_137 ) ;
V_137 &= 0xE7 ;
V_28 = V_137 | 0x10 ;
F_1 ( V_2 , 0x30 , V_28 ) ;
V_28 = V_137 | 0x18 ;
F_1 ( V_2 , 0x30 , V_28 ) ;
V_28 = V_137 | 0x10 ;
F_1 ( V_2 , 0x30 , V_28 ) ;
} else {
F_1 ( V_2 , 0xC6 , 0x01 ) ;
F_1 ( V_2 , 0xC6 , 0x41 ) ;
F_1 ( V_2 , 0xC6 , 0x01 ) ;
}
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_28 ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
F_4 ( V_2 , 0x30 , & V_28 ) ;
V_28 &= 0xE7 ;
F_1 ( V_2 , 0x30 , V_28 ) ;
} else {
F_1 ( V_2 , 0xC6 , 0x81 ) ;
}
}
static int F_42 ( struct V_87 * V_88 , T_2 * V_138 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
T_1 V_139 , V_140 , V_28 ;
T_2 V_141 = 0 , V_142 = 0 ;
int V_29 ;
F_2 ( L_12 , V_17 ) ;
F_40 ( V_2 ) ;
F_6 ( 200 ) ;
F_41 ( V_2 ) ;
if ( V_2 -> V_12 -> V_14 == V_15 ) {
V_140 = 0x28 ; V_139 = 0x2C ;
} else {
V_140 = 0xD0 ; V_139 = 0xD4 ;
}
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_141 <<= 8 ;
F_4 ( V_2 , V_140 + 3 - V_29 , & V_28 ) ;
V_141 |= V_28 ;
}
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_142 <<= 8 ;
F_4 ( V_2 , V_139 + 3 - V_29 , & V_28 ) ;
V_142 |= V_28 ;
}
F_2 ( L_31 , V_142 , V_141 ) ;
if ( V_141 == 0 )
* V_138 = 0 ;
else
* V_138 = V_142 * 100 / V_141 ;
F_2 ( L_32 , V_17 , * V_138 ) ;
return 0 ;
}
static int F_43 ( struct V_87 * V_88 , int V_143 )
{
struct V_1 * V_2 = V_88 -> V_89 ;
if ( V_2 -> V_12 -> V_144 == 0 )
return 0 ;
if ( V_143 ) {
T_1 V_129 = 0x80 | V_2 -> V_12 -> V_144 ;
return F_1 ( V_2 , 0x01 , V_129 ) ;
}
return F_1 ( V_2 , 0x01 , 0 ) ;
}
struct V_87 * F_44 ( const struct V_30 * V_12 ,
struct V_145 * V_18 )
{
struct V_1 * V_2 = NULL ;
T_1 V_4 = 0 ;
F_2 ( L_22 , V_17 ) ;
if ( V_12 == NULL || V_18 == NULL )
return NULL ;
V_2 = F_45 ( sizeof( struct V_1 ) , V_146 ) ;
if ( V_2 == NULL )
goto V_147;
V_2 -> V_12 = V_12 ;
V_2 -> V_18 = V_18 ;
if ( F_4 ( V_2 , 0 , & V_4 ) != 0 ) {
F_2 ( L_33 ,
V_17 , V_2 -> V_12 -> V_13 ) ;
goto V_147;
}
F_4 ( V_2 , 1 , & V_4 ) ;
memcpy ( & V_2 -> V_148 . V_97 , & V_149 ,
sizeof( struct V_150 ) ) ;
V_2 -> V_148 . V_89 = V_2 ;
if ( V_12 -> V_14 == V_15 )
F_23 ( V_2 ) ;
return & V_2 -> V_148 ;
V_147:
F_2 ( L_34 , V_17 ) ;
F_28 ( V_2 ) ;
return NULL ;
}
