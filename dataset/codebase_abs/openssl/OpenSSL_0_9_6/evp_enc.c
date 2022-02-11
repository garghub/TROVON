void F_1 ( T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
int F_2 ( T_1 * V_1 , const T_2 * V_2 ,
unsigned char * V_3 , unsigned char * V_4 , int V_5 )
{
if( V_5 && ( V_5 != - 1 ) ) V_5 = 1 ;
if ( V_2 ) {
V_1 -> V_2 = V_2 ;
V_1 -> V_6 = V_2 -> V_6 ;
if( V_1 -> V_2 -> V_7 & V_8 ) {
if( ! F_3 ( V_1 , V_9 , 0 , NULL ) ) {
F_4 ( V_10 , V_11 ) ;
return 0 ;
}
}
} else if( ! V_1 -> V_2 ) {
F_4 ( V_10 , V_12 ) ;
return 0 ;
}
if( ! ( F_5 ( V_1 ) & V_13 ) ) {
switch( F_6 ( V_1 ) ) {
case V_14 :
case V_15 :
break;
case V_16 :
case V_17 :
V_1 -> V_18 = 0 ;
case V_19 :
if( V_4 ) memcpy ( V_1 -> V_20 , V_4 , F_7 ( V_1 ) ) ;
memcpy ( V_1 -> V_4 , V_1 -> V_20 , F_7 ( V_1 ) ) ;
break;
default:
return 0 ;
break;
}
}
if( V_3 || ( V_1 -> V_2 -> V_7 & V_21 ) ) {
if( ! V_1 -> V_2 -> V_22 ( V_1 , V_3 , V_4 , V_5 ) ) return 0 ;
}
if( V_5 != - 1 ) V_1 -> V_23 = V_5 ;
V_1 -> V_24 = 0 ;
return 1 ;
}
int F_8 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 ,
unsigned char * V_27 , int V_28 )
{
if ( V_1 -> V_23 )
return F_9 ( V_1 , V_25 , V_26 , V_27 , V_28 ) ;
else return F_10 ( V_1 , V_25 , V_26 , V_27 , V_28 ) ;
}
int F_11 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 )
{
if ( V_1 -> V_23 )
return F_12 ( V_1 , V_25 , V_26 ) ;
else return ( F_13 ( V_1 , V_25 , V_26 ) ) ;
}
int F_14 ( T_1 * V_1 , const T_2 * V_2 ,
unsigned char * V_3 , unsigned char * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
}
int F_15 ( T_1 * V_1 , const T_2 * V_2 ,
unsigned char * V_3 , unsigned char * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_9 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 ,
unsigned char * V_27 , int V_28 )
{
int V_29 , V_30 , V_31 ;
V_29 = V_1 -> V_24 ;
V_31 = V_1 -> V_2 -> V_32 ;
* V_26 = 0 ;
if ( ( V_28 == 0 ) && ( V_29 != V_31 ) ) return 1 ;
if ( V_29 != 0 )
{
if ( V_29 + V_28 < V_31 )
{
memcpy ( & ( V_1 -> V_33 [ V_29 ] ) , V_27 , V_28 ) ;
V_1 -> V_24 += V_28 ;
return 1 ;
}
else
{
V_30 = V_31 - V_29 ;
if ( V_30 != 0 ) memcpy ( & ( V_1 -> V_33 [ V_29 ] ) , V_27 , V_30 ) ;
if( ! V_1 -> V_2 -> V_34 ( V_1 , V_25 , V_1 -> V_33 , V_31 ) ) return 0 ;
V_28 -= V_30 ;
V_27 += V_30 ;
V_25 += V_31 ;
* V_26 += V_31 ;
}
}
V_29 = V_28 % V_31 ;
V_28 -= V_29 ;
if ( V_28 > 0 )
{
if( ! V_1 -> V_2 -> V_34 ( V_1 , V_25 , V_27 , V_28 ) ) return 0 ;
* V_26 += V_28 ;
}
if ( V_29 != 0 )
memcpy ( V_1 -> V_33 , & ( V_27 [ V_28 ] ) , V_29 ) ;
V_1 -> V_24 = V_29 ;
return 1 ;
}
int F_12 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 )
{
int V_29 , V_35 , V_36 , V_31 ;
V_36 = V_1 -> V_2 -> V_32 ;
if ( V_36 == 1 )
{
* V_26 = 0 ;
return 1 ;
}
V_31 = V_1 -> V_24 ;
V_35 = V_36 - V_31 ;
for ( V_29 = V_31 ; V_29 < V_36 ; V_29 ++ )
V_1 -> V_33 [ V_29 ] = V_35 ;
if( ! V_1 -> V_2 -> V_34 ( V_1 , V_25 , V_1 -> V_33 , V_36 ) ) return 0 ;
* V_26 = V_36 ;
return 1 ;
}
int F_10 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 ,
unsigned char * V_27 , int V_28 )
{
int V_36 , V_31 , V_35 ;
int V_37 = 0 ;
* V_26 = 0 ;
if ( V_28 == 0 ) return 1 ;
V_36 = V_1 -> V_2 -> V_32 ;
if ( V_36 > 1 )
{
V_31 = V_1 -> V_24 ;
V_35 = V_28 + V_31 ;
if ( V_35 % V_36 == 0 )
{
if ( V_28 < V_36 )
{
memcpy ( & ( V_1 -> V_33 [ V_31 ] ) , V_27 , V_28 ) ;
V_1 -> V_24 = V_36 ;
* V_26 = 0 ;
return 1 ;
}
V_37 = 1 ;
V_28 -= V_36 ;
}
}
if( ! F_9 ( V_1 , V_25 , V_26 , V_27 , V_28 ) ) return 0 ;
if ( V_37 )
{
memcpy ( & ( V_1 -> V_33 [ 0 ] ) , & ( V_27 [ V_28 ] ) , V_36 ) ;
#ifdef F_16
if ( V_1 -> V_24 != 0 )
{
abort () ;
}
#endif
V_1 -> V_24 = V_36 ;
}
return 1 ;
}
int F_13 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 )
{
int V_29 , V_36 ;
int V_35 ;
* V_26 = 0 ;
V_36 = V_1 -> V_2 -> V_32 ;
if ( V_36 > 1 )
{
if ( V_1 -> V_24 != V_36 )
{
F_4 ( V_38 , V_39 ) ;
return ( 0 ) ;
}
if( ! F_9 ( V_1 , V_1 -> V_33 , & V_35 , V_1 -> V_33 , 0 ) ) return 0 ;
if ( V_35 != V_36 )
return ( 0 ) ;
V_35 = V_1 -> V_33 [ V_36 - 1 ] ;
if ( V_35 > V_36 )
{
F_4 ( V_38 , V_40 ) ;
return ( 0 ) ;
}
for ( V_29 = 0 ; V_29 < V_35 ; V_29 ++ )
{
if ( V_1 -> V_33 [ -- V_36 ] != V_35 )
{
F_4 ( V_38 , V_40 ) ;
return ( 0 ) ;
}
}
V_35 = V_1 -> V_2 -> V_32 - V_35 ;
for ( V_29 = 0 ; V_29 < V_35 ; V_29 ++ )
V_25 [ V_29 ] = V_1 -> V_33 [ V_29 ] ;
* V_26 = V_35 ;
}
else
* V_26 = 0 ;
return ( 1 ) ;
}
int F_17 ( T_1 * V_41 )
{
if ( ( V_41 -> V_2 != NULL ) && ( V_41 -> V_2 -> V_42 != NULL ) )
{
if( ! V_41 -> V_2 -> V_42 ( V_41 ) ) return 0 ;
}
memset ( V_41 , 0 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_18 ( T_1 * V_41 , int V_43 )
{
if( V_41 -> V_2 -> V_7 & V_44 )
return F_3 ( V_41 , V_45 , V_43 , NULL ) ;
if( V_41 -> V_6 == V_43 ) return 1 ;
if( ( V_43 > 0 ) && ( V_41 -> V_2 -> V_7 & V_46 ) )
{
V_41 -> V_6 = V_43 ;
return 1 ;
}
F_4 ( V_47 , V_48 ) ;
return 0 ;
}
int F_3 ( T_1 * V_1 , int type , int V_49 , void * V_50 )
{
int V_51 ;
if( ! V_1 -> V_2 ) {
F_4 ( V_52 , V_12 ) ;
return 0 ;
}
if( ! V_1 -> V_2 -> V_53 ) {
F_4 ( V_52 , V_54 ) ;
return 0 ;
}
V_51 = V_1 -> V_2 -> V_53 ( V_1 , type , V_49 , V_50 ) ;
if( V_51 == - 1 ) {
F_4 ( V_52 , V_55 ) ;
return 0 ;
}
return V_51 ;
}
