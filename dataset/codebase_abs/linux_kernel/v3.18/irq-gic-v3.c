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
if ( V_2 -> V_3 >= 8192 )
F_5 () ;
return NULL ;
}
static void F_6 ( void T_1 * V_6 )
{
T_2 V_7 = 1000000 ;
while ( F_7 ( V_6 + V_8 ) & V_9 ) {
V_7 -- ;
if ( ! V_7 ) {
F_8 ( L_1 ) ;
return;
}
F_9 () ;
F_10 ( 1 ) ;
} ;
}
static void F_11 ( void )
{
F_6 ( V_4 . V_5 ) ;
}
static void F_12 ( void )
{
F_6 ( F_13 () ) ;
}
static T_3 T_4 F_14 ( void )
{
T_3 V_10 ;
asm volatile("mrs_s %0, " __stringify(ICC_IAR1_EL1) : "=r" (irqstat));
return V_10 ;
}
static void T_4 F_15 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_PMR_EL1) ", %0" : : "r" (val));
}
static void T_4 F_16 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_CTLR_EL1) ", %0" : : "r" (val));
F_17 () ;
}
static void T_4 F_18 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_GRPEN1_EL1) ", %0" : : "r" (val));
F_17 () ;
}
static void T_4 F_19 ( T_3 V_11 )
{
asm volatile("msr_s " __stringify(ICC_SGI1R_EL1) ", %0" : : "r" (val));
}
static void F_20 ( void )
{
T_3 V_11 ;
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
V_11 |= V_12 ;
asm volatile("msr_s " __stringify(ICC_SRE_EL1) ", %0" : : "r" (val));
F_17 () ;
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
if ( ! ( V_11 & V_12 ) )
F_21 ( L_2 ) ;
}
static void F_22 ( bool V_13 )
{
void T_1 * V_14 ;
T_2 V_7 = 1000000 ;
T_2 V_11 ;
V_14 = F_13 () ;
V_11 = F_7 ( V_14 + V_15 ) ;
if ( V_13 )
V_11 &= ~ V_16 ;
else
V_11 |= V_16 ;
F_23 ( V_11 , V_14 + V_15 ) ;
if ( ! V_13 ) {
V_11 = F_7 ( V_14 + V_15 ) ;
if ( ! ( V_11 & V_16 ) )
return;
}
while ( V_7 -- ) {
V_11 = F_7 ( V_14 + V_15 ) ;
if ( V_13 ^ ( V_11 & V_17 ) )
break;
F_9 () ;
F_10 ( 1 ) ;
} ;
if ( ! V_7 )
F_8 ( L_3 ,
V_13 ? L_4 : L_5 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_12 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_11 ;
}
F_23 ( V_19 , V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
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
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_1 ( V_2 ) ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_22 = F_1 ( V_2 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( V_22 < 16 )
return - V_23 ;
if ( type != V_24 && type != V_25 )
return - V_23 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_12 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_11 ;
}
F_31 ( V_22 , type , V_6 , F_25 ) ;
return 0 ;
}
static T_3 F_32 ( T_3 V_26 )
{
T_3 V_27 ;
V_27 = ( F_33 ( V_26 , 3 ) << 32 |
F_33 ( V_26 , 2 ) << 16 |
F_33 ( V_26 , 1 ) << 8 |
F_33 ( V_26 , 0 ) ) ;
return V_27 ;
}
static T_5 void T_6 F_34 ( struct V_28 * V_29 )
{
T_3 V_30 ;
do {
V_30 = F_14 () ;
if ( F_35 ( V_30 > 15 && V_30 < 1020 ) ) {
int V_31 ;
V_31 = F_36 ( V_4 . V_32 , V_30 , V_29 ) ;
if ( V_31 ) {
F_37 ( true , L_6 ) ;
F_29 ( V_30 ) ;
}
continue;
}
if ( V_30 < 16 ) {
F_29 ( V_30 ) ;
#ifdef F_38
F_39 ( V_30 , V_29 ) ;
#else
F_37 ( true , L_7 ) ;
#endif
continue;
}
} while ( V_30 != V_33 );
}
static void T_7 F_40 ( void )
{
unsigned int V_34 ;
T_3 V_35 ;
void T_1 * V_6 = V_4 . V_5 ;
F_23 ( 0 , V_6 + V_8 ) ;
F_11 () ;
F_41 ( V_6 , V_4 . V_36 , F_11 ) ;
F_23 ( V_37 | V_38 | V_39 ,
V_6 + V_8 ) ;
V_35 = F_32 ( F_42 ( F_43 () ) ) ;
for ( V_34 = 32 ; V_34 < V_4 . V_36 ; V_34 ++ )
F_44 ( V_35 , V_6 + V_40 + V_34 * 8 ) ;
}
static int F_45 ( void )
{
T_3 V_26 = F_42 ( F_43 () ) ;
T_3 V_41 ;
T_2 V_27 ;
int V_34 ;
V_27 = ( F_33 ( V_26 , 3 ) << 24 |
F_33 ( V_26 , 2 ) << 16 |
F_33 ( V_26 , 1 ) << 8 |
F_33 ( V_26 , 0 ) ) ;
for ( V_34 = 0 ; V_34 < V_4 . V_42 ; V_34 ++ ) {
void T_1 * V_43 = V_4 . V_44 [ V_34 ] ;
T_2 V_45 ;
V_45 = F_7 ( V_43 + V_46 ) & V_47 ;
if ( V_45 != V_48 &&
V_45 != V_49 ) {
F_46 ( L_8 , V_43 ) ;
break;
}
do {
V_41 = F_47 ( V_43 + V_50 ) ;
if ( ( V_41 >> 32 ) == V_27 ) {
F_13 () = V_43 ;
F_48 ( L_9 ,
F_43 () ,
( unsigned long long ) V_26 , V_43 ) ;
return 0 ;
}
if ( V_4 . V_51 ) {
V_43 += V_4 . V_51 ;
} else {
V_43 += V_52 * 2 ;
if ( V_41 & V_53 )
V_43 += V_52 * 2 ;
}
} while ( ! ( V_41 & V_54 ) );
}
F_49 ( true , L_10 ,
F_43 () , ( unsigned long long ) V_26 ) ;
return - V_55 ;
}
static void F_50 ( void )
{
F_20 () ;
F_15 ( V_56 ) ;
F_16 ( V_57 ) ;
F_18 ( 1 ) ;
}
static void F_51 ( void )
{
void T_1 * V_14 ;
if ( F_45 () )
return;
F_22 ( true ) ;
V_14 = F_4 () ;
F_52 ( V_14 , F_12 ) ;
F_50 () ;
}
static int F_53 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_7 ( V_6 + V_18 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_19 ) ;
}
static int F_54 ( struct V_58 * V_59 ,
unsigned long V_60 , void * V_61 )
{
if ( V_60 == V_62 || V_60 == V_63 )
F_51 () ;
return V_64 ;
}
static T_8 F_55 ( int * V_65 , const struct V_66 * V_19 ,
T_3 V_67 )
{
int V_68 = * V_65 ;
T_3 V_26 = F_42 ( V_68 ) ;
T_8 V_69 = 0 ;
while ( V_68 < V_70 ) {
if ( F_56 ( ( V_26 & 0xff ) >= 16 ) )
goto V_71;
V_69 |= 1 << ( V_26 & 0xf ) ;
V_68 = F_57 ( V_68 , V_19 ) ;
if ( V_68 == V_70 )
goto V_71;
V_26 = F_42 ( V_68 ) ;
if ( V_67 != ( V_26 & ~ 0xffUL ) ) {
V_68 -- ;
goto V_71;
}
}
V_71:
* V_65 = V_68 ;
return V_69 ;
}
static void F_58 ( T_3 V_67 , T_8 V_69 , unsigned int V_22 )
{
T_3 V_11 ;
V_11 = ( F_33 ( V_67 , 3 ) << 48 |
F_33 ( V_67 , 2 ) << 32 |
V_22 << 24 |
F_33 ( V_67 , 1 ) << 16 |
V_69 ) ;
F_59 ( L_11 , F_43 () , V_11 ) ;
F_19 ( V_11 ) ;
}
static void F_60 ( const struct V_66 * V_19 , unsigned int V_22 )
{
int V_68 ;
if ( F_56 ( V_22 >= 16 ) )
return;
F_61 () ;
F_62 (cpu, *mask) {
T_3 V_67 = F_42 ( V_68 ) & ~ 0xffUL ;
T_8 V_69 ;
V_69 = F_55 ( & V_68 , V_19 , V_67 ) ;
F_58 ( V_67 , V_69 , V_22 ) ;
}
F_17 () ;
}
static void F_63 ( void )
{
F_64 ( F_60 ) ;
F_65 ( & V_72 ) ;
}
static int F_66 ( struct V_1 * V_2 , const struct V_66 * V_73 ,
bool V_74 )
{
unsigned int V_68 = F_67 ( V_73 , V_75 ) ;
void T_1 * V_45 ;
int V_76 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_23 ;
V_76 = F_53 ( V_2 , V_21 ) ;
if ( V_76 )
F_26 ( V_2 ) ;
V_45 = F_3 ( V_2 ) + V_40 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_32 ( F_42 ( V_68 ) ) ;
F_44 ( V_11 , V_45 ) ;
if ( V_76 )
F_27 ( V_2 ) ;
else
F_11 () ;
return V_77 ;
}
static int F_68 ( struct V_58 * V_78 ,
unsigned long V_79 , void * V_80 )
{
if ( V_79 == V_81 ) {
F_22 ( true ) ;
F_50 () ;
} else if ( V_79 == V_82 ) {
F_18 ( 0 ) ;
F_22 ( false ) ;
}
return V_64 ;
}
static void F_69 ( void )
{
F_70 ( & V_83 ) ;
}
static inline void F_69 ( void ) { }
static int F_71 ( struct V_84 * V_2 , unsigned int V_22 ,
T_9 V_85 )
{
if ( V_85 < 16 )
return - V_86 ;
if ( V_85 < 32 ) {
F_72 ( V_22 ) ;
F_73 ( V_22 , & V_87 ,
V_88 ) ;
F_74 ( V_22 , V_89 | V_90 ) ;
}
if ( V_85 >= 32 && V_85 < V_4 . V_36 ) {
F_73 ( V_22 , & V_87 ,
V_91 ) ;
F_74 ( V_22 , V_89 | V_92 ) ;
}
F_75 ( V_22 , V_2 -> V_93 ) ;
return 0 ;
}
static int F_76 ( struct V_84 * V_2 ,
struct V_94 * V_95 ,
const T_2 * V_96 , unsigned int V_97 ,
unsigned long * V_98 , unsigned int * V_99 )
{
if ( V_2 -> V_100 != V_95 )
return - V_23 ;
if ( V_97 < 3 )
return - V_23 ;
switch( V_96 [ 0 ] ) {
case 0 :
* V_98 = V_96 [ 1 ] + 32 ;
break;
case 1 :
* V_98 = V_96 [ 1 ] + 16 ;
break;
default:
return - V_23 ;
}
* V_99 = V_96 [ 2 ] & V_101 ;
return 0 ;
}
static int T_7 F_77 ( struct V_94 * V_102 , struct V_94 * V_103 )
{
void T_1 * V_5 ;
void T_1 * * V_44 ;
T_3 V_51 ;
T_2 V_42 ;
T_2 V_45 ;
int V_104 ;
int V_31 ;
int V_34 ;
V_5 = F_78 ( V_102 , 0 ) ;
if ( ! V_5 ) {
F_21 ( L_12 ,
V_102 -> V_105 ) ;
return - V_106 ;
}
V_45 = F_7 ( V_5 + V_107 ) & V_47 ;
if ( V_45 != V_48 && V_45 != V_49 ) {
F_21 ( L_13 ,
V_102 -> V_105 ) ;
V_31 = - V_55 ;
goto V_108;
}
if ( F_79 ( V_102 , L_14 , & V_42 ) )
V_42 = 1 ;
V_44 = F_80 ( sizeof( * V_44 ) * V_42 , V_109 ) ;
if ( ! V_44 ) {
V_31 = - V_110 ;
goto V_108;
}
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ ) {
V_44 [ V_34 ] = F_78 ( V_102 , 1 + V_34 ) ;
if ( ! V_44 [ V_34 ] ) {
F_21 ( L_15 ,
V_102 -> V_105 , V_34 ) ;
V_31 = - V_55 ;
goto V_111;
}
}
if ( F_81 ( V_102 , L_16 , & V_51 ) )
V_51 = 0 ;
V_4 . V_5 = V_5 ;
V_4 . V_44 = V_44 ;
V_4 . V_42 = V_42 ;
V_4 . V_51 = V_51 ;
V_104 = F_7 ( V_4 . V_5 + V_112 ) & 0x1f ;
V_104 = ( V_104 + 1 ) * 32 ;
if ( V_104 > 1020 )
V_104 = 1020 ;
V_4 . V_36 = V_104 ;
V_4 . V_32 = F_82 ( V_102 , & V_113 ,
& V_4 ) ;
V_4 . V_114 = F_83 ( F_84 ( * V_4 . V_114 ) ) ;
if ( F_56 ( ! V_4 . V_32 ) || F_56 ( ! V_4 . V_114 ) ) {
V_31 = - V_110 ;
goto V_115;
}
F_85 ( F_34 ) ;
F_63 () ;
F_40 () ;
F_51 () ;
F_69 () ;
return 0 ;
V_115:
if ( V_4 . V_32 )
F_86 ( V_4 . V_32 ) ;
F_87 ( V_4 . V_114 ) ;
V_111:
for ( V_34 = 0 ; V_34 < V_42 ; V_34 ++ )
if ( V_44 [ V_34 ] )
F_88 ( V_44 [ V_34 ] ) ;
F_89 ( V_44 ) ;
V_108:
F_88 ( V_5 ) ;
return V_31 ;
}
