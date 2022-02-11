void * F_1 ( struct V_1 * V_1 )
{
F_2 () ;
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
return F_5 ( V_1 ) ;
}
void F_6 ( struct V_1 * V_1 )
{
if ( F_7 () )
F_8 () ;
if ( ! F_3 ( V_1 ) )
return;
F_9 ( V_1 ) ;
}
void * F_10 ( struct V_1 * V_1 , T_1 V_2 )
{
unsigned long V_3 ;
int V_4 , type ;
F_11 () ;
F_12 () ;
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
type = F_13 () ;
V_4 = type + V_5 * F_14 () ;
V_3 = F_15 ( V_6 + V_4 ) ;
F_16 ( ! F_17 ( * ( V_7 - V_4 ) ) ) ;
F_18 ( V_7 - V_4 , F_19 ( V_1 , V_2 ) ) ;
F_20 () ;
return ( void * ) V_3 ;
}
void * F_21 ( struct V_1 * V_1 )
{
return F_10 ( V_1 , V_8 ) ;
}
void * F_22 ( unsigned long V_9 )
{
return F_23 ( V_9 , V_8 ) ;
}
void F_24 ( void * V_10 )
{
unsigned long V_3 = ( unsigned long ) V_10 & V_11 ;
if ( V_3 >= F_15 ( V_12 ) &&
V_3 <= F_15 ( V_6 ) ) {
int V_4 , type ;
type = F_25 () ;
V_4 = type + V_5 * F_14 () ;
#ifdef F_26
F_27 ( V_3 != F_15 ( V_6 + V_4 ) ) ;
#endif
F_28 ( V_7 - V_4 , V_3 ) ;
F_29 () ;
F_20 () ;
}
#ifdef F_26
else {
F_16 ( V_3 < V_13 ) ;
F_16 ( V_3 >= ( unsigned long ) V_14 ) ;
}
#endif
F_30 () ;
F_31 () ;
}
struct V_1 * F_32 ( void * V_15 )
{
unsigned long V_4 , V_3 = ( unsigned long ) V_15 ;
T_2 * V_16 ;
if ( V_3 < V_17 )
return F_33 ( V_15 ) ;
V_4 = F_34 ( V_3 ) ;
V_16 = V_7 - ( V_4 - V_6 ) ;
return F_35 ( * V_16 ) ;
}
void T_3 F_36 ( void )
{
struct V_18 * V_18 ;
int V_19 ;
F_37 () ;
F_38 (zone) {
unsigned long V_20 , V_21 ;
if ( ! F_39 ( V_18 ) )
continue;
V_20 = V_18 -> V_20 ;
V_21 = V_20 + V_18 -> V_22 ;
V_19 = F_40 ( V_18 ) ;
F_41 ( V_23 L_1 ,
V_18 -> V_24 , V_19 , V_20 , V_21 ) ;
F_42 ( V_19 , V_20 ,
V_21 ) ;
}
}
