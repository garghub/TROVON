static long T_1 F_1 ( long * V_1 , long V_2 )
{
while ( * V_1 != - 1 ) {
if ( F_2 ( * V_1 , V_2 , L_1 ) ) {
F_3 ( * V_1 , V_2 ) ;
return * V_1 ;
}
V_1 ++ ;
}
return - 1 ;
}
static int T_1 F_4 ( struct V_3 * V_4 ,
unsigned short V_5 )
{
static int V_6 [] = { 7 , 7 , 10 , 10 , 2 , 2 , 2 } ;
V_4 -> V_5 = V_5 ;
strcpy ( V_4 -> V_7 , V_8 [ V_5 ] ) ;
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = - 1 ;
#ifndef F_6
#ifdef F_7
if ( V_11 && V_4 -> V_12 )
V_4 -> V_12 |= 0xc00 ;
else
#endif
{
V_4 -> V_12 = 0xf8c ;
V_4 -> V_13 = V_6 [ V_5 ] ;
}
#else
V_4 -> V_13 = V_6 [ V_5 ] ;
#endif
switch ( V_5 ) {
#ifndef F_6
case V_14 :
case V_15 :
V_4 -> V_16 = ( V_5 == V_14 ) ? 0xe2 : 0xe3 ;
V_4 -> V_17 = 3 ;
break;
case V_18 :
case V_19 :
V_4 -> V_16 = 0xe5 ;
V_4 -> V_17 = 3 ;
break;
#else
case V_20 :
case V_21 :
case V_22 :
V_4 -> V_12 = ( V_5 == V_20 ) ? 0xf8f : 0xf8d ;
if ( ! V_4 -> V_23 )
V_4 -> V_23 = 0xe0e ;
V_4 -> V_16 = 0xe4 ;
V_4 -> V_17 = 0 ;
break;
#endif
default:
F_8 ( V_24 L_2 , V_5 ) ;
return - V_25 ;
}
return 0 ;
}
static unsigned char F_9 ( struct V_3 * V_4 ,
unsigned char V_26 )
{
unsigned long V_27 ;
unsigned char V_28 = 0xff ;
F_10 ( & V_4 -> V_9 , V_27 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
switch ( V_4 -> V_5 ) {
#ifndef F_6
case V_18 :
case V_19 :
if ( V_26 > 7 ) {
F_11 ( V_26 , V_4 -> V_12 + 8 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
V_28 = F_12 ( V_4 -> V_12 + 9 ) ;
break;
}
case V_14 :
case V_15 :
V_28 = F_12 ( V_4 -> V_12 + V_26 ) ;
break;
#else
case V_20 :
case V_21 :
case V_22 :
F_11 ( V_26 , V_4 -> V_23 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
V_28 = F_12 ( V_4 -> V_23 + 1 ) ;
break;
#endif
default:
F_8 ( V_24 L_2 , V_4 -> V_5 ) ;
}
F_13 ( & V_4 -> V_9 , V_27 ) ;
return V_28 ;
}
static void F_14 ( struct V_3 * V_4 , unsigned char V_26 ,
unsigned char V_29 )
{
unsigned long V_27 ;
F_10 ( & V_4 -> V_9 , V_27 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
switch ( V_4 -> V_5 ) {
#ifndef F_6
case V_18 :
case V_19 :
if ( V_26 > 7 ) {
F_11 ( V_26 , V_4 -> V_12 + 8 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( V_29 , V_4 -> V_12 + 9 ) ;
break;
}
case V_14 :
case V_15 :
F_11 ( V_29 , V_4 -> V_12 + V_26 ) ;
break;
#else
case V_20 :
case V_21 :
case V_22 :
F_11 ( V_26 , V_4 -> V_23 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( V_29 , V_4 -> V_23 + 1 ) ;
break;
#endif
default:
F_8 ( V_24 L_2 , V_4 -> V_5 ) ;
}
F_13 ( & V_4 -> V_9 , V_27 ) ;
}
static int F_15 ( struct V_3 * V_4 ,
long V_30 ,
int V_10 , int V_31 , int V_32 ,
long V_33 , int V_34 )
{
unsigned char V_35 ;
unsigned char V_36 ;
unsigned char V_37 ;
unsigned char V_38 = 0 ;
unsigned char V_39 ;
switch ( V_4 -> V_5 ) {
#ifndef F_6
case V_18 :
F_16 ( V_4 , F_17 ( 4 ) , 0xf0 , 0xfc ) ;
F_16 ( V_4 , F_17 ( 6 ) , 0x02 , 0x02 ) ;
case V_19 :
F_16 ( V_4 , F_17 ( 1 ) , 0x80 , 0x80 ) ;
F_16 ( V_4 , F_17 ( 2 ) , 0x00 , 0x20 ) ;
F_16 ( V_4 , F_17 ( 3 ) , 0xf0 , 0xff ) ;
#ifdef F_18
F_16 ( V_4 , F_17 ( 5 ) , 0x02 , 0x02 ) ;
#else
F_16 ( V_4 , F_17 ( 5 ) , 0x00 , 0x02 ) ;
#endif
break;
case V_14 :
case V_15 :
F_16 ( V_4 , F_17 ( 1 ) , 0x80 , 0x80 ) ;
F_16 ( V_4 , F_17 ( 2 ) , 0x00 , 0x20 ) ;
F_16 ( V_4 , F_17 ( 4 ) , 0x00 , 0x0c ) ;
#ifdef F_18
F_16 ( V_4 , F_17 ( 5 ) , 0x02 , 0x02 ) ;
#else
F_16 ( V_4 , F_17 ( 5 ) , 0x00 , 0x02 ) ;
#endif
break;
#else
case V_21 :
F_16 ( V_4 , F_17 ( 20 ) , 0x04 , 0x0c ) ;
case V_22 :
F_16 ( V_4 , F_17 ( 21 ) , 0x82 , 0xff ) ;
F_16 ( V_4 , F_17 ( 26 ) , 0x01 , 0x01 ) ;
case V_20 :
F_16 ( V_4 , F_17 ( 6 ) , 0x02 , 0x03 ) ;
F_16 ( V_4 , F_17 ( 3 ) , 0x00 , 0xff ) ;
F_16 ( V_4 , F_17 ( 4 ) , 0x10 |
( V_4 -> V_5 == V_20 ? 0x00 : 0x04 ) ,
0x34 ) ;
F_16 ( V_4 , F_17 ( 5 ) , 0x20 , 0xbf ) ;
break;
#endif
default:
F_8 ( V_24 L_2 , V_4 -> V_5 ) ;
return - V_40 ;
}
switch ( V_30 & 0x3ff ) {
case 0x130 :
V_4 -> V_41 = 0x530 ;
V_35 = 0x00 ;
break;
case 0x204 :
V_4 -> V_41 = 0x604 ;
V_35 = 0x03 ;
break;
case 0x280 :
V_4 -> V_41 = 0xe80 ;
V_35 = 0x01 ;
break;
case 0x340 :
V_4 -> V_41 = 0xf40 ;
V_35 = 0x02 ;
break;
default:
F_8 ( V_42 L_3 , V_30 ) ;
goto V_43;
}
F_16 ( V_4 , F_17 ( 1 ) , V_35 << 4 , 0x30 ) ;
V_43:
switch ( V_10 ) {
case 5 :
V_36 = 0x05 ;
break;
case 7 :
V_36 = 0x01 ;
break;
case 9 :
V_36 = 0x02 ;
break;
case 10 :
V_36 = 0x03 ;
break;
case 11 :
V_36 = 0x04 ;
break;
default:
F_8 ( V_42 L_4 , V_10 ) ;
goto V_44;
}
switch ( V_31 ) {
case 0 :
V_37 = 0x01 ;
break;
case 1 :
V_37 = 0x02 ;
break;
case 3 :
V_37 = 0x03 ;
break;
default:
F_8 ( V_42 L_5 , V_31 ) ;
goto V_44;
}
#if F_19 ( F_18 ) || F_19 ( F_6 )
if ( V_31 == V_32 ) {
F_8 ( V_24 L_6 ) ;
return - V_45 ;
}
switch ( V_32 ) {
case 0 :
case 1 :
break;
default:
F_8 ( V_42 L_7 , V_32 ) ;
goto V_44;
}
V_37 |= 0x04 ;
#endif
#ifndef F_6
F_11 ( V_36 << 3 | V_37 , V_4 -> V_41 ) ;
#else
F_14 ( V_4 , F_17 ( 3 ) , ( V_36 << 3 | V_37 ) ) ;
#endif
V_44:
if ( V_4 -> V_5 > V_14 ) {
switch ( V_33 ) {
case 0 :
case - 1 :
break;
case 0x300 :
V_38 = 0x03 ;
break;
case 0x310 :
V_38 = 0x02 ;
break;
case 0x320 :
V_38 = 0x01 ;
break;
case 0x330 :
V_38 = 0x00 ;
break;
default:
F_8 ( V_42
L_8 , V_33 ) ;
goto V_46;
}
switch ( V_34 ) {
case 5 :
V_39 = 0x02 ;
break;
case 7 :
V_39 = 0x03 ;
break;
case 9 :
V_39 = 0x00 ;
break;
case 10 :
V_39 = 0x01 ;
break;
default:
F_8 ( V_42 L_9 ,
V_34 ) ;
goto V_46;
}
F_16 ( V_4 , F_17 ( 6 ) ,
( V_33 <= 0 ) ? 0x00 :
0x80 | V_38 << 5 | V_39 << 3 ,
0xf8 ) ;
}
V_46:
return 0 ;
}
static int T_1 F_20 ( struct V_47 * V_4 )
{
struct V_48 * V_49 ;
unsigned int V_50 ;
struct V_51 V_52 , V_53 ;
int V_54 ;
if ( F_21 ( ! V_4 || ! V_4 -> V_55 ) )
return - V_40 ;
V_49 = V_4 -> V_49 ;
strcpy ( V_49 -> V_56 , V_4 -> V_55 -> V_7 ) ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_52 . V_57 = V_53 . V_57 = V_58 ;
strcpy ( V_52 . V_7 , L_10 ) ;
strcpy ( V_53 . V_7 , L_11 ) ;
V_54 = F_22 ( V_49 , & V_52 , & V_53 ) ;
if ( V_54 < 0 ) {
F_8 ( V_24 L_12 ) ;
return V_54 ;
}
strcpy ( V_52 . V_7 , L_10 ) ; V_52 . V_59 = 1 ;
strcpy ( V_53 . V_7 , L_13 ) ;
V_54 = F_22 ( V_49 , & V_52 , & V_53 ) ;
if ( V_54 < 0 ) {
F_8 ( V_24 L_12 ) ;
return V_54 ;
}
strcpy ( V_52 . V_7 , L_14 ) ; V_52 . V_59 = 1 ;
F_23 ( V_49 , & V_52 ) ;
V_52 . V_59 = 0 ;
for ( V_50 = 0 ; V_50 < F_24 ( V_60 ) ; V_50 ++ ) {
strcpy ( V_52 . V_7 , V_60 [ V_50 ] . V_7 ) ;
F_23 ( V_49 , & V_52 ) ;
V_54 = F_25 ( V_49 ,
F_26 ( & V_60 [ V_50 ] , V_4 ) ) ;
if ( V_54 < 0 )
return V_54 ;
}
return 0 ;
}
static T_2 F_27 ( int V_10 , void * V_61 )
{
struct V_3 * V_4 = V_61 ;
struct V_47 * V_62 = V_4 -> V_62 ;
unsigned char V_63 ;
if ( ! V_62 )
return V_64 ;
V_63 = F_9 ( V_4 , F_17 ( 11 ) ) ;
if ( ( V_63 & V_65 ) && V_62 -> V_66 )
F_28 ( V_62 -> V_66 ) ;
if ( ( V_63 & V_67 ) && V_62 -> V_68 ) {
F_29 ( V_62 ) ;
F_28 ( V_62 -> V_68 ) ;
}
F_11 ( 0x00 , F_30 ( V_62 , V_69 ) ) ;
return V_64 ;
}
static int T_1 F_31 ( struct V_3 * V_4 )
{
unsigned char V_29 ;
#ifdef F_6
unsigned long V_27 ;
#endif
V_4 -> V_70 = F_2 ( V_4 -> V_12 , V_4 -> V_13 ,
L_15 ) ;
if ( V_4 -> V_70 == NULL )
return - V_45 ;
#ifndef F_6
V_29 = F_9 ( V_4 , F_17 ( 1 ) ) ;
if ( V_29 != 0xff && V_29 != F_12 ( V_4 -> V_12 + F_17 ( 1 ) ) )
if ( V_29 == F_9 ( V_4 , F_17 ( 1 ) ) )
return 0 ;
#else
V_4 -> V_71 = F_2 ( V_4 -> V_23 , 2 ,
L_16 ) ;
if ( V_4 -> V_71 == NULL )
return - V_45 ;
F_10 ( & V_4 -> V_9 , V_27 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( ( ( V_4 -> V_23 & 0x1f0 ) >> 4 ) , V_4 -> V_12 ) ;
F_13 ( & V_4 -> V_9 , V_27 ) ;
V_29 = F_9 ( V_4 , F_17 ( 7 ) ) ;
F_14 ( V_4 , F_17 ( 7 ) , 0xff - V_29 ) ;
if ( F_9 ( V_4 , F_17 ( 7 ) ) == 0xff - V_29 )
return 0 ;
F_32 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
#endif
F_32 ( V_4 -> V_70 ) ;
V_4 -> V_70 = NULL ;
return - V_25 ;
}
static int T_1 F_33 ( struct V_3 * V_4 ,
struct V_72 * V_49 ,
const struct V_73 * V_74 )
{
struct V_75 * V_76 ;
int V_54 ;
struct V_75 * V_77 ;
#ifndef F_6
struct V_75 * V_78 ;
#endif
V_76 = F_34 ( V_49 , V_74 -> V_79 [ 0 ] . V_80 , NULL ) ;
if ( V_76 == NULL )
return - V_45 ;
V_54 = F_35 ( V_76 ) ;
if ( V_54 < 0 ) {
F_8 ( V_24 L_17 , V_54 ) ;
return V_54 ;
}
#ifdef F_6
V_30 = F_36 ( V_76 , 0 ) - 4 ;
V_81 = F_36 ( V_76 , 1 ) + 8 ;
V_4 -> V_23 = ( F_36 ( V_76 , 3 ) & ~ 0xf ) | 0xe ;
#else
V_78 = F_34 ( V_49 , V_74 -> V_79 [ 2 ] . V_80 , NULL ) ;
if ( V_78 == NULL )
return - V_45 ;
V_54 = F_35 ( V_78 ) ;
if ( V_54 < 0 ) {
F_8 ( V_24 L_18 , V_54 ) ;
return V_54 ;
}
V_30 = F_36 ( V_76 , 1 ) ;
V_81 = F_36 ( V_76 , 2 ) + 8 ;
V_4 -> V_12 = F_36 ( V_78 , 0 ) - 1 ;
V_4 -> V_13 = F_37 ( V_78 , 0 ) + 1 ;
#endif
V_10 = F_38 ( V_76 , 0 ) ;
V_31 = F_39 ( V_76 , 0 ) ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
V_32 = F_39 ( V_76 , 1 ) ;
#endif
V_77 = F_34 ( V_49 , V_74 -> V_79 [ 1 ] . V_80 , NULL ) ;
if ( V_77 && V_33 > 0 ) {
V_54 = F_35 ( V_77 ) ;
if ( V_54 < 0 ) {
F_8 ( V_24 L_19 ) ;
V_33 = - 1 ;
} else {
V_33 = F_36 ( V_77 , 0 ) ;
V_34 = F_38 ( V_77 , 0 ) ;
}
}
return V_74 -> V_82 ;
}
static void F_40 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_83 ;
if ( V_4 ) {
#ifdef F_6
if ( V_4 -> V_10 > 0 ) {
F_41 ( V_4 -> V_10 ) ;
F_42 ( V_4 -> V_10 , V_4 ) ;
}
F_32 ( V_4 -> V_71 ) ;
#endif
F_32 ( V_4 -> V_70 ) ;
}
}
static int T_1 F_43 ( struct V_48 * V_49 )
{
static long V_84 [] = { 0x530 , 0xe80 , 0xf40 , 0x604 , - 1 } ;
int error ;
int V_85 ;
struct V_3 * V_4 = V_49 -> V_83 ;
struct V_47 * V_62 ;
#ifdef F_18
struct V_86 * V_87 ;
#endif
struct V_88 * V_55 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
V_85 = V_32 ;
#else
V_85 = - 1 ;
#endif
if ( V_30 == V_93 ) {
V_30 = F_1 ( V_84 , 4 ) ;
if ( V_30 < 0 ) {
F_8 ( V_24 L_20 ) ;
return - V_45 ;
}
}
error = F_15 ( V_4 , V_30 , V_10 , V_31 , V_85 ,
V_33 , V_34 ) ;
if ( error )
return error ;
error = F_44 ( V_49 , V_4 -> V_41 + 4 , - 1 , V_10 , V_31 , V_85 ,
#ifdef F_6
V_94 , V_95 ,
#else
V_96 , 0 ,
#endif
& V_62 ) ;
if ( error < 0 )
return error ;
V_4 -> V_62 = V_62 ;
error = F_45 ( V_62 , 0 , & V_55 ) ;
if ( error < 0 )
return error ;
error = F_46 ( V_62 ) ;
if ( error < 0 )
return error ;
#ifdef F_6
error = F_20 ( V_62 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_18
error = F_47 ( V_62 , 0 , & V_87 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_6
error = F_48 ( V_10 , F_27 ,
0 , V_97 L_21 , V_4 ) ;
if ( error < 0 ) {
F_8 ( V_24 L_22 , V_10 ) ;
return error ;
}
#endif
V_4 -> V_10 = V_10 ;
strcpy ( V_49 -> V_98 , V_4 -> V_7 ) ;
sprintf ( V_49 -> V_99 , L_23 , V_49 -> V_98 ) ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
sprintf ( V_49 -> V_100 , L_24 ,
V_49 -> V_99 , V_55 -> V_7 ,
V_4 -> V_41 + 4 , V_10 , V_31 , V_85 ) ;
#else
sprintf ( V_49 -> V_100 , L_25 ,
V_49 -> V_99 , V_55 -> V_7 , V_4 -> V_41 + 4 , V_10 , V_31 ) ;
#endif
if ( V_33 <= 0 || V_33 == V_93 )
V_90 = NULL ;
else {
error = F_49 ( V_49 , 0 , V_101 ,
V_33 , 0 , V_34 , & V_90 ) ;
if ( error )
F_8 ( V_42 L_26 ,
V_33 ) ;
}
if ( V_81 > 0 && V_81 != V_93 ) {
struct V_102 * V_103 = NULL ;
#ifndef F_6
if ( V_4 -> V_5 == V_14 ||
V_4 -> V_5 == V_15 ||
V_4 -> V_5 == V_18 ) {
struct V_104 * V_105 ;
F_16 ( V_4 , F_17 ( 2 ) ,
0x20 , 0x20 ) ;
if ( F_50 ( V_49 , V_81 , V_81 - 8 ,
2 , & V_103 , & V_105 ) < 0 ) {
F_16 ( V_4 , F_17 ( 2 ) ,
0x00 , 0x20 ) ;
}
}
#endif
if ( ! V_103 && F_51 ( V_49 , V_81 , V_81 + 2 ,
V_106 , 0 , & V_103 ) < 0 ) {
F_8 ( V_42 L_27 ,
V_81 , V_81 + 4 - 1 ) ;
}
if ( V_103 ) {
error = F_52 ( V_103 , 0 , 1 , & V_92 ) ;
if ( error < 0 )
return error ;
}
}
return F_53 ( V_49 ) ;
}
static int F_54 ( struct V_48 * * V_107 )
{
struct V_48 * V_49 ;
int V_54 ;
V_54 = F_55 ( V_59 , V_80 , V_108 ,
sizeof( struct V_3 ) , & V_49 ) ;
if ( V_54 < 0 )
return V_54 ;
V_49 -> V_109 = F_40 ;
* V_107 = V_49 ;
return 0 ;
}
static int T_1 F_56 ( struct V_110 * V_111 ,
unsigned int V_112 )
{
#ifdef F_7
if ( V_113 )
return 0 ;
if ( V_11 )
return 0 ;
#endif
return 1 ;
}
static int T_1 F_57 ( struct V_110 * V_111 ,
unsigned int V_112 )
{
struct V_48 * V_49 ;
int error ;
static long V_114 [] = { 0x300 , 0x310 , 0x320 , 0x330 , - 1 } ;
#ifdef F_6
static int V_115 [] = { 5 , 9 , 10 , 11 , 7 , - 1 } ;
#else
static int V_115 [] = { 9 , 10 , 11 , 7 , - 1 } ;
#endif
static int V_116 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_117 [] = { 3 , 1 , 0 , - 1 } ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
static int V_118 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } , { 0 , - 1 } } ;
#endif
if ( V_33 == V_93 ) {
if ( ( V_33 = F_1 ( V_114 , 2 ) ) < 0 ) {
F_8 ( V_24 L_28 ) ;
return - V_45 ;
}
}
if ( V_10 == V_119 ) {
if ( ( V_10 = F_58 ( V_115 ) ) < 0 ) {
F_8 ( V_24 L_29 ) ;
return - V_45 ;
}
}
if ( V_34 == V_119 ) {
if ( ( V_34 = F_58 ( V_116 ) ) < 0 ) {
F_8 ( V_24 L_30 ) ;
return - V_45 ;
}
}
if ( V_31 == V_120 ) {
if ( ( V_31 = F_59 ( V_117 ) ) < 0 ) {
F_8 ( V_24 L_31 ) ;
return - V_45 ;
}
}
#if F_19 ( F_18 ) || F_19 ( F_6 )
if ( V_32 == V_120 ) {
if ( ( V_32 = F_59 ( V_118 [ V_31 % 4 ] ) ) < 0 ) {
F_8 ( V_24 L_32 ) ;
return - V_45 ;
}
}
#endif
error = F_54 ( & V_49 ) ;
if ( error < 0 )
return error ;
if ( ( error = F_60 ( V_49 , V_49 -> V_83 ) ) < 0 ) {
F_61 ( V_49 ) ;
return error ;
}
F_62 ( V_49 , V_111 ) ;
if ( ( error = F_43 ( V_49 ) ) < 0 ) {
F_61 ( V_49 ) ;
return error ;
}
F_63 ( V_111 , V_49 ) ;
return 0 ;
}
static int T_3 F_64 ( struct V_110 * V_111 ,
unsigned int V_112 )
{
F_61 ( F_65 ( V_111 ) ) ;
F_63 ( V_111 , NULL ) ;
return 0 ;
}
static int F_66 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_83 ;
F_67 ( V_49 , V_121 ) ;
V_4 -> V_62 -> V_122 ( V_4 -> V_62 ) ;
return 0 ;
}
static int F_68 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = V_49 -> V_83 ;
int error , V_85 ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
V_85 = V_32 ;
#else
V_85 = - 1 ;
#endif
error = F_15 ( V_4 , V_30 , V_10 , V_31 , V_85 ,
V_33 , V_34 ) ;
if ( error )
return error ;
V_4 -> V_62 -> V_123 ( V_4 -> V_62 ) ;
F_67 ( V_49 , V_124 ) ;
return 0 ;
}
static int F_69 ( struct V_110 * V_112 , unsigned int V_125 ,
T_4 V_126 )
{
return F_66 ( F_65 ( V_112 ) ) ;
}
static int F_70 ( struct V_110 * V_112 , unsigned int V_125 )
{
return F_68 ( F_65 ( V_112 ) ) ;
}
static int T_1 F_71 ( struct V_72 * V_127 ,
const struct V_73 * V_74 )
{
struct V_48 * V_49 ;
int error , V_128 ;
struct V_3 * V_4 ;
if ( V_113 )
return - V_45 ;
if ( ! V_11 )
return - V_25 ;
error = F_54 ( & V_49 ) ;
if ( error < 0 )
return error ;
V_4 = V_49 -> V_83 ;
V_128 = F_33 ( V_4 , V_127 , V_74 ) ;
switch ( V_128 ) {
case 0x0924 :
V_128 = V_18 ;
break;
case 0x0925 :
V_128 = V_19 ;
break;
case 0x0931 :
V_128 = V_21 ;
break;
default:
F_61 ( V_49 ) ;
return - V_25 ;
}
if ( ( error = F_4 ( V_4 , V_128 ) ) ) {
F_61 ( V_49 ) ;
return error ;
}
error = F_31 ( V_4 ) ;
if ( error ) {
F_8 ( V_24 L_33 ) ;
F_61 ( V_49 ) ;
return error ;
}
F_62 ( V_49 , & V_127 -> V_49 -> V_112 ) ;
if ( ( error = F_43 ( V_49 ) ) < 0 ) {
F_61 ( V_49 ) ;
return error ;
}
F_72 ( V_127 , V_49 ) ;
V_113 = 1 ;
return 0 ;
}
static void T_3 F_73 ( struct V_72 * V_127 )
{
F_61 ( F_74 ( V_127 ) ) ;
F_72 ( V_127 , NULL ) ;
V_113 = 0 ;
}
static int F_75 ( struct V_72 * V_127 ,
T_4 V_126 )
{
return F_66 ( F_74 ( V_127 ) ) ;
}
static int F_76 ( struct V_72 * V_127 )
{
return F_68 ( F_74 ( V_127 ) ) ;
}
static int T_5 F_77 ( void )
{
#ifdef F_7
F_78 ( & V_129 ) ;
if ( V_113 )
return 0 ;
F_79 ( & V_129 ) ;
#endif
return F_80 ( & V_130 , 1 ) ;
}
static void T_6 F_81 ( void )
{
if ( ! V_113 ) {
F_82 ( & V_130 ) ;
return;
}
#ifdef F_7
F_79 ( & V_129 ) ;
#endif
}
