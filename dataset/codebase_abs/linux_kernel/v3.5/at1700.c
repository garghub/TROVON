static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , NULL ) ;
F_3 ( V_2 -> V_4 , V_5 ) ;
}
struct V_1 * T_1 F_4 ( int V_6 )
{
struct V_1 * V_2 = F_5 ( sizeof( struct V_7 ) ) ;
unsigned * V_8 ;
int V_9 = 0 ;
if ( ! V_2 )
return F_6 ( - V_10 ) ;
if ( V_6 >= 0 ) {
sprintf ( V_2 -> V_11 , L_1 , V_6 ) ;
F_7 ( V_2 ) ;
V_12 = V_2 -> V_4 ;
V_3 = V_2 -> V_3 ;
} else {
V_2 -> V_4 = V_12 ;
V_2 -> V_3 = V_3 ;
}
if ( V_12 > 0x1ff ) {
V_9 = F_8 ( V_2 , V_12 ) ;
} else if ( V_12 != 0 ) {
V_9 = - V_13 ;
} else {
for ( V_8 = V_14 ; * V_8 ; V_8 ++ ) {
if ( F_8 ( V_2 , * V_8 ) == 0 )
break;
V_2 -> V_3 = V_3 ;
}
if ( ! * V_8 )
V_9 = - V_10 ;
}
if ( V_9 )
goto V_15;
V_9 = F_9 ( V_2 ) ;
if ( V_9 )
goto V_16;
return V_2 ;
V_16:
F_1 ( V_2 ) ;
V_15:
F_10 ( V_2 ) ;
return F_6 ( V_9 ) ;
}
static int T_1 F_8 ( struct V_1 * V_2 , int V_17 )
{
static const char V_18 [ 4 ] = { 3 , 7 , 10 , 15 } ;
static const char V_19 [ 8 ] = { 3 , 4 , 5 , 7 , 9 , 10 , 11 , 15 } ;
static const char V_20 [ 8 ] = { 3 , 4 , 5 , 9 , 10 , 11 , 14 , 15 } ;
unsigned int V_21 , V_3 , V_22 = 0 , V_23 = 0 ;
int V_24 = - V_10 ;
struct V_7 * V_25 = F_11 ( V_2 ) ;
if ( ! F_12 ( V_17 , V_5 , V_26 ) )
return - V_27 ;
#ifdef F_13
F_14 ( L_2 ,
V_17 , F_15 ( V_17 , 4 ) , F_15 ( V_17 , 5 ) ,
F_15 ( V_17 , 6 ) , F_16 ( V_17 + V_28 ) ) ;
#endif
if ( V_14 [ F_17 ( V_17 + V_29 ) & 0x07 ] == V_17 &&
F_15 ( V_17 , 4 ) == 0x0000 &&
( F_15 ( V_17 , 5 ) & 0xff00 ) == 0xF400 )
V_23 = 1 ;
else if ( F_17 ( V_17 + V_30 ) == 0x00 &&
F_17 ( V_17 + V_30 + 1 ) == 0x00 &&
F_17 ( V_17 + V_30 + 2 ) == 0x0e )
V_22 = 1 ;
else {
goto V_31;
}
F_18 ( 0 , V_17 + V_32 ) ;
if ( V_23 ) {
V_3 = V_20 [ ( F_15 ( V_17 , 12 ) & 0x04 )
| ( F_15 ( V_17 , 0 ) >> 14 ) ] ;
} else {
if ( F_17 ( V_17 + V_33 ) & 0x20 ) {
V_3 = V_2 -> V_3 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( V_3 == V_19 [ V_21 ] )
break;
}
if ( V_21 == 8 ) {
goto V_31;
}
} else {
if ( V_34 [ F_17 ( V_17 + V_35 ) & 0x07 ] != V_17 )
goto V_31;
V_3 = V_18 [ ( F_17 ( V_17 + V_35 ) >> 6 ) & 0x03 ] ;
}
}
F_14 ( L_3 , V_2 -> V_11 ,
V_23 ? L_4 : L_5 , V_17 , V_3 ) ;
V_2 -> V_4 = V_17 ;
V_2 -> V_3 = V_3 ;
if ( V_23 ) {
for( V_21 = 0 ; V_21 < 3 ; V_21 ++ ) {
unsigned short V_36 = F_15 ( V_17 , 4 + V_21 ) ;
( ( unsigned short * ) V_2 -> V_37 ) [ V_21 ] = F_19 ( V_36 ) ;
}
} else {
for( V_21 = 0 ; V_21 < 6 ; V_21 ++ ) {
unsigned char V_38 = F_17 ( V_17 + V_30 + V_21 ) ;
V_2 -> V_37 [ V_21 ] = V_38 ;
}
}
F_14 ( L_6 , V_2 -> V_37 ) ;
{
const char * V_39 [] = { L_7 , L_8 , L_7 , L_9 } ;
if ( V_23 ) {
T_2 V_40 = F_15 ( V_17 , 12 ) ;
V_2 -> V_41 = V_40 >> 8 ;
} else {
T_2 V_40 = F_17 ( V_17 + V_42 ) ;
switch ( V_40 & 0x07 ) {
case 0x01 :
case 0x02 :
V_2 -> V_41 = 0x18 ; break;
case 0x04 :
V_2 -> V_41 = 0x08 ; break;
default:
V_2 -> V_41 = 0x00 ; break;
}
}
F_14 ( L_10 , V_39 [ ( V_2 -> V_41 >> 3 ) & 3 ] ) ;
}
F_18 ( 0xda , V_17 + V_43 ) ;
F_18 ( 0x00 , V_17 + V_44 ) ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
F_18 ( V_2 -> V_37 [ V_21 ] , V_17 + F_20 ( 8 + V_21 ) ) ;
F_18 ( 0x04 , V_17 + V_44 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_18 ( 0x00 , V_17 + F_20 ( 8 + V_21 ) ) ;
F_18 ( 0x08 , V_17 + V_44 ) ;
F_18 ( V_2 -> V_41 , V_17 + V_45 ) ;
F_18 ( 0x00 , V_17 + V_46 ) ;
if ( V_47 )
F_14 ( V_48 ) ;
V_2 -> V_49 = & V_50 ;
V_2 -> V_51 = V_52 ;
F_21 ( & V_25 -> V_53 ) ;
V_25 -> V_54 = V_22 ;
V_24 = F_22 ( V_3 , V_55 , 0 , V_26 , V_2 ) ;
if ( V_24 ) {
F_14 ( V_56 L_11
L_12 ,
V_17 , V_3 ) ;
goto V_31;
}
return 0 ;
V_31:
F_3 ( V_17 , V_5 ) ;
return V_24 ;
}
static int T_1 F_15 ( long V_17 , int V_57 )
{
int V_21 ;
unsigned short V_58 = 0 ;
long V_59 = V_17 + V_28 ;
long V_60 = V_17 + V_61 ;
int V_62 = V_57 | V_63 ;
for ( V_21 = 9 ; V_21 >= 0 ; V_21 -- ) {
short V_64 = ( V_62 & ( 1 << V_21 ) ) ? V_65 : 0 ;
F_18 ( V_66 , V_59 ) ;
F_18 ( V_64 , V_60 ) ;
F_18 ( V_66 | V_67 , V_59 ) ;
}
F_18 ( V_65 , V_60 ) ;
for ( V_21 = 16 ; V_21 > 0 ; V_21 -- ) {
F_18 ( V_66 , V_59 ) ;
F_18 ( V_66 | V_67 , V_59 ) ;
V_58 = ( V_58 << 1 ) | ( ( F_17 ( V_60 ) & V_68 ) ? 1 : 0 ) ;
}
F_18 ( V_66 , V_59 ) ;
F_18 ( V_67 , V_59 ) ;
F_18 ( 0 , V_59 ) ;
return V_58 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_25 = F_11 ( V_2 ) ;
int V_17 = V_2 -> V_4 ;
F_18 ( 0x5a , V_17 + V_43 ) ;
F_18 ( 0xe8 , V_17 + V_44 ) ;
V_25 -> V_69 = 0 ;
V_25 -> V_70 = 1 ;
V_25 -> V_71 = 0 ;
V_25 -> V_72 = 0 ;
V_25 -> V_73 = 0 ;
F_18 ( 0x82 , V_17 + V_74 ) ;
F_18 ( 0x81 , V_17 + V_75 ) ;
if ( V_25 -> V_54 ) {
F_18 ( 0x80 , V_17 + V_29 ) ;
}
F_24 ( V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_25 = F_11 ( V_2 ) ;
int V_17 = V_2 -> V_4 ;
F_14 ( L_13 , V_2 -> V_11 ,
F_16 ( V_17 + V_76 ) , F_17 ( V_17 + V_77 ) & 0x80
? L_14 : L_15 ) ;
F_14 ( L_16 ,
V_2 -> V_11 , F_16 ( V_17 + V_77 ) , F_16 ( V_17 + V_74 ) , F_16 ( V_17 + V_78 ) ,
F_16 ( V_17 + V_43 ) , F_16 ( V_17 + V_79 ) , F_16 ( V_17 + V_80 ) ,
F_16 ( V_17 + V_45 - 1 ) , F_16 ( V_17 + V_81 ) ) ;
V_2 -> V_82 . V_83 ++ ;
F_26 ( 0xffff , V_17 + V_84 ) ;
F_26 ( 0xffff , V_17 + V_77 ) ;
F_18 ( 0x5a , V_17 + V_43 ) ;
F_18 ( 0xe8 , V_17 + V_44 ) ;
F_26 ( 0x8182 , V_17 + V_74 ) ;
F_18 ( 0x00 , V_17 + V_80 ) ;
F_18 ( 0x03 , V_17 + V_46 ) ;
V_2 -> V_85 = V_86 ;
V_25 -> V_69 = 0 ;
V_25 -> V_70 = 1 ;
V_25 -> V_71 = 0 ;
V_25 -> V_72 = 0 ;
V_25 -> V_73 = 0 ;
F_27 ( V_2 ) ;
}
static T_3 F_28 ( struct V_87 * V_88 ,
struct V_1 * V_2 )
{
struct V_7 * V_25 = F_11 ( V_2 ) ;
int V_17 = V_2 -> V_4 ;
short V_89 = V_90 < V_88 -> V_91 ? V_88 -> V_91 : V_90 ;
short V_91 = V_88 -> V_91 ;
unsigned char * V_92 = V_88 -> V_93 ;
static T_4 V_94 [ V_90 ] ;
F_29 ( V_2 ) ;
V_25 -> V_70 = 0 ;
{
F_26 ( V_89 , V_17 + V_79 ) ;
F_30 ( V_17 + V_79 , V_92 , V_91 >> 1 ) ;
if ( V_91 & 1 ) {
F_26 ( V_88 -> V_93 [ V_88 -> V_91 - 1 ] , V_17 + V_79 ) ;
V_91 ++ ;
}
if ( V_89 != V_88 -> V_91 )
F_30 ( V_17 + V_79 , V_94 , ( V_89 - V_91 + 1 ) >> 1 ) ;
V_25 -> V_72 ++ ;
V_25 -> V_73 += V_89 + 2 ;
}
V_25 -> V_70 = 1 ;
if ( V_25 -> V_69 == 0 ) {
F_18 ( 0x80 | V_25 -> V_72 , V_17 + V_80 ) ;
V_25 -> V_72 = 0 ;
V_25 -> V_73 = 0 ;
V_25 -> V_69 = 1 ;
F_24 ( V_2 ) ;
} else if ( V_25 -> V_73 < 4096 - 1502 )
F_24 ( V_2 ) ;
F_31 ( V_88 ) ;
return V_95 ;
}
static T_5 V_55 ( int V_3 , void * V_96 )
{
struct V_1 * V_2 = V_96 ;
struct V_7 * V_25 ;
int V_17 , V_97 ;
int V_98 = 0 ;
if ( V_2 == NULL ) {
F_14 ( L_17 , V_3 ) ;
return V_99 ;
}
V_17 = V_2 -> V_4 ;
V_25 = F_11 ( V_2 ) ;
F_32 ( & V_25 -> V_53 ) ;
V_97 = F_16 ( V_17 + V_77 ) ;
F_26 ( V_97 , V_17 + V_77 ) ;
if ( V_47 > 4 )
F_14 ( L_18 , V_2 -> V_11 , V_97 ) ;
if ( V_25 -> V_71 == 0 &&
( V_97 & 0xff00 || ( F_17 ( V_17 + V_100 ) & 0x40 ) == 0 ) ) {
V_98 = 1 ;
V_25 -> V_71 = 1 ;
F_18 ( 0x00 , V_17 + V_75 ) ;
F_33 ( V_2 ) ;
F_18 ( 0x81 , V_17 + V_75 ) ;
V_25 -> V_71 = 0 ;
}
if ( V_97 & 0x00ff ) {
V_98 = 1 ;
if ( V_97 & 0x02 ) {
if ( V_47 > 4 )
F_14 ( L_19 , V_2 -> V_11 ) ;
F_18 ( 0x03 , V_17 + V_46 ) ;
V_2 -> V_82 . V_101 ++ ;
}
if ( V_97 & 0x82 ) {
V_2 -> V_82 . V_102 ++ ;
if ( V_25 -> V_72 && V_25 -> V_70 ) {
F_18 ( 0x80 | V_25 -> V_72 , V_17 + V_80 ) ;
V_25 -> V_72 = 0 ;
V_25 -> V_73 = 0 ;
V_2 -> V_85 = V_86 ;
F_27 ( V_2 ) ;
} else {
V_25 -> V_69 = 0 ;
F_27 ( V_2 ) ;
}
}
}
F_34 ( & V_25 -> V_53 ) ;
return F_35 ( V_98 ) ;
}
static void
F_33 ( struct V_1 * V_2 )
{
int V_17 = V_2 -> V_4 ;
int V_103 = 5 ;
while ( ( F_17 ( V_17 + V_100 ) & 0x40 ) == 0 ) {
T_2 V_97 = F_16 ( V_17 + V_79 ) ;
T_2 V_104 = F_16 ( V_17 + V_79 ) ;
if ( V_47 > 4 )
F_14 ( L_20 ,
V_2 -> V_11 , F_17 ( V_17 + V_100 ) , V_97 ) ;
#ifndef F_36
if ( V_97 == 0 ) {
F_18 ( 0x05 , V_17 + V_81 ) ;
break;
}
#endif
if ( ( V_97 & 0xF0 ) != 0x20 ) {
V_2 -> V_82 . V_105 ++ ;
if ( V_97 & 0x08 ) V_2 -> V_82 . V_106 ++ ;
if ( V_97 & 0x04 ) V_2 -> V_82 . V_107 ++ ;
if ( V_97 & 0x02 ) V_2 -> V_82 . V_108 ++ ;
if ( V_97 & 0x01 ) V_2 -> V_82 . V_109 ++ ;
} else {
struct V_87 * V_88 ;
if ( V_104 > 1550 ) {
F_14 ( L_21 ,
V_2 -> V_11 , V_104 ) ;
F_16 ( V_17 + V_79 ) ; F_16 ( V_17 + V_79 ) ;
F_18 ( 0x05 , V_17 + V_81 ) ;
V_2 -> V_82 . V_105 ++ ;
break;
}
V_88 = F_37 ( V_2 , V_104 + 3 ) ;
if ( V_88 == NULL ) {
F_14 ( L_22 ,
V_2 -> V_11 , V_104 ) ;
F_16 ( V_17 + V_79 ) ; F_16 ( V_17 + V_79 ) ;
F_18 ( 0x05 , V_17 + V_81 ) ;
V_2 -> V_82 . V_110 ++ ;
break;
}
F_38 ( V_88 , 2 ) ;
F_39 ( V_17 + V_79 , F_40 ( V_88 , V_104 ) , ( V_104 + 1 ) >> 1 ) ;
V_88 -> V_111 = F_41 ( V_88 , V_2 ) ;
F_42 ( V_88 ) ;
V_2 -> V_82 . V_112 ++ ;
V_2 -> V_82 . V_113 += V_104 ;
}
if ( -- V_103 <= 0 )
break;
}
{
int V_21 ;
for ( V_21 = 0 ; V_21 < 20 ; V_21 ++ ) {
if ( ( F_17 ( V_17 + V_100 ) & 0x40 ) == 0x40 )
break;
F_16 ( V_17 + V_79 ) ;
F_18 ( 0x05 , V_17 + V_81 ) ;
}
if ( V_47 > 5 )
F_14 ( L_23 ,
V_2 -> V_11 , F_17 ( V_17 + V_100 ) , V_21 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_25 = F_11 ( V_2 ) ;
int V_17 = V_2 -> V_4 ;
F_29 ( V_2 ) ;
F_18 ( 0xda , V_17 + V_43 ) ;
if ( V_25 -> V_54 )
F_18 ( 0x00 , V_17 + V_29 ) ;
F_18 ( 0x00 , V_17 + V_44 ) ;
return 0 ;
}
static void
F_44 ( struct V_1 * V_2 )
{
int V_17 = V_2 -> V_4 ;
struct V_7 * V_25 = F_11 ( V_2 ) ;
unsigned char V_114 [ 8 ] ;
unsigned long V_115 ;
if ( V_2 -> V_115 & V_116 ) {
memset ( V_114 , 0xff , sizeof( V_114 ) ) ;
F_18 ( 3 , V_17 + V_100 ) ;
} else if ( F_45 ( V_2 ) > V_117 ||
( V_2 -> V_115 & V_118 ) ) {
memset ( V_114 , 0xff , sizeof( V_114 ) ) ;
F_18 ( 2 , V_17 + V_100 ) ;
} else if ( F_46 ( V_2 ) ) {
memset ( V_114 , 0x00 , sizeof( V_114 ) ) ;
F_18 ( 1 , V_17 + V_100 ) ;
} else {
struct V_119 * V_120 ;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
F_47 (ha, dev) {
unsigned int V_121 =
F_48 ( V_122 , V_120 -> V_123 ) >> 26 ;
V_114 [ V_121 >> 3 ] |= ( 1 << V_121 ) ;
}
F_18 ( 0x02 , V_17 + V_100 ) ;
}
F_49 ( & V_25 -> V_53 , V_115 ) ;
if ( memcmp ( V_114 , V_25 -> V_114 , sizeof( V_114 ) ) ) {
int V_21 ;
int V_124 = F_16 ( V_17 + V_43 ) ;
F_26 ( ( V_124 & ~ 0x0C00 ) | 0x0480 , V_17 + V_43 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_18 ( V_114 [ V_21 ] , V_17 + F_20 ( 8 + V_21 ) ) ;
memcpy ( V_25 -> V_114 , V_114 , sizeof( V_114 ) ) ;
F_26 ( V_124 , V_17 + V_43 ) ;
}
F_50 ( & V_25 -> V_53 , V_115 ) ;
}
static int T_1 F_51 ( void )
{
if ( V_12 == 0 )
F_14 ( L_24 ) ;
V_125 = F_4 ( - 1 ) ;
if ( F_52 ( V_125 ) )
return F_53 ( V_125 ) ;
return 0 ;
}
static void T_6 F_54 ( void )
{
F_55 ( V_125 ) ;
F_1 ( V_125 ) ;
F_10 ( V_125 ) ;
}
