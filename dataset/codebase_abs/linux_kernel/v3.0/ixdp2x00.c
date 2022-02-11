static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
static struct V_4 V_5 ;
#ifdef F_2
if ( F_3 () )
F_4 ( & V_6 , & V_5 ) ;
#endif
V_3 = * V_7 ;
V_3 |= F_5 ( V_2 -> V_8 ) ;
F_6 ( V_7 , V_3 ) ;
#ifdef F_2
if ( F_3 () )
F_7 ( & V_5 ) ;
#endif
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
static struct V_4 V_5 ;
#ifdef F_2
if ( F_3 () )
F_4 ( & V_6 , & V_5 ) ;
#endif
V_3 = * V_7 ;
V_3 &= ~ F_5 ( V_2 -> V_8 ) ;
F_6 ( V_7 , V_3 ) ;
if ( F_3 () )
F_7 ( & V_5 ) ;
}
static void F_9 ( unsigned int V_8 , struct V_9 * V_10 )
{
volatile T_1 V_11 = 0 ;
static struct V_4 V_5 ;
int V_12 ;
V_10 -> V_1 . V_13 -> V_14 ( & V_10 -> V_1 ) ;
#ifdef F_2
if ( F_3 () )
F_4 ( & V_6 , & V_5 ) ;
#endif
V_11 = * V_15 & 0xff ;
if ( F_3 () )
F_7 ( & V_5 ) ;
if( ! V_11 ) {
F_10 ( V_16 L_1 ) ;
return;
}
for( V_12 = 0 ; V_12 < V_17 ; V_12 ++ ) {
if( V_11 & ( 1 << V_12 ) ) {
int V_18 = F_11 ( 0 ) + V_12 ;
F_12 ( V_18 ) ;
}
}
V_10 -> V_1 . V_13 -> V_19 ( & V_10 -> V_1 ) ;
}
void T_2 F_13 ( volatile unsigned long * V_20 , volatile unsigned long * V_21 , unsigned long V_22 )
{
unsigned int V_8 ;
F_14 () ;
if ( ! F_15 () )
return;
V_15 = V_20 ;
V_7 = V_21 ;
V_17 = V_22 ;
* V_7 = 0xffffffff ;
for( V_8 = F_11 ( 0 ) ; V_8 < F_11 ( V_17 ) ; V_8 ++ ) {
F_16 ( V_8 , & V_23 ,
V_24 ) ;
F_17 ( V_8 , V_25 ) ;
}
F_18 ( V_26 , F_9 ) ;
}
void T_2 F_19 ( void )
{
F_20 () ;
F_21 ( & V_27 , 1 ) ;
}
void F_22 ( void )
{
struct V_28 * V_29 ;
if( ( V_29 = F_23 ( 1 , V_30 ) ) ) {
F_24 ( V_29 ) ;
F_25 ( V_29 ) ;
}
V_29 = F_23 ( 0 , V_31 ) ;
F_24 ( V_29 ) ;
F_25 ( V_29 ) ;
}
void T_2 F_26 ( void )
{
F_27 ( V_32 , 1 ) ;
F_28 ( V_32 , V_33 ) ;
F_29 ( V_34 , F_30 ( V_34 ) ) ;
F_31 () ;
}
