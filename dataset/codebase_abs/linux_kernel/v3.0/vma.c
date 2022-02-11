static int T_1 F_1 ( void )
{
int V_1 = ( V_2 - V_3 + V_4 - 1 ) / V_4 ;
int V_5 ;
V_6 = V_1 << V_7 ;
V_8 = F_2 ( sizeof( struct V_9 * ) * V_1 , V_10 ) ;
if ( ! V_8 )
goto V_11;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
struct V_9 * V_12 ;
V_12 = F_3 ( V_10 ) ;
if ( ! V_12 )
goto V_11;
V_8 [ V_5 ] = V_12 ;
F_4 ( F_5 ( V_12 ) , V_3 + V_5 * V_4 ) ;
}
return 0 ;
V_11:
F_6 ( L_1 ) ;
V_13 = 0 ;
return - V_14 ;
}
static unsigned long F_7 ( unsigned long V_15 , unsigned V_16 )
{
unsigned long V_17 , V_18 ;
unsigned V_19 ;
V_18 = ( V_15 + V_20 - 1 ) & V_21 ;
if ( V_18 >= V_22 )
V_18 = V_22 ;
V_18 -= V_16 ;
V_19 = F_8 () & ( V_23 - 1 ) ;
V_17 = V_15 + ( V_19 << V_7 ) ;
if ( V_17 >= V_18 )
V_17 = V_18 ;
return V_17 ;
}
int F_9 ( struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = V_29 -> V_28 ;
unsigned long V_17 ;
int V_30 ;
if ( ! V_13 )
return 0 ;
F_10 ( & V_28 -> V_31 ) ;
V_17 = F_7 ( V_28 -> V_32 , V_6 ) ;
V_17 = F_11 ( NULL , V_17 , V_6 , 0 , 0 ) ;
if ( F_12 ( V_17 ) ) {
V_30 = V_17 ;
goto V_33;
}
V_29 -> V_28 -> V_34 . V_35 = ( void * ) V_17 ;
V_30 = F_13 ( V_28 , V_17 , V_6 ,
V_36 | V_37 |
V_38 | V_39 | V_40 |
V_41 ,
V_8 ) ;
if ( V_30 ) {
V_29 -> V_28 -> V_34 . V_35 = NULL ;
goto V_33;
}
V_33:
F_14 ( & V_28 -> V_31 ) ;
return V_30 ;
}
static T_1 int F_15 ( char * V_42 )
{
V_13 = F_16 ( V_42 , NULL , 0 ) ;
return 0 ;
}
