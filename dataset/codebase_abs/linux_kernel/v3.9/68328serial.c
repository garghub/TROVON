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
static void F_13 ( struct V_1 * V_2 , unsigned short V_31 )
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
V_32 = V_36 ;
if ( V_31 & V_37 )
V_32 = V_38 ;
else if ( V_31 & V_39 )
V_32 = V_40 ;
else if ( V_31 & V_41 )
V_32 = V_42 ;
F_20 ( & V_2 -> V_43 , V_23 , V_32 ) ;
#ifndef F_14
} while( ( V_31 = V_19 -> V_44 . V_45 ) & V_46 );
#endif
F_21 ( & V_2 -> V_43 ) ;
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
struct V_16 * V_17 = F_24 ( & V_2 -> V_43 ) ;
T_1 * V_19 ;
unsigned short V_31 ;
unsigned short V_57 ;
V_19 = & V_12 [ V_2 -> line ] ;
V_31 = V_19 -> V_44 . V_45 ;
#ifdef F_12
V_57 = V_19 -> V_48 . V_45 ;
if ( V_31 & V_46 )
F_13 ( V_2 , V_31 ) ;
if ( V_57 & V_26 )
F_22 ( V_2 , V_17 ) ;
#else
F_13 ( V_2 , V_31 ) ;
#endif
F_25 ( V_17 ) ;
return V_58 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( V_2 -> V_43 . V_20 & V_59 )
return 0 ;
if ( ! V_2 -> V_29 ) {
V_2 -> V_29 = ( unsigned char * ) F_27 ( V_60 ) ;
if ( ! V_2 -> V_29 )
return - V_61 ;
}
F_7 ( V_20 ) ;
V_19 -> V_21 = V_62 ;
V_19 -> V_21 = V_62 | V_63 | V_22 ;
( void ) V_19 -> V_44 . V_45 ;
#ifdef F_12
V_19 -> V_21 = V_62 | V_63 |
V_64 | V_30 ;
#else
V_19 -> V_21 = V_62 | V_63 | V_64 ;
#endif
if ( V_17 )
F_28 ( V_65 , & V_17 -> V_20 ) ;
V_2 -> V_28 = V_2 -> V_66 = V_2 -> V_53 = 0 ;
F_29 ( V_2 , V_17 ) ;
V_2 -> V_43 . V_20 |= V_59 ;
F_8 ( V_20 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
V_19 -> V_21 = 0 ;
if ( ! ( V_2 -> V_43 . V_20 & V_59 ) )
return;
F_7 ( V_20 ) ;
if ( V_2 -> V_29 ) {
F_31 ( ( unsigned long ) V_2 -> V_29 ) ;
V_2 -> V_29 = 0 ;
}
if ( V_17 )
F_32 ( V_65 , & V_17 -> V_20 ) ;
V_2 -> V_43 . V_20 &= ~ V_59 ;
F_8 ( V_20 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned short V_67 ;
unsigned short V_21 ;
unsigned V_68 ;
int V_69 ;
V_68 = V_17 -> V_70 . V_71 ;
if ( ! ( V_67 = V_2 -> V_67 ) )
return;
V_21 = V_19 -> V_21 ;
V_19 -> V_21 = V_21 & ~ V_22 ;
V_69 = V_68 & V_72 ;
if ( V_69 & V_73 ) {
V_69 = ( V_69 & ~ V_73 ) + V_74 ;
}
V_19 -> V_13 = F_33 ( V_15 , V_75 [ V_69 ] . V_76 ) |
F_33 ( V_14 , V_75 [ V_69 ] . V_77 ) ;
V_21 &= ~ ( V_78 | V_79 | V_80 | V_81 ) ;
if ( ( V_68 & V_82 ) == V_83 )
V_21 |= V_81 ;
if ( V_68 & V_84 )
V_21 |= V_80 ;
if ( V_68 & V_85 )
V_21 |= V_78 ;
if ( V_68 & V_86 )
V_21 |= V_79 ;
#ifdef F_34
if ( V_68 & V_87 ) {
V_19 -> V_48 . V_45 &= ~ V_88 ;
} else {
V_19 -> V_48 . V_45 |= V_88 ;
}
#endif
V_21 |= V_22 ;
V_19 -> V_21 = V_21 ;
return;
}
static void F_35 ( void )
{
int V_89 ;
unsigned long V_20 ;
struct V_1 * V_2 = & V_90 [ 0 ] ;
char V_91 ;
if ( V_2 == 0 ) return;
if ( V_2 -> V_29 == 0 ) return;
F_7 ( V_20 ) ;
V_89 = V_2 -> V_28 ;
while ( V_89 != 0 ) {
V_91 = V_2 -> V_29 [ V_2 -> V_53 ] ;
V_2 -> V_53 = ( V_2 -> V_53 + 1 ) & ( V_54 - 1 ) ;
V_2 -> V_28 -- ;
F_8 ( V_20 ) ;
F_9 ( V_91 ) ;
F_7 ( V_20 ) ;
V_89 = F_36 ( V_2 -> V_28 , V_89 - 1 ) ;
}
F_10 ( 5 ) ;
F_8 ( V_20 ) ;
return;
}
void F_37 ( const char * V_92 )
{
char V_91 ;
while( ( V_91 = * ( V_92 ++ ) ) != 0 ) {
if( V_91 == '\n' )
F_9 ( '\r' ) ;
F_9 ( V_91 ) ;
}
F_35 () ;
return;
}
static void F_38 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_5 ) )
return;
V_2 -> V_34 = ( V_17 -> V_70 . V_93 == V_94 ) ;
F_3 ( L_6 , V_2 -> line , V_2 -> V_34 ? L_7 : L_8 ) ;
}
static int F_39 ( struct V_16 * V_17 ,
const unsigned char * V_95 , int V_96 )
{
int V_91 , V_97 = 0 ;
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
V_91 = F_42 ( int , V_96 , F_36 ( V_54 - V_2 -> V_28 - 1 ,
V_54 - V_2 -> V_66 ) ) ;
F_8 ( V_20 ) ;
if ( V_91 <= 0 )
break;
memcpy ( V_2 -> V_29 + V_2 -> V_66 , V_95 , V_91 ) ;
F_41 () ;
V_2 -> V_66 = ( V_2 -> V_66 + V_91 ) & ( V_54 - 1 ) ;
V_2 -> V_28 += V_91 ;
F_8 ( V_20 ) ;
V_95 += V_91 ;
V_96 -= V_91 ;
V_97 += V_91 ;
}
if ( V_2 -> V_28 && ! V_17 -> V_52 && ! V_17 -> V_98 ) {
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
return V_97 ;
}
static int F_43 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
int V_99 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_10 ) )
return 0 ;
V_99 = V_54 - V_2 -> V_28 - 1 ;
if ( V_99 < 0 )
V_99 = 0 ;
return V_99 ;
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
V_2 -> V_28 = V_2 -> V_66 = V_2 -> V_53 = 0 ;
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
struct V_100 * V_101 )
{
struct V_100 V_102 ;
if ( ! V_101 )
return - V_103 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . type = V_2 -> type ;
V_102 . line = V_2 -> line ;
V_102 . V_67 = V_2 -> V_67 ;
V_102 . V_55 = V_2 -> V_55 ;
V_102 . V_20 = V_2 -> V_43 . V_20 ;
V_102 . V_104 = V_2 -> V_104 ;
V_102 . V_105 = V_2 -> V_43 . V_105 ;
V_102 . V_106 = V_2 -> V_43 . V_106 ;
V_102 . V_107 = V_2 -> V_107 ;
if ( F_53 ( V_101 , & V_102 , sizeof( * V_101 ) ) )
return - V_103 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_100 * V_108 )
{
struct V_109 * V_67 = & V_2 -> V_43 ;
struct V_100 V_110 ;
struct V_1 V_111 ;
int V_112 = 0 ;
if ( ! V_108 )
return - V_103 ;
if ( F_55 ( & V_110 , V_108 , sizeof( V_110 ) ) )
return - V_103 ;
V_111 = * V_2 ;
if ( ! F_56 ( V_113 ) ) {
if ( ( V_110 . V_104 != V_2 -> V_104 ) ||
( V_110 . type != V_2 -> type ) ||
( V_110 . V_105 != V_67 -> V_105 ) ||
( ( V_110 . V_20 & ~ V_114 ) !=
( V_67 -> V_20 & ~ V_114 ) ) )
return - V_115 ;
V_67 -> V_20 = ( ( V_67 -> V_20 & ~ V_114 ) |
( V_110 . V_20 & V_114 ) ) ;
V_2 -> V_107 = V_110 . V_107 ;
goto V_116;
}
if ( V_67 -> V_96 > 1 )
return - V_117 ;
V_2 -> V_104 = V_110 . V_104 ;
V_67 -> V_20 = ( ( V_67 -> V_20 & ~ V_118 ) |
( V_110 . V_20 & V_118 ) ) ;
V_2 -> type = V_110 . type ;
V_67 -> V_105 = V_110 . V_105 ;
V_67 -> V_106 = V_110 . V_106 ;
V_116:
V_112 = F_26 ( V_2 , V_17 ) ;
return V_112 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int * V_119 )
{
#ifdef F_34
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
#endif
unsigned char V_120 ;
unsigned long V_20 ;
F_7 ( V_20 ) ;
#ifdef F_34
V_120 = ( V_19 -> V_48 . V_45 & V_121 ) ? 1 : 0 ;
#else
V_120 = 0 ;
#endif
F_8 ( V_20 ) ;
return F_58 ( V_120 , V_119 ) ;
}
static void F_59 ( struct V_1 * V_2 , unsigned int V_122 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( ! V_2 -> V_67 )
return;
F_7 ( V_20 ) ;
#ifdef F_12
V_19 -> V_48 . V_45 |= V_123 ;
F_60 ( V_122 ) ;
V_19 -> V_48 . V_45 &= ~ V_123 ;
#endif
F_8 ( V_20 ) ;
}
static int F_61 ( struct V_16 * V_17 ,
unsigned int V_124 , unsigned long V_125 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
int V_112 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_15 ) )
return - V_126 ;
if ( ( V_124 != V_127 ) && ( V_124 != V_128 ) &&
( V_124 != V_129 ) && ( V_124 != V_130 ) &&
( V_124 != V_131 ) && ( V_124 != V_132 ) ) {
if ( V_17 -> V_20 & ( 1 << V_65 ) )
return - V_133 ;
}
switch ( V_124 ) {
case V_134 :
V_112 = F_62 ( V_17 ) ;
if ( V_112 )
return V_112 ;
F_63 ( V_17 , 0 ) ;
if ( ! V_125 )
F_59 ( V_2 , 250 ) ;
return 0 ;
case V_135 :
V_112 = F_62 ( V_17 ) ;
if ( V_112 )
return V_112 ;
F_63 ( V_17 , 0 ) ;
F_59 ( V_2 , V_125 ? V_125 * ( 100 ) : 250 ) ;
return 0 ;
case V_127 :
return F_52 ( V_2 ,
(struct V_100 * ) V_125 ) ;
case V_128 :
return F_54 ( V_2 , V_17 ,
(struct V_100 * ) V_125 ) ;
case V_136 :
return F_57 ( V_2 , ( unsigned int * ) V_125 ) ;
case V_132 :
if ( F_53 ( (struct V_1 * ) V_125 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_103 ;
return 0 ;
default:
return - V_137 ;
}
return 0 ;
}
static void F_64 ( struct V_16 * V_17 , struct V_138 * V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
F_29 ( V_2 , V_17 ) ;
if ( ( V_139 -> V_71 & V_87 ) &&
! ( V_17 -> V_70 . V_71 & V_87 ) ) {
V_17 -> V_98 = 0 ;
F_11 ( V_17 ) ;
}
}
static void F_65 ( struct V_16 * V_17 , struct V_140 * V_141 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
struct V_109 * V_67 = & V_2 -> V_43 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_16 ) )
return;
F_7 ( V_20 ) ;
if ( F_66 ( V_141 ) ) {
F_8 ( V_20 ) ;
return;
}
if ( ( V_17 -> V_96 == 1 ) && ( V_67 -> V_96 != 1 ) ) {
F_3 ( L_17
L_18 , V_67 -> V_96 ) ;
V_67 -> V_96 = 1 ;
}
if ( -- V_67 -> V_96 < 0 ) {
F_3 ( L_19 ,
V_2 -> line , V_67 -> V_96 ) ;
V_67 -> V_96 = 0 ;
}
if ( V_67 -> V_96 ) {
F_8 ( V_20 ) ;
return;
}
V_67 -> V_20 |= V_142 ;
V_17 -> V_143 = 1 ;
if ( V_67 -> V_106 != V_144 )
F_63 ( V_17 , V_67 -> V_106 ) ;
V_19 -> V_21 &= ~ V_63 ;
V_19 -> V_21 &= ~ ( V_63 | V_64 ) ;
F_30 ( V_2 , V_17 ) ;
F_45 ( V_17 ) ;
F_67 ( V_17 ) ;
V_17 -> V_143 = 0 ;
F_68 ( & V_2 -> V_43 , NULL ) ;
#warning "This is not and has never been valid so fix it"
#if 0
if (tty->ldisc.num != ldiscs[N_TTY].num) {
if (tty->ldisc.close)
(tty->ldisc.close)(tty);
tty->ldisc = ldiscs[N_TTY];
tty->termios.c_line = N_TTY;
if (tty->ldisc.open)
(tty->ldisc.open)(tty);
}
#endif
if ( V_67 -> V_145 ) {
if ( V_67 -> V_105 )
F_60 ( F_69 ( V_67 -> V_105 ) ) ;
F_70 ( & V_67 -> V_146 ) ;
}
V_67 -> V_20 &= ~ ( V_147 | V_142 ) ;
F_70 ( & V_67 -> V_148 ) ;
F_8 ( V_20 ) ;
}
void F_71 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_20 ) )
return;
F_45 ( V_17 ) ;
F_30 ( V_2 , V_17 ) ;
V_2 -> V_43 . V_96 = 0 ;
V_2 -> V_43 . V_20 &= ~ V_147 ;
F_68 ( & V_2 -> V_43 , NULL ) ;
F_70 ( & V_2 -> V_43 . V_146 ) ;
}
int F_72 ( struct V_16 * V_17 , struct V_140 * V_141 )
{
struct V_1 * V_2 ;
int V_112 ;
V_2 = & V_90 [ V_17 -> V_149 ] ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_21 ) )
return - V_126 ;
V_2 -> V_43 . V_96 ++ ;
V_17 -> V_18 = V_2 ;
F_68 ( & V_2 -> V_43 , V_17 ) ;
V_112 = F_26 ( V_2 , V_17 ) ;
if ( V_112 )
return V_112 ;
return F_73 ( & V_2 -> V_43 , V_17 , V_141 ) ;
}
static void F_74 ( void )
{
F_3 ( L_22 ) ;
}
static int T_3
F_75 ( void )
{
unsigned long V_20 ;
int V_69 ;
struct V_1 * V_2 ;
V_150 = F_76 ( V_151 ) ;
if ( ! V_150 )
return - V_61 ;
F_74 () ;
V_150 -> V_3 = L_23 ;
V_150 -> V_152 = V_153 ;
V_150 -> V_154 = 64 ;
V_150 -> type = V_155 ;
V_150 -> V_156 = V_157 ;
V_150 -> V_158 = V_159 ;
V_150 -> V_158 . V_71 =
V_160 | V_83 | V_161 | V_162 | V_163 ;
V_150 -> V_20 = V_164 ;
F_77 ( V_150 , & V_165 ) ;
F_7 ( V_20 ) ;
for( V_69 = 0 ; V_69 < V_151 ; V_69 ++ ) {
V_2 = & V_90 [ V_69 ] ;
F_78 ( & V_2 -> V_43 ) ;
V_2 -> V_43 . V_166 = & V_167 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_67 = ( int ) & V_12 [ V_69 ] ;
V_2 -> V_55 = V_168 [ V_69 ] ;
V_2 -> V_107 = 16 ;
V_2 -> V_47 = 0 ;
V_2 -> line = V_69 ;
V_2 -> V_34 = 1 ;
F_3 ( L_24 , V_150 -> V_3 , V_2 -> line ,
V_2 -> V_67 , V_2 -> V_55 ) ;
F_3 ( L_25 ) ;
#ifdef F_79
if ( V_69 > 0 )
V_169 &= 0xCF ;
#endif
if ( F_80 ( V_168 [ V_69 ] ,
F_23 ,
0 ,
L_26 , V_2 ) )
F_81 ( L_27 ) ;
F_82 ( & V_2 -> V_43 , V_150 , V_69 ) ;
}
F_8 ( V_20 ) ;
if ( F_83 ( V_150 ) ) {
F_84 ( V_150 ) ;
for ( V_69 = 0 ; V_69 < V_151 ; V_69 ++ )
F_85 ( & V_90 [ V_69 ] . V_43 ) ;
F_3 ( V_170 L_28 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_86 ( void )
{
unsigned short V_21 ;
int V_69 ;
V_21 = V_171 ;
V_171 = V_21 & ~ V_22 ;
V_172:
for ( V_69 = 0 ; V_69 < F_87 ( V_173 ) ; V_69 ++ )
if ( V_173 [ V_69 ] == V_174 )
break;
if ( V_69 >= F_87 ( V_173 ) ) {
V_174 = 9600 ;
goto V_172;
}
V_175 = F_33 ( V_15 , V_75 [ V_69 ] . V_76 ) |
F_33 ( V_14 , V_75 [ V_69 ] . V_77 ) ;
V_21 &= ~ ( V_78 | V_79 | V_80 | V_81 ) ;
V_21 |= V_81 ;
V_21 |= V_22 ;
V_171 = V_21 ;
V_176 = 1 ;
return;
}
int F_88 ( struct V_177 * V_178 , char * V_125 )
{
int V_69 , V_179 = V_180 ;
if ( ! V_178 )
return ( - 1 ) ;
if ( V_125 )
V_179 = F_89 ( V_125 , NULL , 0 ) ;
for ( V_69 = 0 ; V_69 < F_87 ( V_173 ) ; V_69 ++ )
if ( V_173 [ V_69 ] == V_179 )
break;
if ( V_69 < F_87 ( V_173 ) ) {
V_174 = V_179 ;
V_160 = 0 ;
if ( V_69 > 15 ) {
V_160 |= V_73 ;
V_69 -= 15 ;
}
V_160 |= V_69 ;
}
F_86 () ;
return ( 0 ) ;
}
static struct V_181 * F_90 ( struct V_177 * V_91 , int * V_149 )
{
* V_149 = V_91 -> V_149 ;
return V_150 ;
}
void F_91 ( struct V_177 * V_182 , const char * V_183 ,
unsigned int V_96 )
{
if ( ! V_176 )
F_86 () ;
while ( V_96 -- ) {
if ( * V_183 == '\n' )
F_9 ( '\r' ) ;
F_9 ( * V_183 ++ ) ;
}
}
static int T_3 F_92 ( void )
{
F_93 ( & V_184 ) ;
return 0 ;
}
