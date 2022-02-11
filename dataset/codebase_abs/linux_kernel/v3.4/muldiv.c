static inline int F_1 ( int V_1 )
{
return ( V_1 & 0x2000 ) ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 & 0x800000 ) ;
}
static inline int F_3 ( int V_2 )
{
return V_2 << 19 >> 19 ;
}
static inline void F_4 ( struct V_3 * V_4 )
{
V_4 -> V_5 = V_4 -> V_6 ;
V_4 -> V_6 += 4 ;
}
static inline void F_5 ( unsigned int V_7 , unsigned int V_8 ,
unsigned int V_9 )
{
if( V_8 >= 16 || V_7 >= 16 || V_9 >= 16 ) {
__asm__ __volatile__("save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"save %sp, -0x40, %sp\n\t"
"restore; restore; restore; restore;\n\t"
"restore; restore; restore;\n\t");
}
}
static inline int
F_6 ( unsigned int V_10 , unsigned int V_11 , struct V_3 * V_4 )
{
struct V_12 T_1 * V_13 ;
if ( ! V_11 )
return 0 ;
if ( V_11 < 16 ) {
V_4 -> V_14 [ V_11 ] = V_10 ;
return 0 ;
} else {
V_13 = (struct V_12 T_1 * ) V_4 -> V_14 [ V_15 ] ;
return ( F_7 ( V_10 , & V_13 -> V_16 [ V_11 - 16 ] ) ) ;
}
}
int F_8 ( struct V_3 * V_4 , unsigned long V_5 )
{
unsigned int V_1 ;
int V_17 ;
unsigned int V_7 , V_8 , V_18 ;
if ( ! V_5 )
return - 1 ;
if ( F_9 ( V_1 , ( unsigned int T_1 * ) V_5 ) )
return - 1 ;
if ( ( V_1 & 0xc1400000 ) != 0x80400000 )
return - 1 ;
V_17 = ( ( V_1 >> 19 ) & 0xf ) ;
if ( ( V_17 & 0xe ) != 10 && ( V_17 & 0xe ) != 14 )
return - 1 ;
V_7 = ( V_1 >> 14 ) & 0x1f ;
V_8 = V_1 & 0x1f ;
V_18 = ( V_1 >> 25 ) & 0x1f ;
if ( F_1 ( V_1 ) ) {
F_5 ( V_7 , 0 , V_18 ) ;
V_8 = F_3 ( V_1 ) ;
} else {
F_5 ( V_7 , V_8 , V_18 ) ;
V_8 = F_10 ( V_8 , V_4 ) ;
}
V_7 = F_10 ( V_7 , V_4 ) ;
switch ( V_17 ) {
case 10 :
#ifdef F_11
F_12 ( L_1 , V_7 , V_8 ) ;
#endif
__asm__ __volatile__ ("\n\t"
"mov %0, %%o0\n\t"
"call .umul\n\t"
" mov %1, %%o1\n\t"
"mov %%o0, %0\n\t"
"mov %%o1, %1\n\t"
: "=r" (rs1), "=r" (rs2)
: "0" (rs1), "1" (rs2)
: "o0", "o1", "o2", "o3", "o4", "o5", "o7", "cc");
#ifdef F_11
F_12 ( L_2 , V_8 , V_7 ) ;
#endif
if ( F_6 ( V_7 , V_18 , V_4 ) )
return - 1 ;
V_4 -> V_19 = V_8 ;
break;
case 11 :
#ifdef F_11
F_12 ( L_3 , V_7 , V_8 ) ;
#endif
__asm__ __volatile__ ("\n\t"
"mov %0, %%o0\n\t"
"call .mul\n\t"
" mov %1, %%o1\n\t"
"mov %%o0, %0\n\t"
"mov %%o1, %1\n\t"
: "=r" (rs1), "=r" (rs2)
: "0" (rs1), "1" (rs2)
: "o0", "o1", "o2", "o3", "o4", "o5", "o7", "cc");
#ifdef F_11
F_12 ( L_2 , V_8 , V_7 ) ;
#endif
if ( F_6 ( V_7 , V_18 , V_4 ) )
return - 1 ;
V_4 -> V_19 = V_8 ;
break;
case 14 :
#ifdef F_11
F_12 ( L_4 , V_4 -> V_19 , V_7 , V_8 ) ;
#endif
if ( ! V_8 ) {
#ifdef F_11
F_12 ( L_5 ) ;
#endif
F_13 ( V_4 , V_5 , V_4 -> V_6 , V_4 -> V_20 ) ;
return 0 ;
}
__asm__ __volatile__ ("\n\t"
"mov %2, %%o0\n\t"
"mov %0, %%o1\n\t"
"mov %%g0, %%o2\n\t"
"call __udivdi3\n\t"
" mov %1, %%o3\n\t"
"mov %%o1, %0\n\t"
"mov %%o0, %1\n\t"
: "=r" (rs1), "=r" (rs2)
: "r" (regs->y), "0" (rs1), "1" (rs2)
: "o0", "o1", "o2", "o3", "o4", "o5", "o7",
"g1", "g2", "g3", "cc");
#ifdef F_11
F_12 ( L_6 , V_7 ) ;
#endif
if ( F_6 ( V_7 , V_18 , V_4 ) )
return - 1 ;
break;
case 15 :
#ifdef F_11
F_12 ( L_7 , V_4 -> V_19 , V_7 , V_8 ) ;
#endif
if ( ! V_8 ) {
#ifdef F_11
F_12 ( L_5 ) ;
#endif
F_13 ( V_4 , V_5 , V_4 -> V_6 , V_4 -> V_20 ) ;
return 0 ;
}
__asm__ __volatile__ ("\n\t"
"mov %2, %%o0\n\t"
"mov %0, %%o1\n\t"
"mov %%g0, %%o2\n\t"
"call __divdi3\n\t"
" mov %1, %%o3\n\t"
"mov %%o1, %0\n\t"
"mov %%o0, %1\n\t"
: "=r" (rs1), "=r" (rs2)
: "r" (regs->y), "0" (rs1), "1" (rs2)
: "o0", "o1", "o2", "o3", "o4", "o5", "o7",
"g1", "g2", "g3", "cc");
#ifdef F_11
F_12 ( L_6 , V_7 ) ;
#endif
if ( F_6 ( V_7 , V_18 , V_4 ) )
return - 1 ;
break;
}
if ( F_2 ( V_1 ) ) {
V_4 -> V_20 &= ~ V_21 ;
if ( ( V_17 & 0xe ) == 14 ) {
if ( V_8 ) V_4 -> V_20 |= V_22 ;
}
if ( ! V_7 ) V_4 -> V_20 |= V_23 ;
if ( ( ( int ) V_7 ) < 0 ) V_4 -> V_20 |= V_24 ;
#ifdef F_11
F_12 ( L_8 , V_4 -> V_20 ) ;
#endif
}
F_4 ( V_4 ) ;
return 0 ;
}
