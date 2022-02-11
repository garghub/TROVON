static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 = 0 , V_7 , V_8 ;
T_1 V_9 [ V_10 ] ;
struct V_11 V_12 [ 1 ] = {
{
. V_13 = V_2 -> V_14 -> V_15 ,
. V_16 = 0 ,
. V_9 = V_9 ,
}
} ;
if ( 1 + V_5 > sizeof( V_9 ) ) {
F_2 ( & V_2 -> V_17 -> V_18 ,
L_1 ,
V_19 , V_3 , V_5 ) ;
return - V_20 ;
}
for ( V_8 = V_5 ; V_8 > 0 ;
V_8 -= ( V_2 -> V_14 -> V_21 - 1 ) ) {
V_7 = V_8 ;
if ( V_7 > ( V_2 -> V_14 -> V_21 - 1 ) )
V_7 = ( V_2 -> V_14 -> V_21 - 1 ) ;
V_12 [ 0 ] . V_5 = 1 + V_7 ;
V_9 [ 0 ] = V_3 + V_5 - V_8 ;
memcpy ( & V_9 [ 1 ] , & V_4 [ V_5 - V_8 ] , V_7 ) ;
V_6 = F_3 ( V_2 -> V_17 , V_12 , 1 ) ;
if ( V_6 != 1 )
break;
}
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_17 -> V_18 , L_2 \
L_3 , V_19 , V_6 , V_3 , V_5 ) ;
V_6 = - V_22 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
T_1 V_9 [ V_10 ] ;
struct V_11 V_12 [ 2 ] = {
{
. V_13 = V_2 -> V_14 -> V_15 ,
. V_16 = 0 ,
. V_5 = 1 ,
. V_9 = L_4 ,
} , {
. V_13 = V_2 -> V_14 -> V_15 ,
. V_16 = V_23 ,
. V_5 = V_3 + V_5 ,
. V_9 = V_9 ,
}
} ;
if ( V_3 + V_5 > sizeof( V_9 ) ) {
F_2 ( & V_2 -> V_17 -> V_18 ,
L_1 ,
V_19 , V_3 , V_5 ) ;
return - V_20 ;
}
V_6 = F_3 ( V_2 -> V_17 , V_12 , 2 ) ;
if ( V_6 == 2 ) {
memcpy ( V_4 , & V_9 [ V_3 ] , V_5 ) ;
V_6 = 0 ;
} else {
F_2 ( & V_2 -> V_17 -> V_18 , L_5 \
L_3 , V_19 , V_6 , V_3 , V_5 ) ;
V_6 = - V_22 ;
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
static int F_7 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
struct V_27 * V_28 = & V_25 -> V_29 ;
T_2 V_30 = V_28 -> V_31 ;
int V_6 ;
T_1 V_9 [ 3 ] , V_32 , V_33 , V_34 ;
T_2 V_35 ;
T_1 V_36 [] [ 2 ] = {
{ V_37 , 0x60 } ,
{ V_38 , 0x02 } ,
{ V_37 , 0xa0 } ,
{ V_38 , 0x09 } ,
{ V_37 , 0xe0 } ,
{ V_38 , 0x0c } ,
{ V_37 , 0x40 } ,
{ V_38 , 0x01 } ,
{ V_37 , 0x80 } ,
{ V_38 , 0x08 } ,
{ V_37 , 0xc0 } ,
{ V_38 , 0x0b } ,
{ V_39 , 0x1c } ,
{ V_39 , 0x0c } ,
} ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 1 ) ;
if ( V_30 <= 6000000 ) {
V_34 = 0 ;
V_2 -> V_42 = 3000000 ;
} else if ( V_30 <= 7000000 ) {
V_34 = 1 ;
V_2 -> V_42 = 3500000 ;
} else {
V_34 = 2 ;
V_2 -> V_42 = 4000000 ;
}
V_35 = V_28 -> V_43 + V_2 -> V_42 ;
if ( V_35 < 188000000 )
V_33 = 3 ;
else if ( V_35 < 253000000 )
V_33 = 4 ;
else if ( V_35 < 343000000 )
V_33 = 5 ;
else
V_33 = 6 ;
V_9 [ 0 ] = ( V_2 -> V_44 [ V_45 ] & ~ 7 ) | V_33 ;
V_9 [ 1 ] = ( V_2 -> V_44 [ V_46 ] & ~ 3 ) | V_34 ;
V_9 [ 2 ] = V_2 -> V_44 [ V_47 ] ;
V_6 = F_1 ( V_2 , V_45 , V_9 , 3 ) ;
if ( V_6 )
goto error;
V_9 [ 0 ] = ( V_35 / 1000 ) >> 12 ;
V_9 [ 1 ] = ( V_35 / 1000 ) >> 4 ;
V_9 [ 2 ] = ( V_35 / 1000 ) << 4 |
( V_2 -> V_44 [ V_48 ] & 0x0f ) ;
V_6 = F_1 ( V_2 , V_49 , V_9 , 3 ) ;
if ( V_6 )
goto error;
V_9 [ 0 ] = V_2 -> V_44 [ V_50 ] | ( 1 << 6 ) ;
V_6 = F_1 ( V_2 , V_50 , V_9 , 1 ) ;
if ( V_6 )
goto error;
V_9 [ 0 ] = V_2 -> V_44 [ V_50 ] & ~ ( 1 << 6 ) ;
V_6 = F_1 ( V_2 , V_50 , V_9 , 1 ) ;
if ( V_6 )
goto error;
for ( V_32 = 0 ; V_32 < F_8 ( V_36 ) ; V_32 ++ ) {
V_6 = F_5 ( V_2 , V_36 [ V_32 ] [ 0 ] , V_36 [ V_32 ] [ 1 ] ) ;
if ( V_6 )
goto error;
}
error:
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 0 ) ;
if ( V_6 )
F_9 ( & V_2 -> V_17 -> V_18 , L_6 , V_51 , V_6 ) ;
return V_6 ;
}
static int F_10 ( struct V_24 * V_25 , T_2 * V_43 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
* V_43 = V_2 -> V_42 ;
F_9 ( & V_2 -> V_17 -> V_18 , L_7 , V_51 , * V_43 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 1 ) ;
V_6 = F_5 ( V_2 , V_52 , V_2 -> V_44 [ V_52 ] | ( 1 << 0 ) ) ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 0 ) ;
if ( V_6 )
F_9 ( & V_2 -> V_17 -> V_18 , L_6 , V_51 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_6 ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 1 ) ;
V_6 = F_1 ( V_2 , V_53 , V_2 -> V_44 , V_54 ) ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 0 ) ;
if ( V_6 )
F_9 ( & V_2 -> V_17 -> V_18 , L_6 , V_51 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_24 * V_25 )
{
F_14 ( V_25 -> V_26 ) ;
V_25 -> V_26 = NULL ;
return 0 ;
}
struct V_24 * F_15 ( struct V_24 * V_25 ,
struct V_55 * V_17 , struct V_56 * V_14 )
{
struct V_1 * V_2 = NULL ;
T_1 V_4 ;
int V_6 ;
static T_1 V_57 [] = {
0xc0 , 0x88 , 0x00 , 0x8e , 0x03 , 0x00 , 0x00 , 0xd0 , 0x00 , 0x40 ,
0x00 , 0x00 , 0x07 , 0xff , 0x84 , 0x09 , 0x00 , 0x13 , 0x00 , 0x00 ,
0x01 , 0x84 , 0x09 , 0xf0 , 0x19 , 0x0a , 0x8e , 0x69 , 0x98 , 0x01 ,
0x00 , 0x58 , 0x10 , 0x40 , 0x8c , 0x00 , 0x0c , 0x48 , 0x85 , 0xc9 ,
0xa7 , 0x00 , 0x00 , 0x00 , 0x30 , 0x81 , 0x80 , 0x00 , 0x39 , 0x00 ,
0x8a , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xf6 , 0xf6
} ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_58 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_14 = V_14 ;
V_2 -> V_17 = V_17 ;
V_25 -> V_26 = V_2 ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 1 ) ;
V_6 = F_6 ( V_2 , V_53 , & V_4 ) ;
if ( ! V_6 )
F_9 ( & V_2 -> V_17 -> V_18 , L_8 , V_51 , V_4 ) ;
if ( V_6 || V_4 != V_57 [ V_53 ] ) {
F_14 ( V_2 ) ;
return NULL ;
}
F_17 ( & V_2 -> V_17 -> V_18 ,
L_9 ,
V_19 ) ;
memcpy ( & V_25 -> V_40 . V_59 , & V_60 ,
sizeof( struct V_61 ) ) ;
memcpy ( V_2 -> V_44 , V_57 , sizeof( V_57 ) ) ;
if ( V_2 -> V_14 -> V_62 ) {
V_2 -> V_44 [ V_52 ] = 0xb0 ;
V_2 -> V_44 [ V_63 ] = 0x59 ;
}
V_6 = F_5 ( V_2 , V_52 , V_2 -> V_44 [ V_52 ] | ( 1 << 0 ) ) ;
if ( V_6 )
F_9 ( & V_2 -> V_17 -> V_18 , L_6 , V_51 , V_6 ) ;
if ( V_25 -> V_40 . V_41 )
V_25 -> V_40 . V_41 ( V_25 , 0 ) ;
return V_25 ;
}
