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
extern T_1 V_13 ;
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
static void F_19 ( T_1 * V_1 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_40 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_41 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_42 , V_40 * 4 ) ;
V_17 [ V_41 ] |= V_23 & V_15 ;
V_17 [ V_43 ] |= ( * V_1 & V_44 ) ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_40 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_20 ( T_1 * V_1 , T_1 V_5 , T_1 V_45 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_46 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_47 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_48 , V_46 * 4 ) ;
V_17 [ V_47 ] |= V_23 & V_15 ;
V_17 [ V_49 ] |= ( V_45 << 10 ) ;
V_17 [ V_50 ] |= V_5 ;
V_17 [ V_51 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_46 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_21 ( void * V_52 )
{
T_1 * V_53 = V_52 ;
V_3 V_54 [ 8 ] ;
V_3 V_55 [ 8 ] ;
V_54 [ 0 ] = V_56 ;
V_54 [ 1 ] = V_56 ;
F_22 ( V_54 , V_55 , V_57 | V_58 ) ;
* V_53 = V_55 [ 0 ] ;
}
static void F_23 ( T_1 * V_1 , T_1 V_53 )
{
T_1 V_59 = * V_1 ;
T_1 V_60 = V_59 & ~ V_61 ;
T_1 V_62 = V_59 & V_61 ;
switch ( V_60 ) {
case V_63 :
F_5 ( V_1 , F_17 ( V_64 ) , V_62 ) ;
break;
case V_65 :
F_5 ( V_1 , F_17 ( V_66 ) , V_62 ) ;
break;
case V_67 :
F_5 ( V_1 , F_17 ( V_68 ) , V_62 ) ;
break;
case V_69 :
F_5 ( V_1 , F_17 ( V_70 ) , V_62 ) ;
break;
case V_71 :
F_5 ( V_1 , F_17 ( V_72 ) , V_62 ) ;
break;
case V_73 :
F_5 ( V_1 , F_17 ( V_74 ) , V_62 ) ;
break;
case V_75 :
F_5 ( V_1 , F_17 ( V_76 ) , V_62 ) ;
break;
case V_77 :
F_5 ( V_1 , F_17 ( V_78 ) , V_62 ) ;
break;
case V_79 :
F_6 ( V_1 , F_17 ( V_80 ) , V_62 ) ;
break;
case V_81 :
F_7 ( V_1 , F_17 ( V_66 ) , V_62 ) ;
break;
case V_82 :
F_7 ( V_1 , F_17 ( V_68 ) , V_62 ) ;
break;
case V_83 :
F_7 ( V_1 , F_17 ( V_70 ) , V_62 ) ;
break;
case V_84 :
F_7 ( V_1 , F_17 ( V_72 ) , V_62 ) ;
break;
case V_85 :
F_7 ( V_1 , F_17 ( V_74 ) , V_62 ) ;
break;
case V_86 :
F_7 ( V_1 , F_17 ( V_76 ) , V_62 ) ;
break;
case V_87 :
F_7 ( V_1 , F_17 ( V_78 ) , V_62 ) ;
break;
case V_88 :
F_8 ( V_1 , F_17 ( V_80 ) , V_62 ) ;
break;
case V_89 :
F_9 ( V_1 ) ;
break;
case V_90 :
F_15 ( V_1 , V_62 ) ;
break;
case V_91 :
case V_92 :
F_18 ( V_1 , V_62 ) ;
break;
}
switch ( V_60 & ~ V_93 ) {
#ifdef F_24
case V_94 :
if ( V_53 & V_95 ) {
T_1 V_96 = V_59 & V_93 ;
F_20 ( V_1 , V_62 , V_96 ) ;
}
break;
break;
#endif
}
switch ( V_59 ) {
#ifdef F_25
case V_97 :
case V_98 :
F_19 ( V_1 ) ;
break;
#endif
}
}
static void F_26 ( void )
{
T_1 * V_17 ;
T_1 * V_99 , * V_100 ;
T_1 V_101 ;
T_1 V_53 ;
F_27 ( F_21 , & V_53 , 1 ) ;
if ( F_28 ( V_101 , ( T_1 * ) V_56 ) ) {
V_21 = false ;
return;
}
V_99 = ( void * ) V_102 ;
V_100 = ( void * ) V_103 ;
for ( V_17 = V_99 ; V_17 < V_100 ; V_17 ++ )
F_23 ( V_17 , V_53 ) ;
F_14 ( V_104 L_2 ,
V_21 ? L_3 : L_4 ) ;
}
unsigned long F_22 ( unsigned long * V_54 ,
unsigned long * V_55 ,
unsigned long V_105 )
{
unsigned long register T_2 V_106 ( L_5 ) ;
unsigned long register T_3 V_106 ( L_6 ) = V_54 [ 0 ] ;
unsigned long register T_4 V_106 ( L_7 ) = V_54 [ 1 ] ;
unsigned long register T_5 V_106 ( L_8 ) = V_54 [ 2 ] ;
unsigned long register T_6 V_106 ( L_9 ) = V_54 [ 3 ] ;
unsigned long register T_7 V_106 ( L_10 ) = V_54 [ 4 ] ;
unsigned long register T_8 V_106 ( L_11 ) = V_54 [ 5 ] ;
unsigned long register T_9 V_106 ( L_12 ) = V_54 [ 6 ] ;
unsigned long register T_10 V_106 ( L_13 ) = V_54 [ 7 ] ;
unsigned long register T_11 V_106 ( L_14 ) = V_105 ;
unsigned long register T_12 V_106 ( L_15 ) ;
asm volatile("bl kvm_hypercall_start"
: "=r"(r0), "=r"(r3), "=r"(r4), "=r"(r5), "=r"(r6),
"=r"(r7), "=r"(r8), "=r"(r9), "=r"(r10), "=r"(r11),
"=r"(r12)
: "r"(r3), "r"(r4), "r"(r5), "r"(r6), "r"(r7), "r"(r8),
"r"(r9), "r"(r10), "r"(r11)
: "memory", "cc", "xer", "ctr", "lr");
V_55 [ 0 ] = T_4 ;
V_55 [ 1 ] = T_5 ;
V_55 [ 2 ] = T_6 ;
V_55 [ 3 ] = T_7 ;
V_55 [ 4 ] = T_8 ;
V_55 [ 5 ] = T_9 ;
V_55 [ 6 ] = T_10 ;
V_55 [ 7 ] = T_11 ;
return T_3 ;
}
static int F_29 ( void )
{
extern T_1 V_107 ;
struct V_108 * V_109 ;
T_1 * V_110 ;
int V_16 , V_111 ;
V_109 = F_30 ( L_16 ) ;
if ( ! V_109 )
return - 1 ;
V_110 = ( T_1 * ) F_31 ( V_109 , L_17 , & V_16 ) ;
if ( V_16 % 4 )
return - 1 ;
if ( V_16 > ( 4 * 4 ) )
return - 1 ;
for ( V_111 = 0 ; V_111 < ( V_16 / 4 ) ; V_111 ++ )
F_1 ( & ( & V_107 ) [ V_111 ] , V_110 [ V_111 ] ) ;
return 0 ;
}
static T_13 void F_32 ( void )
{
unsigned long V_99 , V_100 ;
V_99 = ( V_3 ) & V_19 [ V_18 + ( V_112 - 1 ) ] & V_113 ;
V_100 = ( V_3 ) & V_19 [ F_13 ( V_19 ) ] & V_113 ;
for (; V_99 < V_100 ; V_99 += V_112 ) {
F_33 ( F_34 ( V_99 ) ) ;
F_35 ( F_34 ( V_99 ) ) ;
F_36 ( V_99 ) ;
V_114 ++ ;
}
}
static int T_13 F_37 ( void )
{
if ( ! F_38 () )
goto V_115;
if ( F_29 () )
goto V_115;
if ( F_39 ( V_116 ) )
F_26 () ;
#ifdef F_40
V_117 = 1 ;
#endif
V_115:
F_32 () ;
return 0 ;
}
