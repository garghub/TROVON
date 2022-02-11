static void
F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_3 [ 5 ] = 0x80 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( V_5 )
V_3 [ 5 ] |= V_5 -> V_10 ;
F_3 ( & V_7 -> V_9 ) ;
}
static int
F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 ;
if ( V_12 -> V_19 < 6 ) {
F_7 ( V_20 L_1
L_2 , V_12 -> V_19 ) ;
return - 1 ;
}
V_3 [ 0 ] = V_16 -> V_21 -> V_22 ( V_16 ) ;
if ( V_3 [ 0 ] == V_23 )
V_3 [ 1 ] = 0x80 ;
V_3 [ 2 ] = V_16 -> V_21 -> V_24 ( V_16 ) ;
if ( F_8 ( V_16 -> V_25 ) -> V_26 == V_27 )
F_1 ( V_14 -> V_28 , V_3 ) ;
if ( V_12 -> V_19 < 8 ) {
V_3 [ 4 ] = 1 ;
return 0 ;
}
V_3 [ 7 ] = 0x32 ;
if ( V_12 -> V_19 < 36 ) {
V_3 [ 4 ] = 3 ;
return 0 ;
}
snprintf ( ( unsigned char * ) & V_3 [ 8 ] , 8 , L_3 ) ;
snprintf ( ( unsigned char * ) & V_3 [ 16 ] , 16 , L_4 ,
& F_9 ( V_16 ) -> V_29 [ 0 ] ) ;
snprintf ( ( unsigned char * ) & V_3 [ 32 ] , 4 , L_4 ,
& F_9 ( V_16 ) -> V_30 [ 0 ] ) ;
V_3 [ 4 ] = 31 ;
return 0 ;
}
static int
F_10 ( struct V_11 * V_12 , unsigned char * V_3 )
{
V_3 [ 1 ] = 0x00 ;
if ( V_12 -> V_19 < 8 )
return 0 ;
V_3 [ 4 ] = 0x0 ;
if ( F_6 ( V_12 ) -> V_25 -> V_31 &
V_32 ) {
V_3 [ 3 ] = 3 ;
V_3 [ 5 ] = 0x80 ;
V_3 [ 6 ] = 0x83 ;
V_3 [ 7 ] = 0x86 ;
}
return 0 ;
}
static int
F_11 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
T_1 V_33 = 0 ;
V_3 [ 1 ] = 0x80 ;
if ( V_16 -> V_25 -> V_31 &
V_32 ) {
T_2 V_34 ;
V_34 =
strlen ( & F_9 ( V_16 ) -> V_35 [ 0 ] ) ;
V_34 ++ ;
if ( ( ( V_33 + 4 ) + V_34 ) > V_12 -> V_19 ) {
V_33 += V_34 ;
V_3 [ 2 ] = ( ( V_33 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_33 & 0xff ) ;
return 0 ;
}
V_33 += sprintf ( ( unsigned char * ) & V_3 [ 4 ] , L_4 ,
& F_9 ( V_16 ) -> V_35 [ 0 ] ) ;
V_33 ++ ;
V_3 [ 3 ] = V_33 ;
}
return 0 ;
}
static int
F_12 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_1 * V_2 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_38 * V_39 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned char V_40 , V_41 ;
unsigned char * V_42 = & F_9 ( V_16 ) -> V_29 [ 0 ] ;
T_2 V_43 ;
T_2 V_34 , V_44 = 0 ;
int V_45 ;
T_1 V_33 = 0 , V_46 ;
V_3 [ 1 ] = 0x83 ;
V_44 = 4 ;
if ( ! ( V_16 -> V_25 -> V_31 & V_32 ) )
goto V_47;
if ( V_44 + 20 > V_12 -> V_19 )
goto V_47;
V_3 [ V_44 ++ ] = 0x1 ;
V_3 [ V_44 ] = 0x00 ;
V_3 [ V_44 ++ ] = 0x3 ;
V_44 ++ ;
V_3 [ V_44 ++ ] = 0x10 ;
V_3 [ V_44 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_44 ++ ] = 0x01 ;
V_3 [ V_44 ++ ] = 0x40 ;
V_3 [ V_44 ] = ( 0x5 << 4 ) ;
V_40 = F_13 (
& F_9 ( V_16 ) -> V_35 [ 0 ] ) ;
V_3 [ V_44 ++ ] |= ( V_40 & 0xf0 ) >> 4 ;
for ( V_45 = 0 ; V_45 < 24 ; V_45 += 2 ) {
V_41 = F_13 (
& F_9 ( V_16 ) -> V_35 [ V_45 + 2 ] ) ;
V_3 [ V_44 ] = ( V_40 & 0x0f ) << 4 ;
V_3 [ V_44 ++ ] |= ( V_41 & 0xf0 ) >> 4 ;
V_40 = V_41 ;
}
V_33 = 20 ;
V_44 = ( V_33 + 4 ) ;
V_47:
V_46 = 8 ;
V_43 = 4 ;
V_43 += 8 ;
V_43 += strlen ( V_42 ) ;
V_43 ++ ;
if ( V_16 -> V_25 -> V_31 &
V_32 ) {
V_34 =
strlen ( & F_9 ( V_16 ) -> V_35 [ 0 ] ) ;
V_34 ++ ;
if ( ( V_33 + ( V_46 + 4 ) +
( V_43 + V_34 ) ) >
V_12 -> V_19 ) {
V_33 += ( V_43 + V_34 ) ;
goto V_48;
}
V_46 += sprintf ( ( unsigned char * ) & V_3 [ V_44 + 12 ] ,
L_5 , V_42 ,
& F_9 ( V_16 ) -> V_35 [ 0 ] ) ;
}
V_3 [ V_44 ] = 0x2 ;
V_3 [ V_44 + 1 ] = 0x1 ;
V_3 [ V_44 + 2 ] = 0x0 ;
memcpy ( ( unsigned char * ) & V_3 [ V_44 + 4 ] , L_3 , 8 ) ;
V_46 ++ ;
V_3 [ V_44 + 3 ] = V_46 ;
V_33 += ( V_46 + 4 ) ;
V_44 += ( V_46 + 4 ) ;
V_48:
V_2 = V_14 -> V_28 ;
if ( V_2 ) {
struct V_49 * V_50 ;
T_2 V_51 , V_52 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 ;
V_37 = V_2 -> V_56 ;
if ( ( ( V_33 + 4 ) + 8 ) > V_12 -> V_19 ) {
V_33 += 8 ;
goto V_57;
}
V_3 [ V_44 ] =
( F_14 ( V_37 ) -> F_15 ( V_37 ) << 4 ) ;
V_3 [ V_44 ++ ] |= 0x1 ;
V_3 [ V_44 ] = 0x80 ;
V_3 [ V_44 ] |= 0x10 ;
V_3 [ V_44 ++ ] |= 0x4 ;
V_44 ++ ;
V_3 [ V_44 ++ ] = 4 ;
V_44 += 2 ;
V_3 [ V_44 ++ ] = ( ( V_2 -> V_58 >> 8 ) & 0xff ) ;
V_3 [ V_44 ++ ] = ( V_2 -> V_58 & 0xff ) ;
V_33 += 8 ;
V_57:
if ( F_8 ( V_16 -> V_25 ) -> V_26 !=
V_27 )
goto V_59;
if ( ( ( V_33 + 4 ) + 8 ) > V_12 -> V_19 ) {
V_33 += 8 ;
goto V_60;
}
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
goto V_60;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( ! ( V_5 ) ) {
F_3 ( & V_7 -> V_9 ) ;
goto V_60;
}
V_54 = V_5 -> V_54 ;
F_3 ( & V_7 -> V_9 ) ;
V_3 [ V_44 ] =
( F_14 ( V_37 ) -> F_15 ( V_37 ) << 4 ) ;
V_3 [ V_44 ++ ] |= 0x1 ;
V_3 [ V_44 ] = 0x80 ;
V_3 [ V_44 ] |= 0x10 ;
V_3 [ V_44 ++ ] |= 0x5 ;
V_44 ++ ;
V_3 [ V_44 ++ ] = 4 ;
V_44 += 2 ;
V_3 [ V_44 ++ ] = ( ( V_54 >> 8 ) & 0xff ) ;
V_3 [ V_44 ++ ] = ( V_54 & 0xff ) ;
V_33 += 8 ;
V_60:
if ( ( ( V_33 + 4 ) + 8 ) > V_12 -> V_19 ) {
V_33 += 8 ;
goto V_59;
}
V_39 = V_16 -> V_61 ;
if ( ! ( V_39 ) )
goto V_59;
F_2 ( & V_39 -> V_62 ) ;
V_50 = V_39 -> V_50 ;
if ( ! ( V_50 ) ) {
F_3 ( & V_39 -> V_62 ) ;
goto V_59;
}
V_53 = V_50 -> V_53 ;
F_3 ( & V_39 -> V_62 ) ;
V_3 [ V_44 ++ ] |= 0x1 ;
V_3 [ V_44 ++ ] |= 0x6 ;
V_44 ++ ;
V_3 [ V_44 ++ ] = 4 ;
V_44 += 2 ;
V_3 [ V_44 ++ ] = ( ( V_53 >> 8 ) & 0xff ) ;
V_3 [ V_44 ++ ] = ( V_53 & 0xff ) ;
V_33 += 8 ;
V_59:
V_52 = strlen ( F_14 ( V_37 ) -> F_16 ( V_37 ) ) ;
V_52 += 10 ;
V_51 = ( ( - V_52 ) & 3 ) ;
if ( V_51 != 0 )
V_52 += V_51 ;
V_52 += 4 ;
if ( ( ( V_33 + 4 ) + V_52 ) > V_12 -> V_19 ) {
V_33 += V_52 ;
goto V_63;
}
V_3 [ V_44 ] =
( F_14 ( V_37 ) -> F_15 ( V_37 ) << 4 ) ;
V_3 [ V_44 ++ ] |= 0x3 ;
V_3 [ V_44 ] = 0x80 ;
V_3 [ V_44 ] |= 0x10 ;
V_3 [ V_44 ++ ] |= 0x8 ;
V_44 += 2 ;
V_55 = F_14 ( V_37 ) -> F_17 ( V_37 ) ;
V_52 = sprintf ( & V_3 [ V_44 ] , L_6 ,
F_14 ( V_37 ) -> F_16 ( V_37 ) , V_55 ) ;
V_52 += 1 ;
if ( V_51 )
V_52 += V_51 ;
V_3 [ V_44 - 1 ] = V_52 ;
V_44 += V_52 ;
V_33 += ( V_52 + 4 ) ;
}
V_63:
V_3 [ 2 ] = ( ( V_33 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_33 & 0xff ) ;
return 0 ;
}
static int
F_18 ( struct V_11 * V_12 , unsigned char * V_3 )
{
if ( V_12 -> V_19 < 60 )
return 0 ;
V_3 [ 1 ] = 0x86 ;
V_3 [ 2 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( F_19 ( F_6 ( V_12 ) ) -> V_64 > 0 )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static int
F_20 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
int V_65 = 0 ;
if ( F_19 ( V_16 ) -> V_66 || F_19 ( V_16 ) -> V_67 )
V_65 = 1 ;
if ( V_12 -> V_19 < ( 0x10 + 4 ) ) {
F_7 ( V_68 L_7
L_8 ,
V_12 -> V_19 ) ;
return - 1 ;
}
if ( V_65 && V_12 -> V_19 < ( 0x3c + 4 ) ) {
F_7 ( V_68 L_7
L_9 ,
V_12 -> V_19 ) ;
V_65 = 0 ;
}
V_3 [ 0 ] = V_16 -> V_21 -> V_22 ( V_16 ) ;
V_3 [ 1 ] = 0xb0 ;
V_3 [ 3 ] = V_65 ? 0x3c : 0x10 ;
F_21 ( 1 , & V_3 [ 6 ] ) ;
F_22 ( F_19 ( V_16 ) -> V_69 , & V_3 [ 8 ] ) ;
F_22 ( F_19 ( V_16 ) -> V_70 , & V_3 [ 12 ] ) ;
if ( ! V_65 || V_12 -> V_19 < ( 0x3c + 4 ) )
return 0 ;
F_22 ( F_19 ( V_16 ) -> V_71 , & V_3 [ 20 ] ) ;
F_22 ( F_19 ( V_16 ) -> V_72 ,
& V_3 [ 24 ] ) ;
F_22 ( F_19 ( V_16 ) -> V_73 , & V_3 [ 28 ] ) ;
F_22 ( F_19 ( V_16 ) -> V_74 ,
& V_3 [ 32 ] ) ;
if ( F_19 ( V_16 ) -> V_74 != 0 )
V_3 [ 32 ] |= 0x80 ;
return 0 ;
}
static int
F_23 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
V_3 [ 0 ] = V_16 -> V_21 -> V_22 ( V_16 ) ;
V_3 [ 1 ] = 0xb2 ;
F_21 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( F_19 ( V_16 ) -> V_66 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( F_19 ( V_16 ) -> V_67 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static int
F_24 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 ;
unsigned char * V_75 = V_12 -> V_17 -> V_76 ;
if ( ! ( V_75 [ 1 ] & 0x1 ) )
return F_4 ( V_12 ) ;
if ( V_12 -> V_19 < 4 ) {
F_7 ( V_20 L_1
L_10 , V_12 -> V_19 ) ;
return - 1 ;
}
V_3 [ 0 ] = V_16 -> V_21 -> V_22 ( V_16 ) ;
switch ( V_75 [ 2 ] ) {
case 0x00 :
return F_10 ( V_12 , V_3 ) ;
case 0x80 :
return F_11 ( V_12 , V_3 ) ;
case 0x83 :
return F_12 ( V_12 , V_3 ) ;
case 0x86 :
return F_18 ( V_12 , V_3 ) ;
case 0xb0 :
return F_20 ( V_12 , V_3 ) ;
case 0xb2 :
return F_23 ( V_12 , V_3 ) ;
default:
F_7 ( V_20 L_11 , V_75 [ 2 ] ) ;
return - 1 ;
}
return 0 ;
}
static int
F_25 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 ;
unsigned long long V_77 = V_16 -> V_21 -> V_78 ( V_16 ) ;
T_2 V_79 ;
if ( V_77 >= 0x00000000ffffffff )
V_79 = 0xffffffff ;
else
V_79 = ( T_2 ) V_77 ;
V_3 [ 0 ] = ( V_79 >> 24 ) & 0xff ;
V_3 [ 1 ] = ( V_79 >> 16 ) & 0xff ;
V_3 [ 2 ] = ( V_79 >> 8 ) & 0xff ;
V_3 [ 3 ] = V_79 & 0xff ;
V_3 [ 4 ] = ( F_19 ( V_16 ) -> V_80 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( F_19 ( V_16 ) -> V_80 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( F_19 ( V_16 ) -> V_80 >> 8 ) & 0xff ;
V_3 [ 7 ] = F_19 ( V_16 ) -> V_80 & 0xff ;
if ( F_19 ( V_16 ) -> V_66 || F_19 ( V_16 ) -> V_67 )
F_22 ( 0xFFFFFFFF , & V_3 [ 0 ] ) ;
return 0 ;
}
static int
F_26 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 ;
unsigned long long V_79 = V_16 -> V_21 -> V_78 ( V_16 ) ;
V_3 [ 0 ] = ( V_79 >> 56 ) & 0xff ;
V_3 [ 1 ] = ( V_79 >> 48 ) & 0xff ;
V_3 [ 2 ] = ( V_79 >> 40 ) & 0xff ;
V_3 [ 3 ] = ( V_79 >> 32 ) & 0xff ;
V_3 [ 4 ] = ( V_79 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_79 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_79 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_79 & 0xff ;
V_3 [ 8 ] = ( F_19 ( V_16 ) -> V_80 >> 24 ) & 0xff ;
V_3 [ 9 ] = ( F_19 ( V_16 ) -> V_80 >> 16 ) & 0xff ;
V_3 [ 10 ] = ( F_19 ( V_16 ) -> V_80 >> 8 ) & 0xff ;
V_3 [ 11 ] = F_19 ( V_16 ) -> V_80 & 0xff ;
if ( F_19 ( V_16 ) -> V_66 || F_19 ( V_16 ) -> V_67 )
V_3 [ 14 ] = 0x80 ;
return 0 ;
}
static int
F_27 ( unsigned char * V_81 )
{
V_81 [ 0 ] = 0x01 ;
V_81 [ 1 ] = 0x0a ;
return 12 ;
}
static int
F_28 ( struct V_15 * V_16 , unsigned char * V_81 )
{
V_81 [ 0 ] = 0x0a ;
V_81 [ 1 ] = 0x0a ;
V_81 [ 2 ] = 2 ;
V_81 [ 4 ] = ( F_19 ( V_16 ) -> V_82 == 2 ) ? 0x30 :
( F_19 ( V_16 ) -> V_82 == 1 ) ? 0x20 : 0x00 ;
V_81 [ 5 ] = ( F_19 ( V_16 ) -> V_83 ) ? 0x40 : 0x00 ;
V_81 [ 8 ] = 0xff ;
V_81 [ 9 ] = 0xff ;
V_81 [ 11 ] = 30 ;
return 12 ;
}
static int
F_29 ( struct V_15 * V_16 , unsigned char * V_81 )
{
V_81 [ 0 ] = 0x08 ;
V_81 [ 1 ] = 0x12 ;
if ( F_19 ( V_16 ) -> V_64 > 0 )
V_81 [ 2 ] = 0x04 ;
V_81 [ 12 ] = 0x20 ;
return 20 ;
}
static void
F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_84 :
case V_23 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void
F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_84 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int
F_32 ( struct V_11 * V_12 , int V_85 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
char * V_75 = V_12 -> V_17 -> V_76 ;
unsigned char * V_86 = V_12 -> V_17 -> V_18 ;
int type = V_16 -> V_21 -> V_22 ( V_16 ) ;
int V_87 = ( V_85 ) ? 8 : 4 ;
int V_88 = 0 ;
unsigned char V_3 [ V_89 ] ;
memset ( V_3 , 0 , V_89 ) ;
switch ( V_75 [ 2 ] & 0x3f ) {
case 0x01 :
V_88 = F_27 ( & V_3 [ V_87 ] ) ;
break;
case 0x08 :
V_88 = F_29 ( V_16 , & V_3 [ V_87 ] ) ;
break;
case 0x0a :
V_88 = F_28 ( V_16 , & V_3 [ V_87 ] ) ;
break;
case 0x3f :
V_88 = F_27 ( & V_3 [ V_87 ] ) ;
V_88 += F_29 ( V_16 , & V_3 [ V_87 + V_88 ] ) ;
V_88 += F_28 ( V_16 , & V_3 [ V_87 + V_88 ] ) ;
break;
default:
F_7 ( V_20 L_12 ,
V_75 [ 2 ] & 0x3f ) ;
return V_90 ;
}
V_87 += V_88 ;
if ( V_85 ) {
V_87 -= 2 ;
V_3 [ 0 ] = ( V_87 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_87 & 0xff ;
if ( ( F_5 ( V_12 ) -> V_91 & V_92 ) ||
( V_12 -> V_93 &&
( V_12 -> V_93 -> V_94 & V_92 ) ) )
F_30 ( & V_3 [ 3 ] , type ) ;
if ( ( F_19 ( V_16 ) -> V_64 > 0 ) &&
( F_19 ( V_16 ) -> V_95 > 0 ) )
F_31 ( & V_3 [ 3 ] , type ) ;
if ( ( V_87 + 2 ) > V_12 -> V_19 )
V_87 = V_12 -> V_19 ;
} else {
V_87 -= 1 ;
V_3 [ 0 ] = V_87 & 0xff ;
if ( ( F_5 ( V_12 ) -> V_91 & V_92 ) ||
( V_12 -> V_93 &&
( V_12 -> V_93 -> V_94 & V_92 ) ) )
F_30 ( & V_3 [ 2 ] , type ) ;
if ( ( F_19 ( V_16 ) -> V_64 > 0 ) &&
( F_19 ( V_16 ) -> V_95 > 0 ) )
F_31 ( & V_3 [ 2 ] , type ) ;
if ( ( V_87 + 1 ) > V_12 -> V_19 )
V_87 = V_12 -> V_19 ;
}
memcpy ( V_86 , V_3 , V_87 ) ;
return 0 ;
}
static int
F_33 ( struct V_11 * V_12 )
{
unsigned char * V_75 = V_12 -> V_17 -> V_76 ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 ;
T_3 V_96 = 0 , V_97 = 0 ;
if ( V_75 [ 1 ] & 0x01 ) {
F_7 ( V_20 L_13
L_14 ) ;
return V_98 ;
}
if ( ! ( F_34 ( V_12 , & V_96 , & V_97 ) ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_99 ] = V_100 ;
if ( V_12 -> V_19 <= 18 ) {
V_3 [ 7 ] = 0x00 ;
return 0 ;
}
V_3 [ V_101 ] = V_96 ;
V_3 [ V_102 ] = V_97 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_99 ] = V_103 ;
if ( V_12 -> V_19 <= 18 ) {
V_3 [ 7 ] = 0x00 ;
return 0 ;
}
V_3 [ V_101 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
return 0 ;
}
static int
F_35 ( struct V_104 * V_105 )
{
struct V_11 * V_12 = F_36 ( V_105 ) ;
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned char * V_3 = V_12 -> V_17 -> V_18 , * V_106 = NULL ;
unsigned char * V_75 = & V_12 -> V_17 -> V_76 [ 0 ] ;
T_4 V_107 ;
unsigned int V_108 = V_12 -> V_19 , V_109 ;
int V_110 , V_87 ;
unsigned short V_111 , V_112 ;
V_87 = 8 ;
V_108 -= 8 ;
V_111 = F_37 ( & V_75 [ 0 ] ) ;
V_112 = F_37 ( & V_75 [ 2 ] ) ;
V_106 = & V_3 [ V_87 ] ;
F_7 ( V_68 L_15
L_16 , V_16 -> V_21 -> V_113 , V_111 , V_112 , V_108 , V_106 ) ;
while ( V_108 ) {
V_107 = F_38 ( & V_106 [ 0 ] ) ;
V_109 = F_39 ( & V_106 [ 8 ] ) ;
F_7 ( V_68 L_17 ,
( unsigned long long ) V_107 , V_109 ) ;
V_110 = V_16 -> V_21 -> V_114 ( V_16 , V_107 , V_109 ) ;
if ( V_110 < 0 ) {
F_7 ( V_20 L_18 ,
V_110 ) ;
return - 1 ;
}
V_106 += 16 ;
V_108 -= 16 ;
}
V_105 -> V_115 = V_116 ;
F_40 ( V_105 , 1 ) ;
return 0 ;
}
static int
F_41 ( struct V_104 * V_105 )
{
struct V_11 * V_12 = F_36 ( V_105 ) ;
struct V_15 * V_16 = F_6 ( V_12 ) ;
T_4 V_107 = V_12 -> V_17 -> V_117 ;
unsigned int V_109 ;
int V_110 ;
V_109 = ( V_12 -> V_19 / F_19 ( V_16 ) -> V_80 ) ;
F_7 ( V_68 L_19 ,
( unsigned long long ) V_107 , V_109 ) ;
V_110 = V_16 -> V_21 -> V_114 ( V_16 , V_107 , V_109 ) ;
if ( V_110 < 0 ) {
F_7 ( V_68 L_20 ) ;
return - 1 ;
}
V_105 -> V_115 = V_116 ;
F_40 ( V_105 , 1 ) ;
return 0 ;
}
int
F_42 ( struct V_104 * V_105 )
{
struct V_11 * V_12 = F_36 ( V_105 ) ;
struct V_15 * V_16 = F_6 ( V_12 ) ;
unsigned short V_118 ;
int V_110 = 0 ;
switch ( V_12 -> V_17 -> V_76 [ 0 ] ) {
case V_119 :
V_110 = F_24 ( V_12 ) ;
break;
case V_120 :
V_110 = F_25 ( V_12 ) ;
break;
case V_121 :
V_110 = F_32 ( V_12 , 0 ) ;
break;
case V_122 :
V_110 = F_32 ( V_12 , 1 ) ;
break;
case V_123 :
switch ( V_12 -> V_17 -> V_76 [ 1 ] & 0x1f ) {
case V_124 :
V_110 = F_26 ( V_12 ) ;
break;
default:
F_7 ( V_20 L_21 ,
V_12 -> V_17 -> V_76 [ 1 ] & 0x1f ) ;
return V_125 ;
}
break;
case V_126 :
V_110 = F_33 ( V_12 ) ;
break;
case V_127 :
if ( ! V_16 -> V_21 -> V_114 ) {
F_7 ( V_20 L_22 ,
V_16 -> V_21 -> V_113 ) ;
return V_125 ;
}
V_110 = F_35 ( V_105 ) ;
break;
case V_128 :
if ( ! V_16 -> V_21 -> V_114 ) {
F_7 ( V_20 L_23
L_24 , V_16 -> V_21 -> V_113 ) ;
return V_125 ;
}
V_110 = F_41 ( V_105 ) ;
break;
case V_129 :
V_118 =
F_37 ( & V_12 -> V_17 -> V_76 [ 8 ] ) ;
switch ( V_118 ) {
case V_130 :
if ( ! V_16 -> V_21 -> V_114 ) {
F_7 ( V_20 L_25
L_26 ,
V_16 -> V_21 -> V_113 ) ;
return V_125 ;
}
V_110 = F_41 ( V_105 ) ;
break;
default:
F_7 ( V_20 L_27
L_28 , V_118 ) ;
break;
}
break;
case V_131 :
case 0x91 :
if ( ! V_16 -> V_21 -> V_132 ) {
F_7 ( V_20
L_29
L_24 , V_16 -> V_21 -> V_113 ) ;
return V_125 ;
}
V_16 -> V_21 -> V_132 ( V_105 ) ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
break;
default:
F_7 ( V_20 L_30 ,
V_12 -> V_17 -> V_76 [ 0 ] , V_16 -> V_21 -> V_113 ) ;
return V_125 ;
}
if ( V_110 < 0 )
return V_110 ;
V_105 -> V_115 = V_116 ;
F_40 ( V_105 , 1 ) ;
return V_142 ;
}
