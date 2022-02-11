T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
T_3 V_5 [ 4 ] [ 16 ] = {
{ 0x1b , 0x36 , 0x51 , 0x6c , 0xa2 , 0xd8 , 0xf3 , 0x10e ,
0x36 , 0x6c , 0xa2 , 0xd8 , 0x144 , 0x1b0 , 0x1e6 , 0x21c } ,
{ 0x1e , 0x3c , 0x5a , 0x78 , 0xb4 , 0xf0 , 0x10e , 0x12c ,
0x3c , 0x78 , 0xb4 , 0xf0 , 0x168 , 0x1e0 , 0x21c , 0x258 } ,
{ 0x0d , 0x1a , 0x27 , 0x34 , 0x4e , 0x68 , 0x75 , 0x82 ,
0x1a , 0x34 , 0x4e , 0x68 , 0x9c , 0xd0 , 0xea , 0x104 } ,
{ 0x0e , 0x1c , 0x2b , 0x39 , 0x56 , 0x73 , 0x82 , 0x90 ,
0x1c , 0x39 , 0x56 , 0x73 , 0xad , 0xe7 , 0x104 , 0x120 }
} ;
T_1 V_6 =
( V_2 -> V_7 -> V_8 == V_9 ) ? 16 : 8 ;
T_1 V_10 ;
if ( V_4 & F_2 ( 0 ) ) {
if ( V_3 == V_11 ) {
if ( V_4 & F_2 ( 2 ) )
V_10 = 0x0D ;
else
V_10 = 0x0C ;
} else if ( V_3 < V_6 ) {
if ( V_4 & F_2 ( 1 ) ) {
if ( V_4 & F_2 ( 2 ) )
V_10 = V_5 [ 1 ] [ V_3 ] ;
else
V_10 = V_5 [ 0 ] [ V_3 ] ;
} else {
if ( V_4 & F_2 ( 2 ) )
V_10 = V_5 [ 3 ] [ V_3 ] ;
else
V_10 = V_5 [ 2 ] [ V_3 ] ;
}
} else
V_10 = V_12 [ 0 ] ;
} else {
if ( V_3 >= V_13 )
V_3 = 0 ;
V_10 = V_12 [ V_3 ] ;
}
return V_10 ;
}
T_2 F_3 ( T_1 V_10 )
{
T_3 * V_14 ;
if ( V_10 ) {
V_14 = memchr ( V_12 , V_10 ,
sizeof( V_12 ) ) ;
if ( V_14 )
return ( T_2 ) ( V_14 - V_12 ) ;
}
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_2 * V_15 )
{
if ( ! V_2 -> V_16 )
return F_5 ( V_2 , V_15 ) ;
else
return F_6 ( V_15 , 0 ,
V_2 -> V_17 . V_18 ,
V_2 -> V_17 . V_19 ) ;
}
struct V_20 *
F_7 ( struct V_1
* V_2 , T_2 V_21 , T_3 V_22 )
{
struct V_20 * V_23 = NULL ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
if ( F_8 ( V_21 ) == V_29 )
V_25 = V_2 -> V_30 -> V_31 -> V_32 [ V_33 ] ;
else
V_25 = V_2 -> V_30 -> V_31 -> V_32 [ V_34 ] ;
if ( ! V_25 ) {
F_9 ( V_2 -> V_7 -> V_35 , L_1
L_2 , V_36 , V_21 , V_22 ) ;
return V_23 ;
}
for ( V_28 = 0 ; V_28 < V_25 -> V_37 ; V_28 ++ ) {
V_27 = & V_25 -> V_38 [ V_28 ] ;
if ( ( ( V_27 -> V_39 == V_22 ) ||
( V_22 == V_40 ) )
&& ! ( V_27 -> V_41 & V_42 ) ) {
V_2 -> V_23 . V_22 = V_22 ;
V_2 -> V_23 . V_43 = V_27 -> V_44 ;
V_2 -> V_23 . V_45 = V_27 -> V_46 ;
V_23 = & V_2 -> V_23 ;
break;
}
}
if ( V_28 == V_25 -> V_37 )
F_9 ( V_2 -> V_7 -> V_35 , L_1
L_2 , V_36 , V_21 , V_22 ) ;
return V_23 ;
}
struct V_20 *
F_10 ( struct V_1 * V_2 ,
T_2 V_21 , T_1 V_43 )
{
struct V_20 * V_23 = NULL ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
if ( F_8 ( V_21 ) == V_29 )
V_25 = V_2 -> V_30 -> V_31 -> V_32 [ V_33 ] ;
else
V_25 = V_2 -> V_30 -> V_31 -> V_32 [ V_34 ] ;
if ( ! V_25 ) {
F_9 ( V_2 -> V_7 -> V_35 , L_1
L_3 , V_36 , V_21 , V_43 ) ;
return V_23 ;
}
for ( V_28 = 0 ; V_28 < V_25 -> V_37 ; V_28 ++ ) {
V_27 = & V_25 -> V_38 [ V_28 ] ;
if ( ( V_27 -> V_44 == V_43 ) &&
! ( V_27 -> V_41 & V_42 ) ) {
V_2 -> V_23 . V_22 = V_27 -> V_39 ;
V_2 -> V_23 . V_43 = V_43 ;
V_2 -> V_23 . V_45 = V_27 -> V_46 ;
V_23 = & V_2 -> V_23 ;
break;
}
}
if ( V_28 == V_25 -> V_37 )
F_9 ( V_2 -> V_7 -> V_35 , L_1
L_3 , V_36 , V_21 , V_43 ) ;
return V_23 ;
}
T_2
F_11 ( struct V_1 * V_2 )
{
T_1 V_28 ;
int V_47 = 0 ;
for ( V_28 = 0 ; V_28 < F_12 ( V_2 -> V_48 ) ; V_28 ++ )
if ( V_2 -> V_48 [ V_28 ] )
V_47 ++ ;
if ( V_47 > 1 )
return true ;
else
return false ;
}
int F_13 ( T_3 * V_49 , int V_50 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_50 * 8 ; V_28 ++ )
if ( V_49 [ V_28 / 16 ] & ( 1 << ( V_28 % 16 ) ) )
return V_28 ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_2 * V_15 )
{
T_1 V_51 = 0 ;
struct V_52 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_53 == V_54 ) {
switch ( V_7 -> V_55 ) {
case V_56 :
F_14 ( V_7 -> V_35 , L_4
L_5 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_57 ,
sizeof( V_57 ) ) ;
break;
case V_58 :
case V_58 | V_59 :
F_14 ( V_7 -> V_35 , L_4
L_6 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_60 ,
sizeof( V_60 ) ) ;
break;
case V_56 | V_58 :
case V_61 | V_56 | V_58 :
case V_61 | V_56 :
case V_61 | V_56 | V_58 | V_59 | V_62 :
case V_56 | V_58 | V_59 :
F_14 ( V_7 -> V_35 , L_4
L_7 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_63 ,
sizeof( V_63 ) ) ;
break;
case V_61 :
case V_61 | V_58 :
F_14 ( V_7 -> V_35 , L_4
L_8 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_64 ,
sizeof( V_64 ) ) ;
break;
case V_61 | V_62 :
case V_61 | V_58 | V_62 | V_59 :
F_14 ( V_7 -> V_35 , L_4
L_8 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_64 ,
sizeof( V_64 ) ) ;
break;
case V_59 :
F_14 ( V_7 -> V_35 , L_4
L_9 , V_7 -> V_55 ) ;
V_51 = F_6 ( V_15 , V_51 , V_65 ,
sizeof( V_65 ) ) ;
break;
}
} else {
switch ( V_7 -> V_66 ) {
case V_56 :
F_14 ( V_7 -> V_35 , L_10 ) ;
V_51 = F_6 ( V_15 , V_51 , V_67 ,
sizeof( V_67 ) ) ;
break;
case V_58 :
case V_58 | V_59 :
F_14 ( V_7 -> V_35 , L_11 ) ;
V_51 = F_6 ( V_15 , V_51 , V_68 ,
sizeof( V_68 ) ) ;
break;
case V_56 | V_58 :
case V_56 | V_58 | V_59 :
F_14 ( V_7 -> V_35 , L_12 ) ;
V_51 = F_6 ( V_15 , V_51 , V_69 ,
sizeof( V_69 ) ) ;
break;
case V_61 :
case V_61 | V_62 :
F_14 ( V_7 -> V_35 , L_13 ) ;
V_51 = F_6 ( V_15 , V_51 , V_70 ,
sizeof( V_70 ) ) ;
break;
}
}
return V_51 ;
}
