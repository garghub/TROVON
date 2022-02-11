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
static void F_4 ( struct V_1 * V_2 ,
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
return;
}
V_3 = F_2 ( V_2 -> V_10 , V_21 [ V_44 ] . V_24 ,
V_21 [ V_44 ] . V_26 ,
V_19 << V_21 [ V_44 ] . V_31 ) ;
if ( V_3 < 0 )
goto V_11;
return;
V_11:
F_3 ( V_2 -> V_15 , L_1 , V_16 ) ;
return;
}
static void F_7 ( struct V_45 * V_46 )
{
struct V_1 * V_2 =
F_8 ( V_46 , struct V_1 , V_47 ) ;
F_9 ( & V_2 -> V_48 ) ;
F_4 ( V_2 , V_2 -> V_49 , V_29 ) ;
F_10 ( & V_2 -> V_48 ) ;
}
static void F_11 ( struct V_50 * V_51 ,
enum V_52 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
V_2 -> V_49 = V_17 ;
F_12 ( & V_2 -> V_47 ) ;
}
static void F_13 ( struct V_45 * V_46 )
{
struct V_1 * V_2 =
F_8 ( V_46 , struct V_1 , V_54 ) ;
F_9 ( & V_2 -> V_48 ) ;
F_4 ( V_2 , V_2 -> V_55 , V_35 ) ;
F_10 ( & V_2 -> V_48 ) ;
}
static void F_14 ( struct V_50 * V_51 ,
enum V_52 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_56 ) ;
V_2 -> V_55 = V_17 ;
F_12 ( & V_2 -> V_54 ) ;
}
static void F_15 ( struct V_45 * V_46 )
{
struct V_1 * V_2 =
F_8 ( V_46 , struct V_1 , V_57 ) ;
F_9 ( & V_2 -> V_48 ) ;
F_4 ( V_2 , V_2 -> V_58 , V_40 ) ;
F_10 ( & V_2 -> V_48 ) ;
}
static void F_16 ( struct V_50 * V_51 ,
enum V_52 V_17 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_59 ) ;
V_2 -> V_58 = V_17 ;
F_12 ( & V_2 -> V_57 ) ;
}
static T_2 F_17 ( struct V_60 * V_15 ,
struct V_61 * V_62 ,
const char * V_63 , T_3 V_64 )
{
T_2 V_3 ;
struct V_50 * V_65 = F_18 ( V_15 ) ;
struct V_1 * V_2 =
F_8 ( V_65 , struct V_1 , V_59 ) ;
unsigned int V_66 ;
V_3 = F_19 ( V_63 , 10 , & V_66 ) ;
if ( V_3 )
goto V_11;
if ( V_66 > V_67 - 1 )
V_66 = V_67 - 1 ;
V_3 = F_20 ( V_2 -> V_10 , 0x04 ,
V_68 [ V_66 ] . V_69 ) ;
if ( V_3 < 0 )
goto V_11;
V_3 = F_20 ( V_2 -> V_10 , 0x05 ,
V_68 [ V_66 ] . V_70 ) ;
if ( V_3 < 0 )
goto V_11;
return V_64 ;
V_11:
F_3 ( V_2 -> V_15 , L_1 , V_16 ) ;
return V_3 ;
}
static int F_21 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_5 * V_6 = V_72 -> V_15 . V_75 ;
struct V_1 * V_2 ;
int V_76 ;
if ( ! F_22 ( V_72 -> V_77 , V_78 ) ) {
F_3 ( & V_72 -> V_15 , L_5 ) ;
return - V_79 ;
}
if ( V_6 == NULL ) {
F_3 ( & V_72 -> V_15 , L_6 ) ;
return - V_14 ;
}
V_2 = F_23 ( & V_72 -> V_15 ,
sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_15 = & V_72 -> V_15 ;
V_2 -> type = V_74 -> V_82 ;
switch ( V_74 -> V_82 ) {
case V_7 :
V_2 -> V_22 = V_83 ;
break;
case V_13 :
V_2 -> V_22 = V_84 ;
break;
default:
return - V_85 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_10 = F_24 ( V_72 , & V_86 ) ;
if ( F_25 ( V_2 -> V_10 ) ) {
V_76 = F_26 ( V_2 -> V_10 ) ;
F_3 ( & V_72 -> V_15 ,
L_7 , V_76 ) ;
return V_76 ;
}
F_27 ( & V_2 -> V_48 ) ;
F_28 ( V_72 , V_2 ) ;
V_76 = F_1 ( V_2 ) ;
if ( V_76 < 0 )
goto V_87;
F_29 ( & V_2 -> V_54 , F_13 ) ;
V_2 -> V_56 . V_88 = L_8 ;
V_2 -> V_56 . V_89 = 16 ;
V_2 -> V_56 . V_90 = F_14 ;
V_2 -> V_56 . V_91 = L_8 ;
V_76 = F_30 ( (struct V_60 * )
& V_72 -> V_15 , & V_2 -> V_56 ) ;
if ( V_76 < 0 )
goto V_87;
F_29 ( & V_2 -> V_47 , F_7 ) ;
V_2 -> V_53 . V_88 = L_9 ;
V_2 -> V_53 . V_89 = 8 ;
V_2 -> V_53 . V_90 = F_11 ;
V_2 -> V_53 . V_91 = L_9 ;
V_76 = F_30 ( (struct V_60 * )
& V_72 -> V_15 , & V_2 -> V_53 ) ;
if ( V_76 < 0 )
goto V_92;
F_29 ( & V_2 -> V_57 ,
F_15 ) ;
V_2 -> V_59 . V_88 = L_10 ;
if ( V_74 -> V_82 == V_7 )
V_2 -> V_59 . V_89 = 4 ;
else
V_2 -> V_59 . V_89 = 8 ;
V_2 -> V_59 . V_90 = F_16 ;
V_76 = F_30 ( (struct V_60 * )
& V_72 -> V_15 , & V_2 -> V_59 ) ;
if ( V_76 < 0 )
goto V_93;
if ( V_74 -> V_82 == V_13 ) {
V_76 =
F_31 ( V_2 -> V_59 . V_15 ,
& V_94 ) ;
if ( V_76 < 0 )
goto V_95;
}
F_6 ( & V_72 -> V_15 , L_11 ,
V_27 [ V_74 -> V_82 ] ) ;
return 0 ;
V_95:
F_32 ( & V_2 -> V_59 ) ;
V_93:
F_32 ( & V_2 -> V_53 ) ;
V_92:
F_32 ( & V_2 -> V_56 ) ;
V_87:
return V_76 ;
}
static int F_33 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_34 ( V_72 ) ;
struct V_20 * V_21 = V_2 -> V_22 ;
F_20 ( V_2 -> V_10 , V_21 [ V_44 ] . V_24 , 0 ) ;
if ( V_2 -> type == V_13 )
F_35 ( V_2 -> V_59 . V_15 , & V_94 ) ;
F_32 ( & V_2 -> V_59 ) ;
F_36 ( & V_2 -> V_57 ) ;
F_32 ( & V_2 -> V_53 ) ;
F_36 ( & V_2 -> V_47 ) ;
F_32 ( & V_2 -> V_56 ) ;
F_36 ( & V_2 -> V_54 ) ;
F_6 ( & V_72 -> V_15 , L_12 , V_27 [ V_2 -> type ] ) ;
return 0 ;
}
