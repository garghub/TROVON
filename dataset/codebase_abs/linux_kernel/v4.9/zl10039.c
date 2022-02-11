static int F_1 ( const struct V_1 * V_2 ,
const enum V_3 V_4 , T_1 * V_5 ,
const T_2 V_6 )
{
T_1 V_7 [] = { V_4 } ;
struct V_8 V_9 [] = {
{
. V_10 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_5 = V_7 ,
. V_13 = 1 ,
} , {
. V_10 = V_2 -> V_11 ,
. V_12 = V_14 ,
. V_5 = V_5 ,
. V_13 = V_6 ,
} ,
} ;
F_2 ( L_1 , V_15 ) ;
if ( F_3 ( V_2 -> V_16 , V_9 , 2 ) != 2 ) {
F_2 ( L_2 , V_15 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const enum V_3 V_4 , const T_1 * V_18 ,
const T_2 V_6 )
{
T_1 V_5 [ V_19 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_5 = V_5 ,
. V_13 = V_6 + 1 ,
} ;
if ( 1 + V_6 > sizeof( V_5 ) ) {
F_5 ( V_20
L_3 ,
V_21 , V_4 , V_6 ) ;
return - V_22 ;
}
F_2 ( L_1 , V_15 ) ;
V_5 [ 0 ] = V_4 ;
memcpy ( & V_5 [ 1 ] , V_18 , V_6 ) ;
if ( F_3 ( V_2 -> V_16 , & V_9 , 1 ) != 1 ) {
F_2 ( L_4 , V_15 ) ;
return - V_17 ;
}
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 ,
const enum V_3 V_4 , T_1 * V_23 )
{
return F_1 ( V_2 , V_4 , V_23 , 1 ) ;
}
static inline int F_7 ( struct V_1 * V_2 ,
const enum V_3 V_4 ,
const T_1 V_23 )
{
return F_4 ( V_2 , V_4 , & V_23 , 1 ) ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
F_2 ( L_1 , V_15 ) ;
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 1 ) ;
V_27 = F_7 ( V_2 , V_30 , 0x40 ) ;
if ( V_27 < 0 ) {
F_2 ( L_5
L_6 ) ;
}
V_27 = F_7 ( V_2 , V_30 , 0x01 ) ;
if ( V_27 < 0 ) {
F_2 ( L_7 ) ;
return V_27 ;
}
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
int V_27 ;
F_2 ( L_1 , V_15 ) ;
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 1 ) ;
V_27 = F_7 ( V_2 , V_30 , 0x80 ) ;
if ( V_27 < 0 ) {
F_2 ( L_8 ) ;
return V_27 ;
}
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 0 ) ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 )
{
struct V_31 * V_32 = & V_25 -> V_33 ;
struct V_1 * V_2 = V_25 -> V_26 ;
T_1 V_5 [ 6 ] ;
T_1 V_34 ;
T_3 V_35 ;
T_3 div ;
int V_27 ;
F_2 ( L_1 , V_15 ) ;
F_2 ( L_9 ,
V_32 -> V_36 , V_32 -> V_37 ) ;
div = ( V_32 -> V_36 * 1000 ) / 126387 ;
V_35 = ( V_32 -> V_37 * 27 ) / 32000 ;
V_34 = ( ( V_35 * 5088 ) / 1011100 ) - 1 ;
V_5 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_5 [ 1 ] = ( div >> 0 ) & 0xff ;
V_5 [ 2 ] = 0x1D ;
V_5 [ 3 ] = 0x40 ;
V_5 [ 4 ] = 0x6E ;
V_5 [ 5 ] = V_34 ;
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 1 ) ;
V_27 = F_7 ( V_2 , V_38 , 0x0A ) ;
if ( V_27 < 0 )
goto error;
V_27 = F_4 ( V_2 , V_39 , V_5 , sizeof( V_5 ) ) ;
if ( V_27 < 0 )
goto error;
V_27 = F_7 ( V_2 , V_38 , 0x6A ) ;
if ( V_27 < 0 )
goto error;
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 0 ) ;
return 0 ;
error:
F_2 ( L_10 ) ;
return V_27 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_26 ;
F_2 ( L_1 , V_15 ) ;
F_12 ( V_2 ) ;
V_25 -> V_26 = NULL ;
return 0 ;
}
struct V_24 * F_13 ( struct V_24 * V_25 ,
T_1 V_11 , struct V_40 * V_16 )
{
struct V_1 * V_2 = NULL ;
F_2 ( L_1 , V_15 ) ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_41 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_16 = V_16 ;
V_2 -> V_11 = V_11 ;
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 1 ) ;
if ( F_6 ( V_2 , V_30 , & V_2 -> V_42 ) < 0 ) {
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 0 ) ;
goto error;
}
if ( V_25 -> V_28 . V_29 )
V_25 -> V_28 . V_29 ( V_25 , 0 ) ;
V_2 -> V_42 = V_2 -> V_42 & 0x0f ;
switch ( V_2 -> V_42 ) {
case V_43 :
strcpy ( V_25 -> V_28 . V_44 . V_45 . V_46 ,
L_11 ) ;
break;
default:
F_2 ( L_12 , V_2 -> V_42 ) ;
goto error;
}
memcpy ( & V_25 -> V_28 . V_44 , & V_47 , sizeof( struct V_48 ) ) ;
V_25 -> V_26 = V_2 ;
F_2 ( L_13 , V_11 ) ;
return V_25 ;
error:
F_12 ( V_2 ) ;
return NULL ;
}
