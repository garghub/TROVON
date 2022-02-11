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
T_2 F_4 ( struct V_7 * V_8 , T_1 * V_20 )
{
if ( ! V_8 -> V_21 )
return F_5 ( V_8 , V_20 ) ;
else
return F_6 ( V_20 , 0 ,
V_8 -> V_22 . V_23 ,
V_8 -> V_22 . V_24 ) ;
}
struct V_25 *
F_7 ( struct V_7 * V_8 , T_1 V_26 , T_3 V_27 , T_2 V_28 )
{
struct V_25 * V_29 = NULL ;
struct V_30 * V_31 ;
struct V_32 * V_33 = NULL ;
int V_2 ;
if ( ! V_27 && ! V_28 )
return V_29 ;
if ( F_8 ( V_26 ) == V_34 )
V_31 = V_8 -> V_35 -> V_36 -> V_37 [ V_38 ] ;
else
V_31 = V_8 -> V_35 -> V_36 -> V_37 [ V_39 ] ;
if ( ! V_31 ) {
F_9 ( V_8 -> V_13 -> V_40 , L_1 ,
V_41 , V_26 ) ;
return V_29 ;
}
for ( V_2 = 0 ; V_2 < V_31 -> V_42 ; V_2 ++ ) {
V_33 = & V_31 -> V_43 [ V_2 ] ;
if ( V_33 -> V_44 & V_45 )
continue;
if ( V_28 ) {
if ( V_33 -> V_46 == V_28 )
break;
} else {
if ( V_33 -> V_47 == V_27 ||
V_27 == V_48 )
break;
}
}
if ( V_2 == V_31 -> V_42 ) {
F_9 ( V_8 -> V_13 -> V_40 , L_2
L_3 , V_41 , V_26 , V_27 ,
V_28 ) ;
} else {
if ( ! V_33 )
return V_29 ;
V_8 -> V_29 . V_27 = V_33 -> V_47 ;
V_8 -> V_29 . V_28 = V_33 -> V_46 ;
V_8 -> V_29 . V_49 = V_33 -> V_50 ;
V_29 = & V_8 -> V_29 ;
}
return V_29 ;
}
T_1
F_10 ( struct V_7 * V_8 )
{
T_2 V_2 ;
int V_51 = 0 ;
for ( V_2 = 0 ; V_2 < F_11 ( V_8 -> V_52 ) ; V_2 ++ )
if ( V_8 -> V_52 [ V_2 ] )
V_51 ++ ;
if ( V_51 > 1 )
return true ;
else
return false ;
}
T_2 F_5 ( struct V_7 * V_8 , T_1 * V_20 )
{
T_2 V_53 = 0 ;
struct V_54 * V_13 = V_8 -> V_13 ;
if ( V_8 -> V_55 == V_56 ) {
switch ( V_13 -> V_57 ) {
case V_58 :
F_12 ( V_13 -> V_40 , L_4
L_5 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_59 ,
sizeof( V_59 ) ) ;
break;
case V_60 :
case V_60 | V_61 :
F_12 ( V_13 -> V_40 , L_4
L_6 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_62 ,
sizeof( V_62 ) ) ;
break;
case V_58 | V_60 :
case V_63 | V_58 | V_60 :
case V_63 | V_58 :
case V_63 | V_58 | V_60 | V_61 | V_64 :
case V_58 | V_60 | V_61 :
F_12 ( V_13 -> V_40 , L_4
L_7 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_65 ,
sizeof( V_65 ) ) ;
break;
case V_63 :
case V_63 | V_60 :
F_12 ( V_13 -> V_40 , L_4
L_8 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_66 ,
sizeof( V_66 ) ) ;
break;
case V_63 | V_64 :
case V_63 | V_60 | V_64 | V_61 :
F_12 ( V_13 -> V_40 , L_4
L_8 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_66 ,
sizeof( V_66 ) ) ;
break;
case V_61 :
F_12 ( V_13 -> V_40 , L_4
L_9 , V_13 -> V_57 ) ;
V_53 = F_6 ( V_20 , V_53 , V_67 ,
sizeof( V_67 ) ) ;
break;
}
} else {
switch ( V_13 -> V_68 ) {
case V_58 :
F_12 ( V_13 -> V_40 , L_10 ) ;
V_53 = F_6 ( V_20 , V_53 , V_69 ,
sizeof( V_69 ) ) ;
break;
case V_60 :
case V_60 | V_61 :
F_12 ( V_13 -> V_40 , L_11 ) ;
V_53 = F_6 ( V_20 , V_53 , V_70 ,
sizeof( V_70 ) ) ;
break;
case V_58 | V_60 :
case V_58 | V_60 | V_61 :
F_12 ( V_13 -> V_40 , L_12 ) ;
V_53 = F_6 ( V_20 , V_53 , V_71 ,
sizeof( V_71 ) ) ;
break;
case V_63 :
case V_63 | V_64 :
F_12 ( V_13 -> V_40 , L_13 ) ;
V_53 = F_6 ( V_20 , V_53 , V_72 ,
sizeof( V_72 ) ) ;
break;
}
}
return V_53 ;
}
