T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
T_3 V_3 [ 4 ] [ 8 ] = {
{ 0x1b , 0x36 , 0x51 , 0x6c , 0xa2 , 0xd8 , 0xf3 , 0x10e }
,
{ 0x1e , 0x3c , 0x5a , 0x78 , 0xb4 , 0xf0 , 0x10e , 0x12c }
,
{ 0x0d , 0x1a , 0x27 , 0x34 , 0x4e , 0x68 , 0x75 , 0x82 }
,
{ 0x0e , 0x1c , 0x2b , 0x39 , 0x56 , 0x73 , 0x82 , 0x90 }
} ;
T_1 V_4 ;
if ( V_2 & F_2 ( 0 ) ) {
if ( V_1 == V_5 ) {
if ( V_2 & F_2 ( 2 ) )
V_4 = 0x0D ;
else
V_4 = 0x0C ;
} else if ( V_1 < 8 ) {
if ( V_2 & F_2 ( 1 ) ) {
if ( V_2 & F_2 ( 2 ) )
V_4 = V_3 [ 1 ] [ V_1 ] ;
else
V_4 = V_3 [ 0 ] [ V_1 ] ;
} else {
if ( V_2 & F_2 ( 2 ) )
V_4 = V_3 [ 3 ] [ V_1 ] ;
else
V_4 = V_3 [ 2 ] [ V_1 ] ;
}
} else
V_4 = V_6 [ 0 ] ;
} else {
if ( V_1 >= V_7 )
V_1 = 0 ;
V_4 = V_6 [ V_1 ] ;
}
return V_4 ;
}
T_2 F_3 ( T_1 V_4 )
{
T_3 * V_8 ;
if ( V_4 ) {
V_8 = memchr ( V_6 , V_4 ,
sizeof( V_6 ) ) ;
if ( V_8 )
return ( T_2 ) ( V_8 - V_6 ) ;
}
return 0 ;
}
T_1 F_4 ( struct V_9 * V_10 , T_2 * V_11 )
{
if ( ! V_10 -> V_12 )
return F_5 ( V_10 , V_11 ) ;
else
return F_6 ( V_11 , 0 ,
V_10 -> V_13 . V_14 ,
V_10 -> V_13 . V_15 ) ;
}
struct V_16 *
F_7 ( struct V_9
* V_10 , T_2 V_17 , T_3 V_18 )
{
struct V_16 * V_19 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
if ( F_8 ( V_17 ) == V_25 )
V_21 = V_10 -> V_26 -> V_27 -> V_28 [ V_29 ] ;
else
V_21 = V_10 -> V_26 -> V_27 -> V_28 [ V_30 ] ;
if ( ! V_21 ) {
F_9 ( V_10 -> V_31 -> V_32 , L_1
L_2 , V_33 , V_17 , V_18 ) ;
return V_19 ;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_34 ; V_24 ++ ) {
V_23 = & V_21 -> V_35 [ V_24 ] ;
if ( ( ( V_23 -> V_36 == V_18 ) ||
( V_18 == V_37 ) )
&& ! ( V_23 -> V_38 & V_39 ) ) {
V_10 -> V_19 . V_18 = V_18 ;
V_10 -> V_19 . V_40 = V_23 -> V_41 ;
V_10 -> V_19 . V_42 = V_23 -> V_43 ;
V_19 = & V_10 -> V_19 ;
break;
}
}
if ( V_24 == V_21 -> V_34 )
F_9 ( V_10 -> V_31 -> V_32 , L_1
L_2 , V_33 , V_17 , V_18 ) ;
return V_19 ;
}
struct V_16 *
F_10 ( struct V_9 * V_10 ,
T_2 V_17 , T_1 V_40 )
{
struct V_16 * V_19 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
if ( F_8 ( V_17 ) == V_25 )
V_21 = V_10 -> V_26 -> V_27 -> V_28 [ V_29 ] ;
else
V_21 = V_10 -> V_26 -> V_27 -> V_28 [ V_30 ] ;
if ( ! V_21 ) {
F_9 ( V_10 -> V_31 -> V_32 , L_1
L_3 , V_33 , V_17 , V_40 ) ;
return V_19 ;
}
for ( V_24 = 0 ; V_24 < V_21 -> V_34 ; V_24 ++ ) {
V_23 = & V_21 -> V_35 [ V_24 ] ;
if ( ( V_23 -> V_41 == V_40 ) &&
! ( V_23 -> V_38 & V_39 ) ) {
V_10 -> V_19 . V_18 = V_23 -> V_36 ;
V_10 -> V_19 . V_40 = V_40 ;
V_10 -> V_19 . V_42 = V_23 -> V_43 ;
V_19 = & V_10 -> V_19 ;
break;
}
}
if ( V_24 == V_21 -> V_34 )
F_9 ( V_10 -> V_31 -> V_32 , L_1
L_3 , V_33 , V_17 , V_40 ) ;
return V_19 ;
}
T_2
F_11 ( struct V_9 * V_10 )
{
T_1 V_24 ;
int V_44 = 0 ;
for ( V_24 = 0 ; V_24 < F_12 ( V_10 -> V_45 ) ; V_24 ++ )
if ( V_10 -> V_45 [ V_24 ] )
V_44 ++ ;
if ( V_44 > 1 )
return true ;
else
return false ;
}
int F_13 ( T_3 * V_46 , int V_47 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_47 * 8 ; V_24 ++ )
if ( V_46 [ V_24 / 16 ] & ( 1 << ( V_24 % 16 ) ) )
return V_24 ;
return 0 ;
}
T_1 F_5 ( struct V_9 * V_10 , T_2 * V_11 )
{
T_1 V_48 = 0 ;
struct V_49 * V_31 = V_10 -> V_31 ;
if ( V_10 -> V_50 == V_51 ) {
switch ( V_31 -> V_52 ) {
case V_53 :
F_14 ( V_31 -> V_32 , L_4
L_5 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_54 ,
sizeof( V_54 ) ) ;
break;
case V_55 :
case V_55 | V_56 :
F_14 ( V_31 -> V_32 , L_4
L_6 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_57 ,
sizeof( V_57 ) ) ;
break;
case V_53 | V_55 :
case V_58 | V_53 | V_55 :
case V_58 | V_53 :
case V_58 | V_53 | V_55 | V_56 | V_59 :
case V_53 | V_55 | V_56 :
F_14 ( V_31 -> V_32 , L_4
L_7 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_60 ,
sizeof( V_60 ) ) ;
break;
case V_58 :
case V_58 | V_55 :
F_14 ( V_31 -> V_32 , L_4
L_8 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_61 ,
sizeof( V_61 ) ) ;
break;
case V_58 | V_59 :
case V_58 | V_55 | V_59 | V_56 :
F_14 ( V_31 -> V_32 , L_4
L_8 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_61 ,
sizeof( V_61 ) ) ;
break;
case V_56 :
F_14 ( V_31 -> V_32 , L_4
L_9 , V_31 -> V_52 ) ;
V_48 = F_6 ( V_11 , V_48 , V_62 ,
sizeof( V_62 ) ) ;
break;
}
} else {
switch ( V_31 -> V_63 ) {
case V_53 :
F_14 ( V_31 -> V_32 , L_10 ) ;
V_48 = F_6 ( V_11 , V_48 , V_64 ,
sizeof( V_64 ) ) ;
break;
case V_55 :
case V_55 | V_56 :
F_14 ( V_31 -> V_32 , L_11 ) ;
V_48 = F_6 ( V_11 , V_48 , V_65 ,
sizeof( V_65 ) ) ;
break;
case V_53 | V_55 :
case V_53 | V_55 | V_56 :
F_14 ( V_31 -> V_32 , L_12 ) ;
V_48 = F_6 ( V_11 , V_48 , V_66 ,
sizeof( V_66 ) ) ;
break;
case V_58 :
case V_58 | V_59 :
F_14 ( V_31 -> V_32 , L_13 ) ;
V_48 = F_6 ( V_11 , V_48 , V_67 ,
sizeof( V_67 ) ) ;
break;
}
}
return V_48 ;
}
