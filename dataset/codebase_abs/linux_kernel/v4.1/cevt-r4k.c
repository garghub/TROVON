static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_4 = F_2 () ;
V_4 += V_1 ;
F_3 ( V_4 ) ;
V_5 = ( ( int ) ( F_2 () - V_4 ) >= 0 ) ? - V_6 : 0 ;
return V_5 ;
}
void F_4 ( enum V_7 V_8 ,
struct V_2 * V_3 )
{
}
static inline int F_5 ( int V_9 )
{
return ( V_10 < 0 ) &&
F_6 () == V_11 &&
! V_9 ;
}
T_1 F_7 ( int V_12 , void * V_13 )
{
const int V_9 = V_14 ;
struct V_2 * V_15 ;
int V_16 = F_8 () ;
if ( F_5 ( V_9 ) )
return V_11 ;
if ( ! V_9 || ( F_9 () & V_17 ) ) {
F_3 ( F_10 () ) ;
V_15 = & F_11 ( V_18 , V_16 ) ;
V_15 -> V_19 ( V_15 ) ;
return V_11 ;
}
return V_20 ;
}
void F_12 ( struct V_2 * V_21 )
{
}
static int F_13 ( void )
{
return ( F_9 () >> V_22 ) & ( 1ul << V_23 ) ;
}
int F_14 ( void )
{
unsigned int V_1 ;
unsigned int V_4 ;
#ifdef F_15
return 1 ;
#endif
if ( F_13 () ) {
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_16 () ;
while ( F_2 () < ( V_4 + V_24 ) )
if ( ! F_13 () )
break;
if ( F_13 () )
return 0 ;
}
for ( V_1 = 0x10 ; V_1 <= 0x400000 ; V_1 <<= 1 ) {
V_4 = F_2 () ;
V_4 += V_1 ;
F_3 ( V_4 ) ;
F_16 () ;
if ( ( int ) ( F_2 () - V_4 ) < 0 )
break;
}
while ( ( int ) ( F_2 () - V_4 ) <= 0 )
;
while ( F_2 () < ( V_4 + V_24 ) )
if ( F_13 () )
break;
if ( ! F_13 () )
return 0 ;
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_16 () ;
while ( F_2 () < ( V_4 + V_24 ) )
if ( ! F_13 () )
break;
if ( F_13 () )
return 0 ;
return 1 ;
}
int F_17 ( void )
{
unsigned int V_16 = F_8 () ;
struct V_2 * V_15 ;
unsigned int V_12 ;
if ( ! V_25 || ! V_26 )
return - V_27 ;
if ( ! F_14 () )
return - V_27 ;
V_12 = V_28 + V_29 ;
if ( V_30 )
V_12 = V_30 () ;
V_15 = & F_11 ( V_18 , V_16 ) ;
V_15 -> V_31 = L_1 ;
V_15 -> V_32 = V_33 |
V_34 |
V_35 ;
F_18 ( V_15 , V_26 ) ;
V_15 -> V_36 = F_19 ( 0x7fffffff , V_15 ) ;
V_15 -> V_37 = F_19 ( 0x300 , V_15 ) ;
V_15 -> V_38 = 300 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_39 = F_20 ( V_16 ) ;
V_15 -> V_40 = F_1 ;
V_15 -> V_41 = F_4 ;
V_15 -> V_19 = F_12 ;
F_21 ( V_15 ) ;
if ( V_42 )
return 0 ;
V_42 = 1 ;
F_22 ( V_12 , & V_43 ) ;
return 0 ;
}
