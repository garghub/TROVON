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
V_20 = F_14 ( V_40 , V_42 , V_47 ) ;
if ( V_20 )
goto V_50;
V_20 = F_15 ( V_40 , V_51 ) ;
if ( V_20 ) {
F_16 ( L_6 ,
V_20 ) ;
F_16 ( L_7 , V_40 ) ;
F_17 ( V_52 , & V_40 -> V_53 . V_54 ) ;
V_20 = - V_55 ;
goto V_50;
}
V_45 = F_18 ( V_40 ) ;
V_45 -> V_56 [ 0 ] = F_19 ( V_41 -> V_57 ) ;
V_45 -> V_58 = 1 ;
V_45 -> V_59 = V_60 ;
V_45 -> V_61 = V_62 ;
V_45 -> V_63 [ 0 ] . V_64 = V_40 -> V_65 -> V_66 ;
V_45 -> V_63 [ 0 ] . V_67 = V_42 -> V_17 ;
V_45 -> V_63 [ 0 ] . V_68 =
F_20 ( V_40 -> V_69 -> V_70 , V_45 -> V_56 [ 0 ] , 0 ,
V_42 -> V_17 , V_62 ) ;
if ( F_21 ( V_40 -> V_69 -> V_70 , V_45 -> V_63 [ 0 ] . V_68 ) ) {
V_20 = - V_71 ;
goto V_72;
}
F_22 ( & V_40 -> V_73 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_74 = ( unsigned long ) V_45 ;
V_49 . V_75 = V_45 -> V_63 ;
V_49 . V_76 = 1 ;
V_49 . V_77 = V_60 ;
V_49 . V_78 = V_79 ;
V_20 = F_23 ( V_40 , & V_49 ) ;
if ( V_20 ) {
V_20 = - V_71 ;
goto V_72;
}
V_50:
F_24 ( V_40 , V_47 ) ;
F_11 ( L_8 , V_24 , V_20 ) ;
return V_20 ;
V_72:
F_25 ( V_45 ) ;
F_26 ( V_45 , 1 ) ;
goto V_50;
}
static void *
F_27 ( struct V_80 * V_81 , T_2 V_82 )
{
struct V_13 * V_41 = V_81 -> V_83 ;
struct V_84 * V_85 = V_41 -> V_86 -> V_87 ;
struct V_39 * V_40 ;
struct V_88 * V_88 ;
V_40 = F_28 ( V_85 , struct V_39 , V_53 ) ;
if ( V_82 > V_89 )
F_29 ( 1 , L_9 ,
V_82 ) ;
V_88 = F_30 ( V_90 ) ;
if ( ! V_88 )
return NULL ;
return F_31 ( V_88 ) ;
}
static void
F_32 ( void * V_91 )
{
}
static int
F_33 ( struct V_39 * V_40 , struct V_13 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_86 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_92 = (struct V_3 * ) V_41 -> V_57 ;
int V_93 ;
V_92 -> V_23 = V_41 -> V_94 ;
V_92 -> V_95 = V_96 ;
V_92 -> V_33 = F_34 ( V_8 -> V_34 . V_35 ) ;
V_92 -> V_97 = V_98 ;
V_92 -> V_99 . V_100 [ 0 ] = V_101 ;
V_92 -> V_99 . V_100 [ 1 ] = V_101 ;
V_92 -> V_99 . V_100 [ 2 ] = V_101 ;
#ifdef F_3
F_4 ( L_10 , V_24 , 64 , V_41 -> V_57 ) ;
#endif
V_93 = F_12 ( V_40 , V_41 ) ;
if ( V_93 )
goto V_102;
return V_93 ;
V_102:
F_11 ( L_11 ) ;
F_35 ( V_2 ) ;
return - V_55 ;
}
static int
F_36 ( struct V_80 * V_81 )
{
struct V_13 * V_41 = V_81 -> V_83 ;
struct V_84 * V_85 = V_41 -> V_86 -> V_87 ;
struct V_39 * V_40 ;
int V_20 ;
F_11 ( L_12 ,
F_5 ( V_41 -> V_94 ) ) ;
if ( ! F_37 ( & V_85 -> V_103 ) ) {
F_38 ( & V_85 -> V_104 , V_81 , NULL ) ;
if ( ! F_37 ( & V_85 -> V_103 ) )
return - V_26 ;
F_39 ( & V_85 -> V_104 , V_81 ) ;
}
V_20 = - V_55 ;
V_40 = F_28 ( V_85 , struct V_39 , V_53 ) ;
if ( ! F_40 ( V_105 , & V_85 -> V_54 ) )
V_20 = F_33 ( V_40 , V_41 ) ;
F_41 ( & V_85 -> V_103 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 )
{
F_11 ( L_13 , V_24 , V_2 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
F_11 ( L_13 , V_24 , V_2 ) ;
F_44 ( V_2 ) ;
F_45 ( V_106 ) ;
}
static struct V_1 *
F_46 ( struct V_107 * args )
{
struct V_1 * V_2 ;
struct V_7 * V_108 ;
if ( args -> V_109 > sizeof( V_2 -> V_68 ) ) {
F_11 ( L_14 , V_24 ) ;
return F_47 ( - V_110 ) ;
}
V_2 = F_48 ( args -> V_111 , sizeof( * V_108 ) ,
V_112 ,
V_112 ) ;
if ( ! V_2 ) {
F_11 ( L_15 ,
V_24 ) ;
return F_47 ( - V_113 ) ;
}
V_2 -> V_114 = & V_115 ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_116 = V_117 ;
V_2 -> V_118 = V_119 ;
V_2 -> V_120 = V_121 ;
V_2 -> V_122 = V_123 ;
V_2 -> V_124 = V_25 / sizeof( T_3 ) ;
V_2 -> V_125 = & V_126 ;
memcpy ( & V_2 -> V_68 , args -> V_127 , args -> V_109 ) ;
V_2 -> V_109 = args -> V_109 ;
F_51 ( V_2 , (struct V_128 * ) & V_2 -> V_68 ) ;
V_2 -> V_129 = 0 ;
V_2 -> V_130 = V_131 ;
V_108 = F_2 ( V_2 ) ;
V_108 -> V_34 . V_35 = V_2 -> V_132 ;
F_52 ( V_2 ) ;
args -> V_87 -> V_133 = V_2 ;
V_2 -> V_87 = args -> V_87 ;
if ( ! F_53 ( V_106 ) )
goto V_134;
F_52 ( V_2 ) ;
return V_2 ;
V_134:
F_54 ( V_2 ) ;
args -> V_87 -> V_133 = NULL ;
F_55 ( V_2 ) ;
F_44 ( V_2 ) ;
return F_47 ( - V_135 ) ;
}
