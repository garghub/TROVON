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
F_13 () ;
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
type = F_14 () ;
V_4 = type + V_5 * F_15 () ;
V_3 = F_16 ( V_6 + V_4 ) ;
#ifdef F_17
F_8 ( ! F_18 ( * ( V_7 - V_4 ) ) ) ;
#endif
F_19 ( V_7 - V_4 , F_20 ( V_1 , V_8 ) ) ;
F_21 ( ( unsigned long ) V_3 ) ;
return ( void * ) V_3 ;
}
void F_22 ( void * V_9 )
{
unsigned long V_3 = ( unsigned long ) V_9 & V_10 ;
int type V_11 ;
if ( V_3 < V_12 ) {
F_23 () ;
F_24 () ;
return;
}
type = F_25 () ;
#ifdef F_17
{
int V_4 = type + V_5 * F_15 () ;
F_8 ( V_3 != F_16 ( V_6 + V_4 ) ) ;
F_26 ( & V_13 , V_3 , V_7 - V_4 ) ;
F_21 ( V_3 ) ;
}
#endif
F_27 () ;
F_23 () ;
F_24 () ;
}
void * F_28 ( unsigned long V_14 )
{
unsigned long V_3 ;
int V_4 , type ;
F_12 () ;
F_13 () ;
type = F_14 () ;
V_4 = type + V_5 * F_15 () ;
V_3 = F_16 ( V_6 + V_4 ) ;
F_19 ( V_7 - V_4 , F_29 ( V_14 , V_8 ) ) ;
F_6 ( V_3 ) ;
return ( void * ) V_3 ;
}
void T_1 F_30 ( void )
{
unsigned long V_15 ;
V_15 = F_16 ( V_6 ) ;
V_7 = F_31 ( V_15 ) ;
}
