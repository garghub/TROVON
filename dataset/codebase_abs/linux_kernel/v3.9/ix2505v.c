static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 ;
T_1 V_6 [] = { 0 } ;
int V_7 ;
struct V_8 V_9 [ 1 ] = {
{ . V_3 = V_3 , . V_10 = V_11 , . V_12 = V_6 , . V_13 = 1 }
} ;
V_7 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
F_3 ( L_1 , V_15 ) ;
return ( V_7 == 1 ) ? ( int ) V_6 [ 0 ] : - 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_12 [] , T_1 V_16 )
{
struct V_8 V_9 [ 1 ] = {
{ . V_3 = V_2 -> V_4 -> V_5 , . V_10 = 0 ,
. V_12 = V_12 , . V_13 = V_16 } ,
} ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_7 != 1 ) {
F_3 ( L_2 , V_15 , V_7 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
V_19 -> V_20 = NULL ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = & V_19 -> V_23 ;
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_24 = V_22 -> V_24 ;
T_2 V_25 = ( V_22 -> V_26 * 27 ) / 32000 ;
T_2 V_27 , V_28 , V_29 , V_30 ;
int V_7 = 0 , V_13 ;
T_1 V_31 , V_32 , V_33 , V_34 , V_35 , V_36 ;
T_1 V_37 [ 4 ] = { 0 } ;
if ( ( V_24 < V_19 -> V_38 . V_39 . V_40 )
|| ( V_24 > V_19 -> V_38 . V_39 . V_41 ) )
return - V_42 ;
if ( V_2 -> V_4 -> V_43 )
V_31 = ( V_2 -> V_4 -> V_43 < 4 )
? V_2 -> V_4 -> V_43 : 0 ;
else
V_31 = 0x0 ;
if ( V_2 -> V_4 -> V_44 )
V_32 = V_2 -> V_4 -> V_44 ;
else
V_32 = 0x3 ;
V_33 = 8 ;
V_34 = 32 ;
V_27 = ( V_24 * V_33 ) / 40 ;
V_30 = V_27 / V_34 ;
V_28 = V_30 / 100 ;
V_29 = ( ( V_30 - ( V_28 * 100 ) ) * V_34 ) / 100 ;
V_37 [ 0 ] = ( ( V_31 & 0x3 ) << 5 ) | ( V_28 >> 3 ) ;
V_37 [ 1 ] = ( V_28 << 5 ) | ( V_29 & 0x1f ) ;
V_37 [ 2 ] = 0x81 | ( ( V_32 & 0x3 ) << 5 ) ;
F_8 ( L_3 , V_24 , V_30 , V_28 , V_29 ) ;
if ( V_24 <= 1065000 )
V_35 = ( 6 << 5 ) | 2 ;
else if ( V_24 <= 1170000 )
V_35 = ( 7 << 5 ) | 2 ;
else if ( V_24 <= 1300000 )
V_35 = ( 1 << 5 ) ;
else if ( V_24 <= 1445000 )
V_35 = ( 2 << 5 ) ;
else if ( V_24 <= 1607000 )
V_35 = ( 3 << 5 ) ;
else if ( V_24 <= 1778000 )
V_35 = ( 4 << 5 ) ;
else if ( V_24 <= 1942000 )
V_35 = ( 5 << 5 ) ;
else
V_35 = ( 6 << 5 ) ;
V_37 [ 3 ] = V_35 ;
if ( V_25 <= 10000 )
V_36 = 0xc ;
else if ( V_25 <= 12000 )
V_36 = 0x2 ;
else if ( V_25 <= 14000 )
V_36 = 0xa ;
else if ( V_25 <= 16000 )
V_36 = 0x6 ;
else if ( V_25 <= 18000 )
V_36 = 0xe ;
else if ( V_25 <= 20000 )
V_36 = 0x1 ;
else if ( V_25 <= 22000 )
V_36 = 0x9 ;
else if ( V_25 <= 24000 )
V_36 = 0x5 ;
else if ( V_25 <= 26000 )
V_36 = 0xd ;
else if ( V_25 <= 28000 )
V_36 = 0x3 ;
else
V_36 = 0xb ;
F_8 ( L_4 , V_35 , V_25 , V_36 ) ;
F_8 ( L_5 , V_37 ) ;
if ( V_19 -> V_38 . V_45 )
V_19 -> V_38 . V_45 ( V_19 , 1 ) ;
V_13 = sizeof( V_37 ) ;
V_7 |= F_4 ( V_2 , V_37 , V_13 ) ;
V_37 [ 2 ] |= 0x4 ;
if ( V_19 -> V_38 . V_45 )
V_19 -> V_38 . V_45 ( V_19 , 1 ) ;
V_13 = 1 ;
V_7 |= F_4 ( V_2 , & V_37 [ 2 ] , V_13 ) ;
F_9 ( 10 ) ;
V_37 [ 2 ] |= ( ( V_36 >> 2 ) & 0x3 ) << 3 ;
V_37 [ 3 ] |= ( V_36 & 0x3 ) << 2 ;
F_8 ( L_6 , V_37 [ 2 ] , V_37 [ 3 ] ) ;
if ( V_19 -> V_38 . V_45 )
V_19 -> V_38 . V_45 ( V_19 , 1 ) ;
V_13 = 2 ;
V_7 |= F_4 ( V_2 , & V_37 [ 2 ] , V_13 ) ;
if ( V_2 -> V_4 -> V_46 )
F_9 ( V_2 -> V_4 -> V_46 ) ;
V_2 -> V_24 = V_24 ;
return V_7 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 * V_24 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
* V_24 = V_2 -> V_24 ;
return 0 ;
}
struct V_18 * F_11 ( struct V_18 * V_19 ,
const struct V_47 * V_4 ,
struct V_48 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_7 ;
if ( NULL == V_4 ) {
F_3 ( L_7 , V_15 ) ;
goto error;
}
V_2 = F_12 ( sizeof( struct V_1 ) , V_49 ) ;
if ( NULL == V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = V_14 ;
if ( V_2 -> V_4 -> V_50 ) {
if ( V_19 -> V_38 . V_45 )
V_19 -> V_38 . V_45 ( V_19 , 1 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 & 0x80 ) {
F_3 ( L_8 , V_15 ) ;
goto error;
}
if ( V_19 -> V_38 . V_45 )
V_19 -> V_38 . V_45 ( V_19 , 0 ) ;
}
V_19 -> V_20 = V_2 ;
memcpy ( & V_19 -> V_38 . V_51 , & V_52 ,
sizeof( struct V_53 ) ) ;
F_3 ( L_9 ,
V_15 , V_19 -> V_38 . V_51 . V_39 . V_54 , V_4 -> V_5 ) ;
return V_19 ;
error:
F_6 ( V_2 ) ;
return NULL ;
}
