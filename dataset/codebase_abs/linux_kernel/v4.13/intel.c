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
if ( V_7 )
return;
F_8 ( V_4 , V_12 ) ;
F_9 ( V_13 ,
1UL << V_14 ) ;
if ( V_4 == & V_15 )
V_16 |= V_17 ;
}
static void F_10 ( struct V_3 * V_4 )
{
T_2 V_18 ;
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
if ( F_11 ( V_19 ,
V_20 ) > 0 ) {
V_4 -> V_21 = F_12 ( 0 ) ;
F_13 ( V_4 ) ;
}
}
if ( ( V_4 -> V_8 == 0xf && V_4 -> V_9 >= 0x03 ) ||
( V_4 -> V_8 == 0x6 && V_4 -> V_9 >= 0x0e ) )
F_8 ( V_4 , V_22 ) ;
if ( V_4 -> V_8 >= 6 && ! F_3 ( V_4 , V_23 ) )
V_4 -> V_24 = F_14 () ;
if ( V_4 -> V_8 == 6 && V_4 -> V_9 == 0x1c && V_4 -> V_25 <= 2 &&
V_4 -> V_24 < 0x20e ) {
F_5 ( L_2 ) ;
F_15 ( V_4 , V_26 ) ;
}
#ifdef F_16
F_8 ( V_4 , V_27 ) ;
#else
if ( V_4 -> V_8 == 15 && V_4 -> V_28 == 64 )
V_4 -> V_28 = 128 ;
#endif
if ( V_4 -> V_8 == 0xF && V_4 -> V_9 == 0x3
&& ( V_4 -> V_25 == 0x3 || V_4 -> V_25 == 0x4 ) )
V_4 -> V_29 = 36 ;
if ( V_4 -> V_30 & ( 1 << 8 ) ) {
F_8 ( V_4 , V_22 ) ;
F_8 ( V_4 , V_31 ) ;
}
if ( V_4 -> V_8 == 6 ) {
switch ( V_4 -> V_9 ) {
case 0x27 :
case 0x35 :
case 0x4a :
F_8 ( V_4 , V_32 ) ;
break;
default:
break;
}
}
if ( V_4 -> V_8 == 6 && V_4 -> V_9 < 15 )
F_15 ( V_4 , V_33 ) ;
#ifdef F_17
if ( V_4 -> V_8 == 15 )
if ( F_11 ( V_19 ,
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
F_8 ( V_4 , V_51 ) ;
F_31 ( V_52 , V_53 ) ;
}
if ( ( V_4 -> V_8 == 15 ) && ( V_4 -> V_9 == 1 ) && ( V_4 -> V_25 == 1 ) ) {
if ( F_32 ( V_19 ,
V_54 ) > 0 ) {
F_18 ( L_11 ) ;
F_18 ( L_12 ) ;
}
}
if ( F_33 ( V_55 ) && ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 ) == 0x520 &&
( V_4 -> V_25 < 0x6 || V_4 -> V_25 == 0xb ) )
F_29 ( V_4 , V_56 ) ;
#ifdef F_34
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
static void F_35 ( struct V_3 * V_4 )
{
#ifdef F_36
unsigned V_59 ;
int V_60 = F_37 () ;
V_59 = F_38 ( V_60 ) ;
if ( V_59 == V_61 || ! F_39 ( V_59 ) ) {
V_59 = F_40 ( V_60 ) ;
}
F_41 ( V_60 , V_59 ) ;
#endif
}
static int F_42 ( struct V_3 * V_4 )
{
unsigned int V_39 , V_40 , V_41 , V_42 ;
if ( ! F_43 ( V_62 ) || V_4 -> V_21 < 4 )
return 1 ;
F_44 ( 4 , 0 , & V_39 , & V_40 , & V_41 , & V_42 ) ;
if ( V_39 & 0x1f )
return ( V_39 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_45 ( struct V_3 * V_4 )
{
#define F_46 0x00200000
#define F_47 0x00400000
#define F_48 0x80000000
#define F_49 0x00000001
#define F_50 0x00000002
#define F_51 0x00000020
T_3 V_63 , V_64 , V_65 , V_66 ;
F_15 ( V_4 , V_67 ) ;
F_15 ( V_4 , V_68 ) ;
F_15 ( V_4 , V_69 ) ;
F_15 ( V_4 , V_70 ) ;
F_15 ( V_4 , V_71 ) ;
F_52 ( V_72 , V_63 , V_64 ) ;
V_65 = V_64 | V_63 ;
if ( V_65 & F_46 )
F_8 ( V_4 , V_67 ) ;
if ( V_65 & F_47 )
F_8 ( V_4 , V_68 ) ;
if ( V_65 & F_48 ) {
F_52 ( V_73 ,
V_63 , V_64 ) ;
V_66 = V_64 | V_63 ;
if ( ( V_66 & F_49 ) &&
( V_65 & F_46 ) )
F_8 ( V_4 , V_69 ) ;
if ( V_66 & F_50 )
F_8 ( V_4 , V_70 ) ;
if ( V_66 & F_51 )
F_8 ( V_4 , V_71 ) ;
}
}
static void F_53 ( struct V_3 * V_4 )
{
T_2 V_74 ;
if ( ! F_3 ( V_4 , V_75 ) )
return;
F_19 ( V_76 , V_74 ) ;
if ( ( V_74 & 0xF ) != V_77 )
return;
F_54 ( L_13 ) ;
F_54 ( L_14 ) ;
V_74 = ( V_74 & ~ 0xF ) | V_78 ;
F_55 ( V_76 , V_74 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
F_53 ( V_4 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
T_2 V_79 ;
if ( ! F_58 ( V_80 , & V_79 ) ) {
if ( V_79 & V_81 )
F_8 ( V_4 , V_82 ) ;
}
}
static void F_59 ( struct V_3 * V_4 )
{
T_2 V_79 ;
if ( F_58 ( V_83 , & V_79 ) )
return;
F_60 ( V_13 , 0 ) ;
F_57 ( V_4 ) ;
F_7 ( V_4 ) ;
V_79 = F_61 ( V_13 ) ;
F_55 ( V_83 , V_79 ) ;
}
static void F_62 ( struct V_3 * V_4 )
{
unsigned int V_84 = 0 ;
F_10 ( V_4 ) ;
F_26 ( V_4 ) ;
F_63 ( V_4 ) ;
if ( ! F_3 ( V_4 , V_85 ) ) {
V_4 -> V_86 = F_42 ( V_4 ) ;
#ifdef F_64
F_65 ( V_4 ) ;
#endif
}
V_84 = F_66 ( V_4 ) ;
if ( V_84 == 0 ) {
F_67 ( V_4 ) ;
V_84 = V_4 -> V_87 ;
}
if ( V_4 -> V_21 > 9 ) {
unsigned V_39 = F_12 ( 10 ) ;
if ( ( V_39 & 0xff ) && ( ( ( V_39 >> 8 ) & 0xff ) > 1 ) )
F_8 ( V_4 , V_88 ) ;
}
if ( F_3 ( V_4 , V_89 ) )
F_8 ( V_4 , V_90 ) ;
if ( F_33 ( V_91 ) ) {
unsigned int V_92 ;
F_52 ( V_19 , V_92 , V_84 ) ;
if ( ! ( V_92 & ( 1 << 11 ) ) )
F_8 ( V_4 , V_93 ) ;
if ( ! ( V_92 & ( 1 << 12 ) ) )
F_8 ( V_4 , V_94 ) ;
}
if ( V_4 -> V_8 == 6 && F_33 ( V_95 ) &&
( V_4 -> V_9 == 29 || V_4 -> V_9 == 46 || V_4 -> V_9 == 47 ) )
F_29 ( V_4 , V_96 ) ;
if ( V_4 -> V_8 == 6 && F_33 ( V_97 ) &&
( ( V_4 -> V_9 == V_98 ) ) )
F_29 ( V_4 , V_99 ) ;
#ifdef F_16
if ( V_4 -> V_8 == 15 )
V_4 -> V_28 = V_4 -> V_100 * 2 ;
if ( V_4 -> V_8 == 6 )
F_8 ( V_4 , V_36 ) ;
#else
if ( V_4 -> V_8 == 6 ) {
char * V_101 = NULL ;
switch ( V_4 -> V_9 ) {
case 5 :
if ( V_84 == 0 )
V_101 = L_15 ;
else if ( V_84 == 256 )
V_101 = L_16 ;
break;
case 6 :
if ( V_84 == 128 )
V_101 = L_17 ;
else if ( V_4 -> V_25 == 0 || V_4 -> V_25 == 5 )
V_101 = L_18 ;
break;
case 8 :
if ( V_84 == 128 )
V_101 = L_19 ;
break;
}
if ( V_101 )
strcpy ( V_4 -> V_102 , V_101 ) ;
}
if ( V_4 -> V_8 == 15 )
F_8 ( V_4 , V_103 ) ;
if ( V_4 -> V_8 == 6 )
F_8 ( V_4 , V_104 ) ;
#endif
F_35 ( V_4 ) ;
if ( F_3 ( V_4 , V_105 ) )
F_45 ( V_4 ) ;
F_53 ( V_4 ) ;
F_59 ( V_4 ) ;
}
static unsigned int F_68 ( struct V_3 * V_4 , unsigned int V_106 )
{
if ( ( V_4 -> V_8 == 6 ) && ( V_4 -> V_9 == 11 ) && ( V_106 == 0 ) )
V_106 = 256 ;
if ( ( V_4 -> V_8 == 5 ) && ( V_4 -> V_9 == 9 ) )
V_106 = 16 ;
return V_106 ;
}
static void F_69 ( const unsigned char V_107 )
{
unsigned char V_108 ;
if ( V_107 == 0 )
return;
for ( V_108 = 0 ; V_109 [ V_108 ] . V_110 != V_107 && \
V_109 [ V_108 ] . V_110 != 0 ; V_108 ++ )
;
if ( V_109 [ V_108 ] . V_111 == 0 )
return;
switch ( V_109 [ V_108 ] . V_111 ) {
case V_112 :
if ( V_113 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_113 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_116 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_116 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_117 :
if ( V_113 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_113 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_116 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_116 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_118 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_118 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_119 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_119 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_120 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_120 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_121 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_121 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_122 :
if ( V_113 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_113 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_118 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_118 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_120 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_120 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_123 :
if ( V_113 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_113 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_124 :
if ( V_120 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_120 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_125 :
if ( V_118 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_118 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_120 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_120 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_126 :
case V_127 :
if ( V_116 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_116 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_128 :
case V_129 :
if ( V_121 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_121 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_130 :
case V_131 :
if ( V_119 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_119 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_121 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_121 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_132 :
if ( V_116 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_116 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
if ( V_121 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_121 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
case V_133 :
if ( V_134 [ V_114 ] < V_109 [ V_108 ] . V_115 )
V_134 [ V_114 ] = V_109 [ V_108 ] . V_115 ;
break;
}
}
static void F_70 ( struct V_3 * V_4 )
{
int V_135 , V_136 , V_137 ;
unsigned int V_138 [ 4 ] ;
unsigned char * V_107 = ( unsigned char * ) V_138 ;
if ( V_4 -> V_21 < 2 )
return;
V_137 = F_12 ( 2 ) & 0xFF ;
for ( V_135 = 0 ; V_135 < V_137 ; V_135 ++ ) {
F_20 ( 2 , & V_138 [ 0 ] , & V_138 [ 1 ] , & V_138 [ 2 ] , & V_138 [ 3 ] ) ;
for ( V_136 = 0 ; V_136 < 3 ; V_136 ++ )
if ( V_138 [ V_136 ] & ( 1 << 31 ) )
V_138 [ V_136 ] = 0 ;
for ( V_136 = 1 ; V_136 < 16 ; V_136 ++ )
F_69 ( V_107 [ V_136 ] ) ;
}
}
