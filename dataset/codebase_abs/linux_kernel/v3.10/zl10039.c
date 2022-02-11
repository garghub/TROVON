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
T_1 V_5 [ V_6 + 1 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_5 = V_5 ,
. V_13 = V_6 + 1 ,
} ;
F_2 ( L_1 , V_15 ) ;
V_5 [ 0 ] = V_4 ;
memcpy ( & V_5 [ 1 ] , V_18 , V_6 ) ;
if ( F_3 ( V_2 -> V_16 , & V_9 , 1 ) != 1 ) {
F_2 ( L_3 , V_15 ) ;
return - V_17 ;
}
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
const enum V_3 V_4 , T_1 * V_19 )
{
return F_1 ( V_2 , V_4 , V_19 , 1 ) ;
}
static inline int F_6 ( struct V_1 * V_2 ,
const enum V_3 V_4 ,
const T_1 V_19 )
{
return F_4 ( V_2 , V_4 , & V_19 , 1 ) ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_23 ;
F_2 ( L_1 , V_15 ) ;
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 1 ) ;
V_23 = F_6 ( V_2 , V_26 , 0x40 ) ;
if ( V_23 < 0 ) {
F_2 ( L_4
L_5 ) ;
}
V_23 = F_6 ( V_2 , V_26 , 0x01 ) ;
if ( V_23 < 0 ) {
F_2 ( L_6 ) ;
return V_23 ;
}
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 0 ) ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
int V_23 ;
F_2 ( L_1 , V_15 ) ;
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 1 ) ;
V_23 = F_6 ( V_2 , V_26 , 0x80 ) ;
if ( V_23 < 0 ) {
F_2 ( L_7 ) ;
return V_23 ;
}
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_27 * V_28 = & V_21 -> V_29 ;
struct V_1 * V_2 = V_21 -> V_22 ;
T_1 V_5 [ 6 ] ;
T_1 V_30 ;
T_3 V_31 ;
T_3 div ;
int V_23 ;
F_2 ( L_1 , V_15 ) ;
F_2 ( L_8 ,
V_28 -> V_32 , V_28 -> V_33 ) ;
div = ( V_28 -> V_32 * 1000 ) / 126387 ;
V_31 = ( V_28 -> V_33 * 27 ) / 32000 ;
V_30 = ( ( V_31 * 5088 ) / 1011100 ) - 1 ;
V_5 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_5 [ 1 ] = ( div >> 0 ) & 0xff ;
V_5 [ 2 ] = 0x1D ;
V_5 [ 3 ] = 0x40 ;
V_5 [ 4 ] = 0x6E ;
V_5 [ 5 ] = V_30 ;
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 1 ) ;
V_23 = F_6 ( V_2 , V_34 , 0x0A ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_4 ( V_2 , V_35 , V_5 , sizeof( V_5 ) ) ;
if ( V_23 < 0 )
goto error;
V_23 = F_6 ( V_2 , V_34 , 0x6A ) ;
if ( V_23 < 0 )
goto error;
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 0 ) ;
return 0 ;
error:
F_2 ( L_9 ) ;
return V_23 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
F_2 ( L_1 , V_15 ) ;
F_11 ( V_2 ) ;
V_21 -> V_22 = NULL ;
return 0 ;
}
struct V_20 * F_12 ( struct V_20 * V_21 ,
T_1 V_11 , struct V_36 * V_16 )
{
struct V_1 * V_2 = NULL ;
F_2 ( L_1 , V_15 ) ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_37 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_16 = V_16 ;
V_2 -> V_11 = V_11 ;
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 1 ) ;
if ( F_5 ( V_2 , V_26 , & V_2 -> V_38 ) < 0 ) {
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 0 ) ;
goto error;
}
if ( V_21 -> V_24 . V_25 )
V_21 -> V_24 . V_25 ( V_21 , 0 ) ;
V_2 -> V_38 = V_2 -> V_38 & 0x0f ;
switch ( V_2 -> V_38 ) {
case V_39 :
strcpy ( V_21 -> V_24 . V_40 . V_41 . V_42 ,
L_10 ) ;
break;
default:
F_2 ( L_11 , V_2 -> V_38 ) ;
goto error;
}
memcpy ( & V_21 -> V_24 . V_40 , & V_43 , sizeof( struct V_44 ) ) ;
V_21 -> V_22 = V_2 ;
F_2 ( L_12 , V_11 ) ;
return V_21 ;
error:
F_11 ( V_2 ) ;
return NULL ;
}
