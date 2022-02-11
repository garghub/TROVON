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
{ 0x17 , 0xea , 0xaa , 0xaa , 0xaa } ,
{ 0x14 , 0x80 , 0x00 , 0x00 , 0x00 } ,
{ 0x11 , 0xf0 , 0x00 , 0x00 , 0x00 } ,
} ;
T_2 V_18 [] [ 2 ] = {
{ 0x1f , 0xdc } ,
{ 0x12 , 0xf8 } ,
{ 0x01 , 0xe0 } ,
} ;
struct V_19 V_20 [] = {
{ 0x00080 , 0x00 , 0xff } ,
{ 0x00081 , 0x03 , 0xff } ,
{ 0x00085 , 0x07 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00070 , V_4 -> V_21 , 0xff } ,
{ 0x00071 , ! V_4 -> V_22 << 4 , 0x10 } ,
{ 0x000cb , V_4 -> V_23 << 6 , 0x40 } ,
{ 0x000a5 , 0x00 , 0x01 } ,
{ 0x00082 , 0x20 , 0x60 } ,
{ 0x000c2 , 0xc3 , 0xff } ,
{ 0x0016a , 0x50 , 0xff } ,
{ 0x00427 , 0x41 , 0xff } ,
} ;
F_2 ( & V_7 -> V_24 ,
L_1 ,
V_9 -> V_25 , V_9 -> V_26 , V_9 -> V_27 ,
V_9 -> V_28 , V_9 -> V_29 ) ;
switch ( V_9 -> V_28 ) {
case 6000000 :
V_12 = 0 ;
V_16 = 2 ;
break;
case 7000000 :
V_12 = 1 ;
V_16 = 1 ;
break;
case 8000000 :
V_12 = 2 ;
V_16 = 0 ;
break;
default:
return - V_30 ;
}
if ( V_2 -> V_31 . V_32 . V_33 )
V_2 -> V_31 . V_32 . V_33 ( V_2 ) ;
if ( V_4 -> V_25 != V_34 ) {
V_11 = F_3 ( V_4 , V_20 , F_4 ( V_20 ) ) ;
if ( V_11 )
goto error;
}
V_4 -> V_25 = V_34 ;
V_4 -> V_35 = false ;
if ( V_2 -> V_31 . V_32 . V_36 ) {
V_11 = V_2 -> V_31 . V_32 . V_36 ( V_2 , & V_14 ) ;
if ( V_11 )
goto error;
F_2 ( & V_7 -> V_24 , L_2 , V_14 ) ;
} else {
V_11 = - V_30 ;
goto error;
}
V_13 = F_5 ( ( V_37 ) V_14 * 0x1000000 , V_38 ) ;
V_15 [ 0 ] = ( V_13 >> 16 ) & 0xff ;
V_15 [ 1 ] = ( V_13 >> 8 ) & 0xff ;
V_15 [ 2 ] = ( V_13 >> 0 ) & 0xff ;
V_11 = F_6 ( V_4 -> V_39 [ 0 ] , 0x00b6 , V_15 , 3 ) ;
if ( V_11 )
goto error;
V_11 = F_6 ( V_4 -> V_39 [ 0 ] , 0x009f , V_17 [ V_12 ] , 5 ) ;
if ( V_11 )
goto error;
V_11 = F_7 ( V_4 -> V_39 [ 0 ] , 0x00d7 , 0xc0 , V_16 << 6 ) ;
if ( V_11 )
goto error;
V_11 = F_6 ( V_4 -> V_39 [ 0 ] , 0x00d9 , V_18 [ V_12 ] , 2 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_4 -> V_39 [ 0 ] , 0x00ff , 0x08 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_4 -> V_39 [ 0 ] , 0x00fe , 0x01 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_3 , V_11 ) ;
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
F_2 ( & V_7 -> V_24 , L_4 ) ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x002f , V_15 , sizeof( V_15 ) ) ;
if ( V_11 )
goto error;
switch ( ( V_15 [ 0 ] >> 6 ) & 0x03 ) {
case 0 :
V_9 -> V_26 = V_40 ;
break;
case 1 :
V_9 -> V_26 = V_41 ;
break;
case 2 :
V_9 -> V_26 = V_42 ;
break;
}
switch ( ( V_15 [ 1 ] >> 1 ) & 0x03 ) {
case 0 :
V_9 -> V_43 = V_44 ;
break;
case 1 :
V_9 -> V_43 = V_45 ;
break;
}
switch ( ( V_15 [ 1 ] >> 3 ) & 0x03 ) {
case 0 :
V_9 -> V_46 = V_47 ;
break;
case 1 :
V_9 -> V_46 = V_48 ;
break;
case 2 :
V_9 -> V_46 = V_49 ;
break;
case 3 :
V_9 -> V_46 = V_50 ;
break;
}
switch ( ( V_15 [ 0 ] >> 3 ) & 0x07 ) {
case 0 :
V_9 -> V_51 = V_52 ;
break;
case 1 :
V_9 -> V_51 = V_53 ;
break;
case 2 :
V_9 -> V_51 = V_54 ;
break;
case 3 :
V_9 -> V_51 = V_55 ;
break;
}
switch ( ( V_15 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_9 -> V_56 = V_57 ;
break;
case 1 :
V_9 -> V_56 = V_58 ;
break;
case 2 :
V_9 -> V_56 = V_59 ;
break;
case 3 :
V_9 -> V_56 = V_60 ;
break;
case 4 :
V_9 -> V_56 = V_61 ;
break;
}
switch ( ( V_15 [ 1 ] >> 5 ) & 0x07 ) {
case 0 :
V_9 -> V_62 = V_57 ;
break;
case 1 :
V_9 -> V_62 = V_58 ;
break;
case 2 :
V_9 -> V_62 = V_59 ;
break;
case 3 :
V_9 -> V_62 = V_60 ;
break;
case 4 :
V_9 -> V_62 = V_61 ;
break;
}
V_11 = F_11 ( V_4 -> V_39 [ 0 ] , 0x07c6 , & V_13 ) ;
if ( V_11 )
goto error;
switch ( ( V_13 >> 0 ) & 0x01 ) {
case 0 :
V_9 -> V_29 = V_63 ;
break;
case 1 :
V_9 -> V_29 = V_64 ;
break;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_3 , V_11 ) ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , enum V_65 * V_66 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
struct V_8 * V_9 = & V_2 -> V_10 ;
int V_11 ;
unsigned int V_13 , V_67 , V_68 ;
T_2 V_15 [ 3 ] ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x0010 , & V_15 [ 0 ] , 1 ) ;
if ( V_11 )
goto error;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x0073 , & V_15 [ 1 ] , 1 ) ;
if ( V_11 )
goto error;
V_67 = ( V_15 [ 0 ] >> 0 ) & 0x07 ;
V_68 = ( V_15 [ 1 ] >> 3 ) & 0x01 ;
if ( V_67 == 6 && V_68 == 1 ) {
* V_66 = V_69 | V_70 |
V_71 | V_72 | V_73 ;
} else if ( V_67 == 6 || V_68 == 1 ) {
* V_66 = V_69 | V_70 |
V_71 | V_72 ;
} else {
* V_66 = 0 ;
}
F_2 ( & V_7 -> V_24 , L_5 ,
* V_66 , 2 , V_15 , V_67 , V_68 ) ;
if ( * V_66 & V_69 ) {
unsigned int V_74 ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x0026 , V_15 , 2 ) ;
if ( V_11 )
goto error;
V_13 = V_15 [ 0 ] << 8 | V_15 [ 1 ] << 0 ;
V_13 = ~ V_13 & 0x0fff ;
V_74 = V_13 << 4 | V_13 >> 8 ;
V_9 -> V_74 . V_75 = 1 ;
V_9 -> V_74 . V_76 [ 0 ] . V_77 = V_78 ;
V_9 -> V_74 . V_76 [ 0 ] . V_79 = V_74 ;
} else {
V_9 -> V_74 . V_75 = 1 ;
V_9 -> V_74 . V_76 [ 0 ] . V_77 = V_80 ;
}
if ( * V_66 & V_71 ) {
unsigned int V_81 ;
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x002c , V_15 , 2 ) ;
if ( V_11 )
goto error;
V_13 = V_15 [ 0 ] << 8 | V_15 [ 1 ] << 0 ;
if ( V_13 )
V_81 = F_13 ( ( V_37 ) ( F_14 ( V_13 )
- F_14 ( 32000 - V_13 ) + 55532585 )
* 10000 , ( 1 << 24 ) ) ;
else
V_81 = 0 ;
V_9 -> V_81 . V_75 = 1 ;
V_9 -> V_81 . V_76 [ 0 ] . V_77 = V_82 ;
V_9 -> V_81 . V_76 [ 0 ] . V_83 = V_81 ;
} else {
V_9 -> V_81 . V_75 = 1 ;
V_9 -> V_81 . V_76 [ 0 ] . V_77 = V_80 ;
}
if ( * V_66 & V_72 ) {
unsigned int V_84 ;
bool V_85 ;
if ( V_4 -> V_35 ) {
V_11 = F_10 ( V_4 -> V_39 [ 0 ] , 0x0076 , V_15 , 3 ) ;
if ( V_11 )
goto error;
if ( ( V_15 [ 2 ] >> 7 ) & 0x01 ) {
V_84 = V_15 [ 2 ] << 16 | V_15 [ 1 ] << 8 |
V_15 [ 0 ] << 0 ;
V_84 &= 0x0fffff ;
V_85 = true ;
} else {
V_84 = 0 ;
V_85 = false ;
}
} else {
V_84 = 0 ;
V_85 = true ;
}
if ( V_85 ) {
V_11 = F_8 ( V_4 -> V_39 [ 0 ] , 0x0079 , 0x01 ) ;
if ( V_11 )
goto error;
V_4 -> V_35 = true ;
}
V_4 -> V_84 += V_84 ;
V_9 -> V_84 . V_75 = 1 ;
V_9 -> V_84 . V_76 [ 0 ] . V_77 = V_86 ;
V_9 -> V_84 . V_76 [ 0 ] . V_79 = V_4 -> V_84 ;
} else {
V_9 -> V_84 . V_75 = 1 ;
V_9 -> V_84 . V_76 [ 0 ] . V_77 = V_80 ;
}
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_3 , V_11 ) ;
return V_11 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
F_2 ( & V_7 -> V_24 , L_4 ) ;
V_11 = F_8 ( V_4 -> V_39 [ 0 ] , 0x0085 , 0x07 ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_3 , V_11 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 [ 0 ] ;
int V_11 ;
struct V_19 V_20 [] = {
{ 0x000ff , 0x1f , 0xff } ,
{ 0x00085 , 0x00 , 0xff } ,
{ 0x00088 , 0x01 , 0xff } ,
{ 0x00081 , 0x00 , 0xff } ,
{ 0x00080 , 0x00 , 0xff } ,
} ;
F_2 ( & V_7 -> V_24 , L_4 ) ;
V_4 -> V_25 = V_87 ;
V_11 = F_3 ( V_4 , V_20 , F_4 ( V_20 ) ) ;
if ( V_11 )
goto error;
return V_11 ;
error:
F_2 ( & V_7 -> V_24 , L_3 , V_11 ) ;
return V_11 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
V_89 -> V_90 = 500 ;
V_89 -> V_91 = V_2 -> V_31 . V_92 . V_93 * 2 ;
V_89 -> V_94 = ( V_2 -> V_31 . V_92 . V_93 * 2 ) + 1 ;
return 0 ;
}
