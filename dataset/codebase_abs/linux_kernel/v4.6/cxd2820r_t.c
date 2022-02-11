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
{ 0x00071 , ! V_4 -> V_21 . V_23 << 4 , 0x10 } ,
{ 0x000cb , V_4 -> V_21 . V_24 << 6 , 0x40 } ,
{ 0x000a5 , 0x00 , 0x01 } ,
{ 0x00082 , 0x20 , 0x60 } ,
{ 0x000c2 , 0xc3 , 0xff } ,
{ 0x0016a , 0x50 , 0xff } ,
{ 0x00427 , 0x41 , 0xff } ,
} ;
F_2 ( & V_4 -> V_25 -> V_26 , L_1 , V_27 ,
V_7 -> V_28 , V_7 -> V_29 ) ;
switch ( V_7 -> V_29 ) {
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
return - V_30 ;
}
if ( V_2 -> V_31 . V_32 . V_33 )
V_2 -> V_31 . V_32 . V_33 ( V_2 ) ;
if ( V_4 -> V_34 != V_35 ) {
for ( V_10 = 0 ; V_10 < F_3 ( V_20 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_20 [ V_10 ] . V_36 ,
V_20 [ V_10 ] . V_37 , V_20 [ V_10 ] . V_38 ) ;
if ( V_9 )
goto error;
}
}
V_4 -> V_34 = V_35 ;
V_4 -> V_39 = false ;
if ( V_2 -> V_31 . V_32 . V_40 ) {
V_9 = V_2 -> V_31 . V_32 . V_40 ( V_2 , & V_12 ) ;
if ( V_9 )
goto error;
} else
V_12 = 0 ;
F_2 ( & V_4 -> V_25 -> V_26 , L_2 , V_27 , V_12 ) ;
V_14 = V_12 / 1000 ;
V_14 *= 0x1000000 ;
V_13 = F_5 ( V_14 , 41000 ) ;
V_15 [ 0 ] = ( ( V_13 >> 16 ) & 0xff ) ;
V_15 [ 1 ] = ( ( V_13 >> 8 ) & 0xff ) ;
V_15 [ 2 ] = ( ( V_13 >> 0 ) & 0xff ) ;
V_9 = F_6 ( V_4 , 0x000b6 , V_15 , 3 ) ;
if ( V_9 )
goto error;
V_9 = F_6 ( V_4 , 0x0009f , V_17 [ V_11 ] , 5 ) ;
if ( V_9 )
goto error;
V_9 = F_4 ( V_4 , 0x000d7 , V_16 << 6 , 0xc0 ) ;
if ( V_9 )
goto error;
V_9 = F_6 ( V_4 , 0x000d9 , V_18 [ V_11 ] , 2 ) ;
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
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
V_9 = F_9 ( V_4 , 0x0002f , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 6 ) & 0x03 ) {
case 0 :
V_7 -> V_41 = V_42 ;
break;
case 1 :
V_7 -> V_41 = V_43 ;
break;
case 2 :
V_7 -> V_41 = V_44 ;
break;
}
switch ( ( V_15 [ 1 ] >> 1 ) & 0x03 ) {
case 0 :
V_7 -> V_45 = V_46 ;
break;
case 1 :
V_7 -> V_45 = V_47 ;
break;
}
switch ( ( V_15 [ 1 ] >> 3 ) & 0x03 ) {
case 0 :
V_7 -> V_48 = V_49 ;
break;
case 1 :
V_7 -> V_48 = V_50 ;
break;
case 2 :
V_7 -> V_48 = V_51 ;
break;
case 3 :
V_7 -> V_48 = V_52 ;
break;
}
switch ( ( V_15 [ 0 ] >> 3 ) & 0x07 ) {
case 0 :
V_7 -> V_53 = V_54 ;
break;
case 1 :
V_7 -> V_53 = V_55 ;
break;
case 2 :
V_7 -> V_53 = V_56 ;
break;
case 3 :
V_7 -> V_53 = V_57 ;
break;
}
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_58 = V_59 ;
break;
case 1 :
V_7 -> V_58 = V_60 ;
break;
case 2 :
V_7 -> V_58 = V_61 ;
break;
case 3 :
V_7 -> V_58 = V_62 ;
break;
case 4 :
V_7 -> V_58 = V_63 ;
break;
}
switch ( ( V_15 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_7 -> V_64 = V_59 ;
break;
case 1 :
V_7 -> V_64 = V_60 ;
break;
case 2 :
V_7 -> V_64 = V_61 ;
break;
case 3 :
V_7 -> V_64 = V_62 ;
break;
case 4 :
V_7 -> V_64 = V_63 ;
break;
}
V_9 = F_10 ( V_4 , 0x007c6 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x01 ) {
case 0 :
V_7 -> V_65 = V_66 ;
break;
case 1 :
V_7 -> V_65 = V_67 ;
break;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_1 * V_68 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 3 ] , V_69 = 0 ;
* V_68 = 0 ;
if ( V_4 -> V_39 ) {
V_9 = F_9 ( V_4 , 0x00076 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 2 ] >> 7 ) & 0x01 || ( V_15 [ 2 ] >> 4 ) & 0x01 ) {
* V_68 = ( V_15 [ 2 ] & 0x0f ) << 16 | V_15 [ 1 ] << 8 | V_15 [ 0 ] ;
V_69 = 1 ;
}
} else {
V_4 -> V_39 = true ;
V_69 = 1 ;
}
if ( V_69 ) {
V_9 = F_7 ( V_4 , 0x00079 , 0x01 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 ,
T_4 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_4 V_71 ;
V_9 = F_9 ( V_4 , 0x00026 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_71 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
V_71 = ~ V_71 & 0x0fff ;
* V_70 = V_71 * 0xffff / 0x0fff ;
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 , T_4 * V_72 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_4 V_71 ;
V_9 = F_9 ( V_4 , 0x00028 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_71 = ( V_15 [ 0 ] & 0x1f ) << 8 | V_15 [ 1 ] ;
#define F_14 15151336
if ( V_71 )
* V_72 = ( F_15 ( V_71 ) - F_14 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_72 = 0 ;
F_2 ( & V_4 -> V_25 -> V_26 , L_4 , V_27 , * V_72 ,
V_71 ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_16 ( struct V_1 * V_2 , T_1 * V_73 )
{
* V_73 = 0 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , enum V_74 * V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 4 ] ;
* V_75 = 0 ;
V_9 = F_10 ( V_4 , 0x00010 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] & 0x07 ) == 6 ) {
V_9 = F_10 ( V_4 , 0x00073 , & V_15 [ 1 ] ) ;
if ( V_9 )
goto error;
if ( ( ( V_15 [ 1 ] >> 3 ) & 0x01 ) == 1 ) {
* V_75 |= V_76 | V_77 |
V_78 | V_79 | V_80 ;
} else {
* V_75 |= V_76 | V_77 |
V_78 | V_79 ;
}
} else {
V_9 = F_10 ( V_4 , 0x00014 , & V_15 [ 2 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 2 ] & 0x0f ) >= 4 ) {
V_9 = F_10 ( V_4 , 0x00a14 , & V_15 [ 3 ] ) ;
if ( V_9 )
goto error;
if ( ( ( V_15 [ 3 ] >> 4 ) & 0x01 ) == 1 )
* V_75 |= V_76 ;
}
}
F_2 ( & V_4 -> V_25 -> V_26 , L_5 , V_27 , 4 , V_15 ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
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
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_19 ( struct V_1 * V_2 )
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
F_2 ( & V_4 -> V_25 -> V_26 , L_6 , V_27 ) ;
V_4 -> V_34 = V_81 ;
for ( V_10 = 0 ; V_10 < F_3 ( V_20 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_20 [ V_10 ] . V_36 , V_20 [ V_10 ] . V_37 ,
V_20 [ V_10 ] . V_38 ) ;
if ( V_9 )
goto error;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_25 -> V_26 , L_3 , V_27 , V_9 ) ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
V_83 -> V_84 = 500 ;
V_83 -> V_85 = V_2 -> V_31 . V_86 . V_87 * 2 ;
V_83 -> V_88 = ( V_2 -> V_31 . V_86 . V_87 * 2 ) + 1 ;
return 0 ;
}
