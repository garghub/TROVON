static void * F_1 ( struct V_1 * V_2 ,
void * V_3 , int V_4 )
{
struct F_1 * V_5 = V_3 ;
if ( V_5 == NULL || V_4 < sizeof( * V_5 ) )
return F_2 ( - V_6 ) ;
if ( F_3 ( V_5 -> V_7 ) != V_8 ) {
ERROR ( L_1 ) ;
return F_2 ( - V_9 ) ;
}
return NULL ;
}
static void * F_4 ( struct V_1 * V_2 , void * V_3 )
{
int V_10 = F_5 ( int , V_2 -> V_10 , V_11 ) ;
struct V_12 * V_13 ;
V_13 = F_6 ( sizeof( * V_13 ) , V_14 ) ;
if ( V_13 == NULL )
goto V_15;
V_13 -> V_16 = F_7 ( V_10 ) ;
if ( V_13 -> V_16 == NULL )
goto V_17;
V_13 -> V_18 = F_7 ( V_10 ) ;
if ( V_13 -> V_18 == NULL )
goto V_19;
return V_13 ;
V_19:
F_8 ( V_13 -> V_16 ) ;
V_17:
F_9 ( V_13 ) ;
V_15:
ERROR ( L_2 ) ;
return F_2 ( - V_20 ) ;
}
static void F_10 ( void * V_21 )
{
struct V_12 * V_13 = V_21 ;
if ( V_13 ) {
F_8 ( V_13 -> V_16 ) ;
F_8 ( V_13 -> V_18 ) ;
}
F_9 ( V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_21 ,
struct V_22 * * V_23 , int V_24 , int V_25 , int V_26 ,
struct V_27 * V_18 )
{
struct V_12 * V_13 = V_21 ;
void * V_3 = V_13 -> V_16 , * V_28 ;
int V_29 , V_30 , V_31 = V_26 , V_32 ;
T_1 V_33 = V_18 -> V_26 ;
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ ) {
V_29 = F_12 ( V_31 , V_2 -> V_34 - V_25 ) ;
memcpy ( V_3 , V_23 [ V_30 ] -> V_35 + V_25 , V_29 ) ;
V_3 += V_29 ;
V_31 -= V_29 ;
V_25 = 0 ;
F_13 ( V_23 [ V_30 ] ) ;
}
V_32 = F_14 ( V_13 -> V_16 , V_26 ,
V_13 -> V_18 , & V_33 ) ;
if ( V_32 )
return - V_6 ;
V_31 = V_33 ;
V_28 = F_15 ( V_18 ) ;
V_3 = V_13 -> V_18 ;
while ( V_28 ) {
if ( V_31 <= V_36 ) {
memcpy ( V_28 , V_3 , V_31 ) ;
break;
}
memcpy ( V_28 , V_3 , V_36 ) ;
V_3 += V_36 ;
V_31 -= V_36 ;
V_28 = F_16 ( V_18 ) ;
}
F_17 ( V_18 ) ;
return V_33 ;
}
