int F_1 ( unsigned char * * * V_1 , T_1 * V_2 )
{
T_2 * * V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( ! V_3 )
return 0 ;
if ( ! * V_3 )
* V_3 = F_3 () ;
if ( * V_3 ) {
( * V_3 ) -> V_4 |= V_5 ;
( * V_3 ) -> V_4 &= ~ V_6 ;
* V_1 = & ( * V_3 ) -> V_7 ;
return 1 ;
}
F_4 ( V_8 , V_9 ) ;
return 0 ;
}
T_1 * F_5 ( T_3 * V_10 , T_1 * * V_2 )
{
return F_6 ( F_7 ( T_1 ) , V_10 , V_2 ) ;
}
int F_8 ( T_3 * V_10 , T_1 * V_2 )
{
return F_9 ( F_7 ( T_1 ) , V_10 , V_2 ) ;
}
T_3 * F_10 ( T_3 * V_11 , T_1 * V_2 )
{
return F_11 ( V_11 , ( V_12 * ) V_2 ,
F_7 ( T_1 ) ) ;
}
int F_12 ( T_3 * V_11 , T_1 * V_2 , T_3 * V_13 , int V_4 )
{
return F_13 ( V_11 , ( V_12 * ) V_2 , V_13 , V_4 ,
F_7 ( T_1 ) ) ;
}
int F_14 ( T_3 * V_11 , T_1 * V_2 , T_3 * V_13 ,
int V_4 )
{
return F_15 ( V_11 , ( V_12 * ) V_2 , V_13 , V_4 ,
L_1 , F_7 ( T_1 ) ) ;
}
int F_16 ( T_3 * V_14 , T_1 * V_2 , T_3 * V_7 , int V_4 )
{
F_17 ( V_15 ) * V_16 ;
int V_17 = F_18 ( V_2 -> V_18 ) ;
int V_19 = F_18 ( F_19 ( V_2 ) ) ;
if ( V_17 == V_20 )
V_16 = V_2 -> V_21 . V_22 -> V_23 ;
else
V_16 = NULL ;
return F_20 ( V_14 , ( V_12 * ) V_2 , V_7 , V_4 ,
V_17 , V_19 , V_16 ,
F_7 ( T_1 ) ) ;
}
T_1 * F_21 ( T_3 * V_14 , T_3 * * V_24 )
{
return ( T_1 * ) F_22 ( V_14 , V_24 ,
F_7
( T_1 ) ) ;
}
