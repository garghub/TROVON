int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 , * V_10 = & V_5 -> V_11 [ 0 ] ;
struct V_12 * V_13 ;
unsigned long V_14 ;
T_2 V_15 ;
T_3 V_16 ;
T_1 V_17 ;
T_1 * V_18 ;
int V_19 ;
V_18 = ( T_1 * ) V_10 -> V_20 ;
V_16 = V_10 -> V_21 ;
V_17 = * V_3 ;
#ifdef F_3
F_4 ( L_1 ,
V_22 , F_5 ( V_17 ) , V_16 ) ;
F_4 ( L_2 ,
V_22 , ( int ) V_23 , V_3 ) ;
F_4 ( L_3 ,
V_22 , ( int ) V_16 , V_18 ) ;
#endif
V_19 = - V_24 ;
if ( V_10 -> V_21 < 24 )
goto V_25;
F_6 ( & V_2 -> V_26 ) ;
V_13 = F_7 ( V_2 , V_17 ) ;
if ( ! V_13 )
goto V_27;
V_9 = & V_13 -> V_28 . V_11 [ 0 ] ;
memcpy ( & V_13 -> V_28 , & V_13 -> V_29 , sizeof( struct V_4 ) ) ;
if ( V_9 -> V_21 < V_16 )
goto V_30;
memcpy ( V_9 -> V_20 , V_18 , V_16 ) ;
V_15 = F_8 ( V_3 + 2 ) ;
if ( V_15 == 0 )
V_15 = 1 ;
else if ( V_15 > V_7 -> V_31 . V_32 )
V_15 = V_7 -> V_31 . V_32 ;
F_9 ( & V_2 -> V_33 ) ;
V_14 = V_2 -> V_14 ;
V_2 -> V_14 = V_15 << V_34 ;
if ( V_2 -> V_14 > V_14 )
F_10 ( V_13 -> V_35 ) ;
F_11 ( & V_2 -> V_33 ) ;
V_19 = 0 ;
F_12 ( V_13 -> V_35 , V_5 -> V_16 ) ;
V_5 -> V_16 = 0 ;
V_30:
F_13 ( & V_2 -> V_26 ) ;
V_36:
return V_19 ;
V_25:
F_14 ( L_4 ,
V_2 , V_10 -> V_21 ) ;
goto V_36;
V_27:
F_14 ( L_5 ,
V_2 , F_5 ( V_17 ) ) ;
goto V_30;
}
static int F_15 ( struct V_37 * V_38 ,
struct V_12 * V_39 )
{
struct V_40 * V_41 ;
int V_19 ;
V_41 = F_16 ( V_38 ) ;
V_19 = F_17 ( V_38 , V_41 , V_39 -> V_42 ,
V_39 -> V_43 . V_16 ) ;
if ( V_19 < 0 )
goto V_44;
V_19 = F_18 ( V_38 , V_45 ) ;
if ( V_19 )
goto V_44;
V_19 = F_19 ( V_38 , V_41 , 1 , 0 ) ;
if ( V_19 )
goto V_46;
V_44:
F_14 ( L_6 , V_22 , V_19 ) ;
return V_19 ;
V_46:
F_20 ( V_41 ) ;
F_21 ( V_41 , 1 ) ;
V_19 = - V_47 ;
goto V_44;
}
static int
F_22 ( struct V_48 * V_49 )
{
struct V_12 * V_39 = V_49 -> V_50 ;
T_3 V_51 = V_39 -> V_52 ;
struct V_53 * V_53 ;
if ( V_51 > V_54 ) {
F_23 ( 1 , L_7 ,
V_51 ) ;
return - V_55 ;
}
V_53 = F_24 ( V_56 ) ;
if ( ! V_53 )
return - V_57 ;
V_39 -> V_42 = F_25 ( V_53 ) ;
V_39 -> V_58 = F_26 ( V_39 -> V_59 , V_56 ) ;
if ( ! V_39 -> V_58 ) {
F_27 ( V_53 ) ;
return - V_57 ;
}
return 0 ;
}
static void
F_28 ( struct V_48 * V_49 )
{
struct V_12 * V_39 = V_49 -> V_50 ;
F_29 ( V_39 -> V_58 ) ;
}
static int
F_30 ( struct V_37 * V_38 , struct V_12 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_60 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 * V_18 ;
int V_61 ;
V_18 = V_39 -> V_42 ;
* V_18 ++ = V_39 -> V_62 ;
* V_18 ++ = V_63 ;
* V_18 ++ = F_31 ( V_7 -> V_31 . V_32 ) ;
* V_18 ++ = V_64 ;
* V_18 ++ = V_65 ;
* V_18 ++ = V_65 ;
* V_18 = V_65 ;
#ifdef F_3
F_4 ( L_8 , V_22 , 64 , V_39 -> V_42 ) ;
#endif
V_61 = F_15 ( V_38 , V_39 ) ;
if ( V_61 )
goto V_66;
return V_61 ;
V_66:
F_14 ( L_9 ) ;
F_32 ( V_2 ) ;
return - V_67 ;
}
static int
F_33 ( struct V_48 * V_49 )
{
struct V_12 * V_39 = V_49 -> V_50 ;
struct V_68 * V_69 = V_39 -> V_60 -> V_70 ;
struct V_37 * V_38 ;
int V_19 ;
F_14 ( L_10 ,
F_5 ( V_39 -> V_62 ) ) ;
if ( ! F_34 ( & V_69 -> V_71 ) ) {
F_35 ( & V_69 -> V_72 , V_49 , NULL ) ;
if ( ! F_34 ( & V_69 -> V_71 ) )
return - V_24 ;
F_36 ( & V_69 -> V_72 , V_49 ) ;
}
V_19 = - V_67 ;
V_38 = F_37 ( V_69 , struct V_37 , V_73 ) ;
if ( ! F_38 ( V_74 , & V_69 -> V_75 ) )
V_19 = F_30 ( V_38 , V_39 ) ;
F_39 ( & V_69 -> V_71 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
F_14 ( L_11 , V_22 , V_2 ) ;
}
static void
F_41 ( struct V_1 * V_2 )
{
F_14 ( L_11 , V_22 , V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_76 ) ;
}
static struct V_1 *
F_44 ( struct V_77 * args )
{
struct V_1 * V_2 ;
struct V_6 * V_78 ;
if ( args -> V_79 > sizeof( V_2 -> V_80 ) ) {
F_14 ( L_12 , V_22 ) ;
return F_45 ( - V_81 ) ;
}
V_2 = F_46 ( args -> V_82 , sizeof( * V_78 ) ,
V_83 ,
V_83 ) ;
if ( ! V_2 ) {
F_14 ( L_13 ,
V_22 ) ;
return F_45 ( - V_57 ) ;
}
V_2 -> V_84 = & V_85 ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_89 ;
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = V_23 / sizeof( T_1 ) ;
V_2 -> V_95 = & V_96 ;
memcpy ( & V_2 -> V_80 , args -> V_97 , args -> V_79 ) ;
V_2 -> V_79 = args -> V_79 ;
F_49 ( V_2 , (struct V_98 * ) & V_2 -> V_80 ) ;
V_2 -> V_99 = 0 ;
V_2 -> V_100 = V_101 ;
V_78 = F_2 ( V_2 ) ;
V_78 -> V_31 . V_32 = V_2 -> V_102 ;
F_50 ( V_2 ) ;
args -> V_70 -> V_103 = V_2 ;
V_2 -> V_70 = args -> V_70 ;
if ( ! F_51 ( V_76 ) )
goto V_104;
F_50 ( V_2 ) ;
return V_2 ;
V_104:
F_52 ( V_2 ) ;
args -> V_70 -> V_103 = NULL ;
args -> V_70 -> V_105 = NULL ;
F_53 ( V_2 ) ;
F_42 ( V_2 ) ;
return F_45 ( - V_55 ) ;
}
