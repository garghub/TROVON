static inline unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 = 0 ;
if ( V_1 < F_2 ( V_3 ) )
V_2 = V_3 [ V_1 ] ;
#if F_3 ( V_4 )
if ( V_2 > V_5 )
return V_5 ;
return V_6 ;
#else
return V_2 ;
#endif
}
static inline unsigned int F_4 ( struct V_7 * V_1 )
{
T_1 V_8 = F_5 ( V_9 [ V_1 -> V_1 ] + V_10 ) ;
int V_11 = ( ( V_8 & V_12 ) >> V_13 ) |
( ( V_8 & V_14 ) >> V_15 ) ;
return V_16 [ V_11 ] ;
}
static T_2 F_6 ( int V_2 , void * V_17 )
{
struct V_7 * V_1 = V_17 ;
T_1 V_8 ;
V_8 = F_5 ( V_9 [ V_1 -> V_1 ] + V_10 ) ;
if ( ! ( V_8 & V_18 ) )
return V_19 ;
V_8 &= ~ ( V_20 | V_21 ) ;
F_7 ( V_8 , ( V_9 [ V_1 -> V_1 ] + V_10 ) ) ;
F_8 ( & V_1 -> V_22 ) ;
return V_23 ;
}
static int F_9 ( struct V_7 * V_1 )
{
if ( F_10 ( ! ( V_1 -> V_24 & V_25 ) ) )
return 0 ;
return F_11 ( F_1 ( V_1 -> V_1 ) , F_6 ,
#if F_3 ( V_4 )
V_26 ,
#else
0 ,
#endif
V_1 -> V_17 , V_1 ) ;
}
static void F_12 ( struct V_7 * V_1 )
{
F_13 ( F_1 ( V_1 -> V_1 ) , V_1 ) ;
}
static int
F_14 ( struct V_7 * V_1 , unsigned long V_8 )
{
if ( ! V_8 )
V_8 = V_27 | V_20 ;
if ( V_8 & V_20 ) {
V_8 &= ~ V_20 ;
V_1 -> V_24 |= V_25 ;
} else {
V_1 -> V_24 &= ~ V_25 ;
}
F_7 ( V_8 , ( V_9 [ V_1 -> V_1 ] + V_10 ) ) ;
V_1 -> V_24 |= V_28 ;
return 0 ;
}
static void F_15 ( struct V_7 * V_1 )
{
int V_2 ;
T_1 V_8 ;
V_8 = F_5 ( V_9 [ V_1 -> V_1 ] + V_10 ) ;
V_8 |= V_21 ;
if ( V_1 -> V_24 & V_25 )
V_8 |= V_20 ;
F_7 ( V_8 , ( V_9 [ V_1 -> V_1 ] + V_10 ) ) ;
if ( V_1 -> V_24 & V_25 ) {
V_2 = F_1 ( V_1 -> V_1 ) ;
F_16 ( V_2 ) ;
}
}
static void F_17 ( struct V_7 * V_1 )
{
int V_2 ;
T_1 V_8 ;
if ( V_1 -> V_24 & V_25 ) {
V_2 = F_1 ( V_1 -> V_1 ) ;
F_18 ( V_2 ) ;
}
V_8 = F_5 ( V_9 [ V_1 -> V_1 ] + V_10 ) ;
V_8 &= ~ ( V_21 | V_18 | V_20 ) ;
F_7 ( V_8 , ( V_9 [ V_1 -> V_1 ] + V_10 ) ) ;
}
static int F_19 ( struct V_7 * V_1 )
{
if ( F_10 ( ! ( V_1 -> V_24 & V_28 ) ) )
F_14 ( V_1 , 0 ) ;
F_17 ( V_1 ) ;
if ( V_1 -> V_29 || ( F_20 () &&
V_1 -> V_1 == V_30 ) )
F_7 ( V_1 -> V_29 , ( V_9 [ V_1 -> V_1 ] + V_31 ) ) ;
if ( V_1 -> V_32 || ( F_20 () &&
V_1 -> V_1 == V_30 ) )
F_7 ( V_1 -> V_32 , ( V_9 [ V_1 -> V_1 ] + V_33 ) ) ;
F_7 ( V_1 -> V_34 >> F_4 ( V_1 ) ,
( V_9 [ V_1 -> V_1 ] + V_35 ) ) ;
F_15 ( V_1 ) ;
return 0 ;
}
static int F_21 ( struct V_7 * V_1 )
{
if ( ! ( F_5 ( V_9 [ V_1 -> V_1 ] + V_10 ) & V_21 ) )
return 0 ;
return F_5 ( V_9 [ V_1 -> V_1 ] + V_35 )
<< F_4 ( V_1 ) ;
}
static inline int F_22 ( int V_36 )
{
unsigned long V_37 = F_23 ( V_36 ) ;
V_37 &= ~ ( V_38 | V_39 ) ;
F_24 ( V_36 , V_37 ) ;
V_37 |= V_40 ;
F_24 ( V_36 , V_37 ) ;
if ( ( F_23 ( V_36 ) & ( V_39 | V_38 ) ) ) {
F_25 ( V_41 L_1 ) ;
return - V_42 ;
}
return 0 ;
}
static T_2 F_26 ( int V_2 , void * V_43 )
{
#if F_3 ( V_4 )
int V_11 = 0 ;
switch ( V_2 ) {
#if F_3 ( V_5 ) && F_3 ( V_44 )
case V_5 :
V_11 ++ ;
#endif
case V_6 :
if ( F_23 ( V_11 ) & ( V_38 | V_39 ) ) {
F_18 ( V_2 ) ;
return V_23 ;
}
default:
return V_19 ;
}
#else
F_22 ( 0 ) ;
#if F_3 ( V_45 ) || \
F_3 ( V_46 ) || \
F_3 ( V_47 )
F_22 ( 1 ) ;
#endif
F_18 ( V_2 ) ;
return V_23 ;
#endif
}
static unsigned int F_27 ( int V_48 )
{
#if F_3 ( V_4 )
return ( V_48 == 0 ) ? F_1 ( 0 ) : F_1 ( 6 ) ;
#else
return ( V_48 == 0 ) ? V_49 :
#if F_3 ( V_44 )
V_44 ;
#else
- 1 ;
#endif
#endif
}
static int T_3 F_28 ( void )
{
struct V_50 * V_51 = & V_52 ;
int V_53 ;
#ifdef F_29
int V_48 ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
V_53 = F_11 ( F_27 ( V_48 ) , F_26 ,
#if F_3 ( V_4 )
V_26 ,
#else
0 ,
#endif
V_55 [ V_48 ] , ( void * ) V_55 [ V_48 ] ) ;
if ( F_10 ( V_53 < 0 ) ) {
F_25 ( V_41 L_2 , V_55 [ V_48 ] ) ;
return V_53 ;
}
}
#endif
V_53 = F_22 ( 0 ) ;
if ( F_10 ( V_53 != 0 ) )
return V_53 ;
#if F_3 ( V_45 ) || \
F_3 ( V_46 ) || \
F_3 ( V_47 )
V_53 = F_22 ( 1 ) ;
if ( F_10 ( V_53 != 0 ) )
return V_53 ;
#endif
return F_30 ( V_51 ) ;
}
static void T_4 F_31 ( void )
{
#ifdef F_29
int V_48 ;
for ( V_48 = 0 ; V_48 < V_54 ; V_48 ++ ) {
F_13 ( F_27 ( V_48 ) , ( void * ) V_55 [ V_48 ] ) ;
}
#endif
F_32 ( & V_52 ) ;
}
