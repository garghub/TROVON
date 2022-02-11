static void * F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 = F_2 ( int , V_2 -> V_4 , V_5 ) ;
struct V_6 * V_7 = F_3 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL )
goto V_9;
V_7 -> V_10 = F_4 ( V_4 ) ;
if ( V_7 -> V_10 == NULL )
goto V_9;
V_7 -> V_11 = F_4 ( V_4 ) ;
if ( V_7 -> V_11 == NULL )
goto V_12;
return V_7 ;
V_12:
F_5 ( V_7 -> V_10 ) ;
V_9:
ERROR ( L_1 ) ;
F_6 ( V_7 ) ;
return F_7 ( - V_13 ) ;
}
static void F_8 ( void * V_14 )
{
struct V_6 * V_7 = V_14 ;
if ( V_7 ) {
F_5 ( V_7 -> V_10 ) ;
F_5 ( V_7 -> V_11 ) ;
}
F_6 ( V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 , void * V_14 ,
struct V_15 * * V_16 , int V_17 , int V_18 , int V_19 ,
struct V_20 * V_11 )
{
struct V_6 * V_7 = V_14 ;
void * V_3 = V_7 -> V_10 , * V_21 ;
int V_22 , V_23 , V_24 = V_19 , V_25 ;
T_1 V_26 = V_11 -> V_19 ;
for ( V_23 = 0 ; V_23 < V_17 ; V_23 ++ ) {
V_22 = F_10 ( V_24 , V_2 -> V_27 - V_18 ) ;
memcpy ( V_3 , V_16 [ V_23 ] -> V_28 + V_18 , V_22 ) ;
V_3 += V_22 ;
V_24 -= V_22 ;
V_18 = 0 ;
F_11 ( V_16 [ V_23 ] ) ;
}
V_25 = F_12 ( V_7 -> V_10 , ( T_1 ) V_19 ,
V_7 -> V_11 , & V_26 ) ;
if ( V_25 != V_29 )
goto V_9;
V_25 = V_24 = ( int ) V_26 ;
V_21 = F_13 ( V_11 ) ;
V_3 = V_7 -> V_11 ;
while ( V_21 ) {
if ( V_24 <= V_30 ) {
memcpy ( V_21 , V_3 , V_24 ) ;
break;
} else {
memcpy ( V_21 , V_3 , V_30 ) ;
V_3 += V_30 ;
V_24 -= V_30 ;
V_21 = F_14 ( V_11 ) ;
}
}
F_15 ( V_11 ) ;
return V_25 ;
V_9:
return - V_31 ;
}
