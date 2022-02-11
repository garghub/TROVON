static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_3 ( V_4 -> V_6 ) ;
#endif
}
int F_4 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = V_4 -> V_10 ++ ;
if ( F_5 ( V_9 >= F_6 ( V_4 -> V_11 ) ) )
return - V_12 ;
V_4 -> V_11 [ V_9 ] = V_8 ;
return V_9 ;
}
void T_1 * F_7 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_16 )
{
struct V_17 * V_18 ;
unsigned long V_19 ;
void T_1 * V_20 ;
if ( V_15 )
V_18 = F_8 ( V_14 , V_21 , V_15 ) ;
else
V_18 = F_9 ( V_14 , V_21 , 0 ) ;
if ( ! V_18 ) {
F_10 ( & V_14 -> V_2 , L_1 , V_15 ) ;
return F_11 ( - V_12 ) ;
}
V_19 = F_12 ( V_18 ) ;
V_20 = F_13 ( & V_14 -> V_2 , V_18 -> V_22 , V_19 ) ;
if ( ! V_20 ) {
F_10 ( & V_14 -> V_2 , L_2 , V_15 ) ;
return F_11 ( - V_23 ) ;
}
if ( V_24 )
F_14 ( V_25 L_3 , V_16 , V_20 , V_19 ) ;
return V_20 ;
}
void F_15 ( T_2 V_26 , void T_1 * V_27 )
{
if ( V_24 )
F_14 ( V_25 L_4 , V_27 , V_26 ) ;
F_16 ( V_26 , V_27 ) ;
}
T_2 F_17 ( const void T_1 * V_27 )
{
T_2 V_28 = F_18 ( V_27 ) ;
if ( V_24 )
F_14 ( V_29 L_5 , V_27 , V_28 ) ;
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_33 ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_4 -> V_34 ) ;
F_27 ( V_4 -> V_34 ) ;
if ( V_31 ) {
F_28 ( V_2 -> V_2 ) ;
V_31 -> V_35 -> V_36 ( V_31 ) ;
}
if ( V_33 ) {
F_29 ( & V_2 -> V_37 ) ;
V_33 -> V_35 -> V_38 ( V_33 ) ;
F_30 ( & V_2 -> V_37 ) ;
V_33 -> V_35 -> V_36 ( V_33 ) ;
}
if ( V_4 -> V_39 . V_40 ) {
F_31 ( V_41 ) ;
F_32 ( V_42 , & V_41 ) ;
F_33 ( & V_4 -> V_39 . V_43 ) ;
F_34 ( V_2 -> V_2 , V_4 -> V_39 . V_19 , NULL ,
V_4 -> V_39 . V_40 , & V_41 ) ;
}
F_35 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_5 = NULL ;
F_36 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 )
{
#ifdef F_38
static const struct V_44 V_45 [] = { {
. V_46 = L_6 ,
. V_26 = ( void * ) 5 ,
} , {
} } ;
struct V_47 * V_2 = & V_14 -> V_2 ;
const struct V_44 * V_48 ;
V_48 = F_39 ( V_45 , V_2 -> V_49 ) ;
if ( V_48 )
return ( int ) ( unsigned long ) V_48 -> V_26 ;
#endif
return 4 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_19 = 0 ;
int V_50 = 0 ;
#ifdef F_38
struct V_51 * V_52 ;
V_52 = F_41 ( V_2 -> V_2 -> V_49 , L_7 , 0 ) ;
if ( V_52 ) {
struct V_17 V_53 ;
V_50 = F_42 ( V_52 , 0 , & V_53 ) ;
if ( V_50 )
return V_50 ;
V_19 = V_53 . V_54 - V_53 . V_22 ;
F_43 ( L_8 , V_19 , & V_53 . V_22 ) ;
} else
#endif
if ( ! F_44 ( & V_55 ) ) {
F_43 ( L_9 , V_39 ) ;
V_19 = F_45 ( V_39 , NULL ) ;
}
if ( V_19 ) {
F_31 ( V_41 ) ;
void * V_56 ;
V_4 -> V_39 . V_19 = V_19 ;
F_46 ( & V_4 -> V_39 . V_43 , 0 , ( V_19 >> V_57 ) - 1 ) ;
F_32 ( V_42 , & V_41 ) ;
F_32 ( V_58 , & V_41 ) ;
V_56 = F_47 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_39 . V_40 , V_59 , & V_41 ) ;
if ( ! V_56 ) {
F_10 ( V_2 -> V_2 , L_10 ) ;
V_4 -> V_39 . V_40 = 0 ;
return - V_23 ;
}
F_48 ( V_2 -> V_2 , L_11 ,
( V_60 ) V_4 -> V_39 . V_40 ,
( V_60 ) ( V_4 -> V_39 . V_40 + V_19 ) ) ;
}
return V_50 ;
}
static int F_49 ( struct V_1 * V_2 , unsigned long V_61 )
{
struct V_13 * V_14 = V_2 -> V_62 ;
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_50 ;
V_4 = F_50 ( sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 ) {
F_10 ( V_2 -> V_2 , L_12 ) ;
return - V_23 ;
}
V_2 -> V_5 = V_4 ;
V_4 -> V_34 = F_51 ( L_13 , 0 ) ;
F_52 ( & V_4 -> V_63 ) ;
F_52 ( & V_4 -> V_64 ) ;
F_53 ( & V_4 -> V_65 ) ;
F_53 ( & V_4 -> V_66 ) ;
F_54 ( V_2 ) ;
F_55 ( V_14 , V_2 ) ;
V_50 = F_56 ( V_2 -> V_2 , V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_40 ( V_2 ) ;
if ( V_50 )
goto V_67;
switch ( F_37 ( V_14 ) ) {
case 4 :
V_31 = F_57 ( V_2 ) ;
break;
case 5 :
V_31 = F_58 ( V_2 ) ;
break;
default:
V_31 = F_11 ( - V_68 ) ;
break;
}
if ( F_59 ( V_31 ) ) {
F_10 ( V_2 -> V_2 , L_14 ) ;
V_50 = F_60 ( V_31 ) ;
goto V_67;
}
V_4 -> V_31 = V_31 ;
if ( V_31 ) {
F_61 ( V_2 -> V_2 ) ;
V_50 = V_31 -> V_35 -> V_69 ( V_31 ) ;
if ( V_50 ) {
F_10 ( V_2 -> V_2 , L_15 , V_50 ) ;
goto V_67;
}
}
V_2 -> V_70 . V_71 = 0 ;
V_2 -> V_70 . V_72 = 0 ;
V_2 -> V_70 . V_73 = 2048 ;
V_2 -> V_70 . V_74 = 2048 ;
V_2 -> V_70 . V_35 = & V_75 ;
V_50 = F_62 ( V_2 , V_4 -> V_76 ) ;
if ( V_50 < 0 ) {
F_10 ( V_2 -> V_2 , L_16 ) ;
goto V_67;
}
F_23 ( V_2 -> V_2 ) ;
V_50 = F_63 ( V_2 , F_64 ( V_2 -> V_62 , 0 ) ) ;
F_25 ( V_2 -> V_2 ) ;
if ( V_50 < 0 ) {
F_10 ( V_2 -> V_2 , L_17 ) ;
goto V_67;
}
F_65 ( V_2 ) ;
#ifdef F_2
if ( V_6 )
V_4 -> V_6 = F_66 ( V_2 ) ;
#endif
V_50 = F_67 ( V_2 ) ;
if ( V_50 )
goto V_67;
F_68 ( V_2 ) ;
return 0 ;
V_67:
F_19 ( V_2 ) ;
return V_50 ;
}
static void F_69 ( struct V_1 * V_2 )
{
static F_70 ( V_77 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_29 ( & V_77 ) ;
if ( ! V_4 -> V_33 )
V_4 -> V_33 = F_71 ( V_2 ) ;
F_30 ( & V_77 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_80 * V_81 ;
F_69 ( V_2 ) ;
V_81 = F_50 ( sizeof( * V_81 ) , V_59 ) ;
if ( ! V_81 )
return - V_23 ;
V_79 -> V_82 = V_81 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_80 * V_81 = V_79 -> V_82 ;
struct V_30 * V_31 = V_4 -> V_31 ;
if ( V_31 )
V_31 -> V_35 -> V_83 ( V_31 , V_79 ) ;
F_29 ( & V_2 -> V_37 ) ;
if ( V_81 == V_4 -> V_84 )
V_4 -> V_84 = NULL ;
F_30 ( & V_2 -> V_37 ) ;
F_36 ( V_81 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_75 ( V_4 -> V_6 ) ;
#endif
}
static T_3 F_76 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
F_77 ( ! V_31 ) ;
return V_31 -> V_35 -> V_85 ( V_31 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
F_77 ( ! V_31 ) ;
V_31 -> V_35 -> V_87 ( V_31 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
F_77 ( ! V_31 ) ;
return V_31 -> V_35 -> V_88 ( V_31 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
F_77 ( ! V_31 ) ;
V_31 -> V_35 -> V_89 ( V_31 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_90 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
if ( ! V_31 )
return - V_91 ;
F_82 ( L_18 , V_2 , V_90 ) ;
return V_31 -> V_35 -> V_92 ( V_31 , V_4 -> V_93 [ V_90 ] ) ;
}
static void F_83 ( struct V_1 * V_2 , int V_90 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = V_4 -> V_31 ;
if ( ! V_31 )
return;
F_82 ( L_18 , V_2 , V_90 ) ;
V_31 -> V_35 -> V_94 ( V_31 , V_4 -> V_93 [ V_90 ] ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( V_33 ) {
F_85 ( V_96 , L_19 , V_33 -> V_15 ) ;
V_33 -> V_35 -> V_97 ( V_33 , V_96 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( V_33 ) {
F_85 ( V_96 , L_20 , V_33 -> V_15 ) ;
F_87 ( & V_33 -> V_98 , V_96 ) ;
}
F_85 ( V_96 , L_21 ) ;
F_87 ( & V_4 -> V_65 , V_96 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
return F_89 ( V_96 , & V_2 -> V_99 -> V_100 ) ;
}
static int F_90 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_101 * V_102 , * V_103 = NULL ;
if ( V_4 -> V_6 ) {
F_85 ( V_96 , L_22 ) ;
V_103 = V_4 -> V_6 -> V_102 ;
F_91 ( V_103 , V_96 ) ;
}
F_29 ( & V_2 -> V_70 . V_104 ) ;
F_92 (fb, &dev->mode_config.fb_list, head) {
if ( V_102 == V_103 )
continue;
F_85 ( V_96 , L_23 ) ;
F_91 ( V_102 , V_96 ) ;
}
F_30 ( & V_2 -> V_70 . V_104 ) ;
return 0 ;
}
static int F_93 ( struct V_95 * V_96 , void * V_86 )
{
struct V_105 * V_52 = (struct V_105 * ) V_96 -> V_106 ;
struct V_1 * V_2 = V_52 -> V_107 -> V_2 ;
int (* V_97)( struct V_1 * V_2 , struct V_95 * V_96 ) =
V_52 -> V_108 -> V_26 ;
int V_50 ;
V_50 = F_94 ( & V_2 -> V_37 ) ;
if ( V_50 )
return V_50 ;
V_50 = V_97 ( V_2 , V_96 ) ;
F_30 ( & V_2 -> V_37 ) ;
return V_50 ;
}
static int F_95 ( struct V_109 * V_107 )
{
int V_50 ;
if ( ! V_107 )
return 0 ;
V_50 = F_96 ( V_107 ) ;
if ( V_50 ) {
F_10 ( V_107 -> V_2 -> V_2 , L_24 ) ;
return V_50 ;
}
V_50 = F_97 ( V_107 ) ;
if ( V_50 ) {
F_10 ( V_107 -> V_2 -> V_2 , L_25 ) ;
return V_50 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_95 ( V_2 -> V_110 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_95 ( V_2 -> V_111 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_95 ( V_2 -> V_112 ) ;
return V_50 ;
}
static int F_98 ( struct V_109 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
int V_50 ;
V_50 = F_99 ( V_113 ,
F_6 ( V_113 ) ,
V_107 -> V_114 , V_107 ) ;
if ( V_50 ) {
F_10 ( V_2 -> V_2 , L_26 ) ;
return V_50 ;
}
return 0 ;
}
static void F_100 ( struct V_109 * V_107 )
{
F_101 ( V_113 ,
F_6 ( V_113 ) , V_107 ) ;
if ( ! V_107 -> V_2 -> V_5 )
return;
F_102 ( V_107 ) ;
F_103 ( V_107 ) ;
}
int F_104 ( struct V_1 * V_2 , V_60 V_115 ,
T_4 * V_116 , bool V_117 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 ;
if ( ! V_4 -> V_33 )
return 0 ;
if ( V_115 > V_4 -> V_33 -> V_118 ) {
F_105 ( L_27 ,
V_115 , V_4 -> V_33 -> V_118 ) ;
return - V_12 ;
}
if ( ! V_116 ) {
V_50 = F_106 ( V_2 , V_115 ) ? 0 : - V_119 ;
} else {
T_4 V_120 = F_107 () ;
unsigned long V_121 ;
if ( F_108 ( * V_116 , V_120 ) < 0 ) {
V_121 = 0 ;
} else {
T_4 V_122 = F_109 ( * V_116 , V_120 ) ;
struct V_123 V_124 = F_110 ( V_122 ) ;
V_121 = F_111 ( & V_124 ) ;
}
if ( V_117 )
V_50 = F_112 ( V_4 -> V_63 ,
F_106 ( V_2 , V_115 ) ,
V_121 ) ;
else
V_50 = F_113 ( V_4 -> V_63 ,
F_106 ( V_2 , V_115 ) ,
V_121 ) ;
if ( V_50 == 0 ) {
F_82 ( L_28 ,
V_115 , V_4 -> V_125 ) ;
V_50 = - V_126 ;
} else if ( V_50 != - V_127 ) {
V_50 = 0 ;
}
}
return V_50 ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_128 * V_129 , V_60 V_115 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_50 = 0 ;
F_29 ( & V_2 -> V_37 ) ;
if ( ! F_115 ( & V_129 -> V_130 . V_131 ) ) {
V_50 = - V_12 ;
} else if ( V_115 > V_4 -> V_125 ) {
V_129 -> V_115 = V_115 ;
F_116 ( & V_129 -> V_130 . V_131 , & V_4 -> V_66 ) ;
} else {
F_117 ( V_4 -> V_34 , & V_129 -> V_130 ) ;
}
F_30 ( & V_2 -> V_37 ) ;
return V_50 ;
}
void F_118 ( struct V_1 * V_2 , V_60 V_115 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_29 ( & V_2 -> V_37 ) ;
V_4 -> V_125 = F_119 ( V_115 , V_4 -> V_125 ) ;
while ( ! F_115 ( & V_4 -> V_66 ) ) {
struct V_128 * V_129 ;
V_129 = F_120 ( & V_4 -> V_66 ,
struct V_128 , V_130 . V_131 ) ;
if ( V_129 -> V_115 > V_4 -> V_125 )
break;
F_121 ( & V_129 -> V_130 . V_131 ) ;
F_117 ( V_4 -> V_34 , & V_129 -> V_130 ) ;
}
F_30 ( & V_2 -> V_37 ) ;
F_122 ( & V_4 -> V_63 ) ;
}
void F_123 ( struct V_132 * V_130 )
{
struct V_128 * V_129 = F_124 ( V_130 , struct V_128 , V_130 ) ;
V_129 -> V_133 ( V_129 ) ;
}
static int F_125 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_134 * args = V_26 ;
struct V_32 * V_33 ;
if ( args -> V_135 != V_136 )
return - V_12 ;
V_33 = V_4 -> V_33 ;
if ( ! V_33 )
return - V_91 ;
return V_33 -> V_35 -> V_137 ( V_33 , args -> V_138 , & args -> V_139 ) ;
}
static int F_126 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_140 * args = V_26 ;
if ( args -> V_61 & ~ V_141 ) {
F_105 ( L_29 , args -> V_61 ) ;
return - V_12 ;
}
return F_127 ( V_2 , V_79 , args -> V_19 ,
args -> V_61 , & args -> V_142 ) ;
}
static inline T_4 F_128 ( struct V_143 V_116 )
{
return F_129 ( V_116 . V_144 , V_116 . V_145 ) ;
}
static int F_130 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_146 * args = V_26 ;
struct V_147 * V_148 ;
T_4 V_116 = F_128 ( args -> V_116 ) ;
int V_50 ;
if ( args -> V_149 & ~ V_150 ) {
F_105 ( L_30 , args -> V_149 ) ;
return - V_12 ;
}
V_148 = F_131 ( V_2 , V_79 , args -> V_142 ) ;
if ( ! V_148 )
return - V_151 ;
V_50 = F_132 ( V_148 , args -> V_149 , & V_116 ) ;
F_133 ( V_148 ) ;
return V_50 ;
}
static int F_134 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_152 * args = V_26 ;
struct V_147 * V_148 ;
int V_50 ;
V_148 = F_131 ( V_2 , V_79 , args -> V_142 ) ;
if ( ! V_148 )
return - V_151 ;
V_50 = F_135 ( V_148 ) ;
F_133 ( V_148 ) ;
return V_50 ;
}
static int F_136 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_153 * args = V_26 ;
struct V_147 * V_148 ;
int V_50 = 0 ;
if ( args -> V_154 )
return - V_12 ;
V_148 = F_131 ( V_2 , V_79 , args -> V_142 ) ;
if ( ! V_148 )
return - V_151 ;
args -> V_155 = F_137 ( V_148 ) ;
F_133 ( V_148 ) ;
return V_50 ;
}
static int F_138 ( struct V_1 * V_2 , void * V_26 ,
struct V_78 * V_79 )
{
struct V_156 * args = V_26 ;
T_4 V_116 = F_128 ( args -> V_116 ) ;
if ( args -> V_154 ) {
F_105 ( L_31 , args -> V_154 ) ;
return - V_12 ;
}
return F_104 ( V_2 , args -> V_115 , & V_116 , true ) ;
}
static int F_139 ( struct V_47 * V_2 )
{
struct V_1 * V_157 = F_140 ( V_2 ) ;
F_141 ( V_157 ) ;
return 0 ;
}
static int F_142 ( struct V_47 * V_2 )
{
struct V_1 * V_157 = F_140 ( V_2 ) ;
F_143 ( V_157 ) ;
return 0 ;
}
static int F_144 ( struct V_47 * V_2 , void * V_26 )
{
return V_2 -> V_49 == V_26 ;
}
static int F_145 ( struct V_47 * V_2 , struct V_158 * * V_159 ,
const char * V_15 )
{
struct V_51 * V_160 = V_2 -> V_49 ;
unsigned V_161 ;
for ( V_161 = 0 ; ; V_161 ++ ) {
struct V_51 * V_52 ;
V_52 = F_41 ( V_160 , V_15 , V_161 ) ;
if ( ! V_52 )
break;
F_146 ( V_2 , V_159 , F_144 , V_52 ) ;
}
return 0 ;
}
static int F_147 ( struct V_47 * V_2 , void * V_26 )
{
return V_2 == V_26 ;
}
static int F_148 ( struct V_47 * V_2 )
{
return F_149 ( & V_162 , F_150 ( V_2 ) ) ;
}
static void F_151 ( struct V_47 * V_2 )
{
F_152 ( F_153 ( F_150 ( V_2 ) ) ) ;
}
static int F_154 ( struct V_13 * V_14 )
{
struct V_158 * V_48 = NULL ;
#ifdef F_38
F_145 ( & V_14 -> V_2 , & V_48 , L_32 ) ;
F_145 ( & V_14 -> V_2 , & V_48 , L_33 ) ;
#else
static const char * V_163 [] = {
L_34 , L_35 ,
} ;
int V_161 ;
F_82 ( L_36 ) ;
for ( V_161 = 0 ; V_161 < F_6 ( V_163 ) ; V_161 ++ ) {
struct V_47 * V_2 ;
V_2 = F_155 ( & V_55 ,
NULL , V_163 [ V_161 ] ) ;
if ( ! V_2 ) {
F_48 ( & V_14 -> V_2 , L_37 , V_163 [ V_161 ] ) ;
return - V_164 ;
}
F_146 ( & V_14 -> V_2 , & V_48 , F_147 , V_2 ) ;
}
#endif
V_14 -> V_2 . V_165 = F_156 ( 32 ) ;
return F_157 ( & V_14 -> V_2 , & V_166 , V_48 ) ;
}
static int F_158 ( struct V_13 * V_14 )
{
F_159 ( & V_14 -> V_2 , & V_166 ) ;
return 0 ;
}
static int T_5 F_160 ( void )
{
F_82 ( L_38 ) ;
F_161 () ;
F_162 () ;
F_163 () ;
F_164 () ;
return F_165 ( & V_167 ) ;
}
static void T_6 F_166 ( void )
{
F_82 ( L_39 ) ;
F_167 ( & V_167 ) ;
F_168 () ;
F_169 () ;
F_170 () ;
F_171 () ;
}
