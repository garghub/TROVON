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
static inline void F_27 ( struct V_26 * * V_27 , T_1 * type ,
T_1 * V_28 )
{
struct V_29 * V_30 ;
V_30 = F_28 ( V_27 ) ;
if ( F_29 ( V_30 ) )
return;
* type |= V_30 -> type & V_31 ;
* V_28 |= V_30 -> V_28 & V_31 ;
}
static int F_30 ( struct V_32 * V_33 ,
const T_2 * V_34 , unsigned int V_35 )
{
struct V_36 * V_37 = F_31 ( V_33 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
int V_13 ;
F_32 ( V_39 , V_40 ) ;
F_33 ( V_39 , F_34 ( V_33 ) &
V_40 ) ;
V_13 = F_35 ( V_39 , V_34 , V_35 ) ;
F_36 ( V_33 , F_37 ( V_39 ) &
V_41 ) ;
return V_13 ;
}
static void F_38 ( struct V_42 * V_16 ,
struct V_38 * V_39 ,
int V_13 ,
int (* F_39)( struct V_43 * V_44 ,
struct V_45 * V_46 ,
struct V_45 * V_47 ,
unsigned int V_48 ) )
{
struct V_49 * V_50 ;
struct V_43 V_44 ;
V_50 = F_40 ( V_16 ) ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_44 . V_21 = V_39 ;
V_44 . V_52 = V_16 -> V_52 ;
V_44 . V_53 = V_54 ;
V_13 = F_39 ( & V_44 , V_16 -> V_46 , V_16 -> V_47 , V_16 -> V_55 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static void F_42 ( struct V_11 * V_16 , int V_13 )
{
struct V_36 * V_37 = F_43 ( V_16 -> V_21 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
F_38 ( F_44 ( V_16 ) , V_39 , V_13 ,
F_45 ( V_39 ) -> V_57 ) ;
}
static void F_46 ( struct V_11 * V_16 , int V_13 )
{
struct V_36 * V_37 = F_43 ( V_16 -> V_21 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
F_38 ( F_44 ( V_16 ) , V_39 , V_13 ,
F_45 ( V_39 ) -> V_58 ) ;
}
static int F_47 ( struct V_42 * V_16 ,
T_3 V_59 )
{
struct V_49 * V_50 = F_40 ( V_16 ) ;
struct V_32 * V_21 = F_48 ( V_16 ) ;
struct V_1 * V_2 ;
V_2 = F_24 ( F_49 ( V_21 ) ) ;
V_50 -> V_18 = V_16 -> V_56 . V_18 ;
V_16 -> V_56 . V_18 = V_59 ;
return F_10 ( V_2 , & V_16 -> V_56 ) ;
}
static int F_50 ( struct V_42 * V_16 )
{
return F_47 ( V_16 , F_42 ) ;
}
static int F_51 ( struct V_42 * V_16 )
{
return F_47 ( V_16 , F_46 ) ;
}
static int F_52 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_24 * V_25 = F_26 ( V_23 ) ;
struct V_60 * V_61 = & V_25 -> V_61 ;
struct V_36 * V_37 = F_43 ( V_21 ) ;
struct V_38 * V_62 ;
V_62 = F_53 ( V_61 ) ;
if ( F_29 ( V_62 ) )
return F_54 ( V_62 ) ;
V_37 -> V_39 = V_62 ;
V_21 -> V_63 . V_64 =
sizeof( struct V_49 ) ;
return 0 ;
}
static void F_55 ( struct V_20 * V_21 )
{
struct V_36 * V_37 = F_43 ( V_21 ) ;
F_56 ( V_37 -> V_39 ) ;
}
static int F_57 ( struct V_22 * V_23 ,
struct V_65 * V_66 )
{
if ( snprintf ( V_23 -> V_66 . V_67 , V_68 ,
L_1 ,
V_66 -> V_67 ) >= V_68 )
return - V_69 ;
memcpy ( V_23 -> V_66 . V_70 , V_66 -> V_70 , V_68 ) ;
V_23 -> V_66 . V_71 = V_66 -> V_71 + 50 ;
V_23 -> V_66 . V_72 = V_66 -> V_72 ;
V_23 -> V_66 . V_73 = V_66 -> V_73 ;
return 0 ;
}
static void * F_58 ( struct V_65 * V_66 , unsigned int V_74 ,
unsigned int V_75 )
{
char * V_76 ;
struct V_22 * V_23 ;
int V_13 ;
V_76 = F_59 ( V_74 + sizeof( * V_23 ) + V_75 , V_77 ) ;
if ( ! V_76 )
return F_60 ( - V_7 ) ;
V_23 = ( void * ) ( V_76 + V_74 ) ;
V_13 = F_57 ( V_23 , V_66 ) ;
if ( V_13 )
goto V_78;
V_51:
return V_76 ;
V_78:
F_61 ( V_76 ) ;
V_76 = F_60 ( V_13 ) ;
goto V_51;
}
static int F_62 ( struct V_79 * V_80 ,
struct V_26 * * V_27 ,
struct V_1 * V_2 )
{
struct V_24 * V_37 ;
struct V_22 * V_23 ;
struct V_65 * V_66 ;
T_1 type = V_81 ;
T_1 V_28 = V_82 ;
int V_13 ;
F_27 ( V_27 , & type , & V_28 ) ;
V_66 = F_63 ( V_27 , type , V_28 ) ;
if ( F_29 ( V_66 ) )
return F_54 ( V_66 ) ;
V_23 = F_58 ( V_66 , 0 , sizeof( * V_37 ) ) ;
V_13 = F_54 ( V_23 ) ;
if ( F_29 ( V_23 ) )
goto V_83;
V_37 = F_26 ( V_23 ) ;
V_37 -> V_2 = V_2 ;
V_13 = F_64 ( & V_37 -> V_61 , V_66 , V_23 ,
V_82 | V_84 ) ;
if ( V_13 )
goto V_78;
type = V_85 | V_84 ;
if ( V_66 -> V_86 & V_31 )
type |= V_31 ;
V_23 -> V_66 . V_86 = type ;
V_23 -> V_66 . V_87 = & V_88 ;
V_23 -> V_66 . V_89 . V_90 = V_66 -> V_91 . V_90 ;
V_23 -> V_66 . V_89 . V_92 = V_66 -> V_91 . V_92 ;
V_23 -> V_66 . V_89 . V_93 = V_66 -> V_91 . V_93 ;
V_23 -> V_66 . V_89 . V_94 = V_66 -> V_91 . V_94 ;
V_23 -> V_66 . V_95 = sizeof( struct V_36 ) ;
V_23 -> V_66 . V_96 = F_52 ;
V_23 -> V_66 . V_97 = F_55 ;
V_23 -> V_66 . V_89 . V_98 = F_30 ;
V_23 -> V_66 . V_89 . V_57 = F_50 ;
V_23 -> V_66 . V_89 . V_58 = F_51 ;
V_13 = F_65 ( V_80 , V_23 ) ;
if ( V_13 ) {
F_66 ( & V_37 -> V_61 ) ;
V_78:
F_61 ( V_23 ) ;
}
V_83:
F_67 ( V_66 ) ;
return V_13 ;
}
static int F_68 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_25 ( V_21 ) ;
struct V_99 * V_25 = F_26 ( V_23 ) ;
struct V_100 * V_61 = & V_25 -> V_61 ;
struct V_101 * V_37 = F_43 ( V_21 ) ;
struct V_102 * V_103 ;
V_103 = F_69 ( V_61 ) ;
if ( F_29 ( V_103 ) )
return F_54 ( V_103 ) ;
V_37 -> V_39 = V_103 ;
F_70 ( F_71 ( V_21 ) ,
sizeof( struct V_104 ) +
F_72 ( V_103 ) ) ;
return 0 ;
}
static void F_73 ( struct V_20 * V_21 )
{
struct V_101 * V_37 = F_43 ( V_21 ) ;
F_74 ( V_37 -> V_39 ) ;
}
static int F_75 ( struct V_105 * V_33 ,
const T_2 * V_34 , unsigned int V_35 )
{
struct V_101 * V_37 = F_76 ( V_33 ) ;
struct V_102 * V_39 = V_37 -> V_39 ;
int V_13 ;
F_77 ( V_39 , V_40 ) ;
F_78 ( V_39 , F_79 ( V_33 ) &
V_40 ) ;
V_13 = F_80 ( V_39 , V_34 , V_35 ) ;
F_81 ( V_33 , F_82 ( V_39 ) &
V_41 ) ;
return V_13 ;
}
static int F_83 ( struct V_106 * V_16 ,
T_3 V_59 )
{
struct V_104 * V_50 = F_84 ( V_16 ) ;
struct V_105 * V_21 = F_85 ( V_16 ) ;
struct V_1 * V_2 =
F_24 ( F_86 ( V_21 ) ) ;
V_50 -> V_18 = V_16 -> V_56 . V_18 ;
V_16 -> V_56 . V_18 = V_59 ;
return F_10 ( V_2 , & V_16 -> V_56 ) ;
}
static void F_87 ( struct V_11 * V_107 , int V_13 )
{
struct V_101 * V_37 = F_43 ( V_107 -> V_21 ) ;
struct V_102 * V_39 = V_37 -> V_39 ;
struct V_106 * V_16 = F_88 ( V_107 ) ;
struct V_104 * V_50 = F_84 ( V_16 ) ;
struct V_108 * V_44 = & V_50 -> V_44 ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_44 -> V_21 = V_39 ;
V_44 -> V_53 = V_54 ;
V_13 = F_89 ( V_44 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static int F_90 ( struct V_106 * V_16 )
{
return F_83 ( V_16 , F_87 ) ;
}
static void F_91 ( struct V_11 * V_107 , int V_13 )
{
struct V_106 * V_16 = F_88 ( V_107 ) ;
struct V_104 * V_50 ;
V_50 = F_84 ( V_16 ) ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_13 = F_92 ( V_16 , & V_50 -> V_44 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static int F_93 ( struct V_106 * V_16 )
{
return F_83 ( V_16 , F_91 ) ;
}
static void F_94 ( struct V_11 * V_107 , int V_13 )
{
struct V_106 * V_16 = F_88 ( V_107 ) ;
struct V_104 * V_50 = F_84 ( V_16 ) ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_13 = F_95 ( & V_50 -> V_44 , V_16 -> V_109 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static int F_96 ( struct V_106 * V_16 )
{
return F_83 ( V_16 , F_94 ) ;
}
static void F_97 ( struct V_11 * V_107 , int V_13 )
{
struct V_106 * V_16 = F_88 ( V_107 ) ;
struct V_104 * V_50 = F_84 ( V_16 ) ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_13 = F_98 ( V_16 , & V_50 -> V_44 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static int F_99 ( struct V_106 * V_16 )
{
return F_83 ( V_16 , F_97 ) ;
}
static void F_100 ( struct V_11 * V_107 , int V_13 )
{
struct V_101 * V_37 = F_43 ( V_107 -> V_21 ) ;
struct V_102 * V_39 = V_37 -> V_39 ;
struct V_106 * V_16 = F_88 ( V_107 ) ;
struct V_104 * V_50 = F_84 ( V_16 ) ;
struct V_108 * V_44 = & V_50 -> V_44 ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
V_44 -> V_21 = V_39 ;
V_44 -> V_53 = V_54 ;
V_13 = F_101 ( V_16 , V_44 ) ;
V_16 -> V_56 . V_18 = V_50 -> V_18 ;
V_51:
F_17 () ;
V_50 -> V_18 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static int F_102 ( struct V_106 * V_16 )
{
return F_83 ( V_16 , F_100 ) ;
}
static int F_103 ( struct V_106 * V_16 , void * V_51 )
{
struct V_104 * V_50 = F_84 ( V_16 ) ;
return F_104 ( & V_50 -> V_44 , V_51 ) ;
}
static int F_105 ( struct V_106 * V_16 , const void * V_110 )
{
struct V_104 * V_50 = F_84 ( V_16 ) ;
return F_106 ( & V_50 -> V_44 , V_110 ) ;
}
static int F_107 ( struct V_79 * V_80 , struct V_26 * * V_27 ,
struct V_1 * V_2 )
{
struct V_99 * V_37 ;
struct V_111 * V_23 ;
struct V_112 * V_113 ;
struct V_65 * V_66 ;
T_1 type = 0 ;
T_1 V_28 = 0 ;
int V_13 ;
F_27 ( V_27 , & type , & V_28 ) ;
V_113 = F_108 ( V_27 [ 1 ] , type , V_28 ) ;
if ( F_29 ( V_113 ) )
return F_54 ( V_113 ) ;
V_66 = & V_113 -> V_56 ;
V_23 = F_58 ( V_66 , F_109 () ,
sizeof( * V_37 ) ) ;
V_13 = F_54 ( V_23 ) ;
if ( F_29 ( V_23 ) )
goto V_83;
V_37 = F_110 ( V_23 ) ;
V_37 -> V_2 = V_2 ;
V_13 = F_111 ( & V_37 -> V_61 , V_113 ,
F_112 ( V_23 ) ) ;
if ( V_13 )
goto V_78;
type = V_84 ;
if ( V_66 -> V_86 & V_31 )
type |= V_31 ;
V_23 -> V_66 . V_114 . V_56 . V_86 = type ;
V_23 -> V_66 . V_114 . V_115 = V_113 -> V_115 ;
V_23 -> V_66 . V_114 . V_116 = V_113 -> V_116 ;
V_23 -> V_66 . V_114 . V_56 . V_95 = sizeof( struct V_101 ) ;
V_23 -> V_66 . V_114 . V_56 . V_96 = F_68 ;
V_23 -> V_66 . V_114 . V_56 . V_97 = F_73 ;
V_23 -> V_66 . V_117 = F_90 ;
V_23 -> V_66 . V_118 = F_93 ;
V_23 -> V_66 . V_119 = F_96 ;
V_23 -> V_66 . V_120 = F_99 ;
V_23 -> V_66 . V_121 = F_103 ;
V_23 -> V_66 . V_122 = F_105 ;
V_23 -> V_66 . V_98 = F_75 ;
V_23 -> V_66 . V_123 = F_102 ;
V_13 = F_113 ( V_80 , V_23 ) ;
if ( V_13 ) {
F_114 ( & V_37 -> V_61 ) ;
V_78:
F_61 ( V_23 ) ;
}
V_83:
F_67 ( V_66 ) ;
return V_13 ;
}
static int F_115 ( struct V_124 * V_33 ,
const T_2 * V_34 , unsigned int V_35 )
{
struct V_125 * V_37 = F_116 ( V_33 ) ;
struct V_124 * V_39 = V_37 -> V_39 ;
return F_117 ( V_39 , V_34 , V_35 ) ;
}
static int F_118 ( struct V_124 * V_33 ,
unsigned int V_126 )
{
struct V_125 * V_37 = F_116 ( V_33 ) ;
struct V_124 * V_39 = V_37 -> V_39 ;
return F_119 ( V_39 , V_126 ) ;
}
static void F_120 ( struct V_127 * V_16 ,
struct V_124 * V_39 ,
int V_13 ,
int (* F_39)( struct V_127 * V_16 ) )
{
struct V_128 * V_50 ;
T_3 V_59 ;
V_50 = F_121 ( V_16 ) ;
V_59 = V_50 -> V_18 ;
if ( F_41 ( V_13 == - V_19 ) )
goto V_51;
F_122 ( V_16 , V_39 ) ;
V_13 = F_39 ( V_16 ) ;
V_51:
F_17 () ;
V_59 ( & V_16 -> V_56 , V_13 ) ;
F_22 () ;
}
static void F_123 ( struct V_11 * V_129 , int V_13 )
{
struct V_125 * V_37 = F_43 ( V_129 -> V_21 ) ;
struct V_124 * V_39 = V_37 -> V_39 ;
struct V_127 * V_16 ;
V_16 = F_16 ( V_129 , struct V_127 , V_56 ) ;
F_120 ( V_16 , V_39 , V_13 , F_124 ( V_39 ) -> V_57 ) ;
}
static void F_125 ( struct V_11 * V_129 , int V_13 )
{
struct V_125 * V_37 = F_43 ( V_129 -> V_21 ) ;
struct V_124 * V_39 = V_37 -> V_39 ;
struct V_127 * V_16 ;
V_16 = F_16 ( V_129 , struct V_127 , V_56 ) ;
F_120 ( V_16 , V_39 , V_13 , F_124 ( V_39 ) -> V_58 ) ;
}
static int F_126 ( struct V_127 * V_16 ,
T_3 V_59 )
{
struct V_128 * V_50 = F_121 ( V_16 ) ;
struct V_124 * V_21 = F_127 ( V_16 ) ;
struct V_1 * V_2 = F_24 ( F_128 ( V_21 ) ) ;
V_50 -> V_18 = V_16 -> V_56 . V_18 ;
V_16 -> V_56 . V_18 = V_59 ;
return F_10 ( V_2 , & V_16 -> V_56 ) ;
}
static int F_129 ( struct V_127 * V_16 )
{
return F_126 ( V_16 , F_123 ) ;
}
static int F_130 ( struct V_127 * V_16 )
{
return F_126 ( V_16 , F_125 ) ;
}
static int F_131 ( struct V_124 * V_21 )
{
struct V_130 * V_23 = F_132 ( V_21 ) ;
struct V_131 * V_25 = V_131 ( V_23 ) ;
struct V_132 * V_61 = & V_25 -> V_133 ;
struct V_125 * V_37 = F_116 ( V_21 ) ;
struct V_124 * V_62 ;
V_62 = F_133 ( V_61 ) ;
if ( F_29 ( V_62 ) )
return F_54 ( V_62 ) ;
V_37 -> V_39 = V_62 ;
F_134 (
V_21 , F_135 ( ( unsigned ) sizeof( struct V_128 ) ,
F_136 ( V_62 ) ) ) ;
return 0 ;
}
static void F_137 ( struct V_124 * V_21 )
{
struct V_125 * V_37 = F_116 ( V_21 ) ;
F_138 ( V_37 -> V_39 ) ;
}
static int F_139 ( struct V_79 * V_80 ,
struct V_26 * * V_27 ,
struct V_1 * V_2 )
{
struct V_131 * V_37 ;
struct V_130 * V_23 ;
struct V_134 * V_66 ;
const char * V_135 ;
T_1 type = 0 ;
T_1 V_28 = V_84 ;
int V_13 ;
F_27 ( V_27 , & type , & V_28 ) ;
V_135 = F_140 ( V_27 [ 1 ] ) ;
if ( F_29 ( V_135 ) )
return F_54 ( V_135 ) ;
V_23 = F_59 ( sizeof( * V_23 ) + sizeof( * V_37 ) , V_77 ) ;
if ( ! V_23 )
return - V_7 ;
V_37 = V_131 ( V_23 ) ;
V_37 -> V_2 = V_2 ;
F_141 ( & V_37 -> V_133 , F_142 ( V_23 ) ) ;
V_13 = F_143 ( & V_37 -> V_133 , V_135 , type , V_28 ) ;
if ( V_13 )
goto V_78;
V_66 = F_144 ( & V_37 -> V_133 ) ;
V_13 = F_57 ( F_142 ( V_23 ) , & V_66 -> V_56 ) ;
if ( V_13 )
goto V_136;
V_23 -> V_66 . V_56 . V_86 = V_84 |
( V_66 -> V_56 . V_86 & V_31 ) ;
V_23 -> V_66 . V_56 . V_95 = sizeof( struct V_125 ) ;
V_23 -> V_66 . V_90 = F_145 ( V_66 ) ;
V_23 -> V_66 . V_137 = F_146 ( V_66 ) ;
V_23 -> V_66 . V_117 = F_131 ;
V_23 -> V_66 . exit = F_137 ;
V_23 -> V_66 . V_98 = F_115 ;
V_23 -> V_66 . V_138 = F_118 ;
V_23 -> V_66 . V_57 = F_129 ;
V_23 -> V_66 . V_58 = F_130 ;
V_13 = F_147 ( V_80 , V_23 ) ;
if ( V_13 ) {
V_136:
F_148 ( & V_37 -> V_133 ) ;
V_78:
F_61 ( V_23 ) ;
}
return V_13 ;
}
static int F_149 ( struct V_79 * V_80 , struct V_26 * * V_27 )
{
struct V_29 * V_30 ;
V_30 = F_28 ( V_27 ) ;
if ( F_29 ( V_30 ) )
return F_54 ( V_30 ) ;
switch ( V_30 -> type & V_30 -> V_28 & V_82 ) {
case V_81 :
return F_62 ( V_80 , V_27 , & V_2 ) ;
case V_139 :
return F_107 ( V_80 , V_27 , & V_2 ) ;
case V_140 :
return F_139 ( V_80 , V_27 , & V_2 ) ;
}
return - V_141 ;
}
static void F_150 ( struct V_22 * V_23 )
{
struct V_24 * V_37 = F_26 ( V_23 ) ;
struct V_99 * V_142 = F_26 ( V_23 ) ;
struct V_131 * V_143 = F_26 ( V_23 ) ;
switch ( V_23 -> V_66 . V_86 & V_82 ) {
case V_144 :
F_114 ( & V_142 -> V_61 ) ;
F_61 ( V_111 ( V_23 ) ) ;
return;
case V_140 :
F_148 ( & V_143 -> V_133 ) ;
F_61 ( V_130 ( V_23 ) ) ;
return;
default:
F_66 ( & V_37 -> V_61 ) ;
F_61 ( V_23 ) ;
}
}
struct V_145 * F_151 ( const char * V_146 ,
T_1 type , T_1 V_28 )
{
char V_147 [ V_68 ] ;
struct V_20 * V_21 ;
if ( snprintf ( V_147 , V_68 ,
L_1 , V_146 ) >= V_68 )
return F_60 ( - V_141 ) ;
type = F_152 ( type ) ;
V_28 &= ~ V_82 ;
V_28 |= ( V_148 | V_149 ) ;
V_21 = F_153 ( V_147 , type , V_28 ) ;
if ( F_29 ( V_21 ) )
return F_154 ( V_21 ) ;
if ( V_21 -> V_150 -> V_151 != V_152 ) {
F_155 ( V_21 ) ;
return F_60 ( - V_141 ) ;
}
return F_156 ( F_157 ( V_21 ) ) ;
}
struct V_38 * F_158 ( struct V_145 * V_21 )
{
struct V_36 * V_37 = F_31 ( & V_21 -> V_56 ) ;
return V_37 -> V_39 ;
}
void F_159 ( struct V_145 * V_21 )
{
F_160 ( & V_21 -> V_56 ) ;
}
struct V_153 * F_161 ( const char * V_146 ,
T_1 type , T_1 V_28 )
{
char V_147 [ V_68 ] ;
struct V_105 * V_21 ;
if ( snprintf ( V_147 , V_68 ,
L_1 , V_146 ) >= V_68 )
return F_60 ( - V_141 ) ;
V_21 = F_162 ( V_147 , type , V_28 ) ;
if ( F_29 ( V_21 ) )
return F_154 ( V_21 ) ;
if ( V_21 -> V_56 . V_150 -> V_151 != V_152 ) {
F_163 ( V_21 ) ;
return F_60 ( - V_141 ) ;
}
return F_164 ( V_21 ) ;
}
struct V_102 * F_165 ( struct V_153 * V_21 )
{
struct V_101 * V_37 = F_76 ( & V_21 -> V_56 ) ;
return V_37 -> V_39 ;
}
struct V_108 * F_166 ( struct V_106 * V_16 )
{
struct V_104 * V_50 = F_84 ( V_16 ) ;
return & V_50 -> V_44 ;
}
void F_167 ( struct V_153 * V_21 )
{
F_163 ( & V_21 -> V_56 ) ;
}
struct V_154 * F_168 ( const char * V_146 ,
T_1 type , T_1 V_28 )
{
char V_147 [ V_68 ] ;
struct V_124 * V_21 ;
if ( snprintf ( V_147 , V_68 ,
L_1 , V_146 ) >= V_68 )
return F_60 ( - V_141 ) ;
V_21 = F_169 ( V_147 , type , V_28 ) ;
if ( F_29 ( V_21 ) )
return F_154 ( V_21 ) ;
if ( V_21 -> V_56 . V_150 -> V_151 != V_152 ) {
F_138 ( V_21 ) ;
return F_60 ( - V_141 ) ;
}
return F_170 ( V_21 ) ;
}
struct V_124 * F_171 ( struct V_154 * V_21 )
{
struct V_125 * V_37 ;
V_37 = F_116 ( & V_21 -> V_56 ) ;
return V_37 -> V_39 ;
}
void F_172 ( struct V_154 * V_21 )
{
F_138 ( & V_21 -> V_56 ) ;
}
static int T_4 F_173 ( void )
{
int V_13 ;
V_13 = F_1 ( & V_2 , V_155 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_174 ( & V_156 ) ;
if ( V_13 )
F_7 ( & V_2 ) ;
return V_13 ;
}
static void T_5 F_175 ( void )
{
F_7 ( & V_2 ) ;
F_176 ( & V_156 ) ;
}
