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
static inline void F_10 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 5" : : "r" (counter));
F_3 () ;
}
static inline T_1 F_11 ( struct V_10 * V_11 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
T_1 V_16 = 0 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_1 ,
F_14 () , V_7 ) ;
} else if ( V_7 == V_8 ) {
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (value));
} else {
F_10 ( V_7 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (value));
}
return V_16 ;
}
static inline void F_15 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_2 ,
F_14 () , V_7 ) ;
} else if ( V_7 == V_8 ) {
asm volatile("mcr p15, 0, %0, c9, c13, 0" : : "r" (value));
} else {
F_10 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c13, 2" : : "r" (value));
}
}
static inline void F_16 ( int V_7 , T_1 V_1 )
{
F_10 ( V_7 ) ;
V_1 &= V_17 ;
asm volatile("mcr p15, 0, %0, c9, c13, 1" : : "r" (val));
}
static inline void F_17 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 1" : : "r" (BIT(counter)));
}
static inline void F_18 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c12, 2" : : "r" (BIT(counter)));
}
static inline void F_19 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 1" : : "r" (BIT(counter)));
}
static inline void F_20 ( int V_7 )
{
T_1 V_9 = F_9 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c14, 2" : : "r" (BIT(counter)));
F_3 () ;
asm volatile("mcr p15, 0, %0, c9, c12, 3" : : "r" (BIT(counter)));
F_3 () ;
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
F_23 ( L_3 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 0" : "=r" (val));
F_23 ( L_4 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r" (val));
F_23 ( L_5 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c14, 1" : "=r" (val));
F_23 ( L_6 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 3" : "=r" (val));
F_23 ( L_7 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c12, 5" : "=r" (val));
F_23 ( L_8 , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r" (val));
F_23 ( L_9 , V_1 ) ;
for ( V_19 = V_20 ;
V_19 <= F_6 ( V_6 ) ; V_19 ++ ) {
F_10 ( V_19 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 2" : "=r" (val));
F_23 ( L_10 ,
F_9 ( V_19 ) , V_1 ) ;
asm volatile("mrc p15, 0, %0, c9, c13, 1" : "=r" (val));
F_23 ( L_11 ,
F_9 ( V_19 ) , V_1 ) ;
}
}
static void F_24 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_12 ,
F_14 () , V_7 ) ;
return;
}
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_6 -> V_26 || V_7 != V_8 )
F_16 ( V_7 , V_14 -> V_27 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_28 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
int V_7 = V_14 -> V_7 ;
if ( ! F_5 ( V_6 , V_7 ) ) {
F_13 ( L_13 ,
F_14 () , V_7 ) ;
return;
}
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static T_2 F_29 ( int V_28 , void * V_29 )
{
T_1 V_3 ;
struct V_30 V_31 ;
struct V_5 * V_6 = (struct V_5 * ) V_29 ;
struct V_22 * V_32 = F_25 ( V_6 -> V_24 ) ;
struct V_33 * V_34 ;
int V_7 ;
V_3 = F_21 () ;
if ( ! F_4 ( V_3 ) )
return V_35 ;
V_34 = F_30 () ;
for ( V_7 = 0 ; V_7 < V_6 -> V_36 ; ++ V_7 ) {
struct V_10 * V_11 = V_32 -> V_23 [ V_7 ] ;
struct V_13 * V_14 ;
if ( ! V_11 )
continue;
if ( ! F_7 ( V_3 , V_7 ) )
continue;
V_14 = & V_11 -> V_15 ;
F_31 ( V_11 ) ;
F_32 ( & V_31 , 0 , V_14 -> V_37 ) ;
if ( ! F_33 ( V_11 ) )
continue;
if ( F_34 ( V_11 , & V_31 , V_34 ) )
V_6 -> V_38 ( V_11 ) ;
}
F_35 () ;
return V_39 ;
}
static void F_36 ( struct V_5 * V_6 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_2 ( F_1 () | V_40 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
unsigned long V_21 ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_2 ( F_1 () & ~ V_40 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static int F_38 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned long V_41 = V_14 -> V_27 & V_42 ;
if ( V_41 == V_43 ) {
if ( F_39 ( V_8 , V_32 -> V_44 ) )
return - V_45 ;
return V_8 ;
}
for ( V_7 = V_20 ; V_7 < V_6 -> V_36 ; ++ V_7 ) {
if ( ! F_39 ( V_7 , V_32 -> V_44 ) )
return V_7 ;
}
return - V_45 ;
}
static int F_40 ( struct V_13 * V_11 ,
struct V_46 * V_47 )
{
unsigned long V_27 = 0 ;
if ( V_47 -> V_48 )
return - V_49 ;
if ( V_47 -> V_50 )
V_27 |= V_51 ;
if ( V_47 -> V_52 )
V_27 |= V_53 ;
if ( ! V_47 -> V_54 )
V_27 |= V_55 ;
V_11 -> V_27 = V_27 ;
return 0 ;
}
static void F_41 ( void * V_56 )
{
struct V_5 * V_6 = (struct V_5 * ) V_56 ;
T_1 V_7 , V_57 = V_6 -> V_36 ;
for ( V_7 = V_8 ; V_7 < V_57 ; ++ V_7 ) {
F_18 ( V_7 ) ;
F_20 ( V_7 ) ;
}
F_2 ( V_58 | V_59 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_60 ,
& V_61 , 0xFF ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_62 ,
& V_63 , 0xFF ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_64 ,
& V_65 , 0xFF ) ;
}
static int F_46 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_66 ,
& V_67 , 0xFF ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_68 ,
& V_69 , 0xFF ) ;
}
static int F_48 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_70 ,
& V_71 , 0xFF ) ;
}
static int F_49 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_72 ,
& V_73 , 0xFFFFF ) ;
}
static int F_50 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_74 ,
& V_73 , 0xFFFFF ) ;
}
static int F_51 ( struct V_10 * V_11 )
{
return F_43 ( V_11 , & V_75 ,
& V_76 , 0xFFFFF ) ;
}
static void F_52 ( struct V_5 * V_6 )
{
V_6 -> V_77 = F_29 ;
V_6 -> V_78 = F_24 ;
V_6 -> V_38 = F_28 ;
V_6 -> V_79 = F_11 ;
V_6 -> V_80 = F_15 ;
V_6 -> V_81 = F_38 ;
V_6 -> V_82 = F_36 ;
V_6 -> V_83 = F_37 ;
V_6 -> V_84 = F_41 ;
V_6 -> V_85 = ( 1LLU << 32 ) - 1 ;
}
static void F_53 ( void * V_56 )
{
int * V_57 = V_56 ;
* V_57 = ( F_1 () >> V_86 ) & V_87 ;
* V_57 += 1 ;
}
static int F_54 ( struct V_5 * V_5 )
{
return F_55 ( & V_5 -> V_88 ,
F_53 ,
& V_5 -> V_36 , 1 ) ;
}
static int F_56 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_14 ;
V_6 -> V_90 = F_42 ;
return F_54 ( V_6 ) ;
}
static int F_57 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_15 ;
V_6 -> V_90 = F_44 ;
return F_54 ( V_6 ) ;
}
static int F_58 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_16 ;
V_6 -> V_90 = F_45 ;
return F_54 ( V_6 ) ;
}
static int F_59 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_17 ;
V_6 -> V_90 = F_46 ;
V_6 -> V_26 = F_40 ;
return F_54 ( V_6 ) ;
}
static int F_60 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_18 ;
V_6 -> V_90 = F_47 ;
V_6 -> V_26 = F_40 ;
return F_54 ( V_6 ) ;
}
static int F_61 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_19 ;
V_6 -> V_90 = F_48 ;
V_6 -> V_26 = F_40 ;
return F_54 ( V_6 ) ;
}
static int F_62 ( struct V_5 * V_6 )
{
int V_91 = F_61 ( V_6 ) ;
V_6 -> V_89 = L_20 ;
return V_91 ;
}
static T_1 F_63 ( int V_92 )
{
T_1 V_1 ;
switch ( V_92 ) {
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
F_64 () ;
}
return V_1 ;
}
static void F_65 ( int V_92 , T_1 V_1 )
{
switch ( V_92 ) {
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
F_64 () ;
}
}
static T_1 F_66 ( void )
{
T_1 V_1 ;
asm volatile("mrc p10, 7, %0, c11, c0, 0" : "=r" (val));
return V_1 ;
}
static void F_67 ( T_1 V_1 )
{
asm volatile("mcr p10, 7, %0, c11, c0, 0" : : "r" (val));
}
static void F_68 ( T_1 * V_93 , T_1 * V_94 )
{
T_1 V_95 ;
T_1 V_96 ;
F_69 ( F_70 () ) ;
* V_93 = F_71 () ;
V_95 = * V_93 | F_72 ( 10 ) | F_72 ( 11 ) ;
F_73 ( V_95 ) ;
* V_94 = F_74 ( V_97 ) ;
V_96 = * V_94 | V_98 ;
F_75 ( V_97 , V_96 ) ;
}
static void F_76 ( T_1 V_93 , T_1 V_94 )
{
F_69 ( F_70 () ) ;
F_75 ( V_97 , V_94 ) ;
F_3 () ;
F_73 ( V_93 ) ;
}
static T_1 F_77 ( unsigned int V_99 )
{
static const T_1 V_100 [] = { V_101 ,
V_102 ,
V_103 } ;
return V_100 [ V_99 ] ;
}
static void F_78 ( int V_7 , T_1 V_27 )
{
T_1 V_1 ;
T_1 V_104 ;
T_1 V_105 , V_106 ;
unsigned int V_99 = F_79 ( V_27 ) ;
unsigned int V_107 = F_80 ( V_27 ) ;
unsigned int V_108 = F_81 ( V_27 ) ;
unsigned int V_109 ;
bool V_110 = F_82 ( V_27 ) ;
V_109 = V_107 * 8 ;
V_104 = 0xff << V_109 ;
if ( V_110 )
V_1 = V_111 ;
else
V_1 = F_77 ( V_99 ) ;
V_1 += V_107 ;
V_1 |= V_27 & ( V_51 | V_53 ) ;
F_16 ( V_7 , V_1 ) ;
if ( V_110 ) {
F_68 ( & V_105 , & V_106 ) ;
V_1 = F_66 () ;
V_1 &= ~ V_104 ;
V_1 |= V_108 << V_109 ;
V_1 |= V_112 ;
F_67 ( V_1 ) ;
F_76 ( V_105 , V_106 ) ;
} else {
V_1 = F_63 ( V_99 ) ;
V_1 &= ~ V_104 ;
V_1 |= V_108 << V_109 ;
V_1 |= V_112 ;
F_65 ( V_99 , V_1 ) ;
}
}
static T_1 F_83 ( T_1 V_1 , int V_107 )
{
T_1 V_104 ;
int V_109 ;
V_109 = V_107 * 8 ;
V_104 = 0xff << V_109 ;
V_1 &= ~ V_104 ;
if ( V_1 & ~ V_112 )
return V_1 |= V_112 ;
return 0 ;
}
static void F_84 ( T_1 V_27 )
{
T_1 V_1 ;
T_1 V_105 , V_106 ;
unsigned int V_99 = F_79 ( V_27 ) ;
unsigned int V_107 = F_80 ( V_27 ) ;
bool V_110 = F_82 ( V_27 ) ;
if ( V_110 ) {
F_68 ( & V_105 , & V_106 ) ;
V_1 = F_66 () ;
V_1 = F_83 ( V_1 , V_107 ) ;
F_67 ( V_1 ) ;
F_76 ( V_105 , V_106 ) ;
} else {
V_1 = F_63 ( V_99 ) ;
V_1 = F_83 ( V_1 , V_107 ) ;
F_65 ( V_99 , V_1 ) ;
}
}
static void F_85 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_113 )
F_84 ( V_14 -> V_27 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_86 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_113 )
F_78 ( V_7 , V_14 -> V_27 ) ;
else
F_16 ( V_7 , V_14 -> V_27 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_87 ( void * V_56 )
{
T_1 V_105 , V_106 ;
struct V_5 * V_6 = V_56 ;
T_1 V_7 , V_57 = V_6 -> V_36 ;
F_41 ( V_56 ) ;
F_65 ( 0 , 0 ) ;
F_65 ( 1 , 0 ) ;
F_65 ( 2 , 0 ) ;
F_68 ( & V_105 , & V_106 ) ;
F_67 ( 0 ) ;
F_76 ( V_105 , V_106 ) ;
for ( V_7 = V_8 ; V_7 < V_57 ; ++ V_7 ) {
F_10 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int F_88 ( struct V_10 * V_11 , unsigned int V_99 ,
unsigned int V_107 )
{
int V_114 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
if ( V_14 -> V_27 & V_115 )
V_114 = V_111 ;
else
V_114 = F_77 ( V_99 ) ;
V_114 -= F_77 ( 0 ) ;
V_114 += V_107 ;
V_114 += F_6 ( V_6 ) + 1 ;
return V_114 ;
}
static int F_89 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_7 ;
int V_114 = - 1 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_99 = F_79 ( V_14 -> V_27 ) ;
unsigned int V_108 = F_81 ( V_14 -> V_27 ) ;
unsigned int V_107 = F_80 ( V_14 -> V_27 ) ;
bool V_110 = F_82 ( V_14 -> V_27 ) ;
bool V_116 = F_90 ( V_14 -> V_27 ) ;
if ( V_110 || V_116 ) {
if ( V_107 > 3 || V_99 > 2 )
return - V_117 ;
if ( V_110 && ( V_108 & 0xe0 ) )
return - V_117 ;
V_114 = F_88 ( V_11 , V_99 , V_107 ) ;
if ( F_39 ( V_114 , V_32 -> V_44 ) )
return - V_45 ;
}
V_7 = F_38 ( V_32 , V_11 ) ;
if ( V_7 < 0 && V_114 >= 0 )
F_91 ( V_114 , V_32 -> V_44 ) ;
return V_7 ;
}
static void F_92 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_114 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_99 = F_79 ( V_14 -> V_27 ) ;
unsigned int V_107 = F_80 ( V_14 -> V_27 ) ;
bool V_110 = F_82 ( V_14 -> V_27 ) ;
bool V_116 = F_90 ( V_14 -> V_27 ) ;
if ( V_110 || V_116 ) {
V_114 = F_88 ( V_11 , V_99 , V_107 ) ;
F_91 ( V_114 , V_32 -> V_44 ) ;
}
}
static int F_93 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_21 ;
if ( F_94 ( V_6 -> V_118 -> V_29 . V_119 ,
L_22 ) )
V_6 -> V_90 = F_50 ;
else
V_6 -> V_90 = F_49 ;
V_6 -> V_26 = F_40 ;
V_6 -> V_84 = F_87 ;
V_6 -> V_78 = F_86 ;
V_6 -> V_38 = F_85 ;
V_6 -> V_81 = F_89 ;
V_6 -> V_120 = F_92 ;
return F_54 ( V_6 ) ;
}
static T_1 F_95 ( int V_92 )
{
T_1 V_1 ;
switch ( V_92 ) {
case 0 :
asm volatile("mrc p15, 0, %0, c15, c0, 0" : "=r" (val));
break;
case 1 :
asm volatile("mrc p15, 1, %0, c15, c0, 0" : "=r" (val));
break;
case 2 :
asm volatile("mrc p15, 2, %0, c15, c0, 0" : "=r" (val));
break;
case 3 :
asm volatile("mrc p15, 3, %0, c15, c2, 0" : "=r" (val));
break;
default:
F_64 () ;
}
return V_1 ;
}
static void F_96 ( int V_92 , T_1 V_1 )
{
switch ( V_92 ) {
case 0 :
asm volatile("mcr p15, 0, %0, c15, c0, 0" : : "r" (val));
break;
case 1 :
asm volatile("mcr p15, 1, %0, c15, c0, 0" : : "r" (val));
break;
case 2 :
asm volatile("mcr p15, 2, %0, c15, c0, 0" : : "r" (val));
break;
case 3 :
asm volatile("mcr p15, 3, %0, c15, c2, 0" : : "r" (val));
break;
default:
F_64 () ;
}
}
static T_1 F_97 ( unsigned int V_99 )
{
static const T_1 V_100 [] = { V_121 ,
V_122 ,
V_123 ,
V_124 } ;
return V_100 [ V_99 ] ;
}
static void F_98 ( int V_7 , T_1 V_27 )
{
T_1 V_1 ;
T_1 V_104 ;
T_1 V_105 , V_106 ;
unsigned int V_99 = F_79 ( V_27 ) ;
unsigned int V_107 = F_80 ( V_27 ) ;
unsigned int V_108 = F_81 ( V_27 ) ;
unsigned int V_109 ;
bool V_110 = F_82 ( V_27 ) ;
V_109 = V_107 * 8 ;
V_104 = 0xff << V_109 ;
if ( V_110 )
V_1 = V_125 ;
else
V_1 = F_97 ( V_99 ) ;
V_1 += V_107 ;
V_1 |= V_27 & ( V_51 | V_53 ) ;
F_16 ( V_7 , V_1 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
if ( V_110 ) {
F_68 ( & V_105 , & V_106 ) ;
V_1 = F_66 () ;
V_1 &= ~ V_104 ;
V_1 |= V_108 << V_109 ;
V_1 |= V_112 ;
F_67 ( V_1 ) ;
F_76 ( V_105 , V_106 ) ;
} else {
V_1 = F_95 ( V_99 ) ;
V_1 &= ~ V_104 ;
V_1 |= V_108 << V_109 ;
V_1 |= V_112 ;
F_96 ( V_99 , V_1 ) ;
}
}
static void F_99 ( T_1 V_27 )
{
T_1 V_1 ;
T_1 V_105 , V_106 ;
unsigned int V_99 = F_79 ( V_27 ) ;
unsigned int V_107 = F_80 ( V_27 ) ;
bool V_110 = F_82 ( V_27 ) ;
if ( V_110 ) {
F_68 ( & V_105 , & V_106 ) ;
V_1 = F_66 () ;
V_1 = F_83 ( V_1 , V_107 ) ;
F_67 ( V_1 ) ;
F_76 ( V_105 , V_106 ) ;
} else {
V_1 = F_95 ( V_99 ) ;
V_1 = F_83 ( V_1 , V_107 ) ;
F_96 ( V_99 , V_1 ) ;
}
}
static void F_100 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_113 )
F_99 ( V_14 -> V_27 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_101 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_113 )
F_98 ( V_7 , V_14 -> V_27 ) ;
else if ( V_7 != V_8 )
F_16 ( V_7 , V_14 -> V_27 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_102 ( void * V_56 )
{
T_1 V_105 , V_106 ;
struct V_5 * V_6 = V_56 ;
T_1 V_7 , V_57 = V_6 -> V_36 ;
F_41 ( V_56 ) ;
F_96 ( 0 , 0 ) ;
F_96 ( 1 , 0 ) ;
F_96 ( 2 , 0 ) ;
F_96 ( 3 , 0 ) ;
F_68 ( & V_105 , & V_106 ) ;
F_67 ( 0 ) ;
F_76 ( V_105 , V_106 ) ;
for ( V_7 = V_8 ; V_7 < V_57 ; ++ V_7 ) {
F_10 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int F_103 ( struct V_10 * V_11 , unsigned int V_99 ,
unsigned int V_107 )
{
int V_114 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
if ( V_14 -> V_27 & V_115 )
V_114 = V_125 ;
else
V_114 = F_97 ( V_99 ) ;
V_114 -= F_97 ( 0 ) ;
V_114 += V_107 ;
V_114 += F_6 ( V_6 ) + 1 ;
return V_114 ;
}
static int F_104 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_7 ;
int V_114 = - 1 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_99 = F_79 ( V_14 -> V_27 ) ;
unsigned int V_107 = F_80 ( V_14 -> V_27 ) ;
bool V_110 = F_82 ( V_14 -> V_27 ) ;
bool V_126 = F_90 ( V_14 -> V_27 ) ;
if ( V_110 || V_126 ) {
if ( V_107 > 3 || V_99 > 3 )
return - V_117 ;
V_114 = F_103 ( V_11 , V_99 , V_107 ) ;
if ( F_39 ( V_114 , V_32 -> V_44 ) )
return - V_45 ;
}
V_7 = F_38 ( V_32 , V_11 ) ;
if ( V_7 < 0 && V_114 >= 0 )
F_91 ( V_114 , V_32 -> V_44 ) ;
return V_7 ;
}
static void F_105 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_114 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_99 = F_79 ( V_14 -> V_27 ) ;
unsigned int V_107 = F_80 ( V_14 -> V_27 ) ;
bool V_110 = F_82 ( V_14 -> V_27 ) ;
bool V_126 = F_90 ( V_14 -> V_27 ) ;
if ( V_110 || V_126 ) {
V_114 = F_103 ( V_11 , V_99 , V_107 ) ;
F_91 ( V_114 , V_32 -> V_44 ) ;
}
}
static int F_106 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_23 ;
V_6 -> V_90 = F_51 ;
V_6 -> V_84 = F_102 ;
V_6 -> V_78 = F_101 ;
V_6 -> V_38 = F_100 ;
V_6 -> V_81 = F_104 ;
V_6 -> V_120 = F_105 ;
return F_54 ( V_6 ) ;
}
static int F_107 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_89 = L_24 ;
V_6 -> V_90 = F_51 ;
V_6 -> V_84 = F_102 ;
V_6 -> V_78 = F_101 ;
V_6 -> V_38 = F_100 ;
V_6 -> V_81 = F_104 ;
V_6 -> V_120 = F_105 ;
return F_54 ( V_6 ) ;
}
static int F_108 ( struct V_127 * V_128 )
{
return F_109 ( V_128 , V_129 ,
V_130 ) ;
}
static int T_3 F_110 ( void )
{
return F_111 ( & V_131 ) ;
}
