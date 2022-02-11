static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( 0 , 0 ) ;
T_1 V_8 = 0 ;
T_1 V_9 = 0 ;
#define F_3 0xD0810600
#define F_4 (1 << 11)
#define F_5 0xD0810900
#define F_5 0xD0810900
#define F_6 0x7000
#define F_7 12
#define F_8 0
#define F_9 1
#define F_10 2
F_11 ( V_7 , 0xD0 , F_3 ) ;
F_12 ( V_7 , 0xD4 , & V_8 ) ;
if ( F_13 ( V_2 ) )
V_4 -> V_10 = V_8 & F_4 ;
F_14 ( L_1 ,
V_4 -> V_10 ? L_2 : L_3 ) ;
if ( V_4 -> V_10 ) {
V_4 -> V_11 = true ;
V_4 -> V_12 = false ;
} else {
V_4 -> V_12 = true ;
V_4 -> V_11 = false ;
}
V_4 -> V_13 = V_8 ;
F_11 ( V_7 , 0xD0 , F_5 ) ;
F_12 ( V_7 , 0xD4 , & V_8 ) ;
F_15 ( V_2 -> V_2 , L_4 , V_8 ) ;
V_9 = ( V_8 & F_6 ) >> F_7 ;
V_4 -> V_14 = V_8 ;
switch ( V_9 ) {
case F_8 :
V_4 -> V_15 = 200 ;
break;
case F_9 :
V_4 -> V_15 = 100 ;
break;
case F_10 :
V_4 -> V_15 = 166 ;
break;
default:
F_16 ( V_2 -> V_2 , L_5 ,
V_9 ) ;
V_4 -> V_15 = 0 ;
}
F_15 ( V_2 -> V_2 , L_6 , V_4 -> V_15 ) ;
F_17 ( V_7 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
T_1 V_16 = 0 ;
struct V_6 * V_17 = F_2 ( 0 , F_19 ( 2 , 0 ) ) ;
F_12 ( V_17 , 0x08 , & V_16 ) ;
V_4 -> V_16 = ( V_18 ) V_16 ;
F_17 ( V_17 ) ;
F_15 ( V_4 -> V_2 -> V_2 , L_7 ,
V_4 -> V_16 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_19 * V_20 = & V_4 -> V_21 ;
T_2 V_22 ;
T_3 V_23 ;
T_4 * V_24 ;
T_4 V_25 ;
T_4 V_26 = 0 ;
struct V_27 * V_28 = & V_4 -> V_29 . V_30 ;
struct V_31 V_32 ;
void * V_33 ;
struct V_6 * V_17 = F_2 ( 0 , F_19 ( 2 , 0 ) ) ;
F_12 ( V_17 , 0xFC , & V_22 ) ;
F_17 ( V_17 ) ;
F_15 ( V_2 -> V_2 , L_8 , V_22 ) ;
if ( V_22 == 0 ) {
V_20 -> V_34 = 0 ;
return;
}
V_24 = F_21 ( V_22 , sizeof( * V_20 ) ) ;
memcpy ( V_20 , V_24 , sizeof( * V_20 ) ) ;
F_22 ( V_24 ) ;
F_15 ( V_2 -> V_2 , L_9 , V_20 -> V_35 ) ;
switch ( V_20 -> V_35 ) {
case 0 :
V_20 -> V_36 = F_21 ( V_22 + sizeof( * V_20 ) - 4 ,
V_20 -> V_34 - sizeof( * V_20 ) + 4 ) ;
V_33 = V_20 -> V_36 ;
V_25 = ( (struct V_37 * ) V_33 ) -> V_38 . V_39 ;
V_4 -> V_29 . V_25 = V_25 ;
V_4 -> V_29 . V_40 =
( (struct V_37 * ) V_33 ) -> V_38 . V_41 ;
memcpy ( & V_4 -> V_29 . V_30 ,
& ( (struct V_37 * ) V_33 ) -> V_42 [ V_25 ] . V_30 ,
sizeof( struct V_27 ) ) ;
V_4 -> V_29 . V_43 =
( (struct V_37 * ) V_33 ) -> V_42 [ V_25 ] . V_43 ;
V_4 -> V_29 . V_44 =
( (struct V_37 * ) V_33 ) -> V_42 [ V_25 ] . V_44 ;
break;
case 1 :
V_20 -> V_36 = F_21 ( V_22 + sizeof( * V_20 ) - 4 ,
V_20 -> V_34 - sizeof( * V_20 ) + 4 ) ;
V_33 = V_20 -> V_36 ;
V_25 = ( (struct V_45 * ) V_33 ) -> V_38 . V_39 ;
V_4 -> V_29 . V_25 = V_25 ;
V_4 -> V_29 . V_40 =
( (struct V_45 * ) V_33 ) -> V_38 . V_41 ;
memcpy ( & V_4 -> V_29 . V_30 ,
& ( (struct V_45 * ) V_33 ) -> V_42 [ V_25 ] . V_30 ,
sizeof( struct V_27 ) ) ;
V_4 -> V_29 . V_43 =
( (struct V_45 * ) V_33 ) -> V_42 [ V_25 ] . V_43 ;
V_4 -> V_29 . V_44 =
( (struct V_45 * ) V_33 ) -> V_42 [ V_25 ] . V_44 ;
break;
case 0x10 :
V_23 = V_20 -> V_46 ;
V_23 |= ( ( 0xff & ( unsigned int ) V_20 -> V_36 ) ) << 8 ;
V_20 -> V_46 = V_20 -> V_34 ;
if ( V_23 > 0xff )
V_20 -> V_34 = 0xff ;
else
V_20 -> V_34 = V_23 ;
V_26 = ( ( 0xff00 & ( unsigned int ) V_20 -> V_36 ) ) >> 8 ;
V_25 = ( ( 0xff0000 & ( unsigned int ) V_20 -> V_36 ) ) >> 16 ;
V_20 -> V_36 = F_21 ( V_22 + V_47 ,
V_48 * V_26 ) ;
V_33 = V_20 -> V_36 ;
V_33 = ( T_4 * ) V_33 + ( V_25 * V_48 ) ;
V_4 -> V_29 . V_25 = V_25 ;
memcpy ( & V_32 , V_33 , sizeof( struct V_31 ) ) ;
V_28 -> V_49 = V_32 . V_49 ;
V_28 -> V_50 = V_32 . V_50 ;
V_28 -> V_51 = V_32 . V_51 ;
V_28 -> V_52 = V_32 . V_52 ;
V_28 -> V_53 = V_32 . V_53 ;
V_28 -> V_54 = V_32 . V_54 ;
V_28 -> V_55 = V_32 . V_55 ;
V_28 -> V_56 = V_32 . V_56 ;
V_28 -> V_57 = V_32 . V_57 ;
V_28 -> V_58 = V_32 . V_58 ;
V_28 -> V_59 = V_32 . V_59 ;
V_28 -> V_60 = V_32 . V_60 ;
V_28 -> V_61 = V_32 . V_61 ;
V_28 -> V_62 = V_32 . V_62 ;
V_28 -> V_63 = V_32 . V_63 ;
V_28 -> V_64 = V_32 . V_64 ;
V_28 -> V_65 = V_32 . V_65 ;
V_4 -> V_29 . V_44 =
* ( ( T_4 * ) V_33 + 0x0d ) ;
V_4 -> V_29 . V_44 |=
( * ( ( T_4 * ) V_33 + 0x0e ) ) << 8 ;
break;
default:
F_23 ( V_2 -> V_2 , L_10 ) ;
V_20 -> V_34 = 0 ;
}
if ( F_24 ( V_4 -> V_2 ) ) {
if ( V_66 == V_67 ) {
if ( V_4 -> V_29 . V_25 == 2 ) {
F_25 ( V_2 -> V_2 , L_11 ) ;
V_4 -> V_66 = V_68 ;
V_66 = V_68 ;
} else if ( V_4 -> V_29 . V_25 == 0 ) {
F_25 ( V_2 -> V_2 , L_12 ) ;
V_4 -> V_66 = V_69 ;
V_66 = V_69 ;
} else {
F_25 ( V_2 -> V_2 , L_13 ) ;
V_4 -> V_66 = V_70 ;
V_66 = V_70 ;
}
} else {
F_25 ( V_2 -> V_2 , L_14 ) ;
V_4 -> V_66 = V_66 ;
}
}
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_1 ( V_2 ) ;
F_20 ( V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
