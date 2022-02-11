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
static int F_11 ( struct V_41 * V_47 ,
enum V_48 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_47 , struct V_1 , V_49 ) ;
int V_3 ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_51 = V_11 ;
V_3 = F_4 ( V_2 , V_2 -> V_51 , V_18 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static T_2 F_14 ( struct V_36 * V_10 ,
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
static int F_15 ( struct V_41 * V_47 ,
enum V_48 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_47 , struct V_1 , V_52 ) ;
int V_3 ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_53 = V_11 ;
V_3 = F_4 ( V_2 , V_2 -> V_53 , V_25 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static int F_16 ( struct V_41 * V_47 ,
enum V_48 V_11 )
{
struct V_1 * V_2 =
F_9 ( V_47 , struct V_1 , V_43 ) ;
int V_3 ;
F_12 ( & V_2 -> V_50 ) ;
V_2 -> V_54 = V_11 ;
V_3 = F_4 ( V_2 , V_2 -> V_54 , V_31 ) ;
F_13 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static int F_17 ( struct V_55 * V_56 ,
const struct V_57 * V_58 )
{
struct V_4 * V_5 = F_18 ( & V_56 -> V_10 ) ;
struct V_1 * V_2 ;
int V_59 ;
if ( ! F_19 ( V_56 -> V_60 , V_61 ) ) {
F_3 ( & V_56 -> V_10 , L_7 ) ;
return - V_62 ;
}
if ( V_5 == NULL ) {
F_3 ( & V_56 -> V_10 , L_8 ) ;
return - V_63 ;
}
V_2 = F_20 ( & V_56 -> V_10 ,
sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_2 -> V_10 = & V_56 -> V_10 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_9 = V_5 -> V_9 ;
V_2 -> V_22 = V_5 -> V_22 ;
V_2 -> V_28 = V_5 -> V_28 ;
V_2 -> V_6 = F_21 ( V_56 , & V_66 ) ;
if ( F_22 ( V_2 -> V_6 ) ) {
V_59 = F_23 ( V_2 -> V_6 ) ;
F_3 ( & V_56 -> V_10 , L_9 ,
V_59 ) ;
return V_59 ;
}
F_24 ( & V_2 -> V_50 ) ;
F_25 ( V_56 , V_2 ) ;
V_59 = F_1 ( V_2 ) ;
if ( V_59 < 0 )
goto V_67;
V_2 -> V_52 . V_68 = L_10 ;
V_2 -> V_52 . V_69 = 16 ;
V_2 -> V_52 . V_70 = F_15 ;
V_2 -> V_52 . V_71 = L_10 ;
V_2 -> V_52 . V_72 = V_73 ,
V_59 = F_26 ( (struct V_36 * )
& V_56 -> V_10 , & V_2 -> V_52 ) ;
if ( V_59 < 0 ) {
F_3 ( V_2 -> V_10 , L_11 ) ;
goto V_67;
}
V_2 -> V_49 . V_68 = L_12 ;
V_2 -> V_49 . V_69 = 8 ;
V_2 -> V_49 . V_70 = F_11 ;
V_2 -> V_49 . V_71 = L_12 ;
V_2 -> V_49 . V_72 = V_74 ,
V_59 = F_26 ( (struct V_36 * )
& V_56 -> V_10 , & V_2 -> V_49 ) ;
if ( V_59 < 0 ) {
F_3 ( V_2 -> V_10 , L_13 ) ;
goto V_75;
}
V_2 -> V_43 . V_68 = L_14 ;
V_2 -> V_43 . V_69 = 8 ;
V_2 -> V_43 . V_70 =
F_16 ;
V_59 = F_26 ( (struct V_36 * )
& V_56 -> V_10 , & V_2 -> V_43 ) ;
if ( V_59 < 0 ) {
F_3 ( V_2 -> V_10 , L_15 ) ;
goto V_76;
}
F_6 ( & V_56 -> V_10 , L_16 ) ;
return 0 ;
V_76:
F_27 ( & V_2 -> V_49 ) ;
V_75:
F_27 ( & V_2 -> V_52 ) ;
V_67:
return V_59 ;
}
static int F_28 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
F_27 ( & V_2 -> V_43 ) ;
F_27 ( & V_2 -> V_49 ) ;
F_27 ( & V_2 -> V_52 ) ;
F_30 ( V_2 -> V_6 , V_7 , 0 ) ;
return 0 ;
}
