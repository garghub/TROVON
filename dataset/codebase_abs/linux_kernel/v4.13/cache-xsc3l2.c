static inline int F_1 ( void )
{
unsigned long V_1 ;
__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));
return ! ! ( V_1 & 0xf8 ) ;
}
static inline void F_2 ( unsigned long V_2 )
{
__asm__("mcr p15, 1, %0, c7, c11, 1" : : "r" (addr));
}
static inline void F_3 ( unsigned long V_2 )
{
__asm__("mcr p15, 1, %0, c7, c7, 1" : : "r" (addr));
}
static inline void F_4 ( void )
{
unsigned long V_1 , V_3 ;
int V_4 , V_5 ;
__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));
for ( V_4 = 0 ; V_4 < F_5 ( V_1 ) ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_3 = ( V_5 << 29 ) | ( V_4 << 5 ) ;
__asm__("mcr p15, 1, %0, c7, c11, 2" : : "r"(set_way));
}
}
F_6 () ;
}
static inline void F_7 ( unsigned long V_7 )
{
#ifdef F_8
if ( V_7 != - 1 )
F_9 ( ( void * ) V_7 ) ;
#endif
}
static inline unsigned long F_10 ( unsigned long V_8 , unsigned long V_9 )
{
#ifdef F_8
unsigned long V_7 = V_9 & V_10 ;
unsigned long V_11 = V_8 << ( 32 - V_12 ) ;
if ( F_11 ( V_11 < ( V_9 << ( 32 - V_12 ) ) ) ) {
F_7 ( V_9 ) ;
V_7 = ( unsigned long ) F_12 ( V_8 >> V_12 ) ;
}
return V_7 + ( V_11 >> ( 32 - V_12 ) ) ;
#else
return F_13 ( V_8 ) ;
#endif
}
static void F_14 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
if ( V_13 == 0 && V_14 == - 1ul ) {
F_4 () ;
return;
}
V_15 = - 1 ;
if ( V_13 & ( V_16 - 1 ) ) {
V_15 = F_10 ( V_13 & ~ ( V_16 - 1 ) , V_15 ) ;
F_2 ( V_15 ) ;
F_3 ( V_15 ) ;
V_13 = ( V_13 | ( V_16 - 1 ) ) + 1 ;
}
while ( V_13 < ( V_14 & ~ ( V_16 - 1 ) ) ) {
V_15 = F_10 ( V_13 , V_15 ) ;
F_3 ( V_15 ) ;
V_13 += V_16 ;
}
if ( V_13 < V_14 ) {
V_15 = F_10 ( V_13 , V_15 ) ;
F_2 ( V_15 ) ;
F_3 ( V_15 ) ;
}
F_7 ( V_15 ) ;
F_6 () ;
}
static void F_15 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
V_15 = - 1 ;
V_13 &= ~ ( V_16 - 1 ) ;
while ( V_13 < V_14 ) {
V_15 = F_10 ( V_13 , V_15 ) ;
F_2 ( V_15 ) ;
V_13 += V_16 ;
}
F_7 ( V_15 ) ;
F_6 () ;
}
static inline void F_16 ( void )
{
unsigned long V_1 , V_3 ;
int V_4 , V_5 ;
__asm__("mrc p15, 1, %0, c0, c0, 1" : "=r" (l2ctype));
for ( V_4 = 0 ; V_4 < F_5 ( V_1 ) ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_3 = ( V_5 << 29 ) | ( V_4 << 5 ) ;
__asm__("mcr p15, 1, %0, c7, c15, 2" : : "r"(set_way));
}
}
F_6 () ;
}
static void F_17 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_15 ;
if ( V_13 == 0 && V_14 == - 1ul ) {
F_16 () ;
return;
}
V_15 = - 1 ;
V_13 &= ~ ( V_16 - 1 ) ;
while ( V_13 < V_14 ) {
V_15 = F_10 ( V_13 , V_15 ) ;
F_2 ( V_15 ) ;
F_3 ( V_15 ) ;
V_13 += V_16 ;
}
F_7 ( V_15 ) ;
F_6 () ;
}
static int T_1 F_18 ( void )
{
if ( ! F_19 () || ! F_1 () )
return 0 ;
if ( F_20 () & V_17 ) {
F_21 ( L_1 ) ;
F_4 () ;
V_18 . V_19 = F_14 ;
V_18 . V_20 = F_15 ;
V_18 . V_21 = F_17 ;
}
return 0 ;
}
