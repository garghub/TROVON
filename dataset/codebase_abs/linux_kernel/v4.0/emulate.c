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
if ( V_82 == 0xffffffff )
* V_75 = ~ 0u ;
else {
* V_75 = ( V_85 ) V_82 + 1 - V_74 . V_83 ;
if ( V_69 > * V_75 )
goto V_84;
}
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
int V_88 ;
#ifdef F_41
if ( V_2 -> V_37 >= V_93 ) {
if ( V_92 -> V_94 ) {
V_85 V_95 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
V_37 = V_38 ;
} else
V_37 = V_99 ;
}
#endif
if ( V_37 == V_93 || V_37 == V_99 )
V_37 = V_92 -> V_41 ? V_99 : V_93 ;
V_88 = F_38 ( V_2 , V_25 , V_37 ) ;
if ( V_88 == V_87 )
V_2 -> V_37 = V_37 ;
return V_88 ;
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
if ( ( V_2 -> V_41 & V_161 ) &&
V_141 == V_43 )
V_147 += V_2 -> V_90 ;
}
if ( V_145 != 4 )
V_147 += F_1 ( V_2 , V_145 ) << V_146 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_147 += F_64 ( V_160 , V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_162 = 1 ;
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
V_120 -> V_74 . V_163 . V_83 = V_147 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_164 . V_74 . V_163 . V_83 = ( T_3 ) V_2 -> V_164 . V_74 . V_163 . V_83 ;
V_165:
return V_88 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
int V_88 = V_87 ;
V_120 -> type = V_151 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_120 -> V_74 . V_163 . V_83 = F_64 ( T_2 , V_2 ) ;
break;
case 4 :
V_120 -> V_74 . V_163 . V_83 = F_64 ( T_3 , V_2 ) ;
break;
case 8 :
V_120 -> V_74 . V_163 . V_83 = F_64 ( V_85 , V_2 ) ;
break;
}
V_165:
return V_88 ;
}
static void F_66 ( struct V_1 * V_2 )
{
long V_166 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_151 && V_2 -> V_22 . type == V_138 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_166 = ( V_167 ) V_2 -> V_22 . V_121 & ( V_167 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_166 = ( V_160 ) V_2 -> V_22 . V_121 & ( V_160 ) V_33 ;
else
V_166 = ( V_168 ) V_2 -> V_22 . V_121 & ( V_168 ) V_33 ;
V_2 -> V_25 . V_74 . V_163 . V_83 = F_13 ( V_2 ,
V_2 -> V_25 . V_74 . V_163 . V_83 + ( V_166 >> 3 ) ) ;
}
V_2 -> V_22 . V_121 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_74 , void * V_32 , unsigned V_69 )
{
int V_88 ;
struct V_169 * V_170 = & V_2 -> V_171 ;
if ( V_170 -> V_172 < V_170 -> V_105 )
goto V_173;
F_22 ( ( V_170 -> V_105 + V_69 ) >= sizeof( V_170 -> V_101 ) ) ;
V_88 = V_2 -> V_6 -> F_67 ( V_2 , V_74 , V_170 -> V_101 + V_170 -> V_105 , V_69 ,
& V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_170 -> V_105 += V_69 ;
V_173:
memcpy ( V_32 , V_170 -> V_101 + V_170 -> V_172 , V_69 ) ;
V_170 -> V_172 += V_69 ;
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
return V_2 -> V_6 -> V_174 ( V_2 , V_79 , V_101 , V_69 ,
& V_2 -> V_52 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_73 V_74 ,
const void * V_175 , const void * V_101 ,
unsigned V_69 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_74 , V_69 , true , & V_79 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_176 ( V_2 , V_79 , V_175 , V_101 ,
V_69 , & V_2 -> V_52 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_69 , unsigned short V_177 ,
void * V_32 )
{
struct V_169 * V_88 = & V_2 -> V_178 ;
if ( V_88 -> V_172 == V_88 -> V_105 ) {
unsigned int V_179 , V_180 ;
unsigned int V_181 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_182 ) ) : 1 ;
V_179 = ( V_2 -> V_183 & V_184 ) ?
F_46 ( F_1 ( V_2 , V_158 ) ) :
V_106 - F_46 ( F_1 ( V_2 , V_158 ) ) ;
V_180 = F_72 ( V_179 , ( unsigned int ) sizeof( V_88 -> V_101 ) / V_69 , V_181 ) ;
if ( V_180 == 0 )
V_180 = 1 ;
V_88 -> V_172 = V_88 -> V_105 = 0 ;
if ( ! V_2 -> V_6 -> F_71 ( V_2 , V_69 , V_177 , V_88 -> V_101 , V_180 ) )
return 0 ;
V_88 -> V_105 = V_180 * V_69 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) &&
! ( V_2 -> V_183 & V_184 ) ) {
V_2 -> V_25 . V_101 = V_88 -> V_101 + V_88 -> V_172 ;
V_2 -> V_25 . type = V_185 ;
V_2 -> V_25 . V_181 = ( V_88 -> V_105 - V_88 -> V_172 ) / V_69 ;
V_88 -> V_172 = V_88 -> V_105 ;
} else {
memcpy ( V_32 , V_88 -> V_101 + V_88 -> V_172 , V_69 ) ;
V_88 -> V_172 += V_69 ;
}
return 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_186 , struct V_35 * V_44 )
{
struct V_187 V_188 ;
T_1 V_74 ;
V_2 -> V_6 -> V_189 ( V_2 , & V_188 ) ;
if ( V_188 . V_69 < V_186 * 8 + 7 )
return F_24 ( V_2 , V_186 << 3 | 0x2 ) ;
V_74 = V_188 . V_113 + V_186 * 8 ;
return V_2 -> V_6 -> V_102 ( V_2 , V_74 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_187 * V_188 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
T_3 V_67 = 0 ;
if ( V_65 & 1 << 2 ) {
struct V_35 V_44 ;
T_2 V_34 ;
memset ( V_188 , 0 , sizeof *V_188 ) ;
if ( ! V_6 -> V_39 ( V_2 , & V_34 , & V_44 , & V_67 ,
V_191 ) )
return;
V_188 -> V_69 = F_18 ( & V_44 ) ;
V_188 -> V_113 = F_75 ( & V_44 ) | ( ( V_85 ) V_67 << 32 ) ;
} else
V_6 -> V_192 ( V_2 , V_188 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
T_2 V_65 , T_1 * V_193 )
{
struct V_187 V_188 ;
T_2 V_186 = V_65 >> 3 ;
T_1 V_74 ;
F_74 ( V_2 , V_65 , & V_188 ) ;
if ( V_188 . V_69 < V_186 * 8 + 7 )
return F_24 ( V_2 , V_65 & 0xfffc ) ;
V_74 = V_188 . V_113 + V_186 * 8 ;
#ifdef F_41
if ( V_74 >> 32 != 0 ) {
V_85 V_95 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ! ( V_95 & V_98 ) )
V_74 &= ( T_3 ) - 1 ;
}
#endif
* V_193 = V_74 ;
return V_87 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_35 * V_44 ,
T_1 * V_193 )
{
int V_88 ;
V_88 = F_76 ( V_2 , V_65 , V_193 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_102 ( V_2 , * V_193 , V_44 , sizeof( * V_44 ) ,
& V_2 -> V_52 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
T_2 V_65 , struct V_35 * V_44 )
{
int V_88 ;
T_1 V_74 ;
V_88 = F_76 ( V_2 , V_65 , & V_74 ) ;
if ( V_88 != V_87 )
return V_88 ;
return V_2 -> V_6 -> V_194 ( V_2 , V_74 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
T_2 V_65 , int V_47 , T_5 V_195 ,
enum V_196 V_197 ,
struct V_35 * V_44 )
{
struct V_35 V_198 , V_199 ;
T_5 V_200 , V_201 ;
unsigned V_202 = V_59 ;
T_3 V_203 = 0 ;
bool V_204 = ! ( V_65 & ~ 0x3 ) ;
T_1 V_205 ;
int V_206 ;
T_2 V_66 ;
T_3 V_67 = 0 ;
memset ( & V_198 , 0 , sizeof V_198 ) ;
if ( V_2 -> V_37 == V_86 ) {
V_2 -> V_6 -> V_39 ( V_2 , & V_66 , & V_198 , NULL , V_47 ) ;
F_80 ( & V_198 , V_65 << 4 ) ;
goto V_207;
} else if ( V_47 <= V_208 && V_2 -> V_37 == V_209 ) {
F_80 ( & V_198 , V_65 << 4 ) ;
F_81 ( & V_198 , 0xffff ) ;
V_198 . type = 3 ;
V_198 . V_110 = 1 ;
V_198 . V_210 = 1 ;
V_198 . V_200 = 3 ;
goto V_207;
}
V_201 = V_65 & 3 ;
if ( ( V_47 == V_89
|| ( V_47 == V_40
&& ( V_2 -> V_37 != V_38 || V_201 != V_195 ) )
|| V_47 == V_211 )
&& V_204 )
goto V_52;
if ( V_47 == V_211 && ( V_65 & ( 1 << 2 ) ) )
goto V_52;
if ( V_204 )
goto V_207;
V_206 = F_77 ( V_2 , V_65 , & V_198 , & V_205 ) ;
if ( V_206 != V_87 )
return V_206 ;
V_203 = V_65 & 0xfffc ;
V_202 = ( V_197 == V_212 ) ? V_62 :
V_59 ;
if ( V_47 <= V_208 && ! V_198 . V_210 ) {
if ( V_197 == V_213 )
return V_214 ;
goto V_52;
}
if ( ! V_198 . V_110 ) {
V_202 = ( V_47 == V_40 ) ? V_60 : V_215 ;
goto V_52;
}
V_200 = V_198 . V_200 ;
switch ( V_47 ) {
case V_40 :
if ( V_201 != V_195 || ( V_198 . type & 0xa ) != 0x2 || V_200 != V_195 )
goto V_52;
break;
case V_89 :
if ( ! ( V_198 . type & 8 ) )
goto V_52;
if ( V_198 . type & 4 ) {
if ( V_200 > V_195 )
goto V_52;
} else {
if ( V_201 > V_195 || V_200 != V_195 )
goto V_52;
}
if ( V_198 . V_41 && V_198 . V_94 ) {
V_85 V_95 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
goto V_52;
}
V_65 = ( V_65 & 0xfffc ) | V_195 ;
break;
case V_211 :
if ( V_198 . V_210 || ( V_198 . type != 1 && V_198 . type != 9 ) )
goto V_52;
V_199 = V_198 ;
V_198 . type |= 2 ;
V_206 = V_2 -> V_6 -> V_176 ( V_2 , V_205 , & V_199 , & V_198 ,
sizeof( V_198 ) , & V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
break;
case V_191 :
if ( V_198 . V_210 || V_198 . type != 2 )
goto V_52;
break;
default:
if ( ( V_198 . type & 0xa ) == 0x8 ||
( ( ( V_198 . type & 0xc ) != 0xc ) &&
( V_201 > V_200 && V_195 > V_200 ) ) )
goto V_52;
break;
}
if ( V_198 . V_210 ) {
if ( ! ( V_198 . type & 1 ) ) {
V_198 . type |= 1 ;
V_206 = F_78 ( V_2 , V_65 ,
& V_198 ) ;
if ( V_206 != V_87 )
return V_206 ;
}
} else if ( V_2 -> V_37 == V_38 ) {
V_206 = V_2 -> V_6 -> V_102 ( V_2 , V_205 + 8 , & V_67 ,
sizeof( V_67 ) , & V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
if ( F_35 ( F_75 ( & V_198 ) |
( ( V_85 ) V_67 << 32 ) ) )
return F_24 ( V_2 , 0 ) ;
}
V_207:
V_2 -> V_6 -> V_68 ( V_2 , V_65 , & V_198 , V_67 , V_47 ) ;
if ( V_44 )
* V_44 = V_198 ;
return V_87 ;
V_52:
return F_21 ( V_2 , V_202 , V_203 , true ) ;
}
static int F_82 ( struct V_1 * V_2 ,
T_2 V_65 , int V_47 )
{
T_5 V_195 = V_2 -> V_6 -> V_195 ( V_2 ) ;
return F_79 ( V_2 , V_65 , V_47 , V_195 ,
V_216 , NULL ) ;
}
static void F_83 ( struct V_119 * V_120 )
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
static int F_84 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
switch ( V_120 -> type ) {
case V_138 :
F_83 ( V_120 ) ;
break;
case V_151 :
if ( V_2 -> V_217 )
return F_70 ( V_2 ,
V_120 -> V_74 . V_163 ,
& V_120 -> V_140 ,
& V_120 -> V_121 ,
V_120 -> V_27 ) ;
else
return F_69 ( V_2 ,
V_120 -> V_74 . V_163 ,
& V_120 -> V_121 ,
V_120 -> V_27 ) ;
break;
case V_185 :
return F_69 ( V_2 ,
V_120 -> V_74 . V_163 ,
V_120 -> V_101 ,
V_120 -> V_27 * V_120 -> V_181 ) ;
break;
case V_132 :
F_55 ( V_2 , & V_120 -> V_134 , V_120 -> V_74 . V_133 ) ;
break;
case V_136 :
F_57 ( V_2 , & V_120 -> V_218 , V_120 -> V_74 . V_137 ) ;
break;
case V_219 :
break;
default:
break;
}
return V_87 ;
}
static int F_85 ( struct V_1 * V_2 , void * V_101 , int V_27 )
{
struct V_73 V_74 ;
F_17 ( V_2 , - V_27 ) ;
V_74 . V_83 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_74 . V_47 = V_40 ;
return F_69 ( V_2 , V_74 , V_101 , V_27 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_219 ;
return F_85 ( V_2 , & V_2 -> V_22 . V_121 , V_2 -> V_90 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
void * V_32 , int V_220 )
{
int V_88 ;
struct V_73 V_74 ;
V_74 . V_83 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_74 . V_47 = V_40 ;
V_88 = F_68 ( V_2 , V_74 , V_32 , V_220 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_220 ) ;
return V_88 ;
}
static int F_88 ( struct V_1 * V_2 )
{
return F_87 ( V_2 , & V_2 -> V_25 . V_121 , V_2 -> V_90 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
void * V_32 , int V_220 )
{
int V_88 ;
unsigned long V_121 , V_221 ;
int V_222 = ( V_2 -> V_183 & V_223 ) >> V_224 ;
int V_195 = V_2 -> V_6 -> V_195 ( V_2 ) ;
V_88 = F_87 ( V_2 , & V_121 , V_220 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_221 = V_225 | V_226 | V_227 | V_228 | V_229 | V_230
| V_231 | V_184 | V_232 | V_233 | V_234 ;
switch( V_2 -> V_37 ) {
case V_38 :
case V_99 :
case V_93 :
if ( V_195 == 0 )
V_221 |= V_235 ;
if ( V_195 <= V_222 )
V_221 |= V_236 ;
break;
case V_209 :
if ( V_222 < 3 )
return F_24 ( V_2 , 0 ) ;
V_221 |= V_236 ;
break;
default:
V_221 |= ( V_235 | V_236 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_183 & ~ V_221 ) | ( V_121 & V_221 ) ;
return V_88 ;
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_138 ;
V_2 -> V_25 . V_74 . V_9 = & V_2 -> V_183 ;
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
return F_89 ( V_2 , & V_2 -> V_25 . V_121 , V_2 -> V_90 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned V_237 = V_2 -> V_22 . V_121 ;
unsigned V_238 = V_2 -> V_239 . V_121 & 31 ;
T_1 V_240 ;
if ( V_238 )
return V_214 ;
V_240 = F_1 ( V_2 , V_142 ) ;
V_88 = F_85 ( V_2 , & V_240 , F_11 ( V_2 ) ) ;
if ( V_88 != V_87 )
return V_88 ;
F_8 ( F_3 ( V_2 , V_142 ) , F_1 ( V_2 , V_43 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_43 ) ,
F_1 ( V_2 , V_43 ) - V_237 ,
F_10 ( V_2 ) ) ;
return V_87 ;
}
static int F_92 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_43 ) , F_1 ( V_2 , V_142 ) ,
F_10 ( V_2 ) ) ;
return F_87 ( V_2 , F_3 ( V_2 , V_142 ) , V_2 -> V_90 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_239 . V_121 ;
V_2 -> V_22 . V_121 = F_30 ( V_2 , V_47 ) ;
if ( V_2 -> V_90 == 4 ) {
F_17 ( V_2 , - 2 ) ;
V_2 -> V_90 = 2 ;
}
return F_86 ( V_2 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_239 . V_121 ;
unsigned long V_65 ;
int V_88 ;
V_88 = F_87 ( V_2 , & V_65 , 2 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_241 = V_242 ;
if ( V_2 -> V_90 > 2 )
F_17 ( V_2 , V_2 -> V_90 - 2 ) ;
V_88 = F_82 ( V_2 , ( T_2 ) V_65 , V_47 ) ;
return V_88 ;
}
static int F_95 ( struct V_1 * V_2 )
{
unsigned long V_243 = F_1 ( V_2 , V_43 ) ;
int V_88 = V_87 ;
int V_9 = V_244 ;
while ( V_9 <= V_158 ) {
( V_9 == V_43 ) ?
( V_2 -> V_22 . V_121 = V_243 ) : ( V_2 -> V_22 . V_121 = F_1 ( V_2 , V_9 ) ) ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
++ V_9 ;
}
return V_88 ;
}
static int F_96 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_121 = ( unsigned long ) V_2 -> V_183 & ~ V_245 ;
return F_86 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
int V_9 = V_158 ;
while ( V_9 >= V_244 ) {
if ( V_9 == V_43 ) {
F_17 ( V_2 , V_2 -> V_90 ) ;
-- V_9 ;
}
V_88 = F_87 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
break;
-- V_9 ;
}
return V_88 ;
}
static int F_98 ( struct V_1 * V_2 , int V_246 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
int V_88 ;
struct V_187 V_188 ;
T_7 V_247 ;
T_7 V_248 ;
T_2 V_249 , V_31 ;
V_2 -> V_22 . V_121 = V_2 -> V_183 ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_183 &= ~ ( V_236 | V_231 | V_233 ) ;
V_2 -> V_22 . V_121 = F_30 ( V_2 , V_89 ) ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_22 . V_121 = V_2 -> V_91 ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_6 -> V_189 ( V_2 , & V_188 ) ;
V_248 = V_188 . V_113 + ( V_246 << 2 ) ;
V_247 = V_188 . V_113 + ( V_246 << 2 ) + 2 ;
V_88 = V_6 -> V_102 ( V_2 , V_247 , & V_249 , 2 , & V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = V_6 -> V_102 ( V_2 , V_248 , & V_31 , 2 , & V_2 -> V_52 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_82 ( V_2 , V_249 , V_89 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_31 ;
return V_88 ;
}
int F_99 ( struct V_1 * V_2 , int V_246 )
{
int V_88 ;
F_6 ( V_2 ) ;
V_88 = F_98 ( V_2 , V_246 ) ;
if ( V_88 == V_87 )
F_4 ( V_2 ) ;
return V_88 ;
}
static int F_100 ( struct V_1 * V_2 , int V_246 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_98 ( V_2 , V_246 ) ;
case V_209 :
case V_93 :
case V_99 :
case V_38 :
default:
return V_214 ;
}
}
static int F_101 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
unsigned long V_250 = 0 ;
unsigned long V_251 = 0 ;
unsigned long V_249 = 0 ;
unsigned long V_33 = V_225 | V_226 | V_227 | V_228 | V_229 | V_231 |
V_236 | V_184 | V_230 | V_235 | V_232 | V_252 |
V_233 | V_234 | ( 1 << 1 ) ;
unsigned long V_253 = V_245 | V_254 | V_255 ;
V_88 = F_87 ( V_2 , & V_250 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_250 & ~ 0xffff )
return F_24 ( V_2 , 0 ) ;
V_88 = F_87 ( V_2 , & V_249 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_87 ( V_2 , & V_251 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_82 ( V_2 , ( T_2 ) V_249 , V_89 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_250 ;
if ( V_2 -> V_90 == 4 )
V_2 -> V_183 = ( ( V_251 & V_33 ) | ( V_2 -> V_183 & V_253 ) ) ;
else if ( V_2 -> V_90 == 2 ) {
V_2 -> V_183 &= ~ 0xffff ;
V_2 -> V_183 |= V_251 ;
}
V_2 -> V_183 &= ~ V_256 ;
V_2 -> V_183 |= V_257 ;
V_2 -> V_6 -> V_258 ( V_2 , false ) ;
return V_88 ;
}
static int F_102 ( struct V_1 * V_2 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_101 ( V_2 ) ;
case V_209 :
case V_93 :
case V_99 :
case V_38 :
default:
return V_214 ;
}
}
static int F_103 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned short V_34 , V_259 ;
struct V_35 V_199 , V_260 ;
const struct V_190 * V_6 = V_2 -> V_6 ;
T_5 V_195 = V_2 -> V_6 -> V_195 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_259 , & V_199 , NULL ,
V_89 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_261 + V_2 -> V_90 , 2 ) ;
V_88 = F_79 ( V_2 , V_34 , V_89 , V_195 ,
V_213 ,
& V_260 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_40 ( V_2 , V_2 -> V_22 . V_121 , & V_260 ) ;
if ( V_88 != V_87 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_68 ( V_2 , V_259 , & V_199 , 0 , V_89 ) ;
return V_88 ;
}
return V_88 ;
}
static int F_104 ( struct V_1 * V_2 )
{
return F_39 ( V_2 , V_2 -> V_22 . V_121 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_88 ;
long int V_262 ;
V_262 = V_2 -> V_91 ;
V_88 = F_39 ( V_2 , V_2 -> V_22 . V_121 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_22 . V_121 = V_262 ;
V_88 = F_86 ( V_2 ) ;
return V_88 ;
}
static int F_106 ( struct V_1 * V_2 )
{
V_85 V_263 = V_2 -> V_25 . V_264 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_214 ;
if ( ( ( T_3 ) ( V_263 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_244 ) ) ||
( ( T_3 ) ( V_263 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_265 ) ) ) {
* F_2 ( V_2 , V_244 ) = ( T_3 ) ( V_263 >> 0 ) ;
* F_2 ( V_2 , V_265 ) = ( T_3 ) ( V_263 >> 32 ) ;
V_2 -> V_183 &= ~ V_228 ;
} else {
V_2 -> V_25 . V_23 = ( ( V_85 ) F_1 ( V_2 , V_182 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_153 ) ;
V_2 -> V_183 |= V_228 ;
}
return V_87 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 ;
V_88 = F_87 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
return F_39 ( V_2 , V_31 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 , V_249 ;
T_2 V_266 ;
int V_195 = V_2 -> V_6 -> V_195 ( V_2 ) ;
struct V_35 V_199 , V_260 ;
const struct V_190 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_266 , & V_199 , NULL ,
V_89 ) ;
V_88 = F_87 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_87 ( V_2 , & V_249 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_37 >= V_93 && ( V_249 & 3 ) > V_195 )
return V_214 ;
V_88 = F_79 ( V_2 , ( T_2 ) V_249 , V_89 , V_195 ,
V_267 ,
& V_260 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_40 ( V_2 , V_31 , & V_260 ) ;
if ( V_88 != V_87 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_68 ( V_2 , V_266 , & V_199 , 0 , V_89 ) ;
}
return V_88 ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_108 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_87 ;
}
static int F_110 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_140 = V_2 -> V_25 . V_121 ;
V_2 -> V_25 . V_121 = F_1 ( V_2 , V_244 ) ;
V_2 -> V_22 . V_140 = V_2 -> V_22 . V_121 ;
V_2 -> V_22 . V_121 = V_2 -> V_25 . V_140 ;
F_111 ( V_2 , V_268 ) ;
if ( V_2 -> V_183 & V_228 ) {
V_2 -> V_22 . type = V_219 ;
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_140 ;
} else {
V_2 -> V_22 . type = V_138 ;
V_2 -> V_22 . V_74 . V_9 = F_3 ( V_2 , V_244 ) ;
V_2 -> V_22 . V_121 = V_2 -> V_25 . V_140 ;
V_2 -> V_25 . V_121 = V_2 -> V_25 . V_140 ;
}
return V_87 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_239 . V_121 ;
unsigned short V_34 ;
int V_88 ;
memcpy ( & V_34 , V_2 -> V_22 . V_261 + V_2 -> V_90 , 2 ) ;
V_88 = F_82 ( V_2 , V_34 , V_47 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_121 ;
return V_88 ;
}
static void
F_113 ( struct V_1 * V_2 ,
struct V_35 * V_249 , struct V_35 * V_36 )
{
V_249 -> V_94 = 0 ;
F_80 ( V_249 , 0 ) ;
V_249 -> V_46 = 1 ;
F_81 ( V_249 , 0xfffff ) ;
V_249 -> type = 0x0b ;
V_249 -> V_210 = 1 ;
V_249 -> V_200 = 0 ;
V_249 -> V_110 = 1 ;
V_249 -> V_41 = 1 ;
V_249 -> V_269 = 0 ;
F_80 ( V_36 , 0 ) ;
F_81 ( V_36 , 0xfffff ) ;
V_36 -> V_46 = 1 ;
V_36 -> V_210 = 1 ;
V_36 -> type = 0x03 ;
V_36 -> V_41 = 1 ;
V_36 -> V_200 = 0 ;
V_36 -> V_110 = 1 ;
V_36 -> V_94 = 0 ;
V_36 -> V_269 = 0 ;
}
static bool F_114 ( struct V_1 * V_2 )
{
T_3 V_270 , V_271 , V_272 , V_273 ;
V_270 = V_272 = 0 ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
return V_271 == V_275
&& V_272 == V_276
&& V_273 == V_277 ;
}
static bool F_115 ( struct V_1 * V_2 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
T_3 V_270 , V_271 , V_272 , V_273 ;
if ( V_2 -> V_37 == V_38 )
return true ;
V_270 = 0x00000000 ;
V_272 = 0x00000000 ;
V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
if ( V_271 == V_275 &&
V_272 == V_276 &&
V_273 == V_277 )
return false ;
if ( V_271 == V_278 &&
V_272 == V_279 &&
V_273 == V_280 )
return true ;
if ( V_271 == V_281 &&
V_272 == V_282 &&
V_273 == V_283 )
return true ;
return false ;
}
static int F_116 ( struct V_1 * V_2 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_35 V_249 , V_36 ;
V_85 V_284 ;
T_2 V_285 , V_286 ;
V_85 V_95 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_209 )
return F_26 ( V_2 ) ;
if ( ! ( F_115 ( V_2 ) ) )
return F_26 ( V_2 ) ;
V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
F_113 ( V_2 , & V_249 , & V_36 ) ;
if ( ! ( V_95 & V_287 ) )
return F_26 ( V_2 ) ;
V_6 -> V_96 ( V_2 , V_288 , & V_284 ) ;
V_284 >>= 32 ;
V_285 = ( T_2 ) ( V_284 & 0xfffc ) ;
V_286 = ( T_2 ) ( V_284 + 8 ) ;
if ( V_95 & V_98 ) {
V_249 . V_41 = 0 ;
V_249 . V_94 = 1 ;
}
V_6 -> V_68 ( V_2 , V_285 , & V_249 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_286 , & V_36 , 0 , V_40 ) ;
* F_2 ( V_2 , V_182 ) = V_2 -> V_91 ;
if ( V_95 & V_98 ) {
#ifdef F_41
* F_2 ( V_2 , V_289 ) = V_2 -> V_183 ;
V_6 -> V_96 ( V_2 ,
V_2 -> V_37 == V_38 ?
V_290 : V_291 , & V_284 ) ;
V_2 -> V_91 = V_284 ;
V_6 -> V_96 ( V_2 , V_292 , & V_284 ) ;
V_2 -> V_183 &= ~ V_284 ;
V_2 -> V_183 |= V_257 ;
#endif
} else {
V_6 -> V_96 ( V_2 , V_288 , & V_284 ) ;
V_2 -> V_91 = ( T_3 ) V_284 ;
V_2 -> V_183 &= ~ ( V_245 | V_236 ) ;
}
return V_87 ;
}
static int F_117 ( struct V_1 * V_2 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_35 V_249 , V_36 ;
V_85 V_284 ;
T_2 V_285 , V_286 ;
V_85 V_95 = 0 ;
V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_2 -> V_37 == V_86 )
return F_24 ( V_2 , 0 ) ;
if ( ( V_2 -> V_37 != V_38 ) && ( V_95 & V_98 )
&& ! F_114 ( V_2 ) )
return F_26 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
return V_214 ;
F_113 ( V_2 , & V_249 , & V_36 ) ;
V_6 -> V_96 ( V_2 , V_293 , & V_284 ) ;
if ( ( V_284 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_183 &= ~ ( V_245 | V_236 ) ;
V_285 = ( T_2 ) V_284 & ~ V_294 ;
V_286 = V_285 + 8 ;
if ( V_95 & V_98 ) {
V_249 . V_41 = 0 ;
V_249 . V_94 = 1 ;
}
V_6 -> V_68 ( V_2 , V_285 , & V_249 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_286 , & V_36 , 0 , V_40 ) ;
V_6 -> V_96 ( V_2 , V_295 , & V_284 ) ;
V_2 -> V_91 = ( V_95 & V_98 ) ? V_284 : ( T_3 ) V_284 ;
V_6 -> V_96 ( V_2 , V_296 , & V_284 ) ;
* F_2 ( V_2 , V_43 ) = ( V_95 & V_98 ) ? V_284 :
( T_3 ) V_284 ;
return V_87 ;
}
static int F_118 ( struct V_1 * V_2 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_35 V_249 , V_36 ;
V_85 V_284 , V_297 , V_298 ;
int V_299 ;
T_2 V_285 = 0 , V_286 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_209 )
return F_24 ( V_2 , 0 ) ;
F_113 ( V_2 , & V_249 , & V_36 ) ;
if ( ( V_2 -> V_112 & 0x8 ) != 0x0 )
V_299 = V_38 ;
else
V_299 = V_99 ;
V_297 = F_1 ( V_2 , V_182 ) ;
V_298 = F_1 ( V_2 , V_265 ) ;
V_249 . V_200 = 3 ;
V_36 . V_200 = 3 ;
V_6 -> V_96 ( V_2 , V_293 , & V_284 ) ;
switch ( V_299 ) {
case V_99 :
V_285 = ( T_2 ) ( V_284 + 16 ) ;
if ( ( V_284 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_286 = ( T_2 ) ( V_284 + 24 ) ;
V_297 = ( T_3 ) V_297 ;
V_298 = ( T_3 ) V_298 ;
break;
case V_38 :
V_285 = ( T_2 ) ( V_284 + 32 ) ;
if ( V_284 == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_286 = V_285 + 8 ;
V_249 . V_41 = 0 ;
V_249 . V_94 = 1 ;
if ( F_35 ( V_297 ) ||
F_35 ( V_298 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
V_285 |= V_294 ;
V_286 |= V_294 ;
V_6 -> V_68 ( V_2 , V_285 , & V_249 , 0 , V_89 ) ;
V_6 -> V_68 ( V_2 , V_286 , & V_36 , 0 , V_40 ) ;
V_2 -> V_91 = V_298 ;
* F_2 ( V_2 , V_43 ) = V_297 ;
return V_87 ;
}
static bool F_119 ( struct V_1 * V_2 )
{
int V_222 ;
if ( V_2 -> V_37 == V_86 )
return false ;
if ( V_2 -> V_37 == V_209 )
return true ;
V_222 = ( V_2 -> V_183 & V_223 ) >> V_224 ;
return V_2 -> V_6 -> V_195 ( V_2 ) > V_222 ;
}
static bool F_120 ( struct V_1 * V_2 ,
T_2 V_177 , T_2 V_220 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_35 V_300 ;
T_3 V_67 ;
int V_301 ;
T_2 V_302 , V_303 , V_304 , V_305 = V_177 & 0x7 ;
unsigned V_33 = ( 1 << V_220 ) - 1 ;
unsigned long V_306 ;
V_6 -> V_39 ( V_2 , & V_302 , & V_300 , & V_67 , V_211 ) ;
if ( ! V_300 . V_110 )
return false ;
if ( F_18 ( & V_300 ) < 103 )
return false ;
V_306 = F_75 ( & V_300 ) ;
#ifdef F_41
V_306 |= ( ( V_85 ) V_67 ) << 32 ;
#endif
V_301 = V_6 -> V_102 ( V_2 , V_306 + 102 , & V_303 , 2 , NULL ) ;
if ( V_301 != V_87 )
return false ;
if ( V_303 + V_177 / 8 > F_18 ( & V_300 ) )
return false ;
V_301 = V_6 -> V_102 ( V_2 , V_306 + V_303 + V_177 / 8 , & V_304 , 2 , NULL ) ;
if ( V_301 != V_87 )
return false ;
if ( ( V_304 >> V_305 ) & V_33 )
return false ;
return true ;
}
static bool F_121 ( struct V_1 * V_2 ,
T_2 V_177 , T_2 V_220 )
{
if ( V_2 -> V_307 )
return true ;
if ( F_119 ( V_2 ) )
if ( ! F_120 ( V_2 , V_177 , V_220 ) )
return false ;
V_2 -> V_307 = true ;
return true ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
V_309 -> V_310 = V_2 -> V_91 ;
V_309 -> V_311 = V_2 -> V_183 ;
V_309 -> V_312 = F_1 ( V_2 , V_244 ) ;
V_309 -> V_313 = F_1 ( V_2 , V_182 ) ;
V_309 -> V_314 = F_1 ( V_2 , V_265 ) ;
V_309 -> V_152 = F_1 ( V_2 , V_153 ) ;
V_309 -> V_315 = F_1 ( V_2 , V_43 ) ;
V_309 -> V_154 = F_1 ( V_2 , V_142 ) ;
V_309 -> V_155 = F_1 ( V_2 , V_156 ) ;
V_309 -> V_157 = F_1 ( V_2 , V_158 ) ;
V_309 -> V_316 = F_30 ( V_2 , V_317 ) ;
V_309 -> V_249 = F_30 ( V_2 , V_89 ) ;
V_309 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_309 -> V_318 = F_30 ( V_2 , V_149 ) ;
V_309 -> V_319 = F_30 ( V_2 , V_191 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_308 * V_309 )
{
int V_206 ;
T_5 V_195 ;
V_2 -> V_91 = V_309 -> V_310 ;
V_2 -> V_183 = V_309 -> V_311 | 2 ;
* F_2 ( V_2 , V_244 ) = V_309 -> V_312 ;
* F_2 ( V_2 , V_182 ) = V_309 -> V_313 ;
* F_2 ( V_2 , V_265 ) = V_309 -> V_314 ;
* F_2 ( V_2 , V_153 ) = V_309 -> V_152 ;
* F_2 ( V_2 , V_43 ) = V_309 -> V_315 ;
* F_2 ( V_2 , V_142 ) = V_309 -> V_154 ;
* F_2 ( V_2 , V_156 ) = V_309 -> V_155 ;
* F_2 ( V_2 , V_158 ) = V_309 -> V_157 ;
F_31 ( V_2 , V_309 -> V_319 , V_191 ) ;
F_31 ( V_2 , V_309 -> V_316 , V_317 ) ;
F_31 ( V_2 , V_309 -> V_249 , V_89 ) ;
F_31 ( V_2 , V_309 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_309 -> V_318 , V_149 ) ;
V_195 = V_309 -> V_249 & 3 ;
V_206 = F_79 ( V_2 , V_309 -> V_319 , V_191 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_316 , V_317 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_249 , V_89 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_36 , V_40 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_318 , V_149 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
return V_87 ;
}
static int F_124 ( struct V_1 * V_2 ,
T_2 V_320 , T_2 V_321 ,
T_1 V_322 , struct V_35 * V_260 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_308 V_323 ;
int V_206 ;
T_3 V_324 = F_75 ( V_260 ) ;
V_206 = V_6 -> V_102 ( V_2 , V_322 , & V_323 , sizeof V_323 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
F_122 ( V_2 , & V_323 ) ;
V_206 = V_6 -> V_194 ( V_2 , V_322 , & V_323 , sizeof V_323 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = V_6 -> V_102 ( V_2 , V_324 , & V_323 , sizeof V_323 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
if ( V_321 != 0xffff ) {
V_323 . V_325 = V_321 ;
V_206 = V_6 -> V_194 ( V_2 , V_324 ,
& V_323 . V_325 ,
sizeof V_323 . V_325 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
}
return F_123 ( V_2 , & V_323 ) ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_326 * V_309 )
{
V_309 -> V_31 = V_2 -> V_91 ;
V_309 -> V_183 = V_2 -> V_183 ;
V_309 -> V_270 = F_1 ( V_2 , V_244 ) ;
V_309 -> V_272 = F_1 ( V_2 , V_182 ) ;
V_309 -> V_273 = F_1 ( V_2 , V_265 ) ;
V_309 -> V_271 = F_1 ( V_2 , V_153 ) ;
V_309 -> V_327 = F_1 ( V_2 , V_43 ) ;
V_309 -> V_328 = F_1 ( V_2 , V_142 ) ;
V_309 -> V_329 = F_1 ( V_2 , V_156 ) ;
V_309 -> V_330 = F_1 ( V_2 , V_158 ) ;
V_309 -> V_316 = F_30 ( V_2 , V_317 ) ;
V_309 -> V_249 = F_30 ( V_2 , V_89 ) ;
V_309 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_309 -> V_318 = F_30 ( V_2 , V_149 ) ;
V_309 -> V_331 = F_30 ( V_2 , V_48 ) ;
V_309 -> V_332 = F_30 ( V_2 , V_208 ) ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_326 * V_309 )
{
int V_206 ;
T_5 V_195 ;
if ( V_2 -> V_6 -> V_333 ( V_2 , 3 , V_309 -> V_334 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_91 = V_309 -> V_31 ;
V_2 -> V_183 = V_309 -> V_183 | 2 ;
* F_2 ( V_2 , V_244 ) = V_309 -> V_270 ;
* F_2 ( V_2 , V_182 ) = V_309 -> V_272 ;
* F_2 ( V_2 , V_265 ) = V_309 -> V_273 ;
* F_2 ( V_2 , V_153 ) = V_309 -> V_271 ;
* F_2 ( V_2 , V_43 ) = V_309 -> V_327 ;
* F_2 ( V_2 , V_142 ) = V_309 -> V_328 ;
* F_2 ( V_2 , V_156 ) = V_309 -> V_329 ;
* F_2 ( V_2 , V_158 ) = V_309 -> V_330 ;
F_31 ( V_2 , V_309 -> V_335 , V_191 ) ;
F_31 ( V_2 , V_309 -> V_316 , V_317 ) ;
F_31 ( V_2 , V_309 -> V_249 , V_89 ) ;
F_31 ( V_2 , V_309 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_309 -> V_318 , V_149 ) ;
F_31 ( V_2 , V_309 -> V_331 , V_48 ) ;
F_31 ( V_2 , V_309 -> V_332 , V_208 ) ;
if ( V_2 -> V_183 & V_336 ) {
V_2 -> V_37 = V_209 ;
V_195 = 3 ;
} else {
V_2 -> V_37 = V_99 ;
V_195 = V_309 -> V_249 & 3 ;
}
V_206 = F_79 ( V_2 , V_309 -> V_335 , V_191 ,
V_195 , V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_316 , V_317 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_249 , V_89 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_36 , V_40 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_318 , V_149 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_331 , V_48 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_79 ( V_2 , V_309 -> V_332 , V_208 , V_195 ,
V_212 , NULL ) ;
if ( V_206 != V_87 )
return V_206 ;
return V_87 ;
}
static int F_127 ( struct V_1 * V_2 ,
T_2 V_320 , T_2 V_321 ,
T_1 V_322 , struct V_35 * V_260 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_326 V_323 ;
int V_206 ;
T_3 V_324 = F_75 ( V_260 ) ;
T_3 V_337 = F_128 ( struct V_326 , V_31 ) ;
T_3 V_338 = F_128 ( struct V_326 , V_335 ) ;
V_206 = V_6 -> V_102 ( V_2 , V_322 , & V_323 , sizeof V_323 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
F_125 ( V_2 , & V_323 ) ;
V_206 = V_6 -> V_194 ( V_2 , V_322 + V_337 , & V_323 . V_31 ,
V_338 - V_337 , & V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = V_6 -> V_102 ( V_2 , V_324 , & V_323 , sizeof V_323 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
if ( V_321 != 0xffff ) {
V_323 . V_325 = V_321 ;
V_206 = V_6 -> V_194 ( V_2 , V_324 ,
& V_323 . V_325 ,
sizeof V_323 . V_325 ,
& V_2 -> V_52 ) ;
if ( V_206 != V_87 )
return V_206 ;
}
return F_126 ( V_2 , & V_323 ) ;
}
static int F_129 ( struct V_1 * V_2 ,
T_2 V_320 , int V_339 , int V_340 ,
bool V_341 , T_3 V_54 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
struct V_35 V_342 , V_343 ;
int V_206 ;
T_2 V_321 = F_30 ( V_2 , V_211 ) ;
T_1 V_322 =
V_6 -> V_49 ( V_2 , V_211 ) ;
T_3 V_344 ;
T_1 V_205 ;
V_206 = F_77 ( V_2 , V_320 , & V_343 , & V_205 ) ;
if ( V_206 != V_87 )
return V_206 ;
V_206 = F_77 ( V_2 , V_321 , & V_342 , & V_205 ) ;
if ( V_206 != V_87 )
return V_206 ;
if ( V_340 == V_345 ) {
if ( V_339 != - 1 ) {
struct V_35 V_346 ;
int V_200 ;
V_206 = F_73 ( V_2 , V_339 ,
& V_346 ) ;
if ( V_206 != V_87 )
return V_206 ;
V_200 = V_346 . V_200 ;
if ( ( V_320 & 3 ) > V_200 || V_6 -> V_195 ( V_2 ) > V_200 )
return F_24 ( V_2 , ( V_339 << 3 ) | 0x2 ) ;
}
}
V_344 = F_18 ( & V_343 ) ;
if ( ! V_343 . V_110 ||
( ( V_344 < 0x67 && ( V_343 . type & 8 ) ) ||
V_344 < 0x2b ) ) {
return F_27 ( V_2 , V_320 & 0xfffc ) ;
}
if ( V_340 == V_347 || V_340 == V_348 ) {
V_342 . type &= ~ ( 1 << 1 ) ;
F_78 ( V_2 , V_321 , & V_342 ) ;
}
if ( V_340 == V_347 )
V_2 -> V_183 = V_2 -> V_183 & ~ V_349 ;
if ( V_340 != V_350 && V_340 != V_345 )
V_321 = 0xffff ;
if ( V_343 . type & 8 )
V_206 = F_127 ( V_2 , V_320 , V_321 ,
V_322 , & V_343 ) ;
else
V_206 = F_124 ( V_2 , V_320 , V_321 ,
V_322 , & V_343 ) ;
if ( V_206 != V_87 )
return V_206 ;
if ( V_340 == V_350 || V_340 == V_345 )
V_2 -> V_183 = V_2 -> V_183 | V_349 ;
if ( V_340 != V_347 ) {
V_343 . type |= ( 1 << 1 ) ;
F_78 ( V_2 , V_320 , & V_343 ) ;
}
V_6 -> V_333 ( V_2 , 0 , V_6 -> V_124 ( V_2 , 0 ) | V_125 ) ;
V_6 -> V_68 ( V_2 , V_320 , & V_343 , 0 , V_211 ) ;
if ( V_341 ) {
V_2 -> V_90 = V_2 -> V_29 = ( V_343 . type & 8 ) ? 4 : 2 ;
V_2 -> V_217 = 0 ;
V_2 -> V_22 . V_121 = ( unsigned long ) V_54 ;
V_206 = F_86 ( V_2 ) ;
}
return V_206 ;
}
int F_130 ( struct V_1 * V_2 ,
T_2 V_320 , int V_339 , int V_340 ,
bool V_341 , T_3 V_54 )
{
int V_88 ;
F_6 ( V_2 ) ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_219 ;
V_88 = F_129 ( V_2 , V_320 , V_339 , V_340 ,
V_341 , V_54 ) ;
if ( V_88 == V_87 ) {
V_2 -> V_31 = V_2 -> V_91 ;
F_4 ( V_2 ) ;
}
return ( V_88 == V_214 ) ? V_351 : V_352 ;
}
static void F_131 ( struct V_1 * V_2 , int V_9 ,
struct V_119 * V_120 )
{
int V_353 = ( V_2 -> V_183 & V_184 ) ? - V_120 -> V_181 : V_120 -> V_181 ;
F_16 ( V_2 , V_9 , V_353 * V_120 -> V_27 ) ;
V_120 -> V_74 . V_163 . V_83 = F_14 ( V_2 , V_9 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
T_5 V_354 , V_355 ;
bool V_356 , V_357 , V_358 ;
V_357 = V_2 -> V_183 & V_359 ;
V_354 = V_2 -> V_25 . V_121 ;
V_355 = V_354 ;
V_358 = V_357 ;
V_357 = false ;
V_356 = V_2 -> V_183 & V_360 ;
if ( ( V_354 & 0x0f ) > 9 || V_356 ) {
V_354 -= 6 ;
V_357 = V_358 | ( V_354 >= 250 ) ;
V_356 = true ;
} else {
V_356 = false ;
}
if ( V_355 > 0x99 || V_358 ) {
V_354 -= 0x60 ;
V_357 = true ;
}
V_2 -> V_25 . V_121 = V_354 ;
V_2 -> V_22 . type = V_361 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_111 ( V_2 , V_362 ) ;
V_2 -> V_183 &= ~ ( V_360 | V_359 ) ;
if ( V_357 )
V_2 -> V_183 |= V_359 ;
if ( V_356 )
V_2 -> V_183 |= V_360 ;
return V_87 ;
}
static int F_133 ( struct V_1 * V_2 )
{
T_5 V_354 , V_363 ;
if ( V_2 -> V_22 . V_121 == 0 )
return F_28 ( V_2 ) ;
V_354 = V_2 -> V_25 . V_121 & 0xff ;
V_363 = V_354 / V_2 -> V_22 . V_121 ;
V_354 %= V_2 -> V_22 . V_121 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_25 . V_121 & 0xffff0000 ) | V_354 | ( V_363 << 8 ) ;
V_2 -> V_22 . type = V_361 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_111 ( V_2 , V_362 ) ;
return V_87 ;
}
static int F_134 ( struct V_1 * V_2 )
{
T_5 V_354 = V_2 -> V_25 . V_121 & 0xff ;
T_5 V_363 = ( V_2 -> V_25 . V_121 >> 8 ) & 0xff ;
V_354 = ( V_354 + ( V_363 * V_2 -> V_22 . V_121 ) ) & 0xff ;
V_2 -> V_25 . V_121 = ( V_2 -> V_25 . V_121 & 0xffff0000 ) | V_354 ;
V_2 -> V_22 . type = V_361 ;
V_2 -> V_22 . V_121 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_111 ( V_2 , V_362 ) ;
return V_87 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_88 ;
long V_100 = V_2 -> V_22 . V_121 ;
V_2 -> V_22 . V_121 = ( unsigned long ) V_2 -> V_91 ;
V_88 = F_42 ( V_2 , V_100 ) ;
if ( V_88 != V_87 )
return V_88 ;
return F_86 ( V_2 ) ;
}
static int F_136 ( struct V_1 * V_2 )
{
T_2 V_34 , V_266 ;
T_1 V_262 ;
int V_88 ;
struct V_35 V_199 , V_260 ;
const struct V_190 * V_6 = V_2 -> V_6 ;
int V_195 = V_2 -> V_6 -> V_195 ( V_2 ) ;
enum V_78 V_364 = V_2 -> V_37 ;
V_262 = V_2 -> V_91 ;
V_6 -> V_39 ( V_2 , & V_266 , & V_199 , NULL , V_89 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_261 + V_2 -> V_90 , 2 ) ;
V_88 = F_79 ( V_2 , V_34 , V_89 , V_195 ,
V_213 , & V_260 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_40 ( V_2 , V_2 -> V_22 . V_121 , & V_260 ) ;
if ( V_88 != V_87 )
goto V_365;
V_2 -> V_22 . V_121 = V_266 ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_365;
V_2 -> V_22 . V_121 = V_262 ;
V_88 = F_86 ( V_2 ) ;
if ( V_88 != V_87 ) {
F_137 ( L_1 ) ;
goto V_365;
}
return V_88 ;
V_365:
V_6 -> V_68 ( V_2 , V_266 , & V_199 , 0 , V_89 ) ;
V_2 -> V_37 = V_364 ;
return V_88 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_88 ;
unsigned long V_31 ;
V_88 = F_87 ( V_2 , & V_31 , V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_88 = F_39 ( V_2 , V_31 ) ;
if ( V_88 != V_87 )
return V_88 ;
F_17 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_87 ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_121 = V_2 -> V_25 . V_121 ;
F_83 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_140 ;
V_2 -> V_217 = 1 ;
return V_87 ;
}
static int F_140 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_121 = V_2 -> V_239 . V_121 ;
return F_111 ( V_2 , V_366 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_138 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_74 . V_9 = F_3 ( V_2 , V_265 ) ;
V_2 -> V_25 . V_121 = ~ ( ( V_2 -> V_22 . V_121 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_87 ;
}
static int F_142 ( struct V_1 * V_2 )
{
V_85 V_367 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_368 , & V_367 ) ;
* F_2 ( V_2 , V_244 ) = ( T_3 ) V_367 ;
* F_2 ( V_2 , V_265 ) = V_367 >> 32 ;
return V_87 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_85 V_369 ;
if ( V_2 -> V_6 -> V_370 ( V_2 , F_1 ( V_2 , V_182 ) , & V_369 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_244 ) = ( T_3 ) V_369 ;
* F_2 ( V_2 , V_265 ) = V_369 >> 32 ;
return V_87 ;
}
static int F_144 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_261 , V_2 -> V_22 . V_261 , sizeof( V_2 -> V_22 . V_261 ) ) ;
return V_87 ;
}
static int F_145 ( struct V_1 * V_2 )
{
T_3 V_271 , V_272 , V_273 , V_270 = 1 ;
T_2 V_371 ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
if ( ! ( V_272 & F_146 ( V_372 ) ) )
return F_26 ( V_2 ) ;
switch ( V_2 -> V_90 ) {
case 2 :
V_371 = ( T_2 ) V_2 -> V_22 . V_121 ;
V_2 -> V_25 . V_121 &= ~ 0xffffUL ;
V_2 -> V_25 . V_121 |= ( unsigned long ) F_147 ( V_371 ) ;
break;
case 4 :
V_2 -> V_25 . V_121 = F_148 ( ( T_3 ) V_2 -> V_22 . V_121 ) ;
break;
case 8 :
V_2 -> V_25 . V_121 = F_149 ( V_2 -> V_22 . V_121 ) ;
break;
default:
F_54 () ;
}
return V_87 ;
}
static int F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_333 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_121 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_151 ( struct V_1 * V_2 )
{
unsigned long V_121 ;
if ( V_2 -> V_37 == V_38 )
V_121 = V_2 -> V_22 . V_121 & ~ 0ULL ;
else
V_121 = V_2 -> V_22 . V_121 & ~ 0U ;
if ( V_2 -> V_6 -> V_373 ( V_2 , V_2 -> V_19 , V_121 ) < 0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_152 ( struct V_1 * V_2 )
{
V_85 V_284 ;
V_284 = ( T_3 ) F_1 ( V_2 , V_244 )
| ( ( V_85 ) F_1 ( V_2 , V_265 ) << 32 ) ;
if ( V_2 -> V_6 -> V_374 ( V_2 , F_1 ( V_2 , V_182 ) , V_284 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_85 V_284 ;
if ( V_2 -> V_6 -> V_96 ( V_2 , F_1 ( V_2 , V_182 ) , & V_284 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_244 ) = ( T_3 ) V_284 ;
* F_2 ( V_2 , V_265 ) = V_284 >> 32 ;
return V_87 ;
}
static int F_154 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_208 )
return F_26 ( V_2 ) ;
V_2 -> V_25 . V_121 = F_30 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_151 )
V_2 -> V_25 . V_27 = 2 ;
return V_87 ;
}
static int F_155 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
if ( V_2 -> V_19 == V_89 || V_2 -> V_19 > V_208 )
return F_26 ( V_2 ) ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_241 = V_242 ;
V_2 -> V_25 . type = V_219 ;
return F_82 ( V_2 , V_34 , V_2 -> V_19 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
V_2 -> V_25 . type = V_219 ;
return F_82 ( V_2 , V_34 , V_191 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_121 ;
V_2 -> V_25 . type = V_219 ;
return F_82 ( V_2 , V_34 , V_211 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_88 ;
T_1 V_79 ;
V_88 = F_37 ( V_2 , V_2 -> V_22 . V_74 . V_163 , 1 , false , & V_79 ) ;
if ( V_88 == V_87 )
V_2 -> V_6 -> V_375 ( V_2 , V_79 ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_159 ( struct V_1 * V_2 )
{
T_1 V_376 ;
V_376 = V_2 -> V_6 -> V_124 ( V_2 , 0 ) ;
V_376 &= ~ V_125 ;
V_2 -> V_6 -> V_333 ( V_2 , 0 , V_376 ) ;
return V_87 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_88 = V_2 -> V_6 -> V_377 ( V_2 ) ;
if ( V_88 != V_87 )
return V_88 ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_161 ( struct V_1 * V_2 ,
void (* F_162)( struct V_1 * V_2 ,
struct V_187 * V_108 ) )
{
struct V_187 V_187 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_90 = 8 ;
F_162 ( V_2 , & V_187 ) ;
if ( V_2 -> V_90 == 2 ) {
V_2 -> V_90 = 4 ;
V_187 . V_113 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_219 ;
return F_69 ( V_2 , V_2 -> V_25 . V_74 . V_163 ,
& V_187 , 2 + V_2 -> V_90 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
return F_161 ( V_2 , V_2 -> V_6 -> V_192 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
return F_161 ( V_2 , V_2 -> V_6 -> V_189 ) ;
}
static int F_165 ( struct V_1 * V_2 , bool V_378 )
{
struct V_187 V_187 ;
int V_88 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_90 = 8 ;
V_88 = F_49 ( V_2 , V_2 -> V_22 . V_74 . V_163 ,
& V_187 . V_69 , & V_187 . V_113 ,
V_2 -> V_90 ) ;
if ( V_88 != V_87 )
return V_88 ;
if ( V_2 -> V_37 == V_38 &&
F_35 ( V_187 . V_113 ) )
return F_24 ( V_2 , 0 ) ;
if ( V_378 )
V_2 -> V_6 -> V_379 ( V_2 , & V_187 ) ;
else
V_2 -> V_6 -> V_380 ( V_2 , & V_187 ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_166 ( struct V_1 * V_2 )
{
return F_165 ( V_2 , true ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = V_2 -> V_6 -> V_377 ( V_2 ) ;
V_2 -> V_25 . type = V_219 ;
return V_88 ;
}
static int F_168 ( struct V_1 * V_2 )
{
return F_165 ( V_2 , false ) ;
}
static int F_169 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_151 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_121 = V_2 -> V_6 -> V_124 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_333 ( V_2 , 0 , ( V_2 -> V_6 -> V_124 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_121 & 0x0f ) ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_171 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
F_16 ( V_2 , V_182 , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_182 ) ) != 0 ) &&
( V_2 -> V_130 == 0xe2 || F_50 ( V_2 -> V_130 ^ 0x5 , V_2 -> V_183 ) ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_88 ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_88 = V_87 ;
if ( F_13 ( V_2 , F_1 ( V_2 , V_182 ) ) == 0 )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
return V_88 ;
}
static int F_173 ( struct V_1 * V_2 )
{
if ( ! F_71 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_121 ,
& V_2 -> V_25 . V_121 ) )
return V_381 ;
return V_87 ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_382 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_121 ,
& V_2 -> V_22 . V_121 , 1 ) ;
V_2 -> V_25 . type = V_219 ;
return V_87 ;
}
static int F_175 ( struct V_1 * V_2 )
{
if ( F_119 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_183 &= ~ V_118 ;
return V_87 ;
}
static int F_176 ( struct V_1 * V_2 )
{
if ( F_119 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_241 = V_383 ;
V_2 -> V_183 |= V_118 ;
return V_87 ;
}
static int F_177 ( struct V_1 * V_2 )
{
T_3 V_270 , V_271 , V_272 , V_273 ;
V_270 = F_1 ( V_2 , V_244 ) ;
V_272 = F_1 ( V_2 , V_182 ) ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
* F_2 ( V_2 , V_244 ) = V_270 ;
* F_2 ( V_2 , V_153 ) = V_271 ;
* F_2 ( V_2 , V_182 ) = V_272 ;
* F_2 ( V_2 , V_265 ) = V_273 ;
return V_87 ;
}
static int F_178 ( struct V_1 * V_2 )
{
T_3 V_115 ;
V_115 = V_225 | V_226 | V_227 | V_228 | V_229 ;
V_115 &= * F_3 ( V_2 , V_244 ) >> 8 ;
V_2 -> V_183 &= ~ 0xffUL ;
V_2 -> V_183 |= V_115 | V_384 ;
return V_87 ;
}
static int F_179 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_244 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_244 ) |= ( V_2 -> V_183 & 0xff ) << 8 ;
return V_87 ;
}
static int F_180 ( struct V_1 * V_2 )
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
static int F_181 ( struct V_1 * V_2 )
{
return V_87 ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_121 = ( V_160 ) V_2 -> V_22 . V_121 ;
return V_87 ;
}
static bool F_183 ( int V_3 )
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
static int F_184 ( struct V_1 * V_2 )
{
if ( ! F_183 ( V_2 -> V_19 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_185 ( struct V_1 * V_2 )
{
V_85 V_385 = V_2 -> V_22 . V_23 ;
int V_386 = V_2 -> V_19 ;
V_85 V_95 = 0 ;
static V_85 V_387 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_388 ,
0 , 0 , 0 ,
V_389 ,
} ;
if ( ! F_183 ( V_386 ) )
return F_26 ( V_2 ) ;
if ( V_385 & V_387 [ V_386 ] )
return F_24 ( V_2 , 0 ) ;
switch ( V_386 ) {
case 0 : {
V_85 V_390 ;
if ( ( ( V_385 & V_391 ) && ! ( V_385 & V_392 ) ) ||
( ( V_385 & V_393 ) && ! ( V_385 & V_394 ) ) )
return F_24 ( V_2 , 0 ) ;
V_390 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ( V_385 & V_391 ) && ( V_95 & V_395 ) &&
! ( V_390 & V_396 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_85 V_397 = 0 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( V_95 & V_98 )
V_397 = V_398 & ~ V_399 ;
if ( V_385 & V_397 )
return F_24 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ( V_95 & V_98 ) && ! ( V_385 & V_396 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
}
return V_87 ;
}
static int F_186 ( struct V_1 * V_2 )
{
unsigned long V_400 ;
V_2 -> V_6 -> V_401 ( V_2 , 7 , & V_400 ) ;
return V_400 & ( 1 << 13 ) ;
}
static int F_187 ( struct V_1 * V_2 )
{
int V_402 = V_2 -> V_19 ;
V_85 V_390 ;
if ( V_402 > 7 )
return F_26 ( V_2 ) ;
V_390 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
if ( ( V_390 & V_403 ) && ( V_402 == 4 || V_402 == 5 ) )
return F_26 ( V_2 ) ;
if ( F_186 ( V_2 ) ) {
T_1 V_404 ;
V_2 -> V_6 -> V_401 ( V_2 , 6 , & V_404 ) ;
V_404 &= ~ 15 ;
V_404 |= V_405 | V_406 ;
V_2 -> V_6 -> V_373 ( V_2 , 6 , V_404 ) ;
return F_23 ( V_2 ) ;
}
return V_87 ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_85 V_385 = V_2 -> V_22 . V_23 ;
int V_402 = V_2 -> V_19 ;
if ( ( V_402 == 6 || V_402 == 7 ) && ( V_385 & 0xffffffff00000000ULL ) )
return F_24 ( V_2 , 0 ) ;
return F_187 ( V_2 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
V_85 V_95 ;
V_2 -> V_6 -> V_96 ( V_2 , V_97 , & V_95 ) ;
if ( ! ( V_95 & V_407 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_190 ( struct V_1 * V_2 )
{
V_85 V_408 = F_1 ( V_2 , V_244 ) ;
if ( V_408 & 0xffff000000000000ULL )
return F_24 ( V_2 , 0 ) ;
return F_189 ( V_2 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
V_85 V_390 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
if ( V_390 & V_409 && V_2 -> V_6 -> V_195 ( V_2 ) )
return F_26 ( V_2 ) ;
return V_87 ;
}
static int F_192 ( struct V_1 * V_2 )
{
V_85 V_390 = V_2 -> V_6 -> V_124 ( V_2 , 4 ) ;
V_85 V_297 = F_1 ( V_2 , V_182 ) ;
if ( ( ! ( V_390 & V_410 ) && V_2 -> V_6 -> V_195 ( V_2 ) ) ||
V_2 -> V_6 -> V_411 ( V_2 , V_297 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_193 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_194 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_121 ( V_2 , V_2 -> V_22 . V_121 , V_2 -> V_25 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static int F_195 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_194 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_121 ( V_2 , V_2 -> V_25 . V_121 , V_2 -> V_22 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_87 ;
}
static unsigned F_196 ( struct V_1 * V_2 )
{
unsigned V_69 ;
V_69 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
if ( V_69 == 8 )
V_69 = 4 ;
return V_69 ;
}
static int F_197 ( struct V_1 * V_2 , struct V_119 * V_120 ,
unsigned V_69 , bool V_412 )
{
int V_88 = V_87 ;
V_120 -> type = V_361 ;
V_120 -> V_27 = V_69 ;
V_120 -> V_74 . V_163 . V_83 = V_2 -> V_91 ;
switch ( V_120 -> V_27 ) {
case 1 :
V_120 -> V_121 = F_64 ( V_159 , V_2 ) ;
break;
case 2 :
V_120 -> V_121 = F_64 ( V_167 , V_2 ) ;
break;
case 4 :
V_120 -> V_121 = F_64 ( V_160 , V_2 ) ;
break;
case 8 :
V_120 -> V_121 = F_64 ( V_168 , V_2 ) ;
break;
}
if ( ! V_412 ) {
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
V_165:
return V_88 ;
}
static int F_198 ( struct V_1 * V_2 , struct V_119 * V_120 ,
unsigned V_41 )
{
int V_88 = V_87 ;
switch ( V_41 ) {
case V_413 :
F_61 ( V_2 , V_120 ) ;
break;
case V_414 :
V_88 = F_197 ( V_2 , V_120 , 1 , false ) ;
break;
case V_415 :
V_2 -> V_164 . V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_416:
* V_120 = V_2 -> V_164 ;
V_2 -> V_417 = V_120 ;
if ( V_2 -> V_41 & V_418 )
F_66 ( V_2 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_419 :
V_2 -> V_164 . V_27 = ( V_2 -> V_90 == 8 ) ? 16 : 8 ;
goto V_416;
case V_420 :
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_244 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_421 :
V_120 -> type = V_138 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 2 : V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_244 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_422 :
if ( V_2 -> V_41 & V_139 ) {
V_120 -> type = V_219 ;
break;
}
V_120 -> type = V_138 ;
V_120 -> V_27 = V_2 -> V_90 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_265 ) ;
F_52 ( V_120 ) ;
V_120 -> V_140 = V_120 -> V_121 ;
break;
case V_423 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_163 . V_83 =
F_14 ( V_2 , V_158 ) ;
V_120 -> V_74 . V_163 . V_47 = V_317 ;
V_120 -> V_121 = 0 ;
V_120 -> V_181 = 1 ;
break;
case V_424 :
V_120 -> type = V_138 ;
V_120 -> V_27 = 2 ;
V_120 -> V_74 . V_9 = F_3 ( V_2 , V_265 ) ;
F_52 ( V_120 ) ;
break;
case V_425 :
V_120 -> type = V_361 ;
V_120 -> V_27 = 1 ;
V_120 -> V_121 = F_1 ( V_2 , V_182 ) & 0xff ;
break;
case V_426 :
V_88 = F_197 ( V_2 , V_120 , 1 , true ) ;
break;
case V_427 :
V_120 -> type = V_361 ;
V_120 -> V_27 = 1 ;
V_120 -> V_121 = 1 ;
break;
case V_428 :
V_88 = F_197 ( V_2 , V_120 , F_196 ( V_2 ) , true ) ;
break;
case V_429 :
V_88 = F_197 ( V_2 , V_120 , V_2 -> V_90 , true ) ;
break;
case V_430 :
V_2 -> V_164 . V_27 = 1 ;
if ( V_2 -> V_164 . type == V_138 ) {
V_2 -> V_164 . V_74 . V_9 = F_48 ( V_2 ,
V_2 -> V_20 , true ) ;
F_52 ( & V_2 -> V_164 ) ;
}
goto V_416;
case V_431 :
V_2 -> V_164 . V_27 = 2 ;
goto V_416;
case V_432 :
V_2 -> V_164 . V_27 = 4 ;
goto V_416;
case V_433 :
V_88 = F_197 ( V_2 , V_120 , 2 , false ) ;
break;
case V_434 :
V_88 = F_197 ( V_2 , V_120 , F_196 ( V_2 ) , false ) ;
break;
case V_435 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_163 . V_83 =
F_14 ( V_2 , V_156 ) ;
V_120 -> V_74 . V_163 . V_47 = V_2 -> V_436 ;
V_120 -> V_121 = 0 ;
V_120 -> V_181 = 1 ;
break;
case V_437 :
V_120 -> type = V_151 ;
V_120 -> V_27 = ( V_2 -> V_41 & V_139 ) ? 1 : V_2 -> V_90 ;
V_120 -> V_74 . V_163 . V_83 =
F_13 ( V_2 ,
F_1 ( V_2 , V_153 ) +
( F_1 ( V_2 , V_244 ) & 0xff ) ) ;
V_120 -> V_74 . V_163 . V_47 = V_2 -> V_436 ;
V_120 -> V_121 = 0 ;
break;
case V_438 :
V_120 -> type = V_361 ;
V_120 -> V_74 . V_163 . V_83 = V_2 -> V_91 ;
V_120 -> V_27 = V_2 -> V_90 + 2 ;
F_199 ( V_120 -> V_261 , V_120 -> V_27 , V_2 ) ;
break;
case V_439 :
V_2 -> V_164 . V_27 = V_2 -> V_90 + 2 ;
goto V_416;
case V_440 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_317 ;
break;
case V_441 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_89 ;
break;
case V_442 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_40 ;
break;
case V_443 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_149 ;
break;
case V_444 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_48 ;
break;
case V_445 :
V_120 -> type = V_361 ;
V_120 -> V_121 = V_208 ;
break;
case V_446 :
default:
V_120 -> type = V_219 ;
break;
}
V_165:
return V_88 ;
}
int F_200 ( struct V_1 * V_2 , void * V_447 , int V_448 )
{
int V_88 = V_87 ;
int V_37 = V_2 -> V_37 ;
int V_449 , V_450 , V_451 , V_452 ;
bool V_453 = false ;
bool V_454 = false ;
struct V_455 V_455 ;
V_2 -> V_164 . type = V_219 ;
V_2 -> V_417 = NULL ;
V_2 -> V_91 = V_2 -> V_31 ;
V_2 -> V_77 . V_108 = V_2 -> V_77 . V_101 ;
V_2 -> V_77 . V_105 = V_2 -> V_77 . V_101 + V_448 ;
V_2 -> V_456 = 1 ;
if ( V_448 > 0 )
memcpy ( V_2 -> V_77 . V_101 , V_447 , V_448 ) ;
else {
V_88 = F_44 ( V_2 , 1 ) ;
if ( V_88 != V_87 )
return V_88 ;
}
switch ( V_37 ) {
case V_86 :
case V_209 :
case V_93 :
V_449 = V_450 = 2 ;
break;
case V_99 :
V_449 = V_450 = 4 ;
break;
#ifdef F_41
case V_38 :
V_449 = 4 ;
V_450 = 8 ;
break;
#endif
default:
return V_351 ;
}
V_2 -> V_90 = V_449 ;
V_2 -> V_29 = V_450 ;
for (; ; ) {
switch ( V_2 -> V_130 = F_64 ( T_5 , V_2 ) ) {
case 0x66 :
V_453 = true ;
V_2 -> V_90 = V_449 ^ 6 ;
break;
case 0x67 :
if ( V_37 == V_38 )
V_2 -> V_29 = V_450 ^ 12 ;
else
V_2 -> V_29 = V_450 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_454 = true ;
V_2 -> V_436 = ( V_2 -> V_130 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_454 = true ;
V_2 -> V_436 = V_2 -> V_130 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_37 != V_38 )
goto V_457;
V_2 -> V_112 = V_2 -> V_130 ;
continue;
case 0xf0 :
V_2 -> V_217 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_130 ;
break;
default:
goto V_457;
}
V_2 -> V_112 = 0 ;
}
V_457:
if ( V_2 -> V_112 & 8 )
V_2 -> V_90 = 8 ;
V_455 = V_458 [ V_2 -> V_130 ] ;
if ( V_2 -> V_130 == 0x0f ) {
V_2 -> V_456 = 2 ;
V_2 -> V_130 = F_64 ( T_5 , V_2 ) ;
V_455 = V_459 [ V_2 -> V_130 ] ;
if ( V_2 -> V_130 == 0x38 ) {
V_2 -> V_456 = 3 ;
V_2 -> V_130 = F_64 ( T_5 , V_2 ) ;
V_455 = V_460 [ V_2 -> V_130 ] ;
}
}
V_2 -> V_41 = V_455 . V_115 ;
if ( V_2 -> V_41 & V_129 )
V_2 -> V_148 = F_64 ( T_5 , V_2 ) ;
if ( V_2 -> V_456 == 1 && ( V_2 -> V_130 == 0xc5 || V_2 -> V_130 == 0xc4 ) &&
( V_37 == V_38 || ( V_2 -> V_148 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_41 = V_461 ;
}
while ( V_2 -> V_41 & V_462 ) {
switch ( V_2 -> V_41 & V_462 ) {
case V_463 :
V_451 = ( V_2 -> V_148 >> 3 ) & 7 ;
V_455 = V_455 . V_464 . V_465 [ V_451 ] ;
break;
case V_466 :
V_451 = ( V_2 -> V_148 >> 3 ) & 7 ;
if ( ( V_2 -> V_148 >> 6 ) == 3 )
V_455 = V_455 . V_464 . V_467 -> V_468 [ V_451 ] ;
else
V_455 = V_455 . V_464 . V_467 -> V_469 [ V_451 ] ;
break;
case V_470 :
V_451 = V_2 -> V_148 & 7 ;
V_455 = V_455 . V_464 . V_465 [ V_451 ] ;
break;
case V_471 :
if ( V_2 -> V_17 && V_453 )
return V_351 ;
V_452 = V_453 ? 0x66 : V_2 -> V_17 ;
switch ( V_452 ) {
case 0x00 : V_455 = V_455 . V_464 . V_472 -> V_473 ; break;
case 0x66 : V_455 = V_455 . V_464 . V_472 -> V_474 ; break;
case 0xf2 : V_455 = V_455 . V_464 . V_472 -> V_475 ; break;
case 0xf3 : V_455 = V_455 . V_464 . V_472 -> V_476 ; break;
}
break;
case V_477 :
if ( V_2 -> V_148 > 0xbf )
V_455 = V_455 . V_464 . V_478 -> V_479 [ V_2 -> V_148 - 0xc0 ] ;
else
V_455 = V_455 . V_464 . V_478 -> V_120 [ ( V_2 -> V_148 >> 3 ) & 7 ] ;
break;
case V_480 :
if ( ( V_2 -> V_148 >> 6 ) == 3 )
V_455 = V_455 . V_464 . V_481 -> V_468 ;
else
V_455 = V_455 . V_464 . V_481 -> V_469 ;
break;
case V_482 :
if ( V_2 -> V_37 == V_38 )
V_455 = V_455 . V_464 . V_483 -> V_484 ;
else
V_455 = V_455 . V_464 . V_483 -> V_485 ;
break;
default:
return V_351 ;
}
V_2 -> V_41 &= ~ ( V_85 ) V_462 ;
V_2 -> V_41 |= V_455 . V_115 ;
}
if ( V_2 -> V_41 == 0 )
return V_351 ;
V_2 -> V_486 = V_455 . V_464 . V_486 ;
if ( F_45 ( V_2 -> V_487 ) && F_33 ( ! ( V_2 -> V_41 & V_488 ) ) )
return V_351 ;
if ( F_45 ( V_2 -> V_41 &
( V_461 | V_489 | V_490 | V_131 | V_135 | V_491 | V_492 | V_493 |
V_494 ) ) ) {
V_2 -> V_495 = V_455 . V_495 ;
V_2 -> V_12 = V_455 . V_12 ;
if ( V_2 -> V_41 & V_461 )
return V_351 ;
if ( V_37 == V_38 ) {
if ( V_2 -> V_90 == 4 && ( V_2 -> V_41 & V_489 ) )
V_2 -> V_90 = 8 ;
else if ( V_2 -> V_41 & V_493 )
V_2 -> V_90 = 8 ;
}
if ( V_2 -> V_41 & V_490 ) {
if ( V_37 == V_38 )
V_2 -> V_90 = 8 ;
else
V_2 -> V_90 = 4 ;
}
if ( ( V_2 -> V_41 & V_494 ) && V_2 -> V_90 == 2 )
V_2 -> V_90 = 4 ;
if ( V_2 -> V_41 & V_131 )
V_2 -> V_90 = 16 ;
else if ( V_2 -> V_41 & V_135 )
V_2 -> V_90 = 8 ;
}
if ( V_2 -> V_41 & V_129 ) {
V_88 = F_63 ( V_2 , & V_2 -> V_164 ) ;
if ( ! V_454 ) {
V_454 = true ;
V_2 -> V_436 = V_2 -> V_143 ;
}
} else if ( V_2 -> V_41 & V_496 )
V_88 = F_65 ( V_2 , & V_2 -> V_164 ) ;
if ( V_88 != V_87 )
goto V_165;
if ( ! V_454 )
V_2 -> V_436 = V_149 ;
V_2 -> V_164 . V_74 . V_163 . V_47 = V_2 -> V_436 ;
V_88 = F_198 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_41 >> V_497 ) & V_498 ) ;
if ( V_88 != V_87 )
goto V_165;
V_88 = F_198 ( V_2 , & V_2 -> V_239 , ( V_2 -> V_41 >> V_499 ) & V_498 ) ;
if ( V_88 != V_87 )
goto V_165;
V_88 = F_198 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_41 >> V_500 ) & V_498 ) ;
if ( V_2 -> V_162 )
V_2 -> V_417 -> V_74 . V_163 . V_83 = F_13 ( V_2 ,
V_2 -> V_417 -> V_74 . V_163 . V_83 + V_2 -> V_91 ) ;
V_165:
return ( V_88 != V_87 ) ? V_351 : V_352 ;
}
bool F_201 ( struct V_1 * V_2 )
{
return V_2 -> V_41 & V_501 ;
}
static bool F_202 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_130 == 0xa6 ) || ( V_2 -> V_130 == 0xa7 ) ||
( V_2 -> V_130 == 0xae ) || ( V_2 -> V_130 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_502 ) &&
( ( V_2 -> V_183 & V_228 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_503 ) &&
( ( V_2 -> V_183 & V_228 ) == V_228 ) ) ) )
return true ;
return false ;
}
static int F_203 ( struct V_1 * V_2 )
{
bool V_504 = false ;
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
if ( F_45 ( V_504 ) )
return F_21 ( V_2 , V_505 , 0 , false ) ;
return V_87 ;
}
static void F_204 ( struct V_1 * V_2 ,
struct V_119 * V_120 )
{
if ( V_120 -> type == V_136 )
F_56 ( V_2 , & V_120 -> V_218 , V_120 -> V_74 . V_137 ) ;
}
static int F_111 ( struct V_1 * V_2 , void (* F_51)( struct F_111 * ) )
{
T_1 V_115 = ( V_2 -> V_183 & V_117 ) | V_118 ;
if ( ! ( V_2 -> V_41 & V_139 ) )
F_51 += F_205 ( V_2 -> V_25 . V_27 ) * V_506 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_183 = ( V_2 -> V_183 & ~ V_117 ) | ( V_115 & V_117 ) ;
if ( ! F_51 )
return F_28 ( V_2 ) ;
return V_87 ;
}
void F_206 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_162 , 0 ,
( void * ) & V_2 -> V_148 - ( void * ) & V_2 -> V_162 ) ;
V_2 -> V_178 . V_172 = 0 ;
V_2 -> V_178 . V_105 = 0 ;
V_2 -> V_171 . V_105 = 0 ;
}
int F_207 ( struct V_1 * V_2 )
{
const struct V_190 * V_6 = V_2 -> V_6 ;
int V_88 = V_87 ;
int V_507 = V_2 -> V_25 . type ;
V_2 -> V_171 . V_172 = 0 ;
if ( V_2 -> V_217 && ( ! ( V_2 -> V_41 & V_508 ) || V_2 -> V_25 . type != V_151 ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_165;
}
if ( ( V_2 -> V_41 & V_509 ) == V_510 && V_2 -> V_22 . type != V_151 ) {
V_88 = F_26 ( V_2 ) ;
goto V_165;
}
if ( F_45 ( V_2 -> V_41 &
( V_511 | V_512 | V_131 | V_135 | V_491 | V_492 | V_513 | V_514 | String ) ) ) {
if ( ( V_2 -> V_37 == V_38 && ( V_2 -> V_41 & V_511 ) ) ||
( V_2 -> V_41 & V_512 ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_165;
}
if ( ( ( V_2 -> V_41 & ( V_131 | V_135 ) ) && ( ( V_6 -> V_124 ( V_2 , 0 ) & V_126 ) ) )
|| ( ( V_2 -> V_41 & V_131 ) && ! ( V_6 -> V_124 ( V_2 , 4 ) & V_515 ) ) ) {
V_88 = F_26 ( V_2 ) ;
goto V_165;
}
if ( ( V_2 -> V_41 & ( V_131 | V_135 ) ) && ( V_6 -> V_124 ( V_2 , 0 ) & V_125 ) ) {
V_88 = F_29 ( V_2 ) ;
goto V_165;
}
if ( V_2 -> V_41 & V_135 ) {
V_88 = F_203 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_165;
F_204 ( V_2 , & V_2 -> V_22 ) ;
F_204 ( V_2 , & V_2 -> V_239 ) ;
if ( ! ( V_2 -> V_41 & V_516 ) )
F_204 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_45 ( V_2 -> V_517 ) && ( V_2 -> V_41 & V_491 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_518 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( ( V_2 -> V_41 & V_514 ) && V_2 -> V_37 < V_93 ) {
V_88 = F_26 ( V_2 ) ;
goto V_165;
}
if ( ( V_2 -> V_41 & V_513 ) && V_6 -> V_195 ( V_2 ) ) {
if ( V_2 -> V_41 & V_519 )
V_88 = F_26 ( V_2 ) ;
else
V_88 = F_24 ( V_2 , 0 ) ;
goto V_165;
}
if ( V_2 -> V_41 & V_492 ) {
V_88 = V_2 -> V_495 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( F_45 ( V_2 -> V_517 ) && ( V_2 -> V_41 & V_491 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_520 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_182 ) ) == 0 ) {
V_2 -> V_31 = V_2 -> V_91 ;
V_2 -> V_183 &= ~ V_252 ;
goto V_165;
}
}
}
if ( ( V_2 -> V_22 . type == V_151 ) && ! ( V_2 -> V_41 & V_521 ) ) {
V_88 = F_68 ( V_2 , V_2 -> V_22 . V_74 . V_163 ,
V_2 -> V_22 . V_261 , V_2 -> V_22 . V_27 ) ;
if ( V_88 != V_87 )
goto V_165;
V_2 -> V_22 . V_264 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_239 . type == V_151 ) {
V_88 = F_68 ( V_2 , V_2 -> V_239 . V_74 . V_163 ,
& V_2 -> V_239 . V_121 , V_2 -> V_239 . V_27 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( ( V_2 -> V_41 & V_522 ) == V_523 )
goto V_524;
if ( ( V_2 -> V_25 . type == V_151 ) && ! ( V_2 -> V_41 & V_516 ) ) {
V_88 = F_68 ( V_2 , V_2 -> V_25 . V_74 . V_163 ,
& V_2 -> V_25 . V_121 , V_2 -> V_25 . V_27 ) ;
if ( V_88 != V_87 ) {
if ( ! ( V_2 -> V_41 & V_525 ) &&
V_88 == V_56 &&
V_2 -> V_52 . V_53 == V_526 )
V_2 -> V_52 . V_54 |= V_527 ;
goto V_165;
}
}
V_2 -> V_25 . V_264 = V_2 -> V_25 . V_23 ;
V_524:
if ( F_45 ( V_2 -> V_517 ) && ( V_2 -> V_41 & V_491 ) ) {
V_88 = F_7 ( V_2 , V_2 -> V_12 ,
V_528 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) )
V_2 -> V_183 |= V_252 ;
else
V_2 -> V_183 &= ~ V_252 ;
if ( V_2 -> V_486 ) {
if ( V_2 -> V_41 & V_529 ) {
void (* F_51)( struct F_111 * ) = ( void * ) V_2 -> V_486 ;
V_88 = F_111 ( V_2 , F_51 ) ;
if ( V_88 != V_87 )
goto V_165;
goto F_84;
}
V_88 = V_2 -> V_486 ( V_2 ) ;
if ( V_88 != V_87 )
goto V_165;
goto F_84;
}
if ( V_2 -> V_456 == 2 )
goto V_530;
else if ( V_2 -> V_456 == 3 )
goto V_531;
switch ( V_2 -> V_130 ) {
case 0x70 ... 0x7f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_183 ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_74 . V_163 . V_83 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_74 . V_9 == F_3 ( V_2 , V_244 ) )
V_2 -> V_25 . type = V_219 ;
else
V_88 = F_139 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_90 ) {
case 2 : V_2 -> V_25 . V_121 = ( V_159 ) V_2 -> V_25 . V_121 ; break;
case 4 : V_2 -> V_25 . V_121 = ( V_167 ) V_2 -> V_25 . V_121 ; break;
case 8 : V_2 -> V_25 . V_121 = ( V_160 ) V_2 -> V_25 . V_121 ; break;
}
break;
case 0xcc :
V_88 = F_100 ( V_2 , 3 ) ;
break;
case 0xcd :
V_88 = F_100 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0xce :
if ( V_2 -> V_183 & V_230 )
V_88 = F_100 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
V_2 -> V_25 . type = V_219 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_532 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_183 ^= V_225 ;
break;
case 0xf8 :
V_2 -> V_183 &= ~ V_225 ;
break;
case 0xf9 :
V_2 -> V_183 |= V_225 ;
break;
case 0xfc :
V_2 -> V_183 &= ~ V_184 ;
break;
case 0xfd :
V_2 -> V_183 |= V_184 ;
break;
default:
goto V_533;
}
if ( V_88 != V_87 )
goto V_165;
F_84:
if ( V_2 -> V_41 & V_534 ) {
F_208 ( V_2 -> V_22 . type == V_151 || V_2 -> V_22 . type == V_185 ) ;
V_88 = F_84 ( V_2 , & V_2 -> V_22 ) ;
if ( V_88 != V_87 )
goto V_165;
}
if ( ! ( V_2 -> V_41 & V_525 ) ) {
V_88 = F_84 ( V_2 , & V_2 -> V_25 ) ;
if ( V_88 != V_87 )
goto V_165;
}
V_2 -> V_25 . type = V_507 ;
if ( ( V_2 -> V_41 & V_509 ) == V_535 )
F_131 ( V_2 , V_156 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_41 & V_522 ) == V_536 )
F_131 ( V_2 , V_158 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
unsigned int V_181 ;
struct V_169 * V_301 = & V_2 -> V_178 ;
if ( ( V_2 -> V_41 & V_509 ) == V_535 )
V_181 = V_2 -> V_22 . V_181 ;
else
V_181 = V_2 -> V_25 . V_181 ;
F_16 ( V_2 , V_182 , - V_181 ) ;
if ( ! F_202 ( V_2 ) ) {
if ( ( V_301 -> V_105 != 0 || F_1 ( V_2 , V_182 ) & 0x3ff ) &&
( V_301 -> V_105 == 0 || V_301 -> V_105 != V_301 -> V_172 ) ) {
V_2 -> V_171 . V_105 = 0 ;
F_4 ( V_2 ) ;
return V_537 ;
}
goto V_165;
}
V_2 -> V_183 &= ~ V_252 ;
}
V_2 -> V_31 = V_2 -> V_91 ;
V_165:
if ( V_88 == V_56 ) {
F_22 ( V_2 -> V_52 . V_53 > 0x1f ) ;
V_2 -> V_538 = true ;
}
if ( V_88 == V_539 )
return V_540 ;
if ( V_88 == V_87 )
F_4 ( V_2 ) ;
return ( V_88 == V_214 ) ? V_351 : V_352 ;
V_530:
switch ( V_2 -> V_130 ) {
case 0x09 :
( V_2 -> V_6 -> V_541 ) ( V_2 ) ;
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
V_6 -> V_401 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_121 ) ;
break;
case 0x40 ... 0x4f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_183 ) )
V_2 -> V_25 . V_121 = V_2 -> V_22 . V_121 ;
else if ( V_2 -> V_37 != V_38 ||
V_2 -> V_90 != 4 )
V_2 -> V_25 . type = V_219 ;
break;
case 0x80 ... 0x8f :
if ( F_50 ( V_2 -> V_130 , V_2 -> V_183 ) )
V_88 = F_42 ( V_2 , V_2 -> V_22 . V_121 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_121 = F_50 ( V_2 -> V_130 , V_2 -> V_183 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_22 . V_27 == 1 ) ? ( T_5 ) V_2 -> V_22 . V_121
: ( T_2 ) V_2 -> V_22 . V_121 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_90 ;
V_2 -> V_25 . V_121 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_159 ) V_2 -> V_22 . V_121 :
( V_167 ) V_2 -> V_22 . V_121 ;
break;
default:
goto V_533;
}
V_531:
if ( V_88 != V_87 )
goto V_165;
goto F_84;
V_533:
return V_351 ;
}
void F_209 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_210 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
