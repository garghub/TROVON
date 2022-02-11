static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
struct V_7 * F_3 ( struct V_8 * V_9 , const char * V_10 )
{
struct V_7 * V_7 ;
char V_11 [ 32 ] ;
V_7 = F_4 ( & V_9 -> V_2 , V_10 ) ;
if ( ! F_5 ( V_7 ) || F_6 ( V_7 ) == - V_12 )
return V_7 ;
snprintf ( V_11 , sizeof( V_11 ) , L_1 , V_10 ) ;
V_7 = F_4 ( & V_9 -> V_2 , V_11 ) ;
if ( ! F_5 ( V_7 ) )
F_7 ( & V_9 -> V_2 , L_2
L_3 , V_10 , V_11 ) ;
return V_7 ;
}
void T_1 * F_8 ( struct V_8 * V_9 , const char * V_10 ,
const char * V_13 )
{
struct V_14 * V_15 ;
unsigned long V_16 ;
void T_1 * V_17 ;
if ( V_10 )
V_15 = F_9 ( V_9 , V_18 , V_10 ) ;
else
V_15 = F_10 ( V_9 , V_18 , 0 ) ;
if ( ! V_15 ) {
F_11 ( & V_9 -> V_2 , L_4 , V_10 ) ;
return F_12 ( - V_19 ) ;
}
V_16 = F_13 ( V_15 ) ;
V_17 = F_14 ( & V_9 -> V_2 , V_15 -> V_20 , V_16 ) ;
if ( ! V_17 ) {
F_11 ( & V_9 -> V_2 , L_5 , V_10 ) ;
return F_12 ( - V_21 ) ;
}
if ( V_22 )
F_15 ( V_23 L_6 , V_13 , V_17 , V_16 ) ;
return V_17 ;
}
void F_16 ( T_2 V_24 , void T_1 * V_25 )
{
if ( V_22 )
F_15 ( V_23 L_7 , V_25 , V_24 ) ;
F_17 ( V_24 , V_25 ) ;
}
T_2 F_18 ( const void T_1 * V_25 )
{
T_2 V_26 = F_19 ( V_25 ) ;
if ( V_22 )
F_20 ( L_8 , V_25 , V_26 ) ;
return V_26 ;
}
static void F_21 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ,
struct V_29 , V_28 ) ;
struct V_3 * V_4 = F_22 ( V_30 ,
struct V_3 , V_31 ) ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 , * V_36 ;
unsigned long V_37 ;
F_23 ( & V_30 -> V_38 , V_37 ) ;
F_24 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_25 ( & V_35 -> V_39 ) ;
F_26 ( & V_30 -> V_38 , V_37 ) ;
if ( V_35 -> V_40 )
V_33 -> V_41 -> V_42 ( V_33 ,
V_4 -> V_43 [ V_35 -> V_44 ] ) ;
else
V_33 -> V_41 -> V_45 ( V_33 ,
V_4 -> V_43 [ V_35 -> V_44 ] ) ;
F_27 ( V_35 ) ;
F_23 ( & V_30 -> V_38 , V_37 ) ;
}
F_26 ( & V_30 -> V_38 , V_37 ) ;
}
static int F_28 ( struct V_3 * V_4 ,
int V_44 , bool V_40 )
{
struct V_29 * V_30 = & V_4 -> V_31 ;
struct V_34 * V_35 ;
unsigned long V_37 ;
V_35 = F_29 ( sizeof( * V_35 ) , V_46 ) ;
if ( ! V_35 )
return - V_21 ;
V_35 -> V_44 = V_44 ;
V_35 -> V_40 = V_40 ;
F_23 ( & V_30 -> V_38 , V_37 ) ;
F_30 ( & V_35 -> V_39 , & V_30 -> V_47 ) ;
F_26 ( & V_30 -> V_38 , V_37 ) ;
F_31 ( V_4 -> V_48 , & V_30 -> V_28 ) ;
return 0 ;
}
static int F_32 ( struct V_49 * V_2 )
{
struct V_8 * V_9 = F_33 ( V_2 ) ;
struct V_1 * V_50 = F_34 ( V_9 ) ;
struct V_3 * V_4 = V_50 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_51 * V_52 = V_4 -> V_52 ;
struct V_29 * V_30 = & V_4 -> V_31 ;
struct V_34 * V_35 , * V_36 ;
F_35 ( & V_30 -> V_28 ) ;
F_24 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_25 ( & V_35 -> V_39 ) ;
F_27 ( V_35 ) ;
}
F_36 ( V_50 ) ;
F_37 ( V_50 ) ;
F_38 ( V_50 ) ;
F_39 ( V_4 ) ;
F_40 ( V_4 ) ;
#ifdef F_41
if ( V_6 && V_4 -> V_6 )
F_42 ( V_50 ) ;
#endif
F_43 ( V_50 ) ;
F_44 ( V_2 ) ;
F_45 ( V_50 ) ;
F_46 ( V_2 ) ;
F_47 ( V_4 -> V_48 ) ;
F_48 ( V_4 -> V_48 ) ;
F_47 ( V_4 -> V_53 ) ;
F_48 ( V_4 -> V_53 ) ;
if ( V_33 && V_33 -> V_41 )
V_33 -> V_41 -> V_54 ( V_33 ) ;
if ( V_52 ) {
F_49 ( & V_50 -> V_55 ) ;
V_52 -> V_41 -> V_56 ( V_52 ) ;
F_50 ( & V_50 -> V_55 ) ;
V_52 -> V_41 -> V_54 ( V_52 ) ;
}
if ( V_4 -> V_57 . V_58 ) {
unsigned long V_59 = V_60 ;
F_51 ( & V_4 -> V_57 . V_61 ) ;
F_52 ( V_2 , V_4 -> V_57 . V_16 , NULL ,
V_4 -> V_57 . V_58 , V_59 ) ;
}
F_53 ( V_2 , V_50 ) ;
F_54 ( V_50 ) ;
V_50 -> V_5 = NULL ;
F_55 ( V_50 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_49 * V_2 = & V_9 -> V_2 ;
return ( int ) ( unsigned long ) F_57 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_62 * V_39 ;
unsigned long V_16 = 0 ;
int V_63 = 0 ;
V_39 = F_59 ( V_2 -> V_2 -> V_64 , L_9 , 0 ) ;
if ( V_39 ) {
struct V_14 V_65 ;
V_63 = F_60 ( V_39 , 0 , & V_65 ) ;
F_61 ( V_39 ) ;
if ( V_63 )
return V_63 ;
V_16 = V_65 . V_66 - V_65 . V_20 ;
F_62 ( L_10 , V_16 , & V_65 . V_20 ) ;
} else if ( ! F_63 ( & V_67 ) ) {
F_62 ( L_11 , V_57 ) ;
V_16 = F_64 ( V_57 , NULL ) ;
}
if ( V_16 ) {
unsigned long V_59 = 0 ;
void * V_68 ;
V_4 -> V_57 . V_16 = V_16 ;
F_65 ( & V_4 -> V_57 . V_61 , 0 , ( V_16 >> V_69 ) - 1 ) ;
F_66 ( & V_4 -> V_57 . V_38 ) ;
V_59 |= V_60 ;
V_59 |= V_70 ;
V_68 = F_67 ( V_2 -> V_2 , V_16 ,
& V_4 -> V_57 . V_58 , V_71 , V_59 ) ;
if ( ! V_68 ) {
F_11 ( V_2 -> V_2 , L_12 ) ;
V_4 -> V_57 . V_58 = 0 ;
return - V_21 ;
}
F_68 ( V_2 -> V_2 , L_13 ,
( V_72 ) V_4 -> V_57 . V_58 ,
( V_72 ) ( V_4 -> V_57 . V_58 + V_16 ) ) ;
}
return V_63 ;
}
static int F_69 ( struct V_49 * V_2 , struct V_73 * V_74 )
{
struct V_8 * V_9 = F_33 ( V_2 ) ;
struct V_1 * V_50 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_63 ;
V_50 = F_70 ( V_74 , V_2 ) ;
if ( F_5 ( V_50 ) ) {
F_11 ( V_2 , L_14 ) ;
return F_6 ( V_50 ) ;
}
F_71 ( V_9 , V_50 ) ;
V_4 = F_29 ( sizeof( * V_4 ) , V_71 ) ;
if ( ! V_4 ) {
F_55 ( V_50 ) ;
return - V_21 ;
}
V_50 -> V_5 = V_4 ;
V_4 -> V_2 = V_50 ;
V_63 = F_72 ( V_50 ) ;
if ( V_63 ) {
F_27 ( V_4 ) ;
F_55 ( V_50 ) ;
return V_63 ;
}
V_4 -> V_48 = F_73 ( L_15 , 0 ) ;
V_4 -> V_53 = F_73 ( L_16 , 0 ) ;
F_74 ( & V_4 -> V_75 ) ;
F_75 ( & V_4 -> V_76 ) ;
F_75 ( & V_4 -> V_31 . V_47 ) ;
F_76 ( & V_4 -> V_31 . V_28 , F_21 ) ;
F_66 ( & V_4 -> V_31 . V_38 ) ;
F_77 ( V_50 ) ;
V_63 = F_78 ( V_2 , V_50 ) ;
if ( V_63 ) {
F_54 ( V_50 ) ;
F_27 ( V_4 ) ;
F_55 ( V_50 ) ;
return V_63 ;
}
V_63 = F_58 ( V_50 ) ;
if ( V_63 )
goto V_77;
F_79 ( V_50 ) ;
switch ( F_56 ( V_9 ) ) {
case 4 :
V_33 = F_80 ( V_50 ) ;
V_4 -> V_33 = V_33 ;
break;
case 5 :
V_33 = F_81 ( V_50 ) ;
break;
default:
V_33 = F_12 ( - V_78 ) ;
break;
}
if ( F_5 ( V_33 ) ) {
F_11 ( V_2 , L_17 ) ;
V_63 = F_6 ( V_33 ) ;
goto V_77;
}
if ( V_33 ) {
V_63 = V_33 -> V_41 -> V_79 ( V_33 ) ;
if ( V_63 ) {
F_11 ( V_2 , L_18 , V_63 ) ;
goto V_77;
}
}
V_50 -> V_80 . V_41 = & V_81 ;
V_63 = F_82 ( V_50 , V_4 -> V_82 ) ;
if ( V_63 < 0 ) {
F_11 ( V_2 , L_19 ) ;
goto V_77;
}
if ( V_33 ) {
F_44 ( V_2 ) ;
V_63 = F_83 ( V_50 , V_33 -> V_83 ) ;
F_46 ( V_2 ) ;
if ( V_63 < 0 ) {
F_11 ( V_2 , L_20 ) ;
goto V_77;
}
}
V_63 = F_84 ( V_50 , 0 ) ;
if ( V_63 )
goto V_77;
F_85 ( V_50 ) ;
#ifdef F_41
if ( V_6 )
V_4 -> V_6 = F_86 ( V_50 ) ;
#endif
V_63 = F_87 ( V_50 ) ;
if ( V_63 )
goto V_77;
F_88 ( V_50 ) ;
return 0 ;
V_77:
F_32 ( V_2 ) ;
return V_63 ;
}
static void F_89 ( struct V_1 * V_2 )
{
static F_90 ( V_84 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_49 ( & V_84 ) ;
if ( ! V_4 -> V_52 )
V_4 -> V_52 = F_91 ( V_2 ) ;
F_50 ( & V_84 ) ;
}
static int F_92 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_87 * V_88 ;
F_89 ( V_2 ) ;
V_88 = F_29 ( sizeof( * V_88 ) , V_71 ) ;
if ( ! V_88 )
return - V_21 ;
V_86 -> V_89 = V_88 ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_87 * V_88 = V_86 -> V_89 ;
F_49 ( & V_2 -> V_55 ) ;
if ( V_88 == V_4 -> V_90 )
V_4 -> V_90 = NULL ;
F_50 ( & V_2 -> V_55 ) ;
F_27 ( V_88 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_95 ( V_4 -> V_6 ) ;
}
static T_3 F_96 ( int V_83 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
F_97 ( ! V_33 ) ;
return V_33 -> V_41 -> V_83 ( V_33 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
F_97 ( ! V_33 ) ;
V_33 -> V_41 -> V_92 ( V_33 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
F_97 ( ! V_33 ) ;
return V_33 -> V_41 -> V_93 ( V_33 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
F_97 ( ! V_33 ) ;
V_33 -> V_41 -> V_94 ( V_33 ) ;
}
static int F_101 ( struct V_1 * V_2 , unsigned int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( ! V_33 )
return - V_96 ;
F_102 ( L_21 , V_2 , V_95 ) ;
return F_28 ( V_4 , V_95 , true ) ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( ! V_33 )
return;
F_102 ( L_21 , V_2 , V_95 ) ;
F_28 ( V_4 , V_95 , false ) ;
}
static int F_104 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * args = V_24 ;
struct V_51 * V_52 ;
if ( args -> V_95 != V_98 )
return - V_19 ;
V_52 = V_4 -> V_52 ;
if ( ! V_52 )
return - V_96 ;
return V_52 -> V_41 -> V_99 ( V_52 , args -> V_100 , & args -> V_101 ) ;
}
static int F_105 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_102 * args = V_24 ;
if ( args -> V_37 & ~ V_103 ) {
F_106 ( L_22 , args -> V_37 ) ;
return - V_19 ;
}
return F_107 ( V_2 , V_86 , args -> V_16 ,
args -> V_37 , & args -> V_104 ) ;
}
static inline T_4 F_108 ( struct V_105 V_106 )
{
return F_109 ( V_106 . V_107 , V_106 . V_108 ) ;
}
static int F_110 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_109 * args = V_24 ;
struct V_110 * V_111 ;
T_4 V_106 = F_108 ( args -> V_106 ) ;
int V_63 ;
if ( args -> V_112 & ~ V_113 ) {
F_106 ( L_23 , args -> V_112 ) ;
return - V_19 ;
}
V_111 = F_111 ( V_86 , args -> V_104 ) ;
if ( ! V_111 )
return - V_114 ;
V_63 = F_112 ( V_111 , args -> V_112 , & V_106 ) ;
F_113 ( V_111 ) ;
return V_63 ;
}
static int F_114 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_115 * args = V_24 ;
struct V_110 * V_111 ;
int V_63 ;
V_111 = F_111 ( V_86 , args -> V_104 ) ;
if ( ! V_111 )
return - V_114 ;
V_63 = F_115 ( V_111 ) ;
F_113 ( V_111 ) ;
return V_63 ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_110 * V_111 , T_5 * V_116 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_52 )
return - V_19 ;
return F_117 ( V_111 , V_4 -> V_52 -> V_117 , V_116 ) ;
}
static int F_118 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_118 * args = V_24 ;
struct V_110 * V_111 ;
int V_63 = 0 ;
if ( args -> V_37 & ~ V_119 )
return - V_19 ;
V_111 = F_111 ( V_86 , args -> V_104 ) ;
if ( ! V_111 )
return - V_114 ;
if ( args -> V_37 & V_120 ) {
T_5 V_116 ;
V_63 = F_116 ( V_2 , V_111 , & V_116 ) ;
if ( ! V_63 )
args -> V_121 = V_116 ;
} else {
args -> V_121 = F_119 ( V_111 ) ;
}
F_113 ( V_111 ) ;
return V_63 ;
}
static int F_120 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_122 * args = V_24 ;
T_4 V_106 = F_108 ( args -> V_106 ) ;
if ( args -> V_123 ) {
F_106 ( L_24 , args -> V_123 ) ;
return - V_19 ;
}
if ( ! V_4 -> V_52 )
return 0 ;
return F_121 ( V_4 -> V_52 -> V_124 , args -> V_125 , & V_106 , true ) ;
}
static int F_122 ( struct V_1 * V_2 , void * V_24 ,
struct V_85 * V_86 )
{
struct V_126 * args = V_24 ;
struct V_110 * V_111 ;
int V_63 ;
switch ( args -> V_127 ) {
case V_128 :
case V_129 :
break;
default:
return - V_19 ;
}
V_63 = F_123 ( & V_2 -> V_55 ) ;
if ( V_63 )
return V_63 ;
V_111 = F_111 ( V_86 , args -> V_104 ) ;
if ( ! V_111 ) {
V_63 = - V_114 ;
goto V_130;
}
V_63 = F_124 ( V_111 , args -> V_127 ) ;
if ( V_63 >= 0 ) {
args -> V_131 = V_63 ;
V_63 = 0 ;
}
F_125 ( V_111 ) ;
V_130:
F_50 ( & V_2 -> V_55 ) ;
return V_63 ;
}
static int F_126 ( struct V_49 * V_2 )
{
struct V_1 * V_50 = F_127 ( V_2 ) ;
F_128 ( V_50 ) ;
return 0 ;
}
static int F_129 ( struct V_49 * V_2 )
{
struct V_1 * V_50 = F_127 ( V_2 ) ;
F_130 ( V_50 ) ;
return 0 ;
}
static int F_131 ( struct V_49 * V_2 , void * V_24 )
{
return V_2 -> V_64 == V_24 ;
}
static int F_132 ( struct V_49 * V_132 ,
struct V_133 * * V_134 )
{
struct V_62 * V_135 = V_132 -> V_64 ;
struct V_62 * V_136 ;
struct V_49 * V_137 ;
if ( F_133 ( V_135 , L_25 ) )
V_137 = V_132 ;
else
V_137 = V_132 -> V_138 ;
F_134 (np, ep_node) {
struct V_62 * V_139 ;
struct V_140 V_141 ;
int V_63 ;
V_63 = F_135 ( V_136 , & V_141 ) ;
if ( V_63 ) {
F_11 ( V_132 , L_26 ) ;
F_61 ( V_136 ) ;
return V_63 ;
}
if ( F_133 ( V_135 , L_25 ) &&
V_141 . V_142 == 0 )
continue;
V_139 = F_136 ( V_136 ) ;
if ( ! V_139 )
continue;
F_137 ( V_137 , V_134 , F_131 ,
V_139 ) ;
F_61 ( V_139 ) ;
}
return 0 ;
}
static int F_138 ( struct V_49 * V_2 , void * V_24 )
{
return ( strstr ( F_139 ( V_2 ) , L_27 ) != NULL ) ;
}
static int F_140 ( struct V_49 * V_2 ,
struct V_133 * * V_134 )
{
struct V_49 * V_132 ;
int V_63 ;
if ( F_133 ( V_2 -> V_64 , L_28 ) ) {
V_63 = F_141 ( V_2 -> V_64 , NULL , NULL , V_2 ) ;
if ( V_63 ) {
F_11 ( V_2 , L_29 ) ;
return V_63 ;
}
V_132 = F_142 ( V_2 , NULL , F_138 ) ;
if ( ! V_132 ) {
F_11 ( V_2 , L_30 ) ;
F_143 ( V_2 ) ;
return - V_78 ;
}
F_144 ( V_132 ) ;
F_137 ( V_2 , V_134 , F_131 ,
V_132 -> V_64 ) ;
} else {
V_132 = V_2 ;
}
V_63 = F_132 ( V_132 , V_134 ) ;
if ( V_63 )
F_143 ( V_2 ) ;
return V_63 ;
}
static int F_145 ( struct V_49 * V_2 ,
struct V_133 * * V_134 )
{
struct V_62 * V_135 ;
V_135 = F_146 ( NULL , V_143 ) ;
if ( ! V_135 )
return 0 ;
F_137 ( V_2 , V_134 , F_131 , V_135 ) ;
F_61 ( V_135 ) ;
return 0 ;
}
static int F_147 ( struct V_49 * V_2 )
{
return F_69 ( V_2 , & V_144 ) ;
}
static void F_148 ( struct V_49 * V_2 )
{
F_32 ( V_2 ) ;
}
static int F_149 ( struct V_8 * V_9 )
{
struct V_133 * V_145 = NULL ;
int V_63 ;
V_63 = F_140 ( & V_9 -> V_2 , & V_145 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_145 ( & V_9 -> V_2 , & V_145 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_150 ( & V_9 -> V_2 , ~ 0 ) ;
if ( V_63 )
return V_63 ;
return F_151 ( & V_9 -> V_2 , & V_146 , V_145 ) ;
}
static int F_152 ( struct V_8 * V_9 )
{
F_153 ( & V_9 -> V_2 , & V_146 ) ;
F_143 ( & V_9 -> V_2 ) ;
return 0 ;
}
static int T_6 F_154 ( void )
{
F_102 ( L_31 ) ;
F_155 () ;
F_156 () ;
F_157 () ;
F_158 () ;
F_159 () ;
return F_160 ( & V_147 ) ;
}
static void T_7 F_161 ( void )
{
F_102 ( L_32 ) ;
F_162 ( & V_147 ) ;
F_163 () ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
}
