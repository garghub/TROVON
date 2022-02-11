static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
struct V_7 V_8 = {
. V_4 = V_4 ,
. V_9 = V_2 -> V_9 ,
. V_10 = V_2 -> V_10 ,
. V_11 = V_2 -> V_11 ,
. V_12 = V_2 -> V_12 ,
. V_13 = V_2 -> V_14 . V_15 ,
. V_16 = V_2 -> V_14 . V_17 ,
. V_18 = V_2 -> V_19 . V_17 ,
. V_20 = V_2 -> V_20 ,
. V_21 = V_2 -> V_22 ,
} ;
return V_2 -> V_23 -> V_4 ( V_2 , & V_8 , V_6 ) ;
}
static inline unsigned long F_2 ( struct V_1 * V_2 )
{
return ( 1UL << ( V_2 -> V_20 << 3 ) ) - 1 ;
}
static inline unsigned long
F_3 ( struct V_1 * V_2 , unsigned long V_24 )
{
if ( V_2 -> V_20 == sizeof( unsigned long ) )
return V_24 ;
else
return V_24 & F_2 ( V_2 ) ;
}
static inline unsigned long
F_4 ( struct V_1 * V_2 , unsigned long V_24 )
{
return F_3 ( V_2 , V_24 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 , unsigned long * V_24 , int V_25 )
{
if ( V_2 -> V_20 == sizeof( unsigned long ) )
* V_24 += V_25 ;
else
* V_24 = ( * V_24 & ~ F_2 ( V_2 ) ) | ( ( * V_24 + V_25 ) & F_2 ( V_2 ) ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_26 )
{
F_5 ( V_2 , & V_2 -> V_27 , V_26 ) ;
}
static T_1 F_7 ( struct V_28 * V_29 )
{
T_1 V_30 = F_8 ( V_29 ) ;
return V_29 -> V_31 ? ( V_30 << 12 ) | 0xfff : V_30 ;
}
static void F_9 ( struct V_1 * V_2 , int V_32 )
{
V_2 -> V_33 = true ;
V_2 -> V_34 = V_32 ;
}
static unsigned long F_10 ( struct V_1 * V_2 , int V_32 )
{
if ( V_2 -> V_35 == V_36 && V_32 < V_37 )
return 0 ;
return V_2 -> V_23 -> V_38 ( V_2 , V_32 ) ;
}
static unsigned V_34 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_33 )
return 0 ;
return V_2 -> V_34 ;
}
static int F_11 ( struct V_1 * V_2 , int V_39 ,
T_1 error , bool V_40 )
{
V_2 -> V_41 . V_42 = V_39 ;
V_2 -> V_41 . V_43 = error ;
V_2 -> V_41 . V_44 = V_40 ;
return V_45 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_46 , 0 , false ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_47 )
{
return F_11 ( V_2 , V_48 , V_47 , true ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_47 )
{
return F_11 ( V_2 , V_49 , V_47 , true ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_50 , 0 , false ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_47 )
{
return F_11 ( V_2 , V_51 , V_47 , true ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_52 , 0 , false ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_53 , 0 , false ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , unsigned V_32 )
{
T_2 V_54 ;
struct V_28 V_29 ;
V_2 -> V_23 -> V_55 ( V_2 , & V_54 , & V_29 , NULL , V_32 ) ;
return V_54 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_54 ,
unsigned V_32 )
{
T_2 V_56 ;
T_1 V_57 ;
struct V_28 V_29 ;
V_2 -> V_23 -> V_55 ( V_2 , & V_56 , & V_29 , & V_57 , V_32 ) ;
V_2 -> V_23 -> V_58 ( V_2 , V_54 , & V_29 , V_57 , V_32 ) ;
}
static bool F_21 ( struct V_1 * V_2 , unsigned V_59 )
{
if ( F_22 ( V_59 < 16 ) )
return false ;
if ( V_2 -> V_60 & V_61 )
return true ;
else if ( V_2 -> V_60 & V_62 )
return false ;
else if ( V_2 -> V_60 & V_63 )
return false ;
else
return true ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
unsigned V_59 , bool V_66 , bool V_67 ,
T_3 * V_68 )
{
struct V_28 V_29 ;
bool V_69 ;
T_3 V_70 ;
T_1 V_71 ;
T_2 V_72 ;
unsigned V_73 , V_74 ;
V_70 = F_10 ( V_2 , V_65 . V_32 ) + V_65 . V_75 ;
switch ( V_2 -> V_35 ) {
case V_76 :
break;
case V_36 :
if ( ( ( signed long ) V_70 << 16 ) >> 16 != V_70 )
return F_13 ( V_2 , 0 ) ;
break;
default:
V_69 = V_2 -> V_23 -> V_55 ( V_2 , & V_72 , & V_29 , NULL ,
V_65 . V_32 ) ;
if ( ! V_69 )
goto V_77;
if ( ( ( V_29 . type & 8 ) || ! ( V_29 . type & 2 ) ) && V_66 )
goto V_77;
if ( ! V_67 && ( V_29 . type & 8 ) && ! ( V_29 . type & 2 ) )
goto V_77;
V_71 = F_7 ( & V_29 ) ;
if ( ( V_29 . type & 8 ) || ! ( V_29 . type & 4 ) ) {
if ( V_65 . V_75 > V_71 || ( T_1 ) ( V_65 . V_75 + V_59 - 1 ) > V_71 )
goto V_77;
} else {
if ( V_65 . V_75 <= V_71 || ( T_1 ) ( V_65 . V_75 + V_59 - 1 ) <= V_71 )
goto V_77;
V_71 = V_29 . V_60 ? 0xffffffff : 0xffff ;
if ( V_65 . V_75 > V_71 || ( T_1 ) ( V_65 . V_75 + V_59 - 1 ) > V_71 )
goto V_77;
}
V_73 = V_2 -> V_23 -> V_73 ( V_2 ) ;
V_74 = V_72 & 3 ;
V_73 = F_24 ( V_73 , V_74 ) ;
if ( ! ( V_29 . type & 8 ) ) {
if ( V_73 > V_29 . V_78 )
goto V_77;
} else if ( ( V_29 . type & 8 ) && ! ( V_29 . type & 4 ) ) {
if ( V_73 != V_29 . V_78 )
goto V_77;
} else if ( ( V_29 . type & 8 ) && ( V_29 . type & 4 ) ) {
if ( V_73 < V_29 . V_78 )
goto V_77;
}
break;
}
if ( V_67 ? V_2 -> V_35 != V_36 : V_2 -> V_20 != 8 )
V_70 &= ( T_1 ) - 1 ;
if ( F_21 ( V_2 , V_59 ) && ( ( V_70 & ( V_59 - 1 ) ) != 0 ) )
return F_13 ( V_2 , 0 ) ;
* V_68 = V_70 ;
return V_79 ;
V_77:
if ( V_65 . V_32 == V_80 )
return F_14 ( V_2 , V_65 . V_32 ) ;
else
return F_13 ( V_2 , V_65 . V_32 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
unsigned V_59 , bool V_66 ,
T_3 * V_68 )
{
return F_23 ( V_2 , V_65 , V_59 , V_66 , false , V_68 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
void * V_81 ,
unsigned V_59 )
{
int V_82 ;
T_3 V_68 ;
V_82 = F_25 ( V_2 , V_65 , V_59 , false , & V_68 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_23 -> V_83 ( V_2 , V_68 , V_81 , V_59 , & V_2 -> V_41 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_4 * V_84 )
{
struct V_85 * V_86 = & V_2 -> V_67 ;
int V_82 ;
int V_59 , V_87 ;
if ( V_2 -> V_27 == V_86 -> V_88 ) {
unsigned long V_68 ;
struct V_64 V_65 = { . V_32 = V_89 ,
. V_75 = V_2 -> V_27 } ;
V_87 = V_86 -> V_88 - V_86 -> V_90 ;
V_59 = F_28 ( 15UL - V_87 ,
V_91 - F_29 ( V_2 -> V_27 ) ) ;
V_82 = F_23 ( V_2 , V_65 , V_59 , false , true , & V_68 ) ;
if ( F_30 ( V_82 != V_79 ) )
return V_82 ;
V_82 = V_2 -> V_23 -> V_67 ( V_2 , V_68 , V_86 -> V_81 + V_87 ,
V_59 , & V_2 -> V_41 ) ;
if ( F_30 ( V_82 != V_79 ) )
return V_82 ;
V_86 -> V_88 += V_59 ;
}
* V_84 = V_86 -> V_81 [ V_2 -> V_27 - V_86 -> V_90 ] ;
V_2 -> V_27 ++ ;
return V_79 ;
}
static int F_31 ( struct V_1 * V_2 ,
void * V_84 , unsigned V_59 )
{
int V_82 ;
if ( F_30 ( V_2 -> V_27 + V_59 - V_2 -> V_22 > 15 ) )
return V_92 ;
while ( V_59 -- ) {
V_82 = F_27 ( V_2 , V_84 ++ ) ;
if ( V_82 != V_79 )
return V_82 ;
}
return V_79 ;
}
static void * F_32 ( T_4 V_11 , unsigned long * V_93 ,
int V_94 )
{
void * V_95 ;
V_95 = & V_93 [ V_11 ] ;
if ( V_94 && V_11 >= 4 && V_11 < 8 )
V_95 = ( unsigned char * ) & V_93 [ V_11 & 3 ] + 1 ;
return V_95 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
T_2 * V_59 , unsigned long * V_96 , int V_97 )
{
int V_82 ;
if ( V_97 == 2 )
V_97 = 3 ;
* V_96 = 0 ;
V_82 = F_26 ( V_2 , V_65 , V_59 , 2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_65 . V_75 += 2 ;
V_82 = F_26 ( V_2 , V_65 , V_96 , V_97 ) ;
return V_82 ;
}
static int F_34 ( unsigned int V_98 , unsigned int V_99 )
{
int V_82 = 0 ;
switch ( ( V_98 & 15 ) >> 1 ) {
case 0 :
V_82 |= ( V_99 & V_100 ) ;
break;
case 1 :
V_82 |= ( V_99 & V_101 ) ;
break;
case 2 :
V_82 |= ( V_99 & V_102 ) ;
break;
case 3 :
V_82 |= ( V_99 & ( V_101 | V_102 ) ) ;
break;
case 4 :
V_82 |= ( V_99 & V_103 ) ;
break;
case 5 :
V_82 |= ( V_99 & V_104 ) ;
break;
case 7 :
V_82 |= ( V_99 & V_102 ) ;
case 6 :
V_82 |= ( ! ( V_99 & V_103 ) != ! ( V_99 & V_100 ) ) ;
break;
}
return ( ! ! V_82 ^ ( V_98 & 1 ) ) ;
}
static void F_35 ( struct V_105 * V_106 )
{
switch ( V_106 -> V_17 ) {
case 1 :
V_106 -> V_107 = * ( T_4 * ) V_106 -> V_65 . V_24 ;
break;
case 2 :
V_106 -> V_107 = * ( T_2 * ) V_106 -> V_65 . V_24 ;
break;
case 4 :
V_106 -> V_107 = * ( T_1 * ) V_106 -> V_65 . V_24 ;
break;
case 8 :
V_106 -> V_107 = * ( V_108 * ) V_106 -> V_65 . V_24 ;
break;
}
}
static void F_36 ( struct V_1 * V_2 , T_5 * V_81 , int V_24 )
{
V_2 -> V_23 -> V_109 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movdqu %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqu %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqu %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqu %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqu %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqu %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqu %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqu %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_37
case 8 : asm("movdqu %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqu %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqu %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqu %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqu %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqu %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqu %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqu %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_38 () ;
}
V_2 -> V_23 -> V_110 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_5 * V_81 ,
int V_24 )
{
V_2 -> V_23 -> V_109 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movdqu %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqu %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqu %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqu %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqu %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqu %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqu %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqu %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_37
case 8 : asm("movdqu %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqu %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqu %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqu %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqu %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqu %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqu %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqu %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_38 () ;
}
V_2 -> V_23 -> V_110 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 , V_108 * V_81 , int V_24 )
{
V_2 -> V_23 -> V_109 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_38 () ;
}
V_2 -> V_23 -> V_110 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 , V_108 * V_81 , int V_24 )
{
V_2 -> V_23 -> V_109 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_38 () ;
}
V_2 -> V_23 -> V_110 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
unsigned V_24 = V_2 -> V_11 ;
int V_94 = V_2 -> V_111 == 0 ;
if ( ! ( V_2 -> V_60 & V_112 ) )
V_24 = ( V_2 -> V_113 & 7 ) | ( ( V_2 -> V_111 & 1 ) << 3 ) ;
if ( V_2 -> V_60 & V_114 ) {
V_106 -> type = V_115 ;
V_106 -> V_17 = 16 ;
V_106 -> V_65 . V_116 = V_24 ;
F_36 ( V_2 , & V_106 -> V_117 , V_24 ) ;
return;
}
if ( V_2 -> V_60 & V_118 ) {
V_24 &= 7 ;
V_106 -> type = V_119 ;
V_106 -> V_17 = 8 ;
V_106 -> V_65 . V_120 = V_24 ;
return;
}
V_106 -> type = V_121 ;
if ( V_2 -> V_60 & V_122 ) {
V_106 -> V_65 . V_24 = F_32 ( V_24 , V_2 -> V_93 , V_94 ) ;
V_106 -> V_17 = 1 ;
} else {
V_106 -> V_65 . V_24 = F_32 ( V_24 , V_2 -> V_93 , 0 ) ;
V_106 -> V_17 = V_2 -> V_97 ;
}
F_35 ( V_106 ) ;
V_106 -> V_123 = V_106 -> V_107 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
T_4 V_124 ;
int V_125 = 0 , V_126 = 0 , V_127 ;
int V_82 = V_79 ;
T_3 V_128 = 0 ;
if ( V_2 -> V_111 ) {
V_2 -> V_11 = ( V_2 -> V_111 & 4 ) << 1 ;
V_125 = ( V_2 -> V_111 & 2 ) << 2 ;
V_2 -> V_12 = V_126 = ( V_2 -> V_111 & 1 ) << 3 ;
}
V_2 -> V_10 |= ( V_2 -> V_129 & 0xc0 ) >> 6 ;
V_2 -> V_11 |= ( V_2 -> V_129 & 0x38 ) >> 3 ;
V_2 -> V_12 |= ( V_2 -> V_129 & 0x07 ) ;
V_2 -> V_130 = V_131 ;
if ( V_2 -> V_10 == 3 ) {
V_106 -> type = V_121 ;
V_106 -> V_17 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
V_106 -> V_65 . V_24 = F_32 ( V_2 -> V_12 ,
V_2 -> V_93 , V_2 -> V_60 & V_122 ) ;
if ( V_2 -> V_60 & V_114 ) {
V_106 -> type = V_115 ;
V_106 -> V_17 = 16 ;
V_106 -> V_65 . V_116 = V_2 -> V_12 ;
F_36 ( V_2 , & V_106 -> V_117 , V_2 -> V_12 ) ;
return V_82 ;
}
if ( V_2 -> V_60 & V_118 ) {
V_106 -> type = V_119 ;
V_106 -> V_17 = 8 ;
V_106 -> V_65 . V_116 = V_2 -> V_12 & 7 ;
return V_82 ;
}
F_35 ( V_106 ) ;
return V_82 ;
}
V_106 -> type = V_132 ;
if ( V_2 -> V_20 == 2 ) {
unsigned V_133 = V_2 -> V_93 [ V_134 ] ;
unsigned V_135 = V_2 -> V_93 [ V_136 ] ;
unsigned V_137 = V_2 -> V_93 [ V_138 ] ;
unsigned V_139 = V_2 -> V_93 [ V_140 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 6 )
V_128 += F_44 ( T_2 , V_2 ) ;
break;
case 1 :
V_128 += F_44 ( V_141 , V_2 ) ;
break;
case 2 :
V_128 += F_44 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_12 ) {
case 0 :
V_128 += V_133 + V_137 ;
break;
case 1 :
V_128 += V_133 + V_139 ;
break;
case 2 :
V_128 += V_135 + V_137 ;
break;
case 3 :
V_128 += V_135 + V_139 ;
break;
case 4 :
V_128 += V_137 ;
break;
case 5 :
V_128 += V_139 ;
break;
case 6 :
if ( V_2 -> V_10 != 0 )
V_128 += V_135 ;
break;
case 7 :
V_128 += V_133 ;
break;
}
if ( V_2 -> V_12 == 2 || V_2 -> V_12 == 3 ||
( V_2 -> V_12 == 6 && V_2 -> V_10 != 0 ) )
V_2 -> V_130 = V_80 ;
V_128 = ( T_2 ) V_128 ;
} else {
if ( ( V_2 -> V_12 & 7 ) == 4 ) {
V_124 = F_44 ( T_4 , V_2 ) ;
V_125 |= ( V_124 >> 3 ) & 7 ;
V_126 |= V_124 & 7 ;
V_127 = V_124 >> 6 ;
if ( ( V_126 & 7 ) == 5 && V_2 -> V_10 == 0 )
V_128 += F_44 ( V_142 , V_2 ) ;
else
V_128 += V_2 -> V_93 [ V_126 ] ;
if ( V_125 != 4 )
V_128 += V_2 -> V_93 [ V_125 ] << V_127 ;
} else if ( ( V_2 -> V_12 & 7 ) == 5 && V_2 -> V_10 == 0 ) {
if ( V_2 -> V_35 == V_36 )
V_2 -> V_143 = 1 ;
} else
V_128 += V_2 -> V_93 [ V_2 -> V_12 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 5 )
V_128 += F_44 ( V_142 , V_2 ) ;
break;
case 1 :
V_128 += F_44 ( V_141 , V_2 ) ;
break;
case 2 :
V_128 += F_44 ( V_142 , V_2 ) ;
break;
}
}
V_106 -> V_65 . V_144 . V_75 = V_128 ;
V_145:
return V_82 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
int V_82 = V_79 ;
V_106 -> type = V_132 ;
switch ( V_2 -> V_20 ) {
case 2 :
V_106 -> V_65 . V_144 . V_75 = F_44 ( T_2 , V_2 ) ;
break;
case 4 :
V_106 -> V_65 . V_144 . V_75 = F_44 ( T_1 , V_2 ) ;
break;
case 8 :
V_106 -> V_65 . V_144 . V_75 = F_44 ( V_108 , V_2 ) ;
break;
}
V_145:
return V_82 ;
}
static void F_46 ( struct V_1 * V_2 )
{
long V_146 = 0 , V_147 ;
if ( V_2 -> V_19 . type == V_132 && V_2 -> V_14 . type == V_121 ) {
V_147 = ~ ( V_2 -> V_19 . V_17 * 8 - 1 ) ;
if ( V_2 -> V_14 . V_17 == 2 )
V_146 = ( V_148 ) V_2 -> V_14 . V_107 & ( V_148 ) V_147 ;
else if ( V_2 -> V_14 . V_17 == 4 )
V_146 = ( V_142 ) V_2 -> V_14 . V_107 & ( V_142 ) V_147 ;
V_2 -> V_19 . V_65 . V_144 . V_75 += ( V_146 >> 3 ) ;
}
V_2 -> V_14 . V_107 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned long V_65 , void * V_84 , unsigned V_59 )
{
int V_82 ;
struct V_149 * V_150 = & V_2 -> V_151 ;
while ( V_59 ) {
int V_152 = F_28 ( V_59 , 8u ) ;
V_59 -= V_152 ;
if ( V_150 -> V_153 < V_150 -> V_88 )
goto V_154;
V_82 = V_2 -> V_23 -> F_47 ( V_2 , V_65 , V_150 -> V_81 + V_150 -> V_88 , V_152 ,
& V_2 -> V_41 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_150 -> V_88 += V_152 ;
V_154:
memcpy ( V_84 , V_150 -> V_81 + V_150 -> V_153 , V_152 ) ;
V_150 -> V_153 += V_152 ;
V_84 += V_152 ;
V_65 += V_152 ;
}
return V_79 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
void * V_81 ,
unsigned V_59 )
{
int V_82 ;
T_3 V_68 ;
V_82 = F_25 ( V_2 , V_65 , V_59 , false , & V_68 ) ;
if ( V_82 != V_79 )
return V_82 ;
return F_47 ( V_2 , V_68 , V_81 , V_59 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
const void * V_81 ,
unsigned V_59 )
{
int V_82 ;
T_3 V_68 ;
V_82 = F_25 ( V_2 , V_65 , V_59 , true , & V_68 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_23 -> V_155 ( V_2 , V_68 , V_81 , V_59 ,
& V_2 -> V_41 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_64 V_65 ,
const void * V_156 , const void * V_81 ,
unsigned V_59 )
{
int V_82 ;
T_3 V_68 ;
V_82 = F_25 ( V_2 , V_65 , V_59 , true , & V_68 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_23 -> V_157 ( V_2 , V_68 , V_156 , V_81 ,
V_59 , & V_2 -> V_41 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_59 , unsigned short V_158 ,
void * V_84 )
{
struct V_149 * V_82 = & V_2 -> V_159 ;
if ( V_82 -> V_153 == V_82 -> V_88 ) {
unsigned int V_160 , V_152 ;
unsigned int V_161 = V_2 -> V_9 ?
F_3 ( V_2 , V_2 -> V_93 [ V_162 ] ) : 1 ;
V_160 = ( V_2 -> V_163 & V_164 ) ?
F_29 ( V_2 -> V_93 [ V_140 ] ) :
V_91 - F_29 ( V_2 -> V_93 [ V_140 ] ) ;
V_152 = F_28 ( F_28 ( V_160 , ( unsigned int ) sizeof( V_82 -> V_81 ) ) / V_59 ,
V_161 ) ;
if ( V_152 == 0 )
V_152 = 1 ;
V_82 -> V_153 = V_82 -> V_88 = 0 ;
if ( ! V_2 -> V_23 -> F_51 ( V_2 , V_59 , V_158 , V_82 -> V_81 , V_152 ) )
return 0 ;
V_82 -> V_88 = V_152 * V_59 ;
}
memcpy ( V_84 , V_82 -> V_81 + V_82 -> V_153 , V_59 ) ;
V_82 -> V_153 += V_59 ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 ,
T_2 V_165 , struct V_28 * V_29 )
{
struct V_166 V_167 ;
T_3 V_65 ;
V_2 -> V_23 -> V_168 ( V_2 , & V_167 ) ;
if ( V_167 . V_59 < V_165 * 8 + 7 )
return F_13 ( V_2 , V_165 << 3 | 0x2 ) ;
V_65 = V_167 . V_96 + V_165 * 8 ;
return V_2 -> V_23 -> V_83 ( V_2 , V_65 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_166 * V_167 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
if ( V_54 & 1 << 2 ) {
struct V_28 V_29 ;
T_2 V_72 ;
memset ( V_167 , 0 , sizeof *V_167 ) ;
if ( ! V_23 -> V_55 ( V_2 , & V_72 , & V_29 , NULL , V_170 ) )
return;
V_167 -> V_59 = F_7 ( & V_29 ) ;
V_167 -> V_96 = F_54 ( & V_29 ) ;
} else
V_23 -> V_171 ( V_2 , V_167 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_166 V_167 ;
T_2 V_165 = V_54 >> 3 ;
T_3 V_65 ;
F_53 ( V_2 , V_54 , & V_167 ) ;
if ( V_167 . V_59 < V_165 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_65 = V_167 . V_96 + V_165 * 8 ;
return V_2 -> V_23 -> V_83 ( V_2 , V_65 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_166 V_167 ;
T_2 V_165 = V_54 >> 3 ;
T_3 V_65 ;
F_53 ( V_2 , V_54 , & V_167 ) ;
if ( V_167 . V_59 < V_165 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_65 = V_167 . V_96 + V_165 * 8 ;
return V_2 -> V_23 -> V_172 ( V_2 , V_65 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
T_2 V_54 , int V_32 )
{
struct V_28 V_173 ;
T_4 V_78 , V_74 , V_73 ;
unsigned V_174 = V_48 ;
T_1 V_175 = 0 ;
bool V_176 = ! ( V_54 & ~ 0x3 ) ;
int V_177 ;
memset ( & V_173 , 0 , sizeof V_173 ) ;
if ( ( V_32 <= V_178 && V_2 -> V_35 == V_179 )
|| V_2 -> V_35 == V_76 ) {
F_58 ( & V_173 , V_54 << 4 ) ;
F_59 ( & V_173 , 0xffff ) ;
V_173 . type = 3 ;
V_173 . V_95 = 1 ;
V_173 . V_180 = 1 ;
if ( V_2 -> V_35 == V_179 )
V_173 . V_78 = 3 ;
goto V_181;
}
if ( ( V_32 == V_89 || V_32 == V_80 || V_32 == V_182 )
&& V_176 )
goto V_41;
if ( V_32 == V_182 && ( V_54 & ( 1 << 2 ) ) )
goto V_41;
if ( V_176 )
goto V_181;
V_177 = F_55 ( V_2 , V_54 , & V_173 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_175 = V_54 & 0xfffc ;
V_174 = V_48 ;
if ( V_32 <= V_178 && ! V_173 . V_180 )
goto V_41;
if ( ! V_173 . V_95 ) {
V_174 = ( V_32 == V_80 ) ? V_49 : V_183 ;
goto V_41;
}
V_74 = V_54 & 3 ;
V_78 = V_173 . V_78 ;
V_73 = V_2 -> V_23 -> V_73 ( V_2 ) ;
switch ( V_32 ) {
case V_80 :
if ( V_74 != V_73 || ( V_173 . type & 0xa ) != 0x2 || V_78 != V_73 )
goto V_41;
break;
case V_89 :
if ( ! ( V_173 . type & 8 ) )
goto V_41;
if ( V_173 . type & 4 ) {
if ( V_78 > V_73 )
goto V_41;
} else {
if ( V_74 > V_73 || V_78 != V_73 )
goto V_41;
}
V_54 = ( V_54 & 0xfffc ) | V_73 ;
break;
case V_182 :
if ( V_173 . V_180 || ( V_173 . type != 1 && V_173 . type != 9 ) )
goto V_41;
break;
case V_170 :
if ( V_173 . V_180 || V_173 . type != 2 )
goto V_41;
break;
default:
if ( ( V_173 . type & 0xa ) == 0x8 ||
( ( ( V_173 . type & 0xc ) != 0xc ) &&
( V_74 > V_78 && V_73 > V_78 ) ) )
goto V_41;
break;
}
if ( V_173 . V_180 ) {
V_173 . type |= 1 ;
V_177 = F_56 ( V_2 , V_54 , & V_173 ) ;
if ( V_177 != V_79 )
return V_177 ;
}
V_181:
V_2 -> V_23 -> V_58 ( V_2 , V_54 , & V_173 , 0 , V_32 ) ;
return V_79 ;
V_41:
F_11 ( V_2 , V_174 , V_175 , true ) ;
return V_45 ;
}
static void F_60 ( struct V_105 * V_106 )
{
switch ( V_106 -> V_17 ) {
case 1 :
* ( T_4 * ) V_106 -> V_65 . V_24 = ( T_4 ) V_106 -> V_107 ;
break;
case 2 :
* ( T_2 * ) V_106 -> V_65 . V_24 = ( T_2 ) V_106 -> V_107 ;
break;
case 4 :
* V_106 -> V_65 . V_24 = ( T_1 ) V_106 -> V_107 ;
break;
case 8 :
* V_106 -> V_65 . V_24 = V_106 -> V_107 ;
break;
}
}
static int F_61 ( struct V_1 * V_2 )
{
int V_82 ;
switch ( V_2 -> V_19 . type ) {
case V_121 :
F_60 ( & V_2 -> V_19 ) ;
break;
case V_132 :
if ( V_2 -> V_184 )
V_82 = F_50 ( V_2 ,
V_2 -> V_19 . V_65 . V_144 ,
& V_2 -> V_19 . V_123 ,
& V_2 -> V_19 . V_107 ,
V_2 -> V_19 . V_17 ) ;
else
V_82 = F_49 ( V_2 ,
V_2 -> V_19 . V_65 . V_144 ,
& V_2 -> V_19 . V_107 ,
V_2 -> V_19 . V_17 ) ;
if ( V_82 != V_79 )
return V_82 ;
break;
case V_115 :
F_39 ( V_2 , & V_2 -> V_19 . V_117 , V_2 -> V_19 . V_65 . V_116 ) ;
break;
case V_119 :
F_41 ( V_2 , & V_2 -> V_19 . V_185 , V_2 -> V_19 . V_65 . V_120 ) ;
break;
case V_186 :
break;
default:
break;
}
return V_79 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_64 V_65 ;
F_5 ( V_2 , & V_2 -> V_93 [ V_187 ] , - V_2 -> V_97 ) ;
V_65 . V_75 = F_4 ( V_2 , V_2 -> V_93 [ V_187 ] ) ;
V_65 . V_32 = V_80 ;
V_2 -> V_19 . type = V_186 ;
return F_49 ( V_2 , V_65 , & V_2 -> V_14 . V_107 , V_2 -> V_97 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
void * V_84 , int V_188 )
{
int V_82 ;
struct V_64 V_65 ;
V_65 . V_75 = F_4 ( V_2 , V_2 -> V_93 [ V_187 ] ) ;
V_65 . V_32 = V_80 ;
V_82 = F_48 ( V_2 , V_65 , V_84 , V_188 ) ;
if ( V_82 != V_79 )
return V_82 ;
F_5 ( V_2 , & V_2 -> V_93 [ V_187 ] , V_188 ) ;
return V_82 ;
}
static int F_64 ( struct V_1 * V_2 )
{
return F_63 ( V_2 , & V_2 -> V_19 . V_107 , V_2 -> V_97 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
void * V_84 , int V_188 )
{
int V_82 ;
unsigned long V_107 , V_189 ;
int V_190 = ( V_2 -> V_163 & V_191 ) >> V_192 ;
int V_73 = V_2 -> V_23 -> V_73 ( V_2 ) ;
V_82 = F_63 ( V_2 , & V_107 , V_188 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_189 = V_101 | V_104 | V_193 | V_102 | V_103 | V_100
| V_194 | V_164 | V_195 | V_196 | V_197 | V_198 ;
switch( V_2 -> V_35 ) {
case V_36 :
case V_199 :
case V_200 :
if ( V_73 == 0 )
V_189 |= V_201 ;
if ( V_73 <= V_190 )
V_189 |= V_202 ;
break;
case V_179 :
if ( V_190 < 3 )
return F_13 ( V_2 , 0 ) ;
V_189 |= V_202 ;
break;
default:
V_189 |= ( V_201 | V_202 ) ;
break;
}
* ( unsigned long * ) V_84 =
( V_2 -> V_163 & ~ V_189 ) | ( V_107 & V_189 ) ;
return V_82 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_121 ;
V_2 -> V_19 . V_65 . V_24 = & V_2 -> V_163 ;
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
return F_65 ( V_2 , & V_2 -> V_19 . V_107 , V_2 -> V_97 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_203 . V_107 ;
V_2 -> V_14 . V_107 = F_19 ( V_2 , V_32 ) ;
return F_62 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_203 . V_107 ;
unsigned long V_54 ;
int V_82 ;
V_82 = F_63 ( V_2 , & V_54 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_57 ( V_2 , ( T_2 ) V_54 , V_32 ) ;
return V_82 ;
}
static int F_69 ( struct V_1 * V_2 )
{
unsigned long V_204 = V_2 -> V_93 [ V_187 ] ;
int V_82 = V_79 ;
int V_24 = V_205 ;
while ( V_24 <= V_140 ) {
( V_24 == V_187 ) ?
( V_2 -> V_14 . V_107 = V_204 ) : ( V_2 -> V_14 . V_107 = V_2 -> V_93 [ V_24 ] ) ;
V_82 = F_62 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
++ V_24 ;
}
return V_82 ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_107 = ( unsigned long ) V_2 -> V_163 ;
return F_62 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_82 = V_79 ;
int V_24 = V_140 ;
while ( V_24 >= V_205 ) {
if ( V_24 == V_187 ) {
F_5 ( V_2 , & V_2 -> V_93 [ V_187 ] ,
V_2 -> V_97 ) ;
-- V_24 ;
}
V_82 = F_63 ( V_2 , & V_2 -> V_93 [ V_24 ] , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
break;
-- V_24 ;
}
return V_82 ;
}
int F_72 ( struct V_1 * V_2 , int V_206 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
int V_82 ;
struct V_166 V_167 ;
T_6 V_207 ;
T_6 V_208 ;
T_2 V_209 , V_22 ;
V_2 -> V_14 . V_107 = V_2 -> V_163 ;
V_82 = F_62 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_163 &= ~ ( V_202 | V_194 | V_197 ) ;
V_2 -> V_14 . V_107 = F_19 ( V_2 , V_89 ) ;
V_82 = F_62 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_14 . V_107 = V_2 -> V_27 ;
V_82 = F_62 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_23 -> V_168 ( V_2 , & V_167 ) ;
V_208 = V_167 . V_96 + ( V_206 << 2 ) ;
V_207 = V_167 . V_96 + ( V_206 << 2 ) + 2 ;
V_82 = V_23 -> V_83 ( V_2 , V_207 , & V_209 , 2 , & V_2 -> V_41 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = V_23 -> V_83 ( V_2 , V_208 , & V_22 , 2 , & V_2 -> V_41 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_57 ( V_2 , V_209 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_27 = V_22 ;
return V_82 ;
}
static int F_73 ( struct V_1 * V_2 , int V_206 )
{
switch( V_2 -> V_35 ) {
case V_76 :
return F_72 ( V_2 , V_206 ) ;
case V_179 :
case V_200 :
case V_199 :
case V_36 :
default:
return V_92 ;
}
}
static int F_74 ( struct V_1 * V_2 )
{
int V_82 = V_79 ;
unsigned long V_210 = 0 ;
unsigned long V_211 = 0 ;
unsigned long V_209 = 0 ;
unsigned long V_147 = V_101 | V_104 | V_193 | V_102 | V_103 | V_194 |
V_202 | V_164 | V_100 | V_201 | V_195 | V_196 |
V_197 | V_198 | ( 1 << 1 ) ;
unsigned long V_212 = V_213 | V_214 | V_215 ;
V_82 = F_63 ( V_2 , & V_210 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
if ( V_210 & ~ 0xffff )
return F_13 ( V_2 , 0 ) ;
V_82 = F_63 ( V_2 , & V_209 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_63 ( V_2 , & V_211 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_57 ( V_2 , ( T_2 ) V_209 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_27 = V_210 ;
if ( V_2 -> V_97 == 4 )
V_2 -> V_163 = ( ( V_211 & V_147 ) | ( V_2 -> V_163 & V_212 ) ) ;
else if ( V_2 -> V_97 == 2 ) {
V_2 -> V_163 &= ~ 0xffff ;
V_2 -> V_163 |= V_211 ;
}
V_2 -> V_163 &= ~ V_216 ;
V_2 -> V_163 |= V_217 ;
return V_82 ;
}
static int F_75 ( struct V_1 * V_2 )
{
switch( V_2 -> V_35 ) {
case V_76 :
return F_74 ( V_2 ) ;
case V_179 :
case V_200 :
case V_199 :
case V_36 :
default:
return V_92 ;
}
}
static int F_76 ( struct V_1 * V_2 )
{
int V_82 ;
unsigned short V_72 ;
memcpy ( & V_72 , V_2 -> V_14 . V_218 + V_2 -> V_97 , 2 ) ;
V_82 = F_57 ( V_2 , V_72 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_218 , V_2 -> V_97 ) ;
return V_79 ;
}
static int F_77 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case 0 :
F_78 ( V_2 , L_1 ) ;
break;
case 1 :
F_78 ( V_2 , L_2 ) ;
break;
case 2 :
F_78 ( V_2 , L_3 ) ;
break;
case 3 :
F_78 ( V_2 , L_4 ) ;
break;
case 4 :
case 6 :
F_78 ( V_2 , L_5 ) ;
break;
case 5 :
F_78 ( V_2 , L_6 ) ;
break;
case 7 :
F_78 ( V_2 , L_7 ) ;
break;
}
return V_79 ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_107 = ~ V_2 -> V_19 . V_107 ;
return V_79 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_81 ( V_2 , L_8 ) ;
return V_79 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_4 V_219 = 0 ;
F_83 ( V_2 , L_9 , V_219 ) ;
return V_79 ;
}
static int F_84 ( struct V_1 * V_2 )
{
T_4 V_219 = 0 ;
F_83 ( V_2 , L_10 , V_219 ) ;
return V_79 ;
}
static int F_85 ( struct V_1 * V_2 )
{
T_4 V_220 = 0 ;
F_83 ( V_2 , L_11 , V_220 ) ;
if ( V_220 )
return F_17 ( V_2 ) ;
return V_79 ;
}
static int F_86 ( struct V_1 * V_2 )
{
T_4 V_220 = 0 ;
F_83 ( V_2 , L_12 , V_220 ) ;
if ( V_220 )
return F_17 ( V_2 ) ;
return V_79 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_82 = V_79 ;
switch ( V_2 -> V_11 ) {
case 0 :
F_81 ( V_2 , L_13 ) ;
break;
case 1 :
F_81 ( V_2 , L_14 ) ;
break;
case 2 : {
long int V_221 ;
V_221 = V_2 -> V_27 ;
V_2 -> V_27 = V_2 -> V_14 . V_107 ;
V_2 -> V_14 . V_107 = V_221 ;
V_82 = F_62 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_27 = V_2 -> V_14 . V_107 ;
break;
case 5 :
V_82 = F_76 ( V_2 ) ;
break;
case 6 :
V_82 = F_62 ( V_2 ) ;
break;
}
return V_82 ;
}
static int F_88 ( struct V_1 * V_2 )
{
V_108 V_222 = V_2 -> V_19 . V_223 ;
if ( ( ( T_1 ) ( V_222 >> 0 ) != ( T_1 ) V_2 -> V_93 [ V_205 ] ) ||
( ( T_1 ) ( V_222 >> 32 ) != ( T_1 ) V_2 -> V_93 [ V_224 ] ) ) {
V_2 -> V_93 [ V_205 ] = ( T_1 ) ( V_222 >> 0 ) ;
V_2 -> V_93 [ V_224 ] = ( T_1 ) ( V_222 >> 32 ) ;
V_2 -> V_163 &= ~ V_102 ;
} else {
V_2 -> V_19 . V_15 = ( ( V_108 ) V_2 -> V_93 [ V_162 ] << 32 ) |
( T_1 ) V_2 -> V_93 [ V_134 ] ;
V_2 -> V_163 |= V_102 ;
}
return V_79 ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_121 ;
V_2 -> V_19 . V_65 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
return F_64 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_82 ;
unsigned long V_209 ;
V_82 = F_63 ( V_2 , & V_2 -> V_27 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
if ( V_2 -> V_97 == 4 )
V_2 -> V_27 = ( T_1 ) V_2 -> V_27 ;
V_82 = F_63 ( V_2 , & V_209 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_57 ( V_2 , ( T_2 ) V_209 , V_89 ) ;
return V_82 ;
}
static int F_91 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_123 = V_2 -> V_14 . V_107 ;
V_2 -> V_14 . V_107 = V_2 -> V_93 [ V_205 ] ;
F_92 ( V_2 , L_15 ) ;
if ( V_2 -> V_163 & V_102 ) {
V_2 -> V_19 . V_107 = V_2 -> V_14 . V_123 ;
} else {
V_2 -> V_19 . type = V_121 ;
V_2 -> V_19 . V_65 . V_24 = ( unsigned long * ) & V_2 -> V_93 [ V_205 ] ;
}
return V_79 ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_203 . V_107 ;
unsigned short V_72 ;
int V_82 ;
memcpy ( & V_72 , V_2 -> V_14 . V_218 + V_2 -> V_97 , 2 ) ;
V_82 = F_57 ( V_2 , V_72 , V_32 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_19 . V_107 = V_2 -> V_14 . V_107 ;
return V_82 ;
}
static void
F_94 ( struct V_1 * V_2 ,
struct V_28 * V_209 , struct V_28 * V_225 )
{
T_2 V_54 ;
memset ( V_209 , 0 , sizeof( struct V_28 ) ) ;
V_2 -> V_23 -> V_55 ( V_2 , & V_54 , V_209 , NULL , V_89 ) ;
memset ( V_225 , 0 , sizeof( struct V_28 ) ) ;
V_209 -> V_226 = 0 ;
F_58 ( V_209 , 0 ) ;
V_209 -> V_31 = 1 ;
F_59 ( V_209 , 0xfffff ) ;
V_209 -> type = 0x0b ;
V_209 -> V_180 = 1 ;
V_209 -> V_78 = 0 ;
V_209 -> V_95 = 1 ;
V_209 -> V_60 = 1 ;
F_58 ( V_225 , 0 ) ;
F_59 ( V_225 , 0xfffff ) ;
V_225 -> V_31 = 1 ;
V_225 -> V_180 = 1 ;
V_225 -> type = 0x03 ;
V_225 -> V_60 = 1 ;
V_225 -> V_78 = 0 ;
V_225 -> V_95 = 1 ;
}
static bool F_95 ( struct V_1 * V_2 )
{
T_1 V_227 , V_228 , V_229 , V_230 ;
V_227 = V_229 = 0 ;
return V_2 -> V_23 -> V_231 ( V_2 , & V_227 , & V_228 , & V_229 , & V_230 )
&& V_228 == V_232
&& V_229 == V_233
&& V_230 == V_234 ;
}
static bool F_96 ( struct V_1 * V_2 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
T_1 V_227 , V_228 , V_229 , V_230 ;
if ( V_2 -> V_35 == V_36 )
return true ;
V_227 = 0x00000000 ;
V_229 = 0x00000000 ;
if ( V_23 -> V_231 ( V_2 , & V_227 , & V_228 , & V_229 , & V_230 ) ) {
if ( V_228 == V_232 &&
V_229 == V_233 &&
V_230 == V_234 )
return false ;
if ( V_228 == V_235 &&
V_229 == V_236 &&
V_230 == V_237 )
return true ;
if ( V_228 == V_238 &&
V_229 == V_239 &&
V_230 == V_240 )
return true ;
}
return false ;
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_28 V_209 , V_225 ;
V_108 V_241 ;
T_2 V_242 , V_243 ;
V_108 V_244 = 0 ;
if ( V_2 -> V_35 == V_76 ||
V_2 -> V_35 == V_179 )
return F_15 ( V_2 ) ;
if ( ! ( F_96 ( V_2 ) ) )
return F_15 ( V_2 ) ;
V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
F_94 ( V_2 , & V_209 , & V_225 ) ;
if ( ! ( V_244 & V_247 ) )
return F_15 ( V_2 ) ;
V_23 -> V_245 ( V_2 , V_248 , & V_241 ) ;
V_241 >>= 32 ;
V_242 = ( T_2 ) ( V_241 & 0xfffc ) ;
V_243 = ( T_2 ) ( V_241 + 8 ) ;
if ( V_244 & V_249 ) {
V_209 . V_60 = 0 ;
V_209 . V_226 = 1 ;
}
V_23 -> V_58 ( V_2 , V_242 , & V_209 , 0 , V_89 ) ;
V_23 -> V_58 ( V_2 , V_243 , & V_225 , 0 , V_80 ) ;
V_2 -> V_93 [ V_162 ] = V_2 -> V_27 ;
if ( V_244 & V_249 ) {
#ifdef F_37
V_2 -> V_93 [ V_250 ] = V_2 -> V_163 & ~ V_196 ;
V_23 -> V_245 ( V_2 ,
V_2 -> V_35 == V_36 ?
V_251 : V_252 , & V_241 ) ;
V_2 -> V_27 = V_241 ;
V_23 -> V_245 ( V_2 , V_253 , & V_241 ) ;
V_2 -> V_163 &= ~ ( V_241 | V_196 ) ;
#endif
} else {
V_23 -> V_245 ( V_2 , V_248 , & V_241 ) ;
V_2 -> V_27 = ( T_1 ) V_241 ;
V_2 -> V_163 &= ~ ( V_213 | V_202 | V_196 ) ;
}
return V_79 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_28 V_209 , V_225 ;
V_108 V_241 ;
T_2 V_242 , V_243 ;
V_108 V_244 = 0 ;
V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
if ( V_2 -> V_35 == V_76 )
return F_13 ( V_2 , 0 ) ;
if ( ( V_2 -> V_35 == V_199 ) && ( V_244 & V_249 )
&& ! F_95 ( V_2 ) )
return F_15 ( V_2 ) ;
if ( V_2 -> V_35 == V_36 )
return F_15 ( V_2 ) ;
F_94 ( V_2 , & V_209 , & V_225 ) ;
V_23 -> V_245 ( V_2 , V_254 , & V_241 ) ;
switch ( V_2 -> V_35 ) {
case V_199 :
if ( ( V_241 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
case V_36 :
if ( V_241 == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
}
V_2 -> V_163 &= ~ ( V_213 | V_202 | V_196 ) ;
V_242 = ( T_2 ) V_241 ;
V_242 &= ~ V_255 ;
V_243 = V_242 + 8 ;
V_243 &= ~ V_255 ;
if ( V_2 -> V_35 == V_36 || ( V_244 & V_249 ) ) {
V_209 . V_60 = 0 ;
V_209 . V_226 = 1 ;
}
V_23 -> V_58 ( V_2 , V_242 , & V_209 , 0 , V_89 ) ;
V_23 -> V_58 ( V_2 , V_243 , & V_225 , 0 , V_80 ) ;
V_23 -> V_245 ( V_2 , V_256 , & V_241 ) ;
V_2 -> V_27 = V_241 ;
V_23 -> V_245 ( V_2 , V_257 , & V_241 ) ;
V_2 -> V_93 [ V_187 ] = V_241 ;
return V_79 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_28 V_209 , V_225 ;
V_108 V_241 ;
int V_258 ;
T_2 V_242 = 0 , V_243 = 0 ;
if ( V_2 -> V_35 == V_76 ||
V_2 -> V_35 == V_179 )
return F_13 ( V_2 , 0 ) ;
F_94 ( V_2 , & V_209 , & V_225 ) ;
if ( ( V_2 -> V_111 & 0x8 ) != 0x0 )
V_258 = V_36 ;
else
V_258 = V_199 ;
V_209 . V_78 = 3 ;
V_225 . V_78 = 3 ;
V_23 -> V_245 ( V_2 , V_254 , & V_241 ) ;
switch ( V_258 ) {
case V_199 :
V_242 = ( T_2 ) ( V_241 + 16 ) ;
if ( ( V_241 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_243 = ( T_2 ) ( V_241 + 24 ) ;
break;
case V_36 :
V_242 = ( T_2 ) ( V_241 + 32 ) ;
if ( V_241 == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_243 = V_242 + 8 ;
V_209 . V_60 = 0 ;
V_209 . V_226 = 1 ;
break;
}
V_242 |= V_255 ;
V_243 |= V_255 ;
V_23 -> V_58 ( V_2 , V_242 , & V_209 , 0 , V_89 ) ;
V_23 -> V_58 ( V_2 , V_243 , & V_225 , 0 , V_80 ) ;
V_2 -> V_27 = V_2 -> V_93 [ V_224 ] ;
V_2 -> V_93 [ V_187 ] = V_2 -> V_93 [ V_162 ] ;
return V_79 ;
}
static bool F_100 ( struct V_1 * V_2 )
{
int V_190 ;
if ( V_2 -> V_35 == V_76 )
return false ;
if ( V_2 -> V_35 == V_179 )
return true ;
V_190 = ( V_2 -> V_163 & V_191 ) >> V_192 ;
return V_2 -> V_23 -> V_73 ( V_2 ) > V_190 ;
}
static bool F_101 ( struct V_1 * V_2 ,
T_2 V_158 , T_2 V_188 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_28 V_259 ;
T_1 V_57 ;
int V_260 ;
T_2 V_261 , V_262 , V_263 , V_264 = V_158 & 0x7 ;
unsigned V_147 = ( 1 << V_188 ) - 1 ;
unsigned long V_265 ;
V_23 -> V_55 ( V_2 , & V_261 , & V_259 , & V_57 , V_182 ) ;
if ( ! V_259 . V_95 )
return false ;
if ( F_7 ( & V_259 ) < 103 )
return false ;
V_265 = F_54 ( & V_259 ) ;
#ifdef F_37
V_265 |= ( ( V_108 ) V_57 ) << 32 ;
#endif
V_260 = V_23 -> V_83 ( V_2 , V_265 + 102 , & V_262 , 2 , NULL ) ;
if ( V_260 != V_79 )
return false ;
if ( V_262 + V_158 / 8 > F_7 ( & V_259 ) )
return false ;
V_260 = V_23 -> V_83 ( V_2 , V_265 + V_262 + V_158 / 8 , & V_263 , 2 , NULL ) ;
if ( V_260 != V_79 )
return false ;
if ( ( V_263 >> V_264 ) & V_147 )
return false ;
return true ;
}
static bool F_102 ( struct V_1 * V_2 ,
T_2 V_158 , T_2 V_188 )
{
if ( V_2 -> V_266 )
return true ;
if ( F_100 ( V_2 ) )
if ( ! F_101 ( V_2 , V_158 , V_188 ) )
return false ;
V_2 -> V_266 = true ;
return true ;
}
static void F_103 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
V_268 -> V_269 = V_2 -> V_27 ;
V_268 -> V_270 = V_2 -> V_163 ;
V_268 -> V_271 = V_2 -> V_93 [ V_205 ] ;
V_268 -> V_272 = V_2 -> V_93 [ V_162 ] ;
V_268 -> V_273 = V_2 -> V_93 [ V_224 ] ;
V_268 -> V_133 = V_2 -> V_93 [ V_134 ] ;
V_268 -> V_274 = V_2 -> V_93 [ V_187 ] ;
V_268 -> V_135 = V_2 -> V_93 [ V_136 ] ;
V_268 -> V_137 = V_2 -> V_93 [ V_138 ] ;
V_268 -> V_139 = V_2 -> V_93 [ V_140 ] ;
V_268 -> V_275 = F_19 ( V_2 , V_276 ) ;
V_268 -> V_209 = F_19 ( V_2 , V_89 ) ;
V_268 -> V_225 = F_19 ( V_2 , V_80 ) ;
V_268 -> V_277 = F_19 ( V_2 , V_131 ) ;
V_268 -> V_278 = F_19 ( V_2 , V_170 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
int V_177 ;
V_2 -> V_27 = V_268 -> V_269 ;
V_2 -> V_163 = V_268 -> V_270 | 2 ;
V_2 -> V_93 [ V_205 ] = V_268 -> V_271 ;
V_2 -> V_93 [ V_162 ] = V_268 -> V_272 ;
V_2 -> V_93 [ V_224 ] = V_268 -> V_273 ;
V_2 -> V_93 [ V_134 ] = V_268 -> V_133 ;
V_2 -> V_93 [ V_187 ] = V_268 -> V_274 ;
V_2 -> V_93 [ V_136 ] = V_268 -> V_135 ;
V_2 -> V_93 [ V_138 ] = V_268 -> V_137 ;
V_2 -> V_93 [ V_140 ] = V_268 -> V_139 ;
F_20 ( V_2 , V_268 -> V_278 , V_170 ) ;
F_20 ( V_2 , V_268 -> V_275 , V_276 ) ;
F_20 ( V_2 , V_268 -> V_209 , V_89 ) ;
F_20 ( V_2 , V_268 -> V_225 , V_80 ) ;
F_20 ( V_2 , V_268 -> V_277 , V_131 ) ;
V_177 = F_57 ( V_2 , V_268 -> V_278 , V_170 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_275 , V_276 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_209 , V_89 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_225 , V_80 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_277 , V_131 ) ;
if ( V_177 != V_79 )
return V_177 ;
return V_79 ;
}
static int F_105 ( struct V_1 * V_2 ,
T_2 V_279 , T_2 V_280 ,
T_3 V_281 , struct V_28 * V_282 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_267 V_283 ;
int V_177 ;
T_1 V_284 = F_54 ( V_282 ) ;
V_177 = V_23 -> V_83 ( V_2 , V_281 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
F_103 ( V_2 , & V_283 ) ;
V_177 = V_23 -> V_172 ( V_2 , V_281 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = V_23 -> V_83 ( V_2 , V_284 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
if ( V_280 != 0xffff ) {
V_283 . V_285 = V_280 ;
V_177 = V_23 -> V_172 ( V_2 , V_284 ,
& V_283 . V_285 ,
sizeof V_283 . V_285 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
}
return F_104 ( V_2 , & V_283 ) ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_286 * V_268 )
{
V_268 -> V_287 = V_2 -> V_23 -> V_288 ( V_2 , 3 ) ;
V_268 -> V_22 = V_2 -> V_27 ;
V_268 -> V_163 = V_2 -> V_163 ;
V_268 -> V_227 = V_2 -> V_93 [ V_205 ] ;
V_268 -> V_229 = V_2 -> V_93 [ V_162 ] ;
V_268 -> V_230 = V_2 -> V_93 [ V_224 ] ;
V_268 -> V_228 = V_2 -> V_93 [ V_134 ] ;
V_268 -> V_289 = V_2 -> V_93 [ V_187 ] ;
V_268 -> V_290 = V_2 -> V_93 [ V_136 ] ;
V_268 -> V_291 = V_2 -> V_93 [ V_138 ] ;
V_268 -> V_292 = V_2 -> V_93 [ V_140 ] ;
V_268 -> V_275 = F_19 ( V_2 , V_276 ) ;
V_268 -> V_209 = F_19 ( V_2 , V_89 ) ;
V_268 -> V_225 = F_19 ( V_2 , V_80 ) ;
V_268 -> V_277 = F_19 ( V_2 , V_131 ) ;
V_268 -> V_293 = F_19 ( V_2 , V_37 ) ;
V_268 -> V_294 = F_19 ( V_2 , V_178 ) ;
V_268 -> V_295 = F_19 ( V_2 , V_170 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_286 * V_268 )
{
int V_177 ;
if ( V_2 -> V_23 -> V_296 ( V_2 , 3 , V_268 -> V_287 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_27 = V_268 -> V_22 ;
V_2 -> V_163 = V_268 -> V_163 | 2 ;
V_2 -> V_93 [ V_205 ] = V_268 -> V_227 ;
V_2 -> V_93 [ V_162 ] = V_268 -> V_229 ;
V_2 -> V_93 [ V_224 ] = V_268 -> V_230 ;
V_2 -> V_93 [ V_134 ] = V_268 -> V_228 ;
V_2 -> V_93 [ V_187 ] = V_268 -> V_289 ;
V_2 -> V_93 [ V_136 ] = V_268 -> V_290 ;
V_2 -> V_93 [ V_138 ] = V_268 -> V_291 ;
V_2 -> V_93 [ V_140 ] = V_268 -> V_292 ;
F_20 ( V_2 , V_268 -> V_295 , V_170 ) ;
F_20 ( V_2 , V_268 -> V_275 , V_276 ) ;
F_20 ( V_2 , V_268 -> V_209 , V_89 ) ;
F_20 ( V_2 , V_268 -> V_225 , V_80 ) ;
F_20 ( V_2 , V_268 -> V_277 , V_131 ) ;
F_20 ( V_2 , V_268 -> V_293 , V_37 ) ;
F_20 ( V_2 , V_268 -> V_294 , V_178 ) ;
if ( V_2 -> V_163 & V_297 )
V_2 -> V_35 = V_179 ;
else
V_2 -> V_35 = V_199 ;
V_2 -> V_23 -> V_298 ( V_2 , V_2 -> V_163 ) ;
V_177 = F_57 ( V_2 , V_268 -> V_295 , V_170 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_275 , V_276 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_209 , V_89 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_225 , V_80 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_277 , V_131 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_293 , V_37 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_57 ( V_2 , V_268 -> V_294 , V_178 ) ;
if ( V_177 != V_79 )
return V_177 ;
return V_79 ;
}
static int F_108 ( struct V_1 * V_2 ,
T_2 V_279 , T_2 V_280 ,
T_3 V_281 , struct V_28 * V_282 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_286 V_283 ;
int V_177 ;
T_1 V_284 = F_54 ( V_282 ) ;
V_177 = V_23 -> V_83 ( V_2 , V_281 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
F_106 ( V_2 , & V_283 ) ;
V_177 = V_23 -> V_172 ( V_2 , V_281 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = V_23 -> V_83 ( V_2 , V_284 , & V_283 , sizeof V_283 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
if ( V_280 != 0xffff ) {
V_283 . V_285 = V_280 ;
V_177 = V_23 -> V_172 ( V_2 , V_284 ,
& V_283 . V_285 ,
sizeof V_283 . V_285 ,
& V_2 -> V_41 ) ;
if ( V_177 != V_79 )
return V_177 ;
}
return F_107 ( V_2 , & V_283 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
T_2 V_279 , int V_299 , int V_300 ,
bool V_301 , T_1 V_43 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
struct V_28 V_302 , V_303 ;
int V_177 ;
T_2 V_280 = F_19 ( V_2 , V_182 ) ;
T_3 V_281 =
V_23 -> V_38 ( V_2 , V_182 ) ;
T_1 V_304 ;
V_177 = F_55 ( V_2 , V_279 , & V_303 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_177 = F_55 ( V_2 , V_280 , & V_302 ) ;
if ( V_177 != V_79 )
return V_177 ;
if ( V_300 == V_305 ) {
if ( V_299 != - 1 ) {
struct V_28 V_306 ;
int V_78 ;
V_177 = F_52 ( V_2 , V_299 ,
& V_306 ) ;
if ( V_177 != V_79 )
return V_177 ;
V_78 = V_306 . V_78 ;
if ( ( V_279 & 3 ) > V_78 || V_23 -> V_73 ( V_2 ) > V_78 )
return F_13 ( V_2 , ( V_299 << 3 ) | 0x2 ) ;
}
} else if ( V_300 != V_307 ) {
int V_78 = V_303 . V_78 ;
if ( ( V_279 & 3 ) > V_78 || V_23 -> V_73 ( V_2 ) > V_78 )
return F_13 ( V_2 , V_279 ) ;
}
V_304 = F_7 ( & V_303 ) ;
if ( ! V_303 . V_95 ||
( ( V_304 < 0x67 && ( V_303 . type & 8 ) ) ||
V_304 < 0x2b ) ) {
F_16 ( V_2 , V_279 & 0xfffc ) ;
return V_45 ;
}
if ( V_300 == V_307 || V_300 == V_308 ) {
V_302 . type &= ~ ( 1 << 1 ) ;
F_56 ( V_2 , V_280 , & V_302 ) ;
}
if ( V_300 == V_307 )
V_2 -> V_163 = V_2 -> V_163 & ~ V_309 ;
if ( V_300 != V_310 && V_300 != V_305 )
V_280 = 0xffff ;
if ( V_303 . type & 8 )
V_177 = F_108 ( V_2 , V_279 , V_280 ,
V_281 , & V_303 ) ;
else
V_177 = F_105 ( V_2 , V_279 , V_280 ,
V_281 , & V_303 ) ;
if ( V_177 != V_79 )
return V_177 ;
if ( V_300 == V_310 || V_300 == V_305 )
V_2 -> V_163 = V_2 -> V_163 | V_309 ;
if ( V_300 != V_307 ) {
V_303 . type |= ( 1 << 1 ) ;
F_56 ( V_2 , V_279 , & V_303 ) ;
}
V_23 -> V_296 ( V_2 , 0 , V_23 -> V_288 ( V_2 , 0 ) | V_311 ) ;
V_23 -> V_58 ( V_2 , V_279 , & V_303 , 0 , V_182 ) ;
if ( V_301 ) {
V_2 -> V_97 = V_2 -> V_20 = ( V_303 . type & 8 ) ? 4 : 2 ;
V_2 -> V_184 = 0 ;
V_2 -> V_14 . V_107 = ( unsigned long ) V_43 ;
V_177 = F_62 ( V_2 ) ;
}
return V_177 ;
}
int F_110 ( struct V_1 * V_2 ,
T_2 V_279 , int V_299 , int V_300 ,
bool V_301 , T_1 V_43 )
{
int V_82 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_186 ;
V_82 = F_109 ( V_2 , V_279 , V_299 , V_300 ,
V_301 , V_43 ) ;
if ( V_82 == V_79 )
V_2 -> V_22 = V_2 -> V_27 ;
return ( V_82 == V_92 ) ? V_312 : V_313 ;
}
static void F_111 ( struct V_1 * V_2 , unsigned V_32 ,
int V_24 , struct V_105 * V_106 )
{
int V_314 = ( V_2 -> V_163 & V_164 ) ? - 1 : 1 ;
F_5 ( V_2 , & V_2 -> V_93 [ V_24 ] , V_314 * V_106 -> V_17 ) ;
V_106 -> V_65 . V_144 . V_75 = F_4 ( V_2 , V_2 -> V_93 [ V_24 ] ) ;
V_106 -> V_65 . V_144 . V_32 = V_32 ;
}
static int F_112 ( struct V_1 * V_2 )
{
T_4 V_315 , V_316 ;
bool V_317 , V_318 , V_319 ;
V_318 = V_2 -> V_163 & V_320 ;
V_315 = V_2 -> V_19 . V_107 ;
V_316 = V_315 ;
V_319 = V_318 ;
V_318 = false ;
V_317 = V_2 -> V_163 & V_321 ;
if ( ( V_315 & 0x0f ) > 9 || V_317 ) {
V_315 -= 6 ;
V_318 = V_319 | ( V_315 >= 250 ) ;
V_317 = true ;
} else {
V_317 = false ;
}
if ( V_316 > 0x99 || V_319 ) {
V_315 -= 0x60 ;
V_318 = true ;
}
V_2 -> V_19 . V_107 = V_315 ;
V_2 -> V_14 . type = V_322 ;
V_2 -> V_14 . V_107 = 0 ;
V_2 -> V_14 . V_17 = 1 ;
F_92 ( V_2 , L_16 ) ;
V_2 -> V_163 &= ~ ( V_321 | V_320 ) ;
if ( V_318 )
V_2 -> V_163 |= V_320 ;
if ( V_317 )
V_2 -> V_163 |= V_321 ;
return V_79 ;
}
static int F_113 ( struct V_1 * V_2 )
{
long V_26 = V_2 -> V_14 . V_107 ;
V_2 -> V_14 . V_107 = ( unsigned long ) V_2 -> V_27 ;
F_6 ( V_2 , V_26 ) ;
return F_62 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
T_2 V_72 , V_323 ;
T_3 V_221 ;
int V_82 ;
V_323 = F_19 ( V_2 , V_89 ) ;
V_221 = V_2 -> V_27 ;
memcpy ( & V_72 , V_2 -> V_14 . V_218 + V_2 -> V_97 , 2 ) ;
if ( F_57 ( V_2 , V_72 , V_89 ) )
return V_79 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_218 , V_2 -> V_97 ) ;
V_2 -> V_14 . V_107 = V_323 ;
V_82 = F_62 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_14 . V_107 = V_221 ;
return F_62 ( V_2 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
int V_82 ;
V_2 -> V_19 . type = V_121 ;
V_2 -> V_19 . V_65 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
V_82 = F_63 ( V_2 , & V_2 -> V_19 . V_107 , V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
F_5 ( V_2 , & V_2 -> V_93 [ V_187 ] , V_2 -> V_14 . V_107 ) ;
return V_79 ;
}
static int F_116 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_17 ) ;
return V_79 ;
}
static int F_117 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_16 ) ;
return V_79 ;
}
static int F_118 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_18 ) ;
return V_79 ;
}
static int F_119 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_19 ) ;
return V_79 ;
}
static int F_120 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_20 ) ;
return V_79 ;
}
static int F_121 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_21 ) ;
return V_79 ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_22 ) ;
return V_79 ;
}
static int F_123 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_15 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_124 ( struct V_1 * V_2 )
{
F_92 ( V_2 , L_23 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_125 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_107 = V_2 -> V_19 . V_107 ;
F_60 ( & V_2 -> V_14 ) ;
V_2 -> V_19 . V_107 = V_2 -> V_14 . V_123 ;
V_2 -> V_184 = 1 ;
return V_79 ;
}
static int F_126 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_10 ) ;
return V_79 ;
}
static int F_128 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_107 = V_2 -> V_203 . V_107 ;
return F_126 ( V_2 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_121 ;
V_2 -> V_19 . V_17 = V_2 -> V_14 . V_17 ;
V_2 -> V_19 . V_65 . V_24 = & V_2 -> V_93 [ V_224 ] ;
V_2 -> V_19 . V_107 = ~ ( ( V_2 -> V_14 . V_107 >> ( V_2 -> V_14 . V_17 * 8 - 1 ) ) - 1 ) ;
return V_79 ;
}
static int F_130 ( struct V_1 * V_2 )
{
V_108 V_324 = 0 ;
V_2 -> V_23 -> V_245 ( V_2 , V_325 , & V_324 ) ;
V_2 -> V_93 [ V_205 ] = ( T_1 ) V_324 ;
V_2 -> V_93 [ V_224 ] = V_324 >> 32 ;
return V_79 ;
}
static int F_131 ( struct V_1 * V_2 )
{
V_108 V_326 ;
if ( V_2 -> V_23 -> V_327 ( V_2 , V_2 -> V_93 [ V_162 ] , & V_326 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_93 [ V_205 ] = ( T_1 ) V_326 ;
V_2 -> V_93 [ V_224 ] = V_326 >> 32 ;
return V_79 ;
}
static int F_132 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_19 . V_218 , V_2 -> V_14 . V_218 , V_2 -> V_97 ) ;
return V_79 ;
}
static int F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_296 ( V_2 , V_2 -> V_11 , V_2 -> V_14 . V_107 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_134 ( struct V_1 * V_2 )
{
unsigned long V_107 ;
if ( V_2 -> V_35 == V_36 )
V_107 = V_2 -> V_14 . V_107 & ~ 0ULL ;
else
V_107 = V_2 -> V_14 . V_107 & ~ 0U ;
if ( V_2 -> V_23 -> V_328 ( V_2 , V_2 -> V_11 , V_107 ) < 0 )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_135 ( struct V_1 * V_2 )
{
V_108 V_241 ;
V_241 = ( T_1 ) V_2 -> V_93 [ V_205 ]
| ( ( V_108 ) V_2 -> V_93 [ V_224 ] << 32 ) ;
if ( V_2 -> V_23 -> V_329 ( V_2 , V_2 -> V_93 [ V_162 ] , V_241 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_108 V_241 ;
if ( V_2 -> V_23 -> V_245 ( V_2 , V_2 -> V_93 [ V_162 ] , & V_241 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_93 [ V_205 ] = ( T_1 ) V_241 ;
V_2 -> V_93 [ V_224 ] = V_241 >> 32 ;
return V_79 ;
}
static int F_137 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 > V_178 )
return F_15 ( V_2 ) ;
V_2 -> V_19 . V_107 = F_19 ( V_2 , V_2 -> V_11 ) ;
return V_79 ;
}
static int F_138 ( struct V_1 * V_2 )
{
T_2 V_72 = V_2 -> V_14 . V_107 ;
if ( V_2 -> V_11 == V_89 || V_2 -> V_11 > V_178 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_11 == V_80 )
V_2 -> V_330 = V_331 ;
V_2 -> V_19 . type = V_186 ;
return F_57 ( V_2 , V_72 , V_2 -> V_11 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
int V_82 ;
T_3 V_68 ;
V_82 = F_25 ( V_2 , V_2 -> V_14 . V_65 . V_144 , 1 , false , & V_68 ) ;
if ( V_82 == V_79 )
V_2 -> V_23 -> V_332 ( V_2 , V_68 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_140 ( struct V_1 * V_2 )
{
T_3 V_333 ;
V_333 = V_2 -> V_23 -> V_288 ( V_2 , 0 ) ;
V_333 &= ~ V_311 ;
V_2 -> V_23 -> V_296 ( V_2 , 0 , V_333 ) ;
return V_79 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_82 ;
if ( V_2 -> V_10 != 3 || V_2 -> V_12 != 1 )
return V_92 ;
V_82 = V_2 -> V_23 -> V_334 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_142 ( struct V_1 * V_2 )
{
struct V_166 V_166 ;
int V_82 ;
V_82 = F_33 ( V_2 , V_2 -> V_14 . V_65 . V_144 ,
& V_166 . V_59 , & V_166 . V_96 ,
V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_23 -> V_335 ( V_2 , & V_166 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_143 ( struct V_1 * V_2 )
{
int V_82 ;
V_82 = V_2 -> V_23 -> V_334 ( V_2 ) ;
V_2 -> V_19 . type = V_186 ;
return V_82 ;
}
static int F_144 ( struct V_1 * V_2 )
{
struct V_166 V_166 ;
int V_82 ;
V_82 = F_33 ( V_2 , V_2 -> V_14 . V_65 . V_144 ,
& V_166 . V_59 , & V_166 . V_96 ,
V_2 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_23 -> V_336 ( V_2 , & V_166 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_145 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = 2 ;
V_2 -> V_19 . V_107 = V_2 -> V_23 -> V_288 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_146 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_296 ( V_2 , 0 , ( V_2 -> V_23 -> V_288 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_14 . V_107 & 0x0f ) ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_147 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_93 [ V_162 ] , - 1 ) ;
if ( ( F_3 ( V_2 , V_2 -> V_93 [ V_162 ] ) != 0 ) &&
( V_2 -> V_113 == 0xe2 || F_34 ( V_2 -> V_113 ^ 0x5 , V_2 -> V_163 ) ) )
F_6 ( V_2 , V_2 -> V_14 . V_107 ) ;
return V_79 ;
}
static int F_148 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_2 -> V_93 [ V_162 ] ) == 0 )
F_6 ( V_2 , V_2 -> V_14 . V_107 ) ;
return V_79 ;
}
static int F_149 ( struct V_1 * V_2 )
{
if ( ! F_51 ( V_2 , V_2 -> V_19 . V_17 , V_2 -> V_14 . V_107 ,
& V_2 -> V_19 . V_107 ) )
return V_337 ;
return V_79 ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_338 ( V_2 , V_2 -> V_14 . V_17 , V_2 -> V_19 . V_107 ,
& V_2 -> V_14 . V_107 , 1 ) ;
V_2 -> V_19 . type = V_186 ;
return V_79 ;
}
static int F_151 ( struct V_1 * V_2 )
{
if ( F_100 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_163 &= ~ V_339 ;
return V_79 ;
}
static int F_152 ( struct V_1 * V_2 )
{
if ( F_100 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_330 = V_340 ;
V_2 -> V_163 |= V_339 ;
return V_79 ;
}
static int F_153 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_186 ;
V_2 -> V_14 . V_107 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
F_127 ( V_2 , L_24 ) ;
return V_79 ;
}
static int F_154 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_25 ) ;
return V_79 ;
}
static int F_155 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_26 ) ;
return V_79 ;
}
static int F_156 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_27 ) ;
return V_79 ;
}
static int F_157 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_28 ) ;
return V_79 ;
}
static int F_158 ( struct V_1 * V_2 )
{
F_127 ( V_2 , L_29 ) ;
return V_79 ;
}
static bool F_159 ( int V_341 )
{
switch ( V_341 ) {
case 0 :
case 2 ... 4 :
case 8 :
return true ;
default:
return false ;
}
}
static int F_160 ( struct V_1 * V_2 )
{
if ( ! F_159 ( V_2 -> V_11 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_161 ( struct V_1 * V_2 )
{
V_108 V_342 = V_2 -> V_14 . V_15 ;
int V_343 = V_2 -> V_11 ;
V_108 V_244 = 0 ;
static V_108 V_344 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_345 ,
0 , 0 , 0 ,
V_346 ,
} ;
if ( ! F_159 ( V_343 ) )
return F_15 ( V_2 ) ;
if ( V_342 & V_344 [ V_343 ] )
return F_13 ( V_2 , 0 ) ;
switch ( V_343 ) {
case 0 : {
V_108 V_347 ;
if ( ( ( V_342 & V_348 ) && ! ( V_342 & V_349 ) ) ||
( ( V_342 & V_350 ) && ! ( V_342 & V_351 ) ) )
return F_13 ( V_2 , 0 ) ;
V_347 = V_2 -> V_23 -> V_288 ( V_2 , 4 ) ;
V_2 -> V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
if ( ( V_342 & V_348 ) && ( V_244 & V_352 ) &&
! ( V_347 & V_353 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_108 V_354 = 0 ;
V_2 -> V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
if ( V_244 & V_249 )
V_354 = V_355 ;
else if ( V_2 -> V_23 -> V_288 ( V_2 , 4 ) & V_353 )
V_354 = V_356 ;
else if ( V_2 -> V_23 -> V_288 ( V_2 , 0 ) & V_348 )
V_354 = V_357 ;
if ( V_342 & V_354 )
return F_13 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
if ( ( V_244 & V_249 ) && ! ( V_342 & V_353 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
}
return V_79 ;
}
static int F_162 ( struct V_1 * V_2 )
{
unsigned long V_358 ;
V_2 -> V_23 -> V_359 ( V_2 , 7 , & V_358 ) ;
return V_358 & ( 1 << 13 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_360 = V_2 -> V_11 ;
V_108 V_347 ;
if ( V_360 > 7 )
return F_15 ( V_2 ) ;
V_347 = V_2 -> V_23 -> V_288 ( V_2 , 4 ) ;
if ( ( V_347 & V_361 ) && ( V_360 == 4 || V_360 == 5 ) )
return F_15 ( V_2 ) ;
if ( F_162 ( V_2 ) )
return F_12 ( V_2 ) ;
return V_79 ;
}
static int F_164 ( struct V_1 * V_2 )
{
V_108 V_342 = V_2 -> V_14 . V_15 ;
int V_360 = V_2 -> V_11 ;
if ( ( V_360 == 6 || V_360 == 7 ) && ( V_342 & 0xffffffff00000000ULL ) )
return F_13 ( V_2 , 0 ) ;
return F_163 ( V_2 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
V_108 V_244 ;
V_2 -> V_23 -> V_245 ( V_2 , V_246 , & V_244 ) ;
if ( ! ( V_244 & V_362 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_108 V_363 = V_2 -> V_93 [ V_205 ] ;
if ( V_363 & 0xffff000000000000ULL )
return F_13 ( V_2 , 0 ) ;
return F_165 ( V_2 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
V_108 V_347 = V_2 -> V_23 -> V_288 ( V_2 , 4 ) ;
if ( V_347 & V_364 && V_2 -> V_23 -> V_73 ( V_2 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_168 ( struct V_1 * V_2 )
{
V_108 V_347 = V_2 -> V_23 -> V_288 ( V_2 , 4 ) ;
V_108 V_365 = V_2 -> V_93 [ V_162 ] ;
if ( ( ! ( V_347 & V_366 ) && V_2 -> V_23 -> V_73 ( V_2 ) ) ||
( V_365 > 3 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = F_28 ( V_2 -> V_19 . V_17 , 4u ) ;
if ( ! F_102 ( V_2 , V_2 -> V_14 . V_107 , V_2 -> V_19 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_170 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_17 = F_28 ( V_2 -> V_14 . V_17 , 4u ) ;
if ( ! F_102 ( V_2 , V_2 -> V_19 . V_107 , V_2 -> V_14 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static unsigned F_171 ( struct V_1 * V_2 )
{
unsigned V_59 ;
V_59 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
if ( V_59 == 8 )
V_59 = 4 ;
return V_59 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_105 * V_106 ,
unsigned V_59 , bool V_367 )
{
int V_82 = V_79 ;
V_106 -> type = V_322 ;
V_106 -> V_17 = V_59 ;
V_106 -> V_65 . V_144 . V_75 = V_2 -> V_27 ;
switch ( V_106 -> V_17 ) {
case 1 :
V_106 -> V_107 = F_44 ( V_141 , V_2 ) ;
break;
case 2 :
V_106 -> V_107 = F_44 ( V_148 , V_2 ) ;
break;
case 4 :
V_106 -> V_107 = F_44 ( V_142 , V_2 ) ;
break;
}
if ( ! V_367 ) {
switch ( V_106 -> V_17 ) {
case 1 :
V_106 -> V_107 &= 0xff ;
break;
case 2 :
V_106 -> V_107 &= 0xffff ;
break;
case 4 :
V_106 -> V_107 &= 0xffffffff ;
break;
}
}
V_145:
return V_82 ;
}
static int F_173 ( struct V_1 * V_2 , struct V_105 * V_106 ,
unsigned V_60 )
{
int V_82 = V_79 ;
switch ( V_60 ) {
case V_368 :
F_42 ( V_2 , V_106 ) ;
break;
case V_369 :
V_82 = F_172 ( V_2 , V_106 , 1 , false ) ;
break;
case V_370 :
V_2 -> V_371 . V_17 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
V_372:
* V_106 = V_2 -> V_371 ;
V_2 -> V_373 = V_106 ;
if ( ( V_2 -> V_60 & V_374 ) && V_106 == & V_2 -> V_19 )
F_46 ( V_2 ) ;
V_106 -> V_123 = V_106 -> V_107 ;
break;
case V_375 :
V_2 -> V_371 . V_17 = 8 ;
goto V_372;
case V_376 :
V_106 -> type = V_121 ;
V_106 -> V_17 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
V_106 -> V_65 . V_24 = & V_2 -> V_93 [ V_205 ] ;
F_35 ( V_106 ) ;
V_106 -> V_123 = V_106 -> V_107 ;
break;
case V_377 :
V_106 -> type = V_132 ;
V_106 -> V_17 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
V_106 -> V_65 . V_144 . V_75 =
F_4 ( V_2 , V_2 -> V_93 [ V_140 ] ) ;
V_106 -> V_65 . V_144 . V_32 = V_276 ;
V_106 -> V_107 = 0 ;
break;
case V_378 :
V_106 -> type = V_121 ;
V_106 -> V_17 = 2 ;
V_106 -> V_65 . V_24 = & V_2 -> V_93 [ V_224 ] ;
F_35 ( V_106 ) ;
break;
case V_379 :
V_106 -> V_17 = 1 ;
V_106 -> V_107 = V_2 -> V_93 [ V_162 ] & 0xff ;
break;
case V_380 :
V_82 = F_172 ( V_2 , V_106 , 1 , true ) ;
break;
case V_381 :
V_106 -> V_17 = 1 ;
V_106 -> V_107 = 1 ;
break;
case V_382 :
V_82 = F_172 ( V_2 , V_106 , F_171 ( V_2 ) , true ) ;
break;
case V_383 :
V_2 -> V_371 . V_17 = 1 ;
goto V_372;
case V_384 :
V_2 -> V_371 . V_17 = 2 ;
goto V_372;
case V_385 :
V_2 -> V_371 . V_17 = 4 ;
goto V_372;
case V_386 :
V_82 = F_172 ( V_2 , V_106 , 2 , false ) ;
break;
case V_387 :
V_82 = F_172 ( V_2 , V_106 , F_171 ( V_2 ) , false ) ;
break;
case V_388 :
V_106 -> type = V_132 ;
V_106 -> V_17 = ( V_2 -> V_60 & V_122 ) ? 1 : V_2 -> V_97 ;
V_106 -> V_65 . V_144 . V_75 =
F_4 ( V_2 , V_2 -> V_93 [ V_138 ] ) ;
V_106 -> V_65 . V_144 . V_32 = V_34 ( V_2 ) ;
V_106 -> V_107 = 0 ;
break;
case V_389 :
V_106 -> type = V_322 ;
V_106 -> V_65 . V_144 . V_75 = V_2 -> V_27 ;
V_106 -> V_17 = V_2 -> V_97 + 2 ;
F_174 ( V_106 -> V_218 , V_106 -> V_17 , V_2 ) ;
break;
case V_390 :
V_2 -> V_371 . V_17 = V_2 -> V_97 + 2 ;
goto V_372;
case V_391 :
V_106 -> V_107 = V_276 ;
break;
case V_392 :
V_106 -> V_107 = V_89 ;
break;
case V_393 :
V_106 -> V_107 = V_80 ;
break;
case V_394 :
V_106 -> V_107 = V_131 ;
break;
case V_395 :
V_106 -> V_107 = V_37 ;
break;
case V_396 :
V_106 -> V_107 = V_178 ;
break;
case V_397 :
default:
V_106 -> type = V_186 ;
break;
}
V_145:
return V_82 ;
}
int F_175 ( struct V_1 * V_2 , void * V_398 , int V_399 )
{
int V_82 = V_79 ;
int V_35 = V_2 -> V_35 ;
int V_400 , V_401 , V_402 , V_403 ;
bool V_404 = false ;
struct V_405 V_405 ;
V_2 -> V_371 . type = V_186 ;
V_2 -> V_373 = NULL ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_67 . V_90 = V_2 -> V_27 ;
V_2 -> V_67 . V_88 = V_2 -> V_67 . V_90 + V_399 ;
if ( V_399 > 0 )
memcpy ( V_2 -> V_67 . V_81 , V_398 , V_399 ) ;
switch ( V_35 ) {
case V_76 :
case V_179 :
case V_200 :
V_400 = V_401 = 2 ;
break;
case V_199 :
V_400 = V_401 = 4 ;
break;
#ifdef F_37
case V_36 :
V_400 = 4 ;
V_401 = 8 ;
break;
#endif
default:
return V_312 ;
}
V_2 -> V_97 = V_400 ;
V_2 -> V_20 = V_401 ;
for (; ; ) {
switch ( V_2 -> V_113 = F_44 ( T_4 , V_2 ) ) {
case 0x66 :
V_404 = true ;
V_2 -> V_97 = V_400 ^ 6 ;
break;
case 0x67 :
if ( V_35 == V_36 )
V_2 -> V_20 = V_401 ^ 12 ;
else
V_2 -> V_20 = V_401 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_9 ( V_2 , ( V_2 -> V_113 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_9 ( V_2 , V_2 -> V_113 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_35 != V_36 )
goto V_406;
V_2 -> V_111 = V_2 -> V_113 ;
continue;
case 0xf0 :
V_2 -> V_184 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_9 = V_2 -> V_113 ;
break;
default:
goto V_406;
}
V_2 -> V_111 = 0 ;
}
V_406:
if ( V_2 -> V_111 & 8 )
V_2 -> V_97 = 8 ;
V_405 = V_407 [ V_2 -> V_113 ] ;
if ( V_2 -> V_113 == 0x0f ) {
V_2 -> V_408 = 1 ;
V_2 -> V_113 = F_44 ( T_4 , V_2 ) ;
V_405 = V_409 [ V_2 -> V_113 ] ;
}
V_2 -> V_60 = V_405 . V_99 ;
if ( V_2 -> V_60 & V_112 )
V_2 -> V_129 = F_44 ( T_4 , V_2 ) ;
while ( V_2 -> V_60 & V_410 ) {
switch ( V_2 -> V_60 & V_410 ) {
case V_411 :
V_402 = ( V_2 -> V_129 >> 3 ) & 7 ;
V_405 = V_405 . V_412 . V_413 [ V_402 ] ;
break;
case V_414 :
V_402 = ( V_2 -> V_129 >> 3 ) & 7 ;
if ( ( V_2 -> V_129 >> 6 ) == 3 )
V_405 = V_405 . V_412 . V_415 -> V_416 [ V_402 ] ;
else
V_405 = V_405 . V_412 . V_415 -> V_417 [ V_402 ] ;
break;
case V_418 :
V_402 = V_2 -> V_129 & 7 ;
V_405 = V_405 . V_412 . V_413 [ V_402 ] ;
break;
case V_419 :
if ( V_2 -> V_9 && V_404 )
return V_312 ;
V_403 = V_404 ? 0x66 : V_2 -> V_9 ;
switch ( V_403 ) {
case 0x00 : V_405 = V_405 . V_412 . V_420 -> V_421 ; break;
case 0x66 : V_405 = V_405 . V_412 . V_420 -> V_422 ; break;
case 0xf2 : V_405 = V_405 . V_412 . V_420 -> V_423 ; break;
case 0xf3 : V_405 = V_405 . V_412 . V_420 -> V_424 ; break;
}
break;
default:
return V_312 ;
}
V_2 -> V_60 &= ~ ( V_108 ) V_410 ;
V_2 -> V_60 |= V_405 . V_99 ;
}
V_2 -> V_425 = V_405 . V_412 . V_425 ;
V_2 -> V_426 = V_405 . V_426 ;
V_2 -> V_4 = V_405 . V_4 ;
if ( V_2 -> V_60 == 0 || ( V_2 -> V_60 & V_427 ) )
return V_312 ;
if ( ! ( V_2 -> V_60 & V_428 ) && V_2 -> V_429 )
return V_312 ;
if ( V_35 == V_36 && ( V_2 -> V_60 & V_430 ) )
V_2 -> V_97 = 8 ;
if ( V_2 -> V_60 & V_431 ) {
if ( V_35 == V_36 )
V_2 -> V_97 = 8 ;
else
V_2 -> V_97 = 4 ;
}
if ( V_2 -> V_60 & V_114 )
V_2 -> V_97 = 16 ;
else if ( V_2 -> V_60 & V_118 )
V_2 -> V_97 = 8 ;
if ( V_2 -> V_60 & V_112 ) {
V_82 = F_43 ( V_2 , & V_2 -> V_371 ) ;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_2 -> V_130 ) ;
} else if ( V_2 -> V_60 & V_432 )
V_82 = F_45 ( V_2 , & V_2 -> V_371 ) ;
if ( V_82 != V_79 )
goto V_145;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_131 ) ;
V_2 -> V_371 . V_65 . V_144 . V_32 = V_34 ( V_2 ) ;
if ( V_2 -> V_371 . type == V_132 && V_2 -> V_20 != 8 )
V_2 -> V_371 . V_65 . V_144 . V_75 = ( T_1 ) V_2 -> V_371 . V_65 . V_144 . V_75 ;
V_82 = F_173 ( V_2 , & V_2 -> V_14 , ( V_2 -> V_60 >> V_433 ) & V_434 ) ;
if ( V_82 != V_79 )
goto V_145;
V_82 = F_173 ( V_2 , & V_2 -> V_203 , ( V_2 -> V_60 >> V_435 ) & V_434 ) ;
if ( V_82 != V_79 )
goto V_145;
V_82 = F_173 ( V_2 , & V_2 -> V_19 , ( V_2 -> V_60 >> V_436 ) & V_434 ) ;
V_145:
if ( V_2 -> V_373 && V_2 -> V_373 -> type == V_132 && V_2 -> V_143 )
V_2 -> V_373 -> V_65 . V_144 . V_75 += V_2 -> V_27 ;
return ( V_82 != V_79 ) ? V_312 : V_313 ;
}
bool F_176 ( struct V_1 * V_2 )
{
return V_2 -> V_60 & V_437 ;
}
static bool F_177 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_113 == 0xa6 ) || ( V_2 -> V_113 == 0xa7 ) ||
( V_2 -> V_113 == 0xae ) || ( V_2 -> V_113 == 0xaf ) )
&& ( ( ( V_2 -> V_9 == V_438 ) &&
( ( V_2 -> V_163 & V_102 ) == 0 ) )
|| ( ( V_2 -> V_9 == V_439 ) &&
( ( V_2 -> V_163 & V_102 ) == V_102 ) ) ) )
return true ;
return false ;
}
static int F_178 ( struct V_1 * V_2 )
{
bool V_440 = false ;
V_2 -> V_23 -> V_109 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_23 -> V_110 ( V_2 ) ;
if ( F_30 ( V_440 ) )
return F_11 ( V_2 , V_441 , 0 , false ) ;
return V_79 ;
}
static void F_179 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
if ( V_106 -> type == V_119 )
F_40 ( V_2 , & V_106 -> V_185 , V_106 -> V_65 . V_120 ) ;
}
int F_180 ( struct V_1 * V_2 )
{
struct V_169 * V_23 = V_2 -> V_23 ;
int V_82 = V_79 ;
int V_442 = V_2 -> V_19 . type ;
V_2 -> V_151 . V_153 = 0 ;
if ( V_2 -> V_35 == V_36 && ( V_2 -> V_60 & V_443 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_145;
}
if ( V_2 -> V_184 && ( ! ( V_2 -> V_60 & V_444 ) || V_2 -> V_19 . type != V_132 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_145;
}
if ( ( V_2 -> V_60 & V_445 ) == V_446 && V_2 -> V_14 . type != V_132 ) {
V_82 = F_15 ( V_2 ) ;
goto V_145;
}
if ( ( ( V_2 -> V_60 & ( V_114 | V_118 ) ) && ( ( V_23 -> V_288 ( V_2 , 0 ) & V_447 ) ) )
|| ( ( V_2 -> V_60 & V_114 ) && ! ( V_23 -> V_288 ( V_2 , 4 ) & V_448 ) ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_145;
}
if ( ( V_2 -> V_60 & ( V_114 | V_118 ) ) && ( V_23 -> V_288 ( V_2 , 0 ) & V_311 ) ) {
V_82 = F_18 ( V_2 ) ;
goto V_145;
}
if ( V_2 -> V_60 & V_118 ) {
V_82 = F_178 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_145;
F_179 ( V_2 , & V_2 -> V_14 ) ;
F_179 ( V_2 , & V_2 -> V_203 ) ;
if ( ! ( V_2 -> V_60 & V_449 ) )
F_179 ( V_2 , & V_2 -> V_19 ) ;
}
if ( F_30 ( V_2 -> V_450 ) && V_2 -> V_4 ) {
V_82 = F_1 ( V_2 , V_2 -> V_4 ,
V_451 ) ;
if ( V_82 != V_79 )
goto V_145;
}
if ( ( V_2 -> V_60 & V_452 ) && V_23 -> V_73 ( V_2 ) ) {
V_82 = F_13 ( V_2 , 0 ) ;
goto V_145;
}
if ( ( V_2 -> V_60 & V_453 ) && ! ( V_2 -> V_35 & V_454 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_145;
}
if ( V_2 -> V_426 ) {
V_82 = V_2 -> V_426 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_145;
}
if ( F_30 ( V_2 -> V_450 ) && V_2 -> V_4 ) {
V_82 = F_1 ( V_2 , V_2 -> V_4 ,
V_455 ) ;
if ( V_82 != V_79 )
goto V_145;
}
if ( V_2 -> V_9 && ( V_2 -> V_60 & String ) ) {
if ( F_3 ( V_2 , V_2 -> V_93 [ V_162 ] ) == 0 ) {
V_2 -> V_22 = V_2 -> V_27 ;
goto V_145;
}
}
if ( ( V_2 -> V_14 . type == V_132 ) && ! ( V_2 -> V_60 & V_456 ) ) {
V_82 = F_48 ( V_2 , V_2 -> V_14 . V_65 . V_144 ,
V_2 -> V_14 . V_218 , V_2 -> V_14 . V_17 ) ;
if ( V_82 != V_79 )
goto V_145;
V_2 -> V_14 . V_223 = V_2 -> V_14 . V_15 ;
}
if ( V_2 -> V_203 . type == V_132 ) {
V_82 = F_48 ( V_2 , V_2 -> V_203 . V_65 . V_144 ,
& V_2 -> V_203 . V_107 , V_2 -> V_203 . V_17 ) ;
if ( V_82 != V_79 )
goto V_145;
}
if ( ( V_2 -> V_60 & V_457 ) == V_458 )
goto V_459;
if ( ( V_2 -> V_19 . type == V_132 ) && ! ( V_2 -> V_60 & V_449 ) ) {
V_82 = F_48 ( V_2 , V_2 -> V_19 . V_65 . V_144 ,
& V_2 -> V_19 . V_107 , V_2 -> V_19 . V_17 ) ;
if ( V_82 != V_79 )
goto V_145;
}
V_2 -> V_19 . V_123 = V_2 -> V_19 . V_107 ;
V_459:
if ( F_30 ( V_2 -> V_450 ) && V_2 -> V_4 ) {
V_82 = F_1 ( V_2 , V_2 -> V_4 ,
V_460 ) ;
if ( V_82 != V_79 )
goto V_145;
}
if ( V_2 -> V_425 ) {
V_82 = V_2 -> V_425 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_145;
goto F_61;
}
if ( V_2 -> V_408 )
goto V_461;
switch ( V_2 -> V_113 ) {
case 0x40 ... 0x47 :
F_81 ( V_2 , L_13 ) ;
break;
case 0x48 ... 0x4f :
F_81 ( V_2 , L_14 ) ;
break;
case 0x63 :
if ( V_2 -> V_35 != V_36 )
goto V_462;
V_2 -> V_19 . V_107 = ( V_142 ) V_2 -> V_14 . V_107 ;
break;
case 0x70 ... 0x7f :
if ( F_34 ( V_2 -> V_113 , V_2 -> V_163 ) )
F_6 ( V_2 , V_2 -> V_14 . V_107 ) ;
break;
case 0x8d :
V_2 -> V_19 . V_107 = V_2 -> V_14 . V_65 . V_144 . V_75 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_19 . V_65 . V_24 == & V_2 -> V_93 [ V_205 ] )
break;
V_82 = F_125 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_97 ) {
case 2 : V_2 -> V_19 . V_107 = ( V_141 ) V_2 -> V_19 . V_107 ; break;
case 4 : V_2 -> V_19 . V_107 = ( V_148 ) V_2 -> V_19 . V_107 ; break;
case 8 : V_2 -> V_19 . V_107 = ( V_142 ) V_2 -> V_19 . V_107 ; break;
}
break;
case 0xc0 ... 0xc1 :
V_82 = F_77 ( V_2 ) ;
break;
case 0xcc :
V_82 = F_73 ( V_2 , 3 ) ;
break;
case 0xcd :
V_82 = F_73 ( V_2 , V_2 -> V_14 . V_107 ) ;
break;
case 0xce :
if ( V_2 -> V_163 & V_100 )
V_82 = F_73 ( V_2 , 4 ) ;
break;
case 0xd0 ... 0xd1 :
V_82 = F_77 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_2 -> V_14 . V_107 = V_2 -> V_93 [ V_162 ] ;
V_82 = F_77 ( V_2 ) ;
break;
case 0xe9 :
case 0xeb :
F_6 ( V_2 , V_2 -> V_14 . V_107 ) ;
V_2 -> V_19 . type = V_186 ;
break;
case 0xf4 :
V_2 -> V_23 -> V_463 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_163 ^= V_101 ;
break;
case 0xf8 :
V_2 -> V_163 &= ~ V_101 ;
break;
case 0xf9 :
V_2 -> V_163 |= V_101 ;
break;
case 0xfc :
V_2 -> V_163 &= ~ V_164 ;
break;
case 0xfd :
V_2 -> V_163 |= V_164 ;
break;
default:
goto V_462;
}
if ( V_82 != V_79 )
goto V_145;
F_61:
V_82 = F_61 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_145;
V_2 -> V_19 . type = V_442 ;
if ( ( V_2 -> V_60 & V_445 ) == V_464 )
F_111 ( V_2 , V_34 ( V_2 ) ,
V_138 , & V_2 -> V_14 ) ;
if ( ( V_2 -> V_60 & V_457 ) == V_465 )
F_111 ( V_2 , V_276 , V_140 ,
& V_2 -> V_19 ) ;
if ( V_2 -> V_9 && ( V_2 -> V_60 & String ) ) {
struct V_149 * V_260 = & V_2 -> V_159 ;
F_5 ( V_2 , & V_2 -> V_93 [ V_162 ] , - 1 ) ;
if ( ! F_177 ( V_2 ) ) {
if ( ( V_260 -> V_88 != 0 || V_2 -> V_93 [ V_162 ] & 0x3ff ) &&
( V_260 -> V_88 == 0 || V_260 -> V_88 != V_260 -> V_153 ) ) {
V_2 -> V_151 . V_88 = 0 ;
return V_466 ;
}
goto V_145;
}
}
V_2 -> V_22 = V_2 -> V_27 ;
V_145:
if ( V_82 == V_45 )
V_2 -> V_467 = true ;
if ( V_82 == V_468 )
return V_469 ;
return ( V_82 == V_92 ) ? V_312 : V_313 ;
V_461:
switch ( V_2 -> V_113 ) {
case 0x09 :
( V_2 -> V_23 -> V_470 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_19 . V_107 = V_23 -> V_288 ( V_2 , V_2 -> V_11 ) ;
break;
case 0x21 :
V_23 -> V_359 ( V_2 , V_2 -> V_11 , & V_2 -> V_19 . V_107 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_19 . V_107 = V_2 -> V_19 . V_123 = V_2 -> V_14 . V_107 ;
if ( ! F_34 ( V_2 -> V_113 , V_2 -> V_163 ) )
V_2 -> V_19 . type = V_186 ;
break;
case 0x80 ... 0x8f :
if ( F_34 ( V_2 -> V_113 , V_2 -> V_163 ) )
F_6 ( V_2 , V_2 -> V_14 . V_107 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_19 . V_107 = F_34 ( V_2 -> V_113 , V_2 -> V_163 ) ;
break;
case 0xa4 :
case 0xa5 :
F_181 ( V_2 , L_30 ) ;
break;
case 0xac :
case 0xad :
F_181 ( V_2 , L_31 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
V_2 -> V_19 . V_107 = ( V_2 -> V_60 & V_122 ) ? ( T_4 ) V_2 -> V_14 . V_107
: ( T_2 ) V_2 -> V_14 . V_107 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
V_2 -> V_19 . V_107 = ( V_2 -> V_60 & V_122 ) ? ( V_141 ) V_2 -> V_14 . V_107 :
( V_148 ) V_2 -> V_14 . V_107 ;
break;
case 0xc0 ... 0xc1 :
F_92 ( V_2 , L_17 ) ;
V_2 -> V_14 . V_107 = V_2 -> V_19 . V_123 ;
F_60 ( & V_2 -> V_14 ) ;
break;
case 0xc3 :
V_2 -> V_19 . V_17 = V_2 -> V_97 ;
V_2 -> V_19 . V_107 = ( V_2 -> V_97 == 4 ) ? ( T_1 ) V_2 -> V_14 . V_107 :
( V_108 ) V_2 -> V_14 . V_107 ;
break;
default:
goto V_462;
}
if ( V_82 != V_79 )
goto V_145;
goto F_61;
V_462:
return V_312 ;
}
