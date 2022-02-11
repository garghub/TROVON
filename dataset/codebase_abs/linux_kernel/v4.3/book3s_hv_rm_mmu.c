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
else
V_9 = 1 ;
if ( ! V_9 ) {
F_7 () ;
F_8 ( & V_7 -> V_10 . V_15 ) ;
F_9 ( V_12 -> V_13 . V_16 -> V_17 ,
& V_7 -> V_10 . V_15 ) ;
}
return V_9 ;
}
void F_10 ( struct V_7 * V_7 , struct V_18 * V_19 ,
unsigned long * V_20 , long V_21 , int V_22 )
{
struct V_18 * V_23 , * V_24 ;
unsigned long V_25 ;
if ( * V_20 & V_26 ) {
V_25 = * V_20 & V_27 ;
V_23 = & V_7 -> V_10 . V_28 [ V_25 ] ;
if ( V_22 )
V_23 = F_1 ( V_23 ) ;
V_24 = & V_7 -> V_10 . V_28 [ V_23 -> V_29 ] ;
if ( V_22 )
V_24 = F_1 ( V_24 ) ;
V_19 -> V_30 = V_25 ;
V_19 -> V_29 = V_23 -> V_29 ;
V_24 -> V_30 = V_21 ;
V_23 -> V_29 = V_21 ;
} else {
V_19 -> V_30 = V_19 -> V_29 = V_21 ;
* V_20 = ( * V_20 & ~ V_27 ) |
V_21 | V_26 ;
}
F_11 ( V_20 ) ;
}
void F_12 ( unsigned long * V_20 , unsigned long V_31 )
{
unsigned long V_32 ;
if ( ! V_31 )
return;
V_32 = F_13 ( V_31 ) ;
V_32 <<= V_33 ;
if ( V_32 > ( * V_20 & V_34 ) )
* V_20 = ( * V_20 & ~ V_34 ) | V_32 ;
}
static unsigned long * F_14 ( struct V_7 * V_7 , unsigned long V_35 ,
unsigned long V_36 )
{
struct V_37 * V_38 ;
unsigned long * V_20 ;
unsigned long V_39 ;
V_39 = F_15 ( V_36 , F_16 ( V_35 , V_36 ) ) ;
V_38 = F_17 ( F_18 ( V_7 ) , V_39 ) ;
if ( ! V_38 )
return NULL ;
V_20 = F_1 ( & V_38 -> V_10 . V_20 [ V_39 - V_38 -> V_40 ] ) ;
return V_20 ;
}
static void F_19 ( struct V_7 * V_7 , long V_21 ,
struct V_18 * V_19 ,
unsigned long V_35 , unsigned long V_41 )
{
struct V_18 * V_42 , * V_43 ;
unsigned long V_44 , V_23 ;
unsigned long * V_20 ;
unsigned long V_45 ;
V_45 = V_41 & ( V_46 | V_47 ) ;
V_44 = V_19 -> V_48 |= V_45 ;
V_20 = F_14 ( V_7 , V_35 , V_44 ) ;
if ( ! V_20 )
return;
F_20 ( V_20 ) ;
V_23 = * V_20 & V_27 ;
V_42 = F_1 ( & V_7 -> V_10 . V_28 [ V_19 -> V_30 ] ) ;
V_43 = F_1 ( & V_7 -> V_10 . V_28 [ V_19 -> V_29 ] ) ;
V_42 -> V_29 = V_19 -> V_29 ;
V_43 -> V_30 = V_19 -> V_30 ;
if ( V_23 == V_21 ) {
V_23 = V_19 -> V_30 ;
if ( V_23 == V_21 )
* V_20 &= ~ ( V_26 | V_27 ) ;
else
* V_20 = ( * V_20 & ~ V_27 ) | V_23 ;
}
* V_20 |= V_45 << V_49 ;
if ( V_45 & V_47 )
F_12 ( V_20 , F_16 ( V_35 , V_41 ) ) ;
F_11 ( V_20 ) ;
}
long F_21 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_21 , unsigned long V_50 , unsigned long V_44 ,
T_2 * V_51 , bool V_22 , unsigned long * V_52 )
{
unsigned long V_25 , V_53 , V_54 , V_39 , V_31 ;
unsigned long V_55 , V_56 ;
T_3 * V_57 ;
struct V_18 * V_19 ;
unsigned long V_58 ;
struct V_37 * V_38 ;
unsigned V_59 ;
unsigned long V_60 ;
unsigned long * V_20 ;
T_1 * V_61 ;
unsigned int V_62 ;
unsigned long V_63 ;
unsigned long V_45 , V_64 = 0 ;
V_31 = F_16 ( V_50 , V_44 ) ;
if ( ! V_31 )
return V_65 ;
V_62 = F_22 ( V_44 ) ;
V_50 &= ~ ( V_66 | V_67 | V_68 ) ;
V_44 &= ~ V_69 ;
V_58 = V_44 ;
V_63 = V_7 -> V_70 ;
F_23 () ;
V_54 = ( V_44 & V_71 ) & ~ ( V_31 - 1 ) ;
V_39 = V_54 >> V_5 ;
V_38 = F_17 ( F_18 ( V_7 ) , V_39 ) ;
V_53 = 0 ;
V_60 = ~ 0ul ;
V_20 = NULL ;
if ( ! ( V_38 && ! ( V_38 -> V_8 & V_72 ) ) ) {
V_50 |= V_67 ;
V_44 |= V_73 | V_74 ;
goto V_75;
}
if ( ! F_24 ( V_38 , V_31 ) )
return V_65 ;
V_55 = V_39 - V_38 -> V_40 ;
V_20 = & V_38 -> V_10 . V_20 [ V_55 ] ;
V_56 = F_25 ( V_38 , V_39 ) ;
if ( V_22 )
V_61 = F_2 ( V_51 , V_56 , & V_59 ) ;
else {
F_26 ( V_64 ) ;
V_61 = F_27 ( V_51 , V_56 , & V_59 ) ;
}
if ( V_61 ) {
T_1 V_76 ;
unsigned int V_77 ;
if ( V_59 )
V_77 = 1ul << V_59 ;
else
V_77 = V_78 ;
if ( V_77 < V_31 ) {
if ( ! V_22 )
F_28 ( V_8 ) ;
return V_65 ;
}
V_76 = F_29 ( V_61 , V_62 ) ;
if ( F_3 ( V_76 ) && ! F_30 ( V_76 ) ) {
if ( V_62 && ! F_31 ( V_76 ) )
V_44 = F_32 ( V_44 ) ;
V_60 = F_33 ( F_34 ( V_76 ) ) ;
V_53 = F_4 ( V_76 ) << V_5 ;
V_53 |= V_56 & ( V_77 - 1 ) ;
V_53 |= V_54 & ~ V_6 ;
}
}
if ( ! V_22 )
F_28 ( V_64 ) ;
V_44 &= ~ ( V_79 - V_31 ) ;
V_44 |= V_53 ;
if ( V_53 )
V_50 |= V_68 ;
else
V_50 |= V_67 ;
if ( V_60 != ~ 0ul && ! F_35 ( V_44 , V_60 ) ) {
if ( V_60 )
return V_65 ;
V_44 &= ~ ( V_80 | V_81 | V_82 ) ;
V_44 |= V_83 ;
}
V_75:
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
if ( F_36 ( ( V_8 & V_85 ) == 0 ) ) {
V_21 &= ~ 7UL ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
if ( ( F_37 ( * V_57 ) & V_68 ) == 0 &&
F_38 ( V_57 , V_66 | V_68 |
V_67 ) )
break;
V_57 += 2 ;
}
if ( V_25 == 8 ) {
V_57 -= 16 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
T_4 V_76 ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_76 = F_37 ( V_57 [ 0 ] ) ;
if ( ! ( V_76 & ( V_68 | V_67 ) ) )
break;
F_40 ( V_57 , V_76 ) ;
V_57 += 2 ;
}
if ( V_25 == 8 )
return V_87 ;
}
V_21 += V_25 ;
} else {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
if ( ! F_38 ( V_57 , V_66 | V_68 |
V_67 ) ) {
T_4 V_76 ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_76 = F_37 ( V_57 [ 0 ] ) ;
if ( V_76 & ( V_68 | V_67 ) ) {
F_40 ( V_57 , V_76 ) ;
return V_87 ;
}
}
}
V_19 = & V_7 -> V_10 . V_28 [ V_21 ] ;
if ( V_22 )
V_19 = F_1 ( V_19 ) ;
if ( V_19 ) {
V_19 -> V_48 = V_58 ;
F_41 ( V_7 , V_19 ) ;
}
if ( V_50 & V_68 ) {
if ( V_22 )
V_20 = F_1 ( V_20 ) ;
F_20 ( V_20 ) ;
if ( F_42 ( V_7 , V_63 ) ) {
V_50 |= V_67 ;
V_50 &= ~ V_68 ;
F_11 ( V_20 ) ;
} else {
F_10 ( V_7 , V_19 , V_20 , V_21 ,
V_22 ) ;
V_45 = * V_20 >> V_49 ;
V_44 &= V_45 | ~ ( V_46 | V_47 ) ;
}
}
V_57 [ 1 ] = F_43 ( V_44 ) ;
F_44 () ;
F_40 ( V_57 , V_50 ) ;
asm volatile("ptesync" : : : "memory");
* V_52 = V_21 ;
return V_88 ;
}
long F_45 ( struct V_14 * V_89 , unsigned long V_8 ,
long V_21 , unsigned long V_50 , unsigned long V_44 )
{
return F_21 ( V_89 -> V_7 , V_8 , V_21 , V_50 , V_44 ,
V_89 -> V_10 . V_51 , true , & V_89 -> V_10 . V_90 [ 4 ] ) ;
}
static inline int F_46 ( unsigned int * V_91 )
{
unsigned int V_92 , V_93 ;
unsigned int V_94 = V_95 ;
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
return V_93 == 0 ;
}
static void F_47 ( struct V_7 * V_7 , unsigned long * V_96 ,
long V_97 , int V_9 , bool V_98 )
{
long V_25 ;
if ( V_9 ) {
while ( ! F_46 ( & V_7 -> V_10 . V_99 ) )
F_39 () ;
if ( V_98 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_97 ; ++ V_25 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_99 = 0 ;
} else {
if ( V_98 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_97 ; ++ V_25 )
asm volatile("tlbiel %0" : : "r" (rbvalues[i]));
asm volatile("ptesync" : : : "memory");
}
}
long F_48 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_100 ,
unsigned long * V_101 )
{
T_3 * V_57 ;
unsigned long V_102 , V_103 , V_104 ;
struct V_18 * V_19 ;
T_4 V_76 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_76 = F_37 ( V_57 [ 0 ] ) ;
if ( ( V_76 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_105 ) && ( V_76 & ~ 0x7fUL ) != V_100 ) ||
( ( V_8 & V_106 ) && ( V_76 & V_100 ) != 0 ) ) {
F_40 ( V_57 , V_76 ) ;
return V_107 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_102 = V_76 & ~ V_66 ;
if ( V_102 & V_68 ) {
V_57 [ 0 ] &= ~ F_43 ( V_68 ) ;
V_104 = F_49 ( V_102 , F_37 ( V_57 [ 1 ] ) , V_21 ) ;
F_47 ( V_7 , & V_104 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_19 ( V_7 , V_21 , V_19 , V_102 ,
F_37 ( V_57 [ 1 ] ) ) ;
}
V_103 = V_19 -> V_48 & ~ V_69 ;
F_41 ( V_7 , V_19 ) ;
F_50 ( V_57 , 0 ) ;
V_101 [ 0 ] = V_102 ;
V_101 [ 1 ] = V_103 ;
return V_88 ;
}
long F_51 ( struct V_14 * V_89 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_100 )
{
return F_48 ( V_89 -> V_7 , V_8 , V_21 , V_100 ,
& V_89 -> V_10 . V_90 [ 4 ] ) ;
}
long F_52 ( struct V_14 * V_89 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
unsigned long * args = & V_89 -> V_10 . V_90 [ 4 ] ;
T_3 * V_108 , * V_109 [ 4 ] ;
unsigned long V_110 [ 4 ] ;
long int V_25 , V_111 , V_112 , V_113 , V_114 , V_115 [ 4 ] ;
unsigned long V_8 , V_116 , V_21 , V_45 ;
int V_9 ;
long int V_117 = V_88 ;
struct V_18 * V_19 , * V_118 [ 4 ] ;
T_4 V_119 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_25 = 0 ; V_25 < 4 && V_117 == V_88 ; ) {
V_113 = 0 ;
for (; V_25 < 4 ; ++ V_25 ) {
V_111 = V_25 * 2 ;
V_21 = args [ V_111 ] ;
V_8 = V_21 >> 56 ;
V_21 &= ( ( 1ul << 56 ) - 1 ) ;
V_116 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_116 == 3 ) {
V_25 = 4 ;
break;
}
if ( V_116 != 1 || V_8 == 3 ||
V_21 >= V_7 -> V_10 . V_84 ) {
args [ V_111 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_21 ;
V_117 = V_65 ;
break;
}
V_108 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
if ( ! F_38 ( V_108 , V_66 ) ) {
if ( V_113 )
break;
while ( ! F_38 ( V_108 , V_66 ) )
F_39 () ;
}
V_114 = 0 ;
V_119 = F_37 ( V_108 [ 0 ] ) ;
if ( V_119 & ( V_67 | V_68 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_114 = 1 ;
break;
case 1 :
if ( ! ( V_119 & args [ V_111 + 1 ] ) )
V_114 = 1 ;
break;
case 2 :
if ( ( V_119 & ~ 0x7fUL ) == args [ V_111 + 1 ] )
V_114 = 1 ;
break;
}
}
if ( ! V_114 ) {
V_108 [ 0 ] &= ~ F_43 ( V_66 ) ;
args [ V_111 ] = ( ( 0x90 | V_8 ) << 56 ) + V_21 ;
continue;
}
args [ V_111 ] = ( ( 0x80 | V_8 ) << 56 ) + V_21 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
F_41 ( V_7 , V_19 ) ;
if ( ! ( V_119 & V_68 ) ) {
V_45 = V_19 -> V_48 & ( V_46 | V_47 ) ;
args [ V_111 ] |= V_45 << ( 56 - 5 ) ;
V_108 [ 0 ] = 0 ;
continue;
}
V_108 [ 0 ] &= ~ F_43 ( V_68 ) ;
V_110 [ V_113 ] = F_49 ( F_37 ( V_108 [ 0 ] ) ,
F_37 ( V_108 [ 1 ] ) , V_21 ) ;
V_115 [ V_113 ] = V_111 ;
V_109 [ V_113 ] = V_108 ;
V_118 [ V_113 ] = V_19 ;
++ V_113 ;
}
if ( ! V_113 )
break;
F_47 ( V_7 , V_110 , V_113 , V_9 , true ) ;
for ( V_112 = 0 ; V_112 < V_113 ; ++ V_112 ) {
V_111 = V_115 [ V_112 ] ;
V_21 = args [ V_111 ] & ( ( 1ul << 56 ) - 1 ) ;
V_108 = V_109 [ V_112 ] ;
V_19 = V_118 [ V_112 ] ;
F_19 ( V_7 , V_21 , V_19 ,
F_37 ( V_108 [ 0 ] ) , F_37 ( V_108 [ 1 ] ) ) ;
V_45 = V_19 -> V_48 & ( V_46 | V_47 ) ;
args [ V_111 ] |= V_45 << ( 56 - 5 ) ;
F_40 ( V_108 , 0 ) ;
}
}
return V_117 ;
}
long F_53 ( struct V_14 * V_89 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_100 ,
unsigned long V_120 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
T_3 * V_57 ;
struct V_18 * V_19 ;
unsigned long V_102 , V_103 , V_104 , V_121 , V_122 ;
T_4 V_76 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_76 = F_37 ( V_57 [ 0 ] ) ;
if ( ( V_76 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_105 ) && ( V_76 & ~ 0x7fUL ) != V_100 ) ) {
F_40 ( V_57 , V_76 ) ;
return V_107 ;
}
V_102 = V_76 ;
V_122 = ( V_8 << 55 ) & V_79 ;
V_122 |= ( V_8 << 48 ) & V_73 ;
V_122 |= V_8 & ( V_123 | V_124 | V_74 ) ;
V_121 = V_79 | V_123 | V_124 |
V_73 | V_74 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
if ( V_19 ) {
V_103 = ( V_19 -> V_48 & ~ V_121 ) | V_122 ;
V_19 -> V_48 = V_103 ;
F_41 ( V_7 , V_19 ) ;
}
if ( V_102 & V_68 ) {
V_76 = F_37 ( V_57 [ 1 ] ) ;
V_103 = ( V_76 & ~ V_121 ) | V_122 ;
if ( F_22 ( V_103 ) && ! F_22 ( V_76 ) )
V_103 = F_32 ( V_103 ) ;
if ( V_103 != V_76 ) {
V_104 = F_49 ( V_102 , V_103 , V_21 ) ;
V_57 [ 0 ] = F_43 ( ( V_102 & ~ V_68 ) |
V_67 ) ;
F_47 ( V_7 , & V_104 , 1 , F_6 ( V_7 , V_8 ) ,
true ) ;
V_57 [ 1 ] = F_43 ( V_103 ) ;
}
}
F_50 ( V_57 , V_102 & ~ V_66 ) ;
asm volatile("ptesync" : : : "memory");
return V_88 ;
}
long F_54 ( struct V_14 * V_89 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
T_3 * V_57 ;
unsigned long V_102 , V_103 ;
int V_25 , V_113 = 1 ;
struct V_18 * V_19 = NULL ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
if ( V_8 & V_125 ) {
V_21 &= ~ 3 ;
V_113 = 4 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
for ( V_25 = 0 ; V_25 < V_113 ; ++ V_25 , ++ V_21 ) {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
V_102 = F_37 ( V_57 [ 0 ] ) & ~ V_66 ;
V_103 = F_37 ( V_57 [ 1 ] ) ;
if ( V_102 & V_67 ) {
V_102 &= ~ V_67 ;
V_102 |= V_68 ;
}
if ( V_102 & V_68 ) {
V_103 = V_19 [ V_25 ] . V_48 | ( V_103 & ( V_46 | V_47 ) ) ;
V_103 &= ~ V_69 ;
}
V_89 -> V_10 . V_90 [ 4 + V_25 * 2 ] = V_102 ;
V_89 -> V_10 . V_90 [ 5 + V_25 * 2 ] = V_103 ;
}
return V_88 ;
}
long F_55 ( struct V_14 * V_89 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
T_3 * V_57 ;
unsigned long V_102 , V_103 , V_126 ;
struct V_18 * V_19 ;
unsigned long * V_20 ;
long V_117 = V_107 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_102 = F_37 ( V_57 [ 0 ] ) ;
V_103 = F_37 ( V_57 [ 1 ] ) ;
if ( ! ( V_102 & ( V_68 | V_67 ) ) )
goto V_127;
V_126 = V_19 -> V_48 ;
if ( V_19 -> V_48 & V_46 ) {
V_19 -> V_48 &= ~ V_46 ;
F_41 ( V_7 , V_19 ) ;
}
if ( V_102 & V_68 ) {
V_126 |= V_103 & ( V_46 | V_47 ) ;
if ( V_103 & V_46 ) {
F_56 ( V_7 , V_57 , V_21 ) ;
V_20 = F_14 ( V_7 , V_102 , V_126 ) ;
if ( V_20 ) {
F_20 ( V_20 ) ;
* V_20 |= V_128 ;
F_11 ( V_20 ) ;
}
}
}
V_89 -> V_10 . V_90 [ 4 ] = V_126 ;
V_117 = V_88 ;
V_127:
F_50 ( V_57 , V_102 & ~ V_66 ) ;
return V_117 ;
}
long F_57 ( struct V_14 * V_89 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
T_3 * V_57 ;
unsigned long V_102 , V_103 , V_126 ;
struct V_18 * V_19 ;
unsigned long * V_20 ;
long V_117 = V_107 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_38 ( V_57 , V_66 ) )
F_39 () ;
V_102 = F_37 ( V_57 [ 0 ] ) ;
V_103 = F_37 ( V_57 [ 1 ] ) ;
if ( ! ( V_102 & ( V_68 | V_67 ) ) )
goto V_127;
V_126 = V_19 -> V_48 ;
if ( V_126 & V_47 ) {
V_19 -> V_48 &= ~ V_47 ;
F_41 ( V_7 , V_19 ) ;
}
if ( V_102 & V_68 ) {
V_57 [ 0 ] |= F_43 ( V_67 ) ;
F_58 ( V_7 , V_57 , V_21 ) ;
V_103 = F_37 ( V_57 [ 1 ] ) ;
V_126 |= V_103 & ( V_46 | V_47 ) ;
if ( V_103 & V_47 ) {
unsigned long V_31 = F_16 ( V_102 , V_103 ) ;
V_57 [ 1 ] = F_43 ( V_103 & ~ V_47 ) ;
F_44 () ;
V_20 = F_14 ( V_7 , V_102 , V_126 ) ;
if ( V_20 ) {
F_20 ( V_20 ) ;
* V_20 |= V_129 ;
F_12 ( V_20 , V_31 ) ;
F_11 ( V_20 ) ;
}
}
}
V_89 -> V_10 . V_90 [ 4 ] = V_126 ;
V_117 = V_88 ;
V_127:
F_50 ( V_57 , V_102 & ~ V_66 ) ;
return V_117 ;
}
void F_58 ( struct V_7 * V_7 , T_3 * V_130 ,
unsigned long V_21 )
{
unsigned long V_104 ;
V_130 [ 0 ] &= ~ F_43 ( V_68 ) ;
V_104 = F_49 ( F_37 ( V_130 [ 0 ] ) , F_37 ( V_130 [ 1 ] ) ,
V_21 ) ;
F_47 ( V_7 , & V_104 , 1 , 1 , true ) ;
}
void F_56 ( struct V_7 * V_7 , T_3 * V_130 ,
unsigned long V_21 )
{
unsigned long V_104 ;
unsigned char V_131 ;
V_104 = F_49 ( F_37 ( V_130 [ 0 ] ) , F_37 ( V_130 [ 1 ] ) ,
V_21 ) ;
V_131 = ( F_37 ( V_130 [ 1 ] ) & ~ V_46 ) >> 8 ;
* ( ( char * ) V_130 + 14 ) = V_131 ;
F_47 ( V_7 , & V_104 , 1 , 1 , false ) ;
}
long F_59 ( struct V_7 * V_7 , T_5 V_132 , unsigned long V_133 ,
unsigned long V_134 )
{
unsigned int V_25 ;
unsigned int V_135 ;
unsigned long V_136 ;
unsigned long V_137 , V_138 ;
unsigned long V_100 ;
T_3 * V_57 ;
unsigned long V_121 , V_139 ;
unsigned long V_102 , V_103 ;
V_121 = V_140 | V_141 | V_142 ;
V_139 = 0 ;
V_135 = 12 ;
if ( V_133 & V_143 ) {
V_121 |= V_144 ;
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
V_100 = V_133 & ~ ( V_136 >> 16 ) ;
V_100 |= ( V_132 & V_136 ) >> 16 ;
if ( V_135 >= 24 )
V_100 &= ~ ( ( 1UL << ( V_135 - 16 ) ) - 1 ) ;
else
V_100 &= ~ 0x7fUL ;
V_139 |= V_100 ;
for (; ; ) {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_138 << 7 ) ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 += 2 ) {
V_102 = F_37 ( V_57 [ V_25 ] ) & ~ V_66 ;
if ( ! ( V_102 & V_134 ) || ( V_102 & V_121 ) != V_139 )
continue;
while ( ! F_38 ( & V_57 [ V_25 ] , V_66 ) )
F_39 () ;
V_102 = F_37 ( V_57 [ V_25 ] ) & ~ V_66 ;
V_103 = F_37 ( V_57 [ V_25 + 1 ] ) ;
if ( ( V_102 & V_134 ) && ( V_102 & V_121 ) == V_139 &&
F_60 ( V_102 , V_103 ) == ( 1ul << V_135 ) )
return ( V_138 << 3 ) + ( V_25 >> 1 ) ;
F_40 ( & V_57 [ V_25 ] , V_102 ) ;
}
if ( V_139 & V_142 )
break;
V_139 |= V_142 ;
V_138 = V_138 ^ V_7 -> V_10 . V_150 ;
}
return - 1 ;
}
long F_61 ( struct V_14 * V_89 , unsigned long V_2 ,
unsigned long V_133 , unsigned int V_151 , bool V_152 )
{
struct V_7 * V_7 = V_89 -> V_7 ;
long int V_153 ;
unsigned long V_102 , V_103 , V_126 ;
T_3 * V_57 ;
unsigned long V_134 ;
struct V_18 * V_19 ;
unsigned long V_154 , V_155 ;
V_134 = V_68 ;
if ( V_151 & V_156 )
V_134 |= V_67 ;
V_153 = F_59 ( V_7 , V_2 , V_133 , V_134 ) ;
if ( V_153 < 0 ) {
if ( V_151 & V_156 )
return V_151 ;
return 0 ;
}
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_153 << 4 ) ) ;
V_102 = F_37 ( V_57 [ 0 ] ) & ~ V_66 ;
V_103 = F_37 ( V_57 [ 1 ] ) ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_153 ] ) ;
V_126 = V_19 -> V_48 ;
F_50 ( V_57 , V_102 ) ;
if ( ( V_151 & V_156 ) && ( V_102 & V_68 ) )
return 0 ;
V_154 = V_126 & ( V_79 | V_123 ) ;
V_155 = ( V_89 -> V_10 . V_157 . V_158 & V_159 ) ? V_160 : V_161 ;
V_151 &= ~ V_156 ;
if ( ! V_152 ) {
if ( V_126 & ( V_124 | V_82 ) )
return V_151 | V_162 ;
if ( ! F_62 ( V_154 , V_133 & V_155 ) )
return V_151 | V_163 ;
} else if ( V_151 & V_164 ) {
if ( ! F_63 ( V_154 , V_133 & V_155 ) )
return V_151 | V_165 ;
} else {
if ( ! F_62 ( V_154 , V_133 & V_155 ) )
return V_151 | V_165 ;
}
if ( V_152 && ( V_89 -> V_10 . V_157 . V_158 & V_166 ) ) {
unsigned int V_167 = F_64 ( V_126 , V_89 -> V_10 . V_168 ) ;
if ( V_151 & V_164 )
V_167 >>= 1 ;
if ( V_167 & 1 )
return V_151 | V_169 ;
}
V_89 -> V_10 . V_170 = V_2 ;
V_89 -> V_10 . V_171 = V_153 ;
V_89 -> V_10 . V_172 [ 0 ] = V_102 ;
V_89 -> V_10 . V_172 [ 1 ] = V_103 ;
if ( V_152 && ( V_89 -> V_10 . V_157 . V_158 & V_173 ) &&
( V_103 & ( V_73 | V_74 ) ) ==
( V_73 | V_74 ) )
return - 2 ;
return - 1 ;
}
