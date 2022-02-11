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
static long F_39 ( struct V_61 * V_62 , struct V_61 * V_63 )
{
unsigned long V_64 ;
V_64 = V_63 -> V_65 - V_62 -> V_65 ;
if ( V_64 > 15 )
V_64 = 0xFFFFFF ;
else
V_64 = V_64 * 1000000 +
V_63 -> V_66 -
V_62 -> V_66 ;
return V_64 ;
}
static void F_40 ( unsigned long V_55 )
{
unsigned long V_30 ;
unsigned long V_67 ;
F_41 ( & V_68 , V_30 ) ;
if ( V_69 ) {
F_4 ( V_70 , V_2 + V_71 ) ;
V_67 = F_39 ( & V_72 , & V_73 ) ;
F_42 ( V_56 . V_57 , L_4 ,
V_69 , V_67 ) ;
F_29 ( V_69 , V_67 ) ;
V_69 = 0 ;
V_72 = V_73 ;
}
F_43 ( & V_68 , V_30 ) ;
}
static T_7 F_44 ( int V_74 , void * V_75 )
{
unsigned char V_55 ;
struct V_61 V_76 ;
static unsigned long V_64 ;
unsigned long V_77 ;
unsigned long V_30 ;
int V_78 , V_79 ;
while ( ( V_78 = F_2 ( V_2 + V_80 ) & V_81 ) ) {
switch ( V_78 & V_81 ) {
case V_82 :
( void ) F_2 ( V_2 + V_83 ) ;
break;
case V_84 :
( void ) F_2 ( V_2 + V_85 ) ;
break;
case V_86 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_87 :
F_41 ( & V_68 , V_30 ) ;
do {
F_45 ( & V_88 ) ;
V_55 = F_2 ( V_2 + V_89 ) ;
F_46 ( & V_76 ) ;
V_64 = F_39 ( & V_72 , & V_76 ) ;
V_77 = F_39 ( & V_73 , & V_76 ) ;
F_42 ( V_56 . V_57 , L_5 ,
V_77 , ( int ) V_55 ) ;
if ( V_77 > V_53 * V_90 ) {
if ( V_69 ) {
F_42 ( V_56 . V_57 , L_6 ) ;
F_29 ( V_69 ,
V_64 -
V_77 ) ;
V_69 = 0 ;
V_72 . V_65 =
V_73 . V_65 ;
V_72 . V_66 =
V_73 . V_66 ;
V_64 = V_77 ;
}
}
V_55 = 1 ;
if ( V_55 ^ V_69 ) {
F_29 ( V_69 ,
V_64 - V_53 ) ;
V_69 = V_55 ;
V_72 = V_76 ;
if ( V_72 . V_66 >= V_53 ) {
V_72 . V_66 -= V_53 ;
} else {
V_72 . V_65 -- ;
V_72 . V_66 += 1000000 -
V_53 ;
}
}
V_73 = V_76 ;
if ( V_55 ) {
V_88 . V_91 = V_92 +
V_93 ;
F_47 ( & V_88 ) ;
}
V_79 = F_2 ( V_2 + V_85 ) ;
} while ( V_79 & V_94 );
F_43 ( & V_68 , V_30 ) ;
break;
default:
break;
}
}
return F_48 ( V_95 ) ;
}
static void F_23 ( unsigned long V_96 )
{
F_5 ( V_96 ) ;
}
static void F_22 ( unsigned long V_96 )
{
long V_97 = V_96 / V_53 ;
if ( V_97 == 0 )
V_97 ++ ;
while ( V_97 -- ) {
F_4 ( V_98 , V_2 + V_99 ) ;
while ( ! ( F_2 ( V_2 + V_85 ) & V_100 ) )
;
}
}
static int F_49 ( void )
{
unsigned long V_30 ;
F_41 ( & V_101 , V_30 ) ;
#if F_50 ( V_102 )
F_3 ( V_71 ,
V_70 |
V_103 |
V_104 ) ;
F_3 ( V_105 , F_1 ( V_105 ) & ( ~ V_106 ) ) ;
F_3 ( V_107 , F_1 ( V_107 ) &
( ~ ( V_108 | V_109 | V_110 | V_111 ) ) ) ;
F_3 ( V_105 , F_1 ( V_105 ) | V_106 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 12 ) ;
F_3 ( V_105 , F_1 ( V_105 ) & ( ~ V_106 ) ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
F_5 ( 50 * 1000 ) ;
F_3 ( V_114 , V_115 | V_117 ) ;
F_6 ( 1 * 1000 ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
F_6 ( 100 ) ;
F_3 ( V_114 , V_116 | V_117 ) ;
F_6 ( 7 ) ;
F_3 ( V_99 , V_118 | V_119 ) ;
F_6 ( 1500 ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_51 ( L_7 , F_1 ( V_89 ) ) ;
F_3 ( V_105 , F_1 ( V_105 ) | V_106 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 1 ) ;
F_3 ( V_105 , V_120 ) ;
F_3 ( V_107 , F_1 ( V_107 ) | V_111 ) ;
#else
F_4 ( 0 , V_2 + V_114 ) ;
F_4 ( 0 , V_2 + V_107 ) ;
F_4 ( V_106 | V_121 , V_2 + V_105 ) ;
F_4 ( 1 , V_2 + V_113 ) ; F_4 ( 0 , V_2 + V_112 ) ;
F_4 ( V_121 , V_2 + V_105 ) ;
F_4 ( V_122 , V_2 + V_71 ) ;
F_4 ( V_111 , V_2 + V_107 ) ;
F_4 ( V_116 | V_115 | V_117 , V_2 + V_114 ) ;
#ifdef F_52
F_53 () ;
#elif F_50 ( V_123 )
F_54 () ;
#endif
#endif
F_43 ( & V_101 , V_30 ) ;
return 0 ;
}
static void F_55 ( void )
{
unsigned long V_30 ;
F_41 ( & V_101 , V_30 ) ;
F_4 ( 0 , V_2 + V_107 ) ;
F_43 ( & V_101 , V_30 ) ;
}
static int F_56 ( void )
{
int V_17 ;
if ( F_57 ( V_2 , 8 , V_124 ) == NULL ) {
F_36 ( L_8 , V_2 ) ;
return - V_125 ;
}
V_17 = F_58 ( V_74 , F_44 , 0 ,
V_124 , NULL ) ;
if ( V_17 < 0 ) {
F_59 ( V_2 , 8 ) ;
F_36 ( L_9 , V_74 ) ;
return V_17 ;
}
F_51 ( L_10 , V_2 , V_74 ) ;
F_60 ( & V_88 , F_40 , 0 ) ;
return 0 ;
}
static void F_61 ( void )
{
F_62 ( V_74 , NULL ) ;
F_63 ( & V_88 ) ;
F_59 ( V_2 , 8 ) ;
}
static void F_53 ( void )
{
int V_31 ;
T_8 V_126 [] = {
V_127 ,
V_128 | V_129 ,
V_130 | V_131 | V_132 ,
V_128 ,
V_133 | V_134 ,
V_135 | V_136 | V_137 ,
V_138 | V_139 ,
V_140 | V_141 | V_142 | V_143 ,
V_144 | V_145 ,
V_146 | V_147 | V_148 ,
V_149 | ( V_150 & 0x0f ) ,
V_151 | ( ( V_150 >> 4 ) & 0x0f ) ,
V_152 | V_153 | V_154
} ;
F_3 ( V_105 , V_106 | V_120 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 12 ) ;
F_3 ( V_105 , V_120 ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
for ( V_31 = 0 ; V_31 < 50 ; V_31 ++ )
F_5 ( 1000 ) ;
F_3 ( V_114 , V_116 | V_117 ) ;
for ( V_31 = 0 ; V_31 < 25 ; V_31 ++ )
F_6 ( 1000 ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
F_6 ( 100 ) ;
F_3 ( V_114 , V_115 | V_117 ) ;
F_6 ( 7 ) ;
for ( V_31 = 0 ; V_31 < sizeof( V_126 ) ; V_31 ++ ) {
F_3 ( V_99 , V_126 [ V_31 ] ) ;
F_6 ( 1500 ) ;
}
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_3 ( V_105 , F_1 ( V_105 ) | V_106 ) ;
F_3 ( V_105 , V_106 | V_121 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 1 ) ;
F_3 ( V_105 , F_1 ( V_105 ) & ( ~ V_106 ) ) ;
F_3 ( V_105 , V_121 ) ;
F_3 ( V_107 , F_1 ( V_107 ) | V_111 ) ;
}
void F_54 ( void )
{
int V_31 ;
F_3 ( V_105 , V_106 | V_121 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 12 ) ;
F_3 ( V_105 , V_121 ) ;
F_3 ( V_114 , V_115 | V_117 ) ;
F_6 ( 10 ) ;
F_3 ( V_114 , V_116 | V_115 | V_117 ) ;
for ( V_31 = 0 ; V_31 < 3 ; V_31 ++ ) {
F_6 ( 10 ) ;
F_3 ( V_114 , V_116 | V_117 ) ;
F_6 ( 10 ) ;
F_3 ( V_114 , V_115 | V_116 | V_117 ) ;
}
F_6 ( 1500 ) ;
F_3 ( V_105 , V_106 | V_121 ) ;
F_3 ( V_112 , 0 ) ;
F_3 ( V_113 , 1 ) ;
F_3 ( V_105 , V_121 ) ;
F_3 ( V_107 , V_111 ) ;
}
static int F_64 ( void )
{
int V_17 ;
F_65 ( & V_8 ) ;
V_17 = F_56 () ;
if ( V_17 < 0 )
return V_17 ;
F_49 () ;
F_51 ( L_11 ) ;
return 0 ;
}
static int F_66 ( struct V_155 * V_57 )
{
return 0 ;
}
static int F_67 ( struct V_155 * V_57 )
{
return 0 ;
}
static int T_9 F_68 ( void )
{
int V_17 ;
V_17 = F_69 ( & V_156 ) ;
if ( V_17 ) {
F_36 ( L_12 ) ;
return - V_157 ;
}
V_58 = F_70 ( L_13 , 0 ) ;
if ( ! V_58 ) {
F_36 ( L_14 ) ;
V_17 = - V_158 ;
goto V_159;
}
V_17 = F_71 ( V_58 ) ;
if ( V_17 ) {
F_36 ( L_15 ) ;
V_17 = - V_157 ;
goto V_160;
}
V_17 = F_34 () ;
if ( V_17 < 0 )
goto V_161;
V_17 = F_64 () ;
if ( V_17 ) {
F_37 () ;
goto V_161;
}
return 0 ;
V_161:
F_72 ( V_58 ) ;
V_160:
F_73 ( V_58 ) ;
V_159:
F_74 ( & V_156 ) ;
return V_17 ;
}
static void T_10 F_75 ( void )
{
F_55 () ;
F_37 () ;
F_61 () ;
F_76 ( V_58 ) ;
F_74 ( & V_156 ) ;
F_51 ( L_16 ) ;
}
