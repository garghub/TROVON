static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 ,
struct V_4 * V_5 , T_5 * V_6 , int * V_7 ,
T_6 * * V_8 )
{
T_7 V_9 ;
F_2 ( V_6 , V_10 ) ;
V_11 = V_12 ;
if ( ! F_3 ( V_2 , F_4 ( V_6 ) , V_10 , V_7 , V_8 ) )
return FALSE ;
V_5 -> V_13 = V_14 ;
V_5 -> V_15 = V_16 ;
V_9 = ( ( T_7 ) ( V_3 - V_1 -> V_17 ) * 8 ) ;
V_5 -> V_18 . V_19 = ( V_20 ) ( V_9 / V_21 ) ;
V_5 -> V_18 . V_22 = ( int ) ( ( V_9 % V_21 ) * 1000000000 / V_21 ) ;
V_5 -> V_23 = V_10 ;
V_5 -> V_24 = V_10 ;
return TRUE ;
}
static T_1
F_5 ( T_8 * V_25 , int * V_7 , T_6 * * V_8 , T_4 * V_26 )
{
T_2 * V_1 ;
V_1 = ( T_2 * ) V_25 -> V_27 ;
* V_26 = F_6 ( V_25 -> V_2 ) ;
if ( ! F_1 ( V_1 , V_25 -> V_2 , * V_26 , & V_25 -> V_5 ,
V_25 -> V_28 , V_7 , V_8 ) ) {
return FALSE ;
}
if ( V_1 -> V_29 != 0 ) {
if ( - 1 == F_7 ( V_25 -> V_2 , V_1 -> V_29 , V_30 , V_7 ) ) {
return FALSE ;
}
}
return TRUE ;
}
static T_1
F_8 ( T_8 * V_25 , T_4 V_31 , struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
T_2 * V_1 ;
if ( - 1 == F_7 ( V_25 -> V_32 , V_31 , V_33 , V_7 ) ) {
return FALSE ;
}
V_1 = ( T_2 * ) V_25 -> V_27 ;
if ( ! F_1 ( V_1 , V_25 -> V_32 , V_31 , V_5 , V_6 ,
V_7 , V_8 ) ) {
if ( * V_7 == 0 )
* V_7 = V_34 ;
return FALSE ;
}
return TRUE ;
}
int
F_9 ( T_8 * V_25 , int * V_7 , T_6 * * V_8 )
{
int V_35 ;
T_9 V_36 [ V_10 + V_37 ] ;
T_9 V_29 = 0 ;
T_10 V_38 = 0 ;
int V_39 ;
int V_40 ;
T_2 * V_1 ;
V_11 = V_12 ;
if ( ! F_10 ( V_25 -> V_2 , V_36 , V_10 , V_7 , V_8 ) ) {
if ( * V_7 != V_34 )
return - 1 ;
return 0 ;
}
V_40 = - 1 ;
for ( V_39 = 0 ; V_39 < V_10 ; V_39 ++ ) {
if ( V_41 == V_36 [ V_39 ] ) {
V_40 = V_39 ;
break;
}
}
if ( - 1 == V_40 ) {
return 0 ;
}
if ( - 1 == F_7 ( V_25 -> V_2 , V_40 , V_33 , V_7 ) ) {
return - 1 ;
}
do {
V_35 = F_11 ( V_36 , V_10 + V_29 , V_25 -> V_2 ) ;
if ( V_35 < 0 ) {
* V_7 = F_12 ( V_25 -> V_2 , V_8 ) ;
return - 1 ;
}
if ( V_35 < V_10 + V_29 ) {
if( V_38 < 2 ) return 0 ;
break;
}
if ( V_36 [ 0 ] == V_41 ) {
V_38 ++ ;
}
else {
if ( V_29 > 0 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
if ( V_36 [ V_39 ] == V_41 ) {
V_29 = V_39 ;
if ( - 1 == F_7 ( V_25 -> V_2 , V_40 , V_33 , V_7 ) ) {
return - 1 ;
}
V_38 = 0 ;
break;
}
}
if ( V_39 == V_37 )
return 0 ;
}
} while ( V_38 < V_42 );
if ( - 1 == F_7 ( V_25 -> V_2 , V_40 , V_33 , V_7 ) ) {
return - 1 ;
}
V_25 -> V_43 = V_44 ;
V_25 -> V_45 = V_46 ;
V_25 -> V_47 = V_48 ;
V_25 -> V_49 = F_5 ;
V_25 -> V_50 = F_8 ;
V_25 -> V_51 = 0 ;
V_1 = ( T_2 * ) F_13 ( sizeof( T_2 ) ) ;
if ( NULL == V_1 ) {
return - 1 ;
}
V_25 -> V_27 = V_1 ;
V_1 -> V_17 = V_40 ;
V_1 -> V_29 = V_29 ;
return 1 ;
}
