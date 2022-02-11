static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_5 )
{
T_1 V_6 ;
unsigned int V_7 , V_8 = 0 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
F_2 ( L_1 , __FILE__ ) ;
if ( F_3 ( V_3 ) ) {
F_2 ( L_2 ) ;
return - V_12 ;
}
if ( V_5 -> V_13 ) {
F_2 ( L_3 ) ;
return 0 ;
}
if ( V_5 -> V_14 >= V_15 ) {
V_7 = V_5 -> V_14 >> V_16 ;
V_5 -> V_17 = V_18 ;
} else if ( V_5 -> V_14 >= V_19 ) {
V_7 = V_5 -> V_14 >> 16 ;
V_5 -> V_17 = V_19 ;
} else {
V_7 = V_5 -> V_14 >> V_20 ;
V_5 -> V_17 = V_21 ;
}
V_5 -> V_22 = F_4 ( sizeof( struct V_23 ) , V_24 ) ;
if ( ! V_5 -> V_22 ) {
F_5 ( L_4 ) ;
return - V_25 ;
}
V_11 = F_6 ( V_5 -> V_22 , V_7 , V_24 ) ;
if ( V_11 < 0 ) {
F_5 ( L_5 ) ;
F_7 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
return - V_25 ;
}
V_5 -> V_26 = F_8 ( V_2 -> V_2 , V_5 -> V_14 ,
& V_5 -> V_13 , V_24 ) ;
if ( ! V_5 -> V_26 ) {
F_5 ( L_6 ) ;
V_11 = - V_25 ;
goto V_27;
}
V_5 -> V_28 = F_4 ( sizeof( struct V_29 ) * V_7 , V_24 ) ;
if ( ! V_5 -> V_28 ) {
F_5 ( L_7 ) ;
V_11 = - V_25 ;
goto V_30;
}
V_10 = V_5 -> V_22 -> V_10 ;
V_6 = V_5 -> V_13 ;
while ( V_8 < V_7 ) {
V_5 -> V_28 [ V_8 ] = F_9 ( V_6 ) ;
F_10 ( V_10 , V_5 -> V_28 [ V_8 ] , V_5 -> V_17 , 0 ) ;
F_11 ( V_10 ) = V_6 ;
V_6 += V_5 -> V_17 ;
V_10 = F_12 ( V_10 ) ;
V_8 ++ ;
}
F_2 ( L_8 ,
( unsigned long ) V_5 -> V_26 ,
( unsigned long ) V_5 -> V_13 ,
V_5 -> V_14 ) ;
return V_11 ;
V_30:
F_13 ( V_2 -> V_2 , V_5 -> V_14 , V_5 -> V_26 ,
( T_1 ) V_5 -> V_13 ) ;
V_5 -> V_13 = ( T_1 ) NULL ;
V_27:
F_14 ( V_5 -> V_22 ) ;
F_7 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
return V_11 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_5 )
{
F_2 ( L_9 , __FILE__ ) ;
if ( F_3 ( V_3 ) ) {
F_2 ( L_2 ) ;
return;
}
if ( ! V_5 -> V_13 ) {
F_2 ( L_10 ) ;
return;
}
F_2 ( L_8 ,
( unsigned long ) V_5 -> V_26 ,
( unsigned long ) V_5 -> V_13 ,
V_5 -> V_14 ) ;
F_14 ( V_5 -> V_22 ) ;
F_7 ( V_5 -> V_22 ) ;
V_5 -> V_22 = NULL ;
F_7 ( V_5 -> V_28 ) ;
V_5 -> V_28 = NULL ;
F_13 ( V_2 -> V_2 , V_5 -> V_14 , V_5 -> V_26 ,
( T_1 ) V_5 -> V_13 ) ;
V_5 -> V_13 = ( T_1 ) NULL ;
}
struct V_4 * F_16 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_4 * V_31 ;
F_2 ( L_9 , __FILE__ ) ;
F_2 ( L_11 , V_14 ) ;
V_31 = F_4 ( sizeof( * V_31 ) , V_24 ) ;
if ( ! V_31 ) {
F_5 ( L_12 ) ;
return NULL ;
}
V_31 -> V_14 = V_14 ;
return V_31 ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_4 * V_31 )
{
F_2 ( L_9 , __FILE__ ) ;
if ( ! V_31 ) {
F_2 ( L_13 ) ;
return;
}
F_7 ( V_31 ) ;
V_31 = NULL ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_4 * V_5 , unsigned int V_3 )
{
if ( F_1 ( V_2 , V_3 , V_5 ) < 0 )
return - V_25 ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_31 )
{
F_15 ( V_2 , V_3 , V_31 ) ;
}
