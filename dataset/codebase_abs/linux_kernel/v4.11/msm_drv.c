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
struct V_12 * F_6 ( struct V_13 * V_14 , const char * V_15 )
{
struct V_12 * V_12 ;
char V_16 [ 32 ] ;
V_12 = F_7 ( & V_14 -> V_2 , V_15 ) ;
if ( ! F_8 ( V_12 ) || F_9 ( V_12 ) == - V_17 )
return V_12 ;
snprintf ( V_16 , sizeof( V_16 ) , L_1 , V_15 ) ;
V_12 = F_7 ( & V_14 -> V_2 , V_16 ) ;
if ( ! F_8 ( V_12 ) )
F_10 ( & V_14 -> V_2 , L_2
L_3 , V_15 , V_16 ) ;
return V_12 ;
}
void T_1 * F_11 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_18 )
{
struct V_19 * V_20 ;
unsigned long V_21 ;
void T_1 * V_22 ;
if ( V_15 )
V_20 = F_12 ( V_14 , V_23 , V_15 ) ;
else
V_20 = F_13 ( V_14 , V_23 , 0 ) ;
if ( ! V_20 ) {
F_14 ( & V_14 -> V_2 , L_4 , V_15 ) ;
return F_15 ( - V_11 ) ;
}
V_21 = F_16 ( V_20 ) ;
V_22 = F_17 ( & V_14 -> V_2 , V_20 -> V_24 , V_21 ) ;
if ( ! V_22 ) {
F_14 ( & V_14 -> V_2 , L_5 , V_15 ) ;
return F_15 ( - V_25 ) ;
}
if ( V_26 )
F_18 ( V_27 L_6 , V_18 , V_22 , V_21 ) ;
return V_22 ;
}
void F_19 ( T_2 V_28 , void T_1 * V_29 )
{
if ( V_26 )
F_18 ( V_27 L_7 , V_29 , V_28 ) ;
F_20 ( V_28 , V_29 ) ;
}
T_2 F_21 ( const void T_1 * V_29 )
{
T_2 V_30 = F_22 ( V_29 ) ;
if ( V_26 )
F_18 ( V_31 L_8 , V_29 , V_30 ) ;
return V_30 ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_24 ( V_33 ,
struct V_34 , V_33 ) ;
struct V_3 * V_4 = F_24 ( V_35 ,
struct V_3 , V_36 ) ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_39 * V_40 , * V_41 ;
unsigned long V_42 ;
F_25 ( & V_35 -> V_43 , V_42 ) ;
F_26 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_27 ( & V_40 -> V_44 ) ;
F_28 ( & V_35 -> V_43 , V_42 ) ;
if ( V_40 -> V_45 )
V_38 -> V_46 -> V_47 ( V_38 ,
V_4 -> V_48 [ V_40 -> V_49 ] ) ;
else
V_38 -> V_46 -> V_50 ( V_38 ,
V_4 -> V_48 [ V_40 -> V_49 ] ) ;
F_29 ( V_40 ) ;
F_25 ( & V_35 -> V_43 , V_42 ) ;
}
F_28 ( & V_35 -> V_43 , V_42 ) ;
}
static int F_30 ( struct V_3 * V_4 ,
int V_49 , bool V_45 )
{
struct V_34 * V_35 = & V_4 -> V_36 ;
struct V_39 * V_40 ;
unsigned long V_42 ;
V_40 = F_31 ( sizeof( * V_40 ) , V_51 ) ;
if ( ! V_40 )
return - V_25 ;
V_40 -> V_49 = V_49 ;
V_40 -> V_45 = V_45 ;
F_25 ( & V_35 -> V_43 , V_42 ) ;
F_32 ( & V_40 -> V_44 , & V_35 -> V_52 ) ;
F_28 ( & V_35 -> V_43 , V_42 ) ;
F_33 ( V_4 -> V_53 , & V_35 -> V_33 ) ;
return 0 ;
}
static int F_34 ( struct V_54 * V_2 )
{
struct V_13 * V_14 = F_35 ( V_2 ) ;
struct V_1 * V_55 = F_36 ( V_14 ) ;
struct V_3 * V_4 = V_55 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_56 * V_57 = V_4 -> V_57 ;
struct V_34 * V_35 = & V_4 -> V_36 ;
struct V_39 * V_40 , * V_41 ;
F_37 ( & V_35 -> V_33 ) ;
F_26 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_27 ( & V_40 -> V_44 ) ;
F_29 ( V_40 ) ;
}
F_38 ( V_55 ) ;
F_39 ( V_55 ) ;
F_40 ( V_55 ) ;
#ifdef F_41
if ( V_6 && V_4 -> V_6 )
F_42 ( V_55 ) ;
#endif
F_43 ( V_55 ) ;
F_44 ( V_2 ) ;
F_45 ( V_55 ) ;
F_46 ( V_2 ) ;
F_47 ( V_4 -> V_53 ) ;
F_48 ( V_4 -> V_53 ) ;
F_47 ( V_4 -> V_58 ) ;
F_48 ( V_4 -> V_58 ) ;
if ( V_38 && V_38 -> V_46 )
V_38 -> V_46 -> V_59 ( V_38 ) ;
if ( V_57 ) {
F_49 ( & V_55 -> V_60 ) ;
V_57 -> V_46 -> V_61 ( V_57 ) ;
F_50 ( & V_55 -> V_60 ) ;
V_57 -> V_46 -> V_59 ( V_57 ) ;
}
if ( V_4 -> V_62 . V_63 ) {
unsigned long V_64 = V_65 ;
F_51 ( & V_4 -> V_62 . V_66 ) ;
F_52 ( V_2 , V_4 -> V_62 . V_21 , NULL ,
V_4 -> V_62 . V_63 , V_64 ) ;
}
F_53 ( V_2 , V_55 ) ;
F_54 ( V_55 ) ;
V_55 -> V_5 = NULL ;
F_55 ( V_55 ) ;
F_29 ( V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_13 * V_14 )
{
struct V_54 * V_2 = & V_14 -> V_2 ;
return ( int ) ( unsigned long ) F_57 ( V_2 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_67 * V_44 ;
unsigned long V_21 = 0 ;
int V_68 = 0 ;
V_44 = F_59 ( V_2 -> V_2 -> V_69 , L_9 , 0 ) ;
if ( V_44 ) {
struct V_19 V_70 ;
V_68 = F_60 ( V_44 , 0 , & V_70 ) ;
F_61 ( V_44 ) ;
if ( V_68 )
return V_68 ;
V_21 = V_70 . V_71 - V_70 . V_24 ;
F_62 ( L_10 , V_21 , & V_70 . V_24 ) ;
} else if ( ! F_63 ( & V_72 ) ) {
F_62 ( L_11 , V_62 ) ;
V_21 = F_64 ( V_62 , NULL ) ;
}
if ( V_21 ) {
unsigned long V_64 = 0 ;
void * V_73 ;
V_4 -> V_62 . V_21 = V_21 ;
F_65 ( & V_4 -> V_62 . V_66 , 0 , ( V_21 >> V_74 ) - 1 ) ;
V_64 |= V_65 ;
V_64 |= V_75 ;
V_73 = F_66 ( V_2 -> V_2 , V_21 ,
& V_4 -> V_62 . V_63 , V_76 , V_64 ) ;
if ( ! V_73 ) {
F_14 ( V_2 -> V_2 , L_12 ) ;
V_4 -> V_62 . V_63 = 0 ;
return - V_25 ;
}
F_67 ( V_2 -> V_2 , L_13 ,
( V_77 ) V_4 -> V_62 . V_63 ,
( V_77 ) ( V_4 -> V_62 . V_63 + V_21 ) ) ;
}
return V_68 ;
}
static int F_68 ( struct V_54 * V_2 , struct V_78 * V_79 )
{
struct V_13 * V_14 = F_35 ( V_2 ) ;
struct V_1 * V_55 ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
int V_68 ;
V_55 = F_69 ( V_79 , V_2 ) ;
if ( F_8 ( V_55 ) ) {
F_14 ( V_2 , L_14 ) ;
return F_9 ( V_55 ) ;
}
F_70 ( V_14 , V_55 ) ;
V_55 -> V_80 = V_14 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_76 ) ;
if ( ! V_4 ) {
F_55 ( V_55 ) ;
return - V_25 ;
}
V_55 -> V_5 = V_4 ;
V_4 -> V_2 = V_55 ;
V_68 = F_71 ( V_55 ) ;
if ( V_68 ) {
F_29 ( V_4 ) ;
F_55 ( V_55 ) ;
return V_68 ;
}
V_4 -> V_53 = F_72 ( L_15 , 0 ) ;
V_4 -> V_58 = F_72 ( L_16 , 0 ) ;
F_73 ( & V_4 -> V_81 ) ;
F_74 ( & V_4 -> V_82 ) ;
F_74 ( & V_4 -> V_36 . V_52 ) ;
F_75 ( & V_4 -> V_36 . V_33 , F_23 ) ;
F_76 ( & V_4 -> V_36 . V_43 ) ;
F_77 ( V_55 ) ;
V_68 = F_78 ( V_2 , V_55 ) ;
if ( V_68 ) {
F_54 ( V_55 ) ;
F_29 ( V_4 ) ;
F_55 ( V_55 ) ;
return V_68 ;
}
V_68 = F_58 ( V_55 ) ;
if ( V_68 )
goto V_83;
F_79 ( V_55 ) ;
switch ( F_56 ( V_14 ) ) {
case 4 :
V_38 = F_80 ( V_55 ) ;
V_4 -> V_38 = V_38 ;
break;
case 5 :
V_38 = F_81 ( V_55 ) ;
break;
default:
V_38 = F_15 ( - V_84 ) ;
break;
}
if ( F_8 ( V_38 ) ) {
F_14 ( V_2 , L_17 ) ;
V_68 = F_9 ( V_38 ) ;
goto V_83;
}
if ( V_38 ) {
V_68 = V_38 -> V_46 -> V_85 ( V_38 ) ;
if ( V_68 ) {
F_14 ( V_2 , L_18 , V_68 ) ;
goto V_83;
}
}
V_55 -> V_86 . V_46 = & V_87 ;
V_68 = F_82 ( V_55 , V_4 -> V_88 ) ;
if ( V_68 < 0 ) {
F_14 ( V_2 , L_19 ) ;
goto V_83;
}
if ( V_38 ) {
F_44 ( V_2 ) ;
V_68 = F_83 ( V_55 , V_38 -> V_89 ) ;
F_46 ( V_2 ) ;
if ( V_68 < 0 ) {
F_14 ( V_2 , L_20 ) ;
goto V_83;
}
}
V_68 = F_84 ( V_55 , 0 ) ;
if ( V_68 )
goto V_83;
F_85 ( V_55 ) ;
#ifdef F_41
if ( V_6 )
V_4 -> V_6 = F_86 ( V_55 ) ;
#endif
V_68 = F_87 ( V_55 ) ;
if ( V_68 )
goto V_83;
F_88 ( V_55 ) ;
return 0 ;
V_83:
F_34 ( V_2 ) ;
return V_68 ;
}
static void F_89 ( struct V_1 * V_2 )
{
static F_90 ( V_90 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_49 ( & V_90 ) ;
if ( ! V_4 -> V_57 )
V_4 -> V_57 = F_91 ( V_2 ) ;
F_50 ( & V_90 ) ;
}
static int F_92 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_93 * V_94 ;
F_89 ( V_2 ) ;
V_94 = F_31 ( sizeof( * V_94 ) , V_76 ) ;
if ( ! V_94 )
return - V_25 ;
V_92 -> V_95 = V_94 ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_93 * V_94 = V_92 -> V_95 ;
F_49 ( & V_2 -> V_60 ) ;
if ( V_94 == V_4 -> V_96 )
V_4 -> V_96 = NULL ;
F_50 ( & V_2 -> V_60 ) ;
F_29 ( V_94 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_95 ( V_4 -> V_6 ) ;
}
static T_3 F_96 ( int V_89 , void * V_97 )
{
struct V_1 * V_2 = V_97 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
F_97 ( ! V_38 ) ;
return V_38 -> V_46 -> V_89 ( V_38 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
F_97 ( ! V_38 ) ;
V_38 -> V_46 -> V_98 ( V_38 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
F_97 ( ! V_38 ) ;
return V_38 -> V_46 -> V_99 ( V_38 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
F_97 ( ! V_38 ) ;
V_38 -> V_46 -> V_100 ( V_38 ) ;
}
static int F_101 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
if ( ! V_38 )
return - V_102 ;
F_102 ( L_21 , V_2 , V_101 ) ;
return F_30 ( V_4 , V_101 , true ) ;
}
static void F_103 ( struct V_1 * V_2 , unsigned int V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_37 * V_38 = V_4 -> V_38 ;
if ( ! V_38 )
return;
F_102 ( L_21 , V_2 , V_101 ) ;
F_30 ( V_4 , V_101 , false ) ;
}
static int F_104 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_103 * args = V_28 ;
struct V_56 * V_57 ;
if ( args -> V_101 != V_104 )
return - V_11 ;
V_57 = V_4 -> V_57 ;
if ( ! V_57 )
return - V_102 ;
return V_57 -> V_46 -> V_105 ( V_57 , args -> V_106 , & args -> V_107 ) ;
}
static int F_105 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_108 * args = V_28 ;
if ( args -> V_42 & ~ V_109 ) {
F_106 ( L_22 , args -> V_42 ) ;
return - V_11 ;
}
return F_107 ( V_2 , V_92 , args -> V_21 ,
args -> V_42 , & args -> V_110 ) ;
}
static inline T_4 F_108 ( struct V_111 V_112 )
{
return F_109 ( V_112 . V_113 , V_112 . V_114 ) ;
}
static int F_110 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_115 * args = V_28 ;
struct V_116 * V_117 ;
T_4 V_112 = F_108 ( args -> V_112 ) ;
int V_68 ;
if ( args -> V_118 & ~ V_119 ) {
F_106 ( L_23 , args -> V_118 ) ;
return - V_11 ;
}
V_117 = F_111 ( V_92 , args -> V_110 ) ;
if ( ! V_117 )
return - V_120 ;
V_68 = F_112 ( V_117 , args -> V_118 , & V_112 ) ;
F_113 ( V_117 ) ;
return V_68 ;
}
static int F_114 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_121 * args = V_28 ;
struct V_116 * V_117 ;
int V_68 ;
V_117 = F_111 ( V_92 , args -> V_110 ) ;
if ( ! V_117 )
return - V_120 ;
V_68 = F_115 ( V_117 ) ;
F_113 ( V_117 ) ;
return V_68 ;
}
static int F_116 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_122 * args = V_28 ;
struct V_116 * V_117 ;
int V_68 = 0 ;
if ( args -> V_123 )
return - V_11 ;
V_117 = F_111 ( V_92 , args -> V_110 ) ;
if ( ! V_117 )
return - V_120 ;
args -> V_124 = F_117 ( V_117 ) ;
F_113 ( V_117 ) ;
return V_68 ;
}
static int F_118 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_125 * args = V_28 ;
T_4 V_112 = F_108 ( args -> V_112 ) ;
if ( args -> V_123 ) {
F_106 ( L_24 , args -> V_123 ) ;
return - V_11 ;
}
if ( ! V_4 -> V_57 )
return 0 ;
return F_119 ( V_4 -> V_57 -> V_126 , args -> V_127 , & V_112 , true ) ;
}
static int F_120 ( struct V_1 * V_2 , void * V_28 ,
struct V_91 * V_92 )
{
struct V_128 * args = V_28 ;
struct V_116 * V_117 ;
int V_68 ;
switch ( args -> V_129 ) {
case V_130 :
case V_131 :
break;
default:
return - V_11 ;
}
V_68 = F_121 ( & V_2 -> V_60 ) ;
if ( V_68 )
return V_68 ;
V_117 = F_111 ( V_92 , args -> V_110 ) ;
if ( ! V_117 ) {
V_68 = - V_120 ;
goto V_132;
}
V_68 = F_122 ( V_117 , args -> V_129 ) ;
if ( V_68 >= 0 ) {
args -> V_133 = V_68 ;
V_68 = 0 ;
}
F_123 ( V_117 ) ;
V_132:
F_50 ( & V_2 -> V_60 ) ;
return V_68 ;
}
static int F_124 ( struct V_54 * V_2 )
{
struct V_1 * V_55 = F_125 ( V_2 ) ;
F_126 ( V_55 ) ;
return 0 ;
}
static int F_127 ( struct V_54 * V_2 )
{
struct V_1 * V_55 = F_125 ( V_2 ) ;
F_128 ( V_55 ) ;
return 0 ;
}
static int F_129 ( struct V_54 * V_2 , void * V_28 )
{
return V_2 -> V_69 == V_28 ;
}
static int F_130 ( struct V_54 * V_134 ,
struct V_135 * * V_136 )
{
struct V_67 * V_137 = V_134 -> V_69 ;
struct V_67 * V_138 ;
struct V_54 * V_139 ;
if ( F_131 ( V_137 , L_25 ) )
V_139 = V_134 ;
else
V_139 = V_134 -> V_140 ;
F_132 (np, ep_node) {
struct V_67 * V_141 ;
struct V_142 V_143 ;
int V_68 ;
V_68 = F_133 ( V_138 , & V_143 ) ;
if ( V_68 ) {
F_14 ( V_134 , L_26 ) ;
F_61 ( V_138 ) ;
return V_68 ;
}
if ( F_131 ( V_137 , L_25 ) &&
V_143 . V_144 == 0 )
continue;
V_141 = F_134 ( V_138 ) ;
if ( ! V_141 )
continue;
F_135 ( V_139 , V_136 , F_129 ,
V_141 ) ;
F_61 ( V_141 ) ;
}
return 0 ;
}
static int F_136 ( struct V_54 * V_2 , void * V_28 )
{
return ( strstr ( F_137 ( V_2 ) , L_27 ) != NULL ) ;
}
static int F_138 ( struct V_54 * V_2 ,
struct V_135 * * V_136 )
{
struct V_54 * V_134 ;
int V_68 ;
if ( F_131 ( V_2 -> V_69 , L_28 ) ) {
V_68 = F_139 ( V_2 -> V_69 , NULL , NULL , V_2 ) ;
if ( V_68 ) {
F_14 ( V_2 , L_29 ) ;
return V_68 ;
}
V_134 = F_140 ( V_2 , NULL , F_136 ) ;
if ( ! V_134 ) {
F_14 ( V_2 , L_30 ) ;
F_141 ( V_2 ) ;
return - V_84 ;
}
F_142 ( V_134 ) ;
F_135 ( V_2 , V_136 , F_129 ,
V_134 -> V_69 ) ;
} else {
V_134 = V_2 ;
}
V_68 = F_130 ( V_134 , V_136 ) ;
if ( V_68 )
F_141 ( V_2 ) ;
return V_68 ;
}
static int F_143 ( struct V_54 * V_2 ,
struct V_135 * * V_136 )
{
struct V_67 * V_137 ;
V_137 = F_144 ( NULL , V_145 ) ;
if ( ! V_137 )
return 0 ;
F_135 ( V_2 , V_136 , F_129 , V_137 ) ;
F_61 ( V_137 ) ;
return 0 ;
}
static int F_145 ( struct V_54 * V_2 )
{
return F_68 ( V_2 , & V_146 ) ;
}
static void F_146 ( struct V_54 * V_2 )
{
F_34 ( V_2 ) ;
}
static int F_147 ( struct V_13 * V_14 )
{
struct V_135 * V_147 = NULL ;
int V_68 ;
V_68 = F_138 ( & V_14 -> V_2 , & V_147 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_143 ( & V_14 -> V_2 , & V_147 ) ;
if ( V_68 )
return V_68 ;
V_68 = F_148 ( & V_14 -> V_2 , ~ 0 ) ;
if ( V_68 )
return V_68 ;
return F_149 ( & V_14 -> V_2 , & V_148 , V_147 ) ;
}
static int F_150 ( struct V_13 * V_14 )
{
F_151 ( & V_14 -> V_2 , & V_148 ) ;
F_141 ( & V_14 -> V_2 ) ;
return 0 ;
}
static int T_5 F_152 ( void )
{
F_102 ( L_31 ) ;
F_153 () ;
F_154 () ;
F_155 () ;
F_156 () ;
F_157 () ;
return F_158 ( & V_149 ) ;
}
static void T_6 F_159 ( void )
{
F_102 ( L_32 ) ;
F_160 ( & V_149 ) ;
F_161 () ;
F_162 () ;
F_163 () ;
F_164 () ;
F_165 () ;
}
