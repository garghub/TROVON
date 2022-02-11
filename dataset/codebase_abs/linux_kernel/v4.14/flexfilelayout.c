static T_1
F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
struct V_4 * args )
{
struct V_5 * V_6 = & args -> V_7 ;
T_2 V_8 = 0 ;
int error ;
T_3 V_9 ;
struct V_10 * V_11 ;
error = - V_12 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
goto V_14;
args -> V_15 = V_11 ;
V_11 -> V_16 = V_17 | V_18 |
V_19 ;
if ( V_6 -> V_20 == V_21 ) {
V_9 = F_3 ( & V_22 , V_1 -> V_23 ) + 1 ;
V_11 -> V_24 = F_4 ( & V_22 , V_9 ) ;
} else
V_11 -> V_24 = V_1 -> V_23 ;
V_11 -> V_25 = V_1 -> V_26 ;
error = F_5 ( & V_11 -> V_27 , V_3 , V_8 ) ;
if ( error )
goto V_14;
V_11 -> V_28 . V_29 = V_3 -> V_30 . V_31 ;
memcpy ( V_11 -> V_28 . V_32 , & V_3 -> V_30 . V_33 , V_11 -> V_28 . V_29 ) ;
V_6 -> V_34 = 0 ;
V_6 -> V_35 = V_36 ;
F_6 ( L_1 , V_6 -> V_34 , V_6 -> V_35 ,
V_6 -> V_20 ) ;
return 0 ;
V_14:
V_6 -> V_35 = 0 ;
return F_7 ( error ) ;
}
static T_1
F_8 ( struct V_37 * V_38 , struct V_39 * V_40 ,
struct V_41 * V_42 , struct V_43 * V_44 )
{
struct V_45 * V_46 ;
T_4 V_47 ;
char V_48 [ V_49 ] ;
V_46 = F_2 ( sizeof( struct V_45 ) , V_13 ) ;
if ( ! V_46 )
return F_7 ( - V_12 ) ;
V_44 -> V_50 = V_46 ;
V_46 -> V_51 = 3 ;
V_46 -> V_52 = 0 ;
V_46 -> V_53 = F_9 ( V_40 ) ;
V_46 -> V_54 = V_46 -> V_53 ;
F_10 ( (struct V_55 * ) & V_40 -> V_56 ,
V_48 , V_49 ) ;
if ( V_40 -> V_56 . V_57 == V_58 ) {
struct V_59 * sin ;
sin = (struct V_59 * ) & V_40 -> V_56 ;
V_47 = F_11 ( sin -> V_60 ) ;
snprintf ( V_46 -> V_61 . V_62 , V_63 + 1 , L_2 ) ;
V_46 -> V_61 . V_64 = 3 ;
} else {
struct V_65 * V_66 ;
V_66 = (struct V_65 * ) & V_40 -> V_56 ;
V_47 = F_11 ( V_66 -> V_67 ) ;
snprintf ( V_46 -> V_61 . V_62 , V_63 + 1 , L_3 ) ;
V_46 -> V_61 . V_64 = 4 ;
}
V_46 -> V_61 . V_68 =
snprintf ( V_46 -> V_61 . V_48 , V_69 + 1 ,
L_4 , V_48 , V_47 >> 8 , V_47 & 0xff ) ;
V_46 -> V_70 = false ;
return 0 ;
}
