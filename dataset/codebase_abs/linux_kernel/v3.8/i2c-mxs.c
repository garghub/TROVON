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
F_22 ( V_2 -> V_19 ) ;
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
return V_64 | V_65 ;
}
static T_3 F_27 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
T_2 V_68 = F_28 ( V_2 -> V_3 + V_69 ) & V_11 ;
if ( ! V_68 )
return V_70 ;
if ( V_68 & V_71 )
V_2 -> V_56 = - V_58 ;
else if ( V_68 & ( V_72 |
V_73 |
V_74 | V_75 ) )
V_2 -> V_56 = - V_76 ;
F_3 ( V_68 , V_2 -> V_3 + V_77 ) ;
return V_78 ;
}
static bool F_29 ( struct V_79 * V_80 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
if ( ! F_30 ( V_80 ) )
return false ;
if ( V_80 -> V_81 != V_2 -> V_82 )
return false ;
V_80 -> V_83 = & V_2 -> V_84 ;
return true ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_4 ;
struct V_85 * V_14 = V_2 -> V_14 ;
struct V_86 * V_87 = V_14 -> V_88 ;
int V_54 ;
V_54 = F_32 ( V_87 , L_6 ,
& V_2 -> V_82 ) ;
if ( V_54 ) {
F_11 ( V_14 , L_7 ) ;
return - V_89 ;
}
V_54 = F_32 ( V_87 , L_8 , & V_4 ) ;
if ( V_54 )
F_33 ( V_14 , L_9 ) ;
else if ( V_4 == 400000 )
V_2 -> V_4 = & V_90 ;
else if ( V_4 != 100000 )
F_33 ( V_14 , L_10 ) ;
return 0 ;
}
static int F_34 ( struct V_91 * V_92 )
{
struct V_85 * V_14 = & V_92 -> V_14 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_93 * V_93 ;
struct V_94 * V_95 ;
T_4 V_96 ;
int V_63 , V_97 , V_98 ;
T_5 V_99 ;
V_93 = F_35 ( V_14 ) ;
if ( F_36 ( V_93 ) )
return F_37 ( V_93 ) ;
V_2 = F_38 ( V_14 , sizeof( struct V_1 ) , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_95 = F_39 ( V_92 , V_102 , 0 ) ;
V_97 = F_40 ( V_92 , 0 ) ;
V_98 = F_40 ( V_92 , 1 ) ;
if ( ! V_95 || V_97 < 0 || V_98 < 0 )
return - V_103 ;
V_96 = F_41 ( V_95 ) ;
if ( ! F_42 ( V_14 , V_95 -> V_104 , V_96 , V_95 -> V_105 ) )
return - V_106 ;
V_2 -> V_3 = F_43 ( V_14 , V_95 -> V_104 , V_96 ) ;
if ( ! V_2 -> V_3 )
return - V_106 ;
V_63 = F_44 ( V_14 , V_97 , F_27 , 0 , F_45 ( V_14 ) , V_2 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_4 = & V_107 ;
F_46 ( & V_2 -> V_19 ) ;
if ( V_14 -> V_88 ) {
V_63 = F_31 ( V_2 ) ;
if ( V_63 )
return V_63 ;
}
F_47 ( V_99 ) ;
F_48 ( V_108 , V_99 ) ;
V_2 -> V_84 . V_109 = V_98 ;
V_2 -> V_33 = F_49 ( V_99 , F_29 , V_2 ) ;
if ( ! V_2 -> V_33 ) {
F_11 ( V_14 , L_11 ) ;
return - V_89 ;
}
F_50 ( V_92 , V_2 ) ;
F_1 ( V_2 ) ;
V_21 = & V_2 -> V_110 ;
F_51 ( V_21 -> V_105 , L_12 , sizeof( V_21 -> V_105 ) ) ;
V_21 -> V_111 = V_112 ;
V_21 -> V_113 = & V_114 ;
V_21 -> V_14 . V_115 = V_14 ;
V_21 -> V_116 = V_92 -> V_117 ;
V_21 -> V_14 . V_88 = V_92 -> V_14 . V_88 ;
F_52 ( V_21 , V_2 ) ;
V_63 = F_53 ( V_21 ) ;
if ( V_63 ) {
F_11 ( V_14 , L_13 , V_63 ) ;
F_3 ( V_118 ,
V_2 -> V_3 + V_119 ) ;
return V_63 ;
}
F_54 ( V_21 ) ;
return 0 ;
}
static int F_55 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_56 ( V_92 ) ;
int V_54 ;
V_54 = F_57 ( & V_2 -> V_110 ) ;
if ( V_54 )
return - V_106 ;
if ( V_2 -> V_33 )
F_58 ( V_2 -> V_33 ) ;
F_3 ( V_118 , V_2 -> V_3 + V_119 ) ;
F_50 ( V_92 , NULL ) ;
return 0 ;
}
static int T_6 F_59 ( void )
{
return F_60 ( & V_120 , F_34 ) ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_120 ) ;
}
