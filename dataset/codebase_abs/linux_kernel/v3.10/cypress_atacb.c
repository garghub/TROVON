static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
if ( F_2 ( V_2 -> V_7 [ 0 ] != V_8 && V_2 -> V_7 [ 0 ] != V_9 ) ) {
F_3 ( V_2 , V_4 ) ;
return;
}
memcpy ( V_5 , V_2 -> V_7 , sizeof( V_5 ) ) ;
memset ( V_2 -> V_7 , 0 , V_6 ) ;
if ( V_5 [ 1 ] >> 5 )
goto V_10;
switch( ( V_5 [ 1 ] >> 1 ) & 0xf ) {
case 3 :
case 4 :
case 5 :
break;
default:
goto V_10;
}
V_2 -> V_11 = 16 ;
V_2 -> V_7 [ 0 ] = 0x24 ;
V_2 -> V_7 [ 1 ] = 0x24 ;
V_2 -> V_7 [ 3 ] = 0xff - 1 ;
V_2 -> V_7 [ 4 ] = 1 ;
if ( V_5 [ 0 ] == V_8 ) {
V_2 -> V_7 [ 6 ] = V_5 [ 4 ] ;
V_2 -> V_7 [ 7 ] = V_5 [ 6 ] ;
V_2 -> V_7 [ 8 ] = V_5 [ 8 ] ;
V_2 -> V_7 [ 9 ] = V_5 [ 10 ] ;
V_2 -> V_7 [ 10 ] = V_5 [ 12 ] ;
V_2 -> V_7 [ 11 ] = V_5 [ 13 ] ;
V_2 -> V_7 [ 12 ] = V_5 [ 14 ] ;
if ( V_5 [ 1 ] & 0x01 ) {
if ( V_5 [ 3 ] || V_5 [ 5 ] || V_5 [ 7 ] || V_5 [ 9 ]
|| V_5 [ 11 ] )
goto V_10;
}
}
else {
V_2 -> V_7 [ 6 ] = V_5 [ 3 ] ;
V_2 -> V_7 [ 7 ] = V_5 [ 4 ] ;
V_2 -> V_7 [ 8 ] = V_5 [ 5 ] ;
V_2 -> V_7 [ 9 ] = V_5 [ 6 ] ;
V_2 -> V_7 [ 10 ] = V_5 [ 7 ] ;
V_2 -> V_7 [ 11 ] = V_5 [ 8 ] ;
V_2 -> V_7 [ 12 ] = V_5 [ 9 ] ;
}
if ( ( V_2 -> V_7 [ 12 ] == V_12 )
&& ( V_2 -> V_7 [ 6 ] == V_13 ) )
goto V_10;
if ( V_2 -> V_7 [ 12 ] == V_14 || V_2 -> V_7 [ 12 ] == V_15 )
V_2 -> V_7 [ 2 ] |= ( 1 << 7 ) ;
F_3 ( V_2 , V_4 ) ;
if ( V_2 -> V_16 == V_17 &&
memcmp ( V_2 -> V_18 , V_19 ,
sizeof( V_19 ) ) == 0 ) {
F_4 ( V_4 , L_1 ) ;
goto V_20;
}
if ( ( V_2 -> V_16 != ( V_21 << 16 ) &&
V_2 -> V_16 != ( V_22 << 16 ) ) &&
V_5 [ 2 ] & 0x20 ) {
struct V_23 V_24 ;
unsigned char V_25 [ 8 ] ;
unsigned char * V_26 = V_2 -> V_18 ;
unsigned char * V_27 = V_26 + 8 ;
int V_28 ;
F_5 ( V_2 , & V_24 , NULL , 0 , sizeof( V_25 ) ) ;
V_2 -> V_11 = 16 ;
V_2 -> V_7 = V_24 . V_7 ;
V_2 -> V_7 [ 2 ] = 1 ;
F_3 ( V_2 , V_4 ) ;
memcpy ( V_25 , V_2 -> V_18 , sizeof( V_25 ) ) ;
V_28 = V_2 -> V_16 ;
F_6 ( V_2 , & V_24 ) ;
if ( V_28 != V_29 )
goto V_10;
memset ( V_26 , 0 , V_30 ) ;
V_26 [ 1 ] = V_31 ;
V_26 [ 2 ] = 0 ;
V_26 [ 3 ] = 0x1D ;
V_26 [ 0 ] = 0x72 ;
V_27 [ 0 ] = 0x09 ;
V_26 [ 7 ] = 14 ;
V_27 [ 1 ] = 12 ;
V_27 [ 2 ] = 0x00 ;
V_27 [ 3 ] = V_25 [ 1 ] ;
V_27 [ 5 ] = V_25 [ 2 ] ;
V_27 [ 7 ] = V_25 [ 3 ] ;
V_27 [ 9 ] = V_25 [ 4 ] ;
V_27 [ 11 ] = V_25 [ 5 ] ;
V_27 [ 12 ] = V_25 [ 6 ] ;
V_27 [ 13 ] = V_25 [ 7 ] ;
V_2 -> V_16 = ( V_32 << 24 ) | V_17 ;
}
goto V_20;
V_10:
V_2 -> V_16 = ( V_32 << 24 ) | V_17 ;
memcpy ( V_2 -> V_18 ,
V_19 ,
sizeof( V_19 ) ) ;
V_20:
memcpy ( V_2 -> V_7 , V_5 , sizeof( V_5 ) ) ;
if ( V_2 -> V_7 [ 0 ] == V_9 )
V_2 -> V_11 = 12 ;
}
static int F_7 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_3 * V_4 ;
int V_16 ;
struct V_37 * V_38 ;
V_16 = F_8 ( & V_4 , V_34 , V_36 ,
( V_36 - V_39 ) + V_40 ) ;
if ( V_16 )
return V_16 ;
V_38 = F_9 ( V_34 ) ;
if ( V_38 -> V_41 . V_42 != 0x38 ||
V_38 -> V_41 . V_43 != 0x4e ||
V_38 -> V_41 . V_44 != 0x64 ) {
V_4 -> V_45 = L_2 ;
V_4 -> V_46 = F_1 ;
} else {
V_4 -> V_45 = L_3 ;
V_4 -> V_46 = F_3 ;
}
V_16 = F_10 ( V_4 ) ;
return V_16 ;
}
