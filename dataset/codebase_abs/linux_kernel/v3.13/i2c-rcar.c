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
struct V_43 * V_44 = F_12 ( V_42 , NULL ) ;
T_1 V_45 , V_46 ;
T_1 V_47 , V_48 ;
T_1 V_49 ;
T_1 V_50 ;
unsigned long V_51 ;
if ( F_13 ( V_44 ) ) {
F_14 ( V_42 , L_1 ) ;
return F_15 ( V_44 ) ;
}
switch ( V_2 -> V_52 ) {
case V_53 :
V_50 = 2 ;
break;
case V_54 :
V_50 = 3 ;
break;
default:
F_14 ( V_42 , L_2 ) ;
return - V_55 ;
}
V_51 = F_16 ( V_44 ) ;
V_46 = V_51 / 20000000 ;
if ( V_46 >= 1 << V_50 ) {
F_14 ( V_42 , L_3 , V_51 ) ;
return - V_55 ;
}
V_48 = V_51 / ( V_46 + 1 ) ;
V_47 = ( V_48 + 500000 ) / 1000000 * 285 ;
V_47 = ( V_47 + 500 ) / 1000 ;
for ( V_45 = 0 ; V_45 < 0x40 ; V_45 ++ ) {
V_49 = V_48 / ( 20 + ( V_45 * 8 ) + V_47 ) ;
if ( V_49 <= V_40 )
goto V_56;
}
F_14 ( V_42 , L_4 ) ;
return - V_55 ;
V_56:
F_17 ( V_42 , L_5 ,
V_49 , V_40 , F_16 ( V_44 ) , V_47 , V_46 , V_45 ) ;
V_2 -> V_57 = V_45 << V_50 | V_46 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_58 , V_2 -> V_57 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_12 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_59 )
{
F_1 ( V_2 , V_12 , ~ V_59 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_60 ;
V_60 = F_8 ( V_2 ) ;
if ( V_60 < 0 )
return V_60 ;
F_7 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
F_10 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_62 * V_26 = V_2 -> V_26 ;
if ( ! ( V_61 & V_63 ) )
return 0 ;
if ( V_61 & V_64 )
F_10 ( V_2 , V_37 ) ;
if ( V_2 -> V_65 < V_26 -> V_66 ) {
F_1 ( V_2 , V_67 , V_26 -> V_68 [ V_2 -> V_65 ] ) ;
V_2 -> V_65 ++ ;
} else {
if ( V_2 -> V_69 & V_70 )
F_10 ( V_2 , V_38 ) ;
else
return V_71 ;
}
F_25 ( V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_61 )
{
struct V_62 * V_26 = V_2 -> V_26 ;
if ( ! ( V_61 & V_72 ) )
return 0 ;
if ( V_61 & V_64 ) {
} else if ( V_2 -> V_65 < V_26 -> V_66 ) {
V_26 -> V_68 [ V_2 -> V_65 ] = F_3 ( V_2 , V_67 ) ;
V_2 -> V_65 ++ ;
}
if ( V_2 -> V_65 + 1 >= V_26 -> V_66 )
F_10 ( V_2 , V_38 ) ;
else
F_10 ( V_2 , V_37 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static T_2 F_28 ( int V_73 , void * V_74 )
{
struct V_1 * V_2 = V_74 ;
struct V_41 * V_42 = F_29 ( V_2 ) ;
T_1 V_61 ;
F_30 ( & V_2 -> V_75 ) ;
V_61 = F_19 ( V_2 ) ;
if ( V_61 & V_76 ) {
F_17 ( V_42 , L_6 ) ;
F_31 ( V_2 , ( V_71 | V_77 ) ) ;
goto V_78;
}
if ( V_61 & V_79 ) {
F_17 ( V_42 , L_7 ) ;
F_31 ( V_2 , V_71 ) ;
goto V_78;
}
if ( V_61 & V_80 ) {
F_17 ( V_42 , L_8 ) ;
F_10 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_23 ) ;
F_31 ( V_2 , V_81 ) ;
goto V_78;
}
if ( F_32 ( V_2 ) )
F_31 ( V_2 , F_26 ( V_2 , V_61 ) ) ;
else
F_31 ( V_2 , F_24 ( V_2 , V_61 ) ) ;
V_78:
if ( F_33 ( V_2 , V_71 ) ) {
F_6 ( V_2 , V_24 ) ;
F_22 ( V_2 ) ;
F_34 ( & V_2 -> V_82 ) ;
}
F_35 ( & V_2 -> V_75 ) ;
return V_83 ;
}
static int F_36 ( struct V_84 * V_85 ,
struct V_62 * V_86 ,
int V_87 )
{
struct V_1 * V_2 = F_37 ( V_85 ) ;
struct V_41 * V_42 = F_29 ( V_2 ) ;
unsigned long V_69 ;
int V_28 , V_60 , V_88 ;
F_38 ( V_42 ) ;
F_39 ( & V_2 -> V_75 , V_69 ) ;
F_5 ( V_2 ) ;
F_18 ( V_2 ) ;
F_40 ( & V_2 -> V_75 , V_69 ) ;
V_60 = - V_89 ;
for ( V_28 = 0 ; V_28 < V_87 ; V_28 ++ ) {
F_39 ( & V_2 -> V_75 , V_69 ) ;
V_2 -> V_26 = & V_86 [ V_28 ] ;
V_2 -> V_65 = 0 ;
V_2 -> V_69 = 0 ;
if ( V_2 -> V_26 == & V_86 [ V_87 - 1 ] )
F_31 ( V_2 , V_70 ) ;
if ( F_32 ( V_2 ) )
V_60 = F_21 ( V_2 ) ;
else
V_60 = F_23 ( V_2 ) ;
F_40 ( & V_2 -> V_75 , V_69 ) ;
if ( V_60 < 0 )
break;
V_88 = F_41 ( V_2 -> V_82 ,
F_33 ( V_2 , V_71 ) ,
5 * V_90 ) ;
if ( ! V_88 ) {
V_60 = - V_91 ;
break;
}
if ( F_33 ( V_2 , V_81 ) ) {
V_60 = - V_92 ;
break;
}
if ( F_33 ( V_2 , V_77 ) ) {
V_60 = - V_93 ;
break;
}
if ( F_33 ( V_2 , V_94 ) ) {
V_60 = - V_55 ;
break;
}
V_60 = V_28 + 1 ;
}
F_42 ( V_42 ) ;
if ( V_60 < 0 )
F_14 ( V_42 , L_9 , V_60 , V_2 -> V_69 ) ;
return V_60 ;
}
static T_1 F_43 ( struct V_84 * V_85 )
{
return V_95 | V_96 ;
}
static int F_44 ( struct V_97 * V_98 )
{
struct V_99 * V_100 = F_45 ( & V_98 -> V_42 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_101 * V_102 ;
struct V_41 * V_42 = & V_98 -> V_42 ;
T_1 V_40 ;
int V_60 ;
V_2 = F_46 ( V_42 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 ) {
F_14 ( V_42 , L_10 ) ;
return - V_104 ;
}
V_40 = 100000 ;
V_60 = F_47 ( V_42 -> V_105 , L_11 , & V_40 ) ;
if ( V_60 < 0 && V_100 && V_100 -> V_40 )
V_40 = V_100 -> V_40 ;
if ( V_98 -> V_42 . V_105 )
V_2 -> V_52 = ( long ) F_48 ( V_106 ,
V_42 ) -> V_107 ;
else
V_2 -> V_52 = F_49 ( V_98 ) -> V_108 ;
V_60 = F_11 ( V_2 , V_40 , V_42 ) ;
if ( V_60 < 0 )
return V_60 ;
V_102 = F_50 ( V_98 , V_109 , 0 ) ;
V_2 -> V_5 = F_51 ( V_42 , V_102 ) ;
if ( F_13 ( V_2 -> V_5 ) )
return F_15 ( V_2 -> V_5 ) ;
V_2 -> V_73 = F_52 ( V_98 , 0 ) ;
F_53 ( & V_2 -> V_82 ) ;
F_54 ( & V_2 -> V_75 ) ;
V_85 = & V_2 -> V_85 ;
V_85 -> V_110 = V_98 -> V_111 ;
V_85 -> V_112 = & V_113 ;
V_85 -> V_114 = V_115 | V_116 ;
V_85 -> V_117 = 3 ;
V_85 -> V_42 . V_118 = V_42 ;
V_85 -> V_42 . V_105 = V_42 -> V_105 ;
F_55 ( V_85 , V_2 ) ;
F_56 ( V_85 -> V_119 , V_98 -> V_119 , sizeof( V_85 -> V_119 ) ) ;
V_60 = F_57 ( V_42 , V_2 -> V_73 , F_28 , 0 ,
F_58 ( V_42 ) , V_2 ) ;
if ( V_60 < 0 ) {
F_14 ( V_42 , L_12 , V_2 -> V_73 ) ;
return V_60 ;
}
V_60 = F_59 ( V_85 ) ;
if ( V_60 < 0 ) {
F_14 ( V_42 , L_13 , V_60 ) ;
return V_60 ;
}
F_60 ( V_42 ) ;
F_61 ( V_98 , V_2 ) ;
F_62 ( V_42 , L_14 ) ;
return 0 ;
}
static int F_63 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_64 ( V_98 ) ;
struct V_41 * V_42 = & V_98 -> V_42 ;
F_65 ( & V_2 -> V_85 ) ;
F_66 ( V_42 ) ;
return 0 ;
}
