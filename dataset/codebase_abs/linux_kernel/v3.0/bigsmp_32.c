static unsigned F_1 ( unsigned long V_1 )
{
return ( V_1 >> 24 ) & 0xFF ;
}
static int F_2 ( void )
{
return 1 ;
}
static const struct V_2 * F_3 ( void )
{
#ifdef F_4
return V_3 ;
#else
return F_5 ( 0 ) ;
#endif
}
static unsigned long F_6 ( T_1 * V_4 , int V_5 )
{
return 0 ;
}
static unsigned long F_7 ( int V_6 )
{
return 1 ;
}
static int F_8 ( int V_7 )
{
return F_9 ( V_8 , V_7 ) ;
}
static inline unsigned long F_10 ( int V_7 )
{
unsigned long V_9 , V_10 ;
V_9 = F_11 ( V_11 ) & ~ V_12 ;
V_10 = F_12 ( V_13 , V_7 ) ;
V_9 |= F_13 ( V_10 ) ;
return V_9 ;
}
static void F_14 ( void )
{
unsigned long V_9 ;
int V_7 = F_15 () ;
F_16 ( V_14 , V_15 ) ;
V_9 = F_10 ( V_7 ) ;
F_16 ( V_11 , V_9 ) ;
}
static void F_17 ( void )
{
F_18 ( V_16
L_1 ,
V_17 ) ;
}
static int F_19 ( int V_18 )
{
if ( V_18 < V_19 )
return ( int ) F_12 ( V_13 , V_18 ) ;
return V_20 ;
}
static void F_20 ( T_1 * V_21 , T_1 * V_22 )
{
F_21 ( 0xFFL , V_22 ) ;
}
static int F_22 ( int V_23 )
{
return 1 ;
}
static unsigned int F_23 ( const struct V_2 * V_2 )
{
int V_7 = F_24 ( V_2 ) ;
if ( V_7 < V_19 )
return F_25 ( V_7 ) ;
return V_20 ;
}
static unsigned int F_26 ( const struct V_2 * V_2 ,
const struct V_2 * V_24 )
{
int V_7 ;
F_27 (cpu, cpumask, andmask) {
if ( F_28 ( V_7 , V_3 ) )
return F_25 ( V_7 ) ;
}
return V_20 ;
}
static int F_29 ( int V_25 , int V_26 )
{
return V_25 >> V_26 ;
}
static inline void F_30 ( const struct V_2 * V_27 , int V_28 )
{
F_31 ( V_27 , V_28 ) ;
}
static void F_32 ( int V_28 )
{
F_33 ( V_3 , V_28 ) ;
}
static void F_34 ( int V_28 )
{
F_30 ( V_3 , V_28 ) ;
}
static int F_35 ( const struct V_29 * V_30 )
{
F_18 ( V_31 L_2 , V_30 -> V_32 ) ;
V_33 = 1 ;
return 0 ;
}
static void F_36 ( int V_7 , struct V_2 * V_34 )
{
F_37 ( V_34 ) ;
F_38 ( V_7 , V_34 ) ;
}
static int F_39 ( void )
{
if ( V_35 )
V_33 = 1 ;
else
F_40 ( V_36 ) ;
return V_33 ;
}
struct V_37 * T_2 F_41 ( void )
{
if ( F_39 () )
return & V_38 ;
return NULL ;
}
