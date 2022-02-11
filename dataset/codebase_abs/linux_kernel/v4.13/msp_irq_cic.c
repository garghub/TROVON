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
if ( ! F_6 ( F_7 () ,
F_8 ( V_5 ) ) )
return;
#endif
V_7 = F_9 () ;
F_10 ( V_9 , V_8 ) ;
V_6 [ V_7 ] |= ( 1 << ( V_5 -> V_10 - V_11 ) ) ;
F_11 ( V_9 , V_8 ) ;
F_1 () ;
}
static void F_12 ( struct V_4 * V_5 )
{
volatile T_2 * V_6 = V_2 ;
int V_7 = F_9 () ;
#ifdef F_5
unsigned long V_9 , V_8 ;
#endif
F_10 ( V_9 , V_8 ) ;
V_6 [ V_7 ] &= ~ ( 1 << ( V_5 -> V_10 - V_11 ) ) ;
F_11 ( V_9 , V_8 ) ;
F_1 () ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_12 ( V_5 ) ;
* V_12 = ( 1 << ( V_5 -> V_10 - V_11 ) ) ;
}
static int F_14 ( struct V_4 * V_5 ,
const struct V_13 * V_13 , bool V_14 )
{
int V_15 ;
unsigned long V_9 ;
unsigned int V_8 ;
unsigned long V_16 = ( 1 << ( V_5 -> V_10 - V_11 ) ) ;
volatile T_2 * V_17 = ( volatile T_2 * ) V_2 ;
F_15 ( V_5 -> V_10 == V_18 || V_5 -> V_10 == V_19 ) ;
F_16 ( V_9 , V_8 ) ;
F_17 (cpu) {
if ( F_6 ( V_15 , V_13 ) )
V_17 [ V_15 ] |= V_16 ;
else
V_17 [ V_15 ] &= ~ V_16 ;
}
F_18 ( V_9 , V_8 ) ;
return 0 ;
}
void T_3 F_19 ( void )
{
int V_20 ;
* V_2 = 0x00000000 ;
* V_21 = 0x00000000 ;
* V_12 = 0xFFFFFFFF ;
* V_22 &= 0xFFFF8F8F ;
for ( V_20 = V_11 ; V_20 < V_11 + 32 ; V_20 ++ ) {
F_20 ( V_20 , & V_23 ,
V_24 ) ;
}
F_21 () ;
}
void F_22 ( void )
{
volatile T_2 * V_6 = ( volatile T_2 * ) V_2 ;
T_2 V_17 ;
T_2 V_25 ;
int V_26 = * V_12 ;
V_17 = V_6 [ F_9 () ] ;
V_25 = V_26 & V_17 ;
if ( V_25 & ( 1 << ( V_18 - V_11 ) ) ) {
F_23 ( V_18 ) ;
} else if ( V_25 & ( 1 << ( V_19 - V_11 ) ) ) {
F_23 ( V_19 ) ;
} else if ( V_25 & ( 1 << ( V_27 - V_11 ) ) ) {
F_24 () ;
} else if ( V_25 ) {
F_23 ( F_25 ( V_25 ) + V_11 - 1 ) ;
} else{
F_26 () ;
}
}
