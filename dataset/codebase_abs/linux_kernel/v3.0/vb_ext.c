static unsigned char F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 ;
V_3 = F_2 ( V_2 -> V_4 , 0x01 ) ;
if ( V_3 > 0x0B0 )
return 0 ;
else
return 1 ;
}
static unsigned char F_3 ( unsigned short V_5 ,
unsigned short V_6 ,
struct V_1 * V_2 )
{
unsigned short V_7 , V_8 , V_9 ;
V_7 = V_5 & 0xFF ;
F_4 ( V_2 -> V_4 , 0x11 , V_7 ) ;
V_7 = ( V_5 & 0xFF00 ) >> 8 ;
V_7 |= ( V_6 & 0x00FF ) ;
F_5 ( V_2 -> V_4 , 0x10 , ~ 0x1F , V_7 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ )
F_6 ( V_2 ) ;
V_9 = ( V_6 & 0x7F00 ) >> 8 ;
V_7 = F_2 ( V_2 -> V_4 , 0x03 ) ;
V_7 = V_7 ^ ( 0x0E ) ;
V_7 &= V_9 ;
if ( V_7 > 0 )
return 1 ;
else
return 0 ;
}
static unsigned char
F_7 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned short V_7 ;
if ( V_11 -> V_12 == V_13 ) {
return 0 ;
} else {
V_7 = ( unsigned short ) V_11 -> V_12 ;
switch ( V_11 -> V_12 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
break;
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_7 = 0 ;
break;
case V_23 :
case V_24 :
case V_25 :
break;
case V_26 :
case V_27 :
V_7 = 0 ;
break;
default:
break;
}
F_5 ( V_2 -> V_28 , 0x36 , 0xF0 , V_7 ) ;
return 1 ;
}
}
static unsigned char F_8 ( struct V_1 * V_2 )
{
unsigned short V_29 [ 16 ] = { V_30 | V_31
| V_32 | V_33 , V_30 | V_31
| V_34 | V_35 , V_30 | V_31
| V_32 | V_36 , V_30 | V_31
| V_37 | V_38 , V_30 | V_31
| V_34 | V_39 , V_30 | V_31
| V_34 | V_40 , V_30 | V_31
| V_34 | V_41 , V_30 | V_42
| V_34 | V_43 , V_30 | V_31
| V_32 | V_44 , V_30 | V_31
| V_34 | V_45 , V_30 | V_31
| V_32 | V_46 , V_30 | V_31
| V_34 | V_47 , V_30 | V_31
| V_34 | V_48 , V_30 | V_42
| V_34 | V_49 , V_30 | V_31
| V_34 | V_50 , V_30 | V_31
| V_34 | V_51 } ;
unsigned short V_52 , V_5 , V_7 ;
V_52 = F_2 ( V_2 -> V_53 , 0x1A ) ;
V_5 = V_52 & 0x1E ;
if ( V_52 == 0 )
return 0 ;
else {
V_5 = V_5 >> 1 ;
V_7 = V_5 & 0x00F ;
F_4 ( V_2 -> V_28 , 0x36 , V_7 ) ;
V_5 -- ;
V_5 = V_29 [ V_5 ] ;
V_7 = ( V_5 & 0xFF00 ) >> 8 ;
F_5 ( V_2 -> V_28 , 0x37 , ~ ( V_54
| V_55 ) , V_7 ) ;
return 1 ;
}
}
static unsigned char
F_9 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned short V_3 ;
if ( F_10 ( V_2 ) == 0 ) {
V_3 = F_2 ( V_2 -> V_56 , 0x0 ) ;
if ( V_3 & 0x050 )
return 1 ;
else
return 0 ;
}
return 0 ;
}
static unsigned char
F_11 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned short V_5 , V_6 , V_7 , V_8 , V_9 ;
V_5 = * V_2 -> V_57 ;
V_6 = 0x0604 ;
V_7 = V_5 & 0xFF ;
F_4 ( V_2 -> V_4 , 0x11 , V_7 ) ;
V_7 = ( V_5 & 0xFF00 ) >> 8 ;
V_7 |= ( V_6 & 0x00FF ) ;
F_5 ( V_2 -> V_4 , 0x10 , ~ 0x1F , V_7 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ )
F_6 ( V_2 ) ;
V_9 = ( V_6 & 0xFF00 ) >> 8 ;
V_7 = F_2 ( V_2 -> V_4 , 0x03 ) ;
V_7 = V_7 ^ ( 0x0E ) ;
V_7 &= V_9 ;
if ( V_7 != V_9 )
return 0 ;
V_5 = * V_2 -> V_58 ;
V_6 = 0x0804 ;
V_7 = V_5 & 0xFF ;
F_4 ( V_2 -> V_4 , 0x11 , V_7 ) ;
V_7 = ( V_5 & 0xFF00 ) >> 8 ;
V_7 |= ( V_6 & 0x00FF ) ;
F_5 ( V_2 -> V_4 , 0x10 , ~ 0x1F , V_7 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ )
F_6 ( V_2 ) ;
V_9 = ( V_6 & 0xFF00 ) >> 8 ;
V_7 = F_2 ( V_2 -> V_4 , 0x03 ) ;
V_7 = V_7 ^ ( 0x0E ) ;
V_7 &= V_9 ;
if ( V_7 != V_9 ) {
return 0 ;
} else {
V_5 = 0x3FF ;
V_6 = 0x0804 ;
V_7 = V_5 & 0xFF ;
F_4 ( V_2 -> V_4 , 0x11 , V_7 ) ;
V_7 = ( V_5 & 0xFF00 ) >> 8 ;
V_7 |= ( V_6 & 0x00FF ) ;
F_5 ( V_2 -> V_4 , 0x10 , ~ 0x1F , V_7 ) ;
for ( V_8 = 0 ; V_8 < 10 ; V_8 ++ )
F_6 ( V_2 ) ;
V_9 = ( V_6 & 0xFF00 ) >> 8 ;
V_7 = F_2 ( V_2 -> V_4 , 0x03 ) ;
V_7 = V_7 ^ ( 0x0E ) ;
V_7 &= V_9 ;
if ( V_7 != V_9 )
return 1 ;
else
return 0 ;
}
}
void F_12 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned short V_52 = 0 , V_5 , V_6 , V_7 ,
V_59 = 0 , V_60 = 0 ,
V_61 = * V_2 -> V_62 ,
V_63 , V_8 ;
V_2 -> V_64 = ( unsigned long ) V_11 -> V_65 ;
if ( V_2 -> V_66 == 1 ) {
V_52 = F_2 ( V_2 -> V_53 , 0x1A ) ;
V_5 = F_2 ( V_2 -> V_53 , 0x1B ) ;
V_52 = ( ( V_52 & 0xFE ) >> 1 ) | ( V_5 << 8 ) ;
if ( V_52 == 0x00 ) {
V_7 = F_7 ( V_11 , V_2 ) ;
if ( V_7 == 1 ) {
F_5 ( V_2 -> V_28 ,
0x39 , 0xFF , 0x01 ) ;
F_5 ( V_2 -> V_28 ,
0x37 , 0xEF , 0x00 ) ;
V_7 = V_67 ;
} else {
V_7 = 0 ;
}
} else {
F_8 ( V_2 ) ;
V_7 = V_67 ;
}
V_5 = ~ ( V_67 | V_68 | V_69 ) ;
F_5 ( V_2 -> V_28 , 0x32 , V_5 , V_7 ) ;
} else {
if ( V_2 -> V_70 & V_71 ) {
V_52 = F_2 ( V_2 -> V_53 , 0x38 ) ;
V_7 = V_52 & 0x01 ;
V_52 = F_2 ( V_2 -> V_53 , 0x3A ) ;
V_7 = V_7 | ( V_52 & 0x02 ) ;
F_5 ( V_2 -> V_28 , 0x32 , 0xA0 , V_7 ) ;
} else {
if ( F_10 ( V_2 ) ) {
V_59 = F_2 ( V_2 -> V_72 ,
0x00 ) ;
if ( ! F_9 ( V_11 ,
V_2 ) ) {
V_60 = 0x2e ;
V_7 = F_13 ( V_60 ,
& V_63 ,
V_2 ) ;
F_14 ( V_11 ,
V_2 ) ;
F_15 ( V_2 ) ;
V_2 -> V_73 = 0x00 ;
V_2 -> V_74 = V_75 ;
V_2 -> V_70 = V_76 |
V_77 |
V_78 ;
F_16 ( 0x2e ,
V_63 ,
V_2 ) ;
F_17 ( 0x2e ,
V_63 ,
V_2 ) ;
F_18 ( V_11 ,
V_2 ) ;
F_19 ( V_60 ,
V_11 ,
V_2 ) ;
F_20 ( 0x2e ,
V_11 ,
V_2 ) ;
F_5 ( V_2 -> V_53 ,
0x01 ,
0xDF ,
0x20 ) ;
for ( V_8 = 0 ; V_8 < 20 ; V_8 ++ )
F_6 ( V_2 ) ;
}
F_4 ( V_2 -> V_72 , 0x00 , 0x1c ) ;
V_52 = 0 ;
V_5 = * V_2 -> V_79 ;
if ( ! ( F_1 ( V_2 ) ) )
V_5 = * V_2 -> V_80 ;
V_6 = 0x0E08 ;
if ( F_3 ( V_5 , V_6 , V_2 ) ) {
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) )
V_52 |= V_81 ;
}
if ( V_2 -> V_82 & V_83 )
F_21 ( V_2 -> V_4 ,
0x0d ,
0x04 ) ;
if ( F_11 ( V_11 ,
V_2 ) ) {
V_52 |= V_84 ;
if ( ( V_2 -> V_82 & V_83 ) )
V_52 ^= ( V_84 |
V_85 ) ;
}
if ( ! ( V_52 & ( V_84 | V_85 ) ) ) {
V_5 = * V_2 -> V_86 ;
if ( ! ( F_1 ( V_2 ) ) )
V_5 = * V_2 -> V_57 ;
V_6 = 0x0604 ;
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) ) {
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) )
V_52 |= V_69 ;
}
if ( V_61 & V_87 ) {
V_5 = * V_2 -> V_88 ;
if ( ! ( F_1 ( V_2 ) ) )
V_5 = * V_2 -> V_58 ;
V_6 = 0x0804 ;
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) ) {
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) )
V_52 |= V_68 ;
}
} else {
if ( ! ( V_52 & V_69 ) ) {
V_5 = * V_2 -> V_88 ;
if ( ! ( F_1 ( V_2 ) ) )
V_5 = * V_2 -> V_58 ;
V_6 = 0x0804 ;
if ( F_3 ( V_5 ,
V_6 ,
V_2 ) ) {
if ( F_3 ( V_5 , V_6 , V_2 ) )
V_52 |= V_68 ;
}
}
}
}
}
if ( ! ( V_52 & V_81 ) ) {
if ( F_22 ( V_11 , V_2 ) )
V_52 |= V_67 ;
}
V_5 = 0 ;
V_6 = 0 ;
F_3 ( V_5 , V_6 , V_2 ) ;
F_5 ( V_2 -> V_28 , 0x32 , ~ 0xDF , V_52 ) ;
F_4 ( V_2 -> V_72 , 0x00 , V_59 ) ;
if ( ! ( V_59 & 0x20 ) ) {
V_2 -> V_70 = V_89 ;
}
}
}
F_23 ( V_11 , V_2 ) ;
}
unsigned short F_22 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned short V_7 ;
V_7 = F_7 ( V_11 , V_2 ) ;
return V_7 ;
}
