static inline T_1 F_1 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r"(val));
return V_1 ;
}
static inline void F_2 ( T_1 V_1 )
{
V_1 &= V_2 ;
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 0" : : "r"(val));
}
static inline int F_4 ( T_1 V_3 )
{
return V_3 & V_4 ;
}
static inline int F_5 ( struct V_5 * V_6 , int V_7 )
{
return V_7 >= V_8 &&
V_7 <= F_6 ( V_6 ) ;
}
static inline int F_7 ( T_1 V_3 , int V_7 )
{
return V_3 & F_8 ( F_9 ( V_7 ) ) ;
}
static inline int F_10 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
F_3 () ;
return V_7 ;
}
static inline T_1 F_11 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
T_1 V_16 = 0 ;
if ( ! F_5 ( V_6 , V_7 ) )
F_13 ( L_1 ,
F_14 () , V_7 ) ;
else if ( V_7 == V_8 )
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
else if ( F_10 ( V_7 ) == V_7 )
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
return V_16 ;
}
static inline void F_15 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) )
F_13 ( L_2 ,
F_14 () , V_7 ) ;
else if ( V_7 == V_8 )
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
else if ( F_10 ( V_7 ) == V_7 )
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
static inline void F_16 ( int V_7 , T_1 V_1 )
{
if ( F_10 ( V_7 ) == V_7 ) {
V_1 &= V_17 ;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
}
static inline int F_17 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_18 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_19 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
return V_7 ;
}
static inline int F_20 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (BIT(counter)));
F_3 () ;
return V_7 ;
}
static inline T_1 F_21 ( void )
{
T_1 V_1 ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
V_1 &= V_18 ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (val));
return V_1 ;
}
static void F_22 ( struct V_5 * V_6 )
{
T_1 V_1 ;
unsigned int V_19 ;
F_23 ( V_20 L_3 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
F_23 ( V_20 L_4 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
F_23 ( V_20 L_5 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
F_23 ( V_20 L_6 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
F_23 ( V_20 L_7 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
F_23 ( V_20 L_8 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
F_23 ( V_20 L_9 , V_1 ) ;
for ( V_19 = V_21 ;
V_19 <= F_6 ( V_6 ) ; V_19 ++ ) {
F_10 ( V_19 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
F_23 ( V_20 L_10 ,
F_9 ( V_19 ) , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
F_23 ( V_20 L_11 ,
F_9 ( V_19 ) , V_1 ) ;
}
}
static void F_24 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_23 * V_24 = V_6 -> V_25 () ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_12 ,
F_14 () , V_7 ) ;
return;
}
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
if ( V_6 -> V_27 || V_7 != V_8 )
F_16 ( V_7 , V_14 -> V_28 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_23 * V_24 = V_6 -> V_25 () ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_13 ,
F_14 () , V_7 ) ;
return;
}
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static T_2 F_28 ( int V_29 , void * V_30 )
{
T_1 V_3 ;
struct V_31 V_32 ;
struct V_5 * V_6 = (struct V_5 * ) V_30 ;
struct V_23 * V_33 = V_6 -> V_25 () ;
struct V_34 * V_35 ;
int V_7 ;
V_3 = F_21 () ;
if ( ! F_4 ( V_3 ) )
return V_36 ;
V_35 = F_29 () ;
for ( V_7 = 0 ; V_7 < V_6 -> V_37 ; ++ V_7 ) {
struct V_10 * V_11 = V_33 -> V_24 [ V_7 ] ;
struct V_13 * V_14 ;
if ( ! V_11 )
continue;
if ( ! F_7 ( V_3 , V_7 ) )
continue;
V_14 = & V_11 -> V_15 ;
F_30 ( V_11 ) ;
F_31 ( & V_32 , 0 , V_14 -> V_38 ) ;
if ( ! F_32 ( V_11 ) )
continue;
if ( F_33 ( V_11 , & V_32 , V_35 ) )
V_6 -> V_39 ( V_11 ) ;
}
F_34 () ;
return V_40 ;
}
static void F_35 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_2 ( F_1 () | V_41 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
unsigned long V_22 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_2 ( F_1 () & ~ V_41 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static int F_37 ( struct V_23 * V_33 ,
struct V_10 * V_11 )
{
int V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned long V_42 = V_14 -> V_28 & V_43 ;
if ( V_42 == V_44 ) {
if ( F_38 ( V_8 , V_33 -> V_45 ) )
return - V_46 ;
return V_8 ;
}
for ( V_7 = V_21 ; V_7 < V_6 -> V_37 ; ++ V_7 ) {
if ( ! F_38 ( V_7 , V_33 -> V_45 ) )
return V_7 ;
}
return - V_46 ;
}
static int F_39 ( struct V_13 * V_11 ,
struct V_47 * V_48 )
{
unsigned long V_28 = 0 ;
if ( V_48 -> V_49 )
return - V_50 ;
if ( V_48 -> V_51 )
V_28 |= V_52 ;
if ( V_48 -> V_53 )
V_28 |= V_54 ;
if ( ! V_48 -> V_55 )
V_28 |= V_56 ;
V_11 -> V_28 = V_28 ;
return 0 ;
}
static void F_40 ( void * V_57 )
{
struct V_5 * V_6 = (struct V_5 * ) V_57 ;
T_1 V_7 , V_58 = V_6 -> V_37 ;
for ( V_7 = V_8 ; V_7 < V_58 ; ++ V_7 ) {
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
}
F_2 ( V_59 | V_60 ) ;
}
static int F_41 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_61 ,
& V_62 , 0xFF ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_63 ,
& V_64 , 0xFF ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_65 ,
& V_66 , 0xFF ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_67 ,
& V_68 , 0xFF ) ;
}
static int F_46 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_69 ,
& V_70 , 0xFF ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_71 ,
& V_72 , 0xFF ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_73 ,
& V_74 , 0xFFFFF ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
return F_42 ( V_11 , & V_75 ,
& V_74 , 0xFFFFF ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
V_6 -> V_76 = F_28 ;
V_6 -> V_77 = F_24 ;
V_6 -> V_39 = F_27 ;
V_6 -> V_78 = F_11 ;
V_6 -> V_79 = F_15 ;
V_6 -> V_80 = F_37 ;
V_6 -> V_81 = F_35 ;
V_6 -> V_82 = F_36 ;
V_6 -> V_83 = F_40 ;
V_6 -> V_84 = ( 1LLU << 32 ) - 1 ;
}
static T_1 F_51 ( void )
{
T_1 V_58 ;
V_58 = ( F_1 () >> V_85 ) & V_86 ;
return V_58 + 1 ;
}
static int F_52 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_14 ;
V_6 -> V_88 = F_41 ;
V_6 -> V_37 = F_51 () ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_15 ;
V_6 -> V_88 = F_43 ;
V_6 -> V_37 = F_51 () ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_16 ;
V_6 -> V_88 = F_44 ;
V_6 -> V_37 = F_51 () ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_17 ;
V_6 -> V_88 = F_45 ;
V_6 -> V_37 = F_51 () ;
V_6 -> V_27 = F_39 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_18 ;
V_6 -> V_88 = F_46 ;
V_6 -> V_37 = F_51 () ;
V_6 -> V_27 = F_39 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_19 ;
V_6 -> V_88 = F_47 ;
V_6 -> V_37 = F_51 () ;
V_6 -> V_27 = F_39 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
F_57 ( V_6 ) ;
V_6 -> V_87 = L_20 ;
return 0 ;
}
static T_1 F_59 ( int V_89 )
{
T_1 V_1 ;
switch ( V_89 ) {
case 0 :
asm volatile("mrc p15, 1, %0, c9, c15, 0" : "=r" (val));
break;
case 1 :
asm volatile("mrc p15, 1, %0, c9, c15, 1" : "=r" (val));
break;
case 2 :
asm volatile("mrc p15, 1, %0, c9, c15, 2" : "=r" (val));
break;
default:
F_60 () ;
}
return V_1 ;
}
static void F_61 ( int V_89 , T_1 V_1 )
{
switch ( V_89 ) {
case 0 :
asm volatile("mcr p15, 1, %0, c9, c15, 0" : : "r" (val));
break;
case 1 :
asm volatile("mcr p15, 1, %0, c9, c15, 1" : : "r" (val));
break;
case 2 :
asm volatile("mcr p15, 1, %0, c9, c15, 2" : : "r" (val));
break;
default:
F_60 () ;
}
}
static T_1 F_62 ( void )
{
T_1 V_1 ;
asm volatile("mrc p10, 7, %0, c11, c0, 0" : "=r" (val));
return V_1 ;
}
static void F_63 ( T_1 V_1 )
{
asm volatile("mcr p10, 7, %0, c11, c0, 0" : : "r" (val));
}
static void F_64 ( T_1 * V_90 , T_1 * V_91 )
{
T_1 V_92 ;
T_1 V_93 ;
F_65 ( F_66 () ) ;
* V_90 = F_67 () ;
V_92 = * V_90 | F_68 ( 10 ) | F_68 ( 11 ) ;
F_69 ( V_92 ) ;
* V_91 = F_70 ( V_94 ) ;
V_93 = * V_91 | V_95 ;
F_71 ( V_94 , V_93 ) ;
}
static void F_72 ( T_1 V_90 , T_1 V_91 )
{
F_65 ( F_66 () ) ;
F_71 ( V_94 , V_91 ) ;
F_3 () ;
F_69 ( V_90 ) ;
}
static T_1 F_73 ( unsigned int V_96 )
{
static const T_1 V_97 [] = { V_98 ,
V_99 ,
V_100 } ;
return V_97 [ V_96 ] ;
}
static void F_74 ( int V_7 , T_1 V_28 )
{
T_1 V_1 ;
T_1 V_101 ;
T_1 V_102 , V_103 ;
unsigned int V_96 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
bool V_107 ;
V_107 = ! ! ( V_28 & V_108 ) ;
V_96 = ( V_28 >> 12 ) & 0xf ;
V_105 = ( V_28 >> 4 ) & 0xff ;
V_104 = ( V_28 >> 0 ) & 0xf ;
V_106 = V_104 * 8 ;
V_101 = 0xff << V_106 ;
if ( V_107 )
V_1 = V_109 ;
else
V_1 = F_73 ( V_96 ) ;
V_1 += V_104 ;
V_1 |= V_28 & ( V_52 | V_54 ) ;
F_16 ( V_7 , V_1 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
if ( V_107 ) {
F_64 ( & V_102 , & V_103 ) ;
V_1 = F_62 () ;
V_1 &= ~ V_101 ;
V_1 |= V_105 << V_106 ;
V_1 |= V_110 ;
F_63 ( V_1 ) ;
F_72 ( V_102 , V_103 ) ;
} else {
V_1 = F_59 ( V_96 ) ;
V_1 &= ~ V_101 ;
V_1 |= V_105 << V_106 ;
V_1 |= V_110 ;
F_61 ( V_96 , V_1 ) ;
}
}
static T_1 F_75 ( T_1 V_1 , int V_104 )
{
T_1 V_101 ;
int V_106 ;
V_106 = V_104 * 8 ;
V_101 = 0xff << V_106 ;
V_1 &= ~ V_101 ;
if ( V_1 & ~ V_110 )
return V_1 |= V_110 ;
return 0 ;
}
static void F_76 ( T_1 V_28 )
{
T_1 V_1 ;
T_1 V_102 , V_103 ;
unsigned int V_96 ;
unsigned int V_104 ;
bool V_107 ;
V_107 = ! ! ( V_28 & V_108 ) ;
V_96 = ( V_28 >> 12 ) & 0xf ;
V_104 = ( V_28 >> 0 ) & 0xf ;
if ( V_107 ) {
F_64 ( & V_102 , & V_103 ) ;
V_1 = F_62 () ;
V_1 = F_75 ( V_1 , V_104 ) ;
F_63 ( V_1 ) ;
F_72 ( V_102 , V_103 ) ;
} else {
V_1 = F_59 ( V_96 ) ;
V_1 = F_75 ( V_1 , V_104 ) ;
F_61 ( V_96 , V_1 ) ;
}
}
static void F_77 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_28 & V_111 )
F_76 ( V_14 -> V_28 ) ;
F_20 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_78 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_23 * V_24 = V_6 -> V_25 () ;
F_25 ( & V_24 -> V_26 , V_22 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_28 & V_111 )
F_74 ( V_7 , V_14 -> V_28 ) ;
else
F_16 ( V_7 , V_14 -> V_28 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_26 ( & V_24 -> V_26 , V_22 ) ;
}
static void F_79 ( void * V_57 )
{
T_1 V_102 , V_103 ;
F_40 ( V_57 ) ;
F_61 ( 0 , 0 ) ;
F_61 ( 1 , 0 ) ;
F_61 ( 2 , 0 ) ;
F_64 ( & V_102 , & V_103 ) ;
F_63 ( 0 ) ;
F_72 ( V_102 , V_103 ) ;
}
static int F_80 ( struct V_10 * V_11 , unsigned int V_96 ,
unsigned int V_104 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
if ( V_14 -> V_28 & V_108 )
V_112 = V_109 ;
else
V_112 = F_73 ( V_96 ) ;
V_112 -= F_73 ( 0 ) ;
V_112 += V_104 ;
V_112 += F_6 ( V_6 ) + 1 ;
return V_112 ;
}
static int F_81 ( struct V_23 * V_33 ,
struct V_10 * V_11 )
{
int V_7 ;
int V_112 = - 1 ;
unsigned int V_113 ;
unsigned int V_96 ;
unsigned int V_105 ;
unsigned int V_104 ;
bool V_114 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
V_96 = ( V_14 -> V_28 >> 12 ) & 0xf ;
V_105 = ( V_14 -> V_28 >> 4 ) & 0xff ;
V_104 = ( V_14 -> V_28 >> 0 ) & 0xf ;
V_114 = ! ! ( V_14 -> V_28 & V_111 ) ;
if ( V_114 ) {
if ( V_104 > 3 || V_96 > 2 )
return - V_115 ;
V_113 = V_14 -> V_28 & V_111 ;
if ( V_113 != V_116 && V_113 != V_108 )
return - V_115 ;
if ( V_113 == V_108 && ( V_105 & 0xe0 ) )
return - V_115 ;
V_112 = F_80 ( V_11 , V_96 , V_104 ) ;
if ( F_38 ( V_112 , V_33 -> V_45 ) )
return - V_46 ;
}
V_7 = F_37 ( V_33 , V_11 ) ;
if ( V_7 < 0 && V_112 >= 0 )
F_82 ( V_112 , V_33 -> V_45 ) ;
return V_7 ;
}
static void F_83 ( struct V_23 * V_33 ,
struct V_10 * V_11 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_96 ;
unsigned int V_104 ;
bool V_114 ;
V_96 = ( V_14 -> V_28 >> 12 ) & 0xf ;
V_104 = ( V_14 -> V_28 >> 0 ) & 0xf ;
V_114 = ! ! ( V_14 -> V_28 & V_111 ) ;
if ( V_114 ) {
V_112 = F_80 ( V_11 , V_96 , V_104 ) ;
F_82 ( V_112 , V_33 -> V_45 ) ;
}
}
static int F_84 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
V_6 -> V_87 = L_21 ;
if ( F_85 ( V_6 -> V_117 -> V_30 . V_118 ,
L_22 ) )
V_6 -> V_88 = F_49 ;
else
V_6 -> V_88 = F_48 ;
V_6 -> V_37 = F_51 () ;
V_6 -> V_27 = F_39 ;
V_6 -> V_83 = F_79 ;
V_6 -> V_77 = F_78 ;
V_6 -> V_39 = F_77 ;
V_6 -> V_80 = F_81 ;
V_6 -> V_119 = F_83 ;
return 0 ;
}
static inline int F_52 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_53 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_54 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_55 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_56 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_57 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_58 ( struct V_5 * V_6 )
{
return - V_120 ;
}
static inline int F_84 ( struct V_5 * V_6 )
{
return - V_120 ;
}
