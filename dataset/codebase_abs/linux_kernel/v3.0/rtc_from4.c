static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = ( V_2 -> V_7 ) ;
if ( V_3 == V_8 )
return;
if ( V_4 & V_9 )
F_2 ( V_3 , V_6 -> V_10 | V_11 ) ;
else
F_2 ( V_3 , V_6 -> V_10 | V_12 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 )
{
struct V_5 * V_13 = V_2 -> V_7 ;
V_13 -> V_14 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_14 & ~ V_16 ) ;
V_13 -> V_10 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_10 & ~ V_16 ) ;
switch ( V_6 ) {
case 0 :
V_13 -> V_14 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_14 | V_17 ) ;
V_13 -> V_10 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_10 | V_17 ) ;
break;
case 1 :
V_13 -> V_14 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_14 | V_18 ) ;
V_13 -> V_10 = ( void V_15 * ) ( ( unsigned long ) V_13 -> V_10 | V_18 ) ;
break;
}
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned short V_19 ;
V_19 = * ( ( volatile unsigned short * ) ( V_20 + V_21 ) ) ;
return ( V_19 & V_22 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
struct V_5 * V_13 = V_2 -> V_7 ;
while ( ! V_13 -> V_23 ( V_2 ) ) ;
V_13 -> V_24 ( V_2 , V_6 ) ;
V_13 -> V_25 ( V_2 , V_26 , 0x0000 , 0x0000 ) ;
V_13 -> V_25 ( V_2 , V_27 , - 1 , - 1 ) ;
V_13 -> V_25 ( V_2 , V_26 , 0x0000 , 0x0004 ) ;
V_13 -> V_25 ( V_2 , V_27 , - 1 , - 1 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_28 )
{
volatile unsigned short * V_29 = ( volatile unsigned short * ) ( V_20 + V_30 ) ;
unsigned short V_19 ;
switch ( V_28 ) {
case V_31 :
V_19 = V_32 | V_33 ;
* V_29 = V_19 ;
break;
case V_34 :
V_19 = 0x00 ;
* V_29 = V_19 ;
break;
case V_35 :
V_19 = V_32 | V_36 | V_33 ;
* V_29 = V_19 ;
break;
default:
F_7 () ;
break;
}
}
static void F_8 ( struct V_1 * V_2 , const T_1 * V_37 , T_1 * V_38 )
{
volatile unsigned short * V_39 = ( volatile unsigned short * ) ( V_20 + V_40 ) ;
unsigned short V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_41 = * V_39 ;
V_38 [ V_42 ] = ( unsigned char ) V_41 ;
V_39 ++ ;
}
V_38 [ 7 ] |= 0x0f ;
}
static int F_9 ( struct V_1 * V_2 , const T_1 * V_43 , T_1 * V_44 , T_1 * V_45 )
{
int V_42 , V_46 , V_47 ;
unsigned short V_19 ;
T_2 V_48 [ 6 ] , V_49 [ 6 ] ;
T_3 V_50 [ 8 ] ;
volatile unsigned short * V_51 ;
V_19 = * ( ( volatile unsigned short * ) ( V_20 + V_52 ) ) ;
if ( ! ( V_19 & V_53 ) ) {
return 0 ;
}
V_51 = ( volatile unsigned short * ) ( V_20 + V_54 ) ;
for ( V_42 = 0 ; V_42 < 8 ; V_42 ++ ) {
V_50 [ V_42 ] = F_10 ( * V_51 ) ;
V_51 ++ ;
}
V_48 [ 5 ] = V_55 -> V_56 [ ( ( ( T_2 ) V_50 [ 0 ] >> 0 ) & 0x0ff ) | ( ( ( T_2 ) V_50 [ 1 ] << 8 ) & 0x300 ) ] ;
V_48 [ 4 ] = V_55 -> V_56 [ ( ( ( T_2 ) V_50 [ 1 ] >> 2 ) & 0x03f ) | ( ( ( T_2 ) V_50 [ 2 ] << 6 ) & 0x3c0 ) ] ;
V_48 [ 3 ] = V_55 -> V_56 [ ( ( ( T_2 ) V_50 [ 2 ] >> 4 ) & 0x00f ) | ( ( ( T_2 ) V_50 [ 3 ] << 4 ) & 0x3f0 ) ] ;
V_48 [ 2 ] = V_55 -> V_56 [ ( ( ( T_2 ) V_50 [ 3 ] >> 6 ) & 0x003 ) | ( ( ( T_2 ) V_50 [ 4 ] << 2 ) & 0x3fc ) ] ;
V_48 [ 1 ] = V_55 -> V_56 [ ( ( ( T_2 ) V_50 [ 5 ] >> 0 ) & 0x0ff ) | ( ( ( T_2 ) V_50 [ 6 ] << 8 ) & 0x300 ) ] ;
V_48 [ 0 ] = ( ( ( T_2 ) V_50 [ 6 ] >> 2 ) & 0x03f ) | ( ( ( T_2 ) V_50 [ 7 ] << 6 ) & 0x3c0 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ ) {
V_49 [ V_42 ] = V_48 [ 0 ] ;
for ( V_46 = 1 ; V_46 < 6 ; V_46 ++ )
if ( V_48 [ V_46 ] != V_55 -> V_57 )
V_49 [ V_42 ] ^= V_55 -> V_58 [ F_11 ( V_55 , V_48 [ V_46 ] + V_42 * V_46 ) ] ;
V_49 [ V_42 ] = V_55 -> V_56 [ V_49 [ V_42 ] ] ;
}
V_47 = F_12 ( V_55 , ( T_3 * ) V_43 , V_48 , 512 , V_49 , 0 , NULL , 0xff , NULL ) ;
if ( V_47 > 0 ) {
F_13 ( V_59 , L_1 L_2 , V_47 ) ;
}
return V_47 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_13 ,
int V_60 , int V_19 , int V_61 )
{
int V_62 = 0 ;
int V_63 , V_64 ;
T_4 V_65 ;
T_3 * V_43 ;
int V_42 ;
V_13 -> V_25 ( V_2 , V_66 , - 1 , - 1 ) ;
if ( V_60 == V_67 ) {
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( ! ( V_19 & 1 << ( V_42 + 1 ) ) )
continue;
V_13 -> V_25 ( V_2 , ( V_68 + V_42 + 1 ) ,
- 1 , - 1 ) ;
V_63 = V_13 -> V_69 ( V_2 ) ;
V_13 -> V_25 ( V_2 , V_70 , - 1 , - 1 ) ;
if ( ! ( V_63 & V_71 ) )
V_62 |= 1 << ( V_42 + 1 ) ;
}
} else if ( V_60 == V_72 ) {
unsigned long V_73 = V_2 -> V_74 . V_73 ;
V_13 -> V_25 ( V_2 , V_68 , - 1 , - 1 ) ;
V_63 = V_13 -> V_69 ( V_2 ) ;
V_13 -> V_25 ( V_2 , V_70 , - 1 , - 1 ) ;
if ( ! ( V_63 & V_71 ) ) {
V_62 |= 1 << 1 ;
goto V_75;
}
V_65 = V_2 -> V_76 ;
V_43 = F_15 ( V_65 , V_77 ) ;
if ( ! V_43 ) {
F_16 ( V_78 L_3 ) ;
V_62 = 1 ;
goto V_75;
}
V_63 = F_17 ( V_2 , V_61 , V_65 , & V_64 , V_43 ) ;
if ( V_63 || ( V_2 -> V_74 . V_73 - V_73 ) > 1 )
V_62 |= 1 << 1 ;
F_18 ( V_43 ) ;
}
V_75:
V_63 = V_19 ;
if ( V_62 == 0 ) {
V_63 = ( V_19 & ~ V_79 ) ;
}
return V_63 ;
}
static int T_5 F_19 ( void )
{
struct V_5 * V_13 ;
unsigned short V_80 , V_81 , V_82 ;
int V_42 ;
int V_83 ;
V_84 = F_15 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_77 ) ;
if ( ! V_84 ) {
F_16 ( L_4 ) ;
return - V_85 ;
}
V_13 = (struct V_5 * ) ( & V_84 [ 1 ] ) ;
memset ( V_84 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_13 , 0 , sizeof( struct V_5 ) ) ;
V_84 -> V_7 = V_13 ;
V_84 -> V_86 = V_87 ;
V_80 = * V_88 & ~ 0x0002 ;
V_80 |= 0x0002 ;
* V_88 = V_80 ;
V_81 = * V_89 & ~ 0x0c00 ;
V_81 |= 0x0800 ;
* V_89 = V_81 ;
V_82 = * V_90 & ~ 0x1c00 ;
V_82 |= 0x1c00 ;
* V_90 = V_82 ;
V_13 -> V_14 = V_20 ;
V_13 -> V_10 = V_20 ;
V_13 -> V_91 = F_1 ;
V_13 -> V_24 = F_3 ;
V_13 -> V_92 = 100 ;
V_13 -> V_23 = F_4 ;
#ifdef F_20
F_16 ( V_93 L_5 ) ;
V_13 -> V_50 . V_28 = V_94 ;
V_13 -> V_50 . V_95 = 512 ;
V_13 -> V_50 . V_96 = 8 ;
V_13 -> V_97 = F_14 ;
V_13 -> V_50 . V_98 = & V_99 ;
V_13 -> V_50 . V_100 = F_6 ;
V_13 -> V_50 . V_101 = F_8 ;
V_13 -> V_50 . V_102 = F_9 ;
V_55 = F_21 ( 10 , 0x409 , 0 , 1 , 6 ) ;
if ( ! V_55 ) {
F_16 ( V_78 L_6 ) ;
V_83 = - V_85 ;
goto V_103;
}
#else
F_16 ( V_93 L_7 ) ;
V_13 -> V_50 . V_28 = V_104 ;
#endif
V_13 -> V_105 = & V_106 ;
V_13 -> V_107 = & V_108 ;
if ( F_22 ( V_84 , V_109 ) ) {
V_83 = - V_110 ;
goto V_111;
}
for ( V_42 = 0 ; V_42 < V_13 -> V_112 ; V_42 ++ ) {
F_5 ( V_84 , V_42 ) ;
}
#if V_113
V_84 -> V_114 |= V_115 ;
#endif
V_83 = F_23 ( V_84 , V_116 ,
V_117 ) ;
if ( V_83 )
goto V_118;
return 0 ;
V_118:
F_24 ( V_84 ) ;
V_111:
F_25 ( V_55 ) ;
V_103:
F_18 ( V_84 ) ;
return V_83 ;
}
static void T_6 F_26 ( void )
{
F_24 ( V_84 ) ;
F_18 ( V_84 ) ;
#ifdef F_20
if ( V_55 ) {
F_25 ( V_55 ) ;
}
#endif
}
