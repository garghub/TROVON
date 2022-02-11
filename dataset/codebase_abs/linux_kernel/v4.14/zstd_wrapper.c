static void * F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( V_5 == NULL )
goto V_7;
V_5 -> V_8 = F_3 ( V_9 ,
V_2 -> V_10 , V_11 ) ;
V_5 -> V_12 = F_4 ( V_5 -> V_8 ) ;
V_5 -> V_13 = F_5 ( V_5 -> V_12 ) ;
if ( V_5 -> V_13 == NULL )
goto V_7;
return V_5 ;
V_7:
ERROR ( L_1 ) ;
F_6 ( V_5 ) ;
return F_7 ( - V_14 ) ;
}
static void F_8 ( void * V_15 )
{
struct V_4 * V_5 = V_15 ;
if ( V_5 )
F_9 ( V_5 -> V_13 ) ;
F_6 ( V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 , void * V_15 ,
struct V_16 * * V_17 , int V_18 , int V_19 , int V_20 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = V_15 ;
T_1 * V_23 ;
V_9 V_24 = 0 ;
V_9 V_25 ;
int V_26 = 0 ;
T_2 V_27 = { NULL , 0 , 0 } ;
T_3 V_28 = { NULL , 0 , 0 } ;
V_23 = F_11 ( V_5 -> V_8 , V_5 -> V_13 , V_5 -> V_12 ) ;
if ( ! V_23 ) {
ERROR ( L_2 ) ;
goto V_29;
}
V_28 . V_30 = V_31 ;
V_28 . V_32 = F_12 ( V_22 ) ;
do {
if ( V_27 . V_33 == V_27 . V_30 && V_26 < V_18 ) {
int V_34 = F_13 ( V_20 , V_2 -> V_35 - V_19 ) ;
V_20 -= V_34 ;
V_27 . V_36 = V_17 [ V_26 ] -> V_37 + V_19 ;
V_27 . V_30 = V_34 ;
V_27 . V_33 = 0 ;
V_19 = 0 ;
}
if ( V_28 . V_33 == V_28 . V_30 ) {
V_28 . V_32 = F_14 ( V_22 ) ;
if ( V_28 . V_32 == NULL ) {
F_15 ( V_22 ) ;
goto V_29;
}
V_28 . V_33 = 0 ;
V_28 . V_30 = V_31 ;
}
V_24 -= V_28 . V_33 ;
V_25 = F_16 ( V_23 , & V_28 , & V_27 ) ;
V_24 += V_28 . V_33 ;
if ( V_27 . V_33 == V_27 . V_30 && V_26 < V_18 )
F_17 ( V_17 [ V_26 ++ ] ) ;
} while ( V_25 != 0 && ! F_18 ( V_25 ) );
F_15 ( V_22 ) ;
if ( F_18 ( V_25 ) ) {
ERROR ( L_3 ,
( int ) F_19 ( V_25 ) ) ;
goto V_29;
}
if ( V_26 < V_18 )
goto V_29;
return ( int ) V_24 ;
V_29:
for (; V_26 < V_18 ; V_26 ++ )
F_17 ( V_17 [ V_26 ] ) ;
return - V_38 ;
}
