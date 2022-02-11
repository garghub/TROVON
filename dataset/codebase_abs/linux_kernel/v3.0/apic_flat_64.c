static int F_1 ( char * V_1 , char * V_2 )
{
return 1 ;
}
static const struct V_3 * F_2 ( void )
{
return V_4 ;
}
static void F_3 ( int V_5 , struct V_3 * V_6 )
{
F_4 ( V_6 ) ;
F_5 ( V_6 ) [ 0 ] = V_7 ;
}
static void F_6 ( void )
{
unsigned long V_8 ;
unsigned long V_9 , V_10 ;
V_9 = F_7 () ;
V_10 = 1UL << V_9 ;
F_8 ( V_11 , V_12 ) ;
V_8 = F_9 ( V_13 ) & ~ V_14 ;
V_8 |= F_10 ( V_10 ) ;
F_8 ( V_13 , V_8 ) ;
}
static inline void F_11 ( unsigned long V_15 , int V_16 )
{
unsigned long V_17 ;
F_12 ( V_17 ) ;
F_13 ( V_15 , V_16 , V_18 -> V_19 ) ;
F_14 ( V_17 ) ;
}
static void F_15 ( const struct V_3 * V_3 , int V_16 )
{
unsigned long V_15 = F_5 ( V_3 ) [ 0 ] ;
F_11 ( V_15 , V_16 ) ;
}
static void
F_16 ( const struct V_3 * V_3 , int V_16 )
{
unsigned long V_15 = F_5 ( V_3 ) [ 0 ] ;
int V_5 = F_7 () ;
if ( V_5 < V_20 )
F_17 ( V_5 , & V_15 ) ;
F_11 ( V_15 , V_16 ) ;
}
static void F_18 ( int V_16 )
{
int V_5 = F_7 () ;
#ifdef F_19
int V_21 = 1 ;
#else
int V_21 = 0 ;
#endif
if ( V_21 || V_16 == V_22 ) {
if ( ! F_20 ( V_4 , F_21 ( V_5 ) ) ) {
unsigned long V_15 = F_5 ( V_4 ) [ 0 ] ;
if ( V_5 < V_20 )
F_17 ( V_5 , & V_15 ) ;
F_11 ( V_15 , V_16 ) ;
}
} else if ( F_22 () > 1 ) {
F_23 ( V_23 ,
V_16 , V_18 -> V_19 ) ;
}
}
static void F_24 ( int V_16 )
{
if ( V_16 == V_22 ) {
F_15 ( V_4 , V_16 ) ;
} else {
F_23 ( V_24 ,
V_16 , V_18 -> V_19 ) ;
}
}
static unsigned int F_25 ( unsigned long V_25 )
{
unsigned int V_10 ;
V_10 = ( ( ( V_25 ) >> 24 ) & 0xFFu ) ;
return V_10 ;
}
static unsigned long F_26 ( unsigned int V_10 )
{
unsigned long V_25 ;
V_25 = ( ( V_10 & 0xFFu ) << 24 ) ;
return V_25 ;
}
static unsigned int F_27 ( void )
{
unsigned int V_10 ;
V_10 = F_25 ( F_9 ( V_26 ) ) ;
return V_10 ;
}
static int F_28 ( void )
{
return F_29 ( F_27 () , V_27 ) ;
}
static int F_30 ( int V_28 , int V_29 )
{
return V_28 >> V_29 ;
}
static int F_31 ( char * V_1 , char * V_2 )
{
#ifdef F_32
if ( V_30 . V_31 . V_32 >= V_33 &&
( V_30 . V_17 & V_34 ) ) {
F_33 ( V_35 L_1 ) ;
return 1 ;
}
if ( ! strncmp ( V_1 , L_2 , 3 ) && ! strncmp ( V_2 , L_3 , 3 ) ) {
F_33 ( V_35 L_4 ) ;
return 1 ;
}
#endif
return 0 ;
}
static const struct V_3 * F_34 ( void )
{
return V_4 ;
}
static void F_35 ( int V_5 , struct V_3 * V_6 )
{
F_4 ( V_6 ) ;
F_36 ( V_5 , V_6 ) ;
}
static void F_37 ( const struct V_3 * V_3 , int V_16 )
{
F_38 ( V_3 , V_16 ) ;
}
static void F_39 ( const struct V_3 * V_3 ,
int V_16 )
{
F_40 ( V_3 , V_16 ) ;
}
static void F_41 ( int V_16 )
{
F_40 ( V_4 , V_16 ) ;
}
static void F_42 ( int V_16 )
{
F_37 ( V_4 , V_16 ) ;
}
static unsigned int F_43 ( const struct V_3 * V_3 )
{
int V_5 ;
V_5 = F_44 ( V_3 ) ;
if ( ( unsigned ) V_5 < V_36 )
return F_45 ( V_37 , V_5 ) ;
else
return V_38 ;
}
static unsigned int
F_46 ( const struct V_3 * V_3 ,
const struct V_3 * V_39 )
{
int V_5 ;
F_47 (cpu, cpumask, andmask) {
if ( F_48 ( V_5 , V_4 ) )
break;
}
return F_45 ( V_37 , V_5 ) ;
}
static int F_49 ( void )
{
if ( V_18 == & V_40 || F_50 () > 8 )
return 1 ;
return 0 ;
}
