void * F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
unsigned long V_3 ;
int V_4 , type ;
F_2 () ;
F_3 () ;
if ( ! F_4 ( V_1 ) )
return F_5 ( V_1 ) ;
type = F_6 () ;
V_4 = type + V_5 * F_7 () ;
V_3 = F_8 ( V_6 + V_4 ) ;
#ifdef F_9
F_10 ( ! F_11 ( * ( V_7 - V_4 ) ) ) ;
#endif
F_12 ( & V_8 , V_3 , V_7 - V_4 , F_13 ( V_1 , V_2 ) ) ;
F_14 ( NULL , V_3 ) ;
return ( void * ) V_3 ;
}
void F_15 ( void * V_9 )
{
unsigned long V_3 = ( unsigned long ) V_9 & V_10 ;
int type ;
unsigned int V_4 ;
if ( V_3 < F_8 ( V_11 ) ) {
F_16 () ;
F_17 () ;
return;
}
type = F_18 () ;
V_4 = type + V_5 * F_7 () ;
#ifdef F_9
F_10 ( V_3 != F_8 ( V_6 + V_4 ) ) ;
#endif
F_19 ( & V_8 , V_3 , V_7 - V_4 ) ;
F_14 ( NULL , V_3 ) ;
F_20 () ;
F_16 () ;
F_17 () ;
}
