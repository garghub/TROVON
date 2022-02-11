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
if ( F_4 ( V_4 -> V_9 >= F_5 ( V_4 -> V_8 ) ) )
return - V_10 ;
V_4 -> V_8 [ V_4 -> V_9 ] = V_8 ;
return V_4 -> V_9 ++ ;
}
struct V_11 * F_6 ( struct V_12 * V_13 , const char * V_14 )
{
struct V_11 * V_11 ;
char V_15 [ 32 ] ;
V_11 = F_7 ( & V_13 -> V_2 , V_14 ) ;
if ( ! F_8 ( V_11 ) || F_9 ( V_11 ) == - V_16 )
return V_11 ;
snprintf ( V_15 , sizeof( V_15 ) , L_1 , V_14 ) ;
V_11 = F_7 ( & V_13 -> V_2 , V_15 ) ;
if ( ! F_8 ( V_11 ) )
F_10 ( & V_13 -> V_2 , L_2
L_3 , V_14 , V_15 ) ;
return V_11 ;
}
void T_1 * F_11 ( struct V_12 * V_13 , const char * V_14 ,
const char * V_17 )
{
struct V_18 * V_19 ;
unsigned long V_20 ;
void T_1 * V_21 ;
if ( V_14 )
V_19 = F_12 ( V_13 , V_22 , V_14 ) ;
else
V_19 = F_13 ( V_13 , V_22 , 0 ) ;
if ( ! V_19 ) {
F_14 ( & V_13 -> V_2 , L_4 , V_14 ) ;
return F_15 ( - V_10 ) ;
}
V_20 = F_16 ( V_19 ) ;
V_21 = F_17 ( & V_13 -> V_2 , V_19 -> V_23 , V_20 ) ;
if ( ! V_21 ) {
F_14 ( & V_13 -> V_2 , L_5 , V_14 ) ;
return F_15 ( - V_24 ) ;
}
if ( V_25 )
F_18 ( V_26 L_6 , V_17 , V_21 , V_20 ) ;
return V_21 ;
}
void F_19 ( T_2 V_27 , void T_1 * V_28 )
{
if ( V_25 )
F_18 ( V_26 L_7 , V_28 , V_27 ) ;
F_20 ( V_27 , V_28 ) ;
}
T_2 F_21 ( const void T_1 * V_28 )
{
T_2 V_29 = F_22 ( V_28 ) ;
if ( V_25 )
F_23 ( L_8 , V_28 , V_29 ) ;
return V_29 ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_25 ( V_31 ,
struct V_32 , V_31 ) ;
struct V_3 * V_4 = F_25 ( V_33 ,
struct V_3 , V_34 ) ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 , * V_39 ;
unsigned long V_40 ;
F_26 ( & V_33 -> V_41 , V_40 ) ;
F_27 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_28 ( & V_38 -> V_42 ) ;
F_29 ( & V_33 -> V_41 , V_40 ) ;
if ( V_38 -> V_43 )
V_36 -> V_44 -> V_45 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
else
V_36 -> V_44 -> V_48 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
F_30 ( V_38 ) ;
F_26 ( & V_33 -> V_41 , V_40 ) ;
}
F_29 ( & V_33 -> V_41 , V_40 ) ;
}
static int F_31 ( struct V_3 * V_4 ,
int V_47 , bool V_43 )
{
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 ;
unsigned long V_40 ;
V_38 = F_32 ( sizeof( * V_38 ) , V_49 ) ;
if ( ! V_38 )
return - V_24 ;
V_38 -> V_47 = V_47 ;
V_38 -> V_43 = V_43 ;
F_26 ( & V_33 -> V_41 , V_40 ) ;
F_33 ( & V_38 -> V_42 , & V_33 -> V_50 ) ;
F_29 ( & V_33 -> V_41 , V_40 ) ;
F_34 ( V_4 -> V_51 , & V_33 -> V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_2 )
{
struct V_12 * V_13 = F_36 ( V_2 ) ;
struct V_1 * V_53 = F_37 ( V_13 ) ;
struct V_3 * V_4 = V_53 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_54 * V_55 = V_4 -> V_55 ;
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 , * V_39 ;
F_38 ( & V_33 -> V_31 ) ;
F_27 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_28 ( & V_38 -> V_42 ) ;
F_30 ( V_38 ) ;
}
F_39 ( V_53 ) ;
F_40 ( V_53 ) ;
F_41 ( V_53 ) ;
F_42 ( V_4 ) ;
F_43 ( V_4 ) ;
#ifdef F_44
if ( V_6 && V_4 -> V_6 )
F_45 ( V_53 ) ;
#endif
F_46 ( V_53 ) ;
F_47 ( V_2 ) ;
F_48 ( V_53 ) ;
F_49 ( V_2 ) ;
F_50 ( V_4 -> V_51 ) ;
F_51 ( V_4 -> V_51 ) ;
F_50 ( V_4 -> V_56 ) ;
F_51 ( V_4 -> V_56 ) ;
if ( V_36 && V_36 -> V_44 )
V_36 -> V_44 -> V_57 ( V_36 ) ;
if ( V_55 ) {
F_52 ( & V_53 -> V_58 ) ;
V_55 -> V_44 -> V_59 ( V_55 ) ;
F_53 ( & V_53 -> V_58 ) ;
V_55 -> V_44 -> V_57 ( V_55 ) ;
}
if ( V_4 -> V_60 . V_61 ) {
unsigned long V_62 = V_63 ;
F_54 ( & V_4 -> V_60 . V_64 ) ;
F_55 ( V_2 , V_4 -> V_60 . V_20 , NULL ,
V_4 -> V_60 . V_61 , V_62 ) ;
}
F_56 ( V_2 , V_53 ) ;
F_57 ( V_53 ) ;
V_53 -> V_5 = NULL ;
F_58 ( V_53 ) ;
F_30 ( V_4 ) ;
return 0 ;
}
static int F_59 ( struct V_12 * V_13 )
{
struct V_52 * V_2 = & V_13 -> V_2 ;
return ( int ) ( unsigned long ) F_60 ( V_2 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_42 ;
unsigned long V_20 = 0 ;
int V_66 = 0 ;
V_42 = F_62 ( V_2 -> V_2 -> V_67 , L_9 , 0 ) ;
if ( V_42 ) {
struct V_18 V_68 ;
V_66 = F_63 ( V_42 , 0 , & V_68 ) ;
F_64 ( V_42 ) ;
if ( V_66 )
return V_66 ;
V_20 = V_68 . V_69 - V_68 . V_23 ;
F_65 ( L_10 , V_20 , & V_68 . V_23 ) ;
} else if ( ! F_66 ( & V_70 ) ) {
F_65 ( L_11 , V_60 ) ;
V_20 = F_67 ( V_60 , NULL ) ;
}
if ( V_20 ) {
unsigned long V_62 = 0 ;
void * V_71 ;
V_4 -> V_60 . V_20 = V_20 ;
F_68 ( & V_4 -> V_60 . V_64 , 0 , ( V_20 >> V_72 ) - 1 ) ;
V_62 |= V_63 ;
V_62 |= V_73 ;
V_71 = F_69 ( V_2 -> V_2 , V_20 ,
& V_4 -> V_60 . V_61 , V_74 , V_62 ) ;
if ( ! V_71 ) {
F_14 ( V_2 -> V_2 , L_12 ) ;
V_4 -> V_60 . V_61 = 0 ;
return - V_24 ;
}
F_70 ( V_2 -> V_2 , L_13 ,
( V_75 ) V_4 -> V_60 . V_61 ,
( V_75 ) ( V_4 -> V_60 . V_61 + V_20 ) ) ;
}
return V_66 ;
}
static int F_71 ( struct V_52 * V_2 , struct V_76 * V_77 )
{
struct V_12 * V_13 = F_36 ( V_2 ) ;
struct V_1 * V_53 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_66 ;
V_53 = F_72 ( V_77 , V_2 ) ;
if ( F_8 ( V_53 ) ) {
F_14 ( V_2 , L_14 ) ;
return F_9 ( V_53 ) ;
}
F_73 ( V_13 , V_53 ) ;
V_4 = F_32 ( sizeof( * V_4 ) , V_74 ) ;
if ( ! V_4 ) {
F_58 ( V_53 ) ;
return - V_24 ;
}
V_53 -> V_5 = V_4 ;
V_4 -> V_2 = V_53 ;
V_66 = F_74 ( V_53 ) ;
if ( V_66 ) {
F_30 ( V_4 ) ;
F_58 ( V_53 ) ;
return V_66 ;
}
V_4 -> V_51 = F_75 ( L_15 , 0 ) ;
V_4 -> V_56 = F_75 ( L_16 , 0 ) ;
F_76 ( & V_4 -> V_78 ) ;
F_77 ( & V_4 -> V_79 ) ;
F_77 ( & V_4 -> V_34 . V_50 ) ;
F_78 ( & V_4 -> V_34 . V_31 , F_24 ) ;
F_79 ( & V_4 -> V_34 . V_41 ) ;
F_80 ( V_53 ) ;
V_66 = F_81 ( V_2 , V_53 ) ;
if ( V_66 ) {
F_57 ( V_53 ) ;
F_30 ( V_4 ) ;
F_58 ( V_53 ) ;
return V_66 ;
}
V_66 = F_61 ( V_53 ) ;
if ( V_66 )
goto V_80;
F_82 ( V_53 ) ;
switch ( F_59 ( V_13 ) ) {
case 4 :
V_36 = F_83 ( V_53 ) ;
V_4 -> V_36 = V_36 ;
break;
case 5 :
V_36 = F_84 ( V_53 ) ;
break;
default:
V_36 = F_15 ( - V_81 ) ;
break;
}
if ( F_8 ( V_36 ) ) {
F_14 ( V_2 , L_17 ) ;
V_66 = F_9 ( V_36 ) ;
goto V_80;
}
if ( V_36 ) {
V_66 = V_36 -> V_44 -> V_82 ( V_36 ) ;
if ( V_66 ) {
F_14 ( V_2 , L_18 , V_66 ) ;
goto V_80;
}
}
V_53 -> V_83 . V_44 = & V_84 ;
V_66 = F_85 ( V_53 , V_4 -> V_85 ) ;
if ( V_66 < 0 ) {
F_14 ( V_2 , L_19 ) ;
goto V_80;
}
if ( V_36 ) {
F_47 ( V_2 ) ;
V_66 = F_86 ( V_53 , V_36 -> V_86 ) ;
F_49 ( V_2 ) ;
if ( V_66 < 0 ) {
F_14 ( V_2 , L_20 ) ;
goto V_80;
}
}
V_66 = F_87 ( V_53 , 0 ) ;
if ( V_66 )
goto V_80;
F_88 ( V_53 ) ;
#ifdef F_44
if ( V_6 )
V_4 -> V_6 = F_89 ( V_53 ) ;
#endif
V_66 = F_90 ( V_53 ) ;
if ( V_66 )
goto V_80;
F_91 ( V_53 ) ;
return 0 ;
V_80:
F_35 ( V_2 ) ;
return V_66 ;
}
static void F_92 ( struct V_1 * V_2 )
{
static F_93 ( V_87 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_52 ( & V_87 ) ;
if ( ! V_4 -> V_55 )
V_4 -> V_55 = F_94 ( V_2 ) ;
F_53 ( & V_87 ) ;
}
static int F_95 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_90 * V_91 ;
F_92 ( V_2 ) ;
V_91 = F_32 ( sizeof( * V_91 ) , V_74 ) ;
if ( ! V_91 )
return - V_24 ;
V_89 -> V_92 = V_91 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_90 * V_91 = V_89 -> V_92 ;
F_52 ( & V_2 -> V_58 ) ;
if ( V_91 == V_4 -> V_93 )
V_4 -> V_93 = NULL ;
F_53 ( & V_2 -> V_58 ) ;
F_30 ( V_91 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_98 ( V_4 -> V_6 ) ;
}
static T_3 F_99 ( int V_86 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_100 ( ! V_36 ) ;
return V_36 -> V_44 -> V_86 ( V_36 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_100 ( ! V_36 ) ;
V_36 -> V_44 -> V_95 ( V_36 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_100 ( ! V_36 ) ;
return V_36 -> V_44 -> V_96 ( V_36 ) ;
}
static void F_103 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_100 ( ! V_36 ) ;
V_36 -> V_44 -> V_97 ( V_36 ) ;
}
static int F_104 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return - V_99 ;
F_105 ( L_21 , V_2 , V_98 ) ;
return F_31 ( V_4 , V_98 , true ) ;
}
static void F_106 ( struct V_1 * V_2 , unsigned int V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return;
F_105 ( L_21 , V_2 , V_98 ) ;
F_31 ( V_4 , V_98 , false ) ;
}
static int F_107 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_100 * args = V_27 ;
struct V_54 * V_55 ;
if ( args -> V_98 != V_101 )
return - V_10 ;
V_55 = V_4 -> V_55 ;
if ( ! V_55 )
return - V_99 ;
return V_55 -> V_44 -> V_102 ( V_55 , args -> V_103 , & args -> V_104 ) ;
}
static int F_108 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_105 * args = V_27 ;
if ( args -> V_40 & ~ V_106 ) {
F_109 ( L_22 , args -> V_40 ) ;
return - V_10 ;
}
return F_110 ( V_2 , V_89 , args -> V_20 ,
args -> V_40 , & args -> V_107 ) ;
}
static inline T_4 F_111 ( struct V_108 V_109 )
{
return F_112 ( V_109 . V_110 , V_109 . V_111 ) ;
}
static int F_113 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_112 * args = V_27 ;
struct V_113 * V_114 ;
T_4 V_109 = F_111 ( args -> V_109 ) ;
int V_66 ;
if ( args -> V_115 & ~ V_116 ) {
F_109 ( L_23 , args -> V_115 ) ;
return - V_10 ;
}
V_114 = F_114 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
V_66 = F_115 ( V_114 , args -> V_115 , & V_109 ) ;
F_116 ( V_114 ) ;
return V_66 ;
}
static int F_117 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_118 * args = V_27 ;
struct V_113 * V_114 ;
int V_66 ;
V_114 = F_114 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
V_66 = F_118 ( V_114 ) ;
F_116 ( V_114 ) ;
return V_66 ;
}
static int F_119 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_119 * args = V_27 ;
struct V_113 * V_114 ;
int V_66 = 0 ;
if ( args -> V_120 )
return - V_10 ;
V_114 = F_114 ( V_89 , args -> V_107 ) ;
if ( ! V_114 )
return - V_117 ;
args -> V_121 = F_120 ( V_114 ) ;
F_116 ( V_114 ) ;
return V_66 ;
}
static int F_121 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_122 * args = V_27 ;
T_4 V_109 = F_111 ( args -> V_109 ) ;
if ( args -> V_120 ) {
F_109 ( L_24 , args -> V_120 ) ;
return - V_10 ;
}
if ( ! V_4 -> V_55 )
return 0 ;
return F_122 ( V_4 -> V_55 -> V_123 , args -> V_124 , & V_109 , true ) ;
}
static int F_123 ( struct V_1 * V_2 , void * V_27 ,
struct V_88 * V_89 )
{
struct V_125 * args = V_27 ;
struct V_113 * V_114 ;
int V_66 ;
switch ( args -> V_126 ) {
case V_127 :
case V_128 :
break;
default:
return - V_10 ;
}
V_66 = F_124 ( & V_2 -> V_58 ) ;
if ( V_66 )
return V_66 ;
V_114 = F_114 ( V_89 , args -> V_107 ) ;
if ( ! V_114 ) {
V_66 = - V_117 ;
goto V_129;
}
V_66 = F_125 ( V_114 , args -> V_126 ) ;
if ( V_66 >= 0 ) {
args -> V_130 = V_66 ;
V_66 = 0 ;
}
F_126 ( V_114 ) ;
V_129:
F_53 ( & V_2 -> V_58 ) ;
return V_66 ;
}
static int F_127 ( struct V_52 * V_2 )
{
struct V_1 * V_53 = F_128 ( V_2 ) ;
F_129 ( V_53 ) ;
return 0 ;
}
static int F_130 ( struct V_52 * V_2 )
{
struct V_1 * V_53 = F_128 ( V_2 ) ;
F_131 ( V_53 ) ;
return 0 ;
}
static int F_132 ( struct V_52 * V_2 , void * V_27 )
{
return V_2 -> V_67 == V_27 ;
}
static int F_133 ( struct V_52 * V_131 ,
struct V_132 * * V_133 )
{
struct V_65 * V_134 = V_131 -> V_67 ;
struct V_65 * V_135 ;
struct V_52 * V_136 ;
if ( F_134 ( V_134 , L_25 ) )
V_136 = V_131 ;
else
V_136 = V_131 -> V_137 ;
F_135 (np, ep_node) {
struct V_65 * V_138 ;
struct V_139 V_140 ;
int V_66 ;
V_66 = F_136 ( V_135 , & V_140 ) ;
if ( V_66 ) {
F_14 ( V_131 , L_26 ) ;
F_64 ( V_135 ) ;
return V_66 ;
}
if ( F_134 ( V_134 , L_25 ) &&
V_140 . V_141 == 0 )
continue;
V_138 = F_137 ( V_135 ) ;
if ( ! V_138 )
continue;
F_138 ( V_136 , V_133 , F_132 ,
V_138 ) ;
F_64 ( V_138 ) ;
}
return 0 ;
}
static int F_139 ( struct V_52 * V_2 , void * V_27 )
{
return ( strstr ( F_140 ( V_2 ) , L_27 ) != NULL ) ;
}
static int F_141 ( struct V_52 * V_2 ,
struct V_132 * * V_133 )
{
struct V_52 * V_131 ;
int V_66 ;
if ( F_134 ( V_2 -> V_67 , L_28 ) ) {
V_66 = F_142 ( V_2 -> V_67 , NULL , NULL , V_2 ) ;
if ( V_66 ) {
F_14 ( V_2 , L_29 ) ;
return V_66 ;
}
V_131 = F_143 ( V_2 , NULL , F_139 ) ;
if ( ! V_131 ) {
F_14 ( V_2 , L_30 ) ;
F_144 ( V_2 ) ;
return - V_81 ;
}
F_145 ( V_131 ) ;
F_138 ( V_2 , V_133 , F_132 ,
V_131 -> V_67 ) ;
} else {
V_131 = V_2 ;
}
V_66 = F_133 ( V_131 , V_133 ) ;
if ( V_66 )
F_144 ( V_2 ) ;
return V_66 ;
}
static int F_146 ( struct V_52 * V_2 ,
struct V_132 * * V_133 )
{
struct V_65 * V_134 ;
V_134 = F_147 ( NULL , V_142 ) ;
if ( ! V_134 )
return 0 ;
F_138 ( V_2 , V_133 , F_132 , V_134 ) ;
F_64 ( V_134 ) ;
return 0 ;
}
static int F_148 ( struct V_52 * V_2 )
{
return F_71 ( V_2 , & V_143 ) ;
}
static void F_149 ( struct V_52 * V_2 )
{
F_35 ( V_2 ) ;
}
static int F_150 ( struct V_12 * V_13 )
{
struct V_132 * V_144 = NULL ;
int V_66 ;
V_66 = F_141 ( & V_13 -> V_2 , & V_144 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_146 ( & V_13 -> V_2 , & V_144 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_151 ( & V_13 -> V_2 , ~ 0 ) ;
if ( V_66 )
return V_66 ;
return F_152 ( & V_13 -> V_2 , & V_145 , V_144 ) ;
}
static int F_153 ( struct V_12 * V_13 )
{
F_154 ( & V_13 -> V_2 , & V_145 ) ;
F_144 ( & V_13 -> V_2 ) ;
return 0 ;
}
static int T_5 F_155 ( void )
{
F_105 ( L_31 ) ;
F_156 () ;
F_157 () ;
F_158 () ;
F_159 () ;
F_160 () ;
return F_161 ( & V_146 ) ;
}
static void T_6 F_162 ( void )
{
F_105 ( L_32 ) ;
F_163 ( & V_146 ) ;
F_164 () ;
F_165 () ;
F_166 () ;
F_167 () ;
F_168 () ;
}
