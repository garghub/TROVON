static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
struct V_7 V_8 = {
. V_4 = V_4 ,
. V_9 = V_2 -> V_10 . V_9 ,
. V_11 = V_2 -> V_10 . V_11 ,
. V_12 = V_2 -> V_10 . V_12 ,
. V_13 = V_2 -> V_10 . V_13 ,
. V_14 = V_2 -> V_10 . V_15 . V_16 ,
. V_17 = V_2 -> V_10 . V_15 . V_18 ,
. V_19 = V_2 -> V_10 . V_20 . V_18 ,
. V_21 = V_2 -> V_10 . V_21 ,
. V_22 = V_2 -> V_23 ,
} ;
return V_2 -> V_24 -> V_4 ( V_2 , & V_8 , V_6 ) ;
}
static inline unsigned long F_2 ( struct V_25 * V_26 )
{
return ( 1UL << ( V_26 -> V_21 << 3 ) ) - 1 ;
}
static inline unsigned long
F_3 ( struct V_25 * V_26 , unsigned long V_27 )
{
if ( V_26 -> V_21 == sizeof( unsigned long ) )
return V_27 ;
else
return V_27 & F_2 ( V_26 ) ;
}
static inline unsigned long
F_4 ( struct V_25 * V_26 , unsigned long V_27 )
{
return F_3 ( V_26 , V_27 ) ;
}
static inline void
F_5 ( struct V_25 * V_26 , unsigned long * V_27 , int V_28 )
{
if ( V_26 -> V_21 == sizeof( unsigned long ) )
* V_27 += V_28 ;
else
* V_27 = ( * V_27 & ~ F_2 ( V_26 ) ) | ( ( * V_27 + V_28 ) & F_2 ( V_26 ) ) ;
}
static inline void F_6 ( struct V_25 * V_26 , int V_29 )
{
F_5 ( V_26 , & V_26 -> V_23 , V_29 ) ;
}
static T_1 F_7 ( struct V_30 * V_31 )
{
T_1 V_32 = F_8 ( V_31 ) ;
return V_31 -> V_33 ? ( V_32 << 12 ) | 0xfff : V_32 ;
}
static void F_9 ( struct V_25 * V_26 , int V_34 )
{
V_26 -> V_35 = true ;
V_26 -> V_36 = V_34 ;
}
static unsigned long F_10 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_34 )
{
if ( V_2 -> V_38 == V_39 && V_34 < V_40 )
return 0 ;
return V_24 -> V_41 ( V_2 , V_34 ) ;
}
static unsigned V_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
if ( ! V_26 -> V_35 )
return 0 ;
return V_26 -> V_36 ;
}
static int F_11 ( struct V_1 * V_2 , int V_42 ,
T_1 error , bool V_43 )
{
V_2 -> V_44 . V_45 = V_42 ;
V_2 -> V_44 . V_46 = error ;
V_2 -> V_44 . V_47 = V_43 ;
return V_48 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_49 , 0 , false ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_50 )
{
return F_11 ( V_2 , V_51 , V_50 , true ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_50 )
{
return F_11 ( V_2 , V_52 , V_50 , true ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_53 , 0 , false ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_50 )
{
return F_11 ( V_2 , V_54 , V_50 , true ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_55 , 0 , false ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_56 , 0 , false ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , unsigned V_34 )
{
T_2 V_57 ;
struct V_30 V_31 ;
V_2 -> V_24 -> V_58 ( V_2 , & V_57 , & V_31 , NULL , V_34 ) ;
return V_57 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 V_57 ,
unsigned V_34 )
{
T_2 V_59 ;
T_1 V_60 ;
struct V_30 V_31 ;
V_2 -> V_24 -> V_58 ( V_2 , & V_59 , & V_31 , & V_60 , V_34 ) ;
V_2 -> V_24 -> V_61 ( V_2 , V_57 , & V_31 , V_60 , V_34 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
unsigned V_64 , bool V_65 , bool V_66 ,
T_3 * V_67 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_30 V_31 ;
bool V_68 ;
T_3 V_69 ;
T_1 V_70 ;
T_2 V_71 ;
unsigned V_72 , V_73 ;
V_69 = F_10 ( V_2 , V_2 -> V_24 , V_63 . V_34 ) + V_63 . V_74 ;
switch ( V_2 -> V_38 ) {
case V_75 :
break;
case V_39 :
if ( ( ( signed long ) V_69 << 16 ) >> 16 != V_69 )
return F_13 ( V_2 , 0 ) ;
break;
default:
V_68 = V_2 -> V_24 -> V_58 ( V_2 , & V_71 , & V_31 , NULL ,
V_63 . V_34 ) ;
if ( ! V_68 )
goto V_76;
if ( ( ( V_31 . type & 8 ) || ! ( V_31 . type & 2 ) ) && V_65 )
goto V_76;
if ( ! V_66 && ( V_31 . type & 8 ) && ! ( V_31 . type & 2 ) )
goto V_76;
V_70 = F_7 ( & V_31 ) ;
if ( ( V_31 . type & 8 ) || ! ( V_31 . type & 4 ) ) {
if ( V_63 . V_74 > V_70 || ( T_1 ) ( V_63 . V_74 + V_64 - 1 ) > V_70 )
goto V_76;
} else {
if ( V_63 . V_74 <= V_70 || ( T_1 ) ( V_63 . V_74 + V_64 - 1 ) <= V_70 )
goto V_76;
V_70 = V_31 . V_77 ? 0xffffffff : 0xffff ;
if ( V_63 . V_74 > V_70 || ( T_1 ) ( V_63 . V_74 + V_64 - 1 ) > V_70 )
goto V_76;
}
V_72 = V_2 -> V_24 -> V_72 ( V_2 ) ;
V_73 = V_71 & 3 ;
V_72 = F_22 ( V_72 , V_73 ) ;
if ( ! ( V_31 . type & 8 ) ) {
if ( V_72 > V_31 . V_78 )
goto V_76;
} else if ( ( V_31 . type & 8 ) && ! ( V_31 . type & 4 ) ) {
if ( V_72 != V_31 . V_78 )
goto V_76;
} else if ( ( V_31 . type & 8 ) && ( V_31 . type & 4 ) ) {
if ( V_72 < V_31 . V_78 )
goto V_76;
}
break;
}
if ( V_66 ? V_2 -> V_38 != V_39 : V_26 -> V_21 != 8 )
V_69 &= ( T_1 ) - 1 ;
* V_67 = V_69 ;
return V_79 ;
V_76:
if ( V_63 . V_34 == V_80 )
return F_14 ( V_2 , V_63 . V_34 ) ;
else
return F_13 ( V_2 , V_63 . V_34 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
unsigned V_64 , bool V_65 ,
T_3 * V_67 )
{
return F_21 ( V_2 , V_63 , V_64 , V_65 , false , V_67 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
void * V_81 ,
unsigned V_64 )
{
int V_82 ;
T_3 V_67 ;
V_82 = F_23 ( V_2 , V_63 , V_64 , false , & V_67 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_24 -> V_83 ( V_2 , V_67 , V_81 , V_64 , & V_2 -> V_44 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
unsigned long V_23 , T_4 * V_84 )
{
struct V_85 * V_86 = & V_2 -> V_10 . V_66 ;
int V_82 ;
int V_64 , V_87 ;
if ( V_23 == V_86 -> V_88 ) {
unsigned long V_67 ;
struct V_62 V_63 = { . V_34 = V_89 , . V_74 = V_23 } ;
V_87 = V_86 -> V_88 - V_86 -> V_90 ;
V_64 = F_26 ( 15UL - V_87 , V_91 - F_27 ( V_23 ) ) ;
V_82 = F_21 ( V_2 , V_63 , V_64 , false , true , & V_67 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = V_24 -> V_66 ( V_2 , V_67 , V_86 -> V_81 + V_87 ,
V_64 , & V_2 -> V_44 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_86 -> V_88 += V_64 ;
}
* V_84 = V_86 -> V_81 [ V_23 - V_86 -> V_90 ] ;
return V_79 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
unsigned long V_23 , void * V_84 , unsigned V_64 )
{
int V_82 ;
if ( V_23 + V_64 - V_2 -> V_23 > 15 )
return V_92 ;
while ( V_64 -- ) {
V_82 = F_25 ( V_2 , V_24 , V_23 ++ , V_84 ++ ) ;
if ( V_82 != V_79 )
return V_82 ;
}
return V_79 ;
}
static void * F_29 ( T_4 V_12 , unsigned long * V_93 ,
int V_94 )
{
void * V_95 ;
V_95 = & V_93 [ V_12 ] ;
if ( V_94 && V_12 >= 4 && V_12 < 8 )
V_95 = ( unsigned char * ) & V_93 [ V_12 & 3 ] + 1 ;
return V_95 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
T_2 * V_64 , unsigned long * V_96 , int V_97 )
{
int V_82 ;
if ( V_97 == 2 )
V_97 = 3 ;
* V_96 = 0 ;
V_82 = F_24 ( V_2 , V_63 , V_64 , 2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_63 . V_74 += 2 ;
V_82 = F_24 ( V_2 , V_63 , V_96 , V_97 ) ;
return V_82 ;
}
static int F_31 ( unsigned int V_98 , unsigned int V_99 )
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
static void F_32 ( struct V_105 * V_106 )
{
switch ( V_106 -> V_18 ) {
case 1 :
V_106 -> V_107 = * ( T_4 * ) V_106 -> V_63 . V_27 ;
break;
case 2 :
V_106 -> V_107 = * ( T_2 * ) V_106 -> V_63 . V_27 ;
break;
case 4 :
V_106 -> V_107 = * ( T_1 * ) V_106 -> V_63 . V_27 ;
break;
case 8 :
V_106 -> V_107 = * ( V_108 * ) V_106 -> V_63 . V_27 ;
break;
}
}
static void F_33 ( struct V_1 * V_2 , T_5 * V_81 , int V_27 )
{
V_2 -> V_24 -> V_109 ( V_2 ) ;
switch ( V_27 ) {
case 0 : asm("movdqu %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqu %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqu %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqu %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqu %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqu %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqu %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqu %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_34
case 8 : asm("movdqu %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqu %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqu %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqu %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqu %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqu %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqu %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqu %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_35 () ;
}
V_2 -> V_24 -> V_110 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_5 * V_81 ,
int V_27 )
{
V_2 -> V_24 -> V_109 ( V_2 ) ;
switch ( V_27 ) {
case 0 : asm("movdqu %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqu %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqu %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqu %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqu %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqu %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqu %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqu %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_34
case 8 : asm("movdqu %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqu %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqu %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqu %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqu %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqu %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqu %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqu %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_35 () ;
}
V_2 -> V_24 -> V_110 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_25 * V_26 ,
int V_111 )
{
unsigned V_27 = V_26 -> V_12 ;
int V_94 = V_26 -> V_112 == 0 ;
if ( ! ( V_26 -> V_77 & V_113 ) )
V_27 = ( V_26 -> V_114 & 7 ) | ( ( V_26 -> V_112 & 1 ) << 3 ) ;
if ( V_26 -> V_77 & V_115 ) {
V_106 -> type = V_116 ;
V_106 -> V_18 = 16 ;
V_106 -> V_63 . V_117 = V_27 ;
F_33 ( V_2 , & V_106 -> V_118 , V_27 ) ;
return;
}
V_106 -> type = V_119 ;
if ( ( V_26 -> V_77 & V_120 ) && ! V_111 ) {
V_106 -> V_63 . V_27 = F_29 ( V_27 , V_26 -> V_93 , V_94 ) ;
V_106 -> V_18 = 1 ;
} else {
V_106 -> V_63 . V_27 = F_29 ( V_27 , V_26 -> V_93 , 0 ) ;
V_106 -> V_18 = V_26 -> V_97 ;
}
F_32 ( V_106 ) ;
V_106 -> V_121 = V_106 -> V_107 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_105 * V_106 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
T_4 V_122 ;
int V_123 = 0 , V_124 = 0 , V_125 ;
int V_82 = V_79 ;
T_3 V_126 = 0 ;
if ( V_26 -> V_112 ) {
V_26 -> V_12 = ( V_26 -> V_112 & 4 ) << 1 ;
V_123 = ( V_26 -> V_112 & 2 ) << 2 ;
V_26 -> V_13 = V_124 = ( V_26 -> V_112 & 1 ) << 3 ;
}
V_26 -> V_127 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
V_26 -> V_11 |= ( V_26 -> V_127 & 0xc0 ) >> 6 ;
V_26 -> V_12 |= ( V_26 -> V_127 & 0x38 ) >> 3 ;
V_26 -> V_13 |= ( V_26 -> V_127 & 0x07 ) ;
V_26 -> V_128 = V_129 ;
if ( V_26 -> V_11 == 3 ) {
V_106 -> type = V_119 ;
V_106 -> V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
V_106 -> V_63 . V_27 = F_29 ( V_26 -> V_13 ,
V_26 -> V_93 , V_26 -> V_77 & V_120 ) ;
if ( V_26 -> V_77 & V_115 ) {
V_106 -> type = V_116 ;
V_106 -> V_18 = 16 ;
V_106 -> V_63 . V_117 = V_26 -> V_13 ;
F_33 ( V_2 , & V_106 -> V_118 , V_26 -> V_13 ) ;
return V_82 ;
}
F_32 ( V_106 ) ;
return V_82 ;
}
V_106 -> type = V_130 ;
if ( V_26 -> V_21 == 2 ) {
unsigned V_131 = V_26 -> V_93 [ V_132 ] ;
unsigned V_133 = V_26 -> V_93 [ V_134 ] ;
unsigned V_135 = V_26 -> V_93 [ V_136 ] ;
unsigned V_137 = V_26 -> V_93 [ V_138 ] ;
switch ( V_26 -> V_11 ) {
case 0 :
if ( V_26 -> V_13 == 6 )
V_126 += F_39 ( T_2 , 2 , V_26 -> V_23 ) ;
break;
case 1 :
V_126 += F_39 ( V_139 , 1 , V_26 -> V_23 ) ;
break;
case 2 :
V_126 += F_39 ( T_2 , 2 , V_26 -> V_23 ) ;
break;
}
switch ( V_26 -> V_13 ) {
case 0 :
V_126 += V_131 + V_135 ;
break;
case 1 :
V_126 += V_131 + V_137 ;
break;
case 2 :
V_126 += V_133 + V_135 ;
break;
case 3 :
V_126 += V_133 + V_137 ;
break;
case 4 :
V_126 += V_135 ;
break;
case 5 :
V_126 += V_137 ;
break;
case 6 :
if ( V_26 -> V_11 != 0 )
V_126 += V_133 ;
break;
case 7 :
V_126 += V_131 ;
break;
}
if ( V_26 -> V_13 == 2 || V_26 -> V_13 == 3 ||
( V_26 -> V_13 == 6 && V_26 -> V_11 != 0 ) )
V_26 -> V_128 = V_80 ;
V_126 = ( T_2 ) V_126 ;
} else {
if ( ( V_26 -> V_13 & 7 ) == 4 ) {
V_122 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
V_123 |= ( V_122 >> 3 ) & 7 ;
V_124 |= V_122 & 7 ;
V_125 = V_122 >> 6 ;
if ( ( V_124 & 7 ) == 5 && V_26 -> V_11 == 0 )
V_126 += F_39 ( V_140 , 4 , V_26 -> V_23 ) ;
else
V_126 += V_26 -> V_93 [ V_124 ] ;
if ( V_123 != 4 )
V_126 += V_26 -> V_93 [ V_123 ] << V_125 ;
} else if ( ( V_26 -> V_13 & 7 ) == 5 && V_26 -> V_11 == 0 ) {
if ( V_2 -> V_38 == V_39 )
V_26 -> V_141 = 1 ;
} else
V_126 += V_26 -> V_93 [ V_26 -> V_13 ] ;
switch ( V_26 -> V_11 ) {
case 0 :
if ( V_26 -> V_13 == 5 )
V_126 += F_39 ( V_140 , 4 , V_26 -> V_23 ) ;
break;
case 1 :
V_126 += F_39 ( V_139 , 1 , V_26 -> V_23 ) ;
break;
case 2 :
V_126 += F_39 ( V_140 , 4 , V_26 -> V_23 ) ;
break;
}
}
V_106 -> V_63 . V_142 . V_74 = V_126 ;
V_143:
return V_82 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_105 * V_106 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
V_106 -> type = V_130 ;
switch ( V_26 -> V_21 ) {
case 2 :
V_106 -> V_63 . V_142 . V_74 = F_39 ( T_2 , 2 , V_26 -> V_23 ) ;
break;
case 4 :
V_106 -> V_63 . V_142 . V_74 = F_39 ( T_1 , 4 , V_26 -> V_23 ) ;
break;
case 8 :
V_106 -> V_63 . V_142 . V_74 = F_39 ( V_108 , 8 , V_26 -> V_23 ) ;
break;
}
V_143:
return V_82 ;
}
static void F_41 ( struct V_25 * V_26 )
{
long V_144 = 0 , V_145 ;
if ( V_26 -> V_20 . type == V_130 && V_26 -> V_15 . type == V_119 ) {
V_145 = ~ ( V_26 -> V_20 . V_18 * 8 - 1 ) ;
if ( V_26 -> V_15 . V_18 == 2 )
V_144 = ( V_146 ) V_26 -> V_15 . V_107 & ( V_146 ) V_145 ;
else if ( V_26 -> V_15 . V_18 == 4 )
V_144 = ( V_140 ) V_26 -> V_15 . V_107 & ( V_140 ) V_145 ;
V_26 -> V_20 . V_63 . V_142 . V_74 += ( V_144 >> 3 ) ;
}
V_26 -> V_15 . V_107 &= ( V_26 -> V_20 . V_18 << 3 ) - 1 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
unsigned long V_63 , void * V_84 , unsigned V_64 )
{
int V_82 ;
struct V_147 * V_148 = & V_2 -> V_10 . V_149 ;
while ( V_64 ) {
int V_150 = F_26 ( V_64 , 8u ) ;
V_64 -= V_150 ;
if ( V_148 -> V_151 < V_148 -> V_88 )
goto V_152;
V_82 = V_24 -> F_42 ( V_2 , V_63 , V_148 -> V_81 + V_148 -> V_88 , V_150 ,
& V_2 -> V_44 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_148 -> V_88 += V_150 ;
V_152:
memcpy ( V_84 , V_148 -> V_81 + V_148 -> V_151 , V_150 ) ;
V_148 -> V_151 += V_150 ;
V_84 += V_150 ;
V_63 += V_150 ;
}
return V_79 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
void * V_81 ,
unsigned V_64 )
{
int V_82 ;
T_3 V_67 ;
V_82 = F_23 ( V_2 , V_63 , V_64 , false , & V_67 ) ;
if ( V_82 != V_79 )
return V_82 ;
return F_42 ( V_2 , V_2 -> V_24 , V_67 , V_81 , V_64 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
const void * V_81 ,
unsigned V_64 )
{
int V_82 ;
T_3 V_67 ;
V_82 = F_23 ( V_2 , V_63 , V_64 , true , & V_67 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_24 -> V_153 ( V_2 , V_67 , V_81 , V_64 ,
& V_2 -> V_44 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_62 V_63 ,
const void * V_154 , const void * V_81 ,
unsigned V_64 )
{
int V_82 ;
T_3 V_67 ;
V_82 = F_23 ( V_2 , V_63 , V_64 , true , & V_67 ) ;
if ( V_82 != V_79 )
return V_82 ;
return V_2 -> V_24 -> V_155 ( V_2 , V_67 , V_154 , V_81 ,
V_64 , & V_2 -> V_44 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
unsigned int V_64 , unsigned short V_156 ,
void * V_84 )
{
struct V_147 * V_82 = & V_2 -> V_10 . V_157 ;
if ( V_82 -> V_151 == V_82 -> V_88 ) {
struct V_25 * V_26 = & V_2 -> V_10 ;
unsigned int V_158 , V_150 ;
unsigned int V_159 = V_26 -> V_9 ?
F_3 ( V_26 , V_26 -> V_93 [ V_160 ] ) : 1 ;
V_158 = ( V_2 -> V_161 & V_162 ) ?
F_27 ( V_26 -> V_93 [ V_138 ] ) :
V_91 - F_27 ( V_26 -> V_93 [ V_138 ] ) ;
V_150 = F_26 ( F_26 ( V_158 , ( unsigned int ) sizeof( V_82 -> V_81 ) ) / V_64 ,
V_159 ) ;
if ( V_150 == 0 )
V_150 = 1 ;
V_82 -> V_151 = V_82 -> V_88 = 0 ;
if ( ! V_24 -> F_46 ( V_2 , V_64 , V_156 , V_82 -> V_81 , V_150 ) )
return 0 ;
V_82 -> V_88 = V_150 * V_64 ;
}
memcpy ( V_84 , V_82 -> V_81 + V_82 -> V_151 , V_64 ) ;
V_82 -> V_151 += V_64 ;
return 1 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_57 , struct V_163 * V_164 )
{
if ( V_57 & 1 << 2 ) {
struct V_30 V_31 ;
T_2 V_71 ;
memset ( V_164 , 0 , sizeof *V_164 ) ;
if ( ! V_24 -> V_58 ( V_2 , & V_71 , & V_31 , NULL , V_165 ) )
return;
V_164 -> V_64 = F_7 ( & V_31 ) ;
V_164 -> V_96 = F_48 ( & V_31 ) ;
} else
V_24 -> V_166 ( V_2 , V_164 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_57 , struct V_30 * V_31 )
{
struct V_163 V_164 ;
T_2 V_167 = V_57 >> 3 ;
int V_168 ;
T_3 V_63 ;
F_47 ( V_2 , V_24 , V_57 , & V_164 ) ;
if ( V_164 . V_64 < V_167 * 8 + 7 )
return F_13 ( V_2 , V_57 & 0xfffc ) ;
V_63 = V_164 . V_96 + V_167 * 8 ;
V_168 = V_24 -> V_83 ( V_2 , V_63 , V_31 , sizeof *V_31 , & V_2 -> V_44 ) ;
return V_168 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_57 , struct V_30 * V_31 )
{
struct V_163 V_164 ;
T_2 V_167 = V_57 >> 3 ;
T_3 V_63 ;
int V_168 ;
F_47 ( V_2 , V_24 , V_57 , & V_164 ) ;
if ( V_164 . V_64 < V_167 * 8 + 7 )
return F_13 ( V_2 , V_57 & 0xfffc ) ;
V_63 = V_164 . V_96 + V_167 * 8 ;
V_168 = V_24 -> V_169 ( V_2 , V_63 , V_31 , sizeof *V_31 , & V_2 -> V_44 ) ;
return V_168 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_57 , int V_34 )
{
struct V_30 V_170 ;
T_4 V_78 , V_73 , V_72 ;
unsigned V_171 = V_51 ;
T_1 V_172 = 0 ;
bool V_173 = ! ( V_57 & ~ 0x3 ) ;
int V_168 ;
memset ( & V_170 , 0 , sizeof V_170 ) ;
if ( ( V_34 <= V_174 && V_2 -> V_38 == V_175 )
|| V_2 -> V_38 == V_75 ) {
F_52 ( & V_170 , V_57 << 4 ) ;
F_53 ( & V_170 , 0xffff ) ;
V_170 . type = 3 ;
V_170 . V_95 = 1 ;
V_170 . V_176 = 1 ;
goto V_177;
}
if ( ( V_34 == V_89 || V_34 == V_80 || V_34 == V_178 )
&& V_173 )
goto V_44;
if ( V_34 == V_178 && ( V_57 & ( 1 << 2 ) ) )
goto V_44;
if ( V_173 )
goto V_177;
V_168 = F_49 ( V_2 , V_24 , V_57 , & V_170 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_172 = V_57 & 0xfffc ;
V_171 = V_51 ;
if ( V_34 <= V_174 && ! V_170 . V_176 )
goto V_44;
if ( ! V_170 . V_95 ) {
V_171 = ( V_34 == V_80 ) ? V_52 : V_179 ;
goto V_44;
}
V_73 = V_57 & 3 ;
V_78 = V_170 . V_78 ;
V_72 = V_24 -> V_72 ( V_2 ) ;
switch ( V_34 ) {
case V_80 :
if ( V_73 != V_72 || ( V_170 . type & 0xa ) != 0x2 || V_78 != V_72 )
goto V_44;
break;
case V_89 :
if ( ! ( V_170 . type & 8 ) )
goto V_44;
if ( V_170 . type & 4 ) {
if ( V_78 > V_72 )
goto V_44;
} else {
if ( V_73 > V_72 || V_78 != V_72 )
goto V_44;
}
V_57 = ( V_57 & 0xfffc ) | V_72 ;
break;
case V_178 :
if ( V_170 . V_176 || ( V_170 . type != 1 && V_170 . type != 9 ) )
goto V_44;
break;
case V_165 :
if ( V_170 . V_176 || V_170 . type != 2 )
goto V_44;
break;
default:
if ( ( V_170 . type & 0xa ) == 0x8 ||
( ( ( V_170 . type & 0xc ) != 0xc ) &&
( V_73 > V_78 && V_72 > V_78 ) ) )
goto V_44;
break;
}
if ( V_170 . V_176 ) {
V_170 . type |= 1 ;
V_168 = F_50 ( V_2 , V_24 , V_57 , & V_170 ) ;
if ( V_168 != V_79 )
return V_168 ;
}
V_177:
V_24 -> V_61 ( V_2 , V_57 , & V_170 , 0 , V_34 ) ;
return V_79 ;
V_44:
F_11 ( V_2 , V_171 , V_172 , true ) ;
return V_48 ;
}
static void F_54 ( struct V_105 * V_106 )
{
switch ( V_106 -> V_18 ) {
case 1 :
* ( T_4 * ) V_106 -> V_63 . V_27 = ( T_4 ) V_106 -> V_107 ;
break;
case 2 :
* ( T_2 * ) V_106 -> V_63 . V_27 = ( T_2 ) V_106 -> V_107 ;
break;
case 4 :
* V_106 -> V_63 . V_27 = ( T_1 ) V_106 -> V_107 ;
break;
case 8 :
* V_106 -> V_63 . V_27 = V_106 -> V_107 ;
break;
}
}
static int F_55 ( struct V_1 * V_2 )
{
int V_82 ;
struct V_25 * V_26 = & V_2 -> V_10 ;
switch ( V_26 -> V_20 . type ) {
case V_119 :
F_54 ( & V_26 -> V_20 ) ;
break;
case V_130 :
if ( V_26 -> V_180 )
V_82 = F_45 ( V_2 ,
V_26 -> V_20 . V_63 . V_142 ,
& V_26 -> V_20 . V_121 ,
& V_26 -> V_20 . V_107 ,
V_26 -> V_20 . V_18 ) ;
else
V_82 = F_44 ( V_2 ,
V_26 -> V_20 . V_63 . V_142 ,
& V_26 -> V_20 . V_107 ,
V_26 -> V_20 . V_18 ) ;
if ( V_82 != V_79 )
return V_82 ;
break;
case V_116 :
F_36 ( V_2 , & V_26 -> V_20 . V_118 , V_26 -> V_20 . V_63 . V_117 ) ;
break;
case V_181 :
break;
default:
break;
}
return V_79 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_62 V_63 ;
F_5 ( V_26 , & V_26 -> V_93 [ V_182 ] , - V_26 -> V_97 ) ;
V_63 . V_74 = F_4 ( V_26 , V_26 -> V_93 [ V_182 ] ) ;
V_63 . V_34 = V_80 ;
V_26 -> V_20 . type = V_181 ;
return F_44 ( V_2 , V_63 , & V_26 -> V_15 . V_107 , V_26 -> V_97 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
void * V_84 , int V_183 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
struct V_62 V_63 ;
V_63 . V_74 = F_4 ( V_26 , V_26 -> V_93 [ V_182 ] ) ;
V_63 . V_34 = V_80 ;
V_82 = F_43 ( V_2 , V_63 , V_84 , V_183 ) ;
if ( V_82 != V_79 )
return V_82 ;
F_5 ( V_26 , & V_26 -> V_93 [ V_182 ] , V_183 ) ;
return V_82 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
return F_57 ( V_2 , & V_26 -> V_20 . V_107 , V_26 -> V_97 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
void * V_84 , int V_183 )
{
int V_82 ;
unsigned long V_107 , V_184 ;
int V_185 = ( V_2 -> V_161 & V_186 ) >> V_187 ;
int V_72 = V_24 -> V_72 ( V_2 ) ;
V_82 = F_57 ( V_2 , & V_107 , V_183 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_184 = V_101 | V_104 | V_188 | V_102 | V_103 | V_100
| V_189 | V_162 | V_190 | V_191 | V_192 | V_193 ;
switch( V_2 -> V_38 ) {
case V_39 :
case V_194 :
case V_195 :
if ( V_72 == 0 )
V_184 |= V_196 ;
if ( V_72 <= V_185 )
V_184 |= V_197 ;
break;
case V_175 :
if ( V_185 < 3 )
return F_13 ( V_2 , 0 ) ;
V_184 |= V_197 ;
break;
default:
V_184 |= ( V_196 | V_197 ) ;
break;
}
* ( unsigned long * ) V_84 =
( V_2 -> V_161 & ~ V_184 ) | ( V_107 & V_184 ) ;
return V_82 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_63 . V_27 = & V_2 -> V_161 ;
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
return F_59 ( V_2 , V_2 -> V_24 , & V_26 -> V_20 . V_107 , V_26 -> V_97 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_34 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_15 . V_107 = F_19 ( V_2 , V_34 ) ;
return F_56 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_34 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
unsigned long V_57 ;
int V_82 ;
V_82 = F_57 ( V_2 , & V_57 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_51 ( V_2 , V_24 , ( T_2 ) V_57 , V_34 ) ;
return V_82 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
unsigned long V_198 = V_26 -> V_93 [ V_182 ] ;
int V_82 = V_79 ;
int V_27 = V_199 ;
while ( V_27 <= V_138 ) {
( V_27 == V_182 ) ?
( V_26 -> V_15 . V_107 = V_198 ) : ( V_26 -> V_15 . V_107 = V_26 -> V_93 [ V_27 ] ) ;
V_82 = F_56 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
++ V_27 ;
}
return V_82 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_15 . V_107 = ( unsigned long ) V_2 -> V_161 ;
return F_56 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
int V_27 = V_138 ;
while ( V_27 >= V_199 ) {
if ( V_27 == V_182 ) {
F_5 ( V_26 , & V_26 -> V_93 [ V_182 ] ,
V_26 -> V_97 ) ;
-- V_27 ;
}
V_82 = F_57 ( V_2 , & V_26 -> V_93 [ V_27 ] , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
break;
-- V_27 ;
}
return V_82 ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_200 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
struct V_163 V_164 ;
T_6 V_201 ;
T_6 V_202 ;
T_2 V_203 , V_23 ;
V_26 -> V_15 . V_107 = V_2 -> V_161 ;
V_82 = F_56 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_161 &= ~ ( V_197 | V_189 | V_192 ) ;
V_26 -> V_15 . V_107 = F_19 ( V_2 , V_89 ) ;
V_82 = F_56 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_15 . V_107 = V_26 -> V_23 ;
V_82 = F_56 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_24 -> V_204 ( V_2 , & V_164 ) ;
V_202 = V_164 . V_96 + ( V_200 << 2 ) ;
V_201 = V_164 . V_96 + ( V_200 << 2 ) + 2 ;
V_82 = V_24 -> V_83 ( V_2 , V_201 , & V_203 , 2 , & V_2 -> V_44 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = V_24 -> V_83 ( V_2 , V_202 , & V_23 , 2 , & V_2 -> V_44 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_51 ( V_2 , V_24 , V_203 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_23 = V_23 ;
return V_82 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_200 )
{
switch( V_2 -> V_38 ) {
case V_75 :
return F_66 ( V_2 , V_24 , V_200 ) ;
case V_175 :
case V_195 :
case V_194 :
case V_39 :
default:
return V_92 ;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_37 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
unsigned long V_205 = 0 ;
unsigned long V_206 = 0 ;
unsigned long V_203 = 0 ;
unsigned long V_145 = V_101 | V_104 | V_188 | V_102 | V_103 | V_189 |
V_197 | V_162 | V_100 | V_196 | V_190 | V_191 |
V_192 | V_193 | ( 1 << 1 ) ;
unsigned long V_207 = V_208 | V_209 | V_210 ;
V_82 = F_57 ( V_2 , & V_205 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
if ( V_205 & ~ 0xffff )
return F_13 ( V_2 , 0 ) ;
V_82 = F_57 ( V_2 , & V_203 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_57 ( V_2 , & V_206 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_51 ( V_2 , V_24 , ( T_2 ) V_203 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_23 = V_205 ;
if ( V_26 -> V_97 == 4 )
V_2 -> V_161 = ( ( V_206 & V_145 ) | ( V_2 -> V_161 & V_207 ) ) ;
else if ( V_26 -> V_97 == 2 ) {
V_2 -> V_161 &= ~ 0xffff ;
V_2 -> V_161 |= V_206 ;
}
V_2 -> V_161 &= ~ V_211 ;
V_2 -> V_161 |= V_212 ;
return V_82 ;
}
static inline int F_69 ( struct V_1 * V_2 ,
struct V_37 * V_24 )
{
switch( V_2 -> V_38 ) {
case V_75 :
return F_68 ( V_2 , V_24 ) ;
case V_175 :
case V_195 :
case V_194 :
case V_39 :
default:
return V_92 ;
}
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
unsigned short V_71 ;
memcpy ( & V_71 , V_26 -> V_15 . V_213 + V_26 -> V_97 , 2 ) ;
V_82 = F_51 ( V_2 , V_2 -> V_24 , V_71 , V_89 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_23 = 0 ;
memcpy ( & V_26 -> V_23 , V_26 -> V_15 . V_213 , V_26 -> V_97 ) ;
return V_79 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
return F_57 ( V_2 , & V_26 -> V_20 . V_107 , V_26 -> V_20 . V_18 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
switch ( V_26 -> V_12 ) {
case 0 :
F_73 ( L_1 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 1 :
F_73 ( L_2 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 2 :
F_73 ( L_3 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 3 :
F_73 ( L_4 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 4 :
case 6 :
F_73 ( L_5 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 5 :
F_73 ( L_6 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 7 :
F_73 ( L_7 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
}
return V_79 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
unsigned long * V_214 = & V_26 -> V_93 [ V_199 ] ;
unsigned long * V_215 = & V_26 -> V_93 [ V_216 ] ;
T_4 V_217 = 0 ;
switch ( V_26 -> V_12 ) {
case 0 ... 1 :
F_75 ( L_8 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 2 :
V_26 -> V_20 . V_107 = ~ V_26 -> V_20 . V_107 ;
break;
case 3 :
F_76 ( L_9 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 4 :
F_77 ( L_10 , V_26 -> V_15 , * V_214 , * V_215 , V_2 -> V_161 ) ;
break;
case 5 :
F_77 ( L_11 , V_26 -> V_15 , * V_214 , * V_215 , V_2 -> V_161 ) ;
break;
case 6 :
F_78 ( L_12 , V_26 -> V_15 , * V_214 , * V_215 ,
V_2 -> V_161 , V_217 ) ;
break;
case 7 :
F_78 ( L_13 , V_26 -> V_15 , * V_214 , * V_215 ,
V_2 -> V_161 , V_217 ) ;
break;
default:
return V_92 ;
}
if ( V_217 )
return F_17 ( V_2 ) ;
return V_79 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
switch ( V_26 -> V_12 ) {
case 0 :
F_76 ( L_14 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 1 :
F_76 ( L_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 2 : {
long int V_218 ;
V_218 = V_26 -> V_23 ;
V_26 -> V_23 = V_26 -> V_15 . V_107 ;
V_26 -> V_15 . V_107 = V_218 ;
V_82 = F_56 ( V_2 ) ;
break;
}
case 4 :
V_26 -> V_23 = V_26 -> V_15 . V_107 ;
break;
case 5 :
V_82 = F_70 ( V_2 ) ;
break;
case 6 :
V_82 = F_56 ( V_2 ) ;
break;
}
return V_82 ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_108 V_219 = V_26 -> V_20 . V_220 ;
if ( ( ( T_1 ) ( V_219 >> 0 ) != ( T_1 ) V_26 -> V_93 [ V_199 ] ) ||
( ( T_1 ) ( V_219 >> 32 ) != ( T_1 ) V_26 -> V_93 [ V_216 ] ) ) {
V_26 -> V_93 [ V_199 ] = ( T_1 ) ( V_219 >> 0 ) ;
V_26 -> V_93 [ V_216 ] = ( T_1 ) ( V_219 >> 32 ) ;
V_2 -> V_161 &= ~ V_102 ;
} else {
V_26 -> V_20 . V_16 = ( ( V_108 ) V_26 -> V_93 [ V_160 ] << 32 ) |
( T_1 ) V_26 -> V_93 [ V_132 ] ;
V_2 -> V_161 |= V_102 ;
}
return V_79 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_37 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
unsigned long V_203 ;
V_82 = F_57 ( V_2 , & V_26 -> V_23 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
if ( V_26 -> V_97 == 4 )
V_26 -> V_23 = ( T_1 ) V_26 -> V_23 ;
V_82 = F_57 ( V_2 , & V_203 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_82 = F_51 ( V_2 , V_24 , ( T_2 ) V_203 , V_89 ) ;
return V_82 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_37 * V_24 , int V_34 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
unsigned short V_71 ;
int V_82 ;
memcpy ( & V_71 , V_26 -> V_15 . V_213 + V_26 -> V_97 , 2 ) ;
V_82 = F_51 ( V_2 , V_24 , V_71 , V_34 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_20 . V_107 = V_26 -> V_15 . V_107 ;
return V_82 ;
}
static inline void
F_83 ( struct V_1 * V_2 ,
struct V_37 * V_24 , struct V_30 * V_203 ,
struct V_30 * V_221 )
{
T_2 V_57 ;
memset ( V_203 , 0 , sizeof( struct V_30 ) ) ;
V_24 -> V_58 ( V_2 , & V_57 , V_203 , NULL , V_89 ) ;
memset ( V_221 , 0 , sizeof( struct V_30 ) ) ;
V_203 -> V_222 = 0 ;
F_52 ( V_203 , 0 ) ;
V_203 -> V_33 = 1 ;
F_53 ( V_203 , 0xfffff ) ;
V_203 -> type = 0x0b ;
V_203 -> V_176 = 1 ;
V_203 -> V_78 = 0 ;
V_203 -> V_95 = 1 ;
V_203 -> V_77 = 1 ;
F_52 ( V_221 , 0 ) ;
F_53 ( V_221 , 0xfffff ) ;
V_221 -> V_33 = 1 ;
V_221 -> V_176 = 1 ;
V_221 -> type = 0x03 ;
V_221 -> V_77 = 1 ;
V_221 -> V_78 = 0 ;
V_221 -> V_95 = 1 ;
}
static int
F_84 ( struct V_1 * V_2 , struct V_37 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_30 V_203 , V_221 ;
V_108 V_223 ;
T_2 V_224 , V_225 ;
V_108 V_226 = 0 ;
if ( V_2 -> V_38 == V_75 ||
V_2 -> V_38 == V_175 )
return F_15 ( V_2 ) ;
V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
F_83 ( V_2 , V_24 , & V_203 , & V_221 ) ;
V_24 -> V_227 ( V_2 , V_229 , & V_223 ) ;
V_223 >>= 32 ;
V_224 = ( T_2 ) ( V_223 & 0xfffc ) ;
V_225 = ( T_2 ) ( V_223 + 8 ) ;
if ( V_226 & V_230 ) {
V_203 . V_77 = 0 ;
V_203 . V_222 = 1 ;
}
V_24 -> V_61 ( V_2 , V_224 , & V_203 , 0 , V_89 ) ;
V_24 -> V_61 ( V_2 , V_225 , & V_221 , 0 , V_80 ) ;
V_26 -> V_93 [ V_160 ] = V_26 -> V_23 ;
if ( V_226 & V_230 ) {
#ifdef F_34
V_26 -> V_93 [ V_231 ] = V_2 -> V_161 & ~ V_191 ;
V_24 -> V_227 ( V_2 ,
V_2 -> V_38 == V_39 ?
V_232 : V_233 , & V_223 ) ;
V_26 -> V_23 = V_223 ;
V_24 -> V_227 ( V_2 , V_234 , & V_223 ) ;
V_2 -> V_161 &= ~ ( V_223 | V_191 ) ;
#endif
} else {
V_24 -> V_227 ( V_2 , V_229 , & V_223 ) ;
V_26 -> V_23 = ( T_1 ) V_223 ;
V_2 -> V_161 &= ~ ( V_208 | V_197 | V_191 ) ;
}
return V_79 ;
}
static int
F_85 ( struct V_1 * V_2 , struct V_37 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_30 V_203 , V_221 ;
V_108 V_223 ;
T_2 V_224 , V_225 ;
V_108 V_226 = 0 ;
V_2 -> V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
if ( V_2 -> V_38 == V_75 )
return F_13 ( V_2 , 0 ) ;
if ( V_2 -> V_38 == V_39 )
return F_15 ( V_2 ) ;
F_83 ( V_2 , V_24 , & V_203 , & V_221 ) ;
V_24 -> V_227 ( V_2 , V_235 , & V_223 ) ;
switch ( V_2 -> V_38 ) {
case V_194 :
if ( ( V_223 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
case V_39 :
if ( V_223 == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
}
V_2 -> V_161 &= ~ ( V_208 | V_197 | V_191 ) ;
V_224 = ( T_2 ) V_223 ;
V_224 &= ~ V_236 ;
V_225 = V_224 + 8 ;
V_225 &= ~ V_236 ;
if ( V_2 -> V_38 == V_39 || ( V_226 & V_230 ) ) {
V_203 . V_77 = 0 ;
V_203 . V_222 = 1 ;
}
V_24 -> V_61 ( V_2 , V_224 , & V_203 , 0 , V_89 ) ;
V_24 -> V_61 ( V_2 , V_225 , & V_221 , 0 , V_80 ) ;
V_24 -> V_227 ( V_2 , V_237 , & V_223 ) ;
V_26 -> V_23 = V_223 ;
V_24 -> V_227 ( V_2 , V_238 , & V_223 ) ;
V_26 -> V_93 [ V_182 ] = V_223 ;
return V_79 ;
}
static int
F_86 ( struct V_1 * V_2 , struct V_37 * V_24 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_30 V_203 , V_221 ;
V_108 V_223 ;
int V_239 ;
T_2 V_224 , V_225 ;
if ( V_2 -> V_38 == V_75 ||
V_2 -> V_38 == V_175 )
return F_13 ( V_2 , 0 ) ;
F_83 ( V_2 , V_24 , & V_203 , & V_221 ) ;
if ( ( V_26 -> V_112 & 0x8 ) != 0x0 )
V_239 = V_39 ;
else
V_239 = V_194 ;
V_203 . V_78 = 3 ;
V_221 . V_78 = 3 ;
V_24 -> V_227 ( V_2 , V_235 , & V_223 ) ;
switch ( V_239 ) {
case V_194 :
V_224 = ( T_2 ) ( V_223 + 16 ) ;
if ( ( V_223 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_225 = ( T_2 ) ( V_223 + 24 ) ;
break;
case V_39 :
V_224 = ( T_2 ) ( V_223 + 32 ) ;
if ( V_223 == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_225 = V_224 + 8 ;
V_203 . V_77 = 0 ;
V_203 . V_222 = 1 ;
break;
}
V_224 |= V_236 ;
V_225 |= V_236 ;
V_24 -> V_61 ( V_2 , V_224 , & V_203 , 0 , V_89 ) ;
V_24 -> V_61 ( V_2 , V_225 , & V_221 , 0 , V_80 ) ;
V_26 -> V_23 = V_26 -> V_93 [ V_216 ] ;
V_26 -> V_93 [ V_182 ] = V_26 -> V_93 [ V_160 ] ;
return V_79 ;
}
static bool F_87 ( struct V_1 * V_2 ,
struct V_37 * V_24 )
{
int V_185 ;
if ( V_2 -> V_38 == V_75 )
return false ;
if ( V_2 -> V_38 == V_175 )
return true ;
V_185 = ( V_2 -> V_161 & V_186 ) >> V_187 ;
return V_24 -> V_72 ( V_2 ) > V_185 ;
}
static bool F_88 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_156 , T_2 V_183 )
{
struct V_30 V_240 ;
T_1 V_60 ;
int V_241 ;
T_2 V_242 , V_243 , V_244 , V_245 = V_156 & 0x7 ;
unsigned V_145 = ( 1 << V_183 ) - 1 ;
unsigned long V_246 ;
V_24 -> V_58 ( V_2 , & V_242 , & V_240 , & V_60 , V_178 ) ;
if ( ! V_240 . V_95 )
return false ;
if ( F_7 ( & V_240 ) < 103 )
return false ;
V_246 = F_48 ( & V_240 ) ;
#ifdef F_34
V_246 |= ( ( V_108 ) V_60 ) << 32 ;
#endif
V_241 = V_24 -> V_83 ( V_2 , V_246 + 102 , & V_243 , 2 , NULL ) ;
if ( V_241 != V_79 )
return false ;
if ( V_243 + V_156 / 8 > F_7 ( & V_240 ) )
return false ;
V_241 = V_24 -> V_83 ( V_2 , V_246 + V_243 + V_156 / 8 , & V_244 , 2 , NULL ) ;
if ( V_241 != V_79 )
return false ;
if ( ( V_244 >> V_245 ) & V_145 )
return false ;
return true ;
}
static bool F_89 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_156 , T_2 V_183 )
{
if ( V_2 -> V_247 )
return true ;
if ( F_87 ( V_2 , V_24 ) )
if ( ! F_88 ( V_2 , V_24 , V_156 , V_183 ) )
return false ;
V_2 -> V_247 = true ;
return true ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_248 * V_249 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_249 -> V_250 = V_26 -> V_23 ;
V_249 -> V_251 = V_2 -> V_161 ;
V_249 -> V_252 = V_26 -> V_93 [ V_199 ] ;
V_249 -> V_253 = V_26 -> V_93 [ V_160 ] ;
V_249 -> V_254 = V_26 -> V_93 [ V_216 ] ;
V_249 -> V_131 = V_26 -> V_93 [ V_132 ] ;
V_249 -> V_255 = V_26 -> V_93 [ V_182 ] ;
V_249 -> V_133 = V_26 -> V_93 [ V_134 ] ;
V_249 -> V_135 = V_26 -> V_93 [ V_136 ] ;
V_249 -> V_137 = V_26 -> V_93 [ V_138 ] ;
V_249 -> V_256 = F_19 ( V_2 , V_257 ) ;
V_249 -> V_203 = F_19 ( V_2 , V_89 ) ;
V_249 -> V_221 = F_19 ( V_2 , V_80 ) ;
V_249 -> V_258 = F_19 ( V_2 , V_129 ) ;
V_249 -> V_259 = F_19 ( V_2 , V_165 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_248 * V_249 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_168 ;
V_26 -> V_23 = V_249 -> V_250 ;
V_2 -> V_161 = V_249 -> V_251 | 2 ;
V_26 -> V_93 [ V_199 ] = V_249 -> V_252 ;
V_26 -> V_93 [ V_160 ] = V_249 -> V_253 ;
V_26 -> V_93 [ V_216 ] = V_249 -> V_254 ;
V_26 -> V_93 [ V_132 ] = V_249 -> V_131 ;
V_26 -> V_93 [ V_182 ] = V_249 -> V_255 ;
V_26 -> V_93 [ V_134 ] = V_249 -> V_133 ;
V_26 -> V_93 [ V_136 ] = V_249 -> V_135 ;
V_26 -> V_93 [ V_138 ] = V_249 -> V_137 ;
F_20 ( V_2 , V_249 -> V_259 , V_165 ) ;
F_20 ( V_2 , V_249 -> V_256 , V_257 ) ;
F_20 ( V_2 , V_249 -> V_203 , V_89 ) ;
F_20 ( V_2 , V_249 -> V_221 , V_80 ) ;
F_20 ( V_2 , V_249 -> V_258 , V_129 ) ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_259 , V_165 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_256 , V_257 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_203 , V_89 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_221 , V_80 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_258 , V_129 ) ;
if ( V_168 != V_79 )
return V_168 ;
return V_79 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_260 , T_2 V_261 ,
T_3 V_262 , struct V_30 * V_263 )
{
struct V_248 V_264 ;
int V_168 ;
T_1 V_265 = F_48 ( V_263 ) ;
V_168 = V_24 -> V_83 ( V_2 , V_262 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
F_90 ( V_2 , V_24 , & V_264 ) ;
V_168 = V_24 -> V_169 ( V_2 , V_262 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = V_24 -> V_83 ( V_2 , V_265 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
if ( V_261 != 0xffff ) {
V_264 . V_266 = V_261 ;
V_168 = V_24 -> V_169 ( V_2 , V_265 ,
& V_264 . V_266 ,
sizeof V_264 . V_266 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
}
return F_91 ( V_2 , V_24 , & V_264 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_267 * V_249 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_249 -> V_268 = V_24 -> V_269 ( V_2 , 3 ) ;
V_249 -> V_23 = V_26 -> V_23 ;
V_249 -> V_161 = V_2 -> V_161 ;
V_249 -> V_270 = V_26 -> V_93 [ V_199 ] ;
V_249 -> V_271 = V_26 -> V_93 [ V_160 ] ;
V_249 -> V_272 = V_26 -> V_93 [ V_216 ] ;
V_249 -> V_273 = V_26 -> V_93 [ V_132 ] ;
V_249 -> V_274 = V_26 -> V_93 [ V_182 ] ;
V_249 -> V_275 = V_26 -> V_93 [ V_134 ] ;
V_249 -> V_276 = V_26 -> V_93 [ V_136 ] ;
V_249 -> V_277 = V_26 -> V_93 [ V_138 ] ;
V_249 -> V_256 = F_19 ( V_2 , V_257 ) ;
V_249 -> V_203 = F_19 ( V_2 , V_89 ) ;
V_249 -> V_221 = F_19 ( V_2 , V_80 ) ;
V_249 -> V_258 = F_19 ( V_2 , V_129 ) ;
V_249 -> V_278 = F_19 ( V_2 , V_40 ) ;
V_249 -> V_279 = F_19 ( V_2 , V_174 ) ;
V_249 -> V_280 = F_19 ( V_2 , V_165 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
struct V_267 * V_249 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_168 ;
if ( V_24 -> V_281 ( V_2 , 3 , V_249 -> V_268 ) )
return F_13 ( V_2 , 0 ) ;
V_26 -> V_23 = V_249 -> V_23 ;
V_2 -> V_161 = V_249 -> V_161 | 2 ;
V_26 -> V_93 [ V_199 ] = V_249 -> V_270 ;
V_26 -> V_93 [ V_160 ] = V_249 -> V_271 ;
V_26 -> V_93 [ V_216 ] = V_249 -> V_272 ;
V_26 -> V_93 [ V_132 ] = V_249 -> V_273 ;
V_26 -> V_93 [ V_182 ] = V_249 -> V_274 ;
V_26 -> V_93 [ V_134 ] = V_249 -> V_275 ;
V_26 -> V_93 [ V_136 ] = V_249 -> V_276 ;
V_26 -> V_93 [ V_138 ] = V_249 -> V_277 ;
F_20 ( V_2 , V_249 -> V_280 , V_165 ) ;
F_20 ( V_2 , V_249 -> V_256 , V_257 ) ;
F_20 ( V_2 , V_249 -> V_203 , V_89 ) ;
F_20 ( V_2 , V_249 -> V_221 , V_80 ) ;
F_20 ( V_2 , V_249 -> V_258 , V_129 ) ;
F_20 ( V_2 , V_249 -> V_278 , V_40 ) ;
F_20 ( V_2 , V_249 -> V_279 , V_174 ) ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_280 , V_165 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_256 , V_257 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_203 , V_89 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_221 , V_80 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_258 , V_129 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_278 , V_40 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_51 ( V_2 , V_24 , V_249 -> V_279 , V_174 ) ;
if ( V_168 != V_79 )
return V_168 ;
return V_79 ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_260 , T_2 V_261 ,
T_3 V_262 , struct V_30 * V_263 )
{
struct V_267 V_264 ;
int V_168 ;
T_1 V_265 = F_48 ( V_263 ) ;
V_168 = V_24 -> V_83 ( V_2 , V_262 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
F_93 ( V_2 , V_24 , & V_264 ) ;
V_168 = V_24 -> V_169 ( V_2 , V_262 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = V_24 -> V_83 ( V_2 , V_265 , & V_264 , sizeof V_264 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
if ( V_261 != 0xffff ) {
V_264 . V_266 = V_261 ;
V_168 = V_24 -> V_169 ( V_2 , V_265 ,
& V_264 . V_266 ,
sizeof V_264 . V_266 ,
& V_2 -> V_44 ) ;
if ( V_168 != V_79 )
return V_168 ;
}
return F_94 ( V_2 , V_24 , & V_264 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_37 * V_24 ,
T_2 V_260 , int V_282 ,
bool V_283 , T_1 V_46 )
{
struct V_30 V_284 , V_285 ;
int V_168 ;
T_2 V_261 = F_19 ( V_2 , V_178 ) ;
T_3 V_262 =
V_24 -> V_41 ( V_2 , V_178 ) ;
T_1 V_286 ;
V_168 = F_49 ( V_2 , V_24 , V_260 , & V_285 ) ;
if ( V_168 != V_79 )
return V_168 ;
V_168 = F_49 ( V_2 , V_24 , V_261 , & V_284 ) ;
if ( V_168 != V_79 )
return V_168 ;
if ( V_282 != V_287 ) {
if ( ( V_260 & 3 ) > V_285 . V_78 ||
V_24 -> V_72 ( V_2 ) > V_285 . V_78 )
return F_13 ( V_2 , 0 ) ;
}
V_286 = F_7 ( & V_285 ) ;
if ( ! V_285 . V_95 ||
( ( V_286 < 0x67 && ( V_285 . type & 8 ) ) ||
V_286 < 0x2b ) ) {
F_16 ( V_2 , V_260 & 0xfffc ) ;
return V_48 ;
}
if ( V_282 == V_287 || V_282 == V_288 ) {
V_284 . type &= ~ ( 1 << 1 ) ;
F_50 ( V_2 , V_24 , V_261 ,
& V_284 ) ;
}
if ( V_282 == V_287 )
V_2 -> V_161 = V_2 -> V_161 & ~ V_289 ;
if ( V_282 != V_290 && V_282 != V_291 )
V_261 = 0xffff ;
if ( V_285 . type & 8 )
V_168 = F_95 ( V_2 , V_24 , V_260 , V_261 ,
V_262 , & V_285 ) ;
else
V_168 = F_92 ( V_2 , V_24 , V_260 , V_261 ,
V_262 , & V_285 ) ;
if ( V_168 != V_79 )
return V_168 ;
if ( V_282 == V_290 || V_282 == V_291 )
V_2 -> V_161 = V_2 -> V_161 | V_289 ;
if ( V_282 != V_287 ) {
V_285 . type |= ( 1 << 1 ) ;
F_50 ( V_2 , V_24 , V_260 ,
& V_285 ) ;
}
V_24 -> V_281 ( V_2 , 0 , V_24 -> V_269 ( V_2 , 0 ) | V_292 ) ;
V_24 -> V_61 ( V_2 , V_260 , & V_285 , 0 , V_178 ) ;
if ( V_283 ) {
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_97 = V_26 -> V_21 = ( V_285 . type & 8 ) ? 4 : 2 ;
V_26 -> V_180 = 0 ;
V_26 -> V_15 . V_107 = ( unsigned long ) V_46 ;
V_168 = F_56 ( V_2 ) ;
}
return V_168 ;
}
int F_97 ( struct V_1 * V_2 ,
T_2 V_260 , int V_282 ,
bool V_283 , T_1 V_46 )
{
struct V_37 * V_24 = V_2 -> V_24 ;
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
V_26 -> V_23 = V_2 -> V_23 ;
V_26 -> V_20 . type = V_181 ;
V_82 = F_96 ( V_2 , V_24 , V_260 , V_282 ,
V_283 , V_46 ) ;
if ( V_82 == V_79 )
V_2 -> V_23 = V_26 -> V_23 ;
return ( V_82 == V_92 ) ? V_293 : V_294 ;
}
static void F_98 ( struct V_1 * V_2 , unsigned V_34 ,
int V_27 , struct V_105 * V_106 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_295 = ( V_2 -> V_161 & V_162 ) ? - 1 : 1 ;
F_5 ( V_26 , & V_26 -> V_93 [ V_27 ] , V_295 * V_106 -> V_18 ) ;
V_106 -> V_63 . V_142 . V_74 = F_4 ( V_26 , V_26 -> V_93 [ V_27 ] ) ;
V_106 -> V_63 . V_142 . V_34 = V_34 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
T_4 V_296 , V_297 ;
bool V_298 , V_299 , V_300 ;
V_299 = V_2 -> V_161 & V_301 ;
V_296 = V_26 -> V_20 . V_107 ;
V_297 = V_296 ;
V_300 = V_299 ;
V_299 = false ;
V_298 = V_2 -> V_161 & V_302 ;
if ( ( V_296 & 0x0f ) > 9 || V_298 ) {
V_296 -= 6 ;
V_299 = V_300 | ( V_296 >= 250 ) ;
V_298 = true ;
} else {
V_298 = false ;
}
if ( V_297 > 0x99 || V_300 ) {
V_296 -= 0x60 ;
V_299 = true ;
}
V_26 -> V_20 . V_107 = V_296 ;
V_26 -> V_15 . type = V_303 ;
V_26 -> V_15 . V_107 = 0 ;
V_26 -> V_15 . V_18 = 1 ;
F_75 ( L_16 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
V_2 -> V_161 &= ~ ( V_302 | V_301 ) ;
if ( V_299 )
V_2 -> V_161 |= V_301 ;
if ( V_298 )
V_2 -> V_161 |= V_302 ;
return V_79 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
T_2 V_71 , V_304 ;
T_3 V_218 ;
int V_82 ;
V_304 = F_19 ( V_2 , V_89 ) ;
V_218 = V_26 -> V_23 ;
memcpy ( & V_71 , V_26 -> V_15 . V_213 + V_26 -> V_97 , 2 ) ;
if ( F_51 ( V_2 , V_2 -> V_24 , V_71 , V_89 ) )
return V_79 ;
V_26 -> V_23 = 0 ;
memcpy ( & V_26 -> V_23 , V_26 -> V_15 . V_213 , V_26 -> V_97 ) ;
V_26 -> V_15 . V_107 = V_304 ;
V_82 = F_56 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_15 . V_107 = V_218 ;
return F_56 ( V_2 ) ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_63 . V_27 = & V_26 -> V_23 ;
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
V_82 = F_57 ( V_2 , & V_26 -> V_20 . V_107 , V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
F_5 ( V_26 , & V_26 -> V_93 [ V_182 ] , V_26 -> V_15 . V_107 ) ;
return V_79 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_17 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_16 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_18 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_19 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_20 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_21 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_22 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_75 ( L_23 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
F_111 ( L_11 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
return V_79 ;
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . V_107 = V_26 -> V_305 . V_107 ;
return F_110 ( V_2 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_18 = V_26 -> V_15 . V_18 ;
V_26 -> V_20 . V_63 . V_27 = & V_26 -> V_93 [ V_216 ] ;
V_26 -> V_20 . V_107 = ~ ( ( V_26 -> V_15 . V_107 >> ( V_26 -> V_15 . V_18 * 8 - 1 ) ) - 1 ) ;
return V_79 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_108 V_306 = 0 ;
V_2 -> V_24 -> V_227 ( V_2 , V_307 , & V_306 ) ;
V_26 -> V_93 [ V_199 ] = ( T_1 ) V_306 ;
V_26 -> V_93 [ V_216 ] = V_306 >> 32 ;
return V_79 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . V_107 = V_26 -> V_15 . V_107 ;
return V_79 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
memcpy ( & V_26 -> V_20 . V_118 , & V_26 -> V_15 . V_118 , V_26 -> V_97 ) ;
return V_79 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
T_3 V_67 ;
V_82 = F_23 ( V_2 , V_26 -> V_15 . V_63 . V_142 , 1 , false , & V_67 ) ;
if ( V_82 == V_79 )
V_2 -> V_24 -> V_308 ( V_2 , V_67 ) ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_3 V_309 ;
V_309 = V_2 -> V_24 -> V_269 ( V_2 , 0 ) ;
V_309 &= ~ V_292 ;
V_2 -> V_24 -> V_281 ( V_2 , 0 , V_309 ) ;
return V_79 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
if ( V_26 -> V_11 != 3 || V_26 -> V_13 != 1 )
return V_92 ;
V_82 = V_2 -> V_24 -> V_310 ( V_2 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_26 -> V_23 = V_2 -> V_23 ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_163 V_163 ;
int V_82 ;
V_82 = F_30 ( V_2 , V_26 -> V_15 . V_63 . V_142 ,
& V_163 . V_64 , & V_163 . V_96 ,
V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_24 -> V_311 ( V_2 , & V_163 ) ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 ;
V_82 = V_2 -> V_24 -> V_310 ( V_2 ) ;
V_26 -> V_20 . type = V_181 ;
return V_82 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_163 V_163 ;
int V_82 ;
V_82 = F_30 ( V_2 , V_26 -> V_15 . V_63 . V_142 ,
& V_163 . V_64 , & V_163 . V_96 ,
V_26 -> V_97 ) ;
if ( V_82 != V_79 )
return V_82 ;
V_2 -> V_24 -> V_312 ( V_2 , & V_163 ) ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . V_18 = 2 ;
V_26 -> V_20 . V_107 = V_2 -> V_24 -> V_269 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_2 -> V_24 -> V_281 ( V_2 , 0 , ( V_2 -> V_24 -> V_269 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_26 -> V_15 . V_107 & 0x0f ) ) ;
V_26 -> V_20 . type = V_181 ;
return V_79 ;
}
static bool F_125 ( int V_313 )
{
switch ( V_313 ) {
case 0 :
case 2 ... 4 :
case 8 :
return true ;
default:
return false ;
}
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
if ( ! F_125 ( V_26 -> V_12 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_108 V_314 = V_26 -> V_15 . V_16 ;
int V_315 = V_26 -> V_12 ;
V_108 V_226 = 0 ;
static V_108 V_316 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_317 ,
0 , 0 , 0 ,
V_318 ,
} ;
if ( ! F_125 ( V_315 ) )
return F_15 ( V_2 ) ;
if ( V_314 & V_316 [ V_315 ] )
return F_13 ( V_2 , 0 ) ;
switch ( V_315 ) {
case 0 : {
V_108 V_319 ;
if ( ( ( V_314 & V_320 ) && ! ( V_314 & V_321 ) ) ||
( ( V_314 & V_322 ) && ! ( V_314 & V_323 ) ) )
return F_13 ( V_2 , 0 ) ;
V_319 = V_2 -> V_24 -> V_269 ( V_2 , 4 ) ;
V_2 -> V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
if ( ( V_314 & V_320 ) && ( V_226 & V_324 ) &&
! ( V_319 & V_325 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_108 V_326 = 0 ;
V_2 -> V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
if ( V_226 & V_230 )
V_326 = V_327 ;
else if ( V_2 -> V_24 -> V_269 ( V_2 , 4 ) & V_325 )
V_326 = V_328 ;
else if ( V_2 -> V_24 -> V_269 ( V_2 , 0 ) & V_320 )
V_326 = V_329 ;
if ( V_314 & V_326 )
return F_13 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_108 V_319 ;
V_319 = V_2 -> V_24 -> V_269 ( V_2 , 4 ) ;
V_2 -> V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
if ( ( V_226 & V_230 ) && ! ( V_314 & V_325 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
}
return V_79 ;
}
static int F_128 ( struct V_1 * V_2 )
{
unsigned long V_330 ;
V_2 -> V_24 -> V_331 ( V_2 , 7 , & V_330 ) ;
return V_330 & ( 1 << 13 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_332 = V_26 -> V_12 ;
V_108 V_319 ;
if ( V_332 > 7 )
return F_15 ( V_2 ) ;
V_319 = V_2 -> V_24 -> V_269 ( V_2 , 4 ) ;
if ( ( V_319 & V_333 ) && ( V_332 == 4 || V_332 == 5 ) )
return F_15 ( V_2 ) ;
if ( F_128 ( V_2 ) )
return F_12 ( V_2 ) ;
return V_79 ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_108 V_314 = V_26 -> V_15 . V_16 ;
int V_332 = V_26 -> V_12 ;
if ( ( V_332 == 6 || V_332 == 7 ) && ( V_314 & 0xffffffff00000000ULL ) )
return F_13 ( V_2 , 0 ) ;
return F_129 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
V_108 V_226 ;
V_2 -> V_24 -> V_227 ( V_2 , V_228 , & V_226 ) ;
if ( ! ( V_226 & V_334 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_132 ( struct V_1 * V_2 )
{
V_108 V_214 = V_2 -> V_10 . V_93 [ V_199 ] ;
if ( V_214 & 0xffff000000000000ULL )
return F_13 ( V_2 , 0 ) ;
return F_131 ( V_2 ) ;
}
static int F_133 ( struct V_1 * V_2 )
{
V_108 V_319 = V_2 -> V_24 -> V_269 ( V_2 , 4 ) ;
if ( V_319 & V_335 && V_2 -> V_24 -> V_72 ( V_2 ) )
return F_15 ( V_2 ) ;
return V_79 ;
}
static int F_134 ( struct V_1 * V_2 )
{
V_108 V_319 = V_2 -> V_24 -> V_269 ( V_2 , 4 ) ;
V_108 V_336 = V_2 -> V_10 . V_93 [ V_160 ] ;
if ( ( ! ( V_319 & V_337 ) && V_2 -> V_24 -> V_72 ( V_2 ) ) ||
( V_336 > 3 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_20 . V_18 = F_26 ( V_26 -> V_20 . V_18 , 4u ) ;
if ( ! F_89 ( V_2 , V_2 -> V_24 , V_26 -> V_15 . V_107 , V_26 -> V_20 . V_18 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static int F_136 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
V_26 -> V_15 . V_18 = F_26 ( V_26 -> V_15 . V_18 , 4u ) ;
if ( ! F_89 ( V_2 , V_2 -> V_24 , V_26 -> V_20 . V_107 , V_26 -> V_15 . V_18 ) )
return F_13 ( V_2 , 0 ) ;
return V_79 ;
}
static unsigned F_137 ( struct V_25 * V_26 )
{
unsigned V_64 ;
V_64 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
if ( V_64 == 8 )
V_64 = 4 ;
return V_64 ;
}
static int F_138 ( struct V_1 * V_2 , struct V_105 * V_106 ,
unsigned V_64 , bool V_338 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
struct V_37 * V_24 = V_2 -> V_24 ;
int V_82 = V_79 ;
V_106 -> type = V_303 ;
V_106 -> V_18 = V_64 ;
V_106 -> V_63 . V_142 . V_74 = V_26 -> V_23 ;
switch ( V_106 -> V_18 ) {
case 1 :
V_106 -> V_107 = F_39 ( V_139 , 1 , V_26 -> V_23 ) ;
break;
case 2 :
V_106 -> V_107 = F_39 ( V_146 , 2 , V_26 -> V_23 ) ;
break;
case 4 :
V_106 -> V_107 = F_39 ( V_140 , 4 , V_26 -> V_23 ) ;
break;
}
if ( ! V_338 ) {
switch ( V_106 -> V_18 ) {
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
V_143:
return V_82 ;
}
int
F_139 ( struct V_1 * V_2 , void * V_339 , int V_340 )
{
struct V_37 * V_24 = V_2 -> V_24 ;
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
int V_38 = V_2 -> V_38 ;
int V_341 , V_342 , V_343 , V_344 ;
bool V_345 = false ;
struct V_346 V_346 ;
struct V_105 V_347 = { . type = V_181 } , * V_348 = NULL ;
V_26 -> V_23 = V_2 -> V_23 ;
V_26 -> V_66 . V_90 = V_26 -> V_23 ;
V_26 -> V_66 . V_88 = V_26 -> V_66 . V_90 + V_340 ;
if ( V_340 > 0 )
memcpy ( V_26 -> V_66 . V_81 , V_339 , V_340 ) ;
switch ( V_38 ) {
case V_75 :
case V_175 :
case V_195 :
V_341 = V_342 = 2 ;
break;
case V_194 :
V_341 = V_342 = 4 ;
break;
#ifdef F_34
case V_39 :
V_341 = 4 ;
V_342 = 8 ;
break;
#endif
default:
return - 1 ;
}
V_26 -> V_97 = V_341 ;
V_26 -> V_21 = V_342 ;
for (; ; ) {
switch ( V_26 -> V_114 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ) {
case 0x66 :
V_345 = true ;
V_26 -> V_97 = V_341 ^ 6 ;
break;
case 0x67 :
if ( V_38 == V_39 )
V_26 -> V_21 = V_342 ^ 12 ;
else
V_26 -> V_21 = V_342 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_9 ( V_26 , ( V_26 -> V_114 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_9 ( V_26 , V_26 -> V_114 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_38 != V_39 )
goto V_349;
V_26 -> V_112 = V_26 -> V_114 ;
continue;
case 0xf0 :
V_26 -> V_180 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_26 -> V_9 = V_26 -> V_114 ;
break;
default:
goto V_349;
}
V_26 -> V_112 = 0 ;
}
V_349:
if ( V_26 -> V_112 & 8 )
V_26 -> V_97 = 8 ;
V_346 = V_350 [ V_26 -> V_114 ] ;
if ( V_26 -> V_114 == 0x0f ) {
V_26 -> V_351 = 1 ;
V_26 -> V_114 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
V_346 = V_352 [ V_26 -> V_114 ] ;
}
V_26 -> V_77 = V_346 . V_99 ;
while ( V_26 -> V_77 & V_353 ) {
switch ( V_26 -> V_77 & V_353 ) {
case V_354 :
V_26 -> V_127 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
-- V_26 -> V_23 ;
V_343 = ( V_26 -> V_127 >> 3 ) & 7 ;
V_346 = V_346 . V_355 . V_356 [ V_343 ] ;
break;
case V_357 :
V_26 -> V_127 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
-- V_26 -> V_23 ;
V_343 = ( V_26 -> V_127 >> 3 ) & 7 ;
if ( ( V_26 -> V_127 >> 6 ) == 3 )
V_346 = V_346 . V_355 . V_358 -> V_359 [ V_343 ] ;
else
V_346 = V_346 . V_355 . V_358 -> V_360 [ V_343 ] ;
break;
case V_361 :
V_343 = V_26 -> V_127 & 7 ;
V_346 = V_346 . V_355 . V_356 [ V_343 ] ;
break;
case V_362 :
if ( V_26 -> V_9 && V_345 )
return V_92 ;
V_344 = V_345 ? 0x66 : V_26 -> V_9 ;
switch ( V_344 ) {
case 0x00 : V_346 = V_346 . V_355 . V_363 -> V_364 ; break;
case 0x66 : V_346 = V_346 . V_355 . V_363 -> V_365 ; break;
case 0xf2 : V_346 = V_346 . V_355 . V_363 -> V_366 ; break;
case 0xf3 : V_346 = V_346 . V_355 . V_363 -> V_367 ; break;
}
break;
default:
return V_92 ;
}
V_26 -> V_77 &= ~ V_353 ;
V_26 -> V_77 |= V_346 . V_99 ;
}
V_26 -> V_368 = V_346 . V_355 . V_368 ;
V_26 -> V_369 = V_346 . V_369 ;
V_26 -> V_4 = V_346 . V_4 ;
if ( V_26 -> V_77 == 0 || ( V_26 -> V_77 & V_370 ) )
return - 1 ;
if ( ! ( V_26 -> V_77 & V_371 ) && V_2 -> V_372 )
return - 1 ;
if ( V_38 == V_39 && ( V_26 -> V_77 & V_373 ) )
V_26 -> V_97 = 8 ;
if ( V_26 -> V_77 & V_374 ) {
if ( V_38 == V_39 )
V_26 -> V_97 = 8 ;
else
V_26 -> V_97 = 4 ;
}
if ( V_26 -> V_77 & V_115 )
V_26 -> V_97 = 16 ;
if ( V_26 -> V_77 & V_113 ) {
V_82 = F_38 ( V_2 , V_24 , & V_347 ) ;
if ( ! V_26 -> V_35 )
F_9 ( V_26 , V_26 -> V_128 ) ;
} else if ( V_26 -> V_77 & V_375 )
V_82 = F_40 ( V_2 , V_24 , & V_347 ) ;
if ( V_82 != V_79 )
goto V_143;
if ( ! V_26 -> V_35 )
F_9 ( V_26 , V_129 ) ;
V_347 . V_63 . V_142 . V_34 = V_36 ( V_2 , V_26 ) ;
if ( V_347 . type == V_130 && V_26 -> V_21 != 8 )
V_347 . V_63 . V_142 . V_74 = ( T_1 ) V_347 . V_63 . V_142 . V_74 ;
switch ( V_26 -> V_77 & V_376 ) {
case V_377 :
break;
case V_378 :
F_37 ( V_2 , & V_26 -> V_15 , V_26 , 0 ) ;
break;
case V_379 :
V_347 . V_18 = 2 ;
goto V_380;
case V_381 :
V_347 . V_18 = 4 ;
goto V_380;
case V_382 :
V_347 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 :
V_26 -> V_97 ;
V_380:
V_26 -> V_15 = V_347 ;
V_348 = & V_26 -> V_15 ;
break;
case V_383 :
V_82 = F_138 ( V_2 , & V_26 -> V_15 , 2 , false ) ;
break;
case V_384 :
V_82 = F_138 ( V_2 , & V_26 -> V_15 , F_137 ( V_26 ) , true ) ;
break;
case V_385 :
V_82 = F_138 ( V_2 , & V_26 -> V_15 , F_137 ( V_26 ) , false ) ;
break;
case V_386 :
V_82 = F_138 ( V_2 , & V_26 -> V_15 , 1 , true ) ;
break;
case V_387 :
V_82 = F_138 ( V_2 , & V_26 -> V_15 , 1 , false ) ;
break;
case V_388 :
V_26 -> V_15 . type = V_119 ;
V_26 -> V_15 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
V_26 -> V_15 . V_63 . V_27 = & V_26 -> V_93 [ V_199 ] ;
F_32 ( & V_26 -> V_15 ) ;
break;
case V_389 :
V_26 -> V_15 . V_18 = 1 ;
V_26 -> V_15 . V_107 = 1 ;
break;
case V_390 :
V_26 -> V_15 . type = V_130 ;
V_26 -> V_15 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
V_26 -> V_15 . V_63 . V_142 . V_74 =
F_4 ( V_26 , V_26 -> V_93 [ V_136 ] ) ;
V_26 -> V_15 . V_63 . V_142 . V_34 = V_36 ( V_2 , V_26 ) ;
V_26 -> V_15 . V_107 = 0 ;
break;
case V_391 :
V_26 -> V_15 . type = V_303 ;
V_26 -> V_15 . V_63 . V_142 . V_74 = V_26 -> V_23 ;
V_26 -> V_15 . V_18 = V_26 -> V_97 + 2 ;
F_140 ( V_26 -> V_15 . V_213 , V_26 -> V_15 . V_18 , V_26 -> V_23 ) ;
break;
case V_392 :
V_347 . V_18 = V_26 -> V_97 + 2 ;
goto V_380;
break;
case V_393 :
V_26 -> V_15 . type = V_119 ;
V_26 -> V_15 . V_18 = 2 ;
V_26 -> V_15 . V_63 . V_27 = & V_26 -> V_93 [ V_216 ] ;
F_32 ( & V_26 -> V_15 ) ;
break;
}
if ( V_82 != V_79 )
goto V_143;
switch ( V_26 -> V_77 & V_394 ) {
case V_395 :
break;
case V_396 :
V_26 -> V_305 . V_18 = 1 ;
V_26 -> V_305 . V_107 = V_26 -> V_93 [ V_160 ] & 0x8 ;
break;
case V_397 :
V_82 = F_138 ( V_2 , & V_26 -> V_305 , 1 , true ) ;
break;
case V_398 :
V_26 -> V_305 . V_18 = 1 ;
V_26 -> V_305 . V_107 = 1 ;
break;
case V_399 :
V_82 = F_138 ( V_2 , & V_26 -> V_305 , F_137 ( V_26 ) , true ) ;
break;
}
if ( V_82 != V_79 )
goto V_143;
switch ( V_26 -> V_77 & V_400 ) {
case V_401 :
F_37 ( V_2 , & V_26 -> V_20 , V_26 ,
V_26 -> V_351 && ( V_26 -> V_114 == 0xb6 || V_26 -> V_114 == 0xb7 ) ) ;
break;
case V_402 :
V_26 -> V_20 . type = V_303 ;
V_26 -> V_20 . V_63 . V_142 . V_74 = V_26 -> V_23 ;
V_26 -> V_20 . V_18 = 1 ;
V_26 -> V_20 . V_107 = F_39 ( T_4 , 1 , V_26 -> V_23 ) ;
break;
case V_403 :
case V_404 :
V_26 -> V_20 = V_347 ;
V_348 = & V_26 -> V_20 ;
if ( ( V_26 -> V_77 & V_400 ) == V_404 )
V_26 -> V_20 . V_18 = 8 ;
else
V_26 -> V_20 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
if ( V_26 -> V_77 & V_405 )
F_41 ( V_26 ) ;
V_26 -> V_20 . V_121 = V_26 -> V_20 . V_107 ;
break;
case V_406 :
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
V_26 -> V_20 . V_63 . V_27 = & V_26 -> V_93 [ V_199 ] ;
F_32 ( & V_26 -> V_20 ) ;
V_26 -> V_20 . V_121 = V_26 -> V_20 . V_107 ;
break;
case V_407 :
V_26 -> V_20 . type = V_130 ;
V_26 -> V_20 . V_18 = ( V_26 -> V_77 & V_120 ) ? 1 : V_26 -> V_97 ;
V_26 -> V_20 . V_63 . V_142 . V_74 =
F_4 ( V_26 , V_26 -> V_93 [ V_138 ] ) ;
V_26 -> V_20 . V_63 . V_142 . V_34 = V_257 ;
V_26 -> V_20 . V_107 = 0 ;
break;
case V_408 :
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_18 = 2 ;
V_26 -> V_20 . V_63 . V_27 = & V_26 -> V_93 [ V_216 ] ;
F_32 ( & V_26 -> V_20 ) ;
break;
case V_409 :
default:
V_26 -> V_20 . type = V_181 ;
break;
}
V_143:
if ( V_348 && V_348 -> type == V_130 && V_26 -> V_141 )
V_348 -> V_63 . V_142 . V_74 += V_26 -> V_23 ;
return ( V_82 == V_92 ) ? V_293 : V_294 ;
}
static bool F_141 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_10 ;
if ( ( ( V_26 -> V_114 == 0xa6 ) || ( V_26 -> V_114 == 0xa7 ) ||
( V_26 -> V_114 == 0xae ) || ( V_26 -> V_114 == 0xaf ) )
&& ( ( ( V_26 -> V_9 == V_410 ) &&
( ( V_2 -> V_161 & V_102 ) == 0 ) )
|| ( ( V_26 -> V_9 == V_411 ) &&
( ( V_2 -> V_161 & V_102 ) == V_102 ) ) ) )
return true ;
return false ;
}
int
F_142 ( struct V_1 * V_2 )
{
struct V_37 * V_24 = V_2 -> V_24 ;
V_108 V_223 ;
struct V_25 * V_26 = & V_2 -> V_10 ;
int V_82 = V_79 ;
int V_412 = V_26 -> V_20 . type ;
int V_200 ;
V_2 -> V_10 . V_149 . V_151 = 0 ;
if ( V_2 -> V_38 == V_39 && ( V_26 -> V_77 & V_413 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( V_26 -> V_180 && ( ! ( V_26 -> V_77 & V_414 ) || V_26 -> V_20 . type != V_130 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( ( V_26 -> V_77 & V_376 ) == V_392 && V_26 -> V_15 . type != V_130 ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( ( V_26 -> V_77 & V_115 )
&& ( ( V_24 -> V_269 ( V_2 , 0 ) & V_415 )
|| ! ( V_24 -> V_269 ( V_2 , 4 ) & V_416 ) ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( ( V_26 -> V_77 & V_115 ) && ( V_24 -> V_269 ( V_2 , 0 ) & V_292 ) ) {
V_82 = F_18 ( V_2 ) ;
goto V_143;
}
if ( F_143 ( V_2 -> V_417 ) && V_26 -> V_4 ) {
V_82 = F_1 ( V_2 , V_26 -> V_4 ,
V_418 ) ;
if ( V_82 != V_79 )
goto V_143;
}
if ( ( V_26 -> V_77 & V_419 ) && V_24 -> V_72 ( V_2 ) ) {
V_82 = F_13 ( V_2 , 0 ) ;
goto V_143;
}
if ( ( V_26 -> V_77 & V_420 ) && ! ( V_2 -> V_38 & V_421 ) ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( V_26 -> V_369 ) {
V_82 = V_26 -> V_369 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_143;
}
if ( F_143 ( V_2 -> V_417 ) && V_26 -> V_4 ) {
V_82 = F_1 ( V_2 , V_26 -> V_4 ,
V_422 ) ;
if ( V_82 != V_79 )
goto V_143;
}
if ( V_26 -> V_9 && ( V_26 -> V_77 & String ) ) {
if ( F_3 ( V_26 , V_26 -> V_93 [ V_160 ] ) == 0 ) {
V_2 -> V_23 = V_26 -> V_23 ;
goto V_143;
}
}
if ( ( V_26 -> V_15 . type == V_130 ) && ! ( V_26 -> V_77 & V_423 ) ) {
V_82 = F_43 ( V_2 , V_26 -> V_15 . V_63 . V_142 ,
V_26 -> V_15 . V_213 , V_26 -> V_15 . V_18 ) ;
if ( V_82 != V_79 )
goto V_143;
V_26 -> V_15 . V_220 = V_26 -> V_15 . V_16 ;
}
if ( V_26 -> V_305 . type == V_130 ) {
V_82 = F_43 ( V_2 , V_26 -> V_305 . V_63 . V_142 ,
& V_26 -> V_305 . V_107 , V_26 -> V_305 . V_18 ) ;
if ( V_82 != V_79 )
goto V_143;
}
if ( ( V_26 -> V_77 & V_400 ) == V_409 )
goto V_424;
if ( ( V_26 -> V_20 . type == V_130 ) && ! ( V_26 -> V_77 & V_425 ) ) {
V_82 = F_43 ( V_2 , V_26 -> V_20 . V_63 . V_142 ,
& V_26 -> V_20 . V_107 , V_26 -> V_20 . V_18 ) ;
if ( V_82 != V_79 )
goto V_143;
}
V_26 -> V_20 . V_121 = V_26 -> V_20 . V_107 ;
V_424:
if ( F_143 ( V_2 -> V_417 ) && V_26 -> V_4 ) {
V_82 = F_1 ( V_2 , V_26 -> V_4 ,
V_426 ) ;
if ( V_82 != V_79 )
goto V_143;
}
if ( V_26 -> V_368 ) {
V_82 = V_26 -> V_368 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_143;
goto F_55;
}
if ( V_26 -> V_351 )
goto V_427;
switch ( V_26 -> V_114 ) {
case 0x06 :
V_82 = F_61 ( V_2 , V_24 , V_257 ) ;
break;
case 0x07 :
V_82 = F_62 ( V_2 , V_24 , V_257 ) ;
break;
case 0x0e :
V_82 = F_61 ( V_2 , V_24 , V_89 ) ;
break;
case 0x16 :
V_82 = F_61 ( V_2 , V_24 , V_80 ) ;
break;
case 0x17 :
V_82 = F_62 ( V_2 , V_24 , V_80 ) ;
break;
case 0x1e :
V_82 = F_61 ( V_2 , V_24 , V_129 ) ;
break;
case 0x1f :
V_82 = F_62 ( V_2 , V_24 , V_129 ) ;
break;
case 0x40 ... 0x47 :
F_76 ( L_14 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0x48 ... 0x4f :
F_76 ( L_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0x63 :
if ( V_2 -> V_38 != V_39 )
goto V_428;
V_26 -> V_20 . V_107 = ( V_140 ) V_26 -> V_15 . V_107 ;
break;
case 0x6c :
case 0x6d :
V_26 -> V_15 . V_107 = V_26 -> V_93 [ V_216 ] ;
goto V_429;
case 0x6e :
case 0x6f :
V_26 -> V_20 . V_107 = V_26 -> V_93 [ V_216 ] ;
goto V_430;
break;
case 0x70 ... 0x7f :
if ( F_31 ( V_26 -> V_114 , V_2 -> V_161 ) )
F_6 ( V_26 , V_26 -> V_15 . V_107 ) ;
break;
case 0x84 ... 0x85 :
V_431:
F_75 ( L_8 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0x86 ... 0x87 :
V_432:
V_26 -> V_15 . V_107 = V_26 -> V_20 . V_107 ;
F_54 ( & V_26 -> V_15 ) ;
V_26 -> V_20 . V_107 = V_26 -> V_15 . V_121 ;
V_26 -> V_180 = 1 ;
break;
case 0x8c :
if ( V_26 -> V_12 > V_174 ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
V_26 -> V_20 . V_107 = F_19 ( V_2 , V_26 -> V_12 ) ;
break;
case 0x8d :
V_26 -> V_20 . V_107 = V_26 -> V_15 . V_63 . V_142 . V_74 ;
break;
case 0x8e : {
T_7 V_71 ;
V_71 = V_26 -> V_15 . V_107 ;
if ( V_26 -> V_12 == V_89 ||
V_26 -> V_12 > V_174 ) {
V_82 = F_15 ( V_2 ) ;
goto V_143;
}
if ( V_26 -> V_12 == V_80 )
V_2 -> V_433 = V_434 ;
V_82 = F_51 ( V_2 , V_24 , V_71 , V_26 -> V_12 ) ;
V_26 -> V_20 . type = V_181 ;
break;
}
case 0x8f :
V_82 = F_71 ( V_2 ) ;
break;
case 0x90 ... 0x97 :
if ( V_26 -> V_20 . V_63 . V_27 == & V_26 -> V_93 [ V_199 ] )
break;
goto V_432;
case 0x98 :
switch ( V_26 -> V_97 ) {
case 2 : V_26 -> V_20 . V_107 = ( V_139 ) V_26 -> V_20 . V_107 ; break;
case 4 : V_26 -> V_20 . V_107 = ( V_146 ) V_26 -> V_20 . V_107 ; break;
case 8 : V_26 -> V_20 . V_107 = ( V_140 ) V_26 -> V_20 . V_107 ; break;
}
break;
case 0xa8 ... 0xa9 :
goto V_431;
case 0xc0 ... 0xc1 :
V_82 = F_72 ( V_2 ) ;
break;
case 0xc3 :
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_63 . V_27 = & V_26 -> V_23 ;
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
V_82 = F_58 ( V_2 ) ;
break;
case 0xc4 :
V_82 = F_82 ( V_2 , V_24 , V_257 ) ;
break;
case 0xc5 :
V_82 = F_82 ( V_2 , V_24 , V_129 ) ;
break;
case 0xcb :
V_82 = F_81 ( V_2 , V_24 ) ;
break;
case 0xcc :
V_200 = 3 ;
goto V_435;
case 0xcd :
V_200 = V_26 -> V_15 . V_107 ;
V_435:
V_82 = F_67 ( V_2 , V_24 , V_200 ) ;
break;
case 0xce :
if ( V_2 -> V_161 & V_100 ) {
V_200 = 4 ;
goto V_435;
}
break;
case 0xcf :
V_82 = F_69 ( V_2 , V_24 ) ;
break;
case 0xd0 ... 0xd1 :
V_82 = F_72 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_26 -> V_15 . V_107 = V_26 -> V_93 [ V_160 ] ;
V_82 = F_72 ( V_2 ) ;
break;
case 0xe0 ... 0xe2 :
F_5 ( V_26 , & V_26 -> V_93 [ V_160 ] , - 1 ) ;
if ( F_3 ( V_26 , V_26 -> V_93 [ V_160 ] ) != 0 &&
( V_26 -> V_114 == 0xe2 || F_31 ( V_26 -> V_114 ^ 0x5 , V_2 -> V_161 ) ) )
F_6 ( V_26 , V_26 -> V_15 . V_107 ) ;
break;
case 0xe3 :
if ( F_3 ( V_26 , V_26 -> V_93 [ V_160 ] ) == 0 )
F_6 ( V_26 , V_26 -> V_15 . V_107 ) ;
break;
case 0xe4 :
case 0xe5 :
goto V_429;
case 0xe6 :
case 0xe7 :
goto V_430;
case 0xe8 : {
long int V_29 = V_26 -> V_15 . V_107 ;
V_26 -> V_15 . V_107 = ( unsigned long ) V_26 -> V_23 ;
F_6 ( V_26 , V_29 ) ;
V_82 = F_56 ( V_2 ) ;
break;
}
case 0xe9 :
goto V_436;
case 0xea :
V_82 = F_70 ( V_2 ) ;
break;
case 0xeb :
V_436:
F_6 ( V_26 , V_26 -> V_15 . V_107 ) ;
V_26 -> V_20 . type = V_181 ;
break;
case 0xec :
case 0xed :
V_429:
if ( ! F_46 ( V_2 , V_24 , V_26 -> V_20 . V_18 , V_26 -> V_15 . V_107 ,
& V_26 -> V_20 . V_107 ) )
goto V_143;
break;
case 0xee :
case 0xef :
V_430:
V_24 -> V_437 ( V_2 , V_26 -> V_15 . V_18 , V_26 -> V_20 . V_107 ,
& V_26 -> V_15 . V_107 , 1 ) ;
V_26 -> V_20 . type = V_181 ;
break;
case 0xf4 :
V_2 -> V_24 -> V_438 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_161 ^= V_101 ;
break;
case 0xf6 ... 0xf7 :
V_82 = F_74 ( V_2 ) ;
break;
case 0xf8 :
V_2 -> V_161 &= ~ V_101 ;
break;
case 0xf9 :
V_2 -> V_161 |= V_101 ;
break;
case 0xfa :
if ( F_87 ( V_2 , V_24 ) ) {
V_82 = F_13 ( V_2 , 0 ) ;
goto V_143;
} else
V_2 -> V_161 &= ~ V_439 ;
break;
case 0xfb :
if ( F_87 ( V_2 , V_24 ) ) {
V_82 = F_13 ( V_2 , 0 ) ;
goto V_143;
} else {
V_2 -> V_433 = V_440 ;
V_2 -> V_161 |= V_439 ;
}
break;
case 0xfc :
V_2 -> V_161 &= ~ V_162 ;
break;
case 0xfd :
V_2 -> V_161 |= V_162 ;
break;
case 0xfe :
V_82 = F_79 ( V_2 ) ;
break;
case 0xff :
V_82 = F_79 ( V_2 ) ;
break;
default:
goto V_428;
}
if ( V_82 != V_79 )
goto V_143;
F_55:
V_82 = F_55 ( V_2 ) ;
if ( V_82 != V_79 )
goto V_143;
V_26 -> V_20 . type = V_412 ;
if ( ( V_26 -> V_77 & V_376 ) == V_390 )
F_98 ( V_2 , V_36 ( V_2 , V_26 ) ,
V_136 , & V_26 -> V_15 ) ;
if ( ( V_26 -> V_77 & V_400 ) == V_407 )
F_98 ( V_2 , V_257 , V_138 ,
& V_26 -> V_20 ) ;
if ( V_26 -> V_9 && ( V_26 -> V_77 & String ) ) {
struct V_147 * V_241 = & V_2 -> V_10 . V_157 ;
F_5 ( V_26 , & V_26 -> V_93 [ V_160 ] , - 1 ) ;
if ( ! F_141 ( V_2 ) ) {
if ( ( V_241 -> V_88 != 0 || V_26 -> V_93 [ V_160 ] & 0x3ff ) &&
( V_241 -> V_88 == 0 || V_241 -> V_88 != V_241 -> V_151 ) ) {
V_2 -> V_10 . V_149 . V_88 = 0 ;
return V_441 ;
}
goto V_143;
}
}
V_2 -> V_23 = V_26 -> V_23 ;
V_143:
if ( V_82 == V_48 )
V_2 -> V_442 = true ;
if ( V_82 == V_443 )
return V_444 ;
return ( V_82 == V_92 ) ? V_293 : V_294 ;
V_427:
switch ( V_26 -> V_114 ) {
case 0x05 :
V_82 = F_84 ( V_2 , V_24 ) ;
break;
case 0x06 :
V_82 = F_118 ( V_2 ) ;
break;
case 0x09 :
( V_2 -> V_24 -> V_445 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_26 -> V_20 . V_107 = V_24 -> V_269 ( V_2 , V_26 -> V_12 ) ;
break;
case 0x21 :
V_24 -> V_331 ( V_2 , V_26 -> V_12 , & V_26 -> V_20 . V_107 ) ;
break;
case 0x22 :
if ( V_24 -> V_281 ( V_2 , V_26 -> V_12 , V_26 -> V_15 . V_107 ) ) {
F_13 ( V_2 , 0 ) ;
V_82 = V_48 ;
goto V_143;
}
V_26 -> V_20 . type = V_181 ;
break;
case 0x23 :
if ( V_24 -> V_446 ( V_2 , V_26 -> V_12 , V_26 -> V_15 . V_107 &
( ( V_2 -> V_38 == V_39 ) ?
~ 0ULL : ~ 0U ) ) < 0 ) {
F_13 ( V_2 , 0 ) ;
V_82 = V_48 ;
goto V_143;
}
V_26 -> V_20 . type = V_181 ;
break;
case 0x30 :
V_223 = ( T_1 ) V_26 -> V_93 [ V_199 ]
| ( ( V_108 ) V_26 -> V_93 [ V_216 ] << 32 ) ;
if ( V_24 -> V_447 ( V_2 , V_26 -> V_93 [ V_160 ] , V_223 ) ) {
F_13 ( V_2 , 0 ) ;
V_82 = V_48 ;
goto V_143;
}
V_82 = V_79 ;
break;
case 0x32 :
if ( V_24 -> V_227 ( V_2 , V_26 -> V_93 [ V_160 ] , & V_223 ) ) {
F_13 ( V_2 , 0 ) ;
V_82 = V_48 ;
goto V_143;
} else {
V_26 -> V_93 [ V_199 ] = ( T_1 ) V_223 ;
V_26 -> V_93 [ V_216 ] = V_223 >> 32 ;
}
V_82 = V_79 ;
break;
case 0x34 :
V_82 = F_85 ( V_2 , V_24 ) ;
break;
case 0x35 :
V_82 = F_86 ( V_2 , V_24 ) ;
break;
case 0x40 ... 0x4f :
V_26 -> V_20 . V_107 = V_26 -> V_20 . V_121 = V_26 -> V_15 . V_107 ;
if ( ! F_31 ( V_26 -> V_114 , V_2 -> V_161 ) )
V_26 -> V_20 . type = V_181 ;
break;
case 0x80 ... 0x8f :
if ( F_31 ( V_26 -> V_114 , V_2 -> V_161 ) )
F_6 ( V_26 , V_26 -> V_15 . V_107 ) ;
break;
case 0x90 ... 0x9f :
V_26 -> V_20 . V_107 = F_31 ( V_26 -> V_114 , V_2 -> V_161 ) ;
break;
case 0xa0 :
V_82 = F_61 ( V_2 , V_24 , V_40 ) ;
break;
case 0xa1 :
V_82 = F_62 ( V_2 , V_24 , V_40 ) ;
break;
case 0xa3 :
V_448:
V_26 -> V_20 . type = V_181 ;
V_26 -> V_15 . V_107 &= ( V_26 -> V_20 . V_18 << 3 ) - 1 ;
F_111 ( L_24 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xa4 :
case 0xa5 :
F_144 ( L_25 , V_26 -> V_305 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xa8 :
V_82 = F_61 ( V_2 , V_24 , V_174 ) ;
break;
case 0xa9 :
V_82 = F_62 ( V_2 , V_24 , V_174 ) ;
break;
case 0xab :
V_449:
F_111 ( L_26 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xac :
case 0xad :
F_144 ( L_27 , V_26 -> V_305 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xae :
break;
case 0xb0 ... 0xb1 :
V_26 -> V_15 . V_121 = V_26 -> V_15 . V_107 ;
V_26 -> V_15 . V_107 = V_26 -> V_93 [ V_199 ] ;
F_75 ( L_23 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
if ( V_2 -> V_161 & V_102 ) {
V_26 -> V_20 . V_107 = V_26 -> V_15 . V_121 ;
} else {
V_26 -> V_20 . type = V_119 ;
V_26 -> V_20 . V_63 . V_27 = ( unsigned long * ) & V_26 -> V_93 [ V_199 ] ;
}
break;
case 0xb2 :
V_82 = F_82 ( V_2 , V_24 , V_80 ) ;
break;
case 0xb3 :
V_450:
F_111 ( L_28 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xb4 :
V_82 = F_82 ( V_2 , V_24 , V_40 ) ;
break;
case 0xb5 :
V_82 = F_82 ( V_2 , V_24 , V_174 ) ;
break;
case 0xb6 ... 0xb7 :
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
V_26 -> V_20 . V_107 = ( V_26 -> V_77 & V_120 ) ? ( T_4 ) V_26 -> V_15 . V_107
: ( T_2 ) V_26 -> V_15 . V_107 ;
break;
case 0xba :
switch ( V_26 -> V_12 & 3 ) {
case 0 :
goto V_448;
case 1 :
goto V_449;
case 2 :
goto V_450;
case 3 :
goto V_451;
}
break;
case 0xbb :
V_451:
F_111 ( L_29 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
break;
case 0xbc : {
T_4 V_452 ;
__asm__ ("bsf %2, %0; setz %1"
: "=r"(c->dst.val), "=q"(zf)
: "r"(c->src.val));
V_2 -> V_161 &= ~ V_453 ;
if ( V_452 ) {
V_2 -> V_161 |= V_453 ;
V_26 -> V_20 . type = V_181 ;
}
break;
}
case 0xbd : {
T_4 V_452 ;
__asm__ ("bsr %2, %0; setz %1"
: "=r"(c->dst.val), "=q"(zf)
: "r"(c->src.val));
V_2 -> V_161 &= ~ V_453 ;
if ( V_452 ) {
V_2 -> V_161 |= V_453 ;
V_26 -> V_20 . type = V_181 ;
}
break;
}
case 0xbe ... 0xbf :
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
V_26 -> V_20 . V_107 = ( V_26 -> V_77 & V_120 ) ? ( V_139 ) V_26 -> V_15 . V_107 :
( V_146 ) V_26 -> V_15 . V_107 ;
break;
case 0xc0 ... 0xc1 :
F_75 ( L_17 , V_26 -> V_15 , V_26 -> V_20 , V_2 -> V_161 ) ;
V_26 -> V_15 . V_107 = V_26 -> V_20 . V_121 ;
F_54 ( & V_26 -> V_15 ) ;
break;
case 0xc3 :
V_26 -> V_20 . V_18 = V_26 -> V_97 ;
V_26 -> V_20 . V_107 = ( V_26 -> V_97 == 4 ) ? ( T_1 ) V_26 -> V_15 . V_107 :
( V_108 ) V_26 -> V_15 . V_107 ;
break;
case 0xc7 :
V_82 = F_80 ( V_2 ) ;
break;
default:
goto V_428;
}
if ( V_82 != V_79 )
goto V_143;
goto F_55;
V_428:
return V_293 ;
}
