int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 , * V_11 = & V_6 -> V_12 [ 0 ] ;
struct V_13 * V_14 ;
unsigned long V_15 ;
T_1 V_16 ;
T_2 V_17 ;
T_3 V_18 ;
T_3 * V_19 ;
int V_20 ;
V_19 = ( T_3 * ) V_11 -> V_21 ;
V_17 = V_11 -> V_22 ;
V_18 = V_4 -> V_23 ;
#ifdef F_3
F_4 ( L_1 ,
V_24 , F_5 ( V_18 ) , V_17 ) ;
F_4 ( L_2 ,
V_24 , ( int ) V_25 , V_4 ) ;
F_4 ( L_3 ,
V_24 , ( int ) V_17 , V_19 ) ;
#endif
V_20 = - V_26 ;
if ( V_11 -> V_22 < 24 )
goto V_27;
F_6 ( & V_2 -> V_28 ) ;
V_14 = F_7 ( V_2 , V_18 ) ;
if ( ! V_14 )
goto V_29;
V_10 = & V_14 -> V_30 . V_12 [ 0 ] ;
memcpy ( & V_14 -> V_30 , & V_14 -> V_31 , sizeof( struct V_5 ) ) ;
if ( V_10 -> V_22 < V_17 )
goto V_32;
memcpy ( V_10 -> V_21 , V_19 , V_17 ) ;
V_16 = F_5 ( V_4 -> V_33 ) ;
if ( V_16 == 0 )
V_16 = 1 ;
else if ( V_16 > V_8 -> V_34 . V_35 )
V_16 = V_8 -> V_34 . V_35 ;
V_15 = V_2 -> V_15 ;
V_2 -> V_15 = V_16 << V_36 ;
if ( V_2 -> V_15 > V_15 )
F_8 ( V_14 -> V_37 ) ;
V_20 = 0 ;
F_9 ( V_14 -> V_37 , V_6 -> V_17 ) ;
V_6 -> V_17 = 0 ;
V_32:
F_10 ( & V_2 -> V_28 ) ;
V_38:
return V_20 ;
V_27:
F_11 ( L_4 ,
V_2 , V_11 -> V_22 ) ;
goto V_38;
V_29:
F_11 ( L_5 ,
V_2 , F_5 ( V_18 ) ) ;
goto V_32;
}
static int F_12 ( struct V_39 * V_40 ,
struct V_13 * V_41 )
{
struct V_5 * V_42 = & V_41 -> V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 V_49 ;
int V_20 ;
V_47 = F_13 ( V_40 ) ;
V_20 = F_14 ( V_40 , V_42 , V_47 , false ) ;
if ( V_20 )
goto V_50;
V_20 = F_15 ( V_40 , V_51 ) ;
if ( V_20 )
goto V_50;
V_45 = F_16 ( V_40 ) ;
V_45 -> V_52 [ 0 ] = F_17 ( V_41 -> V_53 ) ;
V_45 -> V_54 = 1 ;
V_45 -> V_55 = V_56 ;
V_45 -> V_57 [ 0 ] . V_58 = V_40 -> V_59 -> V_60 ;
V_45 -> V_57 [ 0 ] . V_61 = V_42 -> V_17 ;
V_45 -> V_57 [ 0 ] . V_62 =
F_18 ( V_40 -> V_63 -> V_64 , V_45 -> V_52 [ 0 ] , 0 ,
V_42 -> V_17 , V_56 ) ;
if ( F_19 ( V_40 -> V_63 -> V_64 , V_45 -> V_57 [ 0 ] . V_62 ) ) {
V_20 = - V_65 ;
goto V_66;
}
F_20 ( V_40 , V_45 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_45 -> V_67 . V_68 = V_69 ;
V_49 . V_70 = & V_45 -> V_67 ;
V_49 . V_71 = V_45 -> V_57 ;
V_49 . V_72 = 1 ;
V_49 . V_73 = V_74 ;
V_49 . V_75 = V_76 ;
V_20 = F_21 ( V_40 , & V_49 ) ;
if ( V_20 ) {
V_20 = - V_65 ;
goto V_66;
}
V_50:
F_22 ( V_40 , V_47 ) ;
F_11 ( L_6 , V_24 , V_20 ) ;
return V_20 ;
V_66:
F_23 ( V_45 ) ;
F_24 ( V_45 , 1 ) ;
goto V_50;
}
static int
F_25 ( struct V_77 * V_78 )
{
struct V_13 * V_41 = V_78 -> V_79 ;
struct V_80 * V_81 = V_41 -> V_82 -> V_83 ;
T_2 V_84 = V_41 -> V_85 ;
struct V_39 * V_40 ;
struct V_86 * V_86 ;
V_40 = F_26 ( V_81 , struct V_39 , V_87 ) ;
if ( V_84 > V_88 ) {
F_27 ( 1 , L_7 ,
V_84 ) ;
return - V_89 ;
}
V_86 = F_28 ( V_90 ) ;
if ( ! V_86 )
return - V_91 ;
V_41 -> V_53 = F_29 ( V_86 ) ;
V_41 -> V_92 = F_30 ( V_41 -> V_93 , V_90 ) ;
if ( ! V_41 -> V_92 ) {
F_31 ( V_86 ) ;
return - V_91 ;
}
return 0 ;
}
static void
F_32 ( struct V_77 * V_78 )
{
struct V_13 * V_41 = V_78 -> V_79 ;
F_33 ( V_41 -> V_92 ) ;
}
static int
F_34 ( struct V_39 * V_40 , struct V_13 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_82 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_94 = (struct V_3 * ) V_41 -> V_53 ;
int V_95 ;
V_94 -> V_23 = V_41 -> V_96 ;
V_94 -> V_97 = V_98 ;
V_94 -> V_33 = F_35 ( V_8 -> V_34 . V_35 ) ;
V_94 -> V_99 = V_100 ;
V_94 -> V_101 . V_102 [ 0 ] = V_103 ;
V_94 -> V_101 . V_102 [ 1 ] = V_103 ;
V_94 -> V_101 . V_102 [ 2 ] = V_103 ;
#ifdef F_3
F_4 ( L_8 , V_24 , 64 , V_41 -> V_53 ) ;
#endif
V_95 = F_12 ( V_40 , V_41 ) ;
if ( V_95 )
goto V_104;
return V_95 ;
V_104:
F_11 ( L_9 ) ;
F_36 ( V_2 ) ;
return - V_105 ;
}
static int
F_37 ( struct V_77 * V_78 )
{
struct V_13 * V_41 = V_78 -> V_79 ;
struct V_80 * V_81 = V_41 -> V_82 -> V_83 ;
struct V_39 * V_40 ;
int V_20 ;
F_11 ( L_10 ,
F_5 ( V_41 -> V_96 ) ) ;
if ( ! F_38 ( & V_81 -> V_106 ) ) {
F_39 ( & V_81 -> V_107 , V_78 , NULL ) ;
if ( ! F_38 ( & V_81 -> V_106 ) )
return - V_26 ;
F_40 ( & V_81 -> V_107 , V_78 ) ;
}
V_20 = - V_105 ;
V_40 = F_26 ( V_81 , struct V_39 , V_87 ) ;
if ( ! F_41 ( V_108 , & V_81 -> V_109 ) )
V_20 = F_34 ( V_40 , V_41 ) ;
F_42 ( & V_81 -> V_106 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
F_11 ( L_11 , V_24 , V_2 ) ;
}
static void
F_44 ( struct V_1 * V_2 )
{
F_11 ( L_11 , V_24 , V_2 ) ;
F_45 ( V_2 ) ;
F_46 ( V_110 ) ;
}
static struct V_1 *
F_47 ( struct V_111 * args )
{
struct V_1 * V_2 ;
struct V_7 * V_112 ;
if ( args -> V_113 > sizeof( V_2 -> V_62 ) ) {
F_11 ( L_12 , V_24 ) ;
return F_48 ( - V_114 ) ;
}
V_2 = F_49 ( args -> V_115 , sizeof( * V_112 ) ,
V_116 ,
V_116 ) ;
if ( ! V_2 ) {
F_11 ( L_13 ,
V_24 ) ;
return F_48 ( - V_91 ) ;
}
V_2 -> V_117 = & V_118 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
V_2 -> V_119 = V_120 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = V_124 ;
V_2 -> V_125 = V_126 ;
V_2 -> V_127 = V_25 / sizeof( T_3 ) ;
V_2 -> V_128 = & V_129 ;
memcpy ( & V_2 -> V_62 , args -> V_130 , args -> V_113 ) ;
V_2 -> V_113 = args -> V_113 ;
F_52 ( V_2 , (struct V_131 * ) & V_2 -> V_62 ) ;
V_2 -> V_132 = 0 ;
V_2 -> V_133 = V_134 ;
V_112 = F_2 ( V_2 ) ;
V_112 -> V_34 . V_35 = V_2 -> V_135 ;
F_53 ( V_2 ) ;
args -> V_83 -> V_136 = V_2 ;
V_2 -> V_83 = args -> V_83 ;
if ( ! F_54 ( V_110 ) )
goto V_137;
F_53 ( V_2 ) ;
return V_2 ;
V_137:
F_55 ( V_2 ) ;
args -> V_83 -> V_136 = NULL ;
F_56 ( V_2 ) ;
F_45 ( V_2 ) ;
return F_48 ( - V_89 ) ;
}
