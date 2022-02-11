static int F_1 ( void T_1 * V_1 ,
struct V_2 * V_3 )
{
T_2 V_4 , V_5 = 0 ;
V_4 = F_2 ( V_1 + V_6 ) ;
if ( ! V_4 )
return 1 ;
V_3 -> V_7 = ( V_4 & V_8 ) >> V_9 ;
V_3 -> V_10 = V_4 & V_11 ;
V_4 = F_2 ( V_1 + V_12 ) ;
if ( ! ( V_3 -> V_7 && ( V_4 & V_13 ) ) )
goto V_14;
V_3 -> V_15 . V_16 = ( V_4 & V_17 ) >> V_18 ;
V_4 = F_2 ( V_1 + V_19 ) ;
V_3 -> V_15 . V_20 = ( V_4 & V_21 ) >> V_22 ;
V_3 -> V_15 . V_23 = V_4 & V_24 ;
V_3 -> V_15 . V_25 = ( V_4 & V_26 ) >> V_27 ;
V_3 -> V_15 . V_28 = F_2 ( V_1 + V_29 ) ;
F_3 ( 3 , L_1 , V_3 -> V_15 . V_16 ,
V_3 -> V_15 . V_28 ) ;
V_5 = V_30 ;
V_14:
V_4 = F_2 ( V_1 + V_31 ) ;
if ( ! ( V_3 -> V_10 && ( V_4 & V_13 ) ) )
goto V_32;
V_4 = F_2 ( V_1 + V_33 ) ;
V_3 -> V_34 . V_20 = ( V_4 & V_21 ) >> V_22 ;
V_3 -> V_34 . V_23 = V_4 & V_24 ;
V_3 -> V_34 . V_25 = ( V_4 & V_26 ) >> V_27 ;
V_3 -> V_34 . V_28 = F_2 ( V_1 + V_35 ) ;
V_5 |= V_36 ;
V_32:
F_4 ( V_5 , V_1 + V_37 ) ;
F_4 ( 0x0 , V_1 + V_37 ) ;
return 0 ;
}
static void F_5 ( struct V_38 * V_39 ,
struct V_2 * V_3 )
{
struct V_40 * V_41 = V_39 -> V_42 ;
struct V_43 * V_44 ;
if ( V_3 -> V_7 ) {
V_44 = & V_3 -> V_15 ;
snprintf ( V_41 -> V_45 , V_46 ,
L_2 ,
L_3 , V_44 -> V_20 , V_44 -> V_25 , V_44 -> V_23 ) ;
F_6 ( V_47 , V_39 ,
V_3 -> V_7 , 0 , 0 , 0 , 0 , 0 , - 1 ,
V_41 -> V_45 , L_4 ) ;
}
if ( V_3 -> V_10 ) {
V_44 = & V_3 -> V_34 ;
snprintf ( V_41 -> V_45 , V_46 ,
L_2 ,
L_5 , V_44 -> V_20 , V_44 -> V_25 , V_44 -> V_23 ) ;
F_6 ( V_48 , V_39 ,
V_3 -> V_10 , 0 , 0 , 0 , 0 , 0 , - 1 ,
V_41 -> V_45 , L_4 ) ;
}
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
}
static void F_7 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_42 ;
int V_49 ;
V_49 = F_1 ( V_41 -> V_50 , & V_41 -> V_51 ) ;
if ( V_49 )
return;
V_41 -> V_7 += V_41 -> V_51 . V_7 ;
V_41 -> V_10 += V_41 -> V_51 . V_10 ;
F_5 ( V_39 , & V_41 -> V_51 ) ;
F_3 ( 3 , L_6 ,
V_41 -> V_7 , V_41 -> V_10 ) ;
}
static enum V_52 F_8 ( const void T_1 * V_1 )
{
enum V_52 V_53 ;
T_2 V_54 ;
V_54 = F_2 ( V_1 + V_55 ) ;
V_54 = ( V_54 & V_56 ) >> V_57 ;
switch ( V_54 ) {
case V_58 :
V_53 = V_59 ;
break;
case V_60 :
V_53 = V_61 ;
break;
default:
V_53 = V_62 ;
}
return V_53 ;
}
static bool F_9 ( void T_1 * V_1 )
{
enum V_52 V_53 ;
T_2 V_63 ;
bool V_64 = false ;
V_53 = F_8 ( V_1 ) ;
if ( V_53 == V_62 )
return V_64 ;
V_63 = F_2 ( V_1 + V_65 ) & V_66 ;
if ( ( V_63 == V_67 ) && ( V_53 == V_59 ) )
V_64 = true ;
return V_64 ;
}
static T_2 F_10 ( void )
{
struct V_68 V_69 ;
F_11 ( & V_69 ) ;
return V_69 . V_70 * V_69 . V_71 ;
}
static enum V_72 F_12 ( const void T_1 * V_1 )
{
enum V_72 V_73 ;
T_2 V_74 ;
V_74 = F_2 ( V_1 + V_75 ) ;
if ( V_74 & V_76 )
V_73 = V_77 ;
else
V_73 = V_78 ;
return V_73 ;
}
static int F_13 ( struct V_38 * V_39 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_40 * V_41 = V_39 -> V_42 ;
T_2 V_83 ;
int V_20 , V_84 ;
for ( V_20 = 0 ; V_20 < V_39 -> V_85 ; V_20 ++ ) {
V_80 = V_39 -> V_86 [ V_20 ] ;
V_83 = F_10 () ;
for ( V_84 = 0 ; V_84 < V_80 -> V_87 ; V_84 ++ ) {
V_82 = V_80 -> V_88 [ V_84 ] -> V_82 ;
V_82 -> V_89 = V_90 ;
V_82 -> V_91 = F_12 ( V_41 -> V_50 ) ;
V_82 -> V_92 = ( V_83 >> V_93 ) / V_80 -> V_87 ;
V_82 -> V_94 = V_95 ;
V_82 -> V_96 = F_8 ( V_41 -> V_50 ) ;
}
}
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
struct V_97 * V_98 )
{
int V_49 ;
struct V_40 * V_41 ;
V_39 -> V_98 = & V_98 -> V_99 ;
V_41 = V_39 -> V_42 ;
F_15 ( V_98 , V_39 ) ;
V_39 -> V_100 = V_101 | V_102 ;
V_39 -> V_103 = V_104 | V_90 ;
V_39 -> V_105 = V_106 ;
V_39 -> V_107 = V_108 ;
V_39 -> V_109 = V_90 ;
V_39 -> V_110 = L_7 ;
V_39 -> V_111 = V_112 ;
V_39 -> V_113 = V_114 ;
V_39 -> V_115 = L_8 ;
V_116 = V_117 ;
V_39 -> V_118 = F_7 ;
V_39 -> V_119 = NULL ;
V_49 = F_13 ( V_39 ) ;
return V_49 ;
}
static int F_16 ( struct V_97 * V_98 )
{
struct V_38 * V_39 ;
struct V_120 V_121 [ 2 ] ;
struct V_40 * V_41 ;
int V_122 ;
struct V_123 * V_124 ;
void T_1 * V_50 ;
V_124 = F_17 ( V_98 , V_125 , 0 ) ;
V_50 = F_18 ( & V_98 -> V_99 , V_124 ) ;
if ( F_19 ( V_50 ) )
return F_20 ( V_50 ) ;
if ( ! F_9 ( V_50 ) ) {
F_21 ( V_126 , V_127 , L_9 ) ;
return - V_128 ;
}
V_121 [ 0 ] . type = V_129 ;
V_121 [ 0 ] . V_83 = V_130 ;
V_121 [ 0 ] . V_131 = true ;
V_121 [ 1 ] . type = V_132 ;
V_121 [ 1 ] . V_83 = V_133 ;
V_121 [ 1 ] . V_131 = false ;
V_39 = F_22 ( 0 , F_23 ( V_121 ) , V_121 ,
sizeof( struct V_40 ) ) ;
if ( ! V_39 ) {
F_21 ( V_134 , V_127 ,
L_10 ) ;
return - V_135 ;
}
V_41 = V_39 -> V_42 ;
V_41 -> V_50 = V_50 ;
V_122 = F_14 ( V_39 , V_98 ) ;
if ( V_122 ) {
F_21 ( V_134 , V_127 ,
L_11 ) ;
goto V_136;
}
V_122 = F_24 ( V_39 ) ;
if ( V_122 ) {
F_21 ( V_134 , V_127 ,
L_12 ) ;
goto V_136;
}
F_4 ( 0x0 , V_50 + V_37 ) ;
return V_122 ;
V_136:
F_25 ( V_39 ) ;
return V_122 ;
}
static int F_26 ( struct V_97 * V_98 )
{
struct V_38 * V_39 = F_27 ( V_98 ) ;
F_28 ( & V_98 -> V_99 ) ;
F_25 ( V_39 ) ;
return 0 ;
}
