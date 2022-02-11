static int F_1 ( struct V_1 * V_2 , T_1 type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 , V_9 ;
T_1 V_10 = V_2 -> V_11 ;
T_1 V_12 = V_6 -> V_4 . V_13 + V_10 ;
int V_14 ;
void T_2 * V_15 = V_6 -> V_13 ;
V_6 -> V_16 &= ~ ( 1 << V_10 ) ;
switch ( type ) {
case V_17 :
V_14 = V_18 ;
break;
case V_19 :
V_14 = V_20 ;
break;
case V_21 :
if ( V_22 >= 0 ) {
V_14 = V_23 ;
} else {
V_9 = F_3 ( V_12 ) ;
if ( V_9 ) {
V_14 = V_24 ;
F_4 ( L_1 , V_12 ) ;
} else {
V_14 = V_25 ;
F_4 ( L_2 , V_12 ) ;
}
V_6 -> V_16 |= 1 << V_10 ;
}
break;
case V_26 :
V_14 = V_24 ;
break;
case V_27 :
V_14 = V_25 ;
break;
default:
return - V_28 ;
}
if ( V_22 >= 0 ) {
V_9 = F_5 ( V_6 -> V_13 + V_22 ) ;
if ( V_14 == V_23 )
F_6 ( V_9 | ( 1 << V_10 ) ,
V_6 -> V_13 + V_22 ) ;
else
F_6 ( V_9 & ~ ( 1 << V_10 ) ,
V_6 -> V_13 + V_22 ) ;
}
if ( V_14 != V_23 ) {
V_15 += V_29 + ( ( V_10 & 0x10 ) >> 2 ) ;
V_8 = V_10 & 0xf ;
V_9 = F_5 ( V_15 ) & ~ ( 0x3 << ( V_8 << 1 ) ) ;
F_6 ( V_9 | ( V_14 << ( V_8 << 1 ) ) , V_15 ) ;
}
F_6 ( 1 << V_10 , V_6 -> V_13 + V_30 ) ;
return 0 ;
}
static void F_7 ( struct V_5 * V_6 , T_1 V_12 )
{
void T_2 * V_15 = V_6 -> V_13 ;
T_1 V_8 , V_9 ;
int V_14 ;
V_15 += V_29 + ( ( V_12 & 0x10 ) >> 2 ) ;
V_8 = V_12 & 0xf ;
V_9 = F_5 ( V_15 ) ;
V_14 = ( V_9 >> ( V_8 << 1 ) ) & 3 ;
V_9 &= ~ ( 0x3 << ( V_8 << 1 ) ) ;
if ( V_14 == V_25 ) {
V_14 = V_24 ;
F_4 ( L_3 , V_12 ) ;
} else if ( V_14 == V_24 ) {
V_14 = V_25 ;
F_4 ( L_4 , V_12 ) ;
} else {
F_8 ( L_5 ,
V_12 , V_14 ) ;
return;
}
F_6 ( V_9 | ( V_14 << ( V_8 << 1 ) ) , V_15 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_31 )
{
while ( V_31 != 0 ) {
int V_32 = F_10 ( V_31 ) - 1 ;
if ( V_6 -> V_16 & ( 1 << V_32 ) )
F_7 ( V_6 , V_32 ) ;
F_11 ( F_12 ( V_6 -> V_33 , V_32 ) ) ;
V_31 &= ~ ( 1 << V_32 ) ;
}
}
static void F_13 ( struct V_34 * V_35 )
{
T_1 V_31 ;
struct V_5 * V_6 = F_14 ( V_35 ) ;
struct V_36 * V_37 = F_15 ( V_35 ) ;
F_16 ( V_37 , V_35 ) ;
V_31 = F_5 ( V_6 -> V_13 + V_30 ) & F_5 ( V_6 -> V_13 + V_38 ) ;
F_9 ( V_6 , V_31 ) ;
F_17 ( V_37 , V_35 ) ;
}
static void F_18 ( struct V_34 * V_35 )
{
T_1 V_39 , V_31 ;
struct V_5 * V_6 ;
struct V_36 * V_37 = F_15 ( V_35 ) ;
F_16 ( V_37 , V_35 ) ;
F_19 (port, &mxc_gpio_ports, node) {
V_39 = F_5 ( V_6 -> V_13 + V_38 ) ;
if ( ! V_39 )
continue;
V_31 = F_5 ( V_6 -> V_13 + V_30 ) & V_39 ;
if ( V_31 )
F_9 ( V_6 , V_31 ) ;
}
F_17 ( V_37 , V_35 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_10 = V_2 -> V_11 ;
if ( V_40 ) {
if ( V_6 -> V_41 && ( V_10 >= 16 ) )
F_21 ( V_6 -> V_41 ) ;
else
F_21 ( V_6 -> V_42 ) ;
} else {
if ( V_6 -> V_41 && ( V_10 >= 16 ) )
F_22 ( V_6 -> V_41 ) ;
else
F_22 ( V_6 -> V_42 ) ;
}
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , int V_43 )
{
struct V_3 * V_4 ;
struct V_44 * V_45 ;
V_4 = F_24 ( L_6 , 1 , V_43 ,
V_6 -> V_13 , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_7 = V_6 ;
V_45 = V_4 -> V_48 ;
V_45 -> V_37 . V_49 = V_50 ;
V_45 -> V_37 . V_51 = V_52 ;
V_45 -> V_37 . V_53 = V_54 ;
V_45 -> V_37 . V_55 = F_1 ;
V_45 -> V_37 . V_56 = F_20 ;
V_45 -> V_37 . V_57 = V_58 ;
V_45 -> V_59 . V_60 = V_30 ;
V_45 -> V_59 . V_61 = V_38 ;
F_25 ( V_4 , F_26 ( 32 ) , V_62 ,
V_63 , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_64 * V_65 )
{
const struct V_66 * V_67 =
F_28 ( V_68 , & V_65 -> V_69 ) ;
enum V_70 V_71 ;
if ( V_67 )
V_65 -> V_72 = V_67 -> V_73 ;
V_71 = V_65 -> V_72 -> V_74 ;
if ( V_70 ) {
F_29 ( V_70 != V_71 ) ;
return;
}
if ( V_71 == V_75 )
V_76 = & V_77 ;
else if ( V_71 == V_78 )
V_76 = & V_79 ;
else
V_76 = & V_80 ;
V_70 = V_71 ;
}
static int F_30 ( struct V_81 * V_4 , unsigned V_82 )
{
struct V_5 * V_6 = F_31 ( V_4 ) ;
return F_12 ( V_6 -> V_33 , V_82 ) ;
}
static int F_32 ( struct V_64 * V_65 )
{
struct V_83 * V_84 = V_65 -> V_69 . V_85 ;
struct V_5 * V_6 ;
struct V_86 * V_87 ;
int V_43 ;
int V_88 ;
F_27 ( V_65 ) ;
V_6 = F_33 ( & V_65 -> V_69 , sizeof( * V_6 ) , V_89 ) ;
if ( ! V_6 )
return - V_47 ;
V_87 = F_34 ( V_65 , V_90 , 0 ) ;
V_6 -> V_13 = F_35 ( & V_65 -> V_69 , V_87 ) ;
if ( F_36 ( V_6 -> V_13 ) )
return F_37 ( V_6 -> V_13 ) ;
V_6 -> V_41 = F_38 ( V_65 , 1 ) ;
if ( V_6 -> V_41 < 0 )
V_6 -> V_41 = 0 ;
V_6 -> V_42 = F_38 ( V_65 , 0 ) ;
if ( V_6 -> V_42 < 0 )
return V_6 -> V_42 ;
F_6 ( 0 , V_6 -> V_13 + V_38 ) ;
F_6 ( ~ 0 , V_6 -> V_13 + V_30 ) ;
if ( V_70 == V_91 ) {
F_39 ( V_6 -> V_42 , F_18 ) ;
} else {
F_40 ( V_6 -> V_42 ,
F_13 , V_6 ) ;
if ( V_6 -> V_41 > 0 )
F_40 ( V_6 -> V_41 ,
F_13 ,
V_6 ) ;
}
V_88 = F_41 ( & V_6 -> V_4 , & V_65 -> V_69 , 4 ,
V_6 -> V_13 + V_92 ,
V_6 -> V_13 + V_93 , NULL ,
V_6 -> V_13 + V_94 , NULL ,
V_95 ) ;
if ( V_88 )
goto V_96;
if ( F_42 ( V_84 , L_7 ) ) {
V_6 -> V_4 . V_97 = V_98 ;
V_6 -> V_4 . free = V_99 ;
}
V_6 -> V_4 . V_100 = F_30 ;
V_6 -> V_4 . V_13 = ( V_65 -> V_101 < 0 ) ? F_43 ( V_84 , L_8 ) * 32 :
V_65 -> V_101 * 32 ;
V_88 = F_44 ( & V_65 -> V_69 , & V_6 -> V_4 , V_6 ) ;
if ( V_88 )
goto V_96;
V_43 = F_45 ( & V_65 -> V_69 , - 1 , 0 , 32 , F_46 () ) ;
if ( V_43 < 0 ) {
V_88 = V_43 ;
goto V_96;
}
V_6 -> V_33 = F_47 ( V_84 , 32 , V_43 , 0 ,
& V_102 , NULL ) ;
if ( ! V_6 -> V_33 ) {
V_88 = - V_103 ;
goto V_96;
}
V_88 = F_23 ( V_6 , V_43 ) ;
if ( V_88 < 0 )
goto V_104;
F_48 ( & V_6 -> V_105 , & V_106 ) ;
return 0 ;
V_104:
F_49 ( V_6 -> V_33 ) ;
V_96:
F_50 ( & V_65 -> V_69 , L_9 , V_107 , V_88 ) ;
return V_88 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_108 ) ;
}
