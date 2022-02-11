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
F_1 ( V_2 , V_7 , V_8 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
if ( ! ( F_3 ( V_2 , V_7 ) & V_14 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_15 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 V_18 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 ;
unsigned long V_25 ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
V_17 -> V_28 = V_17 -> V_28 ? : 100000 ;
V_17 -> V_29 = V_17 -> V_29 ? : 35 ;
V_17 -> V_30 = V_17 -> V_30 ? : 200 ;
V_17 -> V_31 = V_17 -> V_31 ? : 50 ;
switch ( V_2 -> V_32 ) {
case V_33 :
V_24 = 2 ;
break;
case V_34 :
case V_35 :
V_24 = 3 ;
break;
default:
F_10 ( V_27 , L_1 ) ;
return - V_36 ;
}
V_25 = F_11 ( V_2 -> V_37 ) ;
V_19 = V_25 / 20000000 ;
if ( V_19 >= 1U << V_24 ) {
F_10 ( V_27 , L_2 , V_25 ) ;
return - V_36 ;
}
V_21 = V_25 / ( V_19 + 1 ) ;
V_22 = V_17 -> V_29 + V_17 -> V_30 + V_17 -> V_31 ;
V_20 = ( V_21 + 500000 ) / 1000000 * V_22 ;
V_20 = ( V_20 + 500 ) / 1000 ;
for ( V_18 = 0 ; V_18 < 0x40 ; V_18 ++ ) {
V_23 = V_21 / ( 20 + ( V_18 * 8 ) + V_20 ) ;
if ( V_23 <= V_17 -> V_28 )
goto V_38;
}
F_10 ( V_27 , L_3 ) ;
return - V_36 ;
V_38:
F_12 ( V_27 , L_4 ,
V_23 , V_17 -> V_28 , F_11 ( V_2 -> V_37 ) , V_20 , V_19 , V_18 ) ;
V_2 -> V_11 = V_18 << V_24 | V_19 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_39 = ! ! F_14 ( V_2 ) ;
V_2 -> V_40 = 0 ;
if ( V_2 -> V_41 == 1 )
V_2 -> V_42 |= V_43 ;
F_1 ( V_2 , V_44 , ( V_2 -> V_45 -> V_46 << 1 ) | V_39 ) ;
if ( V_2 -> V_42 & V_47 ) {
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_7 , V_48 ) ;
} else {
F_1 ( V_2 , V_7 , V_48 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
}
F_1 ( V_2 , V_6 , V_39 ? V_49 : V_50 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_45 ++ ;
V_2 -> V_41 -- ;
V_2 -> V_42 &= V_51 ;
F_13 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_53 * V_45 = V_2 -> V_45 ;
if ( ! ( V_52 & V_54 ) )
return;
if ( V_2 -> V_40 < V_45 -> V_55 ) {
F_1 ( V_2 , V_56 , V_45 -> V_57 [ V_2 -> V_40 ] ) ;
V_2 -> V_40 ++ ;
} else {
if ( V_2 -> V_42 & V_43 ) {
F_1 ( V_2 , V_7 , V_58 ) ;
} else {
F_15 ( V_2 ) ;
return;
}
}
F_1 ( V_2 , V_9 , V_59 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_53 * V_45 = V_2 -> V_45 ;
if ( ! ( V_52 & V_60 ) )
return;
if ( V_52 & V_61 ) {
} else if ( V_2 -> V_40 < V_45 -> V_55 ) {
V_45 -> V_57 [ V_2 -> V_40 ] = F_3 ( V_2 , V_56 ) ;
V_2 -> V_40 ++ ;
}
if ( V_2 -> V_40 + 1 >= V_45 -> V_55 )
F_1 ( V_2 , V_7 , V_58 ) ;
if ( V_2 -> V_40 == V_45 -> V_55 && ! ( V_2 -> V_42 & V_43 ) )
F_15 ( V_2 ) ;
else
F_1 ( V_2 , V_9 , V_62 ) ;
}
static bool F_18 ( struct V_1 * V_2 )
{
T_1 V_63 , V_64 ;
T_2 V_65 ;
V_63 = F_3 ( V_2 , V_66 ) & 0xff ;
V_64 = V_63 & F_3 ( V_2 , V_67 ) ;
if ( ! V_64 )
return false ;
if ( V_64 & V_68 ) {
if ( V_63 & V_69 ) {
F_19 ( V_2 -> V_70 , V_71 , & V_65 ) ;
F_1 ( V_2 , V_56 , V_65 ) ;
F_1 ( V_2 , V_67 , V_72 | V_73 | V_68 ) ;
} else {
F_19 ( V_2 -> V_70 , V_74 , & V_65 ) ;
F_3 ( V_2 , V_56 ) ;
F_1 ( V_2 , V_67 , V_75 | V_73 | V_68 ) ;
}
F_1 ( V_2 , V_66 , ~ V_68 & 0xff ) ;
}
if ( V_64 & V_73 ) {
F_19 ( V_2 -> V_70 , V_76 , & V_65 ) ;
F_1 ( V_2 , V_67 , V_68 | V_73 ) ;
F_1 ( V_2 , V_66 , ~ V_73 & 0xff ) ;
}
if ( V_64 & V_75 ) {
int V_77 ;
V_65 = F_3 ( V_2 , V_56 ) ;
V_77 = F_19 ( V_2 -> V_70 , V_78 , & V_65 ) ;
F_1 ( V_2 , V_79 , V_80 | V_81 | ( V_77 < 0 ? V_82 : 0 ) ) ;
F_1 ( V_2 , V_66 , ~ V_75 & 0xff ) ;
}
if ( V_64 & V_72 ) {
F_19 ( V_2 -> V_70 , V_83 , & V_65 ) ;
F_1 ( V_2 , V_56 , V_65 ) ;
F_1 ( V_2 , V_66 , ~ V_72 & 0xff ) ;
}
return true ;
}
static T_3 F_20 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
T_1 V_52 , V_4 ;
V_4 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 , V_4 & V_86 ) ;
V_52 = F_3 ( V_2 , V_9 ) ;
V_52 &= F_3 ( V_2 , V_6 ) ;
if ( ! V_52 ) {
if ( F_18 ( V_2 ) )
return V_87 ;
return V_88 ;
}
if ( V_52 & V_89 ) {
V_2 -> V_42 |= V_90 | V_91 ;
goto V_92;
}
if ( V_52 & V_93 ) {
F_1 ( V_2 , V_6 , V_94 ) ;
V_2 -> V_42 |= V_95 ;
goto V_92;
}
if ( V_52 & V_96 ) {
V_2 -> V_41 -- ;
V_2 -> V_42 |= V_90 ;
goto V_92;
}
if ( F_14 ( V_2 ) )
F_17 ( V_2 , V_52 ) ;
else
F_16 ( V_2 , V_52 ) ;
V_92:
if ( V_2 -> V_42 & V_90 ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_21 ( & V_2 -> V_97 ) ;
}
return V_87 ;
}
static int F_22 ( struct V_98 * V_99 ,
struct V_53 * V_100 ,
int V_101 )
{
struct V_1 * V_2 = F_23 ( V_99 ) ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
int V_12 , V_77 ;
long V_102 ;
F_24 ( V_27 ) ;
V_77 = F_6 ( V_2 ) ;
if ( V_77 < 0 )
goto V_92;
for ( V_12 = 0 ; V_12 < V_101 ; V_12 ++ ) {
if ( V_100 [ V_12 ] . V_55 == 0 ) {
V_77 = - V_103 ;
goto V_92;
}
}
V_2 -> V_45 = V_100 ;
V_2 -> V_41 = V_101 ;
V_2 -> V_42 = ( V_2 -> V_42 & V_51 ) | V_47 ;
F_13 ( V_2 ) ;
V_102 = F_25 ( V_2 -> V_97 , V_2 -> V_42 & V_90 ,
V_101 * V_99 -> V_104 ) ;
if ( ! V_102 ) {
F_5 ( V_2 ) ;
V_77 = - V_105 ;
} else if ( V_2 -> V_42 & V_95 ) {
V_77 = - V_106 ;
} else if ( V_2 -> V_42 & V_91 ) {
V_77 = - V_107 ;
} else {
V_77 = V_101 - V_2 -> V_41 ;
}
V_92:
F_26 ( V_27 ) ;
if ( V_77 < 0 && V_77 != - V_106 )
F_10 ( V_27 , L_5 , V_77 , V_2 -> V_42 ) ;
return V_77 ;
}
static int F_27 ( struct V_108 * V_70 )
{
struct V_1 * V_2 = F_23 ( V_70 -> V_109 ) ;
if ( V_2 -> V_70 )
return - V_15 ;
if ( V_70 -> V_42 & V_110 )
return - V_111 ;
F_24 ( F_9 ( V_2 ) ) ;
V_2 -> V_70 = V_70 ;
F_1 ( V_2 , V_112 , V_70 -> V_46 ) ;
F_1 ( V_2 , V_66 , 0 ) ;
F_1 ( V_2 , V_67 , V_68 | V_73 ) ;
F_1 ( V_2 , V_79 , V_80 | V_81 ) ;
return 0 ;
}
static int F_28 ( struct V_108 * V_70 )
{
struct V_1 * V_2 = F_23 ( V_70 -> V_109 ) ;
F_29 ( ! V_2 -> V_70 ) ;
F_1 ( V_2 , V_67 , 0 ) ;
F_1 ( V_2 , V_79 , 0 ) ;
V_2 -> V_70 = NULL ;
F_26 ( F_9 ( V_2 ) ) ;
return 0 ;
}
static T_1 F_30 ( struct V_98 * V_99 )
{
return V_113 | V_114 |
( V_115 & ~ V_116 ) ;
}
static int F_31 ( struct V_117 * V_118 )
{
struct V_1 * V_2 ;
struct V_98 * V_99 ;
struct V_119 * V_120 ;
struct V_26 * V_27 = & V_118 -> V_27 ;
struct V_16 V_121 ;
int V_84 , V_77 ;
V_2 = F_32 ( V_27 , sizeof( struct V_1 ) , V_122 ) ;
if ( ! V_2 )
return - V_123 ;
V_2 -> V_37 = F_33 ( V_27 , NULL ) ;
if ( F_34 ( V_2 -> V_37 ) ) {
F_10 ( V_27 , L_6 ) ;
return F_35 ( V_2 -> V_37 ) ;
}
V_120 = F_36 ( V_118 , V_124 , 0 ) ;
V_2 -> V_5 = F_37 ( V_27 , V_120 ) ;
if ( F_34 ( V_2 -> V_5 ) )
return F_35 ( V_2 -> V_5 ) ;
V_2 -> V_32 = (enum V_125 ) F_38 ( V_126 , V_27 ) -> V_127 ;
F_39 ( & V_2 -> V_97 ) ;
V_99 = & V_2 -> V_99 ;
V_99 -> V_128 = V_118 -> V_129 ;
V_99 -> V_130 = & V_131 ;
V_99 -> V_132 = V_133 ;
V_99 -> V_134 = 3 ;
V_99 -> V_27 . V_135 = V_27 ;
V_99 -> V_27 . V_136 = V_27 -> V_136 ;
F_40 ( V_99 , V_2 ) ;
F_41 ( V_99 -> V_137 , V_118 -> V_137 , sizeof( V_99 -> V_137 ) ) ;
F_42 ( V_27 , & V_121 , false ) ;
F_43 ( V_27 ) ;
F_24 ( V_27 ) ;
V_77 = F_8 ( V_2 , & V_121 ) ;
if ( V_77 < 0 )
goto V_138;
F_5 ( V_2 ) ;
if ( F_44 ( V_27 -> V_136 , L_7 ) )
V_2 -> V_42 |= V_139 ;
else
F_26 ( V_27 ) ;
V_84 = F_45 ( V_118 , 0 ) ;
V_77 = F_46 ( V_27 , V_84 , F_20 , 0 , F_47 ( V_27 ) , V_2 ) ;
if ( V_77 < 0 ) {
F_10 ( V_27 , L_8 , V_84 ) ;
goto V_140;
}
F_48 ( V_118 , V_2 ) ;
V_77 = F_49 ( V_99 ) ;
if ( V_77 < 0 ) {
F_10 ( V_27 , L_9 , V_77 ) ;
goto V_140;
}
F_50 ( V_27 , L_10 ) ;
return 0 ;
V_138:
F_26 ( V_27 ) ;
V_140:
F_51 ( V_27 ) ;
return V_77 ;
}
static int F_52 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_53 ( V_118 ) ;
struct V_26 * V_27 = & V_118 -> V_27 ;
F_54 ( & V_2 -> V_99 ) ;
if ( V_2 -> V_42 & V_139 )
F_26 ( V_27 ) ;
F_51 ( V_27 ) ;
return 0 ;
}
