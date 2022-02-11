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
void F_6 ( struct V_7 * V_7 , struct V_8 * V_9 ,
unsigned long * V_10 , long V_11 , int V_12 )
{
struct V_8 * V_13 , * V_14 ;
unsigned long V_15 ;
if ( * V_10 & V_16 ) {
V_15 = * V_10 & V_17 ;
V_13 = & V_7 -> V_18 . V_19 [ V_15 ] ;
if ( V_12 )
V_13 = F_1 ( V_13 ) ;
V_14 = & V_7 -> V_18 . V_19 [ V_13 -> V_20 ] ;
if ( V_12 )
V_14 = F_1 ( V_14 ) ;
V_9 -> V_21 = V_15 ;
V_9 -> V_20 = V_13 -> V_20 ;
V_14 -> V_21 = V_11 ;
V_13 -> V_20 = V_11 ;
} else {
V_9 -> V_21 = V_9 -> V_20 = V_11 ;
V_15 = V_11 ;
}
F_7 () ;
* V_10 = V_15 | V_22 | V_16 ;
}
static void F_8 ( struct V_7 * V_7 , long V_11 ,
struct V_8 * V_9 ,
unsigned long V_23 , unsigned long V_24 )
{
struct V_8 * V_25 , * V_26 ;
unsigned long V_27 , V_28 , V_13 ;
struct V_29 * V_30 ;
unsigned long * V_10 ;
unsigned long V_31 ;
V_31 = V_24 & ( V_32 | V_33 ) ;
V_28 = V_9 -> V_34 |= V_31 ;
V_27 = F_9 ( V_28 , F_10 ( V_23 , V_28 ) ) ;
V_30 = F_11 ( F_12 ( V_7 ) , V_27 ) ;
if ( ! V_30 || ( V_30 -> V_35 & V_36 ) )
return;
V_10 = F_1 ( & V_30 -> V_18 . V_10 [ V_27 - V_30 -> V_37 ] ) ;
F_13 ( V_10 ) ;
V_13 = * V_10 & V_17 ;
V_25 = F_1 ( & V_7 -> V_18 . V_19 [ V_9 -> V_21 ] ) ;
V_26 = F_1 ( & V_7 -> V_18 . V_19 [ V_9 -> V_20 ] ) ;
V_25 -> V_20 = V_9 -> V_20 ;
V_26 -> V_21 = V_9 -> V_21 ;
if ( V_13 == V_11 ) {
V_13 = V_9 -> V_21 ;
if ( V_13 == V_11 )
* V_10 &= ~ ( V_16 | V_17 ) ;
else
* V_10 = ( * V_10 & ~ V_17 ) | V_13 ;
}
* V_10 |= V_31 << V_38 ;
F_14 ( V_10 ) ;
}
static T_1 F_15 ( struct V_39 * V_40 , unsigned long V_41 ,
int V_42 , unsigned long * V_43 )
{
T_1 * V_44 ;
unsigned long V_45 = * V_43 ;
unsigned int V_46 ;
V_44 = F_16 ( V_40 -> V_18 . V_47 , V_41 , & V_46 ) ;
if ( ! V_44 )
return F_17 ( 0 ) ;
if ( V_46 )
* V_43 = 1ul << V_46 ;
else
* V_43 = V_48 ;
if ( V_45 > * V_43 )
return F_17 ( 0 ) ;
if ( ! F_3 ( * V_44 ) )
return F_17 ( 0 ) ;
return F_18 ( V_44 , V_42 ) ;
}
static inline void F_19 ( unsigned long * V_49 , unsigned long V_23 )
{
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_49 [ 0 ] = V_23 ;
}
long F_20 ( struct V_39 * V_40 , unsigned long V_35 ,
long V_11 , unsigned long V_50 , unsigned long V_28 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
unsigned long V_15 , V_51 , V_52 , V_27 , V_53 ;
unsigned long V_54 , V_41 ;
unsigned long * V_49 ;
struct V_8 * V_9 ;
unsigned long V_55 = V_28 ;
struct V_29 * V_30 ;
unsigned long * V_56 , V_57 ;
unsigned long V_58 ;
unsigned long * V_10 ;
T_1 V_59 ;
unsigned int V_42 ;
unsigned long V_60 ;
unsigned long V_31 ;
bool V_12 = V_40 -> V_18 . V_61 -> V_62 == V_63 ;
V_53 = F_10 ( V_50 , V_28 ) ;
if ( ! V_53 )
return V_64 ;
V_42 = F_21 ( V_28 ) ;
V_50 &= ~ ( V_65 | V_66 | V_67 ) ;
V_60 = V_7 -> V_68 ;
F_22 () ;
V_52 = ( V_28 & V_69 ) & ~ ( V_53 - 1 ) ;
V_27 = V_52 >> V_5 ;
V_30 = F_11 ( F_12 ( V_7 ) , V_27 ) ;
V_51 = 0 ;
V_58 = ~ 0ul ;
V_10 = NULL ;
if ( ! ( V_30 && ! ( V_30 -> V_35 & V_36 ) ) ) {
if ( ! F_23 ( V_70 ) )
return V_64 ;
V_50 |= V_66 ;
V_28 |= V_71 | V_72 ;
goto V_73;
}
if ( ! F_24 ( V_30 , V_53 ) )
return V_64 ;
V_54 = V_27 - V_30 -> V_37 ;
V_10 = & V_30 -> V_18 . V_10 [ V_54 ] ;
if ( ! V_7 -> V_18 . V_74 ) {
V_56 = V_7 -> V_18 . V_75 [ V_30 -> V_76 ] ;
if ( ! V_56 )
return V_64 ;
V_56 += V_54 ;
if ( V_12 )
V_56 = F_1 ( V_56 ) ;
V_51 = * V_56 ;
if ( ! V_51 )
return V_77 ;
V_58 = V_51 & ( V_78 | V_79 ) ;
V_57 = V_48 << ( V_51 & V_80 ) ;
V_51 &= V_6 ;
} else {
V_41 = F_25 ( V_30 , V_27 ) ;
V_57 = V_53 ;
V_59 = F_15 ( V_40 , V_41 , V_42 , & V_57 ) ;
if ( F_3 ( V_59 ) ) {
if ( V_42 && ! F_26 ( V_59 ) )
V_28 = F_27 ( V_28 ) ;
V_58 = F_28 ( F_29 ( V_59 ) ) ;
V_51 = F_4 ( V_59 ) << V_5 ;
}
}
if ( V_57 < V_53 )
return V_64 ;
if ( V_51 && V_57 > V_53 )
V_51 |= V_52 & ( V_57 - 1 ) ;
V_28 &= ~ ( V_81 - V_53 ) ;
V_28 |= V_51 ;
if ( V_51 )
V_50 |= V_67 ;
else
V_50 |= V_66 ;
if ( V_58 != ~ 0ul && ! F_30 ( V_28 , V_58 ) ) {
if ( V_58 )
return V_64 ;
V_28 &= ~ ( V_79 | V_78 | V_82 ) ;
V_28 |= V_83 ;
}
V_73:
if ( V_11 >= V_7 -> V_18 . V_84 )
return V_64 ;
if ( F_31 ( ( V_35 & V_85 ) == 0 ) ) {
V_11 &= ~ 7UL ;
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 ) {
if ( ( * V_49 & V_67 ) == 0 &&
F_32 ( V_49 , V_65 | V_67 |
V_66 ) )
break;
V_49 += 2 ;
}
if ( V_15 == 8 ) {
V_49 -= 16 ;
for ( V_15 = 0 ; V_15 < 8 ; ++ V_15 ) {
while ( ! F_32 ( V_49 , V_65 ) )
F_33 () ;
if ( ! ( * V_49 & ( V_67 | V_66 ) ) )
break;
* V_49 &= ~ V_65 ;
V_49 += 2 ;
}
if ( V_15 == 8 )
return V_87 ;
}
V_11 += V_15 ;
} else {
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
if ( ! F_32 ( V_49 , V_65 | V_67 |
V_66 ) ) {
while ( ! F_32 ( V_49 , V_65 ) )
F_33 () ;
if ( * V_49 & ( V_67 | V_66 ) ) {
* V_49 &= ~ V_65 ;
return V_87 ;
}
}
}
V_9 = & V_7 -> V_18 . V_19 [ V_11 ] ;
if ( V_12 )
V_9 = F_1 ( V_9 ) ;
if ( V_9 )
V_9 -> V_34 = V_55 ;
if ( V_50 & V_67 ) {
if ( V_12 )
V_10 = F_1 ( V_10 ) ;
F_13 ( V_10 ) ;
if ( V_7 -> V_18 . V_74 &&
F_34 ( V_40 , V_60 ) ) {
V_50 |= V_66 ;
V_50 &= ~ V_67 ;
F_14 ( V_10 ) ;
} else {
F_6 ( V_7 , V_9 , V_10 , V_11 ,
V_12 ) ;
V_31 = * V_10 >> V_38 ;
V_28 &= V_31 | ~ ( V_32 | V_33 ) ;
}
}
V_49 [ 1 ] = V_28 ;
F_35 () ;
V_49 [ 0 ] = V_50 ;
asm volatile("ptesync" : : : "memory");
V_40 -> V_18 . V_88 [ 4 ] = V_11 ;
return V_89 ;
}
static inline int F_36 ( unsigned int * V_90 )
{
unsigned int V_91 , V_92 ;
unsigned int V_93 = V_94 ;
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
return V_92 == 0 ;
}
long F_37 ( struct V_39 * V_40 , unsigned long V_35 ,
unsigned long V_11 , unsigned long V_95 ,
unsigned long V_96 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
unsigned long * V_49 ;
unsigned long V_97 , V_98 , V_99 ;
struct V_8 * V_9 ;
if ( V_11 >= V_7 -> V_18 . V_84 )
return V_64 ;
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
while ( ! F_32 ( V_49 , V_65 ) )
F_33 () ;
if ( ( V_49 [ 0 ] & ( V_66 | V_67 ) ) == 0 ||
( ( V_35 & V_100 ) && ( V_49 [ 0 ] & ~ 0x7fUL ) != V_95 ) ||
( ( V_35 & V_101 ) && ( V_49 [ 0 ] & V_95 ) != 0 ) ) {
V_49 [ 0 ] &= ~ V_65 ;
return V_102 ;
}
V_9 = F_1 ( & V_7 -> V_18 . V_19 [ V_11 ] ) ;
V_97 = V_49 [ 0 ] & ~ V_65 ;
if ( V_97 & V_67 ) {
V_49 [ 0 ] &= ~ V_67 ;
V_99 = F_38 ( V_97 , V_49 [ 1 ] , V_11 ) ;
if ( ! ( V_35 & V_103 ) && F_39 ( & V_7 -> V_104 ) > 1 ) {
while ( ! F_36 ( & V_7 -> V_18 . V_105 ) )
F_33 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_18 . V_105 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
F_8 ( V_7 , V_11 , V_9 , V_97 , V_49 [ 1 ] ) ;
}
V_98 = V_9 -> V_34 ;
F_19 ( V_49 , 0 ) ;
V_40 -> V_18 . V_88 [ 4 ] = V_97 ;
V_40 -> V_18 . V_88 [ 5 ] = V_98 ;
return V_89 ;
}
long F_40 ( struct V_39 * V_40 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
unsigned long * args = & V_40 -> V_18 . V_88 [ 4 ] ;
unsigned long * V_106 , * V_107 [ 4 ] , V_108 [ 4 ] ;
long int V_15 , V_109 , V_110 , V_111 , V_112 , V_113 [ 4 ] ;
unsigned long V_35 , V_114 , V_11 , V_31 ;
long int V_115 = 0 ;
long int V_116 = V_89 ;
struct V_8 * V_9 , * V_117 [ 4 ] ;
if ( F_39 ( & V_7 -> V_104 ) == 1 )
V_115 = 1 ;
for ( V_15 = 0 ; V_15 < 4 && V_116 == V_89 ; ) {
V_111 = 0 ;
for (; V_15 < 4 ; ++ V_15 ) {
V_109 = V_15 * 2 ;
V_11 = args [ V_109 ] ;
V_35 = V_11 >> 56 ;
V_11 &= ( ( 1ul << 56 ) - 1 ) ;
V_114 = V_35 >> 6 ;
V_35 &= 3 ;
if ( V_114 == 3 ) {
V_15 = 4 ;
break;
}
if ( V_114 != 1 || V_35 == 3 ||
V_11 >= V_7 -> V_18 . V_84 ) {
args [ V_109 ] = ( ( 0xa0 | V_35 ) << 56 ) + V_11 ;
V_116 = V_64 ;
break;
}
V_106 = ( unsigned long * )
( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
if ( ! F_32 ( V_106 , V_65 ) ) {
if ( V_111 )
break;
while ( ! F_32 ( V_106 , V_65 ) )
F_33 () ;
}
V_112 = 0 ;
if ( V_106 [ 0 ] & ( V_66 | V_67 ) ) {
switch ( V_35 & 3 ) {
case 0 :
V_112 = 1 ;
break;
case 1 :
if ( ! ( V_106 [ 0 ] & args [ V_109 + 1 ] ) )
V_112 = 1 ;
break;
case 2 :
if ( ( V_106 [ 0 ] & ~ 0x7fUL ) == args [ V_109 + 1 ] )
V_112 = 1 ;
break;
}
}
if ( ! V_112 ) {
V_106 [ 0 ] &= ~ V_65 ;
args [ V_109 ] = ( ( 0x90 | V_35 ) << 56 ) + V_11 ;
continue;
}
args [ V_109 ] = ( ( 0x80 | V_35 ) << 56 ) + V_11 ;
V_9 = F_1 ( & V_7 -> V_18 . V_19 [ V_11 ] ) ;
if ( ! ( V_106 [ 0 ] & V_67 ) ) {
V_31 = V_9 -> V_34 & ( V_32 | V_33 ) ;
args [ V_109 ] |= V_31 << ( 56 - 5 ) ;
V_106 [ 0 ] = 0 ;
continue;
}
V_106 [ 0 ] &= ~ V_67 ;
V_108 [ V_111 ] = F_38 ( V_106 [ 0 ] , V_106 [ 1 ] , V_11 ) ;
V_113 [ V_111 ] = V_109 ;
V_107 [ V_111 ] = V_106 ;
V_117 [ V_111 ] = V_9 ;
++ V_111 ;
}
if ( ! V_111 )
break;
if ( ! V_115 ) {
while( ! F_36 ( & V_7 -> V_18 . V_105 ) )
F_33 () ;
asm volatile("ptesync" : : : "memory");
for ( V_110 = 0 ; V_110 < V_111 ; ++ V_110 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (tlbrb[k]),
"r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_18 . V_105 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
for ( V_110 = 0 ; V_110 < V_111 ; ++ V_110 )
asm volatile("tlbiel %0" : : "r" (tlbrb[k]));
asm volatile("ptesync" : : : "memory");
}
for ( V_110 = 0 ; V_110 < V_111 ; ++ V_110 ) {
V_109 = V_113 [ V_110 ] ;
V_11 = args [ V_109 ] & ( ( 1ul << 56 ) - 1 ) ;
V_106 = V_107 [ V_110 ] ;
V_9 = V_117 [ V_110 ] ;
F_8 ( V_7 , V_11 , V_9 , V_106 [ 0 ] , V_106 [ 1 ] ) ;
V_31 = V_9 -> V_34 & ( V_32 | V_33 ) ;
args [ V_109 ] |= V_31 << ( 56 - 5 ) ;
V_106 [ 0 ] = 0 ;
}
}
return V_116 ;
}
long F_41 ( struct V_39 * V_40 , unsigned long V_35 ,
unsigned long V_11 , unsigned long V_95 ,
unsigned long V_96 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
unsigned long * V_49 ;
struct V_8 * V_9 ;
unsigned long V_97 , V_98 , V_99 , V_118 , V_119 ;
if ( V_11 >= V_7 -> V_18 . V_84 )
return V_64 ;
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
while ( ! F_32 ( V_49 , V_65 ) )
F_33 () ;
if ( ( V_49 [ 0 ] & ( V_66 | V_67 ) ) == 0 ||
( ( V_35 & V_100 ) && ( V_49 [ 0 ] & ~ 0x7fUL ) != V_95 ) ) {
V_49 [ 0 ] &= ~ V_65 ;
return V_102 ;
}
if ( F_39 ( & V_7 -> V_104 ) == 1 )
V_35 |= V_103 ;
V_97 = V_49 [ 0 ] ;
V_119 = ( V_35 << 55 ) & V_81 ;
V_119 |= ( V_35 << 48 ) & V_71 ;
V_119 |= V_35 & ( V_120 | V_121 | V_72 ) ;
V_118 = V_81 | V_120 | V_121 |
V_71 | V_72 ;
V_9 = F_1 ( & V_7 -> V_18 . V_19 [ V_11 ] ) ;
if ( V_9 ) {
V_98 = ( V_9 -> V_34 & ~ V_118 ) | V_119 ;
V_9 -> V_34 = V_98 ;
}
V_98 = ( V_49 [ 1 ] & ~ V_118 ) | V_119 ;
if ( V_97 & V_67 ) {
V_99 = F_38 ( V_97 , V_98 , V_11 ) ;
V_49 [ 0 ] = V_97 & ~ V_67 ;
if ( ! ( V_35 & V_103 ) ) {
while( ! F_36 ( & V_7 -> V_18 . V_105 ) )
F_33 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_18 . V_105 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
}
V_49 [ 1 ] = V_98 ;
F_35 () ;
V_49 [ 0 ] = V_97 & ~ V_65 ;
asm volatile("ptesync" : : : "memory");
return V_89 ;
}
long F_42 ( struct V_39 * V_40 , unsigned long V_35 ,
unsigned long V_11 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
unsigned long * V_49 , V_97 , V_98 ;
int V_15 , V_111 = 1 ;
struct V_8 * V_9 = NULL ;
if ( V_11 >= V_7 -> V_18 . V_84 )
return V_64 ;
if ( V_35 & V_122 ) {
V_11 &= ~ 3 ;
V_111 = 4 ;
}
V_9 = F_1 ( & V_7 -> V_18 . V_19 [ V_11 ] ) ;
for ( V_15 = 0 ; V_15 < V_111 ; ++ V_15 , ++ V_11 ) {
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_11 << 4 ) ) ;
V_97 = V_49 [ 0 ] & ~ V_65 ;
V_98 = V_49 [ 1 ] ;
if ( V_97 & V_66 ) {
V_97 &= ~ V_66 ;
V_97 |= V_67 ;
}
if ( V_97 & V_67 )
V_98 = V_9 [ V_15 ] . V_34 | ( V_98 & ( V_32 | V_33 ) ) ;
V_40 -> V_18 . V_88 [ 4 + V_15 * 2 ] = V_97 ;
V_40 -> V_18 . V_88 [ 5 + V_15 * 2 ] = V_98 ;
}
return V_89 ;
}
void F_43 ( struct V_7 * V_7 , unsigned long * V_123 ,
unsigned long V_11 )
{
unsigned long V_99 ;
V_123 [ 0 ] &= ~ V_67 ;
V_99 = F_38 ( V_123 [ 0 ] , V_123 [ 1 ] , V_11 ) ;
while ( ! F_36 ( & V_7 -> V_18 . V_105 ) )
F_33 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_18 . V_105 = 0 ;
}
void F_44 ( struct V_7 * V_7 , unsigned long * V_123 ,
unsigned long V_11 )
{
unsigned long V_99 ;
unsigned char V_124 ;
V_99 = F_38 ( V_123 [ 0 ] , V_123 [ 1 ] , V_11 ) ;
V_124 = ( V_123 [ 1 ] & ~ V_32 ) >> 8 ;
* ( ( char * ) V_123 + 14 ) = V_124 ;
while ( ! F_36 ( & V_7 -> V_18 . V_105 ) )
F_33 () ;
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_18 . V_105 = 0 ;
}
long F_45 ( struct V_7 * V_7 , T_2 V_125 , unsigned long V_126 ,
unsigned long V_127 )
{
unsigned int V_15 ;
unsigned int V_128 ;
unsigned long V_129 ;
unsigned long V_130 , V_131 ;
unsigned long V_95 ;
unsigned long * V_49 ;
unsigned long V_118 , V_132 ;
unsigned long V_97 , V_98 ;
V_118 = V_133 | V_134 | V_135 ;
V_132 = 0 ;
V_128 = 12 ;
if ( V_126 & V_136 ) {
V_118 |= V_137 ;
V_132 |= V_137 ;
V_128 = V_138 [ ( V_126 & V_139 ) >> 4 ] ;
}
if ( V_126 & V_140 ) {
V_129 = ( 1UL << 40 ) - 1 ;
V_130 = ( V_126 & ~ V_133 ) >> V_141 ;
V_130 ^= V_130 << 25 ;
} else {
V_129 = ( 1UL << 28 ) - 1 ;
V_130 = ( V_126 & ~ V_133 ) >> V_142 ;
}
V_131 = ( V_130 ^ ( ( V_125 & V_129 ) >> V_128 ) ) & V_7 -> V_18 . V_143 ;
V_95 = V_126 & ~ ( V_129 >> 16 ) ;
V_95 |= ( V_125 & V_129 ) >> 16 ;
if ( V_128 >= 24 )
V_95 &= ~ ( ( 1UL << ( V_128 - 16 ) ) - 1 ) ;
else
V_95 &= ~ 0x7fUL ;
V_132 |= V_95 ;
for (; ; ) {
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_131 << 7 ) ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 += 2 ) {
V_97 = V_49 [ V_15 ] & ~ V_65 ;
if ( ! ( V_97 & V_127 ) || ( V_97 & V_118 ) != V_132 )
continue;
while ( ! F_32 ( & V_49 [ V_15 ] , V_65 ) )
F_33 () ;
V_97 = V_49 [ V_15 ] & ~ V_65 ;
V_98 = V_49 [ V_15 + 1 ] ;
if ( ( V_97 & V_127 ) && ( V_97 & V_118 ) == V_132 &&
F_10 ( V_97 , V_98 ) == ( 1ul << V_128 ) )
return ( V_131 << 3 ) + ( V_15 >> 1 ) ;
V_49 [ V_15 ] = V_97 ;
}
if ( V_132 & V_135 )
break;
V_132 |= V_135 ;
V_131 = V_131 ^ V_7 -> V_18 . V_143 ;
}
return - 1 ;
}
long F_46 ( struct V_39 * V_40 , unsigned long V_2 ,
unsigned long V_126 , unsigned int V_144 , bool V_145 )
{
struct V_7 * V_7 = V_40 -> V_7 ;
long int V_146 ;
unsigned long V_97 , V_98 , V_147 ;
unsigned long * V_49 ;
unsigned long V_127 ;
struct V_8 * V_9 ;
unsigned long V_148 , V_149 ;
V_127 = V_67 ;
if ( V_144 & V_150 )
V_127 |= V_66 ;
V_146 = F_45 ( V_7 , V_2 , V_126 , V_127 ) ;
if ( V_146 < 0 ) {
if ( V_144 & V_150 )
return V_144 ;
return 0 ;
}
V_49 = ( unsigned long * ) ( V_7 -> V_18 . V_86 + ( V_146 << 4 ) ) ;
V_97 = V_49 [ 0 ] & ~ V_65 ;
V_98 = V_49 [ 1 ] ;
V_9 = F_1 ( & V_7 -> V_18 . V_19 [ V_146 ] ) ;
V_147 = V_9 -> V_34 ;
F_19 ( V_49 , V_97 ) ;
if ( ( V_144 & V_150 ) && ( V_97 & V_67 ) )
return 0 ;
V_148 = V_147 & ( V_81 | V_120 ) ;
V_149 = ( V_40 -> V_18 . V_151 . V_152 & V_153 ) ? V_154 : V_155 ;
V_144 &= ~ V_150 ;
if ( ! V_145 ) {
if ( V_147 & ( V_121 | V_82 ) )
return V_144 | V_156 ;
if ( ! F_47 ( V_148 , V_126 & V_149 ) )
return V_144 | V_157 ;
} else if ( V_144 & V_158 ) {
if ( ! F_48 ( V_148 , V_126 & V_149 ) )
return V_144 | V_159 ;
} else {
if ( ! F_47 ( V_148 , V_126 & V_149 ) )
return V_144 | V_159 ;
}
if ( V_145 && ( V_40 -> V_18 . V_151 . V_152 & V_160 ) ) {
unsigned int V_161 = F_49 ( V_147 , V_40 -> V_18 . V_162 ) ;
if ( V_144 & V_158 )
V_161 >>= 1 ;
if ( V_161 & 1 )
return V_144 | V_163 ;
}
V_40 -> V_18 . V_164 = V_2 ;
V_40 -> V_18 . V_165 = V_146 ;
V_40 -> V_18 . V_166 [ 0 ] = V_97 ;
V_40 -> V_18 . V_166 [ 1 ] = V_98 ;
if ( V_145 && ( V_40 -> V_18 . V_151 . V_152 & V_167 ) &&
( V_98 & ( V_71 | V_72 ) ) ==
( V_71 | V_72 ) )
return - 2 ;
return - 1 ;
}
