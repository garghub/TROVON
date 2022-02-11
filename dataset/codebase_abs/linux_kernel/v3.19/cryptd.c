static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 ;
struct V_5 * V_6 ;
V_2 -> V_6 = F_2 ( struct V_5 ) ;
if ( ! V_2 -> V_6 )
return - V_7 ;
F_3 (cpu) {
V_6 = F_4 ( V_2 -> V_6 , V_4 ) ;
F_5 ( & V_6 -> V_2 , V_3 ) ;
F_6 ( & V_6 -> V_8 , V_9 ) ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_5 * V_6 ;
F_3 (cpu) {
V_6 = F_4 ( V_2 -> V_6 , V_4 ) ;
F_8 ( V_6 -> V_2 . V_10 ) ;
}
F_9 ( V_2 -> V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
int V_4 , V_13 ;
struct V_5 * V_6 ;
V_4 = F_11 () ;
V_6 = F_12 ( V_2 -> V_6 ) ;
V_13 = F_13 ( & V_6 -> V_2 , V_12 ) ;
F_14 ( V_4 , V_14 , & V_6 -> V_8 ) ;
F_15 () ;
return V_13 ;
}
static void V_9 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_11 * V_16 , * V_17 ;
V_6 = F_16 ( V_8 , struct V_5 , V_8 ) ;
F_17 () ;
F_18 () ;
V_17 = F_19 ( & V_6 -> V_2 ) ;
V_16 = F_20 ( & V_6 -> V_2 ) ;
F_21 () ;
F_22 () ;
if ( ! V_16 )
return;
if ( V_17 )
V_17 -> V_18 ( V_17 , - V_19 ) ;
V_16 -> V_18 ( V_16 , 0 ) ;
if ( V_6 -> V_2 . V_10 )
F_23 ( V_14 , & V_6 -> V_8 ) ;
}
static inline struct V_1 * F_24 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_24 * V_25 = F_26 ( V_23 ) ;
return V_25 -> V_2 ;
}
static int F_27 ( struct V_26 * V_27 ,
const T_1 * V_28 , unsigned int V_29 )
{
struct V_30 * V_31 = F_28 ( V_27 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
int V_13 ;
F_29 ( V_33 , V_34 ) ;
F_30 ( V_33 , F_31 ( V_27 ) &
V_34 ) ;
V_13 = F_32 ( V_33 , V_28 , V_29 ) ;
F_33 ( V_27 , F_34 ( V_33 ) &
V_35 ) ;
return V_13 ;
}
static void F_35 ( struct V_36 * V_16 ,
struct V_32 * V_33 ,
int V_13 ,
int (* F_36)( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_39 * V_41 ,
unsigned int V_42 ) )
{
struct V_43 * V_44 ;
struct V_37 V_38 ;
V_44 = F_37 ( V_16 ) ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_38 . V_21 = V_33 ;
V_38 . V_46 = V_16 -> V_46 ;
V_38 . V_47 = V_48 ;
V_13 = F_36 ( & V_38 , V_16 -> V_40 , V_16 -> V_41 , V_16 -> V_49 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static void F_39 ( struct V_11 * V_16 , int V_13 )
{
struct V_30 * V_31 = F_40 ( V_16 -> V_21 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_35 ( F_41 ( V_16 ) , V_33 , V_13 ,
F_42 ( V_33 ) -> V_51 ) ;
}
static void F_43 ( struct V_11 * V_16 , int V_13 )
{
struct V_30 * V_31 = F_40 ( V_16 -> V_21 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_35 ( F_41 ( V_16 ) , V_33 , V_13 ,
F_42 ( V_33 ) -> V_52 ) ;
}
static int F_44 ( struct V_36 * V_16 ,
T_2 V_53 )
{
struct V_43 * V_44 = F_37 ( V_16 ) ;
struct V_26 * V_21 = F_45 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = F_24 ( F_46 ( V_21 ) ) ;
V_44 -> V_18 = V_16 -> V_50 . V_18 ;
V_16 -> V_50 . V_18 = V_53 ;
return F_10 ( V_2 , & V_16 -> V_50 ) ;
}
static int F_47 ( struct V_36 * V_16 )
{
return F_44 ( V_16 , F_39 ) ;
}
static int F_48 ( struct V_36 * V_16 )
{
return F_44 ( V_16 , F_43 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_24 * V_25 = F_26 ( V_23 ) ;
struct V_54 * V_55 = & V_25 -> V_55 ;
struct V_30 * V_31 = F_40 ( V_21 ) ;
struct V_32 * V_56 ;
V_56 = F_50 ( V_55 ) ;
if ( F_51 ( V_56 ) )
return F_52 ( V_56 ) ;
V_31 -> V_33 = V_56 ;
V_21 -> V_57 . V_58 =
sizeof( struct V_43 ) ;
return 0 ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_30 * V_31 = F_40 ( V_21 ) ;
F_54 ( V_31 -> V_33 ) ;
}
static void * F_55 ( struct V_59 * V_60 , unsigned int V_61 ,
unsigned int V_62 )
{
char * V_63 ;
struct V_22 * V_23 ;
int V_13 ;
V_63 = F_56 ( V_61 + sizeof( * V_23 ) + V_62 , V_64 ) ;
if ( ! V_63 )
return F_57 ( - V_7 ) ;
V_23 = ( void * ) ( V_63 + V_61 ) ;
V_13 = - V_65 ;
if ( snprintf ( V_23 -> V_60 . V_66 , V_67 ,
L_1 , V_60 -> V_66 ) >= V_67 )
goto V_68;
memcpy ( V_23 -> V_60 . V_69 , V_60 -> V_69 , V_67 ) ;
V_23 -> V_60 . V_70 = V_60 -> V_70 + 50 ;
V_23 -> V_60 . V_71 = V_60 -> V_71 ;
V_23 -> V_60 . V_72 = V_60 -> V_72 ;
V_45:
return V_63 ;
V_68:
F_58 ( V_63 ) ;
V_63 = F_57 ( V_13 ) ;
goto V_45;
}
static int F_59 ( struct V_73 * V_74 ,
struct V_75 * * V_76 ,
struct V_1 * V_2 )
{
struct V_24 * V_31 ;
struct V_22 * V_23 ;
struct V_59 * V_60 ;
int V_13 ;
V_60 = F_60 ( V_76 , V_77 ,
V_78 ) ;
if ( F_51 ( V_60 ) )
return F_52 ( V_60 ) ;
V_23 = F_55 ( V_60 , 0 , sizeof( * V_31 ) ) ;
V_13 = F_52 ( V_23 ) ;
if ( F_51 ( V_23 ) )
goto V_79;
V_31 = F_26 ( V_23 ) ;
V_31 -> V_2 = V_2 ;
V_13 = F_61 ( & V_31 -> V_55 , V_60 , V_23 ,
V_78 | V_80 ) ;
if ( V_13 )
goto V_68;
V_23 -> V_60 . V_81 = V_82 | V_80 ;
V_23 -> V_60 . V_83 = & V_84 ;
V_23 -> V_60 . V_85 . V_86 = V_60 -> V_87 . V_86 ;
V_23 -> V_60 . V_85 . V_88 = V_60 -> V_87 . V_88 ;
V_23 -> V_60 . V_85 . V_89 = V_60 -> V_87 . V_89 ;
V_23 -> V_60 . V_85 . V_90 = V_60 -> V_87 . V_90 ;
V_23 -> V_60 . V_91 = sizeof( struct V_30 ) ;
V_23 -> V_60 . V_92 = F_49 ;
V_23 -> V_60 . V_93 = F_53 ;
V_23 -> V_60 . V_85 . V_94 = F_27 ;
V_23 -> V_60 . V_85 . V_51 = F_47 ;
V_23 -> V_60 . V_85 . V_52 = F_48 ;
V_13 = F_62 ( V_74 , V_23 ) ;
if ( V_13 ) {
F_63 ( & V_31 -> V_55 ) ;
V_68:
F_58 ( V_23 ) ;
}
V_79:
F_64 ( V_60 ) ;
return V_13 ;
}
static int F_65 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_95 * V_25 = F_26 ( V_23 ) ;
struct V_96 * V_55 = & V_25 -> V_55 ;
struct V_97 * V_31 = F_40 ( V_21 ) ;
struct V_98 * V_99 ;
V_99 = F_66 ( V_55 ) ;
if ( F_51 ( V_99 ) )
return F_52 ( V_99 ) ;
V_31 -> V_33 = V_99 ;
F_67 ( F_68 ( V_21 ) ,
sizeof( struct V_100 ) +
F_69 ( V_99 ) ) ;
return 0 ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_97 * V_31 = F_40 ( V_21 ) ;
F_71 ( V_31 -> V_33 ) ;
}
static int F_72 ( struct V_101 * V_27 ,
const T_1 * V_28 , unsigned int V_29 )
{
struct V_97 * V_31 = F_73 ( V_27 ) ;
struct V_98 * V_33 = V_31 -> V_33 ;
int V_13 ;
F_74 ( V_33 , V_34 ) ;
F_75 ( V_33 , F_76 ( V_27 ) &
V_34 ) ;
V_13 = F_77 ( V_33 , V_28 , V_29 ) ;
F_78 ( V_27 , F_79 ( V_33 ) &
V_35 ) ;
return V_13 ;
}
static int F_80 ( struct V_102 * V_16 ,
T_2 V_53 )
{
struct V_100 * V_44 = F_81 ( V_16 ) ;
struct V_101 * V_21 = F_82 ( V_16 ) ;
struct V_1 * V_2 =
F_24 ( F_83 ( V_21 ) ) ;
V_44 -> V_18 = V_16 -> V_50 . V_18 ;
V_16 -> V_50 . V_18 = V_53 ;
return F_10 ( V_2 , & V_16 -> V_50 ) ;
}
static void F_84 ( struct V_11 * V_103 , int V_13 )
{
struct V_97 * V_31 = F_40 ( V_103 -> V_21 ) ;
struct V_98 * V_33 = V_31 -> V_33 ;
struct V_102 * V_16 = F_85 ( V_103 ) ;
struct V_100 * V_44 = F_81 ( V_16 ) ;
struct V_104 * V_38 = & V_44 -> V_38 ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_38 -> V_21 = V_33 ;
V_38 -> V_47 = V_48 ;
V_13 = F_86 ( V_38 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static int F_87 ( struct V_102 * V_16 )
{
return F_80 ( V_16 , F_84 ) ;
}
static void F_88 ( struct V_11 * V_103 , int V_13 )
{
struct V_102 * V_16 = F_85 ( V_103 ) ;
struct V_100 * V_44 ;
V_44 = F_81 ( V_16 ) ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_13 = F_89 ( V_16 , & V_44 -> V_38 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static int F_90 ( struct V_102 * V_16 )
{
return F_80 ( V_16 , F_88 ) ;
}
static void F_91 ( struct V_11 * V_103 , int V_13 )
{
struct V_102 * V_16 = F_85 ( V_103 ) ;
struct V_100 * V_44 = F_81 ( V_16 ) ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_13 = F_92 ( & V_44 -> V_38 , V_16 -> V_105 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static int F_93 ( struct V_102 * V_16 )
{
return F_80 ( V_16 , F_91 ) ;
}
static void F_94 ( struct V_11 * V_103 , int V_13 )
{
struct V_102 * V_16 = F_85 ( V_103 ) ;
struct V_100 * V_44 = F_81 ( V_16 ) ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_13 = F_95 ( V_16 , & V_44 -> V_38 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static int F_96 ( struct V_102 * V_16 )
{
return F_80 ( V_16 , F_94 ) ;
}
static void F_97 ( struct V_11 * V_103 , int V_13 )
{
struct V_97 * V_31 = F_40 ( V_103 -> V_21 ) ;
struct V_98 * V_33 = V_31 -> V_33 ;
struct V_102 * V_16 = F_85 ( V_103 ) ;
struct V_100 * V_44 = F_81 ( V_16 ) ;
struct V_104 * V_38 = & V_44 -> V_38 ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
V_38 -> V_21 = V_33 ;
V_38 -> V_47 = V_48 ;
V_13 = F_98 ( V_16 , V_38 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static int F_99 ( struct V_102 * V_16 )
{
return F_80 ( V_16 , F_97 ) ;
}
static int F_100 ( struct V_102 * V_16 , void * V_45 )
{
struct V_100 * V_44 = F_81 ( V_16 ) ;
return F_101 ( & V_44 -> V_38 , V_45 ) ;
}
static int F_102 ( struct V_102 * V_16 , const void * V_106 )
{
struct V_100 * V_44 = F_81 ( V_16 ) ;
return F_103 ( & V_44 -> V_38 , V_106 ) ;
}
static int F_104 ( struct V_73 * V_74 , struct V_75 * * V_76 ,
struct V_1 * V_2 )
{
struct V_95 * V_31 ;
struct V_107 * V_23 ;
struct V_108 * V_109 ;
struct V_59 * V_60 ;
int V_13 ;
V_109 = F_105 ( V_76 [ 1 ] , 0 , 0 ) ;
if ( F_51 ( V_109 ) )
return F_52 ( V_109 ) ;
V_60 = & V_109 -> V_50 ;
V_23 = F_55 ( V_60 , F_106 () ,
sizeof( * V_31 ) ) ;
V_13 = F_52 ( V_23 ) ;
if ( F_51 ( V_23 ) )
goto V_79;
V_31 = F_107 ( V_23 ) ;
V_31 -> V_2 = V_2 ;
V_13 = F_108 ( & V_31 -> V_55 , V_109 ,
F_109 ( V_23 ) ) ;
if ( V_13 )
goto V_68;
V_23 -> V_60 . V_110 . V_50 . V_81 = V_80 ;
V_23 -> V_60 . V_110 . V_111 = V_109 -> V_111 ;
V_23 -> V_60 . V_110 . V_50 . V_91 = sizeof( struct V_97 ) ;
V_23 -> V_60 . V_110 . V_50 . V_92 = F_65 ;
V_23 -> V_60 . V_110 . V_50 . V_93 = F_70 ;
V_23 -> V_60 . V_112 = F_87 ;
V_23 -> V_60 . V_113 = F_90 ;
V_23 -> V_60 . V_114 = F_93 ;
V_23 -> V_60 . V_115 = F_96 ;
V_23 -> V_60 . V_116 = F_100 ;
V_23 -> V_60 . V_117 = F_102 ;
V_23 -> V_60 . V_94 = F_72 ;
V_23 -> V_60 . V_118 = F_99 ;
V_13 = F_110 ( V_74 , V_23 ) ;
if ( V_13 ) {
F_111 ( & V_31 -> V_55 ) ;
V_68:
F_58 ( V_23 ) ;
}
V_79:
F_64 ( V_60 ) ;
return V_13 ;
}
static void F_112 ( struct V_119 * V_16 ,
struct V_120 * V_33 ,
int V_13 ,
int (* F_36)( struct V_119 * V_16 ) )
{
struct V_121 * V_44 ;
V_44 = F_113 ( V_16 ) ;
if ( F_38 ( V_13 == - V_19 ) )
goto V_45;
F_114 ( V_16 , V_33 ) ;
V_13 = F_36 ( V_16 ) ;
V_16 -> V_50 . V_18 = V_44 -> V_18 ;
V_45:
F_17 () ;
V_44 -> V_18 ( & V_16 -> V_50 , V_13 ) ;
F_22 () ;
}
static void F_115 ( struct V_11 * V_122 , int V_13 )
{
struct V_123 * V_31 = F_40 ( V_122 -> V_21 ) ;
struct V_120 * V_33 = V_31 -> V_33 ;
struct V_119 * V_16 ;
V_16 = F_16 ( V_122 , struct V_119 , V_50 ) ;
F_112 ( V_16 , V_33 , V_13 , F_116 ( V_33 ) -> V_51 ) ;
}
static void F_117 ( struct V_11 * V_122 , int V_13 )
{
struct V_123 * V_31 = F_40 ( V_122 -> V_21 ) ;
struct V_120 * V_33 = V_31 -> V_33 ;
struct V_119 * V_16 ;
V_16 = F_16 ( V_122 , struct V_119 , V_50 ) ;
F_112 ( V_16 , V_33 , V_13 , F_116 ( V_33 ) -> V_52 ) ;
}
static int F_118 ( struct V_119 * V_16 ,
T_2 V_53 )
{
struct V_121 * V_44 = F_113 ( V_16 ) ;
struct V_120 * V_21 = F_119 ( V_16 ) ;
struct V_1 * V_2 = F_24 ( F_120 ( V_21 ) ) ;
V_44 -> V_18 = V_16 -> V_50 . V_18 ;
V_16 -> V_50 . V_18 = V_53 ;
return F_10 ( V_2 , & V_16 -> V_50 ) ;
}
static int F_121 ( struct V_119 * V_16 )
{
return F_118 ( V_16 , F_115 ) ;
}
static int F_122 ( struct V_119 * V_16 )
{
return F_118 ( V_16 , F_117 ) ;
}
static int F_123 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_124 * V_25 = F_26 ( V_23 ) ;
struct V_125 * V_55 = & V_25 -> V_126 ;
struct V_123 * V_31 = F_40 ( V_21 ) ;
struct V_120 * V_56 ;
V_56 = F_124 ( V_55 ) ;
if ( F_51 ( V_56 ) )
return F_52 ( V_56 ) ;
F_125 ( V_56 , V_48 ) ;
V_31 -> V_33 = V_56 ;
V_21 -> V_127 . V_58 = sizeof( struct V_121 ) ;
return 0 ;
}
static void F_126 ( struct V_20 * V_21 )
{
struct V_123 * V_31 = F_40 ( V_21 ) ;
F_127 ( V_31 -> V_33 ) ;
}
static int F_128 ( struct V_73 * V_74 ,
struct V_75 * * V_76 ,
struct V_1 * V_2 )
{
struct V_124 * V_31 ;
struct V_22 * V_23 ;
struct V_59 * V_60 ;
int V_13 ;
V_60 = F_60 ( V_76 , V_128 ,
V_78 ) ;
if ( F_51 ( V_60 ) )
return F_52 ( V_60 ) ;
V_23 = F_55 ( V_60 , 0 , sizeof( * V_31 ) ) ;
V_13 = F_52 ( V_23 ) ;
if ( F_51 ( V_23 ) )
goto V_79;
V_31 = F_26 ( V_23 ) ;
V_31 -> V_2 = V_2 ;
V_13 = F_61 ( & V_31 -> V_126 . V_50 , V_60 , V_23 ,
V_78 | V_80 ) ;
if ( V_13 )
goto V_68;
V_23 -> V_60 . V_81 = V_128 | V_80 ;
V_23 -> V_60 . V_83 = V_60 -> V_83 ;
V_23 -> V_60 . V_91 = sizeof( struct V_123 ) ;
V_23 -> V_60 . V_92 = F_123 ;
V_23 -> V_60 . V_93 = F_126 ;
V_23 -> V_60 . V_129 . V_94 = V_60 -> V_129 . V_94 ;
V_23 -> V_60 . V_129 . V_130 = V_60 -> V_129 . V_130 ;
V_23 -> V_60 . V_129 . V_90 = V_60 -> V_129 . V_90 ;
V_23 -> V_60 . V_129 . V_86 = V_60 -> V_129 . V_86 ;
V_23 -> V_60 . V_129 . V_131 = V_60 -> V_129 . V_131 ;
V_23 -> V_60 . V_129 . V_51 = F_121 ;
V_23 -> V_60 . V_129 . V_52 = F_122 ;
V_23 -> V_60 . V_129 . V_132 = V_60 -> V_129 . V_132 ;
V_23 -> V_60 . V_129 . V_133 = V_60 -> V_129 . V_133 ;
V_13 = F_62 ( V_74 , V_23 ) ;
if ( V_13 ) {
F_63 ( & V_31 -> V_126 . V_50 ) ;
V_68:
F_58 ( V_23 ) ;
}
V_79:
F_64 ( V_60 ) ;
return V_13 ;
}
static int F_129 ( struct V_73 * V_74 , struct V_75 * * V_76 )
{
struct V_134 * V_135 ;
V_135 = F_130 ( V_76 ) ;
if ( F_51 ( V_135 ) )
return F_52 ( V_135 ) ;
switch ( V_135 -> type & V_135 -> V_136 & V_78 ) {
case V_77 :
return F_59 ( V_74 , V_76 , & V_2 ) ;
case V_137 :
return F_104 ( V_74 , V_76 , & V_2 ) ;
case V_128 :
return F_128 ( V_74 , V_76 , & V_2 ) ;
}
return - V_138 ;
}
static void F_131 ( struct V_22 * V_23 )
{
struct V_24 * V_31 = F_26 ( V_23 ) ;
struct V_95 * V_139 = F_26 ( V_23 ) ;
struct V_124 * V_140 = F_26 ( V_23 ) ;
switch ( V_23 -> V_60 . V_81 & V_78 ) {
case V_141 :
F_111 ( & V_139 -> V_55 ) ;
F_58 ( V_107 ( V_23 ) ) ;
return;
case V_128 :
F_63 ( & V_140 -> V_126 . V_50 ) ;
F_58 ( V_23 ) ;
return;
default:
F_63 ( & V_31 -> V_55 ) ;
F_58 ( V_23 ) ;
}
}
struct V_142 * F_132 ( const char * V_143 ,
T_3 type , T_3 V_136 )
{
char V_144 [ V_67 ] ;
struct V_20 * V_21 ;
if ( snprintf ( V_144 , V_67 ,
L_1 , V_143 ) >= V_67 )
return F_57 ( - V_138 ) ;
type &= ~ ( V_78 | V_145 ) ;
type |= V_77 ;
V_136 &= ~ V_78 ;
V_136 |= ( V_145 | V_146 ) ;
V_21 = F_133 ( V_144 , type , V_136 ) ;
if ( F_51 ( V_21 ) )
return F_134 ( V_21 ) ;
if ( V_21 -> V_147 -> V_148 != V_149 ) {
F_135 ( V_21 ) ;
return F_57 ( - V_138 ) ;
}
return F_136 ( F_137 ( V_21 ) ) ;
}
struct V_32 * F_138 ( struct V_142 * V_21 )
{
struct V_30 * V_31 = F_28 ( & V_21 -> V_50 ) ;
return V_31 -> V_33 ;
}
void F_139 ( struct V_142 * V_21 )
{
F_140 ( & V_21 -> V_50 ) ;
}
struct V_150 * F_141 ( const char * V_143 ,
T_3 type , T_3 V_136 )
{
char V_144 [ V_67 ] ;
struct V_101 * V_21 ;
if ( snprintf ( V_144 , V_67 ,
L_1 , V_143 ) >= V_67 )
return F_57 ( - V_138 ) ;
V_21 = F_142 ( V_144 , type , V_136 ) ;
if ( F_51 ( V_21 ) )
return F_134 ( V_21 ) ;
if ( V_21 -> V_50 . V_147 -> V_148 != V_149 ) {
F_143 ( V_21 ) ;
return F_57 ( - V_138 ) ;
}
return F_144 ( V_21 ) ;
}
struct V_98 * F_145 ( struct V_150 * V_21 )
{
struct V_97 * V_31 = F_73 ( & V_21 -> V_50 ) ;
return V_31 -> V_33 ;
}
struct V_104 * F_146 ( struct V_102 * V_16 )
{
struct V_100 * V_44 = F_81 ( V_16 ) ;
return & V_44 -> V_38 ;
}
void F_147 ( struct V_150 * V_21 )
{
F_143 ( & V_21 -> V_50 ) ;
}
struct V_151 * F_148 ( const char * V_143 ,
T_3 type , T_3 V_136 )
{
char V_144 [ V_67 ] ;
struct V_120 * V_21 ;
if ( snprintf ( V_144 , V_67 ,
L_1 , V_143 ) >= V_67 )
return F_57 ( - V_138 ) ;
V_21 = F_149 ( V_144 , type , V_136 ) ;
if ( F_51 ( V_21 ) )
return F_134 ( V_21 ) ;
if ( V_21 -> V_50 . V_147 -> V_148 != V_149 ) {
F_127 ( V_21 ) ;
return F_57 ( - V_138 ) ;
}
return F_150 ( V_21 ) ;
}
struct V_120 * F_151 ( struct V_151 * V_21 )
{
struct V_123 * V_31 ;
V_31 = F_152 ( & V_21 -> V_50 ) ;
return V_31 -> V_33 ;
}
void F_153 ( struct V_151 * V_21 )
{
F_127 ( & V_21 -> V_50 ) ;
}
static int T_4 F_154 ( void )
{
int V_13 ;
V_13 = F_1 ( & V_2 , V_152 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_155 ( & V_153 ) ;
if ( V_13 )
F_7 ( & V_2 ) ;
return V_13 ;
}
static void T_5 F_156 ( void )
{
F_7 ( & V_2 ) ;
F_157 ( & V_153 ) ;
}
