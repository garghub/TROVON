int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 , V_10 ;
T_1 V_11 [ 2 ] ;
T_2 V_12 ;
T_3 V_13 ;
T_4 V_14 ;
struct V_15 V_16 [] = {
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
{ 0x1001f , V_4 -> V_17 . V_18 << 7 , 0x80 } ,
{ 0x10070 , V_4 -> V_17 . V_19 , 0xff } ,
{ 0x10071 , ! V_4 -> V_17 . V_20 << 4 , 0x10 } ,
} ;
F_2 ( & V_4 -> V_21 -> V_22 , L_1 , V_23 ,
V_7 -> V_24 , V_7 -> V_25 ) ;
if ( V_2 -> V_26 . V_27 . V_28 )
V_2 -> V_26 . V_27 . V_28 ( V_2 ) ;
if ( V_4 -> V_29 != V_30 ) {
for ( V_10 = 0 ; V_10 < F_3 ( V_16 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_16 [ V_10 ] . V_31 ,
V_16 [ V_10 ] . V_32 , V_16 [ V_10 ] . V_33 ) ;
if ( V_9 )
goto error;
}
}
V_4 -> V_29 = V_30 ;
V_4 -> V_34 = 0 ;
if ( V_2 -> V_26 . V_27 . V_35 ) {
V_9 = V_2 -> V_26 . V_27 . V_35 ( V_2 , & V_12 ) ;
if ( V_9 )
goto error;
} else
V_12 = 0 ;
F_2 ( & V_4 -> V_21 -> V_22 , L_2 , V_23 , V_12 ) ;
V_14 = V_12 / 1000 ;
V_14 *= 0x4000 ;
V_13 = 0x4000 - F_5 ( V_14 , 41000 ) ;
V_11 [ 0 ] = ( V_13 >> 8 ) & 0x3f ;
V_11 [ 1 ] = ( V_13 >> 0 ) & 0xff ;
V_9 = F_6 ( V_4 , 0x10042 , V_11 , 2 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x000ff , 0x08 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x000fe , 0x01 ) ;
if ( V_9 )
goto error;
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 ;
T_1 V_11 [ 2 ] ;
V_9 = F_9 ( V_4 , 0x1001a , V_11 , 2 ) ;
if ( V_9 )
goto error;
V_7 -> V_25 = 2500 * ( ( V_11 [ 0 ] & 0x0f ) << 8 | V_11 [ 1 ] ) ;
V_9 = F_10 ( V_4 , 0x10019 , & V_11 [ 0 ] ) ;
if ( V_9 )
goto error;
switch ( ( V_11 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_36 = V_37 ;
break;
case 1 :
V_7 -> V_36 = V_38 ;
break;
case 2 :
V_7 -> V_36 = V_39 ;
break;
case 3 :
V_7 -> V_36 = V_40 ;
break;
case 4 :
V_7 -> V_36 = V_41 ;
break;
}
switch ( ( V_11 [ 0 ] >> 7 ) & 0x01 ) {
case 0 :
V_7 -> V_42 = V_43 ;
break;
case 1 :
V_7 -> V_42 = V_44 ;
break;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_2 * V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_1 V_11 [ 3 ] , V_46 = 0 ;
* V_45 = 0 ;
if ( V_4 -> V_34 ) {
V_9 = F_9 ( V_4 , 0x10076 , V_11 , sizeof( V_11 ) ) ;
if ( V_9 )
goto error;
if ( ( V_11 [ 2 ] >> 7 ) & 0x01 || ( V_11 [ 2 ] >> 4 ) & 0x01 ) {
* V_45 = ( V_11 [ 2 ] & 0x0f ) << 16 | V_11 [ 1 ] << 8 | V_11 [ 0 ] ;
V_46 = 1 ;
}
} else {
V_4 -> V_34 = 1 ;
V_46 = 1 ;
}
if ( V_46 ) {
V_9 = F_7 ( V_4 , 0x10079 , 0x01 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 ,
T_3 * V_47 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_1 V_11 [ 2 ] ;
T_3 V_48 ;
V_9 = F_9 ( V_4 , 0x10049 , V_11 , sizeof( V_11 ) ) ;
if ( V_9 )
goto error;
V_48 = ( V_11 [ 0 ] & 0x03 ) << 8 | V_11 [ 1 ] ;
V_48 = ( ~ V_48 & 0x03ff ) ;
if ( V_48 == 512 )
V_48 = 0 ;
else if ( V_48 > 350 )
V_48 = 350 ;
* V_47 = V_48 * 0xffff / ( 350 - 0 ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 , T_3 * V_49 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_1 V_48 ;
unsigned int V_50 , V_51 ;
V_9 = F_10 ( V_4 , 0x10019 , & V_48 ) ;
if ( V_9 )
goto error;
if ( ( ( V_48 >> 0 ) & 0x03 ) % 2 ) {
V_50 = 875 ;
V_51 = 650 ;
} else {
V_50 = 950 ;
V_51 = 760 ;
}
V_9 = F_10 ( V_4 , 0x1004d , & V_48 ) ;
if ( V_9 )
goto error;
#define F_14 24204406
if ( V_48 )
* V_49 = V_50 * ( F_15 ( V_51 / V_48 ) >> 5 ) / ( F_14 >> 5 )
/ 10 ;
else
* V_49 = 0 ;
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_16 ( struct V_1 * V_2 , T_2 * V_52 )
{
* V_52 = 0 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_5 * V_53 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_1 V_11 [ 2 ] ;
* V_53 = 0 ;
V_9 = F_9 ( V_4 , 0x10088 , V_11 , sizeof( V_11 ) ) ;
if ( V_9 )
goto error;
if ( ( ( V_11 [ 0 ] >> 0 ) & 0x01 ) == 1 ) {
* V_53 |= V_54 | V_55 |
V_56 | V_57 ;
if ( ( ( V_11 [ 1 ] >> 3 ) & 0x01 ) == 1 ) {
* V_53 |= V_54 | V_55 |
V_56 | V_57 | V_58 ;
}
}
F_2 ( & V_4 -> V_21 -> V_22 , L_4 , V_23 , V_11 [ 0 ] ,
V_11 [ 1 ] ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_9 = F_7 ( V_4 , 0x00085 , 0x07 ) ;
if ( V_9 )
goto error;
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 , V_10 ;
struct V_15 V_16 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( & V_4 -> V_21 -> V_22 , L_5 , V_23 ) ;
V_4 -> V_29 = V_59 ;
for ( V_10 = 0 ; V_10 < F_3 ( V_16 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_16 [ V_10 ] . V_31 , V_16 [ V_10 ] . V_32 ,
V_16 [ V_10 ] . V_33 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_21 -> V_22 , L_3 , V_23 , V_9 ) ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
V_61 -> V_62 = 500 ;
V_61 -> V_63 = 0 ;
V_61 -> V_64 = 0 ;
return 0 ;
}
