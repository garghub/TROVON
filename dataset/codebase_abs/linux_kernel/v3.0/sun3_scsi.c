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
int F_6 ( struct V_11 * V_12 )
{
unsigned long V_13 ;
static int V_14 = 0 ;
struct V_15 * V_16 ;
switch( V_17 -> V_18 ) {
case V_19 | V_20 :
case V_19 | V_21 :
break;
default:
return 0 ;
}
if( V_14 )
return 0 ;
V_12 -> V_22 = L_1 ;
V_12 -> V_23 =
( V_24 > 0 ) ? V_24 : V_25 ;
V_12 -> V_26 =
( V_27 > 0 ) ? V_27 : V_28 ;
V_12 -> V_29 =
( V_30 >= 0 ) ? V_30 : V_31 ;
if ( V_32 >= 0 )
V_12 -> V_33 = V_32 ;
else {
V_12 -> V_33 = 7 ;
}
V_13 = ( unsigned long ) F_7 ( V_34 , V_35 ) ;
V_2 = ( unsigned char * ) V_13 ;
V_5 = (struct V_36 * ) ( ( ( unsigned char * ) V_13 ) + 8 ) ;
if( ( V_37 = F_8 ( sizeof( struct V_38 ) ) )
== NULL ) {
F_9 ( L_2 ) ;
return 0 ;
}
#ifdef F_10
if( ( V_39 = F_11 ( V_40 , 0x10000 ) ) == NULL ) {
F_9 ( L_2 ) ;
return 0 ;
}
#endif
#ifdef F_12
if ( V_41 < 0 )
V_41 = V_42 ;
#endif
V_16 = F_13 ( V_12 , sizeof( struct V_43 ) ) ;
if( V_16 == NULL )
return 0 ;
V_44 = V_16 ;
V_16 -> V_45 = ( unsigned long ) V_13 ;
V_16 -> V_46 = V_47 ;
F_14 ( V_16 , 0 ) ;
V_16 -> V_48 = 32 ;
( (struct V_43 * ) V_16 -> V_49 ) -> V_50 = 0 ;
if ( F_15 ( V_16 -> V_46 , V_51 ,
0 , L_3 , V_16 ) ) {
#ifndef F_16
F_9 ( L_4 ,
V_16 -> V_52 , V_16 -> V_46 ) ;
V_16 -> V_46 = V_53 ;
#else
F_9 ( L_5 ,
V_16 -> V_52 , V_16 -> V_46 ) ;
return 0 ;
#endif
}
F_9 ( L_6 , V_16 -> V_52 , V_16 -> V_45 ) ;
if ( V_16 -> V_46 == V_53 )
F_9 ( L_7 ) ;
else
F_9 ( L_8 , V_16 -> V_46 ) ;
F_9 ( L_9 ,
V_16 -> V_23 , V_16 -> V_26 ,
V_54 ) ;
F_9 ( L_10 , V_16 -> V_52 ) ;
F_17 ( V_16 ) ;
F_9 ( L_11 ) ;
V_5 -> V_55 = 0 ;
F_4 ( V_8 ) ;
V_5 -> V_55 = V_56 | V_57 | V_58 ;
F_4 ( V_8 ) ;
V_5 -> V_59 = 0 ;
V_14 = 1 ;
#ifdef F_18
F_19 ( V_16 ) ;
#endif
return 1 ;
}
int F_20 ( struct V_15 * V_60 )
{
if ( V_60 -> V_46 != V_53 )
F_21 ( V_60 -> V_46 , V_60 ) ;
F_22 ( ( void * ) V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_15 * V_16 )
{
unsigned long V_61 ;
F_23 () ;
F_24 ( V_16 ) ;
F_9 ( L_12 ) ;
F_25 ( V_62 ,
F_26 ( F_27 ( V_63 ) ) ) ;
F_25 ( V_64 , V_65 | V_66 ) ;
F_4 ( 50 ) ;
F_25 ( V_64 , V_65 ) ;
F_27 ( V_67 ) ;
for( V_61 = V_68 + V_69 ; F_28 ( V_68 , V_61 ) ; )
F_29 () ;
F_9 ( L_13 ) ;
}
const char * F_30 ( struct V_15 * V_70 ) {
return L_14 ;
}
static T_1 V_51 ( int V_46 , void * V_71 )
{
unsigned short V_55 = V_5 -> V_55 ;
int V_72 = 0 ;
if( V_55 & ~ V_73 ) {
if( V_55 & V_74 ) {
F_9 ( L_15 , V_44 -> V_52 ) ;
}
if( V_55 & V_75 ) {
F_9 ( L_16 , V_44 -> V_52 ) ;
}
V_72 = 1 ;
}
if( V_55 & ( V_76 | V_77 ) ) {
F_31 ( V_46 , V_71 ) ;
V_72 = 1 ;
}
return F_32 ( V_72 ) ;
}
static unsigned long F_33 ( void * V_78 , unsigned long V_79 , int V_80 )
{
#ifdef F_10
if( V_80 )
memcpy ( V_39 , V_78 , V_79 ) ;
else {
V_81 = V_78 ;
V_82 = V_79 ;
}
#else
void * V_83 ;
if( V_81 != NULL )
F_34 ( V_81 ) ;
V_83 = ( void * ) F_35 ( ( unsigned long ) V_78 , V_79 ) ;
V_81 = V_83 ;
V_82 = V_79 ;
#endif
V_5 -> V_59 = 0 ;
F_5 ( V_84 , V_7 ) ;
V_5 -> V_55 &= ~ V_57 ;
V_5 -> V_55 |= V_57 ;
if( V_80 )
V_5 -> V_55 |= V_85 ;
else
V_5 -> V_55 &= ~ V_85 ;
V_5 -> V_59 = V_79 ;
F_5 ( V_84 , V_7 ) ;
V_5 -> V_55 &= ~ V_57 ;
V_5 -> V_55 |= V_57 ;
if( V_5 -> V_59 != V_79 ) {
F_9 ( L_17 ,
V_44 -> V_52 , V_5 -> V_59 ,
( unsigned int ) V_79 ) ;
F_36 ( V_44 ) ;
}
#ifdef F_10
V_37 -> V_86 = ( ( F_37 ( V_39 ) & 0xff0000 ) >> 8 ) ;
V_37 -> V_87 = ( F_37 ( V_39 ) & 0xffff ) ;
#else
V_37 -> V_86 = ( ( ( unsigned long ) ( V_83 ) & 0xff0000 ) >> 8 ) ;
V_37 -> V_87 = ( ( unsigned long ) ( V_83 ) & 0xffff ) ;
#endif
V_37 -> V_79 = V_79 / 2 ;
V_37 -> V_88 = V_89 ;
if( V_80 ) {
if( V_79 & 1 )
V_37 -> V_79 ++ ;
V_37 -> V_90 = V_91 ;
V_37 -> V_92 = V_93 ;
} else {
V_37 -> V_90 = V_94 ;
V_37 -> V_92 = V_95 ;
}
F_5 ( ( ( F_37 ( V_37 ) & 0xff0000 ) >> 8 ) ,
V_96 ) ;
F_5 ( ( F_37 ( V_37 ) & 0xffff ) , V_97 ) ;
F_5 ( 0xd , V_98 ) ;
F_5 ( V_99 , V_7 ) ;
return V_79 ;
}
static inline unsigned long F_38 ( struct V_15 * V_16 )
{
unsigned short V_100 ;
V_5 -> V_6 = 0x32 ;
F_4 ( V_8 ) ;
V_100 = V_5 -> V_9 ;
F_4 ( V_8 ) ;
V_100 *= 2 ;
return ( unsigned long ) V_100 ;
}
static inline unsigned long F_39 ( struct V_15 * V_16 )
{
return V_101 ;
}
static inline unsigned long F_40 ( unsigned long V_102 ,
struct V_103 * V_104 ,
int V_80 )
{
if ( V_104 -> V_105 -> V_106 == V_107 )
return V_102 ;
else
return 0 ;
}
static inline int F_41 ( unsigned long V_79 , unsigned char * V_78 )
{
F_5 ( V_108 , V_7 ) ;
return 0 ;
}
static int F_42 ( int V_80 )
{
unsigned short V_79 ;
unsigned short V_109 ;
int V_4 = 0 ;
V_110 = 0 ;
#if 1
if( ! V_80 ) {
int V_111 = 20000 ;
while( 1 ) {
if( V_5 -> V_55 & V_112 )
break;
if( -- V_111 <= 0 ) {
F_9 ( L_18 ) ;
return 1 ;
}
F_4 ( 10 ) ;
}
}
#endif
V_79 = F_38 ( V_44 ) ;
#ifdef F_10
if( V_81 ) {
if( V_79 && ( F_27 ( V_113 ) &
( V_114 | V_115 ) ) ) {
F_9 ( L_19 , V_44 -> V_52 ) ;
F_9 ( L_20 , F_27 ( V_113 ) ) ;
V_4 = V_79 ;
}
memcpy ( V_81 , V_39 , V_82 ) ;
V_81 = NULL ;
}
#else
V_109 = V_5 -> V_59 ;
V_101 = V_109 ;
if( ( ! V_80 ) && ( V_79 - V_109 ) == 2 ) {
unsigned short V_78 ;
unsigned char * V_116 ;
V_78 = V_5 -> V_117 ;
V_116 = ( unsigned char * ) F_43 ( V_81 ) ;
V_116 += ( V_82 - V_109 ) ;
V_116 [ - 2 ] = ( V_78 & 0xff00 ) >> 8 ;
V_116 [ - 1 ] = ( V_78 & 0xff ) ;
}
F_34 ( V_81 ) ;
V_81 = NULL ;
#endif
F_5 ( V_84 , V_7 ) ;
V_5 -> V_59 = 0 ;
V_5 -> V_55 &= ~ V_85 ;
V_5 -> V_55 &= ~ V_57 ;
V_5 -> V_55 |= V_57 ;
V_118 = NULL ;
return V_4 ;
}
