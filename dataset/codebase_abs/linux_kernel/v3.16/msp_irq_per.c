static inline void F_1 ( void )
{
const volatile void T_1 * V_1 = V_2 ;
volatile T_2 V_3 ;
F_2 () ;
V_3 = F_3 ( V_1 ) ;
V_3 ++ ;
}
static inline void F_4 ( struct V_4 * V_5 )
{
#ifdef F_5
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
* V_2 |= ( 1 << ( V_5 -> V_8 - V_9 ) ) ;
F_7 ( & V_7 , V_6 ) ;
#else
* V_2 |= ( 1 << ( V_5 -> V_8 - V_9 ) ) ;
#endif
F_1 () ;
}
static inline void F_8 ( struct V_4 * V_5 )
{
#ifdef F_5
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
* V_2 &= ~ ( 1 << ( V_5 -> V_8 - V_9 ) ) ;
F_7 ( & V_7 , V_6 ) ;
#else
* V_2 &= ~ ( 1 << ( V_5 -> V_8 - V_9 ) ) ;
#endif
F_1 () ;
}
static inline void F_9 ( struct V_4 * V_5 )
{
F_8 ( V_5 ) ;
* V_10 = ( 1 << ( V_5 -> V_8 - V_9 ) ) ;
}
static int F_10 ( struct V_4 * V_5 ,
const struct V_11 * V_12 , bool V_13 )
{
F_4 ( V_5 ) ;
return 0 ;
}
void T_3 F_11 ( void )
{
int V_14 ;
* V_2 = 0x00000000 ;
* V_10 = 0xFFFFFFFF ;
for ( V_14 = V_9 ; V_14 < V_9 + 32 ; V_14 ++ ) {
F_12 ( V_14 , & V_15 ) ;
}
}
void F_13 ( void )
{
T_2 V_16 = * V_2 ;
T_2 V_17 = * V_10 ;
T_2 V_18 ;
V_18 = V_17 & V_16 ;
if ( V_18 ) {
F_14 ( F_15 ( V_18 ) + V_9 - 1 ) ;
} else {
F_16 () ;
}
}
