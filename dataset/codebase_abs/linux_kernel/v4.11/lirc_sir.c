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
static int F_7 ( struct V_6 * V_7 , unsigned int * V_8 ,
unsigned int V_9 )
{
unsigned long V_10 ;
int V_11 ;
F_8 ( V_10 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; ) {
if ( V_8 [ V_11 ] )
F_9 ( V_8 [ V_11 ] ) ;
V_11 ++ ;
if ( V_11 >= V_9 )
break;
if ( V_8 [ V_11 ] )
F_10 ( V_8 [ V_11 ] ) ;
V_11 ++ ;
}
F_11 ( V_10 ) ;
return V_9 ;
}
static void F_12 ( int V_12 , unsigned long V_13 )
{
F_13 ( V_14 ) ;
F_14 ( L_1 , V_12 , V_13 ) ;
if ( V_12 ) {
if ( V_13 > V_15 / 2 )
V_13 -= V_15 / 2 ;
else
V_13 = 1 ;
V_14 . V_16 = true ;
} else {
V_13 += V_15 / 2 ;
}
V_14 . V_17 = F_15 ( V_13 ) ;
F_16 ( V_18 , & V_14 ) ;
}
static int F_17 ( void )
{
V_18 = F_18 ( & V_19 -> V_7 , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_18 -> V_22 = V_23 L_2 ;
V_18 -> V_24 . V_25 = V_26 ;
V_18 -> V_24 . V_27 = 0x0001 ;
V_18 -> V_24 . V_28 = 0x0001 ;
V_18 -> V_24 . V_29 = 0x0100 ;
V_18 -> V_30 = F_7 ;
V_18 -> V_31 = V_32 ;
V_18 -> V_33 = V_34 ;
V_18 -> V_35 = V_36 ;
V_18 -> V_7 . V_37 = & V_19 -> V_7 ;
return F_19 ( & V_19 -> V_7 , V_18 ) ;
}
static void F_20 ( unsigned long V_38 )
{
unsigned long V_10 ;
unsigned long V_39 ;
F_21 ( & V_40 , V_10 ) ;
if ( V_41 ) {
F_4 ( V_42 , V_2 + V_43 ) ;
V_39 = F_22 (unsigned long,
ktime_us_delta(last, last_intr_time),
IR_MAX_DURATION) ;
F_23 ( & V_19 -> V_7 , L_3 ,
V_41 , V_39 ) ;
F_12 ( V_41 , V_39 ) ;
V_41 = 0 ;
V_44 = V_45 ;
}
F_24 ( & V_40 , V_10 ) ;
F_25 ( V_18 ) ;
}
static T_1 F_26 ( int V_46 , void * V_47 )
{
unsigned char V_38 ;
T_2 V_48 ;
static unsigned long V_49 ;
unsigned long V_50 ;
unsigned long V_10 ;
int V_51 , V_52 ;
while ( ( V_51 = F_2 ( V_2 + V_53 ) & V_54 ) ) {
switch ( V_51 & V_54 ) {
case V_55 :
( void ) F_2 ( V_2 + V_56 ) ;
break;
case V_57 :
( void ) F_2 ( V_2 + V_58 ) ;
break;
case V_59 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_60 :
F_21 ( & V_40 , V_10 ) ;
do {
F_27 ( & V_61 ) ;
V_38 = F_2 ( V_2 + V_62 ) ;
V_48 = F_28 () ;
V_49 = F_22 (unsigned long,
ktime_us_delta(last, curr_time),
IR_MAX_DURATION) ;
V_50 = F_22 (unsigned long,
ktime_us_delta(last_intr_time,
curr_time),
IR_MAX_DURATION) ;
F_23 ( & V_19 -> V_7 , L_4 ,
V_50 , ( int ) V_38 ) ;
if ( V_50 > V_15 * V_63 ) {
if ( V_41 ) {
F_23 ( & V_19 -> V_7 , L_5 ) ;
F_12 ( V_41 ,
V_49 -
V_50 ) ;
V_41 = 0 ;
V_44 = V_45 ;
V_49 = V_50 ;
}
}
V_38 = 1 ;
if ( V_38 ^ V_41 ) {
F_12 ( V_41 ,
V_49 - V_15 ) ;
V_41 = V_38 ;
V_44 = V_48 ;
V_44 = F_29 ( V_44 ,
V_15 ) ;
}
V_45 = V_48 ;
if ( V_38 ) {
V_61 . V_64 = V_65 +
V_66 ;
F_30 ( & V_61 ) ;
}
V_52 = F_2 ( V_2 + V_58 ) ;
} while ( V_52 & V_67 );
F_24 ( & V_40 , V_10 ) ;
break;
default:
break;
}
}
F_25 ( V_18 ) ;
return F_31 ( V_68 ) ;
}
static void F_10 ( unsigned long V_69 )
{
F_5 ( V_69 ) ;
}
static void F_9 ( unsigned long V_69 )
{
long V_70 = V_69 / V_15 ;
if ( V_70 == 0 )
V_70 ++ ;
while ( V_70 -- ) {
F_4 ( V_71 , V_2 + V_72 ) ;
while ( ! ( F_2 ( V_2 + V_58 ) & V_73 ) )
;
}
}
static int F_32 ( void )
{
unsigned long V_10 ;
F_21 ( & V_74 , V_10 ) ;
#if F_33 ( V_75 )
F_3 ( V_43 ,
V_42 |
V_76 |
V_77 ) ;
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_80 , F_1 ( V_80 ) &
( ~ ( V_81 | V_82 | V_83 | V_84 ) ) ) ;
F_3 ( V_78 , F_1 ( V_78 ) | V_79 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 12 ) ;
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
F_5 ( 50 * 1000 ) ;
F_3 ( V_87 , V_88 | V_90 ) ;
F_6 ( 1 * 1000 ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
F_6 ( 100 ) ;
F_3 ( V_87 , V_89 | V_90 ) ;
F_6 ( 7 ) ;
F_3 ( V_72 , V_91 | V_92 ) ;
F_6 ( 1500 ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_34 ( L_6 , F_1 ( V_62 ) ) ;
F_3 ( V_78 , F_1 ( V_78 ) | V_79 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 1 ) ;
F_3 ( V_78 , V_93 ) ;
F_3 ( V_80 , F_1 ( V_80 ) | V_84 ) ;
#else
F_4 ( 0 , V_2 + V_87 ) ;
F_4 ( 0 , V_2 + V_80 ) ;
F_4 ( V_79 | V_94 , V_2 + V_78 ) ;
F_4 ( 1 , V_2 + V_86 ) ; F_4 ( 0 , V_2 + V_85 ) ;
F_4 ( V_94 , V_2 + V_78 ) ;
F_4 ( V_95 , V_2 + V_43 ) ;
F_4 ( V_84 , V_2 + V_80 ) ;
F_4 ( V_89 | V_88 | V_90 , V_2 + V_87 ) ;
#ifdef F_35
F_36 () ;
#elif F_33 ( V_96 )
F_37 () ;
#endif
#endif
F_24 ( & V_74 , V_10 ) ;
return 0 ;
}
static void F_38 ( void )
{
unsigned long V_10 ;
F_21 ( & V_74 , V_10 ) ;
F_4 ( 0 , V_2 + V_80 ) ;
F_24 ( & V_74 , V_10 ) ;
}
static int F_39 ( void )
{
int V_97 ;
if ( ! F_40 ( V_2 , 8 , V_23 ) ) {
F_41 ( L_7 , V_2 ) ;
return - V_98 ;
}
V_97 = F_42 ( V_46 , F_26 , 0 ,
V_23 , NULL ) ;
if ( V_97 < 0 ) {
F_43 ( V_2 , 8 ) ;
F_41 ( L_8 , V_46 ) ;
return V_97 ;
}
F_34 ( L_9 , V_2 , V_46 ) ;
F_44 ( & V_61 , F_20 , 0 ) ;
return 0 ;
}
static void F_45 ( void )
{
F_46 ( V_46 , NULL ) ;
F_47 ( & V_61 ) ;
F_43 ( V_2 , 8 ) ;
}
static void F_36 ( void )
{
int V_11 ;
T_3 V_99 [] = {
V_100 ,
V_101 | V_102 ,
V_103 | V_104 | V_105 ,
V_101 ,
V_106 | V_107 ,
V_108 | V_109 | V_110 ,
V_111 | V_112 ,
V_113 | V_114 | V_115 | V_116 ,
V_117 | V_118 ,
V_119 | V_120 | V_121 ,
V_122 | ( V_123 & 0x0f ) ,
V_124 | ( ( V_123 >> 4 ) & 0x0f ) ,
V_125 | V_126 | V_127
} ;
F_3 ( V_78 , V_79 | V_93 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 12 ) ;
F_3 ( V_78 , V_93 ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
for ( V_11 = 0 ; V_11 < 50 ; V_11 ++ )
F_5 ( 1000 ) ;
F_3 ( V_87 , V_89 | V_90 ) ;
for ( V_11 = 0 ; V_11 < 25 ; V_11 ++ )
F_6 ( 1000 ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
F_6 ( 100 ) ;
F_3 ( V_87 , V_88 | V_90 ) ;
F_6 ( 7 ) ;
for ( V_11 = 0 ; V_11 < sizeof( V_99 ) ; V_11 ++ ) {
F_3 ( V_72 , V_99 [ V_11 ] ) ;
F_6 ( 1500 ) ;
}
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
F_6 ( 50 ) ;
F_6 ( 1500 ) ;
F_3 ( V_78 , F_1 ( V_78 ) | V_79 ) ;
F_3 ( V_78 , V_79 | V_94 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 1 ) ;
F_3 ( V_78 , F_1 ( V_78 ) & ( ~ V_79 ) ) ;
F_3 ( V_78 , V_94 ) ;
F_3 ( V_80 , F_1 ( V_80 ) | V_84 ) ;
}
void F_37 ( void )
{
int V_11 ;
F_3 ( V_78 , V_79 | V_94 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 12 ) ;
F_3 ( V_78 , V_94 ) ;
F_3 ( V_87 , V_88 | V_90 ) ;
F_6 ( 10 ) ;
F_3 ( V_87 , V_89 | V_88 | V_90 ) ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_6 ( 10 ) ;
F_3 ( V_87 , V_89 | V_90 ) ;
F_6 ( 10 ) ;
F_3 ( V_87 , V_88 | V_89 | V_90 ) ;
}
F_6 ( 1500 ) ;
F_3 ( V_78 , V_79 | V_94 ) ;
F_3 ( V_85 , 0 ) ;
F_3 ( V_86 , 1 ) ;
F_3 ( V_78 , V_94 ) ;
F_3 ( V_80 , V_84 ) ;
}
static int F_48 ( void )
{
int V_97 ;
V_97 = F_39 () ;
if ( V_97 < 0 )
return V_97 ;
F_32 () ;
F_34 ( L_10 ) ;
return 0 ;
}
static int F_49 ( struct V_128 * V_7 )
{
return 0 ;
}
static int F_50 ( struct V_128 * V_7 )
{
return 0 ;
}
static int T_4 F_51 ( void )
{
int V_97 ;
V_97 = F_52 ( & V_129 ) ;
if ( V_97 ) {
F_41 ( L_11 ) ;
return - V_130 ;
}
V_19 = F_53 ( L_12 , 0 ) ;
if ( ! V_19 ) {
F_41 ( L_13 ) ;
V_97 = - V_21 ;
goto V_131;
}
V_97 = F_54 ( V_19 ) ;
if ( V_97 ) {
F_41 ( L_14 ) ;
V_97 = - V_130 ;
goto V_132;
}
V_97 = F_17 () ;
if ( V_97 < 0 )
goto V_133;
V_97 = F_48 () ;
if ( V_97 )
goto V_133;
return 0 ;
V_133:
F_55 ( V_19 ) ;
V_132:
F_56 ( V_19 ) ;
V_131:
F_57 ( & V_129 ) ;
return V_97 ;
}
static void T_5 F_58 ( void )
{
F_38 () ;
F_45 () ;
F_59 ( V_19 ) ;
F_57 ( & V_129 ) ;
F_34 ( L_15 ) ;
}
