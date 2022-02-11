static unsigned long F_1 ( unsigned int V_1 )
{
unsigned long V_2 = V_3 ;
#ifdef F_2
if ( V_1 >= 6 )
V_2 = F_2 ;
#endif
return V_2 ;
}
static unsigned long F_3 ( unsigned int V_1 )
{
unsigned long V_2 = F_1 ( V_1 ) ;
if ( V_1 >= 9 )
V_1 -= 6 ;
if ( V_1 >= 4 )
V_2 += 0x10 ;
return V_2 + ( V_1 * 0x10 ) ;
}
static inline unsigned int F_4 ( unsigned int V_1 )
{
return V_1 >= 6 ? V_4 : V_5 ;
}
static inline unsigned int F_4 ( unsigned int V_1 )
{
return V_6 [ V_1 ] ;
}
static inline unsigned int F_5 ( struct V_7 * V_1 )
{
T_1 V_8 = F_6 ( F_3 ( V_1 -> V_1 ) + V_9 ) ;
int V_10 = ( ( V_8 & V_11 ) >> V_12 ) |
( ( V_8 & V_13 ) >> V_14 ) ;
return V_15 [ V_10 ] ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_7 * V_1 = V_17 ;
T_1 V_8 ;
V_8 = F_6 ( F_3 ( V_1 -> V_1 ) + V_9 ) ;
if ( ! ( V_8 & V_18 ) )
return V_19 ;
V_8 &= ~ ( V_20 | V_21 ) ;
F_8 ( V_8 , ( F_3 ( V_1 -> V_1 ) + V_9 ) ) ;
F_9 ( & V_1 -> V_22 ) ;
return V_23 ;
}
static int F_10 ( struct V_7 * V_1 )
{
if ( F_11 ( ! ( V_1 -> V_24 & V_25 ) ) )
return 0 ;
return F_12 ( F_4 ( V_1 -> V_1 ) , F_7 , V_26 ,
V_1 -> V_17 , V_1 ) ;
}
static void F_13 ( struct V_7 * V_1 )
{
F_14 ( F_4 ( V_1 -> V_1 ) , V_1 ) ;
}
static int
F_15 ( struct V_7 * V_1 , unsigned long V_8 )
{
if ( ! V_8 )
V_8 = V_27 | V_20 ;
if ( V_8 & V_20 ) {
V_8 &= ~ V_20 ;
V_1 -> V_24 |= V_25 ;
} else {
V_1 -> V_24 &= ~ V_25 ;
}
F_8 ( V_8 , ( F_3 ( V_1 -> V_1 ) + V_9 ) ) ;
V_1 -> V_24 |= V_28 ;
return 0 ;
}
static void F_16 ( struct V_7 * V_1 )
{
int V_16 ;
T_1 V_8 ;
V_8 = F_6 ( F_3 ( V_1 -> V_1 ) + V_9 ) ;
V_8 |= V_21 ;
if ( V_1 -> V_24 & V_25 )
V_8 |= V_20 ;
F_8 ( V_8 , ( F_3 ( V_1 -> V_1 ) + V_9 ) ) ;
if ( V_1 -> V_24 & V_25 ) {
V_16 = F_4 ( V_1 -> V_1 ) ;
F_17 ( V_16 ) ;
}
}
static void F_18 ( struct V_7 * V_1 )
{
int V_16 ;
T_1 V_8 ;
if ( V_1 -> V_24 & V_25 ) {
V_16 = F_4 ( V_1 -> V_1 ) ;
F_19 ( V_16 ) ;
}
V_8 = F_6 ( F_3 ( V_1 -> V_1 ) + V_9 ) ;
V_8 &= ~ ( V_21 | V_18 | V_20 ) ;
F_8 ( V_8 , ( F_3 ( V_1 -> V_1 ) + V_9 ) ) ;
}
static int F_20 ( struct V_7 * V_1 )
{
if ( F_11 ( ! ( V_1 -> V_24 & V_28 ) ) )
F_15 ( V_1 , 0 ) ;
F_18 ( V_1 ) ;
if ( V_1 -> V_29 || ( F_21 () &&
V_1 -> V_1 == V_30 ) )
F_8 ( V_1 -> V_29 , ( F_3 ( V_1 -> V_1 ) + V_31 ) ) ;
if ( V_1 -> V_32 || ( F_21 () &&
V_1 -> V_1 == V_30 ) )
F_8 ( V_1 -> V_32 , ( F_3 ( V_1 -> V_1 ) + V_33 ) ) ;
F_8 ( V_1 -> V_34 >> F_5 ( V_1 ) ,
( F_3 ( V_1 -> V_1 ) + V_35 ) ) ;
F_16 ( V_1 ) ;
return 0 ;
}
static int F_22 ( struct V_7 * V_1 )
{
if ( ! ( F_6 ( F_3 ( V_1 -> V_1 ) + V_9 ) & V_21 ) )
return 0 ;
return F_6 ( F_3 ( V_1 -> V_1 ) + V_35 )
<< F_5 ( V_1 ) ;
}
static inline int F_23 ( int V_36 )
{
unsigned long V_37 = F_24 ( V_36 ) ;
V_37 &= ~ ( V_38 | V_39 ) ;
F_25 ( V_36 , V_37 ) ;
V_37 |= V_40 ;
F_25 ( V_36 , V_37 ) ;
if ( ( F_24 ( V_36 ) & ( V_39 | V_38 ) ) ) {
F_26 ( V_41 L_1 ) ;
return - V_42 ;
}
return 0 ;
}
static inline unsigned int F_27 ( int V_43 )
{
return F_4 ( V_43 * 6 ) ;
}
static inline unsigned int F_27 ( int V_43 )
{
return V_44 [ V_43 ] ;
}
static T_2 F_28 ( int V_16 , void * V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_23 ( V_46 ) ;
F_19 ( V_16 ) ;
return V_23 ;
}
static int F_29 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
int V_46 = F_12 ( F_27 ( V_43 ) , F_28 ,
V_26 , V_49 [ V_43 ] , ( void * ) V_49 [ V_43 ] ) ;
if ( F_11 ( V_46 < 0 ) ) {
F_26 ( V_41 L_2 , V_49 [ V_43 ] ) ;
return V_46 ;
}
}
return 0 ;
}
static void F_30 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ )
F_14 ( F_27 ( V_43 ) , NULL ) ;
}
static inline int F_29 ( void )
{
return 0 ;
}
static void F_30 ( void )
{
}
static int T_3 F_31 ( void )
{
struct V_50 * V_51 = & V_52 ;
int V_46 , V_53 ;
V_53 = F_29 () ;
if ( F_11 ( V_53 != 0 ) )
return V_53 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
V_53 = F_23 ( V_46 ) ;
if ( F_11 ( V_53 != 0 ) )
return V_53 ;
}
return F_32 ( V_51 ) ;
}
static void T_4 F_33 ( void )
{
F_30 () ;
F_34 ( & V_52 ) ;
}
