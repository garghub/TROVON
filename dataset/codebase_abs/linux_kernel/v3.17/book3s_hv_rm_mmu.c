static void * F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
T_1 * V_3 ;
V_3 = F_2 ( V_4 , V_2 , NULL ) ;
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
F_9 ( V_12 -> V_13 . V_18 -> V_19 ,
& V_7 -> V_10 . V_17 ) ;
}
return V_9 ;
}
void F_10 ( struct V_7 * V_7 , struct V_20 * V_21 ,
unsigned long * V_22 , long V_23 , int V_24 )
{
struct V_20 * V_25 , * V_26 ;
unsigned long V_27 ;
if ( * V_22 & V_28 ) {
V_27 = * V_22 & V_29 ;
V_25 = & V_7 -> V_10 . V_30 [ V_27 ] ;
if ( V_24 )
V_25 = F_1 ( V_25 ) ;
V_26 = & V_7 -> V_10 . V_30 [ V_25 -> V_31 ] ;
if ( V_24 )
V_26 = F_1 ( V_26 ) ;
V_21 -> V_32 = V_27 ;
V_21 -> V_31 = V_25 -> V_31 ;
V_26 -> V_32 = V_23 ;
V_25 -> V_31 = V_23 ;
} else {
V_21 -> V_32 = V_21 -> V_31 = V_23 ;
* V_22 = ( * V_22 & ~ V_29 ) |
V_23 | V_28 ;
}
F_11 ( V_22 ) ;
}
static void F_12 ( struct V_7 * V_7 , long V_23 ,
struct V_20 * V_21 ,
unsigned long V_33 , unsigned long V_34 )
{
struct V_20 * V_35 , * V_36 ;
unsigned long V_37 , V_38 , V_25 ;
struct V_39 * V_40 ;
unsigned long * V_22 ;
unsigned long V_41 ;
V_41 = V_34 & ( V_42 | V_43 ) ;
V_38 = V_21 -> V_44 |= V_41 ;
V_37 = F_13 ( V_38 , F_14 ( V_33 , V_38 ) ) ;
V_40 = F_15 ( F_16 ( V_7 ) , V_37 ) ;
if ( ! V_40 )
return;
V_22 = F_1 ( & V_40 -> V_10 . V_22 [ V_37 - V_40 -> V_45 ] ) ;
F_17 ( V_22 ) ;
V_25 = * V_22 & V_29 ;
V_35 = F_1 ( & V_7 -> V_10 . V_30 [ V_21 -> V_32 ] ) ;
V_36 = F_1 ( & V_7 -> V_10 . V_30 [ V_21 -> V_31 ] ) ;
V_35 -> V_31 = V_21 -> V_31 ;
V_36 -> V_32 = V_21 -> V_32 ;
if ( V_25 == V_23 ) {
V_25 = V_21 -> V_32 ;
if ( V_25 == V_23 )
* V_22 &= ~ ( V_28 | V_29 ) ;
else
* V_22 = ( * V_22 & ~ V_29 ) | V_25 ;
}
* V_22 |= V_41 << V_46 ;
F_11 ( V_22 ) ;
}
static T_1 F_18 ( T_2 * V_47 , unsigned long V_48 ,
int V_49 , unsigned long * V_50 )
{
T_1 * V_51 ;
unsigned long V_52 = * V_50 ;
unsigned int V_53 ;
V_51 = F_2 ( V_47 , V_48 , & V_53 ) ;
if ( ! V_51 )
return F_19 ( 0 ) ;
if ( V_53 )
* V_50 = 1ul << V_53 ;
else
* V_50 = V_54 ;
if ( V_52 > * V_50 )
return F_19 ( 0 ) ;
return F_20 ( V_51 , V_49 , V_53 ) ;
}
static inline void F_21 ( T_3 * V_55 , unsigned long V_33 )
{
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_55 [ 0 ] = F_22 ( V_33 ) ;
}
long F_23 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_23 , unsigned long V_56 , unsigned long V_38 ,
T_2 * V_47 , bool V_24 , unsigned long * V_57 )
{
unsigned long V_27 , V_58 , V_59 , V_37 , V_60 ;
unsigned long V_61 , V_48 ;
T_3 * V_55 ;
struct V_20 * V_21 ;
unsigned long V_62 ;
struct V_39 * V_40 ;
unsigned long * V_63 , V_64 ;
unsigned long V_65 ;
unsigned long * V_22 ;
T_1 V_66 ;
unsigned int V_49 ;
unsigned long V_67 ;
unsigned long V_41 ;
V_60 = F_14 ( V_56 , V_38 ) ;
if ( ! V_60 )
return V_68 ;
V_49 = F_24 ( V_38 ) ;
V_56 &= ~ ( V_69 | V_70 | V_71 ) ;
V_38 &= ~ V_72 ;
V_62 = V_38 ;
V_67 = V_7 -> V_73 ;
F_25 () ;
V_59 = ( V_38 & V_74 ) & ~ ( V_60 - 1 ) ;
V_37 = V_59 >> V_5 ;
V_40 = F_15 ( F_16 ( V_7 ) , V_37 ) ;
V_58 = 0 ;
V_65 = ~ 0ul ;
V_22 = NULL ;
if ( ! ( V_40 && ! ( V_40 -> V_8 & V_75 ) ) ) {
if ( ! F_26 ( V_76 ) )
return V_68 ;
V_56 |= V_70 ;
V_38 |= V_77 | V_78 ;
goto V_79;
}
if ( ! F_27 ( V_40 , V_60 ) )
return V_68 ;
V_61 = V_37 - V_40 -> V_45 ;
V_22 = & V_40 -> V_10 . V_22 [ V_61 ] ;
if ( ! V_7 -> V_10 . V_15 ) {
V_63 = V_40 -> V_10 . V_80 ;
if ( ! V_63 )
return V_68 ;
V_63 += V_61 ;
if ( V_24 )
V_63 = F_1 ( V_63 ) ;
V_58 = * V_63 ;
if ( ! V_58 )
return V_81 ;
V_65 = V_58 & ( V_82 | V_83 ) ;
V_64 = V_54 << ( V_58 & V_84 ) ;
V_58 &= V_6 ;
V_58 |= V_59 & ~ V_6 ;
} else {
V_48 = F_28 ( V_40 , V_37 ) ;
V_64 = V_60 ;
V_66 = F_18 ( V_47 , V_48 , V_49 ,
& V_64 ) ;
if ( F_3 ( V_66 ) && ! F_29 ( V_66 ) ) {
if ( V_49 && ! F_30 ( V_66 ) )
V_38 = F_31 ( V_38 ) ;
V_65 = F_32 ( F_33 ( V_66 ) ) ;
V_58 = F_4 ( V_66 ) << V_5 ;
V_58 |= V_48 & ( V_64 - 1 ) ;
V_58 |= V_59 & ~ V_6 ;
}
}
if ( V_64 < V_60 )
return V_68 ;
V_38 &= ~ ( V_85 - V_60 ) ;
V_38 |= V_58 ;
if ( V_58 )
V_56 |= V_71 ;
else
V_56 |= V_70 ;
if ( V_65 != ~ 0ul && ! F_34 ( V_38 , V_65 ) ) {
if ( V_65 )
return V_68 ;
V_38 &= ~ ( V_83 | V_82 | V_86 ) ;
V_38 |= V_87 ;
}
V_79:
if ( V_23 >= V_7 -> V_10 . V_88 )
return V_68 ;
if ( F_35 ( ( V_8 & V_89 ) == 0 ) ) {
V_23 &= ~ 7UL ;
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
if ( ( F_36 ( * V_55 ) & V_71 ) == 0 &&
F_37 ( V_55 , V_69 | V_71 |
V_70 ) )
break;
V_55 += 2 ;
}
if ( V_27 == 8 ) {
V_55 -= 16 ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
T_4 V_66 ;
while ( ! F_37 ( V_55 , V_69 ) )
F_38 () ;
V_66 = F_36 ( * V_55 ) ;
if ( ! ( V_66 & ( V_71 | V_70 ) ) )
break;
* V_55 &= ~ F_22 ( V_69 ) ;
V_55 += 2 ;
}
if ( V_27 == 8 )
return V_91 ;
}
V_23 += V_27 ;
} else {
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
if ( ! F_37 ( V_55 , V_69 | V_71 |
V_70 ) ) {
T_4 V_66 ;
while ( ! F_37 ( V_55 , V_69 ) )
F_38 () ;
V_66 = F_36 ( * V_55 ) ;
if ( V_66 & ( V_71 | V_70 ) ) {
* V_55 &= ~ F_22 ( V_69 ) ;
return V_91 ;
}
}
}
V_21 = & V_7 -> V_10 . V_30 [ V_23 ] ;
if ( V_24 )
V_21 = F_1 ( V_21 ) ;
if ( V_21 ) {
V_21 -> V_44 = V_62 ;
F_39 ( V_7 , V_21 ) ;
}
if ( V_56 & V_71 ) {
if ( V_24 )
V_22 = F_1 ( V_22 ) ;
F_17 ( V_22 ) ;
if ( V_7 -> V_10 . V_15 &&
F_40 ( V_7 , V_67 ) ) {
V_56 |= V_70 ;
V_56 &= ~ V_71 ;
F_11 ( V_22 ) ;
} else {
F_10 ( V_7 , V_21 , V_22 , V_23 ,
V_24 ) ;
V_41 = * V_22 >> V_46 ;
V_38 &= V_41 | ~ ( V_42 | V_43 ) ;
}
}
V_55 [ 1 ] = F_22 ( V_38 ) ;
F_41 () ;
V_55 [ 0 ] = F_22 ( V_56 ) ;
asm volatile("ptesync" : : : "memory");
* V_57 = V_23 ;
return V_92 ;
}
long F_42 ( struct V_14 * V_93 , unsigned long V_8 ,
long V_23 , unsigned long V_56 , unsigned long V_38 )
{
return F_23 ( V_93 -> V_7 , V_8 , V_23 , V_56 , V_38 ,
V_93 -> V_10 . V_47 , true , & V_93 -> V_10 . V_94 [ 4 ] ) ;
}
static inline int F_43 ( unsigned int * V_95 )
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
static void F_44 ( struct V_7 * V_7 , unsigned long * V_100 ,
long V_101 , int V_9 , bool V_102 )
{
long V_27 ;
if ( V_9 ) {
while ( ! F_43 ( & V_7 -> V_10 . V_103 ) )
F_38 () ;
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 ) {
unsigned long V_104 = V_100 [ V_27 ] ;
if ( V_104 & 1 )
asm volatile("tlbie %0,1" : :
"r" (rb & 0x0000fffffffff000ul));
else
asm volatile("tlbie %0,0" : :
"r" (rb & 0x0000fffffffff000ul));
}
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_103 = 0 ;
} else {
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 ) {
unsigned long V_104 = V_100 [ V_27 ] ;
if ( V_104 & 1 )
asm volatile("tlbiel %0,1" : :
"r" (rb & 0x0000fffffffff000ul));
else
asm volatile("tlbiel %0,0" : :
"r" (rb & 0x0000fffffffff000ul));
}
asm volatile("ptesync" : : : "memory");
}
}
static void F_45 ( struct V_7 * V_7 , unsigned long * V_100 ,
long V_101 , int V_9 , bool V_102 )
{
long V_27 ;
if ( F_26 ( V_105 ) ) {
F_44 ( V_7 , V_100 , V_101 , V_9 , V_102 ) ;
return;
}
if ( V_9 ) {
while ( ! F_43 ( & V_7 -> V_10 . V_103 ) )
F_38 () ;
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_103 = 0 ;
} else {
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 )
asm volatile("tlbiel %0" : : "r" (rbvalues[i]));
asm volatile("ptesync" : : : "memory");
}
}
long F_46 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_106 ,
unsigned long * V_107 )
{
T_3 * V_55 ;
unsigned long V_108 , V_109 , V_104 ;
struct V_20 * V_21 ;
T_4 V_66 ;
if ( V_23 >= V_7 -> V_10 . V_88 )
return V_68 ;
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
while ( ! F_37 ( V_55 , V_69 ) )
F_38 () ;
V_66 = F_36 ( V_55 [ 0 ] ) ;
if ( ( V_66 & ( V_70 | V_71 ) ) == 0 ||
( ( V_8 & V_110 ) && ( V_66 & ~ 0x7fUL ) != V_106 ) ||
( ( V_8 & V_111 ) && ( V_66 & V_106 ) != 0 ) ) {
V_55 [ 0 ] &= ~ F_22 ( V_69 ) ;
return V_112 ;
}
V_21 = F_1 ( & V_7 -> V_10 . V_30 [ V_23 ] ) ;
V_108 = V_66 & ~ V_69 ;
if ( V_108 & V_71 ) {
T_4 V_113 ;
V_113 = F_36 ( V_55 [ 1 ] ) ;
V_55 [ 0 ] &= ~ F_22 ( V_71 ) ;
V_104 = F_47 ( V_108 , V_113 , V_23 ) ;
F_45 ( V_7 , & V_104 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_12 ( V_7 , V_23 , V_21 , V_108 , V_113 ) ;
}
V_109 = V_21 -> V_44 & ~ V_72 ;
F_39 ( V_7 , V_21 ) ;
F_21 ( V_55 , 0 ) ;
V_107 [ 0 ] = V_108 ;
V_107 [ 1 ] = V_109 ;
return V_92 ;
}
long F_48 ( struct V_14 * V_93 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_106 )
{
return F_46 ( V_93 -> V_7 , V_8 , V_23 , V_106 ,
& V_93 -> V_10 . V_94 [ 4 ] ) ;
}
long F_49 ( struct V_14 * V_93 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
unsigned long * args = & V_93 -> V_10 . V_94 [ 4 ] ;
T_3 * V_114 , * V_115 [ 4 ] ;
unsigned long V_116 [ 4 ] ;
long int V_27 , V_117 , V_118 , V_119 , V_120 , V_121 [ 4 ] ;
unsigned long V_8 , V_122 , V_23 , V_41 ;
int V_9 ;
long int V_123 = V_92 ;
struct V_20 * V_21 , * V_124 [ 4 ] ;
T_4 V_125 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_27 = 0 ; V_27 < 4 && V_123 == V_92 ; ) {
V_119 = 0 ;
for (; V_27 < 4 ; ++ V_27 ) {
V_117 = V_27 * 2 ;
V_23 = args [ V_117 ] ;
V_8 = V_23 >> 56 ;
V_23 &= ( ( 1ul << 56 ) - 1 ) ;
V_122 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_122 == 3 ) {
V_27 = 4 ;
break;
}
if ( V_122 != 1 || V_8 == 3 ||
V_23 >= V_7 -> V_10 . V_88 ) {
args [ V_117 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_23 ;
V_123 = V_68 ;
break;
}
V_114 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
if ( ! F_37 ( V_114 , V_69 ) ) {
if ( V_119 )
break;
while ( ! F_37 ( V_114 , V_69 ) )
F_38 () ;
}
V_120 = 0 ;
V_125 = F_36 ( V_114 [ 0 ] ) ;
if ( V_125 & ( V_70 | V_71 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_120 = 1 ;
break;
case 1 :
if ( ! ( V_125 & args [ V_117 + 1 ] ) )
V_120 = 1 ;
break;
case 2 :
if ( ( V_125 & ~ 0x7fUL ) == args [ V_117 + 1 ] )
V_120 = 1 ;
break;
}
}
if ( ! V_120 ) {
V_114 [ 0 ] &= ~ F_22 ( V_69 ) ;
args [ V_117 ] = ( ( 0x90 | V_8 ) << 56 ) + V_23 ;
continue;
}
args [ V_117 ] = ( ( 0x80 | V_8 ) << 56 ) + V_23 ;
V_21 = F_1 ( & V_7 -> V_10 . V_30 [ V_23 ] ) ;
F_39 ( V_7 , V_21 ) ;
if ( ! ( V_125 & V_71 ) ) {
V_41 = V_21 -> V_44 & ( V_42 | V_43 ) ;
args [ V_117 ] |= V_41 << ( 56 - 5 ) ;
V_114 [ 0 ] = 0 ;
continue;
}
V_114 [ 0 ] &= ~ F_22 ( V_71 ) ;
V_116 [ V_119 ] = F_47 ( F_36 ( V_114 [ 0 ] ) ,
F_36 ( V_114 [ 1 ] ) , V_23 ) ;
V_121 [ V_119 ] = V_117 ;
V_115 [ V_119 ] = V_114 ;
V_124 [ V_119 ] = V_21 ;
++ V_119 ;
}
if ( ! V_119 )
break;
F_45 ( V_7 , V_116 , V_119 , V_9 , true ) ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 ) {
V_117 = V_121 [ V_118 ] ;
V_23 = args [ V_117 ] & ( ( 1ul << 56 ) - 1 ) ;
V_114 = V_115 [ V_118 ] ;
V_21 = V_124 [ V_118 ] ;
F_12 ( V_7 , V_23 , V_21 ,
F_36 ( V_114 [ 0 ] ) , F_36 ( V_114 [ 1 ] ) ) ;
V_41 = V_21 -> V_44 & ( V_42 | V_43 ) ;
args [ V_117 ] |= V_41 << ( 56 - 5 ) ;
V_114 [ 0 ] = 0 ;
}
}
return V_123 ;
}
long F_50 ( struct V_14 * V_93 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_106 ,
unsigned long V_126 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
T_3 * V_55 ;
struct V_20 * V_21 ;
unsigned long V_108 , V_109 , V_104 , V_127 , V_128 ;
T_4 V_66 ;
if ( V_23 >= V_7 -> V_10 . V_88 )
return V_68 ;
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
while ( ! F_37 ( V_55 , V_69 ) )
F_38 () ;
V_66 = F_36 ( V_55 [ 0 ] ) ;
if ( ( V_66 & ( V_70 | V_71 ) ) == 0 ||
( ( V_8 & V_110 ) && ( V_66 & ~ 0x7fUL ) != V_106 ) ) {
V_55 [ 0 ] &= ~ F_22 ( V_69 ) ;
return V_112 ;
}
V_108 = V_66 ;
V_128 = ( V_8 << 55 ) & V_85 ;
V_128 |= ( V_8 << 48 ) & V_77 ;
V_128 |= V_8 & ( V_129 | V_130 | V_78 ) ;
V_127 = V_85 | V_129 | V_130 |
V_77 | V_78 ;
V_21 = F_1 ( & V_7 -> V_10 . V_30 [ V_23 ] ) ;
if ( V_21 ) {
V_109 = ( V_21 -> V_44 & ~ V_127 ) | V_128 ;
V_21 -> V_44 = V_109 ;
F_39 ( V_7 , V_21 ) ;
}
V_109 = ( F_36 ( V_55 [ 1 ] ) & ~ V_127 ) | V_128 ;
if ( V_108 & V_71 ) {
V_104 = F_47 ( V_108 , V_109 , V_23 ) ;
V_55 [ 0 ] = F_22 ( V_108 & ~ V_71 ) ;
F_45 ( V_7 , & V_104 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
if ( F_24 ( V_109 ) && V_7 -> V_10 . V_15 ) {
unsigned long V_60 , V_37 , V_48 ;
struct V_39 * V_40 ;
T_2 * V_47 = V_93 -> V_10 . V_47 ;
T_1 V_66 ;
V_60 = F_14 ( V_108 , V_109 ) ;
V_37 = ( ( V_109 & V_74 ) & ~ ( V_60 - 1 ) ) >> V_5 ;
V_40 = F_15 ( F_16 ( V_7 ) , V_37 ) ;
if ( V_40 ) {
V_48 = F_28 ( V_40 , V_37 ) ;
V_66 = F_18 ( V_47 , V_48 ,
1 , & V_60 ) ;
if ( F_3 ( V_66 ) && ! F_30 ( V_66 ) )
V_109 = F_31 ( V_109 ) ;
}
}
}
V_55 [ 1 ] = F_22 ( V_109 ) ;
F_41 () ;
V_55 [ 0 ] = F_22 ( V_108 & ~ V_69 ) ;
asm volatile("ptesync" : : : "memory");
return V_92 ;
}
long F_51 ( struct V_14 * V_93 , unsigned long V_8 ,
unsigned long V_23 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
T_3 * V_55 ;
unsigned long V_108 , V_109 ;
int V_27 , V_119 = 1 ;
struct V_20 * V_21 = NULL ;
if ( V_23 >= V_7 -> V_10 . V_88 )
return V_68 ;
if ( V_8 & V_131 ) {
V_23 &= ~ 3 ;
V_119 = 4 ;
}
V_21 = F_1 ( & V_7 -> V_10 . V_30 [ V_23 ] ) ;
for ( V_27 = 0 ; V_27 < V_119 ; ++ V_27 , ++ V_23 ) {
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_23 << 4 ) ) ;
V_108 = F_36 ( V_55 [ 0 ] ) & ~ V_69 ;
V_109 = F_36 ( V_55 [ 1 ] ) ;
if ( V_108 & V_70 ) {
V_108 &= ~ V_70 ;
V_108 |= V_71 ;
}
if ( V_108 & V_71 ) {
V_109 = V_21 [ V_27 ] . V_44 | ( V_109 & ( V_42 | V_43 ) ) ;
V_109 &= ~ V_72 ;
}
V_93 -> V_10 . V_94 [ 4 + V_27 * 2 ] = V_108 ;
V_93 -> V_10 . V_94 [ 5 + V_27 * 2 ] = V_109 ;
}
return V_92 ;
}
void F_52 ( struct V_7 * V_7 , T_3 * V_132 ,
unsigned long V_23 )
{
unsigned long V_104 ;
V_132 [ 0 ] &= ~ F_22 ( V_71 ) ;
V_104 = F_47 ( F_36 ( V_132 [ 0 ] ) , F_36 ( V_132 [ 1 ] ) ,
V_23 ) ;
F_45 ( V_7 , & V_104 , 1 , 1 , true ) ;
}
void F_53 ( struct V_7 * V_7 , T_3 * V_132 ,
unsigned long V_23 )
{
unsigned long V_104 ;
unsigned char V_133 ;
V_104 = F_47 ( F_36 ( V_132 [ 0 ] ) , F_36 ( V_132 [ 1 ] ) ,
V_23 ) ;
V_133 = ( F_36 ( V_132 [ 1 ] ) & ~ V_42 ) >> 8 ;
* ( ( char * ) V_132 + 14 ) = V_133 ;
F_45 ( V_7 , & V_104 , 1 , 1 , false ) ;
}
long F_54 ( struct V_7 * V_7 , T_5 V_134 , unsigned long V_135 ,
unsigned long V_136 )
{
unsigned int V_27 ;
unsigned int V_137 ;
unsigned long V_138 ;
unsigned long V_139 , V_140 ;
unsigned long V_106 ;
T_3 * V_55 ;
unsigned long V_127 , V_141 ;
unsigned long V_108 , V_109 ;
V_127 = V_142 | V_143 | V_144 ;
V_141 = 0 ;
V_137 = 12 ;
if ( V_135 & V_145 ) {
V_127 |= V_146 ;
V_141 |= V_146 ;
V_137 = V_147 [ ( V_135 & V_148 ) >> 4 ] ;
}
if ( V_135 & V_149 ) {
V_138 = ( 1UL << 40 ) - 1 ;
V_139 = ( V_135 & ~ V_142 ) >> V_150 ;
V_139 ^= V_139 << 25 ;
} else {
V_138 = ( 1UL << 28 ) - 1 ;
V_139 = ( V_135 & ~ V_142 ) >> V_151 ;
}
V_140 = ( V_139 ^ ( ( V_134 & V_138 ) >> V_137 ) ) & V_7 -> V_10 . V_152 ;
V_106 = V_135 & ~ ( V_138 >> 16 ) ;
V_106 |= ( V_134 & V_138 ) >> 16 ;
if ( V_137 >= 24 )
V_106 &= ~ ( ( 1UL << ( V_137 - 16 ) ) - 1 ) ;
else
V_106 &= ~ 0x7fUL ;
V_141 |= V_106 ;
for (; ; ) {
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_140 << 7 ) ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 += 2 ) {
V_108 = F_36 ( V_55 [ V_27 ] ) & ~ V_69 ;
if ( ! ( V_108 & V_136 ) || ( V_108 & V_127 ) != V_141 )
continue;
while ( ! F_37 ( & V_55 [ V_27 ] , V_69 ) )
F_38 () ;
V_108 = F_36 ( V_55 [ V_27 ] ) & ~ V_69 ;
V_109 = F_36 ( V_55 [ V_27 + 1 ] ) ;
if ( ( V_108 & V_136 ) && ( V_108 & V_127 ) == V_141 &&
F_55 ( V_108 , V_109 ) == ( 1ul << V_137 ) )
return ( V_140 << 3 ) + ( V_27 >> 1 ) ;
V_55 [ V_27 ] = F_22 ( V_108 ) ;
}
if ( V_141 & V_144 )
break;
V_141 |= V_144 ;
V_140 = V_140 ^ V_7 -> V_10 . V_152 ;
}
return - 1 ;
}
long F_56 ( struct V_14 * V_93 , unsigned long V_2 ,
unsigned long V_135 , unsigned int V_153 , bool V_154 )
{
struct V_7 * V_7 = V_93 -> V_7 ;
long int V_155 ;
unsigned long V_108 , V_109 , V_156 ;
T_3 * V_55 ;
unsigned long V_136 ;
struct V_20 * V_21 ;
unsigned long V_157 , V_158 ;
V_136 = V_71 ;
if ( V_153 & V_159 )
V_136 |= V_70 ;
V_155 = F_54 ( V_7 , V_2 , V_135 , V_136 ) ;
if ( V_155 < 0 ) {
if ( V_153 & V_159 )
return V_153 ;
return 0 ;
}
V_55 = ( T_3 * ) ( V_7 -> V_10 . V_90 + ( V_155 << 4 ) ) ;
V_108 = F_36 ( V_55 [ 0 ] ) & ~ V_69 ;
V_109 = F_36 ( V_55 [ 1 ] ) ;
V_21 = F_1 ( & V_7 -> V_10 . V_30 [ V_155 ] ) ;
V_156 = V_21 -> V_44 ;
F_21 ( V_55 , V_108 ) ;
if ( ( V_153 & V_159 ) && ( V_108 & V_71 ) )
return 0 ;
V_157 = V_156 & ( V_85 | V_129 ) ;
V_158 = ( V_93 -> V_10 . V_160 . V_161 & V_162 ) ? V_163 : V_164 ;
V_153 &= ~ V_159 ;
if ( ! V_154 ) {
if ( V_156 & ( V_130 | V_86 ) )
return V_153 | V_165 ;
if ( ! F_57 ( V_157 , V_135 & V_158 ) )
return V_153 | V_166 ;
} else if ( V_153 & V_167 ) {
if ( ! F_58 ( V_157 , V_135 & V_158 ) )
return V_153 | V_168 ;
} else {
if ( ! F_57 ( V_157 , V_135 & V_158 ) )
return V_153 | V_168 ;
}
if ( V_154 && ( V_93 -> V_10 . V_160 . V_161 & V_169 ) ) {
unsigned int V_170 = F_59 ( V_156 , V_93 -> V_10 . V_171 ) ;
if ( V_153 & V_167 )
V_170 >>= 1 ;
if ( V_170 & 1 )
return V_153 | V_172 ;
}
V_93 -> V_10 . V_173 = V_2 ;
V_93 -> V_10 . V_174 = V_155 ;
V_93 -> V_10 . V_175 [ 0 ] = V_108 ;
V_93 -> V_10 . V_175 [ 1 ] = V_109 ;
if ( V_154 && ( V_93 -> V_10 . V_160 . V_161 & V_176 ) &&
( V_109 & ( V_77 | V_78 ) ) ==
( V_77 | V_78 ) )
return - 2 ;
return - 1 ;
}
