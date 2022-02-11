int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
T_4 type ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_6 )
return - 1 ;
return 0 ;
}
if ( F_3 ( & type , 1 , V_1 -> V_5 ) <= 0 ) {
* V_2 = F_4 ( V_1 -> V_5 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_6 )
return - 1 ;
return 0 ;
}
if ( ! ( ( 8 <= V_4 . V_7 ) && ( V_4 . V_7 < 65536 ) &&
( type < 0x04 || type == 0xFB || type == 0xFC || type == 0xFE || type == 0xFF ) ) )
return 0 ;
if ( F_5 ( V_1 -> V_5 , 0 , V_8 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_9 = V_10 ;
V_1 -> V_11 = V_12 ;
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_18 ;
return 1 ;
}
static T_5
V_10 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 * V_19 )
{
T_3 V_4 ;
T_7 V_20 ;
* V_19 = F_6 ( V_1 -> V_5 ) ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return FALSE ;
if ( V_4 . V_7 < 8 ) {
* V_2 = V_21 ;
* V_3 = F_7 ( L_1 , V_4 . V_7 ) ;
return FALSE ;
}
if ( V_4 . V_7 - 8 > V_22 ) {
* V_2 = V_21 ;
* V_3 = F_7 ( L_2 ,
V_4 . V_7 - 8 , V_22 ) ;
return FALSE ;
}
F_8 ( V_1 -> V_23 , V_4 . V_7 - 8 ) ;
V_20 = F_3 ( F_9 ( V_1 -> V_23 ) ,
V_4 . V_7 - 8 ,
V_1 -> V_5 ) ;
if( V_20 != V_4 . V_7 - 8 ) {
* V_2 = F_4 ( V_1 -> V_5 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
V_1 -> V_24 . V_25 = V_26 ;
V_1 -> V_24 . V_7 = V_4 . V_7 - 8 ;
V_1 -> V_24 . V_27 = V_4 . V_7 - 8 ;
V_1 -> V_24 . V_28 . V_29 = ( V_30 ) ( V_4 . V_28 >> 32 ) ;
V_1 -> V_24 . V_28 . V_31 = ( int ) ( ( V_4 . V_28 & 0xFFFFFFFF ) * 1000 ) ;
return TRUE ;
}
static T_5
V_12 ( T_1 * V_1 , T_6 V_32 , struct V_33 * V_24 V_34 ,
T_4 * V_35 , int V_36 , int * V_2 ,
T_2 * * V_3 )
{
T_3 V_4 ;
T_7 V_20 ;
if( F_5 ( V_1 -> V_37 , V_32 , V_8 , V_2 ) == - 1 )
return FALSE ;
if( ! F_2 ( & V_4 , V_1 -> V_37 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
if( V_36 != ( int ) V_4 . V_7 - 8 ) {
* V_2 = V_21 ;
* V_3 = F_7 ( L_3 , V_4 . V_7 , V_36 ) ;
return FALSE ;
}
V_20 = F_3 ( V_35 , V_4 . V_7 - 8 , V_1 -> V_37 ) ;
if( V_20 != ( V_4 . V_7 - 8 ) ) {
* V_2 = F_4 ( V_1 -> V_37 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_2 ( T_3 * V_4 , T_8 V_5 , int * V_2 ,
T_2 * * V_3 )
{
F_10 ( & V_4 -> V_7 , 4 , V_5 , V_2 , V_3 ) ;
F_10 ( & V_4 -> V_28 , 8 , V_5 , V_2 , V_3 ) ;
V_4 -> V_7 = F_11 ( V_4 -> V_7 ) ;
V_4 -> V_28 = F_12 ( V_4 -> V_28 ) ;
return TRUE ;
}
