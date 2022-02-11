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
V_14 = V_2 -> V_14 ;
V_2 -> V_14 = V_15 << V_33 ;
if ( V_2 -> V_14 > V_14 )
F_9 ( V_13 -> V_34 ) ;
V_19 = 0 ;
F_10 ( V_13 -> V_34 , V_5 -> V_16 ) ;
V_5 -> V_16 = 0 ;
V_30:
F_11 ( & V_2 -> V_26 ) ;
V_35:
return V_19 ;
V_25:
F_12 ( L_4 ,
V_2 , V_10 -> V_21 ) ;
goto V_35;
V_27:
F_12 ( L_5 ,
V_2 , F_5 ( V_17 ) ) ;
goto V_30;
}
static int F_13 ( struct V_36 * V_37 ,
struct V_12 * V_38 )
{
struct V_39 * V_40 ;
int V_19 ;
V_40 = F_14 ( V_37 ) ;
V_19 = F_15 ( V_37 , V_40 , V_38 -> V_41 ,
V_38 -> V_42 . V_16 ) ;
if ( V_19 < 0 )
goto V_43;
V_19 = F_16 ( V_37 , V_44 ) ;
if ( V_19 )
goto V_43;
V_19 = F_17 ( V_37 , V_40 , 1 , 0 ) ;
if ( V_19 )
goto V_45;
V_43:
F_12 ( L_6 , V_22 , V_19 ) ;
return V_19 ;
V_45:
F_18 ( V_40 ) ;
F_19 ( V_40 , 1 ) ;
V_19 = - V_46 ;
goto V_43;
}
static int
F_20 ( struct V_47 * V_48 )
{
struct V_12 * V_38 = V_48 -> V_49 ;
T_3 V_50 = V_38 -> V_51 ;
struct V_52 * V_52 ;
if ( V_50 > V_53 ) {
F_21 ( 1 , L_7 ,
V_50 ) ;
return - V_54 ;
}
V_52 = F_22 ( V_55 ) ;
if ( ! V_52 )
return - V_56 ;
V_38 -> V_41 = F_23 ( V_52 ) ;
V_38 -> V_57 = F_24 ( V_38 -> V_58 , V_55 ) ;
if ( ! V_38 -> V_57 ) {
F_25 ( V_52 ) ;
return - V_56 ;
}
return 0 ;
}
static void
F_26 ( struct V_47 * V_48 )
{
struct V_12 * V_38 = V_48 -> V_49 ;
F_27 ( V_38 -> V_57 ) ;
}
static int
F_28 ( struct V_36 * V_37 , struct V_12 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_59 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 * V_18 ;
int V_60 ;
V_18 = V_38 -> V_41 ;
* V_18 ++ = V_38 -> V_61 ;
* V_18 ++ = V_62 ;
* V_18 ++ = F_29 ( V_7 -> V_31 . V_32 ) ;
* V_18 ++ = V_63 ;
* V_18 ++ = V_64 ;
* V_18 ++ = V_64 ;
* V_18 = V_64 ;
#ifdef F_3
F_4 ( L_8 , V_22 , 64 , V_38 -> V_41 ) ;
#endif
V_60 = F_13 ( V_37 , V_38 ) ;
if ( V_60 )
goto V_65;
return V_60 ;
V_65:
F_12 ( L_9 ) ;
F_30 ( V_2 ) ;
return - V_66 ;
}
static int
F_31 ( struct V_47 * V_48 )
{
struct V_12 * V_38 = V_48 -> V_49 ;
struct V_67 * V_68 = V_38 -> V_59 -> V_69 ;
struct V_36 * V_37 ;
int V_19 ;
F_12 ( L_10 ,
F_5 ( V_38 -> V_61 ) ) ;
if ( ! F_32 ( & V_68 -> V_70 ) ) {
F_33 ( & V_68 -> V_71 , V_48 , NULL ) ;
if ( ! F_32 ( & V_68 -> V_70 ) )
return - V_24 ;
F_34 ( & V_68 -> V_71 , V_48 ) ;
}
V_19 = - V_66 ;
V_37 = F_35 ( V_68 , struct V_36 , V_72 ) ;
if ( ! F_36 ( V_73 , & V_68 -> V_74 ) )
V_19 = F_28 ( V_37 , V_38 ) ;
F_37 ( & V_68 -> V_70 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static void
F_38 ( struct V_1 * V_2 )
{
F_12 ( L_11 , V_22 , V_2 ) ;
}
static void
F_39 ( struct V_1 * V_2 )
{
F_12 ( L_11 , V_22 , V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_75 ) ;
}
static struct V_1 *
F_42 ( struct V_76 * args )
{
struct V_1 * V_2 ;
struct V_6 * V_77 ;
if ( args -> V_78 > sizeof( V_2 -> V_79 ) ) {
F_12 ( L_12 , V_22 ) ;
return F_43 ( - V_80 ) ;
}
V_2 = F_44 ( args -> V_81 , sizeof( * V_77 ) ,
V_82 ,
V_82 ) ;
if ( ! V_2 ) {
F_12 ( L_13 ,
V_22 ) ;
return F_43 ( - V_56 ) ;
}
V_2 -> V_83 = & V_84 ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
V_2 -> V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
V_2 -> V_89 = V_90 ;
V_2 -> V_91 = V_92 ;
V_2 -> V_93 = V_23 / sizeof( T_1 ) ;
V_2 -> V_94 = & V_95 ;
memcpy ( & V_2 -> V_79 , args -> V_96 , args -> V_78 ) ;
V_2 -> V_78 = args -> V_78 ;
F_47 ( V_2 , (struct V_97 * ) & V_2 -> V_79 ) ;
V_2 -> V_98 = 0 ;
V_2 -> V_99 = V_100 ;
V_77 = F_2 ( V_2 ) ;
V_77 -> V_31 . V_32 = V_2 -> V_101 ;
F_48 ( V_2 ) ;
args -> V_69 -> V_102 = V_2 ;
V_2 -> V_69 = args -> V_69 ;
if ( ! F_49 ( V_75 ) )
goto V_103;
F_48 ( V_2 ) ;
return V_2 ;
V_103:
F_50 ( V_2 ) ;
args -> V_69 -> V_102 = NULL ;
args -> V_69 -> V_104 = NULL ;
F_51 ( V_2 ) ;
F_40 ( V_2 ) ;
return F_43 ( - V_54 ) ;
}
