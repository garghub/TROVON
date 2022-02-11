static void * F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
int V_5 = F_2 ( int , V_2 -> V_5 , V_6 ) ;
struct V_7 * V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 == NULL )
goto V_10;
V_8 -> V_11 = F_4 ( V_5 ) ;
if ( V_8 -> V_11 == NULL )
goto V_10;
V_8 -> V_12 = F_4 ( V_5 ) ;
if ( V_8 -> V_12 == NULL )
goto V_13;
return V_8 ;
V_13:
F_5 ( V_8 -> V_11 ) ;
V_10:
ERROR ( L_1 ) ;
F_6 ( V_8 ) ;
return F_7 ( - V_14 ) ;
}
static void F_8 ( void * V_15 )
{
struct V_7 * V_8 = V_15 ;
if ( V_8 ) {
F_5 ( V_8 -> V_11 ) ;
F_5 ( V_8 -> V_12 ) ;
}
F_6 ( V_8 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * * V_16 ,
struct V_17 * * V_18 , int V_19 , int V_20 , int V_21 , int V_22 ,
int V_23 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
void * V_3 = V_8 -> V_11 ;
int V_24 , V_25 , V_26 = V_21 , V_27 ;
T_1 V_28 = V_22 ;
F_10 ( & V_2 -> V_29 ) ;
for ( V_25 = 0 ; V_25 < V_19 ; V_25 ++ ) {
F_11 ( V_18 [ V_25 ] ) ;
if ( ! F_12 ( V_18 [ V_25 ] ) )
goto V_30;
V_24 = F_13 ( V_26 , V_2 -> V_31 - V_20 ) ;
memcpy ( V_3 , V_18 [ V_25 ] -> V_32 + V_20 , V_24 ) ;
V_3 += V_24 ;
V_26 -= V_24 ;
V_20 = 0 ;
F_14 ( V_18 [ V_25 ] ) ;
}
V_27 = F_15 ( V_8 -> V_11 , ( T_1 ) V_21 ,
V_8 -> V_12 , & V_28 ) ;
if ( V_27 != V_33 )
goto V_10;
V_27 = V_26 = ( int ) V_28 ;
for ( V_25 = 0 , V_3 = V_8 -> V_12 ; V_26 && V_25 < V_23 ; V_25 ++ ) {
V_24 = F_16 ( int , V_26 , V_34 ) ;
memcpy ( V_16 [ V_25 ] , V_3 , V_24 ) ;
V_3 += V_24 ;
V_26 -= V_24 ;
}
F_17 ( & V_2 -> V_29 ) ;
return V_27 ;
V_30:
for (; V_25 < V_19 ; V_25 ++ )
F_14 ( V_18 [ V_25 ] ) ;
V_10:
F_17 ( & V_2 -> V_29 ) ;
ERROR ( L_2 ) ;
return - V_35 ;
}
