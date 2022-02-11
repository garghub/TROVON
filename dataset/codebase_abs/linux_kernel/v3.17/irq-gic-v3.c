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
static void F_22 ( void )
{
void T_1 * V_13 ;
T_2 V_7 = 1000000 ;
T_2 V_11 ;
V_13 = F_13 () ;
V_11 = F_7 ( V_13 + V_14 ) ;
V_11 &= ~ V_15 ;
F_23 ( V_11 , V_13 + V_14 ) ;
while ( F_7 ( V_13 + V_14 ) & V_16 ) {
V_7 -- ;
if ( ! V_7 ) {
F_8 ( L_3 ) ;
return;
}
F_9 () ;
F_10 ( 1 ) ;
} ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_12 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_11 ;
}
F_23 ( V_18 , V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) ;
F_25 () ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_19 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_20 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_1 ( V_2 ) ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_21 = F_1 ( V_2 ) ;
void (* F_25)( void );
void T_1 * V_6 ;
if ( V_21 < 16 )
return - V_22 ;
if ( type != V_23 && type != V_24 )
return - V_22 ;
if ( F_2 ( V_2 ) ) {
V_6 = F_4 () ;
F_25 = F_12 ;
} else {
V_6 = V_4 . V_5 ;
F_25 = F_11 ;
}
F_31 ( V_21 , type , V_6 , F_25 ) ;
return 0 ;
}
static T_3 F_32 ( T_3 V_25 )
{
T_3 V_26 ;
V_26 = ( F_33 ( V_25 , 3 ) << 32 |
F_33 ( V_25 , 2 ) << 16 |
F_33 ( V_25 , 1 ) << 8 |
F_33 ( V_25 , 0 ) ) ;
return V_26 ;
}
static T_5 void T_6 F_34 ( struct V_27 * V_28 )
{
T_3 V_29 ;
do {
V_29 = F_14 () ;
if ( F_35 ( V_29 > 15 && V_29 < 1020 ) ) {
T_3 V_21 = F_36 ( V_4 . V_30 , V_29 ) ;
if ( F_35 ( V_21 ) ) {
F_37 ( V_21 , V_28 ) ;
continue;
}
F_38 ( true , L_4 ) ;
F_29 ( V_29 ) ;
}
if ( V_29 < 16 ) {
F_29 ( V_29 ) ;
#ifdef F_39
F_40 ( V_29 , V_28 ) ;
#else
F_38 ( true , L_5 ) ;
#endif
continue;
}
} while ( V_29 != V_31 );
}
static void T_7 F_41 ( void )
{
unsigned int V_32 ;
T_3 V_33 ;
void T_1 * V_6 = V_4 . V_5 ;
F_23 ( 0 , V_6 + V_8 ) ;
F_11 () ;
F_42 ( V_6 , V_4 . V_34 , F_11 ) ;
F_23 ( V_35 | V_36 | V_37 ,
V_6 + V_8 ) ;
V_33 = F_32 ( F_43 ( F_44 () ) ) ;
for ( V_32 = 32 ; V_32 < V_4 . V_34 ; V_32 ++ )
F_45 ( V_33 , V_6 + V_38 + V_32 * 8 ) ;
}
static int F_46 ( void )
{
T_3 V_25 = F_43 ( F_44 () ) ;
T_3 V_39 ;
T_2 V_26 ;
int V_32 ;
V_26 = ( F_33 ( V_25 , 3 ) << 24 |
F_33 ( V_25 , 2 ) << 16 |
F_33 ( V_25 , 1 ) << 8 |
F_33 ( V_25 , 0 ) ) ;
for ( V_32 = 0 ; V_32 < V_4 . V_40 ; V_32 ++ ) {
void T_1 * V_41 = V_4 . V_42 [ V_32 ] ;
T_2 V_43 ;
V_43 = F_7 ( V_41 + V_44 ) & V_45 ;
if ( V_43 != V_46 &&
V_43 != V_47 ) {
F_47 ( L_6 , V_41 ) ;
break;
}
do {
V_39 = F_48 ( V_41 + V_48 ) ;
if ( ( V_39 >> 32 ) == V_26 ) {
F_13 () = V_41 ;
F_49 ( L_7 ,
F_44 () ,
( unsigned long long ) V_25 , V_41 ) ;
return 0 ;
}
if ( V_4 . V_49 ) {
V_41 += V_4 . V_49 ;
} else {
V_41 += V_50 * 2 ;
if ( V_39 & V_51 )
V_41 += V_50 * 2 ;
}
} while ( ! ( V_39 & V_52 ) );
}
F_50 ( true , L_8 ,
F_44 () , ( unsigned long long ) V_25 ) ;
return - V_53 ;
}
static void F_51 ( void )
{
void T_1 * V_13 ;
if ( F_46 () )
return;
F_22 () ;
V_13 = F_4 () ;
F_52 ( V_13 , F_12 ) ;
F_20 () ;
F_15 ( V_54 ) ;
F_16 ( V_55 ) ;
F_18 ( 1 ) ;
}
static int F_53 ( struct V_1 * V_2 , T_2 V_17 )
{
T_2 V_18 = 1 << ( F_1 ( V_2 ) % 32 ) ;
void T_1 * V_6 ;
if ( F_2 ( V_2 ) )
V_6 = F_4 () ;
else
V_6 = V_4 . V_5 ;
return ! ! ( F_7 ( V_6 + V_17 + ( F_1 ( V_2 ) / 32 ) * 4 ) & V_18 ) ;
}
static int F_54 ( struct V_56 * V_57 ,
unsigned long V_58 , void * V_59 )
{
if ( V_58 == V_60 || V_58 == V_61 )
F_51 () ;
return V_62 ;
}
static T_8 F_55 ( int * V_63 , const struct V_64 * V_18 ,
T_3 V_65 )
{
int V_66 = * V_63 ;
T_3 V_25 = F_43 ( V_66 ) ;
T_8 V_67 = 0 ;
while ( V_66 < V_68 ) {
if ( F_56 ( ( V_25 & 0xff ) >= 16 ) )
goto V_69;
V_67 |= 1 << ( V_25 & 0xf ) ;
V_66 = F_57 ( V_66 , V_18 ) ;
if ( V_66 == V_68 )
goto V_69;
V_25 = F_43 ( V_66 ) ;
if ( V_65 != ( V_25 & ~ 0xffUL ) ) {
V_66 -- ;
goto V_69;
}
}
V_69:
* V_63 = V_66 ;
return V_67 ;
}
static void F_58 ( T_3 V_65 , T_8 V_67 , unsigned int V_21 )
{
T_3 V_11 ;
V_11 = ( F_33 ( V_65 , 3 ) << 48 |
F_33 ( V_65 , 2 ) << 32 |
V_21 << 24 |
F_33 ( V_65 , 1 ) << 16 |
V_67 ) ;
F_59 ( L_9 , F_44 () , V_11 ) ;
F_19 ( V_11 ) ;
}
static void F_60 ( const struct V_64 * V_18 , unsigned int V_21 )
{
int V_66 ;
if ( F_56 ( V_21 >= 16 ) )
return;
F_61 () ;
F_62 (cpu, *mask) {
T_3 V_65 = F_43 ( V_66 ) & ~ 0xffUL ;
T_8 V_67 ;
V_67 = F_55 ( & V_66 , V_18 , V_65 ) ;
F_58 ( V_65 , V_67 , V_21 ) ;
}
F_17 () ;
}
static void F_63 ( void )
{
F_64 ( F_60 ) ;
F_65 ( & V_70 ) ;
}
static int F_66 ( struct V_1 * V_2 , const struct V_64 * V_71 ,
bool V_72 )
{
unsigned int V_66 = F_67 ( V_71 , V_73 ) ;
void T_1 * V_43 ;
int V_74 ;
T_3 V_11 ;
if ( F_2 ( V_2 ) )
return - V_22 ;
V_74 = F_53 ( V_2 , V_20 ) ;
if ( V_74 )
F_26 ( V_2 ) ;
V_43 = F_3 ( V_2 ) + V_38 + ( F_1 ( V_2 ) * 8 ) ;
V_11 = F_32 ( F_43 ( V_66 ) ) ;
F_45 ( V_11 , V_43 ) ;
if ( V_74 )
F_27 ( V_2 ) ;
else
F_11 () ;
return V_75 ;
}
static int F_68 ( struct V_76 * V_2 , unsigned int V_21 ,
T_9 V_77 )
{
if ( V_77 < 16 )
return - V_78 ;
if ( V_77 < 32 ) {
F_69 ( V_21 ) ;
F_70 ( V_21 , & V_79 ,
V_80 ) ;
F_71 ( V_21 , V_81 | V_82 ) ;
}
if ( V_77 >= 32 && V_77 < V_4 . V_34 ) {
F_70 ( V_21 , & V_79 ,
V_83 ) ;
F_71 ( V_21 , V_81 | V_84 ) ;
}
F_72 ( V_21 , V_2 -> V_85 ) ;
return 0 ;
}
static int F_73 ( struct V_76 * V_2 ,
struct V_86 * V_87 ,
const T_2 * V_88 , unsigned int V_89 ,
unsigned long * V_90 , unsigned int * V_91 )
{
if ( V_2 -> V_92 != V_87 )
return - V_22 ;
if ( V_89 < 3 )
return - V_22 ;
switch( V_88 [ 0 ] ) {
case 0 :
* V_90 = V_88 [ 1 ] + 32 ;
break;
case 1 :
* V_90 = V_88 [ 1 ] + 16 ;
break;
default:
return - V_22 ;
}
* V_91 = V_88 [ 2 ] & V_93 ;
return 0 ;
}
static int T_7 F_74 ( struct V_86 * V_94 , struct V_86 * V_95 )
{
void T_1 * V_5 ;
void T_1 * * V_42 ;
T_3 V_49 ;
T_2 V_40 ;
T_2 V_43 ;
int V_96 ;
int V_97 ;
int V_32 ;
V_5 = F_75 ( V_94 , 0 ) ;
if ( ! V_5 ) {
F_21 ( L_10 ,
V_94 -> V_98 ) ;
return - V_99 ;
}
V_43 = F_7 ( V_5 + V_100 ) & V_45 ;
if ( V_43 != V_46 && V_43 != V_47 ) {
F_21 ( L_11 ,
V_94 -> V_98 ) ;
V_97 = - V_53 ;
goto V_101;
}
if ( F_76 ( V_94 , L_12 , & V_40 ) )
V_40 = 1 ;
V_42 = F_77 ( sizeof( * V_42 ) * V_40 , V_102 ) ;
if ( ! V_42 ) {
V_97 = - V_103 ;
goto V_101;
}
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
V_42 [ V_32 ] = F_75 ( V_94 , 1 + V_32 ) ;
if ( ! V_42 [ V_32 ] ) {
F_21 ( L_13 ,
V_94 -> V_98 , V_32 ) ;
V_97 = - V_53 ;
goto V_104;
}
}
if ( F_78 ( V_94 , L_14 , & V_49 ) )
V_49 = 0 ;
V_4 . V_5 = V_5 ;
V_4 . V_42 = V_42 ;
V_4 . V_40 = V_40 ;
V_4 . V_49 = V_49 ;
V_96 = F_7 ( V_4 . V_5 + V_105 ) & 0x1f ;
V_96 = ( V_96 + 1 ) * 32 ;
if ( V_96 > 1020 )
V_96 = 1020 ;
V_4 . V_34 = V_96 ;
V_4 . V_30 = F_79 ( V_94 , & V_106 ,
& V_4 ) ;
V_4 . V_107 = F_80 ( F_81 ( * V_4 . V_107 ) ) ;
if ( F_56 ( ! V_4 . V_30 ) || F_56 ( ! V_4 . V_107 ) ) {
V_97 = - V_103 ;
goto V_108;
}
F_82 ( F_34 ) ;
F_63 () ;
F_41 () ;
F_51 () ;
return 0 ;
V_108:
if ( V_4 . V_30 )
F_83 ( V_4 . V_30 ) ;
F_84 ( V_4 . V_107 ) ;
V_104:
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ )
if ( V_42 [ V_32 ] )
F_85 ( V_42 [ V_32 ] ) ;
F_86 ( V_42 ) ;
V_101:
F_85 ( V_5 ) ;
return V_97 ;
}
