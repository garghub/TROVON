void F_1 ( T_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
}
T_1 * F_2 ( void )
{
T_1 * V_1 = F_3 ( sizeof *V_1 ) ;
if ( V_1 )
F_1 ( V_1 ) ;
return V_1 ;
}
int F_4 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 , int V_5 )
{
if ( V_2 )
F_1 ( V_1 ) ;
return F_5 ( V_1 , V_2 , NULL , V_3 , V_4 , V_5 ) ;
}
int F_5 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
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
#ifndef F_6
if ( V_1 -> V_8 && V_1 -> V_2 && ( ! V_2 ||
( V_2 && ( V_2 -> V_9 == V_1 -> V_2 -> V_9 ) ) ) )
goto V_10;
#endif
if ( V_2 )
{
if ( V_1 -> V_2 )
{
unsigned long V_11 = V_1 -> V_11 ;
F_7 ( V_1 ) ;
V_1 -> V_7 = V_5 ;
V_1 -> V_11 = V_11 ;
}
#ifndef F_6
if( V_6 )
{
if ( ! F_8 ( V_6 ) )
{
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
}
else
V_6 = F_10 ( V_2 -> V_9 ) ;
if( V_6 )
{
const T_2 * V_14 = F_11 ( V_6 , V_2 -> V_9 ) ;
if( ! V_14 )
{
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
V_2 = V_14 ;
V_1 -> V_8 = V_6 ;
}
else
V_1 -> V_8 = NULL ;
#endif
#ifdef F_12
return F_13 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
#else
V_1 -> V_2 = V_2 ;
if ( V_1 -> V_2 -> V_15 )
{
V_1 -> V_16 = F_3 ( V_1 -> V_2 -> V_15 ) ;
if ( ! V_1 -> V_16 )
{
F_9 ( V_12 , V_17 ) ;
return 0 ;
}
}
else
{
V_1 -> V_16 = NULL ;
}
V_1 -> V_18 = V_2 -> V_18 ;
V_1 -> V_11 = 0 ;
if( V_1 -> V_2 -> V_11 & V_19 )
{
if( ! F_14 ( V_1 , V_20 , 0 , NULL ) )
{
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
}
#endif
}
else if( ! V_1 -> V_2 )
{
F_9 ( V_12 , V_21 ) ;
return 0 ;
}
#ifndef F_6
V_10:
#endif
#ifdef F_12
return F_13 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
#else
F_15 ( V_1 -> V_2 -> V_22 == 1
|| V_1 -> V_2 -> V_22 == 8
|| V_1 -> V_2 -> V_22 == 16 ) ;
if( ! ( F_16 ( V_1 ) & V_23 ) ) {
switch( F_17 ( V_1 ) ) {
case V_24 :
case V_25 :
break;
case V_26 :
case V_27 :
V_1 -> V_28 = 0 ;
case V_29 :
F_15 ( F_18 ( V_1 ) <=
( int ) sizeof( V_1 -> V_4 ) ) ;
if( V_4 ) memcpy ( V_1 -> V_30 , V_4 , F_18 ( V_1 ) ) ;
memcpy ( V_1 -> V_4 , V_1 -> V_30 , F_18 ( V_1 ) ) ;
break;
case V_31 :
V_1 -> V_28 = 0 ;
if( V_4 )
memcpy ( V_1 -> V_4 , V_4 , F_18 ( V_1 ) ) ;
break;
default:
return 0 ;
break;
}
}
if( V_3 || ( V_1 -> V_2 -> V_11 & V_32 ) ) {
if( ! V_1 -> V_2 -> V_33 ( V_1 , V_3 , V_4 , V_5 ) ) return 0 ;
}
V_1 -> V_34 = 0 ;
V_1 -> V_35 = 0 ;
V_1 -> V_36 = V_1 -> V_2 -> V_22 - 1 ;
return 1 ;
#endif
}
int F_19 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 ,
const unsigned char * V_39 , int V_40 )
{
if ( V_1 -> V_7 )
return F_20 ( V_1 , V_37 , V_38 , V_39 , V_40 ) ;
else return F_21 ( V_1 , V_37 , V_38 , V_39 , V_40 ) ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
if ( V_1 -> V_7 )
return F_23 ( V_1 , V_37 , V_38 ) ;
else return F_24 ( V_1 , V_37 , V_38 ) ;
}
int F_25 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
if ( V_1 -> V_7 )
return F_26 ( V_1 , V_37 , V_38 ) ;
else return F_27 ( V_1 , V_37 , V_38 ) ;
}
int F_28 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_4 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
}
int F_29 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_5 ( V_1 , V_2 , V_6 , V_3 , V_4 , 1 ) ;
}
int F_30 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_4 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_31 ( T_1 * V_1 , const T_2 * V_2 , T_3 * V_6 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_5 ( V_1 , V_2 , V_6 , V_3 , V_4 , 0 ) ;
}
int F_20 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 ,
const unsigned char * V_39 , int V_40 )
{
int V_41 , V_42 , V_43 ;
if ( V_1 -> V_2 -> V_11 & V_44 )
{
V_41 = F_32 ( V_1 , V_37 , V_39 , V_40 ) ;
if ( V_41 < 0 )
return 0 ;
else
* V_38 = V_41 ;
return 1 ;
}
if ( V_40 <= 0 )
{
* V_38 = 0 ;
return V_40 == 0 ;
}
if( V_1 -> V_34 == 0 && ( V_40 & ( V_1 -> V_36 ) ) == 0 )
{
if( F_32 ( V_1 , V_37 , V_39 , V_40 ) )
{
* V_38 = V_40 ;
return 1 ;
}
else
{
* V_38 = 0 ;
return 0 ;
}
}
V_41 = V_1 -> V_34 ;
V_43 = V_1 -> V_2 -> V_22 ;
F_15 ( V_43 <= ( int ) sizeof( V_1 -> V_45 ) ) ;
if ( V_41 != 0 )
{
if ( V_41 + V_40 < V_43 )
{
memcpy ( & ( V_1 -> V_45 [ V_41 ] ) , V_39 , V_40 ) ;
V_1 -> V_34 += V_40 ;
* V_38 = 0 ;
return 1 ;
}
else
{
V_42 = V_43 - V_41 ;
memcpy ( & ( V_1 -> V_45 [ V_41 ] ) , V_39 , V_42 ) ;
if( ! F_32 ( V_1 , V_37 , V_1 -> V_45 , V_43 ) ) return 0 ;
V_40 -= V_42 ;
V_39 += V_42 ;
V_37 += V_43 ;
* V_38 = V_43 ;
}
}
else
* V_38 = 0 ;
V_41 = V_40 & ( V_43 - 1 ) ;
V_40 -= V_41 ;
if ( V_40 > 0 )
{
if( ! F_32 ( V_1 , V_37 , V_39 , V_40 ) ) return 0 ;
* V_38 += V_40 ;
}
if ( V_41 != 0 )
memcpy ( V_1 -> V_45 , & ( V_39 [ V_40 ] ) , V_41 ) ;
V_1 -> V_34 = V_41 ;
return 1 ;
}
int F_26 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
int V_46 ;
V_46 = F_23 ( V_1 , V_37 , V_38 ) ;
return V_46 ;
}
int F_23 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
int V_47 , V_46 ;
unsigned int V_41 , V_48 , V_43 ;
if ( V_1 -> V_2 -> V_11 & V_44 )
{
V_46 = F_32 ( V_1 , V_37 , NULL , 0 ) ;
if ( V_46 < 0 )
return 0 ;
else
* V_38 = V_46 ;
return 1 ;
}
V_48 = V_1 -> V_2 -> V_22 ;
F_15 ( V_48 <= sizeof V_1 -> V_45 ) ;
if ( V_48 == 1 )
{
* V_38 = 0 ;
return 1 ;
}
V_43 = V_1 -> V_34 ;
if ( V_1 -> V_11 & V_49 )
{
if( V_43 )
{
F_9 ( V_50 , V_51 ) ;
return 0 ;
}
* V_38 = 0 ;
return 1 ;
}
V_47 = V_48 - V_43 ;
for ( V_41 = V_43 ; V_41 < V_48 ; V_41 ++ )
V_1 -> V_45 [ V_41 ] = V_47 ;
V_46 = F_32 ( V_1 , V_37 , V_1 -> V_45 , V_48 ) ;
if( V_46 )
* V_38 = V_48 ;
return V_46 ;
}
int F_21 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 ,
const unsigned char * V_39 , int V_40 )
{
int V_52 ;
unsigned int V_48 ;
if ( V_1 -> V_2 -> V_11 & V_44 )
{
V_52 = F_32 ( V_1 , V_37 , V_39 , V_40 ) ;
if ( V_52 < 0 )
{
* V_38 = 0 ;
return 0 ;
}
else
* V_38 = V_52 ;
return 1 ;
}
if ( V_40 <= 0 )
{
* V_38 = 0 ;
return V_40 == 0 ;
}
if ( V_1 -> V_11 & V_49 )
return F_20 ( V_1 , V_37 , V_38 , V_39 , V_40 ) ;
V_48 = V_1 -> V_2 -> V_22 ;
F_15 ( V_48 <= sizeof V_1 -> V_53 ) ;
if( V_1 -> V_35 )
{
memcpy ( V_37 , V_1 -> V_53 , V_48 ) ;
V_37 += V_48 ;
V_52 = 1 ;
}
else
V_52 = 0 ;
if( ! F_20 ( V_1 , V_37 , V_38 , V_39 , V_40 ) )
return 0 ;
if ( V_48 > 1 && ! V_1 -> V_34 )
{
* V_38 -= V_48 ;
V_1 -> V_35 = 1 ;
memcpy ( V_1 -> V_53 , & V_37 [ * V_38 ] , V_48 ) ;
}
else
V_1 -> V_35 = 0 ;
if ( V_52 )
* V_38 += V_48 ;
return 1 ;
}
int F_27 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
int V_46 ;
V_46 = F_24 ( V_1 , V_37 , V_38 ) ;
return V_46 ;
}
int F_24 ( T_1 * V_1 , unsigned char * V_37 , int * V_38 )
{
int V_41 , V_47 ;
unsigned int V_48 ;
* V_38 = 0 ;
if ( V_1 -> V_2 -> V_11 & V_44 )
{
V_41 = F_32 ( V_1 , V_37 , NULL , 0 ) ;
if ( V_41 < 0 )
return 0 ;
else
* V_38 = V_41 ;
return 1 ;
}
V_48 = V_1 -> V_2 -> V_22 ;
if ( V_1 -> V_11 & V_49 )
{
if( V_1 -> V_34 )
{
F_9 ( V_54 , V_51 ) ;
return 0 ;
}
* V_38 = 0 ;
return 1 ;
}
if ( V_48 > 1 )
{
if ( V_1 -> V_34 || ! V_1 -> V_35 )
{
F_9 ( V_54 , V_55 ) ;
return ( 0 ) ;
}
F_15 ( V_48 <= sizeof V_1 -> V_53 ) ;
V_47 = V_1 -> V_53 [ V_48 - 1 ] ;
if ( V_47 == 0 || V_47 > ( int ) V_48 )
{
F_9 ( V_54 , V_56 ) ;
return ( 0 ) ;
}
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ )
{
if ( V_1 -> V_53 [ -- V_48 ] != V_47 )
{
F_9 ( V_54 , V_56 ) ;
return ( 0 ) ;
}
}
V_47 = V_1 -> V_2 -> V_22 - V_47 ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ )
V_37 [ V_41 ] = V_1 -> V_53 [ V_41 ] ;
* V_38 = V_47 ;
}
else
* V_38 = 0 ;
return ( 1 ) ;
}
void F_33 ( T_1 * V_1 )
{
if ( V_1 )
{
F_7 ( V_1 ) ;
F_34 ( V_1 ) ;
}
}
int F_7 ( T_1 * V_14 )
{
#ifndef F_12
if ( V_14 -> V_2 != NULL )
{
if( V_14 -> V_2 -> V_57 && ! V_14 -> V_2 -> V_57 ( V_14 ) )
return 0 ;
if ( V_14 -> V_16 )
F_35 ( V_14 -> V_16 , V_14 -> V_2 -> V_15 ) ;
}
if ( V_14 -> V_16 )
F_34 ( V_14 -> V_16 ) ;
#endif
#ifndef F_6
if ( V_14 -> V_8 )
F_36 ( V_14 -> V_8 ) ;
#endif
#ifdef F_12
F_37 ( V_14 ) ;
#endif
memset ( V_14 , 0 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_38 ( T_1 * V_14 , int V_58 )
{
if( V_14 -> V_2 -> V_11 & V_59 )
return F_14 ( V_14 , V_60 , V_58 , NULL ) ;
if( V_14 -> V_18 == V_58 ) return 1 ;
if( ( V_58 > 0 ) && ( V_14 -> V_2 -> V_11 & V_61 ) )
{
V_14 -> V_18 = V_58 ;
return 1 ;
}
F_9 ( V_62 , V_63 ) ;
return 0 ;
}
int F_39 ( T_1 * V_1 , int V_64 )
{
if ( V_64 ) V_1 -> V_11 &= ~ V_49 ;
else V_1 -> V_11 |= V_49 ;
return 1 ;
}
int F_14 ( T_1 * V_1 , int type , int V_65 , void * V_66 )
{
int V_46 ;
if( ! V_1 -> V_2 ) {
F_9 ( V_67 , V_21 ) ;
return 0 ;
}
if( ! V_1 -> V_2 -> V_68 ) {
F_9 ( V_67 , V_69 ) ;
return 0 ;
}
V_46 = V_1 -> V_2 -> V_68 ( V_1 , type , V_65 , V_66 ) ;
if( V_46 == - 1 ) {
F_9 ( V_67 , V_70 ) ;
return 0 ;
}
return V_46 ;
}
int F_40 ( T_1 * V_1 , unsigned char * V_3 )
{
if ( V_1 -> V_2 -> V_11 & V_71 )
return F_14 ( V_1 , V_72 , 0 , V_3 ) ;
if ( F_41 ( V_3 , V_1 -> V_18 ) <= 0 )
return 0 ;
return 1 ;
}
int F_42 ( T_1 * V_37 , const T_1 * V_39 )
{
if ( ( V_39 == NULL ) || ( V_39 -> V_2 == NULL ) )
{
F_9 ( V_73 , V_74 ) ;
return 0 ;
}
#ifndef F_6
if ( V_39 -> V_8 && ! F_8 ( V_39 -> V_8 ) )
{
F_9 ( V_73 , V_75 ) ;
return 0 ;
}
#endif
F_7 ( V_37 ) ;
memcpy ( V_37 , V_39 , sizeof *V_37 ) ;
if ( V_39 -> V_16 && V_39 -> V_2 -> V_15 )
{
V_37 -> V_16 = F_3 ( V_39 -> V_2 -> V_15 ) ;
if ( ! V_37 -> V_16 )
{
F_9 ( V_73 , V_17 ) ;
return 0 ;
}
memcpy ( V_37 -> V_16 , V_39 -> V_16 , V_39 -> V_2 -> V_15 ) ;
}
if ( V_39 -> V_2 -> V_11 & V_76 )
return V_39 -> V_2 -> V_68 ( ( T_1 * ) V_39 , V_77 , 0 , V_37 ) ;
return 1 ;
}
