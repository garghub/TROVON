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
V_11 -> V_18 = ( F_16 () >> 1 ) & 0xff ;
#if F_17 ( V_19 ) || F_17 ( V_20 )
V_11 -> V_21 = ( F_18 () >> V_22 ) & V_23 ;
#endif
#ifdef V_20
V_11 -> V_24 = ( F_18 () & V_25 ) >> V_26 ;
#endif
}
static void F_19 ( void )
{
F_2 ( L_2 , F_3 () , V_2 ) ;
F_20 ( F_21 () + ( 8 * V_27 / V_28 ) ) ;
#ifdef F_22
if ( V_29 )
F_23 ( F_3 () , V_30 ) ;
#endif
F_24 () ;
}
static void F_25 ( void )
{
F_2 ( L_2 , F_3 () , V_2 ) ;
}
static void F_26 ( int V_1 , struct V_31 * V_32 )
{
struct V_33 * V_34 = F_27 ( V_32 ) ;
unsigned long V_35 = F_28 ( V_32 ) ;
unsigned long V_36 = ( unsigned long ) & V_37 ;
unsigned long V_38 = 0 ;
F_2 ( L_3 , F_3 () ,
V_2 , V_1 ) ;
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
F_29 ( V_1 , V_36 , V_35 , ( unsigned long ) V_34 , V_38 ) ;
}
void T_1 F_30 ( void )
{
int V_9 ;
int V_39 = 0 ;
F_2 ( L_2 , F_3 () , V_2 ) ;
#ifdef F_22
if ( V_29 )
F_23 ( 0 , V_30 ) ;
#endif
for ( V_9 = 1 ; V_9 < V_40 ; V_9 ++ ) {
if ( F_31 ( V_9 ) ) {
F_32 ( V_9 , true ) ;
V_41 [ V_9 ] = ++ V_39 ;
V_42 [ V_39 ] = V_9 ;
}
}
if ( V_43 ) {
unsigned int V_44 , V_45 = F_33 () ;
V_44 = ( ( V_45 & V_46 ) >> V_47 ) + 1 ;
V_48 = V_44 ;
}
F_34 ( L_4 , V_39 ) ;
}
void T_1 F_35 ( unsigned int V_49 )
{
F_2 ( L_5 ,
F_3 () , V_2 , V_49 ) ;
F_36 () ;
}
