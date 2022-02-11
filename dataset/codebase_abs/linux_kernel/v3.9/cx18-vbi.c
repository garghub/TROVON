static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
int line = 0 ;
int V_5 ;
T_1 V_6 [ 2 ] = { 0 , 0 } ;
unsigned short V_7 ;
static const T_2 V_8 [] = {
0x00 , 0x00 , 0x01 , 0xba ,
0x44 , 0x00 , 0x0c , 0x66 , 0x24 , 0x01 ,
0x01 , 0xd1 , 0xd3 ,
0xfa , 0xff , 0xff ,
0x00 , 0x00 , 0x01 , 0xbd ,
0x00 , 0x1a ,
0x84 , 0x80 , 0x07 ,
0x21 , 0x00 , 0x5d , 0x63 , 0xa7 ,
0xff , 0xff
} ;
const int V_9 = sizeof( V_8 ) ;
int V_10 = V_2 -> V_11 . V_12 % V_13 ;
T_2 * V_14 = & V_2 -> V_11 . V_15 [ V_10 ] [ 0 ] ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
struct V_16 * V_17 = V_2 -> V_11 . V_18 + V_5 ;
int V_19 , V_20 ;
if ( V_17 -> V_21 == 0 )
continue;
V_20 = V_17 -> line - 6 ;
V_19 = V_17 -> V_22 ;
if ( V_19 )
V_20 += 18 ;
if ( V_20 < 32 )
V_6 [ 0 ] |= ( 1 << V_20 ) ;
else
V_6 [ 1 ] |= ( 1 << ( V_20 - 32 ) ) ;
V_14 [ V_9 + 12 + line * 43 ] = F_2 ( V_17 -> V_21 ) ;
memcpy ( V_14 + V_9 + 12 + line * 43 + 1 , V_17 -> V_23 , 42 ) ;
line ++ ;
}
memcpy ( V_14 , V_8 , sizeof( V_8 ) ) ;
if ( line == 36 ) {
memcpy ( V_14 + V_9 , L_1 , 4 ) ;
memmove ( V_14 + V_9 + 4 , V_14 + V_9 + 12 , line * 43 ) ;
V_7 = 4 + ( ( 43 * line + 3 ) & ~ 3 ) ;
} else {
memcpy ( V_14 + V_9 , L_2 , 4 ) ;
F_3 ( & V_6 [ 0 ] ) ;
F_3 ( & V_6 [ 1 ] ) ;
memcpy ( V_14 + V_9 + 4 , & V_6 [ 0 ] , 8 ) ;
V_7 = 12 + ( ( 43 * line + 3 ) & ~ 3 ) ;
}
V_14 [ 4 + 16 ] = ( V_7 + 10 ) >> 8 ;
V_14 [ 5 + 16 ] = ( V_7 + 10 ) & 0xff ;
V_14 [ 9 + 16 ] = 0x21 | ( ( V_4 >> 29 ) & 0x6 ) ;
V_14 [ 10 + 16 ] = ( V_4 >> 22 ) & 0xff ;
V_14 [ 11 + 16 ] = 1 | ( ( V_4 >> 14 ) & 0xff ) ;
V_14 [ 12 + 16 ] = ( V_4 >> 7 ) & 0xff ;
V_14 [ 13 + 16 ] = 1 | ( ( V_4 & 0x7f ) << 1 ) ;
V_2 -> V_11 . V_24 [ V_10 ] = V_9 + V_7 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_2 * V_25 , T_1 V_7 , T_1 V_26 )
{
T_1 V_27 = V_28 ;
T_1 V_3 = V_2 -> V_11 . V_29 * 2 ;
T_2 * V_30 = V_25 ;
T_2 * V_31 ;
int V_5 ;
V_25 += V_26 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
V_31 = V_25 + V_5 * V_27 ;
if ( V_31 [ 0 ] != 0xff || V_31 [ 1 ] || V_31 [ 2 ] ||
( V_31 [ 3 ] != V_32 [ 0 ] &&
V_31 [ 3 ] != V_32 [ 1 ] ) )
break;
if ( V_5 == V_3 - 1 ) {
memcpy ( V_30 , V_31 + 4 , V_27 - 4 - V_26 ) ;
V_30 += V_27 - 4 - V_26 ;
V_31 += V_27 - V_26 - 1 ;
memset ( V_30 , ( int ) * V_31 , V_26 ) ;
} else {
memcpy ( V_30 , V_31 + 4 , V_27 - 4 ) ;
V_30 += V_27 - 4 ;
}
}
return V_3 * ( V_27 - 4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_2 * V_25 , T_1 V_7 ,
const T_1 V_26 )
{
struct V_33 V_11 ;
int V_5 ;
T_1 line = 0 ;
T_1 V_27 = V_2 -> V_34 ? V_35
: V_36 ;
for ( V_5 = V_26 , V_25 += V_26 ; V_5 < V_7 ; V_5 ++ , V_25 ++ ) {
if ( V_25 [ 0 ] == 0xff && ! V_25 [ 1 ] && ! V_25 [ 2 ] &&
( V_25 [ 3 ] == V_37 [ 0 ] ||
V_25 [ 3 ] == V_37 [ 1 ] ) )
break;
}
V_7 -= ( V_5 - V_26 ) ;
if ( V_7 < V_27 )
return line ;
for ( V_5 = 0 ; V_5 < V_7 / V_27 ; V_5 ++ ) {
T_2 * V_31 = V_25 + V_5 * V_27 ;
if ( V_31 [ 0 ] != 0xff || V_31 [ 1 ] || V_31 [ 2 ] ||
( V_31 [ 3 ] != V_37 [ 0 ] &&
V_31 [ 3 ] != V_37 [ 1 ] ) )
continue;
V_11 . V_31 = V_31 + 4 ;
F_6 ( V_2 -> V_38 , V_11 , V_39 , & V_11 ) ;
if ( V_11 . type ) {
V_2 -> V_11 . V_18 [ line ] . V_21 = V_11 . type ;
V_2 -> V_11 . V_18 [ line ] . V_22 = V_11 . V_40 ;
V_2 -> V_11 . V_18 [ line ] . line = V_11 . line ;
memcpy ( V_2 -> V_11 . V_18 [ line ] . V_23 , V_11 . V_31 , 42 ) ;
line ++ ;
}
}
return line ;
}
static void F_7 ( struct V_1 * V_2 , struct V_41 * V_25 )
{
struct V_42 {
T_3 V_43 ;
T_3 V_44 ;
T_3 V_45 ;
} * V_46 = (struct V_42 * ) V_25 -> V_25 ;
T_2 * V_31 = ( T_2 * ) V_25 -> V_25 ;
T_1 V_7 = V_25 -> V_47 ;
T_1 V_45 ;
int V_3 ;
F_8 ( V_25 ) ;
if ( F_9 ( V_2 ) ) {
V_7 = V_25 -> V_47 =
F_4 ( V_2 , V_31 , V_7 , sizeof( struct V_42 ) ) ;
V_31 += V_7 - 4 ;
memcpy ( V_31 , & V_2 -> V_11 . V_12 , 4 ) ;
V_2 -> V_11 . V_12 ++ ;
return;
}
V_45 = ( F_10 ( V_46 -> V_43 ) == 0x3fffffff ) ? F_10 ( V_46 -> V_45 )
: 0 ;
V_3 = F_5 ( V_2 , V_31 , V_7 , sizeof( struct V_42 ) ) ;
if ( V_3 == 0 ) {
V_2 -> V_11 . V_18 [ 0 ] . V_21 = 0 ;
V_2 -> V_11 . V_18 [ 0 ] . line = 0 ;
V_2 -> V_11 . V_18 [ 0 ] . V_22 = 0 ;
V_3 = 1 ;
}
V_25 -> V_47 = V_7 = V_3 * sizeof( V_2 -> V_11 . V_18 [ 0 ] ) ;
memcpy ( V_31 , & V_2 -> V_11 . V_18 [ 0 ] , V_7 ) ;
if ( V_2 -> V_11 . V_48 )
F_1 ( V_2 , V_3 , V_45 ) ;
V_2 -> V_11 . V_12 ++ ;
}
void F_11 ( struct V_1 * V_2 , struct V_49 * V_50 ,
int V_51 )
{
struct V_41 * V_25 ;
T_1 V_52 ;
if ( V_51 != V_53 )
return;
F_12 (buf, &mdl->buf_list, list) {
V_52 = V_25 -> V_47 ;
if ( V_52 == 0 )
break;
F_7 ( V_2 , V_25 ) ;
V_50 -> V_47 -= ( V_52 - V_25 -> V_47 ) ;
}
}
