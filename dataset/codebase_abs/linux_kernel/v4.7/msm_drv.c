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
F_13 ( V_25 L_3 , V_16 , V_20 , V_19 ) ;
return V_20 ;
}
void F_14 ( T_2 V_26 , void T_1 * V_27 )
{
if ( V_24 )
F_13 ( V_25 L_4 , V_27 , V_26 ) ;
F_15 ( V_26 , V_27 ) ;
}
T_2 F_16 ( const void T_1 * V_27 )
{
T_2 V_28 = F_17 ( V_27 ) ;
if ( V_24 )
F_13 ( V_29 L_5 , V_27 , V_28 ) ;
return V_28 ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_19 ( V_31 ,
struct V_32 , V_31 ) ;
struct V_3 * V_4 = F_19 ( V_33 ,
struct V_3 , V_34 ) ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 , * V_39 ;
unsigned long V_40 ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_38 -> V_42 ) ;
F_23 ( & V_33 -> V_41 , V_40 ) ;
if ( V_38 -> V_43 )
V_36 -> V_44 -> V_45 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
else
V_36 -> V_44 -> V_48 ( V_36 ,
V_4 -> V_46 [ V_38 -> V_47 ] ) ;
F_24 ( V_38 ) ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
}
F_23 ( & V_33 -> V_41 , V_40 ) ;
}
static int F_25 ( struct V_3 * V_4 ,
int V_47 , bool V_43 )
{
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 ;
unsigned long V_40 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_49 ) ;
if ( ! V_38 )
return - V_23 ;
V_38 -> V_47 = V_47 ;
V_38 -> V_43 = V_43 ;
F_20 ( & V_33 -> V_41 , V_40 ) ;
F_27 ( & V_38 -> V_42 , & V_33 -> V_50 ) ;
F_23 ( & V_33 -> V_41 , V_40 ) ;
F_28 ( V_4 -> V_51 , & V_33 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_2 )
{
struct V_13 * V_14 = F_30 ( V_2 ) ;
struct V_1 * V_53 = F_31 ( V_14 ) ;
struct V_3 * V_4 = V_53 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_54 * V_55 = V_4 -> V_55 ;
struct V_32 * V_33 = & V_4 -> V_34 ;
struct V_37 * V_38 , * V_39 ;
F_32 ( & V_33 -> V_31 ) ;
F_21 (vbl_ev, tmp, &vbl_ctrl->event_list, node) {
F_22 ( & V_38 -> V_42 ) ;
F_24 ( V_38 ) ;
}
F_33 ( V_53 ) ;
F_34 ( V_53 ) ;
F_35 ( V_53 ) ;
#ifdef F_36
if ( V_6 && V_4 -> V_6 )
F_37 ( V_53 ) ;
#endif
F_38 ( V_53 ) ;
F_39 ( V_2 ) ;
F_40 ( V_53 ) ;
F_41 ( V_2 ) ;
F_42 ( V_4 -> V_51 ) ;
F_43 ( V_4 -> V_51 ) ;
F_42 ( V_4 -> V_56 ) ;
F_43 ( V_4 -> V_56 ) ;
if ( V_36 ) {
F_44 ( V_2 ) ;
V_36 -> V_44 -> V_57 ( V_36 ) ;
}
if ( V_55 ) {
F_45 ( & V_53 -> V_58 ) ;
V_55 -> V_44 -> V_59 ( V_55 ) ;
F_46 ( & V_53 -> V_58 ) ;
V_55 -> V_44 -> V_57 ( V_55 ) ;
}
if ( V_4 -> V_60 . V_61 ) {
F_47 ( V_62 ) ;
F_48 ( V_63 , & V_62 ) ;
F_49 ( & V_4 -> V_60 . V_64 ) ;
F_50 ( V_2 , V_4 -> V_60 . V_19 , NULL ,
V_4 -> V_60 . V_61 , & V_62 ) ;
}
F_51 ( V_2 , V_53 ) ;
V_53 -> V_5 = NULL ;
F_52 ( V_53 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static int F_53 ( struct V_13 * V_14 )
{
struct V_52 * V_2 = & V_14 -> V_2 ;
return ( int ) ( unsigned long ) F_54 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_65 * V_42 ;
unsigned long V_19 = 0 ;
int V_66 = 0 ;
V_42 = F_56 ( V_2 -> V_2 -> V_67 , L_6 , 0 ) ;
if ( V_42 ) {
struct V_17 V_68 ;
V_66 = F_57 ( V_42 , 0 , & V_68 ) ;
if ( V_66 )
return V_66 ;
V_19 = V_68 . V_69 - V_68 . V_22 ;
F_58 ( L_7 , V_19 , & V_68 . V_22 ) ;
} else if ( ! F_59 ( & V_70 ) ) {
F_58 ( L_8 , V_60 ) ;
V_19 = F_60 ( V_60 , NULL ) ;
}
if ( V_19 ) {
F_47 ( V_62 ) ;
void * V_71 ;
V_4 -> V_60 . V_19 = V_19 ;
F_61 ( & V_4 -> V_60 . V_64 , 0 , ( V_19 >> V_72 ) - 1 ) ;
F_48 ( V_63 , & V_62 ) ;
F_48 ( V_73 , & V_62 ) ;
V_71 = F_62 ( V_2 -> V_2 , V_19 ,
& V_4 -> V_60 . V_61 , V_74 , & V_62 ) ;
if ( ! V_71 ) {
F_9 ( V_2 -> V_2 , L_9 ) ;
V_4 -> V_60 . V_61 = 0 ;
return - V_23 ;
}
F_63 ( V_2 -> V_2 , L_10 ,
( V_75 ) V_4 -> V_60 . V_61 ,
( V_75 ) ( V_4 -> V_60 . V_61 + V_19 ) ) ;
}
return V_66 ;
}
static int F_64 ( struct V_52 * V_2 , struct V_76 * V_77 )
{
struct V_13 * V_14 = F_30 ( V_2 ) ;
struct V_1 * V_53 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_66 ;
V_53 = F_65 ( V_77 , V_2 ) ;
if ( ! V_53 ) {
F_9 ( V_2 , L_11 ) ;
return - V_23 ;
}
F_66 ( V_14 , V_53 ) ;
V_53 -> V_78 = V_14 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_74 ) ;
if ( ! V_4 ) {
F_52 ( V_53 ) ;
return - V_23 ;
}
V_53 -> V_5 = V_4 ;
V_4 -> V_51 = F_67 ( L_12 , 0 ) ;
V_4 -> V_56 = F_67 ( L_13 , 0 ) ;
F_68 ( & V_4 -> V_79 ) ;
F_69 ( & V_4 -> V_80 ) ;
F_69 ( & V_4 -> V_34 . V_50 ) ;
F_70 ( & V_4 -> V_34 . V_31 , F_18 ) ;
F_71 ( & V_4 -> V_34 . V_41 ) ;
F_72 ( V_53 ) ;
V_66 = F_73 ( V_2 , V_53 ) ;
if ( V_66 ) {
F_24 ( V_4 ) ;
F_52 ( V_53 ) ;
return V_66 ;
}
V_66 = F_55 ( V_53 ) ;
if ( V_66 )
goto V_81;
switch ( F_53 ( V_14 ) ) {
case 4 :
V_36 = F_74 ( V_53 ) ;
break;
case 5 :
V_36 = F_75 ( V_53 ) ;
break;
default:
V_36 = F_10 ( - V_82 ) ;
break;
}
if ( F_76 ( V_36 ) ) {
F_9 ( V_2 , L_14 ) ;
V_66 = F_77 ( V_36 ) ;
goto V_81;
}
V_4 -> V_36 = V_36 ;
if ( V_36 ) {
F_78 ( V_2 ) ;
V_66 = V_36 -> V_44 -> V_83 ( V_36 ) ;
if ( V_66 ) {
F_9 ( V_2 , L_15 , V_66 ) ;
goto V_81;
}
}
V_53 -> V_84 . V_44 = & V_85 ;
V_66 = F_79 ( V_53 , V_4 -> V_86 ) ;
if ( V_66 < 0 ) {
F_9 ( V_2 , L_16 ) ;
goto V_81;
}
F_39 ( V_2 ) ;
V_66 = F_80 ( V_53 , F_81 ( V_14 , 0 ) ) ;
F_41 ( V_2 ) ;
if ( V_66 < 0 ) {
F_9 ( V_2 , L_17 ) ;
goto V_81;
}
V_66 = F_82 ( V_53 , 0 ) ;
if ( V_66 )
goto V_81;
V_66 = F_83 ( V_53 ) ;
if ( V_66 ) {
F_9 ( V_2 , L_18 ) ;
goto V_81;
}
F_84 ( V_53 ) ;
#ifdef F_36
if ( V_6 )
V_4 -> V_6 = F_85 ( V_53 ) ;
#endif
V_66 = F_86 ( V_53 ) ;
if ( V_66 )
goto V_81;
F_87 ( V_53 ) ;
return 0 ;
V_81:
F_29 ( V_2 ) ;
return V_66 ;
}
static void F_88 ( struct V_1 * V_2 )
{
static F_89 ( V_87 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_45 ( & V_87 ) ;
if ( ! V_4 -> V_55 )
V_4 -> V_55 = F_90 ( V_2 ) ;
F_46 ( & V_87 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_90 * V_91 ;
F_88 ( V_2 ) ;
V_91 = F_26 ( sizeof( * V_91 ) , V_74 ) ;
if ( ! V_91 )
return - V_23 ;
V_89 -> V_92 = V_91 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_90 * V_91 = V_89 -> V_92 ;
F_45 ( & V_2 -> V_58 ) ;
if ( V_91 == V_4 -> V_93 )
V_4 -> V_93 = NULL ;
F_46 ( & V_2 -> V_58 ) ;
F_24 ( V_91 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_94 ( V_4 -> V_6 ) ;
}
static T_3 F_95 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_96 ( ! V_36 ) ;
return V_36 -> V_44 -> V_94 ( V_36 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_96 ( ! V_36 ) ;
V_36 -> V_44 -> V_96 ( V_36 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_96 ( ! V_36 ) ;
return V_36 -> V_44 -> V_97 ( V_36 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
F_96 ( ! V_36 ) ;
V_36 -> V_44 -> V_98 ( V_36 ) ;
}
static int F_100 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return - V_100 ;
F_101 ( L_19 , V_2 , V_99 ) ;
return F_25 ( V_4 , V_99 , true ) ;
}
static void F_102 ( struct V_1 * V_2 , unsigned int V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_35 * V_36 = V_4 -> V_36 ;
if ( ! V_36 )
return;
F_101 ( L_19 , V_2 , V_99 ) ;
F_25 ( V_4 , V_99 , false ) ;
}
static int F_103 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_101 * args = V_26 ;
struct V_54 * V_55 ;
if ( args -> V_99 != V_102 )
return - V_12 ;
V_55 = V_4 -> V_55 ;
if ( ! V_55 )
return - V_100 ;
return V_55 -> V_44 -> V_103 ( V_55 , args -> V_104 , & args -> V_105 ) ;
}
static int F_104 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_106 * args = V_26 ;
if ( args -> V_40 & ~ V_107 ) {
F_105 ( L_20 , args -> V_40 ) ;
return - V_12 ;
}
return F_106 ( V_2 , V_89 , args -> V_19 ,
args -> V_40 , & args -> V_108 ) ;
}
static inline T_4 F_107 ( struct V_109 V_110 )
{
return F_108 ( V_110 . V_111 , V_110 . V_112 ) ;
}
static int F_109 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_113 * args = V_26 ;
struct V_114 * V_115 ;
T_4 V_110 = F_107 ( args -> V_110 ) ;
int V_66 ;
if ( args -> V_116 & ~ V_117 ) {
F_105 ( L_21 , args -> V_116 ) ;
return - V_12 ;
}
V_115 = F_110 ( V_89 , args -> V_108 ) ;
if ( ! V_115 )
return - V_118 ;
V_66 = F_111 ( V_115 , args -> V_116 , & V_110 ) ;
F_112 ( V_115 ) ;
return V_66 ;
}
static int F_113 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_119 * args = V_26 ;
struct V_114 * V_115 ;
int V_66 ;
V_115 = F_110 ( V_89 , args -> V_108 ) ;
if ( ! V_115 )
return - V_118 ;
V_66 = F_114 ( V_115 ) ;
F_112 ( V_115 ) ;
return V_66 ;
}
static int F_115 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_120 * args = V_26 ;
struct V_114 * V_115 ;
int V_66 = 0 ;
if ( args -> V_121 )
return - V_12 ;
V_115 = F_110 ( V_89 , args -> V_108 ) ;
if ( ! V_115 )
return - V_118 ;
args -> V_122 = F_116 ( V_115 ) ;
F_112 ( V_115 ) ;
return V_66 ;
}
static int F_117 ( struct V_1 * V_2 , void * V_26 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_123 * args = V_26 ;
T_4 V_110 = F_107 ( args -> V_110 ) ;
if ( args -> V_121 ) {
F_105 ( L_22 , args -> V_121 ) ;
return - V_12 ;
}
if ( ! V_4 -> V_55 )
return 0 ;
return F_118 ( V_4 -> V_55 -> V_124 , args -> V_125 , & V_110 , true ) ;
}
static int F_119 ( struct V_52 * V_2 )
{
struct V_1 * V_53 = F_120 ( V_2 ) ;
F_121 ( V_53 ) ;
return 0 ;
}
static int F_122 ( struct V_52 * V_2 )
{
struct V_1 * V_53 = F_120 ( V_2 ) ;
F_123 ( V_53 ) ;
return 0 ;
}
static int F_124 ( struct V_52 * V_2 , void * V_26 )
{
return V_2 -> V_67 == V_26 ;
}
static int F_125 ( struct V_52 * V_2 , struct V_126 * * V_127 ,
const char * V_15 )
{
struct V_65 * V_128 = V_2 -> V_67 ;
unsigned V_129 ;
for ( V_129 = 0 ; ; V_129 ++ ) {
struct V_65 * V_42 ;
V_42 = F_56 ( V_128 , V_15 , V_129 ) ;
if ( ! V_42 )
break;
F_126 ( V_2 , V_127 , F_124 , V_42 ) ;
}
return 0 ;
}
static int F_127 ( struct V_52 * V_2 )
{
return F_64 ( V_2 , & V_130 ) ;
}
static void F_128 ( struct V_52 * V_2 )
{
F_29 ( V_2 ) ;
}
static int F_129 ( struct V_13 * V_14 )
{
struct V_126 * V_131 = NULL ;
F_125 ( & V_14 -> V_2 , & V_131 , L_23 ) ;
F_125 ( & V_14 -> V_2 , & V_131 , L_24 ) ;
V_14 -> V_2 . V_132 = F_130 ( 32 ) ;
return F_131 ( & V_14 -> V_2 , & V_133 , V_131 ) ;
}
static int F_132 ( struct V_13 * V_14 )
{
F_133 ( & V_14 -> V_2 , & V_133 ) ;
return 0 ;
}
static int T_5 F_134 ( void )
{
F_101 ( L_25 ) ;
F_135 () ;
F_136 () ;
F_137 () ;
F_138 () ;
return F_139 ( & V_134 ) ;
}
static void T_6 F_140 ( void )
{
F_101 ( L_26 ) ;
F_141 ( & V_134 ) ;
F_142 () ;
F_143 () ;
F_144 () ;
F_145 () ;
}
