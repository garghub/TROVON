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
F_10 ( L_1 ) ;
F_11 ( V_2 , V_15 ) ;
}
#ifdef F_12
F_5 ( V_2 , V_16 ) ;
#else
if ( V_2 -> V_4 == 15 && V_2 -> V_17 == 64 )
V_2 -> V_17 = 128 ;
#endif
if ( V_2 -> V_4 == 0xF && V_2 -> V_5 == 0x3
&& ( V_2 -> V_14 == 0x3 || V_2 -> V_14 == 0x4 ) )
V_2 -> V_18 = 36 ;
if ( V_2 -> V_19 & ( 1 << 8 ) ) {
F_5 ( V_2 , V_9 ) ;
F_5 ( V_2 , V_20 ) ;
if ( ! F_13 () )
F_14 () ;
}
if ( V_2 -> V_4 == 6 ) {
switch ( V_2 -> V_5 ) {
case 0x27 :
case 0x35 :
case 0x4a :
F_5 ( V_2 , V_21 ) ;
break;
default:
break;
}
}
if ( V_2 -> V_4 == 6 && V_2 -> V_5 < 15 )
F_11 ( V_2 , V_22 ) ;
#ifdef F_15
if ( V_2 -> V_4 == 15 )
if ( F_2 ( V_6 ,
V_23 ) > 0 )
F_16 ( L_2 ) ;
#endif
if ( V_2 -> V_4 > 6 || ( V_2 -> V_4 == 6 && V_2 -> V_5 >= 0xd ) ) {
F_17 ( V_6 , V_3 ) ;
if ( ! ( V_3 & V_24 ) ) {
F_16 ( L_3 ) ;
F_18 ( V_25 ) ;
F_18 ( V_26 ) ;
}
}
if ( V_2 -> V_4 == 5 && V_2 -> V_5 == 9 ) {
F_16 ( L_4 ) ;
F_18 ( V_27 ) ;
}
if ( V_2 -> V_8 >= 0x00000001 ) {
T_2 V_28 , V_29 , V_30 , V_31 ;
F_19 ( 0x00000001 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
if ( V_31 & ( 1U << 28 ) )
V_2 -> V_32 = F_20 ( ( V_29 >> 16 ) & 0xff ) ;
}
}
int F_21 ( void )
{
if ( V_33 . V_34 == V_35 &&
V_33 . V_4 == 6 &&
V_33 . V_5 == 1 &&
V_33 . V_14 < 8 ) {
F_16 ( L_5 ) ;
return 1 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return;
if ( V_2 -> V_4 == 5 &&
V_2 -> V_14 >= 1 && V_2 -> V_14 <= 4 &&
V_2 -> V_5 <= 3 ) {
F_23 ( 1 , L_6
L_7 ) ;
}
}
static int T_3 F_24 ( char * V_37 )
{
V_38 = 1 ;
return 1 ;
}
static void F_25 ( struct V_1 * V_2 )
{
#ifdef F_26
F_27 ( V_2 , V_39 ) ;
if ( ! F_28 () && V_2 -> V_4 == 5 && V_2 -> V_5 < 9 ) {
static int V_40 ;
F_29 ( V_2 , V_39 ) ;
if ( ! V_40 ) {
F_30 ( L_8 ) ;
V_40 = 1 ;
}
}
#endif
if ( ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 | V_2 -> V_14 ) < 0x633 )
F_11 ( V_2 , V_41 ) ;
if ( V_38 ) {
F_10 ( L_9 ) ;
F_5 ( V_2 , V_42 ) ;
F_31 ( V_43 , V_44 ) ;
}
if ( ( V_2 -> V_4 == 15 ) && ( V_2 -> V_5 == 1 ) && ( V_2 -> V_14 == 1 ) ) {
if ( F_32 ( V_6 ,
V_45 )
> 0 ) {
F_16 ( L_10 ) ;
F_16 ( L_11 ) ;
}
}
if ( V_46 && ( V_2 -> V_4 << 8 | V_2 -> V_5 << 4 ) == 0x520 &&
( V_2 -> V_14 < 0x6 || V_2 -> V_14 == 0xb ) )
F_29 ( V_2 , V_47 ) ;
#ifdef F_33
switch ( V_2 -> V_4 ) {
case 4 :
break;
case 5 :
break;
case 6 :
V_48 . V_49 = 7 ;
break;
case 15 :
V_48 . V_49 = 7 ;
break;
}
#endif
F_22 ( V_2 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_34 ( struct V_1 * V_2 )
{
#ifdef F_35
unsigned V_50 ;
int V_51 = F_36 () ;
V_50 = F_37 ( V_51 ) ;
if ( V_50 == V_52 || ! F_38 ( V_50 ) ) {
V_50 = F_39 ( V_51 ) ;
}
F_40 ( V_51 , V_50 ) ;
#endif
}
static int F_41 ( struct V_1 * V_2 )
{
unsigned int V_28 , V_29 , V_30 , V_31 ;
if ( ! F_42 ( V_53 ) || V_2 -> V_8 < 4 )
return 1 ;
F_43 ( 4 , 0 , & V_28 , & V_29 , & V_30 , & V_31 ) ;
if ( V_28 & 0x1f )
return ( V_28 >> 26 ) + 1 ;
else
return 1 ;
}
static void F_44 ( struct V_1 * V_2 )
{
#define F_45 0x00200000
#define F_46 0x00400000
#define F_47 0x80000000
#define F_48 0x00000001
#define F_49 0x00000002
#define F_50 0x00000020
T_2 V_54 , V_55 , V_56 , V_57 ;
F_11 ( V_2 , V_58 ) ;
F_11 ( V_2 , V_59 ) ;
F_11 ( V_2 , V_60 ) ;
F_11 ( V_2 , V_61 ) ;
F_11 ( V_2 , V_62 ) ;
F_9 ( V_63 , V_54 , V_55 ) ;
V_56 = V_55 | V_54 ;
if ( V_56 & F_45 )
F_5 ( V_2 , V_58 ) ;
if ( V_56 & F_46 )
F_5 ( V_2 , V_59 ) ;
if ( V_56 & F_47 ) {
F_9 ( V_64 ,
V_54 , V_55 ) ;
V_57 = V_55 | V_54 ;
if ( ( V_57 & F_48 ) &&
( V_56 & F_45 ) )
F_5 ( V_2 , V_60 ) ;
if ( V_57 & F_49 )
F_5 ( V_2 , V_61 ) ;
if ( V_57 & F_50 )
F_5 ( V_2 , V_62 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_65 ;
if ( ! F_6 ( V_2 , V_66 ) )
return;
F_17 ( V_67 , V_65 ) ;
if ( ( V_65 & 0xF ) != V_68 )
return;
F_52 ( L_12 ) ;
F_52 ( L_13 ) ;
V_65 = ( V_65 & ~ 0xF ) | V_69 ;
F_53 ( V_67 , V_65 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_70 = 0 ;
F_1 ( V_2 ) ;
F_25 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( ! F_6 ( V_2 , V_71 ) ) {
V_2 -> V_72 = F_41 ( V_2 ) ;
#ifdef F_57
F_58 ( V_2 ) ;
#endif
}
V_70 = F_59 ( V_2 ) ;
if ( V_70 == 0 ) {
F_60 ( V_2 ) ;
V_70 = V_2 -> V_73 ;
}
if ( V_2 -> V_8 > 9 ) {
unsigned V_28 = F_3 ( 10 ) ;
if ( ( V_28 & 0xff ) && ( ( ( V_28 >> 8 ) & 0xff ) > 1 ) )
F_5 ( V_2 , V_74 ) ;
}
if ( V_75 )
F_5 ( V_2 , V_76 ) ;
if ( F_61 ( V_77 ) ) {
unsigned int V_78 ;
F_9 ( V_6 , V_78 , V_70 ) ;
if ( ! ( V_78 & ( 1 << 11 ) ) )
F_5 ( V_2 , V_79 ) ;
if ( ! ( V_78 & ( 1 << 12 ) ) )
F_5 ( V_2 , V_80 ) ;
}
if ( V_2 -> V_4 == 6 && V_81 &&
( V_2 -> V_5 == 29 || V_2 -> V_5 == 46 || V_2 -> V_5 == 47 ) )
F_29 ( V_2 , V_82 ) ;
#ifdef F_12
if ( V_2 -> V_4 == 15 )
V_2 -> V_17 = V_2 -> V_83 * 2 ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_25 ) ;
#else
if ( V_2 -> V_4 == 6 ) {
char * V_84 = NULL ;
switch ( V_2 -> V_5 ) {
case 5 :
if ( V_70 == 0 )
V_84 = L_14 ;
else if ( V_70 == 256 )
V_84 = L_15 ;
break;
case 6 :
if ( V_70 == 128 )
V_84 = L_16 ;
else if ( V_2 -> V_14 == 0 || V_2 -> V_14 == 5 )
V_84 = L_17 ;
break;
case 8 :
if ( V_70 == 128 )
V_84 = L_18 ;
break;
}
if ( V_84 )
strcpy ( V_2 -> V_85 , V_84 ) ;
}
if ( V_2 -> V_4 == 15 )
F_5 ( V_2 , V_86 ) ;
if ( V_2 -> V_4 == 6 )
F_5 ( V_2 , V_87 ) ;
#endif
F_34 ( V_2 ) ;
if ( F_6 ( V_2 , V_88 ) )
F_44 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static unsigned int F_62 ( struct V_1 * V_2 , unsigned int V_89 )
{
if ( ( V_2 -> V_4 == 6 ) && ( V_2 -> V_5 == 11 ) && ( V_89 == 0 ) )
V_89 = 256 ;
if ( ( V_2 -> V_4 == 5 ) && ( V_2 -> V_5 == 9 ) )
V_89 = 16 ;
return V_89 ;
}
static void F_63 ( const unsigned char V_90 )
{
unsigned char V_91 ;
if ( V_90 == 0 )
return;
for ( V_91 = 0 ; V_92 [ V_91 ] . V_93 != V_90 && \
V_92 [ V_91 ] . V_93 != 0 ; V_91 ++ )
;
if ( V_92 [ V_91 ] . V_94 == 0 )
return;
switch ( V_92 [ V_91 ] . V_94 ) {
case V_95 :
if ( V_96 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_96 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_99 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_99 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_100 :
if ( V_96 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_96 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_99 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_99 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_101 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_101 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_102 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_102 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_103 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_103 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_104 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_104 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_105 :
if ( V_96 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_96 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_101 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_101 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_103 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_103 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_106 :
if ( V_96 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_96 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_107 :
if ( V_103 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_103 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_108 :
if ( V_101 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_101 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_103 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_103 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_109 :
case V_110 :
if ( V_99 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_99 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_111 :
case V_112 :
if ( V_104 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_104 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_113 :
case V_114 :
if ( V_102 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_102 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_104 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_104 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_115 :
if ( V_99 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_99 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
if ( V_104 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_104 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
case V_116 :
if ( V_117 [ V_97 ] < V_92 [ V_91 ] . V_98 )
V_117 [ V_97 ] = V_92 [ V_91 ] . V_98 ;
break;
}
}
static void F_64 ( struct V_1 * V_2 )
{
int V_118 , V_119 , V_120 ;
unsigned int V_121 [ 4 ] ;
unsigned char * V_90 = ( unsigned char * ) V_121 ;
if ( V_2 -> V_8 < 2 )
return;
V_120 = F_3 ( 2 ) & 0xFF ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
F_19 ( 2 , & V_121 [ 0 ] , & V_121 [ 1 ] , & V_121 [ 2 ] , & V_121 [ 3 ] ) ;
for ( V_119 = 0 ; V_119 < 3 ; V_119 ++ )
if ( V_121 [ V_119 ] & ( 1 << 31 ) )
V_121 [ V_119 ] = 0 ;
for ( V_119 = 1 ; V_119 < 16 ; V_119 ++ )
F_63 ( V_90 [ V_119 ] ) ;
}
}
