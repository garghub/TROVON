int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_5 , V_6 ;
T_3 V_7 = FALSE ;
struct V_8 V_9 ;
T_4 * V_10 ;
V_6 = F_2 ( & V_9 , sizeof( struct V_8 ) , V_1 -> V_11 ) ;
if( V_6 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 && * V_2 != V_12 ) {
return - 1 ;
}
return 0 ;
}
if( V_9 . V_13 != 0 || V_9 . V_14 == 0 ) {
return 0 ;
}
V_9 . V_15 = F_4 ( & V_9 . V_15 ) ;
V_9 . V_14 = F_5 ( & V_9 . V_14 ) ;
V_6 = F_2 ( & V_4 , 2 , V_1 -> V_11 ) ;
if( V_6 != 2 ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 && * V_2 != V_12 ) {
return - 1 ;
}
return 0 ;
}
V_6 = F_2 ( & V_5 , 2 , V_1 -> V_11 ) ;
if( V_6 != 2 ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 && * V_2 != V_12 ) {
return - 1 ;
}
return 0 ;
}
V_5 = F_5 ( & V_5 ) ;
if ( V_5 == 0 )
return 0 ;
if( V_5 > V_9 . V_14 ) {
V_5 = F_6 ( V_5 ) ;
if( V_5 <= V_9 . V_14 ) {
V_7 = TRUE ;
} else {
return 0 ;
}
} else {
V_7 = FALSE ;
}
if ( F_7 ( V_1 -> V_11 , 0 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_10 = ( T_4 * ) F_8 ( sizeof( T_4 ) ) ;
V_1 -> V_17 = ( void * ) V_10 ;
V_10 -> V_18 = V_7 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
return 1 ;
}
static T_3 V_25 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_30 )
{
T_4 * V_10 = ( T_4 * ) V_1 -> V_17 ;
* V_30 = F_9 ( V_1 -> V_11 ) ;
return F_10 ( V_1 -> V_11 , V_10 , & V_1 -> V_31 , V_1 -> V_32 ,
V_2 , V_3 ) ;
}
static T_3
V_27 ( T_1 * V_1 ,
T_5 V_33 ,
struct V_34 * V_31 ,
T_6 * V_35 ,
int T_7 V_36 ,
int * V_2 ,
T_2 * * V_3 )
{
T_4 * V_10 = ( T_4 * ) V_1 -> V_17 ;
if( F_7 ( V_1 -> V_37 , V_33 , V_16 , V_2 ) == - 1 )
return FALSE ;
if( ! F_10 ( V_1 -> V_37 , V_10 , V_31 , V_35 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_10 ( T_8 V_11 , T_4 * V_10 , struct V_34 * V_31 ,
T_6 * V_35 , int * V_2 , T_2 * * V_3 )
{
struct V_8 V_9 ;
int V_6 = 0 ;
T_9 * V_38 ;
V_6 = F_2 ( & V_9 , sizeof( struct V_8 ) , V_11 ) ;
if( V_6 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_11 , V_3 ) ;
if ( * V_2 == 0 && V_6 != 0 )
* V_2 = V_12 ;
return FALSE ;
}
V_9 . V_15 = F_4 ( & V_9 . V_15 ) ;
V_9 . V_14 = F_5 ( & V_9 . V_14 ) ;
V_31 -> V_39 = V_40 ;
V_31 -> T_7 = V_9 . V_14 ;
V_31 -> V_14 = V_9 . V_14 ;
V_31 -> V_41 . V_42 = V_9 . V_15 ;
V_31 -> V_41 . V_43 = 0 ;
if( ! F_11 ( V_11 , V_35 , V_31 -> V_14 , V_2 , V_3 ) )
return FALSE ;
V_38 = F_12 ( V_35 ) ;
if( V_10 -> V_18 ) {
if( V_31 -> V_14 >= 2 ) {
F_13 ( V_38 ) ;
if( V_31 -> V_14 >= 4 ) {
F_13 ( V_38 + 2 ) ;
if( V_31 -> V_14 >= 6 )
F_13 ( V_38 + 4 ) ;
}
}
}
return TRUE ;
}
