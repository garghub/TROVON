static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 -> V_5 , V_2 -> V_3 + V_6 ) ;
F_3 ( V_2 -> V_4 -> V_7 , V_2 -> V_3 + V_8 ) ;
F_3 ( V_2 -> V_4 -> V_9 , V_2 -> V_3 + V_10 ) ;
F_3 ( V_11 << 8 , V_2 -> V_3 + V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 ) {
F_5 ( V_2 -> V_14 , & V_2 -> V_15 [ 0 ] , 1 , V_16 ) ;
F_5 ( V_2 -> V_14 , & V_2 -> V_15 [ 1 ] , 1 , V_17 ) ;
} else {
F_5 ( V_2 -> V_14 , V_2 -> V_15 , 2 , V_16 ) ;
}
}
static void F_6 ( void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_7 ( & V_2 -> V_19 ) ;
F_4 ( V_2 ) ;
}
static int F_8 ( struct V_20 * V_21 ,
struct V_22 * V_23 , T_1 V_24 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 = F_9 ( V_21 ) ;
if ( V_23 -> V_24 & V_27 ) {
V_2 -> V_13 = 1 ;
V_2 -> V_28 = ( V_23 -> V_29 << 1 ) | V_30 ;
V_2 -> V_31 [ 0 ] = V_32 ;
V_26 = F_10 ( V_2 -> V_33 ,
(struct V_34 * ) & V_2 -> V_31 [ 0 ] ,
1 , V_35 , 0 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_1 ) ;
goto V_36;
}
F_12 ( & V_2 -> V_15 [ 0 ] , & V_2 -> V_28 , 1 ) ;
F_13 ( V_2 -> V_14 , & V_2 -> V_15 [ 0 ] , 1 , V_16 ) ;
V_26 = F_10 ( V_2 -> V_33 , & V_2 -> V_15 [ 0 ] , 1 ,
V_37 ,
V_38 | V_39 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_2 ) ;
goto V_40;
}
V_2 -> V_31 [ 1 ] = V_24 | V_41 |
F_14 ( V_23 -> V_42 ) ;
V_26 = F_10 ( V_2 -> V_33 ,
(struct V_34 * ) & V_2 -> V_31 [ 1 ] ,
1 , V_35 , V_38 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_1 ) ;
goto V_40;
}
F_12 ( & V_2 -> V_15 [ 1 ] , V_23 -> V_43 , V_23 -> V_42 ) ;
F_13 ( V_2 -> V_14 , & V_2 -> V_15 [ 1 ] , 1 , V_17 ) ;
V_26 = F_10 ( V_2 -> V_33 , & V_2 -> V_15 [ 1 ] , 1 ,
V_44 ,
V_38 | V_39 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_2 ) ;
goto V_45;
}
} else {
V_2 -> V_13 = 0 ;
V_2 -> V_28 = ( V_23 -> V_29 << 1 ) | V_46 ;
V_2 -> V_31 [ 0 ] = V_24 | V_47 |
F_14 ( V_23 -> V_42 + 1 ) ;
V_26 = F_10 ( V_2 -> V_33 ,
(struct V_34 * ) & V_2 -> V_31 [ 0 ] ,
1 , V_35 , 0 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_1 ) ;
goto V_48;
}
F_15 ( V_2 -> V_15 , 2 ) ;
F_16 ( & V_2 -> V_15 [ 0 ] , & V_2 -> V_28 , 1 ) ;
F_16 ( & V_2 -> V_15 [ 1 ] , V_23 -> V_43 , V_23 -> V_42 ) ;
F_13 ( V_2 -> V_14 , V_2 -> V_15 , 2 , V_16 ) ;
V_26 = F_10 ( V_2 -> V_33 , V_2 -> V_15 , 2 ,
V_37 ,
V_38 | V_39 ) ;
if ( ! V_26 ) {
F_11 ( V_2 -> V_14 ,
L_2 ) ;
goto V_49;
}
}
V_26 -> V_50 = F_6 ;
V_26 -> V_51 = V_2 ;
F_17 ( V_26 ) ;
F_18 ( V_2 -> V_33 ) ;
return 0 ;
V_45:
F_5 ( V_2 -> V_14 , & V_2 -> V_15 [ 1 ] , 1 , V_17 ) ;
V_40:
F_5 ( V_2 -> V_14 , & V_2 -> V_15 [ 0 ] , 1 , V_16 ) ;
V_36:
F_19 ( V_2 -> V_33 ) ;
return - V_52 ;
V_49:
F_5 ( V_2 -> V_14 , V_2 -> V_15 , 2 , V_16 ) ;
V_48:
F_19 ( V_2 -> V_33 ) ;
return - V_52 ;
}
static int F_20 ( struct V_20 * V_21 , struct V_22 * V_23 ,
int V_53 )
{
struct V_1 * V_2 = F_9 ( V_21 ) ;
int V_54 ;
int V_24 ;
V_24 = V_53 ? V_55 : 0 ;
F_21 ( V_2 -> V_14 , L_3 ,
V_23 -> V_29 , V_23 -> V_42 , V_23 -> V_24 , V_53 ) ;
if ( V_23 -> V_42 == 0 )
return - V_52 ;
F_22 ( & V_2 -> V_19 ) ;
V_2 -> V_56 = 0 ;
V_54 = F_8 ( V_21 , V_23 , V_24 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_23 ( & V_2 -> V_19 ,
F_24 ( 1000 ) ) ;
if ( V_54 == 0 )
goto V_57;
if ( V_2 -> V_56 == - V_58 )
F_1 ( V_2 ) ;
F_21 ( V_2 -> V_14 , L_4 , V_2 -> V_56 ) ;
return V_2 -> V_56 ;
V_57:
F_21 ( V_2 -> V_14 , L_5 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
return - V_59 ;
}
static int F_25 ( struct V_20 * V_21 , struct V_22 V_60 [] ,
int V_61 )
{
int V_62 ;
int V_63 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_63 = F_20 ( V_21 , & V_60 [ V_62 ] , V_62 == ( V_61 - 1 ) ) ;
if ( V_63 )
return V_63 ;
}
return V_61 ;
}
static T_2 F_26 ( struct V_20 * V_21 )
{
return V_64 | ( V_65 & ~ V_66 ) ;
}
static T_3 F_27 ( int V_67 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
T_2 V_69 = F_28 ( V_2 -> V_3 + V_70 ) & V_11 ;
if ( ! V_69 )
return V_71 ;
if ( V_69 & V_72 )
V_2 -> V_56 = - V_58 ;
else if ( V_69 & ( V_73 |
V_74 |
V_75 | V_76 ) )
V_2 -> V_56 = - V_77 ;
F_3 ( V_69 , V_2 -> V_3 + V_78 ) ;
return V_79 ;
}
static bool F_29 ( struct V_80 * V_81 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
if ( ! F_30 ( V_81 ) )
return false ;
if ( V_81 -> V_82 != V_2 -> V_83 )
return false ;
V_81 -> V_84 = & V_2 -> V_85 ;
return true ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_4 ;
struct V_86 * V_14 = V_2 -> V_14 ;
struct V_87 * V_88 = V_14 -> V_89 ;
int V_54 ;
V_54 = F_32 ( V_88 , L_6 ,
& V_2 -> V_83 ) ;
if ( V_54 ) {
F_11 ( V_14 , L_7 ) ;
return - V_90 ;
}
V_54 = F_32 ( V_88 , L_8 , & V_4 ) ;
if ( V_54 )
F_33 ( V_14 , L_9 ) ;
else if ( V_4 == 400000 )
V_2 -> V_4 = & V_91 ;
else if ( V_4 != 100000 )
F_33 ( V_14 , L_10 ) ;
return 0 ;
}
static int T_4 F_34 ( struct V_92 * V_93 )
{
struct V_86 * V_14 = & V_93 -> V_14 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_94 * V_94 ;
struct V_95 * V_96 ;
T_5 V_97 ;
int V_63 , V_98 , V_99 ;
T_6 V_100 ;
V_94 = F_35 ( V_14 ) ;
if ( F_36 ( V_94 ) )
return F_37 ( V_94 ) ;
V_2 = F_38 ( V_14 , sizeof( struct V_1 ) , V_101 ) ;
if ( ! V_2 )
return - V_102 ;
V_96 = F_39 ( V_93 , V_103 , 0 ) ;
V_98 = F_40 ( V_93 , 0 ) ;
V_99 = F_40 ( V_93 , 1 ) ;
if ( ! V_96 || V_98 < 0 || V_99 < 0 )
return - V_104 ;
V_97 = F_41 ( V_96 ) ;
if ( ! F_42 ( V_14 , V_96 -> V_105 , V_97 , V_96 -> V_106 ) )
return - V_107 ;
V_2 -> V_3 = F_43 ( V_14 , V_96 -> V_105 , V_97 ) ;
if ( ! V_2 -> V_3 )
return - V_107 ;
V_63 = F_44 ( V_14 , V_98 , F_27 , 0 , F_45 ( V_14 ) , V_2 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = & V_108 ;
if ( V_14 -> V_89 ) {
V_63 = F_31 ( V_2 ) ;
if ( V_63 )
return V_63 ;
}
F_46 ( V_100 ) ;
F_47 ( V_109 , V_100 ) ;
V_2 -> V_85 . V_110 = V_99 ;
V_2 -> V_33 = F_48 ( V_100 , F_29 , V_2 ) ;
if ( ! V_2 -> V_33 ) {
F_11 ( V_14 , L_11 ) ;
return - V_90 ;
}
F_49 ( V_93 , V_2 ) ;
F_1 ( V_2 ) ;
V_21 = & V_2 -> V_111 ;
F_50 ( V_21 -> V_106 , L_12 , sizeof( V_21 -> V_106 ) ) ;
V_21 -> V_112 = V_113 ;
V_21 -> V_114 = & V_115 ;
V_21 -> V_14 . V_116 = V_14 ;
V_21 -> V_117 = V_93 -> V_118 ;
V_21 -> V_14 . V_89 = V_93 -> V_14 . V_89 ;
F_51 ( V_21 , V_2 ) ;
V_63 = F_52 ( V_21 ) ;
if ( V_63 ) {
F_11 ( V_14 , L_13 , V_63 ) ;
F_3 ( V_119 ,
V_2 -> V_3 + V_120 ) ;
return V_63 ;
}
F_53 ( V_21 ) ;
return 0 ;
}
static int T_7 F_54 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_55 ( V_93 ) ;
int V_54 ;
V_54 = F_56 ( & V_2 -> V_111 ) ;
if ( V_54 )
return - V_107 ;
if ( V_2 -> V_33 )
F_57 ( V_2 -> V_33 ) ;
F_3 ( V_119 , V_2 -> V_3 + V_120 ) ;
F_49 ( V_93 , NULL ) ;
return 0 ;
}
static int T_8 F_58 ( void )
{
return F_59 ( & V_121 , F_34 ) ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_121 ) ;
}
