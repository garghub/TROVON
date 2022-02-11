static void * F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
T_1 * V_3 ;
V_3 = F_2 ( V_4 , V_2 ) ;
if ( ! V_3 || ! F_3 ( * V_3 ) )
return NULL ;
V_2 = ( F_4 ( * V_3 ) << V_5 ) | ( V_2 & ~ V_6 ) ;
return F_5 ( V_2 ) ;
}
static int F_6 ( struct V_7 * V_7 , unsigned long V_8 )
{
int V_9 ;
if ( V_7 -> V_10 . V_11 == 1 && V_12 -> V_13 . V_14 )
V_9 = 0 ;
else if ( V_7 -> V_10 . V_15 )
V_9 = 1 ;
else
V_9 = ! ( V_8 & V_16 ) ;
if ( ! V_9 ) {
F_7 () ;
F_8 ( & V_7 -> V_10 . V_17 ) ;
F_9 ( V_12 -> V_13 . V_14 -> V_18 ,
& V_7 -> V_10 . V_17 ) ;
}
return V_9 ;
}
void F_10 ( struct V_7 * V_7 , struct V_19 * V_20 ,
unsigned long * V_21 , long V_22 , int V_23 )
{
struct V_19 * V_24 , * V_25 ;
unsigned long V_26 ;
if ( * V_21 & V_27 ) {
V_26 = * V_21 & V_28 ;
V_24 = & V_7 -> V_10 . V_29 [ V_26 ] ;
if ( V_23 )
V_24 = F_1 ( V_24 ) ;
V_25 = & V_7 -> V_10 . V_29 [ V_24 -> V_30 ] ;
if ( V_23 )
V_25 = F_1 ( V_25 ) ;
V_20 -> V_31 = V_26 ;
V_20 -> V_30 = V_24 -> V_30 ;
V_25 -> V_31 = V_22 ;
V_24 -> V_30 = V_22 ;
} else {
V_20 -> V_31 = V_20 -> V_30 = V_22 ;
* V_21 = ( * V_21 & ~ V_28 ) |
V_22 | V_27 ;
}
F_11 ( V_21 ) ;
}
static inline void F_12 ( struct V_7 * V_7 ,
struct V_19 * V_20 )
{
if ( F_13 ( & V_7 -> V_10 . V_32 ) )
V_20 -> V_33 |= V_34 ;
}
static void F_14 ( struct V_7 * V_7 , long V_22 ,
struct V_19 * V_20 ,
unsigned long V_35 , unsigned long V_36 )
{
struct V_19 * V_37 , * V_38 ;
unsigned long V_39 , V_40 , V_24 ;
struct V_41 * V_42 ;
unsigned long * V_21 ;
unsigned long V_43 ;
V_43 = V_36 & ( V_44 | V_45 ) ;
V_40 = V_20 -> V_33 |= V_43 ;
V_39 = F_15 ( V_40 , F_16 ( V_35 , V_40 ) ) ;
V_42 = F_17 ( F_18 ( V_7 ) , V_39 ) ;
if ( ! V_42 )
return;
V_21 = F_1 ( & V_42 -> V_10 . V_21 [ V_39 - V_42 -> V_46 ] ) ;
F_19 ( V_21 ) ;
V_24 = * V_21 & V_28 ;
V_37 = F_1 ( & V_7 -> V_10 . V_29 [ V_20 -> V_31 ] ) ;
V_38 = F_1 ( & V_7 -> V_10 . V_29 [ V_20 -> V_30 ] ) ;
V_37 -> V_30 = V_20 -> V_30 ;
V_38 -> V_31 = V_20 -> V_31 ;
if ( V_24 == V_22 ) {
V_24 = V_20 -> V_31 ;
if ( V_24 == V_22 )
* V_21 &= ~ ( V_27 | V_28 ) ;
else
* V_21 = ( * V_21 & ~ V_28 ) | V_24 ;
}
* V_21 |= V_43 << V_47 ;
F_11 ( V_21 ) ;
}
static T_1 F_20 ( T_2 * V_48 , unsigned long V_49 ,
int V_50 , unsigned long * V_51 )
{
T_1 * V_52 ;
unsigned long V_53 = * V_51 ;
unsigned int V_54 ;
V_52 = F_21 ( V_48 , V_49 , & V_54 ) ;
if ( ! V_52 )
return F_22 ( 0 ) ;
if ( V_54 )
* V_51 = 1ul << V_54 ;
else
* V_51 = V_55 ;
if ( V_53 > * V_51 )
return F_22 ( 0 ) ;
if ( ! F_3 ( * V_52 ) )
return F_22 ( 0 ) ;
return F_23 ( V_52 , V_50 ) ;
}
static inline void F_24 ( unsigned long * V_56 , unsigned long V_35 )
{
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_56 [ 0 ] = V_35 ;
}
long F_25 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_22 , unsigned long V_57 , unsigned long V_40 ,
T_2 * V_48 , bool V_23 , unsigned long * V_58 )
{
unsigned long V_26 , V_59 , V_60 , V_39 , V_61 ;
unsigned long V_62 , V_49 ;
unsigned long * V_56 ;
struct V_19 * V_20 ;
unsigned long V_63 ;
struct V_41 * V_42 ;
unsigned long * V_64 , V_65 ;
unsigned long V_66 ;
unsigned long * V_21 ;
T_1 V_67 ;
unsigned int V_50 ;
unsigned long V_68 ;
unsigned long V_43 ;
V_61 = F_16 ( V_57 , V_40 ) ;
if ( ! V_61 )
return V_69 ;
V_50 = F_26 ( V_40 ) ;
V_57 &= ~ ( V_70 | V_71 | V_72 ) ;
V_40 &= ~ V_73 ;
V_63 = V_40 ;
V_68 = V_7 -> V_74 ;
F_27 () ;
V_60 = ( V_40 & V_75 ) & ~ ( V_61 - 1 ) ;
V_39 = V_60 >> V_5 ;
V_42 = F_17 ( F_18 ( V_7 ) , V_39 ) ;
V_59 = 0 ;
V_66 = ~ 0ul ;
V_21 = NULL ;
if ( ! ( V_42 && ! ( V_42 -> V_8 & V_76 ) ) ) {
if ( ! F_28 ( V_77 ) )
return V_69 ;
V_57 |= V_71 ;
V_40 |= V_78 | V_79 ;
goto V_80;
}
if ( ! F_29 ( V_42 , V_61 ) )
return V_69 ;
V_62 = V_39 - V_42 -> V_46 ;
V_21 = & V_42 -> V_10 . V_21 [ V_62 ] ;
if ( ! V_7 -> V_10 . V_15 ) {
V_64 = V_42 -> V_10 . V_81 ;
if ( ! V_64 )
return V_69 ;
V_64 += V_62 ;
if ( V_23 )
V_64 = F_1 ( V_64 ) ;
V_59 = * V_64 ;
if ( ! V_59 )
return V_82 ;
V_66 = V_59 & ( V_83 | V_84 ) ;
V_65 = V_55 << ( V_59 & V_85 ) ;
V_59 &= V_6 ;
} else {
V_49 = F_30 ( V_42 , V_39 ) ;
V_65 = V_61 ;
V_67 = F_20 ( V_48 , V_49 , V_50 , & V_65 ) ;
if ( F_3 ( V_67 ) ) {
if ( V_50 && ! F_31 ( V_67 ) )
V_40 = F_32 ( V_40 ) ;
V_66 = F_33 ( F_34 ( V_67 ) ) ;
V_59 = F_4 ( V_67 ) << V_5 ;
}
}
if ( V_65 < V_61 )
return V_69 ;
if ( V_59 && V_65 > V_61 )
V_59 |= V_60 & ( V_65 - 1 ) ;
V_40 &= ~ ( V_86 - V_61 ) ;
V_40 |= V_59 ;
if ( V_59 )
V_57 |= V_72 ;
else
V_57 |= V_71 ;
if ( V_66 != ~ 0ul && ! F_35 ( V_40 , V_66 ) ) {
if ( V_66 )
return V_69 ;
V_40 &= ~ ( V_84 | V_83 | V_87 ) ;
V_40 |= V_88 ;
}
V_80:
if ( V_22 >= V_7 -> V_10 . V_89 )
return V_69 ;
if ( F_36 ( ( V_8 & V_90 ) == 0 ) ) {
V_22 &= ~ 7UL ;
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
if ( ( * V_56 & V_72 ) == 0 &&
F_37 ( V_56 , V_70 | V_72 |
V_71 ) )
break;
V_56 += 2 ;
}
if ( V_26 == 8 ) {
V_56 -= 16 ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
while ( ! F_37 ( V_56 , V_70 ) )
F_38 () ;
if ( ! ( * V_56 & ( V_72 | V_71 ) ) )
break;
* V_56 &= ~ V_70 ;
V_56 += 2 ;
}
if ( V_26 == 8 )
return V_92 ;
}
V_22 += V_26 ;
} else {
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
if ( ! F_37 ( V_56 , V_70 | V_72 |
V_71 ) ) {
while ( ! F_37 ( V_56 , V_70 ) )
F_38 () ;
if ( * V_56 & ( V_72 | V_71 ) ) {
* V_56 &= ~ V_70 ;
return V_92 ;
}
}
}
V_20 = & V_7 -> V_10 . V_29 [ V_22 ] ;
if ( V_23 )
V_20 = F_1 ( V_20 ) ;
if ( V_20 ) {
V_20 -> V_33 = V_63 ;
F_12 ( V_7 , V_20 ) ;
}
if ( V_57 & V_72 ) {
if ( V_23 )
V_21 = F_1 ( V_21 ) ;
F_19 ( V_21 ) ;
if ( V_7 -> V_10 . V_15 &&
F_39 ( V_7 , V_68 ) ) {
V_57 |= V_71 ;
V_57 &= ~ V_72 ;
F_11 ( V_21 ) ;
} else {
F_10 ( V_7 , V_20 , V_21 , V_22 ,
V_23 ) ;
V_43 = * V_21 >> V_47 ;
V_40 &= V_43 | ~ ( V_44 | V_45 ) ;
}
}
V_56 [ 1 ] = V_40 ;
F_40 () ;
V_56 [ 0 ] = V_57 ;
asm volatile("ptesync" : : : "memory");
* V_58 = V_22 ;
return V_93 ;
}
long F_41 ( struct V_94 * V_95 , unsigned long V_8 ,
long V_22 , unsigned long V_57 , unsigned long V_40 )
{
return F_25 ( V_95 -> V_7 , V_8 , V_22 , V_57 , V_40 ,
V_95 -> V_10 . V_48 , true , & V_95 -> V_10 . V_96 [ 4 ] ) ;
}
static inline int F_42 ( unsigned int * V_97 )
{
unsigned int V_98 , V_99 ;
unsigned int V_100 = V_101 ;
asm volatile("1:lwarx %1,0,%2\n"
" cmpwi cr0,%1,0\n"
" bne 2f\n"
" stwcx. %3,0,%2\n"
" bne- 1b\n"
" isync\n"
"2:"
: "=&r" (tmp), "=&r" (old)
: "r" (lock), "r" (token)
: "cc", "memory");
return V_99 == 0 ;
}
long F_43 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_102 ,
unsigned long * V_103 )
{
unsigned long * V_56 ;
unsigned long V_104 , V_105 , V_106 ;
struct V_19 * V_20 ;
if ( V_22 >= V_7 -> V_10 . V_89 )
return V_69 ;
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
while ( ! F_37 ( V_56 , V_70 ) )
F_38 () ;
if ( ( V_56 [ 0 ] & ( V_71 | V_72 ) ) == 0 ||
( ( V_8 & V_107 ) && ( V_56 [ 0 ] & ~ 0x7fUL ) != V_102 ) ||
( ( V_8 & V_108 ) && ( V_56 [ 0 ] & V_102 ) != 0 ) ) {
V_56 [ 0 ] &= ~ V_70 ;
return V_109 ;
}
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
V_104 = V_56 [ 0 ] & ~ V_70 ;
if ( V_104 & V_72 ) {
V_56 [ 0 ] &= ~ V_72 ;
V_106 = F_44 ( V_104 , V_56 [ 1 ] , V_22 ) ;
if ( F_6 ( V_7 , V_8 ) ) {
while ( ! F_42 ( & V_7 -> V_10 . V_110 ) )
F_38 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_110 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
F_14 ( V_7 , V_22 , V_20 , V_104 , V_56 [ 1 ] ) ;
}
V_105 = V_20 -> V_33 & ~ V_73 ;
F_12 ( V_7 , V_20 ) ;
F_24 ( V_56 , 0 ) ;
V_103 [ 0 ] = V_104 ;
V_103 [ 1 ] = V_105 ;
return V_93 ;
}
long F_45 ( struct V_94 * V_95 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_102 )
{
return F_43 ( V_95 -> V_7 , V_8 , V_22 , V_102 ,
& V_95 -> V_10 . V_96 [ 4 ] ) ;
}
long F_46 ( struct V_94 * V_95 )
{
struct V_7 * V_7 = V_95 -> V_7 ;
unsigned long * args = & V_95 -> V_10 . V_96 [ 4 ] ;
unsigned long * V_111 , * V_112 [ 4 ] , V_113 [ 4 ] ;
long int V_26 , V_114 , V_115 , V_116 , V_117 , V_118 [ 4 ] ;
unsigned long V_8 , V_119 , V_22 , V_43 ;
long int V_120 = 0 ;
long int V_121 = V_93 ;
struct V_19 * V_20 , * V_122 [ 4 ] ;
if ( F_13 ( & V_7 -> V_123 ) == 1 )
V_120 = 1 ;
for ( V_26 = 0 ; V_26 < 4 && V_121 == V_93 ; ) {
V_116 = 0 ;
for (; V_26 < 4 ; ++ V_26 ) {
V_114 = V_26 * 2 ;
V_22 = args [ V_114 ] ;
V_8 = V_22 >> 56 ;
V_22 &= ( ( 1ul << 56 ) - 1 ) ;
V_119 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_119 == 3 ) {
V_26 = 4 ;
break;
}
if ( V_119 != 1 || V_8 == 3 ||
V_22 >= V_7 -> V_10 . V_89 ) {
args [ V_114 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_22 ;
V_121 = V_69 ;
break;
}
V_111 = ( unsigned long * )
( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
if ( ! F_37 ( V_111 , V_70 ) ) {
if ( V_116 )
break;
while ( ! F_37 ( V_111 , V_70 ) )
F_38 () ;
}
V_117 = 0 ;
if ( V_111 [ 0 ] & ( V_71 | V_72 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_117 = 1 ;
break;
case 1 :
if ( ! ( V_111 [ 0 ] & args [ V_114 + 1 ] ) )
V_117 = 1 ;
break;
case 2 :
if ( ( V_111 [ 0 ] & ~ 0x7fUL ) == args [ V_114 + 1 ] )
V_117 = 1 ;
break;
}
}
if ( ! V_117 ) {
V_111 [ 0 ] &= ~ V_70 ;
args [ V_114 ] = ( ( 0x90 | V_8 ) << 56 ) + V_22 ;
continue;
}
args [ V_114 ] = ( ( 0x80 | V_8 ) << 56 ) + V_22 ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
F_12 ( V_7 , V_20 ) ;
if ( ! ( V_111 [ 0 ] & V_72 ) ) {
V_43 = V_20 -> V_33 & ( V_44 | V_45 ) ;
args [ V_114 ] |= V_43 << ( 56 - 5 ) ;
V_111 [ 0 ] = 0 ;
continue;
}
V_111 [ 0 ] &= ~ V_72 ;
V_113 [ V_116 ] = F_44 ( V_111 [ 0 ] , V_111 [ 1 ] , V_22 ) ;
V_118 [ V_116 ] = V_114 ;
V_112 [ V_116 ] = V_111 ;
V_122 [ V_116 ] = V_20 ;
++ V_116 ;
}
if ( ! V_116 )
break;
if ( ! V_120 ) {
while( ! F_42 ( & V_7 -> V_10 . V_110 ) )
F_38 () ;
asm volatile("ptesync" : : : "memory");
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (tlbrb[k]),
"r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_110 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 )
asm volatile("tlbiel %0" : : "r" (tlbrb[k]));
asm volatile("ptesync" : : : "memory");
}
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 ) {
V_114 = V_118 [ V_115 ] ;
V_22 = args [ V_114 ] & ( ( 1ul << 56 ) - 1 ) ;
V_111 = V_112 [ V_115 ] ;
V_20 = V_122 [ V_115 ] ;
F_14 ( V_7 , V_22 , V_20 , V_111 [ 0 ] , V_111 [ 1 ] ) ;
V_43 = V_20 -> V_33 & ( V_44 | V_45 ) ;
args [ V_114 ] |= V_43 << ( 56 - 5 ) ;
V_111 [ 0 ] = 0 ;
}
}
return V_121 ;
}
long F_47 ( struct V_94 * V_95 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_102 ,
unsigned long V_124 )
{
struct V_7 * V_7 = V_95 -> V_7 ;
unsigned long * V_56 ;
struct V_19 * V_20 ;
unsigned long V_104 , V_105 , V_106 , V_125 , V_126 ;
if ( V_22 >= V_7 -> V_10 . V_89 )
return V_69 ;
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
while ( ! F_37 ( V_56 , V_70 ) )
F_38 () ;
if ( ( V_56 [ 0 ] & ( V_71 | V_72 ) ) == 0 ||
( ( V_8 & V_107 ) && ( V_56 [ 0 ] & ~ 0x7fUL ) != V_102 ) ) {
V_56 [ 0 ] &= ~ V_70 ;
return V_109 ;
}
V_104 = V_56 [ 0 ] ;
V_126 = ( V_8 << 55 ) & V_86 ;
V_126 |= ( V_8 << 48 ) & V_78 ;
V_126 |= V_8 & ( V_127 | V_128 | V_79 ) ;
V_125 = V_86 | V_127 | V_128 |
V_78 | V_79 ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
if ( V_20 ) {
V_105 = ( V_20 -> V_33 & ~ V_125 ) | V_126 ;
V_20 -> V_33 = V_105 ;
F_12 ( V_7 , V_20 ) ;
}
V_105 = ( V_56 [ 1 ] & ~ V_125 ) | V_126 ;
if ( V_104 & V_72 ) {
V_106 = F_44 ( V_104 , V_105 , V_22 ) ;
V_56 [ 0 ] = V_104 & ~ V_72 ;
if ( F_6 ( V_7 , V_8 ) ) {
while( ! F_42 ( & V_7 -> V_10 . V_110 ) )
F_38 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_110 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
if ( F_26 ( V_105 ) && V_7 -> V_10 . V_15 ) {
unsigned long V_61 , V_39 , V_49 ;
struct V_41 * V_42 ;
T_2 * V_48 = V_95 -> V_10 . V_48 ;
T_1 V_67 ;
V_61 = F_16 ( V_104 , V_105 ) ;
V_39 = ( ( V_105 & V_75 ) & ~ ( V_61 - 1 ) ) >> V_5 ;
V_42 = F_17 ( F_18 ( V_7 ) , V_39 ) ;
if ( V_42 ) {
V_49 = F_30 ( V_42 , V_39 ) ;
V_67 = F_20 ( V_48 , V_49 , 1 , & V_61 ) ;
if ( F_3 ( V_67 ) && ! F_31 ( V_67 ) )
V_105 = F_32 ( V_105 ) ;
}
}
}
V_56 [ 1 ] = V_105 ;
F_40 () ;
V_56 [ 0 ] = V_104 & ~ V_70 ;
asm volatile("ptesync" : : : "memory");
return V_93 ;
}
long F_48 ( struct V_94 * V_95 , unsigned long V_8 ,
unsigned long V_22 )
{
struct V_7 * V_7 = V_95 -> V_7 ;
unsigned long * V_56 , V_104 , V_105 ;
int V_26 , V_116 = 1 ;
struct V_19 * V_20 = NULL ;
if ( V_22 >= V_7 -> V_10 . V_89 )
return V_69 ;
if ( V_8 & V_129 ) {
V_22 &= ~ 3 ;
V_116 = 4 ;
}
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
for ( V_26 = 0 ; V_26 < V_116 ; ++ V_26 , ++ V_22 ) {
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_22 << 4 ) ) ;
V_104 = V_56 [ 0 ] & ~ V_70 ;
V_105 = V_56 [ 1 ] ;
if ( V_104 & V_71 ) {
V_104 &= ~ V_71 ;
V_104 |= V_72 ;
}
if ( V_104 & V_72 ) {
V_105 = V_20 [ V_26 ] . V_33 | ( V_105 & ( V_44 | V_45 ) ) ;
V_105 &= ~ V_73 ;
}
V_95 -> V_10 . V_96 [ 4 + V_26 * 2 ] = V_104 ;
V_95 -> V_10 . V_96 [ 5 + V_26 * 2 ] = V_105 ;
}
return V_93 ;
}
void F_49 ( struct V_7 * V_7 , unsigned long * V_130 ,
unsigned long V_22 )
{
unsigned long V_106 ;
V_130 [ 0 ] &= ~ V_72 ;
V_106 = F_44 ( V_130 [ 0 ] , V_130 [ 1 ] , V_22 ) ;
while ( ! F_42 ( & V_7 -> V_10 . V_110 ) )
F_38 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_110 = 0 ;
}
void F_50 ( struct V_7 * V_7 , unsigned long * V_130 ,
unsigned long V_22 )
{
unsigned long V_106 ;
unsigned char V_131 ;
V_106 = F_44 ( V_130 [ 0 ] , V_130 [ 1 ] , V_22 ) ;
V_131 = ( V_130 [ 1 ] & ~ V_44 ) >> 8 ;
* ( ( char * ) V_130 + 14 ) = V_131 ;
while ( ! F_42 ( & V_7 -> V_10 . V_110 ) )
F_38 () ;
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_110 = 0 ;
}
long F_51 ( struct V_7 * V_7 , T_3 V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
unsigned int V_26 ;
unsigned int V_135 ;
unsigned long V_136 ;
unsigned long V_137 , V_138 ;
unsigned long V_102 ;
unsigned long * V_56 ;
unsigned long V_125 , V_139 ;
unsigned long V_104 , V_105 ;
V_125 = V_140 | V_141 | V_142 ;
V_139 = 0 ;
V_135 = 12 ;
if ( V_133 & V_143 ) {
V_125 |= V_144 ;
V_139 |= V_144 ;
V_135 = V_145 [ ( V_133 & V_146 ) >> 4 ] ;
}
if ( V_133 & V_147 ) {
V_136 = ( 1UL << 40 ) - 1 ;
V_137 = ( V_133 & ~ V_140 ) >> V_148 ;
V_137 ^= V_137 << 25 ;
} else {
V_136 = ( 1UL << 28 ) - 1 ;
V_137 = ( V_133 & ~ V_140 ) >> V_149 ;
}
V_138 = ( V_137 ^ ( ( V_132 & V_136 ) >> V_135 ) ) & V_7 -> V_10 . V_150 ;
V_102 = V_133 & ~ ( V_136 >> 16 ) ;
V_102 |= ( V_132 & V_136 ) >> 16 ;
if ( V_135 >= 24 )
V_102 &= ~ ( ( 1UL << ( V_135 - 16 ) ) - 1 ) ;
else
V_102 &= ~ 0x7fUL ;
V_139 |= V_102 ;
for (; ; ) {
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_138 << 7 ) ) ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 += 2 ) {
V_104 = V_56 [ V_26 ] & ~ V_70 ;
if ( ! ( V_104 & V_134 ) || ( V_104 & V_125 ) != V_139 )
continue;
while ( ! F_37 ( & V_56 [ V_26 ] , V_70 ) )
F_38 () ;
V_104 = V_56 [ V_26 ] & ~ V_70 ;
V_105 = V_56 [ V_26 + 1 ] ;
if ( ( V_104 & V_134 ) && ( V_104 & V_125 ) == V_139 &&
F_16 ( V_104 , V_105 ) == ( 1ul << V_135 ) )
return ( V_138 << 3 ) + ( V_26 >> 1 ) ;
V_56 [ V_26 ] = V_104 ;
}
if ( V_139 & V_142 )
break;
V_139 |= V_142 ;
V_138 = V_138 ^ V_7 -> V_10 . V_150 ;
}
return - 1 ;
}
long F_52 ( struct V_94 * V_95 , unsigned long V_2 ,
unsigned long V_133 , unsigned int V_151 , bool V_152 )
{
struct V_7 * V_7 = V_95 -> V_7 ;
long int V_153 ;
unsigned long V_104 , V_105 , V_154 ;
unsigned long * V_56 ;
unsigned long V_134 ;
struct V_19 * V_20 ;
unsigned long V_155 , V_156 ;
V_134 = V_72 ;
if ( V_151 & V_157 )
V_134 |= V_71 ;
V_153 = F_51 ( V_7 , V_2 , V_133 , V_134 ) ;
if ( V_153 < 0 ) {
if ( V_151 & V_157 )
return V_151 ;
return 0 ;
}
V_56 = ( unsigned long * ) ( V_7 -> V_10 . V_91 + ( V_153 << 4 ) ) ;
V_104 = V_56 [ 0 ] & ~ V_70 ;
V_105 = V_56 [ 1 ] ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_153 ] ) ;
V_154 = V_20 -> V_33 ;
F_24 ( V_56 , V_104 ) ;
if ( ( V_151 & V_157 ) && ( V_104 & V_72 ) )
return 0 ;
V_155 = V_154 & ( V_86 | V_127 ) ;
V_156 = ( V_95 -> V_10 . V_158 . V_159 & V_160 ) ? V_161 : V_162 ;
V_151 &= ~ V_157 ;
if ( ! V_152 ) {
if ( V_154 & ( V_128 | V_87 ) )
return V_151 | V_163 ;
if ( ! F_53 ( V_155 , V_133 & V_156 ) )
return V_151 | V_164 ;
} else if ( V_151 & V_165 ) {
if ( ! F_54 ( V_155 , V_133 & V_156 ) )
return V_151 | V_166 ;
} else {
if ( ! F_53 ( V_155 , V_133 & V_156 ) )
return V_151 | V_166 ;
}
if ( V_152 && ( V_95 -> V_10 . V_158 . V_159 & V_167 ) ) {
unsigned int V_168 = F_55 ( V_154 , V_95 -> V_10 . V_169 ) ;
if ( V_151 & V_165 )
V_168 >>= 1 ;
if ( V_168 & 1 )
return V_151 | V_170 ;
}
V_95 -> V_10 . V_171 = V_2 ;
V_95 -> V_10 . V_172 = V_153 ;
V_95 -> V_10 . V_173 [ 0 ] = V_104 ;
V_95 -> V_10 . V_173 [ 1 ] = V_105 ;
if ( V_152 && ( V_95 -> V_10 . V_158 . V_159 & V_174 ) &&
( V_105 & ( V_78 | V_79 ) ) ==
( V_78 | V_79 ) )
return - 2 ;
return - 1 ;
}
