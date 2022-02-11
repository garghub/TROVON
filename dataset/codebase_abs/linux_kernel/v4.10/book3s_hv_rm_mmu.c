static void * F_1 ( void * V_1 )
{
unsigned long V_2 = ( unsigned long ) V_1 ;
T_1 * V_3 ;
V_3 = F_2 ( V_4 , V_2 , NULL , NULL ) ;
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
bool V_60 ;
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
V_60 = false ;
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
V_61 = F_2 ( V_51 , V_56 , NULL ,
& V_59 ) ;
else {
F_26 ( V_64 ) ;
V_61 = F_27 ( V_51 , V_56 , NULL ,
& V_59 ) ;
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
V_60 = F_33 ( V_76 ) ;
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
else {
V_50 |= V_67 ;
V_44 &= ~ ( V_73 | V_74 ) ;
}
if ( V_61 && ! F_34 ( V_44 , V_60 ) ) {
if ( V_60 )
return V_65 ;
V_44 &= ~ ( V_80 | V_81 | V_82 ) ;
V_44 |= V_83 ;
}
V_75:
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
if ( F_35 ( ( V_8 & V_85 ) == 0 ) ) {
V_21 &= ~ 7UL ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
if ( ( F_36 ( * V_57 ) & V_68 ) == 0 &&
F_37 ( V_57 , V_66 | V_68 |
V_67 ) )
break;
V_57 += 2 ;
}
if ( V_25 == 8 ) {
V_57 -= 16 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
T_4 V_76 ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_76 = F_36 ( V_57 [ 0 ] ) ;
if ( ! ( V_76 & ( V_68 | V_67 ) ) )
break;
F_39 ( V_57 , V_76 ) ;
V_57 += 2 ;
}
if ( V_25 == 8 )
return V_87 ;
}
V_21 += V_25 ;
} else {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
if ( ! F_37 ( V_57 , V_66 | V_68 |
V_67 ) ) {
T_4 V_76 ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_76 = F_36 ( V_57 [ 0 ] ) ;
if ( V_76 & ( V_68 | V_67 ) ) {
F_39 ( V_57 , V_76 ) ;
return V_87 ;
}
}
}
V_19 = & V_7 -> V_10 . V_28 [ V_21 ] ;
if ( V_22 )
V_19 = F_1 ( V_19 ) ;
if ( V_19 ) {
V_19 -> V_48 = V_58 ;
F_40 ( V_7 , V_19 ) ;
}
if ( V_50 & V_68 ) {
if ( V_22 )
V_20 = F_1 ( V_20 ) ;
F_20 ( V_20 ) ;
if ( F_41 ( V_7 , V_63 ) ) {
V_50 |= V_67 ;
V_50 &= ~ V_68 ;
V_44 &= ~ ( V_73 | V_74 ) ;
F_11 ( V_20 ) ;
} else {
F_10 ( V_7 , V_19 , V_20 , V_21 ,
V_22 ) ;
V_45 = * V_20 >> V_49 ;
V_44 &= V_45 | ~ ( V_46 | V_47 ) ;
}
}
if ( F_42 ( V_88 ) ) {
V_44 = F_43 ( V_50 , V_44 ) ;
V_50 = F_44 ( V_50 ) ;
}
V_57 [ 1 ] = F_45 ( V_44 ) ;
F_46 () ;
F_39 ( V_57 , V_50 ) ;
asm volatile("ptesync" : : : "memory");
* V_52 = V_21 ;
return V_89 ;
}
long F_47 ( struct V_14 * V_90 , unsigned long V_8 ,
long V_21 , unsigned long V_50 , unsigned long V_44 )
{
return F_21 ( V_90 -> V_7 , V_8 , V_21 , V_50 , V_44 ,
V_90 -> V_10 . V_51 , true , & V_90 -> V_10 . V_91 [ 4 ] ) ;
}
static inline int F_48 ( unsigned long V_92 , unsigned long V_93 )
{
return ( ( V_92 & V_67 ) &&
( V_93 & ( V_73 | V_74 ) ) ==
( V_73 | V_74 ) ) ;
}
static inline int F_49 ( unsigned int * V_94 )
{
unsigned int V_95 , V_96 ;
unsigned int V_97 = V_98 ;
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
return V_96 == 0 ;
}
static void F_50 ( struct V_7 * V_7 , unsigned long * V_99 ,
long V_100 , int V_9 , bool V_101 )
{
long V_25 ;
if ( V_9 ) {
while ( ! F_49 ( & V_7 -> V_10 . V_102 ) )
F_38 () ;
if ( V_101 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_100 ; ++ V_25 )
asm volatile(PPC_TLBIE_5(%0,%1,0,0,0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_102 = 0 ;
} else {
if ( V_101 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_100 ; ++ V_25 )
asm volatile(PPC_TLBIEL(%0,%1,0,0,0) : :
"r" (rbvalues[i]), "r" (0));
asm volatile("ptesync" : : : "memory");
}
}
long F_51 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_103 ,
unsigned long * V_104 )
{
T_3 * V_57 ;
unsigned long V_92 , V_93 , V_105 ;
struct V_18 * V_19 ;
T_4 V_76 , V_106 , V_107 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_76 = V_106 = F_36 ( V_57 [ 0 ] ) ;
V_107 = F_36 ( V_57 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_76 = F_52 ( V_76 , V_107 ) ;
V_107 = F_53 ( V_107 ) ;
}
if ( ( V_76 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_108 ) && ( V_76 & ~ 0x7fUL ) != V_103 ) ||
( ( V_8 & V_109 ) && ( V_76 & V_103 ) != 0 ) ) {
F_39 ( V_57 , V_106 ) ;
return V_110 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_92 = V_76 & ~ V_66 ;
if ( V_92 & V_68 ) {
V_57 [ 0 ] &= ~ F_45 ( V_68 ) ;
V_105 = F_54 ( V_92 , V_107 , V_21 ) ;
F_50 ( V_7 , & V_105 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_19 ( V_7 , V_21 , V_19 , V_92 ,
F_36 ( V_57 [ 1 ] ) ) ;
}
V_93 = V_19 -> V_48 & ~ V_69 ;
F_40 ( V_7 , V_19 ) ;
F_55 ( V_57 , 0 ) ;
if ( F_48 ( V_92 , V_107 ) )
F_56 ( & V_7 -> V_10 . V_111 ) ;
if ( V_92 & V_67 )
V_92 = ( V_92 & ~ V_67 ) | V_68 ;
V_104 [ 0 ] = V_92 ;
V_104 [ 1 ] = V_93 ;
return V_89 ;
}
long F_57 ( struct V_14 * V_90 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_103 )
{
return F_51 ( V_90 -> V_7 , V_8 , V_21 , V_103 ,
& V_90 -> V_10 . V_91 [ 4 ] ) ;
}
long F_58 ( struct V_14 * V_90 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
unsigned long * args = & V_90 -> V_10 . V_91 [ 4 ] ;
T_3 * V_112 , * V_113 [ 4 ] ;
unsigned long V_114 [ 4 ] ;
long int V_25 , V_115 , V_116 , V_117 , V_118 , V_119 [ 4 ] ;
unsigned long V_8 , V_120 , V_21 , V_45 ;
int V_9 ;
long int V_121 = V_89 ;
struct V_18 * V_19 , * V_122 [ 4 ] ;
T_4 V_123 , V_124 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_25 = 0 ; V_25 < 4 && V_121 == V_89 ; ) {
V_117 = 0 ;
for (; V_25 < 4 ; ++ V_25 ) {
V_115 = V_25 * 2 ;
V_21 = args [ V_115 ] ;
V_8 = V_21 >> 56 ;
V_21 &= ( ( 1ul << 56 ) - 1 ) ;
V_120 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_120 == 3 ) {
V_25 = 4 ;
break;
}
if ( V_120 != 1 || V_8 == 3 ||
V_21 >= V_7 -> V_10 . V_84 ) {
args [ V_115 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_21 ;
V_121 = V_65 ;
break;
}
V_112 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
if ( ! F_37 ( V_112 , V_66 ) ) {
if ( V_117 )
break;
while ( ! F_37 ( V_112 , V_66 ) )
F_38 () ;
}
V_118 = 0 ;
V_123 = F_36 ( V_112 [ 0 ] ) ;
V_124 = F_36 ( V_112 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_123 = F_52 ( V_123 , V_124 ) ;
V_124 = F_53 ( V_124 ) ;
}
if ( V_123 & ( V_67 | V_68 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_118 = 1 ;
break;
case 1 :
if ( ! ( V_123 & args [ V_115 + 1 ] ) )
V_118 = 1 ;
break;
case 2 :
if ( ( V_123 & ~ 0x7fUL ) == args [ V_115 + 1 ] )
V_118 = 1 ;
break;
}
}
if ( ! V_118 ) {
V_112 [ 0 ] &= ~ F_45 ( V_66 ) ;
args [ V_115 ] = ( ( 0x90 | V_8 ) << 56 ) + V_21 ;
continue;
}
args [ V_115 ] = ( ( 0x80 | V_8 ) << 56 ) + V_21 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
F_40 ( V_7 , V_19 ) ;
if ( ! ( V_123 & V_68 ) ) {
V_45 = V_19 -> V_48 & ( V_46 | V_47 ) ;
args [ V_115 ] |= V_45 << ( 56 - 5 ) ;
V_112 [ 0 ] = 0 ;
if ( F_48 ( V_123 , V_124 ) )
F_56 ( & V_7 -> V_10 . V_111 ) ;
continue;
}
V_112 [ 0 ] &= ~ F_45 ( V_68 ) ;
V_114 [ V_117 ] = F_54 ( V_123 , V_124 , V_21 ) ;
V_119 [ V_117 ] = V_115 ;
V_113 [ V_117 ] = V_112 ;
V_122 [ V_117 ] = V_19 ;
++ V_117 ;
}
if ( ! V_117 )
break;
F_50 ( V_7 , V_114 , V_117 , V_9 , true ) ;
for ( V_116 = 0 ; V_116 < V_117 ; ++ V_116 ) {
V_115 = V_119 [ V_116 ] ;
V_21 = args [ V_115 ] & ( ( 1ul << 56 ) - 1 ) ;
V_112 = V_113 [ V_116 ] ;
V_19 = V_122 [ V_116 ] ;
F_19 ( V_7 , V_21 , V_19 ,
F_36 ( V_112 [ 0 ] ) , F_36 ( V_112 [ 1 ] ) ) ;
V_45 = V_19 -> V_48 & ( V_46 | V_47 ) ;
args [ V_115 ] |= V_45 << ( 56 - 5 ) ;
F_39 ( V_112 , 0 ) ;
}
}
return V_121 ;
}
long F_59 ( struct V_14 * V_90 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_103 ,
unsigned long V_125 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
T_3 * V_57 ;
struct V_18 * V_19 ;
unsigned long V_92 , V_93 , V_105 , V_126 , V_127 ;
T_4 V_128 , V_107 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_92 = V_128 = F_36 ( V_57 [ 0 ] ) ;
if ( F_42 ( V_88 ) )
V_92 = F_52 ( V_92 , F_36 ( V_57 [ 1 ] ) ) ;
if ( ( V_92 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_108 ) && ( V_92 & ~ 0x7fUL ) != V_103 ) ) {
F_39 ( V_57 , V_128 ) ;
return V_110 ;
}
V_107 = F_36 ( V_57 [ 1 ] ) ;
V_127 = ( V_8 << 55 ) & V_79 ;
V_127 |= ( V_8 << 48 ) & V_73 ;
V_127 |= V_8 & ( V_129 | V_130 | V_74 ) ;
V_126 = V_79 | V_129 | V_130 |
V_73 | V_74 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
if ( V_19 ) {
V_93 = ( V_19 -> V_48 & ~ V_126 ) | V_127 ;
V_19 -> V_48 = V_93 ;
F_40 ( V_7 , V_19 ) ;
}
if ( V_92 & V_68 ) {
V_93 = ( V_107 & ~ V_126 ) | V_127 ;
if ( F_22 ( V_93 ) && ! F_22 ( V_107 ) )
V_93 = F_32 ( V_93 ) ;
if ( V_93 != V_107 ) {
V_105 = F_54 ( V_92 , V_93 , V_21 ) ;
V_57 [ 0 ] = F_45 ( ( V_128 & ~ V_68 ) |
V_67 ) ;
F_50 ( V_7 , & V_105 , 1 , F_6 ( V_7 , V_8 ) ,
true ) ;
V_93 |= F_36 ( V_57 [ 1 ] ) & ( V_46 | V_47 ) ;
V_57 [ 1 ] = F_45 ( V_93 ) ;
}
}
F_55 ( V_57 , V_128 & ~ V_66 ) ;
asm volatile("ptesync" : : : "memory");
if ( F_48 ( V_92 , V_107 ) )
F_56 ( & V_7 -> V_10 . V_111 ) ;
return V_89 ;
}
long F_60 ( struct V_14 * V_90 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
T_3 * V_57 ;
unsigned long V_92 , V_93 ;
int V_25 , V_117 = 1 ;
struct V_18 * V_19 = NULL ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
if ( V_8 & V_131 ) {
V_21 &= ~ 3 ;
V_117 = 4 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
for ( V_25 = 0 ; V_25 < V_117 ; ++ V_25 , ++ V_21 ) {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
V_92 = F_36 ( V_57 [ 0 ] ) & ~ V_66 ;
V_93 = F_36 ( V_57 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_92 = F_52 ( V_92 , V_93 ) ;
V_93 = F_53 ( V_93 ) ;
}
if ( V_92 & V_67 ) {
V_92 &= ~ V_67 ;
V_92 |= V_68 ;
}
if ( V_92 & V_68 ) {
V_93 = V_19 [ V_25 ] . V_48 | ( V_93 & ( V_46 | V_47 ) ) ;
V_93 &= ~ V_69 ;
}
V_90 -> V_10 . V_91 [ 4 + V_25 * 2 ] = V_92 ;
V_90 -> V_10 . V_91 [ 5 + V_25 * 2 ] = V_93 ;
}
return V_89 ;
}
long F_61 ( struct V_14 * V_90 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
T_3 * V_57 ;
unsigned long V_92 , V_93 , V_132 ;
struct V_18 * V_19 ;
unsigned long * V_20 ;
long V_121 = V_110 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_92 = F_36 ( V_57 [ 0 ] ) ;
V_93 = F_36 ( V_57 [ 1 ] ) ;
if ( ! ( V_92 & ( V_68 | V_67 ) ) )
goto V_133;
V_132 = V_19 -> V_48 ;
if ( V_19 -> V_48 & V_46 ) {
V_19 -> V_48 &= ~ V_46 ;
F_40 ( V_7 , V_19 ) ;
}
if ( V_92 & V_68 ) {
V_132 |= V_93 & ( V_46 | V_47 ) ;
if ( V_93 & V_46 ) {
F_62 ( V_7 , V_57 , V_21 ) ;
V_20 = F_14 ( V_7 , V_92 , V_132 ) ;
if ( V_20 ) {
F_20 ( V_20 ) ;
* V_20 |= V_134 ;
F_11 ( V_20 ) ;
}
}
}
V_90 -> V_10 . V_91 [ 4 ] = V_132 ;
V_121 = V_89 ;
V_133:
F_55 ( V_57 , V_92 & ~ V_66 ) ;
return V_121 ;
}
long F_63 ( struct V_14 * V_90 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
T_3 * V_57 ;
unsigned long V_92 , V_93 , V_132 ;
struct V_18 * V_19 ;
unsigned long * V_20 ;
long V_121 = V_110 ;
if ( V_21 >= V_7 -> V_10 . V_84 )
return V_65 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_21 << 4 ) ) ;
while ( ! F_37 ( V_57 , V_66 ) )
F_38 () ;
V_92 = F_36 ( V_57 [ 0 ] ) ;
V_93 = F_36 ( V_57 [ 1 ] ) ;
if ( ! ( V_92 & ( V_68 | V_67 ) ) )
goto V_133;
V_132 = V_19 -> V_48 ;
if ( V_132 & V_47 ) {
V_19 -> V_48 &= ~ V_47 ;
F_40 ( V_7 , V_19 ) ;
}
if ( V_92 & V_68 ) {
V_57 [ 0 ] |= F_45 ( V_67 ) ;
F_64 ( V_7 , V_57 , V_21 ) ;
V_93 = F_36 ( V_57 [ 1 ] ) ;
V_132 |= V_93 & ( V_46 | V_47 ) ;
if ( V_93 & V_47 ) {
unsigned long V_31 = F_16 ( V_92 , V_93 ) ;
V_57 [ 1 ] = F_45 ( V_93 & ~ V_47 ) ;
F_46 () ;
V_20 = F_14 ( V_7 , V_92 , V_132 ) ;
if ( V_20 ) {
F_20 ( V_20 ) ;
* V_20 |= V_135 ;
F_12 ( V_20 , V_31 ) ;
F_11 ( V_20 ) ;
}
}
}
V_90 -> V_10 . V_91 [ 4 ] = V_132 ;
V_121 = V_89 ;
V_133:
F_55 ( V_57 , V_92 & ~ V_66 ) ;
return V_121 ;
}
void F_64 ( struct V_7 * V_7 , T_3 * V_136 ,
unsigned long V_21 )
{
unsigned long V_105 ;
T_4 V_123 , V_124 ;
V_136 [ 0 ] &= ~ F_45 ( V_68 ) ;
V_123 = F_36 ( V_136 [ 0 ] ) ;
V_124 = F_36 ( V_136 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_123 = F_52 ( V_123 , V_124 ) ;
V_124 = F_53 ( V_124 ) ;
}
V_105 = F_54 ( V_123 , V_124 , V_21 ) ;
F_50 ( V_7 , & V_105 , 1 , 1 , true ) ;
}
void F_62 ( struct V_7 * V_7 , T_3 * V_136 ,
unsigned long V_21 )
{
unsigned long V_105 ;
unsigned char V_137 ;
T_4 V_123 , V_124 ;
V_123 = F_36 ( V_136 [ 0 ] ) ;
V_124 = F_36 ( V_136 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_123 = F_52 ( V_123 , V_124 ) ;
V_124 = F_53 ( V_124 ) ;
}
V_105 = F_54 ( V_123 , V_124 , V_21 ) ;
V_137 = ( F_36 ( V_136 [ 1 ] ) & ~ V_46 ) >> 8 ;
* ( ( char * ) V_136 + 14 ) = V_137 ;
F_50 ( V_7 , & V_105 , 1 , 1 , false ) ;
}
static struct V_138 * F_65 ( struct V_14 * V_90 ,
unsigned long V_139 , unsigned long V_140 , long V_111 )
{
struct V_138 * V_141 = NULL ;
unsigned int V_142 ;
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_143 ; V_25 ++ ) {
V_141 = & V_90 -> V_10 . V_144 . V_141 [ V_25 ] ;
if ( V_141 -> V_111 == V_111 ) {
V_142 = V_141 -> V_145 ;
if ( ( V_141 -> V_139 >> V_142 ) == ( V_139 >> V_142 ) &&
V_141 -> V_140 == V_140 )
return V_141 ;
}
}
return NULL ;
}
static struct V_138 *
F_66 ( struct V_14 * V_90 )
{
unsigned int V_146 = V_90 -> V_10 . V_144 . V_146 ;
V_90 -> V_10 . V_144 . V_146 ++ ;
if ( V_90 -> V_10 . V_144 . V_146 == V_143 )
V_90 -> V_10 . V_144 . V_146 = 0 ;
return & V_90 -> V_10 . V_144 . V_141 [ V_146 ] ;
}
long F_67 ( struct V_7 * V_7 , T_5 V_139 , unsigned long V_140 ,
unsigned long V_147 )
{
unsigned int V_25 ;
unsigned int V_142 ;
unsigned long V_148 ;
unsigned long V_149 , V_150 ;
unsigned long V_103 ;
T_3 * V_57 ;
unsigned long V_126 , V_151 ;
unsigned long V_92 , V_93 , V_152 ;
V_126 = V_153 | V_154 | V_155 ;
V_151 = 0 ;
V_142 = 12 ;
if ( V_140 & V_156 ) {
V_126 |= V_157 ;
V_151 |= V_157 ;
V_142 = V_158 [ ( V_140 & V_159 ) >> 4 ] ;
}
if ( V_140 & V_160 ) {
V_148 = ( 1UL << 40 ) - 1 ;
V_149 = ( V_140 & ~ V_153 ) >> V_161 ;
V_149 ^= V_149 << 25 ;
} else {
V_148 = ( 1UL << 28 ) - 1 ;
V_149 = ( V_140 & ~ V_153 ) >> V_162 ;
}
V_150 = ( V_149 ^ ( ( V_139 & V_148 ) >> V_142 ) ) & V_7 -> V_10 . V_163 ;
V_103 = V_140 & ~ ( V_148 >> 16 ) ;
V_103 |= ( V_139 & V_148 ) >> 16 ;
if ( V_142 >= 24 )
V_103 &= ~ ( ( 1UL << ( V_142 - 16 ) ) - 1 ) ;
else
V_103 &= ~ 0x7fUL ;
V_151 |= V_103 ;
for (; ; ) {
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_150 << 7 ) ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 += 2 ) {
V_92 = F_36 ( V_57 [ V_25 ] ) & ~ V_66 ;
if ( F_42 ( V_88 ) )
V_92 = F_52 ( V_92 , F_36 ( V_57 [ V_25 + 1 ] ) ) ;
if ( ! ( V_92 & V_147 ) || ( V_92 & V_126 ) != V_151 )
continue;
while ( ! F_37 ( & V_57 [ V_25 ] , V_66 ) )
F_38 () ;
V_92 = V_152 = F_36 ( V_57 [ V_25 ] ) & ~ V_66 ;
V_93 = F_36 ( V_57 [ V_25 + 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_92 = F_52 ( V_92 , V_93 ) ;
V_93 = F_53 ( V_93 ) ;
}
if ( ( V_92 & V_147 ) && ( V_92 & V_126 ) == V_151 &&
F_68 ( V_92 , V_93 ) == ( 1ul << V_142 ) )
return ( V_150 << 3 ) + ( V_25 >> 1 ) ;
F_39 ( & V_57 [ V_25 ] , V_152 ) ;
}
if ( V_151 & V_155 )
break;
V_151 |= V_155 ;
V_150 = V_150 ^ V_7 -> V_10 . V_163 ;
}
return - 1 ;
}
long F_69 ( struct V_14 * V_90 , unsigned long V_2 ,
unsigned long V_140 , unsigned int V_164 , bool V_165 )
{
struct V_7 * V_7 = V_90 -> V_7 ;
long int V_146 ;
unsigned long V_92 , V_93 , V_132 , V_152 ;
T_3 * V_57 ;
unsigned long V_147 ;
struct V_18 * V_19 ;
unsigned long V_166 , V_167 ;
struct V_138 * V_168 = NULL ;
long V_111 = 0 ;
V_147 = V_68 ;
if ( V_164 & V_169 ) {
V_147 |= V_67 ;
V_111 = F_70 ( & V_7 -> V_10 . V_111 ) ;
V_168 = F_65 ( V_90 , V_2 , V_140 , V_111 ) ;
}
if ( V_168 ) {
V_146 = V_168 -> V_21 ;
V_92 = V_168 -> V_35 ;
V_93 = V_168 -> V_41 ;
V_132 = V_168 -> V_170 ;
} else {
V_146 = F_67 ( V_7 , V_2 , V_140 , V_147 ) ;
if ( V_146 < 0 ) {
if ( V_164 & V_169 )
return V_164 ;
return 0 ;
}
V_57 = ( T_3 * ) ( V_7 -> V_10 . V_86 + ( V_146 << 4 ) ) ;
V_92 = V_152 = F_36 ( V_57 [ 0 ] ) & ~ V_66 ;
V_93 = F_36 ( V_57 [ 1 ] ) ;
if ( F_42 ( V_88 ) ) {
V_92 = F_52 ( V_92 , V_93 ) ;
V_93 = F_53 ( V_93 ) ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_146 ] ) ;
V_132 = V_19 -> V_48 ;
F_55 ( V_57 , V_152 ) ;
}
if ( ( V_164 & V_169 ) && ( V_92 & V_68 ) )
return 0 ;
V_166 = V_132 & ( V_79 | V_129 ) ;
V_167 = ( V_90 -> V_10 . V_171 . V_172 & V_173 ) ? V_174 : V_175 ;
V_164 &= ~ V_169 ;
if ( ! V_165 ) {
if ( V_132 & ( V_130 | V_82 ) )
return V_164 | V_176 ;
if ( ! F_71 ( V_166 , V_140 & V_167 ) )
return V_164 | V_177 ;
} else if ( V_164 & V_178 ) {
if ( ! F_72 ( V_166 , V_140 & V_167 ) )
return V_164 | V_179 ;
} else {
if ( ! F_71 ( V_166 , V_140 & V_167 ) )
return V_164 | V_179 ;
}
if ( V_165 && ( V_90 -> V_10 . V_171 . V_172 & V_180 ) ) {
unsigned int V_181 = F_73 ( V_132 , V_90 -> V_10 . V_182 ) ;
if ( V_164 & V_178 )
V_181 >>= 1 ;
if ( V_181 & 1 )
return V_164 | V_183 ;
}
V_90 -> V_10 . V_184 = V_2 ;
V_90 -> V_10 . V_185 = V_146 ;
V_90 -> V_10 . V_186 [ 0 ] = V_92 ;
V_90 -> V_10 . V_186 [ 1 ] = V_93 ;
V_90 -> V_10 . V_187 = V_168 ;
if ( ( V_93 & ( V_73 | V_74 ) ) ==
( V_73 | V_74 ) ) {
if ( ! V_168 ) {
unsigned int V_142 = 12 ;
unsigned int V_188 ;
if ( V_140 & V_156 ) {
V_188 = ( ( V_140 & V_159 ) >> 4 ) ;
V_142 = V_158 [ V_188 ] ;
}
V_168 = F_66 ( V_90 ) ;
V_168 -> V_139 = V_2 ;
V_168 -> V_145 = V_142 ;
V_168 -> V_21 = V_146 ;
V_168 -> V_35 = V_92 ;
V_168 -> V_41 = V_93 ;
V_168 -> V_170 = V_132 ;
V_168 -> V_140 = V_140 ;
V_168 -> V_111 = V_111 ;
}
if ( V_165 && ( V_90 -> V_10 . V_171 . V_172 & V_189 ) )
return - 2 ;
}
return - 1 ;
}
