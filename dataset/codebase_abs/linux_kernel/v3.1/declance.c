static inline void F_1 ( volatile unsigned short * V_1 , short V_2 )
{
* V_1 = V_2 ;
F_2 () ;
}
static void F_3 ( struct V_3 * V_4 )
{
volatile struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = 0 ;
F_1 ( & V_6 -> V_8 , V_9 ) ;
F_1 ( & V_6 -> V_10 , ( V_7 & 0xFFFF ) ) ;
F_1 ( & V_6 -> V_8 , V_11 ) ;
F_1 ( & V_6 -> V_10 , V_7 >> 16 ) ;
F_1 ( & V_6 -> V_8 , V_12 ) ;
F_1 ( & V_6 -> V_10 , V_4 -> V_13 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
}
static void F_4 ( const int type , void * V_15 , const void * V_16 , int V_17 )
{
unsigned short * V_18 ;
const unsigned short * V_19 ;
unsigned short V_20 ;
unsigned char * V_21 ;
const unsigned char * V_22 ;
if ( type == V_23 ) {
memcpy ( V_15 , V_16 , V_17 ) ;
} else if ( type == V_24 ) {
V_20 = V_17 >> 1 ;
V_18 = V_15 ;
V_19 = V_16 ;
while ( V_20 -- ) {
* V_18 ++ = * V_19 ++ ;
V_18 ++ ;
}
V_20 = V_17 & 1 ;
V_21 = V_18 ;
V_22 = V_19 ;
while ( V_20 -- ) {
* V_21 ++ = * V_22 ++ ;
}
} else {
V_20 = V_17 >> 4 ;
V_18 = V_15 ;
V_19 = V_16 ;
while ( V_20 -- ) {
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
V_18 += 8 ;
}
V_20 = V_17 & 15 ;
V_21 = ( unsigned char * ) V_18 ;
V_22 = ( unsigned char * ) V_19 ;
while ( V_20 -- ) {
* V_21 ++ = * V_22 ++ ;
}
}
F_2 () ;
}
static void F_5 ( const int type , void * V_15 , const void * V_16 , int V_17 )
{
unsigned short * V_18 ;
const unsigned short * V_19 ;
unsigned short V_20 ;
unsigned char * V_21 ;
const unsigned char * V_22 ;
if ( type == V_23 ) {
memcpy ( V_15 , V_16 , V_17 ) ;
} else if ( type == V_24 ) {
V_20 = V_17 >> 1 ;
V_18 = V_15 ;
V_19 = V_16 ;
while ( V_20 -- ) {
* V_18 ++ = * V_19 ++ ;
V_19 ++ ;
}
V_20 = V_17 & 1 ;
V_21 = V_18 ;
V_22 = V_19 ;
while ( V_20 -- ) {
* V_21 ++ = * V_22 ++ ;
}
} else {
V_20 = V_17 >> 4 ;
V_18 = V_15 ;
V_19 = V_16 ;
while ( V_20 -- ) {
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
* V_18 ++ = * V_19 ++ ;
V_19 += 8 ;
}
V_20 = V_17 & 15 ;
V_21 = ( unsigned char * ) V_18 ;
V_22 = ( unsigned char * ) V_19 ;
while ( V_20 -- ) {
* V_21 ++ = * V_22 ++ ;
}
}
}
static void F_6 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
T_1 V_7 ;
int V_29 ;
F_8 ( V_26 ) ;
V_4 -> V_30 = V_4 -> V_31 = 0 ;
V_4 -> V_32 = V_4 -> V_33 = 0 ;
* F_9 ( V_27 , V_34 [ 0 ] , V_4 -> type ) = ( V_26 -> V_35 [ 1 ] << 8 ) |
V_26 -> V_35 [ 0 ] ;
* F_9 ( V_27 , V_34 [ 1 ] , V_4 -> type ) = ( V_26 -> V_35 [ 3 ] << 8 ) |
V_26 -> V_35 [ 2 ] ;
* F_9 ( V_27 , V_34 [ 2 ] , V_4 -> type ) = ( V_26 -> V_35 [ 5 ] << 8 ) |
V_26 -> V_35 [ 4 ] ;
V_7 = F_10 ( struct V_36 , V_37 ) ;
* F_9 ( V_27 , V_38 , V_4 -> type ) = ( V_39 << 13 ) |
( V_7 >> 16 ) ;
* F_9 ( V_27 , V_40 , V_4 -> type ) = V_7 ;
if ( V_41 )
F_11 ( L_1 ,
V_7 , F_12 ( V_37 , V_4 -> type ) ) ;
V_7 = F_10 ( struct V_36 , V_42 ) ;
* F_9 ( V_27 , V_43 , V_4 -> type ) = ( V_44 << 13 ) |
( V_7 >> 16 ) ;
* F_9 ( V_27 , V_45 , V_4 -> type ) = V_7 ;
if ( V_41 )
F_11 ( L_2 ,
V_7 , F_12 ( V_42 , V_4 -> type ) ) ;
if ( V_41 )
F_11 ( L_3 ) ;
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_7 = V_4 -> V_47 [ V_29 ] ;
* F_9 ( V_27 , V_42 [ V_29 ] . V_48 , V_4 -> type ) = V_7 ;
* F_9 ( V_27 , V_42 [ V_29 ] . V_49 , V_4 -> type ) = ( V_7 >> 16 ) &
0xff ;
* F_9 ( V_27 , V_42 [ V_29 ] . V_50 , V_4 -> type ) = 0xf000 ;
* F_9 ( V_27 , V_42 [ V_29 ] . V_51 , V_4 -> type ) = 0 ;
if ( V_29 < 3 && V_41 )
F_11 ( L_4 ,
V_29 , V_7 , ( T_1 ) V_4 -> V_52 [ V_29 ] ) ;
}
if ( V_41 )
F_11 ( L_5 ) ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_7 = V_4 -> V_54 [ V_29 ] ;
* F_9 ( V_27 , V_37 [ V_29 ] . V_55 , V_4 -> type ) = V_7 ;
* F_9 ( V_27 , V_37 [ V_29 ] . V_56 , V_4 -> type ) = ( ( V_7 >> 16 ) &
0xff ) |
V_57 ;
* F_9 ( V_27 , V_37 [ V_29 ] . V_50 , V_4 -> type ) = - V_58 |
0xf000 ;
* F_9 ( V_27 , V_37 [ V_29 ] . V_59 , V_4 -> type ) = 0 ;
if ( V_29 < 3 && V_41 )
F_11 ( L_4 ,
V_29 , V_7 , ( T_1 ) V_4 -> V_60 [ V_29 ] ) ;
}
F_2 () ;
}
static int F_13 ( struct V_3 * V_4 )
{
volatile struct V_5 * V_6 = V_4 -> V_6 ;
int V_29 ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_61 ) ;
for ( V_29 = 0 ; ( V_29 < 100 ) && ! ( V_6 -> V_10 & V_62 ) ; V_29 ++ ) {
F_14 ( 10 ) ;
}
if ( ( V_29 == 100 ) || ( V_6 -> V_10 & V_63 ) ) {
F_11 ( L_6 ,
V_29 , V_6 -> V_10 ) ;
return - 1 ;
}
if ( ( V_6 -> V_10 & V_63 ) ) {
F_11 ( L_6 ,
V_29 , V_6 -> V_10 ) ;
return - 1 ;
}
F_1 ( & V_6 -> V_10 , V_62 ) ;
F_1 ( & V_6 -> V_10 , V_64 ) ;
F_1 ( & V_6 -> V_10 , V_65 ) ;
return 0 ;
}
static int F_15 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
volatile T_2 * V_66 ;
unsigned short V_67 ;
int V_68 , V_17 ;
struct V_69 * V_70 ;
#ifdef F_16
{
int V_29 ;
F_11 ( L_7 ) ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
if ( V_29 == V_4 -> V_30 )
F_11 ( L_8 , * F_9 ( V_27 , V_37 [ V_29 ] . V_56 ,
V_4 -> type ) &
V_57 ? L_9 : L_10 ) ;
else
F_11 ( L_8 , * F_9 ( V_27 , V_37 [ V_29 ] . V_56 ,
V_4 -> type ) &
V_57 ? L_11 : L_12 ) ;
}
F_11 ( L_13 ) ;
}
#endif
for ( V_66 = F_9 ( V_27 , V_37 [ V_4 -> V_30 ] , V_4 -> type ) ;
! ( ( V_67 = * F_17 ( V_66 , V_56 , V_4 -> type ) ) & V_57 ) ;
V_66 = F_9 ( V_27 , V_37 [ V_4 -> V_30 ] , V_4 -> type ) ) {
V_68 = V_4 -> V_30 ;
if ( ( V_67 & V_71 ) != V_71 ) {
V_26 -> V_72 . V_73 ++ ;
V_26 -> V_72 . V_74 ++ ;
} else if ( V_67 & V_75 ) {
if ( V_67 & V_76 )
V_26 -> V_72 . V_77 ++ ;
if ( V_67 & V_78 )
V_26 -> V_72 . V_79 ++ ;
if ( V_67 & V_80 )
V_26 -> V_72 . V_73 ++ ;
if ( V_67 & V_81 )
V_26 -> V_72 . V_82 ++ ;
if ( V_67 & V_83 )
V_26 -> V_72 . V_74 ++ ;
} else {
V_17 = ( * F_17 ( V_66 , V_59 , V_4 -> type ) & 0xfff ) - 4 ;
V_70 = F_18 ( V_17 + 2 ) ;
if ( V_70 == 0 ) {
F_11 ( L_14 ,
V_26 -> V_84 ) ;
V_26 -> V_72 . V_85 ++ ;
* F_17 ( V_66 , V_59 , V_4 -> type ) = 0 ;
* F_17 ( V_66 , V_56 , V_4 -> type ) =
( ( V_4 -> V_54 [ V_68 ] >> 16 ) &
0xff ) | V_57 ;
V_4 -> V_30 = ( V_68 + 1 ) & V_86 ;
return 0 ;
}
V_26 -> V_72 . V_87 += V_17 ;
F_19 ( V_70 , 2 ) ;
F_20 ( V_70 , V_17 ) ;
F_5 ( V_4 -> type , V_70 -> V_88 ,
( char * ) V_4 -> V_60 [ V_68 ] , V_17 ) ;
V_70 -> V_89 = F_21 ( V_70 , V_26 ) ;
F_22 ( V_70 ) ;
V_26 -> V_72 . V_90 ++ ;
}
* F_17 ( V_66 , V_59 , V_4 -> type ) = 0 ;
* F_17 ( V_66 , V_50 , V_4 -> type ) = - V_58 | 0xf000 ;
* F_17 ( V_66 , V_56 , V_4 -> type ) =
( ( V_4 -> V_54 [ V_68 ] >> 16 ) & 0xff ) | V_57 ;
V_4 -> V_30 = ( V_68 + 1 ) & V_86 ;
}
return 0 ;
}
static void F_23 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
volatile T_2 * V_91 ;
int V_29 , V_92 ;
int V_93 ;
V_92 = V_4 -> V_33 ;
F_24 ( & V_4 -> V_94 ) ;
for ( V_29 = V_92 ; V_29 != V_4 -> V_31 ; V_29 = V_92 ) {
V_91 = F_9 ( V_27 , V_42 [ V_29 ] , V_4 -> type ) ;
if ( * F_25 ( V_91 , V_49 , V_4 -> type ) & V_95 )
break;
if ( * F_25 ( V_91 , V_49 , V_4 -> type ) & V_96 ) {
V_93 = * F_25 ( V_91 , V_51 , V_4 -> type ) ;
V_26 -> V_72 . V_97 ++ ;
if ( V_93 & V_98 )
V_26 -> V_72 . V_99 ++ ;
if ( V_93 & V_100 )
V_26 -> V_72 . V_101 ++ ;
if ( V_93 & V_102 ) {
V_26 -> V_72 . V_103 ++ ;
F_11 ( L_15 , V_26 -> V_84 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
goto V_105;
}
if ( V_93 & ( V_106 | V_107 ) ) {
V_26 -> V_72 . V_108 ++ ;
F_11 ( L_16 ,
V_26 -> V_84 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
goto V_105;
}
} else if ( ( * F_25 ( V_91 , V_49 , V_4 -> type ) & V_109 ) ==
V_109 ) {
* F_25 ( V_91 , V_49 , V_4 -> type ) &= ~ ( V_109 ) ;
if ( * F_25 ( V_91 , V_49 , V_4 -> type ) & V_110 )
V_26 -> V_72 . V_111 ++ ;
if ( * F_25 ( V_91 , V_49 , V_4 -> type ) & V_112 )
V_26 -> V_72 . V_111 += 2 ;
V_26 -> V_72 . V_113 ++ ;
}
V_92 = ( V_92 + 1 ) & V_114 ;
}
V_4 -> V_33 = V_92 ;
V_105:
if ( F_26 ( V_26 ) &&
V_115 > 0 )
F_27 ( V_26 ) ;
F_28 ( & V_4 -> V_94 ) ;
}
static T_3 F_29 ( int V_116 , void * V_117 )
{
struct V_25 * V_26 = V_117 ;
F_11 ( V_118 L_17 , V_26 -> V_84 ) ;
return V_119 ;
}
static T_3 F_30 ( int V_116 , void * V_117 )
{
struct V_25 * V_26 = V_117 ;
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
int V_120 ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
V_120 = V_6 -> V_10 ;
F_1 ( & V_6 -> V_10 , V_120 & ( V_121 | V_122 | V_123 ) ) ;
if ( ( V_120 & V_63 ) ) {
F_1 ( & V_6 -> V_10 , V_124 | V_63 | V_125 |
V_126 | V_127 ) ;
}
if ( V_120 & V_123 )
F_15 ( V_26 ) ;
if ( V_120 & V_122 )
F_23 ( V_26 ) ;
if ( V_120 & V_124 )
V_26 -> V_72 . V_97 ++ ;
if ( V_120 & V_125 )
V_26 -> V_72 . V_74 ++ ;
if ( V_120 & V_127 ) {
F_11 ( L_18 , V_26 -> V_84 , V_120 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
F_27 ( V_26 ) ;
}
F_1 ( & V_6 -> V_10 , V_65 ) ;
F_1 ( & V_6 -> V_10 , V_65 ) ;
return V_119 ;
}
static int F_31 ( struct V_25 * V_26 )
{
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
int V_93 = 0 ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
* F_9 ( V_27 , V_128 , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 0 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 1 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 2 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 3 ] , V_4 -> type ) = 0 ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_32 ( V_26 ) ;
if ( F_33 ( V_26 -> V_116 , F_30 , 0 , L_19 , V_26 ) ) {
F_11 ( L_20 , V_26 -> V_84 , V_26 -> V_116 ) ;
return - V_130 ;
}
if ( V_4 -> V_131 >= 0 ) {
unsigned long V_132 ;
if ( F_33 ( V_4 -> V_131 , F_29 , 0 ,
L_21 , V_26 ) ) {
F_34 ( V_26 -> V_116 , V_26 ) ;
F_11 ( L_22 , V_26 -> V_84 ,
V_4 -> V_131 ) ;
return - V_130 ;
}
F_35 ( & V_133 , V_132 ) ;
F_36 () ;
F_37 ( V_134 ,
F_38 ( V_134 ) | V_135 ) ;
F_36 () ;
F_39 ( & V_133 , V_132 ) ;
}
V_93 = F_13 ( V_4 ) ;
return V_93 ;
}
static int F_40 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
F_8 ( V_26 ) ;
F_41 ( & V_4 -> V_136 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
if ( V_4 -> V_131 >= 0 ) {
unsigned long V_132 ;
F_35 ( & V_133 , V_132 ) ;
F_36 () ;
F_37 ( V_134 ,
F_38 ( V_134 ) & ~ V_135 ) ;
F_42 () ;
F_39 ( & V_133 , V_132 ) ;
F_34 ( V_4 -> V_131 , V_26 ) ;
}
F_34 ( V_26 -> V_116 , V_26 ) ;
return 0 ;
}
static inline int F_43 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
int V_93 ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
V_26 -> V_137 = V_138 ;
V_93 = F_13 ( V_4 ) ;
return V_93 ;
}
static void F_44 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
F_11 ( V_118 L_23 ,
V_26 -> V_84 , V_6 -> V_10 ) ;
F_43 ( V_26 ) ;
F_27 ( V_26 ) ;
}
static int F_45 ( struct V_69 * V_70 , struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
unsigned long V_132 ;
int V_68 , V_17 ;
V_17 = V_70 -> V_17 ;
if ( V_17 < V_139 ) {
if ( F_46 ( V_70 , V_139 ) )
return V_140 ;
V_17 = V_139 ;
}
V_26 -> V_72 . V_141 += V_17 ;
F_35 ( & V_4 -> V_94 , V_132 ) ;
V_68 = V_4 -> V_31 ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_50 , V_4 -> type ) = ( - V_17 ) ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_51 , V_4 -> type ) = 0 ;
F_4 ( V_4 -> type , ( char * ) V_4 -> V_52 [ V_68 ] , V_70 -> V_88 , V_17 ) ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_49 , V_4 -> type ) =
( ( V_4 -> V_47 [ V_68 ] >> 16 ) & 0xff ) |
( V_109 | V_95 ) ;
V_4 -> V_31 = ( V_68 + 1 ) & V_114 ;
if ( V_115 <= 0 )
F_8 ( V_26 ) ;
F_1 ( & V_6 -> V_10 , V_65 | V_142 ) ;
F_39 ( & V_4 -> V_94 , V_132 ) ;
F_47 ( V_70 ) ;
return V_140 ;
}
static void F_48 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
struct V_143 * V_144 ;
T_4 V_145 ;
if ( V_26 -> V_132 & V_146 ) {
* F_9 ( V_27 , V_129 [ 0 ] , V_4 -> type ) = 0xffff ;
* F_9 ( V_27 , V_129 [ 1 ] , V_4 -> type ) = 0xffff ;
* F_9 ( V_27 , V_129 [ 2 ] , V_4 -> type ) = 0xffff ;
* F_9 ( V_27 , V_129 [ 3 ] , V_4 -> type ) = 0xffff ;
return;
}
* F_9 ( V_27 , V_129 [ 0 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 1 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 2 ] , V_4 -> type ) = 0 ;
* F_9 ( V_27 , V_129 [ 3 ] , V_4 -> type ) = 0 ;
F_49 (ha, dev) {
V_145 = F_50 ( V_147 , V_144 -> V_148 ) ;
V_145 = V_145 >> 26 ;
* F_9 ( V_27 , V_129 [ V_145 >> 4 ] , V_4 -> type ) |= 1 << ( V_145 & 0xf ) ;
}
}
static void F_51 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
if ( ! F_52 ( V_26 ) )
return;
if ( V_4 -> V_33 != V_4 -> V_31 ) {
F_53 ( & V_4 -> V_136 , V_138 + 4 * V_149 / 100 ) ;
F_27 ( V_26 ) ;
return;
}
F_8 ( V_26 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
if ( V_26 -> V_132 & V_150 ) {
* F_9 ( V_27 , V_128 , V_4 -> type ) |= V_151 ;
} else {
* F_9 ( V_27 , V_128 , V_4 -> type ) &= ~ V_151 ;
F_48 ( V_26 ) ;
}
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
F_27 ( V_26 ) ;
}
static void F_54 ( unsigned long V_152 )
{
struct V_25 * V_26 = (struct V_25 * ) V_152 ;
F_51 ( V_26 ) ;
}
static int T_5 F_55 ( struct V_153 * V_154 , const int type )
{
static unsigned V_155 ;
static const char V_156 [] = L_24 ;
char V_84 [ 10 ] ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
volatile struct V_5 * V_6 ;
T_6 V_157 = 0 , V_17 = 0 ;
int V_29 , V_158 ;
unsigned long V_159 ;
unsigned char * V_160 ;
if ( V_161 && V_155 ++ == 0 )
F_11 ( V_162 ) ;
if ( V_154 )
snprintf ( V_84 , sizeof( V_84 ) , L_8 , F_56 ( V_154 ) ) ;
else {
V_29 = 0 ;
V_26 = V_163 ;
while ( V_26 ) {
V_29 ++ ;
V_4 = F_7 ( V_26 ) ;
V_26 = V_4 -> V_164 ;
}
snprintf ( V_84 , sizeof( V_84 ) , V_156 , V_29 ) ;
}
V_26 = F_57 ( sizeof( struct V_3 ) ) ;
if ( ! V_26 ) {
F_11 ( V_118 L_25 ,
V_84 ) ;
V_158 = - V_165 ;
goto V_166;
}
V_4 = F_7 ( V_26 ) ;
F_58 ( & V_4 -> V_94 ) ;
V_4 -> type = type ;
switch ( type ) {
case V_167 :
V_26 -> V_168 = F_59 ( V_169 + V_170 ) ;
V_26 -> V_28 = F_59 ( 0x00020000 ) ;
V_26 -> V_171 = V_26 -> V_28 + 0x00020000 ;
V_26 -> V_116 = V_172 [ V_173 ] ;
V_159 = F_59 ( V_169 + V_174 ) ;
memset ( ( void * ) V_26 -> V_28 , 0 ,
V_26 -> V_171 - V_26 -> V_28 ) ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_175 +
2 * V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_176 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_175 +
2 * V_53 * V_58 +
2 * V_29 * V_177 ) ;
V_4 -> V_47 [ V_29 ] =
( V_176 +
V_53 * V_58 +
V_29 * V_177 ) ;
}
V_4 -> V_131 = V_172 [ V_178 ] ;
F_37 ( V_179 ,
F_60 ( V_26 -> V_28 ) << 3 ) ;
break;
#ifdef F_61
case V_23 :
F_62 ( V_154 , V_26 ) ;
V_157 = F_63 ( V_154 ) -> V_180 . V_157 ;
V_17 = F_63 ( V_154 ) -> V_180 . V_181 - V_157 + 1 ;
if ( ! F_64 ( V_157 , V_17 , F_56 ( V_154 ) ) ) {
F_11 ( V_118
L_26 ,
F_56 ( V_154 ) ) ;
V_158 = - V_182 ;
goto V_183;
}
V_26 -> V_28 = F_59 ( V_157 ) ;
V_26 -> V_171 = V_26 -> V_28 + 0x100000 ;
V_26 -> V_168 = V_26 -> V_28 + 0x100000 ;
V_26 -> V_116 = F_63 ( V_154 ) -> V_184 ;
V_159 = V_26 -> V_28 + 0x1c0002 ;
V_4 -> V_131 = - 1 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + V_175 +
V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_176 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + V_175 +
V_53 * V_58 +
V_29 * V_177 ) ;
V_4 -> V_47 [ V_29 ] =
( V_176 +
V_53 * V_58 +
V_29 * V_177 ) ;
}
break;
#endif
case V_24 :
V_26 -> V_116 = V_172 [ V_173 ] ;
V_26 -> V_168 = F_59 ( V_185 + V_186 ) ;
V_26 -> V_28 = F_59 ( V_185 + V_187 ) ;
V_26 -> V_171 = V_26 -> V_28 + V_188 ;
V_159 = F_59 ( V_185 + V_189 + 1 ) ;
V_4 -> V_131 = - 1 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_175 +
2 * V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_176 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_175 +
2 * V_53 * V_58 +
2 * V_29 * V_177 ) ;
V_4 -> V_47 [ V_29 ] =
( V_176 +
V_53 * V_58 +
V_29 * V_177 ) ;
}
break;
default:
F_11 ( V_118 L_27 ,
V_84 ) ;
V_158 = - V_190 ;
goto V_183;
}
V_6 = (struct V_5 * ) V_26 -> V_168 ;
V_160 = ( unsigned char * ) V_159 ;
if ( V_160 [ 0x60 ] != 0xff && V_160 [ 0x64 ] != 0x00 &&
V_160 [ 0x68 ] != 0x55 && V_160 [ 0x6c ] != 0xaa ) {
F_11 ( V_118
L_28 ,
V_84 ) ;
V_158 = - V_190 ;
goto V_191;
}
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( V_160 [ V_29 * 4 ] != V_160 [ 0x3c - V_29 * 4 ] &&
V_160 [ V_29 * 4 ] != V_160 [ 0x40 + V_29 * 4 ] &&
V_160 [ 0x3c - V_29 * 4 ] != V_160 [ 0x40 + V_29 * 4 ] ) {
F_11 ( V_118 L_29
L_30 , V_84 ) ;
V_158 = - V_190 ;
goto V_191;
}
}
switch ( type ) {
case V_167 :
F_11 ( L_31 , V_84 ) ;
break;
case V_23 :
F_11 ( L_32 , V_84 ) ;
break;
case V_24 :
F_11 ( L_33 , V_84 ) ;
break;
}
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_26 -> V_35 [ V_29 ] = V_160 [ V_29 * 4 ] ;
F_11 ( L_34 , V_26 -> V_35 , V_26 -> V_116 ) ;
V_26 -> V_192 = & V_193 ;
V_26 -> V_194 = 5 * V_149 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_13 = 0 ;
V_26 -> V_195 = 0 ;
F_65 ( & V_4 -> V_136 ) ;
V_4 -> V_136 . V_88 = ( unsigned long ) V_26 ;
V_4 -> V_136 . V_196 = F_54 ;
V_158 = F_66 ( V_26 ) ;
if ( V_158 ) {
F_11 ( V_118
L_35 , V_84 ) ;
goto V_191;
}
if ( ! V_154 ) {
V_4 -> V_164 = V_163 ;
V_163 = V_26 ;
}
F_11 ( L_36 , V_84 , V_26 -> V_84 ) ;
return 0 ;
V_191:
if ( V_154 )
F_67 ( V_157 , V_17 ) ;
V_183:
F_68 ( V_26 ) ;
V_166:
return V_158 ;
}
static void T_7 F_69 ( struct V_153 * V_154 )
{
struct V_25 * V_26 = F_70 ( V_154 ) ;
T_6 V_157 , V_17 ;
F_71 ( V_26 ) ;
V_157 = F_63 ( V_154 ) -> V_180 . V_157 ;
V_17 = F_63 ( V_154 ) -> V_180 . V_181 - V_157 + 1 ;
F_67 ( V_157 , V_17 ) ;
F_68 ( V_26 ) ;
}
static int T_8 F_72 ( void )
{
int V_197 = 0 ;
if ( V_172 [ V_173 ] >= 0 ) {
if ( V_172 [ V_178 ] >= 0 ) {
if ( F_55 ( NULL , V_167 ) >= 0 )
V_197 ++ ;
} else if ( ! V_198 ) {
if ( F_55 ( NULL , V_24 ) >= 0 )
V_197 ++ ;
}
}
return ( V_197 > 0 ) ? 0 : - V_190 ;
}
static void T_7 F_73 ( void )
{
while ( V_163 ) {
struct V_25 * V_26 = V_163 ;
struct V_3 * V_4 = F_7 ( V_26 ) ;
F_71 ( V_26 ) ;
V_163 = V_4 -> V_164 ;
F_68 ( V_26 ) ;
}
}
static int T_5 F_74 ( struct V_153 * V_26 )
{
int V_93 = F_55 ( V_26 , V_23 ) ;
if ( ! V_93 )
F_75 ( V_26 ) ;
return V_93 ;
}
static int T_7 F_76 ( struct V_153 * V_26 )
{
F_77 ( V_26 ) ;
F_69 ( V_26 ) ;
return 0 ;
}
static int T_8 F_78 ( void )
{
int V_93 ;
V_93 = F_79 ( & V_199 ) ;
if ( ! V_93 )
F_72 () ;
return V_93 ;
}
static void T_7 F_80 ( void )
{
F_73 () ;
F_81 ( & V_199 ) ;
}
