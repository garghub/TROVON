static int F_1 ( int V_1 , struct V_2 * V_3 , T_1 V_4 ,
struct V_5 * V_5 , struct V_6 * * V_7 )
{
const int V_8 = V_1 | V_9 ;
struct V_6 * V_6 ;
V_6 = F_2 ( V_10 | V_11 , 1 ) ;
V_6 -> V_12 = V_4 ;
V_6 -> V_13 = V_3 ;
V_6 -> V_14 = V_15 ;
if ( F_3 ( V_6 , V_5 , V_16 , 0 ) < V_16 ) {
F_4 ( V_17 L_1 ,
( unsigned long long ) V_4 ) ;
F_5 ( V_6 ) ;
return - V_18 ;
}
F_6 ( V_5 ) ;
F_7 ( V_6 ) ;
if ( V_7 == NULL ) {
F_8 ( V_8 , V_6 ) ;
F_9 ( V_5 ) ;
if ( V_1 == V_19 )
F_10 ( V_6 ) ;
F_5 ( V_6 ) ;
} else {
if ( V_1 == V_19 )
F_11 ( V_5 ) ;
V_6 -> V_20 = * V_7 ;
* V_7 = V_6 ;
F_8 ( V_8 , V_6 ) ;
}
return 0 ;
}
int F_12 ( T_2 V_21 , void * V_22 , struct V_6 * * V_7 )
{
return F_1 ( V_19 , V_23 , V_21 * ( V_16 >> 9 ) ,
F_13 ( V_22 ) , V_7 ) ;
}
int F_14 ( T_2 V_21 , void * V_22 , struct V_6 * * V_7 )
{
return F_1 ( V_24 , V_23 , V_21 * ( V_16 >> 9 ) ,
F_13 ( V_22 ) , V_7 ) ;
}
int F_15 ( struct V_6 * * V_7 )
{
struct V_6 * V_6 ;
struct V_6 * V_25 ;
int V_26 = 0 ;
if ( V_7 == NULL )
return 0 ;
V_6 = * V_7 ;
if ( V_6 == NULL )
return 0 ;
while ( V_6 ) {
struct V_5 * V_5 ;
V_25 = V_6 -> V_20 ;
V_5 = V_6 -> V_27 [ 0 ] . V_28 ;
F_9 ( V_5 ) ;
if ( ! F_16 ( V_5 ) || F_17 ( V_5 ) )
V_26 = - V_29 ;
F_18 ( V_5 ) ;
F_5 ( V_6 ) ;
V_6 = V_25 ;
}
* V_7 = NULL ;
return V_26 ;
}
