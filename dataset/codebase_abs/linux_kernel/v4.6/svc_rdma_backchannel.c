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
F_20 ( & V_40 -> V_67 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_45 -> V_68 . V_69 = V_70 ;
V_49 . V_71 = & V_45 -> V_68 ;
V_49 . V_72 = V_45 -> V_57 ;
V_49 . V_73 = 1 ;
V_49 . V_74 = V_75 ;
V_49 . V_76 = V_77 ;
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
static void *
F_25 ( struct V_78 * V_79 , T_2 V_80 )
{
struct V_13 * V_41 = V_79 -> V_81 ;
struct V_82 * V_83 = V_41 -> V_84 -> V_85 ;
struct V_39 * V_40 ;
struct V_86 * V_86 ;
V_40 = F_26 ( V_83 , struct V_39 , V_87 ) ;
if ( V_80 > V_88 )
F_27 ( 1 , L_7 ,
V_80 ) ;
V_86 = F_28 ( V_89 ) ;
if ( ! V_86 )
return NULL ;
return F_29 ( V_86 ) ;
}
static void
F_30 ( void * V_90 )
{
}
static int
F_31 ( struct V_39 * V_40 , struct V_13 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_84 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_91 = (struct V_3 * ) V_41 -> V_53 ;
int V_92 ;
V_91 -> V_23 = V_41 -> V_93 ;
V_91 -> V_94 = V_95 ;
V_91 -> V_33 = F_32 ( V_8 -> V_34 . V_35 ) ;
V_91 -> V_96 = V_97 ;
V_91 -> V_98 . V_99 [ 0 ] = V_100 ;
V_91 -> V_98 . V_99 [ 1 ] = V_100 ;
V_91 -> V_98 . V_99 [ 2 ] = V_100 ;
#ifdef F_3
F_4 ( L_8 , V_24 , 64 , V_41 -> V_53 ) ;
#endif
V_92 = F_12 ( V_40 , V_41 ) ;
if ( V_92 )
goto V_101;
return V_92 ;
V_101:
F_11 ( L_9 ) ;
F_33 ( V_2 ) ;
return - V_102 ;
}
static int
F_34 ( struct V_78 * V_79 )
{
struct V_13 * V_41 = V_79 -> V_81 ;
struct V_82 * V_83 = V_41 -> V_84 -> V_85 ;
struct V_39 * V_40 ;
int V_20 ;
F_11 ( L_10 ,
F_5 ( V_41 -> V_93 ) ) ;
if ( ! F_35 ( & V_83 -> V_103 ) ) {
F_36 ( & V_83 -> V_104 , V_79 , NULL ) ;
if ( ! F_35 ( & V_83 -> V_103 ) )
return - V_26 ;
F_37 ( & V_83 -> V_104 , V_79 ) ;
}
V_20 = - V_102 ;
V_40 = F_26 ( V_83 , struct V_39 , V_87 ) ;
if ( ! F_38 ( V_105 , & V_83 -> V_106 ) )
V_20 = F_31 ( V_40 , V_41 ) ;
F_39 ( & V_83 -> V_103 ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
F_11 ( L_11 , V_24 , V_2 ) ;
}
static void
F_41 ( struct V_1 * V_2 )
{
F_11 ( L_11 , V_24 , V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_107 ) ;
}
static struct V_1 *
F_44 ( struct V_108 * args )
{
struct V_1 * V_2 ;
struct V_7 * V_109 ;
if ( args -> V_110 > sizeof( V_2 -> V_62 ) ) {
F_11 ( L_12 , V_24 ) ;
return F_45 ( - V_111 ) ;
}
V_2 = F_46 ( args -> V_112 , sizeof( * V_109 ) ,
V_113 ,
V_113 ) ;
if ( ! V_2 ) {
F_11 ( L_13 ,
V_24 ) ;
return F_45 ( - V_114 ) ;
}
V_2 -> V_115 = & V_116 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_117 = V_118 ;
V_2 -> V_119 = V_120 ;
V_2 -> V_121 = V_122 ;
V_2 -> V_123 = V_124 ;
V_2 -> V_125 = V_25 / sizeof( T_3 ) ;
V_2 -> V_126 = & V_127 ;
memcpy ( & V_2 -> V_62 , args -> V_128 , args -> V_110 ) ;
V_2 -> V_110 = args -> V_110 ;
F_49 ( V_2 , (struct V_129 * ) & V_2 -> V_62 ) ;
V_2 -> V_130 = 0 ;
V_2 -> V_131 = V_132 ;
V_109 = F_2 ( V_2 ) ;
V_109 -> V_34 . V_35 = V_2 -> V_133 ;
F_50 ( V_2 ) ;
args -> V_85 -> V_134 = V_2 ;
V_2 -> V_85 = args -> V_85 ;
if ( ! F_51 ( V_107 ) )
goto V_135;
F_50 ( V_2 ) ;
return V_2 ;
V_135:
F_52 ( V_2 ) ;
args -> V_85 -> V_134 = NULL ;
F_53 ( V_2 ) ;
F_42 ( V_2 ) ;
return F_45 ( - V_136 ) ;
}
