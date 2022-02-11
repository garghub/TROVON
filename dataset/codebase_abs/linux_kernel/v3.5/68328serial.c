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
static inline int F_4 ( struct V_1 * V_9 )
{
unsigned long V_10 = 115200 ;
unsigned short int V_11 = V_12 [ V_9 -> line ] . V_13 ;
if ( F_5 ( V_11 , V_14 ) == 0x38 ) V_10 = 38400 ;
V_10 >>= F_5 ( V_11 , V_15 ) ;
return V_10 ;
}
static void F_6 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_3 ) )
return;
F_7 ( V_20 ) ;
V_19 -> V_21 &= ~ V_22 ;
F_8 ( V_20 ) ;
}
static int F_9 ( char V_23 )
{
unsigned long V_20 ;
int V_24 = 0 ;
F_7 ( V_20 ) ;
while ( ! ( V_25 & V_26 ) && ( V_24 < 1000 ) ) {
V_24 ++ ;
F_10 ( 5 ) ;
}
V_27 = V_23 ;
F_10 ( 5 ) ;
F_8 ( V_20 ) ;
return 1 ;
}
static void F_11 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_4 ) )
return;
F_7 ( V_20 ) ;
if ( V_2 -> V_28 && V_2 -> V_29 && ! ( V_19 -> V_21 & V_22 ) ) {
#ifdef F_12
V_19 -> V_21 |= V_22 | V_30 ;
#else
V_19 -> V_21 |= V_22 ;
#endif
}
F_8 ( V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_16 * V_17 ,
unsigned short V_31 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned char V_23 , V_32 ;
#ifndef F_14
do {
#endif
V_23 = F_5 ( V_31 , V_33 ) ;
if( V_2 -> V_34 ) {
if( V_35 & V_31 ) {
return;
#ifdef F_15
} else if ( V_23 == 0x10 ) {
F_16 () ;
F_17 ( 0 ) ;
F_18 () ;
return;
} else if ( V_23 == 0x12 ) {
F_19 () ;
return;
#endif
}
}
if( ! V_17 )
goto V_36;
V_32 = V_37 ;
if ( V_31 & V_38 )
V_32 = V_39 ;
else if ( V_31 & V_40 )
V_32 = V_41 ;
else if ( V_31 & V_42 )
V_32 = V_43 ;
F_20 ( V_17 , V_23 , V_32 ) ;
#ifndef F_14
} while( ( V_31 = V_19 -> V_44 . V_45 ) & V_46 );
#endif
F_21 ( V_17 ) ;
V_36:
return;
}
static void F_22 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
if ( V_2 -> V_47 ) {
V_19 -> V_48 . V_49 . V_50 = V_2 -> V_47 ;
V_2 -> V_47 = 0 ;
goto V_51;
}
if ( ( V_2 -> V_28 <= 0 ) || ! V_17 || V_17 -> V_52 ) {
V_19 -> V_21 &= ~ V_30 ;
goto V_51;
}
V_19 -> V_48 . V_49 . V_50 = V_2 -> V_29 [ V_2 -> V_53 ++ ] ;
V_2 -> V_53 = V_2 -> V_53 & ( V_54 - 1 ) ;
V_2 -> V_28 -- ;
if( V_2 -> V_28 <= 0 ) {
V_19 -> V_21 &= ~ V_30 ;
goto V_51;
}
V_51:
return;
}
T_2 F_23 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
struct V_16 * V_17 = F_24 ( & V_2 -> V_57 ) ;
T_1 * V_19 ;
unsigned short V_31 ;
unsigned short V_58 ;
V_19 = & V_12 [ V_2 -> line ] ;
V_31 = V_19 -> V_44 . V_45 ;
#ifdef F_12
V_58 = V_19 -> V_48 . V_45 ;
if ( V_31 & V_46 )
F_13 ( V_2 , V_17 , V_31 ) ;
if ( V_58 & V_26 )
F_22 ( V_2 , V_17 ) ;
#else
F_13 ( V_2 , V_17 , V_31 ) ;
#endif
F_25 ( V_17 ) ;
return V_59 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( V_2 -> V_57 . V_20 & V_60 )
return 0 ;
if ( ! V_2 -> V_29 ) {
V_2 -> V_29 = ( unsigned char * ) F_27 ( V_61 ) ;
if ( ! V_2 -> V_29 )
return - V_62 ;
}
F_7 ( V_20 ) ;
V_19 -> V_21 = V_63 ;
V_19 -> V_21 = V_63 | V_64 | V_22 ;
( void ) V_19 -> V_44 . V_45 ;
#ifdef F_12
V_19 -> V_21 = V_63 | V_64 |
V_65 | V_30 ;
#else
V_19 -> V_21 = V_63 | V_64 | V_65 ;
#endif
if ( V_17 )
F_28 ( V_66 , & V_17 -> V_20 ) ;
V_2 -> V_28 = V_2 -> V_67 = V_2 -> V_53 = 0 ;
F_29 ( V_2 , V_17 ) ;
V_2 -> V_57 . V_20 |= V_60 ;
F_8 ( V_20 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
V_19 -> V_21 = 0 ;
if ( ! ( V_2 -> V_57 . V_20 & V_60 ) )
return;
F_7 ( V_20 ) ;
if ( V_2 -> V_29 ) {
F_31 ( ( unsigned long ) V_2 -> V_29 ) ;
V_2 -> V_29 = 0 ;
}
if ( V_17 )
F_32 ( V_66 , & V_17 -> V_20 ) ;
V_2 -> V_57 . V_20 &= ~ V_60 ;
F_8 ( V_20 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned short V_68 ;
unsigned short V_21 ;
unsigned V_69 ;
int V_70 ;
V_69 = V_17 -> V_71 -> V_72 ;
if ( ! ( V_68 = V_2 -> V_68 ) )
return;
V_21 = V_19 -> V_21 ;
V_19 -> V_21 = V_21 & ~ V_22 ;
V_70 = V_69 & V_73 ;
if ( V_70 & V_74 ) {
V_70 = ( V_70 & ~ V_74 ) + V_75 ;
}
V_19 -> V_13 = F_33 ( V_15 , V_76 [ V_70 ] . V_77 ) |
F_33 ( V_14 , V_76 [ V_70 ] . V_78 ) ;
V_21 &= ~ ( V_79 | V_80 | V_81 | V_82 ) ;
if ( ( V_69 & V_83 ) == V_84 )
V_21 |= V_82 ;
if ( V_69 & V_85 )
V_21 |= V_81 ;
if ( V_69 & V_86 )
V_21 |= V_79 ;
if ( V_69 & V_87 )
V_21 |= V_80 ;
#ifdef F_34
if ( V_69 & V_88 ) {
V_19 -> V_48 . V_45 &= ~ V_89 ;
} else {
V_19 -> V_48 . V_45 |= V_89 ;
}
#endif
V_21 |= V_22 ;
V_19 -> V_21 = V_21 ;
return;
}
static void F_35 ( void )
{
int V_90 ;
unsigned long V_20 ;
struct V_1 * V_2 = & V_91 [ 0 ] ;
char V_92 ;
if ( V_2 == 0 ) return;
if ( V_2 -> V_29 == 0 ) return;
F_7 ( V_20 ) ;
V_90 = V_2 -> V_28 ;
while ( V_90 != 0 ) {
V_92 = V_2 -> V_29 [ V_2 -> V_53 ] ;
V_2 -> V_53 = ( V_2 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_28 -- ;
F_8 ( V_20 ) ;
F_9 ( V_92 ) ;
F_7 ( V_20 ) ;
V_90 = F_36 ( V_2 -> V_28 , V_90 - 1 ) ;
}
F_10 ( 5 ) ;
F_8 ( V_20 ) ;
return;
}
void F_37 ( const char * V_93 )
{
char V_92 ;
while( ( V_92 = * ( V_93 ++ ) ) != 0 ) {
if( V_92 == '\n' )
F_9 ( '\r' ) ;
F_9 ( V_92 ) ;
}
F_35 () ;
return;
}
static void F_38 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_5 ) )
return;
V_2 -> V_34 = ( V_17 -> V_71 -> V_94 == V_95 ) ;
F_3 ( L_6 , V_2 -> line , V_2 -> V_34 ? L_7 : L_8 ) ;
}
static int F_39 ( struct V_16 * V_17 ,
const unsigned char * V_96 , int V_97 )
{
int V_92 , V_98 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_9 ) )
return 0 ;
if ( ! V_17 || ! V_2 -> V_29 )
return 0 ;
F_40 ( V_20 ) ;
while ( 1 ) {
F_41 () ;
V_92 = F_42 ( int , V_97 , F_36 ( V_54 - V_2 -> V_28 - 1 ,
V_54 - V_2 -> V_67 ) ) ;
F_8 ( V_20 ) ;
if ( V_92 <= 0 )
break;
memcpy ( V_2 -> V_29 + V_2 -> V_67 , V_96 , V_92 ) ;
F_41 () ;
V_2 -> V_67 = ( V_2 -> V_67 + V_92 ) & ( V_54 - 1 ) ;
V_2 -> V_28 += V_92 ;
F_8 ( V_20 ) ;
V_96 += V_92 ;
V_97 -= V_92 ;
V_98 += V_92 ;
}
if ( V_2 -> V_28 && ! V_17 -> V_52 && ! V_17 -> V_99 ) {
F_41 () ;
#ifndef F_12
while( V_2 -> V_28 ) {
#endif
V_19 -> V_21 |= V_22 ;
#ifdef F_12
V_19 -> V_21 |= V_30 ;
#else
while ( ! ( V_19 -> V_48 . V_45 & V_26 ) ) F_10 ( 5 ) ;
#endif
if ( V_19 -> V_48 . V_45 & V_26 ) {
V_19 -> V_48 . V_49 . V_50 = V_2 -> V_29 [ V_2 -> V_53 ++ ] ;
V_2 -> V_53 = V_2 -> V_53 & ( V_54 - 1 ) ;
V_2 -> V_28 -- ;
}
#ifndef F_12
}
#endif
F_8 ( V_20 ) ;
}
return V_98 ;
}
static int F_43 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
int V_100 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_10 ) )
return 0 ;
V_100 = V_54 - V_2 -> V_28 - 1 ;
if ( V_100 < 0 )
V_100 = 0 ;
return V_100 ;
}
static int F_44 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_11 ) )
return 0 ;
return V_2 -> V_28 ;
}
static void F_45 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_12 ) )
return;
F_7 ( V_20 ) ;
V_2 -> V_28 = V_2 -> V_67 = V_2 -> V_53 = 0 ;
F_8 ( V_20 ) ;
F_46 ( V_17 ) ;
}
static void F_47 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_13 ) )
return;
if ( F_48 ( V_17 ) )
V_2 -> V_47 = F_49 ( V_17 ) ;
}
static void F_50 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_14 ) )
return;
if ( F_48 ( V_17 ) ) {
if ( V_2 -> V_47 )
V_2 -> V_47 = 0 ;
else
V_2 -> V_47 = F_51 ( V_17 ) ;
}
}
static int F_52 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_101 V_103 ;
if ( ! V_102 )
return - V_104 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . type = V_2 -> type ;
V_103 . line = V_2 -> line ;
V_103 . V_68 = V_2 -> V_68 ;
V_103 . V_55 = V_2 -> V_55 ;
V_103 . V_20 = V_2 -> V_57 . V_20 ;
V_103 . V_105 = V_2 -> V_105 ;
V_103 . V_106 = V_2 -> V_57 . V_106 ;
V_103 . V_107 = V_2 -> V_57 . V_107 ;
V_103 . V_108 = V_2 -> V_108 ;
if ( F_53 ( V_102 , & V_103 , sizeof( * V_102 ) ) )
return - V_104 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_101 * V_109 )
{
struct V_110 * V_68 = & V_2 -> V_57 ;
struct V_101 V_111 ;
struct V_1 V_112 ;
int V_113 = 0 ;
if ( ! V_109 )
return - V_104 ;
if ( F_55 ( & V_111 , V_109 , sizeof( V_111 ) ) )
return - V_104 ;
V_112 = * V_2 ;
if ( ! F_56 ( V_114 ) ) {
if ( ( V_111 . V_105 != V_2 -> V_105 ) ||
( V_111 . type != V_2 -> type ) ||
( V_111 . V_106 != V_68 -> V_106 ) ||
( ( V_111 . V_20 & ~ V_115 ) !=
( V_68 -> V_20 & ~ V_115 ) ) )
return - V_116 ;
V_68 -> V_20 = ( ( V_68 -> V_20 & ~ V_115 ) |
( V_111 . V_20 & V_115 ) ) ;
V_2 -> V_108 = V_111 . V_108 ;
goto V_117;
}
if ( V_68 -> V_97 > 1 )
return - V_118 ;
V_2 -> V_105 = V_111 . V_105 ;
V_68 -> V_20 = ( ( V_68 -> V_20 & ~ V_119 ) |
( V_111 . V_20 & V_119 ) ) ;
V_2 -> type = V_111 . type ;
V_68 -> V_106 = V_111 . V_106 ;
V_68 -> V_107 = V_111 . V_107 ;
V_117:
V_113 = F_26 ( V_2 , V_17 ) ;
return V_113 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int * V_120 )
{
#ifdef F_34
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
#endif
unsigned char V_121 ;
unsigned long V_20 ;
F_7 ( V_20 ) ;
#ifdef F_34
V_121 = ( V_19 -> V_48 . V_45 & V_122 ) ? 1 : 0 ;
#else
V_121 = 0 ;
#endif
F_8 ( V_20 ) ;
return F_58 ( V_121 , V_120 ) ;
}
static void F_59 ( struct V_1 * V_2 , unsigned int V_123 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( ! V_2 -> V_68 )
return;
F_7 ( V_20 ) ;
#ifdef F_12
V_19 -> V_48 . V_45 |= V_124 ;
F_60 ( V_123 ) ;
V_19 -> V_48 . V_45 &= ~ V_124 ;
#endif
F_8 ( V_20 ) ;
}
static int F_61 ( struct V_16 * V_17 ,
unsigned int V_125 , unsigned long V_126 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
int V_113 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_15 ) )
return - V_127 ;
if ( ( V_125 != V_128 ) && ( V_125 != V_129 ) &&
( V_125 != V_130 ) && ( V_125 != V_131 ) &&
( V_125 != V_132 ) && ( V_125 != V_133 ) ) {
if ( V_17 -> V_20 & ( 1 << V_66 ) )
return - V_134 ;
}
switch ( V_125 ) {
case V_135 :
V_113 = F_62 ( V_17 ) ;
if ( V_113 )
return V_113 ;
F_63 ( V_17 , 0 ) ;
if ( ! V_126 )
F_59 ( V_2 , 250 ) ;
return 0 ;
case V_136 :
V_113 = F_62 ( V_17 ) ;
if ( V_113 )
return V_113 ;
F_63 ( V_17 , 0 ) ;
F_59 ( V_2 , V_126 ? V_126 * ( 100 ) : 250 ) ;
return 0 ;
case V_128 :
return F_52 ( V_2 ,
(struct V_101 * ) V_126 ) ;
case V_129 :
return F_54 ( V_2 , V_17 ,
(struct V_101 * ) V_126 ) ;
case V_137 :
return F_57 ( V_2 , ( unsigned int * ) V_126 ) ;
case V_133 :
if ( F_53 ( (struct V_1 * ) V_126 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_104 ;
return 0 ;
default:
return - V_138 ;
}
return 0 ;
}
static void F_64 ( struct V_16 * V_17 , struct V_139 * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
F_29 ( V_2 , V_17 ) ;
if ( ( V_140 -> V_72 & V_88 ) &&
! ( V_17 -> V_71 -> V_72 & V_88 ) ) {
V_17 -> V_99 = 0 ;
F_11 ( V_17 ) ;
}
}
static void F_65 ( struct V_16 * V_17 , struct V_141 * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
struct V_110 * V_68 = & V_2 -> V_57 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( ! V_2 || F_1 ( V_2 , V_17 -> V_3 , L_16 ) )
return;
F_7 ( V_20 ) ;
if ( F_66 ( V_142 ) ) {
F_8 ( V_20 ) ;
return;
}
if ( ( V_17 -> V_97 == 1 ) && ( V_68 -> V_97 != 1 ) ) {
F_3 ( L_17
L_18 , V_68 -> V_97 ) ;
V_68 -> V_97 = 1 ;
}
if ( -- V_68 -> V_97 < 0 ) {
F_3 ( L_19 ,
V_2 -> line , V_68 -> V_97 ) ;
V_68 -> V_97 = 0 ;
}
if ( V_68 -> V_97 ) {
F_8 ( V_20 ) ;
return;
}
V_68 -> V_20 |= V_143 ;
V_17 -> V_144 = 1 ;
if ( V_68 -> V_107 != V_145 )
F_63 ( V_17 , V_68 -> V_107 ) ;
V_19 -> V_21 &= ~ V_64 ;
V_19 -> V_21 &= ~ ( V_64 | V_65 ) ;
F_30 ( V_2 , V_17 ) ;
F_45 ( V_17 ) ;
F_67 ( V_17 ) ;
V_17 -> V_144 = 0 ;
F_68 ( & V_2 -> V_57 , NULL ) ;
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
if ( V_68 -> V_146 ) {
if ( V_68 -> V_106 )
F_60 ( F_69 ( V_68 -> V_106 ) ) ;
F_70 ( & V_68 -> V_147 ) ;
}
V_68 -> V_20 &= ~ ( V_148 | V_143 ) ;
F_70 ( & V_68 -> V_149 ) ;
F_8 ( V_20 ) ;
}
void F_71 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_20 ) )
return;
F_45 ( V_17 ) ;
F_30 ( V_2 , V_17 ) ;
V_2 -> V_57 . V_97 = 0 ;
V_2 -> V_57 . V_20 &= ~ V_148 ;
F_68 ( & V_2 -> V_57 , NULL ) ;
F_70 ( & V_2 -> V_57 . V_147 ) ;
}
int F_72 ( struct V_16 * V_17 , struct V_141 * V_142 )
{
struct V_1 * V_2 ;
int V_113 ;
V_2 = & V_91 [ V_17 -> V_150 ] ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_21 ) )
return - V_127 ;
V_2 -> V_57 . V_97 ++ ;
V_17 -> V_18 = V_2 ;
F_68 ( & V_2 -> V_57 , V_17 ) ;
V_113 = F_26 ( V_2 , V_17 ) ;
if ( V_113 )
return V_113 ;
return F_73 ( & V_2 -> V_57 , V_17 , V_142 ) ;
}
static void F_74 ( void )
{
F_3 ( L_22 ) ;
}
static int T_3
F_75 ( void )
{
unsigned long V_20 ;
int V_70 ;
struct V_1 * V_2 ;
V_151 = F_76 ( V_152 ) ;
if ( ! V_151 )
return - V_62 ;
F_74 () ;
V_151 -> V_3 = L_23 ;
V_151 -> V_153 = V_154 ;
V_151 -> V_155 = 64 ;
V_151 -> type = V_156 ;
V_151 -> V_157 = V_158 ;
V_151 -> V_159 = V_160 ;
V_151 -> V_159 . V_72 =
V_161 | V_84 | V_162 | V_163 | V_164 ;
V_151 -> V_20 = V_165 ;
F_77 ( V_151 , & V_166 ) ;
if ( F_78 ( V_151 ) ) {
F_79 ( V_151 ) ;
F_3 ( V_167 L_24 ) ;
return - V_62 ;
}
F_7 ( V_20 ) ;
for( V_70 = 0 ; V_70 < V_152 ; V_70 ++ ) {
V_2 = & V_91 [ V_70 ] ;
F_80 ( & V_2 -> V_57 ) ;
V_2 -> V_57 . V_168 = & V_169 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_68 = ( int ) & V_12 [ V_70 ] ;
V_2 -> V_55 = V_170 [ V_70 ] ;
V_2 -> V_108 = 16 ;
V_2 -> V_47 = 0 ;
V_2 -> line = V_70 ;
V_2 -> V_34 = 1 ;
F_3 ( L_25 , V_151 -> V_3 , V_2 -> line ,
V_2 -> V_68 , V_2 -> V_55 ) ;
F_3 ( L_26 ) ;
#ifdef F_81
if ( V_70 > 0 )
V_171 &= 0xCF ;
#endif
if ( F_82 ( V_170 [ V_70 ] ,
F_23 ,
0 ,
L_27 , V_2 ) )
F_83 ( L_28 ) ;
}
F_8 ( V_20 ) ;
return 0 ;
}
static void F_84 ( void )
{
unsigned short V_21 ;
int V_70 ;
V_21 = V_172 ;
V_172 = V_21 & ~ V_22 ;
V_173:
for ( V_70 = 0 ; V_70 < F_85 ( V_174 ) ; V_70 ++ )
if ( V_174 [ V_70 ] == V_175 )
break;
if ( V_70 >= F_85 ( V_174 ) ) {
V_175 = 9600 ;
goto V_173;
}
V_176 = F_33 ( V_15 , V_76 [ V_70 ] . V_77 ) |
F_33 ( V_14 , V_76 [ V_70 ] . V_78 ) ;
V_21 &= ~ ( V_79 | V_80 | V_81 | V_82 ) ;
V_21 |= V_82 ;
V_21 |= V_22 ;
V_172 = V_21 ;
V_177 = 1 ;
return;
}
int F_86 ( struct V_178 * V_179 , char * V_126 )
{
int V_70 , V_180 = V_181 ;
if ( ! V_179 )
return ( - 1 ) ;
if ( V_126 )
V_180 = F_87 ( V_126 , NULL , 0 ) ;
for ( V_70 = 0 ; V_70 < F_85 ( V_174 ) ; V_70 ++ )
if ( V_174 [ V_70 ] == V_180 )
break;
if ( V_70 < F_85 ( V_174 ) ) {
V_175 = V_180 ;
V_161 = 0 ;
if ( V_70 > 15 ) {
V_161 |= V_74 ;
V_70 -= 15 ;
}
V_161 |= V_70 ;
}
F_84 () ;
return ( 0 ) ;
}
static struct V_182 * F_88 ( struct V_178 * V_92 , int * V_150 )
{
* V_150 = V_92 -> V_150 ;
return V_151 ;
}
void F_89 ( struct V_178 * V_183 , const char * V_184 ,
unsigned int V_97 )
{
if ( ! V_177 )
F_84 () ;
while ( V_97 -- ) {
if ( * V_184 == '\n' )
F_9 ( '\r' ) ;
F_9 ( * V_184 ++ ) ;
}
}
static int T_3 F_90 ( void )
{
F_91 ( & V_185 ) ;
return 0 ;
}
