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
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_30 = ( void * ) V_32 +
F_5 ( V_32 -> V_34 ) ;
if ( ( ! memcmp ( & V_30 -> V_35 , V_36 ,
sizeof( V_36 ) ) ) ||
( ! memcmp ( & V_30 -> V_35 , V_37 ,
sizeof( V_37 ) ) &&
F_2 ( V_30 -> V_35 . V_38 ) != V_39 &&
F_2 ( V_30 -> V_35 . V_38 ) != V_40 ) ) {
V_8 = (struct V_7 * )
( ( V_41 * ) & V_30 -> V_42
+ sizeof( V_30 -> V_42 ) +
sizeof( V_30 -> V_35 )
- sizeof( V_30 -> V_42 . V_43 )
- sizeof( V_30 -> V_42 . V_44 )
- sizeof( V_30 -> V_35 . V_38 ) ) ;
memcpy ( V_8 -> V_44 , V_30 -> V_42 . V_44 ,
sizeof( V_8 -> V_44 ) ) ;
memcpy ( V_8 -> V_43 , V_30 -> V_42 . V_43 ,
sizeof( V_8 -> V_43 ) ) ;
V_33 = ( V_41 * ) V_8 - ( V_41 * ) V_32 ;
} else {
V_33 = ( V_41 * ) & V_30 -> V_42 -
( V_41 * ) V_32 ;
}
F_6 ( V_4 , V_33 ) ;
if ( V_2 -> V_45 &&
F_1 ( V_2 , V_4 ) ) {
F_7 ( V_2 -> V_46 -> V_47 , L_1 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
V_2 -> V_48 = V_32 -> V_49 ;
V_2 -> V_50 = V_32 -> V_51 ;
V_28 = F_9 ( V_2 , V_4 ) ;
if ( V_28 == - 1 )
F_10 ( V_2 -> V_46 -> V_47 , L_2 ) ;
return V_28 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_52 * V_46 = V_2 -> V_46 ;
int V_28 = 0 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
V_41 V_53 [ V_54 ] ;
T_1 V_55 , V_34 , V_56 , V_57 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_55 = F_5 ( V_32 -> V_55 ) ;
V_34 = F_5 ( V_32 -> V_34 ) ;
V_56 = F_5 ( V_32 -> V_56 ) ;
V_57 = F_5 ( V_32 -> V_57 ) ;
V_30 = ( void * ) V_32 + V_34 ;
if ( ( V_34 + V_56 ) > ( T_1 ) V_4 -> V_58 ) {
F_10 ( V_46 -> V_47 ,
L_3 ,
V_4 -> V_58 , V_34 , V_56 ) ;
V_2 -> V_59 . V_60 ++ ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( V_55 == V_61 ) {
struct V_62 V_63 ;
struct V_3 * V_64 ;
F_12 ( & V_63 ) ;
F_6 ( V_4 , V_34 ) ;
F_13 ( V_4 , V_56 ) ;
F_14 ( V_4 , & V_63 , V_2 -> V_65 ,
V_2 -> V_66 -> V_67 , 0 , false ) ;
while ( ! F_15 ( & V_63 ) ) {
V_64 = F_16 ( & V_63 ) ;
V_28 = F_9 ( V_2 , V_64 ) ;
if ( V_28 == - 1 )
F_10 ( V_46 -> V_47 , L_4 ) ;
}
return 0 ;
} else if ( V_55 == V_68 ) {
V_28 = F_17 ( V_2 , V_4 ) ;
if ( V_28 )
F_10 ( V_46 -> V_47 , L_5 ) ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( ! F_18 ( V_2 ) ||
! F_19 ( V_2 -> V_65 , V_30 -> V_42 . V_43 ) ) {
F_4 ( V_2 , V_4 ) ;
return V_28 ;
}
if ( F_20 ( V_2 ) ) {
memcpy ( V_53 , V_30 -> V_42 . V_44 , V_54 ) ;
} else {
if ( V_55 != V_69 )
V_2 -> V_70 [ V_32 -> V_71 ] = V_57 ;
memcpy ( V_53 , V_2 -> V_72 . V_73 . V_74 ,
V_54 ) ;
}
V_28 = F_21 ( V_2 , V_57 , V_32 -> V_71 ,
V_53 , ( V_41 ) V_55 , V_4 ) ;
if ( V_28 || ( V_55 == V_69 ) )
F_8 ( V_4 ) ;
if ( V_28 )
V_2 -> V_59 . V_60 ++ ;
return V_28 ;
}
