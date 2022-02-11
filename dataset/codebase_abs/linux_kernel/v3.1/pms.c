static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 | ( V_4 << 8 ) , V_2 -> V_5 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_2 -> V_5 ) ;
return F_5 ( V_2 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_7 )
{
int V_8 = 0 ;
int V_9 ;
F_4 ( 0x28 , V_2 -> V_5 ) ;
while ( ( F_5 ( V_2 -> V_6 ) & 0x01 ) == 0 )
if ( V_8 ++ == 256 )
break;
while ( ( F_5 ( V_2 -> V_6 ) & 0x01 ) != 0 )
if ( V_8 ++ == 256 )
break;
F_4 ( V_7 , V_2 -> V_5 ) ;
V_8 = 0 ;
while ( ( F_5 ( V_2 -> V_6 ) & 0x01 ) == 0 )
if ( V_8 ++ == 256 )
break;
while ( ( F_5 ( V_2 -> V_6 ) & 0x01 ) != 0 )
if ( V_8 ++ == 256 )
break;
for ( V_9 = 0 ; V_9 < 12 ; V_9 ++ ) {
char V_10 = F_5 ( V_2 -> V_6 ) ;
if ( ( V_10 & 2 ) != 0 )
return - 1 ;
if ( ( V_10 & 1 ) == 0 )
break;
}
F_4 ( 0x29 , V_2 -> V_5 ) ;
return F_5 ( V_2 -> V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_7 , T_2 V_11 , T_2 V_6 )
{
int V_12 = 0 ;
int V_13 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
if ( ( V_2 -> V_15 [ V_9 ] . V_7 == V_7 ) &&
( V_2 -> V_15 [ V_9 ] . V_11 == V_11 ) ) {
if ( V_2 -> V_15 [ V_9 ] . V_6 == V_6 )
V_12 = 1 ;
V_2 -> V_15 [ V_9 ] . V_6 = V_6 ;
V_9 = V_2 -> V_14 + 1 ;
}
}
if ( V_9 == V_2 -> V_14 && V_2 -> V_14 < 64 ) {
V_2 -> V_15 [ V_2 -> V_14 ] . V_7 = V_7 ;
V_2 -> V_15 [ V_2 -> V_14 ] . V_11 = V_11 ;
V_2 -> V_15 [ V_2 -> V_14 ] . V_6 = V_6 ;
V_2 -> V_14 ++ ;
}
if ( V_12 )
return 0 ;
F_1 ( V_2 , 0x29 , V_11 ) ;
F_1 ( V_2 , 0x2A , V_6 ) ;
F_1 ( V_2 , 0x28 , V_7 ) ;
F_4 ( 0x28 , V_2 -> V_5 ) ;
V_13 = 0 ;
while ( ( F_5 ( V_2 -> V_6 ) & 1 ) == 0 )
if ( V_13 > 255 )
break;
while ( ( F_5 ( V_2 -> V_6 ) & 1 ) != 0 )
if ( V_13 > 255 )
break;
V_13 = F_5 ( V_2 -> V_6 ) ;
if ( V_13 & 2 )
return - 1 ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 , int V_7 , int V_11 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_14 ; V_9 ++ ) {
if ( V_2 -> V_15 [ V_9 ] . V_7 == V_7 && V_2 -> V_15 [ V_9 ] . V_11 == V_11 )
return V_2 -> V_15 [ V_9 ] . V_6 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , int V_7 , int V_11 , int V_16 , int V_17 )
{
T_1 V_18 ;
V_18 = F_8 ( V_2 , V_7 , V_11 ) ;
V_18 = ( V_18 & V_16 ) | V_17 ;
F_7 ( V_2 , V_7 , V_11 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 , short V_19 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
break;
case V_22 :
F_9 ( V_2 , 0x8a , 0x06 , 0x7f , V_19 ? 0x80 : 0 ) ;
break;
case V_23 :
break;
}
F_1 ( V_2 , 0x2E , 0x31 ) ;
}
static void F_11 ( struct V_1 * V_2 , short V_24 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
F_7 ( V_2 , 0x8a , 0x00 , V_24 ) ;
break;
case V_22 :
F_7 ( V_2 , 0x8a , 0x07 , V_24 ) ;
break;
case V_23 :
F_7 ( V_2 , 0x42 , 0x07 , V_24 ) ;
break;
}
}
static void F_12 ( struct V_1 * V_2 , short V_25 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
F_7 ( V_2 , 0x8a , 0x00 , V_25 ) ;
break;
case V_23 :
F_7 ( V_2 , 0x42 , 0x12 , V_25 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_2 , short V_26 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
F_7 ( V_2 , 0x8a , 0x00 , V_26 ) ;
break;
case V_23 :
F_7 ( V_2 , 0x42 , 0x13 , V_26 ) ;
break;
}
}
static void F_14 ( struct V_1 * V_2 , short V_27 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
F_7 ( V_2 , 0x8a , 0x00 , V_27 ) ;
F_7 ( V_2 , 0x8a , 0x00 , V_27 ) ;
F_7 ( V_2 , 0x8a , 0x00 , V_27 ) ;
break;
case V_23 :
F_7 ( V_2 , 0x42 , 0x19 , V_27 ) ;
break;
}
}
static void F_15 ( struct V_1 * V_2 , short V_28 )
{
int V_29 ;
V_2 -> V_30 = V_28 ;
if ( V_2 -> V_20 == V_23 )
V_29 = 0x42 ;
else if ( V_2 -> V_20 == V_22 )
V_29 = 0x8a ;
else
return;
switch ( V_28 ) {
case 0 :
F_9 ( V_2 , V_29 , 0x0d , 0xfe , 0x00 ) ;
F_9 ( V_2 , V_29 , 0x0f , 0x3f , 0x80 ) ;
break;
case 1 :
F_9 ( V_2 , V_29 , 0x0d , 0xfe , 0x00 ) ;
F_9 ( V_2 , V_29 , 0x0f , 0x3f , 0x40 ) ;
break;
case 2 :
F_9 ( V_2 , V_29 , 0x0d , 0xfe , 0x00 ) ;
F_9 ( V_2 , V_29 , 0x0f , 0x3f , 0x00 ) ;
break;
case 3 :
F_9 ( V_2 , V_29 , 0x0d , 0xfe , 0x01 ) ;
F_9 ( V_2 , V_29 , 0x0f , 0x3f , 0x00 ) ;
break;
}
}
static void F_16 ( struct V_1 * V_2 , short V_31 )
{
switch ( V_2 -> V_20 ) {
case V_23 :
F_7 ( V_2 , 0x8a , 0x05 , V_31 ) ;
F_7 ( V_2 , 0x8a , 0x18 , V_31 ) ;
break;
case V_22 :
F_7 ( V_2 , 0x42 , 0x05 , V_31 ) ;
F_7 ( V_2 , 0x42 , 0x18 , V_31 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 , short V_32 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x06 , 0xcf , ( V_32 & 0x03 ) << 4 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x06 , 0xcf , ( V_32 & 0x03 ) << 4 ) ;
}
static void F_18 ( struct V_1 * V_2 , short V_33 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x06 , 0xf3 , ( V_33 & 0x03 ) << 2 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x06 , 0xf3 , ( V_33 & 0x03 ) << 2 ) ;
}
static void F_19 ( struct V_1 * V_2 , short V_34 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x06 , 0xfc , V_34 & 0x03 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x06 , 0xfc , V_34 & 0x03 ) ;
}
static void F_20 ( struct V_1 * V_2 , short V_35 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x0c , 0x9f , ( V_35 & 0x03 ) << 5 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x0c , 0x9f , ( V_35 & 0x03 ) << 5 ) ;
}
static void F_21 ( struct V_1 * V_2 , short V_36 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x10 , 0xfc , V_36 & 3 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x10 , 0xfc , V_36 & 3 ) ;
}
static void F_22 ( struct V_1 * V_2 , short V_37 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x0c , 0x7f , ( V_37 & 1 ) << 7 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x0c , 0x7 , ( V_37 & 1 ) << 7 ) ;
}
static void F_23 ( struct V_1 * V_2 , short gamma )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0xb8 , 0x00 , 0x7f , ( gamma & 1 ) << 7 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x20 , 0x7 , ( gamma & 1 ) << 7 ) ;
}
static void F_24 ( struct V_1 * V_2 , short V_38 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x06 , 0xbf , ( V_38 & 1 ) << 6 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x06 , 0xbf , ( V_38 & 1 ) << 6 ) ;
}
static void F_25 ( struct V_1 * V_2 , short V_38 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0xb8 , 0x04 , 0x1f , ( V_38 & 7 ) << 5 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x24 , 0x1f , ( V_38 & 7 ) << 5 ) ;
}
static void F_26 ( struct V_1 * V_2 , short V_38 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0xb8 , 0x08 , 0x9f , ( V_38 & 3 ) << 5 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x28 , 0x9f , ( V_38 & 3 ) << 5 ) ;
}
static void F_27 ( struct V_1 * V_2 , short V_37 )
{
if ( V_2 -> V_20 == V_22 ) {
F_9 ( V_2 , 0x8a , 0x08 , 0x07 , ( V_37 & 0x1f ) << 3 ) ;
F_9 ( V_2 , 0x8a , 0x09 , 0x07 , ( V_37 & 0x1f ) << 3 ) ;
} else if ( V_2 -> V_20 == V_23 ) {
F_9 ( V_2 , 0x42 , 0x08 , 0x07 , ( V_37 & 0x1f ) << 3 ) ;
F_9 ( V_2 , 0x42 , 0x09 , 0x07 , ( V_37 & 0x1f ) << 3 ) ;
}
}
static void F_28 ( struct V_1 * V_2 , short V_39 )
{
if ( V_2 -> V_20 == V_22 )
F_7 ( V_2 , 0x8a , 0x11 , V_39 ) ;
else if ( V_2 -> V_20 == V_23 )
F_7 ( V_2 , 0x42 , 0x11 , V_39 ) ;
}
static void F_29 ( struct V_1 * V_2 , short V_6 )
{
F_1 ( V_2 , 0x3b , V_6 ) ;
}
static void F_30 ( struct V_1 * V_2 , short V_6 )
{
F_1 ( V_2 , 0x3a , V_6 ) ;
}
static void F_31 ( struct V_1 * V_2 , short V_31 )
{
F_1 ( V_2 , 0x16 , V_31 ) ;
F_1 ( V_2 , 0x17 , ( V_31 >> 8 ) & 0x01 ) ;
}
static void F_32 ( struct V_1 * V_2 , short V_40 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x0f , 0xdf , ( V_40 & 1 ) << 5 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x0f , 0xdf , ( V_40 & 1 ) << 5 ) ;
}
static void F_33 ( struct V_1 * V_2 , short V_41 )
{
if ( V_2 -> V_20 == V_22 ) {
F_7 ( V_2 , 0x8a , 0x0a , V_41 ) ;
F_7 ( V_2 , 0x8a , 0x0b , V_41 ) ;
} else if ( V_2 -> V_20 == V_23 ) {
F_7 ( V_2 , 0x42 , 0x0a , V_41 ) ;
F_7 ( V_2 , 0x42 , 0x0b , V_41 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , short V_42 )
{
int V_43 = ( V_2 -> V_44 & V_45 ) ? 30 : 25 ;
if ( V_42 == 0 )
return;
V_43 = V_43 / V_42 ;
F_1 ( V_2 , 0x14 , 0x80 | V_43 ) ;
F_1 ( V_2 , 0x15 , 1 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_46 , T_1 V_47 )
{
F_1 ( V_2 , 0x1c , V_46 ) ;
F_1 ( V_2 , 0x1d , V_47 ) ;
}
static void F_36 ( struct V_1 * V_2 , unsigned short V_47 , unsigned short V_46 )
{
if ( V_47 % 5 == 0 ) {
V_46 /= 5 ;
V_47 /= 5 ;
}
while ( V_47 % 3 == 0 && V_46 % 3 == 0 ) {
V_46 /= 3 ;
V_47 /= 3 ;
}
while ( V_47 % 2 == 0 && V_46 % 2 == 0 ) {
V_47 /= 2 ;
V_46 /= 2 ;
}
while ( V_46 > 32 ) {
V_46 /= 2 ;
V_47 = ( V_47 + 1 ) / 2 ;
}
if ( V_46 == 32 )
V_46 -- ;
F_35 ( V_2 , V_46 , V_47 ) ;
}
static void F_37 ( struct V_1 * V_2 , short V_47 , short V_46 )
{
if ( V_47 <= 512 ) {
if ( V_47 % 5 == 0 ) {
V_47 /= 5 ;
V_46 /= 5 ;
}
} else {
V_47 = 512 ;
V_46 = 640 ;
}
while ( ( ( V_47 | V_46 ) & 1 ) == 0 ) {
V_47 >>= 1 ;
V_46 >>= 1 ;
}
while ( V_46 > 32 ) {
V_46 >>= 1 ;
V_47 = ( V_47 + 1 ) >> 1 ;
}
if ( V_46 == 32 )
V_46 -- ;
F_1 ( V_2 , 0x24 , 0x80 | V_46 ) ;
F_1 ( V_2 , 0x25 , V_47 ) ;
}
static void F_38 ( struct V_1 * V_2 , short V_48 , short V_49 )
{
int V_50 ;
V_50 = V_49 ;
if ( V_50 > 280 )
V_50 = 280 ;
F_1 ( V_2 , 0x18 , V_50 ) ;
F_1 ( V_2 , 0x19 , V_50 >> 8 ) ;
if ( V_2 -> V_44 & V_45 ) {
F_1 ( V_2 , 0x1a , 0xfc ) ;
F_1 ( V_2 , 0x1b , 0x00 ) ;
if ( V_49 > V_50 )
F_36 ( V_2 , 240 , 240 ) ;
else
F_36 ( V_2 , V_50 , 240 ) ;
} else {
F_1 ( V_2 , 0x1a , 0x1a ) ;
F_1 ( V_2 , 0x1b , 0x01 ) ;
if ( V_50 > 256 )
F_36 ( V_2 , 270 , 270 ) ;
else
F_36 ( V_2 , V_50 , 270 ) ;
}
F_1 ( V_2 , 0x12 , 0 ) ;
F_1 ( V_2 , 0x13 , V_51 ) ;
F_1 ( V_2 , 0x42 , 0x00 ) ;
F_1 ( V_2 , 0x43 , 0x00 ) ;
F_1 ( V_2 , 0x44 , V_51 ) ;
F_1 ( V_2 , 0x22 , V_48 + 8 ) ;
F_1 ( V_2 , 0x23 , ( V_48 + 8 ) >> 8 ) ;
if ( V_2 -> V_44 & V_45 )
F_37 ( V_2 , V_48 , 640 ) ;
else
F_37 ( V_2 , V_48 + 8 , 768 ) ;
F_1 ( V_2 , 0x30 , F_3 ( V_2 , 0x30 ) & 0xfe ) ;
F_1 ( V_2 , 0x08 , F_3 ( V_2 , 0x08 ) | 0x01 ) ;
F_1 ( V_2 , 0x01 , F_3 ( V_2 , 0x01 ) & 0xfd ) ;
F_1 ( V_2 , 0x32 , 0x00 ) ;
F_1 ( V_2 , 0x33 , V_51 ) ;
}
static void F_39 ( struct V_1 * V_2 , short V_52 )
{
if ( V_2 -> V_20 == V_22 )
F_9 ( V_2 , 0x8a , 0x0d , 0x7f , ( V_52 & 1 ) << 7 ) ;
else if ( V_2 -> V_20 == V_23 )
F_9 ( V_2 , 0x42 , 0x0d , 0x7f , ( V_52 & 1 ) << 7 ) ;
}
static int F_40 ( struct V_1 * V_2 , char T_3 * V_53 , int V_54 , int V_13 )
{
int V_55 ;
int V_56 = 2 * V_2 -> V_48 ;
char V_18 [ V_56 + 32 ] ;
int V_57 = 0 ;
int V_58 = 0 ;
unsigned char V_59 = 0x5 ;
if ( V_54 )
V_59 |= 0x20 ;
F_1 ( V_2 , 0x08 , V_59 ) ;
for ( V_55 = 0 ; V_55 < V_2 -> V_49 ; V_55 ++ ) {
F_41 ( 0 , V_2 -> V_60 ) ;
F_42 ( V_18 , V_2 -> V_60 , V_56 + 32 ) ;
V_57 -= V_2 -> V_49 ;
while ( V_57 <= 0 ) {
int V_61 = V_56 ;
if ( V_61 + V_58 > V_13 )
V_61 = V_13 - V_58 ;
V_57 += V_2 -> V_49 ;
if ( F_43 ( V_53 , V_18 + 32 , V_61 ) )
return V_58 ? V_58 : - V_62 ;
V_53 += V_61 ;
V_58 += V_61 ;
}
}
return V_58 ;
}
static int F_44 ( struct V_63 * V_63 , void * V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
F_46 ( V_66 -> V_67 , V_2 -> V_68 . V_69 , sizeof( V_66 -> V_67 ) ) ;
F_46 ( V_66 -> V_70 , L_1 , sizeof( V_66 -> V_70 ) ) ;
F_46 ( V_66 -> V_71 , L_2 , sizeof( V_66 -> V_71 ) ) ;
V_66 -> V_72 = V_73 | V_74 ;
return 0 ;
}
static int F_47 ( struct V_63 * V_63 , void * V_75 , struct V_76 * V_77 )
{
static const char * V_78 [ 4 ] = {
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
if ( V_77 -> V_3 > 3 )
return - V_79 ;
F_46 ( V_77 -> V_69 , V_78 [ V_77 -> V_3 ] , sizeof( V_77 -> V_69 ) ) ;
V_77 -> type = V_80 ;
V_77 -> V_81 = 0 ;
V_77 -> V_82 = 0 ;
V_77 -> V_44 = V_83 ;
V_77 -> V_84 = 0 ;
return 0 ;
}
static int F_48 ( struct V_63 * V_63 , void * V_75 , unsigned int * V_85 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
* V_85 = V_2 -> V_52 ;
return 0 ;
}
static int F_49 ( struct V_63 * V_63 , void * V_75 , unsigned int V_85 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
if ( V_85 > 3 )
return - V_79 ;
F_50 ( & V_2 -> V_86 ) ;
V_2 -> V_52 = V_85 ;
F_10 ( V_2 , V_85 & 1 ) ;
F_39 ( V_2 , V_85 >> 1 ) ;
F_51 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_52 ( struct V_63 * V_63 , void * V_75 , T_4 * V_44 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
* V_44 = V_2 -> V_44 ;
return 0 ;
}
static int F_53 ( struct V_63 * V_63 , void * V_75 , T_4 * V_44 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
int V_87 = 0 ;
V_2 -> V_44 = * V_44 ;
F_50 ( & V_2 -> V_86 ) ;
if ( V_2 -> V_44 & V_88 ) {
F_34 ( V_2 , 30 ) ;
F_32 ( V_2 , 0 ) ;
F_15 ( V_2 , 1 ) ;
} else if ( V_2 -> V_44 & V_89 ) {
F_34 ( V_2 , 25 ) ;
F_32 ( V_2 , 0 ) ;
F_15 ( V_2 , 2 ) ;
} else if ( V_2 -> V_44 & V_90 ) {
F_34 ( V_2 , 25 ) ;
F_32 ( V_2 , 1 ) ;
F_15 ( V_2 , 2 ) ;
} else {
V_87 = - V_79 ;
}
F_51 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_54 ( struct V_63 * V_63 , void * V_64 ,
struct V_91 * V_92 )
{
switch ( V_92 -> V_93 ) {
case V_94 :
return F_55 ( V_92 , 0 , 255 , 1 , 139 ) ;
case V_95 :
return F_55 ( V_92 , 0 , 255 , 1 , 70 ) ;
case V_96 :
return F_55 ( V_92 , 0 , 255 , 1 , 64 ) ;
case V_97 :
return F_55 ( V_92 , 0 , 255 , 1 , 0 ) ;
}
return - V_79 ;
}
static int F_56 ( struct V_63 * V_63 , void * V_64 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
int V_87 = 0 ;
switch ( V_99 -> V_93 ) {
case V_94 :
V_99 -> V_4 = V_2 -> V_27 ;
break;
case V_95 :
V_99 -> V_4 = V_2 -> V_26 ;
break;
case V_96 :
V_99 -> V_4 = V_2 -> V_100 ;
break;
case V_97 :
V_99 -> V_4 = V_2 -> V_24 ;
break;
default:
V_87 = - V_79 ;
break;
}
return V_87 ;
}
static int F_57 ( struct V_63 * V_63 , void * V_64 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
int V_87 = 0 ;
F_50 ( & V_2 -> V_86 ) ;
switch ( V_99 -> V_93 ) {
case V_94 :
V_2 -> V_27 = V_99 -> V_4 ;
F_14 ( V_2 , V_2 -> V_27 ) ;
break;
case V_95 :
V_2 -> V_26 = V_99 -> V_4 ;
F_13 ( V_2 , V_2 -> V_26 ) ;
break;
case V_96 :
V_2 -> V_100 = V_99 -> V_4 ;
F_12 ( V_2 , V_2 -> V_100 ) ;
break;
case V_97 :
V_2 -> V_24 = V_99 -> V_4 ;
F_11 ( V_2 , V_2 -> V_24 ) ;
break;
default:
V_87 = - V_79 ;
break;
}
F_51 ( & V_2 -> V_86 ) ;
return V_87 ;
}
static int F_58 ( struct V_63 * V_63 , void * V_75 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
struct V_103 * V_104 = & V_102 -> V_102 . V_104 ;
V_104 -> V_48 = V_2 -> V_48 ;
V_104 -> V_49 = V_2 -> V_49 ;
V_104 -> V_105 = V_2 -> V_48 == 15 ?
V_106 : V_107 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_110 = 2 * V_2 -> V_48 ;
V_104 -> V_111 = 2 * V_2 -> V_48 * V_2 -> V_49 ;
V_104 -> V_112 = V_113 ;
return 0 ;
}
static int F_59 ( struct V_63 * V_63 , void * V_75 , struct V_101 * V_102 )
{
struct V_103 * V_104 = & V_102 -> V_102 . V_104 ;
if ( V_104 -> V_49 < 16 || V_104 -> V_49 > 480 )
return - V_79 ;
if ( V_104 -> V_48 < 16 || V_104 -> V_48 > 640 )
return - V_79 ;
if ( V_104 -> V_105 != V_106 &&
V_104 -> V_105 != V_107 )
return - V_79 ;
V_104 -> V_108 = V_109 ;
V_104 -> V_110 = 2 * V_104 -> V_48 ;
V_104 -> V_111 = 2 * V_104 -> V_48 * V_104 -> V_49 ;
V_104 -> V_112 = V_113 ;
return 0 ;
}
static int F_60 ( struct V_63 * V_63 , void * V_75 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
struct V_103 * V_104 = & V_102 -> V_102 . V_104 ;
int V_87 = F_59 ( V_63 , V_75 , V_102 ) ;
if ( V_87 )
return V_87 ;
F_50 ( & V_2 -> V_86 ) ;
V_2 -> V_48 = V_104 -> V_48 ;
V_2 -> V_49 = V_104 -> V_49 ;
V_2 -> V_114 = ( V_104 -> V_105 == V_106 ) ? 15 : 16 ;
F_38 ( V_2 , V_2 -> V_48 , V_2 -> V_49 ) ;
F_51 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_61 ( struct V_63 * V_63 , void * V_75 , struct V_115 * V_102 )
{
static struct V_115 V_116 [] = {
{ 0 , 0 , 0 ,
L_7 , V_106 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 0 , 0 , 0 ,
L_8 , V_107 ,
{ 0 , 0 , 0 , 0 }
} ,
} ;
enum V_117 type = V_102 -> type ;
if ( V_102 -> V_3 > 1 )
return - V_79 ;
* V_102 = V_116 [ V_102 -> V_3 ] ;
V_102 -> type = type ;
return 0 ;
}
static T_5 F_62 ( struct V_63 * V_63 , char T_3 * V_53 ,
T_6 V_13 , T_7 * V_118 )
{
struct V_1 * V_2 = F_45 ( V_63 ) ;
int V_58 ;
F_50 ( & V_2 -> V_86 ) ;
V_58 = F_40 ( V_2 , V_53 , ( V_2 -> V_114 == 15 ) , V_13 ) ;
F_51 ( & V_2 -> V_86 ) ;
return V_58 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_93 ;
int V_119 , V_120 ;
int V_9 ;
static const unsigned char V_121 [] = {
0x4c , 0x30 , 0x00 , 0xe8 ,
0xb6 , 0xe2 , 0x00 , 0x00 ,
0xff , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x78 , 0x98 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x34 , 0x0a , 0xf4 , 0xce ,
0xe4
} ;
V_2 -> V_60 = F_64 ( V_122 , 0x800 ) ;
if ( ! V_2 -> V_60 )
return - V_123 ;
if ( ! F_65 ( 0x9a01 , 1 , L_9 ) ) {
F_66 ( V_124 L_10 ) ;
F_67 ( V_2 -> V_60 ) ;
return - V_125 ;
}
if ( ! F_65 ( V_2 -> V_5 , 3 , L_1 ) ) {
F_66 ( V_124 L_11 , V_2 -> V_5 ) ;
F_68 ( 0x9a01 , 1 ) ;
F_67 ( V_2 -> V_60 ) ;
return - V_125 ;
}
F_4 ( 0xb8 , 0x9a01 ) ;
F_4 ( V_2 -> V_5 >> 4 , 0x9a01 ) ;
V_93 = F_3 ( V_2 , 3 ) ;
V_120 = F_6 ( V_2 , 0x43 ) ;
if ( V_120 != - 1 )
V_119 = 2 ;
else if ( F_6 ( V_2 , 0xb9 ) != - 1 )
V_119 = 3 ;
else if ( F_6 ( V_2 , 0x8b ) != - 1 )
V_119 = 1 ;
else
V_119 = 0 ;
F_66 ( V_126 L_12 , V_119 ) ;
if ( V_119 == 0 ) {
F_68 ( V_2 -> V_5 , 3 ) ;
F_68 ( 0x9a01 , 1 ) ;
F_67 ( V_2 -> V_60 ) ;
return - V_127 ;
}
F_1 ( V_2 , 0x04 , V_122 >> 12 ) ;
for ( V_9 = 0 ; V_9 < 0x19 ; V_9 ++ ) {
if ( V_121 [ V_9 ] == 0xff )
F_9 ( V_2 , 0x8a , V_9 , 0x07 , 0x00 ) ;
else
F_7 ( V_2 , 0x8a , V_9 , V_121 [ V_9 ] ) ;
}
F_7 ( V_2 , 0xb8 , 0x00 , 0x12 ) ;
F_7 ( V_2 , 0xb8 , 0x04 , 0x00 ) ;
F_7 ( V_2 , 0xb8 , 0x07 , 0x00 ) ;
F_7 ( V_2 , 0xb8 , 0x08 , 0x00 ) ;
F_7 ( V_2 , 0xb8 , 0x09 , 0xff ) ;
F_7 ( V_2 , 0xb8 , 0x0a , 0x00 ) ;
F_7 ( V_2 , 0xb8 , 0x0b , 0x10 ) ;
F_7 ( V_2 , 0xb8 , 0x10 , 0x03 ) ;
F_1 ( V_2 , 0x01 , 0x00 ) ;
F_1 ( V_2 , 0x05 , 0xa0 ) ;
F_1 ( V_2 , 0x08 , 0x25 ) ;
F_1 ( V_2 , 0x09 , 0x00 ) ;
F_1 ( V_2 , 0x0a , 0x20 | V_51 ) ;
F_1 ( V_2 , 0x10 , 0x02 ) ;
F_1 ( V_2 , 0x1e , 0x0c ) ;
F_1 ( V_2 , 0x1f , 0x03 ) ;
F_1 ( V_2 , 0x26 , 0x06 ) ;
F_1 ( V_2 , 0x2b , 0x00 ) ;
F_1 ( V_2 , 0x2c , 0x20 ) ;
F_1 ( V_2 , 0x2d , 0x00 ) ;
F_1 ( V_2 , 0x2f , 0x70 ) ;
F_1 ( V_2 , 0x32 , 0x00 ) ;
F_1 ( V_2 , 0x33 , V_51 ) ;
F_1 ( V_2 , 0x34 , 0x00 ) ;
F_1 ( V_2 , 0x35 , 0x00 ) ;
F_1 ( V_2 , 0x3a , 0x80 ) ;
F_1 ( V_2 , 0x3b , 0x10 ) ;
F_1 ( V_2 , 0x20 , 0x00 ) ;
F_1 ( V_2 , 0x21 , 0x00 ) ;
F_1 ( V_2 , 0x30 , 0x22 ) ;
return 0 ;
}
static int T_8 F_69 ( void )
{
struct V_1 * V_2 = & V_128 ;
struct V_129 * V_68 = & V_2 -> V_68 ;
int V_130 ;
F_46 ( V_68 -> V_69 , L_13 , sizeof( V_68 -> V_69 ) ) ;
F_70 ( V_68 , L_14 ) ;
#ifndef F_71
if ( ! V_131 ) {
F_72 ( V_68 ,
L_15 ) ;
return - V_127 ;
}
#endif
V_2 -> V_20 = V_22 ;
V_2 -> V_5 = V_132 ;
V_2 -> V_6 = V_132 + 1 ;
if ( F_63 ( V_2 ) ) {
F_72 ( V_68 , L_16 ) ;
return - V_127 ;
}
V_130 = F_73 ( NULL , V_68 ) ;
if ( V_130 < 0 ) {
F_72 ( V_68 , L_17 ) ;
return V_130 ;
}
F_46 ( V_2 -> V_133 . V_69 , V_68 -> V_69 , sizeof( V_2 -> V_133 . V_69 ) ) ;
V_2 -> V_133 . V_68 = V_68 ;
V_2 -> V_133 . V_134 = & V_135 ;
V_2 -> V_133 . V_136 = & V_137 ;
V_2 -> V_133 . V_138 = V_139 ;
F_74 ( & V_2 -> V_133 , V_2 ) ;
F_75 ( & V_2 -> V_86 ) ;
V_2 -> V_44 = V_140 ;
V_2 -> V_49 = 240 ;
V_2 -> V_48 = 320 ;
V_2 -> V_114 = 15 ;
V_2 -> V_27 = 139 ;
V_2 -> V_26 = 70 ;
V_2 -> V_24 = 0 ;
V_2 -> V_100 = 64 ;
F_33 ( V_2 , 75 ) ;
F_38 ( V_2 , 320 , 240 ) ;
F_10 ( V_2 , 0 ) ;
F_39 ( V_2 , 0 ) ;
if ( F_76 ( & V_2 -> V_133 , V_141 , V_142 ) < 0 ) {
F_77 ( & V_2 -> V_68 ) ;
F_68 ( V_2 -> V_5 , 3 ) ;
F_68 ( 0x9a01 , 1 ) ;
F_67 ( V_2 -> V_60 ) ;
return - V_79 ;
}
return 0 ;
}
static void T_9 F_78 ( void )
{
struct V_1 * V_2 = & V_128 ;
F_79 ( & V_2 -> V_133 ) ;
F_68 ( V_2 -> V_5 , 3 ) ;
F_68 ( 0x9a01 , 1 ) ;
F_67 ( V_2 -> V_60 ) ;
}
