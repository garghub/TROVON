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
static void F_2 ( T_1 * V_24 , T_1 V_14 , T_1 V_25 )
{
* V_24 = ( * V_24 & ~ V_25 ) | ( V_14 & V_25 ) ;
}
static inline unsigned long F_3 ( struct V_1 * V_2 )
{
return ( 1UL << ( V_2 -> V_20 << 3 ) ) - 1 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_26 ;
struct V_27 V_28 ;
if ( V_2 -> V_29 == V_30 )
return ~ 0UL ;
V_2 -> V_23 -> V_31 ( V_2 , & V_26 , & V_28 , NULL , V_32 ) ;
return ~ 0U >> ( ( V_28 . V_33 ^ 1 ) * 16 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return ( F_6 ( F_4 ( V_2 ) ) + 1 ) >> 3 ;
}
static inline unsigned long
F_7 ( struct V_1 * V_2 , unsigned long V_34 )
{
if ( V_2 -> V_20 == sizeof( unsigned long ) )
return V_34 ;
else
return V_34 & F_3 ( V_2 ) ;
}
static inline unsigned long
F_8 ( struct V_1 * V_2 , unsigned long V_34 )
{
return F_7 ( V_2 , V_34 ) ;
}
static void F_9 ( T_1 * V_34 , T_1 V_25 , int V_35 )
{
F_2 ( V_34 , * V_34 + V_35 , V_25 ) ;
}
static inline void
F_10 ( struct V_1 * V_2 , unsigned long * V_34 , int V_35 )
{
T_1 V_25 ;
if ( V_2 -> V_20 == sizeof( unsigned long ) )
V_25 = ~ 0UL ;
else
V_25 = F_3 ( V_2 ) ;
F_9 ( V_34 , V_25 , V_35 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_35 )
{
F_9 ( & V_2 -> V_36 [ V_37 ] , F_4 ( V_2 ) , V_35 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_38 )
{
F_10 ( V_2 , & V_2 -> V_39 , V_38 ) ;
}
static T_3 F_13 ( struct V_27 * V_40 )
{
T_3 V_41 = F_14 ( V_40 ) ;
return V_40 -> V_42 ? ( V_41 << 12 ) | 0xfff : V_41 ;
}
static void F_15 ( struct V_1 * V_2 , int V_43 )
{
V_2 -> V_44 = true ;
V_2 -> V_45 = V_43 ;
}
static unsigned long F_16 ( struct V_1 * V_2 , int V_43 )
{
if ( V_2 -> V_29 == V_30 && V_43 < V_46 )
return 0 ;
return V_2 -> V_23 -> V_47 ( V_2 , V_43 ) ;
}
static unsigned V_45 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_44 )
return 0 ;
return V_2 -> V_45 ;
}
static int F_17 ( struct V_1 * V_2 , int V_48 ,
T_3 error , bool V_49 )
{
V_2 -> V_50 . V_51 = V_48 ;
V_2 -> V_50 . V_52 = error ;
V_2 -> V_50 . V_53 = V_49 ;
return V_54 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_55 , 0 , false ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_56 )
{
return F_17 ( V_2 , V_57 , V_56 , true ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_56 )
{
return F_17 ( V_2 , V_58 , V_56 , true ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_59 , 0 , false ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_56 )
{
return F_17 ( V_2 , V_60 , V_56 , true ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_61 , 0 , false ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_62 , 0 , false ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , unsigned V_43 )
{
T_2 V_63 ;
struct V_27 V_40 ;
V_2 -> V_23 -> V_31 ( V_2 , & V_63 , & V_40 , NULL , V_43 ) ;
return V_63 ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_63 ,
unsigned V_43 )
{
T_2 V_64 ;
T_3 V_65 ;
struct V_27 V_40 ;
V_2 -> V_23 -> V_31 ( V_2 , & V_64 , & V_40 , & V_65 , V_43 ) ;
V_2 -> V_23 -> V_66 ( V_2 , V_63 , & V_40 , V_65 , V_43 ) ;
}
static bool F_27 ( struct V_1 * V_2 , unsigned V_67 )
{
if ( F_28 ( V_67 < 16 ) )
return false ;
if ( V_2 -> V_33 & V_68 )
return true ;
else if ( V_2 -> V_33 & V_69 )
return false ;
else if ( V_2 -> V_33 & V_70 )
return false ;
else
return true ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
unsigned V_67 , bool V_73 , bool V_74 ,
T_1 * V_75 )
{
struct V_27 V_40 ;
bool V_76 ;
T_1 V_77 ;
T_3 V_78 ;
T_2 V_26 ;
unsigned V_79 , V_80 ;
V_77 = F_16 ( V_2 , V_72 . V_43 ) + V_72 . V_81 ;
switch ( V_2 -> V_29 ) {
case V_82 :
break;
case V_30 :
if ( ( ( signed long ) V_77 << 16 ) >> 16 != V_77 )
return F_19 ( V_2 , 0 ) ;
break;
default:
V_76 = V_2 -> V_23 -> V_31 ( V_2 , & V_26 , & V_40 , NULL ,
V_72 . V_43 ) ;
if ( ! V_76 )
goto V_83;
if ( ( ( V_40 . type & 8 ) || ! ( V_40 . type & 2 ) ) && V_73 )
goto V_83;
if ( ! V_74 && ( V_40 . type & 8 ) && ! ( V_40 . type & 2 ) )
goto V_83;
V_78 = F_13 ( & V_40 ) ;
if ( ( V_40 . type & 8 ) || ! ( V_40 . type & 4 ) ) {
if ( V_72 . V_81 > V_78 || ( T_3 ) ( V_72 . V_81 + V_67 - 1 ) > V_78 )
goto V_83;
} else {
if ( V_72 . V_81 <= V_78 || ( T_3 ) ( V_72 . V_81 + V_67 - 1 ) <= V_78 )
goto V_83;
V_78 = V_40 . V_33 ? 0xffffffff : 0xffff ;
if ( V_72 . V_81 > V_78 || ( T_3 ) ( V_72 . V_81 + V_67 - 1 ) > V_78 )
goto V_83;
}
V_79 = V_2 -> V_23 -> V_79 ( V_2 ) ;
V_80 = V_26 & 3 ;
V_79 = F_30 ( V_79 , V_80 ) ;
if ( ! ( V_40 . type & 8 ) ) {
if ( V_79 > V_40 . V_84 )
goto V_83;
} else if ( ( V_40 . type & 8 ) && ! ( V_40 . type & 4 ) ) {
if ( V_79 != V_40 . V_84 )
goto V_83;
} else if ( ( V_40 . type & 8 ) && ( V_40 . type & 4 ) ) {
if ( V_79 < V_40 . V_84 )
goto V_83;
}
break;
}
if ( V_74 ? V_2 -> V_29 != V_30 : V_2 -> V_20 != 8 )
V_77 &= ( T_3 ) - 1 ;
if ( F_27 ( V_2 , V_67 ) && ( ( V_77 & ( V_67 - 1 ) ) != 0 ) )
return F_19 ( V_2 , 0 ) ;
* V_75 = V_77 ;
return V_85 ;
V_83:
if ( V_72 . V_43 == V_32 )
return F_20 ( V_2 , V_72 . V_43 ) ;
else
return F_19 ( V_2 , V_72 . V_43 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
unsigned V_67 , bool V_73 ,
T_1 * V_75 )
{
return F_29 ( V_2 , V_72 , V_67 , V_73 , false , V_75 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
void * V_86 ,
unsigned V_67 )
{
int V_87 ;
T_1 V_75 ;
V_87 = F_31 ( V_2 , V_72 , V_67 , false , & V_75 ) ;
if ( V_87 != V_85 )
return V_87 ;
return V_2 -> V_23 -> V_88 ( V_2 , V_75 , V_86 , V_67 , & V_2 -> V_50 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_4 * V_24 )
{
struct V_89 * V_90 = & V_2 -> V_74 ;
int V_87 ;
int V_67 , V_91 ;
if ( V_2 -> V_39 == V_90 -> V_92 ) {
unsigned long V_75 ;
struct V_71 V_72 = { . V_43 = V_93 ,
. V_81 = V_2 -> V_39 } ;
V_91 = V_90 -> V_92 - V_90 -> V_94 ;
V_67 = F_34 ( 15UL - V_91 ,
V_95 - F_35 ( V_2 -> V_39 ) ) ;
V_87 = F_29 ( V_2 , V_72 , V_67 , false , true , & V_75 ) ;
if ( F_36 ( V_87 != V_85 ) )
return V_87 ;
V_87 = V_2 -> V_23 -> V_74 ( V_2 , V_75 , V_90 -> V_86 + V_91 ,
V_67 , & V_2 -> V_50 ) ;
if ( F_36 ( V_87 != V_85 ) )
return V_87 ;
V_90 -> V_92 += V_67 ;
}
* V_24 = V_90 -> V_86 [ V_2 -> V_39 - V_90 -> V_94 ] ;
V_2 -> V_39 ++ ;
return V_85 ;
}
static int F_37 ( struct V_1 * V_2 ,
void * V_24 , unsigned V_67 )
{
int V_87 ;
if ( F_36 ( V_2 -> V_39 + V_67 - V_2 -> V_22 > 15 ) )
return V_96 ;
while ( V_67 -- ) {
V_87 = F_33 ( V_2 , V_24 ++ ) ;
if ( V_87 != V_85 )
return V_87 ;
}
return V_85 ;
}
static void * F_38 ( T_4 V_11 , unsigned long * V_36 ,
int V_97 )
{
void * V_98 ;
V_98 = & V_36 [ V_11 ] ;
if ( V_97 && V_11 >= 4 && V_11 < 8 )
V_98 = ( unsigned char * ) & V_36 [ V_11 & 3 ] + 1 ;
return V_98 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
T_2 * V_67 , unsigned long * V_99 , int V_100 )
{
int V_87 ;
if ( V_100 == 2 )
V_100 = 3 ;
* V_99 = 0 ;
V_87 = F_32 ( V_2 , V_72 , V_67 , 2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_72 . V_81 += 2 ;
V_87 = F_32 ( V_2 , V_72 , V_99 , V_100 ) ;
return V_87 ;
}
static int F_40 ( unsigned int V_101 , unsigned int V_102 )
{
int V_87 = 0 ;
switch ( ( V_101 & 15 ) >> 1 ) {
case 0 :
V_87 |= ( V_102 & V_103 ) ;
break;
case 1 :
V_87 |= ( V_102 & V_104 ) ;
break;
case 2 :
V_87 |= ( V_102 & V_105 ) ;
break;
case 3 :
V_87 |= ( V_102 & ( V_104 | V_105 ) ) ;
break;
case 4 :
V_87 |= ( V_102 & V_106 ) ;
break;
case 5 :
V_87 |= ( V_102 & V_107 ) ;
break;
case 7 :
V_87 |= ( V_102 & V_105 ) ;
case 6 :
V_87 |= ( ! ( V_102 & V_106 ) != ! ( V_102 & V_103 ) ) ;
break;
}
return ( ! ! V_87 ^ ( V_101 & 1 ) ) ;
}
static void F_41 ( struct V_108 * V_109 )
{
switch ( V_109 -> V_17 ) {
case 1 :
V_109 -> V_110 = * ( T_4 * ) V_109 -> V_72 . V_34 ;
break;
case 2 :
V_109 -> V_110 = * ( T_2 * ) V_109 -> V_72 . V_34 ;
break;
case 4 :
V_109 -> V_110 = * ( T_3 * ) V_109 -> V_72 . V_34 ;
break;
case 8 :
V_109 -> V_110 = * ( V_111 * ) V_109 -> V_72 . V_34 ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , T_5 * V_86 , int V_34 )
{
V_2 -> V_23 -> V_112 ( V_2 ) ;
switch ( V_34 ) {
case 0 : asm("movdqu %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqu %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqu %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqu %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqu %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqu %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqu %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqu %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_43
case 8 : asm("movdqu %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqu %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqu %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqu %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqu %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqu %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqu %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqu %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_44 () ;
}
V_2 -> V_23 -> V_113 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 , T_5 * V_86 ,
int V_34 )
{
V_2 -> V_23 -> V_112 ( V_2 ) ;
switch ( V_34 ) {
case 0 : asm("movdqu %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqu %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqu %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqu %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqu %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqu %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqu %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqu %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_43
case 8 : asm("movdqu %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqu %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqu %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqu %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqu %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqu %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqu %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqu %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_44 () ;
}
V_2 -> V_23 -> V_113 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 , V_111 * V_86 , int V_34 )
{
V_2 -> V_23 -> V_112 ( V_2 ) ;
switch ( V_34 ) {
case 0 : asm("movq %%mm0, %0" : "=m"(*data)); break;
case 1 : asm("movq %%mm1, %0" : "=m"(*data)); break;
case 2 : asm("movq %%mm2, %0" : "=m"(*data)); break;
case 3 : asm("movq %%mm3, %0" : "=m"(*data)); break;
case 4 : asm("movq %%mm4, %0" : "=m"(*data)); break;
case 5 : asm("movq %%mm5, %0" : "=m"(*data)); break;
case 6 : asm("movq %%mm6, %0" : "=m"(*data)); break;
case 7 : asm("movq %%mm7, %0" : "=m"(*data)); break;
default: F_44 () ;
}
V_2 -> V_23 -> V_113 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 , V_111 * V_86 , int V_34 )
{
V_2 -> V_23 -> V_112 ( V_2 ) ;
switch ( V_34 ) {
case 0 : asm("movq %0, %%mm0" : : "m"(*data)); break;
case 1 : asm("movq %0, %%mm1" : : "m"(*data)); break;
case 2 : asm("movq %0, %%mm2" : : "m"(*data)); break;
case 3 : asm("movq %0, %%mm3" : : "m"(*data)); break;
case 4 : asm("movq %0, %%mm4" : : "m"(*data)); break;
case 5 : asm("movq %0, %%mm5" : : "m"(*data)); break;
case 6 : asm("movq %0, %%mm6" : : "m"(*data)); break;
case 7 : asm("movq %0, %%mm7" : : "m"(*data)); break;
default: F_44 () ;
}
V_2 -> V_23 -> V_113 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
unsigned V_34 = V_2 -> V_11 ;
int V_97 = V_2 -> V_114 == 0 ;
if ( ! ( V_2 -> V_33 & V_115 ) )
V_34 = ( V_2 -> V_116 & 7 ) | ( ( V_2 -> V_114 & 1 ) << 3 ) ;
if ( V_2 -> V_33 & V_117 ) {
V_109 -> type = V_118 ;
V_109 -> V_17 = 16 ;
V_109 -> V_72 . V_119 = V_34 ;
F_42 ( V_2 , & V_109 -> V_120 , V_34 ) ;
return;
}
if ( V_2 -> V_33 & V_121 ) {
V_34 &= 7 ;
V_109 -> type = V_122 ;
V_109 -> V_17 = 8 ;
V_109 -> V_72 . V_123 = V_34 ;
return;
}
V_109 -> type = V_124 ;
if ( V_2 -> V_33 & V_125 ) {
V_109 -> V_72 . V_34 = F_38 ( V_34 , V_2 -> V_36 , V_97 ) ;
V_109 -> V_17 = 1 ;
} else {
V_109 -> V_72 . V_34 = F_38 ( V_34 , V_2 -> V_36 , 0 ) ;
V_109 -> V_17 = V_2 -> V_100 ;
}
F_41 ( V_109 ) ;
V_109 -> V_126 = V_109 -> V_110 ;
}
static void F_49 ( struct V_1 * V_2 , int V_127 )
{
if ( V_127 == V_37 || V_127 == V_128 )
V_2 -> V_129 = V_32 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
T_4 V_130 ;
int V_131 = 0 , V_127 = 0 , V_132 ;
int V_87 = V_85 ;
T_1 V_133 = 0 ;
if ( V_2 -> V_114 ) {
V_2 -> V_11 = ( V_2 -> V_114 & 4 ) << 1 ;
V_131 = ( V_2 -> V_114 & 2 ) << 2 ;
V_2 -> V_12 = V_127 = ( V_2 -> V_114 & 1 ) << 3 ;
}
V_2 -> V_10 |= ( V_2 -> V_134 & 0xc0 ) >> 6 ;
V_2 -> V_11 |= ( V_2 -> V_134 & 0x38 ) >> 3 ;
V_2 -> V_12 |= ( V_2 -> V_134 & 0x07 ) ;
V_2 -> V_129 = V_135 ;
if ( V_2 -> V_10 == 3 ) {
V_109 -> type = V_124 ;
V_109 -> V_17 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
V_109 -> V_72 . V_34 = F_38 ( V_2 -> V_12 ,
V_2 -> V_36 , V_2 -> V_33 & V_125 ) ;
if ( V_2 -> V_33 & V_117 ) {
V_109 -> type = V_118 ;
V_109 -> V_17 = 16 ;
V_109 -> V_72 . V_119 = V_2 -> V_12 ;
F_42 ( V_2 , & V_109 -> V_120 , V_2 -> V_12 ) ;
return V_87 ;
}
if ( V_2 -> V_33 & V_121 ) {
V_109 -> type = V_122 ;
V_109 -> V_17 = 8 ;
V_109 -> V_72 . V_119 = V_2 -> V_12 & 7 ;
return V_87 ;
}
F_41 ( V_109 ) ;
return V_87 ;
}
V_109 -> type = V_136 ;
if ( V_2 -> V_20 == 2 ) {
unsigned V_137 = V_2 -> V_36 [ V_138 ] ;
unsigned V_139 = V_2 -> V_36 [ V_128 ] ;
unsigned V_140 = V_2 -> V_36 [ V_141 ] ;
unsigned V_142 = V_2 -> V_36 [ V_143 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 6 )
V_133 += F_51 ( T_2 , V_2 ) ;
break;
case 1 :
V_133 += F_51 ( V_144 , V_2 ) ;
break;
case 2 :
V_133 += F_51 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_12 ) {
case 0 :
V_133 += V_137 + V_140 ;
break;
case 1 :
V_133 += V_137 + V_142 ;
break;
case 2 :
V_133 += V_139 + V_140 ;
break;
case 3 :
V_133 += V_139 + V_142 ;
break;
case 4 :
V_133 += V_140 ;
break;
case 5 :
V_133 += V_142 ;
break;
case 6 :
if ( V_2 -> V_10 != 0 )
V_133 += V_139 ;
break;
case 7 :
V_133 += V_137 ;
break;
}
if ( V_2 -> V_12 == 2 || V_2 -> V_12 == 3 ||
( V_2 -> V_12 == 6 && V_2 -> V_10 != 0 ) )
V_2 -> V_129 = V_32 ;
V_133 = ( T_2 ) V_133 ;
} else {
if ( ( V_2 -> V_12 & 7 ) == 4 ) {
V_130 = F_51 ( T_4 , V_2 ) ;
V_131 |= ( V_130 >> 3 ) & 7 ;
V_127 |= V_130 & 7 ;
V_132 = V_130 >> 6 ;
if ( ( V_127 & 7 ) == 5 && V_2 -> V_10 == 0 )
V_133 += F_51 ( V_145 , V_2 ) ;
else {
V_133 += V_2 -> V_36 [ V_127 ] ;
F_49 ( V_2 , V_127 ) ;
}
if ( V_131 != 4 )
V_133 += V_2 -> V_36 [ V_131 ] << V_132 ;
} else if ( ( V_2 -> V_12 & 7 ) == 5 && V_2 -> V_10 == 0 ) {
if ( V_2 -> V_29 == V_30 )
V_2 -> V_146 = 1 ;
} else {
V_127 = V_2 -> V_12 ;
V_133 += V_2 -> V_36 [ V_127 ] ;
F_49 ( V_2 , V_127 ) ;
}
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 5 )
V_133 += F_51 ( V_145 , V_2 ) ;
break;
case 1 :
V_133 += F_51 ( V_144 , V_2 ) ;
break;
case 2 :
V_133 += F_51 ( V_145 , V_2 ) ;
break;
}
}
V_109 -> V_72 . V_147 . V_81 = V_133 ;
V_148:
return V_87 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
int V_87 = V_85 ;
V_109 -> type = V_136 ;
switch ( V_2 -> V_20 ) {
case 2 :
V_109 -> V_72 . V_147 . V_81 = F_51 ( T_2 , V_2 ) ;
break;
case 4 :
V_109 -> V_72 . V_147 . V_81 = F_51 ( T_3 , V_2 ) ;
break;
case 8 :
V_109 -> V_72 . V_147 . V_81 = F_51 ( V_111 , V_2 ) ;
break;
}
V_148:
return V_87 ;
}
static void F_53 ( struct V_1 * V_2 )
{
long V_149 = 0 , V_25 ;
if ( V_2 -> V_19 . type == V_136 && V_2 -> V_14 . type == V_124 ) {
V_25 = ~ ( V_2 -> V_19 . V_17 * 8 - 1 ) ;
if ( V_2 -> V_14 . V_17 == 2 )
V_149 = ( V_150 ) V_2 -> V_14 . V_110 & ( V_150 ) V_25 ;
else if ( V_2 -> V_14 . V_17 == 4 )
V_149 = ( V_145 ) V_2 -> V_14 . V_110 & ( V_145 ) V_25 ;
V_2 -> V_19 . V_72 . V_147 . V_81 += ( V_149 >> 3 ) ;
}
V_2 -> V_14 . V_110 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
}
static int F_54 ( struct V_1 * V_2 ,
unsigned long V_72 , void * V_24 , unsigned V_67 )
{
int V_87 ;
struct V_151 * V_152 = & V_2 -> V_153 ;
while ( V_67 ) {
int V_154 = F_34 ( V_67 , 8u ) ;
V_67 -= V_154 ;
if ( V_152 -> V_155 < V_152 -> V_92 )
goto V_156;
V_87 = V_2 -> V_23 -> F_54 ( V_2 , V_72 , V_152 -> V_86 + V_152 -> V_92 , V_154 ,
& V_2 -> V_50 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_152 -> V_92 += V_154 ;
V_156:
memcpy ( V_24 , V_152 -> V_86 + V_152 -> V_155 , V_154 ) ;
V_152 -> V_155 += V_154 ;
V_24 += V_154 ;
V_72 += V_154 ;
}
return V_85 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
void * V_86 ,
unsigned V_67 )
{
int V_87 ;
T_1 V_75 ;
V_87 = F_31 ( V_2 , V_72 , V_67 , false , & V_75 ) ;
if ( V_87 != V_85 )
return V_87 ;
return F_54 ( V_2 , V_75 , V_86 , V_67 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
const void * V_86 ,
unsigned V_67 )
{
int V_87 ;
T_1 V_75 ;
V_87 = F_31 ( V_2 , V_72 , V_67 , true , & V_75 ) ;
if ( V_87 != V_85 )
return V_87 ;
return V_2 -> V_23 -> V_157 ( V_2 , V_75 , V_86 , V_67 ,
& V_2 -> V_50 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_71 V_72 ,
const void * V_158 , const void * V_86 ,
unsigned V_67 )
{
int V_87 ;
T_1 V_75 ;
V_87 = F_31 ( V_2 , V_72 , V_67 , true , & V_75 ) ;
if ( V_87 != V_85 )
return V_87 ;
return V_2 -> V_23 -> V_159 ( V_2 , V_75 , V_158 , V_86 ,
V_67 , & V_2 -> V_50 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_67 , unsigned short V_160 ,
void * V_24 )
{
struct V_151 * V_87 = & V_2 -> V_161 ;
if ( V_87 -> V_155 == V_87 -> V_92 ) {
unsigned int V_162 , V_154 ;
unsigned int V_163 = V_2 -> V_9 ?
F_7 ( V_2 , V_2 -> V_36 [ V_164 ] ) : 1 ;
V_162 = ( V_2 -> V_165 & V_166 ) ?
F_35 ( V_2 -> V_36 [ V_143 ] ) :
V_95 - F_35 ( V_2 -> V_36 [ V_143 ] ) ;
V_154 = F_34 ( F_34 ( V_162 , ( unsigned int ) sizeof( V_87 -> V_86 ) ) / V_67 ,
V_163 ) ;
if ( V_154 == 0 )
V_154 = 1 ;
V_87 -> V_155 = V_87 -> V_92 = 0 ;
if ( ! V_2 -> V_23 -> F_58 ( V_2 , V_67 , V_160 , V_87 -> V_86 , V_154 ) )
return 0 ;
V_87 -> V_92 = V_154 * V_67 ;
}
memcpy ( V_24 , V_87 -> V_86 + V_87 -> V_155 , V_67 ) ;
V_87 -> V_155 += V_67 ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_2 V_167 , struct V_27 * V_40 )
{
struct V_168 V_169 ;
T_1 V_72 ;
V_2 -> V_23 -> V_170 ( V_2 , & V_169 ) ;
if ( V_169 . V_67 < V_167 * 8 + 7 )
return F_19 ( V_2 , V_167 << 3 | 0x2 ) ;
V_72 = V_169 . V_99 + V_167 * 8 ;
return V_2 -> V_23 -> V_88 ( V_2 , V_72 , V_40 , sizeof *V_40 ,
& V_2 -> V_50 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
T_2 V_63 , struct V_168 * V_169 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
if ( V_63 & 1 << 2 ) {
struct V_27 V_40 ;
T_2 V_26 ;
memset ( V_169 , 0 , sizeof *V_169 ) ;
if ( ! V_23 -> V_31 ( V_2 , & V_26 , & V_40 , NULL , V_172 ) )
return;
V_169 -> V_67 = F_13 ( & V_40 ) ;
V_169 -> V_99 = F_61 ( & V_40 ) ;
} else
V_23 -> V_173 ( V_2 , V_169 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
T_2 V_63 , struct V_27 * V_40 ,
T_1 * V_174 )
{
struct V_168 V_169 ;
T_2 V_167 = V_63 >> 3 ;
T_1 V_72 ;
F_60 ( V_2 , V_63 , & V_169 ) ;
if ( V_169 . V_67 < V_167 * 8 + 7 )
return F_19 ( V_2 , V_63 & 0xfffc ) ;
* V_174 = V_72 = V_169 . V_99 + V_167 * 8 ;
return V_2 -> V_23 -> V_88 ( V_2 , V_72 , V_40 , sizeof *V_40 ,
& V_2 -> V_50 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
T_2 V_63 , struct V_27 * V_40 )
{
struct V_168 V_169 ;
T_2 V_167 = V_63 >> 3 ;
T_1 V_72 ;
F_60 ( V_2 , V_63 , & V_169 ) ;
if ( V_169 . V_67 < V_167 * 8 + 7 )
return F_19 ( V_2 , V_63 & 0xfffc ) ;
V_72 = V_169 . V_99 + V_167 * 8 ;
return V_2 -> V_23 -> V_175 ( V_2 , V_72 , V_40 , sizeof *V_40 ,
& V_2 -> V_50 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
T_2 V_63 , int V_43 )
{
struct V_27 V_176 , V_177 ;
T_4 V_84 , V_80 , V_79 ;
unsigned V_178 = V_57 ;
T_3 V_179 = 0 ;
bool V_180 = ! ( V_63 & ~ 0x3 ) ;
T_1 V_181 ;
int V_182 ;
memset ( & V_176 , 0 , sizeof V_176 ) ;
if ( ( V_43 <= V_183 && V_2 -> V_29 == V_184 )
|| V_2 -> V_29 == V_82 ) {
F_65 ( & V_176 , V_63 << 4 ) ;
F_66 ( & V_176 , 0xffff ) ;
V_176 . type = 3 ;
V_176 . V_98 = 1 ;
V_176 . V_185 = 1 ;
if ( V_2 -> V_29 == V_184 )
V_176 . V_84 = 3 ;
goto V_186;
}
V_80 = V_63 & 3 ;
V_79 = V_2 -> V_23 -> V_79 ( V_2 ) ;
if ( ( V_43 == V_93
|| ( V_43 == V_32
&& ( V_2 -> V_29 != V_30 || V_80 != V_79 ) )
|| V_43 == V_187 )
&& V_180 )
goto V_50;
if ( V_43 == V_187 && ( V_63 & ( 1 << 2 ) ) )
goto V_50;
if ( V_180 )
goto V_186;
V_182 = F_62 ( V_2 , V_63 , & V_176 , & V_181 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_179 = V_63 & 0xfffc ;
V_178 = V_57 ;
if ( V_43 <= V_183 && ! V_176 . V_185 )
goto V_50;
if ( ! V_176 . V_98 ) {
V_178 = ( V_43 == V_32 ) ? V_58 : V_188 ;
goto V_50;
}
V_84 = V_176 . V_84 ;
switch ( V_43 ) {
case V_32 :
if ( V_80 != V_79 || ( V_176 . type & 0xa ) != 0x2 || V_84 != V_79 )
goto V_50;
break;
case V_93 :
if ( ! ( V_176 . type & 8 ) )
goto V_50;
if ( V_176 . type & 4 ) {
if ( V_84 > V_79 )
goto V_50;
} else {
if ( V_80 > V_79 || V_84 != V_79 )
goto V_50;
}
V_63 = ( V_63 & 0xfffc ) | V_79 ;
break;
case V_187 :
if ( V_176 . V_185 || ( V_176 . type != 1 && V_176 . type != 9 ) )
goto V_50;
V_177 = V_176 ;
V_176 . type |= 2 ;
V_182 = V_2 -> V_23 -> V_159 ( V_2 , V_181 , & V_177 , & V_176 ,
sizeof( V_176 ) , & V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
break;
case V_172 :
if ( V_176 . V_185 || V_176 . type != 2 )
goto V_50;
break;
default:
if ( ( V_176 . type & 0xa ) == 0x8 ||
( ( ( V_176 . type & 0xc ) != 0xc ) &&
( V_80 > V_84 && V_79 > V_84 ) ) )
goto V_50;
break;
}
if ( V_176 . V_185 ) {
V_176 . type |= 1 ;
V_182 = F_63 ( V_2 , V_63 , & V_176 ) ;
if ( V_182 != V_85 )
return V_182 ;
}
V_186:
V_2 -> V_23 -> V_66 ( V_2 , V_63 , & V_176 , 0 , V_43 ) ;
return V_85 ;
V_50:
F_17 ( V_2 , V_178 , V_179 , true ) ;
return V_54 ;
}
static void F_67 ( struct V_108 * V_109 )
{
switch ( V_109 -> V_17 ) {
case 1 :
* ( T_4 * ) V_109 -> V_72 . V_34 = ( T_4 ) V_109 -> V_110 ;
break;
case 2 :
* ( T_2 * ) V_109 -> V_72 . V_34 = ( T_2 ) V_109 -> V_110 ;
break;
case 4 :
* V_109 -> V_72 . V_34 = ( T_3 ) V_109 -> V_110 ;
break;
case 8 :
* V_109 -> V_72 . V_34 = V_109 -> V_110 ;
break;
}
}
static int F_68 ( struct V_1 * V_2 )
{
int V_87 ;
switch ( V_2 -> V_19 . type ) {
case V_124 :
F_67 ( & V_2 -> V_19 ) ;
break;
case V_136 :
if ( V_2 -> V_189 )
V_87 = F_57 ( V_2 ,
V_2 -> V_19 . V_72 . V_147 ,
& V_2 -> V_19 . V_126 ,
& V_2 -> V_19 . V_110 ,
V_2 -> V_19 . V_17 ) ;
else
V_87 = F_56 ( V_2 ,
V_2 -> V_19 . V_72 . V_147 ,
& V_2 -> V_19 . V_110 ,
V_2 -> V_19 . V_17 ) ;
if ( V_87 != V_85 )
return V_87 ;
break;
case V_118 :
F_45 ( V_2 , & V_2 -> V_19 . V_120 , V_2 -> V_19 . V_72 . V_119 ) ;
break;
case V_122 :
F_47 ( V_2 , & V_2 -> V_19 . V_190 , V_2 -> V_19 . V_72 . V_123 ) ;
break;
case V_191 :
break;
default:
break;
}
return V_85 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_86 , int V_17 )
{
struct V_71 V_72 ;
F_11 ( V_2 , - V_17 ) ;
V_72 . V_81 = V_2 -> V_36 [ V_37 ] & F_4 ( V_2 ) ;
V_72 . V_43 = V_32 ;
return F_56 ( V_2 , V_72 , V_86 , V_17 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_191 ;
return F_69 ( V_2 , & V_2 -> V_14 . V_110 , V_2 -> V_100 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
void * V_24 , int V_192 )
{
int V_87 ;
struct V_71 V_72 ;
V_72 . V_81 = V_2 -> V_36 [ V_37 ] & F_4 ( V_2 ) ;
V_72 . V_43 = V_32 ;
V_87 = F_55 ( V_2 , V_72 , V_24 , V_192 ) ;
if ( V_87 != V_85 )
return V_87 ;
F_11 ( V_2 , V_192 ) ;
return V_87 ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_71 ( V_2 , & V_2 -> V_19 . V_110 , V_2 -> V_100 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
void * V_24 , int V_192 )
{
int V_87 ;
unsigned long V_110 , V_193 ;
int V_194 = ( V_2 -> V_165 & V_195 ) >> V_196 ;
int V_79 = V_2 -> V_23 -> V_79 ( V_2 ) ;
V_87 = F_71 ( V_2 , & V_110 , V_192 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_193 = V_104 | V_107 | V_197 | V_105 | V_106 | V_103
| V_198 | V_166 | V_199 | V_200 | V_201 | V_202 ;
switch( V_2 -> V_29 ) {
case V_30 :
case V_203 :
case V_204 :
if ( V_79 == 0 )
V_193 |= V_205 ;
if ( V_79 <= V_194 )
V_193 |= V_206 ;
break;
case V_184 :
if ( V_194 < 3 )
return F_19 ( V_2 , 0 ) ;
V_193 |= V_206 ;
break;
default:
V_193 |= ( V_205 | V_206 ) ;
break;
}
* ( unsigned long * ) V_24 =
( V_2 -> V_165 & ~ V_193 ) | ( V_110 & V_193 ) ;
return V_87 ;
}
static int F_74 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_124 ;
V_2 -> V_19 . V_72 . V_34 = & V_2 -> V_165 ;
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
return F_73 ( V_2 , & V_2 -> V_19 . V_110 , V_2 -> V_100 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_87 ;
unsigned V_207 = V_2 -> V_14 . V_110 ;
unsigned V_208 = V_2 -> V_209 . V_110 & 31 ;
if ( V_208 )
return V_96 ;
V_87 = F_69 ( V_2 , & V_2 -> V_36 [ V_128 ] , F_5 ( V_2 ) ) ;
if ( V_87 != V_85 )
return V_87 ;
F_2 ( & V_2 -> V_36 [ V_128 ] , V_2 -> V_36 [ V_37 ] ,
F_4 ( V_2 ) ) ;
F_2 ( & V_2 -> V_36 [ V_37 ] ,
V_2 -> V_36 [ V_37 ] - V_207 ,
F_4 ( V_2 ) ) ;
return V_85 ;
}
static int F_76 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_36 [ V_37 ] , V_2 -> V_36 [ V_128 ] ,
F_4 ( V_2 ) ) ;
return F_71 ( V_2 , & V_2 -> V_36 [ V_128 ] , V_2 -> V_100 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_43 = V_2 -> V_209 . V_110 ;
V_2 -> V_14 . V_110 = F_25 ( V_2 , V_43 ) ;
return F_70 ( V_2 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_43 = V_2 -> V_209 . V_110 ;
unsigned long V_63 ;
int V_87 ;
V_87 = F_71 ( V_2 , & V_63 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = F_64 ( V_2 , ( T_2 ) V_63 , V_43 ) ;
return V_87 ;
}
static int F_79 ( struct V_1 * V_2 )
{
unsigned long V_210 = V_2 -> V_36 [ V_37 ] ;
int V_87 = V_85 ;
int V_34 = V_211 ;
while ( V_34 <= V_143 ) {
( V_34 == V_37 ) ?
( V_2 -> V_14 . V_110 = V_210 ) : ( V_2 -> V_14 . V_110 = V_2 -> V_36 [ V_34 ] ) ;
V_87 = F_70 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
++ V_34 ;
}
return V_87 ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_110 = ( unsigned long ) V_2 -> V_165 ;
return F_70 ( V_2 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_87 = V_85 ;
int V_34 = V_143 ;
while ( V_34 >= V_211 ) {
if ( V_34 == V_37 ) {
F_11 ( V_2 , V_2 -> V_100 ) ;
-- V_34 ;
}
V_87 = F_71 ( V_2 , & V_2 -> V_36 [ V_34 ] , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
break;
-- V_34 ;
}
return V_87 ;
}
int F_82 ( struct V_1 * V_2 , int V_212 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
int V_87 ;
struct V_168 V_169 ;
T_6 V_213 ;
T_6 V_214 ;
T_2 V_215 , V_22 ;
V_2 -> V_14 . V_110 = V_2 -> V_165 ;
V_87 = F_70 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_165 &= ~ ( V_206 | V_198 | V_201 ) ;
V_2 -> V_14 . V_110 = F_25 ( V_2 , V_93 ) ;
V_87 = F_70 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_14 . V_110 = V_2 -> V_39 ;
V_87 = F_70 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_23 -> V_170 ( V_2 , & V_169 ) ;
V_214 = V_169 . V_99 + ( V_212 << 2 ) ;
V_213 = V_169 . V_99 + ( V_212 << 2 ) + 2 ;
V_87 = V_23 -> V_88 ( V_2 , V_213 , & V_215 , 2 , & V_2 -> V_50 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = V_23 -> V_88 ( V_2 , V_214 , & V_22 , 2 , & V_2 -> V_50 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = F_64 ( V_2 , V_215 , V_93 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_39 = V_22 ;
return V_87 ;
}
static int F_83 ( struct V_1 * V_2 , int V_212 )
{
switch( V_2 -> V_29 ) {
case V_82 :
return F_82 ( V_2 , V_212 ) ;
case V_184 :
case V_204 :
case V_203 :
case V_30 :
default:
return V_96 ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
int V_87 = V_85 ;
unsigned long V_216 = 0 ;
unsigned long V_217 = 0 ;
unsigned long V_215 = 0 ;
unsigned long V_25 = V_104 | V_107 | V_197 | V_105 | V_106 | V_198 |
V_206 | V_166 | V_103 | V_205 | V_199 | V_200 |
V_201 | V_202 | ( 1 << 1 ) ;
unsigned long V_218 = V_219 | V_220 | V_221 ;
V_87 = F_71 ( V_2 , & V_216 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
if ( V_216 & ~ 0xffff )
return F_19 ( V_2 , 0 ) ;
V_87 = F_71 ( V_2 , & V_215 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = F_71 ( V_2 , & V_217 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = F_64 ( V_2 , ( T_2 ) V_215 , V_93 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_39 = V_216 ;
if ( V_2 -> V_100 == 4 )
V_2 -> V_165 = ( ( V_217 & V_25 ) | ( V_2 -> V_165 & V_218 ) ) ;
else if ( V_2 -> V_100 == 2 ) {
V_2 -> V_165 &= ~ 0xffff ;
V_2 -> V_165 |= V_217 ;
}
V_2 -> V_165 &= ~ V_222 ;
V_2 -> V_165 |= V_223 ;
return V_87 ;
}
static int F_85 ( struct V_1 * V_2 )
{
switch( V_2 -> V_29 ) {
case V_82 :
return F_84 ( V_2 ) ;
case V_184 :
case V_204 :
case V_203 :
case V_30 :
default:
return V_96 ;
}
}
static int F_86 ( struct V_1 * V_2 )
{
int V_87 ;
unsigned short V_26 ;
memcpy ( & V_26 , V_2 -> V_14 . V_224 + V_2 -> V_100 , 2 ) ;
V_87 = F_64 ( V_2 , V_26 , V_93 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_39 = 0 ;
memcpy ( & V_2 -> V_39 , V_2 -> V_14 . V_224 , V_2 -> V_100 ) ;
return V_85 ;
}
static int F_87 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case 0 :
F_88 ( V_2 , L_1 ) ;
break;
case 1 :
F_88 ( V_2 , L_2 ) ;
break;
case 2 :
F_88 ( V_2 , L_3 ) ;
break;
case 3 :
F_88 ( V_2 , L_4 ) ;
break;
case 4 :
case 6 :
F_88 ( V_2 , L_5 ) ;
break;
case 5 :
F_88 ( V_2 , L_6 ) ;
break;
case 7 :
F_88 ( V_2 , L_7 ) ;
break;
}
return V_85 ;
}
static int F_89 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_110 = ~ V_2 -> V_19 . V_110 ;
return V_85 ;
}
static int F_90 ( struct V_1 * V_2 )
{
F_91 ( V_2 , L_8 ) ;
return V_85 ;
}
static int F_92 ( struct V_1 * V_2 )
{
T_4 V_225 = 0 ;
F_93 ( V_2 , L_9 , V_225 ) ;
return V_85 ;
}
static int F_94 ( struct V_1 * V_2 )
{
T_4 V_225 = 0 ;
F_93 ( V_2 , L_10 , V_225 ) ;
return V_85 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_4 V_226 = 0 ;
F_93 ( V_2 , L_11 , V_226 ) ;
if ( V_226 )
return F_23 ( V_2 ) ;
return V_85 ;
}
static int F_96 ( struct V_1 * V_2 )
{
T_4 V_226 = 0 ;
F_93 ( V_2 , L_12 , V_226 ) ;
if ( V_226 )
return F_23 ( V_2 ) ;
return V_85 ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_87 = V_85 ;
switch ( V_2 -> V_11 ) {
case 0 :
F_91 ( V_2 , L_13 ) ;
break;
case 1 :
F_91 ( V_2 , L_14 ) ;
break;
case 2 : {
long int V_227 ;
V_227 = V_2 -> V_39 ;
V_2 -> V_39 = V_2 -> V_14 . V_110 ;
V_2 -> V_14 . V_110 = V_227 ;
V_87 = F_70 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_39 = V_2 -> V_14 . V_110 ;
break;
case 5 :
V_87 = F_86 ( V_2 ) ;
break;
case 6 :
V_87 = F_70 ( V_2 ) ;
break;
}
return V_87 ;
}
static int F_98 ( struct V_1 * V_2 )
{
V_111 V_228 = V_2 -> V_19 . V_229 ;
if ( ( ( T_3 ) ( V_228 >> 0 ) != ( T_3 ) V_2 -> V_36 [ V_211 ] ) ||
( ( T_3 ) ( V_228 >> 32 ) != ( T_3 ) V_2 -> V_36 [ V_230 ] ) ) {
V_2 -> V_36 [ V_211 ] = ( T_3 ) ( V_228 >> 0 ) ;
V_2 -> V_36 [ V_230 ] = ( T_3 ) ( V_228 >> 32 ) ;
V_2 -> V_165 &= ~ V_105 ;
} else {
V_2 -> V_19 . V_15 = ( ( V_111 ) V_2 -> V_36 [ V_164 ] << 32 ) |
( T_3 ) V_2 -> V_36 [ V_138 ] ;
V_2 -> V_165 |= V_105 ;
}
return V_85 ;
}
static int F_99 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_124 ;
V_2 -> V_19 . V_72 . V_34 = & V_2 -> V_39 ;
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
return F_72 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_87 ;
unsigned long V_215 ;
V_87 = F_71 ( V_2 , & V_2 -> V_39 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
if ( V_2 -> V_100 == 4 )
V_2 -> V_39 = ( T_3 ) V_2 -> V_39 ;
V_87 = F_71 ( V_2 , & V_215 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_87 = F_64 ( V_2 , ( T_2 ) V_215 , V_93 ) ;
return V_87 ;
}
static int F_101 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_126 = V_2 -> V_14 . V_110 ;
V_2 -> V_14 . V_110 = V_2 -> V_36 [ V_211 ] ;
F_102 ( V_2 , L_15 ) ;
if ( V_2 -> V_165 & V_105 ) {
V_2 -> V_19 . V_110 = V_2 -> V_14 . V_126 ;
} else {
V_2 -> V_19 . type = V_124 ;
V_2 -> V_19 . V_72 . V_34 = ( unsigned long * ) & V_2 -> V_36 [ V_211 ] ;
}
return V_85 ;
}
static int F_103 ( struct V_1 * V_2 )
{
int V_43 = V_2 -> V_209 . V_110 ;
unsigned short V_26 ;
int V_87 ;
memcpy ( & V_26 , V_2 -> V_14 . V_224 + V_2 -> V_100 , 2 ) ;
V_87 = F_64 ( V_2 , V_26 , V_43 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_19 . V_110 = V_2 -> V_14 . V_110 ;
return V_87 ;
}
static void
F_104 ( struct V_1 * V_2 ,
struct V_27 * V_215 , struct V_27 * V_28 )
{
T_2 V_63 ;
memset ( V_215 , 0 , sizeof( struct V_27 ) ) ;
V_2 -> V_23 -> V_31 ( V_2 , & V_63 , V_215 , NULL , V_93 ) ;
memset ( V_28 , 0 , sizeof( struct V_27 ) ) ;
V_215 -> V_231 = 0 ;
F_65 ( V_215 , 0 ) ;
V_215 -> V_42 = 1 ;
F_66 ( V_215 , 0xfffff ) ;
V_215 -> type = 0x0b ;
V_215 -> V_185 = 1 ;
V_215 -> V_84 = 0 ;
V_215 -> V_98 = 1 ;
V_215 -> V_33 = 1 ;
F_65 ( V_28 , 0 ) ;
F_66 ( V_28 , 0xfffff ) ;
V_28 -> V_42 = 1 ;
V_28 -> V_185 = 1 ;
V_28 -> type = 0x03 ;
V_28 -> V_33 = 1 ;
V_28 -> V_84 = 0 ;
V_28 -> V_98 = 1 ;
}
static bool F_105 ( struct V_1 * V_2 )
{
T_3 V_232 , V_233 , V_234 , V_235 ;
V_232 = V_234 = 0 ;
V_2 -> V_23 -> V_236 ( V_2 , & V_232 , & V_233 , & V_234 , & V_235 ) ;
return V_233 == V_237
&& V_234 == V_238
&& V_235 == V_239 ;
}
static bool F_106 ( struct V_1 * V_2 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
T_3 V_232 , V_233 , V_234 , V_235 ;
if ( V_2 -> V_29 == V_30 )
return true ;
V_232 = 0x00000000 ;
V_234 = 0x00000000 ;
V_23 -> V_236 ( V_2 , & V_232 , & V_233 , & V_234 , & V_235 ) ;
if ( V_233 == V_237 &&
V_234 == V_238 &&
V_235 == V_239 )
return false ;
if ( V_233 == V_240 &&
V_234 == V_241 &&
V_235 == V_242 )
return true ;
if ( V_233 == V_243 &&
V_234 == V_244 &&
V_235 == V_245 )
return true ;
return false ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_27 V_215 , V_28 ;
V_111 V_246 ;
T_2 V_247 , V_248 ;
V_111 V_249 = 0 ;
if ( V_2 -> V_29 == V_82 ||
V_2 -> V_29 == V_184 )
return F_21 ( V_2 ) ;
if ( ! ( F_106 ( V_2 ) ) )
return F_21 ( V_2 ) ;
V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
F_104 ( V_2 , & V_215 , & V_28 ) ;
if ( ! ( V_249 & V_252 ) )
return F_21 ( V_2 ) ;
V_23 -> V_250 ( V_2 , V_253 , & V_246 ) ;
V_246 >>= 32 ;
V_247 = ( T_2 ) ( V_246 & 0xfffc ) ;
V_248 = ( T_2 ) ( V_246 + 8 ) ;
if ( V_249 & V_254 ) {
V_215 . V_33 = 0 ;
V_215 . V_231 = 1 ;
}
V_23 -> V_66 ( V_2 , V_247 , & V_215 , 0 , V_93 ) ;
V_23 -> V_66 ( V_2 , V_248 , & V_28 , 0 , V_32 ) ;
V_2 -> V_36 [ V_164 ] = V_2 -> V_39 ;
if ( V_249 & V_254 ) {
#ifdef F_43
V_2 -> V_36 [ V_255 ] = V_2 -> V_165 & ~ V_200 ;
V_23 -> V_250 ( V_2 ,
V_2 -> V_29 == V_30 ?
V_256 : V_257 , & V_246 ) ;
V_2 -> V_39 = V_246 ;
V_23 -> V_250 ( V_2 , V_258 , & V_246 ) ;
V_2 -> V_165 &= ~ ( V_246 | V_200 ) ;
#endif
} else {
V_23 -> V_250 ( V_2 , V_253 , & V_246 ) ;
V_2 -> V_39 = ( T_3 ) V_246 ;
V_2 -> V_165 &= ~ ( V_219 | V_206 | V_200 ) ;
}
return V_85 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_27 V_215 , V_28 ;
V_111 V_246 ;
T_2 V_247 , V_248 ;
V_111 V_249 = 0 ;
V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
if ( V_2 -> V_29 == V_82 )
return F_19 ( V_2 , 0 ) ;
if ( ( V_2 -> V_29 == V_203 ) && ( V_249 & V_254 )
&& ! F_105 ( V_2 ) )
return F_21 ( V_2 ) ;
if ( V_2 -> V_29 == V_30 )
return F_21 ( V_2 ) ;
F_104 ( V_2 , & V_215 , & V_28 ) ;
V_23 -> V_250 ( V_2 , V_259 , & V_246 ) ;
switch ( V_2 -> V_29 ) {
case V_203 :
if ( ( V_246 & 0xfffc ) == 0x0 )
return F_19 ( V_2 , 0 ) ;
break;
case V_30 :
if ( V_246 == 0x0 )
return F_19 ( V_2 , 0 ) ;
break;
}
V_2 -> V_165 &= ~ ( V_219 | V_206 | V_200 ) ;
V_247 = ( T_2 ) V_246 ;
V_247 &= ~ V_260 ;
V_248 = V_247 + 8 ;
V_248 &= ~ V_260 ;
if ( V_2 -> V_29 == V_30 || ( V_249 & V_254 ) ) {
V_215 . V_33 = 0 ;
V_215 . V_231 = 1 ;
}
V_23 -> V_66 ( V_2 , V_247 , & V_215 , 0 , V_93 ) ;
V_23 -> V_66 ( V_2 , V_248 , & V_28 , 0 , V_32 ) ;
V_23 -> V_250 ( V_2 , V_261 , & V_246 ) ;
V_2 -> V_39 = V_246 ;
V_23 -> V_250 ( V_2 , V_262 , & V_246 ) ;
V_2 -> V_36 [ V_37 ] = V_246 ;
return V_85 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_27 V_215 , V_28 ;
V_111 V_246 ;
int V_263 ;
T_2 V_247 = 0 , V_248 = 0 ;
if ( V_2 -> V_29 == V_82 ||
V_2 -> V_29 == V_184 )
return F_19 ( V_2 , 0 ) ;
F_104 ( V_2 , & V_215 , & V_28 ) ;
if ( ( V_2 -> V_114 & 0x8 ) != 0x0 )
V_263 = V_30 ;
else
V_263 = V_203 ;
V_215 . V_84 = 3 ;
V_28 . V_84 = 3 ;
V_23 -> V_250 ( V_2 , V_259 , & V_246 ) ;
switch ( V_263 ) {
case V_203 :
V_247 = ( T_2 ) ( V_246 + 16 ) ;
if ( ( V_246 & 0xfffc ) == 0x0 )
return F_19 ( V_2 , 0 ) ;
V_248 = ( T_2 ) ( V_246 + 24 ) ;
break;
case V_30 :
V_247 = ( T_2 ) ( V_246 + 32 ) ;
if ( V_246 == 0x0 )
return F_19 ( V_2 , 0 ) ;
V_248 = V_247 + 8 ;
V_215 . V_33 = 0 ;
V_215 . V_231 = 1 ;
break;
}
V_247 |= V_260 ;
V_248 |= V_260 ;
V_23 -> V_66 ( V_2 , V_247 , & V_215 , 0 , V_93 ) ;
V_23 -> V_66 ( V_2 , V_248 , & V_28 , 0 , V_32 ) ;
V_2 -> V_39 = V_2 -> V_36 [ V_230 ] ;
V_2 -> V_36 [ V_37 ] = V_2 -> V_36 [ V_164 ] ;
return V_85 ;
}
static bool F_110 ( struct V_1 * V_2 )
{
int V_194 ;
if ( V_2 -> V_29 == V_82 )
return false ;
if ( V_2 -> V_29 == V_184 )
return true ;
V_194 = ( V_2 -> V_165 & V_195 ) >> V_196 ;
return V_2 -> V_23 -> V_79 ( V_2 ) > V_194 ;
}
static bool F_111 ( struct V_1 * V_2 ,
T_2 V_160 , T_2 V_192 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_27 V_264 ;
T_3 V_65 ;
int V_265 ;
T_2 V_266 , V_267 , V_268 , V_269 = V_160 & 0x7 ;
unsigned V_25 = ( 1 << V_192 ) - 1 ;
unsigned long V_270 ;
V_23 -> V_31 ( V_2 , & V_266 , & V_264 , & V_65 , V_187 ) ;
if ( ! V_264 . V_98 )
return false ;
if ( F_13 ( & V_264 ) < 103 )
return false ;
V_270 = F_61 ( & V_264 ) ;
#ifdef F_43
V_270 |= ( ( V_111 ) V_65 ) << 32 ;
#endif
V_265 = V_23 -> V_88 ( V_2 , V_270 + 102 , & V_267 , 2 , NULL ) ;
if ( V_265 != V_85 )
return false ;
if ( V_267 + V_160 / 8 > F_13 ( & V_264 ) )
return false ;
V_265 = V_23 -> V_88 ( V_2 , V_270 + V_267 + V_160 / 8 , & V_268 , 2 , NULL ) ;
if ( V_265 != V_85 )
return false ;
if ( ( V_268 >> V_269 ) & V_25 )
return false ;
return true ;
}
static bool F_112 ( struct V_1 * V_2 ,
T_2 V_160 , T_2 V_192 )
{
if ( V_2 -> V_271 )
return true ;
if ( F_110 ( V_2 ) )
if ( ! F_111 ( V_2 , V_160 , V_192 ) )
return false ;
V_2 -> V_271 = true ;
return true ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
V_273 -> V_274 = V_2 -> V_39 ;
V_273 -> V_275 = V_2 -> V_165 ;
V_273 -> V_276 = V_2 -> V_36 [ V_211 ] ;
V_273 -> V_277 = V_2 -> V_36 [ V_164 ] ;
V_273 -> V_278 = V_2 -> V_36 [ V_230 ] ;
V_273 -> V_137 = V_2 -> V_36 [ V_138 ] ;
V_273 -> V_279 = V_2 -> V_36 [ V_37 ] ;
V_273 -> V_139 = V_2 -> V_36 [ V_128 ] ;
V_273 -> V_140 = V_2 -> V_36 [ V_141 ] ;
V_273 -> V_142 = V_2 -> V_36 [ V_143 ] ;
V_273 -> V_280 = F_25 ( V_2 , V_281 ) ;
V_273 -> V_215 = F_25 ( V_2 , V_93 ) ;
V_273 -> V_28 = F_25 ( V_2 , V_32 ) ;
V_273 -> V_282 = F_25 ( V_2 , V_135 ) ;
V_273 -> V_283 = F_25 ( V_2 , V_172 ) ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_272 * V_273 )
{
int V_182 ;
V_2 -> V_39 = V_273 -> V_274 ;
V_2 -> V_165 = V_273 -> V_275 | 2 ;
V_2 -> V_36 [ V_211 ] = V_273 -> V_276 ;
V_2 -> V_36 [ V_164 ] = V_273 -> V_277 ;
V_2 -> V_36 [ V_230 ] = V_273 -> V_278 ;
V_2 -> V_36 [ V_138 ] = V_273 -> V_137 ;
V_2 -> V_36 [ V_37 ] = V_273 -> V_279 ;
V_2 -> V_36 [ V_128 ] = V_273 -> V_139 ;
V_2 -> V_36 [ V_141 ] = V_273 -> V_140 ;
V_2 -> V_36 [ V_143 ] = V_273 -> V_142 ;
F_26 ( V_2 , V_273 -> V_283 , V_172 ) ;
F_26 ( V_2 , V_273 -> V_280 , V_281 ) ;
F_26 ( V_2 , V_273 -> V_215 , V_93 ) ;
F_26 ( V_2 , V_273 -> V_28 , V_32 ) ;
F_26 ( V_2 , V_273 -> V_282 , V_135 ) ;
V_182 = F_64 ( V_2 , V_273 -> V_283 , V_172 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_280 , V_281 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_215 , V_93 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_28 , V_32 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_282 , V_135 ) ;
if ( V_182 != V_85 )
return V_182 ;
return V_85 ;
}
static int F_115 ( struct V_1 * V_2 ,
T_2 V_284 , T_2 V_285 ,
T_1 V_286 , struct V_27 * V_287 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_272 V_288 ;
int V_182 ;
T_3 V_289 = F_61 ( V_287 ) ;
V_182 = V_23 -> V_88 ( V_2 , V_286 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
F_113 ( V_2 , & V_288 ) ;
V_182 = V_23 -> V_175 ( V_2 , V_286 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = V_23 -> V_88 ( V_2 , V_289 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
if ( V_285 != 0xffff ) {
V_288 . V_290 = V_285 ;
V_182 = V_23 -> V_175 ( V_2 , V_289 ,
& V_288 . V_290 ,
sizeof V_288 . V_290 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
}
return F_114 ( V_2 , & V_288 ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_291 * V_273 )
{
V_273 -> V_292 = V_2 -> V_23 -> V_293 ( V_2 , 3 ) ;
V_273 -> V_22 = V_2 -> V_39 ;
V_273 -> V_165 = V_2 -> V_165 ;
V_273 -> V_232 = V_2 -> V_36 [ V_211 ] ;
V_273 -> V_234 = V_2 -> V_36 [ V_164 ] ;
V_273 -> V_235 = V_2 -> V_36 [ V_230 ] ;
V_273 -> V_233 = V_2 -> V_36 [ V_138 ] ;
V_273 -> V_294 = V_2 -> V_36 [ V_37 ] ;
V_273 -> V_295 = V_2 -> V_36 [ V_128 ] ;
V_273 -> V_296 = V_2 -> V_36 [ V_141 ] ;
V_273 -> V_297 = V_2 -> V_36 [ V_143 ] ;
V_273 -> V_280 = F_25 ( V_2 , V_281 ) ;
V_273 -> V_215 = F_25 ( V_2 , V_93 ) ;
V_273 -> V_28 = F_25 ( V_2 , V_32 ) ;
V_273 -> V_282 = F_25 ( V_2 , V_135 ) ;
V_273 -> V_298 = F_25 ( V_2 , V_46 ) ;
V_273 -> V_299 = F_25 ( V_2 , V_183 ) ;
V_273 -> V_300 = F_25 ( V_2 , V_172 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_291 * V_273 )
{
int V_182 ;
if ( V_2 -> V_23 -> V_301 ( V_2 , 3 , V_273 -> V_292 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_39 = V_273 -> V_22 ;
V_2 -> V_165 = V_273 -> V_165 | 2 ;
V_2 -> V_36 [ V_211 ] = V_273 -> V_232 ;
V_2 -> V_36 [ V_164 ] = V_273 -> V_234 ;
V_2 -> V_36 [ V_230 ] = V_273 -> V_235 ;
V_2 -> V_36 [ V_138 ] = V_273 -> V_233 ;
V_2 -> V_36 [ V_37 ] = V_273 -> V_294 ;
V_2 -> V_36 [ V_128 ] = V_273 -> V_295 ;
V_2 -> V_36 [ V_141 ] = V_273 -> V_296 ;
V_2 -> V_36 [ V_143 ] = V_273 -> V_297 ;
F_26 ( V_2 , V_273 -> V_300 , V_172 ) ;
F_26 ( V_2 , V_273 -> V_280 , V_281 ) ;
F_26 ( V_2 , V_273 -> V_215 , V_93 ) ;
F_26 ( V_2 , V_273 -> V_28 , V_32 ) ;
F_26 ( V_2 , V_273 -> V_282 , V_135 ) ;
F_26 ( V_2 , V_273 -> V_298 , V_46 ) ;
F_26 ( V_2 , V_273 -> V_299 , V_183 ) ;
if ( V_2 -> V_165 & V_302 )
V_2 -> V_29 = V_184 ;
else
V_2 -> V_29 = V_203 ;
V_2 -> V_23 -> V_303 ( V_2 , V_2 -> V_165 ) ;
V_182 = F_64 ( V_2 , V_273 -> V_300 , V_172 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_280 , V_281 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_215 , V_93 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_28 , V_32 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_282 , V_135 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_298 , V_46 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_64 ( V_2 , V_273 -> V_299 , V_183 ) ;
if ( V_182 != V_85 )
return V_182 ;
return V_85 ;
}
static int F_118 ( struct V_1 * V_2 ,
T_2 V_284 , T_2 V_285 ,
T_1 V_286 , struct V_27 * V_287 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_291 V_288 ;
int V_182 ;
T_3 V_289 = F_61 ( V_287 ) ;
V_182 = V_23 -> V_88 ( V_2 , V_286 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
F_116 ( V_2 , & V_288 ) ;
V_182 = V_23 -> V_175 ( V_2 , V_286 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = V_23 -> V_88 ( V_2 , V_289 , & V_288 , sizeof V_288 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
if ( V_285 != 0xffff ) {
V_288 . V_290 = V_285 ;
V_182 = V_23 -> V_175 ( V_2 , V_289 ,
& V_288 . V_290 ,
sizeof V_288 . V_290 ,
& V_2 -> V_50 ) ;
if ( V_182 != V_85 )
return V_182 ;
}
return F_117 ( V_2 , & V_288 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
T_2 V_284 , int V_304 , int V_305 ,
bool V_306 , T_3 V_52 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
struct V_27 V_307 , V_308 ;
int V_182 ;
T_2 V_285 = F_25 ( V_2 , V_187 ) ;
T_1 V_286 =
V_23 -> V_47 ( V_2 , V_187 ) ;
T_3 V_309 ;
T_1 V_181 ;
V_182 = F_62 ( V_2 , V_284 , & V_308 , & V_181 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_182 = F_62 ( V_2 , V_285 , & V_307 , & V_181 ) ;
if ( V_182 != V_85 )
return V_182 ;
if ( V_305 == V_310 ) {
if ( V_304 != - 1 ) {
struct V_27 V_311 ;
int V_84 ;
V_182 = F_59 ( V_2 , V_304 ,
& V_311 ) ;
if ( V_182 != V_85 )
return V_182 ;
V_84 = V_311 . V_84 ;
if ( ( V_284 & 3 ) > V_84 || V_23 -> V_79 ( V_2 ) > V_84 )
return F_19 ( V_2 , ( V_304 << 3 ) | 0x2 ) ;
}
} else if ( V_305 != V_312 ) {
int V_84 = V_308 . V_84 ;
if ( ( V_284 & 3 ) > V_84 || V_23 -> V_79 ( V_2 ) > V_84 )
return F_19 ( V_2 , V_284 ) ;
}
V_309 = F_13 ( & V_308 ) ;
if ( ! V_308 . V_98 ||
( ( V_309 < 0x67 && ( V_308 . type & 8 ) ) ||
V_309 < 0x2b ) ) {
F_22 ( V_2 , V_284 & 0xfffc ) ;
return V_54 ;
}
if ( V_305 == V_312 || V_305 == V_313 ) {
V_307 . type &= ~ ( 1 << 1 ) ;
F_63 ( V_2 , V_285 , & V_307 ) ;
}
if ( V_305 == V_312 )
V_2 -> V_165 = V_2 -> V_165 & ~ V_314 ;
if ( V_305 != V_315 && V_305 != V_310 )
V_285 = 0xffff ;
if ( V_308 . type & 8 )
V_182 = F_118 ( V_2 , V_284 , V_285 ,
V_286 , & V_308 ) ;
else
V_182 = F_115 ( V_2 , V_284 , V_285 ,
V_286 , & V_308 ) ;
if ( V_182 != V_85 )
return V_182 ;
if ( V_305 == V_315 || V_305 == V_310 )
V_2 -> V_165 = V_2 -> V_165 | V_314 ;
if ( V_305 != V_312 ) {
V_308 . type |= ( 1 << 1 ) ;
F_63 ( V_2 , V_284 , & V_308 ) ;
}
V_23 -> V_301 ( V_2 , 0 , V_23 -> V_293 ( V_2 , 0 ) | V_316 ) ;
V_23 -> V_66 ( V_2 , V_284 , & V_308 , 0 , V_187 ) ;
if ( V_306 ) {
V_2 -> V_100 = V_2 -> V_20 = ( V_308 . type & 8 ) ? 4 : 2 ;
V_2 -> V_189 = 0 ;
V_2 -> V_14 . V_110 = ( unsigned long ) V_52 ;
V_182 = F_70 ( V_2 ) ;
}
return V_182 ;
}
int F_120 ( struct V_1 * V_2 ,
T_2 V_284 , int V_304 , int V_305 ,
bool V_306 , T_3 V_52 )
{
int V_87 ;
V_2 -> V_39 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_191 ;
V_87 = F_119 ( V_2 , V_284 , V_304 , V_305 ,
V_306 , V_52 ) ;
if ( V_87 == V_85 )
V_2 -> V_22 = V_2 -> V_39 ;
return ( V_87 == V_96 ) ? V_317 : V_318 ;
}
static void F_121 ( struct V_1 * V_2 , unsigned V_43 ,
int V_34 , struct V_108 * V_109 )
{
int V_319 = ( V_2 -> V_165 & V_166 ) ? - 1 : 1 ;
F_10 ( V_2 , & V_2 -> V_36 [ V_34 ] , V_319 * V_109 -> V_17 ) ;
V_109 -> V_72 . V_147 . V_81 = F_8 ( V_2 , V_2 -> V_36 [ V_34 ] ) ;
V_109 -> V_72 . V_147 . V_43 = V_43 ;
}
static int F_122 ( struct V_1 * V_2 )
{
T_4 V_320 , V_321 ;
bool V_322 , V_323 , V_324 ;
V_323 = V_2 -> V_165 & V_325 ;
V_320 = V_2 -> V_19 . V_110 ;
V_321 = V_320 ;
V_324 = V_323 ;
V_323 = false ;
V_322 = V_2 -> V_165 & V_326 ;
if ( ( V_320 & 0x0f ) > 9 || V_322 ) {
V_320 -= 6 ;
V_323 = V_324 | ( V_320 >= 250 ) ;
V_322 = true ;
} else {
V_322 = false ;
}
if ( V_321 > 0x99 || V_324 ) {
V_320 -= 0x60 ;
V_323 = true ;
}
V_2 -> V_19 . V_110 = V_320 ;
V_2 -> V_14 . type = V_327 ;
V_2 -> V_14 . V_110 = 0 ;
V_2 -> V_14 . V_17 = 1 ;
F_102 ( V_2 , L_16 ) ;
V_2 -> V_165 &= ~ ( V_326 | V_325 ) ;
if ( V_323 )
V_2 -> V_165 |= V_325 ;
if ( V_322 )
V_2 -> V_165 |= V_326 ;
return V_85 ;
}
static int F_123 ( struct V_1 * V_2 )
{
long V_38 = V_2 -> V_14 . V_110 ;
V_2 -> V_14 . V_110 = ( unsigned long ) V_2 -> V_39 ;
F_12 ( V_2 , V_38 ) ;
return F_70 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
T_2 V_26 , V_328 ;
T_1 V_227 ;
int V_87 ;
V_328 = F_25 ( V_2 , V_93 ) ;
V_227 = V_2 -> V_39 ;
memcpy ( & V_26 , V_2 -> V_14 . V_224 + V_2 -> V_100 , 2 ) ;
if ( F_64 ( V_2 , V_26 , V_93 ) )
return V_85 ;
V_2 -> V_39 = 0 ;
memcpy ( & V_2 -> V_39 , V_2 -> V_14 . V_224 , V_2 -> V_100 ) ;
V_2 -> V_14 . V_110 = V_328 ;
V_87 = F_70 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_14 . V_110 = V_227 ;
return F_70 ( V_2 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
int V_87 ;
V_2 -> V_19 . type = V_124 ;
V_2 -> V_19 . V_72 . V_34 = & V_2 -> V_39 ;
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
V_87 = F_71 ( V_2 , & V_2 -> V_19 . V_110 , V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
F_11 ( V_2 , V_2 -> V_14 . V_110 ) ;
return V_85 ;
}
static int F_126 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_17 ) ;
return V_85 ;
}
static int F_127 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_16 ) ;
return V_85 ;
}
static int F_128 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_18 ) ;
return V_85 ;
}
static int F_129 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_19 ) ;
return V_85 ;
}
static int F_130 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_20 ) ;
return V_85 ;
}
static int F_131 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_21 ) ;
return V_85 ;
}
static int F_132 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_22 ) ;
return V_85 ;
}
static int F_133 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_15 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_134 ( struct V_1 * V_2 )
{
F_102 ( V_2 , L_23 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_135 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_110 = V_2 -> V_19 . V_110 ;
F_67 ( & V_2 -> V_14 ) ;
V_2 -> V_19 . V_110 = V_2 -> V_14 . V_126 ;
V_2 -> V_189 = 1 ;
return V_85 ;
}
static int F_136 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_10 ) ;
return V_85 ;
}
static int F_138 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_110 = V_2 -> V_209 . V_110 ;
return F_136 ( V_2 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_124 ;
V_2 -> V_19 . V_17 = V_2 -> V_14 . V_17 ;
V_2 -> V_19 . V_72 . V_34 = & V_2 -> V_36 [ V_230 ] ;
V_2 -> V_19 . V_110 = ~ ( ( V_2 -> V_14 . V_110 >> ( V_2 -> V_14 . V_17 * 8 - 1 ) ) - 1 ) ;
return V_85 ;
}
static int F_140 ( struct V_1 * V_2 )
{
V_111 V_329 = 0 ;
V_2 -> V_23 -> V_250 ( V_2 , V_330 , & V_329 ) ;
V_2 -> V_36 [ V_211 ] = ( T_3 ) V_329 ;
V_2 -> V_36 [ V_230 ] = V_329 >> 32 ;
return V_85 ;
}
static int F_141 ( struct V_1 * V_2 )
{
V_111 V_331 ;
if ( V_2 -> V_23 -> V_332 ( V_2 , V_2 -> V_36 [ V_164 ] , & V_331 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_36 [ V_211 ] = ( T_3 ) V_331 ;
V_2 -> V_36 [ V_230 ] = V_331 >> 32 ;
return V_85 ;
}
static int F_142 ( struct V_1 * V_2 )
{
memcpy ( V_2 -> V_19 . V_224 , V_2 -> V_14 . V_224 , V_2 -> V_100 ) ;
return V_85 ;
}
static int F_143 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_301 ( V_2 , V_2 -> V_11 , V_2 -> V_14 . V_110 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_144 ( struct V_1 * V_2 )
{
unsigned long V_110 ;
if ( V_2 -> V_29 == V_30 )
V_110 = V_2 -> V_14 . V_110 & ~ 0ULL ;
else
V_110 = V_2 -> V_14 . V_110 & ~ 0U ;
if ( V_2 -> V_23 -> V_333 ( V_2 , V_2 -> V_11 , V_110 ) < 0 )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_145 ( struct V_1 * V_2 )
{
V_111 V_246 ;
V_246 = ( T_3 ) V_2 -> V_36 [ V_211 ]
| ( ( V_111 ) V_2 -> V_36 [ V_230 ] << 32 ) ;
if ( V_2 -> V_23 -> V_334 ( V_2 , V_2 -> V_36 [ V_164 ] , V_246 ) )
return F_19 ( V_2 , 0 ) ;
return V_85 ;
}
static int F_146 ( struct V_1 * V_2 )
{
V_111 V_246 ;
if ( V_2 -> V_23 -> V_250 ( V_2 , V_2 -> V_36 [ V_164 ] , & V_246 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_36 [ V_211 ] = ( T_3 ) V_246 ;
V_2 -> V_36 [ V_230 ] = V_246 >> 32 ;
return V_85 ;
}
static int F_147 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 > V_183 )
return F_21 ( V_2 ) ;
V_2 -> V_19 . V_110 = F_25 ( V_2 , V_2 -> V_11 ) ;
return V_85 ;
}
static int F_148 ( struct V_1 * V_2 )
{
T_2 V_26 = V_2 -> V_14 . V_110 ;
if ( V_2 -> V_11 == V_93 || V_2 -> V_11 > V_183 )
return F_21 ( V_2 ) ;
if ( V_2 -> V_11 == V_32 )
V_2 -> V_335 = V_336 ;
V_2 -> V_19 . type = V_191 ;
return F_64 ( V_2 , V_26 , V_2 -> V_11 ) ;
}
static int F_149 ( struct V_1 * V_2 )
{
T_2 V_26 = V_2 -> V_14 . V_110 ;
V_2 -> V_19 . type = V_191 ;
return F_64 ( V_2 , V_26 , V_172 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
T_2 V_26 = V_2 -> V_14 . V_110 ;
V_2 -> V_19 . type = V_191 ;
return F_64 ( V_2 , V_26 , V_187 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_87 ;
T_1 V_75 ;
V_87 = F_31 ( V_2 , V_2 -> V_14 . V_72 . V_147 , 1 , false , & V_75 ) ;
if ( V_87 == V_85 )
V_2 -> V_23 -> V_337 ( V_2 , V_75 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_152 ( struct V_1 * V_2 )
{
T_1 V_338 ;
V_338 = V_2 -> V_23 -> V_293 ( V_2 , 0 ) ;
V_338 &= ~ V_316 ;
V_2 -> V_23 -> V_301 ( V_2 , 0 , V_338 ) ;
return V_85 ;
}
static int F_153 ( struct V_1 * V_2 )
{
int V_87 ;
if ( V_2 -> V_10 != 3 || V_2 -> V_12 != 1 )
return V_96 ;
V_87 = V_2 -> V_23 -> V_339 ( V_2 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_39 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_154 ( struct V_1 * V_2 ,
void (* F_155)( struct V_1 * V_2 ,
struct V_168 * V_340 ) )
{
struct V_168 V_168 ;
if ( V_2 -> V_29 == V_30 )
V_2 -> V_100 = 8 ;
F_155 ( V_2 , & V_168 ) ;
if ( V_2 -> V_100 == 2 ) {
V_2 -> V_100 = 4 ;
V_168 . V_99 &= 0x00ffffff ;
}
V_2 -> V_19 . type = V_191 ;
return F_56 ( V_2 , V_2 -> V_19 . V_72 . V_147 ,
& V_168 , 2 + V_2 -> V_100 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
return F_154 ( V_2 , V_2 -> V_23 -> V_173 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
return F_154 ( V_2 , V_2 -> V_23 -> V_170 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_168 V_168 ;
int V_87 ;
if ( V_2 -> V_29 == V_30 )
V_2 -> V_100 = 8 ;
V_87 = F_39 ( V_2 , V_2 -> V_14 . V_72 . V_147 ,
& V_168 . V_67 , & V_168 . V_99 ,
V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_23 -> V_341 ( V_2 , & V_168 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_87 ;
V_87 = V_2 -> V_23 -> V_339 ( V_2 ) ;
V_2 -> V_19 . type = V_191 ;
return V_87 ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_168 V_168 ;
int V_87 ;
if ( V_2 -> V_29 == V_30 )
V_2 -> V_100 = 8 ;
V_87 = F_39 ( V_2 , V_2 -> V_14 . V_72 . V_147 ,
& V_168 . V_67 , & V_168 . V_99 ,
V_2 -> V_100 ) ;
if ( V_87 != V_85 )
return V_87 ;
V_2 -> V_23 -> V_342 ( V_2 , & V_168 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_161 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = 2 ;
V_2 -> V_19 . V_110 = V_2 -> V_23 -> V_293 ( V_2 , 0 ) ;
return V_85 ;
}
static int F_162 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_301 ( V_2 , 0 , ( V_2 -> V_23 -> V_293 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_14 . V_110 & 0x0f ) ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_163 ( struct V_1 * V_2 )
{
F_10 ( V_2 , & V_2 -> V_36 [ V_164 ] , - 1 ) ;
if ( ( F_7 ( V_2 , V_2 -> V_36 [ V_164 ] ) != 0 ) &&
( V_2 -> V_116 == 0xe2 || F_40 ( V_2 -> V_116 ^ 0x5 , V_2 -> V_165 ) ) )
F_12 ( V_2 , V_2 -> V_14 . V_110 ) ;
return V_85 ;
}
static int F_164 ( struct V_1 * V_2 )
{
if ( F_7 ( V_2 , V_2 -> V_36 [ V_164 ] ) == 0 )
F_12 ( V_2 , V_2 -> V_14 . V_110 ) ;
return V_85 ;
}
static int F_165 ( struct V_1 * V_2 )
{
if ( ! F_58 ( V_2 , V_2 -> V_19 . V_17 , V_2 -> V_14 . V_110 ,
& V_2 -> V_19 . V_110 ) )
return V_343 ;
return V_85 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_344 ( V_2 , V_2 -> V_14 . V_17 , V_2 -> V_19 . V_110 ,
& V_2 -> V_14 . V_110 , 1 ) ;
V_2 -> V_19 . type = V_191 ;
return V_85 ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( F_110 ( V_2 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_165 &= ~ V_345 ;
return V_85 ;
}
static int F_168 ( struct V_1 * V_2 )
{
if ( F_110 ( V_2 ) )
return F_19 ( V_2 , 0 ) ;
V_2 -> V_335 = V_346 ;
V_2 -> V_165 |= V_345 ;
return V_85 ;
}
static int F_169 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_191 ;
V_2 -> V_14 . V_110 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
F_137 ( V_2 , L_24 ) ;
return V_85 ;
}
static int F_170 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_25 ) ;
return V_85 ;
}
static int F_171 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_26 ) ;
return V_85 ;
}
static int F_172 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_27 ) ;
return V_85 ;
}
static int F_173 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_28 ) ;
return V_85 ;
}
static int F_174 ( struct V_1 * V_2 )
{
F_137 ( V_2 , L_29 ) ;
return V_85 ;
}
static int F_175 ( struct V_1 * V_2 )
{
T_3 V_232 , V_233 , V_234 , V_235 ;
V_232 = V_2 -> V_36 [ V_211 ] ;
V_234 = V_2 -> V_36 [ V_164 ] ;
V_2 -> V_23 -> V_236 ( V_2 , & V_232 , & V_233 , & V_234 , & V_235 ) ;
V_2 -> V_36 [ V_211 ] = V_232 ;
V_2 -> V_36 [ V_138 ] = V_233 ;
V_2 -> V_36 [ V_164 ] = V_234 ;
V_2 -> V_36 [ V_230 ] = V_235 ;
return V_85 ;
}
static int F_176 ( struct V_1 * V_2 )
{
V_2 -> V_36 [ V_211 ] &= ~ 0xff00UL ;
V_2 -> V_36 [ V_211 ] |= ( V_2 -> V_165 & 0xff ) << 8 ;
return V_85 ;
}
static int F_177 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_100 ) {
#ifdef F_43
case 8 :
asm("bswap %0" : "+r"(ctxt->dst.val));
break;
#endif
default:
asm("bswap %0" : "+r"(*(u32 *)&ctxt->dst.val));
break;
}
return V_85 ;
}
static bool F_178 ( int V_347 )
{
switch ( V_347 ) {
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
if ( ! F_178 ( V_2 -> V_11 ) )
return F_21 ( V_2 ) ;
return V_85 ;
}
static int F_180 ( struct V_1 * V_2 )
{
V_111 V_348 = V_2 -> V_14 . V_15 ;
int V_349 = V_2 -> V_11 ;
V_111 V_249 = 0 ;
static V_111 V_350 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_351 ,
0 , 0 , 0 ,
V_352 ,
} ;
if ( ! F_178 ( V_349 ) )
return F_21 ( V_2 ) ;
if ( V_348 & V_350 [ V_349 ] )
return F_19 ( V_2 , 0 ) ;
switch ( V_349 ) {
case 0 : {
V_111 V_353 ;
if ( ( ( V_348 & V_354 ) && ! ( V_348 & V_355 ) ) ||
( ( V_348 & V_356 ) && ! ( V_348 & V_357 ) ) )
return F_19 ( V_2 , 0 ) ;
V_353 = V_2 -> V_23 -> V_293 ( V_2 , 4 ) ;
V_2 -> V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
if ( ( V_348 & V_354 ) && ( V_249 & V_358 ) &&
! ( V_353 & V_359 ) )
return F_19 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_111 V_360 = 0 ;
V_2 -> V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
if ( V_249 & V_254 )
V_360 = V_361 ;
else if ( V_2 -> V_23 -> V_293 ( V_2 , 4 ) & V_359 )
V_360 = V_362 ;
else if ( V_2 -> V_23 -> V_293 ( V_2 , 0 ) & V_354 )
V_360 = V_363 ;
if ( V_348 & V_360 )
return F_19 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
if ( ( V_249 & V_254 ) && ! ( V_348 & V_359 ) )
return F_19 ( V_2 , 0 ) ;
break;
}
}
return V_85 ;
}
static int F_181 ( struct V_1 * V_2 )
{
unsigned long V_364 ;
V_2 -> V_23 -> V_365 ( V_2 , 7 , & V_364 ) ;
return V_364 & ( 1 << 13 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
int V_366 = V_2 -> V_11 ;
V_111 V_353 ;
if ( V_366 > 7 )
return F_21 ( V_2 ) ;
V_353 = V_2 -> V_23 -> V_293 ( V_2 , 4 ) ;
if ( ( V_353 & V_367 ) && ( V_366 == 4 || V_366 == 5 ) )
return F_21 ( V_2 ) ;
if ( F_181 ( V_2 ) )
return F_18 ( V_2 ) ;
return V_85 ;
}
static int F_183 ( struct V_1 * V_2 )
{
V_111 V_348 = V_2 -> V_14 . V_15 ;
int V_366 = V_2 -> V_11 ;
if ( ( V_366 == 6 || V_366 == 7 ) && ( V_348 & 0xffffffff00000000ULL ) )
return F_19 ( V_2 , 0 ) ;
return F_182 ( V_2 ) ;
}
static int F_184 ( struct V_1 * V_2 )
{
V_111 V_249 ;
V_2 -> V_23 -> V_250 ( V_2 , V_251 , & V_249 ) ;
if ( ! ( V_249 & V_368 ) )
return F_21 ( V_2 ) ;
return V_85 ;
}
static int F_185 ( struct V_1 * V_2 )
{
V_111 V_369 = V_2 -> V_36 [ V_211 ] ;
if ( V_369 & 0xffff000000000000ULL )
return F_19 ( V_2 , 0 ) ;
return F_184 ( V_2 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
V_111 V_353 = V_2 -> V_23 -> V_293 ( V_2 , 4 ) ;
if ( V_353 & V_370 && V_2 -> V_23 -> V_79 ( V_2 ) )
return F_21 ( V_2 ) ;
return V_85 ;
}
static int F_187 ( struct V_1 * V_2 )
{
V_111 V_353 = V_2 -> V_23 -> V_293 ( V_2 , 4 ) ;
V_111 V_371 = V_2 -> V_36 [ V_164 ] ;
if ( ( ! ( V_353 & V_372 ) && V_2 -> V_23 -> V_79 ( V_2 ) ) ||
( V_371 > 3 ) )
return F_19 ( V_2 , 0 ) ;
return V_85 ;
}
static int F_188 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = F_34 ( V_2 -> V_19 . V_17 , 4u ) ;
if ( ! F_112 ( V_2 , V_2 -> V_14 . V_110 , V_2 -> V_19 . V_17 ) )
return F_19 ( V_2 , 0 ) ;
return V_85 ;
}
static int F_189 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_17 = F_34 ( V_2 -> V_14 . V_17 , 4u ) ;
if ( ! F_112 ( V_2 , V_2 -> V_19 . V_110 , V_2 -> V_14 . V_17 ) )
return F_19 ( V_2 , 0 ) ;
return V_85 ;
}
static unsigned F_190 ( struct V_1 * V_2 )
{
unsigned V_67 ;
V_67 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
if ( V_67 == 8 )
V_67 = 4 ;
return V_67 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_108 * V_109 ,
unsigned V_67 , bool V_373 )
{
int V_87 = V_85 ;
V_109 -> type = V_327 ;
V_109 -> V_17 = V_67 ;
V_109 -> V_72 . V_147 . V_81 = V_2 -> V_39 ;
switch ( V_109 -> V_17 ) {
case 1 :
V_109 -> V_110 = F_51 ( V_144 , V_2 ) ;
break;
case 2 :
V_109 -> V_110 = F_51 ( V_150 , V_2 ) ;
break;
case 4 :
V_109 -> V_110 = F_51 ( V_145 , V_2 ) ;
break;
}
if ( ! V_373 ) {
switch ( V_109 -> V_17 ) {
case 1 :
V_109 -> V_110 &= 0xff ;
break;
case 2 :
V_109 -> V_110 &= 0xffff ;
break;
case 4 :
V_109 -> V_110 &= 0xffffffff ;
break;
}
}
V_148:
return V_87 ;
}
static int F_192 ( struct V_1 * V_2 , struct V_108 * V_109 ,
unsigned V_33 )
{
int V_87 = V_85 ;
switch ( V_33 ) {
case V_374 :
F_48 ( V_2 , V_109 ) ;
break;
case V_375 :
V_87 = F_191 ( V_2 , V_109 , 1 , false ) ;
break;
case V_376 :
V_2 -> V_377 . V_17 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
V_378:
* V_109 = V_2 -> V_377 ;
V_2 -> V_379 = V_109 ;
if ( ( V_2 -> V_33 & V_380 ) && V_109 == & V_2 -> V_19 )
F_53 ( V_2 ) ;
V_109 -> V_126 = V_109 -> V_110 ;
break;
case V_381 :
V_2 -> V_377 . V_17 = 8 ;
goto V_378;
case V_382 :
V_109 -> type = V_124 ;
V_109 -> V_17 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
V_109 -> V_72 . V_34 = & V_2 -> V_36 [ V_211 ] ;
F_41 ( V_109 ) ;
V_109 -> V_126 = V_109 -> V_110 ;
break;
case V_383 :
V_109 -> type = V_136 ;
V_109 -> V_17 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
V_109 -> V_72 . V_147 . V_81 =
F_8 ( V_2 , V_2 -> V_36 [ V_143 ] ) ;
V_109 -> V_72 . V_147 . V_43 = V_281 ;
V_109 -> V_110 = 0 ;
break;
case V_384 :
V_109 -> type = V_124 ;
V_109 -> V_17 = 2 ;
V_109 -> V_72 . V_34 = & V_2 -> V_36 [ V_230 ] ;
F_41 ( V_109 ) ;
break;
case V_385 :
V_109 -> V_17 = 1 ;
V_109 -> V_110 = V_2 -> V_36 [ V_164 ] & 0xff ;
break;
case V_386 :
V_87 = F_191 ( V_2 , V_109 , 1 , true ) ;
break;
case V_387 :
V_109 -> V_17 = 1 ;
V_109 -> V_110 = 1 ;
break;
case V_388 :
V_87 = F_191 ( V_2 , V_109 , F_190 ( V_2 ) , true ) ;
break;
case V_389 :
V_2 -> V_377 . V_17 = 1 ;
goto V_378;
case V_390 :
V_2 -> V_377 . V_17 = 2 ;
goto V_378;
case V_391 :
V_2 -> V_377 . V_17 = 4 ;
goto V_378;
case V_392 :
V_87 = F_191 ( V_2 , V_109 , 2 , false ) ;
break;
case V_393 :
V_87 = F_191 ( V_2 , V_109 , F_190 ( V_2 ) , false ) ;
break;
case V_394 :
V_109 -> type = V_136 ;
V_109 -> V_17 = ( V_2 -> V_33 & V_125 ) ? 1 : V_2 -> V_100 ;
V_109 -> V_72 . V_147 . V_81 =
F_8 ( V_2 , V_2 -> V_36 [ V_141 ] ) ;
V_109 -> V_72 . V_147 . V_43 = V_45 ( V_2 ) ;
V_109 -> V_110 = 0 ;
break;
case V_395 :
V_109 -> type = V_327 ;
V_109 -> V_72 . V_147 . V_81 = V_2 -> V_39 ;
V_109 -> V_17 = V_2 -> V_100 + 2 ;
F_193 ( V_109 -> V_224 , V_109 -> V_17 , V_2 ) ;
break;
case V_396 :
V_2 -> V_377 . V_17 = V_2 -> V_100 + 2 ;
goto V_378;
case V_397 :
V_109 -> V_110 = V_281 ;
break;
case V_398 :
V_109 -> V_110 = V_93 ;
break;
case V_399 :
V_109 -> V_110 = V_32 ;
break;
case V_400 :
V_109 -> V_110 = V_135 ;
break;
case V_401 :
V_109 -> V_110 = V_46 ;
break;
case V_402 :
V_109 -> V_110 = V_183 ;
break;
case V_403 :
default:
V_109 -> type = V_191 ;
break;
}
V_148:
return V_87 ;
}
int F_194 ( struct V_1 * V_2 , void * V_404 , int V_405 )
{
int V_87 = V_85 ;
int V_29 = V_2 -> V_29 ;
int V_406 , V_407 , V_408 , V_409 ;
bool V_410 = false ;
struct V_411 V_411 ;
V_2 -> V_377 . type = V_191 ;
V_2 -> V_379 = NULL ;
V_2 -> V_39 = V_2 -> V_22 ;
V_2 -> V_74 . V_94 = V_2 -> V_39 ;
V_2 -> V_74 . V_92 = V_2 -> V_74 . V_94 + V_405 ;
if ( V_405 > 0 )
memcpy ( V_2 -> V_74 . V_86 , V_404 , V_405 ) ;
switch ( V_29 ) {
case V_82 :
case V_184 :
case V_204 :
V_406 = V_407 = 2 ;
break;
case V_203 :
V_406 = V_407 = 4 ;
break;
#ifdef F_43
case V_30 :
V_406 = 4 ;
V_407 = 8 ;
break;
#endif
default:
return V_317 ;
}
V_2 -> V_100 = V_406 ;
V_2 -> V_20 = V_407 ;
for (; ; ) {
switch ( V_2 -> V_116 = F_51 ( T_4 , V_2 ) ) {
case 0x66 :
V_410 = true ;
V_2 -> V_100 = V_406 ^ 6 ;
break;
case 0x67 :
if ( V_29 == V_30 )
V_2 -> V_20 = V_407 ^ 12 ;
else
V_2 -> V_20 = V_407 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_15 ( V_2 , ( V_2 -> V_116 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_15 ( V_2 , V_2 -> V_116 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_29 != V_30 )
goto V_412;
V_2 -> V_114 = V_2 -> V_116 ;
continue;
case 0xf0 :
V_2 -> V_189 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_9 = V_2 -> V_116 ;
break;
default:
goto V_412;
}
V_2 -> V_114 = 0 ;
}
V_412:
if ( V_2 -> V_114 & 8 )
V_2 -> V_100 = 8 ;
V_411 = V_413 [ V_2 -> V_116 ] ;
if ( V_2 -> V_116 == 0x0f ) {
V_2 -> V_414 = 1 ;
V_2 -> V_116 = F_51 ( T_4 , V_2 ) ;
V_411 = V_415 [ V_2 -> V_116 ] ;
}
V_2 -> V_33 = V_411 . V_102 ;
if ( V_2 -> V_33 & V_115 )
V_2 -> V_134 = F_51 ( T_4 , V_2 ) ;
while ( V_2 -> V_33 & V_416 ) {
switch ( V_2 -> V_33 & V_416 ) {
case V_417 :
V_408 = ( V_2 -> V_134 >> 3 ) & 7 ;
V_411 = V_411 . V_418 . V_419 [ V_408 ] ;
break;
case V_420 :
V_408 = ( V_2 -> V_134 >> 3 ) & 7 ;
if ( ( V_2 -> V_134 >> 6 ) == 3 )
V_411 = V_411 . V_418 . V_421 -> V_422 [ V_408 ] ;
else
V_411 = V_411 . V_418 . V_421 -> V_423 [ V_408 ] ;
break;
case V_424 :
V_408 = V_2 -> V_134 & 7 ;
V_411 = V_411 . V_418 . V_419 [ V_408 ] ;
break;
case V_425 :
if ( V_2 -> V_9 && V_410 )
return V_317 ;
V_409 = V_410 ? 0x66 : V_2 -> V_9 ;
switch ( V_409 ) {
case 0x00 : V_411 = V_411 . V_418 . V_426 -> V_427 ; break;
case 0x66 : V_411 = V_411 . V_418 . V_426 -> V_428 ; break;
case 0xf2 : V_411 = V_411 . V_418 . V_426 -> V_429 ; break;
case 0xf3 : V_411 = V_411 . V_418 . V_426 -> V_430 ; break;
}
break;
default:
return V_317 ;
}
V_2 -> V_33 &= ~ ( V_111 ) V_416 ;
V_2 -> V_33 |= V_411 . V_102 ;
}
V_2 -> V_431 = V_411 . V_418 . V_431 ;
V_2 -> V_432 = V_411 . V_432 ;
V_2 -> V_4 = V_411 . V_4 ;
if ( V_2 -> V_33 == 0 || ( V_2 -> V_33 & V_433 ) )
return V_317 ;
if ( ! ( V_2 -> V_33 & V_434 ) && V_2 -> V_435 )
return V_317 ;
if ( V_29 == V_30 && ( V_2 -> V_33 & V_436 ) )
V_2 -> V_100 = 8 ;
if ( V_2 -> V_33 & V_437 ) {
if ( V_29 == V_30 )
V_2 -> V_100 = 8 ;
else
V_2 -> V_100 = 4 ;
}
if ( V_2 -> V_33 & V_117 )
V_2 -> V_100 = 16 ;
else if ( V_2 -> V_33 & V_121 )
V_2 -> V_100 = 8 ;
if ( V_2 -> V_33 & V_115 ) {
V_87 = F_50 ( V_2 , & V_2 -> V_377 ) ;
if ( ! V_2 -> V_44 )
F_15 ( V_2 , V_2 -> V_129 ) ;
} else if ( V_2 -> V_33 & V_438 )
V_87 = F_52 ( V_2 , & V_2 -> V_377 ) ;
if ( V_87 != V_85 )
goto V_148;
if ( ! V_2 -> V_44 )
F_15 ( V_2 , V_135 ) ;
V_2 -> V_377 . V_72 . V_147 . V_43 = V_45 ( V_2 ) ;
if ( V_2 -> V_377 . type == V_136 && V_2 -> V_20 != 8 )
V_2 -> V_377 . V_72 . V_147 . V_81 = ( T_3 ) V_2 -> V_377 . V_72 . V_147 . V_81 ;
V_87 = F_192 ( V_2 , & V_2 -> V_14 , ( V_2 -> V_33 >> V_439 ) & V_440 ) ;
if ( V_87 != V_85 )
goto V_148;
V_87 = F_192 ( V_2 , & V_2 -> V_209 , ( V_2 -> V_33 >> V_441 ) & V_440 ) ;
if ( V_87 != V_85 )
goto V_148;
V_87 = F_192 ( V_2 , & V_2 -> V_19 , ( V_2 -> V_33 >> V_442 ) & V_440 ) ;
V_148:
if ( V_2 -> V_379 && V_2 -> V_379 -> type == V_136 && V_2 -> V_146 )
V_2 -> V_379 -> V_72 . V_147 . V_81 += V_2 -> V_39 ;
return ( V_87 != V_85 ) ? V_317 : V_318 ;
}
bool F_195 ( struct V_1 * V_2 )
{
return V_2 -> V_33 & V_443 ;
}
static bool F_196 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_116 == 0xa6 ) || ( V_2 -> V_116 == 0xa7 ) ||
( V_2 -> V_116 == 0xae ) || ( V_2 -> V_116 == 0xaf ) )
&& ( ( ( V_2 -> V_9 == V_444 ) &&
( ( V_2 -> V_165 & V_105 ) == 0 ) )
|| ( ( V_2 -> V_9 == V_445 ) &&
( ( V_2 -> V_165 & V_105 ) == V_105 ) ) ) )
return true ;
return false ;
}
static int F_197 ( struct V_1 * V_2 )
{
bool V_446 = false ;
V_2 -> V_23 -> V_112 ( V_2 ) ;
asm volatile("1: fwait \n\t"
"2: \n\t"
".pushsection .fixup,\"ax\" \n\t"
"3: \n\t"
"movb $1, %[fault] \n\t"
"jmp 2b \n\t"
".popsection \n\t"
_ASM_EXTABLE(1b, 3b)
: [fault]"+qm"(fault));
V_2 -> V_23 -> V_113 ( V_2 ) ;
if ( F_36 ( V_446 ) )
return F_17 ( V_2 , V_447 , 0 , false ) ;
return V_85 ;
}
static void F_198 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
if ( V_109 -> type == V_122 )
F_46 ( V_2 , & V_109 -> V_190 , V_109 -> V_72 . V_123 ) ;
}
int F_199 ( struct V_1 * V_2 )
{
struct V_171 * V_23 = V_2 -> V_23 ;
int V_87 = V_85 ;
int V_448 = V_2 -> V_19 . type ;
V_2 -> V_153 . V_155 = 0 ;
if ( V_2 -> V_29 == V_30 && ( V_2 -> V_33 & V_449 ) ) {
V_87 = F_21 ( V_2 ) ;
goto V_148;
}
if ( V_2 -> V_189 && ( ! ( V_2 -> V_33 & V_450 ) || V_2 -> V_19 . type != V_136 ) ) {
V_87 = F_21 ( V_2 ) ;
goto V_148;
}
if ( ( V_2 -> V_33 & V_451 ) == V_452 && V_2 -> V_14 . type != V_136 ) {
V_87 = F_21 ( V_2 ) ;
goto V_148;
}
if ( ( ( V_2 -> V_33 & ( V_117 | V_121 ) ) && ( ( V_23 -> V_293 ( V_2 , 0 ) & V_453 ) ) )
|| ( ( V_2 -> V_33 & V_117 ) && ! ( V_23 -> V_293 ( V_2 , 4 ) & V_454 ) ) ) {
V_87 = F_21 ( V_2 ) ;
goto V_148;
}
if ( ( V_2 -> V_33 & ( V_117 | V_121 ) ) && ( V_23 -> V_293 ( V_2 , 0 ) & V_316 ) ) {
V_87 = F_24 ( V_2 ) ;
goto V_148;
}
if ( V_2 -> V_33 & V_121 ) {
V_87 = F_197 ( V_2 ) ;
if ( V_87 != V_85 )
goto V_148;
F_198 ( V_2 , & V_2 -> V_14 ) ;
F_198 ( V_2 , & V_2 -> V_209 ) ;
if ( ! ( V_2 -> V_33 & V_455 ) )
F_198 ( V_2 , & V_2 -> V_19 ) ;
}
if ( F_36 ( V_2 -> V_456 ) && V_2 -> V_4 ) {
V_87 = F_1 ( V_2 , V_2 -> V_4 ,
V_457 ) ;
if ( V_87 != V_85 )
goto V_148;
}
if ( ( V_2 -> V_33 & V_458 ) && V_23 -> V_79 ( V_2 ) ) {
V_87 = F_19 ( V_2 , 0 ) ;
goto V_148;
}
if ( ( V_2 -> V_33 & V_459 ) && ! ( V_2 -> V_29 & V_460 ) ) {
V_87 = F_21 ( V_2 ) ;
goto V_148;
}
if ( V_2 -> V_432 ) {
V_87 = V_2 -> V_432 ( V_2 ) ;
if ( V_87 != V_85 )
goto V_148;
}
if ( F_36 ( V_2 -> V_456 ) && V_2 -> V_4 ) {
V_87 = F_1 ( V_2 , V_2 -> V_4 ,
V_461 ) ;
if ( V_87 != V_85 )
goto V_148;
}
if ( V_2 -> V_9 && ( V_2 -> V_33 & String ) ) {
if ( F_7 ( V_2 , V_2 -> V_36 [ V_164 ] ) == 0 ) {
V_2 -> V_22 = V_2 -> V_39 ;
goto V_148;
}
}
if ( ( V_2 -> V_14 . type == V_136 ) && ! ( V_2 -> V_33 & V_462 ) ) {
V_87 = F_55 ( V_2 , V_2 -> V_14 . V_72 . V_147 ,
V_2 -> V_14 . V_224 , V_2 -> V_14 . V_17 ) ;
if ( V_87 != V_85 )
goto V_148;
V_2 -> V_14 . V_229 = V_2 -> V_14 . V_15 ;
}
if ( V_2 -> V_209 . type == V_136 ) {
V_87 = F_55 ( V_2 , V_2 -> V_209 . V_72 . V_147 ,
& V_2 -> V_209 . V_110 , V_2 -> V_209 . V_17 ) ;
if ( V_87 != V_85 )
goto V_148;
}
if ( ( V_2 -> V_33 & V_463 ) == V_464 )
goto V_465;
if ( ( V_2 -> V_19 . type == V_136 ) && ! ( V_2 -> V_33 & V_455 ) ) {
V_87 = F_55 ( V_2 , V_2 -> V_19 . V_72 . V_147 ,
& V_2 -> V_19 . V_110 , V_2 -> V_19 . V_17 ) ;
if ( V_87 != V_85 )
goto V_148;
}
V_2 -> V_19 . V_126 = V_2 -> V_19 . V_110 ;
V_465:
if ( F_36 ( V_2 -> V_456 ) && V_2 -> V_4 ) {
V_87 = F_1 ( V_2 , V_2 -> V_4 ,
V_466 ) ;
if ( V_87 != V_85 )
goto V_148;
}
if ( V_2 -> V_431 ) {
V_87 = V_2 -> V_431 ( V_2 ) ;
if ( V_87 != V_85 )
goto V_148;
goto F_68;
}
if ( V_2 -> V_414 )
goto V_467;
switch ( V_2 -> V_116 ) {
case 0x40 ... 0x47 :
F_91 ( V_2 , L_13 ) ;
break;
case 0x48 ... 0x4f :
F_91 ( V_2 , L_14 ) ;
break;
case 0x63 :
if ( V_2 -> V_29 != V_30 )
goto V_468;
V_2 -> V_19 . V_110 = ( V_145 ) V_2 -> V_14 . V_110 ;
break;
case 0x70 ... 0x7f :
if ( F_40 ( V_2 -> V_116 , V_2 -> V_165 ) )
F_12 ( V_2 , V_2 -> V_14 . V_110 ) ;
break;
case 0x8d :
V_2 -> V_19 . V_110 = V_2 -> V_14 . V_72 . V_147 . V_81 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_19 . V_72 . V_34 == & V_2 -> V_36 [ V_211 ] )
break;
V_87 = F_135 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_100 ) {
case 2 : V_2 -> V_19 . V_110 = ( V_144 ) V_2 -> V_19 . V_110 ; break;
case 4 : V_2 -> V_19 . V_110 = ( V_150 ) V_2 -> V_19 . V_110 ; break;
case 8 : V_2 -> V_19 . V_110 = ( V_145 ) V_2 -> V_19 . V_110 ; break;
}
break;
case 0xc0 ... 0xc1 :
V_87 = F_87 ( V_2 ) ;
break;
case 0xcc :
V_87 = F_83 ( V_2 , 3 ) ;
break;
case 0xcd :
V_87 = F_83 ( V_2 , V_2 -> V_14 . V_110 ) ;
break;
case 0xce :
if ( V_2 -> V_165 & V_103 )
V_87 = F_83 ( V_2 , 4 ) ;
break;
case 0xd0 ... 0xd1 :
V_87 = F_87 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_2 -> V_14 . V_110 = V_2 -> V_36 [ V_164 ] ;
V_87 = F_87 ( V_2 ) ;
break;
case 0xe9 :
case 0xeb :
F_12 ( V_2 , V_2 -> V_14 . V_110 ) ;
V_2 -> V_19 . type = V_191 ;
break;
case 0xf4 :
V_2 -> V_23 -> V_469 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_165 ^= V_104 ;
break;
case 0xf8 :
V_2 -> V_165 &= ~ V_104 ;
break;
case 0xf9 :
V_2 -> V_165 |= V_104 ;
break;
case 0xfc :
V_2 -> V_165 &= ~ V_166 ;
break;
case 0xfd :
V_2 -> V_165 |= V_166 ;
break;
default:
goto V_468;
}
if ( V_87 != V_85 )
goto V_148;
F_68:
V_87 = F_68 ( V_2 ) ;
if ( V_87 != V_85 )
goto V_148;
V_2 -> V_19 . type = V_448 ;
if ( ( V_2 -> V_33 & V_451 ) == V_470 )
F_121 ( V_2 , V_45 ( V_2 ) ,
V_141 , & V_2 -> V_14 ) ;
if ( ( V_2 -> V_33 & V_463 ) == V_471 )
F_121 ( V_2 , V_281 , V_143 ,
& V_2 -> V_19 ) ;
if ( V_2 -> V_9 && ( V_2 -> V_33 & String ) ) {
struct V_151 * V_265 = & V_2 -> V_161 ;
F_10 ( V_2 , & V_2 -> V_36 [ V_164 ] , - 1 ) ;
if ( ! F_196 ( V_2 ) ) {
if ( ( V_265 -> V_92 != 0 || V_2 -> V_36 [ V_164 ] & 0x3ff ) &&
( V_265 -> V_92 == 0 || V_265 -> V_92 != V_265 -> V_155 ) ) {
V_2 -> V_153 . V_92 = 0 ;
return V_472 ;
}
goto V_148;
}
}
V_2 -> V_22 = V_2 -> V_39 ;
V_148:
if ( V_87 == V_54 )
V_2 -> V_473 = true ;
if ( V_87 == V_474 )
return V_475 ;
return ( V_87 == V_96 ) ? V_317 : V_318 ;
V_467:
switch ( V_2 -> V_116 ) {
case 0x09 :
( V_2 -> V_23 -> V_476 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_19 . V_110 = V_23 -> V_293 ( V_2 , V_2 -> V_11 ) ;
break;
case 0x21 :
V_23 -> V_365 ( V_2 , V_2 -> V_11 , & V_2 -> V_19 . V_110 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_19 . V_110 = V_2 -> V_19 . V_126 = V_2 -> V_14 . V_110 ;
if ( ! F_40 ( V_2 -> V_116 , V_2 -> V_165 ) )
V_2 -> V_19 . type = V_191 ;
break;
case 0x80 ... 0x8f :
if ( F_40 ( V_2 -> V_116 , V_2 -> V_165 ) )
F_12 ( V_2 , V_2 -> V_14 . V_110 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_19 . V_110 = F_40 ( V_2 -> V_116 , V_2 -> V_165 ) ;
break;
case 0xa4 :
case 0xa5 :
F_200 ( V_2 , L_30 ) ;
break;
case 0xac :
case 0xad :
F_200 ( V_2 , L_31 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
V_2 -> V_19 . V_110 = ( V_2 -> V_14 . V_17 == 1 ) ? ( T_4 ) V_2 -> V_14 . V_110
: ( T_2 ) V_2 -> V_14 . V_110 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
V_2 -> V_19 . V_110 = ( V_2 -> V_14 . V_17 == 1 ) ? ( V_144 ) V_2 -> V_14 . V_110 :
( V_150 ) V_2 -> V_14 . V_110 ;
break;
case 0xc0 ... 0xc1 :
F_102 ( V_2 , L_17 ) ;
V_2 -> V_14 . V_110 = V_2 -> V_19 . V_126 ;
F_67 ( & V_2 -> V_14 ) ;
break;
case 0xc3 :
V_2 -> V_19 . V_17 = V_2 -> V_100 ;
V_2 -> V_19 . V_110 = ( V_2 -> V_100 == 4 ) ? ( T_3 ) V_2 -> V_14 . V_110 :
( V_111 ) V_2 -> V_14 . V_110 ;
break;
default:
goto V_468;
}
if ( V_87 != V_85 )
goto V_148;
goto F_68;
V_468:
return V_317 ;
}
