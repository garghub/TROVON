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
static void F_9 ( unsigned long * V_9 , T_2 V_34 , int V_27 )
{
switch ( V_27 ) {
case 1 :
* ( V_35 * ) V_9 = ( V_35 ) V_34 ;
break;
case 2 :
* ( V_36 * ) V_9 = ( V_36 ) V_34 ;
break;
case 4 :
* V_9 = ( V_37 ) V_34 ;
break;
case 8 :
* V_9 = V_34 ;
break;
}
}
static inline unsigned long F_10 ( struct V_1 * V_2 )
{
return ( 1UL << ( V_2 -> V_29 << 3 ) ) - 1 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
V_36 V_38 ;
struct V_39 V_40 ;
if ( V_2 -> V_41 == V_42 )
return ~ 0UL ;
V_2 -> V_6 -> V_43 ( V_2 , & V_38 , & V_40 , NULL , V_44 ) ;
return ~ 0U >> ( ( V_40 . V_45 ^ 1 ) * 16 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return ( F_13 ( F_11 ( V_2 ) ) + 1 ) >> 3 ;
}
static inline unsigned long
F_14 ( struct V_1 * V_2 , unsigned long V_9 )
{
if ( V_2 -> V_29 == sizeof( unsigned long ) )
return V_9 ;
else
return V_9 & F_10 ( V_2 ) ;
}
static inline unsigned long
F_15 ( struct V_1 * V_2 , int V_9 )
{
return F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static void F_16 ( T_1 * V_9 , T_1 V_33 , int V_46 )
{
F_8 ( V_9 , * V_9 + V_46 , V_33 ) ;
}
static inline void
F_17 ( struct V_1 * V_2 , int V_9 , int V_46 )
{
T_1 * V_47 = F_3 ( V_2 , V_9 ) ;
F_9 ( V_47 , * V_47 + V_46 , V_2 -> V_29 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_46 )
{
F_16 ( F_3 ( V_2 , V_48 ) , F_11 ( V_2 ) , V_46 ) ;
}
static V_37 F_19 ( struct V_39 * V_49 )
{
V_37 V_50 = F_20 ( V_49 ) ;
return V_49 -> V_51 ? ( V_50 << 12 ) | 0xfff : V_50 ;
}
static unsigned long F_21 ( struct V_1 * V_2 , int V_52 )
{
if ( V_2 -> V_41 == V_42 && V_52 < V_53 )
return 0 ;
return V_2 -> V_6 -> V_54 ( V_2 , V_52 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_55 ,
V_37 error , bool V_56 )
{
F_23 ( V_55 > 0x1f ) ;
V_2 -> V_57 . V_58 = V_55 ;
V_2 -> V_57 . V_59 = error ;
V_2 -> V_57 . V_60 = V_56 ;
return V_61 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_62 , 0 , false ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_63 )
{
return F_22 ( V_2 , V_64 , V_63 , true ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_63 )
{
return F_22 ( V_2 , V_65 , V_63 , true ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_66 , 0 , false ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_63 )
{
return F_22 ( V_2 , V_67 , V_63 , true ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_68 , 0 , false ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_69 , 0 , false ) ;
}
static V_36 F_31 ( struct V_1 * V_2 , unsigned V_52 )
{
V_36 V_70 ;
struct V_39 V_49 ;
V_2 -> V_6 -> V_43 ( V_2 , & V_70 , & V_49 , NULL , V_52 ) ;
return V_70 ;
}
static void F_32 ( struct V_1 * V_2 , V_36 V_70 ,
unsigned V_52 )
{
V_36 V_71 ;
V_37 V_72 ;
struct V_39 V_49 ;
V_2 -> V_6 -> V_43 ( V_2 , & V_71 , & V_49 , & V_72 , V_52 ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_52 ) ;
}
static bool F_33 ( struct V_1 * V_2 , unsigned V_74 )
{
if ( F_34 ( V_74 < 16 ) )
return false ;
if ( V_2 -> V_45 & V_75 )
return true ;
else if ( V_2 -> V_45 & V_76 )
return false ;
else if ( V_2 -> V_45 & V_77 )
return false ;
else
return true ;
}
static T_3 int F_35 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
unsigned * V_80 , unsigned V_74 ,
bool V_81 , bool V_82 ,
enum V_83 V_41 , T_1 * V_84 )
{
struct V_39 V_49 ;
bool V_85 ;
T_1 V_86 ;
V_37 V_87 ;
V_36 V_38 ;
V_86 = F_21 ( V_2 , V_79 . V_52 ) + V_79 . V_88 ;
* V_80 = 0 ;
switch ( V_41 ) {
case V_42 :
* V_84 = V_86 ;
if ( F_36 ( V_86 ) )
goto V_89;
* V_80 = F_37 ( T_2 , ~ 0u , ( 1ull << 48 ) - V_86 ) ;
if ( V_74 > * V_80 )
goto V_89;
break;
default:
* V_84 = V_86 = ( V_37 ) V_86 ;
V_85 = V_2 -> V_6 -> V_43 ( V_2 , & V_38 , & V_49 , NULL ,
V_79 . V_52 ) ;
if ( ! V_85 )
goto V_89;
if ( ( ( ( V_2 -> V_41 != V_90 ) && ( V_49 . type & 8 ) )
|| ! ( V_49 . type & 2 ) ) && V_81 )
goto V_89;
if ( ! V_82 && ( V_49 . type & 8 ) && ! ( V_49 . type & 2 ) )
goto V_89;
V_87 = F_19 ( & V_49 ) ;
if ( ! ( V_49 . type & 8 ) && ( V_49 . type & 4 ) ) {
if ( V_79 . V_88 <= V_87 )
goto V_89;
V_87 = V_49 . V_45 ? 0xffffffff : 0xffff ;
}
if ( V_79 . V_88 > V_87 )
goto V_89;
if ( V_87 == 0xffffffff )
* V_80 = ~ 0u ;
else {
* V_80 = ( T_2 ) V_87 + 1 - V_79 . V_88 ;
if ( V_74 > * V_80 )
goto V_89;
}
break;
}
if ( F_33 ( V_2 , V_74 ) && ( ( V_86 & ( V_74 - 1 ) ) != 0 ) )
return F_25 ( V_2 , 0 ) ;
return V_91 ;
V_89:
if ( V_79 . V_52 == V_44 )
return F_26 ( V_2 , 0 ) ;
else
return F_25 ( V_2 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
unsigned V_74 , bool V_81 ,
T_1 * V_84 )
{
unsigned V_80 ;
return F_35 ( V_2 , V_79 , & V_80 , V_74 , V_81 , false ,
V_2 -> V_41 , V_84 ) ;
}
static inline int F_39 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_83 V_41 )
{
T_1 V_84 ;
int V_92 ;
unsigned V_80 ;
struct V_78 V_79 = { . V_52 = V_93 ,
. V_88 = V_25 } ;
if ( V_2 -> V_94 != sizeof( unsigned long ) )
V_79 . V_88 = V_25 & ( ( 1UL << ( V_2 -> V_94 << 3 ) ) - 1 ) ;
V_92 = F_35 ( V_2 , V_79 , & V_80 , 1 , false , true , V_41 , & V_84 ) ;
if ( V_92 == V_91 )
V_2 -> V_95 = V_79 . V_88 ;
return V_92 ;
}
static inline int F_40 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_39 ( V_2 , V_25 , V_2 -> V_41 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_25 ,
const struct V_39 * V_96 )
{
enum V_83 V_41 = V_2 -> V_41 ;
int V_92 ;
#ifdef F_42
if ( V_2 -> V_41 >= V_97 ) {
if ( V_96 -> V_98 ) {
T_2 V_99 = 0 ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( V_99 & V_102 )
V_41 = V_42 ;
} else
V_41 = V_103 ;
}
#endif
if ( V_41 == V_97 || V_41 == V_103 )
V_41 = V_96 -> V_45 ? V_103 : V_97 ;
V_92 = F_39 ( V_2 , V_25 , V_41 ) ;
if ( V_92 == V_91 )
V_2 -> V_41 = V_41 ;
return V_92 ;
}
static inline int F_43 ( struct V_1 * V_2 , int V_104 )
{
return F_40 ( V_2 , V_2 -> V_95 + V_104 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
void * V_105 ,
unsigned V_74 )
{
int V_92 ;
T_1 V_84 ;
V_92 = F_38 ( V_2 , V_79 , V_74 , false , & V_84 ) ;
if ( V_92 != V_91 )
return V_92 ;
return V_2 -> V_6 -> V_106 ( V_2 , V_84 , V_105 , V_74 , & V_2 -> V_57 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_107 )
{
int V_92 ;
unsigned V_74 , V_80 ;
unsigned long V_84 ;
int V_108 = V_2 -> V_82 . V_109 - V_2 -> V_82 . V_105 ;
struct V_78 V_79 = { . V_52 = V_93 ,
. V_88 = V_2 -> V_31 + V_108 } ;
V_92 = F_35 ( V_2 , V_79 , & V_80 , 0 , false , true , V_2 -> V_41 ,
& V_84 ) ;
if ( F_46 ( V_92 != V_91 ) )
return V_92 ;
V_74 = F_37 ( unsigned , 15UL ^ V_108 , V_80 ) ;
V_74 = F_37 ( unsigned , V_74 , V_110 - F_47 ( V_84 ) ) ;
if ( F_46 ( V_74 < V_107 ) )
return F_25 ( V_2 , 0 ) ;
V_92 = V_2 -> V_6 -> V_82 ( V_2 , V_84 , V_2 -> V_82 . V_109 ,
V_74 , & V_2 -> V_57 ) ;
if ( F_46 ( V_92 != V_91 ) )
return V_92 ;
V_2 -> V_82 . V_109 += V_74 ;
return V_91 ;
}
static T_3 int F_48 ( struct V_1 * V_2 ,
unsigned V_74 )
{
unsigned V_111 = V_2 -> V_82 . V_109 - V_2 -> V_82 . V_112 ;
if ( F_46 ( V_111 < V_74 ) )
return F_45 ( V_2 , V_74 - V_111 ) ;
else
return V_91 ;
}
static void * F_49 ( struct V_1 * V_2 , V_35 V_19 ,
int V_113 )
{
void * V_114 ;
int V_115 = ( V_2 -> V_116 == 0 ) && V_113 ;
if ( V_115 && V_19 >= 4 && V_19 < 8 )
V_114 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_114 = F_3 ( V_2 , V_19 ) ;
return V_114 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
V_36 * V_74 , unsigned long * V_117 , int V_94 )
{
int V_92 ;
if ( V_94 == 2 )
V_94 = 3 ;
* V_117 = 0 ;
V_92 = F_44 ( V_2 , V_79 , V_74 , 2 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_79 . V_88 += 2 ;
V_92 = F_44 ( V_2 , V_79 , V_117 , V_94 ) ;
return V_92 ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_118 ;
return F_52 ( V_2 , V_119 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_118 ;
return F_52 ( V_2 , V_120 ) ;
}
static T_3 V_35 F_54 ( unsigned int V_121 , unsigned long V_122 )
{
V_35 V_92 ;
void (* F_55)( void ) = ( void * ) V_123 + 4 * ( V_121 & 0xf ) ;
V_122 = ( V_122 & V_124 ) | V_125 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_92 ;
}
static void F_56 ( struct V_126 * V_127 )
{
switch ( V_127 -> V_27 ) {
case 1 :
V_127 -> V_34 = * ( V_35 * ) V_127 -> V_79 . V_9 ;
break;
case 2 :
V_127 -> V_34 = * ( V_36 * ) V_127 -> V_79 . V_9 ;
break;
case 4 :
V_127 -> V_34 = * ( V_37 * ) V_127 -> V_79 . V_9 ;
break;
case 8 :
V_127 -> V_34 = * ( T_2 * ) V_127 -> V_79 . V_9 ;
break;
}
}
static void F_57 ( struct V_1 * V_2 , T_4 * V_105 , int V_9 )
{
V_2 -> V_6 -> V_128 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_42
case 8 : asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_58 () ;
}
V_2 -> V_6 -> V_129 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , T_4 * V_105 ,
int V_9 )
{
V_2 -> V_6 -> V_128 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_42
case 8 : asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_58 () ;
}
V_2 -> V_6 -> V_129 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_2 * V_105 , int V_9 )
{
V_2 -> V_6 -> V_128 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_58 () ;
}
V_2 -> V_6 -> V_129 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , T_2 * V_105 , int V_9 )
{
V_2 -> V_6 -> V_128 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_58 () ;
}
V_2 -> V_6 -> V_129 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_130 ( V_2 , 0 ) & ( V_131 | V_132 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_128 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_129 ( V_2 ) ;
return V_91 ;
}
static int F_63 ( struct V_1 * V_2 )
{
V_36 V_133 ;
if ( V_2 -> V_6 -> V_130 ( V_2 , 0 ) & ( V_131 | V_132 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_128 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_129 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_133 ;
return V_91 ;
}
static int F_64 ( struct V_1 * V_2 )
{
V_36 V_134 ;
if ( V_2 -> V_6 -> V_130 ( V_2 , 0 ) & ( V_131 | V_132 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_128 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_129 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_134 ;
return V_91 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_45 & V_135 ) )
V_9 = ( V_2 -> V_136 & 7 ) | ( ( V_2 -> V_116 & 1 ) << 3 ) ;
if ( V_2 -> V_45 & V_137 ) {
V_127 -> type = V_138 ;
V_127 -> V_27 = 16 ;
V_127 -> V_79 . V_139 = V_9 ;
F_57 ( V_2 , & V_127 -> V_140 , V_9 ) ;
return;
}
if ( V_2 -> V_45 & V_141 ) {
V_9 &= 7 ;
V_127 -> type = V_142 ;
V_127 -> V_27 = 8 ;
V_127 -> V_79 . V_143 = V_9 ;
return;
}
V_127 -> type = V_144 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_9 = F_49 ( V_2 , V_9 , V_2 -> V_45 & V_145 ) ;
F_56 ( V_127 ) ;
V_127 -> V_146 = V_127 -> V_34 ;
}
static void F_66 ( struct V_1 * V_2 , int V_147 )
{
if ( V_147 == V_48 || V_147 == V_148 )
V_2 -> V_149 = V_44 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
V_35 V_150 ;
int V_151 , V_147 , V_152 ;
int V_92 = V_91 ;
T_1 V_153 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_116 << 1 ) & 8 ) ;
V_151 = ( V_2 -> V_116 << 2 ) & 8 ;
V_147 = ( V_2 -> V_116 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_154 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_154 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_147 | ( V_2 -> V_154 & 0x07 ) ;
V_2 -> V_149 = V_155 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_45 & V_156 ) ) {
V_127 -> type = V_144 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_9 = F_49 ( V_2 , V_2 -> V_20 ,
V_2 -> V_45 & V_145 ) ;
if ( V_2 -> V_45 & V_137 ) {
V_127 -> type = V_138 ;
V_127 -> V_27 = 16 ;
V_127 -> V_79 . V_139 = V_2 -> V_20 ;
F_57 ( V_2 , & V_127 -> V_140 , V_2 -> V_20 ) ;
return V_92 ;
}
if ( V_2 -> V_45 & V_141 ) {
V_127 -> type = V_142 ;
V_127 -> V_27 = 8 ;
V_127 -> V_79 . V_143 = V_2 -> V_20 & 7 ;
return V_92 ;
}
F_56 ( V_127 ) ;
return V_92 ;
}
V_127 -> type = V_157 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_158 = F_1 ( V_2 , V_159 ) ;
unsigned V_160 = F_1 ( V_2 , V_148 ) ;
unsigned V_161 = F_1 ( V_2 , V_162 ) ;
unsigned V_163 = F_1 ( V_2 , V_164 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_153 += F_68 ( V_36 , V_2 ) ;
break;
case 1 :
V_153 += F_68 ( V_165 , V_2 ) ;
break;
case 2 :
V_153 += F_68 ( V_36 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_153 += V_158 + V_161 ;
break;
case 1 :
V_153 += V_158 + V_163 ;
break;
case 2 :
V_153 += V_160 + V_161 ;
break;
case 3 :
V_153 += V_160 + V_163 ;
break;
case 4 :
V_153 += V_161 ;
break;
case 5 :
V_153 += V_163 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_153 += V_160 ;
break;
case 7 :
V_153 += V_158 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_149 = V_44 ;
V_153 = ( V_36 ) V_153 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_150 = F_68 ( V_35 , V_2 ) ;
V_151 |= ( V_150 >> 3 ) & 7 ;
V_147 |= V_150 & 7 ;
V_152 = V_150 >> 6 ;
if ( ( V_147 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_153 += F_68 ( V_166 , V_2 ) ;
else {
V_153 += F_1 ( V_2 , V_147 ) ;
F_66 ( V_2 , V_147 ) ;
if ( ( V_2 -> V_45 & V_167 ) &&
V_147 == V_48 )
V_153 += V_2 -> V_94 ;
}
if ( V_151 != 4 )
V_153 += F_1 ( V_2 , V_151 ) << V_152 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_153 += F_68 ( V_166 , V_2 ) ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_168 = 1 ;
} else {
V_147 = V_2 -> V_20 ;
V_153 += F_1 ( V_2 , V_147 ) ;
F_66 ( V_2 , V_147 ) ;
}
switch ( V_2 -> V_18 ) {
case 1 :
V_153 += F_68 ( V_165 , V_2 ) ;
break;
case 2 :
V_153 += F_68 ( V_166 , V_2 ) ;
break;
}
}
V_127 -> V_79 . V_169 . V_88 = V_153 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_170 . V_79 . V_169 . V_88 = ( V_37 ) V_2 -> V_170 . V_79 . V_169 . V_88 ;
V_171:
return V_92 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
int V_92 = V_91 ;
V_127 -> type = V_157 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_127 -> V_79 . V_169 . V_88 = F_68 ( V_36 , V_2 ) ;
break;
case 4 :
V_127 -> V_79 . V_169 . V_88 = F_68 ( V_37 , V_2 ) ;
break;
case 8 :
V_127 -> V_79 . V_169 . V_88 = F_68 ( T_2 , V_2 ) ;
break;
}
V_171:
return V_92 ;
}
static void F_70 ( struct V_1 * V_2 )
{
long V_172 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_157 && V_2 -> V_22 . type == V_144 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_172 = ( V_173 ) V_2 -> V_22 . V_34 & ( V_173 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_172 = ( V_166 ) V_2 -> V_22 . V_34 & ( V_166 ) V_33 ;
else
V_172 = ( V_174 ) V_2 -> V_22 . V_34 & ( V_174 ) V_33 ;
V_2 -> V_25 . V_79 . V_169 . V_88 = F_14 ( V_2 ,
V_2 -> V_25 . V_79 . V_169 . V_88 + ( V_172 >> 3 ) ) ;
}
V_2 -> V_22 . V_34 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned long V_79 , void * V_32 , unsigned V_74 )
{
int V_92 ;
struct V_175 * V_176 = & V_2 -> V_177 ;
if ( V_176 -> V_178 < V_176 -> V_109 )
goto V_179;
F_23 ( ( V_176 -> V_109 + V_74 ) >= sizeof( V_176 -> V_105 ) ) ;
V_92 = V_2 -> V_6 -> F_71 ( V_2 , V_79 , V_176 -> V_105 + V_176 -> V_109 , V_74 ,
& V_2 -> V_57 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_176 -> V_109 += V_74 ;
V_179:
memcpy ( V_32 , V_176 -> V_105 + V_176 -> V_178 , V_74 ) ;
V_176 -> V_178 += V_74 ;
return V_91 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
void * V_105 ,
unsigned V_74 )
{
int V_92 ;
T_1 V_84 ;
V_92 = F_38 ( V_2 , V_79 , V_74 , false , & V_84 ) ;
if ( V_92 != V_91 )
return V_92 ;
return F_71 ( V_2 , V_84 , V_105 , V_74 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
const void * V_105 ,
unsigned V_74 )
{
int V_92 ;
T_1 V_84 ;
V_92 = F_38 ( V_2 , V_79 , V_74 , true , & V_84 ) ;
if ( V_92 != V_91 )
return V_92 ;
return V_2 -> V_6 -> V_180 ( V_2 , V_84 , V_105 , V_74 ,
& V_2 -> V_57 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
const void * V_181 , const void * V_105 ,
unsigned V_74 )
{
int V_92 ;
T_1 V_84 ;
V_92 = F_38 ( V_2 , V_79 , V_74 , true , & V_84 ) ;
if ( V_92 != V_91 )
return V_92 ;
return V_2 -> V_6 -> V_182 ( V_2 , V_84 , V_181 , V_105 ,
V_74 , & V_2 -> V_57 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
unsigned int V_74 , unsigned short V_183 ,
void * V_32 )
{
struct V_175 * V_92 = & V_2 -> V_184 ;
if ( V_92 -> V_178 == V_92 -> V_109 ) {
unsigned int V_185 , V_186 ;
unsigned int V_187 = V_2 -> V_17 ?
F_14 ( V_2 , F_1 ( V_2 , V_188 ) ) : 1 ;
V_185 = ( V_2 -> V_189 & V_190 ) ?
F_47 ( F_1 ( V_2 , V_164 ) ) :
V_110 - F_47 ( F_1 ( V_2 , V_164 ) ) ;
V_186 = F_76 ( V_185 , ( unsigned int ) sizeof( V_92 -> V_105 ) / V_74 , V_187 ) ;
if ( V_186 == 0 )
V_186 = 1 ;
V_92 -> V_178 = V_92 -> V_109 = 0 ;
if ( ! V_2 -> V_6 -> F_75 ( V_2 , V_74 , V_183 , V_92 -> V_105 , V_186 ) )
return 0 ;
V_92 -> V_109 = V_186 * V_74 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) &&
! ( V_2 -> V_189 & V_190 ) ) {
V_2 -> V_25 . V_105 = V_92 -> V_105 + V_92 -> V_178 ;
V_2 -> V_25 . type = V_191 ;
V_2 -> V_25 . V_187 = ( V_92 -> V_109 - V_92 -> V_178 ) / V_74 ;
V_92 -> V_178 = V_92 -> V_109 ;
} else {
memcpy ( V_32 , V_92 -> V_105 + V_92 -> V_178 , V_74 ) ;
V_92 -> V_178 += V_74 ;
}
return 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
V_36 V_192 , struct V_39 * V_49 )
{
struct V_193 V_194 ;
T_1 V_79 ;
V_2 -> V_6 -> V_195 ( V_2 , & V_194 ) ;
if ( V_194 . V_74 < V_192 * 8 + 7 )
return F_25 ( V_2 , V_192 << 3 | 0x2 ) ;
V_79 = V_194 . V_117 + V_192 * 8 ;
return V_2 -> V_6 -> V_106 ( V_2 , V_79 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_193 * V_194 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
V_37 V_72 = 0 ;
if ( V_70 & 1 << 2 ) {
struct V_39 V_49 ;
V_36 V_38 ;
memset ( V_194 , 0 , sizeof *V_194 ) ;
if ( ! V_6 -> V_43 ( V_2 , & V_38 , & V_49 , & V_72 ,
V_197 ) )
return;
V_194 -> V_74 = F_19 ( & V_49 ) ;
V_194 -> V_117 = F_79 ( & V_49 ) | ( ( T_2 ) V_72 << 32 ) ;
} else
V_6 -> V_198 ( V_2 , V_194 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
V_36 V_70 , T_1 * V_199 )
{
struct V_193 V_194 ;
V_36 V_192 = V_70 >> 3 ;
T_1 V_79 ;
F_78 ( V_2 , V_70 , & V_194 ) ;
if ( V_194 . V_74 < V_192 * 8 + 7 )
return F_25 ( V_2 , V_70 & 0xfffc ) ;
V_79 = V_194 . V_117 + V_192 * 8 ;
#ifdef F_42
if ( V_79 >> 32 != 0 ) {
T_2 V_99 = 0 ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( ! ( V_99 & V_102 ) )
V_79 &= ( V_37 ) - 1 ;
}
#endif
* V_199 = V_79 ;
return V_91 ;
}
static int F_81 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 ,
T_1 * V_199 )
{
int V_92 ;
V_92 = F_80 ( V_2 , V_70 , V_199 ) ;
if ( V_92 != V_91 )
return V_92 ;
return V_2 -> V_6 -> V_106 ( V_2 , * V_199 , V_49 , sizeof( * V_49 ) ,
& V_2 -> V_57 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 )
{
int V_92 ;
T_1 V_79 ;
V_92 = F_80 ( V_2 , V_70 , & V_79 ) ;
if ( V_92 != V_91 )
return V_92 ;
return V_2 -> V_6 -> V_200 ( V_2 , V_79 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 , V_35 V_201 ,
enum V_202 V_203 ,
struct V_39 * V_49 )
{
struct V_39 V_204 , V_205 ;
V_35 V_206 , V_207 ;
unsigned V_208 = V_64 ;
V_37 V_209 = 0 ;
bool V_210 = ! ( V_70 & ~ 0x3 ) ;
T_1 V_211 ;
int V_212 ;
V_36 V_71 ;
V_37 V_72 = 0 ;
memset ( & V_204 , 0 , sizeof V_204 ) ;
if ( V_2 -> V_41 == V_90 ) {
V_2 -> V_6 -> V_43 ( V_2 , & V_71 , & V_204 , NULL , V_52 ) ;
F_84 ( & V_204 , V_70 << 4 ) ;
goto V_213;
} else if ( V_52 <= V_214 && V_2 -> V_41 == V_215 ) {
F_84 ( & V_204 , V_70 << 4 ) ;
F_85 ( & V_204 , 0xffff ) ;
V_204 . type = 3 ;
V_204 . V_114 = 1 ;
V_204 . V_216 = 1 ;
V_204 . V_206 = 3 ;
goto V_213;
}
V_207 = V_70 & 3 ;
if ( ( V_52 == V_93
|| ( V_52 == V_44
&& ( V_2 -> V_41 != V_42 || V_207 != V_201 ) )
|| V_52 == V_217 )
&& V_210 )
goto V_57;
if ( V_52 == V_217 && ( V_70 & ( 1 << 2 ) ) )
goto V_57;
if ( V_210 )
goto V_213;
V_212 = F_81 ( V_2 , V_70 , & V_204 , & V_211 ) ;
if ( V_212 != V_91 )
return V_212 ;
V_209 = V_70 & 0xfffc ;
V_208 = ( V_203 == V_218 ) ? V_67 :
V_64 ;
if ( V_52 <= V_214 && ! V_204 . V_216 ) {
if ( V_203 == V_219 )
return V_220 ;
goto V_57;
}
if ( ! V_204 . V_114 ) {
V_208 = ( V_52 == V_44 ) ? V_65 : V_221 ;
goto V_57;
}
V_206 = V_204 . V_206 ;
switch ( V_52 ) {
case V_44 :
if ( V_207 != V_201 || ( V_204 . type & 0xa ) != 0x2 || V_206 != V_201 )
goto V_57;
break;
case V_93 :
if ( ! ( V_204 . type & 8 ) )
goto V_57;
if ( V_204 . type & 4 ) {
if ( V_206 > V_201 )
goto V_57;
} else {
if ( V_207 > V_201 || V_206 != V_201 )
goto V_57;
}
if ( V_204 . V_45 && V_204 . V_98 ) {
T_2 V_99 = 0 ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( V_99 & V_102 )
goto V_57;
}
V_70 = ( V_70 & 0xfffc ) | V_201 ;
break;
case V_217 :
if ( V_204 . V_216 || ( V_204 . type != 1 && V_204 . type != 9 ) )
goto V_57;
V_205 = V_204 ;
V_204 . type |= 2 ;
V_212 = V_2 -> V_6 -> V_182 ( V_2 , V_211 , & V_205 , & V_204 ,
sizeof( V_204 ) , & V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
break;
case V_197 :
if ( V_204 . V_216 || V_204 . type != 2 )
goto V_57;
break;
default:
if ( ( V_204 . type & 0xa ) == 0x8 ||
( ( ( V_204 . type & 0xc ) != 0xc ) &&
( V_207 > V_206 && V_201 > V_206 ) ) )
goto V_57;
break;
}
if ( V_204 . V_216 ) {
if ( ! ( V_204 . type & 1 ) ) {
V_204 . type |= 1 ;
V_212 = F_82 ( V_2 , V_70 ,
& V_204 ) ;
if ( V_212 != V_91 )
return V_212 ;
}
} else if ( V_2 -> V_41 == V_42 ) {
V_212 = V_2 -> V_6 -> V_106 ( V_2 , V_211 + 8 , & V_72 ,
sizeof( V_72 ) , & V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
if ( F_36 ( F_79 ( & V_204 ) |
( ( T_2 ) V_72 << 32 ) ) )
return F_25 ( V_2 , 0 ) ;
}
V_213:
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_204 , V_72 , V_52 ) ;
if ( V_49 )
* V_49 = V_204 ;
return V_91 ;
V_57:
return F_22 ( V_2 , V_208 , V_209 , true ) ;
}
static int F_86 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 )
{
V_35 V_201 = V_2 -> V_6 -> V_201 ( V_2 ) ;
return F_83 ( V_2 , V_70 , V_52 , V_201 ,
V_222 , NULL ) ;
}
static void F_87 ( struct V_126 * V_127 )
{
return F_9 ( V_127 -> V_79 . V_9 , V_127 -> V_34 , V_127 -> V_27 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
switch ( V_127 -> type ) {
case V_144 :
F_87 ( V_127 ) ;
break;
case V_157 :
if ( V_2 -> V_223 )
return F_74 ( V_2 ,
V_127 -> V_79 . V_169 ,
& V_127 -> V_146 ,
& V_127 -> V_34 ,
V_127 -> V_27 ) ;
else
return F_73 ( V_2 ,
V_127 -> V_79 . V_169 ,
& V_127 -> V_34 ,
V_127 -> V_27 ) ;
break;
case V_191 :
return F_73 ( V_2 ,
V_127 -> V_79 . V_169 ,
V_127 -> V_105 ,
V_127 -> V_27 * V_127 -> V_187 ) ;
break;
case V_138 :
F_59 ( V_2 , & V_127 -> V_140 , V_127 -> V_79 . V_139 ) ;
break;
case V_142 :
F_61 ( V_2 , & V_127 -> V_224 , V_127 -> V_79 . V_143 ) ;
break;
case V_118 :
break;
default:
break;
}
return V_91 ;
}
static int F_89 ( struct V_1 * V_2 , void * V_105 , int V_27 )
{
struct V_78 V_79 ;
F_18 ( V_2 , - V_27 ) ;
V_79 . V_88 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_79 . V_52 = V_44 ;
return F_73 ( V_2 , V_79 , V_105 , V_27 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_118 ;
return F_89 ( V_2 , & V_2 -> V_22 . V_34 , V_2 -> V_94 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
void * V_32 , int V_225 )
{
int V_92 ;
struct V_78 V_79 ;
V_79 . V_88 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_79 . V_52 = V_44 ;
V_92 = F_72 ( V_2 , V_79 , V_32 , V_225 ) ;
if ( V_92 != V_91 )
return V_92 ;
F_18 ( V_2 , V_225 ) ;
return V_92 ;
}
static int F_92 ( struct V_1 * V_2 )
{
return F_91 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_94 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
void * V_32 , int V_225 )
{
int V_92 ;
unsigned long V_34 , V_226 ;
int V_227 = ( V_2 -> V_189 & V_228 ) >> V_229 ;
int V_201 = V_2 -> V_6 -> V_201 ( V_2 ) ;
V_92 = F_91 ( V_2 , & V_34 , V_225 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_226 = V_230 | V_231 | V_232 |
V_233 | V_234 | V_235 |
V_236 | V_190 | V_237 |
V_238 | V_239 ;
switch( V_2 -> V_41 ) {
case V_42 :
case V_103 :
case V_97 :
if ( V_201 == 0 )
V_226 |= V_228 ;
if ( V_201 <= V_227 )
V_226 |= V_125 ;
break;
case V_215 :
if ( V_227 < 3 )
return F_25 ( V_2 , 0 ) ;
V_226 |= V_125 ;
break;
default:
V_226 |= ( V_228 | V_125 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_189 & ~ V_226 ) | ( V_34 & V_226 ) ;
return V_92 ;
}
static int F_94 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_144 ;
V_2 -> V_25 . V_79 . V_9 = & V_2 -> V_189 ;
V_2 -> V_25 . V_27 = V_2 -> V_94 ;
return F_93 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_94 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned V_240 = V_2 -> V_22 . V_34 ;
unsigned V_241 = V_2 -> V_242 . V_34 & 31 ;
T_1 V_243 ;
if ( V_241 )
return V_220 ;
V_243 = F_1 ( V_2 , V_148 ) ;
V_92 = F_89 ( V_2 , & V_243 , F_12 ( V_2 ) ) ;
if ( V_92 != V_91 )
return V_92 ;
F_8 ( F_3 ( V_2 , V_148 ) , F_1 ( V_2 , V_48 ) ,
F_11 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_48 ) ,
F_1 ( V_2 , V_48 ) - V_240 ,
F_11 ( V_2 ) ) ;
return V_91 ;
}
static int F_96 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_48 ) , F_1 ( V_2 , V_148 ) ,
F_11 ( V_2 ) ) ;
return F_91 ( V_2 , F_3 ( V_2 , V_148 ) , V_2 -> V_94 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_242 . V_34 ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_52 ) ;
if ( V_2 -> V_94 == 4 ) {
F_18 ( V_2 , - 2 ) ;
V_2 -> V_94 = 2 ;
}
return F_90 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_242 . V_34 ;
unsigned long V_70 ;
int V_92 ;
V_92 = F_91 ( V_2 , & V_70 , 2 ) ;
if ( V_92 != V_91 )
return V_92 ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_244 = V_245 ;
if ( V_2 -> V_94 > 2 )
F_18 ( V_2 , V_2 -> V_94 - 2 ) ;
V_92 = F_86 ( V_2 , ( V_36 ) V_70 , V_52 ) ;
return V_92 ;
}
static int F_99 ( struct V_1 * V_2 )
{
unsigned long V_246 = F_1 ( V_2 , V_48 ) ;
int V_92 = V_91 ;
int V_9 = V_247 ;
while ( V_9 <= V_164 ) {
( V_9 == V_48 ) ?
( V_2 -> V_22 . V_34 = V_246 ) : ( V_2 -> V_22 . V_34 = F_1 ( V_2 , V_9 ) ) ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
++ V_9 ;
}
return V_92 ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_189 & ~ V_248 ;
return F_90 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
int V_9 = V_164 ;
V_37 V_34 ;
while ( V_9 >= V_247 ) {
if ( V_9 == V_48 ) {
F_18 ( V_2 , V_2 -> V_94 ) ;
-- V_9 ;
}
V_92 = F_91 ( V_2 , & V_34 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
break;
F_9 ( F_3 ( V_2 , V_9 ) , V_34 , V_2 -> V_94 ) ;
-- V_9 ;
}
return V_92 ;
}
static int F_102 ( struct V_1 * V_2 , int V_249 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
int V_92 ;
struct V_193 V_194 ;
T_5 V_250 ;
T_5 V_251 ;
V_36 V_252 , V_31 ;
V_2 -> V_22 . V_34 = V_2 -> V_189 ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_189 &= ~ ( V_125 | V_236 | V_238 ) ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_93 ) ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_22 . V_34 = V_2 -> V_95 ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_6 -> V_195 ( V_2 , & V_194 ) ;
V_251 = V_194 . V_117 + ( V_249 << 2 ) ;
V_250 = V_194 . V_117 + ( V_249 << 2 ) + 2 ;
V_92 = V_6 -> V_106 ( V_2 , V_250 , & V_252 , 2 , & V_2 -> V_57 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = V_6 -> V_106 ( V_2 , V_251 , & V_31 , 2 , & V_2 -> V_57 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_86 ( V_2 , V_252 , V_93 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_95 = V_31 ;
return V_92 ;
}
int F_103 ( struct V_1 * V_2 , int V_249 )
{
int V_92 ;
F_6 ( V_2 ) ;
V_92 = F_102 ( V_2 , V_249 ) ;
if ( V_92 == V_91 )
F_4 ( V_2 ) ;
return V_92 ;
}
static int F_104 ( struct V_1 * V_2 , int V_249 )
{
switch( V_2 -> V_41 ) {
case V_90 :
return F_102 ( V_2 , V_249 ) ;
case V_215 :
case V_97 :
case V_103 :
case V_42 :
default:
return V_220 ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
unsigned long V_253 = 0 ;
unsigned long V_254 = 0 ;
unsigned long V_252 = 0 ;
unsigned long V_33 = V_230 | V_231 | V_232 |
V_233 | V_234 | V_236 |
V_125 | V_190 | V_235 |
V_228 | V_237 | V_255 |
V_238 | V_239 |
V_256 ;
unsigned long V_257 = V_248 | V_258 |
V_259 ;
V_92 = F_91 ( V_2 , & V_253 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
if ( V_253 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_92 = F_91 ( V_2 , & V_252 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_91 ( V_2 , & V_254 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_86 ( V_2 , ( V_36 ) V_252 , V_93 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_95 = V_253 ;
if ( V_2 -> V_94 == 4 )
V_2 -> V_189 = ( ( V_254 & V_33 ) | ( V_2 -> V_189 & V_257 ) ) ;
else if ( V_2 -> V_94 == 2 ) {
V_2 -> V_189 &= ~ 0xffff ;
V_2 -> V_189 |= V_254 ;
}
V_2 -> V_189 &= ~ V_260 ;
V_2 -> V_189 |= V_256 ;
V_2 -> V_6 -> V_261 ( V_2 , false ) ;
return V_92 ;
}
static int F_106 ( struct V_1 * V_2 )
{
switch( V_2 -> V_41 ) {
case V_90 :
return F_105 ( V_2 ) ;
case V_215 :
case V_97 :
case V_103 :
case V_42 :
default:
return V_220 ;
}
}
static int F_107 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned short V_38 ;
struct V_39 V_262 ;
V_35 V_201 = V_2 -> V_6 -> V_201 ( V_2 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_94 , 2 ) ;
V_92 = F_83 ( V_2 , V_38 , V_93 , V_201 ,
V_219 ,
& V_262 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_262 ) ;
if ( V_92 != V_91 )
return V_220 ;
return V_92 ;
}
static int F_108 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_92 ;
long int V_264 ;
V_264 = V_2 -> V_95 ;
V_92 = F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_22 . V_34 = V_264 ;
V_92 = F_90 ( V_2 ) ;
return V_92 ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_2 V_265 = V_2 -> V_25 . V_266 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_220 ;
if ( ( ( V_37 ) ( V_265 >> 0 ) != ( V_37 ) F_1 ( V_2 , V_247 ) ) ||
( ( V_37 ) ( V_265 >> 32 ) != ( V_37 ) F_1 ( V_2 , V_267 ) ) ) {
* F_2 ( V_2 , V_247 ) = ( V_37 ) ( V_265 >> 0 ) ;
* F_2 ( V_2 , V_267 ) = ( V_37 ) ( V_265 >> 32 ) ;
V_2 -> V_189 &= ~ V_233 ;
} else {
V_2 -> V_25 . V_23 = ( ( T_2 ) F_1 ( V_2 , V_188 ) << 32 ) |
( V_37 ) F_1 ( V_2 , V_159 ) ;
V_2 -> V_189 |= V_233 ;
}
return V_91 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned long V_31 ;
V_92 = F_91 ( V_2 , & V_31 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
return F_40 ( V_2 , V_31 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned long V_31 , V_252 ;
int V_201 = V_2 -> V_6 -> V_201 ( V_2 ) ;
struct V_39 V_262 ;
V_92 = F_91 ( V_2 , & V_31 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_91 ( V_2 , & V_252 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
if ( V_2 -> V_41 >= V_97 && ( V_252 & 3 ) > V_201 )
return V_220 ;
V_92 = F_83 ( V_2 , ( V_36 ) V_252 , V_93 , V_201 ,
V_268 ,
& V_262 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_41 ( V_2 , V_31 , & V_262 ) ;
if ( V_92 != V_91 )
return V_220 ;
return V_92 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_92 ;
V_92 = F_112 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_91 ;
}
static int F_114 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_146 = V_2 -> V_25 . V_34 ;
V_2 -> V_25 . V_34 = F_1 ( V_2 , V_247 ) ;
V_2 -> V_22 . V_146 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_146 ;
F_52 ( V_2 , V_269 ) ;
if ( V_2 -> V_189 & V_233 ) {
V_2 -> V_22 . type = V_118 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_146 ;
} else {
V_2 -> V_22 . type = V_144 ;
V_2 -> V_22 . V_79 . V_9 = F_3 ( V_2 , V_247 ) ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_146 ;
V_2 -> V_25 . V_34 = V_2 -> V_25 . V_146 ;
}
return V_91 ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_242 . V_34 ;
unsigned short V_38 ;
int V_92 ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_94 , 2 ) ;
V_92 = F_86 ( V_2 , V_38 , V_52 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
return V_92 ;
}
static int F_116 ( struct V_1 * V_2 )
{
V_37 V_270 , V_271 , V_272 , V_273 ;
V_270 = 0x80000001 ;
V_272 = 0 ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
return V_273 & F_117 ( V_275 ) ;
}
static void F_118 ( struct V_39 * V_49 , V_37 V_122 )
{
V_49 -> V_51 = ( V_122 >> 23 ) & 1 ;
V_49 -> V_45 = ( V_122 >> 22 ) & 1 ;
V_49 -> V_98 = ( V_122 >> 21 ) & 1 ;
V_49 -> V_276 = ( V_122 >> 20 ) & 1 ;
V_49 -> V_114 = ( V_122 >> 15 ) & 1 ;
V_49 -> V_206 = ( V_122 >> 13 ) & 3 ;
V_49 -> V_216 = ( V_122 >> 12 ) & 1 ;
V_49 -> type = ( V_122 >> 8 ) & 15 ;
}
static int F_119 ( struct V_1 * V_2 , T_2 V_277 , int V_186 )
{
struct V_39 V_49 ;
int V_278 ;
V_36 V_70 ;
V_70 = F_120 ( V_37 , V_277 , 0x7fa8 + V_186 * 4 ) ;
if ( V_186 < 3 )
V_278 = 0x7f84 + V_186 * 12 ;
else
V_278 = 0x7f2c + ( V_186 - 3 ) * 12 ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , V_278 + 8 ) ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , V_278 + 4 ) ) ;
F_118 ( & V_49 , F_120 ( V_37 , V_277 , V_278 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_186 ) ;
return V_91 ;
}
static int F_121 ( struct V_1 * V_2 , T_2 V_277 , int V_186 )
{
struct V_39 V_49 ;
int V_278 ;
V_36 V_70 ;
V_37 V_72 ;
V_278 = 0x7e00 + V_186 * 16 ;
V_70 = F_120 ( V_36 , V_277 , V_278 ) ;
F_118 ( & V_49 , F_120 ( V_36 , V_277 , V_278 + 2 ) << 8 ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , V_278 + 4 ) ) ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , V_278 + 8 ) ) ;
V_72 = F_120 ( V_37 , V_277 , V_278 + 12 ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_186 ) ;
return V_91 ;
}
static int F_122 ( struct V_1 * V_2 ,
T_2 V_279 , T_2 V_280 )
{
int V_89 ;
V_89 = V_2 -> V_6 -> V_281 ( V_2 , 4 , V_280 & ~ V_282 ) ;
if ( V_89 )
return V_220 ;
V_89 = V_2 -> V_6 -> V_281 ( V_2 , 0 , V_279 ) ;
if ( V_89 )
return V_220 ;
if ( V_280 & V_282 ) {
V_89 = V_2 -> V_6 -> V_281 ( V_2 , 4 , V_280 ) ;
if ( V_89 )
return V_220 ;
}
return V_91 ;
}
static int F_123 ( struct V_1 * V_2 , T_2 V_277 )
{
struct V_39 V_49 ;
struct V_193 V_194 ;
V_36 V_70 ;
V_37 V_34 , V_279 , V_280 ;
int V_283 ;
V_279 = F_120 ( V_37 , V_277 , 0x7ffc ) ;
V_2 -> V_6 -> V_281 ( V_2 , 3 , F_120 ( V_37 , V_277 , 0x7ff8 ) ) ;
V_2 -> V_189 = F_120 ( V_37 , V_277 , 0x7ff4 ) | V_256 ;
V_2 -> V_95 = F_120 ( V_37 , V_277 , 0x7ff0 ) ;
for ( V_283 = 0 ; V_283 < 8 ; V_283 ++ )
* F_2 ( V_2 , V_283 ) = F_120 ( V_37 , V_277 , 0x7fd0 + V_283 * 4 ) ;
V_34 = F_120 ( V_37 , V_277 , 0x7fcc ) ;
V_2 -> V_6 -> V_284 ( V_2 , 6 , ( V_34 & V_285 ) | V_286 ) ;
V_34 = F_120 ( V_37 , V_277 , 0x7fc8 ) ;
V_2 -> V_6 -> V_284 ( V_2 , 7 , ( V_34 & V_287 ) | V_288 ) ;
V_70 = F_120 ( V_37 , V_277 , 0x7fc4 ) ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f64 ) ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f60 ) ) ;
F_118 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f5c ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_217 ) ;
V_70 = F_120 ( V_37 , V_277 , 0x7fc0 ) ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f80 ) ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f7c ) ) ;
F_118 ( & V_49 , F_120 ( V_37 , V_277 , 0x7f78 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_197 ) ;
V_194 . V_117 = F_120 ( V_37 , V_277 , 0x7f74 ) ;
V_194 . V_74 = F_120 ( V_37 , V_277 , 0x7f70 ) ;
V_2 -> V_6 -> V_289 ( V_2 , & V_194 ) ;
V_194 . V_117 = F_120 ( V_37 , V_277 , 0x7f58 ) ;
V_194 . V_74 = F_120 ( V_37 , V_277 , 0x7f54 ) ;
V_2 -> V_6 -> V_290 ( V_2 , & V_194 ) ;
for ( V_283 = 0 ; V_283 < 6 ; V_283 ++ ) {
int V_291 = F_119 ( V_2 , V_277 , V_283 ) ;
if ( V_291 != V_91 )
return V_291 ;
}
V_280 = F_120 ( V_37 , V_277 , 0x7f14 ) ;
V_2 -> V_6 -> V_292 ( V_2 , F_120 ( V_37 , V_277 , 0x7ef8 ) ) ;
return F_122 ( V_2 , V_279 , V_280 ) ;
}
static int F_124 ( struct V_1 * V_2 , T_2 V_277 )
{
struct V_39 V_49 ;
struct V_193 V_194 ;
T_2 V_34 , V_279 , V_280 ;
V_37 V_72 ;
V_36 V_70 ;
int V_283 , V_291 ;
for ( V_283 = 0 ; V_283 < 16 ; V_283 ++ )
* F_2 ( V_2 , V_283 ) = F_120 ( T_2 , V_277 , 0x7ff8 - V_283 * 8 ) ;
V_2 -> V_95 = F_120 ( T_2 , V_277 , 0x7f78 ) ;
V_2 -> V_189 = F_120 ( V_37 , V_277 , 0x7f70 ) | V_256 ;
V_34 = F_120 ( V_37 , V_277 , 0x7f68 ) ;
V_2 -> V_6 -> V_284 ( V_2 , 6 , ( V_34 & V_285 ) | V_286 ) ;
V_34 = F_120 ( V_37 , V_277 , 0x7f60 ) ;
V_2 -> V_6 -> V_284 ( V_2 , 7 , ( V_34 & V_287 ) | V_288 ) ;
V_279 = F_120 ( T_2 , V_277 , 0x7f58 ) ;
V_2 -> V_6 -> V_281 ( V_2 , 3 , F_120 ( T_2 , V_277 , 0x7f50 ) ) ;
V_280 = F_120 ( T_2 , V_277 , 0x7f48 ) ;
V_2 -> V_6 -> V_292 ( V_2 , F_120 ( V_37 , V_277 , 0x7f00 ) ) ;
V_34 = F_120 ( T_2 , V_277 , 0x7ed0 ) ;
V_2 -> V_6 -> V_293 ( V_2 , V_101 , V_34 & ~ V_102 ) ;
V_70 = F_120 ( V_37 , V_277 , 0x7e90 ) ;
F_118 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e92 ) << 8 ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e94 ) ) ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e98 ) ) ;
V_72 = F_120 ( V_37 , V_277 , 0x7e9c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_217 ) ;
V_194 . V_74 = F_120 ( V_37 , V_277 , 0x7e84 ) ;
V_194 . V_117 = F_120 ( T_2 , V_277 , 0x7e88 ) ;
V_2 -> V_6 -> V_290 ( V_2 , & V_194 ) ;
V_70 = F_120 ( V_37 , V_277 , 0x7e70 ) ;
F_118 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e72 ) << 8 ) ;
F_85 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e74 ) ) ;
F_84 ( & V_49 , F_120 ( V_37 , V_277 , 0x7e78 ) ) ;
V_72 = F_120 ( V_37 , V_277 , 0x7e7c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_197 ) ;
V_194 . V_74 = F_120 ( V_37 , V_277 , 0x7e64 ) ;
V_194 . V_117 = F_120 ( T_2 , V_277 , 0x7e68 ) ;
V_2 -> V_6 -> V_289 ( V_2 , & V_194 ) ;
V_291 = F_122 ( V_2 , V_279 , V_280 ) ;
if ( V_291 != V_91 )
return V_291 ;
for ( V_283 = 0 ; V_283 < 6 ; V_283 ++ ) {
V_291 = F_121 ( V_2 , V_277 , V_283 ) ;
if ( V_291 != V_91 )
return V_291 ;
}
return V_91 ;
}
static int F_125 ( struct V_1 * V_2 )
{
unsigned long V_279 , V_280 , V_99 ;
T_2 V_277 ;
int V_212 ;
if ( ( V_2 -> V_294 & V_295 ) == 0 )
return F_27 ( V_2 ) ;
V_280 = V_2 -> V_6 -> V_130 ( V_2 , 4 ) ;
if ( F_116 ( V_2 ) ) {
struct V_39 V_96 ;
if ( V_280 & V_282 ) {
V_2 -> V_6 -> V_281 ( V_2 , 4 , V_280 & ~ V_282 ) ;
V_280 &= ~ V_282 ;
}
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . type = 0xb ;
V_96 . V_216 = V_96 . V_51 = V_96 . V_114 = 1 ;
V_2 -> V_6 -> V_73 ( V_2 , 0 , & V_96 , 0 , V_93 ) ;
}
V_279 = V_2 -> V_6 -> V_130 ( V_2 , 0 ) ;
if ( V_279 & V_296 )
V_2 -> V_6 -> V_281 ( V_2 , 0 , V_279 & ~ ( V_297 | V_296 ) ) ;
if ( V_280 & V_298 )
V_2 -> V_6 -> V_281 ( V_2 , 4 , V_280 & ~ V_298 ) ;
V_99 = 0 ;
V_2 -> V_6 -> V_293 ( V_2 , V_101 , V_99 ) ;
V_277 = V_2 -> V_6 -> V_299 ( V_2 ) ;
if ( F_116 ( V_2 ) )
V_212 = F_124 ( V_2 , V_277 + 0x8000 ) ;
else
V_212 = F_123 ( V_2 , V_277 + 0x8000 ) ;
if ( V_212 != V_91 ) {
return V_220 ;
}
if ( ( V_2 -> V_294 & V_300 ) == 0 )
V_2 -> V_6 -> V_261 ( V_2 , false ) ;
V_2 -> V_294 &= ~ V_300 ;
V_2 -> V_294 &= ~ V_295 ;
return V_91 ;
}
static void
F_126 ( struct V_1 * V_2 ,
struct V_39 * V_252 , struct V_39 * V_40 )
{
V_252 -> V_98 = 0 ;
F_84 ( V_252 , 0 ) ;
V_252 -> V_51 = 1 ;
F_85 ( V_252 , 0xfffff ) ;
V_252 -> type = 0x0b ;
V_252 -> V_216 = 1 ;
V_252 -> V_206 = 0 ;
V_252 -> V_114 = 1 ;
V_252 -> V_45 = 1 ;
V_252 -> V_276 = 0 ;
F_84 ( V_40 , 0 ) ;
F_85 ( V_40 , 0xfffff ) ;
V_40 -> V_51 = 1 ;
V_40 -> V_216 = 1 ;
V_40 -> type = 0x03 ;
V_40 -> V_45 = 1 ;
V_40 -> V_206 = 0 ;
V_40 -> V_114 = 1 ;
V_40 -> V_98 = 0 ;
V_40 -> V_276 = 0 ;
}
static bool F_127 ( struct V_1 * V_2 )
{
V_37 V_270 , V_271 , V_272 , V_273 ;
V_270 = V_272 = 0 ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
return V_271 == V_301
&& V_272 == V_302
&& V_273 == V_303 ;
}
static bool F_128 ( struct V_1 * V_2 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
V_37 V_270 , V_271 , V_272 , V_273 ;
if ( V_2 -> V_41 == V_42 )
return true ;
V_270 = 0x00000000 ;
V_272 = 0x00000000 ;
V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
if ( V_271 == V_301 &&
V_272 == V_302 &&
V_273 == V_303 )
return false ;
if ( V_271 == V_304 &&
V_272 == V_305 &&
V_273 == V_306 )
return true ;
if ( V_271 == V_307 &&
V_272 == V_308 &&
V_273 == V_309 )
return true ;
return false ;
}
static int F_129 ( struct V_1 * V_2 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_39 V_252 , V_40 ;
T_2 V_310 ;
V_36 V_311 , V_312 ;
T_2 V_99 = 0 ;
if ( V_2 -> V_41 == V_90 ||
V_2 -> V_41 == V_215 )
return F_27 ( V_2 ) ;
if ( ! ( F_128 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
F_126 ( V_2 , & V_252 , & V_40 ) ;
if ( ! ( V_99 & V_313 ) )
return F_27 ( V_2 ) ;
V_6 -> V_100 ( V_2 , V_314 , & V_310 ) ;
V_310 >>= 32 ;
V_311 = ( V_36 ) ( V_310 & 0xfffc ) ;
V_312 = ( V_36 ) ( V_310 + 8 ) ;
if ( V_99 & V_102 ) {
V_252 . V_45 = 0 ;
V_252 . V_98 = 1 ;
}
V_6 -> V_73 ( V_2 , V_311 , & V_252 , 0 , V_93 ) ;
V_6 -> V_73 ( V_2 , V_312 , & V_40 , 0 , V_44 ) ;
* F_2 ( V_2 , V_188 ) = V_2 -> V_95 ;
if ( V_99 & V_102 ) {
#ifdef F_42
* F_2 ( V_2 , V_315 ) = V_2 -> V_189 ;
V_6 -> V_100 ( V_2 ,
V_2 -> V_41 == V_42 ?
V_316 : V_317 , & V_310 ) ;
V_2 -> V_95 = V_310 ;
V_6 -> V_100 ( V_2 , V_318 , & V_310 ) ;
V_2 -> V_189 &= ~ V_310 ;
V_2 -> V_189 |= V_256 ;
#endif
} else {
V_6 -> V_100 ( V_2 , V_314 , & V_310 ) ;
V_2 -> V_95 = ( V_37 ) V_310 ;
V_2 -> V_189 &= ~ ( V_248 | V_125 ) ;
}
return V_91 ;
}
static int F_130 ( struct V_1 * V_2 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_39 V_252 , V_40 ;
T_2 V_310 ;
V_36 V_311 , V_312 ;
T_2 V_99 = 0 ;
V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( V_2 -> V_41 == V_90 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_41 != V_42 ) && ( V_99 & V_102 )
&& ! F_127 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 )
return V_220 ;
F_126 ( V_2 , & V_252 , & V_40 ) ;
V_6 -> V_100 ( V_2 , V_319 , & V_310 ) ;
if ( ( V_310 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_189 &= ~ ( V_248 | V_125 ) ;
V_311 = ( V_36 ) V_310 & ~ V_320 ;
V_312 = V_311 + 8 ;
if ( V_99 & V_102 ) {
V_252 . V_45 = 0 ;
V_252 . V_98 = 1 ;
}
V_6 -> V_73 ( V_2 , V_311 , & V_252 , 0 , V_93 ) ;
V_6 -> V_73 ( V_2 , V_312 , & V_40 , 0 , V_44 ) ;
V_6 -> V_100 ( V_2 , V_321 , & V_310 ) ;
V_2 -> V_95 = ( V_99 & V_102 ) ? V_310 : ( V_37 ) V_310 ;
V_6 -> V_100 ( V_2 , V_322 , & V_310 ) ;
* F_2 ( V_2 , V_48 ) = ( V_99 & V_102 ) ? V_310 :
( V_37 ) V_310 ;
return V_91 ;
}
static int F_131 ( struct V_1 * V_2 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_39 V_252 , V_40 ;
T_2 V_310 , V_323 , V_324 ;
int V_325 ;
V_36 V_311 = 0 , V_312 = 0 ;
if ( V_2 -> V_41 == V_90 ||
V_2 -> V_41 == V_215 )
return F_25 ( V_2 , 0 ) ;
F_126 ( V_2 , & V_252 , & V_40 ) ;
if ( ( V_2 -> V_116 & 0x8 ) != 0x0 )
V_325 = V_42 ;
else
V_325 = V_103 ;
V_323 = F_1 ( V_2 , V_188 ) ;
V_324 = F_1 ( V_2 , V_267 ) ;
V_252 . V_206 = 3 ;
V_40 . V_206 = 3 ;
V_6 -> V_100 ( V_2 , V_319 , & V_310 ) ;
switch ( V_325 ) {
case V_103 :
V_311 = ( V_36 ) ( V_310 + 16 ) ;
if ( ( V_310 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_312 = ( V_36 ) ( V_310 + 24 ) ;
V_323 = ( V_37 ) V_323 ;
V_324 = ( V_37 ) V_324 ;
break;
case V_42 :
V_311 = ( V_36 ) ( V_310 + 32 ) ;
if ( V_310 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_312 = V_311 + 8 ;
V_252 . V_45 = 0 ;
V_252 . V_98 = 1 ;
if ( F_36 ( V_323 ) ||
F_36 ( V_324 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
V_311 |= V_320 ;
V_312 |= V_320 ;
V_6 -> V_73 ( V_2 , V_311 , & V_252 , 0 , V_93 ) ;
V_6 -> V_73 ( V_2 , V_312 , & V_40 , 0 , V_44 ) ;
V_2 -> V_95 = V_324 ;
* F_2 ( V_2 , V_48 ) = V_323 ;
return V_91 ;
}
static bool F_132 ( struct V_1 * V_2 )
{
int V_227 ;
if ( V_2 -> V_41 == V_90 )
return false ;
if ( V_2 -> V_41 == V_215 )
return true ;
V_227 = ( V_2 -> V_189 & V_228 ) >> V_229 ;
return V_2 -> V_6 -> V_201 ( V_2 ) > V_227 ;
}
static bool F_133 ( struct V_1 * V_2 ,
V_36 V_183 , V_36 V_225 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_39 V_326 ;
V_37 V_72 ;
int V_291 ;
V_36 V_327 , V_328 , V_329 , V_330 = V_183 & 0x7 ;
unsigned V_33 = ( 1 << V_225 ) - 1 ;
unsigned long V_331 ;
V_6 -> V_43 ( V_2 , & V_327 , & V_326 , & V_72 , V_217 ) ;
if ( ! V_326 . V_114 )
return false ;
if ( F_19 ( & V_326 ) < 103 )
return false ;
V_331 = F_79 ( & V_326 ) ;
#ifdef F_42
V_331 |= ( ( T_2 ) V_72 ) << 32 ;
#endif
V_291 = V_6 -> V_106 ( V_2 , V_331 + 102 , & V_328 , 2 , NULL ) ;
if ( V_291 != V_91 )
return false ;
if ( V_328 + V_183 / 8 > F_19 ( & V_326 ) )
return false ;
V_291 = V_6 -> V_106 ( V_2 , V_331 + V_328 + V_183 / 8 , & V_329 , 2 , NULL ) ;
if ( V_291 != V_91 )
return false ;
if ( ( V_329 >> V_330 ) & V_33 )
return false ;
return true ;
}
static bool F_134 ( struct V_1 * V_2 ,
V_36 V_183 , V_36 V_225 )
{
if ( V_2 -> V_332 )
return true ;
if ( F_132 ( V_2 ) )
if ( ! F_133 ( V_2 , V_183 , V_225 ) )
return false ;
V_2 -> V_332 = true ;
return true ;
}
static void F_135 ( struct V_1 * V_2 )
{
#ifdef F_42
if ( V_2 -> V_29 != 4 || ! F_127 ( V_2 ) )
return;
* F_2 ( V_2 , V_188 ) = 0 ;
switch ( V_2 -> V_136 ) {
case 0xa4 :
case 0xa5 :
* F_3 ( V_2 , V_162 ) &= ( V_37 ) - 1 ;
case 0xaa :
case 0xab :
* F_3 ( V_2 , V_164 ) &= ( V_37 ) - 1 ;
}
#endif
}
static void F_136 ( struct V_1 * V_2 ,
struct V_333 * V_334 )
{
V_334 -> V_335 = V_2 -> V_95 ;
V_334 -> V_336 = V_2 -> V_189 ;
V_334 -> V_337 = F_1 ( V_2 , V_247 ) ;
V_334 -> V_338 = F_1 ( V_2 , V_188 ) ;
V_334 -> V_339 = F_1 ( V_2 , V_267 ) ;
V_334 -> V_158 = F_1 ( V_2 , V_159 ) ;
V_334 -> V_340 = F_1 ( V_2 , V_48 ) ;
V_334 -> V_160 = F_1 ( V_2 , V_148 ) ;
V_334 -> V_161 = F_1 ( V_2 , V_162 ) ;
V_334 -> V_163 = F_1 ( V_2 , V_164 ) ;
V_334 -> V_341 = F_31 ( V_2 , V_342 ) ;
V_334 -> V_252 = F_31 ( V_2 , V_93 ) ;
V_334 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_334 -> V_343 = F_31 ( V_2 , V_155 ) ;
V_334 -> V_344 = F_31 ( V_2 , V_197 ) ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_333 * V_334 )
{
int V_212 ;
V_35 V_201 ;
V_2 -> V_95 = V_334 -> V_335 ;
V_2 -> V_189 = V_334 -> V_336 | 2 ;
* F_2 ( V_2 , V_247 ) = V_334 -> V_337 ;
* F_2 ( V_2 , V_188 ) = V_334 -> V_338 ;
* F_2 ( V_2 , V_267 ) = V_334 -> V_339 ;
* F_2 ( V_2 , V_159 ) = V_334 -> V_158 ;
* F_2 ( V_2 , V_48 ) = V_334 -> V_340 ;
* F_2 ( V_2 , V_148 ) = V_334 -> V_160 ;
* F_2 ( V_2 , V_162 ) = V_334 -> V_161 ;
* F_2 ( V_2 , V_164 ) = V_334 -> V_163 ;
F_32 ( V_2 , V_334 -> V_344 , V_197 ) ;
F_32 ( V_2 , V_334 -> V_341 , V_342 ) ;
F_32 ( V_2 , V_334 -> V_252 , V_93 ) ;
F_32 ( V_2 , V_334 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_334 -> V_343 , V_155 ) ;
V_201 = V_334 -> V_252 & 3 ;
V_212 = F_83 ( V_2 , V_334 -> V_344 , V_197 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_341 , V_342 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_252 , V_93 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_40 , V_44 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_343 , V_155 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
return V_91 ;
}
static int F_138 ( struct V_1 * V_2 ,
V_36 V_345 , V_36 V_346 ,
T_1 V_347 , struct V_39 * V_262 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_333 V_348 ;
int V_212 ;
V_37 V_349 = F_79 ( V_262 ) ;
V_212 = V_6 -> V_106 ( V_2 , V_347 , & V_348 , sizeof V_348 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
F_136 ( V_2 , & V_348 ) ;
V_212 = V_6 -> V_200 ( V_2 , V_347 , & V_348 , sizeof V_348 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = V_6 -> V_106 ( V_2 , V_349 , & V_348 , sizeof V_348 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
if ( V_346 != 0xffff ) {
V_348 . V_350 = V_346 ;
V_212 = V_6 -> V_200 ( V_2 , V_349 ,
& V_348 . V_350 ,
sizeof V_348 . V_350 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
}
return F_137 ( V_2 , & V_348 ) ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_351 * V_334 )
{
V_334 -> V_31 = V_2 -> V_95 ;
V_334 -> V_189 = V_2 -> V_189 ;
V_334 -> V_270 = F_1 ( V_2 , V_247 ) ;
V_334 -> V_272 = F_1 ( V_2 , V_188 ) ;
V_334 -> V_273 = F_1 ( V_2 , V_267 ) ;
V_334 -> V_271 = F_1 ( V_2 , V_159 ) ;
V_334 -> V_352 = F_1 ( V_2 , V_48 ) ;
V_334 -> V_353 = F_1 ( V_2 , V_148 ) ;
V_334 -> V_354 = F_1 ( V_2 , V_162 ) ;
V_334 -> V_355 = F_1 ( V_2 , V_164 ) ;
V_334 -> V_341 = F_31 ( V_2 , V_342 ) ;
V_334 -> V_252 = F_31 ( V_2 , V_93 ) ;
V_334 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_334 -> V_343 = F_31 ( V_2 , V_155 ) ;
V_334 -> V_356 = F_31 ( V_2 , V_53 ) ;
V_334 -> V_357 = F_31 ( V_2 , V_214 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_351 * V_334 )
{
int V_212 ;
V_35 V_201 ;
if ( V_2 -> V_6 -> V_281 ( V_2 , 3 , V_334 -> V_358 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_95 = V_334 -> V_31 ;
V_2 -> V_189 = V_334 -> V_189 | 2 ;
* F_2 ( V_2 , V_247 ) = V_334 -> V_270 ;
* F_2 ( V_2 , V_188 ) = V_334 -> V_272 ;
* F_2 ( V_2 , V_267 ) = V_334 -> V_273 ;
* F_2 ( V_2 , V_159 ) = V_334 -> V_271 ;
* F_2 ( V_2 , V_48 ) = V_334 -> V_352 ;
* F_2 ( V_2 , V_148 ) = V_334 -> V_353 ;
* F_2 ( V_2 , V_162 ) = V_334 -> V_354 ;
* F_2 ( V_2 , V_164 ) = V_334 -> V_355 ;
F_32 ( V_2 , V_334 -> V_359 , V_197 ) ;
F_32 ( V_2 , V_334 -> V_341 , V_342 ) ;
F_32 ( V_2 , V_334 -> V_252 , V_93 ) ;
F_32 ( V_2 , V_334 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_334 -> V_343 , V_155 ) ;
F_32 ( V_2 , V_334 -> V_356 , V_53 ) ;
F_32 ( V_2 , V_334 -> V_357 , V_214 ) ;
if ( V_2 -> V_189 & V_248 ) {
V_2 -> V_41 = V_215 ;
V_201 = 3 ;
} else {
V_2 -> V_41 = V_103 ;
V_201 = V_334 -> V_252 & 3 ;
}
V_212 = F_83 ( V_2 , V_334 -> V_359 , V_197 ,
V_201 , V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_341 , V_342 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_252 , V_93 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_40 , V_44 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_343 , V_155 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_356 , V_53 , V_201 ,
V_218 , NULL ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_83 ( V_2 , V_334 -> V_357 , V_214 , V_201 ,
V_218 , NULL ) ;
return V_212 ;
}
static int F_141 ( struct V_1 * V_2 ,
V_36 V_345 , V_36 V_346 ,
T_1 V_347 , struct V_39 * V_262 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_351 V_348 ;
int V_212 ;
V_37 V_349 = F_79 ( V_262 ) ;
V_37 V_360 = F_142 ( struct V_351 , V_31 ) ;
V_37 V_361 = F_142 ( struct V_351 , V_359 ) ;
V_212 = V_6 -> V_106 ( V_2 , V_347 , & V_348 , sizeof V_348 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
F_139 ( V_2 , & V_348 ) ;
V_212 = V_6 -> V_200 ( V_2 , V_347 + V_360 , & V_348 . V_31 ,
V_361 - V_360 , & V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = V_6 -> V_106 ( V_2 , V_349 , & V_348 , sizeof V_348 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
if ( V_346 != 0xffff ) {
V_348 . V_350 = V_346 ;
V_212 = V_6 -> V_200 ( V_2 , V_349 ,
& V_348 . V_350 ,
sizeof V_348 . V_350 ,
& V_2 -> V_57 ) ;
if ( V_212 != V_91 )
return V_212 ;
}
return F_140 ( V_2 , & V_348 ) ;
}
static int F_143 ( struct V_1 * V_2 ,
V_36 V_345 , int V_362 , int V_363 ,
bool V_364 , V_37 V_59 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
struct V_39 V_365 , V_366 ;
int V_212 ;
V_36 V_346 = F_31 ( V_2 , V_217 ) ;
T_1 V_347 =
V_6 -> V_54 ( V_2 , V_217 ) ;
V_37 V_367 ;
T_1 V_211 , V_368 ;
V_212 = F_81 ( V_2 , V_345 , & V_366 , & V_211 ) ;
if ( V_212 != V_91 )
return V_212 ;
V_212 = F_81 ( V_2 , V_346 , & V_365 , & V_211 ) ;
if ( V_212 != V_91 )
return V_212 ;
if ( V_363 == V_369 ) {
if ( V_362 != - 1 ) {
struct V_39 V_370 ;
int V_206 ;
V_212 = F_77 ( V_2 , V_362 ,
& V_370 ) ;
if ( V_212 != V_91 )
return V_212 ;
V_206 = V_370 . V_206 ;
if ( ( V_345 & 3 ) > V_206 || V_6 -> V_201 ( V_2 ) > V_206 )
return F_25 ( V_2 , ( V_362 << 3 ) | 0x2 ) ;
}
}
V_367 = F_19 ( & V_366 ) ;
if ( ! V_366 . V_114 ||
( ( V_367 < 0x67 && ( V_366 . type & 8 ) ) ||
V_367 < 0x2b ) ) {
return F_28 ( V_2 , V_345 & 0xfffc ) ;
}
if ( V_363 == V_371 || V_363 == V_372 ) {
V_365 . type &= ~ ( 1 << 1 ) ;
F_82 ( V_2 , V_346 , & V_365 ) ;
}
if ( V_363 == V_371 )
V_2 -> V_189 = V_2 -> V_189 & ~ V_237 ;
if ( V_363 != V_373 && V_363 != V_369 )
V_346 = 0xffff ;
if ( V_366 . type & 8 )
V_212 = F_141 ( V_2 , V_345 , V_346 ,
V_347 , & V_366 ) ;
else
V_212 = F_138 ( V_2 , V_345 , V_346 ,
V_347 , & V_366 ) ;
if ( V_212 != V_91 )
return V_212 ;
if ( V_363 == V_373 || V_363 == V_369 )
V_2 -> V_189 = V_2 -> V_189 | V_237 ;
if ( V_363 != V_371 ) {
V_366 . type |= ( 1 << 1 ) ;
F_82 ( V_2 , V_345 , & V_366 ) ;
}
V_6 -> V_281 ( V_2 , 0 , V_6 -> V_130 ( V_2 , 0 ) | V_131 ) ;
V_6 -> V_73 ( V_2 , V_345 , & V_366 , 0 , V_217 ) ;
if ( V_364 ) {
V_2 -> V_94 = V_2 -> V_29 = ( V_366 . type & 8 ) ? 4 : 2 ;
V_2 -> V_223 = 0 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_59 ;
V_212 = F_90 ( V_2 ) ;
}
V_6 -> V_374 ( V_2 , 7 , & V_368 ) ;
V_6 -> V_284 ( V_2 , 7 , V_368 & ~ ( V_375 | V_376 ) ) ;
return V_212 ;
}
int F_144 ( struct V_1 * V_2 ,
V_36 V_345 , int V_362 , int V_363 ,
bool V_364 , V_37 V_59 )
{
int V_92 ;
F_6 ( V_2 ) ;
V_2 -> V_95 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_118 ;
V_92 = F_143 ( V_2 , V_345 , V_362 , V_363 ,
V_364 , V_59 ) ;
if ( V_92 == V_91 ) {
V_2 -> V_31 = V_2 -> V_95 ;
F_4 ( V_2 ) ;
}
return ( V_92 == V_220 ) ? V_377 : V_378 ;
}
static void F_145 ( struct V_1 * V_2 , int V_9 ,
struct V_126 * V_127 )
{
int V_379 = ( V_2 -> V_189 & V_190 ) ? - V_127 -> V_187 : V_127 -> V_187 ;
F_17 ( V_2 , V_9 , V_379 * V_127 -> V_27 ) ;
V_127 -> V_79 . V_169 . V_88 = F_15 ( V_2 , V_9 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
V_35 V_380 , V_381 ;
bool V_382 , V_383 , V_384 ;
V_383 = V_2 -> V_189 & V_230 ;
V_380 = V_2 -> V_25 . V_34 ;
V_381 = V_380 ;
V_384 = V_383 ;
V_383 = false ;
V_382 = V_2 -> V_189 & V_232 ;
if ( ( V_380 & 0x0f ) > 9 || V_382 ) {
V_380 -= 6 ;
V_383 = V_384 | ( V_380 >= 250 ) ;
V_382 = true ;
} else {
V_382 = false ;
}
if ( V_381 > 0x99 || V_384 ) {
V_380 -= 0x60 ;
V_383 = true ;
}
V_2 -> V_25 . V_34 = V_380 ;
V_2 -> V_22 . type = V_385 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_386 ) ;
V_2 -> V_189 &= ~ ( V_232 | V_230 ) ;
if ( V_383 )
V_2 -> V_189 |= V_230 ;
if ( V_382 )
V_2 -> V_189 |= V_232 ;
return V_91 ;
}
static int F_147 ( struct V_1 * V_2 )
{
V_35 V_380 , V_387 ;
if ( V_2 -> V_22 . V_34 == 0 )
return F_29 ( V_2 ) ;
V_380 = V_2 -> V_25 . V_34 & 0xff ;
V_387 = V_380 / V_2 -> V_22 . V_34 ;
V_380 %= V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_380 | ( V_387 << 8 ) ;
V_2 -> V_22 . type = V_385 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_386 ) ;
return V_91 ;
}
static int F_148 ( struct V_1 * V_2 )
{
V_35 V_380 = V_2 -> V_25 . V_34 & 0xff ;
V_35 V_387 = ( V_2 -> V_25 . V_34 >> 8 ) & 0xff ;
V_380 = ( V_380 + ( V_387 * V_2 -> V_22 . V_34 ) ) & 0xff ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_380 ;
V_2 -> V_22 . type = V_385 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_386 ) ;
return V_91 ;
}
static int F_149 ( struct V_1 * V_2 )
{
int V_92 ;
long V_104 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_95 ;
V_92 = F_43 ( V_2 , V_104 ) ;
if ( V_92 != V_91 )
return V_92 ;
return F_90 ( V_2 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_36 V_38 , V_388 ;
T_1 V_264 ;
int V_92 ;
struct V_39 V_205 , V_262 ;
const struct V_196 * V_6 = V_2 -> V_6 ;
int V_201 = V_2 -> V_6 -> V_201 ( V_2 ) ;
enum V_83 V_389 = V_2 -> V_41 ;
V_264 = V_2 -> V_95 ;
V_6 -> V_43 ( V_2 , & V_388 , & V_205 , NULL , V_93 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_94 , 2 ) ;
V_92 = F_83 ( V_2 , V_38 , V_93 , V_201 ,
V_219 , & V_262 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_262 ) ;
if ( V_92 != V_91 )
goto V_390;
V_2 -> V_22 . V_34 = V_388 ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 )
goto V_390;
V_2 -> V_22 . V_34 = V_264 ;
V_92 = F_90 ( V_2 ) ;
if ( V_92 != V_91 ) {
F_151 ( L_1 ) ;
goto V_390;
}
return V_92 ;
V_390:
V_6 -> V_73 ( V_2 , V_388 , & V_205 , 0 , V_93 ) ;
V_2 -> V_41 = V_389 ;
return V_92 ;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned long V_31 ;
V_92 = F_91 ( V_2 , & V_31 , V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_92 = F_40 ( V_2 , V_31 ) ;
if ( V_92 != V_91 )
return V_92 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_91 ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_34 ;
F_87 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_146 ;
V_2 -> V_223 = 1 ;
return V_91 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = V_2 -> V_242 . V_34 ;
return F_52 ( V_2 , V_391 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_144 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_79 . V_9 = F_3 ( V_2 , V_267 ) ;
V_2 -> V_25 . V_34 = ~ ( ( V_2 -> V_22 . V_34 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_91 ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_2 V_392 = 0 ;
V_2 -> V_6 -> V_100 ( V_2 , V_393 , & V_392 ) ;
* F_2 ( V_2 , V_247 ) = ( V_37 ) V_392 ;
* F_2 ( V_2 , V_267 ) = V_392 >> 32 ;
return V_91 ;
}
static int F_157 ( struct V_1 * V_2 )
{
T_2 V_394 ;
if ( V_2 -> V_6 -> V_395 ( V_2 , F_1 ( V_2 , V_188 ) , & V_394 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_247 ) = ( V_37 ) V_394 ;
* F_2 ( V_2 , V_267 ) = V_394 >> 32 ;
return V_91 ;
}
static int F_158 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_263 , V_2 -> V_22 . V_263 , sizeof( V_2 -> V_22 . V_263 ) ) ;
return V_91 ;
}
static int F_159 ( struct V_1 * V_2 )
{
V_37 V_271 , V_272 , V_273 , V_270 = 1 ;
V_36 V_396 ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
if ( ! ( V_272 & F_160 ( V_397 ) ) )
return F_27 ( V_2 ) ;
switch ( V_2 -> V_94 ) {
case 2 :
V_396 = ( V_36 ) V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 &= ~ 0xffffUL ;
V_2 -> V_25 . V_34 |= ( unsigned long ) F_161 ( V_396 ) ;
break;
case 4 :
V_2 -> V_25 . V_34 = F_162 ( ( V_37 ) V_2 -> V_22 . V_34 ) ;
break;
case 8 :
V_2 -> V_25 . V_34 = F_163 ( V_2 -> V_22 . V_34 ) ;
break;
default:
F_58 () ;
}
return V_91 ;
}
static int F_164 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_281 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_34 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_165 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
if ( V_2 -> V_41 == V_42 )
V_34 = V_2 -> V_22 . V_34 & ~ 0ULL ;
else
V_34 = V_2 -> V_22 . V_34 & ~ 0U ;
if ( V_2 -> V_6 -> V_284 ( V_2 , V_2 -> V_19 , V_34 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_166 ( struct V_1 * V_2 )
{
T_2 V_310 ;
V_310 = ( V_37 ) F_1 ( V_2 , V_247 )
| ( ( T_2 ) F_1 ( V_2 , V_267 ) << 32 ) ;
if ( V_2 -> V_6 -> V_293 ( V_2 , F_1 ( V_2 , V_188 ) , V_310 ) )
return F_25 ( V_2 , 0 ) ;
return V_91 ;
}
static int F_167 ( struct V_1 * V_2 )
{
T_2 V_310 ;
if ( V_2 -> V_6 -> V_100 ( V_2 , F_1 ( V_2 , V_188 ) , & V_310 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_247 ) = ( V_37 ) V_310 ;
* F_2 ( V_2 , V_267 ) = V_310 >> 32 ;
return V_91 ;
}
static int F_168 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_214 )
return F_27 ( V_2 ) ;
V_2 -> V_25 . V_34 = F_31 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_157 )
V_2 -> V_25 . V_27 = 2 ;
return V_91 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
if ( V_2 -> V_19 == V_93 || V_2 -> V_19 > V_214 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_244 = V_245 ;
V_2 -> V_25 . type = V_118 ;
return F_86 ( V_2 , V_38 , V_2 -> V_19 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_118 ;
return F_86 ( V_2 , V_38 , V_197 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_118 ;
return F_86 ( V_2 , V_38 , V_217 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_92 ;
T_1 V_84 ;
V_92 = F_38 ( V_2 , V_2 -> V_22 . V_79 . V_169 , 1 , false , & V_84 ) ;
if ( V_92 == V_91 )
V_2 -> V_6 -> V_398 ( V_2 , V_84 ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_173 ( struct V_1 * V_2 )
{
T_1 V_279 ;
V_279 = V_2 -> V_6 -> V_130 ( V_2 , 0 ) ;
V_279 &= ~ V_131 ;
V_2 -> V_6 -> V_281 ( V_2 , 0 , V_279 ) ;
return V_91 ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_92 = V_2 -> V_6 -> V_399 ( V_2 ) ;
if ( V_92 != V_91 )
return V_92 ;
V_2 -> V_95 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_175 ( struct V_1 * V_2 ,
void (* F_176)( struct V_1 * V_2 ,
struct V_193 * V_112 ) )
{
struct V_193 V_193 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_94 = 8 ;
F_176 ( V_2 , & V_193 ) ;
if ( V_2 -> V_94 == 2 ) {
V_2 -> V_94 = 4 ;
V_193 . V_117 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_118 ;
return F_73 ( V_2 , V_2 -> V_25 . V_79 . V_169 ,
& V_193 , 2 + V_2 -> V_94 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
return F_175 ( V_2 , V_2 -> V_6 -> V_198 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
return F_175 ( V_2 , V_2 -> V_6 -> V_195 ) ;
}
static int F_179 ( struct V_1 * V_2 , bool V_400 )
{
struct V_193 V_193 ;
int V_92 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_94 = 8 ;
V_92 = F_50 ( V_2 , V_2 -> V_22 . V_79 . V_169 ,
& V_193 . V_74 , & V_193 . V_117 ,
V_2 -> V_94 ) ;
if ( V_92 != V_91 )
return V_92 ;
if ( V_2 -> V_41 == V_42 &&
F_36 ( V_193 . V_117 ) )
return F_25 ( V_2 , 0 ) ;
if ( V_400 )
V_2 -> V_6 -> V_289 ( V_2 , & V_193 ) ;
else
V_2 -> V_6 -> V_290 ( V_2 , & V_193 ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_180 ( struct V_1 * V_2 )
{
return F_179 ( V_2 , true ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
return F_179 ( V_2 , false ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_157 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_34 = V_2 -> V_6 -> V_130 ( V_2 , 0 ) ;
return V_91 ;
}
static int F_183 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_281 ( V_2 , 0 , ( V_2 -> V_6 -> V_130 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_34 & 0x0f ) ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_184 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
F_17 ( V_2 , V_188 , - 1 ) ;
if ( ( F_14 ( V_2 , F_1 ( V_2 , V_188 ) ) != 0 ) &&
( V_2 -> V_136 == 0xe2 || F_54 ( V_2 -> V_136 ^ 0x5 , V_2 -> V_189 ) ) )
V_92 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_92 ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_92 = V_91 ;
if ( F_14 ( V_2 , F_1 ( V_2 , V_188 ) ) == 0 )
V_92 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_92 ;
}
static int F_186 ( struct V_1 * V_2 )
{
if ( ! F_75 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_34 ,
& V_2 -> V_25 . V_34 ) )
return V_401 ;
return V_91 ;
}
static int F_187 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_402 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_34 ,
& V_2 -> V_22 . V_34 , 1 ) ;
V_2 -> V_25 . type = V_118 ;
return V_91 ;
}
static int F_188 ( struct V_1 * V_2 )
{
if ( F_132 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_189 &= ~ V_125 ;
return V_91 ;
}
static int F_189 ( struct V_1 * V_2 )
{
if ( F_132 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_244 = V_403 ;
V_2 -> V_189 |= V_125 ;
return V_91 ;
}
static int F_190 ( struct V_1 * V_2 )
{
V_37 V_270 , V_271 , V_272 , V_273 ;
V_270 = F_1 ( V_2 , V_247 ) ;
V_272 = F_1 ( V_2 , V_188 ) ;
V_2 -> V_6 -> V_274 ( V_2 , & V_270 , & V_271 , & V_272 , & V_273 ) ;
* F_2 ( V_2 , V_247 ) = V_270 ;
* F_2 ( V_2 , V_159 ) = V_271 ;
* F_2 ( V_2 , V_188 ) = V_272 ;
* F_2 ( V_2 , V_267 ) = V_273 ;
return V_91 ;
}
static int F_191 ( struct V_1 * V_2 )
{
V_37 V_122 ;
V_122 = V_230 | V_231 | V_232 | V_233 |
V_234 ;
V_122 &= * F_3 ( V_2 , V_247 ) >> 8 ;
V_2 -> V_189 &= ~ 0xffUL ;
V_2 -> V_189 |= V_122 | V_256 ;
return V_91 ;
}
static int F_192 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_247 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_247 ) |= ( V_2 -> V_189 & 0xff ) << 8 ;
return V_91 ;
}
static int F_193 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_94 ) {
#ifdef F_42
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_91 ;
}
static int F_194 ( struct V_1 * V_2 )
{
return V_91 ;
}
static int F_195 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = ( V_166 ) V_2 -> V_22 . V_34 ;
return V_91 ;
}
static bool F_196 ( int V_3 )
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
static int F_197 ( struct V_1 * V_2 )
{
if ( ! F_196 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_91 ;
}
static int F_198 ( struct V_1 * V_2 )
{
T_2 V_404 = V_2 -> V_22 . V_23 ;
int V_405 = V_2 -> V_19 ;
T_2 V_99 = 0 ;
static T_2 V_406 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_407 ,
0 , 0 , 0 ,
V_408 ,
} ;
if ( ! F_196 ( V_405 ) )
return F_27 ( V_2 ) ;
if ( V_404 & V_406 [ V_405 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_405 ) {
case 0 : {
T_2 V_280 ;
if ( ( ( V_404 & V_297 ) && ! ( V_404 & V_296 ) ) ||
( ( V_404 & V_409 ) && ! ( V_404 & V_410 ) ) )
return F_25 ( V_2 , 0 ) ;
V_280 = V_2 -> V_6 -> V_130 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( ( V_404 & V_297 ) && ( V_99 & V_411 ) &&
! ( V_280 & V_298 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
T_2 V_412 = 0 ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( V_99 & V_102 )
V_412 = V_413 & ~ V_414 ;
if ( V_404 & V_412 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( ( V_99 & V_102 ) && ! ( V_404 & V_298 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_91 ;
}
static int F_199 ( struct V_1 * V_2 )
{
unsigned long V_368 ;
V_2 -> V_6 -> V_374 ( V_2 , 7 , & V_368 ) ;
return V_368 & ( 1 << 13 ) ;
}
static int F_200 ( struct V_1 * V_2 )
{
int V_415 = V_2 -> V_19 ;
T_2 V_280 ;
if ( V_415 > 7 )
return F_27 ( V_2 ) ;
V_280 = V_2 -> V_6 -> V_130 ( V_2 , 4 ) ;
if ( ( V_280 & V_416 ) && ( V_415 == 4 || V_415 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_199 ( V_2 ) ) {
T_1 V_417 ;
V_2 -> V_6 -> V_374 ( V_2 , 6 , & V_417 ) ;
V_417 &= ~ 15 ;
V_417 |= V_418 | V_419 ;
V_2 -> V_6 -> V_284 ( V_2 , 6 , V_417 ) ;
return F_24 ( V_2 ) ;
}
return V_91 ;
}
static int F_201 ( struct V_1 * V_2 )
{
T_2 V_404 = V_2 -> V_22 . V_23 ;
int V_415 = V_2 -> V_19 ;
if ( ( V_415 == 6 || V_415 == 7 ) && ( V_404 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_200 ( V_2 ) ;
}
static int F_202 ( struct V_1 * V_2 )
{
T_2 V_99 ;
V_2 -> V_6 -> V_100 ( V_2 , V_101 , & V_99 ) ;
if ( ! ( V_99 & V_420 ) )
return F_27 ( V_2 ) ;
return V_91 ;
}
static int F_203 ( struct V_1 * V_2 )
{
T_2 V_421 = F_1 ( V_2 , V_247 ) ;
if ( V_421 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_202 ( V_2 ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
T_2 V_280 = V_2 -> V_6 -> V_130 ( V_2 , 4 ) ;
if ( V_280 & V_422 && V_2 -> V_6 -> V_201 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_91 ;
}
static int F_205 ( struct V_1 * V_2 )
{
T_2 V_280 = V_2 -> V_6 -> V_130 ( V_2 , 4 ) ;
T_2 V_323 = F_1 ( V_2 , V_188 ) ;
if ( ( ! ( V_280 & V_423 ) && V_2 -> V_6 -> V_201 ( V_2 ) ) ||
V_2 -> V_6 -> V_424 ( V_2 , V_323 ) )
return F_25 ( V_2 , 0 ) ;
return V_91 ;
}
static int F_206 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_207 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_134 ( V_2 , V_2 -> V_22 . V_34 , V_2 -> V_25 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_91 ;
}
static int F_208 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_207 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_134 ( V_2 , V_2 -> V_25 . V_34 , V_2 -> V_22 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_91 ;
}
static unsigned F_209 ( struct V_1 * V_2 )
{
unsigned V_74 ;
V_74 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
if ( V_74 == 8 )
V_74 = 4 ;
return V_74 ;
}
static int F_210 ( struct V_1 * V_2 , struct V_126 * V_127 ,
unsigned V_74 , bool V_425 )
{
int V_92 = V_91 ;
V_127 -> type = V_385 ;
V_127 -> V_27 = V_74 ;
V_127 -> V_79 . V_169 . V_88 = V_2 -> V_95 ;
switch ( V_127 -> V_27 ) {
case 1 :
V_127 -> V_34 = F_68 ( V_165 , V_2 ) ;
break;
case 2 :
V_127 -> V_34 = F_68 ( V_173 , V_2 ) ;
break;
case 4 :
V_127 -> V_34 = F_68 ( V_166 , V_2 ) ;
break;
case 8 :
V_127 -> V_34 = F_68 ( V_174 , V_2 ) ;
break;
}
if ( ! V_425 ) {
switch ( V_127 -> V_27 ) {
case 1 :
V_127 -> V_34 &= 0xff ;
break;
case 2 :
V_127 -> V_34 &= 0xffff ;
break;
case 4 :
V_127 -> V_34 &= 0xffffffff ;
break;
}
}
V_171:
return V_92 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_126 * V_127 ,
unsigned V_45 )
{
int V_92 = V_91 ;
switch ( V_45 ) {
case V_426 :
F_65 ( V_2 , V_127 ) ;
break;
case V_427 :
V_92 = F_210 ( V_2 , V_127 , 1 , false ) ;
break;
case V_428 :
V_2 -> V_170 . V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_429:
* V_127 = V_2 -> V_170 ;
V_2 -> V_430 = V_127 ;
if ( V_2 -> V_45 & V_431 )
F_70 ( V_2 ) ;
V_127 -> V_146 = V_127 -> V_34 ;
break;
case V_432 :
V_2 -> V_170 . V_27 = ( V_2 -> V_94 == 8 ) ? 16 : 8 ;
goto V_429;
case V_433 :
V_127 -> type = V_144 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_9 = F_3 ( V_2 , V_247 ) ;
F_56 ( V_127 ) ;
V_127 -> V_146 = V_127 -> V_34 ;
break;
case V_434 :
V_127 -> type = V_144 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 2 : V_2 -> V_94 ;
V_127 -> V_79 . V_9 = F_3 ( V_2 , V_247 ) ;
F_56 ( V_127 ) ;
V_127 -> V_146 = V_127 -> V_34 ;
break;
case V_435 :
if ( V_2 -> V_45 & V_145 ) {
V_127 -> type = V_118 ;
break;
}
V_127 -> type = V_144 ;
V_127 -> V_27 = V_2 -> V_94 ;
V_127 -> V_79 . V_9 = F_3 ( V_2 , V_267 ) ;
F_56 ( V_127 ) ;
V_127 -> V_146 = V_127 -> V_34 ;
break;
case V_436 :
V_127 -> type = V_157 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_169 . V_88 =
F_15 ( V_2 , V_164 ) ;
V_127 -> V_79 . V_169 . V_52 = V_342 ;
V_127 -> V_34 = 0 ;
V_127 -> V_187 = 1 ;
break;
case V_437 :
V_127 -> type = V_144 ;
V_127 -> V_27 = 2 ;
V_127 -> V_79 . V_9 = F_3 ( V_2 , V_267 ) ;
F_56 ( V_127 ) ;
break;
case V_438 :
V_127 -> type = V_385 ;
V_127 -> V_27 = 1 ;
V_127 -> V_34 = F_1 ( V_2 , V_188 ) & 0xff ;
break;
case V_439 :
V_92 = F_210 ( V_2 , V_127 , 1 , true ) ;
break;
case V_440 :
V_127 -> type = V_385 ;
V_127 -> V_27 = 1 ;
V_127 -> V_34 = 1 ;
break;
case V_441 :
V_92 = F_210 ( V_2 , V_127 , F_209 ( V_2 ) , true ) ;
break;
case V_442 :
V_92 = F_210 ( V_2 , V_127 , V_2 -> V_94 , true ) ;
break;
case V_443 :
V_2 -> V_170 . V_27 = 1 ;
if ( V_2 -> V_170 . type == V_144 ) {
V_2 -> V_170 . V_79 . V_9 = F_49 ( V_2 ,
V_2 -> V_20 , true ) ;
F_56 ( & V_2 -> V_170 ) ;
}
goto V_429;
case V_444 :
V_2 -> V_170 . V_27 = 2 ;
goto V_429;
case V_445 :
V_2 -> V_170 . V_27 = 4 ;
goto V_429;
case V_446 :
V_92 = F_210 ( V_2 , V_127 , 2 , false ) ;
break;
case V_447 :
V_92 = F_210 ( V_2 , V_127 , F_209 ( V_2 ) , false ) ;
break;
case V_448 :
V_127 -> type = V_157 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_169 . V_88 =
F_15 ( V_2 , V_162 ) ;
V_127 -> V_79 . V_169 . V_52 = V_2 -> V_449 ;
V_127 -> V_34 = 0 ;
V_127 -> V_187 = 1 ;
break;
case V_450 :
V_127 -> type = V_157 ;
V_127 -> V_27 = ( V_2 -> V_45 & V_145 ) ? 1 : V_2 -> V_94 ;
V_127 -> V_79 . V_169 . V_88 =
F_14 ( V_2 ,
F_1 ( V_2 , V_159 ) +
( F_1 ( V_2 , V_247 ) & 0xff ) ) ;
V_127 -> V_79 . V_169 . V_52 = V_2 -> V_449 ;
V_127 -> V_34 = 0 ;
break;
case V_451 :
V_127 -> type = V_385 ;
V_127 -> V_79 . V_169 . V_88 = V_2 -> V_95 ;
V_127 -> V_27 = V_2 -> V_94 + 2 ;
F_212 ( V_127 -> V_263 , V_127 -> V_27 , V_2 ) ;
break;
case V_452 :
V_2 -> V_170 . V_27 = V_2 -> V_94 + 2 ;
goto V_429;
case V_453 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_342 ;
break;
case V_454 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_93 ;
break;
case V_455 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_44 ;
break;
case V_456 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_155 ;
break;
case V_457 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_53 ;
break;
case V_458 :
V_127 -> type = V_385 ;
V_127 -> V_34 = V_214 ;
break;
case V_459 :
default:
V_127 -> type = V_118 ;
break;
}
V_171:
return V_92 ;
}
int F_213 ( struct V_1 * V_2 , void * V_460 , int V_461 )
{
int V_92 = V_91 ;
int V_41 = V_2 -> V_41 ;
int V_462 , V_463 , V_464 , V_465 ;
bool V_466 = false ;
bool V_467 = false ;
struct V_468 V_468 ;
V_2 -> V_170 . type = V_118 ;
V_2 -> V_430 = NULL ;
V_2 -> V_95 = V_2 -> V_31 ;
V_2 -> V_82 . V_112 = V_2 -> V_82 . V_105 ;
V_2 -> V_82 . V_109 = V_2 -> V_82 . V_105 + V_461 ;
V_2 -> V_469 = 1 ;
if ( V_461 > 0 )
memcpy ( V_2 -> V_82 . V_105 , V_460 , V_461 ) ;
else {
V_92 = F_45 ( V_2 , 1 ) ;
if ( V_92 != V_91 )
return V_92 ;
}
switch ( V_41 ) {
case V_90 :
case V_215 :
case V_97 :
V_462 = V_463 = 2 ;
break;
case V_103 :
V_462 = V_463 = 4 ;
break;
#ifdef F_42
case V_42 :
V_462 = 4 ;
V_463 = 8 ;
break;
#endif
default:
return V_377 ;
}
V_2 -> V_94 = V_462 ;
V_2 -> V_29 = V_463 ;
for (; ; ) {
switch ( V_2 -> V_136 = F_68 ( V_35 , V_2 ) ) {
case 0x66 :
V_466 = true ;
V_2 -> V_94 = V_462 ^ 6 ;
break;
case 0x67 :
if ( V_41 == V_42 )
V_2 -> V_29 = V_463 ^ 12 ;
else
V_2 -> V_29 = V_463 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_467 = true ;
V_2 -> V_449 = ( V_2 -> V_136 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_467 = true ;
V_2 -> V_449 = V_2 -> V_136 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_41 != V_42 )
goto V_470;
V_2 -> V_116 = V_2 -> V_136 ;
continue;
case 0xf0 :
V_2 -> V_223 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_136 ;
break;
default:
goto V_470;
}
V_2 -> V_116 = 0 ;
}
V_470:
if ( V_2 -> V_116 & 8 )
V_2 -> V_94 = 8 ;
V_468 = V_471 [ V_2 -> V_136 ] ;
if ( V_2 -> V_136 == 0x0f ) {
V_2 -> V_469 = 2 ;
V_2 -> V_136 = F_68 ( V_35 , V_2 ) ;
V_468 = V_472 [ V_2 -> V_136 ] ;
if ( V_2 -> V_136 == 0x38 ) {
V_2 -> V_469 = 3 ;
V_2 -> V_136 = F_68 ( V_35 , V_2 ) ;
V_468 = V_473 [ V_2 -> V_136 ] ;
}
}
V_2 -> V_45 = V_468 . V_122 ;
if ( V_2 -> V_45 & V_135 )
V_2 -> V_154 = F_68 ( V_35 , V_2 ) ;
if ( V_2 -> V_469 == 1 && ( V_2 -> V_136 == 0xc5 || V_2 -> V_136 == 0xc4 ) &&
( V_41 == V_42 || ( V_2 -> V_154 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_45 = V_474 ;
}
while ( V_2 -> V_45 & V_475 ) {
switch ( V_2 -> V_45 & V_475 ) {
case V_476 :
V_464 = ( V_2 -> V_154 >> 3 ) & 7 ;
V_468 = V_468 . V_477 . V_478 [ V_464 ] ;
break;
case V_479 :
V_464 = ( V_2 -> V_154 >> 3 ) & 7 ;
if ( ( V_2 -> V_154 >> 6 ) == 3 )
V_468 = V_468 . V_477 . V_480 -> V_481 [ V_464 ] ;
else
V_468 = V_468 . V_477 . V_480 -> V_482 [ V_464 ] ;
break;
case V_483 :
V_464 = V_2 -> V_154 & 7 ;
V_468 = V_468 . V_477 . V_478 [ V_464 ] ;
break;
case V_484 :
if ( V_2 -> V_17 && V_466 )
return V_377 ;
V_465 = V_466 ? 0x66 : V_2 -> V_17 ;
switch ( V_465 ) {
case 0x00 : V_468 = V_468 . V_477 . V_485 -> V_486 ; break;
case 0x66 : V_468 = V_468 . V_477 . V_485 -> V_487 ; break;
case 0xf2 : V_468 = V_468 . V_477 . V_485 -> V_488 ; break;
case 0xf3 : V_468 = V_468 . V_477 . V_485 -> V_489 ; break;
}
break;
case V_490 :
if ( V_2 -> V_154 > 0xbf )
V_468 = V_468 . V_477 . V_491 -> V_492 [ V_2 -> V_154 - 0xc0 ] ;
else
V_468 = V_468 . V_477 . V_491 -> V_127 [ ( V_2 -> V_154 >> 3 ) & 7 ] ;
break;
case V_493 :
if ( ( V_2 -> V_154 >> 6 ) == 3 )
V_468 = V_468 . V_477 . V_494 -> V_481 ;
else
V_468 = V_468 . V_477 . V_494 -> V_482 ;
break;
case V_495 :
if ( V_2 -> V_41 == V_42 )
V_468 = V_468 . V_477 . V_496 -> V_497 ;
else
V_468 = V_468 . V_477 . V_496 -> V_498 ;
break;
default:
return V_377 ;
}
V_2 -> V_45 &= ~ ( T_2 ) V_475 ;
V_2 -> V_45 |= V_468 . V_122 ;
}
if ( V_2 -> V_45 == 0 )
return V_377 ;
V_2 -> V_499 = V_468 . V_477 . V_499 ;
if ( F_46 ( V_2 -> V_500 ) && F_34 ( ! ( V_2 -> V_45 & V_501 ) ) )
return V_377 ;
if ( F_46 ( V_2 -> V_45 &
( V_474 | V_502 | V_503 | V_137 | V_141 | V_504 | V_505 | V_506 |
V_507 ) ) ) {
V_2 -> V_508 = V_468 . V_508 ;
V_2 -> V_12 = V_468 . V_12 ;
if ( V_2 -> V_45 & V_474 )
return V_377 ;
if ( V_41 == V_42 ) {
if ( V_2 -> V_94 == 4 && ( V_2 -> V_45 & V_502 ) )
V_2 -> V_94 = 8 ;
else if ( V_2 -> V_45 & V_506 )
V_2 -> V_94 = 8 ;
}
if ( V_2 -> V_45 & V_503 ) {
if ( V_41 == V_42 )
V_2 -> V_94 = 8 ;
else
V_2 -> V_94 = 4 ;
}
if ( ( V_2 -> V_45 & V_507 ) && V_2 -> V_94 == 2 )
V_2 -> V_94 = 4 ;
if ( V_2 -> V_45 & V_137 )
V_2 -> V_94 = 16 ;
else if ( V_2 -> V_45 & V_141 )
V_2 -> V_94 = 8 ;
}
if ( V_2 -> V_45 & V_135 ) {
V_92 = F_67 ( V_2 , & V_2 -> V_170 ) ;
if ( ! V_467 ) {
V_467 = true ;
V_2 -> V_449 = V_2 -> V_149 ;
}
} else if ( V_2 -> V_45 & V_509 )
V_92 = F_69 ( V_2 , & V_2 -> V_170 ) ;
if ( V_92 != V_91 )
goto V_171;
if ( ! V_467 )
V_2 -> V_449 = V_155 ;
V_2 -> V_170 . V_79 . V_169 . V_52 = V_2 -> V_449 ;
V_92 = F_211 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_45 >> V_510 ) & V_511 ) ;
if ( V_92 != V_91 )
goto V_171;
V_92 = F_211 ( V_2 , & V_2 -> V_242 , ( V_2 -> V_45 >> V_512 ) & V_511 ) ;
if ( V_92 != V_91 )
goto V_171;
V_92 = F_211 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_45 >> V_513 ) & V_511 ) ;
if ( V_2 -> V_168 && F_34 ( V_2 -> V_430 ) )
V_2 -> V_430 -> V_79 . V_169 . V_88 = F_14 ( V_2 ,
V_2 -> V_430 -> V_79 . V_169 . V_88 + V_2 -> V_95 ) ;
V_171:
return ( V_92 != V_91 ) ? V_377 : V_378 ;
}
bool F_214 ( struct V_1 * V_2 )
{
return V_2 -> V_45 & V_514 ;
}
static bool F_215 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_136 == 0xa6 ) || ( V_2 -> V_136 == 0xa7 ) ||
( V_2 -> V_136 == 0xae ) || ( V_2 -> V_136 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_515 ) &&
( ( V_2 -> V_189 & V_233 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_516 ) &&
( ( V_2 -> V_189 & V_233 ) == V_233 ) ) ) )
return true ;
return false ;
}
static int F_216 ( struct V_1 * V_2 )
{
bool V_517 = false ;
V_2 -> V_6 -> V_128 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_129 ( V_2 ) ;
if ( F_46 ( V_517 ) )
return F_22 ( V_2 , V_518 , 0 , false ) ;
return V_91 ;
}
static void F_217 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
if ( V_127 -> type == V_142 )
F_60 ( V_2 , & V_127 -> V_224 , V_127 -> V_79 . V_143 ) ;
}
static int F_52 ( struct V_1 * V_2 , void (* F_55)( struct F_52 * ) )
{
register void * T_6 V_519 ( V_520 ) ;
T_1 V_122 = ( V_2 -> V_189 & V_124 ) | V_125 ;
if ( ! ( V_2 -> V_45 & V_145 ) )
F_55 += F_218 ( V_2 -> V_25 . V_27 ) * V_521 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop), "+r"(__sp)
: "c"(ctxt->src2.val));
V_2 -> V_189 = ( V_2 -> V_189 & ~ V_124 ) | ( V_122 & V_124 ) ;
if ( ! F_55 )
return F_29 ( V_2 ) ;
return V_91 ;
}
void F_219 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_168 , 0 ,
( void * ) & V_2 -> V_154 - ( void * ) & V_2 -> V_168 ) ;
V_2 -> V_184 . V_178 = 0 ;
V_2 -> V_184 . V_109 = 0 ;
V_2 -> V_177 . V_109 = 0 ;
}
int F_220 ( struct V_1 * V_2 )
{
const struct V_196 * V_6 = V_2 -> V_6 ;
int V_92 = V_91 ;
int V_522 = V_2 -> V_25 . type ;
V_2 -> V_177 . V_178 = 0 ;
if ( V_2 -> V_223 && ( ! ( V_2 -> V_45 & V_523 ) || V_2 -> V_25 . type != V_157 ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_171;
}
if ( ( V_2 -> V_45 & V_524 ) == V_525 && V_2 -> V_22 . type != V_157 ) {
V_92 = F_27 ( V_2 ) ;
goto V_171;
}
if ( F_46 ( V_2 -> V_45 &
( V_526 | V_527 | V_137 | V_141 | V_504 | V_505 | V_528 | V_529 | String ) ) ) {
if ( ( V_2 -> V_41 == V_42 && ( V_2 -> V_45 & V_526 ) ) ||
( V_2 -> V_45 & V_527 ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_171;
}
if ( ( ( V_2 -> V_45 & ( V_137 | V_141 ) ) && ( ( V_6 -> V_130 ( V_2 , 0 ) & V_132 ) ) )
|| ( ( V_2 -> V_45 & V_137 ) && ! ( V_6 -> V_130 ( V_2 , 4 ) & V_530 ) ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_171;
}
if ( ( V_2 -> V_45 & ( V_137 | V_141 ) ) && ( V_6 -> V_130 ( V_2 , 0 ) & V_131 ) ) {
V_92 = F_30 ( V_2 ) ;
goto V_171;
}
if ( V_2 -> V_45 & V_141 ) {
V_92 = F_216 ( V_2 ) ;
if ( V_92 != V_91 )
goto V_171;
F_217 ( V_2 , & V_2 -> V_22 ) ;
F_217 ( V_2 , & V_2 -> V_242 ) ;
if ( ! ( V_2 -> V_45 & V_531 ) )
F_217 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_46 ( V_2 -> V_294 & V_532 ) && V_2 -> V_12 ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_533 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( ( V_2 -> V_45 & V_529 ) && V_2 -> V_41 < V_97 ) {
V_92 = F_27 ( V_2 ) ;
goto V_171;
}
if ( ( V_2 -> V_45 & V_528 ) && V_6 -> V_201 ( V_2 ) ) {
if ( V_2 -> V_45 & V_534 )
V_92 = F_27 ( V_2 ) ;
else
V_92 = F_25 ( V_2 , 0 ) ;
goto V_171;
}
if ( V_2 -> V_45 & V_505 ) {
V_92 = V_2 -> V_508 ( V_2 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( F_46 ( V_2 -> V_294 & V_532 ) && ( V_2 -> V_45 & V_504 ) ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_535 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
if ( F_14 ( V_2 , F_1 ( V_2 , V_188 ) ) == 0 ) {
F_135 ( V_2 ) ;
V_2 -> V_31 = V_2 -> V_95 ;
V_2 -> V_189 &= ~ V_255 ;
goto V_171;
}
}
}
if ( ( V_2 -> V_22 . type == V_157 ) && ! ( V_2 -> V_45 & V_536 ) ) {
V_92 = F_72 ( V_2 , V_2 -> V_22 . V_79 . V_169 ,
V_2 -> V_22 . V_263 , V_2 -> V_22 . V_27 ) ;
if ( V_92 != V_91 )
goto V_171;
V_2 -> V_22 . V_266 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_242 . type == V_157 ) {
V_92 = F_72 ( V_2 , V_2 -> V_242 . V_79 . V_169 ,
& V_2 -> V_242 . V_34 , V_2 -> V_242 . V_27 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( ( V_2 -> V_45 & V_537 ) == V_538 )
goto V_539;
if ( ( V_2 -> V_25 . type == V_157 ) && ! ( V_2 -> V_45 & V_531 ) ) {
V_92 = F_72 ( V_2 , V_2 -> V_25 . V_79 . V_169 ,
& V_2 -> V_25 . V_34 , V_2 -> V_25 . V_27 ) ;
if ( V_92 != V_91 ) {
if ( ! ( V_2 -> V_45 & V_540 ) &&
V_92 == V_61 &&
V_2 -> V_57 . V_58 == V_541 )
V_2 -> V_57 . V_59 |= V_542 ;
goto V_171;
}
}
V_2 -> V_25 . V_266 = V_2 -> V_25 . V_23 ;
V_539:
if ( F_46 ( V_2 -> V_294 & V_532 ) && ( V_2 -> V_45 & V_504 ) ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_543 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) )
V_2 -> V_189 |= V_255 ;
else
V_2 -> V_189 &= ~ V_255 ;
if ( V_2 -> V_499 ) {
if ( V_2 -> V_45 & V_544 ) {
void (* F_55)( struct F_52 * ) = ( void * ) V_2 -> V_499 ;
V_92 = F_52 ( V_2 , F_55 ) ;
if ( V_92 != V_91 )
goto V_171;
goto F_88;
}
V_92 = V_2 -> V_499 ( V_2 ) ;
if ( V_92 != V_91 )
goto V_171;
goto F_88;
}
if ( V_2 -> V_469 == 2 )
goto V_545;
else if ( V_2 -> V_469 == 3 )
goto V_546;
switch ( V_2 -> V_136 ) {
case 0x70 ... 0x7f :
if ( F_54 ( V_2 -> V_136 , V_2 -> V_189 ) )
V_92 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_79 . V_169 . V_88 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_79 . V_9 == F_3 ( V_2 , V_247 ) )
V_2 -> V_25 . type = V_118 ;
else
V_92 = F_153 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_94 ) {
case 2 : V_2 -> V_25 . V_34 = ( V_165 ) V_2 -> V_25 . V_34 ; break;
case 4 : V_2 -> V_25 . V_34 = ( V_173 ) V_2 -> V_25 . V_34 ; break;
case 8 : V_2 -> V_25 . V_34 = ( V_166 ) V_2 -> V_25 . V_34 ; break;
}
break;
case 0xcc :
V_92 = F_104 ( V_2 , 3 ) ;
break;
case 0xcd :
V_92 = F_104 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0xce :
if ( V_2 -> V_189 & V_235 )
V_92 = F_104 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_92 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
V_2 -> V_25 . type = V_118 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_547 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_189 ^= V_230 ;
break;
case 0xf8 :
V_2 -> V_189 &= ~ V_230 ;
break;
case 0xf9 :
V_2 -> V_189 |= V_230 ;
break;
case 0xfc :
V_2 -> V_189 &= ~ V_190 ;
break;
case 0xfd :
V_2 -> V_189 |= V_190 ;
break;
default:
goto V_548;
}
if ( V_92 != V_91 )
goto V_171;
F_88:
if ( V_2 -> V_45 & V_549 ) {
F_221 ( V_2 -> V_22 . type == V_157 || V_2 -> V_22 . type == V_191 ) ;
V_92 = F_88 ( V_2 , & V_2 -> V_22 ) ;
if ( V_92 != V_91 )
goto V_171;
}
if ( ! ( V_2 -> V_45 & V_540 ) ) {
V_92 = F_88 ( V_2 , & V_2 -> V_25 ) ;
if ( V_92 != V_91 )
goto V_171;
}
V_2 -> V_25 . type = V_522 ;
if ( ( V_2 -> V_45 & V_524 ) == V_550 )
F_145 ( V_2 , V_162 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_45 & V_537 ) == V_551 )
F_145 ( V_2 , V_164 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
unsigned int V_187 ;
struct V_175 * V_291 = & V_2 -> V_184 ;
if ( ( V_2 -> V_45 & V_524 ) == V_550 )
V_187 = V_2 -> V_22 . V_187 ;
else
V_187 = V_2 -> V_25 . V_187 ;
F_17 ( V_2 , V_188 , - V_187 ) ;
if ( ! F_215 ( V_2 ) ) {
if ( ( V_291 -> V_109 != 0 || F_1 ( V_2 , V_188 ) & 0x3ff ) &&
( V_291 -> V_109 == 0 || V_291 -> V_109 != V_291 -> V_178 ) ) {
V_2 -> V_177 . V_109 = 0 ;
F_4 ( V_2 ) ;
return V_552 ;
}
goto V_171;
}
V_2 -> V_189 &= ~ V_255 ;
}
V_2 -> V_31 = V_2 -> V_95 ;
V_171:
if ( V_92 == V_61 ) {
F_23 ( V_2 -> V_57 . V_58 > 0x1f ) ;
V_2 -> V_553 = true ;
}
if ( V_92 == V_554 )
return V_555 ;
if ( V_92 == V_91 )
F_4 ( V_2 ) ;
return ( V_92 == V_220 ) ? V_377 : V_378 ;
V_545:
switch ( V_2 -> V_136 ) {
case 0x09 :
( V_2 -> V_6 -> V_556 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_34 = V_6 -> V_130 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_374 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_34 ) ;
break;
case 0x40 ... 0x4f :
if ( F_54 ( V_2 -> V_136 , V_2 -> V_189 ) )
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
else if ( V_2 -> V_94 != 4 )
V_2 -> V_25 . type = V_118 ;
break;
case 0x80 ... 0x8f :
if ( F_54 ( V_2 -> V_136 , V_2 -> V_189 ) )
V_92 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_34 = F_54 ( V_2 -> V_136 , V_2 -> V_189 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_94 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_35 ) V_2 -> V_22 . V_34
: ( V_36 ) V_2 -> V_22 . V_34 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_94 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_165 ) V_2 -> V_22 . V_34 :
( V_173 ) V_2 -> V_22 . V_34 ;
break;
default:
goto V_548;
}
V_546:
if ( V_92 != V_91 )
goto V_171;
goto F_88;
V_548:
return V_377 ;
}
void F_222 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_223 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
