static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static unsigned int F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static struct V_10 * F_5 ( struct V_11 * V_4 ,
struct V_10 * V_12 )
{
struct V_10 * V_13 ;
V_13 = F_6 ( V_12 , sizeof( struct V_14 ) ) ;
if ( V_13 )
F_7 ( V_13 ) ;
F_8 ( V_12 ) ;
return V_13 ;
}
static void F_9 ( void * V_15 )
{
struct V_1 * V_16 = V_15 ;
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = V_16 -> V_4 . V_5 . V_22 -> V_21 ;
T_1 * V_23 = V_18 -> V_24 ;
int V_25 ;
if ( F_10 ( & V_16 -> V_26 ) != 1 )
return;
V_23 [ 0 ] = F_11 ( 1 ) ;
V_23 [ 1 ] = F_11 ( 0 ) ;
V_25 = F_12 ( V_16 -> V_27 , V_18 , V_28 ) ;
if ( V_25 ) {
F_13 ( & V_16 -> V_26 ) ;
F_14 ( V_21 , L_1 , V_25 ) ;
}
}
static void F_15 ( struct V_29 * V_30 , struct V_17 * V_18 )
{
struct V_1 * V_16 = V_18 -> V_31 ;
struct V_20 * V_21 = V_16 -> V_4 . V_5 . V_22 -> V_21 ;
int V_25 = V_18 -> V_25 ;
switch ( V_25 ) {
case - V_32 :
case - V_33 :
F_16 ( & V_16 -> V_26 , 0 ) ;
break;
default:
F_14 ( V_21 , L_2 ,
V_30 -> V_34 , V_25 ,
V_18 -> V_35 , V_18 -> V_36 ) ;
case 0 :
if ( V_30 != V_16 -> V_27 )
break;
if ( F_17 ( & V_16 -> V_26 ) )
break;
V_25 = F_12 ( V_16 -> V_27 , V_18 , V_28 ) ;
if ( V_25 ) {
F_13 ( & V_16 -> V_26 ) ;
F_14 ( V_21 , L_3 , V_25 ) ;
}
break;
}
}
static void F_18 ( struct V_29 * V_30 , struct V_17 * V_18 )
{
struct V_1 * V_16 = V_18 -> V_31 ;
struct V_20 * V_21 = V_16 -> V_4 . V_5 . V_22 -> V_21 ;
int V_25 ;
V_25 = F_19 ( V_16 -> V_22 , ( V_37 * ) V_18 -> V_24 ) ;
if ( V_25 < 0 )
ERROR ( V_21 , L_4 ,
V_25 , V_18 -> V_35 , V_18 -> V_36 ) ;
}
static int
F_20 ( struct V_2 * V_3 , const struct V_38 * V_39 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_20 * V_21 = V_3 -> V_22 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_18 ;
int V_40 = - V_41 ;
T_2 V_42 = F_21 ( V_39 -> V_43 ) ;
T_2 V_44 = F_21 ( V_39 -> V_45 ) ;
T_2 V_46 = F_21 ( V_39 -> V_47 ) ;
switch ( ( V_39 -> V_48 << 8 ) | V_39 -> V_49 ) {
case ( ( V_50 | V_51 | V_52 ) << 8 )
| V_53 :
if ( V_44 || V_42 != V_16 -> V_54 )
goto V_55;
V_40 = V_46 ;
V_18 -> V_56 = F_18 ;
V_18 -> V_31 = V_16 ;
break;
case ( ( V_57 | V_51 | V_52 ) << 8 )
| V_58 :
if ( V_44 || V_42 != V_16 -> V_54 )
goto V_55;
else {
V_37 * V_24 ;
T_3 V_59 ;
V_24 = F_22 ( V_16 -> V_22 , & V_59 ) ;
if ( V_24 ) {
memcpy ( V_18 -> V_24 , V_24 , V_59 ) ;
V_18 -> V_56 = F_15 ;
F_23 ( V_16 -> V_22 , V_24 ) ;
V_40 = V_59 ;
}
}
break;
default:
V_55:
F_24 ( V_21 , L_5 ,
V_39 -> V_48 , V_39 -> V_49 ,
V_44 , V_42 , V_46 ) ;
}
if ( V_40 >= 0 ) {
F_14 ( V_21 , L_6 ,
V_39 -> V_48 , V_39 -> V_49 ,
V_44 , V_42 , V_46 ) ;
V_18 -> V_60 = ( V_40 < V_46 ) ;
V_18 -> V_36 = V_40 ;
V_40 = F_12 ( V_21 -> V_61 -> V_62 , V_18 , V_28 ) ;
if ( V_40 < 0 )
ERROR ( V_21 , L_7 , V_40 ) ;
}
return V_40 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_63 , unsigned V_64 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_20 * V_21 = V_3 -> V_22 -> V_21 ;
if ( V_63 == V_16 -> V_54 ) {
if ( V_16 -> V_27 -> V_65 ) {
F_24 ( V_21 , L_8 , V_63 ) ;
F_26 ( V_16 -> V_27 ) ;
} else {
F_24 ( V_21 , L_9 , V_63 ) ;
V_16 -> V_66 = F_27 ( V_21 -> V_61 ,
V_16 -> V_67 . V_27 ,
V_16 -> V_68 . V_27 ) ;
}
F_28 ( V_16 -> V_27 , V_16 -> V_66 ) ;
V_16 -> V_27 -> V_65 = V_16 ;
} else if ( V_63 == V_16 -> V_69 ) {
struct V_70 * V_71 ;
if ( V_16 -> V_4 . V_72 -> V_65 ) {
F_14 ( V_21 , L_10 ) ;
F_29 ( & V_16 -> V_4 ) ;
}
if ( ! V_16 -> V_4 . V_73 ) {
F_14 ( V_21 , L_11 ) ;
V_16 -> V_4 . V_73 = F_27 ( V_21 -> V_61 ,
V_16 -> V_67 . V_73 , V_16 -> V_68 . V_73 ) ;
V_16 -> V_4 . V_74 = F_27 ( V_21 -> V_61 ,
V_16 -> V_67 . V_74 , V_16 -> V_68 . V_74 ) ;
}
V_16 -> V_4 . V_75 = false ;
V_16 -> V_4 . V_76 = 0 ;
F_14 ( V_21 , L_12 ) ;
V_71 = F_30 ( & V_16 -> V_4 ) ;
if ( F_31 ( V_71 ) )
return F_32 ( V_71 ) ;
F_33 ( V_16 -> V_22 , V_71 ,
& V_16 -> V_4 . V_76 ) ;
} else
goto V_77;
return 0 ;
V_77:
return - V_78 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_20 * V_21 = V_3 -> V_22 -> V_21 ;
if ( ! V_16 -> V_27 -> V_65 )
return;
F_14 ( V_21 , L_13 ) ;
F_35 ( V_16 -> V_22 ) ;
F_29 ( & V_16 -> V_4 ) ;
F_26 ( V_16 -> V_27 ) ;
V_16 -> V_27 -> V_65 = NULL ;
}
static void F_36 ( struct V_11 * V_79 )
{
struct V_1 * V_16 = F_1 ( & V_79 -> V_5 ) ;
struct V_20 * V_21 = V_79 -> V_5 . V_22 -> V_21 ;
F_14 ( V_21 , L_14 , V_80 ) ;
F_37 ( V_16 -> V_22 , V_81 ,
F_3 ( V_21 -> V_61 ) / 100 ) ;
F_38 ( V_16 -> V_22 ) ;
}
static void F_39 ( struct V_11 * V_79 )
{
struct V_1 * V_16 = F_1 ( & V_79 -> V_5 ) ;
F_14 ( V_79 -> V_5 . V_22 -> V_21 , L_14 , V_80 ) ;
F_37 ( V_16 -> V_22 , V_81 , 0 ) ;
F_40 ( V_16 -> V_22 ) ;
}
static int
F_41 ( struct V_82 * V_83 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_83 -> V_21 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_25 ;
struct V_29 * V_30 ;
V_25 = F_42 ( V_83 , V_3 ) ;
if ( V_25 < 0 )
goto V_77;
V_16 -> V_54 = V_25 ;
V_84 . V_85 = V_25 ;
V_86 . V_87 = V_25 ;
V_88 . V_89 = V_25 ;
V_25 = F_42 ( V_83 , V_3 ) ;
if ( V_25 < 0 )
goto V_77;
V_16 -> V_69 = V_25 ;
V_90 . V_87 = V_25 ;
V_88 . V_91 = V_25 ;
V_25 = - V_92 ;
V_30 = F_43 ( V_21 -> V_61 , & V_93 ) ;
if ( ! V_30 )
goto V_77;
V_16 -> V_4 . V_72 = V_30 ;
V_30 -> V_65 = V_21 ;
V_30 = F_43 ( V_21 -> V_61 , & V_94 ) ;
if ( ! V_30 )
goto V_77;
V_16 -> V_4 . V_95 = V_30 ;
V_30 -> V_65 = V_21 ;
V_30 = F_43 ( V_21 -> V_61 , & V_96 ) ;
if ( ! V_30 )
goto V_77;
V_16 -> V_27 = V_30 ;
V_30 -> V_65 = V_21 ;
V_25 = - V_97 ;
V_16 -> V_19 = F_44 ( V_30 , V_98 ) ;
if ( ! V_16 -> V_19 )
goto V_77;
V_16 -> V_19 -> V_24 = F_45 ( V_99 , V_98 ) ;
if ( ! V_16 -> V_19 -> V_24 )
goto V_77;
V_16 -> V_19 -> V_36 = V_99 ;
V_16 -> V_19 -> V_31 = V_16 ;
V_16 -> V_19 -> V_56 = F_15 ;
V_3 -> V_100 = F_46 ( V_101 ) ;
if ( ! V_3 -> V_100 )
goto V_77;
V_16 -> V_68 . V_73 = F_47 ( V_101 ,
V_3 -> V_100 , & V_93 ) ;
V_16 -> V_68 . V_74 = F_47 ( V_101 ,
V_3 -> V_100 , & V_94 ) ;
V_16 -> V_68 . V_27 = F_47 ( V_101 ,
V_3 -> V_100 , & V_96 ) ;
if ( F_4 ( V_83 -> V_21 -> V_61 ) ) {
V_102 . V_103 =
V_93 . V_103 ;
V_104 . V_103 =
V_94 . V_103 ;
V_105 . V_103 =
V_96 . V_103 ;
V_3 -> V_106 = F_46 ( V_107 ) ;
if ( ! V_3 -> V_106 )
goto V_77;
V_16 -> V_67 . V_73 = F_47 ( V_107 ,
V_3 -> V_106 , & V_102 ) ;
V_16 -> V_67 . V_74 = F_47 ( V_107 ,
V_3 -> V_106 , & V_104 ) ;
V_16 -> V_67 . V_27 = F_47 ( V_107 ,
V_3 -> V_106 , & V_105 ) ;
}
V_16 -> V_4 . V_108 = F_36 ;
V_16 -> V_4 . V_109 = F_39 ;
V_25 = F_48 ( F_9 , V_16 ) ;
if ( V_25 < 0 )
goto V_77;
V_16 -> V_22 = V_25 ;
F_37 ( V_16 -> V_22 , V_81 , 0 ) ;
F_49 ( V_16 -> V_22 , V_16 -> V_110 ) ;
#if 0
if (rndis_set_param_vendor(rndis->config, vendorID,
manufacturer))
goto fail0;
#endif
F_14 ( V_21 , L_15 ,
F_4 ( V_83 -> V_21 -> V_61 ) ? L_16 : L_17 ,
V_16 -> V_4 . V_72 -> V_34 , V_16 -> V_4 . V_95 -> V_34 ,
V_16 -> V_27 -> V_34 ) ;
return 0 ;
V_77:
if ( F_4 ( V_83 -> V_21 -> V_61 ) && V_3 -> V_106 )
F_50 ( V_3 -> V_106 ) ;
if ( V_3 -> V_100 )
F_50 ( V_3 -> V_100 ) ;
if ( V_16 -> V_19 ) {
F_51 ( V_16 -> V_19 -> V_24 ) ;
F_52 ( V_16 -> V_27 , V_16 -> V_19 ) ;
}
if ( V_16 -> V_27 )
V_16 -> V_27 -> V_65 = NULL ;
if ( V_16 -> V_4 . V_74 )
V_16 -> V_4 . V_95 -> V_65 = NULL ;
if ( V_16 -> V_4 . V_73 )
V_16 -> V_4 . V_72 -> V_65 = NULL ;
ERROR ( V_21 , L_18 , V_3 -> V_34 , V_25 ) ;
return V_25 ;
}
static void
F_53 ( struct V_82 * V_83 , struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
F_54 ( V_16 -> V_22 ) ;
F_55 () ;
if ( F_4 ( V_83 -> V_21 -> V_61 ) )
F_50 ( V_3 -> V_106 ) ;
F_50 ( V_3 -> V_100 ) ;
F_51 ( V_16 -> V_19 -> V_24 ) ;
F_52 ( V_16 -> V_27 , V_16 -> V_19 ) ;
F_51 ( V_16 ) ;
}
static inline bool F_56 ( struct V_82 * V_83 )
{
return true ;
}
int
F_57 ( struct V_82 * V_83 , V_37 V_110 [ V_111 ] )
{
struct V_1 * V_16 ;
int V_25 ;
if ( ! F_56 ( V_83 ) || ! V_110 )
return - V_78 ;
if ( V_112 [ 0 ] . V_113 == 0 ) {
V_25 = F_58 () ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_59 ( V_83 -> V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
V_112 [ 0 ] . V_113 = V_25 ;
V_86 . V_114 = V_25 ;
V_25 = F_59 ( V_83 -> V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
V_112 [ 1 ] . V_113 = V_25 ;
V_90 . V_114 = V_25 ;
V_25 = F_59 ( V_83 -> V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
V_112 [ 2 ] . V_113 = V_25 ;
V_84 . V_115 = V_25 ;
}
V_25 = - V_97 ;
V_16 = F_60 ( sizeof *V_16 , V_98 ) ;
if ( ! V_16 )
goto V_77;
memcpy ( V_16 -> V_110 , V_110 , V_111 ) ;
V_16 -> V_4 . V_76 = 0 ;
V_16 -> V_4 . V_116 = sizeof( struct V_14 ) ;
V_16 -> V_4 . V_117 = F_5 ;
V_16 -> V_4 . V_118 = V_119 ;
V_16 -> V_4 . V_5 . V_34 = L_19 ;
V_16 -> V_4 . V_5 . V_120 = V_121 ;
V_16 -> V_4 . V_5 . V_122 = F_41 ;
V_16 -> V_4 . V_5 . V_123 = F_53 ;
V_16 -> V_4 . V_5 . V_124 = F_25 ;
V_16 -> V_4 . V_5 . V_125 = F_20 ;
V_16 -> V_4 . V_5 . V_126 = F_34 ;
V_25 = F_61 ( V_83 , & V_16 -> V_4 . V_5 ) ;
if ( V_25 ) {
F_51 ( V_16 ) ;
V_77:
F_55 () ;
}
return V_25 ;
}
