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
static inline int F_30 ( struct V_1 * V_2 , T_1 V_25 ,
int V_65 )
{
switch ( V_2 -> V_66 ) {
case 2 :
V_2 -> V_67 = ( T_2 ) V_25 ;
break;
case 4 :
V_2 -> V_67 = ( T_3 ) V_25 ;
break;
#ifdef F_31
case 8 :
if ( ( V_65 && F_32 ( V_25 ) ) ||
( ! V_65 && ( V_25 >> 32 ) != 0 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_67 = V_25 ;
break;
#endif
default:
F_33 ( 1 , L_1 ) ;
}
return V_68 ;
}
static inline int F_34 ( struct V_1 * V_2 , T_1 V_25 )
{
return F_30 ( V_2 , V_25 , V_2 -> V_37 == V_38 ) ;
}
static inline int F_35 ( struct V_1 * V_2 , int V_69 )
{
return F_34 ( V_2 , V_2 -> V_67 + V_69 ) ;
}
static T_2 F_36 ( struct V_1 * V_2 , unsigned V_47 )
{
T_2 V_70 ;
struct V_35 V_44 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_70 , & V_44 , NULL , V_47 ) ;
return V_70 ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_70 ,
unsigned V_47 )
{
T_2 V_71 ;
T_3 V_72 ;
struct V_35 V_44 ;
V_2 -> V_6 -> V_39 ( V_2 , & V_71 , & V_44 , & V_72 , V_47 ) ;
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_44 , V_72 , V_47 ) ;
}
static bool F_38 ( struct V_1 * V_2 , unsigned V_74 )
{
if ( F_39 ( V_74 < 16 ) )
return false ;
if ( V_2 -> V_41 & V_75 )
return true ;
else if ( V_2 -> V_41 & V_76 )
return false ;
else if ( V_2 -> V_41 & V_77 )
return false ;
else
return true ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
unsigned * V_80 , unsigned V_74 ,
bool V_81 , bool V_82 ,
T_1 * V_83 )
{
struct V_35 V_44 ;
bool V_84 ;
T_1 V_85 ;
T_3 V_86 ;
T_2 V_34 ;
unsigned V_87 ;
V_85 = F_20 ( V_2 , V_79 . V_47 ) + V_79 . V_88 ;
* V_80 = 0 ;
switch ( V_2 -> V_37 ) {
case V_38 :
if ( ( ( signed long ) V_85 << 16 ) >> 16 != V_85 )
return F_24 ( V_2 , 0 ) ;
* V_80 = F_41 ( V_89 , ~ 0u , ( 1ull << 48 ) - V_85 ) ;
if ( V_74 > * V_80 )
goto V_90;
break;
default:
V_84 = V_2 -> V_6 -> V_39 ( V_2 , & V_34 , & V_44 , NULL ,
V_79 . V_47 ) ;
if ( ! V_84 )
goto V_90;
if ( ( ( ( V_2 -> V_37 != V_91 ) && ( V_44 . type & 8 ) )
|| ! ( V_44 . type & 2 ) ) && V_81 )
goto V_90;
if ( ! V_82 && ( V_44 . type & 8 ) && ! ( V_44 . type & 2 ) )
goto V_90;
V_86 = F_18 ( & V_44 ) ;
if ( ( V_2 -> V_37 == V_91 ) && ! V_82 &&
( V_2 -> V_41 & V_92 ) ) {
if ( V_85 > 0xffff )
goto V_90;
* V_80 = 0x10000 - V_85 ;
} else if ( ( V_44 . type & 8 ) || ! ( V_44 . type & 4 ) ) {
if ( V_79 . V_88 > V_86 )
goto V_90;
* V_80 = F_41 ( V_89 , ~ 0u , ( V_89 ) V_86 + 1 - V_79 . V_88 ) ;
} else {
if ( V_79 . V_88 <= V_86 )
goto V_90;
V_86 = V_44 . V_41 ? 0xffffffff : 0xffff ;
if ( V_79 . V_88 > V_86 )
goto V_90;
* V_80 = F_41 ( V_89 , ~ 0u , ( V_89 ) V_86 + 1 - V_79 . V_88 ) ;
}
if ( V_74 > * V_80 )
goto V_90;
V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
if ( ! ( V_44 . type & 8 ) ) {
if ( V_87 > V_44 . V_93 )
goto V_90;
} else if ( ( V_44 . type & 8 ) && ! ( V_44 . type & 4 ) ) {
if ( V_87 != V_44 . V_93 )
goto V_90;
} else if ( ( V_44 . type & 8 ) && ( V_44 . type & 4 ) ) {
if ( V_87 < V_44 . V_93 )
goto V_90;
}
break;
}
if ( V_82 ? V_2 -> V_37 != V_38 : V_2 -> V_29 != 8 )
V_85 &= ( T_3 ) - 1 ;
if ( F_38 ( V_2 , V_74 ) && ( ( V_85 & ( V_74 - 1 ) ) != 0 ) )
return F_24 ( V_2 , 0 ) ;
* V_83 = V_85 ;
return V_68 ;
V_90:
if ( V_79 . V_47 == V_40 )
return F_25 ( V_2 , 0 ) ;
else
return F_24 ( V_2 , 0 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
unsigned V_74 , bool V_81 ,
T_1 * V_83 )
{
unsigned V_80 ;
return F_40 ( V_2 , V_79 , & V_80 , V_74 , V_81 , false , V_83 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
void * V_94 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_83 ;
V_95 = F_42 ( V_2 , V_79 , V_74 , false , & V_83 ) ;
if ( V_95 != V_68 )
return V_95 ;
return V_2 -> V_6 -> V_96 ( V_2 , V_83 , V_94 , V_74 , & V_2 -> V_52 ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_97 )
{
int V_95 ;
unsigned V_74 , V_80 ;
unsigned long V_83 ;
int V_98 = V_2 -> V_82 . V_99 - V_2 -> V_82 . V_94 ;
struct V_78 V_79 = { . V_47 = V_100 ,
. V_88 = V_2 -> V_31 + V_98 } ;
V_95 = F_40 ( V_2 , V_79 , & V_80 , 0 , false , true , & V_83 ) ;
if ( F_45 ( V_95 != V_68 ) )
return V_95 ;
V_74 = F_41 ( unsigned , 15UL ^ V_98 , V_80 ) ;
V_74 = F_41 ( unsigned , V_74 , V_101 - F_46 ( V_83 ) ) ;
if ( F_45 ( V_74 < V_97 ) )
return F_24 ( V_2 , 0 ) ;
V_95 = V_2 -> V_6 -> V_82 ( V_2 , V_83 , V_2 -> V_82 . V_99 ,
V_74 , & V_2 -> V_52 ) ;
if ( F_45 ( V_95 != V_68 ) )
return V_95 ;
V_2 -> V_82 . V_99 += V_74 ;
return V_68 ;
}
static T_4 int F_47 ( struct V_1 * V_2 ,
unsigned V_74 )
{
unsigned V_102 = V_2 -> V_82 . V_99 - V_2 -> V_82 . V_103 ;
if ( F_45 ( V_102 < V_74 ) )
return F_44 ( V_2 , V_74 - V_102 ) ;
else
return V_68 ;
}
static void * F_48 ( struct V_1 * V_2 , T_5 V_19 ,
int V_104 )
{
void * V_105 ;
int V_106 = ( V_2 -> V_107 == 0 ) && V_104 ;
if ( V_106 && V_19 >= 4 && V_19 < 8 )
V_105 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_105 = F_3 ( V_2 , V_19 ) ;
return V_105 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
T_2 * V_74 , unsigned long * V_108 , int V_66 )
{
int V_95 ;
if ( V_66 == 2 )
V_66 = 3 ;
* V_108 = 0 ;
V_95 = F_43 ( V_2 , V_79 , V_74 , 2 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_79 . V_88 += 2 ;
V_95 = F_43 ( V_2 , V_79 , V_108 , V_66 ) ;
return V_95 ;
}
static T_5 F_50 ( unsigned int V_109 , unsigned long V_110 )
{
T_5 V_95 ;
void (* F_51)( void ) = ( void * ) V_111 + 4 * ( V_109 & 0xf ) ;
V_110 = ( V_110 & V_112 ) | V_113 ;
asm("push %[flags]; popf; call *%[fastop]"
: "=a"(rc) : [fastop]"r"(fop), [flags]"r"(flags));
return V_95 ;
}
static void F_52 ( struct V_114 * V_115 )
{
switch ( V_115 -> V_27 ) {
case 1 :
V_115 -> V_116 = * ( T_5 * ) V_115 -> V_79 . V_9 ;
break;
case 2 :
V_115 -> V_116 = * ( T_2 * ) V_115 -> V_79 . V_9 ;
break;
case 4 :
V_115 -> V_116 = * ( T_3 * ) V_115 -> V_79 . V_9 ;
break;
case 8 :
V_115 -> V_116 = * ( V_89 * ) V_115 -> V_79 . V_9 ;
break;
}
}
static void F_53 ( struct V_1 * V_2 , T_6 * V_94 , int V_9 )
{
V_2 -> V_6 -> V_117 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqa %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqa %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqa %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqa %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqa %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqa %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqa %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_31
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 , T_6 * V_94 ,
int V_9 )
{
V_2 -> V_6 -> V_117 ( V_2 ) ;
switch ( V_9 ) {
case 0 : asm("movdqa %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqa %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqa %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqa %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqa %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqa %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqa %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqa %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_31
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_56 ( struct V_1 * V_2 , V_89 * V_94 , int V_9 )
{
V_2 -> V_6 -> V_117 ( V_2 ) ;
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 , V_89 * V_94 , int V_9 )
{
V_2 -> V_6 -> V_117 ( V_2 ) ;
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_119 ( V_2 , 0 ) & ( V_120 | V_121 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_117 ( V_2 ) ;
asm volatile("fninit");
V_2 -> V_6 -> V_118 ( V_2 ) ;
return V_68 ;
}
static int F_59 ( struct V_1 * V_2 )
{
T_2 V_122 ;
if ( V_2 -> V_6 -> V_119 ( V_2 , 0 ) & ( V_120 | V_121 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_117 ( V_2 ) ;
asm volatile("fnstcw %0": "+m"(fcw));
V_2 -> V_6 -> V_118 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_116 = V_122 ;
return V_68 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_2 V_123 ;
if ( V_2 -> V_6 -> V_119 ( V_2 , 0 ) & ( V_120 | V_121 ) )
return F_29 ( V_2 ) ;
V_2 -> V_6 -> V_117 ( V_2 ) ;
asm volatile("fnstsw %0": "+m"(fsw));
V_2 -> V_6 -> V_118 ( V_2 ) ;
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_116 = V_123 ;
return V_68 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
unsigned V_9 = V_2 -> V_19 ;
if ( ! ( V_2 -> V_41 & V_124 ) )
V_9 = ( V_2 -> V_125 & 7 ) | ( ( V_2 -> V_107 & 1 ) << 3 ) ;
if ( V_2 -> V_41 & V_126 ) {
V_115 -> type = V_127 ;
V_115 -> V_27 = 16 ;
V_115 -> V_79 . V_128 = V_9 ;
F_53 ( V_2 , & V_115 -> V_129 , V_9 ) ;
return;
}
if ( V_2 -> V_41 & V_130 ) {
V_9 &= 7 ;
V_115 -> type = V_131 ;
V_115 -> V_27 = 8 ;
V_115 -> V_79 . V_132 = V_9 ;
return;
}
V_115 -> type = V_133 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_9 = F_48 ( V_2 , V_9 , V_2 -> V_41 & V_134 ) ;
F_52 ( V_115 ) ;
V_115 -> V_135 = V_115 -> V_116 ;
}
static void F_62 ( struct V_1 * V_2 , int V_136 )
{
if ( V_136 == V_43 || V_136 == V_137 )
V_2 -> V_138 = V_40 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
T_5 V_139 ;
int V_140 , V_136 , V_141 ;
int V_95 = V_68 ;
T_1 V_142 = 0 ;
V_2 -> V_19 = ( ( V_2 -> V_107 << 1 ) & 8 ) ;
V_140 = ( V_2 -> V_107 << 2 ) & 8 ;
V_136 = ( V_2 -> V_107 << 3 ) & 8 ;
V_2 -> V_18 = ( V_2 -> V_143 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_143 & 0x38 ) >> 3 ;
V_2 -> V_20 = V_136 | ( V_2 -> V_143 & 0x07 ) ;
V_2 -> V_138 = V_144 ;
if ( V_2 -> V_18 == 3 || ( V_2 -> V_41 & V_145 ) ) {
V_115 -> type = V_133 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_9 = F_48 ( V_2 , V_2 -> V_20 ,
V_2 -> V_41 & V_134 ) ;
if ( V_2 -> V_41 & V_126 ) {
V_115 -> type = V_127 ;
V_115 -> V_27 = 16 ;
V_115 -> V_79 . V_128 = V_2 -> V_20 ;
F_53 ( V_2 , & V_115 -> V_129 , V_2 -> V_20 ) ;
return V_95 ;
}
if ( V_2 -> V_41 & V_130 ) {
V_115 -> type = V_131 ;
V_115 -> V_27 = 8 ;
V_115 -> V_79 . V_132 = V_2 -> V_20 & 7 ;
return V_95 ;
}
F_52 ( V_115 ) ;
return V_95 ;
}
V_115 -> type = V_146 ;
if ( V_2 -> V_29 == 2 ) {
unsigned V_147 = F_1 ( V_2 , V_148 ) ;
unsigned V_149 = F_1 ( V_2 , V_137 ) ;
unsigned V_150 = F_1 ( V_2 , V_151 ) ;
unsigned V_152 = F_1 ( V_2 , V_153 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_142 += F_64 ( T_2 , V_2 ) ;
break;
case 1 :
V_142 += F_64 ( V_154 , V_2 ) ;
break;
case 2 :
V_142 += F_64 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_142 += V_147 + V_150 ;
break;
case 1 :
V_142 += V_147 + V_152 ;
break;
case 2 :
V_142 += V_149 + V_150 ;
break;
case 3 :
V_142 += V_149 + V_152 ;
break;
case 4 :
V_142 += V_150 ;
break;
case 5 :
V_142 += V_152 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_142 += V_149 ;
break;
case 7 :
V_142 += V_147 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_138 = V_40 ;
V_142 = ( T_2 ) V_142 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_139 = F_64 ( T_5 , V_2 ) ;
V_140 |= ( V_139 >> 3 ) & 7 ;
V_136 |= V_139 & 7 ;
V_141 = V_139 >> 6 ;
if ( ( V_136 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_142 += F_64 ( V_155 , V_2 ) ;
else {
V_142 += F_1 ( V_2 , V_136 ) ;
F_62 ( V_2 , V_136 ) ;
}
if ( V_140 != 4 )
V_142 += F_1 ( V_2 , V_140 ) << V_141 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
if ( V_2 -> V_37 == V_38 )
V_2 -> V_156 = 1 ;
} else {
V_136 = V_2 -> V_20 ;
V_142 += F_1 ( V_2 , V_136 ) ;
F_62 ( V_2 , V_136 ) ;
}
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 5 )
V_142 += F_64 ( V_155 , V_2 ) ;
break;
case 1 :
V_142 += F_64 ( V_154 , V_2 ) ;
break;
case 2 :
V_142 += F_64 ( V_155 , V_2 ) ;
break;
}
}
V_115 -> V_79 . V_157 . V_88 = V_142 ;
if ( V_2 -> V_29 != 8 )
V_2 -> V_158 . V_79 . V_157 . V_88 = ( T_3 ) V_2 -> V_158 . V_79 . V_157 . V_88 ;
V_159:
return V_95 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
int V_95 = V_68 ;
V_115 -> type = V_146 ;
switch ( V_2 -> V_29 ) {
case 2 :
V_115 -> V_79 . V_157 . V_88 = F_64 ( T_2 , V_2 ) ;
break;
case 4 :
V_115 -> V_79 . V_157 . V_88 = F_64 ( T_3 , V_2 ) ;
break;
case 8 :
V_115 -> V_79 . V_157 . V_88 = F_64 ( V_89 , V_2 ) ;
break;
}
V_159:
return V_95 ;
}
static void F_66 ( struct V_1 * V_2 )
{
long V_160 = 0 , V_33 ;
if ( V_2 -> V_25 . type == V_146 && V_2 -> V_22 . type == V_133 ) {
V_33 = ~ ( ( long ) V_2 -> V_25 . V_27 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_27 == 2 )
V_160 = ( V_161 ) V_2 -> V_22 . V_116 & ( V_161 ) V_33 ;
else if ( V_2 -> V_22 . V_27 == 4 )
V_160 = ( V_155 ) V_2 -> V_22 . V_116 & ( V_155 ) V_33 ;
else
V_160 = ( V_162 ) V_2 -> V_22 . V_116 & ( V_162 ) V_33 ;
V_2 -> V_25 . V_79 . V_157 . V_88 += ( V_160 >> 3 ) ;
}
V_2 -> V_22 . V_116 &= ( V_2 -> V_25 . V_27 << 3 ) - 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
unsigned long V_79 , void * V_32 , unsigned V_74 )
{
int V_95 ;
struct V_163 * V_164 = & V_2 -> V_165 ;
if ( V_164 -> V_166 < V_164 -> V_99 )
goto V_167;
F_22 ( ( V_164 -> V_99 + V_74 ) >= sizeof( V_164 -> V_94 ) ) ;
V_95 = V_2 -> V_6 -> F_67 ( V_2 , V_79 , V_164 -> V_94 + V_164 -> V_99 , V_74 ,
& V_2 -> V_52 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_164 -> V_99 += V_74 ;
V_167:
memcpy ( V_32 , V_164 -> V_94 + V_164 -> V_166 , V_74 ) ;
V_164 -> V_166 += V_74 ;
return V_68 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
void * V_94 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_83 ;
V_95 = F_42 ( V_2 , V_79 , V_74 , false , & V_83 ) ;
if ( V_95 != V_68 )
return V_95 ;
return F_67 ( V_2 , V_83 , V_94 , V_74 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
const void * V_94 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_83 ;
V_95 = F_42 ( V_2 , V_79 , V_74 , true , & V_83 ) ;
if ( V_95 != V_68 )
return V_95 ;
return V_2 -> V_6 -> V_168 ( V_2 , V_83 , V_94 , V_74 ,
& V_2 -> V_52 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_78 V_79 ,
const void * V_169 , const void * V_94 ,
unsigned V_74 )
{
int V_95 ;
T_1 V_83 ;
V_95 = F_42 ( V_2 , V_79 , V_74 , true , & V_83 ) ;
if ( V_95 != V_68 )
return V_95 ;
return V_2 -> V_6 -> V_170 ( V_2 , V_83 , V_169 , V_94 ,
V_74 , & V_2 -> V_52 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
unsigned int V_74 , unsigned short V_171 ,
void * V_32 )
{
struct V_163 * V_95 = & V_2 -> V_172 ;
if ( V_95 -> V_166 == V_95 -> V_99 ) {
unsigned int V_173 , V_174 ;
unsigned int V_175 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_176 ) ) : 1 ;
V_173 = ( V_2 -> V_177 & V_178 ) ?
F_46 ( F_1 ( V_2 , V_153 ) ) :
V_101 - F_46 ( F_1 ( V_2 , V_153 ) ) ;
V_174 = F_72 ( V_173 , ( unsigned int ) sizeof( V_95 -> V_94 ) / V_74 , V_175 ) ;
if ( V_174 == 0 )
V_174 = 1 ;
V_95 -> V_166 = V_95 -> V_99 = 0 ;
if ( ! V_2 -> V_6 -> F_71 ( V_2 , V_74 , V_171 , V_95 -> V_94 , V_174 ) )
return 0 ;
V_95 -> V_99 = V_174 * V_74 ;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) &&
! ( V_2 -> V_177 & V_178 ) ) {
V_2 -> V_25 . V_94 = V_95 -> V_94 + V_95 -> V_166 ;
V_2 -> V_25 . type = V_179 ;
V_2 -> V_25 . V_175 = ( V_95 -> V_99 - V_95 -> V_166 ) / V_74 ;
V_95 -> V_166 = V_95 -> V_99 ;
} else {
memcpy ( V_32 , V_95 -> V_94 + V_95 -> V_166 , V_74 ) ;
V_95 -> V_166 += V_74 ;
}
return 1 ;
}
static int F_73 ( struct V_1 * V_2 ,
T_2 V_180 , struct V_35 * V_44 )
{
struct V_181 V_182 ;
T_1 V_79 ;
V_2 -> V_6 -> V_183 ( V_2 , & V_182 ) ;
if ( V_182 . V_74 < V_180 * 8 + 7 )
return F_24 ( V_2 , V_180 << 3 | 0x2 ) ;
V_79 = V_182 . V_108 + V_180 * 8 ;
return V_2 -> V_6 -> V_96 ( V_2 , V_79 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
T_2 V_70 , struct V_181 * V_182 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
T_3 V_72 = 0 ;
if ( V_70 & 1 << 2 ) {
struct V_35 V_44 ;
T_2 V_34 ;
memset ( V_182 , 0 , sizeof *V_182 ) ;
if ( ! V_6 -> V_39 ( V_2 , & V_34 , & V_44 , & V_72 ,
V_185 ) )
return;
V_182 -> V_74 = F_18 ( & V_44 ) ;
V_182 -> V_108 = F_75 ( & V_44 ) | ( ( V_89 ) V_72 << 32 ) ;
} else
V_6 -> V_186 ( V_2 , V_182 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
T_2 V_70 , struct V_35 * V_44 ,
T_1 * V_187 )
{
struct V_181 V_182 ;
T_2 V_180 = V_70 >> 3 ;
T_1 V_79 ;
F_74 ( V_2 , V_70 , & V_182 ) ;
if ( V_182 . V_74 < V_180 * 8 + 7 )
return F_24 ( V_2 , V_70 & 0xfffc ) ;
* V_187 = V_79 = V_182 . V_108 + V_180 * 8 ;
return V_2 -> V_6 -> V_96 ( V_2 , V_79 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
T_2 V_70 , struct V_35 * V_44 )
{
struct V_181 V_182 ;
T_2 V_180 = V_70 >> 3 ;
T_1 V_79 ;
F_74 ( V_2 , V_70 , & V_182 ) ;
if ( V_182 . V_74 < V_180 * 8 + 7 )
return F_24 ( V_2 , V_70 & 0xfffc ) ;
V_79 = V_182 . V_108 + V_180 * 8 ;
return V_2 -> V_6 -> V_188 ( V_2 , V_79 , V_44 , sizeof *V_44 ,
& V_2 -> V_52 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
T_2 V_70 , int V_47 , T_5 V_87 ,
bool V_189 ,
struct V_35 * V_44 )
{
struct V_35 V_190 , V_191 ;
T_5 V_93 , V_192 ;
unsigned V_193 = V_59 ;
T_3 V_194 = 0 ;
bool V_195 = ! ( V_70 & ~ 0x3 ) ;
T_1 V_196 ;
int V_197 ;
T_2 V_71 ;
T_3 V_72 = 0 ;
memset ( & V_190 , 0 , sizeof V_190 ) ;
if ( V_2 -> V_37 == V_91 ) {
V_2 -> V_6 -> V_39 ( V_2 , & V_71 , & V_190 , NULL , V_47 ) ;
F_79 ( & V_190 , V_70 << 4 ) ;
goto V_198;
} else if ( V_47 <= V_199 && V_2 -> V_37 == V_200 ) {
F_79 ( & V_190 , V_70 << 4 ) ;
F_80 ( & V_190 , 0xffff ) ;
V_190 . type = 3 ;
V_190 . V_105 = 1 ;
V_190 . V_201 = 1 ;
V_190 . V_93 = 3 ;
goto V_198;
}
V_192 = V_70 & 3 ;
if ( ( V_47 == V_100
|| ( V_47 == V_40
&& ( V_2 -> V_37 != V_38 || V_192 != V_87 ) )
|| V_47 == V_202 )
&& V_195 )
goto V_52;
if ( V_47 == V_202 && ( V_70 & ( 1 << 2 ) ) )
goto V_52;
if ( V_195 )
goto V_198;
V_197 = F_76 ( V_2 , V_70 , & V_190 , & V_196 ) ;
if ( V_197 != V_68 )
return V_197 ;
V_194 = V_70 & 0xfffc ;
V_193 = V_189 ? V_62 : V_59 ;
if ( V_47 <= V_199 && ! V_190 . V_201 )
goto V_52;
if ( ! V_190 . V_105 ) {
V_193 = ( V_47 == V_40 ) ? V_60 : V_203 ;
goto V_52;
}
V_93 = V_190 . V_93 ;
switch ( V_47 ) {
case V_40 :
if ( V_192 != V_87 || ( V_190 . type & 0xa ) != 0x2 || V_93 != V_87 )
goto V_52;
break;
case V_100 :
if ( ! ( V_190 . type & 8 ) )
goto V_52;
if ( V_190 . type & 4 ) {
if ( V_93 > V_87 )
goto V_52;
} else {
if ( V_192 > V_87 || V_93 != V_87 )
goto V_52;
}
if ( V_190 . V_41 && V_190 . V_204 ) {
V_89 V_205 = 0 ;
V_2 -> V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( V_205 & V_208 )
goto V_52;
}
V_70 = ( V_70 & 0xfffc ) | V_87 ;
break;
case V_202 :
if ( V_190 . V_201 || ( V_190 . type != 1 && V_190 . type != 9 ) )
goto V_52;
V_191 = V_190 ;
V_190 . type |= 2 ;
V_197 = V_2 -> V_6 -> V_170 ( V_2 , V_196 , & V_191 , & V_190 ,
sizeof( V_190 ) , & V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
break;
case V_185 :
if ( V_190 . V_201 || V_190 . type != 2 )
goto V_52;
break;
default:
if ( ( V_190 . type & 0xa ) == 0x8 ||
( ( ( V_190 . type & 0xc ) != 0xc ) &&
( V_192 > V_93 && V_87 > V_93 ) ) )
goto V_52;
break;
}
if ( V_190 . V_201 ) {
V_190 . type |= 1 ;
V_197 = F_77 ( V_2 , V_70 , & V_190 ) ;
if ( V_197 != V_68 )
return V_197 ;
} else if ( V_2 -> V_37 == V_38 ) {
V_197 = V_2 -> V_6 -> V_96 ( V_2 , V_196 + 8 , & V_72 ,
sizeof( V_72 ) , & V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
}
V_198:
V_2 -> V_6 -> V_73 ( V_2 , V_70 , & V_190 , V_72 , V_47 ) ;
if ( V_44 )
* V_44 = V_190 ;
return V_68 ;
V_52:
return F_21 ( V_2 , V_193 , V_194 , true ) ;
}
static int F_81 ( struct V_1 * V_2 ,
T_2 V_70 , int V_47 )
{
T_5 V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
return F_78 ( V_2 , V_70 , V_47 , V_87 , false , NULL ) ;
}
static void F_82 ( struct V_114 * V_115 )
{
switch ( V_115 -> V_27 ) {
case 1 :
* ( T_5 * ) V_115 -> V_79 . V_9 = ( T_5 ) V_115 -> V_116 ;
break;
case 2 :
* ( T_2 * ) V_115 -> V_79 . V_9 = ( T_2 ) V_115 -> V_116 ;
break;
case 4 :
* V_115 -> V_79 . V_9 = ( T_3 ) V_115 -> V_116 ;
break;
case 8 :
* V_115 -> V_79 . V_9 = V_115 -> V_116 ;
break;
}
}
static int F_83 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
switch ( V_115 -> type ) {
case V_133 :
F_82 ( V_115 ) ;
break;
case V_146 :
if ( V_2 -> V_209 )
return F_70 ( V_2 ,
V_115 -> V_79 . V_157 ,
& V_115 -> V_135 ,
& V_115 -> V_116 ,
V_115 -> V_27 ) ;
else
return F_69 ( V_2 ,
V_115 -> V_79 . V_157 ,
& V_115 -> V_116 ,
V_115 -> V_27 ) ;
break;
case V_179 :
return F_69 ( V_2 ,
V_115 -> V_79 . V_157 ,
V_115 -> V_94 ,
V_115 -> V_27 * V_115 -> V_175 ) ;
break;
case V_127 :
F_55 ( V_2 , & V_115 -> V_129 , V_115 -> V_79 . V_128 ) ;
break;
case V_131 :
F_57 ( V_2 , & V_115 -> V_210 , V_115 -> V_79 . V_132 ) ;
break;
case V_211 :
break;
default:
break;
}
return V_68 ;
}
static int F_84 ( struct V_1 * V_2 , void * V_94 , int V_27 )
{
struct V_78 V_79 ;
F_17 ( V_2 , - V_27 ) ;
V_79 . V_88 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_79 . V_47 = V_40 ;
return F_69 ( V_2 , V_79 , V_94 , V_27 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_211 ;
return F_84 ( V_2 , & V_2 -> V_22 . V_116 , V_2 -> V_66 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
void * V_32 , int V_212 )
{
int V_95 ;
struct V_78 V_79 ;
V_79 . V_88 = F_1 ( V_2 , V_43 ) & F_10 ( V_2 ) ;
V_79 . V_47 = V_40 ;
V_95 = F_68 ( V_2 , V_79 , V_32 , V_212 ) ;
if ( V_95 != V_68 )
return V_95 ;
F_17 ( V_2 , V_212 ) ;
return V_95 ;
}
static int F_87 ( struct V_1 * V_2 )
{
return F_86 ( V_2 , & V_2 -> V_25 . V_116 , V_2 -> V_66 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
void * V_32 , int V_212 )
{
int V_95 ;
unsigned long V_116 , V_213 ;
int V_214 = ( V_2 -> V_177 & V_215 ) >> V_216 ;
int V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
V_95 = F_86 ( V_2 , & V_116 , V_212 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_213 = V_217 | V_218 | V_219 | V_220 | V_221 | V_222
| V_223 | V_178 | V_224 | V_225 | V_226 ;
switch( V_2 -> V_37 ) {
case V_38 :
case V_227 :
case V_228 :
if ( V_87 == 0 )
V_213 |= V_229 ;
if ( V_87 <= V_214 )
V_213 |= V_230 ;
break;
case V_200 :
if ( V_214 < 3 )
return F_24 ( V_2 , 0 ) ;
V_213 |= V_230 ;
break;
default:
V_213 |= ( V_229 | V_230 ) ;
break;
}
* ( unsigned long * ) V_32 =
( V_2 -> V_177 & ~ V_213 ) | ( V_116 & V_213 ) ;
return V_95 ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_133 ;
V_2 -> V_25 . V_79 . V_9 = & V_2 -> V_177 ;
V_2 -> V_25 . V_27 = V_2 -> V_66 ;
return F_88 ( V_2 , & V_2 -> V_25 . V_116 , V_2 -> V_66 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned V_231 = V_2 -> V_22 . V_116 ;
unsigned V_232 = V_2 -> V_233 . V_116 & 31 ;
T_1 V_234 ;
if ( V_232 )
return V_235 ;
V_234 = F_1 ( V_2 , V_137 ) ;
V_95 = F_84 ( V_2 , & V_234 , F_11 ( V_2 ) ) ;
if ( V_95 != V_68 )
return V_95 ;
F_8 ( F_3 ( V_2 , V_137 ) , F_1 ( V_2 , V_43 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_43 ) ,
F_1 ( V_2 , V_43 ) - V_231 ,
F_10 ( V_2 ) ) ;
return V_68 ;
}
static int F_91 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_43 ) , F_1 ( V_2 , V_137 ) ,
F_10 ( V_2 ) ) ;
return F_86 ( V_2 , F_3 ( V_2 , V_137 ) , V_2 -> V_66 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_116 ;
V_2 -> V_22 . V_116 = F_36 ( V_2 , V_47 ) ;
return F_85 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_116 ;
unsigned long V_70 ;
int V_95 ;
V_95 = F_86 ( V_2 , & V_70 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_236 = V_237 ;
V_95 = F_81 ( V_2 , ( T_2 ) V_70 , V_47 ) ;
return V_95 ;
}
static int F_94 ( struct V_1 * V_2 )
{
unsigned long V_238 = F_1 ( V_2 , V_43 ) ;
int V_95 = V_68 ;
int V_9 = V_239 ;
while ( V_9 <= V_153 ) {
( V_9 == V_43 ) ?
( V_2 -> V_22 . V_116 = V_238 ) : ( V_2 -> V_22 . V_116 = F_1 ( V_2 , V_9 ) ) ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
++ V_9 ;
}
return V_95 ;
}
static int F_95 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_116 = ( unsigned long ) V_2 -> V_177 ;
return F_85 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_95 = V_68 ;
int V_9 = V_153 ;
while ( V_9 >= V_239 ) {
if ( V_9 == V_43 ) {
F_17 ( V_2 , V_2 -> V_66 ) ;
-- V_9 ;
}
V_95 = F_86 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
break;
-- V_9 ;
}
return V_95 ;
}
static int F_97 ( struct V_1 * V_2 , int V_240 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
int V_95 ;
struct V_181 V_182 ;
T_7 V_241 ;
T_7 V_242 ;
T_2 V_243 , V_31 ;
V_2 -> V_22 . V_116 = V_2 -> V_177 ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_177 &= ~ ( V_230 | V_223 | V_225 ) ;
V_2 -> V_22 . V_116 = F_36 ( V_2 , V_100 ) ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_22 . V_116 = V_2 -> V_67 ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_6 -> V_183 ( V_2 , & V_182 ) ;
V_242 = V_182 . V_108 + ( V_240 << 2 ) ;
V_241 = V_182 . V_108 + ( V_240 << 2 ) + 2 ;
V_95 = V_6 -> V_96 ( V_2 , V_241 , & V_243 , 2 , & V_2 -> V_52 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = V_6 -> V_96 ( V_2 , V_242 , & V_31 , 2 , & V_2 -> V_52 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_81 ( V_2 , V_243 , V_100 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_67 = V_31 ;
return V_95 ;
}
int F_98 ( struct V_1 * V_2 , int V_240 )
{
int V_95 ;
F_6 ( V_2 ) ;
V_95 = F_97 ( V_2 , V_240 ) ;
if ( V_95 == V_68 )
F_4 ( V_2 ) ;
return V_95 ;
}
static int F_99 ( struct V_1 * V_2 , int V_240 )
{
switch( V_2 -> V_37 ) {
case V_91 :
return F_97 ( V_2 , V_240 ) ;
case V_200 :
case V_228 :
case V_227 :
case V_38 :
default:
return V_235 ;
}
}
static int F_100 ( struct V_1 * V_2 )
{
int V_95 = V_68 ;
unsigned long V_244 = 0 ;
unsigned long V_245 = 0 ;
unsigned long V_243 = 0 ;
unsigned long V_33 = V_217 | V_218 | V_219 | V_220 | V_221 | V_223 |
V_230 | V_178 | V_222 | V_229 | V_224 | V_246 |
V_225 | V_226 | ( 1 << 1 ) ;
unsigned long V_247 = V_248 | V_249 | V_250 ;
V_95 = F_86 ( V_2 , & V_244 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
if ( V_244 & ~ 0xffff )
return F_24 ( V_2 , 0 ) ;
V_95 = F_86 ( V_2 , & V_243 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_86 ( V_2 , & V_245 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_81 ( V_2 , ( T_2 ) V_243 , V_100 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_67 = V_244 ;
if ( V_2 -> V_66 == 4 )
V_2 -> V_177 = ( ( V_245 & V_33 ) | ( V_2 -> V_177 & V_247 ) ) ;
else if ( V_2 -> V_66 == 2 ) {
V_2 -> V_177 &= ~ 0xffff ;
V_2 -> V_177 |= V_245 ;
}
V_2 -> V_177 &= ~ V_251 ;
V_2 -> V_177 |= V_252 ;
return V_95 ;
}
static int F_101 ( struct V_1 * V_2 )
{
switch( V_2 -> V_37 ) {
case V_91 :
return F_100 ( V_2 ) ;
case V_200 :
case V_228 :
case V_227 :
case V_38 :
default:
return V_235 ;
}
}
static int F_102 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned short V_34 , V_253 ;
struct V_35 V_191 , V_254 ;
const struct V_184 * V_6 = V_2 -> V_6 ;
T_5 V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_253 , & V_191 , NULL ,
V_100 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_66 , 2 ) ;
V_95 = F_78 ( V_2 , V_34 , V_100 , V_87 , false ,
& V_254 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_30 ( V_2 , V_2 -> V_22 . V_116 , V_254 . V_204 ) ;
if ( V_95 != V_68 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_73 ( V_2 , V_253 , & V_191 , 0 , V_100 ) ;
return V_95 ;
}
return V_95 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_95 = V_68 ;
switch ( V_2 -> V_19 ) {
case 2 : {
long int V_256 ;
V_256 = V_2 -> V_67 ;
V_95 = F_34 ( V_2 , V_2 -> V_22 . V_116 ) ;
if ( V_95 != V_68 )
break;
V_2 -> V_22 . V_116 = V_256 ;
V_95 = F_85 ( V_2 ) ;
break;
}
case 4 :
V_95 = F_34 ( V_2 , V_2 -> V_22 . V_116 ) ;
break;
case 5 :
V_95 = F_102 ( V_2 ) ;
break;
case 6 :
V_95 = F_85 ( V_2 ) ;
break;
}
return V_95 ;
}
static int F_104 ( struct V_1 * V_2 )
{
V_89 V_257 = V_2 -> V_25 . V_258 ;
if ( V_2 -> V_25 . V_27 == 16 )
return V_235 ;
if ( ( ( T_3 ) ( V_257 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_239 ) ) ||
( ( T_3 ) ( V_257 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_259 ) ) ) {
* F_2 ( V_2 , V_239 ) = ( T_3 ) ( V_257 >> 0 ) ;
* F_2 ( V_2 , V_259 ) = ( T_3 ) ( V_257 >> 32 ) ;
V_2 -> V_177 &= ~ V_220 ;
} else {
V_2 -> V_25 . V_23 = ( ( V_89 ) F_1 ( V_2 , V_176 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_148 ) ;
V_2 -> V_177 |= V_220 ;
}
return V_68 ;
}
static int F_105 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 ;
V_95 = F_86 ( V_2 , & V_31 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
return F_34 ( V_2 , V_31 ) ;
}
static int F_106 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 , V_243 ;
T_2 V_260 ;
int V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
struct V_35 V_191 , V_254 ;
const struct V_184 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_37 == V_38 )
V_6 -> V_39 ( V_2 , & V_260 , & V_191 , NULL ,
V_100 ) ;
V_95 = F_86 ( V_2 , & V_31 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_86 ( V_2 , & V_243 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
if ( V_2 -> V_37 >= V_228 && ( V_243 & 3 ) > V_87 )
return V_235 ;
V_95 = F_78 ( V_2 , ( T_2 ) V_243 , V_100 , 0 , false ,
& V_254 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_30 ( V_2 , V_31 , V_254 . V_204 ) ;
if ( V_95 != V_68 ) {
F_22 ( V_2 -> V_37 != V_38 ) ;
V_6 -> V_73 ( V_2 , V_260 , & V_191 , 0 , V_100 ) ;
}
return V_95 ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = F_106 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
F_17 ( V_2 , V_2 -> V_22 . V_116 ) ;
return V_68 ;
}
static int F_108 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_135 = V_2 -> V_25 . V_116 ;
V_2 -> V_25 . V_116 = F_1 ( V_2 , V_239 ) ;
V_2 -> V_22 . V_135 = V_2 -> V_22 . V_116 ;
V_2 -> V_22 . V_116 = V_2 -> V_25 . V_135 ;
F_109 ( V_2 , V_261 ) ;
if ( V_2 -> V_177 & V_220 ) {
V_2 -> V_25 . V_116 = V_2 -> V_22 . V_135 ;
} else {
V_2 -> V_25 . type = V_133 ;
V_2 -> V_25 . V_79 . V_9 = F_3 ( V_2 , V_239 ) ;
V_2 -> V_25 . V_116 = V_2 -> V_25 . V_135 ;
}
return V_68 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_47 = V_2 -> V_233 . V_116 ;
unsigned short V_34 ;
int V_95 ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_66 , 2 ) ;
V_95 = F_81 ( V_2 , V_34 , V_47 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_25 . V_116 = V_2 -> V_22 . V_116 ;
return V_95 ;
}
static void
F_111 ( struct V_1 * V_2 ,
struct V_35 * V_243 , struct V_35 * V_36 )
{
V_243 -> V_204 = 0 ;
F_79 ( V_243 , 0 ) ;
V_243 -> V_46 = 1 ;
F_80 ( V_243 , 0xfffff ) ;
V_243 -> type = 0x0b ;
V_243 -> V_201 = 1 ;
V_243 -> V_93 = 0 ;
V_243 -> V_105 = 1 ;
V_243 -> V_41 = 1 ;
V_243 -> V_262 = 0 ;
F_79 ( V_36 , 0 ) ;
F_80 ( V_36 , 0xfffff ) ;
V_36 -> V_46 = 1 ;
V_36 -> V_201 = 1 ;
V_36 -> type = 0x03 ;
V_36 -> V_41 = 1 ;
V_36 -> V_93 = 0 ;
V_36 -> V_105 = 1 ;
V_36 -> V_204 = 0 ;
V_36 -> V_262 = 0 ;
}
static bool F_112 ( struct V_1 * V_2 )
{
T_3 V_263 , V_264 , V_265 , V_266 ;
V_263 = V_265 = 0 ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
return V_264 == V_268
&& V_265 == V_269
&& V_266 == V_270 ;
}
static bool F_113 ( struct V_1 * V_2 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
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
static int F_114 ( struct V_1 * V_2 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_35 V_243 , V_36 ;
V_89 V_277 ;
T_2 V_278 , V_279 ;
V_89 V_205 = 0 ;
if ( V_2 -> V_37 == V_91 ||
V_2 -> V_37 == V_200 )
return F_26 ( V_2 ) ;
if ( ! ( F_113 ( V_2 ) ) )
return F_26 ( V_2 ) ;
V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
F_111 ( V_2 , & V_243 , & V_36 ) ;
if ( ! ( V_205 & V_280 ) )
return F_26 ( V_2 ) ;
V_6 -> V_206 ( V_2 , V_281 , & V_277 ) ;
V_277 >>= 32 ;
V_278 = ( T_2 ) ( V_277 & 0xfffc ) ;
V_279 = ( T_2 ) ( V_277 + 8 ) ;
if ( V_205 & V_208 ) {
V_243 . V_41 = 0 ;
V_243 . V_204 = 1 ;
}
V_6 -> V_73 ( V_2 , V_278 , & V_243 , 0 , V_100 ) ;
V_6 -> V_73 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
* F_2 ( V_2 , V_176 ) = V_2 -> V_67 ;
if ( V_205 & V_208 ) {
#ifdef F_31
* F_2 ( V_2 , V_282 ) = V_2 -> V_177 ;
V_6 -> V_206 ( V_2 ,
V_2 -> V_37 == V_38 ?
V_283 : V_284 , & V_277 ) ;
V_2 -> V_67 = V_277 ;
V_6 -> V_206 ( V_2 , V_285 , & V_277 ) ;
V_2 -> V_177 &= ~ V_277 ;
#endif
} else {
V_6 -> V_206 ( V_2 , V_281 , & V_277 ) ;
V_2 -> V_67 = ( T_3 ) V_277 ;
V_2 -> V_177 &= ~ ( V_248 | V_230 ) ;
}
return V_68 ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_35 V_243 , V_36 ;
V_89 V_277 ;
T_2 V_278 , V_279 ;
V_89 V_205 = 0 ;
V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( V_2 -> V_37 == V_91 )
return F_24 ( V_2 , 0 ) ;
if ( ( V_2 -> V_37 == V_227 ) && ( V_205 & V_208 )
&& ! F_112 ( V_2 ) )
return F_26 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 )
return F_26 ( V_2 ) ;
F_111 ( V_2 , & V_243 , & V_36 ) ;
V_6 -> V_206 ( V_2 , V_286 , & V_277 ) ;
switch ( V_2 -> V_37 ) {
case V_227 :
if ( ( V_277 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
break;
case V_38 :
if ( V_277 == 0x0 )
return F_24 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_177 &= ~ ( V_248 | V_230 ) ;
V_278 = ( T_2 ) V_277 ;
V_278 &= ~ V_287 ;
V_279 = V_278 + 8 ;
V_279 &= ~ V_287 ;
if ( V_2 -> V_37 == V_38 || ( V_205 & V_208 ) ) {
V_243 . V_41 = 0 ;
V_243 . V_204 = 1 ;
}
V_6 -> V_73 ( V_2 , V_278 , & V_243 , 0 , V_100 ) ;
V_6 -> V_73 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
V_6 -> V_206 ( V_2 , V_288 , & V_277 ) ;
V_2 -> V_67 = V_277 ;
V_6 -> V_206 ( V_2 , V_289 , & V_277 ) ;
* F_2 ( V_2 , V_43 ) = V_277 ;
return V_68 ;
}
static int F_116 ( struct V_1 * V_2 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_35 V_243 , V_36 ;
V_89 V_277 , V_290 , V_291 ;
int V_292 ;
T_2 V_278 = 0 , V_279 = 0 ;
if ( V_2 -> V_37 == V_91 ||
V_2 -> V_37 == V_200 )
return F_24 ( V_2 , 0 ) ;
F_111 ( V_2 , & V_243 , & V_36 ) ;
if ( ( V_2 -> V_107 & 0x8 ) != 0x0 )
V_292 = V_38 ;
else
V_292 = V_227 ;
V_290 = F_1 ( V_2 , V_176 ) ;
V_291 = F_1 ( V_2 , V_259 ) ;
V_243 . V_93 = 3 ;
V_36 . V_93 = 3 ;
V_6 -> V_206 ( V_2 , V_286 , & V_277 ) ;
switch ( V_292 ) {
case V_227 :
V_278 = ( T_2 ) ( V_277 + 16 ) ;
if ( ( V_277 & 0xfffc ) == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_279 = ( T_2 ) ( V_277 + 24 ) ;
break;
case V_38 :
V_278 = ( T_2 ) ( V_277 + 32 ) ;
if ( V_277 == 0x0 )
return F_24 ( V_2 , 0 ) ;
V_279 = V_278 + 8 ;
V_243 . V_41 = 0 ;
V_243 . V_204 = 1 ;
if ( F_32 ( V_290 ) ||
F_32 ( V_291 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
V_278 |= V_287 ;
V_279 |= V_287 ;
V_6 -> V_73 ( V_2 , V_278 , & V_243 , 0 , V_100 ) ;
V_6 -> V_73 ( V_2 , V_279 , & V_36 , 0 , V_40 ) ;
V_2 -> V_67 = V_291 ;
* F_2 ( V_2 , V_43 ) = V_290 ;
return V_68 ;
}
static bool F_117 ( struct V_1 * V_2 )
{
int V_214 ;
if ( V_2 -> V_37 == V_91 )
return false ;
if ( V_2 -> V_37 == V_200 )
return true ;
V_214 = ( V_2 -> V_177 & V_215 ) >> V_216 ;
return V_2 -> V_6 -> V_87 ( V_2 ) > V_214 ;
}
static bool F_118 ( struct V_1 * V_2 ,
T_2 V_171 , T_2 V_212 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_35 V_293 ;
T_3 V_72 ;
int V_294 ;
T_2 V_295 , V_296 , V_297 , V_298 = V_171 & 0x7 ;
unsigned V_33 = ( 1 << V_212 ) - 1 ;
unsigned long V_299 ;
V_6 -> V_39 ( V_2 , & V_295 , & V_293 , & V_72 , V_202 ) ;
if ( ! V_293 . V_105 )
return false ;
if ( F_18 ( & V_293 ) < 103 )
return false ;
V_299 = F_75 ( & V_293 ) ;
#ifdef F_31
V_299 |= ( ( V_89 ) V_72 ) << 32 ;
#endif
V_294 = V_6 -> V_96 ( V_2 , V_299 + 102 , & V_296 , 2 , NULL ) ;
if ( V_294 != V_68 )
return false ;
if ( V_296 + V_171 / 8 > F_18 ( & V_293 ) )
return false ;
V_294 = V_6 -> V_96 ( V_2 , V_299 + V_296 + V_171 / 8 , & V_297 , 2 , NULL ) ;
if ( V_294 != V_68 )
return false ;
if ( ( V_297 >> V_298 ) & V_33 )
return false ;
return true ;
}
static bool F_119 ( struct V_1 * V_2 ,
T_2 V_171 , T_2 V_212 )
{
if ( V_2 -> V_300 )
return true ;
if ( F_117 ( V_2 ) )
if ( ! F_118 ( V_2 , V_171 , V_212 ) )
return false ;
V_2 -> V_300 = true ;
return true ;
}
static void F_120 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
V_302 -> V_303 = V_2 -> V_67 ;
V_302 -> V_304 = V_2 -> V_177 ;
V_302 -> V_305 = F_1 ( V_2 , V_239 ) ;
V_302 -> V_306 = F_1 ( V_2 , V_176 ) ;
V_302 -> V_307 = F_1 ( V_2 , V_259 ) ;
V_302 -> V_147 = F_1 ( V_2 , V_148 ) ;
V_302 -> V_308 = F_1 ( V_2 , V_43 ) ;
V_302 -> V_149 = F_1 ( V_2 , V_137 ) ;
V_302 -> V_150 = F_1 ( V_2 , V_151 ) ;
V_302 -> V_152 = F_1 ( V_2 , V_153 ) ;
V_302 -> V_309 = F_36 ( V_2 , V_310 ) ;
V_302 -> V_243 = F_36 ( V_2 , V_100 ) ;
V_302 -> V_36 = F_36 ( V_2 , V_40 ) ;
V_302 -> V_311 = F_36 ( V_2 , V_144 ) ;
V_302 -> V_312 = F_36 ( V_2 , V_185 ) ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
int V_197 ;
T_5 V_87 ;
V_2 -> V_67 = V_302 -> V_303 ;
V_2 -> V_177 = V_302 -> V_304 | 2 ;
* F_2 ( V_2 , V_239 ) = V_302 -> V_305 ;
* F_2 ( V_2 , V_176 ) = V_302 -> V_306 ;
* F_2 ( V_2 , V_259 ) = V_302 -> V_307 ;
* F_2 ( V_2 , V_148 ) = V_302 -> V_147 ;
* F_2 ( V_2 , V_43 ) = V_302 -> V_308 ;
* F_2 ( V_2 , V_137 ) = V_302 -> V_149 ;
* F_2 ( V_2 , V_151 ) = V_302 -> V_150 ;
* F_2 ( V_2 , V_153 ) = V_302 -> V_152 ;
F_37 ( V_2 , V_302 -> V_312 , V_185 ) ;
F_37 ( V_2 , V_302 -> V_309 , V_310 ) ;
F_37 ( V_2 , V_302 -> V_243 , V_100 ) ;
F_37 ( V_2 , V_302 -> V_36 , V_40 ) ;
F_37 ( V_2 , V_302 -> V_311 , V_144 ) ;
V_87 = V_302 -> V_243 & 3 ;
V_197 = F_78 ( V_2 , V_302 -> V_312 , V_185 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_309 , V_310 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_243 , V_100 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_36 , V_40 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_311 , V_144 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
return V_68 ;
}
static int F_122 ( struct V_1 * V_2 ,
T_2 V_313 , T_2 V_314 ,
T_1 V_315 , struct V_35 * V_254 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_301 V_316 ;
int V_197 ;
T_3 V_317 = F_75 ( V_254 ) ;
V_197 = V_6 -> V_96 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
F_120 ( V_2 , & V_316 ) ;
V_197 = V_6 -> V_188 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = V_6 -> V_96 ( V_2 , V_317 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
if ( V_314 != 0xffff ) {
V_316 . V_318 = V_314 ;
V_197 = V_6 -> V_188 ( V_2 , V_317 ,
& V_316 . V_318 ,
sizeof V_316 . V_318 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
}
return F_121 ( V_2 , & V_316 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_319 * V_302 )
{
V_302 -> V_31 = V_2 -> V_67 ;
V_302 -> V_177 = V_2 -> V_177 ;
V_302 -> V_263 = F_1 ( V_2 , V_239 ) ;
V_302 -> V_265 = F_1 ( V_2 , V_176 ) ;
V_302 -> V_266 = F_1 ( V_2 , V_259 ) ;
V_302 -> V_264 = F_1 ( V_2 , V_148 ) ;
V_302 -> V_320 = F_1 ( V_2 , V_43 ) ;
V_302 -> V_321 = F_1 ( V_2 , V_137 ) ;
V_302 -> V_322 = F_1 ( V_2 , V_151 ) ;
V_302 -> V_323 = F_1 ( V_2 , V_153 ) ;
V_302 -> V_309 = F_36 ( V_2 , V_310 ) ;
V_302 -> V_243 = F_36 ( V_2 , V_100 ) ;
V_302 -> V_36 = F_36 ( V_2 , V_40 ) ;
V_302 -> V_311 = F_36 ( V_2 , V_144 ) ;
V_302 -> V_324 = F_36 ( V_2 , V_48 ) ;
V_302 -> V_325 = F_36 ( V_2 , V_199 ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_319 * V_302 )
{
int V_197 ;
T_5 V_87 ;
if ( V_2 -> V_6 -> V_326 ( V_2 , 3 , V_302 -> V_327 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_67 = V_302 -> V_31 ;
V_2 -> V_177 = V_302 -> V_177 | 2 ;
* F_2 ( V_2 , V_239 ) = V_302 -> V_263 ;
* F_2 ( V_2 , V_176 ) = V_302 -> V_265 ;
* F_2 ( V_2 , V_259 ) = V_302 -> V_266 ;
* F_2 ( V_2 , V_148 ) = V_302 -> V_264 ;
* F_2 ( V_2 , V_43 ) = V_302 -> V_320 ;
* F_2 ( V_2 , V_137 ) = V_302 -> V_321 ;
* F_2 ( V_2 , V_151 ) = V_302 -> V_322 ;
* F_2 ( V_2 , V_153 ) = V_302 -> V_323 ;
F_37 ( V_2 , V_302 -> V_328 , V_185 ) ;
F_37 ( V_2 , V_302 -> V_309 , V_310 ) ;
F_37 ( V_2 , V_302 -> V_243 , V_100 ) ;
F_37 ( V_2 , V_302 -> V_36 , V_40 ) ;
F_37 ( V_2 , V_302 -> V_311 , V_144 ) ;
F_37 ( V_2 , V_302 -> V_324 , V_48 ) ;
F_37 ( V_2 , V_302 -> V_325 , V_199 ) ;
if ( V_2 -> V_177 & V_329 ) {
V_2 -> V_37 = V_200 ;
V_87 = 3 ;
} else {
V_2 -> V_37 = V_227 ;
V_87 = V_302 -> V_243 & 3 ;
}
V_197 = F_78 ( V_2 , V_302 -> V_328 , V_185 ,
V_87 , true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_309 , V_310 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_243 , V_100 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_36 , V_40 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_311 , V_144 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_324 , V_48 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_78 ( V_2 , V_302 -> V_325 , V_199 , V_87 ,
true , NULL ) ;
if ( V_197 != V_68 )
return V_197 ;
return V_68 ;
}
static int F_125 ( struct V_1 * V_2 ,
T_2 V_313 , T_2 V_314 ,
T_1 V_315 , struct V_35 * V_254 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_319 V_316 ;
int V_197 ;
T_3 V_317 = F_75 ( V_254 ) ;
T_3 V_330 = F_126 ( struct V_319 , V_31 ) ;
T_3 V_331 = F_126 ( struct V_319 , V_328 ) ;
V_197 = V_6 -> V_96 ( V_2 , V_315 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
F_123 ( V_2 , & V_316 ) ;
V_197 = V_6 -> V_188 ( V_2 , V_315 + V_330 , & V_316 . V_31 ,
V_331 - V_330 , & V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = V_6 -> V_96 ( V_2 , V_317 , & V_316 , sizeof V_316 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
if ( V_314 != 0xffff ) {
V_316 . V_318 = V_314 ;
V_197 = V_6 -> V_188 ( V_2 , V_317 ,
& V_316 . V_318 ,
sizeof V_316 . V_318 ,
& V_2 -> V_52 ) ;
if ( V_197 != V_68 )
return V_197 ;
}
return F_124 ( V_2 , & V_316 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
T_2 V_313 , int V_332 , int V_333 ,
bool V_334 , T_3 V_54 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
struct V_35 V_335 , V_336 ;
int V_197 ;
T_2 V_314 = F_36 ( V_2 , V_202 ) ;
T_1 V_315 =
V_6 -> V_49 ( V_2 , V_202 ) ;
T_3 V_337 ;
T_1 V_196 ;
V_197 = F_76 ( V_2 , V_313 , & V_336 , & V_196 ) ;
if ( V_197 != V_68 )
return V_197 ;
V_197 = F_76 ( V_2 , V_314 , & V_335 , & V_196 ) ;
if ( V_197 != V_68 )
return V_197 ;
if ( V_333 == V_338 ) {
if ( V_332 != - 1 ) {
struct V_35 V_339 ;
int V_93 ;
V_197 = F_73 ( V_2 , V_332 ,
& V_339 ) ;
if ( V_197 != V_68 )
return V_197 ;
V_93 = V_339 . V_93 ;
if ( ( V_313 & 3 ) > V_93 || V_6 -> V_87 ( V_2 ) > V_93 )
return F_24 ( V_2 , ( V_332 << 3 ) | 0x2 ) ;
}
} else if ( V_333 != V_340 ) {
int V_93 = V_336 . V_93 ;
if ( ( V_313 & 3 ) > V_93 || V_6 -> V_87 ( V_2 ) > V_93 )
return F_24 ( V_2 , V_313 ) ;
}
V_337 = F_18 ( & V_336 ) ;
if ( ! V_336 . V_105 ||
( ( V_337 < 0x67 && ( V_336 . type & 8 ) ) ||
V_337 < 0x2b ) ) {
return F_27 ( V_2 , V_313 & 0xfffc ) ;
}
if ( V_333 == V_340 || V_333 == V_341 ) {
V_335 . type &= ~ ( 1 << 1 ) ;
F_77 ( V_2 , V_314 , & V_335 ) ;
}
if ( V_333 == V_340 )
V_2 -> V_177 = V_2 -> V_177 & ~ V_342 ;
if ( V_333 != V_343 && V_333 != V_338 )
V_314 = 0xffff ;
if ( V_336 . type & 8 )
V_197 = F_125 ( V_2 , V_313 , V_314 ,
V_315 , & V_336 ) ;
else
V_197 = F_122 ( V_2 , V_313 , V_314 ,
V_315 , & V_336 ) ;
if ( V_197 != V_68 )
return V_197 ;
if ( V_333 == V_343 || V_333 == V_338 )
V_2 -> V_177 = V_2 -> V_177 | V_342 ;
if ( V_333 != V_340 ) {
V_336 . type |= ( 1 << 1 ) ;
F_77 ( V_2 , V_313 , & V_336 ) ;
}
V_6 -> V_326 ( V_2 , 0 , V_6 -> V_119 ( V_2 , 0 ) | V_120 ) ;
V_6 -> V_73 ( V_2 , V_313 , & V_336 , 0 , V_202 ) ;
if ( V_334 ) {
V_2 -> V_66 = V_2 -> V_29 = ( V_336 . type & 8 ) ? 4 : 2 ;
V_2 -> V_209 = 0 ;
V_2 -> V_22 . V_116 = ( unsigned long ) V_54 ;
V_197 = F_85 ( V_2 ) ;
}
return V_197 ;
}
int F_128 ( struct V_1 * V_2 ,
T_2 V_313 , int V_332 , int V_333 ,
bool V_334 , T_3 V_54 )
{
int V_95 ;
F_6 ( V_2 ) ;
V_2 -> V_67 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_211 ;
V_95 = F_127 ( V_2 , V_313 , V_332 , V_333 ,
V_334 , V_54 ) ;
if ( V_95 == V_68 ) {
V_2 -> V_31 = V_2 -> V_67 ;
F_4 ( V_2 ) ;
}
return ( V_95 == V_235 ) ? V_344 : V_345 ;
}
static void F_129 ( struct V_1 * V_2 , int V_9 ,
struct V_114 * V_115 )
{
int V_346 = ( V_2 -> V_177 & V_178 ) ? - V_115 -> V_175 : V_115 -> V_175 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_346 * V_115 -> V_27 ) ;
V_115 -> V_79 . V_157 . V_88 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
T_5 V_347 , V_348 ;
bool V_349 , V_350 , V_351 ;
V_350 = V_2 -> V_177 & V_352 ;
V_347 = V_2 -> V_25 . V_116 ;
V_348 = V_347 ;
V_351 = V_350 ;
V_350 = false ;
V_349 = V_2 -> V_177 & V_353 ;
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
V_2 -> V_25 . V_116 = V_347 ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_116 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_109 ( V_2 , V_355 ) ;
V_2 -> V_177 &= ~ ( V_353 | V_352 ) ;
if ( V_350 )
V_2 -> V_177 |= V_352 ;
if ( V_349 )
V_2 -> V_177 |= V_353 ;
return V_68 ;
}
static int F_131 ( struct V_1 * V_2 )
{
T_5 V_347 , V_356 ;
if ( V_2 -> V_22 . V_116 == 0 )
return F_28 ( V_2 ) ;
V_347 = V_2 -> V_25 . V_116 & 0xff ;
V_356 = V_347 / V_2 -> V_22 . V_116 ;
V_347 %= V_2 -> V_22 . V_116 ;
V_2 -> V_25 . V_116 = ( V_2 -> V_25 . V_116 & 0xffff0000 ) | V_347 | ( V_356 << 8 ) ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_116 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_109 ( V_2 , V_355 ) ;
return V_68 ;
}
static int F_132 ( struct V_1 * V_2 )
{
T_5 V_347 = V_2 -> V_25 . V_116 & 0xff ;
T_5 V_356 = ( V_2 -> V_25 . V_116 >> 8 ) & 0xff ;
V_347 = ( V_347 + ( V_356 * V_2 -> V_22 . V_116 ) ) & 0xff ;
V_2 -> V_25 . V_116 = ( V_2 -> V_25 . V_116 & 0xffff0000 ) | V_347 ;
V_2 -> V_22 . type = V_354 ;
V_2 -> V_22 . V_116 = 0 ;
V_2 -> V_22 . V_27 = 1 ;
F_109 ( V_2 , V_355 ) ;
return V_68 ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_95 ;
long V_69 = V_2 -> V_22 . V_116 ;
V_2 -> V_22 . V_116 = ( unsigned long ) V_2 -> V_67 ;
V_95 = F_35 ( V_2 , V_69 ) ;
if ( V_95 != V_68 )
return V_95 ;
return F_85 ( V_2 ) ;
}
static int F_134 ( struct V_1 * V_2 )
{
T_2 V_34 , V_260 ;
T_1 V_256 ;
int V_95 ;
struct V_35 V_191 , V_254 ;
const struct V_184 * V_6 = V_2 -> V_6 ;
int V_87 = V_2 -> V_6 -> V_87 ( V_2 ) ;
V_256 = V_2 -> V_67 ;
V_6 -> V_39 ( V_2 , & V_260 , & V_191 , NULL , V_100 ) ;
memcpy ( & V_34 , V_2 -> V_22 . V_255 + V_2 -> V_66 , 2 ) ;
V_95 = F_78 ( V_2 , V_34 , V_100 , V_87 , false ,
& V_254 ) ;
if ( V_95 != V_68 )
return V_68 ;
V_95 = F_30 ( V_2 , V_2 -> V_22 . V_116 , V_254 . V_204 ) ;
if ( V_95 != V_68 )
goto V_357;
V_2 -> V_22 . V_116 = V_260 ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
goto V_357;
V_2 -> V_22 . V_116 = V_256 ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != V_68 )
goto V_357;
return V_95 ;
V_357:
V_6 -> V_73 ( V_2 , V_260 , & V_191 , 0 , V_100 ) ;
return V_95 ;
}
static int F_135 ( struct V_1 * V_2 )
{
int V_95 ;
unsigned long V_31 ;
V_95 = F_86 ( V_2 , & V_31 , V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_95 = F_34 ( V_2 , V_31 ) ;
if ( V_95 != V_68 )
return V_95 ;
F_17 ( V_2 , V_2 -> V_22 . V_116 ) ;
return V_68 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_116 = V_2 -> V_25 . V_116 ;
F_82 ( & V_2 -> V_22 ) ;
V_2 -> V_25 . V_116 = V_2 -> V_22 . V_135 ;
V_2 -> V_209 = 1 ;
return V_68 ;
}
static int F_137 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_116 = V_2 -> V_233 . V_116 ;
return F_109 ( V_2 , V_358 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
V_2 -> V_25 . type = V_133 ;
V_2 -> V_25 . V_27 = V_2 -> V_22 . V_27 ;
V_2 -> V_25 . V_79 . V_9 = F_3 ( V_2 , V_259 ) ;
V_2 -> V_25 . V_116 = ~ ( ( V_2 -> V_22 . V_116 >> ( V_2 -> V_22 . V_27 * 8 - 1 ) ) - 1 ) ;
return V_68 ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_89 V_359 = 0 ;
V_2 -> V_6 -> V_206 ( V_2 , V_360 , & V_359 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_359 ;
* F_2 ( V_2 , V_259 ) = V_359 >> 32 ;
return V_68 ;
}
static int F_140 ( struct V_1 * V_2 )
{
V_89 V_361 ;
if ( V_2 -> V_6 -> V_362 ( V_2 , F_1 ( V_2 , V_176 ) , & V_361 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_361 ;
* F_2 ( V_2 , V_259 ) = V_361 >> 32 ;
return V_68 ;
}
static int F_141 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_25 . V_255 , V_2 -> V_22 . V_255 , sizeof( V_2 -> V_22 . V_255 ) ) ;
return V_68 ;
}
static int F_142 ( struct V_1 * V_2 )
{
T_3 V_264 , V_265 , V_266 , V_263 = 1 ;
T_2 V_363 ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
if ( ! ( V_265 & F_143 ( V_364 ) ) )
return F_26 ( V_2 ) ;
switch ( V_2 -> V_66 ) {
case 2 :
V_363 = ( T_2 ) V_2 -> V_22 . V_116 ;
V_2 -> V_25 . V_116 &= ~ 0xffffUL ;
V_2 -> V_25 . V_116 |= ( unsigned long ) F_144 ( V_363 ) ;
break;
case 4 :
V_2 -> V_25 . V_116 = F_145 ( ( T_3 ) V_2 -> V_22 . V_116 ) ;
break;
case 8 :
V_2 -> V_25 . V_116 = F_146 ( V_2 -> V_22 . V_116 ) ;
break;
default:
F_54 () ;
}
return V_68 ;
}
static int F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_326 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_116 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_148 ( struct V_1 * V_2 )
{
unsigned long V_116 ;
if ( V_2 -> V_37 == V_38 )
V_116 = V_2 -> V_22 . V_116 & ~ 0ULL ;
else
V_116 = V_2 -> V_22 . V_116 & ~ 0U ;
if ( V_2 -> V_6 -> V_365 ( V_2 , V_2 -> V_19 , V_116 ) < 0 )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_149 ( struct V_1 * V_2 )
{
V_89 V_277 ;
V_277 = ( T_3 ) F_1 ( V_2 , V_239 )
| ( ( V_89 ) F_1 ( V_2 , V_259 ) << 32 ) ;
if ( V_2 -> V_6 -> V_366 ( V_2 , F_1 ( V_2 , V_176 ) , V_277 ) )
return F_24 ( V_2 , 0 ) ;
return V_68 ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_89 V_277 ;
if ( V_2 -> V_6 -> V_206 ( V_2 , F_1 ( V_2 , V_176 ) , & V_277 ) )
return F_24 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_239 ) = ( T_3 ) V_277 ;
* F_2 ( V_2 , V_259 ) = V_277 >> 32 ;
return V_68 ;
}
static int F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_199 )
return F_26 ( V_2 ) ;
V_2 -> V_25 . V_116 = F_36 ( V_2 , V_2 -> V_19 ) ;
return V_68 ;
}
static int F_152 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_116 ;
if ( V_2 -> V_19 == V_100 || V_2 -> V_19 > V_199 )
return F_26 ( V_2 ) ;
if ( V_2 -> V_19 == V_40 )
V_2 -> V_236 = V_237 ;
V_2 -> V_25 . type = V_211 ;
return F_81 ( V_2 , V_34 , V_2 -> V_19 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_116 ;
V_2 -> V_25 . type = V_211 ;
return F_81 ( V_2 , V_34 , V_185 ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
T_2 V_34 = V_2 -> V_22 . V_116 ;
V_2 -> V_25 . type = V_211 ;
return F_81 ( V_2 , V_34 , V_202 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_95 ;
T_1 V_83 ;
V_95 = F_42 ( V_2 , V_2 -> V_22 . V_79 . V_157 , 1 , false , & V_83 ) ;
if ( V_95 == V_68 )
V_2 -> V_6 -> V_367 ( V_2 , V_83 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_1 V_368 ;
V_368 = V_2 -> V_6 -> V_119 ( V_2 , 0 ) ;
V_368 &= ~ V_120 ;
V_2 -> V_6 -> V_326 ( V_2 , 0 , V_368 ) ;
return V_68 ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_95 = V_2 -> V_6 -> V_369 ( V_2 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_67 = V_2 -> V_31 ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_158 ( struct V_1 * V_2 ,
void (* F_159)( struct V_1 * V_2 ,
struct V_181 * V_103 ) )
{
struct V_181 V_181 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_66 = 8 ;
F_159 ( V_2 , & V_181 ) ;
if ( V_2 -> V_66 == 2 ) {
V_2 -> V_66 = 4 ;
V_181 . V_108 &= 0x00ffffff ;
}
V_2 -> V_25 . type = V_211 ;
return F_69 ( V_2 , V_2 -> V_25 . V_79 . V_157 ,
& V_181 , 2 + V_2 -> V_66 ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
return F_158 ( V_2 , V_2 -> V_6 -> V_186 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
return F_158 ( V_2 , V_2 -> V_6 -> V_183 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_181 V_181 ;
int V_95 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_66 = 8 ;
V_95 = F_49 ( V_2 , V_2 -> V_22 . V_79 . V_157 ,
& V_181 . V_74 , & V_181 . V_108 ,
V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_6 -> V_370 ( V_2 , & V_181 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = V_2 -> V_6 -> V_369 ( V_2 ) ;
V_2 -> V_25 . type = V_211 ;
return V_95 ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_181 V_181 ;
int V_95 ;
if ( V_2 -> V_37 == V_38 )
V_2 -> V_66 = 8 ;
V_95 = F_49 ( V_2 , V_2 -> V_22 . V_79 . V_157 ,
& V_181 . V_74 , & V_181 . V_108 ,
V_2 -> V_66 ) ;
if ( V_95 != V_68 )
return V_95 ;
V_2 -> V_6 -> V_371 ( V_2 , & V_181 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_165 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 . type == V_146 )
V_2 -> V_25 . V_27 = 2 ;
V_2 -> V_25 . V_116 = V_2 -> V_6 -> V_119 ( V_2 , 0 ) ;
return V_68 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_326 ( V_2 , 0 , ( V_2 -> V_6 -> V_119 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_116 & 0x0f ) ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_167 ( struct V_1 * V_2 )
{
int V_95 = V_68 ;
F_16 ( V_2 , F_3 ( V_2 , V_176 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_176 ) ) != 0 ) &&
( V_2 -> V_125 == 0xe2 || F_50 ( V_2 -> V_125 ^ 0x5 , V_2 -> V_177 ) ) )
V_95 = F_35 ( V_2 , V_2 -> V_22 . V_116 ) ;
return V_95 ;
}
static int F_168 ( struct V_1 * V_2 )
{
int V_95 = V_68 ;
if ( F_13 ( V_2 , F_1 ( V_2 , V_176 ) ) == 0 )
V_95 = F_35 ( V_2 , V_2 -> V_22 . V_116 ) ;
return V_95 ;
}
static int F_169 ( struct V_1 * V_2 )
{
if ( ! F_71 ( V_2 , V_2 -> V_25 . V_27 , V_2 -> V_22 . V_116 ,
& V_2 -> V_25 . V_116 ) )
return V_372 ;
return V_68 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_373 ( V_2 , V_2 -> V_22 . V_27 , V_2 -> V_25 . V_116 ,
& V_2 -> V_22 . V_116 , 1 ) ;
V_2 -> V_25 . type = V_211 ;
return V_68 ;
}
static int F_171 ( struct V_1 * V_2 )
{
if ( F_117 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_177 &= ~ V_113 ;
return V_68 ;
}
static int F_172 ( struct V_1 * V_2 )
{
if ( F_117 ( V_2 ) )
return F_24 ( V_2 , 0 ) ;
V_2 -> V_236 = V_374 ;
V_2 -> V_177 |= V_113 ;
return V_68 ;
}
static int F_173 ( struct V_1 * V_2 )
{
T_3 V_263 , V_264 , V_265 , V_266 ;
V_263 = F_1 ( V_2 , V_239 ) ;
V_265 = F_1 ( V_2 , V_176 ) ;
V_2 -> V_6 -> V_267 ( V_2 , & V_263 , & V_264 , & V_265 , & V_266 ) ;
* F_2 ( V_2 , V_239 ) = V_263 ;
* F_2 ( V_2 , V_148 ) = V_264 ;
* F_2 ( V_2 , V_176 ) = V_265 ;
* F_2 ( V_2 , V_259 ) = V_266 ;
return V_68 ;
}
static int F_174 ( struct V_1 * V_2 )
{
T_3 V_110 ;
V_110 = V_217 | V_218 | V_219 | V_220 | V_221 ;
V_110 &= * F_3 ( V_2 , V_239 ) >> 8 ;
V_2 -> V_177 &= ~ 0xffUL ;
V_2 -> V_177 |= V_110 | V_375 ;
return V_68 ;
}
static int F_175 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_239 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_239 ) |= ( V_2 -> V_177 & 0xff ) << 8 ;
return V_68 ;
}
static int F_176 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_66 ) {
#ifdef F_31
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_68 ;
}
static int F_177 ( struct V_1 * V_2 )
{
return V_68 ;
}
static bool F_178 ( int V_3 )
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
static int F_179 ( struct V_1 * V_2 )
{
if ( ! F_178 ( V_2 -> V_19 ) )
return F_26 ( V_2 ) ;
return V_68 ;
}
static int F_180 ( struct V_1 * V_2 )
{
V_89 V_376 = V_2 -> V_22 . V_23 ;
int V_377 = V_2 -> V_19 ;
V_89 V_205 = 0 ;
static V_89 V_378 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_379 ,
0 , 0 , 0 ,
V_380 ,
} ;
if ( ! F_178 ( V_377 ) )
return F_26 ( V_2 ) ;
if ( V_376 & V_378 [ V_377 ] )
return F_24 ( V_2 , 0 ) ;
switch ( V_377 ) {
case 0 : {
V_89 V_381 ;
if ( ( ( V_376 & V_382 ) && ! ( V_376 & V_383 ) ) ||
( ( V_376 & V_384 ) && ! ( V_376 & V_385 ) ) )
return F_24 ( V_2 , 0 ) ;
V_381 = V_2 -> V_6 -> V_119 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( ( V_376 & V_382 ) && ( V_205 & V_386 ) &&
! ( V_381 & V_387 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_89 V_388 = 0 ;
V_2 -> V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( V_205 & V_208 )
V_388 = V_389 ;
if ( V_376 & V_388 )
return F_24 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( ( V_205 & V_208 ) && ! ( V_376 & V_387 ) )
return F_24 ( V_2 , 0 ) ;
break;
}
}
return V_68 ;
}
static int F_181 ( struct V_1 * V_2 )
{
unsigned long V_390 ;
V_2 -> V_6 -> V_391 ( V_2 , 7 , & V_390 ) ;
return V_390 & ( 1 << 13 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
int V_392 = V_2 -> V_19 ;
V_89 V_381 ;
if ( V_392 > 7 )
return F_26 ( V_2 ) ;
V_381 = V_2 -> V_6 -> V_119 ( V_2 , 4 ) ;
if ( ( V_381 & V_393 ) && ( V_392 == 4 || V_392 == 5 ) )
return F_26 ( V_2 ) ;
if ( F_181 ( V_2 ) )
return F_23 ( V_2 ) ;
return V_68 ;
}
static int F_183 ( struct V_1 * V_2 )
{
V_89 V_376 = V_2 -> V_22 . V_23 ;
int V_392 = V_2 -> V_19 ;
if ( ( V_392 == 6 || V_392 == 7 ) && ( V_376 & 0xffffffff00000000ULL ) )
return F_24 ( V_2 , 0 ) ;
return F_182 ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
V_89 V_205 ;
V_2 -> V_6 -> V_206 ( V_2 , V_207 , & V_205 ) ;
if ( ! ( V_205 & V_394 ) )
return F_26 ( V_2 ) ;
return V_68 ;
}
static int F_185 ( struct V_1 * V_2 )
{
V_89 V_395 = F_1 ( V_2 , V_239 ) ;
if ( V_395 & 0xffff000000000000ULL )
return F_24 ( V_2 , 0 ) ;
return F_184 ( V_2 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
V_89 V_381 = V_2 -> V_6 -> V_119 ( V_2 , 4 ) ;
if ( V_381 & V_396 && V_2 -> V_6 -> V_87 ( V_2 ) )
return F_26 ( V_2 ) ;
return V_68 ;
}
static int F_187 ( struct V_1 * V_2 )
{
V_89 V_381 = V_2 -> V_6 -> V_119 ( V_2 , 4 ) ;
V_89 V_290 = F_1 ( V_2 , V_176 ) ;
if ( ( ! ( V_381 & V_397 ) && V_2 -> V_6 -> V_87 ( V_2 ) ) ||
V_2 -> V_6 -> V_398 ( V_2 , V_290 ) )
return F_24 ( V_2 , 0 ) ;
return V_68 ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_25 . V_27 = F_189 ( V_2 -> V_25 . V_27 , 4u ) ;
if ( ! F_119 ( V_2 , V_2 -> V_22 . V_116 , V_2 -> V_25 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_68 ;
}
static int F_190 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_27 = F_189 ( V_2 -> V_22 . V_27 , 4u ) ;
if ( ! F_119 ( V_2 , V_2 -> V_25 . V_116 , V_2 -> V_22 . V_27 ) )
return F_24 ( V_2 , 0 ) ;
return V_68 ;
}
static unsigned F_191 ( struct V_1 * V_2 )
{
unsigned V_74 ;
V_74 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
if ( V_74 == 8 )
V_74 = 4 ;
return V_74 ;
}
static int F_192 ( struct V_1 * V_2 , struct V_114 * V_115 ,
unsigned V_74 , bool V_399 )
{
int V_95 = V_68 ;
V_115 -> type = V_354 ;
V_115 -> V_27 = V_74 ;
V_115 -> V_79 . V_157 . V_88 = V_2 -> V_67 ;
switch ( V_115 -> V_27 ) {
case 1 :
V_115 -> V_116 = F_64 ( V_154 , V_2 ) ;
break;
case 2 :
V_115 -> V_116 = F_64 ( V_161 , V_2 ) ;
break;
case 4 :
V_115 -> V_116 = F_64 ( V_155 , V_2 ) ;
break;
case 8 :
V_115 -> V_116 = F_64 ( V_162 , V_2 ) ;
break;
}
if ( ! V_399 ) {
switch ( V_115 -> V_27 ) {
case 1 :
V_115 -> V_116 &= 0xff ;
break;
case 2 :
V_115 -> V_116 &= 0xffff ;
break;
case 4 :
V_115 -> V_116 &= 0xffffffff ;
break;
}
}
V_159:
return V_95 ;
}
static int F_193 ( struct V_1 * V_2 , struct V_114 * V_115 ,
unsigned V_41 )
{
int V_95 = V_68 ;
switch ( V_41 ) {
case V_400 :
F_61 ( V_2 , V_115 ) ;
break;
case V_401 :
V_95 = F_192 ( V_2 , V_115 , 1 , false ) ;
break;
case V_402 :
V_2 -> V_158 . V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_403:
* V_115 = V_2 -> V_158 ;
V_2 -> V_404 = V_115 ;
if ( V_2 -> V_41 & V_405 )
F_66 ( V_2 ) ;
V_115 -> V_135 = V_115 -> V_116 ;
break;
case V_406 :
V_2 -> V_158 . V_27 = ( V_2 -> V_66 == 8 ) ? 16 : 8 ;
goto V_403;
case V_407 :
V_115 -> type = V_133 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_9 = F_3 ( V_2 , V_239 ) ;
F_52 ( V_115 ) ;
V_115 -> V_135 = V_115 -> V_116 ;
break;
case V_408 :
V_115 -> type = V_133 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 2 : V_2 -> V_66 ;
V_115 -> V_79 . V_9 = F_3 ( V_2 , V_239 ) ;
F_52 ( V_115 ) ;
V_115 -> V_135 = V_115 -> V_116 ;
break;
case V_409 :
if ( V_2 -> V_41 & V_134 ) {
V_115 -> type = V_211 ;
break;
}
V_115 -> type = V_133 ;
V_115 -> V_27 = V_2 -> V_66 ;
V_115 -> V_79 . V_9 = F_3 ( V_2 , V_259 ) ;
F_52 ( V_115 ) ;
V_115 -> V_135 = V_115 -> V_116 ;
break;
case V_410 :
V_115 -> type = V_146 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_157 . V_88 =
F_14 ( V_2 , F_1 ( V_2 , V_153 ) ) ;
V_115 -> V_79 . V_157 . V_47 = V_310 ;
V_115 -> V_116 = 0 ;
V_115 -> V_175 = 1 ;
break;
case V_411 :
V_115 -> type = V_133 ;
V_115 -> V_27 = 2 ;
V_115 -> V_79 . V_9 = F_3 ( V_2 , V_259 ) ;
F_52 ( V_115 ) ;
break;
case V_412 :
V_115 -> type = V_354 ;
V_115 -> V_27 = 1 ;
V_115 -> V_116 = F_1 ( V_2 , V_176 ) & 0xff ;
break;
case V_413 :
V_95 = F_192 ( V_2 , V_115 , 1 , true ) ;
break;
case V_414 :
V_115 -> type = V_354 ;
V_115 -> V_27 = 1 ;
V_115 -> V_116 = 1 ;
break;
case V_415 :
V_95 = F_192 ( V_2 , V_115 , F_191 ( V_2 ) , true ) ;
break;
case V_416 :
V_95 = F_192 ( V_2 , V_115 , V_2 -> V_66 , true ) ;
break;
case V_417 :
V_2 -> V_158 . V_27 = 1 ;
if ( V_2 -> V_158 . type == V_133 ) {
V_2 -> V_158 . V_79 . V_9 = F_48 ( V_2 ,
V_2 -> V_20 , true ) ;
F_52 ( & V_2 -> V_158 ) ;
}
goto V_403;
case V_418 :
V_2 -> V_158 . V_27 = 2 ;
goto V_403;
case V_419 :
V_2 -> V_158 . V_27 = 4 ;
goto V_403;
case V_420 :
V_95 = F_192 ( V_2 , V_115 , 2 , false ) ;
break;
case V_421 :
V_95 = F_192 ( V_2 , V_115 , F_191 ( V_2 ) , false ) ;
break;
case V_422 :
V_115 -> type = V_146 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_157 . V_88 =
F_14 ( V_2 , F_1 ( V_2 , V_151 ) ) ;
V_115 -> V_79 . V_157 . V_47 = V_2 -> V_423 ;
V_115 -> V_116 = 0 ;
V_115 -> V_175 = 1 ;
break;
case V_424 :
V_115 -> type = V_146 ;
V_115 -> V_27 = ( V_2 -> V_41 & V_134 ) ? 1 : V_2 -> V_66 ;
V_115 -> V_79 . V_157 . V_88 =
F_14 ( V_2 ,
F_1 ( V_2 , V_148 ) +
( F_1 ( V_2 , V_239 ) & 0xff ) ) ;
V_115 -> V_79 . V_157 . V_47 = V_2 -> V_423 ;
V_115 -> V_116 = 0 ;
break;
case V_425 :
V_115 -> type = V_354 ;
V_115 -> V_79 . V_157 . V_88 = V_2 -> V_67 ;
V_115 -> V_27 = V_2 -> V_66 + 2 ;
F_194 ( V_115 -> V_255 , V_115 -> V_27 , V_2 ) ;
break;
case V_426 :
V_2 -> V_158 . V_27 = V_2 -> V_66 + 2 ;
goto V_403;
case V_427 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_310 ;
break;
case V_428 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_100 ;
break;
case V_429 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_40 ;
break;
case V_430 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_144 ;
break;
case V_431 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_48 ;
break;
case V_432 :
V_115 -> type = V_354 ;
V_115 -> V_116 = V_199 ;
break;
case V_433 :
default:
V_115 -> type = V_211 ;
break;
}
V_159:
return V_95 ;
}
int F_195 ( struct V_1 * V_2 , void * V_434 , int V_435 )
{
int V_95 = V_68 ;
int V_37 = V_2 -> V_37 ;
int V_436 , V_437 , V_438 , V_439 ;
bool V_440 = false ;
bool V_441 = false ;
struct V_442 V_442 ;
V_2 -> V_158 . type = V_211 ;
V_2 -> V_404 = NULL ;
V_2 -> V_67 = V_2 -> V_31 ;
V_2 -> V_82 . V_103 = V_2 -> V_82 . V_94 ;
V_2 -> V_82 . V_99 = V_2 -> V_82 . V_94 + V_435 ;
V_2 -> V_443 = 1 ;
if ( V_435 > 0 )
memcpy ( V_2 -> V_82 . V_94 , V_434 , V_435 ) ;
else {
V_95 = F_44 ( V_2 , 1 ) ;
if ( V_95 != V_68 )
return V_95 ;
}
switch ( V_37 ) {
case V_91 :
case V_200 :
case V_228 :
V_436 = V_437 = 2 ;
break;
case V_227 :
V_436 = V_437 = 4 ;
break;
#ifdef F_31
case V_38 :
V_436 = 4 ;
V_437 = 8 ;
break;
#endif
default:
return V_344 ;
}
V_2 -> V_66 = V_436 ;
V_2 -> V_29 = V_437 ;
for (; ; ) {
switch ( V_2 -> V_125 = F_64 ( T_5 , V_2 ) ) {
case 0x66 :
V_440 = true ;
V_2 -> V_66 = V_436 ^ 6 ;
break;
case 0x67 :
if ( V_37 == V_38 )
V_2 -> V_29 = V_437 ^ 12 ;
else
V_2 -> V_29 = V_437 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
V_441 = true ;
V_2 -> V_423 = ( V_2 -> V_125 >> 3 ) & 3 ;
break;
case 0x64 :
case 0x65 :
V_441 = true ;
V_2 -> V_423 = V_2 -> V_125 & 7 ;
break;
case 0x40 ... 0x4f :
if ( V_37 != V_38 )
goto V_444;
V_2 -> V_107 = V_2 -> V_125 ;
continue;
case 0xf0 :
V_2 -> V_209 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_125 ;
break;
default:
goto V_444;
}
V_2 -> V_107 = 0 ;
}
V_444:
if ( V_2 -> V_107 & 8 )
V_2 -> V_66 = 8 ;
V_442 = V_445 [ V_2 -> V_125 ] ;
if ( V_2 -> V_125 == 0x0f ) {
V_2 -> V_443 = 2 ;
V_2 -> V_125 = F_64 ( T_5 , V_2 ) ;
V_442 = V_446 [ V_2 -> V_125 ] ;
if ( V_2 -> V_125 == 0x38 ) {
V_2 -> V_443 = 3 ;
V_2 -> V_125 = F_64 ( T_5 , V_2 ) ;
V_442 = V_447 [ V_2 -> V_125 ] ;
}
}
V_2 -> V_41 = V_442 . V_110 ;
if ( V_2 -> V_41 & V_124 )
V_2 -> V_143 = F_64 ( T_5 , V_2 ) ;
if ( V_2 -> V_443 == 1 && ( V_2 -> V_125 == 0xc5 || V_2 -> V_125 == 0xc4 ) &&
( V_37 == V_38 ||
( V_37 >= V_228 && ( V_2 -> V_143 & 0x80 ) ) ) ) {
V_2 -> V_41 = V_448 ;
}
while ( V_2 -> V_41 & V_449 ) {
switch ( V_2 -> V_41 & V_449 ) {
case V_450 :
V_438 = ( V_2 -> V_143 >> 3 ) & 7 ;
V_442 = V_442 . V_451 . V_452 [ V_438 ] ;
break;
case V_453 :
V_438 = ( V_2 -> V_143 >> 3 ) & 7 ;
if ( ( V_2 -> V_143 >> 6 ) == 3 )
V_442 = V_442 . V_451 . V_454 -> V_455 [ V_438 ] ;
else
V_442 = V_442 . V_451 . V_454 -> V_456 [ V_438 ] ;
break;
case V_457 :
V_438 = V_2 -> V_143 & 7 ;
V_442 = V_442 . V_451 . V_452 [ V_438 ] ;
break;
case V_458 :
if ( V_2 -> V_17 && V_440 )
return V_344 ;
V_439 = V_440 ? 0x66 : V_2 -> V_17 ;
switch ( V_439 ) {
case 0x00 : V_442 = V_442 . V_451 . V_459 -> V_460 ; break;
case 0x66 : V_442 = V_442 . V_451 . V_459 -> V_461 ; break;
case 0xf2 : V_442 = V_442 . V_451 . V_459 -> V_462 ; break;
case 0xf3 : V_442 = V_442 . V_451 . V_459 -> V_463 ; break;
}
break;
case V_464 :
if ( V_2 -> V_143 > 0xbf )
V_442 = V_442 . V_451 . V_465 -> V_466 [ V_2 -> V_143 - 0xc0 ] ;
else
V_442 = V_442 . V_451 . V_465 -> V_115 [ ( V_2 -> V_143 >> 3 ) & 7 ] ;
break;
default:
return V_344 ;
}
V_2 -> V_41 &= ~ ( V_89 ) V_449 ;
V_2 -> V_41 |= V_442 . V_110 ;
}
if ( V_2 -> V_41 == 0 )
return V_344 ;
V_2 -> V_467 = V_442 . V_451 . V_467 ;
if ( F_45 ( V_2 -> V_468 ) && F_39 ( ! ( V_2 -> V_41 & V_469 ) ) )
return V_344 ;
if ( F_45 ( V_2 -> V_41 &
( V_448 | V_470 | V_471 | V_126 | V_130 | V_472 | V_473 ) ) ) {
V_2 -> V_474 = V_442 . V_474 ;
V_2 -> V_12 = V_442 . V_12 ;
if ( V_2 -> V_41 & V_448 )
return V_344 ;
if ( V_37 == V_38 && ( V_2 -> V_41 & V_470 ) )
V_2 -> V_66 = 8 ;
if ( V_2 -> V_41 & V_471 ) {
if ( V_37 == V_38 )
V_2 -> V_66 = 8 ;
else
V_2 -> V_66 = 4 ;
}
if ( V_2 -> V_41 & V_126 )
V_2 -> V_66 = 16 ;
else if ( V_2 -> V_41 & V_130 )
V_2 -> V_66 = 8 ;
}
if ( V_2 -> V_41 & V_124 ) {
V_95 = F_63 ( V_2 , & V_2 -> V_158 ) ;
if ( ! V_441 ) {
V_441 = true ;
V_2 -> V_423 = V_2 -> V_138 ;
}
} else if ( V_2 -> V_41 & V_475 )
V_95 = F_65 ( V_2 , & V_2 -> V_158 ) ;
if ( V_95 != V_68 )
goto V_159;
if ( ! V_441 )
V_2 -> V_423 = V_144 ;
V_2 -> V_158 . V_79 . V_157 . V_47 = V_2 -> V_423 ;
V_95 = F_193 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_41 >> V_476 ) & V_477 ) ;
if ( V_95 != V_68 )
goto V_159;
V_95 = F_193 ( V_2 , & V_2 -> V_233 , ( V_2 -> V_41 >> V_478 ) & V_477 ) ;
if ( V_95 != V_68 )
goto V_159;
V_95 = F_193 ( V_2 , & V_2 -> V_25 , ( V_2 -> V_41 >> V_479 ) & V_477 ) ;
if ( V_2 -> V_156 )
V_2 -> V_404 -> V_79 . V_157 . V_88 += V_2 -> V_67 ;
V_159:
return ( V_95 != V_68 ) ? V_344 : V_345 ;
}
bool F_196 ( struct V_1 * V_2 )
{
return V_2 -> V_41 & V_480 ;
}
static bool F_197 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_125 == 0xa6 ) || ( V_2 -> V_125 == 0xa7 ) ||
( V_2 -> V_125 == 0xae ) || ( V_2 -> V_125 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_481 ) &&
( ( V_2 -> V_177 & V_220 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_482 ) &&
( ( V_2 -> V_177 & V_220 ) == V_220 ) ) ) )
return true ;
return false ;
}
static int F_198 ( struct V_1 * V_2 )
{
bool V_483 = false ;
V_2 -> V_6 -> V_117 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_6 -> V_118 ( V_2 ) ;
if ( F_45 ( V_483 ) )
return F_21 ( V_2 , V_484 , 0 , false ) ;
return V_68 ;
}
static void F_199 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
if ( V_115 -> type == V_131 )
F_56 ( V_2 , & V_115 -> V_210 , V_115 -> V_79 . V_132 ) ;
}
static int F_109 ( struct V_1 * V_2 , void (* F_51)( struct F_109 * ) )
{
T_1 V_110 = ( V_2 -> V_177 & V_112 ) | V_113 ;
if ( ! ( V_2 -> V_41 & V_134 ) )
F_51 += F_200 ( V_2 -> V_25 . V_27 ) * V_485 ;
asm("push %[flags]; popf; call *%[fastop]; pushf; pop %[flags]\n"
: "+a"(ctxt->dst.val), "+d"(ctxt->src.val), [flags]"+D"(flags),
[fastop]"+S"(fop)
: "c"(ctxt->src2.val));
V_2 -> V_177 = ( V_2 -> V_177 & ~ V_112 ) | ( V_110 & V_112 ) ;
if ( ! F_51 )
return F_28 ( V_2 ) ;
return V_68 ;
}
void F_201 ( struct V_1 * V_2 )
{
memset ( & V_2 -> V_156 , 0 ,
( void * ) & V_2 -> V_143 - ( void * ) & V_2 -> V_156 ) ;
V_2 -> V_172 . V_166 = 0 ;
V_2 -> V_172 . V_99 = 0 ;
V_2 -> V_165 . V_99 = 0 ;
}
int F_202 ( struct V_1 * V_2 )
{
const struct V_184 * V_6 = V_2 -> V_6 ;
int V_95 = V_68 ;
int V_486 = V_2 -> V_25 . type ;
V_2 -> V_165 . V_166 = 0 ;
if ( V_2 -> V_209 && ( ! ( V_2 -> V_41 & V_487 ) || V_2 -> V_25 . type != V_146 ) ) {
V_95 = F_26 ( V_2 ) ;
goto V_159;
}
if ( ( V_2 -> V_41 & V_488 ) == V_489 && V_2 -> V_22 . type != V_146 ) {
V_95 = F_26 ( V_2 ) ;
goto V_159;
}
if ( F_45 ( V_2 -> V_41 &
( V_490 | V_491 | V_126 | V_130 | V_472 | V_473 | V_492 | V_493 | String ) ) ) {
if ( ( V_2 -> V_37 == V_38 && ( V_2 -> V_41 & V_490 ) ) ||
( V_2 -> V_41 & V_491 ) ) {
V_95 = F_26 ( V_2 ) ;
goto V_159;
}
if ( ( ( V_2 -> V_41 & ( V_126 | V_130 ) ) && ( ( V_6 -> V_119 ( V_2 , 0 ) & V_121 ) ) )
|| ( ( V_2 -> V_41 & V_126 ) && ! ( V_6 -> V_119 ( V_2 , 4 ) & V_494 ) ) ) {
V_95 = F_26 ( V_2 ) ;
goto V_159;
}
if ( ( V_2 -> V_41 & ( V_126 | V_130 ) ) && ( V_6 -> V_119 ( V_2 , 0 ) & V_120 ) ) {
V_95 = F_29 ( V_2 ) ;
goto V_159;
}
if ( V_2 -> V_41 & V_130 ) {
V_95 = F_198 ( V_2 ) ;
if ( V_95 != V_68 )
goto V_159;
F_199 ( V_2 , & V_2 -> V_22 ) ;
F_199 ( V_2 , & V_2 -> V_233 ) ;
if ( ! ( V_2 -> V_41 & V_495 ) )
F_199 ( V_2 , & V_2 -> V_25 ) ;
}
if ( F_45 ( V_2 -> V_496 ) && ( V_2 -> V_41 & V_472 ) ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_497 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( ( V_2 -> V_41 & V_492 ) && V_6 -> V_87 ( V_2 ) ) {
if ( V_2 -> V_41 & V_498 )
V_95 = F_26 ( V_2 ) ;
else
V_95 = F_24 ( V_2 , 0 ) ;
goto V_159;
}
if ( ( V_2 -> V_41 & V_493 ) && V_2 -> V_37 < V_228 ) {
V_95 = F_26 ( V_2 ) ;
goto V_159;
}
if ( V_2 -> V_41 & V_473 ) {
V_95 = V_2 -> V_474 ( V_2 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( F_45 ( V_2 -> V_496 ) && ( V_2 -> V_41 & V_472 ) ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_499 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_176 ) ) == 0 ) {
V_2 -> V_31 = V_2 -> V_67 ;
V_2 -> V_177 &= ~ V_246 ;
goto V_159;
}
}
}
if ( ( V_2 -> V_22 . type == V_146 ) && ! ( V_2 -> V_41 & V_500 ) ) {
V_95 = F_68 ( V_2 , V_2 -> V_22 . V_79 . V_157 ,
V_2 -> V_22 . V_255 , V_2 -> V_22 . V_27 ) ;
if ( V_95 != V_68 )
goto V_159;
V_2 -> V_22 . V_258 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_233 . type == V_146 ) {
V_95 = F_68 ( V_2 , V_2 -> V_233 . V_79 . V_157 ,
& V_2 -> V_233 . V_116 , V_2 -> V_233 . V_27 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( ( V_2 -> V_41 & V_501 ) == V_502 )
goto V_503;
if ( ( V_2 -> V_25 . type == V_146 ) && ! ( V_2 -> V_41 & V_495 ) ) {
V_95 = F_68 ( V_2 , V_2 -> V_25 . V_79 . V_157 ,
& V_2 -> V_25 . V_116 , V_2 -> V_25 . V_27 ) ;
if ( V_95 != V_68 )
goto V_159;
}
V_2 -> V_25 . V_135 = V_2 -> V_25 . V_116 ;
V_503:
if ( F_45 ( V_2 -> V_496 ) && ( V_2 -> V_41 & V_472 ) ) {
V_95 = F_7 ( V_2 , V_2 -> V_12 ,
V_504 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) )
V_2 -> V_177 |= V_246 ;
else
V_2 -> V_177 &= ~ V_246 ;
if ( V_2 -> V_467 ) {
if ( V_2 -> V_41 & V_505 ) {
void (* F_51)( struct F_109 * ) = ( void * ) V_2 -> V_467 ;
V_95 = F_109 ( V_2 , F_51 ) ;
if ( V_95 != V_68 )
goto V_159;
goto F_83;
}
V_95 = V_2 -> V_467 ( V_2 ) ;
if ( V_95 != V_68 )
goto V_159;
goto F_83;
}
if ( V_2 -> V_443 == 2 )
goto V_506;
else if ( V_2 -> V_443 == 3 )
goto V_507;
switch ( V_2 -> V_125 ) {
case 0x63 :
if ( V_2 -> V_37 != V_38 )
goto V_508;
V_2 -> V_25 . V_116 = ( V_155 ) V_2 -> V_22 . V_116 ;
break;
case 0x70 ... 0x7f :
if ( F_50 ( V_2 -> V_125 , V_2 -> V_177 ) )
V_95 = F_35 ( V_2 , V_2 -> V_22 . V_116 ) ;
break;
case 0x8d :
V_2 -> V_25 . V_116 = V_2 -> V_22 . V_79 . V_157 . V_88 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_25 . V_79 . V_9 == F_3 ( V_2 , V_239 ) )
V_2 -> V_25 . type = V_211 ;
else
V_95 = F_136 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_66 ) {
case 2 : V_2 -> V_25 . V_116 = ( V_154 ) V_2 -> V_25 . V_116 ; break;
case 4 : V_2 -> V_25 . V_116 = ( V_161 ) V_2 -> V_25 . V_116 ; break;
case 8 : V_2 -> V_25 . V_116 = ( V_155 ) V_2 -> V_25 . V_116 ; break;
}
break;
case 0xcc :
V_95 = F_99 ( V_2 , 3 ) ;
break;
case 0xcd :
V_95 = F_99 ( V_2 , V_2 -> V_22 . V_116 ) ;
break;
case 0xce :
if ( V_2 -> V_177 & V_222 )
V_95 = F_99 ( V_2 , 4 ) ;
break;
case 0xe9 :
case 0xeb :
V_95 = F_35 ( V_2 , V_2 -> V_22 . V_116 ) ;
V_2 -> V_25 . type = V_211 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_509 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_177 ^= V_217 ;
break;
case 0xf8 :
V_2 -> V_177 &= ~ V_217 ;
break;
case 0xf9 :
V_2 -> V_177 |= V_217 ;
break;
case 0xfc :
V_2 -> V_177 &= ~ V_178 ;
break;
case 0xfd :
V_2 -> V_177 |= V_178 ;
break;
default:
goto V_508;
}
if ( V_95 != V_68 )
goto V_159;
F_83:
if ( V_2 -> V_41 & V_510 ) {
F_203 ( V_2 -> V_22 . type == V_146 || V_2 -> V_22 . type == V_179 ) ;
V_95 = F_83 ( V_2 , & V_2 -> V_22 ) ;
if ( V_95 != V_68 )
goto V_159;
}
if ( ! ( V_2 -> V_41 & V_511 ) ) {
V_95 = F_83 ( V_2 , & V_2 -> V_25 ) ;
if ( V_95 != V_68 )
goto V_159;
}
V_2 -> V_25 . type = V_486 ;
if ( ( V_2 -> V_41 & V_488 ) == V_512 )
F_129 ( V_2 , V_151 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_41 & V_501 ) == V_513 )
F_129 ( V_2 , V_153 , & V_2 -> V_25 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_41 & String ) ) {
unsigned int V_175 ;
struct V_163 * V_294 = & V_2 -> V_172 ;
if ( ( V_2 -> V_41 & V_488 ) == V_512 )
V_175 = V_2 -> V_22 . V_175 ;
else
V_175 = V_2 -> V_25 . V_175 ;
F_16 ( V_2 , F_3 ( V_2 , V_176 ) ,
- V_175 ) ;
if ( ! F_197 ( V_2 ) ) {
if ( ( V_294 -> V_99 != 0 || F_1 ( V_2 , V_176 ) & 0x3ff ) &&
( V_294 -> V_99 == 0 || V_294 -> V_99 != V_294 -> V_166 ) ) {
V_2 -> V_165 . V_99 = 0 ;
F_4 ( V_2 ) ;
return V_514 ;
}
goto V_159;
}
V_2 -> V_177 &= ~ V_246 ;
}
V_2 -> V_31 = V_2 -> V_67 ;
V_159:
if ( V_95 == V_56 ) {
F_22 ( V_2 -> V_52 . V_53 > 0x1f ) ;
V_2 -> V_515 = true ;
}
if ( V_95 == V_516 )
return V_517 ;
if ( V_95 == V_68 )
F_4 ( V_2 ) ;
return ( V_95 == V_235 ) ? V_344 : V_345 ;
V_506:
switch ( V_2 -> V_125 ) {
case 0x09 :
( V_2 -> V_6 -> V_518 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
case 0x1f :
break;
case 0x20 :
V_2 -> V_25 . V_116 = V_6 -> V_119 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_391 ( V_2 , V_2 -> V_19 , & V_2 -> V_25 . V_116 ) ;
break;
case 0x40 ... 0x4f :
if ( F_50 ( V_2 -> V_125 , V_2 -> V_177 ) )
V_2 -> V_25 . V_116 = V_2 -> V_22 . V_116 ;
else if ( V_2 -> V_37 != V_38 ||
V_2 -> V_66 != 4 )
V_2 -> V_25 . type = V_211 ;
break;
case 0x80 ... 0x8f :
if ( F_50 ( V_2 -> V_125 , V_2 -> V_177 ) )
V_95 = F_35 ( V_2 , V_2 -> V_22 . V_116 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_25 . V_116 = F_50 ( V_2 -> V_125 , V_2 -> V_177 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_25 . V_27 = V_2 -> V_66 ;
V_2 -> V_25 . V_116 = ( V_2 -> V_22 . V_27 == 1 ) ? ( T_5 ) V_2 -> V_22 . V_116
: ( T_2 ) V_2 -> V_22 . V_116 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_25 . V_27 = V_2 -> V_66 ;
V_2 -> V_25 . V_116 = ( V_2 -> V_22 . V_27 == 1 ) ? ( V_154 ) V_2 -> V_22 . V_116 :
( V_161 ) V_2 -> V_22 . V_116 ;
break;
case 0xc3 :
V_2 -> V_25 . V_27 = V_2 -> V_66 ;
V_2 -> V_25 . V_116 = ( V_2 -> V_66 == 8 ) ? ( V_89 ) V_2 -> V_22 . V_116 :
( T_3 ) V_2 -> V_22 . V_116 ;
break;
default:
goto V_508;
}
V_507:
if ( V_95 != V_68 )
goto V_159;
goto F_83;
V_508:
return V_344 ;
}
void F_204 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_205 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
