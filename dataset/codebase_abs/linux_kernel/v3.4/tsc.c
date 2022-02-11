T_1 F_1 ( void )
{
T_1 V_1 ;
if ( F_2 ( V_2 ) ) {
return ( V_3 - V_4 ) * ( 1000000000 / V_5 ) ;
}
F_3 ( V_1 ) ;
return F_4 ( V_1 ) ;
}
unsigned long long F_5 ( void )
{
return F_6 () ;
}
int F_7 ( void )
{
return V_6 ;
}
int T_2 F_8 ( char * V_7 )
{
F_9 ( V_8 L_1
L_2 ) ;
V_2 = 1 ;
return 1 ;
}
int T_2 F_8 ( char * V_7 )
{
F_10 ( V_9 ) ;
return 1 ;
}
static int T_2 F_11 ( char * V_7 )
{
if ( ! strcmp ( V_7 , L_3 ) )
V_10 = 1 ;
if ( ! strncmp ( V_7 , L_4 , 9 ) )
V_11 = 1 ;
return 1 ;
}
static T_1 F_12 ( T_1 * V_12 , int V_13 )
{
T_1 V_14 , V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_14 = F_13 () ;
if ( V_13 )
* V_12 = F_14 ( V_18 ) & 0xFFFFFFFF ;
else
* V_12 = F_15 () ;
V_15 = F_13 () ;
if ( ( V_15 - V_14 ) < V_19 )
return V_15 ;
}
return V_20 ;
}
static unsigned long F_16 ( T_1 V_21 , T_1 V_22 , T_1 V_23 )
{
T_1 V_24 ;
if ( V_23 < V_22 )
V_23 += 0x100000000ULL ;
V_23 -= V_22 ;
V_24 = ( ( T_1 ) V_23 * F_14 ( V_25 ) ) ;
F_17 ( V_24 , 1000000 ) ;
F_17 ( V_21 , V_24 ) ;
return ( unsigned long ) V_21 ;
}
static unsigned long F_18 ( T_1 V_21 , T_1 V_26 , T_1 V_27 )
{
T_1 V_24 ;
if ( ! V_26 && ! V_27 )
return V_28 ;
if ( V_27 < V_26 )
V_27 += ( T_1 ) V_29 ;
V_27 -= V_26 ;
V_24 = V_27 * 1000000000LL ;
F_17 ( V_24 , V_30 ) ;
F_17 ( V_21 , V_24 ) ;
return ( unsigned long ) V_21 ;
}
static unsigned long F_19 ( T_3 V_31 , unsigned long V_32 , int V_33 )
{
T_1 V_34 , V_14 , V_15 , V_35 ;
unsigned long V_36 , V_37 ;
int V_38 ;
F_20 ( ( F_21 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_20 ( 0xb0 , 0x43 ) ;
F_20 ( V_31 & 0xff , 0x42 ) ;
F_20 ( V_31 >> 8 , 0x42 ) ;
V_34 = V_14 = V_15 = F_13 () ;
V_38 = 0 ;
V_37 = 0 ;
V_36 = V_28 ;
while ( ( F_21 ( 0x61 ) & 0x20 ) == 0 ) {
V_15 = F_13 () ;
V_35 = V_15 - V_34 ;
V_34 = V_15 ;
if ( ( unsigned long ) V_35 < V_36 )
V_36 = ( unsigned int ) V_35 ;
if ( ( unsigned long ) V_35 > V_37 )
V_37 = ( unsigned int ) V_35 ;
V_38 ++ ;
}
if ( V_38 < V_33 || V_37 > 10 * V_36 )
return V_28 ;
V_35 = V_15 - V_14 ;
F_17 ( V_35 , V_32 ) ;
return V_35 ;
}
static inline int F_22 ( unsigned char V_39 )
{
F_21 ( 0x42 ) ;
return F_21 ( 0x42 ) == V_39 ;
}
static inline int F_23 ( unsigned char V_39 , T_1 * V_40 , unsigned long * V_41 )
{
int V_42 ;
T_1 V_34 = 0 , V_43 = 0 ;
for ( V_42 = 0 ; V_42 < 50000 ; V_42 ++ ) {
if ( ! F_22 ( V_39 ) )
break;
V_43 = V_34 ;
V_34 = F_13 () ;
}
* V_41 = F_13 () - V_43 ;
* V_40 = V_34 ;
return V_42 > 5 ;
}
static unsigned long F_24 ( void )
{
int V_16 ;
T_1 V_34 , V_35 ;
unsigned long V_44 , V_45 ;
F_20 ( ( F_21 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_20 ( 0xb0 , 0x43 ) ;
F_20 ( 0xff , 0x42 ) ;
F_20 ( 0xff , 0x42 ) ;
F_22 ( 0 ) ;
if ( F_23 ( 0xff , & V_34 , & V_44 ) ) {
for ( V_16 = 1 ; V_16 <= V_46 ; V_16 ++ ) {
if ( ! F_23 ( 0xff - V_16 , & V_35 , & V_45 ) )
break;
V_35 -= V_34 ;
if ( V_44 + V_45 >= V_35 >> 11 )
continue;
if ( ! F_22 ( 0xfe - V_16 ) )
break;
goto V_47;
}
}
F_9 ( L_5 ) ;
return 0 ;
V_47:
V_35 *= V_48 ;
F_17 ( V_35 , V_16 * 256 * 1000 ) ;
F_9 ( L_6 ) ;
return V_35 ;
}
unsigned long F_25 ( void )
{
T_1 V_49 , V_50 , V_35 , V_51 , V_52 ;
unsigned long V_53 = V_28 , V_54 = V_28 ;
unsigned long V_55 , V_31 , V_32 , V_56 ;
int V_13 = F_26 () , V_16 , V_33 ;
F_27 ( V_55 ) ;
V_56 = F_24 () ;
F_28 ( V_55 ) ;
if ( V_56 )
return V_56 ;
V_31 = V_57 ;
V_32 = V_58 ;
V_33 = V_59 ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
unsigned long V_60 ;
F_27 ( V_55 ) ;
V_49 = F_12 ( & V_51 , V_13 ) ;
V_60 = F_19 ( V_31 , V_32 , V_33 ) ;
V_50 = F_12 ( & V_52 , V_13 ) ;
F_28 ( V_55 ) ;
V_53 = F_29 ( V_53 , V_60 ) ;
if ( V_51 == V_52 )
continue;
if ( V_49 == V_20 || V_50 == V_20 )
continue;
V_50 = ( V_50 - V_49 ) * 1000000LL ;
if ( V_13 )
V_50 = F_16 ( V_50 , V_51 , V_52 ) ;
else
V_50 = F_18 ( V_50 , V_51 , V_52 ) ;
V_54 = F_29 ( V_54 , ( unsigned long ) V_50 ) ;
V_35 = ( ( T_1 ) V_53 ) * 100 ;
F_17 ( V_35 , V_54 ) ;
if ( V_35 >= 90 && V_35 <= 110 ) {
F_9 ( V_61
L_7 ,
V_13 ? L_8 : L_9 , V_16 + 1 ) ;
return V_54 ;
}
if ( V_16 == 1 && V_53 == V_28 ) {
V_31 = V_62 ;
V_32 = V_63 ;
V_33 = V_64 ;
}
}
if ( V_53 == V_28 ) {
F_9 ( V_8 L_10 ) ;
if ( ! V_13 && ! V_51 && ! V_52 ) {
F_9 ( L_11 ) ;
return 0 ;
}
if ( V_54 == V_28 ) {
F_9 ( V_8 L_12
L_13 ) ;
return 0 ;
}
F_9 ( V_61 L_14 ,
V_13 ? L_8 : L_9 ) ;
return V_54 ;
}
if ( ! V_13 && ! V_51 && ! V_52 ) {
F_9 ( V_61 L_15 ) ;
return V_53 ;
}
if ( V_54 == V_28 ) {
F_9 ( V_8 L_16
L_17 ) ;
return V_53 ;
}
F_9 ( V_8 L_18 ,
V_13 ? L_8 : L_9 , V_53 , V_54 ) ;
F_9 ( V_61 L_15 ) ;
return V_53 ;
}
int F_30 ( void )
{
#ifndef F_31
unsigned long V_65 = V_66 ;
if ( V_67 ) {
V_68 = V_69 . V_70 () ;
V_66 = V_68 ;
F_32 ( 0 ) . V_71 =
F_33 ( F_32 ( 0 ) . V_71 ,
V_65 , V_66 ) ;
return 0 ;
} else
return - V_72 ;
#else
return - V_72 ;
#endif
}
static void F_34 ( unsigned long V_66 , int V_73 )
{
unsigned long long V_74 , V_75 , * V_76 ;
unsigned long V_55 , * V_77 ;
F_27 ( V_55 ) ;
F_35 () ;
V_77 = & F_36 ( V_78 , V_73 ) ;
V_76 = & F_36 ( V_79 , V_73 ) ;
F_3 ( V_74 ) ;
V_75 = F_4 ( V_74 ) ;
if ( V_66 ) {
* V_77 = ( V_80 << V_81 ) / V_66 ;
* V_76 = V_75 - F_37 ( V_74 , * V_77 ,
( 1UL << V_81 ) ) ;
}
F_38 ( 0 ) ;
F_28 ( V_55 ) ;
}
void F_39 ( void )
{
if ( ! V_82 )
return;
V_83 = F_5 () ;
}
void F_40 ( void )
{
unsigned long long V_76 ;
unsigned long V_55 ;
int V_73 ;
if ( ! V_82 )
return;
F_27 ( V_55 ) ;
F_41 ( V_79 , 0 ) ;
V_76 = V_83 - F_5 () ;
F_42 (cpu)
F_36 ( V_79 , V_73 ) = V_76 ;
F_28 ( V_55 ) ;
}
static int F_43 ( struct V_84 * V_85 , unsigned long V_39 ,
void * V_86 )
{
struct V_87 * V_88 = V_86 ;
unsigned long * V_89 ;
if ( F_44 ( & F_32 ( V_88 -> V_73 ) , V_90 ) )
return 0 ;
V_89 = & V_91 . V_71 ;
#ifdef F_31
if ( ! ( V_88 -> V_55 & V_92 ) )
V_89 = & F_32 ( V_88 -> V_73 ) . V_71 ;
#endif
if ( ! V_93 ) {
V_93 = V_88 -> V_94 ;
V_95 = * V_89 ;
V_96 = V_68 ;
}
if ( ( V_39 == V_97 && V_88 -> V_94 < V_88 -> V_98 ) ||
( V_39 == V_99 && V_88 -> V_94 > V_88 -> V_98 ) ||
( V_39 == V_100 ) ) {
* V_89 = F_33 ( V_95 , V_93 , V_88 -> V_98 ) ;
V_68 = F_33 ( V_96 , V_93 , V_88 -> V_98 ) ;
if ( ! ( V_88 -> V_55 & V_92 ) )
F_45 ( L_19 ) ;
}
F_34 ( V_68 , V_88 -> V_73 ) ;
return 0 ;
}
static int T_2 F_46 ( void )
{
if ( ! V_67 )
return 0 ;
if ( F_47 ( V_90 ) )
return 0 ;
F_48 ( & V_101 ,
V_102 ) ;
return 0 ;
}
static T_4 F_49 ( struct V_103 * V_104 )
{
T_4 V_105 = ( T_4 ) F_13 () ;
return V_105 >= V_106 . V_107 ?
V_105 : V_106 . V_107 ;
}
static void F_50 ( struct V_103 * V_104 )
{
V_106 . V_107 = 0 ;
}
void F_45 ( char * V_108 )
{
if ( ! V_6 ) {
V_6 = 1 ;
V_82 = 0 ;
F_51 () ;
F_9 ( V_61 L_20 , V_108 ) ;
if ( V_106 . V_109 )
F_52 ( & V_106 ) ;
else {
V_106 . V_55 |= V_110 ;
V_106 . V_111 = 0 ;
}
}
}
static void T_2 F_53 ( void )
{
#ifdef F_54
#define F_55 0x100
unsigned long V_112 , V_113 ;
F_56 ( V_114 , & V_112 , & V_113 ) ;
if ( V_112 & F_55 )
V_10 = 1 ;
#endif
if ( F_47 ( V_115 ) )
V_10 = 1 ;
}
T_5 int F_57 ( void )
{
if ( ! V_67 || V_6 )
return 1 ;
#ifdef F_31
if ( F_58 () )
return 1 ;
#endif
if ( F_47 ( V_90 ) )
return 0 ;
if ( V_10 )
return 0 ;
if ( V_91 . V_116 != V_117 ) {
if ( F_59 () > 1 )
return 1 ;
}
return 0 ;
}
static void F_60 ( struct V_118 * V_119 )
{
static T_1 V_120 = - 1 , V_121 ;
static int V_13 ;
T_1 V_122 , V_123 , V_35 ;
unsigned long V_88 ;
if ( F_7 () )
goto V_124;
if ( V_120 == - 1 ) {
V_13 = F_26 () ;
F_61 ( & V_125 , V_5 ) ;
V_120 = F_12 ( & V_121 , V_13 ) ;
return;
}
V_122 = F_12 ( & V_123 , V_13 ) ;
if ( V_121 == V_123 )
goto V_124;
if ( V_120 == V_20 || V_122 == V_20 )
goto V_124;
V_35 = V_122 - V_120 ;
V_35 *= 1000000LL ;
if ( V_13 )
V_88 = F_16 ( V_35 , V_121 , V_123 ) ;
else
V_88 = F_18 ( V_35 , V_121 , V_123 ) ;
if ( abs ( V_68 - V_88 ) > V_68 / 100 )
goto V_124;
V_68 = V_88 ;
F_9 ( V_61 L_21
L_22 , ( unsigned long ) V_68 / 1000 ,
( unsigned long ) V_68 % 1000 ) ;
V_124:
F_62 ( & V_106 , V_68 ) ;
}
static int T_2 F_63 ( void )
{
if ( ! V_67 || V_2 > 0 || ! V_68 )
return 0 ;
if ( V_10 )
V_106 . V_55 &= ~ V_126 ;
if ( F_7 () ) {
V_106 . V_111 = 0 ;
V_106 . V_55 &= ~ V_127 ;
}
if ( F_47 ( V_115 ) ) {
F_62 ( & V_106 , V_68 ) ;
return 0 ;
}
F_61 ( & V_125 , 0 ) ;
return 0 ;
}
void T_2 F_64 ( void )
{
T_1 V_89 ;
int V_73 ;
V_128 . V_129 . V_130 () ;
if ( ! V_67 )
return;
V_68 = V_69 . V_70 () ;
V_66 = V_68 ;
if ( ! V_68 ) {
F_45 ( L_23 ) ;
return;
}
F_9 ( L_24 ,
( unsigned long ) V_66 / 1000 ,
( unsigned long ) V_66 % 1000 ) ;
F_42 (cpu)
F_34 ( V_66 , V_73 ) ;
if ( V_2 > 0 )
return;
V_2 = 0 ;
if ( ! V_11 )
F_65 () ;
V_89 = ( ( T_1 ) V_68 * 1000 ) ;
F_17 ( V_89 , V_5 ) ;
V_131 = V_89 ;
F_66 () ;
if ( F_57 () )
F_45 ( L_25 ) ;
F_53 () ;
}
unsigned long T_5 F_67 ( void )
{
int V_16 , V_73 = F_68 () ;
if ( ! V_2 && ! F_44 ( & F_32 ( V_73 ) , V_90 ) )
return 0 ;
F_69 (i)
if ( F_32 ( V_16 ) . V_132 == F_32 ( V_73 ) . V_132 )
return F_32 ( V_16 ) . V_71 ;
return 0 ;
}
