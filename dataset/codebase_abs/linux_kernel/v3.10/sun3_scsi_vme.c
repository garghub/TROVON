static inline unsigned char F_1 ( int V_1 )
{
return ( V_2 [ V_1 ] ) ;
}
static inline void F_2 ( int V_1 , int V_3 )
{
V_2 [ V_1 ] = V_3 ;
}
static int T_1 F_3 ( struct V_4 * V_5 )
{
unsigned long V_6 , V_7 = 0 ;
static int V_8 = 0 ;
struct V_9 * V_10 ;
int V_11 ;
unsigned long V_12 [ 3 ] = { V_13 ,
V_13 + 0x4000 ,
0 } ;
unsigned long V_14 [ 3 ] = { V_15 ,
V_16 ,
0 } ;
switch( V_17 -> V_18 ) {
case V_19 | V_20 :
case V_19 | V_21 :
break;
default:
return 0 ;
}
if( V_8 )
return 0 ;
V_5 -> V_22 = L_1 ;
V_5 -> V_23 =
( V_24 > 0 ) ? V_24 : V_25 ;
V_5 -> V_26 =
( V_27 > 0 ) ? V_27 : V_28 ;
V_5 -> V_29 =
( V_30 >= 0 ) ? V_30 : V_31 ;
if ( V_32 >= 0 )
V_5 -> V_33 = V_32 ;
else {
V_5 -> V_33 = 7 ;
}
V_6 = 0 ;
for( V_11 = 0 ; V_12 [ V_11 ] != 0 ; V_11 ++ ) {
unsigned char V_34 ;
V_6 = ( unsigned long ) F_4 ( V_12 [ V_11 ] , V_35 ,
V_36 ) ;
V_7 = V_14 [ V_11 ] ;
V_2 = ( unsigned char * ) V_6 ;
V_37 = (struct V_38 * ) ( ( ( unsigned char * ) V_6 ) + 8 ) ;
if( F_5 ( ( unsigned long ) V_37 , & V_34 ) ) {
unsigned short V_39 ;
V_39 = V_37 -> V_40 ;
V_37 -> V_40 = 0 ;
F_6 ( V_41 ) ;
if( V_37 -> V_40 == 0x1400 )
break;
V_37 -> V_40 = V_39 ;
}
F_7 ( ( void * ) V_6 ) ;
V_6 = 0 ;
}
if( ! V_6 )
return 0 ;
#ifdef F_8
if ( V_42 < 0 )
V_42 = V_43 ;
#endif
V_10 = F_9 ( V_5 , sizeof( struct V_44 ) ) ;
if( V_10 == NULL )
return 0 ;
V_45 = V_10 ;
V_10 -> V_46 = ( unsigned long ) V_6 ;
V_10 -> V_7 = V_7 ;
F_10 ( V_10 , 0 ) ;
V_10 -> V_47 = 32 ;
( (struct V_44 * ) V_10 -> V_48 ) -> V_49 = 0 ;
if ( F_11 ( V_10 -> V_7 , V_50 ,
0 , L_2 , V_10 ) ) {
#ifndef F_12
F_13 ( L_3 ,
V_10 -> V_51 , V_10 -> V_7 ) ;
V_10 -> V_7 = V_52 ;
#else
F_13 ( L_4 ,
V_10 -> V_51 , V_10 -> V_7 ) ;
return 0 ;
#endif
}
F_13 ( L_5 , V_10 -> V_51 , V_10 -> V_46 ) ;
if ( V_10 -> V_7 == V_52 )
F_13 ( L_6 ) ;
else
F_13 ( L_7 , V_10 -> V_7 ) ;
F_13 ( L_8 ,
V_10 -> V_23 , V_10 -> V_26 ,
V_53 ) ;
F_13 ( L_9 , V_10 -> V_51 ) ;
F_14 ( V_10 ) ;
F_13 ( L_10 ) ;
V_37 -> V_40 = 0 ;
F_6 ( V_41 ) ;
V_37 -> V_40 = V_54 | V_55 | V_56 ;
F_6 ( V_41 ) ;
V_37 -> V_57 = 0 ;
V_37 -> V_58 = 0 ;
V_37 -> V_59 = 0 ;
V_37 -> V_60 = 0 ;
V_37 -> V_61 = 0 ;
V_37 -> V_62 = 0 ;
V_37 -> V_63 = V_64 | ( V_10 -> V_7 & 0xff ) ;
V_8 = 1 ;
#ifdef F_15
F_16 ( V_10 ) ;
#endif
return 1 ;
}
int F_17 ( struct V_9 * V_65 )
{
if ( V_65 -> V_7 != V_52 )
F_18 ( V_65 -> V_7 , V_65 ) ;
F_7 ( ( void * ) V_2 ) ;
F_19 ( V_65 ) ;
return 0 ;
}
static void F_16 ( struct V_9 * V_10 )
{
unsigned long V_66 ;
F_20 () ;
F_21 ( V_10 ) ;
F_13 ( L_11 ) ;
F_22 ( V_67 ,
F_23 ( F_24 ( V_68 ) ) ) ;
F_22 ( V_69 , V_70 | V_71 ) ;
F_6 ( 50 ) ;
F_22 ( V_69 , V_70 ) ;
F_24 ( V_72 ) ;
for( V_66 = V_73 + V_74 ; F_25 ( V_73 , V_66 ) ; )
F_26 () ;
F_13 ( L_12 ) ;
}
static const char * F_27 ( struct V_9 * V_75 ) {
return L_13 ;
}
static T_2 V_50 ( int V_7 , void * V_76 )
{
unsigned short V_40 = V_37 -> V_40 ;
int V_77 = 0 ;
V_37 -> V_40 &= ~ V_78 ;
#ifdef F_28
F_13 ( L_14 , V_40 ) ;
#endif
if( V_40 & ~ V_79 ) {
if( V_40 & V_80 ) {
F_13 ( L_15 , V_45 -> V_51 ) ;
#ifdef F_28
F_13 ( L_16 ,
V_37 -> V_57 ,
V_37 -> V_62 | ( V_37 -> V_61 << 16 ) ,
V_81 ,
V_37 -> V_60 | ( V_37 -> V_59 << 16 ) ) ;
#endif
}
if( V_40 & V_82 ) {
F_13 ( L_17 , V_45 -> V_51 ) ;
}
V_77 = 1 ;
}
if( V_40 & ( V_83 | V_84 ) ) {
F_29 ( V_7 , V_76 ) ;
V_77 = 1 ;
}
return F_30 ( V_77 ) ;
}
static unsigned long F_31 ( void * V_85 , unsigned long V_86 , int V_87 )
{
void * V_88 ;
if( V_81 != NULL )
F_32 ( V_81 ) ;
V_88 = ( void * ) F_33 ( ( unsigned long ) V_85 , V_86 ) ;
V_81 = V_88 ;
V_89 = V_86 ;
#ifdef F_28
F_13 ( L_18 , V_88 , V_86 ) ;
#endif
#if 0
dregs->csr &= ~CSR_FIFO;
dregs->csr |= CSR_FIFO;
#endif
if( V_87 )
V_37 -> V_40 |= V_90 ;
else
V_37 -> V_40 &= ~ V_90 ;
V_37 -> V_40 |= V_91 ;
V_37 -> V_59 = ( ( unsigned long ) V_88 >> 16 ) ;
V_37 -> V_60 = ( ( unsigned long ) V_88 & 0xffff ) ;
V_37 -> V_61 = 0 ;
V_37 -> V_62 = 0 ;
V_37 -> V_58 = 0 ;
V_37 -> V_57 = 0 ;
#ifdef F_28
F_13 ( L_19 , V_37 -> V_40 ) ;
#endif
return V_86 ;
}
static inline unsigned long F_34 ( struct V_9 * V_10 )
{
return V_92 ;
}
static inline unsigned long F_35 ( unsigned long V_93 ,
struct V_94 * V_95 ,
int V_87 )
{
if ( V_95 -> V_96 -> V_97 == V_98 )
return V_93 ;
else
return 0 ;
}
static int F_36 ( unsigned long V_86 , char * V_85 )
{
unsigned short V_40 ;
V_40 = V_37 -> V_40 ;
#ifdef F_28
F_13 ( L_20 , V_85 , V_86 , V_40 , V_37 -> V_57 ) ;
#endif
V_37 -> V_61 = ( V_89 >> 16 ) ;
V_37 -> V_62 = ( V_89 & 0xffff ) ;
V_37 -> V_58 = ( V_89 >> 16 ) ;
V_37 -> V_57 = ( V_89 & 0xffff ) ;
return 0 ;
}
static int F_37 ( int V_87 )
{
unsigned short V_99 ;
int V_100 = 0 ;
V_101 = 0 ;
V_37 -> V_40 &= ~ V_78 ;
V_99 = V_37 -> V_57 ;
if( V_87 ) {
if( ( V_99 > 0 ) && ( V_99 < V_89 ) )
V_99 ++ ;
}
V_92 = V_99 ;
#ifdef F_28
F_13 ( L_21 , V_99 , V_89 ) ;
#endif
if( ( ! V_87 ) && ( V_37 -> V_40 & V_102 ) ) {
unsigned char * V_103 ;
#ifdef F_28
F_13 ( L_22 ) ;
#endif
V_103 = ( unsigned char * ) F_38 ( V_81 ) ;
V_103 += ( V_89 - V_99 ) ;
V_103 -- ;
switch( V_37 -> V_40 & V_102 ) {
case V_104 :
* V_103 = ( V_37 -> V_105 & 0xff00 ) >> 8 ;
V_103 -- ;
case V_106 :
* V_103 = ( V_37 -> V_107 & 0x00ff ) ;
V_103 -- ;
case V_108 :
* V_103 = ( V_37 -> V_107 & 0xff00 ) >> 8 ;
break;
}
}
F_32 ( V_81 ) ;
V_81 = NULL ;
V_37 -> V_59 = 0 ;
V_37 -> V_60 = 0 ;
V_37 -> V_61 = 0 ;
V_37 -> V_62 = 0 ;
V_37 -> V_57 = 0 ;
V_37 -> V_58 = 0 ;
V_37 -> V_40 &= ~ V_90 ;
#if 0
dregs->csr &= ~CSR_FIFO;
dregs->csr |= CSR_FIFO;
#endif
V_109 = NULL ;
return V_100 ;
}
