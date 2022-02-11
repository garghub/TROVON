static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_8 :
V_7 -> V_9 = V_4 ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static inline struct V_6 * F_3 ( struct V_6 * V_7 )
{
return V_6 [ V_7 -> V_11 ] ;
}
static int F_4 ( struct V_6 * V_7 ,
unsigned int V_9 ,
unsigned int V_12 )
{
T_1 V_13 ;
int V_14 ;
struct V_6 * V_15 ;
F_5 ( V_7 -> V_16 , L_1 , V_9 , V_12 ) ;
V_15 = F_3 ( V_7 ) ;
if ( ! V_15 )
return - V_10 ;
F_5 ( V_7 -> V_16 , L_2 , V_15 -> V_17 ) ;
if ( V_15 -> V_18 && V_12 != V_15 -> V_19 ) {
F_6 ( V_7 -> V_16 ,
L_3 ,
V_15 -> V_17 , V_15 -> V_19 ) ;
return - V_10 ;
}
V_13 = F_7 ( V_15 -> V_20 + V_21 ) ;
V_13 &= ~ V_22 ;
V_13 &= ~ V_23 ;
if ( V_15 -> V_24 ) {
if ( V_9 % 32 == 0 ) {
V_13 &= ~ V_23 ;
V_14 = F_8 ( V_15 -> V_25 , 512 * V_12 ) ;
} else if ( V_9 % 48 == 0 ) {
V_13 |= V_23 ;
V_14 = F_8 ( V_15 -> V_25 , 384 * V_12 ) ;
} else {
return - V_10 ;
}
} else {
V_14 = F_8 ( V_15 -> V_25 , 512 * V_12 ) ;
V_13 &= ~ V_23 ;
}
if ( V_14 )
return V_14 ;
V_15 -> V_19 = V_12 ;
if ( ! V_15 -> V_24 ) {
F_9 ( V_13 , V_15 -> V_20 + V_21 ) ;
return 0 ;
}
switch ( V_9 / V_12 ) {
case 32 :
V_13 |= F_10 ( 4 ) ;
break;
case 64 :
V_13 |= F_10 ( 3 ) ;
break;
case 128 :
V_13 |= F_10 ( 2 ) ;
break;
case 256 :
V_13 |= F_10 ( 1 ) ;
break;
case 512 :
V_13 |= F_10 ( 0 ) ;
break;
case 48 :
V_13 |= F_10 ( 3 ) ;
break;
case 96 :
V_13 |= F_10 ( 2 ) ;
break;
case 192 :
V_13 |= F_10 ( 1 ) ;
break;
case 384 :
V_13 |= F_10 ( 0 ) ;
break;
default:
return - V_10 ;
}
F_9 ( V_13 , V_15 -> V_20 + V_21 ) ;
return 0 ;
}
int F_11 ( unsigned int V_26 )
{
struct V_6 * V_7 = V_6 [ V_26 ] ;
T_1 V_27 ;
if ( ! V_7 )
return - V_10 ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_7 -> V_16 , L_4 ) ;
return - V_30 ;
}
F_12 ( V_7 -> V_25 ) ;
F_9 ( V_31 ,
V_7 -> V_20 + V_21 + V_32 ) ;
F_9 ( V_33 ,
V_7 -> V_20 + V_21 + V_34 ) ;
V_7 -> V_24 = 0 ;
return 0 ;
}
int F_13 ( unsigned int V_26 , unsigned int V_9 ,
unsigned int V_12 )
{
struct V_6 * V_7 = V_6 [ V_26 ] ;
T_1 V_27 ;
int V_14 ;
struct V_6 * V_15 ;
if ( ! V_7 )
return - V_10 ;
F_9 ( V_35 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_9 ( V_31 ,
V_7 -> V_20 + V_21 + V_34 ) ;
V_15 = F_3 ( V_7 ) ;
if ( V_7 != V_15 ) {
F_6 ( V_7 -> V_16 , L_5 ) ;
return - V_10 ;
}
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_7 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_7 -> V_24 = 1 ;
V_14 = F_4 ( V_7 , V_9 , V_12 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_14 ( V_7 -> V_25 ) ;
if ( V_14 )
return V_14 ;
F_9 ( V_33 ,
V_7 -> V_20 + V_21 + V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_36 )
{
T_1 V_13 , V_27 ;
T_1 V_37 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_2 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_37 = F_7 ( V_7 -> V_20 + V_21 ) ;
V_37 = V_37 & ~ V_38 & ~ V_39 \
& ~ V_40 & ~ V_41 ;
V_13 = 0 ;
switch ( V_36 & V_42 ) {
case V_43 :
V_13 |= V_41 ;
V_13 &= ~ V_39 ;
break;
case V_44 :
V_13 &= ~ V_41 ;
V_13 &= ~ V_39 ;
V_13 &= ~ V_40 ;
break;
default:
return - V_10 ;
}
switch ( V_36 & V_45 ) {
case V_46 :
V_13 |= V_38 ;
V_13 |= V_39 ;
break;
case V_47 :
V_13 |= V_38 ;
V_13 &= ~ V_39 ;
break;
case V_48 :
V_13 &= ~ V_38 ;
V_13 |= V_39 ;
break;
case V_49 :
V_13 &= ~ V_38 ;
V_13 &= ~ V_39 ;
break;
}
switch ( V_36 & V_50 ) {
case V_51 :
if ( V_7 -> V_17 == V_7 -> V_11 )
V_13 &= ~ V_52 ;
else
V_13 |= V_52 ;
F_9 ( V_13 | V_37 , V_7 -> V_20 + V_21 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_16 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_17 ( V_2 , V_54 , & V_7 -> V_55 ) ;
V_7 -> V_56 = 0 ;
V_7 -> V_57 = 0 ;
F_9 ( V_35 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_9 ( V_31 ,
V_7 -> V_20 + V_21 + V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_53 * V_54 ,
struct V_58 * V_59 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_13 , V_27 ;
int V_14 ;
if ( ! V_7 -> V_9 && V_7 -> V_24 ) {
F_6 ( V_2 -> V_16 , L_6 ) ;
return - V_10 ;
}
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( V_27 & V_29 ) {
F_6 ( V_2 -> V_16 , L_4 ) ;
return - V_30 ;
}
V_14 = F_4 ( V_7 , V_7 -> V_9 , F_19 ( V_59 ) ) ;
if ( V_14 ) {
F_6 ( V_2 -> V_16 , L_7 ) ;
return V_14 ;
}
V_13 = F_7 ( V_7 -> V_20 + V_21 ) ;
V_13 &= ~ V_60 ;
V_13 &= ~ V_61 ;
switch ( F_20 ( V_59 ) ) {
case V_62 :
V_13 |= F_21 ( 0 ) ;
break;
case V_63 :
V_13 |= F_21 ( 4 ) ;
V_13 |= V_61 ;
break;
case V_64 :
V_13 |= F_21 ( 8 ) ;
V_13 |= V_61 ;
break;
default:
return - V_10 ;
}
if ( V_54 -> V_65 == V_66 ) {
V_13 &= ~ V_67 ;
} else {
V_13 |= V_67 ;
}
F_9 ( V_13 , V_7 -> V_20 + V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_9 ( V_68 ,
V_7 -> V_20 + V_21 + V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_53 * V_54 , int V_69 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_6 * V_15 ;
T_1 V_70 ;
V_15 = F_3 ( V_7 ) ;
if ( ! V_15 )
return - V_10 ;
switch ( V_69 ) {
case V_71 :
case V_72 :
case V_73 :
F_5 ( V_2 -> V_16 , L_8 ) ;
F_14 ( V_15 -> V_25 ) ;
if ( ! V_15 -> V_24 )
F_9 ( V_33 ,
V_15 -> V_20 + V_21 + V_32 ) ;
if ( V_7 != V_15 ) {
F_14 ( V_7 -> V_25 ) ;
F_9 ( V_33 ,
V_7 -> V_20 + V_21 + V_32 ) ;
}
if ( V_54 -> V_65 == V_66 ) {
F_9 ( 0 , V_7 -> V_20 + V_74 ) ;
} else {
F_7 ( V_7 -> V_20 + V_74 ) ;
}
V_15 -> V_18 = 1 ;
F_5 ( V_7 -> V_16 , L_9 ,
F_7 ( V_7 -> V_20 + V_21 ) ,
F_7 ( V_7 -> V_20 + V_28 ) ) ;
F_5 ( V_15 -> V_16 , L_9 ,
F_7 ( V_15 -> V_20 + V_21 ) ,
F_7 ( V_15 -> V_20 + V_28 ) ) ;
break;
case V_75 :
case V_76 :
case V_77 :
F_5 ( V_2 -> V_16 , L_10 ) ;
V_70 = V_78 / V_15 -> V_19 ;
if ( ! V_15 -> V_24 ) {
F_9 ( V_33 ,
V_15 -> V_20 + V_21 + V_34 ) ;
F_24 ( V_70 ) ;
}
F_12 ( V_15 -> V_25 ) ;
if ( V_7 != V_15 ) {
F_9 ( V_33 ,
V_7 -> V_20 + V_21 + V_34 ) ;
F_24 ( V_70 ) ;
F_12 ( V_7 -> V_25 ) ;
}
V_15 -> V_18 = 0 ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_79 )
{
struct V_6 * V_7 = F_26 ( V_79 -> V_16 ) ;
F_27 ( V_79 , V_7 ) ;
return 0 ;
}
static T_2 F_28 ( int V_80 , void * V_81 )
{
struct V_6 * V_7 = V_81 ;
unsigned int V_27 ;
V_27 = F_7 ( V_7 -> V_20 + V_28 ) ;
if ( ! ( V_27 & ( V_82 |
V_83 ) ) )
return V_84 ;
if ( V_27 & V_82 ) {
F_5 ( V_7 -> V_16 , L_11 , ++ V_7 -> V_56 ) ;
F_9 ( V_82 ,
V_7 -> V_20 + V_28 + V_34 ) ;
}
if ( V_27 & V_83 ) {
F_5 ( V_7 -> V_16 , L_12 , ++ V_7 -> V_57 ) ;
F_9 ( V_83 ,
V_7 -> V_20 + V_28 + V_34 ) ;
}
F_5 ( V_7 -> V_16 , L_13 ,
F_7 ( V_7 -> V_20 + V_21 ) ,
F_7 ( V_7 -> V_20 + V_28 ) ) ;
return V_85 ;
}
static int F_29 ( struct V_86 * V_87 )
{
struct V_88 * V_89 , * V_90 ;
struct V_6 * V_7 ;
struct V_91 * V_92 ;
int V_14 = 0 ;
if ( V_87 -> V_17 >= F_30 ( V_6 ) )
return - V_10 ;
V_92 = V_87 -> V_16 . V_93 ;
if ( V_92 && V_92 -> V_94 ) {
V_14 = V_92 -> V_94 () ;
if ( V_14 )
return V_14 ;
}
V_7 = F_31 ( sizeof( * V_7 ) , V_95 ) ;
if ( ! V_7 )
return - V_96 ;
V_6 [ V_87 -> V_17 ] = V_7 ;
V_7 -> V_17 = V_87 -> V_17 ;
V_7 -> V_11 = V_7 -> V_17 ;
if ( V_92 && V_92 -> V_97 ) {
V_7 -> V_11 = V_92 -> V_97 ( V_7 -> V_17 ) ;
if ( V_7 -> V_11 < 0 ||
V_7 -> V_11 >= F_30 ( V_6 ) )
return - V_10 ;
}
V_7 -> V_25 = F_32 ( & V_87 -> V_16 , NULL ) ;
if ( F_33 ( V_7 -> V_25 ) ) {
V_14 = F_34 ( V_7 -> V_25 ) ;
F_6 ( & V_87 -> V_16 , L_14 ,
V_14 ) ;
goto V_98;
}
V_89 = F_35 ( V_87 , V_99 , 0 ) ;
if ( ! V_89 ) {
V_14 = - V_100 ;
F_6 ( & V_87 -> V_16 , L_15 ,
V_14 ) ;
goto V_101;
}
if ( ! F_36 ( V_89 -> V_102 , F_37 ( V_89 ) ,
L_16 ) ) {
F_6 ( & V_87 -> V_16 , L_17 ) ;
V_14 = - V_30 ;
goto V_101;
}
V_7 -> V_20 = F_38 ( V_89 -> V_102 , F_37 ( V_89 ) ) ;
if ( ! V_7 -> V_20 ) {
F_6 ( & V_87 -> V_16 , L_18 ) ;
V_14 = - V_100 ;
goto V_103;
}
V_90 = F_35 ( V_87 , V_104 , 0 ) ;
if ( ! V_90 ) {
V_14 = - V_100 ;
F_6 ( & V_87 -> V_16 , L_19 ,
V_14 ) ;
goto V_103;
}
V_7 -> V_55 . V_105 = V_90 -> V_102 ;
V_7 -> V_80 = F_39 ( V_87 , 0 ) ;
if ( V_7 -> V_80 < 0 ) {
V_14 = V_7 -> V_80 ;
F_6 ( & V_87 -> V_16 , L_20 ,
V_14 ) ;
goto V_106;
}
V_7 -> V_16 = & V_87 -> V_16 ;
V_14 = F_40 ( V_7 -> V_80 , F_28 , 0 , L_16 , V_7 ) ;
if ( V_14 ) {
F_6 ( & V_87 -> V_16 , L_21 ) ;
goto V_106;
}
V_7 -> V_55 . V_107 = F_39 ( V_87 , 1 ) ;
if ( V_7 -> V_55 . V_107 < 0 ) {
V_14 = V_7 -> V_55 . V_107 ;
F_6 ( & V_87 -> V_16 , L_22 ,
V_14 ) ;
goto V_108;
}
F_41 ( V_87 , V_7 ) ;
V_14 = F_42 ( & V_87 -> V_16 , & V_109 ) ;
if ( V_14 ) {
F_6 ( & V_87 -> V_16 , L_23 ) ;
goto V_110;
}
V_7 -> V_111 = F_43 (
L_24 , V_87 -> V_17 ) ;
if ( ! V_7 -> V_111 ) {
V_14 = - V_96 ;
goto V_112;
}
F_41 ( V_7 -> V_111 , V_7 ) ;
V_14 = F_44 ( V_7 -> V_111 ) ;
if ( V_14 ) {
F_6 ( & V_87 -> V_16 , L_25 ) ;
goto V_113;
}
return 0 ;
V_113:
F_45 ( V_7 -> V_111 ) ;
V_112:
F_46 ( & V_87 -> V_16 ) ;
V_110:
V_108:
F_47 ( V_7 -> V_80 , V_7 ) ;
V_106:
F_48 ( V_7 -> V_20 ) ;
V_103:
F_49 ( V_89 -> V_102 , F_37 ( V_89 ) ) ;
V_101:
F_50 ( V_7 -> V_25 ) ;
V_98:
F_51 ( V_7 ) ;
return V_14 ;
}
static int T_3 F_52 ( struct V_86 * V_87 )
{
struct V_88 * V_114 = F_35 ( V_87 , V_99 , 0 ) ;
struct V_6 * V_7 = F_53 ( V_87 ) ;
F_54 ( V_7 -> V_111 ) ;
F_46 ( & V_87 -> V_16 ) ;
F_48 ( V_7 -> V_20 ) ;
F_49 ( V_114 -> V_102 , F_37 ( V_114 ) ) ;
F_47 ( V_7 -> V_80 , V_7 ) ;
F_50 ( V_7 -> V_25 ) ;
F_51 ( V_7 ) ;
return 0 ;
}
static int T_4 F_55 ( void )
{
return F_56 ( & V_115 ) ;
}
static void T_5 F_57 ( void )
{
F_58 ( & V_115 ) ;
}
