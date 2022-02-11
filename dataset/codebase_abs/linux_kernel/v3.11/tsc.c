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
unsigned long long F_7 ( void )
{
return F_8 () ;
}
int F_9 ( void )
{
return V_6 ;
}
int T_2 F_10 ( char * V_7 )
{
F_11 ( L_1 ) ;
V_2 = 1 ;
return 1 ;
}
int T_2 F_10 ( char * V_7 )
{
F_12 ( V_8 ) ;
return 1 ;
}
static int T_2 F_13 ( char * V_7 )
{
if ( ! strcmp ( V_7 , L_2 ) )
V_9 = 1 ;
if ( ! strncmp ( V_7 , L_3 , 9 ) )
V_10 = 1 ;
return 1 ;
}
static T_1 F_14 ( T_1 * V_11 , int V_12 )
{
T_1 V_13 , V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_13 = F_15 () ;
if ( V_12 )
* V_11 = F_16 ( V_17 ) & 0xFFFFFFFF ;
else
* V_11 = F_17 () ;
V_14 = F_15 () ;
if ( ( V_14 - V_13 ) < V_18 )
return V_14 ;
}
return V_19 ;
}
static unsigned long F_18 ( T_1 V_20 , T_1 V_21 , T_1 V_22 )
{
T_1 V_23 ;
if ( V_22 < V_21 )
V_22 += 0x100000000ULL ;
V_22 -= V_21 ;
V_23 = ( ( T_1 ) V_22 * F_16 ( V_24 ) ) ;
F_19 ( V_23 , 1000000 ) ;
F_19 ( V_20 , V_23 ) ;
return ( unsigned long ) V_20 ;
}
static unsigned long F_20 ( T_1 V_20 , T_1 V_25 , T_1 V_26 )
{
T_1 V_23 ;
if ( ! V_25 && ! V_26 )
return V_27 ;
if ( V_26 < V_25 )
V_26 += ( T_1 ) V_28 ;
V_26 -= V_25 ;
V_23 = V_26 * 1000000000LL ;
F_19 ( V_23 , V_29 ) ;
F_19 ( V_20 , V_23 ) ;
return ( unsigned long ) V_20 ;
}
static unsigned long F_21 ( T_3 V_30 , unsigned long V_31 , int V_32 )
{
T_1 V_33 , V_13 , V_14 , V_34 ;
unsigned long V_35 , V_36 ;
int V_37 ;
F_22 ( ( F_23 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_22 ( 0xb0 , 0x43 ) ;
F_22 ( V_30 & 0xff , 0x42 ) ;
F_22 ( V_30 >> 8 , 0x42 ) ;
V_33 = V_13 = V_14 = F_15 () ;
V_37 = 0 ;
V_36 = 0 ;
V_35 = V_27 ;
while ( ( F_23 ( 0x61 ) & 0x20 ) == 0 ) {
V_14 = F_15 () ;
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
F_19 ( V_34 , V_31 ) ;
return V_34 ;
}
static inline int F_24 ( unsigned char V_38 )
{
F_23 ( 0x42 ) ;
return F_23 ( 0x42 ) == V_38 ;
}
static inline int F_25 ( unsigned char V_38 , T_1 * V_39 , unsigned long * V_40 )
{
int V_41 ;
T_1 V_33 = 0 , V_42 = 0 ;
for ( V_41 = 0 ; V_41 < 50000 ; V_41 ++ ) {
if ( ! F_24 ( V_38 ) )
break;
V_42 = V_33 ;
V_33 = F_15 () ;
}
* V_40 = F_15 () - V_42 ;
* V_39 = V_33 ;
return V_41 > 5 ;
}
static unsigned long F_26 ( void )
{
int V_15 ;
T_1 V_33 , V_34 ;
unsigned long V_43 , V_44 ;
F_22 ( ( F_23 ( 0x61 ) & ~ 0x02 ) | 0x01 , 0x61 ) ;
F_22 ( 0xb0 , 0x43 ) ;
F_22 ( 0xff , 0x42 ) ;
F_22 ( 0xff , 0x42 ) ;
F_24 ( 0 ) ;
if ( F_25 ( 0xff , & V_33 , & V_43 ) ) {
for ( V_15 = 1 ; V_15 <= V_45 ; V_15 ++ ) {
if ( ! F_25 ( 0xff - V_15 , & V_34 , & V_44 ) )
break;
V_34 -= V_33 ;
if ( V_43 + V_44 >= V_34 >> 11 )
continue;
if ( ! F_24 ( 0xfe - V_15 ) )
break;
goto V_46;
}
}
F_27 ( L_4 ) ;
return 0 ;
V_46:
V_34 *= V_47 ;
F_19 ( V_34 , V_15 * 256 * 1000 ) ;
F_28 ( L_5 ) ;
return V_34 ;
}
unsigned long F_29 ( void )
{
T_1 V_48 , V_49 , V_34 , V_50 , V_51 ;
unsigned long V_52 = V_27 , V_53 = V_27 ;
unsigned long V_54 , V_30 , V_31 , V_55 ;
int V_12 = F_30 () , V_15 , V_32 ;
F_31 ( V_54 ) ;
V_55 = F_26 () ;
F_32 ( V_54 ) ;
if ( V_55 )
return V_55 ;
V_30 = V_56 ;
V_31 = V_57 ;
V_32 = V_58 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
unsigned long V_59 ;
F_31 ( V_54 ) ;
V_48 = F_14 ( & V_50 , V_12 ) ;
V_59 = F_21 ( V_30 , V_31 , V_32 ) ;
V_49 = F_14 ( & V_51 , V_12 ) ;
F_32 ( V_54 ) ;
V_52 = F_33 ( V_52 , V_59 ) ;
if ( V_50 == V_51 )
continue;
if ( V_48 == V_19 || V_49 == V_19 )
continue;
V_49 = ( V_49 - V_48 ) * 1000000LL ;
if ( V_12 )
V_49 = F_18 ( V_49 , V_50 , V_51 ) ;
else
V_49 = F_20 ( V_49 , V_50 , V_51 ) ;
V_53 = F_33 ( V_53 , ( unsigned long ) V_49 ) ;
V_34 = ( ( T_1 ) V_52 ) * 100 ;
F_19 ( V_34 , V_53 ) ;
if ( V_34 >= 90 && V_34 <= 110 ) {
F_28 ( L_6 ,
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
F_11 ( L_9 ) ;
if ( ! V_12 && ! V_50 && ! V_51 ) {
F_34 ( L_10 ) ;
return 0 ;
}
if ( V_53 == V_27 ) {
F_11 ( L_11 ) ;
return 0 ;
}
F_28 ( L_12 ,
V_12 ? L_7 : L_8 ) ;
return V_53 ;
}
if ( ! V_12 && ! V_50 && ! V_51 ) {
F_28 ( L_13 ) ;
return V_52 ;
}
if ( V_53 == V_27 ) {
F_11 ( L_14 ) ;
return V_52 ;
}
F_11 ( L_15 ,
V_12 ? L_7 : L_8 , V_52 , V_53 ) ;
F_28 ( L_13 ) ;
return V_52 ;
}
int F_35 ( void )
{
#ifndef F_36
unsigned long V_63 = V_64 ;
if ( V_65 ) {
V_66 = V_67 . V_68 () ;
V_64 = V_66 ;
F_37 ( 0 ) . V_69 =
F_38 ( F_37 ( 0 ) . V_69 ,
V_63 , V_64 ) ;
return 0 ;
} else
return - V_70 ;
#else
return - V_70 ;
#endif
}
static void F_39 ( unsigned long V_64 , int V_71 )
{
unsigned long long V_72 , V_73 , * V_74 ;
unsigned long V_54 , * V_75 ;
F_31 ( V_54 ) ;
F_40 () ;
V_75 = & F_41 ( V_76 , V_71 ) ;
V_74 = & F_41 ( V_77 , V_71 ) ;
F_3 ( V_72 ) ;
V_73 = F_4 ( V_72 ) ;
if ( V_64 ) {
* V_75 = ( ( V_78 << V_79 ) +
V_64 / 2 ) / V_64 ;
* V_74 = V_73 - F_42 ( V_72 , * V_75 ,
( 1UL << V_79 ) ) ;
}
F_43 ( 0 ) ;
F_32 ( V_54 ) ;
}
void F_44 ( void )
{
if ( ! V_80 )
return;
V_81 = F_5 () ;
}
void F_45 ( void )
{
unsigned long long V_74 ;
unsigned long V_54 ;
int V_71 ;
if ( ! V_80 )
return;
F_31 ( V_54 ) ;
F_46 ( V_77 , 0 ) ;
V_74 = V_81 - F_5 () ;
F_47 (cpu)
F_41 ( V_77 , V_71 ) = V_74 ;
F_32 ( V_54 ) ;
}
static int F_48 ( struct V_82 * V_83 , unsigned long V_38 ,
void * V_84 )
{
struct V_85 * V_86 = V_84 ;
unsigned long * V_87 ;
if ( F_49 ( & F_37 ( V_86 -> V_71 ) , V_88 ) )
return 0 ;
V_87 = & V_89 . V_69 ;
#ifdef F_36
if ( ! ( V_86 -> V_54 & V_90 ) )
V_87 = & F_37 ( V_86 -> V_71 ) . V_69 ;
#endif
if ( ! V_91 ) {
V_91 = V_86 -> V_92 ;
V_93 = * V_87 ;
V_94 = V_66 ;
}
if ( ( V_38 == V_95 && V_86 -> V_92 < V_86 -> V_96 ) ||
( V_38 == V_97 && V_86 -> V_92 > V_86 -> V_96 ) ||
( V_38 == V_98 ) ) {
* V_87 = F_38 ( V_93 , V_91 , V_86 -> V_96 ) ;
V_66 = F_38 ( V_94 , V_91 , V_86 -> V_96 ) ;
if ( ! ( V_86 -> V_54 & V_90 ) )
F_50 ( L_16 ) ;
}
F_39 ( V_66 , V_86 -> V_71 ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
if ( ! V_65 )
return 0 ;
if ( F_52 ( V_88 ) )
return 0 ;
F_53 ( & V_99 ,
V_100 ) ;
return 0 ;
}
static T_4 F_54 ( struct V_101 * V_102 )
{
T_4 V_103 = ( T_4 ) F_15 () ;
return V_103 >= V_104 . V_105 ?
V_103 : V_104 . V_105 ;
}
static void F_55 ( struct V_101 * V_102 )
{
if ( ! F_52 ( V_106 ) )
V_104 . V_105 = 0 ;
}
void F_50 ( char * V_107 )
{
if ( ! V_6 ) {
V_6 = 1 ;
V_80 = 0 ;
F_56 () ;
F_28 ( L_17 , V_107 ) ;
if ( V_104 . V_108 )
F_57 ( & V_104 ) ;
else {
V_104 . V_54 |= V_109 ;
V_104 . V_110 = 0 ;
}
}
}
static void T_2 F_58 ( void )
{
#ifdef F_59
#define F_60 0x100
unsigned long V_111 , V_112 ;
F_61 ( V_113 , & V_111 , & V_112 ) ;
if ( V_111 & F_60 )
V_9 = 1 ;
#endif
if ( F_52 ( V_114 ) )
V_9 = 1 ;
}
int F_62 ( void )
{
if ( ! V_65 || V_6 )
return 1 ;
#ifdef F_36
if ( F_63 () )
return 1 ;
#endif
if ( F_52 ( V_88 ) )
return 0 ;
if ( V_9 )
return 0 ;
if ( V_89 . V_115 != V_116 ) {
if ( F_64 () > 1 )
return 1 ;
}
return 0 ;
}
static void F_65 ( struct V_117 * V_118 )
{
static T_1 V_119 = - 1 , V_120 ;
static int V_12 ;
T_1 V_121 , V_122 , V_34 ;
unsigned long V_86 ;
if ( F_9 () )
goto V_123;
if ( V_119 == - 1 ) {
V_12 = F_30 () ;
F_66 ( & V_124 , V_5 ) ;
V_119 = F_14 ( & V_120 , V_12 ) ;
return;
}
V_121 = F_14 ( & V_122 , V_12 ) ;
if ( V_120 == V_122 )
goto V_123;
if ( V_119 == V_19 || V_121 == V_19 )
goto V_123;
V_34 = V_121 - V_119 ;
V_34 *= 1000000LL ;
if ( V_12 )
V_86 = F_18 ( V_34 , V_120 , V_122 ) ;
else
V_86 = F_20 ( V_34 , V_120 , V_122 ) ;
if ( abs ( V_66 - V_86 ) > V_66 / 100 )
goto V_123;
V_66 = V_86 ;
F_28 ( L_18 ,
( unsigned long ) V_66 / 1000 ,
( unsigned long ) V_66 % 1000 ) ;
V_123:
F_67 ( & V_104 , V_66 ) ;
}
static int T_2 F_68 ( void )
{
if ( ! V_65 || V_2 > 0 || ! V_66 )
return 0 ;
if ( V_9 )
V_104 . V_54 &= ~ V_125 ;
if ( F_9 () ) {
V_104 . V_110 = 0 ;
V_104 . V_54 &= ~ V_126 ;
}
if ( F_52 ( V_106 ) )
V_104 . V_54 |= V_127 ;
if ( F_52 ( V_114 ) ) {
F_67 ( & V_104 , V_66 ) ;
return 0 ;
}
F_66 ( & V_124 , 0 ) ;
return 0 ;
}
void T_2 F_69 ( void )
{
T_1 V_87 ;
int V_71 ;
V_128 . V_129 . V_130 () ;
if ( ! V_65 )
return;
V_66 = V_67 . V_68 () ;
V_64 = V_66 ;
if ( ! V_66 ) {
F_50 ( L_19 ) ;
return;
}
F_28 ( L_20 ,
( unsigned long ) V_64 / 1000 ,
( unsigned long ) V_64 % 1000 ) ;
F_47 (cpu)
F_39 ( V_64 , V_71 ) ;
if ( V_2 > 0 )
return;
V_2 = 0 ;
if ( ! V_10 )
F_70 () ;
V_87 = ( ( T_1 ) V_66 * 1000 ) ;
F_19 ( V_87 , V_5 ) ;
V_131 = V_87 ;
F_71 () ;
if ( F_62 () )
F_50 ( L_21 ) ;
F_58 () ;
}
unsigned long F_72 ( void )
{
int V_15 , V_71 = F_73 () ;
if ( ! V_2 && ! F_49 ( & F_37 ( V_71 ) , V_88 ) )
return 0 ;
F_74 (i)
if ( F_37 ( V_15 ) . V_132 == F_37 ( V_71 ) . V_132 )
return F_37 ( V_15 ) . V_69 ;
return 0 ;
}
