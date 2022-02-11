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
unsigned V_84 , V_85 ;
V_82 = F_22 ( V_2 , V_77 . V_48 ) + V_77 . V_86 ;
switch ( V_2 -> V_36 ) {
case V_37 :
if ( ( ( signed long ) V_82 << 16 ) >> 16 != V_82 )
return F_25 ( V_2 , 0 ) ;
break;
default:
V_81 = V_2 -> V_6 -> V_38 ( V_2 , & V_33 , & V_45 , NULL ,
V_77 . V_48 ) ;
if ( ! V_81 )
goto V_87;
if ( ( ( V_45 . type & 8 ) || ! ( V_45 . type & 2 ) ) && V_78 )
goto V_87;
if ( ! V_79 && ( V_45 . type & 8 ) && ! ( V_45 . type & 2 ) )
goto V_87;
V_83 = F_19 ( & V_45 ) ;
if ( ( V_45 . type & 8 ) || ! ( V_45 . type & 4 ) ) {
if ( V_77 . V_86 > V_83 || ( T_3 ) ( V_77 . V_86 + V_72 - 1 ) > V_83 )
goto V_87;
} else {
if ( V_77 . V_86 <= V_83 || ( T_3 ) ( V_77 . V_86 + V_72 - 1 ) <= V_83 )
goto V_87;
V_83 = V_45 . V_40 ? 0xffffffff : 0xffff ;
if ( V_77 . V_86 > V_83 || ( T_3 ) ( V_77 . V_86 + V_72 - 1 ) > V_83 )
goto V_87;
}
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( V_2 -> V_36 == V_88 )
V_85 = 0 ;
else
V_85 = V_33 & 3 ;
V_84 = F_36 ( V_84 , V_85 ) ;
if ( ! ( V_45 . type & 8 ) ) {
if ( V_84 > V_45 . V_89 )
goto V_87;
} else if ( ( V_45 . type & 8 ) && ! ( V_45 . type & 4 ) ) {
if ( V_84 != V_45 . V_89 )
goto V_87;
} else if ( ( V_45 . type & 8 ) && ( V_45 . type & 4 ) ) {
if ( V_84 < V_45 . V_89 )
goto V_87;
}
break;
}
if ( V_79 ? V_2 -> V_36 != V_37 : V_2 -> V_28 != 8 )
V_82 &= ( T_3 ) - 1 ;
if ( F_33 ( V_2 , V_72 ) && ( ( V_82 & ( V_72 - 1 ) ) != 0 ) )
return F_25 ( V_2 , 0 ) ;
* V_80 = V_82 ;
return V_90 ;
V_87:
if ( V_77 . V_48 == V_39 )
return F_26 ( V_2 , V_33 ) ;
else
return F_25 ( V_2 , V_33 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
unsigned V_72 , bool V_78 ,
T_1 * V_80 )
{
return F_35 ( V_2 , V_77 , V_72 , V_78 , false , V_80 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
void * V_91 ,
unsigned V_72 )
{
int V_92 ;
T_1 V_80 ;
V_92 = F_37 ( V_2 , V_77 , V_72 , false , & V_80 ) ;
if ( V_92 != V_90 )
return V_92 ;
return V_2 -> V_6 -> V_93 ( V_2 , V_80 , V_91 , V_72 , & V_2 -> V_55 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_4 * V_31 )
{
struct V_94 * V_95 = & V_2 -> V_79 ;
int V_92 ;
int V_72 , V_96 ;
if ( V_2 -> V_44 == V_95 -> V_97 ) {
unsigned long V_80 ;
struct V_76 V_77 = { . V_48 = V_98 ,
. V_86 = V_2 -> V_44 } ;
V_96 = V_95 -> V_97 - V_95 -> V_99 ;
V_72 = F_40 ( 15UL - V_96 ,
V_100 - F_41 ( V_2 -> V_44 ) ) ;
V_92 = F_35 ( V_2 , V_77 , V_72 , false , true , & V_80 ) ;
if ( F_42 ( V_92 != V_90 ) )
return V_92 ;
V_92 = V_2 -> V_6 -> V_79 ( V_2 , V_80 , V_95 -> V_91 + V_96 ,
V_72 , & V_2 -> V_55 ) ;
if ( F_42 ( V_92 != V_90 ) )
return V_92 ;
V_95 -> V_97 += V_72 ;
}
* V_31 = V_95 -> V_91 [ V_2 -> V_44 - V_95 -> V_99 ] ;
V_2 -> V_44 ++ ;
return V_90 ;
}
static int F_43 ( struct V_1 * V_2 ,
void * V_31 , unsigned V_72 )
{
int V_92 ;
if ( F_42 ( V_2 -> V_44 + V_72 - V_2 -> V_30 > 15 ) )
return V_101 ;
while ( V_72 -- ) {
V_92 = F_39 ( V_2 , V_31 ++ ) ;
if ( V_92 != V_90 )
return V_92 ;
}
return V_90 ;
}
static void * F_44 ( struct V_1 * V_2 , T_4 V_19 ,
int V_102 )
{
void * V_103 ;
if ( V_102 && V_19 >= 4 && V_19 < 8 )
V_103 = ( unsigned char * ) F_3 ( V_2 , V_19 & 3 ) + 1 ;
else
V_103 = F_3 ( V_2 , V_19 ) ;
return V_103 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
T_2 * V_72 , unsigned long * V_104 , int V_105 )
{
int V_92 ;
if ( V_105 == 2 )
V_105 = 3 ;
* V_104 = 0 ;
V_92 = F_38 ( V_2 , V_77 , V_72 , 2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_77 . V_86 += 2 ;
V_92 = F_38 ( V_2 , V_77 , V_104 , V_105 ) ;
return V_92 ;
}
static int F_46 ( unsigned int V_106 , unsigned int V_107 )
{
int V_92 = 0 ;
switch ( ( V_106 & 15 ) >> 1 ) {
case 0 :
V_92 |= ( V_107 & V_108 ) ;
break;
case 1 :
V_92 |= ( V_107 & V_109 ) ;
break;
case 2 :
V_92 |= ( V_107 & V_110 ) ;
break;
case 3 :
V_92 |= ( V_107 & ( V_109 | V_110 ) ) ;
break;
case 4 :
V_92 |= ( V_107 & V_111 ) ;
break;
case 5 :
V_92 |= ( V_107 & V_112 ) ;
break;
case 7 :
V_92 |= ( V_107 & V_110 ) ;
case 6 :
V_92 |= ( ! ( V_107 & V_111 ) != ! ( V_107 & V_108 ) ) ;
break;
}
return ( ! ! V_92 ^ ( V_106 & 1 ) ) ;
}
static void F_47 ( struct V_113 * V_114 )
{
switch ( V_114 -> V_25 ) {
case 1 :
V_114 -> V_115 = * ( T_4 * ) V_114 -> V_77 . V_9 ;
break;
case 2 :
V_114 -> V_115 = * ( T_2 * ) V_114 -> V_77 . V_9 ;
break;
case 4 :
V_114 -> V_115 = * ( T_3 * ) V_114 -> V_77 . V_9 ;
break;
case 8 :
V_114 -> V_115 = * ( V_116 * ) V_114 -> V_77 . V_9 ;
break;
}
}
static void F_48 ( struct V_1 * V_2 , T_5 * V_91 , int V_9 )
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 , T_5 * V_91 ,
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
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , V_116 * V_91 , int V_9 )
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
default: F_50 () ;
}
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 , V_116 * V_91 , int V_9 )
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
default: F_50 () ;
}
V_2 -> V_6 -> V_118 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
unsigned V_9 = V_2 -> V_19 ;
int V_102 = V_2 -> V_119 == 0 ;
if ( ! ( V_2 -> V_40 & V_120 ) )
V_9 = ( V_2 -> V_121 & 7 ) | ( ( V_2 -> V_119 & 1 ) << 3 ) ;
if ( V_2 -> V_40 & V_122 ) {
V_114 -> type = V_123 ;
V_114 -> V_25 = 16 ;
V_114 -> V_77 . V_124 = V_9 ;
F_48 ( V_2 , & V_114 -> V_125 , V_9 ) ;
return;
}
if ( V_2 -> V_40 & V_126 ) {
V_9 &= 7 ;
V_114 -> type = V_127 ;
V_114 -> V_25 = 8 ;
V_114 -> V_77 . V_128 = V_9 ;
return;
}
V_114 -> type = V_129 ;
if ( V_2 -> V_40 & V_130 ) {
V_114 -> V_77 . V_9 = F_44 ( V_2 , V_9 , V_102 ) ;
V_114 -> V_25 = 1 ;
} else {
V_114 -> V_77 . V_9 = F_44 ( V_2 , V_9 , 0 ) ;
V_114 -> V_25 = V_2 -> V_105 ;
}
F_47 ( V_114 ) ;
V_114 -> V_131 = V_114 -> V_115 ;
}
static void F_55 ( struct V_1 * V_2 , int V_132 )
{
if ( V_132 == V_42 || V_132 == V_133 )
V_2 -> V_134 = V_39 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
T_4 V_135 ;
int V_136 = 0 , V_132 = 0 , V_137 ;
int V_92 = V_90 ;
T_1 V_138 = 0 ;
if ( V_2 -> V_119 ) {
V_2 -> V_19 = ( V_2 -> V_119 & 4 ) << 1 ;
V_136 = ( V_2 -> V_119 & 2 ) << 2 ;
V_2 -> V_20 = V_132 = ( V_2 -> V_119 & 1 ) << 3 ;
}
V_2 -> V_18 |= ( V_2 -> V_139 & 0xc0 ) >> 6 ;
V_2 -> V_19 |= ( V_2 -> V_139 & 0x38 ) >> 3 ;
V_2 -> V_20 |= ( V_2 -> V_139 & 0x07 ) ;
V_2 -> V_134 = V_140 ;
if ( V_2 -> V_18 == 3 ) {
V_114 -> type = V_129 ;
V_114 -> V_25 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
V_114 -> V_77 . V_9 = F_44 ( V_2 , V_2 -> V_20 , V_2 -> V_40 & V_130 ) ;
if ( V_2 -> V_40 & V_122 ) {
V_114 -> type = V_123 ;
V_114 -> V_25 = 16 ;
V_114 -> V_77 . V_124 = V_2 -> V_20 ;
F_48 ( V_2 , & V_114 -> V_125 , V_2 -> V_20 ) ;
return V_92 ;
}
if ( V_2 -> V_40 & V_126 ) {
V_114 -> type = V_127 ;
V_114 -> V_25 = 8 ;
V_114 -> V_77 . V_124 = V_2 -> V_20 & 7 ;
return V_92 ;
}
F_47 ( V_114 ) ;
return V_92 ;
}
V_114 -> type = V_141 ;
if ( V_2 -> V_28 == 2 ) {
unsigned V_142 = F_1 ( V_2 , V_143 ) ;
unsigned V_144 = F_1 ( V_2 , V_133 ) ;
unsigned V_145 = F_1 ( V_2 , V_146 ) ;
unsigned V_147 = F_1 ( V_2 , V_148 ) ;
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 6 )
V_138 += F_57 ( T_2 , V_2 ) ;
break;
case 1 :
V_138 += F_57 ( V_149 , V_2 ) ;
break;
case 2 :
V_138 += F_57 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_20 ) {
case 0 :
V_138 += V_142 + V_145 ;
break;
case 1 :
V_138 += V_142 + V_147 ;
break;
case 2 :
V_138 += V_144 + V_145 ;
break;
case 3 :
V_138 += V_144 + V_147 ;
break;
case 4 :
V_138 += V_145 ;
break;
case 5 :
V_138 += V_147 ;
break;
case 6 :
if ( V_2 -> V_18 != 0 )
V_138 += V_144 ;
break;
case 7 :
V_138 += V_142 ;
break;
}
if ( V_2 -> V_20 == 2 || V_2 -> V_20 == 3 ||
( V_2 -> V_20 == 6 && V_2 -> V_18 != 0 ) )
V_2 -> V_134 = V_39 ;
V_138 = ( T_2 ) V_138 ;
} else {
if ( ( V_2 -> V_20 & 7 ) == 4 ) {
V_135 = F_57 ( T_4 , V_2 ) ;
V_136 |= ( V_135 >> 3 ) & 7 ;
V_132 |= V_135 & 7 ;
V_137 = V_135 >> 6 ;
if ( ( V_132 & 7 ) == 5 && V_2 -> V_18 == 0 )
V_138 += F_57 ( V_150 , V_2 ) ;
else {
V_138 += F_1 ( V_2 , V_132 ) ;
F_55 ( V_2 , V_132 ) ;
}
if ( V_136 != 4 )
V_138 += F_1 ( V_2 , V_136 ) << V_137 ;
} else if ( ( V_2 -> V_20 & 7 ) == 5 && V_2 -> V_18 == 0 ) {
if ( V_2 -> V_36 == V_37 )
V_2 -> V_151 = 1 ;
} else {
V_132 = V_2 -> V_20 ;
V_138 += F_1 ( V_2 , V_132 ) ;
F_55 ( V_2 , V_132 ) ;
}
switch ( V_2 -> V_18 ) {
case 0 :
if ( V_2 -> V_20 == 5 )
V_138 += F_57 ( V_150 , V_2 ) ;
break;
case 1 :
V_138 += F_57 ( V_149 , V_2 ) ;
break;
case 2 :
V_138 += F_57 ( V_150 , V_2 ) ;
break;
}
}
V_114 -> V_77 . V_152 . V_86 = V_138 ;
V_153:
return V_92 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
int V_92 = V_90 ;
V_114 -> type = V_141 ;
switch ( V_2 -> V_28 ) {
case 2 :
V_114 -> V_77 . V_152 . V_86 = F_57 ( T_2 , V_2 ) ;
break;
case 4 :
V_114 -> V_77 . V_152 . V_86 = F_57 ( T_3 , V_2 ) ;
break;
case 8 :
V_114 -> V_77 . V_152 . V_86 = F_57 ( V_116 , V_2 ) ;
break;
}
V_153:
return V_92 ;
}
static void F_59 ( struct V_1 * V_2 )
{
long V_154 = 0 , V_32 ;
if ( V_2 -> V_27 . type == V_141 && V_2 -> V_22 . type == V_129 ) {
V_32 = ~ ( V_2 -> V_27 . V_25 * 8 - 1 ) ;
if ( V_2 -> V_22 . V_25 == 2 )
V_154 = ( V_155 ) V_2 -> V_22 . V_115 & ( V_155 ) V_32 ;
else if ( V_2 -> V_22 . V_25 == 4 )
V_154 = ( V_150 ) V_2 -> V_22 . V_115 & ( V_150 ) V_32 ;
V_2 -> V_27 . V_77 . V_152 . V_86 += ( V_154 >> 3 ) ;
}
V_2 -> V_22 . V_115 &= ( V_2 -> V_27 . V_25 << 3 ) - 1 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned long V_77 , void * V_31 , unsigned V_72 )
{
int V_92 ;
struct V_156 * V_157 = & V_2 -> V_158 ;
if ( V_157 -> V_159 < V_157 -> V_97 )
goto V_160;
F_61 ( ( V_157 -> V_97 + V_72 ) >= sizeof( V_157 -> V_91 ) ) ;
V_92 = V_2 -> V_6 -> F_60 ( V_2 , V_77 , V_157 -> V_91 + V_157 -> V_97 , V_72 ,
& V_2 -> V_55 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_157 -> V_97 += V_72 ;
V_160:
memcpy ( V_31 , V_157 -> V_91 + V_157 -> V_159 , V_72 ) ;
V_157 -> V_159 += V_72 ;
return V_90 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
void * V_91 ,
unsigned V_72 )
{
int V_92 ;
T_1 V_80 ;
V_92 = F_37 ( V_2 , V_77 , V_72 , false , & V_80 ) ;
if ( V_92 != V_90 )
return V_92 ;
return F_60 ( V_2 , V_80 , V_91 , V_72 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
const void * V_91 ,
unsigned V_72 )
{
int V_92 ;
T_1 V_80 ;
V_92 = F_37 ( V_2 , V_77 , V_72 , true , & V_80 ) ;
if ( V_92 != V_90 )
return V_92 ;
return V_2 -> V_6 -> V_161 ( V_2 , V_80 , V_91 , V_72 ,
& V_2 -> V_55 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_76 V_77 ,
const void * V_162 , const void * V_91 ,
unsigned V_72 )
{
int V_92 ;
T_1 V_80 ;
V_92 = F_37 ( V_2 , V_77 , V_72 , true , & V_80 ) ;
if ( V_92 != V_90 )
return V_92 ;
return V_2 -> V_6 -> V_163 ( V_2 , V_80 , V_162 , V_91 ,
V_72 , & V_2 -> V_55 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
unsigned int V_72 , unsigned short V_164 ,
void * V_31 )
{
struct V_156 * V_92 = & V_2 -> V_165 ;
if ( V_92 -> V_159 == V_92 -> V_97 ) {
unsigned int V_166 , V_167 ;
unsigned int V_168 = V_2 -> V_17 ?
F_13 ( V_2 , F_1 ( V_2 , V_169 ) ) : 1 ;
V_166 = ( V_2 -> V_170 & V_171 ) ?
F_41 ( F_1 ( V_2 , V_148 ) ) :
V_100 - F_41 ( F_1 ( V_2 , V_148 ) ) ;
V_167 = F_40 ( F_40 ( V_166 , ( unsigned int ) sizeof( V_92 -> V_91 ) ) / V_72 ,
V_168 ) ;
if ( V_167 == 0 )
V_167 = 1 ;
V_92 -> V_159 = V_92 -> V_97 = 0 ;
if ( ! V_2 -> V_6 -> F_65 ( V_2 , V_72 , V_164 , V_92 -> V_91 , V_167 ) )
return 0 ;
V_92 -> V_97 = V_167 * V_72 ;
}
if ( V_2 -> V_17 && ! ( V_2 -> V_170 & V_171 ) ) {
V_2 -> V_27 . V_91 = V_92 -> V_91 + V_92 -> V_159 ;
V_2 -> V_27 . type = V_172 ;
V_2 -> V_27 . V_168 = ( V_92 -> V_97 - V_92 -> V_159 ) / V_72 ;
V_92 -> V_159 = V_92 -> V_97 ;
} else {
memcpy ( V_31 , V_92 -> V_91 + V_92 -> V_159 , V_72 ) ;
V_92 -> V_159 += V_72 ;
}
return 1 ;
}
static int F_66 ( struct V_1 * V_2 ,
T_2 V_173 , struct V_34 * V_45 )
{
struct V_174 V_175 ;
T_1 V_77 ;
V_2 -> V_6 -> V_176 ( V_2 , & V_175 ) ;
if ( V_175 . V_72 < V_173 * 8 + 7 )
return F_25 ( V_2 , V_173 << 3 | 0x2 ) ;
V_77 = V_175 . V_104 + V_173 * 8 ;
return V_2 -> V_6 -> V_93 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_174 * V_175 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
if ( V_68 & 1 << 2 ) {
struct V_34 V_45 ;
T_2 V_33 ;
memset ( V_175 , 0 , sizeof *V_175 ) ;
if ( ! V_6 -> V_38 ( V_2 , & V_33 , & V_45 , NULL , V_178 ) )
return;
V_175 -> V_72 = F_19 ( & V_45 ) ;
V_175 -> V_104 = F_68 ( & V_45 ) ;
} else
V_6 -> V_179 ( V_2 , V_175 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 ,
T_1 * V_180 )
{
struct V_174 V_175 ;
T_2 V_173 = V_68 >> 3 ;
T_1 V_77 ;
F_67 ( V_2 , V_68 , & V_175 ) ;
if ( V_175 . V_72 < V_173 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
* V_180 = V_77 = V_175 . V_104 + V_173 * 8 ;
return V_2 -> V_6 -> V_93 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
T_2 V_68 , struct V_34 * V_45 )
{
struct V_174 V_175 ;
T_2 V_173 = V_68 >> 3 ;
T_1 V_77 ;
F_67 ( V_2 , V_68 , & V_175 ) ;
if ( V_175 . V_72 < V_173 * 8 + 7 )
return F_25 ( V_2 , V_68 & 0xfffc ) ;
V_77 = V_175 . V_104 + V_173 * 8 ;
return V_2 -> V_6 -> V_181 ( V_2 , V_77 , V_45 , sizeof *V_45 ,
& V_2 -> V_55 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
T_2 V_68 , int V_48 )
{
struct V_34 V_182 , V_183 ;
T_4 V_89 , V_85 , V_84 ;
unsigned V_184 = V_62 ;
T_3 V_185 = 0 ;
bool V_186 = ! ( V_68 & ~ 0x3 ) ;
T_1 V_187 ;
int V_188 ;
T_2 V_69 ;
memset ( & V_182 , 0 , sizeof V_182 ) ;
if ( ( V_48 <= V_189 && V_2 -> V_36 == V_190 )
|| V_2 -> V_36 == V_88 ) {
V_2 -> V_6 -> V_38 ( V_2 , & V_69 , & V_182 , NULL , V_48 ) ;
F_72 ( & V_182 , V_68 << 4 ) ;
goto V_191;
}
V_85 = V_68 & 3 ;
V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
if ( ( V_48 == V_98
|| ( V_48 == V_39
&& ( V_2 -> V_36 != V_37 || V_85 != V_84 ) )
|| V_48 == V_192 )
&& V_186 )
goto V_55;
if ( V_48 == V_192 && ( V_68 & ( 1 << 2 ) ) )
goto V_55;
if ( V_186 )
goto V_191;
V_188 = F_69 ( V_2 , V_68 , & V_182 , & V_187 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_185 = V_68 & 0xfffc ;
V_184 = V_62 ;
if ( V_48 <= V_189 && ! V_182 . V_193 )
goto V_55;
if ( ! V_182 . V_103 ) {
V_184 = ( V_48 == V_39 ) ? V_63 : V_194 ;
goto V_55;
}
V_89 = V_182 . V_89 ;
switch ( V_48 ) {
case V_39 :
if ( V_85 != V_84 || ( V_182 . type & 0xa ) != 0x2 || V_89 != V_84 )
goto V_55;
break;
case V_98 :
if ( ! ( V_182 . type & 8 ) )
goto V_55;
if ( V_182 . type & 4 ) {
if ( V_89 > V_84 )
goto V_55;
} else {
if ( V_85 > V_84 || V_89 != V_84 )
goto V_55;
}
V_68 = ( V_68 & 0xfffc ) | V_84 ;
break;
case V_192 :
if ( V_182 . V_193 || ( V_182 . type != 1 && V_182 . type != 9 ) )
goto V_55;
V_183 = V_182 ;
V_182 . type |= 2 ;
V_188 = V_2 -> V_6 -> V_163 ( V_2 , V_187 , & V_183 , & V_182 ,
sizeof( V_182 ) , & V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
break;
case V_178 :
if ( V_182 . V_193 || V_182 . type != 2 )
goto V_55;
break;
default:
if ( ( V_182 . type & 0xa ) == 0x8 ||
( ( ( V_182 . type & 0xc ) != 0xc ) &&
( V_85 > V_89 && V_84 > V_89 ) ) )
goto V_55;
break;
}
if ( V_182 . V_193 ) {
V_182 . type |= 1 ;
V_188 = F_70 ( V_2 , V_68 , & V_182 ) ;
if ( V_188 != V_90 )
return V_188 ;
}
V_191:
V_2 -> V_6 -> V_71 ( V_2 , V_68 , & V_182 , 0 , V_48 ) ;
return V_90 ;
V_55:
F_23 ( V_2 , V_184 , V_185 , true ) ;
return V_59 ;
}
static void F_73 ( struct V_113 * V_114 )
{
switch ( V_114 -> V_25 ) {
case 1 :
* ( T_4 * ) V_114 -> V_77 . V_9 = ( T_4 ) V_114 -> V_115 ;
break;
case 2 :
* ( T_2 * ) V_114 -> V_77 . V_9 = ( T_2 ) V_114 -> V_115 ;
break;
case 4 :
* V_114 -> V_77 . V_9 = ( T_3 ) V_114 -> V_115 ;
break;
case 8 :
* V_114 -> V_77 . V_9 = V_114 -> V_115 ;
break;
}
}
static int F_74 ( struct V_1 * V_2 )
{
int V_92 ;
switch ( V_2 -> V_27 . type ) {
case V_129 :
F_73 ( & V_2 -> V_27 ) ;
break;
case V_141 :
if ( V_2 -> V_195 )
V_92 = F_64 ( V_2 ,
V_2 -> V_27 . V_77 . V_152 ,
& V_2 -> V_27 . V_131 ,
& V_2 -> V_27 . V_115 ,
V_2 -> V_27 . V_25 ) ;
else
V_92 = F_63 ( V_2 ,
V_2 -> V_27 . V_77 . V_152 ,
& V_2 -> V_27 . V_115 ,
V_2 -> V_27 . V_25 ) ;
if ( V_92 != V_90 )
return V_92 ;
break;
case V_172 :
V_92 = F_63 ( V_2 ,
V_2 -> V_27 . V_77 . V_152 ,
V_2 -> V_27 . V_91 ,
V_2 -> V_27 . V_25 * V_2 -> V_27 . V_168 ) ;
if ( V_92 != V_90 )
return V_92 ;
break;
case V_123 :
F_51 ( V_2 , & V_2 -> V_27 . V_125 , V_2 -> V_27 . V_77 . V_124 ) ;
break;
case V_127 :
F_53 ( V_2 , & V_2 -> V_27 . V_196 , V_2 -> V_27 . V_77 . V_128 ) ;
break;
case V_197 :
break;
default:
break;
}
return V_90 ;
}
static int F_75 ( struct V_1 * V_2 , void * V_91 , int V_25 )
{
struct V_76 V_77 ;
F_17 ( V_2 , - V_25 ) ;
V_77 . V_86 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
return F_63 ( V_2 , V_77 , V_91 , V_25 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_197 ;
return F_75 ( V_2 , & V_2 -> V_22 . V_115 , V_2 -> V_105 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
void * V_31 , int V_198 )
{
int V_92 ;
struct V_76 V_77 ;
V_77 . V_86 = F_1 ( V_2 , V_42 ) & F_10 ( V_2 ) ;
V_77 . V_48 = V_39 ;
V_92 = F_62 ( V_2 , V_77 , V_31 , V_198 ) ;
if ( V_92 != V_90 )
return V_92 ;
F_17 ( V_2 , V_198 ) ;
return V_92 ;
}
static int F_78 ( struct V_1 * V_2 )
{
return F_77 ( V_2 , & V_2 -> V_27 . V_115 , V_2 -> V_105 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
void * V_31 , int V_198 )
{
int V_92 ;
unsigned long V_115 , V_199 ;
int V_200 = ( V_2 -> V_170 & V_201 ) >> V_202 ;
int V_84 = V_2 -> V_6 -> V_84 ( V_2 ) ;
V_92 = F_77 ( V_2 , & V_115 , V_198 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_199 = V_109 | V_112 | V_203 | V_110 | V_111 | V_108
| V_204 | V_171 | V_205 | V_206 | V_207 | V_208 ;
switch( V_2 -> V_36 ) {
case V_37 :
case V_209 :
case V_210 :
if ( V_84 == 0 )
V_199 |= V_211 ;
if ( V_84 <= V_200 )
V_199 |= V_212 ;
break;
case V_190 :
if ( V_200 < 3 )
return F_25 ( V_2 , 0 ) ;
V_199 |= V_212 ;
break;
default:
V_199 |= ( V_211 | V_212 ) ;
break;
}
* ( unsigned long * ) V_31 =
( V_2 -> V_170 & ~ V_199 ) | ( V_115 & V_199 ) ;
return V_92 ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_129 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_170 ;
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
return F_79 ( V_2 , & V_2 -> V_27 . V_115 , V_2 -> V_105 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned V_213 = V_2 -> V_22 . V_115 ;
unsigned V_214 = V_2 -> V_215 . V_115 & 31 ;
T_1 V_216 ;
if ( V_214 )
return V_101 ;
V_216 = F_1 ( V_2 , V_133 ) ;
V_92 = F_75 ( V_2 , & V_216 , F_11 ( V_2 ) ) ;
if ( V_92 != V_90 )
return V_92 ;
F_8 ( F_3 ( V_2 , V_133 ) , F_1 ( V_2 , V_42 ) ,
F_10 ( V_2 ) ) ;
F_8 ( F_3 ( V_2 , V_42 ) ,
F_1 ( V_2 , V_42 ) - V_213 ,
F_10 ( V_2 ) ) ;
return V_90 ;
}
static int F_82 ( struct V_1 * V_2 )
{
F_8 ( F_3 ( V_2 , V_42 ) , F_1 ( V_2 , V_133 ) ,
F_10 ( V_2 ) ) ;
return F_77 ( V_2 , F_3 ( V_2 , V_133 ) , V_2 -> V_105 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_215 . V_115 ;
V_2 -> V_22 . V_115 = F_31 ( V_2 , V_48 ) ;
return F_76 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_215 . V_115 ;
unsigned long V_68 ;
int V_92 ;
V_92 = F_77 ( V_2 , & V_68 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = F_71 ( V_2 , ( T_2 ) V_68 , V_48 ) ;
return V_92 ;
}
static int F_85 ( struct V_1 * V_2 )
{
unsigned long V_217 = F_1 ( V_2 , V_42 ) ;
int V_92 = V_90 ;
int V_9 = V_218 ;
while ( V_9 <= V_148 ) {
( V_9 == V_42 ) ?
( V_2 -> V_22 . V_115 = V_217 ) : ( V_2 -> V_22 . V_115 = F_1 ( V_2 , V_9 ) ) ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
++ V_9 ;
}
return V_92 ;
}
static int F_86 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_115 = ( unsigned long ) V_2 -> V_170 ;
return F_76 ( V_2 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_92 = V_90 ;
int V_9 = V_148 ;
while ( V_9 >= V_218 ) {
if ( V_9 == V_42 ) {
F_17 ( V_2 , V_2 -> V_105 ) ;
-- V_9 ;
}
V_92 = F_77 ( V_2 , F_3 ( V_2 , V_9 ) , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
break;
-- V_9 ;
}
return V_92 ;
}
static int F_88 ( struct V_1 * V_2 , int V_219 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
int V_92 ;
struct V_174 V_175 ;
T_6 V_220 ;
T_6 V_221 ;
T_2 V_222 , V_30 ;
V_2 -> V_22 . V_115 = V_2 -> V_170 ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_170 &= ~ ( V_212 | V_204 | V_207 ) ;
V_2 -> V_22 . V_115 = F_31 ( V_2 , V_98 ) ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_22 . V_115 = V_2 -> V_44 ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_6 -> V_176 ( V_2 , & V_175 ) ;
V_221 = V_175 . V_104 + ( V_219 << 2 ) ;
V_220 = V_175 . V_104 + ( V_219 << 2 ) + 2 ;
V_92 = V_6 -> V_93 ( V_2 , V_220 , & V_222 , 2 , & V_2 -> V_55 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = V_6 -> V_93 ( V_2 , V_221 , & V_30 , 2 , & V_2 -> V_55 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = F_71 ( V_2 , V_222 , V_98 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_44 = V_30 ;
return V_92 ;
}
int F_89 ( struct V_1 * V_2 , int V_219 )
{
int V_92 ;
F_6 ( V_2 ) ;
V_92 = F_88 ( V_2 , V_219 ) ;
if ( V_92 == V_90 )
F_4 ( V_2 ) ;
return V_92 ;
}
static int F_90 ( struct V_1 * V_2 , int V_219 )
{
switch( V_2 -> V_36 ) {
case V_88 :
return F_88 ( V_2 , V_219 ) ;
case V_190 :
case V_210 :
case V_209 :
case V_37 :
default:
return V_101 ;
}
}
static int F_91 ( struct V_1 * V_2 )
{
int V_92 = V_90 ;
unsigned long V_223 = 0 ;
unsigned long V_224 = 0 ;
unsigned long V_222 = 0 ;
unsigned long V_32 = V_109 | V_112 | V_203 | V_110 | V_111 | V_204 |
V_212 | V_171 | V_108 | V_211 | V_205 | V_206 |
V_207 | V_208 | ( 1 << 1 ) ;
unsigned long V_225 = V_226 | V_227 | V_228 ;
V_92 = F_77 ( V_2 , & V_223 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
if ( V_223 & ~ 0xffff )
return F_25 ( V_2 , 0 ) ;
V_92 = F_77 ( V_2 , & V_222 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = F_77 ( V_2 , & V_224 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = F_71 ( V_2 , ( T_2 ) V_222 , V_98 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_44 = V_223 ;
if ( V_2 -> V_105 == 4 )
V_2 -> V_170 = ( ( V_224 & V_32 ) | ( V_2 -> V_170 & V_225 ) ) ;
else if ( V_2 -> V_105 == 2 ) {
V_2 -> V_170 &= ~ 0xffff ;
V_2 -> V_170 |= V_224 ;
}
V_2 -> V_170 &= ~ V_229 ;
V_2 -> V_170 |= V_230 ;
return V_92 ;
}
static int F_92 ( struct V_1 * V_2 )
{
switch( V_2 -> V_36 ) {
case V_88 :
return F_91 ( V_2 ) ;
case V_190 :
case V_210 :
case V_209 :
case V_37 :
default:
return V_101 ;
}
}
static int F_93 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned short V_33 ;
memcpy ( & V_33 , V_2 -> V_22 . V_231 + V_2 -> V_105 , 2 ) ;
V_92 = F_71 ( V_2 , V_33 , V_98 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_231 , V_2 -> V_105 ) ;
return V_90 ;
}
static int F_94 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case 0 :
F_95 ( V_2 , L_1 ) ;
break;
case 1 :
F_95 ( V_2 , L_2 ) ;
break;
case 2 :
F_95 ( V_2 , L_3 ) ;
break;
case 3 :
F_95 ( V_2 , L_4 ) ;
break;
case 4 :
case 6 :
F_95 ( V_2 , L_5 ) ;
break;
case 5 :
F_95 ( V_2 , L_6 ) ;
break;
case 7 :
F_95 ( V_2 , L_7 ) ;
break;
}
return V_90 ;
}
static int F_96 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_115 = ~ V_2 -> V_27 . V_115 ;
return V_90 ;
}
static int F_97 ( struct V_1 * V_2 )
{
F_98 ( V_2 , L_8 ) ;
return V_90 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_4 V_232 = 0 ;
F_100 ( V_2 , L_9 , V_232 ) ;
return V_90 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_4 V_232 = 0 ;
F_100 ( V_2 , L_10 , V_232 ) ;
return V_90 ;
}
static int F_102 ( struct V_1 * V_2 )
{
T_4 V_233 = 0 ;
F_100 ( V_2 , L_11 , V_233 ) ;
if ( V_233 )
return F_29 ( V_2 ) ;
return V_90 ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_4 V_233 = 0 ;
F_100 ( V_2 , L_12 , V_233 ) ;
if ( V_233 )
return F_29 ( V_2 ) ;
return V_90 ;
}
static int F_104 ( struct V_1 * V_2 )
{
int V_92 = V_90 ;
switch ( V_2 -> V_19 ) {
case 0 :
F_98 ( V_2 , L_13 ) ;
break;
case 1 :
F_98 ( V_2 , L_14 ) ;
break;
case 2 : {
long int V_234 ;
V_234 = V_2 -> V_44 ;
V_2 -> V_44 = V_2 -> V_22 . V_115 ;
V_2 -> V_22 . V_115 = V_234 ;
V_92 = F_76 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_44 = V_2 -> V_22 . V_115 ;
break;
case 5 :
V_92 = F_93 ( V_2 ) ;
break;
case 6 :
V_92 = F_76 ( V_2 ) ;
break;
}
return V_92 ;
}
static int F_105 ( struct V_1 * V_2 )
{
V_116 V_235 = V_2 -> V_27 . V_236 ;
if ( ( ( T_3 ) ( V_235 >> 0 ) != ( T_3 ) F_1 ( V_2 , V_218 ) ) ||
( ( T_3 ) ( V_235 >> 32 ) != ( T_3 ) F_1 ( V_2 , V_237 ) ) ) {
* F_2 ( V_2 , V_218 ) = ( T_3 ) ( V_235 >> 0 ) ;
* F_2 ( V_2 , V_237 ) = ( T_3 ) ( V_235 >> 32 ) ;
V_2 -> V_170 &= ~ V_110 ;
} else {
V_2 -> V_27 . V_23 = ( ( V_116 ) F_1 ( V_2 , V_169 ) << 32 ) |
( T_3 ) F_1 ( V_2 , V_143 ) ;
V_2 -> V_170 |= V_110 ;
}
return V_90 ;
}
static int F_106 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_129 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
return F_78 ( V_2 ) ;
}
static int F_107 ( struct V_1 * V_2 )
{
int V_92 ;
unsigned long V_222 ;
V_92 = F_77 ( V_2 , & V_2 -> V_44 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
if ( V_2 -> V_105 == 4 )
V_2 -> V_44 = ( T_3 ) V_2 -> V_44 ;
V_92 = F_77 ( V_2 , & V_222 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_92 = F_71 ( V_2 , ( T_2 ) V_222 , V_98 ) ;
return V_92 ;
}
static int F_108 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_131 = V_2 -> V_22 . V_115 ;
V_2 -> V_22 . V_115 = F_1 ( V_2 , V_218 ) ;
F_109 ( V_2 , L_15 ) ;
if ( V_2 -> V_170 & V_110 ) {
V_2 -> V_27 . V_115 = V_2 -> V_22 . V_131 ;
} else {
V_2 -> V_27 . type = V_129 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_218 ) ;
}
return V_90 ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_215 . V_115 ;
unsigned short V_33 ;
int V_92 ;
memcpy ( & V_33 , V_2 -> V_22 . V_231 + V_2 -> V_105 , 2 ) ;
V_92 = F_71 ( V_2 , V_33 , V_48 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_27 . V_115 = V_2 -> V_22 . V_115 ;
return V_92 ;
}
static void
F_111 ( struct V_1 * V_2 ,
struct V_34 * V_222 , struct V_34 * V_35 )
{
V_222 -> V_238 = 0 ;
F_72 ( V_222 , 0 ) ;
V_222 -> V_47 = 1 ;
F_112 ( V_222 , 0xfffff ) ;
V_222 -> type = 0x0b ;
V_222 -> V_193 = 1 ;
V_222 -> V_89 = 0 ;
V_222 -> V_103 = 1 ;
V_222 -> V_40 = 1 ;
V_222 -> V_239 = 0 ;
F_72 ( V_35 , 0 ) ;
F_112 ( V_35 , 0xfffff ) ;
V_35 -> V_47 = 1 ;
V_35 -> V_193 = 1 ;
V_35 -> type = 0x03 ;
V_35 -> V_40 = 1 ;
V_35 -> V_89 = 0 ;
V_35 -> V_103 = 1 ;
V_35 -> V_238 = 0 ;
V_35 -> V_239 = 0 ;
}
static bool F_113 ( struct V_1 * V_2 )
{
T_3 V_240 , V_241 , V_242 , V_243 ;
V_240 = V_242 = 0 ;
V_2 -> V_6 -> V_244 ( V_2 , & V_240 , & V_241 , & V_242 , & V_243 ) ;
return V_241 == V_245
&& V_242 == V_246
&& V_243 == V_247 ;
}
static bool F_114 ( struct V_1 * V_2 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
T_3 V_240 , V_241 , V_242 , V_243 ;
if ( V_2 -> V_36 == V_37 )
return true ;
V_240 = 0x00000000 ;
V_242 = 0x00000000 ;
V_6 -> V_244 ( V_2 , & V_240 , & V_241 , & V_242 , & V_243 ) ;
if ( V_241 == V_245 &&
V_242 == V_246 &&
V_243 == V_247 )
return false ;
if ( V_241 == V_248 &&
V_242 == V_249 &&
V_243 == V_250 )
return true ;
if ( V_241 == V_251 &&
V_242 == V_252 &&
V_243 == V_253 )
return true ;
return false ;
}
static int F_115 ( struct V_1 * V_2 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_34 V_222 , V_35 ;
V_116 V_254 ;
T_2 V_255 , V_256 ;
V_116 V_257 = 0 ;
if ( V_2 -> V_36 == V_88 ||
V_2 -> V_36 == V_190 )
return F_27 ( V_2 ) ;
if ( ! ( F_114 ( V_2 ) ) )
return F_27 ( V_2 ) ;
V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
F_111 ( V_2 , & V_222 , & V_35 ) ;
if ( ! ( V_257 & V_260 ) )
return F_27 ( V_2 ) ;
V_6 -> V_258 ( V_2 , V_261 , & V_254 ) ;
V_254 >>= 32 ;
V_255 = ( T_2 ) ( V_254 & 0xfffc ) ;
V_256 = ( T_2 ) ( V_254 + 8 ) ;
if ( V_257 & V_262 ) {
V_222 . V_40 = 0 ;
V_222 . V_238 = 1 ;
}
V_6 -> V_71 ( V_2 , V_255 , & V_222 , 0 , V_98 ) ;
V_6 -> V_71 ( V_2 , V_256 , & V_35 , 0 , V_39 ) ;
* F_2 ( V_2 , V_169 ) = V_2 -> V_44 ;
if ( V_257 & V_262 ) {
#ifdef F_49
* F_2 ( V_2 , V_263 ) = V_2 -> V_170 & ~ V_206 ;
V_6 -> V_258 ( V_2 ,
V_2 -> V_36 == V_37 ?
V_264 : V_265 , & V_254 ) ;
V_2 -> V_44 = V_254 ;
V_6 -> V_258 ( V_2 , V_266 , & V_254 ) ;
V_2 -> V_170 &= ~ ( V_254 | V_206 ) ;
#endif
} else {
V_6 -> V_258 ( V_2 , V_261 , & V_254 ) ;
V_2 -> V_44 = ( T_3 ) V_254 ;
V_2 -> V_170 &= ~ ( V_226 | V_212 | V_206 ) ;
}
return V_90 ;
}
static int F_116 ( struct V_1 * V_2 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_34 V_222 , V_35 ;
V_116 V_254 ;
T_2 V_255 , V_256 ;
V_116 V_257 = 0 ;
V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
if ( V_2 -> V_36 == V_88 )
return F_25 ( V_2 , 0 ) ;
if ( ( V_2 -> V_36 == V_209 ) && ( V_257 & V_262 )
&& ! F_113 ( V_2 ) )
return F_27 ( V_2 ) ;
if ( V_2 -> V_36 == V_37 )
return F_27 ( V_2 ) ;
F_111 ( V_2 , & V_222 , & V_35 ) ;
V_6 -> V_258 ( V_2 , V_267 , & V_254 ) ;
switch ( V_2 -> V_36 ) {
case V_209 :
if ( ( V_254 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
case V_37 :
if ( V_254 == 0x0 )
return F_25 ( V_2 , 0 ) ;
break;
default:
break;
}
V_2 -> V_170 &= ~ ( V_226 | V_212 | V_206 ) ;
V_255 = ( T_2 ) V_254 ;
V_255 &= ~ V_268 ;
V_256 = V_255 + 8 ;
V_256 &= ~ V_268 ;
if ( V_2 -> V_36 == V_37 || ( V_257 & V_262 ) ) {
V_222 . V_40 = 0 ;
V_222 . V_238 = 1 ;
}
V_6 -> V_71 ( V_2 , V_255 , & V_222 , 0 , V_98 ) ;
V_6 -> V_71 ( V_2 , V_256 , & V_35 , 0 , V_39 ) ;
V_6 -> V_258 ( V_2 , V_269 , & V_254 ) ;
V_2 -> V_44 = V_254 ;
V_6 -> V_258 ( V_2 , V_270 , & V_254 ) ;
* F_2 ( V_2 , V_42 ) = V_254 ;
return V_90 ;
}
static int F_117 ( struct V_1 * V_2 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_34 V_222 , V_35 ;
V_116 V_254 ;
int V_271 ;
T_2 V_255 = 0 , V_256 = 0 ;
if ( V_2 -> V_36 == V_88 ||
V_2 -> V_36 == V_190 )
return F_25 ( V_2 , 0 ) ;
F_111 ( V_2 , & V_222 , & V_35 ) ;
if ( ( V_2 -> V_119 & 0x8 ) != 0x0 )
V_271 = V_37 ;
else
V_271 = V_209 ;
V_222 . V_89 = 3 ;
V_35 . V_89 = 3 ;
V_6 -> V_258 ( V_2 , V_267 , & V_254 ) ;
switch ( V_271 ) {
case V_209 :
V_255 = ( T_2 ) ( V_254 + 16 ) ;
if ( ( V_254 & 0xfffc ) == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_256 = ( T_2 ) ( V_254 + 24 ) ;
break;
case V_37 :
V_255 = ( T_2 ) ( V_254 + 32 ) ;
if ( V_254 == 0x0 )
return F_25 ( V_2 , 0 ) ;
V_256 = V_255 + 8 ;
V_222 . V_40 = 0 ;
V_222 . V_238 = 1 ;
break;
}
V_255 |= V_268 ;
V_256 |= V_268 ;
V_6 -> V_71 ( V_2 , V_255 , & V_222 , 0 , V_98 ) ;
V_6 -> V_71 ( V_2 , V_256 , & V_35 , 0 , V_39 ) ;
V_2 -> V_44 = F_1 ( V_2 , V_237 ) ;
* F_2 ( V_2 , V_42 ) = F_1 ( V_2 , V_169 ) ;
return V_90 ;
}
static bool F_118 ( struct V_1 * V_2 )
{
int V_200 ;
if ( V_2 -> V_36 == V_88 )
return false ;
if ( V_2 -> V_36 == V_190 )
return true ;
V_200 = ( V_2 -> V_170 & V_201 ) >> V_202 ;
return V_2 -> V_6 -> V_84 ( V_2 ) > V_200 ;
}
static bool F_119 ( struct V_1 * V_2 ,
T_2 V_164 , T_2 V_198 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_34 V_272 ;
T_3 V_70 ;
int V_273 ;
T_2 V_274 , V_275 , V_276 , V_277 = V_164 & 0x7 ;
unsigned V_32 = ( 1 << V_198 ) - 1 ;
unsigned long V_278 ;
V_6 -> V_38 ( V_2 , & V_274 , & V_272 , & V_70 , V_192 ) ;
if ( ! V_272 . V_103 )
return false ;
if ( F_19 ( & V_272 ) < 103 )
return false ;
V_278 = F_68 ( & V_272 ) ;
#ifdef F_49
V_278 |= ( ( V_116 ) V_70 ) << 32 ;
#endif
V_273 = V_6 -> V_93 ( V_2 , V_278 + 102 , & V_275 , 2 , NULL ) ;
if ( V_273 != V_90 )
return false ;
if ( V_275 + V_164 / 8 > F_19 ( & V_272 ) )
return false ;
V_273 = V_6 -> V_93 ( V_2 , V_278 + V_275 + V_164 / 8 , & V_276 , 2 , NULL ) ;
if ( V_273 != V_90 )
return false ;
if ( ( V_276 >> V_277 ) & V_32 )
return false ;
return true ;
}
static bool F_120 ( struct V_1 * V_2 ,
T_2 V_164 , T_2 V_198 )
{
if ( V_2 -> V_279 )
return true ;
if ( F_118 ( V_2 ) )
if ( ! F_119 ( V_2 , V_164 , V_198 ) )
return false ;
V_2 -> V_279 = true ;
return true ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
V_281 -> V_282 = V_2 -> V_44 ;
V_281 -> V_283 = V_2 -> V_170 ;
V_281 -> V_284 = F_1 ( V_2 , V_218 ) ;
V_281 -> V_285 = F_1 ( V_2 , V_169 ) ;
V_281 -> V_286 = F_1 ( V_2 , V_237 ) ;
V_281 -> V_142 = F_1 ( V_2 , V_143 ) ;
V_281 -> V_287 = F_1 ( V_2 , V_42 ) ;
V_281 -> V_144 = F_1 ( V_2 , V_133 ) ;
V_281 -> V_145 = F_1 ( V_2 , V_146 ) ;
V_281 -> V_147 = F_1 ( V_2 , V_148 ) ;
V_281 -> V_288 = F_31 ( V_2 , V_289 ) ;
V_281 -> V_222 = F_31 ( V_2 , V_98 ) ;
V_281 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_281 -> V_290 = F_31 ( V_2 , V_140 ) ;
V_281 -> V_291 = F_31 ( V_2 , V_178 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
int V_188 ;
V_2 -> V_44 = V_281 -> V_282 ;
V_2 -> V_170 = V_281 -> V_283 | 2 ;
* F_2 ( V_2 , V_218 ) = V_281 -> V_284 ;
* F_2 ( V_2 , V_169 ) = V_281 -> V_285 ;
* F_2 ( V_2 , V_237 ) = V_281 -> V_286 ;
* F_2 ( V_2 , V_143 ) = V_281 -> V_142 ;
* F_2 ( V_2 , V_42 ) = V_281 -> V_287 ;
* F_2 ( V_2 , V_133 ) = V_281 -> V_144 ;
* F_2 ( V_2 , V_146 ) = V_281 -> V_145 ;
* F_2 ( V_2 , V_148 ) = V_281 -> V_147 ;
F_32 ( V_2 , V_281 -> V_291 , V_178 ) ;
F_32 ( V_2 , V_281 -> V_288 , V_289 ) ;
F_32 ( V_2 , V_281 -> V_222 , V_98 ) ;
F_32 ( V_2 , V_281 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_281 -> V_290 , V_140 ) ;
V_188 = F_71 ( V_2 , V_281 -> V_291 , V_178 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_288 , V_289 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_222 , V_98 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_35 , V_39 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_290 , V_140 ) ;
if ( V_188 != V_90 )
return V_188 ;
return V_90 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_2 V_292 , T_2 V_293 ,
T_1 V_294 , struct V_34 * V_295 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_280 V_296 ;
int V_188 ;
T_3 V_297 = F_68 ( V_295 ) ;
V_188 = V_6 -> V_93 ( V_2 , V_294 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
F_121 ( V_2 , & V_296 ) ;
V_188 = V_6 -> V_181 ( V_2 , V_294 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = V_6 -> V_93 ( V_2 , V_297 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
if ( V_293 != 0xffff ) {
V_296 . V_298 = V_293 ;
V_188 = V_6 -> V_181 ( V_2 , V_297 ,
& V_296 . V_298 ,
sizeof V_296 . V_298 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
}
return F_122 ( V_2 , & V_296 ) ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_299 * V_281 )
{
V_281 -> V_300 = V_2 -> V_6 -> V_301 ( V_2 , 3 ) ;
V_281 -> V_30 = V_2 -> V_44 ;
V_281 -> V_170 = V_2 -> V_170 ;
V_281 -> V_240 = F_1 ( V_2 , V_218 ) ;
V_281 -> V_242 = F_1 ( V_2 , V_169 ) ;
V_281 -> V_243 = F_1 ( V_2 , V_237 ) ;
V_281 -> V_241 = F_1 ( V_2 , V_143 ) ;
V_281 -> V_302 = F_1 ( V_2 , V_42 ) ;
V_281 -> V_303 = F_1 ( V_2 , V_133 ) ;
V_281 -> V_304 = F_1 ( V_2 , V_146 ) ;
V_281 -> V_305 = F_1 ( V_2 , V_148 ) ;
V_281 -> V_288 = F_31 ( V_2 , V_289 ) ;
V_281 -> V_222 = F_31 ( V_2 , V_98 ) ;
V_281 -> V_35 = F_31 ( V_2 , V_39 ) ;
V_281 -> V_290 = F_31 ( V_2 , V_140 ) ;
V_281 -> V_306 = F_31 ( V_2 , V_51 ) ;
V_281 -> V_307 = F_31 ( V_2 , V_189 ) ;
V_281 -> V_308 = F_31 ( V_2 , V_178 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_299 * V_281 )
{
int V_188 ;
if ( V_2 -> V_6 -> V_309 ( V_2 , 3 , V_281 -> V_300 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_44 = V_281 -> V_30 ;
V_2 -> V_170 = V_281 -> V_170 | 2 ;
* F_2 ( V_2 , V_218 ) = V_281 -> V_240 ;
* F_2 ( V_2 , V_169 ) = V_281 -> V_242 ;
* F_2 ( V_2 , V_237 ) = V_281 -> V_243 ;
* F_2 ( V_2 , V_143 ) = V_281 -> V_241 ;
* F_2 ( V_2 , V_42 ) = V_281 -> V_302 ;
* F_2 ( V_2 , V_133 ) = V_281 -> V_303 ;
* F_2 ( V_2 , V_146 ) = V_281 -> V_304 ;
* F_2 ( V_2 , V_148 ) = V_281 -> V_305 ;
F_32 ( V_2 , V_281 -> V_308 , V_178 ) ;
F_32 ( V_2 , V_281 -> V_288 , V_289 ) ;
F_32 ( V_2 , V_281 -> V_222 , V_98 ) ;
F_32 ( V_2 , V_281 -> V_35 , V_39 ) ;
F_32 ( V_2 , V_281 -> V_290 , V_140 ) ;
F_32 ( V_2 , V_281 -> V_306 , V_51 ) ;
F_32 ( V_2 , V_281 -> V_307 , V_189 ) ;
if ( V_2 -> V_170 & V_310 )
V_2 -> V_36 = V_190 ;
else
V_2 -> V_36 = V_209 ;
V_2 -> V_6 -> V_311 ( V_2 , V_2 -> V_170 ) ;
V_188 = F_71 ( V_2 , V_281 -> V_308 , V_178 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_288 , V_289 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_222 , V_98 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_35 , V_39 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_290 , V_140 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_306 , V_51 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_71 ( V_2 , V_281 -> V_307 , V_189 ) ;
if ( V_188 != V_90 )
return V_188 ;
return V_90 ;
}
static int F_126 ( struct V_1 * V_2 ,
T_2 V_292 , T_2 V_293 ,
T_1 V_294 , struct V_34 * V_295 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_299 V_296 ;
int V_188 ;
T_3 V_297 = F_68 ( V_295 ) ;
V_188 = V_6 -> V_93 ( V_2 , V_294 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
F_124 ( V_2 , & V_296 ) ;
V_188 = V_6 -> V_181 ( V_2 , V_294 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = V_6 -> V_93 ( V_2 , V_297 , & V_296 , sizeof V_296 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
if ( V_293 != 0xffff ) {
V_296 . V_298 = V_293 ;
V_188 = V_6 -> V_181 ( V_2 , V_297 ,
& V_296 . V_298 ,
sizeof V_296 . V_298 ,
& V_2 -> V_55 ) ;
if ( V_188 != V_90 )
return V_188 ;
}
return F_125 ( V_2 , & V_296 ) ;
}
static int F_127 ( struct V_1 * V_2 ,
T_2 V_292 , int V_312 , int V_313 ,
bool V_314 , T_3 V_57 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
struct V_34 V_315 , V_316 ;
int V_188 ;
T_2 V_293 = F_31 ( V_2 , V_192 ) ;
T_1 V_294 =
V_6 -> V_52 ( V_2 , V_192 ) ;
T_3 V_317 ;
T_1 V_187 ;
V_188 = F_69 ( V_2 , V_292 , & V_316 , & V_187 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_188 = F_69 ( V_2 , V_293 , & V_315 , & V_187 ) ;
if ( V_188 != V_90 )
return V_188 ;
if ( V_313 == V_318 ) {
if ( V_312 != - 1 ) {
struct V_34 V_319 ;
int V_89 ;
V_188 = F_66 ( V_2 , V_312 ,
& V_319 ) ;
if ( V_188 != V_90 )
return V_188 ;
V_89 = V_319 . V_89 ;
if ( ( V_292 & 3 ) > V_89 || V_6 -> V_84 ( V_2 ) > V_89 )
return F_25 ( V_2 , ( V_312 << 3 ) | 0x2 ) ;
}
} else if ( V_313 != V_320 ) {
int V_89 = V_316 . V_89 ;
if ( ( V_292 & 3 ) > V_89 || V_6 -> V_84 ( V_2 ) > V_89 )
return F_25 ( V_2 , V_292 ) ;
}
V_317 = F_19 ( & V_316 ) ;
if ( ! V_316 . V_103 ||
( ( V_317 < 0x67 && ( V_316 . type & 8 ) ) ||
V_317 < 0x2b ) ) {
F_28 ( V_2 , V_292 & 0xfffc ) ;
return V_59 ;
}
if ( V_313 == V_320 || V_313 == V_321 ) {
V_315 . type &= ~ ( 1 << 1 ) ;
F_70 ( V_2 , V_293 , & V_315 ) ;
}
if ( V_313 == V_320 )
V_2 -> V_170 = V_2 -> V_170 & ~ V_322 ;
if ( V_313 != V_323 && V_313 != V_318 )
V_293 = 0xffff ;
if ( V_316 . type & 8 )
V_188 = F_126 ( V_2 , V_292 , V_293 ,
V_294 , & V_316 ) ;
else
V_188 = F_123 ( V_2 , V_292 , V_293 ,
V_294 , & V_316 ) ;
if ( V_188 != V_90 )
return V_188 ;
if ( V_313 == V_323 || V_313 == V_318 )
V_2 -> V_170 = V_2 -> V_170 | V_322 ;
if ( V_313 != V_320 ) {
V_316 . type |= ( 1 << 1 ) ;
F_70 ( V_2 , V_292 , & V_316 ) ;
}
V_6 -> V_309 ( V_2 , 0 , V_6 -> V_301 ( V_2 , 0 ) | V_324 ) ;
V_6 -> V_71 ( V_2 , V_292 , & V_316 , 0 , V_192 ) ;
if ( V_314 ) {
V_2 -> V_105 = V_2 -> V_28 = ( V_316 . type & 8 ) ? 4 : 2 ;
V_2 -> V_195 = 0 ;
V_2 -> V_22 . V_115 = ( unsigned long ) V_57 ;
V_188 = F_76 ( V_2 ) ;
}
return V_188 ;
}
int F_128 ( struct V_1 * V_2 ,
T_2 V_292 , int V_312 , int V_313 ,
bool V_314 , T_3 V_57 )
{
int V_92 ;
F_6 ( V_2 ) ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_197 ;
V_92 = F_127 ( V_2 , V_292 , V_312 , V_313 ,
V_314 , V_57 ) ;
if ( V_92 == V_90 ) {
V_2 -> V_30 = V_2 -> V_44 ;
F_4 ( V_2 ) ;
}
return ( V_92 == V_101 ) ? V_325 : V_326 ;
}
static void F_129 ( struct V_1 * V_2 , int V_9 ,
struct V_113 * V_114 )
{
int V_327 = ( V_2 -> V_170 & V_171 ) ? - V_114 -> V_168 : V_114 -> V_168 ;
F_16 ( V_2 , F_3 ( V_2 , V_9 ) , V_327 * V_114 -> V_25 ) ;
V_114 -> V_77 . V_152 . V_86 = F_14 ( V_2 , F_1 ( V_2 , V_9 ) ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
T_4 V_328 , V_329 ;
bool V_330 , V_331 , V_332 ;
V_331 = V_2 -> V_170 & V_333 ;
V_328 = V_2 -> V_27 . V_115 ;
V_329 = V_328 ;
V_332 = V_331 ;
V_331 = false ;
V_330 = V_2 -> V_170 & V_334 ;
if ( ( V_328 & 0x0f ) > 9 || V_330 ) {
V_328 -= 6 ;
V_331 = V_332 | ( V_328 >= 250 ) ;
V_330 = true ;
} else {
V_330 = false ;
}
if ( V_329 > 0x99 || V_332 ) {
V_328 -= 0x60 ;
V_331 = true ;
}
V_2 -> V_27 . V_115 = V_328 ;
V_2 -> V_22 . type = V_335 ;
V_2 -> V_22 . V_115 = 0 ;
V_2 -> V_22 . V_25 = 1 ;
F_109 ( V_2 , L_16 ) ;
V_2 -> V_170 &= ~ ( V_334 | V_333 ) ;
if ( V_331 )
V_2 -> V_170 |= V_333 ;
if ( V_330 )
V_2 -> V_170 |= V_334 ;
return V_90 ;
}
static int F_131 ( struct V_1 * V_2 )
{
long V_43 = V_2 -> V_22 . V_115 ;
V_2 -> V_22 . V_115 = ( unsigned long ) V_2 -> V_44 ;
F_18 ( V_2 , V_43 ) ;
return F_76 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
T_2 V_33 , V_336 ;
T_1 V_234 ;
int V_92 ;
V_336 = F_31 ( V_2 , V_98 ) ;
V_234 = V_2 -> V_44 ;
memcpy ( & V_33 , V_2 -> V_22 . V_231 + V_2 -> V_105 , 2 ) ;
if ( F_71 ( V_2 , V_33 , V_98 ) )
return V_90 ;
V_2 -> V_44 = 0 ;
memcpy ( & V_2 -> V_44 , V_2 -> V_22 . V_231 , V_2 -> V_105 ) ;
V_2 -> V_22 . V_115 = V_336 ;
V_92 = F_76 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_22 . V_115 = V_234 ;
return F_76 ( V_2 ) ;
}
static int F_133 ( struct V_1 * V_2 )
{
int V_92 ;
V_2 -> V_27 . type = V_129 ;
V_2 -> V_27 . V_77 . V_9 = & V_2 -> V_44 ;
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
V_92 = F_77 ( V_2 , & V_2 -> V_27 . V_115 , V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
F_17 ( V_2 , V_2 -> V_22 . V_115 ) ;
return V_90 ;
}
static int F_134 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_17 ) ;
return V_90 ;
}
static int F_135 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_16 ) ;
return V_90 ;
}
static int F_136 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_18 ) ;
return V_90 ;
}
static int F_137 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_19 ) ;
return V_90 ;
}
static int F_138 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_20 ) ;
return V_90 ;
}
static int F_139 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_21 ) ;
return V_90 ;
}
static int F_140 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_22 ) ;
return V_90 ;
}
static int F_141 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_15 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_142 ( struct V_1 * V_2 )
{
F_109 ( V_2 , L_23 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_115 = V_2 -> V_27 . V_115 ;
F_73 ( & V_2 -> V_22 ) ;
V_2 -> V_27 . V_115 = V_2 -> V_22 . V_131 ;
V_2 -> V_195 = 1 ;
return V_90 ;
}
static int F_144 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_10 ) ;
return V_90 ;
}
static int F_146 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_115 = V_2 -> V_215 . V_115 ;
return F_144 ( V_2 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_129 ;
V_2 -> V_27 . V_25 = V_2 -> V_22 . V_25 ;
V_2 -> V_27 . V_77 . V_9 = F_3 ( V_2 , V_237 ) ;
V_2 -> V_27 . V_115 = ~ ( ( V_2 -> V_22 . V_115 >> ( V_2 -> V_22 . V_25 * 8 - 1 ) ) - 1 ) ;
return V_90 ;
}
static int F_148 ( struct V_1 * V_2 )
{
V_116 V_337 = 0 ;
V_2 -> V_6 -> V_258 ( V_2 , V_338 , & V_337 ) ;
* F_2 ( V_2 , V_218 ) = ( T_3 ) V_337 ;
* F_2 ( V_2 , V_237 ) = V_337 >> 32 ;
return V_90 ;
}
static int F_149 ( struct V_1 * V_2 )
{
V_116 V_339 ;
if ( V_2 -> V_6 -> V_340 ( V_2 , F_1 ( V_2 , V_169 ) , & V_339 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_218 ) = ( T_3 ) V_339 ;
* F_2 ( V_2 , V_237 ) = V_339 >> 32 ;
return V_90 ;
}
static int F_150 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_27 . V_231 , V_2 -> V_22 . V_231 , V_2 -> V_105 ) ;
return V_90 ;
}
static int F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_309 ( V_2 , V_2 -> V_19 , V_2 -> V_22 . V_115 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_152 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
if ( V_2 -> V_36 == V_37 )
V_115 = V_2 -> V_22 . V_115 & ~ 0ULL ;
else
V_115 = V_2 -> V_22 . V_115 & ~ 0U ;
if ( V_2 -> V_6 -> V_341 ( V_2 , V_2 -> V_19 , V_115 ) < 0 )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_116 V_254 ;
V_254 = ( T_3 ) F_1 ( V_2 , V_218 )
| ( ( V_116 ) F_1 ( V_2 , V_237 ) << 32 ) ;
if ( V_2 -> V_6 -> V_342 ( V_2 , F_1 ( V_2 , V_169 ) , V_254 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_154 ( struct V_1 * V_2 )
{
V_116 V_254 ;
if ( V_2 -> V_6 -> V_258 ( V_2 , F_1 ( V_2 , V_169 ) , & V_254 ) )
return F_25 ( V_2 , 0 ) ;
* F_2 ( V_2 , V_218 ) = ( T_3 ) V_254 ;
* F_2 ( V_2 , V_237 ) = V_254 >> 32 ;
return V_90 ;
}
static int F_155 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 > V_189 )
return F_27 ( V_2 ) ;
V_2 -> V_27 . V_115 = F_31 ( V_2 , V_2 -> V_19 ) ;
return V_90 ;
}
static int F_156 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_115 ;
if ( V_2 -> V_19 == V_98 || V_2 -> V_19 > V_189 )
return F_27 ( V_2 ) ;
if ( V_2 -> V_19 == V_39 )
V_2 -> V_343 = V_344 ;
V_2 -> V_27 . type = V_197 ;
return F_71 ( V_2 , V_33 , V_2 -> V_19 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_115 ;
V_2 -> V_27 . type = V_197 ;
return F_71 ( V_2 , V_33 , V_178 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
T_2 V_33 = V_2 -> V_22 . V_115 ;
V_2 -> V_27 . type = V_197 ;
return F_71 ( V_2 , V_33 , V_192 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_92 ;
T_1 V_80 ;
V_92 = F_37 ( V_2 , V_2 -> V_22 . V_77 . V_152 , 1 , false , & V_80 ) ;
if ( V_92 == V_90 )
V_2 -> V_6 -> V_345 ( V_2 , V_80 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_160 ( struct V_1 * V_2 )
{
T_1 V_346 ;
V_346 = V_2 -> V_6 -> V_301 ( V_2 , 0 ) ;
V_346 &= ~ V_324 ;
V_2 -> V_6 -> V_309 ( V_2 , 0 , V_346 ) ;
return V_90 ;
}
static int F_161 ( struct V_1 * V_2 )
{
int V_92 ;
if ( V_2 -> V_18 != 3 || V_2 -> V_20 != 1 )
return V_101 ;
V_92 = V_2 -> V_6 -> V_347 ( V_2 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_162 ( struct V_1 * V_2 ,
void (* F_163)( struct V_1 * V_2 ,
struct V_174 * V_348 ) )
{
struct V_174 V_174 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_105 = 8 ;
F_163 ( V_2 , & V_174 ) ;
if ( V_2 -> V_105 == 2 ) {
V_2 -> V_105 = 4 ;
V_174 . V_104 &= 0x00ffffff ;
}
V_2 -> V_27 . type = V_197 ;
return F_63 ( V_2 , V_2 -> V_27 . V_77 . V_152 ,
& V_174 , 2 + V_2 -> V_105 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
return F_162 ( V_2 , V_2 -> V_6 -> V_179 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
return F_162 ( V_2 , V_2 -> V_6 -> V_176 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
struct V_174 V_174 ;
int V_92 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_105 = 8 ;
V_92 = F_45 ( V_2 , V_2 -> V_22 . V_77 . V_152 ,
& V_174 . V_72 , & V_174 . V_104 ,
V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_6 -> V_349 ( V_2 , & V_174 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_167 ( struct V_1 * V_2 )
{
int V_92 ;
V_92 = V_2 -> V_6 -> V_347 ( V_2 ) ;
V_2 -> V_27 . type = V_197 ;
return V_92 ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_174 V_174 ;
int V_92 ;
if ( V_2 -> V_36 == V_37 )
V_2 -> V_105 = 8 ;
V_92 = F_45 ( V_2 , V_2 -> V_22 . V_77 . V_152 ,
& V_174 . V_72 , & V_174 . V_104 ,
V_2 -> V_105 ) ;
if ( V_92 != V_90 )
return V_92 ;
V_2 -> V_6 -> V_350 ( V_2 , & V_174 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = 2 ;
V_2 -> V_27 . V_115 = V_2 -> V_6 -> V_301 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_309 ( V_2 , 0 , ( V_2 -> V_6 -> V_301 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_22 . V_115 & 0x0f ) ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_171 ( struct V_1 * V_2 )
{
F_16 ( V_2 , F_3 ( V_2 , V_169 ) , - 1 ) ;
if ( ( F_13 ( V_2 , F_1 ( V_2 , V_169 ) ) != 0 ) &&
( V_2 -> V_121 == 0xe2 || F_46 ( V_2 -> V_121 ^ 0x5 , V_2 -> V_170 ) ) )
F_18 ( V_2 , V_2 -> V_22 . V_115 ) ;
return V_90 ;
}
static int F_172 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 , F_1 ( V_2 , V_169 ) ) == 0 )
F_18 ( V_2 , V_2 -> V_22 . V_115 ) ;
return V_90 ;
}
static int F_173 ( struct V_1 * V_2 )
{
if ( ! F_65 ( V_2 , V_2 -> V_27 . V_25 , V_2 -> V_22 . V_115 ,
& V_2 -> V_27 . V_115 ) )
return V_351 ;
return V_90 ;
}
static int F_174 ( struct V_1 * V_2 )
{
V_2 -> V_6 -> V_352 ( V_2 , V_2 -> V_22 . V_25 , V_2 -> V_27 . V_115 ,
& V_2 -> V_22 . V_115 , 1 ) ;
V_2 -> V_27 . type = V_197 ;
return V_90 ;
}
static int F_175 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_170 &= ~ V_353 ;
return V_90 ;
}
static int F_176 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 ) )
return F_25 ( V_2 , 0 ) ;
V_2 -> V_343 = V_354 ;
V_2 -> V_170 |= V_353 ;
return V_90 ;
}
static int F_177 ( struct V_1 * V_2 )
{
V_2 -> V_27 . type = V_197 ;
V_2 -> V_22 . V_115 &= ( V_2 -> V_27 . V_25 << 3 ) - 1 ;
F_145 ( V_2 , L_24 ) ;
return V_90 ;
}
static int F_178 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_25 ) ;
return V_90 ;
}
static int F_179 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_26 ) ;
return V_90 ;
}
static int F_180 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_27 ) ;
return V_90 ;
}
static int F_181 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_28 ) ;
return V_90 ;
}
static int F_182 ( struct V_1 * V_2 )
{
F_145 ( V_2 , L_29 ) ;
return V_90 ;
}
static int F_183 ( struct V_1 * V_2 )
{
T_3 V_240 , V_241 , V_242 , V_243 ;
V_240 = F_1 ( V_2 , V_218 ) ;
V_242 = F_1 ( V_2 , V_169 ) ;
V_2 -> V_6 -> V_244 ( V_2 , & V_240 , & V_241 , & V_242 , & V_243 ) ;
* F_2 ( V_2 , V_218 ) = V_240 ;
* F_2 ( V_2 , V_143 ) = V_241 ;
* F_2 ( V_2 , V_169 ) = V_242 ;
* F_2 ( V_2 , V_237 ) = V_243 ;
return V_90 ;
}
static int F_184 ( struct V_1 * V_2 )
{
* F_3 ( V_2 , V_218 ) &= ~ 0xff00UL ;
* F_3 ( V_2 , V_218 ) |= ( V_2 -> V_170 & 0xff ) << 8 ;
return V_90 ;
}
static int F_185 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_105 ) {
#ifdef F_49
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
static bool F_186 ( int V_3 )
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
static int F_187 ( struct V_1 * V_2 )
{
if ( ! F_186 ( V_2 -> V_19 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_116 V_355 = V_2 -> V_22 . V_23 ;
int V_356 = V_2 -> V_19 ;
V_116 V_257 = 0 ;
static V_116 V_357 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_358 ,
0 , 0 , 0 ,
V_359 ,
} ;
if ( ! F_186 ( V_356 ) )
return F_27 ( V_2 ) ;
if ( V_355 & V_357 [ V_356 ] )
return F_25 ( V_2 , 0 ) ;
switch ( V_356 ) {
case 0 : {
V_116 V_360 ;
if ( ( ( V_355 & V_361 ) && ! ( V_355 & V_362 ) ) ||
( ( V_355 & V_363 ) && ! ( V_355 & V_364 ) ) )
return F_25 ( V_2 , 0 ) ;
V_360 = V_2 -> V_6 -> V_301 ( V_2 , 4 ) ;
V_2 -> V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
if ( ( V_355 & V_361 ) && ( V_257 & V_365 ) &&
! ( V_360 & V_366 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_116 V_367 = 0 ;
V_2 -> V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
if ( V_257 & V_262 )
V_367 = V_368 ;
else if ( V_2 -> V_6 -> V_301 ( V_2 , 4 ) & V_366 )
V_367 = V_369 ;
else if ( V_2 -> V_6 -> V_301 ( V_2 , 0 ) & V_361 )
V_367 = V_370 ;
if ( V_355 & V_367 )
return F_25 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
if ( ( V_257 & V_262 ) && ! ( V_355 & V_366 ) )
return F_25 ( V_2 , 0 ) ;
break;
}
}
return V_90 ;
}
static int F_189 ( struct V_1 * V_2 )
{
unsigned long V_371 ;
V_2 -> V_6 -> V_372 ( V_2 , 7 , & V_371 ) ;
return V_371 & ( 1 << 13 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_373 = V_2 -> V_19 ;
V_116 V_360 ;
if ( V_373 > 7 )
return F_27 ( V_2 ) ;
V_360 = V_2 -> V_6 -> V_301 ( V_2 , 4 ) ;
if ( ( V_360 & V_374 ) && ( V_373 == 4 || V_373 == 5 ) )
return F_27 ( V_2 ) ;
if ( F_189 ( V_2 ) )
return F_24 ( V_2 ) ;
return V_90 ;
}
static int F_191 ( struct V_1 * V_2 )
{
V_116 V_355 = V_2 -> V_22 . V_23 ;
int V_373 = V_2 -> V_19 ;
if ( ( V_373 == 6 || V_373 == 7 ) && ( V_355 & 0xffffffff00000000ULL ) )
return F_25 ( V_2 , 0 ) ;
return F_190 ( V_2 ) ;
}
static int F_192 ( struct V_1 * V_2 )
{
V_116 V_257 ;
V_2 -> V_6 -> V_258 ( V_2 , V_259 , & V_257 ) ;
if ( ! ( V_257 & V_375 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_193 ( struct V_1 * V_2 )
{
V_116 V_376 = F_1 ( V_2 , V_218 ) ;
if ( V_376 & 0xffff000000000000ULL )
return F_25 ( V_2 , 0 ) ;
return F_192 ( V_2 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
V_116 V_360 = V_2 -> V_6 -> V_301 ( V_2 , 4 ) ;
if ( V_360 & V_377 && V_2 -> V_6 -> V_84 ( V_2 ) )
return F_27 ( V_2 ) ;
return V_90 ;
}
static int F_195 ( struct V_1 * V_2 )
{
V_116 V_360 = V_2 -> V_6 -> V_301 ( V_2 , 4 ) ;
V_116 V_378 = F_1 ( V_2 , V_169 ) ;
if ( ( ! ( V_360 & V_379 ) && V_2 -> V_6 -> V_84 ( V_2 ) ) ||
( V_378 > 3 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_196 ( struct V_1 * V_2 )
{
V_2 -> V_27 . V_25 = F_40 ( V_2 -> V_27 . V_25 , 4u ) ;
if ( ! F_120 ( V_2 , V_2 -> V_22 . V_115 , V_2 -> V_27 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static int F_197 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_25 = F_40 ( V_2 -> V_22 . V_25 , 4u ) ;
if ( ! F_120 ( V_2 , V_2 -> V_27 . V_115 , V_2 -> V_22 . V_25 ) )
return F_25 ( V_2 , 0 ) ;
return V_90 ;
}
static unsigned F_198 ( struct V_1 * V_2 )
{
unsigned V_72 ;
V_72 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
if ( V_72 == 8 )
V_72 = 4 ;
return V_72 ;
}
static int F_199 ( struct V_1 * V_2 , struct V_113 * V_114 ,
unsigned V_72 , bool V_380 )
{
int V_92 = V_90 ;
V_114 -> type = V_335 ;
V_114 -> V_25 = V_72 ;
V_114 -> V_77 . V_152 . V_86 = V_2 -> V_44 ;
switch ( V_114 -> V_25 ) {
case 1 :
V_114 -> V_115 = F_57 ( V_149 , V_2 ) ;
break;
case 2 :
V_114 -> V_115 = F_57 ( V_155 , V_2 ) ;
break;
case 4 :
V_114 -> V_115 = F_57 ( V_150 , V_2 ) ;
break;
}
if ( ! V_380 ) {
switch ( V_114 -> V_25 ) {
case 1 :
V_114 -> V_115 &= 0xff ;
break;
case 2 :
V_114 -> V_115 &= 0xffff ;
break;
case 4 :
V_114 -> V_115 &= 0xffffffff ;
break;
}
}
V_153:
return V_92 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_113 * V_114 ,
unsigned V_40 )
{
int V_92 = V_90 ;
switch ( V_40 ) {
case V_381 :
F_54 ( V_2 , V_114 ) ;
break;
case V_382 :
V_92 = F_199 ( V_2 , V_114 , 1 , false ) ;
break;
case V_383 :
V_2 -> V_384 . V_25 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
V_385:
* V_114 = V_2 -> V_384 ;
V_2 -> V_386 = V_114 ;
if ( ( V_2 -> V_40 & V_387 ) && V_114 == & V_2 -> V_27 )
F_59 ( V_2 ) ;
V_114 -> V_131 = V_114 -> V_115 ;
break;
case V_388 :
V_2 -> V_384 . V_25 = 8 ;
goto V_385;
case V_389 :
V_114 -> type = V_129 ;
V_114 -> V_25 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
V_114 -> V_77 . V_9 = F_3 ( V_2 , V_218 ) ;
F_47 ( V_114 ) ;
V_114 -> V_131 = V_114 -> V_115 ;
break;
case V_390 :
V_114 -> type = V_141 ;
V_114 -> V_25 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
V_114 -> V_77 . V_152 . V_86 =
F_14 ( V_2 , F_1 ( V_2 , V_148 ) ) ;
V_114 -> V_77 . V_152 . V_48 = V_289 ;
V_114 -> V_115 = 0 ;
V_114 -> V_168 = 1 ;
break;
case V_391 :
V_114 -> type = V_129 ;
V_114 -> V_25 = 2 ;
V_114 -> V_77 . V_9 = F_3 ( V_2 , V_237 ) ;
F_47 ( V_114 ) ;
break;
case V_392 :
V_114 -> V_25 = 1 ;
V_114 -> V_115 = F_1 ( V_2 , V_169 ) & 0xff ;
break;
case V_393 :
V_92 = F_199 ( V_2 , V_114 , 1 , true ) ;
break;
case V_394 :
V_114 -> V_25 = 1 ;
V_114 -> V_115 = 1 ;
break;
case V_395 :
V_92 = F_199 ( V_2 , V_114 , F_198 ( V_2 ) , true ) ;
break;
case V_396 :
V_2 -> V_384 . V_25 = 1 ;
goto V_385;
case V_397 :
V_2 -> V_384 . V_25 = 2 ;
goto V_385;
case V_398 :
V_2 -> V_384 . V_25 = 4 ;
goto V_385;
case V_399 :
V_92 = F_199 ( V_2 , V_114 , 2 , false ) ;
break;
case V_400 :
V_92 = F_199 ( V_2 , V_114 , F_198 ( V_2 ) , false ) ;
break;
case V_401 :
V_114 -> type = V_141 ;
V_114 -> V_25 = ( V_2 -> V_40 & V_130 ) ? 1 : V_2 -> V_105 ;
V_114 -> V_77 . V_152 . V_86 =
F_14 ( V_2 , F_1 ( V_2 , V_146 ) ) ;
V_114 -> V_77 . V_152 . V_48 = V_50 ( V_2 ) ;
V_114 -> V_115 = 0 ;
V_114 -> V_168 = 1 ;
break;
case V_402 :
V_114 -> type = V_335 ;
V_114 -> V_77 . V_152 . V_86 = V_2 -> V_44 ;
V_114 -> V_25 = V_2 -> V_105 + 2 ;
F_201 ( V_114 -> V_231 , V_114 -> V_25 , V_2 ) ;
break;
case V_403 :
V_2 -> V_384 . V_25 = V_2 -> V_105 + 2 ;
goto V_385;
case V_404 :
V_114 -> V_115 = V_289 ;
break;
case V_405 :
V_114 -> V_115 = V_98 ;
break;
case V_406 :
V_114 -> V_115 = V_39 ;
break;
case V_407 :
V_114 -> V_115 = V_140 ;
break;
case V_408 :
V_114 -> V_115 = V_51 ;
break;
case V_409 :
V_114 -> V_115 = V_189 ;
break;
case V_410 :
default:
V_114 -> type = V_197 ;
break;
}
V_153:
return V_92 ;
}
int F_202 ( struct V_1 * V_2 , void * V_411 , int V_412 )
{
int V_92 = V_90 ;
int V_36 = V_2 -> V_36 ;
int V_413 , V_414 , V_415 , V_416 ;
bool V_417 = false ;
struct V_418 V_418 ;
V_2 -> V_384 . type = V_197 ;
V_2 -> V_386 = NULL ;
V_2 -> V_44 = V_2 -> V_30 ;
V_2 -> V_79 . V_99 = V_2 -> V_44 ;
V_2 -> V_79 . V_97 = V_2 -> V_79 . V_99 + V_412 ;
if ( V_412 > 0 )
memcpy ( V_2 -> V_79 . V_91 , V_411 , V_412 ) ;
switch ( V_36 ) {
case V_88 :
case V_190 :
case V_210 :
V_413 = V_414 = 2 ;
break;
case V_209 :
V_413 = V_414 = 4 ;
break;
#ifdef F_49
case V_37 :
V_413 = 4 ;
V_414 = 8 ;
break;
#endif
default:
return V_325 ;
}
V_2 -> V_105 = V_413 ;
V_2 -> V_28 = V_414 ;
for (; ; ) {
switch ( V_2 -> V_121 = F_57 ( T_4 , V_2 ) ) {
case 0x66 :
V_417 = true ;
V_2 -> V_105 = V_413 ^ 6 ;
break;
case 0x67 :
if ( V_36 == V_37 )
V_2 -> V_28 = V_414 ^ 12 ;
else
V_2 -> V_28 = V_414 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_21 ( V_2 , ( V_2 -> V_121 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_21 ( V_2 , V_2 -> V_121 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_36 != V_37 )
goto V_419;
V_2 -> V_119 = V_2 -> V_121 ;
continue;
case 0xf0 :
V_2 -> V_195 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_17 = V_2 -> V_121 ;
break;
default:
goto V_419;
}
V_2 -> V_119 = 0 ;
}
V_419:
if ( V_2 -> V_119 & 8 )
V_2 -> V_105 = 8 ;
V_418 = V_420 [ V_2 -> V_121 ] ;
if ( V_2 -> V_121 == 0x0f ) {
V_2 -> V_421 = 1 ;
V_2 -> V_121 = F_57 ( T_4 , V_2 ) ;
V_418 = V_422 [ V_2 -> V_121 ] ;
}
V_2 -> V_40 = V_418 . V_107 ;
if ( V_2 -> V_40 & V_120 )
V_2 -> V_139 = F_57 ( T_4 , V_2 ) ;
while ( V_2 -> V_40 & V_423 ) {
switch ( V_2 -> V_40 & V_423 ) {
case V_424 :
V_415 = ( V_2 -> V_139 >> 3 ) & 7 ;
V_418 = V_418 . V_425 . V_426 [ V_415 ] ;
break;
case V_427 :
V_415 = ( V_2 -> V_139 >> 3 ) & 7 ;
if ( ( V_2 -> V_139 >> 6 ) == 3 )
V_418 = V_418 . V_425 . V_428 -> V_429 [ V_415 ] ;
else
V_418 = V_418 . V_425 . V_428 -> V_430 [ V_415 ] ;
break;
case V_431 :
V_415 = V_2 -> V_139 & 7 ;
V_418 = V_418 . V_425 . V_426 [ V_415 ] ;
break;
case V_432 :
if ( V_2 -> V_17 && V_417 )
return V_325 ;
V_416 = V_417 ? 0x66 : V_2 -> V_17 ;
switch ( V_416 ) {
case 0x00 : V_418 = V_418 . V_425 . V_433 -> V_434 ; break;
case 0x66 : V_418 = V_418 . V_425 . V_433 -> V_435 ; break;
case 0xf2 : V_418 = V_418 . V_425 . V_433 -> V_436 ; break;
case 0xf3 : V_418 = V_418 . V_425 . V_433 -> V_437 ; break;
}
break;
default:
return V_325 ;
}
V_2 -> V_40 &= ~ ( V_116 ) V_423 ;
V_2 -> V_40 |= V_418 . V_107 ;
}
V_2 -> V_438 = V_418 . V_425 . V_438 ;
V_2 -> V_439 = V_418 . V_439 ;
V_2 -> V_12 = V_418 . V_12 ;
if ( V_2 -> V_40 == 0 || ( V_2 -> V_40 & V_440 ) )
return V_325 ;
if ( ! ( V_2 -> V_40 & V_441 ) && V_2 -> V_442 )
return V_325 ;
if ( V_36 == V_37 && ( V_2 -> V_40 & V_443 ) )
V_2 -> V_105 = 8 ;
if ( V_2 -> V_40 & V_444 ) {
if ( V_36 == V_37 )
V_2 -> V_105 = 8 ;
else
V_2 -> V_105 = 4 ;
}
if ( V_2 -> V_40 & V_122 )
V_2 -> V_105 = 16 ;
else if ( V_2 -> V_40 & V_126 )
V_2 -> V_105 = 8 ;
if ( V_2 -> V_40 & V_120 ) {
V_92 = F_56 ( V_2 , & V_2 -> V_384 ) ;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_2 -> V_134 ) ;
} else if ( V_2 -> V_40 & V_445 )
V_92 = F_58 ( V_2 , & V_2 -> V_384 ) ;
if ( V_92 != V_90 )
goto V_153;
if ( ! V_2 -> V_49 )
F_21 ( V_2 , V_140 ) ;
V_2 -> V_384 . V_77 . V_152 . V_48 = V_50 ( V_2 ) ;
if ( V_2 -> V_384 . type == V_141 && V_2 -> V_28 != 8 )
V_2 -> V_384 . V_77 . V_152 . V_86 = ( T_3 ) V_2 -> V_384 . V_77 . V_152 . V_86 ;
V_92 = F_200 ( V_2 , & V_2 -> V_22 , ( V_2 -> V_40 >> V_446 ) & V_447 ) ;
if ( V_92 != V_90 )
goto V_153;
V_92 = F_200 ( V_2 , & V_2 -> V_215 , ( V_2 -> V_40 >> V_448 ) & V_447 ) ;
if ( V_92 != V_90 )
goto V_153;
V_92 = F_200 ( V_2 , & V_2 -> V_27 , ( V_2 -> V_40 >> V_449 ) & V_447 ) ;
V_153:
if ( V_2 -> V_386 && V_2 -> V_386 -> type == V_141 && V_2 -> V_151 )
V_2 -> V_386 -> V_77 . V_152 . V_86 += V_2 -> V_44 ;
return ( V_92 != V_90 ) ? V_325 : V_326 ;
}
bool F_203 ( struct V_1 * V_2 )
{
return V_2 -> V_40 & V_450 ;
}
static bool F_204 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_121 == 0xa6 ) || ( V_2 -> V_121 == 0xa7 ) ||
( V_2 -> V_121 == 0xae ) || ( V_2 -> V_121 == 0xaf ) )
&& ( ( ( V_2 -> V_17 == V_451 ) &&
( ( V_2 -> V_170 & V_110 ) == 0 ) )
|| ( ( V_2 -> V_17 == V_452 ) &&
( ( V_2 -> V_170 & V_110 ) == V_110 ) ) ) )
return true ;
return false ;
}
static int F_205 ( struct V_1 * V_2 )
{
bool V_453 = false ;
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
if ( F_42 ( V_453 ) )
return F_23 ( V_2 , V_454 , 0 , false ) ;
return V_90 ;
}
static void F_206 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
if ( V_114 -> type == V_127 )
F_52 ( V_2 , & V_114 -> V_196 , V_114 -> V_77 . V_128 ) ;
}
int F_207 ( struct V_1 * V_2 )
{
const struct V_177 * V_6 = V_2 -> V_6 ;
int V_92 = V_90 ;
int V_455 = V_2 -> V_27 . type ;
V_2 -> V_158 . V_159 = 0 ;
if ( V_2 -> V_36 == V_37 && ( V_2 -> V_40 & V_456 ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_153;
}
if ( V_2 -> V_195 && ( ! ( V_2 -> V_40 & V_457 ) || V_2 -> V_27 . type != V_141 ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_153;
}
if ( ( V_2 -> V_40 & V_458 ) == V_459 && V_2 -> V_22 . type != V_141 ) {
V_92 = F_27 ( V_2 ) ;
goto V_153;
}
if ( ( ( V_2 -> V_40 & ( V_122 | V_126 ) ) && ( ( V_6 -> V_301 ( V_2 , 0 ) & V_460 ) ) )
|| ( ( V_2 -> V_40 & V_122 ) && ! ( V_6 -> V_301 ( V_2 , 4 ) & V_461 ) ) ) {
V_92 = F_27 ( V_2 ) ;
goto V_153;
}
if ( ( V_2 -> V_40 & ( V_122 | V_126 ) ) && ( V_6 -> V_301 ( V_2 , 0 ) & V_324 ) ) {
V_92 = F_30 ( V_2 ) ;
goto V_153;
}
if ( V_2 -> V_40 & V_126 ) {
V_92 = F_205 ( V_2 ) ;
if ( V_92 != V_90 )
goto V_153;
F_206 ( V_2 , & V_2 -> V_22 ) ;
F_206 ( V_2 , & V_2 -> V_215 ) ;
if ( ! ( V_2 -> V_40 & V_462 ) )
F_206 ( V_2 , & V_2 -> V_27 ) ;
}
if ( F_42 ( V_2 -> V_463 ) && V_2 -> V_12 ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_464 ) ;
if ( V_92 != V_90 )
goto V_153;
}
if ( ( V_2 -> V_40 & V_465 ) && V_6 -> V_84 ( V_2 ) ) {
V_92 = F_25 ( V_2 , 0 ) ;
goto V_153;
}
if ( ( V_2 -> V_40 & V_466 ) && V_2 -> V_36 < V_210 ) {
V_92 = F_27 ( V_2 ) ;
goto V_153;
}
if ( V_2 -> V_439 ) {
V_92 = V_2 -> V_439 ( V_2 ) ;
if ( V_92 != V_90 )
goto V_153;
}
if ( F_42 ( V_2 -> V_463 ) && V_2 -> V_12 ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_467 ) ;
if ( V_92 != V_90 )
goto V_153;
}
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
if ( F_13 ( V_2 , F_1 ( V_2 , V_169 ) ) == 0 ) {
V_2 -> V_30 = V_2 -> V_44 ;
goto V_153;
}
}
if ( ( V_2 -> V_22 . type == V_141 ) && ! ( V_2 -> V_40 & V_468 ) ) {
V_92 = F_62 ( V_2 , V_2 -> V_22 . V_77 . V_152 ,
V_2 -> V_22 . V_231 , V_2 -> V_22 . V_25 ) ;
if ( V_92 != V_90 )
goto V_153;
V_2 -> V_22 . V_236 = V_2 -> V_22 . V_23 ;
}
if ( V_2 -> V_215 . type == V_141 ) {
V_92 = F_62 ( V_2 , V_2 -> V_215 . V_77 . V_152 ,
& V_2 -> V_215 . V_115 , V_2 -> V_215 . V_25 ) ;
if ( V_92 != V_90 )
goto V_153;
}
if ( ( V_2 -> V_40 & V_469 ) == V_470 )
goto V_471;
if ( ( V_2 -> V_27 . type == V_141 ) && ! ( V_2 -> V_40 & V_462 ) ) {
V_92 = F_62 ( V_2 , V_2 -> V_27 . V_77 . V_152 ,
& V_2 -> V_27 . V_115 , V_2 -> V_27 . V_25 ) ;
if ( V_92 != V_90 )
goto V_153;
}
V_2 -> V_27 . V_131 = V_2 -> V_27 . V_115 ;
V_471:
if ( F_42 ( V_2 -> V_463 ) && V_2 -> V_12 ) {
V_92 = F_7 ( V_2 , V_2 -> V_12 ,
V_472 ) ;
if ( V_92 != V_90 )
goto V_153;
}
if ( V_2 -> V_438 ) {
V_92 = V_2 -> V_438 ( V_2 ) ;
if ( V_92 != V_90 )
goto V_153;
goto F_74;
}
if ( V_2 -> V_421 )
goto V_473;
switch ( V_2 -> V_121 ) {
case 0x40 ... 0x47 :
F_98 ( V_2 , L_13 ) ;
break;
case 0x48 ... 0x4f :
F_98 ( V_2 , L_14 ) ;
break;
case 0x63 :
if ( V_2 -> V_36 != V_37 )
goto V_474;
V_2 -> V_27 . V_115 = ( V_150 ) V_2 -> V_22 . V_115 ;
break;
case 0x70 ... 0x7f :
if ( F_46 ( V_2 -> V_121 , V_2 -> V_170 ) )
F_18 ( V_2 , V_2 -> V_22 . V_115 ) ;
break;
case 0x8d :
V_2 -> V_27 . V_115 = V_2 -> V_22 . V_77 . V_152 . V_86 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_27 . V_77 . V_9 == F_3 ( V_2 , V_218 ) )
break;
V_92 = F_143 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_105 ) {
case 2 : V_2 -> V_27 . V_115 = ( V_149 ) V_2 -> V_27 . V_115 ; break;
case 4 : V_2 -> V_27 . V_115 = ( V_155 ) V_2 -> V_27 . V_115 ; break;
case 8 : V_2 -> V_27 . V_115 = ( V_150 ) V_2 -> V_27 . V_115 ; break;
}
break;
case 0xc0 ... 0xc1 :
V_92 = F_94 ( V_2 ) ;
break;
case 0xcc :
V_92 = F_90 ( V_2 , 3 ) ;
break;
case 0xcd :
V_92 = F_90 ( V_2 , V_2 -> V_22 . V_115 ) ;
break;
case 0xce :
if ( V_2 -> V_170 & V_108 )
V_92 = F_90 ( V_2 , 4 ) ;
break;
case 0xd0 ... 0xd1 :
V_92 = F_94 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_2 -> V_22 . V_115 = F_1 ( V_2 , V_169 ) ;
V_92 = F_94 ( V_2 ) ;
break;
case 0xe9 :
case 0xeb :
F_18 ( V_2 , V_2 -> V_22 . V_115 ) ;
V_2 -> V_27 . type = V_197 ;
break;
case 0xf4 :
V_2 -> V_6 -> V_475 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_170 ^= V_109 ;
break;
case 0xf8 :
V_2 -> V_170 &= ~ V_109 ;
break;
case 0xf9 :
V_2 -> V_170 |= V_109 ;
break;
case 0xfc :
V_2 -> V_170 &= ~ V_171 ;
break;
case 0xfd :
V_2 -> V_170 |= V_171 ;
break;
default:
goto V_474;
}
if ( V_92 != V_90 )
goto V_153;
F_74:
V_92 = F_74 ( V_2 ) ;
if ( V_92 != V_90 )
goto V_153;
V_2 -> V_27 . type = V_455 ;
if ( ( V_2 -> V_40 & V_458 ) == V_476 )
F_129 ( V_2 , V_146 , & V_2 -> V_22 ) ;
if ( ( V_2 -> V_40 & V_469 ) == V_477 )
F_129 ( V_2 , V_148 , & V_2 -> V_27 ) ;
if ( V_2 -> V_17 && ( V_2 -> V_40 & String ) ) {
unsigned int V_168 ;
struct V_156 * V_273 = & V_2 -> V_165 ;
if ( ( V_2 -> V_40 & V_458 ) == V_476 )
V_168 = V_2 -> V_22 . V_168 ;
else
V_168 = V_2 -> V_27 . V_168 ;
F_16 ( V_2 , F_3 ( V_2 , V_169 ) ,
- V_168 ) ;
if ( ! F_204 ( V_2 ) ) {
if ( ( V_273 -> V_97 != 0 || F_1 ( V_2 , V_169 ) & 0x3ff ) &&
( V_273 -> V_97 == 0 || V_273 -> V_97 != V_273 -> V_159 ) ) {
V_2 -> V_158 . V_97 = 0 ;
F_4 ( V_2 ) ;
return V_478 ;
}
goto V_153;
}
}
V_2 -> V_30 = V_2 -> V_44 ;
V_153:
if ( V_92 == V_59 )
V_2 -> V_479 = true ;
if ( V_92 == V_480 )
return V_481 ;
if ( V_92 == V_90 )
F_4 ( V_2 ) ;
return ( V_92 == V_101 ) ? V_325 : V_326 ;
V_473:
switch ( V_2 -> V_121 ) {
case 0x09 :
( V_2 -> V_6 -> V_482 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_27 . V_115 = V_6 -> V_301 ( V_2 , V_2 -> V_19 ) ;
break;
case 0x21 :
V_6 -> V_372 ( V_2 , V_2 -> V_19 , & V_2 -> V_27 . V_115 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_27 . V_115 = V_2 -> V_27 . V_131 = V_2 -> V_22 . V_115 ;
if ( ! F_46 ( V_2 -> V_121 , V_2 -> V_170 ) )
V_2 -> V_27 . type = V_197 ;
break;
case 0x80 ... 0x8f :
if ( F_46 ( V_2 -> V_121 , V_2 -> V_170 ) )
F_18 ( V_2 , V_2 -> V_22 . V_115 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_27 . V_115 = F_46 ( V_2 -> V_121 , V_2 -> V_170 ) ;
break;
case 0xa4 :
case 0xa5 :
F_208 ( V_2 , L_30 ) ;
break;
case 0xac :
case 0xad :
F_208 ( V_2 , L_31 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
V_2 -> V_27 . V_115 = ( V_2 -> V_22 . V_25 == 1 ) ? ( T_4 ) V_2 -> V_22 . V_115
: ( T_2 ) V_2 -> V_22 . V_115 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
V_2 -> V_27 . V_115 = ( V_2 -> V_22 . V_25 == 1 ) ? ( V_149 ) V_2 -> V_22 . V_115 :
( V_155 ) V_2 -> V_22 . V_115 ;
break;
case 0xc0 ... 0xc1 :
F_109 ( V_2 , L_17 ) ;
V_2 -> V_22 . V_115 = V_2 -> V_27 . V_131 ;
F_73 ( & V_2 -> V_22 ) ;
break;
case 0xc3 :
V_2 -> V_27 . V_25 = V_2 -> V_105 ;
V_2 -> V_27 . V_115 = ( V_2 -> V_105 == 4 ) ? ( T_3 ) V_2 -> V_22 . V_115 :
( V_116 ) V_2 -> V_22 . V_115 ;
break;
default:
goto V_474;
}
if ( V_92 != V_90 )
goto V_153;
goto F_74;
V_474:
return V_325 ;
}
void F_209 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
}
void F_210 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
}
