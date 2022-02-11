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
T_1 * V_14 ;
bool V_15 ;
V_4 = F_11 () ;
V_6 = F_12 ( V_2 -> V_6 ) ;
V_13 = F_13 ( & V_6 -> V_2 , V_12 ) ;
V_14 = F_14 ( V_12 -> V_16 ) ;
V_15 = V_12 -> V_17 & V_18 ;
if ( V_13 == - V_19 && ! V_15 )
goto V_20;
F_15 ( V_4 , V_21 , & V_6 -> V_8 ) ;
if ( ! F_16 ( V_14 ) )
goto V_20;
F_17 ( V_14 ) ;
V_20:
F_18 () ;
return V_13 ;
}
static void V_9 ( struct V_22 * V_8 )
{
struct V_5 * V_6 ;
struct V_11 * V_23 , * V_24 ;
V_6 = F_19 ( V_8 , struct V_5 , V_8 ) ;
F_20 () ;
F_21 () ;
V_24 = F_22 ( & V_6 -> V_2 ) ;
V_23 = F_23 ( & V_6 -> V_2 ) ;
F_24 () ;
F_25 () ;
if ( ! V_23 )
return;
if ( V_24 )
V_24 -> V_25 ( V_24 , - V_26 ) ;
V_23 -> V_25 ( V_23 , 0 ) ;
if ( V_6 -> V_2 . V_10 )
F_26 ( V_21 , & V_6 -> V_8 ) ;
}
static inline struct V_1 * F_27 ( struct V_27 * V_16 )
{
struct V_28 * V_29 = F_28 ( V_16 ) ;
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
static void F_41 ( struct V_48 * V_23 ,
struct V_44 * V_45 ,
int V_13 ,
int (* F_42)( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_51 * V_53 ,
unsigned int V_54 ) )
{
struct V_55 * V_56 ;
struct V_42 * V_43 ;
struct V_38 * V_16 ;
struct V_49 V_50 ;
int V_14 ;
V_56 = F_43 ( V_23 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_50 . V_16 = V_45 ;
V_50 . V_58 = V_23 -> V_58 ;
V_50 . V_17 = V_59 ;
V_13 = F_42 ( & V_50 , V_23 -> V_52 , V_23 -> V_53 , V_23 -> V_60 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
V_16 = F_45 ( V_23 ) ;
V_43 = F_34 ( V_16 ) ;
V_14 = F_16 ( & V_43 -> V_14 ) ;
F_20 () ;
V_56 -> V_25 ( & V_23 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_26 && V_14 && F_46 ( & V_43 -> V_14 ) )
F_47 ( V_16 ) ;
}
static void F_48 ( struct V_11 * V_23 , int V_13 )
{
struct V_42 * V_43 = F_14 ( V_23 -> V_16 ) ;
struct V_44 * V_45 = V_43 -> V_45 ;
F_41 ( F_49 ( V_23 ) , V_45 , V_13 ,
F_50 ( V_45 ) -> V_62 ) ;
}
static void F_51 ( struct V_11 * V_23 , int V_13 )
{
struct V_42 * V_43 = F_14 ( V_23 -> V_16 ) ;
struct V_44 * V_45 = V_43 -> V_45 ;
F_41 ( F_49 ( V_23 ) , V_45 , V_13 ,
F_50 ( V_45 ) -> V_63 ) ;
}
static int F_52 ( struct V_48 * V_23 ,
T_4 V_64 )
{
struct V_55 * V_56 = F_43 ( V_23 ) ;
struct V_38 * V_16 = F_45 ( V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_27 ( F_53 ( V_16 ) ) ;
V_56 -> V_25 = V_23 -> V_61 . V_25 ;
V_23 -> V_61 . V_25 = V_64 ;
return F_10 ( V_2 , & V_23 -> V_61 ) ;
}
static int F_54 ( struct V_48 * V_23 )
{
return F_52 ( V_23 , F_48 ) ;
}
static int F_55 ( struct V_48 * V_23 )
{
return F_52 ( V_23 , F_51 ) ;
}
static int F_56 ( struct V_27 * V_16 )
{
struct V_28 * V_29 = F_28 ( V_16 ) ;
struct V_30 * V_31 = F_29 ( V_29 ) ;
struct V_65 * V_66 = & V_31 -> V_66 ;
struct V_42 * V_43 = F_14 ( V_16 ) ;
struct V_44 * V_67 ;
V_67 = F_57 ( V_66 ) ;
if ( F_32 ( V_67 ) )
return F_58 ( V_67 ) ;
V_43 -> V_45 = V_67 ;
V_16 -> V_68 . V_69 =
sizeof( struct V_55 ) ;
return 0 ;
}
static void F_59 ( struct V_27 * V_16 )
{
struct V_42 * V_43 = F_14 ( V_16 ) ;
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
static int F_72 ( struct V_104 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_105 * V_43 = F_73 ( V_39 ) ;
struct V_104 * V_45 = V_43 -> V_45 ;
int V_13 ;
F_74 ( V_45 , V_46 ) ;
F_75 ( V_45 , F_76 ( V_39 ) &
V_46 ) ;
V_13 = F_77 ( V_45 , V_40 , V_41 ) ;
F_75 ( V_39 , F_76 ( V_45 ) &
V_47 ) ;
return V_13 ;
}
static void F_78 ( struct V_106 * V_23 , int V_13 )
{
struct V_104 * V_16 = F_79 ( V_23 ) ;
struct V_105 * V_43 = F_73 ( V_16 ) ;
struct V_107 * V_56 = F_80 ( V_23 ) ;
int V_14 = F_16 ( & V_43 -> V_14 ) ;
F_20 () ;
V_56 -> V_25 ( & V_23 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_26 && V_14 && F_46 ( & V_43 -> V_14 ) )
F_81 ( V_16 ) ;
}
static void F_82 ( struct V_11 * V_61 ,
int V_13 )
{
struct V_106 * V_23 = F_83 ( V_61 ) ;
struct V_107 * V_56 = F_80 ( V_23 ) ;
struct V_104 * V_16 = F_79 ( V_23 ) ;
struct V_105 * V_43 = F_73 ( V_16 ) ;
struct V_104 * V_45 = V_43 -> V_45 ;
F_84 ( V_108 , V_45 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
F_85 ( V_108 , V_45 ) ;
F_86 ( V_108 , V_59 ,
NULL , NULL ) ;
F_87 ( V_108 , V_23 -> V_53 , V_23 -> V_52 , V_23 -> V_109 ,
V_23 -> V_110 ) ;
V_13 = F_88 ( V_108 ) ;
F_89 ( V_108 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_78 ( V_23 , V_13 ) ;
}
static void F_90 ( struct V_11 * V_61 ,
int V_13 )
{
struct V_106 * V_23 = F_83 ( V_61 ) ;
struct V_107 * V_56 = F_80 ( V_23 ) ;
struct V_104 * V_16 = F_79 ( V_23 ) ;
struct V_105 * V_43 = F_73 ( V_16 ) ;
struct V_104 * V_45 = V_43 -> V_45 ;
F_84 ( V_108 , V_45 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
F_85 ( V_108 , V_45 ) ;
F_86 ( V_108 , V_59 ,
NULL , NULL ) ;
F_87 ( V_108 , V_23 -> V_53 , V_23 -> V_52 , V_23 -> V_109 ,
V_23 -> V_110 ) ;
V_13 = F_91 ( V_108 ) ;
F_89 ( V_108 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_78 ( V_23 , V_13 ) ;
}
static int F_92 ( struct V_106 * V_23 ,
T_4 V_64 )
{
struct V_107 * V_56 = F_80 ( V_23 ) ;
struct V_104 * V_16 = F_79 ( V_23 ) ;
struct V_1 * V_2 ;
V_2 = F_27 ( F_93 ( V_16 ) ) ;
V_56 -> V_25 = V_23 -> V_61 . V_25 ;
V_23 -> V_61 . V_25 = V_64 ;
return F_10 ( V_2 , & V_23 -> V_61 ) ;
}
static int F_94 ( struct V_106 * V_23 )
{
return F_92 ( V_23 , F_82 ) ;
}
static int F_95 ( struct V_106 * V_23 )
{
return F_92 ( V_23 , F_90 ) ;
}
static int F_96 ( struct V_104 * V_16 )
{
struct V_111 * V_29 = F_97 ( V_16 ) ;
struct V_112 * V_31 = F_98 ( V_29 ) ;
struct V_113 * V_66 = & V_31 -> V_66 ;
struct V_105 * V_43 = F_73 ( V_16 ) ;
struct V_104 * V_67 ;
V_67 = F_99 ( V_66 ) ;
if ( F_32 ( V_67 ) )
return F_58 ( V_67 ) ;
V_43 -> V_45 = V_67 ;
F_100 (
V_16 , sizeof( struct V_107 ) ) ;
return 0 ;
}
static void F_101 ( struct V_104 * V_16 )
{
struct V_105 * V_43 = F_73 ( V_16 ) ;
F_81 ( V_43 -> V_45 ) ;
}
static void F_102 ( struct V_111 * V_29 )
{
struct V_112 * V_43 = F_98 ( V_29 ) ;
F_103 ( & V_43 -> V_66 ) ;
}
static int F_104 ( struct V_84 * V_85 ,
struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_112 * V_43 ;
struct V_111 * V_29 ;
struct V_114 * V_71 ;
const char * V_115 ;
T_2 type ;
T_2 V_34 ;
int V_13 ;
type = 0 ;
V_34 = V_89 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_115 = F_105 ( V_33 [ 1 ] ) ;
if ( F_32 ( V_115 ) )
return F_58 ( V_115 ) ;
V_29 = F_63 ( sizeof( * V_29 ) + sizeof( * V_43 ) , V_82 ) ;
if ( ! V_29 )
return - V_7 ;
V_43 = F_98 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
F_106 ( & V_43 -> V_66 , F_107 ( V_29 ) ) ;
V_13 = F_108 ( & V_43 -> V_66 , V_115 , type , V_34 ) ;
if ( V_13 )
goto V_83;
V_71 = F_109 ( & V_43 -> V_66 ) ;
V_13 = F_61 ( F_107 ( V_29 ) , & V_71 -> V_61 ) ;
if ( V_13 )
goto V_116;
V_29 -> V_71 . V_61 . V_91 = V_89 |
( V_71 -> V_61 . V_91 & V_37 ) ;
V_29 -> V_71 . V_95 = F_110 ( V_71 ) ;
V_29 -> V_71 . V_117 = F_111 ( V_71 ) ;
V_29 -> V_71 . V_97 = F_112 ( V_71 ) ;
V_29 -> V_71 . V_98 = F_113 ( V_71 ) ;
V_29 -> V_71 . V_61 . V_100 = sizeof( struct V_105 ) ;
V_29 -> V_71 . V_118 = F_96 ;
V_29 -> V_71 . exit = F_101 ;
V_29 -> V_71 . V_103 = F_72 ;
V_29 -> V_71 . V_62 = F_94 ;
V_29 -> V_71 . V_63 = F_95 ;
V_29 -> free = F_102 ;
V_13 = F_114 ( V_85 , V_29 ) ;
if ( V_13 ) {
V_116:
F_103 ( & V_43 -> V_66 ) ;
V_83:
F_65 ( V_29 ) ;
}
return V_13 ;
}
static int F_115 ( struct V_27 * V_16 )
{
struct V_28 * V_29 = F_28 ( V_16 ) ;
struct V_119 * V_31 = F_29 ( V_29 ) ;
struct V_120 * V_66 = & V_31 -> V_66 ;
struct V_121 * V_43 = F_14 ( V_16 ) ;
struct V_122 * V_123 ;
V_123 = F_116 ( V_66 ) ;
if ( F_32 ( V_123 ) )
return F_58 ( V_123 ) ;
V_43 -> V_45 = V_123 ;
F_117 ( F_118 ( V_16 ) ,
sizeof( struct V_124 ) +
F_119 ( V_123 ) ) ;
return 0 ;
}
static void F_120 ( struct V_27 * V_16 )
{
struct V_121 * V_43 = F_14 ( V_16 ) ;
F_121 ( V_43 -> V_45 ) ;
}
static int F_122 ( struct V_125 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_121 * V_43 = F_123 ( V_39 ) ;
struct V_122 * V_45 = V_43 -> V_45 ;
int V_13 ;
F_124 ( V_45 , V_46 ) ;
F_125 ( V_45 , F_126 ( V_39 ) &
V_46 ) ;
V_13 = F_127 ( V_45 , V_40 , V_41 ) ;
F_128 ( V_39 , F_129 ( V_45 ) &
V_47 ) ;
return V_13 ;
}
static int F_130 ( struct V_126 * V_23 ,
T_4 V_64 )
{
struct V_124 * V_56 = F_131 ( V_23 ) ;
struct V_125 * V_16 = F_132 ( V_23 ) ;
struct V_1 * V_2 =
F_27 ( F_133 ( V_16 ) ) ;
V_56 -> V_25 = V_23 -> V_61 . V_25 ;
V_23 -> V_61 . V_25 = V_64 ;
return F_10 ( V_2 , & V_23 -> V_61 ) ;
}
static void F_134 ( struct V_126 * V_23 , int V_13 )
{
struct V_125 * V_16 = F_132 ( V_23 ) ;
struct V_121 * V_43 = F_123 ( V_16 ) ;
struct V_124 * V_56 = F_131 ( V_23 ) ;
int V_14 = F_16 ( & V_43 -> V_14 ) ;
F_20 () ;
V_56 -> V_25 ( & V_23 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_26 && V_14 && F_46 ( & V_43 -> V_14 ) )
F_135 ( V_16 ) ;
}
static void F_136 ( struct V_11 * V_127 , int V_13 )
{
struct V_121 * V_43 = F_14 ( V_127 -> V_16 ) ;
struct V_122 * V_45 = V_43 -> V_45 ;
struct V_126 * V_23 = F_137 ( V_127 ) ;
struct V_124 * V_56 = F_131 ( V_23 ) ;
struct V_128 * V_50 = & V_56 -> V_50 ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_50 -> V_16 = V_45 ;
V_50 -> V_17 = V_59 ;
V_13 = F_138 ( V_50 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_134 ( V_23 , V_13 ) ;
}
static int F_139 ( struct V_126 * V_23 )
{
return F_130 ( V_23 , F_136 ) ;
}
static void F_140 ( struct V_11 * V_127 , int V_13 )
{
struct V_126 * V_23 = F_137 ( V_127 ) ;
struct V_124 * V_56 ;
V_56 = F_131 ( V_23 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_13 = F_141 ( V_23 , & V_56 -> V_50 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_134 ( V_23 , V_13 ) ;
}
static int F_142 ( struct V_126 * V_23 )
{
return F_130 ( V_23 , F_140 ) ;
}
static void F_143 ( struct V_11 * V_127 , int V_13 )
{
struct V_126 * V_23 = F_137 ( V_127 ) ;
struct V_124 * V_56 = F_131 ( V_23 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_13 = F_144 ( & V_56 -> V_50 , V_23 -> V_129 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_134 ( V_23 , V_13 ) ;
}
static int F_145 ( struct V_126 * V_23 )
{
return F_130 ( V_23 , F_143 ) ;
}
static void F_146 ( struct V_11 * V_127 , int V_13 )
{
struct V_126 * V_23 = F_137 ( V_127 ) ;
struct V_124 * V_56 = F_131 ( V_23 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_13 = F_147 ( V_23 , & V_56 -> V_50 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_134 ( V_23 , V_13 ) ;
}
static int F_148 ( struct V_126 * V_23 )
{
return F_130 ( V_23 , F_146 ) ;
}
static void F_149 ( struct V_11 * V_127 , int V_13 )
{
struct V_121 * V_43 = F_14 ( V_127 -> V_16 ) ;
struct V_122 * V_45 = V_43 -> V_45 ;
struct V_126 * V_23 = F_137 ( V_127 ) ;
struct V_124 * V_56 = F_131 ( V_23 ) ;
struct V_128 * V_50 = & V_56 -> V_50 ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
V_50 -> V_16 = V_45 ;
V_50 -> V_17 = V_59 ;
V_13 = F_150 ( V_23 , V_50 ) ;
V_23 -> V_61 . V_25 = V_56 -> V_25 ;
V_57:
F_134 ( V_23 , V_13 ) ;
}
static int F_151 ( struct V_126 * V_23 )
{
return F_130 ( V_23 , F_149 ) ;
}
static int F_152 ( struct V_126 * V_23 , void * V_57 )
{
struct V_124 * V_56 = F_131 ( V_23 ) ;
return F_153 ( & V_56 -> V_50 , V_57 ) ;
}
static int F_154 ( struct V_126 * V_23 , const void * V_130 )
{
struct V_125 * V_16 = F_132 ( V_23 ) ;
struct V_121 * V_43 = F_123 ( V_16 ) ;
struct V_128 * V_50 = F_155 ( V_23 ) ;
V_50 -> V_16 = V_43 -> V_45 ;
V_50 -> V_17 = V_23 -> V_61 . V_17 ;
return F_156 ( V_50 , V_130 ) ;
}
static int F_157 ( struct V_84 * V_85 , struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_119 * V_43 ;
struct V_131 * V_29 ;
struct V_132 * V_133 ;
struct V_70 * V_71 ;
T_2 type = 0 ;
T_2 V_34 = 0 ;
int V_13 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_133 = F_158 ( V_33 [ 1 ] , type , V_34 ) ;
if ( F_32 ( V_133 ) )
return F_58 ( V_133 ) ;
V_71 = & V_133 -> V_61 ;
V_29 = F_62 ( V_71 , F_159 () ,
sizeof( * V_43 ) ) ;
V_13 = F_58 ( V_29 ) ;
if ( F_32 ( V_29 ) )
goto V_88;
V_43 = F_160 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
V_13 = F_161 ( & V_43 -> V_66 , V_133 ,
F_162 ( V_29 ) ) ;
if ( V_13 )
goto V_83;
type = V_89 ;
if ( V_71 -> V_91 & V_37 )
type |= V_37 ;
V_29 -> V_71 . V_134 . V_61 . V_91 = type ;
V_29 -> V_71 . V_134 . V_135 = V_133 -> V_135 ;
V_29 -> V_71 . V_134 . V_136 = V_133 -> V_136 ;
V_29 -> V_71 . V_134 . V_61 . V_100 = sizeof( struct V_121 ) ;
V_29 -> V_71 . V_134 . V_61 . V_101 = F_115 ;
V_29 -> V_71 . V_134 . V_61 . V_102 = F_120 ;
V_29 -> V_71 . V_118 = F_139 ;
V_29 -> V_71 . V_137 = F_142 ;
V_29 -> V_71 . V_138 = F_145 ;
V_29 -> V_71 . V_139 = F_148 ;
V_29 -> V_71 . V_140 = F_152 ;
V_29 -> V_71 . V_141 = F_154 ;
V_29 -> V_71 . V_103 = F_122 ;
V_29 -> V_71 . V_142 = F_151 ;
V_13 = F_163 ( V_85 , V_29 ) ;
if ( V_13 ) {
F_164 ( & V_43 -> V_66 ) ;
V_83:
F_65 ( V_29 ) ;
}
V_88:
F_71 ( V_71 ) ;
return V_13 ;
}
static int F_165 ( struct V_143 * V_39 ,
const T_3 * V_40 , unsigned int V_41 )
{
struct V_144 * V_43 = F_166 ( V_39 ) ;
struct V_143 * V_45 = V_43 -> V_45 ;
return F_167 ( V_45 , V_40 , V_41 ) ;
}
static int F_168 ( struct V_143 * V_39 ,
unsigned int V_145 )
{
struct V_144 * V_43 = F_166 ( V_39 ) ;
struct V_143 * V_45 = V_43 -> V_45 ;
return F_169 ( V_45 , V_145 ) ;
}
static void F_170 ( struct V_146 * V_23 ,
struct V_143 * V_45 ,
int V_13 ,
int (* F_42)( struct V_146 * V_23 ) )
{
struct V_147 * V_56 ;
struct V_144 * V_43 ;
T_4 V_64 ;
struct V_143 * V_16 ;
int V_14 ;
V_56 = F_171 ( V_23 ) ;
V_64 = V_56 -> V_25 ;
V_16 = F_172 ( V_23 ) ;
if ( F_44 ( V_13 == - V_26 ) )
goto V_57;
F_173 ( V_23 , V_45 ) ;
V_13 = F_42 ( V_23 ) ;
V_57:
V_43 = F_166 ( V_16 ) ;
V_14 = F_16 ( & V_43 -> V_14 ) ;
F_20 () ;
V_64 ( & V_23 -> V_61 , V_13 ) ;
F_25 () ;
if ( V_13 != - V_26 && V_14 && F_46 ( & V_43 -> V_14 ) )
F_174 ( V_16 ) ;
}
static void F_175 ( struct V_11 * V_148 , int V_13 )
{
struct V_144 * V_43 = F_14 ( V_148 -> V_16 ) ;
struct V_143 * V_45 = V_43 -> V_45 ;
struct V_146 * V_23 ;
V_23 = F_19 ( V_148 , struct V_146 , V_61 ) ;
F_170 ( V_23 , V_45 , V_13 , F_176 ( V_45 ) -> V_62 ) ;
}
static void F_177 ( struct V_11 * V_148 , int V_13 )
{
struct V_144 * V_43 = F_14 ( V_148 -> V_16 ) ;
struct V_143 * V_45 = V_43 -> V_45 ;
struct V_146 * V_23 ;
V_23 = F_19 ( V_148 , struct V_146 , V_61 ) ;
F_170 ( V_23 , V_45 , V_13 , F_176 ( V_45 ) -> V_63 ) ;
}
static int F_178 ( struct V_146 * V_23 ,
T_4 V_64 )
{
struct V_147 * V_56 = F_171 ( V_23 ) ;
struct V_143 * V_16 = F_172 ( V_23 ) ;
struct V_1 * V_2 = F_27 ( F_179 ( V_16 ) ) ;
V_56 -> V_25 = V_23 -> V_61 . V_25 ;
V_23 -> V_61 . V_25 = V_64 ;
return F_10 ( V_2 , & V_23 -> V_61 ) ;
}
static int F_180 ( struct V_146 * V_23 )
{
return F_178 ( V_23 , F_175 ) ;
}
static int F_181 ( struct V_146 * V_23 )
{
return F_178 ( V_23 , F_177 ) ;
}
static int F_182 ( struct V_143 * V_16 )
{
struct V_149 * V_29 = F_183 ( V_16 ) ;
struct V_150 * V_31 = V_150 ( V_29 ) ;
struct V_151 * V_66 = & V_31 -> V_152 ;
struct V_144 * V_43 = F_166 ( V_16 ) ;
struct V_143 * V_67 ;
V_67 = F_184 ( V_66 ) ;
if ( F_32 ( V_67 ) )
return F_58 ( V_67 ) ;
V_43 -> V_45 = V_67 ;
F_185 (
V_16 , F_186 ( ( unsigned ) sizeof( struct V_147 ) ,
F_187 ( V_67 ) ) ) ;
return 0 ;
}
static void F_188 ( struct V_143 * V_16 )
{
struct V_144 * V_43 = F_166 ( V_16 ) ;
F_174 ( V_43 -> V_45 ) ;
}
static int F_189 ( struct V_84 * V_85 ,
struct V_32 * * V_33 ,
struct V_1 * V_2 )
{
struct V_150 * V_43 ;
struct V_149 * V_29 ;
struct V_153 * V_71 ;
const char * V_115 ;
T_2 type = 0 ;
T_2 V_34 = V_89 ;
int V_13 ;
F_30 ( V_33 , & type , & V_34 ) ;
V_115 = F_105 ( V_33 [ 1 ] ) ;
if ( F_32 ( V_115 ) )
return F_58 ( V_115 ) ;
V_29 = F_63 ( sizeof( * V_29 ) + sizeof( * V_43 ) , V_82 ) ;
if ( ! V_29 )
return - V_7 ;
V_43 = V_150 ( V_29 ) ;
V_43 -> V_2 = V_2 ;
F_190 ( & V_43 -> V_152 , F_191 ( V_29 ) ) ;
V_13 = F_192 ( & V_43 -> V_152 , V_115 , type , V_34 ) ;
if ( V_13 )
goto V_83;
V_71 = F_193 ( & V_43 -> V_152 ) ;
V_13 = F_61 ( F_191 ( V_29 ) , & V_71 -> V_61 ) ;
if ( V_13 )
goto V_154;
V_29 -> V_71 . V_61 . V_91 = V_89 |
( V_71 -> V_61 . V_91 & V_37 ) ;
V_29 -> V_71 . V_61 . V_100 = sizeof( struct V_144 ) ;
V_29 -> V_71 . V_95 = F_194 ( V_71 ) ;
V_29 -> V_71 . V_155 = F_195 ( V_71 ) ;
V_29 -> V_71 . V_118 = F_182 ;
V_29 -> V_71 . exit = F_188 ;
V_29 -> V_71 . V_103 = F_165 ;
V_29 -> V_71 . V_156 = F_168 ;
V_29 -> V_71 . V_62 = F_180 ;
V_29 -> V_71 . V_63 = F_181 ;
V_13 = F_196 ( V_85 , V_29 ) ;
if ( V_13 ) {
V_154:
F_197 ( & V_43 -> V_152 ) ;
V_83:
F_65 ( V_29 ) ;
}
return V_13 ;
}
static int F_198 ( struct V_84 * V_85 , struct V_32 * * V_33 )
{
struct V_35 * V_36 ;
V_36 = F_31 ( V_33 ) ;
if ( F_32 ( V_36 ) )
return F_58 ( V_36 ) ;
switch ( V_36 -> type & V_36 -> V_34 & V_87 ) {
case V_86 :
if ( ( V_36 -> type & V_87 ) ==
V_86 )
return F_66 ( V_85 , V_33 , & V_2 ) ;
return F_104 ( V_85 , V_33 , & V_2 ) ;
case V_157 :
return F_157 ( V_85 , V_33 , & V_2 ) ;
case V_158 :
return F_189 ( V_85 , V_33 , & V_2 ) ;
}
return - V_159 ;
}
static void F_199 ( struct V_28 * V_29 )
{
struct V_30 * V_43 = F_29 ( V_29 ) ;
struct V_119 * V_160 = F_29 ( V_29 ) ;
struct V_150 * V_161 = F_29 ( V_29 ) ;
switch ( V_29 -> V_71 . V_91 & V_87 ) {
case V_162 :
F_164 ( & V_160 -> V_66 ) ;
F_65 ( V_131 ( V_29 ) ) ;
return;
case V_158 :
F_197 ( & V_161 -> V_152 ) ;
F_65 ( V_149 ( V_29 ) ) ;
return;
default:
F_70 ( & V_43 -> V_66 ) ;
F_65 ( V_29 ) ;
}
}
struct V_163 * F_200 ( const char * V_164 ,
T_2 type , T_2 V_34 )
{
char V_165 [ V_73 ] ;
struct V_42 * V_43 ;
struct V_27 * V_16 ;
if ( snprintf ( V_165 , V_73 ,
L_1 , V_164 ) >= V_73 )
return F_64 ( - V_159 ) ;
type = F_201 ( type ) ;
V_34 &= ~ V_87 ;
V_34 |= ( V_166 | V_167 ) ;
V_16 = F_202 ( V_165 , type , V_34 ) ;
if ( F_32 ( V_16 ) )
return F_203 ( V_16 ) ;
if ( V_16 -> V_168 -> V_169 != V_170 ) {
F_204 ( V_16 ) ;
return F_64 ( - V_159 ) ;
}
V_43 = F_14 ( V_16 ) ;
F_205 ( & V_43 -> V_14 , 1 ) ;
return F_206 ( F_207 ( V_16 ) ) ;
}
struct V_44 * F_208 ( struct V_163 * V_16 )
{
struct V_42 * V_43 = F_34 ( & V_16 -> V_61 ) ;
return V_43 -> V_45 ;
}
bool F_209 ( struct V_163 * V_16 )
{
struct V_42 * V_43 = F_34 ( & V_16 -> V_61 ) ;
return F_16 ( & V_43 -> V_14 ) - 1 ;
}
void F_210 ( struct V_163 * V_16 )
{
struct V_42 * V_43 = F_34 ( & V_16 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_14 ) )
F_47 ( & V_16 -> V_61 ) ;
}
struct V_171 * F_211 ( const char * V_164 ,
T_2 type , T_2 V_34 )
{
char V_165 [ V_73 ] ;
struct V_105 * V_43 ;
struct V_104 * V_16 ;
if ( snprintf ( V_165 , V_73 ,
L_1 , V_164 ) >= V_73 )
return F_64 ( - V_159 ) ;
V_16 = F_212 ( V_165 , type , V_34 ) ;
if ( F_32 ( V_16 ) )
return F_203 ( V_16 ) ;
if ( V_16 -> V_61 . V_168 -> V_169 != V_170 ) {
F_81 ( V_16 ) ;
return F_64 ( - V_159 ) ;
}
V_43 = F_73 ( V_16 ) ;
F_205 ( & V_43 -> V_14 , 1 ) ;
return F_19 ( V_16 , struct V_171 , V_61 ) ;
}
struct V_104 * F_213 ( struct V_171 * V_16 )
{
struct V_105 * V_43 = F_73 ( & V_16 -> V_61 ) ;
return V_43 -> V_45 ;
}
bool F_214 ( struct V_171 * V_16 )
{
struct V_105 * V_43 = F_73 ( & V_16 -> V_61 ) ;
return F_16 ( & V_43 -> V_14 ) - 1 ;
}
void F_215 ( struct V_171 * V_16 )
{
struct V_105 * V_43 = F_73 ( & V_16 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_14 ) )
F_81 ( & V_16 -> V_61 ) ;
}
struct V_172 * F_216 ( const char * V_164 ,
T_2 type , T_2 V_34 )
{
char V_165 [ V_73 ] ;
struct V_121 * V_43 ;
struct V_125 * V_16 ;
if ( snprintf ( V_165 , V_73 ,
L_1 , V_164 ) >= V_73 )
return F_64 ( - V_159 ) ;
V_16 = F_217 ( V_165 , type , V_34 ) ;
if ( F_32 ( V_16 ) )
return F_203 ( V_16 ) ;
if ( V_16 -> V_61 . V_168 -> V_169 != V_170 ) {
F_135 ( V_16 ) ;
return F_64 ( - V_159 ) ;
}
V_43 = F_123 ( V_16 ) ;
F_205 ( & V_43 -> V_14 , 1 ) ;
return F_218 ( V_16 ) ;
}
struct V_122 * F_219 ( struct V_172 * V_16 )
{
struct V_121 * V_43 = F_123 ( & V_16 -> V_61 ) ;
return V_43 -> V_45 ;
}
struct V_128 * F_155 ( struct V_126 * V_23 )
{
struct V_124 * V_56 = F_131 ( V_23 ) ;
return & V_56 -> V_50 ;
}
bool F_220 ( struct V_172 * V_16 )
{
struct V_121 * V_43 = F_123 ( & V_16 -> V_61 ) ;
return F_16 ( & V_43 -> V_14 ) - 1 ;
}
void F_221 ( struct V_172 * V_16 )
{
struct V_121 * V_43 = F_123 ( & V_16 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_14 ) )
F_135 ( & V_16 -> V_61 ) ;
}
struct V_173 * F_222 ( const char * V_164 ,
T_2 type , T_2 V_34 )
{
char V_165 [ V_73 ] ;
struct V_144 * V_43 ;
struct V_143 * V_16 ;
if ( snprintf ( V_165 , V_73 ,
L_1 , V_164 ) >= V_73 )
return F_64 ( - V_159 ) ;
V_16 = F_223 ( V_165 , type , V_34 ) ;
if ( F_32 ( V_16 ) )
return F_203 ( V_16 ) ;
if ( V_16 -> V_61 . V_168 -> V_169 != V_170 ) {
F_174 ( V_16 ) ;
return F_64 ( - V_159 ) ;
}
V_43 = F_166 ( V_16 ) ;
F_205 ( & V_43 -> V_14 , 1 ) ;
return F_224 ( V_16 ) ;
}
struct V_143 * F_225 ( struct V_173 * V_16 )
{
struct V_144 * V_43 ;
V_43 = F_166 ( & V_16 -> V_61 ) ;
return V_43 -> V_45 ;
}
bool F_226 ( struct V_173 * V_16 )
{
struct V_144 * V_43 = F_166 ( & V_16 -> V_61 ) ;
return F_16 ( & V_43 -> V_14 ) - 1 ;
}
void F_227 ( struct V_173 * V_16 )
{
struct V_144 * V_43 = F_166 ( & V_16 -> V_61 ) ;
if ( F_46 ( & V_43 -> V_14 ) )
F_174 ( & V_16 -> V_61 ) ;
}
static int T_5 F_228 ( void )
{
int V_13 ;
V_13 = F_1 ( & V_2 , V_174 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_229 ( & V_175 ) ;
if ( V_13 )
F_7 ( & V_2 ) ;
return V_13 ;
}
static void T_6 F_230 ( void )
{
F_7 ( & V_2 ) ;
F_231 ( & V_175 ) ;
}
