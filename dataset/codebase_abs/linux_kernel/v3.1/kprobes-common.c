void T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
__asm__ (
"sub %[ret], pc, #4 \n\t"
"str pc, %[addr] \n\t"
"ldr %[scr], %[addr] \n\t"
"sub %[ret], %[scr], %[ret] \n\t"
: [ret] "=r" (ret), [scr] "=r" (scratch), [addr] "+m" (addr));
V_4 = V_3 ;
}
void T_1 F_2 ( void )
{
int V_5 = F_3 () ;
F_4 ( V_5 == V_6 ) ;
V_7 = V_5 >= V_8 ;
}
void T_1 F_5 ( void )
{
int V_5 = F_3 () ;
F_4 ( V_5 == V_6 ) ;
V_9 = V_5 >= V_10 ;
}
void T_1 F_6 ( void )
{
F_1 () ;
F_2 () ;
F_5 () ;
}
static unsigned long T_2 F_7 ( unsigned long V_11 )
{
return V_11 & V_12 ;
}
static unsigned long T_2 F_8 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_12 ;
}
static unsigned long T_2 F_9 ( unsigned long V_11 )
{
return V_11 & V_13 ;
}
static unsigned long T_2 F_10 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_13 ;
}
static unsigned long T_2 F_11 ( unsigned long V_11 )
{
return V_11 & V_14 ;
}
static unsigned long T_2 F_12 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_14 ;
}
static unsigned long T_2 F_13 ( unsigned long V_11 )
{
return V_11 & V_15 ;
}
static unsigned long T_2 F_14 ( unsigned long V_11 )
{
return ( ~ V_11 ) & V_15 ;
}
static unsigned long T_2 F_15 ( unsigned long V_11 )
{
V_11 &= ~ ( V_11 >> 1 ) ;
return V_11 & V_13 ;
}
static unsigned long T_2 F_16 ( unsigned long V_11 )
{
V_11 &= ~ ( V_11 >> 1 ) ;
return ( ~ V_11 ) & V_13 ;
}
static unsigned long T_2 F_17 ( unsigned long V_11 )
{
V_11 ^= ( V_11 << 3 ) ;
return ( ~ V_11 ) & V_14 ;
}
static unsigned long T_2 F_18 ( unsigned long V_11 )
{
V_11 ^= ( V_11 << 3 ) ;
return V_11 & V_14 ;
}
static unsigned long T_2 F_19 ( unsigned long V_11 )
{
unsigned long V_16 = V_11 ^ ( V_11 << 3 ) ;
V_16 |= ( V_11 << 1 ) ;
return ( ~ V_16 ) & V_14 ;
}
static unsigned long T_2 F_20 ( unsigned long V_11 )
{
unsigned long V_16 = V_11 ^ ( V_11 << 3 ) ;
V_16 |= ( V_11 << 1 ) ;
return V_16 & V_14 ;
}
static unsigned long T_2 F_21 ( unsigned long V_11 )
{
return true ;
}
void T_2 F_22 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
}
void T_2 F_23 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
V_18 -> V_21 . V_22 () ;
}
static void T_2 F_24 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
T_3 V_23 = V_18 -> V_24 ;
int V_25 = ( V_23 >> 16 ) & 0xf ;
int V_26 = V_23 & ( 1 << 20 ) ;
int V_27 = V_23 & ( 1 << 21 ) ;
int V_28 = V_23 & ( 1 << 23 ) ;
int V_29 = V_23 & ( 1 << 24 ) ;
long * V_1 = ( long * ) V_20 -> V_30 [ V_25 ] ;
int V_31 ;
int V_32 ;
V_32 = 0 ;
V_31 = V_23 & 0xffff ;
while ( V_31 ) {
V_31 &= ( V_31 - 1 ) ;
++ V_32 ;
}
if ( ! V_28 )
V_1 -= V_32 ;
V_1 += ( ! V_29 == ! V_28 ) ;
V_31 = V_23 & 0xffff ;
while ( V_31 ) {
int V_33 = F_25 ( V_31 ) ;
V_31 &= ( V_31 - 1 ) ;
if ( V_26 )
V_20 -> V_30 [ V_33 ] = * V_1 ++ ;
else
* V_1 ++ = V_20 -> V_30 [ V_33 ] ;
}
if ( V_27 ) {
if ( ! V_28 )
V_1 -= V_32 ;
V_1 -= ( ! V_29 == ! V_28 ) ;
V_20 -> V_30 [ V_25 ] = ( long ) V_1 ;
}
}
static void T_2 F_26 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
V_20 -> V_34 = ( long ) V_18 -> V_1 + V_4 ;
F_24 ( V_18 , V_20 ) ;
V_20 -> V_34 = ( long ) V_18 -> V_1 + 4 ;
}
static void T_2 F_27 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
F_24 ( V_18 , V_20 ) ;
F_28 ( V_20 -> V_34 , V_20 ) ;
}
static void T_2
F_29 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
register void * T_4 V_35 ( L_1 ) = V_20 ;
register void * T_5 V_35 ( L_2 ) = V_18 -> V_21 . V_22 ;
__asm__ __volatile__ (
"stmdb sp!, {%[regs], r11} \n\t"
"ldmia %[regs], {r0-r12} \n\t"
#if V_36 >= 6
"blx %[fn] \n\t"
#else
"str %[fn], [sp, #-4]! \n\t"
"adr lr, 1f \n\t"
"ldr pc, [sp], #4 \n\t"
"1: \n\t"
#endif
"ldr lr, [sp], #4 \n\t"
"stmia lr, {r0-r12} \n\t"
"ldr r11, [sp], #4 \n\t"
: [regs] "=r" (rregs), [fn] "=r" (rfn)
: "0" (rregs), "1" (rfn)
: "r0", "r2", "r3", "r4", "r5", "r6", "r7",
"r8", "r9", "r10", "r12", "memory", "cc"
);
}
static void T_2
F_30 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
F_29 ( V_18 , (struct V_19 * ) ( V_20 -> V_30 + 2 ) ) ;
}
static void T_2
F_31 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
F_29 ( V_18 , (struct V_19 * ) ( V_20 -> V_30 + 3 ) ) ;
F_28 ( V_20 -> V_34 , V_20 ) ;
}
enum V_37 T_2
F_32 ( T_3 V_23 , struct V_38 * V_39 )
{
T_6 * V_40 = 0 ;
unsigned V_41 = V_23 & 0xffff ;
int V_42 = V_23 & 0x100000 ;
int V_25 = ( V_23 >> 16 ) & 0xf ;
if ( V_25 <= 12 && ( V_41 & 0xe000 ) == 0 ) {
V_40 = F_29 ;
} else if ( V_25 >= 2 && ( V_41 & 0x8003 ) == 0 ) {
V_25 -= 2 ;
V_41 >>= 2 ;
V_40 = F_30 ;
} else if ( V_25 >= 3 && ( V_41 & 0x0007 ) == 0 ) {
if ( V_42 && ( V_41 & 0x8000 ) ) {
V_25 -= 3 ;
V_41 >>= 3 ;
V_40 = F_31 ;
}
}
if ( V_40 ) {
V_39 -> V_23 [ 0 ] = ( V_23 & 0xfff00000 ) | ( V_25 << 16 ) | V_41 ;
V_39 -> V_43 = V_40 ;
return V_44 ;
}
if ( V_41 & 0x8000 )
V_40 = V_42 ? F_27 : F_26 ;
else
V_40 = F_24 ;
V_39 -> V_43 = V_40 ;
return V_45 ;
}
static T_3 T_2
F_33 ( T_3 V_23 , struct V_38 * V_39 ,
bool V_46 )
{
#ifdef F_34
if ( V_46 ) {
T_7 * V_47 = ( T_7 * ) V_39 -> V_23 ;
V_47 [ 1 ] = 0x4770 ;
V_47 [ 2 ] = 0x4770 ;
return V_23 ;
}
V_39 -> V_23 [ 1 ] = 0xe12fff1e ;
#else
V_39 -> V_23 [ 1 ] = 0xe1a0f00e ;
#endif
if ( V_23 < 0xe0000000 )
V_23 = ( V_23 | 0xe0000000 ) & ~ 0x10000000 ;
return V_23 ;
}
static void T_2
F_35 ( T_3 V_23 , struct V_38 * V_39 ,
bool V_46 )
{
#ifdef F_34
if ( V_46 ) {
T_7 * V_48 = ( T_7 * ) V_39 -> V_23 ;
if ( F_36 ( V_23 ) )
* V_48 ++ = V_23 >> 16 ;
* V_48 ++ = V_23 ;
return;
}
#endif
V_39 -> V_23 [ 0 ] = V_23 ;
}
static bool T_2 F_37 ( T_3 * V_49 , T_8 V_20 )
{
T_3 V_23 = * V_49 ;
T_3 V_50 = 0xf ;
for (; V_20 != 0 ; V_20 >>= 4 , V_50 <<= 4 ) {
T_3 V_51 = V_52 ;
switch ( V_20 & 0xf ) {
case V_53 :
continue;
case V_54 :
break;
case V_55 :
V_51 = V_56 ;
break;
case V_57 :
if ( ( V_23 ^ 0xdddddddd ) & V_50 )
goto V_58;
break;
case V_59 :
if ( ( V_23 ^ 0xffffffff ) & V_50 )
goto V_58;
break;
case V_60 :
if ( ( ( V_23 ^ 0xdddddddd ) & V_50 ) == 0 )
goto V_58;
break;
case V_61 :
case V_62 :
if ( ( ( V_23 ^ 0xdddddddd ) & 0xdddddddd & V_50 ) == 0 )
goto V_58;
break;
case V_63 :
if ( ! F_38 ( V_23 ) )
break;
case V_64 :
case V_65 :
if ( ( ( V_23 ^ 0xffffffff ) & V_50 ) == 0 )
goto V_58;
break;
}
V_23 &= ~ V_50 ;
V_23 |= V_51 & V_50 ;
}
* V_49 = V_23 ;
return true ;
V_58:
return false ;
}
int T_2
F_39 ( T_3 V_23 , struct V_38 * V_39 ,
const union V_66 * V_67 , bool V_46 )
{
const struct V_68 * V_69 = (struct V_68 * ) V_67 ;
const struct V_68 * V_70 ;
bool V_71 = false ;
V_23 = F_33 ( V_23 , V_39 , V_46 ) ;
for (; ; V_69 = V_70 ) {
enum V_72 type = V_69 -> V_73 . V_74 & V_75 ;
T_8 V_20 = V_69 -> V_73 . V_74 >> V_76 ;
if ( type == V_77 )
return V_78 ;
V_70 = (struct V_68 * )
( ( V_79 ) V_69 + V_80 [ type ] ) ;
if ( ! V_71 && ( V_23 & V_69 -> V_50 . V_74 ) != V_69 -> V_81 . V_74 )
continue;
if ( ! F_37 ( & V_23 , V_20 ) )
return V_78 ;
switch ( type ) {
case V_82 : {
struct V_83 * V_84 = (struct V_83 * ) V_69 ;
V_70 = (struct V_68 * ) V_84 -> V_67 . V_67 ;
break;
}
case V_85 : {
struct V_86 * V_84 = (struct V_86 * ) V_69 ;
return (* V_84 -> V_87 . V_87 )( V_23 , V_39 ) ;
}
case V_88 : {
struct V_89 * V_84 = (struct V_89 * ) V_69 ;
V_39 -> V_43 = V_84 -> V_40 . V_40 ;
return V_45 ;
}
case V_90 : {
struct V_91 * V_84 = (struct V_91 * ) V_69 ;
V_39 -> V_43 = V_84 -> V_40 . V_40 ;
F_35 ( V_23 , V_39 , V_46 ) ;
return V_44 ;
}
case V_92 :
V_71 = true ;
break;
case V_93 :
default:
return V_78 ;
}
}
}
