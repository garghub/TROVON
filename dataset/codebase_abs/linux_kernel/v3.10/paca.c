static void F_1 ( int V_1 , unsigned long V_2 )
{
if ( V_1 <= V_3 )
return;
V_4 = F_2 ( sizeof( struct V_5 ) *
( V_1 - V_3 ) ) ;
V_6 = F_3 ( F_4 ( V_4 ,
V_7 , V_2 ) ) ;
}
static struct V_5 * F_5 ( int V_8 )
{
struct V_5 * V_9 ;
if ( V_8 < V_3 )
return & V_5 [ V_8 ] ;
V_9 = V_6 + ( V_8 - V_3 ) ;
* V_9 = V_5 [ 0 ] ;
return V_9 ;
}
static void F_6 ( void )
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
void T_1 F_10 ( struct V_12 * V_13 , int V_8 )
{
unsigned long V_14 = ( unsigned long ) ( & V_15 ) + 0x8000UL ;
#ifdef F_11
V_13 -> V_16 = F_5 ( V_8 ) ;
#else
V_13 -> V_17 = V_18 ;
#endif
V_13 -> V_19 = 0x8000 ;
V_13 -> V_20 = V_8 ;
V_13 -> V_14 = V_14 ;
V_13 -> V_21 = ( unsigned long ) V_22 ;
V_13 -> V_23 = V_24 ;
V_13 -> V_25 = 0xffff ;
V_13 -> V_26 = V_27 ;
V_13 -> V_28 = & V_29 ;
V_13 -> V_30 = 0xfeeeeeeeeeeeeeeeULL ;
#ifdef F_12
V_13 -> V_31 = & V_32 [ V_8 ] ;
#endif
}
void F_13 ( struct V_12 * V_13 )
{
V_33 = V_13 ;
#ifdef F_14
F_15 ( V_34 , V_33 -> V_35 ) ;
#else
if ( F_16 ( V_36 ) )
F_15 ( V_37 , V_33 ) ;
#endif
F_15 ( V_38 , V_33 ) ;
}
void T_1 F_17 ( void )
{
int V_8 , V_2 ;
V_2 = F_18 ( 0x10000000ULL , V_39 ) ;
V_40 = F_2 ( sizeof( struct V_12 ) * V_41 ) ;
V_42 = F_3 ( F_4 ( V_40 , V_7 , V_2 ) ) ;
memset ( V_42 , 0 , V_40 ) ;
F_19 ( V_43 L_1 ,
V_40 , V_41 , V_42 ) ;
F_1 ( V_41 , V_2 ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
F_10 ( & V_42 [ V_8 ] , V_8 ) ;
}
void T_1 F_20 ( void )
{
int V_10 ;
V_10 = F_2 ( sizeof( struct V_12 ) * V_41 ) ;
if ( V_10 >= V_40 )
return;
F_8 ( F_9 ( V_42 ) + V_10 , V_40 - V_10 ) ;
F_19 ( V_43 L_2 ,
V_40 - V_10 ) ;
V_40 = V_10 ;
F_6 () ;
}
