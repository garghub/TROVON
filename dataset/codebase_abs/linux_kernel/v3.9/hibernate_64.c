static void * F_1 ( void * V_1 )
{
return ( void * ) F_2 ( V_2 ) ;
}
static int F_3 ( void )
{
struct V_3 V_4 = {
. F_1 = F_1 ,
. V_5 = V_6 ,
. V_7 = true ,
} ;
unsigned long V_8 , V_9 ;
int V_10 ;
int V_11 ;
V_12 = ( V_13 * ) F_2 ( V_2 ) ;
if ( ! V_12 )
return - V_14 ;
F_4 ( V_12 + F_5 ( V_15 ) ,
V_16 [ F_5 ( V_15 ) ] ) ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ ) {
V_8 = V_18 [ V_11 ] . V_19 << V_20 ;
V_9 = V_18 [ V_11 ] . V_21 << V_20 ;
V_10 = F_6 ( & V_4 , V_12 ,
V_8 , V_9 ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
int F_7 ( void )
{
int error ;
if ( ( error = F_3 () ) )
return error ;
V_22 = ( void * ) F_2 ( V_2 ) ;
if ( ! V_22 )
return - V_14 ;
memcpy ( V_22 , & V_23 ,
& V_24 - & V_23 ) ;
F_8 () ;
return 0 ;
}
int F_9 ( unsigned long V_25 )
{
unsigned long V_26 = F_10 ( & V_27 ) >> V_20 ;
unsigned long V_28 = F_11 ( F_10 ( & V_29 ) ) >> V_20 ;
return ( V_25 >= V_26 ) && ( V_25 < V_28 ) ;
}
int F_12 ( void * V_30 , unsigned int V_31 )
{
struct V_32 * V_33 = V_30 ;
if ( V_31 < sizeof( struct V_32 ) )
return - V_34 ;
V_33 -> V_35 = V_36 ;
V_33 -> V_37 = V_38 ;
V_33 -> V_39 = V_40 ;
return 0 ;
}
int F_13 ( void * V_30 )
{
struct V_32 * V_33 = V_30 ;
V_36 = V_33 -> V_35 ;
V_38 = V_33 -> V_37 ;
return ( V_33 -> V_39 == V_40 ) ? 0 : - V_41 ;
}
