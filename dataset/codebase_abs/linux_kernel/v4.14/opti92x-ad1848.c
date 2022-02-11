static int F_1 ( struct V_1 * V_2 ,
unsigned short V_3 )
{
static int V_4 [] = { 7 , 7 , 10 , 10 , 2 , 2 , 2 } ;
V_2 -> V_3 = V_3 ;
strcpy ( V_2 -> V_5 , V_6 [ V_3 ] ) ;
F_2 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = - 1 ;
#ifndef F_3
#ifdef F_4
if ( V_9 && V_2 -> V_10 )
V_2 -> V_10 |= 0xc00 ;
else
#endif
{
V_2 -> V_10 = 0xf8c ;
V_2 -> V_11 = V_4 [ V_3 ] ;
}
#else
V_2 -> V_11 = V_4 [ V_3 ] ;
#endif
switch ( V_3 ) {
#ifndef F_3
case V_12 :
case V_13 :
V_2 -> V_14 = ( V_3 == V_12 ) ? 0xe2 : 0xe3 ;
V_2 -> V_15 = 3 ;
break;
case V_16 :
case V_17 :
V_2 -> V_14 = 0xe5 ;
V_2 -> V_15 = 3 ;
break;
#else
case V_18 :
case V_19 :
case V_20 :
V_2 -> V_10 = ( V_3 == V_18 ) ? 0xf8f : 0xf8d ;
if ( ! V_2 -> V_21 )
V_2 -> V_21 = 0xe0e ;
V_2 -> V_14 = 0xe4 ;
V_2 -> V_15 = 0 ;
break;
#endif
default:
F_5 ( V_22 L_1 , V_3 ) ;
return - V_23 ;
}
return 0 ;
}
static unsigned char F_6 ( struct V_1 * V_2 ,
unsigned char V_24 )
{
unsigned long V_25 ;
unsigned char V_26 = 0xff ;
F_7 ( & V_2 -> V_7 , V_25 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
switch ( V_2 -> V_3 ) {
#ifndef F_3
case V_16 :
case V_17 :
if ( V_24 > 7 ) {
F_8 ( V_24 , V_2 -> V_10 + 8 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
V_26 = F_9 ( V_2 -> V_10 + 9 ) ;
break;
}
case V_12 :
case V_13 :
V_26 = F_9 ( V_2 -> V_10 + V_24 ) ;
break;
#else
case V_18 :
case V_19 :
case V_20 :
F_8 ( V_24 , V_2 -> V_21 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
V_26 = F_9 ( V_2 -> V_21 + 1 ) ;
break;
#endif
default:
F_5 ( V_22 L_1 , V_2 -> V_3 ) ;
}
F_10 ( & V_2 -> V_7 , V_25 ) ;
return V_26 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char V_24 ,
unsigned char V_27 )
{
unsigned long V_25 ;
F_7 ( & V_2 -> V_7 , V_25 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
switch ( V_2 -> V_3 ) {
#ifndef F_3
case V_16 :
case V_17 :
if ( V_24 > 7 ) {
F_8 ( V_24 , V_2 -> V_10 + 8 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
F_8 ( V_27 , V_2 -> V_10 + 9 ) ;
break;
}
case V_12 :
case V_13 :
F_8 ( V_27 , V_2 -> V_10 + V_24 ) ;
break;
#else
case V_18 :
case V_19 :
case V_20 :
F_8 ( V_24 , V_2 -> V_21 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
F_8 ( V_27 , V_2 -> V_21 + 1 ) ;
break;
#endif
default:
F_5 ( V_22 L_1 , V_2 -> V_3 ) ;
}
F_10 ( & V_2 -> V_7 , V_25 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
long V_28 ,
int V_8 , int V_29 , int V_30 ,
long V_31 , int V_32 )
{
unsigned char V_33 ;
unsigned char V_34 ;
unsigned char V_35 ;
unsigned char V_36 = 0 ;
unsigned char V_37 ;
switch ( V_2 -> V_3 ) {
#ifndef F_3
case V_16 :
F_13 ( V_2 , F_14 ( 4 ) , 0xf0 , 0xfc ) ;
F_13 ( V_2 , F_14 ( 6 ) , 0x02 , 0x02 ) ;
case V_17 :
F_13 ( V_2 , F_14 ( 1 ) , 0x80 , 0x80 ) ;
F_13 ( V_2 , F_14 ( 2 ) , 0x00 , 0x20 ) ;
F_13 ( V_2 , F_14 ( 3 ) , 0xf0 , 0xff ) ;
#ifdef F_15
F_13 ( V_2 , F_14 ( 5 ) , 0x02 , 0x02 ) ;
#else
F_13 ( V_2 , F_14 ( 5 ) , 0x00 , 0x02 ) ;
#endif
break;
case V_12 :
case V_13 :
F_13 ( V_2 , F_14 ( 1 ) , 0x80 , 0x80 ) ;
F_13 ( V_2 , F_14 ( 2 ) , 0x00 , 0x20 ) ;
F_13 ( V_2 , F_14 ( 4 ) , 0x00 , 0x0c ) ;
#ifdef F_15
F_13 ( V_2 , F_14 ( 5 ) , 0x02 , 0x02 ) ;
#else
F_13 ( V_2 , F_14 ( 5 ) , 0x00 , 0x02 ) ;
#endif
break;
#else
case V_19 :
F_13 ( V_2 , F_14 ( 20 ) , 0x04 , 0x0c ) ;
case V_20 :
F_13 ( V_2 , F_14 ( 21 ) , 0x82 , 0xff ) ;
F_13 ( V_2 , F_14 ( 26 ) , 0x01 , 0x01 ) ;
case V_18 :
F_13 ( V_2 , F_14 ( 6 ) , 0x02 , 0x03 ) ;
F_13 ( V_2 , F_14 ( 3 ) , 0x00 , 0xff ) ;
F_13 ( V_2 , F_14 ( 4 ) , 0x10 |
( V_2 -> V_3 == V_18 ? 0x00 : 0x04 ) ,
0x34 ) ;
F_13 ( V_2 , F_14 ( 5 ) , 0x20 , 0xbf ) ;
break;
#endif
default:
F_5 ( V_22 L_1 , V_2 -> V_3 ) ;
return - V_38 ;
}
switch ( V_28 & 0x3ff ) {
case 0x130 :
V_2 -> V_39 = 0x530 ;
V_33 = 0x00 ;
break;
case 0x204 :
V_2 -> V_39 = 0x604 ;
V_33 = 0x03 ;
break;
case 0x280 :
V_2 -> V_39 = 0xe80 ;
V_33 = 0x01 ;
break;
case 0x340 :
V_2 -> V_39 = 0xf40 ;
V_33 = 0x02 ;
break;
default:
F_5 ( V_40 L_2 , V_28 ) ;
goto V_41;
}
F_13 ( V_2 , F_14 ( 1 ) , V_33 << 4 , 0x30 ) ;
V_41:
switch ( V_8 ) {
case 5 :
V_34 = 0x05 ;
break;
case 7 :
V_34 = 0x01 ;
break;
case 9 :
V_34 = 0x02 ;
break;
case 10 :
V_34 = 0x03 ;
break;
case 11 :
V_34 = 0x04 ;
break;
default:
F_5 ( V_40 L_3 , V_8 ) ;
goto V_42;
}
switch ( V_29 ) {
case 0 :
V_35 = 0x01 ;
break;
case 1 :
V_35 = 0x02 ;
break;
case 3 :
V_35 = 0x03 ;
break;
default:
F_5 ( V_40 L_4 , V_29 ) ;
goto V_42;
}
#if F_16 ( F_15 ) || F_16 ( F_3 )
if ( V_29 == V_30 ) {
F_5 ( V_22 L_5 ) ;
return - V_43 ;
}
switch ( V_30 ) {
case 0 :
case 1 :
break;
default:
F_5 ( V_40 L_6 , V_30 ) ;
goto V_42;
}
V_35 |= 0x04 ;
#endif
#ifndef F_3
F_8 ( V_34 << 3 | V_35 , V_2 -> V_39 ) ;
#else
F_11 ( V_2 , F_14 ( 3 ) , ( V_34 << 3 | V_35 ) ) ;
#endif
V_42:
if ( V_2 -> V_3 > V_12 ) {
switch ( V_31 ) {
case 0 :
case - 1 :
break;
case 0x300 :
V_36 = 0x03 ;
break;
case 0x310 :
V_36 = 0x02 ;
break;
case 0x320 :
V_36 = 0x01 ;
break;
case 0x330 :
V_36 = 0x00 ;
break;
default:
F_5 ( V_40
L_7 , V_31 ) ;
goto V_44;
}
switch ( V_32 ) {
case 5 :
V_37 = 0x02 ;
break;
case 7 :
V_37 = 0x03 ;
break;
case 9 :
V_37 = 0x00 ;
break;
case 10 :
V_37 = 0x01 ;
break;
default:
F_5 ( V_40 L_8 ,
V_32 ) ;
goto V_44;
}
F_13 ( V_2 , F_14 ( 6 ) ,
( V_31 <= 0 ) ? 0x00 :
0x80 | V_36 << 5 | V_37 << 3 ,
0xf8 ) ;
}
V_44:
return 0 ;
}
static int F_17 ( struct V_45 * V_2 )
{
struct V_46 * V_47 ;
unsigned int V_48 ;
struct V_49 V_50 , V_51 ;
int V_52 ;
if ( F_18 ( ! V_2 || ! V_2 -> V_53 ) )
return - V_38 ;
V_47 = V_2 -> V_47 ;
strcpy ( V_47 -> V_54 , V_2 -> V_53 -> V_5 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_50 . V_55 = V_51 . V_55 = V_56 ;
strcpy ( V_50 . V_5 , L_9 ) ;
strcpy ( V_51 . V_5 , L_10 ) ;
V_52 = F_19 ( V_47 , & V_50 , & V_51 ) ;
if ( V_52 < 0 ) {
F_5 ( V_22 L_11 ) ;
return V_52 ;
}
strcpy ( V_50 . V_5 , L_9 ) ; V_50 . V_57 = 1 ;
strcpy ( V_51 . V_5 , L_12 ) ;
V_52 = F_19 ( V_47 , & V_50 , & V_51 ) ;
if ( V_52 < 0 ) {
F_5 ( V_22 L_11 ) ;
return V_52 ;
}
strcpy ( V_50 . V_5 , L_13 ) ; V_50 . V_57 = 1 ;
F_20 ( V_47 , & V_50 ) ;
V_50 . V_57 = 0 ;
for ( V_48 = 0 ; V_48 < F_21 ( V_58 ) ; V_48 ++ ) {
strcpy ( V_50 . V_5 , V_58 [ V_48 ] . V_5 ) ;
F_20 ( V_47 , & V_50 ) ;
V_52 = F_22 ( V_47 ,
F_23 ( & V_58 [ V_48 ] , V_2 ) ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static T_1 F_24 ( int V_8 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_45 * V_60 = V_2 -> V_60 ;
unsigned char V_61 ;
if ( ! V_60 )
return V_62 ;
V_61 = F_6 ( V_2 , F_14 ( 11 ) ) ;
if ( ( V_61 & V_63 ) && V_60 -> V_64 )
F_25 ( V_60 -> V_64 ) ;
if ( ( V_61 & V_65 ) && V_60 -> V_66 ) {
F_26 ( V_60 ) ;
F_25 ( V_60 -> V_66 ) ;
}
F_8 ( 0x00 , F_27 ( V_60 , V_67 ) ) ;
return V_62 ;
}
static int F_28 ( struct V_1 * V_2 )
{
unsigned char V_27 ;
#ifdef F_3
unsigned long V_25 ;
#endif
V_2 -> V_68 = F_29 ( V_2 -> V_10 , V_2 -> V_11 ,
L_14 ) ;
if ( V_2 -> V_68 == NULL )
return - V_43 ;
#ifndef F_3
V_27 = F_6 ( V_2 , F_14 ( 1 ) ) ;
if ( V_27 != 0xff && V_27 != F_9 ( V_2 -> V_10 + F_14 ( 1 ) ) )
if ( V_27 == F_6 ( V_2 , F_14 ( 1 ) ) )
return 0 ;
#else
V_2 -> V_69 = F_29 ( V_2 -> V_21 , 2 ,
L_15 ) ;
if ( V_2 -> V_69 == NULL )
return - V_43 ;
F_7 ( & V_2 -> V_7 , V_25 ) ;
F_8 ( V_2 -> V_14 , V_2 -> V_10 + V_2 -> V_15 ) ;
F_8 ( ( ( V_2 -> V_21 & 0x1f0 ) >> 4 ) , V_2 -> V_10 ) ;
F_10 ( & V_2 -> V_7 , V_25 ) ;
V_27 = F_6 ( V_2 , F_14 ( 7 ) ) ;
F_11 ( V_2 , F_14 ( 7 ) , 0xff - V_27 ) ;
if ( F_6 ( V_2 , F_14 ( 7 ) ) == 0xff - V_27 )
return 0 ;
F_30 ( V_2 -> V_69 ) ;
V_2 -> V_69 = NULL ;
#endif
F_30 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
return - V_23 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_70 * V_47 ,
const struct V_71 * V_72 )
{
struct V_73 * V_74 ;
int V_52 ;
struct V_73 * V_75 ;
#ifndef F_3
struct V_73 * V_76 ;
#endif
V_74 = F_32 ( V_47 , V_72 -> V_77 [ 0 ] . V_78 , NULL ) ;
if ( V_74 == NULL )
return - V_43 ;
V_52 = F_33 ( V_74 ) ;
if ( V_52 < 0 ) {
F_5 ( V_22 L_16 , V_52 ) ;
return V_52 ;
}
#ifdef F_3
V_28 = F_34 ( V_74 , 0 ) - 4 ;
V_79 = F_34 ( V_74 , 1 ) + 8 ;
V_2 -> V_21 = ( F_34 ( V_74 , 3 ) & ~ 0xf ) | 0xe ;
#else
V_76 = F_32 ( V_47 , V_72 -> V_77 [ 2 ] . V_78 , NULL ) ;
if ( V_76 == NULL )
return - V_43 ;
V_52 = F_33 ( V_76 ) ;
if ( V_52 < 0 ) {
F_5 ( V_22 L_17 , V_52 ) ;
return V_52 ;
}
V_28 = F_34 ( V_74 , 1 ) ;
V_79 = F_34 ( V_74 , 2 ) + 8 ;
V_2 -> V_10 = F_34 ( V_76 , 0 ) - 1 ;
V_2 -> V_11 = F_35 ( V_76 , 0 ) + 1 ;
#endif
V_8 = F_36 ( V_74 , 0 ) ;
V_29 = F_37 ( V_74 , 0 ) ;
#if F_16 ( F_15 ) || F_16 ( F_3 )
V_30 = F_37 ( V_74 , 1 ) ;
#endif
V_75 = F_32 ( V_47 , V_72 -> V_77 [ 1 ] . V_78 , NULL ) ;
if ( V_75 && V_31 > 0 ) {
V_52 = F_33 ( V_75 ) ;
if ( V_52 < 0 ) {
F_5 ( V_22 L_18 ) ;
V_31 = - 1 ;
} else {
V_31 = F_34 ( V_75 , 0 ) ;
V_32 = F_36 ( V_75 , 0 ) ;
}
}
return V_72 -> V_80 ;
}
static void F_38 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_81 ;
if ( V_2 ) {
#ifdef F_3
if ( V_2 -> V_8 > 0 ) {
F_39 ( V_2 -> V_8 ) ;
F_40 ( V_2 -> V_8 , V_2 ) ;
}
F_30 ( V_2 -> V_69 ) ;
#endif
F_30 ( V_2 -> V_68 ) ;
}
}
static int F_41 ( struct V_46 * V_47 )
{
static long V_82 [] = { 0x530 , 0xe80 , 0xf40 , 0x604 , - 1 } ;
int error ;
int V_83 ;
struct V_1 * V_2 = V_47 -> V_81 ;
struct V_45 * V_60 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
#if F_16 ( F_15 ) || F_16 ( F_3 )
V_83 = V_30 ;
#else
V_83 = - 1 ;
#endif
if ( V_28 == V_88 ) {
V_28 = F_42 ( V_82 , 4 ) ;
if ( V_28 < 0 ) {
F_5 ( V_22 L_19 ) ;
return - V_43 ;
}
}
error = F_12 ( V_2 , V_28 , V_8 , V_29 , V_83 ,
V_31 , V_32 ) ;
if ( error )
return error ;
error = F_43 ( V_47 , V_2 -> V_39 + 4 , - 1 , V_8 , V_29 , V_83 ,
#ifdef F_3
V_89 , V_90 ,
#else
V_91 , 0 ,
#endif
& V_60 ) ;
if ( error < 0 )
return error ;
V_2 -> V_60 = V_60 ;
error = F_44 ( V_60 , 0 ) ;
if ( error < 0 )
return error ;
error = F_45 ( V_60 ) ;
if ( error < 0 )
return error ;
#ifdef F_3
error = F_17 ( V_60 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_15
error = F_46 ( V_60 , 0 ) ;
if ( error < 0 )
return error ;
#endif
#ifdef F_3
error = F_47 ( V_8 , F_24 ,
0 , V_92 L_20 , V_2 ) ;
if ( error < 0 ) {
F_5 ( V_22 L_21 , V_8 ) ;
return error ;
}
#endif
V_2 -> V_8 = V_8 ;
strcpy ( V_47 -> V_93 , V_2 -> V_5 ) ;
sprintf ( V_47 -> V_94 , L_22 , V_47 -> V_93 ) ;
#if F_16 ( F_15 ) || F_16 ( F_3 )
snprintf ( V_47 -> V_95 , sizeof( V_47 -> V_95 ) ,
L_23 ,
V_47 -> V_94 , V_60 -> V_53 -> V_5 ,
V_2 -> V_39 + 4 , V_8 , V_29 , V_83 ) ;
#else
snprintf ( V_47 -> V_95 , sizeof( V_47 -> V_95 ) ,
L_24 ,
V_47 -> V_94 , V_60 -> V_53 -> V_5 , V_2 -> V_39 + 4 , V_8 ,
V_29 ) ;
#endif
if ( V_31 <= 0 || V_31 == V_88 )
V_85 = NULL ;
else {
error = F_48 ( V_47 , 0 , V_96 ,
V_31 , 0 , V_32 , & V_85 ) ;
if ( error )
F_5 ( V_40 L_25 ,
V_31 ) ;
}
if ( V_79 > 0 && V_79 != V_88 ) {
struct V_97 * V_98 = NULL ;
#ifndef F_3
if ( V_2 -> V_3 == V_12 ||
V_2 -> V_3 == V_13 ||
V_2 -> V_3 == V_16 ) {
struct V_99 * V_100 ;
F_13 ( V_2 , F_14 ( 2 ) ,
0x20 , 0x20 ) ;
if ( F_49 ( V_47 , V_79 , V_79 - 8 ,
2 , & V_98 , & V_100 ) < 0 ) {
F_13 ( V_2 , F_14 ( 2 ) ,
0x00 , 0x20 ) ;
}
}
#endif
if ( ! V_98 && F_50 ( V_47 , V_79 , V_79 + 2 ,
V_101 , 0 , & V_98 ) < 0 ) {
F_5 ( V_40 L_26 ,
V_79 , V_79 + 4 - 1 ) ;
}
if ( V_98 ) {
error = F_51 ( V_98 , 0 , 1 , & V_87 ) ;
if ( error < 0 )
return error ;
}
}
return F_52 ( V_47 ) ;
}
static int F_53 ( struct V_102 * V_74 , struct V_46 * * V_103 )
{
struct V_46 * V_47 ;
int V_52 ;
V_52 = F_54 ( V_74 , V_57 , V_78 , V_104 ,
sizeof( struct V_1 ) , & V_47 ) ;
if ( V_52 < 0 )
return V_52 ;
V_47 -> V_105 = F_38 ;
* V_103 = V_47 ;
return 0 ;
}
static int F_55 ( struct V_102 * V_106 ,
unsigned int V_107 )
{
#ifdef F_4
if ( V_108 )
return 0 ;
if ( V_9 )
return 0 ;
#endif
return 1 ;
}
static int F_56 ( struct V_102 * V_106 ,
unsigned int V_107 )
{
struct V_46 * V_47 ;
int error ;
static long V_109 [] = { 0x300 , 0x310 , 0x320 , 0x330 , - 1 } ;
#ifdef F_3
static int V_110 [] = { 5 , 9 , 10 , 11 , 7 , - 1 } ;
#else
static int V_110 [] = { 9 , 10 , 11 , 7 , - 1 } ;
#endif
static int V_111 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_112 [] = { 3 , 1 , 0 , - 1 } ;
#if F_16 ( F_15 ) || F_16 ( F_3 )
static int V_113 [] [ 2 ] = { { 1 , - 1 } , { 0 , - 1 } , { - 1 , - 1 } , { 0 , - 1 } } ;
#endif
if ( V_31 == V_88 ) {
if ( ( V_31 = F_42 ( V_109 , 2 ) ) < 0 ) {
F_5 ( V_22 L_27 ) ;
return - V_43 ;
}
}
if ( V_8 == V_114 ) {
if ( ( V_8 = F_57 ( V_110 ) ) < 0 ) {
F_5 ( V_22 L_28 ) ;
return - V_43 ;
}
}
if ( V_32 == V_114 ) {
if ( ( V_32 = F_57 ( V_111 ) ) < 0 ) {
F_5 ( V_22 L_29 ) ;
return - V_43 ;
}
}
if ( V_29 == V_115 ) {
if ( ( V_29 = F_58 ( V_112 ) ) < 0 ) {
F_5 ( V_22 L_30 ) ;
return - V_43 ;
}
}
#if F_16 ( F_15 ) || F_16 ( F_3 )
if ( V_30 == V_115 ) {
if ( ( V_30 = F_58 ( V_113 [ V_29 % 4 ] ) ) < 0 ) {
F_5 ( V_22 L_31 ) ;
return - V_43 ;
}
}
#endif
error = F_53 ( V_106 , & V_47 ) ;
if ( error < 0 )
return error ;
if ( ( error = F_59 ( V_47 , V_47 -> V_81 ) ) < 0 ) {
F_60 ( V_47 ) ;
return error ;
}
if ( ( error = F_41 ( V_47 ) ) < 0 ) {
F_60 ( V_47 ) ;
return error ;
}
F_61 ( V_106 , V_47 ) ;
return 0 ;
}
static int F_62 ( struct V_102 * V_106 ,
unsigned int V_107 )
{
F_60 ( F_63 ( V_106 ) ) ;
return 0 ;
}
static int F_64 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_81 ;
F_65 ( V_47 , V_116 ) ;
V_2 -> V_60 -> V_117 ( V_2 -> V_60 ) ;
return 0 ;
}
static int F_66 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_81 ;
int error , V_83 ;
#if F_16 ( F_15 ) || F_16 ( F_3 )
V_83 = V_30 ;
#else
V_83 = - 1 ;
#endif
error = F_12 ( V_2 , V_28 , V_8 , V_29 , V_83 ,
V_31 , V_32 ) ;
if ( error )
return error ;
V_2 -> V_60 -> V_118 ( V_2 -> V_60 ) ;
F_65 ( V_47 , V_119 ) ;
return 0 ;
}
static int F_67 ( struct V_102 * V_107 , unsigned int V_120 ,
T_2 V_121 )
{
return F_64 ( F_63 ( V_107 ) ) ;
}
static int F_68 ( struct V_102 * V_107 , unsigned int V_120 )
{
return F_66 ( F_63 ( V_107 ) ) ;
}
static int F_69 ( struct V_70 * V_122 ,
const struct V_71 * V_72 )
{
struct V_46 * V_47 ;
int error , V_123 ;
struct V_1 * V_2 ;
if ( V_108 )
return - V_43 ;
if ( ! V_9 )
return - V_23 ;
error = F_53 ( & V_122 -> V_47 -> V_107 , & V_47 ) ;
if ( error < 0 )
return error ;
V_2 = V_47 -> V_81 ;
V_123 = F_31 ( V_2 , V_122 , V_72 ) ;
switch ( V_123 ) {
case 0x0924 :
V_123 = V_16 ;
break;
case 0x0925 :
V_123 = V_17 ;
break;
case 0x0931 :
V_123 = V_19 ;
break;
default:
F_60 ( V_47 ) ;
return - V_23 ;
}
if ( ( error = F_1 ( V_2 , V_123 ) ) ) {
F_60 ( V_47 ) ;
return error ;
}
error = F_28 ( V_2 ) ;
if ( error ) {
F_5 ( V_22 L_32 ) ;
F_60 ( V_47 ) ;
return error ;
}
if ( ( error = F_41 ( V_47 ) ) < 0 ) {
F_60 ( V_47 ) ;
return error ;
}
F_70 ( V_122 , V_47 ) ;
V_108 = 1 ;
return 0 ;
}
static void F_71 ( struct V_70 * V_122 )
{
F_60 ( F_72 ( V_122 ) ) ;
F_70 ( V_122 , NULL ) ;
V_108 = 0 ;
}
static int F_73 ( struct V_70 * V_122 ,
T_2 V_121 )
{
return F_64 ( F_72 ( V_122 ) ) ;
}
static int F_74 ( struct V_70 * V_122 )
{
return F_66 ( F_72 ( V_122 ) ) ;
}
static int T_3 F_75 ( void )
{
#ifdef F_4
F_76 ( & V_124 ) ;
if ( V_108 )
return 0 ;
F_77 ( & V_124 ) ;
#endif
return F_78 ( & V_125 , 1 ) ;
}
static void T_4 F_79 ( void )
{
if ( ! V_108 ) {
F_80 ( & V_125 ) ;
return;
}
#ifdef F_4
F_77 ( & V_124 ) ;
#endif
}
