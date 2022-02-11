static inline void F_1 ( void )
{
const volatile void T_1 * V_1 = V_2 ;
volatile T_2 V_3 ;
F_2 () ;
V_3 = F_3 ( V_1 ) ;
V_3 ++ ;
}
static void F_4 ( struct V_4 * V_5 )
{
volatile T_2 * V_6 = V_2 ;
int V_7 ;
#ifdef F_5
unsigned int V_8 ;
unsigned long V_9 ;
if ( ! F_6 ( F_7 () , V_5 -> V_10 ) )
return;
#endif
V_7 = F_8 () ;
F_9 ( V_9 , V_8 ) ;
V_6 [ V_7 ] |= ( 1 << ( V_5 -> V_11 - V_12 ) ) ;
F_10 ( V_9 , V_8 ) ;
F_1 () ;
}
static void F_11 ( struct V_4 * V_5 )
{
volatile T_2 * V_6 = V_2 ;
int V_7 = F_8 () ;
#ifdef F_5
unsigned long V_9 , V_8 ;
#endif
F_9 ( V_9 , V_8 ) ;
V_6 [ V_7 ] &= ~ ( 1 << ( V_5 -> V_11 - V_12 ) ) ;
F_10 ( V_9 , V_8 ) ;
F_1 () ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_11 ( V_5 ) ;
* V_13 = ( 1 << ( V_5 -> V_11 - V_12 ) ) ;
}
static int F_13 ( struct V_4 * V_5 ,
const struct V_14 * V_14 , bool V_15 )
{
int V_16 ;
unsigned long V_9 ;
unsigned int V_8 ;
unsigned long V_17 = ( 1 << ( V_5 -> V_11 - V_12 ) ) ;
volatile T_2 * V_18 = ( volatile T_2 * ) V_2 ;
F_14 ( V_5 -> V_11 == V_19 || V_5 -> V_11 == V_20 ) ;
F_15 ( V_9 , V_8 ) ;
F_16 (cpu) {
if ( F_6 ( V_16 , V_14 ) )
V_18 [ V_16 ] |= V_17 ;
else
V_18 [ V_16 ] &= ~ V_17 ;
}
F_17 ( V_9 , V_8 ) ;
return 0 ;
}
void T_3 F_18 ( void )
{
int V_21 ;
* V_2 = 0x00000000 ;
* V_22 = 0x00000000 ;
* V_13 = 0xFFFFFFFF ;
* V_23 &= 0xFFFF8F8F ;
for ( V_21 = V_12 ; V_21 < V_12 + 32 ; V_21 ++ ) {
F_19 ( V_21 , & V_24 ,
V_25 ) ;
}
F_20 () ;
}
void F_21 ( void )
{
volatile T_2 * V_6 = ( volatile T_2 * ) V_2 ;
T_2 V_18 ;
T_2 V_26 ;
int V_27 = * V_13 ;
V_18 = V_6 [ F_8 () ] ;
V_26 = V_27 & V_18 ;
if ( V_26 & ( 1 << ( V_19 - V_12 ) ) ) {
F_22 ( V_19 ) ;
} else if ( V_26 & ( 1 << ( V_20 - V_12 ) ) ) {
F_22 ( V_20 ) ;
} else if ( V_26 & ( 1 << ( V_28 - V_12 ) ) ) {
F_23 () ;
} else if ( V_26 ) {
F_22 ( F_24 ( V_26 ) + V_12 - 1 ) ;
} else{
F_25 () ;
}
}
