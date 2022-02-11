static void * F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = F_2 ( sizeof( T_1 ) , V_5 ) ;
if ( V_4 == NULL )
goto V_6;
V_4 -> V_7 = F_3 ( F_4 () ) ;
if ( V_4 -> V_7 == NULL )
goto V_6;
return V_4 ;
V_6:
ERROR ( L_1 ) ;
F_5 ( V_4 ) ;
return F_6 ( - V_8 ) ;
}
static void F_7 ( void * V_9 )
{
T_1 * V_4 = V_9 ;
if ( V_4 )
F_8 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_10 , void * V_9 ,
struct V_11 * * V_12 , int V_13 , int V_14 , int V_15 ,
struct V_16 * V_17 )
{
int V_18 , F_1 = 0 , V_19 = 0 ;
T_1 * V_4 = V_9 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = F_10 ( V_17 ) ;
V_4 -> V_23 = 0 ;
do {
if ( V_4 -> V_23 == 0 && V_19 < V_13 ) {
int V_24 = F_11 ( V_15 , V_10 -> V_25 - V_14 ) ;
V_15 -= V_24 ;
V_4 -> V_26 = V_12 [ V_19 ] -> V_27 + V_14 ;
V_4 -> V_23 = V_24 ;
V_14 = 0 ;
}
if ( V_4 -> V_20 == 0 ) {
V_4 -> V_22 = F_12 ( V_17 ) ;
if ( V_4 -> V_22 != NULL )
V_4 -> V_20 = V_21 ;
}
if ( ! F_1 ) {
V_18 = F_13 ( V_4 ) ;
if ( V_18 != V_28 ) {
F_14 ( V_17 ) ;
goto V_29;
}
F_1 = 1 ;
}
V_18 = F_15 ( V_4 , V_30 ) ;
if ( V_4 -> V_23 == 0 && V_19 < V_13 )
F_16 ( V_12 [ V_19 ++ ] ) ;
} while ( V_18 == V_28 );
F_14 ( V_17 ) ;
if ( V_18 != V_31 )
goto V_29;
V_18 = F_17 ( V_4 ) ;
if ( V_18 != V_28 )
goto V_29;
if ( V_19 < V_13 )
goto V_29;
return V_4 -> V_32 ;
V_29:
for (; V_19 < V_13 ; V_19 ++ )
F_16 ( V_12 [ V_19 ] ) ;
return - V_33 ;
}
