static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
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
F_15 () ;
}
if ( V_2 -> V_4 == 6 ) {
switch ( V_2 -> V_5 ) {
case 0x27 :
case 0x35 :
F_6 ( V_2 , V_22 ) ;
break;
default:
break;
}
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_12 ( V_2 , V_23 ) ;
#ifdef F_16
if ( V_2 -> V_4 == 15 ) {
F_2 ( V_6 , V_3 ) ;
if ( V_3 & V_24 ) {
F_11 ( V_25 L_2 ) ;
V_3 &= ~ V_24 ;
F_3 ( V_6 , V_3 ) ;
}
}
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_2 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_24 ) ) {
F_11 ( V_25 L_3 ) ;
F_17 ( V_26 ) ;
F_17 ( V_27 ) ;
}
}
}
int F_18 ( void )
{
if ( V_28 . V_29 == V_30 &&
V_28 . V_4 == 6 &&
V_28 . V_5 == 1 &&
V_28 . V_14 < 8 ) {
F_11 ( V_25 L_4 ) ;
return 1 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_20 ( 1 , L_5
L_6 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
unsigned long V_32 , V_33 ;
#ifdef F_22
F_23 ( V_2 , V_34 ) ;
if ( ! F_24 () && V_2 -> V_4 == 5 ) {
static int V_35 ;
F_25 ( V_2 , V_34 ) ;
if ( ! V_35 ) {
F_11 ( V_36 L_7 ) ;
V_35 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_12 ( V_2 , V_37 ) ;
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
F_10 ( V_6 , V_32 , V_33 ) ;
if ( ( V_32 & V_38 ) == 0 ) {
F_11 ( V_25 L_8 ) ;
F_11 ( V_25 L_9 ) ;
V_32 |= V_38 ;
F_8 ( V_6 , V_32 , V_33 ) ;
}
}
if ( V_39 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_6 ( V_2 , V_40 ) ;
#ifdef F_26
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_41 . V_42 = 7 ;
break;
case 15 :
V_41 . V_42 = 7 ;
break;
}
#endif
#ifdef F_27
F_28 () ;
#endif
F_19 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
}
static void F_29 ( struct V_1 * V_2 )
{
#ifdef F_30
unsigned V_43 ;
int V_44 = F_31 () ;
V_43 = F_32 ( V_44 ) ;
if ( V_43 == V_45 || ! F_33 ( V_43 ) ) {
V_43 = F_34 ( V_44 ) ;
}
F_35 ( V_44 , V_43 ) ;
#endif
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_46 , V_47 , V_48 , V_49 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_37 ( 4 , 0 , & V_46 , & V_47 , & V_48 , & V_49 ) ;
if ( V_46 & 0x1f )
return ( V_46 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_38 ( struct V_1 * V_2 )
{
#define F_39 0x00200000
#define F_40 0x00400000
#define F_41 0x80000000
#define F_42 0x00000001
#define F_43 0x00000002
#define F_44 0x00000020
T_2 V_50 , V_51 , V_52 , V_53 ;
F_12 ( V_2 , V_54 ) ;
F_12 ( V_2 , V_55 ) ;
F_12 ( V_2 , V_56 ) ;
F_12 ( V_2 , V_57 ) ;
F_12 ( V_2 , V_58 ) ;
F_10 ( V_59 , V_50 , V_51 ) ;
V_52 = V_51 | V_50 ;
if ( V_52 & F_39 )
F_6 ( V_2 , V_54 ) ;
if ( V_52 & F_40 )
F_6 ( V_2 , V_55 ) ;
if ( V_52 & F_41 ) {
F_10 ( V_60 ,
V_50 , V_51 ) ;
V_53 = V_51 | V_50 ;
if ( ( V_53 & F_42 ) &&
( V_52 & F_39 ) )
F_6 ( V_2 , V_56 ) ;
if ( V_53 & F_43 )
F_6 ( V_2 , V_57 ) ;
if ( V_53 & F_44 )
F_6 ( V_2 , V_58 ) ;
}
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_61 = 0 ;
F_1 ( V_2 ) ;
F_21 ( V_2 ) ;
F_46 ( V_2 ) ;
V_61 = F_47 ( V_2 ) ;
if ( V_2 -> V_8 > 9 ) {
unsigned V_46 = F_4 ( 10 ) ;
if ( ( V_46 & 0xff ) && ( ( ( V_46 >> 8 ) & 0xff ) > 1 ) )
F_6 ( V_2 , V_62 ) ;
}
if ( V_63 )
F_6 ( V_2 , V_64 ) ;
if ( V_65 ) {
unsigned int V_66 ;
F_10 ( V_6 , V_66 , V_61 ) ;
if ( ! ( V_66 & ( 1 << 11 ) ) )
F_6 ( V_2 , V_67 ) ;
if ( ! ( V_66 & ( 1 << 12 ) ) )
F_6 ( V_2 , V_68 ) ;
}
if ( V_2 -> V_4 == 6 && V_69 &&
( V_2 -> V_5 == 29 || V_2 -> V_5 == 46 || V_2 -> V_5 == 47 ) )
F_6 ( V_2 , V_70 ) ;
#ifdef F_13
if ( V_2 -> V_4 == 15 )
V_2 -> V_18 = V_2 -> V_71 * 2 ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_26 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_72 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_61 == 0 )
V_72 = L_10 ;
else if ( V_61 == 256 )
V_72 = L_11 ;
break;
case 6 :
if ( V_61 == 128 )
V_72 = L_12 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_72 = L_13 ;
break;
case 8 :
if ( V_61 == 128 )
V_72 = L_14 ;
break;
}
if ( V_72 )
strcpy ( V_2 -> V_73 , V_72 ) ;
}
if ( V_2 -> V_4 == 15 )
F_6 ( V_2 , V_74 ) ;
if ( V_2 -> V_4 == 6 )
F_6 ( V_2 , V_75 ) ;
#endif
if ( ! F_7 ( V_2 , V_76 ) ) {
V_2 -> V_77 = F_36 ( V_2 ) ;
#ifdef F_48
F_49 ( V_2 ) ;
#endif
}
F_29 ( V_2 ) ;
if ( F_7 ( V_2 , V_78 ) )
F_38 ( V_2 ) ;
if ( F_7 ( V_2 , V_79 ) ) {
T_1 V_80 ;
F_2 ( V_81 , V_80 ) ;
if ( ( V_80 & 0xF ) == V_82 ) {
F_50 ( V_15 L_15
L_16
L_17
L_18 ) ;
V_80 = ( V_80 & ~ 0xF ) | V_83 ;
F_3 ( V_81 , V_80 ) ;
}
}
}
static unsigned int F_51 ( struct V_1 * V_2 , unsigned int V_84 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_84 == 0 ) )
V_84 = 256 ;
return V_84 ;
}
static void F_52 ( const unsigned char V_85 )
{
unsigned char V_86 ;
if ( V_85 == 0 )
return;
for ( V_86 = 0 ; V_87 [ V_86 ] . V_88 != V_85 && \
V_87 [ V_86 ] . V_88 != 0 ; V_86 ++ )
;
if ( V_87 [ V_86 ] . V_89 == 0 )
return;
switch ( V_87 [ V_86 ] . V_89 ) {
case V_90 :
if ( V_91 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_91 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_94 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_94 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_95 :
if ( V_91 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_91 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_94 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_94 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_96 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_96 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_97 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_97 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_98 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_98 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_99 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_99 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_100 :
if ( V_91 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_91 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_96 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_96 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_98 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_98 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_101 :
if ( V_91 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_91 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_102 :
if ( V_98 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_98 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_103 :
if ( V_96 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_96 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_98 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_98 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_104 :
case V_105 :
if ( V_94 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_94 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_106 :
case V_107 :
if ( V_99 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_99 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_108 :
case V_109 :
if ( V_97 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_97 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_99 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_99 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_110 :
if ( V_94 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_94 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
if ( V_99 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_99 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
case V_111 :
if ( V_112 [ V_92 ] < V_87 [ V_86 ] . V_93 )
V_112 [ V_92 ] = V_87 [ V_86 ] . V_93 ;
break;
}
}
static void F_53 ( struct V_1 * V_2 )
{
switch ( ( V_2 -> V_4 << 8 ) + V_2 -> V_5 ) {
case 0x60f :
case 0x616 :
case 0x617 :
case 0x61d :
V_113 = - 1 ;
break;
case 0x63a :
V_113 = 2 ;
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
V_113 = 6 ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
int V_114 , V_115 , V_116 ;
unsigned int V_117 [ 4 ] ;
unsigned char * V_85 = ( unsigned char * ) V_117 ;
if ( V_2 -> V_8 < 2 )
return;
V_116 = F_4 ( 2 ) & 0xFF ;
for ( V_114 = 0 ; V_114 < V_116 ; V_114 ++ ) {
F_55 ( 2 , & V_117 [ 0 ] , & V_117 [ 1 ] , & V_117 [ 2 ] , & V_117 [ 3 ] ) ;
for ( V_115 = 0 ; V_115 < 3 ; V_115 ++ )
if ( V_117 [ V_115 ] & ( 1 << 31 ) )
V_117 [ V_115 ] = 0 ;
for ( V_115 = 1 ; V_115 < 16 ; V_115 ++ )
F_52 ( V_85 [ V_115 ] ) ;
}
F_53 ( V_2 ) ;
}
