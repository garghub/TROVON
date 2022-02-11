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
V_21 = ( unsigned char * ) V_18 ;
V_22 = ( const unsigned char * ) V_19 ;
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
V_22 = ( const unsigned char * ) V_19 ;
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
V_21 = ( unsigned char * ) V_18 ;
V_22 = ( const unsigned char * ) V_19 ;
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
V_22 = ( const unsigned char * ) V_19 ;
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
V_70 = F_18 ( V_26 , V_17 + 2 ) ;
if ( V_70 == 0 ) {
V_26 -> V_72 . V_84 ++ ;
* F_17 ( V_66 , V_59 , V_4 -> type ) = 0 ;
* F_17 ( V_66 , V_56 , V_4 -> type ) =
( ( V_4 -> V_54 [ V_68 ] >> 16 ) &
0xff ) | V_57 ;
V_4 -> V_30 = ( V_68 + 1 ) & V_85 ;
return 0 ;
}
V_26 -> V_72 . V_86 += V_17 ;
F_19 ( V_70 , 2 ) ;
F_20 ( V_70 , V_17 ) ;
F_5 ( V_4 -> type , V_70 -> V_87 ,
V_4 -> V_60 [ V_68 ] , V_17 ) ;
V_70 -> V_88 = F_21 ( V_70 , V_26 ) ;
F_22 ( V_70 ) ;
V_26 -> V_72 . V_89 ++ ;
}
* F_17 ( V_66 , V_59 , V_4 -> type ) = 0 ;
* F_17 ( V_66 , V_50 , V_4 -> type ) = - V_58 | 0xf000 ;
* F_17 ( V_66 , V_56 , V_4 -> type ) =
( ( V_4 -> V_54 [ V_68 ] >> 16 ) & 0xff ) | V_57 ;
V_4 -> V_30 = ( V_68 + 1 ) & V_85 ;
}
return 0 ;
}
static void F_23 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
volatile T_2 * V_90 ;
int V_29 , V_91 ;
int V_92 ;
V_91 = V_4 -> V_33 ;
F_24 ( & V_4 -> V_93 ) ;
for ( V_29 = V_91 ; V_29 != V_4 -> V_31 ; V_29 = V_91 ) {
V_90 = F_9 ( V_27 , V_42 [ V_29 ] , V_4 -> type ) ;
if ( * F_25 ( V_90 , V_49 , V_4 -> type ) & V_94 )
break;
if ( * F_25 ( V_90 , V_49 , V_4 -> type ) & V_95 ) {
V_92 = * F_25 ( V_90 , V_51 , V_4 -> type ) ;
V_26 -> V_72 . V_96 ++ ;
if ( V_92 & V_97 )
V_26 -> V_72 . V_98 ++ ;
if ( V_92 & V_99 )
V_26 -> V_72 . V_100 ++ ;
if ( V_92 & V_101 ) {
V_26 -> V_72 . V_102 ++ ;
F_11 ( L_14 , V_26 -> V_103 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
goto V_105;
}
if ( V_92 & ( V_106 | V_107 ) ) {
V_26 -> V_72 . V_108 ++ ;
F_11 ( L_15 ,
V_26 -> V_103 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
goto V_105;
}
} else if ( ( * F_25 ( V_90 , V_49 , V_4 -> type ) & V_109 ) ==
V_109 ) {
* F_25 ( V_90 , V_49 , V_4 -> type ) &= ~ ( V_109 ) ;
if ( * F_25 ( V_90 , V_49 , V_4 -> type ) & V_110 )
V_26 -> V_72 . V_111 ++ ;
if ( * F_25 ( V_90 , V_49 , V_4 -> type ) & V_112 )
V_26 -> V_72 . V_111 += 2 ;
V_26 -> V_72 . V_113 ++ ;
}
V_91 = ( V_91 + 1 ) & V_114 ;
}
V_4 -> V_33 = V_91 ;
V_105:
if ( F_26 ( V_26 ) &&
V_115 > 0 )
F_27 ( V_26 ) ;
F_28 ( & V_4 -> V_93 ) ;
}
static T_3 F_29 ( int V_116 , void * V_117 )
{
struct V_25 * V_26 = V_117 ;
F_11 ( V_118 L_16 , V_26 -> V_103 ) ;
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
V_26 -> V_72 . V_96 ++ ;
if ( V_120 & V_125 )
V_26 -> V_72 . V_74 ++ ;
if ( V_120 & V_127 ) {
F_11 ( L_17 , V_26 -> V_103 , V_120 ) ;
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
int V_92 = 0 ;
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
if ( F_33 ( V_26 -> V_116 , F_30 , 0 , L_18 , V_26 ) ) {
F_11 ( L_19 , V_26 -> V_103 , V_26 -> V_116 ) ;
return - V_130 ;
}
if ( V_4 -> V_131 >= 0 ) {
unsigned long V_132 ;
if ( F_33 ( V_4 -> V_131 , F_29 , V_133 ,
L_20 , V_26 ) ) {
F_34 ( V_26 -> V_116 , V_26 ) ;
F_11 ( L_21 , V_26 -> V_103 ,
V_4 -> V_131 ) ;
return - V_130 ;
}
F_35 ( & V_134 , V_132 ) ;
F_36 () ;
F_37 ( V_135 ,
F_38 ( V_135 ) | V_136 ) ;
F_36 () ;
F_39 ( & V_134 , V_132 ) ;
}
V_92 = F_13 ( V_4 ) ;
return V_92 ;
}
static int F_40 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
F_8 ( V_26 ) ;
F_41 ( & V_4 -> V_137 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
if ( V_4 -> V_131 >= 0 ) {
unsigned long V_132 ;
F_35 ( & V_134 , V_132 ) ;
F_36 () ;
F_37 ( V_135 ,
F_38 ( V_135 ) & ~ V_136 ) ;
F_42 () ;
F_39 ( & V_134 , V_132 ) ;
F_34 ( V_4 -> V_131 , V_26 ) ;
}
F_34 ( V_26 -> V_116 , V_26 ) ;
return 0 ;
}
static inline int F_43 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
int V_92 ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
F_3 ( V_4 ) ;
V_26 -> V_138 = V_139 ;
V_92 = F_13 ( V_4 ) ;
return V_92 ;
}
static void F_44 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile struct V_5 * V_6 = V_4 -> V_6 ;
F_11 ( V_118 L_22 ,
V_26 -> V_103 , V_6 -> V_10 ) ;
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
if ( V_17 < V_140 ) {
if ( F_46 ( V_70 , V_140 ) )
return V_141 ;
V_17 = V_140 ;
}
V_26 -> V_72 . V_142 += V_17 ;
F_35 ( & V_4 -> V_93 , V_132 ) ;
V_68 = V_4 -> V_31 ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_50 , V_4 -> type ) = ( - V_17 ) ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_51 , V_4 -> type ) = 0 ;
F_4 ( V_4 -> type , V_4 -> V_52 [ V_68 ] , V_70 -> V_87 , V_17 ) ;
* F_9 ( V_27 , V_42 [ V_68 ] . V_49 , V_4 -> type ) =
( ( V_4 -> V_47 [ V_68 ] >> 16 ) & 0xff ) |
( V_109 | V_94 ) ;
V_4 -> V_31 = ( V_68 + 1 ) & V_114 ;
if ( V_115 <= 0 )
F_8 ( V_26 ) ;
F_1 ( & V_6 -> V_10 , V_65 | V_143 ) ;
F_39 ( & V_4 -> V_93 , V_132 ) ;
F_47 ( V_70 ) ;
return V_141 ;
}
static void F_48 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_7 ( V_26 ) ;
volatile T_2 * V_27 = ( volatile T_2 * ) V_26 -> V_28 ;
struct V_144 * V_145 ;
T_4 V_146 ;
if ( V_26 -> V_132 & V_147 ) {
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
V_146 = F_50 ( V_148 , V_145 -> V_149 ) ;
V_146 = V_146 >> 26 ;
* F_9 ( V_27 , V_129 [ V_146 >> 4 ] , V_4 -> type ) |= 1 << ( V_146 & 0xf ) ;
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
F_53 ( & V_4 -> V_137 , V_139 + 4 * V_150 / 100 ) ;
F_27 ( V_26 ) ;
return;
}
F_8 ( V_26 ) ;
F_1 ( & V_6 -> V_8 , V_14 ) ;
F_1 ( & V_6 -> V_10 , V_104 ) ;
F_6 ( V_26 ) ;
if ( V_26 -> V_132 & V_151 ) {
* F_9 ( V_27 , V_128 , V_4 -> type ) |= V_152 ;
} else {
* F_9 ( V_27 , V_128 , V_4 -> type ) &= ~ V_152 ;
F_48 ( V_26 ) ;
}
F_3 ( V_4 ) ;
F_13 ( V_4 ) ;
F_27 ( V_26 ) ;
}
static void F_54 ( unsigned long V_153 )
{
struct V_25 * V_26 = (struct V_25 * ) V_153 ;
F_51 ( V_26 ) ;
}
static int F_55 ( struct V_154 * V_155 , const int type )
{
static unsigned V_156 ;
static const char V_157 [] = L_23 ;
char V_103 [ 10 ] ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
volatile struct V_5 * V_6 ;
T_5 V_158 = 0 , V_17 = 0 ;
int V_29 , V_159 ;
unsigned long V_160 ;
unsigned char * V_161 ;
if ( V_162 && V_156 ++ == 0 )
F_11 ( V_163 ) ;
if ( V_155 )
snprintf ( V_103 , sizeof( V_103 ) , L_8 , F_56 ( V_155 ) ) ;
else {
V_29 = 0 ;
V_26 = V_164 ;
while ( V_26 ) {
V_29 ++ ;
V_4 = F_7 ( V_26 ) ;
V_26 = V_4 -> V_165 ;
}
snprintf ( V_103 , sizeof( V_103 ) , V_157 , V_29 ) ;
}
V_26 = F_57 ( sizeof( struct V_3 ) ) ;
if ( ! V_26 ) {
V_159 = - V_166 ;
goto V_167;
}
V_4 = F_7 ( V_26 ) ;
F_58 ( & V_4 -> V_93 ) ;
V_4 -> type = type ;
switch ( type ) {
case V_168 :
V_26 -> V_169 = F_59 ( V_170 + V_171 ) ;
V_26 -> V_28 = F_59 ( 0x00020000 ) ;
V_26 -> V_172 = V_26 -> V_28 + 0x00020000 ;
V_26 -> V_116 = V_173 [ V_174 ] ;
V_160 = F_59 ( V_170 + V_175 ) ;
memset ( ( void * ) V_26 -> V_28 , 0 ,
V_26 -> V_172 - V_26 -> V_28 ) ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_176 +
2 * V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_177 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_176 +
2 * V_53 * V_58 +
2 * V_29 * V_178 ) ;
V_4 -> V_47 [ V_29 ] =
( V_177 +
V_53 * V_58 +
V_29 * V_178 ) ;
}
V_4 -> V_131 = V_173 [ V_179 ] ;
F_37 ( V_180 ,
F_60 ( V_26 -> V_28 ) << 3 ) ;
break;
#ifdef F_61
case V_23 :
F_62 ( V_155 , V_26 ) ;
V_158 = F_63 ( V_155 ) -> V_181 . V_158 ;
V_17 = F_63 ( V_155 ) -> V_181 . V_182 - V_158 + 1 ;
if ( ! F_64 ( V_158 , V_17 , F_56 ( V_155 ) ) ) {
F_11 ( V_118
L_24 ,
F_56 ( V_155 ) ) ;
V_159 = - V_183 ;
goto V_184;
}
V_26 -> V_28 = F_59 ( V_158 ) ;
V_26 -> V_172 = V_26 -> V_28 + 0x100000 ;
V_26 -> V_169 = V_26 -> V_28 + 0x100000 ;
V_26 -> V_116 = F_63 ( V_155 ) -> V_185 ;
V_160 = V_26 -> V_28 + 0x1c0002 ;
V_4 -> V_131 = - 1 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + V_176 +
V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_177 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + V_176 +
V_53 * V_58 +
V_29 * V_178 ) ;
V_4 -> V_47 [ V_29 ] =
( V_177 +
V_53 * V_58 +
V_29 * V_178 ) ;
}
break;
#endif
case V_24 :
V_26 -> V_116 = V_173 [ V_174 ] ;
V_26 -> V_169 = F_59 ( V_186 + V_187 ) ;
V_26 -> V_28 = F_59 ( V_186 + V_188 ) ;
V_26 -> V_172 = V_26 -> V_28 + V_189 ;
V_160 = F_59 ( V_186 + V_190 + 1 ) ;
V_4 -> V_131 = - 1 ;
for ( V_29 = 0 ; V_29 < V_53 ; V_29 ++ ) {
V_4 -> V_60 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_176 +
2 * V_29 * V_58 ) ;
V_4 -> V_54 [ V_29 ] =
( V_177 + V_29 * V_58 ) ;
}
for ( V_29 = 0 ; V_29 < V_46 ; V_29 ++ ) {
V_4 -> V_52 [ V_29 ] =
( char * ) ( V_26 -> V_28 + 2 * V_176 +
2 * V_53 * V_58 +
2 * V_29 * V_178 ) ;
V_4 -> V_47 [ V_29 ] =
( V_177 +
V_53 * V_58 +
V_29 * V_178 ) ;
}
break;
default:
F_11 ( V_118 L_25 ,
V_103 ) ;
V_159 = - V_191 ;
goto V_184;
}
V_6 = (struct V_5 * ) V_26 -> V_169 ;
V_161 = ( unsigned char * ) V_160 ;
if ( V_161 [ 0x60 ] != 0xff && V_161 [ 0x64 ] != 0x00 &&
V_161 [ 0x68 ] != 0x55 && V_161 [ 0x6c ] != 0xaa ) {
F_11 ( V_118
L_26 ,
V_103 ) ;
V_159 = - V_191 ;
goto V_192;
}
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( V_161 [ V_29 * 4 ] != V_161 [ 0x3c - V_29 * 4 ] &&
V_161 [ V_29 * 4 ] != V_161 [ 0x40 + V_29 * 4 ] &&
V_161 [ 0x3c - V_29 * 4 ] != V_161 [ 0x40 + V_29 * 4 ] ) {
F_11 ( V_118 L_27
L_28 , V_103 ) ;
V_159 = - V_191 ;
goto V_192;
}
}
switch ( type ) {
case V_168 :
F_11 ( L_29 , V_103 ) ;
break;
case V_23 :
F_11 ( L_30 , V_103 ) ;
break;
case V_24 :
F_11 ( L_31 , V_103 ) ;
break;
}
for ( V_29 = 0 ; V_29 < 6 ; V_29 ++ )
V_26 -> V_35 [ V_29 ] = V_161 [ V_29 * 4 ] ;
F_11 ( L_32 , V_26 -> V_35 , V_26 -> V_116 ) ;
V_26 -> V_193 = & V_194 ;
V_26 -> V_195 = 5 * V_150 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_13 = 0 ;
V_26 -> V_196 = 0 ;
F_65 ( & V_4 -> V_137 ) ;
V_4 -> V_137 . V_87 = ( unsigned long ) V_26 ;
V_4 -> V_137 . V_197 = F_54 ;
V_159 = F_66 ( V_26 ) ;
if ( V_159 ) {
F_11 ( V_118
L_33 , V_103 ) ;
goto V_192;
}
if ( ! V_155 ) {
V_4 -> V_165 = V_164 ;
V_164 = V_26 ;
}
F_11 ( L_34 , V_103 , V_26 -> V_103 ) ;
return 0 ;
V_192:
if ( V_155 )
F_67 ( V_158 , V_17 ) ;
V_184:
F_68 ( V_26 ) ;
V_167:
return V_159 ;
}
static void T_6 F_69 ( struct V_154 * V_155 )
{
struct V_25 * V_26 = F_70 ( V_155 ) ;
T_5 V_158 , V_17 ;
F_71 ( V_26 ) ;
V_158 = F_63 ( V_155 ) -> V_181 . V_158 ;
V_17 = F_63 ( V_155 ) -> V_181 . V_182 - V_158 + 1 ;
F_67 ( V_158 , V_17 ) ;
F_68 ( V_26 ) ;
}
static int T_7 F_72 ( void )
{
int V_198 = 0 ;
if ( V_173 [ V_174 ] >= 0 ) {
if ( V_173 [ V_179 ] >= 0 ) {
if ( F_55 ( NULL , V_168 ) >= 0 )
V_198 ++ ;
} else if ( ! V_199 ) {
if ( F_55 ( NULL , V_24 ) >= 0 )
V_198 ++ ;
}
}
return ( V_198 > 0 ) ? 0 : - V_191 ;
}
static void T_6 F_73 ( void )
{
while ( V_164 ) {
struct V_25 * V_26 = V_164 ;
struct V_3 * V_4 = F_7 ( V_26 ) ;
F_71 ( V_26 ) ;
V_164 = V_4 -> V_165 ;
F_68 ( V_26 ) ;
}
}
static int F_74 ( struct V_154 * V_26 )
{
int V_92 = F_55 ( V_26 , V_23 ) ;
if ( ! V_92 )
F_75 ( V_26 ) ;
return V_92 ;
}
static int T_6 F_76 ( struct V_154 * V_26 )
{
F_77 ( V_26 ) ;
F_69 ( V_26 ) ;
return 0 ;
}
static int T_7 F_78 ( void )
{
int V_92 ;
V_92 = F_79 ( & V_200 ) ;
if ( ! V_92 )
F_72 () ;
return V_92 ;
}
static void T_6 F_80 ( void )
{
F_73 () ;
F_81 ( & V_200 ) ;
}
