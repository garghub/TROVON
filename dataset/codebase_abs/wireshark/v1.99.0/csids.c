int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_5 ;
T_3 V_6 = FALSE ;
struct V_7 V_8 ;
T_4 * V_9 ;
if( ! F_2 ( V_1 -> V_10 , & V_8 , sizeof( struct V_7 ) , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return - 1 ;
}
return 0 ;
}
if( V_8 . V_12 != 0 || V_8 . V_13 == 0 ) {
return 0 ;
}
V_8 . V_14 = F_3 ( & V_8 . V_14 ) ;
V_8 . V_13 = F_4 ( & V_8 . V_13 ) ;
if( ! F_2 ( V_1 -> V_10 , & V_4 , 2 , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return - 1 ;
}
return 0 ;
}
if( ! F_2 ( V_1 -> V_10 , & V_5 , 2 , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return - 1 ;
}
return 0 ;
}
V_5 = F_4 ( & V_5 ) ;
if ( V_5 == 0 )
return 0 ;
if( V_5 > V_8 . V_13 ) {
V_5 = F_5 ( V_5 ) ;
if( V_5 <= V_8 . V_13 ) {
V_6 = TRUE ;
} else {
return 0 ;
}
} else {
V_6 = FALSE ;
}
if ( F_6 ( V_1 -> V_10 , 0 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_9 = ( T_4 * ) F_7 ( sizeof( T_4 ) ) ;
V_1 -> V_16 = ( void * ) V_9 ;
V_9 -> V_17 = V_6 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_3 V_24 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_29 )
{
T_4 * V_9 = ( T_4 * ) V_1 -> V_16 ;
* V_29 = F_8 ( V_1 -> V_10 ) ;
return F_9 ( V_1 -> V_10 , V_9 , & V_1 -> V_30 , V_1 -> V_31 ,
V_2 , V_3 ) ;
}
static T_3
V_26 ( T_1 * V_1 ,
T_5 V_32 ,
struct V_33 * V_30 ,
T_6 * V_34 ,
int * V_2 ,
T_2 * * V_3 )
{
T_4 * V_9 = ( T_4 * ) V_1 -> V_16 ;
if( F_6 ( V_1 -> V_35 , V_32 , V_15 , V_2 ) == - 1 )
return FALSE ;
if( ! F_9 ( V_1 -> V_35 , V_9 , V_30 , V_34 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_9 ( T_7 V_10 , T_4 * V_9 , struct V_33 * V_30 ,
T_6 * V_34 , int * V_2 , T_2 * * V_3 )
{
struct V_7 V_8 ;
T_8 * V_36 ;
if( ! F_10 ( V_10 , & V_8 , sizeof( struct V_7 ) , V_2 , V_3 ) )
return FALSE ;
V_8 . V_14 = F_3 ( & V_8 . V_14 ) ;
V_8 . V_13 = F_4 ( & V_8 . V_13 ) ;
V_30 -> V_37 = V_38 ;
V_30 -> V_39 = V_40 ;
V_30 -> V_41 = V_8 . V_13 ;
V_30 -> V_13 = V_8 . V_13 ;
V_30 -> V_42 . V_43 = V_8 . V_14 ;
V_30 -> V_42 . V_44 = 0 ;
if( ! F_11 ( V_10 , V_34 , V_30 -> V_13 , V_2 , V_3 ) )
return FALSE ;
V_36 = F_12 ( V_34 ) ;
if( V_9 -> V_17 ) {
if( V_30 -> V_13 >= 2 ) {
F_13 ( V_36 ) ;
if( V_30 -> V_13 >= 4 ) {
F_13 ( V_36 + 2 ) ;
if( V_30 -> V_13 >= 6 )
F_13 ( V_36 + 4 ) ;
}
}
}
return TRUE ;
}
