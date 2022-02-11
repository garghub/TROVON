static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_9 . V_10 ,
. V_11 = 0 ,
. V_12 = 2 ,
. V_5 = V_5 } ;
if ( F_2 ( V_2 -> V_13 , & V_7 , 1 ) != 1 ) {
F_3 ( L_1 , V_3 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_6 V_7 [ 2 ] = {
{
. V_8 = V_2 -> V_9 . V_10 ,
. V_11 = 0 ,
. V_12 = 1 ,
. V_5 = & V_3
} , {
. V_8 = V_2 -> V_9 . V_10 ,
. V_11 = V_15 ,
. V_12 = 1 ,
. V_5 = V_4
}
} ;
if ( F_2 ( V_2 -> V_13 , V_7 , 2 ) != 2 ) {
F_3 ( L_2 , V_3 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 ;
struct V_1 * V_2 = V_17 -> V_21 ;
int V_22 ;
T_1 V_23 , V_24 ;
F_6 ( L_3 , V_25 , V_19 -> V_26 ,
V_19 -> V_27 ) ;
if ( V_17 -> V_28 . V_29 . V_30 )
V_17 -> V_28 . V_29 . V_30 ( V_17 ) ;
V_22 = F_1 ( V_2 , 0x04 , 0x06 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x67 , 0x58 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x05 , 0x18 ) ;
if ( V_22 )
goto error;
switch ( V_19 -> V_27 ) {
case 6000000 :
V_23 = 0xb7 ;
V_24 = 0x55 ;
break;
case 7000000 :
V_23 = 0x00 ;
V_24 = 0x64 ;
break;
case 8000000 :
default:
V_23 = 0x49 ;
V_24 = 0x72 ;
}
V_22 = F_1 ( V_2 , 0x1b , V_23 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x1c , V_24 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x0c , 0xbb ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x0d , 0x31 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x08 , 0x24 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x00 , 0x00 ) ;
if ( V_22 )
goto error;
V_22 = F_1 ( V_2 , 0x00 , 0x20 ) ;
if ( V_22 )
goto error;
return V_22 ;
error:
F_6 ( L_4 , V_25 , V_22 ) ;
return V_22 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_31 * V_32 )
{
V_32 -> V_33 = 300 ;
V_32 -> V_34 = 0 ;
V_32 -> V_35 = 0 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , T_2 * V_36 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
int V_22 ;
T_1 V_23 ;
* V_36 = 0 ;
V_22 = F_4 ( V_2 , 0x42 , & V_23 ) ;
if ( V_22 )
goto error;
if ( V_23 & 0x80 ) {
* V_36 |= V_37 | V_38 | V_39 |
V_40 | V_41 ;
} else {
V_22 = F_4 ( V_2 , 0x01 , & V_23 ) ;
if ( V_22 )
goto error;
if ( V_23 & 0x10 ) {
* V_36 |= V_37 ;
if ( ! ( V_23 & 0x01 ) ) {
* V_36 |= V_38 | V_39 ;
}
}
}
return V_22 ;
error:
F_6 ( L_4 , V_25 , V_22 ) ;
return V_22 ;
}
static int F_9 ( struct V_16 * V_17 , T_3 * V_42 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
int V_22 ;
T_1 V_23 , V_24 ;
T_4 V_43 ;
* V_42 = 0 ;
V_22 = F_4 ( V_2 , 0x65 , & V_23 ) ;
if ( V_22 )
goto error;
V_22 = F_4 ( V_2 , 0x66 , & V_24 ) ;
if ( V_22 )
goto error;
V_43 = ( V_24 << 8 ) | V_23 ;
if ( V_43 < V_2 -> V_42 )
* V_42 = V_43 ;
else
* V_42 = V_43 - V_2 -> V_42 ;
V_2 -> V_42 = V_43 ;
return V_22 ;
error:
F_6 ( L_4 , V_25 , V_22 ) ;
return V_22 ;
}
static int F_10 ( struct V_16 * V_17 , T_4 * V_44 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
int V_22 ;
T_1 V_23 ;
V_22 = F_4 ( V_2 , 0x24 , & V_23 ) ;
if ( V_22 ) {
* V_44 = 0 ;
goto error;
}
* V_44 = ( ( V_23 << 8 ) | V_23 ) ;
return V_22 ;
error:
F_6 ( L_4 , V_25 , V_22 ) ;
return V_22 ;
}
static int F_11 ( struct V_16 * V_17 , T_4 * V_45 )
{
* V_45 = 0 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , T_3 * V_46 )
{
* V_46 = 0 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_21 ;
F_14 ( V_2 ) ;
}
struct V_16 * F_15 ( const struct V_47 * V_9 ,
struct V_48 * V_13 )
{
int V_22 ;
struct V_1 * V_2 = NULL ;
T_1 V_23 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_49 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_47 ) ) ;
V_22 = F_4 ( V_2 , 0x33 , & V_23 ) ;
if ( V_22 || V_23 != 0x0b )
goto error;
memcpy ( & V_2 -> V_50 . V_28 , & V_51 ,
sizeof( struct V_52 ) ) ;
V_2 -> V_50 . V_21 = V_2 ;
return & V_2 -> V_50 ;
error:
F_14 ( V_2 ) ;
return NULL ;
}
