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
if ( V_1 -> V_8 && V_1 -> V_2 && ( ! V_2 ||
( V_2 && ( V_2 -> V_9 == V_1 -> V_2 -> V_9 ) ) ) )
goto V_10;
if ( V_2 )
{
F_4 ( V_1 ) ;
V_1 -> V_7 = V_5 ;
if( V_6 )
{
if ( ! F_5 ( V_6 ) )
{
F_6 ( V_11 , V_12 ) ;
return 0 ;
}
}
else
V_6 = F_7 ( V_2 -> V_9 ) ;
if( V_6 )
{
const T_2 * V_13 = F_8 ( V_6 , V_2 -> V_9 ) ;
if( ! V_13 )
{
F_6 ( V_11 , V_12 ) ;
return 0 ;
}
V_2 = V_13 ;
V_1 -> V_8 = V_6 ;
}
else
V_1 -> V_8 = NULL ;
V_1 -> V_2 = V_2 ;
V_1 -> V_14 = F_9 ( V_1 -> V_2 -> V_15 ) ;
V_1 -> V_16 = V_2 -> V_16 ;
V_1 -> V_17 = 0 ;
if( V_1 -> V_2 -> V_17 & V_18 )
{
if( ! F_10 ( V_1 , V_19 , 0 , NULL ) )
{
F_6 ( V_11 , V_12 ) ;
return 0 ;
}
}
}
else if( ! V_1 -> V_2 )
{
F_6 ( V_11 , V_20 ) ;
return 0 ;
}
V_10:
F_11 ( V_1 -> V_2 -> V_21 == 1
|| V_1 -> V_2 -> V_21 == 8
|| V_1 -> V_2 -> V_21 == 16 ) ;
if( ! ( F_12 ( V_1 ) & V_22 ) ) {
switch( F_13 ( V_1 ) ) {
case V_23 :
case V_24 :
break;
case V_25 :
case V_26 :
V_1 -> V_27 = 0 ;
case V_28 :
F_11 ( F_14 ( V_1 ) <= sizeof V_1 -> V_4 ) ;
if( V_4 ) memcpy ( V_1 -> V_29 , V_4 , F_14 ( V_1 ) ) ;
memcpy ( V_1 -> V_4 , V_1 -> V_29 , F_14 ( V_1 ) ) ;
break;
default:
return 0 ;
break;
}
}
if( V_3 || ( V_1 -> V_2 -> V_17 & V_30 ) ) {
if( ! V_1 -> V_2 -> V_31 ( V_1 , V_3 , V_4 , V_5 ) ) return 0 ;
}
V_1 -> V_32 = 0 ;
V_1 -> V_33 = 0 ;
V_1 -> V_34 = V_1 -> V_2 -> V_21 - 1 ;
return 1 ;
}
int F_15 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 ,
const unsigned char * V_37 , int V_38 )
{
if ( V_1 -> V_7 )
return F_16 ( V_1 , V_35 , V_36 , V_37 , V_38 ) ;
else return F_17 ( V_1 , V_35 , V_36 , V_37 , V_38 ) ;
}
int F_18 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
if ( V_1 -> V_7 )
return F_19 ( V_1 , V_35 , V_36 ) ;
else return F_20 ( V_1 , V_35 , V_36 ) ;
}
int F_21 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
if ( V_1 -> V_7 )
return F_22 ( V_1 , V_35 , V_36 ) ;
else return F_23 ( V_1 , V_35 , V_36 ) ;
}
int F_24 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
}
int F_25 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_3 ( V_1 , V_2 , V_6 , V_3 , V_4 , 1 ) ;
}
int F_26 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_3 ( V_1 , V_2 , NULL , V_3 , V_4 , 0 ) ;
}
int F_27 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_3 ( V_1 , V_2 , V_6 , V_3 , V_4 , 0 ) ;
}
int F_16 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 ,
const unsigned char * V_37 , int V_38 )
{
int V_39 , V_40 , V_41 ;
F_11 ( V_38 > 0 ) ;
if( V_1 -> V_32 == 0 && ( V_38 & ( V_1 -> V_34 ) ) == 0 )
{
if( V_1 -> V_2 -> V_42 ( V_1 , V_35 , V_37 , V_38 ) )
{
* V_36 = V_38 ;
return 1 ;
}
else
{
* V_36 = 0 ;
return 0 ;
}
}
V_39 = V_1 -> V_32 ;
V_41 = V_1 -> V_2 -> V_21 ;
F_11 ( V_41 <= sizeof V_1 -> V_43 ) ;
if ( V_39 != 0 )
{
if ( V_39 + V_38 < V_41 )
{
memcpy ( & ( V_1 -> V_43 [ V_39 ] ) , V_37 , V_38 ) ;
V_1 -> V_32 += V_38 ;
* V_36 = 0 ;
return 1 ;
}
else
{
V_40 = V_41 - V_39 ;
memcpy ( & ( V_1 -> V_43 [ V_39 ] ) , V_37 , V_40 ) ;
if( ! V_1 -> V_2 -> V_42 ( V_1 , V_35 , V_1 -> V_43 , V_41 ) ) return 0 ;
V_38 -= V_40 ;
V_37 += V_40 ;
V_35 += V_41 ;
* V_36 = V_41 ;
}
}
else
* V_36 = 0 ;
V_39 = V_38 & ( V_41 - 1 ) ;
V_38 -= V_39 ;
if ( V_38 > 0 )
{
if( ! V_1 -> V_2 -> V_42 ( V_1 , V_35 , V_37 , V_38 ) ) return 0 ;
* V_36 += V_38 ;
}
if ( V_39 != 0 )
memcpy ( V_1 -> V_43 , & ( V_37 [ V_38 ] ) , V_39 ) ;
V_1 -> V_32 = V_39 ;
return 1 ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
int V_44 ;
V_44 = F_19 ( V_1 , V_35 , V_36 ) ;
return V_44 ;
}
int F_19 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
int V_39 , V_45 , V_46 , V_41 , V_44 ;
V_46 = V_1 -> V_2 -> V_21 ;
F_11 ( V_46 <= sizeof V_1 -> V_43 ) ;
if ( V_46 == 1 )
{
* V_36 = 0 ;
return 1 ;
}
V_41 = V_1 -> V_32 ;
if ( V_1 -> V_17 & V_47 )
{
if( V_41 )
{
F_6 ( V_48 , V_49 ) ;
return 0 ;
}
* V_36 = 0 ;
return 1 ;
}
V_45 = V_46 - V_41 ;
for ( V_39 = V_41 ; V_39 < V_46 ; V_39 ++ )
V_1 -> V_43 [ V_39 ] = V_45 ;
V_44 = V_1 -> V_2 -> V_42 ( V_1 , V_35 , V_1 -> V_43 , V_46 ) ;
if( V_44 )
* V_36 = V_46 ;
return V_44 ;
}
int F_17 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 ,
const unsigned char * V_37 , int V_38 )
{
int V_46 , V_50 ;
if ( V_38 == 0 )
{
* V_36 = 0 ;
return 1 ;
}
if ( V_1 -> V_17 & V_47 )
return F_16 ( V_1 , V_35 , V_36 , V_37 , V_38 ) ;
V_46 = V_1 -> V_2 -> V_21 ;
F_11 ( V_46 <= sizeof V_1 -> V_51 ) ;
if( V_1 -> V_33 )
{
memcpy ( V_35 , V_1 -> V_51 , V_46 ) ;
V_35 += V_46 ;
V_50 = 1 ;
}
else
V_50 = 0 ;
if( ! F_16 ( V_1 , V_35 , V_36 , V_37 , V_38 ) )
return 0 ;
if ( V_46 > 1 && ! V_1 -> V_32 )
{
* V_36 -= V_46 ;
V_1 -> V_33 = 1 ;
memcpy ( V_1 -> V_51 , & V_35 [ * V_36 ] , V_46 ) ;
}
else
V_1 -> V_33 = 0 ;
if ( V_50 )
* V_36 += V_46 ;
return 1 ;
}
int F_23 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
int V_44 ;
V_44 = F_20 ( V_1 , V_35 , V_36 ) ;
return V_44 ;
}
int F_20 ( T_1 * V_1 , unsigned char * V_35 , int * V_36 )
{
int V_39 , V_46 ;
int V_45 ;
* V_36 = 0 ;
V_46 = V_1 -> V_2 -> V_21 ;
if ( V_1 -> V_17 & V_47 )
{
if( V_1 -> V_32 )
{
F_6 ( V_52 , V_49 ) ;
return 0 ;
}
* V_36 = 0 ;
return 1 ;
}
if ( V_46 > 1 )
{
if ( V_1 -> V_32 || ! V_1 -> V_33 )
{
F_6 ( V_52 , V_53 ) ;
return ( 0 ) ;
}
F_11 ( V_46 <= sizeof V_1 -> V_51 ) ;
V_45 = V_1 -> V_51 [ V_46 - 1 ] ;
if ( V_45 > V_46 )
{
F_6 ( V_52 , V_54 ) ;
return ( 0 ) ;
}
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
{
if ( V_1 -> V_51 [ -- V_46 ] != V_45 )
{
F_6 ( V_52 , V_54 ) ;
return ( 0 ) ;
}
}
V_45 = V_1 -> V_2 -> V_21 - V_45 ;
for ( V_39 = 0 ; V_39 < V_45 ; V_39 ++ )
V_35 [ V_39 ] = V_1 -> V_51 [ V_39 ] ;
* V_36 = V_45 ;
}
else
* V_36 = 0 ;
return ( 1 ) ;
}
int F_4 ( T_1 * V_13 )
{
if ( V_13 -> V_2 != NULL )
{
if( V_13 -> V_2 -> V_55 && ! V_13 -> V_2 -> V_55 ( V_13 ) )
return 0 ;
if ( V_13 -> V_14 )
F_28 ( V_13 -> V_14 , V_13 -> V_2 -> V_15 ) ;
}
if ( V_13 -> V_14 )
F_29 ( V_13 -> V_14 ) ;
if ( V_13 -> V_8 )
F_30 ( V_13 -> V_8 ) ;
memset ( V_13 , 0 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_31 ( T_1 * V_13 , int V_56 )
{
if( V_13 -> V_2 -> V_17 & V_57 )
return F_10 ( V_13 , V_58 , V_56 , NULL ) ;
if( V_13 -> V_16 == V_56 ) return 1 ;
if( ( V_56 > 0 ) && ( V_13 -> V_2 -> V_17 & V_59 ) )
{
V_13 -> V_16 = V_56 ;
return 1 ;
}
F_6 ( V_60 , V_61 ) ;
return 0 ;
}
int F_32 ( T_1 * V_1 , int V_62 )
{
if ( V_62 ) V_1 -> V_17 &= ~ V_47 ;
else V_1 -> V_17 |= V_47 ;
return 1 ;
}
int F_10 ( T_1 * V_1 , int type , int V_63 , void * V_64 )
{
int V_44 ;
if( ! V_1 -> V_2 ) {
F_6 ( V_65 , V_20 ) ;
return 0 ;
}
if( ! V_1 -> V_2 -> V_66 ) {
F_6 ( V_65 , V_67 ) ;
return 0 ;
}
V_44 = V_1 -> V_2 -> V_66 ( V_1 , type , V_63 , V_64 ) ;
if( V_44 == - 1 ) {
F_6 ( V_65 , V_68 ) ;
return 0 ;
}
return V_44 ;
}
