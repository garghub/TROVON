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
static unsigned F_33 ( struct V_1 * V_2 , unsigned V_74 )
{
T_2 V_75 = V_2 -> V_45 & V_76 ;
if ( F_34 ( V_74 < 16 ) )
return 1 ;
switch ( V_75 ) {
case V_77 :
case V_78 :
return 1 ;
case V_79 :
return 16 ;
case V_80 :
default:
return V_74 ;
}
}
static T_3 int F_35 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
unsigned * V_83 , unsigned V_74 ,
bool V_84 , bool V_85 ,
enum V_86 V_41 , T_1 * V_87 )
{
struct V_39 V_49 ;
bool V_88 ;
T_1 V_89 ;
V_37 V_90 ;
V_36 V_38 ;
V_89 = F_21 ( V_2 , V_82 . V_52 ) + V_82 . V_91 ;
* V_83 = 0 ;
switch ( V_41 ) {
case V_42 :
* V_87 = V_89 ;
if ( F_36 ( V_89 ) )
goto V_92;
* V_83 = F_37 ( T_2 , ~ 0u , ( 1ull << 48 ) - V_89 ) ;
if ( V_74 > * V_83 )
goto V_92;
break;
default:
* V_87 = V_89 = ( V_37 ) V_89 ;
V_88 = V_2 -> V_6 -> V_43 ( V_2 , & V_38 , & V_49 , NULL ,
V_82 . V_52 ) ;
if ( ! V_88 )
goto V_92;
if ( ( ( ( V_2 -> V_41 != V_93 ) && ( V_49 . type & 8 ) )
|| ! ( V_49 . type & 2 ) ) && V_84 )
goto V_92;
if ( ! V_85 && ( V_49 . type & 8 ) && ! ( V_49 . type & 2 ) )
goto V_92;
V_90 = F_19 ( & V_49 ) ;
if ( ! ( V_49 . type & 8 ) && ( V_49 . type & 4 ) ) {
if ( V_82 . V_91 <= V_90 )
goto V_92;
V_90 = V_49 . V_45 ? 0xffffffff : 0xffff ;
}
if ( V_82 . V_91 > V_90 )
goto V_92;
if ( V_90 == 0xffffffff )
* V_83 = ~ 0u ;
else {
* V_83 = ( T_2 ) V_90 + 1 - V_82 . V_91 ;
if ( V_74 > * V_83 )
goto V_92;
}
break;
}
if ( V_89 & ( F_33 ( V_2 , V_74 ) - 1 ) )
return F_25 ( V_2 , 0 ) ;
return V_94 ;
V_92:
if ( V_82 . V_52 == V_44 )
return F_26 ( V_2 , 0 ) ;
else
return F_25 ( V_2 , 0 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
unsigned V_74 , bool V_84 ,
T_1 * V_87 )
{
unsigned V_83 ;
return F_35 ( V_2 , V_82 , & V_83 , V_74 , V_84 , false ,
V_2 -> V_41 , V_87 ) ;
}
static inline int F_39 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_86 V_41 )
{
T_1 V_87 ;
int V_95 ;
unsigned V_83 ;
struct V_81 V_82 = { . V_52 = V_96 ,
. V_91 = V_25 } ;
if ( V_2 -> V_97 != sizeof( unsigned long ) )
V_82 . V_91 = V_25 & ( ( 1UL << ( V_2 -> V_97 << 3 ) ) - 1 ) ;
V_95 = F_35 ( V_2 , V_82 , & V_83 , 1 , false , true , V_41 , & V_87 ) ;
if ( V_95 == V_94 )
V_2 -> V_98 = V_82 . V_91 ;
return V_95 ;
}
static inline int F_40 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_39 ( V_2 , V_25 , V_2 -> V_41 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_25 ,
const struct V_39 * V_99 )
{
enum V_86 V_41 = V_2 -> V_41 ;
int V_95 ;
#ifdef F_42
if ( V_2 -> V_41 >= V_100 ) {
if ( V_99 -> V_101 ) {
T_2 V_102 = 0 ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( V_102 & V_105 )
V_41 = V_42 ;
} else
V_41 = V_106 ;
}
#endif
if ( V_41 == V_100 || V_41 == V_106 )
V_41 = V_99 -> V_45 ? V_106 : V_100 ;
V_95 = F_39 ( V_2 , V_25 , V_41 ) ;
if ( V_95 == V_94 )
V_2 -> V_41 = V_41 ;
return V_95 ;
}
static inline int F_43 ( struct V_1 * V_2 , int V_107 )
{
return F_40 ( V_2 , V_2 -> V_98 + V_107 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_108 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_82 , V_74 , false , & V_87 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_109 ( V_2 , V_87 , V_108 , V_74 , & V_2 -> V_57 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_108 ,
unsigned int V_74 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_110 ( V_2 , V_87 , V_108 , V_74 , & V_2 -> V_57 ) ;
}
static int F_46 ( struct V_1 * V_2 , int V_111 )
{
int V_95 ;
unsigned V_74 , V_83 ;
unsigned long V_87 ;
int V_112 = V_2 -> V_85 . V_113 - V_2 -> V_85 . V_108 ;
struct V_81 V_82 = { . V_52 = V_96 ,
. V_91 = V_2 -> V_31 + V_112 } ;
V_95 = F_35 ( V_2 , V_82 , & V_83 , 0 , false , true , V_2 -> V_41 ,
& V_87 ) ;
if ( F_47 ( V_95 != V_94 ) )
return V_95 ;
V_74 = F_37 ( unsigned , 15UL ^ V_112 , V_83 ) ;
V_74 = F_37 ( unsigned , V_74 , V_114 - F_48 ( V_87 ) ) ;
if ( F_47 ( V_74 < V_111 ) )
return F_25 ( V_2 , 0 ) ;
V_95 = V_2 -> V_6 -> V_85 ( V_2 , V_87 , V_2 -> V_85 . V_113 ,
V_74 , & V_2 -> V_57 ) ;
if ( F_47 ( V_95 != V_94 ) )
return V_95 ;
V_2 -> V_85 . V_113 += V_74 ;
return V_94 ;
}
static T_3 int F_49 ( struct V_1 * V_2 ,
unsigned V_74 )
{
unsigned V_115 = V_2 -> V_85 . V_113 - V_2 -> V_85 . V_116 ;
if ( F_47 ( V_115 < V_74 ) )
return F_46 ( V_2 , V_74 - V_115 ) ;
else
return V_94 ;
}
static void * F_50 ( struct V_1 * V_2 , V_35 V_19 ,
int V_117 )
{
void * V_118 ;
int V_119 = ( V_2 -> V_120 == 0 ) && V_117 ;
if ( V_119 && V_19 >= 4 && V_19 < 8 )
V_118 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_118 = F_3 ( V_2 , V_19 ) ;
return V_118 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
V_36 * V_74 , unsigned long * V_121 , int V_97 )
{
int V_95 ;
if ( V_97 == 2 )
V_97 = 3 ;
* V_121 = 0 ;
V_95 = F_44 ( V_2 , V_82 , V_74 , 2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_82 . V_91 += 2 ;
V_95 = F_44 ( V_2 , V_82 , V_121 , V_97 ) ;
return V_95 ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_122 ;
return F_53 ( V_2 , V_123 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_122 ;
return F_53 ( V_2 , V_124 ) ;
}
static T_3 V_35 F_55 ( unsigned int V_125 , unsigned long V_126 )
{
V_35 V_95 ;
void (* F_56)( void ) = ( void * ) V_127 + 4 * ( V_125 & 0xf ) ;
V_126 = ( V_126 & V_128 ) | V_129 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_95 ;
}
static void F_57 ( struct V_130 * V_131 )
{
switch ( V_131 -> V_27 ) {
case 1 :
V_131 -> V_34 = * ( V_35 * ) V_131 -> V_82 . V_9 ;
break;
case 2 :
V_131 -> V_34 = * ( V_36 * ) V_131 -> V_82 . V_9 ;
break;
case 4 :
V_131 -> V_34 = * ( V_37 * ) V_131 -> V_82 . V_9 ;
break;
case 8 :
V_131 -> V_34 = * ( T_2 * ) V_131 -> V_82 . V_9 ;
break;
}
}
static void F_58 ( struct V_1 * V_2 , T_4 * V_108 , int V_9 )
{
V_2 -> V_6 -> V_132 ( V_2 ) ;
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
default: F_59 () ;
}
V_2 -> V_6 -> V_133 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_4 * V_108 ,
int V_9 )
{
V_2 -> V_6 -> V_132 ( V_2 ) ;
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
default: F_59 () ;
}
V_2 -> V_6 -> V_133 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , T_2 * V_108 , int V_9 )
{
V_2 -> V_6 -> V_132 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_59 () ;
}
V_2 -> V_6 -> V_133 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_2 * V_108 , int V_9 )
{
V_2 -> V_6 -> V_132 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_59 () ;
}
V_2 -> V_6 -> V_133 ( V_2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_134 ( V_2 , 0 ) & ( V_135 | V_136 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_133 ( V_2 ) ;
return V_94 ;
}
static int F_64 ( struct V_1 * V_2 )
{
V_36 V_137 ;
if ( V_2 -> V_6 -> V_134 ( V_2 , 0 ) & ( V_135 | V_136 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_133 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_137 ;
return V_94 ;
}
static int F_65 ( struct V_1 * V_2 )
{
V_36 V_138 ;
if ( V_2 -> V_6 -> V_134 ( V_2 , 0 ) & ( V_135 | V_136 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_133 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_138 ;
return V_94 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_45 & V_139 ) )
V_9 = ( V_2 -> V_140 & 7 ) | ( ( V_2 -> V_120 & 1 ) << 3 ) ;
if ( V_2 -> V_45 & V_141 ) {
V_131 -> type = V_142 ;
V_131 -> V_27 = 16 ;
V_131 -> V_82 . V_143 = V_9 ;
F_58 ( V_2 , & V_131 -> V_144 , V_9 ) ;
return;
}
if ( V_2 -> V_45 & V_145 ) {
V_9 &= 7 ;
V_131 -> type = V_146 ;
V_131 -> V_27 = 8 ;
V_131 -> V_82 . V_147 = V_9 ;
return;
}
V_131 -> type = V_148 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_9 = F_50 ( V_2 , V_9 , V_2 -> V_45 & V_149 ) ;
F_57 ( V_131 ) ;
V_131 -> V_150 = V_131 -> V_34 ;
}
static void F_67 ( struct V_1 * V_2 , int V_151 )
{
if ( V_151 == V_48 || V_151 == V_152 )
V_2 -> V_153 = V_44 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
V_35 V_154 ;
int V_155 , V_151 , V_156 ;
int V_95 = V_94 ;
T_1 V_157 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_120 << 1 ) & 8 ) ;
V_155 = ( V_2 -> V_120 << 2 ) & 8 ;
V_151 = ( V_2 -> V_120 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_158 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_158 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_151 | ( V_2 -> V_158 & 0x07 ) ;
V_2 -> V_153 = V_159 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_45 & V_160 ) ) {
V_131 -> type = V_148 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_9 = F_50 ( V_2 , V_2 -> V_20 ,
V_2 -> V_45 & V_149 ) ;
if ( V_2 -> V_45 & V_141 ) {
V_131 -> type = V_142 ;
V_131 -> V_27 = 16 ;
V_131 -> V_82 . V_143 = V_2 -> V_20 ;
F_58 ( V_2 , & V_131 -> V_144 , V_2 -> V_20 ) ;
return V_95 ;
}
if ( V_2 -> V_45 & V_145 ) {
V_131 -> type = V_146 ;
V_131 -> V_27 = 8 ;
V_131 -> V_82 . V_147 = V_2 -> V_20 & 7 ;
return V_95 ;
}
F_57 ( V_131 ) ;
return V_95 ;
}
V_131 -> type = V_161 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_162 = F_1 ( V_2 , V_163 ) ;
unsigned V_164 = F_1 ( V_2 , V_152 ) ;
unsigned V_165 = F_1 ( V_2 , V_166 ) ;
unsigned V_167 = F_1 ( V_2 , V_168 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_157 += F_69 ( V_36 , V_2 ) ;
break;
case 1 :
V_157 += F_69 ( V_169 , V_2 ) ;
break;
case 2 :
V_157 += F_69 ( V_36 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_157 += V_162 + V_165 ;
break;
case 1 :
V_157 += V_162 + V_167 ;
break;
case 2 :
V_157 += V_164 + V_165 ;
break;
case 3 :
V_157 += V_164 + V_167 ;
break;
case 4 :
V_157 += V_165 ;
break;
case 5 :
V_157 += V_167 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_157 += V_164 ;
break;
case 7 :
V_157 += V_162 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_153 = V_44 ;
V_157 = ( V_36 ) V_157 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_154 = F_69 ( V_35 , V_2 ) ;
V_155 |= ( V_154 >> 3 ) & 7 ;
V_151 |= V_154 & 7 ;
V_156 = V_154 >> 6 ;
if ( ( V_151 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_157 += F_69 ( V_170 , V_2 ) ;
else {
V_157 += F_1 ( V_2 , V_151 ) ;
F_67 ( V_2 , V_151 ) ;
if ( ( V_2 -> V_45 & V_171 ) &&
V_151 == V_48 )
V_157 += V_2 -> V_97 ;
}
if ( V_155 != 4 )
V_157 += F_1 ( V_2 , V_155 ) << V_156 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_157 += F_69 ( V_170 , V_2 ) ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_172 = 1 ;
} else {
V_151 = V_2 -> V_20 ;
V_157 += F_1 ( V_2 , V_151 ) ;
F_67 ( V_2 , V_151 ) ;
}
switch ( V_2 -> V_18 ) {
case 1 :
V_157 += F_69 ( V_169 , V_2 ) ;
break;
case 2 :
V_157 += F_69 ( V_170 , V_2 ) ;
break;
}
}
V_131 -> V_82 . V_173 . V_91 = V_157 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_174 . V_82 . V_173 . V_91 = ( V_37 ) V_2 -> V_174 . V_82 . V_173 . V_91 ;
V_175:
return V_95 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
int V_95 = V_94 ;
V_131 -> type = V_161 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_131 -> V_82 . V_173 . V_91 = F_69 ( V_36 , V_2 ) ;
break;
case 4 :
V_131 -> V_82 . V_173 . V_91 = F_69 ( V_37 , V_2 ) ;
break;
case 8 :
V_131 -> V_82 . V_173 . V_91 = F_69 ( T_2 , V_2 ) ;
break;
}
V_175:
return V_95 ;
}
static void F_71 ( struct V_1 * V_2 )
{
long V_176 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_161 && V_2 -> V_22 . type == V_148 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_176 = ( V_177 ) V_2 -> V_22 . V_34 & ( V_177 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_176 = ( V_170 ) V_2 -> V_22 . V_34 & ( V_170 ) V_33 ;
else
V_176 = ( V_178 ) V_2 -> V_22 . V_34 & ( V_178 ) V_33 ;
V_2 -> V_25 . V_82 . V_173 . V_91 = F_14 ( V_2 ,
V_2 -> V_25 . V_82 . V_173 . V_91 + ( V_176 >> 3 ) ) ;
}
V_2 -> V_22 . V_34 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
unsigned long V_82 , void * V_32 , unsigned V_74 )
{
int V_95 ;
struct V_179 * V_180 = & V_2 -> V_181 ;
if ( V_180 -> V_182 < V_180 -> V_113 )
goto V_183;
F_23 ( ( V_180 -> V_113 + V_74 ) >= sizeof( V_180 -> V_108 ) ) ;
V_95 = V_2 -> V_6 -> F_72 ( V_2 , V_82 , V_180 -> V_108 + V_180 -> V_113 , V_74 ,
& V_2 -> V_57 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_180 -> V_113 += V_74 ;
V_183:
memcpy ( V_32 , V_180 -> V_108 + V_180 -> V_182 , V_74 ) ;
V_180 -> V_182 += V_74 ;
return V_94 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_108 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_82 , V_74 , false , & V_87 ) ;
if ( V_95 != V_94 )
return V_95 ;
return F_72 ( V_2 , V_87 , V_108 , V_74 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
const void * V_108 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_184 ( V_2 , V_87 , V_108 , V_74 ,
& V_2 -> V_57 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
const void * V_185 , const void * V_108 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_186 ( V_2 , V_87 , V_185 , V_108 ,
V_74 , & V_2 -> V_57 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
unsigned int V_74 , unsigned short V_187 ,
void * V_32 )
{
struct V_179 * V_95 = & V_2 -> V_188 ;
if ( V_95 -> V_182 == V_95 -> V_113 ) {
unsigned int V_189 , V_190 ;
unsigned int V_191 = V_2 -> V_17 ?
F_14 ( V_2 , F_1 ( V_2 , V_192 ) ) : 1 ;
V_189 = ( V_2 -> V_193 & V_194 ) ?
F_48 ( F_1 ( V_2 , V_168 ) ) :
V_114 - F_48 ( F_1 ( V_2 , V_168 ) ) ;
V_190 = F_77 ( V_189 , ( unsigned int ) sizeof( V_95 -> V_108 ) / V_74 , V_191 ) ;
if ( V_190 == 0 )
V_190 = 1 ;
V_95 -> V_182 = V_95 -> V_113 = 0 ;
if ( ! V_2 -> V_6 -> F_76 ( V_2 , V_74 , V_187 , V_95 -> V_108 , V_190 ) )
return 0 ;
V_95 -> V_113 = V_190 * V_74 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) &&
! ( V_2 -> V_193 & V_194 ) ) {
V_2 -> V_25 . V_108 = V_95 -> V_108 + V_95 -> V_182 ;
V_2 -> V_25 . type = V_195 ;
V_2 -> V_25 . V_191 = ( V_95 -> V_113 - V_95 -> V_182 ) / V_74 ;
V_95 -> V_182 = V_95 -> V_113 ;
} else {
memcpy ( V_32 , V_95 -> V_108 + V_95 -> V_182 , V_74 ) ;
V_95 -> V_182 += V_74 ;
}
return 1 ;
}
static int F_78 ( struct V_1 * V_2 ,
V_36 V_196 , struct V_39 * V_49 )
{
struct V_197 V_198 ;
T_1 V_82 ;
V_2 -> V_6 -> V_199 ( V_2 , & V_198 ) ;
if ( V_198 . V_74 < V_196 * 8 + 7 )
return F_25 ( V_2 , V_196 << 3 | 0x2 ) ;
V_82 = V_198 . V_121 + V_196 * 8 ;
return V_2 -> V_6 -> V_109 ( V_2 , V_82 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_197 * V_198 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
V_37 V_72 = 0 ;
if ( V_70 & 1 << 2 ) {
struct V_39 V_49 ;
V_36 V_38 ;
memset ( V_198 , 0 , sizeof *V_198 ) ;
if ( ! V_6 -> V_43 ( V_2 , & V_38 , & V_49 , & V_72 ,
V_201 ) )
return;
V_198 -> V_74 = F_19 ( & V_49 ) ;
V_198 -> V_121 = F_80 ( & V_49 ) | ( ( T_2 ) V_72 << 32 ) ;
} else
V_6 -> V_202 ( V_2 , V_198 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
V_36 V_70 , T_1 * V_203 )
{
struct V_197 V_198 ;
V_36 V_196 = V_70 >> 3 ;
T_1 V_82 ;
F_79 ( V_2 , V_70 , & V_198 ) ;
if ( V_198 . V_74 < V_196 * 8 + 7 )
return F_25 ( V_2 , V_70 & 0xfffc ) ;
V_82 = V_198 . V_121 + V_196 * 8 ;
#ifdef F_42
if ( V_82 >> 32 != 0 ) {
T_2 V_102 = 0 ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( ! ( V_102 & V_105 ) )
V_82 &= ( V_37 ) - 1 ;
}
#endif
* V_203 = V_82 ;
return V_94 ;
}
static int F_82 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 ,
T_1 * V_203 )
{
int V_95 ;
V_95 = F_81 ( V_2 , V_70 , V_203 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_109 ( V_2 , * V_203 , V_49 , sizeof( * V_49 ) ,
& V_2 -> V_57 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 )
{
int V_95 ;
T_1 V_82 ;
V_95 = F_81 ( V_2 , V_70 , & V_82 ) ;
if ( V_95 != V_94 )
return V_95 ;
return V_2 -> V_6 -> V_110 ( V_2 , V_82 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 , V_35 V_204 ,
enum V_205 V_206 ,
struct V_39 * V_49 )
{
struct V_39 V_207 , V_208 ;
V_35 V_209 , V_210 ;
unsigned V_211 = V_64 ;
V_37 V_212 = 0 ;
bool V_213 = ! ( V_70 & ~ 0x3 ) ;
T_1 V_214 ;
int V_215 ;
V_36 V_71 ;
V_37 V_72 = 0 ;
memset ( & V_207 , 0 , sizeof V_207 ) ;
if ( V_2 -> V_41 == V_93 ) {
V_2 -> V_6 -> V_43 ( V_2 , & V_71 , & V_207 , NULL , V_52 ) ;
F_85 ( & V_207 , V_70 << 4 ) ;
goto V_216;
} else if ( V_52 <= V_217 && V_2 -> V_41 == V_218 ) {
F_85 ( & V_207 , V_70 << 4 ) ;
F_86 ( & V_207 , 0xffff ) ;
V_207 . type = 3 ;
V_207 . V_118 = 1 ;
V_207 . V_219 = 1 ;
V_207 . V_209 = 3 ;
goto V_216;
}
V_210 = V_70 & 3 ;
if ( V_52 == V_220 && ( V_70 & ( 1 << 2 ) ) )
goto V_57;
if ( V_213 ) {
if ( V_52 == V_96 || V_52 == V_220 )
goto V_57;
if ( V_52 == V_44 ) {
if ( V_2 -> V_41 != V_42 || V_210 != V_204 )
goto V_57;
V_207 . type = 3 ;
V_207 . V_118 = 1 ;
V_207 . V_219 = 1 ;
V_207 . V_209 = V_204 ;
V_207 . V_45 = 1 ;
V_207 . V_51 = 1 ;
}
goto V_216;
}
V_215 = F_82 ( V_2 , V_70 , & V_207 , & V_214 ) ;
if ( V_215 != V_94 )
return V_215 ;
V_212 = V_70 & 0xfffc ;
V_211 = ( V_206 == V_221 ) ? V_67 :
V_64 ;
if ( V_52 <= V_217 && ! V_207 . V_219 ) {
if ( V_206 == V_222 )
return V_223 ;
goto V_57;
}
if ( ! V_207 . V_118 ) {
V_211 = ( V_52 == V_44 ) ? V_65 : V_224 ;
goto V_57;
}
V_209 = V_207 . V_209 ;
switch ( V_52 ) {
case V_44 :
if ( V_210 != V_204 || ( V_207 . type & 0xa ) != 0x2 || V_209 != V_204 )
goto V_57;
break;
case V_96 :
if ( ! ( V_207 . type & 8 ) )
goto V_57;
if ( V_207 . type & 4 ) {
if ( V_209 > V_204 )
goto V_57;
} else {
if ( V_210 > V_204 || V_209 != V_204 )
goto V_57;
}
if ( V_207 . V_45 && V_207 . V_101 ) {
T_2 V_102 = 0 ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( V_102 & V_105 )
goto V_57;
}
V_70 = ( V_70 & 0xfffc ) | V_204 ;
break;
case V_220 :
if ( V_207 . V_219 || ( V_207 . type != 1 && V_207 . type != 9 ) )
goto V_57;
V_208 = V_207 ;
V_207 . type |= 2 ;
V_215 = V_2 -> V_6 -> V_186 ( V_2 , V_214 , & V_208 , & V_207 ,
sizeof( V_207 ) , & V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
break;
case V_201 :
if ( V_207 . V_219 || V_207 . type != 2 )
goto V_57;
break;
default:
if ( ( V_207 . type & 0xa ) == 0x8 ||
( ( ( V_207 . type & 0xc ) != 0xc ) &&
( V_210 > V_209 && V_204 > V_209 ) ) )
goto V_57;
break;
}
if ( V_207 . V_219 ) {
if ( ! ( V_207 . type & 1 ) ) {
V_207 . type |= 1 ;
V_215 = F_83 ( V_2 , V_70 ,
& V_207 ) ;
if ( V_215 != V_94 )
return V_215 ;
}
} else if ( V_2 -> V_41 == V_42 ) {
V_215 = V_2 -> V_6 -> V_109 ( V_2 , V_214 + 8 , & V_72 ,
sizeof( V_72 ) , & V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
if ( F_36 ( F_80 ( & V_207 ) |
( ( T_2 ) V_72 << 32 ) ) )
return F_25 ( V_2 , 0 ) ;
}
V_216:
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_207 , V_72 , V_52 ) ;
if ( V_49 )
* V_49 = V_207 ;
return V_94 ;
V_57:
return F_22 ( V_2 , V_211 , V_212 , true ) ;
}
static int F_87 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 )
{
V_35 V_204 = V_2 -> V_6 -> V_204 ( V_2 ) ;
if ( V_52 == V_44 && V_70 == 3 &&
V_2 -> V_41 == V_42 )
return F_22 ( V_2 , V_64 , 0 , true ) ;
return F_84 ( V_2 , V_70 , V_52 , V_204 ,
V_225 , NULL ) ;
}
static void F_88 ( struct V_130 * V_131 )
{
return F_9 ( V_131 -> V_82 . V_9 , V_131 -> V_34 , V_131 -> V_27 ) ;
}
static int F_89 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
switch ( V_131 -> type ) {
case V_148 :
F_88 ( V_131 ) ;
break;
case V_161 :
if ( V_2 -> V_226 )
return F_75 ( V_2 ,
V_131 -> V_82 . V_173 ,
& V_131 -> V_150 ,
& V_131 -> V_34 ,
V_131 -> V_27 ) ;
else
return F_74 ( V_2 ,
V_131 -> V_82 . V_173 ,
& V_131 -> V_34 ,
V_131 -> V_27 ) ;
break;
case V_195 :
return F_74 ( V_2 ,
V_131 -> V_82 . V_173 ,
V_131 -> V_108 ,
V_131 -> V_27 * V_131 -> V_191 ) ;
break;
case V_142 :
F_60 ( V_2 , & V_131 -> V_144 , V_131 -> V_82 . V_143 ) ;
break;
case V_146 :
F_62 ( V_2 , & V_131 -> V_227 , V_131 -> V_82 . V_147 ) ;
break;
case V_122 :
break;
default:
break;
}
return V_94 ;
}
static int F_90 ( struct V_1 * V_2 , void * V_108 , int V_27 )
{
struct V_81 V_82 ;
F_18 ( V_2 , - V_27 ) ;
V_82 . V_91 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_82 . V_52 = V_44 ;
return F_74 ( V_2 , V_82 , V_108 , V_27 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_122 ;
return F_90 ( V_2 , & V_2 -> V_22 . V_34 , V_2 -> V_97 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
void * V_32 , int V_228 )
{
int V_95 ;
struct V_81 V_82 ;
V_82 . V_91 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_82 . V_52 = V_44 ;
V_95 = F_73 ( V_2 , V_82 , V_32 , V_228 ) ;
if ( V_95 != V_94 )
return V_95 ;
F_18 ( V_2 , V_228 ) ;
return V_95 ;
}
static int F_93 ( struct V_1 * V_2 )
{
return F_92 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_97 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
void * V_32 , int V_228 )
{
int V_95 ;
unsigned long V_34 , V_229 ;
int V_230 = ( V_2 -> V_193 & V_231 ) >> V_232 ;
int V_204 = V_2 -> V_6 -> V_204 ( V_2 ) ;
V_95 = F_92 ( V_2 , & V_34 , V_228 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_229 = V_233 | V_234 | V_235 |
V_236 | V_237 | V_238 |
V_239 | V_194 | V_240 |
V_241 | V_242 ;
switch( V_2 -> V_41 ) {
case V_42 :
case V_106 :
case V_100 :
if ( V_204 == 0 )
V_229 |= V_231 ;
if ( V_204 <= V_230 )
V_229 |= V_129 ;
break;
case V_218 :
if ( V_230 < 3 )
return F_25 ( V_2 , 0 ) ;
V_229 |= V_129 ;
break;
default:
V_229 |= ( V_231 | V_129 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_193 & ~ V_229 ) | ( V_34 & V_229 ) ;
return V_95 ;
}
static int F_95 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_148 ;
V_2 -> V_25 . V_82 . V_9 = & V_2 -> V_193 ;
V_2 -> V_25 . V_27 = V_2 -> V_97 ;
return F_94 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_97 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned V_243 = V_2 -> V_22 . V_34 ;
unsigned V_244 = V_2 -> V_245 . V_34 & 31 ;
T_1 V_246 ;
if ( V_244 )
return V_223 ;
V_246 = F_1 ( V_2 , V_152 ) ;
V_95 = F_90 ( V_2 , & V_246 , F_12 ( V_2 ) ) ;
if ( V_95 != V_94 )
return V_95 ;
F_8 ( F_3 ( V_2 , V_152 ) , F_1 ( V_2 , V_48 ) ,
F_11 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_48 ) ,
F_1 ( V_2 , V_48 ) - V_243 ,
F_11 ( V_2 ) ) ;
return V_94 ;
}
static int F_97 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_48 ) , F_1 ( V_2 , V_152 ) ,
F_11 ( V_2 ) ) ;
return F_92 ( V_2 , F_3 ( V_2 , V_152 ) , V_2 -> V_97 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_245 . V_34 ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_52 ) ;
if ( V_2 -> V_97 == 4 ) {
F_18 ( V_2 , - 2 ) ;
V_2 -> V_97 = 2 ;
}
return F_91 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_245 . V_34 ;
unsigned long V_70 ;
int V_95 ;
V_95 = F_92 ( V_2 , & V_70 , 2 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_247 = V_248 ;
if ( V_2 -> V_97 > 2 )
F_18 ( V_2 , V_2 -> V_97 - 2 ) ;
V_95 = F_87 ( V_2 , ( V_36 ) V_70 , V_52 ) ;
return V_95 ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned long V_249 = F_1 ( V_2 , V_48 ) ;
int V_95 = V_94 ;
int V_9 = V_250 ;
while ( V_9 <= V_168 ) {
( V_9 == V_48 ) ?
( V_2 -> V_22 . V_34 = V_249 ) : ( V_2 -> V_22 . V_34 = F_1 ( V_2 , V_9 ) ) ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
++ V_9 ;
}
return V_95 ;
}
static int F_101 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_193 & ~ V_251 ;
return F_91 ( V_2 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_95 = V_94 ;
int V_9 = V_168 ;
V_37 V_34 ;
while ( V_9 >= V_250 ) {
if ( V_9 == V_48 ) {
F_18 ( V_2 , V_2 -> V_97 ) ;
-- V_9 ;
}
V_95 = F_92 ( V_2 , & V_34 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
break;
F_9 ( F_3 ( V_2 , V_9 ) , V_34 , V_2 -> V_97 ) ;
-- V_9 ;
}
return V_95 ;
}
static int F_103 ( struct V_1 * V_2 , int V_252 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
int V_95 ;
struct V_197 V_198 ;
T_5 V_253 ;
T_5 V_254 ;
V_36 V_255 , V_31 ;
V_2 -> V_22 . V_34 = V_2 -> V_193 ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_193 &= ~ ( V_129 | V_239 | V_241 ) ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_96 ) ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_22 . V_34 = V_2 -> V_98 ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_6 -> V_199 ( V_2 , & V_198 ) ;
V_254 = V_198 . V_121 + ( V_252 << 2 ) ;
V_253 = V_198 . V_121 + ( V_252 << 2 ) + 2 ;
V_95 = V_6 -> V_109 ( V_2 , V_253 , & V_255 , 2 , & V_2 -> V_57 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = V_6 -> V_109 ( V_2 , V_254 , & V_31 , 2 , & V_2 -> V_57 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_87 ( V_2 , V_255 , V_96 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_98 = V_31 ;
return V_95 ;
}
int F_104 ( struct V_1 * V_2 , int V_252 )
{
int V_95 ;
F_6 ( V_2 ) ;
V_95 = F_103 ( V_2 , V_252 ) ;
if ( V_95 == V_94 )
F_4 ( V_2 ) ;
return V_95 ;
}
static int F_105 ( struct V_1 * V_2 , int V_252 )
{
switch( V_2 -> V_41 ) {
case V_93 :
return F_103 ( V_2 , V_252 ) ;
case V_218 :
case V_100 :
case V_106 :
case V_42 :
default:
return V_223 ;
}
}
static int F_106 ( struct V_1 * V_2 )
{
int V_95 = V_94 ;
unsigned long V_256 = 0 ;
unsigned long V_257 = 0 ;
unsigned long V_255 = 0 ;
unsigned long V_33 = V_233 | V_234 | V_235 |
V_236 | V_237 | V_239 |
V_129 | V_194 | V_238 |
V_231 | V_240 | V_258 |
V_241 | V_242 |
V_259 ;
unsigned long V_260 = V_251 | V_261 |
V_262 ;
V_95 = F_92 ( V_2 , & V_256 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_256 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_95 = F_92 ( V_2 , & V_255 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_92 ( V_2 , & V_257 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_87 ( V_2 , ( V_36 ) V_255 , V_96 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_98 = V_256 ;
if ( V_2 -> V_97 == 4 )
V_2 -> V_193 = ( ( V_257 & V_33 ) | ( V_2 -> V_193 & V_260 ) ) ;
else if ( V_2 -> V_97 == 2 ) {
V_2 -> V_193 &= ~ 0xffff ;
V_2 -> V_193 |= V_257 ;
}
V_2 -> V_193 &= ~ V_263 ;
V_2 -> V_193 |= V_259 ;
V_2 -> V_6 -> V_264 ( V_2 , false ) ;
return V_95 ;
}
static int F_107 ( struct V_1 * V_2 )
{
switch( V_2 -> V_41 ) {
case V_93 :
return F_106 ( V_2 ) ;
case V_218 :
case V_100 :
case V_106 :
case V_42 :
default:
return V_223 ;
}
}
static int F_108 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned short V_38 ;
struct V_39 V_265 ;
V_35 V_204 = V_2 -> V_6 -> V_204 ( V_2 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_266 + V_2 -> V_97 , 2 ) ;
V_95 = F_84 ( V_2 , V_38 , V_96 , V_204 ,
V_222 ,
& V_265 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_265 ) ;
if ( V_95 != V_94 )
return V_223 ;
return V_95 ;
}
static int F_109 ( struct V_1 * V_2 )
{
return F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_95 ;
long int V_267 ;
V_267 = V_2 -> V_98 ;
V_95 = F_40 ( V_2 , V_2 -> V_22 . V_34 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_22 . V_34 = V_267 ;
V_95 = F_91 ( V_2 ) ;
return V_95 ;
}
static int F_111 ( struct V_1 * V_2 )
{
T_2 V_268 = V_2 -> V_25 . V_269 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_223 ;
if ( ( ( V_37 ) ( V_268 >> 0 ) != ( V_37 ) F_1 ( V_2 , V_250 ) ) ||
( ( V_37 ) ( V_268 >> 32 ) != ( V_37 ) F_1 ( V_2 , V_270 ) ) ) {
* F_2 ( V_2 , V_250 ) = ( V_37 ) ( V_268 >> 0 ) ;
* F_2 ( V_2 , V_270 ) = ( V_37 ) ( V_268 >> 32 ) ;
V_2 -> V_193 &= ~ V_236 ;
} else {
V_2 -> V_25 . V_23 = ( ( T_2 ) F_1 ( V_2 , V_192 ) << 32 ) |
( V_37 ) F_1 ( V_2 , V_163 ) ;
V_2 -> V_193 |= V_236 ;
}
return V_94 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 ;
V_95 = F_92 ( V_2 , & V_31 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
return F_40 ( V_2 , V_31 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 , V_255 ;
int V_204 = V_2 -> V_6 -> V_204 ( V_2 ) ;
struct V_39 V_265 ;
V_95 = F_92 ( V_2 , & V_31 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_92 ( V_2 , & V_255 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_2 -> V_41 >= V_100 && ( V_255 & 3 ) > V_204 )
return V_223 ;
V_95 = F_84 ( V_2 , ( V_36 ) V_255 , V_96 , V_204 ,
V_271 ,
& V_265 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_41 ( V_2 , V_31 , & V_265 ) ;
if ( V_95 != V_94 )
return V_223 ;
return V_95 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = F_113 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_94 ;
}
static int F_115 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_150 = V_2 -> V_25 . V_34 ;
V_2 -> V_25 . V_34 = F_1 ( V_2 , V_250 ) ;
V_2 -> V_22 . V_150 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_150 ;
F_53 ( V_2 , V_272 ) ;
if ( V_2 -> V_193 & V_236 ) {
V_2 -> V_22 . type = V_122 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_150 ;
} else {
V_2 -> V_22 . type = V_148 ;
V_2 -> V_22 . V_82 . V_9 = F_3 ( V_2 , V_250 ) ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_150 ;
V_2 -> V_25 . V_34 = V_2 -> V_25 . V_150 ;
}
return V_94 ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_245 . V_34 ;
unsigned short V_38 ;
int V_95 ;
memcpy ( & V_38 , V_2 -> V_22 . V_266 + V_2 -> V_97 , 2 ) ;
V_95 = F_87 ( V_2 , V_38 , V_52 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
return V_95 ;
}
static int F_117 ( struct V_1 * V_2 )
{
V_37 V_273 , V_274 , V_275 , V_276 ;
V_273 = 0x80000001 ;
V_275 = 0 ;
V_2 -> V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
return V_276 & F_118 ( V_278 ) ;
}
static void F_119 ( struct V_39 * V_49 , V_37 V_126 )
{
V_49 -> V_51 = ( V_126 >> 23 ) & 1 ;
V_49 -> V_45 = ( V_126 >> 22 ) & 1 ;
V_49 -> V_101 = ( V_126 >> 21 ) & 1 ;
V_49 -> V_279 = ( V_126 >> 20 ) & 1 ;
V_49 -> V_118 = ( V_126 >> 15 ) & 1 ;
V_49 -> V_209 = ( V_126 >> 13 ) & 3 ;
V_49 -> V_219 = ( V_126 >> 12 ) & 1 ;
V_49 -> type = ( V_126 >> 8 ) & 15 ;
}
static int F_120 ( struct V_1 * V_2 , T_2 V_280 , int V_190 )
{
struct V_39 V_49 ;
int V_281 ;
V_36 V_70 ;
V_70 = F_121 ( V_37 , V_280 , 0x7fa8 + V_190 * 4 ) ;
if ( V_190 < 3 )
V_281 = 0x7f84 + V_190 * 12 ;
else
V_281 = 0x7f2c + ( V_190 - 3 ) * 12 ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , V_281 + 8 ) ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , V_281 + 4 ) ) ;
F_119 ( & V_49 , F_121 ( V_37 , V_280 , V_281 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_190 ) ;
return V_94 ;
}
static int F_122 ( struct V_1 * V_2 , T_2 V_280 , int V_190 )
{
struct V_39 V_49 ;
int V_281 ;
V_36 V_70 ;
V_37 V_72 ;
V_281 = 0x7e00 + V_190 * 16 ;
V_70 = F_121 ( V_36 , V_280 , V_281 ) ;
F_119 ( & V_49 , F_121 ( V_36 , V_280 , V_281 + 2 ) << 8 ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , V_281 + 4 ) ) ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , V_281 + 8 ) ) ;
V_72 = F_121 ( V_37 , V_280 , V_281 + 12 ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_190 ) ;
return V_94 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_2 V_282 , T_2 V_283 )
{
int V_92 ;
V_92 = V_2 -> V_6 -> V_284 ( V_2 , 4 , V_283 & ~ V_285 ) ;
if ( V_92 )
return V_223 ;
V_92 = V_2 -> V_6 -> V_284 ( V_2 , 0 , V_282 ) ;
if ( V_92 )
return V_223 ;
if ( V_283 & V_285 ) {
V_92 = V_2 -> V_6 -> V_284 ( V_2 , 4 , V_283 ) ;
if ( V_92 )
return V_223 ;
}
return V_94 ;
}
static int F_124 ( struct V_1 * V_2 , T_2 V_280 )
{
struct V_39 V_49 ;
struct V_197 V_198 ;
V_36 V_70 ;
V_37 V_34 , V_282 , V_283 ;
int V_286 ;
V_282 = F_121 ( V_37 , V_280 , 0x7ffc ) ;
V_2 -> V_6 -> V_284 ( V_2 , 3 , F_121 ( V_37 , V_280 , 0x7ff8 ) ) ;
V_2 -> V_193 = F_121 ( V_37 , V_280 , 0x7ff4 ) | V_259 ;
V_2 -> V_98 = F_121 ( V_37 , V_280 , 0x7ff0 ) ;
for ( V_286 = 0 ; V_286 < 8 ; V_286 ++ )
* F_2 ( V_2 , V_286 ) = F_121 ( V_37 , V_280 , 0x7fd0 + V_286 * 4 ) ;
V_34 = F_121 ( V_37 , V_280 , 0x7fcc ) ;
V_2 -> V_6 -> V_287 ( V_2 , 6 , ( V_34 & V_288 ) | V_289 ) ;
V_34 = F_121 ( V_37 , V_280 , 0x7fc8 ) ;
V_2 -> V_6 -> V_287 ( V_2 , 7 , ( V_34 & V_290 ) | V_291 ) ;
V_70 = F_121 ( V_37 , V_280 , 0x7fc4 ) ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f64 ) ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f60 ) ) ;
F_119 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f5c ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_220 ) ;
V_70 = F_121 ( V_37 , V_280 , 0x7fc0 ) ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f80 ) ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f7c ) ) ;
F_119 ( & V_49 , F_121 ( V_37 , V_280 , 0x7f78 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_201 ) ;
V_198 . V_121 = F_121 ( V_37 , V_280 , 0x7f74 ) ;
V_198 . V_74 = F_121 ( V_37 , V_280 , 0x7f70 ) ;
V_2 -> V_6 -> V_292 ( V_2 , & V_198 ) ;
V_198 . V_121 = F_121 ( V_37 , V_280 , 0x7f58 ) ;
V_198 . V_74 = F_121 ( V_37 , V_280 , 0x7f54 ) ;
V_2 -> V_6 -> V_293 ( V_2 , & V_198 ) ;
for ( V_286 = 0 ; V_286 < 6 ; V_286 ++ ) {
int V_294 = F_120 ( V_2 , V_280 , V_286 ) ;
if ( V_294 != V_94 )
return V_294 ;
}
V_283 = F_121 ( V_37 , V_280 , 0x7f14 ) ;
V_2 -> V_6 -> V_295 ( V_2 , F_121 ( V_37 , V_280 , 0x7ef8 ) ) ;
return F_123 ( V_2 , V_282 , V_283 ) ;
}
static int F_125 ( struct V_1 * V_2 , T_2 V_280 )
{
struct V_39 V_49 ;
struct V_197 V_198 ;
T_2 V_34 , V_282 , V_283 ;
V_37 V_72 ;
V_36 V_70 ;
int V_286 , V_294 ;
for ( V_286 = 0 ; V_286 < 16 ; V_286 ++ )
* F_2 ( V_2 , V_286 ) = F_121 ( T_2 , V_280 , 0x7ff8 - V_286 * 8 ) ;
V_2 -> V_98 = F_121 ( T_2 , V_280 , 0x7f78 ) ;
V_2 -> V_193 = F_121 ( V_37 , V_280 , 0x7f70 ) | V_259 ;
V_34 = F_121 ( V_37 , V_280 , 0x7f68 ) ;
V_2 -> V_6 -> V_287 ( V_2 , 6 , ( V_34 & V_288 ) | V_289 ) ;
V_34 = F_121 ( V_37 , V_280 , 0x7f60 ) ;
V_2 -> V_6 -> V_287 ( V_2 , 7 , ( V_34 & V_290 ) | V_291 ) ;
V_282 = F_121 ( T_2 , V_280 , 0x7f58 ) ;
V_2 -> V_6 -> V_284 ( V_2 , 3 , F_121 ( T_2 , V_280 , 0x7f50 ) ) ;
V_283 = F_121 ( T_2 , V_280 , 0x7f48 ) ;
V_2 -> V_6 -> V_295 ( V_2 , F_121 ( V_37 , V_280 , 0x7f00 ) ) ;
V_34 = F_121 ( T_2 , V_280 , 0x7ed0 ) ;
V_2 -> V_6 -> V_296 ( V_2 , V_104 , V_34 & ~ V_105 ) ;
V_70 = F_121 ( V_37 , V_280 , 0x7e90 ) ;
F_119 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e92 ) << 8 ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e94 ) ) ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e98 ) ) ;
V_72 = F_121 ( V_37 , V_280 , 0x7e9c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_220 ) ;
V_198 . V_74 = F_121 ( V_37 , V_280 , 0x7e84 ) ;
V_198 . V_121 = F_121 ( T_2 , V_280 , 0x7e88 ) ;
V_2 -> V_6 -> V_293 ( V_2 , & V_198 ) ;
V_70 = F_121 ( V_37 , V_280 , 0x7e70 ) ;
F_119 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e72 ) << 8 ) ;
F_86 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e74 ) ) ;
F_85 ( & V_49 , F_121 ( V_37 , V_280 , 0x7e78 ) ) ;
V_72 = F_121 ( V_37 , V_280 , 0x7e7c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_201 ) ;
V_198 . V_74 = F_121 ( V_37 , V_280 , 0x7e64 ) ;
V_198 . V_121 = F_121 ( T_2 , V_280 , 0x7e68 ) ;
V_2 -> V_6 -> V_292 ( V_2 , & V_198 ) ;
V_294 = F_123 ( V_2 , V_282 , V_283 ) ;
if ( V_294 != V_94 )
return V_294 ;
for ( V_286 = 0 ; V_286 < 6 ; V_286 ++ ) {
V_294 = F_122 ( V_2 , V_280 , V_286 ) ;
if ( V_294 != V_94 )
return V_294 ;
}
return V_94 ;
}
static int F_126 ( struct V_1 * V_2 )
{
unsigned long V_282 , V_283 , V_102 ;
T_2 V_280 ;
int V_215 ;
if ( ( V_2 -> V_297 & V_298 ) == 0 )
return F_27 ( V_2 ) ;
V_283 = V_2 -> V_6 -> V_134 ( V_2 , 4 ) ;
if ( F_117 ( V_2 ) ) {
struct V_39 V_99 ;
if ( V_283 & V_285 ) {
V_2 -> V_6 -> V_284 ( V_2 , 4 , V_283 & ~ V_285 ) ;
V_283 &= ~ V_285 ;
}
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . type = 0xb ;
V_99 . V_219 = V_99 . V_51 = V_99 . V_118 = 1 ;
V_2 -> V_6 -> V_73 ( V_2 , 0 , & V_99 , 0 , V_96 ) ;
}
V_282 = V_2 -> V_6 -> V_134 ( V_2 , 0 ) ;
if ( V_282 & V_299 )
V_2 -> V_6 -> V_284 ( V_2 , 0 , V_282 & ~ ( V_300 | V_299 ) ) ;
if ( V_283 & V_301 )
V_2 -> V_6 -> V_284 ( V_2 , 4 , V_283 & ~ V_301 ) ;
V_102 = 0 ;
V_2 -> V_6 -> V_296 ( V_2 , V_104 , V_102 ) ;
V_280 = V_2 -> V_6 -> V_302 ( V_2 ) ;
if ( F_117 ( V_2 ) )
V_215 = F_125 ( V_2 , V_280 + 0x8000 ) ;
else
V_215 = F_124 ( V_2 , V_280 + 0x8000 ) ;
if ( V_215 != V_94 ) {
return V_223 ;
}
if ( ( V_2 -> V_297 & V_303 ) == 0 )
V_2 -> V_6 -> V_264 ( V_2 , false ) ;
V_2 -> V_297 &= ~ V_303 ;
V_2 -> V_297 &= ~ V_298 ;
return V_94 ;
}
static void
F_127 ( struct V_1 * V_2 ,
struct V_39 * V_255 , struct V_39 * V_40 )
{
V_255 -> V_101 = 0 ;
F_85 ( V_255 , 0 ) ;
V_255 -> V_51 = 1 ;
F_86 ( V_255 , 0xfffff ) ;
V_255 -> type = 0x0b ;
V_255 -> V_219 = 1 ;
V_255 -> V_209 = 0 ;
V_255 -> V_118 = 1 ;
V_255 -> V_45 = 1 ;
V_255 -> V_279 = 0 ;
F_85 ( V_40 , 0 ) ;
F_86 ( V_40 , 0xfffff ) ;
V_40 -> V_51 = 1 ;
V_40 -> V_219 = 1 ;
V_40 -> type = 0x03 ;
V_40 -> V_45 = 1 ;
V_40 -> V_209 = 0 ;
V_40 -> V_118 = 1 ;
V_40 -> V_101 = 0 ;
V_40 -> V_279 = 0 ;
}
static bool F_128 ( struct V_1 * V_2 )
{
V_37 V_273 , V_274 , V_275 , V_276 ;
V_273 = V_275 = 0 ;
V_2 -> V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
return V_274 == V_304
&& V_275 == V_305
&& V_276 == V_306 ;
}
static bool F_129 ( struct V_1 * V_2 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
V_37 V_273 , V_274 , V_275 , V_276 ;
if ( V_2 -> V_41 == V_42 )
return true ;
V_273 = 0x00000000 ;
V_275 = 0x00000000 ;
V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
if ( V_274 == V_304 &&
V_275 == V_305 &&
V_276 == V_306 )
return false ;
if ( V_274 == V_307 &&
V_275 == V_308 &&
V_276 == V_309 )
return true ;
if ( V_274 == V_310 &&
V_275 == V_311 &&
V_276 == V_312 )
return true ;
return false ;
}
static int F_130 ( struct V_1 * V_2 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_39 V_255 , V_40 ;
T_2 V_313 ;
V_36 V_314 , V_315 ;
T_2 V_102 = 0 ;
if ( V_2 -> V_41 == V_93 ||
V_2 -> V_41 == V_218 )
return F_27 ( V_2 ) ;
if ( ! ( F_129 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
F_127 ( V_2 , & V_255 , & V_40 ) ;
if ( ! ( V_102 & V_316 ) )
return F_27 ( V_2 ) ;
V_6 -> V_103 ( V_2 , V_317 , & V_313 ) ;
V_313 >>= 32 ;
V_314 = ( V_36 ) ( V_313 & 0xfffc ) ;
V_315 = ( V_36 ) ( V_313 + 8 ) ;
if ( V_102 & V_105 ) {
V_255 . V_45 = 0 ;
V_255 . V_101 = 1 ;
}
V_6 -> V_73 ( V_2 , V_314 , & V_255 , 0 , V_96 ) ;
V_6 -> V_73 ( V_2 , V_315 , & V_40 , 0 , V_44 ) ;
* F_2 ( V_2 , V_192 ) = V_2 -> V_98 ;
if ( V_102 & V_105 ) {
#ifdef F_42
* F_2 ( V_2 , V_318 ) = V_2 -> V_193 ;
V_6 -> V_103 ( V_2 ,
V_2 -> V_41 == V_42 ?
V_319 : V_320 , & V_313 ) ;
V_2 -> V_98 = V_313 ;
V_6 -> V_103 ( V_2 , V_321 , & V_313 ) ;
V_2 -> V_193 &= ~ V_313 ;
V_2 -> V_193 |= V_259 ;
#endif
} else {
V_6 -> V_103 ( V_2 , V_317 , & V_313 ) ;
V_2 -> V_98 = ( V_37 ) V_313 ;
V_2 -> V_193 &= ~ ( V_251 | V_129 ) ;
}
return V_94 ;
}
static int F_131 ( struct V_1 * V_2 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_39 V_255 , V_40 ;
T_2 V_313 ;
V_36 V_314 , V_315 ;
T_2 V_102 = 0 ;
V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( V_2 -> V_41 == V_93 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_41 != V_42 ) && ( V_102 & V_105 )
&& ! F_128 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 )
return V_223 ;
F_127 ( V_2 , & V_255 , & V_40 ) ;
V_6 -> V_103 ( V_2 , V_322 , & V_313 ) ;
if ( ( V_313 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_193 &= ~ ( V_251 | V_129 ) ;
V_314 = ( V_36 ) V_313 & ~ V_323 ;
V_315 = V_314 + 8 ;
if ( V_102 & V_105 ) {
V_255 . V_45 = 0 ;
V_255 . V_101 = 1 ;
}
V_6 -> V_73 ( V_2 , V_314 , & V_255 , 0 , V_96 ) ;
V_6 -> V_73 ( V_2 , V_315 , & V_40 , 0 , V_44 ) ;
V_6 -> V_103 ( V_2 , V_324 , & V_313 ) ;
V_2 -> V_98 = ( V_102 & V_105 ) ? V_313 : ( V_37 ) V_313 ;
V_6 -> V_103 ( V_2 , V_325 , & V_313 ) ;
* F_2 ( V_2 , V_48 ) = ( V_102 & V_105 ) ? V_313 :
( V_37 ) V_313 ;
return V_94 ;
}
static int F_132 ( struct V_1 * V_2 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_39 V_255 , V_40 ;
T_2 V_313 , V_326 , V_327 ;
int V_328 ;
V_36 V_314 = 0 , V_315 = 0 ;
if ( V_2 -> V_41 == V_93 ||
V_2 -> V_41 == V_218 )
return F_25 ( V_2 , 0 ) ;
F_127 ( V_2 , & V_255 , & V_40 ) ;
if ( ( V_2 -> V_120 & 0x8 ) != 0x0 )
V_328 = V_42 ;
else
V_328 = V_106 ;
V_326 = F_1 ( V_2 , V_192 ) ;
V_327 = F_1 ( V_2 , V_270 ) ;
V_255 . V_209 = 3 ;
V_40 . V_209 = 3 ;
V_6 -> V_103 ( V_2 , V_322 , & V_313 ) ;
switch ( V_328 ) {
case V_106 :
V_314 = ( V_36 ) ( V_313 + 16 ) ;
if ( ( V_313 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_315 = ( V_36 ) ( V_313 + 24 ) ;
V_326 = ( V_37 ) V_326 ;
V_327 = ( V_37 ) V_327 ;
break;
case V_42 :
V_314 = ( V_36 ) ( V_313 + 32 ) ;
if ( V_313 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_315 = V_314 + 8 ;
V_255 . V_45 = 0 ;
V_255 . V_101 = 1 ;
if ( F_36 ( V_326 ) ||
F_36 ( V_327 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
V_314 |= V_323 ;
V_315 |= V_323 ;
V_6 -> V_73 ( V_2 , V_314 , & V_255 , 0 , V_96 ) ;
V_6 -> V_73 ( V_2 , V_315 , & V_40 , 0 , V_44 ) ;
V_2 -> V_98 = V_327 ;
* F_2 ( V_2 , V_48 ) = V_326 ;
return V_94 ;
}
static bool F_133 ( struct V_1 * V_2 )
{
int V_230 ;
if ( V_2 -> V_41 == V_93 )
return false ;
if ( V_2 -> V_41 == V_218 )
return true ;
V_230 = ( V_2 -> V_193 & V_231 ) >> V_232 ;
return V_2 -> V_6 -> V_204 ( V_2 ) > V_230 ;
}
static bool F_134 ( struct V_1 * V_2 ,
V_36 V_187 , V_36 V_228 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_39 V_329 ;
V_37 V_72 ;
int V_294 ;
V_36 V_330 , V_331 , V_332 , V_333 = V_187 & 0x7 ;
unsigned V_33 = ( 1 << V_228 ) - 1 ;
unsigned long V_334 ;
V_6 -> V_43 ( V_2 , & V_330 , & V_329 , & V_72 , V_220 ) ;
if ( ! V_329 . V_118 )
return false ;
if ( F_19 ( & V_329 ) < 103 )
return false ;
V_334 = F_80 ( & V_329 ) ;
#ifdef F_42
V_334 |= ( ( T_2 ) V_72 ) << 32 ;
#endif
V_294 = V_6 -> V_109 ( V_2 , V_334 + 102 , & V_331 , 2 , NULL ) ;
if ( V_294 != V_94 )
return false ;
if ( V_331 + V_187 / 8 > F_19 ( & V_329 ) )
return false ;
V_294 = V_6 -> V_109 ( V_2 , V_334 + V_331 + V_187 / 8 , & V_332 , 2 , NULL ) ;
if ( V_294 != V_94 )
return false ;
if ( ( V_332 >> V_333 ) & V_33 )
return false ;
return true ;
}
static bool F_135 ( struct V_1 * V_2 ,
V_36 V_187 , V_36 V_228 )
{
if ( V_2 -> V_335 )
return true ;
if ( F_133 ( V_2 ) )
if ( ! F_134 ( V_2 , V_187 , V_228 ) )
return false ;
V_2 -> V_335 = true ;
return true ;
}
static void F_136 ( struct V_1 * V_2 )
{
#ifdef F_42
if ( V_2 -> V_29 != 4 || ! F_128 ( V_2 ) )
return;
* F_2 ( V_2 , V_192 ) = 0 ;
switch ( V_2 -> V_140 ) {
case 0xa4 :
case 0xa5 :
* F_3 ( V_2 , V_166 ) &= ( V_37 ) - 1 ;
case 0xaa :
case 0xab :
* F_3 ( V_2 , V_168 ) &= ( V_37 ) - 1 ;
}
#endif
}
static void F_137 ( struct V_1 * V_2 ,
struct V_336 * V_337 )
{
V_337 -> V_338 = V_2 -> V_98 ;
V_337 -> V_339 = V_2 -> V_193 ;
V_337 -> V_340 = F_1 ( V_2 , V_250 ) ;
V_337 -> V_341 = F_1 ( V_2 , V_192 ) ;
V_337 -> V_342 = F_1 ( V_2 , V_270 ) ;
V_337 -> V_162 = F_1 ( V_2 , V_163 ) ;
V_337 -> V_343 = F_1 ( V_2 , V_48 ) ;
V_337 -> V_164 = F_1 ( V_2 , V_152 ) ;
V_337 -> V_165 = F_1 ( V_2 , V_166 ) ;
V_337 -> V_167 = F_1 ( V_2 , V_168 ) ;
V_337 -> V_344 = F_31 ( V_2 , V_345 ) ;
V_337 -> V_255 = F_31 ( V_2 , V_96 ) ;
V_337 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_337 -> V_346 = F_31 ( V_2 , V_159 ) ;
V_337 -> V_347 = F_31 ( V_2 , V_201 ) ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_336 * V_337 )
{
int V_215 ;
V_35 V_204 ;
V_2 -> V_98 = V_337 -> V_338 ;
V_2 -> V_193 = V_337 -> V_339 | 2 ;
* F_2 ( V_2 , V_250 ) = V_337 -> V_340 ;
* F_2 ( V_2 , V_192 ) = V_337 -> V_341 ;
* F_2 ( V_2 , V_270 ) = V_337 -> V_342 ;
* F_2 ( V_2 , V_163 ) = V_337 -> V_162 ;
* F_2 ( V_2 , V_48 ) = V_337 -> V_343 ;
* F_2 ( V_2 , V_152 ) = V_337 -> V_164 ;
* F_2 ( V_2 , V_166 ) = V_337 -> V_165 ;
* F_2 ( V_2 , V_168 ) = V_337 -> V_167 ;
F_32 ( V_2 , V_337 -> V_347 , V_201 ) ;
F_32 ( V_2 , V_337 -> V_344 , V_345 ) ;
F_32 ( V_2 , V_337 -> V_255 , V_96 ) ;
F_32 ( V_2 , V_337 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_337 -> V_346 , V_159 ) ;
V_204 = V_337 -> V_255 & 3 ;
V_215 = F_84 ( V_2 , V_337 -> V_347 , V_201 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_344 , V_345 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_255 , V_96 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_40 , V_44 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_346 , V_159 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
return V_94 ;
}
static int F_139 ( struct V_1 * V_2 ,
V_36 V_348 , V_36 V_349 ,
T_1 V_350 , struct V_39 * V_265 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_336 V_351 ;
int V_215 ;
V_37 V_352 = F_80 ( V_265 ) ;
V_215 = V_6 -> V_109 ( V_2 , V_350 , & V_351 , sizeof V_351 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
F_137 ( V_2 , & V_351 ) ;
V_215 = V_6 -> V_110 ( V_2 , V_350 , & V_351 , sizeof V_351 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = V_6 -> V_109 ( V_2 , V_352 , & V_351 , sizeof V_351 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
if ( V_349 != 0xffff ) {
V_351 . V_353 = V_349 ;
V_215 = V_6 -> V_110 ( V_2 , V_352 ,
& V_351 . V_353 ,
sizeof V_351 . V_353 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
}
return F_138 ( V_2 , & V_351 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
struct V_354 * V_337 )
{
V_337 -> V_31 = V_2 -> V_98 ;
V_337 -> V_193 = V_2 -> V_193 ;
V_337 -> V_273 = F_1 ( V_2 , V_250 ) ;
V_337 -> V_275 = F_1 ( V_2 , V_192 ) ;
V_337 -> V_276 = F_1 ( V_2 , V_270 ) ;
V_337 -> V_274 = F_1 ( V_2 , V_163 ) ;
V_337 -> V_355 = F_1 ( V_2 , V_48 ) ;
V_337 -> V_356 = F_1 ( V_2 , V_152 ) ;
V_337 -> V_357 = F_1 ( V_2 , V_166 ) ;
V_337 -> V_358 = F_1 ( V_2 , V_168 ) ;
V_337 -> V_344 = F_31 ( V_2 , V_345 ) ;
V_337 -> V_255 = F_31 ( V_2 , V_96 ) ;
V_337 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_337 -> V_346 = F_31 ( V_2 , V_159 ) ;
V_337 -> V_359 = F_31 ( V_2 , V_53 ) ;
V_337 -> V_360 = F_31 ( V_2 , V_217 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_354 * V_337 )
{
int V_215 ;
V_35 V_204 ;
if ( V_2 -> V_6 -> V_284 ( V_2 , 3 , V_337 -> V_361 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_98 = V_337 -> V_31 ;
V_2 -> V_193 = V_337 -> V_193 | 2 ;
* F_2 ( V_2 , V_250 ) = V_337 -> V_273 ;
* F_2 ( V_2 , V_192 ) = V_337 -> V_275 ;
* F_2 ( V_2 , V_270 ) = V_337 -> V_276 ;
* F_2 ( V_2 , V_163 ) = V_337 -> V_274 ;
* F_2 ( V_2 , V_48 ) = V_337 -> V_355 ;
* F_2 ( V_2 , V_152 ) = V_337 -> V_356 ;
* F_2 ( V_2 , V_166 ) = V_337 -> V_357 ;
* F_2 ( V_2 , V_168 ) = V_337 -> V_358 ;
F_32 ( V_2 , V_337 -> V_362 , V_201 ) ;
F_32 ( V_2 , V_337 -> V_344 , V_345 ) ;
F_32 ( V_2 , V_337 -> V_255 , V_96 ) ;
F_32 ( V_2 , V_337 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_337 -> V_346 , V_159 ) ;
F_32 ( V_2 , V_337 -> V_359 , V_53 ) ;
F_32 ( V_2 , V_337 -> V_360 , V_217 ) ;
if ( V_2 -> V_193 & V_251 ) {
V_2 -> V_41 = V_218 ;
V_204 = 3 ;
} else {
V_2 -> V_41 = V_106 ;
V_204 = V_337 -> V_255 & 3 ;
}
V_215 = F_84 ( V_2 , V_337 -> V_362 , V_201 ,
V_204 , V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_344 , V_345 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_255 , V_96 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_40 , V_44 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_346 , V_159 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_359 , V_53 , V_204 ,
V_221 , NULL ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_84 ( V_2 , V_337 -> V_360 , V_217 , V_204 ,
V_221 , NULL ) ;
return V_215 ;
}
static int F_142 ( struct V_1 * V_2 ,
V_36 V_348 , V_36 V_349 ,
T_1 V_350 , struct V_39 * V_265 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_354 V_351 ;
int V_215 ;
V_37 V_352 = F_80 ( V_265 ) ;
V_37 V_363 = F_143 ( struct V_354 , V_31 ) ;
V_37 V_364 = F_143 ( struct V_354 , V_362 ) ;
V_215 = V_6 -> V_109 ( V_2 , V_350 , & V_351 , sizeof V_351 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
F_140 ( V_2 , & V_351 ) ;
V_215 = V_6 -> V_110 ( V_2 , V_350 + V_363 , & V_351 . V_31 ,
V_364 - V_363 , & V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = V_6 -> V_109 ( V_2 , V_352 , & V_351 , sizeof V_351 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
if ( V_349 != 0xffff ) {
V_351 . V_353 = V_349 ;
V_215 = V_6 -> V_110 ( V_2 , V_352 ,
& V_351 . V_353 ,
sizeof V_351 . V_353 ,
& V_2 -> V_57 ) ;
if ( V_215 != V_94 )
return V_215 ;
}
return F_141 ( V_2 , & V_351 ) ;
}
static int F_144 ( struct V_1 * V_2 ,
V_36 V_348 , int V_365 , int V_366 ,
bool V_367 , V_37 V_59 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
struct V_39 V_368 , V_369 ;
int V_215 ;
V_36 V_349 = F_31 ( V_2 , V_220 ) ;
T_1 V_350 =
V_6 -> V_54 ( V_2 , V_220 ) ;
V_37 V_370 ;
T_1 V_214 , V_371 ;
V_215 = F_82 ( V_2 , V_348 , & V_369 , & V_214 ) ;
if ( V_215 != V_94 )
return V_215 ;
V_215 = F_82 ( V_2 , V_349 , & V_368 , & V_214 ) ;
if ( V_215 != V_94 )
return V_215 ;
if ( V_366 == V_372 ) {
if ( V_365 != - 1 ) {
struct V_39 V_373 ;
int V_209 ;
V_215 = F_78 ( V_2 , V_365 ,
& V_373 ) ;
if ( V_215 != V_94 )
return V_215 ;
V_209 = V_373 . V_209 ;
if ( ( V_348 & 3 ) > V_209 || V_6 -> V_204 ( V_2 ) > V_209 )
return F_25 ( V_2 , ( V_365 << 3 ) | 0x2 ) ;
}
}
V_370 = F_19 ( & V_369 ) ;
if ( ! V_369 . V_118 ||
( ( V_370 < 0x67 && ( V_369 . type & 8 ) ) ||
V_370 < 0x2b ) ) {
return F_28 ( V_2 , V_348 & 0xfffc ) ;
}
if ( V_366 == V_374 || V_366 == V_375 ) {
V_368 . type &= ~ ( 1 << 1 ) ;
F_83 ( V_2 , V_349 , & V_368 ) ;
}
if ( V_366 == V_374 )
V_2 -> V_193 = V_2 -> V_193 & ~ V_240 ;
if ( V_366 != V_376 && V_366 != V_372 )
V_349 = 0xffff ;
if ( V_369 . type & 8 )
V_215 = F_142 ( V_2 , V_348 , V_349 ,
V_350 , & V_369 ) ;
else
V_215 = F_139 ( V_2 , V_348 , V_349 ,
V_350 , & V_369 ) ;
if ( V_215 != V_94 )
return V_215 ;
if ( V_366 == V_376 || V_366 == V_372 )
V_2 -> V_193 = V_2 -> V_193 | V_240 ;
if ( V_366 != V_374 ) {
V_369 . type |= ( 1 << 1 ) ;
F_83 ( V_2 , V_348 , & V_369 ) ;
}
V_6 -> V_284 ( V_2 , 0 , V_6 -> V_134 ( V_2 , 0 ) | V_135 ) ;
V_6 -> V_73 ( V_2 , V_348 , & V_369 , 0 , V_220 ) ;
if ( V_367 ) {
V_2 -> V_97 = V_2 -> V_29 = ( V_369 . type & 8 ) ? 4 : 2 ;
V_2 -> V_226 = 0 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_59 ;
V_215 = F_91 ( V_2 ) ;
}
V_6 -> V_377 ( V_2 , 7 , & V_371 ) ;
V_6 -> V_287 ( V_2 , 7 , V_371 & ~ ( V_378 | V_379 ) ) ;
return V_215 ;
}
int F_145 ( struct V_1 * V_2 ,
V_36 V_348 , int V_365 , int V_366 ,
bool V_367 , V_37 V_59 )
{
int V_95 ;
F_6 ( V_2 ) ;
V_2 -> V_98 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_122 ;
V_95 = F_144 ( V_2 , V_348 , V_365 , V_366 ,
V_367 , V_59 ) ;
if ( V_95 == V_94 ) {
V_2 -> V_31 = V_2 -> V_98 ;
F_4 ( V_2 ) ;
}
return ( V_95 == V_223 ) ? V_380 : V_381 ;
}
static void F_146 ( struct V_1 * V_2 , int V_9 ,
struct V_130 * V_131 )
{
int V_382 = ( V_2 -> V_193 & V_194 ) ? - V_131 -> V_191 : V_131 -> V_191 ;
F_17 ( V_2 , V_9 , V_382 * V_131 -> V_27 ) ;
V_131 -> V_82 . V_173 . V_91 = F_15 ( V_2 , V_9 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
V_35 V_383 , V_384 ;
bool V_385 , V_386 , V_387 ;
V_386 = V_2 -> V_193 & V_233 ;
V_383 = V_2 -> V_25 . V_34 ;
V_384 = V_383 ;
V_387 = V_386 ;
V_386 = false ;
V_385 = V_2 -> V_193 & V_235 ;
if ( ( V_383 & 0x0f ) > 9 || V_385 ) {
V_383 -= 6 ;
V_386 = V_387 | ( V_383 >= 250 ) ;
V_385 = true ;
} else {
V_385 = false ;
}
if ( V_384 > 0x99 || V_387 ) {
V_383 -= 0x60 ;
V_386 = true ;
}
V_2 -> V_25 . V_34 = V_383 ;
V_2 -> V_22 . type = V_388 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_53 ( V_2 , V_389 ) ;
V_2 -> V_193 &= ~ ( V_235 | V_233 ) ;
if ( V_386 )
V_2 -> V_193 |= V_233 ;
if ( V_385 )
V_2 -> V_193 |= V_235 ;
return V_94 ;
}
static int F_148 ( struct V_1 * V_2 )
{
V_35 V_383 , V_390 ;
if ( V_2 -> V_22 . V_34 == 0 )
return F_29 ( V_2 ) ;
V_383 = V_2 -> V_25 . V_34 & 0xff ;
V_390 = V_383 / V_2 -> V_22 . V_34 ;
V_383 %= V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_383 | ( V_390 << 8 ) ;
V_2 -> V_22 . type = V_388 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_53 ( V_2 , V_389 ) ;
return V_94 ;
}
static int F_149 ( struct V_1 * V_2 )
{
V_35 V_383 = V_2 -> V_25 . V_34 & 0xff ;
V_35 V_390 = ( V_2 -> V_25 . V_34 >> 8 ) & 0xff ;
V_383 = ( V_383 + ( V_390 * V_2 -> V_22 . V_34 ) ) & 0xff ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_383 ;
V_2 -> V_22 . type = V_388 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_53 ( V_2 , V_389 ) ;
return V_94 ;
}
static int F_150 ( struct V_1 * V_2 )
{
int V_95 ;
long V_107 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_98 ;
V_95 = F_43 ( V_2 , V_107 ) ;
if ( V_95 != V_94 )
return V_95 ;
return F_91 ( V_2 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
V_36 V_38 , V_391 ;
T_1 V_267 ;
int V_95 ;
struct V_39 V_208 , V_265 ;
const struct V_200 * V_6 = V_2 -> V_6 ;
int V_204 = V_2 -> V_6 -> V_204 ( V_2 ) ;
enum V_86 V_392 = V_2 -> V_41 ;
V_267 = V_2 -> V_98 ;
V_6 -> V_43 ( V_2 , & V_391 , & V_208 , NULL , V_96 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_266 + V_2 -> V_97 , 2 ) ;
V_95 = F_84 ( V_2 , V_38 , V_96 , V_204 ,
V_222 , & V_265 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_41 ( V_2 , V_2 -> V_22 . V_34 , & V_265 ) ;
if ( V_95 != V_94 )
goto V_393;
V_2 -> V_22 . V_34 = V_391 ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 )
goto V_393;
V_2 -> V_22 . V_34 = V_267 ;
V_95 = F_91 ( V_2 ) ;
if ( V_95 != V_94 ) {
F_152 ( L_1 ) ;
goto V_393;
}
return V_95 ;
V_393:
V_6 -> V_73 ( V_2 , V_391 , & V_208 , 0 , V_96 ) ;
V_2 -> V_41 = V_392 ;
return V_95 ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 ;
V_95 = F_92 ( V_2 , & V_31 , V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_40 ( V_2 , V_31 ) ;
if ( V_95 != V_94 )
return V_95 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_94 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_34 ;
F_88 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_150 ;
V_2 -> V_226 = 1 ;
return V_94 ;
}
static int F_155 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = V_2 -> V_245 . V_34 ;
return F_53 ( V_2 , V_394 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_148 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_82 . V_9 = F_3 ( V_2 , V_270 ) ;
V_2 -> V_25 . V_34 = ~ ( ( V_2 -> V_22 . V_34 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_94 ;
}
static int F_157 ( struct V_1 * V_2 )
{
T_2 V_395 = 0 ;
V_2 -> V_6 -> V_103 ( V_2 , V_396 , & V_395 ) ;
* F_2 ( V_2 , V_250 ) = ( V_37 ) V_395 ;
* F_2 ( V_2 , V_270 ) = V_395 >> 32 ;
return V_94 ;
}
static int F_158 ( struct V_1 * V_2 )
{
T_2 V_397 ;
if ( V_2 -> V_6 -> V_398 ( V_2 , F_1 ( V_2 , V_192 ) , & V_397 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_250 ) = ( V_37 ) V_397 ;
* F_2 ( V_2 , V_270 ) = V_397 >> 32 ;
return V_94 ;
}
static int F_159 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_266 , V_2 -> V_22 . V_266 , sizeof( V_2 -> V_22 . V_266 ) ) ;
return V_94 ;
}
static int F_160 ( struct V_1 * V_2 )
{
V_37 V_274 , V_275 , V_276 , V_273 = 1 ;
V_36 V_399 ;
V_2 -> V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
if ( ! ( V_275 & F_161 ( V_400 ) ) )
return F_27 ( V_2 ) ;
switch ( V_2 -> V_97 ) {
case 2 :
V_399 = ( V_36 ) V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 &= ~ 0xffffUL ;
V_2 -> V_25 . V_34 |= ( unsigned long ) F_162 ( V_399 ) ;
break;
case 4 :
V_2 -> V_25 . V_34 = F_163 ( ( V_37 ) V_2 -> V_22 . V_34 ) ;
break;
case 8 :
V_2 -> V_25 . V_34 = F_164 ( V_2 -> V_22 . V_34 ) ;
break;
default:
F_59 () ;
}
return V_94 ;
}
static int F_165 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_284 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_34 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_166 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
if ( V_2 -> V_41 == V_42 )
V_34 = V_2 -> V_22 . V_34 & ~ 0ULL ;
else
V_34 = V_2 -> V_22 . V_34 & ~ 0U ;
if ( V_2 -> V_6 -> V_287 ( V_2 , V_2 -> V_19 , V_34 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_167 ( struct V_1 * V_2 )
{
T_2 V_313 ;
V_313 = ( V_37 ) F_1 ( V_2 , V_250 )
| ( ( T_2 ) F_1 ( V_2 , V_270 ) << 32 ) ;
if ( V_2 -> V_6 -> V_296 ( V_2 , F_1 ( V_2 , V_192 ) , V_313 ) )
return F_25 ( V_2 , 0 ) ;
return V_94 ;
}
static int F_168 ( struct V_1 * V_2 )
{
T_2 V_313 ;
if ( V_2 -> V_6 -> V_103 ( V_2 , F_1 ( V_2 , V_192 ) , & V_313 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_250 ) = ( V_37 ) V_313 ;
* F_2 ( V_2 , V_270 ) = V_313 >> 32 ;
return V_94 ;
}
static int F_169 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_217 )
return F_27 ( V_2 ) ;
V_2 -> V_25 . V_34 = F_31 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_161 )
V_2 -> V_25 . V_27 = 2 ;
return V_94 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
if ( V_2 -> V_19 == V_96 || V_2 -> V_19 > V_217 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_247 = V_248 ;
V_2 -> V_25 . type = V_122 ;
return F_87 ( V_2 , V_38 , V_2 -> V_19 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_122 ;
return F_87 ( V_2 , V_38 , V_201 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_122 ;
return F_87 ( V_2 , V_38 , V_220 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
int V_95 ;
T_1 V_87 ;
V_95 = F_38 ( V_2 , V_2 -> V_22 . V_82 . V_173 , 1 , false , & V_87 ) ;
if ( V_95 == V_94 )
V_2 -> V_6 -> V_401 ( V_2 , V_87 ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_174 ( struct V_1 * V_2 )
{
T_1 V_282 ;
V_282 = V_2 -> V_6 -> V_134 ( V_2 , 0 ) ;
V_282 &= ~ V_135 ;
V_2 -> V_6 -> V_284 ( V_2 , 0 , V_282 ) ;
return V_94 ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_95 = V_2 -> V_6 -> V_402 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_98 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_176 ( struct V_1 * V_2 ,
void (* F_177)( struct V_1 * V_2 ,
struct V_197 * V_116 ) )
{
struct V_197 V_197 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_97 = 8 ;
F_177 ( V_2 , & V_197 ) ;
if ( V_2 -> V_97 == 2 ) {
V_2 -> V_97 = 4 ;
V_197 . V_121 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_122 ;
return F_45 ( V_2 , V_2 -> V_25 . V_82 . V_173 ,
& V_197 , 2 + V_2 -> V_97 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
return F_176 ( V_2 , V_2 -> V_6 -> V_202 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
return F_176 ( V_2 , V_2 -> V_6 -> V_199 ) ;
}
static int F_180 ( struct V_1 * V_2 , bool V_403 )
{
struct V_197 V_197 ;
int V_95 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_97 = 8 ;
V_95 = F_51 ( V_2 , V_2 -> V_22 . V_82 . V_173 ,
& V_197 . V_74 , & V_197 . V_121 ,
V_2 -> V_97 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_2 -> V_41 == V_42 &&
F_36 ( V_197 . V_121 ) )
return F_25 ( V_2 , 0 ) ;
if ( V_403 )
V_2 -> V_6 -> V_292 ( V_2 , & V_197 ) ;
else
V_2 -> V_6 -> V_293 ( V_2 , & V_197 ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_181 ( struct V_1 * V_2 )
{
return F_180 ( V_2 , true ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
return F_180 ( V_2 , false ) ;
}
static int F_183 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_161 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_34 = V_2 -> V_6 -> V_134 ( V_2 , 0 ) ;
return V_94 ;
}
static int F_184 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_284 ( V_2 , 0 , ( V_2 -> V_6 -> V_134 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_34 & 0x0f ) ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_185 ( struct V_1 * V_2 )
{
int V_95 = V_94 ;
F_17 ( V_2 , V_192 , - 1 ) ;
if ( ( F_14 ( V_2 , F_1 ( V_2 , V_192 ) ) != 0 ) &&
( V_2 -> V_140 == 0xe2 || F_55 ( V_2 -> V_140 ^ 0x5 , V_2 -> V_193 ) ) )
V_95 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_95 ;
}
static int F_186 ( struct V_1 * V_2 )
{
int V_95 = V_94 ;
if ( F_14 ( V_2 , F_1 ( V_2 , V_192 ) ) == 0 )
V_95 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_95 ;
}
static int F_187 ( struct V_1 * V_2 )
{
if ( ! F_76 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_34 ,
& V_2 -> V_25 . V_34 ) )
return V_404 ;
return V_94 ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_405 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_34 ,
& V_2 -> V_22 . V_34 , 1 ) ;
V_2 -> V_25 . type = V_122 ;
return V_94 ;
}
static int F_189 ( struct V_1 * V_2 )
{
if ( F_133 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_193 &= ~ V_129 ;
return V_94 ;
}
static int F_190 ( struct V_1 * V_2 )
{
if ( F_133 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_247 = V_406 ;
V_2 -> V_193 |= V_129 ;
return V_94 ;
}
static int F_191 ( struct V_1 * V_2 )
{
V_37 V_273 , V_274 , V_275 , V_276 ;
V_273 = F_1 ( V_2 , V_250 ) ;
V_275 = F_1 ( V_2 , V_192 ) ;
V_2 -> V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
* F_2 ( V_2 , V_250 ) = V_273 ;
* F_2 ( V_2 , V_163 ) = V_274 ;
* F_2 ( V_2 , V_192 ) = V_275 ;
* F_2 ( V_2 , V_270 ) = V_276 ;
return V_94 ;
}
static int F_192 ( struct V_1 * V_2 )
{
V_37 V_126 ;
V_126 = V_233 | V_234 | V_235 | V_236 |
V_237 ;
V_126 &= * F_3 ( V_2 , V_250 ) >> 8 ;
V_2 -> V_193 &= ~ 0xffUL ;
V_2 -> V_193 |= V_126 | V_259 ;
return V_94 ;
}
static int F_193 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_250 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_250 ) |= ( V_2 -> V_193 & 0xff ) << 8 ;
return V_94 ;
}
static int F_194 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_97 ) {
#ifdef F_42
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_94 ;
}
static int F_195 ( struct V_1 * V_2 )
{
return V_94 ;
}
static int F_196 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = ( V_170 ) V_2 -> V_22 . V_34 ;
return V_94 ;
}
static int F_197 ( struct V_1 * V_2 )
{
V_37 V_273 = 1 , V_274 , V_275 = 0 , V_276 ;
V_2 -> V_6 -> V_277 ( V_2 , & V_273 , & V_274 , & V_275 , & V_276 ) ;
if ( ! ( V_276 & F_161 ( V_407 ) ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_6 -> V_134 ( V_2 , 0 ) & ( V_135 | V_136 ) )
return F_30 ( V_2 ) ;
if ( V_2 -> V_41 >= V_42 )
return V_223 ;
return V_94 ;
}
static int F_198 ( struct V_1 * V_2 )
{
struct V_408 V_409 ;
T_6 V_74 ;
int V_95 ;
V_95 = F_197 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
V_95 = F_199 ( L_2 , , [ V_410 ] L_3 ( V_409 ) ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_2 -> V_6 -> V_134 ( V_2 , 4 ) & V_411 )
V_74 = F_143 ( struct V_408 , V_412 [ 8 * 16 / 4 ] ) ;
else
V_74 = F_143 ( struct V_408 , V_412 [ 0 ] ) ;
return F_45 ( V_2 , V_2 -> V_174 . V_82 . V_173 , & V_409 , V_74 ) ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_408 * V_413 )
{
int V_95 = V_94 ;
struct V_408 V_268 ;
V_95 = F_199 ( L_2 , , [ V_410 ] L_3 ( V_268 ) ) ;
if ( V_95 != V_94 )
return V_95 ;
#ifdef F_42
memcpy ( & V_413 -> V_412 [ 8 * 16 / 4 ] , & V_268 . V_412 [ 8 * 16 / 4 ] , 8 * 16 ) ;
#endif
if ( ! ( V_2 -> V_6 -> V_134 ( V_2 , 4 ) & V_411 ) )
memcpy ( V_413 -> V_412 , V_268 . V_412 , 8 * 16 ) ;
return V_95 ;
}
static int F_201 ( struct V_1 * V_2 )
{
struct V_408 V_409 ;
int V_95 ;
V_95 = F_197 ( V_2 ) ;
if ( V_95 != V_94 )
return V_95 ;
V_95 = F_44 ( V_2 , V_2 -> V_174 . V_82 . V_173 , & V_409 , 512 ) ;
if ( V_95 != V_94 )
return V_95 ;
if ( V_409 . V_414 >> 16 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
if ( V_2 -> V_41 < V_42 )
V_95 = F_200 ( V_2 , & V_409 ) ;
if ( V_95 == V_94 )
V_95 = F_199 ( L_4 , : [ V_410 ] L_5 ( V_409 ) ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
return V_95 ;
}
static bool F_202 ( int V_3 )
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
static int F_203 ( struct V_1 * V_2 )
{
if ( ! F_202 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_94 ;
}
static int F_204 ( struct V_1 * V_2 )
{
T_2 V_415 = V_2 -> V_22 . V_23 ;
int V_416 = V_2 -> V_19 ;
T_2 V_102 = 0 ;
static T_2 V_417 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_418 ,
0 , 0 , 0 ,
V_419 ,
} ;
if ( ! F_202 ( V_416 ) )
return F_27 ( V_2 ) ;
if ( V_415 & V_417 [ V_416 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_416 ) {
case 0 : {
T_2 V_283 ;
if ( ( ( V_415 & V_300 ) && ! ( V_415 & V_299 ) ) ||
( ( V_415 & V_420 ) && ! ( V_415 & V_421 ) ) )
return F_25 ( V_2 , 0 ) ;
V_283 = V_2 -> V_6 -> V_134 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( ( V_415 & V_300 ) && ( V_102 & V_422 ) &&
! ( V_283 & V_301 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
T_2 V_423 = 0 ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( V_102 & V_105 )
V_423 = V_424 & ~ V_425 ;
if ( V_415 & V_423 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( ( V_102 & V_105 ) && ! ( V_415 & V_301 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_94 ;
}
static int F_205 ( struct V_1 * V_2 )
{
unsigned long V_371 ;
V_2 -> V_6 -> V_377 ( V_2 , 7 , & V_371 ) ;
return V_371 & ( 1 << 13 ) ;
}
static int F_206 ( struct V_1 * V_2 )
{
int V_426 = V_2 -> V_19 ;
T_2 V_283 ;
if ( V_426 > 7 )
return F_27 ( V_2 ) ;
V_283 = V_2 -> V_6 -> V_134 ( V_2 , 4 ) ;
if ( ( V_283 & V_427 ) && ( V_426 == 4 || V_426 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_205 ( V_2 ) ) {
T_1 V_428 ;
V_2 -> V_6 -> V_377 ( V_2 , 6 , & V_428 ) ;
V_428 &= ~ 15 ;
V_428 |= V_429 | V_430 ;
V_2 -> V_6 -> V_287 ( V_2 , 6 , V_428 ) ;
return F_24 ( V_2 ) ;
}
return V_94 ;
}
static int F_207 ( struct V_1 * V_2 )
{
T_2 V_415 = V_2 -> V_22 . V_23 ;
int V_426 = V_2 -> V_19 ;
if ( ( V_426 == 6 || V_426 == 7 ) && ( V_415 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_206 ( V_2 ) ;
}
static int F_208 ( struct V_1 * V_2 )
{
T_2 V_102 ;
V_2 -> V_6 -> V_103 ( V_2 , V_104 , & V_102 ) ;
if ( ! ( V_102 & V_431 ) )
return F_27 ( V_2 ) ;
return V_94 ;
}
static int F_209 ( struct V_1 * V_2 )
{
T_2 V_432 = F_1 ( V_2 , V_250 ) ;
if ( V_432 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_208 ( V_2 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
T_2 V_283 = V_2 -> V_6 -> V_134 ( V_2 , 4 ) ;
if ( V_283 & V_433 && V_2 -> V_6 -> V_204 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_94 ;
}
static int F_211 ( struct V_1 * V_2 )
{
T_2 V_283 = V_2 -> V_6 -> V_134 ( V_2 , 4 ) ;
T_2 V_326 = F_1 ( V_2 , V_192 ) ;
if ( ( ! ( V_283 & V_434 ) && V_2 -> V_6 -> V_204 ( V_2 ) ) ||
V_2 -> V_6 -> V_435 ( V_2 , V_326 ) )
return F_25 ( V_2 , 0 ) ;
return V_94 ;
}
static int F_212 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_213 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_135 ( V_2 , V_2 -> V_22 . V_34 , V_2 -> V_25 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_94 ;
}
static int F_214 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_213 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_135 ( V_2 , V_2 -> V_25 . V_34 , V_2 -> V_22 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_94 ;
}
static unsigned F_215 ( struct V_1 * V_2 )
{
unsigned V_74 ;
V_74 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
if ( V_74 == 8 )
V_74 = 4 ;
return V_74 ;
}
static int F_216 ( struct V_1 * V_2 , struct V_130 * V_131 ,
unsigned V_74 , bool V_436 )
{
int V_95 = V_94 ;
V_131 -> type = V_388 ;
V_131 -> V_27 = V_74 ;
V_131 -> V_82 . V_173 . V_91 = V_2 -> V_98 ;
switch ( V_131 -> V_27 ) {
case 1 :
V_131 -> V_34 = F_69 ( V_169 , V_2 ) ;
break;
case 2 :
V_131 -> V_34 = F_69 ( V_177 , V_2 ) ;
break;
case 4 :
V_131 -> V_34 = F_69 ( V_170 , V_2 ) ;
break;
case 8 :
V_131 -> V_34 = F_69 ( V_178 , V_2 ) ;
break;
}
if ( ! V_436 ) {
switch ( V_131 -> V_27 ) {
case 1 :
V_131 -> V_34 &= 0xff ;
break;
case 2 :
V_131 -> V_34 &= 0xffff ;
break;
case 4 :
V_131 -> V_34 &= 0xffffffff ;
break;
}
}
V_175:
return V_95 ;
}
static int F_217 ( struct V_1 * V_2 , struct V_130 * V_131 ,
unsigned V_45 )
{
int V_95 = V_94 ;
switch ( V_45 ) {
case V_437 :
F_66 ( V_2 , V_131 ) ;
break;
case V_438 :
V_95 = F_216 ( V_2 , V_131 , 1 , false ) ;
break;
case V_439 :
V_2 -> V_174 . V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_440:
* V_131 = V_2 -> V_174 ;
V_2 -> V_441 = V_131 ;
if ( V_2 -> V_45 & V_442 )
F_71 ( V_2 ) ;
V_131 -> V_150 = V_131 -> V_34 ;
break;
case V_443 :
V_2 -> V_174 . V_27 = ( V_2 -> V_97 == 8 ) ? 16 : 8 ;
goto V_440;
case V_444 :
V_131 -> type = V_148 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_9 = F_3 ( V_2 , V_250 ) ;
F_57 ( V_131 ) ;
V_131 -> V_150 = V_131 -> V_34 ;
break;
case V_445 :
V_131 -> type = V_148 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 2 : V_2 -> V_97 ;
V_131 -> V_82 . V_9 = F_3 ( V_2 , V_250 ) ;
F_57 ( V_131 ) ;
V_131 -> V_150 = V_131 -> V_34 ;
break;
case V_446 :
if ( V_2 -> V_45 & V_149 ) {
V_131 -> type = V_122 ;
break;
}
V_131 -> type = V_148 ;
V_131 -> V_27 = V_2 -> V_97 ;
V_131 -> V_82 . V_9 = F_3 ( V_2 , V_270 ) ;
F_57 ( V_131 ) ;
V_131 -> V_150 = V_131 -> V_34 ;
break;
case V_447 :
V_131 -> type = V_161 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_173 . V_91 =
F_15 ( V_2 , V_168 ) ;
V_131 -> V_82 . V_173 . V_52 = V_345 ;
V_131 -> V_34 = 0 ;
V_131 -> V_191 = 1 ;
break;
case V_448 :
V_131 -> type = V_148 ;
V_131 -> V_27 = 2 ;
V_131 -> V_82 . V_9 = F_3 ( V_2 , V_270 ) ;
F_57 ( V_131 ) ;
break;
case V_449 :
V_131 -> type = V_388 ;
V_131 -> V_27 = 1 ;
V_131 -> V_34 = F_1 ( V_2 , V_192 ) & 0xff ;
break;
case V_450 :
V_95 = F_216 ( V_2 , V_131 , 1 , true ) ;
break;
case V_451 :
V_131 -> type = V_388 ;
V_131 -> V_27 = 1 ;
V_131 -> V_34 = 1 ;
break;
case V_452 :
V_95 = F_216 ( V_2 , V_131 , F_215 ( V_2 ) , true ) ;
break;
case V_453 :
V_95 = F_216 ( V_2 , V_131 , V_2 -> V_97 , true ) ;
break;
case V_454 :
V_2 -> V_174 . V_27 = 1 ;
if ( V_2 -> V_174 . type == V_148 ) {
V_2 -> V_174 . V_82 . V_9 = F_50 ( V_2 ,
V_2 -> V_20 , true ) ;
F_57 ( & V_2 -> V_174 ) ;
}
goto V_440;
case V_455 :
V_2 -> V_174 . V_27 = 2 ;
goto V_440;
case V_456 :
V_2 -> V_174 . V_27 = 4 ;
goto V_440;
case V_457 :
V_95 = F_216 ( V_2 , V_131 , 2 , false ) ;
break;
case V_458 :
V_95 = F_216 ( V_2 , V_131 , F_215 ( V_2 ) , false ) ;
break;
case V_459 :
V_131 -> type = V_161 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_173 . V_91 =
F_15 ( V_2 , V_166 ) ;
V_131 -> V_82 . V_173 . V_52 = V_2 -> V_460 ;
V_131 -> V_34 = 0 ;
V_131 -> V_191 = 1 ;
break;
case V_461 :
V_131 -> type = V_161 ;
V_131 -> V_27 = ( V_2 -> V_45 & V_149 ) ? 1 : V_2 -> V_97 ;
V_131 -> V_82 . V_173 . V_91 =
F_14 ( V_2 ,
F_1 ( V_2 , V_163 ) +
( F_1 ( V_2 , V_250 ) & 0xff ) ) ;
V_131 -> V_82 . V_173 . V_52 = V_2 -> V_460 ;
V_131 -> V_34 = 0 ;
break;
case V_462 :
V_131 -> type = V_388 ;
V_131 -> V_82 . V_173 . V_91 = V_2 -> V_98 ;
V_131 -> V_27 = V_2 -> V_97 + 2 ;
F_218 ( V_131 -> V_266 , V_131 -> V_27 , V_2 ) ;
break;
case V_463 :
V_2 -> V_174 . V_27 = V_2 -> V_97 + 2 ;
goto V_440;
case V_464 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_345 ;
break;
case V_465 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_96 ;
break;
case V_466 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_44 ;
break;
case V_467 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_159 ;
break;
case V_468 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_53 ;
break;
case V_469 :
V_131 -> type = V_388 ;
V_131 -> V_34 = V_217 ;
break;
case V_470 :
default:
V_131 -> type = V_122 ;
break;
}
V_175:
return V_95 ;
}
int F_219 ( struct V_1 * V_2 , void * V_471 , int V_472 )
{
int V_95 = V_94 ;
int V_41 = V_2 -> V_41 ;
int V_473 , V_474 , V_475 , V_476 ;
bool V_477 = false ;
bool V_478 = false ;
struct V_479 V_479 ;
V_2 -> V_174 . type = V_122 ;
V_2 -> V_441 = NULL ;
V_2 -> V_98 = V_2 -> V_31 ;
V_2 -> V_85 . V_116 = V_2 -> V_85 . V_108 ;
V_2 -> V_85 . V_113 = V_2 -> V_85 . V_108 + V_472 ;
V_2 -> V_480 = 1 ;
if ( V_472 > 0 )
memcpy ( V_2 -> V_85 . V_108 , V_471 , V_472 ) ;
else {
V_95 = F_46 ( V_2 , 1 ) ;
if ( V_95 != V_94 )
return V_95 ;
}
switch ( V_41 ) {
case V_93 :
case V_218 :
case V_100 :
V_473 = V_474 = 2 ;
break;
case V_106 :
V_473 = V_474 = 4 ;
break;
#ifdef F_42
case V_42 :
V_473 = 4 ;
V_474 = 8 ;
break;
#endif
default:
return V_380 ;
}
V_2 -> V_97 = V_473 ;
V_2 -> V_29 = V_474 ;
for (; ; ) {
switch ( V_2 -> V_140 = F_69 ( V_35 , V_2 ) ) {
case 0x66 :
V_477 = true ;
V_2 -> V_97 = V_473 ^ 6 ;
break;
case 0x67 :
if ( V_41 == V_42 )
V_2 -> V_29 = V_474 ^ 12 ;
else
V_2 -> V_29 = V_474 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_478 = true ;
V_2 -> V_460 = ( V_2 -> V_140 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_478 = true ;
V_2 -> V_460 = V_2 -> V_140 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_41 != V_42 )
goto V_481;
V_2 -> V_120 = V_2 -> V_140 ;
continue;
case 0xf0 :
V_2 -> V_226 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_140 ;
break;
default:
goto V_481;
}
V_2 -> V_120 = 0 ;
}
V_481:
if ( V_2 -> V_120 & 8 )
V_2 -> V_97 = 8 ;
V_479 = V_482 [ V_2 -> V_140 ] ;
if ( V_2 -> V_140 == 0x0f ) {
V_2 -> V_480 = 2 ;
V_2 -> V_140 = F_69 ( V_35 , V_2 ) ;
V_479 = V_483 [ V_2 -> V_140 ] ;
if ( V_2 -> V_140 == 0x38 ) {
V_2 -> V_480 = 3 ;
V_2 -> V_140 = F_69 ( V_35 , V_2 ) ;
V_479 = V_484 [ V_2 -> V_140 ] ;
}
}
V_2 -> V_45 = V_479 . V_126 ;
if ( V_2 -> V_45 & V_139 )
V_2 -> V_158 = F_69 ( V_35 , V_2 ) ;
if ( V_2 -> V_480 == 1 && ( V_2 -> V_140 == 0xc5 || V_2 -> V_140 == 0xc4 ) &&
( V_41 == V_42 || ( V_2 -> V_158 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_45 = V_485 ;
}
while ( V_2 -> V_45 & V_486 ) {
switch ( V_2 -> V_45 & V_486 ) {
case V_487 :
V_475 = ( V_2 -> V_158 >> 3 ) & 7 ;
V_479 = V_479 . V_488 . V_489 [ V_475 ] ;
break;
case V_490 :
V_475 = ( V_2 -> V_158 >> 3 ) & 7 ;
if ( ( V_2 -> V_158 >> 6 ) == 3 )
V_479 = V_479 . V_488 . V_491 -> V_492 [ V_475 ] ;
else
V_479 = V_479 . V_488 . V_491 -> V_493 [ V_475 ] ;
break;
case V_494 :
V_475 = V_2 -> V_158 & 7 ;
V_479 = V_479 . V_488 . V_489 [ V_475 ] ;
break;
case V_495 :
if ( V_2 -> V_17 && V_477 )
return V_380 ;
V_476 = V_477 ? 0x66 : V_2 -> V_17 ;
switch ( V_476 ) {
case 0x00 : V_479 = V_479 . V_488 . V_496 -> V_497 ; break;
case 0x66 : V_479 = V_479 . V_488 . V_496 -> V_498 ; break;
case 0xf2 : V_479 = V_479 . V_488 . V_496 -> V_499 ; break;
case 0xf3 : V_479 = V_479 . V_488 . V_496 -> V_500 ; break;
}
break;
case V_501 :
if ( V_2 -> V_158 > 0xbf )
V_479 = V_479 . V_488 . V_502 -> V_503 [ V_2 -> V_158 - 0xc0 ] ;
else
V_479 = V_479 . V_488 . V_502 -> V_131 [ ( V_2 -> V_158 >> 3 ) & 7 ] ;
break;
case V_504 :
if ( ( V_2 -> V_158 >> 6 ) == 3 )
V_479 = V_479 . V_488 . V_505 -> V_492 ;
else
V_479 = V_479 . V_488 . V_505 -> V_493 ;
break;
case V_506 :
if ( V_2 -> V_41 == V_42 )
V_479 = V_479 . V_488 . V_507 -> V_508 ;
else
V_479 = V_479 . V_488 . V_507 -> V_509 ;
break;
default:
return V_380 ;
}
V_2 -> V_45 &= ~ ( T_2 ) V_486 ;
V_2 -> V_45 |= V_479 . V_126 ;
}
if ( V_2 -> V_45 == 0 )
return V_380 ;
V_2 -> V_510 = V_479 . V_488 . V_510 ;
if ( F_47 ( V_2 -> V_511 ) && F_34 ( ! ( V_2 -> V_45 & V_512 ) ) )
return V_380 ;
if ( F_47 ( V_2 -> V_45 &
( V_485 | V_513 | V_514 | V_141 | V_145 | V_515 | V_516 | V_517 |
V_518 ) ) ) {
V_2 -> V_519 = V_479 . V_519 ;
V_2 -> V_12 = V_479 . V_12 ;
if ( V_2 -> V_45 & V_485 )
return V_380 ;
if ( V_41 == V_42 ) {
if ( V_2 -> V_97 == 4 && ( V_2 -> V_45 & V_513 ) )
V_2 -> V_97 = 8 ;
else if ( V_2 -> V_45 & V_517 )
V_2 -> V_97 = 8 ;
}
if ( V_2 -> V_45 & V_514 ) {
if ( V_41 == V_42 )
V_2 -> V_97 = 8 ;
else
V_2 -> V_97 = 4 ;
}
if ( ( V_2 -> V_45 & V_518 ) && V_2 -> V_97 == 2 )
V_2 -> V_97 = 4 ;
if ( V_2 -> V_45 & V_141 )
V_2 -> V_97 = 16 ;
else if ( V_2 -> V_45 & V_145 )
V_2 -> V_97 = 8 ;
}
if ( V_2 -> V_45 & V_139 ) {
V_95 = F_68 ( V_2 , & V_2 -> V_174 ) ;
if ( ! V_478 ) {
V_478 = true ;
V_2 -> V_460 = V_2 -> V_153 ;
}
} else if ( V_2 -> V_45 & V_520 )
V_95 = F_70 ( V_2 , & V_2 -> V_174 ) ;
if ( V_95 != V_94 )
goto V_175;
if ( ! V_478 )
V_2 -> V_460 = V_159 ;
V_2 -> V_174 . V_82 . V_173 . V_52 = V_2 -> V_460 ;
V_95 = F_217 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_45 >> V_521 ) & V_522 ) ;
if ( V_95 != V_94 )
goto V_175;
V_95 = F_217 ( V_2 , & V_2 -> V_245 , ( V_2 -> V_45 >> V_523 ) & V_522 ) ;
if ( V_95 != V_94 )
goto V_175;
V_95 = F_217 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_45 >> V_524 ) & V_522 ) ;
if ( V_2 -> V_172 && F_34 ( V_2 -> V_441 ) )
V_2 -> V_441 -> V_82 . V_173 . V_91 = F_14 ( V_2 ,
V_2 -> V_441 -> V_82 . V_173 . V_91 + V_2 -> V_98 ) ;
V_175:
return ( V_95 != V_94 ) ? V_380 : V_381 ;
}
bool F_220 ( struct V_1 * V_2 )
{
return V_2 -> V_45 & V_525 ;
}
static bool F_221 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_140 == 0xa6 ) || ( V_2 -> V_140 == 0xa7 ) ||
( V_2 -> V_140 == 0xae ) || ( V_2 -> V_140 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_526 ) &&
( ( V_2 -> V_193 & V_236 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_527 ) &&
( ( V_2 -> V_193 & V_236 ) == V_236 ) ) ) )
return true ;
return false ;
}
static int F_222 ( struct V_1 * V_2 )
{
int V_95 ;
V_2 -> V_6 -> V_132 ( V_2 ) ;
V_95 = F_199 ( L_6 ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
if ( F_47 ( V_95 != V_94 ) )
return F_22 ( V_2 , V_528 , 0 , false ) ;
return V_94 ;
}
static void F_223 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
if ( V_131 -> type == V_146 )
F_61 ( V_2 , & V_131 -> V_227 , V_131 -> V_82 . V_147 ) ;
}
static int F_53 ( struct V_1 * V_2 , void (* F_56)( struct F_53 * ) )
{
register void * T_7 V_529 ( V_530 ) ;
T_1 V_126 = ( V_2 -> V_193 & V_128 ) | V_129 ;
if ( ! ( V_2 -> V_45 & V_149 ) )
F_56 += F_224 ( V_2 -> V_25 . V_27 ) * V_531 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop), "+r"(__sp)
: "c"(ctxt->src2.val));
V_2 -> V_193 = ( V_2 -> V_193 & ~ V_128 ) | ( V_126 & V_128 ) ;
if ( ! F_56 )
return F_29 ( V_2 ) ;
return V_94 ;
}
void F_225 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_172 , 0 ,
( void * ) & V_2 -> V_158 - ( void * ) & V_2 -> V_172 ) ;
V_2 -> V_188 . V_182 = 0 ;
V_2 -> V_188 . V_113 = 0 ;
V_2 -> V_181 . V_113 = 0 ;
}
int F_226 ( struct V_1 * V_2 )
{
const struct V_200 * V_6 = V_2 -> V_6 ;
int V_95 = V_94 ;
int V_532 = V_2 -> V_25 . type ;
V_2 -> V_181 . V_182 = 0 ;
if ( V_2 -> V_226 && ( ! ( V_2 -> V_45 & V_533 ) || V_2 -> V_25 . type != V_161 ) ) {
V_95 = F_27 ( V_2 ) ;
goto V_175;
}
if ( ( V_2 -> V_45 & V_534 ) == V_535 && V_2 -> V_22 . type != V_161 ) {
V_95 = F_27 ( V_2 ) ;
goto V_175;
}
if ( F_47 ( V_2 -> V_45 &
( V_536 | V_537 | V_141 | V_145 | V_515 | V_516 | V_538 | V_539 | String ) ) ) {
if ( ( V_2 -> V_41 == V_42 && ( V_2 -> V_45 & V_536 ) ) ||
( V_2 -> V_45 & V_537 ) ) {
V_95 = F_27 ( V_2 ) ;
goto V_175;
}
if ( ( ( V_2 -> V_45 & ( V_141 | V_145 ) ) && ( ( V_6 -> V_134 ( V_2 , 0 ) & V_136 ) ) )
|| ( ( V_2 -> V_45 & V_141 ) && ! ( V_6 -> V_134 ( V_2 , 4 ) & V_411 ) ) ) {
V_95 = F_27 ( V_2 ) ;
goto V_175;
}
if ( ( V_2 -> V_45 & ( V_141 | V_145 ) ) && ( V_6 -> V_134 ( V_2 , 0 ) & V_135 ) ) {
V_95 = F_30 ( V_2 ) ;
goto V_175;
}
if ( V_2 -> V_45 & V_145 ) {
V_95 = F_222 ( V_2 ) ;
if ( V_95 != V_94 )
goto V_175;
F_223 ( V_2 , & V_2 -> V_22 ) ;
F_223 ( V_2 , & V_2 -> V_245 ) ;
if ( ! ( V_2 -> V_45 & V_540 ) )
F_223 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_47 ( V_2 -> V_297 & V_541 ) && V_2 -> V_12 ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_542 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( ( V_2 -> V_45 & V_539 ) && V_2 -> V_41 < V_100 ) {
V_95 = F_27 ( V_2 ) ;
goto V_175;
}
if ( ( V_2 -> V_45 & V_538 ) && V_6 -> V_204 ( V_2 ) ) {
if ( V_2 -> V_45 & V_543 )
V_95 = F_27 ( V_2 ) ;
else
V_95 = F_25 ( V_2 , 0 ) ;
goto V_175;
}
if ( V_2 -> V_45 & V_516 ) {
V_95 = V_2 -> V_519 ( V_2 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( F_47 ( V_2 -> V_297 & V_541 ) && ( V_2 -> V_45 & V_515 ) ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_544 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
if ( F_14 ( V_2 , F_1 ( V_2 , V_192 ) ) == 0 ) {
F_136 ( V_2 ) ;
V_2 -> V_31 = V_2 -> V_98 ;
V_2 -> V_193 &= ~ V_258 ;
goto V_175;
}
}
}
if ( ( V_2 -> V_22 . type == V_161 ) && ! ( V_2 -> V_45 & V_545 ) ) {
V_95 = F_73 ( V_2 , V_2 -> V_22 . V_82 . V_173 ,
V_2 -> V_22 . V_266 , V_2 -> V_22 . V_27 ) ;
if ( V_95 != V_94 )
goto V_175;
V_2 -> V_22 . V_269 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_245 . type == V_161 ) {
V_95 = F_73 ( V_2 , V_2 -> V_245 . V_82 . V_173 ,
& V_2 -> V_245 . V_34 , V_2 -> V_245 . V_27 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( ( V_2 -> V_45 & V_546 ) == V_547 )
goto V_548;
if ( ( V_2 -> V_25 . type == V_161 ) && ! ( V_2 -> V_45 & V_540 ) ) {
V_95 = F_73 ( V_2 , V_2 -> V_25 . V_82 . V_173 ,
& V_2 -> V_25 . V_34 , V_2 -> V_25 . V_27 ) ;
if ( V_95 != V_94 ) {
if ( ! ( V_2 -> V_45 & V_549 ) &&
V_95 == V_61 &&
V_2 -> V_57 . V_58 == V_550 )
V_2 -> V_57 . V_59 |= V_551 ;
goto V_175;
}
}
V_2 -> V_25 . V_269 = V_2 -> V_25 . V_23 ;
V_548:
if ( F_47 ( V_2 -> V_297 & V_541 ) && ( V_2 -> V_45 & V_515 ) ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_552 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) )
V_2 -> V_193 |= V_258 ;
else
V_2 -> V_193 &= ~ V_258 ;
if ( V_2 -> V_510 ) {
if ( V_2 -> V_45 & V_553 ) {
void (* F_56)( struct F_53 * ) = ( void * ) V_2 -> V_510 ;
V_95 = F_53 ( V_2 , F_56 ) ;
if ( V_95 != V_94 )
goto V_175;
goto F_89;
}
V_95 = V_2 -> V_510 ( V_2 ) ;
if ( V_95 != V_94 )
goto V_175;
goto F_89;
}
if ( V_2 -> V_480 == 2 )
goto V_554;
else if ( V_2 -> V_480 == 3 )
goto V_555;
switch ( V_2 -> V_140 ) {
case 0x70 ... 0x7f :
if ( F_55 ( V_2 -> V_140 , V_2 -> V_193 ) )
V_95 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_82 . V_173 . V_91 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_82 . V_9 == F_3 ( V_2 , V_250 ) )
V_2 -> V_25 . type = V_122 ;
else
V_95 = F_154 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_97 ) {
case 2 : V_2 -> V_25 . V_34 = ( V_169 ) V_2 -> V_25 . V_34 ; break;
case 4 : V_2 -> V_25 . V_34 = ( V_177 ) V_2 -> V_25 . V_34 ; break;
case 8 : V_2 -> V_25 . V_34 = ( V_170 ) V_2 -> V_25 . V_34 ; break;
}
break;
case 0xcc :
V_95 = F_105 ( V_2 , 3 ) ;
break;
case 0xcd :
V_95 = F_105 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0xce :
if ( V_2 -> V_193 & V_238 )
V_95 = F_105 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_95 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
V_2 -> V_25 . type = V_122 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_556 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_193 ^= V_233 ;
break;
case 0xf8 :
V_2 -> V_193 &= ~ V_233 ;
break;
case 0xf9 :
V_2 -> V_193 |= V_233 ;
break;
case 0xfc :
V_2 -> V_193 &= ~ V_194 ;
break;
case 0xfd :
V_2 -> V_193 |= V_194 ;
break;
default:
goto V_557;
}
if ( V_95 != V_94 )
goto V_175;
F_89:
if ( V_2 -> V_45 & V_558 ) {
F_227 ( V_2 -> V_22 . type == V_161 || V_2 -> V_22 . type == V_195 ) ;
V_95 = F_89 ( V_2 , & V_2 -> V_22 ) ;
if ( V_95 != V_94 )
goto V_175;
}
if ( ! ( V_2 -> V_45 & V_549 ) ) {
V_95 = F_89 ( V_2 , & V_2 -> V_25 ) ;
if ( V_95 != V_94 )
goto V_175;
}
V_2 -> V_25 . type = V_532 ;
if ( ( V_2 -> V_45 & V_534 ) == V_559 )
F_146 ( V_2 , V_166 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_45 & V_546 ) == V_560 )
F_146 ( V_2 , V_168 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
unsigned int V_191 ;
struct V_179 * V_294 = & V_2 -> V_188 ;
if ( ( V_2 -> V_45 & V_534 ) == V_559 )
V_191 = V_2 -> V_22 . V_191 ;
else
V_191 = V_2 -> V_25 . V_191 ;
F_17 ( V_2 , V_192 , - V_191 ) ;
if ( ! F_221 ( V_2 ) ) {
if ( ( V_294 -> V_113 != 0 || F_1 ( V_2 , V_192 ) & 0x3ff ) &&
( V_294 -> V_113 == 0 || V_294 -> V_113 != V_294 -> V_182 ) ) {
V_2 -> V_181 . V_113 = 0 ;
F_4 ( V_2 ) ;
return V_561 ;
}
goto V_175;
}
V_2 -> V_193 &= ~ V_258 ;
}
V_2 -> V_31 = V_2 -> V_98 ;
V_175:
if ( V_95 == V_61 ) {
F_23 ( V_2 -> V_57 . V_58 > 0x1f ) ;
V_2 -> V_562 = true ;
}
if ( V_95 == V_563 )
return V_564 ;
if ( V_95 == V_94 )
F_4 ( V_2 ) ;
return ( V_95 == V_223 ) ? V_380 : V_381 ;
V_554:
switch ( V_2 -> V_140 ) {
case 0x09 :
( V_2 -> V_6 -> V_565 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_34 = V_6 -> V_134 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_377 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_34 ) ;
break;
case 0x40 ... 0x4f :
if ( F_55 ( V_2 -> V_140 , V_2 -> V_193 ) )
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
else if ( V_2 -> V_97 != 4 )
V_2 -> V_25 . type = V_122 ;
break;
case 0x80 ... 0x8f :
if ( F_55 ( V_2 -> V_140 , V_2 -> V_193 ) )
V_95 = F_43 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_34 = F_55 ( V_2 -> V_140 , V_2 -> V_193 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_97 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_35 ) V_2 -> V_22 . V_34
: ( V_36 ) V_2 -> V_22 . V_34 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_97 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_169 ) V_2 -> V_22 . V_34 :
( V_177 ) V_2 -> V_22 . V_34 ;
break;
default:
goto V_557;
}
V_555:
if ( V_95 != V_94 )
goto V_175;
goto F_89;
V_557:
return V_380 ;
}
void F_228 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_229 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
