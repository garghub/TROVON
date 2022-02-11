static int F_1 ( struct V_1 * V_2 , T_1 type )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
void T_2 * V_13 = V_8 -> V_14 ;
V_8 -> V_15 &= ~ ( 1 << ( V_3 & 31 ) ) ;
switch ( type ) {
case V_16 :
V_12 = V_17 ;
break;
case V_18 :
V_12 = V_19 ;
break;
case V_20 :
V_11 = F_4 ( V_3 ) ;
if ( V_11 ) {
V_12 = V_21 ;
F_5 ( L_1 , V_3 ) ;
} else {
V_12 = V_22 ;
F_5 ( L_2 , V_3 ) ;
}
V_8 -> V_15 |= 1 << ( V_3 & 31 ) ;
break;
case V_23 :
V_12 = V_21 ;
break;
case V_24 :
V_12 = V_22 ;
break;
default:
return - V_25 ;
}
V_13 += V_26 + ( ( V_3 & 0x10 ) >> 2 ) ;
V_10 = V_3 & 0xf ;
V_11 = F_6 ( V_13 ) & ~ ( 0x3 << ( V_10 << 1 ) ) ;
F_7 ( V_11 | ( V_12 << ( V_10 << 1 ) ) , V_13 ) ;
F_7 ( 1 << ( V_3 & 0x1f ) , V_8 -> V_14 + V_27 ) ;
return 0 ;
}
static void F_8 ( struct V_7 * V_8 , T_1 V_3 )
{
void T_2 * V_13 = V_8 -> V_14 ;
T_1 V_10 , V_11 ;
int V_12 ;
V_13 += V_26 + ( ( V_3 & 0x10 ) >> 2 ) ;
V_10 = V_3 & 0xf ;
V_11 = F_6 ( V_13 ) ;
V_12 = ( V_11 >> ( V_10 << 1 ) ) & 3 ;
V_11 &= ~ ( 0x3 << ( V_10 << 1 ) ) ;
if ( V_12 == V_22 ) {
V_12 = V_21 ;
F_5 ( L_3 , V_3 ) ;
} else if ( V_12 == V_21 ) {
V_12 = V_22 ;
F_5 ( L_4 , V_3 ) ;
} else {
F_9 ( L_5 ,
V_3 , V_12 ) ;
return;
}
F_7 ( V_11 | ( V_12 << ( V_10 << 1 ) ) , V_13 ) ;
}
static void F_10 ( struct V_7 * V_8 , T_1 V_28 )
{
T_1 V_29 = V_8 -> V_30 ;
while ( V_28 != 0 ) {
int V_31 = F_11 ( V_28 ) - 1 ;
if ( V_8 -> V_15 & ( 1 << V_31 ) )
F_8 ( V_8 , V_31 ) ;
F_12 ( V_29 + V_31 ) ;
V_28 &= ~ ( 1 << V_31 ) ;
}
}
static void F_13 ( T_1 V_4 , struct V_32 * V_33 )
{
T_1 V_28 ;
struct V_7 * V_8 = F_14 ( V_4 ) ;
struct V_34 * V_35 = F_15 ( V_4 ) ;
F_16 ( V_35 , V_33 ) ;
V_28 = F_6 ( V_8 -> V_14 + V_27 ) & F_6 ( V_8 -> V_14 + V_36 ) ;
F_10 ( V_8 , V_28 ) ;
F_17 ( V_35 , V_33 ) ;
}
static void F_18 ( T_1 V_4 , struct V_32 * V_33 )
{
T_1 V_37 , V_28 ;
struct V_7 * V_8 ;
F_19 (port, &mxc_gpio_ports, node) {
V_37 = F_6 ( V_8 -> V_14 + V_36 ) ;
if ( ! V_37 )
continue;
V_28 = F_6 ( V_8 -> V_14 + V_27 ) & V_37 ;
if ( V_28 )
F_10 ( V_8 , V_28 ) ;
}
}
static int F_20 ( struct V_1 * V_2 , T_1 V_38 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
T_1 V_39 = V_3 & 0x1F ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_38 ) {
if ( V_8 -> V_40 && ( V_39 >= 16 ) )
F_21 ( V_8 -> V_40 ) ;
else
F_21 ( V_8 -> V_4 ) ;
} else {
if ( V_8 -> V_40 && ( V_39 >= 16 ) )
F_22 ( V_8 -> V_40 ) ;
else
F_22 ( V_8 -> V_4 ) ;
}
return 0 ;
}
static void T_3 F_23 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_41 * V_42 ;
V_6 = F_24 ( L_6 , 1 , V_8 -> V_30 ,
V_8 -> V_14 , V_43 ) ;
V_6 -> V_9 = V_8 ;
V_42 = V_6 -> V_44 ;
V_42 -> V_35 . V_45 = V_46 ;
V_42 -> V_35 . V_47 = V_48 ;
V_42 -> V_35 . V_49 = V_50 ;
V_42 -> V_35 . V_51 = F_1 ;
V_42 -> V_35 . V_52 = F_20 ;
V_42 -> V_53 . V_54 = V_27 ;
V_42 -> V_53 . V_55 = V_36 ;
F_25 ( V_6 , F_26 ( 32 ) , V_56 ,
V_57 , 0 ) ;
}
static void T_4 F_27 ( struct V_58 * V_59 )
{
const struct V_60 * V_61 =
F_28 ( V_62 , & V_59 -> V_63 ) ;
enum V_64 V_65 ;
if ( V_61 )
V_59 -> V_66 = V_61 -> V_67 ;
V_65 = V_59 -> V_66 -> V_68 ;
if ( V_64 ) {
F_29 ( V_64 != V_65 ) ;
return;
}
if ( V_65 == V_69 )
V_70 = & V_71 ;
else
V_70 = & V_72 ;
V_64 = V_65 ;
}
static int F_30 ( struct V_73 * V_6 , unsigned V_74 )
{
struct V_75 * V_76 = F_31 ( V_6 ) ;
struct V_7 * V_8 =
F_32 ( V_76 , struct V_7 , V_76 ) ;
return V_8 -> V_30 + V_74 ;
}
static int T_4 F_33 ( struct V_58 * V_59 )
{
struct V_77 * V_78 = V_59 -> V_63 . V_79 ;
struct V_7 * V_8 ;
struct V_80 * V_81 ;
int V_82 ;
F_27 ( V_59 ) ;
V_8 = F_34 ( sizeof( struct V_7 ) , V_83 ) ;
if ( ! V_8 )
return - V_84 ;
V_81 = F_35 ( V_59 , V_85 , 0 ) ;
if ( ! V_81 ) {
V_82 = - V_86 ;
goto V_87;
}
if ( ! F_36 ( V_81 -> V_88 , F_37 ( V_81 ) ,
V_59 -> V_89 ) ) {
V_82 = - V_90 ;
goto V_87;
}
V_8 -> V_14 = F_38 ( V_81 -> V_88 , F_37 ( V_81 ) ) ;
if ( ! V_8 -> V_14 ) {
V_82 = - V_84 ;
goto V_91;
}
V_8 -> V_40 = F_39 ( V_59 , 1 ) ;
V_8 -> V_4 = F_39 ( V_59 , 0 ) ;
if ( V_8 -> V_4 < 0 ) {
V_82 = - V_25 ;
goto V_92;
}
F_7 ( 0 , V_8 -> V_14 + V_36 ) ;
F_7 ( ~ 0 , V_8 -> V_14 + V_27 ) ;
if ( V_64 == V_93 ) {
if ( V_59 -> V_94 == 0 )
F_40 ( V_8 -> V_4 ,
F_18 ) ;
} else {
F_40 ( V_8 -> V_4 , F_13 ) ;
F_41 ( V_8 -> V_4 , V_8 ) ;
if ( V_8 -> V_40 > 0 ) {
F_40 ( V_8 -> V_40 ,
F_13 ) ;
F_41 ( V_8 -> V_40 , V_8 ) ;
}
}
V_82 = F_42 ( & V_8 -> V_76 , & V_59 -> V_63 , 4 ,
V_8 -> V_14 + V_95 ,
V_8 -> V_14 + V_96 , NULL ,
V_8 -> V_14 + V_97 , NULL , false ) ;
if ( V_82 )
goto V_92;
V_8 -> V_76 . V_6 . V_98 = F_30 ;
V_8 -> V_76 . V_6 . V_14 = V_59 -> V_94 * 32 ;
V_8 -> V_76 . V_99 = V_8 -> V_76 . V_100 ( V_8 -> V_76 . V_101 ) ;
V_8 -> V_76 . V_67 = V_8 -> V_76 . V_100 ( V_8 -> V_76 . V_102 ) ;
V_82 = F_43 ( & V_8 -> V_76 . V_6 ) ;
if ( V_82 )
goto V_103;
V_8 -> V_30 = V_104 + ( V_78 ? V_8 -> V_76 . V_6 . V_14 :
V_59 -> V_94 * 32 ) ;
F_23 ( V_8 ) ;
F_44 ( & V_8 -> V_105 , & V_106 ) ;
return 0 ;
V_103:
F_45 ( & V_8 -> V_76 ) ;
V_92:
F_46 ( V_8 -> V_14 ) ;
V_91:
F_47 ( V_81 -> V_88 , F_37 ( V_81 ) ) ;
V_87:
F_48 ( V_8 ) ;
F_49 ( & V_59 -> V_63 , L_7 , V_107 , V_82 ) ;
return V_82 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_108 ) ;
}
