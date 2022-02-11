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
static void F_6 ( struct V_3 * V_4 )
{
T_2 V_7 ;
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
if ( F_7 ( V_10 ,
V_11 ) > 0 ) {
V_4 -> V_12 = F_8 ( 0 ) ;
F_9 ( V_4 ) ;
}
}
if ( ( V_4 -> V_8 == 0xf && V_4 -> V_9 >= 0x03 ) ||
( V_4 -> V_8 == 0x6 && V_4 -> V_9 >= 0x0e ) )
F_10 ( V_4 , V_13 ) ;
if ( V_4 -> V_8 >= 6 && ! F_3 ( V_4 , V_14 ) ) {
unsigned V_15 ;
F_11 ( V_16 , 0 , 0 ) ;
F_12 () ;
F_13 ( V_16 , V_15 , V_4 -> V_17 ) ;
}
if ( V_4 -> V_8 == 6 && V_4 -> V_9 == 0x1c && V_4 -> V_18 <= 2 &&
V_4 -> V_17 < 0x20e ) {
F_5 ( L_2 ) ;
F_14 ( V_4 , V_19 ) ;
}
#ifdef F_15
F_10 ( V_4 , V_20 ) ;
#else
if ( V_4 -> V_8 == 15 && V_4 -> V_21 == 64 )
V_4 -> V_21 = 128 ;
#endif
if ( V_4 -> V_8 == 0xF && V_4 -> V_9 == 0x3
&& ( V_4 -> V_18 == 0x3 || V_4 -> V_18 == 0x4 ) )
V_4 -> V_22 = 36 ;
if ( V_4 -> V_23 & ( 1 << 8 ) ) {
F_10 ( V_4 , V_13 ) ;
F_10 ( V_4 , V_24 ) ;
if ( ! F_16 () )
F_17 () ;
}
if ( V_4 -> V_8 == 6 ) {
switch ( V_4 -> V_9 ) {
case 0x27 :
case 0x35 :
case 0x4a :
F_10 ( V_4 , V_25 ) ;
break;
default:
break;
}
}
if ( V_4 -> V_8 == 6 && V_4 -> V_9 < 15 )
F_14 ( V_4 , V_26 ) ;
#ifdef F_18
if ( V_4 -> V_8 == 15 )
if ( F_7 ( V_10 ,
V_27 ) > 0 )
F_19 ( L_3 ) ;
#endif
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
F_20 ( V_10 , V_7 ) ;
if ( ! ( V_7 & V_28 ) ) {
F_19 ( L_4 ) ;
F_4 ( V_29 ) ;
F_4 ( V_30 ) ;
}
}
if ( V_4 -> V_8 == 5 && V_4 -> V_9 == 9 ) {
F_19 ( L_5 ) ;
F_4 ( V_31 ) ;
}
if ( V_4 -> V_12 >= 0x00000001 ) {
T_3 V_32 , V_33 , V_34 , V_35 ;
F_21 ( 0x00000001 , & V_32 , & V_33 , & V_34 , & V_35 ) ;
if ( V_35 & ( 1U << 28 ) )
V_4 -> V_36 = F_22 ( ( V_33 >> 16 ) & 0xff ) ;
}
F_2 ( V_4 ) ;
}
int F_23 ( void )
{
if ( V_37 . V_38 == V_39 &&
V_37 . V_8 == 6 &&
V_37 . V_9 == 1 &&
V_37 . V_18 < 8 ) {
F_19 ( L_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_40 )
return;
if ( V_4 -> V_8 == 5 &&
V_4 -> V_18 >= 1 && V_4 -> V_18 <= 4 &&
V_4 -> V_9 <= 3 ) {
F_25 ( 1 , L_7
L_8 ) ;
}
}
static int T_1 F_26 ( char * V_1 )
{
V_41 = 1 ;
return 1 ;
}
static void F_27 ( struct V_3 * V_4 )
{
#ifdef F_28
F_29 ( V_4 , V_42 ) ;
if ( V_4 -> V_8 == 5 && V_4 -> V_9 < 9 ) {
static int V_43 ;
F_30 ( V_4 , V_42 ) ;
if ( ! V_43 ) {
F_31 ( L_9 ) ;
V_43 = 1 ;
}
}
#endif
if ( ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 | V_4 -> V_18 ) < 0x633 )
F_14 ( V_4 , V_44 ) ;
if ( V_41 ) {
F_5 ( L_10 ) ;
F_10 ( V_4 , V_45 ) ;
F_32 ( V_46 , V_47 ) ;
}
if ( ( V_4 -> V_8 == 15 ) && ( V_4 -> V_9 == 1 ) && ( V_4 -> V_18 == 1 ) ) {
if ( F_33 ( V_10 ,
V_48 ) > 0 ) {
F_19 ( L_11 ) ;
F_19 ( L_12 ) ;
}
}
if ( F_34 ( V_49 ) && ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 ) == 0x520 &&
( V_4 -> V_18 < 0x6 || V_4 -> V_18 == 0xb ) )
F_30 ( V_4 , V_50 ) ;
#ifdef F_35
switch ( V_4 -> V_8 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_51 . V_52 = 7 ;
break;
case 15 :
V_51 . V_52 = 7 ;
break;
}
#endif
F_24 ( V_4 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
}
static void F_36 ( struct V_3 * V_4 )
{
#ifdef F_37
unsigned V_53 ;
int V_54 = F_38 () ;
V_53 = F_39 ( V_54 ) ;
if ( V_53 == V_55 || ! F_40 ( V_53 ) ) {
V_53 = F_41 ( V_54 ) ;
}
F_42 ( V_54 , V_53 ) ;
#endif
}
static int F_43 ( struct V_3 * V_4 )
{
unsigned int V_32 , V_33 , V_34 , V_35 ;
if ( ! F_44 ( V_56 ) || V_4 -> V_12 < 4 )
return 1 ;
F_45 ( 4 , 0 , & V_32 , & V_33 , & V_34 , & V_35 ) ;
if ( V_32 & 0x1f )
return ( V_32 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_46 ( struct V_3 * V_4 )
{
#define F_47 0x00200000
#define F_48 0x00400000
#define F_49 0x80000000
#define F_50 0x00000001
#define F_51 0x00000002
#define F_52 0x00000020
T_3 V_57 , V_58 , V_59 , V_60 ;
F_14 ( V_4 , V_61 ) ;
F_14 ( V_4 , V_62 ) ;
F_14 ( V_4 , V_63 ) ;
F_14 ( V_4 , V_64 ) ;
F_14 ( V_4 , V_65 ) ;
F_13 ( V_66 , V_57 , V_58 ) ;
V_59 = V_58 | V_57 ;
if ( V_59 & F_47 )
F_10 ( V_4 , V_61 ) ;
if ( V_59 & F_48 )
F_10 ( V_4 , V_62 ) ;
if ( V_59 & F_49 ) {
F_13 ( V_67 ,
V_57 , V_58 ) ;
V_60 = V_58 | V_57 ;
if ( ( V_60 & F_50 ) &&
( V_59 & F_47 ) )
F_10 ( V_4 , V_63 ) ;
if ( V_60 & F_51 )
F_10 ( V_4 , V_64 ) ;
if ( V_60 & F_52 )
F_10 ( V_4 , V_65 ) ;
}
}
static void F_53 ( struct V_3 * V_4 )
{
T_2 V_68 ;
if ( ! F_3 ( V_4 , V_69 ) )
return;
F_20 ( V_70 , V_68 ) ;
if ( ( V_68 & 0xF ) != V_71 )
return;
F_54 ( L_13 ) ;
F_54 ( L_14 ) ;
V_68 = ( V_68 & ~ 0xF ) | V_72 ;
F_55 ( V_70 , V_68 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
F_53 ( V_4 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
unsigned int V_73 = 0 ;
F_6 ( V_4 ) ;
F_27 ( V_4 ) ;
F_58 ( V_4 ) ;
if ( ! F_3 ( V_4 , V_74 ) ) {
V_4 -> V_75 = F_43 ( V_4 ) ;
#ifdef F_59
F_60 ( V_4 ) ;
#endif
}
V_73 = F_61 ( V_4 ) ;
if ( V_73 == 0 ) {
F_62 ( V_4 ) ;
V_73 = V_4 -> V_76 ;
}
if ( V_4 -> V_12 > 9 ) {
unsigned V_32 = F_8 ( 10 ) ;
if ( ( V_32 & 0xff ) && ( ( ( V_32 >> 8 ) & 0xff ) > 1 ) )
F_10 ( V_4 , V_77 ) ;
}
if ( F_3 ( V_4 , V_78 ) )
F_10 ( V_4 , V_79 ) ;
if ( F_34 ( V_80 ) ) {
unsigned int V_81 ;
F_13 ( V_10 , V_81 , V_73 ) ;
if ( ! ( V_81 & ( 1 << 11 ) ) )
F_10 ( V_4 , V_82 ) ;
if ( ! ( V_81 & ( 1 << 12 ) ) )
F_10 ( V_4 , V_83 ) ;
}
if ( V_4 -> V_8 == 6 && F_34 ( V_84 ) &&
( V_4 -> V_9 == 29 || V_4 -> V_9 == 46 || V_4 -> V_9 == 47 ) )
F_30 ( V_4 , V_85 ) ;
if ( V_4 -> V_8 == 6 && F_34 ( V_86 ) &&
( ( V_4 -> V_9 == V_87 ) ) )
F_30 ( V_4 , V_88 ) ;
#ifdef F_15
if ( V_4 -> V_8 == 15 )
V_4 -> V_21 = V_4 -> V_89 * 2 ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_29 ) ;
#else
if ( V_4 -> V_8 == 6 ) {
char * V_90 = NULL ;
switch ( V_4 -> V_9 ) {
case 5 :
if ( V_73 == 0 )
V_90 = L_15 ;
else if ( V_73 == 256 )
V_90 = L_16 ;
break;
case 6 :
if ( V_73 == 128 )
V_90 = L_17 ;
else if ( V_4 -> V_18 == 0 || V_4 -> V_18 == 5 )
V_90 = L_18 ;
break;
case 8 :
if ( V_73 == 128 )
V_90 = L_19 ;
break;
}
if ( V_90 )
strcpy ( V_4 -> V_91 , V_90 ) ;
}
if ( V_4 -> V_8 == 15 )
F_10 ( V_4 , V_92 ) ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_93 ) ;
#endif
F_36 ( V_4 ) ;
if ( F_3 ( V_4 , V_94 ) )
F_46 ( V_4 ) ;
F_53 ( V_4 ) ;
}
static unsigned int F_63 ( struct V_3 * V_4 , unsigned int V_95 )
{
if ( ( V_4 -> V_8 == 6 ) && ( V_4 -> V_9 == 11 ) && ( V_95 == 0 ) )
V_95 = 256 ;
if ( ( V_4 -> V_8 == 5 ) && ( V_4 -> V_9 == 9 ) )
V_95 = 16 ;
return V_95 ;
}
static void F_64 ( const unsigned char V_96 )
{
unsigned char V_97 ;
if ( V_96 == 0 )
return;
for ( V_97 = 0 ; V_98 [ V_97 ] . V_99 != V_96 && \
V_98 [ V_97 ] . V_99 != 0 ; V_97 ++ )
;
if ( V_98 [ V_97 ] . V_100 == 0 )
return;
switch ( V_98 [ V_97 ] . V_100 ) {
case V_101 :
if ( V_102 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_102 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_105 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_105 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_106 :
if ( V_102 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_102 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_105 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_105 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_107 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_107 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_108 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_108 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_109 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_109 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_110 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_110 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_111 :
if ( V_102 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_102 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_107 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_107 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_109 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_109 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_112 :
if ( V_102 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_102 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_113 :
if ( V_109 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_109 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_114 :
if ( V_107 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_107 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_109 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_109 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_115 :
case V_116 :
if ( V_105 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_105 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_117 :
case V_118 :
if ( V_110 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_110 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_119 :
case V_120 :
if ( V_108 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_108 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_110 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_110 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_121 :
if ( V_105 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_105 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
if ( V_110 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_110 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
case V_122 :
if ( V_123 [ V_103 ] < V_98 [ V_97 ] . V_104 )
V_123 [ V_103 ] = V_98 [ V_97 ] . V_104 ;
break;
}
}
static void F_65 ( struct V_3 * V_4 )
{
int V_124 , V_125 , V_126 ;
unsigned int V_127 [ 4 ] ;
unsigned char * V_96 = ( unsigned char * ) V_127 ;
if ( V_4 -> V_12 < 2 )
return;
V_126 = F_8 ( 2 ) & 0xFF ;
for ( V_124 = 0 ; V_124 < V_126 ; V_124 ++ ) {
F_21 ( 2 , & V_127 [ 0 ] , & V_127 [ 1 ] , & V_127 [ 2 ] , & V_127 [ 3 ] ) ;
for ( V_125 = 0 ; V_125 < 3 ; V_125 ++ )
if ( V_127 [ V_125 ] & ( 1 << 31 ) )
V_127 [ V_125 ] = 0 ;
for ( V_125 = 1 ; V_125 < 16 ; V_125 ++ )
F_64 ( V_96 [ V_125 ] ) ;
}
}
