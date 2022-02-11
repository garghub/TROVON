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
if ( V_22 >= 32 && type != V_24 &&
type != V_25 )
return - V_23 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_24 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_24 = F_10 ;
}
return F_30 ( V_22 , type , V_6 , F_24 ) ;
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
if ( V_73 >= V_75 )
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
V_11 = ( F_62 ( V_72 , 3 ) |
F_62 ( V_72 , 2 ) |
V_22 << V_77 |
F_62 ( V_72 , 1 ) |
V_74 << V_78 ) ;
F_63 ( L_11 , F_42 () , V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_64 ( const struct V_71 * V_19 , unsigned int V_22 )
{
int V_73 ;
if ( F_59 ( V_22 >= 16 ) )
return;
F_65 () ;
F_66 (cpu, *mask) {
T_3 V_72 = F_41 ( V_73 ) & ~ 0xffUL ;
T_8 V_74 ;
V_74 = F_58 ( & V_73 , V_19 , V_72 ) ;
F_61 ( V_72 , V_74 , V_22 ) ;
}
F_16 () ;
}
static void F_67 ( void )
{
F_68 ( F_64 ) ;
F_69 ( & V_79 ) ;
}
static int F_70 ( struct V_1 * V_2 , const struct V_71 * V_80 ,
bool V_81 )
{
unsigned int V_73 = F_71 ( V_80 , V_82 ) ;
void T_1 * V_46 ;
int V_83 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_23 ;
V_83 = F_56 ( V_2 , V_21 ) ;
if ( V_83 )
F_25 ( V_2 ) ;
V_46 = F_3 ( V_2 ) + V_40 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_31 ( F_41 ( V_73 ) ) ;
F_43 ( V_11 , V_46 ) ;
if ( V_83 )
F_26 ( V_2 ) ;
else
F_10 () ;
return V_84 ;
}
static int F_72 ( struct V_63 * V_85 ,
unsigned long V_86 , void * V_87 )
{
if ( V_86 == V_88 ) {
F_21 ( true ) ;
F_50 () ;
} else if ( V_86 == V_89 ) {
F_17 ( 0 ) ;
F_21 ( false ) ;
}
return V_69 ;
}
static void F_73 ( void )
{
F_74 ( & V_90 ) ;
}
static inline void F_73 ( void ) { }
static int F_75 ( struct V_91 * V_2 , unsigned int V_22 ,
T_9 V_92 )
{
if ( V_92 < 16 )
return - V_93 ;
if ( V_92 >= V_4 . V_36 && V_92 < 8192 )
return - V_93 ;
if ( V_92 >= V_94 )
return - V_93 ;
if ( V_92 < 32 ) {
F_76 ( V_22 ) ;
F_77 ( V_2 , V_22 , V_92 , & V_95 , V_2 -> V_96 ,
V_97 , NULL , NULL ) ;
F_78 ( V_22 , V_98 | V_99 ) ;
}
if ( V_92 >= 32 && V_92 < V_4 . V_36 ) {
F_77 ( V_2 , V_22 , V_92 , & V_95 , V_2 -> V_96 ,
V_100 , NULL , NULL ) ;
F_78 ( V_22 , V_98 | V_101 ) ;
}
if ( V_92 >= 8192 && V_92 < V_94 ) {
if ( ! F_51 () )
return - V_93 ;
F_77 ( V_2 , V_22 , V_92 , & V_95 , V_2 -> V_96 ,
V_100 , NULL , NULL ) ;
F_78 ( V_22 , V_98 ) ;
}
return 0 ;
}
static int F_79 ( struct V_91 * V_2 ,
struct V_102 * V_103 ,
const T_2 * V_104 , unsigned int V_105 ,
unsigned long * V_106 , unsigned int * V_107 )
{
if ( V_2 -> V_108 != V_103 )
return - V_23 ;
if ( V_105 < 3 )
return - V_23 ;
switch( V_104 [ 0 ] ) {
case 0 :
* V_106 = V_104 [ 1 ] + 32 ;
break;
case 1 :
* V_106 = V_104 [ 1 ] + 16 ;
break;
case V_109 :
* V_106 = V_104 [ 1 ] ;
break;
default:
return - V_23 ;
}
* V_107 = V_104 [ 2 ] & V_110 ;
return 0 ;
}
static int F_80 ( struct V_91 * V_32 , unsigned int V_111 ,
unsigned int V_112 , void * V_113 )
{
int V_34 , V_114 ;
T_9 V_3 ;
unsigned int type = V_115 ;
struct V_116 * V_1 = V_113 ;
V_114 = F_79 ( V_32 , V_1 -> V_117 , V_1 -> args ,
V_1 -> V_118 , & V_3 , & type ) ;
if ( V_114 )
return V_114 ;
for ( V_34 = 0 ; V_34 < V_112 ; V_34 ++ )
F_75 ( V_32 , V_111 + V_34 , V_3 + V_34 ) ;
return 0 ;
}
static void F_81 ( struct V_91 * V_32 , unsigned int V_111 ,
unsigned int V_112 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_112 ; V_34 ++ ) {
struct V_1 * V_2 = F_82 ( V_32 , V_111 + V_34 ) ;
F_83 ( V_111 + V_34 , NULL ) ;
F_84 ( V_2 ) ;
}
}
static int T_7 F_85 ( struct V_102 * V_119 , struct V_102 * V_120 )
{
void T_1 * V_5 ;
struct V_121 * V_122 ;
T_3 V_53 ;
T_2 V_42 ;
T_2 V_41 ;
T_2 V_46 ;
int V_123 ;
int V_31 ;
int V_34 ;
V_5 = F_86 ( V_119 , 0 ) ;
if ( ! V_5 ) {
F_20 ( L_12 ,
V_119 -> V_124 ) ;
return - V_125 ;
}
V_46 = F_6 ( V_5 + V_126 ) & V_48 ;
if ( V_46 != V_49 && V_46 != V_50 ) {
F_20 ( L_13 ,
V_119 -> V_124 ) ;
V_31 = - V_57 ;
goto V_127;
}
if ( F_87 ( V_119 , L_14 , & V_42 ) )
V_42 = 1 ;
V_122 = F_88 ( sizeof( * V_122 ) * V_42 , V_128 ) ;
if ( ! V_122 ) {
V_31 = - V_129 ;
goto V_127;
}
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ ) {
struct V_130 V_131 ;
int V_114 ;
V_114 = F_89 ( V_119 , 1 + V_34 , & V_131 ) ;
V_122 [ V_34 ] . V_45 = F_86 ( V_119 , 1 + V_34 ) ;
if ( V_114 || ! V_122 [ V_34 ] . V_45 ) {
F_20 ( L_15 ,
V_119 -> V_124 , V_34 ) ;
V_31 = - V_57 ;
goto V_132;
}
V_122 [ V_34 ] . V_52 = V_131 . V_133 ;
}
if ( F_90 ( V_119 , L_16 , & V_53 ) )
V_53 = 0 ;
V_4 . V_5 = V_5 ;
V_4 . V_44 = V_122 ;
V_4 . V_42 = V_42 ;
V_4 . V_53 = V_53 ;
V_41 = F_6 ( V_4 . V_5 + V_60 ) ;
V_4 . V_134 . V_135 = F_91 ( V_41 ) ;
V_123 = F_92 ( V_41 ) ;
if ( V_123 > 1020 )
V_123 = 1020 ;
V_4 . V_36 = V_123 ;
V_4 . V_32 = F_93 ( V_119 , & V_136 ,
& V_4 ) ;
V_4 . V_134 . V_137 = F_94 ( F_95 ( * V_4 . V_134 . V_137 ) ) ;
if ( F_59 ( ! V_4 . V_32 ) || F_59 ( ! V_4 . V_134 . V_137 ) ) {
V_31 = - V_129 ;
goto V_138;
}
F_96 ( F_33 ) ;
if ( F_54 ( V_62 ) && F_51 () )
F_97 ( V_119 , & V_4 . V_134 , V_4 . V_32 ) ;
F_67 () ;
F_39 () ;
F_52 () ;
F_73 () ;
return 0 ;
V_138:
if ( V_4 . V_32 )
F_98 ( V_4 . V_32 ) ;
F_99 ( V_4 . V_134 . V_137 ) ;
V_132:
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ )
if ( V_122 [ V_34 ] . V_45 )
F_100 ( V_122 [ V_34 ] . V_45 ) ;
F_101 ( V_122 ) ;
V_127:
F_100 ( V_5 ) ;
return V_31 ;
}
