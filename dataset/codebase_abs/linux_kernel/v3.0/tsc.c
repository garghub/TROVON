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
T_1 V_34 = 0 ;
for ( V_42 = 0 ; V_42 < 50000 ; V_42 ++ ) {
if ( ! F_22 ( V_39 ) )
break;
V_34 = F_13 () ;
}
* V_41 = F_13 () - V_34 ;
* V_40 = V_34 ;
return V_42 > 5 ;
}
static unsigned long F_24 ( void )
{
int V_16 ;
T_1 V_34 , V_35 ;
unsigned long V_43 , V_44 ;
F_20 ( ( F_21 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_20 ( 0xb0 , 0x43 ) ;
F_20 ( 0xff , 0x42 ) ;
F_20 ( 0xff , 0x42 ) ;
F_22 ( 0 ) ;
if ( F_23 ( 0xff , & V_34 , & V_43 ) ) {
for ( V_16 = 1 ; V_16 <= V_45 ; V_16 ++ ) {
if ( ! F_23 ( 0xff - V_16 , & V_35 , & V_44 ) )
break;
V_35 -= V_34 ;
if ( V_43 + V_44 >= V_35 >> 11 )
continue;
if ( ! F_22 ( 0xfe - V_16 ) )
break;
goto V_46;
}
}
F_9 ( L_5 ) ;
return 0 ;
V_46:
V_35 += ( long ) ( V_44 - V_43 ) / 2 ;
V_35 *= V_47 ;
F_17 ( V_35 , V_16 * 256 * 1000 ) ;
F_9 ( L_6 ) ;
return V_35 ;
}
unsigned long F_25 ( void )
{
T_1 V_48 , V_49 , V_35 , V_50 , V_51 ;
unsigned long V_52 = V_28 , V_53 = V_28 ;
unsigned long V_54 , V_31 , V_32 , V_55 ;
int V_13 = F_26 () , V_16 , V_33 ;
F_27 ( V_54 ) ;
V_55 = F_24 () ;
F_28 ( V_54 ) ;
if ( V_55 )
return V_55 ;
V_31 = V_56 ;
V_32 = V_57 ;
V_33 = V_58 ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
unsigned long V_59 ;
F_27 ( V_54 ) ;
V_48 = F_12 ( & V_50 , V_13 ) ;
V_59 = F_19 ( V_31 , V_32 , V_33 ) ;
V_49 = F_12 ( & V_51 , V_13 ) ;
F_28 ( V_54 ) ;
V_52 = F_29 ( V_52 , V_59 ) ;
if ( V_50 == V_51 )
continue;
if ( V_48 == V_20 || V_49 == V_20 )
continue;
V_49 = ( V_49 - V_48 ) * 1000000LL ;
if ( V_13 )
V_49 = F_16 ( V_49 , V_50 , V_51 ) ;
else
V_49 = F_18 ( V_49 , V_50 , V_51 ) ;
V_53 = F_29 ( V_53 , ( unsigned long ) V_49 ) ;
V_35 = ( ( T_1 ) V_52 ) * 100 ;
F_17 ( V_35 , V_53 ) ;
if ( V_35 >= 90 && V_35 <= 110 ) {
F_9 ( V_60
L_7 ,
V_13 ? L_8 : L_9 , V_16 + 1 ) ;
return V_53 ;
}
if ( V_16 == 1 && V_52 == V_28 ) {
V_31 = V_61 ;
V_32 = V_62 ;
V_33 = V_63 ;
}
}
if ( V_52 == V_28 ) {
F_9 ( V_8 L_10 ) ;
if ( ! V_13 && ! V_50 && ! V_51 ) {
F_9 ( L_11 ) ;
return 0 ;
}
if ( V_53 == V_28 ) {
F_9 ( V_8 L_12
L_13 ) ;
return 0 ;
}
F_9 ( V_60 L_14 ,
V_13 ? L_8 : L_9 ) ;
return V_53 ;
}
if ( ! V_13 && ! V_50 && ! V_51 ) {
F_9 ( V_60 L_15 ) ;
return V_52 ;
}
if ( V_53 == V_28 ) {
F_9 ( V_8 L_16
L_17 ) ;
return V_52 ;
}
F_9 ( V_8 L_18 ,
V_13 ? L_8 : L_9 , V_52 , V_53 ) ;
F_9 ( V_60 L_15 ) ;
return V_52 ;
}
int F_30 ( void )
{
#ifndef F_31
unsigned long V_64 = V_65 ;
if ( V_66 ) {
V_67 = V_68 . V_69 () ;
V_65 = V_67 ;
F_32 ( 0 ) . V_70 =
F_33 ( F_32 ( 0 ) . V_70 ,
V_64 , V_65 ) ;
return 0 ;
} else
return - V_71 ;
#else
return - V_71 ;
#endif
}
static void F_34 ( unsigned long V_65 , int V_72 )
{
unsigned long long V_73 , V_74 , * V_75 ;
unsigned long V_54 , * V_76 ;
F_27 ( V_54 ) ;
F_35 () ;
V_76 = & F_36 ( V_77 , V_72 ) ;
V_75 = & F_36 ( V_78 , V_72 ) ;
F_3 ( V_73 ) ;
V_74 = F_4 ( V_73 ) ;
if ( V_65 ) {
* V_76 = ( V_79 << V_80 ) / V_65 ;
* V_75 = V_74 - ( V_73 * * V_76 >> V_80 ) ;
}
F_37 ( 0 ) ;
F_28 ( V_54 ) ;
}
void F_38 ( void )
{
if ( ! V_81 )
return;
V_82 = F_5 () ;
}
void F_39 ( void )
{
unsigned long long V_75 ;
unsigned long V_54 ;
int V_72 ;
if ( ! V_81 )
return;
F_27 ( V_54 ) ;
F_40 ( V_78 , 0 ) ;
V_75 = V_82 - F_5 () ;
F_41 (cpu)
F_36 ( V_78 , V_72 ) = V_75 ;
F_28 ( V_54 ) ;
}
static int F_42 ( struct V_83 * V_84 , unsigned long V_39 ,
void * V_85 )
{
struct V_86 * V_87 = V_85 ;
unsigned long * V_88 ;
if ( F_43 ( & F_32 ( V_87 -> V_72 ) , V_89 ) )
return 0 ;
V_88 = & V_90 . V_70 ;
#ifdef F_31
if ( ! ( V_87 -> V_54 & V_91 ) )
V_88 = & F_32 ( V_87 -> V_72 ) . V_70 ;
#endif
if ( ! V_92 ) {
V_92 = V_87 -> V_93 ;
V_94 = * V_88 ;
V_95 = V_67 ;
}
if ( ( V_39 == V_96 && V_87 -> V_93 < V_87 -> V_97 ) ||
( V_39 == V_98 && V_87 -> V_93 > V_87 -> V_97 ) ||
( V_39 == V_99 ) ) {
* V_88 = F_33 ( V_94 , V_92 , V_87 -> V_97 ) ;
V_67 = F_33 ( V_95 , V_92 , V_87 -> V_97 ) ;
if ( ! ( V_87 -> V_54 & V_91 ) )
F_44 ( L_19 ) ;
}
F_34 ( V_67 , V_87 -> V_72 ) ;
return 0 ;
}
static int T_2 F_45 ( void )
{
if ( ! V_66 )
return 0 ;
if ( F_46 ( V_89 ) )
return 0 ;
F_47 ( & V_100 ,
V_101 ) ;
return 0 ;
}
static T_4 F_48 ( struct V_102 * V_103 )
{
T_4 V_104 = ( T_4 ) F_13 () ;
return V_104 >= V_105 . V_106 ?
V_104 : V_105 . V_106 ;
}
static void F_49 ( struct V_102 * V_103 )
{
V_105 . V_106 = 0 ;
}
void F_44 ( char * V_107 )
{
if ( ! V_6 ) {
V_6 = 1 ;
V_81 = 0 ;
F_50 () ;
F_9 ( V_60 L_20 , V_107 ) ;
if ( V_105 . V_108 )
F_51 ( & V_105 ) ;
else {
V_105 . V_54 |= V_109 ;
V_105 . V_110 = 0 ;
}
}
}
static int T_2 F_52 ( const struct V_111 * V_112 )
{
F_9 ( V_113 L_21 ,
V_112 -> V_114 ) ;
V_6 = 1 ;
return 0 ;
}
static void T_2 F_53 ( void )
{
#ifdef F_54
#define F_55 0x100
unsigned long V_115 , V_116 ;
F_56 ( V_117 , & V_115 , & V_116 ) ;
if ( V_115 & F_55 )
V_10 = 1 ;
#endif
if ( F_46 ( V_118 ) )
V_10 = 1 ;
}
T_5 int F_57 ( void )
{
if ( ! V_66 || V_6 )
return 1 ;
#ifdef F_31
if ( F_58 () )
return 1 ;
#endif
if ( F_46 ( V_89 ) )
return 0 ;
if ( V_10 )
return 0 ;
if ( V_90 . V_119 != V_120 ) {
if ( F_59 () > 1 )
return 1 ;
}
return 0 ;
}
static void F_60 ( struct V_121 * V_122 )
{
static T_1 V_123 = - 1 , V_124 ;
static int V_13 ;
T_1 V_125 , V_126 , V_35 ;
unsigned long V_87 ;
if ( F_7 () )
goto V_127;
if ( V_123 == - 1 ) {
V_13 = F_26 () ;
F_61 ( & V_128 , V_5 ) ;
V_123 = F_12 ( & V_124 , V_13 ) ;
return;
}
V_125 = F_12 ( & V_126 , V_13 ) ;
if ( V_124 == V_126 )
goto V_127;
if ( V_123 == V_20 || V_125 == V_20 )
goto V_127;
V_35 = V_125 - V_123 ;
V_35 *= 1000000LL ;
if ( V_13 )
V_87 = F_16 ( V_35 , V_124 , V_126 ) ;
else
V_87 = F_18 ( V_35 , V_124 , V_126 ) ;
if ( abs ( V_67 - V_87 ) > V_67 / 100 )
goto V_127;
V_67 = V_87 ;
F_9 ( V_60 L_22
L_23 , ( unsigned long ) V_67 / 1000 ,
( unsigned long ) V_67 % 1000 ) ;
V_127:
F_62 ( & V_105 , V_67 ) ;
}
static int T_2 F_63 ( void )
{
if ( ! V_66 || V_2 > 0 || ! V_67 )
return 0 ;
if ( V_10 )
V_105 . V_54 &= ~ V_129 ;
if ( F_7 () ) {
V_105 . V_110 = 0 ;
V_105 . V_54 &= ~ V_130 ;
}
F_61 ( & V_128 , 0 ) ;
return 0 ;
}
void T_2 F_64 ( void )
{
T_1 V_88 ;
int V_72 ;
V_131 . V_132 . V_133 () ;
if ( ! V_66 )
return;
V_67 = V_68 . V_69 () ;
V_65 = V_67 ;
if ( ! V_67 ) {
F_44 ( L_24 ) ;
return;
}
F_9 ( L_25 ,
( unsigned long ) V_65 / 1000 ,
( unsigned long ) V_65 % 1000 ) ;
F_41 (cpu)
F_34 ( V_65 , V_72 ) ;
if ( V_2 > 0 )
return;
V_2 = 0 ;
if ( ! V_11 )
F_65 () ;
V_88 = ( ( T_1 ) V_67 * 1000 ) ;
F_17 ( V_88 , V_5 ) ;
V_134 = V_88 ;
F_66 () ;
F_67 ( V_135 ) ;
if ( F_57 () )
F_44 ( L_26 ) ;
F_53 () ;
}
