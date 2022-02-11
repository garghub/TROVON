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
int F_16 ( void )
{
unsigned int V_14 = F_6 () ;
struct V_2 * V_13 ;
unsigned int V_9 ;
if ( ! V_23 || ! V_24 )
return - V_25 ;
if ( ! F_13 () )
return - V_25 ;
V_9 = V_26 + V_27 ;
if ( V_28 )
V_9 = V_28 () ;
V_13 = & F_10 ( V_16 , V_14 ) ;
V_13 -> V_29 = L_1 ;
V_13 -> V_30 = V_31 |
V_32 |
V_33 ;
F_17 ( V_13 , V_24 ) ;
V_13 -> V_34 = F_18 ( 0x7fffffff , V_13 ) ;
V_13 -> V_35 = F_18 ( 0x300 , V_13 ) ;
V_13 -> V_36 = 300 ;
V_13 -> V_9 = V_9 ;
V_13 -> V_37 = F_19 ( V_14 ) ;
V_13 -> V_38 = F_1 ;
V_13 -> V_39 = F_4 ;
V_13 -> V_17 = F_11 ;
F_20 ( V_13 ) ;
if ( V_40 )
return 0 ;
V_40 = 1 ;
F_21 ( V_9 , & V_41 ) ;
return 0 ;
}
