void * F_1 ( struct V_1 * V_1 )
{
void * V_2 ;
F_2 () ;
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
V_2 = F_5 ( V_1 ) ;
F_6 ( ( unsigned long ) V_2 ) ;
return V_2 ;
}
void F_7 ( struct V_1 * V_1 )
{
F_8 ( F_9 () ) ;
if ( ! F_3 ( V_1 ) )
return;
F_10 ( V_1 ) ;
}
void * F_11 ( struct V_1 * V_1 )
{
unsigned long V_3 ;
int V_4 , type ;
F_12 () ;
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
type = F_13 () ;
V_4 = type + V_5 * F_14 () ;
V_3 = F_15 ( V_6 + V_4 ) ;
#ifdef F_16
F_8 ( ! F_17 ( * ( V_7 - V_4 ) ) ) ;
#endif
F_18 ( V_7 - V_4 , F_19 ( V_1 , V_8 ) ) ;
F_20 ( ( unsigned long ) V_3 ) ;
return ( void * ) V_3 ;
}
void F_21 ( void * V_9 )
{
unsigned long V_3 = ( unsigned long ) V_9 & V_10 ;
int type ;
if ( V_3 < V_11 ) {
F_22 () ;
return;
}
type = F_23 () ;
#ifdef F_16
{
int V_4 = type + V_5 * F_14 () ;
F_8 ( V_3 != F_15 ( V_6 + V_4 ) ) ;
F_24 ( & V_12 , V_3 , V_7 - V_4 ) ;
F_20 ( V_3 ) ;
}
#endif
F_25 () ;
F_22 () ;
}
void * F_26 ( unsigned long V_13 )
{
unsigned long V_3 ;
int V_4 , type ;
F_12 () ;
type = F_13 () ;
V_4 = type + V_5 * F_14 () ;
V_3 = F_15 ( V_6 + V_4 ) ;
F_18 ( V_7 - V_4 , F_27 ( V_13 , V_8 ) ) ;
F_6 ( V_3 ) ;
return ( void * ) V_3 ;
}
struct V_1 * F_28 ( void * V_14 )
{
unsigned long V_4 , V_3 = ( unsigned long ) V_14 ;
T_1 * V_15 ;
if ( V_3 < V_11 )
return F_29 ( V_14 ) ;
V_4 = F_30 ( V_3 ) ;
V_15 = V_7 - ( V_4 - V_6 ) ;
return F_31 ( * V_15 ) ;
}
void T_2 F_32 ( void )
{
unsigned long V_16 ;
V_16 = F_15 ( V_6 ) ;
V_7 = F_33 ( V_16 ) ;
}
