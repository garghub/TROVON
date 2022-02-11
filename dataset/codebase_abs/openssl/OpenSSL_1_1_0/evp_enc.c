int F_1 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return 1 ;
if ( V_1 -> V_2 != NULL ) {
if ( V_1 -> V_2 -> V_3 && ! V_1 -> V_2 -> V_3 ( V_1 ) )
return 0 ;
if ( V_1 -> V_4 && V_1 -> V_2 -> V_5 )
F_2 ( V_1 -> V_4 , V_1 -> V_2 -> V_5 ) ;
}
F_3 ( V_1 -> V_4 ) ;
#ifndef F_4
F_5 ( V_1 -> V_6 ) ;
#endif
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
return 1 ;
}
T_1 * F_6 ( void )
{
return F_7 ( sizeof( T_1 ) ) ;
}
void F_8 ( T_1 * V_7 )
{
F_1 ( V_7 ) ;
F_3 ( V_7 ) ;
}
int F_9 ( T_1 * V_7 , const T_2 * V_2 ,
const unsigned char * V_8 , const unsigned char * V_9 , int V_10 )
{
F_1 ( V_7 ) ;
return F_10 ( V_7 , V_2 , NULL , V_8 , V_9 , V_10 ) ;
}
int F_10 ( T_1 * V_7 , const T_2 * V_2 ,
T_3 * V_11 , const unsigned char * V_8 ,
const unsigned char * V_9 , int V_10 )
{
if ( V_10 == - 1 )
V_10 = V_7 -> V_12 ;
else {
if ( V_10 )
V_10 = 1 ;
V_7 -> V_12 = V_10 ;
}
#ifndef F_4
if ( V_7 -> V_6 && V_7 -> V_2
&& ( V_2 == NULL || V_2 -> V_13 == V_7 -> V_2 -> V_13 ) )
goto V_14;
#endif
if ( V_2 ) {
if ( V_7 -> V_2 ) {
unsigned long V_15 = V_7 -> V_15 ;
F_1 ( V_7 ) ;
V_7 -> V_12 = V_10 ;
V_7 -> V_15 = V_15 ;
}
#ifndef F_4
if ( V_11 ) {
if ( ! F_11 ( V_11 ) ) {
F_12 ( V_16 , V_17 ) ;
return 0 ;
}
} else
V_11 = F_13 ( V_2 -> V_13 ) ;
if ( V_11 ) {
const T_2 * V_1 = F_14 ( V_11 , V_2 -> V_13 ) ;
if ( ! V_1 ) {
F_12 ( V_16 , V_17 ) ;
return 0 ;
}
V_2 = V_1 ;
V_7 -> V_6 = V_11 ;
} else
V_7 -> V_6 = NULL ;
#endif
V_7 -> V_2 = V_2 ;
if ( V_7 -> V_2 -> V_5 ) {
V_7 -> V_4 = F_7 ( V_7 -> V_2 -> V_5 ) ;
if ( V_7 -> V_4 == NULL ) {
F_12 ( V_16 , V_18 ) ;
return 0 ;
}
} else {
V_7 -> V_4 = NULL ;
}
V_7 -> V_19 = V_2 -> V_19 ;
V_7 -> V_15 &= V_20 ;
if ( V_7 -> V_2 -> V_15 & V_21 ) {
if ( ! F_15 ( V_7 , V_22 , 0 , NULL ) ) {
F_12 ( V_16 , V_17 ) ;
return 0 ;
}
}
} else if ( ! V_7 -> V_2 ) {
F_12 ( V_16 , V_23 ) ;
return 0 ;
}
#ifndef F_4
V_14:
#endif
F_16 ( V_7 -> V_2 -> V_24 == 1
|| V_7 -> V_2 -> V_24 == 8
|| V_7 -> V_2 -> V_24 == 16 ) ;
if ( ! ( V_7 -> V_15 & V_20 )
&& F_17 ( V_7 ) == V_25 ) {
F_12 ( V_16 , V_26 ) ;
return 0 ;
}
if ( ! ( F_18 ( F_19 ( V_7 ) ) & V_27 ) ) {
switch ( F_17 ( V_7 ) ) {
case V_28 :
case V_29 :
break;
case V_30 :
case V_31 :
V_7 -> V_32 = 0 ;
case V_33 :
F_16 ( F_20 ( V_7 ) <=
( int ) sizeof( V_7 -> V_9 ) ) ;
if ( V_9 )
memcpy ( V_7 -> V_34 , V_9 , F_20 ( V_7 ) ) ;
memcpy ( V_7 -> V_9 , V_7 -> V_34 , F_20 ( V_7 ) ) ;
break;
case V_35 :
V_7 -> V_32 = 0 ;
if ( V_9 )
memcpy ( V_7 -> V_9 , V_9 , F_20 ( V_7 ) ) ;
break;
default:
return 0 ;
}
}
if ( V_8 || ( V_7 -> V_2 -> V_15 & V_36 ) ) {
if ( ! V_7 -> V_2 -> V_37 ( V_7 , V_8 , V_9 , V_10 ) )
return 0 ;
}
V_7 -> V_38 = 0 ;
V_7 -> V_39 = 0 ;
V_7 -> V_40 = V_7 -> V_2 -> V_24 - 1 ;
return 1 ;
}
int F_21 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
if ( V_7 -> V_12 )
return F_22 ( V_7 , V_41 , V_42 , V_43 , V_44 ) ;
else
return F_23 ( V_7 , V_41 , V_42 , V_43 , V_44 ) ;
}
int F_24 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
if ( V_7 -> V_12 )
return F_25 ( V_7 , V_41 , V_42 ) ;
else
return F_26 ( V_7 , V_41 , V_42 ) ;
}
int F_27 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
if ( V_7 -> V_12 )
return F_28 ( V_7 , V_41 , V_42 ) ;
else
return F_29 ( V_7 , V_41 , V_42 ) ;
}
int F_30 ( T_1 * V_7 , const T_2 * V_2 ,
const unsigned char * V_8 , const unsigned char * V_9 )
{
return F_9 ( V_7 , V_2 , V_8 , V_9 , 1 ) ;
}
int F_31 ( T_1 * V_7 , const T_2 * V_2 ,
T_3 * V_11 , const unsigned char * V_8 ,
const unsigned char * V_9 )
{
return F_10 ( V_7 , V_2 , V_11 , V_8 , V_9 , 1 ) ;
}
int F_32 ( T_1 * V_7 , const T_2 * V_2 ,
const unsigned char * V_8 , const unsigned char * V_9 )
{
return F_9 ( V_7 , V_2 , V_8 , V_9 , 0 ) ;
}
int F_33 ( T_1 * V_7 , const T_2 * V_2 ,
T_3 * V_11 , const unsigned char * V_8 ,
const unsigned char * V_9 )
{
return F_10 ( V_7 , V_2 , V_11 , V_8 , V_9 , 0 ) ;
}
static int F_34 ( const void * V_45 , const void * V_46 ,
int V_47 )
{
T_4 V_48 = ( T_4 ) V_45 - ( T_4 ) V_46 ;
int V_49 = ( V_47 > 0 ) & ( V_48 != 0 ) & ( ( V_48 < ( T_4 ) V_47 ) |
( V_48 > ( 0 - ( T_4 ) V_47 ) ) ) ;
assert ( ! V_49 ) ;
return V_49 ;
}
int F_22 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
int V_50 , V_51 , V_52 ;
if ( V_7 -> V_2 -> V_15 & V_53 ) {
if ( F_34 ( V_41 , V_43 , V_44 ) ) {
F_12 ( V_54 , V_55 ) ;
return 0 ;
}
V_50 = V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_43 , V_44 ) ;
if ( V_50 < 0 )
return 0 ;
else
* V_42 = V_50 ;
return 1 ;
}
if ( V_44 <= 0 ) {
* V_42 = 0 ;
return V_44 == 0 ;
}
if ( F_34 ( V_41 , V_43 , V_44 ) ) {
F_12 ( V_54 , V_55 ) ;
return 0 ;
}
if ( V_7 -> V_38 == 0 && ( V_44 & ( V_7 -> V_40 ) ) == 0 ) {
if ( V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_43 , V_44 ) ) {
* V_42 = V_44 ;
return 1 ;
} else {
* V_42 = 0 ;
return 0 ;
}
}
V_50 = V_7 -> V_38 ;
V_52 = V_7 -> V_2 -> V_24 ;
F_16 ( V_52 <= ( int ) sizeof( V_7 -> V_57 ) ) ;
if ( V_50 != 0 ) {
if ( V_52 - V_50 > V_44 ) {
memcpy ( & ( V_7 -> V_57 [ V_50 ] ) , V_43 , V_44 ) ;
V_7 -> V_38 += V_44 ;
* V_42 = 0 ;
return 1 ;
} else {
V_51 = V_52 - V_50 ;
memcpy ( & ( V_7 -> V_57 [ V_50 ] ) , V_43 , V_51 ) ;
V_44 -= V_51 ;
V_43 += V_51 ;
if ( F_34 ( V_41 , V_43 , V_52 ) ) {
F_12 ( V_54 , V_55 ) ;
return 0 ;
}
if ( ! V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_7 -> V_57 , V_52 ) )
return 0 ;
V_41 += V_52 ;
* V_42 = V_52 ;
}
} else
* V_42 = 0 ;
V_50 = V_44 & ( V_52 - 1 ) ;
V_44 -= V_50 ;
if ( V_44 > 0 ) {
if ( ! V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_43 , V_44 ) )
return 0 ;
* V_42 += V_44 ;
}
if ( V_50 != 0 )
memcpy ( V_7 -> V_57 , & ( V_43 [ V_44 ] ) , V_50 ) ;
V_7 -> V_38 = V_50 ;
return 1 ;
}
int F_28 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
int V_58 ;
V_58 = F_25 ( V_7 , V_41 , V_42 ) ;
return V_58 ;
}
int F_25 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
int V_59 , V_58 ;
unsigned int V_50 , V_60 , V_52 ;
if ( V_7 -> V_2 -> V_15 & V_53 ) {
V_58 = V_7 -> V_2 -> V_56 ( V_7 , V_41 , NULL , 0 ) ;
if ( V_58 < 0 )
return 0 ;
else
* V_42 = V_58 ;
return 1 ;
}
V_60 = V_7 -> V_2 -> V_24 ;
F_16 ( V_60 <= sizeof V_7 -> V_57 ) ;
if ( V_60 == 1 ) {
* V_42 = 0 ;
return 1 ;
}
V_52 = V_7 -> V_38 ;
if ( V_7 -> V_15 & V_61 ) {
if ( V_52 ) {
F_12 ( V_62 ,
V_63 ) ;
return 0 ;
}
* V_42 = 0 ;
return 1 ;
}
V_59 = V_60 - V_52 ;
for ( V_50 = V_52 ; V_50 < V_60 ; V_50 ++ )
V_7 -> V_57 [ V_50 ] = V_59 ;
V_58 = V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_7 -> V_57 , V_60 ) ;
if ( V_58 )
* V_42 = V_60 ;
return V_58 ;
}
int F_23 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 ,
const unsigned char * V_43 , int V_44 )
{
int V_64 ;
unsigned int V_60 ;
if ( V_7 -> V_2 -> V_15 & V_53 ) {
if ( F_34 ( V_41 , V_43 , V_44 ) ) {
F_12 ( V_65 , V_55 ) ;
return 0 ;
}
V_64 = V_7 -> V_2 -> V_56 ( V_7 , V_41 , V_43 , V_44 ) ;
if ( V_64 < 0 ) {
* V_42 = 0 ;
return 0 ;
} else
* V_42 = V_64 ;
return 1 ;
}
if ( V_44 <= 0 ) {
* V_42 = 0 ;
return V_44 == 0 ;
}
if ( V_7 -> V_15 & V_61 )
return F_22 ( V_7 , V_41 , V_42 , V_43 , V_44 ) ;
V_60 = V_7 -> V_2 -> V_24 ;
F_16 ( V_60 <= sizeof V_7 -> V_66 ) ;
if ( V_7 -> V_39 ) {
if ( ( ( T_4 ) V_41 == ( T_4 ) V_43 )
|| F_34 ( V_41 , V_43 , V_60 ) ) {
F_12 ( V_65 , V_55 ) ;
return 0 ;
}
memcpy ( V_41 , V_7 -> V_66 , V_60 ) ;
V_41 += V_60 ;
V_64 = 1 ;
} else
V_64 = 0 ;
if ( ! F_22 ( V_7 , V_41 , V_42 , V_43 , V_44 ) )
return 0 ;
if ( V_60 > 1 && ! V_7 -> V_38 ) {
* V_42 -= V_60 ;
V_7 -> V_39 = 1 ;
memcpy ( V_7 -> V_66 , & V_41 [ * V_42 ] , V_60 ) ;
} else
V_7 -> V_39 = 0 ;
if ( V_64 )
* V_42 += V_60 ;
return 1 ;
}
int F_29 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
int V_58 ;
V_58 = F_26 ( V_7 , V_41 , V_42 ) ;
return V_58 ;
}
int F_26 ( T_1 * V_7 , unsigned char * V_41 , int * V_42 )
{
int V_50 , V_59 ;
unsigned int V_60 ;
* V_42 = 0 ;
if ( V_7 -> V_2 -> V_15 & V_53 ) {
V_50 = V_7 -> V_2 -> V_56 ( V_7 , V_41 , NULL , 0 ) ;
if ( V_50 < 0 )
return 0 ;
else
* V_42 = V_50 ;
return 1 ;
}
V_60 = V_7 -> V_2 -> V_24 ;
if ( V_7 -> V_15 & V_61 ) {
if ( V_7 -> V_38 ) {
F_12 ( V_67 ,
V_63 ) ;
return 0 ;
}
* V_42 = 0 ;
return 1 ;
}
if ( V_60 > 1 ) {
if ( V_7 -> V_38 || ! V_7 -> V_39 ) {
F_12 ( V_67 , V_68 ) ;
return ( 0 ) ;
}
F_16 ( V_60 <= sizeof V_7 -> V_66 ) ;
V_59 = V_7 -> V_66 [ V_60 - 1 ] ;
if ( V_59 == 0 || V_59 > ( int ) V_60 ) {
F_12 ( V_67 , V_69 ) ;
return ( 0 ) ;
}
for ( V_50 = 0 ; V_50 < V_59 ; V_50 ++ ) {
if ( V_7 -> V_66 [ -- V_60 ] != V_59 ) {
F_12 ( V_67 , V_69 ) ;
return ( 0 ) ;
}
}
V_59 = V_7 -> V_2 -> V_24 - V_59 ;
for ( V_50 = 0 ; V_50 < V_59 ; V_50 ++ )
V_41 [ V_50 ] = V_7 -> V_66 [ V_50 ] ;
* V_42 = V_59 ;
} else
* V_42 = 0 ;
return ( 1 ) ;
}
int F_35 ( T_1 * V_1 , int V_70 )
{
if ( V_1 -> V_2 -> V_15 & V_71 )
return F_15 ( V_1 , V_72 , V_70 , NULL ) ;
if ( V_1 -> V_19 == V_70 )
return 1 ;
if ( ( V_70 > 0 ) && ( V_1 -> V_2 -> V_15 & V_73 ) ) {
V_1 -> V_19 = V_70 ;
return 1 ;
}
F_12 ( V_74 , V_75 ) ;
return 0 ;
}
int F_36 ( T_1 * V_7 , int V_76 )
{
if ( V_76 )
V_7 -> V_15 &= ~ V_61 ;
else
V_7 -> V_15 |= V_61 ;
return 1 ;
}
int F_15 ( T_1 * V_7 , int type , int V_77 , void * V_78 )
{
int V_58 ;
if ( ! V_7 -> V_2 ) {
F_12 ( V_79 , V_23 ) ;
return 0 ;
}
if ( ! V_7 -> V_2 -> V_80 ) {
F_12 ( V_79 , V_81 ) ;
return 0 ;
}
V_58 = V_7 -> V_2 -> V_80 ( V_7 , type , V_77 , V_78 ) ;
if ( V_58 == - 1 ) {
F_12 ( V_79 ,
V_82 ) ;
return 0 ;
}
return V_58 ;
}
int F_37 ( T_1 * V_7 , unsigned char * V_8 )
{
if ( V_7 -> V_2 -> V_15 & V_83 )
return F_15 ( V_7 , V_84 , 0 , V_8 ) ;
if ( F_38 ( V_8 , V_7 -> V_19 ) <= 0 )
return 0 ;
return 1 ;
}
int F_39 ( T_1 * V_41 , const T_1 * V_43 )
{
if ( ( V_43 == NULL ) || ( V_43 -> V_2 == NULL ) ) {
F_12 ( V_85 , V_86 ) ;
return 0 ;
}
#ifndef F_4
if ( V_43 -> V_6 && ! F_11 ( V_43 -> V_6 ) ) {
F_12 ( V_85 , V_87 ) ;
return 0 ;
}
#endif
F_1 ( V_41 ) ;
memcpy ( V_41 , V_43 , sizeof( * V_41 ) ) ;
if ( V_43 -> V_4 && V_43 -> V_2 -> V_5 ) {
V_41 -> V_4 = F_40 ( V_43 -> V_2 -> V_5 ) ;
if ( V_41 -> V_4 == NULL ) {
F_12 ( V_85 , V_18 ) ;
return 0 ;
}
memcpy ( V_41 -> V_4 , V_43 -> V_4 , V_43 -> V_2 -> V_5 ) ;
}
if ( V_43 -> V_2 -> V_15 & V_88 )
return V_43 -> V_2 -> V_80 ( ( T_1 * ) V_43 , V_89 , 0 , V_41 ) ;
return 1 ;
}
