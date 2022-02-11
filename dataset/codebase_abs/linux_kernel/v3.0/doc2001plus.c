static void F_1 ( void T_1 * V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; ( V_3 < V_2 ) ; V_3 ++ )
F_2 ( 0 , V_1 , V_4 ) ;
}
static int F_3 ( void T_1 * V_1 )
{
unsigned int V_5 = 0xffff ;
F_4 ( V_6 ,
L_1 ) ;
while ( ( ( F_5 ( V_1 , V_7 ) & V_8 ) != V_8 ) && -- V_5 )
;
if ( V_5 == 0 )
F_4 ( V_9 , L_2 ) ;
return ( V_5 == 0 ) ;
}
static inline int F_6 ( void T_1 * V_1 )
{
int V_10 = 0 ;
F_1 ( V_1 , 4 ) ;
if ( ( F_5 ( V_1 , V_7 ) & V_8 ) != V_8 )
V_10 = F_3 ( V_1 ) ;
return V_10 ;
}
static inline void F_7 ( void T_1 * V_1 )
{
if ( ( F_5 ( V_1 , V_11 ) & V_12 ) == 0 ) {
F_2 ( ( V_12 | V_13 ) , V_1 , V_11 ) ;
F_2 ( ~ ( V_12 | V_13 ) , V_1 , V_14 ) ;
}
}
static void F_8 ( void T_1 * V_1 , unsigned char V_15 ,
unsigned char V_16 )
{
F_2 ( V_15 , V_1 , V_17 ) ;
F_2 ( V_15 , V_1 , V_18 ) ;
F_2 ( V_15 , V_1 , V_18 ) ;
}
static inline void F_9 ( struct V_19 * V_20 , int V_21 ,
unsigned long V_22 , unsigned char V_23 ,
unsigned char V_24 )
{
void T_1 * V_1 = V_20 -> V_25 ;
V_22 >>= V_20 -> V_26 ;
switch ( V_21 ) {
case 1 :
F_2 ( V_22 & 0xff , V_1 , V_27 ) ;
break;
case 2 :
F_2 ( ( V_22 >> 9 ) & 0xff , V_1 , V_27 ) ;
F_2 ( ( V_22 >> 17 ) & 0xff , V_1 , V_27 ) ;
break;
case 3 :
F_2 ( V_22 & 0xff , V_1 , V_27 ) ;
F_2 ( ( V_22 >> 9 ) & 0xff , V_1 , V_27 ) ;
F_2 ( ( V_22 >> 17 ) & 0xff , V_1 , V_27 ) ;
break;
default:
return;
}
F_2 ( 0x00 , V_1 , V_18 ) ;
F_2 ( 0x00 , V_1 , V_18 ) ;
}
static int F_10 ( void T_1 * V_1 , int V_28 )
{
return 0 ;
}
static int F_11 ( void T_1 * V_1 , int floor )
{
F_2 ( ( floor & 0x3 ) , V_1 , V_29 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_30 * V_31 , T_2 * V_32 )
{
struct V_19 * V_33 = V_31 -> V_34 ;
if ( V_33 -> V_26 ) {
unsigned int V_22 = * V_32 & 0x3ff ;
unsigned int V_35 ;
if ( V_22 < 512 ) {
V_35 = V_36 ;
V_22 &= 0x1ff ;
} else if ( V_22 < 1014 ) {
V_35 = V_37 ;
V_22 = ( V_22 & 0x1ff ) + 10 ;
} else {
V_35 = V_38 ;
V_22 = V_22 - 1014 ;
}
* V_32 = ( * V_32 & ~ 0x3ff ) | V_22 ;
return V_35 ;
} else {
if ( ( * V_32 ) & 0x100 )
return V_37 ;
return V_36 ;
}
}
static unsigned int F_13 ( struct V_30 * V_31 , T_2 * V_32 )
{
unsigned int V_22 , V_35 ;
if ( * V_32 & 0x200 ) {
V_35 = V_38 ;
V_22 = 10 + ( * V_32 & 0xf ) ;
} else {
V_35 = V_37 ;
V_22 = ( * V_32 & 0xf ) ;
}
* V_32 = ( * V_32 & ~ 0x3ff ) | V_22 ;
return V_35 ;
}
static unsigned int F_14 ( struct V_30 * V_31 , T_2 * V_32 )
{
unsigned int V_22 , V_35 ;
V_35 = V_37 ;
V_22 = ( * V_32 & 0x200 ) ? 8 : 6 ;
* V_32 = ( * V_32 & ~ 0x3ff ) | V_22 ;
return V_35 ;
}
static unsigned int F_15 ( struct V_30 * V_31 , T_2 * V_32 )
{
unsigned int V_22 , V_35 ;
V_35 = V_38 ;
V_22 = ( * V_32 & 0x200 ) ? 24 : 16 ;
* V_32 = ( * V_32 & ~ 0x3ff ) | V_22 ;
return V_35 ;
}
static inline void F_16 ( void T_1 * V_1 , unsigned char * V_39 , int V_40 )
{
#ifndef F_17
int V_3 ;
for ( V_3 = 0 ; V_3 < V_40 ; V_3 ++ )
V_39 [ V_3 ] = F_5 ( V_1 , V_41 + V_3 ) ;
#else
F_18 ( V_39 , V_1 + V_42 , V_40 ) ;
#endif
}
static inline void F_19 ( void T_1 * V_1 , unsigned char * V_39 , int V_40 )
{
#ifndef F_17
int V_3 ;
for ( V_3 = 0 ; V_3 < V_40 ; V_3 ++ )
F_2 ( V_39 [ V_3 ] , V_1 , V_41 + V_3 ) ;
#else
F_20 ( V_1 + V_42 , V_39 , V_40 ) ;
#endif
}
static int F_21 ( struct V_19 * V_20 , int floor , int V_28 )
{
int V_43 , V_44 , V_3 , V_45 ;
volatile char V_46 ;
void T_1 * V_1 = V_20 -> V_25 ;
F_11 ( V_1 , floor ) ;
F_10 ( V_1 , V_28 ) ;
F_2 ( ( V_47 | V_48 ) , V_1 , V_49 ) ;
F_8 ( V_1 , V_50 , 0 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_51 , 0 ) ;
F_9 ( V_20 , 1 , 0x00 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_7 ) ;
F_6 ( V_1 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
V_43 = F_5 ( V_1 , V_41 ) ;
if ( V_20 -> V_26 )
V_46 = F_5 ( V_1 , V_41 ) ;
V_44 = F_5 ( V_1 , V_41 ) ;
if ( V_20 -> V_26 )
V_46 = F_5 ( V_1 , V_41 ) ;
V_46 = F_5 ( V_1 , V_53 ) ;
V_46 = F_5 ( V_1 , V_53 ) ;
F_2 ( 0 , V_1 , V_49 ) ;
if ( V_43 == 0xff || V_43 == 0 )
return 0 ;
for ( V_3 = 0 ; V_54 [ V_3 ] . V_55 != NULL ; V_3 ++ ) {
if ( V_44 == V_54 [ V_3 ] . V_44 ) {
for ( V_45 = 0 ; V_56 [ V_45 ] . V_44 != 0x0 ; V_45 ++ ) {
if ( V_56 [ V_45 ] . V_44 == V_43 )
break;
}
F_22 ( V_57 L_3
L_4 , V_43 , V_44 ,
V_56 [ V_45 ] . V_55 , V_54 [ V_3 ] . V_55 ) ;
V_20 -> V_43 = V_43 ;
V_20 -> V_44 = V_44 ;
V_20 -> V_58 = F_23 ( ( V_54 [ V_3 ] . V_59 << 20 ) ) - 1 ;
V_20 -> V_60 = V_54 [ V_3 ] . V_60 << V_20 -> V_26 ;
break;
}
}
if ( V_54 [ V_3 ] . V_55 == NULL )
return 0 ;
return 1 ;
}
static void F_24 ( struct V_19 * V_33 )
{
int floor , V_28 ;
int V_61 [ V_62 ] ;
int V_10 ;
V_33 -> V_61 = 0 ;
V_33 -> V_43 = 0 ;
V_33 -> V_44 = 0 ;
V_33 -> V_26 = 0 ;
if ( V_33 -> V_63 == V_64 )
V_33 -> V_26 = 1 ;
if ( ( V_33 -> V_26 << 2 ) !=
( F_5 ( V_33 -> V_25 , V_65 ) & 4 ) ) {
T_3 V_66 = F_5 ( V_33 -> V_25 , V_65 ) ;
F_22 ( V_67 L_5 ,
V_33 -> V_26 ? L_6 : L_7 ) ;
V_66 ^= 4 ;
F_2 ( V_66 , V_33 -> V_25 , V_65 ) ;
}
for ( floor = 0 , V_10 = 1 ; floor < V_62 ; floor ++ ) {
V_61 [ floor ] = 0 ;
for ( V_28 = 0 ; V_28 < V_68 && V_10 != 0 ; V_28 ++ ) {
V_10 = F_21 ( V_33 , floor , V_28 ) ;
if ( V_10 ) {
V_61 [ floor ] ++ ;
V_33 -> V_61 ++ ;
}
}
}
if ( ! V_33 -> V_61 ) {
F_22 ( L_8 ) ;
return;
}
V_33 -> V_69 = F_25 ( sizeof( struct V_70 ) * V_33 -> V_61 , V_71 ) ;
if ( ! V_33 -> V_69 ) {
F_22 ( L_9 ) ;
return;
}
for ( floor = 0 , V_10 = 0 ; floor < V_62 ; floor ++ ) {
for ( V_28 = 0 ; V_28 < V_61 [ floor ] ; V_28 ++ ) {
V_33 -> V_69 [ V_10 ] . floor = floor ;
V_33 -> V_69 [ V_10 ] . V_28 = V_28 ;
V_33 -> V_69 [ V_10 ] . V_72 = 0 ;
V_33 -> V_69 [ V_10 ] . V_73 = 0x50 ;
V_10 ++ ;
}
}
V_33 -> V_74 = V_33 -> V_61 * ( 1 << V_33 -> V_58 ) ;
F_22 ( V_57 L_10 ,
V_33 -> V_61 , V_33 -> V_74 >> 20 ) ;
}
static int F_26 ( struct V_19 * V_75 , struct V_19 * V_76 )
{
int V_77 , V_78 , V_79 ;
if ( V_75 -> V_80 == V_76 -> V_80 )
return 1 ;
V_77 = F_5 ( V_75 -> V_25 , V_81 ) ;
V_78 = F_5 ( V_76 -> V_25 , V_81 ) ;
if ( V_77 != V_78 )
return 0 ;
F_2 ( ( V_77 + 1 ) % 0xff , V_75 -> V_25 , V_81 ) ;
V_78 = F_5 ( V_76 -> V_25 , V_81 ) ;
if ( V_78 == ( V_77 + 1 ) % 0xff )
V_79 = 1 ;
else
V_79 = 0 ;
F_2 ( V_77 , V_75 -> V_25 , V_81 ) ;
return V_79 ;
}
void F_27 ( struct V_30 * V_31 )
{
struct V_19 * V_33 = V_31 -> V_34 ;
struct V_19 * V_82 = NULL ;
if ( V_83 )
V_82 = V_83 -> V_34 ;
while ( V_82 ) {
if ( F_26 ( V_33 , V_82 ) ) {
F_22 ( V_67 L_11
L_12 ,
V_33 -> V_80 ) ;
F_28 ( V_33 -> V_25 ) ;
F_29 ( V_31 ) ;
return;
}
if ( V_82 -> V_84 )
V_82 = V_82 -> V_84 -> V_34 ;
else
V_82 = NULL ;
}
V_31 -> V_55 = L_13 ;
F_22 ( V_67 L_14
L_15 , V_33 -> V_80 ) ;
V_31 -> type = V_85 ;
V_31 -> V_86 = V_87 ;
V_31 -> V_88 = 0 ;
V_31 -> V_60 = 0 ;
V_31 -> V_89 = 512 ;
V_31 -> V_90 = 16 ;
V_31 -> V_91 = V_92 ;
V_31 -> V_93 = V_94 ;
V_31 -> V_95 = NULL ;
V_31 -> V_96 = NULL ;
V_31 -> V_97 = V_98 ;
V_31 -> V_99 = V_100 ;
V_31 -> V_101 = V_102 ;
V_31 -> V_103 = V_104 ;
V_31 -> V_105 = NULL ;
V_33 -> V_74 = 0 ;
V_33 -> V_61 = 0 ;
V_33 -> V_106 = - 1 ;
V_33 -> V_107 = - 1 ;
F_24 ( V_33 ) ;
if ( ! V_33 -> V_74 ) {
F_29 ( V_31 ) ;
F_28 ( V_33 -> V_25 ) ;
} else {
V_33 -> V_84 = V_83 ;
V_83 = V_31 ;
V_31 -> V_88 = V_33 -> V_74 ;
V_31 -> V_60 = V_33 -> V_60 ;
F_30 ( V_31 , NULL , 0 ) ;
return;
}
}
static int V_98 ( struct V_30 * V_31 , T_2 V_32 , T_4 V_40 ,
T_4 * V_108 , T_3 * V_39 )
{
int V_10 , V_3 ;
volatile char V_46 ;
T_2 V_109 ;
unsigned char V_110 [ 6 ] , V_111 [ 6 ] ;
struct V_19 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 = V_33 -> V_25 ;
struct V_70 * V_112 = & V_33 -> V_69 [ V_32 >> ( V_33 -> V_58 ) ] ;
if ( V_32 >= V_33 -> V_74 )
return - V_113 ;
if ( V_32 + V_40 > ( ( V_32 | 0x1ff ) + 1 ) )
V_40 = ( ( V_32 | 0x1ff ) + 1 ) - V_32 ;
F_7 ( V_1 ) ;
if ( V_33 -> V_106 != V_112 -> floor ) {
F_11 ( V_1 , V_112 -> floor ) ;
F_10 ( V_1 , V_112 -> V_28 ) ;
} else if ( V_33 -> V_107 != V_112 -> V_28 ) {
F_10 ( V_1 , V_112 -> V_28 ) ;
}
V_33 -> V_106 = V_112 -> floor ;
V_33 -> V_107 = V_112 -> V_28 ;
F_2 ( ( V_47 | V_48 ) , V_1 , V_49 ) ;
F_8 ( V_1 , V_50 , 0 ) ;
F_6 ( V_1 ) ;
V_109 = V_32 ;
F_8 ( V_1 , F_12 ( V_31 , & V_109 ) , 0 ) ;
F_9 ( V_33 , 3 , V_109 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_7 ) ;
F_6 ( V_1 ) ;
F_2 ( V_114 , V_1 , V_115 ) ;
F_2 ( V_116 , V_1 , V_115 ) ;
* V_108 = V_40 ;
V_10 = 0 ;
F_5 ( V_1 , V_52 ) ;
F_5 ( V_1 , V_52 ) ;
F_16 ( V_1 , V_39 , V_40 ) ;
F_16 ( V_1 , V_111 , 4 ) ;
V_111 [ 4 ] = F_5 ( V_1 , V_53 ) ;
V_111 [ 5 ] = F_5 ( V_1 , V_53 ) ;
V_46 = F_5 ( V_1 , V_115 ) ;
V_46 = F_5 ( V_1 , V_115 ) ;
if ( F_5 ( V_1 , V_115 ) & 0x80 ) {
int V_117 ;
#ifdef F_31
F_22 ( L_16 , ( long ) V_32 ) ;
#endif
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_110 [ V_3 ] = F_5 ( V_1 , V_118 + V_3 ) ;
V_117 = F_32 ( V_39 , V_110 ) ;
#ifdef F_31
F_22 ( L_17 , V_117 ) ;
#endif
if ( V_117 < 0 ) {
#ifdef F_31
F_22 ( L_18 ,
__FILE__ , __LINE__ , ( int ) V_32 ) ;
F_22 ( L_19
L_20 ,
V_110 [ 0 ] , V_110 [ 1 ] , V_110 [ 2 ] ,
V_110 [ 3 ] , V_110 [ 4 ] , V_110 [ 5 ] ) ;
F_22 ( L_21
L_20 ,
V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] ,
V_111 [ 3 ] , V_111 [ 4 ] , V_111 [ 5 ] ) ;
#endif
V_10 = - V_119 ;
}
}
#ifdef F_33
F_22 ( L_22 ,
( long ) V_32 , V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] , V_111 [ 3 ] ,
V_111 [ 4 ] , V_111 [ 5 ] ) ;
#endif
F_2 ( V_120 , V_1 , V_115 ) ;
F_2 ( 0 , V_1 , V_49 ) ;
return V_10 ;
}
static int V_100 ( struct V_30 * V_31 , T_2 V_121 , T_4 V_40 ,
T_4 * V_108 , const T_3 * V_39 )
{
int V_3 , V_122 , V_10 = 0 ;
T_2 V_123 ;
volatile char V_46 ;
char V_111 [ 6 ] ;
struct V_19 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 = V_33 -> V_25 ;
struct V_70 * V_112 = & V_33 -> V_69 [ V_121 >> ( V_33 -> V_58 ) ] ;
if ( V_121 >= V_33 -> V_74 )
return - V_113 ;
if ( ( V_121 & 0x1ff ) || ( V_40 != 0x200 ) )
return - V_113 ;
V_122 = ( V_33 -> V_26 && ( V_121 & 0x200 ) ) ;
F_7 ( V_1 ) ;
if ( V_33 -> V_106 != V_112 -> floor ) {
F_11 ( V_1 , V_112 -> floor ) ;
F_10 ( V_1 , V_112 -> V_28 ) ;
} else if ( V_33 -> V_107 != V_112 -> V_28 ) {
F_10 ( V_1 , V_112 -> V_28 ) ;
}
V_33 -> V_106 = V_112 -> floor ;
V_33 -> V_107 = V_112 -> V_28 ;
F_2 ( V_47 , V_1 , V_49 ) ;
F_8 ( V_1 , V_50 , 0 ) ;
F_6 ( V_1 ) ;
V_123 = V_121 ;
F_2 ( F_12 ( V_31 , & V_123 ) , V_1 , V_17 ) ;
if ( V_122 )
V_123 -= 2 ;
F_8 ( V_1 , V_124 , 0x00 ) ;
F_9 ( V_33 , 3 , V_123 , 0x00 , 0x00 ) ;
F_2 ( V_114 , V_1 , V_115 ) ;
if ( V_122 ) {
F_2 ( 0x55 , V_1 , V_41 ) ;
F_2 ( 0x55 , V_1 , V_41 ) ;
}
F_2 ( V_116 | V_125 , V_1 , V_115 ) ;
F_19 ( V_1 , ( unsigned char * ) V_39 , V_40 ) ;
F_1 ( V_1 , 3 ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_111 [ V_3 ] = F_5 ( V_1 , V_118 + V_3 ) ;
F_2 ( V_120 , V_1 , V_115 ) ;
F_19 ( V_1 , V_111 , 6 ) ;
if ( ! V_122 ) {
F_2 ( 0x55 , V_1 , V_41 + 6 ) ;
F_2 ( 0x55 , V_1 , V_41 + 7 ) ;
}
#ifdef F_33
F_22 ( L_23 ,
( long ) V_121 , V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] , V_111 [ 3 ] ,
V_111 [ 4 ] , V_111 [ 5 ] ) ;
#endif
F_2 ( 0x00 , V_1 , V_18 ) ;
F_2 ( 0x00 , V_1 , V_18 ) ;
F_8 ( V_1 , V_126 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_127 , 0 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
F_1 ( V_1 , 2 ) ;
if ( ( V_46 = F_5 ( V_1 , V_53 ) ) & 1 ) {
F_22 ( L_24 , V_46 , ( int ) V_121 ) ;
* V_108 = 0 ;
V_10 = - V_119 ;
}
V_46 = F_5 ( V_1 , V_53 ) ;
F_2 ( 0 , V_1 , V_49 ) ;
* V_108 = V_40 ;
return V_10 ;
}
static int V_102 ( struct V_30 * V_31 , T_2 V_22 ,
struct V_128 * V_129 )
{
T_2 V_109 , V_130 ;
struct V_19 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 = V_33 -> V_25 ;
struct V_70 * V_112 = & V_33 -> V_69 [ V_22 >> V_33 -> V_58 ] ;
T_4 V_3 , V_88 , V_131 , V_132 ;
T_5 * V_39 = V_129 -> V_133 ;
T_4 V_40 = V_129 -> V_40 ;
F_34 ( V_129 -> V_134 != V_135 ) ;
V_22 += V_129 -> V_136 ;
F_7 ( V_1 ) ;
if ( V_33 -> V_106 != V_112 -> floor ) {
F_11 ( V_1 , V_112 -> floor ) ;
F_10 ( V_1 , V_112 -> V_28 ) ;
} else if ( V_33 -> V_107 != V_112 -> V_28 ) {
F_10 ( V_1 , V_112 -> V_28 ) ;
}
V_33 -> V_106 = V_112 -> floor ;
V_33 -> V_107 = V_112 -> V_28 ;
F_2 ( ( V_47 | V_48 ) , V_1 , V_49 ) ;
F_2 ( V_114 , V_1 , V_115 ) ;
F_6 ( V_1 ) ;
if ( V_40 > 16 )
V_40 = 16 ;
V_131 = 0 ;
V_132 = V_40 ;
for ( V_3 = 0 ; ( ( V_3 < 3 ) && ( V_132 > 0 ) ) ; V_3 ++ ) {
V_109 = V_22 ;
V_130 = V_22 & 0xf ;
if ( ! V_33 -> V_26 ) {
F_8 ( V_1 , V_38 , 0 ) ;
V_88 = 16 - V_130 ;
} else if ( V_130 < 6 ) {
F_8 ( V_1 , F_13 ( V_31 , & V_109 ) , 0 ) ;
V_88 = 6 - V_130 ;
} else if ( V_130 < 8 ) {
F_8 ( V_1 , F_14 ( V_31 , & V_109 ) , 0 ) ;
V_88 = 8 - V_130 ;
} else {
F_8 ( V_1 , F_15 ( V_31 , & V_109 ) , 0 ) ;
V_88 = 16 - V_130 ;
}
if ( V_88 > V_132 )
V_88 = V_132 ;
F_9 ( V_33 , 3 , V_109 , 0 , 0x00 ) ;
F_2 ( 0 , V_1 , V_7 ) ;
F_6 ( V_1 ) ;
F_5 ( V_1 , V_52 ) ;
F_5 ( V_1 , V_52 ) ;
F_16 ( V_1 , & V_39 [ V_131 ] , V_88 - 2 ) ;
V_39 [ V_131 + V_88 - 2 ] = F_5 ( V_1 , V_53 ) ;
V_39 [ V_131 + V_88 - 1 ] = F_5 ( V_1 , V_53 ) ;
V_22 += V_88 ;
V_131 += V_88 ;
V_132 -= V_88 ;
}
F_2 ( 0 , V_1 , V_49 ) ;
V_129 -> V_108 = V_40 ;
return 0 ;
}
static int V_104 ( struct V_30 * V_31 , T_2 V_22 ,
struct V_128 * V_129 )
{
volatile char V_46 ;
T_2 V_109 , V_130 ;
struct V_19 * V_33 = V_31 -> V_34 ;
void T_1 * V_1 = V_33 -> V_25 ;
struct V_70 * V_112 = & V_33 -> V_69 [ V_22 >> V_33 -> V_58 ] ;
T_4 V_3 , V_88 , V_131 , V_132 ;
int V_10 = 0 ;
T_5 * V_39 = V_129 -> V_133 ;
T_4 V_40 = V_129 -> V_40 ;
F_34 ( V_129 -> V_134 != V_135 ) ;
V_22 += V_129 -> V_136 ;
F_7 ( V_1 ) ;
if ( V_33 -> V_106 != V_112 -> floor ) {
F_11 ( V_1 , V_112 -> floor ) ;
F_10 ( V_1 , V_112 -> V_28 ) ;
} else if ( V_33 -> V_107 != V_112 -> V_28 ) {
F_10 ( V_1 , V_112 -> V_28 ) ;
}
V_33 -> V_106 = V_112 -> floor ;
V_33 -> V_107 = V_112 -> V_28 ;
F_2 ( V_47 , V_1 , V_49 ) ;
if ( V_40 > 16 )
V_40 = 16 ;
V_131 = 0 ;
V_132 = V_40 ;
for ( V_3 = 0 ; ( ( V_3 < 3 ) && ( V_132 > 0 ) ) ; V_3 ++ ) {
F_8 ( V_1 , V_50 , 0 ) ;
F_6 ( V_1 ) ;
V_109 = V_22 ;
V_130 = V_22 & 0x0f ;
if ( ! V_33 -> V_26 ) {
F_2 ( V_38 , V_1 , V_17 ) ;
V_88 = 16 - V_130 ;
} else if ( V_130 < 6 ) {
F_2 ( F_13 ( V_31 , & V_109 ) , V_1 , V_17 ) ;
V_88 = 6 - V_130 ;
} else if ( V_130 < 8 ) {
F_2 ( F_14 ( V_31 , & V_109 ) , V_1 , V_17 ) ;
V_88 = 8 - V_130 ;
} else {
F_2 ( F_15 ( V_31 , & V_109 ) , V_1 , V_17 ) ;
V_88 = 16 - V_130 ;
}
if ( V_88 > V_132 )
V_88 = V_132 ;
F_8 ( V_1 , V_124 , 0x00 ) ;
F_9 ( V_33 , 3 , V_109 , 0 , 0x00 ) ;
F_2 ( V_114 , V_1 , V_115 ) ;
F_19 ( V_1 , ( unsigned char * ) & V_39 [ V_131 ] , V_88 ) ;
F_2 ( 0x00 , V_1 , V_18 ) ;
F_2 ( 0x00 , V_1 , V_18 ) ;
F_8 ( V_1 , V_126 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_127 , 0x00 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
F_1 ( V_1 , 2 ) ;
if ( ( V_46 = F_5 ( V_1 , V_53 ) ) & 1 ) {
F_22 ( L_25 ,
V_46 , ( int ) V_22 ) ;
V_129 -> V_108 = 0 ;
V_10 = - V_119 ;
}
V_46 = F_5 ( V_1 , V_53 ) ;
V_22 += V_88 ;
V_131 += V_88 ;
V_132 -= V_88 ;
}
F_2 ( 0 , V_1 , V_49 ) ;
V_129 -> V_108 = V_40 ;
return V_10 ;
}
int V_94 ( struct V_30 * V_31 , struct V_137 * V_138 )
{
volatile char V_46 ;
struct V_19 * V_33 = V_31 -> V_34 ;
T_6 V_22 = V_138 -> V_139 ;
T_6 V_40 = V_138 -> V_40 ;
void T_1 * V_1 = V_33 -> V_25 ;
struct V_70 * V_112 = & V_33 -> V_69 [ V_22 >> V_33 -> V_58 ] ;
F_7 ( V_1 ) ;
if ( V_40 != V_31 -> V_60 )
F_22 ( V_140 L_26 ,
V_40 , V_31 -> V_60 ) ;
if ( V_33 -> V_106 != V_112 -> floor ) {
F_11 ( V_1 , V_112 -> floor ) ;
F_10 ( V_1 , V_112 -> V_28 ) ;
} else if ( V_33 -> V_107 != V_112 -> V_28 ) {
F_10 ( V_1 , V_112 -> V_28 ) ;
}
V_33 -> V_106 = V_112 -> floor ;
V_33 -> V_107 = V_112 -> V_28 ;
V_138 -> V_141 = V_142 ;
F_2 ( V_47 , V_1 , V_49 ) ;
F_8 ( V_1 , V_50 , 0x00 ) ;
F_6 ( V_1 ) ;
F_8 ( V_1 , V_143 , 0 ) ;
F_9 ( V_33 , 2 , V_22 , 0 , 0x00 ) ;
F_8 ( V_1 , V_144 , 0 ) ;
F_6 ( V_1 ) ;
V_138 -> V_141 = V_145 ;
F_8 ( V_1 , V_127 , 0 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
V_46 = F_5 ( V_1 , V_52 ) ;
if ( ( V_46 = F_5 ( V_1 , V_53 ) ) & 1 ) {
F_22 ( L_27 , V_46 , V_22 ) ;
V_138 -> V_141 = V_146 ;
} else {
V_138 -> V_141 = V_147 ;
}
V_46 = F_5 ( V_1 , V_53 ) ;
F_2 ( 0 , V_1 , V_49 ) ;
F_35 ( V_138 ) ;
return 0 ;
}
static void T_7 F_36 ( void )
{
struct V_30 * V_31 ;
struct V_19 * V_33 ;
while ( ( V_31 = V_83 ) ) {
V_33 = V_31 -> V_34 ;
V_83 = V_33 -> V_84 ;
F_37 ( V_31 ) ;
F_28 ( V_33 -> V_25 ) ;
F_29 ( V_33 -> V_69 ) ;
F_29 ( V_31 ) ;
}
}
