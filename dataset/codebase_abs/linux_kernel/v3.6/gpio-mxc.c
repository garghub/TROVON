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
static void F_13 ( T_1 V_35 , struct V_36 * V_37 )
{
T_1 V_32 ;
struct V_5 * V_6 = F_14 ( V_35 ) ;
struct V_38 * V_39 = F_15 ( V_35 ) ;
F_16 ( V_39 , V_37 ) ;
V_32 = F_5 ( V_6 -> V_14 + V_31 ) & F_5 ( V_6 -> V_14 + V_40 ) ;
F_9 ( V_6 , V_32 ) ;
F_17 ( V_39 , V_37 ) ;
}
static void F_18 ( T_1 V_35 , struct V_36 * V_37 )
{
T_1 V_41 , V_32 ;
struct V_5 * V_6 ;
F_19 (port, &mxc_gpio_ports, node) {
V_41 = F_5 ( V_6 -> V_14 + V_40 ) ;
if ( ! V_41 )
continue;
V_32 = F_5 ( V_6 -> V_14 + V_31 ) & V_41 ;
if ( V_32 )
F_9 ( V_6 , V_32 ) ;
}
}
static int F_20 ( struct V_1 * V_2 , T_1 V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_10 = V_2 -> V_11 ;
if ( V_42 ) {
if ( V_6 -> V_43 && ( V_10 >= 16 ) )
F_21 ( V_6 -> V_43 ) ;
else
F_21 ( V_6 -> V_35 ) ;
} else {
if ( V_6 -> V_43 && ( V_10 >= 16 ) )
F_22 ( V_6 -> V_43 ) ;
else
F_22 ( V_6 -> V_35 ) ;
}
return 0 ;
}
static void T_3 F_23 ( struct V_5 * V_6 , int V_44 )
{
struct V_3 * V_4 ;
struct V_45 * V_46 ;
V_4 = F_24 ( L_6 , 1 , V_44 ,
V_6 -> V_14 , V_47 ) ;
V_4 -> V_7 = V_6 ;
V_46 = V_4 -> V_48 ;
V_46 -> V_39 . V_49 = V_50 ;
V_46 -> V_39 . V_51 = V_52 ;
V_46 -> V_39 . V_53 = V_54 ;
V_46 -> V_39 . V_55 = F_1 ;
V_46 -> V_39 . V_56 = F_20 ;
V_46 -> V_57 . V_58 = V_31 ;
V_46 -> V_57 . V_59 = V_40 ;
F_25 ( V_4 , F_26 ( 32 ) , V_60 ,
V_61 , 0 ) ;
}
static void T_4 F_27 ( struct V_62 * V_63 )
{
const struct V_64 * V_65 =
F_28 ( V_66 , & V_63 -> V_67 ) ;
enum V_68 V_69 ;
if ( V_65 )
V_63 -> V_70 = V_65 -> V_71 ;
V_69 = V_63 -> V_70 -> V_72 ;
if ( V_68 ) {
F_29 ( V_68 != V_69 ) ;
return;
}
if ( V_69 == V_73 )
V_74 = & V_75 ;
else if ( V_69 == V_76 )
V_74 = & V_77 ;
else
V_74 = & V_78 ;
V_68 = V_69 ;
}
static int F_30 ( struct V_79 * V_4 , unsigned V_80 )
{
struct V_81 * V_13 = F_31 ( V_4 ) ;
struct V_5 * V_6 =
F_32 ( V_13 , struct V_5 , V_13 ) ;
return F_12 ( V_6 -> V_34 , V_80 ) ;
}
static int T_4 F_33 ( struct V_62 * V_63 )
{
struct V_82 * V_83 = V_63 -> V_67 . V_84 ;
struct V_5 * V_6 ;
struct V_85 * V_86 ;
int V_44 ;
int V_87 ;
F_27 ( V_63 ) ;
V_6 = F_34 ( sizeof( struct V_5 ) , V_88 ) ;
if ( ! V_6 )
return - V_89 ;
V_86 = F_35 ( V_63 , V_90 , 0 ) ;
if ( ! V_86 ) {
V_87 = - V_91 ;
goto V_92;
}
if ( ! F_36 ( V_86 -> V_93 , F_37 ( V_86 ) ,
V_63 -> V_94 ) ) {
V_87 = - V_95 ;
goto V_92;
}
V_6 -> V_14 = F_38 ( V_86 -> V_93 , F_37 ( V_86 ) ) ;
if ( ! V_6 -> V_14 ) {
V_87 = - V_89 ;
goto V_96;
}
V_6 -> V_43 = F_39 ( V_63 , 1 ) ;
V_6 -> V_35 = F_39 ( V_63 , 0 ) ;
if ( V_6 -> V_35 < 0 ) {
V_87 = - V_29 ;
goto V_97;
}
F_6 ( 0 , V_6 -> V_14 + V_40 ) ;
F_6 ( ~ 0 , V_6 -> V_14 + V_31 ) ;
if ( V_68 == V_98 ) {
F_40 ( V_6 -> V_35 , F_18 ) ;
} else {
F_40 ( V_6 -> V_35 , F_13 ) ;
F_41 ( V_6 -> V_35 , V_6 ) ;
if ( V_6 -> V_43 > 0 ) {
F_40 ( V_6 -> V_43 ,
F_13 ) ;
F_41 ( V_6 -> V_43 , V_6 ) ;
}
}
V_87 = F_42 ( & V_6 -> V_13 , & V_63 -> V_67 , 4 ,
V_6 -> V_14 + V_99 ,
V_6 -> V_14 + V_100 , NULL ,
V_6 -> V_14 + V_101 , NULL , 0 ) ;
if ( V_87 )
goto V_97;
V_6 -> V_13 . V_4 . V_102 = F_30 ;
V_6 -> V_13 . V_4 . V_14 = ( V_63 -> V_103 < 0 ) ? F_43 ( V_83 , L_7 ) * 32 :
V_63 -> V_103 * 32 ;
V_87 = F_44 ( & V_6 -> V_13 . V_4 ) ;
if ( V_87 )
goto V_104;
V_44 = F_45 ( - 1 , 0 , 32 , F_46 () ) ;
if ( V_44 < 0 ) {
V_87 = V_44 ;
goto V_105;
}
V_6 -> V_34 = F_47 ( V_83 , 32 , V_44 , 0 ,
& V_106 , NULL ) ;
if ( ! V_6 -> V_34 ) {
V_87 = - V_91 ;
goto V_107;
}
F_23 ( V_6 , V_44 ) ;
F_48 ( & V_6 -> V_108 , & V_109 ) ;
return 0 ;
V_107:
F_49 ( V_44 , 32 ) ;
V_105:
F_50 ( F_51 ( & V_6 -> V_13 . V_4 ) < 0 ) ;
V_104:
F_52 ( & V_6 -> V_13 ) ;
V_97:
F_53 ( V_6 -> V_14 ) ;
V_96:
F_54 ( V_86 -> V_93 , F_37 ( V_86 ) ) ;
V_92:
F_55 ( V_6 ) ;
F_56 ( & V_63 -> V_67 , L_8 , V_110 , V_87 ) ;
return V_87 ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_111 ) ;
}
