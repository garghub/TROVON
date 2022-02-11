static T_1 int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( F_2 ( F_3 () ) )
if ( F_4 ( V_2 , V_3 ) == 1 )
return - 1 ;
return 0 ;
}
static T_1 int F_5 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( F_6 () && ! F_7 ( V_2 ) ) {
F_8 () ;
if ( F_9 () && F_10 ( V_2 , 14 ) )
V_4 = 1 ;
F_11 () ;
}
return V_4 ;
}
static inline int
F_12 ( struct V_1 * V_2 , unsigned char * V_5 ,
unsigned char V_6 , int * V_7 )
{
unsigned char V_8 = V_6 & 0xf0 ;
unsigned char V_9 = V_6 & 0x0f ;
switch ( V_8 ) {
case 0x20 :
case 0x30 :
return ( ( V_9 & 7 ) == 0x6 ) ;
#ifdef F_13
case 0x40 :
return ( ! F_7 ( V_2 ) || F_14 ( V_2 ) ) ;
#endif
case 0x60 :
return ( V_9 & 0xC ) == 0x4 ;
case 0xF0 :
return ! V_9 || ( V_9 >> 1 ) == 1 ;
case 0x00 :
if ( F_15 ( V_5 , V_6 ) )
return 0 ;
* V_7 = ( V_9 == 0xF ) &&
( V_6 == 0x0D || V_6 == 0x18 ) ;
return 0 ;
default:
return 0 ;
}
}
static int
F_16 ( struct V_1 * V_2 , unsigned long V_10 , unsigned long V_3 )
{
unsigned char * V_11 ;
unsigned char * V_5 ;
int V_7 = 0 ;
if ( V_10 & V_12 )
return 0 ;
V_5 = ( void * ) F_17 ( V_13 , V_2 ) ;
V_11 = V_5 + 15 ;
if ( F_7 ( V_2 ) && V_5 >= ( unsigned char * ) V_14 )
return 0 ;
while ( V_5 < V_11 ) {
unsigned char V_6 ;
if ( F_15 ( V_5 , V_6 ) )
break;
V_5 ++ ;
if ( ! F_12 ( V_2 , V_5 , V_6 , & V_7 ) )
break;
}
return V_7 ;
}
static void F_18 ( int V_15 , T_2 * V_16 ,
struct V_17 * V_18 )
{
if ( ! F_19 ( V_19 ) )
return;
if ( V_15 != V_20 )
return;
if ( ! V_18 ) {
F_20 ( 1 , L_1 ) ;
V_16 -> V_21 = 0 ;
return;
}
V_16 -> V_21 = F_21 ( V_18 ) ;
}
static void
F_22 ( int V_22 , int V_15 , unsigned long V_23 ,
struct V_24 * V_25 , struct V_17 * V_18 ,
int V_26 )
{
unsigned V_27 = 0 ;
T_2 V_16 ;
V_16 . V_22 = V_22 ;
V_16 . V_28 = 0 ;
V_16 . V_15 = V_15 ;
V_16 . V_29 = ( void V_30 * ) V_23 ;
if ( V_26 & V_31 )
V_27 = F_23 ( F_24 ( V_26 ) ) ;
if ( V_26 & V_32 )
V_27 = V_33 ;
V_16 . V_34 = V_27 ;
F_18 ( V_15 , & V_16 , V_18 ) ;
F_25 ( V_22 , & V_16 , V_25 ) ;
}
static inline T_3 * F_26 ( T_4 * V_35 , unsigned long V_23 )
{
unsigned V_36 = F_27 ( V_23 ) ;
T_4 * V_37 ;
T_5 * V_38 , * V_39 ;
T_6 * V_40 , * V_41 ;
T_3 * V_42 , * V_43 ;
V_35 += V_36 ;
V_37 = V_44 . V_35 + V_36 ;
if ( ! F_28 ( * V_37 ) )
return NULL ;
V_38 = F_29 ( V_35 , V_23 ) ;
V_39 = F_29 ( V_37 , V_23 ) ;
if ( ! F_30 ( * V_39 ) )
return NULL ;
V_40 = F_31 ( V_38 , V_23 ) ;
V_41 = F_31 ( V_39 , V_23 ) ;
if ( ! F_32 ( * V_41 ) )
return NULL ;
V_42 = F_33 ( V_40 , V_23 ) ;
V_43 = F_33 ( V_41 , V_23 ) ;
if ( ! F_34 ( * V_43 ) )
return NULL ;
if ( ! F_34 ( * V_42 ) )
F_35 ( V_42 , * V_43 ) ;
else
F_36 ( F_37 ( * V_42 ) != F_37 ( * V_43 ) ) ;
return V_43 ;
}
void F_38 ( void )
{
unsigned long V_23 ;
if ( V_45 )
return;
for ( V_23 = V_46 & V_47 ;
V_23 >= V_14 && V_23 < V_48 ;
V_23 += V_49 ) {
struct V_50 * V_50 ;
F_39 ( & V_51 ) ;
F_40 (page, &pgd_list, lru) {
T_7 * V_52 ;
T_3 * V_4 ;
V_52 = & F_41 ( V_50 ) -> V_53 ;
F_39 ( V_52 ) ;
V_4 = F_26 ( F_42 ( V_50 ) , V_23 ) ;
F_43 ( V_52 ) ;
if ( ! V_4 )
break;
}
F_43 ( & V_51 ) ;
}
}
static T_8 int F_44 ( unsigned long V_23 )
{
unsigned long V_54 ;
T_3 * V_43 ;
T_9 * V_55 ;
if ( ! ( V_23 >= V_46 && V_23 < V_56 ) )
return - 1 ;
F_45 ( F_46 () ) ;
V_54 = F_47 () ;
V_43 = F_26 ( F_48 ( V_54 ) , V_23 ) ;
if ( ! V_43 )
return - 1 ;
if ( F_49 ( * V_43 ) )
return 0 ;
V_55 = F_50 ( V_43 , V_23 ) ;
if ( ! F_51 ( * V_55 ) )
return - 1 ;
return 0 ;
}
static inline void
F_52 ( struct V_1 * V_2 , unsigned long V_23 ,
struct V_24 * V_25 )
{
#ifdef F_53
unsigned long V_57 ;
if ( ! F_54 ( V_2 ) || ! V_25 -> V_58 . V_59 )
return;
V_57 = ( V_23 - 0xA0000 ) >> V_33 ;
if ( V_57 < 32 )
V_25 -> V_58 . V_59 -> V_60 |= 1 << V_57 ;
#endif
}
static bool F_55 ( unsigned long V_61 )
{
return V_61 < V_62 ;
}
static void F_56 ( unsigned long V_23 )
{
T_4 * V_63 = F_48 ( F_47 () ) ;
T_4 * V_35 = & V_63 [ F_27 ( V_23 ) ] ;
T_5 * V_38 ;
T_6 * V_40 ;
T_3 * V_42 ;
T_9 * V_64 ;
#ifdef F_57
F_58 ( L_2 , F_59 ( * V_35 ) ) ;
if ( ! F_55 ( F_59 ( * V_35 ) >> V_33 ) || ! F_28 ( * V_35 ) )
goto V_65;
#endif
V_38 = F_29 ( V_35 , V_23 ) ;
V_40 = F_31 ( V_38 , V_23 ) ;
V_42 = F_33 ( V_40 , V_23 ) ;
F_58 ( V_66 L_3 , sizeof( * V_42 ) * 2 , ( V_67 ) F_60 ( * V_42 ) ) ;
if ( ! F_55 ( F_61 ( * V_42 ) ) || ! F_34 ( * V_42 ) || F_62 ( * V_42 ) )
goto V_65;
V_64 = F_50 ( V_42 , V_23 ) ;
F_58 ( L_4 , sizeof( * V_64 ) * 2 , ( V_67 ) F_63 ( * V_64 ) ) ;
V_65:
F_58 ( L_5 ) ;
}
void F_38 ( void )
{
F_64 ( V_46 & V_68 , V_56 ) ;
}
static T_8 int F_44 ( unsigned long V_23 )
{
T_4 * V_35 , * V_69 ;
T_5 * V_38 , * V_70 ;
T_6 * V_40 , * V_71 ;
T_3 * V_42 , * V_72 ;
T_9 * V_64 , * V_73 ;
if ( ! ( V_23 >= V_46 && V_23 < V_56 ) )
return - 1 ;
F_45 ( F_46 () ) ;
V_35 = ( T_4 * ) F_48 ( F_47 () ) + F_27 ( V_23 ) ;
V_69 = F_65 ( V_23 ) ;
if ( F_66 ( * V_69 ) )
return - 1 ;
if ( F_66 ( * V_35 ) ) {
F_67 ( V_35 , * V_69 ) ;
F_68 () ;
} else if ( V_74 > 4 ) {
F_36 ( F_69 ( * V_35 ) != F_69 ( * V_69 ) ) ;
}
V_38 = F_29 ( V_35 , V_23 ) ;
V_70 = F_29 ( V_69 , V_23 ) ;
if ( F_70 ( * V_70 ) )
return - 1 ;
if ( F_70 ( * V_38 ) ) {
F_71 ( V_38 , * V_70 ) ;
F_68 () ;
} else {
F_36 ( F_72 ( * V_38 ) != F_72 ( * V_70 ) ) ;
}
V_40 = F_31 ( V_38 , V_23 ) ;
V_71 = F_31 ( V_70 , V_23 ) ;
if ( F_73 ( * V_71 ) )
return - 1 ;
if ( F_73 ( * V_40 ) || F_74 ( * V_40 ) != F_74 ( * V_71 ) )
F_75 () ;
if ( F_76 ( * V_40 ) )
return 0 ;
V_42 = F_33 ( V_40 , V_23 ) ;
V_72 = F_33 ( V_71 , V_23 ) ;
if ( F_77 ( * V_72 ) )
return - 1 ;
if ( F_77 ( * V_42 ) || F_61 ( * V_42 ) != F_61 ( * V_72 ) )
F_75 () ;
if ( F_49 ( * V_42 ) )
return 0 ;
V_73 = F_50 ( V_72 , V_23 ) ;
if ( ! F_51 ( * V_73 ) )
return - 1 ;
V_64 = F_50 ( V_42 , V_23 ) ;
if ( ! F_51 ( * V_64 ) || F_78 ( * V_64 ) != F_78 ( * V_73 ) )
F_75 () ;
return 0 ;
}
static inline void
F_52 ( struct V_1 * V_2 , unsigned long V_23 ,
struct V_24 * V_25 )
{
}
static int F_79 ( void * V_75 )
{
unsigned long V_76 ;
return F_15 ( ( unsigned long * ) V_75 , V_76 ) ;
}
static void F_56 ( unsigned long V_23 )
{
T_4 * V_63 = F_48 ( F_47 () ) ;
T_4 * V_35 = V_63 + F_27 ( V_23 ) ;
T_5 * V_38 ;
T_6 * V_40 ;
T_3 * V_42 ;
T_9 * V_64 ;
if ( F_79 ( V_35 ) )
goto V_77;
F_58 ( L_6 , F_59 ( * V_35 ) ) ;
if ( ! F_28 ( * V_35 ) )
goto V_65;
V_38 = F_29 ( V_35 , V_23 ) ;
if ( F_79 ( V_38 ) )
goto V_77;
F_58 ( L_7 , F_80 ( * V_38 ) ) ;
if ( ! F_30 ( * V_38 ) || F_81 ( * V_38 ) )
goto V_65;
V_40 = F_31 ( V_38 , V_23 ) ;
if ( F_79 ( V_40 ) )
goto V_77;
F_58 ( L_8 , F_82 ( * V_40 ) ) ;
if ( ! F_32 ( * V_40 ) || F_83 ( * V_40 ) )
goto V_65;
V_42 = F_33 ( V_40 , V_23 ) ;
if ( F_79 ( V_42 ) )
goto V_77;
F_58 ( L_9 , F_60 ( * V_42 ) ) ;
if ( ! F_34 ( * V_42 ) || F_62 ( * V_42 ) )
goto V_65;
V_64 = F_50 ( V_42 , V_23 ) ;
if ( F_79 ( V_64 ) )
goto V_77;
F_58 ( L_10 , F_63 ( * V_64 ) ) ;
V_65:
F_58 ( L_5 ) ;
return;
V_77:
F_58 ( L_11 ) ;
}
static int F_84 ( struct V_1 * V_2 , unsigned long V_23 )
{
#if F_85 ( F_13 ) && F_85 ( V_78 )
if ( V_79 . V_80 != V_81
|| V_79 . V_82 != 0xf )
return 0 ;
if ( V_23 != V_2 -> V_83 )
return 0 ;
if ( ( V_23 >> 32 ) != 0 )
return 0 ;
V_23 |= 0xffffffffUL << 32 ;
if ( ( V_23 >= ( V_67 ) V_84 && V_23 <= ( V_67 ) V_85 ) ||
( V_23 >= V_86 && V_23 <= V_87 ) ) {
F_86 ( V_88 ) ;
V_2 -> V_83 = V_23 ;
return 1 ;
}
#endif
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , unsigned long V_23 )
{
#ifdef F_13
if ( ( V_2 -> V_89 == V_90 || ( V_2 -> V_89 & ( 1 << 2 ) ) ) && ( V_23 >> 32 ) )
return 1 ;
#endif
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , unsigned long V_23 )
{
#ifdef F_89
unsigned long V_91 ;
if ( F_90 ( V_92 ) ) {
V_91 = ( V_23 - V_93 . V_23 ) >> 3 ;
if ( V_91 == 6 ) {
F_91 ( V_2 , 0 ) ;
return 1 ;
}
}
#endif
return 0 ;
}
static void
F_92 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 )
{
if ( ! F_93 () )
return;
if ( V_10 & V_12 ) {
unsigned int V_94 ;
T_4 * V_35 ;
T_9 * V_64 ;
V_35 = F_48 ( F_47 () ) ;
V_35 += F_27 ( V_23 ) ;
V_64 = F_94 ( V_35 , V_23 , & V_94 ) ;
if ( V_64 && F_51 ( * V_64 ) && ! F_95 ( * V_64 ) )
F_58 ( V_95 , F_96 ( & V_96 , F_97 () ) ) ;
if ( V_64 && F_51 ( * V_64 ) && F_95 ( * V_64 ) &&
( F_98 ( * V_35 ) & V_97 ) &&
( F_99 () & V_98 ) )
F_58 ( V_99 , F_96 ( & V_96 , F_97 () ) ) ;
}
F_58 ( V_100 L_12 ) ;
if ( V_23 < V_101 )
F_58 ( V_66 L_13 ) ;
else
F_58 ( V_66 L_14 ) ;
F_58 ( V_66 L_15 , ( void * ) V_23 ) ;
F_58 ( V_100 L_16 , ( void * ) V_2 -> V_83 ) ;
F_56 ( V_23 ) ;
}
static T_8 void
F_100 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 )
{
struct V_24 * V_25 ;
unsigned long V_102 ;
int V_103 ;
V_102 = F_101 () ;
V_25 = V_13 ;
V_103 = V_104 ;
F_58 ( V_100 L_17 ,
V_25 -> V_105 , V_23 ) ;
F_56 ( V_23 ) ;
V_25 -> V_58 . V_106 = V_23 ;
V_25 -> V_58 . V_107 = V_108 ;
V_25 -> V_58 . V_10 = V_10 ;
if ( F_102 ( L_18 , V_2 , V_10 ) )
V_103 = 0 ;
F_103 ( V_102 , V_2 , V_103 ) ;
}
static T_8 void
F_104 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , int signal , int V_15 )
{
struct V_24 * V_25 = V_13 ;
unsigned long V_102 ;
int V_103 ;
struct V_17 * V_18 = NULL ;
if ( F_105 ( V_2 , V_108 ) ) {
if ( F_106 () )
return;
if ( V_13 -> V_58 . V_109 && signal ) {
V_25 -> V_58 . V_107 = V_108 ;
V_25 -> V_58 . V_10 = V_10 | V_110 ;
V_25 -> V_58 . V_106 = V_23 ;
F_22 ( signal , V_15 , V_23 ,
V_25 , V_18 , 0 ) ;
}
return;
}
#ifdef F_107
if ( F_108 ( ( void * ) V_23 ) &&
( ( ( unsigned long ) V_25 -> V_111 - 1 - V_23 < V_101 ) ||
V_23 - ( ( unsigned long ) V_25 -> V_111 + V_112 ) < V_101 ) ) {
register void * T_10 V_113 ( L_19 ) ;
unsigned long V_111 = F_109 ( V_114 . V_115 [ V_116 ] ) - sizeof( void * ) ;
asm volatile ("movq %[stack], %%rsp\n\t"
"call handle_stack_overflow\n\t"
"1: jmp 1b"
: "+r" (__sp)
: "D" ("kernel stack overflow (page fault)"),
"S" (regs), "d" (address),
[stack] "rm" (stack));
F_110 () ;
}
#endif
if ( F_16 ( V_2 , V_10 , V_23 ) )
return;
if ( F_84 ( V_2 , V_23 ) )
return;
V_102 = F_101 () ;
F_92 ( V_2 , V_10 , V_23 ) ;
if ( F_111 ( V_25 ) )
F_58 ( V_117 L_20 ) ;
V_25 -> V_58 . V_106 = V_23 ;
V_25 -> V_58 . V_107 = V_108 ;
V_25 -> V_58 . V_10 = V_10 ;
V_103 = V_104 ;
if ( F_102 ( L_21 , V_2 , V_10 ) )
V_103 = 0 ;
F_58 ( V_118 L_22 , V_23 ) ;
F_103 ( V_102 , V_2 , V_103 ) ;
}
static inline void
F_112 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_24 * V_25 )
{
if ( ! F_113 ( V_25 , V_119 ) )
return;
if ( ! F_114 () )
return;
F_58 ( L_23 ,
F_115 ( V_25 ) > 1 ? V_120 : V_117 ,
V_25 -> V_105 , F_115 ( V_25 ) , V_23 ,
( void * ) V_2 -> V_83 , ( void * ) V_2 -> V_121 , V_10 ) ;
F_116 ( V_66 L_24 , V_2 -> V_83 ) ;
F_58 ( V_66 L_5 ) ;
}
static void
F_117 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_17 * V_18 ,
int V_15 )
{
struct V_24 * V_25 = V_13 ;
if ( V_10 & V_110 ) {
F_118 () ;
if ( F_16 ( V_2 , V_10 , V_23 ) )
return;
if ( F_87 ( V_2 , V_23 ) )
return;
#ifdef F_13
if ( F_2 ( ( V_10 & V_12 ) &&
( ( V_23 & ~ 0xfff ) == V_122 ) ) ) {
if ( F_119 ( V_2 , V_23 ) )
return;
}
#endif
if ( V_23 >= V_14 )
V_10 |= V_123 ;
if ( F_120 ( V_124 ) )
F_112 ( V_2 , V_10 , V_23 , V_25 ) ;
V_25 -> V_58 . V_106 = V_23 ;
V_25 -> V_58 . V_10 = V_10 ;
V_25 -> V_58 . V_107 = V_108 ;
F_22 ( V_119 , V_15 , V_23 , V_25 , V_18 , 0 ) ;
return;
}
if ( F_88 ( V_2 , V_23 ) )
return;
F_104 ( V_2 , V_10 , V_23 , V_119 , V_15 ) ;
}
static T_8 void
F_121 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_17 * V_18 )
{
F_117 ( V_2 , V_10 , V_23 , V_18 , V_125 ) ;
}
static void
F_122 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_17 * V_18 , int V_15 )
{
struct V_126 * V_127 = V_13 -> V_127 ;
F_123 ( & V_127 -> V_128 ) ;
F_117 ( V_2 , V_10 , V_23 , V_18 , V_15 ) ;
}
static T_8 void
F_124 ( struct V_1 * V_2 , unsigned long V_10 , unsigned long V_23 )
{
F_122 ( V_2 , V_10 , V_23 , NULL , V_125 ) ;
}
static inline bool F_125 ( unsigned long V_10 ,
struct V_17 * V_18 )
{
bool V_129 = false ;
if ( ! F_19 ( V_19 ) )
return false ;
if ( V_10 & V_130 )
return true ;
if ( ! F_126 ( V_18 , ( V_10 & V_131 ) ,
( V_10 & V_12 ) , V_129 ) )
return true ;
return false ;
}
static T_8 void
F_127 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_17 * V_18 )
{
if ( F_125 ( V_10 , V_18 ) )
F_122 ( V_2 , V_10 , V_23 , V_18 , V_20 ) ;
else
F_122 ( V_2 , V_10 , V_23 , V_18 , V_132 ) ;
}
static void
F_128 ( struct V_1 * V_2 , unsigned long V_10 , unsigned long V_23 ,
struct V_17 * V_18 , unsigned int V_26 )
{
struct V_24 * V_25 = V_13 ;
int V_133 = V_134 ;
if ( ! ( V_10 & V_110 ) ) {
F_104 ( V_2 , V_10 , V_23 , V_135 , V_134 ) ;
return;
}
if ( F_16 ( V_2 , V_10 , V_23 ) )
return;
V_25 -> V_58 . V_106 = V_23 ;
V_25 -> V_58 . V_10 = V_10 ;
V_25 -> V_58 . V_107 = V_108 ;
#ifdef F_129
if ( V_26 & ( V_32 | V_31 ) ) {
F_58 ( V_136
L_25 ,
V_25 -> V_105 , V_25 -> V_137 , V_23 ) ;
V_133 = V_138 ;
}
#endif
F_22 ( V_135 , V_133 , V_23 , V_25 , V_18 , V_26 ) ;
}
static T_8 void
F_130 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 , struct V_17 * V_18 ,
unsigned int V_26 )
{
if ( F_131 ( V_13 ) && ! ( V_10 & V_110 ) ) {
F_104 ( V_2 , V_10 , V_23 , 0 , 0 ) ;
return;
}
if ( V_26 & V_139 ) {
if ( ! ( V_10 & V_110 ) ) {
F_104 ( V_2 , V_10 , V_23 ,
V_119 , V_125 ) ;
return;
}
F_132 () ;
} else {
if ( V_26 & ( V_140 | V_32 |
V_31 ) )
F_128 ( V_2 , V_10 , V_23 , V_18 , V_26 ) ;
else if ( V_26 & V_141 )
F_121 ( V_2 , V_10 , V_23 , V_18 ) ;
else
F_75 () ;
}
}
static int F_133 ( unsigned long V_10 , T_9 * V_64 )
{
if ( ( V_10 & V_131 ) && ! F_134 ( * V_64 ) )
return 0 ;
if ( ( V_10 & V_12 ) && ! F_95 ( * V_64 ) )
return 0 ;
if ( ( V_10 & V_130 ) )
return 1 ;
return 1 ;
}
static T_8 int
F_135 ( unsigned long V_10 , unsigned long V_23 )
{
T_4 * V_35 ;
T_5 * V_38 ;
T_6 * V_40 ;
T_3 * V_42 ;
T_9 * V_64 ;
int V_4 ;
if ( V_10 != ( V_131 | V_123 )
&& V_10 != ( V_12 | V_123 ) )
return 0 ;
V_35 = V_44 . V_35 + F_27 ( V_23 ) ;
if ( ! F_28 ( * V_35 ) )
return 0 ;
V_38 = F_29 ( V_35 , V_23 ) ;
if ( ! F_30 ( * V_38 ) )
return 0 ;
if ( F_81 ( * V_38 ) )
return F_133 ( V_10 , ( T_9 * ) V_38 ) ;
V_40 = F_31 ( V_38 , V_23 ) ;
if ( ! F_32 ( * V_40 ) )
return 0 ;
if ( F_83 ( * V_40 ) )
return F_133 ( V_10 , ( T_9 * ) V_40 ) ;
V_42 = F_33 ( V_40 , V_23 ) ;
if ( ! F_34 ( * V_42 ) )
return 0 ;
if ( F_62 ( * V_42 ) )
return F_133 ( V_10 , ( T_9 * ) V_42 ) ;
V_64 = F_50 ( V_42 , V_23 ) ;
if ( ! F_51 ( * V_64 ) )
return 0 ;
V_4 = F_133 ( V_10 , V_64 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_133 ( V_10 , ( T_9 * ) V_42 ) ;
F_20 ( ! V_4 , L_26 ) ;
return V_4 ;
}
static inline int
F_136 ( unsigned long V_10 , struct V_17 * V_18 )
{
bool V_129 = false ;
if ( V_10 & V_130 )
return 1 ;
if ( ! F_126 ( V_18 , ( V_10 & V_131 ) ,
( V_10 & V_12 ) , V_129 ) )
return 1 ;
if ( V_10 & V_131 ) {
if ( F_2 ( ! ( V_18 -> V_142 & V_143 ) ) )
return 1 ;
return 0 ;
}
if ( F_2 ( V_10 & V_123 ) )
return 1 ;
if ( F_2 ( ! ( V_18 -> V_142 & ( V_144 | V_145 | V_143 ) ) ) )
return 1 ;
return 0 ;
}
static int F_137 ( unsigned long V_23 )
{
return V_23 >= V_14 ;
}
static inline bool F_138 ( int V_10 , struct V_1 * V_2 )
{
if ( ! F_139 ( V_146 ) )
return false ;
if ( ! F_140 ( V_147 ) )
return false ;
if ( V_10 & V_110 )
return false ;
if ( ! F_7 ( V_2 ) && ( V_2 -> V_102 & V_148 ) )
return false ;
return true ;
}
static T_8 void
F_141 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_23 )
{
struct V_17 * V_18 ;
struct V_24 * V_25 ;
struct V_126 * V_127 ;
int V_26 , V_149 = 0 ;
unsigned int V_102 = V_150 | V_151 ;
V_25 = V_13 ;
V_127 = V_25 -> V_127 ;
if ( F_142 ( V_2 ) )
F_143 ( V_2 ) ;
F_144 ( & V_127 -> V_128 ) ;
if ( F_2 ( F_1 ( V_2 , V_23 ) ) )
return;
if ( F_2 ( F_137 ( V_23 ) ) ) {
if ( ! ( V_10 & ( V_152 | V_110 | V_123 ) ) ) {
if ( F_44 ( V_23 ) >= 0 )
return;
if ( F_145 ( V_2 , V_23 , V_10 ) )
return;
}
if ( F_135 ( V_10 , V_23 ) )
return;
if ( F_5 ( V_2 ) )
return;
F_121 ( V_2 , V_10 , V_23 , NULL ) ;
return;
}
if ( F_2 ( F_5 ( V_2 ) ) )
return;
if ( F_2 ( V_10 & V_152 ) )
F_100 ( V_2 , V_10 , V_23 ) ;
if ( F_2 ( F_138 ( V_10 , V_2 ) ) ) {
F_121 ( V_2 , V_10 , V_23 , NULL ) ;
return;
}
if ( F_2 ( F_146 () || ! V_127 ) ) {
F_121 ( V_2 , V_10 , V_23 , NULL ) ;
return;
}
if ( F_7 ( V_2 ) ) {
F_118 () ;
V_10 |= V_110 ;
V_102 |= V_153 ;
} else {
if ( V_2 -> V_102 & V_154 )
F_118 () ;
}
F_147 ( V_155 , 1 , V_2 , V_23 ) ;
if ( V_10 & V_131 )
V_102 |= V_156 ;
if ( V_10 & V_12 )
V_102 |= V_157 ;
if ( F_2 ( ! F_148 ( & V_127 -> V_128 ) ) ) {
if ( ( V_10 & V_110 ) == 0 &&
! F_149 ( V_2 -> V_83 ) ) {
F_121 ( V_2 , V_10 , V_23 , NULL ) ;
return;
}
V_158:
F_150 ( & V_127 -> V_128 ) ;
} else {
F_151 () ;
}
V_18 = F_152 ( V_127 , V_23 ) ;
if ( F_2 ( ! V_18 ) ) {
F_124 ( V_2 , V_10 , V_23 ) ;
return;
}
if ( F_120 ( V_18 -> V_159 <= V_23 ) )
goto V_160;
if ( F_2 ( ! ( V_18 -> V_142 & V_161 ) ) ) {
F_124 ( V_2 , V_10 , V_23 ) ;
return;
}
if ( V_10 & V_110 ) {
if ( F_2 ( V_23 + 65536 + 32 * sizeof( unsigned long ) < V_2 -> V_121 ) ) {
F_124 ( V_2 , V_10 , V_23 ) ;
return;
}
}
if ( F_2 ( F_153 ( V_18 , V_23 ) ) ) {
F_124 ( V_2 , V_10 , V_23 ) ;
return;
}
V_160:
if ( F_2 ( F_136 ( V_10 , V_18 ) ) ) {
F_127 ( V_2 , V_10 , V_23 , V_18 ) ;
return;
}
V_26 = F_154 ( V_18 , V_23 , V_102 ) ;
V_149 |= V_26 & V_162 ;
if ( F_2 ( V_26 & V_163 ) ) {
if ( V_102 & V_150 ) {
V_102 &= ~ V_150 ;
V_102 |= V_164 ;
if ( ! F_131 ( V_25 ) )
goto V_158;
}
if ( V_102 & V_153 )
return;
F_104 ( V_2 , V_10 , V_23 , V_135 , V_134 ) ;
return;
}
F_123 ( & V_127 -> V_128 ) ;
if ( F_2 ( V_26 & V_165 ) ) {
F_130 ( V_2 , V_10 , V_23 , V_18 , V_26 ) ;
return;
}
if ( V_149 ) {
V_25 -> V_166 ++ ;
F_147 ( V_167 , 1 , V_2 , V_23 ) ;
} else {
V_25 -> V_168 ++ ;
F_147 ( V_169 , 1 , V_2 , V_23 ) ;
}
F_52 ( V_2 , V_23 , V_25 ) ;
}
T_11 void T_12
F_155 ( struct V_1 * V_2 , unsigned long V_10 )
{
unsigned long V_23 = F_156 () ;
enum V_170 V_171 ;
V_171 = F_157 () ;
F_141 ( V_2 , V_10 , V_23 ) ;
F_158 ( V_171 ) ;
}
static T_1 void
F_159 ( unsigned long V_23 , struct V_1 * V_2 ,
unsigned long V_10 )
{
if ( F_7 ( V_2 ) )
F_160 ( V_23 , V_2 , V_10 ) ;
else
F_161 ( V_23 , V_2 , V_10 ) ;
}
T_11 void T_12
F_162 ( struct V_1 * V_2 , unsigned long V_10 )
{
unsigned long V_23 = F_156 () ;
enum V_170 V_171 ;
V_171 = F_157 () ;
F_159 ( V_23 , V_2 , V_10 ) ;
F_141 ( V_2 , V_10 , V_23 ) ;
F_158 ( V_171 ) ;
}
