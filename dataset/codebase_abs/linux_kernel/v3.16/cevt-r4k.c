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
T_1 F_5 ( int V_9 , void * V_10 )
{
const int V_11 = V_12 ;
struct V_2 * V_13 ;
int V_14 = F_6 () ;
if ( F_7 ( V_11 ) )
goto V_15;
if ( ! V_11 || ( F_8 () & ( 1 << 30 ) ) ) {
F_3 ( F_9 () ) ;
V_13 = & F_10 ( V_16 , V_14 ) ;
V_13 -> V_17 ( V_13 ) ;
}
V_15:
return V_18 ;
}
void F_11 ( struct V_2 * V_19 )
{
}
static int F_12 ( void )
{
#ifdef F_13
if ( V_20 )
return F_14 () ;
#endif
return ( F_8 () >> V_21 ) & ( 1ul << V_22 ) ;
}
int F_15 ( void )
{
unsigned int V_1 ;
unsigned int V_4 ;
#ifdef F_16
return 1 ;
#endif
if ( F_12 () ) {
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_17 () ;
while ( F_2 () < ( V_4 + V_23 ) )
if ( ! F_12 () )
break;
if ( F_12 () )
return 0 ;
}
for ( V_1 = 0x10 ; V_1 <= 0x400000 ; V_1 <<= 1 ) {
V_4 = F_2 () ;
V_4 += V_1 ;
F_3 ( V_4 ) ;
F_17 () ;
if ( ( int ) ( F_2 () - V_4 ) < 0 )
break;
}
while ( ( int ) ( F_2 () - V_4 ) <= 0 )
;
while ( F_2 () < ( V_4 + V_23 ) )
if ( F_12 () )
break;
if ( ! F_12 () )
return 0 ;
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_17 () ;
while ( F_2 () < ( V_4 + V_23 ) )
if ( ! F_12 () )
break;
if ( F_12 () )
return 0 ;
return 1 ;
}
int F_18 ( void )
{
unsigned int V_14 = F_6 () ;
struct V_2 * V_13 ;
unsigned int V_9 ;
if ( ! V_24 || ! V_25 )
return - V_26 ;
if ( ! F_15 () )
return - V_26 ;
V_9 = V_27 + V_28 ;
if ( V_29 )
V_9 = V_29 () ;
V_13 = & F_10 ( V_16 , V_14 ) ;
V_13 -> V_30 = L_1 ;
V_13 -> V_31 = V_32 |
V_33 |
V_34 ;
F_19 ( V_13 , V_25 ) ;
V_13 -> V_35 = F_20 ( 0x7fffffff , V_13 ) ;
V_13 -> V_36 = F_20 ( 0x300 , V_13 ) ;
V_13 -> V_37 = 300 ;
V_13 -> V_9 = V_9 ;
V_13 -> V_38 = F_21 ( V_14 ) ;
V_13 -> V_39 = F_1 ;
V_13 -> V_40 = F_4 ;
V_13 -> V_17 = F_11 ;
F_22 ( V_13 ) ;
if ( V_41 )
return 0 ;
V_41 = 1 ;
F_23 ( V_9 , & V_42 ) ;
return 0 ;
}
