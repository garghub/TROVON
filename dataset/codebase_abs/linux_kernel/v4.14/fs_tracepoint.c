static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 )
{
#define F_2 ( type , T_2 , T_3 ) \
MASK_VAL(type, fte_match_set_lyr_2_4, name, mask, value, fld)
F_3 ( V_5 , V_6 ) = {
. V_7 = F_4 ( V_8 , V_3 , V_9 ) << 16 |
F_4 ( V_8 , V_3 , V_10 ) ,
. V_11 = F_4 ( V_8 , V_4 , V_9 ) << 16 |
F_4 (fte_match_set_lyr_2_4, value, smac_15_0) } ;
F_3 ( V_5 , V_12 ) = {
. V_7 = F_4 ( V_8 , V_3 , V_13 ) << 16 |
F_4 ( V_8 , V_3 , V_14 ) ,
. V_11 = F_4 ( V_8 , V_4 , V_13 ) << 16 |
F_4 (fte_match_set_lyr_2_4, value, dmac_15_0) } ;
F_2 ( V_15 , V_16 , V_16 ) ;
F_5 ( V_6 , V_17 * , V_2 , L_1 ) ;
F_5 ( V_12 , V_17 * , V_2 , L_1 ) ;
F_6 ( V_16 , V_2 , L_2 ) ;
if ( V_16 . V_7 == 0xffff ) {
if ( V_16 . V_11 == V_18 ) {
#define F_7 ( type , T_2 , T_3 ) \
MASK_VAL_BE(type, fte_match_set_lyr_2_4, name, mask, value, fld)
F_7 ( T_1 , V_19 ,
V_20 . V_21 . V_22 ) ;
F_7 ( T_1 , V_23 ,
V_24 . V_21 . V_22 ) ;
F_5 ( V_19 , F_8 ( & V_19 . V_11 ) , V_2 ,
L_3 ) ;
F_5 ( V_23 , F_8 ( & V_23 . V_11 ) , V_2 ,
L_3 ) ;
} else if ( V_16 . V_11 == V_25 ) {
static const struct V_26 V_27 = {
. V_28 . V_29 = { F_9 ( 0xffffffff ) ,
F_9 ( 0xffffffff ) ,
F_9 ( 0xffffffff ) ,
F_9 ( 0xffffffff ) } ,
} ;
F_3 ( struct V_26 , V_30 ) ;
F_3 ( struct V_26 , V_31 ) ;
memcpy ( V_30 . V_7 . V_28 . V_32 ,
F_10 ( V_8 , V_3 ,
V_20 . V_33 . V_34 ) ,
sizeof( V_30 . V_7 ) ) ;
memcpy ( V_31 . V_7 . V_28 . V_32 ,
F_10 ( V_8 , V_3 ,
V_24 . V_33 . V_34 ) ,
sizeof( V_31 . V_7 ) ) ;
memcpy ( V_30 . V_11 . V_28 . V_32 ,
F_10 ( V_8 , V_4 ,
V_20 . V_33 . V_34 ) ,
sizeof( V_30 . V_11 ) ) ;
memcpy ( V_31 . V_11 . V_28 . V_32 ,
F_10 ( V_8 , V_4 ,
V_24 . V_33 . V_34 ) ,
sizeof( V_31 . V_11 ) ) ;
if ( ! memcmp ( & V_30 . V_7 , & V_27 , sizeof( V_27 ) ) )
F_11 ( V_2 , L_4 ,
& V_30 . V_11 ) ;
if ( ! memcmp ( & V_31 . V_7 , & V_27 , sizeof( V_27 ) ) )
F_11 ( V_2 , L_5 ,
& V_31 . V_11 ) ;
}
}
#define F_12 ( type , T_2 , T_3 , V_2 , T_4 ) {\
MASK_VAL_L2(type, name, fld); \
PRINT_MASKED_VAL(name, p, format); \
}
F_12 ( V_17 , V_35 , V_35 , V_2 , L_6 ) ;
F_12 ( V_15 , V_36 , V_36 , V_2 , L_7 ) ;
F_12 ( V_15 , V_37 , V_37 , V_2 , L_8 ) ;
F_12 ( V_15 , V_38 , V_38 , V_2 , L_8 ) ;
F_12 ( V_15 , V_39 , V_39 , V_2 , L_8 ) ;
F_12 ( V_15 , V_40 , V_40 , V_2 , L_8 ) ;
F_12 ( V_15 , V_41 , V_41 , V_2 , L_2 ) ;
F_12 ( V_17 , V_42 , V_42 , V_2 , L_7 ) ;
F_12 ( V_17 , V_43 , V_43 , V_2 , L_9 ) ;
F_12 ( V_17 , V_44 , V_44 , V_2 , L_6 ) ;
F_12 ( V_17 , V_45 , V_45 , V_2 , L_7 ) ;
F_12 ( V_17 , V_46 , V_46 , V_2 , L_9 ) ;
F_12 ( V_17 , V_47 , V_47 , V_2 , L_9 ) ;
F_12 ( V_17 , V_48 , V_48 , V_2 , L_9 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 )
{
#define F_14 ( type , T_2 , T_3 ) \
MASK_VAL(type, fte_match_set_misc, name, mask, value, fld)
#define F_15 ( type , T_2 , T_3 , V_2 , T_4 ) {\
MASK_VAL_MISC(type, name, fld); \
PRINT_MASKED_VAL(name, p, format); \
}
F_3 ( V_5 , V_49 ) = {
. V_7 = F_4 ( V_50 , V_3 , V_51 ) << 8 |
F_4 ( V_50 , V_3 , V_52 ) ,
. V_11 = F_4 ( V_50 , V_4 , V_51 ) << 8 |
F_4 (fte_match_set_misc, value, gre_key_l) } ;
F_6 ( V_49 , V_2 , L_10 ) ;
F_15 ( T_1 , V_53 , V_53 , V_2 , L_8 ) ;
F_15 ( V_15 , V_54 , V_54 , V_2 , L_8 ) ;
F_15 ( V_17 , V_55 , V_55 ,
V_2 , L_8 ) ;
F_15 ( V_17 , V_56 , V_56 , V_2 , L_8 ) ;
F_15 ( V_15 , V_57 , V_57 , V_2 , L_8 ) ;
F_15 ( V_17 , V_58 , V_58 ,
V_2 , L_8 ) ;
F_15 ( V_17 , V_59 , V_59 , V_2 , L_8 ) ;
F_15 ( V_15 , V_60 , V_60 , V_2 , L_8 ) ;
F_15 ( V_17 , V_61 ,
V_61 , V_2 , L_8 ) ;
F_15 ( V_17 , V_62 ,
V_62 , V_2 , L_8 ) ;
F_15 ( V_17 , V_63 ,
V_63 , V_2 , L_8 ) ;
F_15 ( V_17 , V_64 ,
V_64 , V_2 , L_8 ) ;
F_15 ( V_17 , V_65 , V_65 , V_2 , L_8 ) ;
F_15 ( T_1 , V_66 , V_66 , V_2 , L_8 ) ;
F_15 ( T_1 , V_67 , V_67 ,
V_2 , L_7 ) ;
F_15 ( T_1 , V_68 , V_68 ,
V_2 , L_7 ) ;
}
const char * F_16 ( struct V_1 * V_2 ,
V_17 V_69 ,
const T_1 * V_70 ,
const T_1 * V_71 ,
const T_1 * V_72 ,
const T_1 * V_73 ,
const T_1 * V_74 ,
const T_1 * V_75 )
{
const char * V_76 = F_17 ( V_2 ) ;
if ( V_69 &
1 << V_77 ) {
F_11 ( V_2 , L_11 ) ;
F_1 ( V_2 , V_70 , V_73 ) ;
}
if ( V_69 &
1 << V_78 ) {
F_11 ( V_2 , L_12 ) ;
F_13 ( V_2 , V_71 , V_74 ) ;
}
if ( V_69 &
1 << V_79 ) {
F_11 ( V_2 , L_13 ) ;
F_1 ( V_2 , V_72 , V_75 ) ;
}
F_18 ( V_2 , 0 ) ;
return V_76 ;
}
const char * F_19 ( struct V_1 * V_2 ,
const struct V_80 * V_81 ,
T_1 V_82 )
{
const char * V_76 = F_17 ( V_2 ) ;
switch ( V_81 -> type ) {
case V_83 :
F_11 ( V_2 , L_14 , V_81 -> V_84 ) ;
break;
case V_85 :
F_11 ( V_2 , L_15 , V_81 -> V_86 ) ;
break;
case V_87 :
F_11 ( V_2 , L_16 , V_81 -> V_88 ) ;
break;
case V_89 :
F_11 ( V_2 , L_17 , V_82 ) ;
break;
}
F_18 ( V_2 , 0 ) ;
return V_76 ;
}
