static inline long F_1 ( unsigned long * V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
asm volatile(" ldarx %0,0,%2\n"
" and. %1,%0,%3\n"
" bne 2f\n"
" ori %0,%0,%4\n"
" stdcx. %0,0,%2\n"
" beq+ 2f\n"
" li %1,%3\n"
"2: isync"
: "=&r" (tmp), "=&r" (old)
: "r" (hpte), "r" (bits), "i" (HPTE_V_HVLOCK)
: "cc", "memory");
return V_4 == 0 ;
}
long F_2 ( struct V_5 * V_6 , unsigned long V_7 ,
long V_8 , unsigned long V_9 , unsigned long V_10 )
{
unsigned long V_11 ;
struct V_12 * V_12 = V_6 -> V_12 ;
unsigned long V_13 , V_14 , V_15 ;
unsigned long * V_1 ;
V_11 = 12 ;
if ( V_9 & V_16 ) {
if ( F_3 ( V_17 ) &&
( V_10 & 0xf000 ) == 0x1000 ) {
V_11 = 16 ;
} else if ( ( V_10 & 0xff000 ) == 0 ) {
V_11 = 24 ;
if ( V_9 & 0x80 )
return V_18 ;
} else
return V_18 ;
}
V_14 = ( V_10 & V_19 ) >> V_12 -> V_20 . V_21 ;
if ( V_14 >= V_12 -> V_20 . V_22 || V_11 > V_12 -> V_20 . V_21 )
return V_18 ;
V_15 = V_12 -> V_20 . V_23 [ V_14 ] . V_24 << V_25 ;
if ( ! V_15 )
return V_18 ;
if ( ( V_10 & V_26 ) != V_27 &&
( V_10 & V_26 ) != ( V_28 | V_29 | V_27 ) )
return V_18 ;
V_9 &= ~ 0x60UL ;
V_10 &= ~ ( V_30 - V_12 -> V_20 . V_31 ) ;
V_10 |= V_15 ;
if ( V_8 >= ( V_32 << 3 ) )
return V_18 ;
if ( F_4 ( ( V_7 & V_33 ) == 0 ) ) {
V_8 &= ~ 7UL ;
V_1 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
for ( V_13 = 0 ; ; ++ V_13 ) {
if ( V_13 == 8 )
return V_35 ;
if ( ( * V_1 & V_36 ) == 0 &&
F_1 ( V_1 , V_37 | V_36 ) )
break;
V_1 += 2 ;
}
} else {
V_13 = 0 ;
V_1 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
if ( ! F_1 ( V_1 , V_37 | V_36 ) )
return V_35 ;
}
V_1 [ 1 ] = V_10 ;
F_5 () ;
V_1 [ 0 ] = V_9 ;
asm volatile("ptesync" : : : "memory");
F_6 ( & V_12 -> V_20 . V_23 [ V_14 ] . V_38 ) ;
V_6 -> V_20 . V_39 [ 4 ] = V_8 + V_13 ;
return V_40 ;
}
static unsigned long F_7 ( unsigned long V_41 , unsigned long V_42 ,
unsigned long V_8 )
{
unsigned long V_43 , V_44 ;
V_43 = ( V_41 & ~ 0x7fUL ) << 16 ;
V_44 = V_8 >> 3 ;
if ( V_41 & V_45 )
V_44 = ~ V_44 ;
if ( ! ( V_41 & V_46 ) )
V_44 ^= V_41 >> 12 ;
else
V_44 ^= V_41 >> 24 ;
V_44 &= 0x7ff ;
if ( V_41 & V_16 ) {
V_43 |= 1 ;
if ( F_3 ( V_17 ) &&
( V_42 & 0xff000 ) ) {
V_43 |= 0x1000 ;
V_43 |= ( V_44 & 0x7f ) << 16 ;
V_43 |= ( V_44 & 0xfe ) ;
}
} else {
V_43 |= ( V_44 & 0x7ff ) << 12 ;
}
V_43 |= ( V_41 >> 54 ) & 0x300 ;
return V_43 ;
}
static inline int F_8 ( unsigned int * V_47 )
{
unsigned int V_3 , V_4 ;
unsigned int V_48 = V_49 ;
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
return V_4 == 0 ;
}
long F_9 ( struct V_5 * V_6 , unsigned long V_7 ,
unsigned long V_8 , unsigned long V_50 ,
unsigned long V_51 )
{
struct V_12 * V_12 = V_6 -> V_12 ;
unsigned long * V_1 ;
unsigned long V_41 , V_42 , V_43 ;
if ( V_8 >= ( V_32 << 3 ) )
return V_18 ;
V_1 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
while ( ! F_1 ( V_1 , V_37 ) )
F_10 () ;
if ( ( V_1 [ 0 ] & V_36 ) == 0 ||
( ( V_7 & V_52 ) && ( V_1 [ 0 ] & ~ 0x7fUL ) != V_50 ) ||
( ( V_7 & V_53 ) && ( V_1 [ 0 ] & V_50 ) != 0 ) ) {
V_1 [ 0 ] &= ~ V_37 ;
return V_54 ;
}
if ( F_11 ( & V_12 -> V_55 ) == 1 )
V_7 |= V_56 ;
V_6 -> V_20 . V_39 [ 4 ] = V_41 = V_1 [ 0 ] & ~ V_37 ;
V_6 -> V_20 . V_39 [ 5 ] = V_42 = V_1 [ 1 ] ;
V_43 = F_7 ( V_41 , V_42 , V_8 ) ;
V_1 [ 0 ] = 0 ;
if ( ! ( V_7 & V_56 ) ) {
while( ! F_8 ( & V_12 -> V_20 . V_57 ) )
F_10 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_12 -> V_20 . V_57 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
return V_40 ;
}
long F_12 ( struct V_5 * V_6 )
{
struct V_12 * V_12 = V_6 -> V_12 ;
unsigned long * args = & V_6 -> V_20 . V_39 [ 4 ] ;
unsigned long * V_58 , V_59 [ 4 ] ;
long int V_13 , V_60 ;
long int V_61 = 0 ;
unsigned long V_7 , V_62 , V_8 ;
long int V_63 = 0 ;
long int V_64 = V_40 ;
if ( F_11 ( & V_12 -> V_55 ) == 1 )
V_63 = 1 ;
for ( V_13 = 0 ; V_13 < 4 ; ++ V_13 ) {
V_8 = args [ V_13 * 2 ] ;
V_7 = V_8 >> 56 ;
V_8 &= ( ( 1ul << 56 ) - 1 ) ;
V_62 = V_7 >> 6 ;
V_7 &= 3 ;
if ( V_62 == 3 )
break;
if ( V_62 != 1 || V_7 == 3 ||
V_8 >= ( V_32 << 3 ) ) {
args [ V_13 * 2 ] = ( ( 0xa0 | V_7 ) << 56 ) + V_8 ;
V_64 = V_18 ;
break;
}
V_58 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
while ( ! F_1 ( V_58 , V_37 ) )
F_10 () ;
V_60 = 0 ;
if ( V_58 [ 0 ] & V_36 ) {
switch ( V_7 & 3 ) {
case 0 :
V_60 = 1 ;
break;
case 1 :
if ( ! ( V_58 [ 0 ] & args [ V_13 * 2 + 1 ] ) )
V_60 = 1 ;
break;
case 2 :
if ( ( V_58 [ 0 ] & ~ 0x7fUL ) == args [ V_13 * 2 + 1 ] )
V_60 = 1 ;
break;
}
}
if ( ! V_60 ) {
V_58 [ 0 ] &= ~ V_37 ;
args [ V_13 * 2 ] = ( ( 0x90 | V_7 ) << 56 ) + V_8 ;
continue;
}
V_7 |= ( V_58 [ 1 ] >> 5 ) & 0x0c ;
args [ V_13 * 2 ] = ( ( 0x80 | V_7 ) << 56 ) + V_8 ;
V_59 [ V_61 ++ ] = F_7 ( V_58 [ 0 ] , V_58 [ 1 ] , V_8 ) ;
V_58 [ 0 ] = 0 ;
}
if ( V_61 == 0 )
return V_64 ;
if ( ! V_63 ) {
while( ! F_8 ( & V_12 -> V_20 . V_57 ) )
F_10 () ;
asm volatile("ptesync" : : : "memory");
for ( V_13 = 0 ; V_13 < V_61 ; ++ V_13 )
asm volatile(PPC_TLBIE(%1,%0)
: : "r" (tlbrb[i]), "r" (kvm->arch.lpid));
asm volatile("eieio; tlbsync; ptesync" : : : "memory");
V_12 -> V_20 . V_57 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
for ( V_13 = 0 ; V_13 < V_61 ; ++ V_13 )
asm volatile("tlbiel %0" : : "r" (tlbrb[i]));
asm volatile("ptesync" : : : "memory");
}
return V_64 ;
}
long F_13 ( struct V_5 * V_6 , unsigned long V_7 ,
unsigned long V_8 , unsigned long V_50 ,
unsigned long V_51 )
{
struct V_12 * V_12 = V_6 -> V_12 ;
unsigned long * V_1 ;
unsigned long V_41 , V_42 , V_43 ;
if ( V_8 >= ( V_32 << 3 ) )
return V_18 ;
V_1 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
while ( ! F_1 ( V_1 , V_37 ) )
F_10 () ;
if ( ( V_1 [ 0 ] & V_36 ) == 0 ||
( ( V_7 & V_52 ) && ( V_1 [ 0 ] & ~ 0x7fUL ) != V_50 ) ) {
V_1 [ 0 ] &= ~ V_37 ;
return V_54 ;
}
if ( F_11 ( & V_12 -> V_55 ) == 1 )
V_7 |= V_56 ;
V_41 = V_1 [ 0 ] ;
V_42 = V_1 [ 1 ] & ~ ( V_30 | V_65 | V_66 |
V_67 | V_68 ) ;
V_42 |= ( V_7 << 55 ) & V_30 ;
V_42 |= ( V_7 << 48 ) & V_67 ;
V_42 |= V_7 & ( V_65 | V_66 | V_68 ) ;
V_43 = F_7 ( V_41 , V_42 , V_8 ) ;
V_1 [ 0 ] = V_41 & ~ V_36 ;
if ( ! ( V_7 & V_56 ) ) {
while( ! F_8 ( & V_12 -> V_20 . V_57 ) )
F_10 () ;
asm volatile("ptesync" : : : "memory");
asm volatile(PPC_TLBIE(%1,%0)"; eieio; tlbsync"
: : "r" (rb), "r" (kvm->arch.lpid));
asm volatile("ptesync" : : : "memory");
V_12 -> V_20 . V_57 = 0 ;
} else {
asm volatile("ptesync" : : : "memory");
asm volatile("tlbiel %0" : : "r" (rb));
asm volatile("ptesync" : : : "memory");
}
V_1 [ 1 ] = V_42 ;
F_5 () ;
V_1 [ 0 ] = V_41 & ~ V_37 ;
asm volatile("ptesync" : : : "memory");
return V_40 ;
}
static unsigned long F_14 ( struct V_12 * V_12 , unsigned long V_69 )
{
long int V_13 ;
unsigned long V_70 , V_71 ;
V_70 = V_69 & ( V_12 -> V_20 . V_31 - 1 ) ;
V_71 = ( V_69 - V_70 ) >> V_25 ;
for ( V_13 = 0 ; V_13 < V_12 -> V_20 . V_22 ; ++ V_13 )
if ( V_71 == V_12 -> V_20 . V_23 [ V_13 ] . V_24 )
return ( V_13 << V_25 ) + V_70 ;
return V_19 ;
}
long F_15 ( struct V_5 * V_6 , unsigned long V_7 ,
unsigned long V_8 )
{
struct V_12 * V_12 = V_6 -> V_12 ;
unsigned long * V_1 , V_42 ;
int V_13 , V_72 = 1 ;
if ( V_8 >= ( V_32 << 3 ) )
return V_18 ;
if ( V_7 & V_73 ) {
V_8 &= ~ 3 ;
V_72 = 4 ;
}
for ( V_13 = 0 ; V_13 < V_72 ; ++ V_13 , ++ V_8 ) {
V_1 = ( unsigned long * ) ( V_12 -> V_20 . V_34 + ( V_8 << 4 ) ) ;
V_42 = V_1 [ 1 ] ;
if ( ( V_7 & V_74 ) && ( V_1 [ 0 ] & V_36 ) )
V_42 = F_14 ( V_12 , V_42 & V_19 ) |
( V_42 & ~ V_19 ) ;
V_6 -> V_20 . V_39 [ 4 + V_13 * 2 ] = V_1 [ 0 ] ;
V_6 -> V_20 . V_39 [ 5 + V_13 * 2 ] = V_42 ;
}
return V_40 ;
}
