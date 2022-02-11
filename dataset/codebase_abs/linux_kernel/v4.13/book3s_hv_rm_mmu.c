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
int V_10 ;
if ( V_7 -> V_11 . V_12 == 1 && V_13 -> V_14 . V_15 )
V_9 = 0 ;
else
V_9 = 1 ;
if ( ! V_9 ) {
F_7 () ;
F_8 ( & V_7 -> V_11 . V_16 ) ;
V_10 = V_13 -> V_14 . V_17 -> V_18 ;
if ( F_9 ( V_19 ) )
V_10 = F_10 ( V_10 ) ;
F_11 ( V_10 , & V_7 -> V_11 . V_16 ) ;
}
return V_9 ;
}
void F_12 ( struct V_7 * V_7 , struct V_20 * V_21 ,
unsigned long * V_22 , long V_23 , int V_24 )
{
struct V_20 * V_25 , * V_26 ;
unsigned long V_27 ;
if ( * V_22 & V_28 ) {
V_27 = * V_22 & V_29 ;
V_25 = & V_7 -> V_11 . V_30 . V_21 [ V_27 ] ;
if ( V_24 )
V_25 = F_1 ( V_25 ) ;
V_26 = & V_7 -> V_11 . V_30 . V_21 [ V_25 -> V_31 ] ;
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
F_13 ( V_22 ) ;
}
void F_14 ( unsigned long * V_22 , unsigned long V_33 )
{
unsigned long V_34 ;
if ( ! V_33 )
return;
V_34 = F_15 ( V_33 ) ;
V_34 <<= V_35 ;
if ( V_34 > ( * V_22 & V_36 ) )
* V_22 = ( * V_22 & ~ V_36 ) | V_34 ;
}
static unsigned long * F_16 ( struct V_7 * V_7 , unsigned long V_37 ,
unsigned long V_38 )
{
struct V_39 * V_40 ;
unsigned long * V_22 ;
unsigned long V_41 ;
V_41 = F_17 ( V_38 , F_18 ( V_37 , V_38 ) ) ;
V_40 = F_19 ( F_20 ( V_7 ) , V_41 ) ;
if ( ! V_40 )
return NULL ;
V_22 = F_1 ( & V_40 -> V_11 . V_22 [ V_41 - V_40 -> V_42 ] ) ;
return V_22 ;
}
static void F_21 ( struct V_7 * V_7 , long V_23 ,
struct V_20 * V_21 ,
unsigned long V_37 , unsigned long V_43 )
{
struct V_20 * V_44 , * V_45 ;
unsigned long V_46 , V_25 ;
unsigned long * V_22 ;
unsigned long V_47 ;
V_47 = V_43 & ( V_48 | V_49 ) ;
V_46 = V_21 -> V_50 |= V_47 ;
V_22 = F_16 ( V_7 , V_37 , V_46 ) ;
if ( ! V_22 )
return;
F_22 ( V_22 ) ;
V_25 = * V_22 & V_29 ;
V_44 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_21 -> V_32 ] ) ;
V_45 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_21 -> V_31 ] ) ;
V_44 -> V_31 = V_21 -> V_31 ;
V_45 -> V_32 = V_21 -> V_32 ;
if ( V_25 == V_23 ) {
V_25 = V_21 -> V_32 ;
if ( V_25 == V_23 )
* V_22 &= ~ ( V_28 | V_29 ) ;
else
* V_22 = ( * V_22 & ~ V_29 ) | V_25 ;
}
* V_22 |= V_47 << V_51 ;
if ( V_47 & V_49 )
F_14 ( V_22 , F_18 ( V_37 , V_43 ) ) ;
F_13 ( V_22 ) ;
}
long F_23 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_23 , unsigned long V_52 , unsigned long V_46 ,
T_2 * V_53 , bool V_24 , unsigned long * V_54 )
{
unsigned long V_27 , V_55 , V_56 , V_41 , V_33 ;
unsigned long V_57 , V_58 ;
T_3 * V_59 ;
struct V_20 * V_21 ;
unsigned long V_60 ;
struct V_39 * V_40 ;
unsigned V_61 ;
bool V_62 ;
unsigned long * V_22 ;
T_1 * V_63 ;
unsigned int V_64 ;
unsigned long V_65 ;
unsigned long V_47 , V_66 = 0 ;
if ( F_24 ( V_7 ) )
return V_67 ;
V_33 = F_18 ( V_52 , V_46 ) ;
if ( ! V_33 )
return V_68 ;
V_64 = F_25 ( V_46 ) ;
V_52 &= ~ ( V_69 | V_70 | V_71 ) ;
V_46 &= ~ V_72 ;
V_60 = V_46 ;
V_65 = V_7 -> V_73 ;
F_26 () ;
V_56 = ( V_46 & V_74 ) & ~ ( V_33 - 1 ) ;
V_41 = V_56 >> V_5 ;
V_40 = F_19 ( F_20 ( V_7 ) , V_41 ) ;
V_55 = 0 ;
V_62 = false ;
V_22 = NULL ;
if ( ! ( V_40 && ! ( V_40 -> V_8 & V_75 ) ) ) {
V_52 |= V_70 ;
V_46 |= V_76 | V_77 ;
goto V_78;
}
if ( ! F_27 ( V_40 , V_33 ) )
return V_68 ;
V_57 = V_41 - V_40 -> V_42 ;
V_22 = & V_40 -> V_11 . V_22 [ V_57 ] ;
V_58 = F_28 ( V_40 , V_41 ) ;
if ( V_24 )
V_63 = F_2 ( V_53 , V_58 , NULL ,
& V_61 ) ;
else {
F_29 ( V_66 ) ;
V_63 = F_30 ( V_53 , V_58 , NULL ,
& V_61 ) ;
}
if ( V_63 ) {
T_1 V_79 ;
unsigned int V_80 ;
if ( V_61 )
V_80 = 1ul << V_61 ;
else
V_80 = V_81 ;
if ( V_80 < V_33 ) {
if ( ! V_24 )
F_31 ( V_8 ) ;
return V_68 ;
}
V_79 = F_32 ( V_63 , V_64 ) ;
if ( F_3 ( V_79 ) && ! F_33 ( V_79 ) ) {
if ( V_64 && ! F_34 ( V_79 ) )
V_46 = F_35 ( V_46 ) ;
V_62 = F_36 ( V_79 ) ;
V_55 = F_4 ( V_79 ) << V_5 ;
V_55 |= V_58 & ( V_80 - 1 ) ;
V_55 |= V_56 & ~ V_6 ;
}
}
if ( ! V_24 )
F_31 ( V_66 ) ;
V_46 &= ~ ( V_82 - V_33 ) ;
V_46 |= V_55 ;
if ( V_55 )
V_52 |= V_71 ;
else {
V_52 |= V_70 ;
V_46 &= ~ ( V_76 | V_77 ) ;
}
if ( V_63 && ! F_37 ( V_46 , V_62 ) ) {
if ( V_62 )
return V_68 ;
V_46 &= ~ ( V_83 | V_84 | V_85 ) ;
V_46 |= V_86 ;
}
V_78:
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
if ( F_39 ( ( V_8 & V_87 ) == 0 ) ) {
V_23 &= ~ 7UL ;
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
if ( ( F_40 ( * V_59 ) & V_71 ) == 0 &&
F_41 ( V_59 , V_69 | V_71 |
V_70 ) )
break;
V_59 += 2 ;
}
if ( V_27 == 8 ) {
V_59 -= 16 ;
for ( V_27 = 0 ; V_27 < 8 ; ++ V_27 ) {
T_4 V_79 ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_79 = F_40 ( V_59 [ 0 ] ) ;
if ( ! ( V_79 & ( V_71 | V_70 ) ) )
break;
F_43 ( V_59 , V_79 ) ;
V_59 += 2 ;
}
if ( V_27 == 8 )
return V_89 ;
}
V_23 += V_27 ;
} else {
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
if ( ! F_41 ( V_59 , V_69 | V_71 |
V_70 ) ) {
T_4 V_79 ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_79 = F_40 ( V_59 [ 0 ] ) ;
if ( V_79 & ( V_71 | V_70 ) ) {
F_43 ( V_59 , V_79 ) ;
return V_89 ;
}
}
}
V_21 = & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ;
if ( V_24 )
V_21 = F_1 ( V_21 ) ;
if ( V_21 ) {
V_21 -> V_50 = V_60 ;
F_44 ( V_7 , V_21 ) ;
}
if ( V_52 & V_71 ) {
if ( V_24 )
V_22 = F_1 ( V_22 ) ;
F_22 ( V_22 ) ;
if ( F_45 ( V_7 , V_65 ) ) {
V_52 |= V_70 ;
V_52 &= ~ V_71 ;
V_46 &= ~ ( V_76 | V_77 ) ;
F_13 ( V_22 ) ;
} else {
F_12 ( V_7 , V_21 , V_22 , V_23 ,
V_24 ) ;
V_47 = * V_22 >> V_51 ;
V_46 &= V_47 | ~ ( V_48 | V_49 ) ;
}
}
if ( F_9 ( V_19 ) ) {
V_46 = F_46 ( V_52 , V_46 ) ;
V_52 = F_47 ( V_52 ) ;
}
V_59 [ 1 ] = F_48 ( V_46 ) ;
F_49 () ;
F_43 ( V_59 , V_52 ) ;
asm volatile("ptesync" : : : "memory");
* V_54 = V_23 ;
return V_90 ;
}
long F_50 ( struct V_15 * V_91 , unsigned long V_8 ,
long V_23 , unsigned long V_52 , unsigned long V_46 )
{
return F_23 ( V_91 -> V_7 , V_8 , V_23 , V_52 , V_46 ,
V_91 -> V_11 . V_53 , true , & V_91 -> V_11 . V_92 [ 4 ] ) ;
}
static inline int F_51 ( unsigned long V_93 , unsigned long V_94 )
{
return ( ( V_93 & V_70 ) &&
( V_94 & ( V_76 | V_77 ) ) ==
( V_76 | V_77 ) ) ;
}
static inline int F_52 ( unsigned int * V_95 )
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
static void F_53 ( struct V_7 * V_7 , unsigned long * V_100 ,
long V_101 , int V_9 , bool V_102 )
{
long V_27 ;
if ( V_9 ) {
while ( ! F_52 ( & V_7 -> V_11 . V_103 ) )
F_42 () ;
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 ) {
asm volatile(PPC_TLBIE_5(%0,%1,0,0,0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
F_54 ( V_7 -> V_11 . V_104 , 0 , V_100 [ V_27 ] ,
V_7 -> V_11 . V_104 , 0 , 0 , 0 ) ;
}
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_11 . V_103 = 0 ;
} else {
if ( V_102 )
asm volatile("ptesync" : : : "memory");
for ( V_27 = 0 ; V_27 < V_101 ; ++ V_27 ) {
asm volatile(PPC_TLBIEL(%0,%1,0,0,0) : :
"r" (rbvalues[i]), "r" (0));
F_54 ( V_7 -> V_11 . V_104 , 1 , V_100 [ V_27 ] ,
0 , 0 , 0 , 0 ) ;
}
asm volatile("ptesync" : : : "memory");
}
}
long F_55 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_105 ,
unsigned long * V_106 )
{
T_3 * V_59 ;
unsigned long V_93 , V_94 , V_107 ;
struct V_20 * V_21 ;
T_4 V_79 , V_108 , V_109 ;
if ( F_24 ( V_7 ) )
return V_67 ;
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_79 = V_108 = F_40 ( V_59 [ 0 ] ) ;
V_109 = F_40 ( V_59 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_79 = F_56 ( V_79 , V_109 ) ;
V_109 = F_57 ( V_109 ) ;
}
if ( ( V_79 & ( V_70 | V_71 ) ) == 0 ||
( ( V_8 & V_110 ) && ( V_79 & ~ 0x7fUL ) != V_105 ) ||
( ( V_8 & V_111 ) && ( V_79 & V_105 ) != 0 ) ) {
F_43 ( V_59 , V_108 ) ;
return V_112 ;
}
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
V_93 = V_79 & ~ V_69 ;
if ( V_93 & V_71 ) {
V_59 [ 0 ] &= ~ F_48 ( V_71 ) ;
V_107 = F_58 ( V_93 , V_109 , V_23 ) ;
F_53 ( V_7 , & V_107 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_21 ( V_7 , V_23 , V_21 , V_93 ,
F_40 ( V_59 [ 1 ] ) ) ;
}
V_94 = V_21 -> V_50 & ~ V_72 ;
F_44 ( V_7 , V_21 ) ;
F_59 ( V_59 , 0 ) ;
if ( F_51 ( V_93 , V_109 ) )
F_60 ( & V_7 -> V_11 . V_113 ) ;
if ( V_93 & V_70 )
V_93 = ( V_93 & ~ V_70 ) | V_71 ;
V_106 [ 0 ] = V_93 ;
V_106 [ 1 ] = V_94 ;
return V_90 ;
}
long F_61 ( struct V_15 * V_91 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_105 )
{
return F_55 ( V_91 -> V_7 , V_8 , V_23 , V_105 ,
& V_91 -> V_11 . V_92 [ 4 ] ) ;
}
long F_62 ( struct V_15 * V_91 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
unsigned long * args = & V_91 -> V_11 . V_92 [ 4 ] ;
T_3 * V_114 , * V_115 [ 4 ] ;
unsigned long V_116 [ 4 ] ;
long int V_27 , V_117 , V_118 , V_119 , V_120 , V_121 [ 4 ] ;
unsigned long V_8 , V_122 , V_23 , V_47 ;
int V_9 ;
long int V_123 = V_90 ;
struct V_20 * V_21 , * V_124 [ 4 ] ;
T_4 V_125 , V_126 ;
if ( F_24 ( V_7 ) )
return V_67 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_27 = 0 ; V_27 < 4 && V_123 == V_90 ; ) {
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
V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) ) {
args [ V_117 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_23 ;
V_123 = V_68 ;
break;
}
V_114 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
if ( ! F_41 ( V_114 , V_69 ) ) {
if ( V_119 )
break;
while ( ! F_41 ( V_114 , V_69 ) )
F_42 () ;
}
V_120 = 0 ;
V_125 = F_40 ( V_114 [ 0 ] ) ;
V_126 = F_40 ( V_114 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_125 = F_56 ( V_125 , V_126 ) ;
V_126 = F_57 ( V_126 ) ;
}
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
V_114 [ 0 ] &= ~ F_48 ( V_69 ) ;
args [ V_117 ] = ( ( 0x90 | V_8 ) << 56 ) + V_23 ;
continue;
}
args [ V_117 ] = ( ( 0x80 | V_8 ) << 56 ) + V_23 ;
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
F_44 ( V_7 , V_21 ) ;
if ( ! ( V_125 & V_71 ) ) {
V_47 = V_21 -> V_50 & ( V_48 | V_49 ) ;
args [ V_117 ] |= V_47 << ( 56 - 5 ) ;
V_114 [ 0 ] = 0 ;
if ( F_51 ( V_125 , V_126 ) )
F_60 ( & V_7 -> V_11 . V_113 ) ;
continue;
}
V_114 [ 0 ] &= ~ F_48 ( V_71 ) ;
V_116 [ V_119 ] = F_58 ( V_125 , V_126 , V_23 ) ;
V_121 [ V_119 ] = V_117 ;
V_115 [ V_119 ] = V_114 ;
V_124 [ V_119 ] = V_21 ;
++ V_119 ;
}
if ( ! V_119 )
break;
F_53 ( V_7 , V_116 , V_119 , V_9 , true ) ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 ) {
V_117 = V_121 [ V_118 ] ;
V_23 = args [ V_117 ] & ( ( 1ul << 56 ) - 1 ) ;
V_114 = V_115 [ V_118 ] ;
V_21 = V_124 [ V_118 ] ;
F_21 ( V_7 , V_23 , V_21 ,
F_40 ( V_114 [ 0 ] ) , F_40 ( V_114 [ 1 ] ) ) ;
V_47 = V_21 -> V_50 & ( V_48 | V_49 ) ;
args [ V_117 ] |= V_47 << ( 56 - 5 ) ;
F_43 ( V_114 , 0 ) ;
}
}
return V_123 ;
}
long F_63 ( struct V_15 * V_91 , unsigned long V_8 ,
unsigned long V_23 , unsigned long V_105 ,
unsigned long V_127 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
T_3 * V_59 ;
struct V_20 * V_21 ;
unsigned long V_93 , V_94 , V_107 , V_128 , V_129 ;
T_4 V_130 , V_109 ;
if ( F_24 ( V_7 ) )
return V_67 ;
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_93 = V_130 = F_40 ( V_59 [ 0 ] ) ;
if ( F_9 ( V_19 ) )
V_93 = F_56 ( V_93 , F_40 ( V_59 [ 1 ] ) ) ;
if ( ( V_93 & ( V_70 | V_71 ) ) == 0 ||
( ( V_8 & V_110 ) && ( V_93 & ~ 0x7fUL ) != V_105 ) ) {
F_43 ( V_59 , V_130 ) ;
return V_112 ;
}
V_109 = F_40 ( V_59 [ 1 ] ) ;
V_129 = ( V_8 << 55 ) & V_82 ;
V_129 |= ( V_8 << 48 ) & V_76 ;
V_129 |= V_8 & ( V_131 | V_132 | V_77 ) ;
V_128 = V_82 | V_131 | V_132 |
V_76 | V_77 ;
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
if ( V_21 ) {
V_94 = ( V_21 -> V_50 & ~ V_128 ) | V_129 ;
V_21 -> V_50 = V_94 ;
F_44 ( V_7 , V_21 ) ;
}
if ( V_93 & V_71 ) {
V_94 = ( V_109 & ~ V_128 ) | V_129 ;
if ( F_25 ( V_94 ) && ! F_25 ( V_109 ) )
V_94 = F_35 ( V_94 ) ;
if ( V_94 != V_109 ) {
V_107 = F_58 ( V_93 , V_94 , V_23 ) ;
V_59 [ 0 ] = F_48 ( ( V_130 & ~ V_71 ) |
V_70 ) ;
F_53 ( V_7 , & V_107 , 1 , F_6 ( V_7 , V_8 ) ,
true ) ;
V_94 |= F_40 ( V_59 [ 1 ] ) & ( V_48 | V_49 ) ;
V_59 [ 1 ] = F_48 ( V_94 ) ;
}
}
F_59 ( V_59 , V_130 & ~ V_69 ) ;
asm volatile("ptesync" : : : "memory");
if ( F_51 ( V_93 , V_109 ) )
F_60 ( & V_7 -> V_11 . V_113 ) ;
return V_90 ;
}
long F_64 ( struct V_15 * V_91 , unsigned long V_8 ,
unsigned long V_23 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
T_3 * V_59 ;
unsigned long V_93 , V_94 ;
int V_27 , V_119 = 1 ;
struct V_20 * V_21 = NULL ;
if ( F_24 ( V_7 ) )
return V_67 ;
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
if ( V_8 & V_133 ) {
V_23 &= ~ 3 ;
V_119 = 4 ;
}
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
for ( V_27 = 0 ; V_27 < V_119 ; ++ V_27 , ++ V_23 ) {
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
V_93 = F_40 ( V_59 [ 0 ] ) & ~ V_69 ;
V_94 = F_40 ( V_59 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_93 = F_56 ( V_93 , V_94 ) ;
V_94 = F_57 ( V_94 ) ;
}
if ( V_93 & V_70 ) {
V_93 &= ~ V_70 ;
V_93 |= V_71 ;
}
if ( V_93 & V_71 ) {
V_94 = V_21 [ V_27 ] . V_50 | ( V_94 & ( V_48 | V_49 ) ) ;
V_94 &= ~ V_72 ;
}
V_91 -> V_11 . V_92 [ 4 + V_27 * 2 ] = V_93 ;
V_91 -> V_11 . V_92 [ 5 + V_27 * 2 ] = V_94 ;
}
return V_90 ;
}
long F_65 ( struct V_15 * V_91 , unsigned long V_8 ,
unsigned long V_23 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
T_3 * V_59 ;
unsigned long V_93 , V_94 , V_134 ;
struct V_20 * V_21 ;
unsigned long * V_22 ;
long V_123 = V_112 ;
if ( F_24 ( V_7 ) )
return V_67 ;
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_93 = F_40 ( V_59 [ 0 ] ) ;
V_94 = F_40 ( V_59 [ 1 ] ) ;
if ( ! ( V_93 & ( V_71 | V_70 ) ) )
goto V_135;
V_134 = V_21 -> V_50 ;
if ( V_21 -> V_50 & V_48 ) {
V_21 -> V_50 &= ~ V_48 ;
F_44 ( V_7 , V_21 ) ;
}
if ( V_93 & V_71 ) {
V_134 |= V_94 & ( V_48 | V_49 ) ;
if ( V_94 & V_48 ) {
F_66 ( V_7 , V_59 , V_23 ) ;
V_22 = F_16 ( V_7 , V_93 , V_134 ) ;
if ( V_22 ) {
F_22 ( V_22 ) ;
* V_22 |= V_136 ;
F_13 ( V_22 ) ;
}
}
}
V_91 -> V_11 . V_92 [ 4 ] = V_134 ;
V_123 = V_90 ;
V_135:
F_59 ( V_59 , V_93 & ~ V_69 ) ;
return V_123 ;
}
long F_67 ( struct V_15 * V_91 , unsigned long V_8 ,
unsigned long V_23 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
T_3 * V_59 ;
unsigned long V_93 , V_94 , V_134 ;
struct V_20 * V_21 ;
unsigned long * V_22 ;
long V_123 = V_112 ;
if ( F_24 ( V_7 ) )
return V_67 ;
if ( V_23 >= F_38 ( & V_7 -> V_11 . V_30 ) )
return V_68 ;
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_23 ] ) ;
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_23 << 4 ) ) ;
while ( ! F_41 ( V_59 , V_69 ) )
F_42 () ;
V_93 = F_40 ( V_59 [ 0 ] ) ;
V_94 = F_40 ( V_59 [ 1 ] ) ;
if ( ! ( V_93 & ( V_71 | V_70 ) ) )
goto V_135;
V_134 = V_21 -> V_50 ;
if ( V_134 & V_49 ) {
V_21 -> V_50 &= ~ V_49 ;
F_44 ( V_7 , V_21 ) ;
}
if ( V_93 & V_71 ) {
V_59 [ 0 ] |= F_48 ( V_70 ) ;
F_68 ( V_7 , V_59 , V_23 ) ;
V_94 = F_40 ( V_59 [ 1 ] ) ;
V_134 |= V_94 & ( V_48 | V_49 ) ;
if ( V_94 & V_49 ) {
unsigned long V_33 = F_18 ( V_93 , V_94 ) ;
V_59 [ 1 ] = F_48 ( V_94 & ~ V_49 ) ;
F_49 () ;
V_22 = F_16 ( V_7 , V_93 , V_134 ) ;
if ( V_22 ) {
F_22 ( V_22 ) ;
* V_22 |= V_137 ;
F_14 ( V_22 , V_33 ) ;
F_13 ( V_22 ) ;
}
}
}
V_91 -> V_11 . V_92 [ 4 ] = V_134 ;
V_123 = V_90 ;
V_135:
F_59 ( V_59 , V_93 & ~ V_69 ) ;
return V_123 ;
}
void F_68 ( struct V_7 * V_7 , T_3 * V_138 ,
unsigned long V_23 )
{
unsigned long V_107 ;
T_4 V_125 , V_126 ;
V_138 [ 0 ] &= ~ F_48 ( V_71 ) ;
V_125 = F_40 ( V_138 [ 0 ] ) ;
V_126 = F_40 ( V_138 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_125 = F_56 ( V_125 , V_126 ) ;
V_126 = F_57 ( V_126 ) ;
}
V_107 = F_58 ( V_125 , V_126 , V_23 ) ;
F_53 ( V_7 , & V_107 , 1 , 1 , true ) ;
}
void F_66 ( struct V_7 * V_7 , T_3 * V_138 ,
unsigned long V_23 )
{
unsigned long V_107 ;
unsigned char V_139 ;
T_4 V_125 , V_126 ;
V_125 = F_40 ( V_138 [ 0 ] ) ;
V_126 = F_40 ( V_138 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_125 = F_56 ( V_125 , V_126 ) ;
V_126 = F_57 ( V_126 ) ;
}
V_107 = F_58 ( V_125 , V_126 , V_23 ) ;
V_139 = ( F_40 ( V_138 [ 1 ] ) & ~ V_48 ) >> 8 ;
* ( ( char * ) V_138 + 14 ) = V_139 ;
F_53 ( V_7 , & V_107 , 1 , 1 , false ) ;
}
static struct V_140 * F_69 ( struct V_15 * V_91 ,
unsigned long V_141 , unsigned long V_142 , long V_113 )
{
struct V_140 * V_143 = NULL ;
unsigned int V_144 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_145 ; V_27 ++ ) {
V_143 = & V_91 -> V_11 . V_146 . V_143 [ V_27 ] ;
if ( V_143 -> V_113 == V_113 ) {
V_144 = V_143 -> V_147 ;
if ( ( V_143 -> V_141 >> V_144 ) == ( V_141 >> V_144 ) &&
V_143 -> V_142 == V_142 )
return V_143 ;
}
}
return NULL ;
}
static struct V_140 *
F_70 ( struct V_15 * V_91 )
{
unsigned int V_148 = V_91 -> V_11 . V_146 . V_148 ;
V_91 -> V_11 . V_146 . V_148 ++ ;
if ( V_91 -> V_11 . V_146 . V_148 == V_145 )
V_91 -> V_11 . V_146 . V_148 = 0 ;
return & V_91 -> V_11 . V_146 . V_143 [ V_148 ] ;
}
long F_71 ( struct V_7 * V_7 , T_5 V_141 , unsigned long V_142 ,
unsigned long V_149 )
{
unsigned int V_27 ;
unsigned int V_144 ;
unsigned long V_150 ;
unsigned long V_151 , V_152 ;
unsigned long V_105 ;
T_3 * V_59 ;
unsigned long V_128 , V_153 ;
unsigned long V_93 , V_94 , V_154 ;
V_128 = V_155 | V_156 | V_157 ;
V_153 = 0 ;
V_144 = 12 ;
if ( V_142 & V_158 ) {
V_128 |= V_159 ;
V_153 |= V_159 ;
V_144 = V_160 [ ( V_142 & V_161 ) >> 4 ] ;
}
if ( V_142 & V_162 ) {
V_150 = ( 1UL << 40 ) - 1 ;
V_151 = ( V_142 & ~ V_155 ) >> V_163 ;
V_151 ^= V_151 << 25 ;
} else {
V_150 = ( 1UL << 28 ) - 1 ;
V_151 = ( V_142 & ~ V_155 ) >> V_164 ;
}
V_152 = ( V_151 ^ ( ( V_141 & V_150 ) >> V_144 ) ) & F_72 ( & V_7 -> V_11 . V_30 ) ;
V_105 = V_142 & ~ ( V_150 >> 16 ) ;
V_105 |= ( V_141 & V_150 ) >> 16 ;
if ( V_144 >= 24 )
V_105 &= ~ ( ( 1UL << ( V_144 - 16 ) ) - 1 ) ;
else
V_105 &= ~ 0x7fUL ;
V_153 |= V_105 ;
for (; ; ) {
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_152 << 7 ) ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 += 2 ) {
V_93 = F_40 ( V_59 [ V_27 ] ) & ~ V_69 ;
if ( F_9 ( V_19 ) )
V_93 = F_56 ( V_93 , F_40 ( V_59 [ V_27 + 1 ] ) ) ;
if ( ! ( V_93 & V_149 ) || ( V_93 & V_128 ) != V_153 )
continue;
while ( ! F_41 ( & V_59 [ V_27 ] , V_69 ) )
F_42 () ;
V_93 = V_154 = F_40 ( V_59 [ V_27 ] ) & ~ V_69 ;
V_94 = F_40 ( V_59 [ V_27 + 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_93 = F_56 ( V_93 , V_94 ) ;
V_94 = F_57 ( V_94 ) ;
}
if ( ( V_93 & V_149 ) && ( V_93 & V_128 ) == V_153 &&
F_73 ( V_93 , V_94 ) == ( 1ul << V_144 ) )
return ( V_152 << 3 ) + ( V_27 >> 1 ) ;
F_43 ( & V_59 [ V_27 ] , V_154 ) ;
}
if ( V_153 & V_157 )
break;
V_153 |= V_157 ;
V_152 = V_152 ^ F_72 ( & V_7 -> V_11 . V_30 ) ;
}
return - 1 ;
}
long F_74 ( struct V_15 * V_91 , unsigned long V_2 ,
unsigned long V_142 , unsigned int V_165 , bool V_166 )
{
struct V_7 * V_7 = V_91 -> V_7 ;
long int V_148 ;
unsigned long V_93 , V_94 , V_134 , V_154 ;
T_3 * V_59 ;
unsigned long V_149 ;
struct V_20 * V_21 ;
unsigned long V_167 , V_168 ;
struct V_140 * V_169 = NULL ;
long V_113 = 0 ;
V_149 = V_71 ;
if ( V_165 & V_170 ) {
V_149 |= V_70 ;
V_113 = F_75 ( & V_7 -> V_11 . V_113 ) ;
V_169 = F_69 ( V_91 , V_2 , V_142 , V_113 ) ;
}
if ( V_169 ) {
V_148 = V_169 -> V_23 ;
V_93 = V_169 -> V_37 ;
V_94 = V_169 -> V_43 ;
V_134 = V_169 -> V_171 ;
} else {
V_148 = F_71 ( V_7 , V_2 , V_142 , V_149 ) ;
if ( V_148 < 0 ) {
if ( V_165 & V_170 )
return V_165 ;
return 0 ;
}
V_59 = ( T_3 * ) ( V_7 -> V_11 . V_30 . V_88 + ( V_148 << 4 ) ) ;
V_93 = V_154 = F_40 ( V_59 [ 0 ] ) & ~ V_69 ;
V_94 = F_40 ( V_59 [ 1 ] ) ;
if ( F_9 ( V_19 ) ) {
V_93 = F_56 ( V_93 , V_94 ) ;
V_94 = F_57 ( V_94 ) ;
}
V_21 = F_1 ( & V_7 -> V_11 . V_30 . V_21 [ V_148 ] ) ;
V_134 = V_21 -> V_50 ;
F_59 ( V_59 , V_154 ) ;
}
if ( ( V_165 & V_170 ) && ( V_93 & V_71 ) )
return 0 ;
V_167 = V_134 & ( V_82 | V_131 ) ;
V_168 = ( V_91 -> V_11 . V_172 . V_173 & V_174 ) ? V_175 : V_176 ;
V_165 &= ~ V_170 ;
if ( ! V_166 ) {
if ( V_134 & ( V_132 | V_85 ) )
return V_165 | V_177 ;
if ( ! F_76 ( V_167 , V_142 & V_168 ) )
return V_165 | V_178 ;
} else if ( V_165 & V_179 ) {
if ( ! F_77 ( V_167 , V_142 & V_168 ) )
return V_165 | V_180 ;
} else {
if ( ! F_76 ( V_167 , V_142 & V_168 ) )
return V_165 | V_180 ;
}
if ( V_166 && ( V_91 -> V_11 . V_172 . V_173 & V_181 ) ) {
unsigned int V_182 = F_78 ( V_134 , V_91 -> V_11 . V_183 ) ;
if ( V_165 & V_179 )
V_182 >>= 1 ;
if ( V_182 & 1 )
return V_165 | V_184 ;
}
V_91 -> V_11 . V_185 = V_2 ;
V_91 -> V_11 . V_186 = V_148 ;
V_91 -> V_11 . V_187 [ 0 ] = V_93 ;
V_91 -> V_11 . V_187 [ 1 ] = V_94 ;
V_91 -> V_11 . V_188 = V_169 ;
if ( ( V_94 & ( V_76 | V_77 ) ) ==
( V_76 | V_77 ) ) {
if ( ! V_169 ) {
unsigned int V_144 = 12 ;
unsigned int V_189 ;
if ( V_142 & V_158 ) {
V_189 = ( ( V_142 & V_161 ) >> 4 ) ;
V_144 = V_160 [ V_189 ] ;
}
V_169 = F_70 ( V_91 ) ;
V_169 -> V_141 = V_2 ;
V_169 -> V_147 = V_144 ;
V_169 -> V_23 = V_148 ;
V_169 -> V_37 = V_93 ;
V_169 -> V_43 = V_94 ;
V_169 -> V_171 = V_134 ;
V_169 -> V_142 = V_142 ;
V_169 -> V_113 = V_113 ;
}
if ( V_166 && ( V_91 -> V_11 . V_172 . V_173 & V_190 ) )
return - 2 ;
}
return - 1 ;
}
