static int F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned long V_3 )
{
long V_4 , V_5 ;
V_4 = F_2 ( V_2 ) ;
V_1 = V_1 + V_4 ;
for (; V_4 < V_6 ; V_1 ++ , V_4 ++ ) {
unsigned long V_7 ;
T_2 * V_8 ;
V_7 = V_2 + V_4 * V_9 ;
if ( V_7 >= V_3 )
break;
V_8 = ( T_2 * ) F_3 ( V_10 ) ;
if ( ! V_8 )
return - V_11 ;
F_4 ( V_1 , F_5 ( F_6 ( V_8 ) | V_12 ) ) ;
for ( V_5 = 0 ; V_5 < V_13 ; V_8 ++ , V_5 ++ , V_7 += V_14 ) {
unsigned long V_15 ;
if ( V_7 >= V_3 )
break;
V_15 = V_16 | V_7 ;
V_15 &= V_17 ;
F_7 ( V_8 , F_8 ( V_15 ) ) ;
}
}
return 0 ;
}
static int F_9 ( void )
{
unsigned long V_18 , V_3 , V_19 ;
int error ;
V_20 = ( V_21 * ) F_3 ( V_10 ) ;
if ( ! V_20 )
return - V_11 ;
F_10 ( V_20 + F_11 ( V_22 ) ,
V_23 [ F_11 ( V_22 ) ] ) ;
V_18 = ( unsigned long ) F_12 ( 0 ) ;
V_3 = ( unsigned long ) F_12 ( V_24 ) ;
for (; V_18 < V_3 ; V_18 = V_19 ) {
T_1 * V_1 = ( T_1 * ) F_3 ( V_10 ) ;
if ( ! V_1 )
return - V_11 ;
V_19 = V_18 + V_25 ;
if ( V_19 > V_3 )
V_19 = V_3 ;
if ( ( error = F_1 ( V_1 , F_6 ( V_18 ) , F_6 ( V_19 ) ) ) )
return error ;
F_10 ( V_20 + F_11 ( V_18 ) ,
F_13 ( F_6 ( V_1 ) ) ) ;
}
return 0 ;
}
int F_14 ( void )
{
int error ;
if ( ( error = F_9 () ) )
return error ;
V_26 = ( void * ) F_3 ( V_10 ) ;
if ( ! V_26 )
return - V_11 ;
memcpy ( V_26 , & V_27 ,
& V_28 - & V_27 ) ;
F_15 () ;
return 0 ;
}
int F_16 ( unsigned long V_29 )
{
unsigned long V_30 = F_17 ( & V_31 ) >> V_32 ;
unsigned long V_33 = F_18 ( F_17 ( & V_34 ) ) >> V_32 ;
return ( V_29 >= V_30 ) && ( V_29 < V_33 ) ;
}
int F_19 ( void * V_35 , unsigned int V_36 )
{
struct V_37 * V_38 = V_35 ;
if ( V_36 < sizeof( struct V_37 ) )
return - V_39 ;
V_38 -> V_40 = V_41 ;
V_38 -> V_42 = V_43 ;
V_38 -> V_44 = V_45 ;
return 0 ;
}
int F_20 ( void * V_35 )
{
struct V_37 * V_38 = V_35 ;
V_41 = V_38 -> V_40 ;
V_43 = V_38 -> V_42 ;
return ( V_38 -> V_44 == V_45 ) ? 0 : - V_46 ;
}
