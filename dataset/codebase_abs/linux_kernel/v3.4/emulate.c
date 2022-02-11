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
static int F_21 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
unsigned V_61 , bool V_62 , bool V_63 ,
T_3 * V_64 )
{
struct V_28 V_29 ;
bool V_65 ;
T_3 V_66 ;
T_1 V_67 ;
T_2 V_68 ;
unsigned V_69 , V_70 ;
V_66 = F_10 ( V_2 , V_60 . V_32 ) + V_60 . V_71 ;
switch ( V_2 -> V_35 ) {
case V_72 :
break;
case V_36 :
if ( ( ( signed long ) V_66 << 16 ) >> 16 != V_66 )
return F_13 ( V_2 , 0 ) ;
break;
default:
V_65 = V_2 -> V_23 -> V_55 ( V_2 , & V_68 , & V_29 , NULL ,
V_60 . V_32 ) ;
if ( ! V_65 )
goto V_73;
if ( ( ( V_29 . type & 8 ) || ! ( V_29 . type & 2 ) ) && V_62 )
goto V_73;
if ( ! V_63 && ( V_29 . type & 8 ) && ! ( V_29 . type & 2 ) )
goto V_73;
V_67 = F_7 ( & V_29 ) ;
if ( ( V_29 . type & 8 ) || ! ( V_29 . type & 4 ) ) {
if ( V_60 . V_71 > V_67 || ( T_1 ) ( V_60 . V_71 + V_61 - 1 ) > V_67 )
goto V_73;
} else {
if ( V_60 . V_71 <= V_67 || ( T_1 ) ( V_60 . V_71 + V_61 - 1 ) <= V_67 )
goto V_73;
V_67 = V_29 . V_74 ? 0xffffffff : 0xffff ;
if ( V_60 . V_71 > V_67 || ( T_1 ) ( V_60 . V_71 + V_61 - 1 ) > V_67 )
goto V_73;
}
V_69 = V_2 -> V_23 -> V_69 ( V_2 ) ;
V_70 = V_68 & 3 ;
V_69 = F_22 ( V_69 , V_70 ) ;
if ( ! ( V_29 . type & 8 ) ) {
if ( V_69 > V_29 . V_75 )
goto V_73;
} else if ( ( V_29 . type & 8 ) && ! ( V_29 . type & 4 ) ) {
if ( V_69 != V_29 . V_75 )
goto V_73;
} else if ( ( V_29 . type & 8 ) && ( V_29 . type & 4 ) ) {
if ( V_69 < V_29 . V_75 )
goto V_73;
}
break;
}
if ( V_63 ? V_2 -> V_35 != V_36 : V_2 -> V_20 != 8 )
V_66 &= ( T_1 ) - 1 ;
* V_64 = V_66 ;
return V_76 ;
V_73:
if ( V_60 . V_32 == V_77 )
return F_14 ( V_2 , V_60 . V_32 ) ;
else
return F_13 ( V_2 , V_60 . V_32 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
unsigned V_61 , bool V_62 ,
T_3 * V_64 )
{
return F_21 ( V_2 , V_60 , V_61 , V_62 , false , V_64 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , false , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return V_2 -> V_23 -> V_80 ( V_2 , V_64 , V_78 , V_61 , & V_2 -> V_41 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_4 * V_81 )
{
struct V_82 * V_83 = & V_2 -> V_63 ;
int V_79 ;
int V_61 , V_84 ;
if ( V_2 -> V_27 == V_83 -> V_85 ) {
unsigned long V_64 ;
struct V_59 V_60 = { . V_32 = V_86 ,
. V_71 = V_2 -> V_27 } ;
V_84 = V_83 -> V_85 - V_83 -> V_87 ;
V_61 = F_26 ( 15UL - V_84 ,
V_88 - F_27 ( V_2 -> V_27 ) ) ;
V_79 = F_21 ( V_2 , V_60 , V_61 , false , true , & V_64 ) ;
if ( F_28 ( V_79 != V_76 ) )
return V_79 ;
V_79 = V_2 -> V_23 -> V_63 ( V_2 , V_64 , V_83 -> V_78 + V_84 ,
V_61 , & V_2 -> V_41 ) ;
if ( F_28 ( V_79 != V_76 ) )
return V_79 ;
V_83 -> V_85 += V_61 ;
}
* V_81 = V_83 -> V_78 [ V_2 -> V_27 - V_83 -> V_87 ] ;
V_2 -> V_27 ++ ;
return V_76 ;
}
static int F_29 ( struct V_1 * V_2 ,
void * V_81 , unsigned V_61 )
{
int V_79 ;
if ( F_28 ( V_2 -> V_27 + V_61 - V_2 -> V_22 > 15 ) )
return V_89 ;
while ( V_61 -- ) {
V_79 = F_25 ( V_2 , V_81 ++ ) ;
if ( V_79 != V_76 )
return V_79 ;
}
return V_76 ;
}
static void * F_30 ( T_4 V_11 , unsigned long * V_90 ,
int V_91 )
{
void * V_92 ;
V_92 = & V_90 [ V_11 ] ;
if ( V_91 && V_11 >= 4 && V_11 < 8 )
V_92 = ( unsigned char * ) & V_90 [ V_11 & 3 ] + 1 ;
return V_92 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
T_2 * V_61 , unsigned long * V_93 , int V_94 )
{
int V_79 ;
if ( V_94 == 2 )
V_94 = 3 ;
* V_93 = 0 ;
V_79 = F_24 ( V_2 , V_60 , V_61 , 2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_60 . V_71 += 2 ;
V_79 = F_24 ( V_2 , V_60 , V_93 , V_94 ) ;
return V_79 ;
}
static int F_32 ( unsigned int V_95 , unsigned int V_96 )
{
int V_79 = 0 ;
switch ( ( V_95 & 15 ) >> 1 ) {
case 0 :
V_79 |= ( V_96 & V_97 ) ;
break;
case 1 :
V_79 |= ( V_96 & V_98 ) ;
break;
case 2 :
V_79 |= ( V_96 & V_99 ) ;
break;
case 3 :
V_79 |= ( V_96 & ( V_98 | V_99 ) ) ;
break;
case 4 :
V_79 |= ( V_96 & V_100 ) ;
break;
case 5 :
V_79 |= ( V_96 & V_101 ) ;
break;
case 7 :
V_79 |= ( V_96 & V_99 ) ;
case 6 :
V_79 |= ( ! ( V_96 & V_100 ) != ! ( V_96 & V_97 ) ) ;
break;
}
return ( ! ! V_79 ^ ( V_95 & 1 ) ) ;
}
static void F_33 ( struct V_102 * V_103 )
{
switch ( V_103 -> V_17 ) {
case 1 :
V_103 -> V_104 = * ( T_4 * ) V_103 -> V_60 . V_24 ;
break;
case 2 :
V_103 -> V_104 = * ( T_2 * ) V_103 -> V_60 . V_24 ;
break;
case 4 :
V_103 -> V_104 = * ( T_1 * ) V_103 -> V_60 . V_24 ;
break;
case 8 :
V_103 -> V_104 = * ( V_105 * ) V_103 -> V_60 . V_24 ;
break;
}
}
static void F_34 ( struct V_1 * V_2 , T_5 * V_78 , int V_24 )
{
V_2 -> V_23 -> V_106 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movdqu %%xmm0, %0" : "=m"(*data)); break;
case 1 : asm("movdqu %%xmm1, %0" : "=m"(*data)); break;
case 2 : asm("movdqu %%xmm2, %0" : "=m"(*data)); break;
case 3 : asm("movdqu %%xmm3, %0" : "=m"(*data)); break;
case 4 : asm("movdqu %%xmm4, %0" : "=m"(*data)); break;
case 5 : asm("movdqu %%xmm5, %0" : "=m"(*data)); break;
case 6 : asm("movdqu %%xmm6, %0" : "=m"(*data)); break;
case 7 : asm("movdqu %%xmm7, %0" : "=m"(*data)); break;
#ifdef F_35
case 8 : asm("movdqu %%xmm8, %0" : "=m"(*data)); break;
case 9 : asm("movdqu %%xmm9, %0" : "=m"(*data)); break;
case 10 : asm("movdqu %%xmm10, %0" : "=m"(*data)); break;
case 11 : asm("movdqu %%xmm11, %0" : "=m"(*data)); break;
case 12 : asm("movdqu %%xmm12, %0" : "=m"(*data)); break;
case 13 : asm("movdqu %%xmm13, %0" : "=m"(*data)); break;
case 14 : asm("movdqu %%xmm14, %0" : "=m"(*data)); break;
case 15 : asm("movdqu %%xmm15, %0" : "=m"(*data)); break;
#endif
default: F_36 () ;
}
V_2 -> V_23 -> V_107 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_5 * V_78 ,
int V_24 )
{
V_2 -> V_23 -> V_106 ( V_2 ) ;
switch ( V_24 ) {
case 0 : asm("movdqu %0, %%xmm0" : : "m"(*data)); break;
case 1 : asm("movdqu %0, %%xmm1" : : "m"(*data)); break;
case 2 : asm("movdqu %0, %%xmm2" : : "m"(*data)); break;
case 3 : asm("movdqu %0, %%xmm3" : : "m"(*data)); break;
case 4 : asm("movdqu %0, %%xmm4" : : "m"(*data)); break;
case 5 : asm("movdqu %0, %%xmm5" : : "m"(*data)); break;
case 6 : asm("movdqu %0, %%xmm6" : : "m"(*data)); break;
case 7 : asm("movdqu %0, %%xmm7" : : "m"(*data)); break;
#ifdef F_35
case 8 : asm("movdqu %0, %%xmm8" : : "m"(*data)); break;
case 9 : asm("movdqu %0, %%xmm9" : : "m"(*data)); break;
case 10 : asm("movdqu %0, %%xmm10" : : "m"(*data)); break;
case 11 : asm("movdqu %0, %%xmm11" : : "m"(*data)); break;
case 12 : asm("movdqu %0, %%xmm12" : : "m"(*data)); break;
case 13 : asm("movdqu %0, %%xmm13" : : "m"(*data)); break;
case 14 : asm("movdqu %0, %%xmm14" : : "m"(*data)); break;
case 15 : asm("movdqu %0, %%xmm15" : : "m"(*data)); break;
#endif
default: F_36 () ;
}
V_2 -> V_23 -> V_107 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
unsigned V_24 = V_2 -> V_11 ;
int V_91 = V_2 -> V_108 == 0 ;
if ( ! ( V_2 -> V_74 & V_109 ) )
V_24 = ( V_2 -> V_110 & 7 ) | ( ( V_2 -> V_108 & 1 ) << 3 ) ;
if ( V_2 -> V_74 & V_111 ) {
V_103 -> type = V_112 ;
V_103 -> V_17 = 16 ;
V_103 -> V_60 . V_113 = V_24 ;
F_34 ( V_2 , & V_103 -> V_114 , V_24 ) ;
return;
}
V_103 -> type = V_115 ;
if ( V_2 -> V_74 & V_116 ) {
V_103 -> V_60 . V_24 = F_30 ( V_24 , V_2 -> V_90 , V_91 ) ;
V_103 -> V_17 = 1 ;
} else {
V_103 -> V_60 . V_24 = F_30 ( V_24 , V_2 -> V_90 , 0 ) ;
V_103 -> V_17 = V_2 -> V_94 ;
}
F_33 ( V_103 ) ;
V_103 -> V_117 = V_103 -> V_104 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
T_4 V_118 ;
int V_119 = 0 , V_120 = 0 , V_121 ;
int V_79 = V_76 ;
T_3 V_122 = 0 ;
if ( V_2 -> V_108 ) {
V_2 -> V_11 = ( V_2 -> V_108 & 4 ) << 1 ;
V_119 = ( V_2 -> V_108 & 2 ) << 2 ;
V_2 -> V_12 = V_120 = ( V_2 -> V_108 & 1 ) << 3 ;
}
V_2 -> V_123 = F_40 ( T_4 , V_2 ) ;
V_2 -> V_10 |= ( V_2 -> V_123 & 0xc0 ) >> 6 ;
V_2 -> V_11 |= ( V_2 -> V_123 & 0x38 ) >> 3 ;
V_2 -> V_12 |= ( V_2 -> V_123 & 0x07 ) ;
V_2 -> V_124 = V_125 ;
if ( V_2 -> V_10 == 3 ) {
V_103 -> type = V_115 ;
V_103 -> V_17 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
V_103 -> V_60 . V_24 = F_30 ( V_2 -> V_12 ,
V_2 -> V_90 , V_2 -> V_74 & V_116 ) ;
if ( V_2 -> V_74 & V_111 ) {
V_103 -> type = V_112 ;
V_103 -> V_17 = 16 ;
V_103 -> V_60 . V_113 = V_2 -> V_12 ;
F_34 ( V_2 , & V_103 -> V_114 , V_2 -> V_12 ) ;
return V_79 ;
}
F_33 ( V_103 ) ;
return V_79 ;
}
V_103 -> type = V_126 ;
if ( V_2 -> V_20 == 2 ) {
unsigned V_127 = V_2 -> V_90 [ V_128 ] ;
unsigned V_129 = V_2 -> V_90 [ V_130 ] ;
unsigned V_131 = V_2 -> V_90 [ V_132 ] ;
unsigned V_133 = V_2 -> V_90 [ V_134 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 6 )
V_122 += F_40 ( T_2 , V_2 ) ;
break;
case 1 :
V_122 += F_40 ( V_135 , V_2 ) ;
break;
case 2 :
V_122 += F_40 ( T_2 , V_2 ) ;
break;
}
switch ( V_2 -> V_12 ) {
case 0 :
V_122 += V_127 + V_131 ;
break;
case 1 :
V_122 += V_127 + V_133 ;
break;
case 2 :
V_122 += V_129 + V_131 ;
break;
case 3 :
V_122 += V_129 + V_133 ;
break;
case 4 :
V_122 += V_131 ;
break;
case 5 :
V_122 += V_133 ;
break;
case 6 :
if ( V_2 -> V_10 != 0 )
V_122 += V_129 ;
break;
case 7 :
V_122 += V_127 ;
break;
}
if ( V_2 -> V_12 == 2 || V_2 -> V_12 == 3 ||
( V_2 -> V_12 == 6 && V_2 -> V_10 != 0 ) )
V_2 -> V_124 = V_77 ;
V_122 = ( T_2 ) V_122 ;
} else {
if ( ( V_2 -> V_12 & 7 ) == 4 ) {
V_118 = F_40 ( T_4 , V_2 ) ;
V_119 |= ( V_118 >> 3 ) & 7 ;
V_120 |= V_118 & 7 ;
V_121 = V_118 >> 6 ;
if ( ( V_120 & 7 ) == 5 && V_2 -> V_10 == 0 )
V_122 += F_40 ( V_136 , V_2 ) ;
else
V_122 += V_2 -> V_90 [ V_120 ] ;
if ( V_119 != 4 )
V_122 += V_2 -> V_90 [ V_119 ] << V_121 ;
} else if ( ( V_2 -> V_12 & 7 ) == 5 && V_2 -> V_10 == 0 ) {
if ( V_2 -> V_35 == V_36 )
V_2 -> V_137 = 1 ;
} else
V_122 += V_2 -> V_90 [ V_2 -> V_12 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 5 )
V_122 += F_40 ( V_136 , V_2 ) ;
break;
case 1 :
V_122 += F_40 ( V_135 , V_2 ) ;
break;
case 2 :
V_122 += F_40 ( V_136 , V_2 ) ;
break;
}
}
V_103 -> V_60 . V_138 . V_71 = V_122 ;
V_139:
return V_79 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_79 = V_76 ;
V_103 -> type = V_126 ;
switch ( V_2 -> V_20 ) {
case 2 :
V_103 -> V_60 . V_138 . V_71 = F_40 ( T_2 , V_2 ) ;
break;
case 4 :
V_103 -> V_60 . V_138 . V_71 = F_40 ( T_1 , V_2 ) ;
break;
case 8 :
V_103 -> V_60 . V_138 . V_71 = F_40 ( V_105 , V_2 ) ;
break;
}
V_139:
return V_79 ;
}
static void F_42 ( struct V_1 * V_2 )
{
long V_140 = 0 , V_141 ;
if ( V_2 -> V_19 . type == V_126 && V_2 -> V_14 . type == V_115 ) {
V_141 = ~ ( V_2 -> V_19 . V_17 * 8 - 1 ) ;
if ( V_2 -> V_14 . V_17 == 2 )
V_140 = ( V_142 ) V_2 -> V_14 . V_104 & ( V_142 ) V_141 ;
else if ( V_2 -> V_14 . V_17 == 4 )
V_140 = ( V_136 ) V_2 -> V_14 . V_104 & ( V_136 ) V_141 ;
V_2 -> V_19 . V_60 . V_138 . V_71 += ( V_140 >> 3 ) ;
}
V_2 -> V_14 . V_104 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned long V_60 , void * V_81 , unsigned V_61 )
{
int V_79 ;
struct V_143 * V_144 = & V_2 -> V_145 ;
while ( V_61 ) {
int V_146 = F_26 ( V_61 , 8u ) ;
V_61 -= V_146 ;
if ( V_144 -> V_147 < V_144 -> V_85 )
goto V_148;
V_79 = V_2 -> V_23 -> F_43 ( V_2 , V_60 , V_144 -> V_78 + V_144 -> V_85 , V_146 ,
& V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_144 -> V_85 += V_146 ;
V_148:
memcpy ( V_81 , V_144 -> V_78 + V_144 -> V_147 , V_146 ) ;
V_144 -> V_147 += V_146 ;
V_81 += V_146 ;
V_60 += V_146 ;
}
return V_76 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , false , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return F_43 ( V_2 , V_64 , V_78 , V_61 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
const void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , true , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return V_2 -> V_23 -> V_149 ( V_2 , V_64 , V_78 , V_61 ,
& V_2 -> V_41 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
const void * V_150 , const void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , true , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return V_2 -> V_23 -> V_151 ( V_2 , V_64 , V_150 , V_78 ,
V_61 , & V_2 -> V_41 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned int V_61 , unsigned short V_152 ,
void * V_81 )
{
struct V_143 * V_79 = & V_2 -> V_153 ;
if ( V_79 -> V_147 == V_79 -> V_85 ) {
unsigned int V_154 , V_146 ;
unsigned int V_155 = V_2 -> V_9 ?
F_3 ( V_2 , V_2 -> V_90 [ V_156 ] ) : 1 ;
V_154 = ( V_2 -> V_157 & V_158 ) ?
F_27 ( V_2 -> V_90 [ V_134 ] ) :
V_88 - F_27 ( V_2 -> V_90 [ V_134 ] ) ;
V_146 = F_26 ( F_26 ( V_154 , ( unsigned int ) sizeof( V_79 -> V_78 ) ) / V_61 ,
V_155 ) ;
if ( V_146 == 0 )
V_146 = 1 ;
V_79 -> V_147 = V_79 -> V_85 = 0 ;
if ( ! V_2 -> V_23 -> F_47 ( V_2 , V_61 , V_152 , V_79 -> V_78 , V_146 ) )
return 0 ;
V_79 -> V_85 = V_146 * V_61 ;
}
memcpy ( V_81 , V_79 -> V_78 + V_79 -> V_147 , V_61 ) ;
V_79 -> V_147 += V_61 ;
return 1 ;
}
static int F_48 ( struct V_1 * V_2 ,
T_2 V_159 , struct V_28 * V_29 )
{
struct V_160 V_161 ;
T_3 V_60 ;
V_2 -> V_23 -> V_162 ( V_2 , & V_161 ) ;
if ( V_161 . V_61 < V_159 * 8 + 7 )
return F_13 ( V_2 , V_159 << 3 | 0x2 ) ;
V_60 = V_161 . V_93 + V_159 * 8 ;
return V_2 -> V_23 -> V_80 ( V_2 , V_60 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_160 * V_161 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
if ( V_54 & 1 << 2 ) {
struct V_28 V_29 ;
T_2 V_68 ;
memset ( V_161 , 0 , sizeof *V_161 ) ;
if ( ! V_23 -> V_55 ( V_2 , & V_68 , & V_29 , NULL , V_164 ) )
return;
V_161 -> V_61 = F_7 ( & V_29 ) ;
V_161 -> V_93 = F_50 ( & V_29 ) ;
} else
V_23 -> V_165 ( V_2 , V_161 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_160 V_161 ;
T_2 V_159 = V_54 >> 3 ;
T_3 V_60 ;
F_49 ( V_2 , V_54 , & V_161 ) ;
if ( V_161 . V_61 < V_159 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_60 = V_161 . V_93 + V_159 * 8 ;
return V_2 -> V_23 -> V_80 ( V_2 , V_60 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_160 V_161 ;
T_2 V_159 = V_54 >> 3 ;
T_3 V_60 ;
F_49 ( V_2 , V_54 , & V_161 ) ;
if ( V_161 . V_61 < V_159 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_60 = V_161 . V_93 + V_159 * 8 ;
return V_2 -> V_23 -> V_166 ( V_2 , V_60 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
T_2 V_54 , int V_32 )
{
struct V_28 V_167 ;
T_4 V_75 , V_70 , V_69 ;
unsigned V_168 = V_48 ;
T_1 V_169 = 0 ;
bool V_170 = ! ( V_54 & ~ 0x3 ) ;
int V_171 ;
memset ( & V_167 , 0 , sizeof V_167 ) ;
if ( ( V_32 <= V_172 && V_2 -> V_35 == V_173 )
|| V_2 -> V_35 == V_72 ) {
F_54 ( & V_167 , V_54 << 4 ) ;
F_55 ( & V_167 , 0xffff ) ;
V_167 . type = 3 ;
V_167 . V_92 = 1 ;
V_167 . V_174 = 1 ;
if ( V_2 -> V_35 == V_173 )
V_167 . V_75 = 3 ;
goto V_175;
}
if ( ( V_32 == V_86 || V_32 == V_77 || V_32 == V_176 )
&& V_170 )
goto V_41;
if ( V_32 == V_176 && ( V_54 & ( 1 << 2 ) ) )
goto V_41;
if ( V_170 )
goto V_175;
V_171 = F_51 ( V_2 , V_54 , & V_167 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_169 = V_54 & 0xfffc ;
V_168 = V_48 ;
if ( V_32 <= V_172 && ! V_167 . V_174 )
goto V_41;
if ( ! V_167 . V_92 ) {
V_168 = ( V_32 == V_77 ) ? V_49 : V_177 ;
goto V_41;
}
V_70 = V_54 & 3 ;
V_75 = V_167 . V_75 ;
V_69 = V_2 -> V_23 -> V_69 ( V_2 ) ;
switch ( V_32 ) {
case V_77 :
if ( V_70 != V_69 || ( V_167 . type & 0xa ) != 0x2 || V_75 != V_69 )
goto V_41;
break;
case V_86 :
if ( ! ( V_167 . type & 8 ) )
goto V_41;
if ( V_167 . type & 4 ) {
if ( V_75 > V_69 )
goto V_41;
} else {
if ( V_70 > V_69 || V_75 != V_69 )
goto V_41;
}
V_54 = ( V_54 & 0xfffc ) | V_69 ;
break;
case V_176 :
if ( V_167 . V_174 || ( V_167 . type != 1 && V_167 . type != 9 ) )
goto V_41;
break;
case V_164 :
if ( V_167 . V_174 || V_167 . type != 2 )
goto V_41;
break;
default:
if ( ( V_167 . type & 0xa ) == 0x8 ||
( ( ( V_167 . type & 0xc ) != 0xc ) &&
( V_70 > V_75 && V_69 > V_75 ) ) )
goto V_41;
break;
}
if ( V_167 . V_174 ) {
V_167 . type |= 1 ;
V_171 = F_52 ( V_2 , V_54 , & V_167 ) ;
if ( V_171 != V_76 )
return V_171 ;
}
V_175:
V_2 -> V_23 -> V_58 ( V_2 , V_54 , & V_167 , 0 , V_32 ) ;
return V_76 ;
V_41:
F_11 ( V_2 , V_168 , V_169 , true ) ;
return V_45 ;
}
static void F_56 ( struct V_102 * V_103 )
{
switch ( V_103 -> V_17 ) {
case 1 :
* ( T_4 * ) V_103 -> V_60 . V_24 = ( T_4 ) V_103 -> V_104 ;
break;
case 2 :
* ( T_2 * ) V_103 -> V_60 . V_24 = ( T_2 ) V_103 -> V_104 ;
break;
case 4 :
* V_103 -> V_60 . V_24 = ( T_1 ) V_103 -> V_104 ;
break;
case 8 :
* V_103 -> V_60 . V_24 = V_103 -> V_104 ;
break;
}
}
static int F_57 ( struct V_1 * V_2 )
{
int V_79 ;
switch ( V_2 -> V_19 . type ) {
case V_115 :
F_56 ( & V_2 -> V_19 ) ;
break;
case V_126 :
if ( V_2 -> V_178 )
V_79 = F_46 ( V_2 ,
V_2 -> V_19 . V_60 . V_138 ,
& V_2 -> V_19 . V_117 ,
& V_2 -> V_19 . V_104 ,
V_2 -> V_19 . V_17 ) ;
else
V_79 = F_45 ( V_2 ,
V_2 -> V_19 . V_60 . V_138 ,
& V_2 -> V_19 . V_104 ,
V_2 -> V_19 . V_17 ) ;
if ( V_79 != V_76 )
return V_79 ;
break;
case V_112 :
F_37 ( V_2 , & V_2 -> V_19 . V_114 , V_2 -> V_19 . V_60 . V_113 ) ;
break;
case V_179 :
break;
default:
break;
}
return V_76 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_59 V_60 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , - V_2 -> V_94 ) ;
V_60 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_180 ] ) ;
V_60 . V_32 = V_77 ;
V_2 -> V_19 . type = V_179 ;
return F_45 ( V_2 , V_60 , & V_2 -> V_14 . V_104 , V_2 -> V_94 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
void * V_81 , int V_181 )
{
int V_79 ;
struct V_59 V_60 ;
V_60 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_180 ] ) ;
V_60 . V_32 = V_77 ;
V_79 = F_44 ( V_2 , V_60 , V_81 , V_181 ) ;
if ( V_79 != V_76 )
return V_79 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , V_181 ) ;
return V_79 ;
}
static int F_60 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
void * V_81 , int V_181 )
{
int V_79 ;
unsigned long V_104 , V_182 ;
int V_183 = ( V_2 -> V_157 & V_184 ) >> V_185 ;
int V_69 = V_2 -> V_23 -> V_69 ( V_2 ) ;
V_79 = F_59 ( V_2 , & V_104 , V_181 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_182 = V_98 | V_101 | V_186 | V_99 | V_100 | V_97
| V_187 | V_158 | V_188 | V_189 | V_190 | V_191 ;
switch( V_2 -> V_35 ) {
case V_36 :
case V_192 :
case V_193 :
if ( V_69 == 0 )
V_182 |= V_194 ;
if ( V_69 <= V_183 )
V_182 |= V_195 ;
break;
case V_173 :
if ( V_183 < 3 )
return F_13 ( V_2 , 0 ) ;
V_182 |= V_195 ;
break;
default:
V_182 |= ( V_194 | V_195 ) ;
break;
}
* ( unsigned long * ) V_81 =
( V_2 -> V_157 & ~ V_182 ) | ( V_104 & V_182 ) ;
return V_79 ;
}
static int F_62 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_115 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_157 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
return F_61 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_196 . V_104 ;
V_2 -> V_14 . V_104 = F_19 ( V_2 , V_32 ) ;
return F_58 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_196 . V_104 ;
unsigned long V_54 ;
int V_79 ;
V_79 = F_59 ( V_2 , & V_54 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_53 ( V_2 , ( T_2 ) V_54 , V_32 ) ;
return V_79 ;
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned long V_197 = V_2 -> V_90 [ V_180 ] ;
int V_79 = V_76 ;
int V_24 = V_198 ;
while ( V_24 <= V_134 ) {
( V_24 == V_180 ) ?
( V_2 -> V_14 . V_104 = V_197 ) : ( V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_24 ] ) ;
V_79 = F_58 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
++ V_24 ;
}
return V_79 ;
}
static int F_66 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_104 = ( unsigned long ) V_2 -> V_157 ;
return F_58 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
int V_24 = V_134 ;
while ( V_24 >= V_198 ) {
if ( V_24 == V_180 ) {
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] ,
V_2 -> V_94 ) ;
-- V_24 ;
}
V_79 = F_59 ( V_2 , & V_2 -> V_90 [ V_24 ] , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
break;
-- V_24 ;
}
return V_79 ;
}
int F_68 ( struct V_1 * V_2 , int V_199 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
int V_79 ;
struct V_160 V_161 ;
T_6 V_200 ;
T_6 V_201 ;
T_2 V_202 , V_22 ;
V_2 -> V_14 . V_104 = V_2 -> V_157 ;
V_79 = F_58 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_157 &= ~ ( V_195 | V_187 | V_190 ) ;
V_2 -> V_14 . V_104 = F_19 ( V_2 , V_86 ) ;
V_79 = F_58 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_14 . V_104 = V_2 -> V_27 ;
V_79 = F_58 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_23 -> V_162 ( V_2 , & V_161 ) ;
V_201 = V_161 . V_93 + ( V_199 << 2 ) ;
V_200 = V_161 . V_93 + ( V_199 << 2 ) + 2 ;
V_79 = V_23 -> V_80 ( V_2 , V_200 , & V_202 , 2 , & V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = V_23 -> V_80 ( V_2 , V_201 , & V_22 , 2 , & V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_53 ( V_2 , V_202 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_22 ;
return V_79 ;
}
static int F_69 ( struct V_1 * V_2 , int V_199 )
{
switch( V_2 -> V_35 ) {
case V_72 :
return F_68 ( V_2 , V_199 ) ;
case V_173 :
case V_193 :
case V_192 :
case V_36 :
default:
return V_89 ;
}
}
static int F_70 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
unsigned long V_203 = 0 ;
unsigned long V_204 = 0 ;
unsigned long V_202 = 0 ;
unsigned long V_141 = V_98 | V_101 | V_186 | V_99 | V_100 | V_187 |
V_195 | V_158 | V_97 | V_194 | V_188 | V_189 |
V_190 | V_191 | ( 1 << 1 ) ;
unsigned long V_205 = V_206 | V_207 | V_208 ;
V_79 = F_59 ( V_2 , & V_203 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
if ( V_203 & ~ 0xffff )
return F_13 ( V_2 , 0 ) ;
V_79 = F_59 ( V_2 , & V_202 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_59 ( V_2 , & V_204 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_53 ( V_2 , ( T_2 ) V_202 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_203 ;
if ( V_2 -> V_94 == 4 )
V_2 -> V_157 = ( ( V_204 & V_141 ) | ( V_2 -> V_157 & V_205 ) ) ;
else if ( V_2 -> V_94 == 2 ) {
V_2 -> V_157 &= ~ 0xffff ;
V_2 -> V_157 |= V_204 ;
}
V_2 -> V_157 &= ~ V_209 ;
V_2 -> V_157 |= V_210 ;
return V_79 ;
}
static int F_71 ( struct V_1 * V_2 )
{
switch( V_2 -> V_35 ) {
case V_72 :
return F_70 ( V_2 ) ;
case V_173 :
case V_193 :
case V_192 :
case V_36 :
default:
return V_89 ;
}
}
static int F_72 ( struct V_1 * V_2 )
{
int V_79 ;
unsigned short V_68 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
V_79 = F_53 ( V_2 , V_68 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_211 , V_2 -> V_94 ) ;
return V_76 ;
}
static int F_73 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case 0 :
F_74 ( V_2 , L_1 ) ;
break;
case 1 :
F_74 ( V_2 , L_2 ) ;
break;
case 2 :
F_74 ( V_2 , L_3 ) ;
break;
case 3 :
F_74 ( V_2 , L_4 ) ;
break;
case 4 :
case 6 :
F_74 ( V_2 , L_5 ) ;
break;
case 5 :
F_74 ( V_2 , L_6 ) ;
break;
case 7 :
F_74 ( V_2 , L_7 ) ;
break;
}
return V_76 ;
}
static int F_75 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_104 = ~ V_2 -> V_19 . V_104 ;
return V_76 ;
}
static int F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 , L_8 ) ;
return V_76 ;
}
static int F_78 ( struct V_1 * V_2 )
{
T_4 V_212 = 0 ;
F_79 ( V_2 , L_9 , V_212 ) ;
return V_76 ;
}
static int F_80 ( struct V_1 * V_2 )
{
T_4 V_212 = 0 ;
F_79 ( V_2 , L_10 , V_212 ) ;
return V_76 ;
}
static int F_81 ( struct V_1 * V_2 )
{
T_4 V_213 = 0 ;
F_79 ( V_2 , L_11 , V_213 ) ;
if ( V_213 )
return F_17 ( V_2 ) ;
return V_76 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_4 V_213 = 0 ;
F_79 ( V_2 , L_12 , V_213 ) ;
if ( V_213 )
return F_17 ( V_2 ) ;
return V_76 ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
switch ( V_2 -> V_11 ) {
case 0 :
F_77 ( V_2 , L_13 ) ;
break;
case 1 :
F_77 ( V_2 , L_14 ) ;
break;
case 2 : {
long int V_214 ;
V_214 = V_2 -> V_27 ;
V_2 -> V_27 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = V_214 ;
V_79 = F_58 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_27 = V_2 -> V_14 . V_104 ;
break;
case 5 :
V_79 = F_72 ( V_2 ) ;
break;
case 6 :
V_79 = F_58 ( V_2 ) ;
break;
}
return V_79 ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_105 V_215 = V_2 -> V_19 . V_216 ;
if ( ( ( T_1 ) ( V_215 >> 0 ) != ( T_1 ) V_2 -> V_90 [ V_198 ] ) ||
( ( T_1 ) ( V_215 >> 32 ) != ( T_1 ) V_2 -> V_90 [ V_217 ] ) ) {
V_2 -> V_90 [ V_198 ] = ( T_1 ) ( V_215 >> 0 ) ;
V_2 -> V_90 [ V_217 ] = ( T_1 ) ( V_215 >> 32 ) ;
V_2 -> V_157 &= ~ V_99 ;
} else {
V_2 -> V_19 . V_15 = ( ( V_105 ) V_2 -> V_90 [ V_156 ] << 32 ) |
( T_1 ) V_2 -> V_90 [ V_128 ] ;
V_2 -> V_157 |= V_99 ;
}
return V_76 ;
}
static int F_85 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_115 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
return F_60 ( V_2 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_79 ;
unsigned long V_202 ;
V_79 = F_59 ( V_2 , & V_2 -> V_27 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
if ( V_2 -> V_94 == 4 )
V_2 -> V_27 = ( T_1 ) V_2 -> V_27 ;
V_79 = F_59 ( V_2 , & V_202 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_53 ( V_2 , ( T_2 ) V_202 , V_86 ) ;
return V_79 ;
}
static int F_87 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_117 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_198 ] ;
F_88 ( V_2 , L_15 ) ;
if ( V_2 -> V_157 & V_99 ) {
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_117 ;
} else {
V_2 -> V_19 . type = V_115 ;
V_2 -> V_19 . V_60 . V_24 = ( unsigned long * ) & V_2 -> V_90 [ V_198 ] ;
}
return V_76 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_32 = V_2 -> V_196 . V_104 ;
unsigned short V_68 ;
int V_79 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
V_79 = F_53 ( V_2 , V_68 , V_32 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_104 ;
return V_79 ;
}
static void
F_90 ( struct V_1 * V_2 ,
struct V_28 * V_202 , struct V_28 * V_218 )
{
T_2 V_54 ;
memset ( V_202 , 0 , sizeof( struct V_28 ) ) ;
V_2 -> V_23 -> V_55 ( V_2 , & V_54 , V_202 , NULL , V_86 ) ;
memset ( V_218 , 0 , sizeof( struct V_28 ) ) ;
V_202 -> V_219 = 0 ;
F_54 ( V_202 , 0 ) ;
V_202 -> V_31 = 1 ;
F_55 ( V_202 , 0xfffff ) ;
V_202 -> type = 0x0b ;
V_202 -> V_174 = 1 ;
V_202 -> V_75 = 0 ;
V_202 -> V_92 = 1 ;
V_202 -> V_74 = 1 ;
F_54 ( V_218 , 0 ) ;
F_55 ( V_218 , 0xfffff ) ;
V_218 -> V_31 = 1 ;
V_218 -> V_174 = 1 ;
V_218 -> type = 0x03 ;
V_218 -> V_74 = 1 ;
V_218 -> V_75 = 0 ;
V_218 -> V_92 = 1 ;
}
static bool F_91 ( struct V_1 * V_2 )
{
T_1 V_220 , V_221 , V_222 , V_223 ;
V_220 = V_222 = 0 ;
return V_2 -> V_23 -> V_224 ( V_2 , & V_220 , & V_221 , & V_222 , & V_223 )
&& V_221 == V_225
&& V_222 == V_226
&& V_223 == V_227 ;
}
static bool F_92 ( struct V_1 * V_2 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
T_1 V_220 , V_221 , V_222 , V_223 ;
if ( V_2 -> V_35 == V_36 )
return true ;
V_220 = 0x00000000 ;
V_222 = 0x00000000 ;
if ( V_23 -> V_224 ( V_2 , & V_220 , & V_221 , & V_222 , & V_223 ) ) {
if ( V_221 == V_225 &&
V_222 == V_226 &&
V_223 == V_227 )
return false ;
if ( V_221 == V_228 &&
V_222 == V_229 &&
V_223 == V_230 )
return true ;
if ( V_221 == V_231 &&
V_222 == V_232 &&
V_223 == V_233 )
return true ;
}
return false ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_28 V_202 , V_218 ;
V_105 V_234 ;
T_2 V_235 , V_236 ;
V_105 V_237 = 0 ;
if ( V_2 -> V_35 == V_72 ||
V_2 -> V_35 == V_173 )
return F_15 ( V_2 ) ;
if ( ! ( F_92 ( V_2 ) ) )
return F_15 ( V_2 ) ;
V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
F_90 ( V_2 , & V_202 , & V_218 ) ;
if ( ! ( V_237 & V_240 ) )
return F_15 ( V_2 ) ;
V_23 -> V_238 ( V_2 , V_241 , & V_234 ) ;
V_234 >>= 32 ;
V_235 = ( T_2 ) ( V_234 & 0xfffc ) ;
V_236 = ( T_2 ) ( V_234 + 8 ) ;
if ( V_237 & V_242 ) {
V_202 . V_74 = 0 ;
V_202 . V_219 = 1 ;
}
V_23 -> V_58 ( V_2 , V_235 , & V_202 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_236 , & V_218 , 0 , V_77 ) ;
V_2 -> V_90 [ V_156 ] = V_2 -> V_27 ;
if ( V_237 & V_242 ) {
#ifdef F_35
V_2 -> V_90 [ V_243 ] = V_2 -> V_157 & ~ V_189 ;
V_23 -> V_238 ( V_2 ,
V_2 -> V_35 == V_36 ?
V_244 : V_245 , & V_234 ) ;
V_2 -> V_27 = V_234 ;
V_23 -> V_238 ( V_2 , V_246 , & V_234 ) ;
V_2 -> V_157 &= ~ ( V_234 | V_189 ) ;
#endif
} else {
V_23 -> V_238 ( V_2 , V_241 , & V_234 ) ;
V_2 -> V_27 = ( T_1 ) V_234 ;
V_2 -> V_157 &= ~ ( V_206 | V_195 | V_189 ) ;
}
return V_76 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_28 V_202 , V_218 ;
V_105 V_234 ;
T_2 V_235 , V_236 ;
V_105 V_237 = 0 ;
V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
if ( V_2 -> V_35 == V_72 )
return F_13 ( V_2 , 0 ) ;
if ( ( V_2 -> V_35 == V_192 ) && ( V_237 & V_242 )
&& ! F_91 ( V_2 ) )
return F_15 ( V_2 ) ;
if ( V_2 -> V_35 == V_36 )
return F_15 ( V_2 ) ;
F_90 ( V_2 , & V_202 , & V_218 ) ;
V_23 -> V_238 ( V_2 , V_247 , & V_234 ) ;
switch ( V_2 -> V_35 ) {
case V_192 :
if ( ( V_234 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
case V_36 :
if ( V_234 == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
}
V_2 -> V_157 &= ~ ( V_206 | V_195 | V_189 ) ;
V_235 = ( T_2 ) V_234 ;
V_235 &= ~ V_248 ;
V_236 = V_235 + 8 ;
V_236 &= ~ V_248 ;
if ( V_2 -> V_35 == V_36 || ( V_237 & V_242 ) ) {
V_202 . V_74 = 0 ;
V_202 . V_219 = 1 ;
}
V_23 -> V_58 ( V_2 , V_235 , & V_202 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_236 , & V_218 , 0 , V_77 ) ;
V_23 -> V_238 ( V_2 , V_249 , & V_234 ) ;
V_2 -> V_27 = V_234 ;
V_23 -> V_238 ( V_2 , V_250 , & V_234 ) ;
V_2 -> V_90 [ V_180 ] = V_234 ;
return V_76 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_28 V_202 , V_218 ;
V_105 V_234 ;
int V_251 ;
T_2 V_235 = 0 , V_236 = 0 ;
if ( V_2 -> V_35 == V_72 ||
V_2 -> V_35 == V_173 )
return F_13 ( V_2 , 0 ) ;
F_90 ( V_2 , & V_202 , & V_218 ) ;
if ( ( V_2 -> V_108 & 0x8 ) != 0x0 )
V_251 = V_36 ;
else
V_251 = V_192 ;
V_202 . V_75 = 3 ;
V_218 . V_75 = 3 ;
V_23 -> V_238 ( V_2 , V_247 , & V_234 ) ;
switch ( V_251 ) {
case V_192 :
V_235 = ( T_2 ) ( V_234 + 16 ) ;
if ( ( V_234 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_236 = ( T_2 ) ( V_234 + 24 ) ;
break;
case V_36 :
V_235 = ( T_2 ) ( V_234 + 32 ) ;
if ( V_234 == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_236 = V_235 + 8 ;
V_202 . V_74 = 0 ;
V_202 . V_219 = 1 ;
break;
}
V_235 |= V_248 ;
V_236 |= V_248 ;
V_23 -> V_58 ( V_2 , V_235 , & V_202 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_236 , & V_218 , 0 , V_77 ) ;
V_2 -> V_27 = V_2 -> V_90 [ V_217 ] ;
V_2 -> V_90 [ V_180 ] = V_2 -> V_90 [ V_156 ] ;
return V_76 ;
}
static bool F_96 ( struct V_1 * V_2 )
{
int V_183 ;
if ( V_2 -> V_35 == V_72 )
return false ;
if ( V_2 -> V_35 == V_173 )
return true ;
V_183 = ( V_2 -> V_157 & V_184 ) >> V_185 ;
return V_2 -> V_23 -> V_69 ( V_2 ) > V_183 ;
}
static bool F_97 ( struct V_1 * V_2 ,
T_2 V_152 , T_2 V_181 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_28 V_252 ;
T_1 V_57 ;
int V_253 ;
T_2 V_254 , V_255 , V_256 , V_257 = V_152 & 0x7 ;
unsigned V_141 = ( 1 << V_181 ) - 1 ;
unsigned long V_258 ;
V_23 -> V_55 ( V_2 , & V_254 , & V_252 , & V_57 , V_176 ) ;
if ( ! V_252 . V_92 )
return false ;
if ( F_7 ( & V_252 ) < 103 )
return false ;
V_258 = F_50 ( & V_252 ) ;
#ifdef F_35
V_258 |= ( ( V_105 ) V_57 ) << 32 ;
#endif
V_253 = V_23 -> V_80 ( V_2 , V_258 + 102 , & V_255 , 2 , NULL ) ;
if ( V_253 != V_76 )
return false ;
if ( V_255 + V_152 / 8 > F_7 ( & V_252 ) )
return false ;
V_253 = V_23 -> V_80 ( V_2 , V_258 + V_255 + V_152 / 8 , & V_256 , 2 , NULL ) ;
if ( V_253 != V_76 )
return false ;
if ( ( V_256 >> V_257 ) & V_141 )
return false ;
return true ;
}
static bool F_98 ( struct V_1 * V_2 ,
T_2 V_152 , T_2 V_181 )
{
if ( V_2 -> V_259 )
return true ;
if ( F_96 ( V_2 ) )
if ( ! F_97 ( V_2 , V_152 , V_181 ) )
return false ;
V_2 -> V_259 = true ;
return true ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
V_261 -> V_262 = V_2 -> V_27 ;
V_261 -> V_263 = V_2 -> V_157 ;
V_261 -> V_264 = V_2 -> V_90 [ V_198 ] ;
V_261 -> V_265 = V_2 -> V_90 [ V_156 ] ;
V_261 -> V_266 = V_2 -> V_90 [ V_217 ] ;
V_261 -> V_127 = V_2 -> V_90 [ V_128 ] ;
V_261 -> V_267 = V_2 -> V_90 [ V_180 ] ;
V_261 -> V_129 = V_2 -> V_90 [ V_130 ] ;
V_261 -> V_131 = V_2 -> V_90 [ V_132 ] ;
V_261 -> V_133 = V_2 -> V_90 [ V_134 ] ;
V_261 -> V_268 = F_19 ( V_2 , V_269 ) ;
V_261 -> V_202 = F_19 ( V_2 , V_86 ) ;
V_261 -> V_218 = F_19 ( V_2 , V_77 ) ;
V_261 -> V_270 = F_19 ( V_2 , V_125 ) ;
V_261 -> V_271 = F_19 ( V_2 , V_164 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
int V_171 ;
V_2 -> V_27 = V_261 -> V_262 ;
V_2 -> V_157 = V_261 -> V_263 | 2 ;
V_2 -> V_90 [ V_198 ] = V_261 -> V_264 ;
V_2 -> V_90 [ V_156 ] = V_261 -> V_265 ;
V_2 -> V_90 [ V_217 ] = V_261 -> V_266 ;
V_2 -> V_90 [ V_128 ] = V_261 -> V_127 ;
V_2 -> V_90 [ V_180 ] = V_261 -> V_267 ;
V_2 -> V_90 [ V_130 ] = V_261 -> V_129 ;
V_2 -> V_90 [ V_132 ] = V_261 -> V_131 ;
V_2 -> V_90 [ V_134 ] = V_261 -> V_133 ;
F_20 ( V_2 , V_261 -> V_271 , V_164 ) ;
F_20 ( V_2 , V_261 -> V_268 , V_269 ) ;
F_20 ( V_2 , V_261 -> V_202 , V_86 ) ;
F_20 ( V_2 , V_261 -> V_218 , V_77 ) ;
F_20 ( V_2 , V_261 -> V_270 , V_125 ) ;
V_171 = F_53 ( V_2 , V_261 -> V_271 , V_164 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_268 , V_269 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_202 , V_86 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_218 , V_77 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_270 , V_125 ) ;
if ( V_171 != V_76 )
return V_171 ;
return V_76 ;
}
static int F_101 ( struct V_1 * V_2 ,
T_2 V_272 , T_2 V_273 ,
T_3 V_274 , struct V_28 * V_275 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_260 V_276 ;
int V_171 ;
T_1 V_277 = F_50 ( V_275 ) ;
V_171 = V_23 -> V_80 ( V_2 , V_274 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
F_99 ( V_2 , & V_276 ) ;
V_171 = V_23 -> V_166 ( V_2 , V_274 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = V_23 -> V_80 ( V_2 , V_277 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_273 != 0xffff ) {
V_276 . V_278 = V_273 ;
V_171 = V_23 -> V_166 ( V_2 , V_277 ,
& V_276 . V_278 ,
sizeof V_276 . V_278 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
}
return F_100 ( V_2 , & V_276 ) ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_279 * V_261 )
{
V_261 -> V_280 = V_2 -> V_23 -> V_281 ( V_2 , 3 ) ;
V_261 -> V_22 = V_2 -> V_27 ;
V_261 -> V_157 = V_2 -> V_157 ;
V_261 -> V_220 = V_2 -> V_90 [ V_198 ] ;
V_261 -> V_222 = V_2 -> V_90 [ V_156 ] ;
V_261 -> V_223 = V_2 -> V_90 [ V_217 ] ;
V_261 -> V_221 = V_2 -> V_90 [ V_128 ] ;
V_261 -> V_282 = V_2 -> V_90 [ V_180 ] ;
V_261 -> V_283 = V_2 -> V_90 [ V_130 ] ;
V_261 -> V_284 = V_2 -> V_90 [ V_132 ] ;
V_261 -> V_285 = V_2 -> V_90 [ V_134 ] ;
V_261 -> V_268 = F_19 ( V_2 , V_269 ) ;
V_261 -> V_202 = F_19 ( V_2 , V_86 ) ;
V_261 -> V_218 = F_19 ( V_2 , V_77 ) ;
V_261 -> V_270 = F_19 ( V_2 , V_125 ) ;
V_261 -> V_286 = F_19 ( V_2 , V_37 ) ;
V_261 -> V_287 = F_19 ( V_2 , V_172 ) ;
V_261 -> V_288 = F_19 ( V_2 , V_164 ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_279 * V_261 )
{
int V_171 ;
if ( V_2 -> V_23 -> V_289 ( V_2 , 3 , V_261 -> V_280 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_27 = V_261 -> V_22 ;
V_2 -> V_157 = V_261 -> V_157 | 2 ;
V_2 -> V_90 [ V_198 ] = V_261 -> V_220 ;
V_2 -> V_90 [ V_156 ] = V_261 -> V_222 ;
V_2 -> V_90 [ V_217 ] = V_261 -> V_223 ;
V_2 -> V_90 [ V_128 ] = V_261 -> V_221 ;
V_2 -> V_90 [ V_180 ] = V_261 -> V_282 ;
V_2 -> V_90 [ V_130 ] = V_261 -> V_283 ;
V_2 -> V_90 [ V_132 ] = V_261 -> V_284 ;
V_2 -> V_90 [ V_134 ] = V_261 -> V_285 ;
F_20 ( V_2 , V_261 -> V_288 , V_164 ) ;
F_20 ( V_2 , V_261 -> V_268 , V_269 ) ;
F_20 ( V_2 , V_261 -> V_202 , V_86 ) ;
F_20 ( V_2 , V_261 -> V_218 , V_77 ) ;
F_20 ( V_2 , V_261 -> V_270 , V_125 ) ;
F_20 ( V_2 , V_261 -> V_286 , V_37 ) ;
F_20 ( V_2 , V_261 -> V_287 , V_172 ) ;
if ( V_2 -> V_157 & V_290 )
V_2 -> V_35 = V_173 ;
else
V_2 -> V_35 = V_192 ;
V_2 -> V_23 -> V_291 ( V_2 , V_2 -> V_157 ) ;
V_171 = F_53 ( V_2 , V_261 -> V_288 , V_164 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_268 , V_269 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_202 , V_86 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_218 , V_77 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_270 , V_125 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_286 , V_37 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_53 ( V_2 , V_261 -> V_287 , V_172 ) ;
if ( V_171 != V_76 )
return V_171 ;
return V_76 ;
}
static int F_104 ( struct V_1 * V_2 ,
T_2 V_272 , T_2 V_273 ,
T_3 V_274 , struct V_28 * V_275 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_279 V_276 ;
int V_171 ;
T_1 V_277 = F_50 ( V_275 ) ;
V_171 = V_23 -> V_80 ( V_2 , V_274 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
F_102 ( V_2 , & V_276 ) ;
V_171 = V_23 -> V_166 ( V_2 , V_274 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = V_23 -> V_80 ( V_2 , V_277 , & V_276 , sizeof V_276 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_273 != 0xffff ) {
V_276 . V_278 = V_273 ;
V_171 = V_23 -> V_166 ( V_2 , V_277 ,
& V_276 . V_278 ,
sizeof V_276 . V_278 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
}
return F_103 ( V_2 , & V_276 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
T_2 V_272 , int V_292 , int V_293 ,
bool V_294 , T_1 V_43 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
struct V_28 V_295 , V_296 ;
int V_171 ;
T_2 V_273 = F_19 ( V_2 , V_176 ) ;
T_3 V_274 =
V_23 -> V_38 ( V_2 , V_176 ) ;
T_1 V_297 ;
V_171 = F_51 ( V_2 , V_272 , & V_296 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_273 , & V_295 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_293 == V_298 ) {
if ( V_292 != - 1 ) {
struct V_28 V_299 ;
int V_75 ;
V_171 = F_48 ( V_2 , V_292 ,
& V_299 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_75 = V_299 . V_75 ;
if ( ( V_272 & 3 ) > V_75 || V_23 -> V_69 ( V_2 ) > V_75 )
return F_13 ( V_2 , ( V_292 << 3 ) | 0x2 ) ;
}
} else if ( V_293 != V_300 ) {
int V_75 = V_296 . V_75 ;
if ( ( V_272 & 3 ) > V_75 || V_23 -> V_69 ( V_2 ) > V_75 )
return F_13 ( V_2 , V_272 ) ;
}
V_297 = F_7 ( & V_296 ) ;
if ( ! V_296 . V_92 ||
( ( V_297 < 0x67 && ( V_296 . type & 8 ) ) ||
V_297 < 0x2b ) ) {
F_16 ( V_2 , V_272 & 0xfffc ) ;
return V_45 ;
}
if ( V_293 == V_300 || V_293 == V_301 ) {
V_295 . type &= ~ ( 1 << 1 ) ;
F_52 ( V_2 , V_273 , & V_295 ) ;
}
if ( V_293 == V_300 )
V_2 -> V_157 = V_2 -> V_157 & ~ V_302 ;
if ( V_293 != V_303 && V_293 != V_298 )
V_273 = 0xffff ;
if ( V_296 . type & 8 )
V_171 = F_104 ( V_2 , V_272 , V_273 ,
V_274 , & V_296 ) ;
else
V_171 = F_101 ( V_2 , V_272 , V_273 ,
V_274 , & V_296 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_293 == V_303 || V_293 == V_298 )
V_2 -> V_157 = V_2 -> V_157 | V_302 ;
if ( V_293 != V_300 ) {
V_296 . type |= ( 1 << 1 ) ;
F_52 ( V_2 , V_272 , & V_296 ) ;
}
V_23 -> V_289 ( V_2 , 0 , V_23 -> V_281 ( V_2 , 0 ) | V_304 ) ;
V_23 -> V_58 ( V_2 , V_272 , & V_296 , 0 , V_176 ) ;
if ( V_294 ) {
V_2 -> V_94 = V_2 -> V_20 = ( V_296 . type & 8 ) ? 4 : 2 ;
V_2 -> V_178 = 0 ;
V_2 -> V_14 . V_104 = ( unsigned long ) V_43 ;
V_171 = F_58 ( V_2 ) ;
}
return V_171 ;
}
int F_106 ( struct V_1 * V_2 ,
T_2 V_272 , int V_292 , int V_293 ,
bool V_294 , T_1 V_43 )
{
int V_79 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_179 ;
V_79 = F_105 ( V_2 , V_272 , V_292 , V_293 ,
V_294 , V_43 ) ;
if ( V_79 == V_76 )
V_2 -> V_22 = V_2 -> V_27 ;
return ( V_79 == V_89 ) ? V_305 : V_306 ;
}
static void F_107 ( struct V_1 * V_2 , unsigned V_32 ,
int V_24 , struct V_102 * V_103 )
{
int V_307 = ( V_2 -> V_157 & V_158 ) ? - 1 : 1 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_24 ] , V_307 * V_103 -> V_17 ) ;
V_103 -> V_60 . V_138 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_24 ] ) ;
V_103 -> V_60 . V_138 . V_32 = V_32 ;
}
static int F_108 ( struct V_1 * V_2 )
{
T_4 V_308 , V_309 ;
bool V_310 , V_311 , V_312 ;
V_311 = V_2 -> V_157 & V_313 ;
V_308 = V_2 -> V_19 . V_104 ;
V_309 = V_308 ;
V_312 = V_311 ;
V_311 = false ;
V_310 = V_2 -> V_157 & V_314 ;
if ( ( V_308 & 0x0f ) > 9 || V_310 ) {
V_308 -= 6 ;
V_311 = V_312 | ( V_308 >= 250 ) ;
V_310 = true ;
} else {
V_310 = false ;
}
if ( V_309 > 0x99 || V_312 ) {
V_308 -= 0x60 ;
V_311 = true ;
}
V_2 -> V_19 . V_104 = V_308 ;
V_2 -> V_14 . type = V_315 ;
V_2 -> V_14 . V_104 = 0 ;
V_2 -> V_14 . V_17 = 1 ;
F_88 ( V_2 , L_16 ) ;
V_2 -> V_157 &= ~ ( V_314 | V_313 ) ;
if ( V_311 )
V_2 -> V_157 |= V_313 ;
if ( V_310 )
V_2 -> V_157 |= V_314 ;
return V_76 ;
}
static int F_109 ( struct V_1 * V_2 )
{
long V_26 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = ( unsigned long ) V_2 -> V_27 ;
F_6 ( V_2 , V_26 ) ;
return F_58 ( V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_2 V_68 , V_316 ;
T_3 V_214 ;
int V_79 ;
V_316 = F_19 ( V_2 , V_86 ) ;
V_214 = V_2 -> V_27 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
if ( F_53 ( V_2 , V_68 , V_86 ) )
return V_76 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_211 , V_2 -> V_94 ) ;
V_2 -> V_14 . V_104 = V_316 ;
V_79 = F_58 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_14 . V_104 = V_214 ;
return F_58 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_79 ;
V_2 -> V_19 . type = V_115 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_79 = F_59 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_112 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_17 ) ;
return V_76 ;
}
static int F_113 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_16 ) ;
return V_76 ;
}
static int F_114 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_18 ) ;
return V_76 ;
}
static int F_115 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_19 ) ;
return V_76 ;
}
static int F_116 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_20 ) ;
return V_76 ;
}
static int F_117 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_21 ) ;
return V_76 ;
}
static int F_118 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_22 ) ;
return V_76 ;
}
static int F_119 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_15 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_120 ( struct V_1 * V_2 )
{
F_88 ( V_2 , L_23 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_121 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_104 = V_2 -> V_19 . V_104 ;
F_56 ( & V_2 -> V_14 ) ;
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_117 ;
V_2 -> V_178 = 1 ;
return V_76 ;
}
static int F_122 ( struct V_1 * V_2 )
{
F_123 ( V_2 , L_10 ) ;
return V_76 ;
}
static int F_124 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_104 = V_2 -> V_196 . V_104 ;
return F_122 ( V_2 ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_115 ;
V_2 -> V_19 . V_17 = V_2 -> V_14 . V_17 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_90 [ V_217 ] ;
V_2 -> V_19 . V_104 = ~ ( ( V_2 -> V_14 . V_104 >> ( V_2 -> V_14 . V_17 * 8 - 1 ) ) - 1 ) ;
return V_76 ;
}
static int F_126 ( struct V_1 * V_2 )
{
V_105 V_317 = 0 ;
V_2 -> V_23 -> V_238 ( V_2 , V_318 , & V_317 ) ;
V_2 -> V_90 [ V_198 ] = ( T_1 ) V_317 ;
V_2 -> V_90 [ V_217 ] = V_317 >> 32 ;
return V_76 ;
}
static int F_127 ( struct V_1 * V_2 )
{
V_105 V_319 ;
if ( V_2 -> V_23 -> V_320 ( V_2 , V_2 -> V_90 [ V_156 ] , & V_319 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_90 [ V_198 ] = ( T_1 ) V_319 ;
V_2 -> V_90 [ V_217 ] = V_319 >> 32 ;
return V_76 ;
}
static int F_128 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_104 ;
return V_76 ;
}
static int F_129 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> V_289 ( V_2 , V_2 -> V_11 , V_2 -> V_14 . V_104 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_130 ( struct V_1 * V_2 )
{
unsigned long V_104 ;
if ( V_2 -> V_35 == V_36 )
V_104 = V_2 -> V_14 . V_104 & ~ 0ULL ;
else
V_104 = V_2 -> V_14 . V_104 & ~ 0U ;
if ( V_2 -> V_23 -> V_321 ( V_2 , V_2 -> V_11 , V_104 ) < 0 )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_131 ( struct V_1 * V_2 )
{
V_105 V_234 ;
V_234 = ( T_1 ) V_2 -> V_90 [ V_198 ]
| ( ( V_105 ) V_2 -> V_90 [ V_217 ] << 32 ) ;
if ( V_2 -> V_23 -> V_322 ( V_2 , V_2 -> V_90 [ V_156 ] , V_234 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_132 ( struct V_1 * V_2 )
{
V_105 V_234 ;
if ( V_2 -> V_23 -> V_238 ( V_2 , V_2 -> V_90 [ V_156 ] , & V_234 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_90 [ V_198 ] = ( T_1 ) V_234 ;
V_2 -> V_90 [ V_217 ] = V_234 >> 32 ;
return V_76 ;
}
static int F_133 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 > V_172 )
return F_15 ( V_2 ) ;
V_2 -> V_19 . V_104 = F_19 ( V_2 , V_2 -> V_11 ) ;
return V_76 ;
}
static int F_134 ( struct V_1 * V_2 )
{
T_2 V_68 = V_2 -> V_14 . V_104 ;
if ( V_2 -> V_11 == V_86 || V_2 -> V_11 > V_172 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_11 == V_77 )
V_2 -> V_323 = V_324 ;
V_2 -> V_19 . type = V_179 ;
return F_53 ( V_2 , V_68 , V_2 -> V_11 ) ;
}
static int F_135 ( struct V_1 * V_2 )
{
memcpy ( & V_2 -> V_19 . V_114 , & V_2 -> V_14 . V_114 , V_2 -> V_94 ) ;
return V_76 ;
}
static int F_136 ( struct V_1 * V_2 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_2 -> V_14 . V_60 . V_138 , 1 , false , & V_64 ) ;
if ( V_79 == V_76 )
V_2 -> V_23 -> V_325 ( V_2 , V_64 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_137 ( struct V_1 * V_2 )
{
T_3 V_326 ;
V_326 = V_2 -> V_23 -> V_281 ( V_2 , 0 ) ;
V_326 &= ~ V_304 ;
V_2 -> V_23 -> V_289 ( V_2 , 0 , V_326 ) ;
return V_76 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_79 ;
if ( V_2 -> V_10 != 3 || V_2 -> V_12 != 1 )
return V_89 ;
V_79 = V_2 -> V_23 -> V_327 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_160 V_160 ;
int V_79 ;
V_79 = F_31 ( V_2 , V_2 -> V_14 . V_60 . V_138 ,
& V_160 . V_61 , & V_160 . V_93 ,
V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_23 -> V_328 ( V_2 , & V_160 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_140 ( struct V_1 * V_2 )
{
int V_79 ;
V_79 = V_2 -> V_23 -> V_327 ( V_2 ) ;
V_2 -> V_19 . type = V_179 ;
return V_79 ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_160 V_160 ;
int V_79 ;
V_79 = F_31 ( V_2 , V_2 -> V_14 . V_60 . V_138 ,
& V_160 . V_61 , & V_160 . V_93 ,
V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_23 -> V_329 ( V_2 , & V_160 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_142 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = 2 ;
V_2 -> V_19 . V_104 = V_2 -> V_23 -> V_281 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_289 ( V_2 , 0 , ( V_2 -> V_23 -> V_281 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_14 . V_104 & 0x0f ) ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_144 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_90 [ V_156 ] , - 1 ) ;
if ( ( F_3 ( V_2 , V_2 -> V_90 [ V_156 ] ) != 0 ) &&
( V_2 -> V_110 == 0xe2 || F_32 ( V_2 -> V_110 ^ 0x5 , V_2 -> V_157 ) ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_145 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_2 -> V_90 [ V_156 ] ) == 0 )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_146 ( struct V_1 * V_2 )
{
if ( ! F_47 ( V_2 , V_2 -> V_19 . V_17 , V_2 -> V_14 . V_104 ,
& V_2 -> V_19 . V_104 ) )
return V_330 ;
return V_76 ;
}
static int F_147 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_331 ( V_2 , V_2 -> V_14 . V_17 , V_2 -> V_19 . V_104 ,
& V_2 -> V_14 . V_104 , 1 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_148 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_157 &= ~ V_332 ;
return V_76 ;
}
static int F_149 ( struct V_1 * V_2 )
{
if ( F_96 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_323 = V_333 ;
V_2 -> V_157 |= V_332 ;
return V_76 ;
}
static int F_150 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_179 ;
V_2 -> V_14 . V_104 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
F_123 ( V_2 , L_24 ) ;
return V_76 ;
}
static int F_151 ( struct V_1 * V_2 )
{
F_123 ( V_2 , L_25 ) ;
return V_76 ;
}
static int F_152 ( struct V_1 * V_2 )
{
F_123 ( V_2 , L_26 ) ;
return V_76 ;
}
static int F_153 ( struct V_1 * V_2 )
{
F_123 ( V_2 , L_27 ) ;
return V_76 ;
}
static int F_154 ( struct V_1 * V_2 )
{
T_4 V_334 ;
__asm__ ("bsf %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
V_2 -> V_157 &= ~ V_335 ;
if ( V_334 ) {
V_2 -> V_157 |= V_335 ;
V_2 -> V_19 . type = V_179 ;
}
return V_76 ;
}
static int F_155 ( struct V_1 * V_2 )
{
T_4 V_334 ;
__asm__ ("bsr %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
V_2 -> V_157 &= ~ V_335 ;
if ( V_334 ) {
V_2 -> V_157 |= V_335 ;
V_2 -> V_19 . type = V_179 ;
}
return V_76 ;
}
static bool F_156 ( int V_336 )
{
switch ( V_336 ) {
case 0 :
case 2 ... 4 :
case 8 :
return true ;
default:
return false ;
}
}
static int F_157 ( struct V_1 * V_2 )
{
if ( ! F_156 ( V_2 -> V_11 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_158 ( struct V_1 * V_2 )
{
V_105 V_337 = V_2 -> V_14 . V_15 ;
int V_338 = V_2 -> V_11 ;
V_105 V_237 = 0 ;
static V_105 V_339 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_340 ,
0 , 0 , 0 ,
V_341 ,
} ;
if ( ! F_156 ( V_338 ) )
return F_15 ( V_2 ) ;
if ( V_337 & V_339 [ V_338 ] )
return F_13 ( V_2 , 0 ) ;
switch ( V_338 ) {
case 0 : {
V_105 V_342 ;
if ( ( ( V_337 & V_343 ) && ! ( V_337 & V_344 ) ) ||
( ( V_337 & V_345 ) && ! ( V_337 & V_346 ) ) )
return F_13 ( V_2 , 0 ) ;
V_342 = V_2 -> V_23 -> V_281 ( V_2 , 4 ) ;
V_2 -> V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
if ( ( V_337 & V_343 ) && ( V_237 & V_347 ) &&
! ( V_342 & V_348 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_105 V_349 = 0 ;
V_2 -> V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
if ( V_237 & V_242 )
V_349 = V_350 ;
else if ( V_2 -> V_23 -> V_281 ( V_2 , 4 ) & V_348 )
V_349 = V_351 ;
else if ( V_2 -> V_23 -> V_281 ( V_2 , 0 ) & V_343 )
V_349 = V_352 ;
if ( V_337 & V_349 )
return F_13 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_2 -> V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
if ( ( V_237 & V_242 ) && ! ( V_337 & V_348 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
}
return V_76 ;
}
static int F_159 ( struct V_1 * V_2 )
{
unsigned long V_353 ;
V_2 -> V_23 -> V_354 ( V_2 , 7 , & V_353 ) ;
return V_353 & ( 1 << 13 ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_355 = V_2 -> V_11 ;
V_105 V_342 ;
if ( V_355 > 7 )
return F_15 ( V_2 ) ;
V_342 = V_2 -> V_23 -> V_281 ( V_2 , 4 ) ;
if ( ( V_342 & V_356 ) && ( V_355 == 4 || V_355 == 5 ) )
return F_15 ( V_2 ) ;
if ( F_159 ( V_2 ) )
return F_12 ( V_2 ) ;
return V_76 ;
}
static int F_161 ( struct V_1 * V_2 )
{
V_105 V_337 = V_2 -> V_14 . V_15 ;
int V_355 = V_2 -> V_11 ;
if ( ( V_355 == 6 || V_355 == 7 ) && ( V_337 & 0xffffffff00000000ULL ) )
return F_13 ( V_2 , 0 ) ;
return F_160 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
V_105 V_237 ;
V_2 -> V_23 -> V_238 ( V_2 , V_239 , & V_237 ) ;
if ( ! ( V_237 & V_357 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_163 ( struct V_1 * V_2 )
{
V_105 V_358 = V_2 -> V_90 [ V_198 ] ;
if ( V_358 & 0xffff000000000000ULL )
return F_13 ( V_2 , 0 ) ;
return F_162 ( V_2 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
V_105 V_342 = V_2 -> V_23 -> V_281 ( V_2 , 4 ) ;
if ( V_342 & V_359 && V_2 -> V_23 -> V_69 ( V_2 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_165 ( struct V_1 * V_2 )
{
V_105 V_342 = V_2 -> V_23 -> V_281 ( V_2 , 4 ) ;
V_105 V_360 = V_2 -> V_90 [ V_156 ] ;
if ( ( ! ( V_342 & V_361 ) && V_2 -> V_23 -> V_69 ( V_2 ) ) ||
( V_360 > 3 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_166 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = F_26 ( V_2 -> V_19 . V_17 , 4u ) ;
if ( ! F_98 ( V_2 , V_2 -> V_14 . V_104 , V_2 -> V_19 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_167 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_17 = F_26 ( V_2 -> V_14 . V_17 , 4u ) ;
if ( ! F_98 ( V_2 , V_2 -> V_19 . V_104 , V_2 -> V_14 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static unsigned F_168 ( struct V_1 * V_2 )
{
unsigned V_61 ;
V_61 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
if ( V_61 == 8 )
V_61 = 4 ;
return V_61 ;
}
static int F_169 ( struct V_1 * V_2 , struct V_102 * V_103 ,
unsigned V_61 , bool V_362 )
{
int V_79 = V_76 ;
V_103 -> type = V_315 ;
V_103 -> V_17 = V_61 ;
V_103 -> V_60 . V_138 . V_71 = V_2 -> V_27 ;
switch ( V_103 -> V_17 ) {
case 1 :
V_103 -> V_104 = F_40 ( V_135 , V_2 ) ;
break;
case 2 :
V_103 -> V_104 = F_40 ( V_142 , V_2 ) ;
break;
case 4 :
V_103 -> V_104 = F_40 ( V_136 , V_2 ) ;
break;
}
if ( ! V_362 ) {
switch ( V_103 -> V_17 ) {
case 1 :
V_103 -> V_104 &= 0xff ;
break;
case 2 :
V_103 -> V_104 &= 0xffff ;
break;
case 4 :
V_103 -> V_104 &= 0xffffffff ;
break;
}
}
V_139:
return V_79 ;
}
static int F_170 ( struct V_1 * V_2 , struct V_102 * V_103 ,
unsigned V_74 )
{
int V_79 = V_76 ;
switch ( V_74 ) {
case V_363 :
F_38 ( V_2 , V_103 ) ;
break;
case V_364 :
V_79 = F_169 ( V_2 , V_103 , 1 , false ) ;
break;
case V_365 :
V_2 -> V_366 . V_17 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
V_367:
* V_103 = V_2 -> V_366 ;
V_2 -> V_368 = V_103 ;
if ( ( V_2 -> V_74 & V_369 ) && V_103 == & V_2 -> V_19 )
F_42 ( V_2 ) ;
V_103 -> V_117 = V_103 -> V_104 ;
break;
case V_370 :
V_2 -> V_366 . V_17 = 8 ;
goto V_367;
case V_371 :
V_103 -> type = V_115 ;
V_103 -> V_17 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
V_103 -> V_60 . V_24 = & V_2 -> V_90 [ V_198 ] ;
F_33 ( V_103 ) ;
V_103 -> V_117 = V_103 -> V_104 ;
break;
case V_372 :
V_103 -> type = V_126 ;
V_103 -> V_17 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
V_103 -> V_60 . V_138 . V_71 =
F_4 ( V_2 , V_2 -> V_90 [ V_134 ] ) ;
V_103 -> V_60 . V_138 . V_32 = V_269 ;
V_103 -> V_104 = 0 ;
break;
case V_373 :
V_103 -> type = V_115 ;
V_103 -> V_17 = 2 ;
V_103 -> V_60 . V_24 = & V_2 -> V_90 [ V_217 ] ;
F_33 ( V_103 ) ;
break;
case V_374 :
V_103 -> V_17 = 1 ;
V_103 -> V_104 = V_2 -> V_90 [ V_156 ] & 0xff ;
break;
case V_375 :
V_79 = F_169 ( V_2 , V_103 , 1 , true ) ;
break;
case V_376 :
V_103 -> V_17 = 1 ;
V_103 -> V_104 = 1 ;
break;
case V_377 :
V_79 = F_169 ( V_2 , V_103 , F_168 ( V_2 ) , true ) ;
break;
case V_378 :
V_2 -> V_366 . V_17 = 1 ;
goto V_367;
case V_379 :
V_2 -> V_366 . V_17 = 2 ;
goto V_367;
case V_380 :
V_2 -> V_366 . V_17 = 4 ;
goto V_367;
case V_381 :
V_79 = F_169 ( V_2 , V_103 , 2 , false ) ;
break;
case V_382 :
V_79 = F_169 ( V_2 , V_103 , F_168 ( V_2 ) , false ) ;
break;
case V_383 :
V_103 -> type = V_126 ;
V_103 -> V_17 = ( V_2 -> V_74 & V_116 ) ? 1 : V_2 -> V_94 ;
V_103 -> V_60 . V_138 . V_71 =
F_4 ( V_2 , V_2 -> V_90 [ V_132 ] ) ;
V_103 -> V_60 . V_138 . V_32 = V_34 ( V_2 ) ;
V_103 -> V_104 = 0 ;
break;
case V_384 :
V_103 -> type = V_315 ;
V_103 -> V_60 . V_138 . V_71 = V_2 -> V_27 ;
V_103 -> V_17 = V_2 -> V_94 + 2 ;
F_171 ( V_103 -> V_211 , V_103 -> V_17 , V_2 ) ;
break;
case V_385 :
V_2 -> V_366 . V_17 = V_2 -> V_94 + 2 ;
goto V_367;
case V_386 :
V_103 -> V_104 = V_269 ;
break;
case V_387 :
V_103 -> V_104 = V_86 ;
break;
case V_388 :
V_103 -> V_104 = V_77 ;
break;
case V_389 :
V_103 -> V_104 = V_125 ;
break;
case V_390 :
V_103 -> V_104 = V_37 ;
break;
case V_391 :
V_103 -> V_104 = V_172 ;
break;
case V_392 :
default:
V_103 -> type = V_179 ;
break;
}
V_139:
return V_79 ;
}
int F_172 ( struct V_1 * V_2 , void * V_393 , int V_394 )
{
int V_79 = V_76 ;
int V_35 = V_2 -> V_35 ;
int V_395 , V_396 , V_397 , V_398 ;
bool V_399 = false ;
struct V_400 V_400 ;
V_2 -> V_366 . type = V_179 ;
V_2 -> V_368 = NULL ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_63 . V_87 = V_2 -> V_27 ;
V_2 -> V_63 . V_85 = V_2 -> V_63 . V_87 + V_394 ;
if ( V_394 > 0 )
memcpy ( V_2 -> V_63 . V_78 , V_393 , V_394 ) ;
switch ( V_35 ) {
case V_72 :
case V_173 :
case V_193 :
V_395 = V_396 = 2 ;
break;
case V_192 :
V_395 = V_396 = 4 ;
break;
#ifdef F_35
case V_36 :
V_395 = 4 ;
V_396 = 8 ;
break;
#endif
default:
return V_305 ;
}
V_2 -> V_94 = V_395 ;
V_2 -> V_20 = V_396 ;
for (; ; ) {
switch ( V_2 -> V_110 = F_40 ( T_4 , V_2 ) ) {
case 0x66 :
V_399 = true ;
V_2 -> V_94 = V_395 ^ 6 ;
break;
case 0x67 :
if ( V_35 == V_36 )
V_2 -> V_20 = V_396 ^ 12 ;
else
V_2 -> V_20 = V_396 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_9 ( V_2 , ( V_2 -> V_110 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_9 ( V_2 , V_2 -> V_110 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_35 != V_36 )
goto V_401;
V_2 -> V_108 = V_2 -> V_110 ;
continue;
case 0xf0 :
V_2 -> V_178 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_9 = V_2 -> V_110 ;
break;
default:
goto V_401;
}
V_2 -> V_108 = 0 ;
}
V_401:
if ( V_2 -> V_108 & 8 )
V_2 -> V_94 = 8 ;
V_400 = V_402 [ V_2 -> V_110 ] ;
if ( V_2 -> V_110 == 0x0f ) {
V_2 -> V_403 = 1 ;
V_2 -> V_110 = F_40 ( T_4 , V_2 ) ;
V_400 = V_404 [ V_2 -> V_110 ] ;
}
V_2 -> V_74 = V_400 . V_96 ;
while ( V_2 -> V_74 & V_405 ) {
switch ( V_2 -> V_74 & V_405 ) {
case V_406 :
V_2 -> V_123 = F_40 ( T_4 , V_2 ) ;
-- V_2 -> V_27 ;
V_397 = ( V_2 -> V_123 >> 3 ) & 7 ;
V_400 = V_400 . V_407 . V_408 [ V_397 ] ;
break;
case V_409 :
V_2 -> V_123 = F_40 ( T_4 , V_2 ) ;
-- V_2 -> V_27 ;
V_397 = ( V_2 -> V_123 >> 3 ) & 7 ;
if ( ( V_2 -> V_123 >> 6 ) == 3 )
V_400 = V_400 . V_407 . V_410 -> V_411 [ V_397 ] ;
else
V_400 = V_400 . V_407 . V_410 -> V_412 [ V_397 ] ;
break;
case V_413 :
V_397 = V_2 -> V_123 & 7 ;
V_400 = V_400 . V_407 . V_408 [ V_397 ] ;
break;
case V_414 :
if ( V_2 -> V_9 && V_399 )
return V_305 ;
V_398 = V_399 ? 0x66 : V_2 -> V_9 ;
switch ( V_398 ) {
case 0x00 : V_400 = V_400 . V_407 . V_415 -> V_416 ; break;
case 0x66 : V_400 = V_400 . V_407 . V_415 -> V_417 ; break;
case 0xf2 : V_400 = V_400 . V_407 . V_415 -> V_418 ; break;
case 0xf3 : V_400 = V_400 . V_407 . V_415 -> V_419 ; break;
}
break;
default:
return V_305 ;
}
V_2 -> V_74 &= ~ ( V_105 ) V_405 ;
V_2 -> V_74 |= V_400 . V_96 ;
}
V_2 -> V_420 = V_400 . V_407 . V_420 ;
V_2 -> V_421 = V_400 . V_421 ;
V_2 -> V_4 = V_400 . V_4 ;
if ( V_2 -> V_74 == 0 || ( V_2 -> V_74 & V_422 ) )
return V_305 ;
if ( ! ( V_2 -> V_74 & V_423 ) && V_2 -> V_424 )
return V_305 ;
if ( V_35 == V_36 && ( V_2 -> V_74 & V_425 ) )
V_2 -> V_94 = 8 ;
if ( V_2 -> V_74 & V_426 ) {
if ( V_35 == V_36 )
V_2 -> V_94 = 8 ;
else
V_2 -> V_94 = 4 ;
}
if ( V_2 -> V_74 & V_111 )
V_2 -> V_94 = 16 ;
if ( V_2 -> V_74 & V_109 ) {
V_79 = F_39 ( V_2 , & V_2 -> V_366 ) ;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_2 -> V_124 ) ;
} else if ( V_2 -> V_74 & V_427 )
V_79 = F_41 ( V_2 , & V_2 -> V_366 ) ;
if ( V_79 != V_76 )
goto V_139;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_125 ) ;
V_2 -> V_366 . V_60 . V_138 . V_32 = V_34 ( V_2 ) ;
if ( V_2 -> V_366 . type == V_126 && V_2 -> V_20 != 8 )
V_2 -> V_366 . V_60 . V_138 . V_71 = ( T_1 ) V_2 -> V_366 . V_60 . V_138 . V_71 ;
V_79 = F_170 ( V_2 , & V_2 -> V_14 , ( V_2 -> V_74 >> V_428 ) & V_429 ) ;
if ( V_79 != V_76 )
goto V_139;
V_79 = F_170 ( V_2 , & V_2 -> V_196 , ( V_2 -> V_74 >> V_430 ) & V_429 ) ;
if ( V_79 != V_76 )
goto V_139;
V_79 = F_170 ( V_2 , & V_2 -> V_19 , ( V_2 -> V_74 >> V_431 ) & V_429 ) ;
V_139:
if ( V_2 -> V_368 && V_2 -> V_368 -> type == V_126 && V_2 -> V_137 )
V_2 -> V_368 -> V_60 . V_138 . V_71 += V_2 -> V_27 ;
return ( V_79 != V_76 ) ? V_305 : V_306 ;
}
bool F_173 ( struct V_1 * V_2 )
{
return V_2 -> V_74 & V_432 ;
}
static bool F_174 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_110 == 0xa6 ) || ( V_2 -> V_110 == 0xa7 ) ||
( V_2 -> V_110 == 0xae ) || ( V_2 -> V_110 == 0xaf ) )
&& ( ( ( V_2 -> V_9 == V_433 ) &&
( ( V_2 -> V_157 & V_99 ) == 0 ) )
|| ( ( V_2 -> V_9 == V_434 ) &&
( ( V_2 -> V_157 & V_99 ) == V_99 ) ) ) )
return true ;
return false ;
}
int F_175 ( struct V_1 * V_2 )
{
struct V_163 * V_23 = V_2 -> V_23 ;
int V_79 = V_76 ;
int V_435 = V_2 -> V_19 . type ;
V_2 -> V_145 . V_147 = 0 ;
if ( V_2 -> V_35 == V_36 && ( V_2 -> V_74 & V_436 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_139;
}
if ( V_2 -> V_178 && ( ! ( V_2 -> V_74 & V_437 ) || V_2 -> V_19 . type != V_126 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_139;
}
if ( ( V_2 -> V_74 & V_438 ) == V_439 && V_2 -> V_14 . type != V_126 ) {
V_79 = F_15 ( V_2 ) ;
goto V_139;
}
if ( ( V_2 -> V_74 & V_111 )
&& ( ( V_23 -> V_281 ( V_2 , 0 ) & V_440 )
|| ! ( V_23 -> V_281 ( V_2 , 4 ) & V_441 ) ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_139;
}
if ( ( V_2 -> V_74 & V_111 ) && ( V_23 -> V_281 ( V_2 , 0 ) & V_304 ) ) {
V_79 = F_18 ( V_2 ) ;
goto V_139;
}
if ( F_28 ( V_2 -> V_442 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_443 ) ;
if ( V_79 != V_76 )
goto V_139;
}
if ( ( V_2 -> V_74 & V_444 ) && V_23 -> V_69 ( V_2 ) ) {
V_79 = F_13 ( V_2 , 0 ) ;
goto V_139;
}
if ( ( V_2 -> V_74 & V_445 ) && ! ( V_2 -> V_35 & V_446 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_139;
}
if ( V_2 -> V_421 ) {
V_79 = V_2 -> V_421 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_139;
}
if ( F_28 ( V_2 -> V_442 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_447 ) ;
if ( V_79 != V_76 )
goto V_139;
}
if ( V_2 -> V_9 && ( V_2 -> V_74 & String ) ) {
if ( F_3 ( V_2 , V_2 -> V_90 [ V_156 ] ) == 0 ) {
V_2 -> V_22 = V_2 -> V_27 ;
goto V_139;
}
}
if ( ( V_2 -> V_14 . type == V_126 ) && ! ( V_2 -> V_74 & V_448 ) ) {
V_79 = F_44 ( V_2 , V_2 -> V_14 . V_60 . V_138 ,
V_2 -> V_14 . V_211 , V_2 -> V_14 . V_17 ) ;
if ( V_79 != V_76 )
goto V_139;
V_2 -> V_14 . V_216 = V_2 -> V_14 . V_15 ;
}
if ( V_2 -> V_196 . type == V_126 ) {
V_79 = F_44 ( V_2 , V_2 -> V_196 . V_60 . V_138 ,
& V_2 -> V_196 . V_104 , V_2 -> V_196 . V_17 ) ;
if ( V_79 != V_76 )
goto V_139;
}
if ( ( V_2 -> V_74 & V_449 ) == V_450 )
goto V_451;
if ( ( V_2 -> V_19 . type == V_126 ) && ! ( V_2 -> V_74 & V_452 ) ) {
V_79 = F_44 ( V_2 , V_2 -> V_19 . V_60 . V_138 ,
& V_2 -> V_19 . V_104 , V_2 -> V_19 . V_17 ) ;
if ( V_79 != V_76 )
goto V_139;
}
V_2 -> V_19 . V_117 = V_2 -> V_19 . V_104 ;
V_451:
if ( F_28 ( V_2 -> V_442 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_453 ) ;
if ( V_79 != V_76 )
goto V_139;
}
if ( V_2 -> V_420 ) {
V_79 = V_2 -> V_420 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_139;
goto F_57;
}
if ( V_2 -> V_403 )
goto V_454;
switch ( V_2 -> V_110 ) {
case 0x40 ... 0x47 :
F_77 ( V_2 , L_13 ) ;
break;
case 0x48 ... 0x4f :
F_77 ( V_2 , L_14 ) ;
break;
case 0x63 :
if ( V_2 -> V_35 != V_36 )
goto V_455;
V_2 -> V_19 . V_104 = ( V_136 ) V_2 -> V_14 . V_104 ;
break;
case 0x70 ... 0x7f :
if ( F_32 ( V_2 -> V_110 , V_2 -> V_157 ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0x8d :
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_60 . V_138 . V_71 ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_19 . V_60 . V_24 == & V_2 -> V_90 [ V_198 ] )
break;
V_79 = F_121 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_94 ) {
case 2 : V_2 -> V_19 . V_104 = ( V_135 ) V_2 -> V_19 . V_104 ; break;
case 4 : V_2 -> V_19 . V_104 = ( V_142 ) V_2 -> V_19 . V_104 ; break;
case 8 : V_2 -> V_19 . V_104 = ( V_136 ) V_2 -> V_19 . V_104 ; break;
}
break;
case 0xc0 ... 0xc1 :
V_79 = F_73 ( V_2 ) ;
break;
case 0xcc :
V_79 = F_69 ( V_2 , 3 ) ;
break;
case 0xcd :
V_79 = F_69 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0xce :
if ( V_2 -> V_157 & V_97 )
V_79 = F_69 ( V_2 , 4 ) ;
break;
case 0xd0 ... 0xd1 :
V_79 = F_73 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_156 ] ;
V_79 = F_73 ( V_2 ) ;
break;
case 0xe9 :
case 0xeb :
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
V_2 -> V_19 . type = V_179 ;
break;
case 0xf4 :
V_2 -> V_23 -> V_456 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_157 ^= V_98 ;
break;
case 0xf8 :
V_2 -> V_157 &= ~ V_98 ;
break;
case 0xf9 :
V_2 -> V_157 |= V_98 ;
break;
case 0xfc :
V_2 -> V_157 &= ~ V_158 ;
break;
case 0xfd :
V_2 -> V_157 |= V_158 ;
break;
default:
goto V_455;
}
if ( V_79 != V_76 )
goto V_139;
F_57:
V_79 = F_57 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_139;
V_2 -> V_19 . type = V_435 ;
if ( ( V_2 -> V_74 & V_438 ) == V_457 )
F_107 ( V_2 , V_34 ( V_2 ) ,
V_132 , & V_2 -> V_14 ) ;
if ( ( V_2 -> V_74 & V_449 ) == V_458 )
F_107 ( V_2 , V_269 , V_134 ,
& V_2 -> V_19 ) ;
if ( V_2 -> V_9 && ( V_2 -> V_74 & String ) ) {
struct V_143 * V_253 = & V_2 -> V_153 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_156 ] , - 1 ) ;
if ( ! F_174 ( V_2 ) ) {
if ( ( V_253 -> V_85 != 0 || V_2 -> V_90 [ V_156 ] & 0x3ff ) &&
( V_253 -> V_85 == 0 || V_253 -> V_85 != V_253 -> V_147 ) ) {
V_2 -> V_145 . V_85 = 0 ;
return V_459 ;
}
goto V_139;
}
}
V_2 -> V_22 = V_2 -> V_27 ;
V_139:
if ( V_79 == V_45 )
V_2 -> V_460 = true ;
if ( V_79 == V_461 )
return V_462 ;
return ( V_79 == V_89 ) ? V_305 : V_306 ;
V_454:
switch ( V_2 -> V_110 ) {
case 0x09 :
( V_2 -> V_23 -> V_463 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_19 . V_104 = V_23 -> V_281 ( V_2 , V_2 -> V_11 ) ;
break;
case 0x21 :
V_23 -> V_354 ( V_2 , V_2 -> V_11 , & V_2 -> V_19 . V_104 ) ;
break;
case 0x40 ... 0x4f :
V_2 -> V_19 . V_104 = V_2 -> V_19 . V_117 = V_2 -> V_14 . V_104 ;
if ( ! F_32 ( V_2 -> V_110 , V_2 -> V_157 ) )
V_2 -> V_19 . type = V_179 ;
break;
case 0x80 ... 0x8f :
if ( F_32 ( V_2 -> V_110 , V_2 -> V_157 ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_19 . V_104 = F_32 ( V_2 -> V_110 , V_2 -> V_157 ) ;
break;
case 0xa4 :
case 0xa5 :
F_176 ( V_2 , L_28 ) ;
break;
case 0xac :
case 0xad :
F_176 ( V_2 , L_29 ) ;
break;
case 0xae :
break;
case 0xb6 ... 0xb7 :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_74 & V_116 ) ? ( T_4 ) V_2 -> V_14 . V_104
: ( T_2 ) V_2 -> V_14 . V_104 ;
break;
case 0xbe ... 0xbf :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_74 & V_116 ) ? ( V_135 ) V_2 -> V_14 . V_104 :
( V_142 ) V_2 -> V_14 . V_104 ;
break;
case 0xc0 ... 0xc1 :
F_88 ( V_2 , L_17 ) ;
V_2 -> V_14 . V_104 = V_2 -> V_19 . V_117 ;
F_56 ( & V_2 -> V_14 ) ;
break;
case 0xc3 :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_94 == 4 ) ? ( T_1 ) V_2 -> V_14 . V_104 :
( V_105 ) V_2 -> V_14 . V_104 ;
break;
default:
goto V_455;
}
if ( V_79 != V_76 )
goto V_139;
goto F_57;
V_455:
return V_305 ;
}
