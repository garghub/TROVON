static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
V_3 = F_3 ( V_1 , & V_1 ) ;
if ( * V_1 != '@' )
return 0 ;
V_4 = F_3 ( V_1 + 1 , & V_1 ) ;
if ( * V_1 != '-' ) {
V_5 = V_4 + V_3 ;
return 0 ;
}
V_5 = F_3 ( V_1 + 1 , & V_1 ) ;
return 0 ;
}
static T_2 T_1 T_3 F_4 ( void )
{
struct V_6 * V_7 ;
unsigned long V_8 = 0 ;
F_5 (memory, reg)
V_8 += F_6 ( V_7 ) -
F_7 ( V_7 ) ;
return ( V_8 * V_9 / 100 ) << V_10 ;
}
static inline T_3 T_2 F_4 ( void )
{
return 0 ;
}
void T_1 F_8 ( T_2 V_11 )
{
T_2 V_12 = 0 ;
T_2 V_13 = 0 ;
T_2 V_14 = V_11 ;
bool V_15 = false ;
F_2 ( L_2 , V_2 , ( unsigned long ) V_11 ) ;
if ( V_3 != - 1 ) {
V_12 = V_3 ;
V_13 = V_4 ;
V_14 = F_9 ( V_5 , V_11 ) ;
if ( V_4 + V_3 == V_5 )
V_15 = true ;
} else {
#ifdef F_10
V_12 = V_16 ;
#elif F_11 ( V_17 )
V_12 = F_4 () ;
#elif F_11 ( V_18 )
V_12 = F_12 ( V_16 , F_4 () ) ;
#elif F_11 ( V_19 )
V_12 = F_13 ( V_16 , F_4 () ) ;
#endif
}
if ( V_12 && ! V_20 ) {
F_2 ( L_3 , V_2 ,
( unsigned long ) V_12 / V_21 ) ;
F_14 ( V_12 , V_13 ,
V_14 ,
& V_20 ,
V_15 ) ;
}
}
int T_1 F_14 ( T_2 V_22 , T_2 V_23 ,
T_2 V_11 , struct V_24 * * V_25 ,
bool V_15 )
{
int V_26 ;
V_26 = F_15 ( V_23 , V_22 , V_11 , 0 , 0 , V_15 , V_25 ) ;
if ( V_26 )
return V_26 ;
F_16 ( F_17 ( * V_25 ) ,
F_18 ( * V_25 ) ) ;
return 0 ;
}
struct V_27 * F_19 ( struct V_28 * V_29 , int V_30 ,
unsigned int V_31 )
{
if ( V_31 > V_32 )
V_31 = V_32 ;
return F_20 ( F_21 ( V_29 ) , V_30 , V_31 ) ;
}
bool F_22 ( struct V_28 * V_29 , struct V_27 * V_33 ,
int V_30 )
{
return F_23 ( F_21 ( V_29 ) , V_33 , V_30 ) ;
}
