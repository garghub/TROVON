static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( int V_1 , int V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static void F_5 ( unsigned long V_4 )
{
while ( V_4 > V_5 ) {
F_6 ( V_5 ) ;
V_4 -= V_5 ;
}
F_6 ( V_4 ) ;
}
static unsigned int F_7 ( struct V_6 * V_6 , T_1 * V_7 )
{
F_8 ( V_6 , & V_8 , V_7 ) ;
if ( V_9 != V_10 )
return V_11 | V_12 ;
return 0 ;
}
static T_2 F_9 ( struct V_6 * V_6 , char T_3 * V_13 , T_4 V_14 ,
T_5 * V_15 )
{
int V_16 = 0 ;
int V_17 = 0 ;
F_10 ( V_7 , V_18 ) ;
if ( V_14 % sizeof( int ) )
return - V_19 ;
F_11 ( & V_8 , & V_7 ) ;
F_12 ( V_20 ) ;
while ( V_16 < V_14 ) {
if ( V_9 != V_10 ) {
if ( F_13 ( V_13 + V_16 ,
V_21 + V_9 ,
sizeof( int ) ) ) {
V_17 = - V_22 ;
break;
}
V_9 = ( V_9 + 1 ) & ( V_23 - 1 ) ;
V_16 += sizeof( int ) ;
} else {
if ( V_6 -> V_24 & V_25 ) {
V_17 = - V_26 ;
break;
}
if ( F_14 ( V_18 ) ) {
V_17 = - V_27 ;
break;
}
F_15 () ;
F_12 ( V_20 ) ;
}
}
F_16 ( & V_8 , & V_7 ) ;
F_12 ( V_28 ) ;
return V_16 ? V_16 : V_17 ;
}
static T_2 F_17 ( struct V_6 * V_6 , const char T_3 * V_13 , T_4 V_16 ,
T_5 * V_29 )
{
unsigned long V_30 ;
int V_31 , V_14 ;
int * V_32 ;
V_14 = V_16 / sizeof( int ) ;
if ( V_16 % sizeof( int ) || V_14 % 2 == 0 )
return - V_19 ;
V_32 = F_18 ( V_13 , V_16 ) ;
if ( F_19 ( V_32 ) )
return F_20 ( V_32 ) ;
V_31 = 0 ;
F_21 ( V_30 ) ;
while ( 1 ) {
if ( V_31 >= V_14 )
break;
if ( V_32 [ V_31 ] )
F_22 ( V_32 [ V_31 ] ) ;
V_31 ++ ;
if ( V_31 >= V_14 )
break;
if ( V_32 [ V_31 ] )
F_23 ( V_32 [ V_31 ] ) ;
V_31 ++ ;
}
F_24 ( V_30 ) ;
F_25 ( V_32 ) ;
return V_14 ;
}
static long F_26 ( struct V_6 * V_33 , unsigned int V_34 , unsigned long V_35 )
{
T_6 T_3 * V_36 = ( T_6 T_3 * ) V_35 ;
int V_17 = 0 ;
T_6 V_3 = 0 ;
if ( V_34 == V_37 )
V_3 = V_38 | V_39 ;
else if ( V_34 == V_40 )
V_3 = V_41 ;
else if ( V_34 == V_42 )
V_3 = V_43 ;
switch ( V_34 ) {
case V_37 :
case V_40 :
case V_42 :
V_17 = F_27 ( V_3 , V_36 ) ;
break;
case V_44 :
case V_45 :
V_17 = F_28 ( V_3 , V_36 ) ;
break;
default:
V_17 = - V_46 ;
}
if ( V_17 )
return V_17 ;
if ( V_34 == V_45 ) {
if ( V_3 != V_43 )
V_17 = - V_47 ;
} else if ( V_34 == V_44 ) {
if ( V_3 != V_41 )
V_17 = - V_47 ;
}
return V_17 ;
}
static void F_29 ( int V_48 , unsigned long V_49 )
{
unsigned int V_50 ;
int V_51 ;
F_30 ( L_1 , V_48 , V_49 ) ;
V_51 = V_49 & V_52 ;
if ( V_48 ) {
if ( V_51 > V_53 / 2 )
V_51 -= V_53 / 2 ;
else
V_51 = 1 ;
V_51 |= V_54 ;
} else {
V_51 += V_53 / 2 ;
}
V_50 = ( V_10 + 1 ) & ( V_23 - 1 ) ;
if ( V_50 == V_9 ) {
F_30 ( L_2 ) ;
return;
}
V_21 [ V_10 ] = V_51 ;
V_10 = V_50 ;
F_31 ( & V_8 ) ;
}
static int F_32 ( void * V_55 )
{
return 0 ;
}
static void F_33 ( void * V_55 )
{
}
static int F_34 ( void )
{
V_56 . V_57 = & V_58 -> V_57 ;
V_56 . V_59 = F_35 ( & V_56 ) ;
if ( V_56 . V_59 < 0 ) {
F_36 ( L_3 ) ;
return - V_60 ;
}
return 0 ;
}
static void F_37 ( void )
{
F_38 ( V_56 . V_59 ) ;
}
static void F_39 ( unsigned long V_55 )
{
unsigned long V_30 ;
unsigned long V_61 ;
F_40 ( & V_62 , V_30 ) ;
if ( V_63 ) {
F_4 ( V_64 , V_2 + V_65 ) ;
V_61 = F_41 (unsigned long,
ktime_us_delta(last, last_intr_time),
PULSE_MASK) ;
F_42 ( V_56 . V_57 , L_4 ,
V_63 , V_61 ) ;
F_29 ( V_63 , V_61 ) ;
V_63 = 0 ;
V_66 = V_67 ;
}
F_43 ( & V_62 , V_30 ) ;
}
static T_7 F_44 ( int V_68 , void * V_69 )
{
unsigned char V_55 ;
T_8 V_70 ;
static unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_30 ;
int V_73 , V_74 ;
while ( ( V_73 = F_2 ( V_2 + V_75 ) & V_76 ) ) {
switch ( V_73 & V_76 ) {
case V_77 :
( void ) F_2 ( V_2 + V_78 ) ;
break;
case V_79 :
( void ) F_2 ( V_2 + V_80 ) ;
break;
case V_81 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_82 :
F_40 ( & V_62 , V_30 ) ;
do {
F_45 ( & V_83 ) ;
V_55 = F_2 ( V_2 + V_84 ) ;
V_70 = F_46 () ;
V_71 = F_41 (unsigned long,
ktime_us_delta(last, curr_time),
PULSE_MASK) ;
V_72 = F_41 (unsigned long,
ktime_us_delta(last_intr_time,
curr_time),
PULSE_MASK) ;
F_42 ( V_56 . V_57 , L_5 ,
V_72 , ( int ) V_55 ) ;
if ( V_72 > V_53 * V_85 ) {
if ( V_63 ) {
F_42 ( V_56 . V_57 , L_6 ) ;
F_29 ( V_63 ,
V_71 -
V_72 ) ;
V_63 = 0 ;
V_66 = V_67 ;
V_71 = V_72 ;
}
}
V_55 = 1 ;
if ( V_55 ^ V_63 ) {
F_29 ( V_63 ,
V_71 - V_53 ) ;
V_63 = V_55 ;
V_66 = V_70 ;
V_66 = F_47 ( V_66 ,
V_53 ) ;
}
V_67 = V_70 ;
if ( V_55 ) {
V_83 . V_86 = V_87 +
V_88 ;
F_48 ( & V_83 ) ;
}
V_74 = F_2 ( V_2 + V_80 ) ;
} while ( V_74 & V_89 );
F_43 ( & V_62 , V_30 ) ;
break;
default:
break;
}
}
return F_49 ( V_90 ) ;
}
static void F_23 ( unsigned long V_91 )
{
F_5 ( V_91 ) ;
}
static void F_22 ( unsigned long V_91 )
{
long V_92 = V_91 / V_53 ;
if ( V_92 == 0 )
V_92 ++ ;
while ( V_92 -- ) {
F_4 ( V_93 , V_2 + V_94 ) ;
while ( ! ( F_2 ( V_2 + V_80 ) & V_95 ) )
;
}
}
static int F_50 ( void )
{
unsigned long V_30 ;
F_40 ( & V_96 , V_30 ) ;
#if F_51 ( V_97 )
F_3 ( V_65 ,
V_64 |
V_98 |
V_99 ) ;
F_3 ( V_100 , F_1 ( V_100 ) & ( ~ V_101 ) ) ;
F_3 ( V_102 , F_1 ( V_102 ) &
( ~ ( V_103 | V_104 | V_105 | V_106 ) ) ) ;
F_3 ( V_100 , F_1 ( V_100 ) | V_101 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 12 ) ;
F_3 ( V_100 , F_1 ( V_100 ) & ( ~ V_101 ) ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
F_5 ( 50 * 1000 ) ;
F_3 ( V_109 , V_110 | V_112 ) ;
F_6 ( 1 * 1000 ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
F_6 ( 100 ) ;
F_3 ( V_109 , V_111 | V_112 ) ;
F_6 ( 7 ) ;
F_3 ( V_94 , V_113 | V_114 ) ;
F_6 ( 1500 ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_52 ( L_7 , F_1 ( V_84 ) ) ;
F_3 ( V_100 , F_1 ( V_100 ) | V_101 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 1 ) ;
F_3 ( V_100 , V_115 ) ;
F_3 ( V_102 , F_1 ( V_102 ) | V_106 ) ;
#else
F_4 ( 0 , V_2 + V_109 ) ;
F_4 ( 0 , V_2 + V_102 ) ;
F_4 ( V_101 | V_116 , V_2 + V_100 ) ;
F_4 ( 1 , V_2 + V_108 ) ; F_4 ( 0 , V_2 + V_107 ) ;
F_4 ( V_116 , V_2 + V_100 ) ;
F_4 ( V_117 , V_2 + V_65 ) ;
F_4 ( V_106 , V_2 + V_102 ) ;
F_4 ( V_111 | V_110 | V_112 , V_2 + V_109 ) ;
#ifdef F_53
F_54 () ;
#elif F_51 ( V_118 )
F_55 () ;
#endif
#endif
F_43 ( & V_96 , V_30 ) ;
return 0 ;
}
static void F_56 ( void )
{
unsigned long V_30 ;
F_40 ( & V_96 , V_30 ) ;
F_4 ( 0 , V_2 + V_102 ) ;
F_43 ( & V_96 , V_30 ) ;
}
static int F_57 ( void )
{
int V_17 ;
if ( F_58 ( V_2 , 8 , V_119 ) == NULL ) {
F_36 ( L_8 , V_2 ) ;
return - V_120 ;
}
V_17 = F_59 ( V_68 , F_44 , 0 ,
V_119 , NULL ) ;
if ( V_17 < 0 ) {
F_60 ( V_2 , 8 ) ;
F_36 ( L_9 , V_68 ) ;
return V_17 ;
}
F_52 ( L_10 , V_2 , V_68 ) ;
F_61 ( & V_83 , F_39 , 0 ) ;
return 0 ;
}
static void F_62 ( void )
{
F_63 ( V_68 , NULL ) ;
F_64 ( & V_83 ) ;
F_60 ( V_2 , 8 ) ;
}
static void F_54 ( void )
{
int V_31 ;
T_9 V_121 [] = {
V_122 ,
V_123 | V_124 ,
V_125 | V_126 | V_127 ,
V_123 ,
V_128 | V_129 ,
V_130 | V_131 | V_132 ,
V_133 | V_134 ,
V_135 | V_136 | V_137 | V_138 ,
V_139 | V_140 ,
V_141 | V_142 | V_143 ,
V_144 | ( V_145 & 0x0f ) ,
V_146 | ( ( V_145 >> 4 ) & 0x0f ) ,
V_147 | V_148 | V_149
} ;
F_3 ( V_100 , V_101 | V_115 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 12 ) ;
F_3 ( V_100 , V_115 ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
for ( V_31 = 0 ; V_31 < 50 ; V_31 ++ )
F_5 ( 1000 ) ;
F_3 ( V_109 , V_111 | V_112 ) ;
for ( V_31 = 0 ; V_31 < 25 ; V_31 ++ )
F_6 ( 1000 ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
F_6 ( 100 ) ;
F_3 ( V_109 , V_110 | V_112 ) ;
F_6 ( 7 ) ;
for ( V_31 = 0 ; V_31 < sizeof( V_121 ) ; V_31 ++ ) {
F_3 ( V_94 , V_121 [ V_31 ] ) ;
F_6 ( 1500 ) ;
}
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_3 ( V_100 , F_1 ( V_100 ) | V_101 ) ;
F_3 ( V_100 , V_101 | V_116 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 1 ) ;
F_3 ( V_100 , F_1 ( V_100 ) & ( ~ V_101 ) ) ;
F_3 ( V_100 , V_116 ) ;
F_3 ( V_102 , F_1 ( V_102 ) | V_106 ) ;
}
void F_55 ( void )
{
int V_31 ;
F_3 ( V_100 , V_101 | V_116 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 12 ) ;
F_3 ( V_100 , V_116 ) ;
F_3 ( V_109 , V_110 | V_112 ) ;
F_6 ( 10 ) ;
F_3 ( V_109 , V_111 | V_110 | V_112 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
F_6 ( 10 ) ;
F_3 ( V_109 , V_111 | V_112 ) ;
F_6 ( 10 ) ;
F_3 ( V_109 , V_110 | V_111 | V_112 ) ;
}
F_6 ( 1500 ) ;
F_3 ( V_100 , V_101 | V_116 ) ;
F_3 ( V_107 , 0 ) ;
F_3 ( V_108 , 1 ) ;
F_3 ( V_100 , V_116 ) ;
F_3 ( V_102 , V_106 ) ;
}
static int F_65 ( void )
{
int V_17 ;
F_66 ( & V_8 ) ;
V_17 = F_57 () ;
if ( V_17 < 0 )
return V_17 ;
F_50 () ;
F_52 ( L_11 ) ;
return 0 ;
}
static int F_67 ( struct V_150 * V_57 )
{
return 0 ;
}
static int F_68 ( struct V_150 * V_57 )
{
return 0 ;
}
static int T_10 F_69 ( void )
{
int V_17 ;
V_17 = F_70 ( & V_151 ) ;
if ( V_17 ) {
F_36 ( L_12 ) ;
return - V_152 ;
}
V_58 = F_71 ( L_13 , 0 ) ;
if ( ! V_58 ) {
F_36 ( L_14 ) ;
V_17 = - V_153 ;
goto V_154;
}
V_17 = F_72 ( V_58 ) ;
if ( V_17 ) {
F_36 ( L_15 ) ;
V_17 = - V_152 ;
goto V_155;
}
V_17 = F_34 () ;
if ( V_17 < 0 )
goto V_156;
V_17 = F_65 () ;
if ( V_17 ) {
F_37 () ;
goto V_156;
}
return 0 ;
V_156:
F_73 ( V_58 ) ;
V_155:
F_74 ( V_58 ) ;
V_154:
F_75 ( & V_151 ) ;
return V_17 ;
}
static void T_11 F_76 ( void )
{
F_56 () ;
F_37 () ;
F_62 () ;
F_77 ( V_58 ) ;
F_75 ( & V_151 ) ;
F_52 ( L_16 ) ;
}
