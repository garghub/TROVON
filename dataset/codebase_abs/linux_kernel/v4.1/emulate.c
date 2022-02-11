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
T_1 V_33 ;
if ( V_2 -> V_29 == sizeof( unsigned long ) )
V_33 = ~ 0UL ;
else
V_33 = F_10 ( V_2 ) ;
F_16 ( F_3 ( V_2 , V_9 ) , V_33 , V_46 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_46 )
{
F_16 ( F_3 ( V_2 , V_47 ) , F_11 ( V_2 ) , V_46 ) ;
}
static V_37 F_19 ( struct V_39 * V_48 )
{
V_37 V_49 = F_20 ( V_48 ) ;
return V_48 -> V_50 ? ( V_49 << 12 ) | 0xfff : V_49 ;
}
static unsigned long F_21 ( struct V_1 * V_2 , int V_51 )
{
if ( V_2 -> V_41 == V_42 && V_51 < V_52 )
return 0 ;
return V_2 -> V_6 -> V_53 ( V_2 , V_51 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_54 ,
V_37 error , bool V_55 )
{
F_23 ( V_54 > 0x1f ) ;
V_2 -> V_56 . V_57 = V_54 ;
V_2 -> V_56 . V_58 = error ;
V_2 -> V_56 . V_59 = V_55 ;
return V_60 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_61 , 0 , false ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_62 )
{
return F_22 ( V_2 , V_63 , V_62 , true ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_62 )
{
return F_22 ( V_2 , V_64 , V_62 , true ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_65 , 0 , false ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_62 )
{
return F_22 ( V_2 , V_66 , V_62 , true ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_67 , 0 , false ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_68 , 0 , false ) ;
}
static V_36 F_31 ( struct V_1 * V_2 , unsigned V_51 )
{
V_36 V_69 ;
struct V_39 V_48 ;
V_2 -> V_6 -> V_43 ( V_2 , & V_69 , & V_48 , NULL , V_51 ) ;
return V_69 ;
}
static void F_32 ( struct V_1 * V_2 , V_36 V_69 ,
unsigned V_51 )
{
V_36 V_70 ;
V_37 V_71 ;
struct V_39 V_48 ;
V_2 -> V_6 -> V_43 ( V_2 , & V_70 , & V_48 , & V_71 , V_51 ) ;
V_2 -> V_6 -> V_72 ( V_2 , V_69 , & V_48 , V_71 , V_51 ) ;
}
static bool F_33 ( struct V_1 * V_2 , unsigned V_73 )
{
if ( F_34 ( V_73 < 16 ) )
return false ;
if ( V_2 -> V_45 & V_74 )
return true ;
else if ( V_2 -> V_45 & V_75 )
return false ;
else if ( V_2 -> V_45 & V_76 )
return false ;
else
return true ;
}
static T_3 int F_35 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
unsigned * V_79 , unsigned V_73 ,
bool V_80 , bool V_81 ,
enum V_82 V_41 , T_1 * V_83 )
{
struct V_39 V_48 ;
bool V_84 ;
T_1 V_85 ;
V_37 V_86 ;
V_36 V_38 ;
V_85 = F_21 ( V_2 , V_78 . V_51 ) + V_78 . V_87 ;
* V_79 = 0 ;
switch ( V_41 ) {
case V_42 :
if ( F_36 ( V_85 ) )
goto V_88;
* V_79 = F_37 ( T_2 , ~ 0u , ( 1ull << 48 ) - V_85 ) ;
if ( V_73 > * V_79 )
goto V_88;
break;
default:
V_84 = V_2 -> V_6 -> V_43 ( V_2 , & V_38 , & V_48 , NULL ,
V_78 . V_51 ) ;
if ( ! V_84 )
goto V_88;
if ( ( ( ( V_2 -> V_41 != V_89 ) && ( V_48 . type & 8 ) )
|| ! ( V_48 . type & 2 ) ) && V_80 )
goto V_88;
if ( ! V_81 && ( V_48 . type & 8 ) && ! ( V_48 . type & 2 ) )
goto V_88;
V_86 = F_19 ( & V_48 ) ;
if ( ! ( V_48 . type & 8 ) && ( V_48 . type & 4 ) ) {
if ( V_78 . V_87 <= V_86 )
goto V_88;
V_86 = V_48 . V_45 ? 0xffffffff : 0xffff ;
}
if ( V_78 . V_87 > V_86 )
goto V_88;
if ( V_86 == 0xffffffff )
* V_79 = ~ 0u ;
else {
* V_79 = ( T_2 ) V_86 + 1 - V_78 . V_87 ;
if ( V_73 > * V_79 )
goto V_88;
}
V_85 &= ( V_37 ) - 1 ;
break;
}
if ( F_33 ( V_2 , V_73 ) && ( ( V_85 & ( V_73 - 1 ) ) != 0 ) )
return F_25 ( V_2 , 0 ) ;
* V_83 = V_85 ;
return V_90 ;
V_88:
if ( V_78 . V_51 == V_44 )
return F_26 ( V_2 , 0 ) ;
else
return F_25 ( V_2 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
unsigned V_73 , bool V_80 ,
T_1 * V_83 )
{
unsigned V_79 ;
return F_35 ( V_2 , V_78 , & V_79 , V_73 , V_80 , false ,
V_2 -> V_41 , V_83 ) ;
}
static inline int F_39 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_82 V_41 )
{
T_1 V_83 ;
int V_91 ;
unsigned V_79 ;
struct V_77 V_78 = { . V_51 = V_92 ,
. V_87 = V_25 } ;
if ( V_2 -> V_93 != sizeof( unsigned long ) )
V_78 . V_87 = V_25 & ( ( 1UL << ( V_2 -> V_93 << 3 ) ) - 1 ) ;
V_91 = F_35 ( V_2 , V_78 , & V_79 , 1 , false , true , V_41 , & V_83 ) ;
if ( V_91 == V_90 )
V_2 -> V_94 = V_78 . V_87 ;
return V_91 ;
}
static inline int F_40 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_39 ( V_2 , V_25 , V_2 -> V_41 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_25 ,
const struct V_39 * V_95 )
{
enum V_82 V_41 = V_2 -> V_41 ;
int V_91 ;
#ifdef F_42
if ( V_2 -> V_41 >= V_96 ) {
if ( V_95 -> V_97 ) {
T_2 V_98 = 0 ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( V_98 & V_101 )
V_41 = V_42 ;
} else
V_41 = V_102 ;
}
#endif
if ( V_41 == V_96 || V_41 == V_102 )
V_41 = V_95 -> V_45 ? V_102 : V_96 ;
V_91 = F_39 ( V_2 , V_25 , V_41 ) ;
if ( V_91 == V_90 )
V_2 -> V_41 = V_41 ;
return V_91 ;
}
static inline int F_43 ( struct V_1 * V_2 , int V_103 )
{
return F_40 ( V_2 , V_2 -> V_94 + V_103 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
void * V_104 ,
unsigned V_73 )
{
int V_91 ;
T_1 V_83 ;
V_91 = F_38 ( V_2 , V_78 , V_73 , false , & V_83 ) ;
if ( V_91 != V_90 )
return V_91 ;
return V_2 -> V_6 -> V_105 ( V_2 , V_83 , V_104 , V_73 , & V_2 -> V_56 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_106 )
{
int V_91 ;
unsigned V_73 , V_79 ;
unsigned long V_83 ;
int V_107 = V_2 -> V_81 . V_108 - V_2 -> V_81 . V_104 ;
struct V_77 V_78 = { . V_51 = V_92 ,
. V_87 = V_2 -> V_31 + V_107 } ;
V_91 = F_35 ( V_2 , V_78 , & V_79 , 0 , false , true , V_2 -> V_41 ,
& V_83 ) ;
if ( F_46 ( V_91 != V_90 ) )
return V_91 ;
V_73 = F_37 ( unsigned , 15UL ^ V_107 , V_79 ) ;
V_73 = F_37 ( unsigned , V_73 , V_109 - F_47 ( V_83 ) ) ;
if ( F_46 ( V_73 < V_106 ) )
return F_25 ( V_2 , 0 ) ;
V_91 = V_2 -> V_6 -> V_81 ( V_2 , V_83 , V_2 -> V_81 . V_108 ,
V_73 , & V_2 -> V_56 ) ;
if ( F_46 ( V_91 != V_90 ) )
return V_91 ;
V_2 -> V_81 . V_108 += V_73 ;
return V_90 ;
}
static T_3 int F_48 ( struct V_1 * V_2 ,
unsigned V_73 )
{
unsigned V_110 = V_2 -> V_81 . V_108 - V_2 -> V_81 . V_111 ;
if ( F_46 ( V_110 < V_73 ) )
return F_45 ( V_2 , V_73 - V_110 ) ;
else
return V_90 ;
}
static void * F_49 ( struct V_1 * V_2 , V_35 V_19 ,
int V_112 )
{
void * V_113 ;
int V_114 = ( V_2 -> V_115 == 0 ) && V_112 ;
if ( V_114 && V_19 >= 4 && V_19 < 8 )
V_113 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_113 = F_3 ( V_2 , V_19 ) ;
return V_113 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
V_36 * V_73 , unsigned long * V_116 , int V_93 )
{
int V_91 ;
if ( V_93 == 2 )
V_93 = 3 ;
* V_116 = 0 ;
V_91 = F_44 ( V_2 , V_78 , V_73 , 2 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_78 . V_87 += 2 ;
V_91 = F_44 ( V_2 , V_78 , V_116 , V_93 ) ;
return V_91 ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_117 ;
return F_52 ( V_2 , V_118 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_117 ;
return F_52 ( V_2 , V_119 ) ;
}
static V_35 F_54 ( unsigned int V_120 , unsigned long V_121 )
{
V_35 V_91 ;
void (* F_55)( void ) = ( void * ) V_122 + 4 * ( V_120 & 0xf ) ;
V_121 = ( V_121 & V_123 ) | V_124 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_91 ;
}
static void F_56 ( struct V_125 * V_126 )
{
switch ( V_126 -> V_27 ) {
case 1 :
V_126 -> V_34 = * ( V_35 * ) V_126 -> V_78 . V_9 ;
break;
case 2 :
V_126 -> V_34 = * ( V_36 * ) V_126 -> V_78 . V_9 ;
break;
case 4 :
V_126 -> V_34 = * ( V_37 * ) V_126 -> V_78 . V_9 ;
break;
case 8 :
V_126 -> V_34 = * ( T_2 * ) V_126 -> V_78 . V_9 ;
break;
}
}
static void F_57 ( struct V_1 * V_2 , T_4 * V_104 , int V_9 )
{
V_2 -> V_6 -> V_127 ( V_2 ) ;
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
V_2 -> V_6 -> V_128 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , T_4 * V_104 ,
int V_9 )
{
V_2 -> V_6 -> V_127 ( V_2 ) ;
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
V_2 -> V_6 -> V_128 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_2 * V_104 , int V_9 )
{
V_2 -> V_6 -> V_127 ( V_2 ) ;
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
V_2 -> V_6 -> V_128 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , T_2 * V_104 , int V_9 )
{
V_2 -> V_6 -> V_127 ( V_2 ) ;
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
V_2 -> V_6 -> V_128 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_129 ( V_2 , 0 ) & ( V_130 | V_131 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_127 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_128 ( V_2 ) ;
return V_90 ;
}
static int F_63 ( struct V_1 * V_2 )
{
V_36 V_132 ;
if ( V_2 -> V_6 -> V_129 ( V_2 , 0 ) & ( V_130 | V_131 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_127 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_128 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_132 ;
return V_90 ;
}
static int F_64 ( struct V_1 * V_2 )
{
V_36 V_133 ;
if ( V_2 -> V_6 -> V_129 ( V_2 , 0 ) & ( V_130 | V_131 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_127 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_128 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_133 ;
return V_90 ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_45 & V_134 ) )
V_9 = ( V_2 -> V_135 & 7 ) | ( ( V_2 -> V_115 & 1 ) << 3 ) ;
if ( V_2 -> V_45 & V_136 ) {
V_126 -> type = V_137 ;
V_126 -> V_27 = 16 ;
V_126 -> V_78 . V_138 = V_9 ;
F_57 ( V_2 , & V_126 -> V_139 , V_9 ) ;
return;
}
if ( V_2 -> V_45 & V_140 ) {
V_9 &= 7 ;
V_126 -> type = V_141 ;
V_126 -> V_27 = 8 ;
V_126 -> V_78 . V_142 = V_9 ;
return;
}
V_126 -> type = V_143 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_9 = F_49 ( V_2 , V_9 , V_2 -> V_45 & V_144 ) ;
F_56 ( V_126 ) ;
V_126 -> V_145 = V_126 -> V_34 ;
}
static void F_66 ( struct V_1 * V_2 , int V_146 )
{
if ( V_146 == V_47 || V_146 == V_147 )
V_2 -> V_148 = V_44 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
V_35 V_149 ;
int V_150 , V_146 , V_151 ;
int V_91 = V_90 ;
T_1 V_152 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_115 << 1 ) & 8 ) ;
V_150 = ( V_2 -> V_115 << 2 ) & 8 ;
V_146 = ( V_2 -> V_115 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_153 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_153 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_146 | ( V_2 -> V_153 & 0x07 ) ;
V_2 -> V_148 = V_154 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_45 & V_155 ) ) {
V_126 -> type = V_143 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_9 = F_49 ( V_2 , V_2 -> V_20 ,
V_2 -> V_45 & V_144 ) ;
if ( V_2 -> V_45 & V_136 ) {
V_126 -> type = V_137 ;
V_126 -> V_27 = 16 ;
V_126 -> V_78 . V_138 = V_2 -> V_20 ;
F_57 ( V_2 , & V_126 -> V_139 , V_2 -> V_20 ) ;
return V_91 ;
}
if ( V_2 -> V_45 & V_140 ) {
V_126 -> type = V_141 ;
V_126 -> V_27 = 8 ;
V_126 -> V_78 . V_142 = V_2 -> V_20 & 7 ;
return V_91 ;
}
F_56 ( V_126 ) ;
return V_91 ;
}
V_126 -> type = V_156 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_157 = F_1 ( V_2 , V_158 ) ;
unsigned V_159 = F_1 ( V_2 , V_147 ) ;
unsigned V_160 = F_1 ( V_2 , V_161 ) ;
unsigned V_162 = F_1 ( V_2 , V_163 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_152 += F_68 ( V_36 , V_2 ) ;
break;
case 1 :
V_152 += F_68 ( V_164 , V_2 ) ;
break;
case 2 :
V_152 += F_68 ( V_36 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_152 += V_157 + V_160 ;
break;
case 1 :
V_152 += V_157 + V_162 ;
break;
case 2 :
V_152 += V_159 + V_160 ;
break;
case 3 :
V_152 += V_159 + V_162 ;
break;
case 4 :
V_152 += V_160 ;
break;
case 5 :
V_152 += V_162 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_152 += V_159 ;
break;
case 7 :
V_152 += V_157 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_148 = V_44 ;
V_152 = ( V_36 ) V_152 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_149 = F_68 ( V_35 , V_2 ) ;
V_150 |= ( V_149 >> 3 ) & 7 ;
V_146 |= V_149 & 7 ;
V_151 = V_149 >> 6 ;
if ( ( V_146 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_152 += F_68 ( V_165 , V_2 ) ;
else {
V_152 += F_1 ( V_2 , V_146 ) ;
F_66 ( V_2 , V_146 ) ;
if ( ( V_2 -> V_45 & V_166 ) &&
V_146 == V_47 )
V_152 += V_2 -> V_93 ;
}
if ( V_150 != 4 )
V_152 += F_1 ( V_2 , V_150 ) << V_151 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_152 += F_68 ( V_165 , V_2 ) ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_167 = 1 ;
} else {
V_146 = V_2 -> V_20 ;
V_152 += F_1 ( V_2 , V_146 ) ;
F_66 ( V_2 , V_146 ) ;
}
switch ( V_2 -> V_18 ) {
case 1 :
V_152 += F_68 ( V_164 , V_2 ) ;
break;
case 2 :
V_152 += F_68 ( V_165 , V_2 ) ;
break;
}
}
V_126 -> V_78 . V_168 . V_87 = V_152 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_169 . V_78 . V_168 . V_87 = ( V_37 ) V_2 -> V_169 . V_78 . V_168 . V_87 ;
V_170:
return V_91 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
int V_91 = V_90 ;
V_126 -> type = V_156 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_126 -> V_78 . V_168 . V_87 = F_68 ( V_36 , V_2 ) ;
break;
case 4 :
V_126 -> V_78 . V_168 . V_87 = F_68 ( V_37 , V_2 ) ;
break;
case 8 :
V_126 -> V_78 . V_168 . V_87 = F_68 ( T_2 , V_2 ) ;
break;
}
V_170:
return V_91 ;
}
static void F_70 ( struct V_1 * V_2 )
{
long V_171 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_156 && V_2 -> V_22 . type == V_143 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_171 = ( V_172 ) V_2 -> V_22 . V_34 & ( V_172 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_171 = ( V_165 ) V_2 -> V_22 . V_34 & ( V_165 ) V_33 ;
else
V_171 = ( V_173 ) V_2 -> V_22 . V_34 & ( V_173 ) V_33 ;
V_2 -> V_25 . V_78 . V_168 . V_87 = F_14 ( V_2 ,
V_2 -> V_25 . V_78 . V_168 . V_87 + ( V_171 >> 3 ) ) ;
}
V_2 -> V_22 . V_34 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned long V_78 , void * V_32 , unsigned V_73 )
{
int V_91 ;
struct V_174 * V_175 = & V_2 -> V_176 ;
if ( V_175 -> V_177 < V_175 -> V_108 )
goto V_178;
F_23 ( ( V_175 -> V_108 + V_73 ) >= sizeof( V_175 -> V_104 ) ) ;
V_91 = V_2 -> V_6 -> F_71 ( V_2 , V_78 , V_175 -> V_104 + V_175 -> V_108 , V_73 ,
& V_2 -> V_56 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_175 -> V_108 += V_73 ;
V_178:
memcpy ( V_32 , V_175 -> V_104 + V_175 -> V_177 , V_73 ) ;
V_175 -> V_177 += V_73 ;
return V_90 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
void * V_104 ,
unsigned V_73 )
{
int V_91 ;
T_1 V_83 ;
V_91 = F_38 ( V_2 , V_78 , V_73 , false , & V_83 ) ;
if ( V_91 != V_90 )
return V_91 ;
return F_71 ( V_2 , V_83 , V_104 , V_73 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
const void * V_104 ,
unsigned V_73 )
{
int V_91 ;
T_1 V_83 ;
V_91 = F_38 ( V_2 , V_78 , V_73 , true , & V_83 ) ;
if ( V_91 != V_90 )
return V_91 ;
return V_2 -> V_6 -> V_179 ( V_2 , V_83 , V_104 , V_73 ,
& V_2 -> V_56 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_77 V_78 ,
const void * V_180 , const void * V_104 ,
unsigned V_73 )
{
int V_91 ;
T_1 V_83 ;
V_91 = F_38 ( V_2 , V_78 , V_73 , true , & V_83 ) ;
if ( V_91 != V_90 )
return V_91 ;
return V_2 -> V_6 -> V_181 ( V_2 , V_83 , V_180 , V_104 ,
V_73 , & V_2 -> V_56 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
unsigned int V_73 , unsigned short V_182 ,
void * V_32 )
{
struct V_174 * V_91 = & V_2 -> V_183 ;
if ( V_91 -> V_177 == V_91 -> V_108 ) {
unsigned int V_184 , V_185 ;
unsigned int V_186 = V_2 -> V_17 ?
F_14 ( V_2 , F_1 ( V_2 , V_187 ) ) : 1 ;
V_184 = ( V_2 -> V_188 & V_189 ) ?
F_47 ( F_1 ( V_2 , V_163 ) ) :
V_109 - F_47 ( F_1 ( V_2 , V_163 ) ) ;
V_185 = F_76 ( V_184 , ( unsigned int ) sizeof( V_91 -> V_104 ) / V_73 , V_186 ) ;
if ( V_185 == 0 )
V_185 = 1 ;
V_91 -> V_177 = V_91 -> V_108 = 0 ;
if ( ! V_2 -> V_6 -> F_75 ( V_2 , V_73 , V_182 , V_91 -> V_104 , V_185 ) )
return 0 ;
V_91 -> V_108 = V_185 * V_73 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) &&
! ( V_2 -> V_188 & V_189 ) ) {
V_2 -> V_25 . V_104 = V_91 -> V_104 + V_91 -> V_177 ;
V_2 -> V_25 . type = V_190 ;
V_2 -> V_25 . V_186 = ( V_91 -> V_108 - V_91 -> V_177 ) / V_73 ;
V_91 -> V_177 = V_91 -> V_108 ;
} else {
memcpy ( V_32 , V_91 -> V_104 + V_91 -> V_177 , V_73 ) ;
V_91 -> V_177 += V_73 ;
}
return 1 ;
}
static int F_77 ( struct V_1 * V_2 ,
V_36 V_191 , struct V_39 * V_48 )
{
struct V_192 V_193 ;
T_1 V_78 ;
V_2 -> V_6 -> V_194 ( V_2 , & V_193 ) ;
if ( V_193 . V_73 < V_191 * 8 + 7 )
return F_25 ( V_2 , V_191 << 3 | 0x2 ) ;
V_78 = V_193 . V_116 + V_191 * 8 ;
return V_2 -> V_6 -> V_105 ( V_2 , V_78 , V_48 , sizeof *V_48 ,
& V_2 -> V_56 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
V_36 V_69 , struct V_192 * V_193 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
V_37 V_71 = 0 ;
if ( V_69 & 1 << 2 ) {
struct V_39 V_48 ;
V_36 V_38 ;
memset ( V_193 , 0 , sizeof *V_193 ) ;
if ( ! V_6 -> V_43 ( V_2 , & V_38 , & V_48 , & V_71 ,
V_196 ) )
return;
V_193 -> V_73 = F_19 ( & V_48 ) ;
V_193 -> V_116 = F_79 ( & V_48 ) | ( ( T_2 ) V_71 << 32 ) ;
} else
V_6 -> V_197 ( V_2 , V_193 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
V_36 V_69 , T_1 * V_198 )
{
struct V_192 V_193 ;
V_36 V_191 = V_69 >> 3 ;
T_1 V_78 ;
F_78 ( V_2 , V_69 , & V_193 ) ;
if ( V_193 . V_73 < V_191 * 8 + 7 )
return F_25 ( V_2 , V_69 & 0xfffc ) ;
V_78 = V_193 . V_116 + V_191 * 8 ;
#ifdef F_42
if ( V_78 >> 32 != 0 ) {
T_2 V_98 = 0 ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( ! ( V_98 & V_101 ) )
V_78 &= ( V_37 ) - 1 ;
}
#endif
* V_198 = V_78 ;
return V_90 ;
}
static int F_81 ( struct V_1 * V_2 ,
V_36 V_69 , struct V_39 * V_48 ,
T_1 * V_198 )
{
int V_91 ;
V_91 = F_80 ( V_2 , V_69 , V_198 ) ;
if ( V_91 != V_90 )
return V_91 ;
return V_2 -> V_6 -> V_105 ( V_2 , * V_198 , V_48 , sizeof( * V_48 ) ,
& V_2 -> V_56 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
V_36 V_69 , struct V_39 * V_48 )
{
int V_91 ;
T_1 V_78 ;
V_91 = F_80 ( V_2 , V_69 , & V_78 ) ;
if ( V_91 != V_90 )
return V_91 ;
return V_2 -> V_6 -> V_199 ( V_2 , V_78 , V_48 , sizeof *V_48 ,
& V_2 -> V_56 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
V_36 V_69 , int V_51 , V_35 V_200 ,
enum V_201 V_202 ,
struct V_39 * V_48 )
{
struct V_39 V_203 , V_204 ;
V_35 V_205 , V_206 ;
unsigned V_207 = V_63 ;
V_37 V_208 = 0 ;
bool V_209 = ! ( V_69 & ~ 0x3 ) ;
T_1 V_210 ;
int V_211 ;
V_36 V_70 ;
V_37 V_71 = 0 ;
memset ( & V_203 , 0 , sizeof V_203 ) ;
if ( V_2 -> V_41 == V_89 ) {
V_2 -> V_6 -> V_43 ( V_2 , & V_70 , & V_203 , NULL , V_51 ) ;
F_84 ( & V_203 , V_69 << 4 ) ;
goto V_212;
} else if ( V_51 <= V_213 && V_2 -> V_41 == V_214 ) {
F_84 ( & V_203 , V_69 << 4 ) ;
F_85 ( & V_203 , 0xffff ) ;
V_203 . type = 3 ;
V_203 . V_113 = 1 ;
V_203 . V_215 = 1 ;
V_203 . V_205 = 3 ;
goto V_212;
}
V_206 = V_69 & 3 ;
if ( ( V_51 == V_92
|| ( V_51 == V_44
&& ( V_2 -> V_41 != V_42 || V_206 != V_200 ) )
|| V_51 == V_216 )
&& V_209 )
goto V_56;
if ( V_51 == V_216 && ( V_69 & ( 1 << 2 ) ) )
goto V_56;
if ( V_209 )
goto V_212;
V_211 = F_81 ( V_2 , V_69 , & V_203 , & V_210 ) ;
if ( V_211 != V_90 )
return V_211 ;
V_208 = V_69 & 0xfffc ;
V_207 = ( V_202 == V_217 ) ? V_66 :
V_63 ;
if ( V_51 <= V_213 && ! V_203 . V_215 ) {
if ( V_202 == V_218 )
return V_219 ;
goto V_56;
}
if ( ! V_203 . V_113 ) {
V_207 = ( V_51 == V_44 ) ? V_64 : V_220 ;
goto V_56;
}
V_205 = V_203 . V_205 ;
switch ( V_51 ) {
case V_44 :
if ( V_206 != V_200 || ( V_203 . type & 0xa ) != 0x2 || V_205 != V_200 )
goto V_56;
break;
case V_92 :
if ( ! ( V_203 . type & 8 ) )
goto V_56;
if ( V_203 . type & 4 ) {
if ( V_205 > V_200 )
goto V_56;
} else {
if ( V_206 > V_200 || V_205 != V_200 )
goto V_56;
}
if ( V_203 . V_45 && V_203 . V_97 ) {
T_2 V_98 = 0 ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( V_98 & V_101 )
goto V_56;
}
V_69 = ( V_69 & 0xfffc ) | V_200 ;
break;
case V_216 :
if ( V_203 . V_215 || ( V_203 . type != 1 && V_203 . type != 9 ) )
goto V_56;
V_204 = V_203 ;
V_203 . type |= 2 ;
V_211 = V_2 -> V_6 -> V_181 ( V_2 , V_210 , & V_204 , & V_203 ,
sizeof( V_203 ) , & V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
break;
case V_196 :
if ( V_203 . V_215 || V_203 . type != 2 )
goto V_56;
break;
default:
if ( ( V_203 . type & 0xa ) == 0x8 ||
( ( ( V_203 . type & 0xc ) != 0xc ) &&
( V_206 > V_205 && V_200 > V_205 ) ) )
goto V_56;
break;
}
if ( V_203 . V_215 ) {
if ( ! ( V_203 . type & 1 ) ) {
V_203 . type |= 1 ;
V_211 = F_82 ( V_2 , V_69 ,
& V_203 ) ;
if ( V_211 != V_90 )
return V_211 ;
}
} else if ( V_2 -> V_41 == V_42 ) {
V_211 = V_2 -> V_6 -> V_105 ( V_2 , V_210 + 8 , & V_71 ,
sizeof( V_71 ) , & V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
if ( F_36 ( F_79 ( & V_203 ) |
( ( T_2 ) V_71 << 32 ) ) )
return F_25 ( V_2 , 0 ) ;
}
V_212:
V_2 -> V_6 -> V_72 ( V_2 , V_69 , & V_203 , V_71 , V_51 ) ;
if ( V_48 )
* V_48 = V_203 ;
return V_90 ;
V_56:
return F_22 ( V_2 , V_207 , V_208 , true ) ;
}
static int F_86 ( struct V_1 * V_2 ,
V_36 V_69 , int V_51 )
{
V_35 V_200 = V_2 -> V_6 -> V_200 ( V_2 ) ;
return F_83 ( V_2 , V_69 , V_51 , V_200 ,
V_221 , NULL ) ;
}
static void F_87 ( struct V_125 * V_126 )
{
return F_9 ( V_126 -> V_78 . V_9 , V_126 -> V_34 , V_126 -> V_27 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
switch ( V_126 -> type ) {
case V_143 :
F_87 ( V_126 ) ;
break;
case V_156 :
if ( V_2 -> V_222 )
return F_74 ( V_2 ,
V_126 -> V_78 . V_168 ,
& V_126 -> V_145 ,
& V_126 -> V_34 ,
V_126 -> V_27 ) ;
else
return F_73 ( V_2 ,
V_126 -> V_78 . V_168 ,
& V_126 -> V_34 ,
V_126 -> V_27 ) ;
break;
case V_190 :
return F_73 ( V_2 ,
V_126 -> V_78 . V_168 ,
V_126 -> V_104 ,
V_126 -> V_27 * V_126 -> V_186 ) ;
break;
case V_137 :
F_59 ( V_2 , & V_126 -> V_139 , V_126 -> V_78 . V_138 ) ;
break;
case V_141 :
F_61 ( V_2 , & V_126 -> V_223 , V_126 -> V_78 . V_142 ) ;
break;
case V_117 :
break;
default:
break;
}
return V_90 ;
}
static int F_89 ( struct V_1 * V_2 , void * V_104 , int V_27 )
{
struct V_77 V_78 ;
F_18 ( V_2 , - V_27 ) ;
V_78 . V_87 = F_1 ( V_2 , V_47 ) & F_11 ( V_2 ) ;
V_78 . V_51 = V_44 ;
return F_73 ( V_2 , V_78 , V_104 , V_27 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_117 ;
return F_89 ( V_2 , & V_2 -> V_22 . V_34 , V_2 -> V_93 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
void * V_32 , int V_224 )
{
int V_91 ;
struct V_77 V_78 ;
V_78 . V_87 = F_1 ( V_2 , V_47 ) & F_11 ( V_2 ) ;
V_78 . V_51 = V_44 ;
V_91 = F_72 ( V_2 , V_78 , V_32 , V_224 ) ;
if ( V_91 != V_90 )
return V_91 ;
F_18 ( V_2 , V_224 ) ;
return V_91 ;
}
static int F_92 ( struct V_1 * V_2 )
{
return F_91 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_93 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
void * V_32 , int V_224 )
{
int V_91 ;
unsigned long V_34 , V_225 ;
int V_226 = ( V_2 -> V_188 & V_227 ) >> V_228 ;
int V_200 = V_2 -> V_6 -> V_200 ( V_2 ) ;
V_91 = F_91 ( V_2 , & V_34 , V_224 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_225 = V_229 | V_230 | V_231 |
V_232 | V_233 | V_234 |
V_235 | V_189 | V_236 |
V_237 | V_238 ;
switch( V_2 -> V_41 ) {
case V_42 :
case V_102 :
case V_96 :
if ( V_200 == 0 )
V_225 |= V_227 ;
if ( V_200 <= V_226 )
V_225 |= V_124 ;
break;
case V_214 :
if ( V_226 < 3 )
return F_25 ( V_2 , 0 ) ;
V_225 |= V_124 ;
break;
default:
V_225 |= ( V_227 | V_124 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_188 & ~ V_225 ) | ( V_34 & V_225 ) ;
return V_91 ;
}
static int F_94 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_143 ;
V_2 -> V_25 . V_78 . V_9 = & V_2 -> V_188 ;
V_2 -> V_25 . V_27 = V_2 -> V_93 ;
return F_93 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_93 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned V_239 = V_2 -> V_22 . V_34 ;
unsigned V_240 = V_2 -> V_241 . V_34 & 31 ;
T_1 V_242 ;
if ( V_240 )
return V_219 ;
V_242 = F_1 ( V_2 , V_147 ) ;
V_91 = F_89 ( V_2 , & V_242 , F_12 ( V_2 ) ) ;
if ( V_91 != V_90 )
return V_91 ;
F_8 ( F_3 ( V_2 , V_147 ) , F_1 ( V_2 , V_47 ) ,
F_11 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_47 ) ,
F_1 ( V_2 , V_47 ) - V_239 ,
F_11 ( V_2 ) ) ;
return V_90 ;
}
static int F_96 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_47 ) , F_1 ( V_2 , V_147 ) ,
F_11 ( V_2 ) ) ;
return F_91 ( V_2 , F_3 ( V_2 , V_147 ) , V_2 -> V_93 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_51 = V_2 -> V_241 . V_34 ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_51 ) ;
if ( V_2 -> V_93 == 4 ) {
F_18 ( V_2 , - 2 ) ;
V_2 -> V_93 = 2 ;
}
return F_90 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_51 = V_2 -> V_241 . V_34 ;
unsigned long V_69 ;
int V_91 ;
V_91 = F_91 ( V_2 , & V_69 , 2 ) ;
if ( V_91 != V_90 )
return V_91 ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_243 = V_244 ;
if ( V_2 -> V_93 > 2 )
F_18 ( V_2 , V_2 -> V_93 - 2 ) ;
V_91 = F_86 ( V_2 , ( V_36 ) V_69 , V_51 ) ;
return V_91 ;
}
static int F_99 ( struct V_1 * V_2 )
{
unsigned long V_245 = F_1 ( V_2 , V_47 ) ;
int V_91 = V_90 ;
int V_9 = V_246 ;
while ( V_9 <= V_163 ) {
( V_9 == V_47 ) ?
( V_2 -> V_22 . V_34 = V_245 ) : ( V_2 -> V_22 . V_34 = F_1 ( V_2 , V_9 ) ) ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
++ V_9 ;
}
return V_91 ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_188 & ~ V_247 ;
return F_90 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_91 = V_90 ;
int V_9 = V_163 ;
V_37 V_34 ;
while ( V_9 >= V_246 ) {
if ( V_9 == V_47 ) {
F_18 ( V_2 , V_2 -> V_93 ) ;
-- V_9 ;
}
V_91 = F_91 ( V_2 , & V_34 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
break;
F_9 ( F_3 ( V_2 , V_9 ) , V_34 , V_2 -> V_93 ) ;
-- V_9 ;
}
return V_91 ;
}
static int F_102 ( struct V_1 * V_2 , int V_248 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
int V_91 ;
struct V_192 V_193 ;
T_5 V_249 ;
T_5 V_250 ;
V_36 V_251 , V_31 ;
V_2 -> V_22 . V_34 = V_2 -> V_188 ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_188 &= ~ ( V_124 | V_235 | V_237 ) ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_92 ) ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_22 . V_34 = V_2 -> V_94 ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_6 -> V_194 ( V_2 , & V_193 ) ;
V_250 = V_193 . V_116 + ( V_248 << 2 ) ;
V_249 = V_193 . V_116 + ( V_248 << 2 ) + 2 ;
V_91 = V_6 -> V_105 ( V_2 , V_249 , & V_251 , 2 , & V_2 -> V_56 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = V_6 -> V_105 ( V_2 , V_250 , & V_31 , 2 , & V_2 -> V_56 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_86 ( V_2 , V_251 , V_92 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_94 = V_31 ;
return V_91 ;
}
int F_103 ( struct V_1 * V_2 , int V_248 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_91 = F_102 ( V_2 , V_248 ) ;
if ( V_91 == V_90 )
F_4 ( V_2 ) ;
return V_91 ;
}
static int F_104 ( struct V_1 * V_2 , int V_248 )
{
switch( V_2 -> V_41 ) {
case V_89 :
return F_102 ( V_2 , V_248 ) ;
case V_214 :
case V_96 :
case V_102 :
case V_42 :
default:
return V_219 ;
}
}
static int F_105 ( struct V_1 * V_2 )
{
int V_91 = V_90 ;
unsigned long V_252 = 0 ;
unsigned long V_253 = 0 ;
unsigned long V_251 = 0 ;
unsigned long V_33 = V_229 | V_230 | V_231 |
V_232 | V_233 | V_235 |
V_124 | V_189 | V_234 |
V_227 | V_236 | V_254 |
V_237 | V_238 |
V_255 ;
unsigned long V_256 = V_247 | V_257 |
V_258 ;
V_91 = F_91 ( V_2 , & V_252 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
if ( V_252 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_91 = F_91 ( V_2 , & V_251 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_91 ( V_2 , & V_253 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_86 ( V_2 , ( V_36 ) V_251 , V_92 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_94 = V_252 ;
if ( V_2 -> V_93 == 4 )
V_2 -> V_188 = ( ( V_253 & V_33 ) | ( V_2 -> V_188 & V_256 ) ) ;
else if ( V_2 -> V_93 == 2 ) {
V_2 -> V_188 &= ~ 0xffff ;
V_2 -> V_188 |= V_253 ;
}
V_2 -> V_188 &= ~ V_259 ;
V_2 -> V_188 |= V_255 ;
V_2 -> V_6 -> V_260 ( V_2 , false ) ;
return V_91 ;
}
static int F_106 ( struct V_1 * V_2 )
{
switch( V_2 -> V_41 ) {
case V_89 :
return F_105 ( V_2 ) ;
case V_214 :
case V_96 :
case V_102 :
case V_42 :
default:
return V_219 ;
}
}
static int F_107 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned short V_38 , V_261 ;
struct V_39 V_204 , V_262 ;
const struct V_195 * V_6 = V_2 -> V_6 ;
V_35 V_200 = V_2 -> V_6 -> V_200 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 )
V_6 -> V_43 ( V_2 , & V_261 , & V_204 , NULL ,
V_92 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_93 , 2 ) ;
V_91 = F_83 ( V_2 , V_38 , V_92 , V_200 ,
V_218 ,
& V_262 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_262 ) ;
if ( V_91 != V_90 ) {
F_23 ( V_2 -> V_41 != V_42 ) ;
V_6 -> V_72 ( V_2 , V_261 , & V_204 , 0 , V_92 ) ;
return V_91 ;
}
return V_91 ;
}
static int F_108 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
int V_91 ;
long int V_264 ;
V_264 = V_2 -> V_94 ;
V_91 = F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_22 . V_34 = V_264 ;
V_91 = F_90 ( V_2 ) ;
return V_91 ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_2 V_265 = V_2 -> V_25 . V_266 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_219 ;
if ( ( ( V_37 ) ( V_265 >> 0 ) != ( V_37 ) F_1 ( V_2 , V_246 ) ) ||
( ( V_37 ) ( V_265 >> 32 ) != ( V_37 ) F_1 ( V_2 , V_267 ) ) ) {
* F_2 ( V_2 , V_246 ) = ( V_37 ) ( V_265 >> 0 ) ;
* F_2 ( V_2 , V_267 ) = ( V_37 ) ( V_265 >> 32 ) ;
V_2 -> V_188 &= ~ V_232 ;
} else {
V_2 -> V_25 . V_23 = ( ( T_2 ) F_1 ( V_2 , V_187 ) << 32 ) |
( V_37 ) F_1 ( V_2 , V_158 ) ;
V_2 -> V_188 |= V_232 ;
}
return V_90 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_31 ;
V_91 = F_91 ( V_2 , & V_31 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
return F_40 ( V_2 , V_31 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_31 , V_251 ;
V_36 V_268 ;
int V_200 = V_2 -> V_6 -> V_200 ( V_2 ) ;
struct V_39 V_204 , V_262 ;
const struct V_195 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_41 == V_42 )
V_6 -> V_43 ( V_2 , & V_268 , & V_204 , NULL ,
V_92 ) ;
V_91 = F_91 ( V_2 , & V_31 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_91 ( V_2 , & V_251 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
if ( V_2 -> V_41 >= V_96 && ( V_251 & 3 ) > V_200 )
return V_219 ;
V_91 = F_83 ( V_2 , ( V_36 ) V_251 , V_92 , V_200 ,
V_269 ,
& V_262 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_41 ( V_2 , V_31 , & V_262 ) ;
if ( V_91 != V_90 ) {
F_23 ( V_2 -> V_41 != V_42 ) ;
V_6 -> V_72 ( V_2 , V_268 , & V_204 , 0 , V_92 ) ;
}
return V_91 ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = F_112 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_90 ;
}
static int F_114 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_145 = V_2 -> V_25 . V_34 ;
V_2 -> V_25 . V_34 = F_1 ( V_2 , V_246 ) ;
V_2 -> V_22 . V_145 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_145 ;
F_52 ( V_2 , V_270 ) ;
if ( V_2 -> V_188 & V_232 ) {
V_2 -> V_22 . type = V_117 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_145 ;
} else {
V_2 -> V_22 . type = V_143 ;
V_2 -> V_22 . V_78 . V_9 = F_3 ( V_2 , V_246 ) ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_145 ;
V_2 -> V_25 . V_34 = V_2 -> V_25 . V_145 ;
}
return V_90 ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_51 = V_2 -> V_241 . V_34 ;
unsigned short V_38 ;
int V_91 ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_93 , 2 ) ;
V_91 = F_86 ( V_2 , V_38 , V_51 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
return V_91 ;
}
static void
F_116 ( struct V_1 * V_2 ,
struct V_39 * V_251 , struct V_39 * V_40 )
{
V_251 -> V_97 = 0 ;
F_84 ( V_251 , 0 ) ;
V_251 -> V_50 = 1 ;
F_85 ( V_251 , 0xfffff ) ;
V_251 -> type = 0x0b ;
V_251 -> V_215 = 1 ;
V_251 -> V_205 = 0 ;
V_251 -> V_113 = 1 ;
V_251 -> V_45 = 1 ;
V_251 -> V_271 = 0 ;
F_84 ( V_40 , 0 ) ;
F_85 ( V_40 , 0xfffff ) ;
V_40 -> V_50 = 1 ;
V_40 -> V_215 = 1 ;
V_40 -> type = 0x03 ;
V_40 -> V_45 = 1 ;
V_40 -> V_205 = 0 ;
V_40 -> V_113 = 1 ;
V_40 -> V_97 = 0 ;
V_40 -> V_271 = 0 ;
}
static bool F_117 ( struct V_1 * V_2 )
{
V_37 V_272 , V_273 , V_274 , V_275 ;
V_272 = V_274 = 0 ;
V_2 -> V_6 -> V_276 ( V_2 , & V_272 , & V_273 , & V_274 , & V_275 ) ;
return V_273 == V_277
&& V_274 == V_278
&& V_275 == V_279 ;
}
static bool F_118 ( struct V_1 * V_2 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
V_37 V_272 , V_273 , V_274 , V_275 ;
if ( V_2 -> V_41 == V_42 )
return true ;
V_272 = 0x00000000 ;
V_274 = 0x00000000 ;
V_6 -> V_276 ( V_2 , & V_272 , & V_273 , & V_274 , & V_275 ) ;
if ( V_273 == V_277 &&
V_274 == V_278 &&
V_275 == V_279 )
return false ;
if ( V_273 == V_280 &&
V_274 == V_281 &&
V_275 == V_282 )
return true ;
if ( V_273 == V_283 &&
V_274 == V_284 &&
V_275 == V_285 )
return true ;
return false ;
}
static int F_119 ( struct V_1 * V_2 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_39 V_251 , V_40 ;
T_2 V_286 ;
V_36 V_287 , V_288 ;
T_2 V_98 = 0 ;
if ( V_2 -> V_41 == V_89 ||
V_2 -> V_41 == V_214 )
return F_27 ( V_2 ) ;
if ( ! ( F_118 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
F_116 ( V_2 , & V_251 , & V_40 ) ;
if ( ! ( V_98 & V_289 ) )
return F_27 ( V_2 ) ;
V_6 -> V_99 ( V_2 , V_290 , & V_286 ) ;
V_286 >>= 32 ;
V_287 = ( V_36 ) ( V_286 & 0xfffc ) ;
V_288 = ( V_36 ) ( V_286 + 8 ) ;
if ( V_98 & V_101 ) {
V_251 . V_45 = 0 ;
V_251 . V_97 = 1 ;
}
V_6 -> V_72 ( V_2 , V_287 , & V_251 , 0 , V_92 ) ;
V_6 -> V_72 ( V_2 , V_288 , & V_40 , 0 , V_44 ) ;
* F_2 ( V_2 , V_187 ) = V_2 -> V_94 ;
if ( V_98 & V_101 ) {
#ifdef F_42
* F_2 ( V_2 , V_291 ) = V_2 -> V_188 ;
V_6 -> V_99 ( V_2 ,
V_2 -> V_41 == V_42 ?
V_292 : V_293 , & V_286 ) ;
V_2 -> V_94 = V_286 ;
V_6 -> V_99 ( V_2 , V_294 , & V_286 ) ;
V_2 -> V_188 &= ~ V_286 ;
V_2 -> V_188 |= V_255 ;
#endif
} else {
V_6 -> V_99 ( V_2 , V_290 , & V_286 ) ;
V_2 -> V_94 = ( V_37 ) V_286 ;
V_2 -> V_188 &= ~ ( V_247 | V_124 ) ;
}
return V_90 ;
}
static int F_120 ( struct V_1 * V_2 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_39 V_251 , V_40 ;
T_2 V_286 ;
V_36 V_287 , V_288 ;
T_2 V_98 = 0 ;
V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( V_2 -> V_41 == V_89 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_41 != V_42 ) && ( V_98 & V_101 )
&& ! F_117 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 )
return V_219 ;
F_116 ( V_2 , & V_251 , & V_40 ) ;
V_6 -> V_99 ( V_2 , V_295 , & V_286 ) ;
if ( ( V_286 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_188 &= ~ ( V_247 | V_124 ) ;
V_287 = ( V_36 ) V_286 & ~ V_296 ;
V_288 = V_287 + 8 ;
if ( V_98 & V_101 ) {
V_251 . V_45 = 0 ;
V_251 . V_97 = 1 ;
}
V_6 -> V_72 ( V_2 , V_287 , & V_251 , 0 , V_92 ) ;
V_6 -> V_72 ( V_2 , V_288 , & V_40 , 0 , V_44 ) ;
V_6 -> V_99 ( V_2 , V_297 , & V_286 ) ;
V_2 -> V_94 = ( V_98 & V_101 ) ? V_286 : ( V_37 ) V_286 ;
V_6 -> V_99 ( V_2 , V_298 , & V_286 ) ;
* F_2 ( V_2 , V_47 ) = ( V_98 & V_101 ) ? V_286 :
( V_37 ) V_286 ;
return V_90 ;
}
static int F_121 ( struct V_1 * V_2 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_39 V_251 , V_40 ;
T_2 V_286 , V_299 , V_300 ;
int V_301 ;
V_36 V_287 = 0 , V_288 = 0 ;
if ( V_2 -> V_41 == V_89 ||
V_2 -> V_41 == V_214 )
return F_25 ( V_2 , 0 ) ;
F_116 ( V_2 , & V_251 , & V_40 ) ;
if ( ( V_2 -> V_115 & 0x8 ) != 0x0 )
V_301 = V_42 ;
else
V_301 = V_102 ;
V_299 = F_1 ( V_2 , V_187 ) ;
V_300 = F_1 ( V_2 , V_267 ) ;
V_251 . V_205 = 3 ;
V_40 . V_205 = 3 ;
V_6 -> V_99 ( V_2 , V_295 , & V_286 ) ;
switch ( V_301 ) {
case V_102 :
V_287 = ( V_36 ) ( V_286 + 16 ) ;
if ( ( V_286 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_288 = ( V_36 ) ( V_286 + 24 ) ;
V_299 = ( V_37 ) V_299 ;
V_300 = ( V_37 ) V_300 ;
break;
case V_42 :
V_287 = ( V_36 ) ( V_286 + 32 ) ;
if ( V_286 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_288 = V_287 + 8 ;
V_251 . V_45 = 0 ;
V_251 . V_97 = 1 ;
if ( F_36 ( V_299 ) ||
F_36 ( V_300 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
V_287 |= V_296 ;
V_288 |= V_296 ;
V_6 -> V_72 ( V_2 , V_287 , & V_251 , 0 , V_92 ) ;
V_6 -> V_72 ( V_2 , V_288 , & V_40 , 0 , V_44 ) ;
V_2 -> V_94 = V_300 ;
* F_2 ( V_2 , V_47 ) = V_299 ;
return V_90 ;
}
static bool F_122 ( struct V_1 * V_2 )
{
int V_226 ;
if ( V_2 -> V_41 == V_89 )
return false ;
if ( V_2 -> V_41 == V_214 )
return true ;
V_226 = ( V_2 -> V_188 & V_227 ) >> V_228 ;
return V_2 -> V_6 -> V_200 ( V_2 ) > V_226 ;
}
static bool F_123 ( struct V_1 * V_2 ,
V_36 V_182 , V_36 V_224 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_39 V_302 ;
V_37 V_71 ;
int V_303 ;
V_36 V_304 , V_305 , V_306 , V_307 = V_182 & 0x7 ;
unsigned V_33 = ( 1 << V_224 ) - 1 ;
unsigned long V_308 ;
V_6 -> V_43 ( V_2 , & V_304 , & V_302 , & V_71 , V_216 ) ;
if ( ! V_302 . V_113 )
return false ;
if ( F_19 ( & V_302 ) < 103 )
return false ;
V_308 = F_79 ( & V_302 ) ;
#ifdef F_42
V_308 |= ( ( T_2 ) V_71 ) << 32 ;
#endif
V_303 = V_6 -> V_105 ( V_2 , V_308 + 102 , & V_305 , 2 , NULL ) ;
if ( V_303 != V_90 )
return false ;
if ( V_305 + V_182 / 8 > F_19 ( & V_302 ) )
return false ;
V_303 = V_6 -> V_105 ( V_2 , V_308 + V_305 + V_182 / 8 , & V_306 , 2 , NULL ) ;
if ( V_303 != V_90 )
return false ;
if ( ( V_306 >> V_307 ) & V_33 )
return false ;
return true ;
}
static bool F_124 ( struct V_1 * V_2 ,
V_36 V_182 , V_36 V_224 )
{
if ( V_2 -> V_309 )
return true ;
if ( F_122 ( V_2 ) )
if ( ! F_123 ( V_2 , V_182 , V_224 ) )
return false ;
V_2 -> V_309 = true ;
return true ;
}
static void F_125 ( struct V_1 * V_2 ,
struct V_310 * V_311 )
{
V_311 -> V_312 = V_2 -> V_94 ;
V_311 -> V_313 = V_2 -> V_188 ;
V_311 -> V_314 = F_1 ( V_2 , V_246 ) ;
V_311 -> V_315 = F_1 ( V_2 , V_187 ) ;
V_311 -> V_316 = F_1 ( V_2 , V_267 ) ;
V_311 -> V_157 = F_1 ( V_2 , V_158 ) ;
V_311 -> V_317 = F_1 ( V_2 , V_47 ) ;
V_311 -> V_159 = F_1 ( V_2 , V_147 ) ;
V_311 -> V_160 = F_1 ( V_2 , V_161 ) ;
V_311 -> V_162 = F_1 ( V_2 , V_163 ) ;
V_311 -> V_318 = F_31 ( V_2 , V_319 ) ;
V_311 -> V_251 = F_31 ( V_2 , V_92 ) ;
V_311 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_311 -> V_320 = F_31 ( V_2 , V_154 ) ;
V_311 -> V_321 = F_31 ( V_2 , V_196 ) ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_310 * V_311 )
{
int V_211 ;
V_35 V_200 ;
V_2 -> V_94 = V_311 -> V_312 ;
V_2 -> V_188 = V_311 -> V_313 | 2 ;
* F_2 ( V_2 , V_246 ) = V_311 -> V_314 ;
* F_2 ( V_2 , V_187 ) = V_311 -> V_315 ;
* F_2 ( V_2 , V_267 ) = V_311 -> V_316 ;
* F_2 ( V_2 , V_158 ) = V_311 -> V_157 ;
* F_2 ( V_2 , V_47 ) = V_311 -> V_317 ;
* F_2 ( V_2 , V_147 ) = V_311 -> V_159 ;
* F_2 ( V_2 , V_161 ) = V_311 -> V_160 ;
* F_2 ( V_2 , V_163 ) = V_311 -> V_162 ;
F_32 ( V_2 , V_311 -> V_321 , V_196 ) ;
F_32 ( V_2 , V_311 -> V_318 , V_319 ) ;
F_32 ( V_2 , V_311 -> V_251 , V_92 ) ;
F_32 ( V_2 , V_311 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_311 -> V_320 , V_154 ) ;
V_200 = V_311 -> V_251 & 3 ;
V_211 = F_83 ( V_2 , V_311 -> V_321 , V_196 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_318 , V_319 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_251 , V_92 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_40 , V_44 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_320 , V_154 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
return V_90 ;
}
static int F_127 ( struct V_1 * V_2 ,
V_36 V_322 , V_36 V_323 ,
T_1 V_324 , struct V_39 * V_262 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_310 V_325 ;
int V_211 ;
V_37 V_326 = F_79 ( V_262 ) ;
V_211 = V_6 -> V_105 ( V_2 , V_324 , & V_325 , sizeof V_325 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
F_125 ( V_2 , & V_325 ) ;
V_211 = V_6 -> V_199 ( V_2 , V_324 , & V_325 , sizeof V_325 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = V_6 -> V_105 ( V_2 , V_326 , & V_325 , sizeof V_325 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
if ( V_323 != 0xffff ) {
V_325 . V_327 = V_323 ;
V_211 = V_6 -> V_199 ( V_2 , V_326 ,
& V_325 . V_327 ,
sizeof V_325 . V_327 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
}
return F_126 ( V_2 , & V_325 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_328 * V_311 )
{
V_311 -> V_31 = V_2 -> V_94 ;
V_311 -> V_188 = V_2 -> V_188 ;
V_311 -> V_272 = F_1 ( V_2 , V_246 ) ;
V_311 -> V_274 = F_1 ( V_2 , V_187 ) ;
V_311 -> V_275 = F_1 ( V_2 , V_267 ) ;
V_311 -> V_273 = F_1 ( V_2 , V_158 ) ;
V_311 -> V_329 = F_1 ( V_2 , V_47 ) ;
V_311 -> V_330 = F_1 ( V_2 , V_147 ) ;
V_311 -> V_331 = F_1 ( V_2 , V_161 ) ;
V_311 -> V_332 = F_1 ( V_2 , V_163 ) ;
V_311 -> V_318 = F_31 ( V_2 , V_319 ) ;
V_311 -> V_251 = F_31 ( V_2 , V_92 ) ;
V_311 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_311 -> V_320 = F_31 ( V_2 , V_154 ) ;
V_311 -> V_333 = F_31 ( V_2 , V_52 ) ;
V_311 -> V_334 = F_31 ( V_2 , V_213 ) ;
}
static int F_129 ( struct V_1 * V_2 ,
struct V_328 * V_311 )
{
int V_211 ;
V_35 V_200 ;
if ( V_2 -> V_6 -> V_335 ( V_2 , 3 , V_311 -> V_336 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_94 = V_311 -> V_31 ;
V_2 -> V_188 = V_311 -> V_188 | 2 ;
* F_2 ( V_2 , V_246 ) = V_311 -> V_272 ;
* F_2 ( V_2 , V_187 ) = V_311 -> V_274 ;
* F_2 ( V_2 , V_267 ) = V_311 -> V_275 ;
* F_2 ( V_2 , V_158 ) = V_311 -> V_273 ;
* F_2 ( V_2 , V_47 ) = V_311 -> V_329 ;
* F_2 ( V_2 , V_147 ) = V_311 -> V_330 ;
* F_2 ( V_2 , V_161 ) = V_311 -> V_331 ;
* F_2 ( V_2 , V_163 ) = V_311 -> V_332 ;
F_32 ( V_2 , V_311 -> V_337 , V_196 ) ;
F_32 ( V_2 , V_311 -> V_318 , V_319 ) ;
F_32 ( V_2 , V_311 -> V_251 , V_92 ) ;
F_32 ( V_2 , V_311 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_311 -> V_320 , V_154 ) ;
F_32 ( V_2 , V_311 -> V_333 , V_52 ) ;
F_32 ( V_2 , V_311 -> V_334 , V_213 ) ;
if ( V_2 -> V_188 & V_247 ) {
V_2 -> V_41 = V_214 ;
V_200 = 3 ;
} else {
V_2 -> V_41 = V_102 ;
V_200 = V_311 -> V_251 & 3 ;
}
V_211 = F_83 ( V_2 , V_311 -> V_337 , V_196 ,
V_200 , V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_318 , V_319 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_251 , V_92 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_40 , V_44 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_320 , V_154 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_333 , V_52 , V_200 ,
V_217 , NULL ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_83 ( V_2 , V_311 -> V_334 , V_213 , V_200 ,
V_217 , NULL ) ;
return V_211 ;
}
static int F_130 ( struct V_1 * V_2 ,
V_36 V_322 , V_36 V_323 ,
T_1 V_324 , struct V_39 * V_262 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_328 V_325 ;
int V_211 ;
V_37 V_326 = F_79 ( V_262 ) ;
V_37 V_338 = F_131 ( struct V_328 , V_31 ) ;
V_37 V_339 = F_131 ( struct V_328 , V_337 ) ;
V_211 = V_6 -> V_105 ( V_2 , V_324 , & V_325 , sizeof V_325 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
F_128 ( V_2 , & V_325 ) ;
V_211 = V_6 -> V_199 ( V_2 , V_324 + V_338 , & V_325 . V_31 ,
V_339 - V_338 , & V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = V_6 -> V_105 ( V_2 , V_326 , & V_325 , sizeof V_325 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
if ( V_323 != 0xffff ) {
V_325 . V_327 = V_323 ;
V_211 = V_6 -> V_199 ( V_2 , V_326 ,
& V_325 . V_327 ,
sizeof V_325 . V_327 ,
& V_2 -> V_56 ) ;
if ( V_211 != V_90 )
return V_211 ;
}
return F_129 ( V_2 , & V_325 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
V_36 V_322 , int V_340 , int V_341 ,
bool V_342 , V_37 V_58 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
struct V_39 V_343 , V_344 ;
int V_211 ;
V_36 V_323 = F_31 ( V_2 , V_216 ) ;
T_1 V_324 =
V_6 -> V_53 ( V_2 , V_216 ) ;
V_37 V_345 ;
T_1 V_210 ;
V_211 = F_81 ( V_2 , V_322 , & V_344 , & V_210 ) ;
if ( V_211 != V_90 )
return V_211 ;
V_211 = F_81 ( V_2 , V_323 , & V_343 , & V_210 ) ;
if ( V_211 != V_90 )
return V_211 ;
if ( V_341 == V_346 ) {
if ( V_340 != - 1 ) {
struct V_39 V_347 ;
int V_205 ;
V_211 = F_77 ( V_2 , V_340 ,
& V_347 ) ;
if ( V_211 != V_90 )
return V_211 ;
V_205 = V_347 . V_205 ;
if ( ( V_322 & 3 ) > V_205 || V_6 -> V_200 ( V_2 ) > V_205 )
return F_25 ( V_2 , ( V_340 << 3 ) | 0x2 ) ;
}
}
V_345 = F_19 ( & V_344 ) ;
if ( ! V_344 . V_113 ||
( ( V_345 < 0x67 && ( V_344 . type & 8 ) ) ||
V_345 < 0x2b ) ) {
return F_28 ( V_2 , V_322 & 0xfffc ) ;
}
if ( V_341 == V_348 || V_341 == V_349 ) {
V_343 . type &= ~ ( 1 << 1 ) ;
F_82 ( V_2 , V_323 , & V_343 ) ;
}
if ( V_341 == V_348 )
V_2 -> V_188 = V_2 -> V_188 & ~ V_236 ;
if ( V_341 != V_350 && V_341 != V_346 )
V_323 = 0xffff ;
if ( V_344 . type & 8 )
V_211 = F_130 ( V_2 , V_322 , V_323 ,
V_324 , & V_344 ) ;
else
V_211 = F_127 ( V_2 , V_322 , V_323 ,
V_324 , & V_344 ) ;
if ( V_211 != V_90 )
return V_211 ;
if ( V_341 == V_350 || V_341 == V_346 )
V_2 -> V_188 = V_2 -> V_188 | V_236 ;
if ( V_341 != V_348 ) {
V_344 . type |= ( 1 << 1 ) ;
F_82 ( V_2 , V_322 , & V_344 ) ;
}
V_6 -> V_335 ( V_2 , 0 , V_6 -> V_129 ( V_2 , 0 ) | V_130 ) ;
V_6 -> V_72 ( V_2 , V_322 , & V_344 , 0 , V_216 ) ;
if ( V_342 ) {
V_2 -> V_93 = V_2 -> V_29 = ( V_344 . type & 8 ) ? 4 : 2 ;
V_2 -> V_222 = 0 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_58 ;
V_211 = F_90 ( V_2 ) ;
}
return V_211 ;
}
int F_133 ( struct V_1 * V_2 ,
V_36 V_322 , int V_340 , int V_341 ,
bool V_342 , V_37 V_58 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_2 -> V_94 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_117 ;
V_91 = F_132 ( V_2 , V_322 , V_340 , V_341 ,
V_342 , V_58 ) ;
if ( V_91 == V_90 ) {
V_2 -> V_31 = V_2 -> V_94 ;
F_4 ( V_2 ) ;
}
return ( V_91 == V_219 ) ? V_351 : V_352 ;
}
static void F_134 ( struct V_1 * V_2 , int V_9 ,
struct V_125 * V_126 )
{
int V_353 = ( V_2 -> V_188 & V_189 ) ? - V_126 -> V_186 : V_126 -> V_186 ;
F_17 ( V_2 , V_9 , V_353 * V_126 -> V_27 ) ;
V_126 -> V_78 . V_168 . V_87 = F_15 ( V_2 , V_9 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
V_35 V_354 , V_355 ;
bool V_356 , V_357 , V_358 ;
V_357 = V_2 -> V_188 & V_229 ;
V_354 = V_2 -> V_25 . V_34 ;
V_355 = V_354 ;
V_358 = V_357 ;
V_357 = false ;
V_356 = V_2 -> V_188 & V_231 ;
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
V_2 -> V_25 . V_34 = V_354 ;
V_2 -> V_22 . type = V_359 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_360 ) ;
V_2 -> V_188 &= ~ ( V_231 | V_229 ) ;
if ( V_357 )
V_2 -> V_188 |= V_229 ;
if ( V_356 )
V_2 -> V_188 |= V_231 ;
return V_90 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_35 V_354 , V_361 ;
if ( V_2 -> V_22 . V_34 == 0 )
return F_29 ( V_2 ) ;
V_354 = V_2 -> V_25 . V_34 & 0xff ;
V_361 = V_354 / V_2 -> V_22 . V_34 ;
V_354 %= V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_354 | ( V_361 << 8 ) ;
V_2 -> V_22 . type = V_359 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_360 ) ;
return V_90 ;
}
static int F_137 ( struct V_1 * V_2 )
{
V_35 V_354 = V_2 -> V_25 . V_34 & 0xff ;
V_35 V_361 = ( V_2 -> V_25 . V_34 >> 8 ) & 0xff ;
V_354 = ( V_354 + ( V_361 * V_2 -> V_22 . V_34 ) ) & 0xff ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_354 ;
V_2 -> V_22 . type = V_359 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_52 ( V_2 , V_360 ) ;
return V_90 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_91 ;
long V_103 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_94 ;
V_91 = F_43 ( V_2 , V_103 ) ;
if ( V_91 != V_90 )
return V_91 ;
return F_90 ( V_2 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_36 V_38 , V_268 ;
T_1 V_264 ;
int V_91 ;
struct V_39 V_204 , V_262 ;
const struct V_195 * V_6 = V_2 -> V_6 ;
int V_200 = V_2 -> V_6 -> V_200 ( V_2 ) ;
enum V_82 V_362 = V_2 -> V_41 ;
V_264 = V_2 -> V_94 ;
V_6 -> V_43 ( V_2 , & V_268 , & V_204 , NULL , V_92 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_263 + V_2 -> V_93 , 2 ) ;
V_91 = F_83 ( V_2 , V_38 , V_92 , V_200 ,
V_218 , & V_262 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_262 ) ;
if ( V_91 != V_90 )
goto V_363;
V_2 -> V_22 . V_34 = V_268 ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 )
goto V_363;
V_2 -> V_22 . V_34 = V_264 ;
V_91 = F_90 ( V_2 ) ;
if ( V_91 != V_90 ) {
F_140 ( L_1 ) ;
goto V_363;
}
return V_91 ;
V_363:
V_6 -> V_72 ( V_2 , V_268 , & V_204 , 0 , V_92 ) ;
V_2 -> V_41 = V_362 ;
return V_91 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_31 ;
V_91 = F_91 ( V_2 , & V_31 , V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_91 = F_40 ( V_2 , V_31 ) ;
if ( V_91 != V_90 )
return V_91 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_90 ;
}
static int F_142 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_34 ;
F_87 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_145 ;
V_2 -> V_222 = 1 ;
return V_90 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = V_2 -> V_241 . V_34 ;
return F_52 ( V_2 , V_364 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_143 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_78 . V_9 = F_3 ( V_2 , V_267 ) ;
V_2 -> V_25 . V_34 = ~ ( ( V_2 -> V_22 . V_34 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_90 ;
}
static int F_145 ( struct V_1 * V_2 )
{
T_2 V_365 = 0 ;
V_2 -> V_6 -> V_99 ( V_2 , V_366 , & V_365 ) ;
* F_2 ( V_2 , V_246 ) = ( V_37 ) V_365 ;
* F_2 ( V_2 , V_267 ) = V_365 >> 32 ;
return V_90 ;
}
static int F_146 ( struct V_1 * V_2 )
{
T_2 V_367 ;
if ( V_2 -> V_6 -> V_368 ( V_2 , F_1 ( V_2 , V_187 ) , & V_367 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_246 ) = ( V_37 ) V_367 ;
* F_2 ( V_2 , V_267 ) = V_367 >> 32 ;
return V_90 ;
}
static int F_147 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_263 , V_2 -> V_22 . V_263 , sizeof( V_2 -> V_22 . V_263 ) ) ;
return V_90 ;
}
static int F_148 ( struct V_1 * V_2 )
{
V_37 V_273 , V_274 , V_275 , V_272 = 1 ;
V_36 V_369 ;
V_2 -> V_6 -> V_276 ( V_2 , & V_272 , & V_273 , & V_274 , & V_275 ) ;
if ( ! ( V_274 & F_149 ( V_370 ) ) )
return F_27 ( V_2 ) ;
switch ( V_2 -> V_93 ) {
case 2 :
V_369 = ( V_36 ) V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 &= ~ 0xffffUL ;
V_2 -> V_25 . V_34 |= ( unsigned long ) F_150 ( V_369 ) ;
break;
case 4 :
V_2 -> V_25 . V_34 = F_151 ( ( V_37 ) V_2 -> V_22 . V_34 ) ;
break;
case 8 :
V_2 -> V_25 . V_34 = F_152 ( V_2 -> V_22 . V_34 ) ;
break;
default:
F_58 () ;
}
return V_90 ;
}
static int F_153 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_335 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_34 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_154 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
if ( V_2 -> V_41 == V_42 )
V_34 = V_2 -> V_22 . V_34 & ~ 0ULL ;
else
V_34 = V_2 -> V_22 . V_34 & ~ 0U ;
if ( V_2 -> V_6 -> V_371 ( V_2 , V_2 -> V_19 , V_34 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_155 ( struct V_1 * V_2 )
{
T_2 V_286 ;
V_286 = ( V_37 ) F_1 ( V_2 , V_246 )
| ( ( T_2 ) F_1 ( V_2 , V_267 ) << 32 ) ;
if ( V_2 -> V_6 -> V_372 ( V_2 , F_1 ( V_2 , V_187 ) , V_286 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_2 V_286 ;
if ( V_2 -> V_6 -> V_99 ( V_2 , F_1 ( V_2 , V_187 ) , & V_286 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_246 ) = ( V_37 ) V_286 ;
* F_2 ( V_2 , V_267 ) = V_286 >> 32 ;
return V_90 ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_213 )
return F_27 ( V_2 ) ;
V_2 -> V_25 . V_34 = F_31 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_156 )
V_2 -> V_25 . V_27 = 2 ;
return V_90 ;
}
static int F_158 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
if ( V_2 -> V_19 == V_92 || V_2 -> V_19 > V_213 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_243 = V_244 ;
V_2 -> V_25 . type = V_117 ;
return F_86 ( V_2 , V_38 , V_2 -> V_19 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_117 ;
return F_86 ( V_2 , V_38 , V_196 ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_117 ;
return F_86 ( V_2 , V_38 , V_216 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_91 ;
T_1 V_83 ;
V_91 = F_38 ( V_2 , V_2 -> V_22 . V_78 . V_168 , 1 , false , & V_83 ) ;
if ( V_91 == V_90 )
V_2 -> V_6 -> V_373 ( V_2 , V_83 ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_162 ( struct V_1 * V_2 )
{
T_1 V_374 ;
V_374 = V_2 -> V_6 -> V_129 ( V_2 , 0 ) ;
V_374 &= ~ V_130 ;
V_2 -> V_6 -> V_335 ( V_2 , 0 , V_374 ) ;
return V_90 ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_91 = V_2 -> V_6 -> V_375 ( V_2 ) ;
if ( V_91 != V_90 )
return V_91 ;
V_2 -> V_94 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_164 ( struct V_1 * V_2 ,
void (* F_165)( struct V_1 * V_2 ,
struct V_192 * V_111 ) )
{
struct V_192 V_192 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_93 = 8 ;
F_165 ( V_2 , & V_192 ) ;
if ( V_2 -> V_93 == 2 ) {
V_2 -> V_93 = 4 ;
V_192 . V_116 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_117 ;
return F_73 ( V_2 , V_2 -> V_25 . V_78 . V_168 ,
& V_192 , 2 + V_2 -> V_93 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
return F_164 ( V_2 , V_2 -> V_6 -> V_197 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
return F_164 ( V_2 , V_2 -> V_6 -> V_194 ) ;
}
static int F_168 ( struct V_1 * V_2 , bool V_376 )
{
struct V_192 V_192 ;
int V_91 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_93 = 8 ;
V_91 = F_50 ( V_2 , V_2 -> V_22 . V_78 . V_168 ,
& V_192 . V_73 , & V_192 . V_116 ,
V_2 -> V_93 ) ;
if ( V_91 != V_90 )
return V_91 ;
if ( V_2 -> V_41 == V_42 &&
F_36 ( V_192 . V_116 ) )
return F_25 ( V_2 , 0 ) ;
if ( V_376 )
V_2 -> V_6 -> V_377 ( V_2 , & V_192 ) ;
else
V_2 -> V_6 -> V_378 ( V_2 , & V_192 ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_169 ( struct V_1 * V_2 )
{
return F_168 ( V_2 , true ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
return F_168 ( V_2 , false ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_156 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_34 = V_2 -> V_6 -> V_129 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_172 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_335 ( V_2 , 0 , ( V_2 -> V_6 -> V_129 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_34 & 0x0f ) ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_173 ( struct V_1 * V_2 )
{
int V_91 = V_90 ;
F_17 ( V_2 , V_187 , - 1 ) ;
if ( ( F_14 ( V_2 , F_1 ( V_2 , V_187 ) ) != 0 ) &&
( V_2 -> V_135 == 0xe2 || F_54 ( V_2 -> V_135 ^ 0x5 , V_2 -> V_188 ) ) )
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_91 ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_91 = V_90 ;
if ( F_14 ( V_2 , F_1 ( V_2 , V_187 ) ) == 0 )
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_91 ;
}
static int F_175 ( struct V_1 * V_2 )
{
if ( ! F_75 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_34 ,
& V_2 -> V_25 . V_34 ) )
return V_379 ;
return V_90 ;
}
static int F_176 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_380 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_34 ,
& V_2 -> V_22 . V_34 , 1 ) ;
V_2 -> V_25 . type = V_117 ;
return V_90 ;
}
static int F_177 ( struct V_1 * V_2 )
{
if ( F_122 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_188 &= ~ V_124 ;
return V_90 ;
}
static int F_178 ( struct V_1 * V_2 )
{
if ( F_122 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_243 = V_381 ;
V_2 -> V_188 |= V_124 ;
return V_90 ;
}
static int F_179 ( struct V_1 * V_2 )
{
V_37 V_272 , V_273 , V_274 , V_275 ;
V_272 = F_1 ( V_2 , V_246 ) ;
V_274 = F_1 ( V_2 , V_187 ) ;
V_2 -> V_6 -> V_276 ( V_2 , & V_272 , & V_273 , & V_274 , & V_275 ) ;
* F_2 ( V_2 , V_246 ) = V_272 ;
* F_2 ( V_2 , V_158 ) = V_273 ;
* F_2 ( V_2 , V_187 ) = V_274 ;
* F_2 ( V_2 , V_267 ) = V_275 ;
return V_90 ;
}
static int F_180 ( struct V_1 * V_2 )
{
V_37 V_121 ;
V_121 = V_229 | V_230 | V_231 | V_232 |
V_233 ;
V_121 &= * F_3 ( V_2 , V_246 ) >> 8 ;
V_2 -> V_188 &= ~ 0xffUL ;
V_2 -> V_188 |= V_121 | V_255 ;
return V_90 ;
}
static int F_181 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_246 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_246 ) |= ( V_2 -> V_188 & 0xff ) << 8 ;
return V_90 ;
}
static int F_182 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_93 ) {
#ifdef F_42
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_90 ;
}
static int F_183 ( struct V_1 * V_2 )
{
return V_90 ;
}
static int F_184 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = ( V_165 ) V_2 -> V_22 . V_34 ;
return V_90 ;
}
static bool F_185 ( int V_3 )
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
static int F_186 ( struct V_1 * V_2 )
{
if ( ! F_185 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_187 ( struct V_1 * V_2 )
{
T_2 V_382 = V_2 -> V_22 . V_23 ;
int V_383 = V_2 -> V_19 ;
T_2 V_98 = 0 ;
static T_2 V_384 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_385 ,
0 , 0 , 0 ,
V_386 ,
} ;
if ( ! F_185 ( V_383 ) )
return F_27 ( V_2 ) ;
if ( V_382 & V_384 [ V_383 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_383 ) {
case 0 : {
T_2 V_387 ;
if ( ( ( V_382 & V_388 ) && ! ( V_382 & V_389 ) ) ||
( ( V_382 & V_390 ) && ! ( V_382 & V_391 ) ) )
return F_25 ( V_2 , 0 ) ;
V_387 = V_2 -> V_6 -> V_129 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( ( V_382 & V_388 ) && ( V_98 & V_392 ) &&
! ( V_387 & V_393 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
T_2 V_394 = 0 ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( V_98 & V_101 )
V_394 = V_395 & ~ V_396 ;
if ( V_382 & V_394 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( ( V_98 & V_101 ) && ! ( V_382 & V_393 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_90 ;
}
static int F_188 ( struct V_1 * V_2 )
{
unsigned long V_397 ;
V_2 -> V_6 -> V_398 ( V_2 , 7 , & V_397 ) ;
return V_397 & ( 1 << 13 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
int V_399 = V_2 -> V_19 ;
T_2 V_387 ;
if ( V_399 > 7 )
return F_27 ( V_2 ) ;
V_387 = V_2 -> V_6 -> V_129 ( V_2 , 4 ) ;
if ( ( V_387 & V_400 ) && ( V_399 == 4 || V_399 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_188 ( V_2 ) ) {
T_1 V_401 ;
V_2 -> V_6 -> V_398 ( V_2 , 6 , & V_401 ) ;
V_401 &= ~ 15 ;
V_401 |= V_402 | V_403 ;
V_2 -> V_6 -> V_371 ( V_2 , 6 , V_401 ) ;
return F_24 ( V_2 ) ;
}
return V_90 ;
}
static int F_190 ( struct V_1 * V_2 )
{
T_2 V_382 = V_2 -> V_22 . V_23 ;
int V_399 = V_2 -> V_19 ;
if ( ( V_399 == 6 || V_399 == 7 ) && ( V_382 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_189 ( V_2 ) ;
}
static int F_191 ( struct V_1 * V_2 )
{
T_2 V_98 ;
V_2 -> V_6 -> V_99 ( V_2 , V_100 , & V_98 ) ;
if ( ! ( V_98 & V_404 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_192 ( struct V_1 * V_2 )
{
T_2 V_405 = F_1 ( V_2 , V_246 ) ;
if ( V_405 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_191 ( V_2 ) ;
}
static int F_193 ( struct V_1 * V_2 )
{
T_2 V_387 = V_2 -> V_6 -> V_129 ( V_2 , 4 ) ;
if ( V_387 & V_406 && V_2 -> V_6 -> V_200 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_194 ( struct V_1 * V_2 )
{
T_2 V_387 = V_2 -> V_6 -> V_129 ( V_2 , 4 ) ;
T_2 V_299 = F_1 ( V_2 , V_187 ) ;
if ( ( ! ( V_387 & V_407 ) && V_2 -> V_6 -> V_200 ( V_2 ) ) ||
V_2 -> V_6 -> V_408 ( V_2 , V_299 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_195 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_196 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_124 ( V_2 , V_2 -> V_22 . V_34 , V_2 -> V_25 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_197 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_196 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_124 ( V_2 , V_2 -> V_25 . V_34 , V_2 -> V_22 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static unsigned F_198 ( struct V_1 * V_2 )
{
unsigned V_73 ;
V_73 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
if ( V_73 == 8 )
V_73 = 4 ;
return V_73 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_125 * V_126 ,
unsigned V_73 , bool V_409 )
{
int V_91 = V_90 ;
V_126 -> type = V_359 ;
V_126 -> V_27 = V_73 ;
V_126 -> V_78 . V_168 . V_87 = V_2 -> V_94 ;
switch ( V_126 -> V_27 ) {
case 1 :
V_126 -> V_34 = F_68 ( V_164 , V_2 ) ;
break;
case 2 :
V_126 -> V_34 = F_68 ( V_172 , V_2 ) ;
break;
case 4 :
V_126 -> V_34 = F_68 ( V_165 , V_2 ) ;
break;
case 8 :
V_126 -> V_34 = F_68 ( V_173 , V_2 ) ;
break;
}
if ( ! V_409 ) {
switch ( V_126 -> V_27 ) {
case 1 :
V_126 -> V_34 &= 0xff ;
break;
case 2 :
V_126 -> V_34 &= 0xffff ;
break;
case 4 :
V_126 -> V_34 &= 0xffffffff ;
break;
}
}
V_170:
return V_91 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_125 * V_126 ,
unsigned V_45 )
{
int V_91 = V_90 ;
switch ( V_45 ) {
case V_410 :
F_65 ( V_2 , V_126 ) ;
break;
case V_411 :
V_91 = F_199 ( V_2 , V_126 , 1 , false ) ;
break;
case V_412 :
V_2 -> V_169 . V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_413:
* V_126 = V_2 -> V_169 ;
V_2 -> V_414 = V_126 ;
if ( V_2 -> V_45 & V_415 )
F_70 ( V_2 ) ;
V_126 -> V_145 = V_126 -> V_34 ;
break;
case V_416 :
V_2 -> V_169 . V_27 = ( V_2 -> V_93 == 8 ) ? 16 : 8 ;
goto V_413;
case V_417 :
V_126 -> type = V_143 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_9 = F_3 ( V_2 , V_246 ) ;
F_56 ( V_126 ) ;
V_126 -> V_145 = V_126 -> V_34 ;
break;
case V_418 :
V_126 -> type = V_143 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 2 : V_2 -> V_93 ;
V_126 -> V_78 . V_9 = F_3 ( V_2 , V_246 ) ;
F_56 ( V_126 ) ;
V_126 -> V_145 = V_126 -> V_34 ;
break;
case V_419 :
if ( V_2 -> V_45 & V_144 ) {
V_126 -> type = V_117 ;
break;
}
V_126 -> type = V_143 ;
V_126 -> V_27 = V_2 -> V_93 ;
V_126 -> V_78 . V_9 = F_3 ( V_2 , V_267 ) ;
F_56 ( V_126 ) ;
V_126 -> V_145 = V_126 -> V_34 ;
break;
case V_420 :
V_126 -> type = V_156 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_168 . V_87 =
F_15 ( V_2 , V_163 ) ;
V_126 -> V_78 . V_168 . V_51 = V_319 ;
V_126 -> V_34 = 0 ;
V_126 -> V_186 = 1 ;
break;
case V_421 :
V_126 -> type = V_143 ;
V_126 -> V_27 = 2 ;
V_126 -> V_78 . V_9 = F_3 ( V_2 , V_267 ) ;
F_56 ( V_126 ) ;
break;
case V_422 :
V_126 -> type = V_359 ;
V_126 -> V_27 = 1 ;
V_126 -> V_34 = F_1 ( V_2 , V_187 ) & 0xff ;
break;
case V_423 :
V_91 = F_199 ( V_2 , V_126 , 1 , true ) ;
break;
case V_424 :
V_126 -> type = V_359 ;
V_126 -> V_27 = 1 ;
V_126 -> V_34 = 1 ;
break;
case V_425 :
V_91 = F_199 ( V_2 , V_126 , F_198 ( V_2 ) , true ) ;
break;
case V_426 :
V_91 = F_199 ( V_2 , V_126 , V_2 -> V_93 , true ) ;
break;
case V_427 :
V_2 -> V_169 . V_27 = 1 ;
if ( V_2 -> V_169 . type == V_143 ) {
V_2 -> V_169 . V_78 . V_9 = F_49 ( V_2 ,
V_2 -> V_20 , true ) ;
F_56 ( & V_2 -> V_169 ) ;
}
goto V_413;
case V_428 :
V_2 -> V_169 . V_27 = 2 ;
goto V_413;
case V_429 :
V_2 -> V_169 . V_27 = 4 ;
goto V_413;
case V_430 :
V_91 = F_199 ( V_2 , V_126 , 2 , false ) ;
break;
case V_431 :
V_91 = F_199 ( V_2 , V_126 , F_198 ( V_2 ) , false ) ;
break;
case V_432 :
V_126 -> type = V_156 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_168 . V_87 =
F_15 ( V_2 , V_161 ) ;
V_126 -> V_78 . V_168 . V_51 = V_2 -> V_433 ;
V_126 -> V_34 = 0 ;
V_126 -> V_186 = 1 ;
break;
case V_434 :
V_126 -> type = V_156 ;
V_126 -> V_27 = ( V_2 -> V_45 & V_144 ) ? 1 : V_2 -> V_93 ;
V_126 -> V_78 . V_168 . V_87 =
F_14 ( V_2 ,
F_1 ( V_2 , V_158 ) +
( F_1 ( V_2 , V_246 ) & 0xff ) ) ;
V_126 -> V_78 . V_168 . V_51 = V_2 -> V_433 ;
V_126 -> V_34 = 0 ;
break;
case V_435 :
V_126 -> type = V_359 ;
V_126 -> V_78 . V_168 . V_87 = V_2 -> V_94 ;
V_126 -> V_27 = V_2 -> V_93 + 2 ;
F_201 ( V_126 -> V_263 , V_126 -> V_27 , V_2 ) ;
break;
case V_436 :
V_2 -> V_169 . V_27 = V_2 -> V_93 + 2 ;
goto V_413;
case V_437 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_319 ;
break;
case V_438 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_92 ;
break;
case V_439 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_44 ;
break;
case V_440 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_154 ;
break;
case V_441 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_52 ;
break;
case V_442 :
V_126 -> type = V_359 ;
V_126 -> V_34 = V_213 ;
break;
case V_443 :
default:
V_126 -> type = V_117 ;
break;
}
V_170:
return V_91 ;
}
int F_202 ( struct V_1 * V_2 , void * V_444 , int V_445 )
{
int V_91 = V_90 ;
int V_41 = V_2 -> V_41 ;
int V_446 , V_447 , V_448 , V_449 ;
bool V_450 = false ;
bool V_451 = false ;
struct V_452 V_452 ;
V_2 -> V_169 . type = V_117 ;
V_2 -> V_414 = NULL ;
V_2 -> V_94 = V_2 -> V_31 ;
V_2 -> V_81 . V_111 = V_2 -> V_81 . V_104 ;
V_2 -> V_81 . V_108 = V_2 -> V_81 . V_104 + V_445 ;
V_2 -> V_453 = 1 ;
if ( V_445 > 0 )
memcpy ( V_2 -> V_81 . V_104 , V_444 , V_445 ) ;
else {
V_91 = F_45 ( V_2 , 1 ) ;
if ( V_91 != V_90 )
return V_91 ;
}
switch ( V_41 ) {
case V_89 :
case V_214 :
case V_96 :
V_446 = V_447 = 2 ;
break;
case V_102 :
V_446 = V_447 = 4 ;
break;
#ifdef F_42
case V_42 :
V_446 = 4 ;
V_447 = 8 ;
break;
#endif
default:
return V_351 ;
}
V_2 -> V_93 = V_446 ;
V_2 -> V_29 = V_447 ;
for (; ; ) {
switch ( V_2 -> V_135 = F_68 ( V_35 , V_2 ) ) {
case 0x66 :
V_450 = true ;
V_2 -> V_93 = V_446 ^ 6 ;
break;
case 0x67 :
if ( V_41 == V_42 )
V_2 -> V_29 = V_447 ^ 12 ;
else
V_2 -> V_29 = V_447 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_451 = true ;
V_2 -> V_433 = ( V_2 -> V_135 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_451 = true ;
V_2 -> V_433 = V_2 -> V_135 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_41 != V_42 )
goto V_454;
V_2 -> V_115 = V_2 -> V_135 ;
continue;
case 0xf0 :
V_2 -> V_222 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_135 ;
break;
default:
goto V_454;
}
V_2 -> V_115 = 0 ;
}
V_454:
if ( V_2 -> V_115 & 8 )
V_2 -> V_93 = 8 ;
V_452 = V_455 [ V_2 -> V_135 ] ;
if ( V_2 -> V_135 == 0x0f ) {
V_2 -> V_453 = 2 ;
V_2 -> V_135 = F_68 ( V_35 , V_2 ) ;
V_452 = V_456 [ V_2 -> V_135 ] ;
if ( V_2 -> V_135 == 0x38 ) {
V_2 -> V_453 = 3 ;
V_2 -> V_135 = F_68 ( V_35 , V_2 ) ;
V_452 = V_457 [ V_2 -> V_135 ] ;
}
}
V_2 -> V_45 = V_452 . V_121 ;
if ( V_2 -> V_45 & V_134 )
V_2 -> V_153 = F_68 ( V_35 , V_2 ) ;
if ( V_2 -> V_453 == 1 && ( V_2 -> V_135 == 0xc5 || V_2 -> V_135 == 0xc4 ) &&
( V_41 == V_42 || ( V_2 -> V_153 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_45 = V_458 ;
}
while ( V_2 -> V_45 & V_459 ) {
switch ( V_2 -> V_45 & V_459 ) {
case V_460 :
V_448 = ( V_2 -> V_153 >> 3 ) & 7 ;
V_452 = V_452 . V_461 . V_462 [ V_448 ] ;
break;
case V_463 :
V_448 = ( V_2 -> V_153 >> 3 ) & 7 ;
if ( ( V_2 -> V_153 >> 6 ) == 3 )
V_452 = V_452 . V_461 . V_464 -> V_465 [ V_448 ] ;
else
V_452 = V_452 . V_461 . V_464 -> V_466 [ V_448 ] ;
break;
case V_467 :
V_448 = V_2 -> V_153 & 7 ;
V_452 = V_452 . V_461 . V_462 [ V_448 ] ;
break;
case V_468 :
if ( V_2 -> V_17 && V_450 )
return V_351 ;
V_449 = V_450 ? 0x66 : V_2 -> V_17 ;
switch ( V_449 ) {
case 0x00 : V_452 = V_452 . V_461 . V_469 -> V_470 ; break;
case 0x66 : V_452 = V_452 . V_461 . V_469 -> V_471 ; break;
case 0xf2 : V_452 = V_452 . V_461 . V_469 -> V_472 ; break;
case 0xf3 : V_452 = V_452 . V_461 . V_469 -> V_473 ; break;
}
break;
case V_474 :
if ( V_2 -> V_153 > 0xbf )
V_452 = V_452 . V_461 . V_475 -> V_476 [ V_2 -> V_153 - 0xc0 ] ;
else
V_452 = V_452 . V_461 . V_475 -> V_126 [ ( V_2 -> V_153 >> 3 ) & 7 ] ;
break;
case V_477 :
if ( ( V_2 -> V_153 >> 6 ) == 3 )
V_452 = V_452 . V_461 . V_478 -> V_465 ;
else
V_452 = V_452 . V_461 . V_478 -> V_466 ;
break;
case V_479 :
if ( V_2 -> V_41 == V_42 )
V_452 = V_452 . V_461 . V_480 -> V_481 ;
else
V_452 = V_452 . V_461 . V_480 -> V_482 ;
break;
default:
return V_351 ;
}
V_2 -> V_45 &= ~ ( T_2 ) V_459 ;
V_2 -> V_45 |= V_452 . V_121 ;
}
if ( V_2 -> V_45 == 0 )
return V_351 ;
V_2 -> V_483 = V_452 . V_461 . V_483 ;
if ( F_46 ( V_2 -> V_484 ) && F_34 ( ! ( V_2 -> V_45 & V_485 ) ) )
return V_351 ;
if ( F_46 ( V_2 -> V_45 &
( V_458 | V_486 | V_487 | V_136 | V_140 | V_488 | V_489 | V_490 |
V_491 ) ) ) {
V_2 -> V_492 = V_452 . V_492 ;
V_2 -> V_12 = V_452 . V_12 ;
if ( V_2 -> V_45 & V_458 )
return V_351 ;
if ( V_41 == V_42 ) {
if ( V_2 -> V_93 == 4 && ( V_2 -> V_45 & V_486 ) )
V_2 -> V_93 = 8 ;
else if ( V_2 -> V_45 & V_490 )
V_2 -> V_93 = 8 ;
}
if ( V_2 -> V_45 & V_487 ) {
if ( V_41 == V_42 )
V_2 -> V_93 = 8 ;
else
V_2 -> V_93 = 4 ;
}
if ( ( V_2 -> V_45 & V_491 ) && V_2 -> V_93 == 2 )
V_2 -> V_93 = 4 ;
if ( V_2 -> V_45 & V_136 )
V_2 -> V_93 = 16 ;
else if ( V_2 -> V_45 & V_140 )
V_2 -> V_93 = 8 ;
}
if ( V_2 -> V_45 & V_134 ) {
V_91 = F_67 ( V_2 , & V_2 -> V_169 ) ;
if ( ! V_451 ) {
V_451 = true ;
V_2 -> V_433 = V_2 -> V_148 ;
}
} else if ( V_2 -> V_45 & V_493 )
V_91 = F_69 ( V_2 , & V_2 -> V_169 ) ;
if ( V_91 != V_90 )
goto V_170;
if ( ! V_451 )
V_2 -> V_433 = V_154 ;
V_2 -> V_169 . V_78 . V_168 . V_51 = V_2 -> V_433 ;
V_91 = F_200 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_45 >> V_494 ) & V_495 ) ;
if ( V_91 != V_90 )
goto V_170;
V_91 = F_200 ( V_2 , & V_2 -> V_241 , ( V_2 -> V_45 >> V_496 ) & V_495 ) ;
if ( V_91 != V_90 )
goto V_170;
V_91 = F_200 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_45 >> V_497 ) & V_495 ) ;
if ( V_2 -> V_167 )
V_2 -> V_414 -> V_78 . V_168 . V_87 = F_14 ( V_2 ,
V_2 -> V_414 -> V_78 . V_168 . V_87 + V_2 -> V_94 ) ;
V_170:
return ( V_91 != V_90 ) ? V_351 : V_352 ;
}
bool F_203 ( struct V_1 * V_2 )
{
return V_2 -> V_45 & V_498 ;
}
static bool F_204 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_135 == 0xa6 ) || ( V_2 -> V_135 == 0xa7 ) ||
( V_2 -> V_135 == 0xae ) || ( V_2 -> V_135 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_499 ) &&
( ( V_2 -> V_188 & V_232 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_500 ) &&
( ( V_2 -> V_188 & V_232 ) == V_232 ) ) ) )
return true ;
return false ;
}
static int F_205 ( struct V_1 * V_2 )
{
bool V_501 = false ;
V_2 -> V_6 -> V_127 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_128 ( V_2 ) ;
if ( F_46 ( V_501 ) )
return F_22 ( V_2 , V_502 , 0 , false ) ;
return V_90 ;
}
static void F_206 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
if ( V_126 -> type == V_141 )
F_60 ( V_2 , & V_126 -> V_223 , V_126 -> V_78 . V_142 ) ;
}
static int F_52 ( struct V_1 * V_2 , void (* F_55)( struct F_52 * ) )
{
T_1 V_121 = ( V_2 -> V_188 & V_123 ) | V_124 ;
if ( ! ( V_2 -> V_45 & V_144 ) )
F_55 += F_207 ( V_2 -> V_25 . V_27 ) * V_503 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_188 = ( V_2 -> V_188 & ~ V_123 ) | ( V_121 & V_123 ) ;
if ( ! F_55 )
return F_29 ( V_2 ) ;
return V_90 ;
}
void F_208 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_167 , 0 ,
( void * ) & V_2 -> V_153 - ( void * ) & V_2 -> V_167 ) ;
V_2 -> V_183 . V_177 = 0 ;
V_2 -> V_183 . V_108 = 0 ;
V_2 -> V_176 . V_108 = 0 ;
}
int F_209 ( struct V_1 * V_2 )
{
const struct V_195 * V_6 = V_2 -> V_6 ;
int V_91 = V_90 ;
int V_504 = V_2 -> V_25 . type ;
V_2 -> V_176 . V_177 = 0 ;
if ( V_2 -> V_222 && ( ! ( V_2 -> V_45 & V_505 ) || V_2 -> V_25 . type != V_156 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_170;
}
if ( ( V_2 -> V_45 & V_506 ) == V_507 && V_2 -> V_22 . type != V_156 ) {
V_91 = F_27 ( V_2 ) ;
goto V_170;
}
if ( F_46 ( V_2 -> V_45 &
( V_508 | V_509 | V_136 | V_140 | V_488 | V_489 | V_510 | V_511 | String ) ) ) {
if ( ( V_2 -> V_41 == V_42 && ( V_2 -> V_45 & V_508 ) ) ||
( V_2 -> V_45 & V_509 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_170;
}
if ( ( ( V_2 -> V_45 & ( V_136 | V_140 ) ) && ( ( V_6 -> V_129 ( V_2 , 0 ) & V_131 ) ) )
|| ( ( V_2 -> V_45 & V_136 ) && ! ( V_6 -> V_129 ( V_2 , 4 ) & V_512 ) ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_170;
}
if ( ( V_2 -> V_45 & ( V_136 | V_140 ) ) && ( V_6 -> V_129 ( V_2 , 0 ) & V_130 ) ) {
V_91 = F_30 ( V_2 ) ;
goto V_170;
}
if ( V_2 -> V_45 & V_140 ) {
V_91 = F_205 ( V_2 ) ;
if ( V_91 != V_90 )
goto V_170;
F_206 ( V_2 , & V_2 -> V_22 ) ;
F_206 ( V_2 , & V_2 -> V_241 ) ;
if ( ! ( V_2 -> V_45 & V_513 ) )
F_206 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_46 ( V_2 -> V_514 ) && ( V_2 -> V_45 & V_488 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_515 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( ( V_2 -> V_45 & V_511 ) && V_2 -> V_41 < V_96 ) {
V_91 = F_27 ( V_2 ) ;
goto V_170;
}
if ( ( V_2 -> V_45 & V_510 ) && V_6 -> V_200 ( V_2 ) ) {
if ( V_2 -> V_45 & V_516 )
V_91 = F_27 ( V_2 ) ;
else
V_91 = F_25 ( V_2 , 0 ) ;
goto V_170;
}
if ( V_2 -> V_45 & V_489 ) {
V_91 = V_2 -> V_492 ( V_2 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( F_46 ( V_2 -> V_514 ) && ( V_2 -> V_45 & V_488 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_517 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
if ( F_14 ( V_2 , F_1 ( V_2 , V_187 ) ) == 0 ) {
V_2 -> V_31 = V_2 -> V_94 ;
V_2 -> V_188 &= ~ V_254 ;
goto V_170;
}
}
}
if ( ( V_2 -> V_22 . type == V_156 ) && ! ( V_2 -> V_45 & V_518 ) ) {
V_91 = F_72 ( V_2 , V_2 -> V_22 . V_78 . V_168 ,
V_2 -> V_22 . V_263 , V_2 -> V_22 . V_27 ) ;
if ( V_91 != V_90 )
goto V_170;
V_2 -> V_22 . V_266 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_241 . type == V_156 ) {
V_91 = F_72 ( V_2 , V_2 -> V_241 . V_78 . V_168 ,
& V_2 -> V_241 . V_34 , V_2 -> V_241 . V_27 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( ( V_2 -> V_45 & V_519 ) == V_520 )
goto V_521;
if ( ( V_2 -> V_25 . type == V_156 ) && ! ( V_2 -> V_45 & V_513 ) ) {
V_91 = F_72 ( V_2 , V_2 -> V_25 . V_78 . V_168 ,
& V_2 -> V_25 . V_34 , V_2 -> V_25 . V_27 ) ;
if ( V_91 != V_90 ) {
if ( ! ( V_2 -> V_45 & V_522 ) &&
V_91 == V_60 &&
V_2 -> V_56 . V_57 == V_523 )
V_2 -> V_56 . V_58 |= V_524 ;
goto V_170;
}
}
V_2 -> V_25 . V_266 = V_2 -> V_25 . V_23 ;
V_521:
if ( F_46 ( V_2 -> V_514 ) && ( V_2 -> V_45 & V_488 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_525 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) )
V_2 -> V_188 |= V_254 ;
else
V_2 -> V_188 &= ~ V_254 ;
if ( V_2 -> V_483 ) {
if ( V_2 -> V_45 & V_526 ) {
void (* F_55)( struct F_52 * ) = ( void * ) V_2 -> V_483 ;
V_91 = F_52 ( V_2 , F_55 ) ;
if ( V_91 != V_90 )
goto V_170;
goto F_88;
}
V_91 = V_2 -> V_483 ( V_2 ) ;
if ( V_91 != V_90 )
goto V_170;
goto F_88;
}
if ( V_2 -> V_453 == 2 )
goto V_527;
else if ( V_2 -> V_453 == 3 )
goto V_528;
switch ( V_2 -> V_135 ) {
case 0x70 ... 0x7f :
if ( F_54 ( V_2 -> V_135 , V_2 -> V_188 ) )
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_78 . V_168 . V_87 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_78 . V_9 == F_3 ( V_2 , V_246 ) )
V_2 -> V_25 . type = V_117 ;
else
V_91 = F_142 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_93 ) {
case 2 : V_2 -> V_25 . V_34 = ( V_164 ) V_2 -> V_25 . V_34 ; break;
case 4 : V_2 -> V_25 . V_34 = ( V_172 ) V_2 -> V_25 . V_34 ; break;
case 8 : V_2 -> V_25 . V_34 = ( V_165 ) V_2 -> V_25 . V_34 ; break;
}
break;
case 0xcc :
V_91 = F_104 ( V_2 , 3 ) ;
break;
case 0xcd :
V_91 = F_104 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0xce :
if ( V_2 -> V_188 & V_234 )
V_91 = F_104 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
V_2 -> V_25 . type = V_117 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_529 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_188 ^= V_229 ;
break;
case 0xf8 :
V_2 -> V_188 &= ~ V_229 ;
break;
case 0xf9 :
V_2 -> V_188 |= V_229 ;
break;
case 0xfc :
V_2 -> V_188 &= ~ V_189 ;
break;
case 0xfd :
V_2 -> V_188 |= V_189 ;
break;
default:
goto V_530;
}
if ( V_91 != V_90 )
goto V_170;
F_88:
if ( V_2 -> V_45 & V_531 ) {
F_210 ( V_2 -> V_22 . type == V_156 || V_2 -> V_22 . type == V_190 ) ;
V_91 = F_88 ( V_2 , & V_2 -> V_22 ) ;
if ( V_91 != V_90 )
goto V_170;
}
if ( ! ( V_2 -> V_45 & V_522 ) ) {
V_91 = F_88 ( V_2 , & V_2 -> V_25 ) ;
if ( V_91 != V_90 )
goto V_170;
}
V_2 -> V_25 . type = V_504 ;
if ( ( V_2 -> V_45 & V_506 ) == V_532 )
F_134 ( V_2 , V_161 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_45 & V_519 ) == V_533 )
F_134 ( V_2 , V_163 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
unsigned int V_186 ;
struct V_174 * V_303 = & V_2 -> V_183 ;
if ( ( V_2 -> V_45 & V_506 ) == V_532 )
V_186 = V_2 -> V_22 . V_186 ;
else
V_186 = V_2 -> V_25 . V_186 ;
F_17 ( V_2 , V_187 , - V_186 ) ;
if ( ! F_204 ( V_2 ) ) {
if ( ( V_303 -> V_108 != 0 || F_1 ( V_2 , V_187 ) & 0x3ff ) &&
( V_303 -> V_108 == 0 || V_303 -> V_108 != V_303 -> V_177 ) ) {
V_2 -> V_176 . V_108 = 0 ;
F_4 ( V_2 ) ;
return V_534 ;
}
goto V_170;
}
V_2 -> V_188 &= ~ V_254 ;
}
V_2 -> V_31 = V_2 -> V_94 ;
V_170:
if ( V_91 == V_60 ) {
F_23 ( V_2 -> V_56 . V_57 > 0x1f ) ;
V_2 -> V_535 = true ;
}
if ( V_91 == V_536 )
return V_537 ;
if ( V_91 == V_90 )
F_4 ( V_2 ) ;
return ( V_91 == V_219 ) ? V_351 : V_352 ;
V_527:
switch ( V_2 -> V_135 ) {
case 0x09 :
( V_2 -> V_6 -> V_538 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_34 = V_6 -> V_129 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_398 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_34 ) ;
break;
case 0x40 ... 0x4f :
if ( F_54 ( V_2 -> V_135 , V_2 -> V_188 ) )
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
else if ( V_2 -> V_93 != 4 )
V_2 -> V_25 . type = V_117 ;
break;
case 0x80 ... 0x8f :
if ( F_54 ( V_2 -> V_135 , V_2 -> V_188 ) )
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_34 = F_54 ( V_2 -> V_135 , V_2 -> V_188 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_93 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_35 ) V_2 -> V_22 . V_34
: ( V_36 ) V_2 -> V_22 . V_34 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_93 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_164 ) V_2 -> V_22 . V_34 :
( V_172 ) V_2 -> V_22 . V_34 ;
break;
default:
goto V_530;
}
V_528:
if ( V_91 != V_90 )
goto V_170;
goto F_88;
V_530:
return V_351 ;
}
void F_211 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
