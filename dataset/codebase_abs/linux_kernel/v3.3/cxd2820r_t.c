int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 , V_10 , V_11 ;
T_1 V_12 , V_13 ;
T_2 V_14 ;
T_3 V_15 [ 3 ] , V_16 ;
T_3 V_17 [] [ 5 ] = {
{ 0x17 , 0xea , 0xaa , 0xaa , 0xaa } ,
{ 0x14 , 0x80 , 0x00 , 0x00 , 0x00 } ,
{ 0x11 , 0xf0 , 0x00 , 0x00 , 0x00 } ,
} ;
T_3 V_18 [] [ 2 ] = {
{ 0x1f , 0xdc } ,
{ 0x12 , 0xf8 } ,
{ 0x01 , 0xe0 } ,
} ;
struct V_19 V_20 [] = {
{ 0x00080 , 0x00 , 0xff } ,
{ 0x00081 , 0x03 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00070 , V_4 -> V_21 . V_22 , 0xff } ,
{ 0x000cb , V_4 -> V_21 . V_23 << 6 , 0x40 } ,
{ 0x000a5 , 0x00 , 0x01 } ,
{ 0x00082 , 0x20 , 0x60 } ,
{ 0x000c2 , 0xc3 , 0xff } ,
{ 0x0016a , 0x50 , 0xff } ,
{ 0x00427 , 0x41 , 0xff } ,
} ;
F_2 ( L_1 , V_24 , V_7 -> V_25 , V_7 -> V_26 ) ;
switch ( V_7 -> V_26 ) {
case 6000000 :
V_11 = 0 ;
V_16 = 2 ;
break;
case 7000000 :
V_11 = 1 ;
V_16 = 1 ;
break;
case 8000000 :
V_11 = 2 ;
V_16 = 0 ;
break;
default:
return - V_27 ;
}
V_9 = F_3 ( V_2 ) ;
if ( V_9 )
goto error;
if ( V_2 -> V_28 . V_29 . V_30 )
V_2 -> V_28 . V_29 . V_30 ( V_2 ) ;
if ( V_4 -> V_31 != V_32 ) {
for ( V_10 = 0 ; V_10 < F_4 ( V_20 ) ; V_10 ++ ) {
V_9 = F_5 ( V_4 , V_20 [ V_10 ] . V_33 ,
V_20 [ V_10 ] . V_34 , V_20 [ V_10 ] . V_35 ) ;
if ( V_9 )
goto error;
}
}
V_4 -> V_31 = V_32 ;
V_4 -> V_36 = 0 ;
if ( V_2 -> V_28 . V_29 . V_37 ) {
V_9 = V_2 -> V_28 . V_29 . V_37 ( V_2 , & V_12 ) ;
if ( V_9 )
goto error;
} else
V_12 = 0 ;
F_2 ( L_2 , V_24 , V_12 ) ;
V_14 = V_12 / 1000 ;
V_14 *= 0x1000000 ;
V_13 = F_6 ( V_14 , 41000 ) ;
V_15 [ 0 ] = ( ( V_13 >> 16 ) & 0xff ) ;
V_15 [ 1 ] = ( ( V_13 >> 8 ) & 0xff ) ;
V_15 [ 2 ] = ( ( V_13 >> 0 ) & 0xff ) ;
V_9 = F_7 ( V_4 , 0x000b6 , V_15 , 3 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x0009f , V_17 [ V_11 ] , 5 ) ;
if ( V_9 )
goto error;
V_9 = F_5 ( V_4 , 0x000d7 , V_16 << 6 , 0xc0 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x000d9 , V_18 [ V_11 ] , 2 ) ;
if ( V_9 )
goto error;
V_9 = F_8 ( V_4 , 0x000ff , 0x08 ) ;
if ( V_9 )
goto error;
V_9 = F_8 ( V_4 , 0x000fe , 0x01 ) ;
if ( V_9 )
goto error;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
V_9 = F_10 ( V_4 , 0x0002f , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 6 ) & 0x03 ) {
case 0 :
V_7 -> V_38 = V_39 ;
break;
case 1 :
V_7 -> V_38 = V_40 ;
break;
case 2 :
V_7 -> V_38 = V_41 ;
break;
}
switch ( ( V_15 [ 1 ] >> 1 ) & 0x03 ) {
case 0 :
V_7 -> V_42 = V_43 ;
break;
case 1 :
V_7 -> V_42 = V_44 ;
break;
}
switch ( ( V_15 [ 1 ] >> 3 ) & 0x03 ) {
case 0 :
V_7 -> V_45 = V_46 ;
break;
case 1 :
V_7 -> V_45 = V_47 ;
break;
case 2 :
V_7 -> V_45 = V_48 ;
break;
case 3 :
V_7 -> V_45 = V_49 ;
break;
}
switch ( ( V_15 [ 0 ] >> 3 ) & 0x07 ) {
case 0 :
V_7 -> V_50 = V_51 ;
break;
case 1 :
V_7 -> V_50 = V_52 ;
break;
case 2 :
V_7 -> V_50 = V_53 ;
break;
case 3 :
V_7 -> V_50 = V_54 ;
break;
}
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_55 = V_56 ;
break;
case 1 :
V_7 -> V_55 = V_57 ;
break;
case 2 :
V_7 -> V_55 = V_58 ;
break;
case 3 :
V_7 -> V_55 = V_59 ;
break;
case 4 :
V_7 -> V_55 = V_60 ;
break;
}
switch ( ( V_15 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_7 -> V_61 = V_56 ;
break;
case 1 :
V_7 -> V_61 = V_57 ;
break;
case 2 :
V_7 -> V_61 = V_58 ;
break;
case 3 :
V_7 -> V_61 = V_59 ;
break;
case 4 :
V_7 -> V_61 = V_60 ;
break;
}
V_9 = F_11 ( V_4 , 0x007c6 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x01 ) {
case 0 :
V_7 -> V_62 = V_63 ;
break;
case 1 :
V_7 -> V_62 = V_64 ;
break;
}
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_65 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 3 ] , V_66 = 0 ;
* V_65 = 0 ;
if ( V_4 -> V_36 ) {
V_9 = F_10 ( V_4 , 0x00076 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 2 ] >> 7 ) & 0x01 || ( V_15 [ 2 ] >> 4 ) & 0x01 ) {
* V_65 = ( V_15 [ 2 ] & 0x0f ) << 16 | V_15 [ 1 ] << 8 | V_15 [ 0 ] ;
V_66 = 1 ;
}
} else {
V_4 -> V_36 = 1 ;
V_66 = 1 ;
}
if ( V_66 ) {
V_9 = F_8 ( V_4 , 0x00079 , 0x01 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 ,
T_4 * V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_4 V_68 ;
V_9 = F_10 ( V_4 , 0x00026 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_68 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
V_68 = ~ V_68 & 0x0fff ;
* V_67 = V_68 * 0xffff / 0x0fff ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_2 , T_4 * V_69 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_4 V_68 ;
V_9 = F_10 ( V_4 , 0x00028 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_68 = ( V_15 [ 0 ] & 0x1f ) << 8 | V_15 [ 1 ] ;
#define F_15 15151336
if ( V_68 )
* V_69 = ( F_16 ( V_68 ) - F_15 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_69 = 0 ;
F_2 ( L_4 , V_24 , * V_69 , V_68 ) ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_17 ( struct V_1 * V_2 , T_1 * V_70 )
{
* V_70 = 0 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_5 * V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 4 ] ;
* V_71 = 0 ;
V_9 = F_11 ( V_4 , 0x00010 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] & 0x07 ) == 6 ) {
V_9 = F_11 ( V_4 , 0x00073 , & V_15 [ 1 ] ) ;
if ( V_9 )
goto error;
if ( ( ( V_15 [ 1 ] >> 3 ) & 0x01 ) == 1 ) {
* V_71 |= V_72 | V_73 |
V_74 | V_75 | V_76 ;
} else {
* V_71 |= V_72 | V_73 |
V_74 | V_75 ;
}
} else {
V_9 = F_11 ( V_4 , 0x00014 , & V_15 [ 2 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 2 ] & 0x0f ) >= 4 ) {
V_9 = F_11 ( V_4 , 0x00a14 , & V_15 [ 3 ] ) ;
if ( V_9 )
goto error;
if ( ( ( V_15 [ 3 ] >> 4 ) & 0x01 ) == 1 )
* V_71 |= V_72 ;
}
}
F_2 ( L_5 , V_24 ,
V_15 [ 0 ] , V_15 [ 1 ] , V_15 [ 2 ] , V_15 [ 3 ] ) ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
V_9 = F_8 ( V_4 , 0x00085 , 0x07 ) ;
if ( V_9 )
goto error;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 , V_10 ;
struct V_19 V_20 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( L_6 , V_24 ) ;
V_4 -> V_31 = V_77 ;
for ( V_10 = 0 ; V_10 < F_4 ( V_20 ) ; V_10 ++ ) {
V_9 = F_5 ( V_4 , V_20 [ V_10 ] . V_33 , V_20 [ V_10 ] . V_34 ,
V_20 [ V_10 ] . V_35 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
V_79 -> V_80 = 500 ;
V_79 -> V_81 = V_2 -> V_28 . V_82 . V_83 * 2 ;
V_79 -> V_84 = ( V_2 -> V_28 . V_82 . V_83 * 2 ) + 1 ;
return 0 ;
}
