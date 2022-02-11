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
F_4 ( V_7 ,
L_1 ) ;
while ( ! ( F_2 ( V_1 , V_8 ) & V_9 ) && -- V_6 )
;
if ( V_6 == 0 )
F_4 ( V_10 , L_2 ) ;
return ( V_6 == 0 ) ;
}
static inline int F_5 ( void T_1 * V_1 )
{
int V_11 = 0 ;
F_1 ( V_1 , 4 ) ;
if ( ! ( F_2 ( V_1 , V_8 ) & V_9 ) )
V_11 = F_3 ( V_1 ) ;
F_1 ( V_1 , 2 ) ;
return V_11 ;
}
static void F_6 ( void T_1 * V_1 , unsigned char V_12 ,
unsigned char V_13 )
{
F_7 ( V_13 | V_14 | V_15 , V_1 , V_8 ) ;
F_1 ( V_1 , 4 ) ;
F_7 ( V_12 , V_1 , V_16 ) ;
F_7 ( 0x00 , V_1 , V_17 ) ;
F_7 ( V_13 | V_15 , V_1 , V_8 ) ;
F_1 ( V_1 , 4 ) ;
}
static inline void F_8 ( void T_1 * V_1 , int V_18 , unsigned long V_19 ,
unsigned char V_20 , unsigned char V_21 )
{
F_7 ( V_20 | V_22 | V_15 , V_1 , V_8 ) ;
F_1 ( V_1 , 4 ) ;
switch ( V_18 )
{
case 1 :
F_7 ( V_19 & 0xff , V_1 , V_16 ) ;
F_7 ( 0x00 , V_1 , V_17 ) ;
break;
case 2 :
F_7 ( ( V_19 >> 9 ) & 0xff , V_1 , V_16 ) ;
F_7 ( ( V_19 >> 17 ) & 0xff , V_1 , V_16 ) ;
F_7 ( 0x00 , V_1 , V_17 ) ;
break;
case 3 :
F_7 ( V_19 & 0xff , V_1 , V_16 ) ;
F_7 ( ( V_19 >> 9 ) & 0xff , V_1 , V_16 ) ;
F_7 ( ( V_19 >> 17 ) & 0xff , V_1 , V_16 ) ;
F_7 ( 0x00 , V_1 , V_17 ) ;
break;
default:
return;
}
F_7 ( V_20 | V_21 | V_15 , V_1 , V_8 ) ;
F_1 ( V_1 , 4 ) ;
}
static int F_9 ( void T_1 * V_1 , int V_23 )
{
F_7 ( V_23 , V_1 , V_24 ) ;
F_1 ( V_1 , 4 ) ;
return F_5 ( V_1 ) ;
}
static int F_10 ( void T_1 * V_1 , int floor )
{
F_7 ( floor , V_1 , V_25 ) ;
return F_5 ( V_1 ) ;
}
static int F_11 ( struct V_26 * V_27 , int floor , int V_23 )
{
int V_28 , V_29 , V_4 , V_30 ;
volatile char V_3 ;
F_10 ( V_27 -> V_31 , floor ) ;
F_9 ( V_27 -> V_31 , V_23 ) ;
F_6 ( V_27 -> V_31 , V_32 , V_33 ) ;
F_5 ( V_27 -> V_31 ) ;
F_6 ( V_27 -> V_31 , V_34 , V_33 ) ;
F_8 ( V_27 -> V_31 , 1 , 0x00 , V_33 , 0x00 ) ;
V_3 = F_2 ( V_27 -> V_31 , V_35 ) ;
F_1 ( V_27 -> V_31 , 2 ) ;
V_28 = F_2 ( V_27 -> V_31 , V_16 ) ;
F_1 ( V_27 -> V_31 , 2 ) ;
V_29 = F_2 ( V_27 -> V_31 , V_16 ) ;
V_3 = F_2 ( V_27 -> V_31 , V_36 ) ;
if ( V_28 == 0xff || V_28 == 0 )
return 0 ;
for ( V_4 = 0 ; V_37 [ V_4 ] . V_38 != NULL ; V_4 ++ ) {
if ( V_29 == V_37 [ V_4 ] . V_29 ) {
for ( V_30 = 0 ; V_39 [ V_30 ] . V_29 != 0x0 ; V_30 ++ ) {
if ( V_39 [ V_30 ] . V_29 == V_28 )
break;
}
F_12 ( V_40 L_3
L_4 ,
V_28 , V_29 , V_39 [ V_30 ] . V_38 , V_37 [ V_4 ] . V_38 ) ;
V_27 -> V_28 = V_28 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_41 = F_13 ( ( V_37 [ V_4 ] . V_42 << 20 ) ) - 1 ;
break;
}
}
if ( V_37 [ V_4 ] . V_38 == NULL )
return 0 ;
else
return 1 ;
}
static void F_14 ( struct V_26 * V_43 )
{
int floor , V_23 ;
int V_44 [ V_45 ] ;
int V_11 ;
V_43 -> V_44 = 0 ;
V_43 -> V_28 = 0 ;
V_43 -> V_29 = 0 ;
for ( floor = 0 , V_11 = 1 ; floor < V_45 ; floor ++ ) {
V_44 [ floor ] = 0 ;
for ( V_23 = 0 ; V_23 < V_46 && V_11 != 0 ; V_23 ++ ) {
V_11 = F_11 ( V_43 , floor , V_23 ) ;
if ( V_11 ) {
V_44 [ floor ] ++ ;
V_43 -> V_44 ++ ;
}
}
}
if ( ! V_43 -> V_44 ) {
F_12 ( L_5 ) ;
return;
}
V_43 -> V_47 = F_15 ( sizeof( struct V_48 ) * V_43 -> V_44 , V_49 ) ;
if ( ! V_43 -> V_47 ) {
F_12 ( L_6 ) ;
return;
}
for ( floor = 0 , V_11 = 0 ; floor < V_45 ; floor ++ ) {
for ( V_23 = 0 ; V_23 < V_44 [ floor ] ; V_23 ++ ) {
V_43 -> V_47 [ V_11 ] . floor = floor ;
V_43 -> V_47 [ V_11 ] . V_23 = V_23 ;
V_43 -> V_47 [ V_11 ] . V_50 = 0 ;
V_43 -> V_47 [ V_11 ] . V_51 = 0x50 ;
V_11 ++ ;
}
}
V_43 -> V_52 = V_43 -> V_44 * ( 1 << V_43 -> V_41 ) ;
F_12 ( V_40 L_7 ,
V_43 -> V_44 , V_43 -> V_52 >> 20 ) ;
}
static int F_16 ( struct V_26 * V_53 , struct V_26 * V_54 )
{
int V_55 , V_56 , V_57 ;
if ( V_53 -> V_58 == V_54 -> V_58 )
return 1 ;
V_55 = F_2 ( V_53 -> V_31 , V_59 ) ;
V_56 = F_2 ( V_54 -> V_31 , V_59 ) ;
if ( V_55 != V_56 )
return 0 ;
F_7 ( ( V_55 + 1 ) % 0xff , V_53 -> V_31 , V_59 ) ;
V_56 = F_2 ( V_54 -> V_31 , V_59 ) ;
if ( V_56 == ( V_55 + 1 ) % 0xff )
V_57 = 1 ;
else
V_57 = 0 ;
F_7 ( V_55 , V_53 -> V_31 , V_59 ) ;
return V_57 ;
}
void F_17 ( struct V_60 * V_61 )
{
struct V_26 * V_43 = V_61 -> V_62 ;
struct V_26 * V_63 = NULL ;
if ( V_64 )
V_63 = V_64 -> V_62 ;
while ( V_63 ) {
if ( F_16 ( V_43 , V_63 ) ) {
F_12 ( V_65 L_8
L_9 , V_43 -> V_58 ) ;
F_18 ( V_43 -> V_31 ) ;
F_19 ( V_61 ) ;
return;
}
if ( V_63 -> V_66 )
V_63 = V_63 -> V_66 -> V_62 ;
else
V_63 = NULL ;
}
V_61 -> V_38 = L_10 ;
F_12 ( V_65 L_11 ,
V_43 -> V_58 ) ;
V_61 -> type = V_67 ;
V_61 -> V_68 = V_69 ;
V_61 -> V_70 = 0 ;
V_61 -> V_71 = 0x2000 ;
V_61 -> V_72 = 512 ;
V_61 -> V_73 = 16 ;
V_61 -> V_74 = V_75 ;
V_61 -> V_76 = V_77 ;
V_61 -> V_78 = NULL ;
V_61 -> V_79 = NULL ;
V_61 -> V_80 = V_81 ;
V_61 -> V_82 = V_83 ;
V_61 -> V_84 = V_85 ;
V_61 -> V_86 = V_87 ;
V_61 -> V_88 = NULL ;
V_43 -> V_52 = 0 ;
V_43 -> V_44 = 0 ;
V_43 -> V_89 = - 1 ;
V_43 -> V_90 = - 1 ;
F_14 ( V_43 ) ;
if ( ! V_43 -> V_52 ) {
F_19 ( V_61 ) ;
F_18 ( V_43 -> V_31 ) ;
} else {
V_43 -> V_66 = V_64 ;
V_64 = V_61 ;
V_61 -> V_70 = V_43 -> V_52 ;
F_20 ( V_61 , NULL , 0 ) ;
return;
}
}
static int V_81 ( struct V_60 * V_61 , T_2 V_91 , T_3 V_92 ,
T_3 * V_93 , T_4 * V_94 )
{
int V_4 , V_11 ;
volatile char V_3 ;
unsigned char V_95 [ 6 ] , V_96 [ 6 ] ;
struct V_26 * V_43 = V_61 -> V_62 ;
void T_1 * V_1 = V_43 -> V_31 ;
struct V_48 * V_97 = & V_43 -> V_47 [ V_91 >> ( V_43 -> V_41 ) ] ;
if ( V_91 >= V_43 -> V_52 )
return - V_98 ;
if ( V_91 + V_92 > ( ( V_91 | 0x1ff ) + 1 ) )
V_92 = ( ( V_91 | 0x1ff ) + 1 ) - V_91 ;
if ( V_43 -> V_89 != V_97 -> floor ) {
F_10 ( V_1 , V_97 -> floor ) ;
F_9 ( V_1 , V_97 -> V_23 ) ;
} else if ( V_43 -> V_90 != V_97 -> V_23 ) {
F_9 ( V_1 , V_97 -> V_23 ) ;
}
V_43 -> V_89 = V_97 -> floor ;
V_43 -> V_90 = V_97 -> V_23 ;
F_6 ( V_1 , ( V_91 >> 8 ) & 1 , V_33 ) ;
F_8 ( V_1 , 3 , V_91 , V_33 , 0x00 ) ;
F_5 ( V_1 ) ;
F_7 ( V_99 , V_1 , V_100 ) ;
F_7 ( V_101 , V_1 , V_100 ) ;
V_3 = F_2 ( V_1 , V_35 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_92 - 1 ; V_4 ++ ) {
V_94 [ V_4 ] = F_2 ( V_1 , V_16 + ( V_4 & 0xff ) ) ;
}
#else
F_22 ( V_94 , V_1 + V_102 , V_92 - 1 ) ;
#endif
V_94 [ V_92 - 1 ] = F_2 ( V_1 , V_36 ) ;
* V_93 = V_92 ;
V_11 = 0 ;
V_3 = F_2 ( V_1 , V_35 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < 5 ; V_4 ++ ) {
V_96 [ V_4 ] = F_2 ( V_1 , V_16 + V_4 ) ;
}
#else
F_22 ( V_96 , V_1 + V_102 , 5 ) ;
#endif
V_96 [ 5 ] = F_2 ( V_1 , V_36 ) ;
V_3 = F_2 ( V_1 , V_100 ) ;
V_3 = F_2 ( V_1 , V_100 ) ;
if ( F_2 ( V_1 , V_100 ) & 0x80 ) {
int V_103 ;
#ifdef F_23
F_12 ( L_12 , ( long ) V_91 ) ;
#endif
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
V_95 [ V_4 ] = F_2 ( V_1 , V_104 + V_4 ) ;
}
V_103 = F_24 ( V_94 , V_95 ) ;
#ifdef F_23
F_12 ( L_13 , V_103 ) ;
#endif
if ( V_103 < 0 ) {
V_11 = - V_105 ;
}
}
#ifdef F_25
F_12 ( L_14 ,
( long ) V_91 , V_96 [ 0 ] , V_96 [ 1 ] , V_96 [ 2 ] , V_96 [ 3 ] ,
V_96 [ 4 ] , V_96 [ 5 ] ) ;
#endif
F_7 ( V_106 , V_1 , V_100 ) ;
return V_11 ;
}
static int V_83 ( struct V_60 * V_61 , T_2 V_107 , T_3 V_92 ,
T_3 * V_93 , const T_4 * V_94 )
{
int V_4 , V_11 = 0 ;
char V_96 [ 6 ] ;
volatile char V_3 ;
struct V_26 * V_43 = V_61 -> V_62 ;
void T_1 * V_1 = V_43 -> V_31 ;
struct V_48 * V_97 = & V_43 -> V_47 [ V_107 >> ( V_43 -> V_41 ) ] ;
if ( V_107 >= V_43 -> V_52 )
return - V_98 ;
#if 0
if (to + len > ( (to | 0x1ff) + 1))
len = ((to | 0x1ff) + 1) - to;
#else
if ( V_107 & 0x1ff || V_92 != 0x200 )
return - V_98 ;
#endif
if ( V_43 -> V_89 != V_97 -> floor ) {
F_10 ( V_1 , V_97 -> floor ) ;
F_9 ( V_1 , V_97 -> V_23 ) ;
} else if ( V_43 -> V_90 != V_97 -> V_23 ) {
F_9 ( V_1 , V_97 -> V_23 ) ;
}
V_43 -> V_89 = V_97 -> floor ;
V_43 -> V_90 = V_97 -> V_23 ;
F_6 ( V_1 , V_32 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_108 , 0x00 ) ;
F_6 ( V_1 , V_109 , 0x00 ) ;
F_8 ( V_1 , 3 , V_107 , 0x00 , 0x00 ) ;
F_5 ( V_1 ) ;
F_7 ( V_99 , V_1 , V_100 ) ;
F_7 ( V_101 | V_110 , V_1 , V_100 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_92 ; V_4 ++ ) {
F_7 ( V_94 [ V_4 ] , V_1 , V_16 + V_4 ) ;
}
#else
F_26 ( V_1 + V_102 , V_94 , V_92 ) ;
#endif
F_7 ( 0x00 , V_1 , V_17 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
F_7 ( 0 , V_1 , V_5 ) ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
V_96 [ V_4 ] = F_2 ( V_1 , V_104 + V_4 ) ;
}
F_7 ( V_106 , V_1 , V_100 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
F_7 ( V_96 [ V_4 ] , V_1 , V_16 + V_4 ) ;
}
#else
F_26 ( V_1 + V_102 , V_96 , 6 ) ;
#endif
F_7 ( 0x55 , V_1 , V_16 ) ;
F_7 ( 0x55 , V_1 , V_16 + 1 ) ;
F_7 ( 0x00 , V_1 , V_17 ) ;
#ifdef F_25
F_12 ( L_15 ,
( long ) V_107 , V_96 [ 0 ] , V_96 [ 1 ] , V_96 [ 2 ] , V_96 [ 3 ] ,
V_96 [ 4 ] , V_96 [ 5 ] ) ;
#endif
F_6 ( V_1 , V_111 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_112 , V_33 ) ;
V_3 = F_2 ( V_1 , V_35 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_16 ) & 1 ) {
F_12 ( L_16 ) ;
* V_93 = 0 ;
V_11 = - V_105 ;
}
V_3 = F_2 ( V_1 , V_36 ) ;
* V_93 = V_92 ;
return V_11 ;
}
static int V_85 ( struct V_60 * V_61 , T_2 V_19 ,
struct V_113 * V_114 )
{
#ifndef F_21
int V_4 ;
#endif
volatile char V_3 ;
struct V_26 * V_43 = V_61 -> V_62 ;
void T_1 * V_1 = V_43 -> V_31 ;
struct V_48 * V_97 = & V_43 -> V_47 [ V_19 >> V_43 -> V_41 ] ;
T_5 * V_94 = V_114 -> V_115 ;
T_3 V_92 = V_114 -> V_92 ;
F_27 ( V_114 -> V_116 != V_117 ) ;
V_19 += V_114 -> V_118 ;
if ( V_43 -> V_89 != V_97 -> floor ) {
F_10 ( V_1 , V_97 -> floor ) ;
F_9 ( V_1 , V_97 -> V_23 ) ;
} else if ( V_43 -> V_90 != V_97 -> V_23 ) {
F_9 ( V_1 , V_97 -> V_23 ) ;
}
V_43 -> V_89 = V_97 -> floor ;
V_43 -> V_90 = V_97 -> V_23 ;
F_7 ( V_99 , V_1 , V_100 ) ;
F_7 ( V_106 , V_1 , V_100 ) ;
F_6 ( V_1 , V_119 , V_33 ) ;
F_8 ( V_1 , 3 , V_19 , V_33 , 0x00 ) ;
F_5 ( V_1 ) ;
V_3 = F_2 ( V_1 , V_35 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_92 - 1 ; V_4 ++ ) {
V_94 [ V_4 ] = F_2 ( V_1 , V_16 + V_4 ) ;
}
#else
F_22 ( V_94 , V_1 + V_102 , V_92 - 1 ) ;
#endif
V_94 [ V_92 - 1 ] = F_2 ( V_1 , V_36 ) ;
V_114 -> V_93 = V_92 ;
return 0 ;
}
static int V_87 ( struct V_60 * V_61 , T_2 V_19 ,
struct V_113 * V_114 )
{
#ifndef F_21
int V_4 ;
#endif
volatile char V_3 ;
int V_11 = 0 ;
struct V_26 * V_43 = V_61 -> V_62 ;
void T_1 * V_1 = V_43 -> V_31 ;
struct V_48 * V_97 = & V_43 -> V_47 [ V_19 >> V_43 -> V_41 ] ;
T_5 * V_94 = V_114 -> V_115 ;
T_3 V_92 = V_114 -> V_92 ;
F_27 ( V_114 -> V_116 != V_117 ) ;
V_19 += V_114 -> V_118 ;
if ( V_43 -> V_89 != V_97 -> floor ) {
F_10 ( V_1 , V_97 -> floor ) ;
F_9 ( V_1 , V_97 -> V_23 ) ;
} else if ( V_43 -> V_90 != V_97 -> V_23 ) {
F_9 ( V_1 , V_97 -> V_23 ) ;
}
V_43 -> V_89 = V_97 -> floor ;
V_43 -> V_90 = V_97 -> V_23 ;
F_7 ( V_99 , V_1 , V_100 ) ;
F_7 ( V_106 , V_1 , V_100 ) ;
F_6 ( V_1 , V_32 , V_33 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_119 , V_33 ) ;
F_6 ( V_1 , V_109 , 0x00 ) ;
F_8 ( V_1 , 3 , V_19 , 0x00 , 0x00 ) ;
#ifndef F_21
for ( V_4 = 0 ; V_4 < V_92 ; V_4 ++ ) {
F_7 ( V_94 [ V_4 ] , V_1 , V_16 + V_4 ) ;
}
#else
F_26 ( V_1 + V_102 , V_94 , V_92 ) ;
#endif
F_7 ( 0x00 , V_1 , V_17 ) ;
F_6 ( V_1 , V_111 , 0x00 ) ;
F_5 ( V_1 ) ;
F_6 ( V_1 , V_112 , 0x00 ) ;
V_3 = F_2 ( V_1 , V_35 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_16 ) & 1 ) {
F_12 ( L_17 ) ;
V_114 -> V_93 = 0 ;
V_11 = - V_105 ;
}
V_3 = F_2 ( V_1 , V_36 ) ;
V_114 -> V_93 = V_92 ;
return V_11 ;
}
int V_77 ( struct V_60 * V_61 , struct V_120 * V_121 )
{
volatile char V_3 ;
struct V_26 * V_43 = V_61 -> V_62 ;
T_6 V_19 = V_121 -> V_122 ;
T_6 V_92 = V_121 -> V_92 ;
void T_1 * V_1 = V_43 -> V_31 ;
struct V_48 * V_97 = & V_43 -> V_47 [ V_19 >> V_43 -> V_41 ] ;
if ( V_92 != V_61 -> V_71 )
F_12 ( V_123 L_18 ,
V_92 , V_61 -> V_71 ) ;
if ( V_43 -> V_89 != V_97 -> floor ) {
F_10 ( V_1 , V_97 -> floor ) ;
F_9 ( V_1 , V_97 -> V_23 ) ;
} else if ( V_43 -> V_90 != V_97 -> V_23 ) {
F_9 ( V_1 , V_97 -> V_23 ) ;
}
V_43 -> V_89 = V_97 -> floor ;
V_43 -> V_90 = V_97 -> V_23 ;
V_121 -> V_124 = V_125 ;
F_6 ( V_1 , V_126 , 0x00 ) ;
F_8 ( V_1 , 2 , V_19 , 0x00 , 0x00 ) ;
F_6 ( V_1 , V_127 , 0x00 ) ;
F_5 ( V_1 ) ;
V_121 -> V_124 = V_128 ;
F_6 ( V_1 , V_112 , V_33 ) ;
V_3 = F_2 ( V_1 , V_35 ) ;
F_1 ( V_1 , 2 ) ;
if ( F_2 ( V_1 , V_16 ) & 1 ) {
F_12 ( L_19 , V_19 ) ;
V_121 -> V_124 = V_129 ;
} else
V_121 -> V_124 = V_130 ;
V_3 = F_2 ( V_1 , V_36 ) ;
F_28 ( V_121 ) ;
return 0 ;
}
static void T_7 F_29 ( void )
{
struct V_60 * V_61 ;
struct V_26 * V_43 ;
while ( ( V_61 = V_64 ) ) {
V_43 = V_61 -> V_62 ;
V_64 = V_43 -> V_66 ;
F_30 ( V_61 ) ;
F_18 ( V_43 -> V_31 ) ;
F_19 ( V_43 -> V_47 ) ;
F_19 ( V_61 ) ;
}
}
