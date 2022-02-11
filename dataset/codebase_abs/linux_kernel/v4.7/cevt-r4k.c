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
static unsigned int F_4 ( void )
{
unsigned int V_4 , V_7 , V_8 , V_9 , V_10 ;
unsigned int V_11 [ 4 ] , V_12 [ 3 ] ;
unsigned int V_13 ;
for ( V_7 = 0 ; V_7 < 5 ; ++ V_7 ) {
for ( V_8 = 0 ; V_8 < 5 ; ++ V_8 ) {
V_4 = F_2 () ;
F_3 ( V_4 ) ;
V_4 = F_2 () - V_4 ;
for ( V_9 = 0 ; V_9 < V_8 ; ++ V_9 ) {
if ( V_4 < V_11 [ V_9 ] ) {
V_10 = F_5 (unsigned int,
j, ARRAY_SIZE(buf1) - 1 ) ;
for (; V_10 > V_9 ; -- V_10 )
V_11 [ V_10 ] = V_11 [ V_10 - 1 ] ;
break;
}
}
if ( V_9 < F_6 ( V_11 ) )
V_11 [ V_9 ] = V_4 ;
}
for ( V_9 = 0 ; V_9 < V_7 ; ++ V_9 ) {
if ( V_11 [ F_6 ( V_11 ) - 1 ] < V_12 [ V_9 ] ) {
V_10 = F_5 (unsigned int,
i, ARRAY_SIZE(buf2) - 1 ) ;
for (; V_10 > V_9 ; -- V_10 )
V_12 [ V_10 ] = V_12 [ V_10 - 1 ] ;
break;
}
}
if ( V_9 < F_6 ( V_12 ) )
V_12 [ V_9 ] = V_11 [ F_6 ( V_11 ) - 1 ] ;
}
V_13 = V_12 [ F_6 ( V_12 ) - 1 ] * 2 ;
if ( V_13 < 0x300 )
V_13 = 0x300 ;
F_7 ( L_1 ,
V_14 , V_12 [ F_6 ( V_12 ) - 1 ] , V_13 ) ;
return V_13 ;
}
static inline int F_8 ( int V_15 )
{
return ( V_16 < 0 ) &&
F_9 () == V_17 &&
! V_15 ;
}
T_1 F_10 ( int V_18 , void * V_19 )
{
const int V_15 = V_20 ;
struct V_2 * V_21 ;
int V_22 = F_11 () ;
if ( F_8 ( V_15 ) )
return V_17 ;
if ( ! V_15 || ( F_12 () & V_23 ) ) {
F_3 ( F_13 () ) ;
V_21 = & F_14 ( V_24 , V_22 ) ;
V_21 -> V_25 ( V_21 ) ;
return V_17 ;
}
return V_26 ;
}
void F_15 ( struct V_2 * V_27 )
{
}
static int F_16 ( void )
{
return ( F_12 () >> V_28 ) & ( 1ul << V_29 ) ;
}
int F_17 ( void )
{
unsigned int V_1 ;
unsigned int V_4 ;
#ifdef F_18
return 1 ;
#endif
if ( F_16 () ) {
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_19 () ;
while ( F_2 () < ( V_4 + V_30 ) )
if ( ! F_16 () )
break;
if ( F_16 () )
return 0 ;
}
for ( V_1 = 0x10 ; V_1 <= 0x400000 ; V_1 <<= 1 ) {
V_4 = F_2 () ;
V_4 += V_1 ;
F_3 ( V_4 ) ;
F_19 () ;
if ( ( int ) ( F_2 () - V_4 ) < 0 )
break;
}
while ( ( int ) ( F_2 () - V_4 ) <= 0 )
;
while ( F_2 () < ( V_4 + V_30 ) )
if ( F_16 () )
break;
if ( ! F_16 () )
return 0 ;
V_4 = F_2 () ;
F_3 ( V_4 ) ;
F_19 () ;
while ( F_2 () < ( V_4 + V_30 ) )
if ( ! F_16 () )
break;
if ( F_16 () )
return 0 ;
return 1 ;
}
unsigned int __weak F_20 ( void )
{
return V_31 + V_32 ;
}
int F_21 ( void )
{
unsigned int V_22 = F_11 () ;
struct V_2 * V_21 ;
unsigned int V_18 , V_13 ;
if ( ! V_33 || ! V_34 )
return - V_35 ;
if ( ! F_17 () )
return - V_35 ;
V_18 = F_20 () ;
V_21 = & F_14 ( V_24 , V_22 ) ;
V_21 -> V_36 = L_2 ;
V_21 -> V_37 = V_38 |
V_39 |
V_40 ;
F_22 ( V_21 , V_34 ) ;
V_21 -> V_41 = F_23 ( 0x7fffffff , V_21 ) ;
V_13 = F_4 () ;
V_21 -> V_42 = F_23 ( V_13 , V_21 ) ;
V_21 -> V_43 = 300 ;
V_21 -> V_18 = V_18 ;
V_21 -> V_44 = F_24 ( V_22 ) ;
V_21 -> V_45 = F_1 ;
V_21 -> V_25 = F_15 ;
F_25 ( V_21 ) ;
if ( V_46 )
return 0 ;
V_46 = 1 ;
F_26 ( V_18 , & V_47 ) ;
return 0 ;
}
