void
F_1 (
T_1 V_1
)
{
int V_2 ;
V_1 -> V_3 = V_4 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
V_1 -> V_5 [ V_2 ] = V_4 ;
V_1 -> V_6 = 0 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
V_1 -> V_7 [ V_2 ] = V_8 ;
V_1 -> V_9 = 0 ;
V_1 -> V_10 = 0 ;
V_1 -> V_11 = 0 ;
V_1 -> V_12 . V_13 = false ;
V_1 -> V_12 . V_14 = 0 ;
V_1 -> V_15 = false ;
}
void
F_2 (
T_1 V_1 ,
T_2 V_16
)
{
T_3 V_17 = NULL ;
int V_18 , V_19 , V_20 , V_21 = 0 ;
T_4 V_22 ;
F_1 ( V_1 ) ;
F_3 ( V_23 , V_24 L_1 , V_16 -> V_25 ) ;
if ( ( V_16 -> V_25 >= 6 )
&& ( V_16 -> V_26 == V_27 ) && ! memcmp ( V_16 -> V_28 , V_29 , 4 )
&& ( V_16 -> V_30 == 1 ) ) {
F_3 ( V_23 , V_24 L_2 ) ;
if ( V_16 -> V_25 >= 10 )
{
if ( ! memcmp ( V_16 -> V_31 , V_29 , 4 ) )
V_1 -> V_3 = V_32 ;
else if ( ! memcmp ( V_16 -> V_31 , V_33 , 4 ) )
V_1 -> V_3 = V_4 ;
else if ( ! memcmp ( V_16 -> V_31 , V_34 , 4 ) )
V_1 -> V_3 = V_35 ;
else if ( ! memcmp ( V_16 -> V_31 , V_36 , 4 ) )
V_1 -> V_3 = V_37 ;
else if ( ! memcmp ( V_16 -> V_31 , V_38 , 4 ) )
V_1 -> V_3 = V_39 ;
else
V_1 -> V_3 = V_40 ;
F_3 ( V_23 , V_24 L_3 , V_1 -> V_3 ) ;
}
if ( V_16 -> V_25 >= 12 )
{
V_19 = 0 ;
F_3 ( V_23 , V_24 L_4 , V_16 -> V_6 , sizeof( V_1 -> V_5 ) ) ;
for ( V_18 = 0 ; ( V_18 < V_16 -> V_6 ) &&
( V_19 < F_4 ( V_1 -> V_5 ) ) ; V_18 ++ ) {
if( V_16 -> V_25 >= 12 + V_18 * 4 + 4 ) {
if ( ! memcmp ( V_16 -> V_41 [ V_18 ] . V_28 , V_42 , 4 ) )
V_1 -> V_5 [ V_19 ++ ] = V_40 ;
else if ( ! memcmp ( V_16 -> V_41 [ V_18 ] . V_28 , V_33 , 4 ) )
V_1 -> V_5 [ V_19 ++ ] = V_4 ;
else if ( ! memcmp ( V_16 -> V_41 [ V_18 ] . V_28 , V_34 , 4 ) )
V_1 -> V_5 [ V_19 ++ ] = V_35 ;
else if ( ! memcmp ( V_16 -> V_41 [ V_18 ] . V_28 , V_36 , 4 ) )
V_1 -> V_5 [ V_19 ++ ] = V_37 ;
else
;
}
else
break;
}
V_1 -> V_6 = ( V_43 ) V_19 ;
F_3 ( V_23 , V_24 L_5 , V_1 -> V_6 ) ;
}
V_20 = V_16 -> V_6 ;
F_3 ( V_23 , V_24 L_6 , V_20 ) ;
F_3 ( V_23 , V_24 L_7 , 14 + V_20 * 4 ) ;
if ( V_16 -> V_25 >= 14 + V_20 * 4 ) {
V_17 = ( T_3 ) V_16 -> V_41 [ V_20 ] . V_28 ;
V_19 = 0 ;
F_3 ( V_23 , V_24 L_8 ,
V_17 -> V_9 , sizeof( V_1 -> V_7 ) ) ;
for ( V_18 = 0 ; ( V_18 < V_17 -> V_9 ) &&
( V_19 < F_4 ( V_1 -> V_7 ) ) ; V_18 ++ ) {
if( V_16 -> V_25 >= 14 + 4 + ( V_20 + V_18 ) * 4 ) {
if ( ! memcmp ( V_17 -> V_44 [ V_18 ] . V_28 , V_29 , 4 ) )
V_1 -> V_7 [ V_19 ++ ] = V_8 ;
else if ( ! memcmp ( V_17 -> V_44 [ V_18 ] . V_28 , V_33 , 4 ) )
V_1 -> V_7 [ V_19 ++ ] = V_45 ;
else
;
}
else
break;
}
if( V_19 > 0 )
V_1 -> V_9 = ( V_43 ) V_19 ;
F_3 ( V_23 , V_24 L_9 , V_1 -> V_9 ) ;
}
if ( V_17 != NULL ) {
V_21 = V_17 -> V_9 ;
F_3 ( V_23 , V_24 L_10 , V_21 ) ;
F_3 ( V_23 , V_24 L_11 , 14 + 4 + ( V_20 + V_21 ) * 4 ) ;
if( V_16 -> V_25 + 2 >= 14 + 4 + ( V_20 + V_21 ) * 4 ) {
V_22 = ( T_4 ) V_17 -> V_44 [ V_21 ] . V_28 ;
V_1 -> V_10 = ( * V_22 ) & V_46 ;
V_1 -> V_11 = 2 << ( ( * V_22 >> V_47 ) & V_48 ) ;
V_1 -> V_12 . V_13 = true ;
V_1 -> V_12 . V_14 = * ( V_49 ) V_22 ;
}
}
V_1 -> V_15 = true ;
}
}
bool
F_5 (
T_5 V_50 ,
T_5 V_51 ,
T_1 V_1
)
{
int V_2 ;
T_5 V_52 = V_40 ;
if ( V_1 -> V_15 == false )
return false ;
switch( V_50 ) {
case 0 :
if ( V_51 != V_1 -> V_3 )
return false ;
if ( V_1 -> V_6 > 0 ) {
for ( V_2 = 0 ; V_2 < V_1 -> V_6 ; V_2 ++ ) {
if ( V_1 -> V_5 [ V_2 ] == V_37 )
V_52 = V_37 ;
else if ( ( V_1 -> V_5 [ V_2 ] == V_4 ) && ( V_52 != V_37 ) )
V_52 = V_4 ;
else if ( ( V_1 -> V_5 [ V_2 ] == V_32 ) && ( V_52 != V_37 ) && ( V_52 != V_4 ) )
V_52 = V_32 ;
else if ( ( V_1 -> V_5 [ V_2 ] == V_39 ) && ( V_52 != V_37 ) && ( V_52 != V_4 ) )
V_52 = V_39 ;
}
if ( V_51 != V_52 )
return false ;
}
return true ;
break;
default:
break;
}
return false ;
}
bool
F_6 (
T_2 V_16
)
{
if ( V_16 == NULL )
return false ;
if ( ( V_16 -> V_25 >= 6 ) &&
( V_16 -> V_26 == V_27 ) && ! memcmp ( V_16 -> V_28 , V_29 , 4 ) &&
( V_16 -> V_30 == 1 ) ) {
return true ;
}
else
return false ;
}
