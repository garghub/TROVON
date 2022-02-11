static void F_1 ( T_1 * V_1 , int V_2 )
{
unsigned long V_3 , V_4 ;
V_4 = V_5 + V_6 / 10 ;
for ( V_3 = 0 ; V_3 < 5000000 && F_2 ( V_5 , V_4 ) ; V_3 ++ )
{
if ( F_3 ( F_4 ( V_7 ) ) & V_8 )
{
F_5 ( V_2 , F_4 ( V_9 ) ) ;
return;
}
}
F_6 ( V_10 L_1 , V_2 ) ;
}
static int T_2 F_7 ( struct V_11 * V_12 )
{
unsigned short V_13 ;
int V_14 , V_15 ;
V_1 -> V_16 = V_12 -> V_17 ;
V_14 = V_1 -> V_14 = V_12 -> V_14 ;
V_15 = V_1 -> V_15 = V_12 -> V_15 ;
V_1 -> V_18 = V_12 -> V_18 ;
if ( V_1 -> V_16 != 0x220 && V_1 -> V_16 != 0x240 )
if ( V_1 -> V_16 != 0x230 && V_1 -> V_16 != 0x250 )
return 0 ;
if ( ! F_8 ( V_1 -> V_16 , 0x10 , L_2 ) ) {
F_6 ( V_19 L_3 ) ;
return 0 ;
}
V_13 = F_3 ( F_4 ( V_20 ) ) ;
if ( ( V_13 >> 8 ) != 'E' ) {
F_6 ( V_19 L_4 , V_1 -> V_16 , V_13 ) ;
F_9 ( V_1 -> V_16 , 0x10 ) ;
return 0 ;
}
if ( ! F_8 ( V_1 -> V_16 + 0x10 , 0x9 , L_5 ) ) {
F_6 ( V_19 L_3 ) ;
F_9 ( V_1 -> V_16 , 0x10 ) ;
return 0 ;
}
return 1 ;
}
static int F_10 ( T_1 * V_1 , int V_21 , int V_14 )
{
static unsigned short V_22 [ 16 ] =
{
0x0000 , 0x0000 , 0x0000 , 0x0008 ,
0x0000 , 0x0010 , 0x0000 , 0x0018 ,
0x0000 , 0x0020 , 0x0028 , 0x0030 ,
0x0038 , 0x0000 , 0x0000 , 0x0000
} ;
unsigned short V_23 , V_24 ;
if ( V_14 < 0 || V_14 > 15 )
return 0 ;
V_23 = F_3 ( F_4 ( V_21 ) ) & ~ 0x38 ;
if ( ( V_24 = V_22 [ V_14 ] ) == 0 && V_14 != 0 )
{
F_6 ( V_19 L_6 , V_14 ) ;
return 0 ;
}
F_5 ( V_23 | V_24 , F_4 ( V_21 ) ) ;
return 1 ;
}
static void F_11 ( T_1 * V_1 , int V_21 , int V_16 )
{
unsigned short V_23 = F_3 ( F_4 ( V_21 ) ) & 0x003f ;
unsigned short V_24 = ( V_16 & 0x0ffc ) << 4 ;
F_5 ( V_24 | V_23 , F_4 ( V_21 ) ) ;
}
static int F_12 ( T_1 * V_1 , int V_21 , int V_15 )
{
static unsigned short V_25 [ 8 ] =
{
0x0001 , 0x0002 , 0x0000 , 0x0003 ,
0x0000 , 0x0005 , 0x0006 , 0x0007
} ;
unsigned short V_23 , V_24 ;
if ( V_15 < 0 || V_15 > 7 )
return 0 ;
V_23 = F_3 ( F_4 ( V_21 ) ) & ~ 0x07 ;
if ( ( V_24 = V_25 [ V_15 ] ) == 0 && V_15 != 4 )
{
F_6 ( V_19 L_7 , V_15 ) ;
return 0 ;
}
F_5 ( V_23 | V_24 , F_4 ( V_21 ) ) ;
return 1 ;
}
static int F_13 ( T_1 * V_1 )
{
unsigned long V_3 , V_4 = V_5 + V_6 / 10 ;
F_5 ( 0x2000 , F_4 ( V_26 ) ) ;
for ( V_3 = 0 ; V_3 < 32768 && F_14 ( V_4 , V_5 ) ; V_3 ++ )
F_3 ( F_4 ( V_26 ) ) ;
F_5 ( 0x0000 , F_4 ( V_26 ) ) ;
return 1 ;
}
static int F_15 ( T_1 * V_1 , unsigned short V_27 )
{
int V_3 , V_28 ;
for ( V_3 = 0 ; V_3 < 327680 ; V_3 ++ )
{
V_28 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_28 & V_8 )
{
F_5 ( V_27 , F_4 ( V_9 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_16 ( T_1 * V_1 , unsigned short * V_27 )
{
int V_3 , V_28 ;
for ( V_3 = 0 ; V_3 < 327680 ; V_3 ++ )
{
V_28 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_28 & V_29 )
{
* V_27 = F_3 ( F_4 ( V_9 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_17 ( T_1 * V_1 , unsigned char * V_30 , int V_31 , int V_32 )
{
int V_3 , V_28 , V_33 ;
unsigned long V_4 ;
if ( V_32 & V_34 )
{
F_5 ( 0x00fe , F_4 ( V_9 ) ) ;
V_4 = V_5 + V_6 / 10 ;
for ( V_3 = 0 ; V_3 < 32768 && F_2 ( V_5 , V_4 ) ; V_3 ++ )
if ( F_3 ( F_4 ( V_9 ) ) == 0x5500 )
break;
F_5 ( * V_30 ++ , F_4 ( V_9 ) ) ;
F_13 ( V_1 ) ;
}
V_33 = 1 ;
while ( ( V_32 & V_35 ) || V_33 < V_31 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < 327670 ; V_36 ++ )
{
if ( F_3 ( F_4 ( V_7 ) ) & V_37 )
break;
}
if ( V_36 == 327670 )
{
if ( V_33 >= V_31 && V_32 & V_35 )
break;
else
{
F_6 ( L_8 ) ;
F_6 ( V_19 L_9 , V_33 , V_31 ) ;
return 0 ;
}
}
if ( V_33 >= V_31 )
{
F_5 ( 0xffff , F_4 ( V_9 ) ) ;
}
else
{
F_5 ( * V_30 ++ , F_4 ( V_9 ) ) ;
}
V_33 ++ ;
}
if ( V_32 & V_35 )
{
F_5 ( 0 , F_4 ( V_9 ) ) ;
V_4 = V_5 + V_6 / 10 ;
for ( V_3 = 0 ; V_3 < 32768 && F_14 ( V_4 , V_5 ) ; V_3 ++ )
V_28 = F_3 ( F_4 ( V_7 ) ) ;
V_4 = V_5 + V_6 / 10 ;
for ( V_3 = 0 ; V_3 < 32768 && F_14 ( V_4 , V_5 ) ; V_3 ++ )
{
V_28 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_28 & 0x4000 )
break;
}
for ( V_3 = 0 ; V_3 < 32000 ; V_3 ++ )
{
V_28 = F_3 ( F_4 ( V_7 ) ) ;
if ( V_28 & V_29 )
break;
}
if ( V_3 == 32000 )
return 0 ;
V_28 = F_3 ( F_4 ( V_9 ) ) ;
}
return 1 ;
}
static void F_18 ( T_1 * V_1 , int V_38 , int V_39 )
{
static unsigned char V_40 [ 101 ] = {
0xdb , 0xe0 , 0xe3 , 0xe5 , 0xe7 , 0xe9 , 0xea , 0xeb , 0xec , 0xed , 0xed , 0xee ,
0xef , 0xef , 0xf0 , 0xf0 , 0xf1 , 0xf1 , 0xf2 , 0xf2 , 0xf2 , 0xf3 , 0xf3 , 0xf3 ,
0xf4 , 0xf4 , 0xf4 , 0xf5 , 0xf5 , 0xf5 , 0xf5 , 0xf6 , 0xf6 , 0xf6 , 0xf6 , 0xf7 ,
0xf7 , 0xf7 , 0xf7 , 0xf7 , 0xf8 , 0xf8 , 0xf8 , 0xf8 , 0xf8 , 0xf9 , 0xf9 , 0xf9 ,
0xf9 , 0xf9 , 0xf9 , 0xfa , 0xfa , 0xfa , 0xfa , 0xfa , 0xfa , 0xfa , 0xfb , 0xfb ,
0xfb , 0xfb , 0xfb , 0xfb , 0xfb , 0xfb , 0xfc , 0xfc , 0xfc , 0xfc , 0xfc , 0xfc ,
0xfc , 0xfc , 0xfc , 0xfc , 0xfd , 0xfd , 0xfd , 0xfd , 0xfd , 0xfd , 0xfd , 0xfd ,
0xfd , 0xfd , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe , 0xfe ,
0xfe , 0xfe , 0xff , 0xff , 0xff
} ;
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , V_40 [ V_38 ] | 0x0000 ) ;
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , V_40 [ V_39 ] | 0x0100 ) ;
}
static void F_19 ( T_1 * V_1 , int V_41 )
{
int V_42 = ( ( 0x8000 * V_41 ) / 100L ) ;
F_1 ( V_1 , 0x0080 ) ;
F_1 ( V_1 , V_42 ) ;
F_1 ( V_1 , 0x0081 ) ;
F_1 ( V_1 , V_42 ) ;
}
static void F_20 ( T_1 * V_1 , int V_43 )
{
int V_42 = ( int ) ( ( ( 0xfd - 0xf0 ) * V_43 ) / 100L ) + 0xf0 ;
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , V_42 | 0x0200 ) ;
}
static void F_21 ( T_1 * V_1 , int V_43 )
{
int V_42 = ( ( ( 0xfd - 0xf0 ) * V_43 ) / 100L ) + 0xf0 ;
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , V_42 | 0x0300 ) ;
}
static void F_22 ( T_1 * V_1 )
{
F_18 ( V_1 , 33 , 33 ) ;
F_20 ( V_1 , 50 ) ;
F_21 ( V_1 , 50 ) ;
F_19 ( V_1 , 30 ) ;
F_1 ( V_1 , 0x0010 ) ;
F_1 ( V_1 , 0x0800 | 0xce ) ;
if( V_44 )
{
V_1 -> V_45 . V_46 = V_1 -> V_45 . V_47 = 33 ;
V_1 -> V_45 . V_48 = 50 ;
V_1 -> V_45 . V_49 = 50 ;
V_1 -> V_45 . V_50 = 30 ;
}
}
static int F_23 ( unsigned T_3 * V_51 , unsigned int * V_52 )
{
unsigned int V_38 , V_41 ;
if ( F_24 ( V_41 , V_51 ) )
return - V_53 ;
V_38 = V_41 & 0xff ;
if ( V_38 > 100 )
V_38 = 100 ;
* V_52 = V_38 ;
return 0 ;
}
static int F_25 ( unsigned T_3 * V_51 ,
unsigned int * V_52 ,
unsigned int * V_54 )
{
unsigned int V_38 , V_39 , V_41 ;
if ( F_24 ( V_41 , V_51 ) )
return - V_53 ;
V_38 = V_41 & 0xff ;
if ( V_38 > 100 )
V_38 = 100 ;
V_39 = ( V_41 >> 8 ) & 0xff ;
if ( V_39 > 100 )
V_39 = 100 ;
* V_52 = V_38 ;
* V_54 = V_39 ;
return 0 ;
}
static int F_26 ( int V_38 )
{
return ( ( V_38 << 8 ) | V_38 ) ;
}
static int F_27 ( int V_38 , int V_39 )
{
return ( ( V_39 << 8 ) | V_38 ) ;
}
static int F_28 ( T_1 * V_1 , unsigned int V_55 , void T_3 * V_56 )
{
if ( V_1 -> V_57 != V_58 )
return V_59 [ V_1 -> V_57 ] -> F_29 ( V_1 -> V_57 , V_55 , V_56 ) ;
else
return - V_60 ;
}
static int F_30 ( int V_21 , unsigned int V_55 , void T_3 * V_56 )
{
T_1 * V_1 = V_59 [ V_21 ] -> V_1 ;
int V_61 = V_55 & 0xff ;
if ( ( V_61 != V_62 ) && ( V_61 != V_63 ) &&
( V_61 != V_64 ) && ( V_61 != V_65 ) &&
( V_61 != V_66 ) && ( V_61 != V_67 ) &&
( V_61 != V_68 ) && ( V_61 != V_69 ) &&
( V_61 != V_70 ) )
{
return F_28 ( V_1 , V_55 , V_56 ) ;
}
if ( ( ( V_55 >> 8 ) & 0xff ) != 'M' )
return - V_60 ;
if ( F_31 ( V_55 ) & V_71 )
{
switch ( V_61 )
{
case V_70 :
if ( V_1 -> V_57 != V_58 )
return F_28 ( V_1 , V_55 , V_56 ) ;
else
{
int V_72 ;
if ( F_24 ( V_72 , ( int T_3 * ) V_56 ) )
return - V_53 ;
if ( V_72 != 0 )
return - V_60 ;
return 0 ;
}
case V_62 :
if ( F_25 ( V_56 ,
& V_1 -> V_45 . V_46 ,
& V_1 -> V_45 . V_47 ) )
return - V_53 ;
F_18 ( V_1 , V_1 -> V_45 . V_46 ,
V_1 -> V_45 . V_47 ) ;
return F_27 ( V_1 -> V_45 . V_46 ,
V_1 -> V_45 . V_47 ) ;
case V_63 :
if ( F_23 ( V_56 , & V_1 -> V_45 . V_48 ) )
return - V_53 ;
F_20 ( V_1 , V_1 -> V_45 . V_48 ) ;
return F_26 ( V_1 -> V_45 . V_48 ) ;
case V_64 :
if ( F_23 ( V_56 , & V_1 -> V_45 . V_49 ) )
return - V_53 ;
F_21 ( V_1 , V_1 -> V_45 . V_49 ) ;
return F_26 ( V_1 -> V_45 . V_49 ) ;
case V_65 :
if ( F_23 ( V_56 , & V_1 -> V_45 . V_50 ) )
return - V_53 ;
F_19 ( V_1 , V_1 -> V_45 . V_50 ) ;
return F_26 ( V_1 -> V_45 . V_50 ) ;
default:
return - V_60 ;
}
}
else
{
int V_28 , V_73 = 0 , V_74 = 0 ;
switch ( V_61 )
{
case V_66 :
if ( F_28 ( V_1 , V_55 , V_56 ) == - V_60 )
break;
V_73 = ~ 0 ;
V_74 = V_75 | V_76 | V_77 | V_78 ;
break;
case V_67 :
if ( F_28 ( V_1 , V_55 , V_56 ) == - V_60 )
break;
V_73 = ~ 0 ;
V_74 = V_75 ;
break;
case V_68 :
if ( V_1 -> V_57 != V_58 )
return F_28 ( V_1 , V_55 , V_56 ) ;
break;
case V_69 :
if ( V_1 -> V_57 != V_58 )
return F_28 ( V_1 , V_55 , V_56 ) ;
V_74 = V_79 ;
break;
case V_70 :
if ( V_1 -> V_57 != V_58 )
return F_28 ( V_1 , V_55 , V_56 ) ;
break;
case V_62 :
V_74 = F_27 ( V_1 -> V_45 . V_46 , V_1 -> V_45 . V_47 ) ;
break;
case V_63 :
V_74 = F_26 ( V_1 -> V_45 . V_48 ) ;
break;
case V_64 :
V_74 = F_26 ( V_1 -> V_45 . V_49 ) ;
break;
case V_65 :
V_74 = F_26 ( V_1 -> V_45 . V_50 ) ;
break;
default:
return - V_60 ;
}
if ( F_24 ( V_28 , ( int T_3 * ) V_56 ) )
return - V_53 ;
V_28 &= V_73 ;
V_28 |= V_74 ;
if ( F_32 ( V_28 , ( int T_3 * ) V_56 ) )
return - V_53 ;
return V_28 ;
}
}
static void F_33 ( void )
{
F_5 ( 0x0000 , F_4 ( V_80 ) ) ;
F_5 ( 0x0000 , F_4 ( V_81 ) ) ;
F_5 ( 0x0000 , F_4 ( V_82 ) ) ;
F_5 ( 0x0000 , F_4 ( V_83 ) ) ;
F_5 ( 0x0000 , F_4 ( V_84 ) ) ;
}
static void F_34 ( void )
{
if( V_85 )
{
F_5 ( 0x0400 , F_4 ( V_80 ) ) ;
F_6 ( V_86 L_10 ) ;
}
else
{
F_6 ( V_86 L_11 ) ;
}
if ( V_87 == - 1 ) {
F_6 ( V_86 L_12 ) ;
} else if ( ! F_8 ( V_87 , 2 , L_13 ) ) {
V_87 = - 1 ;
F_6 ( V_19 L_14 ) ;
} else {
F_11 ( V_1 , V_84 , V_87 ) ;
F_6 ( V_86 L_15 , V_87 ) ;
}
}
static int T_2 F_35 ( struct V_11 * V_12 )
{
unsigned short V_13 ;
char V_23 [ 100 ] ;
V_1 -> V_16 = V_12 -> V_17 ;
V_1 -> V_14 = V_12 -> V_14 ;
V_1 -> V_15 = V_12 -> V_15 ;
V_1 -> V_18 = V_12 -> V_18 ;
V_1 -> V_57 = V_58 ;
if ( ! F_7 ( V_12 ) )
return 0 ;
V_13 = F_3 ( F_4 ( V_20 ) ) & 0x00ff ;
F_33 () ;
#ifdef F_36
if ( F_37 ( V_12 -> V_15 , L_16 ) )
{
F_6 ( L_17 ) ;
F_9 ( V_12 -> V_17 , 0x10 ) ;
F_9 ( V_12 -> V_17 + 0x10 , 0x9 ) ;
return 0 ;
}
if ( ! F_10 ( V_1 , V_80 , V_1 -> V_14 ) )
{
F_6 ( L_18 ) ;
F_9 ( V_12 -> V_17 , 0x10 ) ;
F_9 ( V_12 -> V_17 + 0x10 , 0x9 ) ;
return 0 ;
}
if ( ! F_12 ( V_1 , V_80 , V_1 -> V_15 ) )
{
F_6 ( V_19 L_19 ) ;
F_9 ( V_12 -> V_17 , 0x10 ) ;
F_9 ( V_12 -> V_17 + 0x10 , 0x9 ) ;
return 0 ;
}
#endif
F_34 () ;
V_88 = 1 ;
sprintf ( V_23 , L_20 , V_13 ) ;
F_38 ( V_23 , V_12 ) ;
return 1 ;
}
static int T_2 F_39 ( struct V_11 * V_12 )
{
struct V_89 * V_90 ;
int V_91 ;
if ( ! V_88 )
return 0 ;
V_90 = F_8 ( V_12 -> V_17 , 2 , L_21 ) ;
if ( ! V_90 ) {
F_6 ( V_19 L_22 ) ;
return 0 ;
}
F_11 ( V_1 , V_83 , V_12 -> V_17 ) ;
if ( ! F_10 ( V_1 , V_83 , V_12 -> V_14 ) ) {
F_6 ( V_19 L_23 ) ;
goto V_92;
}
if ( ! V_93 ) {
F_6 ( V_19 L_24 ) ;
goto V_92;
}
if ( ! F_17 ( V_1 , V_94 , V_93 , V_34 | V_35 ) ) {
F_6 ( V_19 L_25 ) ;
goto V_92;
}
for ( V_91 = 900000 ; V_91 > 0 ; V_91 -- )
{
if ( ( F_40 ( V_12 -> V_17 + 1 ) & 0x80 ) == 0 )
F_40 ( V_12 -> V_17 ) ;
else
break;
}
if ( ! F_41 ( V_12 , V_90 ) )
goto V_92;
F_42 ( V_12 , V_95 ) ;
if ( V_12 -> V_96 [ 1 ] != - 1 )
V_97 [ V_12 -> V_96 [ 1 ] ] -> V_98 = & V_99 ;
return 1 ;
V_92:
F_9 ( V_12 -> V_17 , 2 ) ;
return 0 ;
}
static int F_43 ( void * V_100 , int V_101 )
{
switch ( V_101 )
{
case V_102 :
if ( V_93 == 0 )
{
F_6 ( V_19 L_26 ) ;
return - V_103 ;
}
if ( V_104 )
if ( ! F_17 ( V_1 , V_94 , V_93 , V_34 | V_35 ) )
{
F_6 ( V_19 L_25 ) ;
return - V_103 ;
}
V_104 = 0 ;
break;
default:
break;
}
return 0 ;
}
static void F_44 ( void * V_100 , int V_101 )
{
return;
}
static void F_45 ( void * V_100 )
{
if ( V_93 )
if ( ! F_17 ( V_1 , V_94 , V_93 , V_34 | V_35 ) )
{
F_6 ( V_19 L_25 ) ;
}
V_104 = 0 ;
}
static int F_46 ( void * V_100 , T_4 * V_105 )
{
if ( V_105 -> V_106 <= 0 || V_105 -> V_106 > sizeof( V_105 -> V_2 ) )
return - V_60 ;
if ( ! F_17 ( V_1 , V_105 -> V_2 , V_105 -> V_106 , V_105 -> V_32 ) )
{
F_6 ( V_19 L_27 ) ;
return - V_103 ;
}
V_104 = 1 ;
return 0 ;
}
static int F_47 ( void * V_100 , unsigned int V_55 , void T_3 * V_56 , int V_107 )
{
T_4 * V_105 ;
T_5 * V_108 ;
T_6 V_109 ;
unsigned short V_23 ;
unsigned long V_32 ;
unsigned short * V_2 ;
int V_3 , V_110 ;
switch ( V_55 )
{
case V_111 :
F_45 ( V_100 ) ;
return 0 ;
case V_112 :
V_105 = F_48 ( sizeof( T_4 ) ) ;
if ( V_105 == NULL )
return - V_113 ;
if ( F_49 ( V_105 , V_56 , sizeof( T_4 ) ) ) {
F_50 ( V_105 ) ;
return - V_53 ;
}
V_110 = F_46 ( V_100 , V_105 ) ;
F_50 ( V_105 ) ;
return V_110 ;
case V_114 :
V_108 = F_48 ( sizeof( T_5 ) ) ;
if ( V_108 == NULL )
return - V_113 ;
if ( F_49 ( V_108 , V_56 , sizeof( T_5 ) ) ) {
F_50 ( V_108 ) ;
return - V_53 ;
}
V_2 = ( unsigned short * ) ( V_108 -> V_2 ) ;
F_51 ( & V_115 , V_32 ) ;
for ( V_3 = 0 ; V_3 < V_108 -> V_106 ; V_3 ++ ) {
if ( ! F_15 ( V_1 , * V_2 ++ ) ) {
F_52 ( & V_115 , V_32 ) ;
V_108 -> V_106 = V_3 ;
V_110 = F_53 ( V_56 , V_108 , sizeof( T_5 ) ) ;
F_50 ( V_108 ) ;
return V_110 ? - V_53 : - V_103 ;
}
}
F_52 ( & V_115 , V_32 ) ;
F_50 ( V_108 ) ;
return 0 ;
case V_116 :
V_110 = 0 ;
V_108 = F_48 ( sizeof( T_5 ) ) ;
if ( V_108 == NULL )
return - V_113 ;
V_2 = ( unsigned short * ) V_108 -> V_2 ;
F_51 ( & V_115 , V_32 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_108 -> V_2 ) /sizeof( unsigned short ) ; V_3 ++ ) {
V_108 -> V_106 = V_3 ;
if ( ! F_16 ( V_1 , V_2 ++ ) ) {
if ( V_3 == 0 )
V_110 = - V_103 ;
break;
}
}
F_52 ( & V_115 , V_32 ) ;
if ( F_53 ( V_56 , V_108 , sizeof( T_5 ) ) )
V_110 = - V_53 ;
F_50 ( V_108 ) ;
return V_110 ;
case V_117 :
if ( F_49 ( & V_109 , V_56 , sizeof( V_109 ) ) )
return - V_53 ;
F_51 ( & V_115 , V_32 ) ;
if ( ! F_15 ( V_1 , 0x00d0 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_15 ( V_1 , ( unsigned short ) ( V_109 . V_118 & 0xffff ) ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_16 ( V_1 , & V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_109 . V_118 = V_23 ;
F_52 ( & V_115 , V_32 ) ;
if ( F_53 ( V_56 , & V_109 , sizeof( V_109 ) ) )
return - V_53 ;
return 0 ;
case V_119 :
if ( F_49 ( & V_109 , V_56 , sizeof( V_109 ) ) )
return - V_53 ;
F_51 ( & V_115 , V_32 ) ;
if ( ! F_15 ( V_1 , 0x00d1 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_15 ( V_1 , ( unsigned short ) ( V_109 . V_118 & 0xffff ) ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_23 = ( unsigned int ) V_109 . V_120 & 0xffff ;
if ( ! F_15 ( V_1 , V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
F_52 ( & V_115 , V_32 ) ;
return 0 ;
case V_121 :
if ( F_49 ( & V_109 , V_56 , sizeof( V_109 ) ) )
return - V_53 ;
F_51 ( & V_115 , V_32 ) ;
if ( ! F_15 ( V_1 , 0x00d3 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_15 ( V_1 , ( unsigned short ) ( V_109 . V_118 & 0xffff ) ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_23 = ( unsigned int ) V_109 . V_120 & 0x00ff ;
if ( ! F_15 ( V_1 , V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_23 = ( ( unsigned int ) V_109 . V_120 >> 8 ) & 0xffff ;
if ( ! F_15 ( V_1 , V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
F_52 ( & V_115 , V_32 ) ;
return 0 ;
case V_122 :
if ( F_49 ( & V_109 , V_56 , sizeof( V_109 ) ) )
return - V_53 ;
F_51 ( & V_115 , V_32 ) ;
if ( ! F_15 ( V_1 , 0x00d2 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_15 ( V_1 , ( unsigned short ) ( V_109 . V_118 & 0xffff ) ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
if ( ! F_16 ( V_1 , & V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_109 . V_118 = V_23 << 8 ;
if ( ! F_16 ( V_1 , & V_23 ) ) {
F_52 ( & V_115 , V_32 ) ;
return - V_103 ;
}
V_109 . V_118 |= V_23 & 0x00ff ;
F_52 ( & V_115 , V_32 ) ;
if ( F_53 ( V_56 , & V_109 , sizeof( V_109 ) ) )
return - V_53 ;
return 0 ;
default:
return - V_60 ;
}
return - V_60 ;
}
static int T_2 F_54 ( struct V_11 * V_12 )
{
volatile int V_91 ;
struct V_89 * V_90 ;
int V_123 = - 999 ;
if ( ! V_88 )
return 0 ;
if ( ! F_8 ( V_12 -> V_17 , 4 , L_28 ) ) {
F_6 ( V_19 L_29 ) ;
return 0 ;
}
V_90 = F_8 ( V_12 -> V_17 + 4 , 4 , L_30 ) ;
if ( ! V_90 ) {
F_6 ( V_19 L_29 ) ;
F_9 ( V_12 -> V_17 , 4 ) ;
return 0 ;
}
F_11 ( V_1 , V_81 , V_12 -> V_17 ) ;
if ( ! F_10 ( V_1 , V_81 , V_12 -> V_14 ) ) {
F_6 ( L_31 ) ;
goto V_92;
}
if ( ! F_12 ( V_1 , V_81 , V_12 -> V_15 ) ) {
F_6 ( V_19 L_32 ) ;
goto V_92;
}
for ( V_91 = 0 ; V_91 < 100000 && ( F_40 ( V_12 -> V_17 + V_124 ) &
V_125 ) ; V_91 ++ )
;
F_55 ( ( 0x0b ) , V_12 -> V_17 + V_124 ) ;
for ( V_91 = 0 ; ( F_40 ( V_12 -> V_17 + V_126 ) & V_127 ) &&
( V_91 < 100000 ) ; V_91 ++ )
;
if ( ! F_56 ( V_12 , V_90 ) )
goto V_92;
V_1 -> V_57 = V_58 ;
if ( V_44 )
{
if ( ( V_123 = F_57 ( V_128 ,
L_33 ,
& V_129 ,
sizeof ( struct V_130 ) ,
V_1 ) ) < 0 )
{
F_6 ( V_19 L_34 ) ;
goto V_92;
}
}
F_22 ( V_1 ) ;
F_58 ( V_12 , V_90 , V_95 ) ;
if ( V_12 -> V_96 [ 0 ] != - 1 )
{
V_131 [ V_12 -> V_96 [ 0 ] ] -> V_98 = & V_99 ;
if ( V_44 && ( V_132 == ( V_123 + 2 ) ) )
{
V_1 -> V_57 = V_131 [ V_12 -> V_96 [ 0 ] ] -> V_133 ;
}
}
return 1 ;
V_92:
F_9 ( V_12 -> V_17 + 4 , 4 ) ;
F_9 ( V_12 -> V_17 , 4 ) ;
return 0 ;
}
static inline void T_7 F_59 ( struct V_11 * V_12 )
{
F_9 ( V_12 -> V_17 , 0x10 ) ;
F_9 ( V_12 -> V_17 + 0x10 , 0x9 ) ;
}
static inline void T_7 F_60 ( struct V_11 * V_12 )
{
F_61 ( V_12 ) ;
}
static inline void T_7 F_62 ( struct V_11 * V_12 )
{
F_63 ( V_12 ) ;
}
static int T_2 F_64 ( void )
{
if( V_134 )
{
V_135 . V_17 = V_136 ;
if( ! F_7 ( & V_135 ) )
return - V_137 ;
F_6 ( V_86 L_35 , F_3 ( F_4 ( V_20 ) ) & 0x00ff ) ;
F_6 ( V_86 L_36 ) ;
F_33 () ;
F_34 () ;
F_9 ( V_136 , 0x10 ) ;
F_9 ( V_136 + 0x10 , 0x9 ) ;
return 0 ;
}
V_135 . V_17 = V_136 ;
V_138 . V_17 = V_139 ;
V_138 . V_14 = V_140 ;
V_138 . V_15 = V_141 ;
V_142 . V_17 = V_143 ;
V_142 . V_14 = V_144 ;
if ( V_135 . V_17 == - 1 || V_138 . V_17 == - 1 || V_138 . V_14 == - 1 || V_135 . V_15 == - 1 ) {
F_6 ( V_86 L_37 ) ;
return - V_60 ;
}
if ( ! V_94 ) {
V_145 = 1 ;
V_93 = F_65 ( V_146 , ( void * ) & V_94 ) ;
}
if ( ! F_35 ( & V_135 ) )
return - V_137 ;
if ( F_39 ( & V_142 ) )
V_147 = 1 ;
if ( F_54 ( & V_138 ) )
V_148 = 1 ;
return 0 ;
}
static void T_7 F_66 ( void )
{
if( ! V_134 )
{
if( V_145 && V_94 )
F_50 ( V_94 ) ;
if( V_148 )
F_62 ( & V_138 ) ;
if( V_147 )
F_60 ( & V_142 ) ;
F_59 ( & V_135 ) ;
} else if ( V_87 != - 1 )
F_9 ( V_87 , 2 ) ;
if( ! V_149 )
{
F_33 () ;
F_6 ( V_86 L_38 ) ;
}
}
static int T_2 F_67 ( char * V_150 )
{
int V_151 [ 7 ] ;
V_150 = F_68 ( V_150 , F_69 ( V_151 ) , V_151 ) ;
V_136 = V_151 [ 1 ] ;
V_139 = V_151 [ 2 ] ;
V_140 = V_151 [ 3 ] ;
V_141 = V_151 [ 4 ] ;
V_143 = V_151 [ 5 ] ;
V_144 = V_151 [ 6 ] ;
return 1 ;
}
