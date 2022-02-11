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
V_28 = F_6 ( V_8 -> V_14 + V_27 ) & F_6 ( V_8 -> V_14 + V_34 ) ;
F_10 ( V_8 , V_28 ) ;
}
static void F_15 ( T_1 V_4 , struct V_32 * V_33 )
{
T_1 V_35 , V_28 ;
struct V_7 * V_8 ;
F_16 (port, &mxc_gpio_ports, node) {
V_35 = F_6 ( V_8 -> V_14 + V_34 ) ;
if ( ! V_35 )
continue;
V_28 = F_6 ( V_8 -> V_14 + V_27 ) & V_35 ;
if ( V_28 )
F_10 ( V_8 , V_28 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 ) ;
T_1 V_37 = V_3 & 0x1F ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_36 ) {
if ( V_8 -> V_38 && ( V_37 >= 16 ) )
F_18 ( V_8 -> V_38 ) ;
else
F_18 ( V_8 -> V_4 ) ;
} else {
if ( V_8 -> V_38 && ( V_37 >= 16 ) )
F_19 ( V_8 -> V_38 ) ;
else
F_19 ( V_8 -> V_4 ) ;
}
return 0 ;
}
static void T_3 F_20 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_39 * V_40 ;
V_6 = F_21 ( L_6 , 1 , V_8 -> V_30 ,
V_8 -> V_14 , V_41 ) ;
V_6 -> V_9 = V_8 ;
V_40 = V_6 -> V_42 ;
V_40 -> V_43 . V_44 = V_45 ;
V_40 -> V_43 . V_46 = V_47 ;
V_40 -> V_43 . V_48 = V_49 ;
V_40 -> V_43 . V_50 = F_1 ;
V_40 -> V_43 . V_51 = F_17 ;
V_40 -> V_52 . V_53 = V_27 ;
V_40 -> V_52 . V_54 = V_34 ;
F_22 ( V_6 , F_23 ( 32 ) , V_55 ,
V_56 , 0 ) ;
}
static void T_4 F_24 ( struct V_57 * V_58 )
{
const struct V_59 * V_60 =
F_25 ( V_61 , & V_58 -> V_62 ) ;
enum V_63 V_64 ;
if ( V_60 )
V_58 -> V_65 = V_60 -> V_66 ;
V_64 = V_58 -> V_65 -> V_67 ;
if ( V_63 ) {
F_26 ( V_63 != V_64 ) ;
return;
}
if ( V_64 == V_68 )
V_69 = & V_70 ;
else
V_69 = & V_71 ;
V_63 = V_64 ;
}
static int T_4 F_27 ( struct V_57 * V_58 )
{
struct V_72 * V_73 = V_58 -> V_62 . V_74 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
int V_77 ;
F_24 ( V_58 ) ;
V_8 = F_28 ( sizeof( struct V_7 ) , V_78 ) ;
if ( ! V_8 )
return - V_79 ;
V_76 = F_29 ( V_58 , V_80 , 0 ) ;
if ( ! V_76 ) {
V_77 = - V_81 ;
goto V_82;
}
if ( ! F_30 ( V_76 -> V_83 , F_31 ( V_76 ) ,
V_58 -> V_84 ) ) {
V_77 = - V_85 ;
goto V_82;
}
V_8 -> V_14 = F_32 ( V_76 -> V_83 , F_31 ( V_76 ) ) ;
if ( ! V_8 -> V_14 ) {
V_77 = - V_79 ;
goto V_86;
}
V_8 -> V_38 = F_33 ( V_58 , 1 ) ;
V_8 -> V_4 = F_33 ( V_58 , 0 ) ;
if ( V_8 -> V_4 < 0 ) {
V_77 = - V_25 ;
goto V_87;
}
F_7 ( 0 , V_8 -> V_14 + V_34 ) ;
F_7 ( ~ 0 , V_8 -> V_14 + V_27 ) ;
if ( V_63 == V_88 ) {
if ( V_58 -> V_89 == 0 )
F_34 ( V_8 -> V_4 ,
F_15 ) ;
} else {
F_34 ( V_8 -> V_4 , F_13 ) ;
F_35 ( V_8 -> V_4 , V_8 ) ;
if ( V_8 -> V_38 > 0 ) {
F_34 ( V_8 -> V_38 ,
F_13 ) ;
F_35 ( V_8 -> V_38 , V_8 ) ;
}
}
V_77 = F_36 ( & V_8 -> V_90 , & V_58 -> V_62 , 4 ,
V_8 -> V_14 + V_91 ,
V_8 -> V_14 + V_92 , NULL ,
V_8 -> V_14 + V_93 , NULL , false ) ;
if ( V_77 )
goto V_87;
V_8 -> V_90 . V_6 . V_14 = V_58 -> V_89 * 32 ;
V_8 -> V_90 . V_94 = V_8 -> V_90 . V_95 ( V_8 -> V_90 . V_96 ) ;
V_8 -> V_90 . V_66 = V_8 -> V_90 . V_95 ( V_8 -> V_90 . V_97 ) ;
V_77 = F_37 ( & V_8 -> V_90 . V_6 ) ;
if ( V_77 )
goto V_98;
V_8 -> V_30 = V_99 + ( V_73 ? V_8 -> V_90 . V_6 . V_14 :
V_58 -> V_89 * 32 ) ;
F_20 ( V_8 ) ;
F_38 ( & V_8 -> V_100 , & V_101 ) ;
return 0 ;
V_98:
F_39 ( & V_8 -> V_90 ) ;
V_87:
F_40 ( V_8 -> V_14 ) ;
V_86:
F_41 ( V_76 -> V_83 , F_31 ( V_76 ) ) ;
V_82:
F_42 ( V_8 ) ;
F_43 ( & V_58 -> V_62 , L_7 , V_102 , V_77 ) ;
return V_77 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_103 ) ;
}
