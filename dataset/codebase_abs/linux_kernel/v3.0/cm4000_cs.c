static inline void F_1 ( unsigned char V_1 , unsigned short V_2 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
F_3 ( V_1 , V_2 ) ;
}
static inline unsigned char F_4 ( unsigned short V_2 )
{
unsigned char V_1 ;
V_1 = F_5 ( V_2 ) ;
F_2 ( L_2 , V_1 , V_2 ) ;
return V_1 ;
}
static inline unsigned char F_6 ( unsigned char V_3 )
{
return F_7 ( ~ V_3 ) ;
}
static void F_8 ( unsigned char * V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
V_4 [ V_6 ] = F_6 ( V_4 [ V_6 ] ) ;
}
static unsigned int F_9 ( unsigned char V_7 )
{
unsigned int V_8 , V_9 , V_10 , V_11 ;
V_10 = 372 ;
V_11 = 1 ;
switch ( ( V_7 >> 4 ) & 0x0F ) {
case 0x00 :
V_8 = 372 ;
break;
case 0x01 :
V_8 = 372 ;
break;
case 0x02 :
V_8 = 558 ;
break;
case 0x03 :
V_8 = 744 ;
break;
case 0x04 :
V_8 = 1116 ;
break;
case 0x05 :
V_8 = 1488 ;
break;
case 0x06 :
V_8 = 1860 ;
break;
case 0x07 :
V_8 = V_10 ;
break;
case 0x08 :
V_8 = V_10 ;
break;
case 0x09 :
V_8 = 512 ;
break;
case 0x0A :
V_8 = 768 ;
break;
case 0x0B :
V_8 = 1024 ;
break;
case 0x0C :
V_8 = 1536 ;
break;
case 0x0D :
V_8 = 2048 ;
break;
default:
V_8 = V_10 ;
break;
}
switch ( V_7 & 0x0F ) {
case 0x00 :
V_9 = V_11 ;
break;
case 0x01 :
V_9 = 1 ;
break;
case 0x02 :
V_9 = 2 ;
break;
case 0x03 :
V_9 = 4 ;
break;
case 0x04 :
V_9 = 8 ;
break;
case 0x05 :
V_9 = 16 ;
break;
case 0x06 :
V_9 = 32 ;
break;
case 0x07 :
V_9 = V_11 ;
break;
case 0x08 :
V_9 = 12 ;
break;
case 0x09 :
V_9 = 20 ;
break;
default:
V_9 = V_11 ;
break;
}
return ( V_8 / V_9 ) ;
}
static unsigned short F_10 ( unsigned int V_12 ,
unsigned short * V_13 )
{
unsigned short V_14 ;
V_14 = * V_13 = 0 ;
do {
* V_13 = V_14 ;
V_14 = F_5 ( F_11 ( V_12 ) ) |
( F_5 ( F_12 ( V_12 ) ) & 4 ? 0x100 : 0 ) ;
} while ( V_14 != * V_13 );
return * V_13 ;
}
static int F_13 ( struct V_15 * V_16 )
{
unsigned char V_17 , V_18 ;
unsigned char V_3 , V_19 ;
int V_20 , V_21 ;
F_14 ( 3 , V_16 , L_3 , V_16 -> V_22 ) ;
if ( V_16 -> V_22 < 3 ) {
F_14 ( 5 , V_16 , L_4 ) ;
return 0 ;
}
if ( V_16 -> V_23 [ 0 ] == 0x3f )
F_15 ( V_24 , & V_16 -> V_25 ) ;
else
F_16 ( V_24 , & V_16 -> V_25 ) ;
V_20 = 1 ;
V_19 = 1 ;
V_3 = V_16 -> V_23 [ 1 ] ;
V_16 -> V_26 = 0 ;
V_17 = V_18 = V_21 = 0 ;
V_16 -> V_27 = 0x11 ;
do {
if ( V_19 == 1 && ( V_3 & 0x10 ) ) {
V_16 -> V_27 = V_16 -> V_23 [ 2 ] ;
F_14 ( 5 , V_16 , L_5 , V_16 -> V_27 ) ;
V_19 ++ ;
} else if ( ( V_19 == 2 ) && ( V_3 & 0x10 ) ) {
V_16 -> V_27 = 0x11 ;
V_19 ++ ;
}
F_14 ( 5 , V_16 , L_6 , V_3 & 0xf0 ) ;
V_20 += ( ( V_3 & 0x10 ) >> 4 )
+ ( ( V_3 & 0x20 ) >> 5 )
+ ( ( V_3 & 0x40 ) >> 6 )
+ ( ( V_3 & 0x80 ) >> 7 ) ;
if ( V_3 & 0x80 ) {
V_3 = V_16 -> V_23 [ V_20 ] ;
if ( ( V_3 & 0x0f ) ) {
V_17 = 1 ;
F_14 ( 5 , V_16 , L_7 ) ;
} else {
V_18 = 1 ;
F_14 ( 5 , V_16 , L_8 ) ;
}
} else
V_21 = 1 ;
} while ( ! V_21 );
F_14 ( 5 , V_16 , L_9 ,
V_20 , V_16 -> V_23 [ 1 ] & 15 , V_17 ) ;
if ( V_20 + 1 + ( V_16 -> V_23 [ 1 ] & 0x0f ) + V_17 != V_16 -> V_22 ) {
F_14 ( 5 , V_16 , L_10 ) ;
return 0 ;
}
if ( V_18 )
F_15 ( V_28 , & V_16 -> V_25 ) ;
if ( V_17 ) {
V_16 -> V_29 = 0 ;
#ifdef F_17
for ( V_6 = 1 ; V_6 < V_16 -> V_22 ; V_6 ++ )
V_16 -> V_29 ^= V_16 -> V_23 [ V_6 ] ;
if ( V_16 -> V_29 ) {
F_15 ( V_30 , & V_16 -> V_25 ) ;
F_14 ( 5 , V_16 , L_11 ) ;
goto V_31;
}
#endif
if ( V_18 == 0 )
V_16 -> V_26 = 1 ;
F_15 ( V_32 , & V_16 -> V_25 ) ;
}
return 1 ;
}
static void F_18 ( struct V_15 * V_16 )
{
int V_6 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
T_1 V_36 = 0x02 ;
F_14 ( 3 , V_16 , L_12 ) ;
V_16 -> V_37 = V_16 -> V_37 | ( ( ( V_16 -> V_38 - 1 ) & 0x0100 ) >> 8 ) ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
F_14 ( 5 , V_16 , L_13 , V_16 -> V_37 ) ;
F_1 ( ( unsigned char ) ( ( V_16 -> V_38 - 1 ) & 0xFF ) , F_20 ( V_12 ) ) ;
F_14 ( 5 , V_16 , L_14 , V_16 -> V_38 ,
( ( V_16 -> V_38 - 1 ) & 0xFF ) ) ;
for ( V_6 = 0 ; V_6 < F_21 ( V_39 ) ; V_6 ++ ) {
if ( ! memcmp ( V_16 -> V_23 , V_39 [ V_6 ] . V_23 ,
V_39 [ V_6 ] . V_22 ) )
V_36 = V_39 [ V_6 ] . V_36 ;
}
F_1 ( V_36 , F_22 ( V_12 ) ) ;
F_14 ( 3 , V_16 , L_15 ) ;
}
static int F_23 ( struct V_15 * V_16 , struct V_40 * V_40 )
{
unsigned long V_14 , V_6 ;
unsigned short V_41 ;
unsigned char V_42 [ 4 ] ;
T_2 V_43 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
V_43 = 0 ;
F_14 ( 3 , V_16 , L_16 ) ;
F_14 ( 5 , V_16 , L_17
L_18
L_19 , ( unsigned int ) V_40 -> V_44 ,
( unsigned int ) V_40 -> V_25 , V_40 -> V_45 , V_40 -> V_46 ,
V_40 -> V_47 ) ;
V_16 -> V_48 [ 0 ] = 0xff ;
V_16 -> V_48 [ 1 ] = 0x00 ;
V_14 = V_40 -> V_44 ;
while ( ( V_14 = ( V_14 >> 1 ) ) > 0 )
V_16 -> V_48 [ 1 ] ++ ;
V_16 -> V_26 = V_16 -> V_48 [ 1 ] ;
V_16 -> V_48 [ 1 ] = ( 0x01 << 4 ) | ( V_16 -> V_48 [ 1 ] ) ;
F_14 ( 5 , V_16 , L_20 , V_16 -> V_27 ) ;
V_16 -> V_48 [ 2 ] = V_49 [ V_16 -> V_27 & 0x0F ] [ ( V_16 -> V_27 >> 4 ) & 0x0F ] ;
V_16 -> V_48 [ 3 ] = V_16 -> V_48 [ 0 ] ^ V_16 -> V_48 [ 1 ] ^ V_16 -> V_48 [ 2 ] ;
F_14 ( 5 , V_16 , L_21 ,
V_16 -> V_48 [ 0 ] , V_16 -> V_48 [ 1 ] , V_16 -> V_48 [ 2 ] , V_16 -> V_48 [ 3 ] ) ;
if ( F_24 ( V_24 , & V_16 -> V_25 ) )
F_8 ( V_16 -> V_48 , 4 ) ;
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
F_14 ( 5 , V_16 , L_22 ) ;
V_16 -> V_37 = 0x20
| ( F_24 ( V_24 , & V_16 -> V_25 ) ? 0x02 : 0x00 )
| ( ( V_16 -> V_38 >> 8 ) & 0x01 ) ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
F_14 ( 5 , V_16 , L_23 ,
V_16 -> V_37 ) ;
F_14 ( 5 , V_16 , L_24 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
F_1 ( V_6 , F_25 ( V_12 ) ) ;
F_1 ( V_16 -> V_48 [ V_6 ] , F_26 ( V_12 ) ) ;
#ifdef F_27
F_2 ( L_25 , V_16 -> V_48 [ V_6 ] ) ;
}
F_2 ( L_26 ) ;
#else
}
int F_28 ( unsigned int V_12 , struct V_15 * V_16 )
{
if ( F_5 ( F_12 ( V_12 ) ) & 8 ) {
F_16 ( V_50 , & V_16 -> V_25 ) ;
F_15 ( V_51 , & V_16 -> V_25 ) ;
return 0 ;
}
F_1 ( V_16 -> V_37 | 0x40 , F_19 ( V_12 ) ) ;
if ( ( F_5 ( F_12 ( V_12 ) ) & 8 ) == 0 ) {
F_16 ( V_50 , & V_16 -> V_25 ) ;
F_15 ( V_51 , & V_16 -> V_25 ) ;
return 0 ;
}
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
return 1 ;
}
static void F_29 ( struct V_15 * V_16 )
{
F_14 ( 3 , V_16 , L_27 ) ;
F_30 ( V_16 -> V_52 ,
F_31 ( V_53 ,
( void * ) & V_16 -> V_25 ) ) ;
F_14 ( 5 , V_16 , L_28 ) ;
while ( F_24 ( V_53 , ( void * ) & V_16 -> V_25 ) )
F_32 ( 25 ) ;
F_14 ( 5 , V_16 , L_29 ) ;
F_33 ( & V_16 -> V_54 ) ;
#ifdef F_27
V_16 -> V_55 = 0 ;
#endif
F_14 ( 3 , V_16 , L_30 ) ;
}
static void F_34 ( unsigned long V_56 )
{
struct V_15 * V_16 = (struct V_15 * ) V_56 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
unsigned short V_13 ;
struct V_40 V_40 ;
int V_6 , V_57 ;
F_14 ( 7 , V_16 , L_31 ) ;
if ( F_31 ( V_53 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_32 ) ;
V_16 -> V_58 =
V_16 -> V_59 =
V_16 -> V_29 = V_16 -> V_60 = V_16 -> V_61 = 0 ;
V_16 -> V_62 = V_63 ;
F_16 ( V_53 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_52 ) ;
F_14 ( 2 , V_16 , L_33 ) ;
return;
}
if ( F_31 ( V_64 , ( void * ) & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_34 ) ;
goto V_65;
}
V_16 -> V_66 = F_4 ( F_12 ( V_12 ) ) ;
F_14 ( 7 , V_16 , L_35 , V_16 -> V_66 ) ;
F_14 ( 7 , V_16 , L_36 ,
V_16 -> V_66 & 1 ? L_37 : L_38 ) ;
F_14 ( 7 , V_16 , L_39 ,
V_16 -> V_66 == 0xff ? L_38 : L_37 ) ;
if ( ( V_16 -> V_66 & 1 ) == 0
|| V_16 -> V_66 == 0xff ) {
V_16 -> V_58 =
V_16 -> V_59 =
V_16 -> V_29 = V_16 -> V_60 = V_16 -> V_61 = 0 ;
V_16 -> V_62 = V_63 ;
V_16 -> V_25 &= 0x000000ff ;
if ( V_16 -> V_66 == 0xff ) {
F_14 ( 4 , V_16 , L_40 ) ;
F_15 ( V_51 , & V_16 -> V_25 ) ;
} else if ( F_24 ( V_51 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_41
L_42 ) ;
F_16 ( V_51 , & V_16 -> V_25 ) ;
}
goto V_67;
} else if ( ( V_16 -> V_66 & 1 ) && F_24 ( V_51 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_43 ) ;
F_16 ( V_51 , & V_16 -> V_25 ) ;
}
if ( F_24 ( V_50 , & V_16 -> V_25 ) == 1 ) {
F_14 ( 7 , V_16 , L_44 ) ;
goto V_67;
}
switch ( V_16 -> V_62 ) {
unsigned char V_66 ;
case V_68 :
F_14 ( 4 , V_16 , L_45 ) ;
V_66 = F_5 ( F_12 ( V_12 ) ) ;
if ( V_66 & 0x02 ) {
V_16 -> V_69 = V_70 ;
} else {
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
V_16 -> V_58 =
V_16 -> V_59 =
V_16 -> V_29 =
V_16 -> V_60 = V_16 -> V_61 = 0 ;
V_16 -> V_62 = V_63 ;
V_16 -> V_69 = V_71 ;
}
break;
case V_63 :
F_14 ( 4 , V_16 , L_46 ) ;
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
F_14 ( 4 , V_16 , L_47 ) ;
V_16 -> V_38 = 0x173 ;
F_1 ( 0x02 , F_22 ( V_12 ) ) ;
F_1 ( 0x73 , F_20 ( V_12 ) ) ;
F_1 ( 0x21 , F_19 ( V_12 ) ) ;
F_1 ( V_16 -> V_66 & 2 ? 0x46 : 0x44 , F_12 ( V_12 ) ) ;
V_16 -> V_69 = V_72 ;
V_16 -> V_62 = V_73 ;
break;
case V_73 :
F_14 ( 4 , V_16 , L_48 ) ;
F_10 ( V_12 , & V_16 -> V_22 ) ;
V_16 -> V_69 = V_70 ;
V_16 -> V_62 = V_74 ;
break;
case V_74 :
F_14 ( 4 , V_16 , L_49 ) ;
#define F_36 100
if ( V_16 -> V_22 == F_10 ( V_12 , & V_13 ) ) {
if ( V_16 -> V_60 ++ >= F_36 ) {
V_16 -> V_69 = V_70 ;
V_16 -> V_62 = V_75 ;
}
} else {
V_16 -> V_22 = V_13 ;
V_16 -> V_60 = 0 ;
}
F_14 ( 4 , V_16 , L_50 , V_16 -> V_22 ) ;
break;
case V_75 :
F_14 ( 4 , V_16 , L_51 ) ;
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
for ( V_6 = 0 ; V_6 < V_16 -> V_22 ; V_6 ++ ) {
F_1 ( V_6 , F_25 ( V_12 ) ) ;
V_16 -> V_23 [ V_6 ] = F_5 ( F_26 ( V_12 ) ) ;
}
F_14 ( 4 , V_16 , L_52 ) ;
V_16 -> V_37 = 0x01 ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
F_15 ( V_76 , & V_16 -> V_25 ) ;
if ( V_16 -> V_23 [ 0 ] == 0x03 )
F_8 ( V_16 -> V_23 , V_16 -> V_22 ) ;
V_57 = F_13 ( V_16 ) ;
if ( V_57 == 0 ) {
V_16 -> V_69 = 0 ;
V_16 -> V_62 = V_77 ;
} else {
V_16 -> V_69 = V_71 ;
V_16 -> V_62 = V_78 ;
F_15 ( V_50 , & V_16 -> V_25 ) ;
}
if ( F_24 ( V_50 , & V_16 -> V_25 ) == 1 ) {
F_14 ( 4 , V_16 , L_53 ) ;
if ( ( F_24 ( V_79 , & V_16 -> V_25 ) == 0 ) &&
( V_16 -> V_27 != 0x11 ) &&
! ( F_24 ( V_28 , & V_16 -> V_25 ) &&
F_24 ( V_32 , & V_16 -> V_25 ) ) ) {
F_14 ( 4 , V_16 , L_54 ) ;
F_15 ( V_79 , & V_16 -> V_25 ) ;
V_40 . V_44 = ( 0x01 << V_16 -> V_26 ) ;
V_40 . V_25 = 0x01 ;
V_40 . V_45 = 0x00 ;
V_40 . V_46 = 0x00 ;
V_40 . V_47 = 0x00 ;
if ( F_23 ( V_16 , & V_40 ) == 0 ) {
F_14 ( 4 , V_16 , L_55 ) ;
F_16 ( V_79 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_80 ) ;
} else {
F_14 ( 4 , V_16 , L_56
L_57 ) ;
F_16 ( V_76 , & V_16 -> V_25 ) ;
F_16 ( V_50 , & V_16 -> V_25 ) ;
V_16 -> V_58 =
V_16 -> V_59 =
V_16 -> V_29 =
V_16 -> V_60 = V_16 -> V_61 = 0 ;
V_16 -> V_62 = V_63 ;
V_16 -> V_69 = V_71 ;
}
} else {
F_18 ( V_16 ) ;
if ( F_24 ( V_79 , & V_16 -> V_25 ) == 1 )
F_14 ( 4 , V_16 , L_58
L_59 ) ;
if ( V_16 -> V_27 == 0x11 )
F_14 ( 4 , V_16 , L_60
L_61 ) ;
if ( F_24 ( V_28 , & V_16 -> V_25 )
&& F_24 ( V_32 , & V_16 -> V_25 ) )
F_14 ( 4 , V_16 , L_62
L_63 ) ;
F_16 ( V_79 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_80 ) ;
}
} else {
F_14 ( 4 , V_16 , L_64 ) ;
F_35 ( & V_16 -> V_80 ) ;
}
break;
case V_77 :
F_14 ( 4 , V_16 , L_65 ) ;
if ( V_16 -> V_61 == 0 || V_16 -> V_61 == 10 ) {
F_15 ( V_81 , & V_16 -> V_25 ) ;
F_37 ( & V_16 -> V_33 -> V_16 , V_82 L_66 ) ;
if ( F_24 ( V_30 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_67
L_68 , V_16 -> V_29 ) ;
}
#ifdef F_27
else if ( F_24 ( V_83 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_69 ) ;
} else {
F_14 ( 4 , V_16 , L_70
L_71 ) ;
}
#endif
V_16 -> V_61 = 0 ;
F_35 ( & V_16 -> V_80 ) ;
}
V_16 -> V_61 ++ ;
V_16 -> V_69 = V_84 ;
V_16 -> V_62 = V_63 ;
break;
default:
F_14 ( 7 , V_16 , L_72 ) ;
break;
}
V_67:
F_14 ( 7 , V_16 , L_73 ) ;
F_16 ( V_64 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_85 ) ;
V_65:
F_14 ( 7 , V_16 , L_74 ) ;
F_38 ( & V_16 -> V_54 , V_86 + V_16 -> V_69 ) ;
F_16 ( V_53 , & V_16 -> V_25 ) ;
}
static T_2 F_39 ( struct V_87 * V_88 , T_3 char * V_89 , T_4 V_90 ,
T_5 * V_91 )
{
struct V_15 * V_16 = V_88 -> V_92 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
T_2 V_43 ;
int V_6 , V_93 , V_94 ;
F_14 ( 2 , V_16 , L_75 , V_95 -> V_96 , V_95 -> V_97 ) ;
if ( V_90 == 0 )
return 0 ;
if ( ! F_40 ( V_16 -> V_33 ) ||
F_24 ( V_51 , & V_16 -> V_25 ) )
return - V_98 ;
if ( F_24 ( V_30 , & V_16 -> V_25 ) )
return - V_99 ;
if ( F_30
( V_16 -> V_80 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_24 ( V_76 , ( void * ) & V_16 -> V_25 ) != 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
return - V_102 ;
return - V_103 ;
}
if ( F_24 ( V_50 , & V_16 -> V_25 ) == 0 )
return - V_99 ;
if ( F_30
( V_16 -> V_104 ,
( ( V_88 -> V_100 & V_101 ) || ( V_16 -> V_59 < V_16 -> V_58 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
return - V_102 ;
return - V_103 ;
}
if ( F_30
( V_16 -> V_85 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_31 ( V_64 , ( void * ) & V_16 -> V_25 ) == 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
return - V_102 ;
return - V_103 ;
}
V_43 = 0 ;
V_16 -> V_66 = F_5 ( F_12 ( V_12 ) ) ;
if ( ( V_16 -> V_66 & 1 ) == 0
|| V_16 -> V_66 == 0xff ) {
F_16 ( V_50 , & V_16 -> V_25 ) ;
if ( V_16 -> V_66 & 1 ) {
F_15 ( V_51 , & V_16 -> V_25 ) ;
V_43 = - V_98 ;
} else {
V_43 = - V_99 ;
}
goto V_67;
}
F_14 ( 4 , V_16 , L_76 ) ;
V_93 = F_41 ( V_90 , ( T_4 ) ( V_16 -> V_58 - V_16 -> V_59 ) ) ;
V_94 = V_16 -> V_59 ;
if ( V_94 + V_93 > 255 )
V_93 = 256 - V_94 ;
F_14 ( 4 , V_16 , L_77 , V_93 ) ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ ) {
F_1 ( V_94 ++ , F_25 ( V_12 ) ) ;
V_16 -> V_105 [ V_6 ] = F_4 ( F_26 ( V_12 ) ) ;
}
V_93 = F_41 ( V_90 , ( T_4 ) ( V_16 -> V_58 - V_16 -> V_59 ) ) ;
if ( V_94 + V_93 > 255 ) {
F_14 ( 4 , V_16 , L_78 , V_93 ) ;
V_16 -> V_37 |= 0x10 ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
for (; V_6 < V_93 ; V_6 ++ ) {
F_1 ( V_94 ++ , F_25 ( V_12 ) ) ;
V_16 -> V_105 [ V_6 ] = F_4 ( F_26 ( V_12 ) ) ;
}
}
if ( V_16 -> V_26 == 0 && V_90 > V_16 -> V_58 - V_16 -> V_59 && V_6 ) {
F_14 ( 4 , V_16 , L_79 ) ;
V_16 -> V_105 [ V_6 ] = V_16 -> V_105 [ V_6 - 1 ] ;
V_16 -> V_105 [ V_6 - 1 ] = V_16 -> V_106 ;
V_93 ++ ;
}
V_90 = V_93 ;
V_16 -> V_59 = V_16 -> V_58 + 1 ;
F_14 ( 4 , V_16 , L_80 ) ;
V_16 -> V_37 &= 0xdf ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
F_1 ( 0 , F_19 ( V_12 ) ) ;
if ( ! F_28 ( V_12 , V_16 ) ) {
V_43 = - V_98 ;
goto V_67;
}
if ( F_24 ( V_24 , & V_16 -> V_25 ) && V_90 > 0 )
F_8 ( V_16 -> V_105 , V_90 ) ;
if ( F_42 ( V_89 , V_16 -> V_105 , V_90 ) )
V_43 = - V_107 ;
V_67:
F_16 ( V_64 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_85 ) ;
F_14 ( 2 , V_16 , L_81 ,
( V_43 < 0 ? V_43 : V_90 ) ) ;
return V_43 < 0 ? V_43 : V_90 ;
}
static T_2 F_43 ( struct V_87 * V_88 , const char T_3 * V_89 ,
T_4 V_90 , T_5 * V_91 )
{
struct V_15 * V_16 = V_88 -> V_92 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
unsigned short V_13 ;
unsigned char V_14 ;
unsigned char V_108 ;
unsigned char V_109 ;
unsigned short V_110 ;
unsigned short V_111 ;
T_2 V_43 ;
int V_6 ;
F_14 ( 2 , V_16 , L_82 , V_95 -> V_96 , V_95 -> V_97 ) ;
if ( V_90 == 0 )
return 0 ;
if ( V_16 -> V_26 == 0 && V_90 < 4 ) {
F_14 ( 4 , V_16 , L_83 ) ;
return - V_99 ;
}
V_111 = V_90 & 0x1ff ;
V_109 = V_16 -> V_26 ? 0 : V_111 > 5 ? 0x08 : 0 ;
if ( ! F_40 ( V_16 -> V_33 ) ||
F_24 ( V_51 , & V_16 -> V_25 ) )
return - V_98 ;
if ( F_24 ( V_30 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_84 ) ;
return - V_99 ;
}
if ( F_30
( V_16 -> V_80 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_24 ( V_76 , ( void * ) & V_16 -> V_25 ) != 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
return - V_102 ;
return - V_103 ;
}
if ( F_24 ( V_50 , & V_16 -> V_25 ) == 0 ) {
F_14 ( 4 , V_16 , L_85 ) ;
return - V_99 ;
}
if ( F_30
( V_16 -> V_85 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_31 ( V_64 , ( void * ) & V_16 -> V_25 ) == 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
return - V_102 ;
return - V_103 ;
}
if ( F_44 ( V_16 -> V_112 , V_89 , ( ( V_90 > 512 ) ? 512 : V_90 ) ) )
return - V_107 ;
V_43 = 0 ;
V_16 -> V_66 = F_5 ( F_12 ( V_12 ) ) ;
if ( ( V_16 -> V_66 & 1 ) == 0
|| V_16 -> V_66 == 0xff ) {
F_16 ( V_50 , & V_16 -> V_25 ) ;
if ( V_16 -> V_66 & 1 ) {
F_15 ( V_51 , & V_16 -> V_25 ) ;
V_43 = - V_98 ;
} else {
F_14 ( 4 , V_16 , L_86 ) ;
V_43 = - V_99 ;
}
goto V_67;
}
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
if ( ! F_28 ( V_12 , V_16 ) ) {
V_43 = - V_98 ;
goto V_67;
}
V_16 -> V_37 |= ( V_109 ) ;
F_18 ( V_16 ) ;
V_14 = F_5 ( F_19 ( V_12 ) ) ;
V_16 -> V_37 = 0x20
| ( V_109 )
| ( F_24 ( V_24 , & V_16 -> V_25 ) ? 2 : 0 )
| ( ( ( V_16 -> V_38 - 1 ) & 0x0100 ) >> 8 ) ;
F_14 ( 1 , V_16 , L_87 , V_16 -> V_37 ) ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
F_14 ( 4 , V_16 , L_88 ) ;
for ( V_6 = 0 ; V_6 < V_111 ; V_6 ++ ) {
if ( V_6 >= 256 ) {
V_16 -> V_37 = 0x20
| ( V_109 )
| ( F_24 ( V_24 , & V_16 -> V_25 ) ? 2 : 0 )
| ( ( ( V_16 -> V_38 - 1 ) & 0x0100 ) >> 8 )
| 0x10 ;
F_14 ( 4 , V_16 , L_89
L_90 , V_16 -> V_37 ) ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
}
if ( F_24 ( V_24 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_91
L_92 , ( unsigned char ) V_16 -> V_112 [ V_6 ] ,
F_6 ( V_16 -> V_112 [ V_6 ] ) ) ;
F_1 ( V_6 , F_25 ( V_12 ) ) ;
F_1 ( F_6 ( V_16 -> V_112 [ V_6 ] ) ,
F_26 ( V_12 ) ) ;
} else {
F_1 ( V_6 , F_25 ( V_12 ) ) ;
F_1 ( V_16 -> V_112 [ V_6 ] , F_26 ( V_12 ) ) ;
}
}
F_14 ( 4 , V_16 , L_93 ) ;
if ( V_16 -> V_26 == 0 ) {
if ( V_111 == 4 ) {
F_14 ( 4 , V_16 , L_94 ) ;
F_1 ( V_6 , F_25 ( V_12 ) ) ;
if ( F_24 ( V_24 , & V_16 -> V_25 ) )
F_1 ( 0xff , F_26 ( V_12 ) ) ;
else
F_1 ( 0x00 , F_26 ( V_12 ) ) ;
}
if ( V_109 )
V_110 = V_111 ;
else {
if ( V_111 == 4 )
V_110 = 5 ;
else {
V_110 = 5 + ( unsigned char ) V_16 -> V_112 [ 4 ] ;
if ( V_16 -> V_112 [ 4 ] == 0 )
V_110 += 0x100 ;
}
}
} else
V_110 = V_111 ;
if ( F_24 ( V_24 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_95
L_96 , F_6 ( V_16 -> V_112 [ 1 ] ) ) ;
F_1 ( F_6 ( V_16 -> V_112 [ 1 ] ) , F_11 ( V_12 ) ) ;
} else {
F_14 ( 4 , V_16 , L_97 , V_16 -> V_112 [ 1 ] ) ;
F_1 ( V_16 -> V_112 [ 1 ] , F_11 ( V_12 ) ) ;
}
F_14 ( 1 , V_16 , L_98 ,
( unsigned char ) ( V_110 & 0xff ) ) ;
F_1 ( ( unsigned char ) ( V_110 & 0xff ) , F_45 ( V_12 ) ) ;
F_14 ( 1 , V_16 , L_99 ,
0x40
| ( V_16 -> V_66 & 2 ? 0 : 4 )
| ( V_16 -> V_26 ? 0x10 : 0x08 )
| ( V_110 & 0x100 ) >> 8 ) ;
F_1 ( 0x40
| ( V_16 -> V_66 & 2 ? 0 : 4 )
| ( V_16 -> V_26 ? 0x10 : 0x08 )
| ( V_110 & 0x100 ) >> 8 ,
F_12 ( V_12 ) ) ;
if ( V_16 -> V_26 == 1 ) {
F_14 ( 4 , V_16 , L_100 ) ;
for ( V_6 = 0 ; V_6 < 1000 ; V_6 ++ ) {
if ( F_5 ( F_12 ( V_12 ) ) & 0x08 )
break;
F_46 ( 10 ) ;
}
if ( V_6 == 1000 ) {
F_14 ( 4 , V_16 , L_101 ) ;
V_43 = - V_99 ;
goto V_67;
}
}
V_108 = 0 ;
if ( V_16 -> V_26 ) {
for ( V_6 = 0 ; V_6 < 6000 ; V_6 ++ ) {
F_10 ( V_12 , & V_13 ) ;
if ( V_13 >= 3 ) {
V_108 = F_5 ( F_19 ( V_12 ) ) ;
F_14 ( 4 , V_16 , L_102 , V_108 ) ;
break;
}
F_46 ( 10 ) ;
}
if ( V_6 == 6000 ) {
F_14 ( 4 , V_16 , L_103 ) ;
V_43 = - V_99 ;
goto V_67;
}
} else
F_16 ( V_113 , & V_16 -> V_25 ) ;
F_10 ( V_12 , & V_16 -> V_58 ) ;
for ( V_6 = 0 ; V_6 < 600 ; V_6 ++ ) {
if ( V_16 -> V_26 ) {
if ( V_16 -> V_58 >= V_108 + 4 )
break;
}
F_46 ( 10 ) ;
F_10 ( V_12 , & V_13 ) ;
if ( V_13 > V_16 -> V_58 ) {
F_14 ( 1 , V_16 , L_104 ) ;
V_6 = 0 ;
V_16 -> V_58 = V_13 ;
}
else if ( V_16 -> V_26 == 0 ) {
if ( ( F_5 ( F_25 ( V_12 ) ) & 0x80 ) ) {
F_14 ( 1 , V_16 , L_105 ) ;
} else {
F_14 ( 1 , V_16 , L_106
L_107 ) ;
V_16 -> V_106 = F_5 ( F_19 ( V_12 ) ) ;
F_14 ( 1 , V_16 , L_108 ,
V_16 -> V_106 ) ;
V_6 = 0 ;
}
if ( F_5 ( F_12 ( V_12 ) ) & 0x08 ) {
F_14 ( 1 , V_16 , L_109 ) ;
break;
}
}
if ( V_16 -> V_26 )
V_108 = F_5 ( F_19 ( V_12 ) ) ;
}
if ( V_6 == 600 ) {
F_14 ( 1 , V_16 , L_110 ) ;
V_43 = - V_99 ;
goto V_67;
} else {
if ( V_16 -> V_26 == 0 ) {
F_14 ( 1 , V_16 , L_111 ) ;
for ( V_6 = 0 ; V_6 < 1000 ; V_6 ++ ) {
if ( F_5 ( F_12 ( V_12 ) ) & 0x08 )
break;
F_46 ( 10 ) ;
}
if ( V_6 == 1000 ) {
F_14 ( 1 , V_16 , L_112 ) ;
V_43 = - V_99 ;
goto V_67;
}
V_16 -> V_106 = F_5 ( F_19 ( V_12 ) ) ;
F_14 ( 4 , V_16 , L_108 ,
V_16 -> V_106 ) ;
F_10 ( V_12 , & V_16 -> V_58 ) ;
F_14 ( 4 , V_16 , L_113 , V_16 -> V_58 ) ;
}
}
V_16 -> V_59 = V_16 -> V_26 ? 0 : V_111 == 4 ? 5 : V_111 > V_16 -> V_58 ? 5 : V_111 ;
F_14 ( 4 , V_16 , L_114 ,
V_16 -> V_58 , V_16 -> V_59 , V_111 ) ;
V_67:
F_14 ( 4 , V_16 , L_115 ) ;
F_1 ( 0x80 , F_12 ( V_12 ) ) ;
if ( V_43 < 0 ) {
F_14 ( 4 , V_16 , L_116 ) ;
V_16 -> V_37 &= 0xdf ;
F_1 ( V_16 -> V_37 , F_19 ( V_12 ) ) ;
}
F_16 ( V_64 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_85 ) ;
F_35 ( & V_16 -> V_104 ) ;
memset ( ( char * ) V_16 -> V_112 , 0 , 512 ) ;
F_14 ( 2 , V_16 , L_117 ) ;
return V_43 < 0 ? V_43 : V_111 ;
}
static void F_47 ( struct V_15 * V_16 )
{
F_14 ( 3 , V_16 , L_118 ) ;
if ( ! V_16 -> V_55 ) {
F_14 ( 5 , V_16 , L_119 ) ;
F_48 ( & V_16 -> V_54 , F_34 , ( unsigned long ) V_16 ) ;
V_16 -> V_55 = 1 ;
F_38 ( & V_16 -> V_54 , V_86 ) ;
} else
F_14 ( 5 , V_16 , L_120 ) ;
F_14 ( 3 , V_16 , L_121 ) ;
}
static void F_49 ( struct V_15 * V_16 )
{
F_14 ( 3 , V_16 , L_122 ) ;
if ( V_16 -> V_55 ) {
F_14 ( 5 , V_16 , L_123 ) ;
F_29 ( V_16 ) ;
F_16 ( V_50 , & V_16 -> V_25 ) ;
F_16 ( V_76 , & V_16 -> V_25 ) ;
} else
F_14 ( 5 , V_16 , L_124 ) ;
F_14 ( 3 , V_16 , L_125 ) ;
}
static long F_50 ( struct V_87 * V_88 , unsigned int V_114 , unsigned long V_115 )
{
struct V_15 * V_16 = V_88 -> V_92 ;
unsigned int V_12 = V_16 -> V_33 -> V_34 [ 0 ] -> V_35 ;
struct V_116 * V_116 = V_88 -> V_117 . V_118 -> V_119 ;
struct V_120 * V_121 ;
int V_122 ;
int V_43 ;
void T_3 * V_123 = ( void T_3 * ) V_115 ;
#ifdef F_27
char * V_124 [ V_125 + 1 ] = {
[ F_51 ( V_126 ) ] L_126 ,
[ F_51 ( V_127 ) ] L_127 ,
[ F_51 ( V_128 ) ] L_128 ,
[ F_51 ( V_129 ) ] L_129 ,
[ F_51 ( V_130 ) ] L_130 ,
} ;
F_14 ( 3 , V_16 , L_131 , F_52 ( V_116 ) ,
F_53 ( V_116 ) , V_124 [ F_51 ( V_114 ) ] ) ;
#endif
F_54 ( & V_131 ) ;
V_43 = - V_98 ;
V_121 = V_132 [ F_53 ( V_116 ) ] ;
if ( ! F_40 ( V_121 ) ) {
F_14 ( 4 , V_16 , L_132 ) ;
goto V_133;
}
if ( F_24 ( V_51 , & V_16 -> V_25 ) ) {
F_14 ( 4 , V_16 , L_133 ) ;
goto V_133;
}
V_43 = - V_134 ;
if ( F_55 ( V_114 ) != V_135 ) {
F_14 ( 4 , V_16 , L_134 ) ;
goto V_133;
}
if ( F_51 ( V_114 ) > V_125 ) {
F_14 ( 4 , V_16 , L_135 ) ;
goto V_133;
}
V_122 = F_56 ( V_114 ) ;
V_43 = - V_107 ;
F_14 ( 4 , V_16 , L_136 ,
F_57 ( V_114 ) , V_136 , V_137 , V_122 , V_114 ) ;
if ( F_57 ( V_114 ) & V_136 ) {
if ( ! F_58 ( V_138 , V_123 , V_122 ) )
goto V_133;
}
if ( F_57 ( V_114 ) & V_137 ) {
if ( ! F_58 ( V_139 , V_123 , V_122 ) )
goto V_133;
}
V_43 = 0 ;
switch ( V_114 ) {
case V_126 :
F_14 ( 4 , V_16 , L_137 ) ;
{
int V_140 ;
V_140 = V_16 -> V_66 & 3 ;
if ( F_24 ( V_76 , & V_16 -> V_25 ) )
V_140 |= V_141 ;
if ( F_24 ( V_50 , & V_16 -> V_25 ) )
V_140 |= V_142 ;
if ( F_24 ( V_51 , & V_16 -> V_25 ) )
V_140 |= V_143 ;
if ( F_24 ( V_81 , & V_16 -> V_25 ) )
V_140 |= V_144 ;
if ( F_42 ( V_123 , & V_140 , sizeof( int ) ) )
V_43 = - V_107 ;
}
break;
case V_127 :
F_14 ( 4 , V_16 , L_138 ) ;
{
struct V_145 T_3 * V_145 = V_123 ;
int V_14 ;
if ( F_30
( V_16 -> V_80 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_24 ( V_76 , ( void * ) & V_16 -> V_25 )
!= 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
V_43 = - V_102 ;
else
V_43 = - V_103 ;
break;
}
V_43 = - V_107 ;
if ( F_24 ( V_50 , & V_16 -> V_25 ) == 0 ) {
V_14 = - 1 ;
if ( F_42 ( & ( V_145 -> V_22 ) , & V_14 ,
sizeof( int ) ) )
break;
} else {
if ( F_42 ( V_145 -> V_23 , V_16 -> V_23 ,
V_16 -> V_22 ) )
break;
V_14 = V_16 -> V_22 ;
if ( F_42 ( & ( V_145 -> V_22 ) , & V_14 , sizeof( int ) ) )
break;
}
V_43 = 0 ;
break;
}
case V_128 :
#ifdef F_27
F_14 ( 4 , V_16 , L_139 ) ;
if ( V_16 -> V_66 & 0x01 ) {
F_14 ( 4 , V_16 , L_140 ) ;
} else {
F_14 ( 2 , V_16 , L_141 ) ;
}
if ( V_16 -> V_66 & 0x02 ) {
F_14 ( 4 , V_16 , L_142 ) ;
} else {
F_14 ( 2 , V_16 , L_143 ) ;
}
#endif
if ( ( V_16 -> V_66 & 0x01 ) && ( V_16 -> V_66 & 0x02 ) ) {
if ( F_30
( V_16 -> V_85 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_31 ( V_64 , ( void * ) & V_16 -> V_25 )
== 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
V_43 = - V_102 ;
else
V_43 = - V_103 ;
break;
}
F_14 ( 4 , V_16 , L_144 ) ;
F_1 ( 0x42 , F_12 ( V_12 ) ) ;
F_16 ( V_76 , & V_16 -> V_25 ) ;
F_16 ( V_50 , & V_16 -> V_25 ) ;
V_16 -> V_62 = V_68 ;
F_16 ( V_64 , & V_16 -> V_25 ) ;
if ( F_30
( V_16 -> V_80 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_24 ( V_50 , ( void * ) & V_16 -> V_25 ) !=
0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
V_43 = - V_102 ;
else
V_43 = - V_103 ;
break;
}
}
F_16 ( V_64 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_85 ) ;
V_43 = 0 ;
break;
case V_129 :
{
struct V_40 V_146 ;
if ( F_44 ( & V_146 , V_123 ,
sizeof( struct V_40 ) ) ) {
V_43 = - V_107 ;
break;
}
V_43 = 0 ;
F_14 ( 4 , V_16 , L_145 ) ;
if ( F_30
( V_16 -> V_80 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_24 ( V_76 , ( void * ) & V_16 -> V_25 )
!= 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
V_43 = - V_102 ;
else
V_43 = - V_103 ;
break;
}
if ( F_30
( V_16 -> V_85 ,
( ( V_88 -> V_100 & V_101 )
|| ( F_31 ( V_64 , ( void * ) & V_16 -> V_25 )
== 0 ) ) ) ) {
if ( V_88 -> V_100 & V_101 )
V_43 = - V_102 ;
else
V_43 = - V_103 ;
break;
}
if ( ( V_43 = F_23 ( V_16 , & V_146 ) ) != 0 ) {
V_16 -> V_62 = V_63 ;
F_16 ( V_50 , & V_16 -> V_25 ) ;
}
F_16 ( V_64 , & V_16 -> V_25 ) ;
F_35 ( & V_16 -> V_85 ) ;
}
break;
#ifdef F_27
case V_130 :
V_43 = - V_147 ;
break;
#endif
default:
F_14 ( 4 , V_16 , L_146 ) ;
V_43 = - V_147 ;
}
V_133:
F_59 ( & V_131 ) ;
return V_43 ;
}
static int F_60 ( struct V_116 * V_116 , struct V_87 * V_88 )
{
struct V_15 * V_16 ;
struct V_120 * V_121 ;
int V_148 = F_53 ( V_116 ) ;
int V_149 ;
if ( V_148 >= V_150 )
return - V_98 ;
F_54 ( & V_131 ) ;
V_121 = V_132 [ V_148 ] ;
if ( V_121 == NULL || ! F_40 ( V_121 ) ) {
V_149 = - V_98 ;
goto V_133;
}
if ( V_121 -> V_151 ) {
V_149 = - V_152 ;
goto V_133;
}
V_16 = V_121 -> V_153 ;
V_88 -> V_92 = V_16 ;
F_14 ( 2 , V_16 , L_147 ,
F_52 ( V_116 ) , V_148 , V_95 -> V_96 , V_95 -> V_97 ) ;
F_61 ( V_16 ) ;
if ( V_88 -> V_100 & V_101 ) {
V_149 = - V_102 ;
goto V_133;
}
V_16 -> V_69 = V_71 ;
F_47 ( V_16 ) ;
V_121 -> V_151 = 1 ;
F_14 ( 2 , V_16 , L_148 ) ;
V_149 = F_62 ( V_116 , V_88 ) ;
V_133:
F_59 ( & V_131 ) ;
return V_149 ;
}
static int F_63 ( struct V_116 * V_116 , struct V_87 * V_88 )
{
struct V_15 * V_16 ;
struct V_120 * V_121 ;
int V_148 = F_53 ( V_116 ) ;
if ( V_148 >= V_150 )
return - V_98 ;
V_121 = V_132 [ V_148 ] ;
if ( V_121 == NULL )
return - V_98 ;
V_16 = V_121 -> V_153 ;
F_14 ( 2 , V_16 , L_149 ,
F_52 ( V_116 ) , V_148 ) ;
F_49 ( V_16 ) ;
F_61 ( V_16 ) ;
V_121 -> V_151 = 0 ;
F_64 ( & V_16 -> V_52 ) ;
F_14 ( 2 , V_16 , L_150 ) ;
return 0 ;
}
static void F_65 ( struct V_120 * V_121 )
{
struct V_15 * V_16 = V_121 -> V_153 ;
F_14 ( 3 , V_16 , L_151 ) ;
while ( V_121 -> V_151 ) {
F_66 (KERN_INFO MODULE_NAME L_152
L_153 ) ;
F_67 ( V_16 -> V_52 , ( V_121 -> V_151 == 0 ) ) ;
}
F_14 ( 3 , V_16 , L_154 ) ;
return;
}
static int F_68 ( struct V_120 * V_33 , void * V_154 )
{
return F_69 ( V_33 ) ;
}
static int F_70 ( struct V_120 * V_121 , int V_155 )
{
struct V_15 * V_16 ;
V_121 -> V_156 |= V_157 ;
if ( F_71 ( V_121 , F_68 , NULL ) )
goto V_158;
if ( F_72 ( V_121 ) )
goto V_158;
V_16 = V_121 -> V_153 ;
return 0 ;
V_158:
F_73 ( V_121 ) ;
return - V_98 ;
}
static int F_74 ( struct V_120 * V_121 )
{
struct V_15 * V_16 ;
V_16 = V_121 -> V_153 ;
F_49 ( V_16 ) ;
return 0 ;
}
static int F_75 ( struct V_120 * V_121 )
{
struct V_15 * V_16 ;
V_16 = V_121 -> V_153 ;
if ( V_121 -> V_151 )
F_47 ( V_16 ) ;
return 0 ;
}
static void F_73 ( struct V_120 * V_121 )
{
F_65 ( V_121 ) ;
F_76 ( V_121 ) ;
}
static int F_77 ( struct V_120 * V_121 )
{
struct V_15 * V_16 ;
int V_6 , V_149 ;
for ( V_6 = 0 ; V_6 < V_150 ; V_6 ++ )
if ( V_132 [ V_6 ] == NULL )
break;
if ( V_6 == V_150 ) {
F_66 (KERN_NOTICE MODULE_NAME L_155 ) ;
return - V_98 ;
}
V_16 = F_78 ( sizeof( struct V_15 ) , V_159 ) ;
if ( V_16 == NULL )
return - V_160 ;
V_16 -> V_33 = V_121 ;
V_121 -> V_153 = V_16 ;
V_132 [ V_6 ] = V_121 ;
F_79 ( & V_16 -> V_52 ) ;
F_79 ( & V_16 -> V_85 ) ;
F_79 ( & V_16 -> V_80 ) ;
F_79 ( & V_16 -> V_104 ) ;
V_149 = F_70 ( V_121 , V_6 ) ;
if ( V_149 ) {
V_132 [ V_6 ] = NULL ;
F_80 ( V_16 ) ;
return V_149 ;
}
F_81 ( V_161 , NULL , F_82 ( V_162 , V_6 ) , NULL , L_156 , V_6 ) ;
return 0 ;
}
static void F_83 ( struct V_120 * V_121 )
{
struct V_15 * V_16 = V_121 -> V_153 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < V_150 ; V_155 ++ )
if ( V_132 [ V_155 ] == V_121 )
break;
if ( V_155 == V_150 )
return;
F_49 ( V_16 ) ;
F_73 ( V_121 ) ;
V_132 [ V_155 ] = NULL ;
F_80 ( V_16 ) ;
F_84 ( V_161 , F_82 ( V_162 , V_155 ) ) ;
return;
}
static int T_6 F_85 ( void )
{
int V_43 ;
V_161 = F_86 ( V_163 , L_157 ) ;
if ( F_87 ( V_161 ) )
return F_88 ( V_161 ) ;
V_162 = F_89 ( 0 , V_164 , & V_165 ) ;
if ( V_162 < 0 ) {
F_66 (KERN_WARNING MODULE_NAME
L_158 ) ;
F_90 ( V_161 ) ;
return V_162 ;
}
V_43 = F_91 ( & V_166 ) ;
if ( V_43 < 0 ) {
F_92 ( V_162 , V_164 ) ;
F_90 ( V_161 ) ;
return V_43 ;
}
return 0 ;
}
static void T_7 F_93 ( void )
{
F_94 ( & V_166 ) ;
F_92 ( V_162 , V_164 ) ;
F_90 ( V_161 ) ;
}
