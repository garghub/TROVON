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
int V_26 ;
V_26 = F_20 ( V_17 -> V_23 , ( V_38 * ) V_19 -> V_25 ) ;
if ( V_26 < 0 )
F_21 ( L_4 ,
V_26 , V_19 -> V_36 , V_19 -> V_37 ) ;
}
static int
F_22 ( struct V_2 * V_3 , const struct V_39 * V_40 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
struct V_18 * V_19 = V_22 -> V_19 ;
int V_41 = - V_42 ;
T_2 V_43 = F_23 ( V_40 -> V_44 ) ;
T_2 V_45 = F_23 ( V_40 -> V_46 ) ;
T_2 V_47 = F_23 ( V_40 -> V_48 ) ;
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
V_25 = F_24 ( V_17 -> V_23 , & V_60 ) ;
if ( V_25 ) {
memcpy ( V_19 -> V_25 , V_25 , V_60 ) ;
V_19 -> V_57 = F_16 ;
V_19 -> V_32 = V_17 ;
F_25 ( V_17 -> V_23 , V_25 ) ;
V_41 = V_60 ;
}
}
break;
default:
V_56:
F_26 ( V_22 , L_5 ,
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
static int F_27 ( struct V_2 * V_3 , unsigned V_64 , unsigned V_65 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( V_64 == V_17 -> V_55 ) {
if ( V_17 -> V_28 -> V_66 ) {
F_26 ( V_22 , L_8 , V_64 ) ;
F_28 ( V_17 -> V_28 ) ;
}
if ( ! V_17 -> V_28 -> V_67 ) {
F_26 ( V_22 , L_9 , V_64 ) ;
if ( F_29 ( V_22 -> V_62 , V_3 , V_17 -> V_28 ) )
goto V_68;
}
F_30 ( V_17 -> V_28 ) ;
V_17 -> V_28 -> V_66 = V_17 ;
} else if ( V_64 == V_17 -> V_69 ) {
struct V_70 * V_71 ;
if ( V_17 -> V_4 . V_72 -> V_66 ) {
F_15 ( V_22 , L_10 ) ;
F_31 ( & V_17 -> V_4 ) ;
}
if ( ! V_17 -> V_4 . V_72 -> V_67 || ! V_17 -> V_4 . V_73 -> V_67 ) {
F_15 ( V_22 , L_11 ) ;
if ( F_29 ( V_22 -> V_62 , V_3 ,
V_17 -> V_4 . V_72 ) ||
F_29 ( V_22 -> V_62 , V_3 ,
V_17 -> V_4 . V_73 ) ) {
V_17 -> V_4 . V_72 -> V_67 = NULL ;
V_17 -> V_4 . V_73 -> V_67 = NULL ;
goto V_68;
}
}
V_17 -> V_4 . V_74 = false ;
V_17 -> V_4 . V_75 = 0 ;
F_15 ( V_22 , L_12 ) ;
V_71 = F_32 ( & V_17 -> V_4 ) ;
if ( F_33 ( V_71 ) )
return F_34 ( V_71 ) ;
F_35 ( V_17 -> V_23 , V_71 ,
& V_17 -> V_4 . V_75 ) ;
} else
goto V_68;
return 0 ;
V_68:
return - V_76 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_3 -> V_23 -> V_22 ;
if ( ! V_17 -> V_28 -> V_66 )
return;
F_15 ( V_22 , L_13 ) ;
F_37 ( V_17 -> V_23 ) ;
F_31 ( & V_17 -> V_4 ) ;
F_28 ( V_17 -> V_28 ) ;
V_17 -> V_28 -> V_66 = NULL ;
}
static void F_38 ( struct V_12 * V_77 )
{
struct V_1 * V_17 = F_1 ( & V_77 -> V_5 ) ;
struct V_21 * V_22 = V_77 -> V_5 . V_23 -> V_22 ;
F_15 ( V_22 , L_14 , V_78 ) ;
F_39 ( V_17 -> V_23 , V_79 ,
F_3 ( V_22 -> V_62 ) / 100 ) ;
F_40 ( V_17 -> V_23 ) ;
}
static void F_41 ( struct V_12 * V_77 )
{
struct V_1 * V_17 = F_1 ( & V_77 -> V_5 ) ;
F_15 ( V_77 -> V_5 . V_23 -> V_22 , L_14 , V_78 ) ;
F_39 ( V_17 -> V_23 , V_79 , 0 ) ;
F_42 ( V_17 -> V_23 ) ;
}
static inline bool F_43 ( struct V_80 * V_81 )
{
return true ;
}
static int
F_44 ( struct V_80 * V_81 , struct V_2 * V_3 )
{
struct V_21 * V_22 = V_81 -> V_22 ;
struct V_1 * V_17 = F_1 ( V_3 ) ;
struct V_82 * V_83 ;
int V_26 ;
struct V_30 * V_31 ;
struct V_84 * V_85 ;
if ( ! F_43 ( V_81 ) )
return - V_76 ;
V_85 = F_2 ( V_3 -> V_86 , struct V_84 , V_87 ) ;
if ( V_22 -> V_88 ) {
V_3 -> V_89 = F_45 ( sizeof( * V_3 -> V_89 ) ,
V_90 ) ;
if ( ! V_3 -> V_89 )
return - V_91 ;
V_3 -> V_92 = 1 ;
V_3 -> V_89 [ 0 ] . V_93 = & V_85 -> V_94 ;
}
if ( ! V_85 -> V_95 ) {
F_46 ( V_85 -> V_71 , V_22 -> V_62 ) ;
V_26 = F_47 ( V_85 -> V_71 ) ;
if ( V_26 )
goto V_68;
V_85 -> V_95 = true ;
}
V_83 = F_48 ( V_22 , V_96 ,
F_49 ( V_97 ) ) ;
if ( F_33 ( V_83 ) ) {
V_26 = F_34 ( V_83 ) ;
goto V_68;
}
V_98 . V_99 = V_83 [ 0 ] . V_100 ;
V_101 . V_99 = V_83 [ 1 ] . V_100 ;
V_102 . V_103 = V_83 [ 2 ] . V_100 ;
V_26 = F_50 ( V_81 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_55 = V_26 ;
V_102 . V_104 = V_26 ;
V_98 . V_105 = V_26 ;
V_106 . V_107 = V_26 ;
if ( V_22 -> V_88 )
V_3 -> V_89 [ 0 ] . V_108 =
V_102 . V_104 ;
V_26 = F_50 ( V_81 , V_3 ) ;
if ( V_26 < 0 )
goto V_68;
V_17 -> V_69 = V_26 ;
V_101 . V_105 = V_26 ;
V_106 . V_109 = V_26 ;
V_26 = - V_110 ;
V_31 = F_51 ( V_22 -> V_62 , & V_111 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_72 = V_31 ;
V_31 -> V_66 = V_22 ;
V_31 = F_51 ( V_22 -> V_62 , & V_112 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_4 . V_73 = V_31 ;
V_31 -> V_66 = V_22 ;
V_31 = F_51 ( V_22 -> V_62 , & V_113 ) ;
if ( ! V_31 )
goto V_68;
V_17 -> V_28 = V_31 ;
V_31 -> V_66 = V_22 ;
V_26 = - V_91 ;
V_17 -> V_20 = F_52 ( V_31 , V_90 ) ;
if ( ! V_17 -> V_20 )
goto V_68;
V_17 -> V_20 -> V_25 = F_53 ( V_114 , V_90 ) ;
if ( ! V_17 -> V_20 -> V_25 )
goto V_68;
V_17 -> V_20 -> V_37 = V_114 ;
V_17 -> V_20 -> V_32 = V_17 ;
V_17 -> V_20 -> V_57 = F_16 ;
V_115 . V_116 = V_111 . V_116 ;
V_117 . V_116 = V_112 . V_116 ;
V_118 . V_116 = V_113 . V_116 ;
V_119 . V_116 = V_111 . V_116 ;
V_120 . V_116 = V_112 . V_116 ;
V_121 . V_116 = V_113 . V_116 ;
V_26 = F_54 ( V_3 , V_122 , V_123 ,
V_124 ) ;
if ( V_26 )
goto V_68;
V_17 -> V_4 . V_125 = F_38 ;
V_17 -> V_4 . V_126 = F_41 ;
F_39 ( V_17 -> V_23 , V_79 , 0 ) ;
F_55 ( V_17 -> V_23 , V_17 -> V_127 ) ;
if ( V_17 -> V_128 && V_17 -> V_129 &&
F_56 ( V_17 -> V_23 , V_17 -> V_129 ,
V_17 -> V_128 ) )
goto V_68;
F_15 ( V_22 , L_15 ,
F_4 ( V_81 -> V_22 -> V_62 ) ? L_16 :
F_5 ( V_81 -> V_22 -> V_62 ) ? L_17 : L_18 ,
V_17 -> V_4 . V_72 -> V_35 , V_17 -> V_4 . V_73 -> V_35 ,
V_17 -> V_28 -> V_35 ) ;
return 0 ;
V_68:
F_57 ( V_3 -> V_89 ) ;
V_3 -> V_92 = 0 ;
F_58 ( V_3 ) ;
if ( V_17 -> V_20 ) {
F_57 ( V_17 -> V_20 -> V_25 ) ;
F_59 ( V_17 -> V_28 , V_17 -> V_20 ) ;
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
void F_60 ( struct V_130 * V_3 , struct V_70 * V_71 )
{
struct V_84 * V_131 ;
V_131 = F_2 ( V_3 , struct V_84 , V_87 ) ;
if ( V_131 -> V_95 )
F_61 ( F_62 ( V_131 -> V_71 ) ) ;
else
F_63 ( V_131 -> V_71 ) ;
V_131 -> V_132 = V_131 -> V_95 = true ;
V_131 -> V_71 = V_71 ;
}
static inline struct V_84 * F_64 ( struct V_133 * V_134 )
{
return F_2 ( F_65 ( V_134 ) , struct V_84 ,
V_87 . V_135 ) ;
}
static void F_66 ( struct V_130 * V_3 )
{
struct V_84 * V_131 ;
V_131 = F_2 ( V_3 , struct V_84 , V_87 ) ;
if ( ! V_131 -> V_132 ) {
if ( V_131 -> V_95 )
F_61 ( F_62 ( V_131 -> V_71 ) ) ;
else
F_63 ( V_131 -> V_71 ) ;
}
F_57 ( V_131 -> V_94 . V_135 . V_136 ) ;
F_57 ( V_131 ) ;
}
static struct V_130 * F_67 ( void )
{
struct V_84 * V_131 ;
struct V_137 * V_138 [ 1 ] ;
char * V_139 [ 1 ] ;
V_131 = F_45 ( sizeof( * V_131 ) , V_90 ) ;
if ( ! V_131 )
return F_68 ( - V_91 ) ;
V_131 -> V_94 . V_140 = V_131 -> V_141 ;
F_69 ( & V_131 -> V_142 ) ;
V_131 -> V_87 . V_143 = F_66 ;
V_131 -> V_71 = F_70 () ;
if ( F_33 ( V_131 -> V_71 ) ) {
struct V_70 * V_71 = V_131 -> V_71 ;
F_57 ( V_131 ) ;
return F_71 ( V_71 ) ;
}
F_72 ( & V_131 -> V_94 . V_144 ) ;
V_138 [ 0 ] = & V_131 -> V_94 ;
V_139 [ 0 ] = L_20 ;
F_73 ( & V_131 -> V_87 . V_135 , 1 , V_138 ,
V_139 , V_145 ) ;
F_74 ( & V_131 -> V_87 . V_135 , L_21 ,
& V_146 ) ;
return & V_131 -> V_87 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_17 ;
struct V_84 * V_131 ;
V_17 = F_1 ( V_3 ) ;
F_76 ( V_17 -> V_23 ) ;
V_131 = F_2 ( V_3 -> V_86 , struct V_84 , V_87 ) ;
F_57 ( V_17 ) ;
F_77 ( & V_131 -> V_142 ) ;
V_131 -> V_147 -- ;
F_78 ( & V_131 -> V_142 ) ;
}
static void F_79 ( struct V_80 * V_81 , struct V_2 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
F_57 ( V_3 -> V_89 ) ;
V_3 -> V_92 = 0 ;
F_58 ( V_3 ) ;
F_57 ( V_17 -> V_20 -> V_25 ) ;
F_59 ( V_17 -> V_28 , V_17 -> V_20 ) ;
}
static struct V_2 * F_80 ( struct V_130 * V_86 )
{
struct V_1 * V_17 ;
struct V_84 * V_131 ;
int V_26 ;
V_17 = F_45 ( sizeof( * V_17 ) , V_90 ) ;
if ( ! V_17 )
return F_68 ( - V_91 ) ;
V_131 = F_2 ( V_86 , struct V_84 , V_87 ) ;
F_77 ( & V_131 -> V_142 ) ;
V_131 -> V_147 ++ ;
F_81 ( V_131 -> V_71 , V_17 -> V_127 ) ;
V_17 -> V_129 = V_131 -> V_148 ;
V_17 -> V_128 = V_131 -> V_128 ;
V_17 -> V_4 . V_149 = F_62 ( V_131 -> V_71 ) ;
F_78 ( & V_131 -> V_142 ) ;
V_17 -> V_4 . V_75 = 0 ;
V_17 -> V_4 . V_150 = sizeof( struct V_15 ) ;
V_17 -> V_4 . V_151 = F_6 ;
V_17 -> V_4 . V_152 = V_153 ;
V_17 -> V_4 . V_5 . V_35 = L_20 ;
V_17 -> V_4 . V_5 . V_154 = F_44 ;
V_17 -> V_4 . V_5 . V_155 = F_79 ;
V_17 -> V_4 . V_5 . V_156 = F_27 ;
V_17 -> V_4 . V_5 . V_157 = F_22 ;
V_17 -> V_4 . V_5 . V_158 = F_36 ;
V_17 -> V_4 . V_5 . V_159 = F_75 ;
V_26 = F_82 ( F_10 , V_17 ) ;
if ( V_26 < 0 ) {
F_57 ( V_17 ) ;
return F_68 ( V_26 ) ;
}
V_17 -> V_23 = V_26 ;
return & V_17 -> V_4 . V_5 ;
}
static int T_4 F_83 ( void )
{
int V_160 ;
V_160 = F_84 () ;
if ( V_160 )
return V_160 ;
return F_85 ( & V_161 ) ;
}
static void T_5 F_86 ( void )
{
F_87 ( & V_161 ) ;
F_88 () ;
}
