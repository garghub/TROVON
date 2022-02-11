static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static unsigned int F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 1024 * 8 * 1000 * 8 ;
else if ( F_5 ( V_7 ) && V_7 -> V_8 == V_10 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static struct V_11 * F_6 ( struct V_12 * V_4 ,
struct V_11 * V_13 )
{
struct V_11 * V_14 ;
V_14 = F_7 ( V_13 , sizeof( struct V_15 ) ) ;
if ( V_14 )
F_8 ( V_14 ) ;
F_9 ( V_13 ) ;
return V_14 ;
}
static void F_10 ( void * V_16 )
{
struct V_1 * V_17 = V_16 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_21 * V_22 = V_17 -> V_4 . V_5 . V_23 -> V_22 ;
T_1 * V_24 = V_19 -> V_25 ;
int V_26 ;
if ( F_11 ( & V_17 -> V_27 ) != 1 )
return;
V_24 [ 0 ] = F_12 ( 1 ) ;
V_24 [ 1 ] = F_12 ( 0 ) ;
V_26 = F_13 ( V_17 -> V_28 , V_19 , V_29 ) ;
if ( V_26 ) {
F_14 ( & V_17 -> V_27 ) ;
F_15 ( V_22 , L_1 , V_26 ) ;
}
}
static void F_16 ( struct V_30 * V_31 , struct V_18 * V_19 )
{
struct V_1 * V_17 = V_19 -> V_32 ;
struct V_21 * V_22 = V_17 -> V_4 . V_5 . V_23 -> V_22 ;
int V_26 = V_19 -> V_26 ;
switch ( V_26 ) {
case - V_33 :
case - V_34 :
F_17 ( & V_17 -> V_27 , 0 ) ;
break;
default:
F_15 ( V_22 , L_2 ,
V_31 -> V_35 , V_26 ,
V_19 -> V_36 , V_19 -> V_37 ) ;
case 0 :
if ( V_31 != V_17 -> V_28 )
break;
if ( F_18 ( & V_17 -> V_27 ) )
break;
V_26 = F_13 ( V_17 -> V_28 , V_19 , V_29 ) ;
if ( V_26 ) {
F_14 ( & V_17 -> V_27 ) ;
F_15 ( V_22 , L_3 , V_26 ) ;
}
break;
}
}
static void F_19 ( struct V_30 * V_31 , struct V_18 * V_19 )
{
struct V_1 * V_17 = V_19 -> V_32 ;
struct V_21 * V_22 = V_17 -> V_4 . V_5 . V_23 -> V_22 ;
int V_26 ;
V_26 = F_20 ( V_17 -> V_23 , ( V_38 * ) V_19 -> V_25 ) ;
if ( V_26 < 0 )
ERROR ( V_22 , L_4 ,
V_26 , V_19 -> V_36 , V_19 -> V_37 ) ;
}
static int
F_21 ( struct V_2 * V_3 , const struct V_39 * V_40 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
struct V_18 * V_19 = V_22 -> V_19 ;
int V_41 = - V_42 ;
T_2 V_43 = F_22 ( V_40 -> V_44 ) ;
T_2 V_45 = F_22 ( V_40 -> V_46 ) ;
T_2 V_47 = F_22 ( V_40 -> V_48 ) ;
switch ( ( V_40 -> V_49 << 8 ) | V_40 -> V_50 ) {
case ( ( V_51 | V_52 | V_53 ) << 8 )
| V_54 :
if ( V_45 || V_43 != V_17 -> V_55 )
goto V_56;
V_41 = V_47 ;
V_19 -> V_57 = F_19 ;
V_19 -> V_32 = V_17 ;
break;
case ( ( V_58 | V_52 | V_53 ) << 8 )
| V_59 :
if ( V_45 || V_43 != V_17 -> V_55 )
goto V_56;
else {
V_38 * V_25 ;
T_3 V_60 ;
V_25 = F_23 ( V_17 -> V_23 , & V_60 ) ;
if ( V_25 ) {
memcpy ( V_19 -> V_25 , V_25 , V_60 ) ;
V_19 -> V_57 = F_16 ;
V_19 -> V_32 = V_17 ;
F_24 ( V_17 -> V_23 , V_25 ) ;
V_41 = V_60 ;
}
}
break;
default:
V_56:
F_25 ( V_22 , L_5 ,
V_40 -> V_49 , V_40 -> V_50 ,
V_45 , V_43 , V_47 ) ;
}
if ( V_41 >= 0 ) {
F_15 ( V_22 , L_6 ,
V_40 -> V_49 , V_40 -> V_50 ,
V_45 , V_43 , V_47 ) ;
V_19 -> V_61 = ( V_41 < V_47 ) ;
V_19 -> V_37 = V_41 ;
V_41 = F_13 ( V_22 -> V_62 -> V_63 , V_19 , V_29 ) ;
if ( V_41 < 0 )
ERROR ( V_22 , L_7 , V_41 ) ;
}
return V_41 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned V_64 , unsigned V_65 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( V_64 == V_17 -> V_55 ) {
if ( V_17 -> V_28 -> V_66 ) {
F_25 ( V_22 , L_8 , V_64 ) ;
F_27 ( V_17 -> V_28 ) ;
}
if ( ! V_17 -> V_28 -> V_67 ) {
F_25 ( V_22 , L_9 , V_64 ) ;
if ( F_28 ( V_22 -> V_62 , V_3 , V_17 -> V_28 ) )
goto V_68;
}
F_29 ( V_17 -> V_28 ) ;
V_17 -> V_28 -> V_66 = V_17 ;
} else if ( V_64 == V_17 -> V_69 ) {
struct V_70 * V_71 ;
if ( V_17 -> V_4 . V_72 -> V_66 ) {
F_15 ( V_22 , L_10 ) ;
F_30 ( & V_17 -> V_4 ) ;
}
if ( ! V_17 -> V_4 . V_72 -> V_67 || ! V_17 -> V_4 . V_73 -> V_67 ) {
F_15 ( V_22 , L_11 ) ;
if ( F_28 ( V_22 -> V_62 , V_3 ,
V_17 -> V_4 . V_72 ) ||
F_28 ( V_22 -> V_62 , V_3 ,
V_17 -> V_4 . V_73 ) ) {
V_17 -> V_4 . V_72 -> V_67 = NULL ;
V_17 -> V_4 . V_73 -> V_67 = NULL ;
goto V_68;
}
}
V_17 -> V_4 . V_74 = false ;
V_17 -> V_4 . V_75 = 0 ;
F_15 ( V_22 , L_12 ) ;
V_71 = F_31 ( & V_17 -> V_4 ) ;
if ( F_32 ( V_71 ) )
return F_33 ( V_71 ) ;
F_34 ( V_17 -> V_23 , V_71 ,
& V_17 -> V_4 . V_75 ) ;
} else
goto V_68;
return 0 ;
V_68:
return - V_76 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( ! V_17 -> V_28 -> V_66 )
return;
F_15 ( V_22 , L_13 ) ;
F_36 ( V_17 -> V_23 ) ;
F_30 ( & V_17 -> V_4 ) ;
F_27 ( V_17 -> V_28 ) ;
V_17 -> V_28 -> V_66 = NULL ;
}
static void F_37 ( struct V_12 * V_77 )
{
struct V_1 * V_17 = F_1 ( & V_77 -> V_5 ) ;
struct V_21 * V_22 = V_77 -> V_5 . V_23 -> V_22 ;
F_15 ( V_22 , L_14 , V_78 ) ;
F_38 ( V_17 -> V_23 , V_79 ,
F_3 ( V_22 -> V_62 ) / 100 ) ;
F_39 ( V_17 -> V_23 ) ;
}
static void F_40 ( struct V_12 * V_77 )
{
struct V_1 * V_17 = F_1 ( & V_77 -> V_5 ) ;
F_15 ( V_77 -> V_5 . V_23 -> V_22 , L_14 , V_78 ) ;
F_38 ( V_17 -> V_23 , V_79 , 0 ) ;
F_41 ( V_17 -> V_23 ) ;
}
static int
F_42 ( struct V_80 * V_81 , struct V_2 * V_3 )
{
struct V_21 * V_22 = V_81 -> V_22 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_26 ;
struct V_30 * V_31 ;
V_26 = F_43 ( V_81 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_55 = V_26 ;
V_82 . V_83 = V_26 ;
V_84 . V_85 = V_26 ;
V_86 . V_87 = V_26 ;
V_26 = F_43 ( V_81 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_69 = V_26 ;
V_88 . V_85 = V_26 ;
V_86 . V_89 = V_26 ;
V_26 = - V_90 ;
V_31 = F_44 ( V_22 -> V_62 , & V_91 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_72 = V_31 ;
V_31 -> V_66 = V_22 ;
V_31 = F_44 ( V_22 -> V_62 , & V_92 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_73 = V_31 ;
V_31 -> V_66 = V_22 ;
V_31 = F_44 ( V_22 -> V_62 , & V_93 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_28 = V_31 ;
V_31 -> V_66 = V_22 ;
V_26 = - V_94 ;
V_17 -> V_20 = F_45 ( V_31 , V_95 ) ;
if ( ! V_17 -> V_20 )
goto V_68;
V_17 -> V_20 -> V_25 = F_46 ( V_96 , V_95 ) ;
if ( ! V_17 -> V_20 -> V_25 )
goto V_68;
V_17 -> V_20 -> V_37 = V_96 ;
V_17 -> V_20 -> V_32 = V_17 ;
V_17 -> V_20 -> V_57 = F_16 ;
V_97 . V_98 = V_91 . V_98 ;
V_99 . V_98 = V_92 . V_98 ;
V_100 . V_98 = V_93 . V_98 ;
V_101 . V_98 = V_91 . V_98 ;
V_102 . V_98 = V_92 . V_98 ;
V_103 . V_98 = V_93 . V_98 ;
V_26 = F_47 ( V_3 , V_104 , V_105 ,
V_106 ) ;
if ( V_26 )
goto V_68;
V_17 -> V_4 . V_107 = F_37 ;
V_17 -> V_4 . V_108 = F_40 ;
V_26 = F_48 ( F_10 , V_17 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_23 = V_26 ;
F_38 ( V_17 -> V_23 , V_79 , 0 ) ;
F_49 ( V_17 -> V_23 , V_17 -> V_109 ) ;
if ( V_17 -> V_110 && V_17 -> V_111 &&
F_50 ( V_17 -> V_23 , V_17 -> V_111 ,
V_17 -> V_110 ) )
goto V_68;
F_15 ( V_22 , L_15 ,
F_4 ( V_81 -> V_22 -> V_62 ) ? L_16 :
F_5 ( V_81 -> V_22 -> V_62 ) ? L_17 : L_18 ,
V_17 -> V_4 . V_72 -> V_35 , V_17 -> V_4 . V_73 -> V_35 ,
V_17 -> V_28 -> V_35 ) ;
return 0 ;
V_68:
F_51 ( V_3 ) ;
if ( V_17 -> V_20 ) {
F_52 ( V_17 -> V_20 -> V_25 ) ;
F_53 ( V_17 -> V_28 , V_17 -> V_20 ) ;
}
if ( V_17 -> V_28 )
V_17 -> V_28 -> V_66 = NULL ;
if ( V_17 -> V_4 . V_73 )
V_17 -> V_4 . V_73 -> V_66 = NULL ;
if ( V_17 -> V_4 . V_72 )
V_17 -> V_4 . V_72 -> V_66 = NULL ;
ERROR ( V_22 , L_19 , V_3 -> V_35 , V_26 ) ;
return V_26 ;
}
static void
F_54 ( struct V_80 * V_81 , struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_55 ( V_17 -> V_23 ) ;
F_56 () ;
V_112 [ 0 ] . V_113 = 0 ;
F_51 ( V_3 ) ;
F_52 ( V_17 -> V_20 -> V_25 ) ;
F_53 ( V_17 -> V_28 , V_17 -> V_20 ) ;
F_52 ( V_17 ) ;
}
static inline bool F_57 ( struct V_80 * V_81 )
{
return true ;
}
int
F_58 ( struct V_80 * V_81 , V_38 V_109 [ V_114 ] ,
T_3 V_111 , const char * V_110 )
{
struct V_1 * V_17 ;
int V_26 ;
if ( ! F_57 ( V_81 ) || ! V_109 )
return - V_76 ;
if ( V_112 [ 0 ] . V_113 == 0 ) {
V_26 = F_59 () ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_60 ( V_81 -> V_22 , V_112 ) ;
if ( V_26 )
return V_26 ;
V_84 . V_115 = V_112 [ 0 ] . V_113 ;
V_88 . V_115 = V_112 [ 1 ] . V_113 ;
V_82 . V_116 = V_112 [ 2 ] . V_113 ;
}
V_26 = - V_94 ;
V_17 = F_61 ( sizeof *V_17 , V_95 ) ;
if ( ! V_17 )
goto V_68;
memcpy ( V_17 -> V_109 , V_109 , V_114 ) ;
V_17 -> V_111 = V_111 ;
V_17 -> V_110 = V_110 ;
V_17 -> V_4 . V_75 = 0 ;
V_17 -> V_4 . V_117 = sizeof( struct V_15 ) ;
V_17 -> V_4 . V_118 = F_6 ;
V_17 -> V_4 . V_119 = V_120 ;
V_17 -> V_4 . V_5 . V_35 = L_20 ;
V_17 -> V_4 . V_5 . V_121 = V_122 ;
V_17 -> V_4 . V_5 . V_123 = F_42 ;
V_17 -> V_4 . V_5 . V_124 = F_54 ;
V_17 -> V_4 . V_5 . V_125 = F_26 ;
V_17 -> V_4 . V_5 . V_126 = F_21 ;
V_17 -> V_4 . V_5 . V_127 = F_35 ;
V_26 = F_62 ( V_81 , & V_17 -> V_4 . V_5 ) ;
if ( V_26 ) {
F_52 ( V_17 ) ;
V_68:
F_56 () ;
}
return V_26 ;
}
