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
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! ( F_3 ( V_2 , V_7 ) & V_12 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_14 ,
struct V_15 * V_16 )
{
T_1 V_17 , V_18 ;
T_1 V_19 , V_20 ;
T_1 V_21 ;
T_1 V_22 ;
unsigned long V_23 ;
switch ( V_2 -> V_24 ) {
case V_25 :
V_22 = 2 ;
break;
case V_26 :
V_22 = 3 ;
break;
default:
F_9 ( V_16 , L_1 ) ;
return - V_27 ;
}
V_23 = F_10 ( V_2 -> V_28 ) ;
V_18 = V_23 / 20000000 ;
if ( V_18 >= 1U << V_22 ) {
F_9 ( V_16 , L_2 , V_23 ) ;
return - V_27 ;
}
V_20 = V_23 / ( V_18 + 1 ) ;
V_19 = ( V_20 + 500000 ) / 1000000 * 285 ;
V_19 = ( V_19 + 500 ) / 1000 ;
for ( V_17 = 0 ; V_17 < 0x40 ; V_17 ++ ) {
V_21 = V_20 / ( 20 + ( V_17 * 8 ) + V_19 ) ;
if ( V_21 <= V_14 )
goto V_29;
}
F_9 ( V_16 , L_3 ) ;
return - V_27 ;
V_29:
F_11 ( V_16 , L_4 ,
V_21 , V_14 , F_10 ( V_2 -> V_28 ) , V_19 , V_18 , V_17 ) ;
V_2 -> V_30 = V_17 << V_22 | V_18 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_31 = ! ! F_13 ( V_2 ) ;
F_1 ( V_2 , V_9 , ( V_2 -> V_32 -> V_33 << 1 ) | V_31 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_7 , V_34 ) ;
F_1 ( V_2 , V_6 , V_31 ? V_35 : V_36 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_38 * V_32 = V_2 -> V_32 ;
if ( ! ( V_37 & V_39 ) )
return 0 ;
if ( V_37 & V_40 )
F_1 ( V_2 , V_7 , V_41 ) ;
if ( V_2 -> V_42 < V_32 -> V_43 ) {
F_1 ( V_2 , V_44 , V_32 -> V_45 [ V_2 -> V_42 ] ) ;
V_2 -> V_42 ++ ;
} else {
if ( V_2 -> V_46 & V_47 )
F_1 ( V_2 , V_7 , V_48 ) ;
else
return V_49 ;
}
F_1 ( V_2 , V_8 , V_50 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_38 * V_32 = V_2 -> V_32 ;
if ( ! ( V_37 & V_51 ) )
return 0 ;
if ( V_37 & V_40 ) {
} else if ( V_2 -> V_42 < V_32 -> V_43 ) {
V_32 -> V_45 [ V_2 -> V_42 ] = F_3 ( V_2 , V_44 ) ;
V_2 -> V_42 ++ ;
}
if ( V_2 -> V_42 + 1 >= V_32 -> V_43 )
F_1 ( V_2 , V_7 , V_48 ) ;
else
F_1 ( V_2 , V_7 , V_41 ) ;
F_1 ( V_2 , V_8 , V_52 ) ;
return 0 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
T_1 V_53 , V_54 ;
T_2 V_55 ;
V_53 = F_3 ( V_2 , V_56 ) & 0xff ;
V_54 = V_53 & F_3 ( V_2 , V_57 ) ;
if ( ! V_54 )
return false ;
if ( V_54 & V_58 ) {
if ( V_53 & V_59 ) {
F_17 ( V_2 -> V_60 , V_61 , & V_55 ) ;
F_1 ( V_2 , V_44 , V_55 ) ;
F_1 ( V_2 , V_57 , V_62 | V_63 | V_58 ) ;
} else {
F_17 ( V_2 -> V_60 , V_64 , & V_55 ) ;
F_3 ( V_2 , V_44 ) ;
F_1 ( V_2 , V_57 , V_65 | V_63 | V_58 ) ;
}
F_1 ( V_2 , V_56 , ~ V_58 & 0xff ) ;
}
if ( V_54 & V_63 ) {
F_17 ( V_2 -> V_60 , V_66 , & V_55 ) ;
F_1 ( V_2 , V_57 , V_58 | V_63 ) ;
F_1 ( V_2 , V_56 , ~ V_63 & 0xff ) ;
}
if ( V_54 & V_65 ) {
int V_67 ;
V_55 = F_3 ( V_2 , V_44 ) ;
V_67 = F_17 ( V_2 -> V_60 , V_68 , & V_55 ) ;
F_1 ( V_2 , V_69 , V_70 | V_71 | ( V_67 < 0 ? V_72 : 0 ) ) ;
F_1 ( V_2 , V_56 , ~ V_65 & 0xff ) ;
}
if ( V_54 & V_62 ) {
F_17 ( V_2 -> V_60 , V_73 , & V_55 ) ;
F_1 ( V_2 , V_44 , V_55 ) ;
F_1 ( V_2 , V_56 , ~ V_62 & 0xff ) ;
}
return true ;
}
static T_3 F_18 ( int V_74 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
T_3 V_76 = V_77 ;
T_1 V_37 ;
F_19 ( & V_2 -> V_78 ) ;
if ( F_16 ( V_2 ) )
goto exit;
V_37 = F_3 ( V_2 , V_8 ) ;
V_37 &= F_3 ( V_2 , V_6 ) ;
if ( ! V_37 ) {
V_76 = V_79 ;
goto exit;
}
if ( V_37 & V_80 ) {
F_20 ( V_2 , ( V_49 | V_81 ) ) ;
goto V_82;
}
if ( V_37 & V_83 ) {
F_1 ( V_2 , V_7 , V_48 ) ;
F_1 ( V_2 , V_6 , V_84 ) ;
F_20 ( V_2 , V_85 ) ;
goto V_82;
}
if ( V_37 & V_86 ) {
F_20 ( V_2 , V_49 ) ;
goto V_82;
}
if ( F_13 ( V_2 ) )
F_20 ( V_2 , F_15 ( V_2 , V_37 ) ) ;
else
F_20 ( V_2 , F_14 ( V_2 , V_37 ) ) ;
V_82:
if ( F_21 ( V_2 , V_49 ) ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_22 ( & V_2 -> V_87 ) ;
}
exit:
F_23 ( & V_2 -> V_78 ) ;
return V_76 ;
}
static int F_24 ( struct V_88 * V_89 ,
struct V_38 * V_90 ,
int V_91 )
{
struct V_1 * V_2 = F_25 ( V_89 ) ;
struct V_15 * V_16 = F_26 ( V_2 ) ;
unsigned long V_46 ;
int V_10 , V_67 ;
long V_92 ;
F_27 ( V_16 ) ;
F_28 ( & V_2 -> V_78 , V_46 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 , V_93 , V_2 -> V_30 ) ;
F_29 ( & V_2 -> V_78 , V_46 ) ;
V_67 = F_6 ( V_2 ) ;
if ( V_67 < 0 )
goto V_82;
for ( V_10 = 0 ; V_10 < V_91 ; V_10 ++ ) {
if ( V_90 [ V_10 ] . V_43 == 0 ) {
V_67 = - V_94 ;
break;
}
F_28 ( & V_2 -> V_78 , V_46 ) ;
V_2 -> V_32 = & V_90 [ V_10 ] ;
V_2 -> V_42 = 0 ;
V_2 -> V_46 = 0 ;
if ( V_10 == V_91 - 1 )
F_20 ( V_2 , V_47 ) ;
F_12 ( V_2 ) ;
F_29 ( & V_2 -> V_78 , V_46 ) ;
V_92 = F_30 ( V_2 -> V_87 ,
F_21 ( V_2 , V_49 ) ,
V_89 -> V_92 ) ;
if ( ! V_92 ) {
V_67 = - V_95 ;
break;
}
if ( F_21 ( V_2 , V_85 ) ) {
V_67 = - V_96 ;
break;
}
if ( F_21 ( V_2 , V_81 ) ) {
V_67 = - V_97 ;
break;
}
if ( F_21 ( V_2 , V_98 ) ) {
V_67 = - V_27 ;
break;
}
V_67 = V_10 + 1 ;
}
V_82:
F_31 ( V_16 ) ;
if ( V_67 < 0 && V_67 != - V_96 )
F_9 ( V_16 , L_5 , V_67 , V_2 -> V_46 ) ;
return V_67 ;
}
static int F_32 ( struct V_99 * V_60 )
{
struct V_1 * V_2 = F_25 ( V_60 -> V_100 ) ;
if ( V_2 -> V_60 )
return - V_13 ;
if ( V_60 -> V_46 & V_101 )
return - V_102 ;
F_33 ( F_26 ( V_2 ) ) ;
V_2 -> V_60 = V_60 ;
F_1 ( V_2 , V_103 , V_60 -> V_33 ) ;
F_1 ( V_2 , V_56 , 0 ) ;
F_1 ( V_2 , V_57 , V_58 | V_63 ) ;
F_1 ( V_2 , V_69 , V_70 | V_71 ) ;
return 0 ;
}
static int F_34 ( struct V_99 * V_60 )
{
struct V_1 * V_2 = F_25 ( V_60 -> V_100 ) ;
F_35 ( ! V_2 -> V_60 ) ;
F_1 ( V_2 , V_57 , 0 ) ;
F_1 ( V_2 , V_69 , 0 ) ;
V_2 -> V_60 = NULL ;
F_36 ( F_26 ( V_2 ) ) ;
return 0 ;
}
static T_1 F_37 ( struct V_88 * V_89 )
{
return V_104 | V_105 |
( V_106 & ~ V_107 ) ;
}
static int F_38 ( struct V_108 * V_109 )
{
struct V_110 * V_111 = F_39 ( & V_109 -> V_16 ) ;
struct V_1 * V_2 ;
struct V_88 * V_89 ;
struct V_112 * V_113 ;
struct V_15 * V_16 = & V_109 -> V_16 ;
T_1 V_14 ;
int V_74 , V_67 ;
V_2 = F_40 ( V_16 , sizeof( struct V_1 ) , V_114 ) ;
if ( ! V_2 )
return - V_115 ;
V_2 -> V_28 = F_41 ( V_16 , NULL ) ;
if ( F_42 ( V_2 -> V_28 ) ) {
F_9 ( V_16 , L_6 ) ;
return F_43 ( V_2 -> V_28 ) ;
}
V_14 = 100000 ;
V_67 = F_44 ( V_16 -> V_116 , L_7 , & V_14 ) ;
if ( V_67 < 0 && V_111 && V_111 -> V_14 )
V_14 = V_111 -> V_14 ;
if ( V_109 -> V_16 . V_116 )
V_2 -> V_24 = ( long ) F_45 ( V_117 ,
V_16 ) -> V_118 ;
else
V_2 -> V_24 = F_46 ( V_109 ) -> V_119 ;
V_67 = F_8 ( V_2 , V_14 , V_16 ) ;
if ( V_67 < 0 )
return V_67 ;
V_113 = F_47 ( V_109 , V_120 , 0 ) ;
V_2 -> V_5 = F_48 ( V_16 , V_113 ) ;
if ( F_42 ( V_2 -> V_5 ) )
return F_43 ( V_2 -> V_5 ) ;
V_74 = F_49 ( V_109 , 0 ) ;
F_50 ( & V_2 -> V_87 ) ;
F_51 ( & V_2 -> V_78 ) ;
V_89 = & V_2 -> V_89 ;
V_89 -> V_121 = V_109 -> V_122 ;
V_89 -> V_123 = & V_124 ;
V_89 -> V_125 = V_126 ;
V_89 -> V_127 = 3 ;
V_89 -> V_16 . V_128 = V_16 ;
V_89 -> V_16 . V_116 = V_16 -> V_116 ;
F_52 ( V_89 , V_2 ) ;
F_53 ( V_89 -> V_129 , V_109 -> V_129 , sizeof( V_89 -> V_129 ) ) ;
V_67 = F_54 ( V_16 , V_74 , F_18 , 0 ,
F_55 ( V_16 ) , V_2 ) ;
if ( V_67 < 0 ) {
F_9 ( V_16 , L_8 , V_74 ) ;
return V_67 ;
}
V_67 = F_56 ( V_89 ) ;
if ( V_67 < 0 ) {
F_9 ( V_16 , L_9 , V_67 ) ;
return V_67 ;
}
F_57 ( V_16 ) ;
F_58 ( V_109 , V_2 ) ;
F_59 ( V_16 , L_10 ) ;
return 0 ;
}
static int F_60 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_61 ( V_109 ) ;
struct V_15 * V_16 = & V_109 -> V_16 ;
F_62 ( & V_2 -> V_89 ) ;
F_63 ( V_16 ) ;
return 0 ;
}
