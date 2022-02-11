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
if ( ! F_3 ( V_1 ) )
return F_4 ( V_1 ) ;
type = F_12 () ;
V_4 = type + V_5 * F_13 () ;
V_3 = F_14 ( V_6 + V_4 ) ;
F_15 ( ! F_16 ( * ( V_7 - V_4 ) ) ) ;
F_17 ( V_7 - V_4 , F_18 ( V_1 , V_2 ) ) ;
F_19 () ;
return ( void * ) V_3 ;
}
void * F_20 ( struct V_1 * V_1 )
{
return F_10 ( V_1 , V_8 ) ;
}
void * F_21 ( unsigned long V_9 )
{
return F_22 ( V_9 , V_8 ) ;
}
void F_23 ( void * V_10 )
{
unsigned long V_3 = ( unsigned long ) V_10 & V_11 ;
if ( V_3 >= F_14 ( V_12 ) &&
V_3 <= F_14 ( V_6 ) ) {
int V_4 , type ;
type = F_24 () ;
V_4 = type + V_5 * F_13 () ;
#ifdef F_25
F_26 ( V_3 != F_14 ( V_6 + V_4 ) ) ;
#endif
F_27 ( V_7 - V_4 , V_3 ) ;
F_28 () ;
F_19 () ;
}
#ifdef F_25
else {
F_15 ( V_3 < V_13 ) ;
F_15 ( V_3 >= ( unsigned long ) V_14 ) ;
}
#endif
F_29 () ;
}
struct V_1 * F_30 ( void * V_15 )
{
unsigned long V_4 , V_3 = ( unsigned long ) V_15 ;
T_2 * V_16 ;
if ( V_3 < V_17 )
return F_31 ( V_15 ) ;
V_4 = F_32 ( V_3 ) ;
V_16 = V_7 - ( V_4 - V_6 ) ;
return F_33 ( * V_16 ) ;
}
void T_3 F_34 ( void )
{
struct V_18 * V_18 ;
int V_19 ;
F_35 (zone) {
unsigned long V_20 , V_21 ;
if ( ! F_36 ( V_18 ) )
continue;
V_20 = V_18 -> V_20 ;
V_21 = V_20 + V_18 -> V_22 ;
V_19 = F_37 ( V_18 ) ;
F_38 ( V_23 L_1 ,
V_18 -> V_24 , V_19 , V_20 , V_21 ) ;
F_39 ( V_19 , V_20 ,
V_21 ) ;
}
V_25 += V_26 ;
}
