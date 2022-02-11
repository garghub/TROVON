T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 = FALSE ;
T_5 V_5 ;
T_6 type ;
T_7 * V_6 ;
if( ! F_2 ( & V_5 , V_1 -> V_7 , V_4 ,
V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_8 )
return V_9 ;
return V_10 ;
}
if ( ! F_3 ( V_1 -> V_7 , & type , 1 , V_2 , V_3 ) ) {
if ( * V_2 != V_8 )
return V_9 ;
return V_10 ;
}
if ( ( V_5 . V_11 & 0x0000FFFF ) == 0 &&
( V_5 . V_11 & 0xFFFF0000 ) != 0 ) {
V_5 . V_11 = ( ( V_5 . V_11 >> 24 ) & 0xFF ) |
( ( ( V_5 . V_11 >> 16 ) & 0xFF ) << 8 ) ;
V_4 = TRUE ;
}
if ( ! ( ( 8 <= V_5 . V_11 ) && ( V_5 . V_11 < 65536 ) &&
( type < 0x04 || type == 0xFB || type == 0xFC || type == 0xFE || type == 0xFF ) ) )
return V_10 ;
if ( F_4 ( V_1 -> V_7 , 0 , V_12 , V_2 ) == - 1 )
return V_9 ;
V_6 = ( T_7 * ) F_5 ( sizeof( T_7 ) ) ;
V_6 -> V_4 = V_4 ;
V_1 -> V_13 = ( void * ) V_6 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
return V_24 ;
}
static T_4
V_15 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_8 * V_25 )
{
* V_25 = F_6 ( V_1 -> V_7 ) ;
return F_7 ( V_1 , V_1 -> V_7 , & V_1 -> V_26 ,
V_1 -> V_27 , V_2 , V_3 ) ;
}
static T_4
V_17 ( T_2 * V_1 , T_8 V_28 , struct V_29 * V_26 ,
T_9 * V_30 , int * V_2 , T_3 * * V_3 )
{
if( F_4 ( V_1 -> V_31 , V_28 , V_12 , V_2 ) == - 1 )
return FALSE ;
if( ! F_7 ( V_1 , V_1 -> V_31 , V_26 , V_30 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_8 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_2 ( T_5 * V_5 , T_10 V_7 ,
T_4 V_4 , int * V_2 , T_3 * * V_3 )
{
if ( ! F_8 ( V_7 , & V_5 -> V_11 , 4 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_3 ( V_7 , & V_5 -> V_32 , 4 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_3 ( V_7 , & V_5 -> V_33 , 4 , V_2 , V_3 ) )
return FALSE ;
if ( V_4 ) {
V_5 -> V_11 = F_9 ( V_5 -> V_11 ) ;
V_5 -> V_32 = F_9 ( V_5 -> V_32 ) ;
V_5 -> V_33 = F_9 ( V_5 -> V_33 ) ;
} else {
V_5 -> V_11 = F_10 ( V_5 -> V_11 ) ;
V_5 -> V_32 = F_10 ( V_5 -> V_32 ) ;
V_5 -> V_33 = F_10 ( V_5 -> V_33 ) ;
}
return TRUE ;
}
static T_4
F_7 ( T_2 * V_1 , T_10 V_7 , struct V_29 * V_26 , T_9 * V_30 ,
int * V_2 , T_3 * * V_3 )
{
T_7 * V_6 = ( T_7 * ) V_1 -> V_13 ;
T_5 V_5 ;
if( ! F_2 ( & V_5 , V_7 , V_6 -> V_4 ,
V_2 , V_3 ) )
return FALSE ;
if ( V_5 . V_11 < 8 ) {
* V_2 = V_34 ;
* V_3 = F_11 ( L_1 , V_5 . V_11 ) ;
return FALSE ;
}
if ( V_5 . V_11 - 8 > V_35 ) {
* V_2 = V_34 ;
* V_3 = F_11 ( L_2 ,
V_5 . V_11 - 8 , V_35 ) ;
return FALSE ;
}
V_26 -> V_36 = V_37 ;
V_26 -> V_38 = V_1 -> V_20 ;
V_26 -> V_39 = V_40 ;
V_26 -> V_11 = V_5 . V_11 - 8 ;
V_26 -> V_41 = V_5 . V_11 - 8 ;
V_26 -> V_42 . V_43 = ( V_44 ) V_5 . V_32 ;
V_26 -> V_42 . V_45 = ( int ) ( V_5 . V_33 * 1000 ) ;
return F_12 ( V_7 , V_30 , V_26 -> V_41 , V_2 , V_3 ) ;
}
