static void F_1 ( struct V_1 * V_1 ,
T_1 V_2 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
V_3 = F_2 ( V_1 -> V_5 ,
F_3 ( V_1 -> V_5 , 0 ) ,
0 ,
V_6 | V_7 | V_8 ,
V_2 ,
0 ,
V_1 -> V_9 , 1 ,
500 ) ;
if ( V_3 < 0 ) {
F_4 ( V_1 -> V_10 . V_5 ,
L_1 , V_2 , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_5 ( struct V_1 * V_1 ,
T_1 V_2 ,
const T_2 * V_11 ,
int V_12 )
{
int V_3 ;
if ( V_1 -> V_4 < 0 )
return;
memcpy ( V_1 -> V_9 , V_11 , V_12 ) ;
V_3 = F_2 ( V_1 -> V_5 ,
F_6 ( V_1 -> V_5 , 0 ) ,
0x08 ,
V_13 | V_7 | V_8 ,
V_2 ,
0 ,
V_1 -> V_9 , V_12 ,
500 ) ;
if ( V_3 < 0 ) {
F_4 ( V_1 -> V_10 . V_5 ,
L_2 , V_2 , V_3 ) ;
V_1 -> V_4 = V_3 ;
}
}
static void F_7 ( struct V_1 * V_1 , const T_3 * V_14 )
{
int V_15 = 60 ;
if ( V_1 -> V_4 < 0 )
return;
F_5 ( V_1 , 0x08 , V_14 , 8 ) ;
while ( V_15 -- ) {
if ( V_1 -> V_4 < 0 )
return;
F_8 ( 1 ) ;
F_1 ( V_1 , 0x08 ) ;
if ( V_1 -> V_9 [ 0 ] & 0x04 ) {
if ( V_1 -> V_9 [ 0 ] & 0x08 ) {
F_4 ( V_1 -> V_10 . V_5 ,
L_3 , V_14 ) ;
V_1 -> V_4 = - V_16 ;
}
return;
}
}
F_4 ( V_1 -> V_10 . V_5 , L_4 ) ;
V_1 -> V_4 = - V_16 ;
}
static void F_9 ( struct V_1 * V_1 ,
const T_2 V_11 [] [ 8 ] , int V_12 )
{
for (; ; ) {
if ( V_1 -> V_4 < 0 )
return;
F_7 ( V_1 , * V_11 ) ;
V_12 -= 8 ;
if ( V_12 <= 0 )
break;
V_11 ++ ;
}
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
switch ( V_17 -> V_18 ) {
case V_19 :
case V_20 : {
T_2 V_21 [] =
{ 0xa0 , 0x00 , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
V_21 [ 1 ] = V_22 [ V_17 -> V_18 ] . V_23 ;
V_21 [ 3 ] = V_17 -> V_24 -> V_25 ;
F_7 ( V_1 , V_21 ) ;
break;
}
case V_26 :
case V_27 : {
T_2 V_28 [] =
{ 0xb0 , 0x40 , 0x0b , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
T_2 V_29 [] =
{ 0xa0 , 0x40 , 0x11 , 0x01 , 0x00 , 0x00 , 0x00 , 0x16 } ;
if ( V_17 -> V_18 == V_26 ) {
V_28 [ 2 ] = 7 ;
V_29 [ 2 ] = 0x13 ;
}
if ( V_17 -> V_24 -> V_25 < 127 ) {
V_28 [ 3 ] = 0x01 ;
V_28 [ 4 ] = 127 - V_17 -> V_24 -> V_25 ;
} else
V_28 [ 4 ] = V_17 -> V_24 -> V_25 - 127 ;
F_7 ( V_1 , V_28 ) ;
F_7 ( V_1 , V_29 ) ;
break;
}
default:
break;
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
T_3 V_30 = V_1 -> V_30 -> V_25 ;
switch ( V_17 -> V_18 ) {
case V_31 : {
T_2 V_32 [] =
{ 0xc0 , 0x11 , 0x31 , 0x00 , 0x00 , 0x00 , 0x00 , 0x17 } ;
V_32 [ 3 ] = 0x3f - V_30 ;
V_32 [ 4 ] = 0x3f - V_30 ;
V_32 [ 5 ] = 0x3f - V_30 ;
F_7 ( V_1 , V_32 ) ;
break;
}
case V_33 :
case V_34 : {
T_2 V_32 [] =
{ 0x30 , 0x11 , 0x02 , 0x20 , 0x70 , 0x00 , 0x00 , 0x10 } ;
V_32 [ 4 ] = 255 - V_30 ;
F_7 ( V_1 , V_32 ) ;
break;
}
case V_35 : {
T_2 V_32 [] = {
0xb0 , 0x61 , 0x02 , 0x00 , 0x10 , 0x00 , 0x00 , 0x17 } ;
V_30 = 255 - V_30 ;
V_32 [ 3 ] |= ( V_30 & 0x80 ) >> 7 ;
V_32 [ 3 ] |= ( V_30 & 0x40 ) >> 5 ;
V_32 [ 3 ] |= ( V_30 & 0x20 ) >> 3 ;
V_32 [ 3 ] |= ( V_30 & 0x10 ) >> 1 ;
V_32 [ 3 ] |= ( V_30 & 0x08 ) << 1 ;
V_32 [ 3 ] |= ( V_30 & 0x04 ) << 3 ;
V_32 [ 3 ] |= ( V_30 & 0x02 ) << 5 ;
V_32 [ 3 ] |= ( V_30 & 0x01 ) << 7 ;
F_7 ( V_1 , V_32 ) ;
break;
}
case V_19 :
case V_20 : {
T_2 V_32 [] = { 0xa0 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_17 -> V_18 == V_20 && V_30 >= 32 )
V_30 += 16 ;
V_32 [ 1 ] = V_22 [ V_17 -> V_18 ] . V_23 ;
V_32 [ 3 ] = V_30 ;
F_7 ( V_1 , V_32 ) ;
break;
}
case V_26 :
case V_27 : {
T_2 V_36 [] =
{ 0xa0 , 0x40 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x15 } ;
T_2 V_37 [] =
{ 0xc0 , 0x40 , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 , 0x15 } ;
T_2 V_29 [] =
{ 0xa0 , 0x40 , 0x11 , 0x01 , 0x00 , 0x00 , 0x00 , 0x16 } ;
if ( V_17 -> V_18 == V_26 ) {
V_36 [ 2 ] = 0x0e ;
V_37 [ 0 ] = 0xd0 ;
V_37 [ 2 ] = 0x09 ;
V_29 [ 2 ] = 0x13 ;
}
V_36 [ 3 ] = V_30 ;
V_37 [ 3 ] = V_30 >> 1 ;
V_37 [ 4 ] = V_30 >> 1 ;
V_37 [ 5 ] = V_30 >> 1 ;
V_37 [ 6 ] = V_30 >> 1 ;
F_7 ( V_1 , V_36 ) ;
F_7 ( V_1 , V_37 ) ;
F_7 ( V_1 , V_29 ) ;
break;
}
default:
if ( V_17 -> V_38 == V_39 ) {
T_3 V_14 [ 3 ] = { V_30 , V_30 , V_30 } ;
F_5 ( V_1 , 0x05 , V_14 , 3 ) ;
} else {
T_3 V_14 [ 2 ] ;
V_14 [ 0 ] = V_30 << 4 | V_30 ;
V_14 [ 1 ] = V_30 ;
F_5 ( V_1 , 0x10 , V_14 , 2 ) ;
}
}
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
switch ( V_17 -> V_18 ) {
case V_31 : {
T_2 V_32 [] = { 0xc0 , 0x11 , 0x25 , 0x00 , 0x00 , 0x00 , 0x00 , 0x17 } ;
T_4 V_40 = V_1 -> V_41 -> V_25 ;
V_32 [ 3 ] = V_40 >> 8 ;
V_32 [ 4 ] = V_40 & 0xff ;
F_7 ( V_1 , V_32 ) ;
break;
}
case V_33 :
case V_35 : {
T_3 V_40 = V_1 -> V_41 -> V_25 ;
V_40 = ( V_40 << 4 ) | 0x0b ;
F_5 ( V_1 , 0x19 , & V_40 , 1 ) ;
break;
}
case V_19 :
case V_20 : {
T_2 V_32 [] = { 0xb0 , 0x00 , 0x10 , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
int V_42 , V_43 , V_44 ;
if ( V_17 -> V_18 == V_19 ) {
V_44 = 0x4d ;
V_32 [ 4 ] = 0xc0 ;
} else
V_44 = 0x41 ;
V_43 = ( 15 * V_1 -> V_41 -> V_25 + 999 ) / 1000 ;
if ( V_43 < 1 )
V_43 = 1 ;
else if ( V_43 > 16 )
V_43 = 16 ;
if ( V_1 -> V_45 . V_46 == 640 && V_43 < 4 )
V_43 = 4 ;
V_42 = ( V_1 -> V_41 -> V_25 * 15 * V_44 )
/ ( 1000 * V_43 ) ;
if ( V_1 -> V_47 -> V_25 && V_42 < 10 )
V_42 = 10 ;
else if ( V_42 > V_44 )
V_42 = V_44 ;
V_32 [ 1 ] = V_22 [ V_17 -> V_18 ] . V_23 ;
V_32 [ 3 ] = V_42 ;
V_32 [ 4 ] |= V_43 - 1 ;
if ( V_17 -> V_43 == V_43 )
V_32 [ 0 ] = 0xa0 ;
F_7 ( V_1 , V_32 ) ;
if ( V_1 -> V_4 == 0 )
V_17 -> V_43 = V_43 ;
break;
}
case V_27 : {
T_2 V_48 [] =
{ 0xb0 , 0x40 , 0x04 , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
T_2 V_49 [] =
{ 0xa0 , 0x40 , 0x0f , 0x00 , 0x00 , 0x00 , 0x00 , 0x16 } ;
const T_2 V_29 [] =
{ 0xa0 , 0x40 , 0x11 , 0x01 , 0x00 , 0x00 , 0x00 , 0x16 } ;
int V_50 ;
if ( V_1 -> V_41 -> V_25 < 200 ) {
V_49 [ 3 ] = 255 - ( V_1 -> V_41 -> V_25 * 255 )
/ 200 ;
V_50 = 500 ;
} else {
V_50 = ( V_1 -> V_41 -> V_25 - 200 )
* 1000 / 229 + 500 ;
}
V_48 [ 3 ] = V_50 >> 6 ;
V_48 [ 4 ] = V_50 & 0x3f ;
F_7 ( V_1 , V_48 ) ;
F_7 ( V_1 , V_49 ) ;
F_7 ( V_1 , V_29 ) ;
break;
}
case V_26 : {
T_2 V_48 [] =
{ 0xb1 , 0x40 , 0x03 , 0x00 , 0x00 , 0x00 , 0x00 , 0x14 } ;
T_2 V_49 [] =
{ 0xa1 , 0x40 , 0x05 , 0x00 , 0x00 , 0x00 , 0x00 , 0x14 } ;
const T_2 V_29 [] =
{ 0xa1 , 0x40 , 0x13 , 0x01 , 0x00 , 0x00 , 0x00 , 0x14 } ;
int V_50 ;
if ( V_1 -> V_41 -> V_25 < 150 ) {
V_49 [ 3 ] = 150 - V_1 -> V_41 -> V_25 ;
V_50 = 300 ;
} else {
V_50 = ( V_1 -> V_41 -> V_25 - 150 )
* 1000 / 230 + 300 ;
}
V_48 [ 3 ] = V_50 >> 4 ;
V_48 [ 4 ] = V_50 & 0x0f ;
F_7 ( V_1 , V_48 ) ;
F_7 ( V_1 , V_49 ) ;
F_7 ( V_1 , V_29 ) ;
break;
}
default:
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
if ( V_17 -> V_18 == V_19 || V_17 -> V_18 == V_20 ) {
T_2 V_32 [] = { 0xa0 , 0x00 , 0x2b , 0x00 , 0x00 , 0x00 , 0x00 , 0x10 } ;
switch ( V_17 -> V_51 -> V_25 ) {
default:
V_32 [ 3 ] = 0 ;
break;
case 1 :
V_32 [ 3 ] = ( V_17 -> V_18 == V_19 )
? 0x4f : 0x8a ;
break;
}
V_32 [ 1 ] = V_22 [ V_17 -> V_18 ] . V_23 ;
F_7 ( V_1 , V_32 ) ;
}
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_52 , V_53 , V_54 ;
V_54 = F_15 ( & V_17 -> V_54 ) ;
if ( V_54 == - 1 )
return;
if ( V_17 -> V_55 > 0 ) {
V_17 -> V_55 -- ;
return;
}
if ( V_22 [ V_17 -> V_18 ] . V_56 & V_57 ) {
V_52 = 500 ;
V_53 = 5000 ;
} else {
V_52 = 1500 ;
V_53 = 13000 ;
}
if ( V_17 -> V_24 )
V_53 = V_17 -> V_24 -> V_25 * V_53 / 127 ;
if ( V_1 -> V_41 -> V_58 < 500 ) {
if ( F_16 ( V_1 , V_54 ,
V_53 , V_52 ) )
V_17 -> V_55 = V_59 ;
} else {
int V_60 = V_1 -> V_30 -> V_58 * 9 / 10 ;
if ( F_17 ( V_1 , V_54 , V_53 ,
V_52 , V_60 , V_17 -> V_61 ) )
V_17 -> V_55 = V_59 ;
}
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_62 * V_63 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_64 * V_64 ;
F_1 ( V_1 , 0x00 ) ;
if ( V_1 -> V_9 [ 0 ] != 0x10 )
return - V_65 ;
V_17 -> V_18 = V_63 -> V_66 >> 8 ;
V_17 -> V_38 = V_63 -> V_66 & 0xff ;
V_64 = & V_1 -> V_64 ;
if ( ! ( V_22 [ V_17 -> V_18 ] . V_56 & V_57 ) ) {
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = F_19 ( V_68 ) ;
} else {
V_64 -> V_67 = V_70 ;
V_64 -> V_69 = F_19 ( V_70 ) ;
}
V_64 -> V_71 = 36 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
const T_2 V_72 = 0x09 ;
F_5 ( V_1 , 0x01 , & V_72 , 1 ) ;
return V_1 -> V_4 ;
}
static int F_21 ( struct V_73 * V_74 )
{
struct V_1 * V_1 =
F_22 ( V_74 -> V_75 , struct V_1 , V_76 ) ;
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
V_1 -> V_4 = 0 ;
if ( V_74 -> V_63 == V_77 && V_74 -> V_78 && V_74 -> V_25 ) {
V_1 -> V_30 -> V_25 = V_1 -> V_30 -> V_79 ;
V_1 -> V_41 -> V_25 = V_1 -> V_41 -> V_79 ;
V_17 -> V_55 = V_59 ;
}
if ( ! V_1 -> V_80 )
return 0 ;
switch ( V_74 -> V_63 ) {
case V_81 :
F_10 ( V_1 ) ;
break;
case V_77 :
if ( V_1 -> V_41 -> V_78 || ( V_74 -> V_78 && V_74 -> V_25 ) )
F_12 ( V_1 ) ;
if ( V_1 -> V_30 -> V_78 || ( V_74 -> V_78 && V_74 -> V_25 ) )
F_11 ( V_1 ) ;
break;
case V_82 :
F_13 ( V_1 ) ;
break;
default:
return - V_83 ;
}
return V_1 -> V_4 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_84 * V_85 = & V_1 -> V_76 ;
V_1 -> V_86 . V_76 = V_85 ;
F_24 ( V_85 , 5 ) ;
if ( V_17 -> V_18 == V_19 || V_17 -> V_18 == V_20 ||
V_17 -> V_18 == V_26 || V_17 -> V_18 == V_27 )
V_17 -> V_24 = F_25 ( V_85 , & V_87 ,
V_81 , 0 , 255 , 1 , 127 ) ;
switch ( V_17 -> V_18 ) {
case V_19 :
case V_26 :
case V_27 :
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 31 , 1 , 15 ) ;
break;
case V_20 :
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 47 , 1 , 31 ) ;
break;
case V_31 :
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 63 , 1 , 31 ) ;
break;
case V_33 :
case V_35 :
case V_34 :
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 255 , 1 , 127 ) ;
break;
default:
if ( V_17 -> V_38 == V_39 ) {
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 127 , 1 , 63 ) ;
} else {
V_1 -> V_30 = F_25 ( V_85 , & V_87 ,
V_88 , 0 , 15 , 1 , 7 ) ;
}
}
switch ( V_17 -> V_18 ) {
case V_31 :
V_1 -> V_41 = F_25 ( V_85 , & V_87 ,
V_89 , 0 , 8191 , 1 , 482 ) ;
V_17 -> V_61 = 964 ;
break;
case V_19 :
case V_20 :
case V_26 :
case V_27 :
V_1 -> V_41 = F_25 ( V_85 , & V_87 ,
V_89 , 0 , 1023 , 1 , 66 ) ;
V_17 -> V_61 = 200 ;
break;
case V_33 :
case V_35 :
V_1 -> V_41 = F_25 ( V_85 , & V_87 ,
V_89 , 2 , 15 , 1 , 2 ) ;
break;
}
if ( V_1 -> V_41 ) {
V_1 -> V_47 = F_25 ( V_85 , & V_87 ,
V_77 , 0 , 1 , 1 , 1 ) ;
}
if ( V_17 -> V_18 == V_19 || V_17 -> V_18 == V_20 )
V_17 -> V_51 = F_26 ( V_85 , & V_87 ,
V_82 ,
V_90 , 0 ,
V_91 ) ;
if ( V_85 -> error ) {
F_27 ( L_5 ) ;
return V_85 -> error ;
}
if ( V_1 -> V_47 )
F_28 ( 3 , & V_1 -> V_47 , 0 , false ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_64 * V_64 = & V_1 -> V_64 ;
int V_92 , V_93 ;
T_2 V_94 [ 0x31 ] ;
V_93 = V_64 -> V_67 [ V_1 -> V_95 ] . V_96 & 0x07 ;
memcpy ( & V_94 [ 0x01 ] , V_22 [ V_17 -> V_18 ] . V_97 , 0x19 ) ;
V_94 [ 0x18 ] |= V_93 << 4 ;
if ( V_17 -> V_38 == V_39 ) {
V_94 [ 0x05 ] = 0x20 ;
V_94 [ 0x06 ] = 0x20 ;
V_94 [ 0x07 ] = 0x20 ;
} else {
V_94 [ 0x10 ] = 0x00 ;
V_94 [ 0x11 ] = 0x00 ;
}
if ( V_22 [ V_17 -> V_18 ] . V_56 & V_57 ) {
V_94 [ 0x1a ] = 0x14 ;
V_94 [ 0x1b ] = 0x0a ;
V_94 [ 0x1c ] = 0x02 ;
V_94 [ 0x1d ] = 0x02 ;
V_94 [ 0x1e ] = 0x09 ;
V_94 [ 0x1f ] = 0x07 ;
} else {
V_94 [ 0x1a ] = 0x1d ;
V_94 [ 0x1b ] = 0x10 ;
V_94 [ 0x1c ] = 0x05 ;
V_94 [ 0x1d ] = 0x03 ;
V_94 [ 0x1e ] = 0x0f ;
V_94 [ 0x1f ] = 0x0c ;
}
for ( V_92 = 0 ; V_92 < 16 ; V_92 ++ )
V_94 [ 0x20 + V_92 ] = V_92 * 16 ;
V_94 [ 0x20 + V_92 ] = 255 ;
switch ( V_17 -> V_18 ) {
case V_34 :
V_94 [ 0x19 ] = V_93 ? 0x23 : 0x43 ;
break;
case V_20 :
if ( V_17 -> V_38 == V_39 ) {
V_94 [ 0x01 ] = 0x44 ;
V_94 [ 0x12 ] = 0x02 ;
}
break;
case V_27 :
if ( V_17 -> V_38 == V_39 )
V_94 [ 0x12 ] += 1 ;
break;
}
if ( V_64 -> V_67 [ V_1 -> V_95 ] . V_96 & V_98 )
V_94 [ 0x18 ] &= ~ 0x80 ;
if ( V_64 -> V_67 [ V_1 -> V_95 ] . V_96 & V_99 ) {
V_94 [ 0x12 ] += 16 ;
V_94 [ 0x13 ] += 24 ;
V_94 [ 0x15 ] = 320 / 16 ;
V_94 [ 0x16 ] = 240 / 16 ;
}
F_5 ( V_1 , 0x01 , & V_94 [ 0x01 ] , 1 ) ;
F_5 ( V_1 , 0x17 , & V_94 [ 0x17 ] , 1 ) ;
F_5 ( V_1 , 0x01 , & V_94 [ 0x01 ] ,
( V_17 -> V_38 == V_39 ) ? 0x30 : 0x1f ) ;
F_9 ( V_1 , V_22 [ V_17 -> V_18 ] . V_100 ,
V_22 [ V_17 -> V_18 ] . V_101 ) ;
switch ( V_17 -> V_18 ) {
case V_27 : {
const T_2 V_102 [] =
{ 0xa0 , 0x40 , 0x02 , 0x03 , 0x00 , 0x00 , 0x00 , 0x10 } ;
if ( V_93 )
F_7 ( V_1 , V_102 ) ;
break;
}
case V_20 :
if ( V_17 -> V_38 == V_39 ) {
const T_2 V_32 [] = { 0xa0 , 0x21 , 0x13 ,
0x80 , 0x00 , 0x00 , 0x00 , 0x10 } ;
F_7 ( V_1 , V_32 ) ;
}
break;
}
F_5 ( V_1 , 0x15 , & V_94 [ 0x15 ] , 2 ) ;
F_5 ( V_1 , 0x18 , & V_94 [ 0x18 ] , 1 ) ;
F_5 ( V_1 , 0x12 , & V_94 [ 0x12 ] , 1 ) ;
F_5 ( V_1 , 0x13 , & V_94 [ 0x13 ] , 1 ) ;
F_5 ( V_1 , 0x17 , & V_94 [ 0x17 ] , 1 ) ;
F_5 ( V_1 , 0x19 , & V_94 [ 0x19 ] , 1 ) ;
F_5 ( V_1 , 0x1c , & V_94 [ 0x1c ] , 4 ) ;
F_5 ( V_1 , 0x01 , & V_94 [ 0x01 ] , 1 ) ;
F_5 ( V_1 , 0x18 , & V_94 [ 0x18 ] , 2 ) ;
F_8 ( 20 ) ;
V_17 -> V_43 = - 1 ;
F_11 ( V_1 ) ;
F_10 ( V_1 ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
V_17 -> V_103 = 0 ;
V_17 -> V_55 = 0 ;
V_1 -> V_104 = 0 ;
V_1 -> V_105 = 0 ;
F_30 ( & V_17 -> V_54 , - 1 ) ;
return V_1 -> V_4 ;
}
static void F_31 ( struct V_1 * V_1 )
{
F_20 ( V_1 ) ;
}
static T_3 * F_32 ( struct V_1 * V_1 , T_3 * V_106 , int V_12 )
{
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
int V_92 , V_107 = ( V_17 -> V_38 == V_39 ) ? 18 : 12 ;
for ( V_92 = 0 ; V_92 < V_12 ; V_92 ++ ) {
switch ( V_17 -> V_108 ) {
case 0 :
if ( V_106 [ V_92 ] == 0xff )
V_17 -> V_108 ++ ;
break;
case 1 :
if ( V_106 [ V_92 ] == 0xff )
V_17 -> V_108 ++ ;
else
V_17 -> V_108 = 0 ;
break;
case 2 :
if ( V_106 [ V_92 ] == 0x00 )
V_17 -> V_108 ++ ;
else if ( V_106 [ V_92 ] != 0xff )
V_17 -> V_108 = 0 ;
break;
case 3 :
if ( V_106 [ V_92 ] == 0xc4 )
V_17 -> V_108 ++ ;
else if ( V_106 [ V_92 ] == 0xff )
V_17 -> V_108 = 1 ;
else
V_17 -> V_108 = 0 ;
break;
case 4 :
if ( V_106 [ V_92 ] == 0xc4 )
V_17 -> V_108 ++ ;
else if ( V_106 [ V_92 ] == 0xff )
V_17 -> V_108 = 1 ;
else
V_17 -> V_108 = 0 ;
break;
case 5 :
if ( V_106 [ V_92 ] == 0x96 )
V_17 -> V_108 ++ ;
else if ( V_106 [ V_92 ] == 0xff )
V_17 -> V_108 = 1 ;
else
V_17 -> V_108 = 0 ;
break;
default:
V_17 -> V_109 [ V_17 -> V_108 - 6 ] = V_106 [ V_92 ] ;
V_17 -> V_108 ++ ;
if ( V_17 -> V_108 == V_107 ) {
V_17 -> V_108 = 0 ;
return V_106 + V_92 + 1 ;
}
}
}
return NULL ;
}
static void F_33 ( struct V_1 * V_1 ,
T_3 * V_106 ,
int V_12 )
{
int V_110 = 0 , V_111 = 0 , V_112 = 0 ;
struct V_17 * V_17 = (struct V_17 * ) V_1 ;
struct V_64 * V_64 = & V_1 -> V_64 ;
T_3 * V_113 ;
V_113 = F_32 ( V_1 , V_106 , V_12 ) ;
if ( V_113 ) {
if ( V_17 -> V_38 == V_39 ) {
V_110 = 18 ;
V_111 = 3 ;
} else {
V_110 = 12 ;
V_111 = 2 ;
}
V_112 = V_12 - ( V_113 - V_106 ) ;
V_12 = ( V_113 - V_106 ) - V_110 ;
if ( V_12 < 0 )
V_12 = 0 ;
}
if ( V_64 -> V_67 [ V_1 -> V_95 ] . V_96 & V_98 ) {
int V_114 ;
int V_115 = V_64 -> V_67 [ V_1 -> V_95 ] . V_116 ;
V_114 = V_1 -> V_117 ;
if ( V_114 + V_12 > V_115 )
V_12 = V_115 - V_114 ;
}
F_34 ( V_1 , V_118 , V_106 , V_12 ) ;
if ( V_113 ) {
int V_119 = V_17 -> V_109 [ V_111 ] +
( V_17 -> V_109 [ V_111 + 1 ] << 8 ) ;
if ( V_119 == 0 && V_17 -> V_120 != 0 ) {
V_119 = - 1 ;
V_17 -> V_103 = 2 ;
V_17 -> V_120 = 0 ;
} else
V_17 -> V_120 = V_119 ;
F_30 ( & V_17 -> V_54 , V_119 ) ;
if ( V_17 -> V_103 )
V_17 -> V_103 -- ;
else
F_34 ( V_1 , V_121 , NULL , 0 ) ;
F_34 ( V_1 , V_122 , V_113 , V_112 ) ;
}
}
static int F_35 ( struct V_1 * V_1 ,
T_3 * V_106 ,
int V_12 )
{
int V_123 = - V_83 ;
if ( V_12 == 1 && V_106 [ 0 ] == 1 ) {
F_36 ( V_1 -> V_124 , V_125 , 1 ) ;
F_37 ( V_1 -> V_124 ) ;
F_36 ( V_1 -> V_124 , V_125 , 0 ) ;
F_37 ( V_1 -> V_124 ) ;
V_123 = 0 ;
}
return V_123 ;
}
static int F_38 ( struct V_126 * V_127 ,
const struct V_62 * V_63 )
{
return F_39 ( V_127 , V_63 , & V_128 , sizeof( struct V_17 ) ,
V_129 ) ;
}
