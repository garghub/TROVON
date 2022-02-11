static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 1 ;
}
void F_2 ( struct V_3 * V_4 )
{
if ( V_2 )
return;
if ( F_3 ( V_4 , V_5 ) && ! F_3 ( V_4 , V_6 ) ) {
F_4 ( V_5 ) ;
F_5 ( L_1 ) ;
}
}
static int T_1 F_6 ( char * V_1 )
{
V_7 = true ;
return 0 ;
}
static void F_7 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 != 6 )
return;
switch ( V_4 -> V_9 ) {
case V_10 :
case V_11 :
break;
default:
return;
}
if ( V_7 ) {
F_8 ( V_12 ,
V_13 ) ;
return;
}
F_9 ( V_12 ,
V_13 ) ;
F_10 ( V_4 , V_14 ) ;
if ( V_4 == & V_15 )
V_16 |= V_17 ;
}
static void F_11 ( struct V_3 * V_4 )
{
T_2 V_18 ;
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
if ( F_8 ( V_19 ,
V_20 ) > 0 ) {
V_4 -> V_21 = F_12 ( 0 ) ;
F_13 ( V_4 ) ;
}
}
if ( ( V_4 -> V_8 == 0xf && V_4 -> V_9 >= 0x03 ) ||
( V_4 -> V_8 == 0x6 && V_4 -> V_9 >= 0x0e ) )
F_10 ( V_4 , V_22 ) ;
if ( V_4 -> V_8 >= 6 && ! F_3 ( V_4 , V_23 ) )
V_4 -> V_24 = F_14 () ;
if ( V_4 -> V_8 == 6 && V_4 -> V_9 == 0x1c && V_4 -> V_25 <= 2 &&
V_4 -> V_24 < 0x20e ) {
F_5 ( L_2 ) ;
F_15 ( V_4 , V_26 ) ;
}
#ifdef F_16
F_10 ( V_4 , V_27 ) ;
#else
if ( V_4 -> V_8 == 15 && V_4 -> V_28 == 64 )
V_4 -> V_28 = 128 ;
#endif
if ( V_4 -> V_8 == 0xF && V_4 -> V_9 == 0x3
&& ( V_4 -> V_25 == 0x3 || V_4 -> V_25 == 0x4 ) )
V_4 -> V_29 = 36 ;
if ( V_4 -> V_30 & ( 1 << 8 ) ) {
F_10 ( V_4 , V_22 ) ;
F_10 ( V_4 , V_31 ) ;
}
if ( V_4 -> V_8 == 6 ) {
switch ( V_4 -> V_9 ) {
case 0x27 :
case 0x35 :
case 0x4a :
F_10 ( V_4 , V_32 ) ;
break;
default:
break;
}
}
if ( V_4 -> V_8 == 6 && V_4 -> V_9 < 15 )
F_15 ( V_4 , V_33 ) ;
#ifdef F_17
if ( V_4 -> V_8 == 15 )
if ( F_8 ( V_19 ,
V_34 ) > 0 )
F_18 ( L_3 ) ;
#endif
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
F_19 ( V_19 , V_18 ) ;
if ( ! ( V_18 & V_35 ) ) {
F_18 ( L_4 ) ;
F_4 ( V_36 ) ;
F_4 ( V_37 ) ;
}
}
if ( V_4 -> V_8 == 5 && V_4 -> V_9 == 9 ) {
F_18 ( L_5 ) ;
F_4 ( V_38 ) ;
}
if ( V_4 -> V_21 >= 0x00000001 ) {
T_3 V_39 , V_40 , V_41 , V_42 ;
F_20 ( 0x00000001 , & V_39 , & V_40 , & V_41 , & V_42 ) ;
if ( V_42 & ( 1U << 28 ) )
V_4 -> V_43 = F_21 ( ( V_40 >> 16 ) & 0xff ) ;
}
F_2 ( V_4 ) ;
}
int F_22 ( void )
{
if ( V_15 . V_44 == V_45 &&
V_15 . V_8 == 6 &&
V_15 . V_9 == 1 &&
V_15 . V_25 < 8 ) {
F_18 ( L_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_46 )
return;
if ( V_4 -> V_8 == 5 &&
V_4 -> V_25 >= 1 && V_4 -> V_25 <= 4 &&
V_4 -> V_9 <= 3 ) {
F_24 ( 1 , L_7
L_8 ) ;
}
}
static int T_1 F_25 ( char * V_1 )
{
V_47 = 1 ;
return 1 ;
}
static void F_26 ( struct V_3 * V_4 )
{
#ifdef F_27
F_28 ( V_4 , V_48 ) ;
if ( V_4 -> V_8 == 5 && V_4 -> V_9 < 9 ) {
static int V_49 ;
F_29 ( V_4 , V_48 ) ;
if ( ! V_49 ) {
F_30 ( L_9 ) ;
V_49 = 1 ;
}
}
#endif
if ( ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 | V_4 -> V_25 ) < 0x633 )
F_15 ( V_4 , V_50 ) ;
if ( V_47 ) {
F_5 ( L_10 ) ;
F_10 ( V_4 , V_51 ) ;
F_31 ( V_52 , V_53 ) ;
}
if ( ( V_4 -> V_8 == 15 ) && ( V_4 -> V_9 == 1 ) && ( V_4 -> V_25 == 1 ) ) {
if ( F_9 ( V_19 ,
V_54 ) > 0 ) {
F_18 ( L_11 ) ;
F_18 ( L_12 ) ;
}
}
if ( F_32 ( V_55 ) && ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 ) == 0x520 &&
( V_4 -> V_25 < 0x6 || V_4 -> V_25 == 0xb ) )
F_29 ( V_4 , V_56 ) ;
#ifdef F_33
switch ( V_4 -> V_8 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_57 . V_58 = 7 ;
break;
case 15 :
V_57 . V_58 = 7 ;
break;
}
#endif
F_23 ( V_4 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
}
static void F_34 ( struct V_3 * V_4 )
{
#ifdef F_35
unsigned V_59 ;
int V_60 = F_36 () ;
V_59 = F_37 ( V_60 ) ;
if ( V_59 == V_61 || ! F_38 ( V_59 ) ) {
V_59 = F_39 ( V_60 ) ;
}
F_40 ( V_60 , V_59 ) ;
#endif
}
static int F_41 ( struct V_3 * V_4 )
{
unsigned int V_39 , V_40 , V_41 , V_42 ;
if ( ! F_42 ( V_62 ) || V_4 -> V_21 < 4 )
return 1 ;
F_43 ( 4 , 0 , & V_39 , & V_40 , & V_41 , & V_42 ) ;
if ( V_39 & 0x1f )
return ( V_39 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_44 ( struct V_3 * V_4 )
{
#define F_45 0x00200000
#define F_46 0x00400000
#define F_47 0x80000000
#define F_48 0x00000001
#define F_49 0x00000002
#define F_50 0x00000020
T_3 V_63 , V_64 , V_65 , V_66 ;
F_15 ( V_4 , V_67 ) ;
F_15 ( V_4 , V_68 ) ;
F_15 ( V_4 , V_69 ) ;
F_15 ( V_4 , V_70 ) ;
F_15 ( V_4 , V_71 ) ;
F_51 ( V_72 , V_63 , V_64 ) ;
V_65 = V_64 | V_63 ;
if ( V_65 & F_45 )
F_10 ( V_4 , V_67 ) ;
if ( V_65 & F_46 )
F_10 ( V_4 , V_68 ) ;
if ( V_65 & F_47 ) {
F_51 ( V_73 ,
V_63 , V_64 ) ;
V_66 = V_64 | V_63 ;
if ( ( V_66 & F_48 ) &&
( V_65 & F_45 ) )
F_10 ( V_4 , V_69 ) ;
if ( V_66 & F_49 )
F_10 ( V_4 , V_70 ) ;
if ( V_66 & F_50 )
F_10 ( V_4 , V_71 ) ;
}
}
static void F_52 ( struct V_3 * V_4 )
{
T_2 V_74 ;
if ( ! F_3 ( V_4 , V_75 ) )
return;
F_19 ( V_76 , V_74 ) ;
if ( ( V_74 & 0xF ) != V_77 )
return;
F_53 ( L_13 ) ;
F_53 ( L_14 ) ;
V_74 = ( V_74 & ~ 0xF ) | V_78 ;
F_54 ( V_76 , V_74 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_52 ( V_4 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
unsigned int V_79 = 0 ;
F_11 ( V_4 ) ;
F_26 ( V_4 ) ;
F_57 ( V_4 ) ;
if ( ! F_3 ( V_4 , V_80 ) ) {
V_4 -> V_81 = F_41 ( V_4 ) ;
#ifdef F_58
F_59 ( V_4 ) ;
#endif
}
V_79 = F_60 ( V_4 ) ;
if ( V_79 == 0 ) {
F_61 ( V_4 ) ;
V_79 = V_4 -> V_82 ;
}
if ( V_4 -> V_21 > 9 ) {
unsigned V_39 = F_12 ( 10 ) ;
if ( ( V_39 & 0xff ) && ( ( ( V_39 >> 8 ) & 0xff ) > 1 ) )
F_10 ( V_4 , V_83 ) ;
}
if ( F_3 ( V_4 , V_84 ) )
F_10 ( V_4 , V_85 ) ;
if ( F_32 ( V_86 ) ) {
unsigned int V_87 ;
F_51 ( V_19 , V_87 , V_79 ) ;
if ( ! ( V_87 & ( 1 << 11 ) ) )
F_10 ( V_4 , V_88 ) ;
if ( ! ( V_87 & ( 1 << 12 ) ) )
F_10 ( V_4 , V_89 ) ;
}
if ( V_4 -> V_8 == 6 && F_32 ( V_90 ) &&
( V_4 -> V_9 == 29 || V_4 -> V_9 == 46 || V_4 -> V_9 == 47 ) )
F_29 ( V_4 , V_91 ) ;
if ( V_4 -> V_8 == 6 && F_32 ( V_92 ) &&
( ( V_4 -> V_9 == V_93 ) ) )
F_29 ( V_4 , V_94 ) ;
#ifdef F_16
if ( V_4 -> V_8 == 15 )
V_4 -> V_28 = V_4 -> V_95 * 2 ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_36 ) ;
#else
if ( V_4 -> V_8 == 6 ) {
char * V_96 = NULL ;
switch ( V_4 -> V_9 ) {
case 5 :
if ( V_79 == 0 )
V_96 = L_15 ;
else if ( V_79 == 256 )
V_96 = L_16 ;
break;
case 6 :
if ( V_79 == 128 )
V_96 = L_17 ;
else if ( V_4 -> V_25 == 0 || V_4 -> V_25 == 5 )
V_96 = L_18 ;
break;
case 8 :
if ( V_79 == 128 )
V_96 = L_19 ;
break;
}
if ( V_96 )
strcpy ( V_4 -> V_97 , V_96 ) ;
}
if ( V_4 -> V_8 == 15 )
F_10 ( V_4 , V_98 ) ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_99 ) ;
#endif
F_34 ( V_4 ) ;
if ( F_3 ( V_4 , V_100 ) )
F_44 ( V_4 ) ;
F_52 ( V_4 ) ;
F_7 ( V_4 ) ;
}
static unsigned int F_62 ( struct V_3 * V_4 , unsigned int V_101 )
{
if ( ( V_4 -> V_8 == 6 ) && ( V_4 -> V_9 == 11 ) && ( V_101 == 0 ) )
V_101 = 256 ;
if ( ( V_4 -> V_8 == 5 ) && ( V_4 -> V_9 == 9 ) )
V_101 = 16 ;
return V_101 ;
}
static void F_63 ( const unsigned char V_102 )
{
unsigned char V_103 ;
if ( V_102 == 0 )
return;
for ( V_103 = 0 ; V_104 [ V_103 ] . V_105 != V_102 && \
V_104 [ V_103 ] . V_105 != 0 ; V_103 ++ )
;
if ( V_104 [ V_103 ] . V_106 == 0 )
return;
switch ( V_104 [ V_103 ] . V_106 ) {
case V_107 :
if ( V_108 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_108 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_111 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_111 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_112 :
if ( V_108 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_108 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_111 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_111 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_113 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_113 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_114 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_114 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_115 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_115 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_116 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_116 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_117 :
if ( V_108 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_108 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_113 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_113 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_115 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_115 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_118 :
if ( V_108 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_108 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_119 :
if ( V_115 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_115 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_120 :
if ( V_113 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_113 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_115 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_115 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_121 :
case V_122 :
if ( V_111 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_111 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_123 :
case V_124 :
if ( V_116 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_116 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_125 :
case V_126 :
if ( V_114 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_114 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_116 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_116 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_127 :
if ( V_111 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_111 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
if ( V_116 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_116 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
case V_128 :
if ( V_129 [ V_109 ] < V_104 [ V_103 ] . V_110 )
V_129 [ V_109 ] = V_104 [ V_103 ] . V_110 ;
break;
}
}
static void F_64 ( struct V_3 * V_4 )
{
int V_130 , V_131 , V_132 ;
unsigned int V_133 [ 4 ] ;
unsigned char * V_102 = ( unsigned char * ) V_133 ;
if ( V_4 -> V_21 < 2 )
return;
V_132 = F_12 ( 2 ) & 0xFF ;
for ( V_130 = 0 ; V_130 < V_132 ; V_130 ++ ) {
F_20 ( 2 , & V_133 [ 0 ] , & V_133 [ 1 ] , & V_133 [ 2 ] , & V_133 [ 3 ] ) ;
for ( V_131 = 0 ; V_131 < 3 ; V_131 ++ )
if ( V_133 [ V_131 ] & ( 1 << 31 ) )
V_133 [ V_131 ] = 0 ;
for ( V_131 = 1 ; V_131 < 16 ; V_131 ++ )
F_63 ( V_102 [ V_131 ] ) ;
}
}
