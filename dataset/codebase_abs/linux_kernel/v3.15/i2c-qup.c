static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
T_2 V_6 ;
T_2 V_7 ;
V_5 = F_2 ( V_4 -> V_8 + V_9 ) ;
V_6 = F_2 ( V_4 -> V_8 + V_10 ) ;
V_7 = F_2 ( V_4 -> V_8 + V_11 ) ;
if ( ! V_4 -> V_12 ) {
F_3 ( V_13 , V_4 -> V_8 + V_14 ) ;
return V_15 ;
}
V_5 &= V_16 ;
V_6 &= V_17 ;
if ( V_6 ) {
F_3 ( V_6 , V_4 -> V_8 + V_10 ) ;
goto V_18;
}
if ( V_5 ) {
F_3 ( V_13 , V_4 -> V_8 + V_14 ) ;
goto V_18;
}
if ( V_7 & V_19 )
F_3 ( V_19 , V_4 -> V_8 + V_11 ) ;
if ( V_7 & V_20 )
F_3 ( V_20 , V_4 -> V_8 + V_11 ) ;
V_18:
V_4 -> V_6 = V_6 ;
V_4 -> V_5 = V_5 ;
F_4 ( & V_4 -> V_21 ) ;
return V_15 ;
}
static int F_5 ( struct V_3 * V_4 ,
T_2 V_22 , T_2 V_23 )
{
int V_24 = 1 ;
T_2 V_25 ;
do {
V_25 = F_2 ( V_4 -> V_8 + V_14 ) ;
if ( V_25 & V_26 &&
( V_25 & V_23 ) == V_22 )
return 0 ;
F_6 ( 1 ) ;
} while ( V_24 -- );
return - V_27 ;
}
static int F_7 ( struct V_3 * V_4 , T_2 V_22 )
{
return F_5 ( V_4 , V_22 , V_28 ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
return F_5 ( V_4 , 0 , 0 ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
return F_5 ( V_4 , V_29 , V_29 ) ;
}
static int F_10 ( struct V_3 * V_4 , T_2 V_25 )
{
if ( F_8 ( V_4 ) != 0 )
return - V_30 ;
F_3 ( V_25 , V_4 -> V_8 + V_14 ) ;
if ( F_7 ( V_4 , V_25 ) != 0 )
return - V_30 ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 )
{
unsigned long V_31 ;
T_2 V_7 ;
T_2 V_32 ;
V_31 = V_33 + V_34 ;
for (; ; ) {
V_7 = F_2 ( V_4 -> V_8 + V_11 ) ;
V_32 = F_2 ( V_4 -> V_8 + V_9 ) ;
if ( ! ( V_7 & V_35 ) &&
! ( V_32 & V_36 ) )
return 0 ;
if ( F_12 ( V_33 , V_31 ) )
return - V_27 ;
F_13 ( V_4 -> V_37 , V_4 -> V_37 * 2 ) ;
}
}
static void F_14 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
int V_39 = V_12 -> V_40 + 1 ;
if ( V_39 < V_4 -> V_41 ) {
F_3 ( V_42 , V_4 -> V_8 + V_43 ) ;
F_3 ( V_39 , V_4 -> V_8 + V_44 ) ;
} else {
F_3 ( V_45 | V_42 ,
V_4 -> V_8 + V_43 ) ;
F_3 ( V_39 , V_4 -> V_8 + V_46 ) ;
}
}
static void F_15 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
T_2 V_47 = V_12 -> V_47 << 1 ;
T_2 V_48 ;
T_2 V_7 ;
int V_49 ;
T_2 V_50 ;
if ( V_4 -> V_51 == 0 ) {
V_50 = V_52 | V_47 ;
V_49 = 1 ;
} else {
V_50 = 0 ;
V_49 = 0 ;
}
while ( V_4 -> V_51 < V_12 -> V_40 ) {
V_7 = F_2 ( V_4 -> V_8 + V_11 ) ;
if ( V_7 & V_53 )
break;
if ( V_4 -> V_51 == V_12 -> V_40 - 1 )
V_48 = V_54 ;
else
V_48 = V_55 ;
if ( V_49 & 1 )
V_50 |= ( V_48 | V_12 -> V_56 [ V_4 -> V_51 ] ) << V_57 ;
else
V_50 = V_48 | V_12 -> V_56 [ V_4 -> V_51 ] ;
if ( V_49 & 1 || V_4 -> V_51 == V_12 -> V_40 - 1 )
F_3 ( V_50 , V_4 -> V_8 + V_58 ) ;
V_4 -> V_51 ++ ;
V_49 ++ ;
}
}
static int F_16 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
unsigned long V_59 ;
int V_60 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_51 = 0 ;
F_17 ( V_4 -> V_1 ) ;
F_14 ( V_4 , V_12 ) ;
V_60 = F_10 ( V_4 , V_61 ) ;
if ( V_60 )
goto V_62;
F_3 ( V_4 -> V_63 , V_4 -> V_8 + V_64 ) ;
do {
V_60 = F_10 ( V_4 , V_65 ) ;
if ( V_60 )
goto V_62;
F_15 ( V_4 , V_12 ) ;
V_60 = F_10 ( V_4 , V_61 ) ;
if ( V_60 )
goto V_62;
V_59 = F_18 ( & V_4 -> V_21 , V_34 ) ;
if ( ! V_59 ) {
F_3 ( 1 , V_4 -> V_8 + V_66 ) ;
V_60 = - V_27 ;
goto V_62;
}
if ( V_4 -> V_5 || V_4 -> V_6 ) {
if ( V_4 -> V_5 & V_67 )
F_19 ( V_4 -> V_2 , L_1 , V_12 -> V_47 ) ;
V_60 = - V_30 ;
goto V_62;
}
} while ( V_4 -> V_51 < V_12 -> V_40 );
V_60 = F_11 ( V_4 ) ;
V_62:
F_20 ( V_4 -> V_1 ) ;
V_4 -> V_12 = NULL ;
return V_60 ;
}
static void F_21 ( struct V_3 * V_4 , int V_40 )
{
if ( V_40 < V_4 -> V_68 ) {
F_3 ( V_42 , V_4 -> V_8 + V_43 ) ;
F_3 ( V_40 , V_4 -> V_8 + V_69 ) ;
} else {
F_3 ( V_70 | V_42 ,
V_4 -> V_8 + V_43 ) ;
F_3 ( V_40 , V_4 -> V_8 + V_71 ) ;
}
}
static void F_22 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
T_2 V_47 , V_40 , V_50 ;
V_47 = ( V_12 -> V_47 << 1 ) | 1 ;
V_40 = ( V_12 -> V_40 == V_72 ) ? 0 : V_12 -> V_40 ;
V_50 = ( ( V_73 | V_40 ) << V_57 ) | V_52 | V_47 ;
F_3 ( V_50 , V_4 -> V_8 + V_58 ) ;
}
static void F_23 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
T_2 V_7 ;
T_2 V_50 = 0 ;
int V_49 ;
for ( V_49 = 0 ; V_4 -> V_51 < V_12 -> V_40 ; V_49 ++ ) {
if ( ( V_49 & 1 ) == 0 ) {
V_7 = F_2 ( V_4 -> V_8 + V_11 ) ;
if ( ! ( V_7 & V_74 ) )
break;
V_50 = F_2 ( V_4 -> V_8 + V_75 ) ;
V_12 -> V_56 [ V_4 -> V_51 ++ ] = V_50 & 0xFF ;
} else {
V_12 -> V_56 [ V_4 -> V_51 ++ ] = V_50 >> V_57 ;
}
}
}
static int F_24 ( struct V_3 * V_4 , struct V_38 * V_12 )
{
unsigned long V_59 ;
int V_60 ;
if ( V_12 -> V_40 > V_72 ) {
F_19 ( V_4 -> V_2 , L_2 ,
V_72 ) ;
return - V_76 ;
}
V_4 -> V_12 = V_12 ;
V_4 -> V_51 = 0 ;
F_17 ( V_4 -> V_1 ) ;
F_21 ( V_4 , V_12 -> V_40 ) ;
V_60 = F_10 ( V_4 , V_61 ) ;
if ( V_60 )
goto V_62;
F_3 ( V_4 -> V_63 , V_4 -> V_8 + V_64 ) ;
V_60 = F_10 ( V_4 , V_65 ) ;
if ( V_60 )
goto V_62;
F_22 ( V_4 , V_12 ) ;
V_60 = F_10 ( V_4 , V_61 ) ;
if ( V_60 )
goto V_62;
do {
V_59 = F_18 ( & V_4 -> V_21 , V_34 ) ;
if ( ! V_59 ) {
F_3 ( 1 , V_4 -> V_8 + V_66 ) ;
V_60 = - V_27 ;
goto V_62;
}
if ( V_4 -> V_5 || V_4 -> V_6 ) {
if ( V_4 -> V_5 & V_67 )
F_19 ( V_4 -> V_2 , L_1 , V_12 -> V_47 ) ;
V_60 = - V_30 ;
goto V_62;
}
F_23 ( V_4 , V_12 ) ;
} while ( V_4 -> V_51 < V_12 -> V_40 );
V_62:
F_20 ( V_4 -> V_1 ) ;
V_4 -> V_12 = NULL ;
return V_60 ;
}
static int F_25 ( struct V_77 * V_78 ,
struct V_38 V_79 [] ,
int V_80 )
{
struct V_3 * V_4 = F_26 ( V_78 ) ;
int V_60 , V_49 ;
V_60 = F_27 ( V_4 -> V_2 ) ;
if ( V_60 < 0 )
goto V_81;
F_3 ( 1 , V_4 -> V_8 + V_66 ) ;
V_60 = F_7 ( V_4 , V_13 ) ;
if ( V_60 )
goto V_81;
F_3 ( V_82 | V_83 , V_4 -> V_8 + V_84 ) ;
for ( V_49 = 0 ; V_49 < V_80 ; V_49 ++ ) {
if ( V_79 [ V_49 ] . V_40 == 0 ) {
V_60 = - V_76 ;
goto V_81;
}
if ( F_9 ( V_4 ) ) {
V_60 = - V_30 ;
goto V_81;
}
if ( V_79 [ V_49 ] . V_85 & V_86 )
V_60 = F_24 ( V_4 , & V_79 [ V_49 ] ) ;
else
V_60 = F_16 ( V_4 , & V_79 [ V_49 ] ) ;
if ( V_60 )
break;
V_60 = F_10 ( V_4 , V_13 ) ;
if ( V_60 )
break;
}
if ( V_60 == 0 )
V_60 = V_80 ;
V_81:
F_28 ( V_4 -> V_2 ) ;
F_29 ( V_4 -> V_2 ) ;
return V_60 ;
}
static T_2 F_30 ( struct V_77 * V_78 )
{
return V_87 | ( V_88 & ~ V_89 ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
F_32 ( V_4 -> V_90 ) ;
F_32 ( V_4 -> V_91 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
T_2 V_92 ;
F_10 ( V_4 , V_13 ) ;
F_34 ( V_4 -> V_90 ) ;
V_92 = F_2 ( V_4 -> V_8 + V_84 ) ;
V_92 |= V_93 ;
F_3 ( V_92 , V_4 -> V_8 + V_84 ) ;
F_34 ( V_4 -> V_91 ) ;
}
static int F_35 ( struct V_94 * V_95 )
{
static const int V_96 [] = { 4 , 16 , 32 } ;
struct V_97 * V_98 = V_95 -> V_2 . V_99 ;
struct V_3 * V_4 ;
unsigned long V_100 ;
struct V_101 * V_102 ;
T_2 V_103 , V_104 , V_105 ;
int V_60 , V_106 , V_107 ;
int V_108 ;
T_2 V_109 = 100000 ;
V_4 = F_36 ( & V_95 -> V_2 , sizeof( * V_4 ) , V_110 ) ;
if ( ! V_4 )
return - V_111 ;
V_4 -> V_2 = & V_95 -> V_2 ;
F_37 ( & V_4 -> V_21 ) ;
F_38 ( V_95 , V_4 ) ;
F_39 ( V_98 , L_3 , & V_109 ) ;
if ( ! V_109 || V_109 > 400000 ) {
F_19 ( V_4 -> V_2 , L_4 ,
V_109 ) ;
return - V_76 ;
}
V_102 = F_40 ( V_95 , V_112 , 0 ) ;
V_4 -> V_8 = F_41 ( V_4 -> V_2 , V_102 ) ;
if ( F_42 ( V_4 -> V_8 ) )
return F_43 ( V_4 -> V_8 ) ;
V_4 -> V_1 = F_44 ( V_95 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_19 ( V_4 -> V_2 , L_5 ) ;
return V_4 -> V_1 ;
}
V_4 -> V_90 = F_45 ( V_4 -> V_2 , L_6 ) ;
if ( F_42 ( V_4 -> V_90 ) ) {
F_19 ( V_4 -> V_2 , L_7 ) ;
return F_43 ( V_4 -> V_90 ) ;
}
V_4 -> V_91 = F_45 ( V_4 -> V_2 , L_8 ) ;
if ( F_42 ( V_4 -> V_91 ) ) {
F_19 ( V_4 -> V_2 , L_9 ) ;
return F_43 ( V_4 -> V_91 ) ;
}
F_31 ( V_4 ) ;
F_3 ( 1 , V_4 -> V_8 + V_66 ) ;
V_60 = F_8 ( V_4 ) ;
if ( V_60 )
goto V_113;
V_60 = F_46 ( V_4 -> V_2 , V_4 -> V_1 , F_1 ,
V_114 , L_10 , V_4 ) ;
if ( V_60 ) {
F_19 ( V_4 -> V_2 , L_11 , V_4 -> V_1 ) ;
goto V_113;
}
F_20 ( V_4 -> V_1 ) ;
V_104 = F_2 ( V_4 -> V_8 + V_115 ) ;
F_47 ( V_4 -> V_2 , L_12 , V_104 ) ;
V_103 = F_2 ( V_4 -> V_8 + V_43 ) ;
V_105 = F_48 ( V_103 ) ;
if ( V_105 >= F_49 ( V_96 ) )
return - V_30 ;
V_4 -> V_116 = V_96 [ V_105 ] / 2 ;
V_105 = F_50 ( V_103 ) ;
if ( V_105 >= F_49 ( V_96 ) )
return - V_30 ;
V_4 -> V_117 = V_96 [ V_105 ] / 2 ;
V_105 = F_51 ( V_103 ) ;
V_4 -> V_41 = V_4 -> V_116 * ( 2 << V_105 ) ;
V_105 = F_52 ( V_103 ) ;
V_4 -> V_68 = V_4 -> V_117 * ( 2 << V_105 ) ;
V_108 = F_53 ( V_4 -> V_90 ) ;
V_106 = ( ( V_108 / V_109 ) / 2 ) - 3 ;
V_107 = 3 ;
V_4 -> V_63 = ( V_107 << 8 ) | ( V_106 & 0xff ) ;
V_100 = ( V_118 / V_109 ) + 1 ;
V_4 -> V_37 = V_100 * 9 ;
F_47 ( V_4 -> V_2 , L_13 ,
V_4 -> V_117 , V_4 -> V_68 ,
V_4 -> V_116 , V_4 -> V_41 ) ;
F_54 ( & V_4 -> V_78 , V_4 ) ;
V_4 -> V_78 . V_119 = & V_120 ;
V_4 -> V_78 . V_2 . V_121 = V_4 -> V_2 ;
V_4 -> V_78 . V_2 . V_99 = V_95 -> V_2 . V_99 ;
F_55 ( V_4 -> V_78 . V_122 , L_14 , sizeof( V_4 -> V_78 . V_122 ) ) ;
V_60 = F_56 ( & V_4 -> V_78 ) ;
if ( V_60 )
goto V_113;
F_57 ( V_4 -> V_2 , V_123 ) ;
F_58 ( V_4 -> V_2 ) ;
F_59 ( V_4 -> V_2 ) ;
F_60 ( V_4 -> V_2 ) ;
return 0 ;
V_113:
F_33 ( V_4 ) ;
return V_60 ;
}
static int F_61 ( struct V_94 * V_95 )
{
struct V_3 * V_4 = F_62 ( V_95 ) ;
F_20 ( V_4 -> V_1 ) ;
F_33 ( V_4 ) ;
F_63 ( & V_4 -> V_78 ) ;
F_64 ( V_4 -> V_2 ) ;
F_65 ( V_4 -> V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_124 * V_124 )
{
struct V_3 * V_4 = F_67 ( V_124 ) ;
F_47 ( V_124 , L_15 ) ;
F_33 ( V_4 ) ;
return 0 ;
}
static int F_68 ( struct V_124 * V_124 )
{
struct V_3 * V_4 = F_67 ( V_124 ) ;
F_47 ( V_124 , L_16 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_69 ( struct V_124 * V_124 )
{
F_66 ( V_124 ) ;
return 0 ;
}
static int F_70 ( struct V_124 * V_124 )
{
F_68 ( V_124 ) ;
F_28 ( V_124 ) ;
F_71 ( V_124 ) ;
return 0 ;
}
