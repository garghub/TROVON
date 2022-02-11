static int F_1 ( struct V_1 * V_2 , T_1 type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_8 , V_9 ;
T_1 V_10 = V_2 -> V_11 ;
T_1 V_12 = V_6 -> V_13 . V_4 . V_14 + V_10 ;
int V_15 ;
void T_2 * V_16 = V_6 -> V_14 ;
V_6 -> V_17 &= ~ ( 1 << V_10 ) ;
switch ( type ) {
case V_18 :
V_15 = V_19 ;
break;
case V_20 :
V_15 = V_21 ;
break;
case V_22 :
if ( V_23 >= 0 ) {
V_15 = V_24 ;
} else {
V_9 = F_3 ( V_12 ) ;
if ( V_9 ) {
V_15 = V_25 ;
F_4 ( L_1 , V_12 ) ;
} else {
V_15 = V_26 ;
F_4 ( L_2 , V_12 ) ;
}
V_6 -> V_17 |= 1 << V_10 ;
}
break;
case V_27 :
V_15 = V_25 ;
break;
case V_28 :
V_15 = V_26 ;
break;
default:
return - V_29 ;
}
if ( V_23 >= 0 ) {
V_9 = F_5 ( V_6 -> V_14 + V_23 ) ;
if ( V_15 == V_24 )
F_6 ( V_9 | ( 1 << V_10 ) ,
V_6 -> V_14 + V_23 ) ;
else
F_6 ( V_9 & ~ ( 1 << V_10 ) ,
V_6 -> V_14 + V_23 ) ;
}
if ( V_15 != V_24 ) {
V_16 += V_30 + ( ( V_10 & 0x10 ) >> 2 ) ;
V_8 = V_10 & 0xf ;
V_9 = F_5 ( V_16 ) & ~ ( 0x3 << ( V_8 << 1 ) ) ;
F_6 ( V_9 | ( V_15 << ( V_8 << 1 ) ) , V_16 ) ;
}
F_6 ( 1 << V_10 , V_6 -> V_14 + V_31 ) ;
return 0 ;
}
static void F_7 ( struct V_5 * V_6 , T_1 V_12 )
{
void T_2 * V_16 = V_6 -> V_14 ;
T_1 V_8 , V_9 ;
int V_15 ;
V_16 += V_30 + ( ( V_12 & 0x10 ) >> 2 ) ;
V_8 = V_12 & 0xf ;
V_9 = F_5 ( V_16 ) ;
V_15 = ( V_9 >> ( V_8 << 1 ) ) & 3 ;
V_9 &= ~ ( 0x3 << ( V_8 << 1 ) ) ;
if ( V_15 == V_26 ) {
V_15 = V_25 ;
F_4 ( L_3 , V_12 ) ;
} else if ( V_15 == V_25 ) {
V_15 = V_26 ;
F_4 ( L_4 , V_12 ) ;
} else {
F_8 ( L_5 ,
V_12 , V_15 ) ;
return;
}
F_6 ( V_9 | ( V_15 << ( V_8 << 1 ) ) , V_16 ) ;
}
static void F_9 ( struct V_5 * V_6 , T_1 V_32 )
{
while ( V_32 != 0 ) {
int V_33 = F_10 ( V_32 ) - 1 ;
if ( V_6 -> V_17 & ( 1 << V_33 ) )
F_7 ( V_6 , V_33 ) ;
F_11 ( F_12 ( V_6 -> V_34 , V_33 ) ) ;
V_32 &= ~ ( 1 << V_33 ) ;
}
}
static void F_13 ( struct V_35 * V_36 )
{
T_1 V_32 ;
struct V_5 * V_6 = F_14 ( V_36 ) ;
struct V_37 * V_38 = F_15 ( V_36 ) ;
F_16 ( V_38 , V_36 ) ;
V_32 = F_5 ( V_6 -> V_14 + V_31 ) & F_5 ( V_6 -> V_14 + V_39 ) ;
F_9 ( V_6 , V_32 ) ;
F_17 ( V_38 , V_36 ) ;
}
static void F_18 ( struct V_35 * V_36 )
{
T_1 V_40 , V_32 ;
struct V_5 * V_6 ;
struct V_37 * V_38 = F_15 ( V_36 ) ;
F_16 ( V_38 , V_36 ) ;
F_19 (port, &mxc_gpio_ports, node) {
V_40 = F_5 ( V_6 -> V_14 + V_39 ) ;
if ( ! V_40 )
continue;
V_32 = F_5 ( V_6 -> V_14 + V_31 ) & V_40 ;
if ( V_32 )
F_9 ( V_6 , V_32 ) ;
}
F_17 ( V_38 , V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_10 = V_2 -> V_11 ;
if ( V_41 ) {
if ( V_6 -> V_42 && ( V_10 >= 16 ) )
F_21 ( V_6 -> V_42 ) ;
else
F_21 ( V_6 -> V_43 ) ;
} else {
if ( V_6 -> V_42 && ( V_10 >= 16 ) )
F_22 ( V_6 -> V_42 ) ;
else
F_22 ( V_6 -> V_43 ) ;
}
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , int V_44 )
{
struct V_3 * V_4 ;
struct V_45 * V_46 ;
V_4 = F_24 ( L_6 , 1 , V_44 ,
V_6 -> V_14 , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_4 -> V_7 = V_6 ;
V_46 = V_4 -> V_49 ;
V_46 -> V_38 . V_50 = V_51 ;
V_46 -> V_38 . V_52 = V_53 ;
V_46 -> V_38 . V_54 = V_55 ;
V_46 -> V_38 . V_56 = F_1 ;
V_46 -> V_38 . V_57 = F_20 ;
V_46 -> V_38 . V_58 = V_59 ;
V_46 -> V_60 . V_61 = V_31 ;
V_46 -> V_60 . V_62 = V_39 ;
F_25 ( V_4 , F_26 ( 32 ) , V_63 ,
V_64 , 0 ) ;
return 0 ;
}
static void F_27 ( struct V_65 * V_66 )
{
const struct V_67 * V_68 =
F_28 ( V_69 , & V_66 -> V_70 ) ;
enum V_71 V_72 ;
if ( V_68 )
V_66 -> V_73 = V_68 -> V_74 ;
V_72 = V_66 -> V_73 -> V_75 ;
if ( V_71 ) {
F_29 ( V_71 != V_72 ) ;
return;
}
if ( V_72 == V_76 )
V_77 = & V_78 ;
else if ( V_72 == V_79 )
V_77 = & V_80 ;
else
V_77 = & V_81 ;
V_71 = V_72 ;
}
static int F_30 ( struct V_82 * V_4 , unsigned V_83 )
{
struct V_84 * V_13 = F_31 ( V_4 ) ;
struct V_5 * V_6 =
F_32 ( V_13 , struct V_5 , V_13 ) ;
return F_12 ( V_6 -> V_34 , V_83 ) ;
}
static int F_33 ( struct V_65 * V_66 )
{
struct V_85 * V_86 = V_66 -> V_70 . V_87 ;
struct V_5 * V_6 ;
struct V_88 * V_89 ;
int V_44 ;
int V_90 ;
F_27 ( V_66 ) ;
V_6 = F_34 ( & V_66 -> V_70 , sizeof( * V_6 ) , V_91 ) ;
if ( ! V_6 )
return - V_48 ;
V_89 = F_35 ( V_66 , V_92 , 0 ) ;
V_6 -> V_14 = F_36 ( & V_66 -> V_70 , V_89 ) ;
if ( F_37 ( V_6 -> V_14 ) )
return F_38 ( V_6 -> V_14 ) ;
V_6 -> V_42 = F_39 ( V_66 , 1 ) ;
V_6 -> V_43 = F_39 ( V_66 , 0 ) ;
if ( V_6 -> V_43 < 0 )
return V_6 -> V_43 ;
F_6 ( 0 , V_6 -> V_14 + V_39 ) ;
F_6 ( ~ 0 , V_6 -> V_14 + V_31 ) ;
if ( V_71 == V_93 ) {
F_40 ( V_6 -> V_43 , F_18 ) ;
} else {
F_41 ( V_6 -> V_43 ,
F_13 , V_6 ) ;
if ( V_6 -> V_42 > 0 )
F_41 ( V_6 -> V_42 ,
F_13 ,
V_6 ) ;
}
V_90 = F_42 ( & V_6 -> V_13 , & V_66 -> V_70 , 4 ,
V_6 -> V_14 + V_94 ,
V_6 -> V_14 + V_95 , NULL ,
V_6 -> V_14 + V_96 , NULL ,
V_97 ) ;
if ( V_90 )
goto V_98;
V_6 -> V_13 . V_4 . V_99 = F_30 ;
V_6 -> V_13 . V_4 . V_14 = ( V_66 -> V_100 < 0 ) ? F_43 ( V_86 , L_7 ) * 32 :
V_66 -> V_100 * 32 ;
V_90 = F_44 ( & V_6 -> V_13 . V_4 ) ;
if ( V_90 )
goto V_101;
V_44 = F_45 ( - 1 , 0 , 32 , F_46 () ) ;
if ( V_44 < 0 ) {
V_90 = V_44 ;
goto V_102;
}
V_6 -> V_34 = F_47 ( V_86 , 32 , V_44 , 0 ,
& V_103 , NULL ) ;
if ( ! V_6 -> V_34 ) {
V_90 = - V_104 ;
goto V_105;
}
V_90 = F_23 ( V_6 , V_44 ) ;
if ( V_90 < 0 )
goto V_106;
F_48 ( & V_6 -> V_107 , & V_108 ) ;
return 0 ;
V_106:
F_49 ( V_6 -> V_34 ) ;
V_105:
F_50 ( V_44 , 32 ) ;
V_102:
F_51 ( & V_6 -> V_13 . V_4 ) ;
V_101:
F_52 ( & V_6 -> V_13 ) ;
V_98:
F_53 ( & V_66 -> V_70 , L_8 , V_109 , V_90 ) ;
return V_90 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_110 ) ;
}
