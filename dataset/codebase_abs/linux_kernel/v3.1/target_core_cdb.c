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
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_18 * V_19 = V_14 -> V_20 -> V_21 ;
unsigned char * V_3 ;
if ( V_12 -> V_22 < 6 ) {
F_5 ( L_1
L_2 , V_12 -> V_22 ) ;
return - V_23 ;
}
V_3 = F_6 ( V_12 ) ;
if ( V_16 == V_19 -> V_24 . V_25 ) {
V_3 [ 0 ] = 0x3f ;
} else {
V_3 [ 0 ] = V_16 -> V_26 -> V_27 ( V_16 ) ;
if ( V_3 [ 0 ] == V_28 )
V_3 [ 1 ] = 0x80 ;
}
V_3 [ 2 ] = V_16 -> V_26 -> V_29 ( V_16 ) ;
if ( V_16 -> V_30 -> V_31 . V_32 == V_33 )
F_1 ( V_14 -> V_20 , V_3 ) ;
if ( V_12 -> V_22 < 8 ) {
V_3 [ 4 ] = 1 ;
goto V_34;
}
V_3 [ 7 ] = 0x32 ;
if ( V_12 -> V_22 < 36 ) {
V_3 [ 4 ] = 3 ;
goto V_34;
}
snprintf ( ( unsigned char * ) & V_3 [ 8 ] , 8 , L_3 ) ;
snprintf ( ( unsigned char * ) & V_3 [ 16 ] , 16 , L_4 ,
& V_16 -> V_30 -> V_35 . V_36 [ 0 ] ) ;
snprintf ( ( unsigned char * ) & V_3 [ 32 ] , 4 , L_4 ,
& V_16 -> V_30 -> V_35 . V_37 [ 0 ] ) ;
V_3 [ 4 ] = 31 ;
V_34:
F_7 ( V_12 ) ;
return 0 ;
}
static int
F_8 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_38 = 0 ;
if ( V_16 -> V_30 -> V_39 &
V_40 ) {
T_2 V_41 ;
V_41 =
strlen ( & V_16 -> V_30 -> V_35 . V_42 [ 0 ] ) ;
V_41 ++ ;
if ( ( ( V_38 + 4 ) + V_41 ) > V_12 -> V_22 ) {
V_38 += V_41 ;
V_3 [ 2 ] = ( ( V_38 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_38 & 0xff ) ;
return 0 ;
}
V_38 += sprintf ( ( unsigned char * ) & V_3 [ 4 ] , L_4 ,
& V_16 -> V_30 -> V_35 . V_42 [ 0 ] ) ;
V_38 ++ ;
V_3 [ 3 ] = V_38 ;
}
return 0 ;
}
static void
F_9 ( struct V_15 * V_16 , unsigned char * V_43 )
{
unsigned char * V_44 = & V_16 -> V_30 -> V_35 . V_42 [ 0 ] ;
unsigned char * V_3 = V_43 ;
int V_45 = 0 , V_46 = 1 ;
while ( * V_44 != '\0' ) {
if ( V_45 >= 13 )
break;
if ( ! isxdigit ( * V_44 ) ) {
V_44 ++ ;
continue;
}
if ( V_46 != 0 ) {
V_3 [ V_45 ++ ] |= F_10 ( * V_44 ++ ) ;
V_46 = 0 ;
} else {
V_3 [ V_45 ] = F_10 ( * V_44 ++ ) << 4 ;
V_46 = 1 ;
}
}
}
static int
F_11 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_1 * V_2 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_47 * V_48 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned char * V_49 = & V_16 -> V_30 -> V_35 . V_36 [ 0 ] ;
T_2 V_50 ;
T_2 V_41 , V_51 = 0 ;
T_1 V_38 = 0 , V_52 ;
V_51 = 4 ;
if ( ! ( V_16 -> V_30 -> V_39 & V_40 ) )
goto V_53;
if ( V_51 + 20 > V_12 -> V_22 )
goto V_53;
V_3 [ V_51 ++ ] = 0x1 ;
V_3 [ V_51 ] = 0x00 ;
V_3 [ V_51 ++ ] |= 0x3 ;
V_51 ++ ;
V_3 [ V_51 ++ ] = 0x10 ;
V_3 [ V_51 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_51 ++ ] = 0x01 ;
V_3 [ V_51 ++ ] = 0x40 ;
V_3 [ V_51 ] = ( 0x5 << 4 ) ;
F_9 ( V_16 , & V_3 [ V_51 ] ) ;
V_38 = 20 ;
V_51 = ( V_38 + 4 ) ;
V_53:
V_52 = 8 ;
V_50 = 4 ;
V_50 += 8 ;
V_50 += strlen ( V_49 ) ;
V_50 ++ ;
if ( V_16 -> V_30 -> V_39 &
V_40 ) {
V_41 =
strlen ( & V_16 -> V_30 -> V_35 . V_42 [ 0 ] ) ;
V_41 ++ ;
if ( ( V_38 + ( V_52 + 4 ) +
( V_50 + V_41 ) ) >
V_12 -> V_22 ) {
V_38 += ( V_50 + V_41 ) ;
goto V_54;
}
V_52 += sprintf ( ( unsigned char * ) & V_3 [ V_51 + 12 ] ,
L_5 , V_49 ,
& V_16 -> V_30 -> V_35 . V_42 [ 0 ] ) ;
}
V_3 [ V_51 ] = 0x2 ;
V_3 [ V_51 + 1 ] = 0x1 ;
V_3 [ V_51 + 2 ] = 0x0 ;
memcpy ( ( unsigned char * ) & V_3 [ V_51 + 4 ] , L_3 , 8 ) ;
V_52 ++ ;
V_3 [ V_51 + 3 ] = V_52 ;
V_38 += ( V_52 + 4 ) ;
V_51 += ( V_52 + 4 ) ;
V_54:
V_2 = V_14 -> V_20 ;
if ( V_2 ) {
struct V_55 * V_56 ;
T_2 V_57 , V_58 ;
T_1 V_59 = 0 ;
T_1 V_60 = 0 ;
T_1 V_61 ;
V_19 = V_2 -> V_21 ;
if ( ( ( V_38 + 4 ) + 8 ) > V_12 -> V_22 ) {
V_38 += 8 ;
goto V_62;
}
V_3 [ V_51 ] =
( V_19 -> V_63 -> V_64 ( V_19 ) << 4 ) ;
V_3 [ V_51 ++ ] |= 0x1 ;
V_3 [ V_51 ] = 0x80 ;
V_3 [ V_51 ] |= 0x10 ;
V_3 [ V_51 ++ ] |= 0x4 ;
V_51 ++ ;
V_3 [ V_51 ++ ] = 4 ;
V_51 += 2 ;
V_3 [ V_51 ++ ] = ( ( V_2 -> V_65 >> 8 ) & 0xff ) ;
V_3 [ V_51 ++ ] = ( V_2 -> V_65 & 0xff ) ;
V_38 += 8 ;
V_62:
if ( V_16 -> V_30 -> V_31 . V_32 !=
V_33 )
goto V_66;
if ( ( ( V_38 + 4 ) + 8 ) > V_12 -> V_22 ) {
V_38 += 8 ;
goto V_67;
}
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
goto V_67;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( ! V_5 ) {
F_3 ( & V_7 -> V_9 ) ;
goto V_67;
}
V_60 = V_5 -> V_60 ;
F_3 ( & V_7 -> V_9 ) ;
V_3 [ V_51 ] =
( V_19 -> V_63 -> V_64 ( V_19 ) << 4 ) ;
V_3 [ V_51 ++ ] |= 0x1 ;
V_3 [ V_51 ] = 0x80 ;
V_3 [ V_51 ] |= 0x10 ;
V_3 [ V_51 ++ ] |= 0x5 ;
V_51 ++ ;
V_3 [ V_51 ++ ] = 4 ;
V_51 += 2 ;
V_3 [ V_51 ++ ] = ( ( V_60 >> 8 ) & 0xff ) ;
V_3 [ V_51 ++ ] = ( V_60 & 0xff ) ;
V_38 += 8 ;
V_67:
if ( ( ( V_38 + 4 ) + 8 ) > V_12 -> V_22 ) {
V_38 += 8 ;
goto V_66;
}
V_48 = V_16 -> V_68 ;
if ( ! V_48 )
goto V_66;
F_2 ( & V_48 -> V_69 ) ;
V_56 = V_48 -> V_56 ;
if ( ! V_56 ) {
F_3 ( & V_48 -> V_69 ) ;
goto V_66;
}
V_59 = V_56 -> V_59 ;
F_3 ( & V_48 -> V_69 ) ;
V_3 [ V_51 ++ ] |= 0x1 ;
V_3 [ V_51 ++ ] |= 0x6 ;
V_51 ++ ;
V_3 [ V_51 ++ ] = 4 ;
V_51 += 2 ;
V_3 [ V_51 ++ ] = ( ( V_59 >> 8 ) & 0xff ) ;
V_3 [ V_51 ++ ] = ( V_59 & 0xff ) ;
V_38 += 8 ;
V_66:
V_58 = strlen ( V_19 -> V_63 -> V_70 ( V_19 ) ) ;
V_58 += 10 ;
V_57 = ( ( - V_58 ) & 3 ) ;
if ( V_57 != 0 )
V_58 += V_57 ;
V_58 += 4 ;
if ( ( ( V_38 + 4 ) + V_58 ) > V_12 -> V_22 ) {
V_38 += V_58 ;
goto V_71;
}
V_3 [ V_51 ] =
( V_19 -> V_63 -> V_64 ( V_19 ) << 4 ) ;
V_3 [ V_51 ++ ] |= 0x3 ;
V_3 [ V_51 ] = 0x80 ;
V_3 [ V_51 ] |= 0x10 ;
V_3 [ V_51 ++ ] |= 0x8 ;
V_51 += 2 ;
V_61 = V_19 -> V_63 -> V_72 ( V_19 ) ;
V_58 = sprintf ( & V_3 [ V_51 ] , L_6 ,
V_19 -> V_63 -> V_70 ( V_19 ) , V_61 ) ;
V_58 += 1 ;
if ( V_57 )
V_58 += V_57 ;
V_3 [ V_51 - 1 ] = V_58 ;
V_51 += V_58 ;
V_38 += ( V_58 + 4 ) ;
}
V_71:
V_3 [ 2 ] = ( ( V_38 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_38 & 0xff ) ;
return 0 ;
}
static int
F_12 ( struct V_11 * V_12 , unsigned char * V_3 )
{
if ( V_12 -> V_22 < 60 )
return 0 ;
V_3 [ 2 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( V_12 -> V_17 -> V_30 -> V_73 . V_74 > 0 )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static int
F_13 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_75 = 0 ;
if ( V_16 -> V_30 -> V_73 . V_76 || V_16 -> V_30 -> V_73 . V_77 )
V_75 = 1 ;
if ( V_12 -> V_22 < ( 0x10 + 4 ) ) {
F_14 ( L_7
L_8 ,
V_12 -> V_22 ) ;
return - V_23 ;
}
if ( V_75 && V_12 -> V_22 < ( 0x3c + 4 ) ) {
F_14 ( L_7
L_9 ,
V_12 -> V_22 ) ;
V_75 = 0 ;
}
V_3 [ 0 ] = V_16 -> V_26 -> V_27 ( V_16 ) ;
V_3 [ 3 ] = V_75 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
F_15 ( 1 , & V_3 [ 6 ] ) ;
F_16 ( V_16 -> V_30 -> V_73 . V_78 , & V_3 [ 8 ] ) ;
F_16 ( V_16 -> V_30 -> V_73 . V_79 , & V_3 [ 12 ] ) ;
if ( ! V_75 || V_12 -> V_22 < ( 0x3c + 4 ) )
return 0 ;
F_16 ( V_16 -> V_30 -> V_73 . V_80 , & V_3 [ 20 ] ) ;
F_16 ( V_16 -> V_30 -> V_73 . V_81 ,
& V_3 [ 24 ] ) ;
F_16 ( V_16 -> V_30 -> V_73 . V_82 , & V_3 [ 28 ] ) ;
F_16 ( V_16 -> V_30 -> V_73 . V_83 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_30 -> V_73 . V_83 != 0 )
V_3 [ 32 ] |= 0x80 ;
return 0 ;
}
static int
F_17 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_26 -> V_27 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
if ( V_12 -> V_22 >= 5 &&
V_16 -> V_30 -> V_73 . V_84 )
V_3 [ 5 ] = 1 ;
return 0 ;
}
static int
F_18 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_26 -> V_27 ( V_16 ) ;
F_15 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_30 -> V_73 . V_76 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_30 -> V_73 . V_77 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static int
F_19 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_44 ;
if ( V_12 -> V_22 < 8 )
return 0 ;
if ( V_12 -> V_17 -> V_30 -> V_39 &
V_40 ) {
V_3 [ 3 ] = F_20 ( V_85 ) ;
for ( V_44 = 0 ; V_44 < F_21 ( int , F_20 ( V_85 ) ,
V_12 -> V_22 - 4 ) ; ++ V_44 )
V_3 [ V_44 + 4 ] = V_85 [ V_44 ] . V_86 ;
}
return 0 ;
}
static int
F_22 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned char * V_87 = V_12 -> V_88 ;
int V_44 , V_89 ;
if ( ! ( V_87 [ 1 ] & 0x1 ) )
return F_4 ( V_12 ) ;
if ( V_12 -> V_22 < 4 ) {
F_5 ( L_1
L_10 , V_12 -> V_22 ) ;
return - V_23 ;
}
V_3 = F_6 ( V_12 ) ;
V_3 [ 0 ] = V_16 -> V_26 -> V_27 ( V_16 ) ;
for ( V_44 = 0 ; V_44 < F_20 ( V_85 ) ; ++ V_44 )
if ( V_87 [ 2 ] == V_85 [ V_44 ] . V_86 ) {
V_3 [ 1 ] = V_87 [ 2 ] ;
V_89 = V_85 [ V_44 ] . F_23 ( V_12 , V_3 ) ;
F_7 ( V_12 ) ;
return V_89 ;
}
F_7 ( V_12 ) ;
F_5 ( L_11 , V_87 [ 2 ] ) ;
return - V_23 ;
}
static int
F_24 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_90 = V_16 -> V_26 -> V_91 ( V_16 ) ;
T_2 V_92 ;
if ( V_90 >= 0x00000000ffffffff )
V_92 = 0xffffffff ;
else
V_92 = ( T_2 ) V_90 ;
V_3 = F_6 ( V_12 ) ;
V_3 [ 0 ] = ( V_92 >> 24 ) & 0xff ;
V_3 [ 1 ] = ( V_92 >> 16 ) & 0xff ;
V_3 [ 2 ] = ( V_92 >> 8 ) & 0xff ;
V_3 [ 3 ] = V_92 & 0xff ;
V_3 [ 4 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_16 -> V_30 -> V_73 . V_93 & 0xff ;
if ( V_16 -> V_30 -> V_73 . V_76 || V_16 -> V_30 -> V_73 . V_77 )
F_16 ( 0xFFFFFFFF , & V_3 [ 0 ] ) ;
F_7 ( V_12 ) ;
return 0 ;
}
static int
F_25 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_92 = V_16 -> V_26 -> V_91 ( V_16 ) ;
V_3 = F_6 ( V_12 ) ;
V_3 [ 0 ] = ( V_92 >> 56 ) & 0xff ;
V_3 [ 1 ] = ( V_92 >> 48 ) & 0xff ;
V_3 [ 2 ] = ( V_92 >> 40 ) & 0xff ;
V_3 [ 3 ] = ( V_92 >> 32 ) & 0xff ;
V_3 [ 4 ] = ( V_92 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_92 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_92 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_92 & 0xff ;
V_3 [ 8 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 24 ) & 0xff ;
V_3 [ 9 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 16 ) & 0xff ;
V_3 [ 10 ] = ( V_16 -> V_30 -> V_73 . V_93 >> 8 ) & 0xff ;
V_3 [ 11 ] = V_16 -> V_30 -> V_73 . V_93 & 0xff ;
if ( V_16 -> V_30 -> V_73 . V_76 || V_16 -> V_30 -> V_73 . V_77 )
V_3 [ 14 ] = 0x80 ;
F_7 ( V_12 ) ;
return 0 ;
}
static int
F_26 ( unsigned char * V_44 )
{
V_44 [ 0 ] = 0x01 ;
V_44 [ 1 ] = 0x0a ;
return 12 ;
}
static int
F_27 ( struct V_15 * V_16 , unsigned char * V_44 )
{
V_44 [ 0 ] = 0x0a ;
V_44 [ 1 ] = 0x0a ;
V_44 [ 2 ] = 2 ;
V_44 [ 3 ] = ( V_16 -> V_30 -> V_73 . V_94 == 1 ) ? 0x00 : 0x10 ;
V_44 [ 4 ] = ( V_16 -> V_30 -> V_73 . V_95 == 2 ) ? 0x30 :
( V_16 -> V_30 -> V_73 . V_95 == 1 ) ? 0x20 : 0x00 ;
V_44 [ 5 ] = ( V_16 -> V_30 -> V_73 . V_96 ) ? 0x40 : 0x00 ;
V_44 [ 8 ] = 0xff ;
V_44 [ 9 ] = 0xff ;
V_44 [ 11 ] = 30 ;
return 12 ;
}
static int
F_28 ( struct V_15 * V_16 , unsigned char * V_44 )
{
V_44 [ 0 ] = 0x08 ;
V_44 [ 1 ] = 0x12 ;
if ( V_16 -> V_30 -> V_73 . V_74 > 0 )
V_44 [ 2 ] = 0x04 ;
V_44 [ 12 ] = 0x20 ;
return 20 ;
}
static void
F_29 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_97 :
case V_28 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void
F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_97 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int
F_31 ( struct V_11 * V_12 , int V_98 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_87 = V_12 -> V_88 ;
unsigned char * V_99 ;
int type = V_16 -> V_26 -> V_27 ( V_16 ) ;
int V_100 = ( V_98 ) ? 8 : 4 ;
int V_101 = 0 ;
unsigned char V_3 [ V_102 ] ;
memset ( V_3 , 0 , V_102 ) ;
switch ( V_87 [ 2 ] & 0x3f ) {
case 0x01 :
V_101 = F_26 ( & V_3 [ V_100 ] ) ;
break;
case 0x08 :
V_101 = F_28 ( V_16 , & V_3 [ V_100 ] ) ;
break;
case 0x0a :
V_101 = F_27 ( V_16 , & V_3 [ V_100 ] ) ;
break;
case 0x3f :
V_101 = F_26 ( & V_3 [ V_100 ] ) ;
V_101 += F_28 ( V_16 , & V_3 [ V_100 + V_101 ] ) ;
V_101 += F_27 ( V_16 , & V_3 [ V_100 + V_101 ] ) ;
break;
default:
F_5 ( L_12 ,
V_87 [ 2 ] & 0x3f , V_87 [ 3 ] ) ;
return V_103 ;
}
V_100 += V_101 ;
if ( V_98 ) {
V_100 -= 2 ;
V_3 [ 0 ] = ( V_100 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_100 & 0xff ;
if ( ( V_12 -> V_13 -> V_104 & V_105 ) ||
( V_12 -> V_106 &&
( V_12 -> V_106 -> V_107 & V_105 ) ) )
F_29 ( & V_3 [ 3 ] , type ) ;
if ( ( V_16 -> V_30 -> V_73 . V_74 > 0 ) &&
( V_16 -> V_30 -> V_73 . V_108 > 0 ) )
F_30 ( & V_3 [ 3 ] , type ) ;
if ( ( V_100 + 2 ) > V_12 -> V_22 )
V_100 = V_12 -> V_22 ;
} else {
V_100 -= 1 ;
V_3 [ 0 ] = V_100 & 0xff ;
if ( ( V_12 -> V_13 -> V_104 & V_105 ) ||
( V_12 -> V_106 &&
( V_12 -> V_106 -> V_107 & V_105 ) ) )
F_29 ( & V_3 [ 2 ] , type ) ;
if ( ( V_16 -> V_30 -> V_73 . V_74 > 0 ) &&
( V_16 -> V_30 -> V_73 . V_108 > 0 ) )
F_30 ( & V_3 [ 2 ] , type ) ;
if ( ( V_100 + 1 ) > V_12 -> V_22 )
V_100 = V_12 -> V_22 ;
}
V_99 = F_6 ( V_12 ) ;
memcpy ( V_99 , V_3 , V_100 ) ;
F_7 ( V_12 ) ;
return 0 ;
}
static int
F_32 ( struct V_11 * V_12 )
{
unsigned char * V_87 = V_12 -> V_88 ;
unsigned char * V_3 ;
T_3 V_109 = 0 , V_110 = 0 ;
int V_111 = 0 ;
if ( V_87 [ 1 ] & 0x01 ) {
F_5 ( L_13
L_14 ) ;
return V_112 ;
}
V_3 = F_6 ( V_12 ) ;
if ( ! F_33 ( V_12 , & V_109 , & V_110 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_113 ] = V_114 ;
if ( V_12 -> V_22 <= 18 ) {
V_3 [ 7 ] = 0x00 ;
V_111 = - V_23 ;
goto V_115;
}
V_3 [ V_116 ] = V_109 ;
V_3 [ V_117 ] = V_110 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_113 ] = V_118 ;
if ( V_12 -> V_22 <= 18 ) {
V_3 [ 7 ] = 0x00 ;
V_111 = - V_23 ;
goto V_115;
}
V_3 [ V_116 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
V_115:
F_7 ( V_12 ) ;
return 0 ;
}
static int
F_34 ( struct V_119 * V_120 )
{
struct V_11 * V_12 = V_120 -> V_121 ;
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 , * V_122 = NULL ;
unsigned char * V_87 = & V_12 -> V_88 [ 0 ] ;
T_4 V_123 ;
unsigned int V_124 = V_12 -> V_22 , V_125 ;
int V_89 = 0 , V_100 ;
unsigned short V_126 , V_127 ;
V_100 = 8 ;
V_124 -= 8 ;
V_126 = F_35 ( & V_87 [ 0 ] ) ;
V_127 = F_35 ( & V_87 [ 2 ] ) ;
V_3 = F_6 ( V_12 ) ;
V_122 = & V_3 [ V_100 ] ;
F_14 ( L_15
L_16 , V_16 -> V_26 -> V_128 , V_126 , V_127 , V_124 , V_122 ) ;
while ( V_124 ) {
V_123 = F_36 ( & V_122 [ 0 ] ) ;
V_125 = F_37 ( & V_122 [ 8 ] ) ;
F_14 ( L_17 ,
( unsigned long long ) V_123 , V_125 ) ;
V_89 = V_16 -> V_26 -> V_129 ( V_16 , V_123 , V_125 ) ;
if ( V_89 < 0 ) {
F_5 ( L_18 ,
V_89 ) ;
goto V_111;
}
V_122 += 16 ;
V_124 -= 16 ;
}
V_111:
F_7 ( V_12 ) ;
return V_89 ;
}
static int
F_38 ( struct V_119 * V_120 , T_2 V_130 )
{
struct V_11 * V_12 = V_120 -> V_121 ;
struct V_15 * V_16 = V_12 -> V_17 ;
T_4 V_125 ;
T_4 V_123 = V_12 -> V_131 ;
int V_89 ;
if ( V_130 != 0 )
V_125 = V_130 ;
else
V_125 = ( V_16 -> V_26 -> V_91 ( V_16 ) - V_123 ) ;
F_14 ( L_19 ,
( unsigned long long ) V_123 , ( unsigned long long ) V_125 ) ;
V_89 = V_16 -> V_26 -> V_129 ( V_16 , V_123 , V_125 ) ;
if ( V_89 < 0 ) {
F_14 ( L_20 ) ;
return V_89 ;
}
return 0 ;
}
int
F_39 ( struct V_119 * V_120 )
{
struct V_11 * V_12 = V_120 -> V_121 ;
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned short V_132 ;
int V_89 = 0 ;
switch ( V_12 -> V_88 [ 0 ] ) {
case V_133 :
V_89 = F_22 ( V_12 ) ;
break;
case V_134 :
V_89 = F_24 ( V_12 ) ;
break;
case V_135 :
V_89 = F_31 ( V_12 , 0 ) ;
break;
case V_136 :
V_89 = F_31 ( V_12 , 1 ) ;
break;
case V_137 :
switch ( V_12 -> V_88 [ 1 ] & 0x1f ) {
case V_138 :
V_89 = F_25 ( V_12 ) ;
break;
default:
F_5 ( L_21 ,
V_12 -> V_88 [ 1 ] & 0x1f ) ;
return V_139 ;
}
break;
case V_140 :
V_89 = F_32 ( V_12 ) ;
break;
case V_141 :
if ( ! V_16 -> V_26 -> V_129 ) {
F_5 ( L_22 ,
V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
V_89 = F_34 ( V_120 ) ;
break;
case V_142 :
if ( ! V_16 -> V_26 -> V_129 ) {
F_5 ( L_23
L_24 , V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
V_89 = F_38 ( V_120 ,
F_35 ( & V_12 -> V_88 [ 7 ] ) ) ;
break;
case V_143 :
if ( ! V_16 -> V_26 -> V_129 ) {
F_5 ( L_25
L_24 , V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
V_89 = F_38 ( V_120 ,
F_37 ( & V_12 -> V_88 [ 10 ] ) ) ;
break;
case V_144 :
V_132 =
F_35 ( & V_12 -> V_88 [ 8 ] ) ;
switch ( V_132 ) {
case V_145 :
if ( ! V_16 -> V_26 -> V_129 ) {
F_5 ( L_26
L_27 ,
V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
V_89 = F_38 ( V_120 ,
F_37 ( & V_12 -> V_88 [ 28 ] ) ) ;
break;
default:
F_5 ( L_28
L_29 , V_132 ) ;
break;
}
break;
case V_146 :
case 0x91 :
if ( ! V_16 -> V_26 -> V_147 ) {
F_5 ( L_30
L_24 , V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
V_16 -> V_26 -> V_147 ( V_120 ) ;
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
break;
default:
F_5 ( L_31 ,
V_12 -> V_88 [ 0 ] , V_16 -> V_26 -> V_128 ) ;
return V_139 ;
}
if ( V_89 < 0 )
return V_89 ;
if ( ! ( V_12 -> V_157 & V_158 ) ) {
V_120 -> V_159 = V_160 ;
F_40 ( V_120 , 1 ) ;
}
return V_161 ;
}
