static void F_1 ( unsigned int V_1 )
{
void (* F_2)( unsigned int ) = ( void V_2 * ) ( V_3 + 0x8000 ) ;
F_3 ( V_3 + 0x8000 , V_4 ,
V_5 - V_4 ) ;
V_6 = ~ 0 ;
V_7 = ~ 0 ;
V_8 = V_9 ;
V_10 = 0 ;
V_11 = V_11 ;
V_12 = V_12 ;
F_4 () ;
F_2 ( V_1 ) ;
F_5 () ;
V_8 = 0 ;
V_10 = 0 ;
}
static void F_6 ( void )
{
volatile unsigned long * V_13 = ( volatile void * ) 0xc0000000 ;
unsigned long V_14 = * V_13 ;
#ifndef F_7
T_1 V_15 ;
asm volatile(".arch_extension xscale\n\t"
"mra %Q0, %R0, acc0" : "=r" (acc0));
#endif
V_16 |= ( 1 << V_17 ) | ( 1 << V_18 ) ;
V_19 |= 1 << ( V_20 & 0x1f ) ;
V_21 = ~ 0 ;
V_22 = V_9 ;
V_11 = V_11 ;
V_12 = V_12 ;
V_23 |= ( 1u << 13 ) ;
V_23 &= ~ ( ( 1u << 12 ) | ( 1u << 1 ) ) ;
V_24 = 0x5c014000 ;
* V_13 = F_8 ( V_25 ) ;
F_9 ( 0 , V_26 ) ;
* V_13 = V_14 ;
V_22 = 0 ;
#ifndef F_7
asm volatile(".arch_extension xscale\n\t"
"mar acc0, %Q0, %R0" : "=r" (acc0));
#endif
}
static void F_10 ( T_2 V_27 )
{
if ( V_9 == 0 ) {
F_11 ( V_28 L_1 ) ;
return;
}
switch ( V_27 ) {
case V_29 :
F_1 ( V_30 ) ;
break;
case V_31 :
F_6 () ;
break;
}
}
static int F_12 ( T_2 V_27 )
{
return V_27 == V_31 || V_27 == V_29 ;
}
static void T_3 F_13 ( void )
{
V_3 = F_14 ( V_32 , V_33 ) ;
if ( ! V_3 ) {
F_11 ( V_28 L_2 ) ;
return;
}
V_34 |= V_35 | V_36 ;
V_37 |= V_35 | V_36 ;
V_38 |= V_35 | V_36 ;
V_39 = 0 ;
V_8 = 0 ;
V_10 = 0 ;
V_22 = 0 ;
V_40 = & V_41 ;
}
static int F_15 ( struct V_42 * V_43 , unsigned int V_44 )
{
unsigned long V_45 , V_46 = 0 ;
switch ( V_43 -> V_47 ) {
case V_48 :
V_46 = V_49 ;
break;
case V_50 :
V_46 = V_51 ;
break;
case V_52 :
case V_53 :
V_46 = V_54 ;
break;
case V_55 :
V_46 = V_56 ;
break;
case V_57 :
V_46 = V_58 ;
break;
case V_59 :
V_46 = V_60 ;
break;
case V_61 :
V_46 = V_62 ;
break;
case V_63 :
V_46 = V_64 ;
break;
case V_65 :
V_46 = V_66 ;
break;
case V_67 :
V_46 = V_68 ;
break;
case V_69 :
V_46 = V_70 ;
break;
case V_71 :
V_46 = V_72 ;
break;
case V_73 :
V_46 = V_74 ;
break;
case V_75 :
V_46 = V_76 ;
break;
case V_77 :
V_46 = V_78 ;
break;
case V_79 :
V_46 = V_80 ;
break;
case V_81 :
V_46 = V_82 ;
break;
case V_83 :
V_46 = V_84 ;
break;
case V_85 :
V_46 = V_86 ;
break;
case V_87 :
V_46 = V_88 ;
break;
case V_89 :
V_46 = V_90 ;
break;
case V_91 :
V_46 = V_92 ;
break;
case V_93 :
V_46 = V_94 ;
break;
default:
return - V_95 ;
}
F_16 ( V_45 ) ;
if ( V_44 )
V_9 |= V_46 ;
else
V_9 &= ~ V_46 ;
F_17 ( V_45 ) ;
return 0 ;
}
static inline void F_13 ( void ) {}
static void F_18 ( struct V_42 * V_43 )
{
V_96 |= F_19 ( V_43 -> V_47 - V_89 ) ;
}
static void F_20 ( struct V_42 * V_43 )
{
F_21 ( V_43 ) ;
V_96 &= ~ F_22 ( V_43 -> V_47 - V_89 ) ;
}
static void F_23 ( struct V_42 * V_43 )
{
F_24 ( V_43 ) ;
V_96 |= F_22 ( V_43 -> V_47 - V_89 ) ;
}
static int F_25 ( struct V_42 * V_43 , unsigned int V_97 )
{
if ( V_97 & V_98 )
V_99 |= 1 << ( V_43 -> V_47 - V_89 ) ;
if ( V_97 & V_100 )
V_99 |= 1 << ( V_43 -> V_47 - V_89 + 2 ) ;
return 0 ;
}
static void T_3 F_26 ( int (* F_2)( struct V_42 * ,
unsigned int ) )
{
int V_47 ;
for ( V_47 = V_89 ; V_47 <= V_91 ; V_47 ++ ) {
F_27 ( V_47 , & V_101 ,
V_102 ) ;
F_28 ( V_47 , V_103 ) ;
}
V_101 . V_104 = F_2 ;
}
static void T_3 F_29 ( void )
{
T_4 V_105 ;
__asm__ __volatile__("mrc p15, 0, %0, c15, c1, 0\n": "=r"(value));
V_105 |= ( 1 << 6 ) ;
__asm__ __volatile__("mcr p15, 0, %0, c15, c1, 0\n": :"r"(value));
F_26 ( F_15 ) ;
}
void T_3 F_30 ( void )
{
F_29 () ;
F_31 ( 56 , F_15 ) ;
}
void T_3 F_32 ( void )
{
F_29 () ;
F_33 ( F_15 ) ;
}
void T_3 F_34 ( void )
{
F_35 () ;
F_36 ( F_37 ( V_106 ) ) ;
F_38 ( 1 ) ;
}
void T_3 F_39 ( struct V_107 * V_108 )
{
F_40 ( & V_109 , V_108 ) ;
}
static int T_3 F_41 ( void )
{
int V_110 = 0 ;
if ( F_42 () ) {
V_111 = V_12 ;
V_11 &= ~ ( V_112 | V_113 | V_114 | V_115 ) ;
V_116 = ( V_116 & ~ V_117 ) | V_118 ;
if ( ( V_110 = F_43 ( V_119 , 32 ) ) )
return V_110 ;
F_13 () ;
F_44 ( & V_120 ) ;
F_44 ( & V_121 ) ;
if ( F_45 () )
return 0 ;
F_46 ( 32 , 100 ) ;
V_110 = F_47 ( V_122 , F_48 ( V_122 ) ) ;
if ( V_110 )
return V_110 ;
if ( F_49 () || F_50 () || F_51 () ) {
F_52 ( & V_123 ,
& V_124 ,
sizeof( V_124 ) ) ;
V_110 = F_53 ( & V_123 ) ;
}
}
return V_110 ;
}
