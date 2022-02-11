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
static T_1 F_18 ( T_2 * V_45 , unsigned long V_46 ,
int V_47 , unsigned long * V_48 )
{
T_1 * V_49 ;
unsigned long V_50 = * V_48 ;
unsigned int V_51 ;
V_49 = F_2 ( V_45 , V_46 , & V_51 ) ;
if ( ! V_49 )
return F_19 ( 0 ) ;
if ( V_51 )
* V_48 = 1ul << V_51 ;
else
* V_48 = V_52 ;
if ( V_50 > * V_48 )
return F_19 ( 0 ) ;
return F_20 ( V_49 , V_47 , V_51 ) ;
}
static inline void F_21 ( T_3 * V_53 , unsigned long V_31 )
{
asm volatile(PPC_RELEASE_BARRIER "" : : : "memory");
V_53 [ 0 ] = F_22 ( V_31 ) ;
}
long F_23 ( struct V_7 * V_7 , unsigned long V_8 ,
long V_21 , unsigned long V_54 , unsigned long V_36 ,
T_2 * V_45 , bool V_22 , unsigned long * V_55 )
{
unsigned long V_25 , V_56 , V_57 , V_35 , V_58 ;
unsigned long V_59 , V_46 ;
T_3 * V_53 ;
struct V_18 * V_19 ;
unsigned long V_60 ;
struct V_37 * V_38 ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long * V_20 ;
T_1 V_63 ;
unsigned int V_47 ;
unsigned long V_64 ;
unsigned long V_39 ;
V_58 = F_14 ( V_54 , V_36 ) ;
if ( ! V_58 )
return V_65 ;
V_47 = F_24 ( V_36 ) ;
V_54 &= ~ ( V_66 | V_67 | V_68 ) ;
V_36 &= ~ V_69 ;
V_60 = V_36 ;
V_64 = V_7 -> V_70 ;
F_25 () ;
V_57 = ( V_36 & V_71 ) & ~ ( V_58 - 1 ) ;
V_35 = V_57 >> V_5 ;
V_38 = F_15 ( F_16 ( V_7 ) , V_35 ) ;
V_56 = 0 ;
V_62 = ~ 0ul ;
V_20 = NULL ;
if ( ! ( V_38 && ! ( V_38 -> V_8 & V_72 ) ) ) {
V_54 |= V_67 ;
V_36 |= V_73 | V_74 ;
goto V_75;
}
if ( ! F_26 ( V_38 , V_58 ) )
return V_65 ;
V_59 = V_35 - V_38 -> V_43 ;
V_20 = & V_38 -> V_10 . V_20 [ V_59 ] ;
V_46 = F_27 ( V_38 , V_35 ) ;
V_61 = V_58 ;
V_63 = F_18 ( V_45 , V_46 , V_47 , & V_61 ) ;
if ( F_3 ( V_63 ) && ! F_28 ( V_63 ) ) {
if ( V_47 && ! F_29 ( V_63 ) )
V_36 = F_30 ( V_36 ) ;
V_62 = F_31 ( F_32 ( V_63 ) ) ;
V_56 = F_4 ( V_63 ) << V_5 ;
V_56 |= V_46 & ( V_61 - 1 ) ;
V_56 |= V_57 & ~ V_6 ;
}
if ( V_61 < V_58 )
return V_65 ;
V_36 &= ~ ( V_76 - V_58 ) ;
V_36 |= V_56 ;
if ( V_56 )
V_54 |= V_68 ;
else
V_54 |= V_67 ;
if ( V_62 != ~ 0ul && ! F_33 ( V_36 , V_62 ) ) {
if ( V_62 )
return V_65 ;
V_36 &= ~ ( V_77 | V_78 | V_79 ) ;
V_36 |= V_80 ;
}
V_75:
if ( V_21 >= V_7 -> V_10 . V_81 )
return V_65 ;
if ( F_34 ( ( V_8 & V_82 ) == 0 ) ) {
V_21 &= ~ 7UL ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
if ( ( F_35 ( * V_53 ) & V_68 ) == 0 &&
F_36 ( V_53 , V_66 | V_68 |
V_67 ) )
break;
V_53 += 2 ;
}
if ( V_25 == 8 ) {
V_53 -= 16 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 ) {
T_4 V_63 ;
while ( ! F_36 ( V_53 , V_66 ) )
F_37 () ;
V_63 = F_35 ( * V_53 ) ;
if ( ! ( V_63 & ( V_68 | V_67 ) ) )
break;
* V_53 &= ~ F_22 ( V_66 ) ;
V_53 += 2 ;
}
if ( V_25 == 8 )
return V_84 ;
}
V_21 += V_25 ;
} else {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
if ( ! F_36 ( V_53 , V_66 | V_68 |
V_67 ) ) {
T_4 V_63 ;
while ( ! F_36 ( V_53 , V_66 ) )
F_37 () ;
V_63 = F_35 ( * V_53 ) ;
if ( V_63 & ( V_68 | V_67 ) ) {
* V_53 &= ~ F_22 ( V_66 ) ;
return V_84 ;
}
}
}
V_19 = & V_7 -> V_10 . V_28 [ V_21 ] ;
if ( V_22 )
V_19 = F_1 ( V_19 ) ;
if ( V_19 ) {
V_19 -> V_42 = V_60 ;
F_38 ( V_7 , V_19 ) ;
}
if ( V_54 & V_68 ) {
if ( V_22 )
V_20 = F_1 ( V_20 ) ;
F_17 ( V_20 ) ;
if ( F_39 ( V_7 , V_64 ) ) {
V_54 |= V_67 ;
V_54 &= ~ V_68 ;
F_11 ( V_20 ) ;
} else {
F_10 ( V_7 , V_19 , V_20 , V_21 ,
V_22 ) ;
V_39 = * V_20 >> V_44 ;
V_36 &= V_39 | ~ ( V_40 | V_41 ) ;
}
}
V_53 [ 1 ] = F_22 ( V_36 ) ;
F_40 () ;
V_53 [ 0 ] = F_22 ( V_54 ) ;
asm volatile("ptesync" : : : "memory");
* V_55 = V_21 ;
return V_85 ;
}
long F_41 ( struct V_14 * V_86 , unsigned long V_8 ,
long V_21 , unsigned long V_54 , unsigned long V_36 )
{
return F_23 ( V_86 -> V_7 , V_8 , V_21 , V_54 , V_36 ,
V_86 -> V_10 . V_45 , true , & V_86 -> V_10 . V_87 [ 4 ] ) ;
}
static inline int F_42 ( unsigned int * V_88 )
{
unsigned int V_89 , V_90 ;
unsigned int V_91 = V_92 ;
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
return V_90 == 0 ;
}
static void F_43 ( struct V_7 * V_7 , unsigned long * V_93 ,
long V_94 , int V_9 , bool V_95 )
{
long V_25 ;
if ( V_9 ) {
while ( ! F_42 ( & V_7 -> V_10 . V_96 ) )
F_37 () ;
if ( V_95 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_94 ; ++ V_25 )
asm volatile(PPC_TLBIE(%1,%0) : :
"r" (rbvalues[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_7 -> V_10 . V_96 = 0 ;
} else {
if ( V_95 )
asm volatile("ptesync" : : : "memory");
for ( V_25 = 0 ; V_25 < V_94 ; ++ V_25 )
asm volatile("tlbiel %0" : : "r" (rbvalues[i]));
asm volatile("ptesync" : : : "memory");
}
}
long F_44 ( struct V_7 * V_7 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_97 ,
unsigned long * V_98 )
{
T_3 * V_53 ;
unsigned long V_99 , V_100 , V_101 ;
struct V_18 * V_19 ;
T_4 V_63 ;
if ( V_21 >= V_7 -> V_10 . V_81 )
return V_65 ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
while ( ! F_36 ( V_53 , V_66 ) )
F_37 () ;
V_63 = F_35 ( V_53 [ 0 ] ) ;
if ( ( V_63 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_102 ) && ( V_63 & ~ 0x7fUL ) != V_97 ) ||
( ( V_8 & V_103 ) && ( V_63 & V_97 ) != 0 ) ) {
V_53 [ 0 ] &= ~ F_22 ( V_66 ) ;
return V_104 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
V_99 = V_63 & ~ V_66 ;
if ( V_99 & V_68 ) {
T_4 V_105 ;
V_105 = F_35 ( V_53 [ 1 ] ) ;
V_53 [ 0 ] &= ~ F_22 ( V_68 ) ;
V_101 = F_45 ( V_99 , V_105 , V_21 ) ;
F_43 ( V_7 , & V_101 , 1 , F_6 ( V_7 , V_8 ) , true ) ;
F_12 ( V_7 , V_21 , V_19 , V_99 , V_105 ) ;
}
V_100 = V_19 -> V_42 & ~ V_69 ;
F_38 ( V_7 , V_19 ) ;
F_21 ( V_53 , 0 ) ;
V_98 [ 0 ] = V_99 ;
V_98 [ 1 ] = V_100 ;
return V_85 ;
}
long F_46 ( struct V_14 * V_86 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_97 )
{
return F_44 ( V_86 -> V_7 , V_8 , V_21 , V_97 ,
& V_86 -> V_10 . V_87 [ 4 ] ) ;
}
long F_47 ( struct V_14 * V_86 )
{
struct V_7 * V_7 = V_86 -> V_7 ;
unsigned long * args = & V_86 -> V_10 . V_87 [ 4 ] ;
T_3 * V_106 , * V_107 [ 4 ] ;
unsigned long V_108 [ 4 ] ;
long int V_25 , V_109 , V_110 , V_111 , V_112 , V_113 [ 4 ] ;
unsigned long V_8 , V_114 , V_21 , V_39 ;
int V_9 ;
long int V_115 = V_85 ;
struct V_18 * V_19 , * V_116 [ 4 ] ;
T_4 V_117 ;
V_9 = F_6 ( V_7 , 0 ) ;
for ( V_25 = 0 ; V_25 < 4 && V_115 == V_85 ; ) {
V_111 = 0 ;
for (; V_25 < 4 ; ++ V_25 ) {
V_109 = V_25 * 2 ;
V_21 = args [ V_109 ] ;
V_8 = V_21 >> 56 ;
V_21 &= ( ( 1ul << 56 ) - 1 ) ;
V_114 = V_8 >> 6 ;
V_8 &= 3 ;
if ( V_114 == 3 ) {
V_25 = 4 ;
break;
}
if ( V_114 != 1 || V_8 == 3 ||
V_21 >= V_7 -> V_10 . V_81 ) {
args [ V_109 ] = ( ( 0xa0 | V_8 ) << 56 ) + V_21 ;
V_115 = V_65 ;
break;
}
V_106 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
if ( ! F_36 ( V_106 , V_66 ) ) {
if ( V_111 )
break;
while ( ! F_36 ( V_106 , V_66 ) )
F_37 () ;
}
V_112 = 0 ;
V_117 = F_35 ( V_106 [ 0 ] ) ;
if ( V_117 & ( V_67 | V_68 ) ) {
switch ( V_8 & 3 ) {
case 0 :
V_112 = 1 ;
break;
case 1 :
if ( ! ( V_117 & args [ V_109 + 1 ] ) )
V_112 = 1 ;
break;
case 2 :
if ( ( V_117 & ~ 0x7fUL ) == args [ V_109 + 1 ] )
V_112 = 1 ;
break;
}
}
if ( ! V_112 ) {
V_106 [ 0 ] &= ~ F_22 ( V_66 ) ;
args [ V_109 ] = ( ( 0x90 | V_8 ) << 56 ) + V_21 ;
continue;
}
args [ V_109 ] = ( ( 0x80 | V_8 ) << 56 ) + V_21 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
F_38 ( V_7 , V_19 ) ;
if ( ! ( V_117 & V_68 ) ) {
V_39 = V_19 -> V_42 & ( V_40 | V_41 ) ;
args [ V_109 ] |= V_39 << ( 56 - 5 ) ;
V_106 [ 0 ] = 0 ;
continue;
}
V_106 [ 0 ] &= ~ F_22 ( V_68 ) ;
V_108 [ V_111 ] = F_45 ( F_35 ( V_106 [ 0 ] ) ,
F_35 ( V_106 [ 1 ] ) , V_21 ) ;
V_113 [ V_111 ] = V_109 ;
V_107 [ V_111 ] = V_106 ;
V_116 [ V_111 ] = V_19 ;
++ V_111 ;
}
if ( ! V_111 )
break;
F_43 ( V_7 , V_108 , V_111 , V_9 , true ) ;
for ( V_110 = 0 ; V_110 < V_111 ; ++ V_110 ) {
V_109 = V_113 [ V_110 ] ;
V_21 = args [ V_109 ] & ( ( 1ul << 56 ) - 1 ) ;
V_106 = V_107 [ V_110 ] ;
V_19 = V_116 [ V_110 ] ;
F_12 ( V_7 , V_21 , V_19 ,
F_35 ( V_106 [ 0 ] ) , F_35 ( V_106 [ 1 ] ) ) ;
V_39 = V_19 -> V_42 & ( V_40 | V_41 ) ;
args [ V_109 ] |= V_39 << ( 56 - 5 ) ;
V_106 [ 0 ] = 0 ;
}
}
return V_115 ;
}
long F_48 ( struct V_14 * V_86 , unsigned long V_8 ,
unsigned long V_21 , unsigned long V_97 ,
unsigned long V_118 )
{
struct V_7 * V_7 = V_86 -> V_7 ;
T_3 * V_53 ;
struct V_18 * V_19 ;
unsigned long V_99 , V_100 , V_101 , V_119 , V_120 ;
T_4 V_63 ;
if ( V_21 >= V_7 -> V_10 . V_81 )
return V_65 ;
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
while ( ! F_36 ( V_53 , V_66 ) )
F_37 () ;
V_63 = F_35 ( V_53 [ 0 ] ) ;
if ( ( V_63 & ( V_67 | V_68 ) ) == 0 ||
( ( V_8 & V_102 ) && ( V_63 & ~ 0x7fUL ) != V_97 ) ) {
V_53 [ 0 ] &= ~ F_22 ( V_66 ) ;
return V_104 ;
}
V_99 = V_63 ;
V_120 = ( V_8 << 55 ) & V_76 ;
V_120 |= ( V_8 << 48 ) & V_73 ;
V_120 |= V_8 & ( V_121 | V_122 | V_74 ) ;
V_119 = V_76 | V_121 | V_122 |
V_73 | V_74 ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
if ( V_19 ) {
V_100 = ( V_19 -> V_42 & ~ V_119 ) | V_120 ;
V_19 -> V_42 = V_100 ;
F_38 ( V_7 , V_19 ) ;
}
if ( V_99 & V_68 ) {
V_63 = F_35 ( V_53 [ 1 ] ) ;
V_100 = ( V_63 & ~ V_119 ) | V_120 ;
if ( F_24 ( V_100 ) && ! F_24 ( V_63 ) )
V_100 = F_30 ( V_100 ) ;
if ( V_100 != V_63 ) {
V_101 = F_45 ( V_99 , V_100 , V_21 ) ;
V_53 [ 0 ] = F_22 ( ( V_99 & ~ V_68 ) |
V_67 ) ;
F_43 ( V_7 , & V_101 , 1 , F_6 ( V_7 , V_8 ) ,
true ) ;
V_53 [ 1 ] = F_22 ( V_100 ) ;
}
}
F_21 ( V_53 , V_99 & ~ V_66 ) ;
asm volatile("ptesync" : : : "memory");
return V_85 ;
}
long F_49 ( struct V_14 * V_86 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_7 * V_7 = V_86 -> V_7 ;
T_3 * V_53 ;
unsigned long V_99 , V_100 ;
int V_25 , V_111 = 1 ;
struct V_18 * V_19 = NULL ;
if ( V_21 >= V_7 -> V_10 . V_81 )
return V_65 ;
if ( V_8 & V_123 ) {
V_21 &= ~ 3 ;
V_111 = 4 ;
}
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_21 ] ) ;
for ( V_25 = 0 ; V_25 < V_111 ; ++ V_25 , ++ V_21 ) {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_21 << 4 ) ) ;
V_99 = F_35 ( V_53 [ 0 ] ) & ~ V_66 ;
V_100 = F_35 ( V_53 [ 1 ] ) ;
if ( V_99 & V_67 ) {
V_99 &= ~ V_67 ;
V_99 |= V_68 ;
}
if ( V_99 & V_68 ) {
V_100 = V_19 [ V_25 ] . V_42 | ( V_100 & ( V_40 | V_41 ) ) ;
V_100 &= ~ V_69 ;
}
V_86 -> V_10 . V_87 [ 4 + V_25 * 2 ] = V_99 ;
V_86 -> V_10 . V_87 [ 5 + V_25 * 2 ] = V_100 ;
}
return V_85 ;
}
void F_50 ( struct V_7 * V_7 , T_3 * V_124 ,
unsigned long V_21 )
{
unsigned long V_101 ;
V_124 [ 0 ] &= ~ F_22 ( V_68 ) ;
V_101 = F_45 ( F_35 ( V_124 [ 0 ] ) , F_35 ( V_124 [ 1 ] ) ,
V_21 ) ;
F_43 ( V_7 , & V_101 , 1 , 1 , true ) ;
}
void F_51 ( struct V_7 * V_7 , T_3 * V_124 ,
unsigned long V_21 )
{
unsigned long V_101 ;
unsigned char V_125 ;
V_101 = F_45 ( F_35 ( V_124 [ 0 ] ) , F_35 ( V_124 [ 1 ] ) ,
V_21 ) ;
V_125 = ( F_35 ( V_124 [ 1 ] ) & ~ V_40 ) >> 8 ;
* ( ( char * ) V_124 + 14 ) = V_125 ;
F_43 ( V_7 , & V_101 , 1 , 1 , false ) ;
}
long F_52 ( struct V_7 * V_7 , T_5 V_126 , unsigned long V_127 ,
unsigned long V_128 )
{
unsigned int V_25 ;
unsigned int V_129 ;
unsigned long V_130 ;
unsigned long V_131 , V_132 ;
unsigned long V_97 ;
T_3 * V_53 ;
unsigned long V_119 , V_133 ;
unsigned long V_99 , V_100 ;
V_119 = V_134 | V_135 | V_136 ;
V_133 = 0 ;
V_129 = 12 ;
if ( V_127 & V_137 ) {
V_119 |= V_138 ;
V_133 |= V_138 ;
V_129 = V_139 [ ( V_127 & V_140 ) >> 4 ] ;
}
if ( V_127 & V_141 ) {
V_130 = ( 1UL << 40 ) - 1 ;
V_131 = ( V_127 & ~ V_134 ) >> V_142 ;
V_131 ^= V_131 << 25 ;
} else {
V_130 = ( 1UL << 28 ) - 1 ;
V_131 = ( V_127 & ~ V_134 ) >> V_143 ;
}
V_132 = ( V_131 ^ ( ( V_126 & V_130 ) >> V_129 ) ) & V_7 -> V_10 . V_144 ;
V_97 = V_127 & ~ ( V_130 >> 16 ) ;
V_97 |= ( V_126 & V_130 ) >> 16 ;
if ( V_129 >= 24 )
V_97 &= ~ ( ( 1UL << ( V_129 - 16 ) ) - 1 ) ;
else
V_97 &= ~ 0x7fUL ;
V_133 |= V_97 ;
for (; ; ) {
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_132 << 7 ) ) ;
for ( V_25 = 0 ; V_25 < 16 ; V_25 += 2 ) {
V_99 = F_35 ( V_53 [ V_25 ] ) & ~ V_66 ;
if ( ! ( V_99 & V_128 ) || ( V_99 & V_119 ) != V_133 )
continue;
while ( ! F_36 ( & V_53 [ V_25 ] , V_66 ) )
F_37 () ;
V_99 = F_35 ( V_53 [ V_25 ] ) & ~ V_66 ;
V_100 = F_35 ( V_53 [ V_25 + 1 ] ) ;
if ( ( V_99 & V_128 ) && ( V_99 & V_119 ) == V_133 &&
F_53 ( V_99 , V_100 ) == ( 1ul << V_129 ) )
return ( V_132 << 3 ) + ( V_25 >> 1 ) ;
V_53 [ V_25 ] = F_22 ( V_99 ) ;
}
if ( V_133 & V_136 )
break;
V_133 |= V_136 ;
V_132 = V_132 ^ V_7 -> V_10 . V_144 ;
}
return - 1 ;
}
long F_54 ( struct V_14 * V_86 , unsigned long V_2 ,
unsigned long V_127 , unsigned int V_145 , bool V_146 )
{
struct V_7 * V_7 = V_86 -> V_7 ;
long int V_147 ;
unsigned long V_99 , V_100 , V_148 ;
T_3 * V_53 ;
unsigned long V_128 ;
struct V_18 * V_19 ;
unsigned long V_149 , V_150 ;
V_128 = V_68 ;
if ( V_145 & V_151 )
V_128 |= V_67 ;
V_147 = F_52 ( V_7 , V_2 , V_127 , V_128 ) ;
if ( V_147 < 0 ) {
if ( V_145 & V_151 )
return V_145 ;
return 0 ;
}
V_53 = ( T_3 * ) ( V_7 -> V_10 . V_83 + ( V_147 << 4 ) ) ;
V_99 = F_35 ( V_53 [ 0 ] ) & ~ V_66 ;
V_100 = F_35 ( V_53 [ 1 ] ) ;
V_19 = F_1 ( & V_7 -> V_10 . V_28 [ V_147 ] ) ;
V_148 = V_19 -> V_42 ;
F_21 ( V_53 , V_99 ) ;
if ( ( V_145 & V_151 ) && ( V_99 & V_68 ) )
return 0 ;
V_149 = V_148 & ( V_76 | V_121 ) ;
V_150 = ( V_86 -> V_10 . V_152 . V_153 & V_154 ) ? V_155 : V_156 ;
V_145 &= ~ V_151 ;
if ( ! V_146 ) {
if ( V_148 & ( V_122 | V_79 ) )
return V_145 | V_157 ;
if ( ! F_55 ( V_149 , V_127 & V_150 ) )
return V_145 | V_158 ;
} else if ( V_145 & V_159 ) {
if ( ! F_56 ( V_149 , V_127 & V_150 ) )
return V_145 | V_160 ;
} else {
if ( ! F_55 ( V_149 , V_127 & V_150 ) )
return V_145 | V_160 ;
}
if ( V_146 && ( V_86 -> V_10 . V_152 . V_153 & V_161 ) ) {
unsigned int V_162 = F_57 ( V_148 , V_86 -> V_10 . V_163 ) ;
if ( V_145 & V_159 )
V_162 >>= 1 ;
if ( V_162 & 1 )
return V_145 | V_164 ;
}
V_86 -> V_10 . V_165 = V_2 ;
V_86 -> V_10 . V_166 = V_147 ;
V_86 -> V_10 . V_167 [ 0 ] = V_99 ;
V_86 -> V_10 . V_167 [ 1 ] = V_100 ;
if ( V_146 && ( V_86 -> V_10 . V_152 . V_153 & V_168 ) &&
( V_100 & ( V_73 | V_74 ) ) ==
( V_73 | V_74 ) )
return - 2 ;
return - 1 ;
}
