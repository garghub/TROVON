int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 , V_5 , V_6 ;
T_3 V_7 = FALSE ;
struct V_8 V_9 ;
T_4 * V_10 ;
V_6 = F_2 ( & V_9 , sizeof( struct V_8 ) , V_1 -> V_11 ) ;
if( V_6 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 ) {
return - 1 ;
} else {
return 0 ;
}
}
if( V_9 . V_12 != 0 || V_9 . V_13 == 0 ) {
return 0 ;
}
V_9 . V_14 = F_4 ( & V_9 . V_14 ) ;
V_9 . V_13 = F_5 ( & V_9 . V_13 ) ;
V_6 = F_2 ( & V_4 , 2 , V_1 -> V_11 ) ;
if( V_6 != 2 ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 ) {
return - 1 ;
} else {
return 0 ;
}
}
V_6 = F_2 ( & V_5 , 2 , V_1 -> V_11 ) ;
if( V_6 != 2 ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if( * V_2 != 0 ) {
return - 1 ;
} else {
return 0 ;
}
}
V_5 = F_5 ( & V_5 ) ;
if ( V_5 == 0 )
return ( 0 ) ;
if( V_5 > V_9 . V_13 ) {
V_5 = F_6 ( V_5 ) ;
if( V_5 <= V_9 . V_13 ) {
V_7 = TRUE ;
} else {
return 0 ;
}
} else {
V_7 = FALSE ;
}
if ( F_7 ( V_1 -> V_11 , 0 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_10 = ( T_4 * ) F_8 ( sizeof( T_4 ) ) ;
V_1 -> V_16 = ( void * ) V_10 ;
V_10 -> V_17 = V_7 ;
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
T_4 * V_10 = ( T_4 * ) V_1 -> V_16 ;
T_6 * V_30 ;
int V_6 = 0 ;
struct V_8 V_9 ;
* V_29 = F_9 ( V_1 -> V_11 ) ;
V_6 = F_2 ( & V_9 , sizeof( struct V_8 ) , V_1 -> V_11 ) ;
if( V_6 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if ( * V_2 == 0 && V_6 != 0 )
* V_2 = V_31 ;
return FALSE ;
}
V_9 . V_14 = F_4 ( & V_9 . V_14 ) ;
V_9 . V_13 = F_5 ( & V_9 . V_13 ) ;
F_10 ( V_1 -> V_32 , V_9 . V_13 ) ;
V_30 = F_11 ( V_1 -> V_32 ) ;
V_6 = F_2 ( V_30 , V_9 . V_13 , V_1 -> V_11 ) ;
if( V_6 != V_9 . V_13 ) {
* V_2 = F_3 ( V_1 -> V_11 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_31 ;
return FALSE ;
}
V_1 -> V_33 . V_34 = V_35 ;
V_1 -> V_33 . V_36 = V_9 . V_13 ;
V_1 -> V_33 . V_13 = V_9 . V_13 ;
V_1 -> V_33 . V_37 . V_38 = V_9 . V_14 ;
V_1 -> V_33 . V_37 . V_39 = 0 ;
if( V_10 -> V_17 ) {
if( V_9 . V_13 >= 2 ) {
F_12 ( V_30 ) ;
if( V_9 . V_13 >= 4 ) {
F_12 ( V_30 + 2 ) ;
if( V_9 . V_13 >= 6 )
F_12 ( V_30 + 4 ) ;
}
}
}
return TRUE ;
}
static T_3
V_26 ( T_1 * V_1 ,
T_5 V_40 ,
union V_41 * T_7 V_42 ,
T_6 * V_43 ,
int V_36 ,
int * V_2 ,
T_2 * * V_3 )
{
T_4 * V_10 = ( T_4 * ) V_1 -> V_16 ;
int V_6 ;
struct V_8 V_9 ;
if( F_7 ( V_1 -> V_44 , V_40 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_6 = F_2 ( & V_9 , sizeof( struct V_8 ) , V_1 -> V_44 ) ;
if( V_6 != sizeof( struct V_8 ) ) {
* V_2 = F_3 ( V_1 -> V_44 , V_3 ) ;
if( * V_2 == 0 ) {
* V_2 = V_31 ;
}
return FALSE ;
}
V_9 . V_14 = F_4 ( & V_9 . V_14 ) ;
V_9 . V_13 = F_5 ( & V_9 . V_13 ) ;
if( V_36 != V_9 . V_13 ) {
* V_2 = V_45 ;
* V_3 = F_13 ( L_1 ,
V_9 . V_13 , V_36 ) ;
return FALSE ;
}
V_6 = F_2 ( V_43 , V_9 . V_13 , V_1 -> V_44 ) ;
if( V_6 != V_9 . V_13 ) {
* V_2 = F_3 ( V_1 -> V_44 , V_3 ) ;
if( * V_2 == 0 ) {
* V_2 = V_31 ;
}
return FALSE ;
}
if( V_10 -> V_17 ) {
if( V_9 . V_13 >= 2 ) {
F_12 ( V_43 ) ;
if( V_9 . V_13 >= 4 ) {
F_12 ( V_43 + 2 ) ;
if( V_9 . V_13 >= 6 )
F_12 ( V_43 + 4 ) ;
}
}
}
return TRUE ;
}
