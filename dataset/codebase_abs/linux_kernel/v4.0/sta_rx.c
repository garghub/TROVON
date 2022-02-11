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
T_2 V_37 = 0 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_34 = F_5 ( V_32 -> V_38 ) ;
V_35 = F_5 ( V_32 -> V_39 ) ;
V_30 = ( void * ) V_32 + V_34 ;
if ( ( ! memcmp ( & V_30 -> V_40 , V_41 ,
sizeof( V_41 ) ) ) ||
( ! memcmp ( & V_30 -> V_40 , V_42 ,
sizeof( V_42 ) ) &&
F_2 ( V_30 -> V_40 . V_43 ) != V_44 &&
F_2 ( V_30 -> V_40 . V_43 ) != V_45 ) ) {
V_8 = (struct V_7 * )
( ( T_2 * ) & V_30 -> V_46
+ sizeof( V_30 -> V_46 ) +
sizeof( V_30 -> V_40 )
- sizeof( V_30 -> V_46 . V_47 )
- sizeof( V_30 -> V_46 . V_48 )
- sizeof( V_30 -> V_40 . V_43 ) ) ;
memcpy ( V_8 -> V_48 , V_30 -> V_46 . V_48 ,
sizeof( V_8 -> V_48 ) ) ;
memcpy ( V_8 -> V_47 , V_30 -> V_46 . V_47 ,
sizeof( V_8 -> V_47 ) ) ;
V_33 = ( T_2 * ) V_8 - ( T_2 * ) V_32 ;
} else {
V_33 = ( T_2 * ) & V_30 -> V_46 -
( T_2 * ) V_32 ;
}
F_6 ( V_4 , V_33 ) ;
if ( V_2 -> V_49 &&
F_1 ( V_2 , V_4 ) ) {
F_7 ( V_2 -> V_50 -> V_51 , L_1 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
if ( F_9 ( V_2 -> V_50 -> V_52 ) &&
F_2 ( V_30 -> V_46 . V_14 ) == V_53 ) {
V_36 = ( T_2 * ) V_32 + V_34 ;
F_10 ( V_2 , V_36 , V_35 ) ;
}
V_2 -> V_54 = V_32 -> V_55 ;
V_2 -> V_56 = V_32 -> V_57 ;
if ( F_11 ( V_2 ) == V_58 ||
F_11 ( V_2 ) == V_59 ) {
V_37 = F_12 ( V_2 , V_2 -> V_54 ,
V_2 -> V_56 ) ;
F_13 ( V_2 , V_37 , V_32 -> V_60 ,
V_32 -> V_61 ) ;
}
V_28 = F_14 ( V_2 , V_4 ) ;
if ( V_28 == - 1 )
F_15 ( V_2 -> V_50 -> V_51 , L_2 ) ;
return V_28 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_62 * V_50 = V_2 -> V_50 ;
int V_28 = 0 ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
T_2 V_63 [ V_64 ] ;
T_1 V_65 , V_38 , V_39 , V_66 ;
struct V_67 * V_68 ;
V_32 = (struct V_31 * ) ( V_4 -> V_13 ) ;
V_65 = F_5 ( V_32 -> V_65 ) ;
V_38 = F_5 ( V_32 -> V_38 ) ;
V_39 = F_5 ( V_32 -> V_39 ) ;
V_66 = F_5 ( V_32 -> V_66 ) ;
V_30 = ( void * ) V_32 + V_38 ;
if ( ( V_38 + V_39 ) > ( T_1 ) V_4 -> V_69 ) {
F_15 ( V_50 -> V_51 ,
L_3 ,
V_4 -> V_69 , V_38 , V_39 ) ;
V_2 -> V_70 . V_71 ++ ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( V_65 == V_72 ) {
V_28 = F_17 ( V_2 , V_4 ) ;
if ( V_28 )
F_15 ( V_50 -> V_51 , L_4 ) ;
F_8 ( V_4 ) ;
return V_28 ;
}
if ( ( ! F_18 ( V_2 ) &&
! ( F_9 ( V_2 -> V_50 -> V_52 ) &&
! ( V_32 -> V_73 & V_74 ) ) ) ||
! F_19 ( V_2 -> V_75 , V_30 -> V_46 . V_47 ) ) {
F_4 ( V_2 , V_4 ) ;
return V_28 ;
}
if ( F_20 ( V_2 ) ||
( F_9 ( V_2 -> V_50 -> V_52 ) &&
V_32 -> V_73 & V_74 ) ) {
memcpy ( V_63 , V_30 -> V_46 . V_48 , V_64 ) ;
if ( V_32 -> V_73 & V_74 &&
V_32 -> V_76 < V_77 ) {
V_68 = F_21 ( V_2 , V_63 ) ;
if ( V_68 )
V_68 -> V_78 [ V_32 -> V_76 ] =
F_5 ( V_32 -> V_66 ) ;
F_22 ( V_2 , V_63 ,
V_32 -> V_60 ,
V_32 -> V_61 ) ;
}
} else {
if ( V_65 != V_79 )
V_2 -> V_78 [ V_32 -> V_76 ] = V_66 ;
memcpy ( V_63 , V_2 -> V_80 . V_81 . V_82 ,
V_64 ) ;
}
V_28 = F_23 ( V_2 , V_66 , V_32 -> V_76 ,
V_63 , ( T_2 ) V_65 , V_4 ) ;
if ( V_28 || ( V_65 == V_79 ) )
F_8 ( V_4 ) ;
if ( V_28 )
V_2 -> V_70 . V_71 ++ ;
return V_28 ;
}
