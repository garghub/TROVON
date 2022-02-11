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
static T_1 F_53 ( void )
{
T_1 V_57 ;
V_57 = ( F_1 () >> V_86 ) & V_87 ;
return V_57 + 1 ;
}
static int F_54 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_14 ;
V_6 -> V_89 = F_42 ;
V_6 -> V_36 = F_53 () ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_15 ;
V_6 -> V_89 = F_44 ;
V_6 -> V_36 = F_53 () ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_16 ;
V_6 -> V_89 = F_45 ;
V_6 -> V_36 = F_53 () ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_17 ;
V_6 -> V_89 = F_46 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_26 = F_40 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_18 ;
V_6 -> V_89 = F_47 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_26 = F_40 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_19 ;
V_6 -> V_89 = F_48 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_26 = F_40 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
F_59 ( V_6 ) ;
V_6 -> V_88 = L_20 ;
return 0 ;
}
static T_1 F_61 ( int V_90 )
{
T_1 V_1 ;
switch ( V_90 ) {
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
F_62 () ;
}
return V_1 ;
}
static void F_63 ( int V_90 , T_1 V_1 )
{
switch ( V_90 ) {
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
F_62 () ;
}
}
static T_1 F_64 ( void )
{
T_1 V_1 ;
asm volatile("mrc p10, 7, %0, c11, c0, 0" : "=r" (val));
return V_1 ;
}
static void F_65 ( T_1 V_1 )
{
asm volatile("mcr p10, 7, %0, c11, c0, 0" : : "r" (val));
}
static void F_66 ( T_1 * V_91 , T_1 * V_92 )
{
T_1 V_93 ;
T_1 V_94 ;
F_67 ( F_68 () ) ;
* V_91 = F_69 () ;
V_93 = * V_91 | F_70 ( 10 ) | F_70 ( 11 ) ;
F_71 ( V_93 ) ;
* V_92 = F_72 ( V_95 ) ;
V_94 = * V_92 | V_96 ;
F_73 ( V_95 , V_94 ) ;
}
static void F_74 ( T_1 V_91 , T_1 V_92 )
{
F_67 ( F_68 () ) ;
F_73 ( V_95 , V_92 ) ;
F_3 () ;
F_71 ( V_91 ) ;
}
static T_1 F_75 ( unsigned int V_97 )
{
static const T_1 V_98 [] = { V_99 ,
V_100 ,
V_101 } ;
return V_98 [ V_97 ] ;
}
static void F_76 ( int V_7 , T_1 V_27 )
{
T_1 V_1 ;
T_1 V_102 ;
T_1 V_103 , V_104 ;
unsigned int V_97 = F_77 ( V_27 ) ;
unsigned int V_105 = F_78 ( V_27 ) ;
unsigned int V_106 = F_79 ( V_27 ) ;
unsigned int V_107 ;
bool V_108 = F_80 ( V_27 ) ;
V_107 = V_105 * 8 ;
V_102 = 0xff << V_107 ;
if ( V_108 )
V_1 = V_109 ;
else
V_1 = F_75 ( V_97 ) ;
V_1 += V_105 ;
V_1 |= V_27 & ( V_51 | V_53 ) ;
F_16 ( V_7 , V_1 ) ;
if ( V_108 ) {
F_66 ( & V_103 , & V_104 ) ;
V_1 = F_64 () ;
V_1 &= ~ V_102 ;
V_1 |= V_106 << V_107 ;
V_1 |= V_110 ;
F_65 ( V_1 ) ;
F_74 ( V_103 , V_104 ) ;
} else {
V_1 = F_61 ( V_97 ) ;
V_1 &= ~ V_102 ;
V_1 |= V_106 << V_107 ;
V_1 |= V_110 ;
F_63 ( V_97 , V_1 ) ;
}
}
static T_1 F_81 ( T_1 V_1 , int V_105 )
{
T_1 V_102 ;
int V_107 ;
V_107 = V_105 * 8 ;
V_102 = 0xff << V_107 ;
V_1 &= ~ V_102 ;
if ( V_1 & ~ V_110 )
return V_1 |= V_110 ;
return 0 ;
}
static void F_82 ( T_1 V_27 )
{
T_1 V_1 ;
T_1 V_103 , V_104 ;
unsigned int V_97 = F_77 ( V_27 ) ;
unsigned int V_105 = F_78 ( V_27 ) ;
bool V_108 = F_80 ( V_27 ) ;
if ( V_108 ) {
F_66 ( & V_103 , & V_104 ) ;
V_1 = F_64 () ;
V_1 = F_81 ( V_1 , V_105 ) ;
F_65 ( V_1 ) ;
F_74 ( V_103 , V_104 ) ;
} else {
V_1 = F_61 ( V_97 ) ;
V_1 = F_81 ( V_1 , V_105 ) ;
F_63 ( V_97 , V_1 ) ;
}
}
static void F_83 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_111 )
F_82 ( V_14 -> V_27 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_84 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_111 )
F_76 ( V_7 , V_14 -> V_27 ) ;
else
F_16 ( V_7 , V_14 -> V_27 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_85 ( void * V_56 )
{
T_1 V_103 , V_104 ;
struct V_5 * V_6 = V_56 ;
T_1 V_7 , V_57 = V_6 -> V_36 ;
F_41 ( V_56 ) ;
F_63 ( 0 , 0 ) ;
F_63 ( 1 , 0 ) ;
F_63 ( 2 , 0 ) ;
F_66 ( & V_103 , & V_104 ) ;
F_65 ( 0 ) ;
F_74 ( V_103 , V_104 ) ;
for ( V_7 = V_8 ; V_7 < V_57 ; ++ V_7 ) {
F_10 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int F_86 ( struct V_10 * V_11 , unsigned int V_97 ,
unsigned int V_105 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
if ( V_14 -> V_27 & V_113 )
V_112 = V_109 ;
else
V_112 = F_75 ( V_97 ) ;
V_112 -= F_75 ( 0 ) ;
V_112 += V_105 ;
V_112 += F_6 ( V_6 ) + 1 ;
return V_112 ;
}
static int F_87 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_7 ;
int V_112 = - 1 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_97 = F_77 ( V_14 -> V_27 ) ;
unsigned int V_106 = F_79 ( V_14 -> V_27 ) ;
unsigned int V_105 = F_78 ( V_14 -> V_27 ) ;
bool V_108 = F_80 ( V_14 -> V_27 ) ;
bool V_114 = F_88 ( V_14 -> V_27 ) ;
if ( V_108 || V_114 ) {
if ( V_105 > 3 || V_97 > 2 )
return - V_115 ;
if ( V_108 && ( V_106 & 0xe0 ) )
return - V_115 ;
V_112 = F_86 ( V_11 , V_97 , V_105 ) ;
if ( F_39 ( V_112 , V_32 -> V_44 ) )
return - V_45 ;
}
V_7 = F_38 ( V_32 , V_11 ) ;
if ( V_7 < 0 && V_112 >= 0 )
F_89 ( V_112 , V_32 -> V_44 ) ;
return V_7 ;
}
static void F_90 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_97 = F_77 ( V_14 -> V_27 ) ;
unsigned int V_105 = F_78 ( V_14 -> V_27 ) ;
bool V_108 = F_80 ( V_14 -> V_27 ) ;
bool V_114 = F_88 ( V_14 -> V_27 ) ;
if ( V_108 || V_114 ) {
V_112 = F_86 ( V_11 , V_97 , V_105 ) ;
F_89 ( V_112 , V_32 -> V_44 ) ;
}
}
static int F_91 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_21 ;
if ( F_92 ( V_6 -> V_116 -> V_29 . V_117 ,
L_22 ) )
V_6 -> V_89 = F_50 ;
else
V_6 -> V_89 = F_49 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_26 = F_40 ;
V_6 -> V_84 = F_85 ;
V_6 -> V_78 = F_84 ;
V_6 -> V_38 = F_83 ;
V_6 -> V_81 = F_87 ;
V_6 -> V_118 = F_90 ;
return 0 ;
}
static T_1 F_93 ( int V_90 )
{
T_1 V_1 ;
switch ( V_90 ) {
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
F_62 () ;
}
return V_1 ;
}
static void F_94 ( int V_90 , T_1 V_1 )
{
switch ( V_90 ) {
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
F_62 () ;
}
}
static T_1 F_95 ( unsigned int V_97 )
{
static const T_1 V_98 [] = { V_119 ,
V_120 ,
V_121 ,
V_122 } ;
return V_98 [ V_97 ] ;
}
static void F_96 ( int V_7 , T_1 V_27 )
{
T_1 V_1 ;
T_1 V_102 ;
T_1 V_103 , V_104 ;
unsigned int V_97 = F_77 ( V_27 ) ;
unsigned int V_105 = F_78 ( V_27 ) ;
unsigned int V_106 = F_79 ( V_27 ) ;
unsigned int V_107 ;
bool V_108 = F_80 ( V_27 ) ;
V_107 = V_105 * 8 ;
V_102 = 0xff << V_107 ;
if ( V_108 )
V_1 = V_123 ;
else
V_1 = F_95 ( V_97 ) ;
V_1 += V_105 ;
V_1 |= V_27 & ( V_51 | V_53 ) ;
F_16 ( V_7 , V_1 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
if ( V_108 ) {
F_66 ( & V_103 , & V_104 ) ;
V_1 = F_64 () ;
V_1 &= ~ V_102 ;
V_1 |= V_106 << V_107 ;
V_1 |= V_110 ;
F_65 ( V_1 ) ;
F_74 ( V_103 , V_104 ) ;
} else {
V_1 = F_93 ( V_97 ) ;
V_1 &= ~ V_102 ;
V_1 |= V_106 << V_107 ;
V_1 |= V_110 ;
F_94 ( V_97 , V_1 ) ;
}
}
static void F_97 ( T_1 V_27 )
{
T_1 V_1 ;
T_1 V_103 , V_104 ;
unsigned int V_97 = F_77 ( V_27 ) ;
unsigned int V_105 = F_78 ( V_27 ) ;
bool V_108 = F_80 ( V_27 ) ;
if ( V_108 ) {
F_66 ( & V_103 , & V_104 ) ;
V_1 = F_64 () ;
V_1 = F_81 ( V_1 , V_105 ) ;
F_65 ( V_1 ) ;
F_74 ( V_103 , V_104 ) ;
} else {
V_1 = F_93 ( V_97 ) ;
V_1 = F_81 ( V_1 , V_105 ) ;
F_94 ( V_97 , V_1 ) ;
}
}
static void F_98 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_111 )
F_97 ( V_14 -> V_27 ) ;
F_20 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_99 ( struct V_10 * V_11 )
{
unsigned long V_21 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
int V_7 = V_14 -> V_7 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
struct V_22 * V_23 = F_25 ( V_6 -> V_24 ) ;
F_26 ( & V_23 -> V_25 , V_21 ) ;
F_18 ( V_7 ) ;
if ( V_14 -> V_27 & V_111 )
F_96 ( V_7 , V_14 -> V_27 ) ;
else if ( V_7 != V_8 )
F_16 ( V_7 , V_14 -> V_27 ) ;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
F_27 ( & V_23 -> V_25 , V_21 ) ;
}
static void F_100 ( void * V_56 )
{
T_1 V_103 , V_104 ;
struct V_5 * V_6 = V_56 ;
T_1 V_7 , V_57 = V_6 -> V_36 ;
F_41 ( V_56 ) ;
F_94 ( 0 , 0 ) ;
F_94 ( 1 , 0 ) ;
F_94 ( 2 , 0 ) ;
F_94 ( 3 , 0 ) ;
F_66 ( & V_103 , & V_104 ) ;
F_65 ( 0 ) ;
F_74 ( V_103 , V_104 ) ;
for ( V_7 = V_8 ; V_7 < V_57 ; ++ V_7 ) {
F_10 ( V_7 ) ;
asm volatile("mcr p15, 0, %0, c9, c15, 0" : : "r" (0));
}
}
static int F_101 ( struct V_10 * V_11 , unsigned int V_97 ,
unsigned int V_105 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_11 -> V_12 ) ;
if ( V_14 -> V_27 & V_113 )
V_112 = V_123 ;
else
V_112 = F_95 ( V_97 ) ;
V_112 -= F_95 ( 0 ) ;
V_112 += V_105 ;
V_112 += F_6 ( V_6 ) + 1 ;
return V_112 ;
}
static int F_102 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_7 ;
int V_112 = - 1 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_97 = F_77 ( V_14 -> V_27 ) ;
unsigned int V_105 = F_78 ( V_14 -> V_27 ) ;
bool V_108 = F_80 ( V_14 -> V_27 ) ;
bool V_124 = F_88 ( V_14 -> V_27 ) ;
if ( V_108 || V_124 ) {
if ( V_105 > 3 || V_97 > 3 )
return - V_115 ;
V_112 = F_101 ( V_11 , V_97 , V_105 ) ;
if ( F_39 ( V_112 , V_32 -> V_44 ) )
return - V_45 ;
}
V_7 = F_38 ( V_32 , V_11 ) ;
if ( V_7 < 0 && V_112 >= 0 )
F_89 ( V_112 , V_32 -> V_44 ) ;
return V_7 ;
}
static void F_103 ( struct V_22 * V_32 ,
struct V_10 * V_11 )
{
int V_112 ;
struct V_13 * V_14 = & V_11 -> V_15 ;
unsigned int V_97 = F_77 ( V_14 -> V_27 ) ;
unsigned int V_105 = F_78 ( V_14 -> V_27 ) ;
bool V_108 = F_80 ( V_14 -> V_27 ) ;
bool V_124 = F_88 ( V_14 -> V_27 ) ;
if ( V_108 || V_124 ) {
V_112 = F_101 ( V_11 , V_97 , V_105 ) ;
F_89 ( V_112 , V_32 -> V_44 ) ;
}
}
static int F_104 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_23 ;
V_6 -> V_89 = F_51 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_84 = F_100 ;
V_6 -> V_78 = F_99 ;
V_6 -> V_38 = F_98 ;
V_6 -> V_81 = F_102 ;
V_6 -> V_118 = F_103 ;
return 0 ;
}
static int F_105 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
V_6 -> V_88 = L_24 ;
V_6 -> V_89 = F_51 ;
V_6 -> V_36 = F_53 () ;
V_6 -> V_84 = F_100 ;
V_6 -> V_78 = F_99 ;
V_6 -> V_38 = F_98 ;
V_6 -> V_81 = F_102 ;
V_6 -> V_118 = F_103 ;
return 0 ;
}
static inline int F_54 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_55 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_56 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_57 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_58 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_59 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_60 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_91 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_104 ( struct V_5 * V_6 )
{
return - V_125 ;
}
static inline int F_105 ( struct V_5 * V_6 )
{
return - V_125 ;
}
