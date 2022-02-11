static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_3 = F_2 ( V_2 -> V_6 , V_7 , V_8 ,
V_5 -> V_9 ) ;
if ( V_3 < 0 )
F_3 ( V_2 -> V_10 , L_1 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_11 , enum V_12 V_13 )
{
int V_3 ;
V_3 = F_5 ( V_2 -> V_6 , V_14 , & V_2 -> V_15 ) ;
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
goto V_16;
}
if ( V_2 -> V_15 )
F_6 ( V_2 -> V_10 , L_3 , V_2 -> V_15 ) ;
if ( ! V_11 )
V_13 = V_17 ;
switch ( V_13 ) {
case V_18 :
V_3 = F_2 ( V_2 -> V_6 , V_19 ,
V_20 << V_21 ,
( V_11 - 1 ) << V_21 ) ;
if ( V_2 -> V_22 )
V_13 |= ( V_23 << V_24 ) ;
break;
case V_25 :
V_3 = F_2 ( V_2 -> V_6 , V_19 ,
V_26 << V_27 ,
( V_11 - 1 ) << V_27 ) ;
if ( V_2 -> V_28 )
V_13 |= ( V_29 << V_30 ) ;
break;
case V_31 :
V_3 = F_2 ( V_2 -> V_6 , V_19 ,
V_20 << V_21 ,
( V_11 - 1 ) << V_21 ) ;
break;
case V_17 :
break;
default:
return V_3 ;
}
if ( V_3 < 0 ) {
F_3 ( V_2 -> V_10 , L_4 ) ;
goto V_16;
}
if ( V_2 -> V_9 )
V_13 |= ( V_32 << V_33 ) ;
V_3 = F_2 ( V_2 -> V_6 , V_7 ,
V_34 << V_35 ,
V_13 << V_35 ) ;
V_16:
return V_3 ;
}
static T_2 F_7 ( struct V_36 * V_10 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_40 )
{
T_2 V_3 ;
struct V_41 * V_42 = F_8 ( V_10 ) ;
struct V_1 * V_2 =
F_9 ( V_42 , struct V_1 , V_43 ) ;
unsigned int V_44 ;
V_3 = F_10 ( V_39 , 10 , & V_44 ) ;
if ( V_3 )
goto V_45;
if ( V_44 != 0 )
V_44 = 0x01 << V_24 ;
V_2 -> V_22 = V_44 ;
V_3 = F_2 ( V_2 -> V_6 , V_7 ,
V_23 << V_24 ,
V_44 ) ;
if ( V_3 < 0 )
goto V_16;
return V_40 ;
V_16:
F_3 ( V_2 -> V_10 , L_5 , V_46 ) ;
return V_3 ;
V_45:
F_3 ( V_2 -> V_10 , L_6 , V_46 ) ;
return V_3 ;
}
static void F_11 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_49 ) ;
F_12 ( & V_2 -> V_50 ) ;
F_4 ( V_2 , V_2 -> V_51 , V_18 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
static void F_14 ( struct V_41 * V_52 ,
enum V_53 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_52 , struct V_1 , V_54 ) ;
V_2 -> V_51 = V_11 ;
F_15 ( & V_2 -> V_49 ) ;
}
static T_2 F_16 ( struct V_36 * V_10 ,
struct V_37 * V_38 ,
const char * V_39 , T_3 V_40 )
{
T_2 V_3 ;
struct V_41 * V_42 = F_8 ( V_10 ) ;
struct V_1 * V_2 =
F_9 ( V_42 , struct V_1 , V_43 ) ;
unsigned int V_44 ;
V_3 = F_10 ( V_39 , 10 , & V_44 ) ;
if ( V_3 )
goto V_45;
if ( V_44 != 0 )
V_44 = 0x01 << V_30 ;
V_2 -> V_28 = V_44 ;
V_3 = F_2 ( V_2 -> V_6 , V_7 ,
V_29 << V_30 ,
V_44 ) ;
if ( V_3 < 0 )
goto V_16;
return V_40 ;
V_16:
F_3 ( V_2 -> V_10 , L_5 , V_46 ) ;
return V_3 ;
V_45:
F_3 ( V_2 -> V_10 , L_6 , V_46 ) ;
return V_3 ;
}
static void F_17 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_55 ) ;
F_12 ( & V_2 -> V_50 ) ;
F_4 ( V_2 , V_2 -> V_56 , V_25 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
static void F_18 ( struct V_41 * V_52 ,
enum V_53 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_52 , struct V_1 , V_57 ) ;
V_2 -> V_56 = V_11 ;
F_15 ( & V_2 -> V_55 ) ;
}
static void F_19 ( struct V_47 * V_48 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_58 ) ;
F_12 ( & V_2 -> V_50 ) ;
F_4 ( V_2 , V_2 -> V_59 , V_31 ) ;
F_13 ( & V_2 -> V_50 ) ;
}
static void F_20 ( struct V_41 * V_52 ,
enum V_53 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_52 , struct V_1 , V_43 ) ;
V_2 -> V_59 = V_11 ;
F_15 ( & V_2 -> V_58 ) ;
}
static int F_21 ( struct V_60 * V_61 ,
const struct V_62 * V_63 )
{
struct V_4 * V_5 = V_61 -> V_10 . V_64 ;
struct V_1 * V_2 ;
int V_65 ;
if ( ! F_22 ( V_61 -> V_66 , V_67 ) ) {
F_3 ( & V_61 -> V_10 , L_7 ) ;
return - V_68 ;
}
if ( V_5 == NULL ) {
F_3 ( & V_61 -> V_10 , L_8 ) ;
return - V_69 ;
}
V_2 = F_23 ( & V_61 -> V_10 ,
sizeof( struct V_1 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_10 = & V_61 -> V_10 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_9 = V_5 -> V_9 ;
V_2 -> V_22 = V_5 -> V_22 ;
V_2 -> V_28 = V_5 -> V_28 ;
V_2 -> V_6 = F_24 ( V_61 , & V_72 ) ;
if ( F_25 ( V_2 -> V_6 ) ) {
V_65 = F_26 ( V_2 -> V_6 ) ;
F_3 ( & V_61 -> V_10 , L_9 ,
V_65 ) ;
return V_65 ;
}
F_27 ( & V_2 -> V_50 ) ;
F_28 ( V_61 , V_2 ) ;
V_65 = F_1 ( V_2 ) ;
if ( V_65 < 0 )
goto V_73;
F_29 ( & V_2 -> V_55 , F_17 ) ;
V_2 -> V_57 . V_74 = L_10 ;
V_2 -> V_57 . V_75 = 16 ;
V_2 -> V_57 . V_76 = F_18 ;
V_2 -> V_57 . V_77 = L_10 ;
V_65 = F_30 ( (struct V_36 * )
& V_61 -> V_10 , & V_2 -> V_57 ) ;
if ( V_65 < 0 ) {
F_3 ( V_2 -> V_10 , L_11 ) ;
goto V_73;
}
V_65 = F_31 ( V_2 -> V_57 . V_10 , & V_78 ) ;
if ( V_65 < 0 ) {
F_3 ( V_2 -> V_10 , L_12 ) ;
goto V_79;
}
F_29 ( & V_2 -> V_49 , F_11 ) ;
V_2 -> V_54 . V_74 = L_13 ;
V_2 -> V_54 . V_75 = 8 ;
V_2 -> V_54 . V_76 = F_14 ;
V_2 -> V_54 . V_77 = L_13 ;
V_65 = F_30 ( (struct V_36 * )
& V_61 -> V_10 , & V_2 -> V_54 ) ;
if ( V_65 < 0 ) {
F_3 ( V_2 -> V_10 , L_14 ) ;
goto V_80;
}
V_65 = F_31 ( V_2 -> V_54 . V_10 , & V_81 ) ;
if ( V_65 < 0 ) {
F_3 ( V_2 -> V_10 , L_15 ) ;
goto V_82;
}
F_29 ( & V_2 -> V_58 ,
F_19 ) ;
V_2 -> V_43 . V_74 = L_16 ;
V_2 -> V_43 . V_75 = 8 ;
V_2 -> V_43 . V_76 = F_20 ;
V_65 = F_30 ( (struct V_36 * )
& V_61 -> V_10 , & V_2 -> V_43 ) ;
if ( V_65 < 0 ) {
F_3 ( V_2 -> V_10 , L_17 ) ;
goto V_83;
}
F_6 ( & V_61 -> V_10 , L_18 ) ;
return 0 ;
V_83:
F_32 ( V_2 -> V_54 . V_10 , & V_81 ) ;
V_82:
F_33 ( & V_2 -> V_54 ) ;
V_80:
F_32 ( V_2 -> V_57 . V_10 , & V_78 ) ;
V_79:
F_33 ( & V_2 -> V_57 ) ;
V_73:
return V_65 ;
}
static int F_34 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_35 ( V_61 ) ;
F_33 ( & V_2 -> V_43 ) ;
F_36 ( & V_2 -> V_58 ) ;
F_32 ( V_2 -> V_54 . V_10 , & V_81 ) ;
F_33 ( & V_2 -> V_54 ) ;
F_36 ( & V_2 -> V_49 ) ;
F_32 ( V_2 -> V_57 . V_10 , & V_78 ) ;
F_33 ( & V_2 -> V_57 ) ;
F_36 ( & V_2 -> V_55 ) ;
F_37 ( V_2 -> V_6 , V_7 , 0 ) ;
return 0 ;
}
