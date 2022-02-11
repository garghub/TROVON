void F_1 ( T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
int F_2 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 , int V_5 )
{
if ( V_2 )
F_1 ( V_1 ) ;
return F_3 ( V_1 , V_2 , NULL , V_3 , V_4 , V_5 ) ;
}
int F_3 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 , int V_5 )
{
if ( V_5 == - 1 )
V_5 = V_1 -> V_7 ;
else
{
if ( V_5 )
V_5 = 1 ;
V_1 -> V_7 = V_5 ;
}
#ifndef F_4
if ( V_1 -> V_8 && V_1 -> V_2 && ( ! V_2 ||
( V_2 && ( V_2 -> V_9 == V_1 -> V_2 -> V_9 ) ) ) )
goto V_10;
#endif
if ( V_2 )
{
F_5 ( V_1 ) ;
V_1 -> V_7 = V_5 ;
#ifndef F_4
if( V_6 )
{
if ( ! F_6 ( V_6 ) )
{
F_7 ( V_11 , V_12 ) ;
return 0 ;
}
}
else
V_6 = F_8 ( V_2 -> V_9 ) ;
if( V_6 )
{
const T_2 * V_13 = F_9 ( V_6 , V_2 -> V_9 ) ;
if( ! V_13 )
{
F_7 ( V_11 , V_12 ) ;
return 0 ;
}
V_2 = V_13 ;
V_1 -> V_8 = V_6 ;
}
else
V_1 -> V_8 = NULL ;
#endif
V_1 -> V_2 = V_2 ;
if ( V_1 -> V_2 -> V_14 )
{
V_1 -> V_15 = F_10 ( V_1 -> V_2 -> V_14 ) ;
if ( ! V_1 -> V_15 )
{
F_7 ( V_11 , V_16 ) ;
return 0 ;
}
}
else
{
V_1 -> V_15 = NULL ;
}
V_1 -> V_17 = V_2 -> V_17 ;
V_1 -> V_18 = 0 ;
if( V_1 -> V_2 -> V_18 & V_19 )
{
if( ! F_11 ( V_1 , V_20 , 0 , NULL ) )
{
F_7 ( V_11 , V_12 ) ;
return 0 ;
}
}
}
else if( ! V_1 -> V_2 )
{
F_7 ( V_11 , V_21 ) ;
return 0 ;
}
#ifndef F_4
V_10:
#endif
F_12 ( V_1 -> V_2 -> V_22 == 1
|| V_1 -> V_2 -> V_22 == 8
|| V_1 -> V_2 -> V_22 == 16 ) ;
if( ! ( F_13 ( V_1 ) & V_23 ) ) {
switch( F_14 ( V_1 ) ) {
case V_24 :
case V_25 :
break;
case V_26 :
case V_27 :
V_1 -> V_28 = 0 ;
case V_29 :
F_12 ( F_15 ( V_1 ) <=
( int ) sizeof( V_1 -> V_4 ) ) ;
if( V_4 ) memcpy ( V_1 -> V_30 , V_4 , F_15 ( V_1 ) ) ;
memcpy ( V_1 -> V_4 , V_1 -> V_30 , F_15 ( V_1 ) ) ;
break;
default:
return 0 ;
break;
}
}
if( V_3 || ( V_1 -> V_2 -> V_18 & V_31 ) ) {
if( ! V_1 -> V_2 -> V_32 ( V_1 , V_3 , V_4 , V_5 ) ) return 0 ;
}
V_1 -> V_33 = 0 ;
V_1 -> V_34 = 0 ;
V_1 -> V_35 = V_1 -> V_2 -> V_22 - 1 ;
return 1 ;
}
int F_16 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 ,
const unsigned char * V_38 , int V_39 )
{
if ( V_1 -> V_7 )
return F_17 ( V_1 , V_36 , V_37 , V_38 , V_39 ) ;
else return F_18 ( V_1 , V_36 , V_37 , V_38 , V_39 ) ;
}
int F_19 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
if ( V_1 -> V_7 )
return F_20 ( V_1 , V_36 , V_37 ) ;
else return F_21 ( V_1 , V_36 , V_37 ) ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
if ( V_1 -> V_7 )
return F_23 ( V_1 , V_36 , V_37 ) ;
else return F_24 ( V_1 , V_36 , V_37 ) ;
}
int F_25 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
}
int F_26 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_3 ( V_1 , V_2 , V_6 , V_3 , V_4 , 1 ) ;
}
int F_27 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_28 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_3 ( V_1 , V_2 , V_6 , V_3 , V_4 , 0 ) ;
}
int F_17 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 ,
const unsigned char * V_38 , int V_39 )
{
int V_40 , V_41 , V_42 ;
F_12 ( V_39 > 0 ) ;
if( V_1 -> V_33 == 0 && ( V_39 & ( V_1 -> V_35 ) ) == 0 )
{
if( V_1 -> V_2 -> V_43 ( V_1 , V_36 , V_38 , V_39 ) )
{
* V_37 = V_39 ;
return 1 ;
}
else
{
* V_37 = 0 ;
return 0 ;
}
}
V_40 = V_1 -> V_33 ;
V_42 = V_1 -> V_2 -> V_22 ;
F_12 ( V_42 <= ( int ) sizeof( V_1 -> V_44 ) ) ;
if ( V_40 != 0 )
{
if ( V_40 + V_39 < V_42 )
{
memcpy ( & ( V_1 -> V_44 [ V_40 ] ) , V_38 , V_39 ) ;
V_1 -> V_33 += V_39 ;
* V_37 = 0 ;
return 1 ;
}
else
{
V_41 = V_42 - V_40 ;
memcpy ( & ( V_1 -> V_44 [ V_40 ] ) , V_38 , V_41 ) ;
if( ! V_1 -> V_2 -> V_43 ( V_1 , V_36 , V_1 -> V_44 , V_42 ) ) return 0 ;
V_39 -= V_41 ;
V_38 += V_41 ;
V_36 += V_42 ;
* V_37 = V_42 ;
}
}
else
* V_37 = 0 ;
V_40 = V_39 & ( V_42 - 1 ) ;
V_39 -= V_40 ;
if ( V_39 > 0 )
{
if( ! V_1 -> V_2 -> V_43 ( V_1 , V_36 , V_38 , V_39 ) ) return 0 ;
* V_37 += V_39 ;
}
if ( V_40 != 0 )
memcpy ( V_1 -> V_44 , & ( V_38 [ V_39 ] ) , V_40 ) ;
V_1 -> V_33 = V_40 ;
return 1 ;
}
int F_23 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
int V_45 ;
V_45 = F_20 ( V_1 , V_36 , V_37 ) ;
return V_45 ;
}
int F_20 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
int V_46 , V_45 ;
unsigned int V_40 , V_47 , V_42 ;
V_47 = V_1 -> V_2 -> V_22 ;
F_12 ( V_47 <= sizeof V_1 -> V_44 ) ;
if ( V_47 == 1 )
{
* V_37 = 0 ;
return 1 ;
}
V_42 = V_1 -> V_33 ;
if ( V_1 -> V_18 & V_48 )
{
if( V_42 )
{
F_7 ( V_49 , V_50 ) ;
return 0 ;
}
* V_37 = 0 ;
return 1 ;
}
V_46 = V_47 - V_42 ;
for ( V_40 = V_42 ; V_40 < V_47 ; V_40 ++ )
V_1 -> V_44 [ V_40 ] = V_46 ;
V_45 = V_1 -> V_2 -> V_43 ( V_1 , V_36 , V_1 -> V_44 , V_47 ) ;
if( V_45 )
* V_37 = V_47 ;
return V_45 ;
}
int F_18 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 ,
const unsigned char * V_38 , int V_39 )
{
int V_51 ;
unsigned int V_47 ;
if ( V_39 == 0 )
{
* V_37 = 0 ;
return 1 ;
}
if ( V_1 -> V_18 & V_48 )
return F_17 ( V_1 , V_36 , V_37 , V_38 , V_39 ) ;
V_47 = V_1 -> V_2 -> V_22 ;
F_12 ( V_47 <= sizeof V_1 -> V_52 ) ;
if( V_1 -> V_34 )
{
memcpy ( V_36 , V_1 -> V_52 , V_47 ) ;
V_36 += V_47 ;
V_51 = 1 ;
}
else
V_51 = 0 ;
if( ! F_17 ( V_1 , V_36 , V_37 , V_38 , V_39 ) )
return 0 ;
if ( V_47 > 1 && ! V_1 -> V_33 )
{
* V_37 -= V_47 ;
V_1 -> V_34 = 1 ;
memcpy ( V_1 -> V_52 , & V_36 [ * V_37 ] , V_47 ) ;
}
else
V_1 -> V_34 = 0 ;
if ( V_51 )
* V_37 += V_47 ;
return 1 ;
}
int F_24 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
int V_45 ;
V_45 = F_21 ( V_1 , V_36 , V_37 ) ;
return V_45 ;
}
int F_21 ( T_1 * V_1 , unsigned char * V_36 , int * V_37 )
{
int V_40 , V_46 ;
unsigned int V_47 ;
* V_37 = 0 ;
V_47 = V_1 -> V_2 -> V_22 ;
if ( V_1 -> V_18 & V_48 )
{
if( V_1 -> V_33 )
{
F_7 ( V_53 , V_50 ) ;
return 0 ;
}
* V_37 = 0 ;
return 1 ;
}
if ( V_47 > 1 )
{
if ( V_1 -> V_33 || ! V_1 -> V_34 )
{
F_7 ( V_53 , V_54 ) ;
return ( 0 ) ;
}
F_12 ( V_47 <= sizeof V_1 -> V_52 ) ;
V_46 = V_1 -> V_52 [ V_47 - 1 ] ;
if ( V_46 > ( int ) V_47 )
{
F_7 ( V_53 , V_55 ) ;
return ( 0 ) ;
}
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ )
{
if ( V_1 -> V_52 [ -- V_47 ] != V_46 )
{
F_7 ( V_53 , V_55 ) ;
return ( 0 ) ;
}
}
V_46 = V_1 -> V_2 -> V_22 - V_46 ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ )
V_36 [ V_40 ] = V_1 -> V_52 [ V_40 ] ;
* V_37 = V_46 ;
}
else
* V_37 = 0 ;
return ( 1 ) ;
}
int F_5 ( T_1 * V_13 )
{
if ( V_13 -> V_2 != NULL )
{
if( V_13 -> V_2 -> V_56 && ! V_13 -> V_2 -> V_56 ( V_13 ) )
return 0 ;
if ( V_13 -> V_15 )
F_29 ( V_13 -> V_15 , V_13 -> V_2 -> V_14 ) ;
}
if ( V_13 -> V_15 )
F_30 ( V_13 -> V_15 ) ;
#ifndef F_4
if ( V_13 -> V_8 )
F_31 ( V_13 -> V_8 ) ;
#endif
memset ( V_13 , 0 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_32 ( T_1 * V_13 , int V_57 )
{
if( V_13 -> V_2 -> V_18 & V_58 )
return F_11 ( V_13 , V_59 , V_57 , NULL ) ;
if( V_13 -> V_17 == V_57 ) return 1 ;
if( ( V_57 > 0 ) && ( V_13 -> V_2 -> V_18 & V_60 ) )
{
V_13 -> V_17 = V_57 ;
return 1 ;
}
F_7 ( V_61 , V_62 ) ;
return 0 ;
}
int F_33 ( T_1 * V_1 , int V_63 )
{
if ( V_63 ) V_1 -> V_18 &= ~ V_48 ;
else V_1 -> V_18 |= V_48 ;
return 1 ;
}
int F_11 ( T_1 * V_1 , int type , int V_64 , void * V_65 )
{
int V_45 ;
if( ! V_1 -> V_2 ) {
F_7 ( V_66 , V_21 ) ;
return 0 ;
}
if( ! V_1 -> V_2 -> V_67 ) {
F_7 ( V_66 , V_68 ) ;
return 0 ;
}
V_45 = V_1 -> V_2 -> V_67 ( V_1 , type , V_64 , V_65 ) ;
if( V_45 == - 1 ) {
F_7 ( V_66 , V_69 ) ;
return 0 ;
}
return V_45 ;
}
int F_34 ( T_1 * V_1 , unsigned char * V_3 )
{
if ( V_1 -> V_2 -> V_18 & V_70 )
return F_11 ( V_1 , V_71 , 0 , V_3 ) ;
if ( F_35 ( V_3 , V_1 -> V_17 ) <= 0 )
return 0 ;
return 1 ;
}
