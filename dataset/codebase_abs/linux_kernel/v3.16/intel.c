static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
if ( F_2 ( V_6 ,
V_7 ) > 0 ) {
V_2 -> V_8 = F_3 ( 0 ) ;
F_4 ( V_2 ) ;
}
}
if ( ( V_2 -> V_4 == 0xf && V_2 -> V_5 >= 0x03 ) ||
( V_2 -> V_4 == 0x6 && V_2 -> V_5 >= 0x0e ) )
F_5 ( V_2 , V_9 ) ;
if ( V_2 -> V_4 >= 6 && ! F_6 ( V_2 , V_10 ) ) {
unsigned V_11 ;
F_7 ( V_12 , 0 , 0 ) ;
F_8 () ;
F_9 ( V_12 , V_11 , V_2 -> V_13 ) ;
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 == 0x1c && V_2 -> V_14 <= 2 &&
V_2 -> V_13 < 0x20e ) {
F_10 ( V_15 L_1 ) ;
F_11 ( V_2 , V_16 ) ;
}
#ifdef F_12
F_5 ( V_2 , V_17 ) ;
#else
if ( V_2 -> V_4 == 15 && V_2 -> V_18 == 64 )
V_2 -> V_18 = 128 ;
#endif
if ( V_2 -> V_4 == 0xF && V_2 -> V_5 == 0x3
&& ( V_2 -> V_14 == 0x3 || V_2 -> V_14 == 0x4 ) )
V_2 -> V_19 = 36 ;
if ( V_2 -> V_20 & ( 1 << 8 ) ) {
F_5 ( V_2 , V_9 ) ;
F_5 ( V_2 , V_21 ) ;
if ( ! F_13 () )
F_14 () ;
}
if ( V_2 -> V_4 == 6 ) {
switch ( V_2 -> V_5 ) {
case 0x27 :
case 0x35 :
F_5 ( V_2 , V_22 ) ;
break;
default:
break;
}
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_11 ( V_2 , V_23 ) ;
#ifdef F_15
if ( V_2 -> V_4 == 15 )
if ( F_2 ( V_6 ,
V_24 ) > 0 )
F_16 ( L_2 ) ;
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_17 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_25 ) ) {
F_10 ( V_26 L_3 ) ;
F_18 ( V_27 ) ;
F_18 ( V_28 ) ;
}
}
}
int F_19 ( void )
{
if ( V_29 . V_30 == V_31 &&
V_29 . V_4 == 6 &&
V_29 . V_5 == 1 &&
V_29 . V_14 < 8 ) {
F_10 ( V_26 L_4 ) ;
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_32 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_21 ( 1 , L_5
L_6 ) ;
}
}
static int T_2 F_22 ( char * V_33 )
{
V_34 = 1 ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
#ifdef F_24
F_25 ( V_2 , V_35 ) ;
if ( ! F_26 () && V_2 -> V_4 == 5 ) {
static int V_36 ;
F_27 ( V_2 , V_35 ) ;
if ( ! V_36 ) {
F_10 ( V_37 L_7 ) ;
V_36 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_11 ( V_2 , V_38 ) ;
if ( V_34 ) {
F_10 ( V_15 L_8 ) ;
F_5 ( V_2 , V_39 ) ;
F_28 ( V_40 , V_41 ) ;
}
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
if ( F_29 ( V_6 ,
V_42 )
> 0 ) {
F_16 ( L_9 ) ;
F_16 ( L_10 ) ;
}
}
if ( V_43 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_5 ( V_2 , V_44 ) ;
#ifdef F_30
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_45 . V_46 = 7 ;
break;
case 15 :
V_45 . V_46 = 7 ;
break;
}
#endif
F_20 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
#ifdef F_32
unsigned V_47 ;
int V_48 = F_33 () ;
V_47 = F_34 ( V_48 ) ;
if ( V_47 == V_49 || ! F_35 ( V_47 ) ) {
V_47 = F_36 ( V_48 ) ;
}
F_37 ( V_48 , V_47 ) ;
#endif
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_50 , V_51 , V_52 , V_53 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_39 ( 4 , 0 , & V_50 , & V_51 , & V_52 , & V_53 ) ;
if ( V_50 & 0x1f )
return ( V_50 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_40 ( struct V_1 * V_2 )
{
#define F_41 0x00200000
#define F_42 0x00400000
#define F_43 0x80000000
#define F_44 0x00000001
#define F_45 0x00000002
#define F_46 0x00000020
T_3 V_54 , V_55 , V_56 , V_57 ;
F_11 ( V_2 , V_58 ) ;
F_11 ( V_2 , V_59 ) ;
F_11 ( V_2 , V_60 ) ;
F_11 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_62 ) ;
F_9 ( V_63 , V_54 , V_55 ) ;
V_56 = V_55 | V_54 ;
if ( V_56 & F_41 )
F_5 ( V_2 , V_58 ) ;
if ( V_56 & F_42 )
F_5 ( V_2 , V_59 ) ;
if ( V_56 & F_43 ) {
F_9 ( V_64 ,
V_54 , V_55 ) ;
V_57 = V_55 | V_54 ;
if ( ( V_57 & F_44 ) &&
( V_56 & F_41 ) )
F_5 ( V_2 , V_60 ) ;
if ( V_57 & F_45 )
F_5 ( V_2 , V_61 ) ;
if ( V_57 & F_46 )
F_5 ( V_2 , V_62 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned int V_65 = 0 ;
F_1 ( V_2 ) ;
F_23 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( ! F_6 ( V_2 , V_66 ) ) {
V_2 -> V_67 = F_38 ( V_2 ) ;
#ifdef F_49
F_50 ( V_2 ) ;
#endif
}
V_65 = F_51 ( V_2 ) ;
if ( V_2 -> V_8 > 9 ) {
unsigned V_50 = F_3 ( 10 ) ;
if ( ( V_50 & 0xff ) && ( ( ( V_50 >> 8 ) & 0xff ) > 1 ) )
F_5 ( V_2 , V_68 ) ;
}
if ( V_69 )
F_5 ( V_2 , V_70 ) ;
if ( V_71 ) {
unsigned int V_72 ;
F_9 ( V_6 , V_72 , V_65 ) ;
if ( ! ( V_72 & ( 1 << 11 ) ) )
F_5 ( V_2 , V_73 ) ;
if ( ! ( V_72 & ( 1 << 12 ) ) )
F_5 ( V_2 , V_74 ) ;
}
if ( V_2 -> V_4 == 6 && V_75 &&
( V_2 -> V_5 == 29 || V_2 -> V_5 == 46 || V_2 -> V_5 == 47 ) )
F_5 ( V_2 , V_76 ) ;
#ifdef F_12
if ( V_2 -> V_4 == 15 )
V_2 -> V_18 = V_2 -> V_77 * 2 ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_27 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_78 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_65 == 0 )
V_78 = L_11 ;
else if ( V_65 == 256 )
V_78 = L_12 ;
break;
case 6 :
if ( V_65 == 128 )
V_78 = L_13 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_78 = L_14 ;
break;
case 8 :
if ( V_65 == 128 )
V_78 = L_15 ;
break;
}
if ( V_78 )
strcpy ( V_2 -> V_79 , V_78 ) ;
}
if ( V_2 -> V_4 == 15 )
F_5 ( V_2 , V_80 ) ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_81 ) ;
#endif
F_31 ( V_2 ) ;
if ( F_6 ( V_2 , V_82 ) )
F_40 ( V_2 ) ;
if ( F_6 ( V_2 , V_83 ) ) {
T_1 V_84 ;
F_17 ( V_85 , V_84 ) ;
if ( ( V_84 & 0xF ) == V_86 ) {
F_52 ( V_15 L_16
L_17
L_18
L_19 ) ;
V_84 = ( V_84 & ~ 0xF ) | V_87 ;
F_53 ( V_85 , V_84 ) ;
}
}
}
static unsigned int F_54 ( struct V_1 * V_2 , unsigned int V_88 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_88 == 0 ) )
V_88 = 256 ;
return V_88 ;
}
static void F_55 ( const unsigned char V_89 )
{
unsigned char V_90 ;
if ( V_89 == 0 )
return;
for ( V_90 = 0 ; V_91 [ V_90 ] . V_92 != V_89 && \
V_91 [ V_90 ] . V_92 != 0 ; V_90 ++ )
;
if ( V_91 [ V_90 ] . V_93 == 0 )
return;
switch ( V_91 [ V_90 ] . V_93 ) {
case V_94 :
if ( V_95 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_95 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_98 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_98 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_99 :
if ( V_95 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_95 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_98 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_98 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_100 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_100 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_101 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_101 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_102 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_102 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_103 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_103 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_104 :
if ( V_95 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_95 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_100 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_100 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_102 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_102 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_105 :
if ( V_95 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_95 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_106 :
if ( V_102 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_102 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_107 :
if ( V_100 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_100 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_102 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_102 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_108 :
case V_109 :
if ( V_98 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_98 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_110 :
case V_111 :
if ( V_103 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_103 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_112 :
case V_113 :
if ( V_101 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_101 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_103 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_103 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_114 :
if ( V_98 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_98 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
if ( V_103 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_103 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
case V_115 :
if ( V_116 [ V_96 ] < V_91 [ V_90 ] . V_97 )
V_116 [ V_96 ] = V_91 [ V_90 ] . V_97 ;
break;
}
}
static void F_56 ( struct V_1 * V_2 )
{
switch ( ( V_2 -> V_4 << 8 ) + V_2 -> V_5 ) {
case 0x60f :
case 0x616 :
case 0x617 :
case 0x61d :
V_117 = - 1 ;
break;
case 0x63a :
V_117 = 2 ;
break;
case 0x61a :
case 0x61e :
case 0x625 :
case 0x62c :
case 0x62e :
case 0x62f :
case 0x62a :
case 0x62d :
default:
V_117 = 6 ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
int V_118 , V_119 , V_120 ;
unsigned int V_121 [ 4 ] ;
unsigned char * V_89 = ( unsigned char * ) V_121 ;
if ( V_2 -> V_8 < 2 )
return;
V_120 = F_3 ( 2 ) & 0xFF ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
F_58 ( 2 , & V_121 [ 0 ] , & V_121 [ 1 ] , & V_121 [ 2 ] , & V_121 [ 3 ] ) ;
for ( V_119 = 0 ; V_119 < 3 ; V_119 ++ )
if ( V_121 [ V_119 ] & ( 1 << 31 ) )
V_121 [ V_119 ] = 0 ;
for ( V_119 = 1 ; V_119 < 16 ; V_119 ++ )
F_55 ( V_89 [ V_119 ] ) ;
}
F_56 ( V_2 ) ;
}
