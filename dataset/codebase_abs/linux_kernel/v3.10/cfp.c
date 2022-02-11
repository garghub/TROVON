T_1 * F_1 ( T_1 V_1 )
{
T_1 V_2 ;
T_1 V_3 = sizeof( V_4 ) /
sizeof( struct V_5 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return V_4 [ V_2 ] . V_6 ;
return NULL ;
}
T_2 F_2 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_3 V_11 [ 4 ] [ 16 ] = {
{ 0x1b , 0x36 , 0x51 , 0x6c , 0xa2 , 0xd8 , 0xf3 , 0x10e ,
0x36 , 0x6c , 0xa2 , 0xd8 , 0x144 , 0x1b0 , 0x1e6 , 0x21c } ,
{ 0x1e , 0x3c , 0x5a , 0x78 , 0xb4 , 0xf0 , 0x10e , 0x12c ,
0x3c , 0x78 , 0xb4 , 0xf0 , 0x168 , 0x1e0 , 0x21c , 0x258 } ,
{ 0x0d , 0x1a , 0x27 , 0x34 , 0x4e , 0x68 , 0x75 , 0x82 ,
0x1a , 0x34 , 0x4e , 0x68 , 0x9c , 0xd0 , 0xea , 0x104 } ,
{ 0x0e , 0x1c , 0x2b , 0x39 , 0x56 , 0x73 , 0x82 , 0x90 ,
0x1c , 0x39 , 0x56 , 0x73 , 0xad , 0xe7 , 0x104 , 0x120 }
} ;
T_3 V_12 [ 8 ] [ 10 ] = {
{ 0x75 , 0xEA , 0x15F , 0x1D4 , 0x2BE , 0x3A8 , 0x41D ,
0x492 , 0x57C , 0x618 } ,
{ 0x82 , 0x104 , 0x186 , 0x208 , 0x30C , 0x410 , 0x492 ,
0x514 , 0x618 , 0x6C6 } ,
{ 0x3B , 0x75 , 0xB0 , 0xEA , 0x15F , 0x1D4 , 0x20F ,
0x249 , 0x2BE , 0x30C } ,
{ 0x41 , 0x82 , 0xC3 , 0x104 , 0x186 , 0x208 , 0x249 ,
0x28A , 0x30C , 0x363 } ,
{ 0x1B , 0x36 , 0x51 , 0x6C , 0xA2 , 0xD8 , 0xF3 ,
0x10E , 0x144 , 0x168 } ,
{ 0x1E , 0x3C , 0x5A , 0x78 , 0xB4 , 0xF0 , 0x10E ,
0x12C , 0x168 , 0x190 } ,
{ 0xD , 0x1A , 0x27 , 0x34 , 0x4E , 0x68 , 0x75 , 0x82 , 0x9C , 0x00 } ,
{ 0xF , 0x1D , 0x2C , 0x3A , 0x57 , 0x74 , 0x82 , 0x91 , 0xAE , 0x00 } ,
} ;
T_3 V_13 [ 8 ] [ 10 ] = {
{ 0xEA , 0x1D4 , 0x2BE , 0x3A8 , 0x57C , 0x750 , 0x83A ,
0x924 , 0xAF8 , 0xC30 } ,
{ 0x104 , 0x208 , 0x30C , 0x410 , 0x618 , 0x820 , 0x924 ,
0xA28 , 0xC30 , 0xD8B } ,
{ 0x75 , 0xEA , 0x15F , 0x1D4 , 0x2BE , 0x3A8 , 0x41D ,
0x492 , 0x57C , 0x618 } ,
{ 0x82 , 0x104 , 0x186 , 0x208 , 0x30C , 0x410 , 0x492 ,
0x514 , 0x618 , 0x6C6 } ,
{ 0x36 , 0x6C , 0xA2 , 0xD8 , 0x144 , 0x1B0 , 0x1E6 ,
0x21C , 0x288 , 0x2D0 } ,
{ 0x3C , 0x78 , 0xB4 , 0xF0 , 0x168 , 0x1E0 , 0x21C ,
0x258 , 0x2D0 , 0x320 } ,
{ 0x1A , 0x34 , 0x4A , 0x68 , 0x9C , 0xD0 , 0xEA , 0x104 ,
0x138 , 0x00 } ,
{ 0x1D , 0x3A , 0x57 , 0x74 , 0xAE , 0xE6 , 0x104 , 0x121 ,
0x15B , 0x00 } ,
} ;
T_2 V_14 = 0 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
if ( ( V_10 & 0x3 ) == V_18 ) {
V_15 = F_3 ( V_9 & 0xF , 9 ) ;
V_16 = ( V_10 & 0xC ) >> 2 ;
V_17 = ( V_10 & 0x10 ) >> 4 ;
if ( ( V_9 >> 4 ) == 1 )
V_14 = V_13 [ 2 * ( 3 - V_16 ) + V_17 ] [ V_15 ] ;
else
V_14 = V_12 [ 2 * ( 3 - V_16 ) + V_17 ] [ V_15 ] ;
} else if ( ( V_10 & 0x3 ) == V_19 ) {
V_16 = ( V_10 & 0xC ) >> 2 ;
V_17 = ( V_10 & 0x10 ) >> 4 ;
if ( V_9 == V_20 ) {
if ( V_17 == 1 )
V_14 = 0x0D ;
else
V_14 = 0x0C ;
} else if ( V_9 < 16 ) {
if ( ( V_16 == 1 ) || ( V_16 == 0 ) )
V_14 = V_11 [ 2 * ( 1 - V_16 ) + V_17 ] [ V_9 ] ;
else
V_14 = V_21 [ 0 ] ;
} else {
V_14 = V_21 [ 0 ] ;
}
} else {
if ( V_9 >= V_22 )
V_9 = 0 ;
V_14 = V_21 [ V_9 ] ;
}
return V_14 ;
}
T_2 F_4 ( struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
T_3 V_11 [ 4 ] [ 16 ] = {
{ 0x1b , 0x36 , 0x51 , 0x6c , 0xa2 , 0xd8 , 0xf3 , 0x10e ,
0x36 , 0x6c , 0xa2 , 0xd8 , 0x144 , 0x1b0 , 0x1e6 , 0x21c } ,
{ 0x1e , 0x3c , 0x5a , 0x78 , 0xb4 , 0xf0 , 0x10e , 0x12c ,
0x3c , 0x78 , 0xb4 , 0xf0 , 0x168 , 0x1e0 , 0x21c , 0x258 } ,
{ 0x0d , 0x1a , 0x27 , 0x34 , 0x4e , 0x68 , 0x75 , 0x82 ,
0x1a , 0x34 , 0x4e , 0x68 , 0x9c , 0xd0 , 0xea , 0x104 } ,
{ 0x0e , 0x1c , 0x2b , 0x39 , 0x56 , 0x73 , 0x82 , 0x90 ,
0x1c , 0x39 , 0x56 , 0x73 , 0xad , 0xe7 , 0x104 , 0x120 }
} ;
T_2 V_23 =
( V_8 -> V_24 -> V_25 == V_26 ) ? 16 : 8 ;
T_2 V_14 ;
if ( V_8 -> V_24 -> V_27 )
return F_2 ( V_8 , V_9 , V_10 ) ;
if ( V_10 & F_5 ( 0 ) ) {
if ( V_9 == V_20 ) {
if ( V_10 & F_5 ( 2 ) )
V_14 = 0x0D ;
else
V_14 = 0x0C ;
} else if ( V_9 < V_23 ) {
if ( V_10 & F_5 ( 1 ) ) {
if ( V_10 & F_5 ( 2 ) )
V_14 = V_11 [ 1 ] [ V_9 ] ;
else
V_14 = V_11 [ 0 ] [ V_9 ] ;
} else {
if ( V_10 & F_5 ( 2 ) )
V_14 = V_11 [ 3 ] [ V_9 ] ;
else
V_14 = V_11 [ 2 ] [ V_9 ] ;
}
} else
V_14 = V_21 [ 0 ] ;
} else {
if ( V_9 >= V_22 )
V_9 = 0 ;
V_14 = V_21 [ V_9 ] ;
}
return V_14 ;
}
T_2 F_6 ( struct V_7 * V_8 , T_1 * V_28 )
{
if ( ! V_8 -> V_29 )
return F_7 ( V_8 , V_28 ) ;
else
return F_8 ( V_28 , 0 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_30 . V_32 ) ;
}
struct V_33 *
F_9 ( struct V_7 * V_8 , T_1 V_34 , T_3 V_35 , T_2 V_36 )
{
struct V_33 * V_37 = NULL ;
struct V_38 * V_39 ;
struct V_40 * V_41 = NULL ;
int V_2 ;
if ( ! V_35 && ! V_36 )
return V_37 ;
if ( F_10 ( V_34 ) == V_42 )
V_39 = V_8 -> V_43 -> V_44 -> V_45 [ V_46 ] ;
else
V_39 = V_8 -> V_43 -> V_44 -> V_45 [ V_47 ] ;
if ( ! V_39 ) {
F_11 ( V_8 -> V_24 -> V_48 , L_1 ,
V_49 , V_34 ) ;
return V_37 ;
}
for ( V_2 = 0 ; V_2 < V_39 -> V_50 ; V_2 ++ ) {
V_41 = & V_39 -> V_51 [ V_2 ] ;
if ( V_41 -> V_52 & V_53 )
continue;
if ( V_36 ) {
if ( V_41 -> V_54 == V_36 )
break;
} else {
if ( V_41 -> V_55 == V_35 ||
V_35 == V_56 )
break;
}
}
if ( V_2 == V_39 -> V_50 ) {
F_11 ( V_8 -> V_24 -> V_48 , L_2
L_3 , V_49 , V_34 , V_35 ,
V_36 ) ;
} else {
if ( ! V_41 )
return V_37 ;
V_8 -> V_37 . V_35 = V_41 -> V_55 ;
V_8 -> V_37 . V_36 = V_41 -> V_54 ;
V_8 -> V_37 . V_57 = V_41 -> V_58 ;
V_37 = & V_8 -> V_37 ;
}
return V_37 ;
}
T_1
F_12 ( struct V_7 * V_8 )
{
T_2 V_2 ;
int V_59 = 0 ;
for ( V_2 = 0 ; V_2 < F_13 ( V_8 -> V_60 ) ; V_2 ++ )
if ( V_8 -> V_60 [ V_2 ] )
V_59 ++ ;
if ( V_59 > 1 )
return true ;
else
return false ;
}
T_2 F_7 ( struct V_7 * V_8 , T_1 * V_28 )
{
T_2 V_61 = 0 ;
struct V_62 * V_24 = V_8 -> V_24 ;
if ( V_8 -> V_63 == V_64 ) {
switch ( V_24 -> V_65 ) {
case V_66 :
F_14 ( V_24 -> V_48 , L_4
L_5 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_67 ,
sizeof( V_67 ) ) ;
break;
case V_68 :
case V_68 | V_69 :
case V_68 | V_69 | V_70 :
F_14 ( V_24 -> V_48 , L_4
L_6 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_71 ,
sizeof( V_71 ) ) ;
break;
case V_66 | V_68 :
case V_72 | V_66 | V_68 :
case V_72 | V_66 :
case V_72 | V_66 | V_68 | V_69 | V_73 :
case V_72 | V_66 | V_68 | V_69 | V_73 | V_74 :
case V_72 | V_66 | V_68 | V_69 | V_73 |
V_74 | V_70 :
case V_66 | V_68 | V_69 :
case V_66 | V_68 | V_69 | V_70 :
F_14 ( V_24 -> V_48 , L_4
L_7 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_75 ,
sizeof( V_75 ) ) ;
break;
case V_72 :
case V_72 | V_68 :
F_14 ( V_24 -> V_48 , L_4
L_8 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_76 ,
sizeof( V_76 ) ) ;
break;
case V_73 :
case V_72 | V_73 :
case V_72 | V_73 | V_74 :
case V_72 | V_68 | V_73 | V_69 :
case V_72 | V_68 | V_73 | V_69 | V_74 :
F_14 ( V_24 -> V_48 , L_4
L_8 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_76 ,
sizeof( V_76 ) ) ;
break;
case V_69 :
case V_69 | V_70 :
F_14 ( V_24 -> V_48 , L_4
L_9 , V_24 -> V_65 ) ;
V_61 = F_8 ( V_28 , V_61 , V_77 ,
sizeof( V_77 ) ) ;
break;
}
} else {
switch ( V_24 -> V_78 ) {
case V_66 :
F_14 ( V_24 -> V_48 , L_10 ) ;
V_61 = F_8 ( V_28 , V_61 , V_79 ,
sizeof( V_79 ) ) ;
break;
case V_68 :
case V_68 | V_69 :
F_14 ( V_24 -> V_48 , L_11 ) ;
V_61 = F_8 ( V_28 , V_61 , V_80 ,
sizeof( V_80 ) ) ;
break;
case V_66 | V_68 :
case V_66 | V_68 | V_69 :
F_14 ( V_24 -> V_48 , L_12 ) ;
V_61 = F_8 ( V_28 , V_61 , V_81 ,
sizeof( V_81 ) ) ;
break;
case V_72 :
case V_72 | V_73 :
F_14 ( V_24 -> V_48 , L_13 ) ;
V_61 = F_8 ( V_28 , V_61 , V_82 ,
sizeof( V_82 ) ) ;
break;
}
}
return V_61 ;
}
