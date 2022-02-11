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
static int F_25 ( struct V_1 * V_2 ,
unsigned long V_22 , T_4 * V_81 )
{
struct V_82 * V_83 = & V_2 -> V_63 ;
int V_79 ;
int V_61 , V_84 ;
if ( V_22 == V_83 -> V_85 ) {
unsigned long V_64 ;
struct V_59 V_60 = { . V_32 = V_86 , . V_71 = V_22 } ;
V_84 = V_83 -> V_85 - V_83 -> V_87 ;
V_61 = F_26 ( 15UL - V_84 , V_88 - F_27 ( V_22 ) ) ;
V_79 = F_21 ( V_2 , V_60 , V_61 , false , true , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = V_2 -> V_23 -> V_63 ( V_2 , V_64 , V_83 -> V_78 + V_84 ,
V_61 , & V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_83 -> V_85 += V_61 ;
}
* V_81 = V_83 -> V_78 [ V_22 - V_83 -> V_87 ] ;
return V_76 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned long V_22 , void * V_81 , unsigned V_61 )
{
int V_79 ;
if ( V_22 + V_61 - V_2 -> V_22 > 15 )
return V_89 ;
while ( V_61 -- ) {
V_79 = F_25 ( V_2 , V_22 ++ , V_81 ++ ) ;
if ( V_79 != V_76 )
return V_79 ;
}
return V_76 ;
}
static void * F_29 ( T_4 V_11 , unsigned long * V_90 ,
int V_91 )
{
void * V_92 ;
V_92 = & V_90 [ V_11 ] ;
if ( V_91 && V_11 >= 4 && V_11 < 8 )
V_92 = ( unsigned char * ) & V_90 [ V_11 & 3 ] + 1 ;
return V_92 ;
}
static int F_30 ( struct V_1 * V_2 ,
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
static int F_31 ( unsigned int V_95 , unsigned int V_96 )
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
static void F_32 ( struct V_102 * V_103 )
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
static void F_33 ( struct V_1 * V_2 , T_5 * V_78 , int V_24 )
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
V_2 -> V_23 -> V_107 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 , T_5 * V_78 ,
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
V_2 -> V_23 -> V_107 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
int V_108 )
{
unsigned V_24 = V_2 -> V_11 ;
int V_91 = V_2 -> V_109 == 0 ;
if ( ! ( V_2 -> V_74 & V_110 ) )
V_24 = ( V_2 -> V_111 & 7 ) | ( ( V_2 -> V_109 & 1 ) << 3 ) ;
if ( V_2 -> V_74 & V_112 ) {
V_103 -> type = V_113 ;
V_103 -> V_17 = 16 ;
V_103 -> V_60 . V_114 = V_24 ;
F_33 ( V_2 , & V_103 -> V_115 , V_24 ) ;
return;
}
V_103 -> type = V_116 ;
if ( ( V_2 -> V_74 & V_117 ) && ! V_108 ) {
V_103 -> V_60 . V_24 = F_29 ( V_24 , V_2 -> V_90 , V_91 ) ;
V_103 -> V_17 = 1 ;
} else {
V_103 -> V_60 . V_24 = F_29 ( V_24 , V_2 -> V_90 , 0 ) ;
V_103 -> V_17 = V_2 -> V_94 ;
}
F_32 ( V_103 ) ;
V_103 -> V_118 = V_103 -> V_104 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
T_4 V_119 ;
int V_120 = 0 , V_121 = 0 , V_122 ;
int V_79 = V_76 ;
T_3 V_123 = 0 ;
if ( V_2 -> V_109 ) {
V_2 -> V_11 = ( V_2 -> V_109 & 4 ) << 1 ;
V_120 = ( V_2 -> V_109 & 2 ) << 2 ;
V_2 -> V_12 = V_121 = ( V_2 -> V_109 & 1 ) << 3 ;
}
V_2 -> V_124 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
V_2 -> V_10 |= ( V_2 -> V_124 & 0xc0 ) >> 6 ;
V_2 -> V_11 |= ( V_2 -> V_124 & 0x38 ) >> 3 ;
V_2 -> V_12 |= ( V_2 -> V_124 & 0x07 ) ;
V_2 -> V_125 = V_126 ;
if ( V_2 -> V_10 == 3 ) {
V_103 -> type = V_116 ;
V_103 -> V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
V_103 -> V_60 . V_24 = F_29 ( V_2 -> V_12 ,
V_2 -> V_90 , V_2 -> V_74 & V_117 ) ;
if ( V_2 -> V_74 & V_112 ) {
V_103 -> type = V_113 ;
V_103 -> V_17 = 16 ;
V_103 -> V_60 . V_114 = V_2 -> V_12 ;
F_33 ( V_2 , & V_103 -> V_115 , V_2 -> V_12 ) ;
return V_79 ;
}
F_32 ( V_103 ) ;
return V_79 ;
}
V_103 -> type = V_127 ;
if ( V_2 -> V_20 == 2 ) {
unsigned V_128 = V_2 -> V_90 [ V_129 ] ;
unsigned V_130 = V_2 -> V_90 [ V_131 ] ;
unsigned V_132 = V_2 -> V_90 [ V_133 ] ;
unsigned V_134 = V_2 -> V_90 [ V_135 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 6 )
V_123 += F_39 ( T_2 , 2 , V_2 -> V_27 ) ;
break;
case 1 :
V_123 += F_39 ( V_136 , 1 , V_2 -> V_27 ) ;
break;
case 2 :
V_123 += F_39 ( T_2 , 2 , V_2 -> V_27 ) ;
break;
}
switch ( V_2 -> V_12 ) {
case 0 :
V_123 += V_128 + V_132 ;
break;
case 1 :
V_123 += V_128 + V_134 ;
break;
case 2 :
V_123 += V_130 + V_132 ;
break;
case 3 :
V_123 += V_130 + V_134 ;
break;
case 4 :
V_123 += V_132 ;
break;
case 5 :
V_123 += V_134 ;
break;
case 6 :
if ( V_2 -> V_10 != 0 )
V_123 += V_130 ;
break;
case 7 :
V_123 += V_128 ;
break;
}
if ( V_2 -> V_12 == 2 || V_2 -> V_12 == 3 ||
( V_2 -> V_12 == 6 && V_2 -> V_10 != 0 ) )
V_2 -> V_125 = V_77 ;
V_123 = ( T_2 ) V_123 ;
} else {
if ( ( V_2 -> V_12 & 7 ) == 4 ) {
V_119 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
V_120 |= ( V_119 >> 3 ) & 7 ;
V_121 |= V_119 & 7 ;
V_122 = V_119 >> 6 ;
if ( ( V_121 & 7 ) == 5 && V_2 -> V_10 == 0 )
V_123 += F_39 ( V_137 , 4 , V_2 -> V_27 ) ;
else
V_123 += V_2 -> V_90 [ V_121 ] ;
if ( V_120 != 4 )
V_123 += V_2 -> V_90 [ V_120 ] << V_122 ;
} else if ( ( V_2 -> V_12 & 7 ) == 5 && V_2 -> V_10 == 0 ) {
if ( V_2 -> V_35 == V_36 )
V_2 -> V_138 = 1 ;
} else
V_123 += V_2 -> V_90 [ V_2 -> V_12 ] ;
switch ( V_2 -> V_10 ) {
case 0 :
if ( V_2 -> V_12 == 5 )
V_123 += F_39 ( V_137 , 4 , V_2 -> V_27 ) ;
break;
case 1 :
V_123 += F_39 ( V_136 , 1 , V_2 -> V_27 ) ;
break;
case 2 :
V_123 += F_39 ( V_137 , 4 , V_2 -> V_27 ) ;
break;
}
}
V_103 -> V_60 . V_139 . V_71 = V_123 ;
V_140:
return V_79 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_79 = V_76 ;
V_103 -> type = V_127 ;
switch ( V_2 -> V_20 ) {
case 2 :
V_103 -> V_60 . V_139 . V_71 = F_39 ( T_2 , 2 , V_2 -> V_27 ) ;
break;
case 4 :
V_103 -> V_60 . V_139 . V_71 = F_39 ( T_1 , 4 , V_2 -> V_27 ) ;
break;
case 8 :
V_103 -> V_60 . V_139 . V_71 = F_39 ( V_105 , 8 , V_2 -> V_27 ) ;
break;
}
V_140:
return V_79 ;
}
static void F_41 ( struct V_1 * V_2 )
{
long V_141 = 0 , V_142 ;
if ( V_2 -> V_19 . type == V_127 && V_2 -> V_14 . type == V_116 ) {
V_142 = ~ ( V_2 -> V_19 . V_17 * 8 - 1 ) ;
if ( V_2 -> V_14 . V_17 == 2 )
V_141 = ( V_143 ) V_2 -> V_14 . V_104 & ( V_143 ) V_142 ;
else if ( V_2 -> V_14 . V_17 == 4 )
V_141 = ( V_137 ) V_2 -> V_14 . V_104 & ( V_137 ) V_142 ;
V_2 -> V_19 . V_60 . V_139 . V_71 += ( V_141 >> 3 ) ;
}
V_2 -> V_14 . V_104 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned long V_60 , void * V_81 , unsigned V_61 )
{
int V_79 ;
struct V_144 * V_145 = & V_2 -> V_146 ;
while ( V_61 ) {
int V_147 = F_26 ( V_61 , 8u ) ;
V_61 -= V_147 ;
if ( V_145 -> V_148 < V_145 -> V_85 )
goto V_149;
V_79 = V_2 -> V_23 -> F_42 ( V_2 , V_60 , V_145 -> V_78 + V_145 -> V_85 , V_147 ,
& V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_145 -> V_85 += V_147 ;
V_149:
memcpy ( V_81 , V_145 -> V_78 + V_145 -> V_148 , V_147 ) ;
V_145 -> V_148 += V_147 ;
V_81 += V_147 ;
V_60 += V_147 ;
}
return V_76 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , false , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return F_42 ( V_2 , V_64 , V_78 , V_61 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
const void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , true , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return V_2 -> V_23 -> V_150 ( V_2 , V_64 , V_78 , V_61 ,
& V_2 -> V_41 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_59 V_60 ,
const void * V_151 , const void * V_78 ,
unsigned V_61 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_60 , V_61 , true , & V_64 ) ;
if ( V_79 != V_76 )
return V_79 ;
return V_2 -> V_23 -> V_152 ( V_2 , V_64 , V_151 , V_78 ,
V_61 , & V_2 -> V_41 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned int V_61 , unsigned short V_153 ,
void * V_81 )
{
struct V_144 * V_79 = & V_2 -> V_154 ;
if ( V_79 -> V_148 == V_79 -> V_85 ) {
unsigned int V_155 , V_147 ;
unsigned int V_156 = V_2 -> V_9 ?
F_3 ( V_2 , V_2 -> V_90 [ V_157 ] ) : 1 ;
V_155 = ( V_2 -> V_158 & V_159 ) ?
F_27 ( V_2 -> V_90 [ V_135 ] ) :
V_88 - F_27 ( V_2 -> V_90 [ V_135 ] ) ;
V_147 = F_26 ( F_26 ( V_155 , ( unsigned int ) sizeof( V_79 -> V_78 ) ) / V_61 ,
V_156 ) ;
if ( V_147 == 0 )
V_147 = 1 ;
V_79 -> V_148 = V_79 -> V_85 = 0 ;
if ( ! V_2 -> V_23 -> F_46 ( V_2 , V_61 , V_153 , V_79 -> V_78 , V_147 ) )
return 0 ;
V_79 -> V_85 = V_147 * V_61 ;
}
memcpy ( V_81 , V_79 -> V_78 + V_79 -> V_148 , V_61 ) ;
V_79 -> V_148 += V_61 ;
return 1 ;
}
static void F_47 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_160 * V_161 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
if ( V_54 & 1 << 2 ) {
struct V_28 V_29 ;
T_2 V_68 ;
memset ( V_161 , 0 , sizeof *V_161 ) ;
if ( ! V_23 -> V_55 ( V_2 , & V_68 , & V_29 , NULL , V_163 ) )
return;
V_161 -> V_61 = F_7 ( & V_29 ) ;
V_161 -> V_93 = F_48 ( & V_29 ) ;
} else
V_23 -> V_164 ( V_2 , V_161 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_160 V_161 ;
T_2 V_165 = V_54 >> 3 ;
T_3 V_60 ;
F_47 ( V_2 , V_54 , & V_161 ) ;
if ( V_161 . V_61 < V_165 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_60 = V_161 . V_93 + V_165 * 8 ;
return V_2 -> V_23 -> V_80 ( V_2 , V_60 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
T_2 V_54 , struct V_28 * V_29 )
{
struct V_160 V_161 ;
T_2 V_165 = V_54 >> 3 ;
T_3 V_60 ;
F_47 ( V_2 , V_54 , & V_161 ) ;
if ( V_161 . V_61 < V_165 * 8 + 7 )
return F_13 ( V_2 , V_54 & 0xfffc ) ;
V_60 = V_161 . V_93 + V_165 * 8 ;
return V_2 -> V_23 -> V_166 ( V_2 , V_60 , V_29 , sizeof *V_29 ,
& V_2 -> V_41 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
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
F_52 ( & V_167 , V_54 << 4 ) ;
F_53 ( & V_167 , 0xffff ) ;
V_167 . type = 3 ;
V_167 . V_92 = 1 ;
V_167 . V_174 = 1 ;
goto V_175;
}
if ( ( V_32 == V_86 || V_32 == V_77 || V_32 == V_176 )
&& V_170 )
goto V_41;
if ( V_32 == V_176 && ( V_54 & ( 1 << 2 ) ) )
goto V_41;
if ( V_170 )
goto V_175;
V_171 = F_49 ( V_2 , V_54 , & V_167 ) ;
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
case V_163 :
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
V_171 = F_50 ( V_2 , V_54 , & V_167 ) ;
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
static void F_54 ( struct V_102 * V_103 )
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
static int F_55 ( struct V_1 * V_2 )
{
int V_79 ;
switch ( V_2 -> V_19 . type ) {
case V_116 :
F_54 ( & V_2 -> V_19 ) ;
break;
case V_127 :
if ( V_2 -> V_178 )
V_79 = F_45 ( V_2 ,
V_2 -> V_19 . V_60 . V_139 ,
& V_2 -> V_19 . V_118 ,
& V_2 -> V_19 . V_104 ,
V_2 -> V_19 . V_17 ) ;
else
V_79 = F_44 ( V_2 ,
V_2 -> V_19 . V_60 . V_139 ,
& V_2 -> V_19 . V_104 ,
V_2 -> V_19 . V_17 ) ;
if ( V_79 != V_76 )
return V_79 ;
break;
case V_113 :
F_36 ( V_2 , & V_2 -> V_19 . V_115 , V_2 -> V_19 . V_60 . V_114 ) ;
break;
case V_179 :
break;
default:
break;
}
return V_76 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_59 V_60 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , - V_2 -> V_94 ) ;
V_60 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_180 ] ) ;
V_60 . V_32 = V_77 ;
V_2 -> V_19 . type = V_179 ;
return F_44 ( V_2 , V_60 , & V_2 -> V_14 . V_104 , V_2 -> V_94 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
void * V_81 , int V_181 )
{
int V_79 ;
struct V_59 V_60 ;
V_60 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_180 ] ) ;
V_60 . V_32 = V_77 ;
V_79 = F_43 ( V_2 , V_60 , V_81 , V_181 ) ;
if ( V_79 != V_76 )
return V_79 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , V_181 ) ;
return V_79 ;
}
static int F_58 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
void * V_81 , int V_181 )
{
int V_79 ;
unsigned long V_104 , V_182 ;
int V_183 = ( V_2 -> V_158 & V_184 ) >> V_185 ;
int V_69 = V_2 -> V_23 -> V_69 ( V_2 ) ;
V_79 = F_57 ( V_2 , & V_104 , V_181 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_182 = V_98 | V_101 | V_186 | V_99 | V_100 | V_97
| V_187 | V_159 | V_188 | V_189 | V_190 | V_191 ;
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
( V_2 -> V_158 & ~ V_182 ) | ( V_104 & V_182 ) ;
return V_79 ;
}
static int F_60 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_158 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
return F_59 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_32 )
{
V_2 -> V_14 . V_104 = F_19 ( V_2 , V_32 ) ;
return F_56 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 , int V_32 )
{
unsigned long V_54 ;
int V_79 ;
V_79 = F_57 ( V_2 , & V_54 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_51 ( V_2 , ( T_2 ) V_54 , V_32 ) ;
return V_79 ;
}
static int F_63 ( struct V_1 * V_2 )
{
unsigned long V_196 = V_2 -> V_90 [ V_180 ] ;
int V_79 = V_76 ;
int V_24 = V_197 ;
while ( V_24 <= V_135 ) {
( V_24 == V_180 ) ?
( V_2 -> V_14 . V_104 = V_196 ) : ( V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_24 ] ) ;
V_79 = F_56 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
++ V_24 ;
}
return V_79 ;
}
static int F_64 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_104 = ( unsigned long ) V_2 -> V_158 ;
return F_56 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
int V_24 = V_135 ;
while ( V_24 >= V_197 ) {
if ( V_24 == V_180 ) {
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] ,
V_2 -> V_94 ) ;
-- V_24 ;
}
V_79 = F_57 ( V_2 , & V_2 -> V_90 [ V_24 ] , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
break;
-- V_24 ;
}
return V_79 ;
}
int F_66 ( struct V_1 * V_2 , int V_198 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
int V_79 ;
struct V_160 V_161 ;
T_6 V_199 ;
T_6 V_200 ;
T_2 V_201 , V_22 ;
V_2 -> V_14 . V_104 = V_2 -> V_158 ;
V_79 = F_56 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_158 &= ~ ( V_195 | V_187 | V_190 ) ;
V_2 -> V_14 . V_104 = F_19 ( V_2 , V_86 ) ;
V_79 = F_56 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_14 . V_104 = V_2 -> V_27 ;
V_79 = F_56 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_23 -> V_202 ( V_2 , & V_161 ) ;
V_200 = V_161 . V_93 + ( V_198 << 2 ) ;
V_199 = V_161 . V_93 + ( V_198 << 2 ) + 2 ;
V_79 = V_23 -> V_80 ( V_2 , V_199 , & V_201 , 2 , & V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = V_23 -> V_80 ( V_2 , V_200 , & V_22 , 2 , & V_2 -> V_41 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_51 ( V_2 , V_201 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_22 ;
return V_79 ;
}
static int F_67 ( struct V_1 * V_2 , int V_198 )
{
switch( V_2 -> V_35 ) {
case V_72 :
return F_66 ( V_2 , V_198 ) ;
case V_173 :
case V_193 :
case V_192 :
case V_36 :
default:
return V_89 ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
unsigned long V_203 = 0 ;
unsigned long V_204 = 0 ;
unsigned long V_201 = 0 ;
unsigned long V_142 = V_98 | V_101 | V_186 | V_99 | V_100 | V_187 |
V_195 | V_159 | V_97 | V_194 | V_188 | V_189 |
V_190 | V_191 | ( 1 << 1 ) ;
unsigned long V_205 = V_206 | V_207 | V_208 ;
V_79 = F_57 ( V_2 , & V_203 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
if ( V_203 & ~ 0xffff )
return F_13 ( V_2 , 0 ) ;
V_79 = F_57 ( V_2 , & V_201 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_57 ( V_2 , & V_204 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_51 ( V_2 , ( T_2 ) V_201 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_203 ;
if ( V_2 -> V_94 == 4 )
V_2 -> V_158 = ( ( V_204 & V_142 ) | ( V_2 -> V_158 & V_205 ) ) ;
else if ( V_2 -> V_94 == 2 ) {
V_2 -> V_158 &= ~ 0xffff ;
V_2 -> V_158 |= V_204 ;
}
V_2 -> V_158 &= ~ V_209 ;
V_2 -> V_158 |= V_210 ;
return V_79 ;
}
static int F_69 ( struct V_1 * V_2 )
{
switch( V_2 -> V_35 ) {
case V_72 :
return F_68 ( V_2 ) ;
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
int V_79 ;
unsigned short V_68 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
V_79 = F_51 ( V_2 , V_68 , V_86 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_211 , V_2 -> V_94 ) ;
return V_76 ;
}
static int F_71 ( struct V_1 * V_2 )
{
return F_57 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_19 . V_17 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case 0 :
F_73 ( L_1 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 1 :
F_73 ( L_2 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 2 :
F_73 ( L_3 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 3 :
F_73 ( L_4 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 4 :
case 6 :
F_73 ( L_5 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 5 :
F_73 ( L_6 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 7 :
F_73 ( L_7 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
}
return V_76 ;
}
static int F_74 ( struct V_1 * V_2 )
{
unsigned long * V_212 = & V_2 -> V_90 [ V_197 ] ;
unsigned long * V_213 = & V_2 -> V_90 [ V_214 ] ;
T_4 V_215 = 0 ;
switch ( V_2 -> V_11 ) {
case 0 ... 1 :
F_75 ( L_8 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 2 :
V_2 -> V_19 . V_104 = ~ V_2 -> V_19 . V_104 ;
break;
case 3 :
F_76 ( L_9 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 4 :
F_77 ( L_10 , V_2 -> V_14 , * V_212 , * V_213 , V_2 -> V_158 ) ;
break;
case 5 :
F_77 ( L_11 , V_2 -> V_14 , * V_212 , * V_213 , V_2 -> V_158 ) ;
break;
case 6 :
F_78 ( L_12 , V_2 -> V_14 , * V_212 , * V_213 ,
V_2 -> V_158 , V_215 ) ;
break;
case 7 :
F_78 ( L_13 , V_2 -> V_14 , * V_212 , * V_213 ,
V_2 -> V_158 , V_215 ) ;
break;
default:
return V_89 ;
}
if ( V_215 )
return F_17 ( V_2 ) ;
return V_76 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_79 = V_76 ;
switch ( V_2 -> V_11 ) {
case 0 :
F_76 ( L_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 1 :
F_76 ( L_15 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 2 : {
long int V_216 ;
V_216 = V_2 -> V_27 ;
V_2 -> V_27 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = V_216 ;
V_79 = F_56 ( V_2 ) ;
break;
}
case 4 :
V_2 -> V_27 = V_2 -> V_14 . V_104 ;
break;
case 5 :
V_79 = F_70 ( V_2 ) ;
break;
case 6 :
V_79 = F_56 ( V_2 ) ;
break;
}
return V_79 ;
}
static int F_80 ( struct V_1 * V_2 )
{
V_105 V_217 = V_2 -> V_19 . V_218 ;
if ( ( ( T_1 ) ( V_217 >> 0 ) != ( T_1 ) V_2 -> V_90 [ V_197 ] ) ||
( ( T_1 ) ( V_217 >> 32 ) != ( T_1 ) V_2 -> V_90 [ V_214 ] ) ) {
V_2 -> V_90 [ V_197 ] = ( T_1 ) ( V_217 >> 0 ) ;
V_2 -> V_90 [ V_214 ] = ( T_1 ) ( V_217 >> 32 ) ;
V_2 -> V_158 &= ~ V_99 ;
} else {
V_2 -> V_19 . V_15 = ( ( V_105 ) V_2 -> V_90 [ V_157 ] << 32 ) |
( T_1 ) V_2 -> V_90 [ V_129 ] ;
V_2 -> V_158 |= V_99 ;
}
return V_76 ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
return F_58 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
int V_79 ;
unsigned long V_201 ;
V_79 = F_57 ( V_2 , & V_2 -> V_27 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
if ( V_2 -> V_94 == 4 )
V_2 -> V_27 = ( T_1 ) V_2 -> V_27 ;
V_79 = F_57 ( V_2 , & V_201 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_79 = F_51 ( V_2 , ( T_2 ) V_201 , V_86 ) ;
return V_79 ;
}
static int F_83 ( struct V_1 * V_2 , int V_32 )
{
unsigned short V_68 ;
int V_79 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
V_79 = F_51 ( V_2 , V_68 , V_32 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_104 ;
return V_79 ;
}
static void
F_84 ( struct V_1 * V_2 ,
struct V_28 * V_201 , struct V_28 * V_219 )
{
T_2 V_54 ;
memset ( V_201 , 0 , sizeof( struct V_28 ) ) ;
V_2 -> V_23 -> V_55 ( V_2 , & V_54 , V_201 , NULL , V_86 ) ;
memset ( V_219 , 0 , sizeof( struct V_28 ) ) ;
V_201 -> V_220 = 0 ;
F_52 ( V_201 , 0 ) ;
V_201 -> V_31 = 1 ;
F_53 ( V_201 , 0xfffff ) ;
V_201 -> type = 0x0b ;
V_201 -> V_174 = 1 ;
V_201 -> V_75 = 0 ;
V_201 -> V_92 = 1 ;
V_201 -> V_74 = 1 ;
F_52 ( V_219 , 0 ) ;
F_53 ( V_219 , 0xfffff ) ;
V_219 -> V_31 = 1 ;
V_219 -> V_174 = 1 ;
V_219 -> type = 0x03 ;
V_219 -> V_74 = 1 ;
V_219 -> V_75 = 0 ;
V_219 -> V_92 = 1 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_28 V_201 , V_219 ;
V_105 V_221 ;
T_2 V_222 , V_223 ;
V_105 V_224 = 0 ;
if ( V_2 -> V_35 == V_72 ||
V_2 -> V_35 == V_173 )
return F_15 ( V_2 ) ;
V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
F_84 ( V_2 , & V_201 , & V_219 ) ;
V_23 -> V_225 ( V_2 , V_227 , & V_221 ) ;
V_221 >>= 32 ;
V_222 = ( T_2 ) ( V_221 & 0xfffc ) ;
V_223 = ( T_2 ) ( V_221 + 8 ) ;
if ( V_224 & V_228 ) {
V_201 . V_74 = 0 ;
V_201 . V_220 = 1 ;
}
V_23 -> V_58 ( V_2 , V_222 , & V_201 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_223 , & V_219 , 0 , V_77 ) ;
V_2 -> V_90 [ V_157 ] = V_2 -> V_27 ;
if ( V_224 & V_228 ) {
#ifdef F_34
V_2 -> V_90 [ V_229 ] = V_2 -> V_158 & ~ V_189 ;
V_23 -> V_225 ( V_2 ,
V_2 -> V_35 == V_36 ?
V_230 : V_231 , & V_221 ) ;
V_2 -> V_27 = V_221 ;
V_23 -> V_225 ( V_2 , V_232 , & V_221 ) ;
V_2 -> V_158 &= ~ ( V_221 | V_189 ) ;
#endif
} else {
V_23 -> V_225 ( V_2 , V_227 , & V_221 ) ;
V_2 -> V_27 = ( T_1 ) V_221 ;
V_2 -> V_158 &= ~ ( V_206 | V_195 | V_189 ) ;
}
return V_76 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_28 V_201 , V_219 ;
V_105 V_221 ;
T_2 V_222 , V_223 ;
V_105 V_224 = 0 ;
V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
if ( V_2 -> V_35 == V_72 )
return F_13 ( V_2 , 0 ) ;
if ( V_2 -> V_35 == V_36 )
return F_15 ( V_2 ) ;
F_84 ( V_2 , & V_201 , & V_219 ) ;
V_23 -> V_225 ( V_2 , V_233 , & V_221 ) ;
switch ( V_2 -> V_35 ) {
case V_192 :
if ( ( V_221 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
case V_36 :
if ( V_221 == 0x0 )
return F_13 ( V_2 , 0 ) ;
break;
}
V_2 -> V_158 &= ~ ( V_206 | V_195 | V_189 ) ;
V_222 = ( T_2 ) V_221 ;
V_222 &= ~ V_234 ;
V_223 = V_222 + 8 ;
V_223 &= ~ V_234 ;
if ( V_2 -> V_35 == V_36 || ( V_224 & V_228 ) ) {
V_201 . V_74 = 0 ;
V_201 . V_220 = 1 ;
}
V_23 -> V_58 ( V_2 , V_222 , & V_201 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_223 , & V_219 , 0 , V_77 ) ;
V_23 -> V_225 ( V_2 , V_235 , & V_221 ) ;
V_2 -> V_27 = V_221 ;
V_23 -> V_225 ( V_2 , V_236 , & V_221 ) ;
V_2 -> V_90 [ V_180 ] = V_221 ;
return V_76 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_28 V_201 , V_219 ;
V_105 V_221 ;
int V_237 ;
T_2 V_222 = 0 , V_223 = 0 ;
if ( V_2 -> V_35 == V_72 ||
V_2 -> V_35 == V_173 )
return F_13 ( V_2 , 0 ) ;
F_84 ( V_2 , & V_201 , & V_219 ) ;
if ( ( V_2 -> V_109 & 0x8 ) != 0x0 )
V_237 = V_36 ;
else
V_237 = V_192 ;
V_201 . V_75 = 3 ;
V_219 . V_75 = 3 ;
V_23 -> V_225 ( V_2 , V_233 , & V_221 ) ;
switch ( V_237 ) {
case V_192 :
V_222 = ( T_2 ) ( V_221 + 16 ) ;
if ( ( V_221 & 0xfffc ) == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_223 = ( T_2 ) ( V_221 + 24 ) ;
break;
case V_36 :
V_222 = ( T_2 ) ( V_221 + 32 ) ;
if ( V_221 == 0x0 )
return F_13 ( V_2 , 0 ) ;
V_223 = V_222 + 8 ;
V_201 . V_74 = 0 ;
V_201 . V_220 = 1 ;
break;
}
V_222 |= V_234 ;
V_223 |= V_234 ;
V_23 -> V_58 ( V_2 , V_222 , & V_201 , 0 , V_86 ) ;
V_23 -> V_58 ( V_2 , V_223 , & V_219 , 0 , V_77 ) ;
V_2 -> V_27 = V_2 -> V_90 [ V_214 ] ;
V_2 -> V_90 [ V_180 ] = V_2 -> V_90 [ V_157 ] ;
return V_76 ;
}
static bool F_88 ( struct V_1 * V_2 )
{
int V_183 ;
if ( V_2 -> V_35 == V_72 )
return false ;
if ( V_2 -> V_35 == V_173 )
return true ;
V_183 = ( V_2 -> V_158 & V_184 ) >> V_185 ;
return V_2 -> V_23 -> V_69 ( V_2 ) > V_183 ;
}
static bool F_89 ( struct V_1 * V_2 ,
T_2 V_153 , T_2 V_181 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_28 V_238 ;
T_1 V_57 ;
int V_239 ;
T_2 V_240 , V_241 , V_242 , V_243 = V_153 & 0x7 ;
unsigned V_142 = ( 1 << V_181 ) - 1 ;
unsigned long V_244 ;
V_23 -> V_55 ( V_2 , & V_240 , & V_238 , & V_57 , V_176 ) ;
if ( ! V_238 . V_92 )
return false ;
if ( F_7 ( & V_238 ) < 103 )
return false ;
V_244 = F_48 ( & V_238 ) ;
#ifdef F_34
V_244 |= ( ( V_105 ) V_57 ) << 32 ;
#endif
V_239 = V_23 -> V_80 ( V_2 , V_244 + 102 , & V_241 , 2 , NULL ) ;
if ( V_239 != V_76 )
return false ;
if ( V_241 + V_153 / 8 > F_7 ( & V_238 ) )
return false ;
V_239 = V_23 -> V_80 ( V_2 , V_244 + V_241 + V_153 / 8 , & V_242 , 2 , NULL ) ;
if ( V_239 != V_76 )
return false ;
if ( ( V_242 >> V_243 ) & V_142 )
return false ;
return true ;
}
static bool F_90 ( struct V_1 * V_2 ,
T_2 V_153 , T_2 V_181 )
{
if ( V_2 -> V_245 )
return true ;
if ( F_88 ( V_2 ) )
if ( ! F_89 ( V_2 , V_153 , V_181 ) )
return false ;
V_2 -> V_245 = true ;
return true ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
V_247 -> V_248 = V_2 -> V_27 ;
V_247 -> V_249 = V_2 -> V_158 ;
V_247 -> V_250 = V_2 -> V_90 [ V_197 ] ;
V_247 -> V_251 = V_2 -> V_90 [ V_157 ] ;
V_247 -> V_252 = V_2 -> V_90 [ V_214 ] ;
V_247 -> V_128 = V_2 -> V_90 [ V_129 ] ;
V_247 -> V_253 = V_2 -> V_90 [ V_180 ] ;
V_247 -> V_130 = V_2 -> V_90 [ V_131 ] ;
V_247 -> V_132 = V_2 -> V_90 [ V_133 ] ;
V_247 -> V_134 = V_2 -> V_90 [ V_135 ] ;
V_247 -> V_254 = F_19 ( V_2 , V_255 ) ;
V_247 -> V_201 = F_19 ( V_2 , V_86 ) ;
V_247 -> V_219 = F_19 ( V_2 , V_77 ) ;
V_247 -> V_256 = F_19 ( V_2 , V_126 ) ;
V_247 -> V_257 = F_19 ( V_2 , V_163 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_246 * V_247 )
{
int V_171 ;
V_2 -> V_27 = V_247 -> V_248 ;
V_2 -> V_158 = V_247 -> V_249 | 2 ;
V_2 -> V_90 [ V_197 ] = V_247 -> V_250 ;
V_2 -> V_90 [ V_157 ] = V_247 -> V_251 ;
V_2 -> V_90 [ V_214 ] = V_247 -> V_252 ;
V_2 -> V_90 [ V_129 ] = V_247 -> V_128 ;
V_2 -> V_90 [ V_180 ] = V_247 -> V_253 ;
V_2 -> V_90 [ V_131 ] = V_247 -> V_130 ;
V_2 -> V_90 [ V_133 ] = V_247 -> V_132 ;
V_2 -> V_90 [ V_135 ] = V_247 -> V_134 ;
F_20 ( V_2 , V_247 -> V_257 , V_163 ) ;
F_20 ( V_2 , V_247 -> V_254 , V_255 ) ;
F_20 ( V_2 , V_247 -> V_201 , V_86 ) ;
F_20 ( V_2 , V_247 -> V_219 , V_77 ) ;
F_20 ( V_2 , V_247 -> V_256 , V_126 ) ;
V_171 = F_51 ( V_2 , V_247 -> V_257 , V_163 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_254 , V_255 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_201 , V_86 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_219 , V_77 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_256 , V_126 ) ;
if ( V_171 != V_76 )
return V_171 ;
return V_76 ;
}
static int F_93 ( struct V_1 * V_2 ,
T_2 V_258 , T_2 V_259 ,
T_3 V_260 , struct V_28 * V_261 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_246 V_262 ;
int V_171 ;
T_1 V_263 = F_48 ( V_261 ) ;
V_171 = V_23 -> V_80 ( V_2 , V_260 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
F_91 ( V_2 , & V_262 ) ;
V_171 = V_23 -> V_166 ( V_2 , V_260 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = V_23 -> V_80 ( V_2 , V_263 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_259 != 0xffff ) {
V_262 . V_264 = V_259 ;
V_171 = V_23 -> V_166 ( V_2 , V_263 ,
& V_262 . V_264 ,
sizeof V_262 . V_264 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
}
return F_92 ( V_2 , & V_262 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_265 * V_247 )
{
V_247 -> V_266 = V_2 -> V_23 -> V_267 ( V_2 , 3 ) ;
V_247 -> V_22 = V_2 -> V_27 ;
V_247 -> V_158 = V_2 -> V_158 ;
V_247 -> V_268 = V_2 -> V_90 [ V_197 ] ;
V_247 -> V_269 = V_2 -> V_90 [ V_157 ] ;
V_247 -> V_270 = V_2 -> V_90 [ V_214 ] ;
V_247 -> V_271 = V_2 -> V_90 [ V_129 ] ;
V_247 -> V_272 = V_2 -> V_90 [ V_180 ] ;
V_247 -> V_273 = V_2 -> V_90 [ V_131 ] ;
V_247 -> V_274 = V_2 -> V_90 [ V_133 ] ;
V_247 -> V_275 = V_2 -> V_90 [ V_135 ] ;
V_247 -> V_254 = F_19 ( V_2 , V_255 ) ;
V_247 -> V_201 = F_19 ( V_2 , V_86 ) ;
V_247 -> V_219 = F_19 ( V_2 , V_77 ) ;
V_247 -> V_256 = F_19 ( V_2 , V_126 ) ;
V_247 -> V_276 = F_19 ( V_2 , V_37 ) ;
V_247 -> V_277 = F_19 ( V_2 , V_172 ) ;
V_247 -> V_278 = F_19 ( V_2 , V_163 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
struct V_265 * V_247 )
{
int V_171 ;
if ( V_2 -> V_23 -> V_279 ( V_2 , 3 , V_247 -> V_266 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_27 = V_247 -> V_22 ;
V_2 -> V_158 = V_247 -> V_158 | 2 ;
V_2 -> V_90 [ V_197 ] = V_247 -> V_268 ;
V_2 -> V_90 [ V_157 ] = V_247 -> V_269 ;
V_2 -> V_90 [ V_214 ] = V_247 -> V_270 ;
V_2 -> V_90 [ V_129 ] = V_247 -> V_271 ;
V_2 -> V_90 [ V_180 ] = V_247 -> V_272 ;
V_2 -> V_90 [ V_131 ] = V_247 -> V_273 ;
V_2 -> V_90 [ V_133 ] = V_247 -> V_274 ;
V_2 -> V_90 [ V_135 ] = V_247 -> V_275 ;
F_20 ( V_2 , V_247 -> V_278 , V_163 ) ;
F_20 ( V_2 , V_247 -> V_254 , V_255 ) ;
F_20 ( V_2 , V_247 -> V_201 , V_86 ) ;
F_20 ( V_2 , V_247 -> V_219 , V_77 ) ;
F_20 ( V_2 , V_247 -> V_256 , V_126 ) ;
F_20 ( V_2 , V_247 -> V_276 , V_37 ) ;
F_20 ( V_2 , V_247 -> V_277 , V_172 ) ;
V_171 = F_51 ( V_2 , V_247 -> V_278 , V_163 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_254 , V_255 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_201 , V_86 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_219 , V_77 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_256 , V_126 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_276 , V_37 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_51 ( V_2 , V_247 -> V_277 , V_172 ) ;
if ( V_171 != V_76 )
return V_171 ;
return V_76 ;
}
static int F_96 ( struct V_1 * V_2 ,
T_2 V_258 , T_2 V_259 ,
T_3 V_260 , struct V_28 * V_261 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_265 V_262 ;
int V_171 ;
T_1 V_263 = F_48 ( V_261 ) ;
V_171 = V_23 -> V_80 ( V_2 , V_260 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
F_94 ( V_2 , & V_262 ) ;
V_171 = V_23 -> V_166 ( V_2 , V_260 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = V_23 -> V_80 ( V_2 , V_263 , & V_262 , sizeof V_262 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_259 != 0xffff ) {
V_262 . V_264 = V_259 ;
V_171 = V_23 -> V_166 ( V_2 , V_263 ,
& V_262 . V_264 ,
sizeof V_262 . V_264 ,
& V_2 -> V_41 ) ;
if ( V_171 != V_76 )
return V_171 ;
}
return F_95 ( V_2 , & V_262 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
T_2 V_258 , int V_280 ,
bool V_281 , T_1 V_43 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
struct V_28 V_282 , V_283 ;
int V_171 ;
T_2 V_259 = F_19 ( V_2 , V_176 ) ;
T_3 V_260 =
V_23 -> V_38 ( V_2 , V_176 ) ;
T_1 V_284 ;
V_171 = F_49 ( V_2 , V_258 , & V_283 ) ;
if ( V_171 != V_76 )
return V_171 ;
V_171 = F_49 ( V_2 , V_259 , & V_282 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_280 != V_285 ) {
if ( ( V_258 & 3 ) > V_283 . V_75 ||
V_23 -> V_69 ( V_2 ) > V_283 . V_75 )
return F_13 ( V_2 , 0 ) ;
}
V_284 = F_7 ( & V_283 ) ;
if ( ! V_283 . V_92 ||
( ( V_284 < 0x67 && ( V_283 . type & 8 ) ) ||
V_284 < 0x2b ) ) {
F_16 ( V_2 , V_258 & 0xfffc ) ;
return V_45 ;
}
if ( V_280 == V_285 || V_280 == V_286 ) {
V_282 . type &= ~ ( 1 << 1 ) ;
F_50 ( V_2 , V_259 , & V_282 ) ;
}
if ( V_280 == V_285 )
V_2 -> V_158 = V_2 -> V_158 & ~ V_287 ;
if ( V_280 != V_288 && V_280 != V_289 )
V_259 = 0xffff ;
if ( V_283 . type & 8 )
V_171 = F_96 ( V_2 , V_258 , V_259 ,
V_260 , & V_283 ) ;
else
V_171 = F_93 ( V_2 , V_258 , V_259 ,
V_260 , & V_283 ) ;
if ( V_171 != V_76 )
return V_171 ;
if ( V_280 == V_288 || V_280 == V_289 )
V_2 -> V_158 = V_2 -> V_158 | V_287 ;
if ( V_280 != V_285 ) {
V_283 . type |= ( 1 << 1 ) ;
F_50 ( V_2 , V_258 , & V_283 ) ;
}
V_23 -> V_279 ( V_2 , 0 , V_23 -> V_267 ( V_2 , 0 ) | V_290 ) ;
V_23 -> V_58 ( V_2 , V_258 , & V_283 , 0 , V_176 ) ;
if ( V_281 ) {
V_2 -> V_94 = V_2 -> V_20 = ( V_283 . type & 8 ) ? 4 : 2 ;
V_2 -> V_178 = 0 ;
V_2 -> V_14 . V_104 = ( unsigned long ) V_43 ;
V_171 = F_56 ( V_2 ) ;
}
return V_171 ;
}
int F_98 ( struct V_1 * V_2 ,
T_2 V_258 , int V_280 ,
bool V_281 , T_1 V_43 )
{
int V_79 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_179 ;
V_79 = F_97 ( V_2 , V_258 , V_280 ,
V_281 , V_43 ) ;
if ( V_79 == V_76 )
V_2 -> V_22 = V_2 -> V_27 ;
return ( V_79 == V_89 ) ? V_291 : V_292 ;
}
static void F_99 ( struct V_1 * V_2 , unsigned V_32 ,
int V_24 , struct V_102 * V_103 )
{
int V_293 = ( V_2 -> V_158 & V_159 ) ? - 1 : 1 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_24 ] , V_293 * V_103 -> V_17 ) ;
V_103 -> V_60 . V_139 . V_71 = F_4 ( V_2 , V_2 -> V_90 [ V_24 ] ) ;
V_103 -> V_60 . V_139 . V_32 = V_32 ;
}
static int F_100 ( struct V_1 * V_2 )
{
T_4 V_294 , V_295 ;
bool V_296 , V_297 , V_298 ;
V_297 = V_2 -> V_158 & V_299 ;
V_294 = V_2 -> V_19 . V_104 ;
V_295 = V_294 ;
V_298 = V_297 ;
V_297 = false ;
V_296 = V_2 -> V_158 & V_300 ;
if ( ( V_294 & 0x0f ) > 9 || V_296 ) {
V_294 -= 6 ;
V_297 = V_298 | ( V_294 >= 250 ) ;
V_296 = true ;
} else {
V_296 = false ;
}
if ( V_295 > 0x99 || V_298 ) {
V_294 -= 0x60 ;
V_297 = true ;
}
V_2 -> V_19 . V_104 = V_294 ;
V_2 -> V_14 . type = V_301 ;
V_2 -> V_14 . V_104 = 0 ;
V_2 -> V_14 . V_17 = 1 ;
F_75 ( L_16 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
V_2 -> V_158 &= ~ ( V_300 | V_299 ) ;
if ( V_297 )
V_2 -> V_158 |= V_299 ;
if ( V_296 )
V_2 -> V_158 |= V_300 ;
return V_76 ;
}
static int F_101 ( struct V_1 * V_2 )
{
T_2 V_68 , V_302 ;
T_3 V_216 ;
int V_79 ;
V_302 = F_19 ( V_2 , V_86 ) ;
V_216 = V_2 -> V_27 ;
memcpy ( & V_68 , V_2 -> V_14 . V_211 + V_2 -> V_94 , 2 ) ;
if ( F_51 ( V_2 , V_68 , V_86 ) )
return V_76 ;
V_2 -> V_27 = 0 ;
memcpy ( & V_2 -> V_27 , V_2 -> V_14 . V_211 , V_2 -> V_94 ) ;
V_2 -> V_14 . V_104 = V_302 ;
V_79 = F_56 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_14 . V_104 = V_216 ;
return F_56 ( V_2 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_79 ;
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_27 ;
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_79 = F_57 ( V_2 , & V_2 -> V_19 . V_104 , V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_180 ] , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_103 ( struct V_1 * V_2 )
{
F_75 ( L_17 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_104 ( struct V_1 * V_2 )
{
F_75 ( L_16 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_105 ( struct V_1 * V_2 )
{
F_75 ( L_18 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_106 ( struct V_1 * V_2 )
{
F_75 ( L_19 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_107 ( struct V_1 * V_2 )
{
F_75 ( L_20 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_108 ( struct V_1 * V_2 )
{
F_75 ( L_21 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_109 ( struct V_1 * V_2 )
{
F_75 ( L_22 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_110 ( struct V_1 * V_2 )
{
F_75 ( L_23 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_111 ( struct V_1 * V_2 )
{
F_75 ( L_8 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_112 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_104 = V_2 -> V_19 . V_104 ;
F_54 ( & V_2 -> V_14 ) ;
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_118 ;
V_2 -> V_178 = 1 ;
return V_76 ;
}
static int F_113 ( struct V_1 * V_2 )
{
F_114 ( L_11 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
return V_76 ;
}
static int F_115 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_104 = V_2 -> V_303 . V_104 ;
return F_113 ( V_2 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_17 = V_2 -> V_14 . V_17 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_90 [ V_214 ] ;
V_2 -> V_19 . V_104 = ~ ( ( V_2 -> V_14 . V_104 >> ( V_2 -> V_14 . V_17 * 8 - 1 ) ) - 1 ) ;
return V_76 ;
}
static int F_117 ( struct V_1 * V_2 )
{
V_105 V_304 = 0 ;
V_2 -> V_23 -> V_225 ( V_2 , V_305 , & V_304 ) ;
V_2 -> V_90 [ V_197 ] = ( T_1 ) V_304 ;
V_2 -> V_90 [ V_214 ] = V_304 >> 32 ;
return V_76 ;
}
static int F_118 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_104 ;
return V_76 ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 > V_172 )
return F_15 ( V_2 ) ;
V_2 -> V_19 . V_104 = F_19 ( V_2 , V_2 -> V_11 ) ;
return V_76 ;
}
static int F_120 ( struct V_1 * V_2 )
{
T_2 V_68 = V_2 -> V_14 . V_104 ;
if ( V_2 -> V_11 == V_86 || V_2 -> V_11 > V_172 )
return F_15 ( V_2 ) ;
if ( V_2 -> V_11 == V_77 )
V_2 -> V_306 = V_307 ;
V_2 -> V_19 . type = V_179 ;
return F_51 ( V_2 , V_68 , V_2 -> V_11 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
memcpy ( & V_2 -> V_19 . V_115 , & V_2 -> V_14 . V_115 , V_2 -> V_94 ) ;
return V_76 ;
}
static int F_122 ( struct V_1 * V_2 )
{
int V_79 ;
T_3 V_64 ;
V_79 = F_23 ( V_2 , V_2 -> V_14 . V_60 . V_139 , 1 , false , & V_64 ) ;
if ( V_79 == V_76 )
V_2 -> V_23 -> V_308 ( V_2 , V_64 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_123 ( struct V_1 * V_2 )
{
T_3 V_309 ;
V_309 = V_2 -> V_23 -> V_267 ( V_2 , 0 ) ;
V_309 &= ~ V_290 ;
V_2 -> V_23 -> V_279 ( V_2 , 0 , V_309 ) ;
return V_76 ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_79 ;
if ( V_2 -> V_10 != 3 || V_2 -> V_12 != 1 )
return V_89 ;
V_79 = V_2 -> V_23 -> V_310 ( V_2 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_160 V_160 ;
int V_79 ;
V_79 = F_30 ( V_2 , V_2 -> V_14 . V_60 . V_139 ,
& V_160 . V_61 , & V_160 . V_93 ,
V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_23 -> V_311 ( V_2 , & V_160 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_126 ( struct V_1 * V_2 )
{
int V_79 ;
V_79 = V_2 -> V_23 -> V_310 ( V_2 ) ;
V_2 -> V_19 . type = V_179 ;
return V_79 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_160 V_160 ;
int V_79 ;
V_79 = F_30 ( V_2 , V_2 -> V_14 . V_60 . V_139 ,
& V_160 . V_61 , & V_160 . V_93 ,
V_2 -> V_94 ) ;
if ( V_79 != V_76 )
return V_79 ;
V_2 -> V_23 -> V_312 ( V_2 , & V_160 ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_128 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = 2 ;
V_2 -> V_19 . V_104 = V_2 -> V_23 -> V_267 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_129 ( struct V_1 * V_2 )
{
V_2 -> V_23 -> V_279 ( V_2 , 0 , ( V_2 -> V_23 -> V_267 ( V_2 , 0 ) & ~ 0x0eul )
| ( V_2 -> V_14 . V_104 & 0x0f ) ) ;
V_2 -> V_19 . type = V_179 ;
return V_76 ;
}
static int F_130 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_90 [ V_157 ] , - 1 ) ;
if ( ( F_3 ( V_2 , V_2 -> V_90 [ V_157 ] ) != 0 ) &&
( V_2 -> V_111 == 0xe2 || F_31 ( V_2 -> V_111 ^ 0x5 , V_2 -> V_158 ) ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_131 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 , V_2 -> V_90 [ V_157 ] ) == 0 )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
return V_76 ;
}
static int F_132 ( struct V_1 * V_2 )
{
if ( F_88 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_158 &= ~ V_313 ;
return V_76 ;
}
static int F_133 ( struct V_1 * V_2 )
{
if ( F_88 ( V_2 ) )
return F_13 ( V_2 , 0 ) ;
V_2 -> V_306 = V_314 ;
V_2 -> V_158 |= V_313 ;
return V_76 ;
}
static bool F_134 ( int V_315 )
{
switch ( V_315 ) {
case 0 :
case 2 ... 4 :
case 8 :
return true ;
default:
return false ;
}
}
static int F_135 ( struct V_1 * V_2 )
{
if ( ! F_134 ( V_2 -> V_11 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_136 ( struct V_1 * V_2 )
{
V_105 V_316 = V_2 -> V_14 . V_15 ;
int V_317 = V_2 -> V_11 ;
V_105 V_224 = 0 ;
static V_105 V_318 [] = {
0xffffffff00000000ULL ,
0 , 0 , 0 ,
V_319 ,
0 , 0 , 0 ,
V_320 ,
} ;
if ( ! F_134 ( V_317 ) )
return F_15 ( V_2 ) ;
if ( V_316 & V_318 [ V_317 ] )
return F_13 ( V_2 , 0 ) ;
switch ( V_317 ) {
case 0 : {
V_105 V_321 ;
if ( ( ( V_316 & V_322 ) && ! ( V_316 & V_323 ) ) ||
( ( V_316 & V_324 ) && ! ( V_316 & V_325 ) ) )
return F_13 ( V_2 , 0 ) ;
V_321 = V_2 -> V_23 -> V_267 ( V_2 , 4 ) ;
V_2 -> V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
if ( ( V_316 & V_322 ) && ( V_224 & V_326 ) &&
! ( V_321 & V_327 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
case 3 : {
V_105 V_328 = 0 ;
V_2 -> V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
if ( V_224 & V_228 )
V_328 = V_329 ;
else if ( V_2 -> V_23 -> V_267 ( V_2 , 4 ) & V_327 )
V_328 = V_330 ;
else if ( V_2 -> V_23 -> V_267 ( V_2 , 0 ) & V_322 )
V_328 = V_331 ;
if ( V_316 & V_328 )
return F_13 ( V_2 , 0 ) ;
break;
}
case 4 : {
V_105 V_321 ;
V_321 = V_2 -> V_23 -> V_267 ( V_2 , 4 ) ;
V_2 -> V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
if ( ( V_224 & V_228 ) && ! ( V_316 & V_327 ) )
return F_13 ( V_2 , 0 ) ;
break;
}
}
return V_76 ;
}
static int F_137 ( struct V_1 * V_2 )
{
unsigned long V_332 ;
V_2 -> V_23 -> V_333 ( V_2 , 7 , & V_332 ) ;
return V_332 & ( 1 << 13 ) ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_334 = V_2 -> V_11 ;
V_105 V_321 ;
if ( V_334 > 7 )
return F_15 ( V_2 ) ;
V_321 = V_2 -> V_23 -> V_267 ( V_2 , 4 ) ;
if ( ( V_321 & V_335 ) && ( V_334 == 4 || V_334 == 5 ) )
return F_15 ( V_2 ) ;
if ( F_137 ( V_2 ) )
return F_12 ( V_2 ) ;
return V_76 ;
}
static int F_139 ( struct V_1 * V_2 )
{
V_105 V_316 = V_2 -> V_14 . V_15 ;
int V_334 = V_2 -> V_11 ;
if ( ( V_334 == 6 || V_334 == 7 ) && ( V_316 & 0xffffffff00000000ULL ) )
return F_13 ( V_2 , 0 ) ;
return F_138 ( V_2 ) ;
}
static int F_140 ( struct V_1 * V_2 )
{
V_105 V_224 ;
V_2 -> V_23 -> V_225 ( V_2 , V_226 , & V_224 ) ;
if ( ! ( V_224 & V_336 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_141 ( struct V_1 * V_2 )
{
V_105 V_212 = V_2 -> V_90 [ V_197 ] ;
if ( V_212 & 0xffff000000000000ULL )
return F_13 ( V_2 , 0 ) ;
return F_140 ( V_2 ) ;
}
static int F_142 ( struct V_1 * V_2 )
{
V_105 V_321 = V_2 -> V_23 -> V_267 ( V_2 , 4 ) ;
if ( V_321 & V_337 && V_2 -> V_23 -> V_69 ( V_2 ) )
return F_15 ( V_2 ) ;
return V_76 ;
}
static int F_143 ( struct V_1 * V_2 )
{
V_105 V_321 = V_2 -> V_23 -> V_267 ( V_2 , 4 ) ;
V_105 V_338 = V_2 -> V_90 [ V_157 ] ;
if ( ( ! ( V_321 & V_339 ) && V_2 -> V_23 -> V_69 ( V_2 ) ) ||
( V_338 > 3 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_144 ( struct V_1 * V_2 )
{
V_2 -> V_19 . V_17 = F_26 ( V_2 -> V_19 . V_17 , 4u ) ;
if ( ! F_90 ( V_2 , V_2 -> V_14 . V_104 , V_2 -> V_19 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static int F_145 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_17 = F_26 ( V_2 -> V_14 . V_17 , 4u ) ;
if ( ! F_90 ( V_2 , V_2 -> V_19 . V_104 , V_2 -> V_14 . V_17 ) )
return F_13 ( V_2 , 0 ) ;
return V_76 ;
}
static unsigned F_146 ( struct V_1 * V_2 )
{
unsigned V_61 ;
V_61 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
if ( V_61 == 8 )
V_61 = 4 ;
return V_61 ;
}
static int F_147 ( struct V_1 * V_2 , struct V_102 * V_103 ,
unsigned V_61 , bool V_340 )
{
int V_79 = V_76 ;
V_103 -> type = V_301 ;
V_103 -> V_17 = V_61 ;
V_103 -> V_60 . V_139 . V_71 = V_2 -> V_27 ;
switch ( V_103 -> V_17 ) {
case 1 :
V_103 -> V_104 = F_39 ( V_136 , 1 , V_2 -> V_27 ) ;
break;
case 2 :
V_103 -> V_104 = F_39 ( V_143 , 2 , V_2 -> V_27 ) ;
break;
case 4 :
V_103 -> V_104 = F_39 ( V_137 , 4 , V_2 -> V_27 ) ;
break;
}
if ( ! V_340 ) {
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
V_140:
return V_79 ;
}
int F_148 ( struct V_1 * V_2 , void * V_341 , int V_342 )
{
int V_79 = V_76 ;
int V_35 = V_2 -> V_35 ;
int V_343 , V_344 , V_345 , V_346 ;
bool V_347 = false ;
struct V_348 V_348 ;
struct V_102 V_349 = { . type = V_179 } , * V_350 = NULL ;
V_2 -> V_27 = V_2 -> V_22 ;
V_2 -> V_63 . V_87 = V_2 -> V_27 ;
V_2 -> V_63 . V_85 = V_2 -> V_63 . V_87 + V_342 ;
if ( V_342 > 0 )
memcpy ( V_2 -> V_63 . V_78 , V_341 , V_342 ) ;
switch ( V_35 ) {
case V_72 :
case V_173 :
case V_193 :
V_343 = V_344 = 2 ;
break;
case V_192 :
V_343 = V_344 = 4 ;
break;
#ifdef F_34
case V_36 :
V_343 = 4 ;
V_344 = 8 ;
break;
#endif
default:
return - 1 ;
}
V_2 -> V_94 = V_343 ;
V_2 -> V_20 = V_344 ;
for (; ; ) {
switch ( V_2 -> V_111 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ) {
case 0x66 :
V_347 = true ;
V_2 -> V_94 = V_343 ^ 6 ;
break;
case 0x67 :
if ( V_35 == V_36 )
V_2 -> V_20 = V_344 ^ 12 ;
else
V_2 -> V_20 = V_344 ^ 6 ;
break;
case 0x26 :
case 0x2e :
case 0x36 :
case 0x3e :
F_9 ( V_2 , ( V_2 -> V_111 >> 3 ) & 3 ) ;
break;
case 0x64 :
case 0x65 :
F_9 ( V_2 , V_2 -> V_111 & 7 ) ;
break;
case 0x40 ... 0x4f :
if ( V_35 != V_36 )
goto V_351;
V_2 -> V_109 = V_2 -> V_111 ;
continue;
case 0xf0 :
V_2 -> V_178 = 1 ;
break;
case 0xf2 :
case 0xf3 :
V_2 -> V_9 = V_2 -> V_111 ;
break;
default:
goto V_351;
}
V_2 -> V_109 = 0 ;
}
V_351:
if ( V_2 -> V_109 & 8 )
V_2 -> V_94 = 8 ;
V_348 = V_352 [ V_2 -> V_111 ] ;
if ( V_2 -> V_111 == 0x0f ) {
V_2 -> V_353 = 1 ;
V_2 -> V_111 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
V_348 = V_354 [ V_2 -> V_111 ] ;
}
V_2 -> V_74 = V_348 . V_96 ;
while ( V_2 -> V_74 & V_355 ) {
switch ( V_2 -> V_74 & V_355 ) {
case V_356 :
V_2 -> V_124 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
-- V_2 -> V_27 ;
V_345 = ( V_2 -> V_124 >> 3 ) & 7 ;
V_348 = V_348 . V_357 . V_358 [ V_345 ] ;
break;
case V_359 :
V_2 -> V_124 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
-- V_2 -> V_27 ;
V_345 = ( V_2 -> V_124 >> 3 ) & 7 ;
if ( ( V_2 -> V_124 >> 6 ) == 3 )
V_348 = V_348 . V_357 . V_360 -> V_361 [ V_345 ] ;
else
V_348 = V_348 . V_357 . V_360 -> V_362 [ V_345 ] ;
break;
case V_363 :
V_345 = V_2 -> V_124 & 7 ;
V_348 = V_348 . V_357 . V_358 [ V_345 ] ;
break;
case V_364 :
if ( V_2 -> V_9 && V_347 )
return V_89 ;
V_346 = V_347 ? 0x66 : V_2 -> V_9 ;
switch ( V_346 ) {
case 0x00 : V_348 = V_348 . V_357 . V_365 -> V_366 ; break;
case 0x66 : V_348 = V_348 . V_357 . V_365 -> V_367 ; break;
case 0xf2 : V_348 = V_348 . V_357 . V_365 -> V_368 ; break;
case 0xf3 : V_348 = V_348 . V_357 . V_365 -> V_369 ; break;
}
break;
default:
return V_89 ;
}
V_2 -> V_74 &= ~ V_355 ;
V_2 -> V_74 |= V_348 . V_96 ;
}
V_2 -> V_370 = V_348 . V_357 . V_370 ;
V_2 -> V_371 = V_348 . V_371 ;
V_2 -> V_4 = V_348 . V_4 ;
if ( V_2 -> V_74 == 0 || ( V_2 -> V_74 & V_372 ) )
return - 1 ;
if ( ! ( V_2 -> V_74 & V_373 ) && V_2 -> V_374 )
return - 1 ;
if ( V_35 == V_36 && ( V_2 -> V_74 & V_375 ) )
V_2 -> V_94 = 8 ;
if ( V_2 -> V_74 & V_376 ) {
if ( V_35 == V_36 )
V_2 -> V_94 = 8 ;
else
V_2 -> V_94 = 4 ;
}
if ( V_2 -> V_74 & V_112 )
V_2 -> V_94 = 16 ;
if ( V_2 -> V_74 & V_110 ) {
V_79 = F_38 ( V_2 , & V_349 ) ;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_2 -> V_125 ) ;
} else if ( V_2 -> V_74 & V_377 )
V_79 = F_40 ( V_2 , & V_349 ) ;
if ( V_79 != V_76 )
goto V_140;
if ( ! V_2 -> V_33 )
F_9 ( V_2 , V_126 ) ;
V_349 . V_60 . V_139 . V_32 = V_34 ( V_2 ) ;
if ( V_349 . type == V_127 && V_2 -> V_20 != 8 )
V_349 . V_60 . V_139 . V_71 = ( T_1 ) V_349 . V_60 . V_139 . V_71 ;
switch ( V_2 -> V_74 & V_378 ) {
case V_379 :
break;
case V_380 :
F_37 ( V_2 , & V_2 -> V_14 , 0 ) ;
break;
case V_381 :
V_349 . V_17 = 2 ;
goto V_382;
case V_383 :
V_349 . V_17 = 4 ;
goto V_382;
case V_384 :
V_349 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 :
V_2 -> V_94 ;
V_382:
V_2 -> V_14 = V_349 ;
V_350 = & V_2 -> V_14 ;
break;
case V_385 :
V_79 = F_147 ( V_2 , & V_2 -> V_14 , 2 , false ) ;
break;
case V_386 :
V_79 = F_147 ( V_2 , & V_2 -> V_14 , F_146 ( V_2 ) , true ) ;
break;
case V_387 :
V_79 = F_147 ( V_2 , & V_2 -> V_14 , F_146 ( V_2 ) , false ) ;
break;
case V_388 :
V_79 = F_147 ( V_2 , & V_2 -> V_14 , 1 , true ) ;
break;
case V_389 :
V_79 = F_147 ( V_2 , & V_2 -> V_14 , 1 , false ) ;
break;
case V_390 :
V_2 -> V_14 . type = V_116 ;
V_2 -> V_14 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
V_2 -> V_14 . V_60 . V_24 = & V_2 -> V_90 [ V_197 ] ;
F_32 ( & V_2 -> V_14 ) ;
break;
case V_391 :
V_2 -> V_14 . V_17 = 1 ;
V_2 -> V_14 . V_104 = 1 ;
break;
case V_392 :
V_2 -> V_14 . type = V_127 ;
V_2 -> V_14 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
V_2 -> V_14 . V_60 . V_139 . V_71 =
F_4 ( V_2 , V_2 -> V_90 [ V_133 ] ) ;
V_2 -> V_14 . V_60 . V_139 . V_32 = V_34 ( V_2 ) ;
V_2 -> V_14 . V_104 = 0 ;
break;
case V_393 :
V_2 -> V_14 . type = V_301 ;
V_2 -> V_14 . V_60 . V_139 . V_71 = V_2 -> V_27 ;
V_2 -> V_14 . V_17 = V_2 -> V_94 + 2 ;
F_149 ( V_2 -> V_14 . V_211 , V_2 -> V_14 . V_17 , V_2 -> V_27 ) ;
break;
case V_394 :
V_349 . V_17 = V_2 -> V_94 + 2 ;
goto V_382;
break;
case V_395 :
V_2 -> V_14 . type = V_116 ;
V_2 -> V_14 . V_17 = 2 ;
V_2 -> V_14 . V_60 . V_24 = & V_2 -> V_90 [ V_214 ] ;
F_32 ( & V_2 -> V_14 ) ;
break;
}
if ( V_79 != V_76 )
goto V_140;
switch ( V_2 -> V_74 & V_396 ) {
case V_397 :
break;
case V_398 :
V_2 -> V_303 . V_17 = 1 ;
V_2 -> V_303 . V_104 = V_2 -> V_90 [ V_157 ] & 0xff ;
break;
case V_399 :
V_79 = F_147 ( V_2 , & V_2 -> V_303 , 1 , true ) ;
break;
case V_400 :
V_2 -> V_303 . V_17 = 1 ;
V_2 -> V_303 . V_104 = 1 ;
break;
case V_401 :
V_79 = F_147 ( V_2 , & V_2 -> V_303 , F_146 ( V_2 ) , true ) ;
break;
}
if ( V_79 != V_76 )
goto V_140;
switch ( V_2 -> V_74 & V_402 ) {
case V_403 :
F_37 ( V_2 , & V_2 -> V_19 ,
V_2 -> V_353 && ( V_2 -> V_111 == 0xb6 || V_2 -> V_111 == 0xb7 ) ) ;
break;
case V_404 :
V_2 -> V_19 . type = V_301 ;
V_2 -> V_19 . V_60 . V_139 . V_71 = V_2 -> V_27 ;
V_2 -> V_19 . V_17 = 1 ;
V_2 -> V_19 . V_104 = F_39 ( T_4 , 1 , V_2 -> V_27 ) ;
break;
case V_405 :
case V_406 :
V_2 -> V_19 = V_349 ;
V_350 = & V_2 -> V_19 ;
if ( ( V_2 -> V_74 & V_402 ) == V_406 )
V_2 -> V_19 . V_17 = 8 ;
else
V_2 -> V_19 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
if ( V_2 -> V_74 & V_407 )
F_41 ( V_2 ) ;
V_2 -> V_19 . V_118 = V_2 -> V_19 . V_104 ;
break;
case V_408 :
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_90 [ V_197 ] ;
F_32 ( & V_2 -> V_19 ) ;
V_2 -> V_19 . V_118 = V_2 -> V_19 . V_104 ;
break;
case V_409 :
V_2 -> V_19 . type = V_127 ;
V_2 -> V_19 . V_17 = ( V_2 -> V_74 & V_117 ) ? 1 : V_2 -> V_94 ;
V_2 -> V_19 . V_60 . V_139 . V_71 =
F_4 ( V_2 , V_2 -> V_90 [ V_135 ] ) ;
V_2 -> V_19 . V_60 . V_139 . V_32 = V_255 ;
V_2 -> V_19 . V_104 = 0 ;
break;
case V_410 :
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_17 = 2 ;
V_2 -> V_19 . V_60 . V_24 = & V_2 -> V_90 [ V_214 ] ;
F_32 ( & V_2 -> V_19 ) ;
break;
case V_411 :
default:
V_2 -> V_19 . type = V_179 ;
break;
}
V_140:
if ( V_350 && V_350 -> type == V_127 && V_2 -> V_138 )
V_350 -> V_60 . V_139 . V_71 += V_2 -> V_27 ;
return ( V_79 == V_89 ) ? V_291 : V_292 ;
}
static bool F_150 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_111 == 0xa6 ) || ( V_2 -> V_111 == 0xa7 ) ||
( V_2 -> V_111 == 0xae ) || ( V_2 -> V_111 == 0xaf ) )
&& ( ( ( V_2 -> V_9 == V_412 ) &&
( ( V_2 -> V_158 & V_99 ) == 0 ) )
|| ( ( V_2 -> V_9 == V_413 ) &&
( ( V_2 -> V_158 & V_99 ) == V_99 ) ) ) )
return true ;
return false ;
}
int F_151 ( struct V_1 * V_2 )
{
struct V_162 * V_23 = V_2 -> V_23 ;
V_105 V_221 ;
int V_79 = V_76 ;
int V_414 = V_2 -> V_19 . type ;
V_2 -> V_146 . V_148 = 0 ;
if ( V_2 -> V_35 == V_36 && ( V_2 -> V_74 & V_415 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_140;
}
if ( V_2 -> V_178 && ( ! ( V_2 -> V_74 & V_416 ) || V_2 -> V_19 . type != V_127 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_140;
}
if ( ( V_2 -> V_74 & V_378 ) == V_394 && V_2 -> V_14 . type != V_127 ) {
V_79 = F_15 ( V_2 ) ;
goto V_140;
}
if ( ( V_2 -> V_74 & V_112 )
&& ( ( V_23 -> V_267 ( V_2 , 0 ) & V_417 )
|| ! ( V_23 -> V_267 ( V_2 , 4 ) & V_418 ) ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_140;
}
if ( ( V_2 -> V_74 & V_112 ) && ( V_23 -> V_267 ( V_2 , 0 ) & V_290 ) ) {
V_79 = F_18 ( V_2 ) ;
goto V_140;
}
if ( F_152 ( V_2 -> V_419 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_420 ) ;
if ( V_79 != V_76 )
goto V_140;
}
if ( ( V_2 -> V_74 & V_421 ) && V_23 -> V_69 ( V_2 ) ) {
V_79 = F_13 ( V_2 , 0 ) ;
goto V_140;
}
if ( ( V_2 -> V_74 & V_422 ) && ! ( V_2 -> V_35 & V_423 ) ) {
V_79 = F_15 ( V_2 ) ;
goto V_140;
}
if ( V_2 -> V_371 ) {
V_79 = V_2 -> V_371 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_140;
}
if ( F_152 ( V_2 -> V_419 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_424 ) ;
if ( V_79 != V_76 )
goto V_140;
}
if ( V_2 -> V_9 && ( V_2 -> V_74 & String ) ) {
if ( F_3 ( V_2 , V_2 -> V_90 [ V_157 ] ) == 0 ) {
V_2 -> V_22 = V_2 -> V_27 ;
goto V_140;
}
}
if ( ( V_2 -> V_14 . type == V_127 ) && ! ( V_2 -> V_74 & V_425 ) ) {
V_79 = F_43 ( V_2 , V_2 -> V_14 . V_60 . V_139 ,
V_2 -> V_14 . V_211 , V_2 -> V_14 . V_17 ) ;
if ( V_79 != V_76 )
goto V_140;
V_2 -> V_14 . V_218 = V_2 -> V_14 . V_15 ;
}
if ( V_2 -> V_303 . type == V_127 ) {
V_79 = F_43 ( V_2 , V_2 -> V_303 . V_60 . V_139 ,
& V_2 -> V_303 . V_104 , V_2 -> V_303 . V_17 ) ;
if ( V_79 != V_76 )
goto V_140;
}
if ( ( V_2 -> V_74 & V_402 ) == V_411 )
goto V_426;
if ( ( V_2 -> V_19 . type == V_127 ) && ! ( V_2 -> V_74 & V_427 ) ) {
V_79 = F_43 ( V_2 , V_2 -> V_19 . V_60 . V_139 ,
& V_2 -> V_19 . V_104 , V_2 -> V_19 . V_17 ) ;
if ( V_79 != V_76 )
goto V_140;
}
V_2 -> V_19 . V_118 = V_2 -> V_19 . V_104 ;
V_426:
if ( F_152 ( V_2 -> V_419 ) && V_2 -> V_4 ) {
V_79 = F_1 ( V_2 , V_2 -> V_4 ,
V_428 ) ;
if ( V_79 != V_76 )
goto V_140;
}
if ( V_2 -> V_370 ) {
V_79 = V_2 -> V_370 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_140;
goto F_55;
}
if ( V_2 -> V_353 )
goto V_429;
switch ( V_2 -> V_111 ) {
case 0x06 :
V_79 = F_61 ( V_2 , V_255 ) ;
break;
case 0x07 :
V_79 = F_62 ( V_2 , V_255 ) ;
break;
case 0x0e :
V_79 = F_61 ( V_2 , V_86 ) ;
break;
case 0x16 :
V_79 = F_61 ( V_2 , V_77 ) ;
break;
case 0x17 :
V_79 = F_62 ( V_2 , V_77 ) ;
break;
case 0x1e :
V_79 = F_61 ( V_2 , V_126 ) ;
break;
case 0x1f :
V_79 = F_62 ( V_2 , V_126 ) ;
break;
case 0x40 ... 0x47 :
F_76 ( L_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0x48 ... 0x4f :
F_76 ( L_15 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0x63 :
if ( V_2 -> V_35 != V_36 )
goto V_430;
V_2 -> V_19 . V_104 = ( V_137 ) V_2 -> V_14 . V_104 ;
break;
case 0x6c :
case 0x6d :
V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_214 ] ;
goto V_431;
case 0x6e :
case 0x6f :
V_2 -> V_19 . V_104 = V_2 -> V_90 [ V_214 ] ;
goto V_432;
break;
case 0x70 ... 0x7f :
if ( F_31 ( V_2 -> V_111 , V_2 -> V_158 ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0x8d :
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_60 . V_139 . V_71 ;
break;
case 0x8f :
V_79 = F_71 ( V_2 ) ;
break;
case 0x90 ... 0x97 :
if ( V_2 -> V_19 . V_60 . V_24 == & V_2 -> V_90 [ V_197 ] )
break;
V_79 = F_112 ( V_2 ) ;
break;
case 0x98 :
switch ( V_2 -> V_94 ) {
case 2 : V_2 -> V_19 . V_104 = ( V_136 ) V_2 -> V_19 . V_104 ; break;
case 4 : V_2 -> V_19 . V_104 = ( V_143 ) V_2 -> V_19 . V_104 ; break;
case 8 : V_2 -> V_19 . V_104 = ( V_137 ) V_2 -> V_19 . V_104 ; break;
}
break;
case 0xc0 ... 0xc1 :
V_79 = F_72 ( V_2 ) ;
break;
case 0xc4 :
V_79 = F_83 ( V_2 , V_255 ) ;
break;
case 0xc5 :
V_79 = F_83 ( V_2 , V_126 ) ;
break;
case 0xcc :
V_79 = F_67 ( V_2 , 3 ) ;
break;
case 0xcd :
V_79 = F_67 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0xce :
if ( V_2 -> V_158 & V_97 )
V_79 = F_67 ( V_2 , 4 ) ;
break;
case 0xd0 ... 0xd1 :
V_79 = F_72 ( V_2 ) ;
break;
case 0xd2 ... 0xd3 :
V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_157 ] ;
V_79 = F_72 ( V_2 ) ;
break;
case 0xe4 :
case 0xe5 :
goto V_431;
case 0xe6 :
case 0xe7 :
goto V_432;
case 0xe8 : {
long int V_26 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = ( unsigned long ) V_2 -> V_27 ;
F_6 ( V_2 , V_26 ) ;
V_79 = F_56 ( V_2 ) ;
break;
}
case 0xe9 :
case 0xeb :
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
V_2 -> V_19 . type = V_179 ;
break;
case 0xec :
case 0xed :
V_431:
if ( ! F_46 ( V_2 , V_2 -> V_19 . V_17 , V_2 -> V_14 . V_104 ,
& V_2 -> V_19 . V_104 ) )
goto V_140;
break;
case 0xee :
case 0xef :
V_432:
V_23 -> V_433 ( V_2 , V_2 -> V_14 . V_17 , V_2 -> V_19 . V_104 ,
& V_2 -> V_14 . V_104 , 1 ) ;
V_2 -> V_19 . type = V_179 ;
break;
case 0xf4 :
V_2 -> V_23 -> V_434 ( V_2 ) ;
break;
case 0xf5 :
V_2 -> V_158 ^= V_98 ;
break;
case 0xf6 ... 0xf7 :
V_79 = F_74 ( V_2 ) ;
break;
case 0xf8 :
V_2 -> V_158 &= ~ V_98 ;
break;
case 0xf9 :
V_2 -> V_158 |= V_98 ;
break;
case 0xfc :
V_2 -> V_158 &= ~ V_159 ;
break;
case 0xfd :
V_2 -> V_158 |= V_159 ;
break;
case 0xfe :
V_79 = F_79 ( V_2 ) ;
break;
case 0xff :
V_79 = F_79 ( V_2 ) ;
break;
default:
goto V_430;
}
if ( V_79 != V_76 )
goto V_140;
F_55:
V_79 = F_55 ( V_2 ) ;
if ( V_79 != V_76 )
goto V_140;
V_2 -> V_19 . type = V_414 ;
if ( ( V_2 -> V_74 & V_378 ) == V_392 )
F_99 ( V_2 , V_34 ( V_2 ) ,
V_133 , & V_2 -> V_14 ) ;
if ( ( V_2 -> V_74 & V_402 ) == V_409 )
F_99 ( V_2 , V_255 , V_135 ,
& V_2 -> V_19 ) ;
if ( V_2 -> V_9 && ( V_2 -> V_74 & String ) ) {
struct V_144 * V_239 = & V_2 -> V_154 ;
F_5 ( V_2 , & V_2 -> V_90 [ V_157 ] , - 1 ) ;
if ( ! F_150 ( V_2 ) ) {
if ( ( V_239 -> V_85 != 0 || V_2 -> V_90 [ V_157 ] & 0x3ff ) &&
( V_239 -> V_85 == 0 || V_239 -> V_85 != V_239 -> V_148 ) ) {
V_2 -> V_146 . V_85 = 0 ;
return V_435 ;
}
goto V_140;
}
}
V_2 -> V_22 = V_2 -> V_27 ;
V_140:
if ( V_79 == V_45 )
V_2 -> V_436 = true ;
if ( V_79 == V_437 )
return V_438 ;
return ( V_79 == V_89 ) ? V_291 : V_292 ;
V_429:
switch ( V_2 -> V_111 ) {
case 0x09 :
( V_2 -> V_23 -> V_439 ) ( V_2 ) ;
break;
case 0x08 :
case 0x0d :
case 0x18 :
break;
case 0x20 :
V_2 -> V_19 . V_104 = V_23 -> V_267 ( V_2 , V_2 -> V_11 ) ;
break;
case 0x21 :
V_23 -> V_333 ( V_2 , V_2 -> V_11 , & V_2 -> V_19 . V_104 ) ;
break;
case 0x22 :
if ( V_23 -> V_279 ( V_2 , V_2 -> V_11 , V_2 -> V_14 . V_104 ) ) {
F_13 ( V_2 , 0 ) ;
V_79 = V_45 ;
goto V_140;
}
V_2 -> V_19 . type = V_179 ;
break;
case 0x23 :
if ( V_23 -> V_440 ( V_2 , V_2 -> V_11 , V_2 -> V_14 . V_104 &
( ( V_2 -> V_35 == V_36 ) ?
~ 0ULL : ~ 0U ) ) < 0 ) {
F_13 ( V_2 , 0 ) ;
V_79 = V_45 ;
goto V_140;
}
V_2 -> V_19 . type = V_179 ;
break;
case 0x30 :
V_221 = ( T_1 ) V_2 -> V_90 [ V_197 ]
| ( ( V_105 ) V_2 -> V_90 [ V_214 ] << 32 ) ;
if ( V_23 -> V_441 ( V_2 , V_2 -> V_90 [ V_157 ] , V_221 ) ) {
F_13 ( V_2 , 0 ) ;
V_79 = V_45 ;
goto V_140;
}
V_79 = V_76 ;
break;
case 0x32 :
if ( V_23 -> V_225 ( V_2 , V_2 -> V_90 [ V_157 ] , & V_221 ) ) {
F_13 ( V_2 , 0 ) ;
V_79 = V_45 ;
goto V_140;
} else {
V_2 -> V_90 [ V_197 ] = ( T_1 ) V_221 ;
V_2 -> V_90 [ V_214 ] = V_221 >> 32 ;
}
V_79 = V_76 ;
break;
case 0x40 ... 0x4f :
V_2 -> V_19 . V_104 = V_2 -> V_19 . V_118 = V_2 -> V_14 . V_104 ;
if ( ! F_31 ( V_2 -> V_111 , V_2 -> V_158 ) )
V_2 -> V_19 . type = V_179 ;
break;
case 0x80 ... 0x8f :
if ( F_31 ( V_2 -> V_111 , V_2 -> V_158 ) )
F_6 ( V_2 , V_2 -> V_14 . V_104 ) ;
break;
case 0x90 ... 0x9f :
V_2 -> V_19 . V_104 = F_31 ( V_2 -> V_111 , V_2 -> V_158 ) ;
break;
case 0xa0 :
V_79 = F_61 ( V_2 , V_37 ) ;
break;
case 0xa1 :
V_79 = F_62 ( V_2 , V_37 ) ;
break;
case 0xa3 :
V_442:
V_2 -> V_19 . type = V_179 ;
V_2 -> V_14 . V_104 &= ( V_2 -> V_19 . V_17 << 3 ) - 1 ;
F_114 ( L_24 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xa4 :
case 0xa5 :
F_153 ( L_25 , V_2 -> V_303 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xa8 :
V_79 = F_61 ( V_2 , V_172 ) ;
break;
case 0xa9 :
V_79 = F_62 ( V_2 , V_172 ) ;
break;
case 0xab :
V_443:
F_114 ( L_26 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xac :
case 0xad :
F_153 ( L_27 , V_2 -> V_303 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xae :
break;
case 0xb0 ... 0xb1 :
V_2 -> V_14 . V_118 = V_2 -> V_14 . V_104 ;
V_2 -> V_14 . V_104 = V_2 -> V_90 [ V_197 ] ;
F_75 ( L_23 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
if ( V_2 -> V_158 & V_99 ) {
V_2 -> V_19 . V_104 = V_2 -> V_14 . V_118 ;
} else {
V_2 -> V_19 . type = V_116 ;
V_2 -> V_19 . V_60 . V_24 = ( unsigned long * ) & V_2 -> V_90 [ V_197 ] ;
}
break;
case 0xb2 :
V_79 = F_83 ( V_2 , V_77 ) ;
break;
case 0xb3 :
V_444:
F_114 ( L_28 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xb4 :
V_79 = F_83 ( V_2 , V_37 ) ;
break;
case 0xb5 :
V_79 = F_83 ( V_2 , V_172 ) ;
break;
case 0xb6 ... 0xb7 :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_74 & V_117 ) ? ( T_4 ) V_2 -> V_14 . V_104
: ( T_2 ) V_2 -> V_14 . V_104 ;
break;
case 0xba :
switch ( V_2 -> V_11 & 3 ) {
case 0 :
goto V_442;
case 1 :
goto V_443;
case 2 :
goto V_444;
case 3 :
goto V_445;
}
break;
case 0xbb :
V_445:
F_114 ( L_29 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
break;
case 0xbc : {
T_4 V_446 ;
__asm__ ("bsf %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
V_2 -> V_158 &= ~ V_447 ;
if ( V_446 ) {
V_2 -> V_158 |= V_447 ;
V_2 -> V_19 . type = V_179 ;
}
break;
}
case 0xbd : {
T_4 V_446 ;
__asm__ ("bsr %2, %0; setz %1"
: "=r"(ctxt->dst.val), "=q"(zf)
: "r"(ctxt->src.val));
V_2 -> V_158 &= ~ V_447 ;
if ( V_446 ) {
V_2 -> V_158 |= V_447 ;
V_2 -> V_19 . type = V_179 ;
}
break;
}
case 0xbe ... 0xbf :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_74 & V_117 ) ? ( V_136 ) V_2 -> V_14 . V_104 :
( V_143 ) V_2 -> V_14 . V_104 ;
break;
case 0xc0 ... 0xc1 :
F_75 ( L_17 , V_2 -> V_14 , V_2 -> V_19 , V_2 -> V_158 ) ;
V_2 -> V_14 . V_104 = V_2 -> V_19 . V_118 ;
F_54 ( & V_2 -> V_14 ) ;
break;
case 0xc3 :
V_2 -> V_19 . V_17 = V_2 -> V_94 ;
V_2 -> V_19 . V_104 = ( V_2 -> V_94 == 4 ) ? ( T_1 ) V_2 -> V_14 . V_104 :
( V_105 ) V_2 -> V_14 . V_104 ;
break;
case 0xc7 :
V_79 = F_80 ( V_2 ) ;
break;
default:
goto V_430;
}
if ( V_79 != V_76 )
goto V_140;
goto F_55;
V_430:
return V_291 ;
}
