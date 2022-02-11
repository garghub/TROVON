static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 , V_5 ;
V_5 = V_6 + V_7 / 10 ;
for ( V_4 = 0 ; V_4 < 5000000 && F_2 ( V_6 , V_5 ) ; V_4 ++ )
{
if ( F_3 ( F_4 ( V_8 ) ) & V_9 )
{
F_5 ( V_3 , F_4 ( V_10 ) ) ;
return;
}
}
F_6 ( V_11 L_1 , V_3 ) ;
}
static int T_1 F_7 ( struct V_12 * V_13 )
{
unsigned short V_14 ;
int V_15 , V_16 ;
V_2 -> V_17 = V_13 -> V_18 ;
V_15 = V_2 -> V_15 = V_13 -> V_15 ;
V_16 = V_2 -> V_16 = V_13 -> V_16 ;
V_2 -> V_19 = V_13 -> V_19 ;
if ( V_2 -> V_17 != 0x220 && V_2 -> V_17 != 0x240 )
if ( V_2 -> V_17 != 0x230 && V_2 -> V_17 != 0x250 )
return 0 ;
if ( ! F_8 ( V_2 -> V_17 , 0x10 , L_2 ) ) {
F_6 ( V_20 L_3 ) ;
return 0 ;
}
V_14 = F_3 ( F_4 ( V_21 ) ) ;
if ( ( V_14 >> 8 ) != 'E' ) {
F_6 ( V_20 L_4 , V_2 -> V_17 , V_14 ) ;
F_9 ( V_2 -> V_17 , 0x10 ) ;
return 0 ;
}
if ( ! F_8 ( V_2 -> V_17 + 0x10 , 0x9 , L_5 ) ) {
F_6 ( V_20 L_3 ) ;
F_9 ( V_2 -> V_17 , 0x10 ) ;
return 0 ;
}
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 , int V_15 )
{
static unsigned short V_23 [ 16 ] =
{
0x0000 , 0x0000 , 0x0000 , 0x0008 ,
0x0000 , 0x0010 , 0x0000 , 0x0018 ,
0x0000 , 0x0020 , 0x0028 , 0x0030 ,
0x0038 , 0x0000 , 0x0000 , 0x0000
} ;
unsigned short V_24 , V_25 ;
if ( V_15 < 0 || V_15 > 15 )
return 0 ;
V_24 = F_3 ( F_4 ( V_22 ) ) & ~ 0x38 ;
if ( ( V_25 = V_23 [ V_15 ] ) == 0 && V_15 != 0 )
{
F_6 ( V_20 L_6 , V_15 ) ;
return 0 ;
}
F_5 ( V_24 | V_25 , F_4 ( V_22 ) ) ;
return 1 ;
}
static void F_11 ( struct V_1 * V_2 , int V_22 , int V_17 )
{
unsigned short V_24 = F_3 ( F_4 ( V_22 ) ) & 0x003f ;
unsigned short V_25 = ( V_17 & 0x0ffc ) << 4 ;
F_5 ( V_25 | V_24 , F_4 ( V_22 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , int V_22 , int V_16 )
{
static unsigned short V_26 [ 8 ] =
{
0x0001 , 0x0002 , 0x0000 , 0x0003 ,
0x0000 , 0x0005 , 0x0006 , 0x0007
} ;
unsigned short V_24 , V_25 ;
if ( V_16 < 0 || V_16 > 7 )
return 0 ;
V_24 = F_3 ( F_4 ( V_22 ) ) & ~ 0x07 ;
if ( ( V_25 = V_26 [ V_16 ] ) == 0 && V_16 != 4 )
{
F_6 ( V_20 L_7 , V_16 ) ;
return 0 ;
}
F_5 ( V_24 | V_25 , F_4 ( V_22 ) ) ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned long V_4 , V_5 = V_6 + V_7 / 10 ;
F_5 ( 0x2000 , F_4 ( V_27 ) ) ;
for ( V_4 = 0 ; V_4 < 32768 && F_14 ( V_5 , V_6 ) ; V_4 ++ )
F_3 ( F_4 ( V_27 ) ) ;
F_5 ( 0x0000 , F_4 ( V_27 ) ) ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned short V_28 )
{
int V_4 , V_29 ;
for ( V_4 = 0 ; V_4 < 327680 ; V_4 ++ )
{
V_29 = F_3 ( F_4 ( V_8 ) ) ;
if ( V_29 & V_9 )
{
F_5 ( V_28 , F_4 ( V_10 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned short * V_28 )
{
int V_4 , V_29 ;
for ( V_4 = 0 ; V_4 < 327680 ; V_4 ++ )
{
V_29 = F_3 ( F_4 ( V_8 ) ) ;
if ( V_29 & V_30 )
{
* V_28 = F_3 ( F_4 ( V_10 ) ) ;
return 1 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned char * V_31 ,
int V_32 , int V_33 )
{
int V_4 , V_29 , V_34 ;
unsigned long V_5 ;
if ( V_33 & V_35 )
{
F_5 ( 0x00fe , F_4 ( V_10 ) ) ;
V_5 = V_6 + V_7 / 10 ;
for ( V_4 = 0 ; V_4 < 32768 && F_2 ( V_6 , V_5 ) ; V_4 ++ )
if ( F_3 ( F_4 ( V_10 ) ) == 0x5500 )
break;
F_5 ( * V_31 ++ , F_4 ( V_10 ) ) ;
F_13 ( V_2 ) ;
}
V_34 = 1 ;
while ( ( V_33 & V_36 ) || V_34 < V_32 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 327670 ; V_37 ++ )
{
if ( F_3 ( F_4 ( V_8 ) ) & V_38 )
break;
}
if ( V_37 == 327670 )
{
if ( V_34 >= V_32 && V_33 & V_36 )
break;
else
{
F_6 ( L_8 ) ;
F_6 ( V_20 L_9 , V_34 , V_32 ) ;
return 0 ;
}
}
if ( V_34 >= V_32 )
{
F_5 ( 0xffff , F_4 ( V_10 ) ) ;
}
else
{
F_5 ( * V_31 ++ , F_4 ( V_10 ) ) ;
}
V_34 ++ ;
}
if ( V_33 & V_36 )
{
F_5 ( 0 , F_4 ( V_10 ) ) ;
V_5 = V_6 + V_7 / 10 ;
for ( V_4 = 0 ; V_4 < 32768 && F_14 ( V_5 , V_6 ) ; V_4 ++ )
V_29 = F_3 ( F_4 ( V_8 ) ) ;
V_5 = V_6 + V_7 / 10 ;
for ( V_4 = 0 ; V_4 < 32768 && F_14 ( V_5 , V_6 ) ; V_4 ++ )
{
V_29 = F_3 ( F_4 ( V_8 ) ) ;
if ( V_29 & 0x4000 )
break;
}
for ( V_4 = 0 ; V_4 < 32000 ; V_4 ++ )
{
V_29 = F_3 ( F_4 ( V_8 ) ) ;
if ( V_29 & V_30 )
break;
}
if ( V_4 == 32000 )
return 0 ;
V_29 = F_3 ( F_4 ( V_10 ) ) ;
}
return 1 ;
}
static void F_18 ( struct V_1 * V_2 , int V_39 , int V_40 )
{
static unsigned char V_41 [ 101 ] = {
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
F_1 ( V_2 , 0x0010 ) ;
F_1 ( V_2 , V_41 [ V_39 ] | 0x0000 ) ;
F_1 ( V_2 , 0x0010 ) ;
F_1 ( V_2 , V_41 [ V_40 ] | 0x0100 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_42 )
{
int V_43 = ( ( 0x8000 * V_42 ) / 100L ) ;
F_1 ( V_2 , 0x0080 ) ;
F_1 ( V_2 , V_43 ) ;
F_1 ( V_2 , 0x0081 ) ;
F_1 ( V_2 , V_43 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_44 )
{
int V_43 = ( int ) ( ( ( 0xfd - 0xf0 ) * V_44 ) / 100L ) + 0xf0 ;
F_1 ( V_2 , 0x0010 ) ;
F_1 ( V_2 , V_43 | 0x0200 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_44 )
{
int V_43 = ( ( ( 0xfd - 0xf0 ) * V_44 ) / 100L ) + 0xf0 ;
F_1 ( V_2 , 0x0010 ) ;
F_1 ( V_2 , V_43 | 0x0300 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_18 ( V_2 , 33 , 33 ) ;
F_20 ( V_2 , 50 ) ;
F_21 ( V_2 , 50 ) ;
F_19 ( V_2 , 30 ) ;
F_1 ( V_2 , 0x0010 ) ;
F_1 ( V_2 , 0x0800 | 0xce ) ;
if( V_45 )
{
V_2 -> V_46 . V_47 = V_2 -> V_46 . V_48 = 33 ;
V_2 -> V_46 . V_49 = 50 ;
V_2 -> V_46 . V_50 = 50 ;
V_2 -> V_46 . V_51 = 30 ;
}
}
static int F_23 ( unsigned T_2 * V_52 , unsigned int * V_53 )
{
unsigned int V_39 , V_42 ;
if ( F_24 ( V_42 , V_52 ) )
return - V_54 ;
V_39 = V_42 & 0xff ;
if ( V_39 > 100 )
V_39 = 100 ;
* V_53 = V_39 ;
return 0 ;
}
static int F_25 ( unsigned T_2 * V_52 ,
unsigned int * V_53 ,
unsigned int * V_55 )
{
unsigned int V_39 , V_40 , V_42 ;
if ( F_24 ( V_42 , V_52 ) )
return - V_54 ;
V_39 = V_42 & 0xff ;
if ( V_39 > 100 )
V_39 = 100 ;
V_40 = ( V_42 >> 8 ) & 0xff ;
if ( V_40 > 100 )
V_40 = 100 ;
* V_53 = V_39 ;
* V_55 = V_40 ;
return 0 ;
}
static int F_26 ( int V_39 )
{
return ( ( V_39 << 8 ) | V_39 ) ;
}
static int F_27 ( int V_39 , int V_40 )
{
return ( ( V_40 << 8 ) | V_39 ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned int V_56 ,
void T_2 * V_57 )
{
if ( V_2 -> V_58 != V_59 )
return V_60 [ V_2 -> V_58 ] -> F_29 ( V_2 -> V_58 , V_56 , V_57 ) ;
else
return - V_61 ;
}
static int F_30 ( int V_22 , unsigned int V_56 , void T_2 * V_57 )
{
struct V_1 * V_2 = V_60 [ V_22 ] -> V_2 ;
int V_62 = V_56 & 0xff ;
if ( ( V_62 != V_63 ) && ( V_62 != V_64 ) &&
( V_62 != V_65 ) && ( V_62 != V_66 ) &&
( V_62 != V_67 ) && ( V_62 != V_68 ) &&
( V_62 != V_69 ) && ( V_62 != V_70 ) &&
( V_62 != V_71 ) )
{
return F_28 ( V_2 , V_56 , V_57 ) ;
}
if ( ( ( V_56 >> 8 ) & 0xff ) != 'M' )
return - V_61 ;
if ( F_31 ( V_56 ) & V_72 )
{
switch ( V_62 )
{
case V_71 :
if ( V_2 -> V_58 != V_59 )
return F_28 ( V_2 , V_56 , V_57 ) ;
else
{
int V_73 ;
if ( F_24 ( V_73 , ( int T_2 * ) V_57 ) )
return - V_54 ;
if ( V_73 != 0 )
return - V_61 ;
return 0 ;
}
case V_63 :
if ( F_25 ( V_57 ,
& V_2 -> V_46 . V_47 ,
& V_2 -> V_46 . V_48 ) )
return - V_54 ;
F_18 ( V_2 , V_2 -> V_46 . V_47 ,
V_2 -> V_46 . V_48 ) ;
return F_27 ( V_2 -> V_46 . V_47 ,
V_2 -> V_46 . V_48 ) ;
case V_64 :
if ( F_23 ( V_57 , & V_2 -> V_46 . V_49 ) )
return - V_54 ;
F_20 ( V_2 , V_2 -> V_46 . V_49 ) ;
return F_26 ( V_2 -> V_46 . V_49 ) ;
case V_65 :
if ( F_23 ( V_57 , & V_2 -> V_46 . V_50 ) )
return - V_54 ;
F_21 ( V_2 , V_2 -> V_46 . V_50 ) ;
return F_26 ( V_2 -> V_46 . V_50 ) ;
case V_66 :
if ( F_23 ( V_57 , & V_2 -> V_46 . V_51 ) )
return - V_54 ;
F_19 ( V_2 , V_2 -> V_46 . V_51 ) ;
return F_26 ( V_2 -> V_46 . V_51 ) ;
default:
return - V_61 ;
}
}
else
{
int V_29 , V_74 = 0 , V_75 = 0 ;
switch ( V_62 )
{
case V_67 :
if ( F_28 ( V_2 , V_56 , V_57 ) == - V_61 )
break;
V_74 = ~ 0 ;
V_75 = V_76 | V_77 | V_78 | V_79 ;
break;
case V_68 :
if ( F_28 ( V_2 , V_56 , V_57 ) == - V_61 )
break;
V_74 = ~ 0 ;
V_75 = V_76 ;
break;
case V_69 :
if ( V_2 -> V_58 != V_59 )
return F_28 ( V_2 , V_56 , V_57 ) ;
break;
case V_70 :
if ( V_2 -> V_58 != V_59 )
return F_28 ( V_2 , V_56 , V_57 ) ;
V_75 = V_80 ;
break;
case V_71 :
if ( V_2 -> V_58 != V_59 )
return F_28 ( V_2 , V_56 , V_57 ) ;
break;
case V_63 :
V_75 = F_27 ( V_2 -> V_46 . V_47 , V_2 -> V_46 . V_48 ) ;
break;
case V_64 :
V_75 = F_26 ( V_2 -> V_46 . V_49 ) ;
break;
case V_65 :
V_75 = F_26 ( V_2 -> V_46 . V_50 ) ;
break;
case V_66 :
V_75 = F_26 ( V_2 -> V_46 . V_51 ) ;
break;
default:
return - V_61 ;
}
if ( F_24 ( V_29 , ( int T_2 * ) V_57 ) )
return - V_54 ;
V_29 &= V_74 ;
V_29 |= V_75 ;
if ( F_32 ( V_29 , ( int T_2 * ) V_57 ) )
return - V_54 ;
return V_29 ;
}
}
static void F_33 ( void )
{
F_5 ( 0x0000 , F_4 ( V_81 ) ) ;
F_5 ( 0x0000 , F_4 ( V_82 ) ) ;
F_5 ( 0x0000 , F_4 ( V_83 ) ) ;
F_5 ( 0x0000 , F_4 ( V_84 ) ) ;
F_5 ( 0x0000 , F_4 ( V_85 ) ) ;
}
static void F_34 ( void )
{
if( V_86 )
{
F_5 ( 0x0400 , F_4 ( V_81 ) ) ;
F_6 ( V_87 L_10 ) ;
}
else
{
F_6 ( V_87 L_11 ) ;
}
if ( V_88 == - 1 ) {
F_6 ( V_87 L_12 ) ;
} else if ( ! F_8 ( V_88 , 2 , L_13 ) ) {
V_88 = - 1 ;
F_6 ( V_20 L_14 ) ;
} else {
F_11 ( V_2 , V_85 , V_88 ) ;
F_6 ( V_87 L_15 , V_88 ) ;
}
}
static int T_1 F_35 ( struct V_12 * V_13 )
{
unsigned short V_14 ;
char V_24 [ 100 ] ;
V_2 -> V_17 = V_13 -> V_18 ;
V_2 -> V_15 = V_13 -> V_15 ;
V_2 -> V_16 = V_13 -> V_16 ;
V_2 -> V_19 = V_13 -> V_19 ;
V_2 -> V_58 = V_59 ;
if ( ! F_7 ( V_13 ) )
return 0 ;
V_14 = F_3 ( F_4 ( V_21 ) ) & 0x00ff ;
F_33 () ;
#ifdef F_36
if ( F_37 ( V_13 -> V_16 , L_16 ) )
{
F_6 ( L_17 ) ;
F_9 ( V_13 -> V_18 , 0x10 ) ;
F_9 ( V_13 -> V_18 + 0x10 , 0x9 ) ;
return 0 ;
}
if ( ! F_10 ( V_2 , V_81 , V_2 -> V_15 ) )
{
F_6 ( L_18 ) ;
F_9 ( V_13 -> V_18 , 0x10 ) ;
F_9 ( V_13 -> V_18 + 0x10 , 0x9 ) ;
return 0 ;
}
if ( ! F_12 ( V_2 , V_81 , V_2 -> V_16 ) )
{
F_6 ( V_20 L_19 ) ;
F_9 ( V_13 -> V_18 , 0x10 ) ;
F_9 ( V_13 -> V_18 + 0x10 , 0x9 ) ;
return 0 ;
}
#endif
F_34 () ;
V_89 = 1 ;
sprintf ( V_24 , L_20 , V_14 ) ;
F_38 ( V_24 , V_13 ) ;
return 1 ;
}
static int T_1 F_39 ( struct V_12 * V_13 )
{
struct V_90 * V_91 ;
int V_92 ;
if ( ! V_89 )
return 0 ;
V_91 = F_8 ( V_13 -> V_18 , 2 , L_21 ) ;
if ( ! V_91 ) {
F_6 ( V_20 L_22 ) ;
return 0 ;
}
F_11 ( V_2 , V_84 , V_13 -> V_18 ) ;
if ( ! F_10 ( V_2 , V_84 , V_13 -> V_15 ) ) {
F_6 ( V_20 L_23 ) ;
goto V_93;
}
if ( ! V_94 ) {
F_6 ( V_20 L_24 ) ;
goto V_93;
}
if ( ! F_17 ( V_2 , V_95 , V_94 , V_35 | V_36 ) ) {
F_6 ( V_20 L_25 ) ;
goto V_93;
}
for ( V_92 = 900000 ; V_92 > 0 ; V_92 -- )
{
if ( ( F_40 ( V_13 -> V_18 + 1 ) & 0x80 ) == 0 )
F_40 ( V_13 -> V_18 ) ;
else
break;
}
if ( ! F_41 ( V_13 , V_91 ) )
goto V_93;
F_42 ( V_13 , V_96 ) ;
if ( V_13 -> V_97 [ 1 ] != - 1 )
V_98 [ V_13 -> V_97 [ 1 ] ] -> V_99 = & V_100 ;
return 1 ;
V_93:
F_9 ( V_13 -> V_18 , 2 ) ;
return 0 ;
}
static int F_43 ( void * V_101 , int V_102 )
{
switch ( V_102 )
{
case V_103 :
if ( V_94 == 0 )
{
F_6 ( V_20 L_26 ) ;
return - V_104 ;
}
if ( V_105 )
if ( ! F_17 ( V_2 , V_95 , V_94 , V_35 | V_36 ) )
{
F_6 ( V_20 L_25 ) ;
return - V_104 ;
}
V_105 = 0 ;
break;
default:
break;
}
return 0 ;
}
static void F_44 ( void * V_101 , int V_102 )
{
return;
}
static void F_45 ( void * V_101 )
{
if ( V_94 )
if ( ! F_17 ( V_2 , V_95 , V_94 , V_35 | V_36 ) )
{
F_6 ( V_20 L_25 ) ;
}
V_105 = 0 ;
}
static int F_46 ( void * V_101 , T_3 * V_106 )
{
if ( V_106 -> V_107 <= 0 || V_106 -> V_107 > sizeof( V_106 -> V_3 ) )
return - V_61 ;
if ( ! F_17 ( V_2 , V_106 -> V_3 , V_106 -> V_107 , V_106 -> V_33 ) )
{
F_6 ( V_20 L_27 ) ;
return - V_104 ;
}
V_105 = 1 ;
return 0 ;
}
static int F_47 ( void * V_101 , unsigned int V_56 , void T_2 * V_57 , int V_108 )
{
T_3 * V_106 ;
T_4 * V_109 ;
T_5 V_110 ;
unsigned short V_24 ;
unsigned long V_33 ;
unsigned short * V_3 ;
int V_4 , V_111 ;
switch ( V_56 )
{
case V_112 :
F_45 ( V_101 ) ;
return 0 ;
case V_113 :
V_106 = F_48 ( sizeof( T_3 ) ) ;
if ( V_106 == NULL )
return - V_114 ;
if ( F_49 ( V_106 , V_57 , sizeof( T_3 ) ) ) {
F_50 ( V_106 ) ;
return - V_54 ;
}
V_111 = F_46 ( V_101 , V_106 ) ;
F_50 ( V_106 ) ;
return V_111 ;
case V_115 :
V_109 = F_48 ( sizeof( T_4 ) ) ;
if ( V_109 == NULL )
return - V_114 ;
if ( F_49 ( V_109 , V_57 , sizeof( T_4 ) ) ) {
F_50 ( V_109 ) ;
return - V_54 ;
}
V_3 = ( unsigned short * ) ( V_109 -> V_3 ) ;
F_51 ( & V_116 , V_33 ) ;
for ( V_4 = 0 ; V_4 < V_109 -> V_107 ; V_4 ++ ) {
if ( ! F_15 ( V_2 , * V_3 ++ ) ) {
F_52 ( & V_116 , V_33 ) ;
V_109 -> V_107 = V_4 ;
V_111 = F_53 ( V_57 , V_109 , sizeof( T_4 ) ) ;
F_50 ( V_109 ) ;
return V_111 ? - V_54 : - V_104 ;
}
}
F_52 ( & V_116 , V_33 ) ;
F_50 ( V_109 ) ;
return 0 ;
case V_117 :
V_111 = 0 ;
V_109 = F_48 ( sizeof( T_4 ) ) ;
if ( V_109 == NULL )
return - V_114 ;
V_3 = ( unsigned short * ) V_109 -> V_3 ;
F_51 ( & V_116 , V_33 ) ;
for ( V_4 = 0 ; V_4 < sizeof( V_109 -> V_3 ) /sizeof( unsigned short ) ; V_4 ++ ) {
V_109 -> V_107 = V_4 ;
if ( ! F_16 ( V_2 , V_3 ++ ) ) {
if ( V_4 == 0 )
V_111 = - V_104 ;
break;
}
}
F_52 ( & V_116 , V_33 ) ;
if ( F_53 ( V_57 , V_109 , sizeof( T_4 ) ) )
V_111 = - V_54 ;
F_50 ( V_109 ) ;
return V_111 ;
case V_118 :
if ( F_49 ( & V_110 , V_57 , sizeof( V_110 ) ) )
return - V_54 ;
F_51 ( & V_116 , V_33 ) ;
if ( ! F_15 ( V_2 , 0x00d0 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_15 ( V_2 , ( unsigned short ) ( V_110 . V_119 & 0xffff ) ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_16 ( V_2 , & V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_110 . V_119 = V_24 ;
F_52 ( & V_116 , V_33 ) ;
if ( F_53 ( V_57 , & V_110 , sizeof( V_110 ) ) )
return - V_54 ;
return 0 ;
case V_120 :
if ( F_49 ( & V_110 , V_57 , sizeof( V_110 ) ) )
return - V_54 ;
F_51 ( & V_116 , V_33 ) ;
if ( ! F_15 ( V_2 , 0x00d1 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_15 ( V_2 , ( unsigned short ) ( V_110 . V_119 & 0xffff ) ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_24 = ( unsigned int ) V_110 . V_121 & 0xffff ;
if ( ! F_15 ( V_2 , V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
F_52 ( & V_116 , V_33 ) ;
return 0 ;
case V_122 :
if ( F_49 ( & V_110 , V_57 , sizeof( V_110 ) ) )
return - V_54 ;
F_51 ( & V_116 , V_33 ) ;
if ( ! F_15 ( V_2 , 0x00d3 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_15 ( V_2 , ( unsigned short ) ( V_110 . V_119 & 0xffff ) ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_24 = ( unsigned int ) V_110 . V_121 & 0x00ff ;
if ( ! F_15 ( V_2 , V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_24 = ( ( unsigned int ) V_110 . V_121 >> 8 ) & 0xffff ;
if ( ! F_15 ( V_2 , V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
F_52 ( & V_116 , V_33 ) ;
return 0 ;
case V_123 :
if ( F_49 ( & V_110 , V_57 , sizeof( V_110 ) ) )
return - V_54 ;
F_51 ( & V_116 , V_33 ) ;
if ( ! F_15 ( V_2 , 0x00d2 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_15 ( V_2 , ( unsigned short ) ( V_110 . V_119 & 0xffff ) ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
if ( ! F_16 ( V_2 , & V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_110 . V_119 = V_24 << 8 ;
if ( ! F_16 ( V_2 , & V_24 ) ) {
F_52 ( & V_116 , V_33 ) ;
return - V_104 ;
}
V_110 . V_119 |= V_24 & 0x00ff ;
F_52 ( & V_116 , V_33 ) ;
if ( F_53 ( V_57 , & V_110 , sizeof( V_110 ) ) )
return - V_54 ;
return 0 ;
default:
return - V_61 ;
}
return - V_61 ;
}
static int T_1 F_54 ( struct V_12 * V_13 )
{
volatile int V_92 ;
struct V_90 * V_91 ;
int V_124 = - 999 ;
if ( ! V_89 )
return 0 ;
if ( ! F_8 ( V_13 -> V_18 , 4 , L_28 ) ) {
F_6 ( V_20 L_29 ) ;
return 0 ;
}
V_91 = F_8 ( V_13 -> V_18 + 4 , 4 , L_30 ) ;
if ( ! V_91 ) {
F_6 ( V_20 L_29 ) ;
F_9 ( V_13 -> V_18 , 4 ) ;
return 0 ;
}
F_11 ( V_2 , V_82 , V_13 -> V_18 ) ;
if ( ! F_10 ( V_2 , V_82 , V_13 -> V_15 ) ) {
F_6 ( L_31 ) ;
goto V_93;
}
if ( ! F_12 ( V_2 , V_82 , V_13 -> V_16 ) ) {
F_6 ( V_20 L_32 ) ;
goto V_93;
}
for ( V_92 = 0 ; V_92 < 100000 && ( F_40 ( V_13 -> V_18 + V_125 ) &
V_126 ) ; V_92 ++ )
;
F_55 ( ( 0x0b ) , V_13 -> V_18 + V_125 ) ;
for ( V_92 = 0 ; ( F_40 ( V_13 -> V_18 + V_127 ) & V_128 ) &&
( V_92 < 100000 ) ; V_92 ++ )
;
if ( ! F_56 ( V_13 , V_91 ) )
goto V_93;
V_2 -> V_58 = V_59 ;
if ( V_45 )
{
if ( ( V_124 = F_57 ( V_129 ,
L_33 ,
& V_130 ,
sizeof ( struct V_131 ) ,
V_2 ) ) < 0 )
{
F_6 ( V_20 L_34 ) ;
goto V_93;
}
}
F_22 ( V_2 ) ;
F_58 ( V_13 , V_91 , V_96 ) ;
if ( V_13 -> V_97 [ 0 ] != - 1 )
{
V_132 [ V_13 -> V_97 [ 0 ] ] -> V_99 = & V_100 ;
if ( V_45 && ( V_133 == ( V_124 + 2 ) ) )
{
V_2 -> V_58 = V_132 [ V_13 -> V_97 [ 0 ] ] -> V_134 ;
}
}
return 1 ;
V_93:
F_9 ( V_13 -> V_18 + 4 , 4 ) ;
F_9 ( V_13 -> V_18 , 4 ) ;
return 0 ;
}
static inline void T_6 F_59 ( struct V_12 * V_13 )
{
F_9 ( V_13 -> V_18 , 0x10 ) ;
F_9 ( V_13 -> V_18 + 0x10 , 0x9 ) ;
}
static inline void T_6 F_60 ( struct V_12 * V_13 )
{
F_61 ( V_13 ) ;
}
static inline void T_6 F_62 ( struct V_12 * V_13 )
{
F_63 ( V_13 ) ;
}
static int T_1 F_64 ( void )
{
if( V_135 )
{
V_136 . V_18 = V_137 ;
if( ! F_7 ( & V_136 ) )
return - V_138 ;
F_6 ( V_87 L_35 , F_3 ( F_4 ( V_21 ) ) & 0x00ff ) ;
F_6 ( V_87 L_36 ) ;
F_33 () ;
F_34 () ;
F_9 ( V_137 , 0x10 ) ;
F_9 ( V_137 + 0x10 , 0x9 ) ;
return 0 ;
}
V_136 . V_18 = V_137 ;
V_139 . V_18 = V_140 ;
V_139 . V_15 = V_141 ;
V_139 . V_16 = V_142 ;
V_143 . V_18 = V_144 ;
V_143 . V_15 = V_145 ;
if ( V_136 . V_18 == - 1 || V_139 . V_18 == - 1 || V_139 . V_15 == - 1 || V_136 . V_16 == - 1 ) {
F_6 ( V_87 L_37 ) ;
return - V_61 ;
}
if ( ! V_95 ) {
V_146 = 1 ;
V_94 = F_65 ( V_147 , ( void * ) & V_95 ) ;
}
if ( ! F_35 ( & V_136 ) )
return - V_138 ;
if ( F_39 ( & V_143 ) )
V_148 = 1 ;
if ( F_54 ( & V_139 ) )
V_149 = 1 ;
return 0 ;
}
static void T_6 F_66 ( void )
{
if( ! V_135 )
{
if( V_146 && V_95 )
F_50 ( V_95 ) ;
if( V_149 )
F_62 ( & V_139 ) ;
if( V_148 )
F_60 ( & V_143 ) ;
F_59 ( & V_136 ) ;
} else if ( V_88 != - 1 )
F_9 ( V_88 , 2 ) ;
if( ! V_150 )
{
F_33 () ;
F_6 ( V_87 L_38 ) ;
}
}
static int T_1 F_67 ( char * V_151 )
{
int V_152 [ 7 ] ;
V_151 = F_68 ( V_151 , F_69 ( V_152 ) , V_152 ) ;
V_137 = V_152 [ 1 ] ;
V_140 = V_152 [ 2 ] ;
V_141 = V_152 [ 3 ] ;
V_142 = V_152 [ 4 ] ;
V_144 = V_152 [ 5 ] ;
V_145 = V_152 [ 6 ] ;
return 1 ;
}
