T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_4 , V_5 ;
T_4 V_6 = FALSE ;
struct V_7 V_8 ;
T_5 * V_9 ;
if( ! F_2 ( V_1 -> V_10 , & V_8 , sizeof( struct V_7 ) , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return V_12 ;
}
return V_13 ;
}
if( V_8 . V_14 != 0 || V_8 . V_15 == 0 ) {
return V_13 ;
}
V_8 . V_16 = F_3 ( & V_8 . V_16 ) ;
V_8 . V_15 = F_4 ( & V_8 . V_15 ) ;
if( ! F_2 ( V_1 -> V_10 , & V_4 , 2 , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return V_12 ;
}
return V_13 ;
}
if( ! F_2 ( V_1 -> V_10 , & V_5 , 2 , V_2 , V_3 ) ) {
if( * V_2 != V_11 ) {
return V_12 ;
}
return V_13 ;
}
V_5 = F_4 ( & V_5 ) ;
if ( V_5 == 0 )
return V_13 ;
if( V_5 > V_8 . V_15 ) {
V_5 = F_5 ( V_5 ) ;
if( V_5 <= V_8 . V_15 ) {
V_6 = TRUE ;
} else {
return V_13 ;
}
} else {
V_6 = FALSE ;
}
if ( F_6 ( V_1 -> V_10 , 0 , V_17 , V_2 ) == - 1 )
return V_12 ;
V_9 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_1 -> V_18 = ( void * ) V_9 ;
V_9 -> V_19 = V_6 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = 0 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = V_30 ;
return V_31 ;
}
static T_4 V_26 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_6 * V_32 )
{
T_5 * V_9 = ( T_5 * ) V_1 -> V_18 ;
* V_32 = F_8 ( V_1 -> V_10 ) ;
return F_9 ( V_1 -> V_10 , V_9 , & V_1 -> V_33 , V_1 -> V_34 ,
V_2 , V_3 ) ;
}
static T_4
V_28 ( T_2 * V_1 ,
T_6 V_35 ,
struct V_36 * V_33 ,
T_7 * V_37 ,
int * V_2 ,
T_3 * * V_3 )
{
T_5 * V_9 = ( T_5 * ) V_1 -> V_18 ;
if( F_6 ( V_1 -> V_38 , V_35 , V_17 , V_2 ) == - 1 )
return FALSE ;
if( ! F_9 ( V_1 -> V_38 , V_9 , V_33 , V_37 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_9 ( T_8 V_10 , T_5 * V_9 , struct V_36 * V_33 ,
T_7 * V_37 , int * V_2 , T_3 * * V_3 )
{
struct V_7 V_8 ;
T_9 * V_39 ;
if( ! F_10 ( V_10 , & V_8 , sizeof( struct V_7 ) , V_2 , V_3 ) )
return FALSE ;
V_8 . V_16 = F_3 ( & V_8 . V_16 ) ;
V_8 . V_15 = F_4 ( & V_8 . V_15 ) ;
V_33 -> V_40 = V_41 ;
V_33 -> V_42 = V_43 ;
V_33 -> V_44 = V_8 . V_15 ;
V_33 -> V_15 = V_8 . V_15 ;
V_33 -> V_45 . V_46 = V_8 . V_16 ;
V_33 -> V_45 . V_47 = 0 ;
if( ! F_11 ( V_10 , V_37 , V_33 -> V_15 , V_2 , V_3 ) )
return FALSE ;
V_39 = F_12 ( V_37 ) ;
if( V_9 -> V_19 ) {
if( V_33 -> V_15 >= 2 ) {
F_13 ( V_39 ) ;
if( V_33 -> V_15 >= 4 ) {
F_13 ( V_39 + 2 ) ;
if( V_33 -> V_15 >= 6 )
F_13 ( V_39 + 4 ) ;
}
}
}
return TRUE ;
}
