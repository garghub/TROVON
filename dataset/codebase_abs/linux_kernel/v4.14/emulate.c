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
V_35 V_91 ;
V_89 = F_21 ( V_2 , V_82 . V_52 ) + V_82 . V_92 ;
* V_83 = 0 ;
switch ( V_41 ) {
case V_42 :
* V_87 = V_89 ;
V_91 = F_36 ( V_2 ) ;
if ( F_37 ( V_89 , V_91 ) != V_89 )
goto V_93;
* V_83 = F_38 ( T_2 , ~ 0u , ( 1ull << V_91 ) - V_89 ) ;
if ( V_74 > * V_83 )
goto V_93;
break;
default:
* V_87 = V_89 = ( V_37 ) V_89 ;
V_88 = V_2 -> V_6 -> V_43 ( V_2 , & V_38 , & V_49 , NULL ,
V_82 . V_52 ) ;
if ( ! V_88 )
goto V_93;
if ( ( ( ( V_2 -> V_41 != V_94 ) && ( V_49 . type & 8 ) )
|| ! ( V_49 . type & 2 ) ) && V_84 )
goto V_93;
if ( ! V_85 && ( V_49 . type & 8 ) && ! ( V_49 . type & 2 ) )
goto V_93;
V_90 = F_19 ( & V_49 ) ;
if ( ! ( V_49 . type & 8 ) && ( V_49 . type & 4 ) ) {
if ( V_82 . V_92 <= V_90 )
goto V_93;
V_90 = V_49 . V_45 ? 0xffffffff : 0xffff ;
}
if ( V_82 . V_92 > V_90 )
goto V_93;
if ( V_90 == 0xffffffff )
* V_83 = ~ 0u ;
else {
* V_83 = ( T_2 ) V_90 + 1 - V_82 . V_92 ;
if ( V_74 > * V_83 )
goto V_93;
}
break;
}
if ( V_89 & ( F_33 ( V_2 , V_74 ) - 1 ) )
return F_25 ( V_2 , 0 ) ;
return V_95 ;
V_93:
if ( V_82 . V_52 == V_44 )
return F_26 ( V_2 , 0 ) ;
else
return F_25 ( V_2 , 0 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
unsigned V_74 , bool V_84 ,
T_1 * V_87 )
{
unsigned V_83 ;
return F_35 ( V_2 , V_82 , & V_83 , V_74 , V_84 , false ,
V_2 -> V_41 , V_87 ) ;
}
static inline int F_40 ( struct V_1 * V_2 , T_1 V_25 ,
enum V_86 V_41 )
{
T_1 V_87 ;
int V_96 ;
unsigned V_83 ;
struct V_81 V_82 = { . V_52 = V_97 ,
. V_92 = V_25 } ;
if ( V_2 -> V_98 != sizeof( unsigned long ) )
V_82 . V_92 = V_25 & ( ( 1UL << ( V_2 -> V_98 << 3 ) ) - 1 ) ;
V_96 = F_35 ( V_2 , V_82 , & V_83 , 1 , false , true , V_41 , & V_87 ) ;
if ( V_96 == V_95 )
V_2 -> V_99 = V_82 . V_92 ;
return V_96 ;
}
static inline int F_41 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_40 ( V_2 , V_25 , V_2 -> V_41 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_25 ,
const struct V_39 * V_100 )
{
enum V_86 V_41 = V_2 -> V_41 ;
int V_96 ;
#ifdef F_43
if ( V_2 -> V_41 >= V_101 ) {
if ( V_100 -> V_102 ) {
T_2 V_103 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( V_103 & V_106 )
V_41 = V_42 ;
} else
V_41 = V_107 ;
}
#endif
if ( V_41 == V_101 || V_41 == V_107 )
V_41 = V_100 -> V_45 ? V_107 : V_101 ;
V_96 = F_40 ( V_2 , V_25 , V_41 ) ;
if ( V_96 == V_95 )
V_2 -> V_41 = V_41 ;
return V_96 ;
}
static inline int F_44 ( struct V_1 * V_2 , int V_108 )
{
return F_41 ( V_2 , V_2 -> V_99 + V_108 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_109 ,
unsigned V_74 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_82 , V_74 , false , & V_87 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_110 ( V_2 , V_87 , V_109 , V_74 , & V_2 -> V_57 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_109 ,
unsigned int V_74 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_111 ( V_2 , V_87 , V_109 , V_74 , & V_2 -> V_57 ) ;
}
static int F_47 ( struct V_1 * V_2 , int V_112 )
{
int V_96 ;
unsigned V_74 , V_83 ;
unsigned long V_87 ;
int V_113 = V_2 -> V_85 . V_114 - V_2 -> V_85 . V_109 ;
struct V_81 V_82 = { . V_52 = V_97 ,
. V_92 = V_2 -> V_31 + V_113 } ;
V_96 = F_35 ( V_2 , V_82 , & V_83 , 0 , false , true , V_2 -> V_41 ,
& V_87 ) ;
if ( F_48 ( V_96 != V_95 ) )
return V_96 ;
V_74 = F_38 ( unsigned , 15UL ^ V_113 , V_83 ) ;
V_74 = F_38 ( unsigned , V_74 , V_115 - F_49 ( V_87 ) ) ;
if ( F_48 ( V_74 < V_112 ) )
return F_25 ( V_2 , 0 ) ;
V_96 = V_2 -> V_6 -> V_85 ( V_2 , V_87 , V_2 -> V_85 . V_114 ,
V_74 , & V_2 -> V_57 ) ;
if ( F_48 ( V_96 != V_95 ) )
return V_96 ;
V_2 -> V_85 . V_114 += V_74 ;
return V_95 ;
}
static T_3 int F_50 ( struct V_1 * V_2 ,
unsigned V_74 )
{
unsigned V_116 = V_2 -> V_85 . V_114 - V_2 -> V_85 . V_117 ;
if ( F_48 ( V_116 < V_74 ) )
return F_47 ( V_2 , V_74 - V_116 ) ;
else
return V_95 ;
}
static void * F_51 ( struct V_1 * V_2 , V_35 V_19 ,
int V_118 )
{
void * V_119 ;
int V_120 = ( V_2 -> V_121 == 0 ) && V_118 ;
if ( V_120 && V_19 >= 4 && V_19 < 8 )
V_119 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_119 = F_3 ( V_2 , V_19 ) ;
return V_119 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
V_36 * V_74 , unsigned long * V_122 , int V_98 )
{
int V_96 ;
if ( V_98 == 2 )
V_98 = 3 ;
* V_122 = 0 ;
V_96 = F_45 ( V_2 , V_82 , V_74 , 2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_82 . V_92 += 2 ;
V_96 = F_45 ( V_2 , V_82 , V_122 , V_98 ) ;
return V_96 ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_123 ;
return F_54 ( V_2 , V_124 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 . V_34 == 0 )
V_2 -> V_25 . type = V_123 ;
return F_54 ( V_2 , V_125 ) ;
}
static T_3 V_35 F_56 ( unsigned int V_126 , unsigned long V_127 )
{
V_35 V_96 ;
void (* F_57)( void ) = ( void * ) V_128 + 4 * ( V_126 & 0xf ) ;
V_127 = ( V_127 & V_129 ) | V_130 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_96 ;
}
static void F_58 ( struct V_131 * V_132 )
{
switch ( V_132 -> V_27 ) {
case 1 :
V_132 -> V_34 = * ( V_35 * ) V_132 -> V_82 . V_9 ;
break;
case 2 :
V_132 -> V_34 = * ( V_36 * ) V_132 -> V_82 . V_9 ;
break;
case 4 :
V_132 -> V_34 = * ( V_37 * ) V_132 -> V_82 . V_9 ;
break;
case 8 :
V_132 -> V_34 = * ( T_2 * ) V_132 -> V_82 . V_9 ;
break;
}
}
static void F_59 ( struct V_1 * V_2 , T_4 * V_109 , int V_9 )
{
V_2 -> V_6 -> V_133 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_43
case 8 : asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_60 () ;
}
V_2 -> V_6 -> V_134 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 , T_4 * V_109 ,
int V_9 )
{
V_2 -> V_6 -> V_133 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_43
case 8 : asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_60 () ;
}
V_2 -> V_6 -> V_134 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_2 * V_109 , int V_9 )
{
V_2 -> V_6 -> V_133 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_60 () ;
}
V_2 -> V_6 -> V_134 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 * V_109 , int V_9 )
{
V_2 -> V_6 -> V_133 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_60 () ;
}
V_2 -> V_6 -> V_134 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_135 ( V_2 , 0 ) & ( V_136 | V_137 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_134 ( V_2 ) ;
return V_95 ;
}
static int F_65 ( struct V_1 * V_2 )
{
V_36 V_138 ;
if ( V_2 -> V_6 -> V_135 ( V_2 , 0 ) & ( V_136 | V_137 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_134 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_138 ;
return V_95 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_36 V_139 ;
if ( V_2 -> V_6 -> V_135 ( V_2 , 0 ) & ( V_136 | V_137 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_134 ( V_2 ) ;
V_2 -> V_25 . V_34 = V_139 ;
return V_95 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_45 & V_140 ) )
V_9 = ( V_2 -> V_141 & 7 ) | ( ( V_2 -> V_121 & 1 ) << 3 ) ;
if ( V_2 -> V_45 & V_142 ) {
V_132 -> type = V_143 ;
V_132 -> V_27 = 16 ;
V_132 -> V_82 . V_144 = V_9 ;
F_59 ( V_2 , & V_132 -> V_145 , V_9 ) ;
return;
}
if ( V_2 -> V_45 & V_146 ) {
V_9 &= 7 ;
V_132 -> type = V_147 ;
V_132 -> V_27 = 8 ;
V_132 -> V_82 . V_148 = V_9 ;
return;
}
V_132 -> type = V_149 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_9 = F_51 ( V_2 , V_9 , V_2 -> V_45 & V_150 ) ;
F_58 ( V_132 ) ;
V_132 -> V_151 = V_132 -> V_34 ;
}
static void F_68 ( struct V_1 * V_2 , int V_152 )
{
if ( V_152 == V_48 || V_152 == V_153 )
V_2 -> V_154 = V_44 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
V_35 V_155 ;
int V_156 , V_152 , V_157 ;
int V_96 = V_95 ;
T_1 V_158 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_121 << 1 ) & 8 ) ;
V_156 = ( V_2 -> V_121 << 2 ) & 8 ;
V_152 = ( V_2 -> V_121 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_159 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_159 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_152 | ( V_2 -> V_159 & 0x07 ) ;
V_2 -> V_154 = V_160 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_45 & V_161 ) ) {
V_132 -> type = V_149 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_9 = F_51 ( V_2 , V_2 -> V_20 ,
V_2 -> V_45 & V_150 ) ;
if ( V_2 -> V_45 & V_142 ) {
V_132 -> type = V_143 ;
V_132 -> V_27 = 16 ;
V_132 -> V_82 . V_144 = V_2 -> V_20 ;
F_59 ( V_2 , & V_132 -> V_145 , V_2 -> V_20 ) ;
return V_96 ;
}
if ( V_2 -> V_45 & V_146 ) {
V_132 -> type = V_147 ;
V_132 -> V_27 = 8 ;
V_132 -> V_82 . V_148 = V_2 -> V_20 & 7 ;
return V_96 ;
}
F_58 ( V_132 ) ;
return V_96 ;
}
V_132 -> type = V_162 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_163 = F_1 ( V_2 , V_164 ) ;
unsigned V_165 = F_1 ( V_2 , V_153 ) ;
unsigned V_166 = F_1 ( V_2 , V_167 ) ;
unsigned V_168 = F_1 ( V_2 , V_169 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_158 += F_70 ( V_36 , V_2 ) ;
break;
case 1 :
V_158 += F_70 ( V_170 , V_2 ) ;
break;
case 2 :
V_158 += F_70 ( V_36 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_158 += V_163 + V_166 ;
break;
case 1 :
V_158 += V_163 + V_168 ;
break;
case 2 :
V_158 += V_165 + V_166 ;
break;
case 3 :
V_158 += V_165 + V_168 ;
break;
case 4 :
V_158 += V_166 ;
break;
case 5 :
V_158 += V_168 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_158 += V_165 ;
break;
case 7 :
V_158 += V_163 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_154 = V_44 ;
V_158 = ( V_36 ) V_158 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_155 = F_70 ( V_35 , V_2 ) ;
V_156 |= ( V_155 >> 3 ) & 7 ;
V_152 |= V_155 & 7 ;
V_157 = V_155 >> 6 ;
if ( ( V_152 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_158 += F_70 ( V_171 , V_2 ) ;
else {
V_158 += F_1 ( V_2 , V_152 ) ;
F_68 ( V_2 , V_152 ) ;
if ( ( V_2 -> V_45 & V_172 ) &&
V_152 == V_48 )
V_158 += V_2 -> V_98 ;
}
if ( V_156 != 4 )
V_158 += F_1 ( V_2 , V_156 ) << V_157 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
V_158 += F_70 ( V_171 , V_2 ) ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_173 = 1 ;
} else {
V_152 = V_2 -> V_20 ;
V_158 += F_1 ( V_2 , V_152 ) ;
F_68 ( V_2 , V_152 ) ;
}
switch ( V_2 -> V_18 ) {
case 1 :
V_158 += F_70 ( V_170 , V_2 ) ;
break;
case 2 :
V_158 += F_70 ( V_171 , V_2 ) ;
break;
}
}
V_132 -> V_82 . V_174 . V_92 = V_158 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_175 . V_82 . V_174 . V_92 = ( V_37 ) V_2 -> V_175 . V_82 . V_174 . V_92 ;
V_176:
return V_96 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
int V_96 = V_95 ;
V_132 -> type = V_162 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_132 -> V_82 . V_174 . V_92 = F_70 ( V_36 , V_2 ) ;
break;
case 4 :
V_132 -> V_82 . V_174 . V_92 = F_70 ( V_37 , V_2 ) ;
break;
case 8 :
V_132 -> V_82 . V_174 . V_92 = F_70 ( T_2 , V_2 ) ;
break;
}
V_176:
return V_96 ;
}
static void F_72 ( struct V_1 * V_2 )
{
long V_177 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_162 && V_2 -> V_22 . type == V_149 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_177 = ( V_178 ) V_2 -> V_22 . V_34 & ( V_178 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_177 = ( V_171 ) V_2 -> V_22 . V_34 & ( V_171 ) V_33 ;
else
V_177 = ( V_179 ) V_2 -> V_22 . V_34 & ( V_179 ) V_33 ;
V_2 -> V_25 . V_82 . V_174 . V_92 = F_14 ( V_2 ,
V_2 -> V_25 . V_82 . V_174 . V_92 + ( V_177 >> 3 ) ) ;
}
V_2 -> V_22 . V_34 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
unsigned long V_82 , void * V_32 , unsigned V_74 )
{
int V_96 ;
struct V_180 * V_181 = & V_2 -> V_182 ;
if ( V_181 -> V_183 < V_181 -> V_114 )
goto V_184;
F_23 ( ( V_181 -> V_114 + V_74 ) >= sizeof( V_181 -> V_109 ) ) ;
V_96 = V_2 -> V_6 -> F_73 ( V_2 , V_82 , V_181 -> V_109 + V_181 -> V_114 , V_74 ,
& V_2 -> V_57 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_181 -> V_114 += V_74 ;
V_184:
memcpy ( V_32 , V_181 -> V_109 + V_181 -> V_183 , V_74 ) ;
V_181 -> V_183 += V_74 ;
return V_95 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
void * V_109 ,
unsigned V_74 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_82 , V_74 , false , & V_87 ) ;
if ( V_96 != V_95 )
return V_96 ;
return F_73 ( V_2 , V_87 , V_109 , V_74 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
const void * V_109 ,
unsigned V_74 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_185 ( V_2 , V_87 , V_109 , V_74 ,
& V_2 -> V_57 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_81 V_82 ,
const void * V_186 , const void * V_109 ,
unsigned V_74 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_82 , V_74 , true , & V_87 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_187 ( V_2 , V_87 , V_186 , V_109 ,
V_74 , & V_2 -> V_57 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
unsigned int V_74 , unsigned short V_188 ,
void * V_32 )
{
struct V_180 * V_96 = & V_2 -> V_189 ;
if ( V_96 -> V_183 == V_96 -> V_114 ) {
unsigned int V_190 , V_191 ;
unsigned int V_192 = V_2 -> V_17 ?
F_14 ( V_2 , F_1 ( V_2 , V_193 ) ) : 1 ;
V_190 = ( V_2 -> V_194 & V_195 ) ?
F_49 ( F_1 ( V_2 , V_169 ) ) :
V_115 - F_49 ( F_1 ( V_2 , V_169 ) ) ;
V_191 = F_78 ( V_190 , ( unsigned int ) sizeof( V_96 -> V_109 ) / V_74 , V_192 ) ;
if ( V_191 == 0 )
V_191 = 1 ;
V_96 -> V_183 = V_96 -> V_114 = 0 ;
if ( ! V_2 -> V_6 -> F_77 ( V_2 , V_74 , V_188 , V_96 -> V_109 , V_191 ) )
return 0 ;
V_96 -> V_114 = V_191 * V_74 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) &&
! ( V_2 -> V_194 & V_195 ) ) {
V_2 -> V_25 . V_109 = V_96 -> V_109 + V_96 -> V_183 ;
V_2 -> V_25 . type = V_196 ;
V_2 -> V_25 . V_192 = ( V_96 -> V_114 - V_96 -> V_183 ) / V_74 ;
V_96 -> V_183 = V_96 -> V_114 ;
} else {
memcpy ( V_32 , V_96 -> V_109 + V_96 -> V_183 , V_74 ) ;
V_96 -> V_183 += V_74 ;
}
return 1 ;
}
static int F_79 ( struct V_1 * V_2 ,
V_36 V_197 , struct V_39 * V_49 )
{
struct V_198 V_199 ;
T_1 V_82 ;
V_2 -> V_6 -> V_200 ( V_2 , & V_199 ) ;
if ( V_199 . V_74 < V_197 * 8 + 7 )
return F_25 ( V_2 , V_197 << 3 | 0x2 ) ;
V_82 = V_199 . V_122 + V_197 * 8 ;
return V_2 -> V_6 -> V_110 ( V_2 , V_82 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_198 * V_199 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
V_37 V_72 = 0 ;
if ( V_70 & 1 << 2 ) {
struct V_39 V_49 ;
V_36 V_38 ;
memset ( V_199 , 0 , sizeof *V_199 ) ;
if ( ! V_6 -> V_43 ( V_2 , & V_38 , & V_49 , & V_72 ,
V_202 ) )
return;
V_199 -> V_74 = F_19 ( & V_49 ) ;
V_199 -> V_122 = F_81 ( & V_49 ) | ( ( T_2 ) V_72 << 32 ) ;
} else
V_6 -> V_203 ( V_2 , V_199 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
V_36 V_70 , T_1 * V_204 )
{
struct V_198 V_199 ;
V_36 V_197 = V_70 >> 3 ;
T_1 V_82 ;
F_80 ( V_2 , V_70 , & V_199 ) ;
if ( V_199 . V_74 < V_197 * 8 + 7 )
return F_25 ( V_2 , V_70 & 0xfffc ) ;
V_82 = V_199 . V_122 + V_197 * 8 ;
#ifdef F_43
if ( V_82 >> 32 != 0 ) {
T_2 V_103 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( ! ( V_103 & V_106 ) )
V_82 &= ( V_37 ) - 1 ;
}
#endif
* V_204 = V_82 ;
return V_95 ;
}
static int F_83 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 ,
T_1 * V_204 )
{
int V_96 ;
V_96 = F_82 ( V_2 , V_70 , V_204 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_110 ( V_2 , * V_204 , V_49 , sizeof( * V_49 ) ,
& V_2 -> V_57 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
V_36 V_70 , struct V_39 * V_49 )
{
int V_96 ;
T_1 V_82 ;
V_96 = F_82 ( V_2 , V_70 , & V_82 ) ;
if ( V_96 != V_95 )
return V_96 ;
return V_2 -> V_6 -> V_111 ( V_2 , V_82 , V_49 , sizeof *V_49 ,
& V_2 -> V_57 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 , V_35 V_205 ,
enum V_206 V_207 ,
struct V_39 * V_49 )
{
struct V_39 V_208 , V_209 ;
V_35 V_210 , V_211 ;
unsigned V_212 = V_64 ;
V_37 V_213 = 0 ;
bool V_214 = ! ( V_70 & ~ 0x3 ) ;
T_1 V_215 ;
int V_216 ;
V_36 V_71 ;
V_37 V_72 = 0 ;
memset ( & V_208 , 0 , sizeof V_208 ) ;
if ( V_2 -> V_41 == V_94 ) {
V_2 -> V_6 -> V_43 ( V_2 , & V_71 , & V_208 , NULL , V_52 ) ;
F_86 ( & V_208 , V_70 << 4 ) ;
goto V_217;
} else if ( V_52 <= V_218 && V_2 -> V_41 == V_219 ) {
F_86 ( & V_208 , V_70 << 4 ) ;
F_87 ( & V_208 , 0xffff ) ;
V_208 . type = 3 ;
V_208 . V_119 = 1 ;
V_208 . V_220 = 1 ;
V_208 . V_210 = 3 ;
goto V_217;
}
V_211 = V_70 & 3 ;
if ( V_52 == V_221 && ( V_70 & ( 1 << 2 ) ) )
goto V_57;
if ( V_214 ) {
if ( V_52 == V_97 || V_52 == V_221 )
goto V_57;
if ( V_52 == V_44 ) {
if ( V_2 -> V_41 != V_42 || V_211 != V_205 )
goto V_57;
V_208 . type = 3 ;
V_208 . V_119 = 1 ;
V_208 . V_220 = 1 ;
V_208 . V_210 = V_205 ;
V_208 . V_45 = 1 ;
V_208 . V_51 = 1 ;
}
goto V_217;
}
V_216 = F_83 ( V_2 , V_70 , & V_208 , & V_215 ) ;
if ( V_216 != V_95 )
return V_216 ;
V_213 = V_70 & 0xfffc ;
V_212 = ( V_207 == V_222 ) ? V_67 :
V_64 ;
if ( V_52 <= V_218 && ! V_208 . V_220 ) {
if ( V_207 == V_223 )
return V_224 ;
goto V_57;
}
if ( ! V_208 . V_119 ) {
V_212 = ( V_52 == V_44 ) ? V_65 : V_225 ;
goto V_57;
}
V_210 = V_208 . V_210 ;
switch ( V_52 ) {
case V_44 :
if ( V_211 != V_205 || ( V_208 . type & 0xa ) != 0x2 || V_210 != V_205 )
goto V_57;
break;
case V_97 :
if ( ! ( V_208 . type & 8 ) )
goto V_57;
if ( V_208 . type & 4 ) {
if ( V_210 > V_205 )
goto V_57;
} else {
if ( V_211 > V_205 || V_210 != V_205 )
goto V_57;
}
if ( V_208 . V_45 && V_208 . V_102 ) {
T_2 V_103 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( V_103 & V_106 )
goto V_57;
}
V_70 = ( V_70 & 0xfffc ) | V_205 ;
break;
case V_221 :
if ( V_208 . V_220 || ( V_208 . type != 1 && V_208 . type != 9 ) )
goto V_57;
V_209 = V_208 ;
V_208 . type |= 2 ;
V_216 = V_2 -> V_6 -> V_187 ( V_2 , V_215 , & V_209 , & V_208 ,
sizeof( V_208 ) , & V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
break;
case V_202 :
if ( V_208 . V_220 || V_208 . type != 2 )
goto V_57;
break;
default:
if ( ( V_208 . type & 0xa ) == 0x8 ||
( ( ( V_208 . type & 0xc ) != 0xc ) &&
( V_211 > V_210 && V_205 > V_210 ) ) )
goto V_57;
break;
}
if ( V_208 . V_220 ) {
if ( ! ( V_208 . type & 1 ) ) {
V_208 . type |= 1 ;
V_216 = F_84 ( V_2 , V_70 ,
& V_208 ) ;
if ( V_216 != V_95 )
return V_216 ;
}
} else if ( V_2 -> V_41 == V_42 ) {
V_216 = V_2 -> V_6 -> V_110 ( V_2 , V_215 + 8 , & V_72 ,
sizeof( V_72 ) , & V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
if ( F_88 ( F_81 ( & V_208 ) |
( ( T_2 ) V_72 << 32 ) , V_2 ) )
return F_25 ( V_2 , 0 ) ;
}
V_217:
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_208 , V_72 , V_52 ) ;
if ( V_49 )
* V_49 = V_208 ;
return V_95 ;
V_57:
return F_22 ( V_2 , V_212 , V_213 , true ) ;
}
static int F_89 ( struct V_1 * V_2 ,
V_36 V_70 , int V_52 )
{
V_35 V_205 = V_2 -> V_6 -> V_205 ( V_2 ) ;
if ( V_52 == V_44 && V_70 == 3 &&
V_2 -> V_41 == V_42 )
return F_22 ( V_2 , V_64 , 0 , true ) ;
return F_85 ( V_2 , V_70 , V_52 , V_205 ,
V_226 , NULL ) ;
}
static void F_90 ( struct V_131 * V_132 )
{
return F_9 ( V_132 -> V_82 . V_9 , V_132 -> V_34 , V_132 -> V_27 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
switch ( V_132 -> type ) {
case V_149 :
F_90 ( V_132 ) ;
break;
case V_162 :
if ( V_2 -> V_227 )
return F_76 ( V_2 ,
V_132 -> V_82 . V_174 ,
& V_132 -> V_151 ,
& V_132 -> V_34 ,
V_132 -> V_27 ) ;
else
return F_75 ( V_2 ,
V_132 -> V_82 . V_174 ,
& V_132 -> V_34 ,
V_132 -> V_27 ) ;
break;
case V_196 :
return F_75 ( V_2 ,
V_132 -> V_82 . V_174 ,
V_132 -> V_109 ,
V_132 -> V_27 * V_132 -> V_192 ) ;
break;
case V_143 :
F_61 ( V_2 , & V_132 -> V_145 , V_132 -> V_82 . V_144 ) ;
break;
case V_147 :
F_63 ( V_2 , & V_132 -> V_228 , V_132 -> V_82 . V_148 ) ;
break;
case V_123 :
break;
default:
break;
}
return V_95 ;
}
static int F_92 ( struct V_1 * V_2 , void * V_109 , int V_27 )
{
struct V_81 V_82 ;
F_18 ( V_2 , - V_27 ) ;
V_82 . V_92 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_82 . V_52 = V_44 ;
return F_75 ( V_2 , V_82 , V_109 , V_27 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_123 ;
return F_92 ( V_2 , & V_2 -> V_22 . V_34 , V_2 -> V_98 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
void * V_32 , int V_229 )
{
int V_96 ;
struct V_81 V_82 ;
V_82 . V_92 = F_1 ( V_2 , V_48 ) & F_11 ( V_2 ) ;
V_82 . V_52 = V_44 ;
V_96 = F_74 ( V_2 , V_82 , V_32 , V_229 ) ;
if ( V_96 != V_95 )
return V_96 ;
F_18 ( V_2 , V_229 ) ;
return V_96 ;
}
static int F_95 ( struct V_1 * V_2 )
{
return F_94 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_98 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
void * V_32 , int V_229 )
{
int V_96 ;
unsigned long V_34 , V_230 ;
int V_231 = ( V_2 -> V_194 & V_232 ) >> V_233 ;
int V_205 = V_2 -> V_6 -> V_205 ( V_2 ) ;
V_96 = F_94 ( V_2 , & V_34 , V_229 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_230 = V_234 | V_235 | V_236 |
V_237 | V_238 | V_239 |
V_240 | V_195 | V_241 |
V_242 | V_243 ;
switch( V_2 -> V_41 ) {
case V_42 :
case V_107 :
case V_101 :
if ( V_205 == 0 )
V_230 |= V_232 ;
if ( V_205 <= V_231 )
V_230 |= V_130 ;
break;
case V_219 :
if ( V_231 < 3 )
return F_25 ( V_2 , 0 ) ;
V_230 |= V_130 ;
break;
default:
V_230 |= ( V_232 | V_130 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_194 & ~ V_230 ) | ( V_34 & V_230 ) ;
return V_96 ;
}
static int F_97 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_149 ;
V_2 -> V_25 . V_82 . V_9 = & V_2 -> V_194 ;
V_2 -> V_25 . V_27 = V_2 -> V_98 ;
return F_96 ( V_2 , & V_2 -> V_25 . V_34 , V_2 -> V_98 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_96 ;
unsigned V_244 = V_2 -> V_22 . V_34 ;
unsigned V_245 = V_2 -> V_246 . V_34 & 31 ;
T_1 V_247 ;
if ( V_245 )
return V_224 ;
V_247 = F_1 ( V_2 , V_153 ) ;
V_96 = F_92 ( V_2 , & V_247 , F_12 ( V_2 ) ) ;
if ( V_96 != V_95 )
return V_96 ;
F_8 ( F_3 ( V_2 , V_153 ) , F_1 ( V_2 , V_48 ) ,
F_11 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_48 ) ,
F_1 ( V_2 , V_48 ) - V_244 ,
F_11 ( V_2 ) ) ;
return V_95 ;
}
static int F_99 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_48 ) , F_1 ( V_2 , V_153 ) ,
F_11 ( V_2 ) ) ;
return F_94 ( V_2 , F_3 ( V_2 , V_153 ) , V_2 -> V_98 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_246 . V_34 ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_52 ) ;
if ( V_2 -> V_98 == 4 ) {
F_18 ( V_2 , - 2 ) ;
V_2 -> V_98 = 2 ;
}
return F_93 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_246 . V_34 ;
unsigned long V_70 ;
int V_96 ;
V_96 = F_94 ( V_2 , & V_70 , 2 ) ;
if ( V_96 != V_95 )
return V_96 ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_248 = V_249 ;
if ( V_2 -> V_98 > 2 )
F_18 ( V_2 , V_2 -> V_98 - 2 ) ;
V_96 = F_89 ( V_2 , ( V_36 ) V_70 , V_52 ) ;
return V_96 ;
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned long V_250 = F_1 ( V_2 , V_48 ) ;
int V_96 = V_95 ;
int V_9 = V_251 ;
while ( V_9 <= V_169 ) {
( V_9 == V_48 ) ?
( V_2 -> V_22 . V_34 = V_250 ) : ( V_2 -> V_22 . V_34 = F_1 ( V_2 , V_9 ) ) ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
++ V_9 ;
}
return V_96 ;
}
static int F_103 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_194 & ~ V_252 ;
return F_93 ( V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_96 = V_95 ;
int V_9 = V_169 ;
V_37 V_34 ;
while ( V_9 >= V_251 ) {
if ( V_9 == V_48 ) {
F_18 ( V_2 , V_2 -> V_98 ) ;
-- V_9 ;
}
V_96 = F_94 ( V_2 , & V_34 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
break;
F_9 ( F_3 ( V_2 , V_9 ) , V_34 , V_2 -> V_98 ) ;
-- V_9 ;
}
return V_96 ;
}
static int F_105 ( struct V_1 * V_2 , int V_253 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
int V_96 ;
struct V_198 V_199 ;
T_5 V_254 ;
T_5 V_255 ;
V_36 V_256 , V_31 ;
V_2 -> V_22 . V_34 = V_2 -> V_194 ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_194 &= ~ ( V_130 | V_240 | V_242 ) ;
V_2 -> V_22 . V_34 = F_31 ( V_2 , V_97 ) ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_22 . V_34 = V_2 -> V_99 ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_6 -> V_200 ( V_2 , & V_199 ) ;
V_255 = V_199 . V_122 + ( V_253 << 2 ) ;
V_254 = V_199 . V_122 + ( V_253 << 2 ) + 2 ;
V_96 = V_6 -> V_110 ( V_2 , V_254 , & V_256 , 2 , & V_2 -> V_57 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = V_6 -> V_110 ( V_2 , V_255 , & V_31 , 2 , & V_2 -> V_57 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_89 ( V_2 , V_256 , V_97 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_99 = V_31 ;
return V_96 ;
}
int F_106 ( struct V_1 * V_2 , int V_253 )
{
int V_96 ;
F_6 ( V_2 ) ;
V_96 = F_105 ( V_2 , V_253 ) ;
if ( V_96 == V_95 )
F_4 ( V_2 ) ;
return V_96 ;
}
static int F_107 ( struct V_1 * V_2 , int V_253 )
{
switch( V_2 -> V_41 ) {
case V_94 :
return F_105 ( V_2 , V_253 ) ;
case V_219 :
case V_101 :
case V_107 :
case V_42 :
default:
return V_224 ;
}
}
static int F_108 ( struct V_1 * V_2 )
{
int V_96 = V_95 ;
unsigned long V_257 = 0 ;
unsigned long V_258 = 0 ;
unsigned long V_256 = 0 ;
unsigned long V_33 = V_234 | V_235 | V_236 |
V_237 | V_238 | V_240 |
V_130 | V_195 | V_239 |
V_232 | V_241 | V_259 |
V_242 | V_243 |
V_260 ;
unsigned long V_261 = V_252 | V_262 |
V_263 ;
V_96 = F_94 ( V_2 , & V_257 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
if ( V_257 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_96 = F_94 ( V_2 , & V_256 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_94 ( V_2 , & V_258 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_89 ( V_2 , ( V_36 ) V_256 , V_97 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_99 = V_257 ;
if ( V_2 -> V_98 == 4 )
V_2 -> V_194 = ( ( V_258 & V_33 ) | ( V_2 -> V_194 & V_261 ) ) ;
else if ( V_2 -> V_98 == 2 ) {
V_2 -> V_194 &= ~ 0xffff ;
V_2 -> V_194 |= V_258 ;
}
V_2 -> V_194 &= ~ V_264 ;
V_2 -> V_194 |= V_260 ;
V_2 -> V_6 -> V_265 ( V_2 , false ) ;
return V_96 ;
}
static int F_109 ( struct V_1 * V_2 )
{
switch( V_2 -> V_41 ) {
case V_94 :
return F_108 ( V_2 ) ;
case V_219 :
case V_101 :
case V_107 :
case V_42 :
default:
return V_224 ;
}
}
static int F_110 ( struct V_1 * V_2 )
{
int V_96 ;
unsigned short V_38 ;
struct V_39 V_266 ;
V_35 V_205 = V_2 -> V_6 -> V_205 ( V_2 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_267 + V_2 -> V_98 , 2 ) ;
V_96 = F_85 ( V_2 , V_38 , V_97 , V_205 ,
V_223 ,
& V_266 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_42 ( V_2 , V_2 -> V_22 . V_34 , & V_266 ) ;
if ( V_96 != V_95 )
return V_224 ;
return V_96 ;
}
static int F_111 ( struct V_1 * V_2 )
{
return F_41 ( V_2 , V_2 -> V_22 . V_34 ) ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_96 ;
long int V_268 ;
V_268 = V_2 -> V_99 ;
V_96 = F_41 ( V_2 , V_2 -> V_22 . V_34 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_22 . V_34 = V_268 ;
V_96 = F_93 ( V_2 ) ;
return V_96 ;
}
static int F_113 ( struct V_1 * V_2 )
{
T_2 V_269 = V_2 -> V_25 . V_270 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_224 ;
if ( ( ( V_37 ) ( V_269 >> 0 ) != ( V_37 ) F_1 ( V_2 , V_251 ) ) ||
( ( V_37 ) ( V_269 >> 32 ) != ( V_37 ) F_1 ( V_2 , V_271 ) ) ) {
* F_2 ( V_2 , V_251 ) = ( V_37 ) ( V_269 >> 0 ) ;
* F_2 ( V_2 , V_271 ) = ( V_37 ) ( V_269 >> 32 ) ;
V_2 -> V_194 &= ~ V_237 ;
} else {
V_2 -> V_25 . V_23 = ( ( T_2 ) F_1 ( V_2 , V_193 ) << 32 ) |
( V_37 ) F_1 ( V_2 , V_164 ) ;
V_2 -> V_194 |= V_237 ;
}
return V_95 ;
}
static int F_114 ( struct V_1 * V_2 )
{
int V_96 ;
unsigned long V_31 ;
V_96 = F_94 ( V_2 , & V_31 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
return F_41 ( V_2 , V_31 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_96 ;
unsigned long V_31 , V_256 ;
int V_205 = V_2 -> V_6 -> V_205 ( V_2 ) ;
struct V_39 V_266 ;
V_96 = F_94 ( V_2 , & V_31 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_94 ( V_2 , & V_256 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
if ( V_2 -> V_41 >= V_101 && ( V_256 & 3 ) > V_205 )
return V_224 ;
V_96 = F_85 ( V_2 , ( V_36 ) V_256 , V_97 , V_205 ,
V_272 ,
& V_266 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_42 ( V_2 , V_31 , & V_266 ) ;
if ( V_96 != V_95 )
return V_224 ;
return V_96 ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = F_115 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_95 ;
}
static int F_117 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_151 = V_2 -> V_25 . V_34 ;
V_2 -> V_25 . V_34 = F_1 ( V_2 , V_251 ) ;
V_2 -> V_22 . V_151 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_151 ;
F_54 ( V_2 , V_273 ) ;
if ( V_2 -> V_194 & V_237 ) {
V_2 -> V_22 . type = V_123 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_151 ;
} else {
V_2 -> V_22 . type = V_149 ;
V_2 -> V_22 . V_82 . V_9 = F_3 ( V_2 , V_251 ) ;
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_151 ;
V_2 -> V_25 . V_34 = V_2 -> V_25 . V_151 ;
}
return V_95 ;
}
static int F_118 ( struct V_1 * V_2 )
{
int V_52 = V_2 -> V_246 . V_34 ;
unsigned short V_38 ;
int V_96 ;
memcpy ( & V_38 , V_2 -> V_22 . V_267 + V_2 -> V_98 , 2 ) ;
V_96 = F_89 ( V_2 , V_38 , V_52 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
return V_96 ;
}
static int F_119 ( struct V_1 * V_2 )
{
V_37 V_274 , V_275 , V_276 , V_277 ;
V_274 = 0x80000001 ;
V_276 = 0 ;
V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , false ) ;
return V_277 & F_120 ( V_279 ) ;
}
static void F_121 ( struct V_39 * V_49 , V_37 V_127 )
{
V_49 -> V_51 = ( V_127 >> 23 ) & 1 ;
V_49 -> V_45 = ( V_127 >> 22 ) & 1 ;
V_49 -> V_102 = ( V_127 >> 21 ) & 1 ;
V_49 -> V_280 = ( V_127 >> 20 ) & 1 ;
V_49 -> V_119 = ( V_127 >> 15 ) & 1 ;
V_49 -> V_210 = ( V_127 >> 13 ) & 3 ;
V_49 -> V_220 = ( V_127 >> 12 ) & 1 ;
V_49 -> type = ( V_127 >> 8 ) & 15 ;
}
static int F_122 ( struct V_1 * V_2 , T_2 V_281 , int V_191 )
{
struct V_39 V_49 ;
int V_282 ;
V_36 V_70 ;
V_70 = F_123 ( V_37 , V_281 , 0x7fa8 + V_191 * 4 ) ;
if ( V_191 < 3 )
V_282 = 0x7f84 + V_191 * 12 ;
else
V_282 = 0x7f2c + ( V_191 - 3 ) * 12 ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , V_282 + 8 ) ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , V_282 + 4 ) ) ;
F_121 ( & V_49 , F_123 ( V_37 , V_281 , V_282 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_191 ) ;
return V_95 ;
}
static int F_124 ( struct V_1 * V_2 , T_2 V_281 , int V_191 )
{
struct V_39 V_49 ;
int V_282 ;
V_36 V_70 ;
V_37 V_72 ;
V_282 = 0x7e00 + V_191 * 16 ;
V_70 = F_123 ( V_36 , V_281 , V_282 ) ;
F_121 ( & V_49 , F_123 ( V_36 , V_281 , V_282 + 2 ) << 8 ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , V_282 + 4 ) ) ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , V_282 + 8 ) ) ;
V_72 = F_123 ( V_37 , V_281 , V_282 + 12 ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_191 ) ;
return V_95 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_2 V_283 , T_2 V_284 )
{
int V_93 ;
V_93 = V_2 -> V_6 -> V_285 ( V_2 , 4 , V_284 & ~ V_286 ) ;
if ( V_93 )
return V_224 ;
V_93 = V_2 -> V_6 -> V_285 ( V_2 , 0 , V_283 ) ;
if ( V_93 )
return V_224 ;
if ( V_284 & V_286 ) {
V_93 = V_2 -> V_6 -> V_285 ( V_2 , 4 , V_284 ) ;
if ( V_93 )
return V_224 ;
}
return V_95 ;
}
static int F_126 ( struct V_1 * V_2 , T_2 V_281 )
{
struct V_39 V_49 ;
struct V_198 V_199 ;
V_36 V_70 ;
V_37 V_34 , V_283 , V_284 ;
int V_287 ;
V_283 = F_123 ( V_37 , V_281 , 0x7ffc ) ;
V_2 -> V_6 -> V_285 ( V_2 , 3 , F_123 ( V_37 , V_281 , 0x7ff8 ) ) ;
V_2 -> V_194 = F_123 ( V_37 , V_281 , 0x7ff4 ) | V_260 ;
V_2 -> V_99 = F_123 ( V_37 , V_281 , 0x7ff0 ) ;
for ( V_287 = 0 ; V_287 < 8 ; V_287 ++ )
* F_2 ( V_2 , V_287 ) = F_123 ( V_37 , V_281 , 0x7fd0 + V_287 * 4 ) ;
V_34 = F_123 ( V_37 , V_281 , 0x7fcc ) ;
V_2 -> V_6 -> V_288 ( V_2 , 6 , ( V_34 & V_289 ) | V_290 ) ;
V_34 = F_123 ( V_37 , V_281 , 0x7fc8 ) ;
V_2 -> V_6 -> V_288 ( V_2 , 7 , ( V_34 & V_291 ) | V_292 ) ;
V_70 = F_123 ( V_37 , V_281 , 0x7fc4 ) ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f64 ) ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f60 ) ) ;
F_121 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f5c ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_221 ) ;
V_70 = F_123 ( V_37 , V_281 , 0x7fc0 ) ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f80 ) ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f7c ) ) ;
F_121 ( & V_49 , F_123 ( V_37 , V_281 , 0x7f78 ) ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , 0 , V_202 ) ;
V_199 . V_122 = F_123 ( V_37 , V_281 , 0x7f74 ) ;
V_199 . V_74 = F_123 ( V_37 , V_281 , 0x7f70 ) ;
V_2 -> V_6 -> V_293 ( V_2 , & V_199 ) ;
V_199 . V_122 = F_123 ( V_37 , V_281 , 0x7f58 ) ;
V_199 . V_74 = F_123 ( V_37 , V_281 , 0x7f54 ) ;
V_2 -> V_6 -> V_294 ( V_2 , & V_199 ) ;
for ( V_287 = 0 ; V_287 < 6 ; V_287 ++ ) {
int V_295 = F_122 ( V_2 , V_281 , V_287 ) ;
if ( V_295 != V_95 )
return V_295 ;
}
V_284 = F_123 ( V_37 , V_281 , 0x7f14 ) ;
V_2 -> V_6 -> V_296 ( V_2 , F_123 ( V_37 , V_281 , 0x7ef8 ) ) ;
return F_125 ( V_2 , V_283 , V_284 ) ;
}
static int F_127 ( struct V_1 * V_2 , T_2 V_281 )
{
struct V_39 V_49 ;
struct V_198 V_199 ;
T_2 V_34 , V_283 , V_284 ;
V_37 V_72 ;
V_36 V_70 ;
int V_287 , V_295 ;
for ( V_287 = 0 ; V_287 < 16 ; V_287 ++ )
* F_2 ( V_2 , V_287 ) = F_123 ( T_2 , V_281 , 0x7ff8 - V_287 * 8 ) ;
V_2 -> V_99 = F_123 ( T_2 , V_281 , 0x7f78 ) ;
V_2 -> V_194 = F_123 ( V_37 , V_281 , 0x7f70 ) | V_260 ;
V_34 = F_123 ( V_37 , V_281 , 0x7f68 ) ;
V_2 -> V_6 -> V_288 ( V_2 , 6 , ( V_34 & V_289 ) | V_290 ) ;
V_34 = F_123 ( V_37 , V_281 , 0x7f60 ) ;
V_2 -> V_6 -> V_288 ( V_2 , 7 , ( V_34 & V_291 ) | V_292 ) ;
V_283 = F_123 ( T_2 , V_281 , 0x7f58 ) ;
V_2 -> V_6 -> V_285 ( V_2 , 3 , F_123 ( T_2 , V_281 , 0x7f50 ) ) ;
V_284 = F_123 ( T_2 , V_281 , 0x7f48 ) ;
V_2 -> V_6 -> V_296 ( V_2 , F_123 ( V_37 , V_281 , 0x7f00 ) ) ;
V_34 = F_123 ( T_2 , V_281 , 0x7ed0 ) ;
V_2 -> V_6 -> V_297 ( V_2 , V_105 , V_34 & ~ V_106 ) ;
V_70 = F_123 ( V_37 , V_281 , 0x7e90 ) ;
F_121 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e92 ) << 8 ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e94 ) ) ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e98 ) ) ;
V_72 = F_123 ( V_37 , V_281 , 0x7e9c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_221 ) ;
V_199 . V_74 = F_123 ( V_37 , V_281 , 0x7e84 ) ;
V_199 . V_122 = F_123 ( T_2 , V_281 , 0x7e88 ) ;
V_2 -> V_6 -> V_294 ( V_2 , & V_199 ) ;
V_70 = F_123 ( V_37 , V_281 , 0x7e70 ) ;
F_121 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e72 ) << 8 ) ;
F_87 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e74 ) ) ;
F_86 ( & V_49 , F_123 ( V_37 , V_281 , 0x7e78 ) ) ;
V_72 = F_123 ( V_37 , V_281 , 0x7e7c ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_49 , V_72 , V_202 ) ;
V_199 . V_74 = F_123 ( V_37 , V_281 , 0x7e64 ) ;
V_199 . V_122 = F_123 ( T_2 , V_281 , 0x7e68 ) ;
V_2 -> V_6 -> V_293 ( V_2 , & V_199 ) ;
V_295 = F_125 ( V_2 , V_283 , V_284 ) ;
if ( V_295 != V_95 )
return V_295 ;
for ( V_287 = 0 ; V_287 < 6 ; V_287 ++ ) {
V_295 = F_124 ( V_2 , V_281 , V_287 ) ;
if ( V_295 != V_95 )
return V_295 ;
}
return V_95 ;
}
static int F_128 ( struct V_1 * V_2 )
{
unsigned long V_283 , V_284 , V_103 ;
T_2 V_281 ;
int V_216 ;
if ( ( V_2 -> V_6 -> V_298 ( V_2 ) & V_299 ) == 0 )
return F_27 ( V_2 ) ;
V_284 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) ;
if ( F_119 ( V_2 ) ) {
struct V_39 V_100 ;
if ( V_284 & V_286 ) {
V_2 -> V_6 -> V_285 ( V_2 , 4 , V_284 & ~ V_286 ) ;
V_284 &= ~ V_286 ;
}
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . type = 0xb ;
V_100 . V_220 = V_100 . V_51 = V_100 . V_119 = 1 ;
V_2 -> V_6 -> V_73 ( V_2 , 0 , & V_100 , 0 , V_97 ) ;
}
V_283 = V_2 -> V_6 -> V_135 ( V_2 , 0 ) ;
if ( V_283 & V_300 )
V_2 -> V_6 -> V_285 ( V_2 , 0 , V_283 & ~ ( V_301 | V_300 ) ) ;
if ( V_284 & V_302 )
V_2 -> V_6 -> V_285 ( V_2 , 4 , V_284 & ~ V_302 ) ;
V_103 = 0 ;
V_2 -> V_6 -> V_297 ( V_2 , V_105 , V_103 ) ;
V_281 = V_2 -> V_6 -> V_303 ( V_2 ) ;
if ( F_119 ( V_2 ) )
V_216 = F_127 ( V_2 , V_281 + 0x8000 ) ;
else
V_216 = F_126 ( V_2 , V_281 + 0x8000 ) ;
if ( V_216 != V_95 ) {
return V_224 ;
}
if ( ( V_2 -> V_6 -> V_298 ( V_2 ) & V_304 ) == 0 )
V_2 -> V_6 -> V_265 ( V_2 , false ) ;
V_2 -> V_6 -> V_305 ( V_2 , V_2 -> V_6 -> V_298 ( V_2 ) &
~ ( V_304 | V_299 ) ) ;
return V_95 ;
}
static void
F_129 ( struct V_1 * V_2 ,
struct V_39 * V_256 , struct V_39 * V_40 )
{
V_256 -> V_102 = 0 ;
F_86 ( V_256 , 0 ) ;
V_256 -> V_51 = 1 ;
F_87 ( V_256 , 0xfffff ) ;
V_256 -> type = 0x0b ;
V_256 -> V_220 = 1 ;
V_256 -> V_210 = 0 ;
V_256 -> V_119 = 1 ;
V_256 -> V_45 = 1 ;
V_256 -> V_280 = 0 ;
F_86 ( V_40 , 0 ) ;
F_87 ( V_40 , 0xfffff ) ;
V_40 -> V_51 = 1 ;
V_40 -> V_220 = 1 ;
V_40 -> type = 0x03 ;
V_40 -> V_45 = 1 ;
V_40 -> V_210 = 0 ;
V_40 -> V_119 = 1 ;
V_40 -> V_102 = 0 ;
V_40 -> V_280 = 0 ;
}
static bool F_130 ( struct V_1 * V_2 )
{
V_37 V_274 , V_275 , V_276 , V_277 ;
V_274 = V_276 = 0 ;
V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , false ) ;
return V_275 == V_306
&& V_276 == V_307
&& V_277 == V_308 ;
}
static bool F_131 ( struct V_1 * V_2 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
V_37 V_274 , V_275 , V_276 , V_277 ;
if ( V_2 -> V_41 == V_42 )
return true ;
V_274 = 0x00000000 ;
V_276 = 0x00000000 ;
V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , false ) ;
if ( V_275 == V_306 &&
V_276 == V_307 &&
V_277 == V_308 )
return false ;
if ( V_275 == V_309 &&
V_276 == V_310 &&
V_277 == V_311 )
return true ;
if ( V_275 == V_312 &&
V_276 == V_313 &&
V_277 == V_314 )
return true ;
return false ;
}
static int F_132 ( struct V_1 * V_2 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_39 V_256 , V_40 ;
T_2 V_315 ;
V_36 V_316 , V_317 ;
T_2 V_103 = 0 ;
if ( V_2 -> V_41 == V_94 ||
V_2 -> V_41 == V_219 )
return F_27 ( V_2 ) ;
if ( ! ( F_131 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
F_129 ( V_2 , & V_256 , & V_40 ) ;
if ( ! ( V_103 & V_318 ) )
return F_27 ( V_2 ) ;
V_6 -> V_104 ( V_2 , V_319 , & V_315 ) ;
V_315 >>= 32 ;
V_316 = ( V_36 ) ( V_315 & 0xfffc ) ;
V_317 = ( V_36 ) ( V_315 + 8 ) ;
if ( V_103 & V_106 ) {
V_256 . V_45 = 0 ;
V_256 . V_102 = 1 ;
}
V_6 -> V_73 ( V_2 , V_316 , & V_256 , 0 , V_97 ) ;
V_6 -> V_73 ( V_2 , V_317 , & V_40 , 0 , V_44 ) ;
* F_2 ( V_2 , V_193 ) = V_2 -> V_99 ;
if ( V_103 & V_106 ) {
#ifdef F_43
* F_2 ( V_2 , V_320 ) = V_2 -> V_194 ;
V_6 -> V_104 ( V_2 ,
V_2 -> V_41 == V_42 ?
V_321 : V_322 , & V_315 ) ;
V_2 -> V_99 = V_315 ;
V_6 -> V_104 ( V_2 , V_323 , & V_315 ) ;
V_2 -> V_194 &= ~ V_315 ;
V_2 -> V_194 |= V_260 ;
#endif
} else {
V_6 -> V_104 ( V_2 , V_319 , & V_315 ) ;
V_2 -> V_99 = ( V_37 ) V_315 ;
V_2 -> V_194 &= ~ ( V_252 | V_130 ) ;
}
V_2 -> V_324 = ( V_2 -> V_194 & V_240 ) != 0 ;
return V_95 ;
}
static int F_133 ( struct V_1 * V_2 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_39 V_256 , V_40 ;
T_2 V_315 ;
V_36 V_316 , V_317 ;
T_2 V_103 = 0 ;
V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( V_2 -> V_41 == V_94 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_41 != V_42 ) && ( V_103 & V_106 )
&& ! F_130 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 )
return V_224 ;
F_129 ( V_2 , & V_256 , & V_40 ) ;
V_6 -> V_104 ( V_2 , V_325 , & V_315 ) ;
if ( ( V_315 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_194 &= ~ ( V_252 | V_130 ) ;
V_316 = ( V_36 ) V_315 & ~ V_326 ;
V_317 = V_316 + 8 ;
if ( V_103 & V_106 ) {
V_256 . V_45 = 0 ;
V_256 . V_102 = 1 ;
}
V_6 -> V_73 ( V_2 , V_316 , & V_256 , 0 , V_97 ) ;
V_6 -> V_73 ( V_2 , V_317 , & V_40 , 0 , V_44 ) ;
V_6 -> V_104 ( V_2 , V_327 , & V_315 ) ;
V_2 -> V_99 = ( V_103 & V_106 ) ? V_315 : ( V_37 ) V_315 ;
V_6 -> V_104 ( V_2 , V_328 , & V_315 ) ;
* F_2 ( V_2 , V_48 ) = ( V_103 & V_106 ) ? V_315 :
( V_37 ) V_315 ;
return V_95 ;
}
static int F_134 ( struct V_1 * V_2 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_39 V_256 , V_40 ;
T_2 V_315 , V_329 , V_330 ;
int V_331 ;
V_36 V_316 = 0 , V_317 = 0 ;
if ( V_2 -> V_41 == V_94 ||
V_2 -> V_41 == V_219 )
return F_25 ( V_2 , 0 ) ;
F_129 ( V_2 , & V_256 , & V_40 ) ;
if ( ( V_2 -> V_121 & 0x8 ) != 0x0 )
V_331 = V_42 ;
else
V_331 = V_107 ;
V_329 = F_1 ( V_2 , V_193 ) ;
V_330 = F_1 ( V_2 , V_271 ) ;
V_256 . V_210 = 3 ;
V_40 . V_210 = 3 ;
V_6 -> V_104 ( V_2 , V_325 , & V_315 ) ;
switch ( V_331 ) {
case V_107 :
V_316 = ( V_36 ) ( V_315 + 16 ) ;
if ( ( V_315 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_317 = ( V_36 ) ( V_315 + 24 ) ;
V_329 = ( V_37 ) V_329 ;
V_330 = ( V_37 ) V_330 ;
break;
case V_42 :
V_316 = ( V_36 ) ( V_315 + 32 ) ;
if ( V_315 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_317 = V_316 + 8 ;
V_256 . V_45 = 0 ;
V_256 . V_102 = 1 ;
if ( F_88 ( V_329 , V_2 ) ||
F_88 ( V_330 , V_2 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
V_316 |= V_326 ;
V_317 |= V_326 ;
V_6 -> V_73 ( V_2 , V_316 , & V_256 , 0 , V_97 ) ;
V_6 -> V_73 ( V_2 , V_317 , & V_40 , 0 , V_44 ) ;
V_2 -> V_99 = V_330 ;
* F_2 ( V_2 , V_48 ) = V_329 ;
return V_95 ;
}
static bool F_135 ( struct V_1 * V_2 )
{
int V_231 ;
if ( V_2 -> V_41 == V_94 )
return false ;
if ( V_2 -> V_41 == V_219 )
return true ;
V_231 = ( V_2 -> V_194 & V_232 ) >> V_233 ;
return V_2 -> V_6 -> V_205 ( V_2 ) > V_231 ;
}
static bool F_136 ( struct V_1 * V_2 ,
V_36 V_188 , V_36 V_229 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_39 V_332 ;
V_37 V_72 ;
int V_295 ;
V_36 V_333 , V_334 , V_335 , V_336 = V_188 & 0x7 ;
unsigned V_33 = ( 1 << V_229 ) - 1 ;
unsigned long V_337 ;
V_6 -> V_43 ( V_2 , & V_333 , & V_332 , & V_72 , V_221 ) ;
if ( ! V_332 . V_119 )
return false ;
if ( F_19 ( & V_332 ) < 103 )
return false ;
V_337 = F_81 ( & V_332 ) ;
#ifdef F_43
V_337 |= ( ( T_2 ) V_72 ) << 32 ;
#endif
V_295 = V_6 -> V_110 ( V_2 , V_337 + 102 , & V_334 , 2 , NULL ) ;
if ( V_295 != V_95 )
return false ;
if ( V_334 + V_188 / 8 > F_19 ( & V_332 ) )
return false ;
V_295 = V_6 -> V_110 ( V_2 , V_337 + V_334 + V_188 / 8 , & V_335 , 2 , NULL ) ;
if ( V_295 != V_95 )
return false ;
if ( ( V_335 >> V_336 ) & V_33 )
return false ;
return true ;
}
static bool F_137 ( struct V_1 * V_2 ,
V_36 V_188 , V_36 V_229 )
{
if ( V_2 -> V_338 )
return true ;
if ( F_135 ( V_2 ) )
if ( ! F_136 ( V_2 , V_188 , V_229 ) )
return false ;
V_2 -> V_338 = true ;
return true ;
}
static void F_138 ( struct V_1 * V_2 )
{
#ifdef F_43
if ( V_2 -> V_29 != 4 || ! F_130 ( V_2 ) )
return;
* F_2 ( V_2 , V_193 ) = 0 ;
switch ( V_2 -> V_141 ) {
case 0xa4 :
case 0xa5 :
* F_3 ( V_2 , V_167 ) &= ( V_37 ) - 1 ;
case 0xaa :
case 0xab :
* F_3 ( V_2 , V_169 ) &= ( V_37 ) - 1 ;
}
#endif
}
static void F_139 ( struct V_1 * V_2 ,
struct V_339 * V_340 )
{
V_340 -> V_341 = V_2 -> V_99 ;
V_340 -> V_342 = V_2 -> V_194 ;
V_340 -> V_343 = F_1 ( V_2 , V_251 ) ;
V_340 -> V_344 = F_1 ( V_2 , V_193 ) ;
V_340 -> V_345 = F_1 ( V_2 , V_271 ) ;
V_340 -> V_163 = F_1 ( V_2 , V_164 ) ;
V_340 -> V_346 = F_1 ( V_2 , V_48 ) ;
V_340 -> V_165 = F_1 ( V_2 , V_153 ) ;
V_340 -> V_166 = F_1 ( V_2 , V_167 ) ;
V_340 -> V_168 = F_1 ( V_2 , V_169 ) ;
V_340 -> V_347 = F_31 ( V_2 , V_348 ) ;
V_340 -> V_256 = F_31 ( V_2 , V_97 ) ;
V_340 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_340 -> V_349 = F_31 ( V_2 , V_160 ) ;
V_340 -> V_350 = F_31 ( V_2 , V_202 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_339 * V_340 )
{
int V_216 ;
V_35 V_205 ;
V_2 -> V_99 = V_340 -> V_341 ;
V_2 -> V_194 = V_340 -> V_342 | 2 ;
* F_2 ( V_2 , V_251 ) = V_340 -> V_343 ;
* F_2 ( V_2 , V_193 ) = V_340 -> V_344 ;
* F_2 ( V_2 , V_271 ) = V_340 -> V_345 ;
* F_2 ( V_2 , V_164 ) = V_340 -> V_163 ;
* F_2 ( V_2 , V_48 ) = V_340 -> V_346 ;
* F_2 ( V_2 , V_153 ) = V_340 -> V_165 ;
* F_2 ( V_2 , V_167 ) = V_340 -> V_166 ;
* F_2 ( V_2 , V_169 ) = V_340 -> V_168 ;
F_32 ( V_2 , V_340 -> V_350 , V_202 ) ;
F_32 ( V_2 , V_340 -> V_347 , V_348 ) ;
F_32 ( V_2 , V_340 -> V_256 , V_97 ) ;
F_32 ( V_2 , V_340 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_340 -> V_349 , V_160 ) ;
V_205 = V_340 -> V_256 & 3 ;
V_216 = F_85 ( V_2 , V_340 -> V_350 , V_202 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_347 , V_348 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_256 , V_97 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_40 , V_44 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_349 , V_160 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
return V_95 ;
}
static int F_141 ( struct V_1 * V_2 ,
V_36 V_351 , V_36 V_352 ,
T_1 V_353 , struct V_39 * V_266 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_339 V_354 ;
int V_216 ;
V_37 V_355 = F_81 ( V_266 ) ;
V_216 = V_6 -> V_110 ( V_2 , V_353 , & V_354 , sizeof V_354 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
F_139 ( V_2 , & V_354 ) ;
V_216 = V_6 -> V_111 ( V_2 , V_353 , & V_354 , sizeof V_354 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = V_6 -> V_110 ( V_2 , V_355 , & V_354 , sizeof V_354 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
if ( V_352 != 0xffff ) {
V_354 . V_356 = V_352 ;
V_216 = V_6 -> V_111 ( V_2 , V_355 ,
& V_354 . V_356 ,
sizeof V_354 . V_356 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
}
return F_140 ( V_2 , & V_354 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_357 * V_340 )
{
V_340 -> V_31 = V_2 -> V_99 ;
V_340 -> V_194 = V_2 -> V_194 ;
V_340 -> V_274 = F_1 ( V_2 , V_251 ) ;
V_340 -> V_276 = F_1 ( V_2 , V_193 ) ;
V_340 -> V_277 = F_1 ( V_2 , V_271 ) ;
V_340 -> V_275 = F_1 ( V_2 , V_164 ) ;
V_340 -> V_358 = F_1 ( V_2 , V_48 ) ;
V_340 -> V_359 = F_1 ( V_2 , V_153 ) ;
V_340 -> V_360 = F_1 ( V_2 , V_167 ) ;
V_340 -> V_361 = F_1 ( V_2 , V_169 ) ;
V_340 -> V_347 = F_31 ( V_2 , V_348 ) ;
V_340 -> V_256 = F_31 ( V_2 , V_97 ) ;
V_340 -> V_40 = F_31 ( V_2 , V_44 ) ;
V_340 -> V_349 = F_31 ( V_2 , V_160 ) ;
V_340 -> V_362 = F_31 ( V_2 , V_53 ) ;
V_340 -> V_363 = F_31 ( V_2 , V_218 ) ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_357 * V_340 )
{
int V_216 ;
V_35 V_205 ;
if ( V_2 -> V_6 -> V_285 ( V_2 , 3 , V_340 -> V_364 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_99 = V_340 -> V_31 ;
V_2 -> V_194 = V_340 -> V_194 | 2 ;
* F_2 ( V_2 , V_251 ) = V_340 -> V_274 ;
* F_2 ( V_2 , V_193 ) = V_340 -> V_276 ;
* F_2 ( V_2 , V_271 ) = V_340 -> V_277 ;
* F_2 ( V_2 , V_164 ) = V_340 -> V_275 ;
* F_2 ( V_2 , V_48 ) = V_340 -> V_358 ;
* F_2 ( V_2 , V_153 ) = V_340 -> V_359 ;
* F_2 ( V_2 , V_167 ) = V_340 -> V_360 ;
* F_2 ( V_2 , V_169 ) = V_340 -> V_361 ;
F_32 ( V_2 , V_340 -> V_365 , V_202 ) ;
F_32 ( V_2 , V_340 -> V_347 , V_348 ) ;
F_32 ( V_2 , V_340 -> V_256 , V_97 ) ;
F_32 ( V_2 , V_340 -> V_40 , V_44 ) ;
F_32 ( V_2 , V_340 -> V_349 , V_160 ) ;
F_32 ( V_2 , V_340 -> V_362 , V_53 ) ;
F_32 ( V_2 , V_340 -> V_363 , V_218 ) ;
if ( V_2 -> V_194 & V_252 ) {
V_2 -> V_41 = V_219 ;
V_205 = 3 ;
} else {
V_2 -> V_41 = V_107 ;
V_205 = V_340 -> V_256 & 3 ;
}
V_216 = F_85 ( V_2 , V_340 -> V_365 , V_202 ,
V_205 , V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_347 , V_348 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_256 , V_97 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_40 , V_44 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_349 , V_160 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_362 , V_53 , V_205 ,
V_222 , NULL ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_85 ( V_2 , V_340 -> V_363 , V_218 , V_205 ,
V_222 , NULL ) ;
return V_216 ;
}
static int F_144 ( struct V_1 * V_2 ,
V_36 V_351 , V_36 V_352 ,
T_1 V_353 , struct V_39 * V_266 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_357 V_354 ;
int V_216 ;
V_37 V_355 = F_81 ( V_266 ) ;
V_37 V_366 = F_145 ( struct V_357 , V_31 ) ;
V_37 V_367 = F_145 ( struct V_357 , V_365 ) ;
V_216 = V_6 -> V_110 ( V_2 , V_353 , & V_354 , sizeof V_354 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
F_142 ( V_2 , & V_354 ) ;
V_216 = V_6 -> V_111 ( V_2 , V_353 + V_366 , & V_354 . V_31 ,
V_367 - V_366 , & V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = V_6 -> V_110 ( V_2 , V_355 , & V_354 , sizeof V_354 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
if ( V_352 != 0xffff ) {
V_354 . V_356 = V_352 ;
V_216 = V_6 -> V_111 ( V_2 , V_355 ,
& V_354 . V_356 ,
sizeof V_354 . V_356 ,
& V_2 -> V_57 ) ;
if ( V_216 != V_95 )
return V_216 ;
}
return F_143 ( V_2 , & V_354 ) ;
}
static int F_146 ( struct V_1 * V_2 ,
V_36 V_351 , int V_368 , int V_369 ,
bool V_370 , V_37 V_59 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
struct V_39 V_371 , V_372 ;
int V_216 ;
V_36 V_352 = F_31 ( V_2 , V_221 ) ;
T_1 V_353 =
V_6 -> V_54 ( V_2 , V_221 ) ;
V_37 V_373 ;
T_1 V_215 , V_374 ;
V_216 = F_83 ( V_2 , V_351 , & V_372 , & V_215 ) ;
if ( V_216 != V_95 )
return V_216 ;
V_216 = F_83 ( V_2 , V_352 , & V_371 , & V_215 ) ;
if ( V_216 != V_95 )
return V_216 ;
if ( V_369 == V_375 ) {
if ( V_368 != - 1 ) {
struct V_39 V_376 ;
int V_210 ;
V_216 = F_79 ( V_2 , V_368 ,
& V_376 ) ;
if ( V_216 != V_95 )
return V_216 ;
V_210 = V_376 . V_210 ;
if ( ( V_351 & 3 ) > V_210 || V_6 -> V_205 ( V_2 ) > V_210 )
return F_25 ( V_2 , ( V_368 << 3 ) | 0x2 ) ;
}
}
V_373 = F_19 ( & V_372 ) ;
if ( ! V_372 . V_119 ||
( ( V_373 < 0x67 && ( V_372 . type & 8 ) ) ||
V_373 < 0x2b ) ) {
return F_28 ( V_2 , V_351 & 0xfffc ) ;
}
if ( V_369 == V_377 || V_369 == V_378 ) {
V_371 . type &= ~ ( 1 << 1 ) ;
F_84 ( V_2 , V_352 , & V_371 ) ;
}
if ( V_369 == V_377 )
V_2 -> V_194 = V_2 -> V_194 & ~ V_241 ;
if ( V_369 != V_379 && V_369 != V_375 )
V_352 = 0xffff ;
if ( V_372 . type & 8 )
V_216 = F_144 ( V_2 , V_351 , V_352 ,
V_353 , & V_372 ) ;
else
V_216 = F_141 ( V_2 , V_351 , V_352 ,
V_353 , & V_372 ) ;
if ( V_216 != V_95 )
return V_216 ;
if ( V_369 == V_379 || V_369 == V_375 )
V_2 -> V_194 = V_2 -> V_194 | V_241 ;
if ( V_369 != V_377 ) {
V_372 . type |= ( 1 << 1 ) ;
F_84 ( V_2 , V_351 , & V_372 ) ;
}
V_6 -> V_285 ( V_2 , 0 , V_6 -> V_135 ( V_2 , 0 ) | V_136 ) ;
V_6 -> V_73 ( V_2 , V_351 , & V_372 , 0 , V_221 ) ;
if ( V_370 ) {
V_2 -> V_98 = V_2 -> V_29 = ( V_372 . type & 8 ) ? 4 : 2 ;
V_2 -> V_227 = 0 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_59 ;
V_216 = F_93 ( V_2 ) ;
}
V_6 -> V_380 ( V_2 , 7 , & V_374 ) ;
V_6 -> V_288 ( V_2 , 7 , V_374 & ~ ( V_381 | V_382 ) ) ;
return V_216 ;
}
int F_147 ( struct V_1 * V_2 ,
V_36 V_351 , int V_368 , int V_369 ,
bool V_370 , V_37 V_59 )
{
int V_96 ;
F_6 ( V_2 ) ;
V_2 -> V_99 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_123 ;
V_96 = F_146 ( V_2 , V_351 , V_368 , V_369 ,
V_370 , V_59 ) ;
if ( V_96 == V_95 ) {
V_2 -> V_31 = V_2 -> V_99 ;
F_4 ( V_2 ) ;
}
return ( V_96 == V_224 ) ? V_383 : V_384 ;
}
static void F_148 ( struct V_1 * V_2 , int V_9 ,
struct V_131 * V_132 )
{
int V_385 = ( V_2 -> V_194 & V_195 ) ? - V_132 -> V_192 : V_132 -> V_192 ;
F_17 ( V_2 , V_9 , V_385 * V_132 -> V_27 ) ;
V_132 -> V_82 . V_174 . V_92 = F_15 ( V_2 , V_9 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
V_35 V_386 , V_387 ;
bool V_388 , V_389 , V_390 ;
V_389 = V_2 -> V_194 & V_234 ;
V_386 = V_2 -> V_25 . V_34 ;
V_387 = V_386 ;
V_390 = V_389 ;
V_389 = false ;
V_388 = V_2 -> V_194 & V_236 ;
if ( ( V_386 & 0x0f ) > 9 || V_388 ) {
V_386 -= 6 ;
V_389 = V_390 | ( V_386 >= 250 ) ;
V_388 = true ;
} else {
V_388 = false ;
}
if ( V_387 > 0x99 || V_390 ) {
V_386 -= 0x60 ;
V_389 = true ;
}
V_2 -> V_25 . V_34 = V_386 ;
V_2 -> V_22 . type = V_391 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_54 ( V_2 , V_392 ) ;
V_2 -> V_194 &= ~ ( V_236 | V_234 ) ;
if ( V_389 )
V_2 -> V_194 |= V_234 ;
if ( V_388 )
V_2 -> V_194 |= V_236 ;
return V_95 ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_35 V_386 , V_393 ;
if ( V_2 -> V_22 . V_34 == 0 )
return F_29 ( V_2 ) ;
V_386 = V_2 -> V_25 . V_34 & 0xff ;
V_393 = V_386 / V_2 -> V_22 . V_34 ;
V_386 %= V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_386 | ( V_393 << 8 ) ;
V_2 -> V_22 . type = V_391 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_54 ( V_2 , V_392 ) ;
return V_95 ;
}
static int F_151 ( struct V_1 * V_2 )
{
V_35 V_386 = V_2 -> V_25 . V_34 & 0xff ;
V_35 V_393 = ( V_2 -> V_25 . V_34 >> 8 ) & 0xff ;
V_386 = ( V_386 + ( V_393 * V_2 -> V_22 . V_34 ) ) & 0xff ;
V_2 -> V_25 . V_34 = ( V_2 -> V_25 . V_34 & 0xffff0000 ) | V_386 ;
V_2 -> V_22 . type = V_391 ;
V_2 -> V_22 . V_34 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_54 ( V_2 , V_392 ) ;
return V_95 ;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_96 ;
long V_108 = V_2 -> V_22 . V_34 ;
V_2 -> V_22 . V_34 = ( unsigned long ) V_2 -> V_99 ;
V_96 = F_44 ( V_2 , V_108 ) ;
if ( V_96 != V_95 )
return V_96 ;
return F_93 ( V_2 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_36 V_38 , V_394 ;
T_1 V_268 ;
int V_96 ;
struct V_39 V_209 , V_266 ;
const struct V_201 * V_6 = V_2 -> V_6 ;
int V_205 = V_2 -> V_6 -> V_205 ( V_2 ) ;
enum V_86 V_395 = V_2 -> V_41 ;
V_268 = V_2 -> V_99 ;
V_6 -> V_43 ( V_2 , & V_394 , & V_209 , NULL , V_97 ) ;
memcpy ( & V_38 , V_2 -> V_22 . V_267 + V_2 -> V_98 , 2 ) ;
V_96 = F_85 ( V_2 , V_38 , V_97 , V_205 ,
V_223 , & V_266 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_42 ( V_2 , V_2 -> V_22 . V_34 , & V_266 ) ;
if ( V_96 != V_95 )
goto V_396;
V_2 -> V_22 . V_34 = V_394 ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 )
goto V_396;
V_2 -> V_22 . V_34 = V_268 ;
V_96 = F_93 ( V_2 ) ;
if ( V_96 != V_95 ) {
F_154 ( L_1 ) ;
goto V_396;
}
return V_96 ;
V_396:
V_6 -> V_73 ( V_2 , V_394 , & V_209 , 0 , V_97 ) ;
V_2 -> V_41 = V_395 ;
return V_96 ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_96 ;
unsigned long V_31 ;
V_96 = F_94 ( V_2 , & V_31 , V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_96 = F_41 ( V_2 , V_31 ) ;
if ( V_96 != V_95 )
return V_96 ;
F_18 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_95 ;
}
static int F_156 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_34 = V_2 -> V_25 . V_34 ;
F_90 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_151 ;
V_2 -> V_227 = 1 ;
return V_95 ;
}
static int F_157 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = V_2 -> V_246 . V_34 ;
return F_54 ( V_2 , V_397 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_149 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_82 . V_9 = F_3 ( V_2 , V_271 ) ;
V_2 -> V_25 . V_34 = ~ ( ( V_2 -> V_22 . V_34 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_95 ;
}
static int F_159 ( struct V_1 * V_2 )
{
T_2 V_398 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_399 , & V_398 ) ;
* F_2 ( V_2 , V_251 ) = ( V_37 ) V_398 ;
* F_2 ( V_2 , V_271 ) = V_398 >> 32 ;
return V_95 ;
}
static int F_160 ( struct V_1 * V_2 )
{
T_2 V_400 ;
if ( V_2 -> V_6 -> V_401 ( V_2 , F_1 ( V_2 , V_193 ) , & V_400 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_251 ) = ( V_37 ) V_400 ;
* F_2 ( V_2 , V_271 ) = V_400 >> 32 ;
return V_95 ;
}
static int F_161 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_267 , V_2 -> V_22 . V_267 , sizeof( V_2 -> V_22 . V_267 ) ) ;
return V_95 ;
}
static int F_162 ( struct V_1 * V_2 )
{
V_37 V_275 , V_276 , V_277 , V_274 = 1 ;
V_36 V_402 ;
V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , false ) ;
if ( ! ( V_276 & F_163 ( V_403 ) ) )
return F_27 ( V_2 ) ;
switch ( V_2 -> V_98 ) {
case 2 :
V_402 = ( V_36 ) V_2 -> V_22 . V_34 ;
V_2 -> V_25 . V_34 &= ~ 0xffffUL ;
V_2 -> V_25 . V_34 |= ( unsigned long ) F_164 ( V_402 ) ;
break;
case 4 :
V_2 -> V_25 . V_34 = F_165 ( ( V_37 ) V_2 -> V_22 . V_34 ) ;
break;
case 8 :
V_2 -> V_25 . V_34 = F_166 ( V_2 -> V_22 . V_34 ) ;
break;
default:
F_60 () ;
}
return V_95 ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_285 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_34 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_168 ( struct V_1 * V_2 )
{
unsigned long V_34 ;
if ( V_2 -> V_41 == V_42 )
V_34 = V_2 -> V_22 . V_34 & ~ 0ULL ;
else
V_34 = V_2 -> V_22 . V_34 & ~ 0U ;
if ( V_2 -> V_6 -> V_288 ( V_2 , V_2 -> V_19 , V_34 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_169 ( struct V_1 * V_2 )
{
T_2 V_315 ;
V_315 = ( V_37 ) F_1 ( V_2 , V_251 )
| ( ( T_2 ) F_1 ( V_2 , V_271 ) << 32 ) ;
if ( V_2 -> V_6 -> V_297 ( V_2 , F_1 ( V_2 , V_193 ) , V_315 ) )
return F_25 ( V_2 , 0 ) ;
return V_95 ;
}
static int F_170 ( struct V_1 * V_2 )
{
T_2 V_315 ;
if ( V_2 -> V_6 -> V_104 ( V_2 , F_1 ( V_2 , V_193 ) , & V_315 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_251 ) = ( V_37 ) V_315 ;
* F_2 ( V_2 , V_271 ) = V_315 >> 32 ;
return V_95 ;
}
static int F_171 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_218 )
return F_27 ( V_2 ) ;
V_2 -> V_25 . V_34 = F_31 ( V_2 , V_2 -> V_19 ) ;
if ( V_2 -> V_25 . V_27 == 4 && V_2 -> V_25 . type == V_162 )
V_2 -> V_25 . V_27 = 2 ;
return V_95 ;
}
static int F_172 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
if ( V_2 -> V_19 == V_97 || V_2 -> V_19 > V_218 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_44 )
V_2 -> V_248 = V_249 ;
V_2 -> V_25 . type = V_123 ;
return F_89 ( V_2 , V_38 , V_2 -> V_19 ) ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_123 ;
return F_89 ( V_2 , V_38 , V_202 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_36 V_38 = V_2 -> V_22 . V_34 ;
V_2 -> V_25 . type = V_123 ;
return F_89 ( V_2 , V_38 , V_221 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_96 ;
T_1 V_87 ;
V_96 = F_39 ( V_2 , V_2 -> V_22 . V_82 . V_174 , 1 , false , & V_87 ) ;
if ( V_96 == V_95 )
V_2 -> V_6 -> V_404 ( V_2 , V_87 ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_176 ( struct V_1 * V_2 )
{
T_1 V_283 ;
V_283 = V_2 -> V_6 -> V_135 ( V_2 , 0 ) ;
V_283 &= ~ V_136 ;
V_2 -> V_6 -> V_285 ( V_2 , 0 , V_283 ) ;
return V_95 ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_96 = V_2 -> V_6 -> V_405 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_99 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_178 ( struct V_1 * V_2 ,
void (* F_179)( struct V_1 * V_2 ,
struct V_198 * V_117 ) )
{
struct V_198 V_198 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_98 = 8 ;
F_179 ( V_2 , & V_198 ) ;
if ( V_2 -> V_98 == 2 ) {
V_2 -> V_98 = 4 ;
V_198 . V_122 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_123 ;
return F_46 ( V_2 , V_2 -> V_25 . V_82 . V_174 ,
& V_198 , 2 + V_2 -> V_98 ) ;
}
static int F_180 ( struct V_1 * V_2 )
{
return F_178 ( V_2 , V_2 -> V_6 -> V_203 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
return F_178 ( V_2 , V_2 -> V_6 -> V_200 ) ;
}
static int F_182 ( struct V_1 * V_2 , bool V_406 )
{
struct V_198 V_198 ;
int V_96 ;
if ( V_2 -> V_41 == V_42 )
V_2 -> V_98 = 8 ;
V_96 = F_52 ( V_2 , V_2 -> V_22 . V_82 . V_174 ,
& V_198 . V_74 , & V_198 . V_122 ,
V_2 -> V_98 ) ;
if ( V_96 != V_95 )
return V_96 ;
if ( V_2 -> V_41 == V_42 &&
F_88 ( V_198 . V_122 , V_2 ) )
return F_25 ( V_2 , 0 ) ;
if ( V_406 )
V_2 -> V_6 -> V_293 ( V_2 , & V_198 ) ;
else
V_2 -> V_6 -> V_294 ( V_2 , & V_198 ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_183 ( struct V_1 * V_2 )
{
return F_182 ( V_2 , true ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
return F_182 ( V_2 , false ) ;
}
static int F_185 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_162 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_34 = V_2 -> V_6 -> V_135 ( V_2 , 0 ) ;
return V_95 ;
}
static int F_186 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_285 ( V_2 , 0 , ( V_2 -> V_6 -> V_135 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_34 & 0x0f ) ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_187 ( struct V_1 * V_2 )
{
int V_96 = V_95 ;
F_17 ( V_2 , V_193 , - 1 ) ;
if ( ( F_14 ( V_2 , F_1 ( V_2 , V_193 ) ) != 0 ) &&
( V_2 -> V_141 == 0xe2 || F_56 ( V_2 -> V_141 ^ 0x5 , V_2 -> V_194 ) ) )
V_96 = F_44 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_96 ;
}
static int F_188 ( struct V_1 * V_2 )
{
int V_96 = V_95 ;
if ( F_14 ( V_2 , F_1 ( V_2 , V_193 ) ) == 0 )
V_96 = F_44 ( V_2 , V_2 -> V_22 . V_34 ) ;
return V_96 ;
}
static int F_189 ( struct V_1 * V_2 )
{
if ( ! F_77 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_34 ,
& V_2 -> V_25 . V_34 ) )
return V_407 ;
return V_95 ;
}
static int F_190 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_408 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_34 ,
& V_2 -> V_22 . V_34 , 1 ) ;
V_2 -> V_25 . type = V_123 ;
return V_95 ;
}
static int F_191 ( struct V_1 * V_2 )
{
if ( F_135 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_194 &= ~ V_130 ;
return V_95 ;
}
static int F_192 ( struct V_1 * V_2 )
{
if ( F_135 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_248 = V_409 ;
V_2 -> V_194 |= V_130 ;
return V_95 ;
}
static int F_193 ( struct V_1 * V_2 )
{
V_37 V_274 , V_275 , V_276 , V_277 ;
T_2 V_410 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_411 , & V_410 ) ;
if ( V_410 & V_412 &&
V_2 -> V_6 -> V_205 ( V_2 ) ) {
return F_25 ( V_2 , 0 ) ;
}
V_274 = F_1 ( V_2 , V_251 ) ;
V_276 = F_1 ( V_2 , V_193 ) ;
V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , true ) ;
* F_2 ( V_2 , V_251 ) = V_274 ;
* F_2 ( V_2 , V_164 ) = V_275 ;
* F_2 ( V_2 , V_193 ) = V_276 ;
* F_2 ( V_2 , V_271 ) = V_277 ;
return V_95 ;
}
static int F_194 ( struct V_1 * V_2 )
{
V_37 V_127 ;
V_127 = V_234 | V_235 | V_236 | V_237 |
V_238 ;
V_127 &= * F_3 ( V_2 , V_251 ) >> 8 ;
V_2 -> V_194 &= ~ 0xffUL ;
V_2 -> V_194 |= V_127 | V_260 ;
return V_95 ;
}
static int F_195 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_251 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_251 ) |= ( V_2 -> V_194 & 0xff ) << 8 ;
return V_95 ;
}
static int F_196 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_98 ) {
#ifdef F_43
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_95 ;
}
static int F_197 ( struct V_1 * V_2 )
{
return V_95 ;
}
static int F_198 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_34 = ( V_171 ) V_2 -> V_22 . V_34 ;
return V_95 ;
}
static int F_199 ( struct V_1 * V_2 )
{
V_37 V_274 = 1 , V_275 , V_276 = 0 , V_277 ;
V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 , & V_277 , false ) ;
if ( ! ( V_277 & F_163 ( V_413 ) ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_6 -> V_135 ( V_2 , 0 ) & ( V_136 | V_137 ) )
return F_30 ( V_2 ) ;
if ( V_2 -> V_41 >= V_42 )
return V_224 ;
return V_95 ;
}
static T_6 F_200 ( int V_414 )
{
return F_145 ( struct V_415 , V_416 [ 0 ] ) + V_414 * 16 ;
}
static inline T_6 F_201 ( struct V_1 * V_2 )
{
bool V_417 ;
if ( V_2 -> V_41 == V_42 )
return F_200 ( 16 ) ;
V_417 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) & V_418 ;
return F_200 ( V_417 ? 8 : 0 ) ;
}
static int F_202 ( struct V_1 * V_2 )
{
struct V_415 V_419 ;
int V_96 ;
V_96 = F_199 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
V_96 = F_203 ( L_2 , , [ V_420 ] L_3 ( V_419 ) ) ;
V_2 -> V_6 -> V_134 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
return F_46 ( V_2 , V_2 -> V_175 . V_82 . V_174 , & V_419 ,
F_201 ( V_2 ) ) ;
}
static int F_204 ( struct V_1 * V_2 )
{
struct V_415 V_419 ;
int V_96 ;
T_6 V_74 ;
V_96 = F_199 ( V_2 ) ;
if ( V_96 != V_95 )
return V_96 ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
V_74 = F_201 ( V_2 ) ;
if ( V_74 < F_200 ( 16 ) ) {
V_96 = F_203 ( L_2 , , [ V_420 ] L_3 ( V_419 ) ) ;
if ( V_96 != V_95 )
goto V_421;
}
V_96 = F_45 ( V_2 , V_2 -> V_175 . V_82 . V_174 , & V_419 , V_74 ) ;
if ( V_96 != V_95 )
goto V_421;
if ( V_419 . V_422 >> 16 ) {
V_96 = F_25 ( V_2 , 0 ) ;
goto V_421;
}
if ( V_96 == V_95 )
V_96 = F_203 ( L_4 , : [ V_420 ] L_5 ( V_419 ) ) ;
V_421:
V_2 -> V_6 -> V_134 ( V_2 ) ;
return V_96 ;
}
static bool F_205 ( int V_3 )
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
static int F_206 ( struct V_1 * V_2 )
{
if ( ! F_205 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_95 ;
}
static int F_207 ( struct V_1 * V_2 )
{
T_2 V_423 = V_2 -> V_22 . V_23 ;
int V_424 = V_2 -> V_19 ;
T_2 V_103 = 0 ;
static T_2 V_425 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_426 ,
0 , 0 , 0 ,
V_427 ,
} ;
if ( ! F_205 ( V_424 ) )
return F_27 ( V_2 ) ;
if ( V_423 & V_425 [ V_424 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_424 ) {
case 0 : {
T_2 V_284 ;
if ( ( ( V_423 & V_301 ) && ! ( V_423 & V_300 ) ) ||
( ( V_423 & V_428 ) && ! ( V_423 & V_429 ) ) )
return F_25 ( V_2 , 0 ) ;
V_284 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( ( V_423 & V_301 ) && ( V_103 & V_430 ) &&
! ( V_284 & V_302 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
T_2 V_431 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( V_103 & V_106 ) {
T_2 V_432 ;
V_37 V_274 , V_275 , V_276 , V_277 ;
V_274 = 0x80000008 ;
V_276 = 0 ;
if ( V_2 -> V_6 -> V_278 ( V_2 , & V_274 , & V_275 , & V_276 ,
& V_277 , false ) )
V_432 = V_274 & 0xff ;
else
V_432 = 36 ;
V_431 = F_208 ( V_432 , 62 ) ;
}
if ( V_423 & V_431 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( ( V_103 & V_106 ) && ! ( V_423 & V_302 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_95 ;
}
static int F_209 ( struct V_1 * V_2 )
{
unsigned long V_374 ;
V_2 -> V_6 -> V_380 ( V_2 , 7 , & V_374 ) ;
return V_374 & ( 1 << 13 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
int V_433 = V_2 -> V_19 ;
T_2 V_284 ;
if ( V_433 > 7 )
return F_27 ( V_2 ) ;
V_284 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) ;
if ( ( V_284 & V_434 ) && ( V_433 == 4 || V_433 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_209 ( V_2 ) ) {
T_1 V_435 ;
V_2 -> V_6 -> V_380 ( V_2 , 6 , & V_435 ) ;
V_435 &= ~ 15 ;
V_435 |= V_436 | V_437 ;
V_2 -> V_6 -> V_288 ( V_2 , 6 , V_435 ) ;
return F_24 ( V_2 ) ;
}
return V_95 ;
}
static int F_211 ( struct V_1 * V_2 )
{
T_2 V_423 = V_2 -> V_22 . V_23 ;
int V_433 = V_2 -> V_19 ;
if ( ( V_433 == 6 || V_433 == 7 ) && ( V_423 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_210 ( V_2 ) ;
}
static int F_212 ( struct V_1 * V_2 )
{
T_2 V_103 = 0 ;
V_2 -> V_6 -> V_104 ( V_2 , V_105 , & V_103 ) ;
if ( ! ( V_103 & V_438 ) )
return F_27 ( V_2 ) ;
return V_95 ;
}
static int F_213 ( struct V_1 * V_2 )
{
T_2 V_439 = F_1 ( V_2 , V_251 ) ;
if ( V_439 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_212 ( V_2 ) ;
}
static int F_214 ( struct V_1 * V_2 )
{
T_2 V_284 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) ;
if ( V_284 & V_440 && V_2 -> V_6 -> V_205 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_95 ;
}
static int F_215 ( struct V_1 * V_2 )
{
T_2 V_284 = V_2 -> V_6 -> V_135 ( V_2 , 4 ) ;
T_2 V_329 = F_1 ( V_2 , V_193 ) ;
if ( ( ! ( V_284 & V_441 ) && V_2 -> V_6 -> V_205 ( V_2 ) ) ||
V_2 -> V_6 -> V_442 ( V_2 , V_329 ) )
return F_25 ( V_2 , 0 ) ;
return V_95 ;
}
static int F_216 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_217 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_137 ( V_2 , V_2 -> V_22 . V_34 , V_2 -> V_25 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_95 ;
}
static int F_218 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_217 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_137 ( V_2 , V_2 -> V_25 . V_34 , V_2 -> V_22 . V_27 ) )
return F_25 ( V_2 , 0 ) ;
return V_95 ;
}
static unsigned F_219 ( struct V_1 * V_2 )
{
unsigned V_74 ;
V_74 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
if ( V_74 == 8 )
V_74 = 4 ;
return V_74 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_131 * V_132 ,
unsigned V_74 , bool V_443 )
{
int V_96 = V_95 ;
V_132 -> type = V_391 ;
V_132 -> V_27 = V_74 ;
V_132 -> V_82 . V_174 . V_92 = V_2 -> V_99 ;
switch ( V_132 -> V_27 ) {
case 1 :
V_132 -> V_34 = F_70 ( V_170 , V_2 ) ;
break;
case 2 :
V_132 -> V_34 = F_70 ( V_178 , V_2 ) ;
break;
case 4 :
V_132 -> V_34 = F_70 ( V_171 , V_2 ) ;
break;
case 8 :
V_132 -> V_34 = F_70 ( V_179 , V_2 ) ;
break;
}
if ( ! V_443 ) {
switch ( V_132 -> V_27 ) {
case 1 :
V_132 -> V_34 &= 0xff ;
break;
case 2 :
V_132 -> V_34 &= 0xffff ;
break;
case 4 :
V_132 -> V_34 &= 0xffffffff ;
break;
}
}
V_176:
return V_96 ;
}
static int F_221 ( struct V_1 * V_2 , struct V_131 * V_132 ,
unsigned V_45 )
{
int V_96 = V_95 ;
switch ( V_45 ) {
case V_444 :
F_67 ( V_2 , V_132 ) ;
break;
case V_445 :
V_96 = F_220 ( V_2 , V_132 , 1 , false ) ;
break;
case V_446 :
V_2 -> V_175 . V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_447:
* V_132 = V_2 -> V_175 ;
V_2 -> V_448 = V_132 ;
if ( V_2 -> V_45 & V_449 )
F_72 ( V_2 ) ;
V_132 -> V_151 = V_132 -> V_34 ;
break;
case V_450 :
V_2 -> V_175 . V_27 = ( V_2 -> V_98 == 8 ) ? 16 : 8 ;
goto V_447;
case V_451 :
V_132 -> type = V_149 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_9 = F_3 ( V_2 , V_251 ) ;
F_58 ( V_132 ) ;
V_132 -> V_151 = V_132 -> V_34 ;
break;
case V_452 :
V_132 -> type = V_149 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 2 : V_2 -> V_98 ;
V_132 -> V_82 . V_9 = F_3 ( V_2 , V_251 ) ;
F_58 ( V_132 ) ;
V_132 -> V_151 = V_132 -> V_34 ;
break;
case V_453 :
if ( V_2 -> V_45 & V_150 ) {
V_132 -> type = V_123 ;
break;
}
V_132 -> type = V_149 ;
V_132 -> V_27 = V_2 -> V_98 ;
V_132 -> V_82 . V_9 = F_3 ( V_2 , V_271 ) ;
F_58 ( V_132 ) ;
V_132 -> V_151 = V_132 -> V_34 ;
break;
case V_454 :
V_132 -> type = V_162 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_174 . V_92 =
F_15 ( V_2 , V_169 ) ;
V_132 -> V_82 . V_174 . V_52 = V_348 ;
V_132 -> V_34 = 0 ;
V_132 -> V_192 = 1 ;
break;
case V_455 :
V_132 -> type = V_149 ;
V_132 -> V_27 = 2 ;
V_132 -> V_82 . V_9 = F_3 ( V_2 , V_271 ) ;
F_58 ( V_132 ) ;
break;
case V_456 :
V_132 -> type = V_391 ;
V_132 -> V_27 = 1 ;
V_132 -> V_34 = F_1 ( V_2 , V_193 ) & 0xff ;
break;
case V_457 :
V_96 = F_220 ( V_2 , V_132 , 1 , true ) ;
break;
case V_458 :
V_132 -> type = V_391 ;
V_132 -> V_27 = 1 ;
V_132 -> V_34 = 1 ;
break;
case V_459 :
V_96 = F_220 ( V_2 , V_132 , F_219 ( V_2 ) , true ) ;
break;
case V_460 :
V_96 = F_220 ( V_2 , V_132 , V_2 -> V_98 , true ) ;
break;
case V_461 :
V_2 -> V_175 . V_27 = 1 ;
if ( V_2 -> V_175 . type == V_149 ) {
V_2 -> V_175 . V_82 . V_9 = F_51 ( V_2 ,
V_2 -> V_20 , true ) ;
F_58 ( & V_2 -> V_175 ) ;
}
goto V_447;
case V_462 :
V_2 -> V_175 . V_27 = 2 ;
goto V_447;
case V_463 :
V_2 -> V_175 . V_27 = 4 ;
goto V_447;
case V_464 :
V_96 = F_220 ( V_2 , V_132 , 2 , false ) ;
break;
case V_465 :
V_96 = F_220 ( V_2 , V_132 , F_219 ( V_2 ) , false ) ;
break;
case V_466 :
V_132 -> type = V_162 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_174 . V_92 =
F_15 ( V_2 , V_167 ) ;
V_132 -> V_82 . V_174 . V_52 = V_2 -> V_467 ;
V_132 -> V_34 = 0 ;
V_132 -> V_192 = 1 ;
break;
case V_468 :
V_132 -> type = V_162 ;
V_132 -> V_27 = ( V_2 -> V_45 & V_150 ) ? 1 : V_2 -> V_98 ;
V_132 -> V_82 . V_174 . V_92 =
F_14 ( V_2 ,
F_1 ( V_2 , V_164 ) +
( F_1 ( V_2 , V_251 ) & 0xff ) ) ;
V_132 -> V_82 . V_174 . V_52 = V_2 -> V_467 ;
V_132 -> V_34 = 0 ;
break;
case V_469 :
V_132 -> type = V_391 ;
V_132 -> V_82 . V_174 . V_92 = V_2 -> V_99 ;
V_132 -> V_27 = V_2 -> V_98 + 2 ;
F_222 ( V_132 -> V_267 , V_132 -> V_27 , V_2 ) ;
break;
case V_470 :
V_2 -> V_175 . V_27 = V_2 -> V_98 + 2 ;
goto V_447;
case V_471 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_348 ;
break;
case V_472 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_97 ;
break;
case V_473 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_44 ;
break;
case V_474 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_160 ;
break;
case V_475 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_53 ;
break;
case V_476 :
V_132 -> type = V_391 ;
V_132 -> V_34 = V_218 ;
break;
case V_477 :
default:
V_132 -> type = V_123 ;
break;
}
V_176:
return V_96 ;
}
int F_223 ( struct V_1 * V_2 , void * V_478 , int V_479 )
{
int V_96 = V_95 ;
int V_41 = V_2 -> V_41 ;
int V_480 , V_481 , V_482 , V_483 ;
bool V_484 = false ;
bool V_485 = false ;
struct V_486 V_486 ;
V_2 -> V_175 . type = V_123 ;
V_2 -> V_448 = NULL ;
V_2 -> V_99 = V_2 -> V_31 ;
V_2 -> V_85 . V_117 = V_2 -> V_85 . V_109 ;
V_2 -> V_85 . V_114 = V_2 -> V_85 . V_109 + V_479 ;
V_2 -> V_487 = 1 ;
if ( V_479 > 0 )
memcpy ( V_2 -> V_85 . V_109 , V_478 , V_479 ) ;
else {
V_96 = F_47 ( V_2 , 1 ) ;
if ( V_96 != V_95 )
return V_96 ;
}
switch ( V_41 ) {
case V_94 :
case V_219 :
case V_101 :
V_480 = V_481 = 2 ;
break;
case V_107 :
V_480 = V_481 = 4 ;
break;
#ifdef F_43
case V_42 :
V_480 = 4 ;
V_481 = 8 ;
break;
#endif
default:
return V_383 ;
}
V_2 -> V_98 = V_480 ;
V_2 -> V_29 = V_481 ;
for (; ; ) {
switch ( V_2 -> V_141 = F_70 ( V_35 , V_2 ) ) {
case 0x66 :
V_484 = true ;
V_2 -> V_98 = V_480 ^ 6 ;
break;
case 0x67 :
if ( V_41 == V_42 )
V_2 -> V_29 = V_481 ^ 12 ;
else
V_2 -> V_29 = V_481 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_485 = true ;
V_2 -> V_467 = ( V_2 -> V_141 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_485 = true ;
V_2 -> V_467 = V_2 -> V_141 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_41 != V_42 )
goto V_488;
V_2 -> V_121 = V_2 -> V_141 ;
continue;
case 0xf0 :
V_2 -> V_227 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_141 ;
break;
default:
goto V_488;
}
V_2 -> V_121 = 0 ;
}
V_488:
if ( V_2 -> V_121 & 8 )
V_2 -> V_98 = 8 ;
V_486 = V_489 [ V_2 -> V_141 ] ;
if ( V_2 -> V_141 == 0x0f ) {
V_2 -> V_487 = 2 ;
V_2 -> V_141 = F_70 ( V_35 , V_2 ) ;
V_486 = V_490 [ V_2 -> V_141 ] ;
if ( V_2 -> V_141 == 0x38 ) {
V_2 -> V_487 = 3 ;
V_2 -> V_141 = F_70 ( V_35 , V_2 ) ;
V_486 = V_491 [ V_2 -> V_141 ] ;
}
}
V_2 -> V_45 = V_486 . V_127 ;
if ( V_2 -> V_45 & V_140 )
V_2 -> V_159 = F_70 ( V_35 , V_2 ) ;
if ( V_2 -> V_487 == 1 && ( V_2 -> V_141 == 0xc5 || V_2 -> V_141 == 0xc4 ) &&
( V_41 == V_42 || ( V_2 -> V_159 & 0xc0 ) == 0xc0 ) ) {
V_2 -> V_45 = V_492 ;
}
while ( V_2 -> V_45 & V_493 ) {
switch ( V_2 -> V_45 & V_493 ) {
case V_494 :
V_482 = ( V_2 -> V_159 >> 3 ) & 7 ;
V_486 = V_486 . V_495 . V_496 [ V_482 ] ;
break;
case V_497 :
V_482 = ( V_2 -> V_159 >> 3 ) & 7 ;
if ( ( V_2 -> V_159 >> 6 ) == 3 )
V_486 = V_486 . V_495 . V_498 -> V_499 [ V_482 ] ;
else
V_486 = V_486 . V_495 . V_498 -> V_500 [ V_482 ] ;
break;
case V_501 :
V_482 = V_2 -> V_159 & 7 ;
V_486 = V_486 . V_495 . V_496 [ V_482 ] ;
break;
case V_502 :
if ( V_2 -> V_17 && V_484 )
return V_383 ;
V_483 = V_484 ? 0x66 : V_2 -> V_17 ;
switch ( V_483 ) {
case 0x00 : V_486 = V_486 . V_495 . V_503 -> V_504 ; break;
case 0x66 : V_486 = V_486 . V_495 . V_503 -> V_505 ; break;
case 0xf2 : V_486 = V_486 . V_495 . V_503 -> V_506 ; break;
case 0xf3 : V_486 = V_486 . V_495 . V_503 -> V_507 ; break;
}
break;
case V_508 :
if ( V_2 -> V_159 > 0xbf )
V_486 = V_486 . V_495 . V_509 -> V_510 [ V_2 -> V_159 - 0xc0 ] ;
else
V_486 = V_486 . V_495 . V_509 -> V_132 [ ( V_2 -> V_159 >> 3 ) & 7 ] ;
break;
case V_511 :
if ( ( V_2 -> V_159 >> 6 ) == 3 )
V_486 = V_486 . V_495 . V_512 -> V_499 ;
else
V_486 = V_486 . V_495 . V_512 -> V_500 ;
break;
case V_513 :
if ( V_2 -> V_41 == V_42 )
V_486 = V_486 . V_495 . V_514 -> V_515 ;
else
V_486 = V_486 . V_495 . V_514 -> V_516 ;
break;
default:
return V_383 ;
}
V_2 -> V_45 &= ~ ( T_2 ) V_493 ;
V_2 -> V_45 |= V_486 . V_127 ;
}
if ( V_2 -> V_45 == 0 )
return V_383 ;
V_2 -> V_517 = V_486 . V_495 . V_517 ;
if ( F_48 ( V_2 -> V_518 ) && F_34 ( ! ( V_2 -> V_45 & V_519 ) ) )
return V_383 ;
if ( F_48 ( V_2 -> V_45 &
( V_492 | V_520 | V_521 | V_142 | V_146 | V_522 | V_523 | V_524 |
V_525 ) ) ) {
V_2 -> V_526 = V_486 . V_526 ;
V_2 -> V_12 = V_486 . V_12 ;
if ( V_2 -> V_45 & V_492 )
return V_383 ;
if ( V_41 == V_42 ) {
if ( V_2 -> V_98 == 4 && ( V_2 -> V_45 & V_520 ) )
V_2 -> V_98 = 8 ;
else if ( V_2 -> V_45 & V_524 )
V_2 -> V_98 = 8 ;
}
if ( V_2 -> V_45 & V_521 ) {
if ( V_41 == V_42 )
V_2 -> V_98 = 8 ;
else
V_2 -> V_98 = 4 ;
}
if ( ( V_2 -> V_45 & V_525 ) && V_2 -> V_98 == 2 )
V_2 -> V_98 = 4 ;
if ( V_2 -> V_45 & V_142 )
V_2 -> V_98 = 16 ;
else if ( V_2 -> V_45 & V_146 )
V_2 -> V_98 = 8 ;
}
if ( V_2 -> V_45 & V_140 ) {
V_96 = F_69 ( V_2 , & V_2 -> V_175 ) ;
if ( ! V_485 ) {
V_485 = true ;
V_2 -> V_467 = V_2 -> V_154 ;
}
} else if ( V_2 -> V_45 & V_527 )
V_96 = F_71 ( V_2 , & V_2 -> V_175 ) ;
if ( V_96 != V_95 )
goto V_176;
if ( ! V_485 )
V_2 -> V_467 = V_160 ;
V_2 -> V_175 . V_82 . V_174 . V_52 = V_2 -> V_467 ;
V_96 = F_221 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_45 >> V_528 ) & V_529 ) ;
if ( V_96 != V_95 )
goto V_176;
V_96 = F_221 ( V_2 , & V_2 -> V_246 , ( V_2 -> V_45 >> V_530 ) & V_529 ) ;
if ( V_96 != V_95 )
goto V_176;
V_96 = F_221 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_45 >> V_531 ) & V_529 ) ;
if ( V_2 -> V_173 && F_34 ( V_2 -> V_448 ) )
V_2 -> V_448 -> V_82 . V_174 . V_92 = F_14 ( V_2 ,
V_2 -> V_448 -> V_82 . V_174 . V_92 + V_2 -> V_99 ) ;
V_176:
return ( V_96 != V_95 ) ? V_383 : V_384 ;
}
bool F_224 ( struct V_1 * V_2 )
{
return V_2 -> V_45 & V_532 ;
}
static bool F_225 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_141 == 0xa6 ) || ( V_2 -> V_141 == 0xa7 ) ||
( V_2 -> V_141 == 0xae ) || ( V_2 -> V_141 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_533 ) &&
( ( V_2 -> V_194 & V_237 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_534 ) &&
( ( V_2 -> V_194 & V_237 ) == V_237 ) ) ) )
return true ;
return false ;
}
static int F_226 ( struct V_1 * V_2 )
{
int V_96 ;
V_2 -> V_6 -> V_133 ( V_2 ) ;
V_96 = F_203 ( L_6 ) ;
V_2 -> V_6 -> V_134 ( V_2 ) ;
if ( F_48 ( V_96 != V_95 ) )
return F_22 ( V_2 , V_535 , 0 , false ) ;
return V_95 ;
}
static void F_227 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
if ( V_132 -> type == V_147 )
F_62 ( V_2 , & V_132 -> V_228 , V_132 -> V_82 . V_148 ) ;
}
static int F_54 ( struct V_1 * V_2 , void (* F_57)( struct F_54 * ) )
{
T_1 V_127 = ( V_2 -> V_194 & V_129 ) | V_130 ;
if ( ! ( V_2 -> V_45 & V_150 ) )
F_57 += F_228 ( V_2 -> V_25 . V_27 ) * V_536 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop), ASM_CALL_CONSTRAINT
: "c"(ctxt->src2.val));
V_2 -> V_194 = ( V_2 -> V_194 & ~ V_129 ) | ( V_127 & V_129 ) ;
if ( ! F_57 )
return F_29 ( V_2 ) ;
return V_95 ;
}
void F_229 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_173 , 0 ,
( void * ) & V_2 -> V_159 - ( void * ) & V_2 -> V_173 ) ;
V_2 -> V_189 . V_183 = 0 ;
V_2 -> V_189 . V_114 = 0 ;
V_2 -> V_182 . V_114 = 0 ;
}
int F_230 ( struct V_1 * V_2 )
{
const struct V_201 * V_6 = V_2 -> V_6 ;
int V_96 = V_95 ;
int V_537 = V_2 -> V_25 . type ;
unsigned V_538 ;
V_2 -> V_182 . V_183 = 0 ;
if ( V_2 -> V_227 && ( ! ( V_2 -> V_45 & V_539 ) || V_2 -> V_25 . type != V_162 ) ) {
V_96 = F_27 ( V_2 ) ;
goto V_176;
}
if ( ( V_2 -> V_45 & V_540 ) == V_541 && V_2 -> V_22 . type != V_162 ) {
V_96 = F_27 ( V_2 ) ;
goto V_176;
}
V_538 = V_2 -> V_6 -> V_298 ( V_2 ) ;
if ( F_48 ( V_2 -> V_45 &
( V_542 | V_543 | V_142 | V_146 | V_522 | V_523 | V_544 | V_545 | String ) ) ) {
if ( ( V_2 -> V_41 == V_42 && ( V_2 -> V_45 & V_542 ) ) ||
( V_2 -> V_45 & V_543 ) ) {
V_96 = F_27 ( V_2 ) ;
goto V_176;
}
if ( ( ( V_2 -> V_45 & ( V_142 | V_146 ) ) && ( ( V_6 -> V_135 ( V_2 , 0 ) & V_137 ) ) )
|| ( ( V_2 -> V_45 & V_142 ) && ! ( V_6 -> V_135 ( V_2 , 4 ) & V_418 ) ) ) {
V_96 = F_27 ( V_2 ) ;
goto V_176;
}
if ( ( V_2 -> V_45 & ( V_142 | V_146 ) ) && ( V_6 -> V_135 ( V_2 , 0 ) & V_136 ) ) {
V_96 = F_30 ( V_2 ) ;
goto V_176;
}
if ( V_2 -> V_45 & V_146 ) {
V_96 = F_226 ( V_2 ) ;
if ( V_96 != V_95 )
goto V_176;
F_227 ( V_2 , & V_2 -> V_22 ) ;
F_227 ( V_2 , & V_2 -> V_246 ) ;
if ( ! ( V_2 -> V_45 & V_546 ) )
F_227 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_48 ( V_538 & V_547 ) && V_2 -> V_12 ) {
V_96 = F_7 ( V_2 , V_2 -> V_12 ,
V_548 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( ( V_2 -> V_45 & V_545 ) && V_2 -> V_41 < V_101 ) {
V_96 = F_27 ( V_2 ) ;
goto V_176;
}
if ( ( V_2 -> V_45 & V_544 ) && V_6 -> V_205 ( V_2 ) ) {
if ( V_2 -> V_45 & V_549 )
V_96 = F_27 ( V_2 ) ;
else
V_96 = F_25 ( V_2 , 0 ) ;
goto V_176;
}
if ( V_2 -> V_45 & V_523 ) {
V_96 = V_2 -> V_526 ( V_2 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( F_48 ( V_538 & V_547 ) && ( V_2 -> V_45 & V_522 ) ) {
V_96 = F_7 ( V_2 , V_2 -> V_12 ,
V_550 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
if ( F_14 ( V_2 , F_1 ( V_2 , V_193 ) ) == 0 ) {
F_138 ( V_2 ) ;
V_2 -> V_31 = V_2 -> V_99 ;
V_2 -> V_194 &= ~ V_259 ;
goto V_176;
}
}
}
if ( ( V_2 -> V_22 . type == V_162 ) && ! ( V_2 -> V_45 & V_551 ) ) {
V_96 = F_74 ( V_2 , V_2 -> V_22 . V_82 . V_174 ,
V_2 -> V_22 . V_267 , V_2 -> V_22 . V_27 ) ;
if ( V_96 != V_95 )
goto V_176;
V_2 -> V_22 . V_270 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_246 . type == V_162 ) {
V_96 = F_74 ( V_2 , V_2 -> V_246 . V_82 . V_174 ,
& V_2 -> V_246 . V_34 , V_2 -> V_246 . V_27 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( ( V_2 -> V_45 & V_552 ) == V_553 )
goto V_554;
if ( ( V_2 -> V_25 . type == V_162 ) && ! ( V_2 -> V_45 & V_546 ) ) {
V_96 = F_74 ( V_2 , V_2 -> V_25 . V_82 . V_174 ,
& V_2 -> V_25 . V_34 , V_2 -> V_25 . V_27 ) ;
if ( V_96 != V_95 ) {
if ( ! ( V_2 -> V_45 & V_555 ) &&
V_96 == V_61 &&
V_2 -> V_57 . V_58 == V_556 )
V_2 -> V_57 . V_59 |= V_557 ;
goto V_176;
}
}
V_2 -> V_25 . V_270 = V_2 -> V_25 . V_23 ;
V_554:
if ( F_48 ( V_538 & V_547 ) && ( V_2 -> V_45 & V_522 ) ) {
V_96 = F_7 ( V_2 , V_2 -> V_12 ,
V_558 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) )
V_2 -> V_194 |= V_259 ;
else
V_2 -> V_194 &= ~ V_259 ;
if ( V_2 -> V_517 ) {
if ( V_2 -> V_45 & V_559 ) {
void (* F_57)( struct F_54 * ) = ( void * ) V_2 -> V_517 ;
V_96 = F_54 ( V_2 , F_57 ) ;
if ( V_96 != V_95 )
goto V_176;
goto F_91;
}
V_96 = V_2 -> V_517 ( V_2 ) ;
if ( V_96 != V_95 )
goto V_176;
goto F_91;
}
if ( V_2 -> V_487 == 2 )
goto V_560;
else if ( V_2 -> V_487 == 3 )
goto V_561;
switch ( V_2 -> V_141 ) {
case 0x70 ... 0x7f :
if ( F_56 ( V_2 -> V_141 , V_2 -> V_194 ) )
V_96 = F_44 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_82 . V_174 . V_92 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_82 . V_9 == F_3 ( V_2 , V_251 ) )
V_2 -> V_25 . type = V_123 ;
else
V_96 = F_156 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_98 ) {
case 2 : V_2 -> V_25 . V_34 = ( V_170 ) V_2 -> V_25 . V_34 ; break;
case 4 : V_2 -> V_25 . V_34 = ( V_178 ) V_2 -> V_25 . V_34 ; break;
case 8 : V_2 -> V_25 . V_34 = ( V_171 ) V_2 -> V_25 . V_34 ; break;
}
break;
case 0xcc :
V_96 = F_107 ( V_2 , 3 ) ;
break;
case 0xcd :
V_96 = F_107 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0xce :
if ( V_2 -> V_194 & V_239 )
V_96 = F_107 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_96 = F_44 ( V_2 , V_2 -> V_22 . V_34 ) ;
V_2 -> V_25 . type = V_123 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_562 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_194 ^= V_234 ;
break;
case 0xf8 :
V_2 -> V_194 &= ~ V_234 ;
break;
case 0xf9 :
V_2 -> V_194 |= V_234 ;
break;
case 0xfc :
V_2 -> V_194 &= ~ V_195 ;
break;
case 0xfd :
V_2 -> V_194 |= V_195 ;
break;
default:
goto V_563;
}
if ( V_96 != V_95 )
goto V_176;
F_91:
if ( V_2 -> V_45 & V_564 ) {
F_231 ( V_2 -> V_22 . type == V_162 || V_2 -> V_22 . type == V_196 ) ;
V_96 = F_91 ( V_2 , & V_2 -> V_22 ) ;
if ( V_96 != V_95 )
goto V_176;
}
if ( ! ( V_2 -> V_45 & V_555 ) ) {
V_96 = F_91 ( V_2 , & V_2 -> V_25 ) ;
if ( V_96 != V_95 )
goto V_176;
}
V_2 -> V_25 . type = V_537 ;
if ( ( V_2 -> V_45 & V_540 ) == V_565 )
F_148 ( V_2 , V_167 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_45 & V_552 ) == V_566 )
F_148 ( V_2 , V_169 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) ) {
unsigned int V_192 ;
struct V_180 * V_295 = & V_2 -> V_189 ;
if ( ( V_2 -> V_45 & V_540 ) == V_565 )
V_192 = V_2 -> V_22 . V_192 ;
else
V_192 = V_2 -> V_25 . V_192 ;
F_17 ( V_2 , V_193 , - V_192 ) ;
if ( ! F_225 ( V_2 ) ) {
if ( ( V_295 -> V_114 != 0 || F_1 ( V_2 , V_193 ) & 0x3ff ) &&
( V_295 -> V_114 == 0 || V_295 -> V_114 != V_295 -> V_183 ) ) {
V_2 -> V_182 . V_114 = 0 ;
F_4 ( V_2 ) ;
return V_567 ;
}
goto V_176;
}
V_2 -> V_194 &= ~ V_259 ;
}
V_2 -> V_31 = V_2 -> V_99 ;
V_176:
if ( V_96 == V_61 ) {
F_23 ( V_2 -> V_57 . V_58 > 0x1f ) ;
V_2 -> V_568 = true ;
}
if ( V_96 == V_569 )
return V_570 ;
if ( V_96 == V_95 )
F_4 ( V_2 ) ;
return ( V_96 == V_224 ) ? V_383 : V_384 ;
V_560:
switch ( V_2 -> V_141 ) {
case 0x09 :
( V_2 -> V_6 -> V_571 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_34 = V_6 -> V_135 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_380 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_34 ) ;
break;
case 0x40 ... 0x4f :
if ( F_56 ( V_2 -> V_141 , V_2 -> V_194 ) )
V_2 -> V_25 . V_34 = V_2 -> V_22 . V_34 ;
else if ( V_2 -> V_98 != 4 )
V_2 -> V_25 . type = V_123 ;
break;
case 0x80 ... 0x8f :
if ( F_56 ( V_2 -> V_141 , V_2 -> V_194 ) )
V_96 = F_44 ( V_2 , V_2 -> V_22 . V_34 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_34 = F_56 ( V_2 -> V_141 , V_2 -> V_194 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_98 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_35 ) V_2 -> V_22 . V_34
: ( V_36 ) V_2 -> V_22 . V_34 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_98 ;
V_2 -> V_25 . V_34 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_170 ) V_2 -> V_22 . V_34 :
( V_178 ) V_2 -> V_22 . V_34 ;
break;
default:
goto V_563;
}
V_561:
if ( V_96 != V_95 )
goto V_176;
goto F_91;
V_563:
return V_383 ;
}
void F_232 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_233 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
bool F_234 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 && ( V_2 -> V_45 & String ) )
return false ;
if ( V_2 -> V_45 & V_572 )
return false ;
return true ;
}
