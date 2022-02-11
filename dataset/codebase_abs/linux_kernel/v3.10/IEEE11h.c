static bool F_1 ( T_1 V_1 , T_2 V_2 ,
unsigned int V_3 )
{
T_3 V_4 = 0 ;
bool V_5 = true ;
if ( V_3 <= V_6 )
memcpy ( V_1 -> V_7 , V_2 , V_3 ) ;
V_4 = ( ( V_3 - F_2 ( V_8 ,
V_9 ) ) /
( sizeof( V_10 ) ) ) ;
V_1 -> V_11 = & ( ( ( V_12 )
( V_1 -> V_13 ) ) -> V_14 [ 0 ] ) ;
V_1 -> V_15 = 0 ;
V_5 = F_3 ( V_1 -> V_16 ,
( ( T_2 )
( V_1 -> V_7 ) ) -> V_9 ,
V_4
) ;
return V_5 ;
}
static bool F_4 ( T_1 V_1 ,
T_4 V_17 ,
unsigned char V_18 ,
unsigned char V_19 )
{
T_5 V_20 ;
T_6 V_21 = NULL ;
V_21 = ( T_6 ) V_1 -> V_22 ;
memset ( V_21 , 0 , sizeof( V_23 ) + V_6 ) ;
V_21 -> V_24 = ( V_25 ) ( ( unsigned char * ) V_21 +
sizeof( V_23 ) ) ;
V_20 = ( T_5 ) ( ( unsigned char * ) V_21 +
sizeof( V_23 ) ) ;
V_20 -> V_26 . V_27 = ( F_5 ( V_28 ) |
F_6 ( V_29 )
) ;
memcpy ( V_20 -> V_26 . V_30 ,
V_17 -> V_26 . V_31 ,
V_32 ) ;
memcpy ( V_20 -> V_26 . V_31 ,
F_7 ( V_1 -> V_16 ) ,
V_32 ) ;
memcpy ( V_20 -> V_26 . V_33 ,
V_1 -> V_34 ,
V_35 ) ;
V_20 -> V_36 = 0 ;
V_20 -> V_37 = 3 ;
V_20 -> V_38 = ( ( T_2 )
( V_1 -> V_7 ) ) -> V_38 ;
V_20 -> V_39 . V_40 = V_41 ;
V_20 -> V_39 . V_42 = 2 ;
V_20 -> V_39 . V_43 = F_8 ( V_1 -> V_16 ) ;
switch ( V_18 ) {
case V_44 :
V_20 -> V_39 . V_45 = 65 - V_19 ;
break;
case V_46 :
V_20 -> V_39 . V_45 = 66 - V_19 ;
break;
case V_47 :
V_20 -> V_39 . V_45 = 70 - V_19 ;
break;
case V_48 :
V_20 -> V_39 . V_45 = 74 - V_19 ;
break;
case V_49 :
V_20 -> V_39 . V_45 = 77 - V_19 ;
break;
case V_50 :
V_20 -> V_39 . V_45 = 79 - V_19 ;
break;
case V_51 :
V_20 -> V_39 . V_45 = 81 - V_19 ;
break;
case V_52 :
default:
V_20 -> V_39 . V_45 = 82 - V_19 ;
break;
}
V_21 -> V_53 = sizeof( V_54 ) ;
V_21 -> V_55 = sizeof( V_54 ) -
V_56 ;
if ( F_9 ( V_1 -> V_16 , V_21 ) != V_57 )
return false ;
return true ;
}
bool
F_10 ( void * V_58 , void * V_59 )
{
T_1 V_1 = ( T_1 ) V_58 ;
T_7 V_60 = NULL ;
unsigned int V_3 = 0 ;
T_8 V_61 = NULL ;
V_3 = ( ( V_62 ) V_59 ) -> V_53 ;
if ( V_3 > V_6 )
return false ;
V_60 = ( T_7 )
( ( ( V_62 ) V_59 ) -> V_24 ) ;
if ( V_60 -> V_36 == 0 ) {
switch ( V_60 -> V_37 ) {
case V_63 :
return F_1 ( V_1 ,
( T_2 )
V_60 ,
V_3 ) ;
break;
case V_64 :
break;
case V_65 :
return F_4 ( V_1 ,
( T_4 ) V_60 ,
( ( V_62 ) V_59 ) -> V_66 ,
( unsigned char )
( ( V_62 ) V_59 ) -> V_67 ) ;
break;
case V_68 :
break;
case V_69 :
V_61 = ( T_8 ) ( V_60 -> V_70 ) ;
if ( ( V_61 -> V_40 == V_71 )
&& ( V_61 -> V_42 == 3 ) ) {
F_11 ( V_1 -> V_16 ,
V_61 -> V_72 ,
F_12 ( V_1 -> V_16 ,
V_61 -> V_73 ,
V_1 -> V_74 ) ,
V_61 -> V_75 ) ;
}
break;
default:
F_13 ( V_76 ,
V_77 L_1 ,
V_60 -> V_37 ) ;
break;
}
} else {
F_13 ( V_76 , V_77 L_2 ,
V_60 -> V_36 ) ;
V_60 -> V_36 |= 0x80 ;
return true ;
}
return true ;
}
bool F_14 ( void * V_58 )
{
T_1 V_1 = ( T_1 ) V_58 ;
V_12 V_78 = ( V_12 )
( V_1 -> V_13 + sizeof( V_23 ) ) ;
T_3 V_3 = 0 ;
T_6 V_21 = NULL ;
V_21 = ( T_6 ) V_1 -> V_13 ;
memset ( V_21 , 0 , sizeof( V_23 ) + V_6 ) ;
V_21 -> V_24 = ( V_25 ) ( ( unsigned char * ) V_21 +
sizeof( V_23 ) ) ;
V_78 -> V_26 . V_27 = ( F_5 ( V_28 ) |
F_6 ( V_29 )
) ;
memcpy ( V_78 -> V_26 . V_30 , ( ( T_2 )
( V_1 -> V_7 ) ) -> V_26 . V_31 , V_32 ) ;
memcpy ( V_78 -> V_26 . V_31 ,
F_7 ( V_1 -> V_16 ) , V_32 ) ;
memcpy ( V_78 -> V_26 . V_33 , V_1 -> V_34 , V_35 ) ;
V_78 -> V_36 = 0 ;
V_78 -> V_37 = 1 ;
V_78 -> V_38 = ( ( T_2 )
( V_1 -> V_7 ) ) -> V_38 ;
V_3 = V_1 -> V_15 + F_2 ( V_79 ,
V_14 ) ;
V_21 -> V_53 = V_3 ;
V_21 -> V_55 = V_3 - V_56 ;
if ( F_9 ( V_1 -> V_16 , V_21 ) != V_57 )
return false ;
return true ;
}
