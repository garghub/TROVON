static bool
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_8 = (struct V_7 * ) V_4 -> V_13 ;
switch ( F_2 ( V_8 -> V_14 ) ) {
case V_15 :
V_6 = ( void * ) ( V_4 -> V_13 + sizeof( struct V_7 ) ) ;
if ( V_6 -> V_16 . V_17 == F_3 ( V_18 ) ||
V_6 -> V_16 . V_17 == F_3 ( V_19 ) ) {
if ( ! memcmp ( V_6 -> V_20 , V_6 -> V_21 , 4 ) )
return true ;
}
break;
case V_22 :
V_10 = ( void * ) ( V_4 -> V_13 + sizeof( struct V_7 ) ) ;
V_12 = ( void * ) ( V_4 -> V_13 + sizeof( struct V_7 ) +
sizeof( struct V_9 ) ) ;
if ( V_23 == V_12 -> V_24 ) {
if ( ! memcmp ( & V_10 -> V_25 , & V_10 -> V_26 ,
sizeof( struct V_27 ) ) )
return true ;
}
break;
default:
break;
}
return false ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_33 ;
struct V_7 * V_8 ;
T_1 V_34 [ V_35 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_30 = ( void * ) V_32 +
F_5 ( V_32 -> V_36 ) ;
if ( ! memcmp ( & V_30 -> V_37 ,
V_34 , sizeof( V_34 ) ) ) {
V_8 = (struct V_7 * )
( ( T_1 * ) & V_30 -> V_38
+ sizeof( V_30 -> V_38 ) +
sizeof( V_30 -> V_37 )
- sizeof( V_30 -> V_38 . V_39 )
- sizeof( V_30 -> V_38 . V_40 )
- sizeof( V_30 -> V_37 . V_41 ) ) ;
memcpy ( V_8 -> V_40 , V_30 -> V_38 . V_40 ,
sizeof( V_8 -> V_40 ) ) ;
memcpy ( V_8 -> V_39 , V_30 -> V_38 . V_39 ,
sizeof( V_8 -> V_39 ) ) ;
V_33 = ( T_1 * ) V_8 - ( T_1 * ) V_32 ;
} else {
V_33 = ( T_1 * ) & V_30 -> V_38 -
( T_1 * ) V_32 ;
}
F_6 ( V_4 , V_33 ) ;
if ( V_2 -> V_42 &&
F_1 ( V_2 , V_4 ) ) {
F_7 ( V_2 -> V_43 -> V_44 , L_1 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
V_2 -> V_45 = V_32 -> V_46 ;
V_2 -> V_47 = V_32 -> V_48 ;
V_28 = F_9 ( V_2 , V_4 ) ;
if ( V_28 == - 1 )
F_10 ( V_2 -> V_43 -> V_44 , L_2 ) ;
return V_28 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_49 * V_43 = V_2 -> V_43 ;
int V_28 = 0 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
T_1 V_50 [ V_35 ] ;
T_2 V_51 , V_36 , V_52 , V_53 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_51 = F_5 ( V_32 -> V_51 ) ;
V_36 = F_5 ( V_32 -> V_36 ) ;
V_52 = F_5 ( V_32 -> V_52 ) ;
V_53 = F_5 ( V_32 -> V_53 ) ;
V_30 = ( void * ) V_32 + V_36 ;
if ( ( V_36 + V_52 ) > ( T_2 ) V_4 -> V_54 ) {
F_10 ( V_43 -> V_44 ,
L_3 ,
V_4 -> V_54 , V_36 , V_52 ) ;
V_2 -> V_55 . V_56 ++ ;
if ( V_43 -> V_57 . V_58 )
V_43 -> V_57 . V_58 ( V_43 , V_4 ) ;
else
F_8 ( V_4 ) ;
return V_28 ;
}
if ( V_51 == V_59 ) {
struct V_60 V_61 ;
struct V_3 * V_62 ;
F_12 ( & V_61 ) ;
F_6 ( V_4 , V_36 ) ;
F_13 ( V_4 , V_52 ) ;
F_14 ( V_4 , & V_61 , V_2 -> V_63 ,
V_2 -> V_64 -> V_65 , 0 , false ) ;
while ( ! F_15 ( & V_61 ) ) {
V_62 = F_16 ( & V_61 ) ;
V_28 = F_9 ( V_2 , V_62 ) ;
if ( V_28 == - 1 )
F_10 ( V_43 -> V_44 , L_4 ) ;
}
return 0 ;
} else if ( V_51 == V_66 ) {
V_28 = F_17 ( V_2 , V_4 ) ;
if ( V_28 )
F_10 ( V_43 -> V_44 , L_5 ) ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( ! F_18 ( V_2 ) ||
memcmp ( V_2 -> V_63 , V_30 -> V_38 . V_39 , V_35 ) ) {
F_4 ( V_2 , V_4 ) ;
return V_28 ;
}
if ( F_19 ( V_2 ) ) {
memcpy ( V_50 , V_30 -> V_38 . V_40 , V_35 ) ;
} else {
if ( V_51 != V_67 )
V_2 -> V_68 [ V_32 -> V_69 ] = V_53 ;
memcpy ( V_50 , V_2 -> V_70 . V_71 . V_72 ,
V_35 ) ;
}
V_28 = F_20 ( V_2 , V_53 , V_32 -> V_69 ,
V_50 , ( T_1 ) V_51 , V_4 ) ;
if ( V_28 || ( V_51 == V_67 ) ) {
if ( V_43 -> V_57 . V_58 )
V_43 -> V_57 . V_58 ( V_43 , V_4 ) ;
else
F_8 ( V_4 ) ;
}
if ( V_28 )
V_2 -> V_55 . V_56 ++ ;
return V_28 ;
}
