static void F_1 ( unsigned int V_1 )
{
F_2 ( L_1 ,
F_3 () , V_2 , V_1 , F_4 () ) ;
F_5 ( F_6 ( V_1 ) ) ;
}
static void F_7 ( unsigned int V_1 )
{
F_2 ( L_1 ,
F_3 () , V_2 , V_1 , F_4 () ) ;
F_5 ( F_8 ( V_1 ) ) ;
}
void F_9 ( int V_1 , unsigned int V_3 )
{
unsigned long V_4 ;
F_10 ( V_4 ) ;
switch ( V_3 ) {
case V_5 :
F_1 ( V_1 ) ;
break;
case V_6 :
F_7 ( V_1 ) ;
break;
}
F_11 ( V_4 ) ;
}
static void F_12 ( const struct V_7 * V_8 , unsigned int V_3 )
{
unsigned int V_9 ;
F_13 (i, mask)
F_9 ( V_9 , V_3 ) ;
}
static void F_14 ( void )
{
struct V_10 * V_11 = & V_12 ;
F_15 ( V_13 , V_14 | V_15 | V_16 |
V_17 ) ;
V_11 -> V_18 = ( F_16 () >> 1 ) & 0x1ff ;
#if F_17 ( V_19 ) || F_17 ( V_20 )
if ( V_21 )
V_11 -> V_22 = ( F_18 () >> V_23 ) &
V_24 ;
#endif
#ifdef V_20
V_11 -> V_25 = ( F_18 () & V_26 ) >> V_27 ;
#endif
}
static void F_19 ( void )
{
F_2 ( L_2 , F_3 () , V_2 ) ;
F_20 ( F_21 () + ( 8 * V_28 / V_29 ) ) ;
#ifdef F_22
if ( V_30 )
F_23 ( F_3 () , V_31 ) ;
#endif
F_24 () ;
}
static void F_25 ( void )
{
F_2 ( L_2 , F_3 () , V_2 ) ;
}
static void F_26 ( int V_1 , struct V_32 * V_33 )
{
struct V_34 * V_35 = F_27 ( V_33 ) ;
unsigned long V_36 = F_28 ( V_33 ) ;
unsigned long V_37 = ( unsigned long ) & V_38 ;
unsigned long V_39 = 0 ;
F_2 ( L_3 , F_3 () ,
V_2 , V_1 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_29 ( V_1 , V_37 , V_36 , ( unsigned long ) V_35 , V_39 ) ;
}
void T_1 F_30 ( void )
{
int V_9 ;
int V_40 = 0 ;
F_2 ( L_2 , F_3 () , V_2 ) ;
#ifdef F_22
if ( V_30 )
F_23 ( 0 , V_31 ) ;
#endif
for ( V_9 = 1 ; V_9 < V_41 ; V_9 ++ ) {
if ( F_31 ( V_9 ) ) {
F_32 ( V_9 , true ) ;
V_42 [ V_9 ] = ++ V_40 ;
V_43 [ V_40 ] = V_9 ;
}
}
if ( V_21 ) {
unsigned int V_44 = 1 ;
#ifdef V_19
unsigned int V_45 = F_33 () ;
V_44 = ( ( V_45 & V_46 ) >> V_47 ) + 1 ;
#elif F_17 ( V_20 )
unsigned int V_45 = F_33 () ;
V_44 = ( ( V_45 & V_48 ) >> V_49 ) + 1 ;
#endif
V_50 = V_44 ;
}
F_34 ( L_4 , V_40 ) ;
}
void T_1 F_35 ( unsigned int V_51 )
{
F_2 ( L_5 ,
F_3 () , V_2 , V_51 ) ;
F_36 () ;
}
