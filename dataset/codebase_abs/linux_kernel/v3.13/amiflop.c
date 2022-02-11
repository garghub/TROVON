static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 ( & V_3 ) ;
return V_4 ;
}
static void F_3 ( int V_5 )
{
int V_6 ;
static F_4 ( V_7 ) ;
if ( V_5 > 0 ) {
F_5 ( & V_7 ) ;
V_6 = V_8 * V_5 - 1 ;
V_9 . V_10 = V_6 % 256 ;
V_9 . V_11 = V_6 / 256 ;
V_9 . V_12 = 0x19 ;
F_6 ( & V_3 ) ;
F_7 ( & V_7 ) ;
}
}
static inline int F_8 ( int V_13 )
{
V_13 &= 3 ;
return ( ( V_14 < 0 ) || ( V_14 == V_13 ) ) ;
}
static void F_9 ( int V_13 )
{
unsigned long V_15 ;
V_13 &= 3 ;
#ifdef F_10
F_11 ( L_1 , V_13 , V_14 , V_16 ) ;
#endif
F_12 ( V_15 ) ;
F_13 ( V_17 , F_8 ( V_13 ) ) ;
V_14 = V_13 ;
V_16 ++ ;
F_14 ( V_15 ) ;
}
static inline void F_15 ( void )
{
#ifdef F_10
if ( V_16 == 0 )
F_11 ( L_2 ) ;
F_11 ( L_3 , V_14 , V_16 ) ;
#endif
V_16 -- ;
if ( V_16 == 0 ) {
V_14 = - 1 ;
F_16 ( & V_17 ) ;
}
}
static void F_17 ( int V_13 )
{
unsigned char V_18 = ~ 0 ;
V_13 &= 3 ;
#ifdef F_10
F_11 ( L_4 , V_13 ) ;
#endif
if ( V_13 == V_19 )
return;
F_9 ( V_13 ) ;
V_19 = V_13 ;
if ( V_20 [ V_13 ] . V_21 % 2 != 0 )
V_18 &= ~ V_22 ;
if ( V_20 [ V_13 ] . V_23 == 1 )
V_18 &= ~ V_24 ;
V_25 . V_18 |= ( F_18 ( 0 ) | F_18 ( 1 ) | F_18 ( 2 ) | F_18 ( 3 ) ) ;
V_25 . V_18 = V_18 ;
V_18 &= ~ F_18 ( V_13 ) ;
V_25 . V_18 = V_18 ;
F_15 () ;
}
static void F_19 ( int V_13 )
{
unsigned char V_18 ;
unsigned long V_15 ;
V_13 &= 3 ;
#ifdef F_10
F_11 ( L_5 , V_13 ) ;
#endif
if ( V_13 != V_19 ) {
F_11 ( V_26 L_6 , V_13 , V_19 ) ;
return;
}
F_9 ( V_13 ) ;
F_12 ( V_15 ) ;
V_19 = - 1 ;
V_18 = V_25 . V_18 ;
V_18 |= ( F_18 ( 0 ) | F_18 ( 1 ) | F_18 ( 2 ) | F_18 ( 3 ) ) ;
V_25 . V_18 = V_18 ;
F_14 ( V_15 ) ;
F_15 () ;
}
static void F_20 ( unsigned long V_27 )
{
if ( ! ( V_9 . V_28 & V_29 ) || -- V_30 == 0 ) {
F_21 ( & V_31 ) ;
} else {
V_32 . V_33 = V_34 + V_35 / 10 ;
F_22 ( & V_32 ) ;
}
}
static int F_23 ( int V_27 )
{
V_27 &= 3 ;
F_24 ( V_36 + V_27 ) ;
if ( ! V_20 [ V_27 ] . V_23 ) {
V_20 [ V_27 ] . V_23 = 1 ;
F_17 ( V_27 ) ;
F_25 ( & V_31 ) ;
V_32 . V_37 = V_27 ;
F_26 ( & V_32 , V_34 + V_35 / 2 ) ;
V_30 = 10 ;
F_6 ( & V_31 ) ;
F_19 ( V_27 ) ;
}
if ( V_30 == 0 ) {
V_30 = - 1 ;
#if 0
printk (KERN_ERR "motor_on failed, turning motor off\n");
fd_motor_off (nr);
return 0;
#else
F_11 ( V_26 L_7 ) ;
#endif
}
return 1 ;
}
static void F_27 ( unsigned long V_13 )
{
long V_38 ;
#ifdef F_28
long V_39 ;
V_39 = V_13 & 0x40000000 ;
#endif
V_38 = V_13 & 0x80000000 ;
V_13 &= 3 ;
if ( V_38 && ! F_8 ( V_13 ) ) {
V_36 [ V_13 ] . V_33 = V_34 + 1 ;
F_22 ( V_36 + V_13 ) ;
return;
}
V_20 [ V_13 ] . V_23 = 0 ;
F_17 ( V_13 ) ;
F_29 ( 1 ) ;
F_19 ( V_13 ) ;
}
static void F_30 ( unsigned int V_27 )
{
int V_13 ;
V_13 = V_27 & 3 ;
V_36 [ V_13 ] . V_37 = V_27 | 0x80000000 ;
F_26 ( V_36 + V_13 , V_34 + 3 * V_35 ) ;
}
static int F_31 ( int V_13 )
{
unsigned char V_18 ;
int V_40 ;
V_13 &= 3 ;
F_9 ( V_13 ) ;
if ( ! F_23 ( V_13 ) )
return 0 ;
F_17 ( V_13 ) ;
V_18 = V_25 . V_18 ;
V_18 |= V_22 ;
V_18 &= ~ V_41 ;
V_25 . V_18 = V_18 ;
for ( V_40 = V_20 [ V_13 ] . type -> V_42 / 2 ; V_40 != 0 ; -- V_40 ) {
if ( V_9 . V_28 & V_43 )
break;
V_18 &= ~ V_44 ;
V_25 . V_18 = V_18 ;
V_18 |= V_44 ;
F_29 ( 2 ) ;
V_25 . V_18 = V_18 ;
F_3 ( V_20 [ V_13 ] . type -> V_45 ) ;
}
F_3 ( V_20 [ V_13 ] . type -> V_46 ) ;
V_18 |= V_41 ;
V_40 = V_20 [ V_13 ] . type -> V_42 + 20 ;
for (; ; ) {
V_18 &= ~ V_44 ;
V_25 . V_18 = V_18 ;
V_18 |= V_44 ;
F_29 ( 2 ) ;
V_25 . V_18 = V_18 ;
F_3 ( V_20 [ V_13 ] . type -> V_45 + 1 ) ;
if ( ( V_9 . V_28 & V_43 ) == 0 )
break;
if ( -- V_40 == 0 ) {
F_11 ( V_47 L_8 , V_13 ) ;
F_27 ( V_13 ) ;
V_20 [ V_13 ] . V_21 = - 1 ;
F_15 () ;
return 0 ;
}
}
V_20 [ V_13 ] . V_21 = 0 ;
F_3 ( V_20 [ V_13 ] . type -> V_46 ) ;
F_15 () ;
F_19 ( V_13 ) ;
return 1 ;
}
static int F_32 ( int V_13 , int V_21 )
{
unsigned char V_18 ;
int V_48 ;
#ifdef F_10
F_11 ( L_9 , V_13 , V_21 ) ;
#endif
V_13 &= 3 ;
F_9 ( V_13 ) ;
if ( V_20 [ V_13 ] . V_21 == V_21 ) {
F_15 () ;
return 1 ;
}
if ( ! F_23 ( V_13 ) ) {
F_15 () ;
return 0 ;
}
if ( V_20 [ V_13 ] . V_21 < 0 && ! F_31 ( V_13 ) ) {
F_15 () ;
return 0 ;
}
F_17 ( V_13 ) ;
V_48 = V_20 [ V_13 ] . V_21 / 2 - V_21 / 2 ;
V_18 = V_25 . V_18 ;
V_18 |= V_22 | V_41 ;
if ( V_21 % 2 != 0 )
V_18 &= ~ V_22 ;
if ( V_48 < 0 ) {
V_48 = - V_48 ;
V_18 &= ~ V_41 ;
}
V_25 . V_18 = V_18 ;
if ( V_21 % 2 != V_20 [ V_13 ] . V_21 % 2 )
F_3 ( V_20 [ V_13 ] . type -> V_49 ) ;
V_20 [ V_13 ] . V_21 = V_21 ;
if ( V_48 == 0 ) {
F_15 () ;
F_19 ( V_13 ) ;
return 1 ;
}
do {
V_18 &= ~ V_44 ;
V_25 . V_18 = V_18 ;
V_18 |= V_44 ;
F_29 ( 1 ) ;
V_25 . V_18 = V_18 ;
F_3 ( V_20 [ V_13 ] . type -> V_45 ) ;
} while ( -- V_48 != 0 );
F_3 ( V_20 [ V_13 ] . type -> V_46 ) ;
F_15 () ;
F_19 ( V_13 ) ;
return 1 ;
}
static unsigned long F_33 ( int V_13 )
{
int V_50 ;
T_2 V_51 = 0 ;
V_13 &= 3 ;
F_9 ( V_13 ) ;
V_52 ;
F_29 ( 2 ) ;
F_34 ( F_18 ( V_13 ) ) ;
F_29 ( 2 ) ;
F_35 ( F_18 ( V_13 ) ) ;
F_29 ( 2 ) ;
V_53 ;
F_29 ( 2 ) ;
F_34 ( F_18 ( V_13 ) ) ;
F_29 ( 2 ) ;
F_35 ( F_18 ( V_13 ) ) ;
F_29 ( 2 ) ;
for ( V_50 = 0 ; V_50 < 32 ; V_50 ++ ) {
F_34 ( F_18 ( V_13 ) ) ;
F_29 ( 2 ) ;
V_51 <<= 1 ;
V_51 |= ( V_9 . V_28 & V_29 ) ? 0 : 1 ;
F_35 ( F_18 ( V_13 ) ) ;
}
F_15 () ;
if( V_13 == 0 && V_51 == V_54 )
{
V_51 = V_55 ;
F_11 ( V_56 L_10 , ( T_2 ) V_55 ) ;
}
return ( V_51 ) ;
}
static T_1 F_36 ( int V_1 , void * V_2 )
{
if ( V_57 )
V_58 . V_59 = 0x4000 ;
if ( V_57 == 2 ) {
V_60 = 2 ;
V_61 . V_33 = V_34 + 1 ;
V_61 . V_37 = V_19 ;
F_22 ( & V_61 ) ;
}
else {
V_57 = 0 ;
F_16 ( & V_62 ) ;
}
return V_4 ;
}
static void F_37 ( int V_13 )
{
V_13 &= 3 ;
F_9 ( V_13 ) ;
F_13 ( V_62 , ! V_57 ) ;
F_17 ( V_13 ) ;
V_58 . V_63 = V_64 ;
V_58 . V_63 = V_65 | V_66 | V_67 ;
V_58 . V_68 = V_69 ;
V_58 . V_59 = 0 ;
V_58 . V_70 = ( V_71 * ) F_38 ( ( V_71 * ) V_72 ) ;
V_58 . V_59 = V_20 [ V_13 ] . type -> V_73 / sizeof( short ) | V_74 ;
V_58 . V_59 = V_20 [ V_13 ] . type -> V_73 / sizeof( short ) | V_74 ;
V_57 = 1 ;
F_13 ( V_62 , ! V_57 ) ;
V_58 . V_59 = 0 ;
F_19 ( V_13 ) ;
F_15 () ;
}
static int F_39 ( int V_13 )
{
T_3 V_75 ;
V_13 &= 3 ;
F_9 ( V_13 ) ;
if ( ( V_9 . V_28 & V_76 ) == 0 ) {
F_15 () ;
return 0 ;
}
F_13 ( V_62 , ! V_57 ) ;
F_17 ( V_13 ) ;
V_58 . V_63 = V_77 | V_78 | V_66 | V_64 ;
V_75 = V_65 | V_67 ;
if ( ( T_2 ) V_20 [ V_13 ] . V_21 >= V_20 [ V_13 ] . type -> V_79 )
V_75 |= V_77 ;
else if ( ( T_2 ) V_20 [ V_13 ] . V_21 >= V_20 [ V_13 ] . type -> V_80 )
V_75 |= V_78 ;
V_58 . V_63 = V_75 ;
V_58 . V_59 = V_81 ;
V_58 . V_70 = ( V_71 * ) F_38 ( ( V_71 * ) V_72 ) ;
V_58 . V_59 = V_20 [ V_13 ] . type -> V_82 / sizeof( short ) | V_74 | V_81 ;
V_58 . V_59 = V_20 [ V_13 ] . type -> V_82 / sizeof( short ) | V_74 | V_81 ;
V_57 = 2 ;
return 1 ;
}
static void F_40 ( unsigned long V_13 )
{
#ifdef F_10
F_11 ( L_11 , V_13 ) ;
#endif
V_13 &= 3 ;
V_58 . V_59 = 0 ;
V_57 = 0 ;
V_60 = 0 ;
V_83 = 0 ;
V_20 [ V_13 ] . V_84 = 0 ;
F_16 ( & V_62 ) ;
F_19 ( V_13 ) ;
F_15 () ;
}
static unsigned long F_41 ( unsigned long V_85 , unsigned long V_86 )
{
T_3 * V_87 = ( T_3 * ) V_85 , * V_88 = ( T_3 * ) V_86 ;
while ( V_87 < V_88 && * V_87 ++ != 0x4489 )
;
if ( V_87 < V_88 ) {
while ( * V_87 == 0x4489 && V_87 < V_88 )
V_87 ++ ;
return ( T_2 ) V_87 ;
}
return 0 ;
}
static inline unsigned long F_42 ( unsigned long * V_89 , int V_90 )
{
unsigned long V_91 = 0 ;
V_90 /= sizeof( * V_89 ) ;
while ( V_90 -- > 0 )
V_91 ^= * V_89 ++ ;
V_91 = ( ( V_91 >> 1 ) & 0x55555555 ) ^ ( V_91 & 0x55555555 ) ;
return V_91 ;
}
static unsigned long F_43 ( unsigned long * V_37 , unsigned long * V_85 ,
int V_90 )
{
T_2 * V_92 , * V_93 ;
V_90 >>= 2 ;
V_92 = V_85 ;
V_93 = V_92 + V_90 ;
V_85 += V_90 * 2 ;
do {
* V_37 ++ = ( ( * V_92 ++ & 0x55555555 ) << 1 ) | ( * V_93 ++ & 0x55555555 ) ;
} while ( -- V_90 != 0 );
return ( T_2 ) V_85 ;
}
static int F_44 ( int V_13 )
{
unsigned long V_85 ;
unsigned long V_86 ;
int V_94 ;
unsigned long V_91 ;
struct V_95 V_96 ;
V_13 &= 3 ;
V_85 = ( long ) V_72 ;
V_86 = V_85 + V_20 [ V_13 ] . type -> V_73 ;
for ( V_94 = 0 ; V_94 < V_20 [ V_13 ] . V_97 -> V_98 * V_20 [ V_13 ] . type -> V_99 ; V_94 ++ ) {
if ( ! ( V_85 = F_41 ( V_85 , V_86 ) ) ) {
F_11 ( V_100 L_12 , V_94 ) ;
return V_101 ;
}
V_85 = F_43 ( ( T_2 * ) & V_96 . V_102 , ( T_2 * ) V_85 , 4 ) ;
V_85 = F_43 ( ( T_2 * ) & V_96 . V_103 , ( T_2 * ) V_85 , 16 ) ;
V_85 = F_43 ( ( T_2 * ) & V_96 . V_104 , ( T_2 * ) V_85 , 4 ) ;
V_85 = F_43 ( ( T_2 * ) & V_96 . V_105 , ( T_2 * ) V_85 , 4 ) ;
V_91 = F_42 ( ( T_2 * ) & V_96 ,
( char * ) & V_96 . V_104 - ( char * ) & V_96 ) ;
#ifdef F_10
F_11 ( L_13 ,
V_96 . V_102 , V_96 . V_21 , V_96 . V_106 , V_96 . V_107 ,
* ( T_2 * ) & V_96 . V_103 [ 0 ] , * ( T_2 * ) & V_96 . V_103 [ 4 ] ,
* ( T_2 * ) & V_96 . V_103 [ 8 ] , * ( T_2 * ) & V_96 . V_103 [ 12 ] ,
V_96 . V_104 , V_96 . V_105 ) ;
#endif
if ( V_96 . V_104 != V_91 ) {
F_11 ( V_100 L_14 , V_96 . V_104 , V_91 ) ;
return V_108 ;
}
if ( V_96 . V_21 != V_20 [ V_13 ] . V_21 ) {
F_11 ( V_100 L_15 , V_96 . V_21 , V_20 [ V_13 ] . V_21 ) ;
return V_109 ;
}
V_85 = F_43 ( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) ,
( T_2 * ) V_85 , 512 ) ;
V_91 = F_42 ( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) , 512 ) ;
if ( V_96 . V_105 != V_91 ) {
F_11 ( V_100 L_16 ,
V_96 . V_102 , V_96 . V_21 , V_96 . V_106 , V_96 . V_107 , V_94 ,
V_96 . V_105 , V_91 ) ;
F_11 ( V_100 L_17 ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) ) [ 0 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) ) [ 1 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) ) [ 2 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + V_96 . V_106 * 512 ) ) [ 3 ] ) ;
return V_111 ;
}
}
return 0 ;
}
static void F_45 ( unsigned long V_37 , unsigned long * V_112 )
{
unsigned long V_113 ;
V_37 &= 0x55555555 ;
V_113 = V_37 ^ 0x55555555 ;
V_37 |= ( ( V_113 >> 1 ) | 0x80000000 ) & ( V_113 << 1 ) ;
if ( * ( V_112 - 1 ) & 0x00000001 )
V_37 &= 0x7FFFFFFF ;
* V_112 = V_37 ;
}
static void F_46 ( unsigned long * V_112 , unsigned long * V_114 , int V_90 )
{
int V_48 , V_115 = 0 ;
unsigned long V_37 ;
for ( V_48 = 0 ; V_48 < V_90 / 4 ; V_48 ++ ) {
V_37 = V_114 [ V_48 ] >> 1 ;
F_45 ( V_37 , V_112 + V_115 ++ ) ;
}
for ( V_48 = 0 ; V_48 < V_90 / 4 ; V_48 ++ ) {
V_37 = V_114 [ V_48 ] ;
F_45 ( V_37 , V_112 + V_115 ++ ) ;
}
}
static unsigned long * F_47 ( int V_116 , unsigned long * V_85 , int V_48 )
{
struct V_95 V_96 ;
int V_50 ;
V_116 &= 3 ;
* V_85 = ( V_85 [ - 1 ] & 1 ) ? 0x2AAAAAAA : 0xAAAAAAAA ;
V_85 ++ ;
* V_85 ++ = 0x44894489 ;
V_96 . V_102 = 0xFF ;
V_96 . V_21 = V_20 [ V_116 ] . V_21 ;
V_96 . V_106 = V_48 ;
V_96 . V_107 = V_20 [ V_116 ] . V_97 -> V_98 * V_20 [ V_116 ] . type -> V_99 - V_48 ;
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ )
V_96 . V_103 [ V_50 ] = 0 ;
V_96 . V_104 = F_42 ( ( T_2 * ) & V_96 ,
( char * ) & V_96 . V_104 - ( char * ) & V_96 ) ;
V_96 . V_105 = F_42 ( ( T_2 * ) ( V_20 [ V_116 ] . V_110 + V_48 * 512 ) , 512 ) ;
F_46 ( V_85 , ( T_2 * ) & V_96 . V_102 , 4 ) ;
V_85 += 2 ;
F_46 ( V_85 , ( T_2 * ) & V_96 . V_103 , 16 ) ;
V_85 += 8 ;
F_46 ( V_85 , ( T_2 * ) & V_96 . V_104 , 4 ) ;
V_85 += 2 ;
F_46 ( V_85 , ( T_2 * ) & V_96 . V_105 , 4 ) ;
V_85 += 2 ;
F_46 ( V_85 , ( T_2 * ) ( V_20 [ V_116 ] . V_110 + V_48 * 512 ) , 512 ) ;
V_85 += 256 ;
return V_85 ;
}
static void F_48 ( int V_116 )
{
unsigned int V_48 ;
unsigned long * V_87 = ( unsigned long * ) V_72 ;
V_116 &= 3 ;
for ( V_48 = 0 ; V_48 < 415 * V_20 [ V_116 ] . type -> V_99 ; V_48 ++ )
* V_87 ++ = 0xaaaaaaaa ;
for ( V_48 = 0 ; V_48 < V_20 [ V_116 ] . V_97 -> V_98 * V_20 [ V_116 ] . type -> V_99 ; V_48 ++ )
V_87 = F_47 ( V_116 , V_87 , V_48 ) ;
* ( T_3 * ) V_87 = ( V_87 [ - 1 ] & 1 ) ? 0x2AA8 : 0xAAA8 ;
}
static T_3 F_49 ( void * V_117 , int V_118 , int V_119 , int V_120 )
{
static unsigned char V_121 [] = {
0x00 , 0x10 , 0x20 , 0x30 , 0x40 , 0x50 , 0x60 , 0x70 , 0x81 , 0x91 , 0xa1 , 0xb1 , 0xc1 , 0xd1 , 0xe1 , 0xf1 ,
0x12 , 0x02 , 0x32 , 0x22 , 0x52 , 0x42 , 0x72 , 0x62 , 0x93 , 0x83 , 0xb3 , 0xa3 , 0xd3 , 0xc3 , 0xf3 , 0xe3 ,
0x24 , 0x34 , 0x04 , 0x14 , 0x64 , 0x74 , 0x44 , 0x54 , 0xa5 , 0xb5 , 0x85 , 0x95 , 0xe5 , 0xf5 , 0xc5 , 0xd5 ,
0x36 , 0x26 , 0x16 , 0x06 , 0x76 , 0x66 , 0x56 , 0x46 , 0xb7 , 0xa7 , 0x97 , 0x87 , 0xf7 , 0xe7 , 0xd7 , 0xc7 ,
0x48 , 0x58 , 0x68 , 0x78 , 0x08 , 0x18 , 0x28 , 0x38 , 0xc9 , 0xd9 , 0xe9 , 0xf9 , 0x89 , 0x99 , 0xa9 , 0xb9 ,
0x5a , 0x4a , 0x7a , 0x6a , 0x1a , 0x0a , 0x3a , 0x2a , 0xdb , 0xcb , 0xfb , 0xeb , 0x9b , 0x8b , 0xbb , 0xab ,
0x6c , 0x7c , 0x4c , 0x5c , 0x2c , 0x3c , 0x0c , 0x1c , 0xed , 0xfd , 0xcd , 0xdd , 0xad , 0xbd , 0x8d , 0x9d ,
0x7e , 0x6e , 0x5e , 0x4e , 0x3e , 0x2e , 0x1e , 0x0e , 0xff , 0xef , 0xdf , 0xcf , 0xbf , 0xaf , 0x9f , 0x8f ,
0x91 , 0x81 , 0xb1 , 0xa1 , 0xd1 , 0xc1 , 0xf1 , 0xe1 , 0x10 , 0x00 , 0x30 , 0x20 , 0x50 , 0x40 , 0x70 , 0x60 ,
0x83 , 0x93 , 0xa3 , 0xb3 , 0xc3 , 0xd3 , 0xe3 , 0xf3 , 0x02 , 0x12 , 0x22 , 0x32 , 0x42 , 0x52 , 0x62 , 0x72 ,
0xb5 , 0xa5 , 0x95 , 0x85 , 0xf5 , 0xe5 , 0xd5 , 0xc5 , 0x34 , 0x24 , 0x14 , 0x04 , 0x74 , 0x64 , 0x54 , 0x44 ,
0xa7 , 0xb7 , 0x87 , 0x97 , 0xe7 , 0xf7 , 0xc7 , 0xd7 , 0x26 , 0x36 , 0x06 , 0x16 , 0x66 , 0x76 , 0x46 , 0x56 ,
0xd9 , 0xc9 , 0xf9 , 0xe9 , 0x99 , 0x89 , 0xb9 , 0xa9 , 0x58 , 0x48 , 0x78 , 0x68 , 0x18 , 0x08 , 0x38 , 0x28 ,
0xcb , 0xdb , 0xeb , 0xfb , 0x8b , 0x9b , 0xab , 0xbb , 0x4a , 0x5a , 0x6a , 0x7a , 0x0a , 0x1a , 0x2a , 0x3a ,
0xfd , 0xed , 0xdd , 0xcd , 0xbd , 0xad , 0x9d , 0x8d , 0x7c , 0x6c , 0x5c , 0x4c , 0x3c , 0x2c , 0x1c , 0x0c ,
0xef , 0xff , 0xcf , 0xdf , 0xaf , 0xbf , 0x8f , 0x9f , 0x6e , 0x7e , 0x4e , 0x5e , 0x2e , 0x3e , 0x0e , 0x1e
} ;
static unsigned char V_122 [] = {
0x00 , 0x21 , 0x42 , 0x63 , 0x84 , 0xa5 , 0xc6 , 0xe7 , 0x08 , 0x29 , 0x4a , 0x6b , 0x8c , 0xad , 0xce , 0xef ,
0x31 , 0x10 , 0x73 , 0x52 , 0xb5 , 0x94 , 0xf7 , 0xd6 , 0x39 , 0x18 , 0x7b , 0x5a , 0xbd , 0x9c , 0xff , 0xde ,
0x62 , 0x43 , 0x20 , 0x01 , 0xe6 , 0xc7 , 0xa4 , 0x85 , 0x6a , 0x4b , 0x28 , 0x09 , 0xee , 0xcf , 0xac , 0x8d ,
0x53 , 0x72 , 0x11 , 0x30 , 0xd7 , 0xf6 , 0x95 , 0xb4 , 0x5b , 0x7a , 0x19 , 0x38 , 0xdf , 0xfe , 0x9d , 0xbc ,
0xc4 , 0xe5 , 0x86 , 0xa7 , 0x40 , 0x61 , 0x02 , 0x23 , 0xcc , 0xed , 0x8e , 0xaf , 0x48 , 0x69 , 0x0a , 0x2b ,
0xf5 , 0xd4 , 0xb7 , 0x96 , 0x71 , 0x50 , 0x33 , 0x12 , 0xfd , 0xdc , 0xbf , 0x9e , 0x79 , 0x58 , 0x3b , 0x1a ,
0xa6 , 0x87 , 0xe4 , 0xc5 , 0x22 , 0x03 , 0x60 , 0x41 , 0xae , 0x8f , 0xec , 0xcd , 0x2a , 0x0b , 0x68 , 0x49 ,
0x97 , 0xb6 , 0xd5 , 0xf4 , 0x13 , 0x32 , 0x51 , 0x70 , 0x9f , 0xbe , 0xdd , 0xfc , 0x1b , 0x3a , 0x59 , 0x78 ,
0x88 , 0xa9 , 0xca , 0xeb , 0x0c , 0x2d , 0x4e , 0x6f , 0x80 , 0xa1 , 0xc2 , 0xe3 , 0x04 , 0x25 , 0x46 , 0x67 ,
0xb9 , 0x98 , 0xfb , 0xda , 0x3d , 0x1c , 0x7f , 0x5e , 0xb1 , 0x90 , 0xf3 , 0xd2 , 0x35 , 0x14 , 0x77 , 0x56 ,
0xea , 0xcb , 0xa8 , 0x89 , 0x6e , 0x4f , 0x2c , 0x0d , 0xe2 , 0xc3 , 0xa0 , 0x81 , 0x66 , 0x47 , 0x24 , 0x05 ,
0xdb , 0xfa , 0x99 , 0xb8 , 0x5f , 0x7e , 0x1d , 0x3c , 0xd3 , 0xf2 , 0x91 , 0xb0 , 0x57 , 0x76 , 0x15 , 0x34 ,
0x4c , 0x6d , 0x0e , 0x2f , 0xc8 , 0xe9 , 0x8a , 0xab , 0x44 , 0x65 , 0x06 , 0x27 , 0xc0 , 0xe1 , 0x82 , 0xa3 ,
0x7d , 0x5c , 0x3f , 0x1e , 0xf9 , 0xd8 , 0xbb , 0x9a , 0x75 , 0x54 , 0x37 , 0x16 , 0xf1 , 0xd0 , 0xb3 , 0x92 ,
0x2e , 0x0f , 0x6c , 0x4d , 0xaa , 0x8b , 0xe8 , 0xc9 , 0x26 , 0x07 , 0x64 , 0x45 , 0xa2 , 0x83 , 0xe0 , 0xc1 ,
0x1f , 0x3e , 0x5d , 0x7c , 0x9b , 0xba , 0xd9 , 0xf8 , 0x17 , 0x36 , 0x55 , 0x74 , 0x93 , 0xb2 , 0xd1 , 0xf0
} ;
register int V_50 ;
register unsigned char * V_123 , * V_124 , * V_37 , V_125 , V_126 , V_127 ;
V_123 = V_121 ;
V_124 = V_122 ;
V_37 = V_117 ;
V_127 = V_119 ;
V_126 = V_118 ;
for ( V_50 = V_120 ; V_50 >= 0 ; V_50 -- ) {
V_125 = ( * V_37 ++ ) ^ V_126 ;
V_126 = V_123 [ V_125 ] ^ V_127 ;
V_127 = V_124 [ V_125 ] ;
}
return ( V_126 << 8 ) | V_127 ;
}
static inline T_3 F_50 ( struct V_128 * V_96 )
{
return F_49 ( & ( V_96 -> V_21 ) , 0xb2 , 0x30 , 3 ) ;
}
static inline T_3 F_51 ( unsigned char * V_37 )
{
return F_49 ( V_37 , 0xe2 , 0x95 , 511 ) ;
}
static inline unsigned char F_52 ( T_3 V_129 )
{
register T_3 V_130 ;
register unsigned char V_131 ;
register unsigned char * V_132 = V_133 ;
V_130 = V_129 ;
V_130 >>= 8 ;
V_130 &= 127 ;
V_131 = V_132 [ V_130 ] ;
V_131 <<= 4 ;
V_130 = V_129 & 127 ;
V_131 |= V_132 [ V_130 ] ;
return V_131 ;
}
static unsigned long F_53 ( unsigned char * V_37 , unsigned short * V_85 , int V_90 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_90 ; V_50 ++ )
* V_37 ++ = F_52 ( * V_85 ++ ) ;
return ( ( T_2 ) V_85 ) ;
}
static void F_54 ( unsigned long V_87 )
{
F_11 ( L_18 , V_87 ,
( ( T_2 * ) V_87 ) [ 0 ] , ( ( T_2 * ) V_87 ) [ 1 ] ,
( ( T_2 * ) V_87 ) [ 2 ] , ( ( T_2 * ) V_87 ) [ 3 ] ) ;
}
static int F_55 ( int V_13 )
{
unsigned long V_86 ;
unsigned long V_85 ;
int V_94 ;
unsigned short V_134 , V_135 [ 2 ] ;
struct V_128 V_96 ;
V_13 &= 3 ;
V_85 = ( long ) V_72 ;
V_86 = V_85 + V_20 [ V_13 ] . type -> V_73 ;
for ( V_94 = 0 ; V_94 < V_20 [ V_13 ] . V_97 -> V_98 * V_20 [ V_13 ] . type -> V_99 ; V_94 ++ ) {
do {
if ( ! ( V_85 = F_41 ( V_85 , V_86 ) ) ) {
F_11 ( V_100 L_19
L_20 ,
V_20 [ V_13 ] . V_21 , V_13 , V_94 ) ;
return V_101 ;
}
#ifdef F_10
F_54 ( V_85 ) ;
#endif
} while ( * ( ( T_3 * ) V_85 ) != 0x5554 );
V_85 += 2 ;
V_85 = F_53 ( ( unsigned char * ) & V_96 , ( T_3 * ) V_85 , 8 ) ;
V_134 = F_50 ( & V_96 ) ;
#ifdef F_10
F_11 ( L_21 , V_96 . V_21 , V_96 . V_136 ,
V_96 . V_137 , V_96 . V_138 , V_96 . V_134 ) ;
#endif
if ( V_134 != V_96 . V_134 ) {
F_11 ( V_100 L_22 ,
V_96 . V_134 , V_134 ) ;
return V_108 ;
}
if ( V_96 . V_21 != V_20 [ V_13 ] . V_21 / V_20 [ V_13 ] . type -> V_139 ) {
F_11 ( V_100 L_23 ,
V_96 . V_21 ,
V_20 [ V_13 ] . V_21 / V_20 [ V_13 ] . type -> V_139 ) ;
return V_109 ;
}
if ( V_96 . V_136 != V_20 [ V_13 ] . V_21 % V_20 [ V_13 ] . type -> V_139 ) {
F_11 ( V_100 L_24 ,
V_96 . V_136 ,
V_20 [ V_13 ] . V_21 % V_20 [ V_13 ] . type -> V_139 ) ;
return V_109 ;
}
if ( V_96 . V_138 != 2 ) {
F_11 ( V_100 L_25
L_26 , V_96 . V_138 ) ;
return V_111 ;
}
#ifdef F_10
F_11 ( L_27 ) ;
#endif
if ( ! ( V_85 = F_41 ( V_85 , V_86 ) ) ) {
F_11 ( V_100 L_28
L_29 ,
V_20 [ V_13 ] . V_21 , V_13 , V_94 , V_96 . V_137 ) ;
return V_101 ;
}
#ifdef F_10
F_54 ( V_85 ) ;
#endif
if ( * ( ( T_3 * ) V_85 ) != 0x5545 ) {
F_11 ( V_100 L_30
L_31 ,
V_96 . V_21 , V_96 . V_136 , V_96 . V_137 , V_96 . V_138 , V_94 ) ;
return V_101 ;
}
V_85 += 2 ;
V_85 = F_53 ( ( unsigned char * ) ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) , ( T_3 * ) V_85 , 512 ) ;
V_85 = F_53 ( ( unsigned char * ) V_135 , ( T_3 * ) V_85 , 4 ) ;
V_134 = F_51 ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) ;
if ( V_134 != V_135 [ 0 ] ) {
F_11 ( V_100 L_32
L_33 , V_96 . V_21 , V_96 . V_136 ,
V_96 . V_137 , V_96 . V_138 , V_94 , V_135 [ 0 ] , V_134 ) ;
F_11 ( V_100 L_34 ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) ) [ 0 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) ) [ 1 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) ) [ 2 ] ,
( ( T_2 * ) ( V_20 [ V_13 ] . V_110 + ( V_96 . V_137 - 1 ) * 512 ) ) [ 3 ] ) ;
return V_111 ;
}
}
return 0 ;
}
static inline T_3 F_56 ( unsigned char V_131 )
{
register unsigned char * V_140 , V_141 , V_142 ;
register T_3 V_129 ;
V_140 = V_143 ;
V_142 = V_131 ;
V_141 = V_142 >> 4 ;
V_142 &= 15 ;
V_129 = V_140 [ V_141 ] << 8 | V_140 [ V_142 ] ;
return ( V_129 | ( ( V_129 & ( 256 | 64 ) ) ? 0 : 128 ) ) ;
}
static void F_57 ( T_3 * V_112 , unsigned char * V_114 , int V_90 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_90 ; V_50 ++ ) {
* V_112 = F_56 ( * V_114 ++ ) ;
* V_112 |= ( ( V_112 [ - 1 ] & 1 ) || ( * V_112 & 0x4000 ) ) ? 0 : 0x8000 ;
V_112 ++ ;
}
}
static unsigned long * F_58 ( int V_13 , unsigned long * V_85 , int V_48 )
{
static struct V_128 V_96 = { 0 , 0 , 0 , 2 , 0 ,
{ 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 , 78 } } ;
int V_50 ;
static T_3 V_134 [ 2 ] = { 0 , 0x4e4e } ;
V_13 &= 3 ;
for( V_50 = 0 ; V_50 < 6 ; V_50 ++ )
* V_85 ++ = 0xaaaaaaaa ;
* V_85 ++ = 0x44894489 ;
* V_85 ++ = 0x44895554 ;
V_96 . V_21 = V_20 [ V_13 ] . V_21 / V_20 [ V_13 ] . type -> V_139 ;
V_96 . V_136 = V_20 [ V_13 ] . V_21 % V_20 [ V_13 ] . type -> V_139 ;
V_96 . V_137 = V_48 + 1 ;
V_96 . V_134 = F_50 ( & V_96 ) ;
F_57 ( ( T_3 * ) V_85 , ( unsigned char * ) & V_96 . V_21 , 28 ) ;
V_85 += 14 ;
for( V_50 = 0 ; V_50 < 6 ; V_50 ++ )
* V_85 ++ = 0xaaaaaaaa ;
* V_85 ++ = 0x44894489 ;
* V_85 ++ = 0x44895545 ;
F_57 ( ( T_3 * ) V_85 ,
( unsigned char * ) V_20 [ V_13 ] . V_110 + V_48 * 512 , 512 ) ;
V_85 += 256 ;
V_134 [ 0 ] = F_51 ( V_20 [ V_13 ] . V_110 + V_48 * 512 ) ;
F_57 ( ( T_3 * ) V_85 , ( unsigned char * ) V_134 , 4 ) ;
V_85 += 2 ;
for( V_50 = 0 ; V_50 < 38 ; V_50 ++ )
* V_85 ++ = 0x92549254 ;
return V_85 ;
}
static void F_59 ( int V_116 )
{
int V_48 ;
unsigned long V_85 = ( unsigned long ) V_72 ;
unsigned long * V_87 = ( unsigned long * ) V_85 ;
V_116 &= 3 ;
for ( V_48 = 0 ; V_48 < 425 ; V_48 ++ )
* V_87 ++ = 0x92549254 ;
if ( V_20 [ V_116 ] . type -> V_99 == 2 )
for( V_48 = 0 ; V_48 < 473 ; V_48 ++ )
* V_87 ++ = 0x92549254 ;
for ( V_48 = 0 ; V_48 < 20 ; V_48 ++ )
* V_87 ++ = 0x92549254 ;
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ )
* V_87 ++ = 0xaaaaaaaa ;
* V_87 ++ = 0x52245224 ;
* V_87 ++ = 0x52245552 ;
for ( V_48 = 0 ; V_48 < 20 ; V_48 ++ )
* V_87 ++ = 0x92549254 ;
for( V_48 = 0 ; V_48 < V_20 [ V_116 ] . V_97 -> V_98 * V_20 [ V_116 ] . type -> V_99 ; V_48 ++ )
V_87 = F_58 ( V_116 , V_87 , V_48 ) ;
* ( T_3 * ) V_87 = 0xaaa8 ;
}
static void F_60 ( unsigned long V_27 )
{
V_27 &= 3 ;
V_83 = 1 ;
if ( ! F_8 ( V_27 ) ) {
V_144 [ V_27 ] . V_33 = V_34 + 1 ;
F_22 ( V_144 + V_27 ) ;
return;
}
F_9 ( V_27 ) ;
( * V_20 [ V_27 ] . V_97 -> V_145 ) ( V_27 ) ;
if ( ! F_39 ( V_27 ) ) {
F_11 ( V_56 L_35 ) ;
V_83 = 0 ;
V_60 = 0 ;
}
F_15 () ;
}
static int F_61 ( unsigned long V_27 )
{
unsigned long V_15 ;
V_27 &= 3 ;
V_83 = 0 ;
F_24 ( & V_61 ) ;
F_9 ( V_27 ) ;
if ( ! F_23 ( V_27 ) ) {
V_60 = 0 ;
F_15 () ;
return 0 ;
}
F_12 ( V_15 ) ;
if ( V_60 != 2 ) {
F_14 ( V_15 ) ;
( * V_20 [ V_27 ] . V_97 -> V_145 ) ( V_27 ) ;
if ( ! F_39 ( V_27 ) ) {
F_11 ( V_56 L_36
L_37 ) ;
V_60 = 0 ;
return 0 ;
}
F_13 ( V_62 , V_57 != 2 ) ;
}
else {
F_14 ( V_15 ) ;
F_3 ( 2 ) ;
F_40 ( V_27 ) ;
}
F_15 () ;
return 1 ;
}
static int F_62 ( int V_13 , int V_21 )
{
int error , V_146 ;
V_13 &= 3 ;
if ( V_20 [ V_13 ] . V_21 == V_21 )
return 0 ;
F_9 ( V_13 ) ;
if ( ! F_23 ( V_13 ) ) {
F_15 () ;
return - 1 ;
}
if ( V_20 [ V_13 ] . V_84 == 1 ) {
F_24 ( V_144 + V_13 ) ;
F_61 ( V_13 ) ;
}
V_146 = 0 ;
while ( V_146 < V_147 ) {
if ( ! F_32 ( V_13 , V_21 ) )
return - 1 ;
F_37 ( V_13 ) ;
error = ( * V_20 [ V_13 ] . V_97 -> V_148 ) ( V_13 ) ;
if ( error == 0 ) {
F_15 () ;
return 0 ;
}
V_20 [ V_13 ] . V_21 = - 1 ;
V_146 ++ ;
}
F_15 () ;
return - 1 ;
}
static struct V_149 * F_63 ( void )
{
struct V_150 * V_151 ;
int V_48 = V_152 ;
struct V_149 * V_153 = NULL ;
V_154 = V_154 + 1 ;
if ( V_154 == V_152 )
V_154 = 0 ;
for( V_48 = V_152 ; V_48 > 0 ; V_48 -- ) {
if ( V_20 [ V_154 ] . type -> V_155 == V_54 ) {
if ( ++ V_154 == V_152 )
V_154 = 0 ;
continue;
}
V_151 = V_20 [ V_154 ] . V_156 -> V_157 ;
if ( V_151 ) {
V_153 = F_64 ( V_151 ) ;
if ( V_153 )
break;
}
if ( ++ V_154 == V_152 )
V_154 = 0 ;
}
return V_153 ;
}
static void F_65 ( void )
{
struct V_149 * V_153 ;
unsigned int V_48 , V_158 , V_21 , V_159 ;
int V_13 ;
struct V_160 * V_161 ;
char * V_37 ;
unsigned long V_15 ;
int V_162 ;
V_163:
V_153 = F_63 () ;
if ( ! V_153 ) {
return;
}
V_161 = V_153 -> V_164 -> V_165 ;
V_13 = V_161 - V_20 ;
V_166:
for ( V_48 = 0 , V_162 = 0 ; V_48 < F_66 ( V_153 ) ; V_48 ++ ) {
#ifdef F_10
F_11 ( L_38 ,
F_67 ( V_153 ) , V_48 ,
( F_68 ( V_153 ) == V_167 ) ? L_39 : L_40 ) ;
#endif
V_158 = F_67 ( V_153 ) + V_48 ;
if ( ( int ) V_158 > V_161 -> V_168 ) {
V_162 = - V_169 ;
break;
}
V_21 = V_158 / ( V_161 -> V_97 -> V_98 * V_161 -> type -> V_99 ) ;
V_159 = V_158 % ( V_161 -> V_97 -> V_98 * V_161 -> type -> V_99 ) ;
V_37 = V_153 -> V_170 + 512 * V_48 ;
#ifdef F_10
F_11 ( L_41
L_42 , V_21 , V_159 , V_37 ) ;
#endif
if ( F_62 ( V_13 , V_21 ) == - 1 ) {
V_162 = - V_169 ;
break;
}
if ( F_68 ( V_153 ) == V_167 ) {
memcpy ( V_37 , V_161 -> V_110 + V_159 * 512 , 512 ) ;
} else {
memcpy ( V_161 -> V_110 + V_159 * 512 , V_37 , 512 ) ;
if ( ! F_23 ( V_13 ) ) {
V_162 = - V_169 ;
break;
}
F_12 ( V_15 ) ;
V_161 -> V_84 = 1 ;
F_26 ( V_144 + V_13 , V_34 + 1 ) ;
F_14 ( V_15 ) ;
}
}
if ( F_69 ( V_153 , V_162 ) )
goto V_166;
goto V_163;
}
static void F_70 ( struct V_150 * V_151 )
{
F_65 () ;
}
static int F_71 ( struct V_171 * V_172 , struct V_173 * V_174 )
{
int V_13 = F_72 ( V_172 -> V_175 ) & 3 ;
V_174 -> V_139 = V_20 [ V_13 ] . type -> V_139 ;
V_174 -> V_176 = V_20 [ V_13 ] . V_97 -> V_98 * V_20 [ V_13 ] . type -> V_99 ;
V_174 -> V_177 = V_20 [ V_13 ] . type -> V_42 ;
return 0 ;
}
static int F_73 ( struct V_171 * V_172 , T_4 V_178 ,
unsigned int V_179 , unsigned long V_180 )
{
struct V_160 * V_181 = V_172 -> V_182 -> V_165 ;
int V_13 = V_181 - V_20 ;
static struct V_183 V_184 ;
void T_5 * V_185 = ( void T_5 * ) V_180 ;
switch( V_179 ) {
case V_186 :
F_9 ( V_13 ) ;
if ( V_187 [ V_13 ] > 1 ) {
F_15 () ;
return - V_188 ;
}
F_74 ( V_172 ) ;
if ( F_23 ( V_13 ) == 0 ) {
F_15 () ;
return - V_189 ;
}
if ( F_31 ( V_13 ) == 0 ) {
F_15 () ;
return - V_190 ;
}
F_30 ( V_13 ) ;
F_15 () ;
break;
case V_191 :
if ( V_180 < V_181 -> type -> V_42 * V_181 -> type -> V_139 )
{
F_9 ( V_13 ) ;
if ( F_32 ( V_13 , V_180 ) != 0 ) {
memset ( V_181 -> V_110 , V_192 ,
V_181 -> V_97 -> V_98 * V_181 -> type -> V_99 * 512 ) ;
F_61 ( V_13 ) ;
}
F_30 ( V_13 ) ;
F_15 () ;
}
else
return - V_193 ;
break;
case V_194 :
F_30 ( V_13 ) ;
F_75 ( V_172 ) ;
break;
case V_195 :
memset ( ( void * ) & V_184 , 0 , sizeof ( V_184 ) ) ;
V_184 . V_21 = V_181 -> type -> V_42 ;
V_184 . V_196 = V_181 -> type -> V_139 ;
V_184 . V_106 = V_181 -> V_97 -> V_98 * V_181 -> type -> V_99 ;
V_184 . V_197 = V_181 -> V_168 ;
if ( F_76 ( V_185 , & V_184 , sizeof( struct V_183 ) ) )
return - V_198 ;
break;
case V_199 :
case V_200 :
return - V_193 ;
case V_201 :
F_24 ( V_144 + V_13 ) ;
F_61 ( V_13 ) ;
break;
#ifdef F_77
case V_202 :
if ( F_76 ( V_185 , V_72 , V_181 -> type -> V_73 ) )
return - V_198 ;
else
return V_181 -> type -> V_73 ;
#endif
default:
F_11 ( V_203 L_43 ,
V_179 , V_13 ) ;
return - V_204 ;
}
return 0 ;
}
static int F_78 ( struct V_171 * V_172 , T_4 V_178 ,
unsigned int V_179 , unsigned long V_180 )
{
int V_205 ;
F_5 ( & V_206 ) ;
V_205 = F_73 ( V_172 , V_178 , V_179 , V_180 ) ;
F_7 ( & V_206 ) ;
return V_205 ;
}
static void F_79 ( int V_207 )
{
unsigned long V_155 ;
int type ;
int V_13 ;
V_13 = V_207 & 3 ;
V_155 = F_33 ( V_13 ) ;
for ( type = 0 ; type < V_208 ; type ++ )
if ( V_209 [ type ] . V_155 == V_155 )
break;
if ( type >= V_208 ) {
F_11 ( V_26 L_44
L_45 , V_155 ) ;
V_20 [ V_13 ] . type = & V_209 [ V_208 - 1 ] ;
return;
}
V_20 [ V_13 ] . type = V_209 + type ;
V_20 [ V_13 ] . V_21 = - 1 ;
V_20 [ V_13 ] . V_116 = - 1 ;
V_20 [ V_13 ] . V_23 = 0 ;
V_20 [ V_13 ] . V_210 = 0 ;
V_20 [ V_13 ] . V_211 = - 1 ;
}
static int F_80 ( struct V_171 * V_172 , T_4 V_178 )
{
int V_13 = F_72 ( V_172 -> V_175 ) & 3 ;
int system = ( F_72 ( V_172 -> V_175 ) & 4 ) >> 2 ;
int V_212 ;
unsigned long V_15 ;
F_5 ( & V_206 ) ;
V_212 = V_213 [ V_13 ] ;
if ( V_187 [ V_13 ] && V_212 != system ) {
F_7 ( & V_206 ) ;
return - V_188 ;
}
if ( V_178 & ( V_214 | V_215 ) ) {
F_81 ( V_172 ) ;
if ( V_178 & V_215 ) {
int V_216 ;
F_9 ( V_13 ) ;
F_17 ( V_13 ) ;
V_216 = ! ( V_9 . V_28 & V_76 ) ;
F_19 ( V_13 ) ;
F_15 () ;
if ( V_216 ) {
F_7 ( & V_206 ) ;
return - V_217 ;
}
}
}
F_12 ( V_15 ) ;
V_187 [ V_13 ] ++ ;
V_213 [ V_13 ] = system ;
F_14 ( V_15 ) ;
V_20 [ V_13 ] . V_97 = & V_218 [ system ] ;
V_20 [ V_13 ] . V_168 = V_20 [ V_13 ] . type -> V_139 * V_20 [ V_13 ] . type -> V_42 *
V_218 [ system ] . V_98 * V_20 [ V_13 ] . type -> V_99 ;
F_82 ( V_20 [ V_13 ] . V_156 , V_20 [ V_13 ] . V_168 ) ;
F_11 ( V_100 L_46 , V_13 ,
V_20 [ V_13 ] . type -> V_219 , V_218 [ system ] . V_219 ) ;
F_7 ( & V_206 ) ;
return 0 ;
}
static void F_83 ( struct V_156 * V_116 , T_4 V_178 )
{
struct V_160 * V_181 = V_116 -> V_165 ;
int V_13 = V_181 - V_20 ;
F_5 ( & V_206 ) ;
if ( V_20 [ V_13 ] . V_84 == 1 ) {
F_24 ( V_144 + V_13 ) ;
F_61 ( V_13 ) ;
}
if ( ! V_187 [ V_13 ] -- ) {
F_11 ( V_220 L_47 ) ;
V_187 [ V_13 ] = 0 ;
}
#ifdef F_28
F_30 ( V_13 | 0x40000000 ) ;
#endif
F_7 ( & V_206 ) ;
}
static unsigned F_84 ( struct V_156 * V_116 , unsigned int V_221 )
{
struct V_160 * V_181 = V_116 -> V_165 ;
int V_13 = V_181 - V_20 ;
int V_222 ;
static int V_223 = 1 ;
if ( V_223 )
V_222 = V_223 -- ;
else {
F_9 ( V_13 ) ;
F_17 ( V_13 ) ;
V_222 = ! ( V_9 . V_28 & V_224 ) ;
F_19 ( V_13 ) ;
F_15 () ;
}
if ( V_222 ) {
F_79 ( V_13 ) ;
V_181 -> V_21 = - 1 ;
V_181 -> V_84 = 0 ;
V_60 = 0 ;
V_83 = 0 ;
return V_225 ;
}
return 0 ;
}
static int T_6 F_85 ( void )
{
int V_13 , V_226 , V_227 ;
F_11 ( V_100 L_48 ) ;
V_226 = 0 ;
V_227 = 0 ;
for( V_13 = 0 ; V_13 < V_152 ; V_13 ++ ) {
struct V_156 * V_116 ;
F_79 ( V_13 ) ;
if ( V_20 [ V_13 ] . type -> V_155 == V_54 )
continue;
V_116 = F_86 ( 1 ) ;
if ( ! V_116 ) {
V_20 [ V_13 ] . type -> V_155 = V_54 ;
continue;
}
V_20 [ V_13 ] . V_156 = V_116 ;
V_116 -> V_157 = F_87 ( F_70 , & V_228 ) ;
if ( ! V_116 -> V_157 ) {
V_20 [ V_13 ] . type -> V_155 = V_54 ;
continue;
}
V_226 ++ ;
if ( ( V_20 [ V_13 ] . V_110 = F_88 ( V_229 * 512 , V_230 ) ) == NULL ) {
F_11 ( L_49 ) ;
V_20 [ V_13 ] . type = & V_209 [ V_208 - 1 ] ;
V_226 -- ;
V_227 = 1 ;
}
F_11 ( L_50 , V_13 ) ;
V_116 -> V_231 = V_232 ;
V_116 -> V_233 = V_13 ;
V_116 -> V_234 = & V_235 ;
sprintf ( V_116 -> V_236 , L_51 , V_13 ) ;
V_116 -> V_165 = & V_20 [ V_13 ] ;
F_82 ( V_116 , 880 * 2 ) ;
F_89 ( V_116 ) ;
}
if ( ( V_226 > 0 ) || ( V_227 == 0 ) ) {
if ( V_226 == 0 )
F_11 ( L_52 ) ;
F_11 ( L_53 ) ;
return V_226 ;
}
F_11 ( L_53 ) ;
return - V_237 ;
}
static struct V_238 * F_90 ( T_7 V_207 , int * V_239 , void * V_37 )
{
int V_13 = * V_239 & 3 ;
if ( V_20 [ V_13 ] . type -> V_155 == V_54 )
return NULL ;
* V_239 = 0 ;
return F_91 ( V_20 [ V_13 ] . V_156 ) ;
}
static int T_6 F_92 ( struct V_240 * V_241 )
{
int V_50 , V_205 ;
if ( F_93 ( V_232 , L_54 ) )
return - V_188 ;
V_205 = - V_237 ;
V_72 = F_94 ( V_242 , L_55 ) ;
if ( ! V_72 ) {
F_11 ( L_56 ) ;
goto V_243;
}
V_205 = - V_188 ;
if ( F_95 ( V_244 , F_36 , 0 , L_57 , NULL ) ) {
F_11 ( L_58 ) ;
goto V_245;
}
if ( F_95 ( V_246 , F_1 , 0 , L_59 , NULL ) ) {
F_11 ( L_60 ) ;
goto V_247;
}
V_205 = - V_189 ;
if ( F_85 () < 1 )
goto V_248;
F_96 ( F_97 ( V_232 , 0 ) , 256 , V_249 ,
F_90 , NULL , NULL ) ;
F_98 ( & V_32 ) ;
V_32 . V_33 = 0 ;
V_32 . V_37 = 0 ;
V_32 . V_250 = F_20 ;
for ( V_50 = 0 ; V_50 < V_152 ; V_50 ++ ) {
F_98 ( & V_36 [ V_50 ] ) ;
V_36 [ V_50 ] . V_33 = 0 ;
V_36 [ V_50 ] . V_37 = V_50 | 0x80000000 ;
V_36 [ V_50 ] . V_250 = F_27 ;
F_98 ( & V_144 [ V_50 ] ) ;
V_144 [ V_50 ] . V_33 = 0 ;
V_144 [ V_50 ] . V_37 = V_50 ;
V_144 [ V_50 ] . V_250 = F_60 ;
V_20 [ V_50 ] . V_21 = - 1 ;
}
F_98 ( & V_61 ) ;
V_61 . V_33 = 0 ;
V_61 . V_37 = 0 ;
V_61 . V_250 = F_40 ;
for ( V_50 = 0 ; V_50 < 128 ; V_50 ++ )
V_133 [ V_50 ] = 255 ;
for ( V_50 = 0 ; V_50 < 16 ; V_50 ++ )
V_133 [ V_143 [ V_50 ] ] = V_50 ;
V_58 . V_251 = V_252 | V_253 ;
V_9 . V_12 = 8 ;
return 0 ;
V_248:
F_99 ( V_246 , NULL ) ;
V_247:
F_99 ( V_244 , NULL ) ;
V_245:
F_100 ( V_72 ) ;
V_243:
F_101 ( V_232 , L_54 ) ;
return V_205 ;
}
static int T_6 F_102 ( void )
{
return F_103 ( & V_254 , F_92 ) ;
}
static int T_6 F_104 ( char * V_255 )
{
int V_40 ;
if ( ! V_256 )
return 0 ;
if ( ! F_105 ( & V_255 , & V_40 ) )
return 0 ;
F_11 ( V_100 L_61 , V_40 ) ;
V_55 = V_40 ;
return 1 ;
}
