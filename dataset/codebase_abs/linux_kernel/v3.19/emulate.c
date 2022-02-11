static T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( ! ( V_2 -> V_4 & ( 1 << V_3 ) ) ) {
V_2 -> V_4 |= 1 << V_3 ;
V_2 -> V_5 [ V_3 ] = V_2 -> V_6 -> V_7 ( V_2 , V_3 ) ;
}
return V_2 -> V_5 [ V_3 ] ;
}
static T_1 * F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
V_2 -> V_4 |= 1 << V_3 ;
V_2 -> V_8 |= 1 << V_3 ;
return & V_2 -> V_5 [ V_3 ] ;
}
static T_1 * F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
F_1 ( V_2 , V_3 ) ;
return F_2 ( V_2 , V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned V_9 ;
F_5 (reg, (ulong *)&ctxt->regs_dirty, 16 )
V_2 -> V_6 -> V_10 ( V_2 , V_9 , V_2 -> V_5 [ V_9 ] ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_8 = 0 ;
V_2 -> V_4 = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_11 V_12 ,
enum V_13 V_14 )
{
struct V_15 V_16 = {
. V_12 = V_12 ,
. V_17 = V_2 -> V_17 ,
. V_18 = V_2 -> V_18 ,
. V_19 = V_2 -> V_19 ,
. V_20 = V_2 -> V_20 ,
. V_21 = V_2 -> V_22 . V_23 ,
. V_24 = V_2 -> V_25 . V_23 ,
. V_26 = V_2 -> V_22 . V_27 ,
. V_28 = V_2 -> V_25 . V_27 ,
. V_29 = V_2 -> V_29 ,
. V_30 = V_2 -> V_31 ,
} ;
return V_2 -> V_6 -> V_12 ( V_2 , & V_16 , V_14 ) ;
}
static void F_8 ( T_1 * V_32 , T_1 V_22 , T_1 V_33 )
{
* V_32 = ( * V_32 & ~ V_33 ) | ( V_22 & V_33 ) ;
}
static inline unsigned long F_9 ( struct V_1 * V_2 )
{
return ( 1UL << ( V_2 -> V_29 << 3 ) ) - 1 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_2 V_34 ;
struct V_35 V_36 ;
if ( V_2 -> V_37 == V_38 )
return ~ 0UL ;
V_2 -> V_6 -> V_39 ( V_2 , & V_34 , & V_36 , NULL , V_40 ) ;
return ~ 0U >> ( ( V_36 . V_41 ^ 1 ) * 16 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return ( F_12 ( F_10 ( V_2 ) ) + 1 ) >> 3 ;
}
static inline unsigned long
F_13 ( struct V_1 * V_2 , unsigned long V_9 )
{
if ( V_2 -> V_29 == sizeof( unsigned long ) )
return V_9 ;
else
return V_9 & F_9 ( V_2 ) ;
}
static inline unsigned long
F_14 ( struct V_1 * V_2 , int V_9 )
{
return F_13 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static void F_15 ( T_1 * V_9 , T_1 V_33 , int V_42 )
{
F_8 ( V_9 , * V_9 + V_42 , V_33 ) ;
}
static inline void
F_16 ( struct V_1 * V_2 , int V_9 , int V_42 )
{
T_1 V_33 ;
if ( V_2 -> V_29 == sizeof( unsigned long ) )
V_33 = ~ 0UL ;
else
V_33 = F_9 ( V_2 ) ;
F_15 ( F_3 ( V_2 , V_9 ) , V_33 , V_42 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_42 )
{
F_15 ( F_3 ( V_2 , V_43 ) , F_10 ( V_2 ) , V_42 ) ;
}
static T_3 F_18 ( struct V_35 * V_44 )
{
T_3 V_45 = F_19 ( V_44 ) ;
return V_44 -> V_46 ? ( V_45 << 12 ) | 0xfff : V_45 ;
}
static unsigned long F_20 ( struct V_1 * V_2 , int V_47 )
{
if ( V_2 -> V_37 == V_38 && V_47 < V_48 )
return 0 ;
return V_2 -> V_6 -> V_49 ( V_2 , V_47 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_50 ,
T_3 error , bool V_51 )
{
F_22 ( V_50 > 0x1f ) ;
V_2 -> V_52 . V_53 = V_50 ;
V_2 -> V_52 . V_54 = error ;
V_2 -> V_52 . V_55 = V_51 ;
return V_56 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_57 , 0 , false ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_58 )
{
return F_21 ( V_2 , V_59 , V_58 , true ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_58 )
{
return F_21 ( V_2 , V_60 , V_58 , true ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_61 , 0 , false ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_58 )
{
return F_21 ( V_2 , V_62 , V_58 , true ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_63 , 0 , false ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_64 , 0 , false ) ;
}
static T_2 F_30 ( struct V_1 * V_2 , unsigned V_47 )
{
T_2 V_65 ;
struct V_35 V_44 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_65 , & V_44 , NULL , V_47 ) ;
return V_65 ;
}
static void F_31 ( struct V_1 * V_2 , T_2 V_65 ,
unsigned V_47 )
{
T_2 V_66 ;
T_3 V_67 ;
struct V_35 V_44 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_66 , & V_44 , & V_67 , V_47 ) ;
V_2 -> V_6 -> V_68 ( V_2 , V_65 , & V_44 , V_67 , V_47 ) ;
}
static bool F_32 ( struct V_1 * V_2 , unsigned V_69 )
{
if ( F_33 ( V_69 < 16 ) )
return false ;
if ( V_2 -> V_41 & V_70 )
return true ;
else if ( V_2 -> V_41 & V_71 )
return false ;
else if ( V_2 -> V_41 & V_72 )
return false ;
else
return true ;
}
static T_4 int F_34 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
unsigned * V_75 , unsigned V_69 ,
bool V_76 , bool V_77 ,
enum V_78 V_37 , T_1 * V_79 )
{
struct V_35 V_44 ;
bool V_80 ;
T_1 V_81 ;
T_3 V_82 ;
T_2 V_34 ;
V_81 = F_20 ( V_2 , V_74 . V_47 ) + V_74 . V_83 ;
* V_75 = 0 ;
switch ( V_37 ) {
case V_38 :
if ( F_35 ( V_81 ) )
goto V_84;
* V_75 = F_36 ( V_85 , ~ 0u , ( 1ull << 48 ) - V_81 ) ;
if ( V_69 > * V_75 )
goto V_84;
break;
default:
V_80 = V_2 -> V_6 -> V_39 ( V_2 , & V_34 , & V_44 , NULL ,
V_74 . V_47 ) ;
if ( ! V_80 )
goto V_84;
if ( ( ( ( V_2 -> V_37 != V_86 ) && ( V_44 . type & 8 ) )
|| ! ( V_44 . type & 2 ) ) && V_76 )
goto V_84;
if ( ! V_77 && ( V_44 . type & 8 ) && ! ( V_44 . type & 2 ) )
goto V_84;
V_82 = F_18 ( & V_44 ) ;
if ( ! ( V_44 . type & 8 ) && ( V_44 . type & 4 ) ) {
if ( V_74 . V_83 <= V_82 )
goto V_84;
V_82 = V_44 . V_41 ? 0xffffffff : 0xffff ;
}
if ( V_74 . V_83 > V_82 )
goto V_84;
* V_75 = F_36 ( V_85 , ~ 0u , ( V_85 ) V_82 + 1 - V_74 . V_83 ) ;
if ( V_69 > * V_75 )
goto V_84;
V_81 &= ( T_3 ) - 1 ;
break;
}
if ( F_32 ( V_2 , V_69 ) && ( ( V_81 & ( V_69 - 1 ) ) != 0 ) )
return F_24 ( V_2 , 0 ) ;
* V_79 = V_81 ;
return V_87 ;
V_84:
if ( V_74 . V_47 == V_40 )
return F_25 ( V_2 , 0 ) ;
else
return F_24 ( V_2 , 0 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
unsigned V_69 , bool V_76 ,
T_1 * V_79 )
{
unsigned V_75 ;
return F_34 ( V_2 , V_74 , & V_75 , V_69 , V_76 , false ,
V_2 -> V_37 , V_79 ) ;
}
static inline int F_38 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_78 V_37 )
{
T_1 V_79 ;
int V_88 ;
unsigned V_75 ;
struct V_73 V_74 = { . V_47 = V_89 ,
. V_83 = V_25 } ;
if ( V_2 -> V_90 != sizeof( unsigned long ) )
V_74 . V_83 = V_25 & ( ( 1UL << ( V_2 -> V_90 << 3 ) ) - 1 ) ;
V_88 = F_34 ( V_2 , V_74 , & V_75 , 1 , false , true , V_37 , & V_79 ) ;
if ( V_88 == V_87 )
V_2 -> V_91 = V_74 . V_83 ;
return V_88 ;
}
static inline int F_39 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_38 ( V_2 , V_25 , V_2 -> V_37 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_25 ,
const struct V_35 * V_92 )
{
enum V_78 V_37 = V_2 -> V_37 ;
#ifdef F_41
if ( V_2 -> V_37 >= V_93 && V_92 -> V_94 ) {
V_85 V_95 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
V_37 = V_38 ;
}
#endif
if ( V_37 == V_99 || V_37 == V_93 )
V_37 = V_92 -> V_41 ? V_93 : V_99 ;
return F_38 ( V_2 , V_25 , V_37 ) ;
}
static inline int F_42 ( struct V_1 * V_2 , int V_100 )
{
return F_39 ( V_2 , V_2 -> V_91 + V_100 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
void * V_101 ,
unsigned V_69 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_74 , V_69 , false , & V_79 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_102 ( V_2 , V_79 , V_101 , V_69 , & V_2 -> V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_103 )
{
int V_88 ;
unsigned V_69 , V_75 ;
unsigned long V_79 ;
int V_104 = V_2 -> V_77 . V_105 - V_2 -> V_77 . V_101 ;
struct V_73 V_74 = { . V_47 = V_89 ,
. V_83 = V_2 -> V_31 + V_104 } ;
V_88 = F_34 ( V_2 , V_74 , & V_75 , 0 , false , true , V_2 -> V_37 ,
& V_79 ) ;
if ( F_45 ( V_88 != V_87 ) )
return V_88 ;
V_69 = F_36 ( unsigned , 15UL ^ V_104 , V_75 ) ;
V_69 = F_36 ( unsigned , V_69 , V_106 - F_46 ( V_79 ) ) ;
if ( F_45 ( V_69 < V_103 ) )
return F_24 ( V_2 , 0 ) ;
V_88 = V_2 -> V_6 -> V_77 ( V_2 , V_79 , V_2 -> V_77 . V_105 ,
V_69 , & V_2 -> V_52 ) ;
if ( F_45 ( V_88 != V_87 ) )
return V_88 ;
V_2 -> V_77 . V_105 += V_69 ;
return V_87 ;
}
static T_4 int F_47 ( struct V_1 * V_2 ,
unsigned V_69 )
{
unsigned V_107 = V_2 -> V_77 . V_105 - V_2 -> V_77 . V_108 ;
if ( F_45 ( V_107 < V_69 ) )
return F_44 ( V_2 , V_69 - V_107 ) ;
else
return V_87 ;
}
static void * F_48 ( struct V_1 * V_2 , T_5 V_19 ,
int V_109 )
{
void * V_110 ;
int V_111 = ( V_2 -> V_112 == 0 ) && V_109 ;
if ( V_111 && V_19 >= 4 && V_19 < 8 )
V_110 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_110 = F_3 ( V_2 , V_19 ) ;
return V_110 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
T_2 * V_69 , unsigned long * V_113 , int V_90 )
{
int V_88 ;
if ( V_90 == 2 )
V_90 = 3 ;
* V_113 = 0 ;
V_88 = F_43 ( V_2 , V_74 , V_69 , 2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_74 . V_83 += 2 ;
V_88 = F_43 ( V_2 , V_74 , V_113 , V_90 ) ;
return V_88 ;
}
static T_5 F_50 ( unsigned int V_114 , unsigned long V_115 )
{
T_5 V_88 ;
void (* F_51)( void ) = ( void * ) V_116 + 4 * ( V_114 & 0xf ) ;
V_115 = ( V_115 & V_117 ) | V_118 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_88 ;
}
static void F_52 ( struct V_119 * V_120 )
{
switch ( V_120 -> V_27 ) {
case 1 :
V_120 -> V_121 = * ( T_5 * ) V_120 -> V_74 . V_9 ;
break;
case 2 :
V_120 -> V_121 = * ( T_2 * ) V_120 -> V_74 . V_9 ;
break;
case 4 :
V_120 -> V_121 = * ( T_3 * ) V_120 -> V_74 . V_9 ;
break;
case 8 :
V_120 -> V_121 = * ( V_85 * ) V_120 -> V_74 . V_9 ;
break;
}
}
static void F_53 ( struct V_1 * V_2 , T_6 * V_101 , int V_9 )
{
V_2 -> V_6 -> V_122 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_41
case 8 : asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_54 () ;
}
V_2 -> V_6 -> V_123 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_6 * V_101 ,
int V_9 )
{
V_2 -> V_6 -> V_122 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_41
case 8 : asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_54 () ;
}
V_2 -> V_6 -> V_123 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 , V_85 * V_101 , int V_9 )
{
V_2 -> V_6 -> V_122 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_54 () ;
}
V_2 -> V_6 -> V_123 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 , V_85 * V_101 , int V_9 )
{
V_2 -> V_6 -> V_122 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_54 () ;
}
V_2 -> V_6 -> V_123 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_124 ( V_2 , 0 ) & ( V_125 | V_126 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_122 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_123 ( V_2 ) ;
return V_87 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_2 V_127 ;
if ( V_2 -> V_6 -> V_124 ( V_2 , 0 ) & ( V_125 | V_126 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_122 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_123 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_121 = V_127 ;
return V_87 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_2 V_128 ;
if ( V_2 -> V_6 -> V_124 ( V_2 , 0 ) & ( V_125 | V_126 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_122 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_123 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_121 = V_128 ;
return V_87 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_41 & V_129 ) )
V_9 = ( V_2 -> V_130 & 7 ) | ( ( V_2 -> V_112 & 1 ) << 3 ) ;
if ( V_2 -> V_41 & V_131 ) {
V_120 -> type = V_132 ;
V_120 -> V_27 = 16 ;
V_120 -> V_74 . V_133 = V_9 ;
F_53 ( V_2 , & V_120 -> V_134 , V_9 ) ;
return;
}
if ( V_2 -> V_41 & V_135 ) {
V_9 &= 7 ;
V_120 -> type = V_136 ;
V_120 -> V_27 = 8 ;
V_120 -> V_74 . V_137 = V_9 ;
return;
}
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_48 ( V_2 , V_9 , V_2 -> V_41 & V_139 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
}
static void F_62 ( struct V_1 * V_2 , int V_141 )
{
if ( V_141 == V_43 || V_141 == V_142 )
V_2 -> V_143 = V_40 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
T_5 V_144 ;
int V_145 , V_141 , V_146 ;
int V_88 = V_87 ;
T_1 V_147 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_112 << 1 ) & 8 ) ;
V_145 = ( V_2 -> V_112 << 2 ) & 8 ;
V_141 = ( V_2 -> V_112 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_148 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_148 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_141 | ( V_2 -> V_148 & 0x07 ) ;
V_2 -> V_143 = V_149 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_41 & V_150 ) ) {
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_48 ( V_2 , V_2 -> V_20 ,
V_2 -> V_41 & V_139 ) ;
if ( V_2 -> V_41 & V_131 ) {
V_120 -> type = V_132 ;
V_120 -> V_27 = 16 ;
V_120 -> V_74 . V_133 = V_2 -> V_20 ;
F_53 ( V_2 , & V_120 -> V_134 , V_2 -> V_20 ) ;
return V_88 ;
}
if ( V_2 -> V_41 & V_135 ) {
V_120 -> type = V_136 ;
V_120 -> V_27 = 8 ;
V_120 -> V_74 . V_137 = V_2 -> V_20 & 7 ;
return V_88 ;
}
F_52 ( V_120 ) ;
return V_88 ;
}
V_120 -> type = V_151 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_152 = F_1 ( V_2 , V_153 ) ;
unsigned V_154 = F_1 ( V_2 , V_142 ) ;
unsigned V_155 = F_1 ( V_2 , V_156 ) ;
unsigned V_157 = F_1 ( V_2 , V_158 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_147 += F_64 ( T_2 , V_2 ) ;
break;
case 1 :
V_147 += F_64 ( V_159 , V_2 ) ;
break;
case 2 :
V_147 += F_64 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_147 += V_152 + V_155 ;
break;
case 1 :
V_147 += V_152 + V_157 ;
break;
case 2 :
V_147 += V_154 + V_155 ;
break;
case 3 :
V_147 += V_154 + V_157 ;
break;
case 4 :
V_147 += V_155 ;
break;
case 5 :
V_147 += V_157 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_147 += V_154 ;
break;
case 7 :
V_147 += V_152 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_143 = V_40 ;
V_147 = ( T_2 ) V_147 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_144 = F_64 ( T_5 , V_2 ) ;
V_145 |= ( V_144 >> 3 ) & 7 ;
V_141 |= V_144 & 7 ;
V_146 = V_144 >> 6 ;
if ( ( V_141 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_147 += F_64 ( V_160 , V_2 ) ;
else {
V_147 += F_1 ( V_2 , V_141 ) ;
F_62 ( V_2 , V_141 ) ;
}
if ( V_145 != 4 )
V_147 += F_1 ( V_2 , V_145 ) << V_146 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_147 += F_64 ( V_160 , V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_161 = 1 ;
} else {
V_141 = V_2 -> V_20 ;
V_147 += F_1 ( V_2 , V_141 ) ;
F_62 ( V_2 , V_141 ) ;
}
switch ( V_2 -> V_18 ) {
case 1 :
V_147 += F_64 ( V_159 , V_2 ) ;
break;
case 2 :
V_147 += F_64 ( V_160 , V_2 ) ;
break;
}
}
V_120 -> V_74 . V_162 . V_83 = V_147 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_163 . V_74 . V_162 . V_83 = ( T_3 ) V_2 -> V_163 . V_74 . V_162 . V_83 ;
V_164:
return V_88 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
int V_88 = V_87 ;
V_120 -> type = V_151 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_120 -> V_74 . V_162 . V_83 = F_64 ( T_2 , V_2 ) ;
break;
case 4 :
V_120 -> V_74 . V_162 . V_83 = F_64 ( T_3 , V_2 ) ;
break;
case 8 :
V_120 -> V_74 . V_162 . V_83 = F_64 ( V_85 , V_2 ) ;
break;
}
V_164:
return V_88 ;
}
static void F_66 ( struct V_1 * V_2 )
{
long V_165 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_151 && V_2 -> V_22 . type == V_138 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_165 = ( V_166 ) V_2 -> V_22 . V_121 & ( V_166 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_165 = ( V_160 ) V_2 -> V_22 . V_121 & ( V_160 ) V_33 ;
else
V_165 = ( V_167 ) V_2 -> V_22 . V_121 & ( V_167 ) V_33 ;
V_2 -> V_25 . V_74 . V_162 . V_83 = F_13 ( V_2 ,
V_2 -> V_25 . V_74 . V_162 . V_83 + ( V_165 >> 3 ) ) ;
}
V_2 -> V_22 . V_121 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_74 , void * V_32 , unsigned V_69 )
{
int V_88 ;
struct V_168 * V_169 = & V_2 -> V_170 ;
if ( V_169 -> V_171 < V_169 -> V_105 )
goto V_172;
F_22 ( ( V_169 -> V_105 + V_69 ) >= sizeof( V_169 -> V_101 ) ) ;
V_88 = V_2 -> V_6 -> F_67 ( V_2 , V_74 , V_169 -> V_101 + V_169 -> V_105 , V_69 ,
& V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_169 -> V_105 += V_69 ;
V_172:
memcpy ( V_32 , V_169 -> V_101 + V_169 -> V_171 , V_69 ) ;
V_169 -> V_171 += V_69 ;
return V_87 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
void * V_101 ,
unsigned V_69 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_74 , V_69 , false , & V_79 ) ;
if ( V_88 != V_87 )
return V_88 ;
return F_67 ( V_2 , V_79 , V_101 , V_69 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
const void * V_101 ,
unsigned V_69 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_74 , V_69 , true , & V_79 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_173 ( V_2 , V_79 , V_101 , V_69 ,
& V_2 -> V_52 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
const void * V_174 , const void * V_101 ,
unsigned V_69 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_74 , V_69 , true , & V_79 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_175 ( V_2 , V_79 , V_174 , V_101 ,
V_69 , & V_2 -> V_52 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_69 , unsigned short V_176 ,
void * V_32 )
{
struct V_168 * V_88 = & V_2 -> V_177 ;
if ( V_88 -> V_171 == V_88 -> V_105 ) {
unsigned int V_178 , V_179 ;
unsigned int V_180 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_181 ) ) : 1 ;
V_178 = ( V_2 -> V_182 & V_183 ) ?
F_46 ( F_1 ( V_2 , V_158 ) ) :
V_106 - F_46 ( F_1 ( V_2 , V_158 ) ) ;
V_179 = F_72 ( V_178 , ( unsigned int ) sizeof( V_88 -> V_101 ) / V_69 , V_180 ) ;
if ( V_179 == 0 )
V_179 = 1 ;
V_88 -> V_171 = V_88 -> V_105 = 0 ;
if ( ! V_2 -> V_6 -> F_71 ( V_2 , V_69 , V_176 , V_88 -> V_101 , V_179 ) )
return 0 ;
V_88 -> V_105 = V_179 * V_69 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) &&
! ( V_2 -> V_182 & V_183 ) ) {
V_2 -> V_25 . V_101 = V_88 -> V_101 + V_88 -> V_171 ;
V_2 -> V_25 . type = V_184 ;
V_2 -> V_25 . V_180 = ( V_88 -> V_105 - V_88 -> V_171 ) / V_69 ;
V_88 -> V_171 = V_88 -> V_105 ;
} else {
memcpy ( V_32 , V_88 -> V_101 + V_88 -> V_171 , V_69 ) ;
V_88 -> V_171 += V_69 ;
}
return 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_185 , struct V_35 * V_44 )
{
struct V_186 V_187 ;
T_1 V_74 ;
V_2 -> V_6 -> V_188 ( V_2 , & V_187 ) ;
if ( V_187 . V_69 < V_185 * 8 + 7 )
return F_24 ( V_2 , V_185 << 3 | 0x2 ) ;
V_74 = V_187 . V_113 + V_185 * 8 ;
return V_2 -> V_6 -> V_102 ( V_2 , V_74 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_186 * V_187 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
T_3 V_67 = 0 ;
if ( V_65 & 1 << 2 ) {
struct V_35 V_44 ;
T_2 V_34 ;
memset ( V_187 , 0 , sizeof *V_187 ) ;
if ( ! V_6 -> V_39 ( V_2 , & V_34 , & V_44 , & V_67 ,
V_190 ) )
return;
V_187 -> V_69 = F_18 ( & V_44 ) ;
V_187 -> V_113 = F_75 ( & V_44 ) | ( ( V_85 ) V_67 << 32 ) ;
} else
V_6 -> V_191 ( V_2 , V_187 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_35 * V_44 ,
T_1 * V_192 )
{
struct V_186 V_187 ;
T_2 V_185 = V_65 >> 3 ;
T_1 V_74 ;
F_74 ( V_2 , V_65 , & V_187 ) ;
if ( V_187 . V_69 < V_185 * 8 + 7 )
return F_24 ( V_2 , V_65 & 0xfffc ) ;
* V_192 = V_74 = V_187 . V_113 + V_185 * 8 ;
return V_2 -> V_6 -> V_102 ( V_2 , V_74 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_35 * V_44 )
{
struct V_186 V_187 ;
T_2 V_185 = V_65 >> 3 ;
T_1 V_74 ;
F_74 ( V_2 , V_65 , & V_187 ) ;
if ( V_187 . V_69 < V_185 * 8 + 7 )
return F_24 ( V_2 , V_65 & 0xfffc ) ;
V_74 = V_187 . V_113 + V_185 * 8 ;
return V_2 -> V_6 -> V_193 ( V_2 , V_74 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
T_2 V_65 , int V_47 , T_5 V_194 ,
bool V_195 ,
struct V_35 * V_44 )
{
struct V_35 V_196 , V_197 ;
T_5 V_198 , V_199 ;
unsigned V_200 = V_59 ;
T_3 V_201 = 0 ;
bool V_202 = ! ( V_65 & ~ 0x3 ) ;
T_1 V_203 ;
int V_204 ;
T_2 V_66 ;
T_3 V_67 = 0 ;
memset ( & V_196 , 0 , sizeof V_196 ) ;
if ( V_2 -> V_37 == V_86 ) {
V_2 -> V_6 -> V_39 ( V_2 , & V_66 , & V_196 , NULL , V_47 ) ;
F_79 ( & V_196 , V_65 << 4 ) ;
goto V_205;
} else if ( V_47 <= V_206 && V_2 -> V_37 == V_207 ) {
F_79 ( & V_196 , V_65 << 4 ) ;
F_80 ( & V_196 , 0xffff ) ;
V_196 . type = 3 ;
V_196 . V_110 = 1 ;
V_196 . V_208 = 1 ;
V_196 . V_198 = 3 ;
goto V_205;
}
V_199 = V_65 & 3 ;
if ( ( V_47 == V_89
|| ( V_47 == V_40
&& ( V_2 -> V_37 != V_38 || V_199 != V_194 ) )
|| V_47 == V_209 )
&& V_202 )
goto V_52;
if ( V_47 == V_209 && ( V_65 & ( 1 << 2 ) ) )
goto V_52;
if ( V_202 )
goto V_205;
V_204 = F_76 ( V_2 , V_65 , & V_196 , & V_203 ) ;
if ( V_204 != V_87 )
return V_204 ;
V_201 = V_65 & 0xfffc ;
V_200 = V_195 ? V_62 : V_59 ;
if ( V_47 <= V_206 && ! V_196 . V_208 )
goto V_52;
if ( ! V_196 . V_110 ) {
V_200 = ( V_47 == V_40 ) ? V_60 : V_210 ;
goto V_52;
}
V_198 = V_196 . V_198 ;
switch ( V_47 ) {
case V_40 :
if ( V_199 != V_194 || ( V_196 . type & 0xa ) != 0x2 || V_198 != V_194 )
goto V_52;
break;
case V_89 :
if ( ! ( V_196 . type & 8 ) )
goto V_52;
if ( V_196 . type & 4 ) {
if ( V_198 > V_194 )
goto V_52;
} else {
if ( V_199 > V_194 || V_198 != V_194 )
goto V_52;
}
if ( V_196 . V_41 && V_196 . V_94 ) {
V_85 V_95 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
goto V_52;
}
V_65 = ( V_65 & 0xfffc ) | V_194 ;
break;
case V_209 :
if ( V_196 . V_208 || ( V_196 . type != 1 && V_196 . type != 9 ) )
goto V_52;
V_197 = V_196 ;
V_196 . type |= 2 ;
V_204 = V_2 -> V_6 -> V_175 ( V_2 , V_203 , & V_197 , & V_196 ,
sizeof( V_196 ) , & V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
break;
case V_190 :
if ( V_196 . V_208 || V_196 . type != 2 )
goto V_52;
break;
default:
if ( ( V_196 . type & 0xa ) == 0x8 ||
( ( ( V_196 . type & 0xc ) != 0xc ) &&
( V_199 > V_198 && V_194 > V_198 ) ) )
goto V_52;
break;
}
if ( V_196 . V_208 ) {
V_196 . type |= 1 ;
V_204 = F_77 ( V_2 , V_65 , & V_196 ) ;
if ( V_204 != V_87 )
return V_204 ;
} else if ( V_2 -> V_37 == V_38 ) {
V_204 = V_2 -> V_6 -> V_102 ( V_2 , V_203 + 8 , & V_67 ,
sizeof( V_67 ) , & V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
if ( F_35 ( F_75 ( & V_196 ) |
( ( V_85 ) V_67 << 32 ) ) )
return F_24 ( V_2 , 0 ) ;
}
V_205:
V_2 -> V_6 -> V_68 ( V_2 , V_65 , & V_196 , V_67 , V_47 ) ;
if ( V_44 )
* V_44 = V_196 ;
return V_87 ;
V_52:
return F_21 ( V_2 , V_200 , V_201 , true ) ;
}
static int F_81 ( struct V_1 * V_2 ,
T_2 V_65 , int V_47 )
{
T_5 V_194 = V_2 -> V_6 -> V_194 ( V_2 ) ;
return F_78 ( V_2 , V_65 , V_47 , V_194 , false , NULL ) ;
}
static void F_82 ( struct V_119 * V_120 )
{
switch ( V_120 -> V_27 ) {
case 1 :
* ( T_5 * ) V_120 -> V_74 . V_9 = ( T_5 ) V_120 -> V_121 ;
break;
case 2 :
* ( T_2 * ) V_120 -> V_74 . V_9 = ( T_2 ) V_120 -> V_121 ;
break;
case 4 :
* V_120 -> V_74 . V_9 = ( T_3 ) V_120 -> V_121 ;
break;
case 8 :
* V_120 -> V_74 . V_9 = V_120 -> V_121 ;
break;
}
}
static int F_83 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
switch ( V_120 -> type ) {
case V_138 :
F_82 ( V_120 ) ;
break;
case V_151 :
if ( V_2 -> V_211 )
return F_70 ( V_2 ,
V_120 -> V_74 . V_162 ,
& V_120 -> V_140 ,
& V_120 -> V_121 ,
V_120 -> V_27 ) ;
else
return F_69 ( V_2 ,
V_120 -> V_74 . V_162 ,
& V_120 -> V_121 ,
V_120 -> V_27 ) ;
break;
case V_184 :
return F_69 ( V_2 ,
V_120 -> V_74 . V_162 ,
V_120 -> V_101 ,
V_120 -> V_27 * V_120 -> V_180 ) ;
break;
case V_132 :
F_55 ( V_2 , & V_120 -> V_134 , V_120 -> V_74 . V_133 ) ;
break;
case V_136 :
F_57 ( V_2 , & V_120 -> V_212 , V_120 -> V_74 . V_137 ) ;
break;
case V_213 :
break;
default:
break;
}
return V_87 ;
}
static int F_84 ( struct V_1 * V_2 , void * V_101 , int V_27 )
{
struct V_73 V_74 ;
F_17 ( V_2 , - V_27 ) ;
V_74 . V_83 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_74 . V_47 = V_40 ;
return F_69 ( V_2 , V_74 , V_101 , V_27 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_213 ;
return F_84 ( V_2 , & V_2 -> V_22 . V_121 , V_2 -> V_90 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
void * V_32 , int V_214 )
{
int V_88 ;
struct V_73 V_74 ;
V_74 . V_83 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_74 . V_47 = V_40 ;
V_88 = F_68 ( V_2 , V_74 , V_32 , V_214 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_214 ) ;
return V_88 ;
}
static int F_87 ( struct V_1 * V_2 )
{
return F_86 ( V_2 , & V_2 -> V_25 . V_121 , V_2 -> V_90 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
void * V_32 , int V_214 )
{
int V_88 ;
unsigned long V_121 , V_215 ;
int V_216 = ( V_2 -> V_182 & V_217 ) >> V_218 ;
int V_194 = V_2 -> V_6 -> V_194 ( V_2 ) ;
V_88 = F_86 ( V_2 , & V_121 , V_214 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_215 = V_219 | V_220 | V_221 | V_222 | V_223 | V_224
| V_225 | V_183 | V_226 | V_227 | V_228 ;
switch( V_2 -> V_37 ) {
case V_38 :
case V_93 :
case V_99 :
if ( V_194 == 0 )
V_215 |= V_229 ;
if ( V_194 <= V_216 )
V_215 |= V_230 ;
break;
case V_207 :
if ( V_216 < 3 )
return F_24 ( V_2 , 0 ) ;
V_215 |= V_230 ;
break;
default:
V_215 |= ( V_229 | V_230 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_182 & ~ V_215 ) | ( V_121 & V_215 ) ;
return V_88 ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_138 ;
V_2 -> V_25 . V_74 . V_9 = & V_2 -> V_182 ;
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
return F_88 ( V_2 , & V_2 -> V_25 . V_121 , V_2 -> V_90 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned V_231 = V_2 -> V_22 . V_121 ;
unsigned V_232 = V_2 -> V_233 . V_121 & 31 ;
T_1 V_234 ;
if ( V_232 )
return V_235 ;
V_234 = F_1 ( V_2 , V_142 ) ;
V_88 = F_84 ( V_2 , & V_234 , F_11 ( V_2 ) ) ;
if ( V_88 != V_87 )
return V_88 ;
F_8 ( F_3 ( V_2 , V_142 ) , F_1 ( V_2 , V_43 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_43 ) ,
F_1 ( V_2 , V_43 ) - V_231 ,
F_10 ( V_2 ) ) ;
return V_87 ;
}
static int F_91 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_43 ) , F_1 ( V_2 , V_142 ) ,
F_10 ( V_2 ) ) ;
return F_86 ( V_2 , F_3 ( V_2 , V_142 ) , V_2 -> V_90 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_121 ;
V_2 -> V_22 . V_121 = F_30 ( V_2 , V_47 ) ;
if ( V_2 -> V_90 == 4 ) {
F_17 ( V_2 , - 2 ) ;
V_2 -> V_90 = 2 ;
}
return F_85 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_121 ;
unsigned long V_65 ;
int V_88 ;
V_88 = F_86 ( V_2 , & V_65 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_236 = V_237 ;
V_88 = F_81 ( V_2 , ( T_2 ) V_65 , V_47 ) ;
return V_88 ;
}
static int F_94 ( struct V_1 * V_2 )
{
unsigned long V_238 = F_1 ( V_2 , V_43 ) ;
int V_88 = V_87 ;
int V_9 = V_239 ;
while ( V_9 <= V_158 ) {
( V_9 == V_43 ) ?
( V_2 -> V_22 . V_121 = V_238 ) : ( V_2 -> V_22 . V_121 = F_1 ( V_2 , V_9 ) ) ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
++ V_9 ;
}
return V_88 ;
}
static int F_95 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_121 = ( unsigned long ) V_2 -> V_182 & ~ V_240 ;
return F_85 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
int V_9 = V_158 ;
while ( V_9 >= V_239 ) {
if ( V_9 == V_43 ) {
F_17 ( V_2 , V_2 -> V_90 ) ;
-- V_9 ;
}
V_88 = F_86 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
break;
-- V_9 ;
}
return V_88 ;
}
static int F_97 ( struct V_1 * V_2 , int V_241 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
int V_88 ;
struct V_186 V_187 ;
T_7 V_242 ;
T_7 V_243 ;
T_2 V_244 , V_31 ;
V_2 -> V_22 . V_121 = V_2 -> V_182 ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_182 &= ~ ( V_230 | V_225 | V_227 ) ;
V_2 -> V_22 . V_121 = F_30 ( V_2 , V_89 ) ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_22 . V_121 = V_2 -> V_91 ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_6 -> V_188 ( V_2 , & V_187 ) ;
V_243 = V_187 . V_113 + ( V_241 << 2 ) ;
V_242 = V_187 . V_113 + ( V_241 << 2 ) + 2 ;
V_88 = V_6 -> V_102 ( V_2 , V_242 , & V_244 , 2 , & V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = V_6 -> V_102 ( V_2 , V_243 , & V_31 , 2 , & V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_81 ( V_2 , V_244 , V_89 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_31 ;
return V_88 ;
}
int F_98 ( struct V_1 * V_2 , int V_241 )
{
int V_88 ;
F_6 ( V_2 ) ;
V_88 = F_97 ( V_2 , V_241 ) ;
if ( V_88 == V_87 )
F_4 ( V_2 ) ;
return V_88 ;
}
static int F_99 ( struct V_1 * V_2 , int V_241 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_97 ( V_2 , V_241 ) ;
case V_207 :
case V_99 :
case V_93 :
case V_38 :
default:
return V_235 ;
}
}
static int F_100 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
unsigned long V_245 = 0 ;
unsigned long V_246 = 0 ;
unsigned long V_244 = 0 ;
unsigned long V_33 = V_219 | V_220 | V_221 | V_222 | V_223 | V_225 |
V_230 | V_183 | V_224 | V_229 | V_226 | V_247 |
V_227 | V_228 | ( 1 << 1 ) ;
unsigned long V_248 = V_240 | V_249 | V_250 ;
V_88 = F_86 ( V_2 , & V_245 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_245 & ~ 0xffff )
return F_24 ( V_2 , 0 ) ;
V_88 = F_86 ( V_2 , & V_244 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_86 ( V_2 , & V_246 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_81 ( V_2 , ( T_2 ) V_244 , V_89 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_245 ;
if ( V_2 -> V_90 == 4 )
V_2 -> V_182 = ( ( V_246 & V_33 ) | ( V_2 -> V_182 & V_248 ) ) ;
else if ( V_2 -> V_90 == 2 ) {
V_2 -> V_182 &= ~ 0xffff ;
V_2 -> V_182 |= V_246 ;
}
V_2 -> V_182 &= ~ V_251 ;
V_2 -> V_182 |= V_252 ;
return V_88 ;
}
static int F_101 ( struct V_1 * V_2 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_100 ( V_2 ) ;
case V_207 :
case V_99 :
case V_93 :
case V_38 :
default:
return V_235 ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned short V_34 , V_253 ;
struct V_35 V_197 , V_254 ;
const struct V_189 * V_6 = V_2 -> V_6 ;
T_5 V_194 = V_2 -> V_6 -> V_194 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_253 , & V_197 , NULL ,
V_89 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_90 , 2 ) ;
V_88 = F_78 ( V_2 , V_34 , V_89 , V_194 , false ,
& V_254 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_40 ( V_2 , V_2 -> V_22 . V_121 , & V_254 ) ;
if ( V_88 != V_87 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_68 ( V_2 , V_253 , & V_197 , 0 , V_89 ) ;
return V_88 ;
}
return V_88 ;
}
static int F_103 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_2 -> V_22 . V_121 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_88 ;
long int V_256 ;
V_256 = V_2 -> V_91 ;
V_88 = F_39 ( V_2 , V_2 -> V_22 . V_121 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_22 . V_121 = V_256 ;
V_88 = F_85 ( V_2 ) ;
return V_88 ;
}
static int F_105 ( struct V_1 * V_2 )
{
V_85 V_257 = V_2 -> V_25 . V_258 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_235 ;
if ( ( ( T_3 ) ( V_257 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_239 ) ) ||
( ( T_3 ) ( V_257 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_259 ) ) ) {
* F_2 ( V_2 , V_239 ) = ( T_3 ) ( V_257 >> 0 ) ;
* F_2 ( V_2 , V_259 ) = ( T_3 ) ( V_257 >> 32 ) ;
V_2 -> V_182 &= ~ V_222 ;
} else {
V_2 -> V_25 . V_23 = ( ( V_85 ) F_1 ( V_2 , V_181 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_153 ) ;
V_2 -> V_182 |= V_222 ;
}
return V_87 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 ;
V_88 = F_86 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
return F_39 ( V_2 , V_31 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 , V_244 ;
T_2 V_260 ;
int V_194 = V_2 -> V_6 -> V_194 ( V_2 ) ;
struct V_35 V_197 , V_254 ;
const struct V_189 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_260 , & V_197 , NULL ,
V_89 ) ;
V_88 = F_86 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_86 ( V_2 , & V_244 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_37 >= V_99 && ( V_244 & 3 ) > V_194 )
return V_235 ;
V_88 = F_78 ( V_2 , ( T_2 ) V_244 , V_89 , V_194 , false ,
& V_254 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_40 ( V_2 , V_31 , & V_254 ) ;
if ( V_88 != V_87 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_68 ( V_2 , V_260 , & V_197 , 0 , V_89 ) ;
}
return V_88 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_107 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_87 ;
}
static int F_109 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_140 = V_2 -> V_25 . V_121 ;
V_2 -> V_25 . V_121 = F_1 ( V_2 , V_239 ) ;
V_2 -> V_22 . V_140 = V_2 -> V_22 . V_121 ;
V_2 -> V_22 . V_121 = V_2 -> V_25 . V_140 ;
F_110 ( V_2 , V_261 ) ;
if ( V_2 -> V_182 & V_222 ) {
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_140 ;
} else {
V_2 -> V_25 . type = V_138 ;
V_2 -> V_25 . V_74 . V_9 = F_3 ( V_2 , V_239 ) ;
V_2 -> V_25 . V_121 = V_2 -> V_25 . V_140 ;
}
return V_87 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_121 ;
unsigned short V_34 ;
int V_88 ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_90 , 2 ) ;
V_88 = F_81 ( V_2 , V_34 , V_47 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_121 ;
return V_88 ;
}
static void
F_112 ( struct V_1 * V_2 ,
struct V_35 * V_244 , struct V_35 * V_36 )
{
V_244 -> V_94 = 0 ;
F_79 ( V_244 , 0 ) ;
V_244 -> V_46 = 1 ;
F_80 ( V_244 , 0xfffff ) ;
V_244 -> type = 0x0b ;
V_244 -> V_208 = 1 ;
V_244 -> V_198 = 0 ;
V_244 -> V_110 = 1 ;
V_244 -> V_41 = 1 ;
V_244 -> V_262 = 0 ;
F_79 ( V_36 , 0 ) ;
F_80 ( V_36 , 0xfffff ) ;
V_36 -> V_46 = 1 ;
V_36 -> V_208 = 1 ;
V_36 -> type = 0x03 ;
V_36 -> V_41 = 1 ;
V_36 -> V_198 = 0 ;
V_36 -> V_110 = 1 ;
V_36 -> V_94 = 0 ;
V_36 -> V_262 = 0 ;
}
static bool F_113 ( struct V_1 * V_2 )
{
T_3 V_263 , V_264 , V_265 , V_266 ;
V_263 = V_265 = 0 ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
return V_264 == V_268
&& V_265 == V_269
&& V_266 == V_270 ;
}
static bool F_114 ( struct V_1 * V_2 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
T_3 V_263 , V_264 , V_265 , V_266 ;
if ( V_2 -> V_37 == V_38 )
return true ;
V_263 = 0x00000000 ;
V_265 = 0x00000000 ;
V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
if ( V_264 == V_268 &&
V_265 == V_269 &&
V_266 == V_270 )
return false ;
if ( V_264 == V_271 &&
V_265 == V_272 &&
V_266 == V_273 )
return true ;
if ( V_264 == V_274 &&
V_265 == V_275 &&
V_266 == V_276 )
return true ;
return false ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_35 V_244 , V_36 ;
V_85 V_277 ;
T_2 V_278 , V_279 ;
V_85 V_95 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_207 )
return F_26 ( V_2 ) ;
if ( ! ( F_114 ( V_2 ) ) )
return F_26 ( V_2 ) ;
V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
F_112 ( V_2 , & V_244 , & V_36 ) ;
if ( ! ( V_95 & V_280 ) )
return F_26 ( V_2 ) ;
V_6 -> V_96 ( V_2 , V_281 , & V_277 ) ;
V_277 >>= 32 ;
V_278 = ( T_2 ) ( V_277 & 0xfffc ) ;
V_279 = ( T_2 ) ( V_277 + 8 ) ;
if ( V_95 & V_98 ) {
V_244 . V_41 = 0 ;
V_244 . V_94 = 1 ;
}
V_6 -> V_68 ( V_2 , V_278 , & V_244 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
* F_2 ( V_2 , V_181 ) = V_2 -> V_91 ;
if ( V_95 & V_98 ) {
#ifdef F_41
* F_2 ( V_2 , V_282 ) = V_2 -> V_182 ;
V_6 -> V_96 ( V_2 ,
V_2 -> V_37 == V_38 ?
V_283 : V_284 , & V_277 ) ;
V_2 -> V_91 = V_277 ;
V_6 -> V_96 ( V_2 , V_285 , & V_277 ) ;
V_2 -> V_182 &= ~ V_277 ;
V_2 -> V_182 |= V_252 ;
#endif
} else {
V_6 -> V_96 ( V_2 , V_281 , & V_277 ) ;
V_2 -> V_91 = ( T_3 ) V_277 ;
V_2 -> V_182 &= ~ ( V_240 | V_230 ) ;
}
return V_87 ;
}
static int F_116 ( struct V_1 * V_2 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_35 V_244 , V_36 ;
V_85 V_277 ;
T_2 V_278 , V_279 ;
V_85 V_95 = 0 ;
V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_2 -> V_37 == V_86 )
return F_24 ( V_2 , 0 ) ;
if ( ( V_2 -> V_37 != V_38 ) && ( V_95 & V_98 )
&& ! F_113 ( V_2 ) )
return F_26 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
return V_235 ;
F_112 ( V_2 , & V_244 , & V_36 ) ;
V_6 -> V_96 ( V_2 , V_286 , & V_277 ) ;
if ( ( V_277 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_182 &= ~ ( V_240 | V_230 ) ;
V_278 = ( T_2 ) V_277 & ~ V_287 ;
V_279 = V_278 + 8 ;
if ( V_95 & V_98 ) {
V_244 . V_41 = 0 ;
V_244 . V_94 = 1 ;
}
V_6 -> V_68 ( V_2 , V_278 , & V_244 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
V_6 -> V_96 ( V_2 , V_288 , & V_277 ) ;
V_2 -> V_91 = ( V_95 & V_98 ) ? V_277 : ( T_3 ) V_277 ;
V_6 -> V_96 ( V_2 , V_289 , & V_277 ) ;
* F_2 ( V_2 , V_43 ) = ( V_95 & V_98 ) ? V_277 :
( T_3 ) V_277 ;
return V_87 ;
}
static int F_117 ( struct V_1 * V_2 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_35 V_244 , V_36 ;
V_85 V_277 , V_290 , V_291 ;
int V_292 ;
T_2 V_278 = 0 , V_279 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_207 )
return F_24 ( V_2 , 0 ) ;
F_112 ( V_2 , & V_244 , & V_36 ) ;
if ( ( V_2 -> V_112 & 0x8 ) != 0x0 )
V_292 = V_38 ;
else
V_292 = V_93 ;
V_290 = F_1 ( V_2 , V_181 ) ;
V_291 = F_1 ( V_2 , V_259 ) ;
V_244 . V_198 = 3 ;
V_36 . V_198 = 3 ;
V_6 -> V_96 ( V_2 , V_286 , & V_277 ) ;
switch ( V_292 ) {
case V_93 :
V_278 = ( T_2 ) ( V_277 + 16 ) ;
if ( ( V_277 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_279 = ( T_2 ) ( V_277 + 24 ) ;
V_290 = ( T_3 ) V_290 ;
V_291 = ( T_3 ) V_291 ;
break;
case V_38 :
V_278 = ( T_2 ) ( V_277 + 32 ) ;
if ( V_277 == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_279 = V_278 + 8 ;
V_244 . V_41 = 0 ;
V_244 . V_94 = 1 ;
if ( F_35 ( V_290 ) ||
F_35 ( V_291 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
V_278 |= V_287 ;
V_279 |= V_287 ;
V_6 -> V_68 ( V_2 , V_278 , & V_244 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
V_2 -> V_91 = V_291 ;
* F_2 ( V_2 , V_43 ) = V_290 ;
return V_87 ;
}
static bool F_118 ( struct V_1 * V_2 )
{
int V_216 ;
if ( V_2 -> V_37 == V_86 )
return false ;
if ( V_2 -> V_37 == V_207 )
return true ;
V_216 = ( V_2 -> V_182 & V_217 ) >> V_218 ;
return V_2 -> V_6 -> V_194 ( V_2 ) > V_216 ;
}
static bool F_119 ( struct V_1 * V_2 ,
T_2 V_176 , T_2 V_214 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_35 V_293 ;
T_3 V_67 ;
int V_294 ;
T_2 V_295 , V_296 , V_297 , V_298 = V_176 & 0x7 ;
unsigned V_33 = ( 1 << V_214 ) - 1 ;
unsigned long V_299 ;
V_6 -> V_39 ( V_2 , & V_295 , & V_293 , & V_67 , V_209 ) ;
if ( ! V_293 . V_110 )
return false ;
if ( F_18 ( & V_293 ) < 103 )
return false ;
V_299 = F_75 ( & V_293 ) ;
#ifdef F_41
V_299 |= ( ( V_85 ) V_67 ) << 32 ;
#endif
V_294 = V_6 -> V_102 ( V_2 , V_299 + 102 , & V_296 , 2 , NULL ) ;
if ( V_294 != V_87 )
return false ;
if ( V_296 + V_176 / 8 > F_18 ( & V_293 ) )
return false ;
V_294 = V_6 -> V_102 ( V_2 , V_299 + V_296 + V_176 / 8 , & V_297 , 2 , NULL ) ;
if ( V_294 != V_87 )
return false ;
if ( ( V_297 >> V_298 ) & V_33 )
return false ;
return true ;
}
static bool F_120 ( struct V_1 * V_2 ,
T_2 V_176 , T_2 V_214 )
{
if ( V_2 -> V_300 )
return true ;
if ( F_118 ( V_2 ) )
if ( ! F_119 ( V_2 , V_176 , V_214 ) )
return false ;
V_2 -> V_300 = true ;
return true ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
V_302 -> V_303 = V_2 -> V_91 ;
V_302 -> V_304 = V_2 -> V_182 ;
V_302 -> V_305 = F_1 ( V_2 , V_239 ) ;
V_302 -> V_306 = F_1 ( V_2 , V_181 ) ;
V_302 -> V_307 = F_1 ( V_2 , V_259 ) ;
V_302 -> V_152 = F_1 ( V_2 , V_153 ) ;
V_302 -> V_308 = F_1 ( V_2 , V_43 ) ;
V_302 -> V_154 = F_1 ( V_2 , V_142 ) ;
V_302 -> V_155 = F_1 ( V_2 , V_156 ) ;
V_302 -> V_157 = F_1 ( V_2 , V_158 ) ;
V_302 -> V_309 = F_30 ( V_2 , V_310 ) ;
V_302 -> V_244 = F_30 ( V_2 , V_89 ) ;
V_302 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_302 -> V_311 = F_30 ( V_2 , V_149 ) ;
V_302 -> V_312 = F_30 ( V_2 , V_190 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
int V_204 ;
T_5 V_194 ;
V_2 -> V_91 = V_302 -> V_303 ;
V_2 -> V_182 = V_302 -> V_304 | 2 ;
* F_2 ( V_2 , V_239 ) = V_302 -> V_305 ;
* F_2 ( V_2 , V_181 ) = V_302 -> V_306 ;
* F_2 ( V_2 , V_259 ) = V_302 -> V_307 ;
* F_2 ( V_2 , V_153 ) = V_302 -> V_152 ;
* F_2 ( V_2 , V_43 ) = V_302 -> V_308 ;
* F_2 ( V_2 , V_142 ) = V_302 -> V_154 ;
* F_2 ( V_2 , V_156 ) = V_302 -> V_155 ;
* F_2 ( V_2 , V_158 ) = V_302 -> V_157 ;
F_31 ( V_2 , V_302 -> V_312 , V_190 ) ;
F_31 ( V_2 , V_302 -> V_309 , V_310 ) ;
F_31 ( V_2 , V_302 -> V_244 , V_89 ) ;
F_31 ( V_2 , V_302 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_302 -> V_311 , V_149 ) ;
V_194 = V_302 -> V_244 & 3 ;
V_204 = F_78 ( V_2 , V_302 -> V_312 , V_190 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_309 , V_310 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_244 , V_89 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_36 , V_40 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_311 , V_149 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
return V_87 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_2 V_313 , T_2 V_314 ,
T_1 V_315 , struct V_35 * V_254 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_301 V_316 ;
int V_204 ;
T_3 V_317 = F_75 ( V_254 ) ;
V_204 = V_6 -> V_102 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
F_121 ( V_2 , & V_316 ) ;
V_204 = V_6 -> V_193 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = V_6 -> V_102 ( V_2 , V_317 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
if ( V_314 != 0xffff ) {
V_316 . V_318 = V_314 ;
V_204 = V_6 -> V_193 ( V_2 , V_317 ,
& V_316 . V_318 ,
sizeof V_316 . V_318 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
}
return F_122 ( V_2 , & V_316 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_319 * V_302 )
{
V_302 -> V_31 = V_2 -> V_91 ;
V_302 -> V_182 = V_2 -> V_182 ;
V_302 -> V_263 = F_1 ( V_2 , V_239 ) ;
V_302 -> V_265 = F_1 ( V_2 , V_181 ) ;
V_302 -> V_266 = F_1 ( V_2 , V_259 ) ;
V_302 -> V_264 = F_1 ( V_2 , V_153 ) ;
V_302 -> V_320 = F_1 ( V_2 , V_43 ) ;
V_302 -> V_321 = F_1 ( V_2 , V_142 ) ;
V_302 -> V_322 = F_1 ( V_2 , V_156 ) ;
V_302 -> V_323 = F_1 ( V_2 , V_158 ) ;
V_302 -> V_309 = F_30 ( V_2 , V_310 ) ;
V_302 -> V_244 = F_30 ( V_2 , V_89 ) ;
V_302 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_302 -> V_311 = F_30 ( V_2 , V_149 ) ;
V_302 -> V_324 = F_30 ( V_2 , V_48 ) ;
V_302 -> V_325 = F_30 ( V_2 , V_206 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_319 * V_302 )
{
int V_204 ;
T_5 V_194 ;
if ( V_2 -> V_6 -> V_326 ( V_2 , 3 , V_302 -> V_327 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_91 = V_302 -> V_31 ;
V_2 -> V_182 = V_302 -> V_182 | 2 ;
* F_2 ( V_2 , V_239 ) = V_302 -> V_263 ;
* F_2 ( V_2 , V_181 ) = V_302 -> V_265 ;
* F_2 ( V_2 , V_259 ) = V_302 -> V_266 ;
* F_2 ( V_2 , V_153 ) = V_302 -> V_264 ;
* F_2 ( V_2 , V_43 ) = V_302 -> V_320 ;
* F_2 ( V_2 , V_142 ) = V_302 -> V_321 ;
* F_2 ( V_2 , V_156 ) = V_302 -> V_322 ;
* F_2 ( V_2 , V_158 ) = V_302 -> V_323 ;
F_31 ( V_2 , V_302 -> V_328 , V_190 ) ;
F_31 ( V_2 , V_302 -> V_309 , V_310 ) ;
F_31 ( V_2 , V_302 -> V_244 , V_89 ) ;
F_31 ( V_2 , V_302 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_302 -> V_311 , V_149 ) ;
F_31 ( V_2 , V_302 -> V_324 , V_48 ) ;
F_31 ( V_2 , V_302 -> V_325 , V_206 ) ;
if ( V_2 -> V_182 & V_329 ) {
V_2 -> V_37 = V_207 ;
V_194 = 3 ;
} else {
V_2 -> V_37 = V_93 ;
V_194 = V_302 -> V_244 & 3 ;
}
V_204 = F_78 ( V_2 , V_302 -> V_328 , V_190 ,
V_194 , true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_309 , V_310 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_244 , V_89 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_36 , V_40 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_311 , V_149 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_324 , V_48 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_78 ( V_2 , V_302 -> V_325 , V_206 , V_194 ,
true , NULL ) ;
if ( V_204 != V_87 )
return V_204 ;
return V_87 ;
}
static int F_126 ( struct V_1 * V_2 ,
T_2 V_313 , T_2 V_314 ,
T_1 V_315 , struct V_35 * V_254 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_319 V_316 ;
int V_204 ;
T_3 V_317 = F_75 ( V_254 ) ;
T_3 V_330 = F_127 ( struct V_319 , V_31 ) ;
T_3 V_331 = F_127 ( struct V_319 , V_328 ) ;
V_204 = V_6 -> V_102 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
F_124 ( V_2 , & V_316 ) ;
V_204 = V_6 -> V_193 ( V_2 , V_315 + V_330 , & V_316 . V_31 ,
V_331 - V_330 , & V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = V_6 -> V_102 ( V_2 , V_317 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
if ( V_314 != 0xffff ) {
V_316 . V_318 = V_314 ;
V_204 = V_6 -> V_193 ( V_2 , V_317 ,
& V_316 . V_318 ,
sizeof V_316 . V_318 ,
& V_2 -> V_52 ) ;
if ( V_204 != V_87 )
return V_204 ;
}
return F_125 ( V_2 , & V_316 ) ;
}
static int F_128 ( struct V_1 * V_2 ,
T_2 V_313 , int V_332 , int V_333 ,
bool V_334 , T_3 V_54 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
struct V_35 V_335 , V_336 ;
int V_204 ;
T_2 V_314 = F_30 ( V_2 , V_209 ) ;
T_1 V_315 =
V_6 -> V_49 ( V_2 , V_209 ) ;
T_3 V_337 ;
T_1 V_203 ;
V_204 = F_76 ( V_2 , V_313 , & V_336 , & V_203 ) ;
if ( V_204 != V_87 )
return V_204 ;
V_204 = F_76 ( V_2 , V_314 , & V_335 , & V_203 ) ;
if ( V_204 != V_87 )
return V_204 ;
if ( V_333 == V_338 ) {
if ( V_332 != - 1 ) {
struct V_35 V_339 ;
int V_198 ;
V_204 = F_73 ( V_2 , V_332 ,
& V_339 ) ;
if ( V_204 != V_87 )
return V_204 ;
V_198 = V_339 . V_198 ;
if ( ( V_313 & 3 ) > V_198 || V_6 -> V_194 ( V_2 ) > V_198 )
return F_24 ( V_2 , ( V_332 << 3 ) | 0x2 ) ;
}
}
V_337 = F_18 ( & V_336 ) ;
if ( ! V_336 . V_110 ||
( ( V_337 < 0x67 && ( V_336 . type & 8 ) ) ||
V_337 < 0x2b ) ) {
return F_27 ( V_2 , V_313 & 0xfffc ) ;
}
if ( V_333 == V_340 || V_333 == V_341 ) {
V_335 . type &= ~ ( 1 << 1 ) ;
F_77 ( V_2 , V_314 , & V_335 ) ;
}
if ( V_333 == V_340 )
V_2 -> V_182 = V_2 -> V_182 & ~ V_342 ;
if ( V_333 != V_343 && V_333 != V_338 )
V_314 = 0xffff ;
if ( V_336 . type & 8 )
V_204 = F_126 ( V_2 , V_313 , V_314 ,
V_315 , & V_336 ) ;
else
V_204 = F_123 ( V_2 , V_313 , V_314 ,
V_315 , & V_336 ) ;
if ( V_204 != V_87 )
return V_204 ;
if ( V_333 == V_343 || V_333 == V_338 )
V_2 -> V_182 = V_2 -> V_182 | V_342 ;
if ( V_333 != V_340 ) {
V_336 . type |= ( 1 << 1 ) ;
F_77 ( V_2 , V_313 , & V_336 ) ;
}
V_6 -> V_326 ( V_2 , 0 , V_6 -> V_124 ( V_2 , 0 ) | V_125 ) ;
V_6 -> V_68 ( V_2 , V_313 , & V_336 , 0 , V_209 ) ;
if ( V_334 ) {
V_2 -> V_90 = V_2 -> V_29 = ( V_336 . type & 8 ) ? 4 : 2 ;
V_2 -> V_211 = 0 ;
V_2 -> V_22 . V_121 = ( unsigned long ) V_54 ;
V_204 = F_85 ( V_2 ) ;
}
return V_204 ;
}
int F_129 ( struct V_1 * V_2 ,
T_2 V_313 , int V_332 , int V_333 ,
bool V_334 , T_3 V_54 )
{
int V_88 ;
F_6 ( V_2 ) ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_213 ;
V_88 = F_128 ( V_2 , V_313 , V_332 , V_333 ,
V_334 , V_54 ) ;
if ( V_88 == V_87 ) {
V_2 -> V_31 = V_2 -> V_91 ;
F_4 ( V_2 ) ;
}
return ( V_88 == V_235 ) ? V_344 : V_345 ;
}
static void F_130 ( struct V_1 * V_2 , int V_9 ,
struct V_119 * V_120 )
{
int V_346 = ( V_2 -> V_182 & V_183 ) ? - V_120 -> V_180 : V_120 -> V_180 ;
F_16 ( V_2 , V_9 , V_346 * V_120 -> V_27 ) ;
V_120 -> V_74 . V_162 . V_83 = F_14 ( V_2 , V_9 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
T_5 V_347 , V_348 ;
bool V_349 , V_350 , V_351 ;
V_350 = V_2 -> V_182 & V_352 ;
V_347 = V_2 -> V_25 . V_121 ;
V_348 = V_347 ;
V_351 = V_350 ;
V_350 = false ;
V_349 = V_2 -> V_182 & V_353 ;
if ( ( V_347 & 0x0f ) > 9 || V_349 ) {
V_347 -= 6 ;
V_350 = V_351 | ( V_347 >= 250 ) ;
V_349 = true ;
} else {
V_349 = false ;
}
if ( V_348 > 0x99 || V_351 ) {
V_347 -= 0x60 ;
V_350 = true ;
}
V_2 -> V_25 . V_121 = V_347 ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_110 ( V_2 , V_355 ) ;
V_2 -> V_182 &= ~ ( V_353 | V_352 ) ;
if ( V_350 )
V_2 -> V_182 |= V_352 ;
if ( V_349 )
V_2 -> V_182 |= V_353 ;
return V_87 ;
}
static int F_132 ( struct V_1 * V_2 )
{
T_5 V_347 , V_356 ;
if ( V_2 -> V_22 . V_121 == 0 )
return F_28 ( V_2 ) ;
V_347 = V_2 -> V_25 . V_121 & 0xff ;
V_356 = V_347 / V_2 -> V_22 . V_121 ;
V_347 %= V_2 -> V_22 . V_121 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_25 . V_121 & 0xffff0000 ) | V_347 | ( V_356 << 8 ) ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_110 ( V_2 , V_355 ) ;
return V_87 ;
}
static int F_133 ( struct V_1 * V_2 )
{
T_5 V_347 = V_2 -> V_25 . V_121 & 0xff ;
T_5 V_356 = ( V_2 -> V_25 . V_121 >> 8 ) & 0xff ;
V_347 = ( V_347 + ( V_356 * V_2 -> V_22 . V_121 ) ) & 0xff ;
V_2 -> V_25 . V_121 = ( V_2 -> V_25 . V_121 & 0xffff0000 ) | V_347 ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_110 ( V_2 , V_355 ) ;
return V_87 ;
}
static int F_134 ( struct V_1 * V_2 )
{
int V_88 ;
long V_100 = V_2 -> V_22 . V_121 ;
V_2 -> V_22 . V_121 = ( unsigned long ) V_2 -> V_91 ;
V_88 = F_42 ( V_2 , V_100 ) ;
if ( V_88 != V_87 )
return V_88 ;
return F_85 ( V_2 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
T_2 V_34 , V_260 ;
T_1 V_256 ;
int V_88 ;
struct V_35 V_197 , V_254 ;
const struct V_189 * V_6 = V_2 -> V_6 ;
int V_194 = V_2 -> V_6 -> V_194 ( V_2 ) ;
V_256 = V_2 -> V_91 ;
V_6 -> V_39 ( V_2 , & V_260 , & V_197 , NULL , V_89 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_90 , 2 ) ;
V_88 = F_78 ( V_2 , V_34 , V_89 , V_194 , false ,
& V_254 ) ;
if ( V_88 != V_87 )
return V_87 ;
V_88 = F_40 ( V_2 , V_2 -> V_22 . V_121 , & V_254 ) ;
if ( V_88 != V_87 )
goto V_357;
V_2 -> V_22 . V_121 = V_260 ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_357;
V_2 -> V_22 . V_121 = V_256 ;
V_88 = F_85 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_357;
return V_88 ;
V_357:
V_6 -> V_68 ( V_2 , V_260 , & V_197 , 0 , V_89 ) ;
return V_88 ;
}
static int F_136 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 ;
V_88 = F_86 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_39 ( V_2 , V_31 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_87 ;
}
static int F_137 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_121 = V_2 -> V_25 . V_121 ;
F_82 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_140 ;
V_2 -> V_211 = 1 ;
return V_87 ;
}
static int F_138 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_121 = V_2 -> V_233 . V_121 ;
return F_110 ( V_2 , V_358 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_138 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_74 . V_9 = F_3 ( V_2 , V_259 ) ;
V_2 -> V_25 . V_121 = ~ ( ( V_2 -> V_22 . V_121 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_87 ;
}
static int F_140 ( struct V_1 * V_2 )
{
V_85 V_359 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_360 , & V_359 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_359 ;
* F_2 ( V_2 , V_259 ) = V_359 >> 32 ;
return V_87 ;
}
static int F_141 ( struct V_1 * V_2 )
{
V_85 V_361 ;
if ( V_2 -> V_6 -> V_362 ( V_2 , F_1 ( V_2 , V_181 ) , & V_361 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_361 ;
* F_2 ( V_2 , V_259 ) = V_361 >> 32 ;
return V_87 ;
}
static int F_142 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_255 , V_2 -> V_22 . V_255 , sizeof( V_2 -> V_22 . V_255 ) ) ;
return V_87 ;
}
static int F_143 ( struct V_1 * V_2 )
{
T_3 V_264 , V_265 , V_266 , V_263 = 1 ;
T_2 V_363 ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
if ( ! ( V_265 & F_144 ( V_364 ) ) )
return F_26 ( V_2 ) ;
switch ( V_2 -> V_90 ) {
case 2 :
V_363 = ( T_2 ) V_2 -> V_22 . V_121 ;
V_2 -> V_25 . V_121 &= ~ 0xffffUL ;
V_2 -> V_25 . V_121 |= ( unsigned long ) F_145 ( V_363 ) ;
break;
case 4 :
V_2 -> V_25 . V_121 = F_146 ( ( T_3 ) V_2 -> V_22 . V_121 ) ;
break;
case 8 :
V_2 -> V_25 . V_121 = F_147 ( V_2 -> V_22 . V_121 ) ;
break;
default:
F_54 () ;
}
return V_87 ;
}
static int F_148 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_326 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_121 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_149 ( struct V_1 * V_2 )
{
unsigned long V_121 ;
if ( V_2 -> V_37 == V_38 )
V_121 = V_2 -> V_22 . V_121 & ~ 0ULL ;
else
V_121 = V_2 -> V_22 . V_121 & ~ 0U ;
if ( V_2 -> V_6 -> V_365 ( V_2 , V_2 -> V_19 , V_121 ) < 0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_85 V_277 ;
V_277 = ( T_3 ) F_1 ( V_2 , V_239 )
| ( ( V_85 ) F_1 ( V_2 , V_259 ) << 32 ) ;
if ( V_2 -> V_6 -> V_366 ( V_2 , F_1 ( V_2 , V_181 ) , V_277 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_151 ( struct V_1 * V_2 )
{
V_85 V_277 ;
if ( V_2 -> V_6 -> V_96 ( V_2 , F_1 ( V_2 , V_181 ) , & V_277 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_277 ;
* F_2 ( V_2 , V_259 ) = V_277 >> 32 ;
return V_87 ;
}
static int F_152 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_206 )
return F_26 ( V_2 ) ;
V_2 -> V_25 . V_121 = F_30 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_151 )
V_2 -> V_25 . V_27 = 2 ;
return V_87 ;
}
static int F_153 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
if ( V_2 -> V_19 == V_89 || V_2 -> V_19 > V_206 )
return F_26 ( V_2 ) ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_236 = V_237 ;
V_2 -> V_25 . type = V_213 ;
return F_81 ( V_2 , V_34 , V_2 -> V_19 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
V_2 -> V_25 . type = V_213 ;
return F_81 ( V_2 , V_34 , V_190 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
V_2 -> V_25 . type = V_213 ;
return F_81 ( V_2 , V_34 , V_209 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_2 -> V_22 . V_74 . V_162 , 1 , false , & V_79 ) ;
if ( V_88 == V_87 )
V_2 -> V_6 -> V_367 ( V_2 , V_79 ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_157 ( struct V_1 * V_2 )
{
T_1 V_368 ;
V_368 = V_2 -> V_6 -> V_124 ( V_2 , 0 ) ;
V_368 &= ~ V_125 ;
V_2 -> V_6 -> V_326 ( V_2 , 0 , V_368 ) ;
return V_87 ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_88 = V_2 -> V_6 -> V_369 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_159 ( struct V_1 * V_2 ,
void (* F_160)( struct V_1 * V_2 ,
struct V_186 * V_108 ) )
{
struct V_186 V_186 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_90 = 8 ;
F_160 ( V_2 , & V_186 ) ;
if ( V_2 -> V_90 == 2 ) {
V_2 -> V_90 = 4 ;
V_186 . V_113 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_213 ;
return F_69 ( V_2 , V_2 -> V_25 . V_74 . V_162 ,
& V_186 , 2 + V_2 -> V_90 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
return F_159 ( V_2 , V_2 -> V_6 -> V_191 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
return F_159 ( V_2 , V_2 -> V_6 -> V_188 ) ;
}
static int F_163 ( struct V_1 * V_2 , bool V_370 )
{
struct V_186 V_186 ;
int V_88 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_90 = 8 ;
V_88 = F_49 ( V_2 , V_2 -> V_22 . V_74 . V_162 ,
& V_186 . V_69 , & V_186 . V_113 ,
V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_37 == V_38 &&
F_35 ( V_186 . V_113 ) )
return F_24 ( V_2 , 0 ) ;
if ( V_370 )
V_2 -> V_6 -> V_371 ( V_2 , & V_186 ) ;
else
V_2 -> V_6 -> V_372 ( V_2 , & V_186 ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_164 ( struct V_1 * V_2 )
{
return F_163 ( V_2 , true ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = V_2 -> V_6 -> V_369 ( V_2 ) ;
V_2 -> V_25 . type = V_213 ;
return V_88 ;
}
static int F_166 ( struct V_1 * V_2 )
{
return F_163 ( V_2 , false ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_151 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_121 = V_2 -> V_6 -> V_124 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_168 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_326 ( V_2 , 0 , ( V_2 -> V_6 -> V_124 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_121 & 0x0f ) ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_169 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
F_16 ( V_2 , V_181 , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_181 ) ) != 0 ) &&
( V_2 -> V_130 == 0xe2 || F_50 ( V_2 -> V_130 ^ 0x5 , V_2 -> V_182 ) ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_88 ;
}
static int F_170 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
if ( F_13 ( V_2 , F_1 ( V_2 , V_181 ) ) == 0 )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_88 ;
}
static int F_171 ( struct V_1 * V_2 )
{
if ( ! F_71 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_121 ,
& V_2 -> V_25 . V_121 ) )
return V_373 ;
return V_87 ;
}
static int F_172 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_374 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_121 ,
& V_2 -> V_22 . V_121 , 1 ) ;
V_2 -> V_25 . type = V_213 ;
return V_87 ;
}
static int F_173 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_182 &= ~ V_118 ;
return V_87 ;
}
static int F_174 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_236 = V_375 ;
V_2 -> V_182 |= V_118 ;
return V_87 ;
}
static int F_175 ( struct V_1 * V_2 )
{
T_3 V_263 , V_264 , V_265 , V_266 ;
V_263 = F_1 ( V_2 , V_239 ) ;
V_265 = F_1 ( V_2 , V_181 ) ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
* F_2 ( V_2 , V_239 ) = V_263 ;
* F_2 ( V_2 , V_153 ) = V_264 ;
* F_2 ( V_2 , V_181 ) = V_265 ;
* F_2 ( V_2 , V_259 ) = V_266 ;
return V_87 ;
}
static int F_176 ( struct V_1 * V_2 )
{
T_3 V_115 ;
V_115 = V_219 | V_220 | V_221 | V_222 | V_223 ;
V_115 &= * F_3 ( V_2 , V_239 ) >> 8 ;
V_2 -> V_182 &= ~ 0xffUL ;
V_2 -> V_182 |= V_115 | V_376 ;
return V_87 ;
}
static int F_177 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_239 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_239 ) |= ( V_2 -> V_182 & 0xff ) << 8 ;
return V_87 ;
}
static int F_178 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_90 ) {
#ifdef F_41
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_87 ;
}
static int F_179 ( struct V_1 * V_2 )
{
return V_87 ;
}
static bool F_180 ( int V_3 )
{
switch ( V_3 ) {
case 0 :
case 2 ... 4 :
case 8 :
return true ;
default:
return false ;
}
}
static int F_181 ( struct V_1 * V_2 )
{
if ( ! F_180 ( V_2 -> V_19 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_85 V_377 = V_2 -> V_22 . V_23 ;
int V_378 = V_2 -> V_19 ;
V_85 V_95 = 0 ;
static V_85 V_379 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_380 ,
0 , 0 , 0 ,
V_381 ,
} ;
if ( ! F_180 ( V_378 ) )
return F_26 ( V_2 ) ;
if ( V_377 & V_379 [ V_378 ] )
return F_24 ( V_2 , 0 ) ;
switch ( V_378 ) {
case 0 : {
V_85 V_382 ;
if ( ( ( V_377 & V_383 ) && ! ( V_377 & V_384 ) ) ||
( ( V_377 & V_385 ) && ! ( V_377 & V_386 ) ) )
return F_24 ( V_2 , 0 ) ;
V_382 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ( V_377 & V_383 ) && ( V_95 & V_387 ) &&
! ( V_382 & V_388 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_85 V_389 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
V_389 = V_390 & ~ V_391 ;
if ( V_377 & V_389 )
return F_24 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ( V_95 & V_98 ) && ! ( V_377 & V_388 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
}
return V_87 ;
}
static int F_183 ( struct V_1 * V_2 )
{
unsigned long V_392 ;
V_2 -> V_6 -> V_393 ( V_2 , 7 , & V_392 ) ;
return V_392 & ( 1 << 13 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_394 = V_2 -> V_19 ;
V_85 V_382 ;
if ( V_394 > 7 )
return F_26 ( V_2 ) ;
V_382 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
if ( ( V_382 & V_395 ) && ( V_394 == 4 || V_394 == 5 ) )
return F_26 ( V_2 ) ;
if ( F_183 ( V_2 ) ) {
T_1 V_396 ;
V_2 -> V_6 -> V_393 ( V_2 , 6 , & V_396 ) ;
V_396 &= ~ 15 ;
V_396 |= V_397 | V_398 ;
V_2 -> V_6 -> V_365 ( V_2 , 6 , V_396 ) ;
return F_23 ( V_2 ) ;
}
return V_87 ;
}
static int F_185 ( struct V_1 * V_2 )
{
V_85 V_377 = V_2 -> V_22 . V_23 ;
int V_394 = V_2 -> V_19 ;
if ( ( V_394 == 6 || V_394 == 7 ) && ( V_377 & 0xffffffff00000000ULL ) )
return F_24 ( V_2 , 0 ) ;
return F_184 ( V_2 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
V_85 V_95 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ! ( V_95 & V_399 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_187 ( struct V_1 * V_2 )
{
V_85 V_400 = F_1 ( V_2 , V_239 ) ;
if ( V_400 & 0xffff000000000000ULL )
return F_24 ( V_2 , 0 ) ;
return F_186 ( V_2 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_85 V_382 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
if ( V_382 & V_401 && V_2 -> V_6 -> V_194 ( V_2 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_189 ( struct V_1 * V_2 )
{
V_85 V_382 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
V_85 V_290 = F_1 ( V_2 , V_181 ) ;
if ( ( ! ( V_382 & V_402 ) && V_2 -> V_6 -> V_194 ( V_2 ) ) ||
V_2 -> V_6 -> V_403 ( V_2 , V_290 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_190 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_191 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_120 ( V_2 , V_2 -> V_22 . V_121 , V_2 -> V_25 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_192 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_191 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_120 ( V_2 , V_2 -> V_25 . V_121 , V_2 -> V_22 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static unsigned F_193 ( struct V_1 * V_2 )
{
unsigned V_69 ;
V_69 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
if ( V_69 == 8 )
V_69 = 4 ;
return V_69 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_119 * V_120 ,
unsigned V_69 , bool V_404 )
{
int V_88 = V_87 ;
V_120 -> type = V_354 ;
V_120 -> V_27 = V_69 ;
V_120 -> V_74 . V_162 . V_83 = V_2 -> V_91 ;
switch ( V_120 -> V_27 ) {
case 1 :
V_120 -> V_121 = F_64 ( V_159 , V_2 ) ;
break;
case 2 :
V_120 -> V_121 = F_64 ( V_166 , V_2 ) ;
break;
case 4 :
V_120 -> V_121 = F_64 ( V_160 , V_2 ) ;
break;
case 8 :
V_120 -> V_121 = F_64 ( V_167 , V_2 ) ;
break;
}
if ( ! V_404 ) {
switch ( V_120 -> V_27 ) {
case 1 :
V_120 -> V_121 &= 0xff ;
break;
case 2 :
V_120 -> V_121 &= 0xffff ;
break;
case 4 :
V_120 -> V_121 &= 0xffffffff ;
break;
}
}
V_164:
return V_88 ;
}
static int F_195 ( struct V_1 * V_2 , struct V_119 * V_120 ,
unsigned V_41 )
{
int V_88 = V_87 ;
switch ( V_41 ) {
case V_405 :
F_61 ( V_2 , V_120 ) ;
break;
case V_406 :
V_88 = F_194 ( V_2 , V_120 , 1 , false ) ;
break;
case V_407 :
V_2 -> V_163 . V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_408:
* V_120 = V_2 -> V_163 ;
V_2 -> V_409 = V_120 ;
if ( V_2 -> V_41 & V_410 )
F_66 ( V_2 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_411 :
V_2 -> V_163 . V_27 = ( V_2 -> V_90 == 8 ) ? 16 : 8 ;
goto V_408;
case V_412 :
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_239 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_413 :
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 2 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_239 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_414 :
if ( V_2 -> V_41 & V_139 ) {
V_120 -> type = V_213 ;
break;
}
V_120 -> type = V_138 ;
V_120 -> V_27 = V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_259 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_415 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_162 . V_83 =
F_14 ( V_2 , V_158 ) ;
V_120 -> V_74 . V_162 . V_47 = V_310 ;
V_120 -> V_121 = 0 ;
V_120 -> V_180 = 1 ;
break;
case V_416 :
V_120 -> type = V_138 ;
V_120 -> V_27 = 2 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_259 ) ;
F_52 ( V_120 ) ;
break;
case V_417 :
V_120 -> type = V_354 ;
V_120 -> V_27 = 1 ;
V_120 -> V_121 = F_1 ( V_2 , V_181 ) & 0xff ;
break;
case V_418 :
V_88 = F_194 ( V_2 , V_120 , 1 , true ) ;
break;
case V_419 :
V_120 -> type = V_354 ;
V_120 -> V_27 = 1 ;
V_120 -> V_121 = 1 ;
break;
case V_420 :
V_88 = F_194 ( V_2 , V_120 , F_193 ( V_2 ) , true ) ;
break;
case V_421 :
V_88 = F_194 ( V_2 , V_120 , V_2 -> V_90 , true ) ;
break;
case V_422 :
V_2 -> V_163 . V_27 = 1 ;
if ( V_2 -> V_163 . type == V_138 ) {
V_2 -> V_163 . V_74 . V_9 = F_48 ( V_2 ,
V_2 -> V_20 , true ) ;
F_52 ( & V_2 -> V_163 ) ;
}
goto V_408;
case V_423 :
V_2 -> V_163 . V_27 = 2 ;
goto V_408;
case V_424 :
V_2 -> V_163 . V_27 = 4 ;
goto V_408;
case V_425 :
V_88 = F_194 ( V_2 , V_120 , 2 , false ) ;
break;
case V_426 :
V_88 = F_194 ( V_2 , V_120 , F_193 ( V_2 ) , false ) ;
break;
case V_427 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_162 . V_83 =
F_14 ( V_2 , V_156 ) ;
V_120 -> V_74 . V_162 . V_47 = V_2 -> V_428 ;
V_120 -> V_121 = 0 ;
V_120 -> V_180 = 1 ;
break;
case V_429 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_162 . V_83 =
F_13 ( V_2 ,
F_1 ( V_2 , V_153 ) +
( F_1 ( V_2 , V_239 ) & 0xff ) ) ;
V_120 -> V_74 . V_162 . V_47 = V_2 -> V_428 ;
V_120 -> V_121 = 0 ;
break;
case V_430 :
V_120 -> type = V_354 ;
V_120 -> V_74 . V_162 . V_83 = V_2 -> V_91 ;
V_120 -> V_27 = V_2 -> V_90 + 2 ;
F_196 ( V_120 -> V_255 , V_120 -> V_27 , V_2 ) ;
break;
case V_431 :
V_2 -> V_163 . V_27 = V_2 -> V_90 + 2 ;
goto V_408;
case V_432 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_310 ;
break;
case V_433 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_89 ;
break;
case V_434 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_40 ;
break;
case V_435 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_149 ;
break;
case V_436 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_48 ;
break;
case V_437 :
V_120 -> type = V_354 ;
V_120 -> V_121 = V_206 ;
break;
case V_438 :
default:
V_120 -> type = V_213 ;
break;
}
V_164:
return V_88 ;
}
int F_197 ( struct V_1 * V_2 , void * V_439 , int V_440 )
{
int V_88 = V_87 ;
int V_37 = V_2 -> V_37 ;
int V_441 , V_442 , V_443 , V_444 ;
bool V_445 = false ;
bool V_446 = false ;
struct V_447 V_447 ;
V_2 -> V_163 . type = V_213 ;
V_2 -> V_409 = NULL ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_77 . V_108 = V_2 -> V_77 . V_101 ;
V_2 -> V_77 . V_105 = V_2 -> V_77 . V_101 + V_440 ;
V_2 -> V_448 = 1 ;
if ( V_440 > 0 )
memcpy ( V_2 -> V_77 . V_101 , V_439 , V_440 ) ;
else {
V_88 = F_44 ( V_2 , 1 ) ;
if ( V_88 != V_87 )
return V_88 ;
}
switch ( V_37 ) {
case V_86 :
case V_207 :
case V_99 :
V_441 = V_442 = 2 ;
break;
case V_93 :
V_441 = V_442 = 4 ;
break;
#ifdef F_41
case V_38 :
V_441 = 4 ;
V_442 = 8 ;
break;
#endif
default:
return V_344 ;
}
V_2 -> V_90 = V_441 ;
V_2 -> V_29 = V_442 ;
for (; ; ) {
switch ( V_2 -> V_130 = F_64 ( T_5 , V_2 ) ) {
case 0x66 :
V_445 = true ;
V_2 -> V_90 = V_441 ^ 6 ;
break;
case 0x67 :
if ( V_37 == V_38 )
V_2 -> V_29 = V_442 ^ 12 ;
else
V_2 -> V_29 = V_442 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_446 = true ;
V_2 -> V_428 = ( V_2 -> V_130 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_446 = true ;
V_2 -> V_428 = V_2 -> V_130 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_37 != V_38 )
goto V_449;
V_2 -> V_112 = V_2 -> V_130 ;
continue;
case 0xf0 :
V_2 -> V_211 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_130 ;
break;
default:
goto V_449;
}
V_2 -> V_112 = 0 ;
}
V_449:
if ( V_2 -> V_112 & 8 )
V_2 -> V_90 = 8 ;
V_447 = V_450 [ V_2 -> V_130 ] ;
if ( V_2 -> V_130 == 0x0f ) {
V_2 -> V_448 = 2 ;
V_2 -> V_130 = F_64 ( T_5 , V_2 ) ;
V_447 = V_451 [ V_2 -> V_130 ] ;
if ( V_2 -> V_130 == 0x38 ) {
V_2 -> V_448 = 3 ;
V_2 -> V_130 = F_64 ( T_5 , V_2 ) ;
V_447 = V_452 [ V_2 -> V_130 ] ;
}
}
V_2 -> V_41 = V_447 . V_115 ;
if ( V_2 -> V_41 & V_129 )
V_2 -> V_148 = F_64 ( T_5 , V_2 ) ;
if ( V_2 -> V_448 == 1 && ( V_2 -> V_130 == 0xc5 || V_2 -> V_130 == 0xc4 ) &&
( V_37 == V_38 || ( V_2 -> V_148 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_41 = V_453 ;
}
while ( V_2 -> V_41 & V_454 ) {
switch ( V_2 -> V_41 & V_454 ) {
case V_455 :
V_443 = ( V_2 -> V_148 >> 3 ) & 7 ;
V_447 = V_447 . V_456 . V_457 [ V_443 ] ;
break;
case V_458 :
V_443 = ( V_2 -> V_148 >> 3 ) & 7 ;
if ( ( V_2 -> V_148 >> 6 ) == 3 )
V_447 = V_447 . V_456 . V_459 -> V_460 [ V_443 ] ;
else
V_447 = V_447 . V_456 . V_459 -> V_461 [ V_443 ] ;
break;
case V_462 :
V_443 = V_2 -> V_148 & 7 ;
V_447 = V_447 . V_456 . V_457 [ V_443 ] ;
break;
case V_463 :
if ( V_2 -> V_17 && V_445 )
return V_344 ;
V_444 = V_445 ? 0x66 : V_2 -> V_17 ;
switch ( V_444 ) {
case 0x00 : V_447 = V_447 . V_456 . V_464 -> V_465 ; break;
case 0x66 : V_447 = V_447 . V_456 . V_464 -> V_466 ; break;
case 0xf2 : V_447 = V_447 . V_456 . V_464 -> V_467 ; break;
case 0xf3 : V_447 = V_447 . V_456 . V_464 -> V_468 ; break;
}
break;
case V_469 :
if ( V_2 -> V_148 > 0xbf )
V_447 = V_447 . V_456 . V_470 -> V_471 [ V_2 -> V_148 - 0xc0 ] ;
else
V_447 = V_447 . V_456 . V_470 -> V_120 [ ( V_2 -> V_148 >> 3 ) & 7 ] ;
break;
case V_472 :
if ( ( V_2 -> V_148 >> 6 ) == 3 )
V_447 = V_447 . V_456 . V_473 -> V_460 ;
else
V_447 = V_447 . V_456 . V_473 -> V_461 ;
break;
default:
return V_344 ;
}
V_2 -> V_41 &= ~ ( V_85 ) V_454 ;
V_2 -> V_41 |= V_447 . V_115 ;
}
if ( V_2 -> V_41 == 0 )
return V_344 ;
V_2 -> V_474 = V_447 . V_456 . V_474 ;
if ( F_45 ( V_2 -> V_475 ) && F_33 ( ! ( V_2 -> V_41 & V_476 ) ) )
return V_344 ;
if ( F_45 ( V_2 -> V_41 &
( V_453 | V_477 | V_478 | V_131 | V_135 | V_479 | V_480 | V_481 |
V_482 ) ) ) {
V_2 -> V_483 = V_447 . V_483 ;
V_2 -> V_12 = V_447 . V_12 ;
if ( V_2 -> V_41 & V_453 )
return V_344 ;
if ( V_37 == V_38 ) {
if ( V_2 -> V_90 == 4 && ( V_2 -> V_41 & V_477 ) )
V_2 -> V_90 = 8 ;
else if ( V_2 -> V_41 & V_481 )
V_2 -> V_90 = 8 ;
}
if ( V_2 -> V_41 & V_478 ) {
if ( V_37 == V_38 )
V_2 -> V_90 = 8 ;
else
V_2 -> V_90 = 4 ;
}
if ( ( V_2 -> V_41 & V_482 ) && V_2 -> V_90 == 2 )
V_2 -> V_90 = 4 ;
if ( V_2 -> V_41 & V_131 )
V_2 -> V_90 = 16 ;
else if ( V_2 -> V_41 & V_135 )
V_2 -> V_90 = 8 ;
}
if ( V_2 -> V_41 & V_129 ) {
V_88 = F_63 ( V_2 , & V_2 -> V_163 ) ;
if ( ! V_446 ) {
V_446 = true ;
V_2 -> V_428 = V_2 -> V_143 ;
}
} else if ( V_2 -> V_41 & V_484 )
V_88 = F_65 ( V_2 , & V_2 -> V_163 ) ;
if ( V_88 != V_87 )
goto V_164;
if ( ! V_446 )
V_2 -> V_428 = V_149 ;
V_2 -> V_163 . V_74 . V_162 . V_47 = V_2 -> V_428 ;
V_88 = F_195 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_41 >> V_485 ) & V_486 ) ;
if ( V_88 != V_87 )
goto V_164;
V_88 = F_195 ( V_2 , & V_2 -> V_233 , ( V_2 -> V_41 >> V_487 ) & V_486 ) ;
if ( V_88 != V_87 )
goto V_164;
V_88 = F_195 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_41 >> V_488 ) & V_486 ) ;
if ( V_2 -> V_161 )
V_2 -> V_409 -> V_74 . V_162 . V_83 = F_13 ( V_2 ,
V_2 -> V_409 -> V_74 . V_162 . V_83 + V_2 -> V_91 ) ;
V_164:
return ( V_88 != V_87 ) ? V_344 : V_345 ;
}
bool F_198 ( struct V_1 * V_2 )
{
return V_2 -> V_41 & V_489 ;
}
static bool F_199 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_130 == 0xa6 ) || ( V_2 -> V_130 == 0xa7 ) ||
( V_2 -> V_130 == 0xae ) || ( V_2 -> V_130 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_490 ) &&
( ( V_2 -> V_182 & V_222 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_491 ) &&
( ( V_2 -> V_182 & V_222 ) == V_222 ) ) ) )
return true ;
return false ;
}
static int F_200 ( struct V_1 * V_2 )
{
bool V_492 = false ;
V_2 -> V_6 -> V_122 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_123 ( V_2 ) ;
if ( F_45 ( V_492 ) )
return F_21 ( V_2 , V_493 , 0 , false ) ;
return V_87 ;
}
static void F_201 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
if ( V_120 -> type == V_136 )
F_56 ( V_2 , & V_120 -> V_212 , V_120 -> V_74 . V_137 ) ;
}
static int F_110 ( struct V_1 * V_2 , void (* F_51)( struct F_110 * ) )
{
T_1 V_115 = ( V_2 -> V_182 & V_117 ) | V_118 ;
if ( ! ( V_2 -> V_41 & V_139 ) )
F_51 += F_202 ( V_2 -> V_25 . V_27 ) * V_494 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_182 = ( V_2 -> V_182 & ~ V_117 ) | ( V_115 & V_117 ) ;
if ( ! F_51 )
return F_28 ( V_2 ) ;
return V_87 ;
}
void F_203 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_161 , 0 ,
( void * ) & V_2 -> V_148 - ( void * ) & V_2 -> V_161 ) ;
V_2 -> V_177 . V_171 = 0 ;
V_2 -> V_177 . V_105 = 0 ;
V_2 -> V_170 . V_105 = 0 ;
}
int F_204 ( struct V_1 * V_2 )
{
const struct V_189 * V_6 = V_2 -> V_6 ;
int V_88 = V_87 ;
int V_495 = V_2 -> V_25 . type ;
V_2 -> V_170 . V_171 = 0 ;
if ( V_2 -> V_211 && ( ! ( V_2 -> V_41 & V_496 ) || V_2 -> V_25 . type != V_151 ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_164;
}
if ( ( V_2 -> V_41 & V_497 ) == V_498 && V_2 -> V_22 . type != V_151 ) {
V_88 = F_26 ( V_2 ) ;
goto V_164;
}
if ( F_45 ( V_2 -> V_41 &
( V_499 | V_500 | V_131 | V_135 | V_479 | V_480 | V_501 | V_502 | String ) ) ) {
if ( ( V_2 -> V_37 == V_38 && ( V_2 -> V_41 & V_499 ) ) ||
( V_2 -> V_41 & V_500 ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_164;
}
if ( ( ( V_2 -> V_41 & ( V_131 | V_135 ) ) && ( ( V_6 -> V_124 ( V_2 , 0 ) & V_126 ) ) )
|| ( ( V_2 -> V_41 & V_131 ) && ! ( V_6 -> V_124 ( V_2 , 4 ) & V_503 ) ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_164;
}
if ( ( V_2 -> V_41 & ( V_131 | V_135 ) ) && ( V_6 -> V_124 ( V_2 , 0 ) & V_125 ) ) {
V_88 = F_29 ( V_2 ) ;
goto V_164;
}
if ( V_2 -> V_41 & V_135 ) {
V_88 = F_200 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_164;
F_201 ( V_2 , & V_2 -> V_22 ) ;
F_201 ( V_2 , & V_2 -> V_233 ) ;
if ( ! ( V_2 -> V_41 & V_504 ) )
F_201 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_45 ( V_2 -> V_505 ) && ( V_2 -> V_41 & V_479 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_506 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( ( V_2 -> V_41 & V_502 ) && V_2 -> V_37 < V_99 ) {
V_88 = F_26 ( V_2 ) ;
goto V_164;
}
if ( ( V_2 -> V_41 & V_501 ) && V_6 -> V_194 ( V_2 ) ) {
if ( V_2 -> V_41 & V_507 )
V_88 = F_26 ( V_2 ) ;
else
V_88 = F_24 ( V_2 , 0 ) ;
goto V_164;
}
if ( V_2 -> V_41 & V_480 ) {
V_88 = V_2 -> V_483 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( F_45 ( V_2 -> V_505 ) && ( V_2 -> V_41 & V_479 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_508 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_181 ) ) == 0 ) {
V_2 -> V_31 = V_2 -> V_91 ;
V_2 -> V_182 &= ~ V_247 ;
goto V_164;
}
}
}
if ( ( V_2 -> V_22 . type == V_151 ) && ! ( V_2 -> V_41 & V_509 ) ) {
V_88 = F_68 ( V_2 , V_2 -> V_22 . V_74 . V_162 ,
V_2 -> V_22 . V_255 , V_2 -> V_22 . V_27 ) ;
if ( V_88 != V_87 )
goto V_164;
V_2 -> V_22 . V_258 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_233 . type == V_151 ) {
V_88 = F_68 ( V_2 , V_2 -> V_233 . V_74 . V_162 ,
& V_2 -> V_233 . V_121 , V_2 -> V_233 . V_27 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( ( V_2 -> V_41 & V_510 ) == V_511 )
goto V_512;
if ( ( V_2 -> V_25 . type == V_151 ) && ! ( V_2 -> V_41 & V_504 ) ) {
V_88 = F_68 ( V_2 , V_2 -> V_25 . V_74 . V_162 ,
& V_2 -> V_25 . V_121 , V_2 -> V_25 . V_27 ) ;
if ( V_88 != V_87 )
goto V_164;
}
V_2 -> V_25 . V_140 = V_2 -> V_25 . V_121 ;
V_512:
if ( F_45 ( V_2 -> V_505 ) && ( V_2 -> V_41 & V_479 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_513 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) )
V_2 -> V_182 |= V_247 ;
else
V_2 -> V_182 &= ~ V_247 ;
if ( V_2 -> V_474 ) {
if ( V_2 -> V_41 & V_514 ) {
void (* F_51)( struct F_110 * ) = ( void * ) V_2 -> V_474 ;
V_88 = F_110 ( V_2 , F_51 ) ;
if ( V_88 != V_87 )
goto V_164;
goto F_83;
}
V_88 = V_2 -> V_474 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_164;
goto F_83;
}
if ( V_2 -> V_448 == 2 )
goto V_515;
else if ( V_2 -> V_448 == 3 )
goto V_516;
switch ( V_2 -> V_130 ) {
case 0x63 :
if ( V_2 -> V_37 != V_38 )
goto V_517;
V_2 -> V_25 . V_121 = ( V_160 ) V_2 -> V_22 . V_121 ;
break;
case 0x70 ... 0x7f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_182 ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_74 . V_162 . V_83 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_74 . V_9 == F_3 ( V_2 , V_239 ) )
V_2 -> V_25 . type = V_213 ;
else
V_88 = F_137 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_90 ) {
case 2 : V_2 -> V_25 . V_121 = ( V_159 ) V_2 -> V_25 . V_121 ; break;
case 4 : V_2 -> V_25 . V_121 = ( V_166 ) V_2 -> V_25 . V_121 ; break;
case 8 : V_2 -> V_25 . V_121 = ( V_160 ) V_2 -> V_25 . V_121 ; break;
}
break;
case 0xcc :
V_88 = F_99 ( V_2 , 3 ) ;
break;
case 0xcd :
V_88 = F_99 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0xce :
if ( V_2 -> V_182 & V_224 )
V_88 = F_99 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
V_2 -> V_25 . type = V_213 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_518 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_182 ^= V_219 ;
break;
case 0xf8 :
V_2 -> V_182 &= ~ V_219 ;
break;
case 0xf9 :
V_2 -> V_182 |= V_219 ;
break;
case 0xfc :
V_2 -> V_182 &= ~ V_183 ;
break;
case 0xfd :
V_2 -> V_182 |= V_183 ;
break;
default:
goto V_517;
}
if ( V_88 != V_87 )
goto V_164;
F_83:
if ( V_2 -> V_41 & V_519 ) {
F_205 ( V_2 -> V_22 . type == V_151 || V_2 -> V_22 . type == V_184 ) ;
V_88 = F_83 ( V_2 , & V_2 -> V_22 ) ;
if ( V_88 != V_87 )
goto V_164;
}
if ( ! ( V_2 -> V_41 & V_520 ) ) {
V_88 = F_83 ( V_2 , & V_2 -> V_25 ) ;
if ( V_88 != V_87 )
goto V_164;
}
V_2 -> V_25 . type = V_495 ;
if ( ( V_2 -> V_41 & V_497 ) == V_521 )
F_130 ( V_2 , V_156 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_41 & V_510 ) == V_522 )
F_130 ( V_2 , V_158 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
unsigned int V_180 ;
struct V_168 * V_294 = & V_2 -> V_177 ;
if ( ( V_2 -> V_41 & V_497 ) == V_521 )
V_180 = V_2 -> V_22 . V_180 ;
else
V_180 = V_2 -> V_25 . V_180 ;
F_16 ( V_2 , V_181 , - V_180 ) ;
if ( ! F_199 ( V_2 ) ) {
if ( ( V_294 -> V_105 != 0 || F_1 ( V_2 , V_181 ) & 0x3ff ) &&
( V_294 -> V_105 == 0 || V_294 -> V_105 != V_294 -> V_171 ) ) {
V_2 -> V_170 . V_105 = 0 ;
F_4 ( V_2 ) ;
return V_523 ;
}
goto V_164;
}
V_2 -> V_182 &= ~ V_247 ;
}
V_2 -> V_31 = V_2 -> V_91 ;
V_164:
if ( V_88 == V_56 ) {
F_22 ( V_2 -> V_52 . V_53 > 0x1f ) ;
V_2 -> V_524 = true ;
}
if ( V_88 == V_525 )
return V_526 ;
if ( V_88 == V_87 )
F_4 ( V_2 ) ;
return ( V_88 == V_235 ) ? V_344 : V_345 ;
V_515:
switch ( V_2 -> V_130 ) {
case 0x09 :
( V_2 -> V_6 -> V_527 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_121 = V_6 -> V_124 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_393 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_121 ) ;
break;
case 0x40 ... 0x4f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_182 ) )
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_121 ;
else if ( V_2 -> V_37 != V_38 ||
V_2 -> V_90 != 4 )
V_2 -> V_25 . type = V_213 ;
break;
case 0x80 ... 0x8f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_182 ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_121 = F_50 ( V_2 -> V_130 , V_2 -> V_182 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_22 . V_27 == 1 ) ? ( T_5 ) V_2 -> V_22 . V_121
: ( T_2 ) V_2 -> V_22 . V_121 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_159 ) V_2 -> V_22 . V_121 :
( V_166 ) V_2 -> V_22 . V_121 ;
break;
default:
goto V_517;
}
V_516:
if ( V_88 != V_87 )
goto V_164;
goto F_83;
V_517:
return V_344 ;
}
void F_206 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
