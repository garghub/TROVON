static void F_1 ( void T_1 * V_1 , unsigned short V_2 )
{
volatile char V_3 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ )
V_3 = F_2 ( V_1 , V_5 ) ;
}
static int F_3 ( void T_1 * V_1 )
{
unsigned short V_6 = 0xffff ;
F_4 ( L_1 ) ;
while ( ! ( F_2 ( V_1 , V_7 ) & V_8 ) && -- V_6 )
;
if ( V_6 == 0 )
F_4 ( L_2 ) ;
return ( V_6 == 0 ) ;
}
static inline int F_5 ( void T_1 * V_1 )
{
int V_9 = 0 ;
F_1 ( V_1 , 4 ) ;
if ( ! ( F_2 ( V_1 , V_7 ) & V_8 ) )
V_9 = F_3 ( V_1 ) ;
F_1 ( V_1 , 2 ) ;
return V_9 ;
}
static void F_6 ( void T_1 * V_1 , unsigned char V_10 ,
unsigned char V_11 )
{
F_7 ( V_11 | V_12 | V_13 , V_1 , V_7 ) ;
F_1 ( V_1 , 4 ) ;
F_7 ( V_10 , V_1 , V_14 ) ;
F_7 ( 0x00 , V_1 , V_15 ) ;
F_7 ( V_11 | V_13 , V_1 , V_7 ) ;
F_1 ( V_1 , 4 ) ;
}
static inline void F_8 ( void T_1 * V_1 , int V_16 , unsigned long V_17 ,
unsigned char V_18 , unsigned char V_19 )
{
F_7 ( V_18 | V_20 | V_13 , V_1 , V_7 ) ;
F_1 ( V_1 , 4 ) ;
switch ( V_16 )
{
case 1 :
F_7 ( V_17 & 0xff , V_1 , V_14 ) ;
F_7 ( 0x00 , V_1 , V_15 ) ;
break;
case 2 :
F_7 ( ( V_17 >> 9 ) & 0xff , V_1 , V_14 ) ;
F_7 ( ( V_17 >> 17 ) & 0xff , V_1 , V_14 ) ;
F_7 ( 0x00 , V_1 , V_15 ) ;
break;
case 3 :
F_7 ( V_17 & 0xff , V_1 , V_14 ) ;
F_7 ( ( V_17 >> 9 ) & 0xff , V_1 , V_14 ) ;
F_7 ( ( V_17 >> 17 ) & 0xff , V_1 , V_14 ) ;
F_7 ( 0x00 , V_1 , V_15 ) ;
break;
default:
return;
}
F_7 ( V_18 | V_19 | V_13 , V_1 , V_7 ) ;
F_1 ( V_1 , 4 ) ;
}
static int F_9 ( void T_1 * V_1 , int V_21 )
{
F_7 ( V_21 , V_1 , V_22 ) ;
F_1 ( V_1 , 4 ) ;
return F_5 ( V_1 ) ;
}
static int F_10 ( void T_1 * V_1 , int floor )
{
F_7 ( floor , V_1 , V_23 ) ;
return F_5 ( V_1 ) ;
}
static int F_11 ( struct V_24 * V_25 , int floor , int V_21 )
{
int V_26 , V_27 , V_4 , V_28 ;
volatile char V_3 ;
F_10 ( V_25 -> V_29 , floor ) ;
F_9 ( V_25 -> V_29 , V_21 ) ;
F_6 ( V_25 -> V_29 , V_30 , V_31 ) ;
F_5 ( V_25 -> V_29 ) ;
F_6 ( V_25 -> V_29 , V_32 , V_31 ) ;
F_8 ( V_25 -> V_29 , 1 , 0x00 , V_31 , 0x00 ) ;
V_3 = F_2 ( V_25 -> V_29 , V_33 ) ;
F_1 ( V_25 -> V_29 , 2 ) ;
V_26 = F_2 ( V_25 -> V_29 , V_14 ) ;
F_1 ( V_25 -> V_29 , 2 ) ;
V_27 = F_2 ( V_25 -> V_29 , V_14 ) ;
V_3 = F_2 ( V_25 -> V_29 , V_34 ) ;
if ( V_26 == 0xff || V_26 == 0 )
return 0 ;
for ( V_4 = 0 ; V_35 [ V_4 ] . V_36 != NULL ; V_4 ++ ) {
if ( V_27 == V_35 [ V_4 ] . V_27 ) {
for ( V_28 = 0 ; V_37 [ V_28 ] . V_27 != 0x0 ; V_28 ++ ) {
if ( V_37 [ V_28 ] . V_27 == V_26 )
break;
}
F_12 ( V_38 L_3
L_4 ,
V_26 , V_27 , V_37 [ V_28 ] . V_36 , V_35 [ V_4 ] . V_36 ) ;
V_25 -> V_26 = V_26 ;
V_25 -> V_27 = V_27 ;
V_25 -> V_39 = F_13 ( ( V_35 [ V_4 ] . V_40 << 20 ) ) - 1 ;
break;
}
}
if ( V_35 [ V_4 ] . V_36 == NULL )
return 0 ;
else
return 1 ;
}
static void F_14 ( struct V_24 * V_41 )
{
int floor , V_21 ;
int V_42 [ V_43 ] ;
int V_9 ;
V_41 -> V_42 = 0 ;
V_41 -> V_26 = 0 ;
V_41 -> V_27 = 0 ;
for ( floor = 0 , V_9 = 1 ; floor < V_43 ; floor ++ ) {
V_42 [ floor ] = 0 ;
for ( V_21 = 0 ; V_21 < V_44 && V_9 != 0 ; V_21 ++ ) {
V_9 = F_11 ( V_41 , floor , V_21 ) ;
if ( V_9 ) {
V_42 [ floor ] ++ ;
V_41 -> V_42 ++ ;
}
}
}
if ( ! V_41 -> V_42 ) {
F_12 ( L_5 ) ;
return;
}
V_41 -> V_45 = F_15 ( sizeof( struct V_46 ) * V_41 -> V_42 , V_47 ) ;
if ( ! V_41 -> V_45 ) {
F_12 ( L_6 ) ;
return;
}
for ( floor = 0 , V_9 = 0 ; floor < V_43 ; floor ++ ) {
for ( V_21 = 0 ; V_21 < V_42 [ floor ] ; V_21 ++ ) {
V_41 -> V_45 [ V_9 ] . floor = floor ;
V_41 -> V_45 [ V_9 ] . V_21 = V_21 ;
V_41 -> V_45 [ V_9 ] . V_48 = 0 ;
V_41 -> V_45 [ V_9 ] . V_49 = 0x50 ;
V_9 ++ ;
}
}
V_41 -> V_50 = V_41 -> V_42 * ( 1 << V_41 -> V_39 ) ;
F_12 ( V_38 L_7 ,
V_41 -> V_42 , V_41 -> V_50 >> 20 ) ;
}
static int F_16 ( struct V_24 * V_51 , struct V_24 * V_52 )
{
int V_53 , V_54 , V_55 ;
if ( V_51 -> V_56 == V_52 -> V_56 )
return 1 ;
V_53 = F_2 ( V_51 -> V_29 , V_57 ) ;
V_54 = F_2 ( V_52 -> V_29 , V_57 ) ;
if ( V_53 != V_54 )
return 0 ;
F_7 ( ( V_53 + 1 ) % 0xff , V_51 -> V_29 , V_57 ) ;
V_54 = F_2 ( V_52 -> V_29 , V_57 ) ;
if ( V_54 == ( V_53 + 1 ) % 0xff )
V_55 = 1 ;
else
V_55 = 0 ;
F_7 ( V_53 , V_51 -> V_29 , V_57 ) ;
return V_55 ;
}
void F_17 ( struct V_58 * V_59 )
{
struct V_24 * V_41 = V_59 -> V_60 ;
struct V_24 * V_61 = NULL ;
if ( V_62 )
V_61 = V_62 -> V_60 ;
while ( V_61 ) {
if ( F_16 ( V_41 , V_61 ) ) {
F_12 ( V_63 L_8
L_9 , V_41 -> V_56 ) ;
F_18 ( V_41 -> V_29 ) ;
F_19 ( V_59 ) ;
return;
}
if ( V_61 -> V_64 )
V_61 = V_61 -> V_64 -> V_60 ;
else
V_61 = NULL ;
}
V_59 -> V_36 = L_10 ;
F_12 ( V_63 L_11 ,
V_41 -> V_56 ) ;
V_59 -> type = V_65 ;
V_59 -> V_66 = V_67 ;
V_59 -> V_68 = 0 ;
V_59 -> V_69 = 0x2000 ;
V_59 -> V_70 = 512 ;
V_59 -> V_71 = 16 ;
V_59 -> V_72 = V_73 ;
V_59 -> V_74 = V_75 ;
V_59 -> V_76 = NULL ;
V_59 -> V_77 = NULL ;
V_59 -> V_78 = V_79 ;
V_59 -> V_80 = V_81 ;
V_59 -> V_82 = V_83 ;
V_59 -> V_84 = V_85 ;
V_59 -> V_86 = NULL ;
V_41 -> V_50 = 0 ;
V_41 -> V_42 = 0 ;
V_41 -> V_87 = - 1 ;
V_41 -> V_88 = - 1 ;
F_14 ( V_41 ) ;
if ( ! V_41 -> V_50 ) {
F_19 ( V_59 ) ;
F_18 ( V_41 -> V_29 ) ;
} else {
V_41 -> V_64 = V_62 ;
V_62 = V_59 ;
V_59 -> V_68 = V_41 -> V_50 ;
F_20 ( V_59 , NULL , 0 ) ;
return;
}
}
static int V_79 ( struct V_58 * V_59 , T_2 V_89 , T_3 V_90 ,
T_3 * V_91 , T_4 * V_92 )
{
int V_4 , V_9 ;
volatile char V_3 ;
unsigned char V_93 [ 6 ] , V_94 [ 6 ] ;
struct V_24 * V_41 = V_59 -> V_60 ;
void T_1 * V_1 = V_41 -> V_29 ;
struct V_46 * V_95 = & V_41 -> V_45 [ V_89 >> ( V_41 -> V_39 ) ] ;
if ( V_89 >= V_41 -> V_50 )
return - V_96 ;
if ( V_89 + V_90 > ( ( V_89 | 0x1ff ) + 1 ) )
V_90 = ( ( V_89 | 0x1ff ) + 1 ) - V_89 ;
if ( V_41 -> V_87 != V_95 -> floor ) {
F_10 ( V_1 , V_95 -> floor ) ;
F_9 ( V_1 , V_95 -> V_21 ) ;
} else if ( V_41 -> V_88 != V_95 -> V_21 ) {
F_9 ( V_1 , V_95 -> V_21 ) ;
}
V_41 -> V_87 = V_95 -> floor ;
V_41 -> V_88 = V_95 -> V_21 ;
F_6 ( V_1 , ( V_89 >> 8 ) & 1 , V_31 ) ;
F_8 ( V_1 , 3 , V_89 , V_31 , 0x00 ) ;
F_5 ( V_1 ) ;
F_7 ( V_97 , V_1 , V_98 ) ;
F_7 ( V_99 , V_1 , V_98 ) ;
V_3 = F_2 ( V_1 , V_33 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_90 - 1 ; V_4 ++ ) {
V_92 [ V_4 ] = F_2 ( V_1 , V_14 + ( V_4 & 0xff ) ) ;
}
#else
F_22 ( V_92 , V_1 + V_100 , V_90 - 1 ) ;
#endif
V_92 [ V_90 - 1 ] = F_2 ( V_1 , V_34 ) ;
* V_91 = V_90 ;
V_9 = 0 ;
V_3 = F_2 ( V_1 , V_33 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_94 [ V_4 ] = F_2 ( V_1 , V_14 + V_4 ) ;
}
#else
F_22 ( V_94 , V_1 + V_100 , 5 ) ;
#endif
V_94 [ 5 ] = F_2 ( V_1 , V_34 ) ;
V_3 = F_2 ( V_1 , V_98 ) ;
V_3 = F_2 ( V_1 , V_98 ) ;
if ( F_2 ( V_1 , V_98 ) & 0x80 ) {
int V_101 ;
#ifdef F_23
F_12 ( L_12 , ( long ) V_89 ) ;
#endif
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
V_93 [ V_4 ] = F_2 ( V_1 , V_102 + V_4 ) ;
}
V_101 = F_24 ( V_92 , V_93 ) ;
#ifdef F_23
F_12 ( L_13 , V_101 ) ;
#endif
if ( V_101 < 0 ) {
V_9 = - V_103 ;
}
}
#ifdef F_25
F_12 ( L_14 ,
( long ) V_89 , V_94 [ 0 ] , V_94 [ 1 ] , V_94 [ 2 ] , V_94 [ 3 ] ,
V_94 [ 4 ] , V_94 [ 5 ] ) ;
#endif
F_7 ( V_104 , V_1 , V_98 ) ;
return V_9 ;
}
static int V_81 ( struct V_58 * V_59 , T_2 V_105 , T_3 V_90 ,
T_3 * V_91 , const T_4 * V_92 )
{
int V_4 , V_9 = 0 ;
char V_94 [ 6 ] ;
volatile char V_3 ;
struct V_24 * V_41 = V_59 -> V_60 ;
void T_1 * V_1 = V_41 -> V_29 ;
struct V_46 * V_95 = & V_41 -> V_45 [ V_105 >> ( V_41 -> V_39 ) ] ;
if ( V_105 >= V_41 -> V_50 )
return - V_96 ;
#if 0
if (to + len > ( (to | 0x1ff) + 1))
len = ((to | 0x1ff) + 1) - to;
#else
if ( V_105 & 0x1ff || V_90 != 0x200 )
return - V_96 ;
#endif
if ( V_41 -> V_87 != V_95 -> floor ) {
F_10 ( V_1 , V_95 -> floor ) ;
F_9 ( V_1 , V_95 -> V_21 ) ;
} else if ( V_41 -> V_88 != V_95 -> V_21 ) {
F_9 ( V_1 , V_95 -> V_21 ) ;
}
V_41 -> V_87 = V_95 -> floor ;
V_41 -> V_88 = V_95 -> V_21 ;
F_6 ( V_1 , V_30 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_106 , 0x00 ) ;
F_6 ( V_1 , V_107 , 0x00 ) ;
F_8 ( V_1 , 3 , V_105 , 0x00 , 0x00 ) ;
F_5 ( V_1 ) ;
F_7 ( V_97 , V_1 , V_98 ) ;
F_7 ( V_99 | V_108 , V_1 , V_98 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
F_7 ( V_92 [ V_4 ] , V_1 , V_14 + V_4 ) ;
}
#else
F_26 ( V_1 + V_100 , V_92 , V_90 ) ;
#endif
F_7 ( 0x00 , V_1 , V_15 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
V_94 [ V_4 ] = F_2 ( V_1 , V_102 + V_4 ) ;
}
F_7 ( V_104 , V_1 , V_98 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
F_7 ( V_94 [ V_4 ] , V_1 , V_14 + V_4 ) ;
}
#else
F_26 ( V_1 + V_100 , V_94 , 6 ) ;
#endif
F_7 ( 0x55 , V_1 , V_14 ) ;
F_7 ( 0x55 , V_1 , V_14 + 1 ) ;
F_7 ( 0x00 , V_1 , V_15 ) ;
#ifdef F_25
F_12 ( L_15 ,
( long ) V_105 , V_94 [ 0 ] , V_94 [ 1 ] , V_94 [ 2 ] , V_94 [ 3 ] ,
V_94 [ 4 ] , V_94 [ 5 ] ) ;
#endif
F_6 ( V_1 , V_109 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_110 , V_31 ) ;
V_3 = F_2 ( V_1 , V_33 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_14 ) & 1 ) {
F_12 ( L_16 ) ;
* V_91 = 0 ;
V_9 = - V_103 ;
}
V_3 = F_2 ( V_1 , V_34 ) ;
* V_91 = V_90 ;
return V_9 ;
}
static int V_83 ( struct V_58 * V_59 , T_2 V_17 ,
struct V_111 * V_112 )
{
#ifndef F_21
int V_4 ;
#endif
volatile char V_3 ;
struct V_24 * V_41 = V_59 -> V_60 ;
void T_1 * V_1 = V_41 -> V_29 ;
struct V_46 * V_95 = & V_41 -> V_45 [ V_17 >> V_41 -> V_39 ] ;
T_5 * V_92 = V_112 -> V_113 ;
T_3 V_90 = V_112 -> V_90 ;
F_27 ( V_112 -> V_114 != V_115 ) ;
V_17 += V_112 -> V_116 ;
if ( V_41 -> V_87 != V_95 -> floor ) {
F_10 ( V_1 , V_95 -> floor ) ;
F_9 ( V_1 , V_95 -> V_21 ) ;
} else if ( V_41 -> V_88 != V_95 -> V_21 ) {
F_9 ( V_1 , V_95 -> V_21 ) ;
}
V_41 -> V_87 = V_95 -> floor ;
V_41 -> V_88 = V_95 -> V_21 ;
F_7 ( V_97 , V_1 , V_98 ) ;
F_7 ( V_104 , V_1 , V_98 ) ;
F_6 ( V_1 , V_117 , V_31 ) ;
F_8 ( V_1 , 3 , V_17 , V_31 , 0x00 ) ;
F_5 ( V_1 ) ;
V_3 = F_2 ( V_1 , V_33 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_90 - 1 ; V_4 ++ ) {
V_92 [ V_4 ] = F_2 ( V_1 , V_14 + V_4 ) ;
}
#else
F_22 ( V_92 , V_1 + V_100 , V_90 - 1 ) ;
#endif
V_92 [ V_90 - 1 ] = F_2 ( V_1 , V_34 ) ;
V_112 -> V_91 = V_90 ;
return 0 ;
}
static int V_85 ( struct V_58 * V_59 , T_2 V_17 ,
struct V_111 * V_112 )
{
#ifndef F_21
int V_4 ;
#endif
volatile char V_3 ;
int V_9 = 0 ;
struct V_24 * V_41 = V_59 -> V_60 ;
void T_1 * V_1 = V_41 -> V_29 ;
struct V_46 * V_95 = & V_41 -> V_45 [ V_17 >> V_41 -> V_39 ] ;
T_5 * V_92 = V_112 -> V_113 ;
T_3 V_90 = V_112 -> V_90 ;
F_27 ( V_112 -> V_114 != V_115 ) ;
V_17 += V_112 -> V_116 ;
if ( V_41 -> V_87 != V_95 -> floor ) {
F_10 ( V_1 , V_95 -> floor ) ;
F_9 ( V_1 , V_95 -> V_21 ) ;
} else if ( V_41 -> V_88 != V_95 -> V_21 ) {
F_9 ( V_1 , V_95 -> V_21 ) ;
}
V_41 -> V_87 = V_95 -> floor ;
V_41 -> V_88 = V_95 -> V_21 ;
F_7 ( V_97 , V_1 , V_98 ) ;
F_7 ( V_104 , V_1 , V_98 ) ;
F_6 ( V_1 , V_30 , V_31 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_117 , V_31 ) ;
F_6 ( V_1 , V_107 , 0x00 ) ;
F_8 ( V_1 , 3 , V_17 , 0x00 , 0x00 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ ) {
F_7 ( V_92 [ V_4 ] , V_1 , V_14 + V_4 ) ;
}
#else
F_26 ( V_1 + V_100 , V_92 , V_90 ) ;
#endif
F_7 ( 0x00 , V_1 , V_15 ) ;
F_6 ( V_1 , V_109 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_110 , 0x00 ) ;
V_3 = F_2 ( V_1 , V_33 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_14 ) & 1 ) {
F_12 ( L_17 ) ;
V_112 -> V_91 = 0 ;
V_9 = - V_103 ;
}
V_3 = F_2 ( V_1 , V_34 ) ;
V_112 -> V_91 = V_90 ;
return V_9 ;
}
int V_75 ( struct V_58 * V_59 , struct V_118 * V_119 )
{
volatile char V_3 ;
struct V_24 * V_41 = V_59 -> V_60 ;
T_6 V_17 = V_119 -> V_120 ;
T_6 V_90 = V_119 -> V_90 ;
void T_1 * V_1 = V_41 -> V_29 ;
struct V_46 * V_95 = & V_41 -> V_45 [ V_17 >> V_41 -> V_39 ] ;
if ( V_90 != V_59 -> V_69 )
F_12 ( V_121 L_18 ,
V_90 , V_59 -> V_69 ) ;
if ( V_41 -> V_87 != V_95 -> floor ) {
F_10 ( V_1 , V_95 -> floor ) ;
F_9 ( V_1 , V_95 -> V_21 ) ;
} else if ( V_41 -> V_88 != V_95 -> V_21 ) {
F_9 ( V_1 , V_95 -> V_21 ) ;
}
V_41 -> V_87 = V_95 -> floor ;
V_41 -> V_88 = V_95 -> V_21 ;
V_119 -> V_122 = V_123 ;
F_6 ( V_1 , V_124 , 0x00 ) ;
F_8 ( V_1 , 2 , V_17 , 0x00 , 0x00 ) ;
F_6 ( V_1 , V_125 , 0x00 ) ;
F_5 ( V_1 ) ;
V_119 -> V_122 = V_126 ;
F_6 ( V_1 , V_110 , V_31 ) ;
V_3 = F_2 ( V_1 , V_33 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_14 ) & 1 ) {
F_12 ( L_19 , V_17 ) ;
V_119 -> V_122 = V_127 ;
} else
V_119 -> V_122 = V_128 ;
V_3 = F_2 ( V_1 , V_34 ) ;
F_28 ( V_119 ) ;
return 0 ;
}
static void T_7 F_29 ( void )
{
struct V_58 * V_59 ;
struct V_24 * V_41 ;
while ( ( V_59 = V_62 ) ) {
V_41 = V_59 -> V_60 ;
V_62 = V_41 -> V_64 ;
F_30 ( V_59 ) ;
F_18 ( V_41 -> V_29 ) ;
F_19 ( V_41 -> V_45 ) ;
F_19 ( V_59 ) ;
}
}
