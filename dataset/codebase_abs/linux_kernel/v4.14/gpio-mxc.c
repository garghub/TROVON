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
int V_41 ;
if ( V_40 ) {
if ( V_6 -> V_42 && ( V_10 >= 16 ) )
V_41 = F_21 ( V_6 -> V_42 ) ;
else
V_41 = F_21 ( V_6 -> V_43 ) ;
} else {
if ( V_6 -> V_42 && ( V_10 >= 16 ) )
V_41 = F_22 ( V_6 -> V_42 ) ;
else
V_41 = F_22 ( V_6 -> V_43 ) ;
}
return V_41 ;
}
static int F_23 ( struct V_5 * V_6 , int V_44 )
{
struct V_3 * V_4 ;
struct V_45 * V_46 ;
int V_47 ;
V_4 = F_24 ( V_6 -> V_48 , L_6 , 1 , V_44 ,
V_6 -> V_13 , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_7 = V_6 ;
V_46 = V_4 -> V_51 ;
V_46 -> V_37 . V_52 = V_53 ;
V_46 -> V_37 . V_54 = V_55 ;
V_46 -> V_37 . V_56 = V_57 ;
V_46 -> V_37 . V_58 = F_1 ;
V_46 -> V_37 . V_59 = F_20 ;
V_46 -> V_37 . V_60 = V_61 ;
V_46 -> V_62 . V_63 = V_30 ;
V_46 -> V_62 . V_64 = V_38 ;
V_47 = F_25 ( V_6 -> V_48 , V_4 , F_26 ( 32 ) ,
V_65 ,
V_66 , 0 ) ;
return V_47 ;
}
static void F_27 ( struct V_67 * V_68 )
{
const struct V_69 * V_70 =
F_28 ( V_71 , & V_68 -> V_48 ) ;
enum V_72 V_73 ;
if ( V_70 )
V_68 -> V_74 = V_70 -> V_75 ;
V_73 = V_68 -> V_74 -> V_76 ;
if ( V_72 ) {
F_29 ( V_72 != V_73 ) ;
return;
}
if ( V_73 == V_77 )
V_78 = & V_79 ;
else if ( V_73 == V_80 )
V_78 = & V_81 ;
else
V_78 = & V_82 ;
V_72 = V_73 ;
}
static int F_30 ( struct V_83 * V_4 , unsigned V_84 )
{
struct V_5 * V_6 = F_31 ( V_4 ) ;
return F_12 ( V_6 -> V_33 , V_84 ) ;
}
static int F_32 ( struct V_67 * V_68 )
{
struct V_85 * V_86 = V_68 -> V_48 . V_87 ;
struct V_5 * V_6 ;
struct V_88 * V_89 ;
int V_44 ;
int V_90 ;
F_27 ( V_68 ) ;
V_6 = F_33 ( & V_68 -> V_48 , sizeof( * V_6 ) , V_91 ) ;
if ( ! V_6 )
return - V_50 ;
V_6 -> V_48 = & V_68 -> V_48 ;
V_89 = F_34 ( V_68 , V_92 , 0 ) ;
V_6 -> V_13 = F_35 ( & V_68 -> V_48 , V_89 ) ;
if ( F_36 ( V_6 -> V_13 ) )
return F_37 ( V_6 -> V_13 ) ;
V_6 -> V_42 = F_38 ( V_68 , 1 ) ;
if ( V_6 -> V_42 < 0 )
V_6 -> V_42 = 0 ;
V_6 -> V_43 = F_38 ( V_68 , 0 ) ;
if ( V_6 -> V_43 < 0 )
return V_6 -> V_43 ;
F_6 ( 0 , V_6 -> V_13 + V_38 ) ;
F_6 ( ~ 0 , V_6 -> V_13 + V_30 ) ;
if ( V_72 == V_93 ) {
F_39 ( V_6 -> V_43 , F_18 ) ;
} else {
F_40 ( V_6 -> V_43 ,
F_13 , V_6 ) ;
if ( V_6 -> V_42 > 0 )
F_40 ( V_6 -> V_42 ,
F_13 ,
V_6 ) ;
}
V_90 = F_41 ( & V_6 -> V_4 , & V_68 -> V_48 , 4 ,
V_6 -> V_13 + V_94 ,
V_6 -> V_13 + V_95 , NULL ,
V_6 -> V_13 + V_96 , NULL ,
V_97 ) ;
if ( V_90 )
goto V_98;
if ( F_42 ( V_86 , L_7 ) ) {
V_6 -> V_4 . V_99 = V_100 ;
V_6 -> V_4 . free = V_101 ;
}
V_6 -> V_4 . V_102 = F_30 ;
V_6 -> V_4 . V_13 = ( V_68 -> V_103 < 0 ) ? F_43 ( V_86 , L_8 ) * 32 :
V_68 -> V_103 * 32 ;
V_90 = F_44 ( & V_68 -> V_48 , & V_6 -> V_4 , V_6 ) ;
if ( V_90 )
goto V_98;
V_44 = F_45 ( & V_68 -> V_48 , - 1 , 0 , 32 , F_46 () ) ;
if ( V_44 < 0 ) {
V_90 = V_44 ;
goto V_98;
}
V_6 -> V_33 = F_47 ( V_86 , 32 , V_44 , 0 ,
& V_104 , NULL ) ;
if ( ! V_6 -> V_33 ) {
V_90 = - V_105 ;
goto V_98;
}
V_90 = F_23 ( V_6 , V_44 ) ;
if ( V_90 < 0 )
goto V_106;
F_48 ( & V_6 -> V_107 , & V_108 ) ;
return 0 ;
V_106:
F_49 ( V_6 -> V_33 ) ;
V_98:
F_50 ( & V_68 -> V_48 , L_9 , V_109 , V_90 ) ;
return V_90 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_110 ) ;
}
