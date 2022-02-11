int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
unsigned int V_12 ;
T_1 V_13 [ 2 ] ;
T_2 V_14 ;
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
{ 0x1001f , V_4 -> V_17 << 7 , 0x80 } ,
{ 0x10070 , V_4 -> V_18 , 0xff } ,
{ 0x10071 , ! V_4 -> V_19 << 4 , 0x10 } ,
} ;
F_2 ( & V_7 -> V_20 ,
L_1 ,
V_9 -> V_21 , V_9 -> V_22 , V_9 -> V_23 ,
V_9 -> V_24 , V_9 -> V_25 ) ;
if ( V_2 -> V_26 . V_27 . V_28 )
V_2 -> V_26 . V_27 . V_28 ( V_2 ) ;
if ( V_4 -> V_21 != V_29 ) {
V_11 = F_3 ( V_4 , V_16 , F_4 ( V_16 ) ) ;
if ( V_11 )
goto error;
}
V_4 -> V_21 = V_29 ;
V_4 -> V_30 = false ;
if ( V_2 -> V_26 . V_27 . V_31 ) {
V_11 = V_2 -> V_26 . V_27 . V_31 ( V_2 , & V_14 ) ;
if ( V_11 )
goto error;
F_2 ( & V_7 -> V_20 , L_2 , V_14 ) ;
} else {
V_11 = - V_32 ;
goto error;
}
V_12 = 0x4000 - F_5 ( ( V_33 ) V_14 * 0x4000 , V_34 ) ;
V_13 [ 0 ] = ( V_12 >> 8 ) & 0xff ;
V_13 [ 1 ] = ( V_12 >> 0 ) & 0xff ;
V_11 = F_6 ( V_4 -> V_35 [ 1 ] , 0x0042 , V_13 , 2 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_35 [ 0 ] , 0x00ff , 0x08 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_35 [ 0 ] , 0x00fe , 0x01 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_20 , L_3 , V_11 ) ;
return V_11 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
unsigned int V_12 ;
T_1 V_13 [ 2 ] ;
F_2 ( & V_7 -> V_20 , L_4 ) ;
V_11 = F_9 ( V_4 -> V_35 [ 1 ] , 0x001a , V_13 , 2 ) ;
if ( V_11 )
goto error;
V_9 -> V_24 = 2500 * ( ( V_13 [ 0 ] & 0x0f ) << 8 | V_13 [ 1 ] ) ;
V_11 = F_10 ( V_4 -> V_35 [ 1 ] , 0x0019 , & V_12 ) ;
if ( V_11 )
goto error;
switch ( ( V_12 >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_22 = V_36 ;
break;
case 1 :
V_9 -> V_22 = V_37 ;
break;
case 2 :
V_9 -> V_22 = V_38 ;
break;
case 3 :
V_9 -> V_22 = V_39 ;
break;
case 4 :
V_9 -> V_22 = V_40 ;
break;
}
switch ( ( V_12 >> 7 ) & 0x01 ) {
case 0 :
V_9 -> V_25 = V_41 ;
break;
case 1 :
V_9 -> V_25 = V_42 ;
break;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_20 , L_3 , V_11 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 , enum V_43 * V_44 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
unsigned int V_12 , V_45 , V_46 ;
T_1 V_13 [ 3 ] ;
V_11 = F_9 ( V_4 -> V_35 [ 1 ] , 0x0088 , & V_13 [ 0 ] , 1 ) ;
if ( V_11 )
goto error;
V_11 = F_9 ( V_4 -> V_35 [ 1 ] , 0x0073 , & V_13 [ 1 ] , 1 ) ;
if ( V_11 )
goto error;
V_45 = ( V_13 [ 0 ] >> 0 ) & 0x01 ;
V_46 = ( V_13 [ 1 ] >> 3 ) & 0x01 ;
if ( V_45 == 1 && V_46 == 1 ) {
* V_44 = V_47 | V_48 |
V_49 | V_50 | V_51 ;
} else if ( V_45 == 1 || V_46 == 1 ) {
* V_44 = V_47 | V_48 |
V_49 | V_50 ;
} else {
* V_44 = 0 ;
}
F_2 ( & V_7 -> V_20 , L_5 ,
* V_44 , 2 , V_13 , V_45 , V_46 ) ;
if ( * V_44 & V_47 ) {
unsigned int V_52 ;
V_11 = F_9 ( V_4 -> V_35 [ 1 ] , 0x0049 , V_13 , 2 ) ;
if ( V_11 )
goto error;
V_12 = V_13 [ 0 ] << 8 | V_13 [ 1 ] << 0 ;
V_12 = 511 - F_12 ( V_12 , 9 ) ;
V_52 = V_12 << 6 | V_12 >> 4 ;
V_9 -> V_52 . V_53 = 1 ;
V_9 -> V_52 . V_54 [ 0 ] . V_55 = V_56 ;
V_9 -> V_52 . V_54 [ 0 ] . V_57 = V_52 ;
} else {
V_9 -> V_52 . V_53 = 1 ;
V_9 -> V_52 . V_54 [ 0 ] . V_55 = V_58 ;
}
if ( * V_44 & V_49 ) {
unsigned int V_59 , V_60 , V_61 ;
V_11 = F_10 ( V_4 -> V_35 [ 1 ] , 0x0019 , & V_12 ) ;
if ( V_11 )
goto error;
if ( ( ( V_12 >> 0 ) & 0x03 ) % 2 ) {
V_60 = 8750 ;
V_61 = 650 ;
} else {
V_60 = 9500 ;
V_61 = 760 ;
}
V_11 = F_10 ( V_4 -> V_35 [ 1 ] , 0x004d , & V_12 ) ;
if ( V_11 )
goto error;
#define F_13 24204406
if ( V_12 )
V_59 = F_14 ( ( V_33 ) ( F_15 ( V_61 ) - F_15 ( V_12 ) )
* V_60 , F_13 ) ;
else
V_59 = 0 ;
V_9 -> V_59 . V_53 = 1 ;
V_9 -> V_59 . V_54 [ 0 ] . V_55 = V_62 ;
V_9 -> V_59 . V_54 [ 0 ] . V_63 = V_59 ;
} else {
V_9 -> V_59 . V_53 = 1 ;
V_9 -> V_59 . V_54 [ 0 ] . V_55 = V_58 ;
}
if ( * V_44 & V_50 ) {
unsigned int V_64 ;
bool V_65 ;
if ( V_4 -> V_30 ) {
V_11 = F_9 ( V_4 -> V_35 [ 1 ] , 0x0076 , V_13 , 3 ) ;
if ( V_11 )
goto error;
if ( ( V_13 [ 2 ] >> 7 ) & 0x01 ) {
V_64 = V_13 [ 2 ] << 16 | V_13 [ 1 ] << 8 |
V_13 [ 0 ] << 0 ;
V_64 &= 0x0fffff ;
V_65 = true ;
} else {
V_64 = 0 ;
V_65 = false ;
}
} else {
V_64 = 0 ;
V_65 = true ;
}
if ( V_65 ) {
V_11 = F_7 ( V_4 -> V_35 [ 1 ] , 0x0079 , 0x01 ) ;
if ( V_11 )
goto error;
V_4 -> V_30 = true ;
}
V_4 -> V_64 += V_64 ;
V_9 -> V_64 . V_53 = 1 ;
V_9 -> V_64 . V_54 [ 0 ] . V_55 = V_66 ;
V_9 -> V_64 . V_54 [ 0 ] . V_57 = V_4 -> V_64 ;
} else {
V_9 -> V_64 . V_53 = 1 ;
V_9 -> V_64 . V_54 [ 0 ] . V_55 = V_58 ;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_20 , L_3 , V_11 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
F_2 ( & V_7 -> V_20 , L_4 ) ;
V_11 = F_7 ( V_4 -> V_35 [ 0 ] , 0x0085 , 0x07 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_20 , L_3 , V_11 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
struct V_15 V_16 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( & V_7 -> V_20 , L_4 ) ;
V_4 -> V_21 = V_67 ;
V_11 = F_3 ( V_4 , V_16 , F_4 ( V_16 ) ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_20 , L_3 , V_11 ) ;
return V_11 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
V_69 -> V_70 = 500 ;
V_69 -> V_71 = 0 ;
V_69 -> V_72 = 0 ;
return 0 ;
}
