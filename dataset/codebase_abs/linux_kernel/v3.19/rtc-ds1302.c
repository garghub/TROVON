static inline int F_1 ( void )
{
return 0 ;
}
static inline void F_2 ( void )
{
F_3 ( F_4 () & ~ ( V_1 | V_2 | V_3 ) ) ;
}
static inline void F_5 ( void )
{
F_3 ( F_4 () | V_3 ) ;
F_3 ( F_4 () & ~ V_3 ) ;
}
static inline void F_6 ( void )
{
F_3 ( F_4 () | V_1 ) ;
}
static inline void F_7 ( void )
{
F_3 ( F_4 () & ~ V_1 ) ;
}
static inline void F_8 ( int V_4 )
{
F_3 ( ( F_4 () & ~ V_2 ) | ( V_4 ? V_2 : 0 ) ) ;
}
static inline int F_9 ( void )
{
return ! ! ( F_4 () & V_2 ) ;
}
static void F_10 ( unsigned int V_5 )
{
int V_6 ;
F_11 () ;
for ( V_6 = 8 ; ( V_6 ) ; V_6 -- , V_5 >>= 1 ) {
F_8 ( V_5 & 0x1 ) ;
F_5 () ;
}
}
static unsigned int F_12 ( void )
{
unsigned int V_5 ;
int V_6 ;
F_13 () ;
for ( V_6 = 0 , V_5 = 0 ; ( V_6 < 8 ) ; V_6 ++ ) {
V_5 |= ( F_9 () << V_6 ) ;
F_5 () ;
}
return V_5 ;
}
static unsigned int F_14 ( unsigned int V_7 )
{
unsigned int V_5 ;
F_2 () ;
F_6 () ;
F_10 ( ( ( V_7 & 0x3f ) << 1 ) | V_8 ) ;
V_5 = F_12 () ;
F_7 () ;
return V_5 ;
}
static void F_15 ( unsigned int V_7 , unsigned int V_5 )
{
F_2 () ;
F_6 () ;
F_10 ( ( ( V_7 & 0x3f ) << 1 ) | V_9 ) ;
F_10 ( V_5 ) ;
F_7 () ;
}
static int F_16 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
V_13 -> V_14 = F_17 ( F_14 ( V_15 ) ) ;
V_13 -> V_16 = F_17 ( F_14 ( V_17 ) ) ;
V_13 -> V_18 = F_17 ( F_14 ( V_19 ) ) ;
V_13 -> V_20 = F_17 ( F_14 ( V_21 ) ) ;
V_13 -> V_22 = F_17 ( F_14 ( V_23 ) ) ;
V_13 -> V_24 = F_17 ( F_14 ( V_25 ) ) - 1 ;
V_13 -> V_26 = F_17 ( F_14 ( V_27 ) ) ;
if ( V_13 -> V_26 < 70 )
V_13 -> V_26 += 100 ;
F_18 ( V_11 , L_1
L_2 ,
V_28 ,
V_13 -> V_14 , V_13 -> V_16 , V_13 -> V_18 ,
V_13 -> V_22 , V_13 -> V_24 + 1 , V_13 -> V_26 , V_13 -> V_20 ) ;
return F_19 ( V_13 ) ;
}
static int F_20 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
F_15 ( V_29 , V_30 ) ;
F_15 ( V_15 , F_14 ( V_15 ) | 0x80 ) ;
F_15 ( V_15 , F_21 ( V_13 -> V_14 ) ) ;
F_15 ( V_17 , F_21 ( V_13 -> V_16 ) ) ;
F_15 ( V_19 , F_21 ( V_13 -> V_18 ) ) ;
F_15 ( V_21 , F_21 ( V_13 -> V_20 ) ) ;
F_15 ( V_23 , F_21 ( V_13 -> V_22 ) ) ;
F_15 ( V_25 , F_21 ( V_13 -> V_24 + 1 ) ) ;
F_15 ( V_27 , F_21 ( V_13 -> V_26 % 100 ) ) ;
F_15 ( V_15 , F_14 ( V_15 ) & ~ 0x80 ) ;
F_15 ( V_29 , V_31 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 , unsigned int V_32 ,
unsigned long V_33 )
{
switch ( V_32 ) {
#ifdef F_23
case F_23 :
{
int V_34 ;
if ( F_24 ( & V_34 , ( int V_35 * ) V_33 , sizeof( int ) ) )
return - V_36 ;
F_15 ( V_37 , ( 0xa0 | V_34 * 0xf ) ) ;
return 0 ;
}
#endif
}
return - V_38 ;
}
static int T_1 F_25 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
if ( F_1 () ) {
F_26 ( & V_40 -> V_11 , L_3 ) ;
return - V_43 ;
}
F_2 () ;
F_15 ( V_44 , 0x42 ) ;
if ( F_14 ( V_44 ) != 0x42 ) {
F_26 ( & V_40 -> V_11 , L_4 ) ;
return - V_45 ;
}
V_42 = F_27 ( & V_40 -> V_11 , L_5 ,
& V_46 , V_47 ) ;
if ( F_28 ( V_42 ) )
return F_29 ( V_42 ) ;
F_30 ( V_40 , V_42 ) ;
return 0 ;
}
