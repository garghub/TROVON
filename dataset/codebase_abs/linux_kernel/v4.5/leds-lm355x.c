static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
switch ( V_2 -> type ) {
case V_7 :
V_4 = V_6 -> V_8 | V_6 -> V_9 ;
V_3 = F_2 ( V_2 -> V_10 , 0xE0 , 0x28 , V_4 ) ;
if ( V_3 < 0 )
goto V_11;
V_4 = V_6 -> V_12 ;
V_3 = F_2 ( V_2 -> V_10 , 0xA0 , 0x04 , V_4 ) ;
if ( V_3 < 0 )
goto V_11;
break;
case V_13 :
V_4 = V_6 -> V_8 | V_6 -> V_9 | V_6 -> V_12 ;
V_3 = F_2 ( V_2 -> V_10 , 0x0A , 0xC4 , V_4 ) ;
if ( V_3 < 0 )
goto V_11;
break;
default:
return - V_14 ;
}
return V_3 ;
V_11:
F_3 ( V_2 -> V_15 , L_1 , V_16 ) ;
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_17 , enum V_18 V_19 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_20 * V_21 = V_2 -> V_22 ;
V_3 = F_5 ( V_2 -> V_10 , V_21 [ V_23 ] . V_24 , & V_2 -> V_25 ) ;
if ( V_3 < 0 )
goto V_11;
if ( V_2 -> V_25 & V_21 [ V_23 ] . V_26 )
F_6 ( V_2 -> V_15 , L_2 ,
V_27 [ V_2 -> type ] ,
V_2 -> V_25 & V_21 [ V_23 ] . V_26 ) ;
if ( ! V_17 )
V_19 = V_28 ;
switch ( V_19 ) {
case V_29 :
V_3 =
F_2 ( V_2 -> V_10 , V_21 [ V_30 ] . V_24 ,
V_21 [ V_30 ] . V_26 ,
( V_17 - 1 )
<< V_21 [ V_30 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
if ( V_6 -> V_32 != V_33 ) {
V_3 =
F_2 ( V_2 -> V_10 ,
V_21 [ V_34 ] . V_24 ,
V_21 [ V_34 ] . V_26 ,
0x01 <<
V_21 [ V_34 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
V_19 = V_28 ;
F_6 ( V_2 -> V_15 ,
L_3 ) ;
}
break;
case V_35 :
V_3 =
F_2 ( V_2 -> V_10 , V_21 [ V_36 ] . V_24 ,
V_21 [ V_36 ] . V_26 ,
( V_17 - 1 )
<< V_21 [ V_36 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
if ( V_6 -> V_37 != V_38 ) {
if ( V_2 -> type == V_7 )
V_4 = 0x00 ;
else
V_4 = 0x01 ;
V_3 =
F_2 ( V_2 -> V_10 ,
V_21 [ V_39 ] . V_24 ,
V_21 [ V_39 ] . V_26 ,
V_4 <<
V_21 [ V_39 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
V_19 = V_28 ;
F_6 ( V_2 -> V_15 ,
L_4 ) ;
}
break;
case V_40 :
V_3 =
F_2 ( V_2 -> V_10 , V_21 [ V_41 ] . V_24 ,
V_21 [ V_41 ] . V_26 ,
( V_17 - 1 )
<< V_21 [ V_41 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
if ( V_6 -> V_8 != V_42 ) {
V_3 =
F_2 ( V_2 -> V_10 ,
V_21 [ V_43 ] . V_24 ,
V_21 [ V_43 ] . V_26 ,
0x01 <<
V_21 [ V_43 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
V_19 = V_28 ;
}
break;
case V_28 :
break;
default:
return - V_44 ;
}
V_3 = F_2 ( V_2 -> V_10 , V_21 [ V_45 ] . V_24 ,
V_21 [ V_45 ] . V_26 ,
V_19 << V_21 [ V_45 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
return V_3 ;
V_11:
F_3 ( V_2 -> V_15 , L_1 , V_16 ) ;
return V_3 ;
}
static int F_7 ( struct V_46 * V_47 ,
enum V_48 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_47 , struct V_1 , V_49 ) ;
int V_3 ;
F_9 ( & V_2 -> V_50 ) ;
V_3 = F_4 ( V_2 , V_17 , V_29 ) ;
F_10 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static int F_11 ( struct V_46 * V_47 ,
enum V_48 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_47 , struct V_1 , V_51 ) ;
int V_3 ;
F_9 ( & V_2 -> V_50 ) ;
V_3 = F_4 ( V_2 , V_17 , V_35 ) ;
F_10 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static int F_12 ( struct V_46 * V_47 ,
enum V_48 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_47 , struct V_1 , V_52 ) ;
int V_3 ;
F_9 ( & V_2 -> V_50 ) ;
V_3 = F_4 ( V_2 , V_17 , V_40 ) ;
F_10 ( & V_2 -> V_50 ) ;
return V_3 ;
}
static T_2 F_13 ( struct V_53 * V_15 ,
struct V_54 * V_55 ,
const char * V_56 , T_3 V_57 )
{
T_2 V_3 ;
struct V_46 * V_58 = F_14 ( V_15 ) ;
struct V_1 * V_2 =
F_8 ( V_58 , struct V_1 , V_52 ) ;
unsigned int V_59 ;
V_3 = F_15 ( V_56 , 10 , & V_59 ) ;
if ( V_3 )
goto V_11;
if ( V_59 > V_60 - 1 )
V_59 = V_60 - 1 ;
V_3 = F_16 ( V_2 -> V_10 , 0x04 ,
V_61 [ V_59 ] . V_62 ) ;
if ( V_3 < 0 )
goto V_11;
V_3 = F_16 ( V_2 -> V_10 , 0x05 ,
V_61 [ V_59 ] . V_63 ) ;
if ( V_3 < 0 )
goto V_11;
return V_57 ;
V_11:
F_3 ( V_2 -> V_15 , L_1 , V_16 ) ;
return V_3 ;
}
static int F_17 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_5 * V_6 = F_18 ( & V_65 -> V_15 ) ;
struct V_1 * V_2 ;
int V_68 ;
if ( ! F_19 ( V_65 -> V_69 , V_70 ) ) {
F_3 ( & V_65 -> V_15 , L_5 ) ;
return - V_71 ;
}
if ( V_6 == NULL ) {
F_3 ( & V_65 -> V_15 , L_6 ) ;
return - V_14 ;
}
V_2 = F_20 ( & V_65 -> V_15 ,
sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_15 = & V_65 -> V_15 ;
V_2 -> type = V_67 -> V_74 ;
switch ( V_67 -> V_74 ) {
case V_7 :
V_2 -> V_22 = V_75 ;
break;
case V_13 :
V_2 -> V_22 = V_76 ;
break;
default:
return - V_77 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_10 = F_21 ( V_65 , & V_78 ) ;
if ( F_22 ( V_2 -> V_10 ) ) {
V_68 = F_23 ( V_2 -> V_10 ) ;
F_3 ( & V_65 -> V_15 ,
L_7 , V_68 ) ;
return V_68 ;
}
F_24 ( & V_2 -> V_50 ) ;
F_25 ( V_65 , V_2 ) ;
V_68 = F_1 ( V_2 ) ;
if ( V_68 < 0 )
goto V_79;
V_2 -> V_51 . V_80 = L_8 ;
V_2 -> V_51 . V_81 = 16 ;
V_2 -> V_51 . V_82 = F_11 ;
V_2 -> V_51 . V_83 = L_8 ;
V_68 = F_26 ( (struct V_53 * )
& V_65 -> V_15 , & V_2 -> V_51 ) ;
if ( V_68 < 0 )
goto V_79;
V_2 -> V_49 . V_80 = L_9 ;
V_2 -> V_49 . V_81 = 8 ;
V_2 -> V_49 . V_82 = F_7 ;
V_2 -> V_49 . V_83 = L_9 ;
V_68 = F_26 ( (struct V_53 * )
& V_65 -> V_15 , & V_2 -> V_49 ) ;
if ( V_68 < 0 )
goto V_84;
V_2 -> V_52 . V_80 = L_10 ;
if ( V_67 -> V_74 == V_7 )
V_2 -> V_52 . V_81 = 4 ;
else
V_2 -> V_52 . V_81 = 8 ;
V_2 -> V_52 . V_82 =
F_12 ;
if ( V_67 -> V_74 == V_13 )
V_2 -> V_52 . V_85 = V_86 ;
V_68 = F_26 ( (struct V_53 * )
& V_65 -> V_15 , & V_2 -> V_52 ) ;
if ( V_68 < 0 )
goto V_87;
F_6 ( & V_65 -> V_15 , L_11 ,
V_27 [ V_67 -> V_74 ] ) ;
return 0 ;
V_87:
F_27 ( & V_2 -> V_49 ) ;
V_84:
F_27 ( & V_2 -> V_51 ) ;
V_79:
return V_68 ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_29 ( V_65 ) ;
struct V_20 * V_21 = V_2 -> V_22 ;
F_16 ( V_2 -> V_10 , V_21 [ V_45 ] . V_24 , 0 ) ;
F_27 ( & V_2 -> V_52 ) ;
F_27 ( & V_2 -> V_49 ) ;
F_27 ( & V_2 -> V_51 ) ;
F_6 ( & V_65 -> V_15 , L_12 , V_27 [ V_2 -> type ] ) ;
return 0 ;
}
