static void * F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
T_1 * V_5 = F_2 ( sizeof( T_1 ) , V_6 ) ;
if ( V_5 == NULL )
goto V_7;
V_5 -> V_8 = F_3 ( F_4 () ) ;
if ( V_5 -> V_8 == NULL )
goto V_7;
return V_5 ;
V_7:
ERROR ( L_1 ) ;
F_5 ( V_5 ) ;
return F_6 ( - V_9 ) ;
}
static void F_7 ( void * V_10 )
{
T_1 * V_5 = V_10 ;
if ( V_5 )
F_8 ( V_5 -> V_8 ) ;
F_5 ( V_5 ) ;
}
static int F_9 ( struct V_1 * V_11 , void * * V_12 ,
struct V_13 * * V_14 , int V_15 , int V_16 , int V_17 , int V_18 ,
int V_19 )
{
int V_20 , F_1 = 0 ;
int V_21 = 0 , V_22 = 0 ;
T_1 * V_5 = V_11 -> V_5 ;
F_10 ( & V_11 -> V_23 ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_25 = 0 ;
do {
if ( V_5 -> V_25 == 0 && V_21 < V_15 ) {
int V_26 = F_11 ( V_17 , V_11 -> V_27 - V_16 ) ;
V_17 -= V_26 ;
F_12 ( V_14 [ V_21 ] ) ;
if ( ! F_13 ( V_14 [ V_21 ] ) )
goto V_28;
V_5 -> V_29 = V_14 [ V_21 ] -> V_30 + V_16 ;
V_5 -> V_25 = V_26 ;
V_16 = 0 ;
}
if ( V_5 -> V_24 == 0 && V_22 < V_19 ) {
V_5 -> V_31 = V_12 [ V_22 ++ ] ;
V_5 -> V_24 = V_32 ;
}
if ( ! F_1 ) {
V_20 = F_14 ( V_5 ) ;
if ( V_20 != V_33 ) {
ERROR ( L_2
L_3 ,
V_20 , V_18 ) ;
goto V_28;
}
F_1 = 1 ;
}
V_20 = F_15 ( V_5 , V_34 ) ;
if ( V_5 -> V_25 == 0 && V_21 < V_15 )
F_16 ( V_14 [ V_21 ++ ] ) ;
} while ( V_20 == V_33 );
if ( V_20 != V_35 ) {
ERROR ( L_4 ) ;
goto V_28;
}
V_20 = F_17 ( V_5 ) ;
if ( V_20 != V_33 ) {
ERROR ( L_4 ) ;
goto V_28;
}
if ( V_21 < V_15 ) {
ERROR ( L_5 ) ;
goto V_28;
}
V_17 = V_5 -> V_36 ;
F_18 ( & V_11 -> V_23 ) ;
return V_17 ;
V_28:
F_18 ( & V_11 -> V_23 ) ;
for (; V_21 < V_15 ; V_21 ++ )
F_16 ( V_14 [ V_21 ] ) ;
return - V_37 ;
}
