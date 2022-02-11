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
int F_5 ( T_1 * V_1 , const T_2 * V_2 ,
T_3 * V_6 , const unsigned char * V_3 ,
const unsigned char * V_4 , int V_5 )
{
if ( V_5 == - 1 )
V_5 = V_1 -> V_7 ;
else {
if ( V_5 )
V_5 = 1 ;
V_1 -> V_7 = V_5 ;
}
#ifndef F_6
if ( V_1 -> V_8 && V_1 -> V_2 && ( ! V_2 ||
( V_2
&& ( V_2 -> V_9 ==
V_1 -> V_2 -> V_9 ) ) ) )
goto V_10;
#endif
if ( V_2 ) {
if ( V_1 -> V_2 ) {
unsigned long V_11 = V_1 -> V_11 ;
F_7 ( V_1 ) ;
V_1 -> V_7 = V_5 ;
V_1 -> V_11 = V_11 ;
}
#ifndef F_6
if ( V_6 ) {
if ( ! F_8 ( V_6 ) ) {
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
} else
V_6 = F_10 ( V_2 -> V_9 ) ;
if ( V_6 ) {
const T_2 * V_14 = F_11 ( V_6 , V_2 -> V_9 ) ;
if ( ! V_14 ) {
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
V_2 = V_14 ;
V_1 -> V_8 = V_6 ;
} else
V_1 -> V_8 = NULL ;
#endif
#ifdef F_12
if ( F_13 () ) {
const T_2 * V_15 ;
if ( V_2 )
V_15 = F_14 ( V_2 ) ;
if ( V_15 )
V_2 = V_15 ;
return F_15 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
}
#endif
V_1 -> V_2 = V_2 ;
if ( V_1 -> V_2 -> V_16 ) {
V_1 -> V_17 = F_3 ( V_1 -> V_2 -> V_16 ) ;
if ( ! V_1 -> V_17 ) {
F_9 ( V_12 , V_18 ) ;
return 0 ;
}
} else {
V_1 -> V_17 = NULL ;
}
V_1 -> V_19 = V_2 -> V_19 ;
V_1 -> V_11 &= V_20 ;
if ( V_1 -> V_2 -> V_11 & V_21 ) {
if ( ! F_16 ( V_1 , V_22 , 0 , NULL ) ) {
F_9 ( V_12 , V_13 ) ;
return 0 ;
}
}
} else if ( ! V_1 -> V_2 ) {
F_9 ( V_12 , V_23 ) ;
return 0 ;
}
#ifndef F_6
V_10:
#endif
#ifdef F_12
if ( F_13 () )
return F_15 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
#endif
F_17 ( V_1 -> V_2 -> V_24 == 1
|| V_1 -> V_2 -> V_24 == 8
|| V_1 -> V_2 -> V_24 == 16 ) ;
if ( ! ( V_1 -> V_11 & V_20 )
&& F_18 ( V_1 ) == V_25 ) {
F_9 ( V_12 , V_26 ) ;
return 0 ;
}
if ( ! ( F_19 ( V_1 ) & V_27 ) ) {
switch ( F_18 ( V_1 ) ) {
case V_28 :
case V_29 :
break;
case V_30 :
case V_31 :
V_1 -> V_32 = 0 ;
case V_33 :
F_17 ( F_20 ( V_1 ) <=
( int ) sizeof( V_1 -> V_4 ) ) ;
if ( V_4 )
memcpy ( V_1 -> V_34 , V_4 , F_20 ( V_1 ) ) ;
memcpy ( V_1 -> V_4 , V_1 -> V_34 , F_20 ( V_1 ) ) ;
break;
case V_35 :
V_1 -> V_32 = 0 ;
if ( V_4 )
memcpy ( V_1 -> V_4 , V_4 , F_20 ( V_1 ) ) ;
break;
default:
return 0 ;
break;
}
}
if ( V_3 || ( V_1 -> V_2 -> V_11 & V_36 ) ) {
if ( ! V_1 -> V_2 -> V_37 ( V_1 , V_3 , V_4 , V_5 ) )
return 0 ;
}
V_1 -> V_38 = 0 ;
V_1 -> V_39 = 0 ;
V_1 -> V_40 = V_1 -> V_2 -> V_24 - 1 ;
return 1 ;
}
int F_21 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
if ( V_1 -> V_7 )
return F_22 ( V_1 , V_41 , V_42 , V_43 , V_44 ) ;
else
return F_23 ( V_1 , V_41 , V_42 , V_43 , V_44 ) ;
}
int F_24 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
if ( V_1 -> V_7 )
return F_25 ( V_1 , V_41 , V_42 ) ;
else
return F_26 ( V_1 , V_41 , V_42 ) ;
}
int F_27 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
if ( V_1 -> V_7 )
return F_28 ( V_1 , V_41 , V_42 ) ;
else
return F_29 ( V_1 , V_41 , V_42 ) ;
}
int F_30 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_4 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
}
int F_31 ( T_1 * V_1 , const T_2 * V_2 ,
T_3 * V_6 , const unsigned char * V_3 ,
const unsigned char * V_4 )
{
return F_5 ( V_1 , V_2 , V_6 , V_3 , V_4 , 1 ) ;
}
int F_32 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , const unsigned char * V_4 )
{
return F_4 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
}
int F_33 ( T_1 * V_1 , const T_2 * V_2 ,
T_3 * V_6 , const unsigned char * V_3 ,
const unsigned char * V_4 )
{
return F_5 ( V_1 , V_2 , V_6 , V_3 , V_4 , 0 ) ;
}
int F_22 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
int V_45 , V_46 , V_47 ;
if ( V_1 -> V_2 -> V_11 & V_48 ) {
V_45 = F_34 ( V_1 , V_41 , V_43 , V_44 ) ;
if ( V_45 < 0 )
return 0 ;
else
* V_42 = V_45 ;
return 1 ;
}
if ( V_44 <= 0 ) {
* V_42 = 0 ;
return V_44 == 0 ;
}
if ( V_1 -> V_38 == 0 && ( V_44 & ( V_1 -> V_40 ) ) == 0 ) {
if ( F_34 ( V_1 , V_41 , V_43 , V_44 ) ) {
* V_42 = V_44 ;
return 1 ;
} else {
* V_42 = 0 ;
return 0 ;
}
}
V_45 = V_1 -> V_38 ;
V_47 = V_1 -> V_2 -> V_24 ;
F_17 ( V_47 <= ( int ) sizeof( V_1 -> V_49 ) ) ;
if ( V_45 != 0 ) {
if ( V_45 + V_44 < V_47 ) {
memcpy ( & ( V_1 -> V_49 [ V_45 ] ) , V_43 , V_44 ) ;
V_1 -> V_38 += V_44 ;
* V_42 = 0 ;
return 1 ;
} else {
V_46 = V_47 - V_45 ;
memcpy ( & ( V_1 -> V_49 [ V_45 ] ) , V_43 , V_46 ) ;
if ( ! F_34 ( V_1 , V_41 , V_1 -> V_49 , V_47 ) )
return 0 ;
V_44 -= V_46 ;
V_43 += V_46 ;
V_41 += V_47 ;
* V_42 = V_47 ;
}
} else
* V_42 = 0 ;
V_45 = V_44 & ( V_47 - 1 ) ;
V_44 -= V_45 ;
if ( V_44 > 0 ) {
if ( ! F_34 ( V_1 , V_41 , V_43 , V_44 ) )
return 0 ;
* V_42 += V_44 ;
}
if ( V_45 != 0 )
memcpy ( V_1 -> V_49 , & ( V_43 [ V_44 ] ) , V_45 ) ;
V_1 -> V_38 = V_45 ;
return 1 ;
}
int F_28 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
int V_50 ;
V_50 = F_25 ( V_1 , V_41 , V_42 ) ;
return V_50 ;
}
int F_25 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
int V_51 , V_50 ;
unsigned int V_45 , V_52 , V_47 ;
if ( V_1 -> V_2 -> V_11 & V_48 ) {
V_50 = F_34 ( V_1 , V_41 , NULL , 0 ) ;
if ( V_50 < 0 )
return 0 ;
else
* V_42 = V_50 ;
return 1 ;
}
V_52 = V_1 -> V_2 -> V_24 ;
F_17 ( V_52 <= sizeof V_1 -> V_49 ) ;
if ( V_52 == 1 ) {
* V_42 = 0 ;
return 1 ;
}
V_47 = V_1 -> V_38 ;
if ( V_1 -> V_11 & V_53 ) {
if ( V_47 ) {
F_9 ( V_54 ,
V_55 ) ;
return 0 ;
}
* V_42 = 0 ;
return 1 ;
}
V_51 = V_52 - V_47 ;
for ( V_45 = V_47 ; V_45 < V_52 ; V_45 ++ )
V_1 -> V_49 [ V_45 ] = V_51 ;
V_50 = F_34 ( V_1 , V_41 , V_1 -> V_49 , V_52 ) ;
if ( V_50 )
* V_42 = V_52 ;
return V_50 ;
}
int F_23 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
int V_56 ;
unsigned int V_52 ;
if ( V_1 -> V_2 -> V_11 & V_48 ) {
V_56 = F_34 ( V_1 , V_41 , V_43 , V_44 ) ;
if ( V_56 < 0 ) {
* V_42 = 0 ;
return 0 ;
} else
* V_42 = V_56 ;
return 1 ;
}
if ( V_44 <= 0 ) {
* V_42 = 0 ;
return V_44 == 0 ;
}
if ( V_1 -> V_11 & V_53 )
return F_22 ( V_1 , V_41 , V_42 , V_43 , V_44 ) ;
V_52 = V_1 -> V_2 -> V_24 ;
F_17 ( V_52 <= sizeof V_1 -> V_57 ) ;
if ( V_1 -> V_39 ) {
memcpy ( V_41 , V_1 -> V_57 , V_52 ) ;
V_41 += V_52 ;
V_56 = 1 ;
} else
V_56 = 0 ;
if ( ! F_22 ( V_1 , V_41 , V_42 , V_43 , V_44 ) )
return 0 ;
if ( V_52 > 1 && ! V_1 -> V_38 ) {
* V_42 -= V_52 ;
V_1 -> V_39 = 1 ;
memcpy ( V_1 -> V_57 , & V_41 [ * V_42 ] , V_52 ) ;
} else
V_1 -> V_39 = 0 ;
if ( V_56 )
* V_42 += V_52 ;
return 1 ;
}
int F_29 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
int V_50 ;
V_50 = F_26 ( V_1 , V_41 , V_42 ) ;
return V_50 ;
}
int F_26 ( T_1 * V_1 , unsigned char * V_41 , int * V_42 )
{
int V_45 , V_51 ;
unsigned int V_52 ;
* V_42 = 0 ;
if ( V_1 -> V_2 -> V_11 & V_48 ) {
V_45 = F_34 ( V_1 , V_41 , NULL , 0 ) ;
if ( V_45 < 0 )
return 0 ;
else
* V_42 = V_45 ;
return 1 ;
}
V_52 = V_1 -> V_2 -> V_24 ;
if ( V_1 -> V_11 & V_53 ) {
if ( V_1 -> V_38 ) {
F_9 ( V_58 ,
V_55 ) ;
return 0 ;
}
* V_42 = 0 ;
return 1 ;
}
if ( V_52 > 1 ) {
if ( V_1 -> V_38 || ! V_1 -> V_39 ) {
F_9 ( V_58 , V_59 ) ;
return ( 0 ) ;
}
F_17 ( V_52 <= sizeof V_1 -> V_57 ) ;
V_51 = V_1 -> V_57 [ V_52 - 1 ] ;
if ( V_51 == 0 || V_51 > ( int ) V_52 ) {
F_9 ( V_58 , V_60 ) ;
return ( 0 ) ;
}
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ ) {
if ( V_1 -> V_57 [ -- V_52 ] != V_51 ) {
F_9 ( V_58 , V_60 ) ;
return ( 0 ) ;
}
}
V_51 = V_1 -> V_2 -> V_24 - V_51 ;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ )
V_41 [ V_45 ] = V_1 -> V_57 [ V_45 ] ;
* V_42 = V_51 ;
} else
* V_42 = 0 ;
return ( 1 ) ;
}
void F_35 ( T_1 * V_1 )
{
if ( V_1 ) {
F_7 ( V_1 ) ;
F_36 ( V_1 ) ;
}
}
int F_7 ( T_1 * V_14 )
{
#ifndef F_12
if ( V_14 -> V_2 != NULL ) {
if ( V_14 -> V_2 -> V_61 && ! V_14 -> V_2 -> V_61 ( V_14 ) )
return 0 ;
if ( V_14 -> V_17 )
F_37 ( V_14 -> V_17 , V_14 -> V_2 -> V_16 ) ;
}
if ( V_14 -> V_17 )
F_36 ( V_14 -> V_17 ) ;
#endif
#ifndef F_6
if ( V_14 -> V_8 )
F_38 ( V_14 -> V_8 ) ;
#endif
#ifdef F_12
F_39 ( V_14 ) ;
#endif
memset ( V_14 , 0 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_40 ( T_1 * V_14 , int V_62 )
{
if ( V_14 -> V_2 -> V_11 & V_63 )
return F_16 ( V_14 , V_64 , V_62 , NULL ) ;
if ( V_14 -> V_19 == V_62 )
return 1 ;
if ( ( V_62 > 0 ) && ( V_14 -> V_2 -> V_11 & V_65 ) ) {
V_14 -> V_19 = V_62 ;
return 1 ;
}
F_9 ( V_66 , V_67 ) ;
return 0 ;
}
int F_41 ( T_1 * V_1 , int V_68 )
{
if ( V_68 )
V_1 -> V_11 &= ~ V_53 ;
else
V_1 -> V_11 |= V_53 ;
return 1 ;
}
int F_16 ( T_1 * V_1 , int type , int V_69 , void * V_70 )
{
int V_50 ;
if ( ! V_1 -> V_2 ) {
F_9 ( V_71 , V_23 ) ;
return 0 ;
}
if ( ! V_1 -> V_2 -> V_72 ) {
F_9 ( V_71 , V_73 ) ;
return 0 ;
}
V_50 = V_1 -> V_2 -> V_72 ( V_1 , type , V_69 , V_70 ) ;
if ( V_50 == - 1 ) {
F_9 ( V_71 ,
V_74 ) ;
return 0 ;
}
return V_50 ;
}
int F_42 ( T_1 * V_1 , unsigned char * V_3 )
{
if ( V_1 -> V_2 -> V_11 & V_75 )
return F_16 ( V_1 , V_76 , 0 , V_3 ) ;
if ( F_43 ( V_3 , V_1 -> V_19 ) <= 0 )
return 0 ;
return 1 ;
}
int F_44 ( T_1 * V_41 , const T_1 * V_43 )
{
if ( ( V_43 == NULL ) || ( V_43 -> V_2 == NULL ) ) {
F_9 ( V_77 , V_78 ) ;
return 0 ;
}
#ifndef F_6
if ( V_43 -> V_8 && ! F_8 ( V_43 -> V_8 ) ) {
F_9 ( V_77 , V_79 ) ;
return 0 ;
}
#endif
F_7 ( V_41 ) ;
memcpy ( V_41 , V_43 , sizeof *V_41 ) ;
if ( V_43 -> V_17 && V_43 -> V_2 -> V_16 ) {
V_41 -> V_17 = F_3 ( V_43 -> V_2 -> V_16 ) ;
if ( ! V_41 -> V_17 ) {
F_9 ( V_77 , V_18 ) ;
return 0 ;
}
memcpy ( V_41 -> V_17 , V_43 -> V_17 , V_43 -> V_2 -> V_16 ) ;
}
if ( V_43 -> V_2 -> V_11 & V_80 )
return V_43 -> V_2 -> V_72 ( ( T_1 * ) V_43 , V_81 , 0 , V_41 ) ;
return 1 ;
}
