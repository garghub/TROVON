int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 , V_12 ;
T_1 V_13 [ 2 ] ;
T_2 V_14 ;
T_3 V_15 ;
struct V_16 V_17 [] = {
{ 0x00080 , 0x01 , 0xff } ,
{ 0x00081 , 0x05 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00082 , 0x20 , 0x60 } ,
{ 0x1016a , 0x48 , 0xff } ,
{ 0x100a5 , 0x00 , 0x01 } ,
{ 0x10020 , 0x06 , 0x07 } ,
{ 0x10059 , 0x50 , 0xff } ,
{ 0x10087 , 0x0c , 0x3c } ,
{ 0x1008b , 0x07 , 0xff } ,
{ 0x1001f , V_6 -> V_18 . V_19 << 7 , 0x80 } ,
{ 0x10070 , V_6 -> V_18 . V_20 , 0xff } ,
} ;
F_2 ( L_1 , V_21 , V_9 -> V_22 , V_9 -> V_23 ) ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 )
goto error;
if ( V_2 -> V_24 . V_25 . V_26 )
V_2 -> V_24 . V_25 . V_26 ( V_2 , V_4 ) ;
if ( V_6 -> V_27 != V_28 ) {
for ( V_12 = 0 ; V_12 < F_4 ( V_17 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_17 [ V_12 ] . V_29 ,
V_17 [ V_12 ] . V_30 , V_17 [ V_12 ] . V_31 ) ;
if ( V_11 )
goto error;
}
}
V_6 -> V_27 = V_28 ;
V_6 -> V_32 = 0 ;
V_15 = V_6 -> V_18 . V_33 ;
V_15 *= 0x4000 ;
V_14 = F_6 ( V_15 , 41000 ) ;
V_13 [ 0 ] = ( V_14 >> 8 ) & 0x3f ;
V_13 [ 1 ] = ( V_14 >> 0 ) & 0xff ;
V_11 = F_7 ( V_6 , 0x10042 , V_13 , 2 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_6 , 0x000ff , 0x08 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_6 , 0x000fe , 0x01 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_34 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
T_1 V_13 [ 2 ] ;
V_11 = F_10 ( V_6 , 0x1001a , V_13 , 2 ) ;
if ( V_11 )
goto error;
V_9 -> V_23 = 2500 * ( ( V_13 [ 0 ] & 0x0f ) << 8 | V_13 [ 1 ] ) ;
V_11 = F_11 ( V_6 , 0x10019 , & V_13 [ 0 ] ) ;
if ( V_11 )
goto error;
switch ( ( V_13 [ 0 ] >> 0 ) & 0x03 ) {
case 0 :
V_9 -> V_35 = V_36 ;
break;
case 1 :
V_9 -> V_35 = V_37 ;
break;
case 2 :
V_9 -> V_35 = V_38 ;
break;
case 3 :
V_9 -> V_35 = V_39 ;
break;
case 4 :
V_9 -> V_35 = V_40 ;
break;
}
switch ( ( V_13 [ 0 ] >> 7 ) & 0x01 ) {
case 0 :
V_9 -> V_41 = V_42 ;
break;
case 1 :
V_9 -> V_41 = V_43 ;
break;
}
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_4 * V_44 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_1 V_13 [ 3 ] , V_45 = 0 ;
* V_44 = 0 ;
if ( V_6 -> V_32 ) {
V_11 = F_10 ( V_6 , 0x10076 , V_13 , sizeof( V_13 ) ) ;
if ( V_11 )
goto error;
if ( ( V_13 [ 2 ] >> 7 ) & 0x01 || ( V_13 [ 2 ] >> 4 ) & 0x01 ) {
* V_44 = ( V_13 [ 2 ] & 0x0f ) << 16 | V_13 [ 1 ] << 8 | V_13 [ 0 ] ;
V_45 = 1 ;
}
} else {
V_6 -> V_32 = 1 ;
V_45 = 1 ;
}
if ( V_45 ) {
V_11 = F_8 ( V_6 , 0x10079 , 0x01 ) ;
if ( V_11 )
goto error;
}
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 ,
T_2 * V_46 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_1 V_13 [ 2 ] ;
T_2 V_47 ;
V_11 = F_10 ( V_6 , 0x10049 , V_13 , sizeof( V_13 ) ) ;
if ( V_11 )
goto error;
V_47 = ( V_13 [ 0 ] & 0x03 ) << 8 | V_13 [ 1 ] ;
V_47 = ( ~ V_47 & 0x03ff ) ;
if ( V_47 == 512 )
V_47 = 0 ;
else if ( V_47 > 350 )
V_47 = 350 ;
* V_46 = V_47 * 0xffff / ( 350 - 0 ) ;
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_2 , T_2 * V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_1 V_47 ;
unsigned int V_49 , V_50 ;
V_11 = F_11 ( V_6 , 0x10019 , & V_47 ) ;
if ( V_11 )
goto error;
if ( ( ( V_47 >> 0 ) & 0x03 ) % 2 ) {
V_49 = 875 ;
V_50 = 650 ;
} else {
V_49 = 950 ;
V_50 = 760 ;
}
V_11 = F_11 ( V_6 , 0x1004d , & V_47 ) ;
if ( V_11 )
goto error;
#define F_15 24204406
if ( V_47 )
* V_48 = V_49 * ( F_16 ( V_50 / V_47 ) >> 5 ) / ( F_15 >> 5 )
/ 10 ;
else
* V_48 = 0 ;
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 , T_4 * V_51 )
{
* V_51 = 0 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_5 * V_52 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_1 V_13 [ 2 ] ;
* V_52 = 0 ;
V_11 = F_10 ( V_6 , 0x10088 , V_13 , sizeof( V_13 ) ) ;
if ( V_11 )
goto error;
if ( ( ( V_13 [ 0 ] >> 0 ) & 0x01 ) == 1 ) {
* V_52 |= V_53 | V_54 |
V_55 | V_56 ;
if ( ( ( V_13 [ 1 ] >> 3 ) & 0x01 ) == 1 ) {
* V_52 |= V_53 | V_54 |
V_55 | V_56 | V_57 ;
}
}
F_2 ( L_3 , V_21 , V_13 [ 0 ] , V_13 [ 1 ] ) ;
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
V_11 = F_8 ( V_6 , 0x00085 , 0x07 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 , V_12 ;
struct V_16 V_17 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( L_4 , V_21 ) ;
V_6 -> V_27 = V_58 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_17 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_17 [ V_12 ] . V_29 , V_17 [ V_12 ] . V_30 ,
V_17 [ V_12 ] . V_31 ) ;
if ( V_11 )
goto error;
}
return V_11 ;
error:
F_2 ( L_2 , V_21 , V_11 ) ;
return V_11 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
V_60 -> V_61 = 500 ;
V_60 -> V_62 = 0 ;
V_60 -> V_63 = 0 ;
return 0 ;
}
