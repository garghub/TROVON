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
static int F_7 ( struct V_18 * V_19 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
T_2 V_23 = V_22 -> V_23 ;
T_2 V_24 = ( V_22 -> V_25 . V_26 . V_27 * 27 ) / 32000 ;
T_2 V_28 , V_29 , V_30 , V_31 ;
int V_7 = 0 , V_13 ;
T_1 V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
T_1 V_38 [ 4 ] = { 0 } ;
if ( ( V_23 < V_19 -> V_39 . V_40 . V_41 )
|| ( V_23 > V_19 -> V_39 . V_40 . V_42 ) )
return - V_43 ;
if ( V_2 -> V_4 -> V_44 )
V_32 = ( V_2 -> V_4 -> V_44 < 4 )
? V_2 -> V_4 -> V_44 : 0 ;
else
V_32 = 0x0 ;
if ( V_2 -> V_4 -> V_45 )
V_33 = V_2 -> V_4 -> V_45 ;
else
V_33 = 0x3 ;
V_34 = 8 ;
V_35 = 32 ;
V_28 = ( V_23 * V_34 ) / 40 ;
V_31 = V_28 / V_35 ;
V_29 = V_31 / 100 ;
V_30 = ( ( V_31 - ( V_29 * 100 ) ) * V_35 ) / 100 ;
V_38 [ 0 ] = ( ( V_32 & 0x3 ) << 5 ) | ( V_29 >> 3 ) ;
V_38 [ 1 ] = ( V_29 << 5 ) | ( V_30 & 0x1f ) ;
V_38 [ 2 ] = 0x81 | ( ( V_33 & 0x3 ) << 5 ) ;
F_8 ( L_3 , V_23 , V_31 , V_29 , V_30 ) ;
if ( V_23 <= 1065000 )
V_36 = ( 6 << 5 ) | 2 ;
else if ( V_23 <= 1170000 )
V_36 = ( 7 << 5 ) | 2 ;
else if ( V_23 <= 1300000 )
V_36 = ( 1 << 5 ) ;
else if ( V_23 <= 1445000 )
V_36 = ( 2 << 5 ) ;
else if ( V_23 <= 1607000 )
V_36 = ( 3 << 5 ) ;
else if ( V_23 <= 1778000 )
V_36 = ( 4 << 5 ) ;
else if ( V_23 <= 1942000 )
V_36 = ( 5 << 5 ) ;
else
V_36 = ( 6 << 5 ) ;
V_38 [ 3 ] = V_36 ;
if ( V_24 <= 10000 )
V_37 = 0xc ;
else if ( V_24 <= 12000 )
V_37 = 0x2 ;
else if ( V_24 <= 14000 )
V_37 = 0xa ;
else if ( V_24 <= 16000 )
V_37 = 0x6 ;
else if ( V_24 <= 18000 )
V_37 = 0xe ;
else if ( V_24 <= 20000 )
V_37 = 0x1 ;
else if ( V_24 <= 22000 )
V_37 = 0x9 ;
else if ( V_24 <= 24000 )
V_37 = 0x5 ;
else if ( V_24 <= 26000 )
V_37 = 0xd ;
else if ( V_24 <= 28000 )
V_37 = 0x3 ;
else
V_37 = 0xb ;
F_8 ( L_4 , V_36 , V_24 , V_37 ) ;
F_8 ( L_5 , V_38 [ 0 ] , V_38 [ 1 ] , V_38 [ 2 ] , V_38 [ 3 ] ) ;
if ( V_19 -> V_39 . V_46 )
V_19 -> V_39 . V_46 ( V_19 , 1 ) ;
V_13 = sizeof( V_38 ) ;
V_7 |= F_4 ( V_2 , V_38 , V_13 ) ;
V_38 [ 2 ] |= 0x4 ;
if ( V_19 -> V_39 . V_46 )
V_19 -> V_39 . V_46 ( V_19 , 1 ) ;
V_13 = 1 ;
V_7 |= F_4 ( V_2 , & V_38 [ 2 ] , V_13 ) ;
F_9 ( 10 ) ;
V_38 [ 2 ] |= ( ( V_37 >> 2 ) & 0x3 ) << 3 ;
V_38 [ 3 ] |= ( V_37 & 0x3 ) << 2 ;
F_8 ( L_6 , V_38 [ 2 ] , V_38 [ 3 ] ) ;
if ( V_19 -> V_39 . V_46 )
V_19 -> V_39 . V_46 ( V_19 , 1 ) ;
V_13 = 2 ;
V_7 |= F_4 ( V_2 , & V_38 [ 2 ] , V_13 ) ;
if ( V_2 -> V_4 -> V_47 )
F_9 ( V_2 -> V_4 -> V_47 ) ;
V_2 -> V_23 = V_23 ;
return V_7 ;
}
static int F_10 ( struct V_18 * V_19 , T_2 * V_23 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
* V_23 = V_2 -> V_23 ;
return 0 ;
}
struct V_18 * F_11 ( struct V_18 * V_19 ,
const struct V_48 * V_4 ,
struct V_49 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_7 ;
if ( NULL == V_4 ) {
F_3 ( L_7 , V_15 ) ;
goto error;
}
V_2 = F_12 ( sizeof( struct V_1 ) , V_50 ) ;
if ( NULL == V_2 )
return NULL ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = V_14 ;
if ( V_2 -> V_4 -> V_51 ) {
if ( V_19 -> V_39 . V_46 )
V_19 -> V_39 . V_46 ( V_19 , 1 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 & 0x80 ) {
F_3 ( L_8 , V_15 ) ;
goto error;
}
if ( V_19 -> V_39 . V_46 )
V_19 -> V_39 . V_46 ( V_19 , 0 ) ;
}
V_19 -> V_20 = V_2 ;
memcpy ( & V_19 -> V_39 . V_52 , & V_53 ,
sizeof( struct V_54 ) ) ;
F_3 ( L_9 ,
V_15 , V_19 -> V_39 . V_52 . V_40 . V_55 , V_4 -> V_5 ) ;
return V_19 ;
error:
F_6 ( V_2 ) ;
return NULL ;
}
