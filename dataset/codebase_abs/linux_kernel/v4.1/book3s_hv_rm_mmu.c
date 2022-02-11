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
static void F_12 ( struct V_7 * V_7 , long V_21 ,
struct V_18 * V_19 ,
unsigned long V_31 , unsigned long V_32 )
{
struct V_18 * V_33 , * V_34 ;
unsigned long V_35 , V_36 , V_23 ;
struct V_37 * V_38 ;
unsigned long * V_20 ;
unsigned long V_39 ;
V_39 = V_32 & ( V_40 | V_41 ) ;
V_36 = V_19 -> V_42 |= V_39 ;
V_35 = F_13 ( V_36 , F_14 ( V_31 , V_36 ) ) ;
V_38 = F_15 ( F_16 ( V_7 ) , V_35 ) ;
if ( ! V_38 )
return;
V_20 = F_1 ( & V_38 -> V_10 . V_20 [ V_35 - V_38 -> V_43 ] ) ;
F_17 ( V_20 ) ;
V_23 = * V_20 & V_27 ;
V_33 = F_1 ( & V_7 -> V_10 . V_28 [ V_19 -> V_30 ] ) ;
V_34 = F_1 ( & V_7 -> V_10 . V_28 [ V_19 -> V_29 ] ) ;
V_33 -> V_29 = V_19 -> V_29 ;
V_34 -> V_30 = V_19 -> V_30 ;
if ( V_23 == V_21 ) {
V_23 = V_19 -> V_30 ;
if ( V_23 == V_21 )
* V_20 &= ~ ( V_26 | V_27 ) ;
else
* V_20 = ( * V_20 & ~ V_27 ) | V_23 ;
}
* V_20 |= V_39 << V_44 ;
F_11 ( V_20 ) ;
}
long F_18 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_21 , unsigned long V_45 , unsigned long V_36 ,
T_2 * V_46 , bool V_22 , unsigned long * V_47 )
{
unsigned long V_25 , V_48 , V_49 , V_35 , V_50 ;
unsigned long V_51 , V_52 ;
T_3 * V_53 ;
struct V_18 * V_19 ;
unsigned long V_54 ;
struct V_37 * V_38 ;
unsigned V_55 ;
unsigned long V_56 ;
unsigned long * V_20 ;
T_1 * V_57 ;
unsigned int V_58 ;
unsigned long V_59 ;
unsigned long V_39 , V_60 = 0 ;
V_50 = F_14 ( V_45 , V_36 ) ;
if ( ! V_50 )
return V_61 ;
V_58 = F_19 ( V_36 ) ;
V_45 &= ~ ( V_62 | V_63 | V_64 ) ;
V_36 &= ~ V_65 ;
V_54 = V_36 ;
V_59 = V_7 -> V_66 ;
F_20 () ;
V_49 = ( V_36 & V_67 ) & ~ ( V_50 - 1 ) ;
V_35 = V_49 >> V_5 ;
V_38 = F_15 ( F_16 ( V_7 ) , V_35 ) ;
V_48 = 0 ;
V_56 = ~ 0ul ;
V_20 = NULL ;
if ( ! ( V_38 && ! ( V_38 -> V_8 & V_68 ) ) ) {
V_45 |= V_63 ;
V_36 |= V_69 | V_70 ;
goto V_71;
}
if ( ! F_21 ( V_38 , V_50 ) )
return V_61 ;
V_51 = V_35 - V_38 -> V_43 ;
V_20 = & V_38 -> V_10 . V_20 [ V_51 ] ;
V_52 = F_22 ( V_38 , V_35 ) ;
if ( V_22 )
V_57 = F_2 ( V_46 , V_52 , & V_55 ) ;
else {
F_23 ( V_60 ) ;
V_57 = F_24 ( V_46 , V_52 , & V_55 ) ;
}
if ( V_57 ) {
T_1 V_72 ;
unsigned int V_73 ;
if ( V_55 )
V_73 = 1ul << V_55 ;
else
V_73 = V_74 ;
if ( V_73 < V_50 ) {
if ( ! V_22 )
F_25 ( V_8 ) ;
return V_61 ;
}
V_72 = F_26 ( V_57 , V_58 ) ;
if ( F_3 ( V_72 ) && ! F_27 ( V_72 ) ) {
if ( V_58 && ! F_28 ( V_72 ) )
V_36 = F_29 ( V_36 ) ;
V_56 = F_30 ( F_31 ( V_72 ) ) ;
V_48 = F_4 ( V_72 ) << V_5 ;
V_48 |= V_52 & ( V_73 - 1 ) ;
V_48 |= V_49 & ~ V_6 ;
}
}
if ( ! V_22 )
F_25 ( V_60 ) ;
V_36 &= ~ ( V_75 - V_50 ) ;
V_36 |= V_48 ;
if ( V_48 )
V_45 |= V_64 ;
else
V_45 |= V_63 ;
if ( V_56 != ~ 0ul && ! F_32 ( V_36 , V_56 ) ) {
if ( V_56 )
return V_61 ;
V_36 &= ~ ( V_76 | V_77 | V_78 ) ;
V_36 |= V_79 ;
}
V_71:
if ( V_21 >= V_7 -> V_10 . V_80 )
return V_61 ;
if ( F_33 ( ( V_8 & V_81 ) == 0 ) ) {
V_21 &= ~ 7UL ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
if ( ( F_34 ( * V_53 ) & V_64 ) == 0 &&
F_35 ( V_53 , V_62 | V_64 |
V_63 ) )
break;
V_53 += 2 ;
}
if ( V_25 == 8 ) {
V_53 -= 16 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
T_4 V_72 ;
while ( ! F_35 ( V_53 , V_62 ) )
F_36 () ;
V_72 = F_34 ( V_53 [ 0 ] ) ;
if ( ! ( V_72 & ( V_64 | V_63 ) ) )
break;
F_37 ( V_53 , V_72 ) ;
V_53 += 2 ;
}
if ( V_25 == 8 )
return V_83 ;
}
V_21 += V_25 ;
} else {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
if ( ! F_35 ( V_53 , V_62 | V_64 |
V_63 ) ) {
T_4 V_72 ;
while ( ! F_35 ( V_53 , V_62 ) )
F_36 () ;
V_72 = F_34 ( V_53 [ 0 ] ) ;
if ( V_72 & ( V_64 | V_63 ) ) {
F_37 ( V_53 , V_72 ) ;
return V_83 ;
}
}
}
V_19 = & V_7 -> V_10 . V_28 [ V_21 ] ;
if ( V_22 )
V_19 = F_1 ( V_19 ) ;
if ( V_19 ) {
V_19 -> V_42 = V_54 ;
F_38 ( V_7 , V_19 ) ;
}
if ( V_45 & V_64 ) {
if ( V_22 )
V_20 = F_1 ( V_20 ) ;
F_17 ( V_20 ) ;
if ( F_39 ( V_7 , V_59 ) ) {
V_45 |= V_63 ;
V_45 &= ~ V_64 ;
F_11 ( V_20 ) ;
} else {
F_10 ( V_7 , V_19 , V_20 , V_21 ,
V_22 ) ;
V_39 = * V_20 >> V_44 ;
V_36 &= V_39 | ~ ( V_40 | V_41 ) ;
}
}
V_53 [ 1 ] = F_40 ( V_36 ) ;
F_41 () ;
F_37 ( V_53 , V_45 ) ;
asm volatile("ptesync" : : : "memory");
* V_47 = V_21 ;
return V_84 ;
}
long F_42 ( struct V_14 * V_85 , unsigned long V_8 ,
long V_21 , unsigned long V_45 , unsigned long V_36 )
{
return F_18 ( V_85 -> V_7 , V_8 , V_21 , V_45 , V_36 ,
V_85 -> V_10 . V_46 , true , & V_85 -> V_10 . V_86 [ 4 ] ) ;
}
static inline int F_43 ( unsigned int * V_87 )
{
unsigned int V_88 , V_89 ;
unsigned int V_90 = V_91 ;
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
return V_89 == 0 ;
}
static void F_44 ( struct V_7 * V_7 , unsigned long * V_92 ,
long V_93 , int V_9 , bool V_94 )
{
long V_25 ;
if ( V_9 ) {
while ( ! F_43 ( & V_7 -> V_10 . V_95 ) )
F_36 () ;
if ( V_94 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_93 ; ++ V_25 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_95 = 0 ;
} else {
if ( V_94 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_93 ; ++ V_25 )
asm volatile("tlbiel %0" : : "r" (rbvalues[i]));
asm volatile("ptesync" : : : "memory");
}
}
long F_45 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_96 ,
unsigned long * V_97 )
{
T_3 * V_53 ;
unsigned long V_98 , V_99 , V_100 ;
struct V_18 * V_19 ;
T_4 V_72 ;
if ( V_21 >= V_7 -> V_10 . V_80 )
return V_61 ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
while ( ! F_35 ( V_53 , V_62 ) )
F_36 () ;
V_72 = F_34 ( V_53 [ 0 ] ) ;
if ( ( V_72 & ( V_63 | V_64 ) ) == 0 ||
( ( V_8 & V_101 ) && ( V_72 & ~ 0x7fUL ) != V_96 ) ||
( ( V_8 & V_102 ) && ( V_72 & V_96 ) != 0 ) ) {
F_37 ( V_53 , V_72 ) ;
return V_103 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_98 = V_72 & ~ V_62 ;
if ( V_98 & V_64 ) {
T_4 V_104 ;
V_104 = F_34 ( V_53 [ 1 ] ) ;
V_53 [ 0 ] &= ~ F_40 ( V_64 ) ;
V_100 = F_46 ( V_98 , V_104 , V_21 ) ;
F_44 ( V_7 , & V_100 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_12 ( V_7 , V_21 , V_19 , V_98 , V_104 ) ;
}
V_99 = V_19 -> V_42 & ~ V_65 ;
F_38 ( V_7 , V_19 ) ;
F_47 ( V_53 , 0 ) ;
V_97 [ 0 ] = V_98 ;
V_97 [ 1 ] = V_99 ;
return V_84 ;
}
long F_48 ( struct V_14 * V_85 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_96 )
{
return F_45 ( V_85 -> V_7 , V_8 , V_21 , V_96 ,
& V_85 -> V_10 . V_86 [ 4 ] ) ;
}
long F_49 ( struct V_14 * V_85 )
{
struct V_7 * V_7 = V_85 -> V_7 ;
unsigned long * args = & V_85 -> V_10 . V_86 [ 4 ] ;
T_3 * V_105 , * V_106 [ 4 ] ;
unsigned long V_107 [ 4 ] ;
long int V_25 , V_108 , V_109 , V_110 , V_111 , V_112 [ 4 ] ;
unsigned long V_8 , V_113 , V_21 , V_39 ;
int V_9 ;
long int V_114 = V_84 ;
struct V_18 * V_19 , * V_115 [ 4 ] ;
T_4 V_116 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_25 = 0 ; V_25 < 4 && V_114 == V_84 ; ) {
V_110 = 0 ;
for (; V_25 < 4 ; ++ V_25 ) {
V_108 = V_25 * 2 ;
V_21 = args [ V_108 ] ;
V_8 = V_21 >> 56 ;
V_21 &= ( ( 1ul << 56 ) - 1 ) ;
V_113 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_113 == 3 ) {
V_25 = 4 ;
break;
}
if ( V_113 != 1 || V_8 == 3 ||
V_21 >= V_7 -> V_10 . V_80 ) {
args [ V_108 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_21 ;
V_114 = V_61 ;
break;
}
V_105 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
if ( ! F_35 ( V_105 , V_62 ) ) {
if ( V_110 )
break;
while ( ! F_35 ( V_105 , V_62 ) )
F_36 () ;
}
V_111 = 0 ;
V_116 = F_34 ( V_105 [ 0 ] ) ;
if ( V_116 & ( V_63 | V_64 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_111 = 1 ;
break;
case 1 :
if ( ! ( V_116 & args [ V_108 + 1 ] ) )
V_111 = 1 ;
break;
case 2 :
if ( ( V_116 & ~ 0x7fUL ) == args [ V_108 + 1 ] )
V_111 = 1 ;
break;
}
}
if ( ! V_111 ) {
V_105 [ 0 ] &= ~ F_40 ( V_62 ) ;
args [ V_108 ] = ( ( 0x90 | V_8 ) << 56 ) + V_21 ;
continue;
}
args [ V_108 ] = ( ( 0x80 | V_8 ) << 56 ) + V_21 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
F_38 ( V_7 , V_19 ) ;
if ( ! ( V_116 & V_64 ) ) {
V_39 = V_19 -> V_42 & ( V_40 | V_41 ) ;
args [ V_108 ] |= V_39 << ( 56 - 5 ) ;
V_105 [ 0 ] = 0 ;
continue;
}
V_105 [ 0 ] &= ~ F_40 ( V_64 ) ;
V_107 [ V_110 ] = F_46 ( F_34 ( V_105 [ 0 ] ) ,
F_34 ( V_105 [ 1 ] ) , V_21 ) ;
V_112 [ V_110 ] = V_108 ;
V_106 [ V_110 ] = V_105 ;
V_115 [ V_110 ] = V_19 ;
++ V_110 ;
}
if ( ! V_110 )
break;
F_44 ( V_7 , V_107 , V_110 , V_9 , true ) ;
for ( V_109 = 0 ; V_109 < V_110 ; ++ V_109 ) {
V_108 = V_112 [ V_109 ] ;
V_21 = args [ V_108 ] & ( ( 1ul << 56 ) - 1 ) ;
V_105 = V_106 [ V_109 ] ;
V_19 = V_115 [ V_109 ] ;
F_12 ( V_7 , V_21 , V_19 ,
F_34 ( V_105 [ 0 ] ) , F_34 ( V_105 [ 1 ] ) ) ;
V_39 = V_19 -> V_42 & ( V_40 | V_41 ) ;
args [ V_108 ] |= V_39 << ( 56 - 5 ) ;
F_37 ( V_105 , 0 ) ;
}
}
return V_114 ;
}
long F_50 ( struct V_14 * V_85 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_96 ,
unsigned long V_117 )
{
struct V_7 * V_7 = V_85 -> V_7 ;
T_3 * V_53 ;
struct V_18 * V_19 ;
unsigned long V_98 , V_99 , V_100 , V_118 , V_119 ;
T_4 V_72 ;
if ( V_21 >= V_7 -> V_10 . V_80 )
return V_61 ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
while ( ! F_35 ( V_53 , V_62 ) )
F_36 () ;
V_72 = F_34 ( V_53 [ 0 ] ) ;
if ( ( V_72 & ( V_63 | V_64 ) ) == 0 ||
( ( V_8 & V_101 ) && ( V_72 & ~ 0x7fUL ) != V_96 ) ) {
F_37 ( V_53 , V_72 ) ;
return V_103 ;
}
V_98 = V_72 ;
V_119 = ( V_8 << 55 ) & V_75 ;
V_119 |= ( V_8 << 48 ) & V_69 ;
V_119 |= V_8 & ( V_120 | V_121 | V_70 ) ;
V_118 = V_75 | V_120 | V_121 |
V_69 | V_70 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
if ( V_19 ) {
V_99 = ( V_19 -> V_42 & ~ V_118 ) | V_119 ;
V_19 -> V_42 = V_99 ;
F_38 ( V_7 , V_19 ) ;
}
if ( V_98 & V_64 ) {
V_72 = F_34 ( V_53 [ 1 ] ) ;
V_99 = ( V_72 & ~ V_118 ) | V_119 ;
if ( F_19 ( V_99 ) && ! F_19 ( V_72 ) )
V_99 = F_29 ( V_99 ) ;
if ( V_99 != V_72 ) {
V_100 = F_46 ( V_98 , V_99 , V_21 ) ;
V_53 [ 0 ] = F_40 ( ( V_98 & ~ V_64 ) |
V_63 ) ;
F_44 ( V_7 , & V_100 , 1 , F_6 ( V_7 , V_8 ) ,
true ) ;
V_53 [ 1 ] = F_40 ( V_99 ) ;
}
}
F_47 ( V_53 , V_98 & ~ V_62 ) ;
asm volatile("ptesync" : : : "memory");
return V_84 ;
}
long F_51 ( struct V_14 * V_85 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_85 -> V_7 ;
T_3 * V_53 ;
unsigned long V_98 , V_99 ;
int V_25 , V_110 = 1 ;
struct V_18 * V_19 = NULL ;
if ( V_21 >= V_7 -> V_10 . V_80 )
return V_61 ;
if ( V_8 & V_122 ) {
V_21 &= ~ 3 ;
V_110 = 4 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
for ( V_25 = 0 ; V_25 < V_110 ; ++ V_25 , ++ V_21 ) {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_21 << 4 ) ) ;
V_98 = F_34 ( V_53 [ 0 ] ) & ~ V_62 ;
V_99 = F_34 ( V_53 [ 1 ] ) ;
if ( V_98 & V_63 ) {
V_98 &= ~ V_63 ;
V_98 |= V_64 ;
}
if ( V_98 & V_64 ) {
V_99 = V_19 [ V_25 ] . V_42 | ( V_99 & ( V_40 | V_41 ) ) ;
V_99 &= ~ V_65 ;
}
V_85 -> V_10 . V_86 [ 4 + V_25 * 2 ] = V_98 ;
V_85 -> V_10 . V_86 [ 5 + V_25 * 2 ] = V_99 ;
}
return V_84 ;
}
void F_52 ( struct V_7 * V_7 , T_3 * V_123 ,
unsigned long V_21 )
{
unsigned long V_100 ;
V_123 [ 0 ] &= ~ F_40 ( V_64 ) ;
V_100 = F_46 ( F_34 ( V_123 [ 0 ] ) , F_34 ( V_123 [ 1 ] ) ,
V_21 ) ;
F_44 ( V_7 , & V_100 , 1 , 1 , true ) ;
}
void F_53 ( struct V_7 * V_7 , T_3 * V_123 ,
unsigned long V_21 )
{
unsigned long V_100 ;
unsigned char V_124 ;
V_100 = F_46 ( F_34 ( V_123 [ 0 ] ) , F_34 ( V_123 [ 1 ] ) ,
V_21 ) ;
V_124 = ( F_34 ( V_123 [ 1 ] ) & ~ V_40 ) >> 8 ;
* ( ( char * ) V_123 + 14 ) = V_124 ;
F_44 ( V_7 , & V_100 , 1 , 1 , false ) ;
}
long F_54 ( struct V_7 * V_7 , T_5 V_125 , unsigned long V_126 ,
unsigned long V_127 )
{
unsigned int V_25 ;
unsigned int V_128 ;
unsigned long V_129 ;
unsigned long V_130 , V_131 ;
unsigned long V_96 ;
T_3 * V_53 ;
unsigned long V_118 , V_132 ;
unsigned long V_98 , V_99 ;
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
V_131 = ( V_130 ^ ( ( V_125 & V_129 ) >> V_128 ) ) & V_7 -> V_10 . V_143 ;
V_96 = V_126 & ~ ( V_129 >> 16 ) ;
V_96 |= ( V_125 & V_129 ) >> 16 ;
if ( V_128 >= 24 )
V_96 &= ~ ( ( 1UL << ( V_128 - 16 ) ) - 1 ) ;
else
V_96 &= ~ 0x7fUL ;
V_132 |= V_96 ;
for (; ; ) {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_131 << 7 ) ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 += 2 ) {
V_98 = F_34 ( V_53 [ V_25 ] ) & ~ V_62 ;
if ( ! ( V_98 & V_127 ) || ( V_98 & V_118 ) != V_132 )
continue;
while ( ! F_35 ( & V_53 [ V_25 ] , V_62 ) )
F_36 () ;
V_98 = F_34 ( V_53 [ V_25 ] ) & ~ V_62 ;
V_99 = F_34 ( V_53 [ V_25 + 1 ] ) ;
if ( ( V_98 & V_127 ) && ( V_98 & V_118 ) == V_132 &&
F_55 ( V_98 , V_99 ) == ( 1ul << V_128 ) )
return ( V_131 << 3 ) + ( V_25 >> 1 ) ;
F_37 ( & V_53 [ V_25 ] , V_98 ) ;
}
if ( V_132 & V_135 )
break;
V_132 |= V_135 ;
V_131 = V_131 ^ V_7 -> V_10 . V_143 ;
}
return - 1 ;
}
long F_56 ( struct V_14 * V_85 , unsigned long V_2 ,
unsigned long V_126 , unsigned int V_144 , bool V_145 )
{
struct V_7 * V_7 = V_85 -> V_7 ;
long int V_146 ;
unsigned long V_98 , V_99 , V_147 ;
T_3 * V_53 ;
unsigned long V_127 ;
struct V_18 * V_19 ;
unsigned long V_148 , V_149 ;
V_127 = V_64 ;
if ( V_144 & V_150 )
V_127 |= V_63 ;
V_146 = F_54 ( V_7 , V_2 , V_126 , V_127 ) ;
if ( V_146 < 0 ) {
if ( V_144 & V_150 )
return V_144 ;
return 0 ;
}
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_82 + ( V_146 << 4 ) ) ;
V_98 = F_34 ( V_53 [ 0 ] ) & ~ V_62 ;
V_99 = F_34 ( V_53 [ 1 ] ) ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_146 ] ) ;
V_147 = V_19 -> V_42 ;
F_47 ( V_53 , V_98 ) ;
if ( ( V_144 & V_150 ) && ( V_98 & V_64 ) )
return 0 ;
V_148 = V_147 & ( V_75 | V_120 ) ;
V_149 = ( V_85 -> V_10 . V_151 . V_152 & V_153 ) ? V_154 : V_155 ;
V_144 &= ~ V_150 ;
if ( ! V_145 ) {
if ( V_147 & ( V_121 | V_78 ) )
return V_144 | V_156 ;
if ( ! F_57 ( V_148 , V_126 & V_149 ) )
return V_144 | V_157 ;
} else if ( V_144 & V_158 ) {
if ( ! F_58 ( V_148 , V_126 & V_149 ) )
return V_144 | V_159 ;
} else {
if ( ! F_57 ( V_148 , V_126 & V_149 ) )
return V_144 | V_159 ;
}
if ( V_145 && ( V_85 -> V_10 . V_151 . V_152 & V_160 ) ) {
unsigned int V_161 = F_59 ( V_147 , V_85 -> V_10 . V_162 ) ;
if ( V_144 & V_158 )
V_161 >>= 1 ;
if ( V_161 & 1 )
return V_144 | V_163 ;
}
V_85 -> V_10 . V_164 = V_2 ;
V_85 -> V_10 . V_165 = V_146 ;
V_85 -> V_10 . V_166 [ 0 ] = V_98 ;
V_85 -> V_10 . V_166 [ 1 ] = V_99 ;
if ( V_145 && ( V_85 -> V_10 . V_151 . V_152 & V_167 ) &&
( V_99 & ( V_69 | V_70 ) ) ==
( V_69 | V_70 ) )
return - 2 ;
return - 1 ;
}
