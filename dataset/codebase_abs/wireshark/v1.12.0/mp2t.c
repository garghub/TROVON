static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , T_4 V_3 ,
struct V_4 * V_5 , T_5 * V_6 , int * V_7 ,
T_6 * * V_8 )
{
T_7 V_9 ;
int V_10 ;
F_2 ( V_6 , V_11 ) ;
V_12 = V_13 ;
V_10 = F_3 ( F_4 ( V_6 ) , V_11 , V_2 ) ;
if ( V_11 != V_10 ) {
* V_7 = F_5 ( V_2 , V_8 ) ;
if ( V_10 > 0 && * V_7 == 0 ) {
* V_7 = V_14 ;
}
return FALSE ;
}
V_5 -> V_15 = V_16 ;
V_5 -> V_17 = V_18 ;
V_9 = ( ( T_7 ) ( V_3 - V_1 -> V_19 ) * 8 ) ;
V_5 -> V_20 . V_21 = ( V_22 ) ( V_9 / V_23 ) ;
V_5 -> V_20 . V_24 = ( int ) ( ( V_9 % V_23 ) * 1000000000 / V_23 ) ;
V_5 -> V_25 = V_11 ;
V_5 -> V_26 = V_11 ;
return TRUE ;
}
static T_1
F_6 ( T_8 * V_27 , int * V_7 , T_6 * * V_8 , T_4 * V_28 )
{
T_2 * V_1 ;
V_1 = ( T_2 * ) V_27 -> V_29 ;
* V_28 = F_7 ( V_27 -> V_2 ) ;
if ( ! F_1 ( V_1 , V_27 -> V_2 , * V_28 , & V_27 -> V_5 ,
V_27 -> V_30 , V_7 , V_8 ) ) {
return FALSE ;
}
if ( V_1 -> V_31 != 0 ) {
if ( - 1 == F_8 ( V_27 -> V_2 , V_1 -> V_31 , V_32 , V_7 ) ) {
return FALSE ;
}
}
return TRUE ;
}
static T_1
F_9 ( T_8 * V_27 , T_4 V_33 , struct V_4 * V_5 ,
T_5 * V_6 , int * V_7 , T_6 * * V_8 )
{
T_2 * V_1 ;
if ( - 1 == F_8 ( V_27 -> V_34 , V_33 , V_35 , V_7 ) ) {
return FALSE ;
}
V_1 = ( T_2 * ) V_27 -> V_29 ;
if ( ! F_1 ( V_1 , V_27 -> V_34 , V_33 , V_5 , V_6 ,
V_7 , V_8 ) ) {
if ( * V_7 == 0 )
* V_7 = V_14 ;
return FALSE ;
}
return TRUE ;
}
int
F_10 ( T_8 * V_27 , int * V_7 , T_6 * * V_8 )
{
int V_10 ;
T_9 V_36 [ V_11 + V_37 ] ;
T_9 V_31 = 0 ;
T_10 V_38 = 0 ;
int V_39 ;
int V_40 ;
T_2 * V_1 ;
V_12 = V_13 ;
V_10 = F_3 ( V_36 , V_11 , V_27 -> V_2 ) ;
if ( V_11 != V_10 ) {
* V_7 = F_5 ( V_27 -> V_2 , V_8 ) ;
if ( * V_7 != 0 && * V_7 != V_14 )
return - 1 ;
return 0 ;
}
V_40 = - 1 ;
for ( V_39 = 0 ; V_39 < V_11 ; V_39 ++ ) {
if ( V_41 == V_36 [ V_39 ] ) {
V_40 = V_39 ;
break;
}
}
if ( - 1 == V_40 ) {
return 0 ;
}
if ( - 1 == F_8 ( V_27 -> V_2 , V_40 , V_35 , V_7 ) ) {
return - 1 ;
}
do {
V_10 = F_3 ( V_36 , V_11 + V_31 , V_27 -> V_2 ) ;
if ( V_10 < 0 ) {
* V_7 = F_5 ( V_27 -> V_2 , V_8 ) ;
return - 1 ;
}
if ( V_10 < V_11 + V_31 ) {
if( V_38 < 2 ) return 0 ;
break;
}
if ( V_36 [ 0 ] == V_41 ) {
V_38 ++ ;
}
else {
if ( V_31 > 0 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
if ( V_36 [ V_39 ] == V_41 ) {
V_31 = V_39 ;
if ( - 1 == F_8 ( V_27 -> V_2 , V_40 , V_35 , V_7 ) ) {
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
if ( - 1 == F_8 ( V_27 -> V_2 , V_40 , V_35 , V_7 ) ) {
return - 1 ;
}
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_46 ;
V_27 -> V_47 = V_48 ;
V_27 -> V_49 = F_6 ;
V_27 -> V_50 = F_9 ;
V_27 -> V_51 = 0 ;
V_1 = ( T_2 * ) F_11 ( sizeof( T_2 ) ) ;
if ( NULL == V_1 ) {
return - 1 ;
}
V_27 -> V_29 = V_1 ;
V_1 -> V_19 = V_40 ;
V_1 -> V_31 = V_31 ;
return 1 ;
}
