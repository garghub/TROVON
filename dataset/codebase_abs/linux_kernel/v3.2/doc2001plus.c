static void F_1 ( void T_1 * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; ( V_3 < V_2 ) ; V_3 ++ )
F_2 ( 0 , V_1 , V_4 ) ;
}
static int F_3 ( void T_1 * V_1 )
{
unsigned int V_5 = 0xffff ;
F_4 ( L_1 ) ;
while ( ( ( F_5 ( V_1 , V_6 ) & V_7 ) != V_7 ) && -- V_5 )
;
if ( V_5 == 0 )
F_4 ( L_2 ) ;
return ( V_5 == 0 ) ;
}
static inline int F_6 ( void T_1 * V_1 )
{
int V_8 = 0 ;
F_1 ( V_1 , 4 ) ;
if ( ( F_5 ( V_1 , V_6 ) & V_7 ) != V_7 )
V_8 = F_3 ( V_1 ) ;
return V_8 ;
}
static inline void F_7 ( void T_1 * V_1 )
{
if ( ( F_5 ( V_1 , V_9 ) & V_10 ) == 0 ) {
F_2 ( ( V_10 | V_11 ) , V_1 , V_9 ) ;
F_2 ( ~ ( V_10 | V_11 ) , V_1 , V_12 ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char V_13 ,
unsigned char V_14 )
{
F_2 ( V_13 , V_1 , V_15 ) ;
F_2 ( V_13 , V_1 , V_16 ) ;
F_2 ( V_13 , V_1 , V_16 ) ;
}
static inline void F_9 ( struct V_17 * V_18 , int V_19 ,
unsigned long V_20 , unsigned char V_21 ,
unsigned char V_22 )
{
void T_1 * V_1 = V_18 -> V_23 ;
V_20 >>= V_18 -> V_24 ;
switch ( V_19 ) {
case 1 :
F_2 ( V_20 & 0xff , V_1 , V_25 ) ;
break;
case 2 :
F_2 ( ( V_20 >> 9 ) & 0xff , V_1 , V_25 ) ;
F_2 ( ( V_20 >> 17 ) & 0xff , V_1 , V_25 ) ;
break;
case 3 :
F_2 ( V_20 & 0xff , V_1 , V_25 ) ;
F_2 ( ( V_20 >> 9 ) & 0xff , V_1 , V_25 ) ;
F_2 ( ( V_20 >> 17 ) & 0xff , V_1 , V_25 ) ;
break;
default:
return;
}
F_2 ( 0x00 , V_1 , V_16 ) ;
F_2 ( 0x00 , V_1 , V_16 ) ;
}
static int F_10 ( void T_1 * V_1 , int V_26 )
{
return 0 ;
}
static int F_11 ( void T_1 * V_1 , int floor )
{
F_2 ( ( floor & 0x3 ) , V_1 , V_27 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_28 * V_29 , T_2 * V_30 )
{
struct V_17 * V_31 = V_29 -> V_32 ;
if ( V_31 -> V_24 ) {
unsigned int V_20 = * V_30 & 0x3ff ;
unsigned int V_33 ;
if ( V_20 < 512 ) {
V_33 = V_34 ;
V_20 &= 0x1ff ;
} else if ( V_20 < 1014 ) {
V_33 = V_35 ;
V_20 = ( V_20 & 0x1ff ) + 10 ;
} else {
V_33 = V_36 ;
V_20 = V_20 - 1014 ;
}
* V_30 = ( * V_30 & ~ 0x3ff ) | V_20 ;
return V_33 ;
} else {
if ( ( * V_30 ) & 0x100 )
return V_35 ;
return V_34 ;
}
}
static unsigned int F_13 ( struct V_28 * V_29 , T_2 * V_30 )
{
unsigned int V_20 , V_33 ;
if ( * V_30 & 0x200 ) {
V_33 = V_36 ;
V_20 = 10 + ( * V_30 & 0xf ) ;
} else {
V_33 = V_35 ;
V_20 = ( * V_30 & 0xf ) ;
}
* V_30 = ( * V_30 & ~ 0x3ff ) | V_20 ;
return V_33 ;
}
static unsigned int F_14 ( struct V_28 * V_29 , T_2 * V_30 )
{
unsigned int V_20 , V_33 ;
V_33 = V_35 ;
V_20 = ( * V_30 & 0x200 ) ? 8 : 6 ;
* V_30 = ( * V_30 & ~ 0x3ff ) | V_20 ;
return V_33 ;
}
static unsigned int F_15 ( struct V_28 * V_29 , T_2 * V_30 )
{
unsigned int V_20 , V_33 ;
V_33 = V_36 ;
V_20 = ( * V_30 & 0x200 ) ? 24 : 16 ;
* V_30 = ( * V_30 & ~ 0x3ff ) | V_20 ;
return V_33 ;
}
static inline void F_16 ( void T_1 * V_1 , unsigned char * V_37 , int V_38 )
{
#ifndef F_17
int V_3 ;
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ )
V_37 [ V_3 ] = F_5 ( V_1 , V_39 + V_3 ) ;
#else
F_18 ( V_37 , V_1 + V_40 , V_38 ) ;
#endif
}
static inline void F_19 ( void T_1 * V_1 , unsigned char * V_37 , int V_38 )
{
#ifndef F_17
int V_3 ;
for ( V_3 = 0 ; V_3 < V_38 ; V_3 ++ )
F_2 ( V_37 [ V_3 ] , V_1 , V_39 + V_3 ) ;
#else
F_20 ( V_1 + V_40 , V_37 , V_38 ) ;
#endif
}
static int F_21 ( struct V_17 * V_18 , int floor , int V_26 )
{
int V_41 , V_42 , V_3 , V_43 ;
volatile char V_44 ;
void T_1 * V_1 = V_18 -> V_23 ;
F_11 ( V_1 , floor ) ;
F_10 ( V_1 , V_26 ) ;
F_2 ( ( V_45 | V_46 ) , V_1 , V_47 ) ;
F_8 ( V_1 , V_48 , 0 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_49 , 0 ) ;
F_9 ( V_18 , 1 , 0x00 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_6 ) ;
F_6 ( V_1 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
V_41 = F_5 ( V_1 , V_39 ) ;
if ( V_18 -> V_24 )
V_44 = F_5 ( V_1 , V_39 ) ;
V_42 = F_5 ( V_1 , V_39 ) ;
if ( V_18 -> V_24 )
V_44 = F_5 ( V_1 , V_39 ) ;
V_44 = F_5 ( V_1 , V_51 ) ;
V_44 = F_5 ( V_1 , V_51 ) ;
F_2 ( 0 , V_1 , V_47 ) ;
if ( V_41 == 0xff || V_41 == 0 )
return 0 ;
for ( V_3 = 0 ; V_52 [ V_3 ] . V_53 != NULL ; V_3 ++ ) {
if ( V_42 == V_52 [ V_3 ] . V_42 ) {
for ( V_43 = 0 ; V_54 [ V_43 ] . V_42 != 0x0 ; V_43 ++ ) {
if ( V_54 [ V_43 ] . V_42 == V_41 )
break;
}
F_22 ( V_55 L_3
L_4 , V_41 , V_42 ,
V_54 [ V_43 ] . V_53 , V_52 [ V_3 ] . V_53 ) ;
V_18 -> V_41 = V_41 ;
V_18 -> V_42 = V_42 ;
V_18 -> V_56 = F_23 ( ( V_52 [ V_3 ] . V_57 << 20 ) ) - 1 ;
V_18 -> V_58 = V_52 [ V_3 ] . V_58 << V_18 -> V_24 ;
break;
}
}
if ( V_52 [ V_3 ] . V_53 == NULL )
return 0 ;
return 1 ;
}
static void F_24 ( struct V_17 * V_31 )
{
int floor , V_26 ;
int V_59 [ V_60 ] ;
int V_8 ;
V_31 -> V_59 = 0 ;
V_31 -> V_41 = 0 ;
V_31 -> V_42 = 0 ;
V_31 -> V_24 = 0 ;
if ( V_31 -> V_61 == V_62 )
V_31 -> V_24 = 1 ;
if ( ( V_31 -> V_24 << 2 ) !=
( F_5 ( V_31 -> V_23 , V_63 ) & 4 ) ) {
T_3 V_64 = F_5 ( V_31 -> V_23 , V_63 ) ;
F_22 ( V_65 L_5 ,
V_31 -> V_24 ? L_6 : L_7 ) ;
V_64 ^= 4 ;
F_2 ( V_64 , V_31 -> V_23 , V_63 ) ;
}
for ( floor = 0 , V_8 = 1 ; floor < V_60 ; floor ++ ) {
V_59 [ floor ] = 0 ;
for ( V_26 = 0 ; V_26 < V_66 && V_8 != 0 ; V_26 ++ ) {
V_8 = F_21 ( V_31 , floor , V_26 ) ;
if ( V_8 ) {
V_59 [ floor ] ++ ;
V_31 -> V_59 ++ ;
}
}
}
if ( ! V_31 -> V_59 ) {
F_22 ( L_8 ) ;
return;
}
V_31 -> V_67 = F_25 ( sizeof( struct V_68 ) * V_31 -> V_59 , V_69 ) ;
if ( ! V_31 -> V_67 ) {
F_22 ( L_9 ) ;
return;
}
for ( floor = 0 , V_8 = 0 ; floor < V_60 ; floor ++ ) {
for ( V_26 = 0 ; V_26 < V_59 [ floor ] ; V_26 ++ ) {
V_31 -> V_67 [ V_8 ] . floor = floor ;
V_31 -> V_67 [ V_8 ] . V_26 = V_26 ;
V_31 -> V_67 [ V_8 ] . V_70 = 0 ;
V_31 -> V_67 [ V_8 ] . V_71 = 0x50 ;
V_8 ++ ;
}
}
V_31 -> V_72 = V_31 -> V_59 * ( 1 << V_31 -> V_56 ) ;
F_22 ( V_55 L_10 ,
V_31 -> V_59 , V_31 -> V_72 >> 20 ) ;
}
static int F_26 ( struct V_17 * V_73 , struct V_17 * V_74 )
{
int V_75 , V_76 , V_77 ;
if ( V_73 -> V_78 == V_74 -> V_78 )
return 1 ;
V_75 = F_5 ( V_73 -> V_23 , V_79 ) ;
V_76 = F_5 ( V_74 -> V_23 , V_79 ) ;
if ( V_75 != V_76 )
return 0 ;
F_2 ( ( V_75 + 1 ) % 0xff , V_73 -> V_23 , V_79 ) ;
V_76 = F_5 ( V_74 -> V_23 , V_79 ) ;
if ( V_76 == ( V_75 + 1 ) % 0xff )
V_77 = 1 ;
else
V_77 = 0 ;
F_2 ( V_75 , V_73 -> V_23 , V_79 ) ;
return V_77 ;
}
void F_27 ( struct V_28 * V_29 )
{
struct V_17 * V_31 = V_29 -> V_32 ;
struct V_17 * V_80 = NULL ;
if ( V_81 )
V_80 = V_81 -> V_32 ;
while ( V_80 ) {
if ( F_26 ( V_31 , V_80 ) ) {
F_22 ( V_65 L_11
L_12 ,
V_31 -> V_78 ) ;
F_28 ( V_31 -> V_23 ) ;
F_29 ( V_29 ) ;
return;
}
if ( V_80 -> V_82 )
V_80 = V_80 -> V_82 -> V_32 ;
else
V_80 = NULL ;
}
V_29 -> V_53 = L_13 ;
F_22 ( V_65 L_14
L_15 , V_31 -> V_78 ) ;
V_29 -> type = V_83 ;
V_29 -> V_84 = V_85 ;
V_29 -> V_86 = 0 ;
V_29 -> V_58 = 0 ;
V_29 -> V_87 = 512 ;
V_29 -> V_88 = 16 ;
V_29 -> V_89 = V_90 ;
V_29 -> V_91 = V_92 ;
V_29 -> V_93 = NULL ;
V_29 -> V_94 = NULL ;
V_29 -> V_95 = V_96 ;
V_29 -> V_97 = V_98 ;
V_29 -> V_99 = V_100 ;
V_29 -> V_101 = V_102 ;
V_29 -> V_103 = NULL ;
V_31 -> V_72 = 0 ;
V_31 -> V_59 = 0 ;
V_31 -> V_104 = - 1 ;
V_31 -> V_105 = - 1 ;
F_24 ( V_31 ) ;
if ( ! V_31 -> V_72 ) {
F_29 ( V_29 ) ;
F_28 ( V_31 -> V_23 ) ;
} else {
V_31 -> V_82 = V_81 ;
V_81 = V_29 ;
V_29 -> V_86 = V_31 -> V_72 ;
V_29 -> V_58 = V_31 -> V_58 ;
F_30 ( V_29 , NULL , 0 ) ;
return;
}
}
static int V_96 ( struct V_28 * V_29 , T_2 V_30 , T_4 V_38 ,
T_4 * V_106 , T_3 * V_37 )
{
int V_8 , V_3 ;
volatile char V_44 ;
T_2 V_107 ;
unsigned char V_108 [ 6 ] , V_109 [ 6 ] ;
struct V_17 * V_31 = V_29 -> V_32 ;
void T_1 * V_1 = V_31 -> V_23 ;
struct V_68 * V_110 = & V_31 -> V_67 [ V_30 >> ( V_31 -> V_56 ) ] ;
if ( V_30 >= V_31 -> V_72 )
return - V_111 ;
if ( V_30 + V_38 > ( ( V_30 | 0x1ff ) + 1 ) )
V_38 = ( ( V_30 | 0x1ff ) + 1 ) - V_30 ;
F_7 ( V_1 ) ;
if ( V_31 -> V_104 != V_110 -> floor ) {
F_11 ( V_1 , V_110 -> floor ) ;
F_10 ( V_1 , V_110 -> V_26 ) ;
} else if ( V_31 -> V_105 != V_110 -> V_26 ) {
F_10 ( V_1 , V_110 -> V_26 ) ;
}
V_31 -> V_104 = V_110 -> floor ;
V_31 -> V_105 = V_110 -> V_26 ;
F_2 ( ( V_45 | V_46 ) , V_1 , V_47 ) ;
F_8 ( V_1 , V_48 , 0 ) ;
F_6 ( V_1 ) ;
V_107 = V_30 ;
F_8 ( V_1 , F_12 ( V_29 , & V_107 ) , 0 ) ;
F_9 ( V_31 , 3 , V_107 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_6 ) ;
F_6 ( V_1 ) ;
F_2 ( V_112 , V_1 , V_113 ) ;
F_2 ( V_114 , V_1 , V_113 ) ;
* V_106 = V_38 ;
V_8 = 0 ;
F_5 ( V_1 , V_50 ) ;
F_5 ( V_1 , V_50 ) ;
F_16 ( V_1 , V_37 , V_38 ) ;
F_16 ( V_1 , V_109 , 4 ) ;
V_109 [ 4 ] = F_5 ( V_1 , V_51 ) ;
V_109 [ 5 ] = F_5 ( V_1 , V_51 ) ;
V_44 = F_5 ( V_1 , V_113 ) ;
V_44 = F_5 ( V_1 , V_113 ) ;
if ( F_5 ( V_1 , V_113 ) & 0x80 ) {
int V_115 ;
#ifdef F_31
F_22 ( L_16 , ( long ) V_30 ) ;
#endif
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_108 [ V_3 ] = F_5 ( V_1 , V_116 + V_3 ) ;
V_115 = F_32 ( V_37 , V_108 ) ;
#ifdef F_31
F_22 ( L_17 , V_115 ) ;
#endif
if ( V_115 < 0 ) {
#ifdef F_31
F_22 ( L_18 ,
__FILE__ , __LINE__ , ( int ) V_30 ) ;
F_22 ( L_19
L_20 ,
V_108 [ 0 ] , V_108 [ 1 ] , V_108 [ 2 ] ,
V_108 [ 3 ] , V_108 [ 4 ] , V_108 [ 5 ] ) ;
F_22 ( L_21
L_20 ,
V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] ,
V_109 [ 3 ] , V_109 [ 4 ] , V_109 [ 5 ] ) ;
#endif
V_8 = - V_117 ;
}
}
#ifdef F_33
F_22 ( L_22 ,
( long ) V_30 , V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] , V_109 [ 3 ] ,
V_109 [ 4 ] , V_109 [ 5 ] ) ;
#endif
F_2 ( V_118 , V_1 , V_113 ) ;
F_2 ( 0 , V_1 , V_47 ) ;
return V_8 ;
}
static int V_98 ( struct V_28 * V_29 , T_2 V_119 , T_4 V_38 ,
T_4 * V_106 , const T_3 * V_37 )
{
int V_3 , V_120 , V_8 = 0 ;
T_2 V_121 ;
volatile char V_44 ;
char V_109 [ 6 ] ;
struct V_17 * V_31 = V_29 -> V_32 ;
void T_1 * V_1 = V_31 -> V_23 ;
struct V_68 * V_110 = & V_31 -> V_67 [ V_119 >> ( V_31 -> V_56 ) ] ;
if ( V_119 >= V_31 -> V_72 )
return - V_111 ;
if ( ( V_119 & 0x1ff ) || ( V_38 != 0x200 ) )
return - V_111 ;
V_120 = ( V_31 -> V_24 && ( V_119 & 0x200 ) ) ;
F_7 ( V_1 ) ;
if ( V_31 -> V_104 != V_110 -> floor ) {
F_11 ( V_1 , V_110 -> floor ) ;
F_10 ( V_1 , V_110 -> V_26 ) ;
} else if ( V_31 -> V_105 != V_110 -> V_26 ) {
F_10 ( V_1 , V_110 -> V_26 ) ;
}
V_31 -> V_104 = V_110 -> floor ;
V_31 -> V_105 = V_110 -> V_26 ;
F_2 ( V_45 , V_1 , V_47 ) ;
F_8 ( V_1 , V_48 , 0 ) ;
F_6 ( V_1 ) ;
V_121 = V_119 ;
F_2 ( F_12 ( V_29 , & V_121 ) , V_1 , V_15 ) ;
if ( V_120 )
V_121 -= 2 ;
F_8 ( V_1 , V_122 , 0x00 ) ;
F_9 ( V_31 , 3 , V_121 , 0x00 , 0x00 ) ;
F_2 ( V_112 , V_1 , V_113 ) ;
if ( V_120 ) {
F_2 ( 0x55 , V_1 , V_39 ) ;
F_2 ( 0x55 , V_1 , V_39 ) ;
}
F_2 ( V_114 | V_123 , V_1 , V_113 ) ;
F_19 ( V_1 , ( unsigned char * ) V_37 , V_38 ) ;
F_1 ( V_1 , 3 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_109 [ V_3 ] = F_5 ( V_1 , V_116 + V_3 ) ;
F_2 ( V_118 , V_1 , V_113 ) ;
F_19 ( V_1 , V_109 , 6 ) ;
if ( ! V_120 ) {
F_2 ( 0x55 , V_1 , V_39 + 6 ) ;
F_2 ( 0x55 , V_1 , V_39 + 7 ) ;
}
#ifdef F_33
F_22 ( L_23 ,
( long ) V_119 , V_109 [ 0 ] , V_109 [ 1 ] , V_109 [ 2 ] , V_109 [ 3 ] ,
V_109 [ 4 ] , V_109 [ 5 ] ) ;
#endif
F_2 ( 0x00 , V_1 , V_16 ) ;
F_2 ( 0x00 , V_1 , V_16 ) ;
F_8 ( V_1 , V_124 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_125 , 0 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
F_1 ( V_1 , 2 ) ;
if ( ( V_44 = F_5 ( V_1 , V_51 ) ) & 1 ) {
F_22 ( L_24 , V_44 , ( int ) V_119 ) ;
* V_106 = 0 ;
V_8 = - V_117 ;
}
V_44 = F_5 ( V_1 , V_51 ) ;
F_2 ( 0 , V_1 , V_47 ) ;
* V_106 = V_38 ;
return V_8 ;
}
static int V_100 ( struct V_28 * V_29 , T_2 V_20 ,
struct V_126 * V_127 )
{
T_2 V_107 , V_128 ;
struct V_17 * V_31 = V_29 -> V_32 ;
void T_1 * V_1 = V_31 -> V_23 ;
struct V_68 * V_110 = & V_31 -> V_67 [ V_20 >> V_31 -> V_56 ] ;
T_4 V_3 , V_86 , V_129 , V_130 ;
T_5 * V_37 = V_127 -> V_131 ;
T_4 V_38 = V_127 -> V_38 ;
F_34 ( V_127 -> V_132 != V_133 ) ;
V_20 += V_127 -> V_134 ;
F_7 ( V_1 ) ;
if ( V_31 -> V_104 != V_110 -> floor ) {
F_11 ( V_1 , V_110 -> floor ) ;
F_10 ( V_1 , V_110 -> V_26 ) ;
} else if ( V_31 -> V_105 != V_110 -> V_26 ) {
F_10 ( V_1 , V_110 -> V_26 ) ;
}
V_31 -> V_104 = V_110 -> floor ;
V_31 -> V_105 = V_110 -> V_26 ;
F_2 ( ( V_45 | V_46 ) , V_1 , V_47 ) ;
F_2 ( V_112 , V_1 , V_113 ) ;
F_6 ( V_1 ) ;
if ( V_38 > 16 )
V_38 = 16 ;
V_129 = 0 ;
V_130 = V_38 ;
for ( V_3 = 0 ; ( ( V_3 < 3 ) && ( V_130 > 0 ) ) ; V_3 ++ ) {
V_107 = V_20 ;
V_128 = V_20 & 0xf ;
if ( ! V_31 -> V_24 ) {
F_8 ( V_1 , V_36 , 0 ) ;
V_86 = 16 - V_128 ;
} else if ( V_128 < 6 ) {
F_8 ( V_1 , F_13 ( V_29 , & V_107 ) , 0 ) ;
V_86 = 6 - V_128 ;
} else if ( V_128 < 8 ) {
F_8 ( V_1 , F_14 ( V_29 , & V_107 ) , 0 ) ;
V_86 = 8 - V_128 ;
} else {
F_8 ( V_1 , F_15 ( V_29 , & V_107 ) , 0 ) ;
V_86 = 16 - V_128 ;
}
if ( V_86 > V_130 )
V_86 = V_130 ;
F_9 ( V_31 , 3 , V_107 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_6 ) ;
F_6 ( V_1 ) ;
F_5 ( V_1 , V_50 ) ;
F_5 ( V_1 , V_50 ) ;
F_16 ( V_1 , & V_37 [ V_129 ] , V_86 - 2 ) ;
V_37 [ V_129 + V_86 - 2 ] = F_5 ( V_1 , V_51 ) ;
V_37 [ V_129 + V_86 - 1 ] = F_5 ( V_1 , V_51 ) ;
V_20 += V_86 ;
V_129 += V_86 ;
V_130 -= V_86 ;
}
F_2 ( 0 , V_1 , V_47 ) ;
V_127 -> V_106 = V_38 ;
return 0 ;
}
static int V_102 ( struct V_28 * V_29 , T_2 V_20 ,
struct V_126 * V_127 )
{
volatile char V_44 ;
T_2 V_107 , V_128 ;
struct V_17 * V_31 = V_29 -> V_32 ;
void T_1 * V_1 = V_31 -> V_23 ;
struct V_68 * V_110 = & V_31 -> V_67 [ V_20 >> V_31 -> V_56 ] ;
T_4 V_3 , V_86 , V_129 , V_130 ;
int V_8 = 0 ;
T_5 * V_37 = V_127 -> V_131 ;
T_4 V_38 = V_127 -> V_38 ;
F_34 ( V_127 -> V_132 != V_133 ) ;
V_20 += V_127 -> V_134 ;
F_7 ( V_1 ) ;
if ( V_31 -> V_104 != V_110 -> floor ) {
F_11 ( V_1 , V_110 -> floor ) ;
F_10 ( V_1 , V_110 -> V_26 ) ;
} else if ( V_31 -> V_105 != V_110 -> V_26 ) {
F_10 ( V_1 , V_110 -> V_26 ) ;
}
V_31 -> V_104 = V_110 -> floor ;
V_31 -> V_105 = V_110 -> V_26 ;
F_2 ( V_45 , V_1 , V_47 ) ;
if ( V_38 > 16 )
V_38 = 16 ;
V_129 = 0 ;
V_130 = V_38 ;
for ( V_3 = 0 ; ( ( V_3 < 3 ) && ( V_130 > 0 ) ) ; V_3 ++ ) {
F_8 ( V_1 , V_48 , 0 ) ;
F_6 ( V_1 ) ;
V_107 = V_20 ;
V_128 = V_20 & 0x0f ;
if ( ! V_31 -> V_24 ) {
F_2 ( V_36 , V_1 , V_15 ) ;
V_86 = 16 - V_128 ;
} else if ( V_128 < 6 ) {
F_2 ( F_13 ( V_29 , & V_107 ) , V_1 , V_15 ) ;
V_86 = 6 - V_128 ;
} else if ( V_128 < 8 ) {
F_2 ( F_14 ( V_29 , & V_107 ) , V_1 , V_15 ) ;
V_86 = 8 - V_128 ;
} else {
F_2 ( F_15 ( V_29 , & V_107 ) , V_1 , V_15 ) ;
V_86 = 16 - V_128 ;
}
if ( V_86 > V_130 )
V_86 = V_130 ;
F_8 ( V_1 , V_122 , 0x00 ) ;
F_9 ( V_31 , 3 , V_107 , 0 , 0x00 ) ;
F_2 ( V_112 , V_1 , V_113 ) ;
F_19 ( V_1 , ( unsigned char * ) & V_37 [ V_129 ] , V_86 ) ;
F_2 ( 0x00 , V_1 , V_16 ) ;
F_2 ( 0x00 , V_1 , V_16 ) ;
F_8 ( V_1 , V_124 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_125 , 0x00 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
F_1 ( V_1 , 2 ) ;
if ( ( V_44 = F_5 ( V_1 , V_51 ) ) & 1 ) {
F_22 ( L_25 ,
V_44 , ( int ) V_20 ) ;
V_127 -> V_106 = 0 ;
V_8 = - V_117 ;
}
V_44 = F_5 ( V_1 , V_51 ) ;
V_20 += V_86 ;
V_129 += V_86 ;
V_130 -= V_86 ;
}
F_2 ( 0 , V_1 , V_47 ) ;
V_127 -> V_106 = V_38 ;
return V_8 ;
}
int V_92 ( struct V_28 * V_29 , struct V_135 * V_136 )
{
volatile char V_44 ;
struct V_17 * V_31 = V_29 -> V_32 ;
T_6 V_20 = V_136 -> V_137 ;
T_6 V_38 = V_136 -> V_38 ;
void T_1 * V_1 = V_31 -> V_23 ;
struct V_68 * V_110 = & V_31 -> V_67 [ V_20 >> V_31 -> V_56 ] ;
F_7 ( V_1 ) ;
if ( V_38 != V_29 -> V_58 )
F_22 ( V_138 L_26 ,
V_38 , V_29 -> V_58 ) ;
if ( V_31 -> V_104 != V_110 -> floor ) {
F_11 ( V_1 , V_110 -> floor ) ;
F_10 ( V_1 , V_110 -> V_26 ) ;
} else if ( V_31 -> V_105 != V_110 -> V_26 ) {
F_10 ( V_1 , V_110 -> V_26 ) ;
}
V_31 -> V_104 = V_110 -> floor ;
V_31 -> V_105 = V_110 -> V_26 ;
V_136 -> V_139 = V_140 ;
F_2 ( V_45 , V_1 , V_47 ) ;
F_8 ( V_1 , V_48 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_141 , 0 ) ;
F_9 ( V_31 , 2 , V_20 , 0 , 0x00 ) ;
F_8 ( V_1 , V_142 , 0 ) ;
F_6 ( V_1 ) ;
V_136 -> V_139 = V_143 ;
F_8 ( V_1 , V_125 , 0 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
V_44 = F_5 ( V_1 , V_50 ) ;
if ( ( V_44 = F_5 ( V_1 , V_51 ) ) & 1 ) {
F_22 ( L_27 , V_44 , V_20 ) ;
V_136 -> V_139 = V_144 ;
} else {
V_136 -> V_139 = V_145 ;
}
V_44 = F_5 ( V_1 , V_51 ) ;
F_2 ( 0 , V_1 , V_47 ) ;
F_35 ( V_136 ) ;
return 0 ;
}
static void T_7 F_36 ( void )
{
struct V_28 * V_29 ;
struct V_17 * V_31 ;
while ( ( V_29 = V_81 ) ) {
V_31 = V_29 -> V_32 ;
V_81 = V_31 -> V_82 ;
F_37 ( V_29 ) ;
F_28 ( V_31 -> V_23 ) ;
F_29 ( V_31 -> V_67 ) ;
F_29 ( V_29 ) ;
}
}
