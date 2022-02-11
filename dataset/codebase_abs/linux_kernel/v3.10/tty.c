static void * F_1 ( char * V_1 , int V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( * V_1 != ':' ) {
F_2 ( V_7 L_1
L_2 ) ;
return NULL ;
}
V_1 ++ ;
V_6 = F_3 ( sizeof( * V_6 ) , V_8 ) ;
if ( V_6 == NULL )
return NULL ;
* V_6 = ( (struct V_5 ) { . V_9 = V_1 ,
. V_10 = V_4 -> V_10 } ) ;
return V_6 ;
}
static int F_4 ( int V_11 , int V_12 , int V_13 , void * V_14 ,
char * * V_15 )
{
struct V_5 * V_6 = V_14 ;
int V_16 , V_17 , V_18 = 0 ;
if ( V_11 && V_12 )
V_18 = V_19 ;
else if ( V_11 )
V_18 = V_20 ;
else if ( V_12 )
V_18 = V_21 ;
V_16 = F_5 ( V_6 -> V_9 , V_18 ) ;
if ( V_16 < 0 )
return - V_22 ;
if ( V_6 -> V_10 ) {
F_6 ( V_17 = F_7 ( V_16 , & V_6 -> V_23 ) ) ;
if ( V_17 )
return V_17 ;
V_17 = V_10 ( V_16 ) ;
if ( V_17 )
return V_17 ;
}
* V_15 = V_6 -> V_9 ;
return V_16 ;
}
