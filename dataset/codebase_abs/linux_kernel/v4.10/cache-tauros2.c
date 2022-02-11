static inline void F_1 ( unsigned long V_1 )
{
__asm__("mcr p15, 1, %0, c7, c11, 3" : : "r" (addr));
}
static inline void F_2 ( unsigned long V_1 )
{
__asm__("mcr p15, 1, %0, c7, c15, 3" : : "r" (addr));
}
static inline void F_3 ( unsigned long V_1 )
{
__asm__("mcr p15, 1, %0, c7, c7, 3" : : "r" (addr));
}
static void F_4 ( unsigned long V_2 , unsigned long V_3 )
{
if ( V_2 & ( V_4 - 1 ) ) {
F_2 ( V_2 & ~ ( V_4 - 1 ) ) ;
V_2 = ( V_2 | ( V_4 - 1 ) ) + 1 ;
}
if ( V_3 & ( V_4 - 1 ) ) {
F_2 ( V_3 & ~ ( V_4 - 1 ) ) ;
V_3 &= ~ ( V_4 - 1 ) ;
}
while ( V_2 < V_3 ) {
F_3 ( V_2 ) ;
V_2 += V_4 ;
}
F_5 () ;
}
static void F_6 ( unsigned long V_2 , unsigned long V_3 )
{
V_2 &= ~ ( V_4 - 1 ) ;
while ( V_2 < V_3 ) {
F_1 ( V_2 ) ;
V_2 += V_4 ;
}
F_5 () ;
}
static void F_7 ( unsigned long V_2 , unsigned long V_3 )
{
V_2 &= ~ ( V_4 - 1 ) ;
while ( V_2 < V_3 ) {
F_2 ( V_2 ) ;
V_2 += V_4 ;
}
F_5 () ;
}
static void F_8 ( void )
{
__asm__ __volatile__ (
"mcr p15, 1, %0, c7, c11, 0 @L2 Cache Clean All\n\t"
"mrc p15, 0, %0, c1, c0, 0\n\t"
"bic %0, %0, #(1 << 26)\n\t"
"mcr p15, 0, %0, c1, c0, 0 @Disable L2 Cache\n\t"
: : "r" (0x0));
}
static void F_9 ( void )
{
__asm__ __volatile__ (
"mcr p15, 1, %0, c7, c7, 0 @L2 Cache Invalidate All\n\t"
"mrc p15, 0, %0, c1, c0, 0\n\t"
"orr %0, %0, #(1 << 26)\n\t"
"mcr p15, 0, %0, c1, c0, 0 @Enable L2 Cache\n\t"
: : "r" (0x0));
}
static inline T_1 T_2 F_10 ( void )
{
T_1 V_5 ;
__asm__("mrc p15, 1, %0, c15, c1, 0" : "=r" (u));
return V_5 ;
}
static inline void T_2 F_11 ( T_1 V_5 )
{
__asm__("mcr p15, 1, %0, c15, c1, 0" : : "r" (u));
}
static inline int T_2 F_12 ( void )
{
return ! ! ( ( V_6 & 0x000f0000 ) == 0x000f0000 ) ;
}
static inline T_1 T_2 F_13 ( void )
{
T_1 V_7 ;
__asm__("mrc p15, 0, %0, c0, c1, 7\n" : "=r" (mmfr3));
return V_7 ;
}
static inline T_1 T_2 F_14 ( void )
{
T_1 V_8 ;
__asm__("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
return V_8 ;
}
static inline void T_2 F_15 ( T_1 V_8 )
{
__asm__("mcr p15, 0, %0, c1, c0, 1\n" : : "r" (actlr));
}
static void F_16 ( unsigned int V_9 )
{
T_1 V_5 ;
V_5 = F_10 () ;
if ( V_9 & V_10 )
V_5 &= ~ V_11 ;
else
V_5 |= V_11 ;
F_17 ( L_1 ,
( V_9 & V_10 )
? L_2 : L_3 ) ;
if ( V_9 & V_12 )
V_5 |= V_13 ;
else
V_5 &= ~ V_13 ;
F_17 ( L_4 ,
( V_9 & V_12 )
? L_2 : L_3 ) ;
F_11 ( V_5 ) ;
}
static void T_2 F_18 ( unsigned int V_9 )
{
char * V_14 = NULL ;
F_16 ( V_9 ) ;
#ifdef F_19
if ( ( V_6 & 0xff0f0000 ) == 0x56050000 ) {
T_1 V_15 ;
V_15 = F_10 () ;
if ( ! ( V_15 & 0x00400000 ) ) {
F_17 ( L_5 ) ;
F_11 ( V_15 | 0x00400000 ) ;
}
V_14 = L_6 ;
V_16 . V_17 = F_4 ;
V_16 . V_18 = F_6 ;
V_16 . V_19 = F_7 ;
V_16 . V_20 = F_8 ;
V_16 . V_21 = F_9 ;
}
#endif
#ifdef F_20
if ( F_12 () && ( F_13 () & 0xf ) == 1 ) {
T_1 V_8 ;
V_8 = F_14 () ;
if ( ! ( V_8 & 0x00000002 ) ) {
F_17 ( L_5 ) ;
F_15 ( V_8 | 0x00000002 ) ;
}
V_14 = L_7 ;
}
#endif
if ( V_14 == NULL ) {
F_21 ( L_8 ) ;
return;
}
F_17 ( L_9
L_10 , V_14 ) ;
}
void T_2 F_22 ( unsigned int V_9 )
{
#ifdef F_23
struct V_22 * V_23 ;
int V_24 ;
unsigned int V_25 ;
V_23 = F_24 ( NULL , V_26 ) ;
if ( ! V_23 ) {
F_17 ( L_11 ) ;
} else {
V_24 = F_25 ( V_23 , L_12 , & V_25 ) ;
if ( V_24 ) {
F_17 ( L_13
L_14 ) ;
V_9 = 0 ;
} else
V_9 = V_25 ;
}
#endif
F_18 ( V_9 ) ;
}
