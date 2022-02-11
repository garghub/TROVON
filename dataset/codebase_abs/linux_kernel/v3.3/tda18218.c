static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 = 0 ;
T_1 V_7 [ 1 + V_5 ] , V_8 , V_9 , V_10 , V_11 , V_12 ;
struct V_13 V_14 [ 1 ] = {
{
. V_15 = V_2 -> V_16 -> V_17 ,
. V_18 = 0 ,
. V_7 = V_7 ,
}
} ;
V_12 = V_2 -> V_16 -> V_19 - 1 ;
V_8 = V_5 / V_12 ;
V_9 = V_5 % V_12 ;
V_11 = V_12 ;
for ( V_10 = 0 ; ( V_10 <= V_8 && V_9 ) ; V_10 ++ ) {
if ( V_10 == V_8 )
V_11 = V_9 ;
V_14 [ 0 ] . V_5 = V_11 + 1 ;
V_7 [ 0 ] = V_3 + V_10 * V_12 ;
memcpy ( & V_7 [ 1 ] , & V_4 [ V_10 * V_12 ] , V_11 ) ;
V_6 = F_2 ( V_2 -> V_20 , V_14 , 1 ) ;
if ( V_6 != 1 )
break;
}
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( L_1 , V_6 , V_3 , V_5 ) ;
V_6 = - V_21 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_7 [ V_3 + V_5 ] ;
struct V_13 V_14 [ 2 ] = {
{
. V_15 = V_2 -> V_16 -> V_17 ,
. V_18 = 0 ,
. V_5 = 1 ,
. V_7 = L_2 ,
} , {
. V_15 = V_2 -> V_16 -> V_17 ,
. V_18 = V_22 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_6 = F_2 ( V_2 -> V_20 , V_14 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , & V_7 [ V_3 ] , V_5 ) ;
V_6 = 0 ;
} else {
F_3 ( L_3 , V_6 , V_3 , V_5 ) ;
V_6 = - V_21 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_26 * V_27 = & V_24 -> V_28 ;
T_2 V_29 = V_27 -> V_30 ;
int V_6 ;
T_1 V_7 [ 3 ] , V_10 , V_31 , V_32 ;
T_2 V_33 ;
T_1 V_34 [] [ 2 ] = {
{ V_35 , 0x60 } ,
{ V_36 , 0x02 } ,
{ V_35 , 0xa0 } ,
{ V_36 , 0x09 } ,
{ V_35 , 0xe0 } ,
{ V_36 , 0x0c } ,
{ V_35 , 0x40 } ,
{ V_36 , 0x01 } ,
{ V_35 , 0x80 } ,
{ V_36 , 0x08 } ,
{ V_35 , 0xc0 } ,
{ V_36 , 0x0b } ,
{ V_37 , 0x1c } ,
{ V_37 , 0x0c } ,
} ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 1 ) ;
if ( V_29 <= 6000000 ) {
V_32 = 0 ;
V_2 -> V_40 = 3000000 ;
} else if ( V_29 <= 7000000 ) {
V_32 = 1 ;
V_2 -> V_40 = 3500000 ;
} else {
V_32 = 2 ;
V_2 -> V_40 = 4000000 ;
}
V_33 = V_27 -> V_41 + V_2 -> V_40 ;
if ( V_33 < 188000000 )
V_31 = 3 ;
else if ( V_33 < 253000000 )
V_31 = 4 ;
else if ( V_33 < 343000000 )
V_31 = 5 ;
else
V_31 = 6 ;
V_7 [ 0 ] = ( V_2 -> V_42 [ V_43 ] & ~ 7 ) | V_31 ;
V_7 [ 1 ] = ( V_2 -> V_42 [ V_44 ] & ~ 3 ) | V_32 ;
V_7 [ 2 ] = V_2 -> V_42 [ V_45 ] ;
V_6 = F_1 ( V_2 , V_43 , V_7 , 3 ) ;
if ( V_6 )
goto error;
V_7 [ 0 ] = ( V_33 / 1000 ) >> 12 ;
V_7 [ 1 ] = ( V_33 / 1000 ) >> 4 ;
V_7 [ 2 ] = ( V_33 / 1000 ) << 4 |
( V_2 -> V_42 [ V_46 ] & 0x0f ) ;
V_6 = F_1 ( V_2 , V_47 , V_7 , 3 ) ;
if ( V_6 )
goto error;
V_7 [ 0 ] = V_2 -> V_42 [ V_48 ] | ( 1 << 6 ) ;
V_6 = F_1 ( V_2 , V_48 , V_7 , 1 ) ;
if ( V_6 )
goto error;
V_7 [ 0 ] = V_2 -> V_42 [ V_48 ] & ~ ( 1 << 6 ) ;
V_6 = F_1 ( V_2 , V_48 , V_7 , 1 ) ;
if ( V_6 )
goto error;
for ( V_10 = 0 ; V_10 < F_8 ( V_34 ) ; V_10 ++ ) {
V_6 = F_5 ( V_2 , V_34 [ V_10 ] [ 0 ] , V_34 [ V_10 ] [ 1 ] ) ;
if ( V_6 )
goto error;
}
error:
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 0 ) ;
if ( V_6 )
F_9 ( L_4 , V_49 , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_23 * V_24 , T_2 * V_41 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
* V_41 = V_2 -> V_40 ;
F_9 ( L_5 , V_49 , * V_41 ) ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
int V_6 ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 1 ) ;
V_6 = F_5 ( V_2 , V_50 , V_2 -> V_42 [ V_50 ] | ( 1 << 0 ) ) ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 0 ) ;
if ( V_6 )
F_9 ( L_4 , V_49 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
int V_6 ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 1 ) ;
V_6 = F_1 ( V_2 , V_51 , V_2 -> V_42 , V_52 ) ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 0 ) ;
if ( V_6 )
F_9 ( L_4 , V_49 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_23 * V_24 )
{
F_14 ( V_24 -> V_25 ) ;
V_24 -> V_25 = NULL ;
return 0 ;
}
struct V_23 * F_15 ( struct V_23 * V_24 ,
struct V_53 * V_20 , struct V_54 * V_16 )
{
struct V_1 * V_2 = NULL ;
T_1 V_4 ;
int V_6 ;
static T_1 V_55 [] = {
0xc0 , 0x88 , 0x00 , 0x8e , 0x03 , 0x00 , 0x00 , 0xd0 , 0x00 , 0x40 ,
0x00 , 0x00 , 0x07 , 0xff , 0x84 , 0x09 , 0x00 , 0x13 , 0x00 , 0x00 ,
0x01 , 0x84 , 0x09 , 0xf0 , 0x19 , 0x0a , 0x8e , 0x69 , 0x98 , 0x01 ,
0x00 , 0x58 , 0x10 , 0x40 , 0x8c , 0x00 , 0x0c , 0x48 , 0x85 , 0xc9 ,
0xa7 , 0x00 , 0x00 , 0x00 , 0x30 , 0x81 , 0x80 , 0x00 , 0x39 , 0x00 ,
0x8a , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xf6 , 0xf6
} ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_56 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_20 = V_20 ;
V_24 -> V_25 = V_2 ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 1 ) ;
V_6 = F_6 ( V_2 , V_51 , & V_4 ) ;
F_9 ( L_6 , V_49 , V_6 , V_4 ) ;
if ( V_6 || V_4 != V_55 [ V_51 ] ) {
F_14 ( V_2 ) ;
return NULL ;
}
F_17 ( L_7 ) ;
memcpy ( & V_24 -> V_38 . V_57 , & V_58 ,
sizeof( struct V_59 ) ) ;
memcpy ( V_2 -> V_42 , V_55 , sizeof( V_55 ) ) ;
if ( V_2 -> V_16 -> V_60 ) {
V_2 -> V_42 [ V_50 ] = 0xb0 ;
V_2 -> V_42 [ V_61 ] = 0x59 ;
}
V_6 = F_5 ( V_2 , V_50 , V_2 -> V_42 [ V_50 ] | ( 1 << 0 ) ) ;
if ( V_6 )
F_9 ( L_4 , V_49 , V_6 ) ;
if ( V_24 -> V_38 . V_39 )
V_24 -> V_38 . V_39 ( V_24 , 0 ) ;
return V_24 ;
}
