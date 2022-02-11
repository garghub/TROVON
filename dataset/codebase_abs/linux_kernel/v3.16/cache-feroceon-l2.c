static inline unsigned long F_1 ( unsigned long V_1 )
{
#ifdef F_2
void * V_2 = F_3 ( V_1 >> V_3 ) ;
return ( unsigned long ) V_2 + ( V_1 & ~ V_4 ) ;
#else
return F_4 ( V_1 ) ;
#endif
}
static inline void F_5 ( unsigned long V_2 )
{
#ifdef F_2
F_6 ( ( void * ) V_2 ) ;
#endif
}
static inline void F_7 ( unsigned long V_5 )
{
__asm__("mcr p15, 1, %0, c15, c9, 3" : : "r" (addr));
}
static inline void F_8 ( unsigned long V_6 , unsigned long V_7 )
{
unsigned long va_start , va_end , V_8 ;
F_9 ( ( V_6 ^ V_7 ) >> V_3 ) ;
va_start = F_1 ( V_6 ) ;
va_end = va_start + ( V_7 - V_6 ) ;
F_10 ( V_8 ) ;
__asm__("mcr p15, 1, %0, c15, c9, 4\n\t"
"mcr p15, 1, %1, c15, c9, 5"
: : "r" (va_start), "r" (va_end));
F_11 ( V_8 ) ;
F_5 ( va_start ) ;
}
static inline void F_12 ( unsigned long V_5 )
{
__asm__("mcr p15, 1, %0, c15, c10, 3" : : "r" (addr));
}
static inline void F_13 ( unsigned long V_5 )
{
__asm__("mcr p15, 1, %0, c15, c11, 3" : : "r" (addr));
}
static inline void F_14 ( unsigned long V_6 , unsigned long V_7 )
{
unsigned long va_start , va_end , V_8 ;
F_9 ( ( V_6 ^ V_7 ) >> V_3 ) ;
va_start = F_1 ( V_6 ) ;
va_end = va_start + ( V_7 - V_6 ) ;
F_10 ( V_8 ) ;
__asm__("mcr p15, 1, %0, c15, c11, 4\n\t"
"mcr p15, 1, %1, c15, c11, 5"
: : "r" (va_start), "r" (va_end));
F_11 ( V_8 ) ;
F_5 ( va_start ) ;
}
static inline void F_15 ( void )
{
__asm__("mcr p15, 1, %0, c15, c11, 0" : : "r" (0));
}
static unsigned long F_16 ( unsigned long V_6 , unsigned long V_7 )
{
unsigned long V_9 ;
F_9 ( V_6 & ( V_10 - 1 ) ) ;
F_9 ( V_7 & ( V_10 - 1 ) ) ;
V_9 = V_7 ;
if ( V_9 > V_6 + V_11 )
V_9 = V_6 + V_11 ;
if ( V_9 > ( V_6 | ( V_12 - 1 ) ) + 1 )
V_9 = ( V_6 | ( V_12 - 1 ) ) + 1 ;
return V_9 ;
}
static void F_17 ( unsigned long V_6 , unsigned long V_7 )
{
if ( V_6 & ( V_10 - 1 ) ) {
F_12 ( V_6 & ~ ( V_10 - 1 ) ) ;
V_6 = ( V_6 | ( V_10 - 1 ) ) + 1 ;
}
if ( V_6 < V_7 && V_7 & ( V_10 - 1 ) ) {
F_12 ( V_7 & ~ ( V_10 - 1 ) ) ;
V_7 &= ~ ( V_10 - 1 ) ;
}
while ( V_6 < V_7 ) {
unsigned long V_9 = F_16 ( V_6 , V_7 ) ;
F_14 ( V_6 , V_9 - V_10 ) ;
V_6 = V_9 ;
}
F_18 () ;
}
static void F_19 ( unsigned long V_6 , unsigned long V_7 )
{
if ( ! V_13 ) {
V_6 &= ~ ( V_10 - 1 ) ;
V_7 = ( V_7 + V_10 - 1 ) & ~ ( V_10 - 1 ) ;
while ( V_6 != V_7 ) {
unsigned long V_9 = F_16 ( V_6 , V_7 ) ;
F_8 ( V_6 , V_9 - V_10 ) ;
V_6 = V_9 ;
}
}
F_18 () ;
}
static void F_20 ( unsigned long V_6 , unsigned long V_7 )
{
V_6 &= ~ ( V_10 - 1 ) ;
V_7 = ( V_7 + V_10 - 1 ) & ~ ( V_10 - 1 ) ;
while ( V_6 != V_7 ) {
unsigned long V_9 = F_16 ( V_6 , V_7 ) ;
if ( ! V_13 )
F_8 ( V_6 , V_9 - V_10 ) ;
F_14 ( V_6 , V_9 - V_10 ) ;
V_6 = V_9 ;
}
F_18 () ;
}
static int T_1 F_21 ( void )
{
T_2 V_14 ;
V_14 = F_22 () ;
if ( V_14 & V_15 ) {
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_23 () ;
F_24 ( V_14 & ~ V_15 ) ;
F_11 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_25 ( void )
{
T_2 V_14 ;
V_14 = F_22 () ;
F_24 ( V_14 | V_15 ) ;
}
static void T_1 F_26 ( void )
{
__asm__("mcr p15, 0, %0, c7, c5, 0" : : "r" (0));
}
static int T_1 F_27 ( void )
{
T_2 V_14 ;
V_14 = F_22 () ;
if ( V_14 & V_16 ) {
F_24 ( V_14 & ~ V_16 ) ;
F_26 () ;
return 1 ;
}
return 0 ;
}
static void T_1 F_28 ( void )
{
T_2 V_14 ;
V_14 = F_22 () ;
F_24 ( V_14 | V_16 ) ;
}
static inline T_2 F_29 ( void )
{
T_2 V_17 ;
__asm__("mrc p15, 1, %0, c15, c1, 0" : "=r" (u));
return V_17 ;
}
static inline void F_30 ( T_2 V_17 )
{
__asm__("mcr p15, 1, %0, c15, c1, 0" : : "r" (u));
}
static void T_1 F_31 ( void )
{
T_2 V_17 ;
V_17 = F_29 () ;
if ( ! ( V_17 & 0x01000000 ) ) {
F_32 ( V_18 L_1 ) ;
F_30 ( V_17 | 0x01000000 ) ;
}
}
static void T_1 F_33 ( void )
{
T_2 V_17 ;
V_17 = F_29 () ;
if ( ! ( V_17 & 0x00400000 ) ) {
int V_19 , V_20 ;
F_32 ( V_18 L_2 ) ;
V_20 = F_21 () ;
V_19 = F_27 () ;
F_15 () ;
F_30 ( V_17 | 0x00400000 ) ;
if ( V_19 )
F_28 () ;
if ( V_20 )
F_25 () ;
} else
F_34 ( V_21
L_3 ) ;
}
void T_1 F_35 ( int V_22 )
{
V_13 = V_22 ;
F_31 () ;
V_23 . V_24 = F_17 ;
V_23 . V_25 = F_19 ;
V_23 . V_26 = F_20 ;
F_33 () ;
F_32 ( V_18 L_4 ,
V_13 ? L_5 : L_6 ) ;
}
int T_1 F_36 ( void )
{
struct V_27 * V_28 ;
void T_3 * V_29 ;
bool V_13 = false ;
struct V_30 V_31 ;
#if F_37 ( V_32 )
V_13 = true ;
#endif
V_28 = F_38 ( NULL , V_33 ) ;
if ( V_28 && F_39 ( V_28 , L_7 ) ) {
if ( F_40 ( V_28 , 0 , & V_31 ) )
return - V_34 ;
V_29 = F_41 ( V_31 . V_6 , F_42 ( & V_31 ) ) ;
if ( ! V_29 )
return - V_35 ;
if ( V_13 )
F_43 ( F_44 ( V_29 ) | V_36 , V_29 ) ;
else
F_43 ( F_44 ( V_29 ) & ~ V_36 , V_29 ) ;
}
F_35 ( V_13 ) ;
return 0 ;
}
