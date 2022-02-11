int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 , V_12 ;
T_1 V_13 , V_14 ;
T_2 V_15 ;
T_3 V_16 [ 3 ] , V_17 ;
T_3 V_18 [] [ 5 ] = {
{ 0x17 , 0xea , 0xaa , 0xaa , 0xaa } ,
{ 0x14 , 0x80 , 0x00 , 0x00 , 0x00 } ,
{ 0x11 , 0xf0 , 0x00 , 0x00 , 0x00 } ,
} ;
T_3 V_19 [] [ 2 ] = {
{ 0x1f , 0xdc } ,
{ 0x12 , 0xf8 } ,
{ 0x01 , 0xe0 } ,
} ;
struct V_20 V_21 [] = {
{ 0x00080 , 0x00 , 0xff } ,
{ 0x00081 , 0x03 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00070 , V_6 -> V_22 . V_23 , 0xff } ,
{ 0x000cb , V_6 -> V_22 . V_24 << 6 , 0x40 } ,
{ 0x000a5 , 0x00 , 0x01 } ,
{ 0x00082 , 0x20 , 0x60 } ,
{ 0x000c2 , 0xc3 , 0xff } ,
{ 0x0016a , 0x50 , 0xff } ,
{ 0x00427 , 0x41 , 0xff } ,
} ;
F_2 ( L_1 , V_25 , V_9 -> V_26 , V_9 -> V_27 ) ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 )
goto error;
if ( V_2 -> V_28 . V_29 . V_30 )
V_2 -> V_28 . V_29 . V_30 ( V_2 , V_4 ) ;
if ( V_6 -> V_31 != V_32 ) {
for ( V_12 = 0 ; V_12 < F_4 ( V_21 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_21 [ V_12 ] . V_33 ,
V_21 [ V_12 ] . V_34 , V_21 [ V_12 ] . V_35 ) ;
if ( V_11 )
goto error;
}
}
V_6 -> V_31 = V_32 ;
V_6 -> V_36 = 0 ;
switch ( V_9 -> V_27 ) {
case 6000000 :
V_13 = V_6 -> V_22 . V_37 ;
V_12 = 0 ;
V_17 = 2 ;
break;
case 7000000 :
V_13 = V_6 -> V_22 . V_38 ;
V_12 = 1 ;
V_17 = 1 ;
break;
case 8000000 :
V_13 = V_6 -> V_22 . V_39 ;
V_12 = 2 ;
V_17 = 0 ;
break;
default:
return - V_40 ;
}
V_15 = V_13 ;
V_15 *= 0x1000000 ;
V_14 = F_6 ( V_15 , 41000 ) ;
V_16 [ 0 ] = ( ( V_14 >> 16 ) & 0xff ) ;
V_16 [ 1 ] = ( ( V_14 >> 8 ) & 0xff ) ;
V_16 [ 2 ] = ( ( V_14 >> 0 ) & 0xff ) ;
V_11 = F_7 ( V_6 , 0x000b6 , V_16 , 3 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_6 , 0x0009f , V_18 [ V_12 ] , 5 ) ;
if ( V_11 )
goto error;
V_11 = F_5 ( V_6 , 0x000d7 , V_17 << 6 , 0xc0 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_6 , 0x000d9 , V_19 [ V_12 ] , 2 ) ;
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
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
V_11 = F_10 ( V_6 , 0x0002f , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
switch ( ( V_16 [ 0 ] >> 6 ) & 0x03 ) {
case 0 :
V_9 -> V_41 = V_42 ;
break;
case 1 :
V_9 -> V_41 = V_43 ;
break;
case 2 :
V_9 -> V_41 = V_44 ;
break;
}
switch ( ( V_16 [ 1 ] >> 1 ) & 0x03 ) {
case 0 :
V_9 -> V_45 = V_46 ;
break;
case 1 :
V_9 -> V_45 = V_47 ;
break;
}
switch ( ( V_16 [ 1 ] >> 3 ) & 0x03 ) {
case 0 :
V_9 -> V_48 = V_49 ;
break;
case 1 :
V_9 -> V_48 = V_50 ;
break;
case 2 :
V_9 -> V_48 = V_51 ;
break;
case 3 :
V_9 -> V_48 = V_52 ;
break;
}
switch ( ( V_16 [ 0 ] >> 3 ) & 0x07 ) {
case 0 :
V_9 -> V_53 = V_54 ;
break;
case 1 :
V_9 -> V_53 = V_55 ;
break;
case 2 :
V_9 -> V_53 = V_56 ;
break;
case 3 :
V_9 -> V_53 = V_57 ;
break;
}
switch ( ( V_16 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_58 = V_59 ;
break;
case 1 :
V_9 -> V_58 = V_60 ;
break;
case 2 :
V_9 -> V_58 = V_61 ;
break;
case 3 :
V_9 -> V_58 = V_62 ;
break;
case 4 :
V_9 -> V_58 = V_63 ;
break;
}
switch ( ( V_16 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_9 -> V_64 = V_59 ;
break;
case 1 :
V_9 -> V_64 = V_60 ;
break;
case 2 :
V_9 -> V_64 = V_61 ;
break;
case 3 :
V_9 -> V_64 = V_62 ;
break;
case 4 :
V_9 -> V_64 = V_63 ;
break;
}
V_11 = F_11 ( V_6 , 0x007c6 , & V_16 [ 0 ] ) ;
if ( V_11 )
goto error;
switch ( ( V_16 [ 0 ] >> 0 ) & 0x01 ) {
case 0 :
V_9 -> V_65 = V_66 ;
break;
case 1 :
V_9 -> V_65 = V_67 ;
break;
}
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_68 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 3 ] , V_69 = 0 ;
* V_68 = 0 ;
if ( V_6 -> V_36 ) {
V_11 = F_10 ( V_6 , 0x00076 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
if ( ( V_16 [ 2 ] >> 7 ) & 0x01 || ( V_16 [ 2 ] >> 4 ) & 0x01 ) {
* V_68 = ( V_16 [ 2 ] & 0x0f ) << 16 | V_16 [ 1 ] << 8 | V_16 [ 0 ] ;
V_69 = 1 ;
}
} else {
V_6 -> V_36 = 1 ;
V_69 = 1 ;
}
if ( V_69 ) {
V_11 = F_8 ( V_6 , 0x00079 , 0x01 ) ;
if ( V_11 )
goto error;
}
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 ,
T_4 * V_70 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
T_4 V_71 ;
V_11 = F_10 ( V_6 , 0x00026 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
V_71 = ( V_16 [ 0 ] & 0x0f ) << 8 | V_16 [ 1 ] ;
V_71 = ~ V_71 & 0x0fff ;
* V_70 = V_71 * 0xffff / 0x0fff ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_2 , T_4 * V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
T_4 V_71 ;
V_11 = F_10 ( V_6 , 0x00028 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
V_71 = ( V_16 [ 0 ] & 0x1f ) << 8 | V_16 [ 1 ] ;
#define F_15 15151336
if ( V_71 )
* V_72 = ( F_16 ( V_71 ) - F_15 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_72 = 0 ;
F_2 ( L_3 , V_25 , * V_72 , V_71 ) ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 , T_1 * V_73 )
{
* V_73 = 0 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_5 * V_74 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 4 ] ;
* V_74 = 0 ;
V_11 = F_11 ( V_6 , 0x00010 , & V_16 [ 0 ] ) ;
if ( V_11 )
goto error;
if ( ( V_16 [ 0 ] & 0x07 ) == 6 ) {
V_11 = F_11 ( V_6 , 0x00073 , & V_16 [ 1 ] ) ;
if ( V_11 )
goto error;
if ( ( ( V_16 [ 1 ] >> 3 ) & 0x01 ) == 1 ) {
* V_74 |= V_75 | V_76 |
V_77 | V_78 | V_79 ;
} else {
* V_74 |= V_75 | V_76 |
V_77 | V_78 ;
}
} else {
V_11 = F_11 ( V_6 , 0x00014 , & V_16 [ 2 ] ) ;
if ( V_11 )
goto error;
if ( ( V_16 [ 2 ] & 0x0f ) >= 4 ) {
V_11 = F_11 ( V_6 , 0x00a14 , & V_16 [ 3 ] ) ;
if ( V_11 )
goto error;
if ( ( ( V_16 [ 3 ] >> 4 ) & 0x01 ) == 1 )
* V_74 |= V_75 ;
}
}
F_2 ( L_4 , V_25 ,
V_16 [ 0 ] , V_16 [ 1 ] , V_16 [ 2 ] , V_16 [ 3 ] ) ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
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
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 , V_12 ;
struct V_20 V_21 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( L_5 , V_25 ) ;
V_6 -> V_31 = V_80 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_21 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_21 [ V_12 ] . V_33 , V_21 [ V_12 ] . V_34 ,
V_21 [ V_12 ] . V_35 ) ;
if ( V_11 )
goto error;
}
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
V_82 -> V_83 = 500 ;
V_82 -> V_84 = V_2 -> V_28 . V_85 . V_86 * 2 ;
V_82 -> V_87 = ( V_2 -> V_28 . V_85 . V_86 * 2 ) + 1 ;
return 0 ;
}
