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
F_3 ( V_21 , V_22 L_1 , V_14 -> V_23 ) ;
F_1 ( V_1 ) ;
if ( V_14 -> V_23 == 2 ) {
if ( ( V_14 -> V_24 == V_25 ) && ( V_14 -> V_26 == 1 ) ) {
V_1 -> V_3 = true ;
}
return;
}
if ( V_14 -> V_23 < 6 ) {
return;
}
if ( ( V_14 -> V_24 == V_25 ) &&
( V_14 -> V_26 == 1 ) ) {
F_3 ( V_21 , V_22 L_2 ) ;
V_19 = & ( V_14 -> V_27 [ 0 ] ) ;
if ( ! memcmp ( V_19 , V_28 , 4 ) )
V_1 -> V_4 = V_29 ;
else if ( ! memcmp ( V_19 , V_30 , 4 ) )
V_1 -> V_4 = V_31 ;
else if ( ! memcmp ( V_19 , V_32 , 4 ) )
V_1 -> V_4 = V_5 ;
else if ( ! memcmp ( V_19 , V_33 , 4 ) )
V_1 -> V_4 = V_34 ;
else if ( ! memcmp ( V_19 , V_35 , 4 ) ) {
return;
} else
V_1 -> V_4 = V_36 ;
F_3 ( V_21 , V_22 L_3 , V_1 -> V_4 ) ;
if ( V_14 -> V_23 == 6 ) {
V_1 -> V_3 = true ;
return;
}
if ( V_14 -> V_23 >= 8 ) {
V_1 -> V_7 = * ( ( unsigned short * ) & ( V_14 -> V_27 [ 4 ] ) ) ;
V_16 = 0 ;
V_19 = & ( V_14 -> V_27 [ 6 ] ) ;
for ( V_15 = 0 ; ( V_15 < V_1 -> V_7 ) && ( V_16 < sizeof( V_1 -> V_6 ) /sizeof( unsigned char ) ) ; V_15 ++ ) {
if ( V_14 -> V_23 >= 8 + V_15 * 4 + 4 ) {
if ( ! memcmp ( V_19 , V_35 , 4 ) ) {
V_1 -> V_6 [ V_16 ++ ] = V_37 ;
V_20 = true ;
} else if ( ! memcmp ( V_19 , V_28 , 4 ) ) {
} else if ( ! memcmp ( V_19 , V_30 , 4 ) ) {
if ( V_1 -> V_4 != V_5 )
V_1 -> V_6 [ V_16 ++ ] = V_31 ;
else
;
} else if ( ! memcmp ( V_19 , V_32 , 4 ) ) {
V_1 -> V_6 [ V_16 ++ ] = V_5 ;
} else if ( ! memcmp ( V_19 , V_33 , 4 ) ) {
} else {
V_1 -> V_6 [ V_16 ++ ] = V_36 ;
}
V_19 += 4 ;
F_3 ( V_21 , V_22 L_4 , V_16 - 1 , V_1 -> V_6 [ V_16 - 1 ] ) ;
} else
break;
}
if ( V_20 == true ) {
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
F_3 ( V_21 , V_22 L_5 , V_1 -> V_7 ) ;
}
V_17 = * ( ( unsigned short * ) & ( V_14 -> V_27 [ 4 ] ) ) ;
if ( V_14 -> V_23 >= 10 + V_17 * 4 ) {
V_1 -> V_10 = * ( ( unsigned short * ) & ( V_14 -> V_27 [ 6 + 4 * V_17 ] ) ) ;
V_16 = 0 ;
V_19 = & ( V_14 -> V_27 [ 8 + 4 * V_17 ] ) ;
for ( V_15 = 0 ; ( V_15 < V_1 -> V_10 ) && ( V_16 < sizeof( V_1 -> V_8 ) /sizeof( unsigned char ) ) ; V_15 ++ ) {
if ( V_14 -> V_23 >= 10 + ( V_17 + V_15 ) * 4 + 4 ) {
if ( ! memcmp ( V_19 , V_38 , 4 ) )
V_1 -> V_8 [ V_16 ++ ] = V_9 ;
else if ( ! memcmp ( V_19 , V_39 , 4 ) )
V_1 -> V_8 [ V_16 ++ ] = V_40 ;
else
V_1 -> V_8 [ V_16 ++ ] = V_41 ;
F_3 ( V_21 , V_22 L_6 , V_16 - 1 , V_1 -> V_8 [ V_16 - 1 ] ) ;
} else
break;
}
V_1 -> V_10 = ( unsigned short ) V_16 ;
F_3 ( V_21 , V_22 L_7 , V_1 -> V_10 ) ;
V_18 = * ( ( unsigned short * ) & ( V_14 -> V_27 [ 6 + 4 * V_17 ] ) ) ;
if ( V_14 -> V_23 >= 12 + 4 * V_17 + 4 * V_18 ) {
V_1 -> V_11 . V_12 = true ;
V_1 -> V_11 . V_13 = * ( ( unsigned short * ) & ( V_14 -> V_27 [ 8 + 4 * V_17 + 4 * V_18 ] ) ) ;
}
}
V_1 -> V_3 = true ;
}
}
unsigned int
F_4 (
void * V_42 ,
T_2 V_43
)
{
T_3 V_44 = ( T_3 ) V_42 ;
unsigned char * V_45 = NULL ;
unsigned int V_2 = 0 ;
unsigned short * V_46 = NULL ;
if ( V_43 == NULL ) {
return 0 ;
}
if ( ( ( V_44 -> V_47 == V_48 ) ||
( V_44 -> V_47 == V_49 ) ) &&
( V_44 -> V_50 != NULL ) ) {
V_45 = ( unsigned char * ) V_43 ;
V_43 -> V_24 = V_25 ;
V_43 -> V_23 = 6 ;
V_43 -> V_26 = 1 ;
V_43 -> V_27 [ 0 ] = 0x00 ;
V_43 -> V_27 [ 1 ] = 0x0F ;
V_43 -> V_27 [ 2 ] = 0xAC ;
if ( V_44 -> V_4 == V_51 ) {
V_43 -> V_27 [ 3 ] = V_44 -> V_50 -> V_4 ;
} else if ( V_44 -> V_4 == V_52 ) {
V_43 -> V_27 [ 3 ] = V_31 ;
} else if ( V_44 -> V_4 == V_53 ) {
V_43 -> V_27 [ 3 ] = V_5 ;
} else {
V_43 -> V_27 [ 3 ] = V_36 ;
}
V_43 -> V_27 [ 4 ] = 1 ;
V_43 -> V_27 [ 5 ] = 0 ;
V_43 -> V_27 [ 6 ] = 0x00 ;
V_43 -> V_27 [ 7 ] = 0x0F ;
V_43 -> V_27 [ 8 ] = 0xAC ;
if ( V_44 -> V_54 == V_52 ) {
V_43 -> V_27 [ 9 ] = V_31 ;
} else if ( V_44 -> V_54 == V_53 ) {
V_43 -> V_27 [ 9 ] = V_5 ;
} else if ( V_44 -> V_54 == V_55 ) {
V_43 -> V_27 [ 9 ] = V_37 ;
} else {
V_43 -> V_27 [ 9 ] = V_36 ;
}
V_43 -> V_23 += 6 ;
V_43 -> V_27 [ 10 ] = 1 ;
V_43 -> V_27 [ 11 ] = 0 ;
V_43 -> V_27 [ 12 ] = 0x00 ;
V_43 -> V_27 [ 13 ] = 0x0F ;
V_43 -> V_27 [ 14 ] = 0xAC ;
if ( V_44 -> V_47 == V_49 ) {
V_43 -> V_27 [ 15 ] = V_40 ;
} else if ( V_44 -> V_47 == V_48 ) {
V_43 -> V_27 [ 15 ] = V_9 ;
} else {
V_43 -> V_27 [ 15 ] = V_41 ;
}
V_43 -> V_23 += 6 ;
if ( V_44 -> V_50 -> V_11 . V_12 == true ) {
memcpy ( & V_43 -> V_27 [ 16 ] , & V_44 -> V_50 -> V_11 . V_13 , 2 ) ;
} else {
V_43 -> V_27 [ 16 ] = 0 ;
V_43 -> V_27 [ 17 ] = 0 ;
}
V_43 -> V_23 += 2 ;
if ( ( V_44 -> V_56 . V_57 > 0 ) &&
( V_44 -> V_58 == true ) &&
( V_44 -> V_47 == V_48 ) ) {
V_46 = ( unsigned short * ) ( & V_43 -> V_27 [ 18 ] ) ;
* V_46 = 0 ;
V_45 = & V_43 -> V_27 [ 20 ] ;
for ( V_2 = 0 ; V_2 < V_44 -> V_56 . V_57 ; V_2 ++ ) {
if ( ! memcmp ( & V_44 -> V_56 . V_59 [ V_2 ] . V_60 [ 0 ] , V_44 -> V_61 , V_62 ) ) {
( * V_46 ) ++ ;
memcpy ( V_45 , V_44 -> V_56 . V_59 [ V_2 ] . V_63 , 16 ) ;
V_45 += 16 ;
}
}
if ( * V_46 != 0 ) {
V_43 -> V_23 += ( 2 + ( * V_46 ) * 16 ) ;
} else {
V_45 = & V_43 -> V_27 [ 18 ] ;
}
}
return V_43 -> V_23 + V_64 ;
}
return 0 ;
}
