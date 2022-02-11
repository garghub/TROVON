int F_1 ( T_1 V_1 )
{
return ( V_1 == V_2 ) ||
( V_1 == V_3 ) ||
( V_1 == V_4 ) ||
( V_1 == V_5 ) ||
( V_1 == V_6 ) ||
( V_1 == V_7 ) ;
}
int F_2 ( const struct V_8 * V_9 , int V_10 , T_1 * V_11 )
{
T_1 V_1 = * V_11 ;
while ( F_1 ( V_1 ) ) {
struct V_12 V_13 , * V_14 ;
int V_15 ;
if ( V_1 == V_6 )
return - 1 ;
V_14 = F_3 ( V_9 , V_10 , sizeof( V_13 ) , & V_13 ) ;
if ( V_14 == NULL )
return - 1 ;
if ( V_1 == V_4 ) {
T_2 V_16 , * V_17 ;
V_17 = F_3 ( V_9 ,
V_10 + F_4 ( struct V_18 ,
V_19 ) ,
sizeof( V_16 ) ,
& V_16 ) ;
if ( V_17 == NULL )
return - 1 ;
if ( F_5 ( * V_17 ) & ~ 0x7 )
break;
V_15 = 8 ;
} else if ( V_1 == V_5 )
V_15 = ( V_14 -> V_15 + 2 ) << 2 ;
else
V_15 = F_6 ( V_14 ) ;
V_1 = V_14 -> V_1 ;
V_10 += V_15 ;
}
* V_11 = V_1 ;
return V_10 ;
}
