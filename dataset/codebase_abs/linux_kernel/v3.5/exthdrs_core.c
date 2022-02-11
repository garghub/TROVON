bool F_1 ( T_1 V_1 )
{
return ( V_1 == V_2 ) ||
( V_1 == V_3 ) ||
( V_1 == V_4 ) ||
( V_1 == V_5 ) ||
( V_1 == V_6 ) ||
( V_1 == V_7 ) ;
}
int F_2 ( const struct V_8 * V_9 , int V_10 , T_1 * V_11 ,
T_2 * V_12 )
{
T_1 V_1 = * V_11 ;
* V_12 = 0 ;
while ( F_1 ( V_1 ) ) {
struct V_13 V_14 , * V_15 ;
int V_16 ;
if ( V_1 == V_6 )
return - 1 ;
V_15 = F_3 ( V_9 , V_10 , sizeof( V_14 ) , & V_14 ) ;
if ( V_15 == NULL )
return - 1 ;
if ( V_1 == V_4 ) {
T_2 V_17 , * V_18 ;
V_18 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_19 ,
V_20 ) ,
sizeof( V_17 ) ,
& V_17 ) ;
if ( V_18 == NULL )
return - 1 ;
* V_12 = * V_18 ;
if ( F_5 ( * V_12 ) & ~ 0x7 )
break;
V_16 = 8 ;
} else if ( V_1 == V_5 )
V_16 = ( V_15 -> V_16 + 2 ) << 2 ;
else
V_16 = F_6 ( V_15 ) ;
V_1 = V_15 -> V_1 ;
V_10 += V_16 ;
}
* V_11 = V_1 ;
return V_10 ;
}
