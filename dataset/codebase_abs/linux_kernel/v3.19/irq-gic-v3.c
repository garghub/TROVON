static inline unsigned int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) < 32 ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return F_4 () ;
if ( V_2 -> V_3 <= 1023 )
return V_4 . V_5 ;
return NULL ;
}
static void F_5 ( void T_1 * V_6 )
{
T_2 V_7 = 1000000 ;
while ( F_6 ( V_6 + V_8 ) & V_9 ) {
V_7 -- ;
if ( ! V_7 ) {
F_7 ( L_1 ) ;
return;
}
F_8 () ;
F_9 ( 1 ) ;
} ;
}
static void F_10 ( void )
{
F_5 ( V_4 . V_5 ) ;
}
static void F_11 ( void )
{
F_5 ( F_12 () ) ;
}
static T_3 T_4 F_13 ( void )
{
T_3 V_10 ;
asm volatile("mrs_s %0, " __stringify(ICC_IAR1_EL1) : "=r" (irqstat));
return V_10 ;
}
static void T_4 F_14 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_PMR_EL1) ", %0" : : "r" (val));
}
static void T_4 F_15 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_CTLR_EL1) ", %0" : : "r" (val));
F_16 () ;
}
static void T_4 F_17 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_GRPEN1_EL1) ", %0" : : "r" (val));
F_16 () ;
}
static void T_4 F_18 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_SGI1R_EL1) ", %0" : : "r" (val));
}
static void F_19 ( void )
{
T_3 V_11 ;
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
V_11 |= V_12 ;
asm volatile("msr_s " __stringify(ICC_SRE_EL1) ", %0" : : "r" (val));
F_16 () ;
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
if ( ! ( V_11 & V_12 ) )
F_20 ( L_2 ) ;
}
static void F_21 ( bool V_13 )
{
void T_1 * V_14 ;
T_2 V_7 = 1000000 ;
T_2 V_11 ;
V_14 = F_12 () ;
V_11 = F_6 ( V_14 + V_15 ) ;
if ( V_13 )
V_11 &= ~ V_16 ;
else
V_11 |= V_16 ;
F_22 ( V_11 , V_14 + V_15 ) ;
if ( ! V_13 ) {
V_11 = F_6 ( V_14 + V_15 ) ;
if ( ! ( V_11 & V_16 ) )
return;
}
while ( V_7 -- ) {
V_11 = F_6 ( V_14 + V_15 ) ;
if ( V_13 ^ ( V_11 & V_17 ) )
break;
F_8 () ;
F_9 ( 1 ) ;
} ;
if ( ! V_7 )
F_7 ( L_3 ,
V_13 ? L_4 : L_5 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_24)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_24 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_24 = F_10 ;
}
F_22 ( V_19 , V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
F_24 () ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_20 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_23 ( V_2 , V_21 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( F_1 ( V_2 ) ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_22 = F_1 ( V_2 ) ;
void (* F_24)( void );
void T_1 * V_6 ;
if ( V_22 < 16 )
return - V_23 ;
if ( type != V_24 && type != V_25 )
return - V_23 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_24 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_24 = F_10 ;
}
F_30 ( V_22 , type , V_6 , F_24 ) ;
return 0 ;
}
static T_3 F_31 ( T_3 V_26 )
{
T_3 V_27 ;
V_27 = ( F_32 ( V_26 , 3 ) << 32 |
F_32 ( V_26 , 2 ) << 16 |
F_32 ( V_26 , 1 ) << 8 |
F_32 ( V_26 , 0 ) ) ;
return V_27 ;
}
static T_5 void T_6 F_33 ( struct V_28 * V_29 )
{
T_3 V_30 ;
do {
V_30 = F_13 () ;
if ( F_34 ( V_30 > 15 && V_30 < 1020 ) || V_30 >= 8192 ) {
int V_31 ;
V_31 = F_35 ( V_4 . V_32 , V_30 , V_29 ) ;
if ( V_31 ) {
F_36 ( true , L_6 ) ;
F_28 ( V_30 ) ;
}
continue;
}
if ( V_30 < 16 ) {
F_28 ( V_30 ) ;
#ifdef F_37
F_38 ( V_30 , V_29 ) ;
#else
F_36 ( true , L_7 ) ;
#endif
continue;
}
} while ( V_30 != V_33 );
}
static void T_7 F_39 ( void )
{
unsigned int V_34 ;
T_3 V_35 ;
void T_1 * V_6 = V_4 . V_5 ;
F_22 ( 0 , V_6 + V_8 ) ;
F_10 () ;
F_40 ( V_6 , V_4 . V_36 , F_10 ) ;
F_22 ( V_37 | V_38 | V_39 ,
V_6 + V_8 ) ;
V_35 = F_31 ( F_41 ( F_42 () ) ) ;
for ( V_34 = 32 ; V_34 < V_4 . V_36 ; V_34 ++ )
F_43 ( V_35 , V_6 + V_40 + V_34 * 8 ) ;
}
static int F_44 ( void )
{
T_3 V_26 = F_41 ( F_42 () ) ;
T_3 V_41 ;
T_2 V_27 ;
int V_34 ;
V_27 = ( F_32 ( V_26 , 3 ) << 24 |
F_32 ( V_26 , 2 ) << 16 |
F_32 ( V_26 , 1 ) << 8 |
F_32 ( V_26 , 0 ) ) ;
for ( V_34 = 0 ; V_34 < V_4 . V_42 ; V_34 ++ ) {
void T_1 * V_43 = V_4 . V_44 [ V_34 ] . V_45 ;
T_2 V_46 ;
V_46 = F_6 ( V_43 + V_47 ) & V_48 ;
if ( V_46 != V_49 &&
V_46 != V_50 ) {
F_45 ( L_8 , V_43 ) ;
break;
}
do {
V_41 = F_46 ( V_43 + V_51 ) ;
if ( ( V_41 >> 32 ) == V_27 ) {
T_3 V_18 = V_43 - V_4 . V_44 [ V_34 ] . V_45 ;
F_12 () = V_43 ;
F_47 () -> V_52 = V_4 . V_44 [ V_34 ] . V_52 + V_18 ;
F_48 ( L_9 ,
F_42 () ,
( unsigned long long ) V_26 ,
V_34 , & F_47 () -> V_52 ) ;
return 0 ;
}
if ( V_4 . V_53 ) {
V_43 += V_4 . V_53 ;
} else {
V_43 += V_54 * 2 ;
if ( V_41 & V_55 )
V_43 += V_54 * 2 ;
}
} while ( ! ( V_41 & V_56 ) );
}
F_49 ( true , L_10 ,
F_42 () , ( unsigned long long ) V_26 ) ;
return - V_57 ;
}
static void F_50 ( void )
{
F_19 () ;
F_14 ( V_58 ) ;
F_15 ( V_59 ) ;
F_17 ( 1 ) ;
}
static int F_51 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_60 ) & V_61 ) ;
}
static void F_52 ( void )
{
void T_1 * V_14 ;
if ( F_44 () )
return;
F_21 ( true ) ;
V_14 = F_4 () ;
F_53 ( V_14 , F_11 ) ;
if ( F_54 ( V_62 ) && F_51 () )
F_55 () ;
F_50 () ;
}
static int F_56 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_6 ( V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_19 ) ;
}
static int F_57 ( struct V_63 * V_64 ,
unsigned long V_65 , void * V_66 )
{
if ( V_65 == V_67 || V_65 == V_68 )
F_52 () ;
return V_69 ;
}
static T_8 F_58 ( int * V_70 , const struct V_71 * V_19 ,
T_3 V_72 )
{
int V_73 = * V_70 ;
T_3 V_26 = F_41 ( V_73 ) ;
T_8 V_74 = 0 ;
while ( V_73 < V_75 ) {
if ( F_59 ( ( V_26 & 0xff ) >= 16 ) )
goto V_76;
V_74 |= 1 << ( V_26 & 0xf ) ;
V_73 = F_60 ( V_73 , V_19 ) ;
if ( V_73 == V_75 )
goto V_76;
V_26 = F_41 ( V_73 ) ;
if ( V_72 != ( V_26 & ~ 0xffUL ) ) {
V_73 -- ;
goto V_76;
}
}
V_76:
* V_70 = V_73 ;
return V_74 ;
}
static void F_61 ( T_3 V_72 , T_8 V_74 , unsigned int V_22 )
{
T_3 V_11 ;
V_11 = ( F_32 ( V_72 , 3 ) << 48 |
F_32 ( V_72 , 2 ) << 32 |
V_22 << 24 |
F_32 ( V_72 , 1 ) << 16 |
V_74 ) ;
F_62 ( L_11 , F_42 () , V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_63 ( const struct V_71 * V_19 , unsigned int V_22 )
{
int V_73 ;
if ( F_59 ( V_22 >= 16 ) )
return;
F_64 () ;
F_65 (cpu, *mask) {
T_3 V_72 = F_41 ( V_73 ) & ~ 0xffUL ;
T_8 V_74 ;
V_74 = F_58 ( & V_73 , V_19 , V_72 ) ;
F_61 ( V_72 , V_74 , V_22 ) ;
}
F_16 () ;
}
static void F_66 ( void )
{
F_67 ( F_63 ) ;
F_68 ( & V_77 ) ;
}
static int F_69 ( struct V_1 * V_2 , const struct V_71 * V_78 ,
bool V_79 )
{
unsigned int V_73 = F_70 ( V_78 , V_80 ) ;
void T_1 * V_46 ;
int V_81 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_23 ;
V_81 = F_56 ( V_2 , V_21 ) ;
if ( V_81 )
F_25 ( V_2 ) ;
V_46 = F_3 ( V_2 ) + V_40 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_31 ( F_41 ( V_73 ) ) ;
F_43 ( V_11 , V_46 ) ;
if ( V_81 )
F_26 ( V_2 ) ;
else
F_10 () ;
return V_82 ;
}
static int F_71 ( struct V_63 * V_83 ,
unsigned long V_84 , void * V_85 )
{
if ( V_84 == V_86 ) {
F_21 ( true ) ;
F_50 () ;
} else if ( V_84 == V_87 ) {
F_17 ( 0 ) ;
F_21 ( false ) ;
}
return V_69 ;
}
static void F_72 ( void )
{
F_73 ( & V_88 ) ;
}
static inline void F_72 ( void ) { }
static int F_74 ( struct V_89 * V_2 , unsigned int V_22 ,
T_9 V_90 )
{
if ( V_90 < 16 )
return - V_91 ;
if ( V_90 >= V_4 . V_36 && V_90 < 8192 )
return - V_91 ;
if ( V_90 >= V_92 )
return - V_91 ;
if ( V_90 < 32 ) {
F_75 ( V_22 ) ;
F_76 ( V_2 , V_22 , V_90 , & V_93 , V_2 -> V_94 ,
V_95 , NULL , NULL ) ;
F_77 ( V_22 , V_96 | V_97 ) ;
}
if ( V_90 >= 32 && V_90 < V_4 . V_36 ) {
F_76 ( V_2 , V_22 , V_90 , & V_93 , V_2 -> V_94 ,
V_98 , NULL , NULL ) ;
F_77 ( V_22 , V_96 | V_99 ) ;
}
if ( V_90 >= 8192 && V_90 < V_92 ) {
if ( ! F_51 () )
return - V_91 ;
F_76 ( V_2 , V_22 , V_90 , & V_93 , V_2 -> V_94 ,
V_98 , NULL , NULL ) ;
F_77 ( V_22 , V_96 ) ;
}
return 0 ;
}
static int F_78 ( struct V_89 * V_2 ,
struct V_100 * V_101 ,
const T_2 * V_102 , unsigned int V_103 ,
unsigned long * V_104 , unsigned int * V_105 )
{
if ( V_2 -> V_106 != V_101 )
return - V_23 ;
if ( V_103 < 3 )
return - V_23 ;
switch( V_102 [ 0 ] ) {
case 0 :
* V_104 = V_102 [ 1 ] + 32 ;
break;
case 1 :
* V_104 = V_102 [ 1 ] + 16 ;
break;
case V_107 :
* V_104 = V_102 [ 1 ] ;
break;
default:
return - V_23 ;
}
* V_105 = V_102 [ 2 ] & V_108 ;
return 0 ;
}
static int F_79 ( struct V_89 * V_32 , unsigned int V_109 ,
unsigned int V_110 , void * V_111 )
{
int V_34 , V_112 ;
T_9 V_3 ;
unsigned int type = V_113 ;
struct V_114 * V_1 = V_111 ;
V_112 = F_78 ( V_32 , V_1 -> V_115 , V_1 -> args ,
V_1 -> V_116 , & V_3 , & type ) ;
if ( V_112 )
return V_112 ;
for ( V_34 = 0 ; V_34 < V_110 ; V_34 ++ )
F_74 ( V_32 , V_109 + V_34 , V_3 + V_34 ) ;
return 0 ;
}
static void F_80 ( struct V_89 * V_32 , unsigned int V_109 ,
unsigned int V_110 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_110 ; V_34 ++ ) {
struct V_1 * V_2 = F_81 ( V_32 , V_109 + V_34 ) ;
F_82 ( V_109 + V_34 , NULL ) ;
F_83 ( V_2 ) ;
}
}
static int T_7 F_84 ( struct V_100 * V_117 , struct V_100 * V_118 )
{
void T_1 * V_5 ;
struct V_119 * V_120 ;
T_3 V_53 ;
T_2 V_42 ;
T_2 V_41 ;
T_2 V_46 ;
int V_121 ;
int V_31 ;
int V_34 ;
V_5 = F_85 ( V_117 , 0 ) ;
if ( ! V_5 ) {
F_20 ( L_12 ,
V_117 -> V_122 ) ;
return - V_123 ;
}
V_46 = F_6 ( V_5 + V_124 ) & V_48 ;
if ( V_46 != V_49 && V_46 != V_50 ) {
F_20 ( L_13 ,
V_117 -> V_122 ) ;
V_31 = - V_57 ;
goto V_125;
}
if ( F_86 ( V_117 , L_14 , & V_42 ) )
V_42 = 1 ;
V_120 = F_87 ( sizeof( * V_120 ) * V_42 , V_126 ) ;
if ( ! V_120 ) {
V_31 = - V_127 ;
goto V_125;
}
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ ) {
struct V_128 V_129 ;
int V_112 ;
V_112 = F_88 ( V_117 , 1 + V_34 , & V_129 ) ;
V_120 [ V_34 ] . V_45 = F_85 ( V_117 , 1 + V_34 ) ;
if ( V_112 || ! V_120 [ V_34 ] . V_45 ) {
F_20 ( L_15 ,
V_117 -> V_122 , V_34 ) ;
V_31 = - V_57 ;
goto V_130;
}
V_120 [ V_34 ] . V_52 = V_129 . V_131 ;
}
if ( F_89 ( V_117 , L_16 , & V_53 ) )
V_53 = 0 ;
V_4 . V_5 = V_5 ;
V_4 . V_44 = V_120 ;
V_4 . V_42 = V_42 ;
V_4 . V_53 = V_53 ;
V_41 = F_6 ( V_4 . V_5 + V_60 ) ;
V_4 . V_132 . V_133 = F_90 ( V_41 ) ;
V_121 = F_91 ( V_41 ) ;
if ( V_121 > 1020 )
V_121 = 1020 ;
V_4 . V_36 = V_121 ;
V_4 . V_32 = F_92 ( V_117 , & V_134 ,
& V_4 ) ;
V_4 . V_132 . V_135 = F_93 ( F_94 ( * V_4 . V_132 . V_135 ) ) ;
if ( F_59 ( ! V_4 . V_32 ) || F_59 ( ! V_4 . V_132 . V_135 ) ) {
V_31 = - V_127 ;
goto V_136;
}
F_95 ( F_33 ) ;
if ( F_54 ( V_62 ) && F_51 () )
F_96 ( V_117 , & V_4 . V_132 , V_4 . V_32 ) ;
F_66 () ;
F_39 () ;
F_52 () ;
F_72 () ;
return 0 ;
V_136:
if ( V_4 . V_32 )
F_97 ( V_4 . V_32 ) ;
F_98 ( V_4 . V_132 . V_135 ) ;
V_130:
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ )
if ( V_120 [ V_34 ] . V_45 )
F_99 ( V_120 [ V_34 ] . V_45 ) ;
F_100 ( V_120 ) ;
V_125:
F_99 ( V_5 ) ;
return V_31 ;
}
