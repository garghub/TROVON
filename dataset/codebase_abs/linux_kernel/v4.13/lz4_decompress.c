static T_1 int F_1 (
const char * const V_1 ,
char * const V_2 ,
int V_3 ,
int V_4 ,
int V_5 ,
int V_6 ,
int V_7 ,
int V_8 ,
const T_2 * const V_9 ,
const T_2 * const V_10 ,
const T_3 V_11
)
{
const T_2 * V_12 = ( const T_2 * ) V_1 ;
const T_2 * const V_13 = V_12 + V_3 ;
T_2 * V_14 = ( T_2 * ) V_2 ;
T_2 * const V_15 = V_14 + V_4 ;
T_2 * V_16 ;
T_2 * V_17 = V_14 + V_7 ;
const T_2 * const V_18 = V_9 - V_11 ;
const T_2 * const V_19 = ( const T_2 * ) V_10 + V_11 ;
const unsigned int V_20 [] = { 0 , 1 , 2 , 1 , 4 , 4 , 4 , 4 } ;
const int V_21 [] = { 0 , 0 , 0 , - 1 , 0 , 1 , 2 , 3 } ;
const int V_22 = ( V_5 == V_23 ) ;
const int V_24 = ( ( V_22 ) && ( V_11 < ( int ) ( 64 * V_25 ) ) ) ;
if ( ( V_6 ) && ( V_17 > V_15 - V_26 ) )
V_17 = V_15 - V_26 ;
if ( ( V_5 ) && ( F_2 ( V_4 == 0 ) ) )
return ( ( V_3 == 1 ) && ( * V_12 == 0 ) ) ? 0 : - 1 ;
if ( ( ! V_5 ) && ( F_2 ( V_4 == 0 ) ) )
return ( * V_12 == 0 ? 1 : - 1 ) ;
while ( 1 ) {
T_3 V_27 ;
const T_2 * V_28 ;
T_3 V_29 ;
unsigned int const V_30 = * V_12 ++ ;
V_27 = V_30 >> V_31 ;
if ( V_27 == V_32 ) {
unsigned int V_33 ;
do {
V_33 = * V_12 ++ ;
V_27 += V_33 ;
} while ( F_3 ( V_5
? V_12 < V_13 - V_32
: 1 ) & ( V_33 == 255 ) );
if ( ( V_22 )
&& F_2 (
( T_3 ) ( V_14 + V_27 ) < ( T_3 ) ( V_14 ) ) ) {
goto V_34;
}
if ( ( V_22 )
&& F_2 (
( T_3 ) ( V_12 + V_27 ) < ( T_3 ) ( V_12 ) ) ) {
goto V_34;
}
}
V_16 = V_14 + V_27 ;
if ( ( ( V_5 ) && ( ( V_16 > ( V_6 ? V_17 : V_15 - V_26 ) )
|| ( V_12 + V_27 > V_13 - ( 2 + 1 + V_35 ) ) ) )
|| ( ( ! V_5 ) && ( V_16 > V_15 - V_36 ) ) ) {
if ( V_6 ) {
if ( V_16 > V_15 ) {
goto V_34;
}
if ( ( V_5 )
&& ( V_12 + V_27 > V_13 ) ) {
goto V_34;
}
} else {
if ( ( ! V_5 )
&& ( V_16 != V_15 ) ) {
goto V_34;
}
if ( ( V_5 )
&& ( ( V_12 + V_27 != V_13 )
|| ( V_16 > V_15 ) ) ) {
goto V_34;
}
}
memcpy ( V_14 , V_12 , V_27 ) ;
V_12 += V_27 ;
V_14 += V_27 ;
break;
}
F_4 ( V_14 , V_12 , V_16 ) ;
V_12 += V_27 ;
V_14 = V_16 ;
V_29 = F_5 ( V_12 ) ;
V_12 += 2 ;
V_28 = V_14 - V_29 ;
if ( ( V_24 ) && ( F_2 ( V_28 < V_18 ) ) ) {
goto V_34;
}
F_6 ( V_14 , ( V_37 ) V_29 ) ;
V_27 = V_30 & V_38 ;
if ( V_27 == V_38 ) {
unsigned int V_33 ;
do {
V_33 = * V_12 ++ ;
if ( ( V_5 ) && ( V_12 > V_13 - V_35 ) )
goto V_34;
V_27 += V_33 ;
} while ( V_33 == 255 );
if ( ( V_22 )
&& F_2 (
( T_3 ) ( V_14 + V_27 ) < ( T_3 ) V_14 ) ) {
goto V_34;
}
}
V_27 += V_39 ;
if ( ( V_8 == V_40 ) && ( V_28 < V_9 ) ) {
if ( F_2 ( V_14 + V_27 > V_15 - V_35 ) ) {
goto V_34;
}
if ( V_27 <= ( T_3 ) ( V_9 - V_28 ) ) {
memmove ( V_14 , V_19 - ( V_9 - V_28 ) ,
V_27 ) ;
V_14 += V_27 ;
} else {
T_3 const V_41 = ( T_3 ) ( V_9 - V_28 ) ;
T_3 const V_42 = V_27 - V_41 ;
memcpy ( V_14 , V_19 - V_41 , V_41 ) ;
V_14 += V_41 ;
if ( V_42 > ( T_3 ) ( V_14 - V_9 ) ) {
T_2 * const V_43 = V_14 + V_42 ;
const T_2 * V_44 = V_9 ;
while ( V_14 < V_43 )
* V_14 ++ = * V_44 ++ ;
} else {
memcpy ( V_14 , V_9 , V_42 ) ;
V_14 += V_42 ;
}
}
continue;
}
V_16 = V_14 + V_27 ;
if ( F_2 ( V_29 < 8 ) ) {
const int V_45 = V_21 [ V_29 ] ;
V_14 [ 0 ] = V_28 [ 0 ] ;
V_14 [ 1 ] = V_28 [ 1 ] ;
V_14 [ 2 ] = V_28 [ 2 ] ;
V_14 [ 3 ] = V_28 [ 3 ] ;
V_28 += V_20 [ V_29 ] ;
memcpy ( V_14 + 4 , V_28 , 4 ) ;
V_28 -= V_45 ;
} else {
F_7 ( V_14 , V_28 ) ;
V_28 += 8 ;
}
V_14 += 8 ;
if ( F_2 ( V_16 > V_15 - 12 ) ) {
T_2 * const V_46 = V_15 - ( V_36 - 1 ) ;
if ( V_16 > V_15 - V_35 ) {
goto V_34;
}
if ( V_14 < V_46 ) {
F_4 ( V_14 , V_28 , V_46 ) ;
V_28 += V_46 - V_14 ;
V_14 = V_46 ;
}
while ( V_14 < V_16 )
* V_14 ++ = * V_28 ++ ;
} else {
F_7 ( V_14 , V_28 ) ;
if ( V_27 > 16 )
F_4 ( V_14 + 8 , V_28 + 8 , V_16 ) ;
}
V_14 = V_16 ;
}
if ( V_5 ) {
return ( int ) ( ( ( char * ) V_14 ) - V_2 ) ;
} else {
return ( int ) ( ( ( const char * ) V_12 ) - V_1 ) ;
}
V_34:
return - 1 ;
}
int F_8 ( const char * V_1 , char * V_2 ,
int V_47 , int V_48 )
{
return F_1 ( V_1 , V_2 , V_47 ,
V_48 , V_23 , V_49 , 0 ,
V_50 , ( T_2 * ) V_2 , NULL , 0 ) ;
}
int F_9 ( const char * V_1 , char * V_2 ,
int V_47 , int V_7 , int V_48 )
{
return F_1 ( V_1 , V_2 , V_47 ,
V_48 , V_23 , V_51 ,
V_7 , V_50 , ( T_2 * ) V_2 , NULL , 0 ) ;
}
int F_10 ( const char * V_1 , char * V_2 , int V_52 )
{
return F_1 ( V_1 , V_2 , 0 , V_52 ,
V_53 , V_49 , 0 , V_54 ,
( T_2 * ) ( V_2 - 64 * V_25 ) , NULL , 64 * V_25 ) ;
}
int F_11 ( T_4 * V_55 ,
const char * V_56 , int V_11 )
{
T_5 * V_57 = ( T_5 * ) V_55 ;
V_57 -> V_58 = ( T_3 ) V_11 ;
V_57 -> V_59 = ( const T_2 * ) V_56 + V_11 ;
V_57 -> V_60 = NULL ;
V_57 -> V_61 = 0 ;
return 1 ;
}
int F_12 ( T_4 * V_55 ,
const char * V_1 , char * V_2 , int V_47 , int V_62 )
{
T_5 * V_57 = & V_55 -> V_63 ;
int V_64 ;
if ( V_57 -> V_59 == ( T_2 * ) V_2 ) {
V_64 = F_1 ( V_1 , V_2 ,
V_47 ,
V_62 ,
V_23 , V_49 , 0 ,
V_40 , V_57 -> V_59 - V_57 -> V_58 ,
V_57 -> V_60 ,
V_57 -> V_61 ) ;
if ( V_64 <= 0 )
return V_64 ;
V_57 -> V_58 += V_64 ;
V_57 -> V_59 += V_64 ;
} else {
V_57 -> V_61 = V_57 -> V_58 ;
V_57 -> V_60 = V_57 -> V_59 - V_57 -> V_61 ;
V_64 = F_1 ( V_1 , V_2 ,
V_47 , V_62 ,
V_23 , V_49 , 0 ,
V_40 , ( T_2 * ) V_2 ,
V_57 -> V_60 , V_57 -> V_61 ) ;
if ( V_64 <= 0 )
return V_64 ;
V_57 -> V_58 = V_64 ;
V_57 -> V_59 = ( T_2 * ) V_2 + V_64 ;
}
return V_64 ;
}
int F_13 ( T_4 * V_55 ,
const char * V_1 , char * V_2 , int V_52 )
{
T_5 * V_57 = & V_55 -> V_63 ;
int V_64 ;
if ( V_57 -> V_59 == ( T_2 * ) V_2 ) {
V_64 = F_1 ( V_1 , V_2 , 0 , V_52 ,
V_53 , V_49 , 0 ,
V_40 ,
V_57 -> V_59 - V_57 -> V_58 ,
V_57 -> V_60 , V_57 -> V_61 ) ;
if ( V_64 <= 0 )
return V_64 ;
V_57 -> V_58 += V_52 ;
V_57 -> V_59 += V_52 ;
} else {
V_57 -> V_61 = V_57 -> V_58 ;
V_57 -> V_60 = V_57 -> V_59 - V_57 -> V_61 ;
V_64 = F_1 ( V_1 , V_2 , 0 , V_52 ,
V_53 , V_49 , 0 ,
V_40 , ( T_2 * ) V_2 ,
V_57 -> V_60 , V_57 -> V_61 ) ;
if ( V_64 <= 0 )
return V_64 ;
V_57 -> V_58 = V_52 ;
V_57 -> V_59 = ( T_2 * ) V_2 + V_52 ;
}
return V_64 ;
}
static T_1 int F_14 ( const char * V_1 ,
char * V_2 , int V_47 , int V_62 , int V_65 ,
const char * V_10 , int V_11 )
{
if ( V_11 == 0 )
return F_1 ( V_1 , V_2 ,
V_47 , V_62 , V_65 , V_49 , 0 ,
V_50 , ( T_2 * ) V_2 , NULL , 0 ) ;
if ( V_10 + V_11 == V_2 ) {
if ( V_11 >= ( int ) ( 64 * V_25 - 1 ) )
return F_1 ( V_1 , V_2 ,
V_47 , V_62 , V_65 , V_49 , 0 ,
V_54 , ( T_2 * ) V_2 - 64 * V_25 , NULL , 0 ) ;
return F_1 ( V_1 , V_2 , V_47 ,
V_62 , V_65 , V_49 , 0 , V_50 ,
( T_2 * ) V_2 - V_11 , NULL , 0 ) ;
}
return F_1 ( V_1 , V_2 , V_47 ,
V_62 , V_65 , V_49 , 0 , V_40 ,
( T_2 * ) V_2 , ( const T_2 * ) V_10 , V_11 ) ;
}
int F_15 ( const char * V_1 , char * V_2 ,
int V_47 , int V_62 ,
const char * V_10 , int V_11 )
{
return F_14 ( V_1 , V_2 ,
V_47 , V_62 , 1 , V_10 , V_11 ) ;
}
int F_16 ( const char * V_1 , char * V_2 ,
int V_52 , const char * V_10 , int V_11 )
{
return F_14 ( V_1 , V_2 , 0 ,
V_52 , 0 , V_10 , V_11 ) ;
}
