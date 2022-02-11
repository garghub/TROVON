static inline void F_1 ( T_1 * V_1 , T_1 V_2 )
{
* V_1 = V_2 ;
F_2 ( ( V_3 ) V_1 , ( V_3 ) V_1 + 4 ) ;
}
static void F_3 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_6 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_7 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#endif
}
static void F_5 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_6 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_7 | V_5 | ( ( V_4 + 4 ) & 0x0000fffc ) ) ;
#endif
}
static void F_6 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
F_1 ( V_1 , V_7 | V_5 | ( V_4 & 0x0000ffff ) ) ;
}
static void F_7 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_8 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_9 | V_5 | ( ( V_4 + 4 ) & 0x0000fffc ) ) ;
#endif
}
static void F_8 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
F_1 ( V_1 , V_9 | V_5 | ( V_4 & 0x0000fffc ) ) ;
}
static void F_9 ( T_1 * V_1 )
{
F_1 ( V_1 , V_10 ) ;
}
static void F_10 ( T_1 * V_1 , int V_4 )
{
#if F_11 ( V_11 ) && F_11 ( V_12 )
if ( ( V_3 ) V_1 < ( V_3 ) & V_13 )
return;
#endif
F_1 ( V_1 , V_14 | ( V_4 & V_15 ) ) ;
}
static T_1 * F_12 ( int V_16 )
{
T_1 * V_17 ;
if ( ( V_18 + V_16 ) > F_13 ( V_19 ) ) {
F_14 ( V_20 L_1 ,
V_18 , V_16 ) ;
V_21 = false ;
return NULL ;
}
V_17 = ( void * ) & V_19 [ V_18 ] ;
V_18 += V_16 ;
return V_17 ;
}
static void F_15 ( T_1 * V_1 , T_1 V_5 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_25 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_26 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_28 , V_25 * 4 ) ;
V_17 [ V_26 ] |= V_23 & V_15 ;
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_29 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_29 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_29 ] |= V_5 ;
break;
}
V_17 [ V_33 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_25 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_18 ( T_1 * V_1 , T_1 V_5 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_34 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_35 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_36 , V_34 * 4 ) ;
V_17 [ V_35 ] |= V_23 & V_15 ;
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_37 ] ,
F_17 ( V_30 ) , V_31 ) ;
F_3 ( & V_17 [ V_38 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_37 ] ,
F_17 ( V_32 ) , V_31 ) ;
F_3 ( & V_17 [ V_38 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_37 ] |= V_5 ;
V_17 [ V_38 ] |= V_5 ;
break;
}
V_17 [ V_39 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_34 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_19 ( T_1 * V_1 , T_1 V_5 , int V_40 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_41 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_42 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_43 , V_41 * 4 ) ;
V_17 [ V_42 ] |= V_23 & V_15 ;
if ( V_40 ) {
V_17 [ V_44 ] =
V_45 | F_20 ( 30 ) | V_46 ;
} else {
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_44 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_44 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_44 ] |= V_5 ;
break;
}
}
V_17 [ V_47 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_41 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_21 ( T_1 * V_1 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_48 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_49 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_50 , V_48 * 4 ) ;
V_17 [ V_49 ] |= V_23 & V_15 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_48 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_22 ( T_1 * V_1 , T_1 V_5 , T_1 V_51 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_52 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_53 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_54 , V_52 * 4 ) ;
V_17 [ V_53 ] |= V_23 & V_15 ;
V_17 [ V_55 ] |= ( V_51 << 10 ) ;
V_17 [ V_56 ] |= V_5 ;
V_17 [ V_57 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_52 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_23 ( void * V_58 )
{
T_1 * V_59 = V_58 ;
V_3 V_60 [ 8 ] ;
V_3 V_61 [ 8 ] ;
V_60 [ 0 ] = V_62 ;
V_60 [ 1 ] = V_62 ;
F_24 ( V_60 , V_61 , V_63 | V_64 ) ;
* V_59 = V_61 [ 0 ] ;
}
static void F_25 ( T_1 * V_1 , T_1 V_59 )
{
T_1 V_65 = * V_1 ;
T_1 V_66 = V_65 & ~ V_67 ;
T_1 V_68 = V_65 & V_67 ;
switch ( V_66 ) {
case V_69 :
F_5 ( V_1 , F_17 ( V_70 ) , V_68 ) ;
break;
case F_26 ( V_71 ) :
F_5 ( V_1 , F_17 ( V_72 ) , V_68 ) ;
break;
case F_26 ( V_73 ) :
F_5 ( V_1 , F_17 ( V_74 ) , V_68 ) ;
break;
case F_26 ( V_75 ) :
F_5 ( V_1 , F_17 ( V_76 ) , V_68 ) ;
break;
case F_26 ( V_77 ) :
F_5 ( V_1 , F_17 ( V_78 ) , V_68 ) ;
break;
case F_26 ( V_79 ) :
F_5 ( V_1 , F_17 ( V_80 ) , V_68 ) ;
break;
case F_26 ( V_81 ) :
F_5 ( V_1 , F_17 ( V_82 ) , V_68 ) ;
break;
#ifdef F_27
case F_26 ( V_83 ) :
#else
case F_26 ( V_84 ) :
#endif
F_5 ( V_1 , F_17 ( V_85 ) , V_68 ) ;
break;
case F_26 ( V_86 ) :
F_6 ( V_1 , F_17 ( V_87 ) , V_68 ) ;
break;
#ifdef F_28
case F_26 ( V_88 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_90 ) , V_68 ) ;
break;
case F_26 ( V_91 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_92 ) , V_68 ) ;
break;
case F_26 ( V_93 ) :
if ( V_59 & V_89 )
F_5 ( V_1 , F_17 ( V_94 ) , V_68 ) ;
break;
case F_26 ( V_95 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_96 ) + 4 , V_68 ) ;
break;
case F_26 ( V_97 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_98 ) , V_68 ) ;
break;
case F_26 ( V_99 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_100 ) , V_68 ) ;
break;
case F_26 ( V_101 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_96 ) , V_68 ) ;
break;
#endif
case F_26 ( V_102 ) :
#ifdef F_27
case F_26 ( V_103 ) :
#endif
if ( V_59 & V_89 )
F_5 ( V_1 , F_17 ( V_104 ) , V_68 ) ;
break;
case F_26 ( V_105 ) :
#ifdef F_27
case F_26 ( V_106 ) :
#endif
if ( V_59 & V_89 )
F_5 ( V_1 , F_17 ( V_107 ) , V_68 ) ;
break;
case F_26 ( V_108 ) :
#ifdef F_27
case F_26 ( V_109 ) :
#endif
if ( V_59 & V_89 )
F_5 ( V_1 , F_17 ( V_110 ) , V_68 ) ;
break;
case F_26 ( V_111 ) :
#ifdef F_27
case F_26 ( V_112 ) :
#endif
if ( V_59 & V_89 )
F_5 ( V_1 , F_17 ( V_113 ) , V_68 ) ;
break;
#ifdef F_27
case F_26 ( V_114 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_115 ) , V_68 ) ;
break;
#endif
case F_26 ( V_116 ) :
if ( V_59 & V_89 )
F_6 ( V_1 , F_17 ( V_117 ) , V_68 ) ;
break;
case F_29 ( V_71 ) :
F_7 ( V_1 , F_17 ( V_72 ) , V_68 ) ;
break;
case F_29 ( V_73 ) :
F_7 ( V_1 , F_17 ( V_74 ) , V_68 ) ;
break;
case F_29 ( V_75 ) :
F_7 ( V_1 , F_17 ( V_76 ) , V_68 ) ;
break;
case F_29 ( V_77 ) :
F_7 ( V_1 , F_17 ( V_78 ) , V_68 ) ;
break;
case F_29 ( V_79 ) :
F_7 ( V_1 , F_17 ( V_80 ) , V_68 ) ;
break;
case F_29 ( V_81 ) :
F_7 ( V_1 , F_17 ( V_82 ) , V_68 ) ;
break;
#ifdef F_27
case F_29 ( V_83 ) :
#else
case F_29 ( V_84 ) :
#endif
F_7 ( V_1 , F_17 ( V_85 ) , V_68 ) ;
break;
case F_29 ( V_86 ) :
F_8 ( V_1 , F_17 ( V_87 ) , V_68 ) ;
break;
#ifdef F_28
case F_29 ( V_88 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_90 ) , V_68 ) ;
break;
case F_29 ( V_91 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_92 ) , V_68 ) ;
break;
case F_29 ( V_93 ) :
if ( V_59 & V_89 )
F_7 ( V_1 , F_17 ( V_94 ) , V_68 ) ;
break;
case F_29 ( V_95 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_96 ) + 4 , V_68 ) ;
break;
case F_29 ( V_97 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_98 ) , V_68 ) ;
break;
case F_29 ( V_99 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_100 ) , V_68 ) ;
break;
case F_29 ( V_101 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_96 ) , V_68 ) ;
break;
#endif
case F_29 ( V_102 ) :
if ( V_59 & V_89 )
F_7 ( V_1 , F_17 ( V_104 ) , V_68 ) ;
break;
case F_29 ( V_105 ) :
if ( V_59 & V_89 )
F_7 ( V_1 , F_17 ( V_107 ) , V_68 ) ;
break;
case F_29 ( V_108 ) :
if ( V_59 & V_89 )
F_7 ( V_1 , F_17 ( V_110 ) , V_68 ) ;
break;
case F_29 ( V_111 ) :
if ( V_59 & V_89 )
F_7 ( V_1 , F_17 ( V_113 ) , V_68 ) ;
break;
#ifdef F_27
case F_29 ( V_114 ) :
if ( V_59 & V_89 )
F_8 ( V_1 , F_17 ( V_115 ) , V_68 ) ;
break;
#endif
case V_118 :
F_9 ( V_1 ) ;
break;
case V_119 :
F_15 ( V_1 , V_68 ) ;
break;
case V_120 :
case V_121 :
F_18 ( V_1 , V_68 ) ;
break;
#ifdef F_27
case V_122 :
F_19 ( V_1 , V_68 , 0 ) ;
break;
#endif
}
switch ( V_66 & ~ V_123 ) {
#ifdef F_30
case V_124 :
if ( V_59 & V_125 ) {
T_1 V_126 = V_65 & V_123 ;
F_22 ( V_1 , V_68 , V_126 ) ;
}
break;
break;
#endif
}
switch ( V_65 ) {
#ifdef F_27
case V_127 :
F_21 ( V_1 ) ;
break;
case V_128 :
F_19 ( V_1 , 0 , 1 ) ;
break;
#endif
}
}
static void F_31 ( void )
{
T_1 * V_17 ;
T_1 * V_129 , * V_130 ;
T_1 V_131 ;
T_1 V_59 ;
F_32 ( F_23 , & V_59 , 1 ) ;
if ( F_33 ( V_131 , ( T_1 * ) V_62 ) ) {
V_21 = false ;
return;
}
V_129 = ( void * ) V_132 ;
V_130 = ( void * ) V_133 ;
F_34 () ;
for ( V_17 = V_129 ; V_17 < V_130 ; V_17 ++ ) {
if ( V_17 >= V_134 && V_17 < V_135 ) {
V_17 = V_135 - 1 ;
continue;
}
F_25 ( V_17 , V_59 ) ;
}
F_35 () ;
F_14 ( V_136 L_2 ,
V_21 ? L_3 : L_4 ) ;
}
unsigned long F_24 ( unsigned long * V_60 ,
unsigned long * V_61 ,
unsigned long V_137 )
{
unsigned long register T_2 V_138 ( L_5 ) ;
unsigned long register T_3 V_138 ( L_6 ) = V_60 [ 0 ] ;
unsigned long register T_4 V_138 ( L_7 ) = V_60 [ 1 ] ;
unsigned long register T_5 V_138 ( L_8 ) = V_60 [ 2 ] ;
unsigned long register T_6 V_138 ( L_9 ) = V_60 [ 3 ] ;
unsigned long register T_7 V_138 ( L_10 ) = V_60 [ 4 ] ;
unsigned long register T_8 V_138 ( L_11 ) = V_60 [ 5 ] ;
unsigned long register T_9 V_138 ( L_12 ) = V_60 [ 6 ] ;
unsigned long register T_10 V_138 ( L_13 ) = V_60 [ 7 ] ;
unsigned long register T_11 V_138 ( L_14 ) = V_137 ;
unsigned long register T_12 V_138 ( L_15 ) ;
asm volatile("bl kvm_hypercall_start"
: "=r"(r0), "=r"(r3), "=r"(r4), "=r"(r5), "=r"(r6),
"=r"(r7), "=r"(r8), "=r"(r9), "=r"(r10), "=r"(r11),
"=r"(r12)
: "r"(r3), "r"(r4), "r"(r5), "r"(r6), "r"(r7), "r"(r8),
"r"(r9), "r"(r10), "r"(r11)
: "memory", "cc", "xer", "ctr", "lr");
V_61 [ 0 ] = T_4 ;
V_61 [ 1 ] = T_5 ;
V_61 [ 2 ] = T_6 ;
V_61 [ 3 ] = T_7 ;
V_61 [ 4 ] = T_8 ;
V_61 [ 5 ] = T_9 ;
V_61 [ 6 ] = T_10 ;
V_61 [ 7 ] = T_11 ;
return T_3 ;
}
static int F_36 ( void )
{
extern T_1 V_139 ;
struct V_140 * V_141 ;
T_1 * V_142 ;
int V_16 , V_143 ;
V_141 = F_37 ( L_16 ) ;
if ( ! V_141 )
return - 1 ;
V_142 = ( T_1 * ) F_38 ( V_141 , L_17 , & V_16 ) ;
if ( V_16 % 4 )
return - 1 ;
if ( V_16 > ( 4 * 4 ) )
return - 1 ;
for ( V_143 = 0 ; V_143 < ( V_16 / 4 ) ; V_143 ++ )
F_1 ( & ( & V_139 ) [ V_143 ] , V_142 [ V_143 ] ) ;
return 0 ;
}
static T_13 void F_39 ( void )
{
unsigned long V_129 , V_130 ;
V_129 = ( V_3 ) & V_19 [ V_18 + ( V_144 - 1 ) ] & V_145 ;
V_130 = ( V_3 ) & V_19 [ F_13 ( V_19 ) ] & V_145 ;
for (; V_129 < V_130 ; V_129 += V_144 ) {
F_40 ( F_41 ( V_129 ) ) ;
F_42 ( F_41 ( V_129 ) ) ;
F_43 ( V_129 ) ;
V_146 ++ ;
}
}
static int T_13 F_44 ( void )
{
if ( ! F_45 () )
goto V_147;
if ( F_36 () )
goto V_147;
if ( F_46 ( V_148 ) )
F_31 () ;
#ifdef F_47
V_149 = 1 ;
#endif
V_147:
F_39 () ;
return 0 ;
}
