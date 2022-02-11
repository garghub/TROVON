static T_1
F_1 ( T_2 * V_1 , int V_2 , int * V_3 , T_3 * * V_4 , T_4 V_5 )
{
int V_6 ;
V_6 = F_2 ( V_1 , V_2 , V_5 ) ;
if ( V_2 != V_6 ) {
* V_3 = F_3 ( V_5 , V_4 ) ;
if ( V_6 > 0 && * V_3 == 0 ) {
* V_3 = V_7 ;
}
return FALSE ;
}
return TRUE ;
}
static T_1
F_4 ( T_5 * V_8 , int * V_3 , T_3 * * V_4 , T_6 * V_9 )
{
T_7 * V_10 ;
T_8 V_11 ;
V_10 = ( T_7 * ) V_8 -> V_12 ;
* V_9 = F_5 ( V_8 -> V_5 ) ;
F_6 ( V_8 -> V_13 , V_14 ) ;
if ( FALSE == F_1 ( F_7 ( V_8 -> V_13 ) ,
V_14 , V_3 , V_4 , V_8 -> V_5 ) )
{
return FALSE ;
}
if ( V_10 -> V_15 != 0 &&
( - 1 == F_8 ( V_8 -> V_5 , V_10 -> V_15 , V_16 , V_3 ) ) ) {
return FALSE ;
}
V_8 -> V_17 . V_18 = V_19 ;
V_11 = ( ( T_8 ) ( * V_9 - V_10 -> V_20 ) * 8 ) ;
V_8 -> V_17 . V_21 . V_22 = V_11 / V_23 ;
V_8 -> V_17 . V_21 . V_24 = ( V_11 % V_23 ) * 1000000000 / V_23 ;
V_8 -> V_17 . V_25 = V_14 ;
V_8 -> V_17 . V_26 = V_14 ;
return TRUE ;
}
static T_1
F_9 ( T_5 * V_8 , T_6 V_27 ,
union V_28 * T_9 V_29 , T_2 * V_30 , int V_2 ,
int * V_3 , T_3 * * V_4 )
{
if ( - 1 == F_8 ( V_8 -> V_31 , V_27 , V_32 , V_3 ) ) {
return FALSE ;
}
return F_1 ( V_30 , V_2 , V_3 , V_4 , V_8 -> V_31 ) ;
}
int
F_10 ( T_5 * V_8 , int * V_3 , T_3 * * V_4 )
{
int V_6 ;
T_2 V_33 [ V_14 + V_34 ] ;
T_2 V_15 = 0 ;
T_10 V_35 = 0 ;
int V_36 ;
int V_37 ;
T_7 * V_10 ;
V_38 = V_39 ;
V_6 = F_2 ( V_33 , V_14 , V_8 -> V_5 ) ;
if ( V_14 != V_6 ) {
* V_3 = F_3 ( V_8 -> V_5 , V_4 ) ;
return ( * V_3 == 0 ) ? 0 : - 1 ;
}
V_37 = - 1 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
if ( V_40 == V_33 [ V_36 ] ) {
V_37 = V_36 ;
break;
}
}
if ( - 1 == V_37 ) {
return 0 ;
}
if ( - 1 == F_8 ( V_8 -> V_5 , V_37 , V_32 , V_3 ) ) {
return - 1 ;
}
do {
V_6 = F_2 ( V_33 , V_14 + V_15 , V_8 -> V_5 ) ;
if ( V_6 < 0 )
return - 1 ;
if ( V_6 < V_14 + V_15 ) {
if( V_35 < 2 ) return 0 ;
break;
}
if ( V_33 [ 0 ] == V_40 ) {
V_35 ++ ;
}
else {
if ( V_15 > 0 )
return 0 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
if ( V_33 [ V_36 ] == V_40 ) {
V_15 = V_36 ;
if ( - 1 == F_8 ( V_8 -> V_5 , V_37 , V_32 , V_3 ) ) {
return - 1 ;
}
V_35 = 0 ;
break;
}
}
if ( V_36 == V_34 )
return 0 ;
}
} while ( V_35 < V_41 );
if ( - 1 == F_8 ( V_8 -> V_5 , V_37 , V_32 , V_3 ) ) {
return - 1 ;
}
V_8 -> V_42 = V_43 ;
V_8 -> V_44 = V_45 ;
V_8 -> V_46 = V_47 ;
V_8 -> V_48 = F_4 ;
V_8 -> V_49 = F_9 ;
V_8 -> V_50 = 0 ;
V_10 = ( T_7 * ) F_11 ( sizeof( T_7 ) ) ;
if ( NULL == V_10 ) {
return - 1 ;
}
V_8 -> V_12 = V_10 ;
V_10 -> V_20 = V_37 ;
V_10 -> V_15 = V_15 ;
return 1 ;
}
