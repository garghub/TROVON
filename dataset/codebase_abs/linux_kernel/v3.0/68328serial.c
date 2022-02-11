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
#if 0
if(status & DCD) {
if((info->port.tty->termios->c_cflag & CRTSCTS) &&
((info->curregs[3] & AUTO_ENAB)==0)) {
info->curregs[3] |= AUTO_ENAB;
info->pendregs[3] |= AUTO_ENAB;
write_zsreg(info->m68k_channel, 3, info->curregs[3]);
}
} else {
if((info->curregs[3] & AUTO_ENAB)) {
info->curregs[3] &= ~AUTO_ENAB;
info->pendregs[3] &= ~AUTO_ENAB;
write_zsreg(info->m68k_channel, 3, info->curregs[3]);
}
}
#endif
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
if ( V_2 -> V_29 < V_58 )
F_26 ( & V_2 -> V_59 ) ;
if( V_2 -> V_29 <= 0 ) {
V_20 -> V_22 &= ~ V_31 ;
goto V_54;
}
V_54:
return;
}
T_2 F_27 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
T_1 * V_20 ;
unsigned short V_35 ;
unsigned short V_62 ;
V_20 = & V_13 [ V_2 -> line ] ;
V_35 = V_20 -> V_47 . V_48 ;
#ifdef F_13
V_62 = V_20 -> V_51 . V_48 ;
if ( V_35 & V_49 ) F_16 ( V_2 , V_35 ) ;
if ( V_62 & V_27 ) F_25 ( V_2 ) ;
#else
F_16 ( V_2 , V_35 ) ;
#endif
return V_63 ;
}
static void F_28 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 , struct V_1 , V_59 ) ;
struct V_17 * V_18 ;
V_18 = V_2 -> V_18 ;
if ( ! V_18 )
return;
#if 0
if (clear_bit(RS_EVENT_WRITE_WAKEUP, &info->event)) {
tty_wakeup(tty);
}
#endif
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( V_2 -> V_21 & V_66 )
return 0 ;
if ( ! V_2 -> V_30 ) {
V_2 -> V_30 = ( unsigned char * ) F_31 ( V_67 ) ;
if ( ! V_2 -> V_30 )
return - V_68 ;
}
F_8 ( V_21 ) ;
V_20 -> V_22 = V_69 ;
V_2 -> V_70 = 1 ;
V_20 -> V_22 = V_69 | V_71 | V_23 ;
( void ) V_20 -> V_47 . V_48 ;
#ifdef F_13
V_20 -> V_22 = V_69 | V_71 |
V_72 | V_31 ;
#else
V_20 -> V_22 = V_69 | V_71 | V_72 ;
#endif
if ( V_2 -> V_18 )
F_32 ( V_73 , & V_2 -> V_18 -> V_21 ) ;
V_2 -> V_29 = V_2 -> V_74 = V_2 -> V_56 = 0 ;
F_33 ( V_2 ) ;
V_2 -> V_21 |= V_66 ;
F_9 ( V_21 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
V_20 -> V_22 = 0 ;
if ( ! ( V_2 -> V_21 & V_66 ) )
return;
F_8 ( V_21 ) ;
if ( V_2 -> V_30 ) {
F_35 ( ( unsigned long ) V_2 -> V_30 ) ;
V_2 -> V_30 = 0 ;
}
if ( V_2 -> V_18 )
F_36 ( V_73 , & V_2 -> V_18 -> V_21 ) ;
V_2 -> V_21 &= ~ V_66 ;
F_9 ( V_21 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned short V_75 ;
unsigned short V_22 ;
unsigned V_76 ;
int V_77 ;
if ( ! V_2 -> V_18 || ! V_2 -> V_18 -> V_78 )
return;
V_76 = V_2 -> V_18 -> V_78 -> V_79 ;
if ( ! ( V_75 = V_2 -> V_75 ) )
return;
V_22 = V_20 -> V_22 ;
V_20 -> V_22 = V_22 & ~ V_23 ;
V_77 = V_76 & V_80 ;
if ( V_77 & V_81 ) {
V_77 = ( V_77 & ~ V_81 ) + V_82 ;
}
V_2 -> V_12 = V_83 [ V_77 ] ;
V_20 -> V_14 = F_37 ( V_16 , V_84 [ V_77 ] . V_85 ) |
F_37 ( V_15 , V_84 [ V_77 ] . V_86 ) ;
V_22 &= ~ ( V_87 | V_88 | V_89 | V_90 ) ;
if ( ( V_76 & V_91 ) == V_92 )
V_22 |= V_90 ;
if ( V_76 & V_93 )
V_22 |= V_89 ;
if ( V_76 & V_94 )
V_22 |= V_87 ;
if ( V_76 & V_95 )
V_22 |= V_88 ;
#ifdef F_38
if ( V_76 & V_96 ) {
V_20 -> V_51 . V_48 &= ~ V_97 ;
} else {
V_20 -> V_51 . V_48 |= V_97 ;
}
#endif
V_22 |= V_23 ;
V_20 -> V_22 = V_22 ;
return;
}
static void F_39 ( void )
{
int V_98 ;
unsigned long V_21 ;
struct V_1 * V_2 = & V_99 [ 0 ] ;
char V_100 ;
if ( V_2 == 0 ) return;
if ( V_2 -> V_30 == 0 ) return;
F_8 ( V_21 ) ;
V_98 = V_2 -> V_29 ;
while ( V_98 != 0 ) {
V_100 = V_2 -> V_30 [ V_2 -> V_56 ] ;
V_2 -> V_56 = ( V_2 -> V_56 + 1 ) & ( V_57 - 1 ) ;
V_2 -> V_29 -- ;
F_9 ( V_21 ) ;
F_10 ( V_100 ) ;
F_8 ( V_21 ) ;
V_98 = F_40 ( V_2 -> V_29 , V_98 - 1 ) ;
}
F_11 ( 5 ) ;
F_9 ( V_21 ) ;
return;
}
void F_41 ( const char * V_101 )
{
char V_100 ;
while( ( V_100 = * ( V_101 ++ ) ) != 0 ) {
if( V_100 == '\n' )
F_10 ( '\r' ) ;
F_10 ( V_100 ) ;
}
F_39 () ;
return;
}
static void F_42 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_5 ) )
return;
V_2 -> V_38 = ( V_18 -> V_78 -> V_102 == V_103 ) ;
F_3 ( L_6 , V_2 -> line , V_2 -> V_38 ? L_7 : L_8 ) ;
}
static int F_43 ( struct V_17 * V_18 ,
const unsigned char * V_104 , int V_105 )
{
int V_100 , V_106 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_9 ) )
return 0 ;
if ( ! V_18 || ! V_2 -> V_30 )
return 0 ;
F_44 ( V_21 ) ;
while ( 1 ) {
F_45 () ;
V_100 = F_46 ( int , V_105 , F_40 ( V_57 - V_2 -> V_29 - 1 ,
V_57 - V_2 -> V_74 ) ) ;
F_9 ( V_21 ) ;
if ( V_100 <= 0 )
break;
memcpy ( V_2 -> V_30 + V_2 -> V_74 , V_104 , V_100 ) ;
F_45 () ;
V_2 -> V_74 = ( V_2 -> V_74 + V_100 ) & ( V_57 - 1 ) ;
V_2 -> V_29 += V_100 ;
F_9 ( V_21 ) ;
V_104 += V_100 ;
V_105 -= V_100 ;
V_106 += V_100 ;
}
if ( V_2 -> V_29 && ! V_18 -> V_55 && ! V_18 -> V_107 ) {
F_45 () ;
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
return V_106 ;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
int V_108 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_10 ) )
return 0 ;
V_108 = V_57 - V_2 -> V_29 - 1 ;
if ( V_108 < 0 )
V_108 = 0 ;
return V_108 ;
}
static int F_48 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_11 ) )
return 0 ;
return V_2 -> V_29 ;
}
static void F_49 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
unsigned long V_21 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_12 ) )
return;
F_8 ( V_21 ) ;
V_2 -> V_29 = V_2 -> V_74 = V_2 -> V_56 = 0 ;
F_9 ( V_21 ) ;
F_50 ( V_18 ) ;
}
static void F_51 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_13 ) )
return;
if ( F_52 ( V_18 ) )
V_2 -> V_50 = F_53 ( V_18 ) ;
}
static void F_54 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_14 ) )
return;
if ( F_52 ( V_18 ) ) {
if ( V_2 -> V_50 )
V_2 -> V_50 = 0 ;
else
V_2 -> V_50 = F_55 ( V_18 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
struct V_109 V_111 ;
if ( ! V_110 )
return - V_112 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . type = V_2 -> type ;
V_111 . line = V_2 -> line ;
V_111 . V_75 = V_2 -> V_75 ;
V_111 . V_60 = V_2 -> V_60 ;
V_111 . V_21 = V_2 -> V_21 ;
V_111 . V_113 = V_2 -> V_113 ;
V_111 . V_114 = V_2 -> V_114 ;
V_111 . V_115 = V_2 -> V_115 ;
V_111 . V_116 = V_2 -> V_116 ;
if ( F_57 ( V_110 , & V_111 , sizeof( * V_110 ) ) )
return - V_112 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_109 * V_117 )
{
struct V_109 V_118 ;
struct V_1 V_119 ;
int V_120 = 0 ;
if ( ! V_117 )
return - V_112 ;
if ( F_59 ( & V_118 , V_117 , sizeof( V_118 ) ) )
return - V_112 ;
V_119 = * V_2 ;
if ( ! F_60 ( V_121 ) ) {
if ( ( V_118 . V_113 != V_2 -> V_113 ) ||
( V_118 . type != V_2 -> type ) ||
( V_118 . V_114 != V_2 -> V_114 ) ||
( ( V_118 . V_21 & ~ V_122 ) !=
( V_2 -> V_21 & ~ V_122 ) ) )
return - V_123 ;
V_2 -> V_21 = ( ( V_2 -> V_21 & ~ V_122 ) |
( V_118 . V_21 & V_122 ) ) ;
V_2 -> V_116 = V_118 . V_116 ;
goto V_124;
}
if ( V_2 -> V_105 > 1 )
return - V_125 ;
V_2 -> V_113 = V_118 . V_113 ;
V_2 -> V_21 = ( ( V_2 -> V_21 & ~ V_126 ) |
( V_118 . V_21 & V_126 ) ) ;
V_2 -> type = V_118 . type ;
V_2 -> V_114 = V_118 . V_114 ;
V_2 -> V_115 = V_118 . V_115 ;
V_124:
V_120 = F_30 ( V_2 ) ;
return V_120 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int * V_127 )
{
#ifdef F_38
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
#endif
unsigned char V_32 ;
unsigned long V_21 ;
F_8 ( V_21 ) ;
#ifdef F_38
V_32 = ( V_20 -> V_51 . V_48 & V_128 ) ? 1 : 0 ;
#else
V_32 = 0 ;
#endif
F_9 ( V_21 ) ;
return F_62 ( V_32 , V_127 ) ;
}
static void F_63 ( struct V_1 * V_2 , unsigned int V_129 )
{
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( ! V_2 -> V_75 )
return;
F_8 ( V_21 ) ;
#ifdef F_13
V_20 -> V_51 . V_48 |= V_130 ;
F_64 ( V_129 ) ;
V_20 -> V_51 . V_48 &= ~ V_130 ;
#endif
F_9 ( V_21 ) ;
}
static int F_65 ( struct V_17 * V_18 ,
unsigned int V_131 , unsigned long V_132 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
int V_120 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_15 ) )
return - V_133 ;
if ( ( V_131 != V_134 ) && ( V_131 != V_135 ) &&
( V_131 != V_136 ) && ( V_131 != V_137 ) &&
( V_131 != V_138 ) && ( V_131 != V_139 ) ) {
if ( V_18 -> V_21 & ( 1 << V_73 ) )
return - V_140 ;
}
switch ( V_131 ) {
case V_141 :
V_120 = F_66 ( V_18 ) ;
if ( V_120 )
return V_120 ;
F_67 ( V_18 , 0 ) ;
if ( ! V_132 )
F_63 ( V_2 , 250 ) ;
return 0 ;
case V_142 :
V_120 = F_66 ( V_18 ) ;
if ( V_120 )
return V_120 ;
F_67 ( V_18 , 0 ) ;
F_63 ( V_2 , V_132 ? V_132 * ( 100 ) : 250 ) ;
return 0 ;
case V_134 :
return F_56 ( V_2 ,
(struct V_109 * ) V_132 ) ;
case V_135 :
return F_58 ( V_2 ,
(struct V_109 * ) V_132 ) ;
case V_143 :
return F_61 ( V_2 , ( unsigned int * ) V_132 ) ;
case V_139 :
if ( F_57 ( (struct V_1 * ) V_132 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_112 ;
return 0 ;
default:
return - V_144 ;
}
return 0 ;
}
static void F_68 ( struct V_17 * V_18 , struct V_145 * V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
F_33 ( V_2 ) ;
if ( ( V_146 -> V_79 & V_96 ) &&
! ( V_18 -> V_78 -> V_79 & V_96 ) ) {
V_18 -> V_107 = 0 ;
F_12 ( V_18 ) ;
}
}
static void F_69 ( struct V_17 * V_18 , struct V_147 * V_148 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
T_1 * V_20 = & V_13 [ V_2 -> line ] ;
unsigned long V_21 ;
if ( ! V_2 || F_1 ( V_2 , V_18 -> V_3 , L_16 ) )
return;
F_8 ( V_21 ) ;
if ( F_70 ( V_148 ) ) {
F_9 ( V_21 ) ;
return;
}
if ( ( V_18 -> V_105 == 1 ) && ( V_2 -> V_105 != 1 ) ) {
F_3 ( L_17
L_18 , V_2 -> V_105 ) ;
V_2 -> V_105 = 1 ;
}
if ( -- V_2 -> V_105 < 0 ) {
F_3 ( L_19 ,
V_2 -> line , V_2 -> V_105 ) ;
V_2 -> V_105 = 0 ;
}
if ( V_2 -> V_105 ) {
F_9 ( V_21 ) ;
return;
}
V_2 -> V_21 |= V_149 ;
V_18 -> V_150 = 1 ;
if ( V_2 -> V_115 != V_151 )
F_67 ( V_18 , V_2 -> V_115 ) ;
V_20 -> V_22 &= ~ V_71 ;
V_20 -> V_22 &= ~ ( V_71 | V_72 ) ;
F_34 ( V_2 ) ;
F_49 ( V_18 ) ;
F_71 ( V_18 ) ;
V_18 -> V_150 = 0 ;
V_2 -> V_152 = 0 ;
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
if ( V_2 -> V_153 ) {
if ( V_2 -> V_114 ) {
F_64 ( F_72 ( V_2 -> V_114 ) ) ;
}
F_73 ( & V_2 -> V_154 ) ;
}
V_2 -> V_21 &= ~ ( V_155 | V_149 ) ;
F_73 ( & V_2 -> V_156 ) ;
F_9 ( V_21 ) ;
}
void F_74 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 -> V_19 ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_20 ) )
return;
F_49 ( V_18 ) ;
F_34 ( V_2 ) ;
V_2 -> V_152 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_21 &= ~ V_155 ;
V_2 -> V_18 = NULL ;
F_73 ( & V_2 -> V_154 ) ;
}
static int F_75 ( struct V_17 * V_18 , struct V_147 * V_148 ,
struct V_1 * V_2 )
{
F_76 ( V_157 , V_158 ) ;
int V_120 ;
int V_159 = 0 ;
if ( V_2 -> V_21 & V_149 ) {
F_77 ( & V_2 -> V_156 ) ;
#ifdef F_78
if ( V_2 -> V_21 & V_160 )
return - V_161 ;
else
return - V_162 ;
#else
return - V_161 ;
#endif
}
if ( ( V_148 -> V_163 & V_164 ) ||
( V_18 -> V_21 & ( 1 << V_73 ) ) ) {
V_2 -> V_21 |= V_155 ;
return 0 ;
}
if ( V_18 -> V_78 -> V_79 & V_165 )
V_159 = 1 ;
V_120 = 0 ;
F_79 ( & V_2 -> V_154 , & V_157 ) ;
V_2 -> V_105 -- ;
V_2 -> V_153 ++ ;
while ( 1 ) {
F_45 () ;
F_4 ( V_2 , 1 ) ;
F_80 () ;
V_158 -> V_166 = V_167 ;
if ( F_70 ( V_148 ) ||
! ( V_2 -> V_21 & V_66 ) ) {
#ifdef F_78
if ( V_2 -> V_21 & V_160 )
V_120 = - V_161 ;
else
V_120 = - V_162 ;
#else
V_120 = - V_161 ;
#endif
break;
}
if ( ! ( V_2 -> V_21 & V_149 ) && V_159 )
break;
if ( F_81 ( V_158 ) ) {
V_120 = - V_162 ;
break;
}
F_82 () ;
F_83 () ;
F_84 () ;
}
V_158 -> V_166 = V_168 ;
F_85 ( & V_2 -> V_154 , & V_157 ) ;
if ( ! F_70 ( V_148 ) )
V_2 -> V_105 ++ ;
V_2 -> V_153 -- ;
if ( V_120 )
return V_120 ;
V_2 -> V_21 |= V_155 ;
return 0 ;
}
int F_86 ( struct V_17 * V_18 , struct V_147 * V_148 )
{
struct V_1 * V_2 ;
int V_120 , line ;
line = V_18 -> V_169 ;
if ( line >= V_170 || line < 0 )
return - V_133 ;
V_2 = & V_99 [ line ] ;
if ( F_1 ( V_2 , V_18 -> V_3 , L_21 ) )
return - V_133 ;
V_2 -> V_105 ++ ;
V_18 -> V_19 = V_2 ;
V_2 -> V_18 = V_18 ;
V_120 = F_30 ( V_2 ) ;
if ( V_120 )
return V_120 ;
return F_75 ( V_18 , V_148 , V_2 ) ;
}
static void F_87 ( void )
{
F_3 ( L_22 ) ;
}
static int T_3
F_88 ( void )
{
int V_21 , V_77 ;
struct V_1 * V_2 ;
V_171 = F_89 ( V_170 ) ;
if ( ! V_171 )
return - V_68 ;
F_87 () ;
V_171 -> V_3 = L_23 ;
V_171 -> V_172 = V_173 ;
V_171 -> V_174 = 64 ;
V_171 -> type = V_175 ;
V_171 -> V_176 = V_177 ;
V_171 -> V_178 = V_179 ;
V_171 -> V_178 . V_79 =
V_180 | V_92 | V_181 | V_182 | V_165 ;
V_171 -> V_21 = V_183 ;
F_90 ( V_171 , & V_184 ) ;
if ( F_91 ( V_171 ) ) {
F_92 ( V_171 ) ;
F_3 ( V_185 L_24 ) ;
return - V_68 ;
}
F_8 ( V_21 ) ;
for( V_77 = 0 ; V_77 < V_170 ; V_77 ++ ) {
V_2 = & V_99 [ V_77 ] ;
V_2 -> V_7 = V_8 ;
V_2 -> V_75 = ( int ) & V_13 [ V_77 ] ;
V_2 -> V_18 = NULL ;
V_2 -> V_60 = V_186 [ V_77 ] ;
V_2 -> V_116 = 16 ;
V_2 -> V_114 = 50 ;
V_2 -> V_115 = 3000 ;
V_2 -> V_50 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_153 = 0 ;
F_93 ( & V_2 -> V_59 , F_28 ) ;
F_94 ( & V_2 -> V_154 ) ;
F_94 ( & V_2 -> V_156 ) ;
V_2 -> line = V_77 ;
V_2 -> V_38 = 1 ;
F_3 ( L_25 , V_171 -> V_3 , V_2 -> line ,
V_2 -> V_75 , V_2 -> V_60 ) ;
F_3 ( L_26 ) ;
#ifdef F_95
if ( V_77 > 0 )
V_187 &= 0xCF ;
#endif
if ( F_96 ( V_186 [ V_77 ] ,
F_27 ,
V_188 ,
L_27 , V_2 ) )
F_97 ( L_28 ) ;
}
F_9 ( V_21 ) ;
return 0 ;
}
static void F_98 ( void )
{
unsigned short V_22 ;
int V_77 ;
V_22 = V_189 ;
V_189 = V_22 & ~ V_23 ;
V_190:
for ( V_77 = 0 ; V_77 < F_99 ( V_83 ) ; V_77 ++ )
if ( V_83 [ V_77 ] == V_191 )
break;
if ( V_77 >= F_99 ( V_83 ) ) {
V_191 = 9600 ;
goto V_190;
}
V_192 = F_37 ( V_16 , V_84 [ V_77 ] . V_85 ) |
F_37 ( V_15 , V_84 [ V_77 ] . V_86 ) ;
V_22 &= ~ ( V_87 | V_88 | V_89 | V_90 ) ;
V_22 |= V_90 ;
V_22 |= V_23 ;
V_189 = V_22 ;
V_193 = 1 ;
return;
}
int F_100 ( struct V_194 * V_195 , char * V_132 )
{
int V_77 , V_196 = V_197 ;
if ( ! V_195 )
return ( - 1 ) ;
if ( V_132 )
V_196 = F_101 ( V_132 , NULL , 0 ) ;
for ( V_77 = 0 ; V_77 < F_99 ( V_83 ) ; V_77 ++ )
if ( V_83 [ V_77 ] == V_196 )
break;
if ( V_77 < F_99 ( V_83 ) ) {
V_191 = V_196 ;
V_180 = 0 ;
if ( V_77 > 15 ) {
V_180 |= V_81 ;
V_77 -= 15 ;
}
V_180 |= V_77 ;
}
F_98 () ;
return ( 0 ) ;
}
static struct V_198 * F_102 ( struct V_194 * V_100 , int * V_169 )
{
* V_169 = V_100 -> V_169 ;
return V_171 ;
}
void F_103 ( struct V_194 * V_199 , const char * V_200 ,
unsigned int V_105 )
{
if ( ! V_193 )
F_98 () ;
while ( V_105 -- ) {
if ( * V_200 == '\n' )
F_10 ( '\r' ) ;
F_10 ( * V_200 ++ ) ;
}
}
static int T_3 F_104 ( void )
{
F_105 ( & V_201 ) ;
return 0 ;
}
