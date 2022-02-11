static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_7 , 0 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_10 , 0 ) ;
F_1 ( V_2 , V_11 , 0 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_1 ( V_2 , V_13 , 0 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_14 )
{
T_1 V_4 = V_15 | V_16 | V_17 | V_18 ;
switch ( V_14 ) {
case V_19 :
V_4 |= V_20 ;
break;
case V_21 :
V_4 |= V_22 ;
break;
case V_23 :
V_4 = V_17 ;
break;
case V_24 :
default:
V_4 = 0 ;
break;
}
F_1 ( V_2 , V_10 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_25 )
{
F_1 ( V_2 , V_13 , ( V_2 -> V_26 -> V_27 << 1 ) | V_25 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( ! ( F_3 ( V_2 , V_11 ) & V_30 ) )
return 0 ;
F_9 ( 1 ) ;
}
return - V_31 ;
}
static void F_10 ( struct V_1 * V_2 , int V_32 )
{
switch ( V_32 ) {
case V_33 :
F_1 ( V_2 , V_11 , V_34 | V_35 | V_36 ) ;
break;
case V_37 :
F_1 ( V_2 , V_11 , V_34 | V_35 ) ;
break;
case V_38 :
F_1 ( V_2 , V_11 , V_34 | V_35 | V_39 ) ;
break;
}
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_40 ,
struct V_41 * V_42 )
{
T_1 V_43 , V_44 ;
T_1 V_45 , V_46 ;
T_1 V_47 ;
T_1 V_48 ;
unsigned long V_49 ;
switch ( V_2 -> V_50 ) {
case V_51 :
V_48 = 2 ;
break;
case V_52 :
V_48 = 3 ;
break;
default:
F_12 ( V_42 , L_1 ) ;
return - V_53 ;
}
V_49 = F_13 ( V_2 -> V_54 ) ;
V_44 = V_49 / 20000000 ;
if ( V_44 >= 1 << V_48 ) {
F_12 ( V_42 , L_2 , V_49 ) ;
return - V_53 ;
}
V_46 = V_49 / ( V_44 + 1 ) ;
V_45 = ( V_46 + 500000 ) / 1000000 * 285 ;
V_45 = ( V_45 + 500 ) / 1000 ;
for ( V_43 = 0 ; V_43 < 0x40 ; V_43 ++ ) {
V_47 = V_46 / ( 20 + ( V_43 * 8 ) + V_45 ) ;
if ( V_47 <= V_40 )
goto V_55;
}
F_12 ( V_42 , L_3 ) ;
return - V_53 ;
V_55:
F_14 ( V_42 , L_4 ,
V_47 , V_40 , F_13 ( V_2 -> V_54 ) , V_45 , V_44 , V_43 ) ;
V_2 -> V_56 = V_43 << V_48 | V_44 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_57 , V_2 -> V_56 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_12 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_58 )
{
F_1 ( V_2 , V_12 , ~ V_58 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 1 ) ;
F_19 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_59 ;
V_59 = F_8 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
F_7 ( V_2 , 0 ) ;
F_19 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_61 * V_26 = V_2 -> V_26 ;
if ( ! ( V_60 & V_62 ) )
return 0 ;
if ( V_60 & V_63 )
F_10 ( V_2 , V_37 ) ;
if ( V_2 -> V_64 < V_26 -> V_65 ) {
F_1 ( V_2 , V_66 , V_26 -> V_67 [ V_2 -> V_64 ] ) ;
V_2 -> V_64 ++ ;
} else {
if ( V_2 -> V_68 & V_69 )
F_10 ( V_2 , V_38 ) ;
else
return V_70 ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_61 * V_26 = V_2 -> V_26 ;
if ( ! ( V_60 & V_71 ) )
return 0 ;
if ( V_60 & V_63 ) {
} else if ( V_2 -> V_64 < V_26 -> V_65 ) {
V_26 -> V_67 [ V_2 -> V_64 ] = F_3 ( V_2 , V_66 ) ;
V_2 -> V_64 ++ ;
}
if ( V_2 -> V_64 + 1 >= V_26 -> V_65 )
F_10 ( V_2 , V_38 ) ;
else
F_10 ( V_2 , V_37 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static T_2 F_25 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
struct V_41 * V_42 = F_26 ( V_2 ) ;
T_1 V_60 ;
F_27 ( & V_2 -> V_74 ) ;
V_60 = F_16 ( V_2 ) ;
if ( V_60 & V_75 ) {
F_14 ( V_42 , L_5 ) ;
F_28 ( V_2 , ( V_70 | V_76 ) ) ;
goto V_77;
}
if ( V_60 & V_78 ) {
F_14 ( V_42 , L_6 ) ;
F_28 ( V_2 , V_70 ) ;
goto V_77;
}
if ( V_60 & V_79 ) {
F_14 ( V_42 , L_7 ) ;
F_10 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_23 ) ;
F_28 ( V_2 , V_80 ) ;
goto V_77;
}
if ( F_29 ( V_2 ) )
F_28 ( V_2 , F_23 ( V_2 , V_60 ) ) ;
else
F_28 ( V_2 , F_21 ( V_2 , V_60 ) ) ;
V_77:
if ( F_30 ( V_2 , V_70 ) ) {
F_6 ( V_2 , V_24 ) ;
F_19 ( V_2 ) ;
F_31 ( & V_2 -> V_81 ) ;
}
F_32 ( & V_2 -> V_74 ) ;
return V_82 ;
}
static int F_33 ( struct V_83 * V_84 ,
struct V_61 * V_85 ,
int V_86 )
{
struct V_1 * V_2 = F_34 ( V_84 ) ;
struct V_41 * V_42 = F_26 ( V_2 ) ;
unsigned long V_68 ;
int V_28 , V_59 , V_87 ;
F_35 ( V_42 ) ;
F_36 ( & V_2 -> V_74 , V_68 ) ;
F_5 ( V_2 ) ;
F_15 ( V_2 ) ;
F_37 ( & V_2 -> V_74 , V_68 ) ;
V_59 = - V_88 ;
for ( V_28 = 0 ; V_28 < V_86 ; V_28 ++ ) {
F_36 ( & V_2 -> V_74 , V_68 ) ;
V_2 -> V_26 = & V_85 [ V_28 ] ;
V_2 -> V_64 = 0 ;
V_2 -> V_68 = 0 ;
if ( V_2 -> V_26 == & V_85 [ V_86 - 1 ] )
F_28 ( V_2 , V_69 ) ;
if ( F_29 ( V_2 ) )
V_59 = F_18 ( V_2 ) ;
else
V_59 = F_20 ( V_2 ) ;
F_37 ( & V_2 -> V_74 , V_68 ) ;
if ( V_59 < 0 )
break;
V_87 = F_38 ( V_2 -> V_81 ,
F_30 ( V_2 , V_70 ) ,
5 * V_89 ) ;
if ( ! V_87 ) {
V_59 = - V_90 ;
break;
}
if ( F_30 ( V_2 , V_80 ) ) {
V_59 = - V_91 ;
break;
}
if ( F_30 ( V_2 , V_76 ) ) {
V_59 = - V_92 ;
break;
}
if ( F_30 ( V_2 , V_93 ) ) {
V_59 = - V_53 ;
break;
}
V_59 = V_28 + 1 ;
}
F_39 ( V_42 ) ;
if ( V_59 < 0 && V_59 != - V_91 )
F_12 ( V_42 , L_8 , V_59 , V_2 -> V_68 ) ;
return V_59 ;
}
static T_1 F_40 ( struct V_83 * V_84 )
{
return V_94 | V_95 ;
}
static int F_41 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = F_42 ( & V_97 -> V_42 ) ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
struct V_100 * V_101 ;
struct V_41 * V_42 = & V_97 -> V_42 ;
T_1 V_40 ;
int V_59 ;
V_2 = F_43 ( V_42 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 ) {
F_12 ( V_42 , L_9 ) ;
return - V_103 ;
}
V_2 -> V_54 = F_44 ( V_42 , NULL ) ;
if ( F_45 ( V_2 -> V_54 ) ) {
F_12 ( V_42 , L_10 ) ;
return F_46 ( V_2 -> V_54 ) ;
}
V_40 = 100000 ;
V_59 = F_47 ( V_42 -> V_104 , L_11 , & V_40 ) ;
if ( V_59 < 0 && V_99 && V_99 -> V_40 )
V_40 = V_99 -> V_40 ;
if ( V_97 -> V_42 . V_104 )
V_2 -> V_50 = ( long ) F_48 ( V_105 ,
V_42 ) -> V_106 ;
else
V_2 -> V_50 = F_49 ( V_97 ) -> V_107 ;
V_59 = F_11 ( V_2 , V_40 , V_42 ) ;
if ( V_59 < 0 )
return V_59 ;
V_101 = F_50 ( V_97 , V_108 , 0 ) ;
V_2 -> V_5 = F_51 ( V_42 , V_101 ) ;
if ( F_45 ( V_2 -> V_5 ) )
return F_46 ( V_2 -> V_5 ) ;
V_2 -> V_72 = F_52 ( V_97 , 0 ) ;
F_53 ( & V_2 -> V_81 ) ;
F_54 ( & V_2 -> V_74 ) ;
V_84 = & V_2 -> V_84 ;
V_84 -> V_109 = V_97 -> V_110 ;
V_84 -> V_111 = & V_112 ;
V_84 -> V_113 = V_114 | V_115 ;
V_84 -> V_116 = 3 ;
V_84 -> V_42 . V_117 = V_42 ;
V_84 -> V_42 . V_104 = V_42 -> V_104 ;
F_55 ( V_84 , V_2 ) ;
F_56 ( V_84 -> V_118 , V_97 -> V_118 , sizeof( V_84 -> V_118 ) ) ;
V_59 = F_57 ( V_42 , V_2 -> V_72 , F_25 , 0 ,
F_58 ( V_42 ) , V_2 ) ;
if ( V_59 < 0 ) {
F_12 ( V_42 , L_12 , V_2 -> V_72 ) ;
return V_59 ;
}
V_59 = F_59 ( V_84 ) ;
if ( V_59 < 0 ) {
F_12 ( V_42 , L_13 , V_59 ) ;
return V_59 ;
}
F_60 ( V_42 ) ;
F_61 ( V_97 , V_2 ) ;
F_62 ( V_42 , L_14 ) ;
return 0 ;
}
static int F_63 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_64 ( V_97 ) ;
struct V_41 * V_42 = & V_97 -> V_42 ;
F_65 ( & V_2 -> V_84 ) ;
F_66 ( V_42 ) ;
return 0 ;
}
