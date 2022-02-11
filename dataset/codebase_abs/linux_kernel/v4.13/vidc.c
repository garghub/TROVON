static void
F_1 ( int V_1 , unsigned int V_2 )
{
unsigned int V_3 = V_2 & 0x007f ;
unsigned int V_4 = ( V_2 & 0x7f00 ) >> 8 ;
unsigned int V_5 , V_6 ;
if ( V_3 > 100 )
V_3 = 100 ;
if ( V_4 > 100 )
V_4 = 100 ;
#define F_2 ( T_1 , T_2 ) ((lev) * (master) * 65536 / 10000)
V_5 = V_7 [ V_8 ] ;
V_6 = V_9 [ V_8 ] ;
switch ( V_1 ) {
case V_8 :
case V_10 :
V_7 [ V_1 ] = V_3 ;
V_9 [ V_1 ] = V_4 ;
V_11 = F_2 ( V_3 , V_5 ) ;
V_12 = F_2 ( V_4 , V_6 ) ;
break;
}
#undef F_2
}
static int F_3 ( int V_13 , unsigned int V_14 , void T_3 * V_15 )
{
unsigned int V_16 ;
unsigned int V_1 ;
if ( F_4 ( V_14 ) != 'M' )
return - V_17 ;
V_1 = F_5 ( V_14 ) ;
if ( F_6 ( V_14 ) & V_18 ) {
if ( F_7 ( V_16 , ( unsigned int T_3 * ) V_15 ) )
return - V_19 ;
if ( V_1 < V_20 )
F_1 ( V_1 , V_16 ) ;
else
return - V_17 ;
}
switch ( V_1 ) {
case V_21 :
V_16 = 0 ;
break;
case V_22 :
V_16 = V_23 | V_24 | V_25 ;
break;
case V_26 :
V_16 = V_23 | V_24 | V_25 ;
break;
case V_27 :
V_16 = 0 ;
break;
case V_28 :
V_16 = 0 ;
break;
default:
if ( V_1 < V_20 )
V_16 = V_7 [ V_1 ] | V_9 [ V_1 ] << 8 ;
else
return - V_17 ;
}
return F_8 ( V_16 , ( unsigned int T_3 * ) V_15 ) ? - V_19 : 0 ;
}
static unsigned int F_9 ( int V_13 , unsigned int V_29 )
{
switch ( V_29 ) {
default:
V_29 = V_30 ;
case V_31 :
case V_32 :
case V_30 :
V_33 = V_29 ;
F_10 ( V_33 , V_34 ) ;
case V_35 :
break;
}
return V_33 ;
}
static int F_11 ( int V_13 , int V_36 )
{
if ( V_36 ) {
unsigned int V_37 , V_38 , V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 ;
unsigned int V_44 , V_45 ;
V_37 = 0x00000003 ;
V_38 = ( ( ( V_46 * 2 ) / V_36 ) + 1 ) >> 1 ;
if ( V_38 < 3 )
V_38 = 3 ;
if ( V_38 > 255 )
V_38 = 255 ;
V_39 = ( ( ( V_47 * 2 ) / V_36 ) + 1 ) >> 1 ;
if ( V_39 < 3 )
V_39 = 3 ;
if ( V_39 > 255 )
V_39 = 255 ;
V_40 = V_46 / V_38 ;
V_41 = V_47 / V_39 ;
V_42 = F_12 ( V_41 - V_36 ) ;
V_43 = F_12 ( V_40 - V_36 ) ;
if ( V_43 < V_42 ) {
V_38 = V_39 ;
V_37 = 0x00000002 ;
if ( V_43 > ( V_36 / 256 ) )
V_36 = V_41 ;
} else {
V_37 = 0x00000003 ;
if ( V_42 > ( V_36 / 256 ) )
V_36 = V_40 ;
}
F_13 ( 0xb0000000 | ( V_38 - 2 ) ) ;
F_13 ( 0xb1000000 | V_37 ) ;
V_44 = ( 10000 / V_38 ) & ~ 3 ;
if ( V_44 < 208 )
V_44 = 208 ;
if ( V_44 > 4096 )
V_44 = 4096 ;
for ( V_45 = 128 ; V_45 < V_44 ; V_45 <<= 1 ) ;
if ( V_45 - V_44 > V_44 - ( V_45 >> 1 ) )
V_45 >>= 1 ;
if ( V_45 > 4096 ) {
F_14 ( V_48 L_1 ,
V_44 , V_45 ) ;
V_45 = 4096 ;
}
V_49 = V_45 ;
V_50 = V_36 ;
}
return V_50 ;
}
static short F_15 ( int V_13 , short V_51 )
{
switch ( V_51 ) {
default:
V_51 = 2 ;
case 1 :
case 2 :
V_34 = V_51 ;
F_10 ( V_33 , V_34 ) ;
case 0 :
break;
}
return V_34 ;
}
static int F_16 ( int V_13 , int V_52 )
{
if ( V_52 == V_53 )
return - V_54 ;
if ( V_55 )
return - V_56 ;
V_55 = 1 ;
return 0 ;
}
static void F_17 ( int V_13 )
{
V_55 = 0 ;
}
static void
F_18 ( int V_13 , unsigned long V_57 , int V_58 , int V_59 )
{
struct V_60 * V_61 = V_62 [ V_13 ] -> V_63 ;
unsigned long V_64 ;
F_19 ( V_64 ) ;
V_65 = V_57 - ( unsigned long ) V_61 -> V_66 + ( unsigned long ) V_61 -> V_67 ;
V_68 = V_58 ;
F_20 ( V_64 ) ;
}
static void
F_21 ( int V_13 , unsigned long V_57 , int V_69 , int V_70 )
{
}
static int F_22 ( int V_13 , int V_71 , int V_72 )
{
return - V_17 ;
}
static T_4 F_23 ( void )
{
F_24 ( V_73 , 1 ) ;
return V_74 ;
}
static int F_25 ( int V_13 , int V_71 , int V_72 )
{
struct V_75 * V_76 = V_62 [ V_13 ] ;
V_77 = NULL ;
V_76 -> V_63 -> V_64 |= V_78 ;
return 0 ;
}
static void F_26 ( int V_13 )
{
V_77 = NULL ;
}
static int F_27 ( int V_13 )
{
return 0 ;
}
static void F_28 ( int V_13 , int V_79 )
{
struct V_75 * V_76 = V_62 [ V_13 ] ;
if ( V_79 & V_80 ) {
if ( ! ( V_76 -> V_63 -> V_64 & V_81 ) ) {
unsigned long V_64 ;
F_19 ( V_64 ) ;
V_76 -> V_63 -> V_64 |= V_81 ;
V_77 = F_23 ;
F_29 ( 0 , NULL ) ;
F_30 ( V_82 | 0x10 , V_83 ) ;
F_20 ( V_64 ) ;
}
}
}
void F_10 ( int V_84 , int V_51 )
{
#define TYPE ( V_29 , T_5 ) (((fmt)<<2) | ((ch)&3))
switch ( TYPE ( V_84 , V_51 ) ) {
default:
case TYPE ( V_31 , 1 ) :
V_85 = V_86 ;
break;
case TYPE ( V_31 , 2 ) :
V_85 = V_87 ;
break;
case TYPE ( V_32 , 1 ) :
V_85 = V_88 ;
break;
case TYPE ( V_32 , 2 ) :
V_85 = V_89 ;
break;
case TYPE ( V_30 , 1 ) :
V_85 = V_90 ;
break;
case TYPE ( V_30 , 2 ) :
V_85 = V_91 ;
break;
}
}
static void T_6 F_31 ( struct V_92 * V_93 )
{
char V_94 [ 32 ] ;
int V_95 , V_76 ;
sprintf ( V_94 , L_2 , V_93 -> V_96 ) ;
F_32 ( V_94 , V_93 ) ;
memset ( V_97 , 0 , sizeof( V_97 ) ) ;
V_76 = F_33 ( V_98 , V_94 ,
& V_99 , sizeof( V_99 ) ,
V_100 , V_31 | V_32 | V_30 ,
NULL , V_93 -> V_101 , V_93 -> V_102 ) ;
if ( V_76 < 0 )
goto V_103;
V_62 [ V_76 ] -> V_104 = 10 ;
V_62 [ V_76 ] -> V_105 = V_106 ;
V_62 [ V_76 ] -> V_105 =
F_34 ( V_107 ,
V_94 , & V_108 ,
sizeof( V_108 ) , NULL ) ;
if ( V_62 [ V_76 ] -> V_105 < 0 )
goto V_109;
for ( V_95 = 0 ; V_95 < 2 ; V_95 ++ ) {
V_97 [ V_95 ] = F_35 ( V_110 ) ;
if ( ! V_97 [ V_95 ] ) {
F_14 ( V_48 L_3 ,
V_94 ) ;
goto V_111;
}
V_112 [ V_95 ] = F_36 ( ( void * ) V_97 [ V_95 ] ) ;
}
if ( F_37 ( V_93 -> V_101 , V_93 -> V_94 ) ) {
F_14 ( V_48 L_4 , V_94 , V_93 -> V_101 ) ;
goto V_113;
}
if ( F_38 ( V_93 -> V_114 , F_29 , 0 ,
V_93 -> V_94 , & V_65 ) ) {
F_14 ( V_48 L_5 , V_94 , V_93 -> V_114 ) ;
goto V_115;
}
V_73 = V_76 ;
F_1 ( V_8 , ( 85 | 85 << 8 ) ) ;
return;
V_115:
F_39 ( V_93 -> V_101 ) ;
V_113:
V_111:
for ( V_95 = 0 ; V_95 < 2 ; V_95 ++ )
F_40 ( V_97 [ V_95 ] ) ;
F_41 ( V_62 [ V_76 ] -> V_105 ) ;
V_109:
F_42 ( V_76 ) ;
V_103:
return;
}
static int T_6 F_43 ( struct V_92 * V_93 )
{
V_93 -> V_114 = V_116 ;
V_93 -> V_101 = V_117 ;
V_93 -> V_102 = - 1 ;
V_93 -> V_96 = 16 ;
V_93 -> V_94 = L_6 ;
return 1 ;
}
static void T_7 F_44 ( struct V_92 * V_93 )
{
int V_95 , V_76 = V_73 ;
V_73 = - 1 ;
F_45 ( V_93 -> V_114 , & V_65 ) ;
F_39 ( V_93 -> V_101 ) ;
if ( V_76 >= 0 ) {
F_41 ( V_62 [ V_76 ] -> V_105 ) ;
F_42 ( V_76 ) ;
for ( V_95 = 0 ; V_95 < 2 ; V_95 ++ )
F_40 ( V_97 [ V_95 ] ) ;
}
}
static int T_6 F_46 ( void )
{
if ( F_43 ( & V_118 ) == 0 )
return - V_119 ;
F_31 ( & V_118 ) ;
return 0 ;
}
static void T_7 F_47 ( void )
{
F_44 ( & V_118 ) ;
}
