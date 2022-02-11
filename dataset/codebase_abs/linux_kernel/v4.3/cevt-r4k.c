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
static inline int F_4 ( int V_7 )
{
return ( V_8 < 0 ) &&
F_5 () == V_9 &&
! V_7 ;
}
T_1 F_6 ( int V_10 , void * V_11 )
{
const int V_7 = V_12 ;
struct V_2 * V_13 ;
int V_14 = F_7 () ;
if ( F_4 ( V_7 ) )
return V_9 ;
if ( ! V_7 || ( F_8 () & V_15 ) ) {
F_3 ( F_9 () ) ;
V_13 = & F_10 ( V_16 , V_14 ) ;
V_13 -> V_17 ( V_13 ) ;
return V_9 ;
}
return V_18 ;
}
void F_11 ( struct V_2 * V_19 )
{
}
static int F_12 ( void )
{
return ( F_8 () >> V_20 ) & ( 1ul << V_21 ) ;
}
int F_13 ( void )
{
unsigned int V_1 ;
unsigned int V_4 ;
#ifdef F_14
return 1 ;
#endif
if ( F_12 () ) {
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_15 () ;
while ( F_2 () < ( V_4 + V_22 ) )
if ( ! F_12 () )
break;
if ( F_12 () )
return 0 ;
}
for ( V_1 = 0x10 ; V_1 <= 0x400000 ; V_1 <<= 1 ) {
V_4 = F_2 () ;
V_4 += V_1 ;
F_3 ( V_4 ) ;
F_15 () ;
if ( ( int ) ( F_2 () - V_4 ) < 0 )
break;
}
while ( ( int ) ( F_2 () - V_4 ) <= 0 )
;
while ( F_2 () < ( V_4 + V_22 ) )
if ( F_12 () )
break;
if ( ! F_12 () )
return 0 ;
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_15 () ;
while ( F_2 () < ( V_4 + V_22 ) )
if ( ! F_12 () )
break;
if ( F_12 () )
return 0 ;
return 1 ;
}
unsigned int __weak F_16 ( void )
{
return V_23 + V_24 ;
}
int F_17 ( void )
{
unsigned int V_14 = F_7 () ;
struct V_2 * V_13 ;
unsigned int V_10 ;
if ( ! V_25 || ! V_26 )
return - V_27 ;
if ( ! F_13 () )
return - V_27 ;
V_10 = F_16 () ;
V_13 = & F_10 ( V_16 , V_14 ) ;
V_13 -> V_28 = L_1 ;
V_13 -> V_29 = V_30 |
V_31 |
V_32 ;
F_18 ( V_13 , V_26 ) ;
V_13 -> V_33 = F_19 ( 0x7fffffff , V_13 ) ;
V_13 -> V_34 = F_19 ( 0x300 , V_13 ) ;
V_13 -> V_35 = 300 ;
V_13 -> V_10 = V_10 ;
V_13 -> V_36 = F_20 ( V_14 ) ;
V_13 -> V_37 = F_1 ;
V_13 -> V_17 = F_11 ;
F_21 ( V_13 ) ;
if ( V_38 )
return 0 ;
V_38 = 1 ;
F_22 ( V_10 , & V_39 ) ;
return 0 ;
}
