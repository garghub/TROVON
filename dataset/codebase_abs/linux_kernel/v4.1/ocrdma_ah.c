static inline int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , union V_7 * V_8 ,
int V_9 , bool * V_10 )
{
int V_11 = 0 ;
T_1 V_12 ;
struct V_13 V_14 ;
struct V_15 V_16 ;
int V_17 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_12 = V_6 -> V_18 ;
if ( ! V_12 || ( V_12 > 0xFFF ) )
V_12 = V_2 -> V_19 ;
if ( V_12 || V_2 -> V_20 ) {
if ( ! V_12 ) {
F_2 ( L_1 ,
V_2 -> V_21 ) ;
F_2 ( L_2 ,
V_2 -> V_21 ) ;
}
V_14 . V_22 = F_3 ( 0x8100 ) ;
V_14 . V_23 = F_3 ( V_24 ) ;
V_12 |= ( V_2 -> V_25 & 0x07 ) << V_26 ;
V_14 . V_12 = F_3 ( V_12 ) ;
V_17 = sizeof( struct V_13 ) ;
* V_10 = true ;
} else {
V_14 . V_22 = F_3 ( V_24 ) ;
V_17 = sizeof( struct V_27 ) ;
}
memcpy ( & V_14 . V_28 [ 0 ] , & V_2 -> V_29 . V_30 [ 0 ] , V_31 ) ;
V_11 = F_4 ( V_2 , V_6 , & V_14 . V_32 [ 0 ] ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_33 = V_6 -> V_16 . V_33 ;
memcpy ( & V_16 . V_8 [ 0 ] , V_8 -> V_34 , sizeof( union V_7 ) ) ;
memcpy ( & V_16 . V_35 [ 0 ] , V_6 -> V_16 . V_35 . V_34 , sizeof( V_6 -> V_16 . V_35 . V_34 ) ) ;
V_16 . V_36 = F_5 ( ( 6 << 28 ) |
( V_6 -> V_16 . V_37 << 24 ) |
V_6 -> V_16 . V_38 ) ;
V_16 . V_39 = F_5 ( ( V_9 << 16 ) |
( 0x1b << 8 ) | V_6 -> V_16 . V_40 ) ;
memcpy ( & V_4 -> V_41 -> V_42 , & V_14 , V_17 ) ;
memcpy ( ( V_43 * ) V_4 -> V_41 + V_17 , & V_16 , sizeof( struct V_15 ) ) ;
if ( * V_10 )
V_4 -> V_41 -> V_44 |= V_45 ;
V_4 -> V_41 -> V_44 = F_6 ( V_4 -> V_41 -> V_44 ) ;
return V_11 ;
}
struct V_46 * F_7 ( struct V_47 * V_48 , struct V_5 * V_6 )
{
T_2 * V_49 ;
bool V_10 = false ;
int V_11 ;
struct V_3 * V_4 ;
struct V_50 * V_51 = F_8 ( V_48 ) ;
struct V_1 * V_2 = F_9 ( V_48 -> V_52 ) ;
union V_7 V_8 ;
if ( ! ( V_6 -> V_53 & V_54 ) )
return F_10 ( - V_55 ) ;
if ( F_11 ( & V_2 -> V_56 , 1 , 0 ) )
F_12 ( V_2 ) ;
V_4 = F_13 ( sizeof( * V_4 ) , V_57 ) ;
if ( ! V_4 )
return F_10 ( - V_58 ) ;
V_11 = F_14 ( V_2 , V_4 ) ;
if ( V_11 )
goto V_59;
V_11 = F_15 ( & V_2 -> V_60 , 1 , V_6 -> V_16 . V_33 , & V_8 ) ;
if ( V_11 ) {
F_2 ( L_3 ,
V_61 , V_11 ) ;
goto V_62;
}
if ( ( V_51 -> V_63 ) &&
( ! F_16 ( (struct V_64 * ) V_6 -> V_16 . V_35 . V_34 ) ) &&
( ! F_17 ( (struct V_64 * ) V_6 -> V_16 . V_35 . V_34 ) ) ) {
V_11 = F_18 ( & V_8 , & V_6 -> V_16 . V_35 ,
V_6 -> V_32 , & V_6 -> V_18 ) ;
if ( V_11 ) {
F_2 ( L_4
L_5 , V_61 , V_11 ) ;
goto V_62;
}
}
V_11 = F_1 ( V_2 , V_4 , V_6 , & V_8 , V_51 -> V_21 , & V_10 ) ;
if ( V_11 )
goto V_62;
if ( ( V_51 -> V_63 ) && ( V_51 -> V_63 -> V_65 . V_66 ) ) {
V_49 = V_51 -> V_63 -> V_65 . V_66 + V_6 -> V_67 ;
* V_49 = 0 ;
* V_49 |= V_4 -> V_21 & V_68 ;
if ( V_10 )
* V_49 |= ( V_69 <<
V_70 ) ;
}
return & V_4 -> V_71 ;
V_62:
F_19 ( V_2 , V_4 ) ;
V_59:
F_20 ( V_4 ) ;
return F_10 ( V_11 ) ;
}
int F_21 ( struct V_46 * V_71 )
{
struct V_3 * V_4 = F_22 ( V_71 ) ;
struct V_1 * V_2 = F_9 ( V_71 -> V_52 ) ;
F_19 ( V_2 , V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
int F_23 ( struct V_46 * V_71 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_22 ( V_71 ) ;
struct V_72 * V_41 = V_4 -> V_41 ;
struct V_15 * V_16 ;
V_6 -> V_53 |= V_54 ;
if ( V_4 -> V_41 -> V_44 & V_73 ) {
V_16 = (struct V_15 * ) ( ( V_43 * ) V_4 -> V_41 +
sizeof( struct V_13 ) ) ;
V_6 -> V_25 = F_24 ( V_41 -> V_42 . V_12 ) >> 13 ;
} else {
V_16 = (struct V_15 * ) ( ( V_43 * ) V_4 -> V_41 +
sizeof( struct V_27 ) ) ;
V_6 -> V_25 = 0 ;
}
memcpy ( & V_6 -> V_16 . V_35 . V_34 [ 0 ] , & V_16 -> V_35 [ 0 ] , sizeof( V_16 -> V_35 ) ) ;
V_6 -> V_16 . V_33 = V_4 -> V_33 ;
V_6 -> V_16 . V_40 = F_25 ( V_16 -> V_39 ) & 0xff ;
V_6 -> V_16 . V_37 = F_25 ( V_16 -> V_36 ) >> 24 ;
V_6 -> V_16 . V_38 = F_25 ( V_16 -> V_36 ) & 0x00ffffffff ;
return 0 ;
}
int F_26 ( struct V_46 * V_71 , struct V_5 * V_6 )
{
return - V_74 ;
}
int F_27 ( struct V_75 * V_60 ,
int V_76 ,
V_43 V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 ,
struct V_82 * V_83 , struct V_82 * V_84 )
{
int V_11 ;
struct V_1 * V_2 ;
switch ( V_83 -> V_85 . V_86 ) {
case V_87 :
V_2 = F_9 ( V_60 ) ;
if ( ! F_28 ( V_2 , V_84 ) )
V_11 = V_88 | V_89 ;
else
V_11 = V_88 ;
break;
default:
V_11 = V_88 ;
break;
}
return V_11 ;
}
