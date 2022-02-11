static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_9 = V_4 -> V_10 ++ ;
if ( F_4 ( V_9 >= F_5 ( V_4 -> V_8 ) ) )
return - V_11 ;
V_4 -> V_8 [ V_9 ] = V_8 ;
return V_9 ;
}
void T_1 * F_6 ( struct V_12 * V_13 , const char * V_14 ,
const char * V_15 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
void T_1 * V_19 ;
if ( V_14 )
V_17 = F_7 ( V_13 , V_20 , V_14 ) ;
else
V_17 = F_8 ( V_13 , V_20 , 0 ) ;
if ( ! V_17 ) {
F_9 ( & V_13 -> V_2 , L_1 , V_14 ) ;
return F_10 ( - V_11 ) ;
}
V_18 = F_11 ( V_17 ) ;
V_19 = F_12 ( & V_13 -> V_2 , V_17 -> V_21 , V_18 ) ;
if ( ! V_19 ) {
F_9 ( & V_13 -> V_2 , L_2 , V_14 ) ;
return F_10 ( - V_22 ) ;
}
if ( V_23 )
F_13 ( V_24 L_3 , V_15 , V_19 , V_18 ) ;
return V_19 ;
}
void F_14 ( T_2 V_25 , void T_1 * V_26 )
{
if ( V_23 )
F_13 ( V_24 L_4 , V_26 , V_25 ) ;
F_15 ( V_25 , V_26 ) ;
}
T_2 F_16 ( const void T_1 * V_26 )
{
T_2 V_27 = F_17 ( V_26 ) ;
if ( V_23 )
F_13 ( V_28 L_5 , V_26 , V_27 ) ;
return V_27 ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_19 ( V_30 ,
struct V_31 , V_30 ) ;
struct V_3 * V_4 = F_19 ( V_32 ,
struct V_3 , V_33 ) ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 , * V_38 ;
unsigned long V_39 ;
F_20 ( & V_32 -> V_40 , V_39 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_37 -> V_41 ) ;
F_23 ( & V_32 -> V_40 , V_39 ) ;
if ( V_37 -> V_42 )
V_35 -> V_43 -> V_44 ( V_35 ,
V_4 -> V_45 [ V_37 -> V_46 ] ) ;
else
V_35 -> V_43 -> V_47 ( V_35 ,
V_4 -> V_45 [ V_37 -> V_46 ] ) ;
F_24 ( V_37 ) ;
F_20 ( & V_32 -> V_40 , V_39 ) ;
}
F_23 ( & V_32 -> V_40 , V_39 ) ;
}
static int F_25 ( struct V_3 * V_4 ,
int V_46 , bool V_42 )
{
struct V_31 * V_32 = & V_4 -> V_33 ;
struct V_36 * V_37 ;
unsigned long V_39 ;
V_37 = F_26 ( sizeof( * V_37 ) , V_48 ) ;
if ( ! V_37 )
return - V_22 ;
V_37 -> V_46 = V_46 ;
V_37 -> V_42 = V_42 ;
F_20 ( & V_32 -> V_40 , V_39 ) ;
F_27 ( & V_37 -> V_41 , & V_32 -> V_49 ) ;
F_23 ( & V_32 -> V_40 , V_39 ) ;
F_28 ( V_4 -> V_50 , & V_32 -> V_30 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_2 )
{
struct V_12 * V_13 = F_30 ( V_2 ) ;
struct V_1 * V_52 = F_31 ( V_13 ) ;
struct V_3 * V_4 = V_52 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_53 * V_54 = V_4 -> V_54 ;
struct V_31 * V_32 = & V_4 -> V_33 ;
struct V_36 * V_37 , * V_38 ;
F_32 ( & V_32 -> V_30 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_37 -> V_41 ) ;
F_24 ( V_37 ) ;
}
F_33 ( V_52 ) ;
F_34 ( V_52 ) ;
F_35 ( V_52 ) ;
#ifdef F_36
if ( V_6 && V_4 -> V_6 )
F_37 ( V_52 ) ;
#endif
F_38 ( V_52 ) ;
F_39 ( V_2 ) ;
F_40 ( V_52 ) ;
F_41 ( V_2 ) ;
F_42 ( V_4 -> V_50 ) ;
F_43 ( V_4 -> V_50 ) ;
F_42 ( V_4 -> V_55 ) ;
F_43 ( V_4 -> V_55 ) ;
if ( V_35 && V_35 -> V_43 )
V_35 -> V_43 -> V_56 ( V_35 ) ;
if ( V_54 ) {
F_44 ( & V_52 -> V_57 ) ;
V_54 -> V_43 -> V_58 ( V_54 ) ;
F_45 ( & V_52 -> V_57 ) ;
V_54 -> V_43 -> V_56 ( V_54 ) ;
}
if ( V_4 -> V_59 . V_60 ) {
unsigned long V_61 = V_62 ;
F_46 ( & V_4 -> V_59 . V_63 ) ;
F_47 ( V_2 , V_4 -> V_59 . V_18 , NULL ,
V_4 -> V_59 . V_60 , V_61 ) ;
}
F_48 ( V_2 , V_52 ) ;
F_49 ( V_52 ) ;
V_52 -> V_5 = NULL ;
F_50 ( V_52 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_51 * V_2 = & V_13 -> V_2 ;
return ( int ) ( unsigned long ) F_52 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_64 * V_41 ;
unsigned long V_18 = 0 ;
int V_65 = 0 ;
V_41 = F_54 ( V_2 -> V_2 -> V_66 , L_6 , 0 ) ;
if ( V_41 ) {
struct V_16 V_67 ;
V_65 = F_55 ( V_41 , 0 , & V_67 ) ;
F_56 ( V_41 ) ;
if ( V_65 )
return V_65 ;
V_18 = V_67 . V_68 - V_67 . V_21 ;
F_57 ( L_7 , V_18 , & V_67 . V_21 ) ;
} else if ( ! F_58 ( & V_69 ) ) {
F_57 ( L_8 , V_59 ) ;
V_18 = F_59 ( V_59 , NULL ) ;
}
if ( V_18 ) {
unsigned long V_61 = 0 ;
void * V_70 ;
V_4 -> V_59 . V_18 = V_18 ;
F_60 ( & V_4 -> V_59 . V_63 , 0 , ( V_18 >> V_71 ) - 1 ) ;
V_61 |= V_62 ;
V_61 |= V_72 ;
V_70 = F_61 ( V_2 -> V_2 , V_18 ,
& V_4 -> V_59 . V_60 , V_73 , V_61 ) ;
if ( ! V_70 ) {
F_9 ( V_2 -> V_2 , L_9 ) ;
V_4 -> V_59 . V_60 = 0 ;
return - V_22 ;
}
F_62 ( V_2 -> V_2 , L_10 ,
( V_74 ) V_4 -> V_59 . V_60 ,
( V_74 ) ( V_4 -> V_59 . V_60 + V_18 ) ) ;
}
return V_65 ;
}
static int F_63 ( struct V_51 * V_2 , struct V_75 * V_76 )
{
struct V_12 * V_13 = F_30 ( V_2 ) ;
struct V_1 * V_52 ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int V_65 ;
V_52 = F_64 ( V_76 , V_2 ) ;
if ( F_65 ( V_52 ) ) {
F_9 ( V_2 , L_11 ) ;
return F_66 ( V_52 ) ;
}
F_67 ( V_13 , V_52 ) ;
V_52 -> V_77 = V_13 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 ) {
F_50 ( V_52 ) ;
return - V_22 ;
}
V_52 -> V_5 = V_4 ;
V_4 -> V_2 = V_52 ;
V_65 = F_68 ( V_52 ) ;
if ( V_65 ) {
F_24 ( V_4 ) ;
F_50 ( V_52 ) ;
return V_65 ;
}
V_4 -> V_50 = F_69 ( L_12 , 0 ) ;
V_4 -> V_55 = F_69 ( L_13 , 0 ) ;
F_70 ( & V_4 -> V_78 ) ;
F_71 ( & V_4 -> V_79 ) ;
F_71 ( & V_4 -> V_33 . V_49 ) ;
F_72 ( & V_4 -> V_33 . V_30 , F_18 ) ;
F_73 ( & V_4 -> V_33 . V_40 ) ;
F_74 ( V_52 ) ;
V_65 = F_75 ( V_2 , V_52 ) ;
if ( V_65 ) {
F_49 ( V_52 ) ;
F_24 ( V_4 ) ;
F_50 ( V_52 ) ;
return V_65 ;
}
V_65 = F_53 ( V_52 ) ;
if ( V_65 )
goto V_80;
F_76 ( V_52 ) ;
switch ( F_51 ( V_13 ) ) {
case 4 :
V_35 = F_77 ( V_52 ) ;
V_4 -> V_35 = V_35 ;
break;
case 5 :
V_35 = F_78 ( V_52 ) ;
break;
default:
V_35 = F_10 ( - V_81 ) ;
break;
}
if ( F_65 ( V_35 ) ) {
F_9 ( V_2 , L_14 ) ;
V_65 = F_66 ( V_35 ) ;
goto V_80;
}
if ( V_35 ) {
V_65 = V_35 -> V_43 -> V_82 ( V_35 ) ;
if ( V_65 ) {
F_9 ( V_2 , L_15 , V_65 ) ;
goto V_80;
}
}
V_52 -> V_83 . V_43 = & V_84 ;
V_65 = F_79 ( V_52 , V_4 -> V_85 ) ;
if ( V_65 < 0 ) {
F_9 ( V_2 , L_16 ) ;
goto V_80;
}
if ( V_35 ) {
F_39 ( V_2 ) ;
V_65 = F_80 ( V_52 , V_35 -> V_86 ) ;
F_41 ( V_2 ) ;
if ( V_65 < 0 ) {
F_9 ( V_2 , L_17 ) ;
goto V_80;
}
}
V_65 = F_81 ( V_52 , 0 ) ;
if ( V_65 )
goto V_80;
F_82 ( V_52 ) ;
#ifdef F_36
if ( V_6 )
V_4 -> V_6 = F_83 ( V_52 ) ;
#endif
V_65 = F_84 ( V_52 ) ;
if ( V_65 )
goto V_80;
F_85 ( V_52 ) ;
return 0 ;
V_80:
F_29 ( V_2 ) ;
return V_65 ;
}
static void F_86 ( struct V_1 * V_2 )
{
static F_87 ( V_87 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_44 ( & V_87 ) ;
if ( ! V_4 -> V_54 )
V_4 -> V_54 = F_88 ( V_2 ) ;
F_45 ( & V_87 ) ;
}
static int F_89 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_90 * V_91 ;
F_86 ( V_2 ) ;
V_91 = F_26 ( sizeof( * V_91 ) , V_73 ) ;
if ( ! V_91 )
return - V_22 ;
V_89 -> V_92 = V_91 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_90 * V_91 = V_89 -> V_92 ;
F_44 ( & V_2 -> V_57 ) ;
if ( V_91 == V_4 -> V_93 )
V_4 -> V_93 = NULL ;
F_45 ( & V_2 -> V_57 ) ;
F_24 ( V_91 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_92 ( V_4 -> V_6 ) ;
}
static T_3 F_93 ( int V_86 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
F_94 ( ! V_35 ) ;
return V_35 -> V_43 -> V_86 ( V_35 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
F_94 ( ! V_35 ) ;
V_35 -> V_43 -> V_95 ( V_35 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
F_94 ( ! V_35 ) ;
return V_35 -> V_43 -> V_96 ( V_35 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
F_94 ( ! V_35 ) ;
V_35 -> V_43 -> V_97 ( V_35 ) ;
}
static int F_98 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
if ( ! V_35 )
return - V_99 ;
F_99 ( L_18 , V_2 , V_98 ) ;
return F_25 ( V_4 , V_98 , true ) ;
}
static void F_100 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_35 ;
if ( ! V_35 )
return;
F_99 ( L_18 , V_2 , V_98 ) ;
F_25 ( V_4 , V_98 , false ) ;
}
static int F_101 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_100 * args = V_25 ;
struct V_53 * V_54 ;
if ( args -> V_98 != V_101 )
return - V_11 ;
V_54 = V_4 -> V_54 ;
if ( ! V_54 )
return - V_99 ;
return V_54 -> V_43 -> V_102 ( V_54 , args -> V_103 , & args -> V_104 ) ;
}
static int F_102 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_105 * args = V_25 ;
if ( args -> V_39 & ~ V_106 ) {
F_103 ( L_19 , args -> V_39 ) ;
return - V_11 ;
}
return F_104 ( V_2 , V_89 , args -> V_18 ,
args -> V_39 , & args -> V_107 ) ;
}
static inline T_4 F_105 ( struct V_108 V_109 )
{
return F_106 ( V_109 . V_110 , V_109 . V_111 ) ;
}
static int F_107 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_112 * args = V_25 ;
struct V_113 * V_114 ;
T_4 V_109 = F_105 ( args -> V_109 ) ;
int V_65 ;
if ( args -> V_115 & ~ V_116 ) {
F_103 ( L_20 , args -> V_115 ) ;
return - V_11 ;
}
V_114 = F_108 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
V_65 = F_109 ( V_114 , args -> V_115 , & V_109 ) ;
F_110 ( V_114 ) ;
return V_65 ;
}
static int F_111 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_118 * args = V_25 ;
struct V_113 * V_114 ;
int V_65 ;
V_114 = F_108 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
V_65 = F_112 ( V_114 ) ;
F_110 ( V_114 ) ;
return V_65 ;
}
static int F_113 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_119 * args = V_25 ;
struct V_113 * V_114 ;
int V_65 = 0 ;
if ( args -> V_120 )
return - V_11 ;
V_114 = F_108 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
args -> V_121 = F_114 ( V_114 ) ;
F_110 ( V_114 ) ;
return V_65 ;
}
static int F_115 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_122 * args = V_25 ;
T_4 V_109 = F_105 ( args -> V_109 ) ;
if ( args -> V_120 ) {
F_103 ( L_21 , args -> V_120 ) ;
return - V_11 ;
}
if ( ! V_4 -> V_54 )
return 0 ;
return F_116 ( V_4 -> V_54 -> V_123 , args -> V_124 , & V_109 , true ) ;
}
static int F_117 ( struct V_1 * V_2 , void * V_25 ,
struct V_88 * V_89 )
{
struct V_125 * args = V_25 ;
struct V_113 * V_114 ;
int V_65 ;
switch ( args -> V_126 ) {
case V_127 :
case V_128 :
break;
default:
return - V_11 ;
}
V_65 = F_118 ( & V_2 -> V_57 ) ;
if ( V_65 )
return V_65 ;
V_114 = F_108 ( V_89 , args -> V_107 ) ;
if ( ! V_114 ) {
V_65 = - V_117 ;
goto V_129;
}
V_65 = F_119 ( V_114 , args -> V_126 ) ;
if ( V_65 >= 0 ) {
args -> V_130 = V_65 ;
V_65 = 0 ;
}
F_120 ( V_114 ) ;
V_129:
F_45 ( & V_2 -> V_57 ) ;
return V_65 ;
}
static int F_121 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_122 ( V_2 ) ;
F_123 ( V_52 ) ;
return 0 ;
}
static int F_124 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_122 ( V_2 ) ;
F_125 ( V_52 ) ;
return 0 ;
}
static int F_126 ( struct V_51 * V_2 , void * V_25 )
{
return V_2 -> V_66 == V_25 ;
}
static int F_127 ( struct V_51 * V_131 ,
struct V_132 * * V_133 )
{
struct V_64 * V_134 = V_131 -> V_66 ;
struct V_64 * V_135 ;
struct V_51 * V_136 ;
if ( F_128 ( V_134 , L_22 ) )
V_136 = V_131 ;
else
V_136 = V_131 -> V_137 ;
F_129 (np, ep_node) {
struct V_64 * V_138 ;
struct V_139 V_140 ;
int V_65 ;
V_65 = F_130 ( V_135 , & V_140 ) ;
if ( V_65 ) {
F_9 ( V_131 , L_23 ) ;
F_56 ( V_135 ) ;
return V_65 ;
}
if ( F_128 ( V_134 , L_22 ) &&
V_140 . V_141 == 0 )
continue;
V_138 = F_131 ( V_135 ) ;
if ( ! V_138 )
continue;
F_132 ( V_136 , V_133 , F_126 ,
V_138 ) ;
F_56 ( V_138 ) ;
}
return 0 ;
}
static int F_133 ( struct V_51 * V_2 , void * V_25 )
{
return ( strstr ( F_134 ( V_2 ) , L_24 ) != NULL ) ;
}
static int F_135 ( struct V_51 * V_2 ,
struct V_132 * * V_133 )
{
struct V_51 * V_131 ;
int V_65 ;
if ( F_128 ( V_2 -> V_66 , L_25 ) ) {
V_65 = F_136 ( V_2 -> V_66 , NULL , NULL , V_2 ) ;
if ( V_65 ) {
F_9 ( V_2 , L_26 ) ;
return V_65 ;
}
V_131 = F_137 ( V_2 , NULL , F_133 ) ;
if ( ! V_131 ) {
F_9 ( V_2 , L_27 ) ;
F_138 ( V_2 ) ;
return - V_81 ;
}
F_139 ( V_131 ) ;
F_132 ( V_2 , V_133 , F_126 ,
V_131 -> V_66 ) ;
} else {
V_131 = V_2 ;
}
V_65 = F_127 ( V_131 , V_133 ) ;
if ( V_65 )
F_138 ( V_2 ) ;
return V_65 ;
}
static int F_140 ( struct V_51 * V_2 ,
struct V_132 * * V_133 )
{
struct V_64 * V_134 ;
V_134 = F_141 ( NULL , V_142 ) ;
if ( ! V_134 )
return 0 ;
F_132 ( V_2 , V_133 , F_126 , V_134 ) ;
F_56 ( V_134 ) ;
return 0 ;
}
static int F_142 ( struct V_51 * V_2 )
{
return F_63 ( V_2 , & V_143 ) ;
}
static void F_143 ( struct V_51 * V_2 )
{
F_29 ( V_2 ) ;
}
static int F_144 ( struct V_12 * V_13 )
{
struct V_132 * V_144 = NULL ;
int V_65 ;
V_65 = F_135 ( & V_13 -> V_2 , & V_144 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_140 ( & V_13 -> V_2 , & V_144 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_145 ( & V_13 -> V_2 , ~ 0 ) ;
if ( V_65 )
return V_65 ;
return F_146 ( & V_13 -> V_2 , & V_145 , V_144 ) ;
}
static int F_147 ( struct V_12 * V_13 )
{
F_148 ( & V_13 -> V_2 , & V_145 ) ;
F_138 ( & V_13 -> V_2 ) ;
return 0 ;
}
static int T_5 F_149 ( void )
{
F_99 ( L_28 ) ;
F_150 () ;
F_151 () ;
F_152 () ;
F_153 () ;
F_154 () ;
return F_155 ( & V_146 ) ;
}
static void T_6 F_156 ( void )
{
F_99 ( L_29 ) ;
F_157 ( & V_146 ) ;
F_158 () ;
F_159 () ;
F_160 () ;
F_161 () ;
F_162 () ;
}
