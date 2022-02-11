static inline T_1
F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
register short int V_4 = 0 ;
while ( ( ( ( V_3 = F_2 ( V_5 ) ) & V_6 ) == 0 ) && ( V_4 <= 1000 ) )
++ V_4 ;
#ifdef F_3
V_7 += V_4 ;
#endif
return V_3 & 0xf0 ;
}
static inline void
F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
F_1 ( V_2 ) ;
if ( V_8 == V_9 )
F_5 ( V_10 , V_11 ) ;
F_5 ( V_8 , V_12 ) ;
F_5 ( V_10 ^ V_13 , V_11 ) ;
F_1 ( V_2 ) ;
F_5 ( V_10 , V_11 ) ;
}
static inline void
F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
F_1 ( V_2 ) ;
F_5 ( V_3 , V_12 ) ;
F_7 ( V_2 ) ;
}
static inline T_1
F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
V_3 |= F_1 ( V_2 ) >> 4 ;
return V_3 ;
}
static inline void
F_9 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 , int V_16 )
{
#ifndef F_10
T_1 V_17 = V_10 ^ ( V_18 | V_19 ) ;
T_1 V_20 = V_10 ;
#else
#ifdef F_3
int V_21 = V_15 ;
#endif
#endif
#ifdef F_10
#ifdef F_3
V_7 = 0 ;
#endif
for ( ; V_15 > 0 ; -- V_15 , ++ V_14 ) {
F_6 ( V_2 , * V_14 ) ;
}
for ( V_15 = V_16 ; V_15 > 0 ; -- V_15 , ++ V_14 ) {
F_6 ( V_2 , 0 ) ;
}
F_4 ( V_2 , V_9 ) ;
#ifdef F_3
F_11 ( L_1 , V_7 / ( ( V_21 ? V_21 : 1 ) ) ) ;
#endif
#else
for ( ; V_15 > 0 ; V_15 -= 2 ) {
F_5 ( * V_14 ++ , V_12 ) ;
F_5 ( V_17 , V_11 ) ;
F_5 ( * V_14 ++ , V_12 ) ;
F_5 ( V_20 , V_11 ) ;
}
F_4 ( V_2 , V_9 ) ;
#endif
}
static inline void
F_12 ( struct V_1 * V_2 , T_1 * V_22 , int V_15 )
{
#ifndef F_10
T_1 V_3 ;
T_1 V_17 = V_10 ^ ( V_18 | V_19 ) ;
T_1 V_20 = V_10 ;
#else
#ifdef F_3
int V_21 = V_15 ;
V_7 = 0 ;
#endif
#endif
#ifdef F_10
while ( V_15 -- > 0 ) {
* V_22 ++ = F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
}
#ifdef F_3
F_11 ( L_2 , V_7 / ( 2 * ( V_21 ? V_21 : 1 ) ) ) ;
#endif
#else
while ( V_15 -- > 0 ) {
V_3 = F_2 ( V_5 ) & 0xf0 ;
F_5 ( V_17 , V_11 ) ;
* V_22 ++ = V_3 | F_2 ( V_5 ) >> 4 ;
F_5 ( V_20 , V_11 ) ;
}
#endif
}
static inline void
F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_23 , V_12 ) ;
F_5 ( V_10 ^ V_13 , V_11 ) ;
F_1 ( V_2 ) ;
#ifdef F_10
F_5 ( V_24 , V_12 ) ;
#else
F_5 ( 0 , V_12 ) ;
#endif
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
#ifdef F_10
F_5 ( V_25 , V_12 ) ;
#else
F_5 ( 0 , V_12 ) ;
#endif
F_7 ( V_2 ) ;
}
static inline void
F_14 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_3 )
{
F_1 ( V_2 ) ;
F_5 ( V_26 , V_12 ) ;
F_5 ( V_10 ^ V_13 , V_11 ) ;
F_6 ( V_2 , V_3 ) ;
}
static inline T_1
F_15 ( struct V_1 * V_2 , T_1 V_26 )
{
T_1 V_3 ;
F_4 ( V_2 , V_26 ) ;
V_3 = F_8 ( V_2 ) ;
F_4 ( V_2 , V_9 ) ;
return V_3 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_27 = F_17 ( V_2 -> V_28 , V_29 , 0 , V_2 -> V_30 , V_2 ) ;
if ( V_27 ) {
F_11 ( V_31 L_3 , V_2 -> V_30 , V_2 -> V_28 ) ;
return V_27 ;
}
if ( F_18 ( V_2 ) ) {
V_27 = - V_32 ;
goto V_33;
}
F_19 ( V_2 ) ;
return 0 ;
V_33:
F_20 ( V_2 -> V_28 , V_2 ) ;
return V_27 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_14 ( V_2 , V_34 , V_35 ) ;
F_20 ( V_2 -> V_28 , V_2 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( ! F_24 ( V_2 ) || V_2 -> V_36 & ( V_37 | V_38 ) )
{
F_14 ( V_2 , V_34 , ( V_39 & ~ V_40 ) | V_41 ) ;
}
else
{
F_14 ( V_2 , V_34 , V_39 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_11 ( V_42 L_4 , V_2 -> V_30 , L_5 ) ;
if ( ! F_18 ( V_2 ) )
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_43 * V_44 , struct V_1 * V_2 )
{
unsigned long V_36 ;
int V_45 ;
T_1 * V_14 = V_44 -> V_22 ;
T_1 V_46 ;
V_46 = F_28 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( ( V_45 = V_44 -> V_45 ) < V_47 )
V_45 = V_47 ;
if ( V_45 & 1 )
++ V_45 ;
F_29 ( & V_48 , V_36 ) ;
F_30 ( L_6 ,
( int ) V_44 -> V_45 , V_46 ) ;
switch ( V_46 ) {
default:
case V_49 :
F_4 ( V_2 , V_50 | V_51 ) ;
V_46 |= V_52 ;
break;
case V_52 :
F_4 ( V_2 , V_50 | V_53 ) ;
V_46 |= V_49 ;
break;
case ( V_52 | V_49 ) :
F_11 ( V_42 L_7 , V_2 -> V_30 ) ;
F_31 ( & V_48 , V_36 ) ;
return V_54 ;
}
F_9 ( V_2 , V_14 , V_44 -> V_45 , V_45 - V_44 -> V_45 ) ;
if( ! ( V_46 == ( V_52 | V_49 ) ) )
F_26 ( V_2 ) ;
V_2 -> V_55 . V_56 ++ ;
F_31 ( & V_48 , V_36 ) ;
F_32 ( V_44 ) ;
return V_57 ;
}
static T_2
V_29 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_60 ;
int V_61 = 0 ;
int V_62 = 0 ;
F_33 ( & V_48 ) ;
V_60 = F_15 ( V_2 , V_63 ) ;
F_30 ( L_8 , V_60 ) ;
if ( V_60 & V_64 ) {
do {
V_62 = F_34 ( V_2 ) ;
F_30 ( L_9 , V_62 ) ;
}
while ( V_62 && ( ++ V_61 < 100 ) );
}
if( F_28 ( V_2 ) != ( V_52 | V_49 ) )
F_26 ( V_2 ) ;
F_35 ( & V_48 ) ;
return V_65 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_66 {
T_1 V_67 ;
T_1 V_68 ;
unsigned short V_69 ;
} V_66 ;
struct V_43 * V_44 ;
int V_70 ;
T_1 * V_14 ;
T_1 V_71 ;
T_1 V_72 ;
F_30 ( L_10 , V_73 ) ;
F_4 ( V_2 , V_50 | V_74 ) ;
F_14 ( V_2 , V_75 , V_73 ) ;
F_14 ( V_2 , V_76 , 0 ) ;
F_12 ( V_2 , ( T_1 * ) & V_66 , sizeof( struct V_66 ) ) ;
F_30 ( L_11 ,
V_66 . V_67 , V_66 . V_68 ,
V_66 . V_69 ) ;
V_71 = V_66 . V_68 ;
if ( ( V_71 < V_77 ) || ( V_78 < V_71 ) ) {
F_11 ( V_42 L_12 , V_2 -> V_30 ) ;
F_18 ( V_2 ) ;
F_26 ( V_2 ) ;
V_2 -> V_55 . V_79 ++ ;
return 0 ;
}
V_71 = V_73 +
( ( V_66 . V_69 + ( 4 - 1 + 0x100 ) ) >> 8 ) ;
if ( V_71 > V_78 )
V_71 -= ( V_78 - V_77 + 1 ) ;
if ( V_71 != V_66 . V_68 ) {
F_11 ( V_42 L_13 , V_2 -> V_30 ) ;
V_73 = V_66 . V_68 ;
F_4 ( V_2 , V_9 ) ;
F_14 ( V_2 , V_80 , V_73 ) ;
V_2 -> V_55 . V_79 ++ ;
return 0 ;
}
V_73 = V_71 ;
V_70 = V_66 . V_69 - 4 ;
if ( ( V_70 < V_47 ) || ( V_81 < V_70 ) ) {
F_11 ( V_42 L_14 , V_2 -> V_30 , V_70 ) ;
}
else {
V_44 = F_36 ( V_70 + 2 ) ;
if ( V_44 == NULL ) {
F_11 ( V_42 L_15 , V_2 -> V_30 , V_70 ) ;
V_2 -> V_55 . V_82 ++ ;
}
else {
F_37 ( V_44 , 2 ) ;
V_14 = F_38 ( V_44 , V_70 ) ;
F_12 ( V_2 , V_14 , V_70 ) ;
F_30 ( L_16 , V_70 ) ;
V_44 -> V_83 = F_39 ( V_44 , V_2 ) ;
F_40 ( V_44 ) ;
V_2 -> V_55 . V_84 ++ ;
V_2 -> V_55 . V_85 += V_70 ;
}
}
V_72 = F_15 ( V_2 , V_86 ) ;
F_14 ( V_2 , V_80 , V_73 ) ;
F_30 ( L_17 , V_73 , V_72 ) ;
return V_73 != V_72 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_87 ;
static int V_88 ;
if ( ( V_89 . V_90 == 3 ) || ( V_89 . V_90 == 0 ) ) {
V_91 = V_92 ;
if ( V_89 . V_93 != 1 )
V_91 |= V_94 ;
}
else if ( V_89 . V_90 == 2 ) {
V_91 = V_92 | V_94 ;
}
if ( V_95 )
V_91 = V_92 | V_94 ;
if ( V_96 )
V_91 = V_92 ;
F_4 ( V_2 , V_50 | V_97 | V_98 ) ;
F_4 ( V_2 , V_50 | V_97 ) ;
F_14 ( V_2 , V_99 , V_100 ) ;
F_14 ( V_2 , V_34 , V_35 ) ;
for ( V_87 = 0 ; V_87 < 6 ; ++ V_87 ) {
F_14 ( V_2 , V_101 + V_87 , V_2 -> V_102 [ V_87 ] ) ;
}
F_14 ( V_2 , V_103 , V_91 ) ;
V_73 = V_77 = V_104 ;
if ( V_89 . V_105 )
V_78 = V_89 . V_105 - 1 ;
else
V_78 = 255 ;
F_14 ( V_2 , V_106 , V_77 ) ;
F_14 ( V_2 , V_107 , V_78 ) ;
F_14 ( V_2 , V_108 , V_77 ) ;
F_4 ( V_2 , V_109 | V_77 ) ;
F_4 ( V_2 , V_9 ) ;
F_13 ( V_2 ) ;
#define F_41 ( 0 | TXSUC | T16 | 0 | RXCRC | RXSHORT | 0 | 0 )
#define F_42 ( 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 )
if ( ( ( V_87 = F_15 ( V_2 , V_63 ) ) & F_41 ) != F_42 ) {
F_11 ( V_31 L_18
#ifdef F_43
L_19
#endif
L_20 , V_2 -> V_30 , V_87 ) ;
#ifdef F_43
V_2 -> V_36 &= ~ V_110 ;
F_21 ( V_2 ) ;
#endif
V_88 = 1 ;
return 1 ;
}
if ( V_88 ) {
F_11 ( V_42 L_21 , V_2 -> V_30 ) ;
V_88 = 0 ;
}
F_14 ( V_2 , V_34 , V_39 ) ;
return 0 ;
}
struct V_1 * T_3 F_44 ( int V_111 )
{
T_1 V_112 = 0xa5 ;
struct V_1 * V_2 ;
int V_113 = - V_114 ;
int V_87 ;
V_2 = F_45 ( 0 ) ;
if ( ! V_2 )
goto V_115;
F_46 ( & V_48 ) ;
V_2 -> V_116 = V_117 ;
V_2 -> V_28 = V_28 ;
if ( V_111 >= 0 ) {
sprintf ( V_2 -> V_30 , L_22 , V_111 ) ;
F_47 ( V_2 ) ;
}
F_30 ( L_23 , V_118 ) ;
F_11 ( V_119 L_24 ) ;
if ( ! F_48 ( V_2 -> V_116 , 3 , L_25 ) ) {
F_11 ( L_26 , V_2 -> V_116 ) ;
V_113 = - V_120 ;
goto V_121;
}
V_10 = V_122 ;
F_14 ( V_2 , V_103 , V_91 ) ;
F_14 ( V_2 , V_108 , V_112 ) ;
V_112 = F_15 ( V_2 , V_86 ) ;
if ( ( V_112 != 0xa5 ) || ( F_49 ( V_2 ) != 0 ) ) {
F_11 ( L_27 ) ;
V_113 = - V_123 ;
goto V_124;
}
V_2 -> V_102 [ 0 ] = V_89 . V_125 [ 0 ] ;
for ( V_87 = 1 ; V_87 < V_126 ; V_87 ++ ) {
V_2 -> V_102 [ V_87 ] = V_89 . V_125 [ V_87 ] ;
V_2 -> V_127 [ V_87 ] = 0xff ;
}
F_11 ( L_28 , V_2 -> V_102 ) ;
F_11 ( L_29 ,
( V_89 . V_105 ) ? ( V_89 . V_105 >> 2 ) : 64 ) ;
if ( V_89 . V_93 == 1 )
F_11 ( L_30 ) ;
else
F_11 ( L_31 ) ;
V_2 -> V_128 = & V_129 ;
V_2 -> V_130 = V_131 * 2 ;
F_30 ( L_32
L_33
L_34
L_35
L_36
L_37 , V_89 . V_105 , V_89 . V_125 ,
V_89 . V_90 , V_89 . V_93 , V_89 . V_132 ) ;
V_113 = F_50 ( V_2 ) ;
if ( V_113 )
goto V_124;
return V_2 ;
V_124:
F_51 ( V_2 -> V_116 , 3 ) ;
V_121:
F_52 ( V_2 ) ;
V_115:
return F_53 ( V_113 ) ;
}
static unsigned short T_3 F_54 ( struct V_1 * V_2 , int V_133 )
{
unsigned short V_22 ;
int V_134 ;
F_55 ( V_2 , 0 ) ; F_55 ( V_2 , 1 ) ; F_55 ( V_2 , 5 ) ; F_55 ( V_2 , 4 ) ;
for ( V_134 = 9 ; V_134 > 0 ; -- V_134 , V_133 <<= 1 ) {
if ( V_133 & 0x0100 ) {
F_55 ( V_2 , 6 ) ; F_55 ( V_2 , 7 ) ; F_55 ( V_2 , 7 ) ; F_55 ( V_2 , 6 ) ;
}
else {
F_55 ( V_2 , 4 ) ; F_55 ( V_2 , 5 ) ; F_55 ( V_2 , 5 ) ; F_55 ( V_2 , 4 ) ;
}
}
for ( V_22 = 0 , V_134 = 16 ; V_134 > 0 ; -- V_134 ) {
F_55 ( V_2 , 4 ) ; F_55 ( V_2 , 5 ) ; F_55 ( V_2 , 5 ) ; F_55 ( V_2 , 4 ) ;
V_22 = ( V_22 << 1 ) | ( ( F_15 ( V_2 , V_63 ) & V_135 ) >> 7 ) ;
}
F_55 ( V_2 , 0 ) ; F_55 ( V_2 , 1 ) ; F_55 ( V_2 , 1 ) ; F_55 ( V_2 , 0 ) ;
return V_22 ;
}
static int T_3 F_49 ( struct V_1 * V_2 )
{
unsigned short V_136 ;
V_136 = F_54 ( V_2 , 0x1aa ) ;
if ( ! V_137 && ( V_136 != F_56 ( 0x0080 ) ) )
return - 1 ;
V_89 . V_125 [ 0 ] = V_136 & 0xff ;
V_89 . V_125 [ 1 ] = V_136 >> 8 ;
V_136 = F_54 ( V_2 , 0x1ab ) ;
if ( ! V_137 && ( ( V_136 & 0xff ) != 0xc8 ) )
return - 1 ;
V_89 . V_125 [ 2 ] = V_136 & 0xff ;
V_89 . V_125 [ 3 ] = V_136 >> 8 ;
V_136 = F_54 ( V_2 , 0x1ac ) ;
V_89 . V_125 [ 4 ] = V_136 & 0xff ;
V_89 . V_125 [ 5 ] = V_136 >> 8 ;
V_136 = F_54 ( V_2 , 0x1ad ) ;
V_89 . V_105 = ( V_136 >> 8 ) ;
V_136 = F_54 ( V_2 , 0x1ae ) ;
V_89 . V_90 = ( V_136 & 0xff ) ;
V_136 = F_54 ( V_2 , 0x1af ) ;
V_89 . V_93 = ( V_136 & 0xff ) ;
V_136 = F_54 ( V_2 , 0x1a8 ) ;
V_89 . V_132 = ( V_136 >> 8 ) ;
return 0 ;
}
int T_3 F_57 ( void )
{
V_138 = F_44 ( - 1 ) ;
if ( F_58 ( V_138 ) )
return F_59 ( V_138 ) ;
return 0 ;
}
void F_60 ( void )
{
F_61 ( V_138 ) ;
F_51 ( V_138 -> V_116 , 3 ) ;
F_52 ( V_138 ) ;
}
