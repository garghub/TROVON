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
F_14 ( struct V_1 * V_2 , unsigned long V_9 )
{
return F_13 ( V_2 , V_9 ) ;
}
static void F_15 ( T_1 * V_9 , T_1 V_33 , int V_42 )
{
F_8 ( V_9 , * V_9 + V_42 , V_33 ) ;
}
static inline void
F_16 ( struct V_1 * V_2 , unsigned long * V_9 , int V_42 )
{
T_1 V_33 ;
if ( V_2 -> V_29 == sizeof( unsigned long ) )
V_33 = ~ 0UL ;
else
V_33 = F_9 ( V_2 ) ;
F_15 ( V_9 , V_33 , V_42 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_42 )
{
F_15 ( F_3 ( V_2 , V_43 ) , F_10 ( V_2 ) , V_42 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , int V_44 )
{
F_16 ( V_2 , & V_2 -> V_45 , V_44 ) ;
}
static T_3 F_19 ( struct V_35 * V_46 )
{
T_3 V_47 = F_20 ( V_46 ) ;
return V_46 -> V_48 ? ( V_47 << 12 ) | 0xfff : V_47 ;
}
static unsigned long F_21 ( struct V_1 * V_2 , int V_49 )
{
if ( V_2 -> V_37 == V_38 && V_49 < V_50 )
return 0 ;
return V_2 -> V_6 -> V_51 ( V_2 , V_49 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_52 ,
T_3 error , bool V_53 )
{
V_2 -> V_54 . V_55 = V_52 ;
V_2 -> V_54 . V_56 = error ;
V_2 -> V_54 . V_57 = V_53 ;
return V_58 ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_59 , 0 , false ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_60 )
{
return F_22 ( V_2 , V_61 , V_60 , true ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_60 )
{
return F_22 ( V_2 , V_62 , V_60 , true ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_63 , 0 , false ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_60 )
{
return F_22 ( V_2 , V_64 , V_60 , true ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_65 , 0 , false ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_66 , 0 , false ) ;
}
static T_2 F_30 ( struct V_1 * V_2 , unsigned V_49 )
{
T_2 V_67 ;
struct V_35 V_46 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_67 , & V_46 , NULL , V_49 ) ;
return V_67 ;
}
static void F_31 ( struct V_1 * V_2 , T_2 V_67 ,
unsigned V_49 )
{
T_2 V_68 ;
T_3 V_69 ;
struct V_35 V_46 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_68 , & V_46 , & V_69 , V_49 ) ;
V_2 -> V_6 -> V_70 ( V_2 , V_67 , & V_46 , V_69 , V_49 ) ;
}
static bool F_32 ( struct V_1 * V_2 , unsigned V_71 )
{
if ( F_33 ( V_71 < 16 ) )
return false ;
if ( V_2 -> V_41 & V_72 )
return true ;
else if ( V_2 -> V_41 & V_73 )
return false ;
else if ( V_2 -> V_41 & V_74 )
return false ;
else
return true ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
unsigned V_71 , bool V_77 , bool V_78 ,
T_1 * V_79 )
{
struct V_35 V_46 ;
bool V_80 ;
T_1 V_81 ;
T_3 V_82 ;
T_2 V_34 ;
unsigned V_83 ;
V_81 = F_21 ( V_2 , V_76 . V_49 ) + V_76 . V_84 ;
switch ( V_2 -> V_37 ) {
case V_38 :
if ( ( ( signed long ) V_81 << 16 ) >> 16 != V_81 )
return F_24 ( V_2 , 0 ) ;
break;
default:
V_80 = V_2 -> V_6 -> V_39 ( V_2 , & V_34 , & V_46 , NULL ,
V_76 . V_49 ) ;
if ( ! V_80 )
goto V_85;
if ( ( ( ( V_2 -> V_37 != V_86 ) && ( V_46 . type & 8 ) )
|| ! ( V_46 . type & 2 ) ) && V_77 )
goto V_85;
if ( ! V_78 && ( V_46 . type & 8 ) && ! ( V_46 . type & 2 ) )
goto V_85;
V_82 = F_19 ( & V_46 ) ;
if ( ( V_2 -> V_37 == V_86 ) && ! V_78 &&
( V_2 -> V_41 & V_87 ) ) {
if ( V_81 > 0xffff || ( T_3 ) ( V_81 + V_71 - 1 ) > 0xffff )
goto V_85;
} else if ( ( V_46 . type & 8 ) || ! ( V_46 . type & 4 ) ) {
if ( V_76 . V_84 > V_82 || ( T_3 ) ( V_76 . V_84 + V_71 - 1 ) > V_82 )
goto V_85;
} else {
if ( V_76 . V_84 <= V_82 || ( T_3 ) ( V_76 . V_84 + V_71 - 1 ) <= V_82 )
goto V_85;
V_82 = V_46 . V_41 ? 0xffffffff : 0xffff ;
if ( V_76 . V_84 > V_82 || ( T_3 ) ( V_76 . V_84 + V_71 - 1 ) > V_82 )
goto V_85;
}
V_83 = V_2 -> V_6 -> V_83 ( V_2 ) ;
if ( ! ( V_46 . type & 8 ) ) {
if ( V_83 > V_46 . V_88 )
goto V_85;
} else if ( ( V_46 . type & 8 ) && ! ( V_46 . type & 4 ) ) {
if ( V_83 != V_46 . V_88 )
goto V_85;
} else if ( ( V_46 . type & 8 ) && ( V_46 . type & 4 ) ) {
if ( V_83 < V_46 . V_88 )
goto V_85;
}
break;
}
if ( V_78 ? V_2 -> V_37 != V_38 : V_2 -> V_29 != 8 )
V_81 &= ( T_3 ) - 1 ;
if ( F_32 ( V_2 , V_71 ) && ( ( V_81 & ( V_71 - 1 ) ) != 0 ) )
return F_24 ( V_2 , 0 ) ;
* V_79 = V_81 ;
return V_89 ;
V_85:
if ( V_76 . V_49 == V_40 )
return F_25 ( V_2 , V_34 ) ;
else
return F_24 ( V_2 , V_34 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
unsigned V_71 , bool V_77 ,
T_1 * V_79 )
{
return F_34 ( V_2 , V_76 , V_71 , V_77 , false , V_79 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
void * V_90 ,
unsigned V_71 )
{
int V_91 ;
T_1 V_79 ;
V_91 = F_35 ( V_2 , V_76 , V_71 , false , & V_79 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_79 , V_90 , V_71 , & V_2 -> V_54 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_93 )
{
int V_91 ;
unsigned V_71 ;
unsigned long V_79 ;
int V_94 = V_2 -> V_78 . V_95 - V_2 -> V_78 . V_90 ;
struct V_75 V_76 = { . V_49 = V_96 ,
. V_84 = V_2 -> V_31 + V_94 } ;
V_71 = 15UL ^ V_94 ;
V_91 = F_34 ( V_2 , V_76 , V_71 , false , true , & V_79 ) ;
if ( F_38 ( V_91 != V_89 ) )
return V_91 ;
V_71 = F_39 ( unsigned , V_71 , V_97 - F_40 ( V_79 ) ) ;
if ( F_38 ( V_71 < V_93 ) )
return V_98 ;
V_91 = V_2 -> V_6 -> V_78 ( V_2 , V_79 , V_2 -> V_78 . V_95 ,
V_71 , & V_2 -> V_54 ) ;
if ( F_38 ( V_91 != V_89 ) )
return V_91 ;
V_2 -> V_78 . V_95 += V_71 ;
return V_89 ;
}
static T_4 int F_41 ( struct V_1 * V_2 ,
unsigned V_71 )
{
if ( F_38 ( V_2 -> V_78 . V_95 - V_2 -> V_78 . V_99 < V_71 ) )
return F_37 ( V_2 , V_71 ) ;
else
return V_89 ;
}
static void * F_42 ( struct V_1 * V_2 , T_5 V_19 ,
int V_100 )
{
void * V_101 ;
int V_102 = ( V_2 -> V_103 == 0 ) && V_100 ;
if ( V_102 && V_19 >= 4 && V_19 < 8 )
V_101 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_101 = F_3 ( V_2 , V_19 ) ;
return V_101 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
T_2 * V_71 , unsigned long * V_104 , int V_105 )
{
int V_91 ;
if ( V_105 == 2 )
V_105 = 3 ;
* V_104 = 0 ;
V_91 = F_36 ( V_2 , V_76 , V_71 , 2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_76 . V_84 += 2 ;
V_91 = F_36 ( V_2 , V_76 , V_104 , V_105 ) ;
return V_91 ;
}
static T_5 F_44 ( unsigned int V_106 , unsigned long V_107 )
{
T_5 V_91 ;
void (* F_45)( void ) = ( void * ) V_108 + 4 * ( V_106 & 0xf ) ;
V_107 = ( V_107 & V_109 ) | V_110 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_91 ;
}
static void F_46 ( struct V_111 * V_112 )
{
switch ( V_112 -> V_27 ) {
case 1 :
V_112 -> V_113 = * ( T_5 * ) V_112 -> V_76 . V_9 ;
break;
case 2 :
V_112 -> V_113 = * ( T_2 * ) V_112 -> V_76 . V_9 ;
break;
case 4 :
V_112 -> V_113 = * ( T_3 * ) V_112 -> V_76 . V_9 ;
break;
case 8 :
V_112 -> V_113 = * ( V_114 * ) V_112 -> V_76 . V_9 ;
break;
}
}
static void F_47 ( struct V_1 * V_2 , T_6 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_115 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_48
case 8 : asm("movdqa %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqa %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqa %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqa %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqa %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqa %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqa %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqa %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_49 () ;
}
V_2 -> V_6 -> V_116 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 , T_6 * V_90 ,
int V_9 )
{
V_2 -> V_6 -> V_115 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_48
case 8 : asm("movdqa %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqa %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqa %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqa %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqa %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqa %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqa %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqa %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_49 () ;
}
V_2 -> V_6 -> V_116 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , V_114 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_115 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_49 () ;
}
V_2 -> V_6 -> V_116 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , V_114 * V_90 , int V_9 )
{
V_2 -> V_6 -> V_115 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_49 () ;
}
V_2 -> V_6 -> V_116 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_117 ( V_2 , 0 ) & ( V_118 | V_119 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_115 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_116 ( V_2 ) ;
return V_89 ;
}
static int F_54 ( struct V_1 * V_2 )
{
T_2 V_120 ;
if ( V_2 -> V_6 -> V_117 ( V_2 , 0 ) & ( V_118 | V_119 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_115 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_116 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_113 = V_120 ;
return V_89 ;
}
static int F_55 ( struct V_1 * V_2 )
{
T_2 V_121 ;
if ( V_2 -> V_6 -> V_117 ( V_2 , 0 ) & ( V_118 | V_119 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_115 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_116 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_113 = V_121 ;
return V_89 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_41 & V_122 ) )
V_9 = ( V_2 -> V_123 & 7 ) | ( ( V_2 -> V_103 & 1 ) << 3 ) ;
if ( V_2 -> V_41 & V_124 ) {
V_112 -> type = V_125 ;
V_112 -> V_27 = 16 ;
V_112 -> V_76 . V_126 = V_9 ;
F_47 ( V_2 , & V_112 -> V_127 , V_9 ) ;
return;
}
if ( V_2 -> V_41 & V_128 ) {
V_9 &= 7 ;
V_112 -> type = V_129 ;
V_112 -> V_27 = 8 ;
V_112 -> V_76 . V_130 = V_9 ;
return;
}
V_112 -> type = V_131 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_9 = F_42 ( V_2 , V_9 , V_2 -> V_41 & V_132 ) ;
F_46 ( V_112 ) ;
V_112 -> V_133 = V_112 -> V_113 ;
}
static void F_57 ( struct V_1 * V_2 , int V_134 )
{
if ( V_134 == V_43 || V_134 == V_135 )
V_2 -> V_136 = V_40 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
T_5 V_137 ;
int V_138 , V_134 , V_139 ;
int V_91 = V_89 ;
T_1 V_140 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_103 << 1 ) & 8 ) ;
V_138 = ( V_2 -> V_103 << 2 ) & 8 ;
V_134 = ( V_2 -> V_103 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_141 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_141 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_134 | ( V_2 -> V_141 & 0x07 ) ;
V_2 -> V_136 = V_142 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_41 & V_143 ) ) {
V_112 -> type = V_131 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_9 = F_42 ( V_2 , V_2 -> V_20 ,
V_2 -> V_41 & V_132 ) ;
if ( V_2 -> V_41 & V_124 ) {
V_112 -> type = V_125 ;
V_112 -> V_27 = 16 ;
V_112 -> V_76 . V_126 = V_2 -> V_20 ;
F_47 ( V_2 , & V_112 -> V_127 , V_2 -> V_20 ) ;
return V_91 ;
}
if ( V_2 -> V_41 & V_128 ) {
V_112 -> type = V_129 ;
V_112 -> V_27 = 8 ;
V_112 -> V_76 . V_130 = V_2 -> V_20 & 7 ;
return V_91 ;
}
F_46 ( V_112 ) ;
return V_91 ;
}
V_112 -> type = V_144 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_145 = F_1 ( V_2 , V_146 ) ;
unsigned V_147 = F_1 ( V_2 , V_135 ) ;
unsigned V_148 = F_1 ( V_2 , V_149 ) ;
unsigned V_150 = F_1 ( V_2 , V_151 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_140 += F_59 ( T_2 , V_2 ) ;
break;
case 1 :
V_140 += F_59 ( V_152 , V_2 ) ;
break;
case 2 :
V_140 += F_59 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_140 += V_145 + V_148 ;
break;
case 1 :
V_140 += V_145 + V_150 ;
break;
case 2 :
V_140 += V_147 + V_148 ;
break;
case 3 :
V_140 += V_147 + V_150 ;
break;
case 4 :
V_140 += V_148 ;
break;
case 5 :
V_140 += V_150 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_140 += V_147 ;
break;
case 7 :
V_140 += V_145 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_136 = V_40 ;
V_140 = ( T_2 ) V_140 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_137 = F_59 ( T_5 , V_2 ) ;
V_138 |= ( V_137 >> 3 ) & 7 ;
V_134 |= V_137 & 7 ;
V_139 = V_137 >> 6 ;
if ( ( V_134 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_140 += F_59 ( V_153 , V_2 ) ;
else {
V_140 += F_1 ( V_2 , V_134 ) ;
F_57 ( V_2 , V_134 ) ;
}
if ( V_138 != 4 )
V_140 += F_1 ( V_2 , V_138 ) << V_139 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
if ( V_2 -> V_37 == V_38 )
V_2 -> V_154 = 1 ;
} else {
V_134 = V_2 -> V_20 ;
V_140 += F_1 ( V_2 , V_134 ) ;
F_57 ( V_2 , V_134 ) ;
}
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 5 )
V_140 += F_59 ( V_153 , V_2 ) ;
break;
case 1 :
V_140 += F_59 ( V_152 , V_2 ) ;
break;
case 2 :
V_140 += F_59 ( V_153 , V_2 ) ;
break;
}
}
V_112 -> V_76 . V_155 . V_84 = V_140 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_156 . V_76 . V_155 . V_84 = ( T_3 ) V_2 -> V_156 . V_76 . V_155 . V_84 ;
V_157:
return V_91 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
int V_91 = V_89 ;
V_112 -> type = V_144 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_112 -> V_76 . V_155 . V_84 = F_59 ( T_2 , V_2 ) ;
break;
case 4 :
V_112 -> V_76 . V_155 . V_84 = F_59 ( T_3 , V_2 ) ;
break;
case 8 :
V_112 -> V_76 . V_155 . V_84 = F_59 ( V_114 , V_2 ) ;
break;
}
V_157:
return V_91 ;
}
static void F_61 ( struct V_1 * V_2 )
{
long V_158 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_144 && V_2 -> V_22 . type == V_131 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_158 = ( V_159 ) V_2 -> V_22 . V_113 & ( V_159 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_158 = ( V_153 ) V_2 -> V_22 . V_113 & ( V_153 ) V_33 ;
else
V_158 = ( V_160 ) V_2 -> V_22 . V_113 & ( V_160 ) V_33 ;
V_2 -> V_25 . V_76 . V_155 . V_84 += ( V_158 >> 3 ) ;
}
V_2 -> V_22 . V_113 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_62 ( struct V_1 * V_2 ,
unsigned long V_76 , void * V_32 , unsigned V_71 )
{
int V_91 ;
struct V_161 * V_162 = & V_2 -> V_163 ;
if ( V_162 -> V_164 < V_162 -> V_95 )
goto V_165;
F_63 ( ( V_162 -> V_95 + V_71 ) >= sizeof( V_162 -> V_90 ) ) ;
V_91 = V_2 -> V_6 -> F_62 ( V_2 , V_76 , V_162 -> V_90 + V_162 -> V_95 , V_71 ,
& V_2 -> V_54 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_162 -> V_95 += V_71 ;
V_165:
memcpy ( V_32 , V_162 -> V_90 + V_162 -> V_164 , V_71 ) ;
V_162 -> V_164 += V_71 ;
return V_89 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
void * V_90 ,
unsigned V_71 )
{
int V_91 ;
T_1 V_79 ;
V_91 = F_35 ( V_2 , V_76 , V_71 , false , & V_79 ) ;
if ( V_91 != V_89 )
return V_91 ;
return F_62 ( V_2 , V_79 , V_90 , V_71 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
const void * V_90 ,
unsigned V_71 )
{
int V_91 ;
T_1 V_79 ;
V_91 = F_35 ( V_2 , V_76 , V_71 , true , & V_79 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_166 ( V_2 , V_79 , V_90 , V_71 ,
& V_2 -> V_54 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_75 V_76 ,
const void * V_167 , const void * V_90 ,
unsigned V_71 )
{
int V_91 ;
T_1 V_79 ;
V_91 = F_35 ( V_2 , V_76 , V_71 , true , & V_79 ) ;
if ( V_91 != V_89 )
return V_91 ;
return V_2 -> V_6 -> V_168 ( V_2 , V_79 , V_167 , V_90 ,
V_71 , & V_2 -> V_54 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned int V_71 , unsigned short V_169 ,
void * V_32 )
{
struct V_161 * V_91 = & V_2 -> V_170 ;
if ( V_91 -> V_164 == V_91 -> V_95 ) {
unsigned int V_171 , V_172 ;
unsigned int V_173 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_174 ) ) : 1 ;
V_171 = ( V_2 -> V_175 & V_176 ) ?
F_40 ( F_1 ( V_2 , V_151 ) ) :
V_97 - F_40 ( F_1 ( V_2 , V_151 ) ) ;
V_172 = F_68 ( V_171 , ( unsigned int ) sizeof( V_91 -> V_90 ) / V_71 , V_173 ) ;
if ( V_172 == 0 )
V_172 = 1 ;
V_91 -> V_164 = V_91 -> V_95 = 0 ;
if ( ! V_2 -> V_6 -> F_67 ( V_2 , V_71 , V_169 , V_91 -> V_90 , V_172 ) )
return 0 ;
V_91 -> V_95 = V_172 * V_71 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) &&
! ( V_2 -> V_175 & V_176 ) ) {
V_2 -> V_25 . V_90 = V_91 -> V_90 + V_91 -> V_164 ;
V_2 -> V_25 . type = V_177 ;
V_2 -> V_25 . V_173 = ( V_91 -> V_95 - V_91 -> V_164 ) / V_71 ;
V_91 -> V_164 = V_91 -> V_95 ;
} else {
memcpy ( V_32 , V_91 -> V_90 + V_91 -> V_164 , V_71 ) ;
V_91 -> V_164 += V_71 ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_2 V_178 , struct V_35 * V_46 )
{
struct V_179 V_180 ;
T_1 V_76 ;
V_2 -> V_6 -> V_181 ( V_2 , & V_180 ) ;
if ( V_180 . V_71 < V_178 * 8 + 7 )
return F_24 ( V_2 , V_178 << 3 | 0x2 ) ;
V_76 = V_180 . V_104 + V_178 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_76 , V_46 , sizeof *V_46 ,
& V_2 -> V_54 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
T_2 V_67 , struct V_179 * V_180 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
T_3 V_69 = 0 ;
if ( V_67 & 1 << 2 ) {
struct V_35 V_46 ;
T_2 V_34 ;
memset ( V_180 , 0 , sizeof *V_180 ) ;
if ( ! V_6 -> V_39 ( V_2 , & V_34 , & V_46 , & V_69 ,
V_183 ) )
return;
V_180 -> V_71 = F_19 ( & V_46 ) ;
V_180 -> V_104 = F_71 ( & V_46 ) | ( ( V_114 ) V_69 << 32 ) ;
} else
V_6 -> V_184 ( V_2 , V_180 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
T_2 V_67 , struct V_35 * V_46 ,
T_1 * V_185 )
{
struct V_179 V_180 ;
T_2 V_178 = V_67 >> 3 ;
T_1 V_76 ;
F_70 ( V_2 , V_67 , & V_180 ) ;
if ( V_180 . V_71 < V_178 * 8 + 7 )
return F_24 ( V_2 , V_67 & 0xfffc ) ;
* V_185 = V_76 = V_180 . V_104 + V_178 * 8 ;
return V_2 -> V_6 -> V_92 ( V_2 , V_76 , V_46 , sizeof *V_46 ,
& V_2 -> V_54 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_67 , struct V_35 * V_46 )
{
struct V_179 V_180 ;
T_2 V_178 = V_67 >> 3 ;
T_1 V_76 ;
F_70 ( V_2 , V_67 , & V_180 ) ;
if ( V_180 . V_71 < V_178 * 8 + 7 )
return F_24 ( V_2 , V_67 & 0xfffc ) ;
V_76 = V_180 . V_104 + V_178 * 8 ;
return V_2 -> V_6 -> V_186 ( V_2 , V_76 , V_46 , sizeof *V_46 ,
& V_2 -> V_54 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
T_2 V_67 , int V_49 , T_5 V_83 , bool V_187 )
{
struct V_35 V_188 , V_189 ;
T_5 V_88 , V_190 ;
unsigned V_191 = V_61 ;
T_3 V_192 = 0 ;
bool V_193 = ! ( V_67 & ~ 0x3 ) ;
T_1 V_194 ;
int V_195 ;
T_2 V_68 ;
T_3 V_69 = 0 ;
memset ( & V_188 , 0 , sizeof V_188 ) ;
if ( V_2 -> V_37 == V_86 ) {
V_2 -> V_6 -> V_39 ( V_2 , & V_68 , & V_188 , NULL , V_49 ) ;
F_75 ( & V_188 , V_67 << 4 ) ;
goto V_196;
} else if ( V_49 <= V_197 && V_2 -> V_37 == V_198 ) {
F_75 ( & V_188 , V_67 << 4 ) ;
F_76 ( & V_188 , 0xffff ) ;
V_188 . type = 3 ;
V_188 . V_101 = 1 ;
V_188 . V_199 = 1 ;
V_188 . V_88 = 3 ;
goto V_196;
}
V_190 = V_67 & 3 ;
if ( ( V_49 == V_96
|| ( V_49 == V_40
&& ( V_2 -> V_37 != V_38 || V_190 != V_83 ) )
|| V_49 == V_200 )
&& V_193 )
goto V_54;
if ( V_49 == V_200 && ( V_67 & ( 1 << 2 ) ) )
goto V_54;
if ( V_193 )
goto V_196;
V_195 = F_72 ( V_2 , V_67 , & V_188 , & V_194 ) ;
if ( V_195 != V_89 )
return V_195 ;
V_192 = V_67 & 0xfffc ;
V_191 = V_61 ;
if ( V_49 <= V_197 && ! V_188 . V_199 )
goto V_54;
if ( ! V_188 . V_101 ) {
V_191 = ( V_49 == V_40 ) ? V_62 : V_201 ;
goto V_54;
}
V_88 = V_188 . V_88 ;
switch ( V_49 ) {
case V_40 :
if ( V_190 != V_83 || ( V_188 . type & 0xa ) != 0x2 || V_88 != V_83 )
goto V_54;
break;
case V_96 :
if ( ! ( V_188 . type & 8 ) )
goto V_54;
if ( V_188 . type & 4 ) {
if ( V_88 > V_83 )
goto V_54;
} else {
if ( V_190 > V_83 || V_88 != V_83 )
goto V_54;
}
V_67 = ( V_67 & 0xfffc ) | V_83 ;
break;
case V_200 :
if ( V_188 . V_199 || ( V_188 . type != 1 && V_188 . type != 9 ) )
goto V_54;
V_189 = V_188 ;
V_188 . type |= 2 ;
V_195 = V_2 -> V_6 -> V_168 ( V_2 , V_194 , & V_189 , & V_188 ,
sizeof( V_188 ) , & V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
break;
case V_183 :
if ( V_188 . V_199 || V_188 . type != 2 )
goto V_54;
break;
default:
if ( ( V_188 . type & 0xa ) == 0x8 ||
( ( ( V_188 . type & 0xc ) != 0xc ) &&
( V_190 > V_88 && V_83 > V_88 ) ) )
goto V_54;
break;
}
if ( V_188 . V_199 ) {
V_188 . type |= 1 ;
V_195 = F_73 ( V_2 , V_67 , & V_188 ) ;
if ( V_195 != V_89 )
return V_195 ;
} else if ( V_2 -> V_37 == V_38 ) {
V_195 = V_2 -> V_6 -> V_92 ( V_2 , V_194 + 8 , & V_69 ,
sizeof( V_69 ) , & V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
}
V_196:
V_2 -> V_6 -> V_70 ( V_2 , V_67 , & V_188 , V_69 , V_49 ) ;
return V_89 ;
V_54:
F_22 ( V_2 , V_191 , V_192 , true ) ;
return V_58 ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 V_67 , int V_49 )
{
T_5 V_83 = V_2 -> V_6 -> V_83 ( V_2 ) ;
return F_74 ( V_2 , V_67 , V_49 , V_83 , false ) ;
}
static void F_78 ( struct V_111 * V_112 )
{
switch ( V_112 -> V_27 ) {
case 1 :
* ( T_5 * ) V_112 -> V_76 . V_9 = ( T_5 ) V_112 -> V_113 ;
break;
case 2 :
* ( T_2 * ) V_112 -> V_76 . V_9 = ( T_2 ) V_112 -> V_113 ;
break;
case 4 :
* V_112 -> V_76 . V_9 = ( T_3 ) V_112 -> V_113 ;
break;
case 8 :
* V_112 -> V_76 . V_9 = V_112 -> V_113 ;
break;
}
}
static int F_79 ( struct V_1 * V_2 , struct V_111 * V_112 )
{
switch ( V_112 -> type ) {
case V_131 :
F_78 ( V_112 ) ;
break;
case V_144 :
if ( V_2 -> V_202 )
return F_66 ( V_2 ,
V_112 -> V_76 . V_155 ,
& V_112 -> V_133 ,
& V_112 -> V_113 ,
V_112 -> V_27 ) ;
else
return F_65 ( V_2 ,
V_112 -> V_76 . V_155 ,
& V_112 -> V_113 ,
V_112 -> V_27 ) ;
break;
case V_177 :
return F_65 ( V_2 ,
V_112 -> V_76 . V_155 ,
V_112 -> V_90 ,
V_112 -> V_27 * V_112 -> V_173 ) ;
break;
case V_125 :
F_50 ( V_2 , & V_112 -> V_127 , V_112 -> V_76 . V_126 ) ;
break;
case V_129 :
F_52 ( V_2 , & V_112 -> V_203 , V_112 -> V_76 . V_130 ) ;
break;
case V_204 :
break;
default:
break;
}
return V_89 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_90 , int V_27 )
{
struct V_75 V_76 ;
F_17 ( V_2 , - V_27 ) ;
V_76 . V_84 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_76 . V_49 = V_40 ;
return F_65 ( V_2 , V_76 , V_90 , V_27 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_204 ;
return F_80 ( V_2 , & V_2 -> V_22 . V_113 , V_2 -> V_105 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
void * V_32 , int V_205 )
{
int V_91 ;
struct V_75 V_76 ;
V_76 . V_84 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_76 . V_49 = V_40 ;
V_91 = F_64 ( V_2 , V_76 , V_32 , V_205 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_205 ) ;
return V_91 ;
}
static int F_83 ( struct V_1 * V_2 )
{
return F_82 ( V_2 , & V_2 -> V_25 . V_113 , V_2 -> V_105 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
void * V_32 , int V_205 )
{
int V_91 ;
unsigned long V_113 , V_206 ;
int V_207 = ( V_2 -> V_175 & V_208 ) >> V_209 ;
int V_83 = V_2 -> V_6 -> V_83 ( V_2 ) ;
V_91 = F_82 ( V_2 , & V_113 , V_205 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_206 = V_210 | V_211 | V_212 | V_213 | V_214 | V_215
| V_216 | V_176 | V_217 | V_218 | V_219 ;
switch( V_2 -> V_37 ) {
case V_38 :
case V_220 :
case V_221 :
if ( V_83 == 0 )
V_206 |= V_222 ;
if ( V_83 <= V_207 )
V_206 |= V_223 ;
break;
case V_198 :
if ( V_207 < 3 )
return F_24 ( V_2 , 0 ) ;
V_206 |= V_223 ;
break;
default:
V_206 |= ( V_222 | V_223 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_175 & ~ V_206 ) | ( V_113 & V_206 ) ;
return V_91 ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_131 ;
V_2 -> V_25 . V_76 . V_9 = & V_2 -> V_175 ;
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
return F_84 ( V_2 , & V_2 -> V_25 . V_113 , V_2 -> V_105 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned V_224 = V_2 -> V_22 . V_113 ;
unsigned V_225 = V_2 -> V_226 . V_113 & 31 ;
T_1 V_227 ;
if ( V_225 )
return V_98 ;
V_227 = F_1 ( V_2 , V_135 ) ;
V_91 = F_80 ( V_2 , & V_227 , F_11 ( V_2 ) ) ;
if ( V_91 != V_89 )
return V_91 ;
F_8 ( F_3 ( V_2 , V_135 ) , F_1 ( V_2 , V_43 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_43 ) ,
F_1 ( V_2 , V_43 ) - V_224 ,
F_10 ( V_2 ) ) ;
return V_89 ;
}
static int F_87 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_43 ) , F_1 ( V_2 , V_135 ) ,
F_10 ( V_2 ) ) ;
return F_82 ( V_2 , F_3 ( V_2 , V_135 ) , V_2 -> V_105 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_49 = V_2 -> V_226 . V_113 ;
V_2 -> V_22 . V_113 = F_30 ( V_2 , V_49 ) ;
return F_81 ( V_2 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_49 = V_2 -> V_226 . V_113 ;
unsigned long V_67 ;
int V_91 ;
V_91 = F_82 ( V_2 , & V_67 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_228 = V_229 ;
V_91 = F_77 ( V_2 , ( T_2 ) V_67 , V_49 ) ;
return V_91 ;
}
static int F_90 ( struct V_1 * V_2 )
{
unsigned long V_230 = F_1 ( V_2 , V_43 ) ;
int V_91 = V_89 ;
int V_9 = V_231 ;
while ( V_9 <= V_151 ) {
( V_9 == V_43 ) ?
( V_2 -> V_22 . V_113 = V_230 ) : ( V_2 -> V_22 . V_113 = F_1 ( V_2 , V_9 ) ) ;
V_91 = F_81 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
++ V_9 ;
}
return V_91 ;
}
static int F_91 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_113 = ( unsigned long ) V_2 -> V_175 ;
return F_81 ( V_2 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
int V_9 = V_151 ;
while ( V_9 >= V_231 ) {
if ( V_9 == V_43 ) {
F_17 ( V_2 , V_2 -> V_105 ) ;
-- V_9 ;
}
V_91 = F_82 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
break;
-- V_9 ;
}
return V_91 ;
}
static int F_93 ( struct V_1 * V_2 , int V_232 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
int V_91 ;
struct V_179 V_180 ;
T_7 V_233 ;
T_7 V_234 ;
T_2 V_235 , V_31 ;
V_2 -> V_22 . V_113 = V_2 -> V_175 ;
V_91 = F_81 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_175 &= ~ ( V_223 | V_216 | V_218 ) ;
V_2 -> V_22 . V_113 = F_30 ( V_2 , V_96 ) ;
V_91 = F_81 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_113 = V_2 -> V_45 ;
V_91 = F_81 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_6 -> V_181 ( V_2 , & V_180 ) ;
V_234 = V_180 . V_104 + ( V_232 << 2 ) ;
V_233 = V_180 . V_104 + ( V_232 << 2 ) + 2 ;
V_91 = V_6 -> V_92 ( V_2 , V_233 , & V_235 , 2 , & V_2 -> V_54 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = V_6 -> V_92 ( V_2 , V_234 , & V_31 , 2 , & V_2 -> V_54 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_77 ( V_2 , V_235 , V_96 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_45 = V_31 ;
return V_91 ;
}
int F_94 ( struct V_1 * V_2 , int V_232 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_91 = F_93 ( V_2 , V_232 ) ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return V_91 ;
}
static int F_95 ( struct V_1 * V_2 , int V_232 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_93 ( V_2 , V_232 ) ;
case V_198 :
case V_221 :
case V_220 :
case V_38 :
default:
return V_98 ;
}
}
static int F_96 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
unsigned long V_236 = 0 ;
unsigned long V_237 = 0 ;
unsigned long V_235 = 0 ;
unsigned long V_33 = V_210 | V_211 | V_212 | V_213 | V_214 | V_216 |
V_223 | V_176 | V_215 | V_222 | V_217 | V_238 |
V_218 | V_219 | ( 1 << 1 ) ;
unsigned long V_239 = V_240 | V_241 | V_242 ;
V_91 = F_82 ( V_2 , & V_236 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_236 & ~ 0xffff )
return F_24 ( V_2 , 0 ) ;
V_91 = F_82 ( V_2 , & V_235 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_82 ( V_2 , & V_237 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_91 = F_77 ( V_2 , ( T_2 ) V_235 , V_96 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_45 = V_236 ;
if ( V_2 -> V_105 == 4 )
V_2 -> V_175 = ( ( V_237 & V_33 ) | ( V_2 -> V_175 & V_239 ) ) ;
else if ( V_2 -> V_105 == 2 ) {
V_2 -> V_175 &= ~ 0xffff ;
V_2 -> V_175 |= V_237 ;
}
V_2 -> V_175 &= ~ V_243 ;
V_2 -> V_175 |= V_244 ;
return V_91 ;
}
static int F_97 ( struct V_1 * V_2 )
{
switch( V_2 -> V_37 ) {
case V_86 :
return F_96 ( V_2 ) ;
case V_198 :
case V_221 :
case V_220 :
case V_38 :
default:
return V_98 ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned short V_34 ;
memcpy ( & V_34 , V_2 -> V_22 . V_245 + V_2 -> V_105 , 2 ) ;
V_91 = F_77 ( V_2 , V_34 , V_96 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_45 = 0 ;
memcpy ( & V_2 -> V_45 , V_2 -> V_22 . V_245 , V_2 -> V_105 ) ;
return V_89 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_91 = V_89 ;
switch ( V_2 -> V_19 ) {
case 2 : {
long int V_246 ;
V_246 = V_2 -> V_45 ;
V_2 -> V_45 = V_2 -> V_22 . V_113 ;
V_2 -> V_22 . V_113 = V_246 ;
V_91 = F_81 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_45 = V_2 -> V_22 . V_113 ;
break;
case 5 :
V_91 = F_98 ( V_2 ) ;
break;
case 6 :
V_91 = F_81 ( V_2 ) ;
break;
}
return V_91 ;
}
static int F_100 ( struct V_1 * V_2 )
{
V_114 V_247 = V_2 -> V_25 . V_248 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_98 ;
if ( ( ( T_3 ) ( V_247 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_231 ) ) ||
( ( T_3 ) ( V_247 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_249 ) ) ) {
* F_2 ( V_2 , V_231 ) = ( T_3 ) ( V_247 >> 0 ) ;
* F_2 ( V_2 , V_249 ) = ( T_3 ) ( V_247 >> 32 ) ;
V_2 -> V_175 &= ~ V_213 ;
} else {
V_2 -> V_25 . V_23 = ( ( V_114 ) F_1 ( V_2 , V_174 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_146 ) ;
V_2 -> V_175 |= V_213 ;
}
return V_89 ;
}
static int F_101 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_131 ;
V_2 -> V_25 . V_76 . V_9 = & V_2 -> V_45 ;
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
return F_83 ( V_2 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_91 ;
unsigned long V_235 ;
int V_83 = V_2 -> V_6 -> V_83 ( V_2 ) ;
V_91 = F_82 ( V_2 , & V_2 -> V_45 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_105 == 4 )
V_2 -> V_45 = ( T_3 ) V_2 -> V_45 ;
V_91 = F_82 ( V_2 , & V_235 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
if ( V_2 -> V_37 >= V_221 && ( V_235 & 3 ) > V_83 )
return V_98 ;
V_91 = F_77 ( V_2 , ( T_2 ) V_235 , V_96 ) ;
return V_91 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = F_102 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_113 ) ;
return V_89 ;
}
static int F_104 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_133 = V_2 -> V_25 . V_113 ;
V_2 -> V_25 . V_113 = F_1 ( V_2 , V_231 ) ;
V_2 -> V_22 . V_133 = V_2 -> V_22 . V_113 ;
V_2 -> V_22 . V_113 = V_2 -> V_25 . V_133 ;
F_105 ( V_2 , V_250 ) ;
if ( V_2 -> V_175 & V_213 ) {
V_2 -> V_25 . V_113 = V_2 -> V_22 . V_133 ;
} else {
V_2 -> V_25 . type = V_131 ;
V_2 -> V_25 . V_76 . V_9 = F_3 ( V_2 , V_231 ) ;
V_2 -> V_25 . V_113 = V_2 -> V_25 . V_133 ;
}
return V_89 ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_49 = V_2 -> V_226 . V_113 ;
unsigned short V_34 ;
int V_91 ;
memcpy ( & V_34 , V_2 -> V_22 . V_245 + V_2 -> V_105 , 2 ) ;
V_91 = F_77 ( V_2 , V_34 , V_49 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_25 . V_113 = V_2 -> V_22 . V_113 ;
return V_91 ;
}
static void
F_107 ( struct V_1 * V_2 ,
struct V_35 * V_235 , struct V_35 * V_36 )
{
V_235 -> V_251 = 0 ;
F_75 ( V_235 , 0 ) ;
V_235 -> V_48 = 1 ;
F_76 ( V_235 , 0xfffff ) ;
V_235 -> type = 0x0b ;
V_235 -> V_199 = 1 ;
V_235 -> V_88 = 0 ;
V_235 -> V_101 = 1 ;
V_235 -> V_41 = 1 ;
V_235 -> V_252 = 0 ;
F_75 ( V_36 , 0 ) ;
F_76 ( V_36 , 0xfffff ) ;
V_36 -> V_48 = 1 ;
V_36 -> V_199 = 1 ;
V_36 -> type = 0x03 ;
V_36 -> V_41 = 1 ;
V_36 -> V_88 = 0 ;
V_36 -> V_101 = 1 ;
V_36 -> V_251 = 0 ;
V_36 -> V_252 = 0 ;
}
static bool F_108 ( struct V_1 * V_2 )
{
T_3 V_253 , V_254 , V_255 , V_256 ;
V_253 = V_255 = 0 ;
V_2 -> V_6 -> V_257 ( V_2 , & V_253 , & V_254 , & V_255 , & V_256 ) ;
return V_254 == V_258
&& V_255 == V_259
&& V_256 == V_260 ;
}
static bool F_109 ( struct V_1 * V_2 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
T_3 V_253 , V_254 , V_255 , V_256 ;
if ( V_2 -> V_37 == V_38 )
return true ;
V_253 = 0x00000000 ;
V_255 = 0x00000000 ;
V_6 -> V_257 ( V_2 , & V_253 , & V_254 , & V_255 , & V_256 ) ;
if ( V_254 == V_258 &&
V_255 == V_259 &&
V_256 == V_260 )
return false ;
if ( V_254 == V_261 &&
V_255 == V_262 &&
V_256 == V_263 )
return true ;
if ( V_254 == V_264 &&
V_255 == V_265 &&
V_256 == V_266 )
return true ;
return false ;
}
static int F_110 ( struct V_1 * V_2 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_35 V_235 , V_36 ;
V_114 V_267 ;
T_2 V_268 , V_269 ;
V_114 V_270 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_198 )
return F_26 ( V_2 ) ;
if ( ! ( F_109 ( V_2 ) ) )
return F_26 ( V_2 ) ;
V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
F_107 ( V_2 , & V_235 , & V_36 ) ;
if ( ! ( V_270 & V_273 ) )
return F_26 ( V_2 ) ;
V_6 -> V_271 ( V_2 , V_274 , & V_267 ) ;
V_267 >>= 32 ;
V_268 = ( T_2 ) ( V_267 & 0xfffc ) ;
V_269 = ( T_2 ) ( V_267 + 8 ) ;
if ( V_270 & V_275 ) {
V_235 . V_41 = 0 ;
V_235 . V_251 = 1 ;
}
V_6 -> V_70 ( V_2 , V_268 , & V_235 , 0 , V_96 ) ;
V_6 -> V_70 ( V_2 , V_269 , & V_36 , 0 , V_40 ) ;
* F_2 ( V_2 , V_174 ) = V_2 -> V_45 ;
if ( V_270 & V_275 ) {
#ifdef F_48
* F_2 ( V_2 , V_276 ) = V_2 -> V_175 ;
V_6 -> V_271 ( V_2 ,
V_2 -> V_37 == V_38 ?
V_277 : V_278 , & V_267 ) ;
V_2 -> V_45 = V_267 ;
V_6 -> V_271 ( V_2 , V_279 , & V_267 ) ;
V_2 -> V_175 &= ~ V_267 ;
#endif
} else {
V_6 -> V_271 ( V_2 , V_274 , & V_267 ) ;
V_2 -> V_45 = ( T_3 ) V_267 ;
V_2 -> V_175 &= ~ ( V_240 | V_223 ) ;
}
return V_89 ;
}
static int F_111 ( struct V_1 * V_2 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_35 V_235 , V_36 ;
V_114 V_267 ;
T_2 V_268 , V_269 ;
V_114 V_270 = 0 ;
V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
if ( V_2 -> V_37 == V_86 )
return F_24 ( V_2 , 0 ) ;
if ( ( V_2 -> V_37 == V_220 ) && ( V_270 & V_275 )
&& ! F_108 ( V_2 ) )
return F_26 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
return F_26 ( V_2 ) ;
F_107 ( V_2 , & V_235 , & V_36 ) ;
V_6 -> V_271 ( V_2 , V_280 , & V_267 ) ;
switch ( V_2 -> V_37 ) {
case V_220 :
if ( ( V_267 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
break;
case V_38 :
if ( V_267 == 0x0 )
return F_24 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_175 &= ~ ( V_240 | V_223 ) ;
V_268 = ( T_2 ) V_267 ;
V_268 &= ~ V_281 ;
V_269 = V_268 + 8 ;
V_269 &= ~ V_281 ;
if ( V_2 -> V_37 == V_38 || ( V_270 & V_275 ) ) {
V_235 . V_41 = 0 ;
V_235 . V_251 = 1 ;
}
V_6 -> V_70 ( V_2 , V_268 , & V_235 , 0 , V_96 ) ;
V_6 -> V_70 ( V_2 , V_269 , & V_36 , 0 , V_40 ) ;
V_6 -> V_271 ( V_2 , V_282 , & V_267 ) ;
V_2 -> V_45 = V_267 ;
V_6 -> V_271 ( V_2 , V_283 , & V_267 ) ;
* F_2 ( V_2 , V_43 ) = V_267 ;
return V_89 ;
}
static int F_112 ( struct V_1 * V_2 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_35 V_235 , V_36 ;
V_114 V_267 ;
int V_284 ;
T_2 V_268 = 0 , V_269 = 0 ;
if ( V_2 -> V_37 == V_86 ||
V_2 -> V_37 == V_198 )
return F_24 ( V_2 , 0 ) ;
F_107 ( V_2 , & V_235 , & V_36 ) ;
if ( ( V_2 -> V_103 & 0x8 ) != 0x0 )
V_284 = V_38 ;
else
V_284 = V_220 ;
V_235 . V_88 = 3 ;
V_36 . V_88 = 3 ;
V_6 -> V_271 ( V_2 , V_280 , & V_267 ) ;
switch ( V_284 ) {
case V_220 :
V_268 = ( T_2 ) ( V_267 + 16 ) ;
if ( ( V_267 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_269 = ( T_2 ) ( V_267 + 24 ) ;
break;
case V_38 :
V_268 = ( T_2 ) ( V_267 + 32 ) ;
if ( V_267 == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_269 = V_268 + 8 ;
V_235 . V_41 = 0 ;
V_235 . V_251 = 1 ;
break;
}
V_268 |= V_281 ;
V_269 |= V_281 ;
V_6 -> V_70 ( V_2 , V_268 , & V_235 , 0 , V_96 ) ;
V_6 -> V_70 ( V_2 , V_269 , & V_36 , 0 , V_40 ) ;
V_2 -> V_45 = F_1 ( V_2 , V_249 ) ;
* F_2 ( V_2 , V_43 ) = F_1 ( V_2 , V_174 ) ;
return V_89 ;
}
static bool F_113 ( struct V_1 * V_2 )
{
int V_207 ;
if ( V_2 -> V_37 == V_86 )
return false ;
if ( V_2 -> V_37 == V_198 )
return true ;
V_207 = ( V_2 -> V_175 & V_208 ) >> V_209 ;
return V_2 -> V_6 -> V_83 ( V_2 ) > V_207 ;
}
static bool F_114 ( struct V_1 * V_2 ,
T_2 V_169 , T_2 V_205 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_35 V_285 ;
T_3 V_69 ;
int V_286 ;
T_2 V_287 , V_288 , V_289 , V_290 = V_169 & 0x7 ;
unsigned V_33 = ( 1 << V_205 ) - 1 ;
unsigned long V_291 ;
V_6 -> V_39 ( V_2 , & V_287 , & V_285 , & V_69 , V_200 ) ;
if ( ! V_285 . V_101 )
return false ;
if ( F_19 ( & V_285 ) < 103 )
return false ;
V_291 = F_71 ( & V_285 ) ;
#ifdef F_48
V_291 |= ( ( V_114 ) V_69 ) << 32 ;
#endif
V_286 = V_6 -> V_92 ( V_2 , V_291 + 102 , & V_288 , 2 , NULL ) ;
if ( V_286 != V_89 )
return false ;
if ( V_288 + V_169 / 8 > F_19 ( & V_285 ) )
return false ;
V_286 = V_6 -> V_92 ( V_2 , V_291 + V_288 + V_169 / 8 , & V_289 , 2 , NULL ) ;
if ( V_286 != V_89 )
return false ;
if ( ( V_289 >> V_290 ) & V_33 )
return false ;
return true ;
}
static bool F_115 ( struct V_1 * V_2 ,
T_2 V_169 , T_2 V_205 )
{
if ( V_2 -> V_292 )
return true ;
if ( F_113 ( V_2 ) )
if ( ! F_114 ( V_2 , V_169 , V_205 ) )
return false ;
V_2 -> V_292 = true ;
return true ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
V_294 -> V_295 = V_2 -> V_45 ;
V_294 -> V_296 = V_2 -> V_175 ;
V_294 -> V_297 = F_1 ( V_2 , V_231 ) ;
V_294 -> V_298 = F_1 ( V_2 , V_174 ) ;
V_294 -> V_299 = F_1 ( V_2 , V_249 ) ;
V_294 -> V_145 = F_1 ( V_2 , V_146 ) ;
V_294 -> V_300 = F_1 ( V_2 , V_43 ) ;
V_294 -> V_147 = F_1 ( V_2 , V_135 ) ;
V_294 -> V_148 = F_1 ( V_2 , V_149 ) ;
V_294 -> V_150 = F_1 ( V_2 , V_151 ) ;
V_294 -> V_301 = F_30 ( V_2 , V_302 ) ;
V_294 -> V_235 = F_30 ( V_2 , V_96 ) ;
V_294 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_294 -> V_303 = F_30 ( V_2 , V_142 ) ;
V_294 -> V_304 = F_30 ( V_2 , V_183 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
int V_195 ;
T_5 V_83 ;
V_2 -> V_45 = V_294 -> V_295 ;
V_2 -> V_175 = V_294 -> V_296 | 2 ;
* F_2 ( V_2 , V_231 ) = V_294 -> V_297 ;
* F_2 ( V_2 , V_174 ) = V_294 -> V_298 ;
* F_2 ( V_2 , V_249 ) = V_294 -> V_299 ;
* F_2 ( V_2 , V_146 ) = V_294 -> V_145 ;
* F_2 ( V_2 , V_43 ) = V_294 -> V_300 ;
* F_2 ( V_2 , V_135 ) = V_294 -> V_147 ;
* F_2 ( V_2 , V_149 ) = V_294 -> V_148 ;
* F_2 ( V_2 , V_151 ) = V_294 -> V_150 ;
F_31 ( V_2 , V_294 -> V_304 , V_183 ) ;
F_31 ( V_2 , V_294 -> V_301 , V_302 ) ;
F_31 ( V_2 , V_294 -> V_235 , V_96 ) ;
F_31 ( V_2 , V_294 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_294 -> V_303 , V_142 ) ;
V_83 = V_294 -> V_235 & 3 ;
V_195 = F_74 ( V_2 , V_294 -> V_304 , V_183 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_301 , V_302 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_235 , V_96 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_36 , V_40 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_303 , V_142 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
return V_89 ;
}
static int F_118 ( struct V_1 * V_2 ,
T_2 V_305 , T_2 V_306 ,
T_1 V_307 , struct V_35 * V_308 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_293 V_309 ;
int V_195 ;
T_3 V_310 = F_71 ( V_308 ) ;
V_195 = V_6 -> V_92 ( V_2 , V_307 , & V_309 , sizeof V_309 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
F_116 ( V_2 , & V_309 ) ;
V_195 = V_6 -> V_186 ( V_2 , V_307 , & V_309 , sizeof V_309 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = V_6 -> V_92 ( V_2 , V_310 , & V_309 , sizeof V_309 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
if ( V_306 != 0xffff ) {
V_309 . V_311 = V_306 ;
V_195 = V_6 -> V_186 ( V_2 , V_310 ,
& V_309 . V_311 ,
sizeof V_309 . V_311 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
}
return F_117 ( V_2 , & V_309 ) ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_312 * V_294 )
{
V_294 -> V_31 = V_2 -> V_45 ;
V_294 -> V_175 = V_2 -> V_175 ;
V_294 -> V_253 = F_1 ( V_2 , V_231 ) ;
V_294 -> V_255 = F_1 ( V_2 , V_174 ) ;
V_294 -> V_256 = F_1 ( V_2 , V_249 ) ;
V_294 -> V_254 = F_1 ( V_2 , V_146 ) ;
V_294 -> V_313 = F_1 ( V_2 , V_43 ) ;
V_294 -> V_314 = F_1 ( V_2 , V_135 ) ;
V_294 -> V_315 = F_1 ( V_2 , V_149 ) ;
V_294 -> V_316 = F_1 ( V_2 , V_151 ) ;
V_294 -> V_301 = F_30 ( V_2 , V_302 ) ;
V_294 -> V_235 = F_30 ( V_2 , V_96 ) ;
V_294 -> V_36 = F_30 ( V_2 , V_40 ) ;
V_294 -> V_303 = F_30 ( V_2 , V_142 ) ;
V_294 -> V_317 = F_30 ( V_2 , V_50 ) ;
V_294 -> V_318 = F_30 ( V_2 , V_197 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_312 * V_294 )
{
int V_195 ;
T_5 V_83 ;
if ( V_2 -> V_6 -> V_319 ( V_2 , 3 , V_294 -> V_320 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_45 = V_294 -> V_31 ;
V_2 -> V_175 = V_294 -> V_175 | 2 ;
* F_2 ( V_2 , V_231 ) = V_294 -> V_253 ;
* F_2 ( V_2 , V_174 ) = V_294 -> V_255 ;
* F_2 ( V_2 , V_249 ) = V_294 -> V_256 ;
* F_2 ( V_2 , V_146 ) = V_294 -> V_254 ;
* F_2 ( V_2 , V_43 ) = V_294 -> V_313 ;
* F_2 ( V_2 , V_135 ) = V_294 -> V_314 ;
* F_2 ( V_2 , V_149 ) = V_294 -> V_315 ;
* F_2 ( V_2 , V_151 ) = V_294 -> V_316 ;
F_31 ( V_2 , V_294 -> V_321 , V_183 ) ;
F_31 ( V_2 , V_294 -> V_301 , V_302 ) ;
F_31 ( V_2 , V_294 -> V_235 , V_96 ) ;
F_31 ( V_2 , V_294 -> V_36 , V_40 ) ;
F_31 ( V_2 , V_294 -> V_303 , V_142 ) ;
F_31 ( V_2 , V_294 -> V_317 , V_50 ) ;
F_31 ( V_2 , V_294 -> V_318 , V_197 ) ;
if ( V_2 -> V_175 & V_322 ) {
V_2 -> V_37 = V_198 ;
V_83 = 3 ;
} else {
V_2 -> V_37 = V_220 ;
V_83 = V_294 -> V_235 & 3 ;
}
V_195 = F_74 ( V_2 , V_294 -> V_321 , V_183 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_301 , V_302 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_235 , V_96 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_36 , V_40 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_303 , V_142 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_317 , V_50 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_74 ( V_2 , V_294 -> V_318 , V_197 , V_83 , true ) ;
if ( V_195 != V_89 )
return V_195 ;
return V_89 ;
}
static int F_121 ( struct V_1 * V_2 ,
T_2 V_305 , T_2 V_306 ,
T_1 V_307 , struct V_35 * V_308 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_312 V_309 ;
int V_195 ;
T_3 V_310 = F_71 ( V_308 ) ;
T_3 V_323 = F_122 ( struct V_312 , V_31 ) ;
T_3 V_324 = F_122 ( struct V_312 , V_321 ) ;
V_195 = V_6 -> V_92 ( V_2 , V_307 , & V_309 , sizeof V_309 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
F_119 ( V_2 , & V_309 ) ;
V_195 = V_6 -> V_186 ( V_2 , V_307 + V_323 , & V_309 . V_31 ,
V_324 - V_323 , & V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = V_6 -> V_92 ( V_2 , V_310 , & V_309 , sizeof V_309 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
if ( V_306 != 0xffff ) {
V_309 . V_311 = V_306 ;
V_195 = V_6 -> V_186 ( V_2 , V_310 ,
& V_309 . V_311 ,
sizeof V_309 . V_311 ,
& V_2 -> V_54 ) ;
if ( V_195 != V_89 )
return V_195 ;
}
return F_120 ( V_2 , & V_309 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
T_2 V_305 , int V_325 , int V_326 ,
bool V_327 , T_3 V_56 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
struct V_35 V_328 , V_329 ;
int V_195 ;
T_2 V_306 = F_30 ( V_2 , V_200 ) ;
T_1 V_307 =
V_6 -> V_51 ( V_2 , V_200 ) ;
T_3 V_330 ;
T_1 V_194 ;
V_195 = F_72 ( V_2 , V_305 , & V_329 , & V_194 ) ;
if ( V_195 != V_89 )
return V_195 ;
V_195 = F_72 ( V_2 , V_306 , & V_328 , & V_194 ) ;
if ( V_195 != V_89 )
return V_195 ;
if ( V_326 == V_331 ) {
if ( V_325 != - 1 ) {
struct V_35 V_332 ;
int V_88 ;
V_195 = F_69 ( V_2 , V_325 ,
& V_332 ) ;
if ( V_195 != V_89 )
return V_195 ;
V_88 = V_332 . V_88 ;
if ( ( V_305 & 3 ) > V_88 || V_6 -> V_83 ( V_2 ) > V_88 )
return F_24 ( V_2 , ( V_325 << 3 ) | 0x2 ) ;
}
} else if ( V_326 != V_333 ) {
int V_88 = V_329 . V_88 ;
if ( ( V_305 & 3 ) > V_88 || V_6 -> V_83 ( V_2 ) > V_88 )
return F_24 ( V_2 , V_305 ) ;
}
V_330 = F_19 ( & V_329 ) ;
if ( ! V_329 . V_101 ||
( ( V_330 < 0x67 && ( V_329 . type & 8 ) ) ||
V_330 < 0x2b ) ) {
F_27 ( V_2 , V_305 & 0xfffc ) ;
return V_58 ;
}
if ( V_326 == V_333 || V_326 == V_334 ) {
V_328 . type &= ~ ( 1 << 1 ) ;
F_73 ( V_2 , V_306 , & V_328 ) ;
}
if ( V_326 == V_333 )
V_2 -> V_175 = V_2 -> V_175 & ~ V_335 ;
if ( V_326 != V_336 && V_326 != V_331 )
V_306 = 0xffff ;
if ( V_329 . type & 8 )
V_195 = F_121 ( V_2 , V_305 , V_306 ,
V_307 , & V_329 ) ;
else
V_195 = F_118 ( V_2 , V_305 , V_306 ,
V_307 , & V_329 ) ;
if ( V_195 != V_89 )
return V_195 ;
if ( V_326 == V_336 || V_326 == V_331 )
V_2 -> V_175 = V_2 -> V_175 | V_335 ;
if ( V_326 != V_333 ) {
V_329 . type |= ( 1 << 1 ) ;
F_73 ( V_2 , V_305 , & V_329 ) ;
}
V_6 -> V_319 ( V_2 , 0 , V_6 -> V_117 ( V_2 , 0 ) | V_118 ) ;
V_6 -> V_70 ( V_2 , V_305 , & V_329 , 0 , V_200 ) ;
if ( V_327 ) {
V_2 -> V_105 = V_2 -> V_29 = ( V_329 . type & 8 ) ? 4 : 2 ;
V_2 -> V_202 = 0 ;
V_2 -> V_22 . V_113 = ( unsigned long ) V_56 ;
V_195 = F_81 ( V_2 ) ;
}
return V_195 ;
}
int F_124 ( struct V_1 * V_2 ,
T_2 V_305 , int V_325 , int V_326 ,
bool V_327 , T_3 V_56 )
{
int V_91 ;
F_6 ( V_2 ) ;
V_2 -> V_45 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_204 ;
V_91 = F_123 ( V_2 , V_305 , V_325 , V_326 ,
V_327 , V_56 ) ;
if ( V_91 == V_89 ) {
V_2 -> V_31 = V_2 -> V_45 ;
F_4 ( V_2 ) ;
}
return ( V_91 == V_98 ) ? V_337 : V_338 ;
}
static void F_125 ( struct V_1 * V_2 , int V_9 ,
struct V_111 * V_112 )
{
int V_339 = ( V_2 -> V_175 & V_176 ) ? - V_112 -> V_173 : V_112 -> V_173 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_339 * V_112 -> V_27 ) ;
V_112 -> V_76 . V_155 . V_84 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
T_5 V_340 , V_341 ;
bool V_342 , V_343 , V_344 ;
V_343 = V_2 -> V_175 & V_345 ;
V_340 = V_2 -> V_25 . V_113 ;
V_341 = V_340 ;
V_344 = V_343 ;
V_343 = false ;
V_342 = V_2 -> V_175 & V_346 ;
if ( ( V_340 & 0x0f ) > 9 || V_342 ) {
V_340 -= 6 ;
V_343 = V_344 | ( V_340 >= 250 ) ;
V_342 = true ;
} else {
V_342 = false ;
}
if ( V_341 > 0x99 || V_344 ) {
V_340 -= 0x60 ;
V_343 = true ;
}
V_2 -> V_25 . V_113 = V_340 ;
V_2 -> V_22 . type = V_347 ;
V_2 -> V_22 . V_113 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_105 ( V_2 , V_348 ) ;
V_2 -> V_175 &= ~ ( V_346 | V_345 ) ;
if ( V_343 )
V_2 -> V_175 |= V_345 ;
if ( V_342 )
V_2 -> V_175 |= V_346 ;
return V_89 ;
}
static int F_127 ( struct V_1 * V_2 )
{
T_5 V_340 , V_349 ;
if ( V_2 -> V_22 . V_113 == 0 )
return F_28 ( V_2 ) ;
V_340 = V_2 -> V_25 . V_113 & 0xff ;
V_349 = V_340 / V_2 -> V_22 . V_113 ;
V_340 %= V_2 -> V_22 . V_113 ;
V_2 -> V_25 . V_113 = ( V_2 -> V_25 . V_113 & 0xffff0000 ) | V_340 | ( V_349 << 8 ) ;
V_2 -> V_22 . type = V_347 ;
V_2 -> V_22 . V_113 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_105 ( V_2 , V_348 ) ;
return V_89 ;
}
static int F_128 ( struct V_1 * V_2 )
{
T_5 V_340 = V_2 -> V_25 . V_113 & 0xff ;
T_5 V_349 = ( V_2 -> V_25 . V_113 >> 8 ) & 0xff ;
V_340 = ( V_340 + ( V_349 * V_2 -> V_22 . V_113 ) ) & 0xff ;
V_2 -> V_25 . V_113 = ( V_2 -> V_25 . V_113 & 0xffff0000 ) | V_340 ;
V_2 -> V_22 . type = V_347 ;
V_2 -> V_22 . V_113 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_105 ( V_2 , V_348 ) ;
return V_89 ;
}
static int F_129 ( struct V_1 * V_2 )
{
long V_44 = V_2 -> V_22 . V_113 ;
V_2 -> V_22 . V_113 = ( unsigned long ) V_2 -> V_45 ;
F_18 ( V_2 , V_44 ) ;
return F_81 ( V_2 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
T_2 V_34 , V_350 ;
T_1 V_246 ;
int V_91 ;
V_350 = F_30 ( V_2 , V_96 ) ;
V_246 = V_2 -> V_45 ;
memcpy ( & V_34 , V_2 -> V_22 . V_245 + V_2 -> V_105 , 2 ) ;
if ( F_77 ( V_2 , V_34 , V_96 ) )
return V_89 ;
V_2 -> V_45 = 0 ;
memcpy ( & V_2 -> V_45 , V_2 -> V_22 . V_245 , V_2 -> V_105 ) ;
V_2 -> V_22 . V_113 = V_350 ;
V_91 = F_81 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_22 . V_113 = V_246 ;
return F_81 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_91 ;
V_2 -> V_25 . type = V_131 ;
V_2 -> V_25 . V_76 . V_9 = & V_2 -> V_45 ;
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
V_91 = F_82 ( V_2 , & V_2 -> V_25 . V_113 , V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
F_17 ( V_2 , V_2 -> V_22 . V_113 ) ;
return V_89 ;
}
static int F_132 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_113 = V_2 -> V_25 . V_113 ;
F_78 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_113 = V_2 -> V_22 . V_133 ;
V_2 -> V_202 = 1 ;
return V_89 ;
}
static int F_133 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_113 = V_2 -> V_226 . V_113 ;
return F_105 ( V_2 , V_351 ) ;
}
static int F_134 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_131 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_76 . V_9 = F_3 ( V_2 , V_249 ) ;
V_2 -> V_25 . V_113 = ~ ( ( V_2 -> V_22 . V_113 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_89 ;
}
static int F_135 ( struct V_1 * V_2 )
{
V_114 V_352 = 0 ;
V_2 -> V_6 -> V_271 ( V_2 , V_353 , & V_352 ) ;
* F_2 ( V_2 , V_231 ) = ( T_3 ) V_352 ;
* F_2 ( V_2 , V_249 ) = V_352 >> 32 ;
return V_89 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_114 V_354 ;
if ( V_2 -> V_6 -> V_355 ( V_2 , F_1 ( V_2 , V_174 ) , & V_354 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_231 ) = ( T_3 ) V_354 ;
* F_2 ( V_2 , V_249 ) = V_354 >> 32 ;
return V_89 ;
}
static int F_137 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_245 , V_2 -> V_22 . V_245 , sizeof( V_2 -> V_22 . V_245 ) ) ;
return V_89 ;
}
static int F_138 ( struct V_1 * V_2 )
{
T_3 V_254 , V_255 , V_256 , V_253 = 1 ;
T_2 V_356 ;
V_2 -> V_6 -> V_257 ( V_2 , & V_253 , & V_254 , & V_255 , & V_256 ) ;
if ( ! ( V_255 & F_139 ( V_357 ) ) )
return F_26 ( V_2 ) ;
switch ( V_2 -> V_105 ) {
case 2 :
V_356 = ( T_2 ) V_2 -> V_22 . V_113 ;
V_2 -> V_25 . V_113 &= ~ 0xffffUL ;
V_2 -> V_25 . V_113 |= ( unsigned long ) F_140 ( V_356 ) ;
break;
case 4 :
V_2 -> V_25 . V_113 = F_141 ( ( T_3 ) V_2 -> V_22 . V_113 ) ;
break;
case 8 :
V_2 -> V_25 . V_113 = F_142 ( V_2 -> V_22 . V_113 ) ;
break;
default:
return V_58 ;
}
return V_89 ;
}
static int F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_319 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_113 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_144 ( struct V_1 * V_2 )
{
unsigned long V_113 ;
if ( V_2 -> V_37 == V_38 )
V_113 = V_2 -> V_22 . V_113 & ~ 0ULL ;
else
V_113 = V_2 -> V_22 . V_113 & ~ 0U ;
if ( V_2 -> V_6 -> V_358 ( V_2 , V_2 -> V_19 , V_113 ) < 0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_145 ( struct V_1 * V_2 )
{
V_114 V_267 ;
V_267 = ( T_3 ) F_1 ( V_2 , V_231 )
| ( ( V_114 ) F_1 ( V_2 , V_249 ) << 32 ) ;
if ( V_2 -> V_6 -> V_359 ( V_2 , F_1 ( V_2 , V_174 ) , V_267 ) )
return F_24 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_146 ( struct V_1 * V_2 )
{
V_114 V_267 ;
if ( V_2 -> V_6 -> V_271 ( V_2 , F_1 ( V_2 , V_174 ) , & V_267 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_231 ) = ( T_3 ) V_267 ;
* F_2 ( V_2 , V_249 ) = V_267 >> 32 ;
return V_89 ;
}
static int F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_197 )
return F_26 ( V_2 ) ;
V_2 -> V_25 . V_113 = F_30 ( V_2 , V_2 -> V_19 ) ;
return V_89 ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_113 ;
if ( V_2 -> V_19 == V_96 || V_2 -> V_19 > V_197 )
return F_26 ( V_2 ) ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_228 = V_229 ;
V_2 -> V_25 . type = V_204 ;
return F_77 ( V_2 , V_34 , V_2 -> V_19 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_113 ;
V_2 -> V_25 . type = V_204 ;
return F_77 ( V_2 , V_34 , V_183 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_113 ;
V_2 -> V_25 . type = V_204 ;
return F_77 ( V_2 , V_34 , V_200 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_91 ;
T_1 V_79 ;
V_91 = F_35 ( V_2 , V_2 -> V_22 . V_76 . V_155 , 1 , false , & V_79 ) ;
if ( V_91 == V_89 )
V_2 -> V_6 -> V_360 ( V_2 , V_79 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_152 ( struct V_1 * V_2 )
{
T_1 V_361 ;
V_361 = V_2 -> V_6 -> V_117 ( V_2 , 0 ) ;
V_361 &= ~ V_118 ;
V_2 -> V_6 -> V_319 ( V_2 , 0 , V_361 ) ;
return V_89 ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_91 ;
if ( V_2 -> V_18 != 3 || V_2 -> V_20 != 1 )
return V_98 ;
V_91 = V_2 -> V_6 -> V_362 ( V_2 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_45 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_154 ( struct V_1 * V_2 ,
void (* F_155)( struct V_1 * V_2 ,
struct V_179 * V_99 ) )
{
struct V_179 V_179 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_105 = 8 ;
F_155 ( V_2 , & V_179 ) ;
if ( V_2 -> V_105 == 2 ) {
V_2 -> V_105 = 4 ;
V_179 . V_104 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_204 ;
return F_65 ( V_2 , V_2 -> V_25 . V_76 . V_155 ,
& V_179 , 2 + V_2 -> V_105 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
return F_154 ( V_2 , V_2 -> V_6 -> V_184 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
return F_154 ( V_2 , V_2 -> V_6 -> V_181 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_179 V_179 ;
int V_91 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_105 = 8 ;
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_76 . V_155 ,
& V_179 . V_71 , & V_179 . V_104 ,
V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_363 ( V_2 , & V_179 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = V_2 -> V_6 -> V_362 ( V_2 ) ;
V_2 -> V_25 . type = V_204 ;
return V_91 ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_179 V_179 ;
int V_91 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_105 = 8 ;
V_91 = F_43 ( V_2 , V_2 -> V_22 . V_76 . V_155 ,
& V_179 . V_71 , & V_179 . V_104 ,
V_2 -> V_105 ) ;
if ( V_91 != V_89 )
return V_91 ;
V_2 -> V_6 -> V_364 ( V_2 , & V_179 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_161 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_144 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_113 = V_2 -> V_6 -> V_117 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_162 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_319 ( V_2 , 0 , ( V_2 -> V_6 -> V_117 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_113 & 0x0f ) ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_163 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_3 ( V_2 , V_174 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_174 ) ) != 0 ) &&
( V_2 -> V_123 == 0xe2 || F_44 ( V_2 -> V_123 ^ 0x5 , V_2 -> V_175 ) ) )
F_18 ( V_2 , V_2 -> V_22 . V_113 ) ;
return V_89 ;
}
static int F_164 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , F_1 ( V_2 , V_174 ) ) == 0 )
F_18 ( V_2 , V_2 -> V_22 . V_113 ) ;
return V_89 ;
}
static int F_165 ( struct V_1 * V_2 )
{
if ( ! F_67 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_113 ,
& V_2 -> V_25 . V_113 ) )
return V_365 ;
return V_89 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_366 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_113 ,
& V_2 -> V_22 . V_113 , 1 ) ;
V_2 -> V_25 . type = V_204 ;
return V_89 ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( F_113 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_175 &= ~ V_110 ;
return V_89 ;
}
static int F_168 ( struct V_1 * V_2 )
{
if ( F_113 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_228 = V_367 ;
V_2 -> V_175 |= V_110 ;
return V_89 ;
}
static int F_169 ( struct V_1 * V_2 )
{
T_3 V_253 , V_254 , V_255 , V_256 ;
V_253 = F_1 ( V_2 , V_231 ) ;
V_255 = F_1 ( V_2 , V_174 ) ;
V_2 -> V_6 -> V_257 ( V_2 , & V_253 , & V_254 , & V_255 , & V_256 ) ;
* F_2 ( V_2 , V_231 ) = V_253 ;
* F_2 ( V_2 , V_146 ) = V_254 ;
* F_2 ( V_2 , V_174 ) = V_255 ;
* F_2 ( V_2 , V_249 ) = V_256 ;
return V_89 ;
}
static int F_170 ( struct V_1 * V_2 )
{
T_3 V_107 ;
V_107 = V_210 | V_211 | V_212 | V_213 | V_214 ;
V_107 &= * F_3 ( V_2 , V_231 ) >> 8 ;
V_2 -> V_175 &= ~ 0xffUL ;
V_2 -> V_175 |= V_107 | V_368 ;
return V_89 ;
}
static int F_171 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_231 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_231 ) |= ( V_2 -> V_175 & 0xff ) << 8 ;
return V_89 ;
}
static int F_172 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_105 ) {
#ifdef F_48
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
static bool F_173 ( int V_3 )
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
static int F_174 ( struct V_1 * V_2 )
{
if ( ! F_173 ( V_2 -> V_19 ) )
return F_26 ( V_2 ) ;
return V_89 ;
}
static int F_175 ( struct V_1 * V_2 )
{
V_114 V_369 = V_2 -> V_22 . V_23 ;
int V_370 = V_2 -> V_19 ;
V_114 V_270 = 0 ;
static V_114 V_371 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_372 ,
0 , 0 , 0 ,
V_373 ,
} ;
if ( ! F_173 ( V_370 ) )
return F_26 ( V_2 ) ;
if ( V_369 & V_371 [ V_370 ] )
return F_24 ( V_2 , 0 ) ;
switch ( V_370 ) {
case 0 : {
V_114 V_374 ;
if ( ( ( V_369 & V_375 ) && ! ( V_369 & V_376 ) ) ||
( ( V_369 & V_377 ) && ! ( V_369 & V_378 ) ) )
return F_24 ( V_2 , 0 ) ;
V_374 = V_2 -> V_6 -> V_117 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
if ( ( V_369 & V_375 ) && ( V_270 & V_379 ) &&
! ( V_374 & V_380 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_114 V_381 = 0 ;
V_2 -> V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
if ( V_270 & V_275 )
V_381 = V_382 ;
if ( V_369 & V_381 )
return F_24 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
if ( ( V_270 & V_275 ) && ! ( V_369 & V_380 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
}
return V_89 ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned long V_383 ;
V_2 -> V_6 -> V_384 ( V_2 , 7 , & V_383 ) ;
return V_383 & ( 1 << 13 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
int V_385 = V_2 -> V_19 ;
V_114 V_374 ;
if ( V_385 > 7 )
return F_26 ( V_2 ) ;
V_374 = V_2 -> V_6 -> V_117 ( V_2 , 4 ) ;
if ( ( V_374 & V_386 ) && ( V_385 == 4 || V_385 == 5 ) )
return F_26 ( V_2 ) ;
if ( F_176 ( V_2 ) )
return F_23 ( V_2 ) ;
return V_89 ;
}
static int F_178 ( struct V_1 * V_2 )
{
V_114 V_369 = V_2 -> V_22 . V_23 ;
int V_385 = V_2 -> V_19 ;
if ( ( V_385 == 6 || V_385 == 7 ) && ( V_369 & 0xffffffff00000000ULL ) )
return F_24 ( V_2 , 0 ) ;
return F_177 ( V_2 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
V_114 V_270 ;
V_2 -> V_6 -> V_271 ( V_2 , V_272 , & V_270 ) ;
if ( ! ( V_270 & V_387 ) )
return F_26 ( V_2 ) ;
return V_89 ;
}
static int F_180 ( struct V_1 * V_2 )
{
V_114 V_388 = F_1 ( V_2 , V_231 ) ;
if ( V_388 & 0xffff000000000000ULL )
return F_24 ( V_2 , 0 ) ;
return F_179 ( V_2 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
V_114 V_374 = V_2 -> V_6 -> V_117 ( V_2 , 4 ) ;
if ( V_374 & V_389 && V_2 -> V_6 -> V_83 ( V_2 ) )
return F_26 ( V_2 ) ;
return V_89 ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_114 V_374 = V_2 -> V_6 -> V_117 ( V_2 , 4 ) ;
V_114 V_390 = F_1 ( V_2 , V_174 ) ;
if ( ( ! ( V_374 & V_391 ) && V_2 -> V_6 -> V_83 ( V_2 ) ) ||
V_2 -> V_6 -> V_392 ( V_2 , V_390 ) )
return F_24 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_183 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_184 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_115 ( V_2 , V_2 -> V_22 . V_113 , V_2 -> V_25 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_89 ;
}
static int F_185 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_184 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_115 ( V_2 , V_2 -> V_25 . V_113 , V_2 -> V_22 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_89 ;
}
static unsigned F_186 ( struct V_1 * V_2 )
{
unsigned V_71 ;
V_71 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
if ( V_71 == 8 )
V_71 = 4 ;
return V_71 ;
}
static int F_187 ( struct V_1 * V_2 , struct V_111 * V_112 ,
unsigned V_71 , bool V_393 )
{
int V_91 = V_89 ;
V_112 -> type = V_347 ;
V_112 -> V_27 = V_71 ;
V_112 -> V_76 . V_155 . V_84 = V_2 -> V_45 ;
switch ( V_112 -> V_27 ) {
case 1 :
V_112 -> V_113 = F_59 ( V_152 , V_2 ) ;
break;
case 2 :
V_112 -> V_113 = F_59 ( V_159 , V_2 ) ;
break;
case 4 :
V_112 -> V_113 = F_59 ( V_153 , V_2 ) ;
break;
case 8 :
V_112 -> V_113 = F_59 ( V_160 , V_2 ) ;
break;
}
if ( ! V_393 ) {
switch ( V_112 -> V_27 ) {
case 1 :
V_112 -> V_113 &= 0xff ;
break;
case 2 :
V_112 -> V_113 &= 0xffff ;
break;
case 4 :
V_112 -> V_113 &= 0xffffffff ;
break;
}
}
V_157:
return V_91 ;
}
static int F_188 ( struct V_1 * V_2 , struct V_111 * V_112 ,
unsigned V_41 )
{
int V_91 = V_89 ;
switch ( V_41 ) {
case V_394 :
F_56 ( V_2 , V_112 ) ;
break;
case V_395 :
V_91 = F_187 ( V_2 , V_112 , 1 , false ) ;
break;
case V_396 :
V_2 -> V_156 . V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_397:
* V_112 = V_2 -> V_156 ;
V_2 -> V_398 = V_112 ;
if ( V_2 -> V_41 & V_399 )
F_61 ( V_2 ) ;
V_112 -> V_133 = V_112 -> V_113 ;
break;
case V_400 :
V_2 -> V_156 . V_27 = ( V_2 -> V_105 == 8 ) ? 16 : 8 ;
goto V_397;
case V_401 :
V_112 -> type = V_131 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_9 = F_3 ( V_2 , V_231 ) ;
F_46 ( V_112 ) ;
V_112 -> V_133 = V_112 -> V_113 ;
break;
case V_402 :
V_112 -> type = V_131 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 2 : V_2 -> V_105 ;
V_112 -> V_76 . V_9 = F_3 ( V_2 , V_231 ) ;
F_46 ( V_112 ) ;
V_112 -> V_133 = V_112 -> V_113 ;
break;
case V_403 :
if ( V_2 -> V_41 & V_132 ) {
V_112 -> type = V_204 ;
break;
}
V_112 -> type = V_131 ;
V_112 -> V_27 = V_2 -> V_105 ;
V_112 -> V_76 . V_9 = F_3 ( V_2 , V_249 ) ;
F_46 ( V_112 ) ;
V_112 -> V_133 = V_112 -> V_113 ;
break;
case V_404 :
V_112 -> type = V_144 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_155 . V_84 =
F_14 ( V_2 , F_1 ( V_2 , V_151 ) ) ;
V_112 -> V_76 . V_155 . V_49 = V_302 ;
V_112 -> V_113 = 0 ;
V_112 -> V_173 = 1 ;
break;
case V_405 :
V_112 -> type = V_131 ;
V_112 -> V_27 = 2 ;
V_112 -> V_76 . V_9 = F_3 ( V_2 , V_249 ) ;
F_46 ( V_112 ) ;
break;
case V_406 :
V_112 -> V_27 = 1 ;
V_112 -> V_113 = F_1 ( V_2 , V_174 ) & 0xff ;
break;
case V_407 :
V_91 = F_187 ( V_2 , V_112 , 1 , true ) ;
break;
case V_408 :
V_112 -> V_27 = 1 ;
V_112 -> V_113 = 1 ;
break;
case V_409 :
V_91 = F_187 ( V_2 , V_112 , F_186 ( V_2 ) , true ) ;
break;
case V_410 :
V_91 = F_187 ( V_2 , V_112 , V_2 -> V_105 , true ) ;
break;
case V_411 :
V_2 -> V_156 . V_27 = 1 ;
if ( V_2 -> V_156 . type == V_131 ) {
V_2 -> V_156 . V_76 . V_9 = F_42 ( V_2 ,
V_2 -> V_20 , true ) ;
F_46 ( & V_2 -> V_156 ) ;
}
goto V_397;
case V_412 :
V_2 -> V_156 . V_27 = 2 ;
goto V_397;
case V_413 :
V_2 -> V_156 . V_27 = 4 ;
goto V_397;
case V_414 :
V_91 = F_187 ( V_2 , V_112 , 2 , false ) ;
break;
case V_415 :
V_91 = F_187 ( V_2 , V_112 , F_186 ( V_2 ) , false ) ;
break;
case V_416 :
V_112 -> type = V_144 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_155 . V_84 =
F_14 ( V_2 , F_1 ( V_2 , V_149 ) ) ;
V_112 -> V_76 . V_155 . V_49 = V_2 -> V_417 ;
V_112 -> V_113 = 0 ;
V_112 -> V_173 = 1 ;
break;
case V_418 :
V_112 -> type = V_144 ;
V_112 -> V_27 = ( V_2 -> V_41 & V_132 ) ? 1 : V_2 -> V_105 ;
V_112 -> V_76 . V_155 . V_84 =
F_14 ( V_2 ,
F_1 ( V_2 , V_146 ) +
( F_1 ( V_2 , V_231 ) & 0xff ) ) ;
V_112 -> V_76 . V_155 . V_49 = V_2 -> V_417 ;
V_112 -> V_113 = 0 ;
break;
case V_419 :
V_112 -> type = V_347 ;
V_112 -> V_76 . V_155 . V_84 = V_2 -> V_45 ;
V_112 -> V_27 = V_2 -> V_105 + 2 ;
F_189 ( V_112 -> V_245 , V_112 -> V_27 , V_2 ) ;
break;
case V_420 :
V_2 -> V_156 . V_27 = V_2 -> V_105 + 2 ;
goto V_397;
case V_421 :
V_112 -> V_113 = V_302 ;
break;
case V_422 :
V_112 -> V_113 = V_96 ;
break;
case V_423 :
V_112 -> V_113 = V_40 ;
break;
case V_424 :
V_112 -> V_113 = V_142 ;
break;
case V_425 :
V_112 -> V_113 = V_50 ;
break;
case V_426 :
V_112 -> V_113 = V_197 ;
break;
case V_427 :
default:
V_112 -> type = V_204 ;
break;
}
V_157:
return V_91 ;
}
int F_190 ( struct V_1 * V_2 , void * V_428 , int V_429 )
{
int V_91 = V_89 ;
int V_37 = V_2 -> V_37 ;
int V_430 , V_431 , V_432 , V_433 ;
bool V_434 = false ;
bool V_435 = false ;
struct V_436 V_436 ;
V_2 -> V_156 . type = V_204 ;
V_2 -> V_398 = NULL ;
V_2 -> V_45 = V_2 -> V_31 ;
V_2 -> V_78 . V_99 = V_2 -> V_78 . V_90 ;
V_2 -> V_78 . V_95 = V_2 -> V_78 . V_90 + V_429 ;
V_2 -> V_437 = 1 ;
if ( V_429 > 0 )
memcpy ( V_2 -> V_78 . V_90 , V_428 , V_429 ) ;
else {
V_91 = F_37 ( V_2 , 1 ) ;
if ( V_91 != V_89 )
return V_91 ;
}
switch ( V_37 ) {
case V_86 :
case V_198 :
case V_221 :
V_430 = V_431 = 2 ;
break;
case V_220 :
V_430 = V_431 = 4 ;
break;
#ifdef F_48
case V_38 :
V_430 = 4 ;
V_431 = 8 ;
break;
#endif
default:
return V_337 ;
}
V_2 -> V_105 = V_430 ;
V_2 -> V_29 = V_431 ;
for (; ; ) {
switch ( V_2 -> V_123 = F_59 ( T_5 , V_2 ) ) {
case 0x66 :
V_434 = true ;
V_2 -> V_105 = V_430 ^ 6 ;
break;
case 0x67 :
if ( V_37 == V_38 )
V_2 -> V_29 = V_431 ^ 12 ;
else
V_2 -> V_29 = V_431 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_435 = true ;
V_2 -> V_417 = ( V_2 -> V_123 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_435 = true ;
V_2 -> V_417 = V_2 -> V_123 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_37 != V_38 )
goto V_438;
V_2 -> V_103 = V_2 -> V_123 ;
continue;
case 0xf0 :
V_2 -> V_202 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_123 ;
break;
default:
goto V_438;
}
V_2 -> V_103 = 0 ;
}
V_438:
if ( V_2 -> V_103 & 8 )
V_2 -> V_105 = 8 ;
V_436 = V_439 [ V_2 -> V_123 ] ;
if ( V_2 -> V_123 == 0x0f ) {
V_2 -> V_437 = 2 ;
V_2 -> V_123 = F_59 ( T_5 , V_2 ) ;
V_436 = V_440 [ V_2 -> V_123 ] ;
if ( V_2 -> V_123 == 0x38 ) {
V_2 -> V_437 = 3 ;
V_2 -> V_123 = F_59 ( T_5 , V_2 ) ;
V_436 = V_441 [ V_2 -> V_123 ] ;
}
}
V_2 -> V_41 = V_436 . V_107 ;
if ( V_2 -> V_41 & V_122 )
V_2 -> V_141 = F_59 ( T_5 , V_2 ) ;
if ( V_2 -> V_437 == 1 && ( V_2 -> V_123 == 0xc5 || V_2 -> V_123 == 0xc4 ) &&
( V_37 == V_38 ||
( V_37 >= V_221 && ( V_2 -> V_141 & 0x80 ) ) ) ) {
V_2 -> V_41 = V_442 ;
}
while ( V_2 -> V_41 & V_443 ) {
switch ( V_2 -> V_41 & V_443 ) {
case V_444 :
V_432 = ( V_2 -> V_141 >> 3 ) & 7 ;
V_436 = V_436 . V_445 . V_446 [ V_432 ] ;
break;
case V_447 :
V_432 = ( V_2 -> V_141 >> 3 ) & 7 ;
if ( ( V_2 -> V_141 >> 6 ) == 3 )
V_436 = V_436 . V_445 . V_448 -> V_449 [ V_432 ] ;
else
V_436 = V_436 . V_445 . V_448 -> V_450 [ V_432 ] ;
break;
case V_451 :
V_432 = V_2 -> V_141 & 7 ;
V_436 = V_436 . V_445 . V_446 [ V_432 ] ;
break;
case V_452 :
if ( V_2 -> V_17 && V_434 )
return V_337 ;
V_433 = V_434 ? 0x66 : V_2 -> V_17 ;
switch ( V_433 ) {
case 0x00 : V_436 = V_436 . V_445 . V_453 -> V_454 ; break;
case 0x66 : V_436 = V_436 . V_445 . V_453 -> V_455 ; break;
case 0xf2 : V_436 = V_436 . V_445 . V_453 -> V_456 ; break;
case 0xf3 : V_436 = V_436 . V_445 . V_453 -> V_457 ; break;
}
break;
case V_458 :
if ( V_2 -> V_141 > 0xbf )
V_436 = V_436 . V_445 . V_459 -> V_460 [ V_2 -> V_141 - 0xc0 ] ;
else
V_436 = V_436 . V_445 . V_459 -> V_112 [ ( V_2 -> V_141 >> 3 ) & 7 ] ;
break;
default:
return V_337 ;
}
V_2 -> V_41 &= ~ ( V_114 ) V_443 ;
V_2 -> V_41 |= V_436 . V_107 ;
}
if ( V_2 -> V_41 == 0 )
return V_337 ;
V_2 -> V_461 = V_436 . V_445 . V_461 ;
if ( F_38 ( V_2 -> V_462 ) && F_33 ( ! ( V_2 -> V_41 & V_463 ) ) )
return V_337 ;
if ( F_38 ( V_2 -> V_41 &
( V_442 | V_464 | V_465 | V_124 | V_128 | V_466 | V_467 ) ) ) {
V_2 -> V_468 = V_436 . V_468 ;
V_2 -> V_12 = V_436 . V_12 ;
if ( V_2 -> V_41 & V_442 )
return V_337 ;
if ( V_37 == V_38 && ( V_2 -> V_41 & V_464 ) )
V_2 -> V_105 = 8 ;
if ( V_2 -> V_41 & V_465 ) {
if ( V_37 == V_38 )
V_2 -> V_105 = 8 ;
else
V_2 -> V_105 = 4 ;
}
if ( V_2 -> V_41 & V_124 )
V_2 -> V_105 = 16 ;
else if ( V_2 -> V_41 & V_128 )
V_2 -> V_105 = 8 ;
}
if ( V_2 -> V_41 & V_122 ) {
V_91 = F_58 ( V_2 , & V_2 -> V_156 ) ;
if ( ! V_435 ) {
V_435 = true ;
V_2 -> V_417 = V_2 -> V_136 ;
}
} else if ( V_2 -> V_41 & V_469 )
V_91 = F_60 ( V_2 , & V_2 -> V_156 ) ;
if ( V_91 != V_89 )
goto V_157;
if ( ! V_435 )
V_2 -> V_417 = V_142 ;
V_2 -> V_156 . V_76 . V_155 . V_49 = V_2 -> V_417 ;
V_91 = F_188 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_41 >> V_470 ) & V_471 ) ;
if ( V_91 != V_89 )
goto V_157;
V_91 = F_188 ( V_2 , & V_2 -> V_226 , ( V_2 -> V_41 >> V_472 ) & V_471 ) ;
if ( V_91 != V_89 )
goto V_157;
V_91 = F_188 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_41 >> V_473 ) & V_471 ) ;
V_157:
if ( V_2 -> V_154 )
V_2 -> V_398 -> V_76 . V_155 . V_84 += V_2 -> V_45 ;
return ( V_91 != V_89 ) ? V_337 : V_338 ;
}
bool F_191 ( struct V_1 * V_2 )
{
return V_2 -> V_41 & V_474 ;
}
static bool F_192 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_123 == 0xa6 ) || ( V_2 -> V_123 == 0xa7 ) ||
( V_2 -> V_123 == 0xae ) || ( V_2 -> V_123 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_475 ) &&
( ( V_2 -> V_175 & V_213 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_476 ) &&
( ( V_2 -> V_175 & V_213 ) == V_213 ) ) ) )
return true ;
return false ;
}
static int F_193 ( struct V_1 * V_2 )
{
bool V_477 = false ;
V_2 -> V_6 -> V_115 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_116 ( V_2 ) ;
if ( F_38 ( V_477 ) )
return F_22 ( V_2 , V_478 , 0 , false ) ;
return V_89 ;
}
static void F_194 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
if ( V_112 -> type == V_129 )
F_51 ( V_2 , & V_112 -> V_203 , V_112 -> V_76 . V_130 ) ;
}
static int F_105 ( struct V_1 * V_2 , void (* F_45)( struct F_105 * ) )
{
T_1 V_107 = ( V_2 -> V_175 & V_109 ) | V_110 ;
if ( ! ( V_2 -> V_41 & V_132 ) )
F_45 += F_195 ( V_2 -> V_25 . V_27 ) * V_479 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_175 = ( V_2 -> V_175 & ~ V_109 ) | ( V_107 & V_109 ) ;
if ( ! F_45 )
return F_28 ( V_2 ) ;
return V_89 ;
}
void F_196 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_154 , 0 ,
( void * ) & V_2 -> V_141 - ( void * ) & V_2 -> V_154 ) ;
V_2 -> V_170 . V_164 = 0 ;
V_2 -> V_170 . V_95 = 0 ;
V_2 -> V_163 . V_95 = 0 ;
}
int F_197 ( struct V_1 * V_2 )
{
const struct V_182 * V_6 = V_2 -> V_6 ;
int V_91 = V_89 ;
int V_480 = V_2 -> V_25 . type ;
V_2 -> V_163 . V_164 = 0 ;
if ( V_2 -> V_202 && ( ! ( V_2 -> V_41 & V_481 ) || V_2 -> V_25 . type != V_144 ) ) {
V_91 = F_26 ( V_2 ) ;
goto V_157;
}
if ( ( V_2 -> V_41 & V_482 ) == V_483 && V_2 -> V_22 . type != V_144 ) {
V_91 = F_26 ( V_2 ) ;
goto V_157;
}
if ( F_38 ( V_2 -> V_41 &
( V_484 | V_485 | V_124 | V_128 | V_466 | V_467 | V_486 | V_487 | String ) ) ) {
if ( ( V_2 -> V_37 == V_38 && ( V_2 -> V_41 & V_484 ) ) ||
( V_2 -> V_41 & V_485 ) ) {
V_91 = F_26 ( V_2 ) ;
goto V_157;
}
if ( ( ( V_2 -> V_41 & ( V_124 | V_128 ) ) && ( ( V_6 -> V_117 ( V_2 , 0 ) & V_119 ) ) )
|| ( ( V_2 -> V_41 & V_124 ) && ! ( V_6 -> V_117 ( V_2 , 4 ) & V_488 ) ) ) {
V_91 = F_26 ( V_2 ) ;
goto V_157;
}
if ( ( V_2 -> V_41 & ( V_124 | V_128 ) ) && ( V_6 -> V_117 ( V_2 , 0 ) & V_118 ) ) {
V_91 = F_29 ( V_2 ) ;
goto V_157;
}
if ( V_2 -> V_41 & V_128 ) {
V_91 = F_193 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_157;
F_194 ( V_2 , & V_2 -> V_22 ) ;
F_194 ( V_2 , & V_2 -> V_226 ) ;
if ( ! ( V_2 -> V_41 & V_489 ) )
F_194 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_38 ( V_2 -> V_490 ) && ( V_2 -> V_41 & V_466 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_491 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( ( V_2 -> V_41 & V_486 ) && V_6 -> V_83 ( V_2 ) ) {
if ( V_2 -> V_41 & V_492 )
V_91 = F_26 ( V_2 ) ;
else
V_91 = F_24 ( V_2 , 0 ) ;
goto V_157;
}
if ( ( V_2 -> V_41 & V_487 ) && V_2 -> V_37 < V_221 ) {
V_91 = F_26 ( V_2 ) ;
goto V_157;
}
if ( V_2 -> V_41 & V_467 ) {
V_91 = V_2 -> V_468 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( F_38 ( V_2 -> V_490 ) && ( V_2 -> V_41 & V_466 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_493 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_174 ) ) == 0 ) {
V_2 -> V_31 = V_2 -> V_45 ;
V_2 -> V_175 &= ~ V_238 ;
goto V_157;
}
}
}
if ( ( V_2 -> V_22 . type == V_144 ) && ! ( V_2 -> V_41 & V_494 ) ) {
V_91 = F_64 ( V_2 , V_2 -> V_22 . V_76 . V_155 ,
V_2 -> V_22 . V_245 , V_2 -> V_22 . V_27 ) ;
if ( V_91 != V_89 )
goto V_157;
V_2 -> V_22 . V_248 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_226 . type == V_144 ) {
V_91 = F_64 ( V_2 , V_2 -> V_226 . V_76 . V_155 ,
& V_2 -> V_226 . V_113 , V_2 -> V_226 . V_27 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( ( V_2 -> V_41 & V_495 ) == V_496 )
goto V_497;
if ( ( V_2 -> V_25 . type == V_144 ) && ! ( V_2 -> V_41 & V_489 ) ) {
V_91 = F_64 ( V_2 , V_2 -> V_25 . V_76 . V_155 ,
& V_2 -> V_25 . V_113 , V_2 -> V_25 . V_27 ) ;
if ( V_91 != V_89 )
goto V_157;
}
V_2 -> V_25 . V_133 = V_2 -> V_25 . V_113 ;
V_497:
if ( F_38 ( V_2 -> V_490 ) && ( V_2 -> V_41 & V_466 ) ) {
V_91 = F_7 ( V_2 , V_2 -> V_12 ,
V_498 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) )
V_2 -> V_175 |= V_238 ;
else
V_2 -> V_175 &= ~ V_238 ;
if ( V_2 -> V_461 ) {
if ( V_2 -> V_41 & V_499 ) {
void (* F_45)( struct F_105 * ) = ( void * ) V_2 -> V_461 ;
V_91 = F_105 ( V_2 , F_45 ) ;
if ( V_91 != V_89 )
goto V_157;
goto F_79;
}
V_91 = V_2 -> V_461 ( V_2 ) ;
if ( V_91 != V_89 )
goto V_157;
goto F_79;
}
if ( V_2 -> V_437 == 2 )
goto V_500;
else if ( V_2 -> V_437 == 3 )
goto V_501;
switch ( V_2 -> V_123 ) {
case 0x63 :
if ( V_2 -> V_37 != V_38 )
goto V_502;
V_2 -> V_25 . V_113 = ( V_153 ) V_2 -> V_22 . V_113 ;
break;
case 0x70 ... 0x7f :
if ( F_44 ( V_2 -> V_123 , V_2 -> V_175 ) )
F_18 ( V_2 , V_2 -> V_22 . V_113 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_113 = V_2 -> V_22 . V_76 . V_155 . V_84 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_76 . V_9 == F_3 ( V_2 , V_231 ) )
V_2 -> V_25 . type = V_204 ;
else
V_91 = F_132 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_105 ) {
case 2 : V_2 -> V_25 . V_113 = ( V_152 ) V_2 -> V_25 . V_113 ; break;
case 4 : V_2 -> V_25 . V_113 = ( V_159 ) V_2 -> V_25 . V_113 ; break;
case 8 : V_2 -> V_25 . V_113 = ( V_153 ) V_2 -> V_25 . V_113 ; break;
}
break;
case 0xcc :
V_91 = F_95 ( V_2 , 3 ) ;
break;
case 0xcd :
V_91 = F_95 ( V_2 , V_2 -> V_22 . V_113 ) ;
break;
case 0xce :
if ( V_2 -> V_175 & V_215 )
V_91 = F_95 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
F_18 ( V_2 , V_2 -> V_22 . V_113 ) ;
V_2 -> V_25 . type = V_204 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_503 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_175 ^= V_210 ;
break;
case 0xf8 :
V_2 -> V_175 &= ~ V_210 ;
break;
case 0xf9 :
V_2 -> V_175 |= V_210 ;
break;
case 0xfc :
V_2 -> V_175 &= ~ V_176 ;
break;
case 0xfd :
V_2 -> V_175 |= V_176 ;
break;
default:
goto V_502;
}
if ( V_91 != V_89 )
goto V_157;
F_79:
if ( V_2 -> V_41 & V_504 ) {
F_198 ( V_2 -> V_22 . type == V_144 || V_2 -> V_22 . type == V_177 ) ;
V_91 = F_79 ( V_2 , & V_2 -> V_22 ) ;
if ( V_91 != V_89 )
goto V_157;
}
if ( ! ( V_2 -> V_41 & V_505 ) ) {
V_91 = F_79 ( V_2 , & V_2 -> V_25 ) ;
if ( V_91 != V_89 )
goto V_157;
}
V_2 -> V_25 . type = V_480 ;
if ( ( V_2 -> V_41 & V_482 ) == V_506 )
F_125 ( V_2 , V_149 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_41 & V_495 ) == V_507 )
F_125 ( V_2 , V_151 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
unsigned int V_173 ;
struct V_161 * V_286 = & V_2 -> V_170 ;
if ( ( V_2 -> V_41 & V_482 ) == V_506 )
V_173 = V_2 -> V_22 . V_173 ;
else
V_173 = V_2 -> V_25 . V_173 ;
F_16 ( V_2 , F_3 ( V_2 , V_174 ) ,
- V_173 ) ;
if ( ! F_192 ( V_2 ) ) {
if ( ( V_286 -> V_95 != 0 || F_1 ( V_2 , V_174 ) & 0x3ff ) &&
( V_286 -> V_95 == 0 || V_286 -> V_95 != V_286 -> V_164 ) ) {
V_2 -> V_163 . V_95 = 0 ;
F_4 ( V_2 ) ;
return V_508 ;
}
goto V_157;
}
V_2 -> V_175 &= ~ V_238 ;
}
V_2 -> V_31 = V_2 -> V_45 ;
V_157:
if ( V_91 == V_58 )
V_2 -> V_509 = true ;
if ( V_91 == V_510 )
return V_511 ;
if ( V_91 == V_89 )
F_4 ( V_2 ) ;
return ( V_91 == V_98 ) ? V_337 : V_338 ;
V_500:
switch ( V_2 -> V_123 ) {
case 0x09 :
( V_2 -> V_6 -> V_512 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_113 = V_6 -> V_117 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_384 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_113 ) ;
break;
case 0x40 ... 0x4f :
if ( F_44 ( V_2 -> V_123 , V_2 -> V_175 ) )
V_2 -> V_25 . V_113 = V_2 -> V_22 . V_113 ;
else if ( V_2 -> V_37 != V_38 ||
V_2 -> V_105 != 4 )
V_2 -> V_25 . type = V_204 ;
break;
case 0x80 ... 0x8f :
if ( F_44 ( V_2 -> V_123 , V_2 -> V_175 ) )
F_18 ( V_2 , V_2 -> V_22 . V_113 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_113 = F_44 ( V_2 -> V_123 , V_2 -> V_175 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
V_2 -> V_25 . V_113 = ( V_2 -> V_22 . V_27 == 1 ) ? ( T_5 ) V_2 -> V_22 . V_113
: ( T_2 ) V_2 -> V_22 . V_113 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
V_2 -> V_25 . V_113 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_152 ) V_2 -> V_22 . V_113 :
( V_159 ) V_2 -> V_22 . V_113 ;
break;
case 0xc3 :
V_2 -> V_25 . V_27 = V_2 -> V_105 ;
V_2 -> V_25 . V_113 = ( V_2 -> V_105 == 8 ) ? ( V_114 ) V_2 -> V_22 . V_113 :
( T_3 ) V_2 -> V_22 . V_113 ;
break;
default:
goto V_502;
}
V_501:
if ( V_91 != V_89 )
goto V_157;
goto F_79;
V_502:
return V_337 ;
}
void F_199 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_200 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
