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
static int F_5 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
int V_21 ;
T_1 V_22 , V_23 ;
F_6 ( L_3 , V_24 , V_19 -> V_25 ,
V_19 -> V_26 . V_27 . V_28 ) ;
if ( V_17 -> V_29 . V_30 . V_31 )
V_17 -> V_29 . V_30 . V_31 ( V_17 , V_19 ) ;
V_21 = F_1 ( V_2 , 0x04 , 0x06 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x67 , 0x58 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x05 , 0x18 ) ;
if ( V_21 )
goto error;
switch ( V_19 -> V_26 . V_27 . V_28 ) {
case V_32 :
V_22 = 0xb7 ;
V_23 = 0x55 ;
break;
case V_33 :
V_22 = 0x00 ;
V_23 = 0x64 ;
break;
case V_34 :
default:
V_22 = 0x49 ;
V_23 = 0x72 ;
}
V_21 = F_1 ( V_2 , 0x1b , V_22 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x1c , V_23 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x0c , 0xbb ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x0d , 0x31 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x08 , 0x24 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x00 , 0x00 ) ;
if ( V_21 )
goto error;
V_21 = F_1 ( V_2 , 0x00 , 0x20 ) ;
if ( V_21 )
goto error;
return V_21 ;
error:
F_6 ( L_4 , V_24 , V_21 ) ;
return V_21 ;
}
static int F_7 ( struct V_16 * V_17 ,
struct V_35 * V_36 )
{
V_36 -> V_37 = 300 ;
V_36 -> V_38 = 0 ;
V_36 -> V_39 = 0 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , T_2 * V_40 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
int V_21 ;
T_1 V_22 ;
* V_40 = 0 ;
V_21 = F_4 ( V_2 , 0x42 , & V_22 ) ;
if ( V_21 )
goto error;
if ( V_22 & 0x80 ) {
* V_40 |= V_41 | V_42 | V_43 |
V_44 | V_45 ;
} else {
V_21 = F_4 ( V_2 , 0x01 , & V_22 ) ;
if ( V_21 )
goto error;
if ( V_22 & 0x10 ) {
* V_40 |= V_41 ;
if ( ! ( V_22 & 0x01 ) ) {
* V_40 |= V_42 | V_43 ;
}
}
}
return V_21 ;
error:
F_6 ( L_4 , V_24 , V_21 ) ;
return V_21 ;
}
static int F_9 ( struct V_16 * V_17 , T_3 * V_46 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
int V_21 ;
T_1 V_22 , V_23 ;
T_4 V_47 ;
* V_46 = 0 ;
V_21 = F_4 ( V_2 , 0x65 , & V_22 ) ;
if ( V_21 )
goto error;
V_21 = F_4 ( V_2 , 0x66 , & V_23 ) ;
if ( V_21 )
goto error;
V_47 = ( V_23 << 8 ) | V_22 ;
if ( V_47 < V_2 -> V_46 )
* V_46 = V_47 ;
else
* V_46 = V_47 - V_2 -> V_46 ;
V_2 -> V_46 = V_47 ;
return V_21 ;
error:
F_6 ( L_4 , V_24 , V_21 ) ;
return V_21 ;
}
static int F_10 ( struct V_16 * V_17 , T_4 * V_48 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
int V_21 ;
T_1 V_22 ;
V_21 = F_4 ( V_2 , 0x24 , & V_22 ) ;
if ( V_21 ) {
* V_48 = 0 ;
goto error;
}
* V_48 = ( ( V_22 << 8 ) | V_22 ) ;
return V_21 ;
error:
F_6 ( L_4 , V_24 , V_21 ) ;
return V_21 ;
}
static int F_11 ( struct V_16 * V_17 , T_4 * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , T_3 * V_50 )
{
* V_50 = 0 ;
return 0 ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
F_14 ( V_2 ) ;
}
struct V_16 * F_15 ( const struct V_51 * V_9 ,
struct V_52 * V_13 )
{
int V_21 ;
struct V_1 * V_2 = NULL ;
T_1 V_22 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_53 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_13 = V_13 ;
memcpy ( & V_2 -> V_9 , V_9 , sizeof( struct V_51 ) ) ;
V_21 = F_4 ( V_2 , 0x33 , & V_22 ) ;
if ( V_21 || V_22 != 0x0b )
goto error;
memcpy ( & V_2 -> V_54 . V_29 , & V_55 ,
sizeof( struct V_56 ) ) ;
V_2 -> V_54 . V_20 = V_2 ;
return & V_2 -> V_54 ;
error:
F_14 ( V_2 ) ;
return NULL ;
}
