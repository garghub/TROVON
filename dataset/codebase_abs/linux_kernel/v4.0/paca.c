static void T_1 F_1 ( int V_1 , unsigned long V_2 )
{
if ( V_1 <= V_3 )
return;
V_4 = F_2 ( sizeof( struct V_5 ) *
( V_1 - V_3 ) ) ;
V_6 = F_3 ( F_4 ( V_4 ,
V_7 , V_2 ) ) ;
}
static struct V_5 * T_1 F_5 ( int V_8 )
{
struct V_5 * V_9 ;
if ( V_8 < V_3 )
return & V_5 [ V_8 ] ;
V_9 = V_6 + ( V_8 - V_3 ) ;
* V_9 = V_5 [ 0 ] ;
return V_9 ;
}
static void T_1 F_6 ( void )
{
long V_10 = 0 , V_11 ;
if ( ! V_4 )
return;
V_11 = F_7 () - V_3 ;
if ( V_11 > 0 )
V_10 = F_2 ( V_11 * sizeof( struct V_5 ) ) ;
if ( V_10 >= V_4 )
return;
F_8 ( F_9 ( V_6 ) + V_10 , V_4 - V_10 ) ;
V_4 = V_10 ;
}
static inline void F_1 ( int V_1 , unsigned long V_2 ) { }
static inline void F_6 ( void ) { }
static void T_1 F_10 ( int V_1 , int V_2 )
{
int V_12 = F_2 ( sizeof( struct V_13 ) * V_1 ) ;
V_13 = F_3 ( F_4 ( V_12 , V_7 , V_2 ) ) ;
memset ( V_13 , 0 , V_12 ) ;
}
static struct V_13 * T_1 F_11 ( int V_8 )
{
struct V_13 * V_14 = & V_13 [ V_8 ] ;
if ( ! V_13 )
return NULL ;
V_14 -> V_15 = F_12 ( V_16 ) ;
V_14 -> V_17 = F_12 ( sizeof( * V_14 ) ) ;
return V_14 ;
}
static void T_1 F_10 ( int V_1 , int V_2 ) { }
void T_1 F_13 ( struct V_18 * V_19 , int V_8 )
{
unsigned long V_20 = ( unsigned long ) ( & V_21 ) + 0x8000UL ;
#ifdef F_14
V_19 -> V_22 = F_5 ( V_8 ) ;
#else
V_19 -> V_23 = V_24 ;
#endif
V_19 -> V_25 = 0x8000 ;
V_19 -> V_26 = V_8 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_27 = ( unsigned long ) V_28 ;
V_19 -> V_29 = V_30 & ~ ( V_31 | V_32 ) ;
V_19 -> V_33 = 0xffff ;
V_19 -> V_34 = V_35 ;
V_19 -> V_36 = & V_37 ;
V_19 -> V_38 = 0xfeeeeeeeeeeeeeeeULL ;
#ifdef F_15
V_19 -> V_39 = F_11 ( V_8 ) ;
#endif
#ifdef F_16
V_19 -> V_40 = & V_19 -> V_41 ;
#endif
}
void F_17 ( struct V_18 * V_19 )
{
V_42 = V_19 ;
#ifdef F_16
F_18 ( V_43 , V_42 -> V_44 ) ;
#else
if ( F_19 ( V_45 ) )
F_18 ( V_46 , V_42 ) ;
#endif
F_18 ( V_47 , V_42 ) ;
}
void T_1 F_20 ( void )
{
int V_8 , V_2 ;
V_2 = F_21 ( 0x10000000ULL , V_48 ) ;
V_49 = F_2 ( sizeof( struct V_18 ) * V_50 ) ;
V_51 = F_3 ( F_4 ( V_49 , V_7 , V_2 ) ) ;
memset ( V_51 , 0 , V_49 ) ;
F_22 ( V_52 L_1 ,
V_49 , V_50 , V_51 ) ;
F_1 ( V_50 , V_2 ) ;
F_10 ( V_50 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_50 ; V_8 ++ )
F_13 ( & V_51 [ V_8 ] , V_8 ) ;
}
void T_1 F_23 ( void )
{
int V_10 ;
V_10 = F_2 ( sizeof( struct V_18 ) * V_50 ) ;
if ( V_10 >= V_49 )
return;
F_8 ( F_9 ( V_51 ) + V_10 , V_49 - V_10 ) ;
F_22 ( V_52 L_2 ,
V_49 - V_10 ) ;
V_49 = V_10 ;
F_6 () ;
}
