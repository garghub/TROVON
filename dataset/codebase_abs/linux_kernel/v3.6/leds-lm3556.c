static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_2 -> V_7 , V_8 , & V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_1 ) ;
goto V_10;
}
V_3 &= ( ~ V_11 ) ;
V_3 |= ( ( V_6 -> V_12 & 0x01 )
<< V_13 ) ;
V_3 |= ( ( V_6 -> V_14 & 0x01 ) << V_15 ) ;
V_3 |= ( ( V_6 -> V_16 & 0x01 )
<< V_17 ) ;
V_3 |= ( ( V_6 -> V_18 & 0x01 ) << V_19 ) ;
V_3 |= ( ( V_6 -> V_20 & 0x01 ) << V_21 ) ;
V_4 = F_4 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_2 ) ;
goto V_10;
}
V_4 = F_2 ( V_2 -> V_7 , V_22 , & V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_3 ) ;
goto V_10;
}
V_3 &= ( ~ V_23 ) ;
V_3 |= ( ( V_6 -> V_24 & 0x01 ) << V_25 ) ;
V_3 |= ( ( V_6 -> V_26 & 0x01 ) << V_27 ) ;
V_3 |= ( ( V_6 -> V_28 & 0x01 ) << V_29 ) ;
V_4 = F_4 ( V_2 -> V_7 , V_22 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_4 ) ;
goto V_10;
}
V_10:
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_2 V_30 , enum V_31 V_32 )
{
int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_2 -> V_7 , V_33 , & V_2 -> V_34 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_5 ) ;
goto V_10;
}
if ( V_2 -> V_34 )
F_6 ( V_2 -> V_9 , L_6 , V_2 -> V_34 ) ;
if ( ! V_30 )
V_32 = V_35 ;
switch ( V_32 ) {
case V_36 :
V_4 = F_7 ( V_2 -> V_7 , V_37 ,
V_38 << V_39 ,
( V_30 - 1 ) << V_39 ) ;
if ( V_6 -> V_24 )
V_32 |= ( V_40 << V_25 ) ;
break;
case V_41 :
V_4 = F_7 ( V_2 -> V_7 , V_37 ,
V_42 << V_43 ,
( V_30 - 1 ) << V_43 ) ;
break;
case V_44 :
V_4 = F_7 ( V_2 -> V_7 , V_37 ,
V_38 << V_39 ,
( V_30 - 1 ) << V_39 ) ;
break;
case V_35 :
if ( V_6 -> V_24 )
V_32 |= ( V_40 << V_25 ) ;
break;
default:
return V_4 ;
}
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_7 ) ;
goto V_10;
}
V_4 = F_7 ( V_2 -> V_7 , V_22 ,
V_45 << V_46 ,
V_32 << V_46 ) ;
V_10:
return V_4 ;
}
static void F_8 ( struct V_47 * V_48 ,
enum V_49 V_30 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_50 ) ;
F_10 ( & V_2 -> V_51 ) ;
F_5 ( V_2 , V_30 , V_36 ) ;
F_11 ( & V_2 -> V_51 ) ;
}
static void F_12 ( struct V_47 * V_48 ,
enum V_49 V_30 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_52 ) ;
F_10 ( & V_2 -> V_51 ) ;
F_5 ( V_2 , V_30 , V_41 ) ;
F_11 ( & V_2 -> V_51 ) ;
}
static void F_13 ( struct V_47 * V_48 ,
enum V_49 V_30 )
{
struct V_1 * V_2 =
F_9 ( V_48 , struct V_1 , V_53 ) ;
F_10 ( & V_2 -> V_51 ) ;
F_5 ( V_2 , V_30 , V_44 ) ;
F_11 ( & V_2 -> V_51 ) ;
}
static T_3 F_14 ( struct V_54 * V_9 ,
struct V_55 * V_56 ,
const char * V_57 , T_4 V_58 )
{
T_3 V_4 ;
struct V_47 * V_59 = F_15 ( V_9 ) ;
struct V_1 * V_2 =
F_9 ( V_59 , struct V_1 , V_53 ) ;
unsigned int V_60 ;
V_4 = F_16 ( V_57 , 10 , & V_60 ) ;
if ( V_4 )
goto V_10;
if ( V_60 > V_61 - 1 )
V_60 = V_61 - 1 ;
V_4 = F_4 ( V_2 -> V_7 , V_62 ,
V_63 [ V_60 ] . V_64 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_4 ) ;
goto V_10;
}
V_4 = F_4 ( V_2 -> V_7 , V_65 ,
V_63 [ V_60 ] . V_66 ) ;
if ( V_4 < 0 ) {
F_3 ( V_2 -> V_9 , L_4 ) ;
goto V_10;
}
return V_58 ;
V_10:
F_3 ( V_2 -> V_9 , L_8 ) ;
return V_58 ;
}
static int T_1 F_17 ( struct V_67 * V_68 ,
const struct V_69 * V_70 )
{
struct V_5 * V_6 = V_68 -> V_9 . V_71 ;
struct V_1 * V_2 ;
int V_72 ;
if ( ! F_18 ( V_68 -> V_73 , V_74 ) ) {
F_3 ( & V_68 -> V_9 , L_9 ) ;
return - V_75 ;
}
if ( V_6 == NULL ) {
F_3 ( & V_68 -> V_9 , L_10 ) ;
return - V_76 ;
}
V_2 =
F_19 ( & V_68 -> V_9 , sizeof( struct V_1 ) ,
V_77 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_9 = & V_68 -> V_9 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_7 = F_20 ( V_68 , & V_79 ) ;
if ( F_21 ( V_2 -> V_7 ) ) {
V_72 = F_22 ( V_2 -> V_7 ) ;
F_3 ( & V_68 -> V_9 , L_11 ,
V_72 ) ;
return V_72 ;
}
F_23 ( & V_2 -> V_51 ) ;
F_24 ( V_68 , V_2 ) ;
V_72 = F_1 ( V_2 ) ;
if ( V_72 < 0 )
goto V_80;
V_2 -> V_52 . V_81 = L_12 ;
V_2 -> V_52 . V_82 = 16 ;
V_2 -> V_52 . V_83 = F_12 ;
V_72 = F_25 ( (struct V_54 * )
& V_68 -> V_9 , & V_2 -> V_52 ) ;
if ( V_72 < 0 )
goto V_80;
V_2 -> V_50 . V_81 = L_13 ;
V_2 -> V_50 . V_82 = 8 ;
V_2 -> V_50 . V_83 = F_8 ;
V_72 = F_25 ( (struct V_54 * )
& V_68 -> V_9 , & V_2 -> V_50 ) ;
if ( V_72 < 0 )
goto V_84;
V_2 -> V_53 . V_81 = L_14 ;
V_2 -> V_53 . V_82 = 8 ;
V_2 -> V_53 . V_83 = F_13 ;
V_72 = F_25 ( (struct V_54 * )
& V_68 -> V_9 , & V_2 -> V_53 ) ;
if ( V_72 < 0 )
goto V_85;
V_72 = F_26 ( V_2 -> V_53 . V_9 , & V_86 ) ;
if ( V_72 < 0 )
goto V_87;
F_6 ( & V_68 -> V_9 , L_15 ) ;
return 0 ;
V_87:
F_27 ( & V_2 -> V_53 ) ;
V_85:
F_27 ( & V_2 -> V_50 ) ;
V_84:
F_27 ( & V_2 -> V_52 ) ;
V_80:
return V_72 ;
}
static int T_5 F_28 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_29 ( V_68 ) ;
F_30 ( V_2 -> V_53 . V_9 , & V_86 ) ;
F_27 ( & V_2 -> V_53 ) ;
F_27 ( & V_2 -> V_50 ) ;
F_27 ( & V_2 -> V_52 ) ;
F_4 ( V_2 -> V_7 , V_22 , 0 ) ;
return 0 ;
}
