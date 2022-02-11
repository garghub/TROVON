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
F_2 ( L_1 , V_24 , V_7 -> V_25 , V_7 -> V_26 ) ;
switch ( V_7 -> V_26 ) {
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
return - V_27 ;
}
V_9 = F_3 ( V_2 ) ;
if ( V_9 )
goto error;
if ( V_2 -> V_28 . V_29 . V_30 )
V_2 -> V_28 . V_29 . V_30 ( V_2 ) ;
if ( V_4 -> V_31 != V_32 ) {
for ( V_10 = 0 ; V_10 < F_4 ( V_19 ) ; V_10 ++ ) {
V_9 = F_5 ( V_4 , V_19 [ V_10 ] . V_33 ,
V_19 [ V_10 ] . V_34 , V_19 [ V_10 ] . V_35 ) ;
if ( V_9 )
goto error;
}
}
V_4 -> V_31 = V_32 ;
if ( V_2 -> V_28 . V_29 . V_36 ) {
V_9 = V_2 -> V_28 . V_29 . V_36 ( V_2 , & V_12 ) ;
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
V_9 = F_7 ( V_4 , 0x020b6 , V_15 , 3 ) ;
if ( V_9 )
goto error;
V_9 = F_7 ( V_4 , 0x0209f , V_17 [ V_11 ] , 5 ) ;
if ( V_9 )
goto error;
V_9 = F_5 ( V_4 , 0x020d7 , V_16 << 6 , 0xc0 ) ;
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
V_9 = F_10 ( V_4 , 0x0205c , V_15 , 2 ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_37 = V_38 ;
break;
case 1 :
V_7 -> V_37 = V_39 ;
break;
case 2 :
V_7 -> V_37 = V_40 ;
break;
case 3 :
V_7 -> V_37 = V_41 ;
break;
case 4 :
V_7 -> V_37 = V_42 ;
break;
case 5 :
V_7 -> V_37 = V_43 ;
break;
}
switch ( ( V_15 [ 1 ] >> 4 ) & 0x07 ) {
case 0 :
V_7 -> V_44 = V_45 ;
break;
case 1 :
V_7 -> V_44 = V_46 ;
break;
case 2 :
V_7 -> V_44 = V_47 ;
break;
case 3 :
V_7 -> V_44 = V_48 ;
break;
case 4 :
V_7 -> V_44 = V_49 ;
break;
case 5 :
V_7 -> V_44 = V_50 ;
break;
case 6 :
V_7 -> V_44 = V_51 ;
break;
}
V_9 = F_10 ( V_4 , 0x0225b , V_15 , 2 ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_52 = V_53 ;
break;
case 1 :
V_7 -> V_52 = V_54 ;
break;
case 2 :
V_7 -> V_52 = V_55 ;
break;
case 3 :
V_7 -> V_52 = V_56 ;
break;
case 4 :
V_7 -> V_52 = V_57 ;
break;
case 5 :
V_7 -> V_52 = V_58 ;
break;
}
switch ( ( V_15 [ 1 ] >> 0 ) & 0x07 ) {
case 0 :
V_7 -> V_59 = V_60 ;
break;
case 1 :
V_7 -> V_59 = V_61 ;
break;
case 2 :
V_7 -> V_59 = V_62 ;
break;
case 3 :
V_7 -> V_59 = V_63 ;
break;
}
V_9 = F_11 ( V_4 , 0x020b5 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
switch ( ( V_15 [ 0 ] >> 4 ) & 0x01 ) {
case 0 :
V_7 -> V_64 = V_65 ;
break;
case 1 :
V_7 -> V_64 = V_66 ;
break;
}
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , T_4 * V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 1 ] ;
* V_67 = 0 ;
V_9 = F_11 ( V_4 , 0x02010 , & V_15 [ 0 ] ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] & 0x07 ) == 6 ) {
if ( ( ( V_15 [ 0 ] >> 5 ) & 0x01 ) == 1 ) {
* V_67 |= V_68 | V_69 |
V_70 | V_71 | V_72 ;
} else {
* V_67 |= V_68 | V_69 |
V_70 | V_71 ;
}
}
F_2 ( L_4 , V_24 , V_15 [ 0 ] ) ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_73 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 4 ] ;
unsigned int V_74 ;
* V_73 = 0 ;
V_9 = F_10 ( V_4 , 0x02039 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
if ( ( V_15 [ 0 ] >> 4 ) & 0x01 ) {
V_74 = ( V_15 [ 0 ] & 0x0f ) << 24 | V_15 [ 1 ] << 16 |
V_15 [ 2 ] << 8 | V_15 [ 3 ] ;
if ( V_74 )
* V_73 = V_74 * 64 / 16588800 ;
}
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_14 ( struct V_1 * V_2 ,
T_5 * V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_5 V_76 ;
V_9 = F_10 ( V_4 , 0x02026 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_76 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
V_76 = ~ V_76 & 0x0fff ;
* V_75 = V_76 * 0xffff / 0x0fff ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_15 ( struct V_1 * V_2 , T_5 * V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 ;
T_3 V_15 [ 2 ] ;
T_5 V_76 ;
V_9 = F_10 ( V_4 , 0x02028 , V_15 , sizeof( V_15 ) ) ;
if ( V_9 )
goto error;
V_76 = ( V_15 [ 0 ] & 0x0f ) << 8 | V_15 [ 1 ] ;
#define F_16 15151336
if ( V_76 )
* V_77 = ( F_17 ( V_76 ) - F_16 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_77 = 0 ;
F_2 ( L_5 , V_24 , * V_77 , V_76 ) ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_18 ( struct V_1 * V_2 , T_1 * V_78 )
{
* V_78 = 0 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
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
F_2 ( L_6 , V_24 ) ;
for ( V_10 = 0 ; V_10 < F_4 ( V_19 ) ; V_10 ++ ) {
V_9 = F_5 ( V_4 , V_19 [ V_10 ] . V_33 , V_19 [ V_10 ] . V_34 ,
V_19 [ V_10 ] . V_35 ) ;
if ( V_9 )
goto error;
}
V_4 -> V_31 = V_79 ;
return V_9 ;
error:
F_2 ( L_3 , V_24 , V_9 ) ;
return V_9 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
V_81 -> V_82 = 1500 ;
V_81 -> V_83 = V_2 -> V_28 . V_84 . V_85 * 2 ;
V_81 -> V_86 = ( V_2 -> V_28 . V_84 . V_85 * 2 ) + 1 ;
return 0 ;
}
