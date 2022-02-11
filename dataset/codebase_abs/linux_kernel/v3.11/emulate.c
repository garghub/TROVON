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
if ( V_101 && V_19 >= 4 && V_19 < 8 )
V_102 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_102 = F_3 ( V_2 , V_19 ) ;
return V_102 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
T_2 * V_72 , unsigned long * V_103 , int V_104 )
{
int V_91 ;
if ( V_104 == 2 )
V_104 = 3 ;
* V_103 = 0 ;
V_91 = F_37 ( V_2 , V_77 , V_72 , 2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_77 . V_85 += 2 ;
V_91 = F_37 ( V_2 , V_77 , V_103 , V_104 ) ;
return V_91 ;
}
static T_4 F_45 ( unsigned int V_105 , unsigned long V_106 )
{
T_4 V_91 ;
void (* F_46)( void ) = ( void * ) V_107 + 4 * ( V_105 & 0xf ) ;
V_106 = ( V_106 & V_108 ) | V_109 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_91 ;
}
static void F_47 ( struct V_110 * V_111 )
{
switch ( V_111 -> V_25 ) {
case 1 :
V_111 -> V_112 = * ( T_4 * ) V_111 -> V_77 . V_9 ;
break;
case 2 :
V_111 -> V_112 = * ( T_2 * ) V_111 -> V_77 . V_9 ;
break;
case 4 :
V_111 -> V_112 = * ( T_3 * ) V_111 -> V_77 . V_9 ;
break;
case 8 :
V_111 -> V_112 = * ( V_113 * ) V_111 -> V_77 . V_9 ;
break;
}
}
static void F_48 ( struct V_1 * V_2 , T_5 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_114 ( V_2 ) ;
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
V_2 -> V_6 -> V_115 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_5 * V_90 ,
int V_9 )
{
V_2 -> V_6 -> V_114 ( V_2 ) ;
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
V_2 -> V_6 -> V_115 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , V_113 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_114 ( V_2 ) ;
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
V_2 -> V_6 -> V_115 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , V_113 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_114 ( V_2 ) ;
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
V_2 -> V_6 -> V_115 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & ( V_117 | V_118 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_114 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_115 ( V_2 ) ;
return V_89 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_2 V_119 ;
if ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & ( V_117 | V_118 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_114 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_115 ( V_2 ) ;
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_112 = V_119 ;
return V_89 ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_2 V_120 ;
if ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & ( V_117 | V_118 ) )
return F_30 ( V_2 ) ;
V_2 -> V_6 -> V_114 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_115 ( V_2 ) ;
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_112 = V_120 ;
return V_89 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
unsigned V_9 = V_2 -> V_19 ;
int V_101 = V_2 -> V_121 == 0 ;
if ( ! ( V_2 -> V_40 & V_122 ) )
V_9 = ( V_2 -> V_123 & 7 ) | ( ( V_2 -> V_121 & 1 ) << 3 ) ;
if ( V_2 -> V_40 & V_124 ) {
V_111 -> type = V_125 ;
V_111 -> V_25 = 16 ;
V_111 -> V_77 . V_126 = V_9 ;
F_48 ( V_2 , & V_111 -> V_127 , V_9 ) ;
return;
}
if ( V_2 -> V_40 & V_128 ) {
V_9 &= 7 ;
V_111 -> type = V_129 ;
V_111 -> V_25 = 8 ;
V_111 -> V_77 . V_130 = V_9 ;
return;
}
V_111 -> type = V_131 ;
if ( V_2 -> V_40 & V_132 ) {
V_111 -> V_77 . V_9 = F_43 ( V_2 , V_9 , V_101 ) ;
V_111 -> V_25 = 1 ;
} else {
V_111 -> V_77 . V_9 = F_43 ( V_2 , V_9 , 0 ) ;
V_111 -> V_25 = V_2 -> V_104 ;
}
F_47 ( V_111 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
}
static void F_58 ( struct V_1 * V_2 , int V_134 )
{
if ( V_134 == V_42 || V_134 == V_135 )
V_2 -> V_136 = V_39 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
T_4 V_137 ;
int V_138 = 0 , V_134 = 0 , V_139 ;
int V_91 = V_89 ;
T_1 V_140 = 0 ;
if ( V_2 -> V_121 ) {
V_2 -> V_19 = ( V_2 -> V_121 & 4 ) << 1 ;
V_138 = ( V_2 -> V_121 & 2 ) << 2 ;
V_2 -> V_20 = V_134 = ( V_2 -> V_121 & 1 ) << 3 ;
}
V_2 -> V_18 |= ( V_2 -> V_141 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_141 & 0x38 ) >> 3 ;
V_2 -> V_20 |= ( V_2 -> V_141 & 0x07 ) ;
V_2 -> V_136 = V_142 ;
if ( V_2 -> V_18 == 3 ) {
int V_101 = V_2 -> V_121 == 0 ;
V_111 -> type = V_131 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_43 ( V_2 , V_2 -> V_20 ,
V_101 && ( V_2 -> V_40 & V_132 ) ) ;
if ( V_2 -> V_40 & V_124 ) {
V_111 -> type = V_125 ;
V_111 -> V_25 = 16 ;
V_111 -> V_77 . V_126 = V_2 -> V_20 ;
F_48 ( V_2 , & V_111 -> V_127 , V_2 -> V_20 ) ;
return V_91 ;
}
if ( V_2 -> V_40 & V_128 ) {
V_111 -> type = V_129 ;
V_111 -> V_25 = 8 ;
V_111 -> V_77 . V_126 = V_2 -> V_20 & 7 ;
return V_91 ;
}
F_47 ( V_111 ) ;
return V_91 ;
}
V_111 -> type = V_143 ;
if ( V_2 -> V_28 == 2 ) {
unsigned V_144 = F_1 ( V_2 , V_145 ) ;
unsigned V_146 = F_1 ( V_2 , V_135 ) ;
unsigned V_147 = F_1 ( V_2 , V_148 ) ;
unsigned V_149 = F_1 ( V_2 , V_150 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_140 += F_60 ( T_2 , V_2 ) ;
break;
case 1 :
V_140 += F_60 ( V_151 , V_2 ) ;
break;
case 2 :
V_140 += F_60 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_140 += V_144 + V_147 ;
break;
case 1 :
V_140 += V_144 + V_149 ;
break;
case 2 :
V_140 += V_146 + V_147 ;
break;
case 3 :
V_140 += V_146 + V_149 ;
break;
case 4 :
V_140 += V_147 ;
break;
case 5 :
V_140 += V_149 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_140 += V_146 ;
break;
case 7 :
V_140 += V_144 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_136 = V_39 ;
V_140 = ( T_2 ) V_140 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_137 = F_60 ( T_4 , V_2 ) ;
V_138 |= ( V_137 >> 3 ) & 7 ;
V_134 |= V_137 & 7 ;
V_139 = V_137 >> 6 ;
if ( ( V_134 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_140 += F_60 ( V_152 , V_2 ) ;
else {
V_140 += F_1 ( V_2 , V_134 ) ;
F_58 ( V_2 , V_134 ) ;
}
if ( V_138 != 4 )
V_140 += F_1 ( V_2 , V_138 ) << V_139 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
if ( V_2 -> V_36 == V_37 )
V_2 -> V_153 = 1 ;
} else {
V_134 = V_2 -> V_20 ;
V_140 += F_1 ( V_2 , V_134 ) ;
F_58 ( V_2 , V_134 ) ;
}
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 5 )
V_140 += F_60 ( V_152 , V_2 ) ;
break;
case 1 :
V_140 += F_60 ( V_151 , V_2 ) ;
break;
case 2 :
V_140 += F_60 ( V_152 , V_2 ) ;
break;
}
}
V_111 -> V_77 . V_154 . V_85 = V_140 ;
V_155:
return V_91 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
int V_91 = V_89 ;
V_111 -> type = V_143 ;
switch ( V_2 -> V_28 ) {
case 2 :
V_111 -> V_77 . V_154 . V_85 = F_60 ( T_2 , V_2 ) ;
break;
case 4 :
V_111 -> V_77 . V_154 . V_85 = F_60 ( T_3 , V_2 ) ;
break;
case 8 :
V_111 -> V_77 . V_154 . V_85 = F_60 ( V_113 , V_2 ) ;
break;
}
V_155:
return V_91 ;
}
static void F_62 ( struct V_1 * V_2 )
{
long V_156 = 0 , V_32 ;
if ( V_2 -> V_27 . type == V_143 && V_2 -> V_22 . type == V_131 ) {
V_32 = ~ ( V_2 -> V_27 . V_25 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_25 == 2 )
V_156 = ( V_157 ) V_2 -> V_22 . V_112 & ( V_157 ) V_32 ;
else if ( V_2 -> V_22 . V_25 == 4 )
V_156 = ( V_152 ) V_2 -> V_22 . V_112 & ( V_152 ) V_32 ;
V_2 -> V_27 . V_77 . V_154 . V_85 += ( V_156 >> 3 ) ;
}
V_2 -> V_22 . V_112 &= ( V_2 -> V_27 . V_25 << 3 ) - 1 ;
}
static int F_63 ( struct V_1 * V_2 ,
unsigned long V_77 , void * V_31 , unsigned V_72 )
{
int V_91 ;
struct V_158 * V_159 = & V_2 -> V_160 ;
if ( V_159 -> V_161 < V_159 -> V_96 )
goto V_162;
F_64 ( ( V_159 -> V_96 + V_72 ) >= sizeof( V_159 -> V_90 ) ) ;
V_91 = V_2 -> V_6 -> F_63 ( V_2 , V_77 , V_159 -> V_90 + V_159 -> V_96 , V_72 ,
& V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_159 -> V_96 += V_72 ;
V_162:
memcpy ( V_31 , V_159 -> V_90 + V_159 -> V_161 , V_72 ) ;
V_159 -> V_161 += V_72 ;
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
return V_2 -> V_6 -> V_163 ( V_2 , V_80 , V_90 , V_72 ,
& V_2 -> V_55 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
const void * V_164 , const void * V_90 ,
unsigned V_72 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_77 , V_72 , true , & V_80 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_165 ( V_2 , V_80 , V_164 , V_90 ,
V_72 , & V_2 -> V_55 ) ;
}
static int F_68 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned short V_166 ,
void * V_31 )
{
struct V_158 * V_91 = & V_2 -> V_167 ;
if ( V_91 -> V_161 == V_91 -> V_96 ) {
unsigned int V_168 , V_169 ;
unsigned int V_170 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) : 1 ;
V_168 = ( V_2 -> V_172 & V_173 ) ?
F_40 ( F_1 ( V_2 , V_150 ) ) :
V_99 - F_40 ( F_1 ( V_2 , V_150 ) ) ;
V_169 = F_39 ( F_39 ( V_168 , ( unsigned int ) sizeof( V_91 -> V_90 ) ) / V_72 ,
V_170 ) ;
if ( V_169 == 0 )
V_169 = 1 ;
V_91 -> V_161 = V_91 -> V_96 = 0 ;
if ( ! V_2 -> V_6 -> F_68 ( V_2 , V_72 , V_166 , V_91 -> V_90 , V_169 ) )
return 0 ;
V_91 -> V_96 = V_169 * V_72 ;
}
if ( V_2 -> V_17 && ! ( V_2 -> V_172 & V_173 ) ) {
V_2 -> V_27 . V_90 = V_91 -> V_90 + V_91 -> V_161 ;
V_2 -> V_27 . type = V_174 ;
V_2 -> V_27 . V_170 = ( V_91 -> V_96 - V_91 -> V_161 ) / V_72 ;
V_91 -> V_161 = V_91 -> V_96 ;
} else {
memcpy ( V_31 , V_91 -> V_90 + V_91 -> V_161 , V_72 ) ;
V_91 -> V_161 += V_72 ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_2 V_175 , struct V_34 * V_45 )
{
struct V_176 V_177 ;
T_1 V_77 ;
V_2 -> V_6 -> V_178 ( V_2 , & V_177 ) ;
if ( V_177 . V_72 < V_175 * 8 + 7 )
return F_25 ( V_2 , V_175 << 3 | 0x2 ) ;
V_77 = V_177 . V_103 + V_175 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_176 * V_177 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
if ( V_68 & 1 << 2 ) {
struct V_34 V_45 ;
T_2 V_33 ;
memset ( V_177 , 0 , sizeof *V_177 ) ;
if ( ! V_6 -> V_38 ( V_2 , & V_33 , & V_45 , NULL , V_180 ) )
return;
V_177 -> V_72 = F_19 ( & V_45 ) ;
V_177 -> V_103 = F_71 ( & V_45 ) ;
} else
V_6 -> V_181 ( V_2 , V_177 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 ,
T_1 * V_182 )
{
struct V_176 V_177 ;
T_2 V_175 = V_68 >> 3 ;
T_1 V_77 ;
F_70 ( V_2 , V_68 , & V_177 ) ;
if ( V_177 . V_72 < V_175 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
* V_182 = V_77 = V_177 . V_103 + V_175 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 )
{
struct V_176 V_177 ;
T_2 V_175 = V_68 >> 3 ;
T_1 V_77 ;
F_70 ( V_2 , V_68 , & V_177 ) ;
if ( V_177 . V_72 < V_175 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
V_77 = V_177 . V_103 + V_175 * 8 ;
return V_2 -> V_6 -> V_183 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
T_2 V_68 , int V_48 )
{
struct V_34 V_184 , V_185 ;
T_4 V_88 , V_186 , V_84 ;
unsigned V_187 = V_62 ;
T_3 V_188 = 0 ;
bool V_189 = ! ( V_68 & ~ 0x3 ) ;
T_1 V_190 ;
int V_191 ;
T_2 V_69 ;
memset ( & V_184 , 0 , sizeof V_184 ) ;
if ( V_2 -> V_36 == V_87 ) {
V_2 -> V_6 -> V_38 ( V_2 , & V_69 , & V_184 , NULL , V_48 ) ;
F_75 ( & V_184 , V_68 << 4 ) ;
goto V_192;
} else if ( V_48 <= V_193 && V_2 -> V_36 == V_194 ) {
F_75 ( & V_184 , V_68 << 4 ) ;
F_76 ( & V_184 , 0xffff ) ;
V_184 . type = 3 ;
V_184 . V_102 = 1 ;
V_184 . V_195 = 1 ;
V_184 . V_88 = 3 ;
goto V_192;
}
V_186 = V_68 & 3 ;
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( ( V_48 == V_97
|| ( V_48 == V_39
&& ( V_2 -> V_36 != V_37 || V_186 != V_84 ) )
|| V_48 == V_196 )
&& V_189 )
goto V_55;
if ( V_48 == V_196 && ( V_68 & ( 1 << 2 ) ) )
goto V_55;
if ( V_189 )
goto V_192;
V_191 = F_72 ( V_2 , V_68 , & V_184 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_188 = V_68 & 0xfffc ;
V_187 = V_62 ;
if ( V_48 <= V_193 && ! V_184 . V_195 )
goto V_55;
if ( ! V_184 . V_102 ) {
V_187 = ( V_48 == V_39 ) ? V_63 : V_197 ;
goto V_55;
}
V_88 = V_184 . V_88 ;
switch ( V_48 ) {
case V_39 :
if ( V_186 != V_84 || ( V_184 . type & 0xa ) != 0x2 || V_88 != V_84 )
goto V_55;
break;
case V_97 :
if ( ! ( V_184 . type & 8 ) )
goto V_55;
if ( V_184 . type & 4 ) {
if ( V_88 > V_84 )
goto V_55;
} else {
if ( V_186 > V_84 || V_88 != V_84 )
goto V_55;
}
V_68 = ( V_68 & 0xfffc ) | V_84 ;
break;
case V_196 :
if ( V_184 . V_195 || ( V_184 . type != 1 && V_184 . type != 9 ) )
goto V_55;
V_185 = V_184 ;
V_184 . type |= 2 ;
V_191 = V_2 -> V_6 -> V_165 ( V_2 , V_190 , & V_185 , & V_184 ,
sizeof( V_184 ) , & V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
break;
case V_180 :
if ( V_184 . V_195 || V_184 . type != 2 )
goto V_55;
break;
default:
if ( ( V_184 . type & 0xa ) == 0x8 ||
( ( ( V_184 . type & 0xc ) != 0xc ) &&
( V_186 > V_88 && V_84 > V_88 ) ) )
goto V_55;
break;
}
if ( V_184 . V_195 ) {
V_184 . type |= 1 ;
V_191 = F_73 ( V_2 , V_68 , & V_184 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
V_192:
V_2 -> V_6 -> V_71 ( V_2 , V_68 , & V_184 , 0 , V_48 ) ;
return V_89 ;
V_55:
F_23 ( V_2 , V_187 , V_188 , true ) ;
return V_59 ;
}
static void F_77 ( struct V_110 * V_111 )
{
switch ( V_111 -> V_25 ) {
case 1 :
* ( T_4 * ) V_111 -> V_77 . V_9 = ( T_4 ) V_111 -> V_112 ;
break;
case 2 :
* ( T_2 * ) V_111 -> V_77 . V_9 = ( T_2 ) V_111 -> V_112 ;
break;
case 4 :
* V_111 -> V_77 . V_9 = ( T_3 ) V_111 -> V_112 ;
break;
case 8 :
* V_111 -> V_77 . V_9 = V_111 -> V_112 ;
break;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_110 * V_111 )
{
int V_91 ;
switch ( V_111 -> type ) {
case V_131 :
F_77 ( V_111 ) ;
break;
case V_143 :
if ( V_2 -> V_198 )
V_91 = F_67 ( V_2 ,
V_111 -> V_77 . V_154 ,
& V_111 -> V_133 ,
& V_111 -> V_112 ,
V_111 -> V_25 ) ;
else
V_91 = F_66 ( V_2 ,
V_111 -> V_77 . V_154 ,
& V_111 -> V_112 ,
V_111 -> V_25 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_174 :
V_91 = F_66 ( V_2 ,
V_111 -> V_77 . V_154 ,
V_111 -> V_90 ,
V_111 -> V_25 * V_111 -> V_170 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_125 :
F_51 ( V_2 , & V_111 -> V_127 , V_111 -> V_77 . V_126 ) ;
break;
case V_129 :
F_53 ( V_2 , & V_111 -> V_199 , V_111 -> V_77 . V_130 ) ;
break;
case V_200 :
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
V_2 -> V_27 . type = V_200 ;
return F_79 ( V_2 , & V_2 -> V_22 . V_112 , V_2 -> V_104 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
void * V_31 , int V_201 )
{
int V_91 ;
struct V_76 V_77 ;
V_77 . V_85 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
V_91 = F_65 ( V_2 , V_77 , V_31 , V_201 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_201 ) ;
return V_91 ;
}
static int F_82 ( struct V_1 * V_2 )
{
return F_81 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
void * V_31 , int V_201 )
{
int V_91 ;
unsigned long V_112 , V_202 ;
int V_203 = ( V_2 -> V_172 & V_204 ) >> V_205 ;
int V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
V_91 = F_81 ( V_2 , & V_112 , V_201 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_202 = V_206 | V_207 | V_208 | V_209 | V_210 | V_211
| V_212 | V_173 | V_213 | V_214 | V_215 | V_216 ;
switch( V_2 -> V_36 ) {
case V_37 :
case V_217 :
case V_218 :
if ( V_84 == 0 )
V_202 |= V_219 ;
if ( V_84 <= V_203 )
V_202 |= V_220 ;
break;
case V_194 :
if ( V_203 < 3 )
return F_25 ( V_2 , 0 ) ;
V_202 |= V_220 ;
break;
default:
V_202 |= ( V_219 | V_220 ) ;
break;
}
* ( unsigned long * ) V_31 =
( V_2 -> V_172 & ~ V_202 ) | ( V_112 & V_202 ) ;
return V_91 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_172 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
return F_83 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned V_221 = V_2 -> V_22 . V_112 ;
unsigned V_222 = V_2 -> V_223 . V_112 & 31 ;
T_1 V_224 ;
if ( V_222 )
return V_100 ;
V_224 = F_1 ( V_2 , V_135 ) ;
V_91 = F_79 ( V_2 , & V_224 , F_11 ( V_2 ) ) ;
if ( V_91 != V_89 )
return V_91 ;
F_8 ( F_3 ( V_2 , V_135 ) , F_1 ( V_2 , V_42 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_42 ) ,
F_1 ( V_2 , V_42 ) - V_221 ,
F_10 ( V_2 ) ) ;
return V_89 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_42 ) , F_1 ( V_2 , V_135 ) ,
F_10 ( V_2 ) ) ;
return F_81 ( V_2 , F_3 ( V_2 , V_135 ) , V_2 -> V_104 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_223 . V_112 ;
V_2 -> V_22 . V_112 = F_31 ( V_2 , V_48 ) ;
return F_80 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_223 . V_112 ;
unsigned long V_68 ;
int V_91 ;
V_91 = F_81 ( V_2 , & V_68 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_68 , V_48 ) ;
return V_91 ;
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned long V_225 = F_1 ( V_2 , V_42 ) ;
int V_91 = V_89 ;
int V_9 = V_226 ;
while ( V_9 <= V_150 ) {
( V_9 == V_42 ) ?
( V_2 -> V_22 . V_112 = V_225 ) : ( V_2 -> V_22 . V_112 = F_1 ( V_2 , V_9 ) ) ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
++ V_9 ;
}
return V_91 ;
}
static int F_90 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_112 = ( unsigned long ) V_2 -> V_172 ;
return F_80 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
int V_9 = V_150 ;
while ( V_9 >= V_226 ) {
if ( V_9 == V_42 ) {
F_17 ( V_2 , V_2 -> V_104 ) ;
-- V_9 ;
}
V_91 = F_81 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
break;
-- V_9 ;
}
return V_91 ;
}
static int F_92 ( struct V_1 * V_2 , int V_227 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
int V_91 ;
struct V_176 V_177 ;
T_6 V_228 ;
T_6 V_229 ;
T_2 V_230 , V_30 ;
V_2 -> V_22 . V_112 = V_2 -> V_172 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_172 &= ~ ( V_220 | V_212 | V_215 ) ;
V_2 -> V_22 . V_112 = F_31 ( V_2 , V_97 ) ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_112 = V_2 -> V_44 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_6 -> V_178 ( V_2 , & V_177 ) ;
V_229 = V_177 . V_103 + ( V_227 << 2 ) ;
V_228 = V_177 . V_103 + ( V_227 << 2 ) + 2 ;
V_91 = V_6 -> V_92 ( V_2 , V_228 , & V_230 , 2 , & V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = V_6 -> V_92 ( V_2 , V_229 , & V_30 , 2 , & V_2 -> V_55 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , V_230 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_30 ;
return V_91 ;
}
int F_93 ( struct V_1 * V_2 , int V_227 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_91 = F_92 ( V_2 , V_227 ) ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return V_91 ;
}
static int F_94 ( struct V_1 * V_2 , int V_227 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_92 ( V_2 , V_227 ) ;
case V_194 :
case V_218 :
case V_217 :
case V_37 :
default:
return V_100 ;
}
}
static int F_95 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
unsigned long V_231 = 0 ;
unsigned long V_232 = 0 ;
unsigned long V_230 = 0 ;
unsigned long V_32 = V_206 | V_207 | V_208 | V_209 | V_210 | V_212 |
V_220 | V_173 | V_211 | V_219 | V_213 | V_214 |
V_215 | V_216 | ( 1 << 1 ) ;
unsigned long V_233 = V_234 | V_235 | V_236 ;
V_91 = F_81 ( V_2 , & V_231 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_231 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_91 = F_81 ( V_2 , & V_230 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_81 ( V_2 , & V_232 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_230 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_231 ;
if ( V_2 -> V_104 == 4 )
V_2 -> V_172 = ( ( V_232 & V_32 ) | ( V_2 -> V_172 & V_233 ) ) ;
else if ( V_2 -> V_104 == 2 ) {
V_2 -> V_172 &= ~ 0xffff ;
V_2 -> V_172 |= V_232 ;
}
V_2 -> V_172 &= ~ V_237 ;
V_2 -> V_172 |= V_238 ;
return V_91 ;
}
static int F_96 ( struct V_1 * V_2 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_95 ( V_2 ) ;
case V_194 :
case V_218 :
case V_217 :
case V_37 :
default:
return V_100 ;
}
}
static int F_97 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned short V_33 ;
memcpy ( & V_33 , V_2 -> V_22 . V_239 + V_2 -> V_104 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_239 , V_2 -> V_104 ) ;
return V_89 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
switch ( V_2 -> V_19 ) {
case 2 : {
long int V_240 ;
V_240 = V_2 -> V_44 ;
V_2 -> V_44 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = V_240 ;
V_91 = F_80 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_44 = V_2 -> V_22 . V_112 ;
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
V_113 V_241 = V_2 -> V_27 . V_242 ;
if ( ( ( T_3 ) ( V_241 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_226 ) ) ||
( ( T_3 ) ( V_241 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_243 ) ) ) {
* F_2 ( V_2 , V_226 ) = ( T_3 ) ( V_241 >> 0 ) ;
* F_2 ( V_2 , V_243 ) = ( T_3 ) ( V_241 >> 32 ) ;
V_2 -> V_172 &= ~ V_209 ;
} else {
V_2 -> V_27 . V_23 = ( ( V_113 ) F_1 ( V_2 , V_171 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_145 ) ;
V_2 -> V_172 |= V_209 ;
}
return V_89 ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
return F_82 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_230 ;
V_91 = F_81 ( V_2 , & V_2 -> V_44 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_104 == 4 )
V_2 -> V_44 = ( T_3 ) V_2 -> V_44 ;
V_91 = F_81 ( V_2 , & V_230 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_230 , V_97 ) ;
return V_91 ;
}
static int F_102 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_133 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = F_1 ( V_2 , V_226 ) ;
F_103 ( V_2 , V_244 ) ;
if ( V_2 -> V_172 & V_209 ) {
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_133 ;
} else {
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_226 ) ;
}
return V_89 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_223 . V_112 ;
unsigned short V_33 ;
int V_91 ;
memcpy ( & V_33 , V_2 -> V_22 . V_239 + V_2 -> V_104 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_48 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_112 ;
return V_91 ;
}
static void
F_105 ( struct V_1 * V_2 ,
struct V_34 * V_230 , struct V_34 * V_35 )
{
V_230 -> V_245 = 0 ;
F_75 ( V_230 , 0 ) ;
V_230 -> V_47 = 1 ;
F_76 ( V_230 , 0xfffff ) ;
V_230 -> type = 0x0b ;
V_230 -> V_195 = 1 ;
V_230 -> V_88 = 0 ;
V_230 -> V_102 = 1 ;
V_230 -> V_40 = 1 ;
V_230 -> V_246 = 0 ;
F_75 ( V_35 , 0 ) ;
F_76 ( V_35 , 0xfffff ) ;
V_35 -> V_47 = 1 ;
V_35 -> V_195 = 1 ;
V_35 -> type = 0x03 ;
V_35 -> V_40 = 1 ;
V_35 -> V_88 = 0 ;
V_35 -> V_102 = 1 ;
V_35 -> V_245 = 0 ;
V_35 -> V_246 = 0 ;
}
static bool F_106 ( struct V_1 * V_2 )
{
T_3 V_247 , V_248 , V_249 , V_250 ;
V_247 = V_249 = 0 ;
V_2 -> V_6 -> V_251 ( V_2 , & V_247 , & V_248 , & V_249 , & V_250 ) ;
return V_248 == V_252
&& V_249 == V_253
&& V_250 == V_254 ;
}
static bool F_107 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
T_3 V_247 , V_248 , V_249 , V_250 ;
if ( V_2 -> V_36 == V_37 )
return true ;
V_247 = 0x00000000 ;
V_249 = 0x00000000 ;
V_6 -> V_251 ( V_2 , & V_247 , & V_248 , & V_249 , & V_250 ) ;
if ( V_248 == V_252 &&
V_249 == V_253 &&
V_250 == V_254 )
return false ;
if ( V_248 == V_255 &&
V_249 == V_256 &&
V_250 == V_257 )
return true ;
if ( V_248 == V_258 &&
V_249 == V_259 &&
V_250 == V_260 )
return true ;
return false ;
}
static int F_108 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_230 , V_35 ;
V_113 V_261 ;
T_2 V_262 , V_263 ;
V_113 V_264 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_194 )
return F_27 ( V_2 ) ;
if ( ! ( F_107 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
F_105 ( V_2 , & V_230 , & V_35 ) ;
if ( ! ( V_264 & V_267 ) )
return F_27 ( V_2 ) ;
V_6 -> V_265 ( V_2 , V_268 , & V_261 ) ;
V_261 >>= 32 ;
V_262 = ( T_2 ) ( V_261 & 0xfffc ) ;
V_263 = ( T_2 ) ( V_261 + 8 ) ;
if ( V_264 & V_269 ) {
V_230 . V_40 = 0 ;
V_230 . V_245 = 1 ;
}
V_6 -> V_71 ( V_2 , V_262 , & V_230 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_263 , & V_35 , 0 , V_39 ) ;
* F_2 ( V_2 , V_171 ) = V_2 -> V_44 ;
if ( V_264 & V_269 ) {
#ifdef F_49
* F_2 ( V_2 , V_270 ) = V_2 -> V_172 & ~ V_214 ;
V_6 -> V_265 ( V_2 ,
V_2 -> V_36 == V_37 ?
V_271 : V_272 , & V_261 ) ;
V_2 -> V_44 = V_261 ;
V_6 -> V_265 ( V_2 , V_273 , & V_261 ) ;
V_2 -> V_172 &= ~ ( V_261 | V_214 ) ;
#endif
} else {
V_6 -> V_265 ( V_2 , V_268 , & V_261 ) ;
V_2 -> V_44 = ( T_3 ) V_261 ;
V_2 -> V_172 &= ~ ( V_234 | V_220 | V_214 ) ;
}
return V_89 ;
}
static int F_109 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_230 , V_35 ;
V_113 V_261 ;
T_2 V_262 , V_263 ;
V_113 V_264 = 0 ;
V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
if ( V_2 -> V_36 == V_87 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_36 == V_217 ) && ( V_264 & V_269 )
&& ! F_106 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_36 == V_37 )
return F_27 ( V_2 ) ;
F_105 ( V_2 , & V_230 , & V_35 ) ;
V_6 -> V_265 ( V_2 , V_274 , & V_261 ) ;
switch ( V_2 -> V_36 ) {
case V_217 :
if ( ( V_261 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
case V_37 :
if ( V_261 == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_172 &= ~ ( V_234 | V_220 | V_214 ) ;
V_262 = ( T_2 ) V_261 ;
V_262 &= ~ V_275 ;
V_263 = V_262 + 8 ;
V_263 &= ~ V_275 ;
if ( V_2 -> V_36 == V_37 || ( V_264 & V_269 ) ) {
V_230 . V_40 = 0 ;
V_230 . V_245 = 1 ;
}
V_6 -> V_71 ( V_2 , V_262 , & V_230 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_263 , & V_35 , 0 , V_39 ) ;
V_6 -> V_265 ( V_2 , V_276 , & V_261 ) ;
V_2 -> V_44 = V_261 ;
V_6 -> V_265 ( V_2 , V_277 , & V_261 ) ;
* F_2 ( V_2 , V_42 ) = V_261 ;
return V_89 ;
}
static int F_110 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_230 , V_35 ;
V_113 V_261 ;
int V_278 ;
T_2 V_262 = 0 , V_263 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_194 )
return F_25 ( V_2 , 0 ) ;
F_105 ( V_2 , & V_230 , & V_35 ) ;
if ( ( V_2 -> V_121 & 0x8 ) != 0x0 )
V_278 = V_37 ;
else
V_278 = V_217 ;
V_230 . V_88 = 3 ;
V_35 . V_88 = 3 ;
V_6 -> V_265 ( V_2 , V_274 , & V_261 ) ;
switch ( V_278 ) {
case V_217 :
V_262 = ( T_2 ) ( V_261 + 16 ) ;
if ( ( V_261 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_263 = ( T_2 ) ( V_261 + 24 ) ;
break;
case V_37 :
V_262 = ( T_2 ) ( V_261 + 32 ) ;
if ( V_261 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_263 = V_262 + 8 ;
V_230 . V_40 = 0 ;
V_230 . V_245 = 1 ;
break;
}
V_262 |= V_275 ;
V_263 |= V_275 ;
V_6 -> V_71 ( V_2 , V_262 , & V_230 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_263 , & V_35 , 0 , V_39 ) ;
V_2 -> V_44 = F_1 ( V_2 , V_243 ) ;
* F_2 ( V_2 , V_42 ) = F_1 ( V_2 , V_171 ) ;
return V_89 ;
}
static bool F_111 ( struct V_1 * V_2 )
{
int V_203 ;
if ( V_2 -> V_36 == V_87 )
return false ;
if ( V_2 -> V_36 == V_194 )
return true ;
V_203 = ( V_2 -> V_172 & V_204 ) >> V_205 ;
return V_2 -> V_6 -> V_84 ( V_2 ) > V_203 ;
}
static bool F_112 ( struct V_1 * V_2 ,
T_2 V_166 , T_2 V_201 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_279 ;
T_3 V_70 ;
int V_280 ;
T_2 V_281 , V_282 , V_283 , V_284 = V_166 & 0x7 ;
unsigned V_32 = ( 1 << V_201 ) - 1 ;
unsigned long V_285 ;
V_6 -> V_38 ( V_2 , & V_281 , & V_279 , & V_70 , V_196 ) ;
if ( ! V_279 . V_102 )
return false ;
if ( F_19 ( & V_279 ) < 103 )
return false ;
V_285 = F_71 ( & V_279 ) ;
#ifdef F_49
V_285 |= ( ( V_113 ) V_70 ) << 32 ;
#endif
V_280 = V_6 -> V_92 ( V_2 , V_285 + 102 , & V_282 , 2 , NULL ) ;
if ( V_280 != V_89 )
return false ;
if ( V_282 + V_166 / 8 > F_19 ( & V_279 ) )
return false ;
V_280 = V_6 -> V_92 ( V_2 , V_285 + V_282 + V_166 / 8 , & V_283 , 2 , NULL ) ;
if ( V_280 != V_89 )
return false ;
if ( ( V_283 >> V_284 ) & V_32 )
return false ;
return true ;
}
static bool F_113 ( struct V_1 * V_2 ,
T_2 V_166 , T_2 V_201 )
{
if ( V_2 -> V_286 )
return true ;
if ( F_111 ( V_2 ) )
if ( ! F_112 ( V_2 , V_166 , V_201 ) )
return false ;
V_2 -> V_286 = true ;
return true ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
V_288 -> V_289 = V_2 -> V_44 ;
V_288 -> V_290 = V_2 -> V_172 ;
V_288 -> V_291 = F_1 ( V_2 , V_226 ) ;
V_288 -> V_292 = F_1 ( V_2 , V_171 ) ;
V_288 -> V_293 = F_1 ( V_2 , V_243 ) ;
V_288 -> V_144 = F_1 ( V_2 , V_145 ) ;
V_288 -> V_294 = F_1 ( V_2 , V_42 ) ;
V_288 -> V_146 = F_1 ( V_2 , V_135 ) ;
V_288 -> V_147 = F_1 ( V_2 , V_148 ) ;
V_288 -> V_149 = F_1 ( V_2 , V_150 ) ;
V_288 -> V_295 = F_31 ( V_2 , V_296 ) ;
V_288 -> V_230 = F_31 ( V_2 , V_97 ) ;
V_288 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_288 -> V_297 = F_31 ( V_2 , V_142 ) ;
V_288 -> V_298 = F_31 ( V_2 , V_180 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
int V_191 ;
V_2 -> V_44 = V_288 -> V_289 ;
V_2 -> V_172 = V_288 -> V_290 | 2 ;
* F_2 ( V_2 , V_226 ) = V_288 -> V_291 ;
* F_2 ( V_2 , V_171 ) = V_288 -> V_292 ;
* F_2 ( V_2 , V_243 ) = V_288 -> V_293 ;
* F_2 ( V_2 , V_145 ) = V_288 -> V_144 ;
* F_2 ( V_2 , V_42 ) = V_288 -> V_294 ;
* F_2 ( V_2 , V_135 ) = V_288 -> V_146 ;
* F_2 ( V_2 , V_148 ) = V_288 -> V_147 ;
* F_2 ( V_2 , V_150 ) = V_288 -> V_149 ;
F_32 ( V_2 , V_288 -> V_298 , V_180 ) ;
F_32 ( V_2 , V_288 -> V_295 , V_296 ) ;
F_32 ( V_2 , V_288 -> V_230 , V_97 ) ;
F_32 ( V_2 , V_288 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_288 -> V_297 , V_142 ) ;
V_191 = F_74 ( V_2 , V_288 -> V_298 , V_180 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_295 , V_296 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_230 , V_97 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_35 , V_39 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_297 , V_142 ) ;
if ( V_191 != V_89 )
return V_191 ;
return V_89 ;
}
static int F_116 ( struct V_1 * V_2 ,
T_2 V_299 , T_2 V_300 ,
T_1 V_301 , struct V_34 * V_302 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_287 V_303 ;
int V_191 ;
T_3 V_304 = F_71 ( V_302 ) ;
V_191 = V_6 -> V_92 ( V_2 , V_301 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
F_114 ( V_2 , & V_303 ) ;
V_191 = V_6 -> V_183 ( V_2 , V_301 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = V_6 -> V_92 ( V_2 , V_304 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_300 != 0xffff ) {
V_303 . V_305 = V_300 ;
V_191 = V_6 -> V_183 ( V_2 , V_304 ,
& V_303 . V_305 ,
sizeof V_303 . V_305 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
return F_115 ( V_2 , & V_303 ) ;
}
static void F_117 ( struct V_1 * V_2 ,
struct V_306 * V_288 )
{
V_288 -> V_307 = V_2 -> V_6 -> V_116 ( V_2 , 3 ) ;
V_288 -> V_30 = V_2 -> V_44 ;
V_288 -> V_172 = V_2 -> V_172 ;
V_288 -> V_247 = F_1 ( V_2 , V_226 ) ;
V_288 -> V_249 = F_1 ( V_2 , V_171 ) ;
V_288 -> V_250 = F_1 ( V_2 , V_243 ) ;
V_288 -> V_248 = F_1 ( V_2 , V_145 ) ;
V_288 -> V_308 = F_1 ( V_2 , V_42 ) ;
V_288 -> V_309 = F_1 ( V_2 , V_135 ) ;
V_288 -> V_310 = F_1 ( V_2 , V_148 ) ;
V_288 -> V_311 = F_1 ( V_2 , V_150 ) ;
V_288 -> V_295 = F_31 ( V_2 , V_296 ) ;
V_288 -> V_230 = F_31 ( V_2 , V_97 ) ;
V_288 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_288 -> V_297 = F_31 ( V_2 , V_142 ) ;
V_288 -> V_312 = F_31 ( V_2 , V_51 ) ;
V_288 -> V_313 = F_31 ( V_2 , V_193 ) ;
V_288 -> V_314 = F_31 ( V_2 , V_180 ) ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_306 * V_288 )
{
int V_191 ;
if ( V_2 -> V_6 -> V_315 ( V_2 , 3 , V_288 -> V_307 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_44 = V_288 -> V_30 ;
V_2 -> V_172 = V_288 -> V_172 | 2 ;
* F_2 ( V_2 , V_226 ) = V_288 -> V_247 ;
* F_2 ( V_2 , V_171 ) = V_288 -> V_249 ;
* F_2 ( V_2 , V_243 ) = V_288 -> V_250 ;
* F_2 ( V_2 , V_145 ) = V_288 -> V_248 ;
* F_2 ( V_2 , V_42 ) = V_288 -> V_308 ;
* F_2 ( V_2 , V_135 ) = V_288 -> V_309 ;
* F_2 ( V_2 , V_148 ) = V_288 -> V_310 ;
* F_2 ( V_2 , V_150 ) = V_288 -> V_311 ;
F_32 ( V_2 , V_288 -> V_314 , V_180 ) ;
F_32 ( V_2 , V_288 -> V_295 , V_296 ) ;
F_32 ( V_2 , V_288 -> V_230 , V_97 ) ;
F_32 ( V_2 , V_288 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_288 -> V_297 , V_142 ) ;
F_32 ( V_2 , V_288 -> V_312 , V_51 ) ;
F_32 ( V_2 , V_288 -> V_313 , V_193 ) ;
if ( V_2 -> V_172 & V_316 )
V_2 -> V_36 = V_194 ;
else
V_2 -> V_36 = V_217 ;
V_2 -> V_6 -> V_317 ( V_2 , V_2 -> V_172 ) ;
V_191 = F_74 ( V_2 , V_288 -> V_314 , V_180 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_295 , V_296 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_230 , V_97 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_35 , V_39 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_297 , V_142 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_312 , V_51 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_288 -> V_313 , V_193 ) ;
if ( V_191 != V_89 )
return V_191 ;
return V_89 ;
}
static int F_119 ( struct V_1 * V_2 ,
T_2 V_299 , T_2 V_300 ,
T_1 V_301 , struct V_34 * V_302 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_306 V_303 ;
int V_191 ;
T_3 V_304 = F_71 ( V_302 ) ;
V_191 = V_6 -> V_92 ( V_2 , V_301 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
F_117 ( V_2 , & V_303 ) ;
V_191 = V_6 -> V_183 ( V_2 , V_301 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = V_6 -> V_92 ( V_2 , V_304 , & V_303 , sizeof V_303 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_300 != 0xffff ) {
V_303 . V_305 = V_300 ;
V_191 = V_6 -> V_183 ( V_2 , V_304 ,
& V_303 . V_305 ,
sizeof V_303 . V_305 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
return F_118 ( V_2 , & V_303 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
T_2 V_299 , int V_318 , int V_319 ,
bool V_320 , T_3 V_57 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_321 , V_322 ;
int V_191 ;
T_2 V_300 = F_31 ( V_2 , V_196 ) ;
T_1 V_301 =
V_6 -> V_52 ( V_2 , V_196 ) ;
T_3 V_323 ;
T_1 V_190 ;
V_191 = F_72 ( V_2 , V_299 , & V_322 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_72 ( V_2 , V_300 , & V_321 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_319 == V_324 ) {
if ( V_318 != - 1 ) {
struct V_34 V_325 ;
int V_88 ;
V_191 = F_69 ( V_2 , V_318 ,
& V_325 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_88 = V_325 . V_88 ;
if ( ( V_299 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , ( V_318 << 3 ) | 0x2 ) ;
}
} else if ( V_319 != V_326 ) {
int V_88 = V_322 . V_88 ;
if ( ( V_299 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , V_299 ) ;
}
V_323 = F_19 ( & V_322 ) ;
if ( ! V_322 . V_102 ||
( ( V_323 < 0x67 && ( V_322 . type & 8 ) ) ||
V_323 < 0x2b ) ) {
F_28 ( V_2 , V_299 & 0xfffc ) ;
return V_59 ;
}
if ( V_319 == V_326 || V_319 == V_327 ) {
V_321 . type &= ~ ( 1 << 1 ) ;
F_73 ( V_2 , V_300 , & V_321 ) ;
}
if ( V_319 == V_326 )
V_2 -> V_172 = V_2 -> V_172 & ~ V_328 ;
if ( V_319 != V_329 && V_319 != V_324 )
V_300 = 0xffff ;
if ( V_322 . type & 8 )
V_191 = F_119 ( V_2 , V_299 , V_300 ,
V_301 , & V_322 ) ;
else
V_191 = F_116 ( V_2 , V_299 , V_300 ,
V_301 , & V_322 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_319 == V_329 || V_319 == V_324 )
V_2 -> V_172 = V_2 -> V_172 | V_328 ;
if ( V_319 != V_326 ) {
V_322 . type |= ( 1 << 1 ) ;
F_73 ( V_2 , V_299 , & V_322 ) ;
}
V_6 -> V_315 ( V_2 , 0 , V_6 -> V_116 ( V_2 , 0 ) | V_117 ) ;
V_6 -> V_71 ( V_2 , V_299 , & V_322 , 0 , V_196 ) ;
if ( V_320 ) {
V_2 -> V_104 = V_2 -> V_28 = ( V_322 . type & 8 ) ? 4 : 2 ;
V_2 -> V_198 = 0 ;
V_2 -> V_22 . V_112 = ( unsigned long ) V_57 ;
V_191 = F_80 ( V_2 ) ;
}
return V_191 ;
}
int F_121 ( struct V_1 * V_2 ,
T_2 V_299 , int V_318 , int V_319 ,
bool V_320 , T_3 V_57 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_200 ;
V_91 = F_120 ( V_2 , V_299 , V_318 , V_319 ,
V_320 , V_57 ) ;
if ( V_91 == V_89 ) {
V_2 -> V_30 = V_2 -> V_44 ;
F_4 ( V_2 ) ;
}
return ( V_91 == V_100 ) ? V_330 : V_331 ;
}
static void F_122 ( struct V_1 * V_2 , int V_9 ,
struct V_110 * V_111 )
{
int V_332 = ( V_2 -> V_172 & V_173 ) ? - V_111 -> V_170 : V_111 -> V_170 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_332 * V_111 -> V_25 ) ;
V_111 -> V_77 . V_154 . V_85 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
T_4 V_333 , V_334 ;
bool V_335 , V_336 , V_337 ;
V_336 = V_2 -> V_172 & V_338 ;
V_333 = V_2 -> V_27 . V_112 ;
V_334 = V_333 ;
V_337 = V_336 ;
V_336 = false ;
V_335 = V_2 -> V_172 & V_339 ;
if ( ( V_333 & 0x0f ) > 9 || V_335 ) {
V_333 -= 6 ;
V_336 = V_337 | ( V_333 >= 250 ) ;
V_335 = true ;
} else {
V_335 = false ;
}
if ( V_334 > 0x99 || V_337 ) {
V_333 -= 0x60 ;
V_336 = true ;
}
V_2 -> V_27 . V_112 = V_333 ;
V_2 -> V_22 . type = V_340 ;
V_2 -> V_22 . V_112 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_103 ( V_2 , V_341 ) ;
V_2 -> V_172 &= ~ ( V_339 | V_338 ) ;
if ( V_336 )
V_2 -> V_172 |= V_338 ;
if ( V_335 )
V_2 -> V_172 |= V_339 ;
return V_89 ;
}
static int F_124 ( struct V_1 * V_2 )
{
T_4 V_333 , V_342 ;
if ( V_2 -> V_22 . V_112 == 0 )
return F_29 ( V_2 ) ;
V_333 = V_2 -> V_27 . V_112 & 0xff ;
V_342 = V_333 / V_2 -> V_22 . V_112 ;
V_333 %= V_2 -> V_22 . V_112 ;
V_2 -> V_27 . V_112 = ( V_2 -> V_27 . V_112 & 0xffff0000 ) | V_333 | ( V_342 << 8 ) ;
V_2 -> V_22 . type = V_340 ;
V_2 -> V_22 . V_112 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_103 ( V_2 , V_341 ) ;
return V_89 ;
}
static int F_125 ( struct V_1 * V_2 )
{
T_4 V_333 = V_2 -> V_27 . V_112 & 0xff ;
T_4 V_342 = ( V_2 -> V_27 . V_112 >> 8 ) & 0xff ;
V_333 = ( V_333 + ( V_342 * V_2 -> V_22 . V_112 ) ) & 0xff ;
V_2 -> V_27 . V_112 = ( V_2 -> V_27 . V_112 & 0xffff0000 ) | V_333 ;
V_2 -> V_22 . type = V_340 ;
V_2 -> V_22 . V_112 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_103 ( V_2 , V_341 ) ;
return V_89 ;
}
static int F_126 ( struct V_1 * V_2 )
{
long V_43 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = ( unsigned long ) V_2 -> V_44 ;
F_18 ( V_2 , V_43 ) ;
return F_80 ( V_2 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
T_2 V_33 , V_343 ;
T_1 V_240 ;
int V_91 ;
V_343 = F_31 ( V_2 , V_97 ) ;
V_240 = V_2 -> V_44 ;
memcpy ( & V_33 , V_2 -> V_22 . V_239 + V_2 -> V_104 , 2 ) ;
if ( F_74 ( V_2 , V_33 , V_97 ) )
return V_89 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_239 , V_2 -> V_104 ) ;
V_2 -> V_22 . V_112 = V_343 ;
V_91 = F_80 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_112 = V_240 ;
return F_80 ( V_2 ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
int V_91 ;
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_91 = F_81 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_129 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_112 = V_2 -> V_27 . V_112 ;
F_77 ( & V_2 -> V_22 ) ;
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_133 ;
V_2 -> V_198 = 1 ;
return V_89 ;
}
static int F_130 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_112 = V_2 -> V_223 . V_112 ;
return F_103 ( V_2 , V_344 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_25 = V_2 -> V_22 . V_25 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_243 ) ;
V_2 -> V_27 . V_112 = ~ ( ( V_2 -> V_22 . V_112 >> ( V_2 -> V_22 . V_25 * 8 - 1 ) ) - 1 ) ;
return V_89 ;
}
static int F_132 ( struct V_1 * V_2 )
{
V_113 V_345 = 0 ;
V_2 -> V_6 -> V_265 ( V_2 , V_346 , & V_345 ) ;
* F_2 ( V_2 , V_226 ) = ( T_3 ) V_345 ;
* F_2 ( V_2 , V_243 ) = V_345 >> 32 ;
return V_89 ;
}
static int F_133 ( struct V_1 * V_2 )
{
V_113 V_347 ;
if ( V_2 -> V_6 -> V_348 ( V_2 , F_1 ( V_2 , V_171 ) , & V_347 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_226 ) = ( T_3 ) V_347 ;
* F_2 ( V_2 , V_243 ) = V_347 >> 32 ;
return V_89 ;
}
static int F_134 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_27 . V_239 , V_2 -> V_22 . V_239 , V_2 -> V_104 ) ;
return V_89 ;
}
static int F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_315 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_112 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_136 ( struct V_1 * V_2 )
{
unsigned long V_112 ;
if ( V_2 -> V_36 == V_37 )
V_112 = V_2 -> V_22 . V_112 & ~ 0ULL ;
else
V_112 = V_2 -> V_22 . V_112 & ~ 0U ;
if ( V_2 -> V_6 -> V_349 ( V_2 , V_2 -> V_19 , V_112 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_137 ( struct V_1 * V_2 )
{
V_113 V_261 ;
V_261 = ( T_3 ) F_1 ( V_2 , V_226 )
| ( ( V_113 ) F_1 ( V_2 , V_243 ) << 32 ) ;
if ( V_2 -> V_6 -> V_350 ( V_2 , F_1 ( V_2 , V_171 ) , V_261 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_138 ( struct V_1 * V_2 )
{
V_113 V_261 ;
if ( V_2 -> V_6 -> V_265 ( V_2 , F_1 ( V_2 , V_171 ) , & V_261 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_226 ) = ( T_3 ) V_261 ;
* F_2 ( V_2 , V_243 ) = V_261 >> 32 ;
return V_89 ;
}
static int F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_193 )
return F_27 ( V_2 ) ;
V_2 -> V_27 . V_112 = F_31 ( V_2 , V_2 -> V_19 ) ;
return V_89 ;
}
static int F_140 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
if ( V_2 -> V_19 == V_97 || V_2 -> V_19 > V_193 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_39 )
V_2 -> V_351 = V_352 ;
V_2 -> V_27 . type = V_200 ;
return F_74 ( V_2 , V_33 , V_2 -> V_19 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
V_2 -> V_27 . type = V_200 ;
return F_74 ( V_2 , V_33 , V_180 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
V_2 -> V_27 . type = V_200 ;
return F_74 ( V_2 , V_33 , V_196 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_2 -> V_22 . V_77 . V_154 , 1 , false , & V_80 ) ;
if ( V_91 == V_89 )
V_2 -> V_6 -> V_353 ( V_2 , V_80 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_144 ( struct V_1 * V_2 )
{
T_1 V_354 ;
V_354 = V_2 -> V_6 -> V_116 ( V_2 , 0 ) ;
V_354 &= ~ V_117 ;
V_2 -> V_6 -> V_315 ( V_2 , 0 , V_354 ) ;
return V_89 ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_91 ;
if ( V_2 -> V_18 != 3 || V_2 -> V_20 != 1 )
return V_100 ;
V_91 = V_2 -> V_6 -> V_355 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_146 ( struct V_1 * V_2 ,
void (* F_147)( struct V_1 * V_2 ,
struct V_176 * V_356 ) )
{
struct V_176 V_176 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_104 = 8 ;
F_147 ( V_2 , & V_176 ) ;
if ( V_2 -> V_104 == 2 ) {
V_2 -> V_104 = 4 ;
V_176 . V_103 &= 0x00ffffff ;
}
V_2 -> V_27 . type = V_200 ;
return F_66 ( V_2 , V_2 -> V_27 . V_77 . V_154 ,
& V_176 , 2 + V_2 -> V_104 ) ;
}
static int F_148 ( struct V_1 * V_2 )
{
return F_146 ( V_2 , V_2 -> V_6 -> V_181 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
return F_146 ( V_2 , V_2 -> V_6 -> V_178 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
struct V_176 V_176 ;
int V_91 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_104 = 8 ;
V_91 = F_44 ( V_2 , V_2 -> V_22 . V_77 . V_154 ,
& V_176 . V_72 , & V_176 . V_103 ,
V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_357 ( V_2 , & V_176 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = V_2 -> V_6 -> V_355 ( V_2 ) ;
V_2 -> V_27 . type = V_200 ;
return V_91 ;
}
static int F_152 ( struct V_1 * V_2 )
{
struct V_176 V_176 ;
int V_91 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_104 = 8 ;
V_91 = F_44 ( V_2 , V_2 -> V_22 . V_77 . V_154 ,
& V_176 . V_72 , & V_176 . V_103 ,
V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_358 ( V_2 , & V_176 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_112 = V_2 -> V_6 -> V_116 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_315 ( V_2 , 0 , ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_112 & 0x0f ) ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_155 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_3 ( V_2 , V_171 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) != 0 ) &&
( V_2 -> V_123 == 0xe2 || F_45 ( V_2 -> V_123 ^ 0x5 , V_2 -> V_172 ) ) )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_156 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) == 0 )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 , V_2 -> V_27 . V_25 , V_2 -> V_22 . V_112 ,
& V_2 -> V_27 . V_112 ) )
return V_359 ;
return V_89 ;
}
static int F_158 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_360 ( V_2 , V_2 -> V_22 . V_25 , V_2 -> V_27 . V_112 ,
& V_2 -> V_22 . V_112 , 1 ) ;
V_2 -> V_27 . type = V_200 ;
return V_89 ;
}
static int F_159 ( struct V_1 * V_2 )
{
if ( F_111 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_172 &= ~ V_109 ;
return V_89 ;
}
static int F_160 ( struct V_1 * V_2 )
{
if ( F_111 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_351 = V_361 ;
V_2 -> V_172 |= V_109 ;
return V_89 ;
}
static int F_161 ( struct V_1 * V_2 )
{
T_3 V_247 , V_248 , V_249 , V_250 ;
V_247 = F_1 ( V_2 , V_226 ) ;
V_249 = F_1 ( V_2 , V_171 ) ;
V_2 -> V_6 -> V_251 ( V_2 , & V_247 , & V_248 , & V_249 , & V_250 ) ;
* F_2 ( V_2 , V_226 ) = V_247 ;
* F_2 ( V_2 , V_145 ) = V_248 ;
* F_2 ( V_2 , V_171 ) = V_249 ;
* F_2 ( V_2 , V_243 ) = V_250 ;
return V_89 ;
}
static int F_162 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_226 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_226 ) |= ( V_2 -> V_172 & 0xff ) << 8 ;
return V_89 ;
}
static int F_163 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_104 ) {
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
static bool F_164 ( int V_3 )
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
static int F_165 ( struct V_1 * V_2 )
{
if ( ! F_164 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_113 V_362 = V_2 -> V_22 . V_23 ;
int V_363 = V_2 -> V_19 ;
V_113 V_264 = 0 ;
static V_113 V_364 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_365 ,
0 , 0 , 0 ,
V_366 ,
} ;
if ( ! F_164 ( V_363 ) )
return F_27 ( V_2 ) ;
if ( V_362 & V_364 [ V_363 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_363 ) {
case 0 : {
V_113 V_367 ;
if ( ( ( V_362 & V_368 ) && ! ( V_362 & V_369 ) ) ||
( ( V_362 & V_370 ) && ! ( V_362 & V_371 ) ) )
return F_25 ( V_2 , 0 ) ;
V_367 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
if ( ( V_362 & V_368 ) && ( V_264 & V_372 ) &&
! ( V_367 & V_373 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_113 V_374 = 0 ;
V_2 -> V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
if ( V_264 & V_269 )
V_374 = V_375 ;
else if ( V_2 -> V_6 -> V_116 ( V_2 , 4 ) & V_373 )
V_374 = V_376 ;
else if ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & V_368 )
V_374 = V_377 ;
if ( V_362 & V_374 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
if ( ( V_264 & V_269 ) && ! ( V_362 & V_373 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_89 ;
}
static int F_167 ( struct V_1 * V_2 )
{
unsigned long V_378 ;
V_2 -> V_6 -> V_379 ( V_2 , 7 , & V_378 ) ;
return V_378 & ( 1 << 13 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
int V_380 = V_2 -> V_19 ;
V_113 V_367 ;
if ( V_380 > 7 )
return F_27 ( V_2 ) ;
V_367 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
if ( ( V_367 & V_381 ) && ( V_380 == 4 || V_380 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_167 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_89 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_113 V_362 = V_2 -> V_22 . V_23 ;
int V_380 = V_2 -> V_19 ;
if ( ( V_380 == 6 || V_380 == 7 ) && ( V_362 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_168 ( V_2 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_113 V_264 ;
V_2 -> V_6 -> V_265 ( V_2 , V_266 , & V_264 ) ;
if ( ! ( V_264 & V_382 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_171 ( struct V_1 * V_2 )
{
V_113 V_383 = F_1 ( V_2 , V_226 ) ;
if ( V_383 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_170 ( V_2 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
V_113 V_367 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
if ( V_367 & V_384 && V_2 -> V_6 -> V_84 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_113 V_367 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
V_113 V_385 = F_1 ( V_2 , V_171 ) ;
if ( ( ! ( V_367 & V_386 ) && V_2 -> V_6 -> V_84 ( V_2 ) ) ||
( V_385 > 3 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = F_39 ( V_2 -> V_27 . V_25 , 4u ) ;
if ( ! F_113 ( V_2 , V_2 -> V_22 . V_112 , V_2 -> V_27 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_175 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_25 = F_39 ( V_2 -> V_22 . V_25 , 4u ) ;
if ( ! F_113 ( V_2 , V_2 -> V_27 . V_112 , V_2 -> V_22 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static unsigned F_176 ( struct V_1 * V_2 )
{
unsigned V_72 ;
V_72 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
if ( V_72 == 8 )
V_72 = 4 ;
return V_72 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_110 * V_111 ,
unsigned V_72 , bool V_387 )
{
int V_91 = V_89 ;
V_111 -> type = V_340 ;
V_111 -> V_25 = V_72 ;
V_111 -> V_77 . V_154 . V_85 = V_2 -> V_44 ;
switch ( V_111 -> V_25 ) {
case 1 :
V_111 -> V_112 = F_60 ( V_151 , V_2 ) ;
break;
case 2 :
V_111 -> V_112 = F_60 ( V_157 , V_2 ) ;
break;
case 4 :
V_111 -> V_112 = F_60 ( V_152 , V_2 ) ;
break;
case 8 :
V_111 -> V_112 = F_60 ( V_388 , V_2 ) ;
break;
}
if ( ! V_387 ) {
switch ( V_111 -> V_25 ) {
case 1 :
V_111 -> V_112 &= 0xff ;
break;
case 2 :
V_111 -> V_112 &= 0xffff ;
break;
case 4 :
V_111 -> V_112 &= 0xffffffff ;
break;
}
}
V_155:
return V_91 ;
}
static int F_178 ( struct V_1 * V_2 , struct V_110 * V_111 ,
unsigned V_40 )
{
int V_91 = V_89 ;
switch ( V_40 ) {
case V_389 :
F_57 ( V_2 , V_111 ) ;
break;
case V_390 :
V_91 = F_177 ( V_2 , V_111 , 1 , false ) ;
break;
case V_391 :
V_2 -> V_392 . V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_393:
* V_111 = V_2 -> V_392 ;
V_2 -> V_394 = V_111 ;
if ( ( V_2 -> V_40 & V_395 ) && V_111 == & V_2 -> V_27 )
F_62 ( V_2 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_396 :
V_2 -> V_392 . V_25 = 8 ;
goto V_393;
case V_397 :
V_111 -> type = V_131 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_226 ) ;
F_47 ( V_111 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_398 :
V_111 -> type = V_131 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 2 : V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_226 ) ;
F_47 ( V_111 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_399 :
if ( V_2 -> V_40 & V_132 ) {
V_111 -> type = V_200 ;
break;
}
V_111 -> type = V_131 ;
V_111 -> V_25 = V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_243 ) ;
F_47 ( V_111 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_400 :
V_111 -> type = V_143 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_154 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_150 ) ) ;
V_111 -> V_77 . V_154 . V_48 = V_296 ;
V_111 -> V_112 = 0 ;
V_111 -> V_170 = 1 ;
break;
case V_401 :
V_111 -> type = V_131 ;
V_111 -> V_25 = 2 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_243 ) ;
F_47 ( V_111 ) ;
break;
case V_402 :
V_111 -> V_25 = 1 ;
V_111 -> V_112 = F_1 ( V_2 , V_171 ) & 0xff ;
break;
case V_403 :
V_91 = F_177 ( V_2 , V_111 , 1 , true ) ;
break;
case V_404 :
V_111 -> V_25 = 1 ;
V_111 -> V_112 = 1 ;
break;
case V_405 :
V_91 = F_177 ( V_2 , V_111 , F_176 ( V_2 ) , true ) ;
break;
case V_406 :
V_91 = F_177 ( V_2 , V_111 , V_2 -> V_104 , true ) ;
break;
case V_407 :
V_2 -> V_392 . V_25 = 1 ;
if ( V_2 -> V_392 . type == V_131 ) {
V_2 -> V_392 . V_77 . V_9 = F_43 ( V_2 , V_2 -> V_20 , 1 ) ;
F_47 ( & V_2 -> V_392 ) ;
}
goto V_393;
case V_408 :
V_2 -> V_392 . V_25 = 2 ;
goto V_393;
case V_409 :
V_2 -> V_392 . V_25 = 4 ;
goto V_393;
case V_410 :
V_91 = F_177 ( V_2 , V_111 , 2 , false ) ;
break;
case V_411 :
V_91 = F_177 ( V_2 , V_111 , F_176 ( V_2 ) , false ) ;
break;
case V_412 :
V_111 -> type = V_143 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_154 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_148 ) ) ;
V_111 -> V_77 . V_154 . V_48 = V_50 ( V_2 ) ;
V_111 -> V_112 = 0 ;
V_111 -> V_170 = 1 ;
break;
case V_413 :
V_111 -> type = V_143 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_154 . V_85 =
F_14 ( V_2 ,
F_1 ( V_2 , V_145 ) +
( F_1 ( V_2 , V_226 ) & 0xff ) ) ;
V_111 -> V_77 . V_154 . V_48 = V_50 ( V_2 ) ;
V_111 -> V_112 = 0 ;
break;
case V_414 :
V_111 -> type = V_340 ;
V_111 -> V_77 . V_154 . V_85 = V_2 -> V_44 ;
V_111 -> V_25 = V_2 -> V_104 + 2 ;
F_179 ( V_111 -> V_239 , V_111 -> V_25 , V_2 ) ;
break;
case V_415 :
V_2 -> V_392 . V_25 = V_2 -> V_104 + 2 ;
goto V_393;
case V_416 :
V_111 -> V_112 = V_296 ;
break;
case V_417 :
V_111 -> V_112 = V_97 ;
break;
case V_418 :
V_111 -> V_112 = V_39 ;
break;
case V_419 :
V_111 -> V_112 = V_142 ;
break;
case V_420 :
V_111 -> V_112 = V_51 ;
break;
case V_421 :
V_111 -> V_112 = V_193 ;
break;
case V_422 :
default:
V_111 -> type = V_200 ;
break;
}
V_155:
return V_91 ;
}
int F_180 ( struct V_1 * V_2 , void * V_423 , int V_424 )
{
int V_91 = V_89 ;
int V_36 = V_2 -> V_36 ;
int V_425 , V_426 , V_427 , V_428 ;
bool V_429 = false ;
struct V_430 V_430 ;
V_2 -> V_392 . type = V_200 ;
V_2 -> V_394 = NULL ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_79 . V_98 = V_2 -> V_44 ;
V_2 -> V_79 . V_96 = V_2 -> V_79 . V_98 + V_424 ;
if ( V_424 > 0 )
memcpy ( V_2 -> V_79 . V_90 , V_423 , V_424 ) ;
switch ( V_36 ) {
case V_87 :
case V_194 :
case V_218 :
V_425 = V_426 = 2 ;
break;
case V_217 :
V_425 = V_426 = 4 ;
break;
#ifdef F_49
case V_37 :
V_425 = 4 ;
V_426 = 8 ;
break;
#endif
default:
return V_330 ;
}
V_2 -> V_104 = V_425 ;
V_2 -> V_28 = V_426 ;
for (; ; ) {
switch ( V_2 -> V_123 = F_60 ( T_4 , V_2 ) ) {
case 0x66 :
V_429 = true ;
V_2 -> V_104 = V_425 ^ 6 ;
break;
case 0x67 :
if ( V_36 == V_37 )
V_2 -> V_28 = V_426 ^ 12 ;
else
V_2 -> V_28 = V_426 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_21 ( V_2 , ( V_2 -> V_123 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_21 ( V_2 , V_2 -> V_123 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_36 != V_37 )
goto V_431;
V_2 -> V_121 = V_2 -> V_123 ;
continue;
case 0xf0 :
V_2 -> V_198 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_123 ;
break;
default:
goto V_431;
}
V_2 -> V_121 = 0 ;
}
V_431:
if ( V_2 -> V_121 & 8 )
V_2 -> V_104 = 8 ;
V_430 = V_432 [ V_2 -> V_123 ] ;
if ( V_2 -> V_123 == 0x0f ) {
V_2 -> V_433 = 1 ;
V_2 -> V_123 = F_60 ( T_4 , V_2 ) ;
V_430 = V_434 [ V_2 -> V_123 ] ;
}
V_2 -> V_40 = V_430 . V_106 ;
if ( V_2 -> V_40 & V_122 )
V_2 -> V_141 = F_60 ( T_4 , V_2 ) ;
while ( V_2 -> V_40 & V_435 ) {
switch ( V_2 -> V_40 & V_435 ) {
case V_436 :
V_427 = ( V_2 -> V_141 >> 3 ) & 7 ;
V_430 = V_430 . V_437 . V_438 [ V_427 ] ;
break;
case V_439 :
V_427 = ( V_2 -> V_141 >> 3 ) & 7 ;
if ( ( V_2 -> V_141 >> 6 ) == 3 )
V_430 = V_430 . V_437 . V_440 -> V_441 [ V_427 ] ;
else
V_430 = V_430 . V_437 . V_440 -> V_442 [ V_427 ] ;
break;
case V_443 :
V_427 = V_2 -> V_141 & 7 ;
V_430 = V_430 . V_437 . V_438 [ V_427 ] ;
break;
case V_444 :
if ( V_2 -> V_17 && V_429 )
return V_330 ;
V_428 = V_429 ? 0x66 : V_2 -> V_17 ;
switch ( V_428 ) {
case 0x00 : V_430 = V_430 . V_437 . V_445 -> V_446 ; break;
case 0x66 : V_430 = V_430 . V_437 . V_445 -> V_447 ; break;
case 0xf2 : V_430 = V_430 . V_437 . V_445 -> V_448 ; break;
case 0xf3 : V_430 = V_430 . V_437 . V_445 -> V_449 ; break;
}
break;
case V_450 :
if ( V_2 -> V_141 > 0xbf )
V_430 = V_430 . V_437 . V_451 -> V_452 [ V_2 -> V_141 - 0xc0 ] ;
else
V_430 = V_430 . V_437 . V_451 -> V_111 [ ( V_2 -> V_141 >> 3 ) & 7 ] ;
break;
default:
return V_330 ;
}
V_2 -> V_40 &= ~ ( V_113 ) V_435 ;
V_2 -> V_40 |= V_430 . V_106 ;
}
V_2 -> V_453 = V_430 . V_437 . V_453 ;
V_2 -> V_454 = V_430 . V_454 ;
V_2 -> V_12 = V_430 . V_12 ;
if ( V_2 -> V_40 == 0 || ( V_2 -> V_40 & V_455 ) )
return V_330 ;
if ( ! ( V_2 -> V_40 & V_456 ) && V_2 -> V_457 )
return V_330 ;
if ( V_36 == V_37 && ( V_2 -> V_40 & V_458 ) )
V_2 -> V_104 = 8 ;
if ( V_2 -> V_40 & V_459 ) {
if ( V_36 == V_37 )
V_2 -> V_104 = 8 ;
else
V_2 -> V_104 = 4 ;
}
if ( V_2 -> V_40 & V_124 )
V_2 -> V_104 = 16 ;
else if ( V_2 -> V_40 & V_128 )
V_2 -> V_104 = 8 ;
if ( V_2 -> V_40 & V_122 ) {
V_91 = F_59 ( V_2 , & V_2 -> V_392 ) ;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_2 -> V_136 ) ;
} else if ( V_2 -> V_40 & V_460 )
V_91 = F_61 ( V_2 , & V_2 -> V_392 ) ;
if ( V_91 != V_89 )
goto V_155;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_142 ) ;
V_2 -> V_392 . V_77 . V_154 . V_48 = V_50 ( V_2 ) ;
if ( V_2 -> V_392 . type == V_143 && V_2 -> V_28 != 8 )
V_2 -> V_392 . V_77 . V_154 . V_85 = ( T_3 ) V_2 -> V_392 . V_77 . V_154 . V_85 ;
V_91 = F_178 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_40 >> V_461 ) & V_462 ) ;
if ( V_91 != V_89 )
goto V_155;
V_91 = F_178 ( V_2 , & V_2 -> V_223 , ( V_2 -> V_40 >> V_463 ) & V_462 ) ;
if ( V_91 != V_89 )
goto V_155;
V_91 = F_178 ( V_2 , & V_2 -> V_27 , ( V_2 -> V_40 >> V_464 ) & V_462 ) ;
V_155:
if ( V_2 -> V_394 && V_2 -> V_394 -> type == V_143 && V_2 -> V_153 )
V_2 -> V_394 -> V_77 . V_154 . V_85 += V_2 -> V_44 ;
return ( V_91 != V_89 ) ? V_330 : V_331 ;
}
bool F_181 ( struct V_1 * V_2 )
{
return V_2 -> V_40 & V_465 ;
}
static bool F_182 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_123 == 0xa6 ) || ( V_2 -> V_123 == 0xa7 ) ||
( V_2 -> V_123 == 0xae ) || ( V_2 -> V_123 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_466 ) &&
( ( V_2 -> V_172 & V_209 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_467 ) &&
( ( V_2 -> V_172 & V_209 ) == V_209 ) ) ) )
return true ;
return false ;
}
static int F_183 ( struct V_1 * V_2 )
{
bool V_468 = false ;
V_2 -> V_6 -> V_114 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_115 ( V_2 ) ;
if ( F_41 ( V_468 ) )
return F_23 ( V_2 , V_469 , 0 , false ) ;
return V_89 ;
}
static void F_184 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
if ( V_111 -> type == V_129 )
F_52 ( V_2 , & V_111 -> V_199 , V_111 -> V_77 . V_130 ) ;
}
static int F_103 ( struct V_1 * V_2 , void (* F_46)( struct F_103 * ) )
{
T_1 V_106 = ( V_2 -> V_172 & V_108 ) | V_109 ;
if ( ! ( V_2 -> V_40 & V_132 ) )
F_46 += F_185 ( V_2 -> V_27 . V_25 ) * V_470 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_172 = ( V_2 -> V_172 & ~ V_108 ) | ( V_106 & V_108 ) ;
if ( ! F_46 )
return F_29 ( V_2 ) ;
return V_89 ;
}
int F_186 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
int V_91 = V_89 ;
int V_471 = V_2 -> V_27 . type ;
V_2 -> V_160 . V_161 = 0 ;
if ( ( V_2 -> V_36 == V_37 && ( V_2 -> V_40 & V_472 ) ) ||
( V_2 -> V_40 & V_473 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_198 && ( ! ( V_2 -> V_40 & V_474 ) || V_2 -> V_27 . type != V_143 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & V_475 ) == V_476 && V_2 -> V_22 . type != V_143 ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( ( V_2 -> V_40 & ( V_124 | V_128 ) ) && ( ( V_6 -> V_116 ( V_2 , 0 ) & V_118 ) ) )
|| ( ( V_2 -> V_40 & V_124 ) && ! ( V_6 -> V_116 ( V_2 , 4 ) & V_477 ) ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & ( V_124 | V_128 ) ) && ( V_6 -> V_116 ( V_2 , 0 ) & V_117 ) ) {
V_91 = F_30 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_40 & V_128 ) {
V_91 = F_183 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
F_184 ( V_2 , & V_2 -> V_22 ) ;
F_184 ( V_2 , & V_2 -> V_223 ) ;
if ( ! ( V_2 -> V_40 & V_478 ) )
F_184 ( V_2 , & V_2 -> V_27 ) ;
}
if ( F_41 ( V_2 -> V_479 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_480 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( ( V_2 -> V_40 & V_481 ) && V_6 -> V_84 ( V_2 ) ) {
V_91 = F_25 ( V_2 , 0 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & V_482 ) && V_2 -> V_36 < V_218 ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_454 ) {
V_91 = V_2 -> V_454 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( F_41 ( V_2 -> V_479 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_483 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) == 0 ) {
V_2 -> V_30 = V_2 -> V_44 ;
goto V_155;
}
}
if ( ( V_2 -> V_22 . type == V_143 ) && ! ( V_2 -> V_40 & V_484 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_22 . V_77 . V_154 ,
V_2 -> V_22 . V_239 , V_2 -> V_22 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
V_2 -> V_22 . V_242 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_223 . type == V_143 ) {
V_91 = F_65 ( V_2 , V_2 -> V_223 . V_77 . V_154 ,
& V_2 -> V_223 . V_112 , V_2 -> V_223 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( ( V_2 -> V_40 & V_485 ) == V_486 )
goto V_487;
if ( ( V_2 -> V_27 . type == V_143 ) && ! ( V_2 -> V_40 & V_478 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_27 . V_77 . V_154 ,
& V_2 -> V_27 . V_112 , V_2 -> V_27 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
}
V_2 -> V_27 . V_133 = V_2 -> V_27 . V_112 ;
V_487:
if ( F_41 ( V_2 -> V_479 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_488 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( V_2 -> V_453 ) {
if ( V_2 -> V_40 & V_489 ) {
void (* F_46)( struct F_103 * ) = ( void * ) V_2 -> V_453 ;
V_91 = F_103 ( V_2 , F_46 ) ;
if ( V_91 != V_89 )
goto V_155;
goto F_78;
}
V_91 = V_2 -> V_453 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
goto F_78;
}
if ( V_2 -> V_433 )
goto V_490;
switch ( V_2 -> V_123 ) {
case 0x63 :
if ( V_2 -> V_36 != V_37 )
goto V_491;
V_2 -> V_27 . V_112 = ( V_152 ) V_2 -> V_22 . V_112 ;
break;
case 0x70 ... 0x7f :
if ( F_45 ( V_2 -> V_123 , V_2 -> V_172 ) )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
break;
case 0x8d :
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_77 . V_154 . V_85 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_27 . V_77 . V_9 == F_3 ( V_2 , V_226 ) )
break;
V_91 = F_129 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_104 ) {
case 2 : V_2 -> V_27 . V_112 = ( V_151 ) V_2 -> V_27 . V_112 ; break;
case 4 : V_2 -> V_27 . V_112 = ( V_157 ) V_2 -> V_27 . V_112 ; break;
case 8 : V_2 -> V_27 . V_112 = ( V_152 ) V_2 -> V_27 . V_112 ; break;
}
break;
case 0xcc :
V_91 = F_94 ( V_2 , 3 ) ;
break;
case 0xcd :
V_91 = F_94 ( V_2 , V_2 -> V_22 . V_112 ) ;
break;
case 0xce :
if ( V_2 -> V_172 & V_211 )
V_91 = F_94 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
V_2 -> V_27 . type = V_200 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_492 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_172 ^= V_206 ;
break;
case 0xf8 :
V_2 -> V_172 &= ~ V_206 ;
break;
case 0xf9 :
V_2 -> V_172 |= V_206 ;
break;
case 0xfc :
V_2 -> V_172 &= ~ V_173 ;
break;
case 0xfd :
V_2 -> V_172 |= V_173 ;
break;
default:
goto V_491;
}
if ( V_91 != V_89 )
goto V_155;
F_78:
if ( ! ( V_2 -> V_40 & V_493 ) ) {
V_91 = F_78 ( V_2 , & V_2 -> V_27 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( V_2 -> V_40 & V_494 ) {
F_187 ( V_2 -> V_22 . type == V_143 || V_2 -> V_22 . type == V_174 ) ;
V_91 = F_78 ( V_2 , & V_2 -> V_22 ) ;
if ( V_91 != V_89 )
goto V_155;
}
V_2 -> V_27 . type = V_471 ;
if ( ( V_2 -> V_40 & V_475 ) == V_495 )
F_122 ( V_2 , V_148 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_40 & V_485 ) == V_496 )
F_122 ( V_2 , V_150 , & V_2 -> V_27 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
unsigned int V_170 ;
struct V_158 * V_280 = & V_2 -> V_167 ;
if ( ( V_2 -> V_40 & V_475 ) == V_495 )
V_170 = V_2 -> V_22 . V_170 ;
else
V_170 = V_2 -> V_27 . V_170 ;
F_16 ( V_2 , F_3 ( V_2 , V_171 ) ,
- V_170 ) ;
if ( ! F_182 ( V_2 ) ) {
if ( ( V_280 -> V_96 != 0 || F_1 ( V_2 , V_171 ) & 0x3ff ) &&
( V_280 -> V_96 == 0 || V_280 -> V_96 != V_280 -> V_161 ) ) {
V_2 -> V_160 . V_96 = 0 ;
F_4 ( V_2 ) ;
return V_497 ;
}
goto V_155;
}
}
V_2 -> V_30 = V_2 -> V_44 ;
V_155:
if ( V_91 == V_59 )
V_2 -> V_498 = true ;
if ( V_91 == V_499 )
return V_500 ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return ( V_91 == V_100 ) ? V_330 : V_331 ;
V_490:
switch ( V_2 -> V_123 ) {
case 0x09 :
( V_2 -> V_6 -> V_501 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_27 . V_112 = V_6 -> V_116 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_379 ( V_2 , V_2 -> V_19 , & V_2 -> V_27 . V_112 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_27 . V_112 = V_2 -> V_27 . V_133 = V_2 -> V_22 . V_112 ;
if ( ! F_45 ( V_2 -> V_123 , V_2 -> V_172 ) )
V_2 -> V_27 . type = V_200 ;
break;
case 0x80 ... 0x8f :
if ( F_45 ( V_2 -> V_123 , V_2 -> V_172 ) )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_27 . V_112 = F_45 ( V_2 -> V_123 , V_2 -> V_172 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_2 -> V_27 . V_112 = ( V_2 -> V_22 . V_25 == 1 ) ? ( T_4 ) V_2 -> V_22 . V_112
: ( T_2 ) V_2 -> V_22 . V_112 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_2 -> V_27 . V_112 = ( V_2 -> V_22 . V_25 == 1 ) ? ( V_151 ) V_2 -> V_22 . V_112 :
( V_157 ) V_2 -> V_22 . V_112 ;
break;
case 0xc3 :
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_2 -> V_27 . V_112 = ( V_2 -> V_104 == 4 ) ? ( T_3 ) V_2 -> V_22 . V_112 :
( V_113 ) V_2 -> V_22 . V_112 ;
break;
default:
goto V_491;
}
if ( V_91 != V_89 )
goto V_155;
goto F_78;
V_491:
return V_330 ;
}
void F_188 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_189 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
