static void F_1
( T_1 * V_1 , struct V_2 * V_3 [] )
{
struct V_2 * V_4 ;
V_4 = V_3 [ ( ( V_1 -> V_5 != 1 ) << 1 ) + ( V_1 -> V_6 != V_7 ) ] ;
while ( V_4 -> V_4 != - 1 ) {
F_2 ( V_1 , V_4 -> V_4 , V_4 -> V_8 ) ;
V_4 ++ ;
}
}
static void F_3
( T_1 * V_1 , unsigned int V_9 , unsigned int V_10 , unsigned int V_11 )
{
int V_12 ;
V_12 = F_4 ( V_1 , V_9 ) ;
V_12 = ( V_12 & ~ V_10 ) | ( V_11 & V_10 ) ;
F_2 ( V_1 , V_9 , V_12 ) ;
}
static void F_5
( int V_13 , unsigned long V_14 , int V_15 , int V_16 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
if ( V_1 -> V_18 ) {
V_1 -> V_19 = V_14 ;
V_1 -> V_20 = V_15 ;
V_1 -> V_21 = V_16 ;
V_1 -> V_22 = V_23 ;
} else {
V_1 -> V_24 = V_14 ;
V_1 -> V_25 = V_15 ;
V_1 -> V_26 = V_16 ;
V_1 -> V_27 = V_23 ;
}
}
static void F_6
( int V_13 , unsigned long V_14 , int V_28 , int V_16 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
V_1 -> V_24 = V_14 ;
V_1 -> V_25 = V_28 ;
V_1 -> V_26 = V_16 ;
V_1 -> V_27 = V_29 ;
}
static int F_7 ( int clock , int V_30 , int * V_31 , int * V_32 )
{
int V_33 ;
int V_34 , V_35 ;
int V_36 ;
V_34 = * V_31 ;
V_33 = ( clock + V_34 / 2 ) / V_34 ;
V_36 = V_30 - V_33 ;
if ( V_36 > V_30 - 1 ) {
V_36 = V_30 - 1 ;
V_33 = V_30 - V_36 ;
}
* V_31 = clock / V_33 ;
V_35 = V_34 - * V_31 ;
if ( V_35 < 0 ) V_35 = - V_35 ;
* V_32 = V_35 ;
return V_36 ;
}
static int F_8
( int V_37 , int V_38 , int V_39 , int V_40 , int * V_41 , int * V_31 )
{
int V_42 = * V_31 , V_43 = * V_31 ;
int V_44 , V_45 ;
int V_46 , V_47 ;
int V_36 ;
V_44 = F_7 ( V_37 , V_38 , & V_42 , & V_46 ) ;
V_45 = F_7 ( V_39 , V_40 , & V_43 , & V_47 ) ;
if ( V_46 < V_47 ) {
* V_41 = V_44 ;
* V_31 = V_42 ;
V_36 = 1 ;
} else {
* V_41 = 0x80 | V_45 ;
* V_31 = V_43 ;
V_36 = 2 ;
}
return V_36 ;
}
static void F_9 ( T_1 * V_1 , int * V_31 , int * V_41 )
{
int V_35 = 0 , div ;
if ( V_1 -> V_18 ) {
if ( V_1 -> V_48 == V_49 ) {
div = 0x80 | F_7 ( 795500 , 256 , V_31 , & V_35 ) ;
} else {
div = 0x80 | F_7 ( 795500 , 128 , V_31 , & V_35 ) ;
}
} else if( V_1 -> V_50 & V_51 ) {
if ( V_1 -> V_48 == V_49 ) {
F_8 ( 397700 , 128 , 795500 , 256 ,
& div , V_31 ) ;
} else {
F_8 ( V_52 , 128 , V_53 , 256 ,
& div , V_31 ) ;
}
} else {
if ( * V_31 > 22000 ) {
div = 0x80 | F_7 ( V_54 , 256 , V_31 , & V_35 ) ;
} else {
div = 0x00 | F_7 ( V_55 , 128 , V_31 , & V_35 ) ;
}
}
* V_41 = div ;
}
static void F_10 ( T_1 * V_1 , int V_56 )
{
int V_34 ;
int div , V_45 ;
F_9 ( V_1 , & ( V_1 -> V_34 ) , & div ) ;
#ifdef F_11
F_12 ( V_57 L_1 , V_56 , V_1 -> V_34 , div ) ;
#endif
V_34 = ( V_1 -> V_34 * 9 ) / 20 ;
V_45 = 256 - 7160000 / ( V_34 * 82 ) ;
if ( ! V_1 -> V_18 ) V_56 = 1 ;
if ( V_56 == 1 ) {
F_2 ( V_1 , 0xa1 , div ) ;
F_2 ( V_1 , 0xa2 , V_45 ) ;
} else {
F_13 ( V_1 , 0x70 , div ) ;
F_2 ( V_1 , 0xa2 , V_45 ) ;
F_13 ( V_1 , 0x72 , V_45 ) ;
}
}
static int F_14 ( int V_13 , int V_58 , int V_59 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
F_10 ( V_1 , 1 ) ;
F_15 ( V_1 , V_60 ) ;
F_2 ( V_1 , 0xb8 , 0x0e ) ;
F_3 ( V_1 , 0xa8 , 0x03 , 3 - V_1 -> V_5 ) ;
F_2 ( V_1 , 0xb9 , 2 ) ;
F_1 ( V_1 , V_61 ) ;
F_3 ( V_1 , 0xb1 , 0xf0 , 0x50 ) ;
F_3 ( V_1 , 0xb2 , 0xf0 , 0x50 ) ;
V_1 -> V_62 = 0 ;
return 0 ;
}
static int F_16 ( int V_13 , int V_58 , int V_59 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
F_17 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
F_2 ( V_1 , 0xb8 , 4 ) ;
F_3 ( V_1 , 0xa8 , 0x03 , 3 - V_1 -> V_5 ) ;
F_2 ( V_1 , 0xb9 , 2 ) ;
F_1 ( V_1 , V_63 ) ;
F_3 ( V_1 , 0xb1 , 0xf0 , 0x50 ) ;
F_3 ( V_1 , 0xb2 , 0xf0 , 0x50 ) ;
F_15 ( V_1 , V_64 ) ;
V_1 -> V_62 = 0 ;
return 0 ;
}
static int F_18 ( int V_13 , int V_58 , int V_59 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
unsigned char V_6 ;
F_19 ( V_1 , 0x78 , 0xd0 , 0xd0 ) ;
F_10 ( V_1 , 2 ) ;
V_6 = F_20 ( V_1 , 0x7a ) & 0x18 ;
if ( V_1 -> V_5 != 1 ) V_6 |= 0x02 ;
if ( V_1 -> V_6 != V_7 ) V_6 |= 0x05 ;
V_6 |= 0x60 ;
F_13 ( V_1 , 0x7a , V_6 ) ;
F_21 ( V_1 , V_65 ) ;
V_1 -> V_62 = 0 ;
return 0 ;
}
static int F_22 ( int V_13 , int V_58 , int V_59 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
#ifdef F_11
F_12 ( V_57 L_2
, V_17 [ V_13 ] -> V_66 -> V_67 , V_17 [ V_13 ] -> V_68 -> V_67 ) ;
#endif
if ( V_1 -> V_18 ) {
return F_18 ( V_13 , V_58 , V_59 ) ;
} else {
return F_16 ( V_13 , V_58 , V_59 ) ;
}
}
static void F_23 ( int V_13 )
{
unsigned long V_69 ;
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
F_24 ( & V_1 -> V_70 , V_69 ) ;
F_17 ( V_1 ) ;
F_25 ( & V_1 -> V_70 , V_69 ) ;
if ( V_1 -> V_18 ) F_19 ( V_1 , 0x78 , 0x03 , 0x00 ) ;
}
static void F_26
( int V_13 , unsigned long V_14 , int V_15 , int V_16 )
{
int V_28 = V_15 ;
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
short V_71 = - V_15 ;
if ( V_17 [ V_13 ] -> V_68 -> V_67 > 3 ) V_28 >>= 1 ;
V_28 -- ;
V_1 -> V_27 = V_29 ;
F_2 ( V_1 , 0xa4 , ( unsigned char ) ( ( unsigned short ) V_71 & 0xff ) ) ;
F_2 ( V_1 , 0xa5 , ( unsigned char ) ( ( ( unsigned short ) V_71 >> 8 ) & 0xff ) ) ;
F_3 ( V_1 , 0xb8 , 0x0f , 0x0f ) ;
V_1 -> V_72 = 1 ;
}
static void F_27
( int V_13 , unsigned long V_14 , int V_15 , int V_16 )
{
int V_28 = V_15 ;
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
short V_71 = - V_15 ;
if ( V_17 [ V_13 ] -> V_66 -> V_67 > 3 )
V_28 >>= 1 ;
V_28 -- ;
V_1 -> V_27 = V_23 ;
F_2 ( V_1 , 0xa4 , ( unsigned char ) ( ( unsigned short ) V_71 & 0xff ) ) ;
F_2 ( V_1 , 0xa5 , ( unsigned char ) ( ( ( unsigned short ) V_71 >> 8 ) & 0xff ) ) ;
F_3 ( V_1 , 0xb8 , 0x05 , 0x05 ) ;
V_1 -> V_72 = 1 ;
}
static void F_28
( int V_13 , unsigned long V_14 , int V_15 , int V_16 )
{
int V_28 = V_15 ;
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
short V_71 = - V_15 ;
if ( V_17 [ V_13 ] -> V_66 -> V_67 > 3 ) V_28 >>= 1 ;
V_28 -- ;
F_13 ( V_1 , 0x74 , ( unsigned char ) ( ( unsigned short ) V_71 & 0xff ) ) ;
F_13 ( V_1 , 0x76 , ( unsigned char ) ( ( ( unsigned short ) V_71 >> 8 ) & 0xff ) ) ;
F_19 ( V_1 , 0x78 , 0x03 , 0x03 ) ;
V_1 -> V_22 = V_23 ;
V_1 -> V_73 = 1 ;
}
static void F_29
( int V_13 , unsigned long V_14 , int V_15 , int V_16 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
if ( V_1 -> V_18 ) {
F_28 ( V_13 , V_14 , V_15 , V_16 ) ;
} else {
F_27 ( V_13 , V_14 , V_15 , V_16 ) ;
}
}
static void F_30 ( int V_13 , int V_6 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
int V_74 = V_6 & V_1 -> V_22 ;
V_6 &= V_1 -> V_27 ;
if ( ! V_6 && ! V_74 ) {
F_15 ( V_1 , 0xd0 ) ;
}
if ( V_6 ) {
switch ( V_1 -> V_27 )
{
case V_29 :
F_26 ( V_13 , V_1 -> V_24 , V_1 -> V_25 ,
V_1 -> V_26 ) ;
break;
case V_23 :
F_29 ( V_13 , V_1 -> V_24 , V_1 -> V_25 ,
V_1 -> V_26 ) ;
break;
}
}
if ( V_74 ) {
switch ( V_1 -> V_22 ) {
case V_29 :
F_26 ( V_13 , V_1 -> V_19 , V_1 -> V_20 ,
V_1 -> V_21 ) ;
break;
case V_23 :
F_29 ( V_13 , V_1 -> V_19 , V_1 -> V_20 ,
V_1 -> V_21 ) ;
break;
}
}
V_1 -> V_62 = V_6 | V_74 ;
}
static int F_31 ( int V_13 , int V_34 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
int V_75 , V_76 , V_77 ;
if ( V_34 > 0 ) {
V_75 = ( V_1 -> V_18 ? 6215 : 5000 ) ;
V_76 = ( V_1 -> V_18 ? 44100 : 48000 ) ;
if ( V_34 < V_75 ) V_34 = V_75 ;
if ( V_34 > V_76 ) V_34 = V_76 ;
F_9 ( V_1 , & V_34 , & V_77 ) ;
V_1 -> V_34 = V_34 ;
}
return V_1 -> V_34 ;
}
static unsigned int F_32 ( int V_13 , unsigned int V_6 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
if ( V_6 != 0 ) {
if ( V_6 == V_7 || V_6 == V_78 ) {
V_1 -> V_6 = V_6 ;
} else {
V_1 -> V_6 = V_7 ;
}
}
return V_1 -> V_6 ;
}
static short F_33 ( int V_13 , short V_5 )
{
T_1 * V_1 = V_17 [ V_13 ] -> V_1 ;
if ( V_5 == 1 || V_5 == 2 ) V_1 -> V_5 = V_5 ;
return V_1 -> V_5 ;
}
struct V_79 * F_34
( T_1 * V_1 , int * V_80 , int * V_81 )
{
* V_80 = V_82 ;
* V_81 |= V_78 ;
if ( V_1 -> V_18 ) {
int V_83 ;
V_83 = V_1 -> V_84 ;
V_1 -> V_84 = V_1 -> V_85 ;
V_1 -> V_85 = V_83 ;
* V_80 |= V_86 ;
}
return & V_87 ;
}
static void F_35
( char * V_88 , int V_13 , int V_72 , unsigned char V_89 , int V_27 )
{
if ( ! V_72 || ! V_89 ) return;
#ifdef F_11
F_12 ( V_57 L_3 , V_88 , V_27 ) ;
#endif
switch ( V_27 ) {
case V_23 :
F_36 ( V_13 , 1 ) ;
break;
case V_29 :
F_37 ( V_13 ) ;
break;
case V_90 :
break;
default: ;
}
}
void F_38 ( T_1 * V_1 )
{
int V_91 ;
unsigned char V_92 ;
if ( V_1 -> V_48 == V_93 ) {
V_92 = F_20 ( V_1 , 0x7f ) >> 4 ;
} else {
V_92 = 0xff ;
}
#ifdef F_11
F_12 ( V_57 L_4 , ( int ) V_92 ) ;
#endif
F_35
( L_5
, V_1 -> V_13 , V_1 -> V_72 , V_92 & 0x01 , V_1 -> V_27 ) ;
F_35
( L_6
, V_1 -> V_13 , V_1 -> V_73 , V_92 & 0x02 , V_1 -> V_22 ) ;
if ( V_1 -> V_48 == V_93 && ( V_92 & 0x02 ) ) {
F_19 ( V_1 , 0x7a , 0x80 , 0x00 ) ;
}
if ( V_92 & 0x01 ) {
V_91 = F_39 ( V_94 ) ;
}
}
static void F_40 ( T_1 * V_1 )
{
F_15 ( V_1 , 0xc6 ) ;
}
static int F_2 ( T_1 * V_1 , unsigned char V_9 , unsigned char V_8 )
{
#ifdef F_11
F_12 ( V_57 L_7 , V_9 , V_8 ) ;
#endif
if ( ! F_15 ( V_1 , V_9 ) )
return 0 ;
return F_15 ( V_1 , V_8 ) ;
}
static int F_4 ( T_1 * V_1 , unsigned char V_9 )
{
if ( ! F_15 ( V_1 , 0xc0 ) ) return - 1 ;
if ( ! F_15 ( V_1 , V_9 ) ) return - 1 ;
return F_41 ( V_1 ) ;
}
int F_42 ( T_1 * V_1 )
{
int V_95 ;
#ifdef F_11
F_12 ( V_57 L_8 ) ;
F_43 ( V_1 ) ;
#endif
F_44 ( 3 , V_96 ) ;
F_45 ( 10 ) ;
F_44 ( 0 , V_96 ) ;
F_45 ( 30 ) ;
for ( V_95 = 0 ; V_95 < 1000 && ! ( F_39 ( V_94 ) & 0x80 ) ; V_95 ++ ) ;
if ( F_39 ( V_97 ) != 0xAA ) {
F_46 ( F_12 ( L_9 ) ) ;
return 0 ;
}
F_40 ( V_1 ) ;
#ifdef F_47
F_12 ( V_57 L_10 ) ;
F_43 ( V_1 ) ;
#endif
return 1 ;
}
static int F_48 ( int V_98 )
{
switch ( V_98 ) {
case 2 :
case 9 :
return 0 ;
case 5 :
return 1 ;
case 7 :
return 2 ;
case 10 :
return 3 ;
default:
F_12 ( V_99 L_11 , V_98 ) ;
return - 1 ;
}
}
static int F_49 ( T_1 * V_1 )
{
int V_100 ;
if ( ( V_100 = F_48 ( V_1 -> V_98 ) ) == - 1 ) return 0 ;
if ( ! F_2 ( V_1 , 0xb1 , 0x50 | ( V_100 << 2 ) ) ) {
F_12 ( V_99 L_12 ) ;
return 0 ;
}
return 1 ;
}
static void F_50 ( T_1 * V_1 )
{
int V_100 ;
if ( ( V_100 = F_48 ( V_1 -> V_98 ) ) == - 1 ) return;
F_19 ( V_1 , 0x7f , 0x0f , 0x01 | ( ( V_100 + 1 ) << 1 ) ) ;
}
static int F_51 ( T_1 * V_1 )
{
if ( V_1 -> V_48 == V_93 ) F_50 ( V_1 ) ;
return F_49 ( V_1 ) ;
}
static void F_52 ( T_1 * V_1 )
{
int V_101 , V_102 ;
V_101 = F_20 ( V_1 , 0x64 ) ;
F_13 ( V_1 , 0x64 , ~ V_101 ) ;
V_102 = F_20 ( V_1 , 0x64 ) ^ ~ V_101 ;
F_13 ( V_1 , 0x64 , V_101 ) ;
V_101 ^= F_20 ( V_1 , 0x64 ) ;
F_12 ( V_57 L_13 , ( V_101 & 0x0ff ) , ( V_102 & 0x0ff ) ) ;
}
static unsigned int F_53 ( T_1 * V_1 )
{
unsigned int V_11 ;
unsigned long V_69 ;
F_24 ( & V_1 -> V_70 , V_69 ) ;
F_44 ( ( ( unsigned char ) ( 0x40 & 0xff ) ) , V_103 ) ;
F_45 ( 20 ) ;
V_11 = F_39 ( V_104 ) << 8 ;
F_45 ( 20 ) ;
V_11 |= F_39 ( V_104 ) ;
F_45 ( 20 ) ;
F_25 ( & V_1 -> V_70 , V_69 ) ;
return V_11 ;
}
static int F_54 ( T_1 * V_1 , int V_9 , int V_105 )
{
int V_101 , V_102 , V_106 ;
V_101 = F_20 ( V_1 , V_9 ) ;
V_102 = V_101 ^ V_105 ;
F_13 ( V_1 , V_9 , V_102 ) ;
V_106 = F_20 ( V_1 , V_9 ) ;
F_13 ( V_1 , V_9 , V_101 ) ;
return ( V_102 == V_106 ) ;
}
int F_55 ( T_1 * V_1 , struct V_107 * V_108 )
{
unsigned char V_109 ;
int V_110 = 0 , V_111 = 0 ;
int V_112 ;
static char V_113 [ 100 ] , V_114 [ 10 ] ;
F_15 ( V_1 , 0xe7 ) ;
for ( V_112 = 1000 ; V_112 ; V_112 -- ) {
if ( F_39 ( V_94 ) & 0x80 ) {
if ( V_110 == 0 ) {
V_110 = F_39 ( V_97 ) ;
} else {
V_111 = F_39 ( V_97 ) ;
break;
}
}
}
if ( V_110 == 0 ) return 0 ;
if ( V_110 == 0x48 && ( V_111 & 0xf0 ) == 0x80 ) {
sprintf ( V_113 , L_14 ,
V_111 & 0x0f ) ;
V_108 -> V_113 = V_113 ;
V_1 -> V_115 = V_116 ;
return 1 ;
}
V_1 -> V_115 = V_117 ;
V_1 -> V_48 = V_111 & 0x0f ;
if ( V_110 == 0x68 && ( V_111 & 0xf0 ) == 0x80 ) {
char * V_118 = NULL ;
int V_48 = - 1 ;
switch ( V_1 -> V_119 . V_120 ) {
case V_121 :
case V_122 :
break;
case 688 :
V_48 = 0x00 ;
break;
case 1688 :
V_48 = 0x08 ;
break;
case 1868 :
V_48 = V_123 ;
break;
case 1869 :
V_48 = V_124 ;
break;
case 1788 :
V_48 = V_125 ;
break;
case 1878 :
V_48 = V_126 ;
break;
case 1879 :
V_48 = V_127 ;
break;
case 1887 :
V_48 = V_93 ;
break;
case 1888 :
V_48 = V_49 ;
break;
default:
F_12 ( V_99 L_15 , V_1 -> V_119 . V_120 ) ;
return 0 ;
}
if ( V_48 != - 1 ) {
V_1 -> V_48 = V_48 ;
sprintf ( V_114 , L_16 , V_1 -> V_119 . V_120 ) ;
V_118 = V_114 ;
}
if ( V_118 == NULL && ( V_111 & 0x0f ) < 8 ) {
V_118 = L_17 ;
}
#ifdef F_56
F_52 ( V_1 ) ;
#endif
if ( V_118 == NULL && V_1 -> V_119 . V_120 == V_122 ) {
V_118 = L_18 ;
}
if ( V_118 == NULL ) {
int type ;
type = F_53 ( V_1 ) ;
switch ( type ) {
case 0x1868 :
V_118 = L_19 ;
V_1 -> V_48 = V_123 ;
break;
case 0x1869 :
V_118 = L_20 ;
V_1 -> V_48 = V_124 ;
break;
case 0x1878 :
V_118 = L_21 ;
V_1 -> V_48 = V_126 ;
break;
case 0x1879 :
V_118 = L_22 ;
V_1 -> V_48 = V_127 ;
break;
default:
if ( ( type & 0x00ff ) != ( ( type >> 8 ) & 0x00ff ) ) {
F_12 ( L_23 , type ) ;
}
}
}
#if 0
if (chip == NULL && !ess_probe(devc, 0x64, (1 << 4))) {
#endif
if ( V_118 == NULL && F_54 ( V_1 , 0x64 , ( 1 << 2 ) ) ) {
if ( F_54 ( V_1 , 0x70 , 0x7f ) ) {
if ( F_54 ( V_1 , 0x64 , ( 1 << 5 ) ) ) {
V_118 = L_24 ;
V_1 -> V_48 = V_93 ;
} else {
V_118 = L_25 ;
V_1 -> V_48 = V_49 ;
}
} else {
V_118 = L_26 ;
V_1 -> V_48 = V_125 ;
}
}
if ( V_118 == NULL ) {
V_118 = L_18 ;
}
F_12 ( V_57 L_27 , V_118 ,
( V_1 -> V_119 . V_120 == V_121 ||
V_1 -> V_119 . V_120 == V_122 ) ?
L_28 : L_29 ,
V_1 -> V_119 . V_120 == V_122 ?
L_30 : L_31 ) ;
sprintf ( V_113 , L_32 , V_118 , V_111 & 0x0f ) ;
} else {
strcpy ( V_113 , L_33 ) ;
}
switch( V_1 -> V_48 ) {
case V_49 :
V_1 -> V_50 |= V_51 ;
break;
}
V_108 -> V_113 = V_113 ;
F_17 ( V_1 ) ;
V_109 = F_20 ( V_1 , 0x40 ) ;
F_13 ( V_1 , 0x40 , V_109 | 0x03 ) ;
if ( V_1 -> V_48 >= 8 ) {
V_1 -> V_50 |= V_128 ;
}
F_17 ( V_1 ) ;
return F_51 ( V_1 ) ;
}
static int F_57 ( T_1 * V_1 )
{
unsigned char V_109 , V_129 = 0 , V_130 ;
int V_67 ;
#ifdef F_47
F_12 ( V_57 L_34
, V_1 -> V_85 , V_1 -> V_84 , V_1 -> V_18 ) ;
#endif
V_67 = V_1 -> V_85 ;
if ( V_67 > 3 || V_67 < 0 || V_67 == 2 ) {
V_129 = 0 ;
F_12 ( V_99 L_35 , V_67 ) ;
return 0 ;
} else {
V_109 = 0x50 ;
if ( V_67 == 3 ) {
V_129 = 3 ;
} else {
V_129 = V_67 + 1 ;
}
}
if ( ! F_2 ( V_1 , 0xb2 , V_109 | ( V_129 << 2 ) ) ) {
F_12 ( V_99 L_36 ) ;
return 0 ;
}
if ( V_1 -> V_18 ) {
V_67 = V_1 -> V_84 ;
V_130 = 0 ;
if ( V_67 >= 0 ) {
switch ( V_67 ) {
case 0 :
V_129 = 0x04 ;
break;
case 1 :
V_129 = 0x05 ;
break;
case 3 :
V_129 = 0x06 ;
break;
case 5 :
V_129 = 0x07 ;
V_130 = 0x20 ;
break;
default:
F_12 ( V_99 L_37 , V_67 ) ;
return 0 ;
}
F_19 ( V_1 , 0x78 , 0x20 , V_130 ) ;
F_19 ( V_1 , 0x7d , 0x07 , V_129 ) ;
}
}
return 1 ;
}
int F_58 ( T_1 * V_1 , struct V_107 * V_108 )
{
if ( V_1 -> V_115 != V_117 ) {
F_12 ( V_57 L_38 ) ;
return 1 ;
}
if ( V_1 -> V_48 == V_93 ) {
if ( V_108 -> V_131 != - 1 ) {
V_1 -> V_84 = V_108 -> V_131 ;
}
if ( V_1 -> V_85 != V_1 -> V_84 && V_1 -> V_84 != - 1 ) {
V_1 -> V_18 = 1 ;
}
}
if ( ! F_57 ( V_1 ) ) {
F_59 ( V_1 -> V_98 , V_1 ) ;
return 0 ;
}
return 1 ;
}
static int F_60 ( int V_48 )
{
switch ( V_48 ) {
case V_93 :
return 1 ;
default:
return 0 ;
}
}
static void F_43 ( T_1 * V_1 )
{
int * V_132 = V_133 ;
return;
while ( * V_132 != 0 ) {
F_12 ( V_57 L_39 , * V_132 , ( int ) ( F_20 ( V_1 , * V_132 ) ) ) ;
V_132 ++ ;
}
}
void F_13 ( T_1 * V_1 , unsigned int V_134 , unsigned int V_12 )
{
unsigned long V_69 ;
#ifdef F_47
F_12 ( V_57 L_40 , V_134 , V_12 ) ;
#endif
F_24 ( & V_1 -> V_70 , V_69 ) ;
if ( V_134 >= 0xa0 ) {
F_2 ( V_1 , V_134 , V_12 ) ;
} else {
F_44 ( ( ( unsigned char ) ( V_134 & 0xff ) ) , V_103 ) ;
F_45 ( 20 ) ;
F_44 ( ( ( unsigned char ) ( V_12 & 0xff ) ) , V_104 ) ;
F_45 ( 20 ) ;
}
F_25 ( & V_1 -> V_70 , V_69 ) ;
}
unsigned int F_20 ( T_1 * V_1 , unsigned int V_134 )
{
unsigned int V_11 ;
unsigned long V_69 ;
F_24 ( & V_1 -> V_70 , V_69 ) ;
if ( V_134 >= 0xa0 ) {
V_11 = F_4 ( V_1 , V_134 ) ;
} else {
F_44 ( ( ( unsigned char ) ( V_134 & 0xff ) ) , V_103 ) ;
F_45 ( 20 ) ;
V_11 = F_39 ( V_104 ) ;
F_45 ( 20 ) ;
}
F_25 ( & V_1 -> V_70 , V_69 ) ;
return V_11 ;
}
static void F_19
( T_1 * V_1 , unsigned int V_9 , unsigned int V_10 , unsigned int V_11 )
{
int V_12 ;
V_12 = F_20 ( V_1 , V_9 ) ;
V_12 = ( V_12 & ~ V_10 ) | ( V_11 & V_10 ) ;
F_13 ( V_1 , V_9 , V_12 ) ;
}
void F_61 ( T_1 * V_1 )
{
V_1 -> V_135 = V_136 ;
switch ( V_1 -> V_48 ) {
case V_93 :
V_1 -> V_137 = V_138 ;
V_1 -> V_139 = V_140 ;
#ifdef F_47
F_12 ( V_57 L_41 , V_1 -> V_18 ) ;
#endif
if ( V_1 -> V_18 ) {
V_1 -> V_141 = & V_142 ;
V_1 -> V_143 = F_62 ( V_142 ) ;
} else {
V_1 -> V_141 = & V_144 ;
V_1 -> V_143 = F_62 ( V_144 ) ;
}
break;
default:
if ( V_1 -> V_48 < 8 ) {
V_1 -> V_137 = V_145 ;
V_1 -> V_139 = V_146 ;
V_1 -> V_141 = & V_147 ;
V_1 -> V_143 = F_62 ( V_147 ) ;
} else {
V_1 -> V_137 = V_148 ;
V_1 -> V_139 = V_149 ;
if ( V_1 -> V_48 < 0x10 ) {
V_1 -> V_141 = & V_150 ;
V_1 -> V_143 = F_62 ( V_147 ) ;
} else {
V_1 -> V_141 = & V_151 ;
V_1 -> V_143 = F_62 ( V_151 ) ;
}
}
}
}
int F_63 ( T_1 * V_1 , int V_13 , int V_152 , int V_153 )
{
if ( F_60 ( V_1 -> V_48 ) && ( V_1 -> V_154 & ( 1 << V_13 ) ) ) {
F_64 ( V_1 , V_13 + V_155 , V_152 , V_153 ) ;
}
return F_64 ( V_1 , V_13 , V_152 , V_153 ) ;
}
void F_21 ( T_1 * V_1 , int V_13 )
{
int V_152 , V_153 , V_12 ;
V_12 = V_1 -> V_156 [ V_13 ] ;
V_152 = V_12 & 0x000000ff ;
V_153 = ( V_12 & 0x0000ff00 ) >> 8 ;
F_64 ( V_1 , V_13 , V_152 , V_153 ) ;
}
static int F_65 ( T_1 * V_1 , int V_10 )
{
int V_112 , V_157 , V_158 , V_159 ;
int V_12 , V_152 , V_153 ;
#ifdef F_47
F_12 ( V_57 L_42 , V_10 ) ;
#endif
V_158 = V_1 -> V_154 ;
V_159 = ( V_158 ^ V_10 ) ;
for ( V_112 = 0 ; V_112 < 32 ; V_112 ++ ) {
V_157 = ( 1 << V_112 ) ;
if ( V_159 & V_157 ) {
if ( V_10 & V_157 ) {
V_12 = V_1 -> V_156 [ V_112 ] ;
V_152 = V_12 & 0x000000ff ;
V_153 = ( V_12 & 0x0000ff00 ) >> 8 ;
} else {
V_152 = 0 ;
V_153 = 0 ;
}
F_64 ( V_1 , V_112 + V_155 , V_152 , V_153 ) ;
}
}
return V_10 ;
}
int F_66 ( T_1 * V_1 , int * V_10 )
{
if ( F_60 ( V_1 -> V_48 ) ) {
* V_10 = F_65 ( V_1 , * V_10 ) ;
return 1 ;
} else {
return 0 ;
}
}
int F_67 ( T_1 * V_1 )
{
if ( F_60 ( V_1 -> V_48 ) ) {
switch ( V_1 -> V_48 ) {
case V_93 :
F_19 ( V_1 , 0x7a , 0x18 , 0x08 ) ;
F_19 ( V_1 , 0x1c , 0x07 , 0x07 ) ;
break;
}
V_1 -> V_154 = V_1 -> V_139 ;
F_65 ( V_1 , 0 ) ;
V_1 -> V_154 = 0 ;
return 1 ;
} else {
return 0 ;
}
}
int F_68 ( T_1 * V_1 , struct V_107 * V_108 )
{
unsigned char V_109 , V_160 ;
V_109 = F_20 ( V_1 , 0x40 ) & 0x03 ;
if ( V_1 -> V_48 < 8 ) {
F_13 ( V_1 , 0x40 , V_109 | 0x03 ) ;
return 0 ;
}
V_160 = ( V_108 -> V_161 & 0x0f0 ) >> 4 ;
if ( V_160 > 3 ) {
F_13 ( V_1 , 0x40 , V_109 ) ;
return 0 ;
}
V_109 |= V_160 << 3 ;
V_160 = 1 ;
switch ( abs ( V_108 -> V_98 ) ) {
case 9 :
V_160 = 0x4 ;
break;
case 5 :
V_160 = 0x5 ;
break;
case 7 :
V_160 = 0x6 ;
break;
case 10 :
V_160 = 0x7 ;
break;
default:
return 0 ;
}
V_109 |= V_160 << 5 ;
F_13 ( V_1 , 0x40 , V_109 | 0x03 ) ;
return 1 ;
}
