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
T_2 F_2 ( struct V_7 * V_8 , T_1 V_9 ,
T_1 V_10 )
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
T_2 V_12 =
( V_8 -> V_13 -> V_14 == V_15 ) ? 16 : 8 ;
T_2 V_16 ;
if ( V_10 & F_3 ( 0 ) ) {
if ( V_9 == V_17 ) {
if ( V_10 & F_3 ( 2 ) )
V_16 = 0x0D ;
else
V_16 = 0x0C ;
} else if ( V_9 < V_12 ) {
if ( V_10 & F_3 ( 1 ) ) {
if ( V_10 & F_3 ( 2 ) )
V_16 = V_11 [ 1 ] [ V_9 ] ;
else
V_16 = V_11 [ 0 ] [ V_9 ] ;
} else {
if ( V_10 & F_3 ( 2 ) )
V_16 = V_11 [ 3 ] [ V_9 ] ;
else
V_16 = V_11 [ 2 ] [ V_9 ] ;
}
} else
V_16 = V_18 [ 0 ] ;
} else {
if ( V_9 >= V_19 )
V_9 = 0 ;
V_16 = V_18 [ V_9 ] ;
}
return V_16 ;
}
T_1 F_4 ( T_2 V_16 )
{
T_3 * V_20 ;
if ( V_16 ) {
V_20 = memchr ( V_18 , V_16 ,
sizeof( V_18 ) ) ;
if ( V_20 )
return ( T_1 ) ( V_20 - V_18 ) ;
}
return 0 ;
}
T_2 F_5 ( struct V_7 * V_8 , T_1 * V_21 )
{
if ( ! V_8 -> V_22 )
return F_6 ( V_8 , V_21 ) ;
else
return F_7 ( V_21 , 0 ,
V_8 -> V_23 . V_24 ,
V_8 -> V_23 . V_25 ) ;
}
struct V_26 *
F_8 ( struct V_7 * V_8 , T_1 V_27 , T_3 V_28 , T_2 V_29 )
{
struct V_26 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_33 * V_34 = NULL ;
int V_2 ;
if ( ! V_28 && ! V_29 )
return V_30 ;
if ( F_9 ( V_27 ) == V_35 )
V_32 = V_8 -> V_36 -> V_37 -> V_38 [ V_39 ] ;
else
V_32 = V_8 -> V_36 -> V_37 -> V_38 [ V_40 ] ;
if ( ! V_32 ) {
F_10 ( V_8 -> V_13 -> V_41 , L_1 ,
V_42 , V_27 ) ;
return V_30 ;
}
for ( V_2 = 0 ; V_2 < V_32 -> V_43 ; V_2 ++ ) {
V_34 = & V_32 -> V_44 [ V_2 ] ;
if ( V_34 -> V_45 & V_46 )
continue;
if ( V_29 ) {
if ( V_34 -> V_47 == V_29 )
break;
} else {
if ( V_34 -> V_48 == V_28 ||
V_28 == V_49 )
break;
}
}
if ( V_2 == V_32 -> V_43 ) {
F_10 ( V_8 -> V_13 -> V_41 , L_2
L_3 , V_42 , V_27 , V_28 ,
V_29 ) ;
} else {
if ( ! V_34 )
return V_30 ;
V_8 -> V_30 . V_28 = V_34 -> V_48 ;
V_8 -> V_30 . V_29 = V_34 -> V_47 ;
V_8 -> V_30 . V_50 = V_34 -> V_51 ;
V_30 = & V_8 -> V_30 ;
}
return V_30 ;
}
T_1
F_11 ( struct V_7 * V_8 )
{
T_2 V_2 ;
int V_52 = 0 ;
for ( V_2 = 0 ; V_2 < F_12 ( V_8 -> V_53 ) ; V_2 ++ )
if ( V_8 -> V_53 [ V_2 ] )
V_52 ++ ;
if ( V_52 > 1 )
return true ;
else
return false ;
}
int F_13 ( T_3 * V_54 , int V_3 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 * 8 ; V_2 ++ )
if ( V_54 [ V_2 / 16 ] & ( 1 << ( V_2 % 16 ) ) )
return V_2 ;
return 0 ;
}
T_2 F_6 ( struct V_7 * V_8 , T_1 * V_21 )
{
T_2 V_55 = 0 ;
struct V_56 * V_13 = V_8 -> V_13 ;
if ( V_8 -> V_57 == V_58 ) {
switch ( V_13 -> V_59 ) {
case V_60 :
F_14 ( V_13 -> V_41 , L_4
L_5 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_61 ,
sizeof( V_61 ) ) ;
break;
case V_62 :
case V_62 | V_63 :
F_14 ( V_13 -> V_41 , L_4
L_6 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_64 ,
sizeof( V_64 ) ) ;
break;
case V_60 | V_62 :
case V_65 | V_60 | V_62 :
case V_65 | V_60 :
case V_65 | V_60 | V_62 | V_63 | V_66 :
case V_60 | V_62 | V_63 :
F_14 ( V_13 -> V_41 , L_4
L_7 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_67 ,
sizeof( V_67 ) ) ;
break;
case V_65 :
case V_65 | V_62 :
F_14 ( V_13 -> V_41 , L_4
L_8 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_68 ,
sizeof( V_68 ) ) ;
break;
case V_65 | V_66 :
case V_65 | V_62 | V_66 | V_63 :
F_14 ( V_13 -> V_41 , L_4
L_8 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_68 ,
sizeof( V_68 ) ) ;
break;
case V_63 :
F_14 ( V_13 -> V_41 , L_4
L_9 , V_13 -> V_59 ) ;
V_55 = F_7 ( V_21 , V_55 , V_69 ,
sizeof( V_69 ) ) ;
break;
}
} else {
switch ( V_13 -> V_70 ) {
case V_60 :
F_14 ( V_13 -> V_41 , L_10 ) ;
V_55 = F_7 ( V_21 , V_55 , V_71 ,
sizeof( V_71 ) ) ;
break;
case V_62 :
case V_62 | V_63 :
F_14 ( V_13 -> V_41 , L_11 ) ;
V_55 = F_7 ( V_21 , V_55 , V_72 ,
sizeof( V_72 ) ) ;
break;
case V_60 | V_62 :
case V_60 | V_62 | V_63 :
F_14 ( V_13 -> V_41 , L_12 ) ;
V_55 = F_7 ( V_21 , V_55 , V_73 ,
sizeof( V_73 ) ) ;
break;
case V_65 :
case V_65 | V_66 :
F_14 ( V_13 -> V_41 , L_13 ) ;
V_55 = F_7 ( V_21 , V_55 , V_74 ,
sizeof( V_74 ) ) ;
break;
}
}
return V_55 ;
}
