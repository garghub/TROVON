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
{ 0x1c , 0xb3 , 0x33 , 0x33 , 0x33 } ,
{ 0x17 , 0xea , 0xaa , 0xaa , 0xaa } ,
{ 0x14 , 0x80 , 0x00 , 0x00 , 0x00 } ,
{ 0x11 , 0xf0 , 0x00 , 0x00 , 0x00 } ,
} ;
struct V_19 V_20 [] = {
{ 0x00080 , 0x02 , 0xff } ,
{ 0x00081 , 0x20 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x02069 , 0x01 , 0xff } ,
{ 0x0207f , 0x2a , 0xff } ,
{ 0x02082 , 0x0a , 0xff } ,
{ 0x02083 , 0x0a , 0xff } ,
{ 0x020cb , V_6 -> V_21 . V_22 << 6 , 0x40 } ,
{ 0x02070 , V_6 -> V_21 . V_23 , 0xff } ,
{ 0x020b5 , V_6 -> V_21 . V_24 << 4 , 0x10 } ,
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
F_2 ( L_1 , V_25 , V_9 -> V_26 , V_9 -> V_27 ) ;
V_11 = F_3 ( V_2 ) ;
if ( V_11 )
goto error;
if ( V_2 -> V_28 . V_29 . V_30 )
V_2 -> V_28 . V_29 . V_30 ( V_2 , V_4 ) ;
if ( V_6 -> V_31 != V_32 ) {
for ( V_12 = 0 ; V_12 < F_4 ( V_20 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_20 [ V_12 ] . V_33 ,
V_20 [ V_12 ] . V_34 , V_20 [ V_12 ] . V_35 ) ;
if ( V_11 )
goto error;
}
}
V_6 -> V_31 = V_32 ;
switch ( V_9 -> V_27 ) {
case 5000000 :
V_13 = V_6 -> V_21 . V_36 ;
V_12 = 0 ;
V_17 = 3 ;
break;
case 6000000 :
V_13 = V_6 -> V_21 . V_37 ;
V_12 = 1 ;
V_17 = 2 ;
break;
case 7000000 :
V_13 = V_6 -> V_21 . V_38 ;
V_12 = 2 ;
V_17 = 1 ;
break;
case 8000000 :
V_13 = V_6 -> V_21 . V_39 ;
V_12 = 3 ;
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
V_11 = F_7 ( V_6 , 0x020b6 , V_16 , 3 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_6 , 0x0209f , V_18 [ V_12 ] , 5 ) ;
if ( V_11 )
goto error;
V_11 = F_5 ( V_6 , 0x020d7 , V_17 << 6 , 0xc0 ) ;
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
struct V_3 * V_41 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
V_11 = F_10 ( V_6 , 0x0205c , V_16 , 2 ) ;
if ( V_11 )
goto error;
switch ( ( V_16 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_42 = V_43 ;
break;
case 1 :
V_9 -> V_42 = V_44 ;
break;
case 2 :
V_9 -> V_42 = V_45 ;
break;
case 3 :
V_9 -> V_42 = V_46 ;
break;
case 4 :
V_9 -> V_42 = V_47 ;
break;
case 5 :
V_9 -> V_42 = V_48 ;
break;
}
switch ( ( V_16 [ 1 ] >> 4 ) & 0x07 ) {
case 0 :
V_9 -> V_49 = V_50 ;
break;
case 1 :
V_9 -> V_49 = V_51 ;
break;
case 2 :
V_9 -> V_49 = V_52 ;
break;
case 3 :
V_9 -> V_49 = V_53 ;
break;
case 4 :
V_9 -> V_49 = V_54 ;
break;
case 5 :
V_9 -> V_49 = V_55 ;
break;
case 6 :
V_9 -> V_49 = V_56 ;
break;
}
V_11 = F_10 ( V_6 , 0x0225b , V_16 , 2 ) ;
if ( V_11 )
goto error;
switch ( ( V_16 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_57 = V_58 ;
break;
case 1 :
V_9 -> V_57 = V_59 ;
break;
case 2 :
V_9 -> V_57 = V_60 ;
break;
case 3 :
V_9 -> V_57 = V_61 ;
break;
case 4 :
V_9 -> V_57 = V_62 ;
break;
case 5 :
V_9 -> V_57 = V_63 ;
break;
}
switch ( ( V_16 [ 1 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_64 = V_65 ;
break;
case 1 :
V_9 -> V_64 = V_66 ;
break;
case 2 :
V_9 -> V_64 = V_67 ;
break;
case 3 :
V_9 -> V_64 = V_68 ;
break;
}
V_11 = F_11 ( V_6 , 0x020b5 , & V_16 [ 0 ] ) ;
if ( V_11 )
goto error;
switch ( ( V_16 [ 0 ] >> 4 ) & 0x01 ) {
case 0 :
V_9 -> V_69 = V_70 ;
break;
case 1 :
V_9 -> V_69 = V_71 ;
break;
}
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_4 * V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 1 ] ;
* V_72 = 0 ;
V_11 = F_11 ( V_6 , 0x02010 , & V_16 [ 0 ] ) ;
if ( V_11 )
goto error;
if ( ( V_16 [ 0 ] & 0x07 ) == 6 ) {
if ( ( ( V_16 [ 0 ] >> 5 ) & 0x01 ) == 1 ) {
* V_72 |= V_73 | V_74 |
V_75 | V_76 | V_77 ;
} else {
* V_72 |= V_73 | V_74 |
V_75 | V_76 ;
}
}
F_2 ( L_3 , V_25 , V_16 [ 0 ] ) ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 4 ] ;
unsigned int V_79 ;
* V_78 = 0 ;
V_11 = F_10 ( V_6 , 0x02039 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
if ( ( V_16 [ 0 ] >> 4 ) & 0x01 ) {
V_79 = ( V_16 [ 0 ] & 0x0f ) << 24 | V_16 [ 1 ] << 16 |
V_16 [ 2 ] << 8 | V_16 [ 3 ] ;
if ( V_79 )
* V_78 = V_79 * 64 / 16588800 ;
}
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_14 ( struct V_1 * V_2 ,
T_5 * V_80 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
T_5 V_81 ;
V_11 = F_10 ( V_6 , 0x02026 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
V_81 = ( V_16 [ 0 ] & 0x0f ) << 8 | V_16 [ 1 ] ;
V_81 = ~ V_81 & 0x0fff ;
* V_80 = V_81 * 0xffff / 0x0fff ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_15 ( struct V_1 * V_2 , T_5 * V_82 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
T_3 V_16 [ 2 ] ;
T_5 V_81 ;
V_11 = F_10 ( V_6 , 0x02028 , V_16 , sizeof( V_16 ) ) ;
if ( V_11 )
goto error;
V_81 = ( V_16 [ 0 ] & 0x0f ) << 8 | V_16 [ 1 ] ;
#define F_16 15151336
if ( V_81 )
* V_82 = ( F_17 ( V_81 ) - F_16 ) / ( ( 1 << 24 )
/ 100 ) ;
else
* V_82 = 0 ;
F_2 ( L_4 , V_25 , * V_82 , V_81 ) ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_18 ( struct V_1 * V_2 , T_1 * V_83 )
{
* V_83 = 0 ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 , V_12 ;
struct V_19 V_20 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x02069 , 0x00 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( L_5 , V_25 ) ;
for ( V_12 = 0 ; V_12 < F_4 ( V_20 ) ; V_12 ++ ) {
V_11 = F_5 ( V_6 , V_20 [ V_12 ] . V_33 , V_20 [ V_12 ] . V_34 ,
V_20 [ V_12 ] . V_35 ) ;
if ( V_11 )
goto error;
}
V_6 -> V_31 = V_84 ;
return V_11 ;
error:
F_2 ( L_2 , V_25 , V_11 ) ;
return V_11 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
V_86 -> V_87 = 1500 ;
V_86 -> V_88 = V_2 -> V_28 . V_89 . V_90 * 2 ;
V_86 -> V_91 = ( V_2 -> V_28 . V_89 . V_90 * 2 ) + 1 ;
return 0 ;
}
