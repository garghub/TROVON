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
static void F_12 ( struct V_7 * V_7 , long V_22 ,
struct V_19 * V_20 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_19 * V_34 , * V_35 ;
unsigned long V_36 , V_37 , V_24 ;
struct V_38 * V_39 ;
unsigned long * V_21 ;
unsigned long V_40 ;
V_40 = V_33 & ( V_41 | V_42 ) ;
V_37 = V_20 -> V_43 |= V_40 ;
V_36 = F_13 ( V_37 , F_14 ( V_32 , V_37 ) ) ;
V_39 = F_15 ( F_16 ( V_7 ) , V_36 ) ;
if ( ! V_39 )
return;
V_21 = F_1 ( & V_39 -> V_10 . V_21 [ V_36 - V_39 -> V_44 ] ) ;
F_17 ( V_21 ) ;
V_24 = * V_21 & V_28 ;
V_34 = F_1 ( & V_7 -> V_10 . V_29 [ V_20 -> V_31 ] ) ;
V_35 = F_1 ( & V_7 -> V_10 . V_29 [ V_20 -> V_30 ] ) ;
V_34 -> V_30 = V_20 -> V_30 ;
V_35 -> V_31 = V_20 -> V_31 ;
if ( V_24 == V_22 ) {
V_24 = V_20 -> V_31 ;
if ( V_24 == V_22 )
* V_21 &= ~ ( V_27 | V_28 ) ;
else
* V_21 = ( * V_21 & ~ V_28 ) | V_24 ;
}
* V_21 |= V_40 << V_45 ;
F_11 ( V_21 ) ;
}
static T_1 F_18 ( T_2 * V_46 , unsigned long V_47 ,
int V_48 , unsigned long * V_49 )
{
T_1 * V_50 ;
unsigned long V_51 = * V_49 ;
unsigned int V_52 ;
V_50 = F_19 ( V_46 , V_47 , & V_52 ) ;
if ( ! V_50 )
return F_20 ( 0 ) ;
if ( V_52 )
* V_49 = 1ul << V_52 ;
else
* V_49 = V_53 ;
if ( V_51 > * V_49 )
return F_20 ( 0 ) ;
if ( ! F_3 ( * V_50 ) )
return F_20 ( 0 ) ;
return F_21 ( V_50 , V_48 ) ;
}
static inline void F_22 ( unsigned long * V_54 , unsigned long V_32 )
{
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_54 [ 0 ] = V_32 ;
}
long F_23 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_22 , unsigned long V_55 , unsigned long V_37 ,
T_2 * V_46 , bool V_23 , unsigned long * V_56 )
{
unsigned long V_26 , V_57 , V_58 , V_36 , V_59 ;
unsigned long V_60 , V_47 ;
unsigned long * V_54 ;
struct V_19 * V_20 ;
unsigned long V_61 ;
struct V_38 * V_39 ;
unsigned long * V_62 , V_63 ;
unsigned long V_64 ;
unsigned long * V_21 ;
T_1 V_65 ;
unsigned int V_48 ;
unsigned long V_66 ;
unsigned long V_40 ;
V_59 = F_14 ( V_55 , V_37 ) ;
if ( ! V_59 )
return V_67 ;
V_48 = F_24 ( V_37 ) ;
V_55 &= ~ ( V_68 | V_69 | V_70 ) ;
V_37 &= ~ V_71 ;
V_61 = V_37 ;
V_66 = V_7 -> V_72 ;
F_25 () ;
V_58 = ( V_37 & V_73 ) & ~ ( V_59 - 1 ) ;
V_36 = V_58 >> V_5 ;
V_39 = F_15 ( F_16 ( V_7 ) , V_36 ) ;
V_57 = 0 ;
V_64 = ~ 0ul ;
V_21 = NULL ;
if ( ! ( V_39 && ! ( V_39 -> V_8 & V_74 ) ) ) {
if ( ! F_26 ( V_75 ) )
return V_67 ;
V_55 |= V_69 ;
V_37 |= V_76 | V_77 ;
goto V_78;
}
if ( ! F_27 ( V_39 , V_59 ) )
return V_67 ;
V_60 = V_36 - V_39 -> V_44 ;
V_21 = & V_39 -> V_10 . V_21 [ V_60 ] ;
if ( ! V_7 -> V_10 . V_15 ) {
V_62 = V_39 -> V_10 . V_79 ;
if ( ! V_62 )
return V_67 ;
V_62 += V_60 ;
if ( V_23 )
V_62 = F_1 ( V_62 ) ;
V_57 = * V_62 ;
if ( ! V_57 )
return V_80 ;
V_64 = V_57 & ( V_81 | V_82 ) ;
V_63 = V_53 << ( V_57 & V_83 ) ;
V_57 &= V_6 ;
} else {
V_47 = F_28 ( V_39 , V_36 ) ;
V_63 = V_59 ;
V_65 = F_18 ( V_46 , V_47 , V_48 , & V_63 ) ;
if ( F_3 ( V_65 ) ) {
if ( V_48 && ! F_29 ( V_65 ) )
V_37 = F_30 ( V_37 ) ;
V_64 = F_31 ( F_32 ( V_65 ) ) ;
V_57 = F_4 ( V_65 ) << V_5 ;
}
}
if ( V_63 < V_59 )
return V_67 ;
if ( V_57 && V_63 > V_59 )
V_57 |= V_58 & ( V_63 - 1 ) ;
V_37 &= ~ ( V_84 - V_59 ) ;
V_37 |= V_57 ;
if ( V_57 )
V_55 |= V_70 ;
else
V_55 |= V_69 ;
if ( V_64 != ~ 0ul && ! F_33 ( V_37 , V_64 ) ) {
if ( V_64 )
return V_67 ;
V_37 &= ~ ( V_82 | V_81 | V_85 ) ;
V_37 |= V_86 ;
}
V_78:
if ( V_22 >= V_7 -> V_10 . V_87 )
return V_67 ;
if ( F_34 ( ( V_8 & V_88 ) == 0 ) ) {
V_22 &= ~ 7UL ;
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
if ( ( * V_54 & V_70 ) == 0 &&
F_35 ( V_54 , V_68 | V_70 |
V_69 ) )
break;
V_54 += 2 ;
}
if ( V_26 == 8 ) {
V_54 -= 16 ;
for ( V_26 = 0 ; V_26 < 8 ; ++ V_26 ) {
while ( ! F_35 ( V_54 , V_68 ) )
F_36 () ;
if ( ! ( * V_54 & ( V_70 | V_69 ) ) )
break;
* V_54 &= ~ V_68 ;
V_54 += 2 ;
}
if ( V_26 == 8 )
return V_90 ;
}
V_22 += V_26 ;
} else {
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
if ( ! F_35 ( V_54 , V_68 | V_70 |
V_69 ) ) {
while ( ! F_35 ( V_54 , V_68 ) )
F_36 () ;
if ( * V_54 & ( V_70 | V_69 ) ) {
* V_54 &= ~ V_68 ;
return V_90 ;
}
}
}
V_20 = & V_7 -> V_10 . V_29 [ V_22 ] ;
if ( V_23 )
V_20 = F_1 ( V_20 ) ;
if ( V_20 ) {
V_20 -> V_43 = V_61 ;
F_37 ( V_7 , V_20 ) ;
}
if ( V_55 & V_70 ) {
if ( V_23 )
V_21 = F_1 ( V_21 ) ;
F_17 ( V_21 ) ;
if ( V_7 -> V_10 . V_15 &&
F_38 ( V_7 , V_66 ) ) {
V_55 |= V_69 ;
V_55 &= ~ V_70 ;
F_11 ( V_21 ) ;
} else {
F_10 ( V_7 , V_20 , V_21 , V_22 ,
V_23 ) ;
V_40 = * V_21 >> V_45 ;
V_37 &= V_40 | ~ ( V_41 | V_42 ) ;
}
}
V_54 [ 1 ] = V_37 ;
F_39 () ;
V_54 [ 0 ] = V_55 ;
asm volatile("ptesync" : : : "memory");
* V_56 = V_22 ;
return V_91 ;
}
long F_40 ( struct V_92 * V_93 , unsigned long V_8 ,
long V_22 , unsigned long V_55 , unsigned long V_37 )
{
return F_23 ( V_93 -> V_7 , V_8 , V_22 , V_55 , V_37 ,
V_93 -> V_10 . V_46 , true , & V_93 -> V_10 . V_94 [ 4 ] ) ;
}
static inline int F_41 ( unsigned int * V_95 )
{
unsigned int V_96 , V_97 ;
unsigned int V_98 = V_99 ;
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
return V_97 == 0 ;
}
long F_42 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_100 ,
unsigned long * V_101 )
{
unsigned long * V_54 ;
unsigned long V_102 , V_103 , V_104 ;
struct V_19 * V_20 ;
if ( V_22 >= V_7 -> V_10 . V_87 )
return V_67 ;
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
while ( ! F_35 ( V_54 , V_68 ) )
F_36 () ;
if ( ( V_54 [ 0 ] & ( V_69 | V_70 ) ) == 0 ||
( ( V_8 & V_105 ) && ( V_54 [ 0 ] & ~ 0x7fUL ) != V_100 ) ||
( ( V_8 & V_106 ) && ( V_54 [ 0 ] & V_100 ) != 0 ) ) {
V_54 [ 0 ] &= ~ V_68 ;
return V_107 ;
}
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
V_102 = V_54 [ 0 ] & ~ V_68 ;
if ( V_102 & V_70 ) {
V_54 [ 0 ] &= ~ V_70 ;
V_104 = F_43 ( V_102 , V_54 [ 1 ] , V_22 ) ;
if ( F_6 ( V_7 , V_8 ) ) {
while ( ! F_41 ( & V_7 -> V_10 . V_108 ) )
F_36 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_108 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
F_12 ( V_7 , V_22 , V_20 , V_102 , V_54 [ 1 ] ) ;
}
V_103 = V_20 -> V_43 & ~ V_71 ;
F_37 ( V_7 , V_20 ) ;
F_22 ( V_54 , 0 ) ;
V_101 [ 0 ] = V_102 ;
V_101 [ 1 ] = V_103 ;
return V_91 ;
}
long F_44 ( struct V_92 * V_93 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_100 )
{
return F_42 ( V_93 -> V_7 , V_8 , V_22 , V_100 ,
& V_93 -> V_10 . V_94 [ 4 ] ) ;
}
long F_45 ( struct V_92 * V_93 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
unsigned long * args = & V_93 -> V_10 . V_94 [ 4 ] ;
unsigned long * V_109 , * V_110 [ 4 ] , V_111 [ 4 ] ;
long int V_26 , V_112 , V_113 , V_114 , V_115 , V_116 [ 4 ] ;
unsigned long V_8 , V_117 , V_22 , V_40 ;
long int V_118 = 0 ;
long int V_119 = V_91 ;
struct V_19 * V_20 , * V_120 [ 4 ] ;
if ( F_46 ( & V_7 -> V_121 ) == 1 )
V_118 = 1 ;
for ( V_26 = 0 ; V_26 < 4 && V_119 == V_91 ; ) {
V_114 = 0 ;
for (; V_26 < 4 ; ++ V_26 ) {
V_112 = V_26 * 2 ;
V_22 = args [ V_112 ] ;
V_8 = V_22 >> 56 ;
V_22 &= ( ( 1ul << 56 ) - 1 ) ;
V_117 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_117 == 3 ) {
V_26 = 4 ;
break;
}
if ( V_117 != 1 || V_8 == 3 ||
V_22 >= V_7 -> V_10 . V_87 ) {
args [ V_112 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_22 ;
V_119 = V_67 ;
break;
}
V_109 = ( unsigned long * )
( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
if ( ! F_35 ( V_109 , V_68 ) ) {
if ( V_114 )
break;
while ( ! F_35 ( V_109 , V_68 ) )
F_36 () ;
}
V_115 = 0 ;
if ( V_109 [ 0 ] & ( V_69 | V_70 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_115 = 1 ;
break;
case 1 :
if ( ! ( V_109 [ 0 ] & args [ V_112 + 1 ] ) )
V_115 = 1 ;
break;
case 2 :
if ( ( V_109 [ 0 ] & ~ 0x7fUL ) == args [ V_112 + 1 ] )
V_115 = 1 ;
break;
}
}
if ( ! V_115 ) {
V_109 [ 0 ] &= ~ V_68 ;
args [ V_112 ] = ( ( 0x90 | V_8 ) << 56 ) + V_22 ;
continue;
}
args [ V_112 ] = ( ( 0x80 | V_8 ) << 56 ) + V_22 ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
F_37 ( V_7 , V_20 ) ;
if ( ! ( V_109 [ 0 ] & V_70 ) ) {
V_40 = V_20 -> V_43 & ( V_41 | V_42 ) ;
args [ V_112 ] |= V_40 << ( 56 - 5 ) ;
V_109 [ 0 ] = 0 ;
continue;
}
V_109 [ 0 ] &= ~ V_70 ;
V_111 [ V_114 ] = F_43 ( V_109 [ 0 ] , V_109 [ 1 ] , V_22 ) ;
V_116 [ V_114 ] = V_112 ;
V_110 [ V_114 ] = V_109 ;
V_120 [ V_114 ] = V_20 ;
++ V_114 ;
}
if ( ! V_114 )
break;
if ( ! V_118 ) {
while( ! F_41 ( & V_7 -> V_10 . V_108 ) )
F_36 () ;
asm volatile("ptesync" : : : "memory");
for ( V_113 = 0 ; V_113 < V_114 ; ++ V_113 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (tlbrb[k]),
"r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_108 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
for ( V_113 = 0 ; V_113 < V_114 ; ++ V_113 )
asm volatile("tlbiel %0" : : "r" (tlbrb[k]));
asm volatile("ptesync" : : : "memory");
}
for ( V_113 = 0 ; V_113 < V_114 ; ++ V_113 ) {
V_112 = V_116 [ V_113 ] ;
V_22 = args [ V_112 ] & ( ( 1ul << 56 ) - 1 ) ;
V_109 = V_110 [ V_113 ] ;
V_20 = V_120 [ V_113 ] ;
F_12 ( V_7 , V_22 , V_20 , V_109 [ 0 ] , V_109 [ 1 ] ) ;
V_40 = V_20 -> V_43 & ( V_41 | V_42 ) ;
args [ V_112 ] |= V_40 << ( 56 - 5 ) ;
V_109 [ 0 ] = 0 ;
}
}
return V_119 ;
}
long F_47 ( struct V_92 * V_93 , unsigned long V_8 ,
unsigned long V_22 , unsigned long V_100 ,
unsigned long V_122 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
unsigned long * V_54 ;
struct V_19 * V_20 ;
unsigned long V_102 , V_103 , V_104 , V_123 , V_124 ;
if ( V_22 >= V_7 -> V_10 . V_87 )
return V_67 ;
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
while ( ! F_35 ( V_54 , V_68 ) )
F_36 () ;
if ( ( V_54 [ 0 ] & ( V_69 | V_70 ) ) == 0 ||
( ( V_8 & V_105 ) && ( V_54 [ 0 ] & ~ 0x7fUL ) != V_100 ) ) {
V_54 [ 0 ] &= ~ V_68 ;
return V_107 ;
}
V_102 = V_54 [ 0 ] ;
V_124 = ( V_8 << 55 ) & V_84 ;
V_124 |= ( V_8 << 48 ) & V_76 ;
V_124 |= V_8 & ( V_125 | V_126 | V_77 ) ;
V_123 = V_84 | V_125 | V_126 |
V_76 | V_77 ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
if ( V_20 ) {
V_103 = ( V_20 -> V_43 & ~ V_123 ) | V_124 ;
V_20 -> V_43 = V_103 ;
F_37 ( V_7 , V_20 ) ;
}
V_103 = ( V_54 [ 1 ] & ~ V_123 ) | V_124 ;
if ( V_102 & V_70 ) {
V_104 = F_43 ( V_102 , V_103 , V_22 ) ;
V_54 [ 0 ] = V_102 & ~ V_70 ;
if ( F_6 ( V_7 , V_8 ) ) {
while( ! F_41 ( & V_7 -> V_10 . V_108 ) )
F_36 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_108 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
if ( F_24 ( V_103 ) && V_7 -> V_10 . V_15 ) {
unsigned long V_59 , V_36 , V_47 ;
struct V_38 * V_39 ;
T_2 * V_46 = V_93 -> V_10 . V_46 ;
T_1 V_65 ;
V_59 = F_14 ( V_102 , V_103 ) ;
V_36 = ( ( V_103 & V_73 ) & ~ ( V_59 - 1 ) ) >> V_5 ;
V_39 = F_15 ( F_16 ( V_7 ) , V_36 ) ;
if ( V_39 ) {
V_47 = F_28 ( V_39 , V_36 ) ;
V_65 = F_18 ( V_46 , V_47 , 1 , & V_59 ) ;
if ( F_3 ( V_65 ) && ! F_29 ( V_65 ) )
V_103 = F_30 ( V_103 ) ;
}
}
}
V_54 [ 1 ] = V_103 ;
F_39 () ;
V_54 [ 0 ] = V_102 & ~ V_68 ;
asm volatile("ptesync" : : : "memory");
return V_91 ;
}
long F_48 ( struct V_92 * V_93 , unsigned long V_8 ,
unsigned long V_22 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
unsigned long * V_54 , V_102 , V_103 ;
int V_26 , V_114 = 1 ;
struct V_19 * V_20 = NULL ;
if ( V_22 >= V_7 -> V_10 . V_87 )
return V_67 ;
if ( V_8 & V_127 ) {
V_22 &= ~ 3 ;
V_114 = 4 ;
}
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_22 ] ) ;
for ( V_26 = 0 ; V_26 < V_114 ; ++ V_26 , ++ V_22 ) {
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_22 << 4 ) ) ;
V_102 = V_54 [ 0 ] & ~ V_68 ;
V_103 = V_54 [ 1 ] ;
if ( V_102 & V_69 ) {
V_102 &= ~ V_69 ;
V_102 |= V_70 ;
}
if ( V_102 & V_70 ) {
V_103 = V_20 [ V_26 ] . V_43 | ( V_103 & ( V_41 | V_42 ) ) ;
V_103 &= ~ V_71 ;
}
V_93 -> V_10 . V_94 [ 4 + V_26 * 2 ] = V_102 ;
V_93 -> V_10 . V_94 [ 5 + V_26 * 2 ] = V_103 ;
}
return V_91 ;
}
void F_49 ( struct V_7 * V_7 , unsigned long * V_128 ,
unsigned long V_22 )
{
unsigned long V_104 ;
V_128 [ 0 ] &= ~ V_70 ;
V_104 = F_43 ( V_128 [ 0 ] , V_128 [ 1 ] , V_22 ) ;
while ( ! F_41 ( & V_7 -> V_10 . V_108 ) )
F_36 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_108 = 0 ;
}
void F_50 ( struct V_7 * V_7 , unsigned long * V_128 ,
unsigned long V_22 )
{
unsigned long V_104 ;
unsigned char V_129 ;
V_104 = F_43 ( V_128 [ 0 ] , V_128 [ 1 ] , V_22 ) ;
V_129 = ( V_128 [ 1 ] & ~ V_41 ) >> 8 ;
* ( ( char * ) V_128 + 14 ) = V_129 ;
while ( ! F_41 ( & V_7 -> V_10 . V_108 ) )
F_36 () ;
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_7 -> V_10 . V_108 = 0 ;
}
long F_51 ( struct V_7 * V_7 , T_3 V_130 , unsigned long V_131 ,
unsigned long V_132 )
{
unsigned int V_26 ;
unsigned int V_133 ;
unsigned long V_134 ;
unsigned long V_135 , V_136 ;
unsigned long V_100 ;
unsigned long * V_54 ;
unsigned long V_123 , V_137 ;
unsigned long V_102 , V_103 ;
V_123 = V_138 | V_139 | V_140 ;
V_137 = 0 ;
V_133 = 12 ;
if ( V_131 & V_141 ) {
V_123 |= V_142 ;
V_137 |= V_142 ;
V_133 = V_143 [ ( V_131 & V_144 ) >> 4 ] ;
}
if ( V_131 & V_145 ) {
V_134 = ( 1UL << 40 ) - 1 ;
V_135 = ( V_131 & ~ V_138 ) >> V_146 ;
V_135 ^= V_135 << 25 ;
} else {
V_134 = ( 1UL << 28 ) - 1 ;
V_135 = ( V_131 & ~ V_138 ) >> V_147 ;
}
V_136 = ( V_135 ^ ( ( V_130 & V_134 ) >> V_133 ) ) & V_7 -> V_10 . V_148 ;
V_100 = V_131 & ~ ( V_134 >> 16 ) ;
V_100 |= ( V_130 & V_134 ) >> 16 ;
if ( V_133 >= 24 )
V_100 &= ~ ( ( 1UL << ( V_133 - 16 ) ) - 1 ) ;
else
V_100 &= ~ 0x7fUL ;
V_137 |= V_100 ;
for (; ; ) {
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_136 << 7 ) ) ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 += 2 ) {
V_102 = V_54 [ V_26 ] & ~ V_68 ;
if ( ! ( V_102 & V_132 ) || ( V_102 & V_123 ) != V_137 )
continue;
while ( ! F_35 ( & V_54 [ V_26 ] , V_68 ) )
F_36 () ;
V_102 = V_54 [ V_26 ] & ~ V_68 ;
V_103 = V_54 [ V_26 + 1 ] ;
if ( ( V_102 & V_132 ) && ( V_102 & V_123 ) == V_137 &&
F_14 ( V_102 , V_103 ) == ( 1ul << V_133 ) )
return ( V_136 << 3 ) + ( V_26 >> 1 ) ;
V_54 [ V_26 ] = V_102 ;
}
if ( V_137 & V_140 )
break;
V_137 |= V_140 ;
V_136 = V_136 ^ V_7 -> V_10 . V_148 ;
}
return - 1 ;
}
long F_52 ( struct V_92 * V_93 , unsigned long V_2 ,
unsigned long V_131 , unsigned int V_149 , bool V_150 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
long int V_151 ;
unsigned long V_102 , V_103 , V_152 ;
unsigned long * V_54 ;
unsigned long V_132 ;
struct V_19 * V_20 ;
unsigned long V_153 , V_154 ;
V_132 = V_70 ;
if ( V_149 & V_155 )
V_132 |= V_69 ;
V_151 = F_51 ( V_7 , V_2 , V_131 , V_132 ) ;
if ( V_151 < 0 ) {
if ( V_149 & V_155 )
return V_149 ;
return 0 ;
}
V_54 = ( unsigned long * ) ( V_7 -> V_10 . V_89 + ( V_151 << 4 ) ) ;
V_102 = V_54 [ 0 ] & ~ V_68 ;
V_103 = V_54 [ 1 ] ;
V_20 = F_1 ( & V_7 -> V_10 . V_29 [ V_151 ] ) ;
V_152 = V_20 -> V_43 ;
F_22 ( V_54 , V_102 ) ;
if ( ( V_149 & V_155 ) && ( V_102 & V_70 ) )
return 0 ;
V_153 = V_152 & ( V_84 | V_125 ) ;
V_154 = ( V_93 -> V_10 . V_156 . V_157 & V_158 ) ? V_159 : V_160 ;
V_149 &= ~ V_155 ;
if ( ! V_150 ) {
if ( V_152 & ( V_126 | V_85 ) )
return V_149 | V_161 ;
if ( ! F_53 ( V_153 , V_131 & V_154 ) )
return V_149 | V_162 ;
} else if ( V_149 & V_163 ) {
if ( ! F_54 ( V_153 , V_131 & V_154 ) )
return V_149 | V_164 ;
} else {
if ( ! F_53 ( V_153 , V_131 & V_154 ) )
return V_149 | V_164 ;
}
if ( V_150 && ( V_93 -> V_10 . V_156 . V_157 & V_165 ) ) {
unsigned int V_166 = F_55 ( V_152 , V_93 -> V_10 . V_167 ) ;
if ( V_149 & V_163 )
V_166 >>= 1 ;
if ( V_166 & 1 )
return V_149 | V_168 ;
}
V_93 -> V_10 . V_169 = V_2 ;
V_93 -> V_10 . V_170 = V_151 ;
V_93 -> V_10 . V_171 [ 0 ] = V_102 ;
V_93 -> V_10 . V_171 [ 1 ] = V_103 ;
if ( V_150 && ( V_93 -> V_10 . V_156 . V_157 & V_172 ) &&
( V_103 & ( V_76 | V_77 ) ) ==
( V_76 | V_77 ) )
return - 2 ;
return - 1 ;
}
