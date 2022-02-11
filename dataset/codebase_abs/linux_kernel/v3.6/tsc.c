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
F_9 ( L_1 ) ;
V_2 = 1 ;
return 1 ;
}
int T_2 F_8 ( char * V_7 )
{
F_10 ( V_8 ) ;
return 1 ;
}
static int T_2 F_11 ( char * V_7 )
{
if ( ! strcmp ( V_7 , L_2 ) )
V_9 = 1 ;
if ( ! strncmp ( V_7 , L_3 , 9 ) )
V_10 = 1 ;
return 1 ;
}
static T_1 F_12 ( T_1 * V_11 , int V_12 )
{
T_1 V_13 , V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_13 = F_13 () ;
if ( V_12 )
* V_11 = F_14 ( V_17 ) & 0xFFFFFFFF ;
else
* V_11 = F_15 () ;
V_14 = F_13 () ;
if ( ( V_14 - V_13 ) < V_18 )
return V_14 ;
}
return V_19 ;
}
static unsigned long F_16 ( T_1 V_20 , T_1 V_21 , T_1 V_22 )
{
T_1 V_23 ;
if ( V_22 < V_21 )
V_22 += 0x100000000ULL ;
V_22 -= V_21 ;
V_23 = ( ( T_1 ) V_22 * F_14 ( V_24 ) ) ;
F_17 ( V_23 , 1000000 ) ;
F_17 ( V_20 , V_23 ) ;
return ( unsigned long ) V_20 ;
}
static unsigned long F_18 ( T_1 V_20 , T_1 V_25 , T_1 V_26 )
{
T_1 V_23 ;
if ( ! V_25 && ! V_26 )
return V_27 ;
if ( V_26 < V_25 )
V_26 += ( T_1 ) V_28 ;
V_26 -= V_25 ;
V_23 = V_26 * 1000000000LL ;
F_17 ( V_23 , V_29 ) ;
F_17 ( V_20 , V_23 ) ;
return ( unsigned long ) V_20 ;
}
static unsigned long F_19 ( T_3 V_30 , unsigned long V_31 , int V_32 )
{
T_1 V_33 , V_13 , V_14 , V_34 ;
unsigned long V_35 , V_36 ;
int V_37 ;
F_20 ( ( F_21 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_20 ( 0xb0 , 0x43 ) ;
F_20 ( V_30 & 0xff , 0x42 ) ;
F_20 ( V_30 >> 8 , 0x42 ) ;
V_33 = V_13 = V_14 = F_13 () ;
V_37 = 0 ;
V_36 = 0 ;
V_35 = V_27 ;
while ( ( F_21 ( 0x61 ) & 0x20 ) == 0 ) {
V_14 = F_13 () ;
V_34 = V_14 - V_33 ;
V_33 = V_14 ;
if ( ( unsigned long ) V_34 < V_35 )
V_35 = ( unsigned int ) V_34 ;
if ( ( unsigned long ) V_34 > V_36 )
V_36 = ( unsigned int ) V_34 ;
V_37 ++ ;
}
if ( V_37 < V_32 || V_36 > 10 * V_35 )
return V_27 ;
V_34 = V_14 - V_13 ;
F_17 ( V_34 , V_31 ) ;
return V_34 ;
}
static inline int F_22 ( unsigned char V_38 )
{
F_21 ( 0x42 ) ;
return F_21 ( 0x42 ) == V_38 ;
}
static inline int F_23 ( unsigned char V_38 , T_1 * V_39 , unsigned long * V_40 )
{
int V_41 ;
T_1 V_33 = 0 , V_42 = 0 ;
for ( V_41 = 0 ; V_41 < 50000 ; V_41 ++ ) {
if ( ! F_22 ( V_38 ) )
break;
V_42 = V_33 ;
V_33 = F_13 () ;
}
* V_40 = F_13 () - V_42 ;
* V_39 = V_33 ;
return V_41 > 5 ;
}
static unsigned long F_24 ( void )
{
int V_15 ;
T_1 V_33 , V_34 ;
unsigned long V_43 , V_44 ;
F_20 ( ( F_21 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_20 ( 0xb0 , 0x43 ) ;
F_20 ( 0xff , 0x42 ) ;
F_20 ( 0xff , 0x42 ) ;
F_22 ( 0 ) ;
if ( F_23 ( 0xff , & V_33 , & V_43 ) ) {
for ( V_15 = 1 ; V_15 <= V_45 ; V_15 ++ ) {
if ( ! F_23 ( 0xff - V_15 , & V_34 , & V_44 ) )
break;
V_34 -= V_33 ;
if ( V_43 + V_44 >= V_34 >> 11 )
continue;
if ( ! F_22 ( 0xfe - V_15 ) )
break;
goto V_46;
}
}
F_25 ( L_4 ) ;
return 0 ;
V_46:
V_34 *= V_47 ;
F_17 ( V_34 , V_15 * 256 * 1000 ) ;
F_26 ( L_5 ) ;
return V_34 ;
}
unsigned long F_27 ( void )
{
T_1 V_48 , V_49 , V_34 , V_50 , V_51 ;
unsigned long V_52 = V_27 , V_53 = V_27 ;
unsigned long V_54 , V_30 , V_31 , V_55 ;
int V_12 = F_28 () , V_15 , V_32 ;
F_29 ( V_54 ) ;
V_55 = F_24 () ;
F_30 ( V_54 ) ;
if ( V_55 )
return V_55 ;
V_30 = V_56 ;
V_31 = V_57 ;
V_32 = V_58 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
unsigned long V_59 ;
F_29 ( V_54 ) ;
V_48 = F_12 ( & V_50 , V_12 ) ;
V_59 = F_19 ( V_30 , V_31 , V_32 ) ;
V_49 = F_12 ( & V_51 , V_12 ) ;
F_30 ( V_54 ) ;
V_52 = F_31 ( V_52 , V_59 ) ;
if ( V_50 == V_51 )
continue;
if ( V_48 == V_19 || V_49 == V_19 )
continue;
V_49 = ( V_49 - V_48 ) * 1000000LL ;
if ( V_12 )
V_49 = F_16 ( V_49 , V_50 , V_51 ) ;
else
V_49 = F_18 ( V_49 , V_50 , V_51 ) ;
V_53 = F_31 ( V_53 , ( unsigned long ) V_49 ) ;
V_34 = ( ( T_1 ) V_52 ) * 100 ;
F_17 ( V_34 , V_53 ) ;
if ( V_34 >= 90 && V_34 <= 110 ) {
F_26 ( L_6 ,
V_12 ? L_7 : L_8 , V_15 + 1 ) ;
return V_53 ;
}
if ( V_15 == 1 && V_52 == V_27 ) {
V_30 = V_60 ;
V_31 = V_61 ;
V_32 = V_62 ;
}
}
if ( V_52 == V_27 ) {
F_9 ( L_9 ) ;
if ( ! V_12 && ! V_50 && ! V_51 ) {
F_32 ( L_10 ) ;
return 0 ;
}
if ( V_53 == V_27 ) {
F_9 ( L_11 ) ;
return 0 ;
}
F_26 ( L_12 ,
V_12 ? L_7 : L_8 ) ;
return V_53 ;
}
if ( ! V_12 && ! V_50 && ! V_51 ) {
F_26 ( L_13 ) ;
return V_52 ;
}
if ( V_53 == V_27 ) {
F_9 ( L_14 ) ;
return V_52 ;
}
F_9 ( L_15 ,
V_12 ? L_7 : L_8 , V_52 , V_53 ) ;
F_26 ( L_13 ) ;
return V_52 ;
}
int F_33 ( void )
{
#ifndef F_34
unsigned long V_63 = V_64 ;
if ( V_65 ) {
V_66 = V_67 . V_68 () ;
V_64 = V_66 ;
F_35 ( 0 ) . V_69 =
F_36 ( F_35 ( 0 ) . V_69 ,
V_63 , V_64 ) ;
return 0 ;
} else
return - V_70 ;
#else
return - V_70 ;
#endif
}
static void F_37 ( unsigned long V_64 , int V_71 )
{
unsigned long long V_72 , V_73 , * V_74 ;
unsigned long V_54 , * V_75 ;
F_29 ( V_54 ) ;
F_38 () ;
V_75 = & F_39 ( V_76 , V_71 ) ;
V_74 = & F_39 ( V_77 , V_71 ) ;
F_3 ( V_72 ) ;
V_73 = F_4 ( V_72 ) ;
if ( V_64 ) {
* V_75 = ( V_78 << V_79 ) / V_64 ;
* V_74 = V_73 - F_40 ( V_72 , * V_75 ,
( 1UL << V_79 ) ) ;
}
F_41 ( 0 ) ;
F_30 ( V_54 ) ;
}
void F_42 ( void )
{
if ( ! V_80 )
return;
V_81 = F_5 () ;
}
void F_43 ( void )
{
unsigned long long V_74 ;
unsigned long V_54 ;
int V_71 ;
if ( ! V_80 )
return;
F_29 ( V_54 ) ;
F_44 ( V_77 , 0 ) ;
V_74 = V_81 - F_5 () ;
F_45 (cpu)
F_39 ( V_77 , V_71 ) = V_74 ;
F_30 ( V_54 ) ;
}
static int F_46 ( struct V_82 * V_83 , unsigned long V_38 ,
void * V_84 )
{
struct V_85 * V_86 = V_84 ;
unsigned long * V_87 ;
if ( F_47 ( & F_35 ( V_86 -> V_71 ) , V_88 ) )
return 0 ;
V_87 = & V_89 . V_69 ;
#ifdef F_34
if ( ! ( V_86 -> V_54 & V_90 ) )
V_87 = & F_35 ( V_86 -> V_71 ) . V_69 ;
#endif
if ( ! V_91 ) {
V_91 = V_86 -> V_92 ;
V_93 = * V_87 ;
V_94 = V_66 ;
}
if ( ( V_38 == V_95 && V_86 -> V_92 < V_86 -> V_96 ) ||
( V_38 == V_97 && V_86 -> V_92 > V_86 -> V_96 ) ||
( V_38 == V_98 ) ) {
* V_87 = F_36 ( V_93 , V_91 , V_86 -> V_96 ) ;
V_66 = F_36 ( V_94 , V_91 , V_86 -> V_96 ) ;
if ( ! ( V_86 -> V_54 & V_90 ) )
F_48 ( L_16 ) ;
}
F_37 ( V_66 , V_86 -> V_71 ) ;
return 0 ;
}
static int T_2 F_49 ( void )
{
if ( ! V_65 )
return 0 ;
if ( F_50 ( V_88 ) )
return 0 ;
F_51 ( & V_99 ,
V_100 ) ;
return 0 ;
}
static T_4 F_52 ( struct V_101 * V_102 )
{
T_4 V_103 = ( T_4 ) F_13 () ;
return V_103 >= V_104 . V_105 ?
V_103 : V_104 . V_105 ;
}
static void F_53 ( struct V_101 * V_102 )
{
V_104 . V_105 = 0 ;
}
void F_48 ( char * V_106 )
{
if ( ! V_6 ) {
V_6 = 1 ;
V_80 = 0 ;
F_54 () ;
F_26 ( L_17 , V_106 ) ;
if ( V_104 . V_107 )
F_55 ( & V_104 ) ;
else {
V_104 . V_54 |= V_108 ;
V_104 . V_109 = 0 ;
}
}
}
static void T_2 F_56 ( void )
{
#ifdef F_57
#define F_58 0x100
unsigned long V_110 , V_111 ;
F_59 ( V_112 , & V_110 , & V_111 ) ;
if ( V_110 & F_58 )
V_9 = 1 ;
#endif
if ( F_50 ( V_113 ) )
V_9 = 1 ;
}
T_5 int F_60 ( void )
{
if ( ! V_65 || V_6 )
return 1 ;
#ifdef F_34
if ( F_61 () )
return 1 ;
#endif
if ( F_50 ( V_88 ) )
return 0 ;
if ( V_9 )
return 0 ;
if ( V_89 . V_114 != V_115 ) {
if ( F_62 () > 1 )
return 1 ;
}
return 0 ;
}
static void F_63 ( struct V_116 * V_117 )
{
static T_1 V_118 = - 1 , V_119 ;
static int V_12 ;
T_1 V_120 , V_121 , V_34 ;
unsigned long V_86 ;
if ( F_7 () )
goto V_122;
if ( V_118 == - 1 ) {
V_12 = F_28 () ;
F_64 ( & V_123 , V_5 ) ;
V_118 = F_12 ( & V_119 , V_12 ) ;
return;
}
V_120 = F_12 ( & V_121 , V_12 ) ;
if ( V_119 == V_121 )
goto V_122;
if ( V_118 == V_19 || V_120 == V_19 )
goto V_122;
V_34 = V_120 - V_118 ;
V_34 *= 1000000LL ;
if ( V_12 )
V_86 = F_16 ( V_34 , V_119 , V_121 ) ;
else
V_86 = F_18 ( V_34 , V_119 , V_121 ) ;
if ( abs ( V_66 - V_86 ) > V_66 / 100 )
goto V_122;
V_66 = V_86 ;
F_26 ( L_18 ,
( unsigned long ) V_66 / 1000 ,
( unsigned long ) V_66 % 1000 ) ;
V_122:
F_65 ( & V_104 , V_66 ) ;
}
static int T_2 F_66 ( void )
{
if ( ! V_65 || V_2 > 0 || ! V_66 )
return 0 ;
if ( V_9 )
V_104 . V_54 &= ~ V_124 ;
if ( F_7 () ) {
V_104 . V_109 = 0 ;
V_104 . V_54 &= ~ V_125 ;
}
if ( F_50 ( V_113 ) ) {
F_65 ( & V_104 , V_66 ) ;
return 0 ;
}
F_64 ( & V_123 , 0 ) ;
return 0 ;
}
void T_2 F_67 ( void )
{
T_1 V_87 ;
int V_71 ;
V_126 . V_127 . V_128 () ;
if ( ! V_65 )
return;
V_66 = V_67 . V_68 () ;
V_64 = V_66 ;
if ( ! V_66 ) {
F_48 ( L_19 ) ;
return;
}
F_26 ( L_20 ,
( unsigned long ) V_64 / 1000 ,
( unsigned long ) V_64 % 1000 ) ;
F_45 (cpu)
F_37 ( V_64 , V_71 ) ;
if ( V_2 > 0 )
return;
V_2 = 0 ;
if ( ! V_10 )
F_68 () ;
V_87 = ( ( T_1 ) V_66 * 1000 ) ;
F_17 ( V_87 , V_5 ) ;
V_129 = V_87 ;
F_69 () ;
if ( F_60 () )
F_48 ( L_21 ) ;
F_56 () ;
}
unsigned long T_5 F_70 ( void )
{
int V_15 , V_71 = F_71 () ;
if ( ! V_2 && ! F_47 ( & F_35 ( V_71 ) , V_88 ) )
return 0 ;
F_72 (i)
if ( F_35 ( V_15 ) . V_130 == F_35 ( V_71 ) . V_130 )
return F_35 ( V_15 ) . V_69 ;
return 0 ;
}
