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
if ( V_4 -> V_8 >= 6 && ! F_3 ( V_4 , V_14 ) )
V_4 -> V_15 = F_11 () ;
if ( V_4 -> V_8 == 6 && V_4 -> V_9 == 0x1c && V_4 -> V_16 <= 2 &&
V_4 -> V_15 < 0x20e ) {
F_5 ( L_2 ) ;
F_12 ( V_4 , V_17 ) ;
}
#ifdef F_13
F_10 ( V_4 , V_18 ) ;
#else
if ( V_4 -> V_8 == 15 && V_4 -> V_19 == 64 )
V_4 -> V_19 = 128 ;
#endif
if ( V_4 -> V_8 == 0xF && V_4 -> V_9 == 0x3
&& ( V_4 -> V_16 == 0x3 || V_4 -> V_16 == 0x4 ) )
V_4 -> V_20 = 36 ;
if ( V_4 -> V_21 & ( 1 << 8 ) ) {
F_10 ( V_4 , V_13 ) ;
F_10 ( V_4 , V_22 ) ;
if ( ! F_14 () )
F_15 () ;
}
if ( V_4 -> V_8 == 6 ) {
switch ( V_4 -> V_9 ) {
case 0x27 :
case 0x35 :
case 0x4a :
F_10 ( V_4 , V_23 ) ;
break;
default:
break;
}
}
if ( V_4 -> V_8 == 6 && V_4 -> V_9 < 15 )
F_12 ( V_4 , V_24 ) ;
#ifdef F_16
if ( V_4 -> V_8 == 15 )
if ( F_7 ( V_10 ,
V_25 ) > 0 )
F_17 ( L_3 ) ;
#endif
if ( V_4 -> V_8 > 6 || ( V_4 -> V_8 == 6 && V_4 -> V_9 >= 0xd ) ) {
F_18 ( V_10 , V_7 ) ;
if ( ! ( V_7 & V_26 ) ) {
F_17 ( L_4 ) ;
F_4 ( V_27 ) ;
F_4 ( V_28 ) ;
}
}
if ( V_4 -> V_8 == 5 && V_4 -> V_9 == 9 ) {
F_17 ( L_5 ) ;
F_4 ( V_29 ) ;
}
if ( V_4 -> V_12 >= 0x00000001 ) {
T_3 V_30 , V_31 , V_32 , V_33 ;
F_19 ( 0x00000001 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
if ( V_33 & ( 1U << 28 ) )
V_4 -> V_34 = F_20 ( ( V_31 >> 16 ) & 0xff ) ;
}
F_2 ( V_4 ) ;
}
int F_21 ( void )
{
if ( V_35 . V_36 == V_37 &&
V_35 . V_8 == 6 &&
V_35 . V_9 == 1 &&
V_35 . V_16 < 8 ) {
F_17 ( L_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_38 )
return;
if ( V_4 -> V_8 == 5 &&
V_4 -> V_16 >= 1 && V_4 -> V_16 <= 4 &&
V_4 -> V_9 <= 3 ) {
F_23 ( 1 , L_7
L_8 ) ;
}
}
static int T_1 F_24 ( char * V_1 )
{
V_39 = 1 ;
return 1 ;
}
static void F_25 ( struct V_3 * V_4 )
{
#ifdef F_26
F_27 ( V_4 , V_40 ) ;
if ( V_4 -> V_8 == 5 && V_4 -> V_9 < 9 ) {
static int V_41 ;
F_28 ( V_4 , V_40 ) ;
if ( ! V_41 ) {
F_29 ( L_9 ) ;
V_41 = 1 ;
}
}
#endif
if ( ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 | V_4 -> V_16 ) < 0x633 )
F_12 ( V_4 , V_42 ) ;
if ( V_39 ) {
F_5 ( L_10 ) ;
F_10 ( V_4 , V_43 ) ;
F_30 ( V_44 , V_45 ) ;
}
if ( ( V_4 -> V_8 == 15 ) && ( V_4 -> V_9 == 1 ) && ( V_4 -> V_16 == 1 ) ) {
if ( F_31 ( V_10 ,
V_46 ) > 0 ) {
F_17 ( L_11 ) ;
F_17 ( L_12 ) ;
}
}
if ( F_32 ( V_47 ) && ( V_4 -> V_8 << 8 | V_4 -> V_9 << 4 ) == 0x520 &&
( V_4 -> V_16 < 0x6 || V_4 -> V_16 == 0xb ) )
F_28 ( V_4 , V_48 ) ;
#ifdef F_33
switch ( V_4 -> V_8 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_49 . V_50 = 7 ;
break;
case 15 :
V_49 . V_50 = 7 ;
break;
}
#endif
F_22 ( V_4 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
}
static void F_34 ( struct V_3 * V_4 )
{
#ifdef F_35
unsigned V_51 ;
int V_52 = F_36 () ;
V_51 = F_37 ( V_52 ) ;
if ( V_51 == V_53 || ! F_38 ( V_51 ) ) {
V_51 = F_39 ( V_52 ) ;
}
F_40 ( V_52 , V_51 ) ;
#endif
}
static int F_41 ( struct V_3 * V_4 )
{
unsigned int V_30 , V_31 , V_32 , V_33 ;
if ( ! F_42 ( V_54 ) || V_4 -> V_12 < 4 )
return 1 ;
F_43 ( 4 , 0 , & V_30 , & V_31 , & V_32 , & V_33 ) ;
if ( V_30 & 0x1f )
return ( V_30 >> 26 ) + 1 ;
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
T_3 V_55 , V_56 , V_57 , V_58 ;
F_12 ( V_4 , V_59 ) ;
F_12 ( V_4 , V_60 ) ;
F_12 ( V_4 , V_61 ) ;
F_12 ( V_4 , V_62 ) ;
F_12 ( V_4 , V_63 ) ;
F_51 ( V_64 , V_55 , V_56 ) ;
V_57 = V_56 | V_55 ;
if ( V_57 & F_45 )
F_10 ( V_4 , V_59 ) ;
if ( V_57 & F_46 )
F_10 ( V_4 , V_60 ) ;
if ( V_57 & F_47 ) {
F_51 ( V_65 ,
V_55 , V_56 ) ;
V_58 = V_56 | V_55 ;
if ( ( V_58 & F_48 ) &&
( V_57 & F_45 ) )
F_10 ( V_4 , V_61 ) ;
if ( V_58 & F_49 )
F_10 ( V_4 , V_62 ) ;
if ( V_58 & F_50 )
F_10 ( V_4 , V_63 ) ;
}
}
static void F_52 ( struct V_3 * V_4 )
{
T_2 V_66 ;
if ( ! F_3 ( V_4 , V_67 ) )
return;
F_18 ( V_68 , V_66 ) ;
if ( ( V_66 & 0xF ) != V_69 )
return;
F_53 ( L_13 ) ;
F_53 ( L_14 ) ;
V_66 = ( V_66 & ~ 0xF ) | V_70 ;
F_54 ( V_68 , V_66 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
F_52 ( V_4 ) ;
}
static void F_56 ( struct V_3 * V_4 )
{
unsigned int V_71 = 0 ;
F_6 ( V_4 ) ;
F_25 ( V_4 ) ;
F_57 ( V_4 ) ;
if ( ! F_3 ( V_4 , V_72 ) ) {
V_4 -> V_73 = F_41 ( V_4 ) ;
#ifdef F_58
F_59 ( V_4 ) ;
#endif
}
V_71 = F_60 ( V_4 ) ;
if ( V_71 == 0 ) {
F_61 ( V_4 ) ;
V_71 = V_4 -> V_74 ;
}
if ( V_4 -> V_12 > 9 ) {
unsigned V_30 = F_8 ( 10 ) ;
if ( ( V_30 & 0xff ) && ( ( ( V_30 >> 8 ) & 0xff ) > 1 ) )
F_10 ( V_4 , V_75 ) ;
}
if ( F_3 ( V_4 , V_76 ) )
F_10 ( V_4 , V_77 ) ;
if ( F_32 ( V_78 ) ) {
unsigned int V_79 ;
F_51 ( V_10 , V_79 , V_71 ) ;
if ( ! ( V_79 & ( 1 << 11 ) ) )
F_10 ( V_4 , V_80 ) ;
if ( ! ( V_79 & ( 1 << 12 ) ) )
F_10 ( V_4 , V_81 ) ;
}
if ( V_4 -> V_8 == 6 && F_32 ( V_82 ) &&
( V_4 -> V_9 == 29 || V_4 -> V_9 == 46 || V_4 -> V_9 == 47 ) )
F_28 ( V_4 , V_83 ) ;
if ( V_4 -> V_8 == 6 && F_32 ( V_84 ) &&
( ( V_4 -> V_9 == V_85 ) ) )
F_28 ( V_4 , V_86 ) ;
#ifdef F_13
if ( V_4 -> V_8 == 15 )
V_4 -> V_19 = V_4 -> V_87 * 2 ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_27 ) ;
#else
if ( V_4 -> V_8 == 6 ) {
char * V_88 = NULL ;
switch ( V_4 -> V_9 ) {
case 5 :
if ( V_71 == 0 )
V_88 = L_15 ;
else if ( V_71 == 256 )
V_88 = L_16 ;
break;
case 6 :
if ( V_71 == 128 )
V_88 = L_17 ;
else if ( V_4 -> V_16 == 0 || V_4 -> V_16 == 5 )
V_88 = L_18 ;
break;
case 8 :
if ( V_71 == 128 )
V_88 = L_19 ;
break;
}
if ( V_88 )
strcpy ( V_4 -> V_89 , V_88 ) ;
}
if ( V_4 -> V_8 == 15 )
F_10 ( V_4 , V_90 ) ;
if ( V_4 -> V_8 == 6 )
F_10 ( V_4 , V_91 ) ;
#endif
F_34 ( V_4 ) ;
if ( F_3 ( V_4 , V_92 ) )
F_44 ( V_4 ) ;
F_52 ( V_4 ) ;
}
static unsigned int F_62 ( struct V_3 * V_4 , unsigned int V_93 )
{
if ( ( V_4 -> V_8 == 6 ) && ( V_4 -> V_9 == 11 ) && ( V_93 == 0 ) )
V_93 = 256 ;
if ( ( V_4 -> V_8 == 5 ) && ( V_4 -> V_9 == 9 ) )
V_93 = 16 ;
return V_93 ;
}
static void F_63 ( const unsigned char V_94 )
{
unsigned char V_95 ;
if ( V_94 == 0 )
return;
for ( V_95 = 0 ; V_96 [ V_95 ] . V_97 != V_94 && \
V_96 [ V_95 ] . V_97 != 0 ; V_95 ++ )
;
if ( V_96 [ V_95 ] . V_98 == 0 )
return;
switch ( V_96 [ V_95 ] . V_98 ) {
case V_99 :
if ( V_100 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_100 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_103 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_103 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_104 :
if ( V_100 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_100 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_103 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_103 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_105 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_105 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_106 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_106 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_107 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_107 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_108 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_108 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_109 :
if ( V_100 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_100 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_105 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_105 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_107 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_107 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_110 :
if ( V_100 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_100 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_111 :
if ( V_107 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_107 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_112 :
if ( V_105 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_105 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_107 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_107 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_113 :
case V_114 :
if ( V_103 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_103 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_115 :
case V_116 :
if ( V_108 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_108 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_117 :
case V_118 :
if ( V_106 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_106 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_108 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_108 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_119 :
if ( V_103 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_103 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
if ( V_108 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_108 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
case V_120 :
if ( V_121 [ V_101 ] < V_96 [ V_95 ] . V_102 )
V_121 [ V_101 ] = V_96 [ V_95 ] . V_102 ;
break;
}
}
static void F_64 ( struct V_3 * V_4 )
{
int V_122 , V_123 , V_124 ;
unsigned int V_125 [ 4 ] ;
unsigned char * V_94 = ( unsigned char * ) V_125 ;
if ( V_4 -> V_12 < 2 )
return;
V_124 = F_8 ( 2 ) & 0xFF ;
for ( V_122 = 0 ; V_122 < V_124 ; V_122 ++ ) {
F_19 ( 2 , & V_125 [ 0 ] , & V_125 [ 1 ] , & V_125 [ 2 ] , & V_125 [ 3 ] ) ;
for ( V_123 = 0 ; V_123 < 3 ; V_123 ++ )
if ( V_125 [ V_123 ] & ( 1 << 31 ) )
V_125 [ V_123 ] = 0 ;
for ( V_123 = 1 ; V_123 < 16 ; V_123 ++ )
F_63 ( V_94 [ V_123 ] ) ;
}
}
