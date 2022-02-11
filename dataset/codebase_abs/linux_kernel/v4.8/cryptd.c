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
struct V_14 * V_15 ;
T_1 * V_16 ;
bool V_17 ;
V_4 = F_11 () ;
V_6 = F_12 ( V_2 -> V_6 ) ;
V_13 = F_13 ( & V_6 -> V_2 , V_12 ) ;
V_16 = F_14 ( V_12 -> V_15 ) ;
V_17 = V_12 -> V_18 & V_19 ;
if ( V_13 == - V_20 && ! V_17 )
goto V_21;
F_15 ( V_4 , V_22 , & V_6 -> V_8 ) ;
if ( ! F_16 ( V_16 ) )
goto V_21;
V_15 = V_12 -> V_15 ;
F_17 ( V_16 ) ;
V_21:
F_18 () ;
return V_13 ;
}
static void V_9 ( struct V_23 * V_8 )
{
struct V_5 * V_6 ;
struct V_11 * V_24 , * V_25 ;
V_6 = F_19 ( V_8 , struct V_5 , V_8 ) ;
F_20 () ;
F_21 () ;
V_25 = F_22 ( & V_6 -> V_2 ) ;
V_24 = F_23 ( & V_6 -> V_2 ) ;
F_24 () ;
F_25 () ;
if ( ! V_24 )
return;
if ( V_25 )
V_25 -> V_26 ( V_25 , - V_27 ) ;
V_24 -> V_26 ( V_24 , 0 ) ;
if ( V_6 -> V_2 . V_10 )
F_26 ( V_22 , & V_6 -> V_8 ) ;
}
static inline struct V_1 * F_27 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_28 ( V_15 ) ;
struct V_30 * V_31 = F_29 ( V_29 ) ;
return V_31 -> V_2 ;
}
static inline void F_30 ( struct V_32 * * V_33 , T_2 * type ,
T_2 * V_34 )
{
struct V_35 * V_36 ;
V_36 = F_31 ( V_33 ) ;
if ( F_32 ( V_36 ) )
return;
* type |= V_36 -> type & V_37 ;
* V_34 |= V_36 -> V_34 & V_37 ;
}
static int F_33 ( struct V_38 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_42 * V_43 = F_34 ( V_39 ) ;
struct V_44 * V_45 = V_43 -> V_45 ;
int V_13 ;
F_35 ( V_45 , V_46 ) ;
F_36 ( V_45 , F_37 ( V_39 ) &
V_46 ) ;
V_13 = F_38 ( V_45 , V_40 , V_41 ) ;
F_39 ( V_39 , F_40 ( V_45 ) &
V_47 ) ;
return V_13 ;
}
static void F_41 ( struct V_48 * V_24 ,
struct V_44 * V_45 ,
int V_13 ,
int (* F_42)( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_51 * V_53 ,
unsigned int V_54 ) )
{
struct V_55 * V_56 ;
struct V_42 * V_43 ;
struct V_38 * V_15 ;
struct V_49 V_50 ;
int V_16 ;
V_56 = F_43 ( V_24 ) ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_50 . V_15 = V_45 ;
V_50 . V_58 = V_24 -> V_58 ;
V_50 . V_18 = V_59 ;
V_13 = F_42 ( & V_50 , V_24 -> V_52 , V_24 -> V_53 , V_24 -> V_60 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
V_15 = F_45 ( V_24 ) ;
V_43 = F_34 ( V_15 ) ;
V_16 = F_16 ( & V_43 -> V_16 ) ;
F_20 () ;
V_56 -> V_26 ( & V_24 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_27 && V_16 && F_46 ( & V_43 -> V_16 ) )
F_47 ( V_15 ) ;
}
static void F_48 ( struct V_11 * V_24 , int V_13 )
{
struct V_42 * V_43 = F_14 ( V_24 -> V_15 ) ;
struct V_44 * V_45 = V_43 -> V_45 ;
F_41 ( F_49 ( V_24 ) , V_45 , V_13 ,
F_50 ( V_45 ) -> V_62 ) ;
}
static void F_51 ( struct V_11 * V_24 , int V_13 )
{
struct V_42 * V_43 = F_14 ( V_24 -> V_15 ) ;
struct V_44 * V_45 = V_43 -> V_45 ;
F_41 ( F_49 ( V_24 ) , V_45 , V_13 ,
F_50 ( V_45 ) -> V_63 ) ;
}
static int F_52 ( struct V_48 * V_24 ,
T_4 V_64 )
{
struct V_55 * V_56 = F_43 ( V_24 ) ;
struct V_38 * V_15 = F_45 ( V_24 ) ;
struct V_1 * V_2 ;
V_2 = F_27 ( F_53 ( V_15 ) ) ;
V_56 -> V_26 = V_24 -> V_61 . V_26 ;
V_24 -> V_61 . V_26 = V_64 ;
return F_10 ( V_2 , & V_24 -> V_61 ) ;
}
static int F_54 ( struct V_48 * V_24 )
{
return F_52 ( V_24 , F_48 ) ;
}
static int F_55 ( struct V_48 * V_24 )
{
return F_52 ( V_24 , F_51 ) ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_28 ( V_15 ) ;
struct V_30 * V_31 = F_29 ( V_29 ) ;
struct V_65 * V_66 = & V_31 -> V_66 ;
struct V_42 * V_43 = F_14 ( V_15 ) ;
struct V_44 * V_67 ;
V_67 = F_57 ( V_66 ) ;
if ( F_32 ( V_67 ) )
return F_58 ( V_67 ) ;
V_43 -> V_45 = V_67 ;
V_15 -> V_68 . V_69 =
sizeof( struct V_55 ) ;
return 0 ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_42 * V_43 = F_14 ( V_15 ) ;
F_60 ( V_43 -> V_45 ) ;
}
static int F_61 ( struct V_28 * V_29 ,
struct V_70 * V_71 )
{
if ( snprintf ( V_29 -> V_71 . V_72 , V_73 ,
L_1 ,
V_71 -> V_72 ) >= V_73 )
return - V_74 ;
memcpy ( V_29 -> V_71 . V_75 , V_71 -> V_75 , V_73 ) ;
V_29 -> V_71 . V_76 = V_71 -> V_76 + 50 ;
V_29 -> V_71 . V_77 = V_71 -> V_77 ;
V_29 -> V_71 . V_78 = V_71 -> V_78 ;
return 0 ;
}
static void * F_62 ( struct V_70 * V_71 , unsigned int V_79 ,
unsigned int V_80 )
{
char * V_81 ;
struct V_28 * V_29 ;
int V_13 ;
V_81 = F_63 ( V_79 + sizeof( * V_29 ) + V_80 , V_82 ) ;
if ( ! V_81 )
return F_64 ( - V_7 ) ;
V_29 = ( void * ) ( V_81 + V_79 ) ;
V_13 = F_61 ( V_29 , V_71 ) ;
if ( V_13 )
goto V_83;
V_57:
return V_81 ;
V_83:
F_65 ( V_81 ) ;
V_81 = F_64 ( V_13 ) ;
goto V_57;
}
static int F_66 ( struct V_84 * V_85 ,
struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_30 * V_43 ;
struct V_28 * V_29 ;
struct V_70 * V_71 ;
T_2 type = V_86 ;
T_2 V_34 = V_87 ;
int V_13 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_71 = F_67 ( V_33 , type , V_34 ) ;
if ( F_32 ( V_71 ) )
return F_58 ( V_71 ) ;
V_29 = F_62 ( V_71 , 0 , sizeof( * V_43 ) ) ;
V_13 = F_58 ( V_29 ) ;
if ( F_32 ( V_29 ) )
goto V_88;
V_43 = F_29 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
V_13 = F_68 ( & V_43 -> V_66 , V_71 , V_29 ,
V_87 | V_89 ) ;
if ( V_13 )
goto V_83;
type = V_90 | V_89 ;
if ( V_71 -> V_91 & V_37 )
type |= V_37 ;
V_29 -> V_71 . V_91 = type ;
V_29 -> V_71 . V_92 = & V_93 ;
V_29 -> V_71 . V_94 . V_95 = V_71 -> V_96 . V_95 ;
V_29 -> V_71 . V_94 . V_97 = V_71 -> V_96 . V_97 ;
V_29 -> V_71 . V_94 . V_98 = V_71 -> V_96 . V_98 ;
V_29 -> V_71 . V_94 . V_99 = V_71 -> V_96 . V_99 ;
V_29 -> V_71 . V_100 = sizeof( struct V_42 ) ;
V_29 -> V_71 . V_101 = F_56 ;
V_29 -> V_71 . V_102 = F_59 ;
V_29 -> V_71 . V_94 . V_103 = F_33 ;
V_29 -> V_71 . V_94 . V_62 = F_54 ;
V_29 -> V_71 . V_94 . V_63 = F_55 ;
V_13 = F_69 ( V_85 , V_29 ) ;
if ( V_13 ) {
F_70 ( & V_43 -> V_66 ) ;
V_83:
F_65 ( V_29 ) ;
}
V_88:
F_71 ( V_71 ) ;
return V_13 ;
}
static int F_72 ( struct V_14 * V_15 )
{
struct V_28 * V_29 = F_28 ( V_15 ) ;
struct V_104 * V_31 = F_29 ( V_29 ) ;
struct V_105 * V_66 = & V_31 -> V_66 ;
struct V_106 * V_43 = F_14 ( V_15 ) ;
struct V_107 * V_108 ;
V_108 = F_73 ( V_66 ) ;
if ( F_32 ( V_108 ) )
return F_58 ( V_108 ) ;
V_43 -> V_45 = V_108 ;
F_74 ( F_75 ( V_15 ) ,
sizeof( struct V_109 ) +
F_76 ( V_108 ) ) ;
return 0 ;
}
static void F_77 ( struct V_14 * V_15 )
{
struct V_106 * V_43 = F_14 ( V_15 ) ;
F_78 ( V_43 -> V_45 ) ;
}
static int F_79 ( struct V_110 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_106 * V_43 = F_80 ( V_39 ) ;
struct V_107 * V_45 = V_43 -> V_45 ;
int V_13 ;
F_81 ( V_45 , V_46 ) ;
F_82 ( V_45 , F_83 ( V_39 ) &
V_46 ) ;
V_13 = F_84 ( V_45 , V_40 , V_41 ) ;
F_85 ( V_39 , F_86 ( V_45 ) &
V_47 ) ;
return V_13 ;
}
static int F_87 ( struct V_111 * V_24 ,
T_4 V_64 )
{
struct V_109 * V_56 = F_88 ( V_24 ) ;
struct V_110 * V_15 = F_89 ( V_24 ) ;
struct V_1 * V_2 =
F_27 ( F_90 ( V_15 ) ) ;
V_56 -> V_26 = V_24 -> V_61 . V_26 ;
V_24 -> V_61 . V_26 = V_64 ;
return F_10 ( V_2 , & V_24 -> V_61 ) ;
}
static void F_91 ( struct V_111 * V_24 , int V_13 )
{
struct V_110 * V_15 = F_89 ( V_24 ) ;
struct V_106 * V_43 = F_80 ( V_15 ) ;
struct V_109 * V_56 = F_88 ( V_24 ) ;
int V_16 = F_16 ( & V_43 -> V_16 ) ;
F_20 () ;
V_56 -> V_26 ( & V_24 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_27 && V_16 && F_46 ( & V_43 -> V_16 ) )
F_92 ( V_15 ) ;
}
static void F_93 ( struct V_11 * V_112 , int V_13 )
{
struct V_106 * V_43 = F_14 ( V_112 -> V_15 ) ;
struct V_107 * V_45 = V_43 -> V_45 ;
struct V_111 * V_24 = F_94 ( V_112 ) ;
struct V_109 * V_56 = F_88 ( V_24 ) ;
struct V_113 * V_50 = & V_56 -> V_50 ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_50 -> V_15 = V_45 ;
V_50 -> V_18 = V_59 ;
V_13 = F_95 ( V_50 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
F_91 ( V_24 , V_13 ) ;
}
static int F_96 ( struct V_111 * V_24 )
{
return F_87 ( V_24 , F_93 ) ;
}
static void F_97 ( struct V_11 * V_112 , int V_13 )
{
struct V_111 * V_24 = F_94 ( V_112 ) ;
struct V_109 * V_56 ;
V_56 = F_88 ( V_24 ) ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_13 = F_98 ( V_24 , & V_56 -> V_50 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
F_91 ( V_24 , V_13 ) ;
}
static int F_99 ( struct V_111 * V_24 )
{
return F_87 ( V_24 , F_97 ) ;
}
static void F_100 ( struct V_11 * V_112 , int V_13 )
{
struct V_111 * V_24 = F_94 ( V_112 ) ;
struct V_109 * V_56 = F_88 ( V_24 ) ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_13 = F_101 ( & V_56 -> V_50 , V_24 -> V_114 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
F_91 ( V_24 , V_13 ) ;
}
static int F_102 ( struct V_111 * V_24 )
{
return F_87 ( V_24 , F_100 ) ;
}
static void F_103 ( struct V_11 * V_112 , int V_13 )
{
struct V_111 * V_24 = F_94 ( V_112 ) ;
struct V_109 * V_56 = F_88 ( V_24 ) ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_13 = F_104 ( V_24 , & V_56 -> V_50 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
F_91 ( V_24 , V_13 ) ;
}
static int F_105 ( struct V_111 * V_24 )
{
return F_87 ( V_24 , F_103 ) ;
}
static void F_106 ( struct V_11 * V_112 , int V_13 )
{
struct V_106 * V_43 = F_14 ( V_112 -> V_15 ) ;
struct V_107 * V_45 = V_43 -> V_45 ;
struct V_111 * V_24 = F_94 ( V_112 ) ;
struct V_109 * V_56 = F_88 ( V_24 ) ;
struct V_113 * V_50 = & V_56 -> V_50 ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
V_50 -> V_15 = V_45 ;
V_50 -> V_18 = V_59 ;
V_13 = F_107 ( V_24 , V_50 ) ;
V_24 -> V_61 . V_26 = V_56 -> V_26 ;
V_57:
F_91 ( V_24 , V_13 ) ;
}
static int F_108 ( struct V_111 * V_24 )
{
return F_87 ( V_24 , F_106 ) ;
}
static int F_109 ( struct V_111 * V_24 , void * V_57 )
{
struct V_109 * V_56 = F_88 ( V_24 ) ;
return F_110 ( & V_56 -> V_50 , V_57 ) ;
}
static int F_111 ( struct V_111 * V_24 , const void * V_115 )
{
struct V_110 * V_15 = F_89 ( V_24 ) ;
struct V_106 * V_43 = F_80 ( V_15 ) ;
struct V_113 * V_50 = F_112 ( V_24 ) ;
V_50 -> V_15 = V_43 -> V_45 ;
V_50 -> V_18 = V_24 -> V_61 . V_18 ;
return F_113 ( V_50 , V_115 ) ;
}
static int F_114 ( struct V_84 * V_85 , struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_104 * V_43 ;
struct V_116 * V_29 ;
struct V_117 * V_118 ;
struct V_70 * V_71 ;
T_2 type = 0 ;
T_2 V_34 = 0 ;
int V_13 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_118 = F_115 ( V_33 [ 1 ] , type , V_34 ) ;
if ( F_32 ( V_118 ) )
return F_58 ( V_118 ) ;
V_71 = & V_118 -> V_61 ;
V_29 = F_62 ( V_71 , F_116 () ,
sizeof( * V_43 ) ) ;
V_13 = F_58 ( V_29 ) ;
if ( F_32 ( V_29 ) )
goto V_88;
V_43 = F_117 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
V_13 = F_118 ( & V_43 -> V_66 , V_118 ,
F_119 ( V_29 ) ) ;
if ( V_13 )
goto V_83;
type = V_89 ;
if ( V_71 -> V_91 & V_37 )
type |= V_37 ;
V_29 -> V_71 . V_119 . V_61 . V_91 = type ;
V_29 -> V_71 . V_119 . V_120 = V_118 -> V_120 ;
V_29 -> V_71 . V_119 . V_121 = V_118 -> V_121 ;
V_29 -> V_71 . V_119 . V_61 . V_100 = sizeof( struct V_106 ) ;
V_29 -> V_71 . V_119 . V_61 . V_101 = F_72 ;
V_29 -> V_71 . V_119 . V_61 . V_102 = F_77 ;
V_29 -> V_71 . V_122 = F_96 ;
V_29 -> V_71 . V_123 = F_99 ;
V_29 -> V_71 . V_124 = F_102 ;
V_29 -> V_71 . V_125 = F_105 ;
V_29 -> V_71 . V_126 = F_109 ;
V_29 -> V_71 . V_127 = F_111 ;
V_29 -> V_71 . V_103 = F_79 ;
V_29 -> V_71 . V_128 = F_108 ;
V_13 = F_120 ( V_85 , V_29 ) ;
if ( V_13 ) {
F_121 ( & V_43 -> V_66 ) ;
V_83:
F_65 ( V_29 ) ;
}
V_88:
F_71 ( V_71 ) ;
return V_13 ;
}
static int F_122 ( struct V_129 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_130 * V_43 = F_123 ( V_39 ) ;
struct V_129 * V_45 = V_43 -> V_45 ;
return F_124 ( V_45 , V_40 , V_41 ) ;
}
static int F_125 ( struct V_129 * V_39 ,
unsigned int V_131 )
{
struct V_130 * V_43 = F_123 ( V_39 ) ;
struct V_129 * V_45 = V_43 -> V_45 ;
return F_126 ( V_45 , V_131 ) ;
}
static void F_127 ( struct V_132 * V_24 ,
struct V_129 * V_45 ,
int V_13 ,
int (* F_42)( struct V_132 * V_24 ) )
{
struct V_133 * V_56 ;
struct V_130 * V_43 ;
T_4 V_64 ;
struct V_129 * V_15 ;
int V_16 ;
V_56 = F_128 ( V_24 ) ;
V_64 = V_56 -> V_26 ;
V_15 = F_129 ( V_24 ) ;
if ( F_44 ( V_13 == - V_27 ) )
goto V_57;
F_130 ( V_24 , V_45 ) ;
V_13 = F_42 ( V_24 ) ;
V_57:
V_43 = F_123 ( V_15 ) ;
V_16 = F_16 ( & V_43 -> V_16 ) ;
F_20 () ;
V_64 ( & V_24 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_27 && V_16 && F_46 ( & V_43 -> V_16 ) )
F_131 ( V_15 ) ;
}
static void F_132 ( struct V_11 * V_134 , int V_13 )
{
struct V_130 * V_43 = F_14 ( V_134 -> V_15 ) ;
struct V_129 * V_45 = V_43 -> V_45 ;
struct V_132 * V_24 ;
V_24 = F_19 ( V_134 , struct V_132 , V_61 ) ;
F_127 ( V_24 , V_45 , V_13 , F_133 ( V_45 ) -> V_62 ) ;
}
static void F_134 ( struct V_11 * V_134 , int V_13 )
{
struct V_130 * V_43 = F_14 ( V_134 -> V_15 ) ;
struct V_129 * V_45 = V_43 -> V_45 ;
struct V_132 * V_24 ;
V_24 = F_19 ( V_134 , struct V_132 , V_61 ) ;
F_127 ( V_24 , V_45 , V_13 , F_133 ( V_45 ) -> V_63 ) ;
}
static int F_135 ( struct V_132 * V_24 ,
T_4 V_64 )
{
struct V_133 * V_56 = F_128 ( V_24 ) ;
struct V_129 * V_15 = F_129 ( V_24 ) ;
struct V_1 * V_2 = F_27 ( F_136 ( V_15 ) ) ;
V_56 -> V_26 = V_24 -> V_61 . V_26 ;
V_24 -> V_61 . V_26 = V_64 ;
return F_10 ( V_2 , & V_24 -> V_61 ) ;
}
static int F_137 ( struct V_132 * V_24 )
{
return F_135 ( V_24 , F_132 ) ;
}
static int F_138 ( struct V_132 * V_24 )
{
return F_135 ( V_24 , F_134 ) ;
}
static int F_139 ( struct V_129 * V_15 )
{
struct V_135 * V_29 = F_140 ( V_15 ) ;
struct V_136 * V_31 = V_136 ( V_29 ) ;
struct V_137 * V_66 = & V_31 -> V_138 ;
struct V_130 * V_43 = F_123 ( V_15 ) ;
struct V_129 * V_67 ;
V_67 = F_141 ( V_66 ) ;
if ( F_32 ( V_67 ) )
return F_58 ( V_67 ) ;
V_43 -> V_45 = V_67 ;
F_142 (
V_15 , F_143 ( ( unsigned ) sizeof( struct V_133 ) ,
F_144 ( V_67 ) ) ) ;
return 0 ;
}
static void F_145 ( struct V_129 * V_15 )
{
struct V_130 * V_43 = F_123 ( V_15 ) ;
F_131 ( V_43 -> V_45 ) ;
}
static int F_146 ( struct V_84 * V_85 ,
struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_136 * V_43 ;
struct V_135 * V_29 ;
struct V_139 * V_71 ;
const char * V_140 ;
T_2 type = 0 ;
T_2 V_34 = V_89 ;
int V_13 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_140 = F_147 ( V_33 [ 1 ] ) ;
if ( F_32 ( V_140 ) )
return F_58 ( V_140 ) ;
V_29 = F_63 ( sizeof( * V_29 ) + sizeof( * V_43 ) , V_82 ) ;
if ( ! V_29 )
return - V_7 ;
V_43 = V_136 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
F_148 ( & V_43 -> V_138 , F_149 ( V_29 ) ) ;
V_13 = F_150 ( & V_43 -> V_138 , V_140 , type , V_34 ) ;
if ( V_13 )
goto V_83;
V_71 = F_151 ( & V_43 -> V_138 ) ;
V_13 = F_61 ( F_149 ( V_29 ) , & V_71 -> V_61 ) ;
if ( V_13 )
goto V_141;
V_29 -> V_71 . V_61 . V_91 = V_89 |
( V_71 -> V_61 . V_91 & V_37 ) ;
V_29 -> V_71 . V_61 . V_100 = sizeof( struct V_130 ) ;
V_29 -> V_71 . V_95 = F_152 ( V_71 ) ;
V_29 -> V_71 . V_142 = F_153 ( V_71 ) ;
V_29 -> V_71 . V_122 = F_139 ;
V_29 -> V_71 . exit = F_145 ;
V_29 -> V_71 . V_103 = F_122 ;
V_29 -> V_71 . V_143 = F_125 ;
V_29 -> V_71 . V_62 = F_137 ;
V_29 -> V_71 . V_63 = F_138 ;
V_13 = F_154 ( V_85 , V_29 ) ;
if ( V_13 ) {
V_141:
F_155 ( & V_43 -> V_138 ) ;
V_83:
F_65 ( V_29 ) ;
}
return V_13 ;
}
static int F_156 ( struct V_84 * V_85 , struct V_32 * * V_33 )
{
struct V_35 * V_36 ;
V_36 = F_31 ( V_33 ) ;
if ( F_32 ( V_36 ) )
return F_58 ( V_36 ) ;
switch ( V_36 -> type & V_36 -> V_34 & V_87 ) {
case V_86 :
return F_66 ( V_85 , V_33 , & V_2 ) ;
case V_144 :
return F_114 ( V_85 , V_33 , & V_2 ) ;
case V_145 :
return F_146 ( V_85 , V_33 , & V_2 ) ;
}
return - V_146 ;
}
static void F_157 ( struct V_28 * V_29 )
{
struct V_30 * V_43 = F_29 ( V_29 ) ;
struct V_104 * V_147 = F_29 ( V_29 ) ;
struct V_136 * V_148 = F_29 ( V_29 ) ;
switch ( V_29 -> V_71 . V_91 & V_87 ) {
case V_149 :
F_121 ( & V_147 -> V_66 ) ;
F_65 ( V_116 ( V_29 ) ) ;
return;
case V_145 :
F_155 ( & V_148 -> V_138 ) ;
F_65 ( V_135 ( V_29 ) ) ;
return;
default:
F_70 ( & V_43 -> V_66 ) ;
F_65 ( V_29 ) ;
}
}
struct V_150 * F_158 ( const char * V_151 ,
T_2 type , T_2 V_34 )
{
char V_152 [ V_73 ] ;
struct V_42 * V_43 ;
struct V_14 * V_15 ;
if ( snprintf ( V_152 , V_73 ,
L_1 , V_151 ) >= V_73 )
return F_64 ( - V_146 ) ;
type = F_159 ( type ) ;
V_34 &= ~ V_87 ;
V_34 |= ( V_153 | V_154 ) ;
V_15 = F_160 ( V_152 , type , V_34 ) ;
if ( F_32 ( V_15 ) )
return F_161 ( V_15 ) ;
if ( V_15 -> V_155 -> V_156 != V_157 ) {
F_162 ( V_15 ) ;
return F_64 ( - V_146 ) ;
}
V_43 = F_14 ( V_15 ) ;
F_163 ( & V_43 -> V_16 , 1 ) ;
return F_164 ( F_165 ( V_15 ) ) ;
}
struct V_44 * F_166 ( struct V_150 * V_15 )
{
struct V_42 * V_43 = F_34 ( & V_15 -> V_61 ) ;
return V_43 -> V_45 ;
}
bool F_167 ( struct V_150 * V_15 )
{
struct V_42 * V_43 = F_34 ( & V_15 -> V_61 ) ;
return F_16 ( & V_43 -> V_16 ) - 1 ;
}
void F_168 ( struct V_150 * V_15 )
{
struct V_42 * V_43 = F_34 ( & V_15 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_16 ) )
F_47 ( & V_15 -> V_61 ) ;
}
struct V_158 * F_169 ( const char * V_151 ,
T_2 type , T_2 V_34 )
{
char V_152 [ V_73 ] ;
struct V_106 * V_43 ;
struct V_110 * V_15 ;
if ( snprintf ( V_152 , V_73 ,
L_1 , V_151 ) >= V_73 )
return F_64 ( - V_146 ) ;
V_15 = F_170 ( V_152 , type , V_34 ) ;
if ( F_32 ( V_15 ) )
return F_161 ( V_15 ) ;
if ( V_15 -> V_61 . V_155 -> V_156 != V_157 ) {
F_92 ( V_15 ) ;
return F_64 ( - V_146 ) ;
}
V_43 = F_80 ( V_15 ) ;
F_163 ( & V_43 -> V_16 , 1 ) ;
return F_171 ( V_15 ) ;
}
struct V_107 * F_172 ( struct V_158 * V_15 )
{
struct V_106 * V_43 = F_80 ( & V_15 -> V_61 ) ;
return V_43 -> V_45 ;
}
struct V_113 * F_112 ( struct V_111 * V_24 )
{
struct V_109 * V_56 = F_88 ( V_24 ) ;
return & V_56 -> V_50 ;
}
bool F_173 ( struct V_158 * V_15 )
{
struct V_106 * V_43 = F_80 ( & V_15 -> V_61 ) ;
return F_16 ( & V_43 -> V_16 ) - 1 ;
}
void F_174 ( struct V_158 * V_15 )
{
struct V_106 * V_43 = F_80 ( & V_15 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_16 ) )
F_92 ( & V_15 -> V_61 ) ;
}
struct V_159 * F_175 ( const char * V_151 ,
T_2 type , T_2 V_34 )
{
char V_152 [ V_73 ] ;
struct V_130 * V_43 ;
struct V_129 * V_15 ;
if ( snprintf ( V_152 , V_73 ,
L_1 , V_151 ) >= V_73 )
return F_64 ( - V_146 ) ;
V_15 = F_176 ( V_152 , type , V_34 ) ;
if ( F_32 ( V_15 ) )
return F_161 ( V_15 ) ;
if ( V_15 -> V_61 . V_155 -> V_156 != V_157 ) {
F_131 ( V_15 ) ;
return F_64 ( - V_146 ) ;
}
V_43 = F_123 ( V_15 ) ;
F_163 ( & V_43 -> V_16 , 1 ) ;
return F_177 ( V_15 ) ;
}
struct V_129 * F_178 ( struct V_159 * V_15 )
{
struct V_130 * V_43 ;
V_43 = F_123 ( & V_15 -> V_61 ) ;
return V_43 -> V_45 ;
}
bool F_179 ( struct V_159 * V_15 )
{
struct V_130 * V_43 = F_123 ( & V_15 -> V_61 ) ;
return F_16 ( & V_43 -> V_16 ) - 1 ;
}
void F_180 ( struct V_159 * V_15 )
{
struct V_130 * V_43 = F_123 ( & V_15 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_16 ) )
F_131 ( & V_15 -> V_61 ) ;
}
static int T_5 F_181 ( void )
{
int V_13 ;
V_13 = F_1 ( & V_2 , V_160 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_182 ( & V_161 ) ;
if ( V_13 )
F_7 ( & V_2 ) ;
return V_13 ;
}
static void T_6 F_183 ( void )
{
F_7 ( & V_2 ) ;
F_184 ( & V_161 ) ;
}
