static void T_1 F_1 ( struct V_1 * V_2 )
{
T_2 V_3 ;
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_7 ) {
V_3 &= ~ V_7 ;
F_3 ( V_6 , V_3 ) ;
V_2 -> V_8 = F_4 ( 0 ) ;
F_5 ( V_2 ) ;
}
}
if ( ( V_2 -> V_4 == 0xf && V_2 -> V_5 >= 0x03 ) ||
( V_2 -> V_4 == 0x6 && V_2 -> V_5 >= 0x0e ) )
F_6 ( V_2 , V_9 ) ;
if ( V_2 -> V_4 >= 6 && ! F_7 ( V_2 , V_10 ) ) {
unsigned V_11 ;
F_8 ( V_12 , 0 , 0 ) ;
F_9 () ;
F_10 ( V_12 , V_11 , V_2 -> V_13 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 0x1c && V_2 -> V_14 <= 2 &&
V_2 -> V_13 < 0x20e ) {
F_11 ( V_15 L_1 ) ;
F_12 ( V_2 , V_16 ) ;
}
#ifdef F_13
F_6 ( V_2 , V_17 ) ;
#else
if ( V_2 -> V_4 == 15 && V_2 -> V_18 == 64 )
V_2 -> V_18 = 128 ;
#endif
if ( V_2 -> V_4 == 0xF && V_2 -> V_5 == 0x3
&& ( V_2 -> V_14 == 0x3 || V_2 -> V_14 == 0x4 ) )
V_2 -> V_19 = 36 ;
if ( V_2 -> V_20 & ( 1 << 8 ) ) {
F_6 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_21 ) ;
if ( ! F_14 () )
V_22 = 1 ;
}
if ( V_2 -> V_4 == 6 ) {
switch ( V_2 -> V_5 ) {
case 0x27 :
case 0x35 :
F_6 ( V_2 , V_23 ) ;
break;
default:
break;
}
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_12 ( V_2 , V_24 ) ;
#ifdef F_15
if ( V_2 -> V_4 == 15 ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_25 ) {
F_11 ( V_26 L_2 ) ;
V_3 &= ~ V_25 ;
F_3 ( V_6 , V_3 ) ;
}
}
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_25 ) ) {
F_11 ( V_26 L_3 ) ;
F_16 ( V_27 ) ;
F_16 ( V_28 ) ;
}
}
}
int T_1 F_17 ( void )
{
if ( V_29 . V_30 == V_31 &&
V_29 . V_4 == 6 &&
V_29 . V_5 == 1 &&
V_29 . V_14 < 8 ) {
F_11 ( V_26 L_4 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_32 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_19 ( 1 , L_5
L_6 ) ;
}
}
static void T_1 F_20 ( struct V_1 * V_2 )
{
unsigned long V_33 , V_34 ;
#ifdef F_21
F_22 ( V_2 , V_35 ) ;
if ( ! F_23 () && V_2 -> V_4 == 5 ) {
static int V_36 ;
F_24 ( V_2 , V_35 ) ;
if ( ! V_36 ) {
F_11 ( V_37 L_7 ) ;
V_36 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_12 ( V_2 , V_38 ) ;
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
F_10 ( V_6 , V_33 , V_34 ) ;
if ( ( V_33 & V_39 ) == 0 ) {
F_11 ( V_26 L_8 ) ;
F_11 ( V_26 L_9 ) ;
V_33 |= V_39 ;
F_8 ( V_6 , V_33 , V_34 ) ;
}
}
if ( V_40 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_6 ( V_2 , V_41 ) ;
#ifdef F_25
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_42 . V_43 = 7 ;
break;
case 15 :
V_42 . V_43 = 7 ;
break;
}
#endif
#ifdef F_26
F_27 () ;
#endif
F_18 ( V_2 ) ;
}
static void T_1 F_20 ( struct V_1 * V_2 )
{
}
static void T_1 F_28 ( struct V_1 * V_2 )
{
#ifdef F_29
unsigned V_44 ;
int V_45 = F_30 () ;
V_44 = F_31 ( V_45 ) ;
if ( V_44 == V_46 || ! F_32 ( V_44 ) ) {
V_44 = F_33 ( V_45 ) ;
}
F_34 ( V_45 , V_44 ) ;
#endif
}
static int T_1 F_35 ( struct V_1 * V_2 )
{
unsigned int V_47 , V_48 , V_49 , V_50 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_36 ( 4 , 0 , & V_47 , & V_48 , & V_49 , & V_50 ) ;
if ( V_47 & 0x1f )
return ( V_47 >> 26 ) + 1 ;
else
return 1 ;
}
static void T_1 F_37 ( struct V_1 * V_2 )
{
#define F_38 0x00200000
#define F_39 0x00400000
#define F_40 0x80000000
#define F_41 0x00000001
#define F_42 0x00000002
#define F_43 0x00000020
T_3 V_51 , V_52 , V_53 , V_54 ;
F_12 ( V_2 , V_55 ) ;
F_12 ( V_2 , V_56 ) ;
F_12 ( V_2 , V_57 ) ;
F_12 ( V_2 , V_58 ) ;
F_12 ( V_2 , V_59 ) ;
F_10 ( V_60 , V_51 , V_52 ) ;
V_53 = V_52 | V_51 ;
if ( V_53 & F_38 )
F_6 ( V_2 , V_55 ) ;
if ( V_53 & F_39 )
F_6 ( V_2 , V_56 ) ;
if ( V_53 & F_40 ) {
F_10 ( V_61 ,
V_51 , V_52 ) ;
V_54 = V_52 | V_51 ;
if ( ( V_54 & F_41 ) &&
( V_53 & F_38 ) )
F_6 ( V_2 , V_57 ) ;
if ( V_54 & F_42 )
F_6 ( V_2 , V_58 ) ;
if ( V_54 & F_43 )
F_6 ( V_2 , V_59 ) ;
}
}
static void T_1 F_44 ( struct V_1 * V_2 )
{
unsigned int V_62 = 0 ;
F_1 ( V_2 ) ;
F_20 ( V_2 ) ;
F_45 ( V_2 ) ;
V_62 = F_46 ( V_2 ) ;
if ( V_2 -> V_8 > 9 ) {
unsigned V_47 = F_4 ( 10 ) ;
if ( ( V_47 & 0xff ) && ( ( ( V_47 >> 8 ) & 0xff ) > 1 ) )
F_6 ( V_2 , V_63 ) ;
}
if ( V_64 )
F_6 ( V_2 , V_65 ) ;
if ( V_66 ) {
unsigned int V_67 ;
F_10 ( V_6 , V_67 , V_62 ) ;
if ( ! ( V_67 & ( 1 << 11 ) ) )
F_6 ( V_2 , V_68 ) ;
if ( ! ( V_67 & ( 1 << 12 ) ) )
F_6 ( V_2 , V_69 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 29 && V_70 )
F_6 ( V_2 , V_71 ) ;
#ifdef F_13
if ( V_2 -> V_4 == 15 )
V_2 -> V_18 = V_2 -> V_72 * 2 ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_27 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_73 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_62 == 0 )
V_73 = L_10 ;
else if ( V_62 == 256 )
V_73 = L_11 ;
break;
case 6 :
if ( V_62 == 128 )
V_73 = L_12 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_73 = L_13 ;
break;
case 8 :
if ( V_62 == 128 )
V_73 = L_14 ;
break;
}
if ( V_73 )
strcpy ( V_2 -> V_74 , V_73 ) ;
}
if ( V_2 -> V_4 == 15 )
F_6 ( V_2 , V_75 ) ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_76 ) ;
#endif
if ( ! F_7 ( V_2 , V_77 ) ) {
V_2 -> V_78 = F_35 ( V_2 ) ;
#ifdef F_47
F_48 ( V_2 ) ;
#endif
}
F_28 ( V_2 ) ;
if ( F_7 ( V_2 , V_79 ) )
F_37 ( V_2 ) ;
if ( F_7 ( V_2 , V_80 ) ) {
T_2 V_81 ;
F_2 ( V_82 , V_81 ) ;
if ( ( V_81 & 0xF ) == V_83 ) {
F_49 ( V_15 L_15
L_16
L_17
L_18 ) ;
V_81 = ( V_81 & ~ 0xF ) | V_84 ;
F_3 ( V_82 , V_81 ) ;
}
}
}
static unsigned int T_1 F_50 ( struct V_1 * V_2 , unsigned int V_85 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_85 == 0 ) )
V_85 = 256 ;
return V_85 ;
}
static void T_1 F_51 ( const unsigned char V_86 )
{
unsigned char V_87 ;
if ( V_86 == 0 )
return;
for ( V_87 = 0 ; V_88 [ V_87 ] . V_89 != V_86 && \
V_88 [ V_87 ] . V_89 != 0 ; V_87 ++ )
;
if ( V_88 [ V_87 ] . V_90 == 0 )
return;
switch ( V_88 [ V_87 ] . V_90 ) {
case V_91 :
if ( V_92 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_92 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_95 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_95 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_96 :
if ( V_92 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_92 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_97 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_97 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_98 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_98 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_99 :
if ( V_92 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_92 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_100 :
if ( V_98 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_98 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_101 :
if ( V_97 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_97 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_98 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_98 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_102 :
case V_103 :
if ( V_95 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_95 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_104 :
case V_105 :
if ( V_106 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_106 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_107 :
case V_108 :
if ( V_109 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_109 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_106 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_106 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
case V_110 :
if ( V_95 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_95 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
if ( V_106 [ V_93 ] < V_88 [ V_87 ] . V_94 )
V_106 [ V_93 ] = V_88 [ V_87 ] . V_94 ;
break;
}
}
static void T_1 F_52 ( struct V_1 * V_2 )
{
switch ( ( V_2 -> V_4 << 8 ) + V_2 -> V_5 ) {
case 0x60f :
case 0x616 :
case 0x617 :
case 0x61d :
V_111 = - 1 ;
break;
case 0x61a :
case 0x61e :
case 0x625 :
case 0x62c :
case 0x62e :
case 0x62f :
V_111 = 6 ;
break;
case 0x62a :
case 0x62d :
V_111 = 5 ;
break;
case 0x63a :
V_111 = 1 ;
break;
default:
V_111 = 6 ;
}
}
static void T_1 F_53 ( struct V_1 * V_2 )
{
int V_112 , V_113 , V_114 ;
unsigned int V_115 [ 4 ] ;
unsigned char * V_86 = ( unsigned char * ) V_115 ;
if ( V_2 -> V_8 < 2 )
return;
V_114 = F_4 ( 2 ) & 0xFF ;
for ( V_112 = 0 ; V_112 < V_114 ; V_112 ++ ) {
F_54 ( 2 , & V_115 [ 0 ] , & V_115 [ 1 ] , & V_115 [ 2 ] , & V_115 [ 3 ] ) ;
for ( V_113 = 0 ; V_113 < 3 ; V_113 ++ )
if ( V_115 [ V_113 ] & ( 1 << 31 ) )
V_115 [ V_113 ] = 0 ;
for ( V_113 = 1 ; V_113 < 16 ; V_113 ++ )
F_51 ( V_86 [ V_113 ] ) ;
}
F_52 ( V_2 ) ;
}
