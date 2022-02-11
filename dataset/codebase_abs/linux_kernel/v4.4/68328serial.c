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
V_67 = V_2 -> V_67 ;
if ( ! V_67 )
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
if ( V_2 == NULL ) return;
if ( V_2 -> V_29 == NULL ) return;
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
if ( V_2 -> V_28 && ! V_17 -> V_52 ) {
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
int V_98 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_10 ) )
return 0 ;
V_98 = V_54 - V_2 -> V_28 - 1 ;
if ( V_98 < 0 )
V_98 = 0 ;
return V_98 ;
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
struct V_99 * V_100 )
{
struct V_99 V_101 ;
if ( ! V_100 )
return - V_102 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . type = V_2 -> type ;
V_101 . line = V_2 -> line ;
V_101 . V_67 = V_2 -> V_67 ;
V_101 . V_55 = V_2 -> V_55 ;
V_101 . V_20 = V_2 -> V_43 . V_20 ;
V_101 . V_103 = V_2 -> V_103 ;
V_101 . V_104 = V_2 -> V_43 . V_104 ;
V_101 . V_105 = V_2 -> V_43 . V_105 ;
V_101 . V_106 = V_2 -> V_106 ;
if ( F_53 ( V_100 , & V_101 , sizeof( * V_100 ) ) )
return - V_102 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_16 * V_17 ,
struct V_99 * V_107 )
{
struct V_108 * V_67 = & V_2 -> V_43 ;
struct V_99 V_109 ;
struct V_1 V_110 ;
int V_111 = 0 ;
if ( ! V_107 )
return - V_102 ;
if ( F_55 ( & V_109 , V_107 , sizeof( V_109 ) ) )
return - V_102 ;
V_110 = * V_2 ;
if ( ! F_56 ( V_112 ) ) {
if ( ( V_109 . V_103 != V_2 -> V_103 ) ||
( V_109 . type != V_2 -> type ) ||
( V_109 . V_104 != V_67 -> V_104 ) ||
( ( V_109 . V_20 & ~ V_113 ) !=
( V_67 -> V_20 & ~ V_113 ) ) )
return - V_114 ;
V_67 -> V_20 = ( ( V_67 -> V_20 & ~ V_113 ) |
( V_109 . V_20 & V_113 ) ) ;
V_2 -> V_106 = V_109 . V_106 ;
goto V_115;
}
if ( V_67 -> V_96 > 1 )
return - V_116 ;
V_2 -> V_103 = V_109 . V_103 ;
V_67 -> V_20 = ( ( V_67 -> V_20 & ~ V_117 ) |
( V_109 . V_20 & V_117 ) ) ;
V_2 -> type = V_109 . type ;
V_67 -> V_104 = V_109 . V_104 ;
V_67 -> V_105 = V_109 . V_105 ;
V_115:
V_111 = F_26 ( V_2 , V_17 ) ;
return V_111 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int * V_118 )
{
#ifdef F_34
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
#endif
unsigned char V_119 ;
unsigned long V_20 ;
F_7 ( V_20 ) ;
#ifdef F_34
V_119 = ( V_19 -> V_48 . V_45 & V_120 ) ? 1 : 0 ;
#else
V_119 = 0 ;
#endif
F_8 ( V_20 ) ;
return F_58 ( V_119 , V_118 ) ;
}
static void F_59 ( struct V_1 * V_2 , unsigned int V_121 )
{
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( ! V_2 -> V_67 )
return;
F_7 ( V_20 ) ;
#ifdef F_12
V_19 -> V_48 . V_45 |= V_122 ;
F_60 ( V_121 ) ;
V_19 -> V_48 . V_45 &= ~ V_122 ;
#endif
F_8 ( V_20 ) ;
}
static int F_61 ( struct V_16 * V_17 ,
unsigned int V_123 , unsigned long V_124 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
int V_111 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_15 ) )
return - V_125 ;
if ( ( V_123 != V_126 ) && ( V_123 != V_127 ) &&
( V_123 != V_128 ) && ( V_123 != V_129 ) &&
( V_123 != V_130 ) && ( V_123 != V_131 ) ) {
if ( V_17 -> V_20 & ( 1 << V_65 ) )
return - V_132 ;
}
switch ( V_123 ) {
case V_133 :
V_111 = F_62 ( V_17 ) ;
if ( V_111 )
return V_111 ;
F_63 ( V_17 , 0 ) ;
if ( ! V_124 )
F_59 ( V_2 , 250 ) ;
return 0 ;
case V_134 :
V_111 = F_62 ( V_17 ) ;
if ( V_111 )
return V_111 ;
F_63 ( V_17 , 0 ) ;
F_59 ( V_2 , V_124 ? V_124 * ( 100 ) : 250 ) ;
return 0 ;
case V_126 :
return F_52 ( V_2 ,
(struct V_99 * ) V_124 ) ;
case V_127 :
return F_54 ( V_2 , V_17 ,
(struct V_99 * ) V_124 ) ;
case V_135 :
return F_57 ( V_2 , ( unsigned int * ) V_124 ) ;
case V_131 :
if ( F_53 ( (struct V_1 * ) V_124 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_102 ;
return 0 ;
default:
return - V_136 ;
}
return 0 ;
}
static void F_64 ( struct V_16 * V_17 , struct V_137 * V_138 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
F_29 ( V_2 , V_17 ) ;
if ( ( V_138 -> V_71 & V_87 ) &&
! ( V_17 -> V_70 . V_71 & V_87 ) )
F_11 ( V_17 ) ;
}
static void F_65 ( struct V_16 * V_17 , struct V_139 * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 -> V_18 ;
struct V_108 * V_67 = & V_2 -> V_43 ;
T_1 * V_19 = & V_12 [ V_2 -> line ] ;
unsigned long V_20 ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_16 ) )
return;
F_7 ( V_20 ) ;
if ( F_66 ( V_140 ) ) {
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
V_67 -> V_20 |= V_141 ;
V_17 -> V_142 = 1 ;
if ( V_67 -> V_105 != V_143 )
F_63 ( V_17 , V_67 -> V_105 ) ;
V_19 -> V_21 &= ~ V_63 ;
V_19 -> V_21 &= ~ ( V_63 | V_64 ) ;
F_30 ( V_2 , V_17 ) ;
F_45 ( V_17 ) ;
F_67 ( V_17 ) ;
V_17 -> V_142 = 0 ;
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
if ( V_67 -> V_144 ) {
if ( V_67 -> V_104 )
F_60 ( F_69 ( V_67 -> V_104 ) ) ;
F_70 ( & V_67 -> V_145 ) ;
}
V_67 -> V_20 &= ~ ( V_146 | V_141 ) ;
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
V_2 -> V_43 . V_20 &= ~ V_146 ;
F_68 ( & V_2 -> V_43 , NULL ) ;
F_70 ( & V_2 -> V_43 . V_145 ) ;
}
int F_72 ( struct V_16 * V_17 , struct V_139 * V_140 )
{
struct V_1 * V_2 ;
int V_111 ;
V_2 = & V_90 [ V_17 -> V_147 ] ;
if ( F_1 ( V_2 , V_17 -> V_3 , L_21 ) )
return - V_125 ;
V_2 -> V_43 . V_96 ++ ;
V_17 -> V_18 = V_2 ;
F_68 ( & V_2 -> V_43 , V_17 ) ;
V_111 = F_26 ( V_2 , V_17 ) ;
if ( V_111 )
return V_111 ;
return F_73 ( & V_2 -> V_43 , V_17 , V_140 ) ;
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
V_148 = F_76 ( V_149 ) ;
if ( ! V_148 )
return - V_61 ;
F_74 () ;
V_148 -> V_3 = L_23 ;
V_148 -> V_150 = V_151 ;
V_148 -> V_152 = 64 ;
V_148 -> type = V_153 ;
V_148 -> V_154 = V_155 ;
V_148 -> V_156 = V_157 ;
V_148 -> V_156 . V_71 =
V_158 | V_83 | V_159 | V_160 | V_161 ;
V_148 -> V_20 = V_162 ;
F_77 ( V_148 , & V_163 ) ;
F_7 ( V_20 ) ;
for( V_69 = 0 ; V_69 < V_149 ; V_69 ++ ) {
V_2 = & V_90 [ V_69 ] ;
F_78 ( & V_2 -> V_43 ) ;
V_2 -> V_43 . V_164 = & V_165 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_67 = ( int ) & V_12 [ V_69 ] ;
V_2 -> V_55 = V_166 [ V_69 ] ;
V_2 -> V_106 = 16 ;
V_2 -> V_47 = 0 ;
V_2 -> line = V_69 ;
V_2 -> V_34 = 1 ;
F_3 ( L_24 , V_148 -> V_3 , V_2 -> line ,
V_2 -> V_67 , V_2 -> V_55 ) ;
F_3 ( L_25 ) ;
#ifdef F_79
if ( V_69 > 0 )
V_167 &= 0xCF ;
#endif
if ( F_80 ( V_166 [ V_69 ] ,
F_23 ,
0 ,
L_26 , V_2 ) )
F_81 ( L_27 ) ;
F_82 ( & V_2 -> V_43 , V_148 , V_69 ) ;
}
F_8 ( V_20 ) ;
if ( F_83 ( V_148 ) ) {
F_84 ( V_148 ) ;
for ( V_69 = 0 ; V_69 < V_149 ; V_69 ++ )
F_85 ( & V_90 [ V_69 ] . V_43 ) ;
F_3 ( V_168 L_28 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_86 ( void )
{
unsigned short V_21 ;
int V_69 ;
V_21 = V_169 ;
V_169 = V_21 & ~ V_22 ;
V_170:
for ( V_69 = 0 ; V_69 < F_87 ( V_171 ) ; V_69 ++ )
if ( V_171 [ V_69 ] == V_172 )
break;
if ( V_69 >= F_87 ( V_171 ) ) {
V_172 = 9600 ;
goto V_170;
}
V_173 = F_33 ( V_15 , V_75 [ V_69 ] . V_76 ) |
F_33 ( V_14 , V_75 [ V_69 ] . V_77 ) ;
V_21 &= ~ ( V_78 | V_79 | V_80 | V_81 ) ;
V_21 |= V_81 ;
V_21 |= V_22 ;
V_169 = V_21 ;
V_174 = 1 ;
return;
}
int F_88 ( struct V_175 * V_176 , char * V_124 )
{
int V_69 , V_177 = V_178 ;
if ( ! V_176 )
return ( - 1 ) ;
if ( V_124 )
V_177 = F_89 ( V_124 , NULL , 0 ) ;
for ( V_69 = 0 ; V_69 < F_87 ( V_171 ) ; V_69 ++ )
if ( V_171 [ V_69 ] == V_177 )
break;
if ( V_69 < F_87 ( V_171 ) ) {
V_172 = V_177 ;
V_158 = 0 ;
if ( V_69 > 15 ) {
V_158 |= V_73 ;
V_69 -= 15 ;
}
V_158 |= V_69 ;
}
F_86 () ;
return ( 0 ) ;
}
static struct V_179 * F_90 ( struct V_175 * V_91 , int * V_147 )
{
* V_147 = V_91 -> V_147 ;
return V_148 ;
}
void F_91 ( struct V_175 * V_180 , const char * V_181 ,
unsigned int V_96 )
{
if ( ! V_174 )
F_86 () ;
while ( V_96 -- ) {
if ( * V_181 == '\n' )
F_9 ( '\r' ) ;
F_9 ( * V_181 ++ ) ;
}
}
static int T_3 F_92 ( void )
{
F_93 ( & V_182 ) ;
return 0 ;
}
