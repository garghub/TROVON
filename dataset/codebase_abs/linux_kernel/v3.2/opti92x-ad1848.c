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
if ( ! V_4 -> V_23 ) {
V_4 -> V_23 = 0xe0e ;
V_4 -> V_24 = 2 ;
}
V_4 -> V_16 = 0xe4 ;
V_4 -> V_17 = 0 ;
break;
#endif
default:
F_8 ( V_25 L_2 , V_5 ) ;
return - V_26 ;
}
return 0 ;
}
static unsigned char F_9 ( struct V_3 * V_4 ,
unsigned char V_27 )
{
unsigned long V_28 ;
unsigned char V_29 = 0xff ;
F_10 ( & V_4 -> V_9 , V_28 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
switch ( V_4 -> V_5 ) {
#ifndef F_6
case V_18 :
case V_19 :
if ( V_27 > 7 ) {
F_11 ( V_27 , V_4 -> V_12 + 8 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
V_29 = F_12 ( V_4 -> V_12 + 9 ) ;
break;
}
case V_14 :
case V_15 :
V_29 = F_12 ( V_4 -> V_12 + V_27 ) ;
break;
#else
case V_20 :
case V_21 :
case V_22 :
F_11 ( V_27 , V_4 -> V_23 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
V_29 = F_12 ( V_4 -> V_23 + 1 ) ;
break;
#endif
default:
F_8 ( V_25 L_2 , V_4 -> V_5 ) ;
}
F_13 ( & V_4 -> V_9 , V_28 ) ;
return V_29 ;
}
static void F_14 ( struct V_3 * V_4 , unsigned char V_27 ,
unsigned char V_30 )
{
unsigned long V_28 ;
F_10 ( & V_4 -> V_9 , V_28 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
switch ( V_4 -> V_5 ) {
#ifndef F_6
case V_18 :
case V_19 :
if ( V_27 > 7 ) {
F_11 ( V_27 , V_4 -> V_12 + 8 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( V_30 , V_4 -> V_12 + 9 ) ;
break;
}
case V_14 :
case V_15 :
F_11 ( V_30 , V_4 -> V_12 + V_27 ) ;
break;
#else
case V_20 :
case V_21 :
case V_22 :
F_11 ( V_27 , V_4 -> V_23 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( V_30 , V_4 -> V_23 + 1 ) ;
break;
#endif
default:
F_8 ( V_25 L_2 , V_4 -> V_5 ) ;
}
F_13 ( & V_4 -> V_9 , V_28 ) ;
}
static int T_1 F_15 ( struct V_3 * V_4 ,
long V_31 ,
int V_10 , int V_32 , int V_33 ,
long V_34 , int V_35 )
{
unsigned char V_36 ;
unsigned char V_37 ;
unsigned char V_38 ;
unsigned char V_39 = 0 ;
unsigned char V_40 ;
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
F_8 ( V_25 L_2 , V_4 -> V_5 ) ;
return - V_41 ;
}
switch ( V_31 & 0x3ff ) {
case 0x130 :
V_4 -> V_42 = 0x530 ;
V_36 = 0x00 ;
break;
case 0x204 :
V_4 -> V_42 = 0x604 ;
V_36 = 0x03 ;
break;
case 0x280 :
V_4 -> V_42 = 0xe80 ;
V_36 = 0x01 ;
break;
case 0x340 :
V_4 -> V_42 = 0xf40 ;
V_36 = 0x02 ;
break;
default:
F_8 ( V_43 L_3 , V_31 ) ;
goto V_44;
}
F_16 ( V_4 , F_17 ( 1 ) , V_36 << 4 , 0x30 ) ;
V_44:
switch ( V_10 ) {
case 5 :
V_37 = 0x05 ;
break;
case 7 :
V_37 = 0x01 ;
break;
case 9 :
V_37 = 0x02 ;
break;
case 10 :
V_37 = 0x03 ;
break;
case 11 :
V_37 = 0x04 ;
break;
default:
F_8 ( V_43 L_4 , V_10 ) ;
goto V_45;
}
switch ( V_32 ) {
case 0 :
V_38 = 0x01 ;
break;
case 1 :
V_38 = 0x02 ;
break;
case 3 :
V_38 = 0x03 ;
break;
default:
F_8 ( V_43 L_5 , V_32 ) ;
goto V_45;
}
#if F_19 ( F_18 ) || F_19 ( F_6 )
if ( V_32 == V_33 ) {
F_8 ( V_25 L_6 ) ;
return - V_46 ;
}
switch ( V_33 ) {
case 0 :
case 1 :
break;
default:
F_8 ( V_43 L_7 , V_33 ) ;
goto V_45;
}
V_38 |= 0x04 ;
#endif
#ifndef F_6
F_11 ( V_37 << 3 | V_38 , V_4 -> V_42 ) ;
#else
F_14 ( V_4 , F_17 ( 3 ) , ( V_37 << 3 | V_38 ) ) ;
#endif
V_45:
if ( V_4 -> V_5 > V_14 ) {
switch ( V_34 ) {
case 0 :
case - 1 :
break;
case 0x300 :
V_39 = 0x03 ;
break;
case 0x310 :
V_39 = 0x02 ;
break;
case 0x320 :
V_39 = 0x01 ;
break;
case 0x330 :
V_39 = 0x00 ;
break;
default:
F_8 ( V_43
L_8 , V_34 ) ;
goto V_47;
}
switch ( V_35 ) {
case 5 :
V_40 = 0x02 ;
break;
case 7 :
V_40 = 0x03 ;
break;
case 9 :
V_40 = 0x00 ;
break;
case 10 :
V_40 = 0x01 ;
break;
default:
F_8 ( V_43 L_9 ,
V_35 ) ;
goto V_47;
}
F_16 ( V_4 , F_17 ( 6 ) ,
( V_34 <= 0 ) ? 0x00 :
0x80 | V_39 << 5 | V_40 << 3 ,
0xf8 ) ;
}
V_47:
return 0 ;
}
static int T_1 F_20 ( struct V_48 * V_4 )
{
struct V_49 * V_50 ;
unsigned int V_51 ;
struct V_52 V_53 , V_54 ;
int V_55 ;
if ( F_21 ( ! V_4 || ! V_4 -> V_56 ) )
return - V_41 ;
V_50 = V_4 -> V_50 ;
strcpy ( V_50 -> V_57 , V_4 -> V_56 -> V_7 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_53 . V_58 = V_54 . V_58 = V_59 ;
strcpy ( V_53 . V_7 , L_10 ) ;
strcpy ( V_54 . V_7 , L_11 ) ;
V_55 = F_22 ( V_50 , & V_53 , & V_54 ) ;
if ( V_55 < 0 ) {
F_8 ( V_25 L_12 ) ;
return V_55 ;
}
strcpy ( V_53 . V_7 , L_10 ) ; V_53 . V_60 = 1 ;
strcpy ( V_54 . V_7 , L_13 ) ;
V_55 = F_22 ( V_50 , & V_53 , & V_54 ) ;
if ( V_55 < 0 ) {
F_8 ( V_25 L_12 ) ;
return V_55 ;
}
strcpy ( V_53 . V_7 , L_14 ) ; V_53 . V_60 = 1 ;
F_23 ( V_50 , & V_53 ) ;
V_53 . V_60 = 0 ;
for ( V_51 = 0 ; V_51 < F_24 ( V_61 ) ; V_51 ++ ) {
strcpy ( V_53 . V_7 , V_61 [ V_51 ] . V_7 ) ;
F_23 ( V_50 , & V_53 ) ;
V_55 = F_25 ( V_50 ,
F_26 ( & V_61 [ V_51 ] , V_4 ) ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static T_2 F_27 ( int V_10 , void * V_62 )
{
struct V_3 * V_4 = V_62 ;
struct V_48 * V_63 = V_4 -> V_63 ;
unsigned char V_64 ;
if ( ! V_63 )
return V_65 ;
V_64 = F_9 ( V_4 , F_17 ( 11 ) ) ;
if ( ( V_64 & V_66 ) && V_63 -> V_67 )
F_28 ( V_63 -> V_67 ) ;
if ( ( V_64 & V_68 ) && V_63 -> V_69 ) {
F_29 ( V_63 ) ;
F_28 ( V_63 -> V_69 ) ;
}
F_11 ( 0x00 , F_30 ( V_63 , V_70 ) ) ;
return V_65 ;
}
static int T_1 F_31 ( struct V_3 * V_4 )
{
unsigned char V_30 ;
#ifdef F_6
unsigned long V_28 ;
#endif
V_4 -> V_71 = F_2 ( V_4 -> V_12 , V_4 -> V_13 ,
L_15 ) ;
if ( V_4 -> V_71 == NULL )
return - V_46 ;
#ifndef F_6
V_30 = F_9 ( V_4 , F_17 ( 1 ) ) ;
if ( V_30 != 0xff && V_30 != F_12 ( V_4 -> V_12 + F_17 ( 1 ) ) )
if ( V_30 == F_9 ( V_4 , F_17 ( 1 ) ) )
return 0 ;
#else
V_4 -> V_72 = F_2 ( V_4 -> V_23 ,
V_4 -> V_24 ,
L_16 ) ;
if ( V_4 -> V_72 == NULL )
return - V_46 ;
F_10 ( & V_4 -> V_9 , V_28 ) ;
F_11 ( V_4 -> V_16 , V_4 -> V_12 + V_4 -> V_17 ) ;
F_11 ( ( ( V_4 -> V_23 & 0x1f0 ) >> 4 ) , V_4 -> V_12 ) ;
F_13 ( & V_4 -> V_9 , V_28 ) ;
V_30 = F_9 ( V_4 , F_17 ( 7 ) ) ;
F_14 ( V_4 , F_17 ( 7 ) , 0xff - V_30 ) ;
if ( F_9 ( V_4 , F_17 ( 7 ) ) == 0xff - V_30 )
return 0 ;
F_32 ( V_4 -> V_72 ) ;
V_4 -> V_72 = NULL ;
#endif
F_32 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
return - V_26 ;
}
static int T_1 F_33 ( struct V_3 * V_4 ,
struct V_73 * V_50 ,
const struct V_74 * V_75 )
{
struct V_76 * V_77 ;
int V_55 ;
struct V_76 * V_78 ;
#ifndef F_6
struct V_76 * V_79 ;
#endif
V_77 = F_34 ( V_50 , V_75 -> V_80 [ 0 ] . V_81 , NULL ) ;
if ( V_77 == NULL )
return - V_46 ;
V_55 = F_35 ( V_77 ) ;
if ( V_55 < 0 ) {
F_8 ( V_25 L_17 , V_55 ) ;
return V_55 ;
}
#ifdef F_6
V_31 = F_36 ( V_77 , 0 ) - 4 ;
V_82 = F_36 ( V_77 , 1 ) + 8 ;
V_4 -> V_23 = F_36 ( V_77 , 3 ) + 2 ;
V_4 -> V_24 = F_37 ( V_77 , 3 ) - 2 ;
#else
V_79 = F_34 ( V_50 , V_75 -> V_80 [ 2 ] . V_81 , NULL ) ;
if ( V_79 == NULL )
return - V_46 ;
V_55 = F_35 ( V_79 ) ;
if ( V_55 < 0 ) {
F_8 ( V_25 L_18 , V_55 ) ;
return V_55 ;
}
V_31 = F_36 ( V_77 , 1 ) ;
V_82 = F_36 ( V_77 , 2 ) + 8 ;
V_4 -> V_12 = F_36 ( V_79 , 0 ) - 1 ;
V_4 -> V_13 = F_37 ( V_79 , 0 ) + 1 ;
#endif
V_10 = F_38 ( V_77 , 0 ) ;
V_32 = F_39 ( V_77 , 0 ) ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
V_33 = F_39 ( V_77 , 1 ) ;
#endif
V_78 = F_34 ( V_50 , V_75 -> V_80 [ 1 ] . V_81 , NULL ) ;
if ( V_78 && V_34 > 0 ) {
V_55 = F_35 ( V_78 ) ;
if ( V_55 < 0 ) {
F_8 ( V_25 L_19 ) ;
V_34 = - 1 ;
} else {
V_34 = F_36 ( V_78 , 0 ) ;
V_35 = F_38 ( V_78 , 0 ) ;
}
}
return V_75 -> V_83 ;
}
static void F_40 ( struct V_49 * V_50 )
{
struct V_3 * V_4 = V_50 -> V_84 ;
if ( V_4 ) {
#ifdef F_6
if ( V_4 -> V_10 > 0 ) {
F_41 ( V_4 -> V_10 ) ;
F_42 ( V_4 -> V_10 , V_4 ) ;
}
F_32 ( V_4 -> V_72 ) ;
#endif
F_32 ( V_4 -> V_71 ) ;
}
}
static int T_1 F_43 ( struct V_49 * V_50 )
{
static long V_85 [] = { 0x530 , 0xe80 , 0xf40 , 0x604 , - 1 } ;
int error ;
int V_86 ;
struct V_3 * V_4 = V_50 -> V_84 ;
struct V_48 * V_63 ;
#ifdef F_18
struct V_87 * V_88 ;
#endif
struct V_89 * V_56 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
V_86 = V_33 ;
#else
V_86 = - 1 ;
#endif
if ( V_31 == V_94 ) {
V_31 = F_1 ( V_85 , 4 ) ;
if ( V_31 < 0 ) {
F_8 ( V_25 L_20 ) ;
return - V_46 ;
}
}
error = F_15 ( V_4 , V_31 , V_10 , V_32 , V_86 ,
V_34 , V_35 ) ;
if ( error )
return error ;
error = F_44 ( V_50 , V_4 -> V_42 + 4 , - 1 , V_10 , V_32 , V_86 ,
#ifdef F_6
V_95 , V_96 ,
#else
V_97 , 0 ,
#endif
& V_63 ) ;
if ( error < 0 )
return error ;
#ifdef F_6
V_4 -> V_63 = V_63 ;
#endif
error = F_45 ( V_63 , 0 , & V_56 ) ;
if ( error < 0 )
return error ;
error = F_46 ( V_63 ) ;
if ( error < 0 )
return error ;
#ifdef F_6
error = F_20 ( V_63 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_18
error = F_47 ( V_63 , 0 , & V_88 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_6
error = F_48 ( V_10 , F_27 ,
0 , V_98 L_21 , V_4 ) ;
if ( error < 0 ) {
F_8 ( V_25 L_22 , V_10 ) ;
return error ;
}
#endif
V_4 -> V_10 = V_10 ;
strcpy ( V_50 -> V_99 , V_4 -> V_7 ) ;
sprintf ( V_50 -> V_100 , L_23 , V_50 -> V_99 ) ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
sprintf ( V_50 -> V_101 , L_24 ,
V_50 -> V_100 , V_56 -> V_7 ,
V_4 -> V_42 + 4 , V_10 , V_32 , V_86 ) ;
#else
sprintf ( V_50 -> V_101 , L_25 ,
V_50 -> V_100 , V_56 -> V_7 , V_4 -> V_42 + 4 , V_10 , V_32 ) ;
#endif
if ( V_34 <= 0 || V_34 == V_94 )
V_91 = NULL ;
else {
error = F_49 ( V_50 , 0 , V_102 ,
V_34 , 0 , V_35 , & V_91 ) ;
if ( error )
F_8 ( V_43 L_26 ,
V_34 ) ;
}
if ( V_82 > 0 && V_82 != V_94 ) {
struct V_103 * V_104 = NULL ;
#ifndef F_6
if ( V_4 -> V_5 == V_14 ||
V_4 -> V_5 == V_15 ||
V_4 -> V_5 == V_18 ) {
struct V_105 * V_106 ;
F_16 ( V_4 , F_17 ( 2 ) ,
0x20 , 0x20 ) ;
if ( F_50 ( V_50 , V_82 , V_82 - 8 ,
2 , & V_104 , & V_106 ) < 0 ) {
F_16 ( V_4 , F_17 ( 2 ) ,
0x00 , 0x20 ) ;
}
}
#endif
if ( ! V_104 && F_51 ( V_50 , V_82 , V_82 + 2 ,
V_107 , 0 , & V_104 ) < 0 ) {
F_8 ( V_43 L_27 ,
V_82 , V_82 + 4 - 1 ) ;
}
if ( V_104 ) {
error = F_52 ( V_104 , 0 , 1 , & V_93 ) ;
if ( error < 0 )
return error ;
}
}
return F_53 ( V_50 ) ;
}
static int F_54 ( struct V_49 * * V_108 )
{
struct V_49 * V_50 ;
int V_55 ;
V_55 = F_55 ( V_60 , V_81 , V_109 ,
sizeof( struct V_3 ) , & V_50 ) ;
if ( V_55 < 0 )
return V_55 ;
V_50 -> V_110 = F_40 ;
* V_108 = V_50 ;
return 0 ;
}
static int T_1 F_56 ( struct V_111 * V_112 ,
unsigned int V_113 )
{
#ifdef F_7
if ( V_114 )
return 0 ;
if ( V_11 )
return 0 ;
#endif
return 1 ;
}
static int T_1 F_57 ( struct V_111 * V_112 ,
unsigned int V_113 )
{
struct V_49 * V_50 ;
int error ;
static long V_115 [] = { 0x300 , 0x310 , 0x320 , 0x330 , - 1 } ;
#ifdef F_6
static int V_116 [] = { 5 , 9 , 10 , 11 , 7 , - 1 } ;
#else
static int V_116 [] = { 9 , 10 , 11 , 7 , - 1 } ;
#endif
static int V_117 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_118 [] = { 3 , 1 , 0 , - 1 } ;
#if F_19 ( F_18 ) || F_19 ( F_6 )
static int V_119 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } , { 0 , - 1 } } ;
#endif
if ( V_34 == V_94 ) {
if ( ( V_34 = F_1 ( V_115 , 2 ) ) < 0 ) {
F_8 ( V_25 L_28 ) ;
return - V_46 ;
}
}
if ( V_10 == V_120 ) {
if ( ( V_10 = F_58 ( V_116 ) ) < 0 ) {
F_8 ( V_25 L_29 ) ;
return - V_46 ;
}
}
if ( V_35 == V_120 ) {
if ( ( V_35 = F_58 ( V_117 ) ) < 0 ) {
F_8 ( V_25 L_30 ) ;
return - V_46 ;
}
}
if ( V_32 == V_121 ) {
if ( ( V_32 = F_59 ( V_118 ) ) < 0 ) {
F_8 ( V_25 L_31 ) ;
return - V_46 ;
}
}
#if F_19 ( F_18 ) || F_19 ( F_6 )
if ( V_33 == V_121 ) {
if ( ( V_33 = F_59 ( V_119 [ V_32 % 4 ] ) ) < 0 ) {
F_8 ( V_25 L_32 ) ;
return - V_46 ;
}
}
#endif
error = F_54 ( & V_50 ) ;
if ( error < 0 )
return error ;
if ( ( error = F_60 ( V_50 , V_50 -> V_84 ) ) < 0 ) {
F_61 ( V_50 ) ;
return error ;
}
F_62 ( V_50 , V_112 ) ;
if ( ( error = F_43 ( V_50 ) ) < 0 ) {
F_61 ( V_50 ) ;
return error ;
}
F_63 ( V_112 , V_50 ) ;
return 0 ;
}
static int T_3 F_64 ( struct V_111 * V_112 ,
unsigned int V_113 )
{
F_61 ( F_65 ( V_112 ) ) ;
F_63 ( V_112 , NULL ) ;
return 0 ;
}
static int T_1 F_66 ( struct V_73 * V_122 ,
const struct V_74 * V_75 )
{
struct V_49 * V_50 ;
int error , V_123 ;
struct V_3 * V_4 ;
if ( V_114 )
return - V_46 ;
if ( ! V_11 )
return - V_26 ;
error = F_54 ( & V_50 ) ;
if ( error < 0 )
return error ;
V_4 = V_50 -> V_84 ;
V_123 = F_33 ( V_4 , V_122 , V_75 ) ;
switch ( V_123 ) {
case 0x0924 :
V_123 = V_18 ;
break;
case 0x0925 :
V_123 = V_19 ;
break;
case 0x0931 :
V_123 = V_21 ;
break;
default:
F_61 ( V_50 ) ;
return - V_26 ;
}
if ( ( error = F_4 ( V_4 , V_123 ) ) ) {
F_61 ( V_50 ) ;
return error ;
}
error = F_31 ( V_4 ) ;
if ( error ) {
F_8 ( V_25 L_33 ) ;
F_61 ( V_50 ) ;
return error ;
}
F_62 ( V_50 , & V_122 -> V_50 -> V_113 ) ;
if ( ( error = F_43 ( V_50 ) ) < 0 ) {
F_61 ( V_50 ) ;
return error ;
}
F_67 ( V_122 , V_50 ) ;
V_114 = 1 ;
return 0 ;
}
static void T_3 F_68 ( struct V_73 * V_122 )
{
F_61 ( F_69 ( V_122 ) ) ;
F_67 ( V_122 , NULL ) ;
V_114 = 0 ;
}
static int T_4 F_70 ( void )
{
#ifdef F_7
F_71 ( & V_124 ) ;
if ( V_114 )
return 0 ;
F_72 ( & V_124 ) ;
#endif
return F_73 ( & V_125 , 1 ) ;
}
static void T_5 F_74 ( void )
{
if ( ! V_114 ) {
F_75 ( & V_125 ) ;
return;
}
#ifdef F_7
F_72 ( & V_124 ) ;
#endif
}
