static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_6 = 0 ;
switch ( V_4 -> V_7 ) {
case V_8 :
case V_9 :
V_6 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
break;
default:
F_2 ( V_4 -> V_13 , L_1 ) ;
break;
} ;
return V_4 -> V_14 + ( V_2 -> V_15 * V_6 ) ;
}
static inline void T_1 * F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_6 = 0 ;
switch ( V_4 -> V_7 ) {
case V_9 :
V_6 = V_16 ;
break;
default:
F_2 ( V_4 -> V_13 , L_1 ) ;
break;
} ;
return V_4 -> V_17 + ( V_2 -> V_15 * V_6 ) ;
}
static void F_4 ( void T_1 * V_18 , T_2 V_19 ,
T_2 V_20 , T_2 V_21 , T_2 V_22 )
{
T_2 V_23 ;
F_5 ( V_19 , V_18 + V_24 ) ;
V_23 = F_6 ( V_18 + F_7 ( V_20 ) ) ;
V_23 = ( V_23 & V_21 ) | V_22 ;
F_5 ( V_23 , V_18 + F_7 ( V_20 ) ) ;
}
static T_2 F_8 ( void T_1 * V_18 , T_2 V_19 , T_2 V_20 )
{
F_5 ( V_19 , V_18 + V_24 ) ;
return F_6 ( V_18 + F_7 ( V_20 ) ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
void T_1 * V_25 = F_1 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_23 ;
V_23 = V_26 | V_27 ;
F_4 ( V_25 , V_28 , V_29 , ~ V_23 , V_23 ) ;
F_4 ( V_25 , V_28 , V_30 ,
~ V_31 ,
V_32 ) ;
if ( V_2 -> V_33 ) {
F_10 ( V_4 -> V_13 , L_2 , V_2 -> V_15 ) ;
V_23 = V_34 ;
} else {
V_23 = V_35 ;
}
F_4 ( V_25 , V_28 , V_36 ,
~ V_37 , V_23 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_38 ;
unsigned int V_39 ;
void T_1 * V_25 = F_1 ( V_2 ) ;
void T_1 * V_17 = F_3 ( V_2 ) ;
struct V_40 * V_13 = V_2 -> V_5 -> V_13 ;
V_39 = 0x0 ;
V_39 |= ( 0xc << V_41 ) ;
V_39 |= ( 0x4 << V_42 ) ;
V_39 |= ( 0x9 << V_43 ) ;
V_39 |= ( 0x3 << V_44 ) ;
F_4 ( V_25 , V_45 , V_46 , 0x0 , V_39 ) ;
V_39 = 0x0 ;
V_39 |= ( 0x1b << V_47 ) ;
V_39 |= ( 0x2 << V_48 ) ;
V_39 |= ( 0x9 << V_49 ) ;
F_4 ( V_25 , V_45 , V_50 , 0x0 , V_39 ) ;
V_39 = V_51 ;
F_4 ( V_25 , V_52 , V_53 , 0x0 , V_39 ) ;
V_39 = V_54 ;
F_4 ( V_25 , V_52 , V_55 , 0x0 , V_39 ) ;
V_39 = V_56 ;
F_4 ( V_25 , V_52 , V_57 , 0x0 , V_39 ) ;
F_4 ( V_25 , V_58 , V_59 ,
~ V_60 ,
V_61 ) ;
F_5 ( V_62 , V_17 + V_63 ) ;
F_12 ( 1 ) ;
F_5 ( 0x0 , V_17 + V_63 ) ;
F_12 ( 1 ) ;
V_38 = 50 ;
while ( V_38 ) {
V_39 = F_8 ( V_25 , V_58 ,
V_64 ) ;
if ( V_39 & V_65 )
break;
F_13 ( 20 ) ;
V_38 -- ;
}
if ( ! V_38 ) {
F_2 ( V_13 , L_3 , V_2 -> V_15 ) ;
return - V_66 ;
}
F_14 ( V_13 , L_4 , V_2 -> V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_67 * V_67 )
{
int V_68 ;
struct V_1 * V_2 = F_16 ( V_67 ) ;
switch ( V_2 -> V_5 -> V_7 ) {
case V_8 :
case V_11 :
V_68 = F_9 ( V_2 ) ;
break;
case V_9 :
V_68 = F_11 ( V_2 ) ;
break;
default:
V_68 = - V_69 ;
} ;
return 0 ;
}
static int F_17 ( struct V_70 * V_71 )
{
struct V_40 * V_13 = & V_71 -> V_13 ;
struct V_72 * V_73 = V_13 -> V_74 , * V_75 ;
const struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_82 , V_83 = 0 ;
if ( F_18 ( V_73 ) == 0 )
return - V_69 ;
V_4 = F_19 ( V_13 , sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return - V_85 ;
F_20 ( V_13 , V_4 ) ;
V_4 -> V_13 = V_13 ;
V_79 = F_21 ( V_71 , V_86 , L_5 ) ;
V_4 -> V_14 = F_22 ( V_13 , V_79 ) ;
if ( F_23 ( V_4 -> V_14 ) )
return F_24 ( V_4 -> V_14 ) ;
V_77 = F_25 ( V_87 , V_73 ) ;
if ( V_77 )
V_4 -> V_7 = (enum V_88 ) V_77 -> V_89 ;
else
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_7 == V_9 ) {
V_79 = F_21 ( V_71 , V_86 ,
L_6 ) ;
V_4 -> V_17 = F_22 ( V_13 , V_79 ) ;
if ( F_23 ( V_4 -> V_17 ) )
return F_24 ( V_4 -> V_17 ) ;
}
F_26 (dn, child) {
unsigned int V_90 ;
struct V_1 * V_2 ;
if ( F_27 ( V_75 , L_7 , & V_90 ) ) {
F_2 ( V_13 , L_8 ,
V_75 -> V_91 ) ;
V_82 = - V_92 ;
goto V_93;
}
if ( V_90 >= V_94 ) {
F_2 ( V_13 , L_9 , V_90 ) ;
V_82 = - V_92 ;
goto V_93;
}
if ( V_4 -> V_95 [ V_90 ] . V_67 ) {
F_2 ( V_13 , L_10 , V_90 ) ;
V_82 = - V_92 ;
goto V_93;
}
V_2 = & V_4 -> V_95 [ V_90 ] ;
V_2 -> V_15 = V_90 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_67 = F_28 ( V_13 , V_75 , & V_96 ) ;
V_2 -> V_33 = F_29 ( V_75 , L_11 ) ;
if ( F_23 ( V_2 -> V_67 ) ) {
F_2 ( V_13 , L_12 ) ;
V_82 = F_24 ( V_2 -> V_67 ) ;
goto V_93;
}
F_30 ( V_2 -> V_67 , V_2 ) ;
V_83 ++ ;
}
V_81 = F_31 ( V_13 , V_97 ) ;
if ( F_23 ( V_81 ) ) {
F_2 ( V_13 , L_13 ) ;
return F_24 ( V_81 ) ;
}
F_10 ( V_13 , L_14 , V_83 ) ;
return 0 ;
V_93:
F_32 ( V_75 ) ;
return V_82 ;
}
