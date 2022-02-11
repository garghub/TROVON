static int F_1 ( const T_1 V_1 , const T_2 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
T_2 V_5 ;
int V_6 = 0 ;
if ( ! V_3 || ! V_4 )
return V_7 ;
* V_3 = 0 ;
do {
if ( V_6 >= V_1 )
return V_7 ;
V_5 = V_2 [ V_6 ] & 0x80 ;
* V_3 <<= 7 ;
* V_3 |= V_2 [ V_6 ] & 0x7f ;
++ V_6 ;
} while ( V_5 );
* V_4 = V_6 ;
return V_8 ;
}
int F_2 ( const T_1 V_1 , const T_2 * V_9 , T_1 * V_10 ,
T_3 V_11 , void * V_12 )
{
int type ;
int V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_4 ;
const T_2 * V_16 ;
const T_2 * V_17 ;
if ( * V_10 >= V_1 )
return V_7 ;
type = V_9 [ * V_10 ] ;
switch ( type ) {
case V_18 :
case V_19 :
( * V_10 ) ++ ;
V_13 = F_1 ( V_1 - * V_10 , & V_9 [ * V_10 ] ,
& V_14 , & V_4 ) ;
if ( V_13 != V_8 || * V_10 + V_4 >= V_1 )
return V_7 ;
* V_10 += V_4 ;
V_16 = & V_9 [ * V_10 ] ;
* V_10 += V_14 ;
V_13 = F_1 ( V_1 - * V_10 , & V_9 [ * V_10 ] ,
& V_15 , & V_4 ) ;
if ( V_13 != V_8 || * V_10 + V_4 > V_1 )
return V_7 ;
* V_10 += V_4 ;
V_17 = & V_9 [ * V_10 ] ;
* V_10 += V_15 ;
if ( type == V_19 )
return V_11 ( V_16 , V_14 , V_17 , V_15 ,
V_12 ) ;
break;
default:
return V_7 ;
}
return V_8 ;
}
