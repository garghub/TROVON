int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
T_4 type ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return - 1 ;
if ( F_3 ( & type , 1 , V_1 -> V_5 ) <= 0 )
return - 1 ;
if ( ! ( ( 8 <= V_4 . V_6 ) && ( V_4 . V_6 < 65536 ) &&
( type < 0x04 || type == 0xFB || type == 0xFC || type == 0xFE || type == 0xFF ) ) )
return 0 ;
if ( F_4 ( V_1 -> V_5 , 0 , V_7 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_8 = V_9 ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
return 1 ;
}
static T_5
V_9 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 * V_18 )
{
T_3 V_4 ;
T_7 V_19 ;
* V_18 = F_5 ( V_1 -> V_5 ) ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return FALSE ;
if ( V_4 . V_6 < 8 ) {
* V_2 = V_20 ;
* V_3 = F_6 ( L_1 , V_4 . V_6 ) ;
return FALSE ;
}
if ( V_4 . V_6 - 8 > V_21 ) {
* V_2 = V_20 ;
* V_3 = F_6 ( L_2 ,
V_4 . V_6 - 8 , V_21 ) ;
return FALSE ;
}
F_7 ( V_1 -> V_22 , V_4 . V_6 - 8 ) ;
V_19 = F_3 ( F_8 ( V_1 -> V_22 ) ,
V_4 . V_6 - 8 ,
V_1 -> V_5 ) ;
if( V_19 != V_4 . V_6 - 8 ) {
* V_2 = F_9 ( V_1 -> V_5 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_23 ;
return FALSE ;
}
V_1 -> V_24 . V_25 = V_26 ;
V_1 -> V_24 . V_6 = V_4 . V_6 - 8 ;
V_1 -> V_24 . V_27 = V_4 . V_6 - 8 ;
V_1 -> V_24 . V_28 . V_29 = ( V_30 ) ( V_4 . V_28 >> 32 ) ;
V_1 -> V_24 . V_28 . V_31 = ( int ) ( ( V_4 . V_28 & 0xFFFFFFFF ) * 1000 ) ;
return TRUE ;
}
static T_5
V_11 ( T_1 * V_1 , T_6 V_32 , union V_33
* T_8 V_34 , T_4 * V_35 , int V_36 , int * V_2 ,
T_2 * * V_3 )
{
T_3 V_4 ;
T_7 V_19 ;
if( F_4 ( V_1 -> V_37 , V_32 , V_7 , V_2 ) == - 1 )
return FALSE ;
if( ! F_2 ( & V_4 , V_1 -> V_37 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_23 ;
return FALSE ;
}
if( V_36 != ( int ) V_4 . V_6 - 8 ) {
* V_2 = V_20 ;
* V_3 = F_6 ( L_3 , V_4 . V_6 , V_36 ) ;
return FALSE ;
}
V_19 = F_3 ( V_35 , V_4 . V_6 - 8 , V_1 -> V_37 ) ;
if( V_19 != ( V_4 . V_6 - 8 ) ) {
* V_2 = F_9 ( V_1 -> V_37 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_23 ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_2 ( T_3 * V_4 , T_9 V_5 , int * V_2 ,
T_2 * * V_3 )
{
F_10 ( & V_4 -> V_6 , 4 , V_5 , V_2 , V_3 ) ;
F_10 ( & V_4 -> V_28 , 8 , V_5 , V_2 , V_3 ) ;
V_4 -> V_6 = F_11 ( V_4 -> V_6 ) ;
V_4 -> V_28 = F_12 ( V_4 -> V_28 ) ;
return TRUE ;
}
