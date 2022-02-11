static void F_1 ( unsigned int V_1 )
{
extern const char V_2 [] , V_3 [] ;
void (* F_2)( unsigned int ) = ( void V_4 * ) ( V_5 + 0x8000 ) ;
F_3 ( V_5 + 0x8000 , V_2 ,
V_3 - V_2 ) ;
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
extern void V_15 ( long ) ;
V_16 |= ( 1 << V_17 ) | ( 1 << V_18 ) ;
V_19 |= 1 << ( V_20 & 0x1f ) ;
V_21 = ~ 0 ;
V_22 = V_9 ;
V_11 = V_11 ;
V_12 = V_12 ;
V_23 |= ( 1u << 13 ) ;
V_23 &= ~ ( ( 1u << 12 ) | ( 1u << 1 ) ) ;
V_24 = 0x5c014000 ;
* V_13 = F_7 ( V_25 ) ;
V_15 ( V_26 - V_27 ) ;
* V_13 = V_14 ;
V_22 = 0 ;
}
static void F_8 ( T_1 V_28 )
{
if ( V_9 == 0 ) {
F_9 ( V_29 L_1 ) ;
return;
}
switch ( V_28 ) {
case V_30 :
F_1 ( V_31 ) ;
break;
case V_32 :
F_6 () ;
break;
}
}
static int F_10 ( T_1 V_28 )
{
return V_28 == V_32 || V_28 == V_30 ;
}
static void T_2 F_11 ( void )
{
V_5 = F_12 ( V_33 , V_34 ) ;
if ( ! V_5 ) {
F_9 ( V_29 L_2 ) ;
return;
}
V_35 |= V_36 | V_37 ;
V_38 |= V_36 | V_37 ;
V_39 |= V_36 | V_37 ;
V_40 = 0 ;
V_8 = 0 ;
V_10 = 0 ;
V_22 = 0 ;
V_41 = & V_42 ;
}
static int F_13 ( struct V_43 * V_44 , unsigned int V_45 )
{
unsigned long V_46 , V_47 = 0 ;
switch ( V_44 -> V_48 ) {
case V_49 :
V_47 = V_50 ;
break;
case V_51 :
V_47 = V_52 ;
break;
case V_53 :
case V_54 :
V_47 = V_55 ;
break;
case V_56 :
V_47 = V_57 ;
break;
case V_58 :
V_47 = V_59 ;
break;
case V_60 :
V_47 = V_61 ;
break;
case V_62 :
V_47 = V_63 ;
break;
case V_64 :
V_47 = V_65 ;
break;
case V_66 :
V_47 = V_67 ;
break;
case V_68 :
V_47 = V_69 ;
break;
case V_70 :
V_47 = V_71 ;
break;
case V_72 :
V_47 = V_73 ;
break;
case V_74 :
V_47 = V_75 ;
break;
case V_76 :
V_47 = V_77 ;
break;
case V_78 :
V_47 = V_79 ;
break;
case V_80 :
V_47 = V_81 ;
break;
case V_82 :
V_47 = V_83 ;
break;
case V_84 :
V_47 = V_85 ;
break;
case V_86 :
V_47 = V_87 ;
break;
case V_88 :
V_47 = V_89 ;
break;
case V_90 :
V_47 = V_91 ;
break;
case V_92 :
V_47 = V_93 ;
break;
case V_94 :
V_47 = V_95 ;
break;
default:
return - V_96 ;
}
F_14 ( V_46 ) ;
if ( V_45 )
V_9 |= V_47 ;
else
V_9 &= ~ V_47 ;
F_15 ( V_46 ) ;
return 0 ;
}
static inline void F_11 ( void ) {}
static void F_16 ( struct V_43 * V_44 )
{
V_97 |= F_17 ( V_44 -> V_48 - V_90 ) ;
}
static void F_18 ( struct V_43 * V_44 )
{
V_98 &= ~ ( 1 << ( ( V_44 -> V_48 - F_19 ( 0 ) ) & 0x1f ) ) ;
V_97 &= ~ F_20 ( V_44 -> V_48 - V_90 ) ;
}
static void F_21 ( struct V_43 * V_44 )
{
V_98 |= 1 << ( ( V_44 -> V_48 - F_19 ( 0 ) ) & 0x1f ) ;
V_97 |= F_20 ( V_44 -> V_48 - V_90 ) ;
}
static int F_22 ( struct V_43 * V_44 , unsigned int V_99 )
{
if ( V_99 & V_100 )
V_101 |= 1 << ( V_44 -> V_48 - V_90 ) ;
if ( V_99 & V_102 )
V_101 |= 1 << ( V_44 -> V_48 - V_90 + 2 ) ;
return 0 ;
}
static void T_2 F_23 ( T_3 F_2 )
{
int V_48 ;
for ( V_48 = V_90 ; V_48 <= V_92 ; V_48 ++ ) {
F_24 ( V_48 , & V_103 ,
V_104 ) ;
F_25 ( V_48 , V_105 ) ;
}
V_103 . V_106 = F_2 ;
}
void T_2 F_26 ( void )
{
T_4 V_107 ;
__asm__ __volatile__("mrc p15, 0, %0, c15, c1, 0\n": "=r"(value));
V_107 |= ( 1 << 6 ) ;
__asm__ __volatile__("mcr p15, 0, %0, c15, c1, 0\n": :"r"(value));
F_27 ( 56 , F_13 ) ;
F_23 ( F_13 ) ;
F_28 ( V_108 , 2 , 127 , NULL ) ;
}
void T_2 F_29 ( void )
{
F_30 () ;
F_31 ( F_32 ( V_109 ) ) ;
F_33 ( 1 ) ;
}
void T_2 F_34 ( struct V_110 * V_111 )
{
F_35 ( & V_112 , V_111 ) ;
}
static int T_2 F_36 ( void )
{
int V_113 = 0 ;
if ( F_37 () ) {
V_114 = V_12 ;
V_11 &= ~ ( V_115 | V_116 | V_117 | V_118 ) ;
F_38 ( V_119 , F_39 ( V_119 ) ) ;
if ( ( V_113 = F_40 ( V_120 , 32 ) ) )
return V_113 ;
F_11 () ;
F_41 ( & V_121 ) ;
F_41 ( & V_122 ) ;
F_41 ( & V_123 ) ;
F_41 ( & V_124 ) ;
V_113 = F_42 ( V_125 , F_39 ( V_125 ) ) ;
}
return V_113 ;
}
