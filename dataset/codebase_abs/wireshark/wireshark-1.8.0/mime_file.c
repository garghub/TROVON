static T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_4 * V_4 )
{
T_5 * V_5 = ( T_5 * ) V_1 -> V_5 ;
char V_6 [ V_7 ] ;
T_6 * V_8 ;
int V_9 ;
if ( V_5 -> V_10 ) {
* V_2 = F_2 ( V_1 -> V_11 , V_3 ) ;
return FALSE ;
}
V_1 -> V_12 . V_13 = 0 ;
V_1 -> V_12 . V_14 . V_15 = 0 ;
V_1 -> V_12 . V_14 . V_16 = 0 ;
* V_4 = F_3 ( V_1 -> V_11 ) ;
V_9 = F_4 ( V_6 , sizeof( V_6 ) , V_1 -> V_11 ) ;
if ( V_9 <= 0 ) {
V_5 -> V_10 = TRUE ;
if ( V_9 < 0 )
V_1 -> V_12 . V_14 . V_16 = 1000000000 ;
V_1 -> V_12 . V_17 = 0 ;
V_1 -> V_12 . V_18 = 0 ;
return TRUE ;
}
F_5 ( V_1 -> V_19 , V_9 ) ;
V_8 = F_6 ( V_1 -> V_19 ) ;
memcpy ( V_8 , V_6 , V_9 ) ;
V_1 -> V_12 . V_17 = V_9 ;
V_1 -> V_12 . V_18 = V_9 ;
return TRUE ;
}
static T_1
F_7 ( T_2 * V_1 , T_4 V_20 , union V_21 * T_7 V_22 , T_6 * V_23 , int V_24 , int * V_2 , T_3 * * V_3 )
{
if ( F_8 ( V_1 -> V_25 , V_20 , V_26 , V_2 ) == - 1 ) {
* V_3 = NULL ;
return FALSE ;
}
F_9 ( V_23 , V_24 , V_1 -> V_25 , V_2 , V_3 ) ;
* V_2 = 0 ;
* V_3 = NULL ;
return TRUE ;
}
int
F_10 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_27 [ 128 ] ;
int V_28 ;
int V_29 ;
T_8 V_30 ;
T_8 V_31 = 0 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ )
V_31 = F_11 ( V_31 , V_33 [ V_30 ] . V_34 ) ;
V_31 = F_12 ( V_31 , sizeof( V_27 ) ) ;
V_28 = F_4 ( V_27 , V_31 , V_1 -> V_11 ) ;
if ( V_28 > 0 ) {
T_1 V_35 = FALSE ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
if ( ( T_8 ) V_28 >= V_33 [ V_30 ] . V_34 && ! memcmp ( V_27 , V_33 [ V_30 ] . V_36 , F_12 ( V_33 [ V_30 ] . V_34 , ( T_8 ) V_28 ) ) ) {
if ( ! V_35 ) {
V_35 = TRUE ;
} else
return 0 ;
}
}
if ( ! V_35 )
return 0 ;
if ( F_8 ( V_1 -> V_11 , 0 , V_26 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
V_1 -> V_41 = V_42 ;
V_1 -> V_43 = F_1 ;
V_1 -> V_44 = F_7 ;
V_1 -> V_45 = 0 ;
V_29 = 1 ;
V_1 -> V_5 = F_13 ( sizeof( T_5 ) ) ;
} else {
* V_2 = F_2 ( V_1 -> V_11 , V_3 ) ;
V_29 = - 1 ;
}
return V_29 ;
}
