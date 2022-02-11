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
T_1 V_34 , V_35 ;
T_2 * V_36 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_34 = F_5 ( V_32 -> V_37 ) ;
V_35 = F_5 ( V_32 -> V_38 ) ;
V_30 = ( void * ) V_32 + V_34 ;
if ( ( ! memcmp ( & V_30 -> V_39 , V_40 ,
sizeof( V_40 ) ) ) ||
( ! memcmp ( & V_30 -> V_39 , V_41 ,
sizeof( V_41 ) ) &&
F_2 ( V_30 -> V_39 . V_42 ) != V_43 &&
F_2 ( V_30 -> V_39 . V_42 ) != V_44 ) ) {
V_8 = (struct V_7 * )
( ( T_2 * ) & V_30 -> V_45
+ sizeof( V_30 -> V_45 ) +
sizeof( V_30 -> V_39 )
- sizeof( V_30 -> V_45 . V_46 )
- sizeof( V_30 -> V_45 . V_47 )
- sizeof( V_30 -> V_39 . V_42 ) ) ;
memcpy ( V_8 -> V_47 , V_30 -> V_45 . V_47 ,
sizeof( V_8 -> V_47 ) ) ;
memcpy ( V_8 -> V_46 , V_30 -> V_45 . V_46 ,
sizeof( V_8 -> V_46 ) ) ;
V_33 = ( T_2 * ) V_8 - ( T_2 * ) V_32 ;
} else {
V_33 = ( T_2 * ) & V_30 -> V_45 -
( T_2 * ) V_32 ;
}
F_6 ( V_4 , V_33 ) ;
if ( V_2 -> V_48 &&
F_1 ( V_2 , V_4 ) ) {
F_7 ( V_2 -> V_49 -> V_50 , L_1 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
if ( F_9 ( V_2 -> V_49 -> V_51 ) &&
F_2 ( V_30 -> V_45 . V_14 ) == V_52 ) {
V_36 = ( T_2 * ) V_32 + V_34 ;
F_10 ( V_2 , V_36 , V_35 ) ;
}
V_2 -> V_53 = V_32 -> V_54 ;
V_2 -> V_55 = V_32 -> V_56 ;
V_28 = F_11 ( V_2 , V_4 ) ;
if ( V_28 == - 1 )
F_12 ( V_2 -> V_49 -> V_50 , L_2 ) ;
return V_28 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_57 * V_49 = V_2 -> V_49 ;
int V_28 = 0 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
T_2 V_58 [ V_59 ] ;
T_1 V_60 , V_37 , V_38 , V_61 ;
struct V_62 * V_63 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_60 = F_5 ( V_32 -> V_60 ) ;
V_37 = F_5 ( V_32 -> V_37 ) ;
V_38 = F_5 ( V_32 -> V_38 ) ;
V_61 = F_5 ( V_32 -> V_61 ) ;
V_30 = ( void * ) V_32 + V_37 ;
if ( ( V_37 + V_38 ) > ( T_1 ) V_4 -> V_64 ) {
F_12 ( V_49 -> V_50 ,
L_3 ,
V_4 -> V_64 , V_37 , V_38 ) ;
V_2 -> V_65 . V_66 ++ ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( V_60 == V_67 ) {
V_28 = F_14 ( V_2 , V_4 ) ;
if ( V_28 )
F_12 ( V_49 -> V_50 , L_4 ) ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( ( ! F_15 ( V_2 ) &&
! ( F_9 ( V_2 -> V_49 -> V_51 ) &&
! ( V_32 -> V_68 & V_69 ) ) ) ||
! F_16 ( V_2 -> V_70 , V_30 -> V_45 . V_46 ) ) {
F_4 ( V_2 , V_4 ) ;
return V_28 ;
}
if ( F_17 ( V_2 ) ||
( F_9 ( V_2 -> V_49 -> V_51 ) &&
V_32 -> V_68 & V_69 ) ) {
memcpy ( V_58 , V_30 -> V_45 . V_47 , V_59 ) ;
if ( V_32 -> V_68 & V_69 &&
V_32 -> V_71 < V_72 ) {
V_63 = F_18 ( V_2 , V_58 ) ;
if ( V_63 )
V_63 -> V_73 [ V_32 -> V_71 ] =
F_5 ( V_32 -> V_61 ) ;
}
} else {
if ( V_60 != V_74 )
V_2 -> V_73 [ V_32 -> V_71 ] = V_61 ;
memcpy ( V_58 , V_2 -> V_75 . V_76 . V_77 ,
V_59 ) ;
}
V_28 = F_19 ( V_2 , V_61 , V_32 -> V_71 ,
V_58 , ( T_2 ) V_60 , V_4 ) ;
if ( V_28 || ( V_60 == V_74 ) )
F_8 ( V_4 ) ;
if ( V_28 )
V_2 -> V_65 . V_66 ++ ;
return V_28 ;
}
