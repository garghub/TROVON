static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = V_4 -> V_10 ++ ;
if ( F_4 ( V_9 >= F_5 ( V_4 -> V_11 ) ) )
return - V_12 ;
V_4 -> V_11 [ V_9 ] = V_8 ;
return V_9 ;
}
void T_1 * F_6 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_16 )
{
struct V_17 * V_18 ;
unsigned long V_19 ;
void T_1 * V_20 ;
if ( V_15 )
V_18 = F_7 ( V_14 , V_21 , V_15 ) ;
else
V_18 = F_8 ( V_14 , V_21 , 0 ) ;
if ( ! V_18 ) {
F_9 ( & V_14 -> V_2 , L_1 , V_15 ) ;
return F_10 ( - V_12 ) ;
}
V_19 = F_11 ( V_18 ) ;
V_20 = F_12 ( & V_14 -> V_2 , V_18 -> V_22 , V_19 ) ;
if ( ! V_20 ) {
F_9 ( & V_14 -> V_2 , L_2 , V_15 ) ;
return F_10 ( - V_23 ) ;
}
if ( V_24 )
F_13 ( V_25 L_3 , V_16 , ( V_26 ) V_20 , V_19 ) ;
return V_20 ;
}
void F_14 ( V_26 V_27 , void T_1 * V_28 )
{
if ( V_24 )
F_13 ( V_25 L_4 , ( V_26 ) V_28 , V_27 ) ;
F_15 ( V_27 , V_28 ) ;
}
V_26 F_16 ( const void T_1 * V_28 )
{
V_26 V_29 = F_17 ( V_28 ) ;
if ( V_24 )
F_13 ( V_30 L_5 , ( V_26 ) V_28 , V_29 ) ;
return V_29 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_33 * V_34 = V_4 -> V_34 ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 -> V_2 ) ;
F_25 ( V_4 -> V_35 ) ;
F_26 ( V_4 -> V_35 ) ;
if ( V_32 ) {
F_27 ( V_2 -> V_2 ) ;
V_32 -> V_36 -> V_37 ( V_32 ) ;
}
if ( V_34 ) {
F_28 ( & V_2 -> V_38 ) ;
V_34 -> V_36 -> V_39 ( V_34 ) ;
V_34 -> V_36 -> V_37 ( V_34 ) ;
F_29 ( & V_2 -> V_38 ) ;
}
if ( V_4 -> V_40 . V_41 ) {
F_30 ( V_42 ) ;
F_31 ( V_43 , & V_42 ) ;
F_32 ( & V_4 -> V_40 . V_44 ) ;
F_33 ( V_2 -> V_2 , V_4 -> V_40 . V_19 , NULL ,
V_4 -> V_40 . V_41 , & V_42 ) ;
}
F_34 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_5 = NULL ;
F_35 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 )
{
#ifdef F_37
static const struct V_45 V_46 [] = { {
. V_47 = L_6 ,
. V_27 = ( void * ) 5 ,
} , {
} } ;
struct V_48 * V_2 = & V_14 -> V_2 ;
const struct V_45 * V_49 ;
V_49 = F_38 ( V_46 , V_2 -> V_50 ) ;
if ( V_49 )
return ( int ) V_49 -> V_27 ;
#endif
return 4 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_51 )
{
struct V_13 * V_14 = V_2 -> V_52 ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
int V_53 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 ) {
F_9 ( V_2 -> V_2 , L_7 ) ;
return - V_23 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_35 = F_41 ( L_8 , 0 ) ;
F_42 ( & V_4 -> V_55 ) ;
F_42 ( & V_4 -> V_56 ) ;
F_43 ( & V_4 -> V_57 ) ;
F_43 ( & V_4 -> V_58 ) ;
F_44 ( V_2 ) ;
if ( ! F_45 ( & V_59 ) ) {
F_30 ( V_42 ) ;
unsigned long V_19 ;
void * V_60 ;
F_46 ( L_9 , V_40 ) ;
V_19 = F_47 ( V_40 , NULL ) ;
V_4 -> V_40 . V_19 = V_19 ;
F_48 ( & V_4 -> V_40 . V_44 , 0 , ( V_19 >> V_61 ) - 1 ) ;
F_31 ( V_43 , & V_42 ) ;
F_31 ( V_62 , & V_42 ) ;
V_60 = F_49 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_40 . V_41 , V_54 , & V_42 ) ;
if ( ! V_60 ) {
F_9 ( V_2 -> V_2 , L_10 ) ;
V_4 -> V_40 . V_41 = 0 ;
V_53 = - V_23 ;
goto V_63;
}
F_50 ( V_2 -> V_2 , L_11 ,
( V_64 ) V_4 -> V_40 . V_41 ,
( V_64 ) ( V_4 -> V_40 . V_41 + V_19 ) ) ;
}
F_51 ( V_14 , V_2 ) ;
V_53 = F_52 ( V_2 -> V_2 , V_2 ) ;
if ( V_53 )
return V_53 ;
switch ( F_36 ( V_14 ) ) {
case 4 :
V_32 = F_53 ( V_2 ) ;
break;
case 5 :
V_32 = F_54 ( V_2 ) ;
break;
default:
V_32 = F_10 ( - V_65 ) ;
break;
}
if ( F_55 ( V_32 ) ) {
F_9 ( V_2 -> V_2 , L_12 ) ;
V_53 = F_56 ( V_32 ) ;
goto V_63;
}
V_4 -> V_32 = V_32 ;
if ( V_32 ) {
F_57 ( V_2 -> V_2 ) ;
V_53 = V_32 -> V_36 -> V_66 ( V_32 ) ;
if ( V_53 ) {
F_9 ( V_2 -> V_2 , L_13 , V_53 ) ;
goto V_63;
}
}
V_2 -> V_67 . V_68 = 0 ;
V_2 -> V_67 . V_69 = 0 ;
V_2 -> V_67 . V_70 = 2048 ;
V_2 -> V_67 . V_71 = 2048 ;
V_2 -> V_67 . V_36 = & V_72 ;
V_53 = F_58 ( V_2 , V_4 -> V_73 ) ;
if ( V_53 < 0 ) {
F_9 ( V_2 -> V_2 , L_14 ) ;
goto V_63;
}
F_22 ( V_2 -> V_2 ) ;
V_53 = F_59 ( V_2 , F_60 ( V_2 -> V_52 , 0 ) ) ;
F_24 ( V_2 -> V_2 ) ;
if ( V_53 < 0 ) {
F_9 ( V_2 -> V_2 , L_15 ) ;
goto V_63;
}
F_61 ( V_2 ) ;
#ifdef F_62
V_4 -> V_6 = F_63 ( V_2 ) ;
#endif
V_53 = F_64 ( V_2 ) ;
if ( V_53 )
goto V_63;
F_65 ( V_2 ) ;
return 0 ;
V_63:
F_18 ( V_2 ) ;
return V_53 ;
}
static void F_66 ( struct V_1 * V_2 )
{
static F_67 ( V_74 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_28 ( & V_74 ) ;
if ( ! V_4 -> V_34 )
V_4 -> V_34 = F_68 ( V_2 ) ;
F_29 ( & V_74 ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_77 * V_78 ;
F_66 ( V_2 ) ;
V_78 = F_40 ( sizeof( * V_78 ) , V_54 ) ;
if ( ! V_78 )
return - V_23 ;
V_76 -> V_79 = V_78 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_77 * V_78 = V_76 -> V_79 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( V_32 )
V_32 -> V_36 -> V_80 ( V_32 , V_76 ) ;
F_28 ( & V_2 -> V_38 ) ;
if ( V_78 == V_4 -> V_81 )
V_4 -> V_81 = NULL ;
F_29 ( & V_2 -> V_38 ) ;
F_35 ( V_78 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_72 ( V_4 -> V_6 ) ;
}
static T_2 F_73 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
return V_32 -> V_36 -> V_82 ( V_32 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
V_32 -> V_36 -> V_84 ( V_32 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
return V_32 -> V_36 -> V_85 ( V_32 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
F_74 ( ! V_32 ) ;
V_32 -> V_36 -> V_86 ( V_32 ) ;
}
static int F_78 ( struct V_1 * V_2 , int V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( ! V_32 )
return - V_88 ;
F_46 ( L_16 , V_2 , V_87 ) ;
return V_32 -> V_36 -> V_89 ( V_32 , V_4 -> V_90 [ V_87 ] ) ;
}
static void F_79 ( struct V_1 * V_2 , int V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_31 * V_32 = V_4 -> V_32 ;
if ( ! V_32 )
return;
F_46 ( L_16 , V_2 , V_87 ) ;
V_32 -> V_36 -> V_91 ( V_32 , V_4 -> V_90 [ V_87 ] ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = V_4 -> V_34 ;
if ( V_34 ) {
F_81 ( V_93 , L_17 , V_34 -> V_15 ) ;
V_34 -> V_36 -> V_94 ( V_34 , V_93 ) ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_33 * V_34 = V_4 -> V_34 ;
if ( V_34 ) {
F_81 ( V_93 , L_18 , V_34 -> V_15 ) ;
F_83 ( & V_34 -> V_95 , V_93 ) ;
}
F_81 ( V_93 , L_19 ) ;
F_83 ( & V_4 -> V_57 , V_93 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
return F_85 ( V_93 , & V_2 -> V_96 -> V_97 ) ;
}
static int F_86 ( struct V_1 * V_2 , struct V_92 * V_93 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_98 * V_99 , * V_100 = NULL ;
if ( V_4 -> V_6 ) {
F_81 ( V_93 , L_20 ) ;
V_100 = V_4 -> V_6 -> V_99 ;
F_87 ( V_100 , V_93 ) ;
}
F_28 ( & V_2 -> V_67 . V_101 ) ;
F_88 (fb, &dev->mode_config.fb_list, head) {
if ( V_99 == V_100 )
continue;
F_81 ( V_93 , L_21 ) ;
F_87 ( V_99 , V_93 ) ;
}
F_29 ( & V_2 -> V_67 . V_101 ) ;
return 0 ;
}
static int F_89 ( struct V_92 * V_93 , void * V_83 )
{
struct V_102 * V_103 = (struct V_102 * ) V_93 -> V_104 ;
struct V_1 * V_2 = V_103 -> V_105 -> V_2 ;
int (* V_94)( struct V_1 * V_2 , struct V_92 * V_93 ) =
V_103 -> V_106 -> V_27 ;
int V_53 ;
V_53 = F_90 ( & V_2 -> V_38 ) ;
if ( V_53 )
return V_53 ;
V_53 = V_94 ( V_2 , V_93 ) ;
F_29 ( & V_2 -> V_38 ) ;
return V_53 ;
}
static int F_91 ( struct V_107 * V_105 )
{
int V_53 ;
if ( ! V_105 )
return 0 ;
V_53 = F_92 ( V_105 ) ;
if ( V_53 ) {
F_9 ( V_105 -> V_2 -> V_2 , L_22 ) ;
return V_53 ;
}
V_53 = F_93 ( V_105 ) ;
if ( V_53 ) {
F_9 ( V_105 -> V_2 -> V_2 , L_23 ) ;
return V_53 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_53 ;
V_53 = F_91 ( V_2 -> V_108 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_91 ( V_2 -> V_109 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_91 ( V_2 -> V_110 ) ;
return V_53 ;
}
static int F_94 ( struct V_107 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
int V_53 ;
V_53 = F_95 ( V_111 ,
F_5 ( V_111 ) ,
V_105 -> V_112 , V_105 ) ;
if ( V_53 ) {
F_9 ( V_2 -> V_2 , L_24 ) ;
return V_53 ;
}
return 0 ;
}
static void F_96 ( struct V_107 * V_105 )
{
F_97 ( V_111 ,
F_5 ( V_111 ) , V_105 ) ;
if ( ! V_105 -> V_2 -> V_5 )
return;
F_98 ( V_105 ) ;
F_99 ( V_105 ) ;
}
int F_100 ( struct V_1 * V_2 , V_64 V_113 ,
struct V_114 * V_115 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_53 ;
if ( ! V_4 -> V_34 )
return 0 ;
if ( V_113 > V_4 -> V_34 -> V_116 ) {
F_101 ( L_25 ,
V_113 , V_4 -> V_34 -> V_116 ) ;
return - V_12 ;
}
if ( ! V_115 ) {
V_53 = F_102 ( V_2 , V_113 ) ? 0 : - V_117 ;
} else {
unsigned long V_118 = F_103 ( V_115 ) ;
unsigned long V_119 = V_120 ;
unsigned long V_121 ;
if ( F_104 ( V_119 , V_118 ) )
V_121 = 0 ;
else
V_121 = V_118 - V_119 ;
V_53 = F_105 ( V_4 -> V_55 ,
F_102 ( V_2 , V_113 ) ,
V_121 ) ;
if ( V_53 == 0 ) {
F_46 ( L_26 ,
V_113 , V_4 -> V_122 ) ;
V_53 = - V_123 ;
} else if ( V_53 != - V_124 ) {
V_53 = 0 ;
}
}
return V_53 ;
}
int F_106 ( struct V_1 * V_2 ,
struct V_125 * V_126 , V_64 V_113 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_53 = 0 ;
F_28 ( & V_2 -> V_38 ) ;
if ( ! F_107 ( & V_126 -> V_127 . V_128 ) ) {
V_53 = - V_12 ;
} else if ( V_113 > V_4 -> V_122 ) {
V_126 -> V_113 = V_113 ;
F_108 ( & V_126 -> V_127 . V_128 , & V_4 -> V_58 ) ;
} else {
F_109 ( V_4 -> V_35 , & V_126 -> V_127 ) ;
}
F_29 ( & V_2 -> V_38 ) ;
return V_53 ;
}
void F_110 ( struct V_1 * V_2 , V_64 V_113 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_28 ( & V_2 -> V_38 ) ;
V_4 -> V_122 = F_111 ( V_113 , V_4 -> V_122 ) ;
while ( ! F_107 ( & V_4 -> V_58 ) ) {
struct V_125 * V_126 ;
V_126 = F_112 ( & V_4 -> V_58 ,
struct V_125 , V_127 . V_128 ) ;
if ( V_126 -> V_113 > V_4 -> V_122 )
break;
F_113 ( & V_126 -> V_127 . V_128 ) ;
F_109 ( V_4 -> V_35 , & V_126 -> V_127 ) ;
}
F_29 ( & V_2 -> V_38 ) ;
F_114 ( & V_4 -> V_55 ) ;
}
void F_115 ( struct V_129 * V_127 )
{
struct V_125 * V_126 = F_116 ( V_127 , struct V_125 , V_127 ) ;
V_126 -> V_130 ( V_126 ) ;
}
static int F_117 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_131 * args = V_27 ;
struct V_33 * V_34 ;
if ( args -> V_132 != V_133 )
return - V_12 ;
V_34 = V_4 -> V_34 ;
if ( ! V_34 )
return - V_88 ;
return V_34 -> V_36 -> V_134 ( V_34 , args -> V_135 , & args -> V_136 ) ;
}
static int F_118 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_137 * args = V_27 ;
if ( args -> V_51 & ~ V_138 ) {
F_101 ( L_27 , args -> V_51 ) ;
return - V_12 ;
}
return F_119 ( V_2 , V_76 , args -> V_19 ,
args -> V_51 , & args -> V_139 ) ;
}
static int F_120 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_140 * args = V_27 ;
struct V_141 * V_142 ;
int V_53 ;
if ( args -> V_143 & ~ V_144 ) {
F_101 ( L_28 , args -> V_143 ) ;
return - V_12 ;
}
V_142 = F_121 ( V_2 , V_76 , args -> V_139 ) ;
if ( ! V_142 )
return - V_145 ;
V_53 = F_122 ( V_142 , args -> V_143 , & F_123 ( args -> V_115 ) ) ;
F_124 ( V_142 ) ;
return V_53 ;
}
static int F_125 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_146 * args = V_27 ;
struct V_141 * V_142 ;
int V_53 ;
V_142 = F_121 ( V_2 , V_76 , args -> V_139 ) ;
if ( ! V_142 )
return - V_145 ;
V_53 = F_126 ( V_142 ) ;
F_124 ( V_142 ) ;
return V_53 ;
}
static int F_127 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_147 * args = V_27 ;
struct V_141 * V_142 ;
int V_53 = 0 ;
if ( args -> V_148 )
return - V_12 ;
V_142 = F_121 ( V_2 , V_76 , args -> V_139 ) ;
if ( ! V_142 )
return - V_145 ;
args -> V_149 = F_128 ( V_142 ) ;
F_124 ( V_142 ) ;
return V_53 ;
}
static int F_129 ( struct V_1 * V_2 , void * V_27 ,
struct V_75 * V_76 )
{
struct V_150 * args = V_27 ;
if ( args -> V_148 ) {
F_101 ( L_29 , args -> V_148 ) ;
return - V_12 ;
}
return F_100 ( V_2 , args -> V_113 ,
& F_123 ( args -> V_115 ) ) ;
}
static int F_130 ( struct V_48 * V_2 )
{
struct V_1 * V_151 = F_131 ( V_2 ) ;
F_132 ( V_151 ) ;
return 0 ;
}
static int F_133 ( struct V_48 * V_2 )
{
struct V_1 * V_151 = F_131 ( V_2 ) ;
F_134 ( V_151 ) ;
return 0 ;
}
static int F_135 ( struct V_48 * V_2 , void * V_27 )
{
return V_2 -> V_50 == V_27 ;
}
static int F_136 ( struct V_48 * V_2 , struct V_152 * * V_153 ,
const char * V_15 )
{
struct V_154 * V_155 = V_2 -> V_50 ;
unsigned V_156 ;
for ( V_156 = 0 ; ; V_156 ++ ) {
struct V_154 * V_103 ;
V_103 = F_137 ( V_155 , V_15 , V_156 ) ;
if ( ! V_103 )
break;
F_138 ( V_2 , V_153 , F_135 , V_103 ) ;
}
return 0 ;
}
static int F_139 ( struct V_48 * V_2 , void * V_27 )
{
return V_2 == V_27 ;
}
static int F_140 ( struct V_48 * V_2 )
{
return F_141 ( & V_157 , F_142 ( V_2 ) ) ;
}
static void F_143 ( struct V_48 * V_2 )
{
F_144 ( F_145 ( F_142 ( V_2 ) ) ) ;
}
static int F_146 ( struct V_13 * V_14 )
{
struct V_152 * V_49 = NULL ;
#ifdef F_37
F_136 ( & V_14 -> V_2 , & V_49 , L_30 ) ;
F_136 ( & V_14 -> V_2 , & V_49 , L_31 ) ;
#else
static const char * V_158 [] = {
L_32 , L_33 ,
} ;
int V_156 ;
F_46 ( L_34 ) ;
for ( V_156 = 0 ; V_156 < F_5 ( V_158 ) ; V_156 ++ ) {
struct V_48 * V_2 ;
V_2 = F_147 ( & V_59 ,
NULL , V_158 [ V_156 ] ) ;
if ( ! V_2 ) {
F_50 ( & V_14 -> V_2 , L_35 , V_158 [ V_156 ] ) ;
return - V_159 ;
}
F_138 ( & V_14 -> V_2 , & V_49 , F_139 , V_2 ) ;
}
#endif
V_14 -> V_2 . V_160 = F_148 ( 32 ) ;
return F_149 ( & V_14 -> V_2 , & V_161 , V_49 ) ;
}
static int F_150 ( struct V_13 * V_14 )
{
F_151 ( & V_14 -> V_2 , & V_161 ) ;
return 0 ;
}
static int T_3 F_152 ( void )
{
F_46 ( L_36 ) ;
F_153 () ;
F_154 () ;
return F_155 ( & V_162 ) ;
}
static void T_4 F_156 ( void )
{
F_46 ( L_37 ) ;
F_157 ( & V_162 ) ;
F_158 () ;
F_159 () ;
}
