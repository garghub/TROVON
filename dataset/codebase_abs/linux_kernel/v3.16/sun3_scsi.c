static inline unsigned char F_1 ( int V_1 )
{
return ( V_2 [ V_1 ] ) ;
}
static inline void F_2 ( int V_1 , int V_3 )
{
V_2 [ V_1 ] = V_3 ;
}
static inline unsigned short F_3 ( unsigned char V_1 )
{
unsigned short V_4 ;
V_5 -> V_6 = V_7 ;
F_4 ( V_8 ) ;
V_4 = V_5 -> V_9 ;
F_4 ( V_8 ) ;
return V_4 ;
}
static inline void F_5 ( unsigned short V_10 , unsigned char V_1 )
{
V_5 -> V_6 = V_1 ;
F_4 ( V_8 ) ;
V_5 -> V_9 = V_10 ;
F_4 ( V_8 ) ;
}
static int T_1 F_6 ( struct V_11 * V_12 )
{
unsigned long V_13 , V_14 ;
static int V_15 = 0 ;
struct V_16 * V_17 ;
#ifdef F_7
int V_18 ;
unsigned long V_19 [ 3 ] = { V_20 ,
V_20 + 0x4000 ,
0 } ;
unsigned long V_21 [ 3 ] = { V_22 ,
V_23 ,
0 } ;
#endif
switch( V_24 -> V_25 ) {
#ifdef F_7
case V_26 | V_27 :
case V_26 | V_28 :
break;
#else
case V_26 | V_29 :
case V_26 | V_30 :
break;
#endif
default:
return 0 ;
}
if( V_15 )
return 0 ;
#ifdef F_7
V_12 -> V_31 = L_1 ;
#else
V_12 -> V_31 = L_2 ;
#endif
V_12 -> V_32 =
( V_33 > 0 ) ? V_33 : V_34 ;
V_12 -> V_35 =
( V_36 > 0 ) ? V_36 : V_37 ;
V_12 -> V_38 =
( V_39 >= 0 ) ? V_39 : V_40 ;
if ( V_41 >= 0 )
V_12 -> V_42 = V_41 ;
else {
V_12 -> V_42 = 7 ;
}
#ifdef F_7
V_13 = 0 ;
for ( V_18 = 0 ; V_19 [ V_18 ] != 0 ; V_18 ++ ) {
unsigned char V_43 ;
V_13 = ( unsigned long ) F_8 ( V_19 [ V_18 ] , V_44 ,
V_45 ) ;
V_14 = V_21 [ V_18 ] ;
V_2 = ( unsigned char * ) V_13 ;
V_5 = (struct V_46 * ) ( ( ( unsigned char * ) V_13 ) + 8 ) ;
if ( F_9 ( ( unsigned long ) V_5 , & V_43 ) ) {
unsigned short V_47 ;
V_47 = V_5 -> V_48 ;
V_5 -> V_48 = 0 ;
F_4 ( V_8 ) ;
if ( V_5 -> V_48 == 0x1400 )
break;
V_5 -> V_48 = V_47 ;
}
F_10 ( ( void * ) V_13 ) ;
V_13 = 0 ;
}
if ( ! V_13 )
return 0 ;
#else
V_14 = V_49 ;
V_13 = ( unsigned long ) F_11 ( V_50 , V_44 ) ;
V_2 = ( unsigned char * ) V_13 ;
V_5 = (struct V_46 * ) ( ( ( unsigned char * ) V_13 ) + 8 ) ;
if( ( V_51 = F_12 ( sizeof( struct V_52 ) ) )
== NULL ) {
F_13 ( L_3 ) ;
return 0 ;
}
#endif
#ifdef F_14
if ( V_53 < 0 )
V_53 = V_54 ;
#endif
V_17 = F_15 ( V_12 , sizeof( struct V_55 ) ) ;
if( V_17 == NULL )
return 0 ;
V_56 = V_17 ;
V_17 -> V_57 = ( unsigned long ) V_13 ;
V_17 -> V_14 = V_14 ;
F_16 ( V_17 , 0 ) ;
V_17 -> V_58 = 32 ;
( (struct V_55 * ) V_17 -> V_59 ) -> V_60 = 0 ;
if ( F_17 ( V_17 -> V_14 , V_61 ,
0 , L_4 , V_17 ) ) {
#ifndef F_18
F_13 ( L_5 ,
V_17 -> V_62 , V_17 -> V_14 ) ;
V_17 -> V_14 = V_63 ;
#else
F_13 ( L_6 ,
V_17 -> V_62 , V_17 -> V_14 ) ;
return 0 ;
#endif
}
F_19 ( L_7 , V_17 -> V_62 ,
V_12 -> V_31 , V_17 -> V_57 ) ;
if ( V_17 -> V_14 == V_63 )
F_13 ( L_8 ) ;
else
F_13 ( L_9 , V_17 -> V_14 ) ;
F_13 ( L_10 ,
V_17 -> V_32 , V_17 -> V_35 ,
V_64 ) ;
F_13 ( L_11 , V_17 -> V_62 ) ;
F_20 ( V_17 ) ;
F_13 ( L_12 ) ;
V_5 -> V_48 = 0 ;
F_4 ( V_8 ) ;
V_5 -> V_48 = V_65 | V_66 | V_67 ;
F_4 ( V_8 ) ;
V_5 -> V_68 = 0 ;
#ifdef F_7
V_5 -> V_69 = 0 ;
V_5 -> V_70 = 0 ;
V_5 -> V_71 = 0 ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 0 ;
V_5 -> V_74 = V_75 | ( V_17 -> V_14 & 0xff ) ;
#endif
V_15 = 1 ;
#ifdef F_21
F_22 ( V_17 ) ;
#endif
return 1 ;
}
int F_23 ( struct V_16 * V_76 )
{
if ( V_76 -> V_14 != V_63 )
F_24 ( V_76 -> V_14 , V_76 ) ;
F_10 ( ( void * ) V_2 ) ;
F_25 ( V_76 ) ;
return 0 ;
}
static void F_22 ( struct V_16 * V_17 )
{
unsigned long V_77 ;
F_26 () ;
F_27 ( V_17 ) ;
F_13 ( L_13 ) ;
F_28 ( V_78 ,
F_29 ( F_30 ( V_79 ) ) ) ;
F_28 ( V_80 , V_81 | V_82 ) ;
F_4 ( 50 ) ;
F_28 ( V_80 , V_81 ) ;
F_30 ( V_83 ) ;
for( V_77 = V_84 + V_85 ; F_31 ( V_84 , V_77 ) ; )
F_32 () ;
F_13 ( L_14 ) ;
}
static const char * F_33 ( struct V_16 * V_86 )
{
return L_15 ;
}
static T_2 V_61 ( int V_14 , void * V_87 )
{
unsigned short V_48 = V_5 -> V_48 ;
int V_88 = 0 ;
#ifdef F_7
V_5 -> V_48 &= ~ V_89 ;
#endif
if( V_48 & ~ V_90 ) {
if( V_48 & V_91 ) {
F_13 ( L_16 , V_56 -> V_62 ) ;
}
if( V_48 & V_92 ) {
F_13 ( L_17 , V_56 -> V_62 ) ;
}
V_88 = 1 ;
}
if( V_48 & ( V_93 | V_94 ) ) {
F_34 ( V_14 , V_87 ) ;
V_88 = 1 ;
}
return F_35 ( V_88 ) ;
}
static unsigned long F_36 ( void * V_95 , unsigned long V_96 , int V_97 )
{
void * V_98 ;
if( V_99 != NULL )
F_37 ( V_99 ) ;
#ifdef F_7
V_98 = ( void * ) F_38 ( ( unsigned long ) V_95 , V_96 ) ;
#else
V_98 = ( void * ) F_39 ( ( unsigned long ) V_95 , V_96 ) ;
#endif
V_99 = V_98 ;
V_100 = V_96 ;
#ifndef F_7
V_5 -> V_68 = 0 ;
F_5 ( V_101 , V_7 ) ;
V_5 -> V_48 &= ~ V_66 ;
V_5 -> V_48 |= V_66 ;
#endif
if( V_97 )
V_5 -> V_48 |= V_102 ;
else
V_5 -> V_48 &= ~ V_102 ;
#ifdef F_7
V_5 -> V_48 |= V_103 ;
V_5 -> V_70 = ( ( unsigned long ) V_98 >> 16 ) ;
V_5 -> V_71 = ( ( unsigned long ) V_98 & 0xffff ) ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 0 ;
V_5 -> V_69 = 0 ;
V_5 -> V_68 = 0 ;
#else
V_5 -> V_68 = V_96 ;
F_5 ( V_101 , V_7 ) ;
V_5 -> V_48 &= ~ V_66 ;
V_5 -> V_48 |= V_66 ;
if( V_5 -> V_68 != V_96 ) {
F_13 ( L_18 ,
V_56 -> V_62 , V_5 -> V_68 ,
( unsigned int ) V_96 ) ;
F_40 ( V_104 , V_56 ) ;
}
V_51 -> V_105 = ( ( ( unsigned long ) ( V_98 ) & 0xff0000 ) >> 8 ) ;
V_51 -> V_106 = ( ( unsigned long ) ( V_98 ) & 0xffff ) ;
V_51 -> V_96 = V_96 / 2 ;
V_51 -> V_107 = V_108 ;
if( V_97 ) {
if( V_96 & 1 )
V_51 -> V_96 ++ ;
V_51 -> V_109 = V_110 ;
V_51 -> V_111 = V_112 ;
} else {
V_51 -> V_109 = V_113 ;
V_51 -> V_111 = V_114 ;
}
F_5 ( ( ( F_41 ( V_51 ) & 0xff0000 ) >> 8 ) ,
V_115 ) ;
F_5 ( ( F_41 ( V_51 ) & 0xffff ) , V_116 ) ;
F_5 ( 0xd , V_117 ) ;
F_5 ( V_118 , V_7 ) ;
#endif
return V_96 ;
}
static inline unsigned long F_42 ( struct V_16 * V_17 )
{
unsigned short V_119 ;
V_5 -> V_6 = 0x32 ;
F_4 ( V_8 ) ;
V_119 = V_5 -> V_9 ;
F_4 ( V_8 ) ;
V_119 *= 2 ;
return ( unsigned long ) V_119 ;
}
static inline unsigned long F_43 ( struct V_16 * V_17 )
{
return V_120 ;
}
static inline unsigned long F_44 ( unsigned long V_121 ,
struct V_122 * V_123 ,
int V_97 )
{
if ( V_123 -> V_124 -> V_125 == V_126 )
return V_121 ;
else
return 0 ;
}
static inline int F_45 ( unsigned long V_96 , unsigned char * V_95 )
{
#ifdef F_7
unsigned short V_48 ;
V_48 = V_5 -> V_48 ;
V_5 -> V_72 = ( V_100 >> 16 ) ;
V_5 -> V_73 = ( V_100 & 0xffff ) ;
V_5 -> V_69 = ( V_100 >> 16 ) ;
V_5 -> V_68 = ( V_100 & 0xffff ) ;
#else
F_5 ( V_127 , V_7 ) ;
#endif
return 0 ;
}
static int F_46 ( int V_97 )
{
unsigned short T_3 V_96 ;
unsigned short V_128 ;
int V_4 = 0 ;
V_129 = 0 ;
#ifdef F_7
V_5 -> V_48 &= ~ V_89 ;
V_128 = V_5 -> V_68 ;
if ( V_97 ) {
if ( ( V_128 > 0 ) && ( V_128 < V_100 ) )
V_128 ++ ;
}
V_120 = V_128 ;
if ( ( ! V_97 ) && ( V_5 -> V_48 & V_130 ) ) {
unsigned char * V_131 ;
V_131 = ( unsigned char * ) F_47 ( V_99 ) ;
V_131 += ( V_100 - V_128 ) ;
V_131 -- ;
switch ( V_5 -> V_48 & V_130 ) {
case V_132 :
* V_131 = ( V_5 -> V_133 & 0xff00 ) >> 8 ;
V_131 -- ;
case V_134 :
* V_131 = ( V_5 -> V_135 & 0x00ff ) ;
V_131 -- ;
case V_136 :
* V_131 = ( V_5 -> V_135 & 0xff00 ) >> 8 ;
break;
}
}
#else
if( ! V_97 ) {
int V_137 = 20000 ;
while( 1 ) {
if( V_5 -> V_48 & V_138 )
break;
if( -- V_137 <= 0 ) {
F_13 ( L_19 ) ;
return 1 ;
}
F_4 ( 10 ) ;
}
}
V_96 = F_42 ( V_56 ) ;
V_128 = V_5 -> V_68 ;
V_120 = V_128 ;
if( ( ! V_97 ) && ( V_96 - V_128 ) == 2 ) {
unsigned short V_95 ;
unsigned char * V_131 ;
V_95 = V_5 -> V_139 ;
V_131 = ( unsigned char * ) F_48 ( V_99 ) ;
V_131 += ( V_100 - V_128 ) ;
V_131 [ - 2 ] = ( V_95 & 0xff00 ) >> 8 ;
V_131 [ - 1 ] = ( V_95 & 0xff ) ;
}
#endif
F_37 ( V_99 ) ;
V_99 = NULL ;
#ifdef F_7
V_5 -> V_70 = 0 ;
V_5 -> V_71 = 0 ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 0 ;
V_5 -> V_68 = 0 ;
V_5 -> V_69 = 0 ;
V_5 -> V_48 &= ~ V_102 ;
#else
F_5 ( V_101 , V_7 ) ;
V_5 -> V_68 = 0 ;
V_5 -> V_48 &= ~ V_102 ;
V_5 -> V_48 &= ~ V_66 ;
V_5 -> V_48 |= V_66 ;
#endif
V_140 = NULL ;
return V_4 ;
}
