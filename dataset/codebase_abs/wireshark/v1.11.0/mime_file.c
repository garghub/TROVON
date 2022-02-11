static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = 0 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = 0 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = V_3 ;
}
static T_1
F_2 ( T_2 * V_10 , int * V_11 , T_3 * * V_12 , T_4 * V_13 )
{
T_5 * V_14 = ( T_5 * ) V_10 -> V_14 ;
char V_15 [ V_16 ] ;
T_6 * V_17 ;
int V_3 ;
if ( V_14 -> V_18 ) {
* V_11 = F_3 ( V_10 -> V_19 , V_12 ) ;
return FALSE ;
}
* V_13 = F_4 ( V_10 -> V_19 ) ;
V_3 = F_5 ( V_15 , sizeof( V_15 ) , V_10 -> V_19 ) ;
if ( V_3 <= 0 ) {
F_1 ( & V_10 -> V_2 , 0 ) ;
V_14 -> V_18 = TRUE ;
if ( V_3 < 0 )
V_10 -> V_2 . V_5 . V_7 = 1000000000 ;
return TRUE ;
}
F_1 ( & V_10 -> V_2 , V_3 ) ;
F_6 ( V_10 -> V_20 , V_3 ) ;
V_17 = F_7 ( V_10 -> V_20 ) ;
memcpy ( V_17 , V_15 , V_3 ) ;
return TRUE ;
}
static T_1
F_8 ( T_2 * V_10 , T_4 V_21 , struct V_1 * V_2 , T_7 * V_17 , int V_22 , int * V_11 , T_3 * * V_12 )
{
if ( F_9 ( V_10 -> V_23 , V_21 , V_24 , V_11 ) == - 1 ) {
* V_12 = NULL ;
return FALSE ;
}
F_1 ( V_2 , V_22 ) ;
return F_10 ( V_10 -> V_23 , V_17 , V_22 , V_11 ,
V_12 ) ;
}
int
F_11 ( T_2 * V_10 , int * V_11 , T_3 * * V_12 )
{
char V_25 [ 128 ] ;
int V_26 ;
T_1 V_27 ;
T_8 V_28 ;
T_8 V_29 = 0 ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ )
V_29 = F_12 ( V_29 , V_31 [ V_28 ] . V_32 ) ;
V_29 = ( T_8 ) F_13 ( V_29 , sizeof( V_25 ) ) ;
V_26 = F_5 ( V_25 , V_29 , V_10 -> V_19 ) ;
if ( V_26 < 0 ) {
* V_11 = F_3 ( V_10 -> V_19 , V_12 ) ;
return - 1 ;
}
if ( V_26 == 0 )
return 0 ;
V_27 = FALSE ;
for ( V_28 = 0 ; V_28 < V_30 ; V_28 ++ ) {
if ( ( T_8 ) V_26 >= V_31 [ V_28 ] . V_32 && ! memcmp ( V_25 , V_31 [ V_28 ] . V_33 , F_13 ( V_31 [ V_28 ] . V_32 , ( T_8 ) V_26 ) ) ) {
if ( ! V_27 ) {
V_27 = TRUE ;
} else
return 0 ;
}
}
if ( ! V_27 )
return 0 ;
if ( F_9 ( V_10 -> V_19 , 0 , V_24 , V_11 ) == - 1 )
return - 1 ;
V_10 -> V_34 = V_35 ;
V_10 -> V_36 = V_37 ;
V_10 -> V_38 = V_39 ;
V_10 -> V_40 = F_2 ;
V_10 -> V_41 = F_8 ;
V_10 -> V_42 = 0 ;
V_10 -> V_14 = F_14 ( sizeof( T_5 ) ) ;
return 1 ;
}
