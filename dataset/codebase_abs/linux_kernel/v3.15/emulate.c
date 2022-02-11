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
. V_24 = V_2 -> V_22 . V_25 ,
. V_26 = V_2 -> V_27 . V_25 ,
. V_28 = V_2 -> V_28 ,
. V_29 = V_2 -> V_30 ,
} ;
return V_2 -> V_6 -> V_12 ( V_2 , & V_16 , V_14 ) ;
}
static void F_8 ( T_1 * V_31 , T_1 V_22 , T_1 V_32 )
{
* V_31 = ( * V_31 & ~ V_32 ) | ( V_22 & V_32 ) ;
}
static inline unsigned long F_9 ( struct V_1 * V_2 )
{
return ( 1UL << ( V_2 -> V_28 << 3 ) ) - 1 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_2 V_33 ;
struct V_34 V_35 ;
if ( V_2 -> V_36 == V_37 )
return ~ 0UL ;
V_2 -> V_6 -> V_38 ( V_2 , & V_33 , & V_35 , NULL , V_39 ) ;
return ~ 0U >> ( ( V_35 . V_40 ^ 1 ) * 16 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return ( F_12 ( F_10 ( V_2 ) ) + 1 ) >> 3 ;
}
static inline unsigned long
F_13 ( struct V_1 * V_2 , unsigned long V_9 )
{
if ( V_2 -> V_28 == sizeof( unsigned long ) )
return V_9 ;
else
return V_9 & F_9 ( V_2 ) ;
}
static inline unsigned long
F_14 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_13 ( V_2 , V_9 ) ;
}
static void F_15 ( T_1 * V_9 , T_1 V_32 , int V_41 )
{
F_8 ( V_9 , * V_9 + V_41 , V_32 ) ;
}
static inline void
F_16 ( struct V_1 * V_2 , unsigned long * V_9 , int V_41 )
{
T_1 V_32 ;
if ( V_2 -> V_28 == sizeof( unsigned long ) )
V_32 = ~ 0UL ;
else
V_32 = F_9 ( V_2 ) ;
F_15 ( V_9 , V_32 , V_41 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_41 )
{
F_15 ( F_3 ( V_2 , V_42 ) , F_10 ( V_2 ) , V_41 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , int V_43 )
{
F_16 ( V_2 , & V_2 -> V_44 , V_43 ) ;
}
static T_3 F_19 ( struct V_34 * V_45 )
{
T_3 V_46 = F_20 ( V_45 ) ;
return V_45 -> V_47 ? ( V_46 << 12 ) | 0xfff : V_46 ;
}
static void F_21 ( struct V_1 * V_2 , int V_48 )
{
V_2 -> V_49 = true ;
V_2 -> V_50 = V_48 ;
}
static unsigned long F_22 ( struct V_1 * V_2 , int V_48 )
{
if ( V_2 -> V_36 == V_37 && V_48 < V_51 )
return 0 ;
return V_2 -> V_6 -> V_52 ( V_2 , V_48 ) ;
}
static unsigned V_50 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_49 )
return 0 ;
return V_2 -> V_50 ;
}
static int F_23 ( struct V_1 * V_2 , int V_53 ,
T_3 error , bool V_54 )
{
V_2 -> V_55 . V_56 = V_53 ;
V_2 -> V_55 . V_57 = error ;
V_2 -> V_55 . V_58 = V_54 ;
return V_59 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_60 , 0 , false ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_61 )
{
return F_23 ( V_2 , V_62 , V_61 , true ) ;
}
static int F_26 ( struct V_1 * V_2 , int V_61 )
{
return F_23 ( V_2 , V_63 , V_61 , true ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_64 , 0 , false ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_61 )
{
return F_23 ( V_2 , V_65 , V_61 , true ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_66 , 0 , false ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_23 ( V_2 , V_67 , 0 , false ) ;
}
static T_2 F_31 ( struct V_1 * V_2 , unsigned V_48 )
{
T_2 V_68 ;
struct V_34 V_45 ;
V_2 -> V_6 -> V_38 ( V_2 , & V_68 , & V_45 , NULL , V_48 ) ;
return V_68 ;
}
static void F_32 ( struct V_1 * V_2 , T_2 V_68 ,
unsigned V_48 )
{
T_2 V_69 ;
T_3 V_70 ;
struct V_34 V_45 ;
V_2 -> V_6 -> V_38 ( V_2 , & V_69 , & V_45 , & V_70 , V_48 ) ;
V_2 -> V_6 -> V_71 ( V_2 , V_68 , & V_45 , V_70 , V_48 ) ;
}
static bool F_33 ( struct V_1 * V_2 , unsigned V_72 )
{
if ( F_34 ( V_72 < 16 ) )
return false ;
if ( V_2 -> V_40 & V_73 )
return true ;
else if ( V_2 -> V_40 & V_74 )
return false ;
else if ( V_2 -> V_40 & V_75 )
return false ;
else
return true ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
unsigned V_72 , bool V_78 , bool V_79 ,
T_1 * V_80 )
{
struct V_34 V_45 ;
bool V_81 ;
T_1 V_82 ;
T_3 V_83 ;
T_2 V_33 ;
unsigned V_84 ;
V_82 = F_22 ( V_2 , V_77 . V_48 ) + V_77 . V_85 ;
switch ( V_2 -> V_36 ) {
case V_37 :
if ( ( ( signed long ) V_82 << 16 ) >> 16 != V_82 )
return F_25 ( V_2 , 0 ) ;
break;
default:
V_81 = V_2 -> V_6 -> V_38 ( V_2 , & V_33 , & V_45 , NULL ,
V_77 . V_48 ) ;
if ( ! V_81 )
goto V_86;
if ( ( ( ( V_2 -> V_36 != V_87 ) && ( V_45 . type & 8 ) )
|| ! ( V_45 . type & 2 ) ) && V_78 )
goto V_86;
if ( ! V_79 && ( V_45 . type & 8 ) && ! ( V_45 . type & 2 ) )
goto V_86;
V_83 = F_19 ( & V_45 ) ;
if ( ( V_45 . type & 8 ) || ! ( V_45 . type & 4 ) ) {
if ( V_77 . V_85 > V_83 || ( T_3 ) ( V_77 . V_85 + V_72 - 1 ) > V_83 )
goto V_86;
} else {
if ( V_77 . V_85 <= V_83 || ( T_3 ) ( V_77 . V_85 + V_72 - 1 ) <= V_83 )
goto V_86;
V_83 = V_45 . V_40 ? 0xffffffff : 0xffff ;
if ( V_77 . V_85 > V_83 || ( T_3 ) ( V_77 . V_85 + V_72 - 1 ) > V_83 )
goto V_86;
}
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( ! ( V_45 . type & 8 ) ) {
if ( V_84 > V_45 . V_88 )
goto V_86;
} else if ( ( V_45 . type & 8 ) && ! ( V_45 . type & 4 ) ) {
if ( V_84 != V_45 . V_88 )
goto V_86;
} else if ( ( V_45 . type & 8 ) && ( V_45 . type & 4 ) ) {
if ( V_84 < V_45 . V_88 )
goto V_86;
}
break;
}
if ( V_79 ? V_2 -> V_36 != V_37 : V_2 -> V_28 != 8 )
V_82 &= ( T_3 ) - 1 ;
if ( F_33 ( V_2 , V_72 ) && ( ( V_82 & ( V_72 - 1 ) ) != 0 ) )
return F_25 ( V_2 , 0 ) ;
* V_80 = V_82 ;
return V_89 ;
V_86:
if ( V_77 . V_48 == V_39 )
return F_26 ( V_2 , V_33 ) ;
else
return F_25 ( V_2 , V_33 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
unsigned V_72 , bool V_78 ,
T_1 * V_80 )
{
return F_35 ( V_2 , V_77 , V_72 , V_78 , false , V_80 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
void * V_90 ,
unsigned V_72 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_77 , V_72 , false , & V_80 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_80 , V_90 , V_72 , & V_2 -> V_55 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_4 * V_31 )
{
struct V_93 * V_94 = & V_2 -> V_79 ;
int V_91 ;
int V_72 , V_95 ;
if ( V_2 -> V_44 == V_94 -> V_96 ) {
unsigned long V_80 ;
struct V_76 V_77 = { . V_48 = V_97 ,
. V_85 = V_2 -> V_44 } ;
V_95 = V_94 -> V_96 - V_94 -> V_98 ;
V_72 = F_39 ( 15UL - V_95 ,
V_99 - F_40 ( V_2 -> V_44 ) ) ;
V_91 = F_35 ( V_2 , V_77 , V_72 , false , true , & V_80 ) ;
if ( F_41 ( V_91 != V_89 ) )
return V_91 ;
V_91 = V_2 -> V_6 -> V_79 ( V_2 , V_80 , V_94 -> V_90 + V_95 ,
V_72 , & V_2 -> V_55 ) ;
if ( F_41 ( V_91 != V_89 ) )
return V_91 ;
V_94 -> V_96 += V_72 ;
}
* V_31 = V_94 -> V_90 [ V_2 -> V_44 - V_94 -> V_98 ] ;
V_2 -> V_44 ++ ;
return V_89 ;
}
static int F_42 ( struct V_1 * V_2 ,
void * V_31 , unsigned V_72 )
{
int V_91 ;
if ( F_41 ( V_2 -> V_44 + V_72 - V_2 -> V_30 > 15 ) )
return V_100 ;
while ( V_72 -- ) {
V_91 = F_38 ( V_2 , V_31 ++ ) ;
if ( V_91 != V_89 )
return V_91 ;
}
return V_89 ;
}
static void * F_43 ( struct V_1 * V_2 , T_4 V_19 ,
int V_101 )
{
void * V_102 ;
int V_103 = ( V_2 -> V_104 == 0 ) && V_101 ;
if ( V_103 && V_19 >= 4 && V_19 < 8 )
V_102 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_102 = F_3 ( V_2 , V_19 ) ;
return V_102 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
T_2 * V_72 , unsigned long * V_105 , int V_106 )
{
int V_91 ;
if ( V_106 == 2 )
V_106 = 3 ;
* V_105 = 0 ;
V_91 = F_37 ( V_2 , V_77 , V_72 , 2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_77 . V_85 += 2 ;
V_91 = F_37 ( V_2 , V_77 , V_105 , V_106 ) ;
return V_91 ;
}
static T_4 F_45 ( unsigned int V_107 , unsigned long V_108 )
{
T_4 V_91 ;
void (* F_46)( void ) = ( void * ) V_109 + 4 * ( V_107 & 0xf ) ;
V_108 = ( V_108 & V_110 ) | V_111 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_91 ;
}
static void F_47 ( struct V_112 * V_113 )
{
switch ( V_113 -> V_25 ) {
case 1 :
V_113 -> V_114 = * ( T_4 * ) V_113 -> V_77 . V_9 ;
break;
case 2 :
V_113 -> V_114 = * ( T_2 * ) V_113 -> V_77 . V_9 ;
break;
case 4 :
V_113 -> V_114 = * ( T_3 * ) V_113 -> V_77 . V_9 ;
break;
case 8 :
V_113 -> V_114 = * ( V_115 * ) V_113 -> V_77 . V_9 ;
break;
}
}
static void F_48 ( struct V_1 * V_2 , T_5 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_116 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_49
case 8 : asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_50 () ;
}
V_2 -> V_6 -> V_117 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_5 * V_90 ,
int V_9 )
{
V_2 -> V_6 -> V_116 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_49
case 8 : asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_50 () ;
}
V_2 -> V_6 -> V_117 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , V_115 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_116 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_50 () ;
}
V_2 -> V_6 -> V_117 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , V_115 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_116 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_50 () ;
}
V_2 -> V_6 -> V_117 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_118 ( V_2 , 0 ) & ( V_119 | V_120 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_116 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_117 ( V_2 ) ;
return V_89 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_2 V_121 ;
if ( V_2 -> V_6 -> V_118 ( V_2 , 0 ) & ( V_119 | V_120 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_116 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_117 ( V_2 ) ;
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_114 = V_121 ;
return V_89 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_2 V_122 ;
if ( V_2 -> V_6 -> V_118 ( V_2 , 0 ) & ( V_119 | V_120 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_116 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_117 ( V_2 ) ;
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_114 = V_122 ;
return V_89 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_40 & V_123 ) )
V_9 = ( V_2 -> V_124 & 7 ) | ( ( V_2 -> V_104 & 1 ) << 3 ) ;
if ( V_2 -> V_40 & V_125 ) {
V_113 -> type = V_126 ;
V_113 -> V_25 = 16 ;
V_113 -> V_77 . V_127 = V_9 ;
F_48 ( V_2 , & V_113 -> V_128 , V_9 ) ;
return;
}
if ( V_2 -> V_40 & V_129 ) {
V_9 &= 7 ;
V_113 -> type = V_130 ;
V_113 -> V_25 = 8 ;
V_113 -> V_77 . V_131 = V_9 ;
return;
}
V_113 -> type = V_132 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_9 = F_43 ( V_2 , V_9 , V_2 -> V_40 & V_133 ) ;
F_47 ( V_113 ) ;
V_113 -> V_134 = V_113 -> V_114 ;
}
static void F_58 ( struct V_1 * V_2 , int V_135 )
{
if ( V_135 == V_42 || V_135 == V_136 )
V_2 -> V_137 = V_39 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
T_4 V_138 ;
int V_139 = 0 , V_135 = 0 , V_140 ;
int V_91 = V_89 ;
T_1 V_141 = 0 ;
if ( V_2 -> V_104 ) {
V_2 -> V_19 = ( V_2 -> V_104 & 4 ) << 1 ;
V_139 = ( V_2 -> V_104 & 2 ) << 2 ;
V_2 -> V_20 = V_135 = ( V_2 -> V_104 & 1 ) << 3 ;
}
V_2 -> V_18 |= ( V_2 -> V_142 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_142 & 0x38 ) >> 3 ;
V_2 -> V_20 |= ( V_2 -> V_142 & 0x07 ) ;
V_2 -> V_137 = V_143 ;
if ( V_2 -> V_18 == 3 ) {
V_113 -> type = V_132 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_9 = F_43 ( V_2 , V_2 -> V_20 ,
V_2 -> V_40 & V_133 ) ;
if ( V_2 -> V_40 & V_125 ) {
V_113 -> type = V_126 ;
V_113 -> V_25 = 16 ;
V_113 -> V_77 . V_127 = V_2 -> V_20 ;
F_48 ( V_2 , & V_113 -> V_128 , V_2 -> V_20 ) ;
return V_91 ;
}
if ( V_2 -> V_40 & V_129 ) {
V_113 -> type = V_130 ;
V_113 -> V_25 = 8 ;
V_113 -> V_77 . V_127 = V_2 -> V_20 & 7 ;
return V_91 ;
}
F_47 ( V_113 ) ;
return V_91 ;
}
V_113 -> type = V_144 ;
if ( V_2 -> V_28 == 2 ) {
unsigned V_145 = F_1 ( V_2 , V_146 ) ;
unsigned V_147 = F_1 ( V_2 , V_136 ) ;
unsigned V_148 = F_1 ( V_2 , V_149 ) ;
unsigned V_150 = F_1 ( V_2 , V_151 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_141 += F_60 ( T_2 , V_2 ) ;
break;
case 1 :
V_141 += F_60 ( V_152 , V_2 ) ;
break;
case 2 :
V_141 += F_60 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_141 += V_145 + V_148 ;
break;
case 1 :
V_141 += V_145 + V_150 ;
break;
case 2 :
V_141 += V_147 + V_148 ;
break;
case 3 :
V_141 += V_147 + V_150 ;
break;
case 4 :
V_141 += V_148 ;
break;
case 5 :
V_141 += V_150 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_141 += V_147 ;
break;
case 7 :
V_141 += V_145 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_137 = V_39 ;
V_141 = ( T_2 ) V_141 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_138 = F_60 ( T_4 , V_2 ) ;
V_139 |= ( V_138 >> 3 ) & 7 ;
V_135 |= V_138 & 7 ;
V_140 = V_138 >> 6 ;
if ( ( V_135 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_141 += F_60 ( V_153 , V_2 ) ;
else {
V_141 += F_1 ( V_2 , V_135 ) ;
F_58 ( V_2 , V_135 ) ;
}
if ( V_139 != 4 )
V_141 += F_1 ( V_2 , V_139 ) << V_140 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
if ( V_2 -> V_36 == V_37 )
V_2 -> V_154 = 1 ;
} else {
V_135 = V_2 -> V_20 ;
V_141 += F_1 ( V_2 , V_135 ) ;
F_58 ( V_2 , V_135 ) ;
}
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 5 )
V_141 += F_60 ( V_153 , V_2 ) ;
break;
case 1 :
V_141 += F_60 ( V_152 , V_2 ) ;
break;
case 2 :
V_141 += F_60 ( V_153 , V_2 ) ;
break;
}
}
V_113 -> V_77 . V_155 . V_85 = V_141 ;
V_156:
return V_91 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
int V_91 = V_89 ;
V_113 -> type = V_144 ;
switch ( V_2 -> V_28 ) {
case 2 :
V_113 -> V_77 . V_155 . V_85 = F_60 ( T_2 , V_2 ) ;
break;
case 4 :
V_113 -> V_77 . V_155 . V_85 = F_60 ( T_3 , V_2 ) ;
break;
case 8 :
V_113 -> V_77 . V_155 . V_85 = F_60 ( V_115 , V_2 ) ;
break;
}
V_156:
return V_91 ;
}
static void F_62 ( struct V_1 * V_2 )
{
long V_157 = 0 , V_32 ;
if ( V_2 -> V_27 . type == V_144 && V_2 -> V_22 . type == V_132 ) {
V_32 = ~ ( V_2 -> V_27 . V_25 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_25 == 2 )
V_157 = ( V_158 ) V_2 -> V_22 . V_114 & ( V_158 ) V_32 ;
else if ( V_2 -> V_22 . V_25 == 4 )
V_157 = ( V_153 ) V_2 -> V_22 . V_114 & ( V_153 ) V_32 ;
V_2 -> V_27 . V_77 . V_155 . V_85 += ( V_157 >> 3 ) ;
}
V_2 -> V_22 . V_114 &= ( V_2 -> V_27 . V_25 << 3 ) - 1 ;
}
static int F_63 ( struct V_1 * V_2 ,
unsigned long V_77 , void * V_31 , unsigned V_72 )
{
int V_91 ;
struct V_159 * V_160 = & V_2 -> V_161 ;
if ( V_160 -> V_162 < V_160 -> V_96 )
goto V_163;
F_64 ( ( V_160 -> V_96 + V_72 ) >= sizeof( V_160 -> V_90 ) ) ;
V_91 = V_2 -> V_6 -> F_63 ( V_2 , V_77 , V_160 -> V_90 + V_160 -> V_96 , V_72 ,
& V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_160 -> V_96 += V_72 ;
V_163:
memcpy ( V_31 , V_160 -> V_90 + V_160 -> V_162 , V_72 ) ;
V_160 -> V_162 += V_72 ;
return V_89 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
void * V_90 ,
unsigned V_72 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_77 , V_72 , false , & V_80 ) ;
if ( V_91 != V_89 )
return V_91 ;
return F_63 ( V_2 , V_80 , V_90 , V_72 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
const void * V_90 ,
unsigned V_72 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_77 , V_72 , true , & V_80 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_164 ( V_2 , V_80 , V_90 , V_72 ,
& V_2 -> V_55 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
const void * V_165 , const void * V_90 ,
unsigned V_72 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_77 , V_72 , true , & V_80 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_166 ( V_2 , V_80 , V_165 , V_90 ,
V_72 , & V_2 -> V_55 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned short V_167 ,
void * V_31 )
{
struct V_159 * V_91 = & V_2 -> V_168 ;
if ( V_91 -> V_162 == V_91 -> V_96 ) {
unsigned int V_169 , V_170 ;
unsigned int V_171 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_172 ) ) : 1 ;
V_169 = ( V_2 -> V_173 & V_174 ) ?
F_40 ( F_1 ( V_2 , V_151 ) ) :
V_99 - F_40 ( F_1 ( V_2 , V_151 ) ) ;
V_170 = F_39 ( F_39 ( V_169 , ( unsigned int ) sizeof( V_91 -> V_90 ) ) / V_72 ,
V_171 ) ;
if ( V_170 == 0 )
V_170 = 1 ;
V_91 -> V_162 = V_91 -> V_96 = 0 ;
if ( ! V_2 -> V_6 -> F_68 ( V_2 , V_72 , V_167 , V_91 -> V_90 , V_170 ) )
return 0 ;
V_91 -> V_96 = V_170 * V_72 ;
}
if ( V_2 -> V_17 && ! ( V_2 -> V_173 & V_174 ) ) {
V_2 -> V_27 . V_90 = V_91 -> V_90 + V_91 -> V_162 ;
V_2 -> V_27 . type = V_175 ;
V_2 -> V_27 . V_171 = ( V_91 -> V_96 - V_91 -> V_162 ) / V_72 ;
V_91 -> V_162 = V_91 -> V_96 ;
} else {
memcpy ( V_31 , V_91 -> V_90 + V_91 -> V_162 , V_72 ) ;
V_91 -> V_162 += V_72 ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_2 V_176 , struct V_34 * V_45 )
{
struct V_177 V_178 ;
T_1 V_77 ;
V_2 -> V_6 -> V_179 ( V_2 , & V_178 ) ;
if ( V_178 . V_72 < V_176 * 8 + 7 )
return F_25 ( V_2 , V_176 << 3 | 0x2 ) ;
V_77 = V_178 . V_105 + V_176 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_177 * V_178 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
if ( V_68 & 1 << 2 ) {
struct V_34 V_45 ;
T_2 V_33 ;
memset ( V_178 , 0 , sizeof *V_178 ) ;
if ( ! V_6 -> V_38 ( V_2 , & V_33 , & V_45 , NULL , V_181 ) )
return;
V_178 -> V_72 = F_19 ( & V_45 ) ;
V_178 -> V_105 = F_71 ( & V_45 ) ;
} else
V_6 -> V_182 ( V_2 , V_178 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 ,
T_1 * V_183 )
{
struct V_177 V_178 ;
T_2 V_176 = V_68 >> 3 ;
T_1 V_77 ;
F_70 ( V_2 , V_68 , & V_178 ) ;
if ( V_178 . V_72 < V_176 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
* V_183 = V_77 = V_178 . V_105 + V_176 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 )
{
struct V_177 V_178 ;
T_2 V_176 = V_68 >> 3 ;
T_1 V_77 ;
F_70 ( V_2 , V_68 , & V_178 ) ;
if ( V_178 . V_72 < V_176 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
V_77 = V_178 . V_105 + V_176 * 8 ;
return V_2 -> V_6 -> V_184 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
T_2 V_68 , int V_48 )
{
struct V_34 V_185 , V_186 ;
T_4 V_88 , V_187 , V_84 ;
unsigned V_188 = V_62 ;
T_3 V_189 = 0 ;
bool V_190 = ! ( V_68 & ~ 0x3 ) ;
T_1 V_191 ;
int V_192 ;
T_2 V_69 ;
memset ( & V_185 , 0 , sizeof V_185 ) ;
if ( V_2 -> V_36 == V_87 ) {
V_2 -> V_6 -> V_38 ( V_2 , & V_69 , & V_185 , NULL , V_48 ) ;
F_75 ( & V_185 , V_68 << 4 ) ;
goto V_193;
} else if ( V_48 <= V_194 && V_2 -> V_36 == V_195 ) {
F_75 ( & V_185 , V_68 << 4 ) ;
F_76 ( & V_185 , 0xffff ) ;
V_185 . type = 3 ;
V_185 . V_102 = 1 ;
V_185 . V_196 = 1 ;
V_185 . V_88 = 3 ;
goto V_193;
}
V_187 = V_68 & 3 ;
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( ( V_48 == V_97
|| ( V_48 == V_39
&& ( V_2 -> V_36 != V_37 || V_187 != V_84 ) )
|| V_48 == V_197 )
&& V_190 )
goto V_55;
if ( V_48 == V_197 && ( V_68 & ( 1 << 2 ) ) )
goto V_55;
if ( V_190 )
goto V_193;
V_192 = F_72 ( V_2 , V_68 , & V_185 , & V_191 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_189 = V_68 & 0xfffc ;
V_188 = V_62 ;
if ( V_48 <= V_194 && ! V_185 . V_196 )
goto V_55;
if ( ! V_185 . V_102 ) {
V_188 = ( V_48 == V_39 ) ? V_63 : V_198 ;
goto V_55;
}
V_88 = V_185 . V_88 ;
switch ( V_48 ) {
case V_39 :
if ( V_187 != V_84 || ( V_185 . type & 0xa ) != 0x2 || V_88 != V_84 )
goto V_55;
break;
case V_97 :
if ( ! ( V_185 . type & 8 ) )
goto V_55;
if ( V_185 . type & 4 ) {
if ( V_88 > V_84 )
goto V_55;
} else {
if ( V_187 > V_84 || V_88 != V_84 )
goto V_55;
}
V_68 = ( V_68 & 0xfffc ) | V_84 ;
break;
case V_197 :
if ( V_185 . V_196 || ( V_185 . type != 1 && V_185 . type != 9 ) )
goto V_55;
V_186 = V_185 ;
V_185 . type |= 2 ;
V_192 = V_2 -> V_6 -> V_166 ( V_2 , V_191 , & V_186 , & V_185 ,
sizeof( V_185 ) , & V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
break;
case V_181 :
if ( V_185 . V_196 || V_185 . type != 2 )
goto V_55;
break;
default:
if ( ( V_185 . type & 0xa ) == 0x8 ||
( ( ( V_185 . type & 0xc ) != 0xc ) &&
( V_187 > V_88 && V_84 > V_88 ) ) )
goto V_55;
break;
}
if ( V_185 . V_196 ) {
V_185 . type |= 1 ;
V_192 = F_73 ( V_2 , V_68 , & V_185 ) ;
if ( V_192 != V_89 )
return V_192 ;
}
V_193:
V_2 -> V_6 -> V_71 ( V_2 , V_68 , & V_185 , 0 , V_48 ) ;
return V_89 ;
V_55:
F_23 ( V_2 , V_188 , V_189 , true ) ;
return V_59 ;
}
static void F_77 ( struct V_112 * V_113 )
{
switch ( V_113 -> V_25 ) {
case 1 :
* ( T_4 * ) V_113 -> V_77 . V_9 = ( T_4 ) V_113 -> V_114 ;
break;
case 2 :
* ( T_2 * ) V_113 -> V_77 . V_9 = ( T_2 ) V_113 -> V_114 ;
break;
case 4 :
* V_113 -> V_77 . V_9 = ( T_3 ) V_113 -> V_114 ;
break;
case 8 :
* V_113 -> V_77 . V_9 = V_113 -> V_114 ;
break;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_112 * V_113 )
{
int V_91 ;
switch ( V_113 -> type ) {
case V_132 :
F_77 ( V_113 ) ;
break;
case V_144 :
if ( V_2 -> V_199 )
V_91 = F_67 ( V_2 ,
V_113 -> V_77 . V_155 ,
& V_113 -> V_134 ,
& V_113 -> V_114 ,
V_113 -> V_25 ) ;
else
V_91 = F_66 ( V_2 ,
V_113 -> V_77 . V_155 ,
& V_113 -> V_114 ,
V_113 -> V_25 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_175 :
V_91 = F_66 ( V_2 ,
V_113 -> V_77 . V_155 ,
V_113 -> V_90 ,
V_113 -> V_25 * V_113 -> V_171 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_126 :
F_51 ( V_2 , & V_113 -> V_128 , V_113 -> V_77 . V_127 ) ;
break;
case V_130 :
F_53 ( V_2 , & V_113 -> V_200 , V_113 -> V_77 . V_131 ) ;
break;
case V_201 :
break;
default:
break;
}
return V_89 ;
}
static int F_79 ( struct V_1 * V_2 , void * V_90 , int V_25 )
{
struct V_76 V_77 ;
F_17 ( V_2 , - V_25 ) ;
V_77 . V_85 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
return F_66 ( V_2 , V_77 , V_90 , V_25 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_201 ;
return F_79 ( V_2 , & V_2 -> V_22 . V_114 , V_2 -> V_106 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
void * V_31 , int V_202 )
{
int V_91 ;
struct V_76 V_77 ;
V_77 . V_85 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
V_91 = F_65 ( V_2 , V_77 , V_31 , V_202 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_202 ) ;
return V_91 ;
}
static int F_82 ( struct V_1 * V_2 )
{
return F_81 ( V_2 , & V_2 -> V_27 . V_114 , V_2 -> V_106 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
void * V_31 , int V_202 )
{
int V_91 ;
unsigned long V_114 , V_203 ;
int V_204 = ( V_2 -> V_173 & V_205 ) >> V_206 ;
int V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
V_91 = F_81 ( V_2 , & V_114 , V_202 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_203 = V_207 | V_208 | V_209 | V_210 | V_211 | V_212
| V_213 | V_174 | V_214 | V_215 | V_216 | V_217 ;
switch( V_2 -> V_36 ) {
case V_37 :
case V_218 :
case V_219 :
if ( V_84 == 0 )
V_203 |= V_220 ;
if ( V_84 <= V_204 )
V_203 |= V_221 ;
break;
case V_195 :
if ( V_204 < 3 )
return F_25 ( V_2 , 0 ) ;
V_203 |= V_221 ;
break;
default:
V_203 |= ( V_220 | V_221 ) ;
break;
}
* ( unsigned long * ) V_31 =
( V_2 -> V_173 & ~ V_203 ) | ( V_114 & V_203 ) ;
return V_91 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_132 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_173 ;
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
return F_83 ( V_2 , & V_2 -> V_27 . V_114 , V_2 -> V_106 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned V_222 = V_2 -> V_22 . V_114 ;
unsigned V_223 = V_2 -> V_224 . V_114 & 31 ;
T_1 V_225 ;
if ( V_223 )
return V_100 ;
V_225 = F_1 ( V_2 , V_136 ) ;
V_91 = F_79 ( V_2 , & V_225 , F_11 ( V_2 ) ) ;
if ( V_91 != V_89 )
return V_91 ;
F_8 ( F_3 ( V_2 , V_136 ) , F_1 ( V_2 , V_42 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_42 ) ,
F_1 ( V_2 , V_42 ) - V_222 ,
F_10 ( V_2 ) ) ;
return V_89 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_42 ) , F_1 ( V_2 , V_136 ) ,
F_10 ( V_2 ) ) ;
return F_81 ( V_2 , F_3 ( V_2 , V_136 ) , V_2 -> V_106 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_114 ;
V_2 -> V_22 . V_114 = F_31 ( V_2 , V_48 ) ;
return F_80 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_114 ;
unsigned long V_68 ;
int V_91 ;
V_91 = F_81 ( V_2 , & V_68 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_68 , V_48 ) ;
return V_91 ;
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned long V_226 = F_1 ( V_2 , V_42 ) ;
int V_91 = V_89 ;
int V_9 = V_227 ;
while ( V_9 <= V_151 ) {
( V_9 == V_42 ) ?
( V_2 -> V_22 . V_114 = V_226 ) : ( V_2 -> V_22 . V_114 = F_1 ( V_2 , V_9 ) ) ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
++ V_9 ;
}
return V_91 ;
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_114 = ( unsigned long ) V_2 -> V_173 ;
return F_80 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
int V_9 = V_151 ;
while ( V_9 >= V_227 ) {
if ( V_9 == V_42 ) {
F_17 ( V_2 , V_2 -> V_106 ) ;
-- V_9 ;
}
V_91 = F_81 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
break;
-- V_9 ;
}
return V_91 ;
}
static int F_92 ( struct V_1 * V_2 , int V_228 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
int V_91 ;
struct V_177 V_178 ;
T_6 V_229 ;
T_6 V_230 ;
T_2 V_231 , V_30 ;
V_2 -> V_22 . V_114 = V_2 -> V_173 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_173 &= ~ ( V_221 | V_213 | V_216 ) ;
V_2 -> V_22 . V_114 = F_31 ( V_2 , V_97 ) ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_114 = V_2 -> V_44 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_6 -> V_179 ( V_2 , & V_178 ) ;
V_230 = V_178 . V_105 + ( V_228 << 2 ) ;
V_229 = V_178 . V_105 + ( V_228 << 2 ) + 2 ;
V_91 = V_6 -> V_92 ( V_2 , V_229 , & V_231 , 2 , & V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = V_6 -> V_92 ( V_2 , V_230 , & V_30 , 2 , & V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , V_231 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_30 ;
return V_91 ;
}
int F_93 ( struct V_1 * V_2 , int V_228 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_91 = F_92 ( V_2 , V_228 ) ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return V_91 ;
}
static int F_94 ( struct V_1 * V_2 , int V_228 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_92 ( V_2 , V_228 ) ;
case V_195 :
case V_219 :
case V_218 :
case V_37 :
default:
return V_100 ;
}
}
static int F_95 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
unsigned long V_232 = 0 ;
unsigned long V_233 = 0 ;
unsigned long V_231 = 0 ;
unsigned long V_32 = V_207 | V_208 | V_209 | V_210 | V_211 | V_213 |
V_221 | V_174 | V_212 | V_220 | V_214 | V_215 |
V_216 | V_217 | ( 1 << 1 ) ;
unsigned long V_234 = V_235 | V_236 | V_237 ;
V_91 = F_81 ( V_2 , & V_232 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_232 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_91 = F_81 ( V_2 , & V_231 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_81 ( V_2 , & V_233 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_231 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_232 ;
if ( V_2 -> V_106 == 4 )
V_2 -> V_173 = ( ( V_233 & V_32 ) | ( V_2 -> V_173 & V_234 ) ) ;
else if ( V_2 -> V_106 == 2 ) {
V_2 -> V_173 &= ~ 0xffff ;
V_2 -> V_173 |= V_233 ;
}
V_2 -> V_173 &= ~ V_238 ;
V_2 -> V_173 |= V_239 ;
return V_91 ;
}
static int F_96 ( struct V_1 * V_2 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_95 ( V_2 ) ;
case V_195 :
case V_219 :
case V_218 :
case V_37 :
default:
return V_100 ;
}
}
static int F_97 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned short V_33 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_106 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_240 , V_2 -> V_106 ) ;
return V_89 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
switch ( V_2 -> V_19 ) {
case 2 : {
long int V_241 ;
V_241 = V_2 -> V_44 ;
V_2 -> V_44 = V_2 -> V_22 . V_114 ;
V_2 -> V_22 . V_114 = V_241 ;
V_91 = F_80 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_44 = V_2 -> V_22 . V_114 ;
break;
case 5 :
V_91 = F_97 ( V_2 ) ;
break;
case 6 :
V_91 = F_80 ( V_2 ) ;
break;
}
return V_91 ;
}
static int F_99 ( struct V_1 * V_2 )
{
V_115 V_242 = V_2 -> V_27 . V_243 ;
if ( ( ( T_3 ) ( V_242 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_227 ) ) ||
( ( T_3 ) ( V_242 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_244 ) ) ) {
* F_2 ( V_2 , V_227 ) = ( T_3 ) ( V_242 >> 0 ) ;
* F_2 ( V_2 , V_244 ) = ( T_3 ) ( V_242 >> 32 ) ;
V_2 -> V_173 &= ~ V_210 ;
} else {
V_2 -> V_27 . V_23 = ( ( V_115 ) F_1 ( V_2 , V_172 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_146 ) ;
V_2 -> V_173 |= V_210 ;
}
return V_89 ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_132 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
return F_82 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_231 ;
V_91 = F_81 ( V_2 , & V_2 -> V_44 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_106 == 4 )
V_2 -> V_44 = ( T_3 ) V_2 -> V_44 ;
V_91 = F_81 ( V_2 , & V_231 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_231 , V_97 ) ;
return V_91 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = F_101 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_114 ) ;
return V_89 ;
}
static int F_103 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_134 = V_2 -> V_22 . V_114 ;
V_2 -> V_22 . V_114 = F_1 ( V_2 , V_227 ) ;
F_104 ( V_2 , V_245 ) ;
if ( V_2 -> V_173 & V_210 ) {
V_2 -> V_27 . V_114 = V_2 -> V_22 . V_134 ;
} else {
V_2 -> V_27 . type = V_132 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_227 ) ;
}
return V_89 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_114 ;
unsigned short V_33 ;
int V_91 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_106 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_48 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_27 . V_114 = V_2 -> V_22 . V_114 ;
return V_91 ;
}
static void
F_106 ( struct V_1 * V_2 ,
struct V_34 * V_231 , struct V_34 * V_35 )
{
V_231 -> V_246 = 0 ;
F_75 ( V_231 , 0 ) ;
V_231 -> V_47 = 1 ;
F_76 ( V_231 , 0xfffff ) ;
V_231 -> type = 0x0b ;
V_231 -> V_196 = 1 ;
V_231 -> V_88 = 0 ;
V_231 -> V_102 = 1 ;
V_231 -> V_40 = 1 ;
V_231 -> V_247 = 0 ;
F_75 ( V_35 , 0 ) ;
F_76 ( V_35 , 0xfffff ) ;
V_35 -> V_47 = 1 ;
V_35 -> V_196 = 1 ;
V_35 -> type = 0x03 ;
V_35 -> V_40 = 1 ;
V_35 -> V_88 = 0 ;
V_35 -> V_102 = 1 ;
V_35 -> V_246 = 0 ;
V_35 -> V_247 = 0 ;
}
static bool F_107 ( struct V_1 * V_2 )
{
T_3 V_248 , V_249 , V_250 , V_251 ;
V_248 = V_250 = 0 ;
V_2 -> V_6 -> V_252 ( V_2 , & V_248 , & V_249 , & V_250 , & V_251 ) ;
return V_249 == V_253
&& V_250 == V_254
&& V_251 == V_255 ;
}
static bool F_108 ( struct V_1 * V_2 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
T_3 V_248 , V_249 , V_250 , V_251 ;
if ( V_2 -> V_36 == V_37 )
return true ;
V_248 = 0x00000000 ;
V_250 = 0x00000000 ;
V_6 -> V_252 ( V_2 , & V_248 , & V_249 , & V_250 , & V_251 ) ;
if ( V_249 == V_253 &&
V_250 == V_254 &&
V_251 == V_255 )
return false ;
if ( V_249 == V_256 &&
V_250 == V_257 &&
V_251 == V_258 )
return true ;
if ( V_249 == V_259 &&
V_250 == V_260 &&
V_251 == V_261 )
return true ;
return false ;
}
static int F_109 ( struct V_1 * V_2 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_115 V_262 ;
T_2 V_263 , V_264 ;
V_115 V_265 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_195 )
return F_27 ( V_2 ) ;
if ( ! ( F_108 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
F_106 ( V_2 , & V_231 , & V_35 ) ;
if ( ! ( V_265 & V_268 ) )
return F_27 ( V_2 ) ;
V_6 -> V_266 ( V_2 , V_269 , & V_262 ) ;
V_262 >>= 32 ;
V_263 = ( T_2 ) ( V_262 & 0xfffc ) ;
V_264 = ( T_2 ) ( V_262 + 8 ) ;
if ( V_265 & V_270 ) {
V_231 . V_40 = 0 ;
V_231 . V_246 = 1 ;
}
V_6 -> V_71 ( V_2 , V_263 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_264 , & V_35 , 0 , V_39 ) ;
* F_2 ( V_2 , V_172 ) = V_2 -> V_44 ;
if ( V_265 & V_270 ) {
#ifdef F_49
* F_2 ( V_2 , V_271 ) = V_2 -> V_173 & ~ V_215 ;
V_6 -> V_266 ( V_2 ,
V_2 -> V_36 == V_37 ?
V_272 : V_273 , & V_262 ) ;
V_2 -> V_44 = V_262 ;
V_6 -> V_266 ( V_2 , V_274 , & V_262 ) ;
V_2 -> V_173 &= ~ ( V_262 | V_215 ) ;
#endif
} else {
V_6 -> V_266 ( V_2 , V_269 , & V_262 ) ;
V_2 -> V_44 = ( T_3 ) V_262 ;
V_2 -> V_173 &= ~ ( V_235 | V_221 | V_215 ) ;
}
return V_89 ;
}
static int F_110 ( struct V_1 * V_2 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_115 V_262 ;
T_2 V_263 , V_264 ;
V_115 V_265 = 0 ;
V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
if ( V_2 -> V_36 == V_87 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_36 == V_218 ) && ( V_265 & V_270 )
&& ! F_107 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_36 == V_37 )
return F_27 ( V_2 ) ;
F_106 ( V_2 , & V_231 , & V_35 ) ;
V_6 -> V_266 ( V_2 , V_275 , & V_262 ) ;
switch ( V_2 -> V_36 ) {
case V_218 :
if ( ( V_262 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
case V_37 :
if ( V_262 == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_173 &= ~ ( V_235 | V_221 | V_215 ) ;
V_263 = ( T_2 ) V_262 ;
V_263 &= ~ V_276 ;
V_264 = V_263 + 8 ;
V_264 &= ~ V_276 ;
if ( V_2 -> V_36 == V_37 || ( V_265 & V_270 ) ) {
V_231 . V_40 = 0 ;
V_231 . V_246 = 1 ;
}
V_6 -> V_71 ( V_2 , V_263 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_264 , & V_35 , 0 , V_39 ) ;
V_6 -> V_266 ( V_2 , V_277 , & V_262 ) ;
V_2 -> V_44 = V_262 ;
V_6 -> V_266 ( V_2 , V_278 , & V_262 ) ;
* F_2 ( V_2 , V_42 ) = V_262 ;
return V_89 ;
}
static int F_111 ( struct V_1 * V_2 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_115 V_262 ;
int V_279 ;
T_2 V_263 = 0 , V_264 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_195 )
return F_25 ( V_2 , 0 ) ;
F_106 ( V_2 , & V_231 , & V_35 ) ;
if ( ( V_2 -> V_104 & 0x8 ) != 0x0 )
V_279 = V_37 ;
else
V_279 = V_218 ;
V_231 . V_88 = 3 ;
V_35 . V_88 = 3 ;
V_6 -> V_266 ( V_2 , V_275 , & V_262 ) ;
switch ( V_279 ) {
case V_218 :
V_263 = ( T_2 ) ( V_262 + 16 ) ;
if ( ( V_262 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_264 = ( T_2 ) ( V_262 + 24 ) ;
break;
case V_37 :
V_263 = ( T_2 ) ( V_262 + 32 ) ;
if ( V_262 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_264 = V_263 + 8 ;
V_231 . V_40 = 0 ;
V_231 . V_246 = 1 ;
break;
}
V_263 |= V_276 ;
V_264 |= V_276 ;
V_6 -> V_71 ( V_2 , V_263 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_264 , & V_35 , 0 , V_39 ) ;
V_2 -> V_44 = F_1 ( V_2 , V_244 ) ;
* F_2 ( V_2 , V_42 ) = F_1 ( V_2 , V_172 ) ;
return V_89 ;
}
static bool F_112 ( struct V_1 * V_2 )
{
int V_204 ;
if ( V_2 -> V_36 == V_87 )
return false ;
if ( V_2 -> V_36 == V_195 )
return true ;
V_204 = ( V_2 -> V_173 & V_205 ) >> V_206 ;
return V_2 -> V_6 -> V_84 ( V_2 ) > V_204 ;
}
static bool F_113 ( struct V_1 * V_2 ,
T_2 V_167 , T_2 V_202 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_34 V_280 ;
T_3 V_70 ;
int V_281 ;
T_2 V_282 , V_283 , V_284 , V_285 = V_167 & 0x7 ;
unsigned V_32 = ( 1 << V_202 ) - 1 ;
unsigned long V_286 ;
V_6 -> V_38 ( V_2 , & V_282 , & V_280 , & V_70 , V_197 ) ;
if ( ! V_280 . V_102 )
return false ;
if ( F_19 ( & V_280 ) < 103 )
return false ;
V_286 = F_71 ( & V_280 ) ;
#ifdef F_49
V_286 |= ( ( V_115 ) V_70 ) << 32 ;
#endif
V_281 = V_6 -> V_92 ( V_2 , V_286 + 102 , & V_283 , 2 , NULL ) ;
if ( V_281 != V_89 )
return false ;
if ( V_283 + V_167 / 8 > F_19 ( & V_280 ) )
return false ;
V_281 = V_6 -> V_92 ( V_2 , V_286 + V_283 + V_167 / 8 , & V_284 , 2 , NULL ) ;
if ( V_281 != V_89 )
return false ;
if ( ( V_284 >> V_285 ) & V_32 )
return false ;
return true ;
}
static bool F_114 ( struct V_1 * V_2 ,
T_2 V_167 , T_2 V_202 )
{
if ( V_2 -> V_287 )
return true ;
if ( F_112 ( V_2 ) )
if ( ! F_113 ( V_2 , V_167 , V_202 ) )
return false ;
V_2 -> V_287 = true ;
return true ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_288 * V_289 )
{
V_289 -> V_290 = V_2 -> V_44 ;
V_289 -> V_291 = V_2 -> V_173 ;
V_289 -> V_292 = F_1 ( V_2 , V_227 ) ;
V_289 -> V_293 = F_1 ( V_2 , V_172 ) ;
V_289 -> V_294 = F_1 ( V_2 , V_244 ) ;
V_289 -> V_145 = F_1 ( V_2 , V_146 ) ;
V_289 -> V_295 = F_1 ( V_2 , V_42 ) ;
V_289 -> V_147 = F_1 ( V_2 , V_136 ) ;
V_289 -> V_148 = F_1 ( V_2 , V_149 ) ;
V_289 -> V_150 = F_1 ( V_2 , V_151 ) ;
V_289 -> V_296 = F_31 ( V_2 , V_297 ) ;
V_289 -> V_231 = F_31 ( V_2 , V_97 ) ;
V_289 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_289 -> V_298 = F_31 ( V_2 , V_143 ) ;
V_289 -> V_299 = F_31 ( V_2 , V_181 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_288 * V_289 )
{
int V_192 ;
V_2 -> V_44 = V_289 -> V_290 ;
V_2 -> V_173 = V_289 -> V_291 | 2 ;
* F_2 ( V_2 , V_227 ) = V_289 -> V_292 ;
* F_2 ( V_2 , V_172 ) = V_289 -> V_293 ;
* F_2 ( V_2 , V_244 ) = V_289 -> V_294 ;
* F_2 ( V_2 , V_146 ) = V_289 -> V_145 ;
* F_2 ( V_2 , V_42 ) = V_289 -> V_295 ;
* F_2 ( V_2 , V_136 ) = V_289 -> V_147 ;
* F_2 ( V_2 , V_149 ) = V_289 -> V_148 ;
* F_2 ( V_2 , V_151 ) = V_289 -> V_150 ;
F_32 ( V_2 , V_289 -> V_299 , V_181 ) ;
F_32 ( V_2 , V_289 -> V_296 , V_297 ) ;
F_32 ( V_2 , V_289 -> V_231 , V_97 ) ;
F_32 ( V_2 , V_289 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_289 -> V_298 , V_143 ) ;
V_192 = F_74 ( V_2 , V_289 -> V_299 , V_181 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_296 , V_297 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_231 , V_97 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_35 , V_39 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_298 , V_143 ) ;
if ( V_192 != V_89 )
return V_192 ;
return V_89 ;
}
static int F_117 ( struct V_1 * V_2 ,
T_2 V_300 , T_2 V_301 ,
T_1 V_302 , struct V_34 * V_303 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_288 V_304 ;
int V_192 ;
T_3 V_305 = F_71 ( V_303 ) ;
V_192 = V_6 -> V_92 ( V_2 , V_302 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
F_115 ( V_2 , & V_304 ) ;
V_192 = V_6 -> V_184 ( V_2 , V_302 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = V_6 -> V_92 ( V_2 , V_305 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
if ( V_301 != 0xffff ) {
V_304 . V_306 = V_301 ;
V_192 = V_6 -> V_184 ( V_2 , V_305 ,
& V_304 . V_306 ,
sizeof V_304 . V_306 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
}
return F_116 ( V_2 , & V_304 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_307 * V_289 )
{
V_289 -> V_308 = V_2 -> V_6 -> V_118 ( V_2 , 3 ) ;
V_289 -> V_30 = V_2 -> V_44 ;
V_289 -> V_173 = V_2 -> V_173 ;
V_289 -> V_248 = F_1 ( V_2 , V_227 ) ;
V_289 -> V_250 = F_1 ( V_2 , V_172 ) ;
V_289 -> V_251 = F_1 ( V_2 , V_244 ) ;
V_289 -> V_249 = F_1 ( V_2 , V_146 ) ;
V_289 -> V_309 = F_1 ( V_2 , V_42 ) ;
V_289 -> V_310 = F_1 ( V_2 , V_136 ) ;
V_289 -> V_311 = F_1 ( V_2 , V_149 ) ;
V_289 -> V_312 = F_1 ( V_2 , V_151 ) ;
V_289 -> V_296 = F_31 ( V_2 , V_297 ) ;
V_289 -> V_231 = F_31 ( V_2 , V_97 ) ;
V_289 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_289 -> V_298 = F_31 ( V_2 , V_143 ) ;
V_289 -> V_313 = F_31 ( V_2 , V_51 ) ;
V_289 -> V_314 = F_31 ( V_2 , V_194 ) ;
V_289 -> V_315 = F_31 ( V_2 , V_181 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_307 * V_289 )
{
int V_192 ;
if ( V_2 -> V_6 -> V_316 ( V_2 , 3 , V_289 -> V_308 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_44 = V_289 -> V_30 ;
V_2 -> V_173 = V_289 -> V_173 | 2 ;
* F_2 ( V_2 , V_227 ) = V_289 -> V_248 ;
* F_2 ( V_2 , V_172 ) = V_289 -> V_250 ;
* F_2 ( V_2 , V_244 ) = V_289 -> V_251 ;
* F_2 ( V_2 , V_146 ) = V_289 -> V_249 ;
* F_2 ( V_2 , V_42 ) = V_289 -> V_309 ;
* F_2 ( V_2 , V_136 ) = V_289 -> V_310 ;
* F_2 ( V_2 , V_149 ) = V_289 -> V_311 ;
* F_2 ( V_2 , V_151 ) = V_289 -> V_312 ;
F_32 ( V_2 , V_289 -> V_315 , V_181 ) ;
F_32 ( V_2 , V_289 -> V_296 , V_297 ) ;
F_32 ( V_2 , V_289 -> V_231 , V_97 ) ;
F_32 ( V_2 , V_289 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_289 -> V_298 , V_143 ) ;
F_32 ( V_2 , V_289 -> V_313 , V_51 ) ;
F_32 ( V_2 , V_289 -> V_314 , V_194 ) ;
if ( V_2 -> V_173 & V_317 )
V_2 -> V_36 = V_195 ;
else
V_2 -> V_36 = V_218 ;
V_2 -> V_6 -> V_318 ( V_2 , V_2 -> V_173 ) ;
V_192 = F_74 ( V_2 , V_289 -> V_315 , V_181 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_296 , V_297 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_231 , V_97 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_35 , V_39 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_298 , V_143 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_313 , V_51 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_74 ( V_2 , V_289 -> V_314 , V_194 ) ;
if ( V_192 != V_89 )
return V_192 ;
return V_89 ;
}
static int F_120 ( struct V_1 * V_2 ,
T_2 V_300 , T_2 V_301 ,
T_1 V_302 , struct V_34 * V_303 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_307 V_304 ;
int V_192 ;
T_3 V_305 = F_71 ( V_303 ) ;
V_192 = V_6 -> V_92 ( V_2 , V_302 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
F_118 ( V_2 , & V_304 ) ;
V_192 = V_6 -> V_184 ( V_2 , V_302 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = V_6 -> V_92 ( V_2 , V_305 , & V_304 , sizeof V_304 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
if ( V_301 != 0xffff ) {
V_304 . V_306 = V_301 ;
V_192 = V_6 -> V_184 ( V_2 , V_305 ,
& V_304 . V_306 ,
sizeof V_304 . V_306 ,
& V_2 -> V_55 ) ;
if ( V_192 != V_89 )
return V_192 ;
}
return F_119 ( V_2 , & V_304 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
T_2 V_300 , int V_319 , int V_320 ,
bool V_321 , T_3 V_57 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
struct V_34 V_322 , V_323 ;
int V_192 ;
T_2 V_301 = F_31 ( V_2 , V_197 ) ;
T_1 V_302 =
V_6 -> V_52 ( V_2 , V_197 ) ;
T_3 V_324 ;
T_1 V_191 ;
V_192 = F_72 ( V_2 , V_300 , & V_323 , & V_191 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_192 = F_72 ( V_2 , V_301 , & V_322 , & V_191 ) ;
if ( V_192 != V_89 )
return V_192 ;
if ( V_320 == V_325 ) {
if ( V_319 != - 1 ) {
struct V_34 V_326 ;
int V_88 ;
V_192 = F_69 ( V_2 , V_319 ,
& V_326 ) ;
if ( V_192 != V_89 )
return V_192 ;
V_88 = V_326 . V_88 ;
if ( ( V_300 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , ( V_319 << 3 ) | 0x2 ) ;
}
} else if ( V_320 != V_327 ) {
int V_88 = V_323 . V_88 ;
if ( ( V_300 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , V_300 ) ;
}
V_324 = F_19 ( & V_323 ) ;
if ( ! V_323 . V_102 ||
( ( V_324 < 0x67 && ( V_323 . type & 8 ) ) ||
V_324 < 0x2b ) ) {
F_28 ( V_2 , V_300 & 0xfffc ) ;
return V_59 ;
}
if ( V_320 == V_327 || V_320 == V_328 ) {
V_322 . type &= ~ ( 1 << 1 ) ;
F_73 ( V_2 , V_301 , & V_322 ) ;
}
if ( V_320 == V_327 )
V_2 -> V_173 = V_2 -> V_173 & ~ V_329 ;
if ( V_320 != V_330 && V_320 != V_325 )
V_301 = 0xffff ;
if ( V_323 . type & 8 )
V_192 = F_120 ( V_2 , V_300 , V_301 ,
V_302 , & V_323 ) ;
else
V_192 = F_117 ( V_2 , V_300 , V_301 ,
V_302 , & V_323 ) ;
if ( V_192 != V_89 )
return V_192 ;
if ( V_320 == V_330 || V_320 == V_325 )
V_2 -> V_173 = V_2 -> V_173 | V_329 ;
if ( V_320 != V_327 ) {
V_323 . type |= ( 1 << 1 ) ;
F_73 ( V_2 , V_300 , & V_323 ) ;
}
V_6 -> V_316 ( V_2 , 0 , V_6 -> V_118 ( V_2 , 0 ) | V_119 ) ;
V_6 -> V_71 ( V_2 , V_300 , & V_323 , 0 , V_197 ) ;
if ( V_321 ) {
V_2 -> V_106 = V_2 -> V_28 = ( V_323 . type & 8 ) ? 4 : 2 ;
V_2 -> V_199 = 0 ;
V_2 -> V_22 . V_114 = ( unsigned long ) V_57 ;
V_192 = F_80 ( V_2 ) ;
}
return V_192 ;
}
int F_122 ( struct V_1 * V_2 ,
T_2 V_300 , int V_319 , int V_320 ,
bool V_321 , T_3 V_57 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_201 ;
V_91 = F_121 ( V_2 , V_300 , V_319 , V_320 ,
V_321 , V_57 ) ;
if ( V_91 == V_89 ) {
V_2 -> V_30 = V_2 -> V_44 ;
F_4 ( V_2 ) ;
}
return ( V_91 == V_100 ) ? V_331 : V_332 ;
}
static void F_123 ( struct V_1 * V_2 , int V_9 ,
struct V_112 * V_113 )
{
int V_333 = ( V_2 -> V_173 & V_174 ) ? - V_113 -> V_171 : V_113 -> V_171 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_333 * V_113 -> V_25 ) ;
V_113 -> V_77 . V_155 . V_85 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
T_4 V_334 , V_335 ;
bool V_336 , V_337 , V_338 ;
V_337 = V_2 -> V_173 & V_339 ;
V_334 = V_2 -> V_27 . V_114 ;
V_335 = V_334 ;
V_338 = V_337 ;
V_337 = false ;
V_336 = V_2 -> V_173 & V_340 ;
if ( ( V_334 & 0x0f ) > 9 || V_336 ) {
V_334 -= 6 ;
V_337 = V_338 | ( V_334 >= 250 ) ;
V_336 = true ;
} else {
V_336 = false ;
}
if ( V_335 > 0x99 || V_338 ) {
V_334 -= 0x60 ;
V_337 = true ;
}
V_2 -> V_27 . V_114 = V_334 ;
V_2 -> V_22 . type = V_341 ;
V_2 -> V_22 . V_114 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_104 ( V_2 , V_342 ) ;
V_2 -> V_173 &= ~ ( V_340 | V_339 ) ;
if ( V_337 )
V_2 -> V_173 |= V_339 ;
if ( V_336 )
V_2 -> V_173 |= V_340 ;
return V_89 ;
}
static int F_125 ( struct V_1 * V_2 )
{
T_4 V_334 , V_343 ;
if ( V_2 -> V_22 . V_114 == 0 )
return F_29 ( V_2 ) ;
V_334 = V_2 -> V_27 . V_114 & 0xff ;
V_343 = V_334 / V_2 -> V_22 . V_114 ;
V_334 %= V_2 -> V_22 . V_114 ;
V_2 -> V_27 . V_114 = ( V_2 -> V_27 . V_114 & 0xffff0000 ) | V_334 | ( V_343 << 8 ) ;
V_2 -> V_22 . type = V_341 ;
V_2 -> V_22 . V_114 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_104 ( V_2 , V_342 ) ;
return V_89 ;
}
static int F_126 ( struct V_1 * V_2 )
{
T_4 V_334 = V_2 -> V_27 . V_114 & 0xff ;
T_4 V_343 = ( V_2 -> V_27 . V_114 >> 8 ) & 0xff ;
V_334 = ( V_334 + ( V_343 * V_2 -> V_22 . V_114 ) ) & 0xff ;
V_2 -> V_27 . V_114 = ( V_2 -> V_27 . V_114 & 0xffff0000 ) | V_334 ;
V_2 -> V_22 . type = V_341 ;
V_2 -> V_22 . V_114 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_104 ( V_2 , V_342 ) ;
return V_89 ;
}
static int F_127 ( struct V_1 * V_2 )
{
long V_43 = V_2 -> V_22 . V_114 ;
V_2 -> V_22 . V_114 = ( unsigned long ) V_2 -> V_44 ;
F_18 ( V_2 , V_43 ) ;
return F_80 ( V_2 ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
T_2 V_33 , V_344 ;
T_1 V_241 ;
int V_91 ;
V_344 = F_31 ( V_2 , V_97 ) ;
V_241 = V_2 -> V_44 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_106 , 2 ) ;
if ( F_74 ( V_2 , V_33 , V_97 ) )
return V_89 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_240 , V_2 -> V_106 ) ;
V_2 -> V_22 . V_114 = V_344 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_114 = V_241 ;
return F_80 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
int V_91 ;
V_2 -> V_27 . type = V_132 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
V_91 = F_81 ( V_2 , & V_2 -> V_27 . V_114 , V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_114 ) ;
return V_89 ;
}
static int F_130 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_114 = V_2 -> V_27 . V_114 ;
F_77 ( & V_2 -> V_22 ) ;
V_2 -> V_27 . V_114 = V_2 -> V_22 . V_134 ;
V_2 -> V_199 = 1 ;
return V_89 ;
}
static int F_131 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_114 = V_2 -> V_224 . V_114 ;
return F_104 ( V_2 , V_345 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_132 ;
V_2 -> V_27 . V_25 = V_2 -> V_22 . V_25 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_244 ) ;
V_2 -> V_27 . V_114 = ~ ( ( V_2 -> V_22 . V_114 >> ( V_2 -> V_22 . V_25 * 8 - 1 ) ) - 1 ) ;
return V_89 ;
}
static int F_133 ( struct V_1 * V_2 )
{
V_115 V_346 = 0 ;
V_2 -> V_6 -> V_266 ( V_2 , V_347 , & V_346 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_346 ;
* F_2 ( V_2 , V_244 ) = V_346 >> 32 ;
return V_89 ;
}
static int F_134 ( struct V_1 * V_2 )
{
V_115 V_348 ;
if ( V_2 -> V_6 -> V_349 ( V_2 , F_1 ( V_2 , V_172 ) , & V_348 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_348 ;
* F_2 ( V_2 , V_244 ) = V_348 >> 32 ;
return V_89 ;
}
static int F_135 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_27 . V_240 , V_2 -> V_22 . V_240 , V_2 -> V_106 ) ;
return V_89 ;
}
static int F_136 ( struct V_1 * V_2 )
{
T_3 V_249 , V_250 , V_251 , V_248 = 1 ;
T_2 V_350 ;
V_2 -> V_6 -> V_252 ( V_2 , & V_248 , & V_249 , & V_250 , & V_251 ) ;
if ( ! ( V_250 & F_137 ( V_351 ) ) )
return F_27 ( V_2 ) ;
switch ( V_2 -> V_106 ) {
case 2 :
V_350 = ( T_2 ) V_2 -> V_22 . V_114 ;
V_2 -> V_27 . V_114 &= ~ 0xffffUL ;
V_2 -> V_27 . V_114 |= ( unsigned long ) F_138 ( V_350 ) ;
break;
case 4 :
V_2 -> V_27 . V_114 = F_139 ( ( T_3 ) V_2 -> V_22 . V_114 ) ;
break;
case 8 :
V_2 -> V_27 . V_114 = F_140 ( V_2 -> V_22 . V_114 ) ;
break;
default:
return V_59 ;
}
return V_89 ;
}
static int F_141 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_316 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_114 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_142 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
if ( V_2 -> V_36 == V_37 )
V_114 = V_2 -> V_22 . V_114 & ~ 0ULL ;
else
V_114 = V_2 -> V_22 . V_114 & ~ 0U ;
if ( V_2 -> V_6 -> V_352 ( V_2 , V_2 -> V_19 , V_114 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_115 V_262 ;
V_262 = ( T_3 ) F_1 ( V_2 , V_227 )
| ( ( V_115 ) F_1 ( V_2 , V_244 ) << 32 ) ;
if ( V_2 -> V_6 -> V_353 ( V_2 , F_1 ( V_2 , V_172 ) , V_262 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_144 ( struct V_1 * V_2 )
{
V_115 V_262 ;
if ( V_2 -> V_6 -> V_266 ( V_2 , F_1 ( V_2 , V_172 ) , & V_262 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_262 ;
* F_2 ( V_2 , V_244 ) = V_262 >> 32 ;
return V_89 ;
}
static int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_194 )
return F_27 ( V_2 ) ;
V_2 -> V_27 . V_114 = F_31 ( V_2 , V_2 -> V_19 ) ;
return V_89 ;
}
static int F_146 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_114 ;
if ( V_2 -> V_19 == V_97 || V_2 -> V_19 > V_194 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_39 )
V_2 -> V_354 = V_355 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_2 -> V_19 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_114 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_181 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_114 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_197 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_2 -> V_22 . V_77 . V_155 , 1 , false , & V_80 ) ;
if ( V_91 == V_89 )
V_2 -> V_6 -> V_356 ( V_2 , V_80 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_150 ( struct V_1 * V_2 )
{
T_1 V_357 ;
V_357 = V_2 -> V_6 -> V_118 ( V_2 , 0 ) ;
V_357 &= ~ V_119 ;
V_2 -> V_6 -> V_316 ( V_2 , 0 , V_357 ) ;
return V_89 ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_91 ;
if ( V_2 -> V_18 != 3 || V_2 -> V_20 != 1 )
return V_100 ;
V_91 = V_2 -> V_6 -> V_358 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_152 ( struct V_1 * V_2 ,
void (* F_153)( struct V_1 * V_2 ,
struct V_177 * V_359 ) )
{
struct V_177 V_177 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_106 = 8 ;
F_153 ( V_2 , & V_177 ) ;
if ( V_2 -> V_106 == 2 ) {
V_2 -> V_106 = 4 ;
V_177 . V_105 &= 0x00ffffff ;
}
V_2 -> V_27 . type = V_201 ;
return F_66 ( V_2 , V_2 -> V_27 . V_77 . V_155 ,
& V_177 , 2 + V_2 -> V_106 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
return F_152 ( V_2 , V_2 -> V_6 -> V_182 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
return F_152 ( V_2 , V_2 -> V_6 -> V_179 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_177 V_177 ;
int V_91 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_106 = 8 ;
V_91 = F_44 ( V_2 , V_2 -> V_22 . V_77 . V_155 ,
& V_177 . V_72 , & V_177 . V_105 ,
V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_360 ( V_2 , & V_177 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = V_2 -> V_6 -> V_358 ( V_2 ) ;
V_2 -> V_27 . type = V_201 ;
return V_91 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_177 V_177 ;
int V_91 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_106 = 8 ;
V_91 = F_44 ( V_2 , V_2 -> V_22 . V_77 . V_155 ,
& V_177 . V_72 , & V_177 . V_105 ,
V_2 -> V_106 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_361 ( V_2 , & V_177 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_159 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_114 = V_2 -> V_6 -> V_118 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_160 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_316 ( V_2 , 0 , ( V_2 -> V_6 -> V_118 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_114 & 0x0f ) ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_161 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_3 ( V_2 , V_172 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_172 ) ) != 0 ) &&
( V_2 -> V_124 == 0xe2 || F_45 ( V_2 -> V_124 ^ 0x5 , V_2 -> V_173 ) ) )
F_18 ( V_2 , V_2 -> V_22 . V_114 ) ;
return V_89 ;
}
static int F_162 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , F_1 ( V_2 , V_172 ) ) == 0 )
F_18 ( V_2 , V_2 -> V_22 . V_114 ) ;
return V_89 ;
}
static int F_163 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 , V_2 -> V_27 . V_25 , V_2 -> V_22 . V_114 ,
& V_2 -> V_27 . V_114 ) )
return V_362 ;
return V_89 ;
}
static int F_164 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_363 ( V_2 , V_2 -> V_22 . V_25 , V_2 -> V_27 . V_114 ,
& V_2 -> V_22 . V_114 , 1 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_165 ( struct V_1 * V_2 )
{
if ( F_112 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_173 &= ~ V_111 ;
return V_89 ;
}
static int F_166 ( struct V_1 * V_2 )
{
if ( F_112 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_354 = V_364 ;
V_2 -> V_173 |= V_111 ;
return V_89 ;
}
static int F_167 ( struct V_1 * V_2 )
{
T_3 V_248 , V_249 , V_250 , V_251 ;
V_248 = F_1 ( V_2 , V_227 ) ;
V_250 = F_1 ( V_2 , V_172 ) ;
V_2 -> V_6 -> V_252 ( V_2 , & V_248 , & V_249 , & V_250 , & V_251 ) ;
* F_2 ( V_2 , V_227 ) = V_248 ;
* F_2 ( V_2 , V_146 ) = V_249 ;
* F_2 ( V_2 , V_172 ) = V_250 ;
* F_2 ( V_2 , V_244 ) = V_251 ;
return V_89 ;
}
static int F_168 ( struct V_1 * V_2 )
{
T_3 V_108 ;
V_108 = V_207 | V_208 | V_209 | V_210 | V_211 ;
V_108 &= * F_3 ( V_2 , V_227 ) >> 8 ;
V_2 -> V_173 &= ~ 0xffUL ;
V_2 -> V_173 |= V_108 | V_365 ;
return V_89 ;
}
static int F_169 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_227 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_227 ) |= ( V_2 -> V_173 & 0xff ) << 8 ;
return V_89 ;
}
static int F_170 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_106 ) {
#ifdef F_49
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_89 ;
}
static bool F_171 ( int V_3 )
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
static int F_172 ( struct V_1 * V_2 )
{
if ( ! F_171 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_115 V_366 = V_2 -> V_22 . V_23 ;
int V_367 = V_2 -> V_19 ;
V_115 V_265 = 0 ;
static V_115 V_368 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_369 ,
0 , 0 , 0 ,
V_370 ,
} ;
if ( ! F_171 ( V_367 ) )
return F_27 ( V_2 ) ;
if ( V_366 & V_368 [ V_367 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_367 ) {
case 0 : {
V_115 V_371 ;
if ( ( ( V_366 & V_372 ) && ! ( V_366 & V_373 ) ) ||
( ( V_366 & V_374 ) && ! ( V_366 & V_375 ) ) )
return F_25 ( V_2 , 0 ) ;
V_371 = V_2 -> V_6 -> V_118 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
if ( ( V_366 & V_372 ) && ( V_265 & V_376 ) &&
! ( V_371 & V_377 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_115 V_378 = 0 ;
V_2 -> V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
if ( V_265 & V_270 )
V_378 = V_379 ;
else if ( V_2 -> V_6 -> V_118 ( V_2 , 4 ) & V_377 )
V_378 = V_380 ;
else if ( V_2 -> V_6 -> V_118 ( V_2 , 0 ) & V_372 )
V_378 = V_381 ;
if ( V_366 & V_378 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
if ( ( V_265 & V_270 ) && ! ( V_366 & V_377 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_89 ;
}
static int F_174 ( struct V_1 * V_2 )
{
unsigned long V_382 ;
V_2 -> V_6 -> V_383 ( V_2 , 7 , & V_382 ) ;
return V_382 & ( 1 << 13 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_384 = V_2 -> V_19 ;
V_115 V_371 ;
if ( V_384 > 7 )
return F_27 ( V_2 ) ;
V_371 = V_2 -> V_6 -> V_118 ( V_2 , 4 ) ;
if ( ( V_371 & V_385 ) && ( V_384 == 4 || V_384 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_174 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_89 ;
}
static int F_176 ( struct V_1 * V_2 )
{
V_115 V_366 = V_2 -> V_22 . V_23 ;
int V_384 = V_2 -> V_19 ;
if ( ( V_384 == 6 || V_384 == 7 ) && ( V_366 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_175 ( V_2 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
V_115 V_265 ;
V_2 -> V_6 -> V_266 ( V_2 , V_267 , & V_265 ) ;
if ( ! ( V_265 & V_386 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_178 ( struct V_1 * V_2 )
{
V_115 V_387 = F_1 ( V_2 , V_227 ) ;
if ( V_387 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_177 ( V_2 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
V_115 V_371 = V_2 -> V_6 -> V_118 ( V_2 , 4 ) ;
if ( V_371 & V_388 && V_2 -> V_6 -> V_84 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_180 ( struct V_1 * V_2 )
{
V_115 V_371 = V_2 -> V_6 -> V_118 ( V_2 , 4 ) ;
V_115 V_389 = F_1 ( V_2 , V_172 ) ;
if ( ( ! ( V_371 & V_390 ) && V_2 -> V_6 -> V_84 ( V_2 ) ) ||
( V_389 > 3 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_181 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = F_39 ( V_2 -> V_27 . V_25 , 4u ) ;
if ( ! F_114 ( V_2 , V_2 -> V_22 . V_114 , V_2 -> V_27 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_25 = F_39 ( V_2 -> V_22 . V_25 , 4u ) ;
if ( ! F_114 ( V_2 , V_2 -> V_27 . V_114 , V_2 -> V_22 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static unsigned F_183 ( struct V_1 * V_2 )
{
unsigned V_72 ;
V_72 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
if ( V_72 == 8 )
V_72 = 4 ;
return V_72 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_112 * V_113 ,
unsigned V_72 , bool V_391 )
{
int V_91 = V_89 ;
V_113 -> type = V_341 ;
V_113 -> V_25 = V_72 ;
V_113 -> V_77 . V_155 . V_85 = V_2 -> V_44 ;
switch ( V_113 -> V_25 ) {
case 1 :
V_113 -> V_114 = F_60 ( V_152 , V_2 ) ;
break;
case 2 :
V_113 -> V_114 = F_60 ( V_158 , V_2 ) ;
break;
case 4 :
V_113 -> V_114 = F_60 ( V_153 , V_2 ) ;
break;
case 8 :
V_113 -> V_114 = F_60 ( V_392 , V_2 ) ;
break;
}
if ( ! V_391 ) {
switch ( V_113 -> V_25 ) {
case 1 :
V_113 -> V_114 &= 0xff ;
break;
case 2 :
V_113 -> V_114 &= 0xffff ;
break;
case 4 :
V_113 -> V_114 &= 0xffffffff ;
break;
}
}
V_156:
return V_91 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_112 * V_113 ,
unsigned V_40 )
{
int V_91 = V_89 ;
switch ( V_40 ) {
case V_393 :
F_57 ( V_2 , V_113 ) ;
break;
case V_394 :
V_91 = F_184 ( V_2 , V_113 , 1 , false ) ;
break;
case V_395 :
V_2 -> V_396 . V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_397:
* V_113 = V_2 -> V_396 ;
V_2 -> V_398 = V_113 ;
if ( ( V_2 -> V_40 & V_399 ) && V_113 == & V_2 -> V_27 )
F_62 ( V_2 ) ;
V_113 -> V_134 = V_113 -> V_114 ;
break;
case V_400 :
V_2 -> V_396 . V_25 = 8 ;
goto V_397;
case V_401 :
V_113 -> type = V_132 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_9 = F_3 ( V_2 , V_227 ) ;
F_47 ( V_113 ) ;
V_113 -> V_134 = V_113 -> V_114 ;
break;
case V_402 :
V_113 -> type = V_132 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 2 : V_2 -> V_106 ;
V_113 -> V_77 . V_9 = F_3 ( V_2 , V_227 ) ;
F_47 ( V_113 ) ;
V_113 -> V_134 = V_113 -> V_114 ;
break;
case V_403 :
if ( V_2 -> V_40 & V_133 ) {
V_113 -> type = V_201 ;
break;
}
V_113 -> type = V_132 ;
V_113 -> V_25 = V_2 -> V_106 ;
V_113 -> V_77 . V_9 = F_3 ( V_2 , V_244 ) ;
F_47 ( V_113 ) ;
V_113 -> V_134 = V_113 -> V_114 ;
break;
case V_404 :
V_113 -> type = V_144 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_155 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_151 ) ) ;
V_113 -> V_77 . V_155 . V_48 = V_297 ;
V_113 -> V_114 = 0 ;
V_113 -> V_171 = 1 ;
break;
case V_405 :
V_113 -> type = V_132 ;
V_113 -> V_25 = 2 ;
V_113 -> V_77 . V_9 = F_3 ( V_2 , V_244 ) ;
F_47 ( V_113 ) ;
break;
case V_406 :
V_113 -> V_25 = 1 ;
V_113 -> V_114 = F_1 ( V_2 , V_172 ) & 0xff ;
break;
case V_407 :
V_91 = F_184 ( V_2 , V_113 , 1 , true ) ;
break;
case V_408 :
V_113 -> V_25 = 1 ;
V_113 -> V_114 = 1 ;
break;
case V_409 :
V_91 = F_184 ( V_2 , V_113 , F_183 ( V_2 ) , true ) ;
break;
case V_410 :
V_91 = F_184 ( V_2 , V_113 , V_2 -> V_106 , true ) ;
break;
case V_411 :
V_2 -> V_396 . V_25 = 1 ;
if ( V_2 -> V_396 . type == V_132 ) {
V_2 -> V_396 . V_77 . V_9 = F_43 ( V_2 ,
V_2 -> V_20 , true ) ;
F_47 ( & V_2 -> V_396 ) ;
}
goto V_397;
case V_412 :
V_2 -> V_396 . V_25 = 2 ;
goto V_397;
case V_413 :
V_2 -> V_396 . V_25 = 4 ;
goto V_397;
case V_414 :
V_91 = F_184 ( V_2 , V_113 , 2 , false ) ;
break;
case V_415 :
V_91 = F_184 ( V_2 , V_113 , F_183 ( V_2 ) , false ) ;
break;
case V_416 :
V_113 -> type = V_144 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_155 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_149 ) ) ;
V_113 -> V_77 . V_155 . V_48 = V_50 ( V_2 ) ;
V_113 -> V_114 = 0 ;
V_113 -> V_171 = 1 ;
break;
case V_417 :
V_113 -> type = V_144 ;
V_113 -> V_25 = ( V_2 -> V_40 & V_133 ) ? 1 : V_2 -> V_106 ;
V_113 -> V_77 . V_155 . V_85 =
F_14 ( V_2 ,
F_1 ( V_2 , V_146 ) +
( F_1 ( V_2 , V_227 ) & 0xff ) ) ;
V_113 -> V_77 . V_155 . V_48 = V_50 ( V_2 ) ;
V_113 -> V_114 = 0 ;
break;
case V_418 :
V_113 -> type = V_341 ;
V_113 -> V_77 . V_155 . V_85 = V_2 -> V_44 ;
V_113 -> V_25 = V_2 -> V_106 + 2 ;
F_186 ( V_113 -> V_240 , V_113 -> V_25 , V_2 ) ;
break;
case V_419 :
V_2 -> V_396 . V_25 = V_2 -> V_106 + 2 ;
goto V_397;
case V_420 :
V_113 -> V_114 = V_297 ;
break;
case V_421 :
V_113 -> V_114 = V_97 ;
break;
case V_422 :
V_113 -> V_114 = V_39 ;
break;
case V_423 :
V_113 -> V_114 = V_143 ;
break;
case V_424 :
V_113 -> V_114 = V_51 ;
break;
case V_425 :
V_113 -> V_114 = V_194 ;
break;
case V_426 :
default:
V_113 -> type = V_201 ;
break;
}
V_156:
return V_91 ;
}
int F_187 ( struct V_1 * V_2 , void * V_427 , int V_428 )
{
int V_91 = V_89 ;
int V_36 = V_2 -> V_36 ;
int V_429 , V_430 , V_431 , V_432 ;
bool V_433 = false ;
struct V_434 V_434 ;
V_2 -> V_396 . type = V_201 ;
V_2 -> V_398 = NULL ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_79 . V_98 = V_2 -> V_44 ;
V_2 -> V_79 . V_96 = V_2 -> V_79 . V_98 + V_428 ;
V_2 -> V_435 = 1 ;
if ( V_428 > 0 )
memcpy ( V_2 -> V_79 . V_90 , V_427 , V_428 ) ;
switch ( V_36 ) {
case V_87 :
case V_195 :
case V_219 :
V_429 = V_430 = 2 ;
break;
case V_218 :
V_429 = V_430 = 4 ;
break;
#ifdef F_49
case V_37 :
V_429 = 4 ;
V_430 = 8 ;
break;
#endif
default:
return V_331 ;
}
V_2 -> V_106 = V_429 ;
V_2 -> V_28 = V_430 ;
for (; ; ) {
switch ( V_2 -> V_124 = F_60 ( T_4 , V_2 ) ) {
case 0x66 :
V_433 = true ;
V_2 -> V_106 = V_429 ^ 6 ;
break;
case 0x67 :
if ( V_36 == V_37 )
V_2 -> V_28 = V_430 ^ 12 ;
else
V_2 -> V_28 = V_430 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_21 ( V_2 , ( V_2 -> V_124 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_21 ( V_2 , V_2 -> V_124 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_36 != V_37 )
goto V_436;
V_2 -> V_104 = V_2 -> V_124 ;
continue;
case 0xf0 :
V_2 -> V_199 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_124 ;
break;
default:
goto V_436;
}
V_2 -> V_104 = 0 ;
}
V_436:
if ( V_2 -> V_104 & 8 )
V_2 -> V_106 = 8 ;
V_434 = V_437 [ V_2 -> V_124 ] ;
if ( V_2 -> V_124 == 0x0f ) {
V_2 -> V_435 = 2 ;
V_2 -> V_124 = F_60 ( T_4 , V_2 ) ;
V_434 = V_438 [ V_2 -> V_124 ] ;
if ( V_2 -> V_124 == 0x38 ) {
V_2 -> V_435 = 3 ;
V_2 -> V_124 = F_60 ( T_4 , V_2 ) ;
V_434 = V_439 [ V_2 -> V_124 ] ;
}
}
V_2 -> V_40 = V_434 . V_108 ;
if ( V_2 -> V_40 & V_123 )
V_2 -> V_142 = F_60 ( T_4 , V_2 ) ;
while ( V_2 -> V_40 & V_440 ) {
switch ( V_2 -> V_40 & V_440 ) {
case V_441 :
V_431 = ( V_2 -> V_142 >> 3 ) & 7 ;
V_434 = V_434 . V_442 . V_443 [ V_431 ] ;
break;
case V_444 :
V_431 = ( V_2 -> V_142 >> 3 ) & 7 ;
if ( ( V_2 -> V_142 >> 6 ) == 3 )
V_434 = V_434 . V_442 . V_445 -> V_446 [ V_431 ] ;
else
V_434 = V_434 . V_442 . V_445 -> V_447 [ V_431 ] ;
break;
case V_448 :
V_431 = V_2 -> V_142 & 7 ;
V_434 = V_434 . V_442 . V_443 [ V_431 ] ;
break;
case V_449 :
if ( V_2 -> V_17 && V_433 )
return V_331 ;
V_432 = V_433 ? 0x66 : V_2 -> V_17 ;
switch ( V_432 ) {
case 0x00 : V_434 = V_434 . V_442 . V_450 -> V_451 ; break;
case 0x66 : V_434 = V_434 . V_442 . V_450 -> V_452 ; break;
case 0xf2 : V_434 = V_434 . V_442 . V_450 -> V_453 ; break;
case 0xf3 : V_434 = V_434 . V_442 . V_450 -> V_454 ; break;
}
break;
case V_455 :
if ( V_2 -> V_142 > 0xbf )
V_434 = V_434 . V_442 . V_456 -> V_457 [ V_2 -> V_142 - 0xc0 ] ;
else
V_434 = V_434 . V_442 . V_456 -> V_113 [ ( V_2 -> V_142 >> 3 ) & 7 ] ;
break;
default:
return V_331 ;
}
V_2 -> V_40 &= ~ ( V_115 ) V_440 ;
V_2 -> V_40 |= V_434 . V_108 ;
}
V_2 -> V_458 = V_434 . V_442 . V_458 ;
V_2 -> V_459 = V_434 . V_459 ;
V_2 -> V_12 = V_434 . V_12 ;
if ( V_2 -> V_40 == 0 || ( V_2 -> V_40 & V_460 ) )
return V_331 ;
if ( ! ( V_2 -> V_40 & V_461 ) && V_2 -> V_462 )
return V_331 ;
if ( V_36 == V_37 && ( V_2 -> V_40 & V_463 ) )
V_2 -> V_106 = 8 ;
if ( V_2 -> V_40 & V_464 ) {
if ( V_36 == V_37 )
V_2 -> V_106 = 8 ;
else
V_2 -> V_106 = 4 ;
}
if ( V_2 -> V_40 & V_125 )
V_2 -> V_106 = 16 ;
else if ( V_2 -> V_40 & V_129 )
V_2 -> V_106 = 8 ;
if ( V_2 -> V_40 & V_123 ) {
V_91 = F_59 ( V_2 , & V_2 -> V_396 ) ;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_2 -> V_137 ) ;
} else if ( V_2 -> V_40 & V_465 )
V_91 = F_61 ( V_2 , & V_2 -> V_396 ) ;
if ( V_91 != V_89 )
goto V_156;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_143 ) ;
V_2 -> V_396 . V_77 . V_155 . V_48 = V_50 ( V_2 ) ;
if ( V_2 -> V_396 . type == V_144 && V_2 -> V_28 != 8 )
V_2 -> V_396 . V_77 . V_155 . V_85 = ( T_3 ) V_2 -> V_396 . V_77 . V_155 . V_85 ;
V_91 = F_185 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_40 >> V_466 ) & V_467 ) ;
if ( V_91 != V_89 )
goto V_156;
V_91 = F_185 ( V_2 , & V_2 -> V_224 , ( V_2 -> V_40 >> V_468 ) & V_467 ) ;
if ( V_91 != V_89 )
goto V_156;
V_91 = F_185 ( V_2 , & V_2 -> V_27 , ( V_2 -> V_40 >> V_469 ) & V_467 ) ;
V_156:
if ( V_2 -> V_398 && V_2 -> V_398 -> type == V_144 && V_2 -> V_154 )
V_2 -> V_398 -> V_77 . V_155 . V_85 += V_2 -> V_44 ;
return ( V_91 != V_89 ) ? V_331 : V_332 ;
}
bool F_188 ( struct V_1 * V_2 )
{
return V_2 -> V_40 & V_470 ;
}
static bool F_189 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_124 == 0xa6 ) || ( V_2 -> V_124 == 0xa7 ) ||
( V_2 -> V_124 == 0xae ) || ( V_2 -> V_124 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_471 ) &&
( ( V_2 -> V_173 & V_210 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_472 ) &&
( ( V_2 -> V_173 & V_210 ) == V_210 ) ) ) )
return true ;
return false ;
}
static int F_190 ( struct V_1 * V_2 )
{
bool V_473 = false ;
V_2 -> V_6 -> V_116 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_117 ( V_2 ) ;
if ( F_41 ( V_473 ) )
return F_23 ( V_2 , V_474 , 0 , false ) ;
return V_89 ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
if ( V_113 -> type == V_130 )
F_52 ( V_2 , & V_113 -> V_200 , V_113 -> V_77 . V_131 ) ;
}
static int F_104 ( struct V_1 * V_2 , void (* F_46)( struct F_104 * ) )
{
T_1 V_108 = ( V_2 -> V_173 & V_110 ) | V_111 ;
if ( ! ( V_2 -> V_40 & V_133 ) )
F_46 += F_192 ( V_2 -> V_27 . V_25 ) * V_475 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_173 = ( V_2 -> V_173 & ~ V_110 ) | ( V_108 & V_110 ) ;
if ( ! F_46 )
return F_29 ( V_2 ) ;
return V_89 ;
}
int F_193 ( struct V_1 * V_2 )
{
const struct V_180 * V_6 = V_2 -> V_6 ;
int V_91 = V_89 ;
int V_476 = V_2 -> V_27 . type ;
V_2 -> V_161 . V_162 = 0 ;
if ( ( V_2 -> V_36 == V_37 && ( V_2 -> V_40 & V_477 ) ) ||
( V_2 -> V_40 & V_478 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_156;
}
if ( V_2 -> V_199 && ( ! ( V_2 -> V_40 & V_479 ) || V_2 -> V_27 . type != V_144 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_156;
}
if ( ( V_2 -> V_40 & V_480 ) == V_481 && V_2 -> V_22 . type != V_144 ) {
V_91 = F_27 ( V_2 ) ;
goto V_156;
}
if ( ( ( V_2 -> V_40 & ( V_125 | V_129 ) ) && ( ( V_6 -> V_118 ( V_2 , 0 ) & V_120 ) ) )
|| ( ( V_2 -> V_40 & V_125 ) && ! ( V_6 -> V_118 ( V_2 , 4 ) & V_482 ) ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_156;
}
if ( ( V_2 -> V_40 & ( V_125 | V_129 ) ) && ( V_6 -> V_118 ( V_2 , 0 ) & V_119 ) ) {
V_91 = F_30 ( V_2 ) ;
goto V_156;
}
if ( V_2 -> V_40 & V_129 ) {
V_91 = F_190 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_156;
F_191 ( V_2 , & V_2 -> V_22 ) ;
F_191 ( V_2 , & V_2 -> V_224 ) ;
if ( ! ( V_2 -> V_40 & V_483 ) )
F_191 ( V_2 , & V_2 -> V_27 ) ;
}
if ( F_41 ( V_2 -> V_484 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_485 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( ( V_2 -> V_40 & V_486 ) && V_6 -> V_84 ( V_2 ) ) {
V_91 = F_25 ( V_2 , 0 ) ;
goto V_156;
}
if ( ( V_2 -> V_40 & V_487 ) && V_2 -> V_36 < V_219 ) {
V_91 = F_27 ( V_2 ) ;
goto V_156;
}
if ( V_2 -> V_459 ) {
V_91 = V_2 -> V_459 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( F_41 ( V_2 -> V_484 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_488 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_172 ) ) == 0 ) {
V_2 -> V_30 = V_2 -> V_44 ;
goto V_156;
}
}
if ( ( V_2 -> V_22 . type == V_144 ) && ! ( V_2 -> V_40 & V_489 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_22 . V_77 . V_155 ,
V_2 -> V_22 . V_240 , V_2 -> V_22 . V_25 ) ;
if ( V_91 != V_89 )
goto V_156;
V_2 -> V_22 . V_243 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_224 . type == V_144 ) {
V_91 = F_65 ( V_2 , V_2 -> V_224 . V_77 . V_155 ,
& V_2 -> V_224 . V_114 , V_2 -> V_224 . V_25 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( ( V_2 -> V_40 & V_490 ) == V_491 )
goto V_492;
if ( ( V_2 -> V_27 . type == V_144 ) && ! ( V_2 -> V_40 & V_483 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_27 . V_77 . V_155 ,
& V_2 -> V_27 . V_114 , V_2 -> V_27 . V_25 ) ;
if ( V_91 != V_89 )
goto V_156;
}
V_2 -> V_27 . V_134 = V_2 -> V_27 . V_114 ;
V_492:
if ( F_41 ( V_2 -> V_484 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_493 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( V_2 -> V_458 ) {
if ( V_2 -> V_40 & V_494 ) {
void (* F_46)( struct F_104 * ) = ( void * ) V_2 -> V_458 ;
V_91 = F_104 ( V_2 , F_46 ) ;
if ( V_91 != V_89 )
goto V_156;
goto F_78;
}
V_91 = V_2 -> V_458 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_156;
goto F_78;
}
if ( V_2 -> V_435 == 2 )
goto V_495;
else if ( V_2 -> V_435 == 3 )
goto V_496;
switch ( V_2 -> V_124 ) {
case 0x63 :
if ( V_2 -> V_36 != V_37 )
goto V_497;
V_2 -> V_27 . V_114 = ( V_153 ) V_2 -> V_22 . V_114 ;
break;
case 0x70 ... 0x7f :
if ( F_45 ( V_2 -> V_124 , V_2 -> V_173 ) )
F_18 ( V_2 , V_2 -> V_22 . V_114 ) ;
break;
case 0x8d :
V_2 -> V_27 . V_114 = V_2 -> V_22 . V_77 . V_155 . V_85 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_27 . V_77 . V_9 == F_3 ( V_2 , V_227 ) )
break;
V_91 = F_130 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_106 ) {
case 2 : V_2 -> V_27 . V_114 = ( V_152 ) V_2 -> V_27 . V_114 ; break;
case 4 : V_2 -> V_27 . V_114 = ( V_158 ) V_2 -> V_27 . V_114 ; break;
case 8 : V_2 -> V_27 . V_114 = ( V_153 ) V_2 -> V_27 . V_114 ; break;
}
break;
case 0xcc :
V_91 = F_94 ( V_2 , 3 ) ;
break;
case 0xcd :
V_91 = F_94 ( V_2 , V_2 -> V_22 . V_114 ) ;
break;
case 0xce :
if ( V_2 -> V_173 & V_212 )
V_91 = F_94 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
F_18 ( V_2 , V_2 -> V_22 . V_114 ) ;
V_2 -> V_27 . type = V_201 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_498 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_173 ^= V_207 ;
break;
case 0xf8 :
V_2 -> V_173 &= ~ V_207 ;
break;
case 0xf9 :
V_2 -> V_173 |= V_207 ;
break;
case 0xfc :
V_2 -> V_173 &= ~ V_174 ;
break;
case 0xfd :
V_2 -> V_173 |= V_174 ;
break;
default:
goto V_497;
}
if ( V_91 != V_89 )
goto V_156;
F_78:
if ( ! ( V_2 -> V_40 & V_499 ) ) {
V_91 = F_78 ( V_2 , & V_2 -> V_27 ) ;
if ( V_91 != V_89 )
goto V_156;
}
if ( V_2 -> V_40 & V_500 ) {
F_194 ( V_2 -> V_22 . type == V_144 || V_2 -> V_22 . type == V_175 ) ;
V_91 = F_78 ( V_2 , & V_2 -> V_22 ) ;
if ( V_91 != V_89 )
goto V_156;
}
V_2 -> V_27 . type = V_476 ;
if ( ( V_2 -> V_40 & V_480 ) == V_501 )
F_123 ( V_2 , V_149 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_40 & V_490 ) == V_502 )
F_123 ( V_2 , V_151 , & V_2 -> V_27 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
unsigned int V_171 ;
struct V_159 * V_281 = & V_2 -> V_168 ;
if ( ( V_2 -> V_40 & V_480 ) == V_501 )
V_171 = V_2 -> V_22 . V_171 ;
else
V_171 = V_2 -> V_27 . V_171 ;
F_16 ( V_2 , F_3 ( V_2 , V_172 ) ,
- V_171 ) ;
if ( ! F_189 ( V_2 ) ) {
if ( ( V_281 -> V_96 != 0 || F_1 ( V_2 , V_172 ) & 0x3ff ) &&
( V_281 -> V_96 == 0 || V_281 -> V_96 != V_281 -> V_162 ) ) {
V_2 -> V_161 . V_96 = 0 ;
F_4 ( V_2 ) ;
return V_503 ;
}
goto V_156;
}
}
V_2 -> V_30 = V_2 -> V_44 ;
V_156:
if ( V_91 == V_59 )
V_2 -> V_504 = true ;
if ( V_91 == V_505 )
return V_506 ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return ( V_91 == V_100 ) ? V_331 : V_332 ;
V_495:
switch ( V_2 -> V_124 ) {
case 0x09 :
( V_2 -> V_6 -> V_507 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_27 . V_114 = V_6 -> V_118 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_383 ( V_2 , V_2 -> V_19 , & V_2 -> V_27 . V_114 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_27 . V_114 = V_2 -> V_27 . V_134 = V_2 -> V_22 . V_114 ;
if ( ! F_45 ( V_2 -> V_124 , V_2 -> V_173 ) )
V_2 -> V_27 . type = V_201 ;
break;
case 0x80 ... 0x8f :
if ( F_45 ( V_2 -> V_124 , V_2 -> V_173 ) )
F_18 ( V_2 , V_2 -> V_22 . V_114 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_27 . V_114 = F_45 ( V_2 -> V_124 , V_2 -> V_173 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
V_2 -> V_27 . V_114 = ( V_2 -> V_22 . V_25 == 1 ) ? ( T_4 ) V_2 -> V_22 . V_114
: ( T_2 ) V_2 -> V_22 . V_114 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
V_2 -> V_27 . V_114 = ( V_2 -> V_22 . V_25 == 1 ) ? ( V_152 ) V_2 -> V_22 . V_114 :
( V_158 ) V_2 -> V_22 . V_114 ;
break;
case 0xc3 :
V_2 -> V_27 . V_25 = V_2 -> V_106 ;
V_2 -> V_27 . V_114 = ( V_2 -> V_106 == 4 ) ? ( T_3 ) V_2 -> V_22 . V_114 :
( V_115 ) V_2 -> V_22 . V_114 ;
break;
default:
goto V_497;
}
V_496:
if ( V_91 != V_89 )
goto V_156;
goto F_78;
V_497:
return V_331 ;
}
void F_195 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_196 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
