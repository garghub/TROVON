void F_1 ( T_1 * V_1 )
{
#ifndef F_2
V_1 -> V_2 = V_3 ;
#else
const char * V_2 = V_1 -> V_4 -> V_2 ;
const char * V_5 = V_1 -> V_4 -> V_5 ;
V_1 -> V_2 = V_3 ;
if ( V_1 -> V_6 )
return;
if ( V_1 -> V_4 -> type == V_7 ) {
V_1 -> V_2 = V_8 ;
} else if ( ! strncmp ( V_2 , L_1 , 3 ) ) {
V_1 -> V_2 = V_9 ;
if ( ! strncmp ( V_5 , L_2 , 15 ) ||
! strncmp ( V_5 , L_3 , 15 ) ||
! strncmp ( V_5 , L_4 , 15 ) ||
! strncmp ( V_5 , L_5 , 16 )
#if 0
|| !strncmp(model, "CD-ROM DRIVE:500", 16)
#endif
)
V_1 -> V_10 . V_11 |= V_12 ;
} else if ( ! strncmp ( V_2 , L_6 , 7 ) ) {
V_1 -> V_2 = V_13 ;
}
#endif
}
int F_3 ( T_1 * V_1 , int V_14 )
{
unsigned char * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
int V_20 , V_21 = 0 ;
#ifdef F_2
if ( V_1 -> V_2 == V_13 )
V_21 = ( V_14 > 2048 ) ? 0x81 : 0x83 ;
#endif
V_15 = F_4 ( 512 , V_22 | V_23 ) ;
if ( ! V_15 )
return - V_24 ;
#ifdef F_5
F_6 ( L_7 , V_1 -> V_10 . V_25 , V_21 , V_14 ) ;
#endif
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 . V_26 [ 0 ] = V_27 ;
V_17 . V_26 [ 1 ] = ( 1 << 4 ) ;
V_17 . V_26 [ 4 ] = 12 ;
V_19 = (struct V_18 * ) V_15 ;
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_28 = 0x08 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_29 = ( V_14 >> 8 ) & 0xff ;
V_19 -> V_30 = V_14 & 0xff ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = sizeof( * V_19 ) ;
V_17 . V_32 = V_33 ;
V_17 . V_34 = V_35 ;
if ( 0 == ( V_20 = F_7 ( V_1 , & V_17 ) ) ) {
V_1 -> V_4 -> V_36 = V_14 ;
}
#ifdef F_5
else
F_6 ( L_8 ,
V_1 -> V_10 . V_25 , V_14 ) ;
#endif
F_8 ( V_15 ) ;
return V_20 ;
}
int F_9 ( struct V_37 * V_10 )
{
T_1 * V_1 = V_10 -> V_38 ;
unsigned long V_39 ;
unsigned char * V_15 ;
struct V_16 V_17 ;
int V_20 , V_40 ;
if ( V_1 -> V_10 . V_11 & V_12 )
return 0 ;
V_15 = F_4 ( 512 , V_22 | V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_39 = 0 ;
V_40 = 0 ;
V_20 = 0 ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
switch ( V_1 -> V_2 ) {
case V_3 :
V_17 . V_26 [ 0 ] = V_41 ;
V_17 . V_26 [ 8 ] = 12 ;
V_17 . V_26 [ 9 ] = 0x40 ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = 12 ;
V_17 . V_42 = 1 ;
V_17 . V_32 = V_43 ;
V_17 . V_34 = V_35 ;
V_20 = F_7 ( V_1 , & V_17 ) ;
if ( V_20 != 0 )
break;
if ( ( V_15 [ 0 ] << 8 ) + V_15 [ 1 ] < 0x0a ) {
F_6 ( V_44 L_9
L_10 , V_1 -> V_10 . V_25 ) ;
V_40 = 1 ;
break;
}
V_39 = V_15 [ 11 ] + ( V_15 [ 10 ] << 8 ) +
( V_15 [ 9 ] << 16 ) + ( V_15 [ 8 ] << 24 ) ;
if ( V_15 [ 6 ] <= 1 ) {
V_39 = 0 ;
}
break;
#ifdef F_2
case V_9 : {
unsigned long V_45 , V_46 , V_47 ;
V_17 . V_26 [ 0 ] = 0xde ;
V_17 . V_26 [ 1 ] = 0x03 ;
V_17 . V_26 [ 2 ] = 0xb0 ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = 0x16 ;
V_17 . V_42 = 1 ;
V_17 . V_32 = V_43 ;
V_17 . V_34 = V_35 ;
V_20 = F_7 ( V_1 , & V_17 ) ;
if ( V_20 != 0 )
break;
if ( V_15 [ 14 ] != 0 && V_15 [ 14 ] != 0xb0 ) {
F_6 ( V_44 L_11
L_10 ,
V_1 -> V_10 . V_25 ) ;
V_40 = 1 ;
break;
}
V_45 = F_10 ( V_15 [ 15 ] ) ;
V_46 = F_10 ( V_15 [ 16 ] ) ;
V_47 = F_10 ( V_15 [ 17 ] ) ;
V_39 = V_45 * V_48 * V_49 + V_46 * V_49 + V_47 ;
break;
}
case V_13 : {
unsigned long V_45 , V_46 , V_47 ;
V_17 . V_26 [ 0 ] = 0xc7 ;
V_17 . V_26 [ 1 ] = 0x03 ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = 4 ;
V_17 . V_42 = 1 ;
V_17 . V_32 = V_43 ;
V_17 . V_34 = V_35 ;
V_20 = F_7 ( V_1 , & V_17 ) ;
if ( V_20 == - V_50 ) {
F_6 ( V_44 L_9
L_10 ,
V_1 -> V_10 . V_25 ) ;
V_40 = 1 ;
break;
}
if ( V_20 != 0 )
break;
V_45 = F_10 ( V_15 [ 1 ] ) ;
V_46 = F_10 ( V_15 [ 2 ] ) ;
V_47 = F_10 ( V_15 [ 3 ] ) ;
V_39 = V_45 * V_48 * V_49 + V_46 * V_49 + V_47 ;
if ( V_39 )
V_39 -= V_51 ;
F_3 ( V_1 , 2048 ) ;
break;
}
case V_8 :
V_17 . V_26 [ 0 ] = V_41 ;
V_17 . V_26 [ 8 ] = 0x04 ;
V_17 . V_26 [ 9 ] = 0x40 ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = 0x04 ;
V_17 . V_42 = 1 ;
V_17 . V_32 = V_43 ;
V_17 . V_34 = V_35 ;
V_20 = F_7 ( V_1 , & V_17 ) ;
if ( V_20 != 0 ) {
break;
}
if ( ( V_20 = V_15 [ 2 ] ) == 0 ) {
F_6 ( V_52
L_12 , V_1 -> V_10 . V_25 ) ;
break;
}
V_17 . V_26 [ 0 ] = V_41 ;
V_17 . V_26 [ 6 ] = V_20 & 0x7f ;
V_17 . V_26 [ 8 ] = 0x0c ;
V_17 . V_26 [ 9 ] = 0x40 ;
V_17 . V_15 = V_15 ;
V_17 . V_31 = 12 ;
V_17 . V_42 = 1 ;
V_17 . V_32 = V_43 ;
V_17 . V_34 = V_35 ;
V_20 = F_7 ( V_1 , & V_17 ) ;
if ( V_20 != 0 ) {
break;
}
V_39 = V_15 [ 11 ] + ( V_15 [ 10 ] << 8 ) +
( V_15 [ 9 ] << 16 ) + ( V_15 [ 8 ] << 24 ) ;
break;
#endif
default:
F_6 ( V_52
L_13 ,
V_1 -> V_10 . V_25 , V_1 -> V_2 ) ;
V_39 = 0 ;
V_40 = 1 ;
break;
}
V_1 -> V_53 = V_39 ;
V_1 -> V_54 = 0 ;
if ( V_55 != F_11 ( V_10 ) && 1 == F_12 ( V_1 ) )
V_1 -> V_54 = 1 ;
if ( 2048 != V_1 -> V_4 -> V_36 ) {
F_3 ( V_1 , 2048 ) ;
}
if ( V_40 )
V_10 -> V_11 |= V_12 ;
#ifdef F_5
if ( V_39 )
F_6 ( V_56 L_14 ,
V_1 -> V_10 . V_25 , V_39 ) ;
#endif
F_8 ( V_15 ) ;
return V_20 ;
}
