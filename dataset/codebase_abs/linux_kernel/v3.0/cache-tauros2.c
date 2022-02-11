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
static inline T_1 T_2 F_8 ( void )
{
T_1 V_5 ;
__asm__("mrc p15, 1, %0, c15, c1, 0" : "=r" (u));
return V_5 ;
}
static inline void T_2 F_9 ( T_1 V_5 )
{
__asm__("mcr p15, 1, %0, c15, c1, 0" : : "r" (u));
}
static void T_2 F_10 ( void )
{
T_1 V_5 ;
V_5 = F_8 () ;
if ( ! ( V_5 & 0x01000000 ) ) {
F_11 ( V_6 L_1 ) ;
F_9 ( V_5 | 0x01000000 ) ;
}
}
static inline int T_2 F_12 ( void )
{
extern int V_7 ;
return ! ! ( ( V_7 & 0x000f0000 ) == 0x000f0000 ) ;
}
static inline T_1 T_2 F_13 ( void )
{
T_1 V_8 ;
__asm__("mrc p15, 0, %0, c0, c1, 7\n" : "=r" (mmfr3));
return V_8 ;
}
static inline T_1 T_2 F_14 ( void )
{
T_1 V_9 ;
__asm__("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
return V_9 ;
}
static inline void T_2 F_15 ( T_1 V_9 )
{
__asm__("mcr p15, 0, %0, c1, c0, 1\n" : : "r" (actlr));
}
void T_2 F_16 ( void )
{
extern int V_7 ;
char * V_10 ;
F_10 () ;
#ifdef F_17
if ( ( V_7 & 0xff0f0000 ) == 0x56050000 ) {
T_1 V_11 ;
V_11 = F_8 () ;
if ( ! ( V_11 & 0x00400000 ) ) {
F_11 ( V_6 L_2 ) ;
F_9 ( V_11 | 0x00400000 ) ;
}
V_10 = L_3 ;
V_12 . V_13 = F_4 ;
V_12 . V_14 = F_6 ;
V_12 . V_15 = F_7 ;
}
#endif
#ifdef F_18
if ( F_12 () && ( F_13 () & 0xf ) == 0 ) {
if ( ! ( F_19 () & 0x04000000 ) ) {
F_11 ( V_6 L_2 ) ;
F_20 ( 0x04000000 , 0x04000000 ) ;
}
V_10 = L_4 ;
V_12 . V_13 = F_4 ;
V_12 . V_14 = F_6 ;
V_12 . V_15 = F_7 ;
}
#endif
#ifdef F_21
if ( F_12 () && ( F_13 () & 0xf ) == 1 ) {
T_1 V_9 ;
V_9 = F_14 () ;
if ( ! ( V_9 & 0x00000002 ) ) {
F_11 ( V_6 L_2 ) ;
F_15 ( V_9 | 0x00000002 ) ;
}
V_10 = L_5 ;
}
#endif
if ( V_10 == NULL ) {
F_11 ( V_16 L_6 ) ;
return;
}
F_11 ( V_6 L_7
L_8 , V_10 ) ;
}
