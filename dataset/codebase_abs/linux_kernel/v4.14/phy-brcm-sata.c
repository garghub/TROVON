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
}
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
}
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
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_13 = V_2 -> V_5 -> V_13 ;
void T_1 * V_25 = V_4 -> V_14 ;
unsigned int V_67 ;
unsigned int V_39 , V_38 ;
if ( V_2 -> V_15 == 0 )
V_67 = V_45 ;
else if ( V_2 -> V_15 == 1 )
V_67 = V_68 ;
else
return - V_69 ;
V_39 = 0x0 ;
V_39 |= ( 0x0f << V_41 ) ;
V_39 |= ( 0x06 << V_42 ) ;
V_39 |= ( 0x0f << V_43 ) ;
V_39 |= ( 0x06 << V_44 ) ;
F_4 ( V_25 , V_67 , V_46 , 0x0 , V_39 ) ;
V_39 = 0x0 ;
V_39 |= ( 0x2e << V_47 ) ;
V_39 |= ( 0x02 << V_48 ) ;
V_39 |= ( 0x16 << V_49 ) ;
F_4 ( V_25 , V_67 , V_50 , 0x0 , V_39 ) ;
F_4 ( V_25 , V_70 , V_71 ,
~ ( V_72 << V_73 ) ,
0x0c << V_73 ) ;
F_4 ( V_25 , V_70 , V_74 ,
0xff0 , 0x4f0 ) ;
V_39 = V_75 | V_76 ;
F_4 ( V_25 , V_70 , V_77 ,
~ V_39 , V_39 ) ;
V_39 = V_78 ;
F_4 ( V_25 , V_70 , V_77 ,
~ V_39 , 0 ) ;
F_12 ( 10 ) ;
F_4 ( V_25 , V_70 , V_77 ,
~ V_39 , V_39 ) ;
V_38 = 50 ;
while ( -- V_38 ) {
V_39 = F_8 ( V_25 , V_58 ,
V_64 ) ;
if ( V_39 & V_65 )
break;
F_13 ( 20 ) ;
}
if ( ! V_38 ) {
F_2 ( V_13 , L_3 , V_2 -> V_15 ) ;
return - V_66 ;
}
F_14 ( V_13 , L_4 , V_2 -> V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_40 * V_13 = V_2 -> V_5 -> V_13 ;
void T_1 * V_25 = V_4 -> V_14 ;
unsigned int V_39 , V_38 ;
V_39 = V_79 ;
F_4 ( V_25 , V_52 , V_53 , 0x0 , V_39 ) ;
V_39 = V_80 ;
F_4 ( V_25 , V_52 , V_55 , 0x0 , V_39 ) ;
V_39 = V_81 ;
F_4 ( V_25 , V_52 , V_57 , 0x0 , V_39 ) ;
V_39 = V_82 ;
F_4 ( V_25 , V_70 , V_83 , 0x0 , V_39 ) ;
V_38 = 50 ;
do {
V_39 = F_8 ( V_25 , V_58 ,
V_64 ) ;
if ( V_39 & V_65 )
break;
F_13 ( 20 ) ;
V_38 -- ;
} while ( V_38 );
if ( ( V_39 & V_65 ) == 0 ) {
F_2 ( V_13 , L_3 , V_2 -> V_15 ) ;
return - V_66 ;
}
F_4 ( V_25 , V_84 , V_85 ,
~ V_86 , V_86 ) ;
V_39 = ( ( 0xc << V_41 ) |
( 0x4 << V_42 ) |
( 0x8 << V_43 ) |
( 0x3 << V_44 ) ) ;
F_4 ( V_25 , V_45 , V_46 , 0x0 , V_39 ) ;
V_39 = ( ( 0x1b << V_47 ) |
( 0x2 << V_48 ) |
( 0x9 << V_49 ) ) ;
F_4 ( V_25 , V_45 , V_50 , 0x0 , V_39 ) ;
return 0 ;
}
static int F_17 ( struct V_87 * V_87 )
{
int V_88 ;
struct V_1 * V_2 = F_18 ( V_87 ) ;
switch ( V_2 -> V_5 -> V_7 ) {
case V_8 :
case V_11 :
V_88 = F_9 ( V_2 ) ;
break;
case V_9 :
V_88 = F_11 ( V_2 ) ;
break;
case V_89 :
V_88 = F_15 ( V_2 ) ;
break;
case V_90 :
V_88 = F_16 ( V_2 ) ;
break;
default:
V_88 = - V_91 ;
}
return V_88 ;
}
static int F_19 ( struct V_92 * V_93 )
{
struct V_40 * V_13 = & V_93 -> V_13 ;
struct V_94 * V_95 = V_13 -> V_96 , * V_97 ;
const struct V_98 * V_99 ;
struct V_3 * V_4 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
int V_104 , V_105 = 0 ;
if ( F_20 ( V_95 ) == 0 )
return - V_91 ;
V_4 = F_21 ( V_13 , sizeof( * V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_107 ;
F_22 ( V_13 , V_4 ) ;
V_4 -> V_13 = V_13 ;
V_101 = F_23 ( V_93 , V_108 , L_5 ) ;
V_4 -> V_14 = F_24 ( V_13 , V_101 ) ;
if ( F_25 ( V_4 -> V_14 ) )
return F_26 ( V_4 -> V_14 ) ;
V_99 = F_27 ( V_109 , V_95 ) ;
if ( V_99 )
V_4 -> V_7 = (enum V_110 ) V_99 -> V_111 ;
else
V_4 -> V_7 = V_8 ;
if ( V_4 -> V_7 == V_9 ) {
V_101 = F_23 ( V_93 , V_108 ,
L_6 ) ;
V_4 -> V_17 = F_24 ( V_13 , V_101 ) ;
if ( F_25 ( V_4 -> V_17 ) )
return F_26 ( V_4 -> V_17 ) ;
}
F_28 (dn, child) {
unsigned int V_112 ;
struct V_1 * V_2 ;
if ( F_29 ( V_97 , L_7 , & V_112 ) ) {
F_2 ( V_13 , L_8 ,
V_97 -> V_113 ) ;
V_104 = - V_69 ;
goto V_114;
}
if ( V_112 >= V_115 ) {
F_2 ( V_13 , L_9 , V_112 ) ;
V_104 = - V_69 ;
goto V_114;
}
if ( V_4 -> V_116 [ V_112 ] . V_87 ) {
F_2 ( V_13 , L_10 , V_112 ) ;
V_104 = - V_69 ;
goto V_114;
}
V_2 = & V_4 -> V_116 [ V_112 ] ;
V_2 -> V_15 = V_112 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_87 = F_30 ( V_13 , V_97 , & V_117 ) ;
V_2 -> V_33 = F_31 ( V_97 , L_11 ) ;
if ( F_25 ( V_2 -> V_87 ) ) {
F_2 ( V_13 , L_12 ) ;
V_104 = F_26 ( V_2 -> V_87 ) ;
goto V_114;
}
F_32 ( V_2 -> V_87 , V_2 ) ;
V_105 ++ ;
}
V_103 = F_33 ( V_13 , V_118 ) ;
if ( F_25 ( V_103 ) ) {
F_2 ( V_13 , L_13 ) ;
return F_26 ( V_103 ) ;
}
F_10 ( V_13 , L_14 , V_105 ) ;
return 0 ;
V_114:
F_34 ( V_97 ) ;
return V_104 ;
}
