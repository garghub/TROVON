static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 2 ] = { V_3 , V_4 } ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_10 . V_11 ,
. V_12 = 0 ,
. V_13 = sizeof( V_6 ) ,
. V_6 = V_6 ,
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 1 ) ;
if ( V_5 == 1 ) {
V_5 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_1 ,
V_16 , V_5 , V_3 ) ;
V_5 = - V_17 ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_2 -> V_10 . V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_6 = & V_3
} , {
. V_9 = V_2 -> V_10 . V_11 ,
. V_12 = V_18 ,
. V_13 = 1 ,
. V_6 = V_4
}
} ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 == 2 ) {
V_5 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 , L_2 ,
V_16 , V_5 , V_3 ) ;
V_5 = - V_17 ;
}
return V_5 ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_23 ;
struct V_1 * V_2 = V_20 -> V_24 ;
int V_5 ;
T_1 V_25 , V_26 ;
F_6 ( & V_2 -> V_14 -> V_15 , L_3 ,
V_27 , V_22 -> V_28 , V_22 -> V_29 ) ;
if ( V_20 -> V_30 . V_31 . V_32 )
V_20 -> V_30 . V_31 . V_32 ( V_20 ) ;
V_5 = F_1 ( V_2 , 0x04 , 0x06 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x67 , 0x58 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x05 , 0x18 ) ;
if ( V_5 )
goto error;
switch ( V_22 -> V_29 ) {
case 6000000 :
V_25 = 0xb7 ;
V_26 = 0x55 ;
break;
case 7000000 :
V_25 = 0x00 ;
V_26 = 0x64 ;
break;
case 8000000 :
default:
V_25 = 0x49 ;
V_26 = 0x72 ;
}
V_5 = F_1 ( V_2 , 0x1b , V_25 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x1c , V_26 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x0c , 0xbb ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x0d , 0x31 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x08 , 0x24 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x00 , 0x00 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 , 0x00 , 0x20 ) ;
if ( V_5 )
goto error;
return V_5 ;
error:
F_6 ( & V_2 -> V_14 -> V_15 , L_4 , V_27 , V_5 ) ;
return V_5 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_33 * V_34 )
{
V_34 -> V_35 = 300 ;
V_34 -> V_36 = 0 ;
V_34 -> V_37 = 0 ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , enum V_38 * V_39 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
int V_5 ;
T_1 V_25 ;
* V_39 = 0 ;
V_5 = F_4 ( V_2 , 0x42 , & V_25 ) ;
if ( V_5 )
goto error;
if ( V_25 & 0x80 ) {
* V_39 |= V_40 | V_41 | V_42 |
V_43 | V_44 ;
} else {
V_5 = F_4 ( V_2 , 0x01 , & V_25 ) ;
if ( V_5 )
goto error;
if ( V_25 & 0x10 ) {
* V_39 |= V_40 ;
if ( ! ( V_25 & 0x01 ) ) {
* V_39 |= V_41 | V_42 ;
}
}
}
return V_5 ;
error:
F_6 ( & V_2 -> V_14 -> V_15 , L_4 , V_27 , V_5 ) ;
return V_5 ;
}
static int F_9 ( struct V_19 * V_20 , T_2 * V_45 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
int V_5 ;
T_1 V_25 , V_26 ;
T_3 V_46 ;
* V_45 = 0 ;
V_5 = F_4 ( V_2 , 0x65 , & V_25 ) ;
if ( V_5 )
goto error;
V_5 = F_4 ( V_2 , 0x66 , & V_26 ) ;
if ( V_5 )
goto error;
V_46 = ( V_26 << 8 ) | V_25 ;
if ( V_46 < V_2 -> V_45 )
* V_45 = V_46 ;
else
* V_45 = V_46 - V_2 -> V_45 ;
V_2 -> V_45 = V_46 ;
return V_5 ;
error:
F_6 ( & V_2 -> V_14 -> V_15 , L_4 , V_27 , V_5 ) ;
return V_5 ;
}
static int F_10 ( struct V_19 * V_20 , T_3 * V_47 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
int V_5 ;
T_1 V_25 ;
V_5 = F_4 ( V_2 , 0x24 , & V_25 ) ;
if ( V_5 ) {
* V_47 = 0 ;
goto error;
}
* V_47 = ( ( V_25 << 8 ) | V_25 ) ;
return V_5 ;
error:
F_6 ( & V_2 -> V_14 -> V_15 , L_4 , V_27 , V_5 ) ;
return V_5 ;
}
static int F_11 ( struct V_19 * V_20 , T_3 * V_48 )
{
* V_48 = 0 ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 , T_2 * V_49 )
{
* V_49 = 0 ;
return 0 ;
}
static void F_13 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_24 ;
F_14 ( V_2 ) ;
}
struct V_19 * F_15 ( const struct V_50 * V_10 ,
struct V_51 * V_14 )
{
int V_5 ;
struct V_1 * V_2 = NULL ;
T_1 V_25 ;
V_2 = F_16 ( sizeof( struct V_1 ) , V_52 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_10 , V_10 , sizeof( struct V_50 ) ) ;
V_5 = F_4 ( V_2 , 0x33 , & V_25 ) ;
if ( V_5 || V_25 != 0x0b )
goto error;
memcpy ( & V_2 -> V_53 . V_30 , & V_54 ,
sizeof( struct V_55 ) ) ;
V_2 -> V_53 . V_24 = V_2 ;
return & V_2 -> V_53 ;
error:
F_14 ( V_2 ) ;
return NULL ;
}
