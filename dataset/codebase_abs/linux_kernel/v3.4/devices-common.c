struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 ,
T_1 V_5 , int V_6 , void * V_7 ,
unsigned int V_8 )
{
struct V_1 * V_9 ;
int V_10 ;
V_9 = F_2 ( V_4 , V_5 , V_11 ) ;
if ( ! V_9 )
return F_3 ( - V_12 ) ;
V_9 -> V_13 = F_4 ( 32 ) ;
V_9 -> V_9 . V_14 = F_4 ( 32 ) ;
V_9 -> V_6 [ 0 ] = V_6 ;
V_9 -> V_8 = V_8 ;
V_9 -> V_9 . V_15 = V_7 ;
V_9 -> V_9 . V_3 = V_3 ;
V_10 = F_5 ( V_9 , & V_16 ) ;
if ( V_10 ) {
F_6 ( V_9 ) ;
return F_3 ( V_10 ) ;
}
return V_9 ;
}
static struct V_17 *
F_7 ( struct V_2 * V_3 , int V_18 , T_1 V_19 , int V_6 ,
struct V_20 * V_7 )
{
struct V_21 V_22 [] = {
{
. V_23 = V_19 ,
. V_24 = V_19 + 127 ,
. V_25 = V_26 ,
} ,
{
. V_23 = V_6 ,
. V_24 = V_6 ,
. V_25 = V_27 ,
}
} ;
return F_8 (
V_3 ,
L_1 ,
V_18 ,
V_22 ,
F_9 ( V_22 ) ,
V_7 ,
sizeof( * V_7 ) ) ;
}
void F_10 ( struct V_2 * V_3 , T_1 * V_5 , int V_28 ,
int V_6 , struct V_20 * V_7 )
{
int V_29 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_29 += 32 , V_6 ++ ) {
V_7 -> V_31 = V_29 ;
V_7 -> V_32 = F_11 ( V_29 ) ;
V_7 -> V_33 = 32 ;
F_7 ( V_3 , V_30 , V_5 [ V_30 ] , V_6 , V_7 ) ;
}
}
