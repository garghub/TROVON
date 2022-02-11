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
F_24 ( V_2 , V_21 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool V_11 )
{
T_2 V_24 ;
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
V_24 = V_11 ? V_28 : V_29 ;
break;
case V_30 :
V_24 = V_11 ? V_31 : V_32 ;
break;
case V_33 :
V_24 = V_11 ? V_20 : V_21 ;
break;
default:
return - V_26 ;
}
F_24 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
enum V_22 V_23 , bool * V_11 )
{
if ( V_2 -> V_3 >= V_4 . V_25 )
return - V_26 ;
switch ( V_23 ) {
case V_27 :
* V_11 = F_23 ( V_2 , V_28 ) ;
break;
case V_30 :
* V_11 = F_23 ( V_2 , V_31 ) ;
break;
case V_33 :
* V_11 = ! F_23 ( V_2 , V_21 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_31 ( F_1 ( V_2 ) ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_34 = F_1 ( V_2 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( V_34 < 16 )
return - V_26 ;
if ( V_34 >= 32 && type != V_35 &&
type != V_36 )
return - V_26 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_11 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_10 ;
}
return F_33 ( V_34 , type , V_6 , F_25 ) ;
}
static T_3 F_34 ( T_3 V_37 )
{
T_3 V_38 ;
V_38 = ( F_35 ( V_37 , 3 ) << 32 |
F_35 ( V_37 , 2 ) << 16 |
F_35 ( V_37 , 1 ) << 8 |
F_35 ( V_37 , 0 ) ) ;
return V_38 ;
}
static T_5 void T_6 F_36 ( struct V_39 * V_40 )
{
T_3 V_41 ;
do {
V_41 = F_13 () ;
if ( F_37 ( V_41 > 15 && V_41 < 1020 ) || V_41 >= 8192 ) {
int V_42 ;
V_42 = F_38 ( V_4 . V_43 , V_41 , V_40 ) ;
if ( V_42 ) {
F_39 ( true , L_6 ) ;
F_31 ( V_41 ) ;
}
continue;
}
if ( V_41 < 16 ) {
F_31 ( V_41 ) ;
#ifdef F_40
F_41 ( V_41 , V_40 ) ;
#else
F_39 ( true , L_7 ) ;
#endif
continue;
}
} while ( V_41 != V_44 );
}
static void T_7 F_42 ( void )
{
unsigned int V_45 ;
T_3 V_46 ;
void T_1 * V_6 = V_4 . V_5 ;
F_22 ( 0 , V_6 + V_8 ) ;
F_10 () ;
F_43 ( V_6 , V_4 . V_25 , F_10 ) ;
F_22 ( V_47 | V_48 | V_49 ,
V_6 + V_8 ) ;
V_46 = F_34 ( F_44 ( F_45 () ) ) ;
for ( V_45 = 32 ; V_45 < V_4 . V_25 ; V_45 ++ )
F_46 ( V_46 , V_6 + V_50 + V_45 * 8 ) ;
}
static int F_47 ( void )
{
T_3 V_37 = F_44 ( F_45 () ) ;
T_3 V_51 ;
T_2 V_38 ;
int V_45 ;
V_38 = ( F_35 ( V_37 , 3 ) << 24 |
F_35 ( V_37 , 2 ) << 16 |
F_35 ( V_37 , 1 ) << 8 |
F_35 ( V_37 , 0 ) ) ;
for ( V_45 = 0 ; V_45 < V_4 . V_52 ; V_45 ++ ) {
void T_1 * V_53 = V_4 . V_54 [ V_45 ] . V_55 ;
T_2 V_24 ;
V_24 = F_6 ( V_53 + V_56 ) & V_57 ;
if ( V_24 != V_58 &&
V_24 != V_59 ) {
F_48 ( L_8 , V_53 ) ;
break;
}
do {
V_51 = F_49 ( V_53 + V_60 ) ;
if ( ( V_51 >> 32 ) == V_38 ) {
T_3 V_18 = V_53 - V_4 . V_54 [ V_45 ] . V_55 ;
F_12 () = V_53 ;
F_50 () -> V_61 = V_4 . V_54 [ V_45 ] . V_61 + V_18 ;
F_51 ( L_9 ,
F_45 () ,
( unsigned long long ) V_37 ,
V_45 , & F_50 () -> V_61 ) ;
return 0 ;
}
if ( V_4 . V_62 ) {
V_53 += V_4 . V_62 ;
} else {
V_53 += V_63 * 2 ;
if ( V_51 & V_64 )
V_53 += V_63 * 2 ;
}
} while ( ! ( V_51 & V_65 ) );
}
F_52 ( true , L_10 ,
F_45 () , ( unsigned long long ) V_37 ) ;
return - V_66 ;
}
static void F_53 ( void )
{
F_19 () ;
F_14 ( V_67 ) ;
F_15 ( V_68 ) ;
F_17 ( 1 ) ;
}
static int F_54 ( void )
{
return ! ! ( F_6 ( V_4 . V_5 + V_69 ) & V_70 ) ;
}
static void F_55 ( void )
{
void T_1 * V_14 ;
if ( F_47 () )
return;
F_21 ( true ) ;
V_14 = F_4 () ;
F_56 ( V_14 , F_11 ) ;
if ( F_57 ( V_71 ) && F_54 () )
F_58 () ;
F_53 () ;
}
static int F_59 ( struct V_72 * V_73 ,
unsigned long V_74 , void * V_75 )
{
if ( V_74 == V_76 || V_74 == V_77 )
F_55 () ;
return V_78 ;
}
static T_8 F_60 ( int * V_79 , const struct V_80 * V_19 ,
T_3 V_81 )
{
int V_82 = * V_79 ;
T_3 V_37 = F_44 ( V_82 ) ;
T_8 V_83 = 0 ;
while ( V_82 < V_84 ) {
if ( F_61 ( ( V_37 & 0xff ) >= 16 ) )
goto V_85;
V_83 |= 1 << ( V_37 & 0xf ) ;
V_82 = F_62 ( V_82 , V_19 ) ;
if ( V_82 >= V_84 )
goto V_85;
V_37 = F_44 ( V_82 ) ;
if ( V_81 != ( V_37 & ~ 0xffUL ) ) {
V_82 -- ;
goto V_85;
}
}
V_85:
* V_79 = V_82 ;
return V_83 ;
}
static void F_63 ( T_3 V_81 , T_8 V_83 , unsigned int V_34 )
{
T_3 V_11 ;
V_11 = ( F_64 ( V_81 , 3 ) |
F_64 ( V_81 , 2 ) |
V_34 << V_86 |
F_64 ( V_81 , 1 ) |
V_83 << V_87 ) ;
F_65 ( L_11 , F_45 () , V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_66 ( const struct V_80 * V_19 , unsigned int V_34 )
{
int V_82 ;
if ( F_61 ( V_34 >= 16 ) )
return;
F_67 () ;
F_68 (cpu, mask) {
T_3 V_81 = F_44 ( V_82 ) & ~ 0xffUL ;
T_8 V_83 ;
V_83 = F_60 ( & V_82 , V_19 , V_81 ) ;
F_63 ( V_81 , V_83 , V_34 ) ;
}
F_16 () ;
}
static void F_69 ( void )
{
F_70 ( F_66 ) ;
F_71 ( & V_88 ) ;
}
static int F_72 ( struct V_1 * V_2 , const struct V_80 * V_89 ,
bool V_90 )
{
unsigned int V_82 = F_73 ( V_89 , V_91 ) ;
void T_1 * V_24 ;
int V_92 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_26 ;
V_92 = F_23 ( V_2 , V_21 ) ;
if ( V_92 )
F_26 ( V_2 ) ;
V_24 = F_3 ( V_2 ) + V_50 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_34 ( F_44 ( V_82 ) ) ;
F_46 ( V_11 , V_24 ) ;
if ( V_92 )
F_27 ( V_2 ) ;
else
F_10 () ;
return V_93 ;
}
static int F_74 ( struct V_72 * V_94 ,
unsigned long V_95 , void * V_96 )
{
if ( V_95 == V_97 ) {
F_21 ( true ) ;
F_53 () ;
} else if ( V_95 == V_98 ) {
F_17 ( 0 ) ;
F_21 ( false ) ;
}
return V_78 ;
}
static void F_75 ( void )
{
F_76 ( & V_99 ) ;
}
static inline void F_75 ( void ) { }
static int F_77 ( struct V_100 * V_2 , unsigned int V_34 ,
T_9 V_101 )
{
if ( V_101 < 16 )
return - V_102 ;
if ( V_101 >= V_4 . V_25 && V_101 < 8192 )
return - V_102 ;
if ( V_101 >= V_103 )
return - V_102 ;
if ( V_101 < 32 ) {
F_78 ( V_34 ) ;
F_79 ( V_2 , V_34 , V_101 , & V_104 , V_2 -> V_105 ,
V_106 , NULL , NULL ) ;
F_80 ( V_34 , V_107 | V_108 ) ;
}
if ( V_101 >= 32 && V_101 < V_4 . V_25 ) {
F_79 ( V_2 , V_34 , V_101 , & V_104 , V_2 -> V_105 ,
V_109 , NULL , NULL ) ;
F_80 ( V_34 , V_107 | V_110 ) ;
}
if ( V_101 >= 8192 && V_101 < V_103 ) {
if ( ! F_54 () )
return - V_102 ;
F_79 ( V_2 , V_34 , V_101 , & V_104 , V_2 -> V_105 ,
V_109 , NULL , NULL ) ;
F_80 ( V_34 , V_107 ) ;
}
return 0 ;
}
static int F_81 ( struct V_100 * V_2 ,
struct V_111 * V_112 ,
const T_2 * V_113 , unsigned int V_114 ,
unsigned long * V_115 , unsigned int * V_116 )
{
if ( V_2 -> V_117 != V_112 )
return - V_26 ;
if ( V_114 < 3 )
return - V_26 ;
switch( V_113 [ 0 ] ) {
case 0 :
* V_115 = V_113 [ 1 ] + 32 ;
break;
case 1 :
* V_115 = V_113 [ 1 ] + 16 ;
break;
case V_118 :
* V_115 = V_113 [ 1 ] ;
break;
default:
return - V_26 ;
}
* V_116 = V_113 [ 2 ] & V_119 ;
return 0 ;
}
static int F_82 ( struct V_100 * V_43 , unsigned int V_120 ,
unsigned int V_121 , void * V_122 )
{
int V_45 , V_123 ;
T_9 V_3 ;
unsigned int type = V_124 ;
struct V_125 * V_1 = V_122 ;
V_123 = F_81 ( V_43 , V_1 -> V_126 , V_1 -> args ,
V_1 -> V_127 , & V_3 , & type ) ;
if ( V_123 )
return V_123 ;
for ( V_45 = 0 ; V_45 < V_121 ; V_45 ++ )
F_77 ( V_43 , V_120 + V_45 , V_3 + V_45 ) ;
return 0 ;
}
static void F_83 ( struct V_100 * V_43 , unsigned int V_120 ,
unsigned int V_121 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_121 ; V_45 ++ ) {
struct V_1 * V_2 = F_84 ( V_43 , V_120 + V_45 ) ;
F_85 ( V_120 + V_45 , NULL ) ;
F_86 ( V_2 ) ;
}
}
static int T_7 F_87 ( struct V_111 * V_128 , struct V_111 * V_129 )
{
void T_1 * V_5 ;
struct V_130 * V_131 ;
T_3 V_62 ;
T_2 V_52 ;
T_2 V_51 ;
T_2 V_24 ;
int V_132 ;
int V_42 ;
int V_45 ;
V_5 = F_88 ( V_128 , 0 ) ;
if ( ! V_5 ) {
F_20 ( L_12 ,
V_128 -> V_133 ) ;
return - V_134 ;
}
V_24 = F_6 ( V_5 + V_135 ) & V_57 ;
if ( V_24 != V_58 && V_24 != V_59 ) {
F_20 ( L_13 ,
V_128 -> V_133 ) ;
V_42 = - V_66 ;
goto V_136;
}
if ( F_89 ( V_128 , L_14 , & V_52 ) )
V_52 = 1 ;
V_131 = F_90 ( sizeof( * V_131 ) * V_52 , V_137 ) ;
if ( ! V_131 ) {
V_42 = - V_138 ;
goto V_136;
}
for ( V_45 = 0 ; V_45 < V_52 ; V_45 ++ ) {
struct V_139 V_140 ;
int V_123 ;
V_123 = F_91 ( V_128 , 1 + V_45 , & V_140 ) ;
V_131 [ V_45 ] . V_55 = F_88 ( V_128 , 1 + V_45 ) ;
if ( V_123 || ! V_131 [ V_45 ] . V_55 ) {
F_20 ( L_15 ,
V_128 -> V_133 , V_45 ) ;
V_42 = - V_66 ;
goto V_141;
}
V_131 [ V_45 ] . V_61 = V_140 . V_142 ;
}
if ( F_92 ( V_128 , L_16 , & V_62 ) )
V_62 = 0 ;
V_4 . V_5 = V_5 ;
V_4 . V_54 = V_131 ;
V_4 . V_52 = V_52 ;
V_4 . V_62 = V_62 ;
V_51 = F_6 ( V_4 . V_5 + V_69 ) ;
V_4 . V_143 . V_144 = F_93 ( V_51 ) ;
V_132 = F_94 ( V_51 ) ;
if ( V_132 > 1020 )
V_132 = 1020 ;
V_4 . V_25 = V_132 ;
V_4 . V_43 = F_95 ( V_128 , & V_145 ,
& V_4 ) ;
V_4 . V_143 . V_146 = F_96 ( F_97 ( * V_4 . V_143 . V_146 ) ) ;
if ( F_61 ( ! V_4 . V_43 ) || F_61 ( ! V_4 . V_143 . V_146 ) ) {
V_42 = - V_138 ;
goto V_147;
}
F_98 ( F_36 ) ;
if ( F_57 ( V_71 ) && F_54 () )
F_99 ( V_128 , & V_4 . V_143 , V_4 . V_43 ) ;
F_69 () ;
F_42 () ;
F_55 () ;
F_75 () ;
return 0 ;
V_147:
if ( V_4 . V_43 )
F_100 ( V_4 . V_43 ) ;
F_101 ( V_4 . V_143 . V_146 ) ;
V_141:
for ( V_45 = 0 ; V_45 < V_52 ; V_45 ++ )
if ( V_131 [ V_45 ] . V_55 )
F_102 ( V_131 [ V_45 ] . V_55 ) ;
F_103 ( V_131 ) ;
V_136:
F_102 ( V_5 ) ;
return V_42 ;
}
