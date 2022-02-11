static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_4 V_5 [ 1 ] = {
{ . V_6 = V_2 -> V_7 -> V_8 , . V_9 = V_10 ,
. V_11 = & V_3 , . V_12 = sizeof( V_3 ) } ,
} ;
if ( F_2 ( V_2 -> V_13 , V_5 , 1 ) != 1 ) {
F_3 ( V_14 L_1 ,
V_15 , V_2 -> V_7 -> V_8 ) ;
return - V_16 ;
}
F_4 ( L_2 , V_3 ,
( V_3 & V_17 ) ? 1 : 0 ) ;
if ( V_3 & V_18 )
F_5 ( L_3
L_4 , V_15 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_11 [] , T_1 V_19 )
{
struct V_4 V_5 [ 1 ] = {
{ . V_6 = V_2 -> V_7 -> V_8 , . V_9 = 0 ,
. V_11 = V_11 , . V_12 = V_19 } ,
} ;
T_1 V_20 = 0 ;
int V_21 ;
if ( V_22 & 0x02 ) {
if ( ( V_11 [ 0 ] & 0x80 ) == 0x00 )
V_20 = 2 ;
else if ( ( V_11 [ 0 ] & 0xc0 ) == 0x80 )
V_20 = 4 ;
else if ( ( V_11 [ 0 ] & 0xf0 ) == 0xc0 )
V_20 = 6 ;
else if ( ( V_11 [ 0 ] & 0xf0 ) == 0xd0 )
V_20 = 8 ;
else if ( ( V_11 [ 0 ] & 0xf0 ) == 0xe0 )
V_20 = 10 ;
else if ( ( V_11 [ 0 ] & 0xf0 ) == 0xf0 )
V_20 = 12 ;
F_4 ( L_5 , V_20 ) ;
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_19 ; V_23 ++ )
F_3 ( V_24 L_6 , V_11 [ V_23 ] ) ;
F_3 ( V_24 L_7 ) ;
}
}
V_21 = F_2 ( V_2 -> V_13 , V_5 , 1 ) ;
if ( V_21 != 1 ) {
F_3 ( V_14 L_8 , V_15 , V_21 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
V_26 -> V_27 = NULL ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
T_1 V_11 [] = { 0xf0 , 0x80 } ;
int V_21 ;
F_5 ( L_9 , V_15 ) ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 1 ) ;
V_21 = F_6 ( V_2 , V_11 , sizeof( V_11 ) ) ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 0 ) ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_30 )
{
T_1 V_11 [ 2 ] ;
T_2 div , V_31 ;
div = ( V_30 + V_32 / 2 ) / V_32 ;
V_2 -> V_30 = div * V_32 ;
V_31 = V_30 - V_2 -> V_30 ;
V_11 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_11 [ 1 ] = ( div >> 0 ) & 0xff ;
F_5 ( L_10 , V_15 ,
V_30 , V_2 -> V_30 , V_31 , div ) ;
return F_6 ( V_2 , V_11 , sizeof( V_11 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_33 )
{
T_1 V_34 , V_35 ;
int V_21 ;
T_1 V_36 [] = {
0xc0 , 0x00 ,
} ;
T_1 V_37 [] = {
0xf0 , 0x00 ,
} ;
T_1 V_38 [] = { 0xc8 } ;
if ( V_33 > 35000 )
V_33 = 35000 ;
if ( V_33 < 8000 )
V_33 = 8000 ;
#define F_12 (_XTAL/575)
if ( V_33 <= 28820 ) {
V_34 = F_12 ;
} else {
V_34 = ( ( V_39 * 21 * 1000 ) / ( V_33 * 419 ) ) ;
}
if ( V_34 < 4 )
V_34 = 4 ;
if ( V_34 > F_12 )
V_34 = F_12 ;
V_35 = ( V_33 * V_34 * 1257 ) / ( V_39 * 1000 ) - 1 ;
if ( V_35 > 62 )
V_35 = 62 ;
V_36 [ 1 ] = ( V_35 << 1 ) & 0x7e ;
V_37 [ 1 ] = ( V_34 << 2 ) & 0x7c ;
F_5 ( L_11 , V_15 , V_33 , V_34 , V_35 ) ;
if ( V_34 != V_2 -> V_34 ) {
V_21 = F_6 ( V_2 , V_37 , sizeof( V_37 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_35 != V_2 -> V_35 ) {
V_21 = F_6 ( V_2 , V_36 , sizeof( V_36 ) ) ;
if ( V_21 < 0 )
return V_21 ;
F_13 ( 1 ) ;
V_21 = F_6 ( V_2 , V_38 ,
sizeof( V_38 ) ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_2 -> V_34 = V_34 ;
V_2 -> V_35 = V_35 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_40 )
{
T_1 V_11 [ 2 ] ;
T_1 V_41 , V_42 , V_43 ;
V_41 = 0 ;
V_42 = 1 ;
V_43 = 1 ;
V_11 [ 0 ] = 0x80 | ( ( V_41 << 5 ) & 0x20 )
| ( ( V_42 << 3 ) & 0x18 ) | ( ( V_43 << 1 ) & 0x06 ) ;
if ( ! V_2 -> V_7 -> V_44 )
V_11 [ 0 ] |= 0x01 ;
V_11 [ 1 ] = V_45 | ( ( V_40 << 5 ) & 0x60 ) ;
F_5 ( L_12 , V_15 , V_40 , V_41 , V_42 , V_43 ) ;
return F_6 ( V_2 , V_11 , sizeof( V_11 ) ) ;
}
static int F_15 ( struct V_25 * V_26 )
{
struct V_46 * V_47 = & V_26 -> V_48 ;
struct V_1 * V_2 = V_26 -> V_27 ;
int V_21 = 0 ;
T_2 V_30 = V_47 -> V_30 ;
T_2 V_33 ;
int V_23 ;
T_1 V_40 ;
if ( ( V_30 < V_26 -> V_28 . V_49 . V_50 )
|| ( V_30 > V_26 -> V_28 . V_49 . V_51 ) )
return - V_52 ;
V_33 = ( 27 * V_47 -> V_53 ) / 32 ;
V_33 /= 1000 ;
V_33 += 3000 ;
if ( V_30 < 950000 )
return - V_52 ;
else if ( V_30 < 1250000 )
V_40 = 0 ;
else if ( V_30 < 1750000 )
V_40 = 1 ;
else if ( V_30 < 2175000 )
V_40 = 2 ;
else
return - V_52 ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 1 ) ;
V_21 = F_14 ( V_2 , V_40 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_10 ( V_2 , V_47 -> V_30 ) ;
if ( V_21 < 0 )
goto error;
V_21 = F_11 ( V_2 , V_33 ) ;
if ( V_21 < 0 )
goto error;
for ( V_23 = 0 ; V_23 < 20 ; V_23 ++ ) {
V_21 = F_1 ( V_2 ) ;
if ( V_21 < 0 )
goto error;
if ( V_21 & V_17 )
break;
F_13 ( 10 ) ;
}
error:
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 0 ) ;
return V_21 ;
}
static int F_16 ( struct V_25 * V_26 , T_2 * V_30 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
* V_30 = V_2 -> V_30 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_21 ;
int V_23 ;
T_1 V_54 [] [ 2 ] = {
{ 0x04 , 0x00 } ,
{ 0x8b , V_45 } ,
{ 0xc0 , 0x20 } ,
{ 0xd3 , 0x40 } ,
{ 0xe3 , 0x5b } ,
{ 0xf0 , 0x28 } ,
{ 0xe3 , 0xf9 } ,
} ;
V_2 -> V_34 = 0xff ;
V_2 -> V_35 = 0xff ;
if ( ! V_2 -> V_7 -> V_44 )
V_54 [ 1 ] [ 0 ] |= 0x01 ;
F_5 ( L_9 , V_15 ) ;
for ( V_23 = 0 ; V_23 < F_18 ( V_54 ) ; V_23 ++ ) {
V_21 = F_6 ( V_2 , V_54 [ V_23 ] , 2 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_27 ;
int V_21 = 0 ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 1 ) ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_17 ( V_2 ) ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 0 ) ;
return V_21 ;
}
struct V_25 * F_20 ( struct V_25 * V_26 ,
const struct V_55 * V_7 ,
struct V_56 * V_13 )
{
struct V_1 * V_2 ;
int V_21 ;
if ( ! V_7 ) {
F_3 ( V_14 L_13 , V_15 ) ;
return NULL ;
}
V_2 = F_21 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_13 = V_13 ;
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 1 ) ;
V_21 = F_1 ( V_2 ) ;
if ( V_21 < 0 ) {
F_3 ( V_14 L_14 , V_15 ) ;
goto error;
}
V_21 = F_17 ( V_2 ) ;
if ( V_21 < 0 ) {
F_3 ( V_14 L_15 ,
V_15 ) ;
goto error;
}
if ( V_26 -> V_28 . V_29 )
V_26 -> V_28 . V_29 ( V_26 , 0 ) ;
V_26 -> V_27 = V_2 ;
memcpy ( & V_26 -> V_28 . V_58 , & V_59 ,
sizeof( struct V_60 ) ) ;
F_3 ( V_61 L_16 ,
V_15 , V_26 -> V_28 . V_58 . V_49 . V_62 , V_7 -> V_8 ) ;
return V_26 ;
error:
F_8 ( V_2 ) ;
return NULL ;
}
