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
static int F_23 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_6 ( V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_19 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_10 ;
}
F_22 ( V_19 , V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
F_25 () ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_20 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
if ( F_28 ( V_2 ) )
F_24 ( V_2 , V_21 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_22 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_23 V_24 , bool V_11 )
{
T_2 V_25 ;
if ( V_2 -> V_3 >= V_4 . V_26 )
return - V_27 ;
switch ( V_24 ) {
case V_28 :
V_25 = V_11 ? V_29 : V_30 ;
break;
case V_31 :
V_25 = V_11 ? V_32 : V_21 ;
break;
case V_33 :
V_25 = V_11 ? V_20 : V_22 ;
break;
default:
return - V_27 ;
}
F_24 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_23 V_24 , bool * V_11 )
{
if ( V_2 -> V_3 >= V_4 . V_26 )
return - V_27 ;
switch ( V_24 ) {
case V_28 :
* V_11 = F_23 ( V_2 , V_29 ) ;
break;
case V_31 :
* V_11 = F_23 ( V_2 , V_32 ) ;
break;
case V_33 :
* V_11 = ! F_23 ( V_2 , V_22 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_33 ( F_1 ( V_2 ) ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) >= 8192 || F_28 ( V_2 ) )
return;
F_35 ( F_1 ( V_2 ) ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_34 = F_1 ( V_2 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( V_34 < 16 )
return - V_27 ;
if ( V_34 >= 32 && type != V_35 &&
type != V_36 )
return - V_27 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_10 ;
}
return F_37 ( V_34 , type , V_6 , F_25 ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_37 )
{
if ( V_37 )
F_39 ( V_2 ) ;
else
F_40 ( V_2 ) ;
return 0 ;
}
static T_3 F_41 ( T_3 V_38 )
{
T_3 V_39 ;
V_39 = ( F_42 ( V_38 , 3 ) << 32 |
F_42 ( V_38 , 2 ) << 16 |
F_42 ( V_38 , 1 ) << 8 |
F_42 ( V_38 , 0 ) ) ;
return V_39 ;
}
static T_5 void T_6 F_43 ( struct V_40 * V_41 )
{
T_3 V_42 ;
do {
V_42 = F_13 () ;
if ( F_44 ( V_42 > 15 && V_42 < 1020 ) || V_42 >= 8192 ) {
int V_43 ;
if ( F_45 ( & V_44 ) )
F_33 ( V_42 ) ;
V_43 = F_46 ( V_4 . V_45 , V_42 , V_41 ) ;
if ( V_43 ) {
F_47 ( true , L_6 ) ;
if ( F_45 ( & V_44 ) ) {
if ( V_42 < 8192 )
F_35 ( V_42 ) ;
} else {
F_33 ( V_42 ) ;
}
}
continue;
}
if ( V_42 < 16 ) {
F_33 ( V_42 ) ;
if ( F_45 ( & V_44 ) )
F_35 ( V_42 ) ;
#ifdef F_48
F_49 ( V_42 , V_41 ) ;
#else
F_47 ( true , L_7 ) ;
#endif
continue;
}
} while ( V_42 != V_46 );
}
static void T_7 F_50 ( void )
{
unsigned int V_47 ;
T_3 V_48 ;
void T_1 * V_6 = V_4 . V_5 ;
F_22 ( 0 , V_6 + V_8 ) ;
F_10 () ;
F_51 ( V_6 , V_4 . V_26 , F_10 ) ;
F_22 ( V_49 | V_50 | V_51 ,
V_6 + V_8 ) ;
V_48 = F_41 ( F_52 ( F_53 () ) ) ;
for ( V_47 = 32 ; V_47 < V_4 . V_26 ; V_47 ++ )
F_54 ( V_48 , V_6 + V_52 + V_47 * 8 ) ;
}
static int F_55 ( void )
{
T_3 V_38 = F_52 ( F_53 () ) ;
T_3 V_53 ;
T_2 V_39 ;
int V_47 ;
V_39 = ( F_42 ( V_38 , 3 ) << 24 |
F_42 ( V_38 , 2 ) << 16 |
F_42 ( V_38 , 1 ) << 8 |
F_42 ( V_38 , 0 ) ) ;
for ( V_47 = 0 ; V_47 < V_4 . V_54 ; V_47 ++ ) {
void T_1 * V_55 = V_4 . V_56 [ V_47 ] . V_57 ;
T_2 V_25 ;
V_25 = F_6 ( V_55 + V_58 ) & V_59 ;
if ( V_25 != V_60 &&
V_25 != V_61 ) {
F_56 ( L_8 , V_55 ) ;
break;
}
do {
V_53 = F_57 ( V_55 + V_62 ) ;
if ( ( V_53 >> 32 ) == V_39 ) {
T_3 V_18 = V_55 - V_4 . V_56 [ V_47 ] . V_57 ;
F_12 () = V_55 ;
F_58 () -> V_63 = V_4 . V_56 [ V_47 ] . V_63 + V_18 ;
F_59 ( L_9 ,
F_53 () ,
( unsigned long long ) V_38 ,
V_47 , & F_58 () -> V_63 ) ;
return 0 ;
}
if ( V_4 . V_64 ) {
V_55 += V_4 . V_64 ;
} else {
V_55 += V_65 * 2 ;
if ( V_53 & V_66 )
V_55 += V_65 * 2 ;
}
} while ( ! ( V_53 & V_67 ) );
}
F_60 ( true , L_10 ,
F_53 () , ( unsigned long long ) V_38 ) ;
return - V_68 ;
}
static void F_61 ( void )
{
F_19 () ;
F_14 ( V_69 ) ;
if ( F_45 ( & V_44 ) ) {
F_15 ( V_70 ) ;
} else {
F_15 ( V_71 ) ;
}
F_17 ( 1 ) ;
}
static int F_62 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_72 ) & V_73 ) ;
}
static void F_63 ( void )
{
void T_1 * V_14 ;
if ( F_55 () )
return;
F_21 ( true ) ;
V_14 = F_4 () ;
F_64 ( V_14 , F_11 ) ;
if ( F_65 ( V_74 ) && F_62 () )
F_66 () ;
F_61 () ;
}
static int F_67 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
if ( V_77 == V_79 || V_77 == V_80 )
F_63 () ;
return V_81 ;
}
static T_8 F_68 ( int * V_82 , const struct V_83 * V_19 ,
T_3 V_84 )
{
int V_85 = * V_82 ;
T_3 V_38 = F_52 ( V_85 ) ;
T_8 V_86 = 0 ;
while ( V_85 < V_87 ) {
if ( F_69 ( ( V_38 & 0xff ) >= 16 ) )
goto V_88;
V_86 |= 1 << ( V_38 & 0xf ) ;
V_85 = F_70 ( V_85 , V_19 ) ;
if ( V_85 >= V_87 )
goto V_88;
V_38 = F_52 ( V_85 ) ;
if ( V_84 != ( V_38 & ~ 0xffUL ) ) {
V_85 -- ;
goto V_88;
}
}
V_88:
* V_82 = V_85 ;
return V_86 ;
}
static void F_71 ( T_3 V_84 , T_8 V_86 , unsigned int V_34 )
{
T_3 V_11 ;
V_11 = ( F_72 ( V_84 , 3 ) |
F_72 ( V_84 , 2 ) |
V_34 << V_89 |
F_72 ( V_84 , 1 ) |
V_86 << V_90 ) ;
F_73 ( L_11 , F_53 () , V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_74 ( const struct V_83 * V_19 , unsigned int V_34 )
{
int V_85 ;
if ( F_69 ( V_34 >= 16 ) )
return;
F_75 () ;
F_76 (cpu, mask) {
T_3 V_84 = F_52 ( V_85 ) & ~ 0xffUL ;
T_8 V_86 ;
V_86 = F_68 ( & V_85 , V_19 , V_84 ) ;
F_71 ( V_84 , V_86 , V_34 ) ;
}
F_16 () ;
}
static void F_77 ( void )
{
F_78 ( F_74 ) ;
F_79 ( & V_91 ) ;
}
static int F_80 ( struct V_1 * V_2 , const struct V_83 * V_92 ,
bool V_93 )
{
unsigned int V_85 = F_81 ( V_92 , V_94 ) ;
void T_1 * V_25 ;
int V_95 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_27 ;
V_95 = F_23 ( V_2 , V_22 ) ;
if ( V_95 )
F_26 ( V_2 ) ;
V_25 = F_3 ( V_2 ) + V_52 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_41 ( F_52 ( V_85 ) ) ;
F_54 ( V_11 , V_25 ) ;
if ( V_95 )
F_29 ( V_2 ) ;
else
F_10 () ;
return V_96 ;
}
static int F_82 ( struct V_75 * V_97 ,
unsigned long V_98 , void * V_99 )
{
if ( V_98 == V_100 ) {
F_21 ( true ) ;
F_61 () ;
} else if ( V_98 == V_101 ) {
F_17 ( 0 ) ;
F_21 ( false ) ;
}
return V_81 ;
}
static void F_83 ( void )
{
F_84 ( & V_102 ) ;
}
static inline void F_83 ( void ) { }
static int F_85 ( struct V_103 * V_2 , unsigned int V_34 ,
T_9 V_104 )
{
struct V_105 * V_106 = & V_107 ;
if ( F_45 ( & V_44 ) )
V_106 = & V_108 ;
if ( V_104 < 16 )
return - V_109 ;
if ( V_104 >= V_4 . V_26 && V_104 < 8192 )
return - V_109 ;
if ( V_104 >= V_110 )
return - V_109 ;
if ( V_104 < 32 ) {
F_86 ( V_34 ) ;
F_87 ( V_2 , V_34 , V_104 , V_106 , V_2 -> V_111 ,
V_112 , NULL , NULL ) ;
F_88 ( V_34 , V_113 ) ;
}
if ( V_104 >= 32 && V_104 < V_4 . V_26 ) {
F_87 ( V_2 , V_34 , V_104 , V_106 , V_2 -> V_111 ,
V_114 , NULL , NULL ) ;
F_89 ( V_34 ) ;
}
if ( V_104 >= 8192 && V_104 < V_110 ) {
if ( ! F_62 () )
return - V_109 ;
F_87 ( V_2 , V_34 , V_104 , V_106 , V_2 -> V_111 ,
V_114 , NULL , NULL ) ;
}
return 0 ;
}
static int F_90 ( struct V_103 * V_2 ,
struct V_115 * V_116 ,
const T_2 * V_117 , unsigned int V_118 ,
unsigned long * V_119 , unsigned int * V_120 )
{
if ( V_2 -> V_121 != V_116 )
return - V_27 ;
if ( V_118 < 3 )
return - V_27 ;
switch( V_117 [ 0 ] ) {
case 0 :
* V_119 = V_117 [ 1 ] + 32 ;
break;
case 1 :
* V_119 = V_117 [ 1 ] + 16 ;
break;
case V_122 :
* V_119 = V_117 [ 1 ] ;
break;
default:
return - V_27 ;
}
* V_120 = V_117 [ 2 ] & V_123 ;
return 0 ;
}
static int F_91 ( struct V_103 * V_45 , unsigned int V_124 ,
unsigned int V_125 , void * V_126 )
{
int V_47 , V_127 ;
T_9 V_3 ;
unsigned int type = V_128 ;
struct V_129 * V_1 = V_126 ;
V_127 = F_90 ( V_45 , V_1 -> V_130 , V_1 -> args ,
V_1 -> V_131 , & V_3 , & type ) ;
if ( V_127 )
return V_127 ;
for ( V_47 = 0 ; V_47 < V_125 ; V_47 ++ )
F_85 ( V_45 , V_124 + V_47 , V_3 + V_47 ) ;
return 0 ;
}
static void F_92 ( struct V_103 * V_45 , unsigned int V_124 ,
unsigned int V_125 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_125 ; V_47 ++ ) {
struct V_1 * V_2 = F_93 ( V_45 , V_124 + V_47 ) ;
F_94 ( V_124 + V_47 , NULL ) ;
F_95 ( V_2 ) ;
}
}
static int T_7 F_96 ( struct V_115 * V_132 , struct V_115 * V_133 )
{
void T_1 * V_5 ;
struct V_134 * V_135 ;
T_3 V_64 ;
T_2 V_54 ;
T_2 V_53 ;
T_2 V_25 ;
int V_136 ;
int V_43 ;
int V_47 ;
V_5 = F_97 ( V_132 , 0 ) ;
if ( ! V_5 ) {
F_20 ( L_12 ,
V_132 -> V_137 ) ;
return - V_138 ;
}
V_25 = F_6 ( V_5 + V_139 ) & V_59 ;
if ( V_25 != V_60 && V_25 != V_61 ) {
F_20 ( L_13 ,
V_132 -> V_137 ) ;
V_43 = - V_68 ;
goto V_140;
}
if ( F_98 ( V_132 , L_14 , & V_54 ) )
V_54 = 1 ;
V_135 = F_99 ( sizeof( * V_135 ) * V_54 , V_141 ) ;
if ( ! V_135 ) {
V_43 = - V_142 ;
goto V_140;
}
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ ) {
struct V_143 V_144 ;
int V_127 ;
V_127 = F_100 ( V_132 , 1 + V_47 , & V_144 ) ;
V_135 [ V_47 ] . V_57 = F_97 ( V_132 , 1 + V_47 ) ;
if ( V_127 || ! V_135 [ V_47 ] . V_57 ) {
F_20 ( L_15 ,
V_132 -> V_137 , V_47 ) ;
V_43 = - V_68 ;
goto V_145;
}
V_135 [ V_47 ] . V_63 = V_144 . V_146 ;
}
if ( F_101 ( V_132 , L_16 , & V_64 ) )
V_64 = 0 ;
if ( ! F_102 () )
F_103 ( & V_44 ) ;
if ( F_45 ( & V_44 ) )
F_59 ( L_17 ) ;
V_4 . V_5 = V_5 ;
V_4 . V_56 = V_135 ;
V_4 . V_54 = V_54 ;
V_4 . V_64 = V_64 ;
V_53 = F_6 ( V_4 . V_5 + V_72 ) ;
V_4 . V_147 . V_148 = F_104 ( V_53 ) ;
V_136 = F_105 ( V_53 ) ;
if ( V_136 > 1020 )
V_136 = 1020 ;
V_4 . V_26 = V_136 ;
V_4 . V_45 = F_106 ( V_132 , & V_149 ,
& V_4 ) ;
V_4 . V_147 . V_150 = F_107 ( F_108 ( * V_4 . V_147 . V_150 ) ) ;
if ( F_69 ( ! V_4 . V_45 ) || F_69 ( ! V_4 . V_147 . V_150 ) ) {
V_43 = - V_142 ;
goto V_151;
}
F_109 ( F_43 ) ;
if ( F_65 ( V_74 ) && F_62 () )
F_110 ( V_132 , & V_4 . V_147 , V_4 . V_45 ) ;
F_77 () ;
F_50 () ;
F_63 () ;
F_83 () ;
return 0 ;
V_151:
if ( V_4 . V_45 )
F_111 ( V_4 . V_45 ) ;
F_112 ( V_4 . V_147 . V_150 ) ;
V_145:
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ )
if ( V_135 [ V_47 ] . V_57 )
F_113 ( V_135 [ V_47 ] . V_57 ) ;
F_114 ( V_135 ) ;
V_140:
F_113 ( V_5 ) ;
return V_43 ;
}
