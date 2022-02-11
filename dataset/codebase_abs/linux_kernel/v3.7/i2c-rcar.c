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
struct V_43 * V_44 = F_12 ( NULL , L_1 ) ;
T_1 V_45 , V_46 ;
T_1 V_47 , V_48 ;
T_1 V_49 ;
if ( ! V_44 ) {
F_13 ( V_42 , L_2 ) ;
return - V_50 ;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_48 = F_14 ( V_44 ) / ( 1 + V_46 ) ;
if ( V_48 < 20000000 )
goto V_51;
}
F_13 ( V_42 , L_3 ) ;
return - V_50 ;
V_51:
V_47 = ( V_48 + 500000 ) / 1000000 * 285 ;
V_47 = ( V_47 + 500 ) / 1000 ;
for ( V_45 = 0 ; V_45 < 0x40 ; V_45 ++ ) {
V_49 = V_48 / ( 20 + ( V_45 * 8 ) + V_47 ) ;
if ( V_49 <= V_40 )
goto V_52;
}
F_13 ( V_42 , L_4 ) ;
return - V_50 ;
V_52:
F_15 ( V_42 , L_5 ,
V_49 , V_40 , F_14 ( V_44 ) , V_47 , V_46 , V_45 ) ;
V_2 -> V_53 = ( V_45 << 2 | V_46 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_54 , V_2 -> V_53 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_12 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_55 )
{
F_1 ( V_2 , V_12 , ~ V_55 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 1 ) ;
F_20 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_8 ( V_2 ) ;
if ( V_56 < 0 )
return V_56 ;
F_7 ( V_2 , 0 ) ;
F_20 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_57 )
{
struct V_58 * V_26 = V_2 -> V_26 ;
if ( ! ( V_57 & V_59 ) )
return 0 ;
if ( V_57 & V_60 )
F_10 ( V_2 , V_37 ) ;
if ( V_2 -> V_61 < V_26 -> V_62 ) {
F_1 ( V_2 , V_63 , V_26 -> V_64 [ V_2 -> V_61 ] ) ;
V_2 -> V_61 ++ ;
} else {
if ( V_2 -> V_65 & V_66 )
F_10 ( V_2 , V_38 ) ;
else
return V_67 ;
}
F_23 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_57 )
{
struct V_58 * V_26 = V_2 -> V_26 ;
if ( ! ( V_57 & V_68 ) )
return 0 ;
if ( V_57 & V_60 ) {
} else if ( V_2 -> V_61 < V_26 -> V_62 ) {
V_26 -> V_64 [ V_2 -> V_61 ] = F_3 ( V_2 , V_63 ) ;
V_2 -> V_61 ++ ;
}
if ( V_2 -> V_61 + 1 >= V_26 -> V_62 )
F_10 ( V_2 , V_38 ) ;
else
F_10 ( V_2 , V_37 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static T_2 F_26 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
struct V_41 * V_42 = F_27 ( V_2 ) ;
T_1 V_57 ;
F_28 ( & V_2 -> V_71 ) ;
V_57 = F_17 ( V_2 ) ;
if ( V_57 & V_72 ) {
F_15 ( V_42 , L_6 ) ;
F_29 ( V_2 , ( V_67 | V_73 ) ) ;
goto V_74;
}
if ( V_57 & V_75 ) {
F_15 ( V_42 , L_7 ) ;
F_29 ( V_2 , V_67 ) ;
goto V_74;
}
if ( V_57 & V_76 ) {
F_15 ( V_42 , L_8 ) ;
F_10 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_23 ) ;
F_29 ( V_2 , V_77 ) ;
goto V_74;
}
if ( F_30 ( V_2 ) )
F_29 ( V_2 , F_24 ( V_2 , V_57 ) ) ;
else
F_29 ( V_2 , F_22 ( V_2 , V_57 ) ) ;
V_74:
if ( F_31 ( V_2 , V_67 ) ) {
F_6 ( V_2 , V_24 ) ;
F_20 ( V_2 ) ;
F_32 ( & V_2 -> V_78 ) ;
}
F_33 ( & V_2 -> V_71 ) ;
return V_79 ;
}
static int F_34 ( struct V_80 * V_81 ,
struct V_58 * V_82 ,
int V_83 )
{
struct V_1 * V_2 = F_35 ( V_81 ) ;
struct V_41 * V_42 = F_27 ( V_2 ) ;
unsigned long V_65 ;
int V_28 , V_56 , V_84 ;
F_36 ( V_42 ) ;
F_37 ( & V_2 -> V_71 , V_65 ) ;
F_5 ( V_2 ) ;
F_16 ( V_2 ) ;
F_38 ( & V_2 -> V_71 , V_65 ) ;
V_56 = - V_85 ;
for ( V_28 = 0 ; V_28 < V_83 ; V_28 ++ ) {
F_37 ( & V_2 -> V_71 , V_65 ) ;
V_2 -> V_26 = & V_82 [ V_28 ] ;
V_2 -> V_61 = 0 ;
V_2 -> V_65 = 0 ;
if ( V_2 -> V_26 == & V_82 [ V_83 - 1 ] )
F_29 ( V_2 , V_66 ) ;
if ( F_30 ( V_2 ) )
V_56 = F_19 ( V_2 ) ;
else
V_56 = F_21 ( V_2 ) ;
F_38 ( & V_2 -> V_71 , V_65 ) ;
if ( V_56 < 0 )
break;
V_84 = F_39 ( V_2 -> V_78 ,
F_31 ( V_2 , V_67 ) ,
5 * V_86 ) ;
if ( ! V_84 ) {
V_56 = - V_87 ;
break;
}
if ( F_31 ( V_2 , V_77 ) ) {
V_56 = - V_88 ;
break;
}
if ( F_31 ( V_2 , V_73 ) ) {
V_56 = - V_89 ;
break;
}
if ( F_31 ( V_2 , V_90 ) ) {
V_56 = - V_50 ;
break;
}
V_56 = V_28 + 1 ;
}
F_40 ( V_42 ) ;
if ( V_56 < 0 )
F_13 ( V_42 , L_9 , V_56 , V_2 -> V_65 ) ;
return V_56 ;
}
static T_1 F_41 ( struct V_80 * V_81 )
{
return V_91 | V_92 ;
}
static int T_3 F_42 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_42 . V_97 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
struct V_98 * V_99 ;
struct V_41 * V_42 = & V_94 -> V_42 ;
T_1 V_40 ;
int V_56 ;
V_99 = F_43 ( V_94 , V_100 , 0 ) ;
if ( ! V_99 ) {
F_13 ( V_42 , L_10 ) ;
return - V_101 ;
}
V_2 = F_44 ( V_42 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 ) {
F_13 ( V_42 , L_11 ) ;
return - V_103 ;
}
V_40 = 100000 ;
if ( V_96 && V_96 -> V_40 )
V_40 = V_96 -> V_40 ;
V_56 = F_11 ( V_2 , V_40 , V_42 ) ;
if ( V_56 < 0 )
return V_56 ;
V_2 -> V_5 = F_45 ( V_42 , V_99 -> V_104 , F_46 ( V_99 ) ) ;
if ( ! V_2 -> V_5 ) {
F_13 ( V_42 , L_12 ) ;
return - V_101 ;
}
V_2 -> V_69 = F_47 ( V_94 , 0 ) ;
F_48 ( & V_2 -> V_78 ) ;
F_49 ( & V_2 -> V_71 ) ;
V_81 = & V_2 -> V_81 ;
V_81 -> V_105 = V_94 -> V_106 ;
V_81 -> V_107 = & V_108 ;
V_81 -> V_109 = V_110 | V_111 ;
V_81 -> V_112 = 3 ;
V_81 -> V_42 . V_113 = V_42 ;
F_50 ( V_81 , V_2 ) ;
F_51 ( V_81 -> V_114 , V_94 -> V_114 , sizeof( V_81 -> V_114 ) ) ;
V_56 = F_52 ( V_42 , V_2 -> V_69 , F_26 , 0 ,
F_53 ( V_42 ) , V_2 ) ;
if ( V_56 < 0 ) {
F_13 ( V_42 , L_13 , V_2 -> V_69 ) ;
return V_56 ;
}
V_56 = F_54 ( V_81 ) ;
if ( V_56 < 0 ) {
F_13 ( V_42 , L_14 , V_56 ) ;
return V_56 ;
}
F_55 ( V_42 ) ;
F_56 ( V_94 , V_2 ) ;
F_57 ( V_42 , L_15 ) ;
return 0 ;
}
static int T_4 F_58 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_59 ( V_94 ) ;
struct V_41 * V_42 = & V_94 -> V_42 ;
F_60 ( & V_2 -> V_81 ) ;
F_61 ( V_42 ) ;
return 0 ;
}
