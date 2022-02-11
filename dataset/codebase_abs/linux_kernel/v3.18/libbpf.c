static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) ( unsigned long ) V_1 ;
}
int F_2 ( enum V_2 V_3 , int V_4 , int V_5 ,
int V_6 )
{
union V_7 V_8 = {
. V_3 = V_3 ,
. V_4 = V_4 ,
. V_5 = V_5 ,
. V_6 = V_6
} ;
return F_3 ( V_9 , V_10 , & V_8 , sizeof( V_8 ) ) ;
}
int F_4 ( int V_11 , void * V_12 , void * V_13 )
{
union V_7 V_8 = {
. V_14 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_13 = F_1 ( V_13 ) ,
} ;
return F_3 ( V_9 , V_15 , & V_8 , sizeof( V_8 ) ) ;
}
int F_5 ( int V_11 , void * V_12 , void * V_13 )
{
union V_7 V_8 = {
. V_14 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_13 = F_1 ( V_13 ) ,
} ;
return F_3 ( V_9 , V_16 , & V_8 , sizeof( V_8 ) ) ;
}
int F_6 ( int V_11 , void * V_12 )
{
union V_7 V_8 = {
. V_14 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
} ;
return F_3 ( V_9 , V_17 , & V_8 , sizeof( V_8 ) ) ;
}
int F_7 ( int V_11 , void * V_12 , void * V_18 )
{
union V_7 V_8 = {
. V_14 = V_11 ,
. V_12 = F_1 ( V_12 ) ,
. V_18 = F_1 ( V_18 ) ,
} ;
return F_3 ( V_9 , V_19 , & V_8 , sizeof( V_8 ) ) ;
}
int F_8 ( enum V_20 V_21 ,
const struct V_22 * V_23 , int V_24 ,
const char * V_25 )
{
union V_7 V_8 = {
. V_21 = V_21 ,
. V_23 = F_1 ( ( void * ) V_23 ) ,
. V_26 = V_24 / sizeof( struct V_22 ) ,
. V_25 = F_1 ( ( void * ) V_25 ) ,
. V_27 = F_1 ( V_28 ) ,
. V_29 = V_30 ,
. V_31 = 1 ,
} ;
V_28 [ 0 ] = 0 ;
return F_3 ( V_9 , V_32 , & V_8 , sizeof( V_8 ) ) ;
}
