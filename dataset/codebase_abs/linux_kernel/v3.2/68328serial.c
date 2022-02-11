static inline int F_1 ( struct V_1 * V_2 ,
char * V_3 , const char * V_4 )
{
#ifdef F_2
static const char * V_5 =
L_1 ;
static const char * V_6 =
L_2 ;
if ( ! V_2 ) {
F_3 ( V_6 , V_3 , V_4 ) ;
return 1 ;
}
if ( V_2 -> V_7 != V_8 ) {
F_3 ( V_5 , V_3 , V_4 ) ;
return 1 ;
}
#endif
return 0 ;
}
static inline void F_4 ( struct V_1 * V_9 , int V_10 )
{
if ( V_10 ) {
} else {
}
return;
}
static inline int F_5 ( struct V_1 * V_9 )
{
unsigned long V_11 = 115200 ;
unsigned short int V_12 = V_13 [ V_9 -> line ] . V_14 ;
if ( F_6 ( V_12 , V_15 ) == 0x38 ) V_11 = 38400 ;
V_11 >>= F_6 ( V_12 , V_16 ) ;
return V_11 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_3 ) )
return;
F_8 ( V_21 ) ;
V_20 -> V_22 &= ~ V_23 ;
F_9 ( V_21 ) ;
}
static int F_10 ( char V_24 )
{
int V_21 , V_25 = 0 ;
F_8 ( V_21 ) ;
while ( ! ( V_26 & V_27 ) && ( V_25 < 1000 ) ) {
V_25 ++ ;
F_11 ( 5 ) ;
}
V_28 = V_24 ;
F_11 ( 5 ) ;
F_9 ( V_21 ) ;
return 1 ;
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_4 ) )
return;
F_8 ( V_21 ) ;
if ( V_2 -> V_29 && V_2 -> V_30 && ! ( V_20 -> V_22 & V_23 ) ) {
#ifdef F_13
V_20 -> V_22 |= V_23 | V_31 ;
#else
V_20 -> V_22 |= V_23 ;
#endif
}
F_9 ( V_21 ) ;
}
static void F_14 ( void )
{
}
static void F_15 ( struct V_1 * V_2 , unsigned short V_32 )
{
if( ( V_32 & V_33 ) && V_2 -> V_34 )
F_14 () ;
return;
}
static void F_16 ( struct V_1 * V_2 , unsigned short V_35 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned char V_24 , V_36 ;
#ifndef F_17
do {
#endif
V_24 = F_6 ( V_35 , V_37 ) ;
if( V_2 -> V_38 ) {
if( V_33 & V_35 ) {
F_15 ( V_2 , V_35 ) ;
return;
#ifdef F_18
} else if ( V_24 == 0x10 ) {
F_19 () ;
F_20 ( 0 ) ;
F_21 () ;
return;
} else if ( V_24 == 0x12 ) {
F_22 () ;
return;
#endif
}
}
if( ! V_18 )
goto V_39;
V_36 = V_40 ;
if( V_35 & V_41 ) {
V_36 = V_42 ;
F_15 ( V_2 , V_35 ) ;
} else if( V_35 & V_43 ) {
V_36 = V_44 ;
F_15 ( V_2 , V_35 ) ;
} else if( V_35 & V_45 ) {
V_36 = V_46 ;
F_15 ( V_2 , V_35 ) ;
}
F_23 ( V_18 , V_24 , V_36 ) ;
#ifndef F_17
} while( ( V_35 = V_20 -> V_47 . V_48 ) & V_49 );
#endif
F_24 ( V_18 ) ;
V_39:
return;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
if ( V_2 -> V_50 ) {
V_20 -> V_51 . V_52 . V_53 = V_2 -> V_50 ;
V_2 -> V_50 = 0 ;
goto V_54;
}
if( ( V_2 -> V_29 <= 0 ) || V_2 -> V_18 -> V_55 ) {
V_20 -> V_22 &= ~ V_31 ;
goto V_54;
}
V_20 -> V_51 . V_52 . V_53 = V_2 -> V_30 [ V_2 -> V_56 ++ ] ;
V_2 -> V_56 = V_2 -> V_56 & ( V_57 - 1 ) ;
V_2 -> V_29 -- ;
if( V_2 -> V_29 <= 0 ) {
V_20 -> V_22 &= ~ V_31 ;
goto V_54;
}
V_54:
return;
}
T_2 F_26 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 * V_20 ;
unsigned short V_35 ;
unsigned short V_60 ;
V_20 = & V_13 [ V_2 -> line ] ;
V_35 = V_20 -> V_47 . V_48 ;
#ifdef F_13
V_60 = V_20 -> V_51 . V_48 ;
if ( V_35 & V_49 ) F_16 ( V_2 , V_35 ) ;
if ( V_60 & V_27 ) F_25 ( V_2 ) ;
#else
F_16 ( V_2 , V_35 ) ;
#endif
return V_61 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( V_2 -> V_21 & V_62 )
return 0 ;
if ( ! V_2 -> V_30 ) {
V_2 -> V_30 = ( unsigned char * ) F_28 ( V_63 ) ;
if ( ! V_2 -> V_30 )
return - V_64 ;
}
F_8 ( V_21 ) ;
V_20 -> V_22 = V_65 ;
V_2 -> V_66 = 1 ;
V_20 -> V_22 = V_65 | V_67 | V_23 ;
( void ) V_20 -> V_47 . V_48 ;
#ifdef F_13
V_20 -> V_22 = V_65 | V_67 |
V_68 | V_31 ;
#else
V_20 -> V_22 = V_65 | V_67 | V_68 ;
#endif
if ( V_2 -> V_18 )
F_29 ( V_69 , & V_2 -> V_18 -> V_21 ) ;
V_2 -> V_29 = V_2 -> V_70 = V_2 -> V_56 = 0 ;
F_30 ( V_2 ) ;
V_2 -> V_21 |= V_62 ;
F_9 ( V_21 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
V_20 -> V_22 = 0 ;
if ( ! ( V_2 -> V_21 & V_62 ) )
return;
F_8 ( V_21 ) ;
if ( V_2 -> V_30 ) {
F_32 ( ( unsigned long ) V_2 -> V_30 ) ;
V_2 -> V_30 = 0 ;
}
if ( V_2 -> V_18 )
F_33 ( V_69 , & V_2 -> V_18 -> V_21 ) ;
V_2 -> V_21 &= ~ V_62 ;
F_9 ( V_21 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned short V_71 ;
unsigned short V_22 ;
unsigned V_72 ;
int V_73 ;
if ( ! V_2 -> V_18 || ! V_2 -> V_18 -> V_74 )
return;
V_72 = V_2 -> V_18 -> V_74 -> V_75 ;
if ( ! ( V_71 = V_2 -> V_71 ) )
return;
V_22 = V_20 -> V_22 ;
V_20 -> V_22 = V_22 & ~ V_23 ;
V_73 = V_72 & V_76 ;
if ( V_73 & V_77 ) {
V_73 = ( V_73 & ~ V_77 ) + V_78 ;
}
V_2 -> V_12 = V_79 [ V_73 ] ;
V_20 -> V_14 = F_34 ( V_16 , V_80 [ V_73 ] . V_81 ) |
F_34 ( V_15 , V_80 [ V_73 ] . V_82 ) ;
V_22 &= ~ ( V_83 | V_84 | V_85 | V_86 ) ;
if ( ( V_72 & V_87 ) == V_88 )
V_22 |= V_86 ;
if ( V_72 & V_89 )
V_22 |= V_85 ;
if ( V_72 & V_90 )
V_22 |= V_83 ;
if ( V_72 & V_91 )
V_22 |= V_84 ;
#ifdef F_35
if ( V_72 & V_92 ) {
V_20 -> V_51 . V_48 &= ~ V_93 ;
} else {
V_20 -> V_51 . V_48 |= V_93 ;
}
#endif
V_22 |= V_23 ;
V_20 -> V_22 = V_22 ;
return;
}
static void F_36 ( void )
{
int V_94 ;
unsigned long V_21 ;
struct V_1 * V_2 = & V_95 [ 0 ] ;
char V_96 ;
if ( V_2 == 0 ) return;
if ( V_2 -> V_30 == 0 ) return;
F_8 ( V_21 ) ;
V_94 = V_2 -> V_29 ;
while ( V_94 != 0 ) {
V_96 = V_2 -> V_30 [ V_2 -> V_56 ] ;
V_2 -> V_56 = ( V_2 -> V_56 + 1 ) & ( V_57 - 1 ) ;
V_2 -> V_29 -- ;
F_9 ( V_21 ) ;
F_10 ( V_96 ) ;
F_8 ( V_21 ) ;
V_94 = F_37 ( V_2 -> V_29 , V_94 - 1 ) ;
}
F_11 ( 5 ) ;
F_9 ( V_21 ) ;
return;
}
void F_38 ( const char * V_97 )
{
char V_96 ;
while( ( V_96 = * ( V_97 ++ ) ) != 0 ) {
if( V_96 == '\n' )
F_10 ( '\r' ) ;
F_10 ( V_96 ) ;
}
F_36 () ;
return;
}
static void F_39 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_5 ) )
return;
V_2 -> V_38 = ( V_18 -> V_74 -> V_98 == V_99 ) ;
F_3 ( L_6 , V_2 -> line , V_2 -> V_38 ? L_7 : L_8 ) ;
}
static int F_40 ( struct V_17 * V_18 ,
const unsigned char * V_100 , int V_101 )
{
int V_96 , V_102 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_9 ) )
return 0 ;
if ( ! V_18 || ! V_2 -> V_30 )
return 0 ;
F_41 ( V_21 ) ;
while ( 1 ) {
F_42 () ;
V_96 = F_43 ( int , V_101 , F_37 ( V_57 - V_2 -> V_29 - 1 ,
V_57 - V_2 -> V_70 ) ) ;
F_9 ( V_21 ) ;
if ( V_96 <= 0 )
break;
memcpy ( V_2 -> V_30 + V_2 -> V_70 , V_100 , V_96 ) ;
F_42 () ;
V_2 -> V_70 = ( V_2 -> V_70 + V_96 ) & ( V_57 - 1 ) ;
V_2 -> V_29 += V_96 ;
F_9 ( V_21 ) ;
V_100 += V_96 ;
V_101 -= V_96 ;
V_102 += V_96 ;
}
if ( V_2 -> V_29 && ! V_18 -> V_55 && ! V_18 -> V_103 ) {
F_42 () ;
#ifndef F_13
while( V_2 -> V_29 ) {
#endif
V_20 -> V_22 |= V_23 ;
#ifdef F_13
V_20 -> V_22 |= V_31 ;
#else
while ( ! ( V_20 -> V_51 . V_48 & V_27 ) ) F_11 ( 5 ) ;
#endif
if ( V_20 -> V_51 . V_48 & V_27 ) {
V_20 -> V_51 . V_52 . V_53 = V_2 -> V_30 [ V_2 -> V_56 ++ ] ;
V_2 -> V_56 = V_2 -> V_56 & ( V_57 - 1 ) ;
V_2 -> V_29 -- ;
}
#ifndef F_13
}
#endif
F_9 ( V_21 ) ;
}
return V_102 ;
}
static int F_44 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
int V_104 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_10 ) )
return 0 ;
V_104 = V_57 - V_2 -> V_29 - 1 ;
if ( V_104 < 0 )
V_104 = 0 ;
return V_104 ;
}
static int F_45 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_11 ) )
return 0 ;
return V_2 -> V_29 ;
}
static void F_46 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_12 ) )
return;
F_8 ( V_21 ) ;
V_2 -> V_29 = V_2 -> V_70 = V_2 -> V_56 = 0 ;
F_9 ( V_21 ) ;
F_47 ( V_18 ) ;
}
static void F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_13 ) )
return;
if ( F_49 ( V_18 ) )
V_2 -> V_50 = F_50 ( V_18 ) ;
}
static void F_51 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_14 ) )
return;
if ( F_49 ( V_18 ) ) {
if ( V_2 -> V_50 )
V_2 -> V_50 = 0 ;
else
V_2 -> V_50 = F_52 ( V_18 ) ;
}
}
static int F_53 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_105 V_107 ;
if ( ! V_106 )
return - V_108 ;
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_107 . type = V_2 -> type ;
V_107 . line = V_2 -> line ;
V_107 . V_71 = V_2 -> V_71 ;
V_107 . V_58 = V_2 -> V_58 ;
V_107 . V_21 = V_2 -> V_21 ;
V_107 . V_109 = V_2 -> V_109 ;
V_107 . V_110 = V_2 -> V_110 ;
V_107 . V_111 = V_2 -> V_111 ;
V_107 . V_112 = V_2 -> V_112 ;
if ( F_54 ( V_106 , & V_107 , sizeof( * V_106 ) ) )
return - V_108 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_105 * V_113 )
{
struct V_105 V_114 ;
struct V_1 V_115 ;
int V_116 = 0 ;
if ( ! V_113 )
return - V_108 ;
if ( F_56 ( & V_114 , V_113 , sizeof( V_114 ) ) )
return - V_108 ;
V_115 = * V_2 ;
if ( ! F_57 ( V_117 ) ) {
if ( ( V_114 . V_109 != V_2 -> V_109 ) ||
( V_114 . type != V_2 -> type ) ||
( V_114 . V_110 != V_2 -> V_110 ) ||
( ( V_114 . V_21 & ~ V_118 ) !=
( V_2 -> V_21 & ~ V_118 ) ) )
return - V_119 ;
V_2 -> V_21 = ( ( V_2 -> V_21 & ~ V_118 ) |
( V_114 . V_21 & V_118 ) ) ;
V_2 -> V_112 = V_114 . V_112 ;
goto V_120;
}
if ( V_2 -> V_101 > 1 )
return - V_121 ;
V_2 -> V_109 = V_114 . V_109 ;
V_2 -> V_21 = ( ( V_2 -> V_21 & ~ V_122 ) |
( V_114 . V_21 & V_122 ) ) ;
V_2 -> type = V_114 . type ;
V_2 -> V_110 = V_114 . V_110 ;
V_2 -> V_111 = V_114 . V_111 ;
V_120:
V_116 = F_27 ( V_2 ) ;
return V_116 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned int * V_123 )
{
#ifdef F_35
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
#endif
unsigned char V_32 ;
unsigned long V_21 ;
F_8 ( V_21 ) ;
#ifdef F_35
V_32 = ( V_20 -> V_51 . V_48 & V_124 ) ? 1 : 0 ;
#else
V_32 = 0 ;
#endif
F_9 ( V_21 ) ;
return F_59 ( V_32 , V_123 ) ;
}
static void F_60 ( struct V_1 * V_2 , unsigned int V_125 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( ! V_2 -> V_71 )
return;
F_8 ( V_21 ) ;
#ifdef F_13
V_20 -> V_51 . V_48 |= V_126 ;
F_61 ( V_125 ) ;
V_20 -> V_51 . V_48 &= ~ V_126 ;
#endif
F_9 ( V_21 ) ;
}
static int F_62 ( struct V_17 * V_18 ,
unsigned int V_127 , unsigned long V_128 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
int V_116 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_15 ) )
return - V_129 ;
if ( ( V_127 != V_130 ) && ( V_127 != V_131 ) &&
( V_127 != V_132 ) && ( V_127 != V_133 ) &&
( V_127 != V_134 ) && ( V_127 != V_135 ) ) {
if ( V_18 -> V_21 & ( 1 << V_69 ) )
return - V_136 ;
}
switch ( V_127 ) {
case V_137 :
V_116 = F_63 ( V_18 ) ;
if ( V_116 )
return V_116 ;
F_64 ( V_18 , 0 ) ;
if ( ! V_128 )
F_60 ( V_2 , 250 ) ;
return 0 ;
case V_138 :
V_116 = F_63 ( V_18 ) ;
if ( V_116 )
return V_116 ;
F_64 ( V_18 , 0 ) ;
F_60 ( V_2 , V_128 ? V_128 * ( 100 ) : 250 ) ;
return 0 ;
case V_130 :
return F_53 ( V_2 ,
(struct V_105 * ) V_128 ) ;
case V_131 :
return F_55 ( V_2 ,
(struct V_105 * ) V_128 ) ;
case V_139 :
return F_58 ( V_2 , ( unsigned int * ) V_128 ) ;
case V_135 :
if ( F_54 ( (struct V_1 * ) V_128 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_108 ;
return 0 ;
default:
return - V_140 ;
}
return 0 ;
}
static void F_65 ( struct V_17 * V_18 , struct V_141 * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
F_30 ( V_2 ) ;
if ( ( V_142 -> V_75 & V_92 ) &&
! ( V_18 -> V_74 -> V_75 & V_92 ) ) {
V_18 -> V_103 = 0 ;
F_12 ( V_18 ) ;
}
}
static void F_66 ( struct V_17 * V_18 , struct V_143 * V_144 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( ! V_2 || F_1 ( V_2 , V_18 -> V_3 , L_16 ) )
return;
F_8 ( V_21 ) ;
if ( F_67 ( V_144 ) ) {
F_9 ( V_21 ) ;
return;
}
if ( ( V_18 -> V_101 == 1 ) && ( V_2 -> V_101 != 1 ) ) {
F_3 ( L_17
L_18 , V_2 -> V_101 ) ;
V_2 -> V_101 = 1 ;
}
if ( -- V_2 -> V_101 < 0 ) {
F_3 ( L_19 ,
V_2 -> line , V_2 -> V_101 ) ;
V_2 -> V_101 = 0 ;
}
if ( V_2 -> V_101 ) {
F_9 ( V_21 ) ;
return;
}
V_2 -> V_21 |= V_145 ;
V_18 -> V_146 = 1 ;
if ( V_2 -> V_111 != V_147 )
F_64 ( V_18 , V_2 -> V_111 ) ;
V_20 -> V_22 &= ~ V_67 ;
V_20 -> V_22 &= ~ ( V_67 | V_68 ) ;
F_31 ( V_2 ) ;
F_46 ( V_18 ) ;
F_68 ( V_18 ) ;
V_18 -> V_146 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_18 = NULL ;
#warning "This is not and has never been valid so fix it"
#if 0
if (tty->ldisc.num != ldiscs[N_TTY].num) {
if (tty->ldisc.close)
(tty->ldisc.close)(tty);
tty->ldisc = ldiscs[N_TTY];
tty->termios->c_line = N_TTY;
if (tty->ldisc.open)
(tty->ldisc.open)(tty);
}
#endif
if ( V_2 -> V_149 ) {
if ( V_2 -> V_110 ) {
F_61 ( F_69 ( V_2 -> V_110 ) ) ;
}
F_70 ( & V_2 -> V_150 ) ;
}
V_2 -> V_21 &= ~ ( V_151 | V_145 ) ;
F_70 ( & V_2 -> V_152 ) ;
F_9 ( V_21 ) ;
}
void F_71 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_20 ) )
return;
F_46 ( V_18 ) ;
F_31 ( V_2 ) ;
V_2 -> V_148 = 0 ;
V_2 -> V_101 = 0 ;
V_2 -> V_21 &= ~ V_151 ;
V_2 -> V_18 = NULL ;
F_70 ( & V_2 -> V_150 ) ;
}
static int F_72 ( struct V_17 * V_18 , struct V_143 * V_144 ,
struct V_1 * V_2 )
{
F_73 ( V_153 , V_154 ) ;
int V_116 ;
int V_155 = 0 ;
if ( V_2 -> V_21 & V_145 ) {
F_74 ( & V_2 -> V_152 ) ;
#ifdef F_75
if ( V_2 -> V_21 & V_156 )
return - V_157 ;
else
return - V_158 ;
#else
return - V_157 ;
#endif
}
if ( ( V_144 -> V_159 & V_160 ) ||
( V_18 -> V_21 & ( 1 << V_69 ) ) ) {
V_2 -> V_21 |= V_151 ;
return 0 ;
}
if ( V_18 -> V_74 -> V_75 & V_161 )
V_155 = 1 ;
V_116 = 0 ;
F_76 ( & V_2 -> V_150 , & V_153 ) ;
V_2 -> V_101 -- ;
V_2 -> V_149 ++ ;
while ( 1 ) {
F_42 () ;
F_4 ( V_2 , 1 ) ;
F_77 () ;
V_154 -> V_162 = V_163 ;
if ( F_67 ( V_144 ) ||
! ( V_2 -> V_21 & V_62 ) ) {
#ifdef F_75
if ( V_2 -> V_21 & V_156 )
V_116 = - V_157 ;
else
V_116 = - V_158 ;
#else
V_116 = - V_157 ;
#endif
break;
}
if ( ! ( V_2 -> V_21 & V_145 ) && V_155 )
break;
if ( F_78 ( V_154 ) ) {
V_116 = - V_158 ;
break;
}
F_79 () ;
F_80 () ;
F_81 () ;
}
V_154 -> V_162 = V_164 ;
F_82 ( & V_2 -> V_150 , & V_153 ) ;
if ( ! F_67 ( V_144 ) )
V_2 -> V_101 ++ ;
V_2 -> V_149 -- ;
if ( V_116 )
return V_116 ;
V_2 -> V_21 |= V_151 ;
return 0 ;
}
int F_83 ( struct V_17 * V_18 , struct V_143 * V_144 )
{
struct V_1 * V_2 ;
int V_116 , line ;
line = V_18 -> V_165 ;
if ( line >= V_166 || line < 0 )
return - V_129 ;
V_2 = & V_95 [ line ] ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_21 ) )
return - V_129 ;
V_2 -> V_101 ++ ;
V_18 -> V_19 = V_2 ;
V_2 -> V_18 = V_18 ;
V_116 = F_27 ( V_2 ) ;
if ( V_116 )
return V_116 ;
return F_72 ( V_18 , V_144 , V_2 ) ;
}
static void F_84 ( void )
{
F_3 ( L_22 ) ;
}
static int T_3
F_85 ( void )
{
int V_21 , V_73 ;
struct V_1 * V_2 ;
V_167 = F_86 ( V_166 ) ;
if ( ! V_167 )
return - V_64 ;
F_84 () ;
V_167 -> V_3 = L_23 ;
V_167 -> V_168 = V_169 ;
V_167 -> V_170 = 64 ;
V_167 -> type = V_171 ;
V_167 -> V_172 = V_173 ;
V_167 -> V_174 = V_175 ;
V_167 -> V_174 . V_75 =
V_176 | V_88 | V_177 | V_178 | V_161 ;
V_167 -> V_21 = V_179 ;
F_87 ( V_167 , & V_180 ) ;
if ( F_88 ( V_167 ) ) {
F_89 ( V_167 ) ;
F_3 ( V_181 L_24 ) ;
return - V_64 ;
}
F_8 ( V_21 ) ;
for( V_73 = 0 ; V_73 < V_166 ; V_73 ++ ) {
V_2 = & V_95 [ V_73 ] ;
V_2 -> V_7 = V_8 ;
V_2 -> V_71 = ( int ) & V_13 [ V_73 ] ;
V_2 -> V_18 = NULL ;
V_2 -> V_58 = V_182 [ V_73 ] ;
V_2 -> V_112 = 16 ;
V_2 -> V_110 = 50 ;
V_2 -> V_111 = 3000 ;
V_2 -> V_50 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_101 = 0 ;
V_2 -> V_149 = 0 ;
F_90 ( & V_2 -> V_150 ) ;
F_90 ( & V_2 -> V_152 ) ;
V_2 -> line = V_73 ;
V_2 -> V_38 = 1 ;
F_3 ( L_25 , V_167 -> V_3 , V_2 -> line ,
V_2 -> V_71 , V_2 -> V_58 ) ;
F_3 ( L_26 ) ;
#ifdef F_91
if ( V_73 > 0 )
V_183 &= 0xCF ;
#endif
if ( F_92 ( V_182 [ V_73 ] ,
F_26 ,
0 ,
L_27 , V_2 ) )
F_93 ( L_28 ) ;
}
F_9 ( V_21 ) ;
return 0 ;
}
static void F_94 ( void )
{
unsigned short V_22 ;
int V_73 ;
V_22 = V_184 ;
V_184 = V_22 & ~ V_23 ;
V_185:
for ( V_73 = 0 ; V_73 < F_95 ( V_79 ) ; V_73 ++ )
if ( V_79 [ V_73 ] == V_186 )
break;
if ( V_73 >= F_95 ( V_79 ) ) {
V_186 = 9600 ;
goto V_185;
}
V_187 = F_34 ( V_16 , V_80 [ V_73 ] . V_81 ) |
F_34 ( V_15 , V_80 [ V_73 ] . V_82 ) ;
V_22 &= ~ ( V_83 | V_84 | V_85 | V_86 ) ;
V_22 |= V_86 ;
V_22 |= V_23 ;
V_184 = V_22 ;
V_188 = 1 ;
return;
}
int F_96 ( struct V_189 * V_190 , char * V_128 )
{
int V_73 , V_191 = V_192 ;
if ( ! V_190 )
return ( - 1 ) ;
if ( V_128 )
V_191 = F_97 ( V_128 , NULL , 0 ) ;
for ( V_73 = 0 ; V_73 < F_95 ( V_79 ) ; V_73 ++ )
if ( V_79 [ V_73 ] == V_191 )
break;
if ( V_73 < F_95 ( V_79 ) ) {
V_186 = V_191 ;
V_176 = 0 ;
if ( V_73 > 15 ) {
V_176 |= V_77 ;
V_73 -= 15 ;
}
V_176 |= V_73 ;
}
F_94 () ;
return ( 0 ) ;
}
static struct V_193 * F_98 ( struct V_189 * V_96 , int * V_165 )
{
* V_165 = V_96 -> V_165 ;
return V_167 ;
}
void F_99 ( struct V_189 * V_194 , const char * V_195 ,
unsigned int V_101 )
{
if ( ! V_188 )
F_94 () ;
while ( V_101 -- ) {
if ( * V_195 == '\n' )
F_10 ( '\r' ) ;
F_10 ( * V_195 ++ ) ;
}
}
static int T_3 F_100 ( void )
{
F_101 ( & V_196 ) ;
return 0 ;
}
