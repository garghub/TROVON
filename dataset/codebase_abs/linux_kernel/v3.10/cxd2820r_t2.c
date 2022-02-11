int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 , V_10 , V_11 ;
T_1 V_12 , V_13 ;
T_2 V_14 ;
T_3 V_15 [ 3 ] , V_16 ;
T_3 V_17 [] [ 5 ] = {
{ 0x1c , 0xb3 , 0x33 , 0x33 , 0x33 } ,
{ 0x17 , 0xea , 0xaa , 0xaa , 0xaa } ,
{ 0x14 , 0x80 , 0x00 , 0x00 , 0x00 } ,
{ 0x11 , 0xf0 , 0x00 , 0x00 , 0x00 } ,
} ;
struct V_18 V_19 [] = {
{ 0x00080 , 0x02 , 0xff } ,
{ 0x00081 , 0x20 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x02069 , 0x01 , 0xff } ,
{ 0x0207f , 0x2a , 0xff } ,
{ 0x02082 , 0x0a , 0xff } ,
{ 0x02083 , 0x0a , 0xff } ,
{ 0x020cb , V_4 -> V_20 . V_21 << 6 , 0x40 } ,
{ 0x02070 , V_4 -> V_20 . V_22 , 0xff } ,
{ 0x020b5 , V_4 -> V_20 . V_23 << 4 , 0x10 } ,
{ 0x02567 , 0x07 , 0x0f } ,
{ 0x02569 , 0x03 , 0x03 } ,
{ 0x02595 , 0x1a , 0xff } ,
{ 0x02596 , 0x50 , 0xff } ,
{ 0x02a8c , 0x00 , 0xff } ,
{ 0x02a8d , 0x34 , 0xff } ,
{ 0x02a45 , 0x06 , 0x07 } ,
{ 0x03f10 , 0x0d , 0xff } ,
{ 0x03f11 , 0x02 , 0xff } ,
{ 0x03f12 , 0x01 , 0xff } ,
{ 0x03f23 , 0x2c , 0xff } ,
{ 0x03f51 , 0x13 , 0xff } ,
{ 0x03f52 , 0x01 , 0xff } ,
{ 0x03f53 , 0x00 , 0xff } ,
{ 0x027e6 , 0x14 , 0xff } ,
{ 0x02786 , 0x02 , 0x07 } ,
{ 0x02787 , 0x40 , 0xe0 } ,
{ 0x027ef , 0x10 , 0x18 } ,
} ;
F_2 ( & V_4 -> V_24 -> V_25 , L_1 , V_26 ,
V_7 -> V_27 , V_7 -> V_28 ) ;
switch ( V_7 -> V_28 ) {
case 5000000 :
V_11 = 0 ;
V_16 = 3 ;
break;
case 6000000 :
V_11 = 1 ;
V_16 = 2 ;
break;
case 7000000 :
V_11 = 2 ;
V_16 = 1 ;
break;
case 8000000 :
V_11 = 3 ;
V_16 = 0 ;
break;
default:
return - V_29 ;
}
if ( V_2 -> V_30 . V_31 . V_32 )
V_2 -> V_30 . V_31 . V_32 ( V_2 ) ;
if ( V_4 -> V_33 != V_34 ) {
for ( V_10 = 0 ; V_10 < F_3 ( V_19 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_19 [ V_10 ] . V_35 ,
V_19 [ V_10 ] . V_36 , V_19 [ V_10 ] . V_37 ) ;
if ( V_9 )
goto error;
}
}
V_4 -> V_33 = V_34 ;
if ( V_2 -> V_30 . V_31 . V_38 ) {
V_9 = V_2 -> V_30 . V_31 . V_38 ( V_2 , & V_12 ) ;
if ( V_9 )
goto error;
} else
V_12 = 0 ;
F_2 ( & V_4 -> V_24 -> V_25 , L_2 , V_26 , V_12 ) ;
V_14 = V_12 / 1000 ;
V_14 *= 0x1000000 ;
V_13 = F_5 ( V_14 , 41000 ) ;
V_15 [ 0 ] = ( ( V_13 >> 16 ) & 0xff ) ;
V_15 [ 1 ] = ( ( V_13 >> 8 ) & 0xff ) ;
V_15 [ 2 ] = ( ( V_13 >> 0 ) & 0xff ) ;
if ( V_7 -> V_39 > 255 ) {
F_2 ( & V_4 -> V_24 -> V_25 , L_3 , V_26 ) ;
V_9 = F_6 ( V_4 , 0x023ad , 0 ) ;
if ( V_9 )
goto error;
} else {
F_2 ( & V_4 -> V_24 -> V_25 , L_4 , V_26 ,
V_7 -> V_39 ) ;
V_9 = F_6 ( V_4 , 0x023af , V_7 -> V_39 & 0xFF ) ;
if ( V_9 )
goto error;
V_9 = F_6 ( V_4 , 0x023ad , 1 ) ;
if ( V_9 )
goto error;
}
V_9 = F_7 ( V_4 , 0x020b6 , V_15 , 3 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x0209f , V_17 [ V_11 ] , 5 ) ;
if ( V_9 )
goto error;
V_9 = F_4 ( V_4 , 0x020d7 , V_16 << 6 , 0xc0 ) ;
if ( V_9 )
goto error;
V_9 = F_6 ( V_4 , 0x000ff , 0x08 ) ;
if ( V_9 )
goto error;
V_9 = F_6 ( V_4 , 0x000fe , 0x01 ) ;
if ( V_9 )
goto error;
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_2 -> V_8 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
V_9 = F_9 ( V_4 , 0x0205c , V_15 , 2 ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_40 = V_41 ;
break;
case 1 :
V_7 -> V_40 = V_42 ;
break;
case 2 :
V_7 -> V_40 = V_43 ;
break;
case 3 :
V_7 -> V_40 = V_44 ;
break;
case 4 :
V_7 -> V_40 = V_45 ;
break;
case 5 :
V_7 -> V_40 = V_46 ;
break;
}
switch ( ( V_15 [ 1 ] >> 4 ) & 0x07 ) {
case 0 :
V_7 -> V_47 = V_48 ;
break;
case 1 :
V_7 -> V_47 = V_49 ;
break;
case 2 :
V_7 -> V_47 = V_50 ;
break;
case 3 :
V_7 -> V_47 = V_51 ;
break;
case 4 :
V_7 -> V_47 = V_52 ;
break;
case 5 :
V_7 -> V_47 = V_53 ;
break;
case 6 :
V_7 -> V_47 = V_54 ;
break;
}
V_9 = F_9 ( V_4 , 0x0225b , V_15 , 2 ) ;
if ( V_9 )
goto error;
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
case 5 :
V_7 -> V_55 = V_61 ;
break;
}
switch ( ( V_15 [ 1 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_62 = V_63 ;
break;
case 1 :
V_7 -> V_62 = V_64 ;
break;
case 2 :
V_7 -> V_62 = V_65 ;
break;
case 3 :
V_7 -> V_62 = V_66 ;
break;
}
V_9 = F_10 ( V_4 , 0x020b5 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 4 ) & 0x01 ) {
case 0 :
V_7 -> V_67 = V_68 ;
break;
case 1 :
V_7 -> V_67 = V_69 ;
break;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_4 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 1 ] ;
* V_70 = 0 ;
V_9 = F_10 ( V_4 , 0x02010 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] & 0x07 ) == 6 ) {
if ( ( ( V_15 [ 0 ] >> 5 ) & 0x01 ) == 1 ) {
* V_70 |= V_71 | V_72 |
V_73 | V_74 | V_75 ;
} else {
* V_70 |= V_71 | V_72 |
V_73 | V_74 ;
}
}
F_2 ( & V_4 -> V_24 -> V_25 , L_6 , V_26 , V_15 [ 0 ] ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 4 ] ;
unsigned int V_77 ;
* V_76 = 0 ;
V_9 = F_9 ( V_4 , 0x02039 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] >> 4 ) & 0x01 ) {
V_77 = ( V_15 [ 0 ] & 0x0f ) << 24 | V_15 [ 1 ] << 16 |
V_15 [ 2 ] << 8 | V_15 [ 3 ] ;
if ( V_77 )
* V_76 = V_77 * 64 / 16588800 ;
}
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 ,
T_5 * V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_5 V_79 ;
V_9 = F_9 ( V_4 , 0x02026 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_79 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
V_79 = ~ V_79 & 0x0fff ;
* V_78 = V_79 * 0xffff / 0x0fff ;
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_2 , T_5 * V_80 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_5 V_79 ;
V_9 = F_9 ( V_4 , 0x02028 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_79 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
#define F_15 15151336
if ( V_79 )
* V_80 = ( F_16 ( V_79 ) - F_15 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_80 = 0 ;
F_2 ( & V_4 -> V_24 -> V_25 , L_7 , V_26 , * V_80 ,
V_79 ) ;
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_17 ( struct V_1 * V_2 , T_1 * V_81 )
{
* V_81 = 0 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 , V_10 ;
struct V_18 V_19 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x02069 , 0x00 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( & V_4 -> V_24 -> V_25 , L_8 , V_26 ) ;
for ( V_10 = 0 ; V_10 < F_3 ( V_19 ) ; V_10 ++ ) {
V_9 = F_4 ( V_4 , V_19 [ V_10 ] . V_35 , V_19 [ V_10 ] . V_36 ,
V_19 [ V_10 ] . V_37 ) ;
if ( V_9 )
goto error;
}
V_4 -> V_33 = V_82 ;
return V_9 ;
error:
F_2 ( & V_4 -> V_24 -> V_25 , L_5 , V_26 , V_9 ) ;
return V_9 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_83 * V_84 )
{
V_84 -> V_85 = 1500 ;
V_84 -> V_86 = V_2 -> V_30 . V_87 . V_88 * 2 ;
V_84 -> V_89 = ( V_2 -> V_30 . V_87 . V_88 * 2 ) + 1 ;
return 0 ;
}
