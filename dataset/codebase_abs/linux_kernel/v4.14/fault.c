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
static void F_18 ( int V_15 , T_2 * V_16 , T_3 * V_17 )
{
if ( ! F_19 ( V_18 ) )
return;
if ( V_15 != V_19 )
return;
if ( ! V_17 ) {
F_20 ( 1 , L_1 ) ;
V_16 -> V_20 = 0 ;
return;
}
V_16 -> V_20 = * V_17 ;
}
static void
F_21 ( int V_21 , int V_15 , unsigned long V_22 ,
struct V_23 * V_24 , T_3 * V_17 , int V_25 )
{
unsigned V_26 = 0 ;
T_2 V_16 ;
V_16 . V_21 = V_21 ;
V_16 . V_27 = 0 ;
V_16 . V_15 = V_15 ;
V_16 . V_28 = ( void V_29 * ) V_22 ;
if ( V_25 & V_30 )
V_26 = F_22 ( F_23 ( V_25 ) ) ;
if ( V_25 & V_31 )
V_26 = V_32 ;
V_16 . V_33 = V_26 ;
F_18 ( V_15 , & V_16 , V_17 ) ;
F_24 ( V_21 , & V_16 , V_24 ) ;
}
static inline T_4 * F_25 ( T_5 * V_34 , unsigned long V_22 )
{
unsigned V_35 = F_26 ( V_22 ) ;
T_5 * V_36 ;
T_6 * V_37 , * V_38 ;
T_7 * V_39 , * V_40 ;
T_4 * V_41 , * V_42 ;
V_34 += V_35 ;
V_36 = V_43 . V_34 + V_35 ;
if ( ! F_27 ( * V_36 ) )
return NULL ;
V_37 = F_28 ( V_34 , V_22 ) ;
V_38 = F_28 ( V_36 , V_22 ) ;
if ( ! F_29 ( * V_38 ) )
return NULL ;
V_39 = F_30 ( V_37 , V_22 ) ;
V_40 = F_30 ( V_38 , V_22 ) ;
if ( ! F_31 ( * V_40 ) )
return NULL ;
V_41 = F_32 ( V_39 , V_22 ) ;
V_42 = F_32 ( V_40 , V_22 ) ;
if ( ! F_33 ( * V_42 ) )
return NULL ;
if ( ! F_33 ( * V_41 ) )
F_34 ( V_41 , * V_42 ) ;
else
F_35 ( F_36 ( * V_41 ) != F_36 ( * V_42 ) ) ;
return V_42 ;
}
void F_37 ( void )
{
unsigned long V_22 ;
if ( V_44 )
return;
for ( V_22 = V_45 & V_46 ;
V_22 >= V_14 && V_22 < V_47 ;
V_22 += V_48 ) {
struct V_49 * V_49 ;
F_38 ( & V_50 ) ;
F_39 (page, &pgd_list, lru) {
T_8 * V_51 ;
T_4 * V_4 ;
V_51 = & F_40 ( V_49 ) -> V_52 ;
F_38 ( V_51 ) ;
V_4 = F_25 ( F_41 ( V_49 ) , V_22 ) ;
F_42 ( V_51 ) ;
if ( ! V_4 )
break;
}
F_42 ( & V_50 ) ;
}
}
static T_9 int F_43 ( unsigned long V_22 )
{
unsigned long V_53 ;
T_4 * V_42 ;
T_10 * V_54 ;
if ( ! ( V_22 >= V_45 && V_22 < V_55 ) )
return - 1 ;
F_44 ( F_45 () ) ;
V_53 = F_46 () ;
V_42 = F_25 ( F_47 ( V_53 ) , V_22 ) ;
if ( ! V_42 )
return - 1 ;
if ( F_48 ( * V_42 ) )
return 0 ;
V_54 = F_49 ( V_42 , V_22 ) ;
if ( ! F_50 ( * V_54 ) )
return - 1 ;
return 0 ;
}
static inline void
F_51 ( struct V_1 * V_2 , unsigned long V_22 ,
struct V_23 * V_24 )
{
#ifdef F_52
unsigned long V_56 ;
if ( ! F_53 ( V_2 ) || ! V_24 -> V_57 . V_58 )
return;
V_56 = ( V_22 - 0xA0000 ) >> V_32 ;
if ( V_56 < 32 )
V_24 -> V_57 . V_58 -> V_59 |= 1 << V_56 ;
#endif
}
static bool F_54 ( unsigned long V_60 )
{
return V_60 < V_61 ;
}
static void F_55 ( unsigned long V_22 )
{
T_5 * V_62 = F_47 ( F_46 () ) ;
T_5 * V_34 = & V_62 [ F_26 ( V_22 ) ] ;
T_6 * V_37 ;
T_7 * V_39 ;
T_4 * V_41 ;
T_10 * V_63 ;
#ifdef F_56
F_57 ( L_2 , F_58 ( * V_34 ) ) ;
if ( ! F_54 ( F_58 ( * V_34 ) >> V_32 ) || ! F_27 ( * V_34 ) )
goto V_64;
#define F_59 pr_cont
#else
#define F_59 pr_info
#endif
V_37 = F_28 ( V_34 , V_22 ) ;
V_39 = F_30 ( V_37 , V_22 ) ;
V_41 = F_32 ( V_39 , V_22 ) ;
F_59 ( L_3 , sizeof( * V_41 ) * 2 , ( V_65 ) F_60 ( * V_41 ) ) ;
#undef F_59
if ( ! F_54 ( F_61 ( * V_41 ) ) || ! F_33 ( * V_41 ) || F_62 ( * V_41 ) )
goto V_64;
V_63 = F_49 ( V_41 , V_22 ) ;
F_63 ( L_4 , sizeof( * V_63 ) * 2 , ( V_65 ) F_64 ( * V_63 ) ) ;
V_64:
F_63 ( L_5 ) ;
}
void F_37 ( void )
{
F_65 ( V_45 & V_66 , V_55 ) ;
}
static T_9 int F_43 ( unsigned long V_22 )
{
T_5 * V_34 , * V_67 ;
T_6 * V_37 , * V_68 ;
T_7 * V_39 , * V_69 ;
T_4 * V_41 , * V_70 ;
T_10 * V_63 , * V_71 ;
if ( ! ( V_22 >= V_45 && V_22 < V_55 ) )
return - 1 ;
F_44 ( F_45 () ) ;
V_34 = ( T_5 * ) F_47 ( F_46 () ) + F_26 ( V_22 ) ;
V_67 = F_66 ( V_22 ) ;
if ( F_67 ( * V_67 ) )
return - 1 ;
if ( F_67 ( * V_34 ) ) {
F_68 ( V_34 , * V_67 ) ;
F_69 () ;
} else if ( V_72 > 4 ) {
F_35 ( F_70 ( * V_34 ) != F_70 ( * V_67 ) ) ;
}
V_37 = F_28 ( V_34 , V_22 ) ;
V_68 = F_28 ( V_67 , V_22 ) ;
if ( F_71 ( * V_68 ) )
return - 1 ;
if ( F_71 ( * V_37 ) ) {
F_72 ( V_37 , * V_68 ) ;
F_69 () ;
} else {
F_35 ( F_73 ( * V_37 ) != F_73 ( * V_68 ) ) ;
}
V_39 = F_30 ( V_37 , V_22 ) ;
V_69 = F_30 ( V_68 , V_22 ) ;
if ( F_74 ( * V_69 ) )
return - 1 ;
if ( F_74 ( * V_39 ) || F_75 ( * V_39 ) != F_75 ( * V_69 ) )
F_76 () ;
if ( F_77 ( * V_39 ) )
return 0 ;
V_41 = F_32 ( V_39 , V_22 ) ;
V_70 = F_32 ( V_69 , V_22 ) ;
if ( F_78 ( * V_70 ) )
return - 1 ;
if ( F_78 ( * V_41 ) || F_61 ( * V_41 ) != F_61 ( * V_70 ) )
F_76 () ;
if ( F_48 ( * V_41 ) )
return 0 ;
V_71 = F_49 ( V_70 , V_22 ) ;
if ( ! F_50 ( * V_71 ) )
return - 1 ;
V_63 = F_49 ( V_41 , V_22 ) ;
if ( ! F_50 ( * V_63 ) || F_79 ( * V_63 ) != F_79 ( * V_71 ) )
F_76 () ;
return 0 ;
}
static inline void
F_51 ( struct V_1 * V_2 , unsigned long V_22 ,
struct V_23 * V_24 )
{
}
static int F_80 ( void * V_73 )
{
unsigned long V_74 ;
return F_15 ( ( unsigned long * ) V_73 , V_74 ) ;
}
static void F_55 ( unsigned long V_22 )
{
T_5 * V_62 = F_47 ( F_46 () ) ;
T_5 * V_34 = V_62 + F_26 ( V_22 ) ;
T_6 * V_37 ;
T_7 * V_39 ;
T_4 * V_41 ;
T_10 * V_63 ;
if ( F_80 ( V_34 ) )
goto V_75;
F_57 ( L_6 , F_58 ( * V_34 ) ) ;
if ( ! F_27 ( * V_34 ) )
goto V_64;
V_37 = F_28 ( V_34 , V_22 ) ;
if ( F_80 ( V_37 ) )
goto V_75;
F_63 ( L_7 , F_81 ( * V_37 ) ) ;
if ( ! F_29 ( * V_37 ) || F_82 ( * V_37 ) )
goto V_64;
V_39 = F_30 ( V_37 , V_22 ) ;
if ( F_80 ( V_39 ) )
goto V_75;
F_63 ( L_8 , F_83 ( * V_39 ) ) ;
if ( ! F_31 ( * V_39 ) || F_84 ( * V_39 ) )
goto V_64;
V_41 = F_32 ( V_39 , V_22 ) ;
if ( F_80 ( V_41 ) )
goto V_75;
F_63 ( L_9 , F_60 ( * V_41 ) ) ;
if ( ! F_33 ( * V_41 ) || F_62 ( * V_41 ) )
goto V_64;
V_63 = F_49 ( V_41 , V_22 ) ;
if ( F_80 ( V_63 ) )
goto V_75;
F_63 ( L_10 , F_64 ( * V_63 ) ) ;
V_64:
F_63 ( L_5 ) ;
return;
V_75:
F_57 ( L_11 ) ;
}
static int F_85 ( struct V_1 * V_2 , unsigned long V_22 )
{
#if F_86 ( F_13 ) && F_86 ( V_76 )
if ( V_77 . V_78 != V_79
|| V_77 . V_80 != 0xf )
return 0 ;
if ( V_22 != V_2 -> V_81 )
return 0 ;
if ( ( V_22 >> 32 ) != 0 )
return 0 ;
V_22 |= 0xffffffffUL << 32 ;
if ( ( V_22 >= ( V_65 ) V_82 && V_22 <= ( V_65 ) V_83 ) ||
( V_22 >= V_84 && V_22 <= V_85 ) ) {
F_87 ( V_86 ) ;
V_2 -> V_81 = V_22 ;
return 1 ;
}
#endif
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , unsigned long V_22 )
{
#ifdef F_13
if ( ( V_2 -> V_87 == V_88 || ( V_2 -> V_87 & ( 1 << 2 ) ) ) && ( V_22 >> 32 ) )
return 1 ;
#endif
return 0 ;
}
static int F_89 ( struct V_1 * V_2 , unsigned long V_22 )
{
#ifdef F_90
unsigned long V_89 ;
if ( F_91 ( V_90 ) ) {
V_89 = ( V_22 - V_91 . V_22 ) >> 3 ;
if ( V_89 == 6 ) {
F_92 ( V_2 , 0 ) ;
return 1 ;
}
}
#endif
return 0 ;
}
static void
F_93 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 )
{
if ( ! F_94 () )
return;
if ( V_10 & V_12 ) {
unsigned int V_92 ;
T_5 * V_34 ;
T_10 * V_63 ;
V_34 = F_47 ( F_46 () ) ;
V_34 += F_26 ( V_22 ) ;
V_63 = F_95 ( V_34 , V_22 , & V_92 ) ;
if ( V_63 && F_50 ( * V_63 ) && ! F_96 ( * V_63 ) )
F_97 ( V_93 , F_98 ( & V_94 , F_99 () ) ) ;
if ( V_63 && F_50 ( * V_63 ) && F_96 ( * V_63 ) &&
( F_100 ( * V_34 ) & V_95 ) &&
( F_101 () & V_96 ) )
F_97 ( V_97 , F_98 ( & V_94 , F_99 () ) ) ;
}
F_97 ( V_98 L_12 ) ;
if ( V_22 < V_99 )
F_97 ( V_100 L_13 ) ;
else
F_97 ( V_100 L_14 ) ;
F_97 ( V_100 L_15 , ( void * ) V_22 ) ;
F_97 ( V_98 L_16 , ( void * ) V_2 -> V_81 ) ;
F_55 ( V_22 ) ;
}
static T_9 void
F_102 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 )
{
struct V_23 * V_24 ;
unsigned long V_101 ;
int V_102 ;
V_101 = F_103 () ;
V_24 = V_13 ;
V_102 = V_103 ;
F_97 ( V_98 L_17 ,
V_24 -> V_104 , V_22 ) ;
F_55 ( V_22 ) ;
V_24 -> V_57 . V_105 = V_22 ;
V_24 -> V_57 . V_106 = V_107 ;
V_24 -> V_57 . V_10 = V_10 ;
if ( F_104 ( L_18 , V_2 , V_10 ) )
V_102 = 0 ;
F_105 ( V_101 , V_2 , V_102 ) ;
}
static T_9 void
F_106 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , int signal , int V_15 )
{
struct V_23 * V_24 = V_13 ;
unsigned long V_101 ;
int V_102 ;
if ( F_107 ( V_2 , V_107 ) ) {
if ( F_108 () )
return;
if ( V_13 -> V_57 . V_108 && signal ) {
V_24 -> V_57 . V_106 = V_107 ;
V_24 -> V_57 . V_10 = V_10 | V_109 ;
V_24 -> V_57 . V_105 = V_22 ;
F_21 ( signal , V_15 , V_22 ,
V_24 , NULL , 0 ) ;
}
return;
}
#ifdef F_109
if ( F_110 ( ( void * ) V_22 ) &&
( ( ( unsigned long ) V_24 -> V_110 - 1 - V_22 < V_99 ) ||
V_22 - ( ( unsigned long ) V_24 -> V_110 + V_111 ) < V_99 ) ) {
unsigned long V_110 = F_111 ( V_112 . V_113 [ V_114 ] ) - sizeof( void * ) ;
asm volatile ("movq %[stack], %%rsp\n\t"
"call handle_stack_overflow\n\t"
"1: jmp 1b"
: ASM_CALL_CONSTRAINT
: "D" ("kernel stack overflow (page fault)"),
"S" (regs), "d" (address),
[stack] "rm" (stack));
F_112 () ;
}
#endif
if ( F_16 ( V_2 , V_10 , V_22 ) )
return;
if ( F_85 ( V_2 , V_22 ) )
return;
V_101 = F_103 () ;
F_93 ( V_2 , V_10 , V_22 ) ;
if ( F_113 ( V_24 ) )
F_97 ( V_115 L_19 ) ;
V_24 -> V_57 . V_105 = V_22 ;
V_24 -> V_57 . V_106 = V_107 ;
V_24 -> V_57 . V_10 = V_10 ;
V_102 = V_103 ;
if ( F_104 ( L_20 , V_2 , V_10 ) )
V_102 = 0 ;
F_97 ( V_116 L_21 , V_22 ) ;
F_105 ( V_101 , V_2 , V_102 ) ;
}
static inline void
F_114 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , struct V_23 * V_24 )
{
if ( ! F_115 ( V_24 , V_117 ) )
return;
if ( ! F_116 () )
return;
F_97 ( L_22 ,
F_117 ( V_24 ) > 1 ? V_118 : V_115 ,
V_24 -> V_104 , F_117 ( V_24 ) , V_22 ,
( void * ) V_2 -> V_81 , ( void * ) V_2 -> V_119 , V_10 ) ;
F_118 ( V_100 L_23 , V_2 -> V_81 ) ;
F_97 ( V_100 L_5 ) ;
}
static void
F_119 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , T_3 * V_17 , int V_15 )
{
struct V_23 * V_24 = V_13 ;
if ( V_10 & V_109 ) {
F_120 () ;
if ( F_16 ( V_2 , V_10 , V_22 ) )
return;
if ( F_88 ( V_2 , V_22 ) )
return;
#ifdef F_13
if ( F_2 ( ( V_10 & V_12 ) &&
( ( V_22 & ~ 0xfff ) == V_120 ) ) ) {
if ( F_121 ( V_2 , V_22 ) )
return;
}
#endif
if ( V_22 >= V_14 )
V_10 |= V_121 ;
if ( F_122 ( V_122 ) )
F_114 ( V_2 , V_10 , V_22 , V_24 ) ;
V_24 -> V_57 . V_105 = V_22 ;
V_24 -> V_57 . V_10 = V_10 ;
V_24 -> V_57 . V_106 = V_107 ;
F_21 ( V_117 , V_15 , V_22 , V_24 , V_17 , 0 ) ;
return;
}
if ( F_89 ( V_2 , V_22 ) )
return;
F_106 ( V_2 , V_10 , V_22 , V_117 , V_15 ) ;
}
static T_9 void
F_123 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , T_3 * V_17 )
{
F_119 ( V_2 , V_10 , V_22 , V_17 , V_123 ) ;
}
static void
F_124 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , struct V_124 * V_125 , int V_15 )
{
struct V_126 * V_127 = V_13 -> V_127 ;
T_3 V_17 ;
if ( V_125 )
V_17 = F_125 ( V_125 ) ;
F_126 ( & V_127 -> V_128 ) ;
F_119 ( V_2 , V_10 , V_22 ,
( V_125 ) ? & V_17 : NULL , V_15 ) ;
}
static T_9 void
F_127 ( struct V_1 * V_2 , unsigned long V_10 , unsigned long V_22 )
{
F_124 ( V_2 , V_10 , V_22 , NULL , V_123 ) ;
}
static inline bool F_128 ( unsigned long V_10 ,
struct V_124 * V_125 )
{
bool V_129 = false ;
if ( ! F_19 ( V_18 ) )
return false ;
if ( V_10 & V_130 )
return true ;
if ( ! F_129 ( V_125 , ( V_10 & V_131 ) ,
( V_10 & V_12 ) , V_129 ) )
return true ;
return false ;
}
static T_9 void
F_130 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , struct V_124 * V_125 )
{
if ( F_128 ( V_10 , V_125 ) )
F_124 ( V_2 , V_10 , V_22 , V_125 , V_19 ) ;
else
F_124 ( V_2 , V_10 , V_22 , V_125 , V_132 ) ;
}
static void
F_131 ( struct V_1 * V_2 , unsigned long V_10 , unsigned long V_22 ,
T_3 * V_17 , unsigned int V_25 )
{
struct V_23 * V_24 = V_13 ;
int V_133 = V_134 ;
if ( ! ( V_10 & V_109 ) ) {
F_106 ( V_2 , V_10 , V_22 , V_135 , V_134 ) ;
return;
}
if ( F_16 ( V_2 , V_10 , V_22 ) )
return;
V_24 -> V_57 . V_105 = V_22 ;
V_24 -> V_57 . V_10 = V_10 ;
V_24 -> V_57 . V_106 = V_107 ;
#ifdef F_132
if ( V_25 & ( V_31 | V_30 ) ) {
F_97 ( V_136
L_24 ,
V_24 -> V_104 , V_24 -> V_137 , V_22 ) ;
V_133 = V_138 ;
}
#endif
F_21 ( V_135 , V_133 , V_22 , V_24 , V_17 , V_25 ) ;
}
static T_9 void
F_133 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 , T_3 * V_17 , unsigned int V_25 )
{
if ( F_134 ( V_13 ) && ! ( V_10 & V_109 ) ) {
F_106 ( V_2 , V_10 , V_22 , 0 , 0 ) ;
return;
}
if ( V_25 & V_139 ) {
if ( ! ( V_10 & V_109 ) ) {
F_106 ( V_2 , V_10 , V_22 ,
V_117 , V_123 ) ;
return;
}
F_135 () ;
} else {
if ( V_25 & ( V_140 | V_31 |
V_30 ) )
F_131 ( V_2 , V_10 , V_22 , V_17 , V_25 ) ;
else if ( V_25 & V_141 )
F_123 ( V_2 , V_10 , V_22 , V_17 ) ;
else
F_76 () ;
}
}
static int F_136 ( unsigned long V_10 , T_10 * V_63 )
{
if ( ( V_10 & V_131 ) && ! F_137 ( * V_63 ) )
return 0 ;
if ( ( V_10 & V_12 ) && ! F_96 ( * V_63 ) )
return 0 ;
if ( ( V_10 & V_130 ) )
return 1 ;
return 1 ;
}
static T_9 int
F_138 ( unsigned long V_10 , unsigned long V_22 )
{
T_5 * V_34 ;
T_6 * V_37 ;
T_7 * V_39 ;
T_4 * V_41 ;
T_10 * V_63 ;
int V_4 ;
if ( V_10 != ( V_131 | V_121 )
&& V_10 != ( V_12 | V_121 ) )
return 0 ;
V_34 = V_43 . V_34 + F_26 ( V_22 ) ;
if ( ! F_27 ( * V_34 ) )
return 0 ;
V_37 = F_28 ( V_34 , V_22 ) ;
if ( ! F_29 ( * V_37 ) )
return 0 ;
if ( F_82 ( * V_37 ) )
return F_136 ( V_10 , ( T_10 * ) V_37 ) ;
V_39 = F_30 ( V_37 , V_22 ) ;
if ( ! F_31 ( * V_39 ) )
return 0 ;
if ( F_84 ( * V_39 ) )
return F_136 ( V_10 , ( T_10 * ) V_39 ) ;
V_41 = F_32 ( V_39 , V_22 ) ;
if ( ! F_33 ( * V_41 ) )
return 0 ;
if ( F_62 ( * V_41 ) )
return F_136 ( V_10 , ( T_10 * ) V_41 ) ;
V_63 = F_49 ( V_41 , V_22 ) ;
if ( ! F_50 ( * V_63 ) )
return 0 ;
V_4 = F_136 ( V_10 , V_63 ) ;
if ( ! V_4 )
return 0 ;
V_4 = F_136 ( V_10 , ( T_10 * ) V_41 ) ;
F_20 ( ! V_4 , L_25 ) ;
return V_4 ;
}
static inline int
F_139 ( unsigned long V_10 , struct V_124 * V_125 )
{
bool V_129 = false ;
if ( V_10 & V_130 )
return 1 ;
if ( ! F_129 ( V_125 , ( V_10 & V_131 ) ,
( V_10 & V_12 ) , V_129 ) )
return 1 ;
if ( V_10 & V_131 ) {
if ( F_2 ( ! ( V_125 -> V_142 & V_143 ) ) )
return 1 ;
return 0 ;
}
if ( F_2 ( V_10 & V_121 ) )
return 1 ;
if ( F_2 ( ! ( V_125 -> V_142 & ( V_144 | V_145 | V_143 ) ) ) )
return 1 ;
return 0 ;
}
static int F_140 ( unsigned long V_22 )
{
return V_22 >= V_14 ;
}
static inline bool F_141 ( int V_10 , struct V_1 * V_2 )
{
if ( ! F_142 ( V_146 ) )
return false ;
if ( ! F_143 ( V_147 ) )
return false ;
if ( V_10 & V_109 )
return false ;
if ( ! F_7 ( V_2 ) && ( V_2 -> V_101 & V_148 ) )
return false ;
return true ;
}
static T_9 void
F_144 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_22 )
{
struct V_124 * V_125 ;
struct V_23 * V_24 ;
struct V_126 * V_127 ;
int V_25 , V_149 = 0 ;
unsigned int V_101 = V_150 | V_151 ;
T_3 V_17 ;
V_24 = V_13 ;
V_127 = V_24 -> V_127 ;
if ( F_145 ( V_2 ) )
F_146 ( V_2 ) ;
F_147 ( & V_127 -> V_128 ) ;
if ( F_2 ( F_1 ( V_2 , V_22 ) ) )
return;
if ( F_2 ( F_140 ( V_22 ) ) ) {
if ( ! ( V_10 & ( V_152 | V_109 | V_121 ) ) ) {
if ( F_43 ( V_22 ) >= 0 )
return;
if ( F_148 ( V_2 , V_22 , V_10 ) )
return;
}
if ( F_138 ( V_10 , V_22 ) )
return;
if ( F_5 ( V_2 ) )
return;
F_123 ( V_2 , V_10 , V_22 , NULL ) ;
return;
}
if ( F_2 ( F_5 ( V_2 ) ) )
return;
if ( F_2 ( V_10 & V_152 ) )
F_102 ( V_2 , V_10 , V_22 ) ;
if ( F_2 ( F_141 ( V_10 , V_2 ) ) ) {
F_123 ( V_2 , V_10 , V_22 , NULL ) ;
return;
}
if ( F_2 ( F_149 () || ! V_127 ) ) {
F_123 ( V_2 , V_10 , V_22 , NULL ) ;
return;
}
if ( F_7 ( V_2 ) ) {
F_120 () ;
V_10 |= V_109 ;
V_101 |= V_153 ;
} else {
if ( V_2 -> V_101 & V_154 )
F_120 () ;
}
F_150 ( V_155 , 1 , V_2 , V_22 ) ;
if ( V_10 & V_131 )
V_101 |= V_156 ;
if ( V_10 & V_12 )
V_101 |= V_157 ;
if ( F_2 ( ! F_151 ( & V_127 -> V_128 ) ) ) {
if ( ( V_10 & V_109 ) == 0 &&
! F_152 ( V_2 -> V_81 ) ) {
F_123 ( V_2 , V_10 , V_22 , NULL ) ;
return;
}
V_158:
F_153 ( & V_127 -> V_128 ) ;
} else {
F_154 () ;
}
V_125 = F_155 ( V_127 , V_22 ) ;
if ( F_2 ( ! V_125 ) ) {
F_127 ( V_2 , V_10 , V_22 ) ;
return;
}
if ( F_122 ( V_125 -> V_159 <= V_22 ) )
goto V_160;
if ( F_2 ( ! ( V_125 -> V_142 & V_161 ) ) ) {
F_127 ( V_2 , V_10 , V_22 ) ;
return;
}
if ( V_10 & V_109 ) {
if ( F_2 ( V_22 + 65536 + 32 * sizeof( unsigned long ) < V_2 -> V_119 ) ) {
F_127 ( V_2 , V_10 , V_22 ) ;
return;
}
}
if ( F_2 ( F_156 ( V_125 , V_22 ) ) ) {
F_127 ( V_2 , V_10 , V_22 ) ;
return;
}
V_160:
if ( F_2 ( F_139 ( V_10 , V_125 ) ) ) {
F_130 ( V_2 , V_10 , V_22 , V_125 ) ;
return;
}
V_17 = F_125 ( V_125 ) ;
V_25 = F_157 ( V_125 , V_22 , V_101 ) ;
V_149 |= V_25 & V_162 ;
if ( F_2 ( V_25 & V_163 ) ) {
if ( V_101 & V_150 ) {
V_101 &= ~ V_150 ;
V_101 |= V_164 ;
if ( ! F_134 ( V_24 ) )
goto V_158;
}
if ( V_101 & V_153 )
return;
F_106 ( V_2 , V_10 , V_22 , V_135 , V_134 ) ;
return;
}
F_126 ( & V_127 -> V_128 ) ;
if ( F_2 ( V_25 & V_165 ) ) {
F_133 ( V_2 , V_10 , V_22 , & V_17 , V_25 ) ;
return;
}
if ( V_149 ) {
V_24 -> V_166 ++ ;
F_150 ( V_167 , 1 , V_2 , V_22 ) ;
} else {
V_24 -> V_168 ++ ;
F_150 ( V_169 , 1 , V_2 , V_22 ) ;
}
F_51 ( V_2 , V_22 , V_24 ) ;
}
static T_1 void
F_158 ( unsigned long V_22 , struct V_1 * V_2 ,
unsigned long V_10 )
{
if ( F_7 ( V_2 ) )
F_159 ( V_22 , V_2 , V_10 ) ;
else
F_160 ( V_22 , V_2 , V_10 ) ;
}
T_11 void T_12
F_161 ( struct V_1 * V_2 , unsigned long V_10 )
{
unsigned long V_22 = F_162 () ;
enum V_170 V_171 ;
V_171 = F_163 () ;
if ( F_164 () )
F_158 ( V_22 , V_2 , V_10 ) ;
F_144 ( V_2 , V_10 , V_22 ) ;
F_165 ( V_171 ) ;
}
