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
V_111 -> type = V_131 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_43 ( V_2 , V_2 -> V_20 , V_2 -> V_40 & V_132 ) ;
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
if ( ( V_48 <= V_192 && V_2 -> V_36 == V_193 )
|| V_2 -> V_36 == V_87 ) {
V_2 -> V_6 -> V_38 ( V_2 , & V_69 , & V_184 , NULL , V_48 ) ;
F_75 ( & V_184 , V_68 << 4 ) ;
goto V_194;
}
V_186 = V_68 & 3 ;
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( ( V_48 == V_97
|| ( V_48 == V_39
&& ( V_2 -> V_36 != V_37 || V_186 != V_84 ) )
|| V_48 == V_195 )
&& V_189 )
goto V_55;
if ( V_48 == V_195 && ( V_68 & ( 1 << 2 ) ) )
goto V_55;
if ( V_189 )
goto V_194;
V_191 = F_72 ( V_2 , V_68 , & V_184 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_188 = V_68 & 0xfffc ;
V_187 = V_62 ;
if ( V_48 <= V_192 && ! V_184 . V_196 )
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
case V_195 :
if ( V_184 . V_196 || ( V_184 . type != 1 && V_184 . type != 9 ) )
goto V_55;
V_185 = V_184 ;
V_184 . type |= 2 ;
V_191 = V_2 -> V_6 -> V_165 ( V_2 , V_190 , & V_185 , & V_184 ,
sizeof( V_184 ) , & V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
break;
case V_180 :
if ( V_184 . V_196 || V_184 . type != 2 )
goto V_55;
break;
default:
if ( ( V_184 . type & 0xa ) == 0x8 ||
( ( ( V_184 . type & 0xc ) != 0xc ) &&
( V_186 > V_88 && V_84 > V_88 ) ) )
goto V_55;
break;
}
if ( V_184 . V_196 ) {
V_184 . type |= 1 ;
V_191 = F_73 ( V_2 , V_68 , & V_184 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
V_194:
V_2 -> V_6 -> V_71 ( V_2 , V_68 , & V_184 , 0 , V_48 ) ;
return V_89 ;
V_55:
F_23 ( V_2 , V_187 , V_188 , true ) ;
return V_59 ;
}
static void F_76 ( struct V_110 * V_111 )
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
static int F_77 ( struct V_1 * V_2 )
{
int V_91 ;
if ( V_2 -> V_40 & V_198 )
return V_89 ;
switch ( V_2 -> V_27 . type ) {
case V_131 :
F_76 ( & V_2 -> V_27 ) ;
break;
case V_143 :
if ( V_2 -> V_199 )
V_91 = F_67 ( V_2 ,
V_2 -> V_27 . V_77 . V_154 ,
& V_2 -> V_27 . V_133 ,
& V_2 -> V_27 . V_112 ,
V_2 -> V_27 . V_25 ) ;
else
V_91 = F_66 ( V_2 ,
V_2 -> V_27 . V_77 . V_154 ,
& V_2 -> V_27 . V_112 ,
V_2 -> V_27 . V_25 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_174 :
V_91 = F_66 ( V_2 ,
V_2 -> V_27 . V_77 . V_154 ,
V_2 -> V_27 . V_90 ,
V_2 -> V_27 . V_25 * V_2 -> V_27 . V_170 ) ;
if ( V_91 != V_89 )
return V_91 ;
break;
case V_125 :
F_51 ( V_2 , & V_2 -> V_27 . V_127 , V_2 -> V_27 . V_77 . V_126 ) ;
break;
case V_129 :
F_53 ( V_2 , & V_2 -> V_27 . V_200 , V_2 -> V_27 . V_77 . V_130 ) ;
break;
case V_201 :
break;
default:
break;
}
return V_89 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_90 , int V_25 )
{
struct V_76 V_77 ;
F_17 ( V_2 , - V_25 ) ;
V_77 . V_85 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
return F_66 ( V_2 , V_77 , V_90 , V_25 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_201 ;
return F_78 ( V_2 , & V_2 -> V_22 . V_112 , V_2 -> V_104 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
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
static int F_81 ( struct V_1 * V_2 )
{
return F_80 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
void * V_31 , int V_202 )
{
int V_91 ;
unsigned long V_112 , V_203 ;
int V_204 = ( V_2 -> V_172 & V_205 ) >> V_206 ;
int V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
V_91 = F_80 ( V_2 , & V_112 , V_202 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_203 = V_207 | V_208 | V_209 | V_210 | V_211 | V_212
| V_213 | V_173 | V_214 | V_215 | V_216 | V_217 ;
switch( V_2 -> V_36 ) {
case V_37 :
case V_218 :
case V_219 :
if ( V_84 == 0 )
V_203 |= V_220 ;
if ( V_84 <= V_204 )
V_203 |= V_221 ;
break;
case V_193 :
if ( V_204 < 3 )
return F_25 ( V_2 , 0 ) ;
V_203 |= V_221 ;
break;
default:
V_203 |= ( V_220 | V_221 ) ;
break;
}
* ( unsigned long * ) V_31 =
( V_2 -> V_172 & ~ V_203 ) | ( V_112 & V_203 ) ;
return V_91 ;
}
static int F_83 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_172 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
return F_82 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned V_222 = V_2 -> V_22 . V_112 ;
unsigned V_223 = V_2 -> V_224 . V_112 & 31 ;
T_1 V_225 ;
if ( V_223 )
return V_100 ;
V_225 = F_1 ( V_2 , V_135 ) ;
V_91 = F_78 ( V_2 , & V_225 , F_11 ( V_2 ) ) ;
if ( V_91 != V_89 )
return V_91 ;
F_8 ( F_3 ( V_2 , V_135 ) , F_1 ( V_2 , V_42 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_42 ) ,
F_1 ( V_2 , V_42 ) - V_222 ,
F_10 ( V_2 ) ) ;
return V_89 ;
}
static int F_85 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_42 ) , F_1 ( V_2 , V_135 ) ,
F_10 ( V_2 ) ) ;
return F_80 ( V_2 , F_3 ( V_2 , V_135 ) , V_2 -> V_104 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_112 ;
V_2 -> V_22 . V_112 = F_31 ( V_2 , V_48 ) ;
return F_79 ( V_2 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_112 ;
unsigned long V_68 ;
int V_91 ;
V_91 = F_80 ( V_2 , & V_68 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_68 , V_48 ) ;
return V_91 ;
}
static int F_88 ( struct V_1 * V_2 )
{
unsigned long V_226 = F_1 ( V_2 , V_42 ) ;
int V_91 = V_89 ;
int V_9 = V_227 ;
while ( V_9 <= V_150 ) {
( V_9 == V_42 ) ?
( V_2 -> V_22 . V_112 = V_226 ) : ( V_2 -> V_22 . V_112 = F_1 ( V_2 , V_9 ) ) ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
++ V_9 ;
}
return V_91 ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_112 = ( unsigned long ) V_2 -> V_172 ;
return F_79 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
int V_9 = V_150 ;
while ( V_9 >= V_227 ) {
if ( V_9 == V_42 ) {
F_17 ( V_2 , V_2 -> V_104 ) ;
-- V_9 ;
}
V_91 = F_80 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
break;
-- V_9 ;
}
return V_91 ;
}
static int F_91 ( struct V_1 * V_2 , int V_228 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
int V_91 ;
struct V_176 V_177 ;
T_6 V_229 ;
T_6 V_230 ;
T_2 V_231 , V_30 ;
V_2 -> V_22 . V_112 = V_2 -> V_172 ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_172 &= ~ ( V_221 | V_213 | V_216 ) ;
V_2 -> V_22 . V_112 = F_31 ( V_2 , V_97 ) ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_112 = V_2 -> V_44 ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_6 -> V_178 ( V_2 , & V_177 ) ;
V_230 = V_177 . V_103 + ( V_228 << 2 ) ;
V_229 = V_177 . V_103 + ( V_228 << 2 ) + 2 ;
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
int F_92 ( struct V_1 * V_2 , int V_228 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_91 = F_91 ( V_2 , V_228 ) ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return V_91 ;
}
static int F_93 ( struct V_1 * V_2 , int V_228 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_91 ( V_2 , V_228 ) ;
case V_193 :
case V_219 :
case V_218 :
case V_37 :
default:
return V_100 ;
}
}
static int F_94 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
unsigned long V_232 = 0 ;
unsigned long V_233 = 0 ;
unsigned long V_231 = 0 ;
unsigned long V_32 = V_207 | V_208 | V_209 | V_210 | V_211 | V_213 |
V_221 | V_173 | V_212 | V_220 | V_214 | V_215 |
V_216 | V_217 | ( 1 << 1 ) ;
unsigned long V_234 = V_235 | V_236 | V_237 ;
V_91 = F_80 ( V_2 , & V_232 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_232 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_91 = F_80 ( V_2 , & V_231 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_80 ( V_2 , & V_233 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_231 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = V_232 ;
if ( V_2 -> V_104 == 4 )
V_2 -> V_172 = ( ( V_233 & V_32 ) | ( V_2 -> V_172 & V_234 ) ) ;
else if ( V_2 -> V_104 == 2 ) {
V_2 -> V_172 &= ~ 0xffff ;
V_2 -> V_172 |= V_233 ;
}
V_2 -> V_172 &= ~ V_238 ;
V_2 -> V_172 |= V_239 ;
return V_91 ;
}
static int F_95 ( struct V_1 * V_2 )
{
switch( V_2 -> V_36 ) {
case V_87 :
return F_94 ( V_2 ) ;
case V_193 :
case V_219 :
case V_218 :
case V_37 :
default:
return V_100 ;
}
}
static int F_96 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned short V_33 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_104 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_97 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_240 , V_2 -> V_104 ) ;
return V_89 ;
}
static int F_97 ( struct V_1 * V_2 )
{
T_4 V_241 = 0 ;
F_98 ( V_2 , L_1 , V_241 ) ;
return V_89 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_4 V_241 = 0 ;
F_98 ( V_2 , L_2 , V_241 ) ;
return V_89 ;
}
static int F_100 ( struct V_1 * V_2 )
{
T_4 V_242 = 0 ;
F_98 ( V_2 , L_3 , V_242 ) ;
if ( V_242 )
return F_29 ( V_2 ) ;
return V_89 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_4 V_242 = 0 ;
F_98 ( V_2 , L_4 , V_242 ) ;
if ( V_242 )
return F_29 ( V_2 ) ;
return V_89 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
switch ( V_2 -> V_19 ) {
case 2 : {
long int V_243 ;
V_243 = V_2 -> V_44 ;
V_2 -> V_44 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = V_243 ;
V_91 = F_79 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_44 = V_2 -> V_22 . V_112 ;
break;
case 5 :
V_91 = F_96 ( V_2 ) ;
break;
case 6 :
V_91 = F_79 ( V_2 ) ;
break;
}
return V_91 ;
}
static int F_103 ( struct V_1 * V_2 )
{
V_113 V_244 = V_2 -> V_27 . V_245 ;
if ( ( ( T_3 ) ( V_244 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_227 ) ) ||
( ( T_3 ) ( V_244 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_246 ) ) ) {
* F_2 ( V_2 , V_227 ) = ( T_3 ) ( V_244 >> 0 ) ;
* F_2 ( V_2 , V_246 ) = ( T_3 ) ( V_244 >> 32 ) ;
V_2 -> V_172 &= ~ V_210 ;
} else {
V_2 -> V_27 . V_23 = ( ( V_113 ) F_1 ( V_2 , V_171 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_145 ) ;
V_2 -> V_172 |= V_210 ;
}
return V_89 ;
}
static int F_104 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
return F_81 ( V_2 ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_231 ;
V_91 = F_80 ( V_2 , & V_2 -> V_44 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_104 == 4 )
V_2 -> V_44 = ( T_3 ) V_2 -> V_44 ;
V_91 = F_80 ( V_2 , & V_231 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_74 ( V_2 , ( T_2 ) V_231 , V_97 ) ;
return V_91 ;
}
static int F_106 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_133 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = F_1 ( V_2 , V_227 ) ;
F_107 ( V_2 , V_247 ) ;
if ( V_2 -> V_172 & V_210 ) {
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_133 ;
} else {
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_227 ) ;
}
return V_89 ;
}
static int F_108 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_224 . V_112 ;
unsigned short V_33 ;
int V_91 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_104 , 2 ) ;
V_91 = F_74 ( V_2 , V_33 , V_48 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_112 ;
return V_91 ;
}
static void
F_109 ( struct V_1 * V_2 ,
struct V_34 * V_231 , struct V_34 * V_35 )
{
V_231 -> V_248 = 0 ;
F_75 ( V_231 , 0 ) ;
V_231 -> V_47 = 1 ;
F_110 ( V_231 , 0xfffff ) ;
V_231 -> type = 0x0b ;
V_231 -> V_196 = 1 ;
V_231 -> V_88 = 0 ;
V_231 -> V_102 = 1 ;
V_231 -> V_40 = 1 ;
V_231 -> V_249 = 0 ;
F_75 ( V_35 , 0 ) ;
F_110 ( V_35 , 0xfffff ) ;
V_35 -> V_47 = 1 ;
V_35 -> V_196 = 1 ;
V_35 -> type = 0x03 ;
V_35 -> V_40 = 1 ;
V_35 -> V_88 = 0 ;
V_35 -> V_102 = 1 ;
V_35 -> V_248 = 0 ;
V_35 -> V_249 = 0 ;
}
static bool F_111 ( struct V_1 * V_2 )
{
T_3 V_250 , V_251 , V_252 , V_253 ;
V_250 = V_252 = 0 ;
V_2 -> V_6 -> V_254 ( V_2 , & V_250 , & V_251 , & V_252 , & V_253 ) ;
return V_251 == V_255
&& V_252 == V_256
&& V_253 == V_257 ;
}
static bool F_112 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
T_3 V_250 , V_251 , V_252 , V_253 ;
if ( V_2 -> V_36 == V_37 )
return true ;
V_250 = 0x00000000 ;
V_252 = 0x00000000 ;
V_6 -> V_254 ( V_2 , & V_250 , & V_251 , & V_252 , & V_253 ) ;
if ( V_251 == V_255 &&
V_252 == V_256 &&
V_253 == V_257 )
return false ;
if ( V_251 == V_258 &&
V_252 == V_259 &&
V_253 == V_260 )
return true ;
if ( V_251 == V_261 &&
V_252 == V_262 &&
V_253 == V_263 )
return true ;
return false ;
}
static int F_113 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_113 V_264 ;
T_2 V_265 , V_266 ;
V_113 V_267 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_193 )
return F_27 ( V_2 ) ;
if ( ! ( F_112 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
F_109 ( V_2 , & V_231 , & V_35 ) ;
if ( ! ( V_267 & V_270 ) )
return F_27 ( V_2 ) ;
V_6 -> V_268 ( V_2 , V_271 , & V_264 ) ;
V_264 >>= 32 ;
V_265 = ( T_2 ) ( V_264 & 0xfffc ) ;
V_266 = ( T_2 ) ( V_264 + 8 ) ;
if ( V_267 & V_272 ) {
V_231 . V_40 = 0 ;
V_231 . V_248 = 1 ;
}
V_6 -> V_71 ( V_2 , V_265 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_266 , & V_35 , 0 , V_39 ) ;
* F_2 ( V_2 , V_171 ) = V_2 -> V_44 ;
if ( V_267 & V_272 ) {
#ifdef F_49
* F_2 ( V_2 , V_273 ) = V_2 -> V_172 & ~ V_215 ;
V_6 -> V_268 ( V_2 ,
V_2 -> V_36 == V_37 ?
V_274 : V_275 , & V_264 ) ;
V_2 -> V_44 = V_264 ;
V_6 -> V_268 ( V_2 , V_276 , & V_264 ) ;
V_2 -> V_172 &= ~ ( V_264 | V_215 ) ;
#endif
} else {
V_6 -> V_268 ( V_2 , V_271 , & V_264 ) ;
V_2 -> V_44 = ( T_3 ) V_264 ;
V_2 -> V_172 &= ~ ( V_235 | V_221 | V_215 ) ;
}
return V_89 ;
}
static int F_114 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_113 V_264 ;
T_2 V_265 , V_266 ;
V_113 V_267 = 0 ;
V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
if ( V_2 -> V_36 == V_87 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_36 == V_218 ) && ( V_267 & V_272 )
&& ! F_111 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_36 == V_37 )
return F_27 ( V_2 ) ;
F_109 ( V_2 , & V_231 , & V_35 ) ;
V_6 -> V_268 ( V_2 , V_277 , & V_264 ) ;
switch ( V_2 -> V_36 ) {
case V_218 :
if ( ( V_264 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
case V_37 :
if ( V_264 == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_172 &= ~ ( V_235 | V_221 | V_215 ) ;
V_265 = ( T_2 ) V_264 ;
V_265 &= ~ V_278 ;
V_266 = V_265 + 8 ;
V_266 &= ~ V_278 ;
if ( V_2 -> V_36 == V_37 || ( V_267 & V_272 ) ) {
V_231 . V_40 = 0 ;
V_231 . V_248 = 1 ;
}
V_6 -> V_71 ( V_2 , V_265 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_266 , & V_35 , 0 , V_39 ) ;
V_6 -> V_268 ( V_2 , V_279 , & V_264 ) ;
V_2 -> V_44 = V_264 ;
V_6 -> V_268 ( V_2 , V_280 , & V_264 ) ;
* F_2 ( V_2 , V_42 ) = V_264 ;
return V_89 ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_231 , V_35 ;
V_113 V_264 ;
int V_281 ;
T_2 V_265 = 0 , V_266 = 0 ;
if ( V_2 -> V_36 == V_87 ||
V_2 -> V_36 == V_193 )
return F_25 ( V_2 , 0 ) ;
F_109 ( V_2 , & V_231 , & V_35 ) ;
if ( ( V_2 -> V_121 & 0x8 ) != 0x0 )
V_281 = V_37 ;
else
V_281 = V_218 ;
V_231 . V_88 = 3 ;
V_35 . V_88 = 3 ;
V_6 -> V_268 ( V_2 , V_277 , & V_264 ) ;
switch ( V_281 ) {
case V_218 :
V_265 = ( T_2 ) ( V_264 + 16 ) ;
if ( ( V_264 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_266 = ( T_2 ) ( V_264 + 24 ) ;
break;
case V_37 :
V_265 = ( T_2 ) ( V_264 + 32 ) ;
if ( V_264 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_266 = V_265 + 8 ;
V_231 . V_40 = 0 ;
V_231 . V_248 = 1 ;
break;
}
V_265 |= V_278 ;
V_266 |= V_278 ;
V_6 -> V_71 ( V_2 , V_265 , & V_231 , 0 , V_97 ) ;
V_6 -> V_71 ( V_2 , V_266 , & V_35 , 0 , V_39 ) ;
V_2 -> V_44 = F_1 ( V_2 , V_246 ) ;
* F_2 ( V_2 , V_42 ) = F_1 ( V_2 , V_171 ) ;
return V_89 ;
}
static bool F_116 ( struct V_1 * V_2 )
{
int V_204 ;
if ( V_2 -> V_36 == V_87 )
return false ;
if ( V_2 -> V_36 == V_193 )
return true ;
V_204 = ( V_2 -> V_172 & V_205 ) >> V_206 ;
return V_2 -> V_6 -> V_84 ( V_2 ) > V_204 ;
}
static bool F_117 ( struct V_1 * V_2 ,
T_2 V_166 , T_2 V_202 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_282 ;
T_3 V_70 ;
int V_283 ;
T_2 V_284 , V_285 , V_286 , V_287 = V_166 & 0x7 ;
unsigned V_32 = ( 1 << V_202 ) - 1 ;
unsigned long V_288 ;
V_6 -> V_38 ( V_2 , & V_284 , & V_282 , & V_70 , V_195 ) ;
if ( ! V_282 . V_102 )
return false ;
if ( F_19 ( & V_282 ) < 103 )
return false ;
V_288 = F_71 ( & V_282 ) ;
#ifdef F_49
V_288 |= ( ( V_113 ) V_70 ) << 32 ;
#endif
V_283 = V_6 -> V_92 ( V_2 , V_288 + 102 , & V_285 , 2 , NULL ) ;
if ( V_283 != V_89 )
return false ;
if ( V_285 + V_166 / 8 > F_19 ( & V_282 ) )
return false ;
V_283 = V_6 -> V_92 ( V_2 , V_288 + V_285 + V_166 / 8 , & V_286 , 2 , NULL ) ;
if ( V_283 != V_89 )
return false ;
if ( ( V_286 >> V_287 ) & V_32 )
return false ;
return true ;
}
static bool F_118 ( struct V_1 * V_2 ,
T_2 V_166 , T_2 V_202 )
{
if ( V_2 -> V_289 )
return true ;
if ( F_116 ( V_2 ) )
if ( ! F_117 ( V_2 , V_166 , V_202 ) )
return false ;
V_2 -> V_289 = true ;
return true ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
V_291 -> V_292 = V_2 -> V_44 ;
V_291 -> V_293 = V_2 -> V_172 ;
V_291 -> V_294 = F_1 ( V_2 , V_227 ) ;
V_291 -> V_295 = F_1 ( V_2 , V_171 ) ;
V_291 -> V_296 = F_1 ( V_2 , V_246 ) ;
V_291 -> V_144 = F_1 ( V_2 , V_145 ) ;
V_291 -> V_297 = F_1 ( V_2 , V_42 ) ;
V_291 -> V_146 = F_1 ( V_2 , V_135 ) ;
V_291 -> V_147 = F_1 ( V_2 , V_148 ) ;
V_291 -> V_149 = F_1 ( V_2 , V_150 ) ;
V_291 -> V_298 = F_31 ( V_2 , V_299 ) ;
V_291 -> V_231 = F_31 ( V_2 , V_97 ) ;
V_291 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_291 -> V_300 = F_31 ( V_2 , V_142 ) ;
V_291 -> V_301 = F_31 ( V_2 , V_180 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_290 * V_291 )
{
int V_191 ;
V_2 -> V_44 = V_291 -> V_292 ;
V_2 -> V_172 = V_291 -> V_293 | 2 ;
* F_2 ( V_2 , V_227 ) = V_291 -> V_294 ;
* F_2 ( V_2 , V_171 ) = V_291 -> V_295 ;
* F_2 ( V_2 , V_246 ) = V_291 -> V_296 ;
* F_2 ( V_2 , V_145 ) = V_291 -> V_144 ;
* F_2 ( V_2 , V_42 ) = V_291 -> V_297 ;
* F_2 ( V_2 , V_135 ) = V_291 -> V_146 ;
* F_2 ( V_2 , V_148 ) = V_291 -> V_147 ;
* F_2 ( V_2 , V_150 ) = V_291 -> V_149 ;
F_32 ( V_2 , V_291 -> V_301 , V_180 ) ;
F_32 ( V_2 , V_291 -> V_298 , V_299 ) ;
F_32 ( V_2 , V_291 -> V_231 , V_97 ) ;
F_32 ( V_2 , V_291 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_291 -> V_300 , V_142 ) ;
V_191 = F_74 ( V_2 , V_291 -> V_301 , V_180 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_298 , V_299 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_231 , V_97 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_35 , V_39 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_300 , V_142 ) ;
if ( V_191 != V_89 )
return V_191 ;
return V_89 ;
}
static int F_121 ( struct V_1 * V_2 ,
T_2 V_302 , T_2 V_303 ,
T_1 V_304 , struct V_34 * V_305 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_290 V_306 ;
int V_191 ;
T_3 V_307 = F_71 ( V_305 ) ;
V_191 = V_6 -> V_92 ( V_2 , V_304 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
F_119 ( V_2 , & V_306 ) ;
V_191 = V_6 -> V_183 ( V_2 , V_304 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = V_6 -> V_92 ( V_2 , V_307 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_303 != 0xffff ) {
V_306 . V_308 = V_303 ;
V_191 = V_6 -> V_183 ( V_2 , V_307 ,
& V_306 . V_308 ,
sizeof V_306 . V_308 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
return F_120 ( V_2 , & V_306 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_309 * V_291 )
{
V_291 -> V_310 = V_2 -> V_6 -> V_116 ( V_2 , 3 ) ;
V_291 -> V_30 = V_2 -> V_44 ;
V_291 -> V_172 = V_2 -> V_172 ;
V_291 -> V_250 = F_1 ( V_2 , V_227 ) ;
V_291 -> V_252 = F_1 ( V_2 , V_171 ) ;
V_291 -> V_253 = F_1 ( V_2 , V_246 ) ;
V_291 -> V_251 = F_1 ( V_2 , V_145 ) ;
V_291 -> V_311 = F_1 ( V_2 , V_42 ) ;
V_291 -> V_312 = F_1 ( V_2 , V_135 ) ;
V_291 -> V_313 = F_1 ( V_2 , V_148 ) ;
V_291 -> V_314 = F_1 ( V_2 , V_150 ) ;
V_291 -> V_298 = F_31 ( V_2 , V_299 ) ;
V_291 -> V_231 = F_31 ( V_2 , V_97 ) ;
V_291 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_291 -> V_300 = F_31 ( V_2 , V_142 ) ;
V_291 -> V_315 = F_31 ( V_2 , V_51 ) ;
V_291 -> V_316 = F_31 ( V_2 , V_192 ) ;
V_291 -> V_317 = F_31 ( V_2 , V_180 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_309 * V_291 )
{
int V_191 ;
if ( V_2 -> V_6 -> V_318 ( V_2 , 3 , V_291 -> V_310 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_44 = V_291 -> V_30 ;
V_2 -> V_172 = V_291 -> V_172 | 2 ;
* F_2 ( V_2 , V_227 ) = V_291 -> V_250 ;
* F_2 ( V_2 , V_171 ) = V_291 -> V_252 ;
* F_2 ( V_2 , V_246 ) = V_291 -> V_253 ;
* F_2 ( V_2 , V_145 ) = V_291 -> V_251 ;
* F_2 ( V_2 , V_42 ) = V_291 -> V_311 ;
* F_2 ( V_2 , V_135 ) = V_291 -> V_312 ;
* F_2 ( V_2 , V_148 ) = V_291 -> V_313 ;
* F_2 ( V_2 , V_150 ) = V_291 -> V_314 ;
F_32 ( V_2 , V_291 -> V_317 , V_180 ) ;
F_32 ( V_2 , V_291 -> V_298 , V_299 ) ;
F_32 ( V_2 , V_291 -> V_231 , V_97 ) ;
F_32 ( V_2 , V_291 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_291 -> V_300 , V_142 ) ;
F_32 ( V_2 , V_291 -> V_315 , V_51 ) ;
F_32 ( V_2 , V_291 -> V_316 , V_192 ) ;
if ( V_2 -> V_172 & V_319 )
V_2 -> V_36 = V_193 ;
else
V_2 -> V_36 = V_218 ;
V_2 -> V_6 -> V_320 ( V_2 , V_2 -> V_172 ) ;
V_191 = F_74 ( V_2 , V_291 -> V_317 , V_180 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_298 , V_299 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_231 , V_97 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_35 , V_39 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_300 , V_142 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_315 , V_51 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_74 ( V_2 , V_291 -> V_316 , V_192 ) ;
if ( V_191 != V_89 )
return V_191 ;
return V_89 ;
}
static int F_124 ( struct V_1 * V_2 ,
T_2 V_302 , T_2 V_303 ,
T_1 V_304 , struct V_34 * V_305 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_309 V_306 ;
int V_191 ;
T_3 V_307 = F_71 ( V_305 ) ;
V_191 = V_6 -> V_92 ( V_2 , V_304 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
F_122 ( V_2 , & V_306 ) ;
V_191 = V_6 -> V_183 ( V_2 , V_304 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = V_6 -> V_92 ( V_2 , V_307 , & V_306 , sizeof V_306 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_303 != 0xffff ) {
V_306 . V_308 = V_303 ;
V_191 = V_6 -> V_183 ( V_2 , V_307 ,
& V_306 . V_308 ,
sizeof V_306 . V_308 ,
& V_2 -> V_55 ) ;
if ( V_191 != V_89 )
return V_191 ;
}
return F_123 ( V_2 , & V_306 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
T_2 V_302 , int V_321 , int V_322 ,
bool V_323 , T_3 V_57 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
struct V_34 V_324 , V_325 ;
int V_191 ;
T_2 V_303 = F_31 ( V_2 , V_195 ) ;
T_1 V_304 =
V_6 -> V_52 ( V_2 , V_195 ) ;
T_3 V_326 ;
T_1 V_190 ;
V_191 = F_72 ( V_2 , V_302 , & V_325 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_191 = F_72 ( V_2 , V_303 , & V_324 , & V_190 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_322 == V_327 ) {
if ( V_321 != - 1 ) {
struct V_34 V_328 ;
int V_88 ;
V_191 = F_69 ( V_2 , V_321 ,
& V_328 ) ;
if ( V_191 != V_89 )
return V_191 ;
V_88 = V_328 . V_88 ;
if ( ( V_302 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , ( V_321 << 3 ) | 0x2 ) ;
}
} else if ( V_322 != V_329 ) {
int V_88 = V_325 . V_88 ;
if ( ( V_302 & 3 ) > V_88 || V_6 -> V_84 ( V_2 ) > V_88 )
return F_25 ( V_2 , V_302 ) ;
}
V_326 = F_19 ( & V_325 ) ;
if ( ! V_325 . V_102 ||
( ( V_326 < 0x67 && ( V_325 . type & 8 ) ) ||
V_326 < 0x2b ) ) {
F_28 ( V_2 , V_302 & 0xfffc ) ;
return V_59 ;
}
if ( V_322 == V_329 || V_322 == V_330 ) {
V_324 . type &= ~ ( 1 << 1 ) ;
F_73 ( V_2 , V_303 , & V_324 ) ;
}
if ( V_322 == V_329 )
V_2 -> V_172 = V_2 -> V_172 & ~ V_331 ;
if ( V_322 != V_332 && V_322 != V_327 )
V_303 = 0xffff ;
if ( V_325 . type & 8 )
V_191 = F_124 ( V_2 , V_302 , V_303 ,
V_304 , & V_325 ) ;
else
V_191 = F_121 ( V_2 , V_302 , V_303 ,
V_304 , & V_325 ) ;
if ( V_191 != V_89 )
return V_191 ;
if ( V_322 == V_332 || V_322 == V_327 )
V_2 -> V_172 = V_2 -> V_172 | V_331 ;
if ( V_322 != V_329 ) {
V_325 . type |= ( 1 << 1 ) ;
F_73 ( V_2 , V_302 , & V_325 ) ;
}
V_6 -> V_318 ( V_2 , 0 , V_6 -> V_116 ( V_2 , 0 ) | V_117 ) ;
V_6 -> V_71 ( V_2 , V_302 , & V_325 , 0 , V_195 ) ;
if ( V_323 ) {
V_2 -> V_104 = V_2 -> V_28 = ( V_325 . type & 8 ) ? 4 : 2 ;
V_2 -> V_199 = 0 ;
V_2 -> V_22 . V_112 = ( unsigned long ) V_57 ;
V_191 = F_79 ( V_2 ) ;
}
return V_191 ;
}
int F_126 ( struct V_1 * V_2 ,
T_2 V_302 , int V_321 , int V_322 ,
bool V_323 , T_3 V_57 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_201 ;
V_91 = F_125 ( V_2 , V_302 , V_321 , V_322 ,
V_323 , V_57 ) ;
if ( V_91 == V_89 ) {
V_2 -> V_30 = V_2 -> V_44 ;
F_4 ( V_2 ) ;
}
return ( V_91 == V_100 ) ? V_333 : V_334 ;
}
static void F_127 ( struct V_1 * V_2 , int V_9 ,
struct V_110 * V_111 )
{
int V_335 = ( V_2 -> V_172 & V_173 ) ? - V_111 -> V_170 : V_111 -> V_170 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_335 * V_111 -> V_25 ) ;
V_111 -> V_77 . V_154 . V_85 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
T_4 V_336 , V_337 ;
bool V_338 , V_339 , V_340 ;
V_339 = V_2 -> V_172 & V_341 ;
V_336 = V_2 -> V_27 . V_112 ;
V_337 = V_336 ;
V_340 = V_339 ;
V_339 = false ;
V_338 = V_2 -> V_172 & V_342 ;
if ( ( V_336 & 0x0f ) > 9 || V_338 ) {
V_336 -= 6 ;
V_339 = V_340 | ( V_336 >= 250 ) ;
V_338 = true ;
} else {
V_338 = false ;
}
if ( V_337 > 0x99 || V_340 ) {
V_336 -= 0x60 ;
V_339 = true ;
}
V_2 -> V_27 . V_112 = V_336 ;
V_2 -> V_22 . type = V_343 ;
V_2 -> V_22 . V_112 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_107 ( V_2 , V_344 ) ;
V_2 -> V_172 &= ~ ( V_342 | V_341 ) ;
if ( V_339 )
V_2 -> V_172 |= V_341 ;
if ( V_338 )
V_2 -> V_172 |= V_342 ;
return V_89 ;
}
static int F_129 ( struct V_1 * V_2 )
{
T_4 V_336 = V_2 -> V_27 . V_112 & 0xff ;
T_4 V_345 = ( V_2 -> V_27 . V_112 >> 8 ) & 0xff ;
V_336 = ( V_336 + ( V_345 * V_2 -> V_22 . V_112 ) ) & 0xff ;
V_2 -> V_27 . V_112 = ( V_2 -> V_27 . V_112 & 0xffff0000 ) | V_336 ;
V_2 -> V_22 . type = V_343 ;
V_2 -> V_22 . V_112 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_107 ( V_2 , V_344 ) ;
return V_89 ;
}
static int F_130 ( struct V_1 * V_2 )
{
long V_43 = V_2 -> V_22 . V_112 ;
V_2 -> V_22 . V_112 = ( unsigned long ) V_2 -> V_44 ;
F_18 ( V_2 , V_43 ) ;
return F_79 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
T_2 V_33 , V_346 ;
T_1 V_243 ;
int V_91 ;
V_346 = F_31 ( V_2 , V_97 ) ;
V_243 = V_2 -> V_44 ;
memcpy ( & V_33 , V_2 -> V_22 . V_240 + V_2 -> V_104 , 2 ) ;
if ( F_74 ( V_2 , V_33 , V_97 ) )
return V_89 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_240 , V_2 -> V_104 ) ;
V_2 -> V_22 . V_112 = V_346 ;
V_91 = F_79 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_112 = V_243 ;
return F_79 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_91 ;
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_91 = F_80 ( V_2 , & V_2 -> V_27 . V_112 , V_2 -> V_104 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_133 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_112 = V_2 -> V_27 . V_112 ;
F_76 ( & V_2 -> V_22 ) ;
V_2 -> V_27 . V_112 = V_2 -> V_22 . V_133 ;
V_2 -> V_199 = 1 ;
return V_89 ;
}
static int F_134 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_112 = V_2 -> V_224 . V_112 ;
return F_107 ( V_2 , V_347 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_131 ;
V_2 -> V_27 . V_25 = V_2 -> V_22 . V_25 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_246 ) ;
V_2 -> V_27 . V_112 = ~ ( ( V_2 -> V_22 . V_112 >> ( V_2 -> V_22 . V_25 * 8 - 1 ) ) - 1 ) ;
return V_89 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_113 V_348 = 0 ;
V_2 -> V_6 -> V_268 ( V_2 , V_349 , & V_348 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_348 ;
* F_2 ( V_2 , V_246 ) = V_348 >> 32 ;
return V_89 ;
}
static int F_137 ( struct V_1 * V_2 )
{
V_113 V_350 ;
if ( V_2 -> V_6 -> V_351 ( V_2 , F_1 ( V_2 , V_171 ) , & V_350 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_350 ;
* F_2 ( V_2 , V_246 ) = V_350 >> 32 ;
return V_89 ;
}
static int F_138 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_27 . V_240 , V_2 -> V_22 . V_240 , V_2 -> V_104 ) ;
return V_89 ;
}
static int F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_318 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_112 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_140 ( struct V_1 * V_2 )
{
unsigned long V_112 ;
if ( V_2 -> V_36 == V_37 )
V_112 = V_2 -> V_22 . V_112 & ~ 0ULL ;
else
V_112 = V_2 -> V_22 . V_112 & ~ 0U ;
if ( V_2 -> V_6 -> V_352 ( V_2 , V_2 -> V_19 , V_112 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_141 ( struct V_1 * V_2 )
{
V_113 V_264 ;
V_264 = ( T_3 ) F_1 ( V_2 , V_227 )
| ( ( V_113 ) F_1 ( V_2 , V_246 ) << 32 ) ;
if ( V_2 -> V_6 -> V_353 ( V_2 , F_1 ( V_2 , V_171 ) , V_264 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_142 ( struct V_1 * V_2 )
{
V_113 V_264 ;
if ( V_2 -> V_6 -> V_268 ( V_2 , F_1 ( V_2 , V_171 ) , & V_264 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_227 ) = ( T_3 ) V_264 ;
* F_2 ( V_2 , V_246 ) = V_264 >> 32 ;
return V_89 ;
}
static int F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_192 )
return F_27 ( V_2 ) ;
V_2 -> V_27 . V_112 = F_31 ( V_2 , V_2 -> V_19 ) ;
return V_89 ;
}
static int F_144 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
if ( V_2 -> V_19 == V_97 || V_2 -> V_19 > V_192 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_39 )
V_2 -> V_354 = V_355 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_2 -> V_19 ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_180 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_112 ;
V_2 -> V_27 . type = V_201 ;
return F_74 ( V_2 , V_33 , V_195 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
int V_91 ;
T_1 V_80 ;
V_91 = F_36 ( V_2 , V_2 -> V_22 . V_77 . V_154 , 1 , false , & V_80 ) ;
if ( V_91 == V_89 )
V_2 -> V_6 -> V_356 ( V_2 , V_80 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_1 V_357 ;
V_357 = V_2 -> V_6 -> V_116 ( V_2 , 0 ) ;
V_357 &= ~ V_117 ;
V_2 -> V_6 -> V_318 ( V_2 , 0 , V_357 ) ;
return V_89 ;
}
static int F_149 ( struct V_1 * V_2 )
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
static int F_150 ( struct V_1 * V_2 ,
void (* F_151)( struct V_1 * V_2 ,
struct V_176 * V_359 ) )
{
struct V_176 V_176 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_104 = 8 ;
F_151 ( V_2 , & V_176 ) ;
if ( V_2 -> V_104 == 2 ) {
V_2 -> V_104 = 4 ;
V_176 . V_103 &= 0x00ffffff ;
}
V_2 -> V_27 . type = V_201 ;
return F_66 ( V_2 , V_2 -> V_27 . V_77 . V_154 ,
& V_176 , 2 + V_2 -> V_104 ) ;
}
static int F_152 ( struct V_1 * V_2 )
{
return F_150 ( V_2 , V_2 -> V_6 -> V_181 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
return F_150 ( V_2 , V_2 -> V_6 -> V_178 ) ;
}
static int F_154 ( struct V_1 * V_2 )
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
V_2 -> V_6 -> V_360 ( V_2 , & V_176 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = V_2 -> V_6 -> V_358 ( V_2 ) ;
V_2 -> V_27 . type = V_201 ;
return V_91 ;
}
static int F_156 ( struct V_1 * V_2 )
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
V_2 -> V_6 -> V_361 ( V_2 , & V_176 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_157 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_112 = V_2 -> V_6 -> V_116 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_158 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_318 ( V_2 , 0 , ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_112 & 0x0f ) ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_159 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_3 ( V_2 , V_171 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) != 0 ) &&
( V_2 -> V_123 == 0xe2 || F_45 ( V_2 -> V_123 ^ 0x5 , V_2 -> V_172 ) ) )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_160 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) == 0 )
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
return V_89 ;
}
static int F_161 ( struct V_1 * V_2 )
{
if ( ! F_68 ( V_2 , V_2 -> V_27 . V_25 , V_2 -> V_22 . V_112 ,
& V_2 -> V_27 . V_112 ) )
return V_362 ;
return V_89 ;
}
static int F_162 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_363 ( V_2 , V_2 -> V_22 . V_25 , V_2 -> V_27 . V_112 ,
& V_2 -> V_22 . V_112 , 1 ) ;
V_2 -> V_27 . type = V_201 ;
return V_89 ;
}
static int F_163 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_172 &= ~ V_109 ;
return V_89 ;
}
static int F_164 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_354 = V_364 ;
V_2 -> V_172 |= V_109 ;
return V_89 ;
}
static int F_165 ( struct V_1 * V_2 )
{
T_3 V_250 , V_251 , V_252 , V_253 ;
V_250 = F_1 ( V_2 , V_227 ) ;
V_252 = F_1 ( V_2 , V_171 ) ;
V_2 -> V_6 -> V_254 ( V_2 , & V_250 , & V_251 , & V_252 , & V_253 ) ;
* F_2 ( V_2 , V_227 ) = V_250 ;
* F_2 ( V_2 , V_145 ) = V_251 ;
* F_2 ( V_2 , V_171 ) = V_252 ;
* F_2 ( V_2 , V_246 ) = V_253 ;
return V_89 ;
}
static int F_166 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_227 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_227 ) |= ( V_2 -> V_172 & 0xff ) << 8 ;
return V_89 ;
}
static int F_167 ( struct V_1 * V_2 )
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
static bool F_168 ( int V_3 )
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
static int F_169 ( struct V_1 * V_2 )
{
if ( ! F_168 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_113 V_365 = V_2 -> V_22 . V_23 ;
int V_366 = V_2 -> V_19 ;
V_113 V_267 = 0 ;
static V_113 V_367 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_368 ,
0 , 0 , 0 ,
V_369 ,
} ;
if ( ! F_168 ( V_366 ) )
return F_27 ( V_2 ) ;
if ( V_365 & V_367 [ V_366 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_366 ) {
case 0 : {
V_113 V_370 ;
if ( ( ( V_365 & V_371 ) && ! ( V_365 & V_372 ) ) ||
( ( V_365 & V_373 ) && ! ( V_365 & V_374 ) ) )
return F_25 ( V_2 , 0 ) ;
V_370 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
if ( ( V_365 & V_371 ) && ( V_267 & V_375 ) &&
! ( V_370 & V_376 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_113 V_377 = 0 ;
V_2 -> V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
if ( V_267 & V_272 )
V_377 = V_378 ;
else if ( V_2 -> V_6 -> V_116 ( V_2 , 4 ) & V_376 )
V_377 = V_379 ;
else if ( V_2 -> V_6 -> V_116 ( V_2 , 0 ) & V_371 )
V_377 = V_380 ;
if ( V_365 & V_377 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
if ( ( V_267 & V_272 ) && ! ( V_365 & V_376 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_89 ;
}
static int F_171 ( struct V_1 * V_2 )
{
unsigned long V_381 ;
V_2 -> V_6 -> V_382 ( V_2 , 7 , & V_381 ) ;
return V_381 & ( 1 << 13 ) ;
}
static int F_172 ( struct V_1 * V_2 )
{
int V_383 = V_2 -> V_19 ;
V_113 V_370 ;
if ( V_383 > 7 )
return F_27 ( V_2 ) ;
V_370 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
if ( ( V_370 & V_384 ) && ( V_383 == 4 || V_383 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_171 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_89 ;
}
static int F_173 ( struct V_1 * V_2 )
{
V_113 V_365 = V_2 -> V_22 . V_23 ;
int V_383 = V_2 -> V_19 ;
if ( ( V_383 == 6 || V_383 == 7 ) && ( V_365 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_172 ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_113 V_267 ;
V_2 -> V_6 -> V_268 ( V_2 , V_269 , & V_267 ) ;
if ( ! ( V_267 & V_385 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_175 ( struct V_1 * V_2 )
{
V_113 V_386 = F_1 ( V_2 , V_227 ) ;
if ( V_386 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_174 ( V_2 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
V_113 V_370 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
if ( V_370 & V_387 && V_2 -> V_6 -> V_84 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_89 ;
}
static int F_177 ( struct V_1 * V_2 )
{
V_113 V_370 = V_2 -> V_6 -> V_116 ( V_2 , 4 ) ;
V_113 V_388 = F_1 ( V_2 , V_171 ) ;
if ( ( ! ( V_370 & V_389 ) && V_2 -> V_6 -> V_84 ( V_2 ) ) ||
( V_388 > 3 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_178 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = F_39 ( V_2 -> V_27 . V_25 , 4u ) ;
if ( ! F_118 ( V_2 , V_2 -> V_22 . V_112 , V_2 -> V_27 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_179 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_25 = F_39 ( V_2 -> V_22 . V_25 , 4u ) ;
if ( ! F_118 ( V_2 , V_2 -> V_27 . V_112 , V_2 -> V_22 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_89 ;
}
static unsigned F_180 ( struct V_1 * V_2 )
{
unsigned V_72 ;
V_72 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
if ( V_72 == 8 )
V_72 = 4 ;
return V_72 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_110 * V_111 ,
unsigned V_72 , bool V_390 )
{
int V_91 = V_89 ;
V_111 -> type = V_343 ;
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
V_111 -> V_112 = F_60 ( V_391 , V_2 ) ;
break;
}
if ( ! V_390 ) {
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
static int F_182 ( struct V_1 * V_2 , struct V_110 * V_111 ,
unsigned V_40 )
{
int V_91 = V_89 ;
switch ( V_40 ) {
case V_392 :
F_57 ( V_2 , V_111 ) ;
break;
case V_393 :
V_91 = F_181 ( V_2 , V_111 , 1 , false ) ;
break;
case V_394 :
V_2 -> V_395 . V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_396:
* V_111 = V_2 -> V_395 ;
V_2 -> V_397 = V_111 ;
if ( ( V_2 -> V_40 & V_398 ) && V_111 == & V_2 -> V_27 )
F_62 ( V_2 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_399 :
V_2 -> V_395 . V_25 = 8 ;
goto V_396;
case V_400 :
V_111 -> type = V_131 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_227 ) ;
F_47 ( V_111 ) ;
V_111 -> V_133 = V_111 -> V_112 ;
break;
case V_401 :
V_111 -> type = V_143 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_154 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_150 ) ) ;
V_111 -> V_77 . V_154 . V_48 = V_299 ;
V_111 -> V_112 = 0 ;
V_111 -> V_170 = 1 ;
break;
case V_402 :
V_111 -> type = V_131 ;
V_111 -> V_25 = 2 ;
V_111 -> V_77 . V_9 = F_3 ( V_2 , V_246 ) ;
F_47 ( V_111 ) ;
break;
case V_403 :
V_111 -> V_25 = 1 ;
V_111 -> V_112 = F_1 ( V_2 , V_171 ) & 0xff ;
break;
case V_404 :
V_91 = F_181 ( V_2 , V_111 , 1 , true ) ;
break;
case V_405 :
V_111 -> V_25 = 1 ;
V_111 -> V_112 = 1 ;
break;
case V_406 :
V_91 = F_181 ( V_2 , V_111 , F_180 ( V_2 ) , true ) ;
break;
case V_407 :
V_91 = F_181 ( V_2 , V_111 , V_2 -> V_104 , true ) ;
break;
case V_408 :
V_2 -> V_395 . V_25 = 1 ;
goto V_396;
case V_409 :
V_2 -> V_395 . V_25 = 2 ;
goto V_396;
case V_410 :
V_2 -> V_395 . V_25 = 4 ;
goto V_396;
case V_411 :
V_91 = F_181 ( V_2 , V_111 , 2 , false ) ;
break;
case V_412 :
V_91 = F_181 ( V_2 , V_111 , F_180 ( V_2 ) , false ) ;
break;
case V_413 :
V_111 -> type = V_143 ;
V_111 -> V_25 = ( V_2 -> V_40 & V_132 ) ? 1 : V_2 -> V_104 ;
V_111 -> V_77 . V_154 . V_85 =
F_14 ( V_2 , F_1 ( V_2 , V_148 ) ) ;
V_111 -> V_77 . V_154 . V_48 = V_50 ( V_2 ) ;
V_111 -> V_112 = 0 ;
V_111 -> V_170 = 1 ;
break;
case V_414 :
V_111 -> type = V_343 ;
V_111 -> V_77 . V_154 . V_85 = V_2 -> V_44 ;
V_111 -> V_25 = V_2 -> V_104 + 2 ;
F_183 ( V_111 -> V_240 , V_111 -> V_25 , V_2 ) ;
break;
case V_415 :
V_2 -> V_395 . V_25 = V_2 -> V_104 + 2 ;
goto V_396;
case V_416 :
V_111 -> V_112 = V_299 ;
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
V_111 -> V_112 = V_192 ;
break;
case V_422 :
default:
V_111 -> type = V_201 ;
break;
}
V_155:
return V_91 ;
}
int F_184 ( struct V_1 * V_2 , void * V_423 , int V_424 )
{
int V_91 = V_89 ;
int V_36 = V_2 -> V_36 ;
int V_425 , V_426 , V_427 , V_428 ;
bool V_429 = false ;
struct V_430 V_430 ;
V_2 -> V_395 . type = V_201 ;
V_2 -> V_397 = NULL ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_79 . V_98 = V_2 -> V_44 ;
V_2 -> V_79 . V_96 = V_2 -> V_79 . V_98 + V_424 ;
if ( V_424 > 0 )
memcpy ( V_2 -> V_79 . V_90 , V_423 , V_424 ) ;
switch ( V_36 ) {
case V_87 :
case V_193 :
case V_219 :
V_425 = V_426 = 2 ;
break;
case V_218 :
V_425 = V_426 = 4 ;
break;
#ifdef F_49
case V_37 :
V_425 = 4 ;
V_426 = 8 ;
break;
#endif
default:
return V_333 ;
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
V_2 -> V_199 = 1 ;
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
return V_333 ;
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
return V_333 ;
}
V_2 -> V_40 &= ~ ( V_113 ) V_435 ;
V_2 -> V_40 |= V_430 . V_106 ;
}
V_2 -> V_453 = V_430 . V_437 . V_453 ;
V_2 -> V_454 = V_430 . V_454 ;
V_2 -> V_12 = V_430 . V_12 ;
if ( V_2 -> V_40 == 0 || ( V_2 -> V_40 & V_455 ) )
return V_333 ;
if ( ! ( V_2 -> V_40 & V_456 ) && V_2 -> V_457 )
return V_333 ;
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
V_91 = F_59 ( V_2 , & V_2 -> V_395 ) ;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_2 -> V_136 ) ;
} else if ( V_2 -> V_40 & V_460 )
V_91 = F_61 ( V_2 , & V_2 -> V_395 ) ;
if ( V_91 != V_89 )
goto V_155;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_142 ) ;
V_2 -> V_395 . V_77 . V_154 . V_48 = V_50 ( V_2 ) ;
if ( V_2 -> V_395 . type == V_143 && V_2 -> V_28 != 8 )
V_2 -> V_395 . V_77 . V_154 . V_85 = ( T_3 ) V_2 -> V_395 . V_77 . V_154 . V_85 ;
V_91 = F_182 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_40 >> V_461 ) & V_462 ) ;
if ( V_91 != V_89 )
goto V_155;
V_91 = F_182 ( V_2 , & V_2 -> V_224 , ( V_2 -> V_40 >> V_463 ) & V_462 ) ;
if ( V_91 != V_89 )
goto V_155;
V_91 = F_182 ( V_2 , & V_2 -> V_27 , ( V_2 -> V_40 >> V_464 ) & V_462 ) ;
V_155:
if ( V_2 -> V_397 && V_2 -> V_397 -> type == V_143 && V_2 -> V_153 )
V_2 -> V_397 -> V_77 . V_154 . V_85 += V_2 -> V_44 ;
return ( V_91 != V_89 ) ? V_333 : V_334 ;
}
bool F_185 ( struct V_1 * V_2 )
{
return V_2 -> V_40 & V_465 ;
}
static bool F_186 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_123 == 0xa6 ) || ( V_2 -> V_123 == 0xa7 ) ||
( V_2 -> V_123 == 0xae ) || ( V_2 -> V_123 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_466 ) &&
( ( V_2 -> V_172 & V_210 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_467 ) &&
( ( V_2 -> V_172 & V_210 ) == V_210 ) ) ) )
return true ;
return false ;
}
static int F_187 ( struct V_1 * V_2 )
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
static void F_188 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
if ( V_111 -> type == V_129 )
F_52 ( V_2 , & V_111 -> V_200 , V_111 -> V_77 . V_130 ) ;
}
static int F_107 ( struct V_1 * V_2 , void (* F_46)( struct F_107 * ) )
{
T_1 V_106 = ( V_2 -> V_172 & V_108 ) | V_109 ;
F_46 += F_189 ( V_2 -> V_27 . V_25 ) * V_470 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+b"(ctxt->src.val), [flags]"+D"(flags)
: "c"(ctxt->src2.val), [fastop]"S"(fop));
V_2 -> V_172 = ( V_2 -> V_172 & ~ V_108 ) | ( V_106 & V_108 ) ;
return V_89 ;
}
int F_190 ( struct V_1 * V_2 )
{
const struct V_179 * V_6 = V_2 -> V_6 ;
int V_91 = V_89 ;
int V_471 = V_2 -> V_27 . type ;
V_2 -> V_160 . V_161 = 0 ;
if ( V_2 -> V_36 == V_37 && ( V_2 -> V_40 & V_472 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_199 && ( ! ( V_2 -> V_40 & V_473 ) || V_2 -> V_27 . type != V_143 ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & V_474 ) == V_475 && V_2 -> V_22 . type != V_143 ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( ( V_2 -> V_40 & ( V_124 | V_128 ) ) && ( ( V_6 -> V_116 ( V_2 , 0 ) & V_118 ) ) )
|| ( ( V_2 -> V_40 & V_124 ) && ! ( V_6 -> V_116 ( V_2 , 4 ) & V_476 ) ) ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & ( V_124 | V_128 ) ) && ( V_6 -> V_116 ( V_2 , 0 ) & V_117 ) ) {
V_91 = F_30 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_40 & V_128 ) {
V_91 = F_187 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
F_188 ( V_2 , & V_2 -> V_22 ) ;
F_188 ( V_2 , & V_2 -> V_224 ) ;
if ( ! ( V_2 -> V_40 & V_477 ) )
F_188 ( V_2 , & V_2 -> V_27 ) ;
}
if ( F_41 ( V_2 -> V_478 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_479 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( ( V_2 -> V_40 & V_480 ) && V_6 -> V_84 ( V_2 ) ) {
V_91 = F_25 ( V_2 , 0 ) ;
goto V_155;
}
if ( ( V_2 -> V_40 & V_481 ) && V_2 -> V_36 < V_219 ) {
V_91 = F_27 ( V_2 ) ;
goto V_155;
}
if ( V_2 -> V_454 ) {
V_91 = V_2 -> V_454 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( F_41 ( V_2 -> V_478 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_482 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) == 0 ) {
V_2 -> V_30 = V_2 -> V_44 ;
goto V_155;
}
}
if ( ( V_2 -> V_22 . type == V_143 ) && ! ( V_2 -> V_40 & V_483 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_22 . V_77 . V_154 ,
V_2 -> V_22 . V_240 , V_2 -> V_22 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
V_2 -> V_22 . V_245 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_224 . type == V_143 ) {
V_91 = F_65 ( V_2 , V_2 -> V_224 . V_77 . V_154 ,
& V_2 -> V_224 . V_112 , V_2 -> V_224 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( ( V_2 -> V_40 & V_484 ) == V_485 )
goto V_486;
if ( ( V_2 -> V_27 . type == V_143 ) && ! ( V_2 -> V_40 & V_477 ) ) {
V_91 = F_65 ( V_2 , V_2 -> V_27 . V_77 . V_154 ,
& V_2 -> V_27 . V_112 , V_2 -> V_27 . V_25 ) ;
if ( V_91 != V_89 )
goto V_155;
}
V_2 -> V_27 . V_133 = V_2 -> V_27 . V_112 ;
V_486:
if ( F_41 ( V_2 -> V_478 ) && V_2 -> V_12 ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_487 ) ;
if ( V_91 != V_89 )
goto V_155;
}
if ( V_2 -> V_453 ) {
if ( V_2 -> V_40 & V_488 ) {
void (* F_46)( struct F_107 * ) = ( void * ) V_2 -> V_453 ;
V_91 = F_107 ( V_2 , F_46 ) ;
if ( V_91 != V_89 )
goto V_155;
goto F_77;
}
V_91 = V_2 -> V_453 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
goto F_77;
}
if ( V_2 -> V_433 )
goto V_489;
switch ( V_2 -> V_123 ) {
case 0x63 :
if ( V_2 -> V_36 != V_37 )
goto V_490;
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
if ( V_2 -> V_27 . V_77 . V_9 == F_3 ( V_2 , V_227 ) )
break;
V_91 = F_133 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_104 ) {
case 2 : V_2 -> V_27 . V_112 = ( V_151 ) V_2 -> V_27 . V_112 ; break;
case 4 : V_2 -> V_27 . V_112 = ( V_157 ) V_2 -> V_27 . V_112 ; break;
case 8 : V_2 -> V_27 . V_112 = ( V_152 ) V_2 -> V_27 . V_112 ; break;
}
break;
case 0xcc :
V_91 = F_93 ( V_2 , 3 ) ;
break;
case 0xcd :
V_91 = F_93 ( V_2 , V_2 -> V_22 . V_112 ) ;
break;
case 0xce :
if ( V_2 -> V_172 & V_212 )
V_91 = F_93 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
F_18 ( V_2 , V_2 -> V_22 . V_112 ) ;
V_2 -> V_27 . type = V_201 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_491 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_172 ^= V_207 ;
break;
case 0xf8 :
V_2 -> V_172 &= ~ V_207 ;
break;
case 0xf9 :
V_2 -> V_172 |= V_207 ;
break;
case 0xfc :
V_2 -> V_172 &= ~ V_173 ;
break;
case 0xfd :
V_2 -> V_172 |= V_173 ;
break;
default:
goto V_490;
}
if ( V_91 != V_89 )
goto V_155;
F_77:
V_91 = F_77 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_155;
V_2 -> V_27 . type = V_471 ;
if ( ( V_2 -> V_40 & V_474 ) == V_492 )
F_127 ( V_2 , V_148 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_40 & V_484 ) == V_493 )
F_127 ( V_2 , V_150 , & V_2 -> V_27 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
unsigned int V_170 ;
struct V_158 * V_283 = & V_2 -> V_167 ;
if ( ( V_2 -> V_40 & V_474 ) == V_492 )
V_170 = V_2 -> V_22 . V_170 ;
else
V_170 = V_2 -> V_27 . V_170 ;
F_16 ( V_2 , F_3 ( V_2 , V_171 ) ,
- V_170 ) ;
if ( ! F_186 ( V_2 ) ) {
if ( ( V_283 -> V_96 != 0 || F_1 ( V_2 , V_171 ) & 0x3ff ) &&
( V_283 -> V_96 == 0 || V_283 -> V_96 != V_283 -> V_161 ) ) {
V_2 -> V_160 . V_96 = 0 ;
F_4 ( V_2 ) ;
return V_494 ;
}
goto V_155;
}
}
V_2 -> V_30 = V_2 -> V_44 ;
V_155:
if ( V_91 == V_59 )
V_2 -> V_495 = true ;
if ( V_91 == V_496 )
return V_497 ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return ( V_91 == V_100 ) ? V_333 : V_334 ;
V_489:
switch ( V_2 -> V_123 ) {
case 0x09 :
( V_2 -> V_6 -> V_498 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_27 . V_112 = V_6 -> V_116 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_382 ( V_2 , V_2 -> V_19 , & V_2 -> V_27 . V_112 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_27 . V_112 = V_2 -> V_27 . V_133 = V_2 -> V_22 . V_112 ;
if ( ! F_45 ( V_2 -> V_123 , V_2 -> V_172 ) )
V_2 -> V_27 . type = V_201 ;
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
case 0xc0 ... 0xc1 :
F_107 ( V_2 , V_499 ) ;
V_2 -> V_22 . V_112 = V_2 -> V_27 . V_133 ;
F_76 ( & V_2 -> V_22 ) ;
break;
case 0xc3 :
V_2 -> V_27 . V_25 = V_2 -> V_104 ;
V_2 -> V_27 . V_112 = ( V_2 -> V_104 == 4 ) ? ( T_3 ) V_2 -> V_22 . V_112 :
( V_113 ) V_2 -> V_22 . V_112 ;
break;
default:
goto V_490;
}
if ( V_91 != V_89 )
goto V_155;
goto F_77;
V_490:
return V_333 ;
}
void F_191 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_192 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
