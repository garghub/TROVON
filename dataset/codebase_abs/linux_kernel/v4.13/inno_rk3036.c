static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> type = V_5 ;
V_4 -> V_6 = 2 ;
V_4 -> V_7 . integer . V_8 = 0 ;
V_4 -> V_7 . integer . V_9 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_14 , V_15 , V_16 ;
V_15 = F_4 ( V_13 , V_17 , & V_16 ) ;
if ( V_15 )
return V_15 ;
V_14 = ( ( V_16 >> V_18 ) &
V_19 ) == V_20 ;
V_11 -> V_7 . integer . V_7 [ 0 ] = V_14 ;
V_14 = ( ( V_16 >> V_21 ) &
V_19 ) == V_20 ;
V_11 -> V_7 . integer . V_7 [ 1 ] = V_14 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
int V_14 , V_15 , V_22 ;
V_14 = ( V_11 -> V_7 . integer . V_7 [ 0 ] ?
V_20 : V_23 ) <<
V_18 ;
V_14 |= ( V_11 -> V_7 . integer . V_7 [ 1 ] ?
V_20 : V_23 ) <<
V_21 ;
V_22 = V_19 << V_18 |
V_19 << V_21 ;
V_15 = F_6 ( V_13 , V_17 ,
V_22 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_27 * V_28 = V_25 -> V_28 ;
unsigned int V_29 = 0 , V_30 = 0 , V_31 = 0 ;
F_8 ( V_28 -> V_32 , L_1 , V_26 ) ;
switch ( V_26 & V_33 ) {
case V_34 :
V_29 |= V_35 |
V_36 ;
break;
case V_37 :
V_29 |= V_38 |
V_39 ;
break;
default:
F_9 ( V_28 -> V_32 , L_2 ) ;
return - V_40 ;
}
switch ( V_26 & V_41 ) {
case V_42 :
V_30 |= V_43 ;
break;
case V_44 :
V_30 |= V_45 ;
break;
case V_46 :
V_30 |= V_47 ;
break;
case V_48 :
V_30 |= V_49 ;
break;
default:
F_9 ( V_28 -> V_32 , L_3 ) ;
return - V_40 ;
}
switch ( V_26 & V_50 ) {
case V_51 :
V_30 |= V_52 ;
V_31 |= V_53 ;
break;
case V_54 :
V_30 |= V_55 ;
V_31 |= V_56 ;
break;
case V_57 :
V_30 |= V_55 ;
V_31 |= V_53 ;
break;
case V_58 :
V_30 |= V_52 ;
V_31 |= V_56 ;
break;
default:
F_9 ( V_28 -> V_32 , L_3 ) ;
return - V_40 ;
}
F_10 ( V_28 , V_59 , V_60 |
V_61 , V_29 ) ;
F_10 ( V_28 , V_62 , V_63 |
V_64 , V_30 ) ;
F_10 ( V_28 , V_65 , V_66 , V_31 ) ;
return 0 ;
}
static int F_11 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_24 * V_25 )
{
struct V_27 * V_28 = V_25 -> V_28 ;
unsigned int V_30 = 0 , V_31 = 0 ;
switch ( F_12 ( V_70 ) ) {
case V_71 :
V_30 |= V_72 ;
break;
case V_73 :
V_30 |= V_74 ;
break;
case V_75 :
V_30 |= V_76 ;
break;
case V_77 :
V_30 |= V_78 ;
break;
default:
return - V_40 ;
}
V_30 |= V_52 ;
V_31 |= V_79 | V_80 ;
F_10 ( V_28 , V_62 , V_63 |
V_81 , V_30 ) ;
F_10 ( V_28 , V_65 , V_82 |
V_83 , V_31 ) ;
return 0 ;
}
static void F_13 ( struct V_27 * V_28 )
{
F_14 ( V_28 , V_84 ,
V_85 | V_86 ) ;
F_14 ( V_28 , V_84 ,
V_87 | V_88 ) ;
}
static int F_15 ( struct V_27 * V_28 )
{
F_13 ( V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_27 * V_28 )
{
F_13 ( V_28 ) ;
return 0 ;
}
static int F_17 ( struct V_27 * V_28 ,
enum V_89 V_90 )
{
switch ( V_90 ) {
case V_91 :
F_14 ( V_28 , V_92 , V_93 ) ;
F_14 ( V_28 , V_94 , V_95 ) ;
break;
case V_96 :
F_14 ( V_28 , V_92 , V_93 ) ;
F_14 ( V_28 , V_94 , V_97 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_18 ( struct V_98 * V_99 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 = V_99 -> V_32 . V_103 ;
struct V_104 * V_105 ;
void T_1 * V_106 ;
struct V_107 * V_108 ;
int V_15 ;
V_101 = F_19 ( & V_99 -> V_32 , sizeof( * V_101 ) , V_109 ) ;
if ( ! V_101 )
return - V_110 ;
V_105 = F_20 ( V_99 , V_111 , 0 ) ;
V_106 = F_21 ( & V_99 -> V_32 , V_105 ) ;
if ( F_22 ( V_106 ) )
return F_23 ( V_106 ) ;
V_101 -> V_106 = V_106 ;
V_101 -> V_107 = F_24 ( & V_99 -> V_32 , V_101 -> V_106 ,
& V_112 ) ;
if ( F_22 ( V_101 -> V_107 ) ) {
F_9 ( & V_99 -> V_32 , L_4 ) ;
return F_23 ( V_101 -> V_107 ) ;
}
V_108 = F_25 ( V_103 , L_5 ) ;
if ( F_22 ( V_108 ) ) {
F_9 ( & V_99 -> V_32 , L_6 ) ;
return F_23 ( V_108 ) ;
}
V_15 = F_26 ( V_108 , V_113 , V_114 ) ;
if ( V_15 ) {
F_9 ( & V_99 -> V_32 , L_7 , V_15 ) ;
return V_15 ;
}
V_101 -> V_115 = F_27 ( & V_99 -> V_32 , L_8 ) ;
if ( F_22 ( V_101 -> V_115 ) )
return F_23 ( V_101 -> V_115 ) ;
V_15 = F_28 ( V_101 -> V_115 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_99 -> V_32 , L_9 ) ;
return V_15 ;
}
V_101 -> V_32 = & V_99 -> V_32 ;
F_29 ( & V_99 -> V_32 , V_101 ) ;
V_15 = F_30 ( & V_99 -> V_32 , & V_116 ,
V_117 ,
F_31 ( V_117 ) ) ;
if ( V_15 ) {
F_32 ( V_101 -> V_115 ) ;
F_29 ( & V_99 -> V_32 , NULL ) ;
}
return V_15 ;
}
static int F_33 ( struct V_98 * V_99 )
{
struct V_100 * V_101 = F_34 ( & V_99 -> V_32 ) ;
F_35 ( & V_99 -> V_32 ) ;
F_32 ( V_101 -> V_115 ) ;
return 0 ;
}
