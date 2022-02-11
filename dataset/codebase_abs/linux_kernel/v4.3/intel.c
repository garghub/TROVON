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
if ( V_2 -> V_4 == 5 && V_2 -> V_5 == 9 ) {
F_16 ( L_4 ) ;
F_18 ( V_29 ) ;
}
}
int F_19 ( void )
{
if ( V_30 . V_31 == V_32 &&
V_30 . V_4 == 6 &&
V_30 . V_5 == 1 &&
V_30 . V_14 < 8 ) {
F_10 ( V_26 L_5 ) ;
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_33 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_21 ( 1 , L_6
L_7 ) ;
}
}
static int T_2 F_22 ( char * V_34 )
{
V_35 = 1 ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
#ifdef F_24
F_25 ( V_2 , V_36 ) ;
if ( ! F_26 () && V_2 -> V_4 == 5 && V_2 -> V_5 < 9 ) {
static int V_37 ;
F_27 ( V_2 , V_36 ) ;
if ( ! V_37 ) {
F_10 ( V_38 L_8 ) ;
V_37 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_11 ( V_2 , V_39 ) ;
if ( V_35 ) {
F_10 ( V_15 L_9 ) ;
F_5 ( V_2 , V_40 ) ;
F_28 ( V_41 , V_42 ) ;
}
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
if ( F_29 ( V_6 ,
V_43 )
> 0 ) {
F_16 ( L_10 ) ;
F_16 ( L_11 ) ;
}
}
if ( V_44 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_27 ( V_2 , V_45 ) ;
#ifdef F_30
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_46 . V_47 = 7 ;
break;
case 15 :
V_46 . V_47 = 7 ;
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
unsigned V_48 ;
int V_49 = F_33 () ;
V_48 = F_34 ( V_49 ) ;
if ( V_48 == V_50 || ! F_35 ( V_48 ) ) {
V_48 = F_36 ( V_49 ) ;
}
F_37 ( V_49 , V_48 ) ;
#endif
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_51 , V_52 , V_53 , V_54 ;
if ( V_2 -> V_8 < 4 )
return 1 ;
F_39 ( 4 , 0 , & V_51 , & V_52 , & V_53 , & V_54 ) ;
if ( V_51 & 0x1f )
return ( V_51 >> 26 ) + 1 ;
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
T_3 V_55 , V_56 , V_57 , V_58 ;
F_11 ( V_2 , V_59 ) ;
F_11 ( V_2 , V_60 ) ;
F_11 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_62 ) ;
F_11 ( V_2 , V_63 ) ;
F_9 ( V_64 , V_55 , V_56 ) ;
V_57 = V_56 | V_55 ;
if ( V_57 & F_41 )
F_5 ( V_2 , V_59 ) ;
if ( V_57 & F_42 )
F_5 ( V_2 , V_60 ) ;
if ( V_57 & F_43 ) {
F_9 ( V_65 ,
V_55 , V_56 ) ;
V_58 = V_56 | V_55 ;
if ( ( V_58 & F_44 ) &&
( V_57 & F_41 ) )
F_5 ( V_2 , V_61 ) ;
if ( V_58 & F_45 )
F_5 ( V_2 , V_62 ) ;
if ( V_58 & F_46 )
F_5 ( V_2 , V_63 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
T_1 V_66 ;
if ( ! F_6 ( V_2 , V_67 ) )
return;
F_17 ( V_68 , V_66 ) ;
if ( ( V_66 & 0xF ) != V_69 )
return;
F_48 ( L_12 ) ;
F_48 ( L_13 ) ;
V_66 = ( V_66 & ~ 0xF ) | V_70 ;
F_49 ( V_68 , V_66 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_71 = 0 ;
F_1 ( V_2 ) ;
F_23 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( ! F_6 ( V_2 , V_72 ) ) {
V_2 -> V_73 = F_38 ( V_2 ) ;
#ifdef F_53
F_54 ( V_2 ) ;
#endif
}
V_71 = F_55 ( V_2 ) ;
if ( V_71 == 0 ) {
F_56 ( V_2 ) ;
V_71 = V_2 -> V_74 ;
}
if ( V_2 -> V_8 > 9 ) {
unsigned V_51 = F_3 ( 10 ) ;
if ( ( V_51 & 0xff ) && ( ( ( V_51 >> 8 ) & 0xff ) > 1 ) )
F_5 ( V_2 , V_75 ) ;
}
if ( V_76 )
F_5 ( V_2 , V_77 ) ;
if ( V_78 ) {
unsigned int V_79 ;
F_9 ( V_6 , V_79 , V_71 ) ;
if ( ! ( V_79 & ( 1 << 11 ) ) )
F_5 ( V_2 , V_80 ) ;
if ( ! ( V_79 & ( 1 << 12 ) ) )
F_5 ( V_2 , V_81 ) ;
}
if ( V_2 -> V_4 == 6 && V_82 &&
( V_2 -> V_5 == 29 || V_2 -> V_5 == 46 || V_2 -> V_5 == 47 ) )
F_27 ( V_2 , V_83 ) ;
#ifdef F_12
if ( V_2 -> V_4 == 15 )
V_2 -> V_18 = V_2 -> V_84 * 2 ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_27 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_85 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_71 == 0 )
V_85 = L_14 ;
else if ( V_71 == 256 )
V_85 = L_15 ;
break;
case 6 :
if ( V_71 == 128 )
V_85 = L_16 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_85 = L_17 ;
break;
case 8 :
if ( V_71 == 128 )
V_85 = L_18 ;
break;
}
if ( V_85 )
strcpy ( V_2 -> V_86 , V_85 ) ;
}
if ( V_2 -> V_4 == 15 )
F_5 ( V_2 , V_87 ) ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_88 ) ;
#endif
F_31 ( V_2 ) ;
if ( F_6 ( V_2 , V_89 ) )
F_40 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static unsigned int F_57 ( struct V_1 * V_2 , unsigned int V_90 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_90 == 0 ) )
V_90 = 256 ;
if ( ( V_2 -> V_4 == 5 ) && ( V_2 -> V_5 == 9 ) )
V_90 = 16 ;
return V_90 ;
}
static void F_58 ( const unsigned char V_91 )
{
unsigned char V_92 ;
if ( V_91 == 0 )
return;
for ( V_92 = 0 ; V_93 [ V_92 ] . V_94 != V_91 && \
V_93 [ V_92 ] . V_94 != 0 ; V_92 ++ )
;
if ( V_93 [ V_92 ] . V_95 == 0 )
return;
switch ( V_93 [ V_92 ] . V_95 ) {
case V_96 :
if ( V_97 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_97 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_100 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_100 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_101 :
if ( V_97 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_97 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_100 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_100 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_102 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_102 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_103 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_103 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_104 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_104 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_105 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_105 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_106 :
if ( V_97 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_97 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_102 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_102 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_104 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_104 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_107 :
if ( V_97 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_97 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_108 :
if ( V_104 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_104 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_109 :
if ( V_102 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_102 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_104 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_104 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_110 :
case V_111 :
if ( V_100 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_100 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_112 :
case V_113 :
if ( V_105 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_105 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_114 :
case V_115 :
if ( V_103 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_103 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_105 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_105 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_116 :
if ( V_100 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_100 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
if ( V_105 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_105 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
case V_117 :
if ( V_118 [ V_98 ] < V_93 [ V_92 ] . V_99 )
V_118 [ V_98 ] = V_93 [ V_92 ] . V_99 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 )
{
int V_119 , V_120 , V_121 ;
unsigned int V_122 [ 4 ] ;
unsigned char * V_91 = ( unsigned char * ) V_122 ;
if ( V_2 -> V_8 < 2 )
return;
V_121 = F_3 ( 2 ) & 0xFF ;
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
F_60 ( 2 , & V_122 [ 0 ] , & V_122 [ 1 ] , & V_122 [ 2 ] , & V_122 [ 3 ] ) ;
for ( V_120 = 0 ; V_120 < 3 ; V_120 ++ )
if ( V_122 [ V_120 ] & ( 1 << 31 ) )
V_122 [ V_120 ] = 0 ;
for ( V_120 = 1 ; V_120 < 16 ; V_120 ++ )
F_58 ( V_91 [ V_120 ] ) ;
}
}
