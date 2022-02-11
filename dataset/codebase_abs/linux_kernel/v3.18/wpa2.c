void
F_1 (
T_1 V_1
)
{
int V_2 ;
V_1 -> V_3 = false ;
V_1 -> V_4 = V_5 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
V_1 -> V_6 [ V_2 ] = V_5 ;
V_1 -> V_7 = 1 ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
V_1 -> V_8 [ V_2 ] = V_9 ;
V_1 -> V_10 = 1 ;
V_1 -> V_11 . V_12 = false ;
V_1 -> V_11 . V_13 = 0 ;
}
void
F_2 (
T_1 V_1 ,
T_2 V_14
)
{
int V_15 , V_16 ;
unsigned short V_17 = 0 , V_18 = 0 ;
unsigned char * V_19 ;
bool V_20 = false ;
F_3 ( L_1 , V_14 -> V_21 ) ;
F_1 ( V_1 ) ;
if ( V_14 -> V_21 == 2 ) {
if ( ( V_14 -> V_22 == V_23 ) && ( V_14 -> V_24 == 1 ) )
V_1 -> V_3 = true ;
return;
}
if ( V_14 -> V_21 < 6 ) {
return;
}
if ( ( V_14 -> V_22 == V_23 ) &&
( V_14 -> V_24 == 1 ) ) {
F_3 ( L_2 ) ;
V_19 = & ( V_14 -> V_25 [ 0 ] ) ;
if ( ! memcmp ( V_19 , V_26 , 4 ) )
V_1 -> V_4 = V_27 ;
else if ( ! memcmp ( V_19 , V_28 , 4 ) )
V_1 -> V_4 = V_29 ;
else if ( ! memcmp ( V_19 , V_30 , 4 ) )
V_1 -> V_4 = V_5 ;
else if ( ! memcmp ( V_19 , V_31 , 4 ) )
V_1 -> V_4 = V_32 ;
else if ( ! memcmp ( V_19 , V_33 , 4 ) ) {
return;
} else
V_1 -> V_4 = V_34 ;
F_3 ( L_3 , V_1 -> V_4 ) ;
if ( V_14 -> V_21 == 6 ) {
V_1 -> V_3 = true ;
return;
}
if ( V_14 -> V_21 >= 8 ) {
V_1 -> V_7 = * ( ( unsigned short * ) & ( V_14 -> V_25 [ 4 ] ) ) ;
V_16 = 0 ;
V_19 = & ( V_14 -> V_25 [ 6 ] ) ;
for ( V_15 = 0 ; ( V_15 < V_1 -> V_7 ) && ( V_16 < sizeof( V_1 -> V_6 ) /sizeof( unsigned char ) ) ; V_15 ++ ) {
if ( V_14 -> V_21 >= 8 + V_15 * 4 + 4 ) {
if ( ! memcmp ( V_19 , V_33 , 4 ) ) {
V_1 -> V_6 [ V_16 ++ ] = V_35 ;
V_20 = true ;
} else if ( ! memcmp ( V_19 , V_26 , 4 ) ) {
} else if ( ! memcmp ( V_19 , V_28 , 4 ) ) {
if ( V_1 -> V_4 != V_5 )
V_1 -> V_6 [ V_16 ++ ] = V_29 ;
else
;
} else if ( ! memcmp ( V_19 , V_30 , 4 ) ) {
V_1 -> V_6 [ V_16 ++ ] = V_5 ;
} else if ( ! memcmp ( V_19 , V_31 , 4 ) ) {
} else {
V_1 -> V_6 [ V_16 ++ ] = V_34 ;
}
V_19 += 4 ;
F_3 ( L_4 ,
V_16 - 1 , V_1 -> V_6 [ V_16 - 1 ] ) ;
} else
break;
}
if ( V_20 ) {
if ( V_16 != 1 ) {
return;
}
if ( V_1 -> V_4 == V_5 ) {
return;
}
}
if ( ( V_1 -> V_7 != 0 ) && ( V_16 == 0 ) ) {
return;
}
V_1 -> V_7 = ( unsigned short ) V_16 ;
F_3 ( L_5 , V_1 -> V_7 ) ;
}
V_17 = * ( ( unsigned short * ) & ( V_14 -> V_25 [ 4 ] ) ) ;
if ( V_14 -> V_21 >= 10 + V_17 * 4 ) {
V_1 -> V_10 = * ( ( unsigned short * ) & ( V_14 -> V_25 [ 6 + 4 * V_17 ] ) ) ;
V_16 = 0 ;
V_19 = & ( V_14 -> V_25 [ 8 + 4 * V_17 ] ) ;
for ( V_15 = 0 ; ( V_15 < V_1 -> V_10 ) && ( V_16 < sizeof( V_1 -> V_8 ) /sizeof( unsigned char ) ) ; V_15 ++ ) {
if ( V_14 -> V_21 >= 10 + ( V_17 + V_15 ) * 4 + 4 ) {
if ( ! memcmp ( V_19 , V_36 , 4 ) )
V_1 -> V_8 [ V_16 ++ ] = V_9 ;
else if ( ! memcmp ( V_19 , V_37 , 4 ) )
V_1 -> V_8 [ V_16 ++ ] = V_38 ;
else
V_1 -> V_8 [ V_16 ++ ] = V_39 ;
F_3 ( L_6 ,
V_16 - 1 ,
V_1 -> V_8 [ V_16 - 1 ] ) ;
} else
break;
}
V_1 -> V_10 = ( unsigned short ) V_16 ;
F_3 ( L_7 ,
V_1 -> V_10 ) ;
V_18 = * ( ( unsigned short * ) & ( V_14 -> V_25 [ 6 + 4 * V_17 ] ) ) ;
if ( V_14 -> V_21 >= 12 + 4 * V_17 + 4 * V_18 ) {
V_1 -> V_11 . V_12 = true ;
V_1 -> V_11 . V_13 = * ( ( unsigned short * ) & ( V_14 -> V_25 [ 8 + 4 * V_17 + 4 * V_18 ] ) ) ;
}
}
V_1 -> V_3 = true ;
}
}
unsigned int
F_4 (
void * V_40 ,
T_2 V_41
)
{
T_3 V_42 = ( T_3 ) V_40 ;
unsigned char * V_43 = NULL ;
unsigned int V_2 = 0 ;
unsigned short * V_44 = NULL ;
if ( V_41 == NULL )
return 0 ;
if ( ( ( V_42 -> V_45 == V_46 ) ||
( V_42 -> V_45 == V_47 ) ) &&
( V_42 -> V_48 != NULL ) ) {
V_43 = ( unsigned char * ) V_41 ;
V_41 -> V_22 = V_23 ;
V_41 -> V_21 = 6 ;
V_41 -> V_24 = 1 ;
V_41 -> V_25 [ 0 ] = 0x00 ;
V_41 -> V_25 [ 1 ] = 0x0F ;
V_41 -> V_25 [ 2 ] = 0xAC ;
if ( V_42 -> V_4 == V_49 )
V_41 -> V_25 [ 3 ] = V_42 -> V_48 -> V_4 ;
else if ( V_42 -> V_4 == V_50 )
V_41 -> V_25 [ 3 ] = V_29 ;
else if ( V_42 -> V_4 == V_51 )
V_41 -> V_25 [ 3 ] = V_5 ;
else
V_41 -> V_25 [ 3 ] = V_34 ;
V_41 -> V_25 [ 4 ] = 1 ;
V_41 -> V_25 [ 5 ] = 0 ;
V_41 -> V_25 [ 6 ] = 0x00 ;
V_41 -> V_25 [ 7 ] = 0x0F ;
V_41 -> V_25 [ 8 ] = 0xAC ;
if ( V_42 -> V_52 == V_50 )
V_41 -> V_25 [ 9 ] = V_29 ;
else if ( V_42 -> V_52 == V_51 )
V_41 -> V_25 [ 9 ] = V_5 ;
else if ( V_42 -> V_52 == V_53 )
V_41 -> V_25 [ 9 ] = V_35 ;
else
V_41 -> V_25 [ 9 ] = V_34 ;
V_41 -> V_21 += 6 ;
V_41 -> V_25 [ 10 ] = 1 ;
V_41 -> V_25 [ 11 ] = 0 ;
V_41 -> V_25 [ 12 ] = 0x00 ;
V_41 -> V_25 [ 13 ] = 0x0F ;
V_41 -> V_25 [ 14 ] = 0xAC ;
if ( V_42 -> V_45 == V_47 )
V_41 -> V_25 [ 15 ] = V_38 ;
else if ( V_42 -> V_45 == V_46 )
V_41 -> V_25 [ 15 ] = V_9 ;
else
V_41 -> V_25 [ 15 ] = V_39 ;
V_41 -> V_21 += 6 ;
if ( V_42 -> V_48 -> V_11 . V_12 == true ) {
memcpy ( & V_41 -> V_25 [ 16 ] , & V_42 -> V_48 -> V_11 . V_13 , 2 ) ;
} else {
V_41 -> V_25 [ 16 ] = 0 ;
V_41 -> V_25 [ 17 ] = 0 ;
}
V_41 -> V_21 += 2 ;
if ( ( V_42 -> V_54 . V_55 > 0 ) &&
V_42 -> V_56 &&
( V_42 -> V_45 == V_46 ) ) {
V_44 = ( unsigned short * ) ( & V_41 -> V_25 [ 18 ] ) ;
* V_44 = 0 ;
V_43 = & V_41 -> V_25 [ 20 ] ;
for ( V_2 = 0 ; V_2 < V_42 -> V_54 . V_55 ; V_2 ++ ) {
if ( ! memcmp ( & V_42 -> V_54 . V_57 [ V_2 ] . V_58 [ 0 ] , V_42 -> V_59 , V_60 ) ) {
( * V_44 ) ++ ;
memcpy ( V_43 , V_42 -> V_54 . V_57 [ V_2 ] . V_61 , 16 ) ;
V_43 += 16 ;
}
}
if ( * V_44 != 0 )
V_41 -> V_21 += ( 2 + ( * V_44 ) * 16 ) ;
else
V_43 = & V_41 -> V_25 [ 18 ] ;
}
return V_41 -> V_21 + V_62 ;
}
return 0 ;
}
