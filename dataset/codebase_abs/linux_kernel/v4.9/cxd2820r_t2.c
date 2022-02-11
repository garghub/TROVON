int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 , V_12 ;
unsigned int V_13 ;
T_1 V_14 ;
T_2 V_15 [ 3 ] , V_16 ;
T_2 V_17 [] [ 5 ] = {
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
{ 0x020cb , V_4 -> V_20 << 6 , 0x40 } ,
{ 0x02070 , V_4 -> V_21 , 0xff } ,
{ 0x02071 , ! V_4 -> V_22 << 6 , 0x40 } ,
{ 0x020b5 , V_4 -> V_23 << 4 , 0x10 } ,
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
F_2 ( & V_7 -> V_24 ,
L_1 ,
V_9 -> V_25 , V_9 -> V_26 , V_9 -> V_27 ,
V_9 -> V_28 , V_9 -> V_29 , V_9 -> V_30 ) ;
switch ( V_9 -> V_28 ) {
case 5000000 :
V_12 = 0 ;
V_16 = 3 ;
break;
case 6000000 :
V_12 = 1 ;
V_16 = 2 ;
break;
case 7000000 :
V_12 = 2 ;
V_16 = 1 ;
break;
case 8000000 :
V_12 = 3 ;
V_16 = 0 ;
break;
default:
return - V_31 ;
}
if ( V_2 -> V_32 . V_33 . V_34 )
V_2 -> V_32 . V_33 . V_34 ( V_2 ) ;
if ( V_4 -> V_25 != V_35 ) {
V_11 = F_3 ( V_4 , V_19 , F_4 ( V_19 ) ) ;
if ( V_11 )
goto error;
}
V_4 -> V_25 = V_35 ;
if ( V_2 -> V_32 . V_33 . V_36 ) {
V_11 = V_2 -> V_32 . V_33 . V_36 ( V_2 , & V_14 ) ;
if ( V_11 )
goto error;
F_2 ( & V_7 -> V_24 , L_2 , V_14 ) ;
} else {
V_11 = - V_31 ;
goto error;
}
V_13 = F_5 ( ( V_37 ) V_14 * 0x1000000 , V_38 ) ;
V_15 [ 0 ] = ( V_13 >> 16 ) & 0xff ;
V_15 [ 1 ] = ( V_13 >> 8 ) & 0xff ;
V_15 [ 2 ] = ( V_13 >> 0 ) & 0xff ;
V_11 = F_6 ( V_4 -> V_39 [ 0 ] , 0x20b6 , V_15 , 3 ) ;
if ( V_11 )
goto error;
if ( V_9 -> V_30 > 255 ) {
F_2 ( & V_7 -> V_24 , L_3 ) ;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x23ad , 0x00 ) ;
if ( V_11 )
goto error;
} else {
F_2 ( & V_7 -> V_24 , L_4 ) ;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x23af , V_9 -> V_30 & 0xff ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x23ad , 0x01 ) ;
if ( V_11 )
goto error;
}
V_11 = F_6 ( V_4 -> V_39 [ 0 ] , 0x209f , V_17 [ V_12 ] , 5 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_4 -> V_39 [ 0 ] , 0x20d7 , 0xc0 , V_16 << 6 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x00ff , 0x08 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x00fe , 0x01 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_5 , V_11 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
unsigned int V_13 ;
T_2 V_15 [ 2 ] ;
F_2 ( & V_7 -> V_24 , L_6 ) ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x205c , V_15 , 2 ) ;
if ( V_11 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_40 = V_41 ;
break;
case 1 :
V_9 -> V_40 = V_42 ;
break;
case 2 :
V_9 -> V_40 = V_43 ;
break;
case 3 :
V_9 -> V_40 = V_44 ;
break;
case 4 :
V_9 -> V_40 = V_45 ;
break;
case 5 :
V_9 -> V_40 = V_46 ;
break;
}
switch ( ( V_15 [ 1 ] >> 4 ) & 0x07 ) {
case 0 :
V_9 -> V_47 = V_48 ;
break;
case 1 :
V_9 -> V_47 = V_49 ;
break;
case 2 :
V_9 -> V_47 = V_50 ;
break;
case 3 :
V_9 -> V_47 = V_51 ;
break;
case 4 :
V_9 -> V_47 = V_52 ;
break;
case 5 :
V_9 -> V_47 = V_53 ;
break;
case 6 :
V_9 -> V_47 = V_54 ;
break;
}
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x225b , V_15 , 2 ) ;
if ( V_11 )
goto error;
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_55 = V_56 ;
break;
case 1 :
V_9 -> V_55 = V_57 ;
break;
case 2 :
V_9 -> V_55 = V_58 ;
break;
case 3 :
V_9 -> V_55 = V_59 ;
break;
case 4 :
V_9 -> V_55 = V_60 ;
break;
case 5 :
V_9 -> V_55 = V_61 ;
break;
}
switch ( ( V_15 [ 1 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_26 = V_62 ;
break;
case 1 :
V_9 -> V_26 = V_63 ;
break;
case 2 :
V_9 -> V_26 = V_64 ;
break;
case 3 :
V_9 -> V_26 = V_65 ;
break;
}
V_11 = F_11 ( V_4 -> V_39 [ 0 ] , 0x20b5 , & V_13 ) ;
if ( V_11 )
goto error;
switch ( ( V_13 >> 4 ) & 0x01 ) {
case 0 :
V_9 -> V_29 = V_66 ;
break;
case 1 :
V_9 -> V_29 = V_67 ;
break;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_5 , V_11 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , enum V_68 * V_69 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_8 * V_9 = & V_2 -> V_10 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
unsigned int V_13 , V_70 , V_71 ;
T_2 V_15 [ 4 ] ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x2010 , & V_15 [ 0 ] , 1 ) ;
if ( V_11 )
goto error;
V_70 = ( V_15 [ 0 ] >> 0 ) & 0x07 ;
V_71 = ( V_15 [ 0 ] >> 5 ) & 0x01 ;
if ( V_70 == 6 && V_71 == 1 ) {
* V_69 = V_72 | V_73 |
V_74 | V_75 | V_76 ;
} else if ( V_70 == 6 || V_71 == 1 ) {
* V_69 = V_72 | V_73 |
V_74 | V_75 ;
} else {
* V_69 = 0 ;
}
F_2 ( & V_7 -> V_24 , L_7 ,
* V_69 , 1 , V_15 , V_70 , V_71 ) ;
if ( * V_69 & V_72 ) {
unsigned int V_77 ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x2026 , V_15 , 2 ) ;
if ( V_11 )
goto error;
V_13 = V_15 [ 0 ] << 8 | V_15 [ 1 ] << 0 ;
V_13 = ~ V_13 & 0x0fff ;
V_77 = V_13 << 4 | V_13 >> 8 ;
V_9 -> V_77 . V_78 = 1 ;
V_9 -> V_77 . V_79 [ 0 ] . V_80 = V_81 ;
V_9 -> V_77 . V_79 [ 0 ] . V_82 = V_77 ;
} else {
V_9 -> V_77 . V_78 = 1 ;
V_9 -> V_77 . V_79 [ 0 ] . V_80 = V_83 ;
}
if ( * V_69 & V_74 ) {
unsigned int V_84 ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x2028 , V_15 , 2 ) ;
if ( V_11 )
goto error;
V_13 = V_15 [ 0 ] << 8 | V_15 [ 1 ] << 0 ;
V_13 = V_13 & 0x0fff ;
#define F_13 15151336
if ( V_13 )
V_84 = F_14 ( ( V_37 ) ( F_15 ( V_13 )
- F_13 ) * 10000 ,
( 1 << 24 ) ) ;
else
V_84 = 0 ;
V_9 -> V_84 . V_78 = 1 ;
V_9 -> V_84 . V_79 [ 0 ] . V_80 = V_85 ;
V_9 -> V_84 . V_79 [ 0 ] . V_86 = V_84 ;
} else {
V_9 -> V_84 . V_78 = 1 ;
V_9 -> V_84 . V_79 [ 0 ] . V_80 = V_83 ;
}
if ( * V_69 & V_75 ) {
unsigned int V_87 ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x2039 , V_15 , 4 ) ;
if ( V_11 )
goto error;
if ( ( V_15 [ 0 ] >> 4 ) & 0x01 ) {
V_87 = V_15 [ 0 ] << 24 | V_15 [ 1 ] << 16 |
V_15 [ 2 ] << 8 | V_15 [ 3 ] << 0 ;
V_87 &= 0x0fffffff ;
} else {
V_87 = 0 ;
}
V_4 -> V_87 += V_87 ;
V_9 -> V_87 . V_78 = 1 ;
V_9 -> V_87 . V_79 [ 0 ] . V_80 = V_88 ;
V_9 -> V_87 . V_79 [ 0 ] . V_82 = V_4 -> V_87 ;
} else {
V_9 -> V_87 . V_78 = 1 ;
V_9 -> V_87 . V_79 [ 0 ] . V_80 = V_83 ;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_5 , V_11 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
struct V_18 V_19 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x02069 , 0x00 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( & V_7 -> V_24 , L_6 ) ;
V_11 = F_3 ( V_4 , V_19 , F_4 ( V_19 ) ) ;
if ( V_11 )
goto error;
V_4 -> V_25 = V_89 ;
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_5 , V_11 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
V_91 -> V_92 = 1500 ;
V_91 -> V_93 = V_2 -> V_32 . V_94 . V_95 * 2 ;
V_91 -> V_96 = ( V_2 -> V_32 . V_94 . V_95 * 2 ) + 1 ;
return 0 ;
}
